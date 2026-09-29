#ifndef EFFM5_H
#define EFFM5_H

#include "structs.h"

s32 effect_M3_init(WORK_Other_CONN* wk, s16 num);
u32 effect_M4_init(s16 type);
void effect_M4_move(WORK_Other* ewk);
s32 effect_M5_init(PLW* oya);
void effect_M5_move(WORK_Other* ewk);

#endif
