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

#ifndef __PATTERN_H
#define __PATTERN_H

#if defined(_WIN32)
#if defined(UNIKEYHOOK)
#define DllInterface   __declspec( dllexport )
#else
#define DllInterface   __declspec( dllimport )
#endif
#else
#define DllInterface //not used
#endif

#define MAX_PATTERN_LEN 40

class DllInterface PatternState {
public:
    char *m_pattern;
    int m_border[MAX_PATTERN_LEN+1];
    int m_pos;
    int m_found;
    void init(char *pattern);
    void reset();
    int foundAtNextChar(char ch); //get next input char, returns 1 if pattern is found.
};

class DllInterface PatternList {
public:
    PatternState *m_patterns;
    int m_count;
    void init(char **patterns, int count);
    int foundAtNextChar(char ch);
    void reset();

    PatternList() {
        m_count = 0;
        m_patterns = 0;
    }

    ~PatternList() {
        if (m_patterns)
            delete [] m_patterns;
    }
};


#endif
