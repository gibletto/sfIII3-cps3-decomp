/*
 * EFFM7.C  Effects M6, M7, M8 (win-pose extras) and fight player control
 *
 * effect_M6_init (id 226, from effM5) creates an object behind a parent effect, copying its
 * position, facing and colour, with char 105 of etc_char_table.
 * Effect M7 (id 227): effect_M7_init (from win_pl) creates six objects around the losing opponent
 * from a position table; effm7_move places each relative to the opponent, waits, animates,
 * jumps up and flies off horizontally until off screen.
 * Effect M8 (id 228): running animals, either a random group of five from off screen or a single
 * one running in from the side (effect_M8_move, effm8_move_win, don_run_sub_m8).
 * Player_control is the per-frame player control of a fight, called from Game2_1 (Game_Main) and
 * end_sub: it runs the player_main_process phase, body touch and push-back resolution, quake and
 * hit requests, stores the 48-entry afterimage (zanzou) history, draws both players and runs the
 * super-art and stun gauges. plcnt_init is player-control routine 0: it runs the init routine
 * for the current appear_type from appear_initalize and moves both player works.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLCNTSET.h"
#include "PLCNTDAT.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "HITCHECK.h"
#include "bg_sub.h"
#include "CHARSET.h"
#include "spgauge.h"
#include "sc_sub.h"
#include "EFFM7.h"



s32 effect_M6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 226;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->my_master = (u32*)oya;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 105;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = oya->wu.my_priority - 1;
    ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
    ewk->wu.xyz[1].cal = oya->wu.xyz[1].cal;
    ewk->wu.rl_flag = oya->wu.rl_flag;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code;
    suzi_offset_set(ewk);
}



void effect_M7_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            effm7_move(ewk);
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effm7_move(WORK_Other* ewk) {
    s16 ix;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ix = ewk->master_id ^ 1;
        ewk->wu.rl_flag ^= plw[ix].wu.rl_flag;
        if (plw[ix].wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = plw[ix].wu.xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;
        } else {
            ewk->wu.xyz[0].disp.pos = plw[ix].wu.xyz[0].disp.pos + ewk->wu.xyz[0].disp.pos;
        }
        set_char_move_init(&ewk->wu, 0, 0);
        break;
    case 1:
        ewk->wu.old_rno[1]--;
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 1, 108);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0x78000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case 4:
        add_y_sub(ewk);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.d[0].sp = 0;
            if (ewk->wu.rl_flag) {
                ewk->wu.mvxy.a[0].sp = 0x80000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0x80000;
            }
            ewk->wu.mvxy.a[1].sp = -0x8000;
            ewk->wu.mvxy.d[1].sp = 0x4000;
        }
        break;
    case 5:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (range_x_check3(ewk, 208) == 0) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[1]++;
        }
        break;
    }
}



s32 effect_M7_init(PLW* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = effm7_data_tbl;
    s16 em_id = oya->wu.id ^ 1;
    for (i = 0; i < 6; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 227;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->my_master = (u32*)oya;
        ewk->master_id = oya->wu.id;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = oya->wu.my_col_code;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].cal = plw[em_id].wu.xyz[1].cal;
        ewk->wu.xyz[1].disp.pos += *(s16*)data_ptr++;
        ewk->wu.position_z = plw[em_id].wu.my_priority;
        ewk->wu.position_z += *(s16*)data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.rl_flag = *data_ptr++;
        ewk->wu.kage_char = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.char_table[0] = *oya->wu.char_table;
        ewk->wu.char_table[1] = etc_char_table;
        ewk->wu.char_index = 0;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 6;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = ewk->wu.position_z + 5;
    }
}



void effect_M8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.type) {
                effm8_move_win(ewk);
            } else {
                effm8_move_app(ewk);
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effm8_move_app(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 60;
        break;
    case 1:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 0x34);
        }
        break;
    case 3:
        don_run_sub_m8(ewk);
        break;
    }
}



void don_run_sub_m8(WORK_Other* ewk) {
    char_move(&ewk->wu);
    add_x_sub(ewk);
    if (!range_x_check3(ewk, 56)) {
        ewk->wu.routine_no[1]++;
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
    }
}



void effm8_move_win(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 1:
        don_run_sub_m8(ewk);
        break;
    }
}



s32 effect_M8_init(WORK* oya, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 work;
    if (data) {
        work = random_16_com();
        work = effm8_random_tbl[work];
        if (!work) {
            return 0;
        }
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[(ix)];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 228;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->my_master = (u32*)oya;
        ewk->master_id = oya->id;
        ewk->wu.type = 1;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = oya->my_col_code;
        ewk->wu.rl_flag = oya->rl_flag;
        if (oya->rl_flag) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].position_x - 48;
            ewk->wu.mvxy.a[0].sp = 0x48000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset + 48;
            ewk->wu.mvxy.a[0].sp = -0x48000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        ewk->wu.xyz[1].cal = oya->xyz[1].cal;
        ewk->wu.xyz[1].disp.pos -= 5;
        ewk->wu.position_z = oya->my_priority;
        ewk->wu.position_z -= 2;
        ewk->wu.my_priority = ewk->wu.position_z;
        *ewk->wu.char_table = etc2_char_table;
        ewk->wu.char_index = 52;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -2;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 8;
        ewk->wu.old_rno[0] = 0;
        for (i = 0; i < 4; i++) {
            if ((ix = pull_effect_work(3)) == -1) {
                return -1;
            }
            ewk = (WORK_Other*)frw[(ix)];
            ewk->wu.be_flag = 1;
            ewk->wu.id = 228;
            ewk->wu.work_id = 16;
            ewk->wu.cgromtype = 1;
            ewk->wu.disp_flag = 0;
            ewk->my_master = (u32*)oya;
            ewk->master_id = oya->id;
            ewk->wu.type = 1;
            ewk->wu.my_family = 2;
            ewk->wu.my_col_mode = 0x4200;
            ewk->wu.my_col_code = oya->my_col_code;
            ewk->wu.rl_flag = oya->rl_flag;
            if (oya->rl_flag) {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].position_x - 48;
                ewk->wu.mvxy.a[0].sp = 0x48000;
                ewk->wu.mvxy.d[0].sp = 0;
            } else {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset + 48;
                ewk->wu.mvxy.a[0].sp = -0x48000;
                ewk->wu.mvxy.d[0].sp = 0;
            }
            ewk->wu.xyz[1].cal = oya->xyz[1].cal;
            ewk->wu.xyz[1].disp.pos -= 5;
            ewk->wu.position_z = oya->my_priority;
            ewk->wu.position_z -= 2;
            ewk->wu.my_priority = ewk->wu.position_z;
            *ewk->wu.char_table = etc2_char_table;
            ewk->wu.char_index = 55;
            ewk->wu.kage_flag = 1;
            ewk->wu.kage_hx = -2;
            ewk->wu.kage_hy = 0;
            ewk->wu.kage_prio = 71;
            ewk->wu.kage_char = 8;
            ewk->wu.old_rno[0] = effm8_timer_tbl[i];
        }
    } else {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[(ix)];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 228;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->my_master = (u32*)oya;
        ewk->master_id = oya->id;
        ewk->wu.type = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = oya->my_col_code;
        if (oya->id) {
            ewk->wu.xyz[0].disp.pos = 648;
            ewk->wu.mvxy.a[0].sp = 0x48000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = 376;
            ewk->wu.mvxy.a[0].sp = -0x48000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        ewk->wu.xyz[1].cal = oya->xyz[1].cal;
        ewk->wu.position_z = oya->my_priority;
        ewk->wu.position_z++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.rl_flag = oya->rl_flag ^ 1;
        *ewk->wu.char_table = etc2_char_table;
        ewk->wu.char_index = 54;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -2;
        ewk->wu.kage_hy = 4;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 8;
    }
    return 0;
}



void Player_control(void) {
    s32 i;
    s32 j;
    pl_eff_disp_stop = 0;
    if (((pcon_rno[0] + pcon_rno[1]) == 0) || (!Game_pause && !EXE_flag)) {
        pcon_timer++;
        pcon_timer &= 0x7FFF;
        set_scrrrl();
        player_main_process[pcon_rno[0]]();
        check_body_touch();
        check_damage_hosei();
        set_quake(&plw[0]);
        set_quake(&plw[1]);
        if (plw[0].zuru_flag == 0 && plw[0].zettai_muteki_flag == 0) {
            hit_push_request(&plw[0].wu);
        }
        if (plw[1].zuru_flag == 0 && plw[1].zettai_muteki_flag == 0) {
            hit_push_request(&plw[1].wu);
        }
        add_next_position(&plw[0]);
        add_next_position(&plw[1]);
        check_cg_zoom();
    }
    for (i = 47; i > 0; i--) {
        j = i - 1;
        zanzou_table[0][i] = zanzou_table[0][j];
        zanzou_table[1][i] = zanzou_table[1][j];
        continue;
    }
    zanzou_table[0]->pos_x = plw[0].wu.position_x;
    zanzou_table[0]->pos_y = plw[0].wu.position_y;
    zanzou_table[0]->pos_z = plw[0].wu.position_z;
    zanzou_table[0]->cg_num = plw[0].wu.cg_number;
    zanzou_table[0]->renew = plw[0].wu.renew_attack;
    zanzou_table[0]->hit_ix = plw[0].wu.cg_hit_ix;
    zanzou_table[0]->flip = plw[0].wu.rl_flag;
    zanzou_table[0]->cg_flp = plw[0].wu.cg_flip;
    zanzou_table[0]->kowaza = plw[0].wu.kind_of_waza;
    zanzou_table[1]->pos_x = plw[1].wu.position_x;
    zanzou_table[1]->pos_y = plw[1].wu.position_y;
    zanzou_table[1]->pos_z = plw[1].wu.position_z;
    zanzou_table[1]->cg_num = plw[1].wu.cg_number;
    zanzou_table[1]->renew = plw[1].wu.renew_attack;
    zanzou_table[1]->hit_ix = plw[1].wu.cg_hit_ix;
    zanzou_table[1]->flip = plw[1].wu.rl_flag;
    zanzou_table[1]->cg_flp = plw[1].wu.cg_flip;
    zanzou_table[1]->kowaza = plw[1].wu.kind_of_waza;
    if (pl_eff_disp_stop == 0) {
        sort_push_request((WORK_Other*)&plw[0]);
        sort_push_request((WORK_Other*)&plw[1]);
    }
    if (Combo_Demo_Flag == 0) {
        spgauge_cont_main();
        stngauge_cont_main();
    }
}


void plcnt_init(void) {
    appear_initalize[appear_type]();
    move_player_work();
}
