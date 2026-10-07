/*
 * PLS01.C  Player movement and state check subroutines
 *
 * Subroutines used by the player state checks. They test and start jumps (air, triangle and
 * 360 jumps, high jumps), forward/back dashes, walks and steps, turning round (check_hurimuki),
 * standing up, and guard (check_defense_lever, check_defense_kind, check_attbox_dir).
 * The car-bonus-stage versions of the facing checks (saishin_bs2_*) are here too.
 * jumping_union_process and jumping_process_ix move a work through the air under its speeds
 * and animation and land it; check_floor/check_ashimoto test the ground under the player.
 * Also: super art stop (sa_stop_check), combo power counter resets and the recovery-roll check.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "Grade.h"
#include "PLS01.h"



s32 sa_stop_check(void) {
    if (plw[0].sa_stop_flag != 0) {
        return 1;
    }
    if (plw[1].sa_stop_flag != 0) {
        return 1;
    }
    return 0;
}



void check_my_tk_power_off(PLW* wk) {
    if (wk->wu.old_rno[1] == 1) {
        if (wk->wu.old_rno[2] >= 8 || wk->wu.old_rno[2] <= 3) {
            wk->tk_dageki = 0;
            wk->tk_nage = 0;
            wk->tk_kizetsu = 0;
        }
    } else if (wk->wu.old_rno[1] == 3) {
        if (wk->wu.routine_no[1] == 0 && wk->wu.routine_no[2] < 0x33 && wk->wu.routine_no[2] > 0x2E) {
        }
    }
}



void check_em_tk_power_off(PLW* wk, PLW* tk) {
    if (about_rno[wk->wu.old_rno[1]] != 1) {
        return;
    }
    tk->tk_dageki -= wk->utk_dageki;
    tk->tk_nage -= wk->utk_nage;
    tk->tk_kizetsu -= wk->utk_kizetsu;
    wk->utk_dageki = wk->utk_nage = wk->utk_kizetsu = 0;
    if (tk->tk_dageki < 0) {
        tk->tk_dageki = 0;
    }
    if (tk->tk_nage < 0) {
        tk->tk_nage = 0;
    }
    if (tk->tk_kizetsu < 0) {
        tk->tk_kizetsu = 0;
    }
}



/* provisional name */
s32 check_ukemi_flag(PLW* wk) {
    return wk->cp->waza_flag[7];
}



s32 check_rl_flag(WORK* wk) {
    return wk->rl_flag == wk->rl_waza;
}



void set_rl_waza(PLW* wk) {
    s16 v;
    s16 d;
    WORK_Other* p;
    if (Bonus_Game_Flag != 0x15) {
        goto other;
    }
    if (wk->wu.operator) {
        if (wk->wu.xyz[0].disp.pos < bs2_hosei[0] || wk->wu.xyz[0].disp.pos > bs2_hosei[1]) {
            goto other;
        }
        if ((v = wk->cp->sw_lvbt & 0xF) && !(v & 3)) {
            wk->wu.rl_waza = (v & 8) != 0;
            return;
        }
    }
    wk->wu.rl_waza = wk->wu.rl_flag;
    return;
other:
    p = (WORK_Other*)wk->wu.target_adrs;
    d = wk->wu.xyz[0].disp.pos - p->wu.xyz[0].disp.pos;
    if (d) {
        if (d > 0) {
            wk->wu.rl_waza = 0;
        } else {
            wk->wu.rl_waza = 1;
        }
    } else {
        wk->wu.rl_waza = (p->wu.rl_waza + 1) & 1;
    }
}



s32 check_rl_on_car(PLW* wk) {
    s16 rnum;
    if (Bonus_Game_Flag != 21) {
        return 0;
    }
    if (wk->wu.operator == 0) {
        return 0;
    }
    if (bs2_floor[2] == 0) {
        return 0;
    }
    rnum = 0;
    wk->bs2_area_car = 0;
    wk->bs2_over_car = 0;
    if (wk->wu.xyz[0].disp.pos >= bs2_floor[0] && !(wk->wu.xyz[0].disp.pos > bs2_floor[1])) {
        wk->bs2_area_car = 1;
    }
    if (wk->wu.xyz[0].disp.pos >= bs2_hosei[0] && !(wk->wu.xyz[0].disp.pos > bs2_hosei[1])) {
        rnum = 1;
    }
    if (wk->wu.xyz[1].disp.pos + (wk->wu.cg_jphos) >= bs2_floor[2]) {
        wk->bs2_over_car = 1;
    }
    return rnum;
}



