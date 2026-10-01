/*
 * ta_sub.c  Stage background object helpers
 *
 * Shared routines for the stage background tasks and their objects (effects that live in the
 * stage). sync_fam_set / sync_fam_set2 / sync_fam_set3 set a plane's family position
 * from its BG position. range_x_check / y_range / xy_range decide whether an object is on
 * screen, and the disp_pos_trans_entry_* family converts an object's position to screen
 * coordinates and draws it only when it is visible (and background objects are not switched
 * off). eff_hit_check and its helpers test each player (while in routine states 14..23) against the
 * object's hit box using pl_hit_eff / eff_hit_data and count contacts in eff_hit_flag.
 * Small state checks used by stage objects: complete_victory_check, either_pl_hissatsu_check
 * (a player is doing a special move), compel_dead_check, pl_shot_on_check (a button is down),
 * range_abs_check, plus waza_slot_clear_all_p and win_lose_work_clear.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "fifo.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "ta_sub.h"

#pragma inline(obr_disp_off)

static s32 obr_disp_off(void);

struct PLW_tag;



/* provisional name */
void waza_slot_clear_all_p(PLW* pl) {
    s16 j;
    for (j = 0; j < 56; j++) {
        if (wcp[pl->wu.id].waza_flag[j] != -1) {
            waza_work[pl->wu.id][j].w_type = 0;
        }
    }
}



/* provisional name */
s32 sw_to_lvbt(s32 value) {
    s32 lvbt = value & 127;
    lvbt |= ((u16)value << 1) & 0x700;
    return lvbt;
}



