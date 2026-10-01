/*
 * EFF85.C  Effect 85: the swallow on the stage background
 *
 * Stage object created by the bg130.c stage set-up (effect_85_init, skipped during the obroll
 * replay). effect_85_move dispatches through a three-entry table (init / run / free); the run
 * state steps through a nine-entry sequence table: perching at the nest, hopping, flying
 * across to other perches and back (eff85_1000 .. eff85_8000), with patterns from
 * eff85_char_index_tbl and chn_char_table. swallow_sprize_check sends the bird to eff85_9000
 * when the screen quake is strong: it flies off-screen and the sequence restarts once BG1 has
 * scrolled past 720.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "EFF85.h"



void effect_85_move(WORK_Other* ewk) {
    void (*const eff85_jp_tbl[3])(WORK_Other*) = { eff85_0000, eff85_0100, eff85_0200 };
    eff85_jp_tbl[ewk->wu.routine_no[0]](ewk);
}



void eff85_0000(WORK_Other* ewk) {
    ewk->wu.routine_no[0]++;
    ewk->wu.routine_no[1] = 0;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.rl_flag = 0;
    ewk->wu.old_rno[0] = 0;
}



void eff85_0100(WORK_Other* ewk) {
    void (*const eff85_move_tbl[9])(WORK_Other*) = { eff85_1000, eff85_common, eff85_3000, eff85_common, eff85_5000, eff85_common, eff85_7000, eff85_8000, eff85_9000 };
    if (!EXE_flag && !Game_pause && !EXE_obroll) {
        eff85_move_tbl[ewk->wu.routine_no[1]](ewk);
    }
    disp_pos_trans_entry(ewk);
}



void eff85_1000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        if (ewk->wu.old_rno[0]) {
            set_char_move_init(&ewk->wu, 0, 44);
        } else {
            set_char_move_init(&ewk->wu, 0, 28);
        }
        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 1;
        ewk->wu.xyz[0].cal = 0x1EB0000;
        ewk->wu.xyz[1].cal = 0x2C0000;
        break;
    case 1:
        if (!swallow_sprize_check(ewk)) {
            break;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



void eff85_common(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, eff85_char_index_tbl[ewk->wu.routine_no[1]]);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



void eff85_3000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 31);
        ewk->wu.dir_timer = 34;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x2000;
        cal_initial_speed(&ewk->wu, ewk->wu.dir_timer, 400, 81);
        break;
    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x1900000;
            ewk->wu.xyz[1].cal = 0x510000;
            break;
        }
        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}



void eff85_5000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, eff85_char_index_tbl[ewk->wu.routine_no[1]]);
        break;
    case 1:
        if (!swallow_sprize_check(ewk)) {
            break;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



void eff85_7000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 34);
        ewk->wu.dir_timer = 110;
        cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, 491, 44, 2, 0);
        break;
    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.xyz[0].cal = 0x1EB0000;
            ewk->wu.xyz[1].cal = 0x2C0000;
            break;
        }
        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    }
}



void eff85_8000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, 35);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



void eff85_9000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        if (ewk->wu.cg_flip == 0) {
            ewk->wu.mvxy.a[0].sp = -0x50000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 45);
        } else {
            ewk->wu.mvxy.a[0].sp = 0x50000;
            ewk->wu.mvxy.a[1].sp = 0xC000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, 46);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].l_limit2 - bg_w.pos_offset &&
            ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].r_limit2 + bg_w.pos_offset) {
            break;
        }
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 0;
        break;
    case 2:
        if (bg_w.bgw[1].wxy[0].disp.pos > 720) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    }
}



s32 swallow_sprize_check(WORK_Other* ewk) {
    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[1] = 8;
        ewk->wu.routine_no[2] = 0;
        return 0;
    }
    return 1;
}

/* Finished: free the effect's character graphics and its work slot. */
void eff85_0200(WORK_Other* ewk)
{
    all_cgps_put_back(&ewk->wu);
    push_effect_work(&ewk->wu);
}



s32 effect_85_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if (!EXE_obroll) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 85;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.dead_f = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.xyz[0].cal = 0x1EB0000;
        ewk->wu.xyz[1].cal = 0x2C0000;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = chn_char_table;
        return 0;
    }
}
