/*
 * BONUS_BG.C  First bonus stage background
 *
 * Bonus_bg1 moves bgw[1] and bgw[0] through their ROM jump tables (bns02, bns01), then display
 * positions and family set, with no zoom check. bns01_init00 loads the stage graphics and starts
 * effect 05.
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
#include "bonus_bg.h"

/* provisional name */
void Bonus_bg1(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        BG_JMP2 jmp1;
        jmp1 = bonus1_jmp1_tbl;
        jmp1.f[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        BG_JMP2 jmp0;
        jmp0 = bonus1_jmp0_tbl;
        jmp0.f[bgw_ptr->r_no_0]();
    }
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bns01(void) {
    void (*bg080_sync_jmp[2])() = { bns01_init00, bns01_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bns01_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    load_char_gfx(0xDCE0, 1);
    effect_05_init();
}



void bns01_move(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
}



void bns02(void) {
    void (*bg0602_jmp[2])() = { bns02_init00, bns02_move };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bns02_init00(void) {
    bgw_ptr->r_no_0 += 1;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bns02_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}
