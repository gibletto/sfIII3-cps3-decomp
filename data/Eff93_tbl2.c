/*
 * EFF93_TBL2.C  game tables
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
