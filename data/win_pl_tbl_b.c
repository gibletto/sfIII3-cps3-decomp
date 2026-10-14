/*
 * WIN_PL_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Win_00000();
extern void Win_01000();
extern void Win_02000();
extern void Win_03000();
extern void Win_04000();
extern void Win_05000();
extern void Win_06000();
extern void Win_07000();
extern void Win_08000();
extern void Win_09000();
extern void Win_10000();
extern void Win_11000();
extern void Win_12000();
extern void Win_13000();
extern void Win_14000();
extern void Win_15000();

const s16 win_10000_tbl[2][8] = {
    { 32, 33, 34, 32, 36, 37, 38, 33 },
    { 35, 39, 34, 35, 36, 37, 38, 39 },
};

const s16 win_02000_tbl[18] = {
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

/* Stored after Win_3001_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Win_3001_tbl. */
const s8 Win_3001_tbl_tail[40] = {
    36, 37, 41, 39, 41, 38, 39, 41, 36, 39, 41, 39, 41, 36, 39, 37,
    2, -77, 2, -79, 2, -72, 2, -72, 0, 34, 0, 33, 0, 34, 0, 35,
    0, 36, 0, 37, 0, 37, 0, 35,
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

