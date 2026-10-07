/*
 * HITCHECK.C  Hit detection and damage resolution
 *
 * Players and effects queue themselves each frame with hit_push_request; hit_check_main_process
 * (from Game_Main and end_sub) then runs catch_hit_check (throws), attack_hit_check (attack boxes
 * against damage boxes), set_judge_result and check_result_extra, and clears the queue.
 * The judged pairs go to the per-pair routines in HITPLPL, HITPLEF, HITEFPL and HITEFEF.
 * This module sets the resulting states: struck (set_struck_status), caught, guard and blocking
 * (parry, set_paring_status), damage and stun (set_damage_and_piyo), combo work and damage
 * reduction (add_combo_work, cal_combo_waribiki), hit stop and hit mark positions.
 * It also provides the damage routine lookups by damage index and general helpers used by many
 * effects and moves: hit_check_subroutine, hit_check_x_only, get_target_att_position.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "Grade.h"
#include "PLS02.h"
#include "EFF02.h"
#include "HITEFEF.h"
#include "HITEFPL.h"
#include "HITPLEF.h"
#include "HITPLPL.h"
#include "ta_sub.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "HITCHECK.h"
#include "fighter.h"

struct PLW_tag;



/* provisional name */
void set_char_base_data_init(WORK* wk) {
    const CHAR_INIT_ROM* cdat =
        (const CHAR_INIT_ROM*)((u8*)char_init_data + (s16)(wk->charset_id * sizeof(CHAR_INIT_ROM)));
    wk->char_table[0] = cdat->nmca;
    wk->char_table[1] = cdat->dmca;
    wk->char_table[6] = cdat->btca;
    wk->char_table[2] = cdat->caca;
    wk->char_table[3] = cdat->cuca;
    wk->char_table[4] = cdat->atca;
    wk->char_table[5] = cdat->saca;
    wk->char_table[7] = cdat->exca;
    wk->char_table[8] = cdat->cbca;
    wk->char_table[9] = cdat->yuca;
    wk->step_xy_table = cdat->stxy;
    wk->move_xy_table = cdat->mvxy;
    wk->se_random_table = cdat->sernd;
    wk->overlap_char_tbl = cdat->ovct;
    wk->olc_ix_table = cdat->ovix;
    wk->rival_catch_tbl = cdat->rict;
    wk->hit_ix_table = cdat->hiit;
    wk->body_adrs = cdat->boda;
    wk->hand_adrs = cdat->hana;
    wk->catch_adrs = cdat->cata;
    wk->caught_adrs = cdat->caua;
    wk->attack_adrs = cdat->atta;
    wk->hosei_adrs = cdat->hosa;
    wk->att_ix_table = cdat->atit;
    wk->cgromtype = cdat->cgromtype;
    wk->my_col_mode = cdat->my_cm;
    wk->my_col_code = cdat->my_cc;
    wk->my_family = cdat->my_fm;
    wk->my_ext_pri = cdat->my_ep;
}



/* provisional name */
void hit_check_main_process(void) {
    aiuchi_flag = 0;
    if (hpq_in > 1) {
        if (ca_check_flag) {
            catch_hit_check();
        }
        attack_hit_check();
        if (set_judge_result()) {
            check_result_extra();
        }
    }
    clear_hit_queue();
}



s16 set_judge_result(void) {
    s16 i;
    s16 rnum = 0;
    for (i = 0; i < hpq_in; i++) {
        if (hs[i].flag.results & 0x101) {
            rnum = 1;
            if (hs[i].flag.results & 0x100) {
                set_caught_status(i);
            } else {
                set_struck_status(i);
            }
        }
    }
    return rnum;
}



void check_result_extra(void) {
    WORK_Other* dm1p;
    WORK_Other* dm2p;
    s16 hs1;
    s16 hs2;
    s16 qua;
    s16 p1state;
    s16 p2state;
    p1state = plw[0].wu.routine_no[1] == 1 && plw[0].wu.routine_no[3] == 0;
    p2state = plw[1].wu.routine_no[1] == 1 && plw[1].wu.routine_no[3] == 0;
    if (p1state & p2state) {
        dm1p = (WORK_Other*)plw[0].wu.dmg_adrs;
        dm2p = (WORK_Other*)plw[1].wu.dmg_adrs;
        switch ((dm1p->wu.work_id == 1) + ((dm2p->wu.work_id == 1) * 2)) {
        case 3:
            aiuchi_flag = 1;
            if ((hs1 = plw[0].wu.dm_stop) < 0) {
                hs1 = -hs1;
            }
            if ((hs2 = plw[1].wu.dm_stop) < 0) {
                hs2 = -hs2;
            }
            qua = plw[0].wu.dm_quake;
            if (qua < plw[1].wu.dm_quake) {
                qua = plw[1].wu.dm_quake;
            }
            if (hs1 > hs2) {
                plw[0].wu.hit_stop = plw[1].wu.hit_stop = hs1;
                plw[0].wu.hit_quake = plw[1].wu.hit_quake = qua;
            } else if (hs2) {
                plw[0].wu.hit_stop = plw[1].wu.hit_stop = hs2;
                plw[0].wu.hit_quake = plw[1].wu.hit_quake = qua;
            }
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
            plw[0].wu.dm_nodeathattack = plw[1].wu.dm_nodeathattack = 0;
        }
        return;
    }
}



