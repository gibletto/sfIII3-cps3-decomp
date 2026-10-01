/*
 * PLPAT09.C  Player 09 (Oro) special attack routines
 *
 * Character-specific attack routines for player number 9, dispatched by pl09_extra_attack
 * through pl09_exatt_table. The file begins with Att_PL08_TOKUSHUKOUDOU, player 8's personal
 * action (super gauge and a stun power boost of 6, capped 24).
 * Att_SP_YAGYOUDAMA is the projectile super; set_tenguiwa, Att_PL09_EX_TENGUIWA and
 * Att_PL09_EX_KISHINRIKI handle the rock-summon and other extra moves, and
 * Att_JINNCHUUWATARI_EX the jumping special, with mvxy_table_reader stepping the move data.
 * Att_PL09_TOKUSHUKOUDOU is the personal action: each repeat builds tk_success (up to 13) and
 * cuts the stun gauge timer by the rate in pl09_tk_table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFF13_KOTP.h"
#include "EFFECT.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "CHARSET.h"
#include "PLPAT09.h"



void Att_PL08_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 64) {
            wk->wu.routine_no[3]++;
            wk->tk_kizetsu += 6;
            if (wk->tk_kizetsu > 24) {
                wk->tk_kizetsu = 24;
            }
            grade_add_personal_action(wk->wu.id);
        }
        break;
    default:
        char_move((WORK*)wk);
        break;
    }
}


void pl09_extra_attack(PLW* wk) {
    pl09_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_SP_YAGYOUDAMA(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
        }
        break;
    case 2:
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 3;
            break;
        }
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 2;
        }
        break;
    }
}



s32 set_tenguiwa(PLW* wk, u8 data) {
    s16 i;
    s16 j;
    u16 num;
    s16 rv;
    const u8* tengu;
    WORK* tmw;
    if (!data) {
        tengu = tenguiwa_stand_by[tenguiwa_stage_data[bg_w.stage][0]];
        for (i = 0; i < 3; i++) {
            effect_13_init((WORK*)wk, tengu[random_16_com() & 7]);
        }
        for (j = 0, i = 0; i < 8; i++) {
            if (!(rv = get_my_shell_ix((WORK*)wk, i, &tmw))) {
                continue;
            }
            rv = tmw->type;
            num = rv - 24;
            if (num <= 35) {
                tmw->old_pos[0] = tenguiwa_pos_hosei[j][0];
                tmw->old_pos[1] = tenguiwa_pos_hosei[j][1];
                tmw->old_pos[2] = tenguiwa_pos_hosei[j][2];
                tmw->scr_mv_x = tenguiwa_pos_hosei[j][3];
                tmw->scr_mv_y = tenguiwa_pos_hosei[j][4];
                rv = tmw->direction = tenguiwa_pos_hosei[j][5];
                j++;
                if (j > 2) {
                    break;
                }
            }
        }
        return rv;
    }
    tengu = tenguiwa_stand_by[tenguiwa_stage_data[bg_w.stage][1]];
    for (i = 0; i < 5; i++) {
        effect_13_init((WORK*)wk, tengu[random_16_com() & 7]);
    }
    for (j = 0, i = 0; i < 8; i++) {
        if (!(rv = get_my_shell_ix((WORK*)wk, i, &tmw))) {
            continue;
        }
        rv = tmw->type;
        num = rv - 24;
        if (num <= 35) {
            tmw->old_pos[0] = tenguiwa_pos_hosei2[j][0];
            tmw->old_pos[1] = tenguiwa_pos_hosei2[j][1];
            tmw->old_pos[2] = tenguiwa_pos_hosei2[j][2];
            tmw->scr_mv_x = tenguiwa_pos_hosei2[j][3];
            tmw->scr_mv_y = tenguiwa_pos_hosei2[j][4];
            rv = tmw->direction = tenguiwa_pos_hosei2[j][5];
            j++;
            if (j > 4) {
                break;
            }
        }
    }
    return rv;
}



void Att_PL09_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->tk_success = 0;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            if (++wk->tk_success > 13) {
                wk->tk_success = 13;
            }
        }
        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        wk->py->now.timer -= wk->py->recover * pl09_tk_table[wk->tk_success] / 100;
        if (wk->py->now.quantity.h <= 0) {
            wk->py->now.timer = 0;
        }
        break;
    default:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 64) {
            grade_add_personal_action(wk->wu.id);
        }
        break;
    }
}



void Att_JINNCHUUWATARI_EX(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        wk->wu.kow = wk->as->r_no;
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move((WORK*)wk);
        mvxy_table_reader(wk);
        break;
    case 2:
        mvxy_table_reader(wk);
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = (wk->wu.routine_no[1] == 0) ? 2 : 4;
            break;
        }
        jumping_union_process((WORK*)wk, 4);
        break;
    case 4:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = (wk->wu.routine_no[1] == 0) ? 2 : 3;
        }
        break;
    }
}



void mvxy_table_reader(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;
    const s16* curr_kop = &homing_kop[wk->wu.kow][0];
    u16 ex;
    u16 ey;
    if (wk->wu.cg_type == 30) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        switch (curr_kop[0]) {
        case 0:
            if (wk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
                ex = twk->wu.xyz[0].disp.pos - homing_hos[wk->wu.kow][twk->player_number][0];
                if (!wk->wu.rl_flag) {
                    ex = wk->wu.xyz[0].disp.pos - (ex - wk->wu.xyz[0].disp.pos);
                }
            } else {
                ex = twk->wu.xyz[0].disp.pos + homing_hos[wk->wu.kow][twk->player_number][0];
                if (wk->wu.rl_flag) {
                    ex = wk->wu.xyz[0].disp.pos + (wk->wu.xyz[0].disp.pos - ex);
                }
            }
            ey = homing_hos[wk->wu.kow][twk->player_number][1];
            wk->wu.mvxy.a[0].sp = 0;
            cal_initial_speed(&wk->wu, curr_kop[1], ex, ey);
            wk->wu.kow++;
            break;
        case 1:
            ex = wk->wu.xyz[0].disp.pos;
            if (wk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
                ex += (twk->wu.xyz[0].disp.pos - wk->wu.xyz[0].disp.pos) / 2;
            } else {
                ex -= (wk->wu.xyz[0].disp.pos - twk->wu.xyz[0].disp.pos) / 2;
            }
            ey = homing_hos[wk->wu.kow][twk->player_number][1];
            wk->wu.mvxy.a[0].sp = 0;
            cal_initial_speed(&wk->wu, curr_kop[1], ex, ey);
            wk->wu.kow++;
            break;
        }
        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        wk->wu.routine_no[3]++;
        wk->wu.cg_type = 0;
        add_mvxy_speed(&wk->wu);
    }
    if (wk->wu.cg_type == 20) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        wk->wu.routine_no[3]++;
        wk->wu.cg_type = 0;
        add_mvxy_speed(&wk->wu);
    }
}



void Att_PL09_EX_TENGUIWA(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->sa->dtm_mul = 2;
        break;
    case 1:
        char_move(&wk->wu);
        break;
    }
}



void Att_PL09_EX_KISHINRIKI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        wk->sa->dtm_mul = 16;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}
