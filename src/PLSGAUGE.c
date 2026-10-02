/*
 * PLSGAUGE.C  Vitality, hit stop and super art gauge rules
 *
 * setup_vitality sets a player's starting vitality; cal_dm_vital_gauge_hosei adjusts damage.
 * set_hit_stop_hit_quake sets the hit stop and screen shake after a hit.
 * The add_sp_arts_gauge_* routines decide how much super art gauge each event earns: starting an
 * attack, guarding, hitting and taking damage, parrying, personal actions, recovery rolls and
 * throw escapes, scaled down by the combo count (cal_sa_gauge_waribiki) and added by
 * add_super_arts_gauge; sa_gauge_flash is the gauge flash table.
 * check_buttobi_type, setup_saishin_lvdir and setup_lvdir_after_autodir handle blow-away type
 * and lever direction; dead_voice_request/2 request the KO voice. short_to_bcd converts a count
 * to BCD digits.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"
#include "PLS02.h"
#include "PLSGAUGE.h"



void setup_vitality(WORK* wk, s16 pno) {
    s16 ix;
    if (wk->operator == 0) {
        ix = Game_setting.level + CC_Value[1];
    } else {
        ix = 2;
    }
    wk->original_vitality = Com_Vital_Unit_Data[pno][Game_setting.set2][ix];
    wk->dmcal_m = 32;
    wk->dmcal_d = wk->original_vitality * 32 / Max_vitality;
    wk->vitality = wk->vital_new = wk->vital_old = Max_vitality;
    wk->dm_vital = 0;
}



void cal_dm_vital_gauge_hosei(PLW* wk) {
    s32 v;
    s16 cnjix;
    if (!wk->wu.dm_vital) {
        return;
    }
    v = Max_vitality;
    v *= 6;
    if (wk->wu.vital_new < v / 10) {
        if (Max_vitality == 192) {
            cnjix = wk->wu.vital_new / 19;
        } else {
            cnjix = wk->wu.vital_new / 16;
        }
        if (cnjix > 5) {
            cnjix = 5;
        }
        v = wk->wu.dm_vital;
        v *= konjyou_tbl[wk->player_number][cnjix];
        wk->wu.dm_vital = v / wk->wu.dmcal_m;
    }
    v = wk->wu.dm_vital;
    v *= 32 - wk->tk_konjyou;
    wk->wu.dm_vital = v / wk->wu.dmcal_m;
    v = wk->wu.dm_vital;
    v *= wk->wu.dmcal_m;
    wk->wu.dm_vital = v / wk->wu.dmcal_d;
    if (wk->wu.dm_vital <= 0) {
        wk->wu.dm_vital = 1;
    }
}


/* provisional name */
s16 get_sa_gauge_len(s16 id) {
    return plw[id].sa->gauge_len;
}



void set_hit_stop_hit_quake(WORK* wk) {
    if (wk->dm_stop) {
        wk->hit_stop = wk->dm_stop;
        wk->dm_stop = 0;
    }
    if (wk->dm_quake) {
        wk->hit_quake = wk->dm_quake;
        wk->dm_quake = 0;
    }
}



void add_sp_arts_gauge_init(PLW* wk) {
    PLW* mwk;
    s16 asag;
    if (wk->wu.work_id != 1) {
        mwk = (PLW*)wk->cp;
        if (mwk->wu.work_id == 1) {
            asag = add_arts_gauge[mwk->player_number][wk->wu.add_arts_point][0];
            add_super_arts_gauge(mwk->sa, mwk->wu.id, asag, mwk->metamorphose);
        }
    } else {
        asag = add_arts_gauge[wk->player_number][wk->wu.add_arts_point][0];
        add_super_arts_gauge(wk->sa, wk->wu.id, asag, wk->metamorphose);
    }
}



void add_sp_arts_gauge_guard(PLW* wk) {
    PLW* mwk;
    s16 asag;
    if (wk->wu.work_id != 1) {
        mwk = (PLW*)wk->cp;
        if (mwk->wu.work_id == 1) {
            asag = add_arts_gauge[mwk->player_number][wk->wu.add_arts_point][1];
            add_super_arts_gauge(mwk->sa, mwk->wu.id, asag, mwk->metamorphose);
        }
    } else {
        asag = add_arts_gauge[wk->player_number][wk->wu.add_arts_point][1];
        add_super_arts_gauge(wk->sa, wk->wu.id, asag, wk->metamorphose);
    }
}



