/*
 * EFFB2_TBL.C  round-start FIGHT call tables (effect B2)
 *
 * effb2_sound_tbl holds the four round-call voices, one picked at random each round, and
 * fight_col_move_tbl is the colour sequence stepped through by the FIGHT colour flash
 * (fight_col_chg_sub). Read by EFFB2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effb2_sound_tbl[4] = {
    128, 130, 132, 134,
};

const s16 fight_col_move_tbl[18] = {
    6, 7, 8, 9, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11,
    12, 0,
};
