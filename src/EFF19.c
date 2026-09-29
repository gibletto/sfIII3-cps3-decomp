/*
 * EFF19.C  Effect 19: stage object reacting to quakes (bg130)
 *
 * effect_19_move animates the object and, according to bg_w.quake_y_index, picks a random
 * reaction from small tables: wait, jump up and fall, or play an animation and vanish while a
 * player is in range, then reappear. effect_19_init is called from bg130.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "EFF19.h"



void effect_19_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 6);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff19_quake_sub(ewk);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

u8 * eff19_quake_sub(WORK_Other* ewk)
{
    const s8* sel_tbl;
    s16 rnd;
    s8 sel;
    s32 hit;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index < 3) {
            return (u8*)0x2C;
        }
        rnd = random_16_com();
        if (bg_w.quake_y_index < 8) {
            sel = effect_19_s_tbl[rnd];
        } else {
            sel_tbl = effect_19_m_tbl;
            if (bg_w.quake_y_index > 14) {
                sel_tbl = effect_19_l_tbl;
            }
            sel = sel_tbl[rnd];
        }
        if (sel == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.old_rno[0] = 60;
            return (u8*)0x28;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.routine_no[2] = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x6000;
        /* eff19_wait_tbl */
        ewk->wu.old_rno[0] = eff19_wait_tbl[rnd];
        return (u8*)eff19_wait_tbl;
    case 1:
        if (ewk->wu.routine_no[2] == 0) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[1]++;
                return (u8*)0x26;
            }
            return (u8*)0;
        }
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1] = 0;
            return (u8*)((s32 (*)())set_char_move_init)(ewk, 0, 6);
        }
        return (u8*)(s32)ewk->wu.routine_no[2];
    case 2:
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < 66) {
            ewk->wu.routine_no[1]++;
            return (u8*)0x26;
        }
        return (u8*)0x68;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type != 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        return (u8*)0;
    case 4:
        hit = range_x_check(&ewk->wu);
        if (hit != 0) {
            return (u8*)hit;
        }
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[1].disp.pos = eff19_data_tbl[ewk->wu.type * 2 + 1];
        return (u8*)((s32 (*)())set_char_move_init)(ewk, 0, 6);
    default:
        return (u8*)(s32)ewk->wu.routine_no[1];
    }
}



s32 effect_19_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = &eff19_data_tbl[0];
    for (i = 0; i < 7; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 19;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.dead_f = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = 6;
        ewk->wu.char_table[0] = jp3_char_table;
        ewk->wu.sync_suzi = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.my_priority = ewk->wu.position_z = 80;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        suzi_offset_set(ewk);
    }
    return 0;
}
