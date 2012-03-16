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

#ifndef __VN_LEXI_H
#define __VN_LEXI_H

enum VnLexiName {
    vnl_nonVnChar = -1,
    vnl_A, vnl_a, vnl_A1, vnl_a1, vnl_A2, vnl_a2, vnl_A3, vnl_a3, vnl_A4, vnl_a4, vnl_A5, vnl_a5,
    vnl_Ar, vnl_ar, vnl_Ar1, vnl_ar1, vnl_Ar2, vnl_ar2, vnl_Ar3, vnl_ar3, vnl_Ar4, vnl_ar4, vnl_Ar5, vnl_ar5,
    vnl_Ab, vnl_ab, vnl_Ab1, vnl_ab1, vnl_Ab2, vnl_ab2, vnl_Ab3, vnl_ab3, vnl_Ab4, vnl_ab4, vnl_Ab5, vnl_ab5,
    vnl_B, vnl_b, vnl_C, vnl_c,
    vnl_D, vnl_d, vnl_DD, vnl_dd,
    vnl_E, vnl_e, vnl_E1, vnl_e1, vnl_E2, vnl_e2, vnl_E3, vnl_e3, vnl_E4, vnl_e4, vnl_E5, vnl_e5,
    vnl_Er, vnl_er, vnl_Er1, vnl_er1, vnl_Er2, vnl_er2, vnl_Er3, vnl_er3, vnl_Er4, vnl_er4, vnl_Er5, vnl_er5,
    vnl_F, vnl_f, vnl_G, vnl_g, vnl_H, vnl_h,
    vnl_I, vnl_i, vnl_I1, vnl_i1, vnl_I2, vnl_i2, vnl_I3, vnl_i3, vnl_I4, vnl_i4, vnl_I5, vnl_i5,
    vnl_J, vnl_j, vnl_K, vnl_k, vnl_L, vnl_l, vnl_M, vnl_m, vnl_N, vnl_n,
    vnl_O, vnl_o, vnl_O1, vnl_o1, vnl_O2, vnl_o2, vnl_O3, vnl_o3, vnl_O4, vnl_o4, vnl_O5, vnl_o5,
    vnl_Or, vnl_or, vnl_Or1, vnl_or1, vnl_Or2, vnl_or2, vnl_Or3, vnl_or3, vnl_Or4, vnl_or4, vnl_Or5, vnl_or5,
    vnl_Oh, vnl_oh, vnl_Oh1, vnl_oh1, vnl_Oh2, vnl_oh2, vnl_Oh3, vnl_oh3, vnl_Oh4, vnl_oh4, vnl_Oh5, vnl_oh5,
    vnl_P, vnl_p, vnl_Q, vnl_q, vnl_R, vnl_r, vnl_S, vnl_s, vnl_T, vnl_t,
    vnl_U, vnl_u, vnl_U1, vnl_u1, vnl_U2, vnl_u2, vnl_U3, vnl_u3, vnl_U4, vnl_u4, vnl_U5, vnl_u5,
    vnl_Uh, vnl_uh, vnl_Uh1, vnl_uh1, vnl_Uh2, vnl_uh2, vnl_Uh3, vnl_uh3, vnl_Uh4, vnl_uh4, vnl_Uh5, vnl_uh5,
    vnl_V, vnl_v, vnl_W, vnl_w, vnl_X, vnl_x,
    vnl_Y, vnl_y, vnl_Y1, vnl_y1, vnl_Y2, vnl_y2, vnl_Y3, vnl_y3, vnl_Y4, vnl_y4, vnl_Y5, vnl_y5,
    vnl_Z, vnl_z,

    vnl_lastChar,
};

enum VowelSeq {
    vs_nil = -1,
    vs_a,
    vs_ar,
    vs_ab,
    vs_e,
    vs_er,
    vs_i,
    vs_o,
    vs_or,
    vs_oh,
    vs_u,
    vs_uh,
    vs_y,
    vs_ai,
    vs_ao,
    vs_au,
    vs_ay,
    vs_aru,
    vs_ary,
    vs_eo,
    vs_eu,
    vs_eru,
    vs_ia,
    vs_ie,
    vs_ier,
    vs_iu,
    vs_oa,
    vs_oab,
    vs_oe,
    vs_oi,
    vs_ori,
    vs_ohi,
    vs_ua,
    vs_uar,
    vs_ue,
    vs_uer,
    vs_ui,
    vs_uo,
    vs_uor,
    vs_uoh,
    vs_uu,
    vs_uy,
    vs_uha,
    vs_uhi,
    vs_uho,
    vs_uhoh,
    vs_uhu,
    vs_ye,
    vs_yer,
    vs_ieu,
    vs_ieru,
    vs_oai,
    vs_oay,
    vs_oeo,
    vs_uay,
    vs_uary,
    vs_uoi,
    vs_uou,
    vs_uori,
    vs_uohi,
    vs_uohu,
    vs_uya,
    vs_uye,
    vs_uyer,
    vs_uyu,
    vs_uhoi,
    vs_uhou,
    vs_uhohi,
    vs_uhohu,
    vs_yeu,
    vs_yeru
};

enum ConSeq {
    cs_nil = -1,
    cs_b,
    cs_c,
    cs_ch,
    cs_d,
    cs_dd,
    cs_dz,
    cs_g,
    cs_gh,
    cs_gi,
    cs_gin,
    cs_h,
    cs_k,
    cs_kh,
    cs_l,
    cs_m,
    cs_n,
    cs_ng,
    cs_ngh,
    cs_nh,
    cs_p,
    cs_ph,
    cs_q,
    cs_qu,
    cs_r,
    cs_s,
    cs_t,
    cs_th,
    cs_tr,
    cs_v,
    cs_x
};



#endif
