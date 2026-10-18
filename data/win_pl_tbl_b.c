/*
 * WIN_PL_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 win_10000_tbl[2][8] = {
    { 32, 33, 34, 32, 36, 37, 38, 33 },
    { 35, 39, 34, 35, 36, 37, 38, 39 },
};

const s16 win_2000_tbl[18] = {
    0, 0, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 1,
    1, 1,
};

const s16 Win_3000_tbl[16] = {
    42, 34, 33, 42, 32, 42, 32, 35,
    42, 34, 33, 42, 32, 42, 32, 35,
};

const s8 Win_3001_tbl[16] = {
    36, 40, 41, 40, 41, 38, 40, 39,
    36, 40, 41, 39, 41, 37, 39, 40,
};

/* provisional name */
/* Stored after Win_3001_tbl, with its shape. Nothing in the program refers to it. */
const s8 Win_3001_tbl_unref[16] = {
    36, 37, 41, 39, 41, 38, 39, 41,
    36, 39, 41, 39, 41, 36, 39, 37,
};

/* provisional name */
/* Stored after Win_3001_tbl_unref. Nothing in the program refers to it. */
const s16 win_pl_unref_words[12] = {
    691, 689, 696, 696,
    34, 33, 34, 35, 36, 37, 37, 35,
};

const s16 q_em_distance_tbl[21][2] = {
    { -96, -16 },
    { -104, 0 },
    { -90, -16 },
    { -100, -8 },
    { -100, 0 },
    { -106, 0 },
    { 12, -117 },
    { -84, -21 },
    { -112, 0 },
    { -106, 4 },
    { -100, 0 },
    { -90, -16 },
    { -90, -16 },
    { -96, -16 },
    { -90, -16 },
    { -90, -16 },
    { -90, -16 },
    { 0, -96 },
    { -2, -112 },
    { -112, 4 },
    { -96, -6 },
};

/* A table of the same form as the Win_*_tbl tables after it; no routine reads it. */
const s16 Win_unused_tbl[8] = {
    36, 37, 38, 38, 37, 39, 37, 39,
};

const s16 Win_15000_tbl[8] = {
    38, 37, 40, 39, 38, 40, 39, 36,
};

const s16 meta_win_tbl[22] = {
    33, 32, 32, 32, 32, 32, 33, 32,
    32, 37, 32, 32, 32, 32, 34, 34,
    32, 32, 32, 32,
    32, 0,
};

