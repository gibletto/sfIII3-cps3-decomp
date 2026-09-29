/*
 * EFF49.C  Effect 49: continue countdown digits
 *
 * effect_49_init creates the tens or units digit of the continue counter (from Win.c).
 * effect_49_move shows the digit from Continue_Count[LOSER], plays a sound and changes the
 * digit whenever the count changes, and hides it when the count runs out or it is off
 * screen. Setup_Char_49 returns the digit to display.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "textsound.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARMOVE.h"
#include "EFF49.h"



void effect_49_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (ewk->wu.dmcal_m == Continue_Count[LOSER]) {
            break;
        }
        ewk->wu.dmcal_m = Continue_Count[LOSER];
        if (Continue_Count[LOSER] < 0) {
            ewk->wu.routine_no[0]++;
        } else {
            sound_request(0xA7);
            ewk->wu.dir_step = Setup_Char_49(ewk);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        break;
    case 2:
        if (Ck_Range_Out_S(ewk, 1, 64)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_49_init(s16 vital_new) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 49;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.direction = 1;
    ewk->wu.vital_new = vital_new;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 84;
    ewk->wu.dmcal_m = Continue_Count[LOSER];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos + 8;
    ewk->wu.position_z = 15;
    if (vital_new == 4) {
        ix = Continue_Count[LOSER] & 0xF0;
        ix >>= 4;
        ewk->wu.dir_step = ix;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 450;
    } else {
        ix = Continue_Count[LOSER] & 0xF;
        ewk->wu.dir_step = ix;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 594;
    }
    return 0;
}



u8 Setup_Char_49(WORK_Other* ewk) {
    s16 xx;
    if (ewk->wu.vital_new == 4) {
        xx = Continue_Count[LOSER] & 0xF0;
        return (xx >>= 4);
    }
    return Continue_Count[LOSER] & 0xF;
}
