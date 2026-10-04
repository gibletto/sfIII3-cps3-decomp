/*
 * EFF46.C  Effect 46: appearance object that flies off
 *
 * Effect 46 is created by the appearance scripts (appear.c) near a character. It idles
 * until the character comes close (eff46_appear_check), plays one of two random reaction
 * animations and then flies away, ending once off screen.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF46.h"



void effect_46_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff46_move(ewk);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void eff46_move(WORK_Other* ewk) {
    s16 work2;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        char_move(&ewk->wu);
        if (eff46_appear_check(ewk)) {
        } else {
            break;
        }
        ewk->wu.routine_no[1]++;
        work2 = random_16_com();
        if (work2 & 1) {
            set_char_move_init(&ewk->wu, 0, 44);
        } else {
            set_char_move_init(&ewk->wu, 0, 45);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos >= ewk->wu.old_rno[0]) {
            add_y_sub(ewk);
        }
        if (!range_x_check3(ewk, 64)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        ewk->wu.routine_no[0] = 2;
        break;
    }
}


s16 eff46_appear_check(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work = oya_ptr->xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;
    if (work < 0) {
        work = -work;
    }
    if (work > 48) {
        return 0;
    }
    work = oya_ptr->xyz[1].disp.pos - ewk->wu.xyz[1].disp.pos;
    if (work < 0) {
        work = -work;
    }
    if (work > 80) {
        return 0;
    }
    return 1;
}



s32 effect_46_init(WORK* wk, s32 _p1) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 46;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    if (wk->id) {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 112;
        ewk->wu.mvxy.a[0].sp = 0x50000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.mvxy.a[1].sp = 0x30000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
    } else {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - 112;
        ewk->wu.mvxy.a[0].sp = -0x50000;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.mvxy.a[1].sp = 0x30000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.old_rno[0] = ewk->wu.xyz[1].disp.pos;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.char_index = 43;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    return 0;
}
