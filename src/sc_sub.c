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
        win_mark_timer[pl] = (*(const s16(*)[])((&win_mark_blink_tbl[0][1])))[win_mark_phase[pl]];
        if (win_mark_phase[pl] == 2) {
            win_mark_phase[pl] = 0;
        } else {
            win_mark_phase[pl] = win_mark_phase[pl] + 2;
        }
        return;
    default:
        if (win_mark_new[pl] && win_mark_phase[pl ^ 1] == 0) {
            win_mark_rno[pl] = 1;
            win_mark_new[pl] = 0;
            win_mark_timer[pl] = 1;
            win_mark_phase[pl] = 0;
            win_mark_pos_set(pl);
        }
        return;
    }
}



/* provisional name */
void win_mark_pos_set(s16 pl) {
    win_mark_num[pl] = PL_Wins[pl] * 2;
    if (pl != 0) {
        win_mark_pos[1] = win_mark_pos_tbl[(*&Game_setting).mode][4];
    } else {
        win_mark_pos[0] = win_mark_pos_tbl[(*&Game_setting).mode][0];
    }
}



/* provisional name */
void win_mark_new_check(s16 pl) {
    if (win_mark_phase[pl] == 0) {
        win_mark_new[pl] = 0;
        win_mark_pos_set(pl);
    }
}



/* provisional name */
void win_mark_write(s16 pl) {
    u32 cell = (SS_RAM + 0x400) + win_mark_pos[pl] * 4;
    s16* type = win_type[pl];
    s16* phase = &win_mark_phase[pl];
    s16 n = win_mark_num[pl];
    if (pl == 0) {
        for (; n > 0; n -= 2) {
            *(u16*)(cell + 2) = win_mark_blink_tbl[*type][*phase] | (*(u16*)(cell + 2) & 1);
            *(u16*)(cell + 6) = win_mark_blink_tbl[*type++][*phase] | (*(u16*)(cell - 2) & 1);
            cell -= 8;
        }
    } else {
        for (; n > 0; n -= 2) {
            *(u16*)(cell + 2) = win_mark_blink_tbl[*type][*phase] | (*(u16*)(cell + 2) & 1);
            *(u16*)(cell + 6) = win_mark_blink_tbl[*type++][*phase] | (*(u16*)(cell + 6) & 1);
            cell += 8;
        }
    }
}

/* provisional name */
u32 win_mark_all_write(u32 pl)
{
    s16 side;
    s16 count;
    s16 n;
    u32 rv;
    u16 *cell;
    s16 *type;

    side = (s16)pl;
    win_mark_phase[side] = 0;
    rv = ((u32 (*)())win_mark_pos_set)(pl);
    cell = (u16 *)((SS_RAM + 0x400) + win_mark_pos[side] * 4);
    if (!side) {
        count = Battle_Round[Play_Type] + 1;
        n = count * 2;
        rv = 0;
        type = win_type[side];
        if (count != 0) {
            do {
                n -= 2;
                cell[1] = win_mark_blink_tbl[*type][win_mark_phase[side]] | (cell[1] & 1);
                rv = (((s16 *)cell)[-1] & 1) | win_mark_blink_tbl[*type][win_mark_phase[side]];
                cell[3] = rv;
                cell -= 4;
                type++;
            } while (n > 0);
        }
    } else {
        count = Battle_Round[Play_Type] + 1;
        n = count * 2;
        type = win_type[side];
        if (count != 0) {
            do {
                n -= 2;
                cell[1] = win_mark_blink_tbl[*type][win_mark_phase[side]] | (cell[1] & 1);
                rv = ((s16 *)cell)[3] & 1;
                cell[3] = win_mark_blink_tbl[*type][win_mark_phase[side]] | rv;
                cell += 4;
                type++;
            } while (n > 0);
        }
    }
    return rv;
}



