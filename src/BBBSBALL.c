/*
 * BBBSBALL.C  Bonus stage: ball launcher
 *
 * effect_I8_init creates one bonus-stage ball work (effect id 0xBC) owned by the thrower,
 * taking its launch delay, speed indices and x offset from one row of ball data.
 * bbbs_ball_set walks a BBBSTable entry and creates one ball per row, accumulating the
 * launch delays so the balls of a volley come out in sequence.
 * Called from bbbs_com_execute (BBBSCOM) when the thrower's throw animation signals.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "BBBSBALL.h"



s32 effect_I8_init(PLW* wk, s16 top, const s16* sptr) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xBC;
    ewk->wu.work_id = 2;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.dm_vital = wk->wu.my_col_code;
    ewk->wu.dir_timer = top;
    ewk->wu.dir_step = sptr[1];
    ewk->wu.dir_old = sptr[2];
    ewk->wu.next_x = sptr[3];
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = (u32*)wk->wu.target_adrs;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = 0x1C;
    return 0;
}



/* provisional name */
void bbbs_ball_set(PLW* wk, const BBBSTable* dadr) {
    s16 i;
    s16 ttime = 0;
    for (i = 0; i < dadr->kosuu; i++) {
        ttime += dadr->bbdat[i][0];
        effect_I8_init(wk, ttime, &dadr->bbdat[i][0]);
    }
}