s32 saishin_bs2_area_car(PLW* wk) {
    wk->bs2_area_car2 = 0;
    wk->bs2_over_car2 = 0;
    if (pcon_dp_flag) {
        return 1;
    }
    if (wk->wu.xyz[0].disp.pos >= bs2_floor[0] && wk->wu.xyz[0].disp.pos <= bs2_floor[1]) {
        wk->bs2_area_car2 = 1;
    }
    if (wk->wu.xyz[1].disp.pos + wk->wu.cg_jphos > bs2_floor[2]) {
        wk->bs2_over_car2 = 1;
    }
    if (wk->bs2_over_car != 1 || wk->bs2_over_car2 != 0 || wk->bs2_area_car2 != 1) {
        return 1;
    }
    return 0;
}



s8 saishin_bs2_on_car(PLW* wk) {
    if (wk->bs2_on_car) {
        if (wk->wu.xyz[1].disp.pos > bs2_floor[2] + 2) {
            wk->bs2_on_car = 0;
        }
    }
    return wk->bs2_on_car;
}



s32 check_air_jump(PLW* wk) {
    if (wk->spmv_ng_flag & 0x80000) {
        return 0;
    }
    if (wk->extra_jump) {
        return 0;
    }
    if (wk->air_jump_ok_time) {
        return 0;
    }
    if (wk->wu.pat_status < 20 || wk->wu.pat_status > 30) {
        return 0;
    }
    if (wk->wu.position_y < 48) {
        return 0;
    }
    if (!(wk->cp->sw_now & 1)) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 53;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    grade_add_command_waza(wk->wu.id);
    return 1;
}



s32 check_sankaku_tobi(PLW* wk) {
    if (wk->spmv_ng_flag & 0x40000) {
        return 0;
    }
    if (wk->extra_jump) {
        return 0;
    }
    if ((wk->wu.pat_status != 20) && (wk->wu.pat_status != 24) && (wk->wu.pat_status != 26) &&
        (wk->wu.pat_status != 30)) {
        return 0;
    }
    if (wk->micchaku_wall_time == 8 || wk->micchaku_wall_time == 0) {
        return 0;
    }
    if (!(wk->micchaku_flag & wk->cp->sw_lvbt >> 2)) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 52;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    grade_add_command_waza(wk->wu.id);
    return 1;
}



void check_extra_jump_timer(PLW* wk) {
    if (wk->air_jump_ok_time) {
        wk->air_jump_ok_time--;
    }
    if (wk->wu.xyz[1].disp.pos > 48) {
        if (wk->micchaku_flag) {
            wk->micchaku_wall_time++;
            if (wk->micchaku_wall_time > 8) {
                wk->micchaku_wall_time = 8;
            }
            return;
        }
    }
    wk->micchaku_wall_time = 0;
}



void remake_sankaku_tobi_mvxy(WORK* wk, u8 kabe) {
    if (kabe == 1) {
        wk->rl_flag = 0;
    }
    if (kabe == 2) {
        wk->rl_flag = 1;
    }
    if (kabe == 0) {
        if (wk->position_x > (s16)get_center_position()) {
            wk->rl_flag = 0;
        } else {
            wk->rl_flag = 1;
        }
    }
    if (wk->mvxy.a[0].sp < 0) {
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
        wk->mvxy.d[0].sp = -wk->mvxy.d[0].sp;
    }
    kabe = 4;
    if (wk->mvxy.a[1].real.h <= 0) {
        wk->mvxy.a[1].real.h = kabe;
        wk->mvxy.a[0].real.h = wk->mvxy.a[0].real.h * 5 / kabe;
    } else {
        wk->mvxy.a[1].real.h = wk->mvxy.a[1].real.h * 4 / 3;
        wk->mvxy.a[0].real.h = wk->mvxy.a[0].real.h * 5 / 4;
        wk->mvxy.a[1].real.h = wk->mvxy.a[1].real.h + 2;
    }
    if (wk->mvxy.a[1].real.h < kabe) {
        wk->mvxy.a[1].real.h = kabe;
    }
}



