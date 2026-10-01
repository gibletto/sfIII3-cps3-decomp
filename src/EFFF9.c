/*
 * EFFF9.C  Effects F7, F8 and F9: object viewer, second parry mark and ending message text
 *
 * Effect F7 is a debug viewer for op_char_table objects: player 2 picks the object (0-25), zooms
 * it, toggles its priority and moves it, with the values printed on the text layer.
 * Effect F8 is a second parry mark: like effect C7 it is placed from its own offset table for the
 * parry type and character and plays pattern 3 of ef01_char_table until it ends.
 * Effect F9 is the ending message window. effect_F9_move picks the message by Country and
 * Language (effF9_mes_jp / _en / _es / _pt), loads its graphics, types it out a few characters
 * every three frames and calls Next_Talk_Message when its display time runs out. The ending
 * scripts (end_*.c) drive it through Rewrite_End_Message, Rewrite_Talk_Message,
 * Set_Direct_Message and Next_Talk_Message, which read the per-character scene lists in
 * txt_no_tbl (message + time pairs); effF9_talk_init opens the window on BG3.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "CHARMOVE.h"
#include "CMD_MAIN.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "textsound.h"
#include "EFFF9.h"



void effect_F7_move(WORK_Other* ewk) {
    s16 work;
    s16 mr;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = ewk->wu.old_rno[1];
        ewk->wu.my_mr.size.y = ewk->wu.old_rno[1];
        set_char_move_init2(&ewk->wu, 0, 3, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        switch ((s16)(p2sw_0 & ~p2sw_1)) {
        case 0x10:
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[0]++;
            if (ewk->wu.old_rno[0] >= 26) {
                ewk->wu.old_rno[0] = 0;
            }
            break;
        case 0x20:
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.old_rno[0] = 25;
            }
            break;
        case 0x40:
            ewk->wu.old_rno[1]++;
            if (ewk->wu.old_rno[1] > 127) {
                ewk->wu.old_rno[1] = 127;
            }
            break;
        case 0x100:
            ewk->wu.old_rno[2] ^= 1;
            ewk->wu.my_priority = ewk->wu.position_z = ewk->wu.old_rno[2] ? 10 : 100;
            break;
        case 0x200:
            ewk->wu.old_rno[1]--;
            if (ewk->wu.old_rno[1] < 0) {
                ewk->wu.old_rno[1] = 0;
            }
            break;
        }
        if (p2sw_0 & 8) {
            ewk->wu.xyz[0].disp.pos++;
        }
        if (p2sw_0 & 4) {
            ewk->wu.xyz[0].disp.pos--;
        }
        if (p2sw_0 & 1) {
            ewk->wu.xyz[1].disp.pos++;
        }
        if (p2sw_0 & 2) {
            ewk->wu.xyz[1].disp.pos--;
        }
        work = debug_hex4_to_bcd(ewk->wu.old_rno[0]);
        tilemap_print_hex(8, 4, 14, work, 4, 0);
        mr = ewk->wu.old_rno[1] - 63;
        if (mr < 0) {
            tilemap_print_string_attr(7, 6, 14, "-");
            mr = -mr;
        } else {
            tilemap_print_string_attr(7, 6, 14, " ");
        }
        work = debug_hex4_to_bcd(mr);
        tilemap_print_hex(8, 6, 14, work, 4, 0);
        tilemap_print_hex(8, 8, 14, ewk->wu.xyz[0].disp.pos, 4, 0);
        tilemap_print_hex(8, 10, 14, ewk->wu.xyz[1].disp.pos, 4, 0);
        ewk->wu.my_mr.size.x = ewk->wu.old_rno[1];
        ewk->wu.my_mr.size.y = ewk->wu.old_rno[1];
        disp_pos_trans_entry5(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_F7_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 157;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 192;
    ewk->wu.char_table[0] = op_char_table;
    ewk->wu.xyz[0].cal = 0x2000000;
    ewk->wu.xyz[1].cal = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 100;
    ewk->wu.old_rno[0] = 0;
    ewk->wu.old_rno[2] = 0;
    ewk->wu.old_rno[1] = 63;
    tilemap_print_string_attr(2, 2, 14, effF7_blk_msg);
    tilemap_print_string_attr(2, 4, 14, effF7_obj_msg);
    tilemap_print_string_attr(2, 6, 14, effF7_mr_msg);
    tilemap_print_string_attr(2, 8, 14, effF7_pos_msg);
}

u32 effect_F8_move(WORK_Other* ewk)
{
    WORK* mwk = (WORK*)ewk->my_master;
    /* paring_b_mark_data[direction][master_player][2]: { x, y } */
    const s16 (*mark_tbl)[24][2] = paring_b_mark_data;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[2].disp.pos = 26;
        ewk->wu.next_z = mwk->position_z;
        if (!mwk->rl_flag) {
            ewk->wu.position_x = mwk->position_x - mark_tbl[ewk->wu.direction][ewk->master_player][0];
        } else {
            ewk->wu.position_x = mwk->position_x + mark_tbl[ewk->wu.direction][ewk->master_player][0];
        }
        ewk->wu.position_y = mark_tbl[ewk->wu.direction][ewk->master_player][1] + mwk->position_y;
        if (ewk->wu.position_z == ewk->wu.xyz[2].disp.pos) {
            ewk->wu.position_z = ewk->wu.next_z;
        } else {
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        }
        set_char_move_init(&ewk->wu, 0, 3);
        return sort_push_request(&ewk->wu);
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return 0;
        }
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                return 0;
            }
        }
        return sort_push_request(&ewk->wu);
    case 2:
        ewk->wu.routine_no[0] = 3;
        return 2;
    default:
        all_cgps_put_back(&ewk->wu);
        return push_effect_work((WORK*)ewk);
    }
}



