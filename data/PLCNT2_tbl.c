/*
 * PLCNT2_TBL.C  player control tables for the bonus stage
 *
 * player_bonus_process is the three phases of bonus-stage player control (init, move, die);
 * bsmr_range_table gives the screen range offsets of each player by stage type, used to set
 * their screen facing. Read by PLCNT2.C.
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
