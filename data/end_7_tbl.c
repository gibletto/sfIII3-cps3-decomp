/*
 * END_7_TBL.C  Ibuki's ending tables (ending 7)
 *
 * end_700_bg0_cell_tbl and end_700_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written at the start of the ending, timer_7_tbl the length in frames of each of its
 * four scenes and end_7_pos the BG x and y of each scene. Read by END_7.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_700_bg0_cell_tbl[10] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 4 }, { 0x1000, 7 }, { 0x1040, 8 }, { 0x1080, 9 }, { 0x10C0, 10 },
    { 0x2000, 11 }, { 0x2040, 12 },
};

const PANEL end_700_bg1_cell_tbl[4] = {
    { 0x80, 5 }, { 0xC0, 6 }, { 0x2000, 13 }, { 0x2040, 14 },
};

const s16 timer_7_tbl[4] = {
    480, 840, 840, 960,
};

const s16 end_7_pos[4][2] = {
    { 256, 768 },
    { 768, 768 },
    { 768, 512 },
    { 256, 256 },
};
