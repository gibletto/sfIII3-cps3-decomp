/*
 * EFF94_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff94_0000();
extern void eff94_1000();
extern void eff94_2000();
extern void eff94_2000_0();
extern void eff94_2000_1();
extern void eff94_2000_2();
extern void eff94_2000_3();
extern void eff94_2000_4();
extern void eff94_3000();
extern void eff94_3000_0();
extern void eff94_3000_4();
extern void eff94_4000();

const s16 eff94_data_tbl[5][10] = {
    { 2, 8320, 392, 64, 12, 22, 52, 0, 0, 1 },
    { 2, 8320, 408, 75, 11, 23, 53, 0, 1, 1 },
    { 2, 8320, 640, 16, 10, 9, 10, 0, 4, 1 },
    { 2, 8320, 352, 272, 10, 2, 2, 0, 2, 1 },
    { 2, 8320, 352, 272, 10, 2, 2, 0, 3, 0 },
};

/* The initial values of eff94_move_jp (effect_94_move) in eff94.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 eff94_move_jp_init[5] = {
    (u32)eff94_0000,
    (u32)eff94_1000,
    (u32)eff94_2000,
    (u32)eff94_3000,
    (u32)eff94_4000,
};

const s16 eff94_2000_tbl[8] = {
    288, 336, 320, 288, 328, 296, 344, 304,
};

/* The initial values of eff94_2000_jp (eff94_2000) in eff94.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 eff94_2000_jp_init[5] = {
    (u32)eff94_2000_0,
    (u32)eff94_2000_1,
    (u32)eff94_2000_2,
    (u32)eff94_2000_3,
    (u32)eff94_2000_4,
};

const s8 eff94_2000_1_tbl[16] = {
    0, 1, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 0, 1, 1, 0, 1,
};

/* The initial values of eff94_jp (eff94_3000) in eff94.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 eff94_jp_init[4] = {
    (u32)eff94_3000_0,
    (u32)eff94_2000_2,
    (u32)eff94_2000_3,
    (u32)eff94_3000_4,
};

const s16 eff94_3000_tbl[4][3] = {
    { 328, 304, 0 },
    { 288, 240, 1 },
    { 280, 320, 0 },
    { 352, 264, 1 },
};
