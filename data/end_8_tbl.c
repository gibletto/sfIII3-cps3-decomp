/*
 * END_8_TBL.C  Elena's ending tables (ending 8)
 *
 * end_800_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * the ending, timer_8_tbl the length in frames of each of its four scenes and end_8_pos the
 * BG x and y of each scene. Read by END_8.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_800_bg0_cell_tbl[11] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 4096, 4 }, { 4160, 5 }, { 4224, 10 }, { 4288, 11 }, { 8192, 6 },
    { 8256, 7 }, { 12288, 8 }, { 12352, 9 },
};

const s16 timer_8_tbl[4] = {
    840, 480, 900, 360,
};

const s16 end_8_pos[4][2] = {
    { 256, 768 },
    { 256, 512 },
    { 256, 0 },
    { 768, 512 },
};
