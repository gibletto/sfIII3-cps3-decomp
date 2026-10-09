/*
 * CHARMOVE.C  cg script interpreter (character animation and action scripts)
 *
 * char_move advances a work's cg (character animation) script one frame: it counts down the current
 * line, loads the next cg data line with check_cgd_patdat (pattern, step move, attack number,
 * effects, sound, judgement areas) and runs any script commands. The comm_* routines are the script
 * commands: jumps and calls (comm_jsr/comm_ret and the comm_rja/comm_uja return-jump slots), loops,
 * position and speed setting, arithmetic and compares on the cmwk work registers, lever and button
 * tests, hit, super art, facing and screen-side jumps, sound, shadow and display flags.
 * set_char_move_init2 and the char_move_cm* helpers start a script at an index or a saved address;
 * decord_if_jump and get_comm_if_* decode conditional jumps. Every player, effect and stage object
 * animates through this module.
 * set_char_move_init points a work at script `index` of character table `koc`, clears the cg
 * counters, copies the two header words of the script, resets the script work registers and
 * move-origin record, sets the attack kind for attacking works, and for players clears the
 * per-move flags (counting repeated moves for the grade). It then runs the first frame with
 * char_move. This is the standard way every object starts a new animation.
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
#include "CHARMOVE.h"
#include "fighter.h"


void set_char_move_init(wk, koc, index)
WORK* wk;
s16 koc;
s16 index;
{
    u32* dst;
    u32* src;
    s16 i;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = (u32*)wk->char_table[koc][index];
    dst = (u32*)&wk->cg_ctr;
    for (i = 0; i < 6; i++) {
        *dst++ = 0;
    }
    src = wk->set_char_ad;
    dst = (u32*)&wk->cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    wk->cg_ix = -wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->cmoa.koc = wk->now_koc;
    wk->cmoa.ix = wk->char_index;
    wk->cmoa.pat = 1;
    wk->cmwk[8] = 0;
    wk->cmwk[15] = 0;
    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }
    if (wk->work_id == 1) {
        ((PLW*)wk)->tc_1st_flag = 0;
        if (wk->now_koc == 4 || wk->now_koc == 5) {
            grade_add_onaji_waza(wk->id);
        }
        ((PLW*)wk)->ja_nmj_rno = 0;
    }
    wk->K5_init_flag = 1;
    char_move(wk);
}

void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf) {
    u32* dst;
    u32* src;
    s16 i;
    u8 pst;
    u8 kow;
    pst = wk->pat_status;
    kow = wk->kind_of_waza;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = (u32*)wk->char_table[koc][index];
    dst = (u32*)&wk->cg_ctr;
    for (i = 0; i < 6; i++) {
        *dst++ = 0;
    }
    src = wk->set_char_ad;
    dst = (u32*)&wk->cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    wk->cg_ix = (ip - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }
    if (scf) {
        wk->pat_status = pst;
        wk->kind_of_waza = kow;
    }
    if (wk->work_id & 0xF) {
        wk->at_koa = acatkoa_table[wk->kind_of_waza];
    }
    wk->K5_init_flag = 1;
    char_move(wk);
}



void exset_char_move_init(WORK* wk, s16 koc, s16 index) {
    u32* dst;
    u32* src;
    s16 i;
    u8 now_ctr;
    wk->now_koc = koc;
    wk->char_index = index;
    wk->set_char_ad = (u32*)wk->char_table[koc][index];
    now_ctr = wk->cg_ctr;
    dst = (u32*)&wk->cg_ctr;
    src = wk->set_char_ad + wk->cg_ix;
    for (i = 0; i < wk->cgd_type; i++) {
        *dst++ = *src++;
    }
    wk->cg_ctr = now_ctr;
    wk->cmoa.koc = wk->now_koc;
    wk->cmoa.ix = wk->char_index;
    wk->cmoa.pat = 1;
    wk->K5_init_flag = 1;
    check_cgd_patdat2(wk);
}



void char_move_z(WORK* wk) {
    if (test_flag) {
        wk->cg_next_ix = 0;
    }
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}


/* provisional name */
void char_move_reset_ctr(WORK* wk) {
    wk->cg_next_ix = 0;
    wk->cg_ctr = 1;
}



void char_move_wca(WORK* wk) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (wk->cg_wca_ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}



