/*
 * lose_pl.c  Win/lose poses after a round and the opening demo (first half)
 *
 * Player routines for the end of a round: bonus_game_win_pause picks the pose after a bonus
 * stage from its result, meta_win_pause and meta_lose_pause handle a player who is not in his
 * own character, and lose_player dispatches the loser through Lose_00000..Lose_30000 by the
 * character's lose type (normal loser, judged-loss loser and special cases).
 * The second part starts the opening demo: opening_demo_tick is the per-frame entry (init,
 * move, Capcom screen), opning_init_00000/01000 allocate scroll graphics and set up the BG
 * planes, and opening_move advances the scene number when the music sequence reaches the next
 * cue in op_change_sound_tbl, then runs op_100_move..op_106_move; the later bars continue in
 * end_main.c.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "aboutspr.h"
#include "SE.h"
#include "SYS_sub.h"
#include "textsound.h"
#include "sc_trans.h"
#include "CHARMOVE.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "end_main.h"
#include "sys_config.h"
#include "PLS02.h"
#include "Com_Pl.h"
#include "CHARSET.h"
#include "lose_pl.h"



void bonus_game_win_pause(PLW* wk) {
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[1], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[1], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if (set_field_hosei_flag(&plw[0], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[0], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        if (Bonus_Game_Flag == 21) {
            if (wk->wu.operator) {
                if (Time_Over) {
                    set_char_move_init(&wk->wu, 9, 67);
                } else {
                    set_char_move_init(&wk->wu, 9, 65);
                }
                break;
            }
            wk->wu.routine_no[3] = 99;
            break;
        }
        if (wk->wu.operator) {
            if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
                set_char_move_init(&wk->wu, 9, 65);
                break;
            }
            if (Bonus_Game_result > 10) {
                set_char_move_init(&wk->wu, 9, 66);
                break;
            }
            set_char_move_init(&wk->wu, 9, 67);
            break;
        }
        if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
            win_rno[0] = 1;
            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x20000;
            }
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            win_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, 66);
            break;
        }
        set_char_move_init(&wk->wu, 9, 52);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void meta_win_pause(PLW* wk) {
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, meta_win_tbl[wk->player_number]);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void lose_player(PLW* wk) {
    void (*lose_jp_tbl[4])(PLW*) = { Lose_00000, Lose_10000, Lose_20000, Lose_30000 };
    if (My_char[wk->wu.id] != wk->player_number) {
        meta_lose_pause(wk);
    } else {
        lose_jp_tbl[lose_type_tbl[wk->player_number]](wk);
    }
}



void Lose_00000(PLW* wk) {
    if (pcon_rno[0] == 2 && pcon_rno[1] == 3) {
        Judge_normal_loser(wk);
    } else {
        Normal_normal_Loser(wk);
    }
}



void Lose_10000(PLW* wk) {
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[0] == 2) && (pcon_rno[1] == 3)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16_com();
            wk->wu.char_index &= 3;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x38);
            break;
        default:
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    } else if ((pcon_rno[1] == 0) || (pcon_rno[1] == 4)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            wk->wu.char_index = random_16_com();
            wk->wu.char_index &= 7;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 0x18);
            break;
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    }
}



s32 Lose_20000(PLW* wk) {
    s16 work;
    s32 rc;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[0] == 2) && (pcon_rno[1] == 3)) {
        Judge_normal_loser(wk);
        return;
    }
    if (wk->wu.routine_no[3] != 0) {
        Normal_normal_Loser(wk);
        return;
    }
    wk->wu.routine_no[3]++;
    rc = 42;
    if (!Extra_Break) {
        if (Round_num >= Battle_Round[Play_Type] * 2) {
            rc = effect_C1_init(&wk->wu);
        } else if (PL_Wins[Winner_id] >= Battle_Round[Play_Type] + 1) {
            rc = effect_C1_init(&wk->wu);
        } else {
            rc = (s32)PL_Wins;
        }
    }
    if (pcon_rno[1] == 0) {
        return rc;
    }
    if ((rc = pcon_rno[1]) == 4) {
        return rc;
    }
    lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
    work = random_16_com();
    work &= 7;
    set_char_move_init(&wk->wu, 9, work + 0x18);
}



void Lose_30000(PLW* wk) {
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[0] == 2) && (pcon_rno[1] == 3)) {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x3A);
            } else {
                set_char_move_init(&wk->wu, 9, 0x38);
            }
            break;
        default:
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    } else if ((pcon_rno[1] == 0) || (pcon_rno[1] == 4)) {
        return;
    } else {
        switch (wk->wu.routine_no[3]) {
        case 0:
            wk->wu.routine_no[3]++;
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            if (Country != 1) {
                set_char_move_init(&wk->wu, 9, 0x1C);
            } else {
                set_char_move_init(&wk->wu, 9, 0x18);
            }
            break;
        case 1:
        case 9:
            char_move(&wk->wu);
            break;
        }
    }
}



void Normal_normal_Loser(PLW* wk) {
    s16 work;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[1] == 0) || (pcon_rno[1] == 4)) {
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
        work = random_16_com();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work + 0x18);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void Judge_normal_loser(PLW* wk) {
    s16 work;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        work = random_16_com();
        work &= 3;
        set_char_move_init(&wk->wu, 9, work + 0x38);
        break;
    case 1:
    case 9:
    default:
        char_move(&wk->wu);
        break;
    }
}



void meta_lose_pause(PLW* wk) {
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[1] == 0) || (pcon_rno[1] == 4)) {
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        set_char_move_init(&wk->wu, 9, meta_lose_tbl[wk->player_number]);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



/* provisional name */
void op_work_clear(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        op_w.bgw[i].r_no_0 = op_w.bgw[i].r_no_1 = 0;
    }
}



