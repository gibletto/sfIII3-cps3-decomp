/*
 * BG_SUB_TBL_B.C  finish screen scroll positions
 *
 * akebono_scrn_pos_tbl gives the scroll x, y of each finish screen (akebono) page. Read by
 * akebono_scrn_move in BG000.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

/* Scroll positions (x, y) for akebono_scrn_move (bg_sub.c). */
/* provisional name */
const s16 akebono_scrn_pos_tbl[4][2] = {
    { 256, 256 }, { 768, 256 }, { 256, 0 }, { 768, 0 },
};