void char_move_wca_init(WORK* wk) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (wk->cg_wca_ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
}



s32 comm_wca(WORK* wk, CHAR_CMD* _p1) {
    char_move_wca_init(wk);
    return 1;
}



void char_move_index(WORK* wk, s16 ix) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
    char_move(wk);
}


/* provisional name */
void char_move_index_set(WORK* wk, s16 ix) {
    wk->cg_next_ix = 0;
    wk->cg_ix = (ix - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->K5_init_flag = 1;
}


/* provisional name */
void set_cmja_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmja.koc = koc;
    wk->cmja.ix = ix;
    wk->cmja.pat = pat;
}



void char_move_cmja(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmja.koc, wk->cmja.ix, wk->cmja.pat, 0);
}


/* provisional name */
void set_cmj2_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj2.koc = koc;
    wk->cmj2.ix = ix;
    wk->cmj2.pat = pat;
}



/* provisional name */
void char_move_cmj2(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj2.koc, wk->cmj2.ix, wk->cmj2.pat, 0);
}


/* provisional name */
void set_cmj3_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj3.koc = koc;
    wk->cmj3.ix = ix;
    wk->cmj3.pat = pat;
}



/* provisional name */
void char_move_cmj3(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj3.koc, wk->cmj3.ix, wk->cmj3.pat, 0);
}


/* provisional name */
void set_cmj4_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj4.koc = koc;
    wk->cmj4.ix = ix;
    wk->cmj4.pat = pat;
}



void char_move_cmj4(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj4.koc, wk->cmj4.ix, wk->cmj4.pat, 0);
}


/* provisional name */
void set_cmj5_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj5.koc = koc;
    wk->cmj5.ix = ix;
    wk->cmj5.pat = pat;
}



/* provisional name */
void char_move_cmj5(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj5.koc, wk->cmj5.ix, wk->cmj5.pat, 0);
}


/* provisional name */
void set_cmj6_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj6.koc = koc;
    wk->cmj6.ix = ix;
    wk->cmj6.pat = pat;
}



/* provisional name */
void char_move_cmj6(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj6.koc, wk->cmj6.ix, wk->cmj6.pat, 0);
}


/* provisional name */
void set_cmj7_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmj7.koc = koc;
    wk->cmj7.ix = ix;
    wk->cmj7.pat = pat;
}



/* provisional name */
void char_move_cmj7(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj7.koc, wk->cmj7.ix, wk->cmj7.pat, 0);
}



/* provisional name */
s32 char_move_cmoa(WORK* wk, CHAR_CMD* _p1) {
    set_char_move_init2(wk, wk->cmoa.koc, wk->cmoa.ix, wk->cmoa.pat, 0);
}


/* provisional name */
void set_cmms_data(WORK* wk, s16 koc, s16 ix, s16 pat) {
    wk->cmms.koc = koc;
    wk->cmms.ix = ix;
    wk->cmms.pat = pat;
}



void char_move_cmms(WORK* wk) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmms.koc, wk->cmms.ix, wk->cmms.pat, 0);
}


void char_move_cmms2(WORK* wk) {
    u32* to_ram;
    u32* dst;
    u32* src;
    s16 i;
    s16 now_cgd;
    setup_comm_back(wk);
    now_cgd = wk->cgd_type;
    wk->now_koc = wk->cmms.koc;
    wk->char_index = wk->cmms.ix;
    wk->set_char_ad = (u32*)wk->char_table[wk->now_koc][wk->char_index];
    src = wk->set_char_ad;
    dst = (u32*)&wk->cg_ctr;
    *--dst = *--src;
    *--dst = *--src;
    if (now_cgd > wk->cgd_type) {
        to_ram = (u32*)&wk->cg_wca_ix;
        for (i = 0; i < now_cgd - wk->cgd_type; i++) {
            *--to_ram = 0;
        }
    }
    wk->cg_ix = (wk->cmms.pat - 1) * wk->cgd_type - wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
}