s32 effect_F8_init(PLW* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 158;
    ewk->wu.work_id = 64;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.direction = data;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2020;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->my_master = (u32*)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    ewk->wu.char_table[0] = ef01_char_table;
    return 0;
}



void effect_F9_move(WORK_Other* owk) {
    WORK_Other_CONN* ewk = (WORK_Other_CONN*)owk;
    const u16* chr_data;
    const CONN* conn_data;
    s32 variant;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        variant = Language;
        switch (Country) {
        case 1:
            conn_data = effF9_mes_jp[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_jp[ewk->master_player][mes_already].chr;
            break;
        case 3:
            switch (variant) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 5:
            conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
            break;
        case 6:
            conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
            break;
        case 7:
            switch (variant) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 2:
        case 4:
        default:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        }
        for (i = 0; i < chr_data[0]; i++) {
            load_char_gfx(chr_data[i + 1], 1);
            continue;
        }
        ewk->num_of_conn = chr_data[i + 1];
        ewk->wu.old_rno[4] = chr_data[i + 1];
        if (ewk->wu.old_rno[4] == 0) {
            ewk->wu.old_rno[5] = 0;
        } else {
            ewk->wu.old_rno[5] = 1;
        }
        ewk->wu.old_rno[6] = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].nx = conn_data[i].nx;
            ewk->conn[i].ny = conn_data[i].ny;
            ewk->conn[i].col = conn_data[i].col;
            ewk->conn[i].chr = conn_data[i].chr;
            continue;
        }
        efff9_suicide = 0;
        ewk->wu.vitality = 240;
        ewk->num_of_conn = ewk->wu.old_rno[5];
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        ewk->wu.routine_no[0]++;
        break;
    case 5:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 6;
            break;
        }
        ewk->wu.old_rno[6]--;
        if (ewk->wu.old_rno[6] == 0) {
            ewk->wu.old_rno[6] = 3;
            if (ewk->wu.old_rno[4] == ewk->wu.old_rno[5]) {
                ewk->wu.old_rno[6] = 3;
            } else {
                ewk->wu.old_rno[5]++;
                if (Country != 1) {
                    ewk->wu.old_rno[5]++;
                    if (ewk->wu.old_rno[4] < ewk->wu.old_rno[5]) {
                        ewk->wu.old_rno[5] = ewk->wu.old_rno[4];
                    }
                }
                ewk->num_of_conn = ewk->wu.old_rno[5];
            }
        }
        if (ewk->wu.old_rno[3] == 0) {
            Next_Talk_Message();
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 6;
            break;
        }
        ewk->wu.old_rno[3]--;
        if (efff9_suicide == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 6;
            ewk->wu.disp_flag = 0;
            break;
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 6:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Start the ending text effect for character pl_no. */
s32 effect_F9_init(s16 pl_no)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    keep_mes_no = 0;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_PL_NO = pl_no;
    ewk->master_player = efff9_PL_NO;
    return 0;
}



void efff9_wk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 159;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_priority = 5;
    ewk->wu.position_x = 312;
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 5;
}



/* provisional name */
s32 effF9_talk_init(s16 pl) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    effF9_talk_wk_set(ewk);
    efff9_PL_NO = pl;
    ewk->master_player = efff9_PL_NO;
    load_any_color(0x8D);
    return 0;
}



/* provisional name */
void effF9_talk_wk_set(WORK_Other* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x9F;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 3;
    ewk->wu.my_priority = 5;
    if (Game_setting.mode == 0) {
        ewk->wu.position_x = 0x280;
    } else {
        ewk->wu.position_x = 0x2E8;
    }
    ewk->wu.position_y = 0x18;
    ewk->wu.position_z = 5;
}



s32 Rewrite_End_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    keep_mes_no = mes_no;
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    ewk->wu.old_rno[3] = *(s16*)((u8*)efff9_txt_scene_adrs + 2);
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
s32 Rewrite_Talk_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    keep_mes_no = mes_no;
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    effF9_talk_wk_set(ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    ewk->wu.old_rno[3] = efff9_txt_scene_adrs[1];
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
s32 Set_Direct_Message(s16 mes) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 0;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set(ewk);
    mes_already = mes;
    return 0;
}



/* provisional name */
s32 Next_Talk_Message(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set(ewk);
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[keep_mes_no];
    efff9_message = efff9_txt_scene_adrs[efff9_txt_point];
    ewk->wu.old_rno[3] = efff9_txt_scene_adrs[efff9_txt_point + 1];
    efff9_txt_point += 2;
    mes_already = efff9_message;
    return 0;
}
