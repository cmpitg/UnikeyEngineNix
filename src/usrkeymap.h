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

#ifndef __UNIKEY_USER_KEY_MAP_H
#define __UNIKEY_USER_KEY_MAP_H

#include "inputproc.h"
struct UkKeyMapPair {
    unsigned char   key;
    int             action;
};

DllInterface int UkLoadKeyMap (const char *fileName, int keyMap[256]);
DllInterface int UkLoadKeyOrderMap (const char *fileName,
                                    UkKeyMapPair *pMap, int *pMapCount);
DllInterface int UkStoreKeyOrderMap (const char *fileName,
                                     UkKeyMapPair *pMap, int mapCount);

#endif
