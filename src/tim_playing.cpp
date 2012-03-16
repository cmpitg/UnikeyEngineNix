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

#include <iostream>
#include "unikey.h"
#include "unikey.cpp"

#define _TOCHAR(x) (unsigned int) x

using namespace std;

int main (int argc, char *argv[])
{
    // The main variable is named MyKbEngine

    UnikeySetup ();

    // UnikeyPutChar (_UINT('a'));
    // // UnikeyPutChar (_UINT('b'));
    // UnikeyPutChar (_UINT('a'));

    UnikeyFilter (_TOCHAR('a'));
    // UnikeyPutChar (_UINT('b'));
    UnikeyFilter (_TOCHAR('a'));

    cout << "UnikeyBuf: " << UnikeyBuf << endl;

    UnikeyCleanup ();

    return 0;
}
