/*
 * END_20_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_2000_0000();
extern void end_2000_0001();
extern void end_2000_0002();
extern void end_2000_0003();
extern void end_2000_0005();
extern void end_2001_0000();
extern void end_2001_0002();
extern void end_2001_0003();
extern void end_2001_0004();
extern void end_2001_0005();
extern void end_X_com01();

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

/* Initial values of end_900_jp (end_2000_move), end_2001_jp (end_2001_move) in end_20.c. */
const u32 end_20_local_init[12] = {
    (u32)end_2000_0000,
    (u32)end_2000_0001,
    (u32)end_2000_0002,
    (u32)end_2000_0003,
    (u32)end_2000_0002,
    (u32)end_2000_0005,
    (u32)end_2001_0000,
    (u32)end_X_com01,
    (u32)end_2001_0002,
    (u32)end_2001_0003,
    (u32)end_2001_0004,
    (u32)end_2001_0005,
};
