/*
 * END_12_TBL.C  Sean's ending tables (ending 12)
 *
 * end_c00_bg0_cell_tbl and end_c00_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written at the start of the ending, timer_c_tbl the length in frames of each of its
 * seven scenes and end_c_pos the BG x and y of each scene. Read by END_12.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_c00_bg0_cell_tbl[12] = {
    { 0x1000, 3 }, { 0x1040, 4 }, { 0x2000, 11 }, { 0x2040, 12 }, { 0x3000, 15 }, { 0x3040, 16 }, { 0x80, 5 }, { 0xC0, 6 },
    { 0x1080, 7 }, { 0x10C0, 8 }, { 0x2080, 13 }, { 0x20C0, 14 },
};

const PANEL end_c00_bg1_cell_tbl[6] = {
    { 0x1000, 1 }, { 0x1040, 2 }, { 0x2000, 9 }, { 0x2040, 10 }, { 0x3000, 17 }, { 0x3040, 18 },
};

const s16 timer_c_tbl[7] = {
    600, 600, 360, 420, 360, 540, 420,
};

const s16 end_c_pos[7][2] = {
    { 256, 32 }, { 768, 768 }, { 768, 768 }, { 768, 512 }, { 768, 768 }, { 768, 256 }, { 768, 256 },
};
