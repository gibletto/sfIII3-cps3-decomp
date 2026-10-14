/*
 * END_3_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 end_400_panel_tbl_0[];
extern const u32 end_400_panel_tbl_1[];

extern void end_300_0000();
extern void end_300_0002();
extern void end_300_0003();
extern void end_300_0004();
extern void end_300_0005();
extern void end_301_0003();
extern void end_X_com01();

const u32 end_400_panel_tbl_0[24] = {
    0, 1, 0x40, 2, 0x80, 3, 0xC0, 0,
    0x1000, 0x10, 0x1040, 0x11, 0x1080, 0x12, 0x10C0, 0,
    0x2000, 0x13, 0x2040, 0x14, 0x2080, 0x15, 0x20C0, 0,
};

const u32 end_400_panel_tbl_1[24] = {
    0, 4, 0x40, 5, 0x80, 6, 0xC0, 7,
    0x1000, 8, 0x1040, 9, 0x1080, 0xA, 0x10C0, 0xB,
    0x2000, 0xC, 0x2040, 0xD, 0x2080, 0xE, 0x10C0, 0xF,
};

