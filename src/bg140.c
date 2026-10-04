/*
 * BG140.C  Stage background BG140
 *
 * BG140 runs the stage's layers (bg1401, bg1400, bg1402), then zoom check, display positions and
 * family set. bg1401_init00 loads the stage graphics and starts effects 05, 06, 12 and 14;
 * bg1402 moves the synchronised third layer. bg1403 is not referenced: it waits for bg1403_wait
 * to run out, then lowers the layer to pos_y_work.
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
#include "bg140.h"

#pragma inline(bg1400, bg1401)



void BG140(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1401();
    bgw_ptr = &bg_w.bgw[0];
    bg1400();
    bgw_ptr = &bg_w.bgw[2];
    bg1402();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1401(void) {
    void (*bg1601_jmp[2])() = { bg1401_init00, bg_base_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1401_init00(void) {
    void* zero;
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    zero = 0;
    bgw_ptr->zuubun = (s32)zero;
    bg_app = (s32)zero;
    load_char_gfx(0xDA30, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init((s32)zero);
    effect_14_init(10);
}



void bg1400(void) {
    void (*bg080_sync_jmp[2])() = { bg1400_init00, bg_move_common };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg1400_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1402(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xA000;
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



/* provisional name: unreferenced; waits for bg1403_wait to run out, then lowers the layer to pos_y_work */
void bg1403(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (bgw_ptr->fam_no == 0) {
            bg1403_wait--;
        }
        if (bg1403_wait < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 1:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y << 2;
        if (bgw_ptr->xy[1].cal < bgw_ptr->pos_y_work) {
            bgw_ptr->xy[1].cal = bgw_ptr->pos_y_work;
            bgw_ptr->r_no_0++;
            bg_app = 0;
        }
        break;
    }
}
