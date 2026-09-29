/*
 * END_16_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_1600_0000();
extern void end_1600_1000();
extern void end_1600_2000();
extern void end_1600_3000();
extern void end_1600_5000();

const char end_1600_bg0_cell_tbl[128] = {
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 64, 0, 0, 0, 2,
    0, 0, 0, -128, 0, 0, 0, 3,
    0, 0, 16, -128, 0, 0, 0, 4,
    0, 0, 16, -64, 0, 0, 0, 5,
    0, 0, 32, -128, 0, 0, 0, 12,
    0, 0, 32, -64, 0, 0, 0, 13,
    0, 0, 32, 0, 0, 0, 0, 6,
    0, 0, 32, 64, 0, 0, 0, 7,
    0, 0, 48, 0, 0, 0, 0, 8,
    0, 0, 48, 64, 0, 0, 0, 9,
    0, 0, 48, -128, 0, 0, 0, 10,
    0, 0, 48, -64, 0, 0, 0, 11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const s16 timer_16_tbl[6] = {
    660, 360, 360, 660, 660, 240,
};

const s16 end_16_pos[7][2] = {
    { 256, 768 },
    { 256, 768 },
    { 768, 256 },
    { 256, 256 },
    { 256, 0 },
    { 256, 0 },
    { 768, 0 },
};

/* The initial values of end_1600_move_jp (end_1600_move) in end_16.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_1600_move_jp_init[6] = {
    (u32)end_1600_0000,
    (u32)end_1600_1000,
    (u32)end_1600_2000,
    (u32)end_1600_3000,
    (u32)end_1600_3000,
    (u32)end_1600_5000,
};
