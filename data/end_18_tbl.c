/*
 * END_18_TBL.C  Q's ending tables (ending 18)
 *
 * end_1800_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_18_tbl the length in frames of each of its eleven scenes and end_18_pos
 * the BG x and y of each scene. Read by END_18.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_1800_bg0_cell_tbl[16] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 4 }, { 0x1000, 5 }, { 0x1040, 6 }, { 0x1080, 1 }, { 0x10C0, 2 },
    { 0x2000, 7 }, { 0x2040, 8 }, { 0x2080, 9 }, { 0x20C0, 10 },
};

const s16 timer_18_tbl[11] = {
    900, 240, 240, 240, 240, 420, 720, 360,
    480, 240, 300,
};

const s16 end_18_pos[11][2] = {
    { 768, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 256, 768 },
    { 256, 512 },
    { 256, 256 },
    { 768, 512 },
};
