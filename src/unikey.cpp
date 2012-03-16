/*
  This file is a part of the Unikey Engine for *nix systems project.

  Copyright (C) 1998-2006 Pham Kim Long <unikey@gmail.com>
  Copyright (C) 2009-2011 Ubuntu-VN <http://www.ubuntu-vn.org>
  Copyright (C) 2012 Dương "Yang" ヤン Nguyễn <cmpitg@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or (at
  your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
*/

#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <iostream>
#include "unikey.h"
#include "ukengine.h"
#include "usrkeymap.h"

using namespace std;

//---- exported variables for use in UkEnginge class ----
UkSharedMem *pShMem = 0;

UkEngine MyKbEngine;

int UnikeyCapsLockOn = 0;
int UnikeyShiftPressed = 0;
//----------------------------------------------------

unsigned char UnikeyBuf[1024];
int UnikeyBackspaces;
int UnikeyBufChars;
UkOutputType UnikeyOutput;

//--------------------------------------------
void UnikeySetInputMethod (UkInputMethod im) {
    if (im == UkTelex || im == UkVni || im == UkSimpleTelex
        || im == UkSimpleTelex2) {
        pShMem->input.setIM (im);
        MyKbEngine.reset ();
    } else if (im == UkUsrIM && pShMem->usrKeyMapLoaded) {
        //cout << "Switched to user mode\n"; //DEBUG
        pShMem->input.setIM (pShMem->usrKeyMap);
        MyKbEngine.reset ();
    }

    //cout << "IM changed to: " << im << endl; //DEBUG
}


//--------------------------------------------
void UnikeySetCapsState (int shiftPressed, int CapsLockOn) {
    //UnikeyCapsAll = (shiftPressed && !CapsLockOn) || (!shiftPressed && CapsLockOn);
    UnikeyCapsLockOn = CapsLockOn;
    UnikeyShiftPressed = shiftPressed;
}

//--------------------------------------------
int UnikeySetOutputCharset(int charset) {
    pShMem->charsetId = charset;
    MyKbEngine.reset ();
    return 1;
}

//--------------------------------------------
void UnikeySetOptions (UnikeyOptions *pOpt) {
    pShMem->options.freeMarking = pOpt->freeMarking;
    pShMem->options.modernStyle = pOpt->modernStyle;
    pShMem->options.macroEnabled = pOpt->macroEnabled;
    pShMem->options.useUnicodeClipboard = pOpt->useUnicodeClipboard;
    pShMem->options.alwaysMacro = pOpt->alwaysMacro;
    pShMem->options.spellCheckEnabled = pOpt->spellCheckEnabled;
    pShMem->options.autoNonVnRestore = pOpt->autoNonVnRestore;
}

//--------------------------------------------
void UnikeyGetOptions(UnikeyOptions *pOpt) {
    *pOpt = pShMem->options;
}

//--------------------------------------------
void CreateDefaultUnikeyOptions(UnikeyOptions *pOpt) {
    pOpt->freeMarking = 1;
    pOpt->modernStyle = 0;
    pOpt->macroEnabled = 0;
    pOpt->useUnicodeClipboard = 0;
    pOpt->alwaysMacro = 0;
    pOpt->spellCheckEnabled = 1;
    pOpt->autoNonVnRestore = 0;
}

//--------------------------------------------
void UnikeyCheckKbCase (int *pShiftPressed, int *pCapsLockOn) {
    *pShiftPressed = UnikeyShiftPressed;
    *pCapsLockOn = UnikeyCapsLockOn;
}

//--------------------------------------------
void UnikeySetup (void) {
    SetupUnikeyEngine ();
    pShMem = new UkSharedMem;
    pShMem->input.init ();
    pShMem->macStore.init ();
    pShMem->vietKey = 1;
    pShMem->usrKeyMapLoaded = 0;
    MyKbEngine.setCtrlInfo (pShMem);
    MyKbEngine.setCheckKbCaseFunc (&UnikeyCheckKbCase);
    UnikeySetInputMethod (UkTelex);
    UnikeySetOutputCharset (CONV_CHARSET_XUTF8);
    pShMem->initialized = 1;
    CreateDefaultUnikeyOptions (&pShMem->options);
}

//--------------------------------------------
void UnikeyCleanup (void) {
    delete pShMem;
}

//--------------------------------------------
void UnikeyFilter (unsigned int ch) {
    UnikeyBufChars = sizeof (UnikeyBuf);
    // DEBUG
    // cerr << "=== Processing UnikeyFilter " << (char) ch << " ===" << endl
    //      << "Cached Size before processing: " << UnikeyBufChars << endl;
    MyKbEngine.process (ch, UnikeyBackspaces, UnikeyBuf,
                        UnikeyBufChars, UnikeyOutput);
    // cerr << "Cached Size after processing: " << UnikeyBufChars << endl << endl;
}

//--------------------------------------------
void UnikeyPutChar (unsigned int ch) {
    MyKbEngine.pass (ch);
    UnikeyBufChars = 0;
    UnikeyBackspaces = 0;
}

//--------------------------------------------
void UnikeyResetBuf (void) {
    MyKbEngine.reset ();
}

//--------------------------------------------
void UnikeySetSingleMode (void) {
    MyKbEngine.setSingleMode ();
}

//--------------------------------------------
void UnikeyBackspacePress (void) {
    UnikeyBufChars = sizeof (UnikeyBuf);
    MyKbEngine.processBackspace
    (UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
    //  printf("Backspaces: %d\n",UnikeyBackspaces);
}

//--------------------------------------------
int UnikeyLoadMacroTable (const char *fileName) {
    return pShMem->macStore.loadFromFile(fileName);
}

//--------------------------------------------
int UnikeyLoadUserKeyMap (const char *fileName) {
    if (UkLoadKeyMap (fileName, pShMem->usrKeyMap)) {
        //cout << "User key map loaded!\n"; //DEBUG
        pShMem->usrKeyMapLoaded = 1;
        return 1;
    }
    return 0;
}

//--------------------------------------------
void UnikeyRestoreKeyStrokes (void) {
    UnikeyBufChars = sizeof (UnikeyBuf);
    MyKbEngine.restoreKeyStrokes (UnikeyBackspaces, UnikeyBuf,
                                  UnikeyBufChars, UnikeyOutput);
}

bool UnikeyAtWordBeginning (void) {
    return MyKbEngine.atWordBeginning();
}

void UnikeyClearBuf (void) {
    UnikeyResetBuf ();
    UnikeyBufChars = 0;
    UnikeyBackspaces = 0;
    memset (UnikeyBuf, 0, sizeof (UnikeyBuf));
    MyKbEngine.clearBuf ();
}

void UnikeyOutputBuf (bool outputEngineBuf) {
    if (outputEngineBuf) {
        MyKbEngine.outputBuf ();
    }
    cout << "UnikeyBuf:" << endl
         << " - Contents " << UnikeyBuf << endl
         << " - Cached size: " << UnikeyBufChars << endl
         << " - Real size: " << sizeof (UnikeyBuf) << endl << endl;
}
