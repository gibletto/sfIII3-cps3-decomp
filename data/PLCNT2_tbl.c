/*
 * PLCNT2_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void plcnt_b_die();
extern void plcnt_b_init();
extern void plcnt_b_move();

const s16 bsmr_range_table[3][2][2] = {
    { { 192, 192 }, { 192, 192 } },
    { { 64, 192 }, { 224, -136 } },
    { { -112, 224 }, { 216, 40 } },
};

void (*const player_bonus_process[3])() = {
    plcnt_b_init,
    plcnt_b_move,
    plcnt_b_die,
};
