/*
 * BG090.C  Stage background BG090
 *
 * bg080_sync_move finishes BG080's sync layer. BG090 runs the stage's two main layers and
 * three extra family layers (bg_fam0900) each frame, then zoom check, positions and family
 * set. bg0902_init00 loads the stage graphics and starts effects 05, 06 and 68.
 * bg090_demo_check and demo90_base run the stage's entrance demo: the layer waits for the
 * Appear_free signal, scrolls its Y down to 0 and waits for Appear_end before normal
 * movement. While win_sp_flag is set, jijii_win_bg / jijii_win_bg2 take over the layers for
 * the special win scene: at flag value 2 the layer scrolls up past 0xB0 and sets it to 3.
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
#include "bg000.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF68.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "bg090.h"

#pragma inline(bg0601, bg0602, bg0701, bg0702, bg0801, bg0802, bg080_sync_common)
#include "fighter.h"
#include "EFF45.h"
#include "EFF61.h"
#include "effj4.h"
#include "effj5.h"
#include "effj6.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "eff14.h"
#include "EFF21.h"
#include "EFF22.h"
#include "EFF24.h"
#include "EFF44.h"
#include "eff94.h"
#include "EFFJ8.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "bg050.h"



void BG180(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1802();
    bgw_ptr = &bg_w.bgw[0];
    bg1801();
    bgw_ptr = &bg_w.bgw[2];
    bg180_sync_common();
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



void BG060(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0602();
    bgw_ptr = &bg_w.bgw[0];
    bg0601();
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



void BG070(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0702();
    bgw_ptr = &bg_w.bgw[0];
    bg0701();
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












void BG080(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0802();
    bgw_ptr = &bg_w.bgw[0];
    bg0801();
    bgw_ptr = &bg_w.bgw[2];
    bg080_sync_common();
    bgw_ptr = &bg_w.bgw[5];
    bg080_sync_common();
    bgw_ptr = &bg_w.bgw[6];
    bg080_sync_common();
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
    if (!bgw_ptr->fam_no) {
        effect_45_init();
    }
}



void bg0802(void) {
    void (*jmp[2])(void) = { bg0802_init00, bg_base_move_common };
    jmp[bgw_ptr->r_no_0]();
}



void bg0802_init00(void) {
    void* z;
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    z = 0;
    bgw_ptr->zuubun = (s32)z;
    load_char_gfx(0xD880, 1);
    effect_05_init();
    effect_06_init();
    effect_44_init((s32)z);
    effect_21_init((s32)z);
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



void bg080_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(bgw_ptr->fam_no);
}



void BG090(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0902();
    bgw_ptr = &bg_w.bgw[0];
    bg0901();
    bgw_ptr = &bg_w.bgw[2];
    bg_fam0900();
    bgw_ptr = &bg_w.bgw[6];
    bg_fam0900();
    bgw_ptr = &bg_w.bgw[5];
    bg_fam0900();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0901(void) {
    void (*bg0901_jmp[3])() = { bg0901_init00, demo90_base, bg_move_common };
    if (win_sp_flag) {
        jijii_win_bg2();
    } else {
        bg0901_jmp[bgw_ptr->r_no_0]();
    }
}



void bg0901_init00(void) {
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg090_demo_check();
}



void bg0902(void) {
    void (*bg0902_jmp[3])() = { bg0902_init00, demo90_base, bg_base_move_common };
    if (win_sp_flag) {
        jijii_win_bg();
    } else {
        bg0902_jmp[bgw_ptr->r_no_0]();
    }
}



void bg0902_init00(void) {
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg090_demo_check();
    load_char_gfx(0xDEE0, 1);
    effect_05_init();
    effect_06_init();
    effect_68_init();
}



void bg_fam0900(void) {
    if (win_sp_flag) {
        jijii_win_bg2();
        sync_fam_set3(bgw_ptr->fam_no);
        return;
    }
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
        bg090_demo_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    case 1:
        demo90_base();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    case 2:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(bgw_ptr->fam_no);
        break;
    }
}



void bg090_demo_check(void) {
    if ((plw->player_number != PL_ORO) && (plw[1].player_number != PL_ORO)) {
        bgw_ptr->r_no_0 = 2;
    } else if (bg_w.area != 0) {
        bgw_ptr->r_no_0 = 2;
    } else {
        bgw_ptr->r_no_0 = 1;
        bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = bgw_ptr->speed_y * 0xC0;
    }
}



void demo90_base(void) {
    s16 chk_pl;
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        chk_pl = 0;
        if (plw->player_number == PL_ORO && plw[1].player_number == PL_ORO) {
            if (Appear_hv[0]) {
                chk_pl = 1;
            }
        } else if (plw[1].player_number == PL_ORO) {
            chk_pl = 1;
        }
        if (Appear_free[chk_pl]) {
            bgw_ptr->r_no_1++;
            break;
        }
        break;
    case 1:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 0xA;
        bgw_ptr->wxy[1].cal -= bgw_ptr->speed_y * 0xA;
        if (bgw_ptr->xy[1].disp.pos <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->wxy[1].cal = 0;
            break;
        }
        break;
    case 2:
        if (Appear_end == 2) {
            bgw_ptr->r_no_0++;
            bgw_ptr->r_no_1 = 0;
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->wxy[1].cal = 0;
        }
        break;
    }
}



void jijii_win_bg(void) {
    if ((EXE_flag || Game_pause)) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (win_sp_flag == 2) {
            bgw_ptr->xy[1].cal += 0xA0000;
            bgw_ptr->wxy[1].cal += 0xA0000;
            if (bgw_ptr->xy[1].disp.pos > 0xB0) {
                bgw_ptr->r_no_1 += 1;
                win_sp_flag = 3;
            }
        }
    case 1:
        break;
    }
}



void jijii_win_bg2(void) {
    s16 zuu_work;
    s32 sp_work;
    if ((EXE_flag || Game_pause)) {
        return;
    }
    switch (bg_w.bgw[1].r_no_1) {
    case 0:
        if (win_sp_flag == 2) {
            zuu_work = 0xA;
            sp_work = bgw_ptr->speed_y * zuu_work;
            bgw_ptr->xy[1].cal += sp_work;
            bgw_ptr->wxy[1].cal += sp_work;
        }
    case 1:
        break;
    }
}
