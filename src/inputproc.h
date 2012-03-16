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

#ifndef __UK_INPUT_PROCESSOR_H
#define __UK_INPUT_PROCESSOR_H

#include "keycons.h"
#include "vnlexi.h"

#if defined(_WIN32)
#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )
#if defined(UNIKEYHOOK)
#define DllInterface   __declspec( dllexport )
#else
#define DllInterface   __declspec( dllimport )
#endif
#else
#define DllInterface //not used
#define DllExport
#define DllImport
#endif

enum UkKeyEvName {
    vneRoofAll, vneRoof_a, vneRoof_e, vneRoof_o,
    vneHookAll, vneHook_uo, vneHook_u, vneHook_o, vneBowl,
    vneDd,
    vneTone0, vneTone1, vneTone2, vneTone3, vneTone4, vneTone5,
    vne_telex_w, //special for telex
    vneMapChar, //e.g. [ -> u+ , ] -> o+
    vneEscChar,
    vneNormal, //does not belong to any of the above categories
    vneCount //just to count how many event types there are
};

enum UkCharType {
    ukcVn,
    ukcWordBreak,
    ukcNonVn,
    ukcReset
};

struct UkKeyEvent {
    int evType;
    UkCharType chType;
    VnLexiName vnSym; //meaningful only when chType==ukcVn
    unsigned int keyCode;
    int tone; //meaningful only when this is a vowel
};

struct UkKeyMapping {
    unsigned char key;
    int action;
};

///////////////////////////////////////////
class UkInputProcessor {

public:
    //don't do anything with constructor, because
    //this object can be allocated in shared memory
    //Use init method instead
    //UkInputProcessor();

    void init();

    UkInputMethod getIM() {
        return m_im;
    }

    void keyCodeToEvent(unsigned int keyCode, UkKeyEvent & ev);
    void keyCodeToSymbol(unsigned int keyCode, UkKeyEvent & ev);
    int setIM(UkInputMethod im);
    int setIM(int map[256]);
    void getKeyMap(int map[256]);

    UkCharType getCharType(unsigned int keyCode);

protected:
    static bool m_classInit;

    UkInputMethod m_im;
    int m_keyMap[256];

    void useBuiltIn(UkKeyMapping *map);

};

void UkResetKeyMap(int keyMap[256]);
void SetupInputClassifierTable();

DllInterface extern UkKeyMapping TelexMethodMapping[];
DllInterface extern UkKeyMapping SimpleTelexMethodMapping[];
DllInterface extern UkKeyMapping VniMethodMapping[];
DllInterface extern UkKeyMapping VIQRMethodMapping[];
DllInterface extern UkKeyMapping MsViMethodMapping[];

extern VnLexiName IsoVnLexiMap[];
inline VnLexiName IsoToVnLexi(unsigned int keyCode) {
    return (keyCode >= 256)? vnl_nonVnChar : IsoVnLexiMap[keyCode];
}

#endif
