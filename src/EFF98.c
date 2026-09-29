/*
 * EFF98.C  Effect 98: super-art plate on the player select screens (move states)
 *
 * effect_98_move dispatches through EFF98_Jmp_Tbl and draws the plate every frame.
 * The plate is driven by the Order / Order_Timer bytes for its slot (dir_old):
 *   EFF98_WAIT      idles until an order code is written, then switches to it
 *   EFF98_SLIDE_IN  after the order timer, slides the plate in from the screen edge to its
 *                   Plate_Pos_Data_79 position, stops the cursor and starts effect 80
 *   EFF98_SLIDE_OUT empty slot
 *   EFF98_SUDDENLY  after the order timer, shows the plate at its position at once
 * The die state and effect_98_init follow in EFF99.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "Eff80.h"
#include "CHARMOVE.h"
#include "EFF98.h"



void effect_98_move(WORK_Other* ewk) {
    EFF98_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF98_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}



void EFF98_SLIDE_IN(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.vital_new =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][1];
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
                Order[ewk->wu.dir_old] = 0;
                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
            }
        } else if (ewk->wu.vital_new >= ewk->wu.xyz[0].disp.pos) {
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.vital_new;
        }
        break;
    }
}



void EFF98_SLIDE_OUT(WORK_Other* ewk) {}



void EFF98_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][1];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}