void add_sp_arts_gauge_hit_dm(PLW* wk) {
    PLW* emwk;
    s16 asag;
    if (wk->wu.work_id != 1) {
        return;
    }
    emwk = (PLW*)wk->wu.target_adrs;
    asag = add_arts_gauge[emwk->player_number][wk->wu.dm_arts_point][2];
    if (asag) {
        add_super_arts_gauge(wk->sa, wk->wu.id, asag / 3, wk->metamorphose);
        if (emwk->wu.operator == 0) {
            asag += (((Country & 2) ? asagh_zuru2 : asagh_zuru)[Game_setting.level]);
        }
        if (asag <= 0) {
            asag = 1;
        }
        asag = cal_sa_gauge_waribiki(wk, asag);
        if (emwk->wu.operator == 0 && Break_Into_CPU == 1) {
            asag = (asag * 120) / 100;
        }
        add_super_arts_gauge(emwk->sa, emwk->wu.id, asag, emwk->metamorphose);
    }
    wk->wu.dm_arts_point = 0;
}



/* provisional name */
s32 cal_sa_gauge_waribiki(PLW* wk, s16 asag) {
    s16 num;
    if (wk->cb->total <= 1) {
        return asag;
    }
    num = 32 - (wk->cb->total - 1) * 2;
    if (num <= 0) {
        num = 1;
    }
    asag = (asag * num) / 32;
    if (asag == 0) {
        asag = 1;
    }
    return asag;
}


/* provisional name */
void cal_sa_gauge_dummy(void) {}



void add_sp_arts_gauge_paring(PLW* wk) {
    u16 asag;
    if (wk->wu.work_id == 1) {
        PLW* emwk = (PLW*)wk->wu.target_adrs;
        asag = add_arts_gauge[emwk->player_number][wk->wu.dm_arts_point][3];
        if ((s16)asag != 0) {
            if (wk->wu.operator == 0) {
                if (Country & 2) {
                    asag += asagh_zuru2[Game_setting.level];
                } else {
                    asag += asagh_zuru[Game_setting.level];
                }
            }
            if ((s16)asag <= 0) {
                asag = 1;
            }
            add_super_arts_gauge(wk->sa, wk->wu.id, (s16)asag, wk->metamorphose);
        }
        wk->wu.dm_arts_point = 0;
    }
}



void add_sp_arts_gauge_tokushu(PLW* wk) {
    s32 asag;
    if (wk->wu.work_id != 1) {
        return;
    }
    asag = apagt_table[wk->player_number];
    if (!asag) {
        return;
    }
    if (!wk->wu.operator) {
        if (Country & 2) {
            asag += asagh_zuru2[(*&Game_setting).level];
        } else {
            asag += asagh_zuru[(*&Game_setting).level];
        }
    }
    if (asag <= 0) {
        asag = 1;
    }
    ((void(*)(SA_WORK* wk, s16 ix, s16 asag, u16 mf))add_super_arts_gauge)(wk->sa, wk->wu.id, asag, wk->metamorphose);
}



void add_sp_arts_gauge_ukemi(PLW* wk) {
    s16 asag;
    if (wk->wu.work_id != 1) {
        return;
    }
    asag = ukemi_apagt_table[wk->player_number];
    if (asag == 0) {
        return;
    }
    if (wk->wu.operator == 0) {
        if (Country & 2) {
            asag += asagh_zuru2[Game_setting.level];
        } else {
            asag += asagh_zuru[Game_setting.level];
        }
    }
    if (asag <= 0) {
        asag = 1;
    }
    add_super_arts_gauge(wk->sa, wk->wu.id, asag, wk->metamorphose);
}



void add_sp_arts_gauge_nagenuke(PLW* wk) {
    s32 asag;
    if (wk->wu.work_id != 1) {
        return;
    }
    asag = nagenuke_apagt_table[wk->player_number];
    if (!asag) {
        return;
    }
    if (!wk->wu.operator) {
        if (Country & 2) {
            asag += asagh_zuru2[(*&Game_setting).level];
        } else {
            asag += asagh_zuru[(*&Game_setting).level];
        }
    }
    if (asag <= 0) {
        asag = 1;
    }
    ((void(*)(SA_WORK* wk, s16 ix, s16 asag, u16 mf))add_super_arts_gauge)(wk->sa, wk->wu.id, asag, wk->metamorphose);
}



