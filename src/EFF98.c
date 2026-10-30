/*
 * EFF98.C  Effect 98: super-art plate on the player select screens
 *
 * effect_98_move dispatches through EFF98_Jmp_Tbl and draws the plate every frame.
 * The plate is driven by the Order / Order_Timer bytes for its slot (dir_old):
 *   EFF98_WAIT      idles until an order code is written, then switches to it
 *   EFF98_SLIDE_IN  after the order timer, slides the plate in from the screen edge to its
 *                   Plate_Pos_Data_79 position, stops the cursor and starts effect 80
 *   EFF98_SLIDE_OUT empty slot
 *   EFF98_SUDDENLY  after the order timer, shows the plate at its position at once
 *   EFF98_KILL      after the order timer, hides the plate and frees it
 * effect_98_init (called from next_cpu.c) creates the plate for a player, order slot and BG.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "Eff80.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF98.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFA1.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF99.h"
#include "effa0.h"

/* routine_no[0]: order code, index into EFF98_Jmp_Tbl */
#define R0_WAIT         0       /* idle until an order arrives */

/* routine_no[1]: step within each order */
#define R1_WAIT         0       /* count the order timer down */
#define R1_SLIDE        1       /* (default) slide to the plate position */

/* routine_no[1], EFF98_SUDDENLY */
#define R1_SHOWN        1       /* (default) shown: back to waiting */

/* routine_no[1], EFF98_KILL */
#define R1_KILL         1       /* (default) put the work back */



void effect_98_move(WORK_Other* ewk) {
    EFF98_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF98_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = R1_WAIT;
    }
}



void EFF98_SLIDE_IN(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_WAIT:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.vital_new =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][SEL_POS_X];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][SEL_POS_Y];
        Stop_Cursor[ewk->master_id] = 1;
        Disp_Command_Name[ewk->master_id][ewk->master_player] = 1;
        effect_80_init(ewk, ewk->master_id, ewk->master_player, ewk->wu.my_family - 1);
        if (ewk->master_id == 0) {
            ewk->wu.xyz[0].disp.pos = 0xF0;
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        } else {
            ewk->wu.xyz[0].disp.pos = 0x310;
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.vital_new <= ewk->wu.xyz[0].disp.pos) {
                Order[ewk->wu.dir_old] = R0_WAIT;
                ewk->wu.routine_no[0] = R0_WAIT;
                ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
            }
        } else if (ewk->wu.vital_new >= ewk->wu.xyz[0].disp.pos) {
            Order[ewk->wu.dir_old] = R0_WAIT;
            ewk->wu.routine_no[0] = R0_WAIT;
            ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
        }
        break;
    }
}



void EFF98_SLIDE_OUT(WORK_Other* ewk) {}



void EFF98_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_WAIT:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][SEL_POS_X];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][SEL_POS_Y];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.routine_no[0] = R0_WAIT;
        Order[ewk->wu.dir_old] = R0_WAIT;
        break;
    }
}



void EFF98_KILL(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_WAIT:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_98_init(s16 PL_id, s16 dir_old, s16 master_player, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->master_player = master_player;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 98;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_old = dir_old;
    ewk->wu.char_index = 14;
    ewk->wu.dir_step = 30;
    ewk->wu.position_z = 35;
    return 0;
}