s32 char_move_cmms3(PLW* wk) {
    CHAR_CMD* cpc;
    u32* to_ram;
    u32* src;
    s16 i;
    s16 now_cgd;
    wk->meoshi_jump_flag = 1;
    setup_comm_retmj(&wk->wu);
    setup_comm_back(&wk->wu);
    now_cgd = wk->wu.cgd_type;
    wk->wu.now_koc = wk->wu.cmms.koc;
    wk->wu.char_index = wk->wu.cmms.ix;
    wk->wu.set_char_ad = (u32*)wk->wu.char_table[wk->wu.now_koc][wk->wu.char_index];
    to_ram = (u32*)&wk->wu.cg_ctr;
    src = wk->wu.set_char_ad;
    *--to_ram = *--src;
    *--to_ram = *--src;
    wk->wu.cg_ix = wk->wu.cmms.pat * wk->wu.cgd_type - wk->wu.cgd_type;
loop:
    cpc = (CHAR_CMD*)&wk->wu.set_char_ad[wk->wu.cg_ix];
    if (cpc->code < 0x100) {
        if (comm_jmp_tbl[cpc->code](wk, cpc) != 0) {
            wk->wu.cg_ix += wk->wu.cgd_type;
            goto loop;
        }
        if (wk->meoshi_jump_flag == 0) {
            return 0;
        }
    }
    if (now_cgd > wk->wu.cgd_type) {
        to_ram = (u32*)&wk->wu.cg_wca_ix;
        for (i = 0; i < now_cgd - wk->wu.cgd_type; i++) {
            *--to_ram = 0;
        }
    }
    wk->wu.cg_ix -= wk->wu.cgd_type;
    wk->wu.cg_ctr = 1;
    wk->wu.cg_next_ix = 0;
    wk->wu.old_cgnum = 0;
    wk->wu.cg_wca_ix = 0;
    wk->meoshi_jump_flag = 0;
    return 1;
}


/* provisional name */
void set_cmhs_data(PLW* wk, s16 koc, s16 ix, s16 pat) {
    wk->wu.cmhs.koc = koc;
    wk->wu.cmhs.ix = ix;
    wk->wu.cmhs.pat = pat;
    wk->hsjp_ok = 0;
}



void char_move_cmhs(PLW* wk) {
    if (wk->hsjp_ok != 0) {
        setup_comm_back(&wk->wu);
        wk->hsjp_ok = 0;
        set_char_move_init2(&wk->wu, wk->wu.cmhs.koc, wk->wu.cmhs.ix, wk->wu.cmhs.pat, 0);
    }
}



void char_move_next(WORK* wk);

void char_move(WORK* wk) {
    wk->K5_exec_ok = 1;
    if (--wk->cg_ctr != 0) {
        return;
    }
    char_move_next(wk);
}

void char_move_next(WORK* wk) {
    CHAR_CMD* cpc;
    if (wk->cg_next_ix) {
        wk->cg_ix = (wk->cg_next_ix - 1) * wk->cgd_type;
    } else {
        wk->cg_ix += wk->cgd_type;
    }
next:
    cpc = (CHAR_CMD*)(wk->set_char_ad + wk->cg_ix);
    if (cpc->code >= 0x100) {
        check_cgd_patdat(wk);
        return;
    } else if (comm_jmp_tbl[cpc->code]((PLW*)wk, cpc) == 0) {
        return;
    }
    wk->cg_ix += wk->cgd_type;
    goto next;
}

u32 comm_dummy(void)
{
    return 1;
}



s32 comm_roa(WORK* wk, CHAR_CMD* _p1) {
    if (wk->cmoa.pat == 0) {
        wk->cmoa.koc = wk->now_koc;
        wk->cmoa.ix = wk->char_index;
        wk->cmoa.pat = 1;
    }
    set_char_move_init2(wk, wk->cmoa.koc, wk->cmoa.ix, wk->cmoa.pat, 0);
    return 0;
}

u32 comm_end(WORK* wk, CHAR_CMD* ctc)
{

    wk->cg_ix = (ctc->pat - 2) * wk->cgd_type;
    return 1;
}

u32 comm_jmp(WORK* wk, CHAR_CMD* ctc)
{

    setup_comm_back(wk);
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 0);
    return 0;
}



s32 comm_jpss(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 1);
    return 0;
}



s32 comm_jsr(WORK* wk, CHAR_CMD* ctc) {
    wk->cmsw.koc = wk->now_koc;
    wk->cmsw.ix = wk->char_index;
    wk->cmsw.pat = (wk->cg_ix / wk->cgd_type) + 2;
    set_char_move_init2(wk, ctc->koc, ctc->ix, ctc->pat, 0);
    return 0;
}



