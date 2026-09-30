#ifndef EFFJ0_H
#define EFFJ0_H

#include "structs.h"

void effJ2_trans(WORK* ewk);
s32 effect_J0_init(WORK_Other* ek, WORK_Other* mk, s16 data);
void effect_J0_move(WORK_Other* ewk);
void effect_J2_move(WORK_Other_CONN* ewk);
void effect_J1_move(void);

s32 effect_J2_init(s16 delay);

#endif
