/*
 * EFFL7_TBL.C  screen-crossing companion routines and player 17 palette steps
 *
 * effl7_data_tbl is the random choice of the companion's performance routine; read by EFFL7.C.
 * effM0_tbl_top_0 is the timed colour data of player 17's super art palette effect, reached
 * through effM0_cctbl in EFFM0_TBL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effM0_tbl_top_0[];


const s16 effl7_data_tbl[16] = {
    55, 56, 57, 55, 56, 57, 55, 57,
    55, 56, 57, 55, 56, 57, 56, 57,
};

const s16 effM0_tbl_top_0[56] = {
    0, 11007, 9823, 7647, 4479, 2334, 157, 4415,
    4351, 3231, 2139, 23, 992, 992, 992, 992,
    992, 992, 992, 992, 992, 992, 992, 992,
    992, 992, 992, 992, 992, 992, 992, 992,
    992, 992, 992, 992, 992, 992, 992, 992,
    992, 992, 992, 992, 992, 992, 992, 992,
    992, 992, 992, 992, 992, 992, 992, 992,
};

