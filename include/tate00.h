#ifndef TATE00_H
#define TATE00_H

#include "structs.h"

void cal_bg_speed_data();
void ta0_init00(void);
void ta0_init01(void);
void ta0_init02(void);
void cal_bg_speed_data_x(s16 bg_num, s16 tm, s16 dummy);
void ta0_move(void);
void cal_bg_speed_data_y(s16 bg_num, s16 tm, s16 dummy);
void TATE00(void);

#endif
