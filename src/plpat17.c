/*
 * plpat17.c  Character 17 (Makoto) special attack routines
 *
 * The entry routine pl17_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl17_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * Att_PL17_AT1 is a jump that travels to the screen wall (set_kabe_move_spd sets the speed toward
 * a point near the wall, kabe_check stops the player there), Att_PL17_AT2 starts effect L8 at its
 * marker, and Att_PL17_TOKUSHUKOUDOU is the personal action.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "effl8.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFI3.h"
#include "bg_sub.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "CHARSET.h"
#include "plpat17.h"


void pl17_extra_attack(PLW* wk) {
    pl17_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL17_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.xyz[1].cal = 0;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->scr_pos_set_flag = 0;
        reset_mvxy_data(&wk->wu);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        wk->wu.mvxy.index = wk->as->data_ix;
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        set_kabe_move_spd(&wk->wu, 28);
        wk->rl_save = 0;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 10) {
            wk->wu.routine_no[3] = 3;
            effect_I3_init(&wk->wu, 2);
        }
        if (wk->wu.routine_no[3] != 1) {
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 4;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] != 2) {
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 2);
        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 20) {
                setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
                wk->wu.mvxy.index++;
                wk->wu.cg_type = 0;
            }
            if (wk->wu.cg_type == 21) {
                reset_mvxy_data(&wk->wu);
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 2;
            }
            if (wk->wu.cg_type == 25) {
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 5;
            }
        }
        break;
    case 4:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 2;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    case 5:
        jumping_union_process(&wk->wu, 2);
        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 21) {
                reset_mvxy_data(&wk->wu);
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 2;
            }
            if (wk->wu.cg_type == 26) {
                wk->wu.cg_type = 0;
                wk->wu.routine_no[3] = 3;
            }
            if (wk->wu.cg_type == 30) {
                wk->wu.cg_type = 0;
                wk->wu.mvxy.d[0].sp = 0;
            }
            if (wk->rl_save) {
                wk->rl_save = 0;
                wk->wu.routine_no[3] = 2;
                wk->wu.xyz[0].disp.pos = get_center_position();
                if (wk->wu.rl_flag) {
                    wk->wu.xyz[0].disp.pos -= 142;
                } else {
                    wk->wu.xyz[0].disp.pos += 142;
                }
            }
        }
        if ((wk->wu.routine_no[3] == 5) && (kabe_check(&wk->wu))) {
            char_move_cmj4(&wk->wu);
            reset_mvxy_data(&wk->wu);
            wk->rl_save = 1;
        }
        break;
    }
}



void set_kabe_move_spd(WORK* wk, s16 tm) {
    s16 tar_pos;
    tar_pos = get_center_position();
    if (wk->rl_flag) {
        tar_pos -= 192;
    } else {
        tar_pos += 192;
    }
    cal_all_speed_data(wk, tm, tar_pos, wk->xyz[1].disp.pos + 120, 2, 2);
    if (!wk->rl_flag) {
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
        wk->mvxy.d[0].sp = -wk->mvxy.d[0].sp;
    }
    wk->mvxy.kop[0] = 1;
}



s32 kabe_check(WORK* wk) {
    s16 tar_pos;
    if (wk->xyz[1].disp.pos <= 84) {
        return 0;
    }
    tar_pos = get_center_position();
    if (wk->rl_flag) {
        tar_pos -= 142;
        if (!(wk->xyz[0].disp.pos > tar_pos)) {
            wk->xyz[0].disp.pos = tar_pos;
            return 1;
        }
        return 0;
    }
    tar_pos += 142;
    if (wk->xyz[0].disp.pos >= tar_pos) {
        wk->xyz[0].disp.pos = tar_pos;
        return 1;
    }
    return 0;
}



void Att_PL17_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 10) {
            wk->wu.cg_type = 0;
            effect_L8_init(wk);
        }
        break;
    }
}



void Att_PL17_TOKUSHUKOUDOU(PLW* wk) {
    s32 t;
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;
        case 10:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }
            grade_add_personal_action(wk->wu.id);
            break;
        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            if (wk->tk_dageki > 20) {
                wk->tk_dageki = 20;
            }
            break;
        case 30:
            wk->wu.routine_no[3]++;
            if (wk->tk_success < 3) {
                wk->tk_success++;
                t = wk->py->recover;
                t *= 110;
                wk->py->recover = t / 100;
            }
            break;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}
