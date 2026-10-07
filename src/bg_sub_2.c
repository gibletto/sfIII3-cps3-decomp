/*
 * BG_SUB_2.C  Stage background subroutines: scrolling, zoom, family set, cell writers (part 2)
 *
 * Routines: bgw_xy_add, bgw_wxy_add, Bg_mv_tw, Bg_mv_tw_appoint, x_right_check, x_left_check,
 * scr_x_dummy, scr_10_20, scr_10_21, scr_10_22, scr_11_20, scr_11_21, ...
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
#include "bg_sub_3.h"
#include "bg_sub_5.h"
#include "bg_sub_2.h"

#pragma inline(remake_x_mvstep)


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
        bg_w.bg2_sp_y = bgw_ptr->chase_xy[1].disp.pos - bgw_ptr->pos_y_work;
    }
}

/* provisional name */
void bgw_xy_add(s32 x, s32 y) {
    bgw_ptr->xy[0].cal += x;
    bgw_ptr->xy[1].cal += y;
}


/* provisional name */
void bgw_wxy_add(s32 x, s32 y) {
    bgw_ptr->wxy[0].cal += x;
    bgw_ptr->wxy[1].cal += y;
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
    s32 meri;
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



/* provisional name: an unreferenced copy of scr_11_22 */
void scr_11_22_2(void) {
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



/* provisional name: an unreferenced copy of scr_12_21 */
void scr_12_21_2(void) {
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

s32 remake_x_mvstep(s16 x) {
    return x * 80 / 100;
}



/* provisional name */
void bg_base_x_move_check(void) {
    s16 mvstep;
    s16 max_x;
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
            max_x = bg_w.max_x;
            if (mvstep < 0) {
                if (mvstep < -max_x) {
                    mvstep = -max_x;
                }
                mvstep = -remake_x_mvstep(-mvstep);
            } else {
                if (mvstep > max_x) {
                    mvstep = max_x;
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
