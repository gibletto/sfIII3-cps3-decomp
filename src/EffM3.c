/*
 * EFFM3.C  Effect M3: zooming grade letter on the result screen
 *
 * Effect M3 is created by the EFFL1 grade plate (effect_M3_init in effM5) once per grade letter.
 * effect_M3_move waits for Next_Step, then shrinks the letter from a large size to normal using
 * the M3_bahn_data speed and damping values; when the first letter lands it clears Next_Step and
 * calls the follow-up routine. effM3_trans places the letter on its BG family and draws it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "EffM3.h"



void effect_M3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] = 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 64;
        ewk->wu.my_family = 3;
        ewk->wu.position_z = 60 - (ewk->wu.type + 2);
        ewk->wu.dmcal_m = M3_bahn_data[0];
        ewk->wu.dmcal_d = M3_bahn_data[1];
        ewk->wu.dir_timer = M3_bahn_data[2];
        ewk->wu.old_cgnum = 0;
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (!(Next_Step & 1)) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].real.h = 64;
            ewk->wu.mvxy.a[0].real.l = -1;
            ewk->wu.mvxy.d[0].real.h = -1;
            ewk->wu.mvxy.d[0].real.l = M3_bahn_data[4] * 16;
            ewk->wu.mvxy.kop[0] = 1;
            ewk->wu.my_mr_flag = 1;
        case 1:
            if (--ewk->wu.dir_timer >= 0) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
        case 2:
            cal_mvxy_speed(&ewk->wu);
            ewk->wu.mvxy.d[0].sp = (ewk->wu.mvxy.d[0].sp * ewk->wu.dmcal_m) / ewk->wu.dmcal_d;
            if (!ewk->wu.mvxy.a[0].real.h) {
                ewk->wu.routine_no[1]++;
                if (ewk->wu.type == 0) {
                    Next_Step = 0;
                    effinitjp_quake_y[0](ewk, M3_bahn_data[3]);
                }
            }
            break;
        default:
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        ewk->wu.my_mr.size.x = ewk->wu.my_mr.size.y = ewk->wu.my_mts = ewk->wu.mvxy.a[0].real.h + 63;
        effM3_trans(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effM3_trans(WORK* ewk) {
    ewk->position_x = bg_w.bgw[ewk->my_family - 1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[ewk->my_family - 1].wxy[1].disp.pos;
    ewk->position_x += ewk->xyz[0].disp.pos;
    ewk->position_y += ewk->xyz[1].disp.pos;
    sort_push_request4(ewk);
}