void set_caught_status(s16 ix) {
    s16 ix2 = hs[ix].dm_me;
    PLW* as = (PLW*)q_hit_push[ix2];
    PLW* ds = (PLW*)q_hit_push[ix];
    s16 blocking_status = check_blocking_flag(as, ds);
    s8 gddir;
    s32 dm_type;
wait_hit:
    if (ix != hs[ix2].my_hit) {
        goto wait_hit;
    }
wait_dm:
    if (hs[ix2].flag.results & 0x100) {
        if (ix != hs[ix2].dm_me) {
            goto wait_dm;
        }
        if (as->wu.att.dipsw & 0x40) {
            if (ds->wu.att.dipsw & 0x40) {
            } else {
                goto two;
            }
        } else if (as->wu.att.dipsw & 0x20) {
            if (ds->wu.att.dipsw & 0x40) {
                goto one;
            }
            if (ds->wu.att.dipsw & 0x20) {
            } else {
                goto two;
            }
        } else if (ds->wu.att.dipsw & 0x60) {
            goto one;
        } else {
            switch (blocking_status) {
            case 1:
                ds->hazusenai_flag = 1;
                goto two;
            case 2:
                as->hazusenai_flag = 1;
                goto one;
            case 3:
                ds->hazusenai_flag = 1;
                as->hazusenai_flag = 1;
                break;
            default:
                as->cat_break_reserve = ds->cat_break_reserve = 1;
                break;
            }
        }
        if (Game_timer & 1) {
            goto two;
        }
    one:
        hs[ix2].flag.results &= 0x111;
        hs[ix].flag.results &= 0x1011;
        return;
    two:
        hs[ix2].flag.results &= 0x1011;
        hs[ix].flag.results &= 0x111;
    }
    as->wu.hit_adrs = (u32*)ds;
    ds->wu.dmg_adrs = (u32*)as;
    as->wu.hit_work_id = ds->wu.work_id;
    ds->wu.dmg_work_id = as->wu.work_id;
    ds->dm_point = 1;
    gddir = get_guard_direction(&as->wu, &ds->wu);
    setup_saishin_lvdir(ds, gddir);
    setup_dm_rl(&as->wu, &ds->wu);
    set_catch_hit_mark_pos(&as->wu, &ds->wu);
    set_damage_and_piyo(as, ds);
    ds->wu.dm_guard_success = -1;
    if (ds->guard_flag == 3 || as->wu.att.guard == 0 || ds->py->flag != 0) {
        if (ds->wu.xyz[1].disp.pos > 0 || check_pat_status(&ds->wu)) {
            goto three;
        }
        goto four;
    } else if (ds->wu.xyz[1].disp.pos > 0) {
        switch (defense_sky(as, ds, gddir)) {
        case 0:
            goto blocking;
        case 1:
            goto guard;
        }
    three:
        as->wu.hf.hit.player = 2;
        ds->wu.routine_no[2] = as->wu.att.reaction;
    } else {
        switch (defense_ground(as, ds, gddir)) {
        case 0:
            goto blocking;
        case 1:
            goto guard;
        default:
            break;
        }
    four:
        as->wu.hf.hit.player = 1;
        ds->wu.routine_no[2] = as->wu.att.reaction;
    }
    dm_type = 0;
    if (ds->wu.routine_no[1] == 1 && ds->wu.cg_type == 10) {
        dm_type = 1;
    }
    switch (dm_type + (((as->wu.rl_flag + ds->wu.rl_flag) & 1) * 2)) {
    case 0:
    case 3:
        as->wu.routine_no[1] = as->wu.cmcr.koc;
        as->wu.routine_no[2] = as->wu.cmcr.ix;
        as->wu.char_index = as->wu.cmcr.pat;
        break;
    default:
        as->wu.routine_no[1] = as->wu.cmcf.koc;
        as->wu.routine_no[2] = as->wu.cmcf.ix;
        as->wu.char_index = as->wu.cmcf.pat;
        break;
    }
    as->wu.routine_no[3] = 0;
    if (ds->guard_flag == 3 || blocking_status & 1) {
        ds->hazusenai_flag = 1;
    }
    as->tsukami_num = ds->player_number;
    as->tsukami_f = 1;
    ds->tsukamare_f = 1;
    ds->wu.routine_no[1] = 3;
    ds->wu.routine_no[2] = as->wu.att.ng_type;
    ds->wu.routine_no[3] = 0;
    grade_add_clean_hits((WORK_Other*)as);
    check_guard_miss(&as->wu, ds, gddir);
    if (as->wu.att.ng_type == 2) {
        ds->wu.xyz[1].disp.pos = as->wu.xyz[1].disp.pos;
    }
    effect_02_init(&as->wu, ds->dm_point, 1, ds->wu.dm_rl);
    dm_status_copy(&as->wu, &ds->wu);
    ds->wu.dm_vital = 0;
    as->wu.hit_stop = ds->wu.dm_stop = 0;
    as->wu.cmwk[8]++;
    as->wu.cmwk[0xF]++;
    ds->wu.dm_count_up++;
    hit_pattern_extdat_check(&as->wu);
    paring_ctr_vs[Play_Type][ds->wu.id] = 0;
    paring_counter[ds->wu.id] = 0;
    paring_bonus_r[ds->wu.id] = 0;
    return;
guard:
    set_guard_status(as, ds);
    return;
blocking:
    set_blocking_status(as, ds);
}



s32 check_pat_status(WORK* wk) {
    if (wk->pat_status >= 14 && wk->pat_status <= 30) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 check_blocking_flag(PLW* as, PLW* ds) {
    WORK_CP* wp;
    s16 num;
    wp = ds->cp;
    num = (wp->waza_flag[3] + wp->waza_flag[4]) != 0;
    wp = as->cp;
    num += (wp->waza_flag[3] + wp->waza_flag[4] != 0) << 1;
    return num;
}



void setup_catch_atthit(WORK* as, WORK* ds) {
    set_damage_and_piyo((PLW*)as, (PLW*)ds);
    dm_status_copy(as, ds);
    as->hit_stop = ds->dm_stop = 0;
}



void set_catch_hit_mark_pos(WORK* as, WORK* ds) {
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][0];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][0];
        }
        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][1];
    } else {
        cal_hit_mark_position(ds, as, (s16*)ds->h_cau, (s16*)as->h_cat);
    }
}



void set_struck_status(s16 ix) {
    WORK* as;
    WORK* ds;
    s16 ix2;
    ix2 = hs[ix].dm_me;
wait_hit:
    if (ix != hs[ix2].my_hit) {
        goto wait_hit;
    }
    as = q_hit_push[ix2];
    ds = q_hit_push[ix];
    as->hit_adrs = (u32*)ds;
    ds->dmg_adrs = (u32*)as;
    as->hit_work_id = ds->work_id;
    ds->dmg_work_id = as->work_id;
    switch ((as->work_id == 1) + ((ds->work_id == 1) * 2)) {
    case 3:
        player_at_vs_player_dm(ix2, ix);
        break;
    case 2:
        if (hs[ix].flag.results & 0x10) {
            if (hs[ix].my_hit == ix2) {
                as->att_hit_ok = 1;
                break;
            }
        }
        effect_at_vs_player_dm(ix2, ix);
        break;
    case 1:
        player_at_vs_effect_dm(ix2, ix);
        break;
    default:
        effect_at_vs_effect_dm(ix2, ix);
        break;
    }
}



void cal_hit_mark_pos(WORK* as, WORK* ds, s16 ix2, s16 ix) {
    if (as->att.mkh_ix) {
        if (as->rl_flag) {
            as->hit_mark_x = as->xyz[0].disp.pos - hit_mark_hosei_table[as->att.mkh_ix][0];
        } else {
            as->hit_mark_x = as->xyz[0].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][0];
        }
        as->hit_mark_y = as->xyz[1].disp.pos + hit_mark_hosei_table[as->att.mkh_ix][1];
    } else {
        cal_hit_mark_position(ds, as, hs[ix].dh, hs[ix2].ah);
    }
    as->hit_mark_z = as->position_z - 8;
}



