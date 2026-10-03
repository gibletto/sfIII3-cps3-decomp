/*
 * PLS02.C  Movement data, body push and position correction
 *
 * Subroutines for character movement. setup_mvxy_data, add_to_mvxy_data, cal_mvxy_speed and
 * the add_mvxy_speed family load and apply the per-move x/y speed and acceleration data;
 * setup_butt_own_data sets up blow-away movement; setup_air_paring_mvxy and remake_mvxy_*
 * adjust speeds after an air parry or a push.
 * check_body_touch/check_body_touch2 and meri_case_switch keep the two players' bodies from
 * overlapping; check_work_position and set_field_hosei_flag clamp works to the screen and stage
 * limits (with a bonus-stage version). Also the CPU random helpers random_32_com/random_16_com
 * and the guard and attack direction calculations (get_guard_direction, cal_attdir).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"
#include "HITCHECK.h"
#include "PLS01.h"
#include "PLS02.h"

struct PLW_tag;

/* stored after parabora_own_table (after its remy entry) */
extern const u32 parabora_own_table_tail[];
#define parabora_ex_table ((s16 (*)[][24][4][4][6])&parabora_own_table_tail[1])



void add_to_mvxy_data(wk, ix)
    WORK *wk;
    u16 ix;
{
    s16* adrs;
    s32 sp;
    wk->mvxy.index = ix;
    adrs = &wk->move_xy_table[ix * 6];
    sp = adrs[0];
    sp *= 256;
    wk->mvxy.a[0].sp += sp;
    sp = adrs[1];
    sp *= 256;
    wk->mvxy.d[0].sp += sp;
    wk->mvxy.kop[0] = adrs[2];
    sp = adrs[3];
    sp *= 256;
    wk->mvxy.a[1].sp += sp;
    sp = adrs[4];
    sp *= 256;
    wk->mvxy.d[1].sp += sp;
    wk->mvxy.kop[1] = adrs[5];
}



void setup_move_data_easy(WORK* wk, const s16* adrs, s16 prx, s16 pry) {
    wk->mvxy.a[0].sp = adrs[0];
    wk->mvxy.a[0].sp <<= 8;
    wk->mvxy.d[0].sp = adrs[1];
    wk->mvxy.d[0].sp <<= 8;
    wk->mvxy.kop[0] = prx;
    wk->mvxy.a[1].sp = adrs[2];
    wk->mvxy.a[1].sp <<= 8;
    wk->mvxy.d[1].sp = adrs[3];
    wk->mvxy.d[1].sp <<= 8;
    wk->mvxy.kop[1] = pry;
}



void setup_mvxy_data(wk, ix)
    WORK *wk;
    u16 ix;
{
    wk->mvxy.index = ix;
    read_adrs_store_mvxy(wk, &wk->move_xy_table[ix * 6]);
}

/* Unreferenced: blow-away movement taken from the table stored after parabora_own_table, by the
   attacker's character and our weight. */
void setup_butt_own_data_ex(WORK* wk, s16 ix) {
    s16* adrs;
    wk->mvxy.index = ix;
    adrs = (*parabora_ex_table)[ix][((PLW*)wk->target_adrs)->player_number][wk->weight_level][(s8)wk->dm_attlv];
    read_adrs_store_mvxy(wk, adrs);
}

/* Unreferenced: as above, by our character and the attacker's weight. */
void setup_butt_own_data_ex2(WORK* wk, s16 ix) {
    s16* adrs;
    wk->mvxy.index = ix;
    adrs = (*parabora_ex_table)[ix][((PLW*)wk)->player_number][((WORK*)wk->target_adrs)->weight_level][(s8)wk->dm_attlv];
    read_adrs_store_mvxy(wk, adrs);
}



void setup_butt_own_data(WORK* wk) {
    wk->mvxy.index = wk->dm_butt_type;
    read_adrs_store_mvxy(wk, ((s16(*)[4][6])parabora_own_table[wk->dm_plnum])[wk->dm_butt_type][wk->weight_level]);
}



void read_adrs_store_mvxy(WORK* wk, s16* adrs) {
    wk->mvxy.a[0].sp = adrs[0];
    wk->mvxy.a[0].sp <<= 8;
    wk->mvxy.d[0].sp = adrs[1];
    wk->mvxy.d[0].sp <<= 8;
    wk->mvxy.kop[0] = adrs[2];
    wk->mvxy.a[1].sp = adrs[3];
    wk->mvxy.a[1].sp <<= 8;
    wk->mvxy.d[1].sp = adrs[4];
    wk->mvxy.d[1].sp <<= 8;
    wk->mvxy.kop[1] = adrs[5];
}

s32 get_weight_point(WORK* wk)
{
    return wk->dm_weight - wk->weight_level + 3;
}



