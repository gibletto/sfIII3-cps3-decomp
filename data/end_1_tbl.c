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
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 4096, 4 }, { 4160, 5 }, { 4224, 6 }, { 4288, 7 }, { 8192, 8 },
    { 8256, 9 }, { 8320, 10 }, { 8384, 11 },
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