s32 add_super_arts_gauge(wk, ix, asag, mf)
    SA_WORK *wk;
    s16 ix;
    s16 asag;
    u8 mf;
{
    if (!test_flag) {
        if (mf) {
            return 0;
        }
        if (wk->ok == -1) {
            return 0;
        }
        if (pcon_dp_flag) {
            return 0;
        }
        if (Bonus_Game_Flag) {
            return 0;
        }
        if (wk->store == wk->store_max) {
            return 0;
        }
        asag = asag * 120 / 100;
        if (Battle_Round[Play_Type] == 0) {
            asag = asag * 150 / 100;
        }
        wk->gauge.s.h += asag;
        wk->gauge.s.l = -1;
        if (wk->gauge.s.h > wk->gauge_len) {
            wk->store += 1;
            if (wk->store < wk->store_max) {
                wk->gauge.s.h -= wk->gauge_len;
            } else {
                wk->store = wk->store_max;
                if (wk->gauge_type == 1) {
                    wk->gauge.s.h = wk->gauge_len;
                } else {
                    wk->gauge.i = 0;
                }
            }
            sa_gauge_flash[ix] |= 1;
        }
    }
}



s16 check_buttobi_type(PLW* wk) {
    s16 rn;
    setup_butt_own_data(&wk->wu);
    rn = dir32_skydm[cal_move_dir_forecast(&wk->wu, 5)];
    return rn;
}

s32 check_buttobi_type2(WORK* wk)
{
    s32 dir;
    setup_butt_own_data();
    dir = cal_move_dir_forecast(wk, 5);
    return dir32_grddm[dir];
}



void setup_saishin_lvdir(PLW* ds) {
    if ((ds->sa_stop_flag) == 1) {
        if (ds->wu.rl_flag) {
            ds->saishin_lvdir = convert_saishin_lvdir[1][ds->sa_stop_lvdir & 0xC];
        } else {
            ds->saishin_lvdir = convert_saishin_lvdir[0][ds->sa_stop_lvdir & 0xC];
        }
    } else if (ds->wu.rl_flag) {
        ds->saishin_lvdir = convert_saishin_lvdir[1][ds->cp->sw_lvbt & 0xC];
    } else {
        ds->saishin_lvdir = convert_saishin_lvdir[0][ds->cp->sw_lvbt & 0xC];
    }
}



void setup_lvdir_after_autodir(PLW* wk) {
    const u8* p = convert_saishin_lvdir[0];
    if (wk->wu.rl_flag) {
        p += wk->cp->sw_lvbt & 0xC;
        p += 16;
        wk->cp->lever_dir = *p;
    } else {
        p += wk->cp->sw_lvbt & 0xC;
        wk->cp->lever_dir = *p;
    }
}



void dead_voice_request(void) {
    if (dead_voice_flag) {
        if (plw[0].dead_flag) {
            dead_voice_request2(&plw[0]);
        }
        if (plw[1].dead_flag) {
            dead_voice_request2(&plw[1]);
        }
    }
    dead_voice_flag = 0;
}



void dead_voice_request2(PLW* wk) {
    s16 secd1;
    s16 secd2;
    s16 ks = 0;
    if (wk->metamorphose != 0 && Country != 8) {
        ks = 0x600;
    }
    secd1 = dead_voice_table[wk->player_number][0];
    secd2 = dead_voice_table[wk->player_number][1];
    if ((wk->wu.routine_no[1] == 1) && atsagct[wk->wu.routine_no[2]] & 0x10) {
        sound_effect_request[secd2](wk, secd2 + ks);
    } else {
        sound_effect_request[secd1](wk, secd1 + ks);
    }
}


/* provisional name */
s32 short_to_bcd(s16 num) {
    u16 bcd = 0;
    u16 div = 1000;
    u16 digit = 0x1000;
    s16 i;
    i = 0;
    goto test;
body:
    if (num >= div) {
        num -= div;
        bcd += digit;
        goto body;
    }
    digit >>= 4;
    div /= 10;
    i++;
test:
    if (i < 3) {
        goto body;
    }
    bcd += num;
    return bcd;
}



/* provisional name: unreferenced; picks the player whose grade the hidden display shows */
void kakushi_setup(s32 pl) {
    u16 sw;
    s32 other = 1 & (pl + 1);
    s16 q = pl;
    if (PT_backup == 0) {
        kakushi_op = 0;
        if (RO_backup[(s16)pl]) {
            kakushi_ix = other;
        } else {
            kakushi_ix = pl;
        }
        kakushi_on = 0;
        return;
    } else {
        kakushi_op = 1;
        kakushi_ix = pl;
        if (q) {
            sw = p2sw_0;
        } else {
            sw = p1sw_0;
        }
        kakushi_on = sw == 0xF6;
    }
}
