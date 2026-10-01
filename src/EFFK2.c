/*
 * EFFK2.C  Effects K1 (select timer display) and K2 (bonus-stage car debris)
 *
 * Effect K1 shows the select-screen timer on the left or right of BG1 (sel_pl_char_table): it
 * zooms in, redraws its digits (Setup_Char_Index) whenever Select_Timer changes with a zoom flip,
 * and shrinks away and frees itself when Time_Stop goes negative.
 * Effect K2 is a piece of debris from the bonus-stage car. setup_effK2 spawns the pieces listed
 * in hahen_data for a part's new break level, setup_effK2_sync_bomb adds those of skipped levels
 * when the car collapses, and illegal_setup_effK2 spawns the sets in ill_hahen_data for the final
 * collapse. effect_K2_init creates a piece at the part (bonus_char_table); effect_K2_move applies
 * its offset, flight (k2_kidou), pattern and landing height, then runs one of nine movement types
 * (effK2_main_process): fly and vanish, bounce under gravity (type 8 with a landing sound), wait
 * or stop until the car breaks, and others. disp_effK2 queues the piece at its data's depth.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFF42.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFF13.h"
#include "EFF44.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFC2.h"
#include "EFFK2.h"




void effect_K1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Time_Stop < 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.routine_no[1] = 0;
            sort_push_request(&ewk->wu);
            return;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (--ewk->wu.dir_timer) {
                return;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 5;
            ewk->wu.disp_flag = 1;
            Time_Stop = 0;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;
        case 1:
            if ((ewk->wu.my_mr.size.x -= ewk->wu.mvxy.a[0].real.h) <= 63) {
                ewk->wu.my_mr.size.x = 63;
            }
            if ((ewk->wu.my_mr.size.y -= ewk->wu.mvxy.a[0].real.h) <= 63) {
                ewk->wu.my_mr.size.y = 63;
            }
            if (ewk->wu.my_mr.size.x > 63) {
                break;
            }
            if (ewk->wu.my_mr.size.y > 63) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr_flag = 0;
            break;
        case 2:
            if (Select_Timer != ewk->wu.rl_waza) {
                ewk->wu.rl_waza = Select_Timer;
                Setup_Char_Index(ewk);
                ewk->wu.dir_step += 20;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
            break;
        case 3:
            if (zoom_x_step_check(ewk)) {
                ewk->wu.routine_no[1]++;
                ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                Setup_Char_Index(ewk);
                ewk->wu.dir_step += 20;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
            break;
        default:
            if (zoom_x_step_check(ewk)) {
                ewk->wu.routine_no[1] = 2;
                ewk->wu.my_mr_flag = 0;
            }
            break;
        }
        break;
    default:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.mvxy.a[0].sp = -0x80000;
        case 1:
            if (zoom_x_step_check(ewk)) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
                return;
            }
            break;
        case 2:
            ewk->wu.routine_no[1]++;
            return;
        default:
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
            return;
        }
        break;
    }
    ewk->wu.position_x = bg_w.bgw[1].wxy[0].disp.pos + ewk->wu.routine_no[6];
    ewk->wu.position_y = bg_w.bgw[1].wxy[1].disp.pos + 160;
    sort_push_request(&ewk->wu);
}



s32 effect_K1_init(s16 side) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 201;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.mvxy.a[0].sp = -0x80000;
    ewk->wu.dir_timer = 10;
    ewk->wu.rl_waza = Select_Timer;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = 3;
    ewk->wu.my_family = 2;
    ewk->wu.position_z = 20;
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 63;
    ewk->wu.my_mr.size.y = 63;
    ewk->wu.mvxy.a[0].sp = 0x80000;
    if (side) {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + DE_X[10] - 8;
        ewk->wu.routine_no[6] = -8;
        ewk->wu.dir_step = 29;
        ewk->wu.routine_no[7] = 240;
    } else {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + DE_X[10] + 8;
        ewk->wu.routine_no[6] = 8;
        ewk->wu.dir_step = 29;
        ewk->wu.routine_no[7] = 15;
    }
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x205C;
    return 0;
}



void effect_K2_move(WORK_Other* ewk) {
    DADD* hahen = (DADD*)ewk->wu.target_adrs;
    WORK* mwk = (WORK*)ewk->my_master;
    if (ewk->wu.dir_old == 0 && (mwk->id != ewk->master_work_id || mwk->dir_old != 0)) {
        ewk->wu.dir_old = 1;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = hahen->rno;
        ewk->wu.disp_flag = hahen->init_dsp;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.xyz[0].disp.pos += hahen->hx;
        ewk->wu.xyz[1].disp.pos += hahen->hy;
        ewk->wu.position_z = 24;
        ewk->wu.kage_hy = 0;
        if ((ewk->wu.next_y = hahen->gr1st) == 0) {
            ewk->wu.next_y = (random_16_com() & 7) + 4;
            if (hahen->kage_char) {
                ewk->wu.next_y = -ewk->wu.next_y;
            }
            if ((ewk->wu.xyz[1].disp.pos) < 0) {
                ewk->wu.next_y += ewk->wu.xyz[1].disp.pos;
            }
        }
        setup_move_data_easy(&ewk->wu, k2_kidou[hahen->ispix], 1, 0);
        set_char_move_init(&ewk->wu, 0, (hahen->cix));
        if (hahen->cix == 0x78) {
            setup_demojump((PLW*)ewk->wu.hit_adrs, 1);
        }
        disp_effK2(&ewk->wu, mwk, hahen);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            effK2_main_process[ewk->wu.routine_no[1]](ewk, hahen);
        }
        disp_effK2(&ewk->wu, mwk, hahen);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void disp_effK2(WORK* wk, WORK* mk, DADD* hk) {
    s16 flag;
    s16 hz;
    wk->position_x = wk->xyz[0].disp.pos;
    wk->position_y = wk->xyz[1].disp.pos;
    if (wk->dir_old == 0) {
        flag = hk->pri_use;
        hz = hk->hzd;
        if (wk->mvxy.a[1].real.h >= 0) {
            flag >>= 4;
            hz = hk->hzr;
        }
        flag &= 0xF;
        switch (flag) {
        case 1:
            wk->position_z = hz + 24;
            break;
        case 15:
            wk->position_z = hz + 68;
            break;
        default:
            wk->position_z = hz + mk->position_z;
            break;
        }
    }
    sort_push_request(wk);
}



void effK2_parts_move_type_0(WORK_Other* ewk, DADD* _p1) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.routine_no[2] = 10;
            reset_mvxy_data(&ewk->wu);
        } else if (screen_x_range_check(&ewk->wu)) {
            ewk->wu.routine_no[2] = 20;
            ewk->wu.routine_no[1] = 1;
        }
        break;
    }
}



void effK2_parts_move_type_1(WORK_Other* ewk, DADD* hahen) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        switch (ewk->wu.dm_attlv) {
        case 2:
        case 3:
            char_move(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 10;
            break;
        }
        if (ewk->wu.mvxy.a[1].sp > 0) {
            break;
        }
        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
            if (++ewk->wu.kage_hy > hahen->bau) {
                ewk->wu.routine_no[2] = 10;
            } else {
                ewk->wu.routine_no[2] = 1;
            }
        }
        if (screen_x_range_check(&ewk->wu)) {
            ewk->wu.routine_no[2] = 20;
        }
        break;
    case 1:
        ewk->wu.routine_no[2] = 0;
        ewk->wu.mvxy.a[0].sp /= 2;
        ewk->wu.mvxy.d[0].sp /= 2;
        ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
        ewk->wu.mvxy.a[1].sp /= 3;
        set_next_next_y(&ewk->wu, hahen->kage_char);
        break;
    case 10:
        switch (hahen->doa) {
        case 0:
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[2] = 20;
            break;
        case 1:
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[2] = 15;
            break;
        default:
            ewk->wu.disp_flag = 2;
            ewk->wu.kage_prio = 20;
            ewk->wu.routine_no[2] = 11;
            break;
        }
        break;
    case 11:
        if (--ewk->wu.kage_prio > 0) {
            break;
        }
    case 20:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        break;
    }
}



void effK2_parts_move_type_2(WORK_Other* ewk, DADD* _p1) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
            ewk->wu.routine_no[1] = 0;
            char_move_cmja(&ewk->wu);
            reset_mvxy_data(&ewk->wu);
        } else if (screen_x_range_check(&ewk->wu) != 0) {
            ewk->wu.routine_no[2] = 20;
            ewk->wu.routine_no[1] = 1;
        }
        break;
    }
}



void effK2_parts_move_type_3(WORK_Other* ewk, DADD* hahen) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.mvxy.a[1].sp > 0) {
            break;
        }
        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
            if (++ewk->wu.kage_hy > hahen->bau) {
                ewk->wu.routine_no[2] = 10;
            } else {
                ewk->wu.routine_no[2] = 1;
            }
            ewk->wu.routine_no[1] = 1;
            char_move_cmja(&ewk->wu);
            reset_mvxy_data(&ewk->wu);
        } else if (screen_x_range_check(&ewk->wu)) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.routine_no[2] = 20;
        }
        break;
    }
}



void effK2_parts_move_type_4(WORK_Other* ewk, DADD* arg1) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        if (ewk->wu.dir_old) {
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_prio = 60;
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (--ewk->wu.kage_prio <= 0) {
            char_move_cmja(&ewk->wu);
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



void effK2_parts_move_type_5(WORK_Other* ewk, DADD* arg1) {
    char_move(&ewk->wu);
    if (ewk->wu.dir_old) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[1] = 1;
        ewk->wu.routine_no[2] = 20;
    }
}



void effK2_parts_move_type_6(WORK_Other* ewk, DADD* arg1) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.kage_prio = (random_16_com() & 7) + 28;
        ewk->wu.kage_hy = ewk->wu.kage_prio / 2;
        ewk->wu.routine_no[2]++;
    case 1:
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.kage_hy) {
            ewk->wu.kage_hy--;
        } else {
            ewk->wu.disp_flag = 2;
        }
        if (--ewk->wu.kage_prio < 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        }
        break;
    }
}



void effK2_parts_move_type_7(WORK_Other* ewk, DADD* arg1) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        if (ewk->wu.dir_old) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.routine_no[2] = 10;
        }
        break;
    }
}



void effK2_parts_move_type_8(WORK_Other* ewk, DADD* hahen) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        switch (ewk->wu.dm_attlv) {
        case 2:
        case 3:
            char_move(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 10;
            break;
        }
        if (ewk->wu.mvxy.a[1].sp > 0) {
            break;
        }
        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
            if (++ewk->wu.kage_hy > hahen->bau) {
                ewk->wu.routine_no[2] = 10;
            } else {
                ewk->wu.routine_no[2] = 1;
            }
            sound_effect_request[0x3E4](ewk, 0x3E4);
        }
        if (screen_x_range_check(&ewk->wu)) {
            ewk->wu.routine_no[2] = 20;
        }
        break;
    case 1:
        ewk->wu.routine_no[2] = 0;
        ewk->wu.mvxy.a[0].sp /= 2;
        ewk->wu.mvxy.d[0].sp /= 2;
        ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
        ewk->wu.mvxy.a[1].sp /= 3;
        set_next_next_y(&ewk->wu, hahen->kage_char);
        break;
    case 10:
        switch (hahen->doa) {
        case 0:
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[2] = 20;
            break;
        case 1:
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[2] = 15;
            break;
        default:
            ewk->wu.disp_flag = 2;
            ewk->wu.kage_prio = 20;
            ewk->wu.routine_no[2] = 11;
            break;
        }
        break;
    case 11:
        if (--ewk->wu.kage_prio > 0) {
            break;
        }
    case 20:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        break;
    }
}



void set_next_next_y(WORK* wk, u8 flag) {
    if (flag) {
        wk->next_y -= (random_16_com() & 4) + 2;
    } else {
        wk->next_y += (random_16_com() & 4) + 2;
    }
}



s32 effect_K2_init(WORK_Other* wk, u32* dad) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 202;
    ewk->wu.work_id = 16;
    ewk->wu.type = wk->wu.type;
    ewk->wu.dm_rl = wk->wu.dm_rl;
    ewk->wu.dm_dir = wk->wu.dm_dir;
    ewk->wu.dm_attlv = wk->wu.dm_attlv;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = wk->wu.cgromtype;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->wu.my_priority = wk->wu.position_z;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->wu.id;
    ewk->wu.dir_old = 0;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = dad;
    ewk->wu.hit_adrs = wk->wu.target_adrs;
    ewk->wu.xyz[0].disp.pos = 448;
    ewk->wu.xyz[1].disp.pos = 0;
    *ewk->wu.char_table = bonus_char_table;
    effect_K2_move(ewk);
    return 0;
}



void setup_effK2(WORK* wk) {
    const DADD* dhead;
    s16 i;
    s16 num;
    if (!(num = hahen_data[wk->vital_old][wk->type].kosuu)) {
        return;
    }
    dhead = hahen_data[wk->vital_old][wk->type].dadd;
    for (i = 0; i < num; i++) {
        effect_K2_init((WORK_Other*)wk, (u32*)&dhead[i]);
    }
}



void setup_effK2_sync_bomb(WORK* wk) {
    const DADD* dhead;
    s16 i;
    s16 j;
    s16 num;
    for (j = wk->vital_old + 1; j < 8; j++) {
        if (!(num = hahen_data[j][wk->type].kosuu) || hahen_data[j][wk->type].bomb != 0) {
            continue;
        }
        dhead = hahen_data[j][wk->type].dadd;
        for (i = 0; i < num; i++) {
            if (dhead[i].bomb == 0) {
                effect_K2_init((WORK_Other*)wk, (u32*)&dhead[i]);
            }
        }
    }
}



void illegal_setup_effK2(WORK* wk, s16 ix) {
    const DADD* dhead;
    s16 i;
    s16 num = ill_hahen_data[ix].kosuu;
    dhead = ill_hahen_data[ix].dadd;
    for (i = 0; i < num; i++) {
        effect_K2_init((WORK_Other*)wk, (u32*)&dhead[i]);
    }
}
