/*
 * END_5_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_500_0001();
extern void end_500_0006();
extern void end_500_0007();
extern void end_500_0008();
extern void end_500_0011();
extern void end_500_comm();
extern void end_501_0007();
extern void end_501_0008();
extern void end_501_0009();
extern void end_501_0010();
extern void end_501_0011();
extern void end_501_0012();
extern void end_X_com01();

const PANEL end_500_bg0_cell_tbl[12] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 9 }, { 8256, 10 }, { 8320, 11 }, { 8384, 12 },
};

const PANEL end_500_bg1_cell_tbl[10] = {
    { 0, 13 }, { 64, 14 }, { 128, 15 }, { 192, 13 }, { 4096, 18 }, { 4160, 19 }, { 8192, 16 }, { 8256, 17 },
    { 12288, 16 }, { 12352, 17 },
};

const s16 timer_5_tbl[13] = {
    120, 540, 660, 420, 180, 360, 360, 360,
    360, 360, 300, 360, 360,
};

const s16 end_5_pos[11][2] = {
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 768, 256 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
};

const END_500_JP end_500_jp_tbl[1] = {
    { { end_500_comm, end_500_0001, end_500_0001, end_500_comm, end_500_comm, end_500_comm, end_500_0006, end_500_0007, end_500_0008, end_X_com01, end_X_com01, end_500_0011, end_X_com01 } },
};

const s16 necro_quake_tbl[32][2] = {
    { 2, -2 }, { 4, -4 }, { 6, -8 }, { 8, -4 }, { 6, 0 }, { 8, -4 }, { 4, 0 }, { 0, 0 },
    { -2, 0 }, { -4, 4 }, { -4, 8 }, { -6, 2 }, { 0, 6 }, { 4, 0 }, { -5, -4 }, { -5, 2 },
    { 0, 0 }, { 2, -4 }, { 4, -8 }, { 6, -10 }, { 2, 2 }, { -2, 6 }, { 0, 4 }, { 3, 1 },
    { 6, 0 }, { 4, -2 }, { -6, 4 }, { -2, 8 }, { 0, 0 }, { 6, 6 }, { 0, -8 }, { 4, 4 },
};

const s16 necro_quake_timer[32] = {
    4, 4, 4, 4, 8, 4, 4, 4,
    4, 4, 4, 4, 8, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 8, 4, 8,
};

const s16 end_500_quake_tbl[8] = {
    2, 4, -2, -4, -2, -4, 2, 4,
};

/* The initial values of end_500_jp (end_501_move) in end_5.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 end_500_jp_init[13] = {
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_X_com01,
    (u32)end_501_0007,
    (u32)end_501_0008,
    (u32)end_501_0009,
    (u32)end_501_0010,
    (u32)end_501_0011,
    (u32)end_501_0012,
};

const s8 end_5_bg1_cell_tbl[12] = {
    13, 14, 15, 13, 14, 15, 13, 14,
    15, 13, 14, 15,
};

const s32 end_5_bg1_ofs_tbl[4] = {
    0, 64, 128, 192,
};
