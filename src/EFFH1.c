/*
 * EFFH1.C  Effect H1: ending falling objects
 *
 * effect_H1_init (called from end_4.c) creates eight end_char_table objects whose start
 * position, priority, pattern and first delay come from effh1_data_tbl. effect_H1_move runs
 * eff_h1_move while the ending scene is unchanged: after its delay the object appears relative
 * to BG1 and plays its pattern while it stays in range; objects 0-4 then restart from their home
 * position after a random wait from effh1_wait_timer, the others stop. Once the ending scene
 * (end_w.r_no_2) moves on they are no longer moved or drawn.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFH1.h"

/* routine_no[0] */
#define R0_MOVE         0       /* run the object while the scene lasts */
#define R0_END          1       /* one more frame */

/* routine_no[1] */
#define R1_WAIT         0       /* count the delay down, then appear */
#define R1_MOVE         1       /* animate while in range */
#define R1_STOP         99      /* the scene has moved on */

void eff_h1_move(WORK_Other* ewk);



void effect_H1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_MOVE:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[1] = R1_STOP;
            break;
        }
        eff_h1_move(ewk);
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void eff_h1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_WAIT:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].xy[0].disp.pos;
        }
        break;
    case R1_MOVE:
        char_move(&ewk->wu);
        if (range_x_check(&ewk->wu) != 0) {
            if (ewk->wu.xyz[1].disp.pos > -8) {
                disp_pos_trans_entry(ewk);
                return;
            }
        }
        if ((u8)ewk->wu.type > 4) {
            ewk->wu.routine_no[0]++;
        } else {
            ewk->wu.routine_no[1] = R1_WAIT;
            ewk->wu.disp_flag = 0;
            {
                u16 work = random_16_com();
                work &= 7;
                ewk->wu.old_rno[0] = effh1_wait_timer[(s16)work];
            }
            ewk->wu.xyz[0].disp.pos = effh1_data_tbl[ewk->wu.type][0];
            ewk->wu.xyz[1].disp.pos = effh1_data_tbl[ewk->wu.type][1];
        }
        break;
    }
}



s32 effect_H1_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = &effh1_data_tbl[0][0];
    for (i = 0; i < 8; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 171;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.old_rno[6] = end_w.r_no_2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = end_char_table;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 32;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
    }
    return 0;
}
