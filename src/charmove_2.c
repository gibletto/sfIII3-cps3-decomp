/*
 * CHARMOVE_2.C  cg script interpreter (character animation and action scripts) (part 2)
 *
 * Routines: comm_ixfw, comm_ixbw, comm_quax, comm_quay, comm_if_s, comm_rapp, comm_rapk, comm_gets,
 * comm_s123, comm_s456, comm_a123, comm_a456, ...
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLSGAUGE.h"
#include "PLS02.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS03ATT.h"
#include "Grade.h"
#include "EFFF1.h"
#include "EFFF2_code.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "charmove_2.h"
#include "fighter.h"



s32 comm_ixfw(WORK* wk, CHAR_CMD* ctc) {
    if ((test_flag == 0) || (ixbfw_cut == 0)) {
        wk->cg_ix += (ctc->pat - 1) * wk->cgd_type;
    }
    return 1;
}



s32 comm_ixbw(WORK* wk, CHAR_CMD* ctc) {
    if ((test_flag == 0) || (ixbfw_cut == 0)) {
        wk->cg_ix -= (ctc->pat + 1) * wk->cgd_type;
    }
    return 1;
}



s32 comm_quax(WORK* _p0, CHAR_CMD* ctc) {
    bg_w.quake_x_index = ctc->koc;
    return 1;
}

s32 comm_quay(s32 wk_adrs, CHAR_CMD* ctc)
{

    bg_w.quake_y_index = ctc->koc;
    return 1;
}



s32 comm_if_s(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_shot(wk);
    if (my_shdat == shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_rapp(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[9]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }
        return 1;
    }
    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[9]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }
    return 1;
}



s32 comm_rapk(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[11]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }
        return 1;
    }
    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[11]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }
    return 1;
}



s32 comm_gets(WORK* wk, CHAR_CMD* ctc) {
    u32* src = wk->set_char_ad;
    u32* dst = (u32*)&wk->cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    return 1;
}



s32 comm_s123(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[1] = ctc->koc;
    wk->routine_no[2] = ctc->ix;
    wk->routine_no[3] = ctc->pat;
    return 1;
}



s32 comm_s456(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[4] = ctc->koc;
    wk->routine_no[5] = ctc->ix;
    wk->routine_no[6] = ctc->pat;
    return 1;
}



s32 comm_a123(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[4] += ctc->koc;
    wk->routine_no[5] += ctc->ix;
    wk->routine_no[6] += ctc->pat;
    return 1;
}



s32 comm_a456(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[4] += ctc->koc;
    wk->routine_no[5] += ctc->ix;
    wk->routine_no[6] += ctc->pat;
    return 1;
}



s32 comm_stop(PLW* wk, CHAR_CMD* ctc) {
    PLW* wk2;
    if (test_flag == 0) {
        wk->wu.dm_stop = 0;
        wk->wu.hit_stop = ctc->koc;
        wk2 = (PLW*)wk->wu.target_adrs;
        wk2->wu.hit_stop = ctc->ix;
        wk2->sa_stop_sai = ctc->ix - 4;
        if (wk2->sa_stop_sai < 0) {
            wk2->sa_stop_sai = 1;
        }
        setup_shell_hit_stop(&wk->wu, ctc->ix, ctc->pat);
        setup_shell_hit_stop(&wk2->wu, ctc->ix, 0);
        wk->sa_stop_flag = 0;
        wk2->sa_stop_flag = 2;
        wk2->just_sa_stop_timer = Game_timer;
    }
    return 1;
}



s32 comm_smhf(WORK* wk, CHAR_CMD* ctc) {
    wk->meoshi_hit_flag = ctc->koc;
    return 1;
}



s32 comm_ngme(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    emwk = (WORK*)wk->hit_adrs;
    emwk->routine_no[1] = 3;
    emwk->routine_no[2] = 1;
    emwk->routine_no[3] = 1;
    if (test_flag) {
        wk->cmyd.pat = 1;
    }
    return 1;
}



s32 comm_ngem(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    emwk = (WORK*)wk->hit_adrs;
    emwk->routine_no[1] = 3;
    emwk->routine_no[2] = 2;
    emwk->routine_no[3] = 1;
    if (test_flag) {
        wk->cmyd.pat = 2;
    }
    return 1;
}



s32 comm_iflb(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_lvsh(wk);
    if (my_shdat == shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_asxy(WORK* wk, CHAR_CMD* ctc) {
    s16* from_rom2 = &wk->step_xy_table[ctc->koc];
    s32 st = *from_rom2++;
    st <<= 8;
    if (wk->rl_flag) {
        wk->xyz[0].cal += st;
    } else {
        wk->xyz[0].cal -= st;
    }
    st = *from_rom2;
    st <<= 8;
    wk->xyz[1].cal += st;
    return 1;
}



s32 comm_schx(WORK* wk, CHAR_CMD* ctc) {
    switch (ctc->koc) {
    case 0:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * ctc->ix) / ctc->pat;
        break;
    case 2:
        wk->mvxy.a[0].sp = (wk->mvxy.a[0].sp * ctc->ix) / ctc->pat;
    case 1:
        wk->mvxy.d[0].sp = (wk->mvxy.d[0].sp * ctc->ix) / ctc->pat;
        break;
    }
    return 1;
}



s32 comm_schy(WORK* wk, CHAR_CMD* ctc) {
    switch (ctc->koc) {
    case 0:
        wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * ctc->ix) / ctc->pat;
        break;
    case 2:
        wk->mvxy.a[1].sp = (wk->mvxy.a[1].sp * ctc->ix) / ctc->pat;
    case 1:
        wk->mvxy.d[1].sp = (wk->mvxy.d[1].sp * ctc->ix) / ctc->pat;
        break;
    }
    return 1;
}



s32 comm_back(WORK* wk, CHAR_CMD* _p1) {
    set_char_move_init2(wk, wk->cmbk.koc, wk->cmbk.ix, wk->cmbk.pat, 0);
    return 0;
}



s32 comm_mvix(WORK* wk, CHAR_CMD* ctc) {
    wk->mvxy.index = ctc->koc;
    return 1;
}



s32 comm_sajp(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        if (My_char[wk->id] != PL_NO12 && ((PLW*)wk)->sa->kind_of_arts == ctc->koc && ((PLW*)wk)->sa->ok == -1) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }
    } else {
        wk = (WORK*)((WORK_Other*)wk)->my_master;
        if (wk->work_id == 1 && ((PLW*)wk)->sa->kind_of_arts == ctc->koc && ((PLW*)wk)->sa->ok == -1) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }
    }
    return 1;
}



s32 comm_ccch(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->koc) {
        wk->extra_col += ctc->ix;
        wk->extra_col &= 0x2FFF;
    } else {
        wk->extra_col = ctc->ix;
    }
    return 1;
}



s32 comm_wset(WORK* wk, CHAR_CMD* ctc) {
    switch (ctc->ix) {
    default:
    case 0:
        wk->cmwk[ctc->koc & 0xF] = ctc->pat;
        break;
    case 1:
        wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
        break;
    case 2:
        wk->cmwk[ctc->koc & 0xF] |= ctc->pat;
        break;
    case 3:
        wk->cmwk[ctc->koc & 0xF] += ctc->pat;
        break;
    case 4:
        wk->cmwk[ctc->koc & 0xF] -= ctc->pat;
        break;
    case 5:
        wk->cmwk[ctc->koc & 0xF] *= ctc->pat;
        break;
    case 6:
        wk->cmwk[ctc->koc & 0xF] /= ctc->pat;
        break;
    }
    return 1;
}



s32 comm_wswk(WORK* wk, CHAR_CMD* ctc) {
    switch (ctc->ix) {
    case 0:
    default:
        wk->cmwk[ctc->koc & 0xF] = wk->cmwk[ctc->pat & 0xF];
        break;
    case 1:
        wk->cmwk[ctc->koc & 0xF] &= wk->cmwk[ctc->pat & 0xF];
        break;
    case 2:
        wk->cmwk[ctc->koc & 0xF] |= wk->cmwk[ctc->pat & 0xF];
        break;
    case 3:
        wk->cmwk[ctc->koc & 0xF] += wk->cmwk[ctc->pat & 0xF];
        break;
    case 4:
        wk->cmwk[ctc->koc & 0xF] -= wk->cmwk[ctc->pat & 0xF];
        break;
    case 5:
        wk->cmwk[ctc->koc & 0xF] *= wk->cmwk[ctc->pat & 0xF];
        break;
    case 6:
        wk->cmwk[ctc->koc & 0xF] /= wk->cmwk[ctc->pat & 0xF];
        break;
    }
    return 1;
}



s32 comm_wadd(WORK* wk, CHAR_CMD* ctc) {
    wk->cmwk[ctc->koc & 0xF] += ctc->ix;
    wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
    return 1;
}



s32 comm_wceq(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] == ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wcne(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] != ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wcgt(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] > ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wclt(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] < ctc->ix) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wadd2(WORK* wk, CHAR_CMD* ctc) {
    wk->cmwk[ctc->koc & 0xF] += wk->cmwk[ctc->ix & 0xF];
    wk->cmwk[ctc->koc & 0xF] &= ctc->pat;
    return 1;
}



s32 comm_wceq2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] == wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wcne2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] != wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wcgt2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] > wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_wclt2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmwk[ctc->koc & 0xF] < wk->cmwk[ctc->ix & 0xF]) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_rapp2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[8]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }
        return 1;
    }
    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[8]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }
    return 1;
}



s32 comm_rapk2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        if (wcp[wk->id].waza_flag[10]) {
            setup_comm_back(wk);
            set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
            return 0;
        }
        return 1;
    }
    if (wcp[((WORK_Other*)wk)->master_id & 1].waza_flag[10]) {
        setup_comm_back(wk);
        set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
        return 0;
    }
    return 1;
}



s32 comm_iflg(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->koc == 0) {
        if (wk->cmwk[11] < ctc->ix) {
            return 1;
        }
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    if (((WORK*)wk->target_adrs)->cmwk[11] < ctc->ix) {
        return 1;
    }
    return decord_if_jump(wk, ctc, ctc->pat);
}



s32 comm_mpcy(WORK* wk, CHAR_CMD* ctc) {
    s16 ans = 0;
    switch (ctc->ix) {
    case 1:
        if (wk->xyz[1].disp.pos > ctc->koc) {
            ans = 1;
        }
        break;
    case 2:
        if (wk->xyz[1].disp.pos < ctc->koc) {
            ans = 1;
        }
        break;
    default:
        if (wk->xyz[1].disp.pos == ctc->koc) {
            ans = 1;
        }
        break;
    }
    if (ans == 0) {
        return 1;
    }
    return decord_if_jump(wk, ctc, ctc->pat);
}



s32 comm_epcy(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    s16 ans = 0;
    switch (ctc->ix) {
    case 1:
        if (emwk->xyz[1].disp.pos > ctc->koc) {
            ans = 1;
        }
        break;
    case 2:
        if (emwk->xyz[1].disp.pos < ctc->koc) {
            ans = 1;
        }
        break;
    default:
        if (emwk->xyz[1].disp.pos == ctc->koc) {
            ans = 1;
        }
        break;
    }
    if (ans == 0) {
        return 1;
    }
    return decord_if_jump(wk, ctc, ctc->pat);
}



s32 comm_imgs(PLW* wk, CHAR_CMD* ctc) {
    PLW* tk;
    if (test_flag == 0) {
        tk = (PLW*)wk->wu.target_adrs;
        switch (ctc->koc) {
        case 0:
            wk->image_setup_flag = 1;
            wk->image_data_index = ctc->ix;
            break;
        default:
            wk->image_setup_flag = 1;
            wk->image_data_index = ctc->ix;
        case 1:
            tk->image_setup_flag = 1;
            tk->image_data_index = ctc->ix;
            break;
        }
    }
    return 1;
}



s32 comm_imgc(PLW* wk, CHAR_CMD* ctc) {
    PLW* tk = (PLW*)wk->wu.target_adrs;
    switch (ctc->koc) {
    case 0:
        wk->image_setup_flag = 0;
        break;
    default:
        wk->image_setup_flag = 0;
    case 1:
        tk->image_setup_flag = 0;
        break;
    }
    return 1;
}



s32 comm_rvxy(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        break;
    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
    default:
        if (wk->rl_flag) {
            emwk->xyz[0].cal = wk->xyz[0].cal + (ctc->ix << 8);
        } else {
            emwk->xyz[0].cal = wk->xyz[0].cal - (ctc->ix << 8);
        }
        emwk->xyz[1].cal = wk->xyz[1].cal + (ctc->pat << 8);
        break;
    }
    return 1;
}



s32 comm_rv_x(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }
        break;
    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal = emwk->xyz[0].cal + (ctc->ix << 8);
        } else {
            wk->xyz[0].cal = emwk->xyz[0].cal - (ctc->ix << 8);
        }
    default:
        if (wk->rl_flag) {
            emwk->xyz[0].cal = wk->xyz[0].cal + (ctc->ix << 8);
        } else {
            emwk->xyz[0].cal = wk->xyz[0].cal - (ctc->ix << 8);
        }
        break;
    }
    return 1;
}



s32 comm_rv_y(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    switch (ctc->koc) {
    case 0:
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
        break;
    case 2:
        wk->xyz[1].cal = emwk->xyz[1].cal + (ctc->pat << 8);
    default:
        emwk->xyz[1].cal = wk->xyz[1].cal + (ctc->pat << 8);
        break;
    }
    return 1;
}



s32 comm_ccfl(PLW* wk, CHAR_CMD* _p1) {
    wk->caution_flag = 0;
    return 1;
}



s32 comm_myhp(WORK* wk, CHAR_CMD* ctc) {
    s16 num = 0;
    s32 cmpvital = (Max_vitality * ctc->ix) / 100;
    switch (ctc->koc) {
    case 1:
        if (wk->vital_new > cmpvital) {
            num = 1;
        }
        break;
    case 2:
        if (wk->vital_new < cmpvital) {
            num = 1;
        }
        break;
    default:
        if (wk->vital_new == cmpvital) {
            num = 1;
        }
        break;
    }
    if (num) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}



s32 comm_emhp(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk = (WORK*)wk->target_adrs;
    s16 num = 0;
    s32 cmpvital = (Max_vitality * ctc->ix) / 100;
    switch (ctc->koc) {
    case 1:
        if (emwk->vital_new > cmpvital) {
            num = 1;
        }
        break;
    case 2:
        if (emwk->vital_new < cmpvital) {
            num = 1;
        }
        break;
    default:
        if (emwk->vital_new == cmpvital) {
            num = 1;
        }
        break;
    }
    if (num) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return 1;
}

u32 comm_exbgs(u32 wk_adrs, CHAR_CMD* ctc, u32 arg2, u32 arg3) {
    effect_F1_init(wk_adrs, (u8)ctc->koc);
    return 1;
}

u32 comm_exbgc(WORK* wk)
{

    another_bg[wk->id] = 0;
    return 1;
}



s32 comm_atmf(PLW* wk, CHAR_CMD* ctc) {
    wk->atemi_flag = ctc->koc;
    wk->atemi_point = ctc->ix;
    return 1;
}



s32 comm_chkwf(PLW* wk, CHAR_CMD* ctc) {
    s16 ix;
    if (wk->cp->waza_flag[ctc->koc] == 0 || wk->cp->waza_flag[ctc->koc] == -1) {
        ix = ctc->pat;
    } else {
        waza_flag_clear_only_1(wk->wu.id, ctc->koc);
        ix = ctc->ix;
    }
    return decord_if_jump(&wk->wu, ctc, ix);
}



s32 comm_retmj(PLW* wk, CHAR_CMD* ctc) {
    u32* dst;
    u32* src;
    wk->wu.now_koc = wk->wu.cmb2.koc;
    wk->wu.char_index = wk->wu.cmb2.ix;
    wk->wu.cg_ix = wk->wu.cmb2.pat;
    wk->wu.set_char_ad = (u32*)wk->wu.char_table[wk->wu.now_koc][wk->wu.char_index];
    src = wk->wu.set_char_ad;
    dst = (u32*)&wk->wu.cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    wk->meoshi_jump_flag = 0;
    return 0;
}



s32 comm_sstx(WORK* wk, CHAR_CMD* ctc) {
    SST sstx;
    SST* p;
    s32 x;

    p = &sstx;
    p->patl = 0;
    p->pats.h = ctc->pat;
    p->patl = p->patl >> 8;
    x = p->patl;
    switch (ctc->koc) {
    case 0:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.a[0].sp = x;
            break;
        case 1:
            wk->mvxy.a[0].sp &= x;
            break;
        case 2:
            wk->mvxy.a[0].sp |= x;
            break;
        case 3:
            wk->mvxy.a[0].sp += x;
            break;
        case 4:
            wk->mvxy.a[0].sp -= x;
            break;
        case 5:
            wk->mvxy.a[0].sp *= x;
            break;
        case 6:
            wk->mvxy.a[0].sp /= x;
            break;
        }
        break;
    case 2:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.a[0].sp = x;
            break;
        case 1:
            wk->mvxy.a[0].sp &= x;
            break;
        case 2:
            wk->mvxy.a[0].sp |= x;
            break;
        case 3:
            wk->mvxy.a[0].sp += x;
            break;
        case 4:
            wk->mvxy.a[0].sp -= x;
            break;
        case 5:
            wk->mvxy.a[0].sp *= x;
            break;
        case 6:
            wk->mvxy.a[0].sp /= x;
            break;
        }
    case 1:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.d[0].sp = p->patl;
            break;
        case 1:
            wk->mvxy.d[0].sp &= p->patl;
            break;
        case 2:
            wk->mvxy.d[0].sp |= p->patl;
            break;
        case 3:
            wk->mvxy.d[0].sp += p->patl;
            break;
        case 4:
            wk->mvxy.d[0].sp -= p->patl;
            break;
        case 5:
            wk->mvxy.d[0].sp *= p->patl;
            break;
        case 6:
            wk->mvxy.d[0].sp /= p->patl;
            break;
        }
        break;
    default:
        wk->mvxy.kop[0] = ctc->pat;
        break;
    }
    return 1;
}



s32 comm_ssty(WORK* wk, CHAR_CMD* ctc) {
    SST ssty;
    SST* p;
    s32 x;

    p = &ssty;
    p->patl = 0;
    p->pats.h = ctc->pat;
    p->patl = p->patl >> 8;
    x = p->patl;
    switch (ctc->koc) {
    case 0:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.a[1].sp = x;
            break;
        case 1:
            wk->mvxy.a[1].sp &= x;
            break;
        case 2:
            wk->mvxy.a[1].sp |= x;
            break;
        case 3:
            wk->mvxy.a[1].sp += x;
            break;
        case 4:
            wk->mvxy.a[1].sp -= x;
            break;
        case 5:
            wk->mvxy.a[1].sp *= x;
            break;
        case 6:
            wk->mvxy.a[1].sp /= x;
            break;
        }
        break;
    case 2:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.a[1].sp = x;
            break;
        case 1:
            wk->mvxy.a[1].sp &= x;
            break;
        case 2:
            wk->mvxy.a[1].sp |= x;
            break;
        case 3:
            wk->mvxy.a[1].sp += x;
            break;
        case 4:
            wk->mvxy.a[1].sp -= x;
            break;
        case 5:
            wk->mvxy.a[1].sp *= x;
            break;
        case 6:
            wk->mvxy.a[1].sp /= x;
            break;
        }
    case 1:
        switch (ctc->ix) {
        case 0:
        default:
            wk->mvxy.d[1].sp = p->patl;
            break;
        case 1:
            wk->mvxy.d[1].sp &= p->patl;
            break;
        case 2:
            wk->mvxy.d[1].sp |= p->patl;
            break;
        case 3:
            wk->mvxy.d[1].sp += p->patl;
            break;
        case 4:
            wk->mvxy.d[1].sp -= p->patl;
            break;
        case 5:
            wk->mvxy.d[1].sp *= p->patl;
            break;
        case 6:
            wk->mvxy.d[1].sp /= p->patl;
            break;
        }
        break;
    default:
        wk->mvxy.kop[1] = ctc->pat;
        break;
    }
    return 1;
}

s32 comm_ngda(WORK* wk, CHAR_CMD* ctc)
{

    wk->cmyd.koc = ctc->koc;
    wk->cmyd.ix = ctc->ix;
    wk->cmyd.pat = ctc->pat;
    return 1;
}



s32 comm_flip(WORK* wk, CHAR_CMD* _p1) {
    wk->rl_flag = (wk->rl_flag + 1) & 1;
    return 1;
}



s32 comm_kage(WORK* wk, CHAR_CMD* ctc) {
    wk->kage_hx = ctc->koc;
    wk->kage_hy = ctc->ix;
    wk->kage_char = ctc->pat;
    return 1;
}



s32 comm_dspf(WORK* wk, CHAR_CMD* ctc) {
    wk->disp_flag = ctc->koc;
    return 1;
}



s32 comm_ifrlf(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->koc) {
        if (wk->rl_flag == wk->rl_waza) {
            return decord_if_jump(wk, ctc, ctc->pat);
        }
        return decord_if_jump(wk, ctc, ctc->ix);
    }
    if (wk->rl_flag == wk->rl_waza) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }
    return decord_if_jump(wk, ctc, ctc->pat);
}



s32 comm_srlf(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->koc) {
        if (wk->rl_flag != wk->rl_waza) {
            wk->rl_flag = wk->rl_waza;
        }
    } else if (wk->rl_flag == wk->rl_waza) {
        wk->rl_flag = (wk->rl_flag + 1) & 1;
    }
    return 1;
}



s32 comm_bgrlf(WORK* wk, CHAR_CMD* ctc) {
    s16 ix;
    if (wk->rl_flag) {
        if (wk->position_x > bg_w.bgw[1].pos_x_work) {
            ix = ctc->pat;
        } else {
            ix = ctc->ix;
        }
    } else if (wk->position_x < bg_w.bgw[1].pos_x_work) {
        ix = ctc->pat;
    } else {
        ix = ctc->ix;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_scmd(PLW* wk, CHAR_CMD* ctc) {
    wk->cmd_request = ctc->koc;
    return 1;
}



s32 comm_rljmp(WORK* wk, CHAR_CMD* ctc) {
    if (wk->rl_flag) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->ix);
}



s32 comm_ifs2(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_shot(wk);
    if (my_shdat & shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_abbak(WORK* wk, CHAR_CMD* _p1) {
    set_char_move_init2(wk, wk->cmb3.koc, wk->cmb3.ix, wk->cmb3.pat, 0);
    return 0;
}



s32 comm_sse(WORK* wk, CHAR_CMD* ctc) {
    wk->cg_se = ctc->koc;
    if (wk->cg_se & 0x800) {
        wk->cg_se = (*(u16**)(wk->se_random_table + (wk->cg_se & 0x7FF)))[random_16_com()];
    }
    if (wk->cg_se) {
        sound_effect_request[wk->cg_se](wk, check_xcopy_filter_se_req(wk));
    }
    return 1;
}



s32 comm_s_chg(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_shot_now_off(wk);
    if (my_shdat == shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_schg2(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_shot_now_off(wk);
    if (my_shdat & shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 comm_rhsja(PLW* wk, CHAR_CMD* ctc) {
    wk->wu.cmhs.koc = ctc->koc;
    wk->wu.cmhs.ix = ctc->ix;
    wk->wu.cmhs.pat = ctc->pat;
    wk->hsjp_ok = 1;
    return 1;
}



s32 comm_uhsja(PLW* wk, CHAR_CMD* ctc) {
    setup_comm_back(&wk->wu);
    wk->hsjp_ok = 0;
    set_char_move_init2(&wk->wu, wk->wu.cmhs.koc, wk->wu.cmhs.ix, wk->wu.cmhs.pat, 0);
    return 0;
}



s32 comm_ifcom(WORK* wk, CHAR_CMD* ctc) {
    if (wk->operator) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->ix);
}



s32 comm_axjmp(WORK* wk, CHAR_CMD* ctc) {
    if (*(s16*)&wk->mvxy.a[0] > 2) {
        return decord_if_jump(wk, ctc, ctc->koc);
    }
    if (*(s16*)&wk->mvxy.a[0] < -2) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->ix);
}



s32 comm_ayjmp(WORK* wk, CHAR_CMD* ctc) {
    if (wk->mvxy.a[1].real.h > 0) {
        return decord_if_jump(wk, ctc, ctc->koc);
    }
    if (wk->mvxy.a[1].real.h < 0) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->ix);
}



s32 comm_ifs3(WORK* wk, CHAR_CMD* ctc) {
    u16 shdat;
    u16 my_shdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_shdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_shdat = ctc->koc;
    }
    shdat = get_comm_if_shot_now(wk);
    if (my_shdat & shdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}



s32 decord_if_jump(WORK* wk, CHAR_CMD* cpc, s16 ix) {
    s16 rnum;
    switch (ix & 0xE000) {
    case 0x4000:
        wk->cg_ix += ((ix & 0xFF) - 1) * wk->cgd_type;
        rnum = 1;
        break;
    case 0x8000:
        wk->cg_ix -= ((ix & 0xFF) + 1) * wk->cgd_type;
        rnum = 1;
        break;
    case 0x2000:
        rnum = comm_if_jmp_tbl[ix & 0xFF](wk, cpc);
        break;
    default:
        wk->cg_ix = (ix - 2) * wk->cgd_type;
        rnum = 1;
        break;
    }
    return rnum;
}



s32 get_comm_if_lever(WORK* wk) {
    u16 num;
    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_new & 0xF;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_new & 0xF;
    }
    return num;
}



s32 get_comm_if_shot(WORK* wk) {
    u16 num;
    if (wk->work_id == 1) {
        num = wcp[(s16)wk->id].sw_new & 0x770;
    } else {
        num = wcp[(s16)(((WORK_Other*)wk)->master_id & 1)].sw_new & 0x770;
    }
    return num;
}



s32 get_comm_if_shot_now_off(WORK* wk) {
    u16 num;
    if (wk->work_id == 1) {
        num = wcp[wk->id].sw_now & 0x770;
    } else {
        num = wcp[((WORK_Other*)wk)->master_id & 1].sw_now & 0x770;
    }
    if (wk->cg_cancel & 0x80) {
        if (wk->work_id == 1) {
            num |= wcp[wk->id].sw_off & 0x770;
        } else {
            num |= wcp[((WORK_Other*)wk)->master_id & 1].sw_off & 0x770;
        }
    }
    return num;
}



s32 get_comm_if_shot_now(WORK* wk) {
    u16 num;
    if (wk->work_id == 1) {
        num = wcp[(s16)wk->id].sw_now & 0x770;
    } else {
        num = wcp[(s16)(((WORK_Other*)wk)->master_id & 1)].sw_now & 0x770;
    }
    return num;
}



s32 get_comm_if_lvsh(WORK* wk) {
    u16 num;
    if (wk->work_id == 1) {
        num = wcp[(s16)wk->id].sw_new & 0x77F;
    } else {
        num = wcp[(s16)(((WORK_Other*)wk)->master_id & 1)].sw_new & 0x77F;
    }
    return num;
}



s32 get_comm_djmp_lever_dir(PLW* wk) {
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



void setup_comm_back(WORK* wk) {
    wk->K5_init_flag = 1;
    wk->cmbk.koc = wk->now_koc;
    wk->cmbk.ix = wk->char_index;
    wk->cmbk.pat = (wk->cg_ix / wk->cgd_type) + 2;
}



void setup_comm_retmj(WORK* wk) {
    wk->cmb2.koc = wk->now_koc;
    wk->cmb2.ix = wk->char_index;
    wk->cmb2.pat = wk->cg_ix;
}



void setup_comm_abbak(WORK* wk) {
    wk->cmb3.koc = wk->now_koc;
    wk->cmb3.ix = wk->char_index;
    wk->cmb3.pat = (wk->cg_ix / wk->cgd_type) + 2;
}



void check_cgd_patdat(WORK* wk) {
    ST st;
    u32* dst;
    u32* src;
    s16 i;
    s16* from_rom2;
    src = wk->set_char_ad + wk->cg_ix;
    dst = (u32*)&wk->cg_ctr;
    for (i = 0; i < wk->cgd_type; i++) {
        *dst++ = *src++;
    }
    switch (wk->cgd_type) {
    case 6:
        if (wk->cg_add_xy) {
            from_rom2 = wk->step_xy_table + wk->cg_add_xy;
            st.l = *from_rom2++;
            st.l <<= 8;
            if (wk->rl_flag) {
                wk->xyz[0].cal += st.l;
            } else {
                wk->xyz[0].cal -= st.l;
            }
            st.l = *from_rom2;
            st.l <<= 8;
            wk->xyz[1].cal += st.l;
        }
        if (wk->cg_status & 0x80) {
            wk->pat_status = wk->cg_status & 0x7F;
        }
    case 4:
        wk->cg_meoshi = wk->cg_hit_ix & 0x1FFF;
        st.w.h = wk->cg_att_ix;
        st.w.l = wk->cg_hit_ix;
        wk->cg_att_ix >>= 6;
        st.l *= 8;
        wk->cg_hit_ix = st.w.h & 0x1FF;
        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }
        if (wk->cg_effect) {
            effinitjptbl[wk->cg_effect](wk, wk->cg_eftype);
        }
    }
    wk->cg_jphos = jphos_table[wk->cg_olc_ix & 0xF];
    wk->cg_olc_ix >>= 4;
    wk->cg_flip = wk->cg_se & 3;
    wk->cg_prio = (wk->cg_se & 0xF) >> 2;
    wk->cg_se >>= 4;
    if (wk->cg_se & 0x800) {
        wk->cg_se = (*(u16**)(wk->se_random_table + (wk->cg_se & 0x7FF)))[random_16_com()];
    }
    if (wk->cg_se) {
        sound_effect_request[wk->cg_se](wk, check_xcopy_filter_se_req(wk));
    }
    if (wk->work_id == 1) {
        if (wk->cg_rival == 0) {
            wk->curr_rca = 0;
        } else {
            wk->curr_rca = wk->rival_catch_tbl + (wk->cg_rival - 24 + ((PLW*)wk)->tsukami_num);
        }
    }
    wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
    set_jugde_area(wk);
    if (wk->cg_type != 0xFF) {
        if (wk->cg_type & 0x80) {
            wk->cg_wca_ix = wk->cg_type & 0x7F;
            wk->cg_type = 0;
        }
    }
}



u32 check_xcopy_filter_se_req(WORK* wk) {
    s32 voif;
    if ((voif = wk->cg_se) < 0x160) {
        return voif;
    }
    if (wk->work_id != 1) {
        if (((WORK_Other*)wk)->master_work_id != 1) {
            return voif;
        }
        if ((u16)((WORK_Other*)wk)->master_id > 1) {
            return voif;
        }
        if (plw[((WORK_Other*)wk)->master_id].metamorphose == 0) {
            return voif;
        }
        return xcopy_se_tbl[wk->cg_se - 0x160];
    }
    if (((PLW*)wk)->metamorphose == 0) {
        return voif;
    }
    return xcopy_se_tbl[wk->cg_se - 0x160];
}



void check_cgd_patdat2(WORK* wk) {
    ST st;
    switch (wk->cgd_type) {
    case 6:
        if (wk->cg_status & 0x80) {
            wk->pat_status = wk->cg_status & 0x7F;
        }
    case 4:
        wk->cg_meoshi = wk->cg_hit_ix & 0x1FFF;
        st.w.h = wk->cg_att_ix;
        st.w.l = wk->cg_hit_ix;
        wk->cg_att_ix >>= 6;
        st.l *= 8;
        wk->cg_hit_ix = st.w.h & 0x1FF;
        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }
    }
    wk->cg_jphos = jphos_table[wk->cg_olc_ix & 0xF];
    wk->cg_olc_ix >>= 4;
    wk->cg_flip = wk->cg_se & 3;
    wk->cg_prio = (wk->cg_se & 0xF) >> 2;
    wk->cg_se >>= 4;
    if (wk->cg_se & 0x800) {
        wk->cg_se = (*(u16**)(wk->se_random_table + (wk->cg_se & 0x7FF)))[random_16_com()];
    }
    if (wk->work_id == 1) {
        if (wk->cg_rival == 0) {
            wk->curr_rca = 0;
        } else {
            wk->curr_rca = wk->rival_catch_tbl + (wk->cg_rival - 24 + ((PLW*)wk)->tsukami_num);
        }
    }
    wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
    set_jugde_area(wk);
    if (wk->cg_type != 0xFF) {
        if (wk->cg_type & 0x80) {
            wk->cg_wca_ix = wk->cg_type & 0x7F;
            wk->cg_type = 0;
        }
    }
}



void set_new_attnum(WORK* wk) {
    s16 aag_sw;
    u32 dspadrs;
    extern u16 att_req;
    wk->renew_attack = wk->cg_att_ix;
    if ((att_req = (++att_req & 0x7FFF)) == 0) {
        att_req++;
    }
    aag_sw = 0;
    if (wk->cg_att_ix < 0) {
        wk->cg_att_ix = -wk->cg_att_ix;
        wk->attack_num = att_req;
        wk->att_hit_ok = 1;
        aag_sw = 1;
        wk->meoshi_hit_flag = 0;
        if (wk->work_id == 1) {
            ((PLW*)wk)->caution_flag = 1;
            ((PLW*)wk)->total_att_hit_ok += 1;
        }
        grade_add_att_renew((WORK_Other*)wk);
    }
    wk->att = *(wk->att_ix_table + wk->cg_att_ix);
    dspadrs = (u32)(wk->att_ix_table + wk->cg_att_ix);
    wk->zu_flag = wk->att.level & 0x80;
    wk->jump_att_flag = wk->att.level & 0x40;
    wk->at_attribute = (wk->att.level >> 4) & 3;
    wk->no_death_attack = wk->att.level & 8;
    wk->att.level &= 7;
    wk->kezuri_pow = kezuri_pow_table[(wk->att.guard >> 6) & 3];
    wk->att.guard &= 0x3F;
    wk->att_zuru = (wk->att.dir >> 4) & 7;
    wk->att.dir &= 0xF;
    wk->add_arts_point = wk->att.piyo >> 4;
    wk->att.piyo &= 0xF;
    wk->vs_id = wk->att.ng_type >> 4;
    wk->att.ng_type &= 0xF;
    wk->dir_atthit = cal_attdir(wk);
    if (aag_sw) {
        add_sp_arts_gauge_init((PLW*)wk);
    }
}


/* provisional name */
void kezuri_pow_init(WORK* wk) {
    if (wk->kezuri_pow == 0) {
        wk->kezuri_pow = kezuri_pow_table[3];
    }
}



void set_jugde_area(WORK* wk) {
    wk->h_bod = wk->body_adrs + wk->cg_ja.boix;
    wk->h_cat = wk->catch_adrs + wk->cg_ja.caix;
    wk->h_cau = wk->caught_adrs + wk->cg_ja.cuix;
    wk->h_att = wk->attack_adrs + wk->cg_ja.atix;
    wk->h_hos = wk->hosei_adrs + wk->cg_ja.hoix;
    wk->h_han = wk->hand_adrs + (wk->cg_ja.bhix + wk->cg_ja.haix);
}

/* provisional name */
void set_char_olc_data(WORK* wk) {
    wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
}



void get_char_data_zanzou(WORK* wk) {
    if (wk->cg_att_ix) {
        set_new_attnum(wk);
    }
    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
    set_jugde_area(wk);
}
