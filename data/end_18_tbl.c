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
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 1 }, { 4288, 2 },
    { 8192, 7 }, { 8256, 8 }, { 8320, 9 }, { 8384, 10 },
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
