#ifndef EFF58_H
#define EFF58_H

#include "structs.h"

void EFF58_Type_01(WORK_Other* ewk);
s32 effect_55_init(void);
s32 effect_56_init(s8 side);
s32 effect_57_init(s16 char_ix, s16 x, s16 y, s16 timer, s16 step, s16 z);
s32 effect_58_area_init(s16 time0, s16 step);
void EFF58_Type_03(WORK_Other* ewk);
void EFF58_Type_02(WORK_Other* ewk);
void effect_55_move(WORK_Other* ewk);
void effect_56_move(WORK_Other* ewk);
void effect_57_move(WORK_Other* ewk);
s32 effect_58_init(s16 id, s16 time0, s16 option);
void effect_58_move(WORK_Other* ewk);

void EFF58_Type_05(WORK_Other* ewk);

#endif
