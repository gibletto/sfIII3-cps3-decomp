/*
 * EFF02.C  Effect 01 init and effect 02 (hit marks)
 *
 * effect_01_init creates an overlay-parts work for one of a character's parts slots and
 * records it in the master's olc_work_ix.
 * Effect 02 is the hit mark shown when an attack connects or is guarded. Its entry in the
 * hmdt table chooses the mark (guard and chip variants), colour, direction, position
 * offset, screen quake and hit sound (urian_guard_se_check). effect_02_init is called
 * from the hit-check modules (HITCHECK, HITEFEF, HITPLEF, PLPCA).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "CHARSET.h"
#include "EFF02.h"
#include "fighter.h"



s32 effect_01_init(WORK* wk, u8 koolc) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 1;
    ewk->wu.work_id = 32;
    ewk->wu.type = koolc;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.blink_timing = wk->blink_timing;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    wk->olc_work_ix[koolc] = ewk->wu.myself;
    return 0;
}



void effect_02_move(WORK_Other* ewk) {
    const HMDT* tad;
    const EXPLEM* edt;
    s32 index;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.char_table[0] = ef01_char_table;
        tad = &hmdt[ewk->wu.kohm];
        if (ewk->wu.vital_old == 2) {
            ewk->wu.kohm = tad->deff;
            if (ewk->wu.dm_vital != 0) {
                ewk->wu.kohm = tad->kezu;
            }
        }
        tad = &hmdt[ewk->wu.kohm];
        if (tad->hits == 0) {
            if (tad->se) {
                urian_guard_se_check(ewk, (PLW*)ewk->wu.target_adrs, tad->se);
            } else {
                Last_Called_SE = 0;
            }
            push_effect_work(&ewk->wu);
            return;
        }
        if (tad->status & 8) {
            ewk->wu.disp_flag = 2;
        } else {
            ewk->wu.disp_flag = 1;
        }
        if (tad->status & 0x40) {
            if (((PLW*)ewk->wu.target_adrs)->wu.work_id == 1) {
                ewk->wu.dir_timer = ((PLW*)ewk->wu.target_adrs)->player_number;
            } else {
                ewk->wu.dir_timer = ((WORK_Other*)ewk->wu.target_adrs)->master_player;
            }
        }
        if (tad->col) {
            ewk->wu.my_col_code = hcct[tad->col];
        } else if (tad->status & 0x80) {
            ewk->wu.my_col_code = ((PLW*)ewk->wu.target_adrs)->wu.my_col_code + 7;
        }
        if (tad->se) {
            urian_guard_se_check(ewk, (PLW*)ewk->wu.target_adrs, tad->se);
        } else {
            Last_Called_SE = 0;
        }
        if (tad->status & 4) {
            ewk->wu.rl_flag = ewk->wu.dm_rl;
        }
        if (tad->status & 0x10) {
            if (tad->status & 0x20) {
                edt = &explem2[tad->emhix][(u8)ewk->wu.dir_timer];
            } else {
                edt = &explem[tad->myhix];
            }
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= *(s16*)&edt->hx;
            } else {
                ewk->wu.xyz[0].disp.pos += *(s16*)&edt->hx;
            }
            ewk->wu.xyz[1].disp.pos += *(s16*)&edt->hy;
        } else {
            ewk->wu.xyz[0].disp.pos += ewk->wu.old_pos[0];
            ewk->wu.xyz[1].disp.pos += ewk->wu.old_pos[1];
        }
        if (ewk->wu.weight_level) {
            ewk->wu.xyz[0].disp.pos += ((PLW*)ewk->my_master)->muriyari_ugoku;
        }
        if (tad->status & 2) {
            ewk->wu.xyz[0].disp.pos += random_16_com() - 7;
            ewk->wu.xyz[1].disp.pos += (random_16_com() & 7) - 3;
        }
        ewk->wu.scr_mv_x = gqdt[tad->quake][0];
        ewk->wu.scr_mv_y = gqdt[tad->quake][1];
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        if (tad->status & 0x10) {
            index = edt->chix;
        } else {
            ewk->wu.dir_old = 0;
            if (tad->dir) {
                ewk->wu.dir_old = hit_mark_dir_table[ewk->wu.direction];
                if (ewk->wu.dir_old < 0) {
                    ewk->wu.rl_flag = 1;
                    ewk->wu.dir_old = -ewk->wu.dir_old;
                }
            }
            index = tad->hits + ewk->wu.dir_old;
        }
        set_char_move_init(&ewk->wu, 0, index);
        if (Pause_Hit_Marks) {
            break;
        }
        sort_push_request8(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (Pause_Hit_Marks) {
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }
            if (ewk->wu.scr_mv_x && --ewk->wu.scr_mv_x == 0) {
                bg_w.quake_y_index = ewk->wu.scr_mv_y;
            }
        }
        sort_push_request8(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void urian_guard_se_check(ewk, twk, oto)
WORK_Other* ewk;
PLW* twk;
u16 oto;
{
    u16 se = oto;
    if (twk->player_number == PL_URIEN && (se == 266 || se == 267)) {
        sound_effect_request[0x2F9](ewk, 0x2F9);
        Last_Called_SE = 0x2F9;
        return;
    }
    sound_effect_request[oto](ewk, se);
    Last_Called_SE = oto;
}



s32 effect_02_init(wk, dmgp, mkst, dmrl)
WORK* wk;
s8 dmgp;
s8 mkst;
s8 dmrl;
{
    WORK_Other* ewk;
    WORK_Other* dwk;
    s16 ix;
    if (Combo_Demo_Flag & 0x80) {
        return 0;
    }
    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 2;
    ewk->wu.work_id = 64;
    ewk->wu.vital_new = dmgp;
    ewk->wu.vital_old = mkst;
    ewk->wu.dm_rl = dmrl;
    ewk->wu.kohm = wk->att.hit_mark;
    ewk->wu.direction = wk->dir_atthit;
    ewk->wu.dm_vital = wk->kezuri_pow;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->wu.old_pos[0] = wk->hit_mark_x - wk->xyz[0].disp.pos;
    ewk->wu.old_pos[1] = wk->hit_mark_y - wk->xyz[1].disp.pos;
    ewk->wu.weight_level = 0;
    if (wk->work_id == 1) {
        ewk->my_master = (u32*)wk;
        ewk->master_id = wk->id;
        ewk->master_work_id = wk->work_id;
        ewk->wu.target_adrs = wk->target_adrs;
        ewk->wu.my_col_code = wk->my_col_code + 7;
        ewk->master_player = ewk->wu.dir_timer = ((PLW*)wk)->player_number;
        ewk->wu.weight_level = 1;
    } else {
        dwk = (WORK_Other*)wk;
        ewk->my_master = (u32*)dwk->my_master;
        ewk->master_id = dwk->master_id;
        ewk->master_work_id = dwk->master_work_id;
        ewk->wu.target_adrs = ((WORK*)dwk->my_master)->target_adrs;
        ewk->wu.my_col_code = ((WORK*)dwk->my_master)->my_col_code + 7;
        ewk->master_player = ewk->wu.dir_timer = dwk->master_player;
    }
    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}
