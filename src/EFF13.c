/*
 * EFF13.C  Effect 13: projectiles (shells) - main routine and first processes
 *
 * Effect 13 is the projectile work fired by characters. effect_13_move loads its TAMA
 * parameters (life time, attack kind, defence power, colour, kind_of_tama), handles hit
 * results and runs the kind-of-tama process kotp_00000 to kotp_05000 (normal flight and hit
 * handling, special shells such as the tengu stones that attack and return).
 * Helper routines check screen ranges, aim at the target and relaunch shells.
 * The remaining processes and effect_13_init are in EFF13_KOTP.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFF96.h"
#include "EFFECT.h"
#include "bg_sub.h"
#include "HITCHECK.h"
#include "Grade.h"
#include "CHARID.h"
#include "CHARSET.h"
#include "PLSGAUGE.h"
#include "PLCNTSET.h"
#include "EFF13.h"



void effect_13_move(WORK_Other* ewk) {
    TAMA* tama = (TAMA*)ewk->wu.my_effadrs;
    PLW* mwk;
    PLW* emwk;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 11;
        set_char_base_data(&ewk->wu);
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.work_id = tama->my_wkid;
        ewk->wu.dir_timer = tama->life_time;
        ewk->wu.disp_flag = tama->disp_type;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.at_koa = tama->koa;
        ewk->wu.vital_new = tama->def_power;
        ewk->wu.dm_vital = 0;
        ewk->wu.original_vitality = tama->waza_num;
        ewk->wu.shell_vs_refrect = tama->vs_refrect;
        ewk->wu.charset_id = tama->kind_of_tama;
        if (ewk->master_id) {
            if (tama->col_2p == 0) {
                ewk->wu.my_col_code = ewk->wu.spr.gfx_cells;
            } else {
                ewk->wu.my_col_code = tcct[tama->col_2p];
            }
        } else if (tama->col_1p == 0) {
            ewk->wu.my_col_code = ewk->wu.spr.gfx_cells;
        } else {
            ewk->wu.my_col_code = tcct[tama->col_1p];
        }
        if (tama->kage_index) {
            ewk->wu.kage_flag = 1;
            ewk->wu.kage_hx = kage_tbl[tama->kage_index][0];
            ewk->wu.kage_hy = kage_tbl[tama->kage_index][1];
            ewk->wu.kage_prio = kage_tbl[tama->kage_index][2];
            ewk->wu.kage_char = kage_tbl[tama->kage_index][3];
        } else {
            ewk->wu.kage_flag = 0;
        }
        if (tama->kind_of_tama == 2) {
            set_tengu_init_pos(ewk, (WORK*)ewk->my_master);
            ewk->wu.disp_flag = 0;
            ewk->wu.dir_old = ((PLW*)ewk->my_master)->sa->id_arts;
            set_char_move_init2(&ewk->wu, 0, tama->chix, random_16_com() & 7, 0);
        } else if (tama->kind_of_tama == 0xF) {
            mwk = (PLW*)ewk->my_master;
            if (tama->data01) {
                ewk->wu.mvxy.a[0].sp = mwk->wu.mvxy.a[0].sp;
                ewk->wu.mvxy.a[1].sp = mwk->wu.mvxy.a[1].sp ? mwk->wu.mvxy.a[1].sp : -0x80000;
                ewk->wu.mvxy.d[0].sp = mwk->wu.mvxy.d[0].sp;
                ewk->wu.mvxy.d[1].sp = mwk->wu.mvxy.d[1].sp;
                ewk->wu.mvxy.kop[1] = 0;
            } else {
                emwk = (PLW*)mwk->wu.target_adrs;
                ewk->wu.xyz[0].disp.pos = tama->hos_x;
                ewk->wu.xyz[0].disp.pos += emwk->wu.xyz[0].disp.pos;
                ewk->wu.xyz[0].disp.pos += X_F_L_A_T_pos_hos[0][emwk->player_number][0];
                ewk->wu.xyz[1].disp.pos = tama->hos_y;
                ewk->wu.xyz[1].disp.pos += emwk->wu.xyz[1].disp.pos;
                ewk->wu.xyz[1].disp.pos += X_F_L_A_T_pos_hos[0][emwk->player_number][1];
                ewk->wu.rl_flag = ewk->wu.xyz[0].disp.pos > emwk->wu.xyz[0].disp.pos ? 0 : 1;
                setup_mvxy_data(&ewk->wu, tama->data00);
            }
            set_char_move_init(&ewk->wu, 0, tama->chix);
        } else {
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= tama->hos_x;
            } else {
                ewk->wu.xyz[0].disp.pos += tama->hos_x;
            }
            ewk->wu.xyz[1].disp.pos += tama->hos_y;
            ewk->wu.position_z = ewk->wu.my_priority;
            if (tama->kind_of_tama == 7) {
                ewk->wu.position_z += 2;
            }
            setup_mvxy_data(&ewk->wu, tama->data00);
            set_char_move_init(&ewk->wu, 0, tama->chix);
        }
        if (tama->kind_of_tama == 11) {
            ewk->wu.next_z = 70;
        }
        if (tama->kind_of_tama == 10) {
            ewk->wu.rl_flag = ((WORK*)ewk->my_master)->rl_waza;
        }
        tama_display(ewk);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.hit_stop = -ewk->wu.hit_stop;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            kind_of_tama_process[tama->kind_of_tama](ewk, tama);
        }
        tama_display(ewk);
        if (ewk->wu.spr.floor) {
            ewk->wu.kind_of_waza |= 0x20;
            ewk->wu.at_koa = 0x80;
        }
        hit_push_request(&ewk->wu);
        break;
    case 2:
        erase_my_shell_ix((WORK*)ewk->my_master, ewk->wu.myself);
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void tama_display(WORK_Other* ewk) {
    set_quake((PLW*)ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + ewk->wu.next_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request(ewk);
}



s32 screen_x_range_check(WORK* wk) {
    s16 scpx = get_center_position();
    s16 scpxr = scpx + 256;
    s16 scpxl = scpx - 256;
    scpx = wk->xyz[0].disp.pos;
    if (scpxl < 0) {
        scpxr -= scpxl;
        scpx -= scpxl;
        scpxl = 0;
    }
    if (scpx > scpxr || scpx < scpxl) {
        return 1;
    }
    return 0;
}



s32 screen_range_check(WORK* wk) {
    s16 scpx = get_center_position();
    s16 scpxr = scpx + 256;
    s16 scpxl = scpx - 256;
    s16 scpy;
    s16 scpyu;
    scpx = wk->xyz[0].disp.pos;
    if (scpxl < 0) {
        scpxr -= scpxl;
        scpx -= scpxl;
        scpxl = 0;
    }
    if (scpx > scpxr || scpx < scpxl) {
        return 1;
    }
    scpy = get_height_position();
    scpyu = scpy + 288;
    scpy = wk->xyz[1].disp.pos;
    if (scpy > scpyu) {
        return 1;
    }
    return 0;
}



s32 tama15_screen_check(WORK* wk) {
    s16 scpx = get_center_position();
    s16 scpxr = scpx + 512;
    s16 scpxl = scpx - 512;
    s16 scpy;
    s16 scpyu;
    s16 scpyd;
    scpx = wk->xyz[0].disp.pos;
    if (scpxl < 0) {
        scpxr -= scpxl;
        scpx -= scpxl;
        scpxl = 0;
    }
    if (scpx > scpxr || scpx < scpxl) {
        return 1;
    }
    scpy = get_height_position();
    scpyu = scpy + 512;
    scpyd = scpy - 288;
    scpy = wk->xyz[1].disp.pos;
    if (scpyd < 0) {
        scpyu -= scpyd;
        scpy -= scpyd;
        scpyd = 0;
    }
    if (scpy > scpyu || scpy < scpyd) {
        return 1;
    }
    return 0;
}



void set_tengu_init_pos(WORK_Other* ewk, WORK* twk) {
    s16 scpx;
    scpx = get_center_position();
    if (twk->rl_flag) {
        scpx -= 320;
    } else {
        scpx += 320;
    }
    ewk->wu.xyz[0].disp.pos = scpx;
    ewk->wu.xyz[1].disp.pos = ewk->wu.direction;
}



void kotp_00000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            if (ewk->wu.hit_stop == 1) {
                ewk->wu.hit_stop = 0;
                add_mvxy_speed_exp(&ewk->wu, 2);
            } else {
                ewk->wu.hit_stop--;
                break;
            }
        } else {
            add_mvxy_speed(&ewk->wu);
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
        if (--ewk->wu.dir_timer >= 0 && screen_range_check(&ewk->wu) == 0) {
            break;
        }
        ewk->wu.mvxy.a[0].sp /= 4;
        ewk->wu.mvxy.a[1].sp /= 4;
        set_char_move_init(&ewk->wu, 0, twk->ernm);
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 0x100) {
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



void kotp_01000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
            break;
        }
        if (screen_range_check(&ewk->wu)) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.disp_flag = 0;
        }
        break;
    case 1:
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
        ewk->wu.routine_no[2] = 0;
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.disp_flag = 0;
        }
        break;
    }
}



void kotp_02000(WORK_Other* ewk, TAMA* twk) {
    PLW* mwk = (PLW*)ewk->my_master;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        char_move(&ewk->wu);
        switch (ewk->wu.routine_no[2]) {
        case 0:
            ewk->wu.routine_no[2] = 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.dir_timer = twk->data00;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x7000;
            cal_initial_speed(&ewk->wu,
                              ewk->wu.dir_timer,
                              mwk->wu.xyz[0].disp.pos + ewk->wu.old_pos[0],
                              mwk->wu.xyz[1].disp.pos + ewk->wu.old_pos[1]);
            break;
        case 1:
            add_mvxy_speed_no_use_rl(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
            if (check_tengu_attack(&ewk->wu, &mwk->wu, twk) == 0 && --ewk->wu.dir_timer < 0) {
                ewk->wu.routine_no[2] = 2;
            }
            break;
        case 2:
            ewk->wu.position_z = mwk->wu.position_z + ewk->wu.old_pos[2];
            if (mwk->sa->ok != -1 || ewk->wu.dir_old != mwk->sa->id_arts) {
                ewk->wu.routine_no[1] = 2;
                ewk->wu.routine_no[2] = 0;
                ewk->wu.cg_hit_ix = 0;
                make_speed_xy_back(&ewk->wu, &mwk->wu, twk);
                break;
            }
            if (check_tengu_attack(&ewk->wu, &mwk->wu, twk)) {
                break;
            }
            set_tengu_my_home(&ewk->wu, &mwk->wu);
            if (ewk->wu.dir_step > 8) {
                ewk->wu.routine_no[2] = 1;
                ewk->wu.dir_timer = 8;
                cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.dmcal_m, ewk->wu.dmcal_d, 2, 2);
            }
            break;
        case 3:
            add_mvxy_speed_no_use_rl(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.routine_no[2] = 4;
                ewk->wu.att_hit_ok = 0;
                ewk->wu.dir_timer = twk->hos_x;
                set_tengu_my_home(&ewk->wu, &mwk->wu);
                cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.dmcal_m, ewk->wu.dmcal_d, 2, 2);
            }
            break;
        case 4:
            add_mvxy_speed_no_use_rl(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
            ewk->wu.cg_hit_ix = 0;
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.routine_no[2] = 2;
            }
            break;
        case 5:
            set_tengu_my_home(&ewk->wu, &mwk->wu);
            ewk->wu.routine_no[2] = 4;
            ewk->wu.cg_hit_ix = 0;
            ewk->wu.dir_timer = twk->hos_y;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x4000;
            cal_initial_speed(&ewk->wu, ewk->wu.dir_timer, ewk->wu.dmcal_m, ewk->wu.dmcal_d);
            break;
        }
        break;
    case 1:
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 5;
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.cg_hit_ix = 0;
        set_hit_stop_hit_quake(&ewk->wu);
        break;
    case 2:
        add_mvxy_speed_no_use_rl(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (--ewk->wu.dir_timer < 0) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.disp_flag = 0;
        }
        ewk->wu.cg_hit_ix = 0;
        break;
    }
}



void set_tengu_my_home(WORK* ewk, WORK* mwk) {
    if (mwk->pat_status < 32) {
        ewk->dmcal_m = mwk->xyz[0].disp.pos + ewk->old_pos[0];
        ewk->dmcal_d = mwk->xyz[1].disp.pos + ewk->old_pos[1];
    } else {
        ewk->dmcal_m = mwk->xyz[0].disp.pos + ewk->scr_mv_x;
        ewk->dmcal_d = mwk->xyz[1].disp.pos + ewk->scr_mv_y;
    }
    ewk->dir_step = cal_move_quantity2(ewk->xyz[0].disp.pos, ewk->xyz[1].disp.pos, ewk->dmcal_m, ewk->dmcal_d);
}



s32 check_tengu_attack(WORK* ewk, WORK* mwk, TAMA* twk) {
    if (mwk->cg_ja.atix == 0) {
        return 0;
    }
    ewk->routine_no[2] = 3;
    ewk->att_hit_ok = 1;
    ewk->rl_flag = mwk->rl_flag;
    ewk->dir_timer = twk->life_time;
    grade_add_att_renew((WORK_Other*)ewk);
    if (mwk->xyz[1].disp.pos > 0) {
        make_speed_xy_att(ewk, mwk, ewk->dir_timer, 2, 0);
    } else {
        make_speed_xy_att(ewk, mwk, ewk->dir_timer, 0, 2);
    }
    return 1;
}



void make_speed_xy_att(WORK* ewk, WORK* mwk, s16 tm, u8 xsw, u8 ysw) {
    s16 ax;
    s16 ay;
    get_target_att_position(mwk, &ax, &ay);
    cal_all_speed_data(ewk, tm, ax, ay, xsw, ysw);
}



void make_speed_xy_back(WORK* ewk, WORK* mwk, TAMA* twk) {
    s16 bx;
    s16 by;
    ewk->dmcal_m = ewk->xyz[0].disp.pos;
    ewk->dmcal_d = ewk->xyz[1].disp.pos;
    ewk->mvxy.d[0].sp = 0;
    ewk->mvxy.d[1].sp = -0x7000;
    ewk->dir_timer = twk->data01;
    set_tengu_init_pos((WORK_Other*)ewk, mwk);
    bx = ewk->xyz[0].disp.pos;
    by = ewk->xyz[1].disp.pos;
    ewk->xyz[0].disp.pos = ewk->dmcal_m;
    ewk->xyz[1].disp.pos = ewk->dmcal_d;
    cal_initial_speed(ewk, ewk->dir_timer, bx, by);
}



void kotp_03000(WORK_Other* ewk, TAMA* twk) {
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
        if ((ewk->wu.xyz[1].disp.pos + ewk->wu.cg_jphos) <= 0) {
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.xyz[1].disp.pos = -ewk->wu.cg_jphos;
            break;
        }
        if (--ewk->wu.dir_timer >= 0 && !screen_range_check(&ewk->wu)) {
            break;
        }
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.hit_stop = 0;
        ewk->wu.hit_quake = 0;
        if (ewk->wu.vital_new < 0x100) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                    ewk->wu.routine_no[1] = 2;
                    ewk->wu.routine_no[2] = 1;
                    ewk->wu.mvxy.a[0].sp = 0;
                    ewk->wu.mvxy.a[1].sp = 0;
                    ewk->wu.mvxy.d[0].sp = 0;
                    ewk->wu.mvxy.d[1].sp = 0;
                    ewk->wu.hf.hit_flag = 0;
                    ewk->wu.kage_flag = 0;
                    break;
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.disp_flag = 2;
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
            ewk->wu.mvxy.a[0].sp /= 3;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hf.hit_flag = 0;
            ewk->wu.kage_flag = 0;
            break;
        }
        ewk->wu.routine_no[1] = 0;
        ewk->wu.hf.hit_flag = 0;
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

void kotp_04000(WORK_Other* ewk)
{

    ewk->wu.disp_flag = 0;
    ewk->wu.routine_no[0] = 2;
}



void kotp_05000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.routine_no[3] == 0) {
            ewk->wu.routine_no[3]++;
            ewk->wu.xyz[1].disp.pos = ((s16)get_height_position()) + 256;
        }
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
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
        if (--ewk->wu.dir_timer >= 0 && screen_x_range_check(&ewk->wu) == 0) {
            break;
        }
        ewk->wu.mvxy.a[0].sp /= 4;
        ewk->wu.mvxy.a[1].sp /= 4;
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
