/*
 * EFFL4.C  Effects L4, L5, L6: stage pieces, stamped sign and win-pose walkers
 *
 * Effect L4 (id 214): effect_L4_init (from bg130) creates six stage pieces from a position /
 * priority / character table; effect_L4_move animates each piece, shows it on odd cg_type frames
 * and positions it through the background display entry.
 * Effect L5 (id 215): effect_L5_init (from effb2) attaches a sign to a parent effect on BG family
 * 4; hukuromoji_move stamps it in by shrinking it from double size with a sound request, and
 * effect_L5_move follows the parent's state and frees itself with it.
 * Effect L6: effect_L6_init (from win_pl) starts a walker used in a win pose; effl6_back/1
 * walk it with a shadow for a set time, then play the stop animation and switch to their final
 * character, kept at the sync point and queued for display.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "SE.h"
#include "bg_sub.h"
#include "EFFL4.h"



void effect_L4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            ewk->wu.disp_flag = ewk->wu.cg_type & 1;
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_L4_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = effl4_data_tbl;
    for (i = 0; i < 6; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 214;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x80;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.char_table[0] = frc_char_table;
    }
}



void effect_L5_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr = (WORK_Other*)ewk->my_master;
    switch (oya_ptr->wu.routine_no[0]) {
    case 5:
    case 6:
        hukuromoji_move(ewk);
        disp_pos_trans_entry5(ewk);
        break;
    case 7:
        ewk->wu.extra_col = oya_ptr->wu.extra_col;
        disp_pos_trans_entry5(ewk);
        break;
    case 8:
        ewk->wu.disp_flag = 0;
        disp_pos_trans_entry5(ewk);
        break;
    case 9:
    case 99:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void hukuromoji_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init2(&ewk->wu, 0, 2, 6, 0);
        ewk->wu.hit_stop = 2;
        break;
    case 1:
        ewk->wu.hit_stop -= 1;
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[1] += 1;
            Sound_SE(oya_ptr->wu.dir_old + 1);
            return;
        }
        break;
    case 2:
        ewk->wu.my_mr.size.x -= 6;
        ewk->wu.my_mr.size.y -= 6;
        if (ewk->wu.my_mr.size.x <= 63) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.hit_stop = 4;
            set_char_move_init2(&ewk->wu, 0, 2, 7, 0);
            return;
        }
        break;
    case 3:
        ewk->wu.hit_stop -= 1;
        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.routine_no[1] += 1;
            rf_b2_flag = 1;
        }
        break;
    case 4:
        break;
    }
}



s32 effect_L5_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xD7;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)oya;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x1E0;
    ewk->wu.my_priority = ewk->wu.position_z = 9;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    return 0;
}



void effect_L6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.type) {
                effl6_flont(ewk);
            } else {
                effl6_back(ewk);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void effl6_flont(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 1);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 1, 59);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        break;
    }
}



/* provisional name */
void effl6_back(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 1);
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 1, 52);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        break;
    }
}



s32 effect_L6_init(WORK* wk, u8 typel6) {
    s16 ix;
    WORK_Other* ewk;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 216;
    ewk->master_id = wk->id;
    ewk->wu.type = typel6;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    if (wk->id) {
        ewk->wu.my_col_code = wk->my_col_code + 2;
    }
    if (Player_Color[wk->id] == 6) {
        ewk->wu.my_col_code = wk->my_col_code + 3;
    }
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = 28;
    ewk->wu.position_z = 28;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_table[1] = etc_char_table;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    if (typel6) {
        ewk->wu.rl_flag = wk->rl_flag ^ 1;
        if (wk->rl_flag) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos += 32;
            ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 96;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 32;
            ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 96;
        }
        ewk->wu.old_rno[0] = 120;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
    } else {
        ewk->wu.rl_flag = wk->rl_flag;
        if (wk->rl_flag) {
            if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
                ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
            } else {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
            }
            ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 32;
        } else {
            if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
                ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
            } else {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
            }
            ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 32;
        }
        ewk->wu.old_rno[0] = 80;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
    }
    suzi_offset_set(ewk);
    return 0;
}
