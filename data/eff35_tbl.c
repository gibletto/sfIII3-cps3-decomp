/*
 * EFF35_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff35_0000();
extern void eff35_0001();
extern void eff35_0002();
extern void eff35_0003();
extern void eff35_0004();
extern void eff35_0005();
extern void eff35_0006();

const s16 eff35_data_tbl[12][7] = {
    { 608, 0, 28, 1, 1, 0, 60 },
    { 432, 0, 28, 1, 2, 0, 60 },
    { 848, 20, 81, 1, 3, 3, 60 },
    { 512, 8, 82, 1, 4, 3, 60 },
    { 512, 0, 75, 7, 1, 4, 60 },
    { 0, 118, 20, 12, 1, 5, 60 },
    { 0, 118, 20, 12, 2, 5, 60 },
    { 0, 112, 20, 12, 3, 6, 60 },
    { 0, 112, 20, 12, 4, 6, 60 },
    { 0, 118, 20, 12, 5, 5, 60 },
    { 0, 118, 20, 12, 6, 6, 60 },
    { 0, 118, 20, 12, 7, 6, 60 },
};

/* Initial values of eff35_jp (effect_35_move) in eff35.c. */
const u32 eff35_jp_init[7] = {
    (u32)eff35_0000,
    (u32)eff35_0001,
    (u32)eff35_0002,
    (u32)eff35_0003,
    (u32)eff35_0004,
    (u32)eff35_0005,
    (u32)eff35_0006,
};

const s16 eff35_03_b[4] = {
    180, 120, 240, 60,
};

const s16 eff35_03_s[4] = {
    190, 130, 220, 60,
};
