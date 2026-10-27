/*
 * EFFM4_TBL.C  palette scripts of effect M4
 *
 * effM4_dir_tbl_0 .. _7 are timed palette scripts, { frames, palette } steps ending with -1,
 * reached through the effM4_dir_tbl list. Read by EFFM5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effM4_dir_tbl_0[4][2] = {
    { 17, 9 }, { 1, 149 }, { 1, 152 }, { -1, 0 },
};

const s16 effM4_dir_tbl_1[4][2] = {
    { 1, 126 }, { 11, 127 }, { 1, 122 }, { -1, 0 },
};

const s16 effM4_dir_tbl_2[3][2] = {
    { 15, 151 }, { 1, 157 }, { -1, 0 },
};

const s16 effM4_dir_tbl_3[5][2] = {
    { 10, 150 }, { 6, 3 }, { 1, 137 }, { 1, 0 },
    { -1, 0 },
};

const s16 effM4_dir_tbl_4[2][2] = {
    { 15, 157 }, { -1, 0 },
};

const s16 effM4_dir_tbl_5[2][2] = {
    { 20, 139 }, { -1, 0 },
};

const s16 effM4_dir_tbl_6[2][2] = {
    { 21, 155 }, { -1, 0 },
};

const s16 effM4_dir_tbl_7[2][2] = {
    { 22, 159 }, { -1, 0 },
};
