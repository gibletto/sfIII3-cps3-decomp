/*
 * EFF75_ORDER.C  Effect 75: move routine, order-driven states and init
 *
 * effect_75_move runs the current order state from its jump table and draws the object.
 * The effect 75 states driven through Order / Order_Timer / Order_Dir: EFF75_WAIT, an empty
 * SLIDE_IN, CHAR_CHANGE (switch animation), SUDDENLY (appear on its BG) and DIE (hide and
 * release). effect_75_init creates the object on a target BG with sel_pl_char_table.
 * Used by sel_pl and next_cpu.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF75_ORDER.h"


void effect_75_move(WORK_Other* ewk) {
    EFF75_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}


void EFF75_WAIT(WORK_Other_CONN* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}



void EFF75_SLIDE_IN(WORK_Other* ewk) {}



void EFF75_CHAR_CHANGE(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }
    ewk->wu.routine_no[0] = 0;
    Order[ewk->wu.dir_old] = 0;
    ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}



void EFF75_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos;
        ewk->wu.position_z = 76;
        ewk->wu.dir_step = Order_Dir[ewk->wu.dir_old];
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}



void EFF75_DIE(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 75;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x40;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = 19;
    ewk->wu.dir_step = ID;
    ewk->wu.dir_old = dir_old;
    return 0;
}
