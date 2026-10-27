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
    { 4096, 3 }, { 4160, 4 }, { 8192, 11 }, { 8256, 12 }, { 12288, 15 }, { 12352, 16 }, { 128, 5 }, { 192, 6 },
    { 4224, 7 }, { 4288, 8 }, { 8320, 13 }, { 8384, 14 },
};

const PANEL end_c00_bg1_cell_tbl[6] = {
    { 4096, 1 }, { 4160, 2 }, { 8192, 9 }, { 8256, 10 }, { 12288, 17 }, { 12352, 18 },
};

const s16 timer_c_tbl[7] = {
    600, 600, 360, 420, 360, 540, 420,
};

const s16 end_c_pos[7][2] = {
    { 256, 32 }, { 768, 768 }, { 768, 768 }, { 768, 512 }, { 768, 768 }, { 768, 256 }, { 768, 256 },
};
