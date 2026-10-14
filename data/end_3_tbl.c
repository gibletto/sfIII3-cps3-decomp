/*
 * END_3_TBL.C  game tables
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

const PANEL end_300_bg0_cell_tbl[12] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 1 }, { 8256, 2 }, { 8320, 11 }, { 8384, 12 },
};

const s16 end_3_pos[6][2] = {
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 768, 544 },
    { 256, 256 },
    { 768, 256 },
};

const s16 timer_3_tbl[6] = {
    660, 420, 1080, 900, 720, 1020,
};
