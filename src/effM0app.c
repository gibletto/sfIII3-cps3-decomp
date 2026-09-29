/*
 * EFFM0APP.C  Stage animal creation
 *
 * effect_M0_init(pl_rl, animal_type) allocates a stage animal effect (M0, id 220) of the given
 * type, using the etc2 character table and facing the direction passed in. The animal's
 * behaviour is run by effect_M0_move in EFFM0. Called by the fighter appearance routines
 * in APPEAR.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effM0app.h"



/* provisional name */
s32 effect_M0_init(u8 pl_rl, u8 animal_type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 220;
    ewk->wu.work_id = 16;
    ewk->wu.type = animal_type;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 61;
    ewk->wu.rl_flag = pl_rl;
    return 0;
}
