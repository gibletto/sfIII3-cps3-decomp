/*
 * EFFB4.C  Effect B3 (round / FIGHT display) and effect B4 (ball hit spark)
 *
 * Effect B3 is the display child of the round-call effect B2 (EFFB2.C). effect_B3_move
 * follows its parent's state each frame and dispatches to the display routines:
 *   round_move_init  shows the ROUND pattern at the parent's zoom size
 *   round_move       requests the round-number call (or the final-round call) and places it
 *   fight_move       starts the FIGHT pattern, growing with the parent's zoom
 *   fight_col_move   copies the parent's flash colour
 *   fight_vanish     plays the vanish pattern, then sets rf_b2_flag
 * effect_B3_init also spawns effect B9. Effect B4 (spawned by EFF09.c when the entrance ball
 * hits a player) plays a random mark from s_mark_tbl at its parent's position, then frees itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "effb9.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "CHARSET.h"
#include "SE.h"
#include "bg_sub.h"
#include "EFFB4.h"



void effect_B3_move(WORK_Other* ewk) {
    effb3_oya = (WORK_Other*)ewk->my_master;
    if (ewk->wu.old_rno[1] != effb3_oya->wu.routine_no[0]) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
    }
    ewk->wu.old_rno[1] = effb3_oya->wu.routine_no[0];
    switch (effb3_oya->wu.routine_no[0]) {
    case 1:
        round_move_init(ewk);
        break;
    case 2:
        round_move(ewk);
        break;
    case 3:
    case 5:
    case 6:
        ewk->wu.my_mr.size.x = effb3_oya->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = effb3_oya->wu.my_mr.size.y;
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        fight_move(ewk);
        break;
    case 7:
        fight_col_move(ewk);
        break;
    case 8:
        fight_vanish(ewk);
        break;
    case 9:
    case 10:
    case 99:
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void round_move_init(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.my_mr_flag = ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 2, 1, 0);
    case 1:
        ewk->wu.my_mr.size.x = effb3_oya->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = effb3_oya->wu.my_mr.size.y;
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void round_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        if (ewk->wu.hit_quake) {
            Sound_SE(138);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 96;
            ewk->wu.xyz[1].disp.pos = 144;
            set_char_move_init2(&ewk->wu, 0, 2, 4, 0);
        } else {
            Sound_SE(effb3_oya->wu.dir_old);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 32;
            set_char_move_init2(&ewk->wu, 0, 2, 2, 0);
        }
    case 1:
        ewk->wu.my_mr.size.x = effb3_oya->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = effb3_oya->wu.my_mr.size.y;
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void fight_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        set_char_move_init2(&ewk->wu, 0, 2, 5, 0);
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
        ewk->wu.xyz[1].disp.pos = 144;
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        ewk->wu.my_mr.size.x = effb3_oya->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = effb3_oya->wu.my_mr.size.y;
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void fight_col_move(WORK_Other* ewk) {
    ewk->wu.extra_col = effb3_oya->wu.extra_col;
    disp_pos_trans_entry5(ewk);
}



void fight_vanish(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        set_char_move_init2(&ewk->wu, 0, 4, 1, 0);
        disp_pos_trans_entry5(ewk);
        ewk->wu.my_col_code = 0x1E0;
        ewk->wu.extra_col = 0;
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        rf_b2_flag = 1;
        disp_pos_trans_entry5(ewk);
        break;
    }
}



s32 effect_B3_init(WORK_Other* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 113;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x1E0;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.xyz[1].cal = 0x780000;
    ewk->wu.xyz[0].disp.low = 0;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    ewk->wu.old_rno[1] = 0;
    if (wk->wu.type) {
        ewk->wu.hit_quake = 1;
    } else {
        ewk->wu.hit_quake = 0;
    }
    effect_B9_init(wk);
    return 0;
}



void effect_B4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = random_16_com();
        ewk->wu.old_rno[0] &= 0x1F;
        ewk->wu.char_index += s_mark_tbl[ewk->wu.old_rno[0]];
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_B4_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 114;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)oya;
    ewk->master_id = 0;
    ewk->wu.my_col_mode = 0;
    ewk->wu.my_col_code = 0x20;
    ewk->wu.my_family = 2;
    ewk->wu.position_z = oya->wu.position_z - 1;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.char_index = 34;
    ewk->wu.sync_suzi = 0;
    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = oya->wu.xyz[1].disp.pos;
    suzi_offset_set(ewk);
    return 0;
}
