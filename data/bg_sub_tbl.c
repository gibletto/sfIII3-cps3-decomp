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

/* Initial values of jump_tbl (TATE00) in tate00.c. */
const u32 jump_tbl_init[4] = {
    (u32)ta0_init00, (u32)ta0_init01, (u32)ta0_init02, (u32)ta0_move,
};

/* Scroll positions (x, y) for akebono_scrn_move (bg_sub.c). */
const s16 akebono_scrn_pos_tbl[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};

