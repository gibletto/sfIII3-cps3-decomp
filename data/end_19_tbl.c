/*
 * END_19_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_1900_0();
extern void end_1900_common();

const PANEL end_1900_bg0_cell_tbl[10] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 0 }, { 4096, 4 }, { 4160, 5 }, { 4224, 6 }, { 4288, 7 },
    { 8192, 8 }, { 8256, 9 },
};

const s16 timer_19_tbl[6] = {
    360, 720, 660, 780, 600, 300,
};

const s16 end_19_pos[6][2] = {
    { 512, 768 },
    { 256, 512 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 256, 256 },
};

/* The initial values of end_1900_move_jp (end_1900_move) in end_19.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_1900_move_jp_init[6] = {
    (u32)end_1900_0,
    (u32)end_1900_common,
    (u32)end_1900_common,
    (u32)end_1900_common,
    (u32)end_1900_common,
    (u32)end_1900_common,
};
