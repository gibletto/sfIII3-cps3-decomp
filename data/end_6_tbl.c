/*
 * END_6_TBL.C  Hugo's ending tables (ending 6)
 *
 * end_600_bg0_cell_tbl and end_600_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written at the start of the ending, timer_6_tbl the length in frames of each of its
 * six scenes and end_6_pos the BG x and y of each scene. Read by END_6.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_600_bg0_cell_tbl[12] = {
    { 0, 3 }, { 0x40, 4 }, { 0x1000, 11 }, { 0x1040, 12 }, { 0x2000, 5 }, { 0x2040, 6 }, { 0x3000, 7 }, { 0x3040, 8 },
    { 0x80, 9 }, { 0xC0, 10 }, { 0x1080, 13 }, { 0x10C0, 14 },
};

const PANEL end_600_bg1_cell_tbl[4] = {
    { 0, 1 }, { 0x40, 2 }, { 0x3000, 1 }, { 0x3040, 2 },
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
