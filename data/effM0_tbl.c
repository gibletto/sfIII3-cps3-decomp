/*
 * EFFM0_TBL.C  player 17 super art palette data
 *
 * effM0_tbl_top holds the colour data of the super art palette effect, and effM0_cctbl its
 * timed colour steps, both on effM0_tbl_top_0. EFFL8.C reaches the steps through effL8_data_tbl.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effM0_tbl_top_0[];

const s16 effM0_tbl_top[8] = {
    0x3E0, 0x3E0, 0x3E0, 0x3E0, 0x3E0, 0x3E0, 0x3E0, 0x3E0,
};

/* provisional name */
const ColorCode effM0_cctbl[2] = {
    { 4, 0, effM0_tbl_top_0 },
    { 4, 1, effM0_tbl_top_0 },
};
