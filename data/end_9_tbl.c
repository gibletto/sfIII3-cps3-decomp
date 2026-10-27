/*
 * END_9_TBL.C  Oro's ending tables (ending 9)
 *
 * end_900_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_9_tbl the length in frames of each of its six scenes and end_9_pos the BG
 * x and y of each scene. Read by END_9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_900_bg0_cell_tbl[8] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 5 }, { 8256, 6 }, { 12288, 7 }, { 12352, 8 },
};

const s16 timer_9_tbl[6] = {
    300, 480, 120, 540, 780, 600,
};

const s16 end_9_pos[6][2] = {
    { 256, 512 },
    { 256, 768 },
    { 256, 336 },
    { 256, 0 },
    { 256, 768 },
    { 256, 512 },
};
