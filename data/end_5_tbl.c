/*
 * END_5_TBL.C  Necro's ending tables (ending 5)
 *
 * end_500_bg0_cell_tbl and end_500_bg1_cell_tbl list the BG0 and BG1 cells (map offset, cell
 * number) written by end_500_cell_set, timer_5_tbl the length in frames of each of its 13
 * scenes and end_5_pos the BG x and y of the scenes. Read by END_5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_500_bg0_cell_tbl[12] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 9 }, { 8256, 10 }, { 8320, 11 }, { 8384, 12 },
};

const PANEL end_500_bg1_cell_tbl[10] = {
    { 0, 13 }, { 64, 14 }, { 128, 15 }, { 192, 13 }, { 4096, 18 }, { 4160, 19 }, { 8192, 16 }, { 8256, 17 },
    { 12288, 16 }, { 12352, 17 },
};

const s16 timer_5_tbl[13] = {
    120, 540, 660, 420, 180, 360, 360, 360,
    360, 360, 300, 360, 360,
};

const s16 end_5_pos[11][2] = {
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 768, 256 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
};
