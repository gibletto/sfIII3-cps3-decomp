/*
 * END_6_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_600_0000();
extern void end_600_1000();
extern void end_600_2000();
extern void end_600_3000();
extern void end_600_4000();
extern void end_600_5000();
extern void end_601_0000();
extern void end_601_1000();
extern void end_601_2000();
extern void end_601_3000();
extern void end_X_com01();

const PANEL end_600_bg0_cell_tbl[12] = {
    { 0, 3 }, { 64, 4 }, { 4096, 11 }, { 4160, 12 }, { 8192, 5 }, { 8256, 6 }, { 12288, 7 }, { 12352, 8 },
    { 128, 9 }, { 192, 10 }, { 4224, 13 }, { 4288, 14 },
};

const PANEL end_600_bg1_cell_tbl[4] = {
    { 0, 1 }, { 64, 2 }, { 12288, 1 }, { 12352, 2 },
};

const s16 timer_6_tbl[6] = {
    420, 360, 120, 1080, 720, 540,
};

const s16 end_6_pos[6][2] = {
    { 256, 768 },
    { 256, 768 },
    { 256, 256 },
    { 256, 0 },
    { 768, 768 },
    { 768, 512 },
};

/* Initial values of end_1000_jp (end_600_move) in end_6.c. */
const u32 end_1000_jp_init_2[6] = {
    (u32)end_600_0000,
    (u32)end_600_1000,
    (u32)end_600_2000,
    (u32)end_600_3000,
    (u32)end_600_4000,
    (u32)end_600_5000,
};

const s16 end_600_1000_tbl[8][2] = {
    { -4, 2 }, { 6, -6 }, { -2, 4 }, { -4, 3 }, { 11, 0 }, { -4, 2 }, { 8, 0 }, { 2, -2 },
};

const s16 end_600_2000_tbl[12][2] = {
    { 3, -2 }, { 1, 3 }, { 2, -1 }, { 3, -2 }, { 2, 3 }, { 2, -2 }, { 3, -2 }, { 2, 3 },
    { 2, -2 }, { 3, -2 }, { 1, 3 }, { 2, -1 },
};

const u8 end_600_5000_pal_tbl[8] = {
    44, 45, 44, 46, 44, 45, 44, 46,
};

const END601_JP end_601_jp_tbl[1] = {
    { { end_601_0000, end_601_1000, end_601_2000, end_601_3000, end_X_com01, end_X_com01 } },
};
