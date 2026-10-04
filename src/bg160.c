/*
 * BG160.C  Stage background BG160
 *
 * BG160 runs the stage's layers (bg1601, bg1602, bg1602_sync_common), then zoom check, display
 * positions and family set. bg1602_init00 loads the stage graphics and starts effects 05, 06,
 * 44, 19 and 94.
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
#include "bg160.h"

#pragma inline(bg1601, bg1602)



void BG160(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1602();
    bgw_ptr = &bg_w.bgw[0];
    bg1601();
    bgw_ptr = &bg_w.bgw[2];
    bg1602_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1601(void) {
    void (*bg1601_jmp[2])() = { bg1601_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1601_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1602(void) {
    void (*bg1602_jmp[2])() = { bg1602_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void bg1602_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDBF0, 1);
    effect_05_init();
    effect_06_init();
    effect_44_init(2);
    effect_19_init();
    effect_94_init(2);
}



void bg1602_sync_common(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->fam_no = 2;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->pos_y_work = 0;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->speed_x = 0x12000;
        bgw_ptr->speed_y = 0x10000;
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}