s32 comm_ret(WORK* wk, CHAR_CMD* _p1) {
    set_char_move_init2(wk, wk->cmsw.koc, wk->cmsw.ix, wk->cmsw.pat, 0);
    return 0;
}



s32 comm_sps(WORK* wk, CHAR_CMD* ctc) {
    wk->pat_status = ctc->pat;
    return 1;
}



s32 comm_setr(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[ctc->koc] = ctc->ix;
    return 1;
}



s32 comm_addr(WORK* wk, CHAR_CMD* ctc) {
    wk->routine_no[ctc->koc] += ctc->ix;
    return 1;
}



s32 comm_if_l(WORK* wk, CHAR_CMD* ctc) {
    u16 lvdat;
    u16 my_lvdat;
    s16 ix;
    if (ctc->koc & 0x4000) {
        my_lvdat = wk->cmwk[ctc->koc & 0xF];
    } else {
        my_lvdat = ctc->koc;
    }
    lvdat = get_comm_if_lever(wk);
    if (!(my_lvdat & 0x7FFF)) {
        if (lvdat == 0) {
            ix = ctc->ix;
        } else {
            ix = ctc->pat;
        }
    } else if (my_lvdat & 0x8000) {
        if (lvdat == (my_lvdat & 0xF)) {
            return decord_if_jump(wk, ctc, ctc->ix);
        } else {
            ix = ctc->pat;
        }
    } else if (lvdat & my_lvdat) {
        ix = ctc->ix;
    } else {
        ix = ctc->pat;
    }
    return decord_if_jump(wk, ctc, ix);
}

s32 comm_djmp(WORK* wk, CHAR_CMD* ctc) {
    u8 ldir;
    if ((ldir = get_comm_djmp_lever_dir((PLW*)wk))) {
        if (ldir == 1) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->koc);
}



s32 comm_for(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->pat & 0x4000) {
        wk->cmlp.code = wk->cmwk[ctc->pat & 0xF];
    } else {
        wk->cmlp.code = ctc->pat;
    }
    wk->cmlp.koc = wk->now_koc;
    wk->cmlp.ix = wk->char_index;
    wk->cmlp.pat = wk->cg_ix / wk->cgd_type + 2;
    return 1;
}



s32 comm_nex(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cmlp.code) {
        if (--wk->cmlp.code > 0) {
            set_char_move_init2(wk, wk->cmlp.koc, wk->cmlp.ix, wk->cmlp.pat, 1);
            return 0;
        }
    }
    return 1;
}



s32 comm_for2(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->pat & 0x4000) {
        wk->cml2.code = wk->cmwk[ctc->pat & 0xF];
    } else {
        wk->cml2.code = ctc->pat;
    }
    wk->cml2.koc = wk->now_koc;
    wk->cml2.ix = wk->char_index;
    wk->cml2.pat = (wk->cg_ix / wk->cgd_type) + 2;
    return 1;
}



s32 comm_nex2(WORK* wk, CHAR_CMD* ctc) {
    if (wk->cml2.code && --wk->cml2.code > 0) {
        set_char_move_init2(wk, wk->cml2.koc, wk->cml2.ix, wk->cml2.pat, 1);
        return 0;
    }
    return 1;
}



s32 comm_rja(WORK* wk, CHAR_CMD* ctc) {
    wk->cmja.koc = ctc->koc;
    wk->cmja.ix = ctc->ix;
    wk->cmja.pat = ctc->pat;
    return 1;
}



s32 comm_uja(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmja.koc, wk->cmja.ix, wk->cmja.pat, 0);
    return 0;
}



s32 comm_rja2(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj2.koc = ctc->koc;
    wk->cmj2.ix = ctc->ix;
    wk->cmj2.pat = ctc->pat;
    return 1;
}



s32 comm_uja2(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj2.koc, wk->cmj2.ix, wk->cmj2.pat, 0);
    return 0;
}



s32 comm_rja3(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj3.koc = ctc->koc;
    wk->cmj3.ix = ctc->ix;
    wk->cmj3.pat = ctc->pat;
    return 1;
}



s32 comm_uja3(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj3.koc, wk->cmj3.ix, wk->cmj3.pat, 0);
    return 0;
}



