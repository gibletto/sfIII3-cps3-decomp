/*
 * BG_SUB_3.C  Stage background subroutines: scrolling, zoom, family set, cell writers (part 3)
 *
 * Zoom: zoom_frame_judge, zoom_ud_check, zoom_x_width_check, bg_base_y_move_check. Line scroll:
 * suzi_line_clear, suzi_offset_set, suzi_sync_pos_set.
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

#pragma inline(remake_x_mvstep)



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
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0;
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
    BGW* l;
    s32 k;
    if (l = bgw_ptr, k = bg_w.bg2_sp_y, (s8)bg_w.chase_flag & 0xF0) {
        l->chase_xy[1].cal = l->speed_y * k;
        if (bgw_ptr->y_limit2 < bgw_ptr->chase_xy[1].disp.pos) {
            bgw_ptr->chase_xy[1].disp.pos = bgw_ptr->y_limit2, bgw_ptr->chase_xy[1].disp.low = 0;
        }
        bgw_ptr->chase_xy[1].disp.pos += bgw_ptr->pos_y_work;
    } else {
        l->xy[1].cal = l->speed_y * k;
        if (bgw_ptr->y_limit2 < bgw_ptr->xy[1].disp.pos) {
            bgw_ptr->xy[1].disp.pos = bgw_ptr->y_limit2, bgw_ptr->xy[1].disp.low = 0;
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
    s32 work;
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
/* An earlier frame judgement on the two players' distance alone. */
s32 zoom_frame_judge_dist(void) {
    PLW* p1;
    PLW* p2;
    s16 left;
    s16 right;
    bg_w.frame_flag = 0;
    p1 = &plw[0];
    p2 = &plw[1];
    if (p1->wu.scr_mv_x < plw[1].wu.scr_mv_x) {
        left = p1->wu.scr_mv_x;
        right = p2->wu.scr_mv_x;
    } else {
        left = p2->wu.scr_mv_x;
        right = p1->wu.scr_mv_x;
    }
    right -= left;
    if (right > 304) {
        return 2;
    }
    if (right < 272) {
        return 0;
    }
    return 1;
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
void zoom_y_width_check(void) {
    s32 f;
    if (Game_setting.mode) {
        return;
    }
    /* previous bg_f_y, kept in the unnamed word at bg_w+0x34 */
    bg_w.old_bg_f_y = bg_w.bg_f_y;
    bg_w.frame_flag = zoom_frame_judge();
    f = bg_w.bg_f_y;
    switch (bg_w.frame_flag) {
    case 1:
        if (f < 9) {
            bg_w.bg_f_y++;
            if (bg_w.old_frame_flag == 1) {
                Frame_Up(192, 224, 0, 1);
            }
        }
        break;
    case 2:
        if (f > 0) {
            bg_w.bg_f_y--;
            if (bg_w.old_frame_flag == 2) {
                Frame_Down(192, 224, 0, 1);
            }
        }
        break;
    case 3:
        if (f != 9) {
            Zoomf_Init_Y();
        }
        break;
    }
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
void suzi_line_calc(s16 bg_num) {
    s32* calc;
    s32* line;
    u16* dst;
    u16 top;
    s16 dist;
    s16 i;
    if (bg_stop) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    if ((bg_w.chase_flag & 0xF) == 0) {
        dist = bg_w.bgw[bg_num].wxy[0].disp.pos;
    } else {
        dist = bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    }
    if (dist == bg_w.bgw[bg_num].old_pos_x) {
        return;
    }
    dist -= bg_w.bgw[bg_num].old_pos_x;
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bg_w.bgw[bg_num].zuubun * -dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bg_w.bgw[bg_num].d_line; i++) {
            *line -= calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    } else {
        calc[0] = bg_w.bgw[bg_num].zuubun * dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bg_w.bgw[bg_num].d_line; i++) {
            *line += calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bg_w.bgw[bg_num].suzi_adrs + 2048);
    for (i = 0; i < bg_w.bgw[bg_num].no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
}



/* provisional name */
void suzi_line_calc_fill(s16 bg_num) {
    s32* calc;
    s32* line;
    u16* dst;
    u16 top;
    s16 dist;
    s16 count;
    s16 i;
    if (bg_stop) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    if ((bg_w.chase_flag & 0xF) == 0) {
        dist = bg_w.bgw[bg_num].wxy[0].disp.pos;
    } else {
        dist = bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    }
    if (bg_w.bgw[bg_num].old_pos_x == dist) {
        return;
    }
    dist -= bg_w.bgw[bg_num].old_pos_x;
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bg_w.bgw[bg_num].zuubun * -dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bg_w.bgw[bg_num].d_line; i++) {
            *line -= calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        count = 41 - bg_w.bgw[bg_num].d_line;
        for (i = 0; i < count; i++) {
            *dst = *(u16*)(line - 1);
            dst += 2;
        }
    } else {
        calc[0] = bg_w.bgw[bg_num].zuubun * dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        calc[1] = 0;
        for (i = 0; i < bg_w.bgw[bg_num].d_line; i++) {
            *line += calc[1];
            calc[1] += calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        count = 41 - bg_w.bgw[bg_num].d_line;
        for (i = 0; i < count; i++) {
            *dst = *(u16*)(line - 1);
            dst = dst + 2;
        }
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bg_w.bgw[bg_num].suzi_adrs + 2048);
    for (i = 0; i < bg_w.bgw[bg_num].no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
}

/* provisional name */
void suzi_line_calc_flat(s16 bg_num) {
    s32* calc;
    s32* line;
    u16* dst;
    s32 top;
    s16 dist;
    s16 count;
    s16 i;
    if (bg_stop) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    if ((bg_w.chase_flag & 0xF) == 0) {
        dist = bg_w.bgw[bg_num].wxy[0].disp.pos;
    } else {
        dist = bg_w.bgw[bg_num].chase_xy[0].disp.pos;
    }
    if (dist == bg_w.bgw[bg_num].old_pos_x) {
        return;
    }
    dist -= bg_w.bgw[bg_num].old_pos_x;
    /* calc[0] = step per line, calc[1] = running offset */
    calc = suzi_calc_w;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        calc[0] = bg_w.bgw[bg_num].zuubun * -dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line += calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        line--;
        count = bg_w.bgw[bg_num].d_line - 1;
        for (i = 0; i < count; i++) {
            *dst = *(u16*)line;
            dst += 2;
        }
    } else {
        calc[0] = bg_w.bgw[bg_num].zuubun * dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        calc[1] = calc[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line -= calc[1];
            calc[1] -= calc[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
        line--;
        count = bg_w.bgw[bg_num].d_line - 1;
        for (i = 0; i < count; i++) {
            *dst = *(u16*)line;
            dst += 2;
        }
    }
    top = suzi_line_buf[0];
    dst = (u16*)((u8*)bg_w.bgw[bg_num].suzi_adrs + 2048);
    for (i = 0; i < bg_w.bgw[bg_num].no_suzi_line - 512; i++) {
        *dst = top;
        dst += 2;
    }
}
