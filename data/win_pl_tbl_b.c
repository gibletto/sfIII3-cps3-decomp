/*
 * WIN_PL_TBL_B.C  round winner pose tables
 *
 * The pose lists of the individual winner routines: win_10000_tbl, Win_3000_tbl,
 * Win_3001_tbl and Win_15000_tbl; win_2000_tbl marks per background where Dudley's
 * final-win poses may play; q_em_distance_tbl gives, by opponent character, the distance Q
 * keeps; meta_win_tbl the pose of a winner not in his own character. Read by WIN_PL.C;
 * Win_3001_tbl_unref, win_pl_unref_words and Win_unused_tbl are not read.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 win_10000_tbl[2][8] = {
    { 32, 33, 34, 32, 36, 37, 38, 33 },
    { 35, 39, 34, 35, 36, 37, 38, 39 },
};

/* Per background: 1 where Dudley's final-win poses (his butler comes down from above) may play, 0 where the
   stage's scenery is in the way. One entry per background of the 18-background stage list; later background
   numbers read on into Win_3000_tbl. */
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
    { -96, -16 },  /* Gill */
    { -104, 0 },  /* Alex */
    { -90, -16 },  /* Ryu */
    { -100, -8 },  /* Yun */
    { -100, 0 },  /* Dudley */
    { -106, 0 },  /* Necro */
    { 12, -117 },  /* Hugo */
    { -84, -21 },  /* Ibuki */
    { -112, 0 },  /* Elena */
    { -106, 4 },  /* Oro */
    { -100, 0 },  /* Yang */
    { -90, -16 },  /* Ken */
    { -90, -16 },  /* Sean */
    { -96, -16 },  /* Urien */
    { -90, -16 },  /* Gouki */
    { -90, -16 },  /* Shin Gouki */
    { -90, -16 },  /* Chun-Li */
    { 0, -96 },  /* Makoto */
    { -2, -112 },  /* Q */
    { -112, 4 },  /* Twelve */
    { -96, -6 },  /* Remy */
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

