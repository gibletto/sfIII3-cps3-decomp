/*
 * EFFM2.C  Effect M2: cat walking and running in a win pose
 *
 * Effect M2 is started from the win-pose routines (win_pl.c, Win_12000) by effect_M2_init.
 * effect_M2_move chooses one of four animations at random and runs one of two behaviours while
 * the game is not paused, drawing through pl_eff_trans_entry:
 * effm2_move (type 0) appears 60 pixels beside the player, plays its animation and then runs off
 * (cat_run_set2) until it leaves the screen range;
 * effm2_move2 (type 1) enters from the screen edge behind the player, walking or running
 * (cat_walk_set / cat_run_set2), stops beside the player and plays its closing animations.
 * Both have a shadow and are released when finished.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "effM0.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "EFFM2.h"



void effect_M2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.old_rno[0] = random_16_com();
        ewk->wu.old_rno[0] &= 3;
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.type) {
                effm2_move2(ewk);
            } else {
                effm2_move(ewk);
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 99:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effm2_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 7;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;
        if (oya_ptr->id) {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + 60;
        } else {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - 60;
        }
        ewk->wu.xyz[1].disp.pos = 7;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        set_char_move_init(&ewk->wu, 0, effm2_char_tbl[ewk->wu.old_rno[0]]);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            if (ewk->wu.old_rno[0] == 2) {
                ewk->wu.rl_flag ^= 1;
            }
            cat_run_set2(ewk);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        if (!range_x_check3(ewk, 64)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }
        break;
    }
}



void effm2_move2(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 dis_w;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 7;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;
        if (oya_ptr->rl_flag) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 48;
            if (oya_ptr->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
                cat_run_set2(ewk);
            } else {
                cat_walk_set(ewk);
            }
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset + 48;
            if (oya_ptr->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
                cat_run_set2(ewk);
            } else {
                cat_walk_set(ewk);
            }
        }
        ewk->wu.xyz[1].disp.pos = 7;
        ewk->wu.my_priority = ewk->wu.position_z = 70;
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        dis_w = oya_ptr->xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;
        if (dis_w < 0) {
            dis_w = -dis_w;
        }
        if (dis_w < 48) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 51);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 28);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        break;
    }
}



s32 effect_M2_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if (data) {
        if (Win_Record[wk->id] <= 3) {
            return;
        }
    } else {
        if (Win_Record[wk->id] <= 2) {
            return;
        }
    }
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 222;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.type = data;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 62;
    return 0;
}
