/*
 * EFFM7.C  Effect M7: entrance extras
 *
 * effect_M7_init (from the entrance Appear_41000 in appear.c) creates six objects beside the
 * opponent from effm7_data_tbl, with a shadow, using the player's character table;
 * effm7_move places each relative to the opponent, waits, animates, jumps up and flies off
 * horizontally until off screen.
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

/* routine_no[0] */
#define R0_MOVE         0       /* run the extra's routine */
#define R0_KILL         99      /* (default) put the work back */

/* routine_no[1] */
#define R1_INIT         0       /* place beside the opponent */
#define R1_WAIT         1       /* wait to start */
#define R1_ANIM         2       /* animate for a while */
#define R1_TAKEOFF      3       /* take-off animation */
#define R1_JUMP         4       /* jump up */
#define R1_FLY          5       /* fly off the screen */



void effect_M7_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_MOVE:
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
    case R1_INIT:
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
    case R1_WAIT:
        ewk->wu.old_rno[1]--;
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case R1_ANIM:
        char_move(&ewk->wu);
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 1, 108);
        }
        break;
    case R1_TAKEOFF:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0x78000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case R1_JUMP:
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
    case R1_FLY:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (range_x_check3(&ewk->wu, 208) == 0) {
            ewk->wu.routine_no[0] = R0_KILL;
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



