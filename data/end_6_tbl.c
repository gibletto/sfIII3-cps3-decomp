/*
 * END_6_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const PANEL end_600_bg0_cell_tbl[12] = {
    { 0, 3 }, { 64, 4 }, { 4096, 11 }, { 4160, 12 }, { 8192, 5 }, { 8256, 6 }, { 12288, 7 }, { 12352, 8 },
    { 128, 9 }, { 192, 10 }, { 4224, 13 }, { 4288, 14 },
};

const PANEL end_600_bg1_cell_tbl[4] = {
    { 0, 1 }, { 64, 2 }, { 12288, 1 }, { 12352, 2 },
};

const s16 timer_6_tbl[6] = {
    420, 360, 120, 1080, 720, 540,
};

const s16 end_6_pos[6][2] = {
    { 256, 768 },
    { 256, 768 },
    { 256, 256 },
    { 256, 0 },
    { 768, 768 },
    { 768, 512 },
};
