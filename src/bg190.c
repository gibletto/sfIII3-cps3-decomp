/*
 * BG190.C  Stage background BG190
 *
 * BG190 runs the stage's layers (bg1901, bg1902, sync_bg14_common), then zoom check, display
 * positions and family set. bg1902_init00 loads the stage graphics and starts effects 05, 06,
 * 74, 14, L4, 44 and 12.
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
#include "EFF74.h"
#include "EFFI4MV.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "bg000.h"
#include "eff05.h"
#include "eff06.h"
#include "eff12.h"
#include "eff14.h"
#include "EFF19.h"
#include "EFF25.h"
#include "eff35.h"
#include "EFF44.h"
#include "EFF85.h"
#include "eff94.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "bg190.h"

#pragma inline(bg1901, bg1902)



void BG190(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1902();
    bgw_ptr = &bg_w.bgw[0];
    bg1901();
    bgw_ptr = &bg_w.bgw[2];
    sync_bg14_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1901(void) {
    void (*bg1601_jmp[2])() = { bg1901_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1901_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1902(void) {
    void (*bg1602_jmp[2])() = { bg1902_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void bg1902_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDD60, 1);
    effect_05_init();
    effect_06_init();
    effect_74_init();
    effect_14_init(8);
    effect_14_init(9);
    effect_L4_init();
    effect_44_init(6);
    effect_12_init(3);
}



void sync_bg14_common(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xD000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
