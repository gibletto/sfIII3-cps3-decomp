/*
 * EFFK4.C  Effect K4: debris pieces scattered from a hit mark
 *
 * Effect K4 (id 204) is a small flying fragment thrown out from the hit mark of a struck object.
 * effect_K4_init copies the parent's family, colour and damage level and the struck work's hit
 * mark position; the pieces use bonus_char_table graphics.
 * effect_K4_move picks a random start offset and a random launch speed and lifetime from the
 * effK4_isp_table / effK4_isp_x_hosei / effK4_isp_y_hosei / effK4_life_time tables by damage
 * level, then flies under gravity, blinks for the second half of its life and frees itself.
 * setup_effK4 is the hook called from the bonus-stage object routines (EFFC2, EFFC3); it is an
 * empty routine in this build.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFK4.h"



void effect_K4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        get_init_position_effK4(&ewk->wu);
        get_init_speed_and_timer_effK4(&ewk->wu);
        ewk->wu.position_z = 24;
        set_char_move_init(&ewk->wu, 0, effK4_char_sel_table[ewk->wu.dm_attlv][random_16_com()]);
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
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
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(ewk);
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



void get_init_position_effK4(WORK* wk) {
    s16 xhs;
    wk->xyz[0].disp.pos = wk->hit_mark_x;
    wk->xyz[1].disp.pos = wk->hit_mark_y;
    xhs = 32 - (random_32_com() * 2);
    wk->xyz[0].disp.pos += xhs;
    wk->xyz[1].disp.pos += 8 - random_16_com();
    wk->position_z = 24;
    wk->type = (xhs < 0) * 2;
}



void get_init_speed_and_timer_effK4(WORK* wk) {
    s16 data[4];
    s16 ix;
    ix = wk->type + (random_16_com() & 1);
    data[0] = effK4_isp_table[wk->dm_attlv][ix][0];
    data[2] = effK4_isp_table[wk->dm_attlv][ix][1];
    data[1] = 0;
    data[3] = -96;
    ix = random_16_com() & 7;
    data[0] += effK4_isp_x_hosei[wk->dm_attlv][ix];
    ix = random_16_com() & 7;
    data[2] += effK4_isp_y_hosei[wk->dm_attlv][ix];
    setup_move_data_easy(wk, &data[0], 1, 0);
    wk->kage_prio = effK4_life_time[wk->dm_attlv] + (random_16_com() & 7);
    wk->kage_hy = wk->kage_prio / 2;
}



s32 effect_K4_init(WORK_Other* wk, WORK* dad) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 204;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = wk->wu.cgromtype;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = (u32*)dad;
    ewk->wu.dm_dir = wk->wu.dm_dir;
    ewk->wu.dm_attlv = wk->wu.dm_attlv;
    ewk->wu.hit_mark_x = dad->hit_mark_x;
    ewk->wu.hit_mark_y = dad->hit_mark_y;
    ewk->wu.hit_mark_z = dad->hit_mark_z;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    *ewk->wu.char_table = bonus_char_table;
    return 0;
}



void setup_effK4(void)
{
  return;
}
