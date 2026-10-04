/*
 * BG150.C  Stage background BG150
 *
 * BG150 runs the stage's layers (bg1502, bg1501, bg1502_sync_common), then zoom check, display
 * positions and family set. bg1502_init00 loads the stage graphics and starts effects 05, 12, 06,
 * 44, 25, 94, I4 and 85.
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
#include "bg150.h"

#pragma inline(bg1501, bg1502)



void BG150(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1502();
    bgw_ptr = &bg_w.bgw[0];
    bg1501();
    bgw_ptr = &bg_w.bgw[2];
    bg1502_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1501(void) {
    void (*bg1601_jmp[2])() = { bg1501_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1501_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1502(void) {
    void (*bg1602_jmp[2])() = { bg1502_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void bg1502_init00(void) {
    void* zero;
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    zero = 0;
    bgw_ptr->zuubun = (s32)zero;
    load_char_gfx(0xDE10, 1);
    load_char_gfx(0xE0A0, 1);
    effect_05_init();
    effect_12_init(5);
    effect_06_init();
    effect_44_init(8);
    effect_25_init((s32)zero);
    effect_94_init((s32)zero);
    effect_94_init(1);
    effect_I4_init();
    effect_85_init();
}



void bg1502_sync_common(void) {
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
        bgw_ptr->speed_x = 0xF000;
        bgw_ptr->speed_y = 0xF000;
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}
