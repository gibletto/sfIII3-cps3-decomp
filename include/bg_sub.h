#ifndef BG_SUB_H
#define BG_SUB_H

#include "structs.h"

void Bg_Family_Set(void);
void Bg_Family_Set_2(void);
void Bg_Family_Set_2_appoint(s32 num_of_bg);
void Bg_Family_Set_appoint(s32 num_of_bg);
void Bg_mv_tw(s32 value_x, s32 value_y);
s32 remake_mvstep();
s32 zoom_frame_judge(void);
void zoom_x_width_check(void);
s32 zoom_y_width_check(void);
void ake_Family_Set(void);
void bg_pos_hosei_sub3(s16 bg);
void ake_cell_write(s8 map, s32 ofs, s32 cell, u32 src);
void ake_cell_write_attr(s8 map, s32 ofs, s32 cell, u32 src, s16 attr);
void akebono_cell_fill(void);
void bg_scr_clear_all(void);
void compel_bg_init_position(void);
void ake_Family_Set2(void);
void bg_work_clear(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void blit_16x16_yflip(u16* src, s16 code, u16* dst, s16 attr);
void bg_cell_write_yflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void blit_16x16_xflip(u16* src, s16 code, u16* dst, s16 attr);
void bg_cell_write_xflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void blit_16x16_tile(u16* src, s16 code, u16* dst, s16 attr);
void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void blit_16x16_xyflip(u16* src, s16 code, u16* dst, s16 attr);
void bg_cell_write_xyflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void bg_cell_fill(s16 bg, s16 attr);
void blit_8x16_tile(u16* src, s16 code, u16* dst, s16 attr);
void bg_scr_write(void);
void bg_debug_scroll_layers(void);
void bg_layers_off(void);
void bg_free_work_blocks(void);
void bg_chase_move(void);
void chase_start_check(void);
s32 chase_xy_move(void);
void bg_test_stage_select(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);
void scr_10_21(void);
void scr_11_20(void);
void scr_11_22(void);
void scr_12_21(void);
void scr_12_22(void);
s32 suzi_line_calc(s16 bg_num);
s32 suzi_line_calc_fill(s16 bg_num);
s32 suzi_line_calc_flat(s16 bg_num);
void suzi_line_clear(s16 bg_num);
s32 suzi_line_calc2(s16 bg_no);
s32 bg_debug_stage_change(void);
void bg_base_x_move_sub(void);
s16 get_center_position(void);
s32 remake_x_mvstep(s16 x);
void check_cg_zoom(void);
void akebono_scr_write(void);
void bg_etc_scr_write(s16 type);
void scr_10_22(void);
void scr_11_21(void);
void scr_12_20(void);
void bg_pos_hosei_sub2(s16 bg_no);
s32 suzi_offset_set(WORK* wk);
u32 suzi_offset_set_sub(WORK* wk);
void suzi_sync_pos_set(WORK_Other* ewk);
void Bg_mv_tw_appoint(s16 bg_num, s32 dx, s32 dy);
s32 get_height_position(void);
void bg_pos_hosei2(void);
void x_left_check(s16 d0);
void scr_x_dummy(void);
void scr_10_20(void);
void x_right_check(s16 d1);
void zoom_ud_check(void);

#endif
