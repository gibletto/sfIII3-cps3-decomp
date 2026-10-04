/*
 * EFF28.C  Effect 28: static stage objects
 *
 * effect_28_init creates the objects listed in scr_obj_data28 for a type (position,
 * priority, animation, family, colour, BG sync); effect_28_move animates and draws them.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff28.h"



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



