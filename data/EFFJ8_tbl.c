/*
 * EFFJ8_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void dragonfly_l_move();
extern void dragonfly_move_0000();
extern void dragonfly_move_0001();
extern void dragonfly_move_0004();
extern void dragonfly_move_0005();
extern void dragonfly_r_move();

const s16 effj8_timer_tbl[8] = {
    60, 120, 180, 90, 150, 30, 220, 160,
};

const s16 effj8_y_tbl[8] = {
    128, 80, 96, 160, 176, 112, 144, 168,
};

/* The initial values of dragonfly_move_jp1 (dragonfly_move) in EFFJ8.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 dragonfly_move_jp1_init[8] = {
    (u32)dragonfly_move_0000,
    (u32)dragonfly_move_0001,
    (u32)dragonfly_r_move,
    (u32)dragonfly_l_move,
    (u32)dragonfly_move_0004,
    (u32)dragonfly_move_0005,
    (u32)dragonfly_l_move,
    (u32)dragonfly_r_move,
};

const s32 effj8_sp_tbl[8][4] = {
    { 393216, -16384, 16384, 0 },
    { 393216, -18432, -16384, 0 },
    { 393216, -4096, 16384, 0 },
    { 393216, -8192, -16384, 0 },
    { 524288, -40960, 16384, 0 },
    { 524288, -8192, -16384, 0 },
    { 524288, -24576, 16384, 0 },
    { 524288, -16384, -16384, 0 },
};
