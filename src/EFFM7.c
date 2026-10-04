/*
 * EFFM7.C  Effects M7, M8 (win-pose extras) and fight player control
 *
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
#include "plcntset_2.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "HITCHECK.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "spgauge.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "EFFM7.h"



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



