#ifndef SPGAUGE_H
#define SPGAUGE_H

#include "structs.h"

void spgauge_cont_init(void);
s16 sa_color_chenge(s8 pl, s8 step);
void satime_stock_clear(void);
void sa_gauge_trans(s8 Stpl_Num, s16 Spg_Col);
void sa_moji_trans();
void sa_time_moji_send(void);
void sa_waku_trans();
void samoji_control(s8 pl);
void sa_gauge_color_set(s8 pl);
void sagauge_color_chenge(s8 pl);
void sast_control(s8 pl);
void spgauge_cont_demo_init(void);
void spgauge_cont_main(void);
void spgauge_control(s8 Spg_Num);
void spgauge_sound_request(s8 pl);
void spgauge_wipe_write(s8 Stpl_Num);
void spgauge_work_clear(s8 Stpl_Num);
void wipe_check(void);
void satime_ko_after_clear(s8 Stpl_Num);

#endif
