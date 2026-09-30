/*
 * EFFA6_INIT.C  Effect A6 work setup
 *
 * effA6_work_set fills the fixed fields of an effect A6 dialogue work (id 106, palette 0x160,
 * family 1, priority 35) for effect_A6_init in EFFA6.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "EFFA6_INIT.h"
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
