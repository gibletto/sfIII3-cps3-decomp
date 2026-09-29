/*
 * EFF18_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data18_0[];


const s16 eff17_data_tbl[9][5] = {
    { 396, 144, 28, 1, 0 },
    { 422, 144, 27, 2, 3 },
    { 451, 144, 26, 3, 6 },
    { 478, 144, 25, 4, 9 },
    { 505, 144, 24, 5, 12 },
    { 543, 144, 23, 6, 15 },
    { 569, 144, 22, 7, 18 },
    { 599, 144, 21, 8, 21 },
    { 629, 144, 20, 9, 24 },
};

/* Stored after eff17_data_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of eff17_data_tbl. */
const s16 eff17_data_tbl_tail[1] = {
    0,
};

const s16 scr_obj_num18[1][4] = {
    { 1, 1, 1, 1 },
};

const s16 scr_obj_data18_0[2] = {
    0, 0,
};