void set_paring_status(PLW* as, PLW* ds) {
    s16 hsadix;
    if ((as->wu.att.hs_you == 0) && (as->wu.att.hs_me == 0)) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        hsadix = 4;
        if ((as->wu.kind_of_waza & 0xF8) == 0) {
            hsadix = (as->wu.kind_of_waza / 2) & 3;
        }
        ds->wu.routine_no[1] = 0;
        ds->wu.routine_no[3] = 0;
        waza_slot_clear_all_p(ds);
        dm_status_copy(&as->wu, &ds->wu);
        ds->wu.dm_piyo = 0;
        ds->wu.cg_type = 0;
        switch ((as->wu.xyz[1].disp.pos > 0) + (ds->wu.routine_no[2] - 31) * 2) {
        case 0:
        case 2:
        case 4:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = sel_hs_add_tbl[hsadix] + 16;
            as->wu.hit_quake = sel_hs_add_tbl[hsadix] + 16;
            break;
        case 1:
        case 3:
        case 5:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 6:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 7:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 8:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 9:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        default:
            ds->wu.dm_stop = 0;
            as->wu.hit_stop = 0;
            as->wu.hit_quake = 0;
            break;
        }
        ds->wu.dm_quake = 0;
        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }
        ds->wu.dm_arts_point = 0;
        if (as->wu.pat_status >= 0xE && as->wu.pat_status < 31 && as->wu.work_id == 1 &&
            sel_sp_ch_tbl[as->wu.kind_of_waza >> 3] == 0) {
            remake_mvxy_PoGR(&as->wu);
        }
        if (Bonus_Game_Flag == 0 && ds->spmv_ng_flag & 0x80) {
            paring_bonus_r[ds->wu.id] = 1;
            paring_ctr_vs[Play_Type][ds->wu.id]++;
            if (paring_ctr_vs[Play_Type][ds->wu.id] > 39) {
                paring_ctr_vs[Play_Type][ds->wu.id] = 39;
            }
            paring_counter[ds->wu.id] = parisucc_pts[Play_Type][paring_ctr_vs[Play_Type][ds->wu.id] - 1];
        }
        as->wu.cmwk[8]++;
    }
    hit_pattern_extdat_check(&as->wu);
}



void plef_at_vs_player_damage_union(PLW* as, PLW* ds, s8 gddir) {
    ds->wu.dm_guard_success = -1;
    if (ds->guard_flag == 3 || as->wu.att.guard == 0 || ds->py->flag != 0) {
        if (ds->wu.pat_status == 10) {
            ds->wu.xyz[1].cal = 0;
            goto switch_defense_ground;
        } else if (ds->wu.pat_status == 12 && ds->wu.xyz[1].disp.pos < 6) {
            ds->wu.xyz[1].cal = 0;
            goto switch_defense_ground;
        }
        if (ds->wu.routine_no[1] == 1) {
            if (ds->wu.xyz[1].disp.pos > 0 || check_pat_status(&ds->wu)) {
                goto jump_one;
            } else {
                goto jump_two;
            }
        }
    }
    if (ds->wu.xyz[1].disp.pos > 0 || check_pat_status(&ds->wu)) {
        switch (defense_sky(as, ds, gddir)) {
        case 0:
            goto set_paring_status;
        case 1:
            goto set_guard_status;
        }
    jump_one:
        as->wu.hf.hit.player = 2;
        dm_reaction_init_set(as, ds);
        if (as->wu.att.dipsw & 0x10) {
            ds->wu.routine_no[2] = get_sky_sp_damage(ds->wu.routine_no[2]);
        } else {
            ds->wu.routine_no[2] = get_sky_nm_damage(ds->wu.routine_no[2]);
        }
    } else {
    switch_defense_ground:
        switch (defense_ground(as, ds, gddir)) {
        case 0:
            goto set_paring_status;
        case 1:
            goto set_guard_status;
        }
    jump_two:
        as->wu.hf.hit.player = 1;
        dm_reaction_init_set(as, ds);
        if (as->wu.zu_flag == 0) {
            if (ds->wu.pat_status >= 32) {
                ds->wu.routine_no[2] = get_kagami_damage(ds->wu.routine_no[2]);
            } else {
                switch (ds->dm_point) {
                case 0:
                case 1:
                    if (check_head_damage(ds->wu.routine_no[2])) {
                        ds->wu.routine_no[2] = get_kind_of_head_dm(as->wu.dir_atthit, ds->wu.dm_rl);
                    }
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    ds->wu.routine_no[2] = get_grd_hand_damage(ds->wu.routine_no[2]);
                default:
                    if (check_trunk_damage(ds->wu.routine_no[2])) {
                        ds->wu.routine_no[2] = get_kind_of_trunk_dm(as->wu.dir_atthit, ds->wu.dm_rl);
                    }
                }
            }
        }
    }
    ds->wu.routine_no[1] = 1;
    ds->wu.routine_no[3] = 0;
    grade_add_clean_hits((WORK_Other*)as);
    check_guard_miss(&as->wu, ds, gddir);
    effect_02_init(&as->wu, ds->dm_point, 1, ds->wu.dm_rl);
    dm_status_copy(&as->wu, &ds->wu);
    same_dm_stop(&as->wu, &ds->wu);
    as->wu.cmwk[8]++;
    as->wu.cmwk[15]++;
    ds->wu.dm_count_up++;
    if (ds->wu.xyz[1].disp.pos < 0) {
        ds->wu.xyz[1].cal = 0;
    }
    add_combo_work(as, ds);
    hit_pattern_extdat_check(&as->wu);
    if (ds->atemi_flag && ds->atemi_point != ds->dm_point) {
        ds->atemi_flag = 0;
    }
    paring_ctr_vs[Play_Type][ds->wu.id] = 0;
    paring_counter[ds->wu.id] = 0;
    paring_bonus_r[ds->wu.id] = 0;
    return;
set_guard_status:
    set_guard_status(as, ds);
    return;
set_paring_status:
    set_blocking_status(as, ds);
}



void dm_reaction_init_set(PLW* as, PLW* ds) {
    ds->wu.routine_no[2] = as->wu.att.reaction;
    if (ds->wu.routine_no[2] == 89 || ds->wu.routine_no[2] == 90) {
        if (ds->running_f == 1 && Dsas_dir_table[as->wu.att.dir]) {
            if (check_work_position(&as->wu, &ds->wu)) {
                if (ds->move_distance > 0) {
                    ds->wu.routine_no[2] = 99;
                }
            } else if (ds->move_distance < 0) {
                ds->wu.routine_no[2] = 99;
            }
        }
    }
    ds->wu.routine_no[2] = change_damage_attribute(as, as->wu.at_attribute, ds->wu.routine_no[2]);
}



