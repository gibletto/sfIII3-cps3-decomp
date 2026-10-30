/*
 * EFF21_TBL.C  bg050 background-synchronised object tables
 *
 * eff21_num gives the number of objects of each sync index and eff21_data_tbl_00 their family,
 * colour, position, priority, animation and speed number, reached through eff21_data_adrs.
 * eff21_sp_tbl holds the speed pairs. Read by EFF21.C, the bg050 background-synchronised
 * objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff21_data_tbl_00[];


const s16 eff21_num[2] = {
    3, 0,
};

const s32 eff21_sp_tbl[1][2] = {
    { 0x2000, 0x2000 },
};

const s16 eff21_data_tbl_00[28] = {
    1, 2, 8320, 640, 0, 10, 17, 0,
    0, 0, 2, 8320, 192, 0, 10, 18,
    0, 0, 1, 2, 8320, 736, 0, 10,
    19, 0, 0, 0,
};

