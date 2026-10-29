/*
 * TA_SUB_TBL.C  stage object hit box tables
 *
 * eff_hit_data gives the hit box of each stage object type and pl_hit_eff each character's
 * box against them (offset and size). Read by eff_hit_check and its helpers in TA_SUB.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff_hit_data[4][4] = {
    { -67, 59, 13, 29 },
    { 31, 95, 24, 15 },
    { 4, 123, 28, 15 },
    { 20, 15, 67, 37 },
};

const s16 pl_hit_eff[25][4] = {
    { -11, 56, 33, 38 },  /* Gill */
    { -11, 56, 35, 53 },  /* Alex */
    { -13, 47, 50, 38 },  /* Ryu */
    { -18, 42, 36, 32 },  /* Yun */
    { -24, 48, 40, 48 },  /* Dudley */
    { -21, 48, 37, 42 },  /* Necro */
    { -13, 47, 50, 38 },  /* Hugo */
    { -22, 38, 36, 36 },  /* Ibuki */
    { -13, 47, 50, 38 },  /* Elena */
    { -28, 50, 28, 34 },  /* Oro */
    { -18, 42, 36, 32 },  /* Yang */
    { -13, 47, 50, 38 },  /* Ken */
    { -13, 47, 50, 38 },  /* Sean */
    { -11, 56, 33, 38 },  /* Urien */
    { -13, 47, 50, 38 },  /* Gouki */
    { -13, 47, 50, 38 },  /* Shin Gouki */
    { -13, 47, 50, 38 },  /* Chun-Li */
    { -13, 47, 50, 38 },  /* Makoto */
    { -21, 48, 37, 42 },  /* Q */
    { -11, 56, 33, 38 },  /* Twelve */
    { -11, 56, 33, 38 },  /* Remy */
    { -11, 56, 33, 38 },  /* 21 */
    { -11, 56, 33, 38 },  /* 22 */
    { -11, 56, 33, 38 },  /* 23 */
    { -11, 56, 33, 38 },  /* 24 */
};

#pragma section

s16 eff_hit_flag[11];  /* 02026B30 */
