/*
 * BG050.C  Stage backgrounds BG050, BG180, BG060, BG070 and BG080
 *
 * Per-layer init and move routines for five stages. Each stage routine (BG050, BG180,
 * BG060, BG070, BG080) moves bgw[1], bgw[0] and a third synchronised layer (bgw[2]), then
 * runs zoom check, display positions and family set.
 * Layer inits set the start position (normally X 0x200), load the stage graphics and start
 * its scenery effects (05, 06, 14, 21, 22, 24, 44, 45, 60, 94, J5, J8); sync layers follow
 * the X/Y move checks with family 2's shadow display. bg1802_move and friends follow both
 * players, clamp the Y zoom and apply the chase guard. BG070's main layer uses a line-scroll
 * buffer allocated and cleared in bg0701_init00.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFF45.h"
#include "EFF61.h"
#include "bg000.h"
#include "bg090.h"
#include "effJ6.h"
#include "sys_config.h"
#include "sys_test.h"
#include "eff05.h"
#include "eff06.h"
#include "eff14.h"
#include "EFF21.h"
#include "EFF22.h"
#include "EFF24.h"
#include "EFF44.h"
#include "eff94.h"
#include "EFFJ8.h"
#include "aboutspr.h"
#include "meta_col.h"
#include "ta_sub.h"
#include "bg050.h"



void BG050(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        void (*bg0502_jmp[2])() = { bg0502_init00, bg_base_move_common };
        bg0502_jmp[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        void (*bg0501_jmp[2])() = { bg0501_init00, bg_move_common };
        bg0501_jmp[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[2];
    {
        void (*bg050_sync_jmp[2])() = { bg050_sync_init, bg050_sync_move };
        bg050_sync_jmp[bgw_ptr->r_no_0]();
    }
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0501(void) {
    void (*bg0801_jmp[2])() = { bg0501_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg0501_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0502(void) {
    void (*bg1602_jmp[2])() = { bg0502_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void bg0502_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9000, 1);
    effect_05_init();
    effect_06_init();
}



void bg050_sync_common(void) {
    void (*bg080_sync_jmp[2])() = { bg050_sync_init, bg050_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg050_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(2);
}

void bg050_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(2);
}



void BG180(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        void (*jmp1[2])() = { bg1802_init00, bg1802_move };
        jmp1[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        void (*jmp0[2])() = { bg1801_init00, bg1801_move };
        jmp0[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[2];
    {
        void (*jmp2[2])() = { bg180_sync_init, bg180_sync_move };
        jmp2[bgw_ptr->r_no_0]();
    }
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1801(void) {
    void (*bg0801_jmp[2])() = { bg1801_init00, bg1801_move };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg1801_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1801_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg1802(void) {
    void (*bg1601_jmp[2])() = { bg1802_init00, bg1802_move };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg1802_init00(void) {

    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9000, 1);
    effect_05_init();
    effect_06_init();
    effect_22_init();
    effect_44_init(4);
    effect_14_init(6);
    effect_14_init(7);
}



void bg1802_move(void)
{
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg180_sync_common(void) {
    void (*bg080_sync_jmp[2])() = { bg180_sync_init, bg180_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg180_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(2);
}

void bg180_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(2);
}



void bg0601_BG060(void) {
    void (*bg1601_jmp[2])() = { bg0601_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg0602_BG060(void) {
    void (*bg1602_jmp[2])() = { bg0602_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG060(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0602_BG060();
    bgw_ptr = &bg_w.bgw[0];
    bg0601_BG060();
    bgw_ptr = &bg_w.bgw[2];
    bg0603();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0601(void) {
    void (*bg1601_jmp[2])() = { bg0601_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg0601_init00(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0;
}



void bg0602(void) {
    void (*bg0602_jmp[2])() = { bg0602_init00, bg_base_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg0602_init00(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0;
    load_char_gfx(0xDA70, 1);
    effect_05_init();
    effect_60_init(0);
    effect_60_init(1);
    effect_44_init(1);
    effect_24_init();
}



void bg0603(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0x10800;
        bgw_ptr->speed_y = 0x10000;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}



void bg0701_BG070(void) {
    void (*bg1601_jmp[2])() = { bg0701_init00, bg0701_move00 };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg0702_BG070(void) {
    void (*bg1602_jmp[2])() = { bg0702_init00, bg_base_move_common };
    bg1602_jmp[bgw_ptr->r_no_0]();
}



void BG070(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0702_BG070();
    bgw_ptr = &bg_w.bgw[0];
    bg0701_BG070();
    bgw_ptr = &bg_w.bgw[2];
    bg0703();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0701(void) {
    void (*bg1601_jmp[2])() = { bg0701_init00, bg0701_move00 };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg0701_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    effect_J5_init();
    bgw_ptr->suzi_c_no = simmram_small_page_alloc_40(1);
    bgw_ptr->suzi_adrs = (u16*)simmram_slot_addr(bgw_ptr->suzi_c_no);
    scrn_linescroll_set_now(0, bgw_ptr->suzi_adrs);
    memset(bgw_ptr->suzi_adrs, 0, 0x1000);
    scroll_layer_mask_enable(16);
    suzi_line_clear(0);
    bgw_ptr->zuubun = 0xE3;
    bgw_ptr->no_suzi_line = 0x200;
    bgw_ptr->u_line = 0x18F;
    bgw_ptr->d_line = 112;
    bgw_ptr->start_suzi = bgw_ptr->suzi_adrs + 0x400;
}

void bg0701_move00(void) {
    bg_x_move_check();
    bg_y_move_check();
    suzi_line_calc2(0);
}



void bg0702(void) {
    void (*bg080_sync_jmp[2])() = { bg0702_init00, bg_base_move_common };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg0702_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDCA0, 1);
    effect_06_init();
    effect_94_init(3);
    effect_J8_init();
}



void bg0703(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0 += 1;
        bgw_ptr->fam_no = 2;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xC0;
        bgw_ptr->speed_x = 0xE000;
        bgw_ptr->speed_y = 0xF800;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}



void bg0801_BG080(void) {
    void (*bg0801_jmp[2])() = { bg0801_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg0802_BG080(void) {
    void (*bg0802_jmp[2])() = { bg0802_init00, bg_base_move_common };
    bg0802_jmp[bgw_ptr->r_no_0]();
}



void bg080_sync_common_BG080(void) {
    void (*bg080_sync_jmp[2])() = { bg080_sync_init, bg080_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg0801_bg080(void) {
    void (*bg0801_jmp[2])() = { bg0801_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg0802_bg080(void) {
    void (*bg0802_jmp[2])() = { bg0802_init00, bg_base_move_common };
    bg0802_jmp[bgw_ptr->r_no_0]();
}



void bg080_sync_common_bg080(void) {
    void (*bg080_sync_jmp[2])() = { bg080_sync_init, bg080_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void BG080(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0802_BG080();
    bgw_ptr = &bg_w.bgw[0];
    bg0801_BG080();
    bgw_ptr = &bg_w.bgw[2];
    bg080_sync_common_BG080();
    bgw_ptr = &bg_w.bgw[5];
    bg080_sync_common_BG080();
    bgw_ptr = &bg_w.bgw[6];
    bg080_sync_common_BG080();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0801(void) {
    void (*bg0801_jmp[2])() = { bg0801_init00, bg_move_common };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg0801_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    if (bgw_ptr->fam_no == 0) {
        effect_45_init();
    }
}



void bg0802(void) {
    BG_JMP2 bg0802_jmp;
    bg0802_jmp = bg0802_jmp_tbl;
    bg0802_jmp.f[bgw_ptr->r_no_0]();
}



void bg0802_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xD880, 1);
    effect_05_init();
    effect_06_init();
    effect_44_init(0);
    effect_21_init(0);
}



void bg080_sync_common(void) {
    void (*bg080_sync_jmp[2])() = { bg080_sync_init, bg080_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg080_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    switch (bgw_ptr->fam_no) {
    case 2:
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xFC00;
        break;
    case 5:
        bgw_ptr->speed_x = 0xB000;
        bgw_ptr->speed_y = 0xFC00;
        break;
    case 6:
        bgw_ptr->speed_x = 0x7000;
        bgw_ptr->speed_y = 0xF100;
        break;
    }
    sync_fam_set3(bgw_ptr->fam_no);
}
