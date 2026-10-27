/*
 * END_3_TBL.C  Yun's ending tables (ending 3)
 *
 * end_300_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_3_tbl the length in frames of each of its six scenes and end_3_pos the BG
 * x and y of each scene. Read by END_3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_300_bg0_cell_tbl[12] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 1 }, { 8256, 2 }, { 8320, 11 }, { 8384, 12 },
};

const s16 end_3_pos[6][2] = {
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 768, 544 },
    { 256, 256 },
    { 768, 256 },
};

const s16 timer_3_tbl[6] = {
    660, 420, 1080, 900, 720, 1020,
};
