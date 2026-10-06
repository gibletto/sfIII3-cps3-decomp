#ifndef CMB_WIN_H
#define CMB_WIN_H

#include "structs.h"

void sc_vram_to_ram(void);
void combo_window_all_clear(void);
void combo_message_set();
void combo_hitnum_set();
s16 combo_pts_set();
void combo_window_slide(s8 PL, s16 x, s16 y, s16 n);
void combo_window_erase(s8 PL, s8 kind, s16 y);

void end_waku_write(s8 mode);

#endif
