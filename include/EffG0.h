#ifndef EFFG0_H
#define EFFG0_H

#include "structs.h"

void Check_Die_G0(WORK_Other_CONN* ewk);
s16 score_bunkai_G0(WORK_Other_CONN* ewk, u32 tsc);
s32 effect_G0_init(s16 Order, s16 Time, u32 Score, s16 Pos_Index);
void Flash_G0(WORK_Other_CONN* ewk);
void effG0_trans(WORK* ewk);
void effect_G0_move(WORK_Other* ewk);

#endif
