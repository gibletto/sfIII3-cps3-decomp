#ifndef CMB_CONT_H
#define CMB_CONT_H

#include "structs.h"

void SCORE_PLUS(s8 PL, u32 PTS);
s32 arts_finish_check(s8 PL);
void combo_cont_init(void);
void combo_cont_main(void);
void combo_control(s32 pl_arg);
void combo_hensuu_clear(s8 PL);
void combo_rp_clear_check();
void combo_window_push(s8 PL, s8 KIND);
u32 SCORE_CALCULATION(s8 PL);
void combo_window_trans(s8 PL);
void first_attack_pts_check(s8 PL);
void hit_combo_check(s8 PL);
s32 paring_check(s8 PL);
s32 reversal_check(s8 PL);
void reversal_continue_check(s8 PL);
void super_arts_finish_check(s8 PL);
s32 arts_finish_check2(s8 PL);
void super_arts_last_check(s8 PL);

#endif
