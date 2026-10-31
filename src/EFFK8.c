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
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFK8.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the scaled pattern */
#define R0_MOVE         1       /* show while the player's move lasts */
#define R0_KILL         2       /* put the work back */
#define R0_DEAD         3       /* (default) killed: put the work back */



void effect_K8_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init(&ewk->wu, 0, 0x8F);
    case R0_MOVE:
        if (ewk->wu.dead_f != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_DEAD;
            break;
        }
        if (ewk->wu.dir_old != mwk->now_koc || ewk->wu.dir_step != mwk->char_index) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_KILL;
            break;
        }
        char_move(&ewk->wu);
        ewk->wu.position_x = bg_w.bgw[1].position_x + bg_w.pos_offset - 200;
        ewk->wu.position_y = bg_w.bgw[1].position_y + 200;
        disp_seraph_cells(&ewk->wu);
        break;
    case R0_KILL:
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
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}
