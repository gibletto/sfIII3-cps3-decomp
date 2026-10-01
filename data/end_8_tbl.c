/*
 * END_8_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_8000_0000();
extern void end_8000_0001();
extern void end_8000_0002();

const PANEL end_800_bg0_cell_tbl[11] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 4096, 4 }, { 4160, 5 }, { 4224, 10 }, { 4288, 11 }, { 8192, 6 },
    { 8256, 7 }, { 12288, 8 }, { 12352, 9 },
};

const s16 timer_8_tbl[4] = {
    840, 480, 900, 360,
};

const s16 end_8_pos[4][2] = {
    { 256, 768 },
    { 256, 512 },
    { 256, 0 },
    { 768, 512 },
};

/* Initial values of end_700_jp (end_800_move) in end_8.c. */
const u32 end_700_jp_init[4] = {
    (u32)end_8000_0000,
    (u32)end_8000_0001,
    (u32)end_8000_0002,
    (u32)end_8000_0002,
};
