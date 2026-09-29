/*
 * PLCNT3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void plcnt_b2_die();
extern void plcnt_b2_move();
extern void plcnt_b_init();

void (*const player_bonus2_process[3])() = {
    plcnt_b_init,
    plcnt_b2_move,
    plcnt_b2_die,
};
