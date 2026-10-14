/*
 * BG_SUB_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void ta0_init00();
extern void ta0_init01();
extern void ta0_init02();
extern void ta0_move();

/* Scroll positions (x, y) for akebono_scrn_move (bg_sub.c). */
const s16 akebono_scrn_pos_tbl[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};

