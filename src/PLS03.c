/*
 * PLS03.C  Super art and special move command checks
 *
 * Checks whether the player's command input starts a special move or super art.
 * check_super_arts_attack, check_full_gauge_attack/2 and execute_super_arts test the super art
 * commands against the gauge and start the art; check_special_attack tests the special move
 * commands and hissatsu_setup_union sets up the chosen move; check_leap_attack tests the
 * leap attack.
 * These checks are called from the per-state checks in PLS00.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Grade.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "PLS03.h"
void hissatsu_setup_union(PLW* wk, s16 rno) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = rno;
    wk->wu.routine_no[3] = 0;
    wk->cancel_timer = 0;
    wk->wu.cg_type = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.paring_attack_flag = 0;
}



s32 check_full_gauge_attack(PLW* wk, s8 always) {
    u16* conpane;
    s16 j;
    s16 cusw;
    s32 exsw;
    if (wk->sa->mp != 1) {
        return 0;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (((Bonus_Game_Flag == 21) && (wk->bs2_on_car)) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }
        if (wk->sa->exsa_g_ix == 0) {
            return 0;
        }
        if (wk->sa->exsa_g_ix > 0x1C) {
            return 0;
        }
        if (always && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x100)) {
            return 0;
        }
        if (wk->cancel_timer == 0) {
            wk->permited_koa |= 0x40;
        }
        if (wk->cp->btix[wk->sa->exsa_g_ix] & 0x4000) {
            if (Version_Type == 3) {
                return 0;
            }
            if (Version_Type == 2) {
                return 0;
            }
        }
        conpane = &wk->cp->sw_lvbt;
        if (wk->cp->waza_flag[wk->sa->exsa_g_ix] == -1) {
            return 0;
        }
        if ((wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF) == 0x80) {
            return 0;
        }
        if (!wk->cp->waza_flag[wk->sa->exsa_g_ix]) {
            return 0;
        }
        cusw = conpane[wk->cp->btix[wk->sa->exsa_g_ix] & 0xFF];
        for (j = 3; j >= 0; j--) {
            if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_g_ix] & 0x600)) {
                continue;
            }
            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j]];
            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_g_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->exsa_g_ix - 20][j].as;
                wk->wu.cg_cancel = 0;
                wk->sa->mp = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_g_ix][j]);
                waza_slot_clear_all_p(wk);
                return 1;
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->exsa_a_ix == 0) {
        return 0;
    }
    if ((wk->sa->exsa_a_ix) < 0x1C) {
        return 0;
    }
    if (always && !(wk->cp->btix[wk->sa->exsa_a_ix] & 0x100)) {
        return 0;
    }
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 0x40;
    }
    if (wk->cp->btix[wk->sa->exsa_a_ix] & 0x4000) {
        if (Version_Type == 3) {
            return 0;
        }
        if (Version_Type == 2) {
            return 0;
        }
    }
    conpane = &wk->cp->sw_lvbt;
    if (wk->cp->waza_flag[wk->sa->exsa_a_ix] == -1) {
        return 0;
    }
    if ((wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF) == 0x80) {
        return 0;
    }
    if (!wk->cp->waza_flag[wk->sa->exsa_a_ix]) {
        return 0;
    }
    cusw = conpane[wk->cp->btix[wk->sa->exsa_a_ix] & 0xFF];
    for (j = 3; j >= 0; j--) {
        if ((j == 3) && !(wk->cp->btix[wk->sa->exsa_a_ix] & 0x600)) {
            continue;
        }
        exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j]];
        if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exsa_a_ix][j] & 0xF]) {
            setup_comm_back(&wk->wu);
            wk->as = &asstbl_sa_air[wk->player_number][wk->sa->exsa_a_ix - 38][j].as;
            wk->wu.cg_cancel = 0;
            wk->sa->mp = -1;
            hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exsa_a_ix][j]);
            waza_slot_clear_all_p(wk);
            return 1;
        }
    }
    return 0;
}



s32 check_full_gauge_attack2(PLW* wk, s8 always) {
    u16* conpane;
    s16 j;
    s32 cusw;
    s32 exsw;
    if (wk->sa->mp != 1) {
        return 0;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (((Bonus_Game_Flag == 21) && (wk->bs2_on_car)) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }
        if (wk->sa->exs2_g_ix == 0) {
            return 0;
        }
        if (wk->sa->exs2_g_ix > 0x1C) {
            return 0;
        }
        if (always && !(wk->cp->btix[wk->sa->exs2_g_ix] & 0x100)) {
            return 0;
        }
        if (wk->cancel_timer == 0) {
            wk->permited_koa |= 0x40;
        }
        if (wk->cp->btix[wk->sa->exs2_g_ix] & 0x4000) {
            if (Version_Type == 3) {
                return 0;
            }
            if (Version_Type == 2) {
                return 0;
            }
        }
        conpane = &wk->cp->sw_lvbt;
        if (wk->cp->waza_flag[wk->sa->exs2_g_ix] == -1) {
            return 0;
        }
        if ((wk->cp->btix[wk->sa->exs2_g_ix] & 0xFF) == 0x80) {
            return 0;
        }
        if (!wk->cp->waza_flag[wk->sa->exs2_g_ix]) {
            return 0;
        }
        cusw = conpane[wk->cp->btix[wk->sa->exs2_g_ix] & 0xFF];
        for (j = 3; j >= 0; j--) {
            if ((j == 3) && !(wk->cp->btix[wk->sa->exs2_g_ix] & 0x600)) {
                continue;
            }
            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_g_ix][j]];
            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_g_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->exs2_g_ix - 20][j].as;
                wk->wu.cg_cancel = 0;
                wk->sa->mp = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exs2_g_ix][j]);
                waza_slot_clear_all_p(wk);
                return 1;
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->exs2_a_ix == 0) {
        return 0;
    }
    if ((wk->sa->exs2_a_ix) < 0x1C) {
        return 0;
    }
    if (always && !(wk->cp->btix[wk->sa->exs2_a_ix] & 0x100)) {
        return 0;
    }
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 0x40;
    }
    if (wk->cp->btix[wk->sa->exs2_a_ix] & 0x4000) {
        if (Version_Type == 3) {
            return 0;
        }
        if (Version_Type == 2) {
            return 0;
        }
    }
    conpane = &wk->cp->sw_lvbt;
    if (wk->cp->waza_flag[wk->sa->exs2_a_ix] == -1) {
        return 0;
    }
    if ((wk->cp->btix[wk->sa->exs2_a_ix] & 0xFF) == 0x80) {
        return 0;
    }
    if (!wk->cp->waza_flag[wk->sa->exs2_a_ix]) {
        return 0;
    }
    cusw = conpane[wk->cp->btix[wk->sa->exs2_a_ix] & 0xFF];
    for (j = 3; j >= 0; j--) {
        if ((j == 3) && !(wk->cp->btix[wk->sa->exs2_a_ix] & 0x600)) {
            continue;
        }
        exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_a_ix][j]];
        if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->exs2_a_ix][j] & 0xF]) {
            setup_comm_back(&wk->wu);
            wk->as = &asstbl_sa_air[wk->player_number][wk->sa->exs2_a_ix - 38][j].as;
            wk->wu.cg_cancel = 0;
            wk->sa->mp = -1;
            hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->exs2_a_ix][j]);
            waza_slot_clear_all_p(wk);
            return 1;
        }
    }
    return 0;
}



s32 check_super_arts_attack(PLW* wk) {
    u16* conpane;
    s16 j;
    s16 cusw;
    u16 exsw;
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }
    if (((Bonus_Game_Flag == 21) && (wk->bs2_on_car)) || (wk->wu.xyz[1].disp.pos < 1)) {
        if (wk->spmv_ng_flag & 0x40000000) {
            return 0;
        }
        if (wk->sa->nmsa_g_ix == 0) {
            return 0;
        }
        if (wk->sa->nmsa_g_ix > 0x1C) {
            return 0;
        }
        if (wk->cp->btix[wk->sa->nmsa_g_ix] & 0x4000) {
            if (Version_Type == 3) {
                return 0;
            }
            if (Version_Type == 2) {
                return 0;
            }
        }
        conpane = &wk->cp->sw_lvbt;
        if (wk->cp->waza_flag[wk->sa->nmsa_g_ix] == -1) {
            return 0;
        }
        if (((wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->nmsa_g_ix])) {
            cusw = conpane[wk->cp->btix[wk->sa->nmsa_g_ix] & 0xFF];
            for (j = 3; j >= 0; j--) {
                if ((j == 3) && !(wk->cp->btix[wk->sa->nmsa_g_ix] & 0x600)) {
                    continue;
                }
                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j]];
                if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_g_ix][j] & 0xF]) {
                    setup_comm_back(&wk->wu);
                    wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->nmsa_g_ix - 20][j].as;
                    wk->wu.cg_cancel = 0;
                    wk->sa->ok = -1;
                    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][j]);
                    waza_slot_clear_all_p(wk);
                    return 1;
                }
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->nmsa_a_ix == 0) {
        return 0;
    }
    if ((wk->sa->nmsa_a_ix) < 0x1C) {
        return 0;
    }
    if (wk->cp->btix[wk->sa->nmsa_a_ix] & 0x4000) {
        if (Version_Type == 3) {
            return 0;
        }
        if (Version_Type == 2) {
            return 0;
        }
    }
    conpane = &wk->cp->sw_lvbt;
    if (wk->cp->waza_flag[wk->sa->nmsa_a_ix] == -1) {
        return 0;
    }
    if (((wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF) != 0x80) && (wk->cp->waza_flag[wk->sa->nmsa_a_ix])) {
        cusw = conpane[wk->cp->btix[wk->sa->nmsa_a_ix] & 0xFF];
        for (j = 3; j >= 0; j--) {
            if ((j == 3) && !(wk->cp->btix[wk->sa->nmsa_a_ix] & 0x600)) {
                continue;
            }
            exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j]];
            if (exsw == cmdshot_conv_tbl[wk->cp->exdt[wk->sa->nmsa_a_ix][j] & 0xF]) {
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_air[wk->player_number][wk->sa->nmsa_a_ix - 38][j].as;
                wk->wu.cg_cancel = 0;
                wk->sa->ok = -1;
                hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][j]);
                waza_slot_clear_all_p(wk);
                return 1;
            }
        }
    }
    return 0;
}



s32 execute_super_arts(PLW* wk) {
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 1;
    }
    if ((wk->sa->gauge_type != 3) && pcon_dp_flag) {
        return 0;
    }
    if ((Bonus_Game_Flag == 21) && wk->bs2_on_car) {
        goto ground;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        goto air;
    }
ground:
    if (wk->spmv_ng_flag & 0x40000000) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (wk->sa->nmsa_g_ix > 28) {
        return 0;
    }
    if (wk->cp->btix[wk->sa->nmsa_g_ix] & 0x4000) {
        if (Version_Type == 3) {
            return 0;
        }
        if (Version_Type == 2) {
            return 0;
        }
    }
    setup_comm_back(&wk->wu);
    wk->as = &asstbl_sa_ground[wk->player_number][wk->sa->nmsa_g_ix - 20][0].as;
    wk->wu.cg_cancel = 0;
    wk->sa->ok = -1;
    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_g_ix][0]);
    waza_slot_clear_all_p(wk);
    return 1;
air:
    if (wk->spmv_ng_flag & 0x80000000) {
        return 0;
    }
    if (wk->sa->ok != 1) {
        return 0;
    }
    if (wk->sa->nmsa_a_ix < 28) {
        return 0;
    }
    if (wk->cp->btix[wk->sa->nmsa_a_ix] & 0x4000) {
        if (Version_Type == 3) {
            return 0;
        }
        if (Version_Type == 2) {
            return 0;
        }
    }
    setup_comm_back(&wk->wu);
    wk->as = &asstbl_sa_air[wk->player_number][wk->sa->nmsa_a_ix - 38][0].as;
    wk->wu.cg_cancel = 0;
    wk->sa->ok = -1;
    hissatsu_setup_union(wk, wk->cp->waza_r[wk->sa->nmsa_a_ix][0]);
    waza_slot_clear_all_p(wk);
    return 1;
}



s32 check_special_attack(PLW* wk) {
    s16 i;
    s16 j;
    u16 cusw;
    u16 exsw;
    u16* conpane;
    if (wk->cancel_timer == 0) {
        wk->permited_koa |= 2;
    }
    if (pcon_dp_flag) {
        return 0;
    }
    if (((Bonus_Game_Flag == 21) && wk->bs2_on_car) || (wk->wu.xyz[1].disp.pos <= 0)) {
        if (wk->spmv_ng_flag & 0x10000000) {
            return 0;
        }
        conpane = (u16*)wk->cp;
        for (i = 28; i < 38; i++) {
            if (wk->cp->waza_flag[i] == -1) {
                continue;
            }
            if ((wk->cp->btix[i] & 0x800) && shell_live_check(wk, i)) {
                continue;
            }
            if ((wk->cp->btix[i] & 0x1000) && (wk->metamorphose || (wk->sa->ok != -1))) {
                continue;
            }
            if (wk->cp->btix[i] & 0x4000) {
                if (Version_Type == 3) {
                    return 0;
                }
                if (Version_Type == 2) {
                    return 0;
                }
            }
            if (((wk->cp->btix[i] & 0xFF) == 0x80) || !wk->cp->waza_flag[i]) {
                continue;
            }
            cusw = conpane[wk->cp->btix[i] & 0xFF];
            for (j = 3; j >= 0; j--) {
                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
                if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                    continue;
                }
                if (j == 3) {
                    if (!(wk->cp->btix[i] & 0x600)) {
                        continue;
                    }
                    if (wk->metamorphose) {
                        if (wk->cp->btix[i] & 0x400) {
                            continue;
                        }
                    } else {
                        if ((wk->sa->mp == -1) || (wk->sa->ok == -1)) {
                            continue;
                        }
                        if (wk->cp->btix[i] & 0x400) {
                            if (wk->sa->ex != 1) {
                                continue;
                            }
                            wk->sa->ex = -1;
                        }
                    }
                }
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_ground[wk->player_number][i - 20][j].as;
                wk->wu.cg_cancel &= 0x40;
                hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                waza_flag_clear_only_1(wk->wu.id, i);
                grade_add_command_waza(wk->wu.id);
                return 1;
            }
        }
        return 0;
    }
    if (wk->spmv_ng_flag & 0x20000000) {
        return 0;
    }
    if ((wk->wu.mvxy.a[1].sp > 0) && (wk->wu.xyz[1].disp.pos < 32)) {
        return 0;
    }
    conpane = (u16*)wk->cp;
    for (i = 46; i < 56; i++) {
        if (wk->cp->waza_flag[i] == -1) {
            continue;
        }
        if ((wk->cp->btix[i] & 0x1000) && (wk->metamorphose || (wk->sa->ok != -1))) {
            continue;
        }
        if ((wk->cp->btix[i] & 0x2000) && (wk->wu.mvxy.a[0].sp < 0)) {
            continue;
        }
        if (wk->cp->btix[i] & 0x4000) {
            if (Version_Type == 3) {
                return 0;
            }
            if (Version_Type == 2) {
                return 0;
            }
        }
        if ((wk->cp->btix[i] & 0xFF) != 0x80) {
            if (!wk->cp->waza_flag[i]) {
                continue;
            }
            cusw = conpane[wk->cp->btix[i] & 0xFF];
            for (j = 3; j >= 0; j--) {
                exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
                if (exsw != cmdshot_conv_tbl[wk->cp->exdt[i][j] & 0xF]) {
                    continue;
                }
                if (j == 3) {
                    if (!(wk->cp->btix[i] & 0x600)) {
                        continue;
                    }
                    if (wk->metamorphose) {
                        if (wk->cp->btix[i] & 0x400) {
                            continue;
                        }
                    } else {
                        if ((wk->sa->mp == -1) || (wk->sa->ok == -1)) {
                            continue;
                        }
                        if (wk->cp->btix[i] & 0x400) {
                            if (wk->sa->ex != 1) {
                                continue;
                            }
                            wk->sa->ex = -1;
                        }
                    }
                }
                setup_comm_back(&wk->wu);
                wk->as = &asstbl_sa_air[wk->player_number][i - 38][j].as;
                wk->wu.cg_cancel &= 0x40;
                hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
                waza_flag_clear_only_1(wk->wu.id, i);
                grade_add_command_waza(wk->wu.id);
                return 1;
            }
            continue;
        }
        if (wk->cp->waza_flag[i]) {
            setup_comm_back(&wk->wu);
            wk->as = &asstbl_sa_air[wk->player_number][i - 38][0].as;
            wk->wu.cg_cancel &= 0x40;
            hissatsu_setup_union(wk, wk->cp->waza_r[i][0]);
            waza_flag_clear_only_1(wk->wu.id, i);
            grade_add_command_waza(wk->wu.id);
            return 1;
        }
    }
    return 0;
}



s32 check_leap_attack(PLW* wk) {
    if (pcon_dp_flag) {
        return 0;
    }
    wk->permited_koa |= 0x200;
    if (wk->cp->ca25 == 0) {
        return 0;
    }
    if (wk->cp->sw_lvbt & 0xF) {
        return 0;
    }
    if (Bonus_Game_Flag == 21 && wk->bs2_on_car) {
        goto go;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }
go:
    setup_comm_back(&wk->wu);
    wk->as = &asstbl_lv_D010[wk->player_number][0].as;
    hissatsu_setup_union(wk, wk->cp->waza_r[14][0]);
    return 1;
}


