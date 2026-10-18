/*
 * END_20_TBL.C  game tables
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
