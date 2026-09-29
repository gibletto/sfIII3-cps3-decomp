/*
 * EFFH9.C  Effects H7 and H8 (objects that pop out of the ground) and H9 (balls-left counter)
 *
 * Effects H7 and H8 are created at their owner's x, at floor level, with the owner's palette
 * and facing (plef_char_table). Each waits a per-type delay (effH7_wait_tbl / effH8_wait_tbl),
 * raises a dust effect (effect 3 types 69 / 70) and then appears with a pattern from
 * effH7_char_tbl / effH8_char_tbl at the offsets in effH7_pos_tbl / effH8_pos_tbl.
 * effect_H7_move bounces the object in (effH7_bound_tbl) and then bobs it along random height
 * tables (effH7_move_tbl). effect_H8_move plays its pattern once; on stage 8 in the first round
 * it later switches to a second pattern and flies upward. Both die with dead_f or Suicide[0].
 * Effect H9 is the bonus stage's remaining-ball counter: effect_H9_init (BBBSCOM.c) builds three
 * connected sprites from bbbs_ball by facing, and effect_H9_move counts the two-digit number up
 * to Bonus_Game_Work, then keeps it equal to Bonus_Game_Work (nokori_ball_effH9).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFF03.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFH9.h"



void effect_H7_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        if (ewk->wu.rl_waza) {
            ewk->wu.position_x += ((const s16*)((const u8*)effH7_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH7_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH7_pos_tbl[0][0]))))[0];
        } else {
            ewk->wu.position_x -= ((const s16*)((const u8*)effH7_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH7_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH7_pos_tbl[0][0]))))[0];
        }
        ewk->wu.position_y += ((const s16*)((const u8*)effH7_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH7_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH7_pos_tbl[0][0]))))[1];
        ewk->wu.position_z += ((const s16*)((const u8*)effH7_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH7_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH7_pos_tbl[0][0]))))[2];
        ewk->wu.xyz[0].disp.pos = ewk->wu.position_x;
        ewk->wu.xyz[1].disp.pos = ewk->wu.position_y;
        ewk->wu.disp_flag = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.dir_timer = effH7_wait_tbl[ewk->wu.type];
        set_char_move_init(&ewk->wu, 0, effH7_char_tbl[ewk->wu.rl_waza][ewk->wu.type]);
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (--ewk->wu.dir_timer > 0) {
                    break;
                }
                effect_03_init(&ewk->wu, 69);
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 4;
                break;
            case 1:
                if (--ewk->wu.dir_timer > 0) {
                    break;
                }
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 1;
                ewk->wu.dir_timer = 0;
                break;
            case 2:
                ewk->wu.dir_step = effH7_bound_tbl[ewk->wu.dir_timer++];
                if (ewk->wu.dir_step == 99) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.dir_timer = effH7_wait2_tbl[ewk->wu.type];
                } else {
                    ewk->wu.position_y += ewk->wu.dir_step;
                }
                break;
            case 3:
                if (--ewk->wu.dir_timer > 0) {
                    break;
                }
                ewk->wu.routine_no[1]++;
            case 4:
                ewk->wu.dir_timer = 0;
                ewk->wu.move_xy_table = effH7_move_tbl[random_16_com()];
                ewk->wu.routine_no[1]++;
            default:
                char_move(&ewk->wu);
                ewk->wu.dir_step = ewk->wu.move_xy_table[ewk->wu.dir_timer++];
                if (ewk->wu.dir_step == 99) {
                    ewk->wu.routine_no[1] = 4;
                } else {
                    ewk->wu.position_y += ewk->wu.dir_step;
                }
                break;
            }
        }
        sort_push_request(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_H7_init(WORK* wk, s16 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 177;
    ewk->wu.type = type;
    ewk->wu.work_id = 16;
    ewk->wu.rl_waza = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = ewk->wu.blink_timing = wk->id;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = -4;
    ewk->wu.position_z = wk->position_z;
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}



void effect_H8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        if (ewk->wu.rl_waza) {
            ewk->wu.position_x += ((const s16*)((const u8*)effH8_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH8_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH8_pos_tbl[0][0]))))[0];
        } else {
            ewk->wu.position_x -= ((const s16*)((const u8*)effH8_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH8_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH8_pos_tbl[0][0]))))[0];
        }
        ewk->wu.position_y += ((const s16*)((const u8*)effH8_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH8_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH8_pos_tbl[0][0]))))[1];
        ewk->wu.position_z += ((const s16*)((const u8*)effH8_pos_tbl + (s8)((ewk)->wu.rl_waza * sizeof(effH8_pos_tbl[0])) + (s8)((ewk)->wu.type * sizeof(effH8_pos_tbl[0][0]))))[2];
        ewk->wu.xyz[0].disp.pos = ewk->wu.position_x;
        ewk->wu.xyz[1].disp.pos = ewk->wu.position_y;
        ewk->wu.disp_flag = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.dir_timer = effH8_wait_tbl[ewk->wu.type];
        set_char_move_init(&ewk->wu, 0, effH8_char_tbl[ewk->wu.rl_waza][ewk->wu.type]);
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (--ewk->wu.dir_timer > 0) {
                    break;
                }
                effect_03_init(&ewk->wu, 70);
                ewk->wu.routine_no[1]++;
                ewk->wu.dir_timer = 4;
                break;
            case 1:
                if (--ewk->wu.dir_timer > 0) {
                    break;
                }
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 1;
                break;
            case 2:
                char_move(&ewk->wu);
                if (ewk->wu.cg_type == 0xFF) {
                    if (bg_w.stage == 8 && Round_num == 0) {
                        ewk->wu.routine_no[1] = 3;
                    } else {
                        ewk->wu.routine_no[1] = 9;
                    }
                }
                break;
            case 3:
                if (bg_w.bgw[1].r_no_1 >= 1) {
                    set_char_move_init(&ewk->wu, 0, effH8_char2_tbl[ewk->wu.rl_waza][ewk->wu.type]);
                    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x;
                    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y;
                    ewk->wu.mvxy.d[0].sp = 0;
                    ewk->wu.mvxy.a[0].sp = 0;
                    ewk->wu.mvxy.a[1].sp = 0;
                    ewk->wu.mvxy.d[1].sp = -0x3400;
                    ewk->wu.mvxy.kop[0] = ewk->wu.mvxy.kop[1] = 0;
                    ewk->wu.kage_flag = 0;
                    ewk->wu.routine_no[1]++;
                }
                break;
            case 4:
                char_move(&ewk->wu);
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.mvxy.a[1].sp < -0x100000) {
                    ewk->wu.mvxy.d[1].sp = 0;
                }
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
                break;
            }
        }
        sort_push_request(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_H8_init(WORK* wk, s16 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 178;
    ewk->wu.type = type;
    ewk->wu.work_id = 16;
    ewk->wu.rl_waza = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = ewk->wu.blink_timing = wk->id;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = wk->position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = -4;
    ewk->wu.position_z = wk->position_z - 6;
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}



void effect_H9_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.position_z = ewk->wu.my_priority = 9;
            ewk->wu.direction = 0;
            ewk->wu.dir_timer = 0;
            nokori_ball_effH9(ewk, ewk->wu.direction);
            break;
        case 1:
            if (--ewk->wu.dir_timer > 0) {
                break;
            }
            ewk->wu.dir_timer = 3;
            ewk->wu.direction++;
            nokori_ball_effH9(ewk, ewk->wu.direction);
            if (ewk->wu.direction >= Bonus_Game_Work) {
                ewk->wu.routine_no[0] = 1;
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        effH9_trans(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        nokori_ball_effH9(ewk, Bonus_Game_Work);
        effH9_trans(&ewk->wu);
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



void effH9_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}



void nokori_ball_effH9(WORK_Other_CONN* ewk, s16 num) {
    ewk->conn[0].chr = (num % 10) + 0xB318;
    ewk->conn[1].chr = (num / 10) + 0xB318;
}



s32 effect_H9_init(PLW* wk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 179;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = wk->wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 92;
    ewk->num_of_conn = 3;
    if (wk->wu.rl_flag) {
        ix = 1;
    } else {
        ix = 0;
    }
    for (i = 0; i < 3; i++) {
        ewk->conn[i] = bbbs_ball[ix][i];
    }
    return 0;
}
