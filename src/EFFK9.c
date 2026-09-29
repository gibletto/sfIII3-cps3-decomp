/*
 * EFFK9.C  Effect K9: screen overlay tied to a player animation
 *
 * Effect K9 (id 209) is the companion of effect K8: effect_K9_init records the owning player's
 * current animation (now_koc / char_index) and uses plef_char_table graphics.
 * effect_K9_move plays char 0x90 at a fixed offset from the BG1 scroll position and draws it with
 * sort_push_request for as long as the player remains in that animation and the effect's own
 * animation has not ended, then frees the work.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFK9.h"



void effect_K9_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_priority = ewk->wu.position_z = 32;
        set_char_move_init(&ewk->wu, 0, 0x90);
    case 1:
        if (ewk->wu.dead_f == 0 && ewk->wu.dir_old == mwk->now_koc && ewk->wu.dir_step == mwk->char_index) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type != 0xFF) {
                ewk->wu.position_x = bg_w.pos_offset + bg_w.bgw[1].position_x - 232;
                ewk->wu.position_y = bg_w.bgw[1].position_y + 208;
                sort_push_request(ewk);
                return;
            }
        }
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        return;
    default:
    case 2:
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_K9_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 209;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x148;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = plef_char_table;
    return 0;
}
