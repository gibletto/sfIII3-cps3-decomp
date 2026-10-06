/*
 * BG050.C  Stage backgrounds BG050, BG180, BG060, BG070 and BG080
 *
 * Per-layer init and move routines for five stages. Each stage routine (BG050, BG180,
 * BG060, BG070, BG080) moves bgw[1], bgw[0] and a third synchronised layer (bgw[2]), then
 * runs zoom check, display positions and family set.
 * Layer inits set the start position (normally X 0x200), load the stage graphics and start
 * its scenery effects (05, 06, 14, 21, 22, 24, 44, 45, 60, 94, J5, J8); sync layers follow
 * the X/Y move checks with family 2's shadow display. bg1802_move and friends follow both
 * players, clamp the Y zoom and apply the chase guard. BG070's main layer uses a line-scroll
 * buffer allocated and cleared in bg0701_init00.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF45.h"
#include "EFF61.h"
#include "bg000.h"
#include "bg090.h"
#include "effj4.h"
#include "effj5.h"
#include "effj6.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "eff05.h"
#include "eff06.h"
#include "eff14.h"
#include "EFF21.h"
#include "EFF22.h"
#include "EFF24.h"
#include "EFF44.h"
#include "eff94.h"
#include "EFFJ8.h"
#include "aboutspr.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "ta_sub.h"
#include "bg050.h"



void BG050(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0502();
    bgw_ptr = &bg_w.bgw[0];
    bg0501();
    bgw_ptr = &bg_w.bgw[2];
    bg050_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0501(void) {
    void (*bg0801_jmp[2])() = { bg0501_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg0501_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0502(void) {
    void (*bg1602_jmp[2])() = { bg0502_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void bg0502_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9000, 1);
    effect_05_init();
    effect_06_init();
}



void bg050_sync_common(void) {
    void (*bg080_sync_jmp[2])() = { bg050_sync_init, bg050_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg050_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(2);
}

void bg050_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(2);
}



