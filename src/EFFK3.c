/*
 * EFFK3.C  Effect K3: shards from the bonus-stage car
 *
 * setup_effK3 is called by the car parts (EFFC3.C): when part 3 reaches break level 3 or 4 it
 * spawns numof_effK3[] K3 works for the attack strength. effect_K3_init copies the part's colour,
 * attack level and owner fields (bonus_char_table). set_init_posspeed_effK3 places each shard at
 * random around (520, 96) and gives it a random flight from effK3_isp_table and the
 * effK3_isp_x_hosei / _y_hosei spreads. effect_K3_move plays pattern 0x71 or 0x72 while it flies,
 * blinks for the second half of its life (effK3_life_time) and then frees itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFK3.h"



void effect_K3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        set_init_posspeed_effK3(&ewk->wu);
        ewk->wu.position_z = 24;
        set_char_move_init(&ewk->wu, 0, (random_16_com() & 1) + 0x71);
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
        sort_push_request(&ewk->wu);
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



void set_init_posspeed_effK3(WORK* wk) {
    s16 data[4];
    s16 ix;
    s16 flag;
    wk->xyz[0].disp.pos = 520;
    wk->xyz[1].disp.pos = 96;
    flag = (random_32_com() * 2) - 32;
    wk->xyz[0].disp.pos += flag;
    wk->xyz[1].disp.pos += random_16_com();
    if (flag < 0) {
        flag = 2;
    } else {
        flag = 0;
    }
    ix = random_16_com() & 1;
    data[0] = effK3_isp_table[wk->dm_attlv][flag + ix][0];
    data[2] = effK3_isp_table[wk->dm_attlv][flag + ix][1];
    data[1] = 0;
    data[3] = -96;
    ix = random_16_com() & 7;
    data[0] += effK3_isp_x_hosei[wk->dm_attlv][ix];
    ix = random_16_com() & 7;
    data[2] += effK3_isp_y_hosei[wk->dm_attlv][ix];
    setup_move_data_easy(wk, &data[0], 1, 0);
    wk->kage_prio = effK3_life_time[wk->dm_attlv] + (random_16_com() & 3);
    wk->kage_hy = wk->kage_prio / 2;
}



s32 effect_K3_init(WORK_Other* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 203;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = wk->wu.cgromtype;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->wu.dm_dir = wk->wu.dm_dir;
    ewk->wu.dm_attlv = wk->wu.dm_attlv;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    *ewk->wu.char_table = bonus_char_table;
    return 0;
}



s32 setup_effK3(WORK* wk) {
    s16 i;
    if (wk->type != 3) {
        return 0;
    }
    if (wk->vital_old < 3 || wk->vital_old > 4) {
        return 0;
    }
    for (i = 0; i < numof_effK3[wk->dm_attlv]; i++) {
        effect_K3_init((WORK_Other*)wk);
    }
    return 1;
}
