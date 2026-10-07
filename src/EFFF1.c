/*
 * EFFF1.C  Effects F1 and F2: another-BG switch control and ending falling objects
 *
 * Effect F1 is started from character move data (CHARMOVE.c) to switch a player's another-BG.
 * effect_F1_move loads its type, duration and end conditions from effF1_data_tbl (mirrored with
 * effF1_rl_type_tbl when the player faces left), sets another_bg[] for the player and clears it
 * again when a condition is met: the timer runs out, the player's or opponent's state or move
 * changes, the super art ends, dramatic-battle mode is on, or the player's shell is gone.
 * effect_F1_init itself is an empty stub.
 * Effect F2 (effect_F2_init, from end_12.c) creates ten ending objects from efff2_data_tbl.
 * Each waits a random time (efff2_timer_tbl), plays its pattern until frame type 9, then falls
 * with the speeds in efff2_sp_tbl1 and starts again from its home position; all are freed when
 * the ending scene moves on.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFF1.h"



void effect_F1_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    s32 rno;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        effF1_data_set(ewk, mwk);
        {
            s8 t = ewk->wu.type;
            another_bg[ewk->master_id] = t;
        }
        ewk->wu.routine_no[0]++;
    case 1:
        if (ewk->wu.dead_f == 1) {
            goto end;
        }
        if ((ewk->wu.dir_old & 1) && (--ewk->wu.direction == 0)) {
            goto end;
        }
        if ((ewk->wu.dir_old & 2)) {
            if (((ewk->wu.routine_no[5] != mwk->wu.routine_no[1]) ||
                                      (ewk->wu.routine_no[6] != mwk->wu.routine_no[2]))) {
                goto end;
            }
        }
        if ((ewk->wu.dir_old & 4) && (mwk->sa->ok != -1)) {
            goto end;
        }
        if (ewk->wu.dir_old & 8) {
            rno = ((WORK*)mwk->wu.target_adrs)->routine_no[1];
            if (rno != 4 && rno != 2) {
                goto end;
            }
        }
        if (ewk->wu.dir_old & 0x10) {
            rno = mwk->wu.routine_no[1];
            if (rno != 4 && rno != 2) {
                goto end;
            }
        }
        if ((ewk->wu.dir_old & 0x20) && (ewk->wu.total_att_set != ((WORK*)mwk->wu.target_adrs)->kind_of_waza)) {
            goto end;
        }
        if ((ewk->wu.dir_old & 0x40) && (ewk->wu.total_paring != mwk->wu.kind_of_waza)) {
            goto end;
        }
        if ((ewk->wu.dir_old & 0x80) && pcon_dp_flag) {
            goto end;
        }
        if (ewk->wu.old_rno[2] && (ewk->wu.total_paring != mwk->wu.kind_of_waza) && (mwk->wu.shell_ix[0] == -1)) {
            goto end;
        }
        if (another_bg[ewk->master_id] != ewk->wu.type) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (another_bg[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    end:
        ewk->wu.routine_no[0]++;
        another_bg[ewk->master_id] = 0;
        break;
    case 2:
    default:
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void effF1_data_set(WORK_Other* ewk, PLW* mwk) {
    const s16* tbl = effF1_data_tbl[ewk->wu.type];
    ewk->wu.dir_old = tbl[0];
    ewk->wu.type = tbl[1];
    ewk->wu.direction = tbl[2];
    ewk->wu.old_rno[3] = tbl[3];
    ewk->wu.old_rno[2] = tbl[4];
    ewk->wu.routine_no[5] = mwk->wu.routine_no[1];
    ewk->wu.routine_no[6] = mwk->wu.routine_no[2];
    ewk->wu.total_paring = mwk->wu.kind_of_waza;
    ewk->wu.total_att_set = ((WORK*)mwk->wu.target_adrs)->kind_of_waza;
    if (mwk->wu.rl_flag) {
        ewk->wu.type = effF1_rl_type_tbl[ewk->wu.type];
    }
}

u32 effect_F1_init()
{
    return 0;
}



void effect_F2_move(WORK_Other* ewk) {
    s16 work;
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[1] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[4], ewk->wu.char_index, 0);
        work = random_16_com();
        work &= 0xF;
        ewk->wu.old_rno[5] = efff2_timer_tbl[work];
        break;
    case 1:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            ewk->wu.cg_type = 0;
            ewk->wu.mvxy.a[0].sp = efff2_sp_tbl1[ewk->wu.type][0];
            ewk->wu.mvxy.d[0].sp = efff2_sp_tbl1[ewk->wu.type][1];
            ewk->wu.mvxy.a[1].sp = -0x18000;
            ewk->wu.mvxy.d[1].sp = -0x400;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < 256) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.xyz[0].disp.pos = efff2_data_tbl1[ewk->wu.type][1];
            ewk->wu.xyz[1].disp.pos = efff2_data_tbl1[ewk->wu.type][2];
            ewk->wu.old_rno[4] = 19;
            ewk->wu.char_index = 1;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_F2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = &efff2_data_tbl1[0][0];
    for (i = 0; i < 10; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 152;
        ewk->wu.be_flag = 1;
        ewk->wu.work_id = 0x10;
        ewk->wu.cgromtype = 1;
        ewk->wu.type = i;
        ewk->wu.old_rno[0] = end_w.r_no_2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = end_char_table;
        ewk->wu.my_col_code = 32;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.old_rno[6] = 0;
        ewk->wu.old_rno[6] += end_w.r_no_2;
        ewk->wu.old_rno[4] = 19;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = 1;
        ewk->wu.old_rno[1] = 1;
    }
    return 0;
}
