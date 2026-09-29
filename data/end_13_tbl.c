/*
 * END_13_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_X_com01();
extern void end_d00_1000();
extern void end_d00_2000();
extern void end_d00_3000();
extern void end_d00_4000();
extern void end_d00_6000();
extern void end_d00_7000();
extern void end_d01_4000();

const PANEL end_d00_bg0_cell_tbl[8] = {
    { 0, 3 }, { 64, 4 }, { 4096, 5 }, { 4160, 6 }, { 8192, 7 }, { 8256, 8 }, { 12288, 1 }, { 12352, 2 },
};

const s16 timer_d_tbl[8] = {
    120, 240, 600, 780, 600, 420, 360, 660,
};

const s16 end_d_pos[8][2] = {
    { 256, 0 }, { 256, 768 }, { 256, 768 }, { 256, 512 }, { 192, 256 }, { 256, 512 }, { 256, 0 }, { 256, 0 },
};

/* The initial values of end_101_jp (end_d00_move), end_d01_jp (end_d01_move) in end_13.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_13_local_init[16] = {
    (u32)end_d00_1000,
    (u32)end_d00_1000,
    (u32)end_d00_2000,
    (u32)end_d00_3000,
    (u32)end_d00_4000,
    (u32)end_d00_1000,
    (u32)end_d00_6000,
    (u32)end_d00_7000,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_d01_4000,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
};

const PANEL end_e00_bg0_cell_tbl[16] = {
    { 0, 0 }, { 64, 0 }, { 4096, 0 }, { 4160, 0 }, { 8192, 1 }, { 8256, 1 }, { 12288, 1 }, { 12352, 1 },
    { 128, 14 }, { 192, 15 }, { 4224, 0 }, { 4288, 0 }, { 8320, 0 }, { 8384, 0 }, { 12416, 10 }, { 12480, 11 },
};

const PANEL end_e00_ake_cell_tbl[14] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 0 }, { 8256, 0 }, { 12288, 0 }, { 12352, 0 },
    { 4224, 0 }, { 4288, 0 }, { 8320, 0 }, { 8384, 0 }, { 12416, 0 }, { 12480, 0 },
};

const PANEL end_e00_bg2_cell_tbl[8] = {
    { 0, 0 }, { 64, 0 }, { 4224, 6 }, { 4288, 7 }, { 8320, 8 }, { 8384, 9 }, { 12416, 1 }, { 12480, 1 },
};