/* provisional name */
s16 opening_demo_tick(void) {
    void (*opening_demo_jp[3])() = { opening_init2, opening_move, opening_capcom_scene_init };
    Game_timer += 1;
    opening_demo_jp[op_w.r_no_0]();
    update_all_disp_pos_ending();
    return op_end_flag;
}



void opening_init2(void) {
    Game_timer = 0;
    switch (op_w.r_no_1) {
    case 0:
        opning_init_00000();
        break;
    case 1:
        opning_init_01000();
        break;
    case 2:
        opning_init_02000();
        break;
    }
}



void opning_init_00000(void) {
    s16 i;
    op_w.r_no_1++;
    op_end_flag = 0;
    bg_vbl_trans_flag = 0;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    scr_cg_c_no = ((s16)simmram_block_alloc_10(0x165, 1));
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = 3;
    polygon2d_submit_line(0x01D2C000, 0, 0, 3);
    polygon2d_submit_line(0x01D2C080, bg_w.scroll_cg_adr, 0x164AF, 1);
    if ((*&Game_setting).mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    for (i = 0; i < 6; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0x2000000;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].position_x = 0x200 - bg_w.pos_offset;
        bg_w.bgw[i].position_y = 0;
    }
    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = ((u16 *(*)(s16 handle))simmram_slot_addr)(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, bg_w.bgw[i].bg_address);
        scrn_map_set(i, bg_w.bgw[i].bg_address);
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
        op_w.bgw[i].bg_no = i;
    }
    sprite_list_setup(0, 1, (s16*)((u32)op_scr_record_data[0]));
    sprite_list_setup(1, 1, (s16*)((u32)op_scr_record_data[1]));
    sprite_list_setup(2, 1, (s16*)((u32)op_scr_record_data[2]));
    sprite_list_setup(3, 1, (s16*)((u32)op_scr_record_data[3]));
    op_w.r_no_2 = 0;
    op_end_flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    bg_w.chase_flag = 0;
}



void opning_init_01000(void) {
    s16 i;
    op_w.r_no_1++;
    for (i = 0; i < 4; i++) {
        scroll_layer_mask_enable(1 << i);
        Bg_On_W(1 << i);
        scrn_attr_set(i, 0, 24);
        scrn_reg_w[i].ctrl &= 0xFE7F;
    }
    scroll_layer_mask_disable(0xFF);
    Bg_Off_W(0xFF);
    op_w.free_work = 8;
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    base_y_pos = 40;
    load_char_gfx(0xE3D0, 1);
    load_char_gfx(0xE470, 1);
    load_char_gfx(0xE520, 1);
}



