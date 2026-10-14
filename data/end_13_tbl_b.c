/*
 * END_13_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_X_com01();
extern void end_d00_1000();
extern void end_d00_2000();
extern void end_d00_3000();
extern void end_d00_4000();
extern void end_d00_6000();
extern void end_d00_7000();
extern void end_d01_4000();

const PANEL end_e00_bg0_cell_tbl[16] = {
    { 0, 0 }, { 64, 0 }, { 4096, 0 }, { 4160, 0 }, { 8192, 1 }, { 8256, 1 }, { 12288, 1 }, { 12352, 1 },
    { 128, 14 }, { 192, 15 }, { 4224, 0 }, { 4288, 0 }, { 8320, 0 }, { 8384, 0 }, { 12416, 10 }, { 12480, 11 },
};

const PANEL end_e00_ake_cell_tbl[14] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 0 }, { 8256, 0 }, { 12288, 0 }, { 12352, 0 },
    { 4224, 0 }, { 4288, 0 }, { 8320, 0 }, { 8384, 0 }, { 12416, 0 }, { 12480, 0 },
};

const PANEL end_e00_bg2_cell_tbl[8] = {
    { 0, 0 }, { 64, 0 }, { 4224, 6 }, { 4288, 7 }, { 8320, 8 }, { 8384, 9 }, { 12416, 1 }, { 12480, 1 },
};
