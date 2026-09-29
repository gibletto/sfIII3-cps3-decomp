#ifndef VITAL_H
#define VITAL_H

#include "structs.h"

void end_waku_write(s8 mode);
void debug_scrfont_view(void);
void vital_cont_init(void);
s32 vital_parts_allwrite(s8 pl);
void count_cont_init();
void count_cont_reset(void);
void counter_control(void);
void counter_flash(s8 type);
void bcount_cont_init(u8 pl);
void bcount_cont_reset(void);
s32 bcounter_control(void);
s16 bcounter_down(u8 stop);
u32 counter_color_clear(void);
void bcount_cont_main(void);
s32 count_cont_main(void);
void vital_cont_main(void);
s32 vital_control(s8 pl);

#endif