void cal_mvxy_speed(WORK* wk) {
    s16 i;
    for (i = 0; i < 2; i++) {
        switch (wk->mvxy.kop[i]) {
        case 0:
            wk->mvxy.a[i].sp += wk->mvxy.d[i].sp;
            break;
        default:
            break;
        case 1:
            if (wk->mvxy.a[i].sp >= 0) {
                wk->mvxy.a[i].sp += wk->mvxy.d[i].sp;
                if (wk->mvxy.a[i].sp < 0) {
                    wk->mvxy.d[i].sp = 0;
                    wk->mvxy.a[i].sp = 0;
                }
            } else {
                wk->mvxy.a[i].sp += wk->mvxy.d[i].sp;
                if (wk->mvxy.a[i].sp >= 0) {
                    wk->mvxy.d[i].sp = 0;
                    wk->mvxy.a[i].sp = 0;
                }
            }
            break;
        }
    }
}



void add_mvxy_speed(WORK* wk) {
    if (wk->rl_flag) {
        wk->xyz[0].cal += wk->mvxy.a[0].sp;
    } else {
        wk->xyz[0].cal -= wk->mvxy.a[0].sp;
    }
    wk->xyz[1].cal += wk->mvxy.a[1].sp;
}



void add_mvxy_speed_exp(WORK* wk, s16 dvp) {
    if (wk->rl_flag) {
        wk->xyz[0].cal += wk->mvxy.a[0].sp / dvp;
    } else {
        wk->xyz[0].cal -= wk->mvxy.a[0].sp / dvp;
    }
    wk->xyz[1].cal += wk->mvxy.a[1].sp;
}



void add_mvxy_speed_no_use_rl(WORK* wk) {
    wk->xyz[0].cal += wk->mvxy.a[0].sp;
    wk->xyz[1].cal += wk->mvxy.a[1].sp;
}



void add_mvxy_speed_direct(WORK* wk, s16 sx, s16 sy) {
    s32 ax;
    s32 ay;
    ax = sx;
    ay = sy;
    ax <<= 8;
    if (wk->rl_flag) {
        wk->xyz[0].cal += ax;
    } else {
        wk->xyz[0].cal -= ax;
    }
    wk->xyz[1].cal += ay << 8;
}



void reset_mvxy_data(WORK* wk) {
    wk->mvxy.a[0].sp = wk->mvxy.d[0].sp = wk->mvxy.kop[0] = 0;
    wk->mvxy.a[1].sp = wk->mvxy.d[1].sp = wk->mvxy.kop[1] = 0;
}



/* provisional name */
void setup_air_paring_mvxy(WORK* wk) {
    wk->mvxy.a[0].sp = wk->mvxy.a[0].sp * 60 / 100;
    wk->mvxy.a[1].sp = wk->mvxy.a[1].sp * 40 / 100;
    switch ((wk->mvxy.a[0].sp < 0) * 2 + (wk->mvxy.a[0].sp > 0)) {
    case 0:
    case 1:
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
        wk->mvxy.d[0].sp = -wk->mvxy.d[0].sp;
    case 2:
        if (wk->mvxy.a[0].real.h > -2) {
            wk->mvxy.a[0].real.h = -2;
        }
    }
}



void remake_mvxy_PoSB(WORK* wk) {
    if (wk->mvxy.a[1].sp < 0) {
        wk->mvxy.a[1].sp = wk->mvxy.a[1].sp * 30 / 100;
        wk->mvxy.a[1].sp = -wk->mvxy.a[1].sp;
    }
}



void remake_mvxy_PoGR(WORK* wk) {
    s32 v;
    if (wk->mvxy.d[1].sp) {
        switch (((wk->mvxy.a[1].sp < 0) * 2) + (wk->mvxy.a[1].sp > 0)) {
        case 1:
            v = wk->mvxy.a[1].sp;
            v *= 80;
            wk->mvxy.a[1].sp = v / 100;
            break;
        default:
            v = wk->mvxy.a[1].sp;
            v *= 10;
            wk->mvxy.a[1].sp = v / 100;
            break;
        }
    }
    switch (((wk->mvxy.a[0].sp < 0) * 2) + (wk->mvxy.a[0].sp > 0)) {
    case 2:
        v = wk->mvxy.a[0].sp;
        v *= 30;
        wk->mvxy.a[0].sp = v / 100;
        break;
    default:
        v = wk->mvxy.a[0].sp;
        v *= 50;
        wk->mvxy.a[0].sp = v / 100;
        if (wk->mvxy.a[0].real.h < 1) {
            wk->mvxy.a[0].real.h = 1;
        }
        wk->mvxy.d[0].sp = 0;
        wk->mvxy.a[0].sp = -wk->mvxy.a[0].sp;
    }
}



