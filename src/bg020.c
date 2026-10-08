/*
 * BG020.C  Stage 02 background
 *
 * BG020 runs the three scroll layers and the sync layer of stage 02 through their dispatchers
 * (bg0201, bg0202, bg020_sync_common), then the zoom check, position correction and family set.
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
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "bg040.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFF61.h"
#include "EFF78.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "fifo.h"
#include "bg120.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF07.h"
#include "EFF11.h"
#include "eff14.h"
#include "EFF44.h"
#include "aboutspr.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Com_Pl.h"
#include "ta_sub.h"
#include "bg000.h"
#include "fighter.h"
#include "ta_sub2.h"
#include "tate00.h"

#pragma inline(bg0201, bg0202, bg020_sync_common)


void BG020(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0202();
    bgw_ptr = &bg_w.bgw[0];
    bg0201();
    bgw_ptr = &bg_w.bgw[2];
    bg0201();
    bgw_ptr = &bg_w.bgw[5];
    bg020_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_2_appoint(0);
    Bg_Family_Set_appoint(2);
}



void bg0201(void) {
    void (*bg0201_jmp[2])() = { bg0201_init00, bg_move_common };
    bg0201_jmp[bgw_ptr->r_no_0]();
}



void bg0201_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0202(void) {
    void (*bg0202_jmp[2])() = { bg0202_init00, bg_base_move_common };
    bg0202_jmp[bgw_ptr->r_no_0]();
}



void bg0202_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDF20, 1);
    effect_06_init();
    effect_78_entry();
}



void bg020_sync_common(void) {
    void (*bg0602_jmp[2])() = { bg020_sync_init, bg020_sync_move };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg020_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(5);
}

void bg020_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(5);
}