void set_guard_status(PLW* as, PLW* ds) {
    if (as->wu.att.hs_you == 0 && as->wu.att.hs_me == 0) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        ds->wu.routine_no[1] = 1;
        ds->wu.routine_no[3] = 0;
        effect_02_init(&as->wu, ds->dm_point, 2, ds->wu.dm_rl);
        dm_status_copy(&as->wu, &ds->wu);
        same_dm_stop(&as->wu, &ds->wu);
        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }
        ds->wu.dm_piyo = 0;
        as->wu.cmwk[8]++;
        add_sp_arts_gauge_guard(as);
        ds->wu.dm_arts_point = 0;
        grade_add_guard_success(ds->wu.id);
    }
    hit_pattern_extdat_check(&as->wu);
}



/* provisional name */
void set_blocking_status(PLW* as, PLW* ds) {
    s16 hsadix;
    if ((as->wu.att.hs_you == 0) && (as->wu.att.hs_me == 0)) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        hsadix = 4;
        if ((as->wu.kind_of_waza & 0xF8) == 0) {
            hsadix = (as->wu.kind_of_waza / 2) & 3;
        }
        ds->wu.routine_no[1] = 0;
        ds->wu.routine_no[3] = 0;
        waza_slot_clear_all_p(ds);
        dm_status_copy(&as->wu, &ds->wu);
        ds->wu.dm_piyo = 0;
        ds->wu.cg_type = 0;
        switch ((ds->wu.routine_no[2] - 31) * 2 + (as->wu.xyz[1].disp.pos > 0)) {
        case 0:
        case 2:
        case 4:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = sel_hs_add_tbl[hsadix] + 16;
            as->wu.hit_quake = sel_hs_add_tbl[hsadix] + 16;
            break;
        case 1:
        case 3:
        case 5:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 6:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 7:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 8:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        case 9:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;
        default:
            ds->wu.dm_stop = 0;
            as->wu.hit_stop = 0;
            as->wu.hit_quake = 0;
            break;
        }
        ds->wu.dm_quake = 0;
        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }
        ds->wu.dm_arts_point = 0;
        if (as->wu.pat_status >= 0xE && as->wu.pat_status <= 0x1E && as->wu.work_id == 1 &&
            sel_sp_ch_tbl[as->wu.kind_of_waza >> 3] == 0) {
            remake_mvxy_PoGR(&as->wu);
        }
        if (Bonus_Game_Flag == 0) {
            paring_bonus_r[ds->wu.id] = 1;
            paring_ctr_vs[Play_Type][ds->wu.id]++;
            if (paring_ctr_vs[Play_Type][ds->wu.id] > 39) {
                paring_ctr_vs[Play_Type][ds->wu.id] = 39;
            }
            paring_counter[ds->wu.id] = parisucc_pts[Play_Type][paring_ctr_vs[Play_Type][ds->wu.id] - 1];
        }
        as->wu.cmwk[8]++;
    }
    hit_pattern_extdat_check(&as->wu);
}



s32 check_normal_attack(u8 waza) {
    return sel_sp_ch_tbl[waza >> 3] == 0;
}



void hit_pattern_extdat_check(WORK* as) {
    switch ((as->cg_extdat & 0xC0) + ((as->cg_extdat & 0x3F) != 0)) {
    case 0x80:
        char_move_z(as);
        break;
    case 0x40:
        as->cg_ctr = 1;
        break;
    case 0x81:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        char_move_z(as);
        break;
    case 0x41:
        as->cg_ctr = 1;
    case 0x1:
        setup_comm_abbak(as);
        as->cg_ix = ((as->cg_extdat & 0x3F) - 1) * as->cgd_type - as->cgd_type;
        as->cg_next_ix = 0;
        break;
    }
}



s32 check_dm_att_guard(WORK* as, WORK* ds) {
    s16 rnum;
    rnum = 0;
    if (as->kezuri_pow) {
        if (ds->dm_vital != 0) {
            ds->dm_vital = ds->dm_vital / as->kezuri_pow;
            if (ds->dm_vital == 0) {
                ds->dm_vital = 1;
            }
            if (ds->dm_vital > ds->vital_new) {
                if (as->no_death_attack) {
                    ds->dm_vital = ds->vital_new;
                } else {
                    ds->dm_guard_success = ds->routine_no[2];
                    rnum = 1;
                }
            }
        }
    } else {
        ds->dm_vital = 0;
    }
    return rnum;
}



s32 check_dm_att_blocking(WORK* as, WORK* ds, s16 dnum) {
    s16 rnum = 0;
    TAMA* tama = (TAMA*)as->my_effadrs;
    if (as->work_id == 4 && as->id == 13 && tama->kz_blocking != 0 && as->kezuri_pow) {
        if (ds->dm_vital != 0) {
            ds->dm_vital = ds->dm_vital / as->kezuri_pow;
            if (ds->dm_vital == 0) {
                ds->dm_vital = 1;
            }
            if (ds->dm_vital > ds->vital_new) {
                if (as->no_death_attack) {
                    ds->dm_vital = ds->vital_new;
                } else {
                    ds->dm_guard_success = dnum;
                    rnum = 1;
                }
            }
        }
    } else {
        ds->dm_vital = 0;
    }
    return rnum;
}



