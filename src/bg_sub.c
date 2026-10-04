/*
 * BG_SUB.C  Stage background subroutines: scrolling, zoom, family set, cell writers
 *
 * Shared machinery used by every stage routine. Scrolling: check_cg_zoom and the scr_1x_2x rules
 * decide how the main layer follows the two players; bg_base_x_move_check, bg_x/y_move_check and
 * remake_x_mvstep move the layers; the chase routines handle requested scrolls. Tile writers blit
 * 16x16 and 8x16 cells (plain, flipped, wrapped) and the HUD rectangle; bg_work_clear and
 * compel_bg_init_position reset the display. A few debug helpers step through the stages from the
 * controls.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_5.h"
#include "bg_sub.h"

#pragma inline(remake_x_mvstep)

s32 remake_x_mvstep(s16 x);



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
    s32 i;
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
    s32 changed;
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

    for (i = 0; i < bg_w.scno; i++) {
        if ((((SCROLL_CTRL*)((u8*)scrn_reg_w + (s8)(i * sizeof(SCROLL_CTRL))))->ctrl & 0x8000) == 0) {
            continue;
        }
        Bg_Off_W(1 << i);
    }
    if ((scrn_reg_w[3].ctrl & 0x8000) != 0) {
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
    if (!Bonus_Game_Flag) {
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


