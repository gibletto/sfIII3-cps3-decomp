/*
 * END_MAIN_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void op_bg0_0000();
extern void op_bg0_0001();
extern void op_bg0_0002();
extern void op_bg0_0003();
extern void op_bg0_0004();
extern void op_bg0_0005();
extern void op_bg0_0006();
extern void op_bg0_0007();
extern void op_bg0_0008();
extern void op_bg0_0010();
extern void op_bg0_0011();
extern void op_bg0_0012();
extern void op_bg0_0013();
extern void op_bg0_0014();
extern void op_bg0_0015();
extern void op_bg0_0016();
extern void op_bg1_0003_move();
extern void opening_capcom_scene_init();
extern void opening_init2();
extern void opening_move();

const s16 op_bg0_0001_tbl[16] = {
    4, -8, 2, 1, -6, -3, 9, -3,
    8, -2, 6, 3, -4, -9, 3, -1,
};

const u8 op_scr_record_data[4][56] = {
    { 0, 1, 0, 75, 0, 127, 127, 0, 0, 12, 0, 255, 127, 0, 0, 12, 1, 127, 127, 0, 0, 12, 1, 255, 127, 0, 0, 12, 2, 127, 127, 0, 0, 12, 2, 255, 127, 0, 0, 12, 3, 127, 127, 0, 0, 12, 3, 255, 127, 0, 0, 12, 255, 255, 255, 255 },
    { 0, 2, 0, 80, 0, 127, 127, 0, 0, 28, 0, 255, 127, 0, 0, 28, 1, 127, 127, 0, 0, 28, 1, 255, 127, 0, 0, 28, 2, 127, 127, 0, 0, 28, 2, 255, 127, 0, 0, 28, 3, 127, 127, 0, 0, 28, 3, 255, 127, 0, 0, 28, 255, 255, 255, 255 },
    { 0, 3, 0, 85, 0, 127, 127, 0, 0, 44, 0, 255, 127, 0, 0, 44, 1, 127, 127, 0, 0, 44, 1, 255, 127, 0, 0, 44, 2, 127, 127, 0, 0, 44, 2, 255, 127, 0, 0, 44, 3, 127, 127, 0, 0, 44, 3, 255, 127, 0, 0, 44, 255, 255, 255, 255 },
    { 0, 4, 0, 88, 0, 127, 127, 0, 0, 60, 0, 255, 127, 0, 0, 60, 1, 127, 127, 0, 0, 60, 1, 255, 127, 0, 0, 60, 2, 127, 127, 0, 0, 60, 2, 255, 127, 0, 0, 60, 3, 127, 127, 0, 0, 60, 3, 255, 127, 0, 0, 60, 255, 255, 255, 255 },
};

/* Initial values of opening_demo_jp (opening_demo_tick) in lose_pl.c. */
const u32 opening_demo_jp_init[3] = {
    (u32)opening_init2,
    (u32)opening_move,
    (u32)opening_capcom_scene_init,
};

const s16 op_101_tbl[2] = {
    0, 11,
};

const s16 op_102_tbl[3] = {
    0, 9, 12,
};

const s16 op_103_tbl[12] = {
    0, 1, 2, 3, 4, 5, 7, 8,
    9, 11, 12, 13,
};

const s16 op_106_tbl[4] = {
    0, 1, 3, 7,
};

const s16 op_107_tbl[12] = {
    0, 1, 2, 3, 4, 5, 7, 8,
    9, 11, 12, 13,
};

const s16 op_108_tbl[13] = {
    0, 4, 20, 24, 28, 32, 48, 52,
    60, 64, 76, 80, 86,
};

const s16 op_109_tbl[5] = {
    0, 3, 5, 7, 11,
};

const s16 op_110_tbl[6] = {
    0, 0, 3, 4, 7, 9,
};

const s16 op_111_tbl[5] = {
    0, 2, 4, 7, 11,
};

const s16 op_112_tbl[9] = {
    0, 8, 8, 14, 19, 26, 34, 40,
    44,
};

const s16 op_113_tbl[4] = {
    0, 3, 7, 11,
};

const s16 op_114_tbl[6] = {
    0, 2, 3, 4, 7, 9,
};

const s16 op_115_tbl[2] = {
    0, 7,
};

const OP_BG0_JP op_bg0_jp_tbl[1] = {
    { { op_bg0_0000, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0015, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0015, op_bg0_0001, op_bg0_0000, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0000, op_bg0_0004, op_bg0_0001, op_bg0_0001, op_bg0_0004, op_bg0_0005, op_bg0_0002, op_bg0_0001, op_bg0_0002, op_bg0_0001, op_bg0_0002, op_bg0_0006, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0007, op_bg0_0008, op_bg0_0000, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0000, op_bg0_0004, op_bg0_0001, op_bg0_0004, op_bg0_0001, op_bg0_0002, op_bg1_0003_move, op_bg0_0002, op_bg0_0010, op_bg0_0002, op_bg0_0011, op_bg0_0012, op_bg0_0013, op_bg0_0014, op_bg0_0002, op_bg0_0016 } },
};

const s16 op_bg0_0004_tbl[6] = {
    45, 46, 45, 46, 47, 42,
};
