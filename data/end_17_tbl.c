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

extern const u8 end_5_bg1_cell_0[];

const PANEL end_1100_bg0_cell_tbl[16] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 9 }, { 8256, 10 }, { 8320, 11 }, { 8384, 12 }, { 12288, 13 }, { 12352, 14 }, { 12416, 15 }, { 12480, 16 },
};

const u8 end_5_bg1_cell_0[16] = {
    0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 16, 64, 0, 0, 0, 0,
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
