/*
 * PLCNT3_TBL.C  player control phases for the second bonus stage type
 *
 * player_bonus2_process is the three phases (init, move, die) of player control in the second
 * bonus stage type. Read by PLCNT3.C.
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