void check_body_touch(void) {
    PLW* p1w = &plw[0];
    PLW* p2w = &plw[1];
    s16 meri;
    if (p1w->wu.h_hos->hos_box[0] != 0 && p2w->wu.h_hos->hos_box[0] != 0) {
        meri = hit_check_subroutine(&p1w->wu, &p2w->wu, &p1w->wu.h_hos->hos_box[0], &p2w->wu.h_hos->hos_box[0]);
        if (meri != 0) {
            meri = meri_case_switch(meri);
            if (p1w->wu.old_pos[1] <= 0 && p2w->wu.old_pos[1] <= 0) {
                if (ichikannkei) {
                    goto one;
                }
                goto two;
            }
            if (check_work_position(&p1w->wu, &p2w->wu)) {
                goto one;
            }
            goto two;
        }
    }
    p1w->hos_em_flag = 0;
    p2w->hos_em_flag = 0;
    return;
one:
    p1w->wu.xyz[0].disp.pos += meri * (p1w->micchaku_flag != 1);
    p2w->wu.xyz[0].disp.pos -= meri * (p2w->micchaku_flag != 2);
    p1w->hos_em_flag = 2;
    p2w->hos_em_flag = 1;
    return;
two:
    p1w->wu.xyz[0].disp.pos -= meri * (p1w->micchaku_flag != 2);
    p2w->wu.xyz[0].disp.pos += meri * (p2w->micchaku_flag != 1);
    p1w->hos_em_flag = 1;
    p2w->hos_em_flag = 2;
}



s32 meri_case_switch(s16 meri) {
    switch (meri & 0xFFF8) {
    case 0:
        if (meri < 4) {
            meri /= 2;
        } else {
            meri /= 4;
        }
        break;
    case 8:
        meri = (meri * 21) / 64;
        break;
    default:
        meri = (meri * 13) / 32;
        break;
    }
    return meri;
}



void check_body_touch2(void) {
    PLW* hmw;
    PLW* cmw;
    WORK* efw;
    s16* dad0;
    s16* dad1;
    s16 meri;
    s16 ix;
    s16 dad2[4];
    s16 dad3[4];
    if (plw->wu.operator) {
        hmw = &plw[0];
        cmw = &plw[1];
    } else {
        hmw = &plw[1];
        cmw = &plw[0];
    }
    if (!saishin_bs2_on_car(hmw)) {
        efw = (WORK*)cmw->wu.my_effadrs;
        ix = (sel_hosei_tbl_ix[hmw->player_number]) + 1 + ((efw->dir_timer == 1) * 2);
        dad0 = &hmw->wu.hosei_adrs[1].hos_box[0];
        dad1 = &efw->hosei_adrs[ix].hos_box[0];
        if (!hoseishitemo_eenka(&hmw->wu, efw->xyz[0].disp.pos + (dad1[0] + dad1[1] / 2))) {
            dad2[0] = dad0[0];
            dad2[1] = dad0[1];
            dad2[2] = dad0[2];
            dad2[3] = dad0[3];
            dad3[0] = dad1[0];
            dad3[1] = dad1[1];
            dad3[2] = dad1[2];
            dad3[3] = dad1[3];
            if (hmw->wu.cg_jphos) {
                dad2[2] += hmw->wu.cg_jphos;
                dad2[3] -= hmw->wu.cg_jphos;
            }
            if (efw->xyz[1].disp.pos) {
                dad3[2] -= efw->xyz[1].disp.pos;
            }
            meri = hit_check_subroutine(&hmw->wu, efw, &dad2[0], &dad3[0]);
            if (meri != 0) {
                meri = meri_case_switch(meri);
                if (!check_work_position_bonus(&hmw->wu, efw->xyz[0].disp.pos + (dad1[0] + dad1[1] / 2))) {
                    goto two;
                } else {
                    goto one;
                }
            }
        }
    }
    hmw->hos_em_flag = 0;
    cmw->hos_em_flag = 0;
    return;
one:
    hmw->wu.xyz[0].disp.pos += (meri) * (hmw->micchaku_flag != 1);
    hmw->hos_em_flag = 2;
    cmw->hos_em_flag = 1;
    return;
two:
    hmw->wu.xyz[0].disp.pos -= (meri) * (hmw->micchaku_flag != 2);
    hmw->hos_em_flag = 1;
    cmw->hos_em_flag = 2;
    return;
}



s32 hoseishitemo_eenka(WORK* wk, s16 tx) {
    s16 rnum = 0;
    if (((s32 (*)(WORK*))cal_top_of_position_y)(wk) + wk->cg_jphos > bs2_floor[2] || wk->mvxy.a[1].real.h < 0) {
        switch ((wk->xyz[0].disp.pos < tx) + (wk->rl_flag != 0) * 2) {
        case 1:
        case 2:
            if (wk->mvxy.a[1].real.h > 0 && wk->mvxy.a[0].real.h < 0) {
                rnum = 1;
            }
            if (wk->mvxy.a[1].real.h < 0 && wk->mvxy.a[0].real.h > 0) {
                rnum = 1;
            }
            break;
        default:
            if (wk->mvxy.a[1].real.h > 0 && wk->mvxy.a[0].real.h > 0) {
                rnum = 1;
            }
        }
    }
    return rnum;
}