void set_damage_and_piyo(PLW* as, PLW* ds) {
    s32 v;
    cal_damage_vitality(as, ds);
    ds->wu.dm_piyo = add_piyo_gauge[as->player_number][as->wu.att.piyo];
    if ((ds->wu.pat_status == 32 || ds->wu.pat_status == 3) || ds->wu.pat_status == 25) {
        v = ds->wu.dm_vital;
        ds->wu.dm_vital = v * 125 / 100;
    } else if (ds->wu.pat_status == 7 || ds->wu.pat_status == 23 || ds->wu.pat_status == 35) {
        v = ds->wu.dm_vital;
        ds->wu.dm_vital = v * 150 / 100;
    } else if (ds->wu.pat_status == 1 || ds->wu.pat_status == 21 || ds->wu.pat_status == 37) {
        ds->wu.dm_vital *= 2;
    }
    if (ds->wu.dm_vital) {
        if (as->wu.routine_no[1] == 2) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->tk_nage + 32) / 32;
            if ((as->tk_nage -= 2) < 0) {
                as->tk_nage = 0;
            }
        }
        if (as->wu.routine_no[1] == 4) {
            ds->wu.dm_vital = ds->wu.dm_vital * (as->tk_dageki + 32) / 32;
            if ((as->tk_dageki -= 2) < 0) {
                as->tk_dageki = 0;
            }
        }
        ds->utk_nage = as->tk_nage;
        ds->utk_dageki = as->tk_dageki;
    }
    if (ds->wu.dm_piyo) {
        ds->wu.dm_piyo = ds->wu.dm_piyo * (as->tk_kizetsu + 32) / 32;
        if ((as->tk_kizetsu -= 2) < 0) {
            as->tk_kizetsu = 0;
        }
        ds->utk_kizetsu = as->tk_kizetsu;
    }
    as->wu.at_ten_ix = remake_score_index(ds->wu.dm_vital);
    cal_combo_waribiki(as, ds);
    cal_dm_vital_gauge_hosei(ds);
    cal_combo_waribiki2(ds);
    if (as->wu.work_id != 1) {
        return;
    }
    switch (as->dm_vital_use) {
    case 1:
        ds->wu.dm_vital += as->dm_vital_backup;
        as->dm_vital_backup = 0;
        break;
    case 2:
        as->dm_vital_backup /= 2;
        ds->wu.dm_vital += as->dm_vital_backup;
        break;
    }
}



s16 remake_score_index(s16 dmv) {
    s16 i;
    for (i = 0; i < 16; i++) {
        if (dmv < rsix_r_table[i][0]) {
            break;
        }
    }
    return rsix_r_table[i][1];
}



void same_dm_stop(WORK* as, WORK* ds) {
    if (as->work_id == 1 && as->att.dipsw & 1 && (ds->xyz[1].disp.pos > 0 || (ds->vital_new - ds->dm_vital) <= -3)) {
        switch ((ds->dm_stop < 0) + ((as->att.hs_me < 0) * 2)) {
        case 1:
            ds->dm_stop = -as->att.hs_me;
        case 2:
            ds->dm_stop = -as->att.hs_me;
            break;
        default:
            ds->dm_stop = as->att.hs_me;
            break;
        }
    }
}



s32 defense_sky(PLW* as, PLW* ds, s8 gddir) {
    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 4) {
        if (ds->spmv_ng_flag & 0x400 || ds->cp->waza_flag[5] == 0) {
            goto low;
        }
        blocking_point_count_up(ds);
        as->wu.hf.hit.player = 0x80;
        ds->wu.routine_no[2] = 0x22;
        if (check_dm_att_blocking(&as->wu, &ds->wu, 7)) {
            return 2;
        }
        return 0;
    low:
        if (ds->spmv_ng_flag & 0x800 || ds->cp->waza_flag[6] == 0) {
            goto guard;
        }
        blocking_point_count_up(ds);
        as->wu.hf.hit.player = 0x80;
        ds->wu.routine_no[2] = 0x23;
        if (check_dm_att_blocking(&as->wu, &ds->wu, 7)) {
            return 2;
        }
        return 0;
    }
guard:
    if (!(as->wu.att.guard & 32)) {
        return 2;
    }
    if (ds->guard_flag & 1) {
        goto miss;
    }
    if (ds->spmv_ng_flag & 32) {
        goto miss;
    }
    if (ds->saishin_lvdir & gddir) {
        as->wu.hf.hit.player = 0x20;
        ds->wu.routine_no[2] = 7;
        if (check_dm_att_guard(&as->wu, &ds->wu)) {
            return 2;
        }
        return 1;
    }
miss:
    return 2;
}



void blocking_point_count_up(PLW* wk) {
    s16 v;
    wk->kind_of_blocking = 0;
    if (wk->wu.routine_no[1] == 0) {
        if ((v = wk->wu.routine_no[2]) > 30 && v < 36) {
            wk->kind_of_blocking = 1;
        }
    }
    if (wk->wu.routine_no[1] == 1) {
        if ((v = wk->wu.routine_no[2]) > 3 && v < 8) {
            wk->kind_of_blocking = 2;
        }
    }
    grade_add_blocking(wk);
}



/* provisional name */
s32 check_normal_waza(u8 waza) {
    return sel_sp_ch_tbl[waza >> 3] == 0;
}



s32 defense_ground(PLW* as, PLW* ds, s8 gddir) {
    s8 just_now;
    s8 attr_att;
    just_now = 0;
    if (ds->guard_chuu != 0 && ds->guard_chuu < 5) {
        just_now = 1;
        attr_att = check_normal_waza(as->wu.kind_of_waza);
    }
    if (ds->py->flag == 0 && !(ds->guard_flag & 2) && as->wu.att.guard & 3) {
        if (as->wu.att.guard & 2 && !(ds->spmv_ng_flag & 0x100)) {
            if (just_now) {
                if (ds->cp->waza_flag[3] >= blocking_term_tbl[attr_att][0]) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;
                    if (check_attbox_dir(ds) == 0) {
                        ds->wu.routine_no[2] = 31;
                    } else {
                        ds->wu.routine_no[2] = 32;
                    }
                    return check_dm_att_blocking(&as->wu, &ds->wu, 5) ? 2 : 0;
                }
            } else if (as->wu.jump_att_flag) {
                if (ds->cp->waza_flag[12]) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;
                    if (check_attbox_dir(ds) == 0) {
                        ds->wu.routine_no[2] = 31;
                    } else {
                        ds->wu.routine_no[2] = 32;
                    }
                    return check_dm_att_blocking(&as->wu, &ds->wu, 5) ? 2 : 0;
                }
            } else if (ds->cp->waza_flag[3] != 0) {
                blocking_point_count_up(ds);
                as->wu.hf.hit.player = 64;
                if (check_attbox_dir(ds) == 0) {
                    ds->wu.routine_no[2] = 31;
                } else {
                    ds->wu.routine_no[2] = 32;
                }
                if (check_dm_att_blocking(&as->wu, &ds->wu, 5)) {
                    return 2;
                }
                return 0;
            }
        }
        if (as->wu.att.guard & 1 && !(ds->spmv_ng_flag & 0x200)) {
            if (just_now) {
                if (ds->cp->waza_flag[4] >= blocking_term_tbl[attr_att][1]) {
                    blocking_point_count_up(ds);
                    as->wu.hf.hit.player = 64;
                    ds->wu.routine_no[2] = 33;
                    if (check_dm_att_blocking(&as->wu, &ds->wu, 6)) {
                        return 2;
                    }
                    return 0;
                }
            } else if (ds->cp->waza_flag[4] != 0) {
                blocking_point_count_up(ds);
                as->wu.hf.hit.player = 64;
                ds->wu.routine_no[2] = 33;
                if (check_dm_att_blocking(&as->wu, &ds->wu, 6)) {
                    return 2;
                }
                return 0;
            }
        }
    }
    if (!(as->wu.att.guard & 0x18)) {
        return 2;
    }
    if (ds->guard_flag & 1) {
        return 2;
    }
    if (ds->spmv_ng_flag & 0x10) {
        return 2;
    }
    if (!ds->auto_guard) {
        if (!(ds->saishin_lvdir & gddir)) {
            return 2;
        }
        if (ds->cp->sw_lvbt & 1) {
            return 2;
        }
    }
    switch (as->wu.att.guard & 0x18) {
    case 8:
        if (!(ds->cp->sw_lvbt & 2)) {
            return 2;
        }
        ds->wu.routine_no[2] = 6;
        break;
    case 16:
        if (ds->cp->sw_lvbt & 2) {
            return 2;
        }
        ds->wu.routine_no[2] = 5;
        break;
    default:
        if (ds->cp->sw_lvbt & 2) {
            ds->wu.routine_no[2] = 6;
        } else {
            ds->wu.routine_no[2] = 5;
        }
        break;
    }
    as->wu.hf.hit.player = 16;
    if (ds->wu.routine_no[2] == 5 && check_attbox_dir(ds) == 0) {
        ds->wu.routine_no[2] = 4;
    }
    if (check_dm_att_guard(&as->wu, &ds->wu)) {
        return 2;
    }
    return 1;
}



