/*
 * END_2_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_200_0000();
extern void end_200_1000();
extern void end_200_2000();
extern void end_200_3000();
extern void end_201_1000();
extern void end_201_3000();
extern void end_202_1000();
extern void end_202_3000();
extern void end_202_4000();
extern void end_X_com01();

const PANEL end_200_panel0[6] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 5 }, { 8256, 6 },
};

const PANEL end_200_panel1[2] = {
    { 8192, 7 }, { 8256, 8 },
};

const s16 timer_2_tbl[5] = {
    480, 660, 120, 240, 780,
};

const s16 end_2_pos[5][2] = {
    { 256, 768 },
    { 320, 256 },
    { 512, 0 },
    { 320, 256 },
    { 320, 256 },
};
