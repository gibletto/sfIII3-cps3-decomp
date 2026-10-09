/*
 * EFFJ5.C  Effect J5: animated BG0
 *
 * effect_J5 animates BG0 by flipping between its own page and a SIMM RAM copy filled by
 * effJ5_bg_write, on the timings of effJ5_frame_tbl (started from a stage init in BG050.C).
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
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFF27.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "effj5.h"



void effect_J5_move(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_ix = 0;
        ewk->wu.char_index = 0;
        ewk->wu.cg_ctr = effJ5_frame_tbl[ewk->wu.cg_ix].timer;
        effJ5_bg_write();
        scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
        Scrn_Y_Set_R(0, effJ5_frame_tbl[ewk->wu.cg_ix].y);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 3;
                ewk->wu.cg_ctr = effJ5_frame_tbl[ewk->wu.cg_ix].timer;
                work = effJ5_frame_tbl[ewk->wu.cg_ix].slot;
                scrn_map_set_now(0, eff_bg_adrs[work].adrs);
            }
        }
        work = effJ5_frame_tbl[ewk->wu.cg_ix].y;
        work += bg_w.bgw[0].abs_y & 0x3FF;
        Scrn_Y_Set_R(0, work);
        break;
    default:
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        break;
    }
}



/* provisional name */
void effJ5_bg_write(void) {
    s16 i;
    s16 j;
    const J5_ENTRY* p;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 16; j++) {
            p = (const J5_ENTRY*)effJ5_cell_tbl[i];
            p += j;
            scroll_cell_write(i, p->a, p->b, (u32)effJ5_scrn_data);
        }
    }
}



s32 effect_J5_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 195;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[0].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[0].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    return 0;
}
