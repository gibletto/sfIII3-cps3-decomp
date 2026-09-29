/*
 * BG_SUB_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void ta0_init00();
extern void ta0_init01();
extern void ta0_init02();
extern void ta0_move();

const s8 bg_test_stage_tbl[14][2] = {
    { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 },
    { 8, 0 }, { 9, 9 }, { 13, 0 }, { 20, 0 }, { 21, 0 }, { 0, 0 },
};

/* The initial values of jump_tbl (TATE00) in tate00.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 jump_tbl_init[4] = {
    (u32)ta0_init00, (u32)ta0_init01, (u32)ta0_init02, (u32)ta0_move,
};

/* Stored after bg_test_stage_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of bg_test_stage_tbl. */
const u32 jump_tbl_tail[4] = {
    0x1000100, 0x3000100, 0x1000000, 0x3000000,
};

