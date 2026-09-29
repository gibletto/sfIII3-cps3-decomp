/*
 * EFF83.C  Effect 83: win-pose companion that runs in to the winner (second variant)
 *
 * The twin of effect 82, spawned by Win_07000 (win_pl.c) for character 7's final-round win pose
 * when the win pattern chosen is above 3. effect_83_init starts the object off-screen on the
 * winner's facing side; effect_83_move runs it toward the winner with a shadow, requests a voice
 * when it is within 112 dots, then switches to pattern 35 and sets cmwk[1] = 9 in the winner's
 * work to release the winner's pose. Uses etc2_char_table index 34.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "SE.h"
#include "bg_sub.h"
#include "EFF83.h"



void effect_83_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 50;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos, 2, 2);
        break;
    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;
            add_x_sub(ewk);
            add_y_sub(ewk);
            work = ewk->wu.xyz[0].disp.pos - oya_ptr->xyz[0].disp.pos;
            if (work < 0) {
                work = -work;
            }
            if (work <= 112) {
                ewk->wu.routine_no[0]++;
                Sound_SE((ewk->master_id * 768) + 350);
                char_move_z(&ewk->wu);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                oya_ptr->cmwk[1] = 9;
                set_char_move_init(&ewk->wu, 0, 35);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}



s32 effect_83_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 83;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }
        ewk->wu.old_rno[2] = wk->xyz[0].disp.pos + 56;
    } else {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
        }
        ewk->wu.old_rno[2] = wk->xyz[0].disp.pos - 56;
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.char_index = 34;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    return 0;
}
