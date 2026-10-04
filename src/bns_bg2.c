/*
 * BNS_BG2.C  Second bonus stage background
 *
 * Bonus_bg2 moves bgw[1] and bgw[0] (bns11, bns12), then display positions and family set, with
 * no zoom check. bns11_init00 loads the stage graphics, starts effects 05 and 12 and creates the
 * effect 35 bonus-stage props.
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
#include "bns_bg2.h"

void Bonus_bg2(void) {
    bgw_ptr = &bg_w.bgw[1];
    bns11();
    bgw_ptr = &bg_w.bgw[0];
    bns12();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bns11(void) {
    void (*bg080_sync_jmp[2])() = { bns11_init00, bns11_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bns11_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    load_char_gfx(0xDFA0, 1);
    effect_05_init();
    effect_12_init(4);
    if (plw[0].wu.operator == 0) {
        effect_35_init(2, 1);
    } else {
        effect_35_init(2, 0);
    }
    effect_35_init(12, 2);
    effect_35_init(18, 3);
    effect_35_init(2, 4);
}



void bns11_move(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
}



void bns12(void) {
    void (*bg080_sync_jmp[2])() = { bns12_init00, bns12_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bns12_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bns12_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}
