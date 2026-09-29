/*
 * EFFF5_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void efff5_0008();
extern void efff5_0000();
extern void efff5_0001();
extern void efff5_0002();
extern void efff5_0003();
extern void efff5_0004();
extern void efff5_0005();
extern void efff5_0006();
extern void efff5_0007();
extern void efff5_0009();
extern void efff5_0010();
extern void efff5_0011();

const s16 efff5_data_tbl[22][6] = {
    { 8, 512, 144, 71, 100, 0 },
    { 0, 512, 48, 50, 54, 1 },
    { 1, 512, 40, 52, 62, 1 },
    { 0, 512, 48, 50, 57, 1 },
    { 2, 512, 64, 78, 58, 1 },
    { 2, 512, 0, 78, 58, 1 },
    { 0, 512, 48, 50, 63, 1 },
    { 0, 512, 48, 50, 64, 1 },
    { 3, 512, 53, 52, 58, 0 },
    { 4, 688, 126, 70, 66, 0 },
    { 5, 512, 48, 50, 52, 1 },
    { 5, 512, 48, 50, 54, 1 },
    { 5, 512, 48, 50, 63, 1 },
    { 5, 512, 48, 50, 64, 1 },
    { 4, 688, 126, 70, 24, 0 },
    { 7, 512, 48, 84, 86, 0 },
    { 8, 512, 144, 71, 91, 0 },
    { 8, 512, 144, 70, 92, 0 },
    { 8, 512, 144, 72, 93, 0 },
    { 9, 512, 144, 68, 93, 0 },
    { 10, 608, 408, 54, 91, 0 },
    { 11, 864, 120, 54, 92, 0 },
};

/* The initial values of efff5_jp (effect_F5_move) in efff5.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 efff5_jp_init[12] = {
    (u32)efff5_0000,
    (u32)efff5_0001,
    (u32)efff5_0002,
    (u32)efff5_0003,
    (u32)efff5_0004,
    (u32)efff5_0005,
    (u32)efff5_0006,
    (u32)efff5_0007,
    (u32)efff5_0008,
    (u32)efff5_0009,
    (u32)efff5_0010,
    (u32)efff5_0011,
};
