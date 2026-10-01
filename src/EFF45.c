/*
 * EFF45.C  Effect 45: background cell animation (bg050)
 *
 * effect_45_init keeps the BG0 character block and allocates a spare one. effect_45_move
 * writes the animation cells, cycles through the four frames of eff45_anm_tbl by switching
 * the character pointer and y scroll, and frees the spare block when it ends.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "sys_test.h"
#include "EFFECT.h"
#include "sys_config.h"
#include "EFF45.h"



void effect_45_move(WORK_Other_CONN* ewk) {
    s32 i;
    s32 j;
    s32 slot;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_ix = 0;
        ewk->wu.char_index = 0;
        ewk->wu.cg_ctr = eff45_anm_tbl[ewk->wu.cg_ix].timer;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 16; j++) {
                scroll_cell_write(i, eff45_cell_tbl[i][j].a, eff45_cell_tbl[i][j].b, eff45_scrn_data);
            }
        }
        scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
        Scrn_Y_Set_R(0, eff45_anm_tbl[ewk->wu.cg_ix].y);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.cg_ctr--;
            if (ewk->wu.cg_ctr <= 0) {
                ewk->wu.cg_ix++;
                ewk->wu.cg_ix &= 3;
                ewk->wu.cg_ctr = eff45_anm_tbl[ewk->wu.cg_ix].timer;
                slot = eff45_anm_tbl[ewk->wu.cg_ix].slot;
                scrn_map_set(0, eff_bg_adrs[slot].adrs);
            }
        }
        Scrn_Y_Set_W(0, eff45_anm_tbl[ewk->wu.cg_ix].y + (bg_w.bgw[0].abs_y & 0x3FF));
        break;
    default:
        push_effect_work(&ewk->wu);
        simmram_block_free_40(eff_bg_adrs[1].no);
        break;
    }
}



s32 effect_45_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 45;
    ewk->wu.work_id = 16;
    eff_bg_adrs[0].no = bg_w.bgw[0].bg_adrs_c_no;
    eff_bg_adrs[0].adrs = (u32)bg_w.bgw[0].bg_address;
    eff_bg_adrs[1].no = simmram_big_page_alloc_40(1);
    eff_bg_adrs[1].adrs = simmram_slot_addr(eff_bg_adrs[1].no);
    return 0;
}
