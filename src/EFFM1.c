/*
 * EFFM1.C  Effect M1: companion figure in a player entry animation
 *
 * Effect M1 (id 221) is created by Appear_37000 (appear.c) during a player's entry. effect_M1_init
 * places it 64 pixels in front of the player with the player's colours (offset for side and for
 * colour 6), using etc3_char_table and a shadow.
 * effect_M1_move runs effm1_move while the game is not paused: the figure plays char 12 until
 * the player sets its cmwk[0] signal, then char 13; when that ends it flags the player
 * (cmwk[0] = 2), turns round and leaves with a computed initial speed for 60 frames, after which
 * the work is released.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFFM1.h"



void effect_M1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, 12);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            effm1_move(ewk);
        }
        pl_eff_trans_entry(ewk);
        break;
    case 99:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effm1_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (oya_ptr->cmwk[0]) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 13);
        } else {
            char_move(&ewk->wu);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            oya_ptr->cmwk[0] = 2;
            ewk->wu.routine_no[1]++;
            set_char_move_init2(&ewk->wu, 0, 0, 3, 0);
            ewk->wu.rl_flag ^= 1;
            ewk->wu.old_rno[0] = 60;
            cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        }
        break;
    case 2:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[0] = 99;
            ewk->wu.disp_flag = 0;
            break;
        }
        char_move(&ewk->wu);
        add_x_sub(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}



s32 effect_M1_init(WORK* wk) {
    s16 ix;
    WORK_Other* ewk;

    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 221;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    if (wk->id) {
        ewk->wu.my_col_code = wk->my_col_code + 2;
    }
    if (Player_Color[wk->id] == 6) {
        ewk->wu.my_col_code = wk->my_col_code + 3;
    }
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[0].disp.pos += wk->rl_flag ? -64 : 64;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 2;
    ewk->wu.position_z = wk->my_priority - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    *ewk->wu.char_table = etc3_char_table;
    ewk->wu.sync_suzi = 0;
    if (wk->rl_flag) {
        ewk->wu.old_rno[1] = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 32;
    } else {
        s16 v = bg_w.pos_offset + bg_w.bgw[1].wxy[0].disp.pos;
        v += 32;
        ewk->wu.old_rno[1] = v;
    }
    suzi_offset_set(ewk);
    return 0;
}
