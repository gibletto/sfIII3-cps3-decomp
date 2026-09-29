#ifndef EFF93_H
#define EFF93_H

#include "structs.h"

void Bg_Family_Set_Ex(s16 xx);
void Eff93_SLIDE_L(WORK_Other* ewk);
s32 effect_87_init(s16 type);
s32 effect_88_init(s16 type);
void eff89_cell_attr_set(WORK_Other* ewk, s16 attr);
s32 effect_89_init();
void eff91_cell_data_set(WORK_Other* ewk);
s32 effect_91_init(s16 type, s16 a, s16 b, s16 c, s16 d);
s32 effect_92_init(s16 pl, s16 type);
void Eff93_SLIDE_R(WORK_Other* ewk);
void Eff93_SLIDE_L_OUT(WORK_Other* ewk);
void Eff93_SLIDE_R_OUT(WORK_Other* ewk);
s32 effect_93_init(s8 Move_Type, s16 Time);
void effect_87_move(WORK_Other* ewk);
void effect_88_move(WORK_Other* ewk);
void effect_89_move(WORK_Other* ewk);
void effect_90_move(WORK_Other* ewk);
void effect_91_move(WORK_Other* ewk);
void effect_92_move(WORK_Other* ewk);
void effect_93_move(WORK_Other* ewk);

#endif
