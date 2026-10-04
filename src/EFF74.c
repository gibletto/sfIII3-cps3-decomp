/*
 * EFF74.C  Effect 74: background cell animation with random patterns (bg130)
 *
 * effect_74_init allocates two spare BG character blocks. eff74_cell_trans loads the 48
 * animation cells; effect_74_move picks random patterns (eff74_pattern_set) and steps
 * through their frames by switching the BG1 character pointer and y scroll.
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
#include "aboutspr.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "EFF74.h"



void effect_74_move(WORK_Other* ewk) {
    const EFF74_FRAME* frame;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        eff74_cell_trans();
        eff74_pattern_set(ewk);
        scrn_map_set(1, eff_bg_adrs[ewk->wu.old_rno[2]].adrs);
        Scrn_Y_Set_R(1, ewk->wu.old_rno[1]);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                if (ewk->wu.cg_ix >= ewk->wu.old_rno[4]) {
                    ewk->wu.cg_ix = 0;
                    ewk->wu.char_index--;
                    if (ewk->wu.char_index <= 0) {
                        eff74_pattern_set(ewk);
                    } else {
                        ewk->wu.old_rno[2] = eff74_anim_tbl[(s8)ewk->wu.old_rno[0]].frames->slot;
                        ewk->wu.old_rno[1] = eff74_anim_tbl[(s8)ewk->wu.old_rno[0]].frames->y;
                        ewk->wu.cg_ctr = eff74_anim_tbl[(s8)ewk->wu.old_rno[0]].frames->timer;
                    }
                } else {
                    frame = &eff74_anim_tbl[(s8)ewk->wu.old_rno[0]].frames[ewk->wu.cg_ix];
                    ewk->wu.old_rno[2] = frame->slot;
                    ewk->wu.old_rno[1] = frame->y;
                    ewk->wu.cg_ctr = frame->timer;
                }
            }
            scrn_map_set(1, eff_bg_adrs[ewk->wu.old_rno[2]].adrs);
        }
        Scrn_Y_Set_W(1, ewk->wu.old_rno[1] + (bg_w.bgw[1].abs_y & 0x3FF));
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        simmram_block_free_40(eff_bg_adrs[2].no);
        break;
    }
}



/* provisional name */
void eff74_pattern_set(WORK_Other* ewk) {
    ewk->wu.cg_ix = 0;
    ewk->wu.old_rno[0] = random_16_com() & 3;
    ewk->wu.old_rno[2] = eff74_anim_tbl[ewk->wu.old_rno[0]].frames->slot;
    ewk->wu.old_rno[1] = eff74_anim_tbl[ewk->wu.old_rno[0]].frames->y;
    ewk->wu.cg_ctr = eff74_anim_tbl[ewk->wu.old_rno[0]].frames->timer;
    ewk->wu.char_index = eff74_anim_tbl[ewk->wu.old_rno[0]].char_ix[ewk->wu.old_rno[0]];
    ewk->wu.old_rno[4] = eff74_anim_tbl[ewk->wu.old_rno[0]].count;
}



/* provisional name */
void eff74_cell_trans(void) {
    s32 i;
    s32 j;
    const CELL_REQ* p;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            p = &eff74_cell_tbl[i][j];
            scroll_cell_write(i, p->a, p->b, eff74_scrn_data);
        }
    }
}



s32 effect_74_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 74;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[1].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[1].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    eff_bg_adrs[2].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[2].adrs = simmram_slot_addr(eff_bg_adrs[2].no);
    return 0;
}
