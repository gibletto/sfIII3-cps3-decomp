/*
 * EFF42.C  Effect 42 (order-driven select object)
 *
 * Effect 42 is a select-screen object driven through the Order tables: EFF42_SUDDENLY,
 * SLIDE_IN, SLIDE_OUT, KILL and MOVE place it from Pos_Data_69, slide it in from either
 * side, or release it. Used by sel_pl and next_cpu.
 * zoom_x_step_check steps a work's horizontal zoom toward 0 or 63.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF42.h"



void effect_42_move(WORK_Other* ewk) {
    EFF42_Jmp_Tbl[Order[ewk->wu.dir_old]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF42_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }
        if (ewk->wu.my_family == 4) {
            ewk->wu.routine_no[6]++;
            ewk->wu.xyz[0].disp.pos = Target_BG_X[3] + Offset_BG_X[3] + Pos_Data_69[ewk->wu.dir_old][0];
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Pos_Data_69[ewk->wu.dir_old][1];
        } else {
            ewk->wu.disp_flag = 1;
            Order[ewk->wu.dir_old] = 3;
            ewk->wu.routine_no[6] = 0;
            ewk->wu.xyz[0].disp.pos = Pos_Data_69[ewk->wu.dir_old][0] + 512;
            ewk->wu.xyz[1].disp.pos = Pos_Data_69[ewk->wu.dir_old][1] + 0;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (!Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 32)) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[6] = 0;
            Order[ewk->wu.dir_old] = 3;
        }
        break;
    }
}



void EFF42_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }
        ewk->wu.routine_no[6]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.hit_quake = Pos_Data_69[ewk->wu.dir_old][0] + 512;
        ewk->wu.xyz[1].disp.pos = Pos_Data_69[ewk->wu.dir_old][1] + 0;
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.xyz[0].disp.pos = 800;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = 224;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                Order[ewk->wu.dir_old] = 3;
                ewk->wu.routine_no[6] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            Order[ewk->wu.dir_old] = 3;
            ewk->wu.routine_no[6] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    }
}



void EFF42_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            return;
        }
        ewk->wu.routine_no[6]++;
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = -0x8000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0x8000;
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, 2, 16)) {
            ewk->wu.routine_no[6] += 1;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFF42_KILL(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


void EFF42_MOVE(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            Time_Stop = 0;
        }
        break;
    case 1:
        if (ewk->wu.rl_waza != Select_Timer) {
            ewk->wu.rl_waza = Select_Timer;
            Setup_Char_Index(ewk);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        break;
    }
}



void Setup_Char_Index(WORK_Other* ewk) {
    s32 xx = Select_Timer & (s8)ewk->wu.routine_no[7];
    xx &= 0xFF;
    if (ewk->wu.routine_no[7] == 240) {
        xx >>= 4;
    }
    if (ewk->wu.dir_old >= 7) {
        ewk->wu.dir_step = xx + 10;
    } else {
        ewk->wu.dir_step = xx;
    }
}



s32 effect_42_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 42;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.dir_timer = 10;
    ewk->wu.rl_waza = Select_Timer;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.dir_old = type;
    if (type & 1) {
        ewk->wu.direction = 4;
    } else {
        ewk->wu.direction = 8;
    }
    ewk->wu.char_index = 3;
    ewk->wu.position_z = 14;
    switch (type) {
    case 5:
        ewk->wu.routine_no[7] = 240;
        ix = Select_Timer & 0xF0;
        ix >>= 4;
        ewk->wu.dir_step = ix;
        break;
    case 6:
        ewk->wu.routine_no[7] = 15;
        ewk->wu.dir_step = 0;
        break;
    case 7:
        ewk->wu.routine_no[7] = 240;
        ix = Select_Timer & 0xF0;
        ix >>= 4;
        ewk->wu.dir_step = ix + 10;
        break;
    case 8:
        ewk->wu.routine_no[7] = 15;
        ewk->wu.dir_step = 10;
        break;
    case 9:
        ewk->wu.routine_no[7] = 240;
        ix = Select_Timer & 0xF0;
        ix >>= 4;
        ewk->wu.dir_step = ix + 10;
        ewk->wu.my_family = 4;
        break;
    case 10:
        ewk->wu.routine_no[7] = 15;
        ewk->wu.dir_step = 10;
        ewk->wu.my_family = 4;
        break;
    }
    return 0;
}


s32 zoom_x_step_check(wk)
WORK* wk;
{
    if (wk->mvxy.a[0].sp <= 0) {
        if ((wk->my_mr.size.x += *(s16*)&wk->mvxy.a[0]) <= 0) {
            wk->my_mr.size.x = 0;
            return 1;
        }
        return 0;
    } else {
        if ((wk->my_mr.size.x += *(s16*)&wk->mvxy.a[0]) >= 63) {
            wk->my_mr.size.x = 63;
            return 1;
        }
        return 0;
    }
}


/* provisional name */
s32 Order_Timer_Dec(WORK_Other* ewk) {
    if (ewk->wu.direction == 0) {
        Order_Timer[ewk->wu.dir_old]--;
    }
    return Order_Timer[ewk->wu.dir_old];
}
