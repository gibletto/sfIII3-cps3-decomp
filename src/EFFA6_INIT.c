/*
 * EFFA6_INIT.C  Effect A6 init: pre-fight dialogue text on the VS screen
 *
 * effect_A6_init is called by the effect 76 plate for orders 0x43 / 0x44 on the VS screen.
 * It creates the connected-sprite dialogue work, records the speaking character (My_char of
 * Player_id) and the parent plate, starts a 60-frame delay and chooses which half of the
 * character's script (routine_no[5] = 0 or 32) and which x position to use from the plate side
 * and Player_id. effA6_work_set fills the fixed fields (id 106, palette 0x160, family 1,
 * priority 35). The move routine is in EFFA6.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "EFFA6_INIT.h"



s32 effect_A6_init(WORK_Other* mwk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    effA6_work_set(ewk);
    ewk->master_player = My_char[Player_id];
    ewk->my_master = (u32*)mwk;
    ewk->wu.dir_old = mwk->wu.dir_old;
    ewk->wu.routine_no[6] = 60;
    switch (ewk->wu.dir_old) {
    case 0x43:
        if (!Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }
        ewk->wu.position_x = 504;
        break;
    default:
        if (Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }
        ewk->wu.position_x = 632;
        break;
    }
    return 0;
}



/* provisional name */
void effA6_work_set(WORK* wk) {
    wk->be_flag = 1;
    wk->id = 106;
    wk->work_id = 16;
    wk->rl_flag = 0;
    wk->cgromtype = 1;
    wk->sync_suzi = 0;
    wk->my_col_mode = 0x4200;
    wk->my_col_code = 0x160;
    wk->my_family = 1;
    wk->my_priority = 35;
    wk->position_x = 0x238;
    wk->position_y = 24;
    wk->position_z = 35;
}
