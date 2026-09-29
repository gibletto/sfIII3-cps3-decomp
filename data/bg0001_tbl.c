/*
 * BG0001_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Game_Dummy();
extern void game_phase_dispatch();
extern void match_state_0_fight();

const GAME_TASK_JMP Main_Jmp_Data[1] = {
    { { match_state_0_fight, game_phase_dispatch, Game_Dummy } },
};
