/*
 * EFF78.C  Effect 78: crows (bg000)
 *
 * effect_78_entry creates the two crows on BG2. effect_78_move animates them; when the
 * screen quakes (crow_fuss_check) they take off away from the players and fly to a new perch
 * (crow_fuss_move) before returning to their idle animation.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFF78.h"

/* routine_no[0] */
#define R0_INIT         0       /* show */
#define R0_IDLE         1       /* idle until the screen quakes */
#define R0_FUSS         2       /* fly off and come back */

/* routine_no[1] */
#define R1_INIT         0       /* pick the take-off by direction */
#define R1_TAKEOFF      1       /* take off, then fly away */
#define R1_AWAY         2       /* fly away for 28 frames */
#define R1_HOVER        3       /* four more frames */
#define R1_TURN         4       /* turn, then head for the perch */
#define R1_BACK         5       /* fly back to the pattern's signal */
#define R1_ARRIVE       6       /* reach the perch */
#define R1_LAND         7       /* land, then idle again */

/* crow_char_tbl columns */
#define CROW_CHAR       0       /* take-off pattern, flight follows */
#define CROW_DX         1       /* x distance of the flight */
#define CROW_DY         2       /* y distance of the flight */



void effect_78_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_IDLE:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (crow_fuss_check(ewk)) {
                char_move(&ewk->wu);
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case R0_FUSS:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            crow_fuss_move(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 crow_fuss_check(WORK_Other* ewk) {
    s16 work;
    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = R1_INIT;
        ewk->wu.direction = 0;
        work = plw[0].wu.xyz[0].disp.pos + plw[1].wu.xyz[0].disp.pos;
        work >>= 1;
        work = ewk->wu.xyz[0].disp.pos - work;
        if (work > 64) {
            ewk->wu.direction = 2;
        } else if (work < -64) {
            ewk->wu.direction = 1;
        }
        return 0;
    }
    return 1;
}



void crow_fuss_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = crow_char_tbl[ewk->wu.direction][CROW_CHAR];
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;
    case R1_TAKEOFF:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 1);
            ewk->wu.dir_timer = 28;
            ewk->wu.old_rno[1] = ewk->wu.xyz[0].disp.pos + crow_char_tbl[ewk->wu.direction][CROW_DX];
            ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos + crow_char_tbl[ewk->wu.direction][CROW_DY];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2], 2, 2);
        }
        break;
    case R1_AWAY:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 2);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        break;
    case R1_HOVER:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case R1_TURN:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 3);
            ewk->wu.dir_timer = 48;
            ewk->wu.old_rno[1] = eff78_data_tbl[ewk->wu.type * 2];
            ewk->wu.old_rno[2] = eff78_data_tbl[ewk->wu.type * 2 + 1];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2] + 4, 0, 0);
        }
        break;
    case R1_BACK:
        ewk->wu.dir_timer--;
        add_x_sub(ewk);
        add_y_sub(ewk);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case R1_ARRIVE:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[1];
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 4);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        break;
    case R1_LAND:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = R0_IDLE;
            set_char_move_init(&ewk->wu, 0, 4);
        }
        break;
    }
}



/* provisional name */
s32 effect_78_entry(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff78_data_tbl;
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 78;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = ewk->wu.my_priority = 83;
        ewk->wu.char_index = 4;
        ewk->wu.char_table[0] = j10_char_table;
        ewk->wu.hit_stop = 0;
    }
}
