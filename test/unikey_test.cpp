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
#include <gtest/gtest.h>
#include "unikey.h"

#define _TOCHAR(x) (unsigned int) x
#define _TOSTR(x) (const char *)x

using namespace std;

TEST (LettersCompletionTest, SingleLetters) {
    UnikeyFilter (_TOCHAR('a'));
    UnikeyFilter (_TOCHAR('a'));
    EXPECT_STREQ ("â", _TOSTR(UnikeyBuf));
    UnikeyClearBuf ();

    UnikeyFilter (_TOCHAR('a'));
    UnikeyFilter (_TOCHAR('s'));
    EXPECT_STREQ ("á", _TOSTR(UnikeyBuf));
    UnikeyClearBuf ();

    UnikeyFilter (_TOCHAR('a'));
    UnikeyFilter (_TOCHAR('w'));
    EXPECT_STREQ ("ă", _TOSTR(UnikeyBuf));
    UnikeyClearBuf ();

    UnikeyFilter (_TOCHAR('o'));
    UnikeyFilter (_TOCHAR('o'));
    EXPECT_STREQ ("ô", _TOSTR(UnikeyBuf));
    UnikeyClearBuf ();
}

TEST (LettersCompletionTest, LongWords) {
    UnikeyFilter (_TOCHAR('u'));
    UnikeyFilter (_TOCHAR('o'));
    UnikeyFilter (_TOCHAR('n'));
    UnikeyFilter (_TOCHAR('g'));
    UnikeyFilter (_TOCHAR('w'));
    UnikeyFilter (_TOCHAR(' '));
    EXPECT_STREQ ("ương", _TOSTR(UnikeyBuf));
    UnikeyClearBuf ();
}

int main (int argc, char *argv[])
{
    UnikeySetup ();

    testing::InitGoogleTest (&argc, argv);
    int dummyVal = RUN_ALL_TESTS ();

    UnikeyCleanup ();

    return 0;
}
