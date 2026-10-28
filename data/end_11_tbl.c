/*
 * END_11_TBL.C  Ken's ending tables (ending 11)
 *
 * end_b00_bg0_cell_tbl and end_b00_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written at the start of the ending, timer_b_tbl the length in frames of each of its
 * seven scenes and end_b_pos the BG x and y of each scene. Read by END_11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_b00_bg0_cell_tbl[8] = {
    { 0, 3 }, { 0x40, 4 }, { 0x80, 8 }, { 0xC0, 9 }, { 0x1000, 12 }, { 0x1040, 13 }, { 0x1080, 14 }, { 0x10C0, 15 },
};

const PANEL end_b00_bg1_cell_tbl[16] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 5 }, { 0xC0, 6 }, { 0x1000, 1 }, { 0x1040, 2 }, { 0x1080, 5 }, { 0x10C0, 6 },
    { 0x2000, 1 }, { 0x2040, 2 }, { 0x2080, 5 }, { 0x20C0, 6 }, { 0x3000, 1 }, { 0x3040, 2 }, { 0x3080, 5 }, { 0x30C0, 6 },
};

const s16 timer_b_tbl[7] = {
    240, 480, 180, 420, 600, 1080, 720,
};

const s16 end_b_pos[7][2] = {
    { 256, 0 }, { 256, 768 }, { 768, 0 }, { 768, 768 }, { 256, 512 }, { 768, 512 }, { 768, 512 },
};
