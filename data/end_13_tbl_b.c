/*
 * END_13_TBL_B.C  Gouki's ending cell tables (ending 14)
 *
 * The initial cells (map offset, cell number) of the Gouki and Shin Gouki ending:
 * end_e00_bg0_cell_tbl for BG0, end_e00_ake_cell_tbl for the overlay layer (written with
 * end_ake_cell_put) and end_e00_bg2_cell_tbl for BG2. Read by end_e00_cell_set in END_14.C;
 * the scene timings are in END_14_TBL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_e00_bg0_cell_tbl[16] = {
    { 0, 0 }, { 0x40, 0 }, { 0x1000, 0 }, { 0x1040, 0 }, { 0x2000, 1 }, { 0x2040, 1 }, { 0x3000, 1 }, { 0x3040, 1 },
    { 0x80, 14 }, { 0xC0, 15 }, { 0x1080, 0 }, { 0x10C0, 0 }, { 0x2080, 0 }, { 0x20C0, 0 }, { 0x3080, 10 }, { 0x30C0, 11 },
};

const PANEL end_e00_ake_cell_tbl[14] = {
    { 0, 1 }, { 0x40, 2 }, { 0x1000, 3 }, { 0x1040, 4 }, { 0x2000, 0 }, { 0x2040, 0 }, { 0x3000, 0 }, { 0x3040, 0 },
    { 0x1080, 0 }, { 0x10C0, 0 }, { 0x2080, 0 }, { 0x20C0, 0 }, { 0x3080, 0 }, { 0x30C0, 0 },
};

const PANEL end_e00_bg2_cell_tbl[8] = {
    { 0, 0 }, { 0x40, 0 }, { 0x1080, 6 }, { 0x10C0, 7 }, { 0x2080, 8 }, { 0x20C0, 9 }, { 0x3080, 1 }, { 0x30C0, 1 },
};
