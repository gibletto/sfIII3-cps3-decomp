/*
 * EFF41.C  Effect 40 (select-screen zoom object) and effect 41 (super art sign)
 *
 * Effect 40 waits for its delay, appears at double size and shrinks to normal while moving
 * forward in priority; it is placed by direction from eff40_pos_x_tbl.
 * Effect 41 is the sign shown when a super art or EX move is used: it plays the sa_sign_data
 * animation beside the player, flashes the super-art gauge, and on cue creates effect D9 and
 * consumes the gauge (gauge_minus, which also adds to the super-art grade).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFD9.h"
#include "EFFECT.h"
#include "Grade.h"
#include "CHARSET.h"
#include "EFF41.h"



void effect_40_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dir_timer = 1;
        ewk->wu.mvxy.a[0].sp = 0x80000;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 2:
        ewk->wu.my_priority++;
        ewk->wu.position_z++;
        if ((ewk->wu.my_mr.size.x -= ewk->wu.mvxy.a[0].real.h) <= 63) {
            ewk->wu.my_mr.size.x = 63;
        }
        if ((ewk->wu.my_mr.size.y -= ewk->wu.mvxy.a[0].real.h) <= 63) {
            ewk->wu.my_mr.size.y = 63;
        }
        if (ewk->wu.my_mr.size.x <= 63 && ewk->wu.my_mr.size.y <= 63) {
            ewk->wu.routine_no[0]++;
        }
        break;
    default:
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



s32 effect_40_init(s16 dir, s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 40;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2043;
    ewk->wu.my_family = 1;
    ewk->wu.position_z = 40;
    ewk->wu.dir_timer = timer;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_step = dir;
    ewk->wu.char_index = 22;
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 127;
    ewk->wu.my_mr.size.y = 127;
    ewk->wu.xyz[0].disp.pos = eff40_pos_x_tbl[dir] + DE_X[10] + bg_w.bgw[0].position_x + 0xC0;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].position_y + 0x80;
    return 0;
}



void effect_41_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.position_z = 24;
        switch (sa_sign_data[ewk->wu.type][3]) {
        case 1:
            sa_gauge_flash[mwk->wu.id] |= 4;
            break;
        case 2:
            sa_gauge_flash[mwk->wu.id] |= 4;
            break;
        }
        set_char_move_init(&ewk->wu, 0, sa_sign_data[ewk->wu.type][2]);
        goto jump;
    case 1:
        if (ewk->wu.dead_f == 1 || mwk->wu.routine_no[1] != 4) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.hit_stop) {
                ewk->wu.hit_stop--;
            } else {
                char_move(&ewk->wu);
            }
        }
        if (ewk->wu.cg_type == 4) {
            ewk->wu.cg_type = 0;
            effect_D9_init(mwk, 7);
        }
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
    jump:
        eff41_main_process[sa_sign_data[ewk->wu.type][4]](ewk, mwk);
        ewk->wu.cg_type = 0;
        sort_push_request(&ewk->wu);
        break;
    case 2:
        erase_my_shell_ix((WORK*)ewk->my_master, ewk->wu.myself);
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff41_process_00(WORK_Other* ewk, PLW* mwk) {
    if (ewk->wu.cg_type == 1) {
        gauge_minus(ewk, mwk);
    }
    ewk->wu.position_x = mwk->wu.position_x;
    if (mwk->wu.rl_flag) {
        ewk->wu.position_x -= sa_sign_data[ewk->wu.type][0];
    } else {
        ewk->wu.position_x += sa_sign_data[ewk->wu.type][0];
    }
    ewk->wu.position_y = mwk->wu.position_y + sa_sign_data[ewk->wu.type][1];
}



void eff41_process_01(WORK_Other* ewk, PLW* mwk) {
    const s16 (*t)[5];
    switch ((u8)ewk->wu.cg_type) {
    case 1:
        gauge_minus(ewk, mwk);
        ewk->wu.routine_no[1] = 1;
        break;
    case 2:
        ewk->wu.routine_no[1] = 2;
        break;
    }
    t = sa_sign_data;
    switch (ewk->wu.routine_no[1]) {
    case 1:
        ewk->wu.position_x = mwk->wu.position_x;
        ewk->wu.position_y = 0;
        break;
    case 2:
        ewk->wu.position_x = bg_w.bgw[1].position_x + bg_w.pos_offset;
        ewk->wu.position_y = mwk->wu.position_y + t[ewk->wu.type][1];
        break;
    default:
        ewk->wu.position_x = mwk->wu.position_x;
        if (mwk->wu.rl_flag) {
            ewk->wu.position_x -= t[ewk->wu.type][0];
        } else {
            ewk->wu.position_x += t[ewk->wu.type][0];
        }
        ewk->wu.position_y = mwk->wu.position_y + t[ewk->wu.type][1];
        break;
    }
}



void gauge_minus(WORK_Other* ewk, PLW* mwk) {
    switch (sa_sign_data[ewk->wu.type][3]) {
    case 1:
        mwk->sa->saeff_ok = -1;
        grade_add_super_arts(mwk->wu.id, 1);
        break;
    case 2:
        mwk->sa->saeff_mp = -1;
        grade_add_super_arts(mwk->wu.id, 2);
        break;
    }
}
