/*
 * END_16_TBL.C  Chun-Li's ending tables (ending 16)
 *
 * end_1600_bg0_cell_tbl holds the BG0 cells (map offset, cell number)
 * written at the start of the ending, timer_16_tbl the length in frames of each scene and
 * end_16_pos the BG x and y of each scene. Read by END_16.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_1600_bg0_cell_tbl[16] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0x1080, 4 },
    { 0x10C0, 5 }, { 0x2080, 12 }, { 0x20C0, 13 }, { 0x2000, 6 },
    { 0x2040, 7 }, { 0x3000, 8 }, { 0x3040, 9 }, { 0x3080, 10 },
    { 0x30C0, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
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
