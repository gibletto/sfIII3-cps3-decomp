/*
 * EFF93_TBL2.C  win mark colours and face-select BG slide routines
 *
 * win_mark_col_tbl is the colour of each kind of win mark, read by EFF92_CODE.C; Eff93_Jmp_Tbl
 * is the four slide routines (left, right, left out, right out) of the face-select BG, read by
 * EFF93.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Eff93_SLIDE_L();
extern void Eff93_SLIDE_L_OUT();
extern void Eff93_SLIDE_R();
extern void Eff93_SLIDE_R_OUT();

const s16 win_mark_col_tbl[10] = {
    14, 14, 14, 14, 14, 14, 14, 14,
    14, 0,
};

const Eff93_Jmp_Tbl_t Eff93_Jmp_Tbl[4] = {
    Eff93_SLIDE_L,
    Eff93_SLIDE_R,
    Eff93_SLIDE_L_OUT,
    Eff93_SLIDE_R_OUT,
};
