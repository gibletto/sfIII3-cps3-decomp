/*
 * END_5_TBL.C  Necro's ending tables (ending 5)
 *
 * end_500_bg0_cell_tbl and end_500_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written by end_500_cell_set, timer_5_tbl the length in frames of each of its 13
 * scenes and end_5_pos the BG x and y of the scenes. Read by END_5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_500_bg0_cell_tbl[12] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 4 }, { 0x1000, 5 }, { 0x1040, 6 }, { 0x1080, 7 }, { 0x10C0, 8 },
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
};

const PANEL end_500_bg1_cell_tbl[10] = {
    { 0, 13 }, { 0x40, 14 }, { 0x80, 15 }, { 0xC0, 13 }, { 0x1000, 18 }, { 0x1040, 19 }, { 0x2000, 16 }, { 0x2040, 17 },
    { 0x3000, 16 }, { 0x3040, 17 },
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
