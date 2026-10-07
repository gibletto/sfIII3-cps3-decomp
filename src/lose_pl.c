/*
 * LOSE_PL.C  Win/lose poses after a round and the opening demo (first half)
 *
 * Player routines for the end of a round: lose_player dispatches the loser through
 * Lose_00000..Lose_30000 by the character's lose type (normal loser, judged-loss loser and special
 * cases); meta_lose_pause handles a loser who is not in his own character. The second part starts
 * the opening demo: opening_demo_tick is the per-frame entry (init, move, Capcom screen),
 * opning_init_00000/01000 allocate scroll graphics and set up the BG planes, and opening_move
 * advances the scene number when the music sequence reaches the next cue in op_change_sound_tbl,
 * then runs op_100_move..op_106_move; the later bars continue in end_main.c.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "SYS_sub.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sc_trans.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "end_main.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "PLS02.h"
#include "Com_Pl.h"
#include "lose_pl.h"

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



void Lose_20000(PLW* wk) {
    s16 work;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    if ((pcon_rno[0] == 2) && (pcon_rno[1] == 3)) {
        Judge_normal_loser(wk);
        return;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        if (!Extra_Break) {
            if ((Round_num >= (work = Battle_Round[Play_Type]) * 2) || (PL_Wins[Winner_id] >= work + 1)) {
                effect_C1_init(&wk->wu);
            }
        }
        if ((pcon_rno[1] != 0) && (pcon_rno[1] != 4)) {
            lose_rno[0] = lose_rno[1] = lose_rno[2] = 0;
            work = random_16_com();
            work &= 7;
            set_char_move_init(&wk->wu, 9, work + 0x18);
            break;
        }
        break;
    default:
        Normal_normal_Loser(wk);
        break;
    }
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


