/*
 * EFF86_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff86_0000();

const s16 eff86_data_tbl00[7] = {
    0, 2, 8224, 511, 56, 10, 18,
};

/* The initial values of eff86_jp_tbl (effect_86_move) in EFF86.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const eff86_jp_tbl_init[1])() = {
    eff86_0000,
};
