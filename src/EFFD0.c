/*
 * EFFD0.C  Effect D0: thrown object that bounces along the floor (move)
 *
 * effect_D0_move plays the object's start pattern, then switches to pattern 15, moves it 96 dots
 * up and 22 dots forward, and flies it through a series of arcs whose timers and speeds come from
 * effd0_conter / effd0_data_tbl (d0_speed_set, mirrored for facing). When it falls below the
 * floor it plays its landing pattern 16 and rests. It is removed when a screen wipe (Exec_Wipe)
 * has finished. The init, effect_D0_init, is in EFFD1.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "EFFD0.h"



s32 effect_D0_move(WORK_Other* ewk) {
    s32 rc;
    if (Exec_Wipe) {
        ewk->wu.no_death_attack = 1;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[1] = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if ((rc = ewk->wu.no_death_attack) != 0 && Exec_Wipe == 0) {
            ewk->wu.routine_no[0] = 99;
            return rc;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[0]++;
            set_char_move_init(&ewk->wu, 0, 15);
            d0_speed_set(&ewk->wu, ewk->wu.old_rno[1]);
            ewk->wu.xyz[1].disp.pos += 96;
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos += 22;
            } else {
                ewk->wu.xyz[0].disp.pos -= 22;
            }
        }
        pl_eff_trans_entry(ewk);
        break;
    case 2:
        if ((rc = ewk->wu.no_death_attack) != 0 && Exec_Wipe == 0) {
            ewk->wu.routine_no[0] = 99;
            return rc;
        }
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            d0_speed_set(&ewk->wu, ewk->wu.old_rno[1]);
        } else {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        if (ewk->wu.xyz[1].disp.pos < 0) {
            ewk->wu.routine_no[0]++;
            set_char_move_init(&ewk->wu, 0, 16);
        }
        pl_eff_trans_entry(ewk);
        break;
    case 3:
        if ((rc = ewk->wu.no_death_attack) != 0 && Exec_Wipe == 0) {
            ewk->wu.routine_no[0] = 99;
            return rc;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[0]++;
        }
        pl_eff_trans_entry(ewk);
        break;
    case 4:
        if ((rc = ewk->wu.no_death_attack) != 0 && Exec_Wipe == 0) {
            ewk->wu.routine_no[0] = 99;
            return rc;
        }
        pl_eff_trans_entry(ewk);
        break;
    case 99:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        return 0;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void d0_speed_set(WORK* ewk, s16 num) {
    ewk->old_rno[0] = effd0_conter[num];
    ewk->old_rno[1]++;
    if (ewk->rl_flag) {
        ewk->mvxy.a[0].sp = -effd0_data_tbl[num][0];
        ewk->mvxy.d[0].sp = -effd0_data_tbl[num][1];
    } else {
        ewk->mvxy.a[0].sp = effd0_data_tbl[num][0];
        ewk->mvxy.d[0].sp = effd0_data_tbl[num][1];
    }
    ewk->mvxy.a[1].sp = effd0_data_tbl[num][2];
    ewk->mvxy.d[1].sp = effd0_data_tbl[num][3];
}
