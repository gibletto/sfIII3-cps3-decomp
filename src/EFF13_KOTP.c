/*
 * EFF13_KOTP.C  Effect 13: projectile processes 14-16 and init
 *
 * kotp_14000 to kotp_16000 are further kind-of-tama processes of the projectile effect
 * (kotp_14000 animates, passes its hit flag to the master and ends with its animation).
 * effect_13_init creates a projectile for a player or effect: it registers it as the
 * owner's shell, copies facing, family, colour and weight, and records the owner's
 * player number and hit state. Called from the player pattern code (PLPAT09 and others).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "EFF13.h"
#include "EFF96.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFF13_KOTP.h"
#include "fighter.h"



void kotp_14000(WORK_Other* ewk) {
    char_move(&ewk->wu);
    if (ewk->wu.hf.hit_flag) {
        ((WORK*)ewk->my_master)->hf.hit_flag = ewk->wu.hf.hit_flag;
        ewk->wu.hf.hit_flag = 0;
    }
    if (ewk->wu.cg_type == 0xFF) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
    }
}



void kotp_15000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
            break;
        }
        if (--ewk->wu.dir_timer >= 0 && !tama15_screen_check(&ewk->wu)) {
            break;
        }
        ewk->wu.mvxy.a[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = 0;
        set_char_move_init(&ewk->wu, 0, twk->ernm);
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 256) {
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



void kotp_16000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            if (ewk->wu.hit_stop == 1) {
                ewk->wu.hit_stop = 0;
            } else {
                ewk->wu.hit_stop--;
                break;
            }
        } else {
            add_mvxy_speed(&ewk->wu);
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].cal += 0x38000;
            } else {
                ewk->wu.xyz[0].cal -= 0x38000;
            }
        }
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
            break;
        }
        if ((ewk->wu.xyz[1].disp.pos + ewk->wu.cg_jphos) <= 0) {
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, twk->erex);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.xyz[1].disp.pos = -ewk->wu.cg_jphos;
            break;
        }
        if (--ewk->wu.dir_timer >= 0 && !screen_range_check(&ewk->wu)) {
            break;
        }
        set_char_move_init(&ewk->wu, 0, twk->ernm);
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 256) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    effect_96_init(&ewk->wu, twk->erdf, ewk->wu.disp_flag, ewk->wu.hit_stop);
                } else {
                    effect_96_init(&ewk->wu, twk->erht, ewk->wu.disp_flag, ewk->wu.hit_stop);
                }
            } else {
                effect_96_init(&ewk->wu, twk->erex, ewk->wu.disp_flag, ewk->wu.hit_stop);
            }
            if (ewk->dm_refrect) {
                ewk->master_id = (ewk->master_id + 1) & 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->dm_refrect = 0;
            }
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



s32 effect_13_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    write_my_shell_ix(wk, ix);
    if (wk->work_id == 1 && wk->rl_flag == 1 && ((PLW*)wk)->player_number == PL_GILL) {
        data++;
    }
    ewk->wu.be_flag = 1;
    ewk->wu.id = 13;
    ewk->wu.type = data;
    ewk->wu.operator = wk->operator;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.spr.gfx_cells = wk->my_col_code;
    ewk->wu.weight_level = wk->weight_level;
    ewk->wu.rl_waza = Round_num;
    ewk->my_master = (u32*)wk;
    if (wk->work_id == 1) {
        ewk->master_player = ((PLW*)wk)->player_number;
        ewk->master_id = wk->id;
        ewk->master_work_id = wk->work_id;
        ewk->wu.olc_work_ix[0] = ((PLW*)wk)->tk_dageki;
        ewk->wu.olc_work_ix[1] = ((PLW*)wk)->tk_nage;
        ewk->wu.olc_work_ix[2] = ((PLW*)wk)->tk_kizetsu;
        ewk->wu.olc_work_ix[3] = wk->routine_no[1];
    } else {
        ewk->master_player = ((WORK_Other*)wk)->master_player;
        ewk->master_id = ((WORK_Other*)wk)->master_id;
        ewk->master_work_id = ((WORK_Other*)wk)->master_work_id;
    }
    ewk->wu.xyz[0] = wk->xyz[0];
    ewk->wu.xyz[1] = wk->xyz[1];
    ewk->wu.my_effadrs = (u32*)&tama_data[data];
    if (wk->work_id == 1) {
        ewk->wu.spr.floor = ((PLW*)wk)->metamorphose;
    }
    return 0;
}