void setup_dm_rl(WORK* as, WORK* ds) {
    s16 dx;
    XY* pd;
    XY* pf;
    if (as->work_id != 1 || check_aiuchi_pat(as->att.reaction) != 0) {
        ds->dm_rl = as->rl_flag;
        return;
    }
    dx = (pd = &ds->xyz[0])->disp.pos - (pf = &as->xyz[0])->disp.pos;
    switch ((pd[1].disp.pos > 0) + (pf[1].disp.pos > 0) * 2) {
    case 0:
    case 2:
        if (!(as->att.dipsw & 0x60)) {
            ds->dm_rl = as->rl_flag;
            break;
        }
    default:
        if (dx) {
            if (dx > 0) {
                ds->dm_rl = 1;
            } else {
                ds->dm_rl = 0;
            }
        } else {
            ds->dm_rl = as->rl_flag;
        }
    }
}



void dm_status_copy(WORK* as, WORK* ds) {
    ds->dm_attlv = as->att.level;
    ds->dm_impact = as->att.impact;
    ds->dm_dir = as->dir_atthit;
    ds->dm_stop = as->att.hs_you;
    ds->dm_quake = as->att.hs_you;
    if (ds->dm_quake < 0) {
        ds->dm_quake = -ds->dm_quake;
    }
    ds->dm_weight = as->weight_level;
    ds->dm_butt_type = as->att.but_ix;
    ds->dm_zuru = as->att_zuru;
    ds->dm_attribute = as->at_attribute;
    ds->dm_ten_ix = as->at_ten_ix;
    ds->dm_koa = as->at_koa;
    ds->hm_dm_side = as->att.dmg_mark;
    ds->dm_work_id = as->work_id;
    as->hit_stop = as->att.hs_me;
    ds->dm_arts_point = as->add_arts_point;
    ds->dm_kind_of_waza = as->kind_of_waza;
    ds->dm_nodeathattack = as->no_death_attack;
    ds->dm_jump_att_flag = as->jump_att_flag;
    if (as->work_id == 1) {
        ds->dm_exdm_ix = ((PLW*)as)->exdm_ix;
        ds->dm_plnum = ((PLW*)as)->player_number;
    } else {
        ds->dm_plnum = ((PLW*)((WORK_Other*)as)->my_master)->player_number;
    }
    as->meoshi_hit_flag = 1;
}



void add_combo_work(PLW* as, PLW* ds) {
    s16* r;
    s16* c;
    if (ds->kezurijini_flag) {
        return;
    }
    ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
    c = &ds->cb->kind_of[0][0][0];
    r = (s16*)((u8*)calc_hit + (s8)(ds->wu.id * 20));
    c[as->wu.kind_of_waza]++;
    r[(as->wu.kind_of_waza & 0x78) / 8]++;
    ds->cb->total++;
    c = &ds->rp->kind_of[0][0][0];
    c[as->wu.kind_of_waza]++;
    ds->rp->total++;
}



void nise_combo_work(PLW* as, PLW* ds, s16 num) {
    s16* kow;
    s16* cal;
    s16 i;
    for (i = 0; i < num; i++) {
        ds->kizetsu_kow = ds->cb->new_dm = as->wu.kind_of_waza;
        kow = &ds->cb->kind_of[0][0][0];
        cal = &calc_hit[ds->wu.id][0];
        kow[as->wu.kind_of_waza]++;
        cal[(as->wu.kind_of_waza & 120) / 8]++;
        ds->cb->total++;
        kow = &ds->rp->kind_of[0][0][0];
        kow[as->wu.kind_of_waza]++;
        ds->rp->total++;
    }
}



void cal_combo_waribiki(PLW* as, PLW* ds) {
    POWER* power;
    KOATT* koatt;
    s16 i;
    s16 j;
    s16 k;
    TBL tbl;
    if (ds->wu.dm_vital == 0) {
        return;
    }
    if (ds->rp->total == 0) {
        return;
    }
    koatt = (KOATT*)exchange_koa[(as->wu.kind_of_waza) >> 1];
    tbl.ixl = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            k = ds->rp->kind_of[i][j][0] + ds->rp->kind_of[i][j][1];
            if (k != 0) {
                tbl.ixl += k * koatt->step[i][j] * 256;
            }
        }
    }
    if (tbl.ixs.l != 0) {
        tbl.ixs.h++;
    }
    power = (POWER*)exchange_pow[as->wu.kind_of_waza >> 1];
    if ((as->player_number == PL_YUN || as->player_number == PL_YANG) && (as->sa->kind_of_arts == 2 && as->sa->ok == -1)) {
        power = (POWER*)exchange_pow_pl03_sa3[as->wu.kind_of_waza >> 1];
    }
    if (tbl.ixs.h > 31) {
        tbl.ixs.h = 31;
    }
    ds->wu.dm_vital *= power[0].data[tbl.ixs.h];
    ds->wu.dm_vital >>= 5;
    if (ds->wu.dm_vital <= 0) {
        ds->wu.dm_vital = 1;
    }
}



