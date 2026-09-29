#ifndef EFFK7_H
#define EFFK7_H

#include "structs.h"

s32 chkNameExport(s16 name_no);
void K7_move_type_1(WORK_Other* ewk, PLW* mwk);
void K7_col_mode_flip(WORK* wk);
void K7_move_type_0(WORK_Other* ewk, PLW* mwk);
s16 K7_mt0_rebirth_check(PLW* mwk);
s32 effect_K7_init(PLW* wk);
void effect_K7_move(WORK_Other* ewk);

#endif
