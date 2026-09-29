/*
 * EFFL7.C  Companion that crosses the screen (effect L7)
 *
 * A figure that runs in from off screen next to a player, performs, and runs off again.
 * effect_L7_init only starts it for the player's own character when the player's 0x1000
 * switch is held and poison_flag is clear; it sets poison_flag while the figure is out and
 * picks its routine at random from effl7_data_tbl. effl7_move leaps it to a point beside
 * the player, plays the chosen animation, turns and runs off until out of range.
 * effect_L7_move stops early on Suicide and clears the flag when it ends.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "effL7.h"



void effect_L7_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    if (Suicide[0]) {
        ewk->wu.routine_no[0] = 99;
        poison_flag[oya_ptr->id] = 0;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((!EXE_flag) && (!Game_pause)) {
            effl7_move(ewk);
        }
        pl_eff_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.routine_no[0] += 1;
        poison_flag[oya_ptr->id] = 0;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effl7_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 80;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1] += 1;
            set_char_move_init(&ewk->wu, 0, 1);
        }
        break;
    default:
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
            set_char_move_init(&ewk->wu, 1, ewk->wu.old_rno[2]);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.rl_flag ^= 1;
        }
        break;
    case 4:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
            ((void (*)(WORK*, s16, s16, s16))set_char_move_init2)(&ewk->wu, 0, 0, 3);
            if (ewk->wu.rl_flag) {
                ewk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0x20000;
            }
            ewk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 5:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        if (range_x_check3((WORK*)ewk, 64) == 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.kage_flag = 0;
        }
        break;
    case 6:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.routine_no[0] += 1;
        break;
    }
}



s32 effect_L7_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    s16 kind_w;
    if ((wk->work_id == 1) && (((PLW*)wk)->player_number != My_char[wk->id])) {
        return;
    }
    if (poison_flag[wk->id]) {
        return;
    }
    if (wk->id) {
        if (!(p2sw_0 & 0x1000)) {
            return;
        }
    } else if (!(p1sw_0 & 0x1000)) {
        return;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 217;
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
    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 32;
    } else {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 32;
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = 28;
    ewk->wu.position_z = 28;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_table[1] = etc_char_table;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    kind_w = random_16_com();
    ewk->wu.old_rno[2] = effl7_data_tbl[kind_w];
    poison_flag[wk->id] = 1;
    return 0;
}
