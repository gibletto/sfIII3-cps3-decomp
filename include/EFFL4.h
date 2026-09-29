#ifndef EFFL4_H
#define EFFL4_H

#include "structs.h"

s32 effect_L4_init(void);
s32 effect_L5_init(WORK_Other* oya);
void effl6_flont(WORK_Other* ewk);
void effl6_back(WORK_Other* ewk);
void effect_L4_move(WORK_Other* ewk);
void effect_L5_move(WORK_Other* ewk);
s32 effect_L6_init(WORK* wk, u8 typel6);
void effect_L6_move(WORK_Other* ewk);
void hukuromoji_move(WORK_Other* ewk);

#endif
