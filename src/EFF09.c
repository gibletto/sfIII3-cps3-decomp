/*
 * EFF09.C  Effect 09: character props for appearances and win poses
 *
 * Effect 09 is a family of props that belong to a character. effect_09_init2 creates one
 * from eff09_data2 (colour, offset from the owner, priority, animation) and is used by the
 * appearance scripts in appear.c; effect_09_init creates one from eff09_data.
 * effect_09_move dispatches through eff09_tbl to the behaviour routines eff09_0000 to
 * eff09_27000: plain animations, props thrown and caught, and sean_ball_move, a ball that
 * bounces under gravity and is hit-checked against the players (creating effect B4).
 * jijii_win_tama_sub handles the ball in one of the old man's win poses.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFB4.h"
#include "EFFECT.h"
#include "HITCHECK.h"
#include "PLS02.h"
#include "CHARSET.h"
#include "SE.h"
#include "bg_sub.h"
#include "EFF09.h"


void effect_09_move(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[1] = 99;
    }
    eff09_tbl[ewk->wu.routine_no[0]](ewk);
}



void eff09_0000(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_1000(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = 4;
        ewk->wu.old_rno[0] = random_16_com();
        ewk->wu.old_rno[0] &= 1;
        if (ewk->master_id) {
            ewk->wu.type = 10;
        } else {
            ewk->wu.type = 9;
        }
        if (EXE_obroll) {
            set_char_move_init(&ewk->wu, 0, 25);
            ewk->wu.old_rno[0] = 1;
        } else if (ewk->wu.old_rno[0]) {
            set_char_move_init(&ewk->wu, 0, 25);
        } else {
            set_char_move_init(&ewk->wu, 0, 65);
        }
        sort_push_request(&ewk->wu);
        break;
    case 1:
    case 3:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
            }
        }
        if (obr_disp_off_check()) {
            break;
        }
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (obr_disp_off_check()) {
            break;
        }
        if (ewk->wu.old_rno[0] && !EXE_flag && !Game_pause && !EXE_obroll && eff_hit_check(ewk, 0)) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 65);
        }
        sort_push_request(&ewk->wu);
        break;
    case 4:
        if (obr_disp_off_check()) {
            break;
        }
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_2000(WORK_Other* ewk) {
    s16 work;
    const s32* ptr;
    u16 sw_work;
    const s16* pl_hit_ptr;
    PLW* hit_pl;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        Appear_free[ewk->master_id] = 0;
        if (ewk->master_id) {
            sw_work = p2sw_0;
        } else {
            sw_work = p1sw_0;
        }
        if (sw_work & 0x1000) {
            work = 0;
        } else {
            work = random_16_com();
            work &= 1;
        }
        ewk->wu.dir_step = work;
        ptr = eff09_2000_data[ewk->wu.dir_step];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;
        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
            ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
        }
        ewk->wu.old_rno[0] = ewk->wu.old_rno[1] = ewk->wu.old_rno[2] = ewk->wu.old_rno[3] = 0;
        suzi_sync_pos_set(ewk);
        sort_push_request(ewk);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[0].disp.pos > 784 || ewk->wu.xyz[0].disp.pos < 240) {
                ewk->wu.routine_no[1] = 99;
                Appear_free[ewk->master_id] = 1;
                ewk->wu.disp_flag = 0;
            }
            if (ewk->master_id) {
                sw_work = p2sw_0;
                hit_pl = &plw[0];
                pl_hit_ptr = &plw[0].wu.h_bod->body_dm[0][0];
            } else {
                sw_work = p1sw_0;
                hit_pl = &plw[1];
                pl_hit_ptr = &plw[1].wu.h_bod->body_dm[0][0];
            }
            sean_ball_move(ewk, sw_work);
            if (((s16)hit_check_subroutine(&hit_pl->wu, &ewk->wu, pl_hit_ptr, sean_ball_hit))) {
                ewk->wu.routine_no[1]++;
                ball_bound_set(ewk);
                set_char_move_init2(&hit_pl->wu, 9, 63, 1, 0);
                Appear_free[ewk->master_id] = 2;
                effect_B4_init(ewk);
                work = random_16_com();
                work &= 7;
                hit_pl = ewk->master_id ? &plw[1] : &plw[0];
                add_super_arts_gauge(hit_pl->sa, hit_pl->wu.id, 1, hit_pl->metamorphose);
                return;
            }
            if (ewk->wu.xyz[1].disp.pos < 0) {
                Sound_SE((ewk->master_id * 0x300) + 0x157);
                ewk->wu.routine_no[1]++;
                ball_bound_set(ewk);
                Appear_free[ewk->master_id] = 1;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.xyz[0].disp.pos > 784 || ewk->wu.xyz[0].disp.pos < 240 || ewk->wu.xyz[1].disp.pos < -56) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            } else {
                add_x_sub(ewk);
                add_y_sub(ewk);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(ewk);
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void sean_ball_move(WORK_Other* ewk, u16 sw_work) {
    if (!plw[ewk->master_id].wu.operator) {
        return;
    }
    if (sw_work & 1) {
        ewk->wu.old_rno[0]++;
        if (ewk->wu.old_rno[0] < 8) {
            ewk->wu.mvxy.d[1].sp += eff09_add_tbl0[ewk->wu.dir_step][0];
        }
    }
    if (sw_work & 2) {
        ewk->wu.old_rno[1]++;
        if (ewk->wu.old_rno[1] < 8) {
            ewk->wu.mvxy.d[1].sp += eff09_add_tbl0[ewk->wu.dir_step][1];
        }
    }
    if (sw_work & 4) {
        ewk->wu.old_rno[2]++;
        if (ewk->wu.rl_flag) {
            if (ewk->wu.old_rno[2] < 4) {
                ewk->wu.mvxy.d[0].sp += eff09_add_tbl1[ewk->wu.dir_step][0];
            }
        } else if (ewk->wu.old_rno[2] < 8) {
            ewk->wu.mvxy.d[0].sp += eff09_add_tbl2[ewk->wu.dir_step][0];
        }
    }
    if (sw_work & 8) {
        ewk->wu.old_rno[3]++;
        if (ewk->wu.rl_flag) {
            if (ewk->wu.old_rno[3] < 8) {
                ewk->wu.mvxy.d[0].sp += eff09_add_tbl1[ewk->wu.dir_step][1];
            }
        } else if (ewk->wu.old_rno[3] < 4) {
            ewk->wu.mvxy.d[0].sp += eff09_add_tbl2[ewk->wu.dir_step][1];
        }
    }
}



void ball_bound_set(WORK_Other* ewk) {
    ewk->wu.mvxy.a[0].sp = -0x40000;
    ewk->wu.mvxy.a[1].sp = 0x60000;
    ewk->wu.mvxy.d[0].sp = -0x1000;
    ewk->wu.mvxy.d[1].sp = -0x8000;
    ewk->wu.dir_timer = 12;
    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
    }
}



void eff09_3000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Exec_Wipe) {
            ewk->wu.routine_no[1] = 99;
            break;
        }
        Sound_SE((Winner_id * 0x300) + 0x136);
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 96;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.xyz[0].disp.pos, 40, 1, 2);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
            } else {
                add_y_sub(ewk);
            }
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (Exec_Wipe) {
            Sound_SE((Winner_id * 0x300) + 0x130);
        }
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_4000(WORK_Other* ewk) {
    s16 work;
    s16 work2;
    WORK* oya_ptr;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 2;
        ewk->wu.kage_hy = -3;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        ewk->wu.my_col_code = 0x2000;
        ewk->wu.position_z = ewk->wu.my_priority = 20;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya_ptr = (WORK*)ewk->my_master;
        ewk->wu.rl_flag = oya_ptr->rl_flag;
        if (oya_ptr->rl_flag) {
            work = bg_w.bgw[1].xy[0].disp.pos - 272;
            work2 = oya_ptr->xyz[0].disp.pos - 88;
        } else {
            work = bg_w.bgw[1].xy[0].disp.pos + 272;
            work2 = oya_ptr->xyz[0].disp.pos + 88;
        }
        ewk->wu.xyz[0].disp.pos = work;
        ewk->wu.old_rno[0] = 202;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 29);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_5000(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_6000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        } else {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
        }
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff09_7000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 32;
        if (ewk->master_id) {
            ewk->wu.mvxy.a[0].sp = 0x30000;
            ewk->wu.mvxy.a[1].sp = 0x90000;
            ewk->wu.mvxy.d[0].sp = 0x1000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x30000;
            ewk->wu.mvxy.a[1].sp = 0x90000;
            ewk->wu.mvxy.d[0].sp = -0x1000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case 1:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
            break;
        }
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_8000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_s(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_9000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos -= 6;
        } else {
            ewk->wu.xyz[0].disp.pos -= 2;
        }
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_10000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos -= 6;
        } else {
            ewk->wu.xyz[0].disp.pos -= 2;
        }
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_11000(WORK_Other* ewk) {
    s16 work;
    s16 work2;
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 2;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        ewk->wu.my_col_code = 0x2000;
        ewk->wu.position_z = ewk->wu.my_priority = 20;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.rl_flag = oya_ptr->rl_flag ^ 1;
        if (oya_ptr->rl_flag) {
            work = bg_w.bgw[1].xy[0].disp.pos + 272;
            work2 = oya_ptr->xyz[0].disp.pos + 56;
        } else {
            work = bg_w.bgw[1].xy[0].disp.pos - 272;
            work2 = oya_ptr->xyz[0].disp.pos - 56;
        }
        ewk->wu.xyz[0].disp.pos = work;
        ewk->wu.old_rno[0] = 220;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 1) {
                ewk->wu.routine_no[1]++;
                oya_ptr->cmwk[0] = 9;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        add_x_sub(ewk);
        if (oya_ptr->rl_flag) {
            if (oya_ptr->xyz[0].disp.pos > ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
            }
        } else if (oya_ptr->xyz[0].disp.pos < ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
        }
    case 3:
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_12000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.a[1].sp = -0x10000;
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = -0x20000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x20000;
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < 56) {
            ewk->wu.routine_no[1]++;
            ewk->wu.blink_timing = 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.old_rno[1] = 20;
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            break;
        }
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_13000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 83);
                ewk->wu.mvxy.a[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][0];
                ewk->wu.mvxy.d[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][1];
                ewk->wu.mvxy.a[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][2];
                ewk->wu.mvxy.d[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][3];
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[0].disp.pos < bg_w.bgw[1].pos_x_work - 240 ||
                ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 240 || ewk->wu.xyz[1].disp.pos > 512) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_14000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    if (ewk->wu.rl_flag) {
        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - eff09_data2[ewk->wu.type][2];
    } else {
        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + eff09_data2[ewk->wu.type][2];
    }
    ewk->wu.xyz[1].disp.pos = oya_ptr->xyz[1].disp.pos + eff09_data2[ewk->wu.type][3];
    ewk->wu.xyz[1].disp.pos += base_y_pos;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_15000(WORK_Other* ewk) {
    WORK* oya_ptr;
    if (obr_disp_off_check()) {
        return;
    }
    oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (oya_ptr->cg_type == 9) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_16000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.xyz[0].disp.pos += 2;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        ewk->wu.rl_flag = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_17000(WORK_Other* ewk) {
    WORK* oya_ptr;
    if (obr_disp_off_check()) {
        return;
    }
    oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (oya_ptr->cg_type == 9) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            } else if (oya_ptr->routine_no[1] != 4 || oya_ptr->routine_no[2] != 30) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos;
        if (oya_ptr->rl_flag) {
            ewk->wu.xyz[0].disp.pos -= eff09_data2[21][2];
        } else {
            ewk->wu.xyz[0].disp.pos += eff09_data2[21][2];
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_18000(WORK_Other* ewk) {
    WORK* oya_ptr;
    if (obr_disp_off_check()) {
        return;
    }
    oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        if (oya_ptr->rl_flag) {
            if (oya_ptr->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
                ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - 256;
            } else {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
            }
        } else if (oya_ptr->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }
        ewk->wu.xyz[1].disp.pos = base_y_pos + 160;
        ewk->wu.old_rno[0] = 35;
        ewk->wu.old_rno[1] = oya_ptr->xyz[1].disp.pos + 106 + base_y_pos;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.old_rno[1], 0, 0);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
            } else {
                add_x_sub2(ewk);
                add_y_sub2(ewk);
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_19000(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.a[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][0];
        ewk->wu.mvxy.d[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][1];
        ewk->wu.mvxy.a[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][2];
        ewk->wu.mvxy.d[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][3];
        ewk->wu.routine_no[1]++;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
    case 2:
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos <= 63) {
                ewk->wu.xyz[1].cal = 0x3F0000;
                ewk->wu.mvxy.a[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][0];
                ewk->wu.mvxy.d[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][1];
                ewk->wu.mvxy.a[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][2];
                ewk->wu.mvxy.d[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][3];
                ewk->wu.routine_no[1]++;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos <= 63) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_20000(WORK_Other* ewk) {
    WORK* oya_ptr;
    s16 pos_work;
    oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 5;
        ewk->wu.kage_hy = base_y_pos + 2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 11;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (oya_ptr->id) {
                pos_work = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
                pos_work -= 64;
                if (ewk->wu.xyz[0].disp.pos < pos_work) {
                    oya_ptr->cmwk[1] = 1;
                    ewk->wu.routine_no[1]++;
                }
            } else {
                pos_work = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
                pos_work += 64;
                if (ewk->wu.xyz[0].disp.pos > pos_work) {
                    oya_ptr->cmwk[1] = 1;
                    ewk->wu.routine_no[1]++;
                }
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_21000(WORK_Other* ewk) {
    s16 arrive_x;
    s16 arrive_y;
    if (Suicide[0]) {
        ewk->wu.routine_no[1] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x8000;
        if (ewk->wu.type == 29) {
            ewk->wu.old_rno[0] = 70;
            if (ewk->wu.rl_flag) {
                arrive_x = ewk->wu.xyz[0].disp.pos + 42;
            } else {
                arrive_x = ewk->wu.xyz[0].disp.pos - 42;
            }
            arrive_y = ewk->wu.xyz[1].disp.pos + 6;
        } else {
            ewk->wu.old_rno[0] = 64;
            if (plw[Winner_id].wu.rl_flag) {
                arrive_x = plw[Winner_id].wu.xyz[0].disp.pos + 28;
            } else {
                arrive_x = plw[Winner_id].wu.xyz[0].disp.pos - 28;
            }
            arrive_y = plw[Winner_id].wu.xyz[1].disp.pos + 162;
        }
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], arrive_x, arrive_y, 2, 2);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 58);
            } else {
                add_x_sub(ewk);
                add_y_sub(ewk);
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
                plw[Winner_id].wu.cmwk[0] = 1;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_22000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 62);
            } else if (oya_ptr->cg_ix != ewk->wu.cg_ix) {
                work = oya_ptr->cg_ix / oya_ptr->cgd_type;
            set_pat:
                set_char_move_init2(&ewk->wu, 0, 61, work + 1, 0);
                ewk->wu.cg_ix = oya_ptr->cg_ix;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
    }
}



void eff09_23000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16* exe = &EXE_flag;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 1;
        ewk->wu.kage_hy = -2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 11;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!*exe && !Game_pause) {
            if (oya_ptr->cg_type == 1) {
                ewk->wu.routine_no[1]++;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 2:
        if (!*exe && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                if (ewk->wu.rl_flag) {
                    ewk->wu.mvxy.a[0].sp = -0x20000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0x20000;
                }
                ewk->wu.mvxy.d[0].sp = 0;
                set_char_move_init(&ewk->wu, 0, 64);
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 3:
        if (!*exe && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            if (range_x_check3(ewk, 64) == 0) {
                ewk->wu.routine_no[1]++;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        goto dflt;
    }
    return;
dflt:
    all_cgps_put_back(ewk);
    push_effect_work(&ewk->wu);
}



void eff09_24000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        if (ewk->wu.type == 38) {
            ewk->wu.rl_flag ^= 1;
        }
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        return;
    case 1:
        if (!EXE_flag && !Game_pause) {
            if (oya_ptr->cg_type == 1) {
                ewk->wu.routine_no[1]++;
                if (ewk->wu.type == 38) {
                    ewk->wu.routine_no[1] = 99;
                }
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 9) {
                ewk->wu.routine_no[1]++;
                char_move_z(&ewk->wu);
                if (ewk->wu.type == 35) {
                    ewk->wu.mvxy.a[0].sp = 0x18000;
                } else {
                    ewk->wu.mvxy.a[0].sp = -0x18000;
                }
                if (ewk->wu.rl_flag) {
                    s32* sp = &ewk->wu.mvxy.a[0].sp;
                    *sp = -*sp;
                }
                ewk->wu.mvxy.d[0].sp = 0;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            if (ewk->wu.type == 34) {
                if (range_x_check3(ewk, 176) == 0) {
                    ewk->wu.routine_no[1]++;
                }
            } else {
                if (range_x_check3(ewk, 88) == 0) {
                    ewk->wu.routine_no[1]++;
                }
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        goto dflt;
    }
    return;
dflt:
    all_cgps_put_back(ewk);
    push_effect_work(&ewk->wu);
}



void eff09_25000(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x6000;
        if (ewk->wu.type == 36) {
            ewk->wu.mvxy.a[0].sp = 0x48000;
            ewk->wu.mvxy.a[1].sp = 0x10000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x28000;
            ewk->wu.mvxy.a[1].sp = 0x30000;
        }
        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
        pl_eff_trans_entry(ewk);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (range_x_check3(ewk, 16) == 0) {
                ewk->wu.routine_no[1]++;
            } else if (ewk->wu.xyz[1].disp.pos < 0) {
                ewk->wu.xyz[1].cal = 0;
                ewk->wu.mvxy.a[1].sp = 0x40000;
                Sound_SE((ewk->master_id * 0x300) + 0x157);
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff09_26000(WORK_Other* ewk) {
    WORK* oya_ptr;
    oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 101);
        ewk->wu.old_rno[0] = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 9) {
                ewk->wu.routine_no[1]++;
                oya_ptr->cmwk[0] = 1;
            }
        }
        jijii_win_tama_sub(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 102);
            }
        }
        jijii_win_tama_sub(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (oya_ptr->cmwk[0] == 2) {
                ewk->wu.routine_no[1]++;
            }
        }
        jijii_win_tama_sub(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }
        ewk->wu.xyz[1].disp.pos = oya_ptr->position_y + base_y_pos;
        ewk->wu.xyz[1].disp.pos -= 42;
        jijii_win_tama_sub(ewk);
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void jijii_win_tama_sub(WORK_Other* ewk) {
    WORK* mwk;
    mwk = (WORK*)ewk->my_master;
    ewk->wu.old_rno[0] ^= 1;
    if (ewk->wu.old_rno[0]) {
        ewk->wu.position_z = mwk->position_z - 2;
    } else {
        ewk->wu.position_z = mwk->position_z + 2;
    }
}



void eff09_27000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -8;
        ewk->wu.kage_hy = -11;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 8;
        ewk->wu.mvxy.a[0].sp = -0x80000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x6000;
        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos < -8) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[1].cal = -0x80000;
                ewk->wu.mvxy.a[0].sp = -0x38000;
                ewk->wu.mvxy.d[0].sp = 0;
                if (ewk->wu.rl_flag) {
                    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                }
                set_char_move_init2(&ewk->wu, 0, 107, 2, 0);
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            if (range_x_check3(ewk, 36) == 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_09_init(WORK_Other* mk, s8 kind) {
    WORK_Other* ewk;
    const s16* data;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.type = kind;
    ewk->wu.be_flag = 1;
    data = (const s16*)((const u8*)eff09_data + (s8)((s8)ewk->wu.type * 18));
    ewk->wu.id = 9;
    ewk->wu.work_id = 16;
    ewk->master_id = mk->wu.id;
    ewk->wu.my_priority = 64;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = eff09_char_table;
    ewk->wu.routine_no[0] = data[0];
    ewk->wu.my_family = data[1];
    ewk->wu.my_col_code = data[2];
    ewk->wu.xyz[0].disp.pos = data[3];
    ewk->wu.xyz[1].disp.pos = data[4];
    ewk->wu.position_z = ewk->wu.my_priority = data[5];
    ewk->wu.char_index = data[6];
    ewk->wu.hit_stop = data[7];
    ewk->wu.sync_suzi = data[8];
    suzi_offset_set(&ewk->wu);
    return 0;
}



s32 effect_09_init2(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if (data == 0x1F && bg_w.stage == 0xA) {
        return 0;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.type = data;
    ewk->my_master = (u32*)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 9;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.my_col_mode = wk->my_col_mode;
    data_ptr = eff09_data2[ewk->wu.type];
    ewk->wu.routine_no[0] = *data_ptr++;
    switch (data) {
    case 18:
    case 19:
    case 31:
        ewk->wu.my_col_code = 0x2020;
        data_ptr++;
        break;
    case 24:
    case 25:
    case 26:
    case 27:
        ewk->wu.my_col_code = 99;
        data_ptr++;
        break;
    case 32:
        ewk->wu.my_col_code = 104;
        data_ptr++;
        break;
    case 33:
        ewk->wu.my_col_code = 105;
        data_ptr++;
        break;
    case 34:
    case 35:
    case 38:
    case 39:
    case 40:
        ewk->wu.my_col_code = 106;
        data_ptr++;
        break;
    default:
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.my_col_code += wk->my_col_code;
        break;
    }
    ewk->wu.my_family = wk->my_family;
    if (data == 4) {
        ewk->wu.rl_flag = 0;
    } else {
        ewk->wu.rl_flag = wk->rl_flag;
    }
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    if (wk->rl_flag) {
        ewk->wu.xyz[0].disp.pos -= *data_ptr++;
    } else {
        ewk->wu.xyz[0].disp.pos += *data_ptr++;
    }
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos += wk->xyz[1].disp.pos;
    ewk->wu.my_priority = wk->my_priority;
    ewk->wu.my_priority += *data_ptr++;
    ewk->wu.position_z = ewk->wu.my_priority;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    suzi_offset_set(ewk);
    return 0;
}
