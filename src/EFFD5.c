/*
 * EFFD5.C  Effects D5 and D6: the thrown rose and its scattering petals
 *
 * Effect D5 is a rose thrown by a player (only one per player; my_rose_live_check). effect_D5_init
 * places it in front of the player and sets cmwk[0]; effect_D5_move aims it at the opponent with
 * cal_speeds (range_isp_table / range_time_table) and flies it as a hit-capable object (pattern
 * 0x7C) with a shadow. effD5_main_process handles hits: struck by the opponent it bursts into
 * petals, is knocked back (or reflected by certain hits), and on hitting it plays sound 0x10B and
 * scatters petals by the attack's direction.
 * Effect D6 is one petal: setup_hana_extra spawns num_of_hana[] petals with random directions and
 * speeds (hana_dir_hosei, hana_speed_hosei, hana_delta_hosei); effect_D6_move slows each petal
 * to a stop with add_pos_dir_064, lets it hang for 24 frames, blinks it for 12 and frees it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "HITCHECK.h"
#include "PLS01.h"
#include "CHARID.h"
#include "CHARSET.h"
#include "EFFD5.h"



void effect_D5_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 11;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_code = ewk->wu.dm_vital;
        *ewk->wu.char_table = plef_char_table;
        ewk->wu.type = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        cal_speeds(ewk, (PLW*)ewk->my_master, (PLW*)ewk->wu.target_adrs);
        add_mvxy_speed(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, 0x7C);
        sort_push_request(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (sa_stop_check() == 0) {
            if (ewk->wu.hit_stop < 0) {
                ewk->wu.hit_stop = -ewk->wu.hit_stop;
            }
            if (EXE_flag == 0 && Game_pause == 0) {
                effD5_main_process(ewk);
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.disp_flag = 0;
                    break;
                }
            }
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            if (ewk->wu.type) {
                hit_push_request(&ewk->wu);
            }
        }
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



void effD5_main_process(WORK_Other* ewk) {
    s16 dsst;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.xyz[1].disp.pos < 0) {
            ewk->wu.xyz[1].disp.pos = 0;
            char_move_cmja(&ewk->wu);
            ewk->wu.mvxy.a[0].sp = ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = ewk->wu.mvxy.d[1].sp = 0;
        }
        break;
    case 1:
        if (ewk->wu.hf.hit.player) {
            if (ewk->wu.hf.hit.player & 0x33) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.a[0].sp = 0;
                ewk->wu.mvxy.a[1].sp = 0;
                ewk->wu.direction = 2;
                if (ewk->wu.rl_flag) {
                    ewk->wu.direction = cal_attdir_flip(ewk->wu.direction);
                }
                setup_hana_extra(&ewk->wu, 0, 8);
            } else if (ewk->wu.hf.hit.player & 0xC0) {
                ewk->wu.routine_no[1] = 0;
                ewk->refrected = 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->wu.mvxy.a[0].sp = 0x60000;
                ewk->wu.mvxy.d[0].sp = -0x3000;
                ewk->wu.mvxy.a[1].sp /= 3;
                ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
                ewk->wu.hit_stop = 4;
                ewk->wu.direction = 0xD;
                if (ewk->wu.rl_flag) {
                    ewk->wu.direction = cal_attdir_flip(ewk->wu.direction);
                }
                setup_hana_extra(&ewk->wu, 1, 0x18);
            }
        } else {
            sound_effect_request[0x10B](ewk, 0x10B);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.type = 0;
            ewk->wu.kage_flag = 0;
            ewk->wu.dir_timer = 16;
            ewk->wu.hit_stop = 2;
            ewk->wu.direction = ewk->wu.dm_dir;
            dsst = 3;
            if (!(ewk->wu.dm_kind_of_waza & 0xF8)) {
                dsst = (ewk->wu.dm_kind_of_waza / 2) & 3;
            }
            setup_hana_extra(&ewk->wu, dm_sp_sel_tbl[dsst][0], dm_sp_sel_tbl[dsst][1]);
        }
        ewk->wu.hf.hit_flag = 0;
        break;
    case 2:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        }
        break;
    }
}



void cal_speeds(WORK_Other* ewk, PLW* _p1, PLW* twk) {
    s16 tx = twk->wu.position_x;
    s16 rix = 0;
    if (ewk->wu.rl_flag) {
        tx -= 16;
        if (tx > ewk->wu.position_x) {
            rix = (tx - ewk->wu.position_x) / 32;
        } else {
            tx = ewk->wu.position_x + 16;
        }
    } else {
        tx += 16;
        if (tx < ewk->wu.position_x) {
            rix = (ewk->wu.position_x - tx) / 32;
        } else {
            tx = ewk->wu.position_x - 16;
        }
    }
    ewk->wu.mvxy.a[0].sp = 0;
    ewk->wu.mvxy.a[1].real.h = range_isp_table[rix];
    cal_delta_speed(&ewk->wu, range_time_table[rix], tx, 0, 2, 1);
    ewk->wu.mvxy.kop[0] = 1;
    if (ewk->wu.rl_flag == 0) {
        ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
    }
}



s32 effect_D5_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (my_rose_live_check((PLW*)wk) != 0) {
        return -1;
    }
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 135;
    ewk->wu.work_id = 2;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.dm_vital = wk->my_col_code + 6;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = wk->target_adrs;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    if (ewk->wu.rl_flag) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x + 28;
    } else {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x - 28;
    }
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = wk->position_y + 124;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = 28;
    wk->cmwk[0] = 1;
    return 0;
}



s32 my_rose_live_check(PLW* wk) {
    WORK_Other* twk;
    s16 ix;
    if (wk->player_number != My_char[wk->wu.id]) {
        return 1;
    }
    ix = search_effect_index(3, 0, 0x87);
    if (ix == -1) {
        return 0;
    }
    twk = (WORK_Other*)frw[ix];
    if (twk->master_id == wk->wu.id) {
        return 1;
    }
    ix = search_effect_index(3, 1, 0x87);
    if (ix == -1) {
        return 0;
    }
    twk = (WORK_Other*)frw[ix];
    if (twk->master_id == wk->wu.id) {
        return 1;
    }
    return 0;
}



void effect_D6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        add_pos_dir_064(&ewk->wu, ewk->wu.dir_old << 1);
        set_char_move_init(&ewk->wu, 0, 0x7D);
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (!(sa_stop_check() == 0)) {
        } else {
            if (EXE_flag == 0 && Game_pause == 0) {
                switch (ewk->wu.routine_no[1]) {
                case 0:
                    ewk->wu.dir_old += ewk->wu.dir_step;
                    if (ewk->wu.dir_old < 0) {
                        ewk->wu.dir_old = 0;
                        ewk->wu.routine_no[1]++;
                        ewk->wu.dir_timer = 24;
                    }
                    add_pos_dir_064(&ewk->wu, ewk->wu.dir_old);
                    char_move(&ewk->wu);
                    break;
                case 1:
                    char_move(&ewk->wu);
                    if (--ewk->wu.dir_timer <= 0) {
                        ewk->wu.routine_no[1]++;
                        ewk->wu.disp_flag = 2;
                        ewk->wu.dir_timer = 12;
                    }
                    break;
                default:
                    char_move(&ewk->wu);
                    if (--ewk->wu.dir_timer <= 0) {
                        ewk->wu.routine_no[0]++;
                        ewk->wu.disp_flag = 0;
                    }
                    break;
                }
            }
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        }
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_D6_init(WORK_Other* wk, s16 dr, s16 sp, s16 dl, s16 acc) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 136;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->wu.cgromtype = 1;
    ewk->wu.direction = dr;
    ewk->wu.dir_old = (sp * acc) / 16;
    ewk->wu.dir_step = (dl * acc) / 16;
    ewk->master_id = ewk->wu.blink_timing = wk->master_id;
    ewk->wu.xyz[0].disp.pos = wk->wu.position_x;
    ewk->wu.xyz[1].disp.pos = wk->wu.position_y;
    ewk->wu.position_z = wk->wu.position_z + 1;
    *ewk->wu.char_table = plef_char_table;
    return 0;
}



void setup_hana_extra(WORK* wk, s16 num, s16 acc) {
    s16 i;
    s16 way = wk->direction * 4;
    s16 rnd_00 = random_16_com() & 3;
    s16 rnd_01;
    for (i = 0; i < num_of_hana[num]; i++) {
        rnd_01 = random_16_com() & 3;
        effect_D6_init((WORK_Other*)wk,
                       way + hana_dir_hosei[rnd_00][i] & 0x3F,
                       hana_speed_hosei[rnd_01][i],
                       hana_delta_hosei[rnd_01][i],
                       acc);
    }
}