s32 comm_rja4(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj4.koc = ctc->koc;
    wk->cmj4.ix = ctc->ix;
    wk->cmj4.pat = ctc->pat;
    return 1;
}



s32 comm_uja4(WORK* wk, CHAR_CMD* _p1) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj4.koc, wk->cmj4.ix, wk->cmj4.pat, 0);
    return 0;
}



s32 comm_rja5(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj5.koc = ctc->koc;
    wk->cmj5.ix = ctc->ix;
    wk->cmj5.pat = ctc->pat;
    return 1;
}



s32 comm_uja5(WORK* wk, CHAR_CMD* _p1) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj5.koc, wk->cmj5.ix, wk->cmj5.pat, 0);
    return 0;
}



s32 comm_rja6(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj6.koc = ctc->koc;
    wk->cmj6.ix = ctc->ix;
    wk->cmj6.pat = ctc->pat;
    return 1;
}



s32 comm_uja6(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj6.koc, wk->cmj6.ix, wk->cmj6.pat, 0);
    return 0;
}



s32 comm_rja7(WORK* wk, CHAR_CMD* ctc) {
    wk->cmj7.koc = ctc->koc;
    wk->cmj7.ix = ctc->ix;
    wk->cmj7.pat = ctc->pat;
    return 1;
}



s32 comm_uja7(WORK* wk, CHAR_CMD* ctc) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmj7.koc, wk->cmj7.ix, wk->cmj7.pat, 0);
    return 0;
}



s32 comm_rmja(WORK* wk, CHAR_CMD* ctc) {
    wk->cmms.koc = ctc->koc;
    wk->cmms.ix = ctc->ix;
    wk->cmms.pat = ctc->pat;
    return 1;
}



s32 comm_umja(WORK* wk, CHAR_CMD* _p1) {
    setup_comm_back(wk);
    set_char_move_init2(wk, wk->cmms.koc, wk->cmms.ix, wk->cmms.pat, 0);
    return 0;
}



s32 comm_mdat(WORK* wk, CHAR_CMD* ctc) {
    wk->cmmd.koc = ctc->koc;
    wk->cmmd.ix = ctc->ix;
    wk->cmmd.pat = ctc->pat;
    return 1;
}



s32 comm_ydat(WORK* wk, CHAR_CMD* ctc) {
    wk->cmyd.koc = ctc->koc;
    wk->cmyd.ix = ctc->ix;
    wk->cmyd.pat = ctc->pat;
    return 1;
}



s32 comm_mpos(WORK* wk, CHAR_CMD* ctc) {
    wk->att.hit_mark = ctc->koc;
    wk->hit_mark_x = ctc->ix;
    wk->hit_mark_y = ctc->pat;
    return 1;
}



s32 comm_cafr(WORK* wk, CHAR_CMD* ctc) {
    wk->cmcf.koc = ctc->koc;
    wk->cmcf.ix = ctc->ix;
    wk->cmcf.pat = ctc->pat;
    return 1;
}



s32 comm_care(WORK* wk, CHAR_CMD* ctc) {
    wk->cmcr.koc = ctc->koc;
    wk->cmcr.ix = ctc->ix;
    wk->cmcr.pat = ctc->pat;
    return 1;
}



s32 comm_psxy(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    switch (ctc->koc) {
    case 0:
        wk->xyz[0].disp.pos = ctc->ix;
        wk->xyz[1].disp.pos = ctc->pat;
        break;
    case 2:
        wk->xyz[0].disp.pos = ctc->ix;
        wk->xyz[1].disp.pos = ctc->pat;
    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[0].disp.pos = ctc->ix;
        emwk->xyz[1].disp.pos = ctc->pat;
        break;
    }
    return 1;
}



s32 comm_ps_x(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    switch (ctc->koc) {
    case 0:
        wk->xyz[0].disp.pos = ctc->ix;
        break;
    case 2:
        wk->xyz[0].disp.pos = ctc->ix;
    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[0].disp.pos = ctc->ix;
        break;
    }
    return 1;
}



