/*
 * EFFD5_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 dm_sp_sel_tbl[4][2] = {
    { 0, 14 }, { 1, 16 }, { 2, 18 }, { 3, 20 },
};

const s16 range_time_table[16] = {
    32, 34, 36, 38, 40, 42, 44, 46,
    48, 50, 52, 54, 56, 58, 60, 62,
};

const s16 range_isp_table[16] = {
    2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 4, 5, 5, 5, 5, 5,
};
