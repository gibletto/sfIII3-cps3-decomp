/*
 * EFFM3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 M3_bahn_data_tail[];
extern const s16 effM4_dir_tbl_0[];
extern const s16 effM4_dir_tbl_1[];
extern const s16 effM4_dir_tbl_2[];
extern const s16 effM4_dir_tbl_3[];
extern const s16 effM4_dir_tbl_4[];
extern const s16 effM4_dir_tbl_5[];
extern const s16 effM4_dir_tbl_6[];
extern const s16 effM4_dir_tbl_7[];


const s16 M3_bahn_data[5] = {
    16, 10, 78, 0, -512,
};

/* Stored after M3_bahn_data. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of M3_bahn_data. */
const s16 M3_bahn_data_tail[1] = {
    0,
};

const s16 effM4_dir_tbl_0[8] = {
    17, 9, 1, 149, 1, 152, -1, 0,
};

const s16 effM4_dir_tbl_1[8] = {
    1, 126, 11, 127, 1, 122, -1, 0,
};

const s16 effM4_dir_tbl_2[6] = {
    15, 151, 1, 157, -1, 0,
};

const s16 effM4_dir_tbl_3[10] = {
    10, 150, 6, 3, 1, 137, 1, 0,
    -1, 0,
};

const s16 effM4_dir_tbl_4[4] = {
    15, 157, -1, 0,
};

const s16 effM4_dir_tbl_5[4] = {
    20, 139, -1, 0,
};

const s16 effM4_dir_tbl_6[4] = {
    21, 155, -1, 0,
};

const s16 effM4_dir_tbl_7[4] = {
    22, 159, -1, 0,
};

