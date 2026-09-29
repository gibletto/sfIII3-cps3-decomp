/*
 * BG130.C  Stage backgrounds BG130-BG160, BG190 and the bonus stages
 *
 * Per-layer init and move routines for stages BG130, BG140, BG150, BG160 and BG190 and the
 * two bonus-stage backgrounds. Each stage routine moves bgw[1], bgw[0] and (where present)
 * a synchronised third layer, then runs zoom check, display positions and family set.
 * Base-layer inits load the stage graphics and start its scenery effects (05, 06, 12, 14,
 * 19, 25, 44, 74, 85, 94, I4, L4). Bonus_bg1 and Bonus_bg2 run the bonus stages without a
 * zoom check; bns11_init00 also creates the four effect 35 bonus-stage props.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFF74.h"
#include "EFFI4MV.h"
#include "EFFL4.h"
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



void bg1300_BG130(void) {
    void (*bg1601_jmp[2])() = { bg1300_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1301_BG130(void) {
    void (*bg1602_jmp[2])() = { bg1301_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG130(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1301_BG130();
    bgw_ptr = &bg_w.bgw[0];
    bg1300_BG130();
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



void bg1400_BG140(void) {
    void (*bg1601_jmp[2])() = { bg1400_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1401_BG140(void) {
    void (*bg1602_jmp[2])() = { bg1401_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG140(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1401_BG140();
    bgw_ptr = &bg_w.bgw[0];
    bg1400_BG140();
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
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    load_char_gfx(0xDA30, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init(0);
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



void bg1501_BG150(void) {
    void (*bg1601_jmp[2])() = { bg1501_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1502_BG150(void) {
    void (*bg1602_jmp[2])() = { bg1502_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG150(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1502_BG150();
    bgw_ptr = &bg_w.bgw[0];
    bg1501_BG150();
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

    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDE10, 1);
    load_char_gfx(0xE0A0, 1);
    effect_05_init();
    effect_12_init(5);
    effect_06_init();
    effect_44_init(8);
    effect_25_init(0);
    effect_94_init(0);
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



void bg1601_BG160(void) {
    void (*bg1601_jmp[2])() = { bg1601_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1602_BG160(void) {
    void (*bg1602_jmp[2])() = { bg1602_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG160(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1602_BG160();
    bgw_ptr = &bg_w.bgw[0];
    bg1601_BG160();
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



void bg1901_BG190(void) {
    void (*bg1601_jmp[2])() = { bg1901_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1902_BG190(void) {
    void (*bg1602_jmp[2])() = { bg1902_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG190(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1902_BG190();
    bgw_ptr = &bg_w.bgw[0];
    bg1901_BG190();
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



void Bonus_bg2(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        void (*jmp1[2])() = { bns11_init00, bns11_move };
        jmp1[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        void (*jmp0[2])() = { bns12_init00, bns12_move };
        jmp0[bgw_ptr->r_no_0]();
    }
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
    effect_35_init(2, plw[0].wu.operator ? 0 : 1);
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
