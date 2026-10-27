/*
 * EFFM8.C  effect M8 tables
 *
 * effm8_random_tbl is a 16-entry yes/no table indexed by a random number that decides whether
 * effect_M8_init starts its running figures at all; effm8_timer_tbl holds the start delays of
 * the four figures that follow the first. Read by PLCNTSET.C.
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
