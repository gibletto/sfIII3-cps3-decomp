/*
 * END_13_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_d00_bg0_cell_tbl[8] = {
    { 0, 3 }, { 64, 4 }, { 4096, 5 }, { 4160, 6 }, { 8192, 7 }, { 8256, 8 }, { 12288, 1 }, { 12352, 2 },
};

const s16 timer_d_tbl[8] = {
    120, 240, 600, 780, 600, 420, 360, 660,
};

const s16 end_d_pos[8][2] = {
    { 256, 0 }, { 256, 768 }, { 256, 768 }, { 256, 512 }, { 192, 256 }, { 256, 512 }, { 256, 0 }, { 256, 0 },
};
