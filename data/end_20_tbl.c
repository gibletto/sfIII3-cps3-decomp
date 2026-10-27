/*
 * END_20_TBL.C  Remy's ending tables (ending 20)
 *
 * end_2000_bg0_cell_tbl and end_2000_ake_cell_tbl list the BG0 and overlay layer cells (map
 * offset, cell number) written at the start of the ending, timer_20_tbl the length in frames
 * of each of its six scenes and end_20_pos the BG x and y of each scene. Read by END_20.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_2000_bg0_cell_tbl[4] = {
    { 4096, 1 }, { 4160, 2 }, { 8192, 3 }, { 8256, 4 },
};

const PANEL end_2000_ake_cell_tbl[4] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 },
};

const s16 timer_20_tbl[6] = {
    360, 420, 780, 720, 240, 780,
};

const s16 end_20_pos[6][2] = {
    { 256, 704 },
    { 256, 304 },
    { 256, 448 },
    { 256, 816 },
    { 768, 768 },
    { 256, 224 },
};
