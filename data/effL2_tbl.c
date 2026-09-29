/*
 * EFFL2_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void effl3_0000();
extern void effl3_0001();
extern void effl3_0002();

const s8 effl2_dir_tbl[2][16] = {
    { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3 },
};

/* The initial values of effl3_jp (effect_L3_move) in effL3.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 effl3_jp_init[3] = {
    (u32)effl3_0000,
    (u32)effl3_0001,
    (u32)effl3_0002,
};
