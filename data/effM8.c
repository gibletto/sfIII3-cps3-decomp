/*
 * EFFM8.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s8 effm8_random_tbl[16] = {
    0, 1, 0, 0, 1, 1, 0, 1,
    0, 0, 1, 0, 1, 1, 0, 1,
};

const s16 effm8_timer_tbl[4] = {
    24, 56, 72, 112,
};
