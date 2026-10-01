/*
 * EFFL3.C  Perfect-win extras (effect L3)
 *
 * Six extra figures that join the winner's pose after a Perfect (created from WIN_PL only
 * when Perfect_Flag is set). effect_L3_init positions them from effl3_pos_data relative to
 * the stage centre and the loser, borrowing the owner's character tables and colour.
 * effect_L3_move runs one of three routines: effl3_0000 walks in to a target point and
 * plays an arrival animation, effl3_0001 jumps in on a computed arc and lands, and
 * effl3_0002, once Appear_Q is raised, either leaps off screen (effl3_tobi) or plays a
 * vanish animation (effl3_kie) after a random wait.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "effL3.h"



void effect_L3_move(WORK_Other* ewk) {
    void (*effl3_jp[3])(WORK_Other*) = { effl3_0000, effl3_0001, effl3_0002 };
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
    case 1:
        if (!EXE_flag && !Game_pause) {
            effl3_jp[ewk->wu.routine_no[1]](ewk);
        }
        pl_eff_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effl3_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 2);
        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = 0x28000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x28000;
        }
    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);
        if (ewk->wu.rl_flag) {
            if (ewk->wu.xyz[0].disp.pos > ewk->wu.old_rno[0]) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 11);
            }
        } else {
            if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[0]) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 11);
            }
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if ((u8)ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 0);
        }
        break;
    case 3:
        if (Appear_Q) {
            ewk->wu.routine_no[1] = 2;
        }
        char_move(&ewk->wu);
        break;
    }
}



void effl3_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 1, 49);
        ewk->wu.old_rno[2] = 60;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[2], ewk->wu.old_rno[0], ewk->wu.xyz[1].disp.pos - 32, 2, 2);
        break;
    case 1:
        char_move(&ewk->wu);
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 1, 50);
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            break;
        }
        add_x_sub(ewk);
        add_y_sub(ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 0);
        }
        break;
    case 3:
        if (Appear_Q) {
            ewk->wu.routine_no[1] = 2;
        }
        char_move(&ewk->wu);
        break;
    }
}



void effl3_0002(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[3]) {
    case 0:
        ewk->wu.routine_no[3]++;
        ewk->wu.disp_flag = 1;
        work = random_16_com();
        ewk->wu.old_rno[4] = effl3_wait_timer[work];
        ewk->wu.old_rno[3] = ewk->wu.type & 1;
        break;
    case 1:
        if (ewk->wu.old_rno[3]) {
            effl3_tobi(ewk);
            break;
        }
        effl3_kie(ewk);
        break;
    }
}



/* provisional name */
void effl3_tobi(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[4]) {
    case 0:
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] < 0) {
            ewk->wu.routine_no[4]++;
            set_char_move_init(&ewk->wu, 9, 39);
            return;
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[4]++;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0x78000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case 2:
        add_y_sub(ewk);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[4]++;
            ewk->wu.mvxy.d[0].sp = 0;
            if (ewk->wu.rl_flag) {
                ewk->wu.mvxy.a[0].sp = 0x80000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0x80000;
            }
            ewk->wu.mvxy.a[1].sp = -0x8000;
            ewk->wu.mvxy.d[1].sp = 0x4000;
        }
        break;
    case 3:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (!range_x_check3(ewk, 208)) {
            ewk->wu.routine_no[0] = 99;
        }
        break;
    case 4:
        break;
    }
}



/* provisional name */
void effl3_kie(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[4]) {
    case 0:
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] < 0) {
            ewk->wu.routine_no[4]++;
            set_char_move_init(&ewk->wu, 1, 94);
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 99;
        }
        break;
    }
}



s32 effect_L3_init(PLW* oya) {
    s16 i;
    PLW* f;
    const s16* t;
    s16 s;
    WORK_Other* n;
    s16 k;

    if (!Perfect_Flag) {
        return;
    }
    t = effl3_pos_data;
    k = oya->wu.id ^ 1;
    for (i = 0, f = &plw[k]; i < 6; i++) {
        s = pull_effect_work(3);
        if (s == -1) {
            return -1;
        }
        n = (WORK_Other*)frw[s];
        n->wu.be_flag = 1;
        n->wu.id = 213;
        n->wu.work_id = 16;
        n->my_master = (u32*)oya;
        n->master_id = oya->wu.id;
        n->wu.cgromtype = 1;
        n->wu.my_family = 2;
        n->wu.my_col_mode = 0x4200;
        n->wu.my_col_code = oya->wu.my_col_code;
        n->wu.type = i;
        n->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        n->wu.xyz[0].disp.pos += *t++;
        n->wu.xyz[1].disp.pos = f->wu.xyz[1].disp.pos;
        n->wu.xyz[1].disp.pos += *t++;
        n->wu.position_z = f->wu.position_z;
        n->wu.position_z += *t++;
        n->wu.my_priority = n->wu.position_z;
        n->wu.rl_flag = *t++;
        n->wu.kage_char = *t++;
        n->wu.old_rno[0] = f->wu.xyz[0].disp.pos;
        n->wu.old_rno[0] += *t++;
        n->wu.old_rno[1] = *t++;
        n->wu.routine_no[1] = *t++;
        n->wu.char_table[0] = oya->wu.char_table[0];
        n->wu.char_table[1] = etc_char_table;
        n->wu.char_table[9] = oya->wu.char_table[9];
        n->wu.kage_flag = 1;
        n->wu.kage_hx = 6;
        n->wu.kage_hy = 0;
        n->wu.kage_prio = n->wu.position_z + 5;
    }
}