s32 check_F_R_dash(PLW* wk) {
    s16* q;
    s16 num;
    s16 rnum;
    if (Bonus_Game_Flag == 21 && wk->bs2_on_car) {
        goto ok;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }
ok:
    q = &wk->cp->waza_flag[0];
    num = (q[0] != 0);
    num += (q[1] != 0) * 2;
    rnum = 0;
loop:
    switch (num) {
    case 1:
        if (wk->spmv_ng_flag & 4) {
            break;
        }
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 5;
        wk->wu.routine_no[3] = 0;
        rnum = 1;
        break;
    case 2:
        if (wk->spmv_ng_flag & 8) {
            break;
        }
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 6;
        wk->wu.routine_no[3] = 0;
        rnum = 1;
        break;
    case 3:
        if (wk->cp->lever_dir < 2) {
            num = 1;
        } else {
            num = 2;
        }
        goto loop;
    }
    if (rnum) {
        grade_add_command_waza(wk->wu.id);
    }
    return rnum;
}



/* provisional name */
s32 check_360_jump(PLW* wk) {
    if (wk->spmv_ng_flag & 0x10000) {
        return 0;
    }
    if (wk->cp->waza_flag[13] == 0) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 19;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    return 1;
}



s32 check_jump_ready(PLW* wk) {
    if (!(wk->cp->sw_new & 1)) {
        return 0;
    }
    if (wk->cp->waza_flag[2] == 0) {
        wk->wu.routine_no[2] = 16;
    } else {
        wk->wu.routine_no[2] = 17;
        grade_add_command_waza(wk->wu.id);
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    return 1;
}



s32 check_hijump_only(PLW* wk) {
    if (wk->spmv_ng_flag & 0x20000) {
        return 0;
    }
    if (!(wk->cp->sw_new & 1)) {
        return 0;
    }
    if (wk->cp->waza_flag[2] == 0) {
        return 0;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 17;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    grade_add_command_waza(wk->wu.id);
    return 1;
}



s32 check_bend_myself(PLW* wk) {
    if (!(wk->cp->sw_new & 2)) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 8;
    wk->wu.routine_no[3] = 0;
    return 1;
}



s32 check_F_R_walk(PLW* wk) {
    s16 r = 0;
    switch (wk->cp->lever_dir) {
    case 1:
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 3;
        wk->wu.routine_no[3] = 0;
        r = 1;
        break;
    case 2:
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[2] = 4;
        r = 1;
        wk->wu.routine_no[3] = 0;
        break;
    }
    return r;
}



/* provisional name */
s32 check_F_R_step(PLW* wk) {
    s16 rnum = 0;
    switch (wk->cp->lever_dir) {
    case 1:
        if (!(wk->spmv_ng_flag & 1)) {
            wk->wu.routine_no[1] = 0;
            wk->wu.routine_no[2] = 11;
            wk->wu.routine_no[3] = 0;
            rnum = 1;
        }
        break;
    case 2:
        if (!(wk->spmv_ng_flag & 2)) {
            wk->wu.routine_no[1] = 0;
            wk->wu.routine_no[2] = 12;
            wk->wu.routine_no[3] = 0;
            rnum = 1;
        }
        break;
    }
    return rnum;
}



/* provisional name */
s32 check_hurimuki_bs2(WORK* wk) {
    return wk->rl_flag == wk->rl_waza;
}



s32 check_turn_to_back(PLW* wk) {
    if (wk->hurimukenai_flag) {
        return 0;
    }
    if (Bonus_Game_Flag == 21) {
        if (check_hurimuki_bs2(&wk->wu)) {
            return 0;
        }
    } else if (check_hurimuki(&wk->wu)) {
        return 0;
    }
    if (wk->cp->sw_lvbt & 2) {
        wk->wu.routine_no[2] = 10;
    } else {
        wk->wu.routine_no[2] = 2;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[3] = 0;
    wk->wu.cg_type = 0;
    wk->hurimukenai_flag = 1;
    return 1;
}



s32 check_hurimuki(WORK* wk) {
    WORK* em = (WORK*)wk->target_adrs;
    s16 result = wk->xyz[0].disp.pos - em->old_pos[0];
    if (result) {
        if (result > 0) {
            return wk->rl_flag == 0;
        }
        return wk->rl_flag;
    }
    return 1;
}



s32 check_walking_lv_dir(PLW* wk) {
    s16 rnum = 0;
    switch (wk->cp->lever_dir) {
    case 1:
        if (wk->wu.routine_no[2] != 3) {
            rnum = 1;
        }
        break;
    case 2:
        if (wk->wu.routine_no[2] != 4) {
            rnum = 1;
        }
        break;
    default:
        rnum = 1;
        break;
    }
    if (rnum) {
        if (wk->wu.pat_status < 32) {
            wk->wu.routine_no[2] = 1;
        } else {
            wk->wu.routine_no[2] = 9;
        }
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[3] = 0;
    }
    return rnum;
}



/* provisional name: check_walking_lv_dir for the other walk states (11/12), unreferenced */
s32 check_walking_lv_dir2(PLW* wk) {
    s16 rnum = 0;
    switch (wk->cp->lever_dir) {
    case 1:
        if (wk->wu.routine_no[2] != 11) {
            rnum = 1;
        }
        break;
    case 2:
        if (wk->wu.routine_no[2] != 12) {
            rnum = 1;
        }
        break;
    default:
        rnum = 1;
        break;
    }
    if (rnum) {
        if (wk->wu.pat_status < 32) {
            wk->wu.routine_no[2] = 1;
        } else {
            wk->wu.routine_no[2] = 9;
        }
        wk->wu.routine_no[1] = 0;
        wk->wu.routine_no[3] = 0;
    }
    return rnum;
}



s32 check_stand_up(PLW* wk) {
    if (wk->cp->sw_new & 2) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 7;
    wk->wu.routine_no[3] = 0;
    return 1;
}



s32 check_defense_lever(PLW* wk) {
    if (!check_em_catt(wk)) {
        return 0;
    }
    if (wk->cp->sw_new & 2) {
        wk->wu.routine_no[2] = 29;
    } else if (check_attbox_dir(wk)) {
        wk->wu.routine_no[2] = 28;
    } else {
        wk->wu.routine_no[2] = 27;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[3] = 0;
    return 1;
}



s32 check_em_catt(PLW* wk) {
    PLW* em = (PLW*)wk->wu.target_adrs;
    s16 xd;
    s8 rlf;
    if (em->caution_flag == 0) {
        return 0;
    }
    if ((rlf = (wk->wu.rl_flag + em->wu.rl_flag) & 1) == 0) {
        return 0;
    }
    if (wk->cp->lever_dir != 2 || wk->cp->sw_new & 1) {
        return 0;
    }
    xd = wk->wu.xyz[0].disp.pos - em->wu.xyz[0].disp.pos;
    if (xd < 0) {
        xd = -xd;
    }
    if (xd > 112) {
        return 0;
    }
    return 1;
}



s32 check_attbox_dir(PLW* wk) {
    s16 target_pos_x;
    s16 target_pos_y;
    s16 emdir;
    s16* dttbl;
    get_target_att_position((WORK*)wk->wu.target_adrs, &target_pos_x, &target_pos_y);
    dttbl = (s16*)sel_hd_fg_hos[wk->player_number];
    if (wk->wu.rl_flag) {
        emdir = caldir_pos_032(
            wk->wu.xyz[0].disp.pos - dttbl[0], wk->wu.xyz[1].disp.pos + dttbl[1], target_pos_x, target_pos_y);
    } else {
        emdir = caldir_pos_032(
            wk->wu.xyz[0].disp.pos + dttbl[0], wk->wu.xyz[1].disp.pos + dttbl[1], target_pos_x, target_pos_y);
        emdir = dir32_rl_conv[emdir];
    }
    if ((wk->wu.now_koc == 0) && ((wk->wu.char_index) == 29)) {
        emdir = dir32_sel_tbl[1][emdir];
    } else {
        emdir = dir32_sel_tbl[0][emdir];
    }
    return emdir;
}



s32 check_defense_kind(PLW* wk) {
    u16 rnum = 0;
    switch (wk->wu.routine_no[2]) {
    case 27:
        if (wk->cp->sw_new & 2) {
            rnum = 3;
        } else if (chcgp_hos[wk->player_number] && check_attbox_dir(wk)) {
            rnum = 2;
        }
        break;
    case 28:
        if (wk->cp->sw_new & 2) {
            rnum = 3;
        } else if (chcgp_hos[wk->player_number] && (check_attbox_dir(wk) == 0)) {
            rnum = 1;
        }
        break;
    case 29:
        if (!(wk->cp->sw_new & 2)) {
            if (check_attbox_dir(wk)) {
                rnum = 2;
            } else {
                rnum = 1;
            }
        }
        break;
    }
    if (rnum) {
        wk->wu.routine_no[2] = rnum + 26;
        set_char_move_init(&wk->wu, 0, rnum + 28);
        while (1) {
            if (wk->wu.cg_type == 1) {
                break;
            }
            char_move_z(&wk->wu);
        }
    }
    return rnum;
}



void jumping_union_process(WORK* wk, s16 num) {
    add_mvxy_speed(wk);
    cal_mvxy_speed(wk);
    char_move(wk);
    if ((Bonus_Game_Flag == 21) && (wk->operator != 0) && (saishin_bs2_area_car((PLW*)wk) == 0)) {
        if (!(wk->xyz[1].disp.pos + wk->cg_jphos > bs2_floor[2])) {
            wk->position_y = wk->xyz[1].disp.pos = bs2_floor[2];
            wk->mvxy.a[1].sp = 0;
            wk->routine_no[3] = num;
            ((PLW*)wk)->bs2_on_car = 1;
            char_move_cmja(wk);
        }
        return;
    }
    if ((wk->xyz[1].disp.pos + wk->cg_jphos) <= 0) {
        wk->position_y = 0;
        wk->xyz[1].cal = 0;
        wk->mvxy.a[1].sp = 0;
        wk->routine_no[3] = num;
        char_move_cmja(wk);
    }
}



/* provisional name */
void jumping_process_ix(WORK* wk, s16 ix, s16 num) {
    cal_mvxy_speed(wk);
    add_mvxy_speed(wk);
    char_move(wk);
    if ((wk->xyz[1].disp.pos + wk->cg_jphos) <= 0) {
        wk->position_y = 0;
        wk->xyz[1].cal = 0;
        wk->routine_no[ix] = num;
        char_move_cmja(wk);
    }
}



s32 check_floor(PLW* wk) {
    if (wk->bs2_on_car == 0) {
        return 0;
    }
    if (wk->bs2_area_car) {
        return 0;
    }
    return 1;
}



s32 check_ashimoto(PLW* wk) {
    if (check_floor(wk) == 0) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 54;
    wk->wu.routine_no[3] = 0;
    wk->jpdir = 0;
    return 1;
}



s32 check_floor_2(PLW* wk) {
    WORK* efw;
    if (wk->bs2_on_car == 0) {
        return 0;
    } else if (wk->bs2_area_car != 0) {
        return 0;
    }
    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    if (hit_check_x_only(&wk->wu, efw, &wk->wu.hosei_adrs->hos_box[4], &efw->h_hos->hos_box[0])) {
        return 0;
    }
    return 1;
}



s32 check_ashimoto_ex(PLW* wk) {
    if (check_floor_2(wk) == 0) {
        return 0;
    }
    wk->wu.routine_no[1] = 0;
    wk->wu.routine_no[2] = 55;
    wk->wu.routine_no[3] = 0;
    return 1;
}
