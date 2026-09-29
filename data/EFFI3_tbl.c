/*
 * EFFI3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u8 effI2_col_tbl[10] = {
    8, 13, 14, 15, 16, 17, 16, 15,
    14, 13,
};

const u8 effI2_timer_tbl[10] = {
    9, 8, 7, 6, 5, 4, 5, 6,
    7, 8,
};

const I3_Data i3_data[6] = {
    { 3, 2, 0 }, { 1, 1, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 },
};
