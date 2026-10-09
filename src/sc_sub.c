/*
 * SC_SUB.C  HUD win marks, palette fade control and stun gauge
 *
 * Per-player HUD pieces drawn on the text layer during a fight. The win mark routines
 * (win_mark_control, win_mark_pos_set, win_mark_write, win_mark_all_write) place one mark per round
 * won and blink a newly won mark using win_mark_blink_tbl. fade_cont_init / fade_cont_main run a
 * multi-layer palette fade: the fade number selects a list of palette groups and step parameters,
 * and each frame the groups due for an update are re-sent through the colour request queue with the
 * next brightness until every layer has reached its target, after which the fade flags are cleared.
 * stngauge_cont_init / stngauge_cont_main / stngauge_control keep each player's stun gauge in step
 * with the stun value, with stun_put, stun_mark_write and stun_gauge_waku_write drawing the gauge,
 * its "stun" mark and its frame.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "sc_sub_2.h"
#include "sc_sub.h"
#include "cps3.h"



/* provisional name */
void win_mark_control(s16 pl) {
    if (Exec_Wipe) {
        return;
    }
    switch (win_mark_rno[pl]) {
    case 0:
        win_mark_new[pl] = 0;
        if (PL_Wins[pl] == 0) {
            win_mark_rno[pl] = 99;
            return;
        }
        win_mark_rno[pl]++;
        win_mark_timer[pl] = 1;
        win_mark_phase[pl] = 0;
        win_mark_pos_set(pl);
        return;
    case 1:
        if (win_mark_new[pl]) {
            win_mark_new_check(pl);
        }
        if (--win_mark_timer[pl] != 0) {
            return;
        }
        win_mark_write(pl);
        win_mark_timer[pl] = win_mark_blink_tbl[0][win_mark_phase[pl] + 1];
        if (win_mark_phase[pl] != 2) {
            win_mark_phase[pl] += 2;
        } else {
            win_mark_phase[pl] = 0;
        }
        return;
    default:
        if (win_mark_new[pl]) {
            if (win_mark_phase[pl ^ 1] == 0) {
                win_mark_rno[pl] = 1;
                win_mark_new[pl] = 0;
                win_mark_timer[pl] = 1;
                win_mark_phase[pl] = 0;
                win_mark_pos_set(pl);
            }
        }
        return;
    }
}



/* provisional name */
void win_mark_pos_set(s16 pl) {
    win_mark_num[pl] = PL_Wins[pl] * 2;
    if (pl != 0) {
        win_mark_pos[1] = win_mark_pos_tbl[Game_setting.mode][4];
    } else {
        win_mark_pos[0] = win_mark_pos_tbl[Game_setting.mode][0];
    }
}



/* provisional name */
void win_mark_new_check(pl)
s16 pl;
{
    if (win_mark_phase[pl] == 0) {
        win_mark_new[pl] = 0;
        win_mark_pos_set(pl);
    }
}



/* provisional name */
void win_mark_write(s16 pl) {
    u16 (*cell)[4] = (u16 (*)[4])((SS_RAM + 0x400) + win_mark_pos[pl] * 4);
    s16* type = win_type[pl];
    s16 n;
    if (pl == 0) {
        for (n = win_mark_num[pl]; n > 0; n -= 2) {
            (*cell)[1] = win_mark_blink_tbl[*type][win_mark_phase[pl]] | ((*cell)[1] & 1);
            (*cell)[3] = win_mark_blink_tbl[*type++][win_mark_phase[pl]] | (cell[-1][3] & 1);
            cell--;
        }
    } else {
        for (n = win_mark_num[pl]; n > 0; n -= 2) {
            (*cell)[1] = win_mark_blink_tbl[*type][win_mark_phase[pl]] | ((*cell)[1] & 1);
            (*cell)[3] = win_mark_blink_tbl[*type++][win_mark_phase[pl]] | ((*cell)[3] & 1);
            cell++;
        }
    }
}

/* provisional name */
u32 win_mark_all_write(u32 pl)
{
    u16 (*cell)[4];
    s16* type;
    s16 n;

    win_mark_phase[(s16)pl] = 0;
    win_mark_pos_set(pl);
    cell = (u16 (*)[4])((SS_RAM + 0x400) + win_mark_pos[(s16)pl] * 4);
    type = win_type[(s16)pl];
    if ((s16)pl == 0) {
        for (n = (Battle_Round[Play_Type] + 1) * 2; n > 0; n -= 2) {
            (*cell)[1] = win_mark_blink_tbl[*type][win_mark_phase[(s16)pl]] | ((*cell)[1] & 1);
            (*cell)[3] = win_mark_blink_tbl[*type++][win_mark_phase[(s16)pl]] | ((*cell)[-1] & 1);
            cell--;
        }
    } else {
        for (n = (Battle_Round[Play_Type] + 1) * 2; n > 0; n -= 2) {
            (*cell)[1] = win_mark_blink_tbl[*type][win_mark_phase[(s16)pl]] | ((*cell)[1] & 1);
            (*cell)[3] = win_mark_blink_tbl[*type++][win_mark_phase[(s16)pl]] | ((*cell)[3] & 1);
            cell++;
        }
    }
}