s16 get_sel_hosei_tbl_ix(s16 plnum) {
    return sel_hosei_tbl_ix[plnum];
}



s32 check_work_position_bonus(WORK* hm, s16 tx) {
    s16 result = hm->xyz[0].disp.pos - tx;
    s16 num;
    if (result) {
        if (result > 0) {
            num = 1;
        } else {
            num = 0;
        }
    } else {
        num = hm->rl_flag == 0;
    }
    return num;
}



s32 set_field_hosei_flag(PLW* pl, s16 pos, s16 ix) {
    s16 hami;
    if (ix != 0) {
        hami = pl->wu.xyz[0].disp.pos + satse[pl->player_number] - pos;
        if (hami) {
            if (hami >= 0) {
                pl->wu.xyz[0].disp.pos -= hami;
                pl->micchaku_flag = 1;
                pl->hos_fi_flag = 1;
                pl->hosei_amari = -hami;
            } else {
                goto no_hosei;
            }
        } else {
            pl->micchaku_flag = 1;
            pl->hos_fi_flag = 0;
            pl->hosei_amari = 0;
        }
    } else {
        hami = pl->wu.xyz[0].disp.pos - satse[pl->player_number] - pos;
        if (hami) {
            if (hami <= 0) {
                pl->wu.xyz[0].disp.pos -= hami;
                pl->micchaku_flag = 2;
                pl->hos_fi_flag = 2;
                pl->hosei_amari = -hami;
            } else {
                goto no_hosei;
            }
        } else {
            pl->micchaku_flag = 2;
            pl->hos_fi_flag = 0;
            pl->hosei_amari = 0;
        }
    }
    return 0;
no_hosei:
    pl->micchaku_flag = 0;
    pl->hos_fi_flag = 0;
    pl->hosei_amari = 0;
    return 1;
}



s32 check_work_position(WORK* p1, WORK* p2) {
    s16 r;
    s16 d = p1->xyz[0].disp.pos - p2->xyz[0].disp.pos;
    if (d) {
        if (d > 0) {
            r = 1;
        } else {
            r = 0;
        }
    } else if ((p1->rl_flag + p2->rl_flag) & 1) {
        if (p1->rl_flag) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        switch ((p1->xyz[1].disp.pos == 0) + (p2->xyz[1].disp.pos == 0) * 2) {
        case 1:
            if (p1->rl_flag) {
                r = 0;
            } else {
                r = 1;
            }
            break;
        case 2:
            if (p2->rl_flag) {
                r = 0;
            } else {
                r = 1;
            }
            break;
        default:
            r = 0;
            break;
        }
    }
    return r;
}



s32 random_32_com(void) {
    Random_ix32_com++;
    Random_ix32_com &= 0x7F;
    return random_tbl_32_com[Random_ix32_com];
}



s32 random_16_com(void) {
    Random_ix16_com++;
    Random_ix16_com &= 0x3F;
    return random_tbl_16_com[Random_ix16_com];
}

/* Next value from the CPU's 32-entry extra random table. */
s32 random_32_ex_com(void)
{
    Random_ix32_ex_com++;
    Random_ix32_ex_com &= 0x1F;
    return random_tbl_32_ex[(s16)Random_ix32_ex_com];
}

/* Next value from the CPU's 16-entry extra random table. */
s32 random_16_ex_com(void)
{
    Random_ix16_ex_com++;
    Random_ix16_ex_com &= 0xF;
    return random_tbl_16_ex_com[Random_ix16_ex_com];
}



s32 get_guard_direction(WORK* as, WORK* ds) {
    s16 result;
    s8 num;
    if (as->work_id == 1) {
        result = as->xyz[0].disp.pos - ds->xyz[0].disp.pos;
        if (result) {
            if (result < 0) {
                if (ds->rl_flag) {
                    num = 1;
                } else {
                    num = 2;
                }
            } else if (ds->rl_flag) {
                num = 2;
            } else {
                num = 1;
            }
        } else {
            num = 3;
        }
    } else if (as->rl_flag + ds->rl_flag & 1) {
        num = 2;
    } else {
        num = 3;
    }
    return num;
}



s16 cal_attdir(WORK* wk) {
    s16 resdir = wk->att.dir;
    if (wk->rl_flag) {
        resdir = dir16_rl_conv[resdir];
    }
    return resdir;
}



s16 cal_attdir_flip(s16 index) {
    return dir16_rl_conv[index];
}
