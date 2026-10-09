/*
 * EFF08.C  Animated background layer (effect 08)
 *
 * Animates the BG1 scroll layer by flipping its character page between the layer's own
 * map and a second copy built in a SIMM RAM slot, and by moving its Y scroll per frame.
 * effect_08_init records the two page addresses (the second allocated with
 * simmram_big_page_alloc_40); effect_08_build_tile_grid writes the 2x16 cell grid into it.
 * effect_08_move steps through eff08_anm_tbl, and at the end of each 8-frame cycle picks a
 * random number of extra loops through eff08_anm2_tbl; the slot is freed on exit.
 * Started from the BG030 base-layer init (bg0301_init).
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
#include "PLS02.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "eff08.h"



void effect_08_move(WORK_Other* ewk) {
    s8 rounds;
    s16 slot;
    s16 pos_y;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_ix = 0;
        ewk->wu.char_index = 0;
        ewk->wu.cg_ctr = eff08_anm_tbl[(s8)ewk->wu.cg_ix].timer;
        effect_08_build_tile_grid(ewk);
        scrn_map_set_now(1, (u32)bg_w.bgw[1].bg_address);
        Scrn_Y_Set_R(1, eff08_anm_tbl[(s8)ewk->wu.cg_ix].y);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 7;
                if (!ewk->wu.cg_ix) {
                    rounds = random_16_com();
                    rounds = eff08_loop_tbl[rounds];
                } else {
                    rounds = 0;
                }
                if (rounds) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.dir_step = rounds;
                    ewk->wu.cg_ctr = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].timer;
                    slot = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].slot;
                    scrn_map_set_now(1, eff_bg_adrs[slot].adrs);
                    pos_y = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].y;
                    pos_y += bg_w.bgw[1].abs_y & 0x3FF;
                    Scrn_Y_Set_R(1, pos_y);
                    return;
                }
                ewk->wu.cg_ctr = eff08_anm_tbl[(s8)ewk->wu.cg_ix].timer;
                slot = eff08_anm_tbl[(s8)ewk->wu.cg_ix].slot;
                scrn_map_set_now(1, eff_bg_adrs[slot].adrs);
            }
        }
        pos_y = eff08_anm_tbl[(s8)ewk->wu.cg_ix].y;
        pos_y += bg_w.bgw[1].abs_y & 0x3FF;
        Scrn_Y_Set_R(1, pos_y);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 3;
                if (!ewk->wu.cg_ix) {
                    ewk->wu.dir_step--;
                    if (ewk->wu.dir_step <= 0) {
                        ewk->wu.routine_no[0] = 1;
                        ewk->wu.cg_ctr = eff08_anm_tbl[(s8)ewk->wu.cg_ix].timer;
                        slot = eff08_anm_tbl[(s8)ewk->wu.cg_ix].slot;
                        scrn_map_set_now(1, eff_bg_adrs[slot].adrs);
                        pos_y = eff08_anm_tbl[(s8)ewk->wu.cg_ix].y;
                        pos_y += bg_w.bgw[1].abs_y & 0x3FF;
                        Scrn_Y_Set_R(1, pos_y);
                        break;
                    }
                }
                ewk->wu.cg_ctr = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].timer;
                slot = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].slot;
                scrn_map_set_now(1, eff_bg_adrs[slot].adrs);
            }
        }
        pos_y = eff08_anm2_tbl[(s8)ewk->wu.cg_ix].y;
        pos_y += bg_w.bgw[1].abs_y & 0x3FF;
        Scrn_Y_Set_R(1, pos_y);
        break;
    default:
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        break;
    }
}



/* provisional name */
void effect_08_build_tile_grid()
{
    const GRID_CELL* cell;
    s16 i;
    s16 j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 16; j++) {
            cell = (const GRID_CELL*)eff08_cell_tbl[i];
            cell += j;
            scroll_cell_write(i, cell->a, cell->b, (u32)eff08_scrn_data);
        }
    }
}



s32 effect_08_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 8;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[1].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[1].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    return 0;
}
