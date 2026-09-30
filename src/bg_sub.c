/*
 * BG_SUB.C  Stage background subroutines: scrolling, zoom, family set, cell writers
 *
 * Shared machinery used by every stage routine.
 * Scrolling: check_cg_zoom and the scr_1x_2x rules decide how the main layer
 * follows the two players; bg_base_x_move_check, bg_x/y_move_check and
 * remake_x_mvstep move the layers; the chase routines handle requested scrolls.
 * Zoom: zoom_frame_judge, zoom_ud_check, zoom_x_width_check, bg_base_y_move_check.
 * Line scroll: suzi_line_clear, suzi_offset_set, suzi_sync_pos_set.
 * Bg_Family_Set and its variants load scroll and family registers; bg_pos_hosei_* add the
 * screen offset and quake. Tile writers blit 16x16 and 8x16 cells (plain, flipped, wrapped)
 * and the HUD rectangle; bg_work_clear and compel_bg_init_position reset the display.
 * A few debug helpers step through the stages from the controls.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "tate00.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "bg_sub.h"

#pragma inline(remake_x_mvstep)

static s32 remake_x_mvstep(s16 x);



/* provisional name */
s32 bg_debug_stage_change(void) {
    u16 sw1;
    u16 sw2;
    u16 ret = 0;
    sw1 = p1sw_0 & ~p1sw_1;
    sw2 = p2sw_0 & ~p2sw_1;
    if (exsw_1 & 0x80) {
        if ((sw1 & 0x80) || (sw2 & 0x80)) {
            bg_w.stage++;
            ret = 1;
            if (bg_w.stage > 22) {
                bg_w.stage = 0;
            }
        }
        if ((sw1 & 0x100) || (sw2 & 0x100)) {
            bg_w.stage--;
            ret = 1;
            if (bg_w.stage < 0) {
                bg_w.stage = 22;
            }
        }
        if ((sw1 & 0x200) || (sw2 & 0x200)) {
            bg_w.area++;
            ret = 1;
            if (bg_w.area > 2) {
                bg_w.area = 0;
            }
        }
    }
    return ret;
}



/* provisional name */
void bg_free_work_blocks(void) {
    s16 i;
    simmram_block_free_10(scr_cg_c_no);
    i = 0;
    while (i < bg_w.scno) {
        simmram_block_free_40(bg_w.bgw[i].bg_adrs_c_no);
        sprite_list_clear(i);
        if (bg_w.bgw[i].zuubun != 0) {
            simmram_block_free_40(bg_w.bgw[i].suzi_c_no);
        }
        i++;
    }
}



