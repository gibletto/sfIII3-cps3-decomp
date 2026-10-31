/*
 * EFFB2.C  Round-start FIGHT call sequence (effect B2)
 *
 * Controls the start-of-round call. effect_B2_move steps through timed states: it picks a
 * call voice from effb2_sound_tbl, starts effect I6 and opens it with a vertical zoom,
 * waits, starts effect L5 and zooms it in, waits for the rf_b2_flag handshakes, runs
 * fight_col_chg_sub (a colour flash through fight_col_move_tbl) and finally sets Next_Step
 * so the round can begin. b3_Break_Into_check aborts the sequence when Break_Into is set.
 * effect_B2_init is called by the game manager (Manage.c) at the start of each round. It loads
 * the round-call graphics, resets the BG3 scroll to the screen origin, sets the BG families
 * (ake_Family_Set) and decides from Battle_Round and Round_num whether this is the final round
 * (type 1) or a normal round (type 0). It then spawns effect B3, the display child that shows
 * the round number and FIGHT (EFFB4.C).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFI5.h"
#include "effi6.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "effb2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "effb3.h"
#include "EFFB4.h"

/* routine_no[0] */
#define R0_INIT         0       /* set up, pick the call voice */
#define R0_ROUND        1       /* short wait, then start the line */
#define R0_ROUND_OPEN   2       /* open the round display */
#define R0_ROUND_HOLD   3       /* hold the round display */
#define R0_FIGHT        4       /* short wait, then start the stamp */
#define R0_FIGHT_OPEN   5       /* open FIGHT */
#define R0_STAMP        6       /* wait for the stamp to land */
#define R0_FLASH        7       /* flash FIGHT's colours */
#define R0_FIGHT_OUT    8       /* wait for FIGHT to vanish */
#define R0_GO           9       /* let the round start */
#define R0_END          10      /* one more frame */
#define R0_BREAK        99      /* broken into: one frame */
#define R0_BREAK_END    100     /* one more frame */

/* routine_no[1]: FIGHT colour flash */
#define R1_INIT         0       /* start the colour flash */
#define R1_FLASH        1       /* step through the flash colours */
#define R1_HOLD         2       /* hold, then report done */
#define R1_DRAW         3       /* draw only */



s16 rf_b2_flag;  /* 02068C24 */
s16 b2_curr_no;  /* 02068C26 */


void effect_B2_move(WORK_Other* ewk) {
    s16 work;
    b3_Break_Into_check(ewk);
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.old_rno[0] = ewk->wu.old_rno[1] = ewk->wu.old_rno[2] = 0;
        rf_b2_flag = 0;
        b2_curr_no = 0;
        ewk->wu.hit_stop = 2;
        work = random_16_com();
        work &= 3;
        ewk->wu.dir_old = effb2_sound_tbl[work];
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    case R0_ROUND:
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.my_mr.size.y = 0;
            effect_I6_init(ewk);
        }
        break;
    case R0_ROUND_OPEN:
        ewk->wu.my_mr.size.y += 10;
        if (ewk->wu.my_mr.size.y >= 63) {
            ewk->wu.routine_no[0]++;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.hit_stop = 64;
            rf_b2_flag = 0;
        }
        break;
    case R0_ROUND_HOLD:
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0]++;
            b2_curr_no = 0;
            rf_b2_flag = 0;
            ewk->wu.hit_stop = 10;
        }
        break;
    case R0_FIGHT:
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0]++;
            rf_b2_flag = 0;
            effect_L5_init(ewk);
        }
        break;
    case R0_FIGHT_OPEN:
        ewk->wu.my_mr.size.y += 6;
        if (ewk->wu.my_mr.size.y >= 63) {
            ewk->wu.routine_no[0]++;
            ewk->wu.my_mr.size.y = 63;
        }
        break;
    case R0_STAMP:
        if (rf_b2_flag) {
            ewk->wu.routine_no[0]++;
            rf_b2_flag = 0;
        }
        break;
    case R0_FLASH:
        if (fight_col_chg_sub(ewk) != 0) {
            ewk->wu.routine_no[0]++;
            rf_b2_flag = 0;
            ewk->wu.routine_no[1] = R1_INIT;
        }
        break;
    case R0_FIGHT_OUT:
        if (rf_b2_flag) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_GO:
        Next_Step = 1;
        ewk->wu.routine_no[0]++;
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    case R0_BREAK:
        ewk->wu.routine_no[0]++;
        break;
    case R0_BREAK_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 b3_Break_Into_check(WORK_Other* ewk) {
    if (Break_Into) {
        ewk->wu.routine_no[0] = R0_BREAK;
        return 1;
    }
    return 0;
}



s32 fight_col_chg_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_INIT:
        ewk->wu.routine_no[1]++;
        ewk->wu.vital_new = 0;
        ewk->wu.hit_stop = 1;
        break;
    case R1_FLASH:
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.hit_stop = 1;
            ewk->wu.vital_new++;
            if (ewk->wu.vital_new > 17) {
                ewk->wu.routine_no[1]++;
                ewk->wu.hit_stop = 6;
            } else {
                ewk->wu.extra_col = fight_col_move_tbl[ewk->wu.vital_new];
                ewk->wu.extra_col += 0x1E0;
                ewk->wu.extra_col |= 0x2000;
            }
        }
        break;
    case R1_HOLD:
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.routine_no[1]++;
            return 1;
        }
    case R1_DRAW:
        disp_pos_trans_entry5(ewk);
        break;
    }
    return 0;
}


s32 effect_B2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x70;
    ewk->wu.work_id = 0x10;
    ewk->wu.my_family = 4;
    load_char_gfx(0xA7F8, 1);
    bg_w.bgw[3].xy[0].cal = bg_w.bgw[3].wxy[0].cal = 0x100000;
    bg_w.bgw[3].xy[1].cal = bg_w.bgw[3].wxy[1].cal = 0;
    bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    ake_Family_Set();
    switch (Battle_Round[Play_Type]) {
    case 0:
        ewk->wu.type = 0;
        break;
    case 1:
        if (Round_num == 2) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    case 2:
        if (Round_num == 4) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    case 3:
        if (Round_num == 6) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    }
    effect_B3_init(ewk);
    return 0;
}
