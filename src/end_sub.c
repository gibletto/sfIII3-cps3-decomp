/*
 * END_SUB.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads
 *
 * Card dispenser bookkeeping for the regions that give out cards: card_win_check counts wins per
 * player and requests a card when the required wins are reached; card_msg_disp blinks the "card won"
 * and "no cards" messages. cd_keep_spinning_tick keeps the CD drive spinning and cd_error_fatal_hang
 * shows the no-drive / no-disc message and stops the machine. staff_roll_main scrolls the staff
 * credits after an ending, with a button skip check. debug_play07..13 are debug-menu fight setups
 * that initialise a match with fixed characters and stage and run the battle loop.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Manage.h"
#include "manage_2.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "entry_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "color3rd.h"
#include "end_sub.h"
#include "cps3.h"

#pragma inline(card_pl_work_clear)



/* provisional name */
void card_pl_work_clear(s16 pl) {
    memset(&card_pl_w[pl], 0, 12);
}

/* provisional name */
u32 card_work_clear(void)
{
    memset((u8 *)&card_pl_w[0], 0, sizeof(SELPL));
    return (u32)memset((u8 *)&card_pl_w[1], 0, sizeof(SELPL));
}

/* provisional name */
u32 card_win_check(s16 vs_mode)
{
    SELPL *win;
    s8 need;
    s32 ret;

    if (!Card_Dispenser) {
        return 0;
    }
    ret = Country;
    if (ret != 6 && ret != 5) {
        return (u32)ret;
    }
    if (!Play_Type) {
        win = (SELPL *)((u8 *)card_pl_w + (s8)(Winner_id * sizeof(SELPL)));
        if (!vs_mode) {
            need = Win_Point_Com - Continue_Coin[Winner_id];
            if (need < 0) {
                need = 1;
            }
            win->wins += 1;
            if (!win->cleared && need <= win->wins) {
                win->cleared += 1;
                card_out_req += 1;
                win->flag = 1;
            }
        } else {
            win->cleared += 1;
            card_out_req += 1;
            win->flag = 1;
        }
        return (u32)memset((u8 *)card_pl_w + (s8)(Loser_id * sizeof(SELPL)), 0, sizeof(SELPL));
    }
    memset((u8 *)card_pl_w + (s8)(Loser_id * sizeof(SELPL)), 0, sizeof(SELPL));
    win = (SELPL *)((u8 *)card_pl_w + (s8)(Winner_id * sizeof(SELPL)));
    win->vs_wins += 1;
    ret = win->cleared;
    if (!ret) {
        if ((ret = win->vs_wins) >= Win_Point_Human) {
            win->cleared += 1;
            card_out_req += 1;
            win->flag = 1;
            ret = 1;
        }
    }
    return (u32)ret;
}


/* provisional name */
void card_msg_disp(void) {
    SELPL* rec;
    if (!Card_Dispenser) {
        return;
    }
    if (Country != 6 && Country != 5) {
        return;
    }
    rec = &card_pl_w[Winner_id];
    switch (rec->card_state) {
    case 0:
        if (card_out_busy != 0 || card_empty_flag != -1) {
            break;
        }
        rec->card_state++;
        card_pl_w[Winner_id].blink = 0;
    case 1:
        switch (card_pl_w[Winner_id].blink & 31) {
        case 0:
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_mes);
            break;
        case 15:
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_clr_mes);
            break;
        }
        if (card_out_busy == 0 && card_empty_flag != -1) {
            card_pl_w[Winner_id].msg_state = 0;
            card_pl_w[Winner_id].card_state = 0;
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_clr_mes);
            return;
        }
        card_pl_w[Winner_id].blink++;
        return;
    }
    switch (rec->msg_state) {
    case 0:
        if (rec->flag == 0) {
            break;
        }
        rec->msg_state++;
        card_pl_w[Winner_id].msg_timer = -32;
        card_msg_cnt = -1;
    case 1:
        card_msg_cnt++;
        if (--card_pl_w[Winner_id].msg_timer == 0) {
            card_pl_w[Winner_id].msg_state = card_msg_cnt = 0;
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_clr_mes);
            card_pl_w[Winner_id].flag = 0;
            break;
        }
        switch (card_msg_cnt & 63) {
        case 0:
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_mes);
            break;
        case 31:
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_clr_mes);
            break;
        }
        break;
    }
}