s32 comm_ps_y(WORK* wk, CHAR_CMD* ctc) {
    if (wk->work_id == 1) {
        switch (ctc->koc) {
        case 0:
            if (bg_w.stage == 21) {
                if (((PLW*)wk)->bs2_on_car) {
                    s16* fc = &bs2_floor[2];
                    if (ctc->pat < *fc) {
                        wk->xyz[1].disp.pos = *fc;
                        break;
                    }
                }
            }
            wk->xyz[1].disp.pos = ctc->pat;
            break;
        case 2:
            wk->xyz[1].disp.pos = ctc->pat;
        default:
            wk = (WORK*)wk->target_adrs;
            wk->xyz[1].disp.pos = ctc->pat;
            break;
        }
        return 1;
    }
    switch (ctc->koc) {
    case 0:
        wk->xyz[1].disp.pos = ctc->pat;
        break;
    case 2:
        wk->xyz[1].disp.pos = ctc->pat;
    default:
        wk = (WORK*)wk->target_adrs;
        wk->xyz[1].disp.pos = ctc->pat;
        break;
    }
    return 1;
}



s32 comm_paxy(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }
        wk->xyz[1].cal += ctc->pat << 8;
        break;
    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }
        wk->xyz[1].cal += ctc->pat << 8;
    default:
        emwk = (WORK*)wk->target_adrs;
        if (emwk->rl_flag) {
            emwk->xyz[0].cal += ctc->ix << 8;
        } else {
            emwk->xyz[0].cal -= ctc->ix << 8;
        }
        emwk->xyz[1].cal += ctc->pat << 8;
        break;
    }
    return 1;
}



s32 comm_pa_x(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    switch (ctc->koc) {
    case 0:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }
        break;
    case 2:
        if (wk->rl_flag) {
            wk->xyz[0].cal += ctc->ix << 8;
        } else {
            wk->xyz[0].cal -= ctc->ix << 8;
        }
    default:
        emwk = (WORK*)wk->target_adrs;
        if (emwk->rl_flag) {
            emwk->xyz[0].cal += ctc->ix << 8;
        } else {
            emwk->xyz[0].cal -= ctc->ix << 8;
        }
        break;
    }
    return 1;
}



s32 comm_pa_y(WORK* wk, CHAR_CMD* ctc) {
    WORK* emwk;
    switch (ctc->koc) {
    case 0:
        wk->xyz[1].cal += ctc->pat << 8;
        break;
    case 2:
        wk->xyz[1].cal += ctc->pat << 8;
    default:
        emwk = (WORK*)wk->target_adrs;
        emwk->xyz[1].cal += ctc->pat << 8;
        break;
    }
    return 1;
}



s32 comm_exec(WORK* wk, CHAR_CMD* ctc) {
    effinitjptbl[ctc->koc](wk, (u8)ctc->ix);
    return 1;
}



s32 comm_rngc(WORK* wk, CHAR_CMD* ctc) {
    s16 rngdat;
    if (wk->work_id == 1) {
        rngdat = get_em_body_range(wk);
    } else {
        rngdat = get_em_body_range((WORK*)((WORK_Other*)wk)->my_master);
    }
    if (rngdat > ctc->koc) {
        return decord_if_jump(wk, ctc, ctc->pat);
    }
    return decord_if_jump(wk, ctc, ctc->ix);
}



s32 comm_mxyt(WORK* wk, CHAR_CMD* ctc) {
    if (ctc->koc) {
        setup_mvxy_data(wk, ctc->koc);
    } else {
        reset_mvxy_data(wk);
    }
    return 1;
}



s32 comm_pjmp(WORK* wk, CHAR_CMD* ctc) {
    if (random_32_com() < ctc->koc) {
        return decord_if_jump(wk, ctc, ctc->ix);
    }
    return decord_if_jump(wk, ctc, ctc->pat);
}



s32 comm_hjmp(WORK* wk, CHAR_CMD* ctc) {
    if (wk->meoshi_hit_flag != 0 && wk->hf.hit_flag != 0) {
        if (wk->hf.hit_flag & 0x303) {
            return decord_if_jump(wk, ctc, ctc->koc);
        }
        if (wk->hf.hit_flag & 0x3030) {
            return decord_if_jump(wk, ctc, ctc->ix);
        }
        if (wk->hf.hit_flag & 0xC0C0) {
            return decord_if_jump(wk, ctc, ctc->pat);
        }
    }
    return 1;
}



s32 comm_hclr(WORK* wk, CHAR_CMD* _p1) {
    wk->hf.hit_flag = 0;
    return 1;
}



