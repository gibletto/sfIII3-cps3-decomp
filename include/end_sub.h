#ifndef END_SUB_H
#define END_SUB_H

#include "structs.h"

u32 card_work_clear(void);
void debug_play07_init(void);
void debug_play08_init(void);
void debug_play09_init(void);
void debug_play10_init(void);
void debug_play11_init(void);
void debug_play12_init(void);
void debug_play13_init(void);
void init_color_trans_req(void);
void load_any_color();
void load_bg_color();
void load_bg_color_fade(u16 col_no, u8 r, u8 g, u8 b);
void load_any_color_fade(u16 col_no, u8 r, u8 g, u8 b);
void load_any_color_attr(u16 col_no, u8 r, u8 g, u8 b);
void load_any_color_req();
void load_player_color();
void load_player_color_fade(u16 a, s16 b, s16 c, u8 d, u8 e, u8 f);
void load_char_eff_color();
void load_side_color(u8 side, u16 ix);
void load_player_sub_color(void);
void load_opt_color(u16 ix);
void card_msg_disp(void);
void cd_error_fatal_hang(s32 kind);
void cd_keep_spinning_tick(void);
void cd_selftest_periodic(void);
void debug_play07(void);
void debug_play08(void);
void debug_play09(void);
void debug_play10(void);
void debug_play11(void);
void debug_play12(void);
void debug_play13(void);
void debug_play07_move(void);
void debug_play08_move(void);
void debug_play09_move(void);
void debug_play10_move(void);
void debug_play11_move(void);
void debug_play13_move(void);
void debug_play12_move(void);
void metamor_color_restore(u16 wkid);
u32 card_win_check(s16 vs_mode);
void card_pl_work_clear(s16 pl);
s32 staff_roll_main();
s32 staff_roll_skip_check(void);
void staff_roll_put();
void color_trans_dummy(void);

#endif
