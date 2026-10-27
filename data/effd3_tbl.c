/*
 * EFFD3_TBL.C  screen wipe and finish screen tables (effects D2, D3)
 *
 * EFFD3_Jmp_Tbl holds the two routines of a screen wipe panel, effD2_wipe_close and
 * effD2_wipe_open, called by EFFD2.C. ake_timer_tbl and ake_pos_tbl give, for each of the 13
 * pictures of the akebono finish screen, the frames it is shown and its BG3 x and y; read by
 * akebono_finish in EFFD3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void effD2_wipe_close();
extern void effD2_wipe_open();

void (*const EFFD3_Jmp_Tbl[2])() = {
    effD2_wipe_close,
    effD2_wipe_open,
};

const s16 ake_timer_tbl[13] = {
    4, 4, 4, 4, 4, 10, 10, 10,
    10, 10, 10, 10, 20,
};

const s16 ake_pos_tbl[13][2] = {
    { 256, 768 },
    { 768, 0 },
    { 256, 768 },
    { 768, 0 },
    { 256, 768 },
    { 768, 0 },
    { 256, 0 },
    { 768, 256 },
    { 256, 256 },
    { 768, 512 },
    { 256, 512 },
    { 768, 768 },
    { 256, 768 },
};

