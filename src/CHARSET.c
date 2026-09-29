/*
 * CHARSET.C  Start a cg script
 *
 * set_char_move_init points a work at script `index` of character table `koc`, clears the
 * cg counters, copies the two header words of the script, resets the script work registers
 * and move-origin record, sets the attack kind for attacking works, and for players clears
 * the per-move flags (counting repeated moves for the grade). It then runs the first frame
 * with char_move. This is the standard way every object starts a new animation.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "Grade.h"
#include "CHARSET.h"



void set_char_move_init(wk, koc, index)
WORK* wk;
s16 koc;
s16 index;
{
    u32* dst;
    u32* src;
    s16 i;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = (u32*)wk->char_table[koc][index];
    dst = (u32*)&wk->cg_ctr;
    for (i = 0; i < 6; i++) {
        dst[i] = 0;
    }
    src = wk->set_char_ad;
    dst = (u32*)&wk->cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    wk->cg_ix = -wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->cmoa.koc = wk->now_koc;
    wk->cmoa.ix = wk->char_index;
    wk->cmoa.pat = 1;
    wk->cmwk[8] = 0;
    wk->cmwk[15] = 0;
    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }
    if (wk->work_id == 1) {
        ((PLW*)wk)->tc_1st_flag = 0;
        if (wk->now_koc == 4 || wk->now_koc == 5) {
            grade_add_onaji_waza(wk->id);
        }
        ((PLW*)wk)->ja_nmj_rno = 0;
    }
    wk->K5_init_flag = 1;
    char_move(wk);
}
