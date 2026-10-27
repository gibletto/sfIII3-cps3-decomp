/*
 * EFF19_TBL.C  bg130 quake-reacting object tables
 *
 * eff19_data_tbl gives the x, y position of each of the seven objects. effect_19_s_tbl,
 * effect_19_m_tbl and effect_19_l_tbl decide at random whether an object reacts to a small,
 * middle or large quake, and eff19_wait_tbl gives the random wait before it does. Read by
 * EFF19.C, the bg130 stage object reacting to quakes.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff19_data_tbl[14] = {
    384, 192, 256, 196, 416, 240, 328, 288,
    376, 256, 452, 252, 206, 210,
};

const s8 eff19_wait_tbl[16] = {
    6, 30, 3, 50, 20, 18, 14, 28,
    0, 8, 18, 4, 30, 23, 38, 4,
};

const s8 effect_19_s_tbl[16] = {
    0, 0, 0, 0, 1, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 0,
};

const s8 effect_19_m_tbl[16] = {
    1, 0, 0, 0, 1, 0, 0, 1,
    0, 0, 1, 0, 0, 1, 0, 1,
};

const s8 effect_19_l_tbl[16] = {
    1, 1, 1, 0, 1, 1, 0, 1,
    0, 0, 1, 1, 0, 1, 0, 1,
};