/* provisional name */
void sync_fam_set(s16 num_of_bg) {
    s32 x;
    s32 y;
    bg_pos_hosei_sub3(num_of_bg);
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    x = -x & 0x3FF;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



/* provisional name */
void sync_fam_set2(s16 num_of_bg) {
    s32 x;
    s32 y;
    bg_pos_hosei_sub2(num_of_bg);
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    x = -x & 0x3FF;
    y = (0x300 - ((y + 8) & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



void sync_fam_set3(s16 bg_no) {
    BGW* bgw_ptr = &bg_w.bgw[bg_no];
    u16 pos;
    u16 pos2;
    u16 posy2;
    u16 x;
    u16 y;
    pos2 = (bg_w.chase_flag & 0xF) ? bgw_ptr->chase_xy[0].disp.pos : bgw_ptr->wxy[0].disp.pos;
    posy2 = (bg_w.chase_flag & 0xF0) ? bgw_ptr->chase_xy[1].disp.pos : bgw_ptr->xy[1].disp.pos;
    pos = pos2 & 0x3FF;
    pos -= bg_w.pos_offset;
    pos2 -= bg_w.pos_offset;
    if (bg_w.quake_x_index > 0) {
        pos += quake_x_tbl[bg_w.quake_x_index];
        pos2 += quake_x_tbl[bg_w.quake_x_index];
    }
    bg_w.bgw[bg_no].position_x = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_x = pos2;
    x = -pos & 0x3FF;
    pos = posy2 & 0x3FF;
    pos += quake_y_tbl[bg_w.quake_y_index];
    posy2 += quake_y_tbl[bg_w.quake_y_index];
    bg_w.bgw[bg_no].position_y = y = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_y = posy2;
    y = (0x300 - y) & 0x3FF;
    Family_Set_W(bg_no + 1, x, y);
}



s32 range_x_check(WORK* wk) {
    s16 x;
    s16 left;
    s16 right;
    if (bg_w.chase_flag & 0xF) {
        x = bg_w.bgw[wk->my_family - 1].chase_xy[0].disp.pos;
    } else {
        x = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos;
    }
    left = x - 193;
    right = x + 193;
    if (left > wk->xyz[0].disp.pos) {
        return 0;
    } else if (wk->xyz[0].disp.pos > right) {
        return 0;
    } else {
        return 1;
    }
}



/* provisional name */
s32 range_x_check2(WORK* wk) {
    s16 left;
    s16 right;
    s16 w;
    left = bg_w.bgw[wk->my_family - 1].abs_x;
    w = 320;
    left -= w;
    if (left > wk->xyz[0].disp.pos) {
        return 0;
    }
    right = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos;
    right += w;
    if (wk->xyz[0].disp.pos > right) {
        return 0;
    }
    return 1;
}



s32 range_x_check3(WORK* wk, s16 w) {
    s16 x;
    s16 left;
    s16 right;
    if (bg_w.chase_flag & 0xF) {
        x = bg_w.bgw[wk->my_family - 1].chase_xy[0].disp.pos;
    } else {
        x = bg_w.bgw[wk->my_family - 1].wxy[0].disp.pos;
    }
    left = x - w - 192;
    right = x + w + 192;
    if (left > wk->xyz[0].disp.pos) {
        return 0;
    } else if (wk->xyz[0].disp.pos > right) {
        return 0;
    } else {
        return 1;
    }
}



s32 range_y_check(WORK* wk) {
    s16 y;
    s16 top;
    s16 bottom;
    if (bg_w.chase_flag & 0xF) {
        y = bg_w.bgw[wk->my_family - 1].chase_xy[1].disp.pos;
    } else {
        y = bg_w.bgw[wk->my_family - 1].wxy[1].disp.pos;
    }
    top = y + 256;
    bottom = y - 32;
    if (top < wk->xyz[1].disp.pos) {
        return 0;
    } else if (bottom > wk->xyz[1].disp.pos) {
        return 0;
    } else {
        return 1;
    }
}



/* provisional name */
s32 range_xy_check(WORK_Other* ewk) {
    if (!range_x_check(ewk)) {
        return 0;
    }
    if (!range_y_check(ewk)) {
        return 0;
    }
    return 1;
}



/* provisional name */
s32 range_x_out_y_in_check(WORK_Other* ewk, s16 bg_no) {
    s16 pos_y_work;
    s16 work2;
    s16 work3;
    if (range_x_check(ewk)) {
        return 0;
    }
    if (bg_w.chase_flag & 0xF) {
        pos_y_work = bg_w.bgw[bg_no].chase_xy[1].disp.pos;
    } else {
        pos_y_work = bg_w.bgw[bg_no].wxy[1].disp.pos;
    }
    work2 = pos_y_work + 256;
    work3 = pos_y_work - 32;
    if (work2 < ewk->wu.xyz[1].disp.pos) {
        return 0;
    } else if (work3 > ewk->wu.xyz[1].disp.pos) {
        return 0;
    }
    return 1;
}



void add_x_sub(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
}



void add_x_sub2(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
}



void add_y_sub(WORK_Other* ewk) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
}



void add_y_sub2(WORK_Other* ewk) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
}



/* provisional name */
s32 obr_disp_off_check(void) {
    if (seraph_flag | akebono_flag | sa_pa_flag) {
        return 1;
    }
    return 0;
}

/* provisional name */
static s32 obr_disp_off(void) {
    if (seraph_flag | akebono_flag | sa_pa_flag) {
        return 1;
    }
    return 0;
}



void disp_pos_trans_entry(WORK_Other* ewk) {
    if (obr_disp_off()) {
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



void disp_pos_trans_entry5(WORK_Other* ewk) {
    if (obr_disp_off()) {
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



void disp_pos_trans_entry_r(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(ewk);
        }
    }
}



/* provisional name */
void disp_pos_trans_entry_rxy(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        if (range_xy_check(ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(ewk);
        }
    }
}



void disp_pos_trans_entry_r4(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        if (range_y_check((WORK*)ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(ewk);
        }
    }
}



/* provisional name */
void disp_pos_trans_entry_rbg(WORK_Other* ewk, s16 bg_no) {
    if (obr_disp_off() == 0) {
        if (range_x_out_y_in_check(ewk, bg_no) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(ewk);
        }
    }
}

void disp_pos_trans_entry_s(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
    }
}



void disp_pos_trans_entry_rs(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            suzi_sync_pos_set(ewk);
            sort_push_request4(ewk);
        }
    }
}

/* provisional name */
void disp_pos_trans_entry_seraph(WORK_Other* ewk)
{
    if (seraph_flag) {
        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
    }
}



void pl_eff_trans_entry(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request(&ewk->wu);
    }
}



/* provisional name */
void pl_eff_trans_entry_r(WORK_Other* ewk) {
    if (obr_disp_off() == 0) {
        if (range_x_check((WORK*)ewk) != 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request(ewk);
        }
    }
}



/* Accumulates this effect's hits on the players; returns its hit count. */
s32 eff_hit_check(WORK_Other* ewk, s16 type) {
    if (!EXE_obroll) {
        if (type) {
            if (pcon_dp_flag) {
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[0]);
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[1]);
            }
        } else {
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[0]);
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub(ewk, &plw[1]);
        }
    }
    return eff_hit_flag[ewk->wu.type];
}