/* provisional name */
void opning_init_02000(void) {
    op_w.free_work--;
    if (op_w.free_work < 0) {
        op_w.r_no_0++;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        wipe_pattern_set(0, 7, 0);
        Text_Fill_Upper(0, 32);
    }
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    op_demo_index = 0;
    gSeqStatus[0] = 0;
    op_w.index = 0;
    op_sound_status = 0;
    op_plmove_timer = 0;
    if ((Demo_Sound == 0 && Demo_Flag == 0) || Keep_BGM_Flag != 0) {
        sound_reg_level_set(0, 128);
    } else {
        sound_reg_level_set(0, 0);
    }
}



void opening_move(void) {
    s16 work2;
    op_plmove_timer += 1;
    if (op_w.r_no_1 <= 17) {
        work2 = gSeqStatus[0];
        if (op_sound_status != work2) {
            if (work2 == op_change_sound_tbl[op_w.r_no_1]) {
                op_w.r_no_1 += 1;
                op_w.r_no_2 = 0;
                op_work_clear();
            }
        }
    }
    opening_move_jp[op_w.r_no_1]();
    op_sound_status = gSeqStatus[0];
}



void op_100_move(void) {
    op_w.r_no_1++;
    sound_request(1);
    wipe_pattern_set(0, 7, 0);
    Text_Fill_Upper(0, 32);
    op_101_move();
}



void op_101_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        ToneDown(0);
        opening_bg_move_broadcast(0);
        effect_F6_init(0);
        effect_F6_init(1);
        op_obj_disp = 0;
        effect_48_init(0);
        break;
    case 1:
        if (gSeqStatus[0] >= op_101_tbl[op_w.r_no_2] && gSeqStatus[0] != 101) {
            op_w.r_no_2 += 1;
            op_w.index = 1;
            op_obj_disp = 1;
            op_work_clear();
            break;
        }
        opening_bg_move_broadcast(0);
        break;
    default:
        opening_bg_move_broadcast(1);
        break;
    }
}



void op_102_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_w.index = 2;
        effect_F6_init(2);
        effect_F6_init(3);
        effect_F6_init(4);
        op_obj_disp = 0;
        effect_48_init(1);
        op_work_clear();
        opening_bg_move_broadcast(2);
        break;
    case 1:
        if (gSeqStatus[0] >= op_102_tbl[op_w.r_no_2] && gSeqStatus[0] != 102) {
            op_w.r_no_2 += 1;
            op_w.index = 3;
            op_obj_disp = 1;
            op_work_clear();
            opening_bg_move_broadcast(3);
            return;
        }
        opening_bg_move_broadcast(2);
        break;
    case 2:
        if (gSeqStatus[0] >= op_102_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_w.index = 4;
            op_work_clear();
            opening_bg_move_broadcast(4);
            return;
        }
        opening_bg_move_broadcast(3);
        break;
    default:
        opening_bg_move_broadcast(4);
        break;
    }
}



