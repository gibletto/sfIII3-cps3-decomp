/*
 * EFF58.C  Effects 55-57 and effect 58 (timed screen commands)
 *
 * Effect 55 is a bg120 object that slides down, holds, slides up and repeats. Effect 56
 * steps through eight palette steps. Effect 57 is an animation that starts after a delay.
 * Effect 58 is a timer: after time0 frames it performs one screen command - stop a scroll,
 * screen switch or fill, the title logo, sound and BGM requests, set Next_Step, slide a BG
 * layer to its target, set a Suicide flag or move a virtual BG. Used by the game flow,
 * select, continue and ranking screens (Game_Main, Manage, Win, sel_pl, next_cpu, ...).
 * EFF58_Type_05 is the type routine for a marker that follows the player.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Win.h"
#include "end_sub.h"
#include "Eff59.h"
#include "sys_test.h"
#include "textsound.h"
#include "sc_trans.h"
#include "SE.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "CHARMOVE.h"
#include "bg_sub.h"
#include "EFF58.h"
#include "sc_logo.h"



void effect_55_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 3);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal += 0x3000;
            if (ewk->wu.xyz[1].disp.pos >= 128) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 300;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal -= 0x4000;
            if (ewk->wu.xyz[1].disp.pos <= 96) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 480;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0] = 1;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_55_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 55;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    ewk->wu.xyz[0].disp.pos = 511;
    ewk->wu.xyz[1].disp.pos = 96;
    ewk->wu.my_priority = 86;
    ewk->wu.position_z = 86;
    ewk->wu.hit_stop = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = brz_char_table;
    suzi_offset_set(ewk);
    return 0;
}

/* Start the flashing palette effect for one side (rl_flag 0 or 1). */
s32 effect_56_init(s8 side)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 56;
    ewk->wu.rl_flag = side;
    ewk->wu.operator = 0;
    ewk->wu.type = eff56_timer_tbl[side][0];
    return 0;
}



void effect_56_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
    case 1:
        ewk->wu.type--;
        if (ewk->wu.type == 0) {
            ewk->wu.operator++;
            if (ewk->wu.operator > 7) {
                ewk->wu.operator = 0;
            }
            ewk->wu.type = eff56_timer_tbl[ewk->wu.rl_flag][ewk->wu.operator];
            load_any_color(eff56_color_tbl[ewk->wu.rl_flag][ewk->wu.operator]);
        }
        break;
    default:
    case 2:
        push_effect_work(&ewk->wu);
        break;
    }
}



void effect_57_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



s32 effect_57_init(s16 char_ix, s16 x, s16 y, s16 timer, s16 step, s16 z) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 57;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 67;
    ewk->wu.my_family = 1;
    ewk->wu.position_z = z;
    ewk->wu.dir_timer = timer;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = char_ix;
    ewk->wu.dir_step = step;
    ewk->wu.xyz[0].disp.pos = x;
    ewk->wu.xyz[1].disp.pos = y;
    return 0;
}



