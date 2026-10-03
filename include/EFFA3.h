#ifndef EFFA3_H
#define EFFA3_H

#include "structs.h"

s32 Check_Sleep_A5(WORK_Other* ewk);
void effA3_area_clear(WORK_Other* ewk);
void effA3_cell_put(WORK_Other* ewk);
s32 effect_A3_init(s16 type, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f, s16 g, s16 h);
s32 effect_A4_init(s16 PL_id);
u32 effect_A5_entry(void);
s32 effA5_shot_pressed(void);
s32 effA5_start_pressed(void);
void effect_A3_move(WORK_Other* ewk);
void effect_A4_move(WORK_Other* ewk);
void effect_A5_move(WORK_Other* ewk);

#endif