void cal_combo_waribiki2(PLW* ds) {
    s16 num;
    if (ds->wu.dm_piyo == 0) {
        return;
    }
    if (ds->cb->total == 0) {
        return;
    }
    num = 32 - (ds->cb->total * 2);
    if (num <= 0) {
        num = 1;
    }
    ds->wu.dm_piyo = (ds->wu.dm_piyo * num) / 32;
    if (ds->wu.dm_piyo == 0) {
        ds->wu.dm_piyo = 1;
    }
}



void catch_hit_check(void) {
    WORK* mad;
    WORK* sad;
    s16* mh;
    s16* sh;
    s16 mi;
    s16 si;
    for (mi = 0; mi < hpq_in; mi++) {
        if (hs[mi].flag.results & 0x1000) {
            continue;
        }
        mad = q_hit_push[mi];
        if (mad->work_id != 1) {
            continue;
        }
        if (mad->att_hit_ok == 0) {
            continue;
        }
        mh = &mad->h_cat->cat_box[0];
        if (mh[1] == 0) {
            continue;
        }
        for (si = 0; si < hpq_in; si++) {
            if (si == mi) {
                continue;
            }
            if (hs[si].flag.results & 0x100) {
                continue;
            }
            sad = q_hit_push[si];
            if (sad->work_id != 1) {
                continue;
            }
            sh = &sad->h_cau->cau_box[0];
            if (sh[1] == 0) {
                continue;
            }
            if (!(mad->att.guard & 0x18)) {
                if (!((PLW*)sad)->tsukamarenai_flag) {
                    if (!(mad->att.dipsw & 0x60)) {
                        if ((sad->routine_no[1] == 1) && (sad->routine_no[3] != 0)) {
                            if (sad->routine_no[2] != 0x19) {
                                continue;
                            }
                        }
                    } else if ((sad->routine_no[1] == 1) && (sad->routine_no[3] != 0) && (sad->cg_type != 10)) {
                        if (!dm_oiuchi_catch[sad->routine_no[2]]) {
                            continue;
                        }
                    }
                } else {
                    continue;
                }
            }
            if (hit_check_subroutine(mad, sad, mh, sh)) {
                hs[mi].flag.results |= 0x1000;
                hs[mi].my_hit = (u16)si;
                hs[si].flag.results |= 0x100;
                hs[si].dm_me = (u16)mi;
                mad->att_hit_ok = 0;
                hs[mi].ah = mh;
                hs[si].dh = sh;
                mad->att_hit_ok = 0;
            } else {
                continue;
            }
            break;
        }
    }
}



void attack_hit_check(void) {
    WORK* mad;
    WORK* sad;
    s16* mh;
    s16* sh;
    s16 mi;
    s16 si;
    s16 lp;
    s16 lp2;
    s16 mw;
    s16* assign1;
    s16* assign2;
    for (si = 0; si < hpq_in; si++) {
        if (hs[si].flag.results & 0x1101) {
            continue;
        }
        sad = q_hit_push[si];
        sh = sad->h_bod->body_dm[0];
        mh = sad->h_han->hand_dm[0];
        for (lp = 0; lp < 4; lp++, sh += 4, assign1 = mh += 4) {
            dmdat_adrs[lp] = sh;
            dmdat_adrs[lp + 4] = mh;
        }
        dmdat_adrs[8] = &sad->h_att->att_box[2][0];
        dmdat_adrs[9] = &sad->h_att->att_box[3][0];
        dmdat_adrs[10] = &sad->h_hos->hos_box[0];
        for (mi = 0; mi < hpq_in; mi++) {
            if (mi == si) {
                continue;
            }
            if (hs[mi].flag.results & 0x1110) {
                continue;
            }
            mad = q_hit_push[mi];
            if (mad->cg_ja.atix == 0) {
                continue;
            }
            if (mad->att_hit_ok == 0) {
                continue;
            }
            if (!(mad->att.dipsw & 2) ||
                (!(sad->att.dipsw & 2) && (sad->work_id == 1 || !(((WORK_Other*)sad)->refrected)))) {
                if ((mad->work_id != 1 && mad->work_id != 8) || !(sad->att.dipsw & 2)) {
                    if (!(mad->vs_id & sad->work_id)) {
                        continue;
                    }
                }
            }
            if (mad->work_id != 1) {
                if (sad->work_id == 1) {
                    if (((WORK_Other*)mad)->master_id == sad->id) {
                        continue;
                    }
                } else if (((WORK_Other*)mad)->master_id == ((WORK_Other*)sad)->master_id) {
                    continue;
                }
            } else if ((sad->work_id != 1 && ((WORK_Other*)sad)->refrected == 0) &&
                       (mad->id == ((WORK_Other*)sad)->master_id)) {
                continue;
            }
            mh = &mad->h_att->att_box[0][0];
            for (lp = 0; lp < 4; lp++, assign2 = mh += 4) {
                if (mh[1] == 0) {
                    continue;
                }
                for (lp2 = 0; lp2 < 11; lp2++) {
                    if (lp2 > 3 && mad->att_hit_ok == 0) {
                        goto end;
                    }
                    if (dmdat_adrs[lp2][1] == 0) {
                        continue;
                    }
                    if ((lp == 2 || lp == 3) && (lp2 == 8 || lp2 == 9)) {
                        continue;
                    }
                    if ((lp2 > 3) && (lp2 < 0xA)) {
                        if (!(((mad->rl_flag) + (sad->rl_flag)) & 1)) {
                            if (mad->rl_flag) {
                                if (!(mad->xyz[0].disp.pos <= sad->xyz[0].disp.pos)) {
                                    continue;
                                }
                            } else if (!(mad->xyz[0].disp.pos >= sad->xyz[0].disp.pos)) {
                                continue;
                            }
                        }
                        if (mad->att.dipsw & 4 && (lp2 >= 8 || sad->cg_ja.bhix == 0)) {
                            continue;
                        }
                    }
                    if (lp2 == 10) {
                        if (!(mad->att.dipsw & 64) || sad->kind_of_waza & 0x60 || pcon_dp_flag ||
                            sad->pat_status == 0x26) {
                            continue;
                        }
                    }
                    mw = hit_check_subroutine(mad, sad, mh, dmdat_adrs[lp2]);
                    if (mw > mkm_wk[si]) {
                        hs[mi].flag.results |= 0x10;
                        hs[mi].my_hit = si;
                        hs[mi].my_att = lp;
                        hs[si].flag.results |= 1;
                        hs[si].dm_me = mi;
                        hs[si].dm_body = lp2;
                        mad->att_hit_ok = 0;
                        mkm_wk[si] = mw;
                        hs[mi].ah = mh;
                        hs[si].dh = dmdat_adrs[lp2];
                    }
                }
            }
        }
    end:
        continue;
    }
}



