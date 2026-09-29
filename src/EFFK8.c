/*
 * EFFK8.C  Effect K8: scaled screen overlay tied to a player animation
 *
 * Effect K8 (id 208) is created by effect_K8_init for a player work. It remembers the player's
 * current animation (now_koc / char_index) and stays alive only while the player keeps playing
 * that animation.
 * effect_K8_move plays char 0x8F from plef_char_table at a fixed place relative to the BG1
 * scroll position (200 left, 200 down), drawn through disp_seraph_cells with the scaling (mr)
 * flag set at full size, and frees itself when the animation changes or the work is killed.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFK8.h"



void effect_K8_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init(&ewk->wu, 0, 0x8F);
    case 1:
        if (ewk->wu.dead_f != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }
        if (ewk->wu.dir_old != mwk->now_koc || ewk->wu.dir_step != mwk->char_index) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        char_move(&ewk->wu);
        ewk->wu.position_x = bg_w.bgw[1].position_x + bg_w.pos_offset - 200;
        ewk->wu.position_y = bg_w.bgw[1].position_y + 200;
        disp_seraph_cells(&ewk->wu);
        break;
    case 2:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_K8_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 208;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x140;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = plef_char_table;
    return 0;
}
