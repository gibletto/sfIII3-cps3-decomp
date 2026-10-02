/*
 * EFF99.C  Effect 98 die state and init, effects 99 and A0
 *
 * EFF98_DIE counts down the order timer, hides the super-art plate and frees it.
 * effect_98_init (called from next_cpu.c) creates the plate for a player, order slot and BG.
 * Effect 99 shows a select-screen sprite (sel_pl_char_table) after a delay, drawn relative to
 * BG1, and frees it when Disp_PERFECT is cleared.
 * Effect A0 is Akuma's (Gouki) intrusion entrance: effect_A0_init picks a palette that differs
 * from the opponent's colour (effA0_swap_tbl), places the object off-screen and spawns two A1
 * after-images.
 * effect_A0_move runs in with a shadow, plays its appearance pattern, sets gouki_app, wakes
 * the other player (cmwk[0]), and finally sets Next_Step to hand control back to the game flow.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "EFFA1.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFF99.h"



void effect_99_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        break;
    case 1:
        if (Disp_PERFECT == 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        return;
    }
    ewk->wu.position_x = bg_w.bgw[1].xy[0].disp.pos + ewk->wu.dm_vital;
    ewk->wu.position_y = bg_w.bgw[1].xy[1].disp.pos + base_y_pos + 136;
    sort_push_request4(ewk);
}



s32 effect_99_init(s16 index, s16 timer, s16 ip) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 99;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x21E0;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = index;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_timer = timer;
    ewk->wu.position_z = 10;
    if (index == 20) {
        ewk->wu.dm_vital = -8;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    } else {
        ewk->wu.dm_vital = 46;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ip, 0);
    }
    return 0;
}



void effect_A0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 18;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 40;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos, 2, 2);
        break;
    case 1:
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[0]++;
            char_move_z(&ewk->wu);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 2:
        char_move_z(&ewk->wu);
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 40) {
            gouki_app = 1;
            plw[ewk->master_id ^ 1].wu.cmwk[0] = (ewk->master_id ^ 1) + 1;
            ewk->wu.my_priority = 58;
            ewk->wu.position_z = 58;
            ewk->wu.cg_type = 0;
        }
        if (ewk->wu.cg_type == 50) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.kage_flag = 1;
            ewk->wu.cg_type = 0;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 4:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 5:
        Next_Step = 1;
        ewk->wu.routine_no[0]++;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 6:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_disp_off_check()) {
            sort_push_request(ewk);
        }
        break;
    case 7:
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        break;
    case 8:
        ewk->wu.routine_no[0]++;
        break;
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_A0_init(s16 pl) {
    WORK_Other* ewk;
    PLW* mwk;
    WORK* twk;
    s16 ix;
    s16 center;
    s16 offset;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    mwk = &plw[pl];
    twk = (WORK*)mwk->wu.target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 100;
    ewk->master_id = mwk->wu.id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = mwk->wu.my_col_mode;
    ewk->wu.my_col_code = 50;
    ewk->wu.my_family = mwk->wu.my_family;
    ewk->my_master = (u32*)mwk;
    ewk->wu.rl_flag = mwk->wu.rl_flag;
    ewk->wu.old_rno[2] = Player_Color[twk->id];
    if (*(volatile s16*)&ewk->wu.old_rno[2] == Player_Color[mwk->wu.id]) {
        if (Player_Color[mwk->wu.id] < 7) {
            ewk->wu.old_rno[2] = effA0_swap_tbl[Player_Color[mwk->wu.id]];
        } else {
            ewk->wu.old_rno[2] = 0;
        }
        Player_Color[twk->id] = *(volatile s8*)((u8*)&ewk->wu.old_rno[2] + 1);
    }
    center = bg_w.bgw[1].wxy[0].disp.pos;
    offset = bg_w.pos_offset;
    if (mwk->wu.rl_flag) {
        if (mwk->wu.xyz[0].disp.pos < center) {
            ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos - 0x100;
        } else {
            ewk->wu.xyz[0].disp.pos = center - offset - 32;
        }
        ewk->wu.old_rno[1] = twk->xyz[0].disp.pos - 16;
    } else {
        if (mwk->wu.xyz[0].disp.pos > center) {
            ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos + 0x100;
        } else {
            ewk->wu.xyz[0].disp.pos = offset + center + 32;
        }
        ewk->wu.old_rno[1] = twk->xyz[0].disp.pos + 16;
    }
    ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos - 4;
    ewk->wu.my_priority = mwk->wu.my_priority - 12;
    ewk->wu.position_z = mwk->wu.my_priority - 12;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_index = 9;
    ewk->wu.sync_suzi = 0;
    load_any_color(ewk->wu.old_rno[2] + 0xAB);
    load_any_color(0xB2);
    effect_A1_init(ewk, 1);
    effect_A1_init(ewk, 2);
    return 0;
}
