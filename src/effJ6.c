/*
 * EFFJ6.C  Effects J2-J6: connected sprite, background pieces and stage objects
 *
 * A group of small effects:
 * effect_J2_init builds a two-part connected sprite (id 192) from bbbs_nando_large.
 * effect_J3 plays a one-shot animation at its owner's position and submits a 2D polygon quad.
 * effect_J4 places background pieces from effJ4_data_tbl that scroll with BG1, either for a
 * limited life or permanently (effJ4_piece_set / effJ4_piece_set_stay, effect_J4_init2).
 * effect_J5 animates BG0 by flipping between its own page and a SIMM RAM copy filled by
 * effJ5_bg_write, on the timings of effJ5_frame_tbl (started from a stage init in BG050.C).
 * effect_J6 is a stage object that can be hit: eff_hit_check changes its pattern and
 * starts effect 27 (created from EFFI4MV).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "sys_test.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFF27.h"
#include "EFFECT.h"
#include "sys_config.h"
#include "CHARSET.h"
#include "effJ6.h"



s32 effect_J2_init(s16 delay) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 192;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 92;
    ewk->wu.dir_timer = delay;
    ewk->num_of_conn = 2;
    ewk->conn[0] = bbbs_nando_large[0];
    ewk->conn[1] = bbbs_nando_large[1];
    return 0;
}



void effect_J3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_J3_init(WORK* wk, u8 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 193;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->my_master = (u32*)wk;
    ewk->wu.type = type;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2120;
    ewk->wu.char_table[0] = etc2_char_table;
    if (type) {
        ewk->wu.char_index = 57;
        ewk->wu.my_priority = ewk->wu.position_z = 71;
    } else {
        ewk->wu.char_index = 56;
        ewk->wu.my_priority = ewk->wu.position_z = 69;
    }
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos;
    polygon2d_submit_quad(0x03304980, 0x9280, 0x100, 0, 0, 0);
    return 0;
}



void effect_J4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = 0;
        ewk->wu.old_cgnum = 0;
        ewk->wu.cg_number = 1;
        ewk->wu.xyz[0].disp.pos = effJ4_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = effJ4_data_tbl[ewk->wu.type][1];
        ewk->wu.cg_number = effJ4_data_tbl[ewk->wu.type][3];
        if (ewk->wu.dir_timer == 9999) {
            ewk->wu.my_priority = 2;
            ewk->wu.dir_timer = 0x7FFF;
        } else {
            ewk->wu.my_priority = ewk->wu.position_z = 71;
        }
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = effJ4_data_tbl[ewk->wu.type][2];
        break;
    case 1:
        ewk->wu.dir_timer--;
        if (ewk->wu.dead_f || ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + bg_w.bgw[1].position_x + bg_w.pos_offset;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + bg_w.bgw[1].position_y;
        sort_push_request(ewk);
        break;
    case 2:
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* provisional name */
s32 effJ4_piece_set(type, data2)
s16 type;
u8 data2;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 194;
    ewk->wu.type = type;
    ewk->wu.dir_timer = data2;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4400;
    ewk->wu.my_col_code = 0x2000;
    return 0;
}



s32 effect_J4_init(u8 unused, u8 data) {
    s16 i;
    if (test_flag) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        effJ4_piece_set(i, data);
    }
}

/* provisional name */
s32 effJ4_piece_set_stay(type)
s16 type;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 194;
    ewk->wu.type = type;
    ewk->wu.dir_timer = 9999;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4400;
    ewk->wu.my_col_code = 0x2000;
    return 0;
}



s32 effect_J4_init2(s16 ix) {
    s16 i;
    if (test_flag) {
        return 0;
    }
    for (i = effJ4_piece_range[ix][0]; i < effJ4_piece_range[ix][1]; i++) {
        effJ4_piece_set_stay(i);
    }
}



void effect_J5_move(WORK_Other* ewk) {
    s16 slot;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_ix = 0;
        ewk->wu.char_index = 0;
        ewk->wu.cg_ctr = effJ5_frame_tbl[ewk->wu.cg_ix].timer;
        effJ5_bg_write();
        scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
        Scrn_Y_Set_R(0, effJ5_frame_tbl[ewk->wu.cg_ix].y);
        break;
    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 3;
                ewk->wu.cg_ctr = effJ5_frame_tbl[ewk->wu.cg_ix].timer;
                slot = effJ5_frame_tbl[ewk->wu.cg_ix].slot;
                scrn_map_set_now(0, eff_bg_adrs[slot].adrs);
            }
        }
        Scrn_Y_Set_R(0, (s16)(effJ5_frame_tbl[ewk->wu.cg_ix].y + (bg_w.bgw[0].abs_y & 0x3FF)));
        break;
    default:
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        break;
    }
}



/* provisional name */
void effJ5_bg_write(void) {
    s16 i;
    s16 j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 16; j++) {
            scroll_cell_write(i, effJ5_cell_tbl[i][j].a, effJ5_cell_tbl[i][j].b, effJ5_scrn_data);
        }
    }
}



s32 effect_J5_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 195;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[0].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[0].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    return 0;
}



void effect_J6_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr;
    if (obr_disp_off_check()) {
        return;
    }
    oya_ptr = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 4;
            set_char_move_init(&ewk->wu, 0, 3);
        } else {
            set_char_move_init(&ewk->wu, 0, 4);
        }
        break;
    case 1:
        if (oya_ptr->wu.routine_no[0] >= 2) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            effect_j6_hit_sub(ewk);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, 3);
    case 4:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effect_j6_hit_sub(WORK_Other* ewk) {
    if (eff_hit_check(ewk, 0)) {
        ewk->wu.routine_no[0]++;
        effect_27_init(ewk, 1);
    }
}



s32 effect_J6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 196;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = 3;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    *ewk->wu.char_table = chn_char_table;
    ewk->wu.xyz[0].disp.pos = 904;
    ewk->wu.xyz[1].disp.pos = 16;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.char_index = 4;
    ewk->wu.routine_no[1] = 0;
    return 0;
}
