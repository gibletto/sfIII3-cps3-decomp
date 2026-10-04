#ifndef EFFD2_H
#define EFFD2_H

#include "structs.h"

void effD2_wipe_close(WORK_Other* ewk);
void effD2_wipe_open(WORK_Other* ewk);
s32 effect_D2_init(s16 vital, s16 dir, s16 family, s16 timer);
void effD2_pos_set(WORK_Other* ewk);
void effect_D2_move(WORK_Other* ewk);

#endif