void op_103_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_w.index = 5;
        effect_F6_init(5);
        effect_F6_init(6);
        effect_F6_init(7);
        effect_F6_init(8);
        effect_F6_init(9);
        effect_F6_init(10);
        op_work_clear();
        opening_bg_move_broadcast(5);
        break;
    case 1:
        if (((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) && ((*(u8(*)[])&gSeqStatus[0])[0] != 0x67)) {
            op_w.r_no_2 += 1;
            op_w.index = 6;
            op_work_clear();
            effect_F6_init(11);
            effect_F6_init(12);
            effect_F6_init(13);
            effect_F6_init(14);
            effect_F6_init(15);
            effect_F6_init(16);
            return;
        }
        opening_bg_move_broadcast(5);
        break;
    case 2:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 7;
            op_obj_disp = 0;
            effect_48_init(8);
            return;
        }
        opening_bg_move_broadcast(6);
        break;
    case 3:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 8;
            op_obj_disp = 1;
            op_scrn_end = 0;
            effect_36_init(22);
            return;
        }
        opening_bg_move_broadcast(7);
        break;
    case 4:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 9;
            return;
        }
        opening_bg_move_broadcast(8);
        break;
    case 5:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 10;
            return;
        }
        opening_bg_move_broadcast(9);
        break;
    case 6:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 11;
            return;
        }
        opening_bg_move_broadcast(10);
        break;
    case 7:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 12;
            op_obj_disp = 0;
            effect_48_init(9);
            return;
        }
        opening_bg_move_broadcast(11);
        break;
    case 8:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 13;
            op_obj_disp = 1;
            return;
        }
        opening_bg_move_broadcast(12);
        break;
    case 9:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 14;
            op_scrn_end = 0;
            effect_36_init(23);
            return;
        }
        opening_bg_move_broadcast(13);
        break;
    case 10:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 15;
        }
        opening_bg_move_broadcast(14);
        break;
    case 11:
        if ((*(u8(*)[])&gSeqStatus[0])[0] >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 16;
            return;
        }
        opening_bg_move_broadcast(15);
        break;
    default:
        opening_bg_move_broadcast(16);
        break;
    }
}



void op_104_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_work_clear();
        op_w.index = 17;
        opening_bg_move_broadcast(17);
        effect_F6_init(17);
        effect_F6_init(18);
        effect_F6_init(19);
        effect_F6_init(20);
        effect_F6_init(21);
        effect_F6_init(22);
        effect_F6_init(23);
        break;
    case 1:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2] && gSeqStatus[0] != 104) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 18;
            break;
        }
        opening_bg_move_broadcast(17);
        break;
    case 2:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 19;
            op_obj_disp = 0;
            effect_48_init(10);
            break;
        }
        opening_bg_move_broadcast(18);
        break;
    case 3:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 20;
            op_obj_disp = 1;
            break;
        }
        opening_bg_move_broadcast(19);
        break;
    case 4:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 21;
            op_obj_disp = 0;
            effect_48_init(11);
            break;
        }
        opening_bg_move_broadcast(20);
        break;
    case 5:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 22;
            op_obj_disp = 1;
            break;
        }
        opening_bg_move_broadcast(21);
        break;
    case 6:
        if (gSeqStatus[0] >= op_104_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 23;
            break;
        }
        opening_bg_move_broadcast(22);
        break;
    case 7:
    default:
        opening_bg_move_broadcast(23);
        break;
    }
}



void op_105_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        purge_char_gfx(0xE520);
        load_char_gfx(0xE528, 1);
        op_work_clear();
        op_w.index = 24;
        opening_bg_move_broadcast(24);
        effect_F6_init(24);
        op_obj_disp = 0;
        effect_48_init(12);
        break;
    case 1:
    default:
        opening_bg_move_broadcast(24);
        break;
    }
}



void op_106_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_work_clear();
        op_w.index = 25;
        op_obj_disp = 1;
        opening_bg_move_broadcast(25);
        effect_F6_init(25);
        effect_F6_init(26);
        effect_F6_init(27);
        effect_F6_init(28);
        effect_36_init(18);
        effect_36_init(19);
        effect_36_init(20);
        effect_36_init(21);
        break;
    case 1:
        if (gSeqStatus[0] >= op_106_tbl[op_w.r_no_2] && gSeqStatus[0] != 106) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 26;
            return;
        }
        opening_bg_move_broadcast(25);
        break;
    case 2:
        if (gSeqStatus[0] >= op_106_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 27;
            return;
        }
        opening_bg_move_broadcast(26);
        break;
    case 3:
        if (gSeqStatus[0] >= op_106_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 28;
            op_obj_disp = 0;
            effect_48_init(15);
            return;
        }
        opening_bg_move_broadcast(27);
        break;
    default:
        opening_bg_move_broadcast(28);
        break;
    }
}
