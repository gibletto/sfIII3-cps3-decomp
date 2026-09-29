#ifndef EFFB4_H
#define EFFB4_H

#include "structs.h"

s32 effect_B3_init(WORK_Other* wk);
void effect_B3_move(WORK_Other* ewk);
s32 effect_B4_init(WORK_Other* oya);
void effect_B4_move(WORK_Other* ewk);
void fight_col_move(WORK_Other* ewk);
void fight_move(WORK_Other* ewk);
void fight_vanish(WORK_Other* ewk);
void round_move(WORK_Other* ewk);
void round_move_init(WORK_Other* ewk);

#endif
