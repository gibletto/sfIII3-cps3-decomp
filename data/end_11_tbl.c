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
    { 0, 3 }, { 64, 4 }, { 128, 8 }, { 192, 9 }, { 4096, 12 }, { 4160, 13 }, { 4224, 14 }, { 4288, 15 },
};

const PANEL end_b00_bg1_cell_tbl[16] = {
    { 0, 1 }, { 64, 2 }, { 128, 5 }, { 192, 6 }, { 4096, 1 }, { 4160, 2 }, { 4224, 5 }, { 4288, 6 },
    { 8192, 1 }, { 8256, 2 }, { 8320, 5 }, { 8384, 6 }, { 12288, 1 }, { 12352, 2 }, { 12416, 5 }, { 12480, 6 },
};

const s16 timer_b_tbl[7] = {
    240, 480, 180, 420, 600, 1080, 720,
};

const s16 end_b_pos[7][2] = {
    { 256, 0 }, { 256, 768 }, { 768, 0 }, { 768, 768 }, { 256, 512 }, { 768, 512 }, { 768, 512 },
};
