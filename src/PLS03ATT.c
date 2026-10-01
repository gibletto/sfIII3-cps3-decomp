/*
 * PLS03ATT.C  Normal attack, taunt, throw and cancel checks
 *
 * Checks the player's buttons for normal attacks and related actions. check_nm_attack starts
 * standing, crouching and jumping normals; check_paring_attack and check_lever_up_attack handle
 * parry follow-ups and lever-up attacks; check_chouhatsu starts the taunt (personal action);
 * check_catch_attack and check_nagenuke_cmd start throws and throw escapes, using the range and
 * body helpers (get_nearing_range, get_em_body_range, decode_wst_data).
 * set_attack_routine_number switches the player into the attack routine. Button decoding lives
 * in shot_data_convert, renbanshot_conpaneshot and datacmd_conpanecmd; check_renda_cancel,
 * check_meoshi_cancel and check_sp_waza_flag handle chain and target-combo cancels.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "PLS02.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS03ATT.h"



s32 check_nm_attack(PLW* wk) {
    s16 kos;
    s16 koa;
    wk->permited_koa |= 4;
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    switch (wk->wu.pat_status) {
    case 20:
        koa = waza_select(wk, kos, 3);
        wk->as = &asstbl_lv_3010[wk->player_number][kos][koa].as;
        break;
    case 14:
        koa = waza_select(wk, kos, 6);
        wk->as = &asstbl_lv_3010[wk->player_number][kos][koa].as;
        break;
    case 26:
        koa = waza_select(wk, kos, 9);
        wk->as = &asstbl_lv_3010[wk->player_number][kos][koa].as;
        break;
    case 22:
        koa = waza_select(wk, kos, 2);
        wk->as = &asstbl_lv_2010[wk->player_number][kos][koa].as;
        break;
    case 16:
        koa = waza_select(wk, kos, 5);
        wk->as = &asstbl_lv_2010[wk->player_number][kos][koa].as;
        break;
    case 28:
        koa = waza_select(wk, kos, 8);
        wk->as = &asstbl_lv_2010[wk->player_number][kos][koa].as;
        break;
    case 24:
        koa = waza_select(wk, kos, 4);
        wk->as = &asstbl_lv_4010[wk->player_number][kos][koa].as;
        break;
    case 18:
        koa = waza_select(wk, kos, 7);
        wk->as = &asstbl_lv_4010[wk->player_number][kos][koa].as;
        break;
    case 30:
        koa = waza_select(wk, kos, 10);
        wk->as = &asstbl_lv_4010[wk->player_number][kos][koa].as;
        break;
    default:
        if (((Bonus_Game_Flag != 21) || !wk->bs2_on_car) && (wk->wu.xyz[1].disp.pos > 0)) {
            return 0;
        }
        if (wk->cp->sw_lvbt & 2) {
            koa = waza_select(wk, kos, 1);
            wk->as = &asstbl_lv_1010[wk->player_number][kos][koa].as;
        } else {
            koa = waza_select(wk, kos, 0);
            wk->as = &asstbl_lv_0010[wk->player_number][kos][koa].as;
        }
        break;
    }
    setup_comm_back(&wk->wu);
    wk->current_attack = shot_data_refresh(kos);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.cg_cancel &= 0xF8;
    return 1;
}



/* provisional name */
s32 check_jump_pat_status(PLW* wk) {
    if (!(wk->cp->sw_lvbt & 1)) {
        return 0;
    }
    if (((Bonus_Game_Flag != 21) || !wk->bs2_on_car) && (wk->wu.xyz[1].disp.pos >= 1)) {
        return 0;
    }
    hoken_muriyari_chakuchi(wk);
    wk->wu.pat_status = jump_pat_status_data[wk->wu.rl_flag != wk->wu.rl_waza][wk->cp->lever_dir];
    return 1;
}



