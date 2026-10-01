#ifndef EFFA7_H
#define EFFA7_H

#include "structs.h"

u32 effect_A8_init(void);
void Setup_A9(WORK_Other* ewk, s16 Char_Index, s16 Option, s16 Option2);
s32 effect_A7_init(PLW* wk);
s32 effect_A7_move(WORK_Other* ewk);
void effect_A8_move(WORK_Other* ewk);
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2);
void effect_A9_move(WORK_Other* ewk);

#endif
