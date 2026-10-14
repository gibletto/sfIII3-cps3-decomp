/*
 * END_10_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_1000_0000();
extern void end_1000_1000();
extern void end_1000_2000();
extern void end_1000_4000();
extern void end_1001_1000();
extern void end_1002_1000();
extern void end_1003_1000();
extern void end_1003_2000();
extern void end_X_com01();

const PANEL end_1000_bg0_cell_tbl[8] = {
    { 0, 5 }, { 64, 6 }, { 4096, 1 }, { 4160, 2 }, { 8192, 3 }, { 8256, 4 }, { 12288, 7 }, { 12352, 8 },
};

const s16 timer_10_tbl[6] = {
    780, 720, 420, 780, 420, 660,
};

const s16 end_10_pos[6][2] = {
    { 256, 768 },
    { 256, 512 },
    { 256, 432 },
    { 256, 432 },
    { 256, 0 },
    { 256, 256 },
};
