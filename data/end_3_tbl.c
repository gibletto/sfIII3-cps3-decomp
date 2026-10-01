/*
 * END_3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const void* const end_300_col_tbl_tail[];
extern const u32 end_400_panel_tbl_0[];
extern const u32 end_400_panel_tbl_1[];

extern void end_300_0000();
extern void end_300_0002();
extern void end_300_0003();
extern void end_300_0004();
extern void end_300_0005();
extern void end_301_0003();
extern void end_X_com01();

const PANEL end_300_bg0_cell_tbl[12] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 1 }, { 8256, 2 }, { 8320, 11 }, { 8384, 12 },
};

const s16 end_3_pos[6][2] = {
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 768, 544 },
    { 256, 256 },
    { 768, 256 },
};

const s16 timer_3_tbl[6] = {
    660, 420, 1080, 900, 720, 1020,
};

/* Initial values of end_1000_jp (end_300_move) in end_3.c. */
const u32 end_1000_jp_init[6] = {
    (u32)end_300_0000,
    (u32)end_300_0000,
    (u32)end_300_0002,
    (u32)end_300_0003,
    (u32)end_300_0004,
    (u32)end_300_0005,
};

const u8 end_300_col_tbl[4] = {
    59, 60, 61, 0,
};

/* Stored after end_300_col_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_300_col_tbl. */
const void* const end_300_col_tbl_tail[6] = {
    end_X_com01, end_X_com01, end_X_com01, end_301_0003,
    end_X_com01, end_X_com01,
};

const u32 end_400_panel_tbl_0[24] = {
    0, 1, 0x40, 2, 0x80, 3, 0xC0, 0,
    0x1000, 0x10, 0x1040, 0x11, 0x1080, 0x12, 0x10C0, 0,
    0x2000, 0x13, 0x2040, 0x14, 0x2080, 0x15, 0x20C0, 0,
};

const u32 end_400_panel_tbl_1[24] = {
    0, 4, 0x40, 5, 0x80, 6, 0xC0, 7,
    0x1000, 8, 0x1040, 9, 0x1080, 0xA, 0x10C0, 0xB,
    0x2000, 0xC, 0x2040, 0xD, 0x2080, 0xE, 0x10C0, 0xF,
};

