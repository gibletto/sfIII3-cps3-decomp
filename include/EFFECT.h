#ifndef EFFECT_H
#define EFFECT_H

#include "structs.h"

void effect_work_quick_init(void);
void effect_work_quick_clear(void);
s32 effect_work_pull_link(s16 index, s16 before, s16 aix);
s32 search_effect_index(s16 index, s16 flag, s16 tid);
void effect_work_init(void);
void effect_work_kill(s16 index, s16 kill_id);
s32 pull_effect_work(s16 index);
void move_effect_work(s16 index);
s32 push_effect_work(WORK* wkhd);
void work_init_zero(s32* adrs_int, s32 xx);
void work_init_copy(s32* src, s32* dst, s16 size);
void setup_meoshi_hit_flag(WORK* wk, u8 flag);
void clear_caution_flag(PLW* wk);
void reset_extra_bg_flag(WORK* wk);
void flip_my_rl_flag(WORK* wk);
void set_caution_flag(PLW* wk);
void setup_status_flag(WORK* wk, u8 status);
void setup_shell_hit_stop(WORK* wk, s16 tm, s16 fl);
void clear_my_shell_ix(WORK* wk);
s32 erase_my_shell_ix(WORK* wk, s16 ix);
s32 get_my_shell_ix(WORK* wk, s16 ix, WORK** tmw);
void write_my_shell_ix(WORK* wk, s16 ix);
s32 shell_live_check(PLW* wk, s16 wix);
s32 get_vs_shell_adrs(WORK* wk, s16 id, s16 ix, WORK_Other** tmw);
void effect_work_list_init();
void effect_work_list_release();

#endif
