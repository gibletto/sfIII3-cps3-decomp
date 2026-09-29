#ifndef EFFJ6_H
#define EFFJ6_H

#include "structs.h"

s32 effect_J2_init(s16 delay);
s32 effJ4_piece_set();
s32 effJ4_piece_set_stay();
s32 effect_J4_init2(s16 ix);
void effJ5_bg_write(void);
s32 effect_J3_init(WORK* wk, u8 type);
s32 effect_J4_init(u8 unused, u8 data);
s32 effect_J5_init(void);
void effect_J3_move(WORK_Other* ewk);
void effect_J4_move(WORK_Other* ewk);
void effect_J5_move(WORK_Other* ewk);
s32 effect_J6_init(WORK_Other* oya);
void effect_J6_move(WORK_Other* ewk);
void effect_j6_hit_sub(WORK_Other* ewk);

#endif
