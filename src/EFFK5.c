/*
 * EFFK5.C  Effect K5: interpolated body and hand damage boxes for a player
 *
 * Effect K5 (id 205) is an invisible helper created for each player by effect_K5_init (from
 * PLCNTDAT and CMD_MAIN; never in bonus game 21). It moves the player's damage (hurt) boxes
 * smoothly between animation frames instead of letting them jump.
 * Each time the player's hit index changes, K5_init_data loads eight joints (four body
 * boxes, four hand boxes) from the master's tables; get_okuri_time scans ahead in the animation
 * script to find how many frames remain until the next hit index, and K5_decode_new_hit_index
 * sets up per-joint speeds (switch fields from decode_mvsw).
 * K5_main_process advances the joints each frame and K5_init_data_copy2 writes them into the
 * rambod / ramhan RAM boxes, which the player's h_bod / h_han pointers then use for hit checks.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"
#include "EFFECT.h"
#include "EFFK5.h"

static void get_okuri_time(WORK* ewk, WORK* mwk, MVJ* mvj);


void effect_K5_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    MVJ* mvj;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        if (get_cal_work(&ewk->wu) == -1) {
            ewk->wu.routine_no[0] = 3;
            return;
        }
        mvj = (MVJ*)(((WORK*)ewk->wu.target_adrs)->routine_no);
        init_K5_work(&ewk->wu, mwk, mvj);
        ewk->wu.old_rno[1] = mwk->cg_hit_ix;
        get_table_adrs_K5(mwk);
        K5_init_data(mwk, mvj, (u16*)(&mwk->cg_ja));
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            return;
        }
        if (((PLW*)mwk)->waku_ram_index != ewk->wu.myself) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            return;
        }
        get_master_table_address(&ewk->wu, mwk);
        mvj = (MVJ*)(((WORK*)ewk->wu.target_adrs)->routine_no);
        if (mwk->K5_exec_ok) {
            mwk->K5_exec_ok = 0;
            if (mwk->K5_init_flag || (ewk->wu.old_rno[1] != mwk->cg_hit_ix)) {
                mwk->K5_init_flag = 0;
                ewk->wu.old_rno[1] = mwk->cg_hit_ix;
                ewk->wu.routine_no[1] = 0;
                K5_init_data(mwk, mvj, (u16*)(&mwk->cg_ja));
            }
            K5_main_process(&ewk->wu, mwk, mvj);
        }
        K5_init_data_copy2((K5Data*)&rambod[mwk->id], mvj, 4);
        K5_init_data_copy2((K5Data*)&ramhan[mwk->id], mvj + 4, 4);
        mwk->h_bod = (BODY_BOX*)&rambod[mwk->id];
        mwk->h_han = (HAND_BOX*)&ramhan[mwk->id];
        break;
    case 2:
        push_effect_work((WORK*)ewk->wu.target_adrs);
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void K5_main_process(WORK* ewk, WORK* mwk, MVJ* mvj) {
    s32 i;
    switch (ewk->routine_no[1]) {
    case 0:
        get_okuri_time(ewk, mwk, mvj);
        break;
    case 1:
        for (i = 0; i < 8; i++) {
            if (mvj[i].rno) {
                k5_add_sub(&mvj[i]);
            }
        }
        break;
    }
}



static void get_okuri_time(WORK* ewk, WORK* mwk, MVJ* mvj) {
    GOTCP gotcp;
    ST st;
    s16 exc;
    u16 now_mf;
    if ((mwk->cgd_type != 2) && (mwk->cg_ja.mf.full & 0x1010)) {
        now_mf = mwk->cg_ja.mf.full;
        exc = 0;
        ewk->old_rno[0] = mwk->cg_ctr;
        ewk->cg_ix = mwk->cg_ix;
    loop:
        {
            ewk->cg_ix += mwk->cgd_type;
            gotcp.cpl = &mwk->set_char_ad[ewk->cg_ix];
            if (gotcp.cps[0] >= 0x100) {
                st.l = gotcp.cpl[2];
                st.l *= 8;
                ewk->cg_hit_ix = st.w.h & 0x1FF;
                if (ewk->old_rno[1] == ewk->cg_hit_ix) {
                    if ((gotcp.cpc[1] != 0xFF) || (gotcp.cpc[0] < 0xC8)) {
                        ewk->old_rno[0] += gotcp.cpc[0];
                    }
                    goto loop;
                }
                if (ewk->old_rno[0] >= 2) {
                    K5_decode_new_hit_index(ewk, mvj, now_mf);
                    ewk->routine_no[1] = 1;
                    return;
                }
                goto end;
            }
            if (k5_exc_check[gotcp.cps[0]] == 2) {
                goto end;
            }
            if (k5_exc_check[gotcp.cps[0]]) {
                goto loop;
            }
            if (exc++ >= 4) {
                goto end;
            }
            switch (gotcp.cps[0]) {
            case 2:
                ewk->cg_ix = (gotcp.cps[3] - 2) * mwk->cgd_type;
                break;
            case 49:
                if ((test_flag == 0) || (ixbfw_cut == 0)) {
                    ewk->cg_ix += (gotcp.cps[3] - 1) * mwk->cgd_type;
                }
                break;
            case 50:
                if ((test_flag == 0) || (ixbfw_cut == 0)) {
                    ewk->cg_ix -= (gotcp.cps[3] + 1) * mwk->cgd_type;
                }
                break;
            }
            goto loop;
        }
    }
end:
    ewk->old_rno[0] = 1;
    ewk->routine_no[1] = 2;
}



void K5_decode_new_hit_index(WORK* wk, MVJ* mvj, u16 mf) {
    s16 i;
    s16 t0;
    s16 t1;
    MVSW mvsw;
    MVJ* m;
    get_table_adrs_K5(wk);
    mvsw.swi = decode_mvsw(mf);
    if (wk->cg_ja.boix != mvj[0].index) {
        for (i = 0, m = mvj; i < 4; i++, m++) {
            if (m->r[1].pos.h != 0) {
                wk->xyz[0].disp.pos = m->r[0].pos.h;
                wk->xyz[1].disp.pos = m->r[1].pos.h;
                if ((t1 = wk->h_bod->body_dm[i][1])) {
                    t0 = wk->h_bod->body_dm[i][0];
                } else {
                    t0 = wk->xyz[0].disp.pos + wk->xyz[1].disp.pos / 2;
                }
                cal_all_speed_data(wk, wk->old_rno[0], t0, t1, mvsw.swc.hh, mvsw.swc.l);
                m->r[0].cal = wk->xyz[0].cal;
                m->r[1].cal = wk->xyz[1].cal;
                m->a[0].sp = wk->mvxy.a[0].sp;
                m->d[0].sp = wk->mvxy.d[0].sp;
                m->a[1].sp = wk->mvxy.a[1].sp;
                m->d[1].sp = wk->mvxy.d[1].sp;
                wk->xyz[0].disp.pos = m->r[2].pos.h;
                wk->xyz[1].disp.pos = m->r[3].pos.h;
                if ((t1 = wk->h_bod->body_dm[i][3])) {
                    t0 = wk->h_bod->body_dm[i][2];
                } else {
                    t0 = wk->xyz[0].disp.pos + wk->xyz[1].disp.pos / 2;
                }
                cal_all_speed_data(wk, wk->old_rno[0], t0, t1, mvsw.swc.h, mvsw.swc.ll);
                m->r[2].cal = wk->xyz[0].cal;
                m->r[3].cal = wk->xyz[1].cal;
                m->a[2].sp = wk->mvxy.a[0].sp;
                m->d[2].sp = wk->mvxy.d[0].sp;
                m->a[3].sp = wk->mvxy.a[1].sp;
                m->d[3].sp = wk->mvxy.d[1].sp;
                m->rno = 1;
            } else {
                m->rno = 0;
            }
            m->index = wk->cg_ja.boix;
            continue;
        }
    }
    if (mvj[4].index != (wk->cg_ja.bhix + wk->cg_ja.haix)) {
        for (i = 4, m = &mvj[4]; i < 8; i++, m++) {
            if (m->r[1].pos.h != 0) {
                wk->xyz[0].disp.pos = m->r[0].pos.h;
                wk->xyz[1].disp.pos = m->r[1].pos.h;
                if ((t1 = wk->h_han->hand_dm[i - 4][1])) {
                    t0 = wk->h_han->hand_dm[i - 4][0];
                } else {
                    t0 = wk->xyz[0].disp.pos + wk->xyz[1].disp.pos / 2;
                }
                cal_all_speed_data(wk, wk->old_rno[0], t0, t1, mvsw.swc.hh, mvsw.swc.l);
                m->r[0].cal = wk->xyz[0].cal;
                m->r[1].cal = wk->xyz[1].cal;
                m->a[0].sp = wk->mvxy.a[0].sp;
                m->d[0].sp = wk->mvxy.d[0].sp;
                m->a[1].sp = wk->mvxy.a[1].sp;
                m->d[1].sp = wk->mvxy.d[1].sp;
                wk->xyz[0].disp.pos = m->r[2].pos.h;
                wk->xyz[1].disp.pos = m->r[3].pos.h;
                if ((t1 = wk->h_han->hand_dm[i - 4][3])) {
                    t0 = wk->h_han->hand_dm[i - 4][2];
                } else {
                    t0 = wk->xyz[0].disp.pos + wk->xyz[1].disp.pos / 2;
                }
                cal_all_speed_data(wk, wk->old_rno[0], t0, t1, mvsw.swc.h, mvsw.swc.ll);
                m->r[2].cal = wk->xyz[0].cal;
                m->r[3].cal = wk->xyz[1].cal;
                m->a[2].sp = wk->mvxy.a[0].sp;
                m->d[2].sp = wk->mvxy.d[0].sp;
                m->a[3].sp = wk->mvxy.a[1].sp;
                m->d[3].sp = wk->mvxy.d[1].sp;
                m->rno = 1;
            } else {
                m->rno = 0;
            }
            m->index = wk->cg_ja.bhix + wk->cg_ja.haix;
            continue;
        }
    }
}



u32 decode_mvsw(u16 flag) {
    MVSW_BE mvsw;
    mvsw.swi = flag;
    if (flag & 0x1000) {
        mvsw.swc.hh = mvsw.swc.h = mvsw.swc.l;
        mvsw.swc.hh >>= 2;
        mvsw.swc.hh &= 3;
        mvsw.swc.h &= 3;
    } else {
        mvsw.sws.h = 0xFFFF;
    }
    if (flag & 0x10) {
        mvsw.swc.l = mvsw.swc.ll;
        mvsw.swc.l >>= 2;
        mvsw.swc.l &= 3;
        mvsw.swc.ll &= 3;
    } else {
        mvsw.sws.l = 0xFFFF;
    }
    return mvsw.swi;
}



void get_table_adrs_K5(WORK* wk) {
    wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
    wk->h_bod = &wk->body_adrs[wk->cg_ja.boix];
    wk->h_han = &wk->hand_adrs[wk->cg_ja.bhix + wk->cg_ja.haix];
}



void init_K5_work(WORK* ewk, WORK* mwk, MVJ* mvj) {
    s16 i;
    for (i = 0; i < 10; i++) {
        mvj[i].index = mvj[i].rno = 0;
    }
    ewk->cg_hit_ix = mwk->cg_hit_ix;
    ewk->hit_ix_table = mwk->hit_ix_table;
    ewk->body_adrs = mwk->body_adrs;
    ewk->hand_adrs = mwk->hand_adrs;
    mwk->K5_init_flag = 1;
}



void get_master_table_address(WORK* ewk, WORK* mwk) {
    ewk->hit_ix_table = mwk->hit_ix_table;
    ewk->body_adrs = mwk->body_adrs;
    ewk->hand_adrs = mwk->hand_adrs;
}



void K5_init_data(WORK* mwk, MVJ* mvj, u16* ixtbl) {
    s32 i;
    for (i = 0; i < 8; i++) {
        mvj[i].rno = 0;
        mvj[i].index = ixtbl[lookup_index[i]];
    }
    K5_init_data_copy(mvj, (K5Data*)mwk->body_adrs[mwk->cg_ja.boix].body_dm, 4);
    K5_init_data_copy(mvj + 4, (K5Data*)mwk->hand_adrs[mwk->cg_ja.bhix + mwk->cg_ja.haix].hand_dm, 4);
}



void K5_init_data_copy(MVJ* mvj, K5Data* dad, s16 num) {
    s32 i;
    MVJ* mv;
    K5Data* dd;
    for (i = 0; i < num; i++) {
        mvj[i].r[0].pos.h = dad[i].mvxy_lv[0];
        mv = &mvj[i];
        dd = &dad[i];
        mv->r[1].pos.h = dd->mvxy_lv[1];
        mv->r[2].pos.h = dd->mvxy_lv[2];
        mv->r[3].pos.h = dd->mvxy_lv[3];
    }
}


/* provisional name */
void K5_init_data_copy2(K5Data* dad, MVJ* mvj, s16 num) {
    s32 i;
    K5Data* d;
    MVJ* m;
    for (i = 0; i < num; i++) {
        d = &dad[i];
        m = &mvj[i];
        d->mvxy_lv[0] = m->r[0].pos.h;
        d->mvxy_lv[1] = m->r[1].pos.h;
        d->mvxy_lv[2] = m->r[2].pos.h;
        d->mvxy_lv[3] = m->r[3].pos.h;
    }
}



s32 get_cal_work(WORK* wk) {
    WORK* fwk;
    s16 ix;
    if ((ix = pull_effect_work(7)) == -1) {
        return -1;
    }
    fwk = (WORK*)frw[ix];
    wk->target_adrs = (u32*)fwk;
    fwk->be_flag = 1;
    fwk->id = 0xCD;
    return 0;
}



void k5_add_sub(MVJ* mvj) {
    s16 i;
    for (i = 0; i < 4; i++) {
        mvj->r[i].cal += mvj->a[i].sp;
    }
    for (i = 0; i < 4; i++) {
        mvj->a[i].sp += mvj->d[i].sp;
    }
}



s32 effect_K5_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (Bonus_Game_Flag == 21) {
        return -1;
    }
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xCD;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32*)wk;
    wk->waku_ram_index = ewk->wu.myself;
    return 0;
}
