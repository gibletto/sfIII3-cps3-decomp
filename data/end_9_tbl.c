/*
 * END_9_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_900_0000();
extern void end_900_5000();

const PANEL end_900_bg0_cell_tbl[8] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 5 }, { 8256, 6 }, { 12288, 7 }, { 12352, 8 },
};

const s16 timer_9_tbl[6] = {
    300, 480, 120, 540, 780, 600,
};

const s16 end_9_pos[6][2] = {
    { 256, 512 },
    { 256, 768 },
    { 256, 336 },
    { 256, 0 },
    { 256, 768 },
    { 256, 512 },
};

/* The initial values of end_1000_jp (end_900_move) in end_9.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_1000_jp_init_3[6] = {
    (u32)end_900_0000,
    (u32)end_900_0000,
    (u32)end_900_0000,
    (u32)end_900_0000,
    (u32)end_900_0000,
    (u32)end_900_5000,
};
