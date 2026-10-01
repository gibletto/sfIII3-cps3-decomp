/*
 * EFF29.C  Effect 28 (static stage objects) and effect 29 (bg100 object)
 *
 * effect_28_init creates the objects listed in scr_obj_data28 for a type (position,
 * priority, animation, family, colour, BG sync); effect_28_move animates and draws them.
 * Effect 29 is a single object in bg100 that waits a random time, plays its animation once
 * and hides again.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF29.h"



void effect_28_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        if (ewk->wu.dir_step) {
            disp_pos_trans_entry_rs(ewk);
            break;
        }
        disp_pos_trans_entry_s(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_28_init(type28)
u8 type28;
{
    const s16* t;
    s16 s;
    s16 n;
    s16 i;
    WORK_Other* o;
    n = scr_obj_num28[type28];
    if (n == 0) {
        return;
    }
    t = scr_obj_data28[type28];
    for (i = 0; i < n; i++) {
        s = pull_effect_work(4);
        if (s == -1) {
            return -1;
        }
        o = (WORK_Other*)frw[s];
        o->wu.be_flag = 1;
        o->wu.id = 28;
        o->wu.work_id = 16;
        o->wu.cgromtype = 1;
        o->wu.rl_flag = 0;
        o->wu.my_col_mode = 0x4200;
        o->wu.type = i;
        o->wu.dead_f = *t++;
        o->wu.my_family = *t++;
        o->wu.my_col_code = *t++;
        o->wu.xyz[0].disp.pos = *t++;
        o->wu.xyz[1].disp.pos = *t++;
        o->wu.my_priority = o->wu.position_z = *t++;
        o->wu.char_index = *t++;
        o->wu.sync_suzi = *t++;
        o->wu.dir_step = *t++;
        o->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(o);
    }
    return 0;
}



void effect_29_move(WORK_Other* ewk) {
    s16 work;
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 1;
                set_char_move_init(&ewk->wu, 0, 0);
                break;
            }
        }
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0] = 0;
                ewk->wu.disp_flag = 0;
                work = random_16_com();
                work &= 7;
                ewk->wu.old_rno[0] = eff29_vanish_time[work];
            }
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_29_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 29;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.dead_f = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x80;
    ewk->wu.xyz[0].disp.pos = 512;
    ewk->wu.xyz[1].disp.pos = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 82;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = hkg_char_table;
    suzi_offset_set(ewk);
    ewk->wu.old_rno[0] = 120;
    ewk->wu.disp_flag = 0;
    return 0;
}