void effect_58_move(WORK_Other* ewk) {
    s16 xx;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            Scrn_Move_Set(4, 0, 0);
            ewk->wu.routine_no[0] = 99;
            break;
        case 1:
            EFF58_Type_01(ewk);
            break;
        case 2:
            EFF58_Type_02(ewk);
            break;
        case 3:
            EFF58_Type_03(ewk);
            break;
        case 4:
            break;
        case 5:
            EFF58_Type_05(ewk);
            break;
        case 6:
            if (Demo_Sound || Demo_Flag) {
                sound_request(ewk->wu.direction);
            }
            push_effect_work(&ewk->wu);
            break;
        case 7:
            Next_Step = 1;
            push_effect_work(&ewk->wu);
            break;
        case 8:
            if ((Demo_Sound || Demo_Flag) && !Keep_BGM_Flag) {
                bgm_request(ewk->wu.direction);
            }
            push_effect_work(&ewk->wu);
            break;
        case 9:
            if ((Demo_Sound || Demo_Flag) && !Keep_BGM_Flag) {
                sound_fade_in_submit(ewk->wu.direction, 0x222);
            }
            push_effect_work(&ewk->wu);
            break;
        case 10:
            SF33rd_Logo(ewk);
            break;
        case 11:
            EFF58_Type_11(ewk);
            break;
        case 12:
            if (!Cut_Scroll) {
                xx = 3;
            } else {
                xx = Cut_Cut_Sub(3);
            }
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case 13:
            if (!Cut_Scroll) {
                xx = 5;
            } else {
                xx = Cut_Cut_Sub(5);
            }
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case 14:
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case 15:
            Suicide[ewk->wu.direction] = 1;
            push_effect_work(&ewk->wu);
            break;
        case 16:
            bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos += 256;
            Setup_Virtual_BG(ewk->wu.direction,
                         bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                         bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            push_effect_work(&ewk->wu);
            break;
        case 17:
            bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos += 512;
            Setup_Virtual_BG(ewk->wu.direction,
                         bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                         bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            push_effect_work(&ewk->wu);
            break;
        case 18:
            Setup_Virtual_BG(2, 0x480, 0);
            push_effect_work(&ewk->wu);
            break;
        }
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_58_init(s16 id, s16 time0, s16 option) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 58;
    ewk->wu.work_id = 16;
    ewk->wu.dir_timer = time0;
    ewk->wu.dir_old = time0;
    ewk->wu.direction = option;
    ewk->wu.routine_no[1] = id;
    return 0;
}



/* provisional name */
s32 effect_58_area_init(s16 time0, s16 step) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 58;
    ewk->wu.work_id = 16;
    ewk->wu.dir_timer = 1;
    ewk->wu.dir_old = time0;
    ewk->wu.dir_step = step;
    ewk->wu.routine_no[1] = 5;
    return 0;
}



void EFF58_Type_01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (!--Cover_Timer) {
            ewk->wu.routine_no[2]++;
            Switch_Screen_Init(0, 0);
        }
        break;
    case 1:
        if (Switch_Screen_Revival()) {
            ewk->wu.routine_no[0] = 99;
        }
        break;
    }
}



void EFF58_Type_03(WORK_Other* ewk) {
    tilemap_fill_all(0, 32);
    ToneDown(0);
    ewk->wu.routine_no[0] = 99;
}



void EFF58_Type_02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2180;
        ewk->wu.my_family = 2;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].position_x + DE_X[10] + 0xC0;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].position_y + 200;
        ewk->wu.position_z = 38;
        if (Country == 1) {
            ewk->wu.dir_step = 34;
        } else {
            ewk->wu.dir_step = 37;
        }
        ewk->wu.char_index = 9;
        ewk->wu.char_table[0] = sel_pl_char_table;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (Suicide[0] != 0) {
            ewk->wu.routine_no[2]++;
            break;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(ewk);
        break;
    case 2:
        ewk->wu.routine_no[2]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}


void EFF58_Type_05(WORK_Other* ewk) {
    s16 x;
    s32 pl;
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.my_family = 2;
        pl = ewk->wu.dir_old;
        ewk->wu.my_priority = plw[pl].wu.my_priority - 10;
        ewk->wu.position_z = plw[ewk->wu.dir_old].wu.position_z - 10;
        ewk->wu.char_index = 26;
        ewk->wu.char_table[0] = sel_pl_char_table;
        ewk->wu.disp_flag = 1;
        ((void(*)(WORK* wk, s16 koc, s32 index, s32 ip, s16 scf))set_char_move_init2)(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 11, 0);
        break;
    case 1:
        x = Separate_Area[ewk->wu.dir_old][ewk->wu.dir_step - 1];
        if (plw[ewk->wu.dir_old].wu.rl_waza == 0) {
            x = -x;
        }
        ewk->wu.xyz[0].disp.pos = plw[ewk->wu.dir_old].wu.xyz[0].disp.pos + x;
        ewk->wu.xyz[1].disp.pos = plw[ewk->wu.dir_old].wu.xyz[1].disp.pos + 32;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void SF33rd_Logo(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        SF3_logo(0);
        Switch_Screen_Init(5, 5);
        Stop_SG = 0;
        break;
    case 1:
        if (Switch_Screen_Revival()) {
            ewk->wu.routine_no[2]++;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void EFF58_Type_11(WORK_Other* ewk) {
    if (Break_Into) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[2]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        ToneDown((s8)ewk->wu.routine_no[2] + 10);
        ewk->wu.routine_no[2]++;
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



