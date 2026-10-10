/*
 * BG_SUB.C  Stage background subroutines: scrolling, zoom, family set, cell writers
 *
 * Shared machinery used by every stage routine. Scrolling: check_cg_zoom and the scr_1x_2x rules
 * decide how the main layer follows the two players; bg_base_x_move_check, bg_x/y_move_check and
 * remake_x_mvstep move the layers; the chase routines handle requested scrolls. Tile writers blit
 * 16x16 and 8x16 cells (plain, flipped, wrapped) and the HUD rectangle; bg_work_clear and
 * compel_bg_init_position reset the display. A few debug helpers step through the stages from the
 * controls.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_5.h"
#include "bg_sub.h"




/* provisional name */
s32 bg_debug_stage_change(void) {
    u16 sw1;
    u16 sw2;
    u16 ret = 0;
    sw1 = p1sw_0 & ~p1sw_1;
    sw2 = p2sw_0 & ~p2sw_1;
    if (exsw_1 & 0x80) {
        if ((sw1 & 0x80) || (sw2 & 0x80)) {
            bg_w.stage++;
            ret = 1;
            if (bg_w.stage > 22) {
                bg_w.stage = 0;
            }
        }
        if ((sw1 & 0x100) || (sw2 & 0x100)) {
            bg_w.stage--;
            ret = 1;
            if (bg_w.stage < 0) {
                bg_w.stage = 22;
            }
        }
        if ((sw1 & 0x200) || (sw2 & 0x200)) {
            bg_w.area++;
            ret = 1;
            if (bg_w.area > 2) {
                bg_w.area = 0;
            }
        }
    }
    return ret;
}



/* provisional name */
void bg_free_work_blocks(void) {
    s16 i;
    simmram_block_free_10(scr_cg_c_no);
    for (i = 0; i < bg_w.scno; i++) {
        simmram_block_free_40(bg_w.bgw[i].bg_adrs_c_no);
        sprite_list_clear(i);
        if (bg_w.bgw[i].zuubun != 0) {
            simmram_block_free_40(bg_w.bgw[i].suzi_c_no);
        }
    }
}



/* provisional name */
void bg_debug_scroll_layers(void) {
    BGW* bgw;
    s32 dx;
    s32 dy;
    s16 i;
    for (i = 0; i < 7; i++) {
        if (i != 4) {
            bgw = &bg_w.bgw[i];
            if (p1sw_0 & 0x10) {
                dx = bgw->speed_x * 2;
                dy = bgw->speed_y * 2;
            } else {
                dx = bgw->speed_x;
                dy = bgw->speed_y;
            }
            if (p1sw_0 & 4) {
                Bg_mv_tw_appoint(i, -dx, 0);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 8) {
                Bg_mv_tw_appoint(i, dx, 0);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 1) {
                Bg_mv_tw_appoint(i, 0, dy);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            if (p1sw_0 & 2) {
                Bg_mv_tw_appoint(i, 0, -dy);
                bgw->hos_xy[0].cal = bgw->xy[0].cal;
            }
            sync_fam_set3(i);
        }
    }
}



/* provisional name */
void bg_test_stage_select(void) {
    u16 sw;
    s16 changed;
    s8 save_27;
    s8 save_entry;
    changed = 0;
    sw = ~p1sw_1 & p1sw_0;
    if (sw & 0x80) {
        bg_select_no++;
        if (bg_select_no > 16) {
            bg_select_no = 0;
        }
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
        changed = 1;
    }
    if (sw & 0x100) {
        bg_select_no--;
        if (bg_select_no < 0) {
            bg_select_no = 16;
        }
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
        changed = 1;
    }
    if (changed) {
        System_all_clear_Wait();
        pcon_rno[3] = 0;
        pcon_rno[2] = 0;
        pcon_rno[1] = 0;
        pcon_rno[0] = 0;
        save_27 = bg_test_flag;
        save_entry = bg_select_no;
        bg_work_clear();
        bg_select_no = save_entry;
        bg_test_flag = save_27;
    }
}



/* provisional name */
void bg_layers_off(void) {
    s16 i;

    for (i = 0; i < bg_w.scno; i++) {
        if ((scrn_reg_w[i].ctrl & 0x8000) == 0) {
            continue;
        }
        Bg_Off_W(1 << i);
    }
    if ((scrn_reg_w[3].ctrl & 0x8000) != 0) {
        Bg_Off_W(8);
    }
}