s32 eff_hit_check_sub(WORK_Other* ewk, PLW* pl) {
    if (pl->wu.routine_no[1] == 1) {
        if (pl->wu.routine_no[2] < 14 || pl->wu.routine_no[2] >= 24) {
            return 0;
        }
        if (hit_check_subroutine(
                &pl->wu, &ewk->wu, &pl_hit_eff[pl->player_number][0], &eff_hit_data[ewk->wu.type][0])) {
            return 1;
        }
    }
    return 0;
}

s16 eff_hit_check2(ewk, type, where_type)
WORK_Other* ewk;
s16 type;
s16 where_type;
{
    if (!EXE_obroll) {
        if (type) {
            if (pcon_dp_flag) {
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub2(ewk, &plw[0]);
                eff_hit_flag[ewk->wu.type] += eff_hit_check_sub2(ewk, &plw[1]);
            }
        } else {
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub2(ewk, &plw[0], where_type);
            eff_hit_flag[ewk->wu.type] += eff_hit_check_sub2(ewk, &plw[1], where_type);
        }
    }
    return eff_hit_flag[ewk->wu.type];
}

s32 eff_hit_check_sub2(ewk, pl, where_type)
WORK_Other* ewk;
PLW* pl;
s16 where_type;
{
    s16* hd1 = pl->wu.h_bod->body_dm[where_type];
    if (hit_check_subroutine_yu(&pl->wu, &ewk->wu, hd1, (s16*)eff_hit_data[ewk->wu.type])) {
        return 1;
    }
    return 0;
}



s32 hit_check_subroutine_yu(WORK* tpl, WORK* tef, s16* hd1, s16* hd2) {
    s16 d0 = *hd1++;
    s16 d1 = *hd1++;
    s16 d2;
    s16 d3;
    s16 flag;
    if (tpl->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += tpl->xyz[0].disp.pos;
    d2 = *hd2++;
    d3 = *hd2++;
    if (tef->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += tef->xyz[0].disp.pos;
    flag = (d0 < d2);
    d2 += (d3 - d0);
    d3 += d1;
    if ((u32)d2 >= d3) {
        return 0;
    }
    d0 = (tpl->xyz[1].disp.pos + *hd1++) - (tef->xyz[1].disp.pos + *hd2++ - 40);
    d0 += d1 = *hd1;
    d1 += *hd2;
    if ((u32)d0 >= d1) {
        return 0;
    } else if (flag) {
        d2 = d3 - d2;
    }
    return d2;
}



void eff_hit_flag_clear(void) {
    s16 i;
    s16* ptr;
    ptr = &eff_hit_flag[0];
    for (i = 0; i < 0xB; i++) {
        *ptr++ = 0;
    }
}



/* provisional name */
s32 complete_victory_check(void) {
    if (!Allow_a_battle_f && Conclusion_Flag == 1 && C_No[0] >= 2 && Complete_Victory) {
        return 1;
    }
    return 0;
}

/* provisional name */
u32 range_abs_check(s16 a, s16 b, s16 range)
{
    s16 dist;
    dist = a - b;
    if (dist < 0) {
        dist = -dist;
    }
    if (dist < range) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 either_pl_hissatsu_check(void) {
    if (plw[0].wu.routine_no[1] == 4 && plw[0].wu.routine_no[2] >= 16) {
        return 1;
    }
    if (plw[1].wu.routine_no[1] == 4 && plw[1].wu.routine_no[2] >= 16) {
        return 1;
    }
    return 0;
}



s32 compel_dead_check(WORK_Other* ewk) {
    if (bg_w.compel_on[0] != 0 && ewk->wu.dead_f != 0) {
        return 1;
    }
    return 0;
}

/* provisional name */
s32 pl_shot_on_check(pl)
s16 pl;
{
    if (pl) {
        if (p2sw_0 & 0x3F0) {
            return 1;
        }
        return 0;
    }
    if (p1sw_0 & 0x3F0) {
        return 1;
    }
    return 0;
}



void win_lose_work_clear(void) {
    a_rno = 0;
    lose_rno[2] = 0;
    win_rno[0] = 0;
    win_free[0] = 0;
    lose_rno[0] = 0;
    lose_free[0] = 0;
    win_rno[1] = 0;
    win_free[1] = 0;
    lose_rno[1] = 0;
    lose_free[1] = 0;
}