/* provisional name */
void bg_debug_scroll_layers(void) {
    BGW* bgw;
    s32 dx;
    s32 dy;
    s16 i;
    for (i = 0; i < 7; i++) {
        if (i != 4) {
            bgw = &bg_w.bgw[i];
            if (p1sw_0 & 0x10) {
                dx = bgw->speed_x * 2;
                dy = bgw->speed_y * 2;
            } else {
                dx = bgw->speed_x;
                dy = bgw->speed_y;
            }
            if (p1sw_0 & 4) {
                Bg_mv_tw_appoint(i, -dx, 0);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 8) {
                Bg_mv_tw_appoint(i, dx, 0);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 1) {
                Bg_mv_tw_appoint(i, 0, dy);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 2) {
                Bg_mv_tw_appoint(i, 0, -dy);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            sync_fam_set3(i);
        }
    }
}



/* provisional name */
void bg_test_stage_select(void) {
    u16 sw;
    s16 changed;
    s8 save_27;
    s8 save_entry;
    changed = 0;
    sw = ~p1sw_1 & p1sw_0;
    if (sw & 0x80) {
        if (++bg_select_no > 16) {
            bg_select_no = 0;
        }
        changed = 1;
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
    }
    if (sw & 0x100) {
        if (--bg_select_no < 0) {
            bg_select_no = 16;
        }
        changed = 1;
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
    }
    if (changed) {
        System_all_clear_Wait();
        pcon_rno[3] = 0;
        pcon_rno[2] = 0;
        pcon_rno[1] = 0;
        pcon_rno[0] = 0;
        save_27 = bg_test_flag;
        save_entry = bg_select_no;
        bg_work_clear();
        bg_select_no = save_entry;
        bg_test_flag = save_27;
    }
}



/* provisional name */
void bg_layers_off(void) {
    s16 i;
    i = 0;
    while (i < bg_w.scno) {
        if (scrn_reg_w[i].ctrl & 0x8000) {
            Bg_Off_W(1 << i);
        }
        i++;
    }
    if (scrn_reg_w[3].ctrl & 0x8000) {
        Bg_Off_W(8);
    }
}



/* provisional name */
void check_cg_zoom(void) {
    s16 i;
    s16 zoom_wk;
    zoom_req_flag_old = zoom_request_flag;
    zoom_request_flag = 0;
    for (i = 0; i < 2; i++) {
        if (plw[i].scr_pos_set_flag) {
            plw[i].wu.scr_mv_x = plw[i].wu.xyz[0].disp.pos;
            plw[i].wu.scr_mv_y = plw[i].wu.xyz[1].disp.pos;
        } else if (plw[i].tsukamare_f) {
            plw[i].wu.scr_mv_x = plw[i + 1 & 1].wu.xyz[0].disp.pos;
            plw[i].wu.scr_mv_y = plw[i + 1 & 1].wu.xyz[1].disp.pos;
        }
    }
    zoom_wk = plw[1].wu.cg_zoom & 0xE200;
    switch (plw[0].wu.cg_zoom & 0xE200) {
    case 0x4000:
        break;
    case 0x2000:
        switch (zoom_wk) {
        case 0x4000:
            zoom_request_flag = 0x100;
            scr_req_x = plw[0].wu.xyz[0].disp.pos;
            break;
        case 0x2000:
            zoom_request_flag = 0x100;
            scr_req_x = (plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos) >> 1;
            break;
        case 0x200:
        case 0x0:
        case 0x2200:
            zoom_request_flag = 0x100;
            scr_req_x = plw[1].wu.xyz[0].disp.pos;
            break;
        }
        break;
    case 0x200:
        switch (zoom_wk) {
        case 0x2000:
        case 0x0:
        case 0x4000:
        case 0x2200:
            zoom_request_flag = 0x100;
            scr_req_x = plw[0].wu.xyz[0].disp.pos;
            break;
        case 0x200:
            zoom_request_flag = 0x100;
            scr_req_x = (plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos) >> 1;
            break;
        }
        break;
    case 0x0:
        switch (zoom_wk) {
        case 0x2200:
            zoom_request_flag = 0x100;
            scr_req_x = (plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos) >> 1;
            break;
        case 0x2000:
            zoom_request_flag = 0x100;
            scr_req_x = plw[0].wu.xyz[0].disp.pos;
            break;
        case 0x200:
            zoom_request_flag = 0x100;
            scr_req_x = plw[1].wu.xyz[0].disp.pos;
            break;
        case 0x4000:
            zoom_request_flag = 0x100;
            scr_req_x = plw[0].wu.xyz[0].disp.pos;
            break;
        case 0x0:
            break;
        }
        break;
    case 0x2200:
        switch (zoom_wk) {
        case 0x0:
        case 0x2200:
        case 0x4000:
            zoom_request_flag = 0x100;
            scr_req_x = (plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos) >> 1;
            break;
        case 0x2000:
            zoom_request_flag = 0x100;
            scr_req_x = plw[0].wu.xyz[0].disp.pos;
            break;
        case 0x200:
            zoom_request_flag = 0x100;
            scr_req_x = plw[1].wu.xyz[0].disp.pos;
            break;
            break;
        }
        break;
    }
    zoom_wk = plw[1].wu.cg_zoom & 0xD100;
    switch (plw[0].wu.cg_zoom & 0xD100) {
    case 0x4000:
        zoom_request_flag |= 0x1000;
        scr_req_y = 0;
        break;
    case 0x1000:
        switch (zoom_wk) {
        case 0x1000:
            zoom_request_flag |= 0x1000;
            scr_req_y = (plw[0].wu.xyz[1].disp.pos + plw[1].wu.xyz[1].disp.pos) >> 1;
            break;
        case 0x100:
        case 0x0:
        case 0x1100:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[1].wu.xyz[1].disp.pos;
            break;
        case 0x4000:
            zoom_request_flag |= 0x1000;
            scr_req_y = 0;
            break;
        }
        break;
    case 0x100:
        switch (zoom_wk) {
        case 0x1000:
        case 0x0:
        case 0x1100:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[0].wu.xyz[1].disp.pos;
            break;
        case 0x100:
            zoom_request_flag |= 0x1000;
            scr_req_y = (plw[0].wu.xyz[1].disp.pos + plw[1].wu.xyz[1].disp.pos) >> 1;
            break;
        case 0x4000:
            zoom_request_flag |= 0x1000;
            scr_req_y = 0;
            break;
        }
        break;
    case 0x0:
        switch (zoom_wk) {
        case 0x1000:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[0].wu.xyz[1].disp.pos;
            break;
        case 0x100:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[1].wu.xyz[1].disp.pos;
            break;
        case 0x1100:
            zoom_request_flag |= 0x1000;
            scr_req_y = (plw[0].wu.xyz[1].disp.pos + plw[1].wu.xyz[1].disp.pos) >> 1;
            break;
        case 0x0:
            break;
        case 0x4000:
            zoom_request_flag |= 0x1000;
            scr_req_y = 0;
            break;
        }
        break;
    case 0x1100:
        switch (zoom_wk) {
        case 0x1000:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[0].wu.xyz[1].disp.pos;
            break;
        case 0x100:
            zoom_request_flag |= 0x1000;
            scr_req_y = plw[1].wu.xyz[1].disp.pos;
            break;
        case 0x1100:
        case 0x0:
            zoom_request_flag |= 0x1000;
            scr_req_y = (plw[0].wu.xyz[1].disp.pos + plw[1].wu.xyz[1].disp.pos) >> 1;
            break;
        case 0x4000:
            zoom_request_flag |= 0x1000;
            scr_req_y = 0;
            break;
        }
        break;
    }
    zoom_request_level = plw[0].wu.cg_zoom & 0xFF;
    if (zoom_request_level < (plw[1].wu.cg_zoom & 0xFF)) {
        zoom_request_level = plw[1].wu.cg_zoom & 0xFF;
    }
    if (zoom_request_level) {
        zoom_request_flag |= 1;
    }
}



/* Outside the bonus game, turn the players' positions into a camera request
   and, while the background is chasing, apply it. */
void bg_chase_move(void)
{
    if (Bonus_Game_Flag == 0) {
        chase_start_check();
        if (bg_w.chase_flag) {
            chase_xy_move();
        }
    }
}



void chase_start_check(void) {
    s16 work;
    s16 work2;
    if (zoom_request_flag & 0xF00) {
        if (chase_x != scr_req_x) {
            chase_x = scr_req_x;
            if (bgw_ptr->zuubun) {
                bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->abs_x + bg_w.pos_offset;
            } else {
                bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->position_x + bg_w.pos_offset;
            }
            chase_time_x = 6;
            cal_bg_speed_data_x(bgw_ptr->fam_no, chase_time_x, chase_x);
            bg_w.chase_flag |= 1;
            bg_w.chase_flag &= 0xFFFD;
            bg_w.old_chase_flag = 1;
        }
    } else {
        work = zoom_req_flag_old & 0xF00;
        work2 = ~(zoom_request_flag & 0xF00);
        work &= work2;
        if (work) {
            bg_w.chase_flag |= 2;
            bg_w.chase_flag &= 0xFFFE;
            chase_x = bgw_ptr->wxy[0].disp.pos;
            chase_time_x = 6;
            cal_bg_speed_data_x(bgw_ptr->fam_no, chase_time_x, chase_x);
        }
    }
    if (zoom_request_flag & 0xF000) {
        bg_w.chase_flag |= 0x10;
        bg_w.chase_flag &= 0xFFDF;
        bg_w.old_chase_flag |= 0x10;
        bg_w.old_chase_flag &= 0xFFDF;
        if (chase_y != scr_req_y) {
            chase_y = scr_req_y;
            if (bgw_ptr->abs_y < 0) {
                bgw_ptr->chase_xy[1].disp.pos = 0;
            } else {
                bgw_ptr->chase_xy[1].disp.pos = bgw_ptr->abs_y;
            }
            chase_time_y = 6;
            cal_bg_speed_data_y(bgw_ptr->fam_no, chase_time_y, chase_y);
        }
    } else {
        work = zoom_req_flag_old & 0xF000;
        work2 = ~(zoom_request_flag & 0xF000);
        work &= work2;
        if (work) {
            bg_w.chase_flag |= 0x20;
            bg_w.chase_flag &= 0xFFEF;
            chase_y = bgw_ptr->xy[1].disp.pos;
            chase_time_y = 6;
            cal_bg_speed_data_y(bgw_ptr->fam_no, chase_time_y, chase_y);
        }
    }
}



s32 chase_xy_move(void) {
    s32 sp_y;
    if (bg_w.chase_flag & 0xF) {
        bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
        if (bg_w.chase_flag & 1) {
            chase_time_x -= 1;
            if (chase_time_x > 0) {
                bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
                bgw_ptr->chase_xy[0].cal += bg_mvxy.a[0].sp;
            }
        }
        if (bg_w.chase_flag & 2) {
            chase_time_x -= 1;
            if (chase_time_x > 0) {
                bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
                bgw_ptr->chase_xy[0].cal += bg_mvxy.a[0].sp;
            } else {
                bg_w.chase_flag &= 0xFFF0;
                bg_w.old_chase_flag &= 0xFFF0;
                bgw_ptr->chase_xy[0].disp.pos = chase_x;
            }
        }
        if (bgw_ptr->chase_xy[0].disp.pos > bgw_ptr->r_limit2) {
            bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->r_limit2;
            bgw_ptr->chase_xy[0].disp.low = 0;
        }
        if (bgw_ptr->chase_xy[0].disp.pos < bgw_ptr->l_limit2) {
            bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->l_limit2;
            bgw_ptr->chase_xy[0].disp.low = 0;
        }
        bg_w.bg2_sp_x = bg_w.bg2_sp_x2 = bgw_ptr->chase_xy[0].disp.pos - bgw_ptr->pos_x_work;
    }
    if (bg_w.chase_flag & 0xF0) {
        if (bg_w.chase_flag & 0x10) {
            chase_time_y -= 1;
            if (chase_time_y > 0) {
                bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
                bgw_ptr->chase_xy[1].cal += bg_mvxy.a[1].sp;
            }
        }
        if (bg_w.chase_flag & 0x20) {
            chase_time_y -= 1;
            if (chase_time_y > 0) {
                bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
                bgw_ptr->chase_xy[1].cal += bg_mvxy.a[1].sp;
            } else {
                bg_w.chase_flag &= 0xFF0F;
                bg_w.old_chase_flag &= 0xFF0F;
                bgw_ptr->chase_xy[1].disp.pos = chase_y;
            }
        }
        if (bgw_ptr->chase_xy[1].disp.pos > bgw_ptr->y_limit2) {
            bgw_ptr->chase_xy[1].disp.pos = bgw_ptr->y_limit2;
            bgw_ptr->chase_xy[1].disp.low = 0;
        }
        sp_y = bgw_ptr->pos_y_work;
        sp_y = bgw_ptr->chase_xy[1].disp.pos - sp_y;
        bg_w.bg2_sp_y = sp_y;
        return sp_y;
    }
    return bg_w.chase_flag;
}


void Bg_mv_tw(s32 value_x, s32 value_y) {
    bgw_ptr->xy[0].cal += value_x;
    bgw_ptr->xy[1].cal += value_y;
    bgw_ptr->wxy[0].cal += value_x;
    bgw_ptr->wxy[1].cal += value_y;
}



/* provisional name */
void Bg_mv_tw_appoint(s16 bg_num, s32 dx, s32 dy) {
    bg_w.bgw[bg_num].xy[0].cal += dx;
    bg_w.bgw[bg_num].xy[1].cal += dy;
    bg_w.bgw[bg_num].wxy[0].cal += dx;
    bg_w.bgw[bg_num].wxy[1].cal += dy;
}



void x_right_check(s16 d1) {
    s32 speed_w;
    bg_w.scr_stop &= 0xFFFC;
    speed_w = bgw_ptr->speed_x * d1;
    ideal_w.iw[0].cal += speed_w;
}



void x_left_check(s16 d0) {
    s32 speed_w;
    bg_w.scr_stop &= 0xFFFC;
    speed_w = bgw_ptr->speed_x * d0;
    ideal_w.iw[0].cal += speed_w;
}



void scr_x_dummy(void) {}



void scr_10_20(void) {}



void scr_10_21(void) {
    s16 meri;
    meri = plw[1].wu.scr_mv_x - satse[plw[1].player_number];
    meri = meri - (ideal_w.iw[0].disp.pos - bg_w.pos_offset + 0x40);
    x_left_check(meri);
}



void scr_10_22(void) {
    s16 meri;
    meri = plw[1].wu.scr_mv_x + satse[plw[1].player_number];
    meri = meri - (ideal_w.iw[0].disp.pos + bg_w.pos_offset - 0x3F);
    x_right_check(meri);
}



void scr_11_20(void) {
    s16 meri;
    meri = plw[0].wu.scr_mv_x - satse[plw[0].player_number];
    meri = meri - (ideal_w.iw[0].disp.pos - bg_w.pos_offset + 0x40);
    x_left_check(meri);
}



void scr_11_21(void) {
    s16 meri;
    if (plw[0].wu.scr_mv_x < plw[1].wu.scr_mv_x) {
        meri = plw[0].wu.scr_mv_x - satse[plw[0].player_number];
    } else {
        meri = plw[1].wu.scr_mv_x - satse[plw[1].player_number];
    }
    meri = meri - (ideal_w.iw[0].disp.pos - bg_w.pos_offset + 0x40);
    x_left_check(meri);
}



void scr_11_22(void) {
    s16 meri;
    s16 meri2;
    meri = (satse[plw[1].player_number] - satse[plw[0].player_number]);
    meri >>= 1;
    meri2 = plw[0].wu.scr_mv_x + plw[1].wu.scr_mv_x;
    meri2 >>= 1;
    meri2 += meri;
    meri2 -= ideal_w.iw[0].disp.pos;
    if (meri2 < 0) {
        if (plw[1].micchaku_flag != 1) {
            x_left_check(meri2);
        }
    } else if (plw[0].micchaku_flag != 2) {
        x_right_check(meri2);
    }
}



void scr_12_20(void) {
    s16 meri;
    meri = plw[0].wu.scr_mv_x + satse[plw[0].player_number];
    meri = meri - (ideal_w.iw[0].disp.pos + bg_w.pos_offset - 0x3F);
    x_right_check(meri);
}



void scr_12_21(void) {
    s16 meri;
    s16 meri2;
    meri = (satse[plw[0].player_number] - satse[plw[1].player_number]);
    meri >>= 1;
    meri2 = plw[0].wu.scr_mv_x + plw[1].wu.scr_mv_x;
    meri2 >>= 1;
    meri2 += meri;
    meri2 -= ideal_w.iw[0].disp.pos;
    if (meri2 < 0) {
        if (plw[0].micchaku_flag != 1) {
            x_left_check(meri2);
        }
    } else if (plw[1].micchaku_flag != 2) {
        x_right_check(meri2);
    }
}



void scr_12_22(void) {
    s16 meri;
    PLW* p1 = &plw[0];
    PLW* p2 = &plw[1];
    if (p1->wu.scr_mv_x > p2->wu.scr_mv_x) {
        meri = p1->wu.scr_mv_x + satse[p1->player_number];
    } else {
        meri = p2->wu.scr_mv_x + satse[p2->player_number];
    }
    meri = meri - (ideal_w.iw[0].disp.pos + bg_w.pos_offset - 0x3F);
    x_right_check(meri);
}



/* provisional name */
void bg_base_x_move_sub(void) {
    s16 work0;
    s16 work1;
    s16 bg_pos;
    PLW* pl;
    const s8* st_tbl;
    bg_pos = ideal_w.iw[0].disp.pos - bg_w.pos_offset;
    pl = &plw[0];
    if (pl->wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work0 = pl->wu.scr_mv_x - satse[pl->player_number];
    } else {
        work0 = pl->wu.scr_mv_x + satse[pl->player_number];
    }
    work0 -= bg_pos;
    pl = &plw[1];
    if (pl->wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work1 = pl->wu.scr_mv_x - satse[pl->player_number];
    } else {
        work1 = pl->wu.scr_mv_x + satse[pl->player_number];
    }
    work1 -= bg_pos;
    if (Game_setting.mode) {
        if (work0 < 0) {
            work0 = 0;
        } else if (work0 > 0x1EF) {
            work0 = 0x1EF;
        }
        if (work1 < 0) {
            work1 = 0;
        } else if (work1 > 0x1EF) {
            work1 = 0x1EF;
        }
        st_tbl = pos_area_wide_tbl;
    } else {
        if (work0 < 0) {
            work0 = 0;
        } else if (work0 > 0x17F) {
            work0 = 0x17F;
        }
        if (work1 < 0) {
            work1 = 0;
        } else if (work1 > 0x17F) {
            work1 = 0x17F;
        }
        st_tbl = pos_area_tbl;
    }
    scr_x_mv_jp[(st_tbl[work0] << 4) + st_tbl[work1]]();
}

static s32 remake_x_mvstep(s16 x) {
    return x * 80 / 100;
}



/* provisional name */
void bg_base_x_move_check(void) {
    s16 mvstep;
    s16 old_work;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    if (!bg_stop && !bg_app_stop) {
        if (bg_w.chase_flag & 0xF) {
            bgw_ptr->old_pos_x = bgw_ptr->chase_xy[0].disp.pos;
        } else {
            bgw_ptr->old_pos_x = bgw_ptr->wxy[0].disp.pos;
        }
        old_work = bgw_ptr->wxy[0].disp.pos;
        ideal_w.iw[0].cal = bgw_ptr->wxy[0].cal;
        bg_base_x_move_sub();
        mvstep = ideal_w.iw[0].disp.pos;
        mvstep -= old_work;
        ideal_w.iw[0].cal = 0;
        ideal_w.iw[0].disp.pos = mvstep;
        if (mvstep) {
            if (mvstep < 0) {
                if (mvstep < -bg_w.max_x) {
                    mvstep = -bg_w.max_x;
                }
                mvstep = -remake_x_mvstep(-mvstep);
            } else {
                if (mvstep > bg_w.max_x) {
                    mvstep = bg_w.max_x;
                }
                mvstep = remake_x_mvstep(mvstep);
            }
        }
        ideal_w.iw[0].disp.pos = mvstep;
        Bg_mv_tw(ideal_w.iw[0].cal, 0);
        if (bgw_ptr->wxy[0].disp.pos < bgw_ptr->l_limit2) {
            bgw_ptr->wxy[0].disp.pos = bgw_ptr->l_limit2;
            bgw_ptr->wxy[0].disp.low = 0;
            bgw_ptr->xy[0].disp.pos = bgw_ptr->l_limit2;
            bgw_ptr->xy[0].disp.low = 0;
        }
        if (bgw_ptr->wxy[0].disp.pos > bgw_ptr->r_limit2) {
            bgw_ptr->wxy[0].disp.pos = bgw_ptr->r_limit2;
            bgw_ptr->wxy[0].disp.low = 0;
            bgw_ptr->xy[0].disp.pos = bgw_ptr->r_limit2;
            bgw_ptr->xy[0].disp.low = 0;
        }
    }
    bg_w.bg2_sp_x = bgw_ptr->xy[0].disp.pos - bgw_ptr->pos_x_work;
    bg_w.bg2_sp_x2 = bgw_ptr->wxy[0].disp.pos - bgw_ptr->pos_x_work;
    if (!(bg_w.chase_flag & 0xF)) {
        bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos;
    }
}

/* provisional name */
s32 remake_mvstep(x)
s16 x;
{
    return x * 80 / 100;
}



/* provisional name */
void bg_base_y_move_check(void) {
    s32 pos_w;
    s32 kake;
    s16 hi_pos;
    if (!bg_stop && !bg_app_stop) {
        if (plw[0].wu.scr_mv_y > plw[1].wu.scr_mv_y) {
            hi_pos = plw[0].wu.scr_mv_y;
        } else {
            hi_pos = plw[1].wu.scr_mv_y;
        }
        hi_pos -= 0x58;
        if (hi_pos <= 0) {
            bgw_ptr->wxy[1].cal = 0;
            bgw_ptr->xy[1].cal = 0;
        } else {
            kake = 0x1C000;
            pos_w = kake * hi_pos;
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->wxy[1].cal = 0;
            bgw_ptr->xy[1].cal += pos_w;
            bgw_ptr->wxy[1].cal += pos_w;
            if (bgw_ptr->xy[1].disp.pos > bgw_ptr->y_limit2) {
                bgw_ptr->xy[1].disp.pos = bgw_ptr->y_limit2;
                bgw_ptr->xy[1].disp.low = 0;
                bgw_ptr->wxy[1].disp.pos = bgw_ptr->y_limit2;
                bgw_ptr->wxy[1].disp.low = 0;
                bg_w.scr_stop &= 0x7FFF;
            }
        }
    }
    bg_w.bg2_sp_y = bgw_ptr->xy[1].disp.pos - bgw_ptr->pos_y_work;
}



void bg_x_move_check(void) {
    if (bg_w.chase_flag & 0xF) {
        bgw_ptr->old_pos_x = bgw_ptr->chase_xy[0].disp.pos;
    } else {
        bgw_ptr->old_pos_x = bgw_ptr->wxy[0].disp.pos;
    }
    if (bg_w.chase_flag & 0xF) {
        bgw_ptr->chase_xy[0].cal = bgw_ptr->speed_x * bg_w.bg2_sp_x2;
        bgw_ptr->chase_xy[0].disp.pos += bgw_ptr->pos_x_work;
    } else {
        bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal = bgw_ptr->speed_x * bg_w.bg2_sp_x2;
        bgw_ptr->xy[0].disp.pos += bgw_ptr->pos_x_work;
        bgw_ptr->wxy[0].disp.pos = bgw_ptr->xy[0].disp.pos;
    }
    if (!(bg_w.chase_flag & 0xF)) {
        bgw_ptr->chase_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos;
    }
}



void bg_y_move_check(void) {
    if (bg_w.chase_flag & 0xF0) {
        bgw_ptr->chase_xy[1].cal = bgw_ptr->speed_y * bg_w.bg2_sp_y;
        if (bgw_ptr->y_limit2 < bgw_ptr->chase_xy[1].disp.pos) {
            bgw_ptr->chase_xy[1].disp.pos = bgw_ptr->y_limit2;
            bgw_ptr->chase_xy[1].disp.low = 0;
        }
        bgw_ptr->chase_xy[1].disp.pos += bgw_ptr->pos_y_work;
    } else {
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y * bg_w.bg2_sp_y;
        if (bgw_ptr->y_limit2 < bgw_ptr->xy[1].disp.pos) {
            bgw_ptr->xy[1].disp.pos = bgw_ptr->y_limit2;
            bgw_ptr->xy[1].disp.low = 0;
        }
        bgw_ptr->xy[1].disp.pos += bgw_ptr->pos_y_work;
        bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    }
}



/* provisional name */
s32 zoom_frame_judge(void) {
    PLW* p1;
    PLW* p2;
    s16 left;
    s16 right;
    s16 work;
    bg_w.frame_flag = 0;
    if (bg_w.bgw[1].wxy[0].disp.pos <= bg_w.bgw[1].l_limit2 ||
        bg_w.bgw[1].wxy[0].disp.pos >= bg_w.bgw[1].r_limit2) {
        return 2;
    }
    p1 = &plw[0];
    p2 = &plw[1];
    if (p1->wu.scr_mv_x < p2->wu.scr_mv_x) {
        left = p1->wu.scr_mv_x;
        right = p2->wu.scr_mv_x;
    } else {
        left = p2->wu.scr_mv_x;
        right = p1->wu.scr_mv_x;
    }
    work = right - left;
    if (work > 368) {
        return 2;
    }
    return 1;
}



void zoom_ud_check(void) {
    s16 work;
    s16 work2;
    s16 pos_w;
    s16 x2;
    if (bg_app) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    if (Bonus_Game_Flag) {
        return;
    }
    work2 = zoom_request_flag;
    work2 &= 0xFF;
    bg_w.frame_deff = 64 - zoom_request_level;
    work = ~zoom_req_flag_old & zoom_request_flag;
    work &= 0xFF;
    if (work && !bg_w.frame_flag) {
        bg_w.frame_flag = 1;
        bg_w.old_frame_flag = 1;
        bg_w.center_y = 224 - scr_req_y;
        x2 = scr_req_x + 512;
        if (scr_req_x < bg_w.bgw[1].l_limit2) {
            if (bg_w.bgw[1].zuubun != 0) {
                bg_w.center_x = x2;
                pos_w = bg_w.bgw[1].wxy[0].disp.pos + 512;
            } else {
                bg_w.center_x = scr_req_x;
                pos_w = bg_w.bgw[1].wxy[0].disp.pos;
            }
            pos_w -= bg_w.pos_offset;
            bg_w.center_x -= pos_w;
            if (Monitor_Flip) {
                bg_w.center_x = bg_w.pos_offset * 2 - bg_w.center_x;
            }
        } else if (bg_w.bgw[1].r_limit2 < scr_req_x) {
            if (bg_w.bgw[1].zuubun != 0) {
                bg_w.center_x = x2;
                pos_w = bg_w.bgw[1].wxy[0].disp.pos + 512;
            } else {
                bg_w.center_x = scr_req_x;
                pos_w = bg_w.bgw[1].wxy[0].disp.pos;
            }
            pos_w -= bg_w.pos_offset;
            bg_w.center_x -= pos_w;
            if (Monitor_Flip) {
                bg_w.center_x = bg_w.pos_offset * 2 - bg_w.center_x;
            }
        } else {
            bg_w.center_x = 192;
            bg_w.center_y = 224;
        }
    }
    if (work2) {
        if (bg_w.bg_f_x > bg_w.frame_deff) {
            Frame_Up(bg_w.center_x, bg_w.center_y, 1, 1);
            bg_w.bg_f_x--;
            bg_w.bg_f_y--;
            return;
        }
        if (bg_w.bg_f_x < bg_w.frame_deff) {
            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
            bg_w.bg_f_x++;
            bg_w.bg_f_y++;
            if (bg_w.bg_f_x == 64) {
                bg_w.frame_flag = 0;
                Zoomf_Init();
            }
        }
    } else if (bg_w.bg_f_x < 64) {
        Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        bg_w.bg_f_x++;
        bg_w.bg_f_y++;
        if (bg_w.bg_f_x == 64) {
            bg_w.frame_flag = 0;
            Zoomf_Init();
        }
    }
}



/* provisional name */
void zoom_x_width_check(void) {
    s32 f;
    if (Game_setting.mode) {
        return;
    }
    if (bg_stop) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    bg_w.frame_flag = zoom_frame_judge();
    f = bg_w.bg_f_x;
    switch (bg_w.frame_flag) {
    case 1:
        if (f < 9) {
            bg_w.bg_f_x++;
            if (bg_w.old_frame_flag == 1) {
                Frame_Up(192, 224, 1, 0);
            }
        }
        break;
    case 2:
        if (f > 0) {
            bg_w.bg_f_x--;
            if (bg_w.old_frame_flag == 2) {
                Frame_Down(192, 224, 1, 0);
            }
        }
        break;
    case 3:
        if (f != 9) {
            Zoomf_Init_X();
        }
        break;
    }
}

/* provisional name */
s32 zoom_y_width_check(void) {
    s32 f;
    s32 flag;
    if (Game_setting.mode) {
        return Game_setting.mode;
    }
    /* previous bg_f_y, kept in the unnamed word at bg_w+0x34 */
    bg_w.old_bg_f[1] = bg_w.bg_f_y;
    bg_w.frame_flag = zoom_frame_judge();
    f = bg_w.bg_f_y;
    flag = bg_w.frame_flag;
    if (flag == 1) {
        if (f < 9) {
            bg_w.bg_f_y++;
            flag = bg_w.old_frame_flag;
            if (flag == 1) {
                return Frame_Up(192, 224, 0, 1);
            }
        }
    } else if (flag == 2) {
        if (f > 0) {
            bg_w.bg_f_y--;
            flag = bg_w.old_frame_flag;
            if (flag == 2) {
                return Frame_Down(192, 224, 0, 1);
            }
        }
    } else if (flag == 3) {
        if (f != 9) {
            return ((s32(*)())Zoomf_Init_Y)();
        }
        return f;
    }
    return flag;
}



/* provisional name */
void suzi_line_clear(s16 bg_num) {
    u16* dst;
    s16 i;
    dst = bg_w.bgw[bg_num].suzi_adrs;
    for (i = 0; i < 0x400; i++) {
        *dst++ = 0x200;
        *dst++ = 0;
    }
    dst = suzi_line_buf;
    for (i = 0; i < 0x400; i++) {
        *dst++ = 0x200;
        *dst++ = 0;
    }
}

/* provisional name */
s32 suzi_line_calc(s16 bg_num) {
    BGW* bgw;
    s32* calc;
    s32* line;
    u16* dst;
    u16 top;
    s16 dist;
    s16 i;
    if (bg_stop) {
        return bg_stop;
    }
    if (bg_app_stop) {
        return bg_app_stop;
    }
    bgw = &bg_w.bgw[bg_num];
    if ((bg_w.chase_flag & 0xF) == 0) {
        if (bgw->old_pos_x == bgw->wxy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->wxy[0].disp.pos - bgw->old_pos_x;
    } else {
        if (bgw->old_pos_x == bgw->chase_xy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->chase_xy[0].disp.pos - bgw->old_pos_x;
    }
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bgw->zuubun * -dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bgw->d_line; i++) {
            *line -= calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    } else {
        calc[0] = bgw->zuubun * dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bgw->d_line; i++) {
            *line += calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bgw->suzi_adrs + 2048);
    for (i = 0; i < bgw->no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
    return 0x38;
}

/* provisional name */
s32 suzi_line_calc_fill(s16 bg_num) {
    BGW* bgw;
    s32* calc;
    s32* line;
    u16* dst;
    u16 top;
    s16 dist;
    s16 count;
    s16 i;
    if (bg_stop) {
        return bg_stop;
    }
    if (bg_app_stop) {
        return bg_app_stop;
    }
    bgw = &bg_w.bgw[bg_num];
    if ((bg_w.chase_flag & 0xF) == 0) {
        if (bgw->old_pos_x == bgw->wxy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->wxy[0].disp.pos - bgw->old_pos_x;
    } else {
        if (bgw->old_pos_x == bgw->chase_xy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->chase_xy[0].disp.pos - bgw->old_pos_x;
    }
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bgw->zuubun * -dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bgw->d_line; i++) {
            *line -= calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    } else {
        calc[0] = bgw->zuubun * dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bgw->d_line; i++) {
            *line += calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    }
    /* pad the table out to 41 lines with the last one */
    count = 41 - bgw->d_line;
    for (i = 0; i < count; i++) {
        *dst = *(u16*)(line - 1);
        dst += 2;
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bgw->suzi_adrs + 2048);
    for (i = 0; i < bgw->no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
    return 0x38;
}

/* provisional name */
s32 suzi_line_calc_flat(s16 bg_num) {
    BGW* bgw;
    s32* calc;
    s32* line;
    u16* dst;
    u16 top;
    s16 dist;
    s16 count;
    s16 i;
    if (bg_stop) {
        return bg_stop;
    }
    if (bg_app_stop) {
        return bg_app_stop;
    }
    bgw = &bg_w.bgw[bg_num];
    if ((bg_w.chase_flag & 0xF) == 0) {
        if (bgw->old_pos_x == bgw->wxy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->wxy[0].disp.pos - bgw->old_pos_x;
    } else {
        if (bgw->old_pos_x == bgw->chase_xy[0].disp.pos) {
            return 0x30;
        }
        dist = bgw->chase_xy[0].disp.pos - bgw->old_pos_x;
    }
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bgw->zuubun * -dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    } else {
        calc[0] = bgw->zuubun * dist;
        dst = bgw->start_suzi;
        calc[1] = calc[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    }
    /* below the horizon the last line is repeated */
    count = bgw->d_line - 1;
    for (i = 0; i < count; i++) {
        *dst = *(u16*)(line - 1);
        dst += 2;
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bgw->suzi_adrs + 2048);
    for (i = 0; i < bgw->no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
    return 0x38;
}

/* provisional name */
s32 suzi_line_calc2(s16 bg_no)
{
    s32 *step = suzi_calc_w;    /* [0] step per line, [1] running delta */
    s32 *line = (s32 *)suzi_line_buf;
    BGW *bgw;
    u16 *dst;
    u16 *src;
    s16 pos;
    s16 i;
    s32 ret;

    if ((ret = bg_stop) != 0 || (ret = bg_app_stop) != 0) {
        return ret;
    }
    bgw = (BGW *)((u8 *)bg_w.bgw + (s16)(bg_no * sizeof(BGW)));
    if ((bg_w.chase_flag & 0xF) == 0) {
        pos = bgw->wxy[0].disp.pos;
    } else {
        pos = bgw->chase_xy[0].disp.pos;
    }
    if (bgw->old_pos_x == pos) {
        return 0x30;
    }
    pos -= bgw->old_pos_x;
    if (pos < 0) {
        step[0] = bgw->zuubun * -pos;
        dst = bgw->start_suzi;
        step[1] = step[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line += step[1];
            step[1] -= step[0];
            *dst = *(u16 *)line;
            line++;
            dst += 2;
        }
    } else {
        step[0] = bgw->zuubun * pos;
        dst = bgw->start_suzi;
        step[1] = step[0] * bgw->u_line;
        for (i = 0; i < bgw->u_line; i++) {
            *line -= step[1];
            step[1] -= step[0];
            *dst = *(u16 *)line;
            line++;
            dst += 2;
        }
    }
    dst = bgw->suzi_adrs;
    src = dst + 1024;
    for (i = 0; i < 512; i++) {
        *dst = *src;
        dst += 2;
        src += 2;
    }
    return 0x40;
}



s32 suzi_offset_set(WORK* wk) {
    if (wk->sync_suzi != 1) {
        return wk->sync_suzi;
    }
    return suzi_offset_set_sub(wk);
}

u32 suzi_offset_set_sub(WORK* wk)
{
    BGW *bgw;
    s16 work;

    work = 0x300 - (wk->xyz[1].disp.pos & 0x300);
    work += 0x100 - (wk->xyz[1].disp.pos & 0xFF);
    bgw = (BGW *)((u8 *)bg_w.bgw + (s16)((wk->my_family - 1) * sizeof(BGW)));
    wk->suzi_offset = bgw->suzi_adrs + (s16)(work * 2);
    return 0;
}



void suzi_sync_pos_set(WORK_Other* ewk) {
    s16 sub;
    if (ewk->wu.sync_suzi) {
        if (ewk->wu.sync_suzi == 2) {
            suzi_offset_set_sub((WORK*)ewk);
        }
        sub = *ewk->wu.suzi_offset - 512;
    } else {
        sub = 0;
    }
    ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos - sub) & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
}



void Bg_Family_Set(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < bg_w.scno; i++) {
        x = bg_w.bgw[i].position_x;
        y = bg_w.bgw[i].position_y;
        Scrn_Move_Set(i, x, y);
        x = -x & 0x3FF;
        y = (768 - (y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, x, y);
        continue;
    }
}



void Bg_Family_Set_appoint(s32 num_of_bg) {
    s32 x = bg_w.bgw[num_of_bg].position_x;
    s32 y = bg_w.bgw[num_of_bg].position_y;
    Scrn_Move_Set(num_of_bg, x, y);
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



void Bg_Family_Set_2(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < bg_w.scno; i++) {
        x = bg_w.bgw[i].position_x;
        y = bg_w.bgw[i].position_y;
        y += 8;
        Scrn_Move_Set(i, x, y);
        Family_Set_W(i + 1, -x & 0x3FF, (768 - (y & 0x3FF)) & 0x3FF);
    }
}



void Bg_Family_Set_2_appoint(s32 num_of_bg) {
    s16 x;
    s16 y;
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    y += 8;
    Scrn_Move_Set(num_of_bg, x, y);
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



/* provisional name */
void ake_Family_Set(void) {
    s16 pos_work_x = bg_w.bgw[3].position_x;
    s16 pos_work_y = bg_w.bgw[3].position_y;
    Scrn_Move_Set(3, pos_work_x, pos_work_y);
    pos_work_x = -pos_work_x & 0x3FF;
    pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, pos_work_x, pos_work_y);
}



void ake_Family_Set2(void) {
    s16 x = bg_w.bgw[3].position_x;
    s16 y = bg_w.bgw[3].position_y;
    Scrn_Move_Set(3, x, y);
    x = 512 - bg_w.pos_offset;
    y = 0;
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, x, y);
}



void bg_pos_hosei_sub2(s16 bg_no) {
    u16 pos;
    s16 pos2;
    s16 work;
    pos2 = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos = pos2 & 0x3FF;
    pos -= bg_w.pos_offset;
    pos &= 0x3FF;
    pos += quake_x_tbl[bg_w.quake_x_index];
    bg_w.bgw[bg_no].position_x = pos & 0x3FF;
    pos2 -= bg_w.pos_offset;
    pos2 += quake_x_tbl[bg_w.quake_x_index];
    bg_w.bgw[bg_no].abs_x = pos2;
    pos2 = bg_w.bgw[bg_no].xy[1].disp.pos;
    pos = pos2 & 0x3FF;
    work = quake_y_tbl[bg_w.quake_y_index];
    pos += work;
    pos2 += work;
    bg_w.bgw[bg_no].position_y = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_y = pos2;
}



void bg_pos_hosei_sub3(s16 bg_no) {
    s32 pos;
    s32 pos2;
    volatile s16 work;
    volatile s16 work2;
    pos2 = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos = pos2 & 0x3FF;
    pos -= work = bg_w.pos_offset;
    pos &= 0x3FF;
    pos2 -= work;
    pos += work = quake_x_tbl[bg_w.quake_x_index];
    pos2 += work;
    bg_w.bgw[bg_no].position_x = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_x = pos2;
    pos2 = bg_w.bgw[bg_no].xy[1].disp.pos;
    pos = pos2 & 0x3FF;
    pos += work2 = quake_y_tbl[bg_w.quake_y_index];
    pos2 += work2;
    bg_w.bgw[bg_no].position_y = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_y = pos2;
}

void bg_pos_hosei2(void)
{
    s16 x;
    s16 y;
    s16 quake;
    s16 i;

    for (i = 0; i < bg_w.scno; i++) {
        if (bg_w.chase_flag & 0xF) {
            x = bg_w.bgw[i].chase_xy[0].disp.pos;
        } else {
            x = bg_w.bgw[i].wxy[0].disp.pos;
        }
        bg_w.bgw[i].position_x = ((x & 0x3FF) - bg_w.pos_offset & 0x3FF) + quake_x_tbl[bg_w.quake_x_index] & 0x3FF;
        bg_w.bgw[i].abs_x = x - bg_w.pos_offset + quake_x_tbl[bg_w.quake_x_index];
        if (bg_w.chase_flag & 0xF0) {
            y = bg_w.bgw[i].chase_xy[1].disp.pos;
        } else {
            y = bg_w.bgw[i].xy[1].disp.pos;
        }
        quake = quake_y_tbl[bg_w.quake_y_index];
        bg_w.bgw[i].position_y = (y & 0x3FF) + quake & 0x3FF;
        bg_w.bgw[i].abs_y = y + quake;
        continue;
    }
}



s16 get_center_position(void) {
    if (Bonus_Game_Flag == 0x16) {
        return 0x200;
    }
    return bg_w.bgw[1].wxy[0].disp.pos;
}



s32 get_height_position(void) {
    BGW* blk = &bg_w.bgw[1];
    return blk->xy[1].disp.pos;
}



/* provisional name */
void blit_16x16_tile(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            *d++ = *src++ + code;
            *d++ = *src++ + attr;
        }
        dst += 0x80;
    }
}



/* provisional name */
void blit_8x16_tile(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* d;
    u16* s;
    for (i = 0; i < 16; i++) {
        d = dst;
        s = src;
        for (j = 0; j < 8; j++) {
            *d++ = *s++ + code;
            *d++ = *s++ + attr;
        }
        dst += 0x80;
        src += 0x20;
    }
}



/* provisional name */
void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u32 dst;
    u32 s;
    u16 code;
    dst = (u32)bg_w.bgw[bg].bg_address + ofs;
    s = (cell << 10) + src;
    code = (u32)bg_w.scroll_cg_adr >> 7;
    blit_16x16_tile((u16*)s, code, (u16*)dst, attr);
}



/* provisional name */
void blit_16x16_xflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* s;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            s = &src[i * 32 + 30 - j * 2];
            *d++ = *s++ + code;
            *d = *s + attr;
            *d++ |= 0x1000;
        }
        dst += 0x80;
    }
}



