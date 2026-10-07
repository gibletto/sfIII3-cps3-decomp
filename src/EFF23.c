/*
 * EFF23.C  Effect 23: background cell animation (bg100)
 *
 * effect_23_init records the BG0 character block and allocates a spare block in SIMM memory.
 * effect_23_move writes the animation cells into the blocks, then cycles through the four
 * frames of eff23_anm_tbl by switching the BG0 character pointer and y scroll, and frees the
 * spare block when it ends. Called from bg100.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "EFF23.h"



void effect_23_move(WORK_Other_CONN* ewk) {
    s16 i;
    s16 j;
    s16 slot;
    const EFF23_CELL_REQ* cell;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.char_index = ewk->wu.cg_ix = 0;
        ewk->wu.cg_ctr = eff23_anm_tbl[ewk->wu.cg_ix].timer;
        for (i = 0; i < 2; i++) {
            cell = eff23_cell_tbl[i];
            for (j = 0; j < 16; j++) {
                scroll_cell_write(i, cell[j].a, cell[j].b, eff23_scrn_data);
            }
        }
        scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
        Scrn_Y_Set_R(0, eff23_anm_tbl[ewk->wu.cg_ix].y);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 3;
                ewk->wu.cg_ctr = eff23_anm_tbl[ewk->wu.cg_ix].timer;
                slot = eff23_anm_tbl[ewk->wu.cg_ix].slot;
                scrn_map_set_now(0, eff_bg_adrs[slot].adrs);
            }
        }
        Scrn_Y_Set_R(0, eff23_anm_tbl[ewk->wu.cg_ix].y + (bg_w.bgw[0].abs_y & 0x3FF));
        break;
    default:
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        break;
    }
}



s32 effect_23_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 23;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[0].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[0].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    return 0;
}
