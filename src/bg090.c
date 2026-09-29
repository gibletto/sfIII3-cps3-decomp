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
#include "bg000.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF68.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "bg090.h"
#include "fighter.h"



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
        return;
    }
    bg0901_jmp[bgw_ptr->r_no_0]();
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



s32 bg090_demo_check(void) {
    s16 pos_w;
    if ((plw->player_number != PL_ORO) && (plw[1].player_number != PL_ORO)) {
        return bgw_ptr->r_no_0 = 2;
    }
    if (bg_w.area != 0) {
        return bgw_ptr->r_no_0 = 2;
    }
    bgw_ptr->r_no_0 = 1;
    pos_w = 0xC0;
    return bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = bgw_ptr->speed_y * pos_w;
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