/* provisional name */
void bg_cell_write_xflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_xflip(s, code, dst, attr);
}



/* provisional name */
void blit_16x16_yflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* s;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            s = src + (15 - i) * 32 + j * 2;
            *d++ = *s++ + code;
            *d = *s + attr;
            *d++ |= 0x800;
        }
        dst += 0x80;
    }
}



/* provisional name */
void bg_cell_write_yflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_yflip(s, code, dst, attr);
}



/* provisional name */
void blit_16x16_xyflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* s;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            s = &src[(15 - i) * 32 + (15 - j) * 2];
            *d++ = s[0] + code;
            *d = s[1] + attr;
            *d++ |= 0x1800;
        }
        dst += 0x80;
    }
}



/* provisional name */
void bg_cell_write_xyflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_xyflip(s, code, dst, attr);
}



/* provisional name */
void bg_cell_fill(s16 bg, s16 attr) {
    bg_cell_write(bg, 0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x40, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x80, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0xC0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1000, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1040, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1080, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x10C0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
}



/* provisional name */
void bg_scr_write(void) {
    s16 attr = bg_attr_tbl[bg_w.bg_index] + bg_attr_add_tbl[bg_w.bg_index];
    s16 set;
    HUD_CELL** cells;
    HUD_CELL* c;
    s16 i;
    s16 j;
    if (Country == 8) {
        set = bg_cell_set_tbl[bg_w.stage];
    } else {
        set = 0;
    }
    cells = bg_rewrite_cell_tbl[set];
    for (i = 0; i < bg_w.scno; i++) {
        bg_cell_fill(i, attr);
        for (j = 0; j < bg_cell_cnt_tbl[bg_w.bg_index][i]; j++) {
            c = &cells[i][j];
            bg_cell_write(i, c->ofs, c->cell, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
        }
    }
}



/* provisional name */
void ake_cell_write(s8 map, s32 ofs, s32 cell, u32 src) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)(ake_scrl_w[map].adrs + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.ake_cg_adr >> 7;
    blit_16x16_tile(s, code, dst, 0x3C0);
}



/* provisional name */
void ake_cell_write_attr(s8 map, s32 ofs, s32 cell, u32 src, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)(ake_scrl_w[map].adrs + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.ake_cg_adr >> 7;
    blit_16x16_tile(s, code, dst, attr + 0x3C0);
}



/* provisional name */
void akebono_cell_fill(void) {
    ake_cell_write(1, 0x2000, 1, (u32)ake_scrn_data);
    ake_cell_write(1, 0x2040, 2, (u32)ake_scrn_data);
    ake_cell_write(1, 0x2080, 3, (u32)ake_scrn_data);
    ake_cell_write(1, 0x20C0, 4, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3000, 5, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3040, 6, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3080, 7, (u32)ake_scrn_data);
    ake_cell_write(1, 0x30C0, 8, (u32)ake_scrn_data);
}

/* provisional name */
void akebono_scr_write(void)
{
    s16 *attr = (s16 *)ake_attr_tbl;
    PANEL *cell;
    s16 i;

    cell = (PANEL *)ake_cell1_data;
    for (i = 0; i < 16; i++) {
        ake_cell_write_attr(1, cell->ofs, cell->cell, (u32)ake_scrn_data, *attr);
        attr++;
        cell++;
    }
    cell = (PANEL *)ake_cell2_data;
    for (i = 0; i < 8; i++) {
        ake_cell_write(2, cell->ofs, cell->cell, (u32)ake_scrn_data);
        cell++;
    }
}



/* provisional name */
void bg_etc_scr_write(s16 n) {
    s16 i;
    s16 j;
    TILEREQ* t;
    for (i = 0; i < bg_w.scno; i++) {
        for (j = 0; j < etc_bg_cell_cnt_tbl[n][i]; j++) {
            t = &bg_etc_cell_tbl[n][i][j];
            bg_cell_write(i, t->ofs, t->cell, etc_bg_cg_src_tbl[n], 0, etc_bg_attr_tbl[n] + t->attr);
        }
    }
}



/* provisional name */
void bg_scr_clear_all(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < bg_w.scno; i++) {
        for (j = 0; j < bg_w.scno; j++) {
            u32 dst = (u32)bg_w.bgw[(s16)i].bg_address + (j << 12);
            for (k = 0; k < 4; k++) {
                blit_16x16_tile((u16*)bg_cg_src_tbl[bg_w.bg_index], bg_w.scroll_cg_adr >> 7, (u16*)(dst + k * 0x40), 0);
            }
        }
    }
}



void bg_work_clear(void) {
    s16 i;
    bg_w.bg_routine = 0;
    bg_w.bg_r_1 = 0;
    bg_w.bg_r_2 = 0;
    bg_w.compel_on[0] = 0;
    win_sp_flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
    }
}



/* provisional name */
void compel_bg_init_position(void) {
    s16 i;
    bg_w.compel_on[0] = 1;
    Zoomf_Init();
    bg_w.bg_f_x = 64;
    bg_w.old_bg_f[0] = 64;
    bg_w.bg_f_y = 64;
    bg_w.old_bg_f[1] = 64;
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].xy[0].disp.pos = bg_w.bgw[i].wxy[0].disp.pos = bg_w.bgw[i].pos_x_work;
        bg_w.bgw[i].xy[1].disp.pos = bg_w.bgw[i].wxy[1].disp.pos = bg_w.bgw[i].pos_y_work;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        if (bg_w.bgw[i].zuubun) {
            suzi_line_clear(i);
        }
    }
}
