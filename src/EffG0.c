/*
 * EFFG0.C  Effect G0: bonus score line
 *
 * effect_G0_init (from Manage) allocates a bonus score line that slides onto the screen with its
 * score digits. score_bunkai_G0 converts the score into six digit characters and returns the
 * number of significant digits.
 * effect_G0_move animates and places the line (Flash_G0, effG0_trans) and removes it when
 * Check_Die_G0 says the display is finished.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EffG0.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait hidden, then show */
#define R0_MOVE         1       /* slide in, flash when ordered */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1], in R0_MOVE */
#define R1_SLIDE        0       /* slide in to its place */
#define R1_FLASH        1       /* flash when ordered */

/* routine_no[2] */
#define R2_INIT         0       /* set four flashes */
#define R2_PLAIN        1       /* plain digits, then light them */
#define R2_LIT          2       /* lit digits, then put them back */



void effect_G0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (--ewk->wu.dir_timer) {
                break;
            }
            ewk->wu.routine_no[0] = R0_MOVE;
            ewk->wu.routine_no[1] = R1_SLIDE;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
        default:
            effG0_trans(&ewk->wu);
            break;
        }
        break;
    case R0_MOVE:
        Check_Die_G0((WORK_Other_CONN*)ewk);
        switch (ewk->wu.routine_no[1]) {
        case R1_SLIDE:
            ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
            ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
            if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                Order_Dir[ewk->wu.dir_old] = 0;
            }
            break;
        case R1_FLASH:
            switch (Order[ewk->wu.dir_old]) {
            case 0:
                break;
            case 1:
                Flash_G0((WORK_Other_CONN*)ewk);
                break;
            }
            break;
        }
        effG0_trans(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void Check_Die_G0(WORK_Other_CONN* ewk) {
    if (Suicide[2]) {
        ewk->wu.disp_flag = 0;
        ewk->wu.type = 0;
        ewk->wu.routine_no[0] = R0_END;
    }
}



void effG0_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = ewk->xyz[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos + ewk->xyz[1].disp.pos;
    sort_push_request3(ewk);
}



void Flash_G0(WORK_Other_CONN* ewk) {
    s16 ix;
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2]++;
        ewk->wu.vital_new = 4;
        ewk->wu.dir_timer = 1;
    case R2_PLAIN:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[2] = R2_LIT;
            ewk->wu.dir_timer = 3;
            for (ix = 0; ix < ewk->num_of_conn; ix++) {
                ewk->conn[ix].chr += 10;
            }
        }
        break;
    case R2_LIT:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }
        for (ix = 0; ix < ewk->num_of_conn; ix++) {
            ewk->conn[ix].chr -= 10;
        }
        if (--ewk->wu.vital_new == 0) {
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.routine_no[1] = R1_SLIDE;
            ewk->wu.routine_no[2] = R2_INIT;
            break;
        }
        ewk->wu.routine_no[2] = R2_PLAIN;
        ewk->wu.dir_timer = 3;
        break;
    }
}



s16 score_bunkai_G0(WORK_Other_CONN* ewk, u32 tsc) {
    s16 noobjans = 0;
    s16 i;
    s16 ixs[6];
    s16 ixa[6];
    for (i = 5; i > 0; i--) {
        ixa[i] = tsc / bunkai_table_G0[i];
        ixs[i] = tsc = tsc % bunkai_table_G0[i];
    }
    ixa[i] = tsc;
    for (i = 0; i < 6; i++) {
        if ((ewk->conn[i].chr = bunkai_numobj_G0[ixa[i]]) != 0xBD33) {
            noobjans = i + 1;
        }
    }
    return noobjans == 0 ? 1 : noobjans;
}



s32 effect_G0_init(Order, Time, Score, Pos_Index)
s16 Order;
s16 Time;
u32 Score;
s16 Pos_Index;
{
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 160;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.dir_old = Order;
    ewk->wu.dir_timer = Time;
    ewk->wu.dm_butt_type = Score;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x1E0;
    ewk->num_of_conn = 6;
    for (ix = 0; ix < 6; ix++) {
        ewk->conn[ix] = Result_Score[ix];
    }
    if (Perfect_Flag) {
        ix = 1;
    } else {
        ix = 0;
    }
    ewk->wu.hit_quake = bg_w.bgw[1].wxy[0].disp.pos + Compute_Score_Pos_Data_G0[ix][Pos_Index][0];
    ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 416;
    ewk->wu.xyz[1].disp.pos = Compute_Score_Pos_Data_G0[ix][Pos_Index][1];
    ewk->wu.my_priority = ewk->wu.position_z = 5;
    ewk->wu.mvxy.a[0].sp = 0xFFFE8000;
    ewk->wu.mvxy.d[0].sp = 0xFFFD8000;
    ewk->num_of_conn = score_bunkai_G0(ewk, Score);
    return 0;
}
