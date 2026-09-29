/*
 * END_7_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_700_0000();
extern void end_700_2000();
extern void end_X_com01();

const PANEL end_700_bg0_cell_tbl[10] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 7 }, { 4160, 8 }, { 4224, 9 }, { 4288, 10 },
    { 8192, 11 }, { 8256, 12 },
};

const PANEL end_700_bg1_cell_tbl[4] = {
    { 128, 5 }, { 192, 6 }, { 8192, 13 }, { 8256, 14 },
};

const s16 timer_7_tbl[4] = {
    480, 840, 840, 960,
};

const s16 end_7_pos[4][2] = {
    { 256, 768 },
    { 768, 768 },
    { 768, 512 },
    { 256, 256 },
};

/* The initial values of end_800_jp (end_700_move), end_701_jp (end_701_move) in end_7.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_7_local_init[8] = {
    (u32)end_700_0000,
    (u32)end_700_0000,
    (u32)end_700_2000,
    (u32)end_700_0000,
    (u32)end_X_com01,
    (u32)end_700_0000,
    (u32)end_X_com01,
    (u32)end_700_0000,
};
