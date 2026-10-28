/*
 * END_1_TBL.C  Alex's ending tables (ending 1)
 *
 * end_100_panel lists the BG0 cells (map offset, cell number) written by end_100_cell_set at
 * the start of the ending, timer_1_tbl the length in frames of each of its five scenes and
 * end_1_pos the BG0 x and y of each scene. Read by END_1.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_100_panel[11] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0x1000, 4 }, { 0x1040, 5 }, { 0x1080, 6 }, { 0x10C0, 7 }, { 0x2000, 8 },
    { 0x2040, 9 }, { 0x2080, 10 }, { 0x20C0, 11 },
};

const s16 timer_1_tbl[5] = {
    1200, 900, 1260, 240, 360,
};

const s16 end_1_pos[5][2] = {
    { 256, 768 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 768, 240 },
};