/* provisional name */
s32 check_paring_attack(PLW* wk) {
    s16 kos;
    if (wk->spmv_ng_flag & 0x1000) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_paring_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 1;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



/* provisional name */
s32 check_dm_shot_attack(PLW* wk) {
    s16 kos;
    if (wk->spmv_ng_flag & 0x2000) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_dm_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



s32 check_chouhatsu(PLW* wk) {
    wk->permited_koa |= 0x80;
    if (wk->wu.xyz[1].disp.pos > 0) {
        return 0;
    }
    if (wk->cp->sw_lvbt & 0xF) {
        return 0;
    }
    if (wk->cp->ca36 == 0) {
        return 0;
    }
    wk->as = &asstbl_lv_E010[wk->player_number][0].as;
    setup_comm_back(&wk->wu);
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



/* provisional name */
s32 check_lever_up_attack(PLW* wk) {
    s16 kos;
    wk->permited_koa |= 8;
    if (wk->spmv_ng_flag & 0x4000) {
        return 0;
    }
    if (!(wk->cp->sw_new & 1)) {
        return 0;
    }
    if ((kos = shot_data_convert(wk->cp->sw_now)) < 0) {
        return 0;
    }
    setup_comm_back((WORK*)wk);
    wk->as = &asstbl_lever_up_att[wk->player_number][kos].as;
    set_attack_routine_number(wk);
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    return 1;
}



/* provisional name */
s32 check_nagenuke_cmd(PLW* wk) {
    if (wk->cat_break_reserve) {
        return 1;
    }
    if (wk->cp->sw_now & 0x660) {
        return 0;
    }
    if (wk->cp->ca14) {
        return 1;
    }
    return 0;
}



s32 check_catch_attack(PLW* wk) {
    s16 kos;
    if (pcon_dp_flag) {
        return 0;
    }
    if (wk->spmv_ng_flag & 0x2000) {
        return 0;
    }
    wk->permited_koa |= 0x100;
    if (wk->cp->ca14 == 0) {
        return 0;
    }
    kos = ((wk->cp->sw_new & 4) != 0) + (((wk->cp->sw_new & 8) != 0) * 2);
    if ((wk->wu.pat_status < 0xE) || (wk->wu.pat_status > 0x1E)) {
        if (!(nml_catch_h2_ok[0][wk->player_number] & 0x10)) {
            return 0;
        }
        if (wk->cp->sw_lvbt & 1) {
            return 0;
        }
        if (wk->cp->sw_lvbt & 2) {
            if (!(nml_catch_h2_ok[0][wk->player_number] & 1)) {
                return 0;
            }
            kos += 3;
        }
        wk->as = &asstbl_lv_A010[wk->player_number][kos].as;
    } else {
        if (!(nml_catch_h2_ok[1][wk->player_number] & 0x10)) {
            return 0;
        }
        if (wk->wu.xyz[1].disp.pos < 24) {
            return 0;
        }
        if (wk->cp->sw_lvbt & 2) {
            if (!(nml_catch_h2_ok[1][wk->player_number] & 1)) {
                return 0;
            }
            kos += 3;
        }
        wk->as = &asstbl_lv_B010[wk->player_number][kos].as;
    }
    setup_comm_back(&wk->wu);
    set_attack_routine_number(wk);
    wk->cancel_timer = 0;
    wk->wu.paring_attack_flag = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.hf.hit_flag = 0;
    wk->wu.cg_cancel = 0;
    return 1;
}



void set_attack_routine_number(PLW* wk) {
    wk->wu.routine_no[1] = 4;
    wk->wu.routine_no[2] = wk->as->r_no;
    wk->wu.routine_no[3] = 0;
    wk->wu.cg_type = 0;
}



s32 get_nearing_range(s16 pnum, s16 kos) {
    u16 nrange;
    const u16* asstbl;
    u16 lwork;
    nrange = 0;
    if ((kos = shot_data_convert(kos)) < 0) {
        return 0;
    }
    {
        const u8* row = (const u8*)asstbl_lv_0000 + (s16)(pnum * sizeof(asstbl_lv_0000[0]));
        asstbl = (const u16*)(row + kos * 4);
    }
    if ((lwork = asstbl[0] & 0x7FF)) {
        nrange = lwork;
    } else if ((lwork = asstbl[1] & 0x7FF)) {
        nrange = lwork;
    }
    return nrange;
}

/* provisional name */
s32 waza_select(wk, kos, sf)
PLW* wk;
s16 kos;
s16 sf;
{
    const u16* wst;
    switch (sf) {
    case 0:
        wst = asstbl_lv_0000[wk->player_number][kos];
        break;
    case 1:
        wst = asstbl_lv_1000[wk->player_number][kos];
        break;
    case 2:
        wst = asstbl_lv_2000[wk->player_number][kos];
        break;
    case 3:
        wst = asstbl_lv_3000[wk->player_number][kos];
        break;
    case 4:
        wst = asstbl_lv_4000[wk->player_number][kos];
        break;
    case 5:
        wst = asstbl_lv_2000[wk->player_number][kos];
        break;
    case 6:
        wst = asstbl_lv_3000[wk->player_number][kos];
        break;
    case 7:
        wst = asstbl_lv_4000[wk->player_number][kos];
        break;
    case 8:
        wst = asstbl_lv_2000[wk->player_number][kos];
        break;
    case 9:
        wst = asstbl_lv_3000[wk->player_number][kos];
        break;
    case 10:
        wst = asstbl_lv_4000[wk->player_number][kos];
        break;
    default:
        return 0;
    }
    if (decode_wst_data(wk, wst[0], wst[1])) {
        return 2;
    }
    if (decode_wst_data(wk, wst[1], wst[1])) {
        return 1;
    }
    return 0;
}



s32 decode_wst_data(PLW* wk, u16 cmd, s16 cmd_ex) {
    u16 lever;
    u16 rnum;
    if (cmd == 0) {
        return 0;
    }
    rnum = 0;
    lever = cmd & 0xF;
    switch (cmd & 0xF000) {
    case 0x4000:
        rnum = wk->cp->sw_new & lever;
        break;
    case 0x8000:
        rnum = (lever == (wk->cp->sw_new & 0xF));
        break;
    case 0x3000:
        rnum = cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex);
        break;
    case 0x7000:
        if ((wk->cp->sw_new & lever) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0xB000:
        if ((lever == (wk->cp->sw_new & 0xF)) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0x2000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0x1000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0xA000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0x9000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (lever == (wk->cp->sw_new & 0xF)) &&
            (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = 1;
        }
        break;
    case 0x6000:
        if ((wk->wu.mvxy.a[1].sp > 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }
        break;
    case 0x5000:
        if ((wk->wu.mvxy.a[1].sp <= 0) && (cmd_ex_check(wk->wu.xyz[1].disp.pos, cmd_ex))) {
            rnum = wk->cp->sw_new & lever;
        }
        break;
    default:
        if (get_em_body_range(&wk->wu) >= cmd) {
            rnum = 1;
        }
        break;
    }
    return rnum;
}



s32 get_em_body_range(WORK* wk) {
    WORK* em;
    s16* dad;
    s16 res_hs;
    if (Bonus_Game_Flag == 0x15 && wk->operator != 0) {
        em = (WORK*)((WORK*)wk->target_adrs)->my_effadrs;
        dad = (s16*)(em->hosei_adrs + (get_sel_hosei_tbl_ix(((WORK_Other*)em)->master_player) + 1));
        res_hs = wk->xyz[0].disp.pos - (em->xyz[0].disp.pos + dad[0] + (dad[1] / 2));
        if (res_hs < 0) {
            res_hs = -res_hs;
        }
        res_hs -= (dad[1] / 2);
        return res_hs;
    }
    em = (WORK*)wk->target_adrs;
    res_hs = (wk->xyz[0].disp.pos) - (em->xyz[0].disp.pos);
    if (res_hs < 0) {
        res_hs = -res_hs;
    }
    res_hs += em->hosei_adrs[1].hos_box[0];
    return res_hs;
}



s32 cmd_ex_check(s16 px, s16 cx) {
    if (cx) {
        if (cx < 0) {
            if (px + cx <= 0) {
                return 1;
            }
        } else if (px - cx >= 0) {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 shot_data_convert(s32 sw) {
    s16 i;
    s16 rnum = -1;
    for (i = 0; i < 6; i++) {
        if (sw & shot_prio[i][0]) {
            rnum = shot_prio[i][1];
        }
    }
    return rnum;
}



s16 shot_data_refresh(s16 sw) {
    return shot_refresh[sw];
}



s16 renbanshot_conpaneshot(const s16* dadr, s16 pow) {
    return rc_shot_conv[dadr[pow] & 0xF];
}



s32 datacmd_conpanecmd(s16 dat) {
    s16 r;
    r = (dat & 0x700) >> 1 | dat & 0x7F;
    return r;
}



s32 check_renda_cancel(PLW* wk) {
    if (wk->wu.rl_flag != wk->wu.rl_waza) {
        return 0;
    }
    wk->permited_koa |= 32;
    if (wk->wu.pat_status == renda_status_table[(wk->cp->sw_new & 3)] &&
        wk->current_attack == (wk->cp->sw_now & 0x770)) {
        setup_comm_back((WORK*)wk);
        wk->wu.cg_ix = wk->wu.cg_eftype * wk->wu.cgd_type - (wk->wu.cgd_type * 2);
        wk->wu.cg_next_ix = 0;
        wk->wu.cg_ctr = 1;
        wk->wu.meoshi_hit_flag = 0;
        wk->wu.att_hit_ok = 0;
        wk->wu.hf.hit_flag = 0;
        wk->caution_flag = 1;
        wk->cancel_timer = 0;
        wk->wu.cg_cancel &= 0xE0;
        return 1;
    }
    return 0;
}



/* provisional name */
s32 check_sp_waza_flag(PLW* wk) {
    s16 i;
    s16 rnum = 0;
    for (i = 20; i < 38; i++) {
        if (wk->cp->waza_flag[i]) {
            rnum = 1;
        }
    }
    return rnum;
}



/* provisional name */
s32 check_meoshi_cancel(PLW* wk) {
    s16 i;
    s16 tdat;
    s16 wdat;
    wk->permited_koa |= 0x10;
    if (wk->wu.meoshi_hit_flag == 0) {
        return 0;
    }
    tdat = wk->wu.cg_meoshi & 0x8F;
    if (tdat != 0) {
        wdat = cnmc_conv_data[wk->cp->sw_new & 0xF];
        tdat &= 0xF;
        if (wk->wu.cg_meoshi & 0x80) {
            for (i = 0; i < 6; i++) {
                if (cnmc_Z_lever_data[tdat][i] == -1) {
                    return 0;
                }
                if (wdat == cnmc_Z_lever_data[tdat][i]) {
                    goto matched;
                }
            }
        } else {
            for (i = 0; i < 8; i++) {
                if (cnmc_z_lever_data[tdat][i] == -1) {
                    return 0;
                }
                if (wdat == cnmc_z_lever_data[tdat][i]) {
                    goto matched;
                }
            }
        }
        return 0;
    }
matched:
    if ((tdat = wk->wu.cg_meoshi & 0x770) == 0) {
        if (!(wk->wu.cg_meoshi & 0x800)) {
            return 0;
        }
        goto cancel;
    }
    wdat = wk->cp->sw_new & 0x770;
    if (wdat & ~tdat) {
        return 0;
    }
    if (shot_data_convert(wk->cp->sw_now) >= 0) {
        if (wk->wu.cg_meoshi & 0x800) {
            goto cancel;
        }
        goto end;
    }
    if (!(wk->wu.cg_cancel & 0x80)) {
        return 0;
    }
    wdat = wk->cp->sw_off & 0x770;
    if (wdat & ~tdat) {
        return 0;
    }
    if (shot_data_convert(wk->cp->sw_off) < 0) {
        return 0;
    }
    if (!(wk->wu.cg_meoshi & 0x800)) {
        return 0;
    }
cancel:
    if (wk->wu.cg_meoshi & 0x1000) {
        if (char_move_cmms3(wk) == 0) {
            return 0;
        }
    } else {
        char_move_cmms2((WORK*)wk);
    }
    wk->wu.hf.hit_flag = 0;
    wk->wu.att_hit_ok = 0;
    wk->wu.meoshi_hit_flag = 0;
    wk->wu.cg_cancel &= 0x60;
    if ((wk->tc_1st_flag == 0) && (wk->wu.now_koc == 4)) {
        grade_add_target_combo(wk->wu.id);
    }
    wk->tc_1st_flag = 1;
    return 1;
end:
    if ((wk->tc_1st_flag == 0) && wk->wu.now_koc == 4) {
        grade_add_target_combo(wk->wu.id);
    }
    check_nm_attack(wk);
    wk->tc_1st_flag = 1;
    return 1;
}

s32 get_meoshi_lever(s16 lever)
{
    return gml_real_lever_data[lever & 0xF];
}

s32 get_meoshi_shot(s16 shot) {
    return ((shot & 0x700) >> 1) + (shot & 0x70);
}
