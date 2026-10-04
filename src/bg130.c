/*
 * BG130.C  Stage background BG130
 *
 * BG130 moves bgw[1] and bgw[0] through their layer routines (bg1301, bg1300) and a synchronised
 * third layer with bg1302, which also sets up the family layer on its first call, then runs the
 * zoom check, display positions and family set. bg1301_init00 loads the stage graphics and
 * starts effect 05.
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
#include "bg130.h"

#pragma inline(bg1300, bg1301)



void BG130(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1301();
    bgw_ptr = &bg_w.bgw[0];
    bg1300();
    bgw_ptr = &bg_w.bgw[2];
    bg1302();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1301(void) {
    void (*bg1601_jmp[2])() = { bg1301_init00, bg_base_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1301_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x2A00, 1);
    effect_05_init();
}



void bg1300(void) {
    void (*bg080_sync_jmp[2])() = { bg1300_init00, bg_move_common };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg1300_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1302(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xD0;
        bgw_ptr->speed_x = 0xE000;
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



