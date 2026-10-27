/*
 * EFFD5_TBL.C  thrown rose tables
 *
 * range_time_table and range_isp_table give the flight time and initial height speed of the
 * rose by distance to the opponent, and dm_sp_sel_tbl the petal set and petal acceleration by
 * the strength of the attack that hits it. Read by EFFD5.C, the thrown rose.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


/* One row per attack strength (dm_kind_of_waza): petal set (num_of_hana) and petal acceleration. */
const s16 dm_sp_sel_tbl[4][2] = {
    { 0, 14 }, { 1, 16 }, { 2, 18 }, { 3, 20 },
};

const s16 range_time_table[16][1] = {
    { 32 }, { 34 }, { 36 }, { 38 }, { 40 }, { 42 }, { 44 }, { 46 },
    { 48 }, { 50 }, { 52 }, { 54 }, { 56 }, { 58 }, { 60 }, { 62 },
};

const s16 range_isp_table[16] = {
    2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 4, 5, 5, 5, 5, 5,
};
