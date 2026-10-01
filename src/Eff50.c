/*
 * EFF50.C  Effect 50: super art selection plate part
 *
 * Effect 50 is created by effect_50_init from sel_pl as part of the super art selection display.
 * effect_50_move appears when the art selection opens, animates in step with the plate held in
 * Synchro_Address, and when Moving_Plate selects its plate steps to the next animation and shifts
 * its offset; it follows Plate_X / Plate_Y for the player and hides and releases itself when
 * Sel_Arts_Complete is set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "Eff50.h"



void effect_50_move(WORK_Other* ewk) {
    WORK_Other* pwk;
    if (Sel_Arts_Complete[ewk->master_id] < 0) {
        ewk->wu.routine_no[0] = 3;
        ewk->wu.dir_timer = 1;
        return;
    }
    pwk = (WORK_Other*)Synchro_Address[ewk->master_id][(ewk->wu.direction - 1) ^ 1];
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!Select_Arts[ewk->master_id]) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
        }
        break;
    case 1:
        if (Sel_Arts_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0] = 3;
            ewk->wu.dir_timer = 5;
        } else if (Moving_Plate[ewk->master_id] == ewk->wu.direction && !ewk->wu.dm_vital) {
            ewk->wu.routine_no[0]++;
            ewk->wu.char_index++;
            ewk->wu.dmcal_m += 4;
            ewk->wu.dmcal_d--;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        if (!ewk->wu.dm_vital) {
            char_move(&ewk->wu);
        }
        break;
    case 2:
        if (ewk->wu.cg_type != 0 && !Moving_Plate[ewk->master_id]) {
            ewk->wu.routine_no[0] = 1;
            ewk->wu.char_index--;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            ewk->wu.cg_ix = pwk->wu.cg_ix - ewk->wu.cgd_type;
            char_move_z(&ewk->wu);
            ewk->wu.cg_ctr = pwk->wu.cg_ctr;
            ewk->wu.dmcal_m -= 4;
            ewk->wu.dmcal_d++;
            if (ewk->wu.direction != 1) {
                break;
            }
        }
        char_move(&ewk->wu);
        break;
    case 3:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.xyz[0].disp.pos = ewk->wu.dmcal_m + Plate_X[ewk->master_id][0];
    ewk->wu.xyz[1].disp.pos = ewk->wu.dmcal_d + Plate_Y[ewk->master_id][0];
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_50_init(s16 PL_id, s16 Direction, s16 dm_vital) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 50;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->master_id = PL_id;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.dm_vital = dm_vital;
    ewk->wu.direction = Direction;
    if (dm_vital == 0) {
        Synchro_Address[ewk->master_id][ewk->wu.direction - 1] = (u32*)ewk;
    }
    ewk->wu.xyz[0].disp.pos = Plate_Pos_Data_79[Play_Type][ewk->master_id][0][0];
    ewk->wu.xyz[1].disp.pos = Plate_Pos_Data_79[Play_Type][ewk->master_id][0][1];
    if (dm_vital == 1) {
        ewk->wu.char_index = 31;
        ewk->wu.dir_step = Direction - 1;
    } else {
        ewk->wu.char_index = ((Direction - 1) * 2) + 27;
        ewk->wu.dir_step = 0;
    }
    ewk->wu.dmcal_m = EFF50_Correct_Data[Direction - 1][dm_vital][0];
    ewk->wu.dmcal_d = EFF50_Correct_Data[Direction - 1][dm_vital][1];
    ewk->wu.position_z = 30;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}
