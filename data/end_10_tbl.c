/*
 * END_10_TBL.C  Yang's ending tables (ending 10)
 *
 * end_1000_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start
 * of the ending, timer_10_tbl the length in frames of each of its six scenes and end_10_pos
 * the BG x and y of each scene. Read by END_10.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_1000_bg0_cell_tbl[8] = {
    { 0, 5 }, { 64, 6 }, { 4096, 1 }, { 4160, 2 }, { 8192, 3 }, { 8256, 4 }, { 12288, 7 }, { 12352, 8 },
};

const s16 timer_10_tbl[6] = {
    780, 720, 420, 780, 420, 660,
};

const s16 end_10_pos[6][2] = {
    { 256, 768 },
    { 256, 512 },
    { 256, 432 },
    { 256, 432 },
    { 256, 0 },
    { 256, 256 },
};
