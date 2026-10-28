/*
 * END_19_TBL.C  Twelve's ending tables (ending 19)
 *
 * end_1900_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_19_tbl the length in frames of each scene and end_19_pos the BG x and y of
 * each scene. Read by END_19.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_1900_bg0_cell_tbl[10] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 0 }, { 0x1000, 4 }, { 0x1040, 5 }, { 0x1080, 6 }, { 0x10C0, 7 },
    { 0x2000, 8 }, { 0x2040, 9 },
};

const s16 timer_19_tbl[6] = {
    360, 720, 660, 780, 600, 300,
};

const s16 end_19_pos[6][2] = {
    { 512, 768 },
    { 256, 512 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 256, 256 },
};
