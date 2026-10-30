/*
 * END_17_TBL.C  Makoto's ending tables (ending 17)
 *
 * end_1100_bg0_cell_tbl lists the 16 BG0 cells (map offset, cell number) written at the start
 * of the ending, timer_11_tbl the length in frames of each of its seven scenes and end_11_pos
 * the BG x and y of each scene; read by END_17.C. end_5_bg1_cell_0 is a cell list reached
 * only through end_5_bg1_refs in END_5.C, which nothing reads.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_5_bg1_cell_0[];

const PANEL end_1100_bg0_cell_tbl[16] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 4 }, { 0x1000, 5 }, { 0x1040, 6 }, { 0x1080, 7 }, { 0x10C0, 8 },
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 }, { 0x3000, 13 }, { 0x3040, 14 }, { 0x3080, 15 }, { 0x30C0, 16 },
};

const PANEL end_5_bg1_cell_0[2] = {
    { 0x1000, 0 }, { 0x1040, 0 },
};

const s16 timer_11_tbl[7] = {
    660, 480, 120, 180, 480, 1260, 420,
};

const s16 end_11_pos[7][2] = {
    { 256, 768 },
    { 768, 768 },
    { 768, 768 },
    { 256, 768 },
    { 768, 512 },
    { 256, 256 },
    { 768, 256 },
};
