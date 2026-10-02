/*
 * BG040.C  Stage background BG040 (and BG030 base layer)
 *
 * bg0301 and bg0301_init finish stage BG030: its base layer is initialised at X 0x200, its
 * graphics loaded and the stage effects 05, 06, 08, 71 and L2 started.
 * BG040 runs one frame of stage BG040: it moves the far layer (bg0402) and the main layer
 * (bg0401) through their init and common move routines, then calls zoom_ud_check,
 * bg_pos_hosei2 and Bg_Family_Set_2. bg0401_init00 loads the stage graphics and starts
 * effects 12, 06, 44 and 53.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFF71.h"
#include "bg000.h"
#include "eff05.h"
#include "eff06.h"
#include "eff08.h"
#include "eff12.h"
#include "EFF44.h"
#include "EFF53.h"
#include "effL2.h"
#include "aboutspr.h"
#include "bg040.h"
#include "sys_test.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "EFF61.h"
#include "EFF78.h"
#include "SE.h"
#include "fifo.h"
#include "bg120.h"
#include "EFF07.h"
#include "EFF11.h"
#include "eff14.h"
#include "appear.h"
#include "sys_config.h"
#include "Com_Pl.h"
#include "ta_sub.h"
#include "fighter.h"



void BG030(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0301();
    bgw_ptr = &bg_w.bgw[0];
    bg0300();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0300(void) {
    void (*bg0602_jmp[2])() = { bg0300_init00, bg_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg0300_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_14_init(5);
}



void bg0301(void) {
    void (*bg080_sync_jmp[2])() = { bg0301_init, bg_base_move_common };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}


void bg0301_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xD990, 1);
    effect_05_init();
    effect_06_init();
    effect_08_init();
    effect_71_init();
    effect_L2_init();
}



void bg0401_BG040(void) {
    void (*bg0401_jmp[3])() = { bg0401_init00, bg0401_init01, bg_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}



void bg0402_BG040(void) {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_init01, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}



void bg0402_bg040(void) {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_init01, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}



void BG040(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0402_BG040();
    bgw_ptr = &bg_w.bgw[0];
    bg0401_BG040();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_2();
}



void bg0401(void) {
    void (*bg0401_jmp[3])() = { bg0401_init00, bg0401_init01, bg_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}



void bg0401_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDB40, 1);
    effect_12_init(1);
    effect_06_init();
    effect_44_init(3);
    effect_53_init();
}



void bg0401_init01(void) {
    bgw_ptr->r_no_0++;
}



void bg0402(void) {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_init01, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}



void bg0402_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0402_init01(void) {
    bgw_ptr->r_no_0++;
}
