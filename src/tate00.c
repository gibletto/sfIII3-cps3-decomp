/*
 * TATE00.C  Stage background control task
 *
 * TATE00 is the per-frame stage BG entry used during fights (and by the debug fight setups):
 * ta0_init00 sets a random compel_flag and allocates the match scene, ta0_init01 runs
 * akebono_initialize and ta0_init02 loads the stage colours, each running the stage's own
 * handler from ta_move_tbl; ta0_move then calls that handler every frame and counts down the
 * screen quake timers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "PLS02.h"
#include "tate00.h"



void TATE00(void) {
    void (*jump_tbl[4])() = { ta0_init00, ta0_init01, ta0_init02, ta0_move };
    jump_tbl[bg_w.bg_routine]();
}



void ta0_init00(void) {
    bg_w.bg_routine++;
    bg_w.compel_flag = random_16_com();
    bg_w.compel_flag &= 3;
    bg_initialize();
}



void ta0_init01(void) {
    bg_w.bg_routine++;
    akebono_initialize();
    ta_move_tbl[bg_w.bg_index]();
}



void ta0_init02(void) {
    bg_w.bg_routine++;
    bg_color_trans();
    ta_move_tbl[bg_w.bg_index]();
}



void ta0_move(void) {
    ta_move_tbl[bg_w.bg_index]();
    if (bg_w.quake_x_index > 0) {
        bg_w.quake_x_index--;
    }
    if (bg_w.quake_y_index > 0) {
        bg_w.quake_y_index--;
    }
}
