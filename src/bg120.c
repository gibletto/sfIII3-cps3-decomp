/*
 * BG120.C  Stage backgrounds BG110 and BG120
 *
 * BG110 (with bg1100/bg1101 and their init and move routines) and BG120 (bg1201/bg1202)
 * each move their two layers, then run zoom check, display positions and family set.
 * bg1202_init00 loads BG120's graphics and starts effects 05, 06, the stage effect and 12.
 * bg_fam0C00 runs BG120's extra family layer.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFF58.h"
#include "bg000.h"
#include "eff05.h"
#include "eff06.h"
#include "eff12.h"
#include "EFF44.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "bg120.h"
static void bg1101_BG110(void) {
    void (*bg_jmp[2])() = { bg1101_init00, bg1101_move };
    bg_jmp[bgw_ptr->r_no_0]();
}



static void bg1100_BG110(void) {
    void (*bg_jmp[2])() = { bg1100_init00, bg1100_move };
    bg_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void BG110(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1101_BG110();
    bgw_ptr = &bg_w.bgw[0];
    bg1100_BG110();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1101(void) {
    void (*bg0602_jmp[2])() = { bg1101_init00, bg1101_move };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg1101_init00(void) {
    bgw_ptr->r_no_0 += 1;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1101_move(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg1100(void) {
    void (*bg1601_jmp[2])() = { bg1100_init00, bg1100_move };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1100_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1100_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



#pragma inline(bg1201, bg1202)



void BG120(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1202();
    bgw_ptr = &bg_w.bgw[0];
    bg1201();
    bgw_ptr = &bg_w.bgw[2];
    bg_fam0C00();
    bgw_ptr = &bg_w.bgw[6];
    bg_fam0C00();
    bgw_ptr = &bg_w.bgw[5];
    bg_fam0C00();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1201(void) {
    void (*bg1201_jmp[2])() = { bg1201_init00, bg_move_common };
    bg1201_jmp[bgw_ptr->r_no_0]();
}



void bg1201_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1202(void) {
    void (*bg1202_jmp[2])() = { bg1202_init00, bg_base_move_common };
    bg1202_jmp[bgw_ptr->r_no_0]();
}



void bg1202_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDAC0, 1);
    effect_05_init();
    effect_06_init();
    effect_55_init();
    effect_12_init(2);
}



void bg_fam0C00(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        switch (bgw_ptr->fam_no) {
        case 2:
            bgw_ptr->speed_x = 0xC000;
            bgw_ptr->speed_y = 0x10000;
            break;
        case 6:
            bgw_ptr->speed_x = 0x9000;
            bgw_ptr->speed_y = 0x10000;
            break;
        default:
            bgw_ptr->speed_x = 0x12000;
            bgw_ptr->speed_y = 0x10000;
            break;
        }
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    default:
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}
