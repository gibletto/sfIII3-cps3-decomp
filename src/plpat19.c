/*
 * plpat19.c  Character 19 (Twelve) special attack routines
 *
 * The entry routine pl19_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl19_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * Att_METAMORPHOSE starts the metamorphosis (effect K7), Att_SA__D_R_A and
 * Att_EX__D_R_A are the super art and EX versions of the D.R.A. move, Att_KUUCHUUHISSATU and
 * Att_AIR_A_X_E are air specials, Att_AIRDASH is the air dash that wraps round at the screen wall
 * (kabe_check2/3), and Att_pl19_TOKUSHUKOUDOU is the personal action. get_lever_dir reads the
 * lever direction for steering.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFI3.h"
#include "EFFK7.h"
#include "EFFL0.h"
#include "bg_sub.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "CHARSET.h"
#include "plpat19.h"


void pl19_extra_attack(PLW* wk) {
    pl19_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_METAMORPHOSE(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        reset_mvxy_data(&wk->wu);
        wk->metamorphose = 0;
        wk->metamor_over = 0;
        if (Bonus_Game_Flag == 0x15) {
            goto alt;
        }
        if (effect_K7_init(wk) != -1) {
            set_char_move_init(&wk->wu, 5, wk->as->char_ix);
            break;
        }
    alt:
        set_char_move_init(&wk->wu, 5, wk->as->char_ix + 2);
        wk->wu.routine_no[3] = 9;
        break;
    case 1:
        char_move(&wk->wu);
        if ((u8)wk->wu.cg_type == 20) {
            wk->wu.routine_no[2] = 32;
            wk->wu.routine_no[3] = 1;
        }
        break;
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void Att_SA__D_R_A(PLW* wk) {
    PLW* emwk;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if ((wk->wu.routine_no[3] != 3) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] == 3) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.d[1].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.routine_no[3] = 5;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 30) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            emwk = (PLW*)wk->wu.target_adrs;
            wk->wu.xyz[0].disp.pos = emwk->wu.xyz[0].disp.pos;
            wk->wu.xyz[1].disp.pos = emwk->wu.xyz[1].disp.pos + -224;
            if (wk->wu.xyz[1].disp.pos < 0) {
                wk->wu.xyz[1].disp.pos = 0;
            }
        }
        if ((wk->wu.cg_type == 64) || (wk->wu.cg_type == 0xFF)) {
            wk->wu.routine_no[3] = 5;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
        }
        break;
    case 4:
        jumping_union_process(&wk->wu, 5);
        if ((wk->wu.routine_no[3] != 5) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] == 5) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.d[1].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 5:
        char_move(&wk->wu);
        break;
    default:
        char_move(&wk->wu);
    }
}



void Att_EX__D_R_A(PLW* wk) {
    PLW* twk;
    s16 ex;
    s16 ey;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        twk = (PLW*)wk->wu.target_adrs;
        if (wk->wu.rl_flag) {
            ex = twk->wu.position_x - dra_em_tall[twk->player_number][0];
        } else {
            ex = twk->wu.position_x + dra_em_tall[twk->player_number][0];
        }
        ey = dra_em_tall[twk->player_number][1];
        wk->wu.mvxy.a[0].sp = 0;
        cal_delta_speed(&wk->wu, 8, ex, ey, 2, 2);
        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
            wk->wu.mvxy.kop[1] = 2;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if ((wk->wu.routine_no[3] != 3) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] == 3) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.d[1].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 64 || wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}



void Att_KUUCHUUHISSATU(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
    case 1:
        jumping_union_process(&wk->wu, 2);
        if ((wk->wu.routine_no[3] != 2) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] == 2) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.d[1].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 2:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 64 || wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}



void Att_AIRDASH(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (kabe_check3(wk) != 0) {
            wk->wu.rl_flag = (wk->wu.rl_flag + 1) & 1;
            wk->wu.xyz[0].disp.pos = wk->wu.rl_flag ? bg_w.bgw[1].l_limit2 - 192 : bg_w.bgw[1].r_limit2 + 192;
            set_char_move_init(&wk->wu, 5, 65);
            wk->wu.routine_no[3] = 5;
            wk->wu.cg_type = 0;
            effect_I3_init(&wk->wu, 4);
            break;
        }
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 25:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 30:
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
            break;
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        if (kabe_check3(wk)) {
            wk->wu.rl_flag = wk->wu.rl_flag + 1 & 1;
            wk->wu.xyz[0].disp.pos = wk->wu.rl_flag ? bg_w.bgw[1].l_limit2 - 192 : bg_w.bgw[1].r_limit2 + 192;
            set_char_move_init(&wk->wu, 5, 65);
            wk->wu.routine_no[3] = 5;
            wk->wu.cg_type = 0;
            effect_I3_init(&wk->wu, 4);
        }
        break;
    case 4:
        char_move(&wk->wu);
        break;
    case 5:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
        }
        break;
    case 6:
        wk->wu.routine_no[3] = 1;
        char_move_cmj4(&wk->wu);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    }
}



/* provisional name */
s32 kabe_check2(PLW* wk) {
    s16 tar_pos;
    if (get_lever_dir(wk) != 1) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 32) {
        return 0;
    }
    tar_pos = get_center_position();
    if (wk->wu.rl_flag) {
        tar_pos += 160;
        if (wk->wu.xyz[0].disp.pos >= tar_pos) {
            wk->wu.xyz[0].disp.pos = tar_pos;
            return 1;
        }
        return 0;
    }
    tar_pos -= 160;
    if (!(wk->wu.xyz[0].disp.pos > tar_pos)) {
        wk->wu.xyz[0].disp.pos = tar_pos;
        return 1;
    }
    return 0;
}



s32 kabe_check3(PLW* wk) {
    if (get_lever_dir(wk) != 1) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos <= 32) {
        return 0;
    }
    return wk->wu.rl_flag + wk->micchaku_flag == 2;
}



void Att_pl19_TOKUSHUKOUDOU(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        if (wk->sa->ok == -1) {
            wk->wu.routine_no[3] = 2;
            set_char_move_init((WORK*)wk, 5, 62);
        } else if (wk->wu.disp_flag != 1 || wk->wu.my_col_mode != 0x4200) {
            wk->wu.routine_no[3] = 2;
            set_char_move_init((WORK*)wk, 5, 64);
        } else {
            set_char_move_init((WORK*)wk, 5, 63);
        }
        break;
    case 1:
        char_move((WORK*)wk);
        switch ((u8)wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            return;
        case 0xFF:
            grade_add_personal_action(wk->wu.id);
            effect_L0_init((WORK*)wk, 180);
            return;
        }
        return;
    case 2:
        char_move((WORK*)wk);
        break;
    }
}



void Att_AIR_A_X_E(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
        }
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] == 3) {
            break;
        }
        if (wk->wu.cg_type == 20) {
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



s32 get_lever_dir(PLW* wk) {
    u8 num;
    if (wk->wu.work_id == 1) {
        if (wk->py->flag == 0) {
            num = wcp[wk->wu.id].lever_dir;
        } else {
            num = 0;
        }
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].lever_dir;
    }
    return num;
}