s32 hit_check_subroutine(WORK* wk1, WORK* wk2, const s16* hd1, const s16* hd2) {
    s16 d0;
    s16 d1;
    s16 d2;
    s16 d3;
    d0 = *hd1++;
    d1 = *hd1++;
    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += wk1->xyz[0].disp.pos;
    d2 = *hd2++;
    d3 = *hd2++;
    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += wk2->xyz[0].disp.pos;
    d2 += d3 - d0;
    d3 += d1;
    if ((u32)d2 >= d3) {
        return 0;
    }
    d0 = (wk1->xyz[1].disp.pos + *hd1++) - (wk2->xyz[1].disp.pos + *hd2++);
    d0 += d1 = *hd1;
    d1 += *hd2;
    if ((u32)d0 >= d1) {
        return 0;
    }
    if (d2 > (d3 - d2)) {
        d2 = d3 - d2;
    }
    return d2;
}



s32 hit_check_x_only(WORK* wk1, WORK* wk2, s16* hd1, s16* hd2) {
    s16 d0;
    s16 d1;
    s16 d2;
    s16 d3;
    d0 = *hd1++;
    d1 = *hd1++;
    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += wk1->xyz[0].disp.pos;
    d2 = *hd2++;
    d3 = *hd2++;
    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += wk2->xyz[0].disp.pos;
    d2 += d3 - d0;
    d3 += d1;
    if ((u32)d2 >= d3) {
        return 0;
    }
    return 1;
}



void cal_hit_mark_position(WORK* wk1, WORK* wk2, s16* hd1, s16* hd2) {
    s16 d0 = *hd1++;
    s16 d1 = *hd1++;
    s16 d2;
    s16 d3;
    if (wk1->rl_flag) {
        d0 = -d0;
        d0 -= d1;
    }
    d0 += wk1->xyz[0].disp.pos;
    d1 += d0;
    d2 = *hd2++;
    d3 = *hd2++;
    if (wk2->rl_flag) {
        d2 = -d2;
        d2 -= d3;
    }
    d2 += wk2->xyz[0].disp.pos;
    d3 += d2;
    if (d0 < d2) {
        d0 = d2;
    }
    if (d1 > d3) {
        d1 = d3;
    }
    wk2->hit_mark_x = (d0 + d1) >> 1;
    d0 = wk1->xyz[1].disp.pos + *hd1++;
    d1 = *hd1 + d0;
    d2 = wk2->xyz[1].disp.pos + *hd2++;
    d3 = *hd2 + d2;
    if (d0 < d2) {
        d0 = d2;
    }
    if (d1 > d3) {
        d1 = d3;
    }
    wk2->hit_mark_y = (d0 + d1) >> 1;
}



void get_target_att_position(WORK* wk, s16* tx, s16* ty) {
    s16 i;
    s16* ta;
    *tx = wk->xyz[0].disp.pos;
    *ty = wk->xyz[1].disp.pos;
    ta = wk->h_att->att_box[0];
    for (i = 0; i < 3; ta += 4, i++) {
        if (ta[0]) {
            if (wk->rl_flag) {
                *tx -= ta[0] + (ta[1] / 2);
            } else {
                *tx += ta[0] + (ta[1] / 2);
            }
            *ty += ta[2] + (ta[3] / 2);
            break;
        }
    }
}



s32 get_att_head_position(WORK* wk) {
    s16 v = wk->xyz[0].disp.pos;
    s32 b = v;
    s16 i;
    s16* p;
    if (wk->cg_ja.atix == 0) {
        return b;
    }
    p = &wk->h_att->att_box[0][0];
    for (i = 0; i < 3; i++, p += 4) {
        if (*p) {
            if (wk->rl_flag) {
                s16 t = v - *p;
                if (b < t) {
                    v = t;
                }
            } else {
                s16 t = *p + v;
                if (b > t) {
                    v = t;
                }
            }
            break;
        }
    }
    return v;
}



void hit_push_request(WORK* hpr_wk) {
    if (hpq_in < 31 && hpr_wk->cg_hit_ix != 0) {
        q_hit_push[hpq_in++] = hpr_wk;
    }
}



void clear_hit_queue(void) {
    s16 i;
    s16* p;
    WORK** q;
    hpq_in = 0;
    p = mkm_wk;
    i = 0;
    do {
        *p = 0;
        i += 2;
        p++;
        *p = 0;
        p++;
    } while (i < 0x20);
    q = q_hit_push;
    i = 0;
    do {
        *q = 0;
        i += 2;
        q++;
        *q = 0;
        q++;
    } while (i < 0x20);
    work_init_zero((s32*)hs, sizeof(hs));
}



s32 change_damage_attribute(PLW* as, u16 atr, u16 ix) {
    switch (atr) {
    case 1:
        if (as->wu.work_id == 1 && as->player_number == PL_GILL && as->wu.rl_flag) {
            ix = attr_freeze_tbl[ix - 32];
            as->wu.at_attribute = 3;
        } else {
            ix = attr_flame_tbl[ix - 32];
        }
        break;
    case 2:
        ix = attr_thunder_tbl[ix - 32];
        break;
    case 3:
        if (as->wu.work_id == 1 && as->player_number == PL_GILL && as->wu.rl_flag) {
            ix = attr_flame_tbl[ix - 32];
            as->wu.at_attribute = 1;
        } else {
            ix = attr_freeze_tbl[ix - 32];
        }
        break;
    }
    return ix;
}



s16 get_sky_nm_damage(u16 ix) {
    ix -= 32;
    return sky_nm_damage_tbl[ix];
}



/* provisional name: unreferenced */
s16 get_sky_nm2_damage(u16 ix) {
    ix -= 32;
    return sky_nm2_damage_tbl[ix];
}



s16 get_sky_sp_damage(u16 ix) {
    ix -= 32;
    return sky_sp_damage_tbl[ix];
}



s16 get_kagami_damage(u16 ix) {
    ix -= 32;
    return kagami_damage_tbl[ix];
}



/* provisional name: unreferenced */
s16 get_kagami2_damage(u16 ix) {
    ix -= 32;
    return kagami2_damage_tbl[ix];
}



s16 get_grd_hand_damage(u16 ix) {
    ix -= 32;
    return grd_hand_damage_tbl[ix];
}



s32 check_head_damage(s16 ix) {
    ix -= 32;
    return hddm_damage_tbl[ix];
}



s32 check_trunk_damage(s16 ix) {
    ix -= 32;
    return trdm_damage_tbl[ix];
}



/* provisional name */
s32 check_aiuchi_pat(s16 pat) {
    pat -= 32;
    return check_aiuchi_pat_table1[pat];
}
