#ifndef SC_SUB_H
#define SC_SUB_H

#include "structs.h"

void win_mark_pos_set(s16 pl);
u32 win_mark_all_write(u32 pl);
void fade_cont_init(void);
s32 fade_cont_main();
void win_mark_control(s16 id);
void win_mark_new_check(s16 pl);
void win_mark_write(s16 pl);
void stngauge_cont_init(void);
void stngauge_cont_main();
void stngauge_control(s32 player);
void stngauge_work_clear(void);
void stun_gauge_waku_write(s8 pl);
void stun_mark_write(s8 pl, s8 ix);
void stun_put();

#endif
