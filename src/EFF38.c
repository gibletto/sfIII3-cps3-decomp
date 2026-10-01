/*
 * EFF38.C  Effect 38: order-driven select/VS screen object
 *
 * Effect 38 is controlled through the Order, Order_Timer and Order_Dir tables. Its states
 * (EFF38_WAIT, SUDDENLY, SLIDE_IN, SLIDE_OUT, KILL, SHIFT, MOVE) make it appear at once,
 * slide in or out from the side, shift or move, and release it. Used by the character
 * select (sel_pl) and next-opponent (next_cpu) screens.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "CALDIR.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARMOVE.h"
#include "EFF38.h"
#include "fighter.h"




void effect_38_move(WORK_Other* ewk) {
    EFF38_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF38_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    }
}



void EFF38_SUDDENLY(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] == 0) {
        ewk->wu.disp_flag = 1;
        Order[ewk->wu.dir_old] = 0;
        ewk->wu.routine_no[0] = 0;
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    }
}



void EFF38_SLIDE_IN(WORK_Other* ewk) {
    u16 cut = Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (Order[ewk->wu.dir_old] != 1) {
            if (ewk->master_id == 0) {
                ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 128;
                ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 32;
            } else {
                ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 128;
                ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 32;
            }
            Order[ewk->wu.dir_old] = 1;
            break;
        }
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                Exit_Slide_in_38(ewk);
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            Exit_Slide_in_38(ewk);
        }
        break;
    }
}



/* provisional name */
void Exit_Slide_in_38(WORK_Other* ewk) {
    ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
    if (--Select_Start[ewk->master_id] < 0) {
        Select_Start[ewk->master_id] = 0;
    }
    ewk->wu.routine_no[1] = 0;
    ewk->wu.routine_no[6] = 0;
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        return;
    }
    if (ewk->wu.vital_old == 0x7F) {
        ewk->wu.routine_no[0] = 5;
        Order[ewk->wu.dir_old] = 5;
        return;
    }
    ewk->wu.routine_no[0] = 0;
    Order[ewk->wu.dir_old] = 0;
}



void EFF38_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[6]++;
            if (Order_Dir[ewk->wu.dir_old] == 8) {
                ewk->wu.mvxy.a[0].sp = 0xF0000;
                ewk->wu.mvxy.d[0].sp = 0x8000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0xF0000;
                ewk->wu.mvxy.d[0].sp = -0x8000;
            }
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 80)) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFF38_KILL(WORK_Other* ewk) {
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



void EFF38_SHIFT(WORK_Other* ewk) {
    u16 cut = Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] != 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        if (ewk->master_id == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF38_Base_XY[ewk->master_id][1][1] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
            ewk->wu.mvxy.a[0].sp = -0x60000;
            ewk->wu.mvxy.a[1].sp = 0x30000;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.vital_new, 1, 1);
            ewk->wu.dir_timer = 10;
        } else {
            ewk->wu.hit_quake = 128 + bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.vital_new = -32 + bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
            ewk->wu.mvxy.a[0].sp = 0x60000;
            ewk->wu.mvxy.a[1].sp = -0x30000;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.vital_new, 1, 1);
            ewk->wu.dir_timer = 10;
        }
        break;
    case 1:
        if (Shift_38(ewk)) {
            ewk->wu.routine_no[0] = 5;
            Order[ewk->wu.dir_old] = 5;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[6] = 0;
            if (--Select_Start[ewk->master_id] < 0) {
                Select_Start[ewk->master_id] = 0;
            }
        }
        break;
    }
}



s32 Shift_38(WORK_Other* ewk) {
    s16 ix;
    s16 loop;
    if (Scene_Cut) {
        loop = 3;
    } else {
        loop = 1;
    }
    for (ix = 0; ix < loop; ix++) {
        Move_X_Sub_38(ewk);
        Move_Y_Sub_38(ewk, ewk->wu.vital_new);
        if (--ewk->wu.dir_timer == 0) {
            return 1;
        }
    }
    return 0;
}



s32 Move_X_Sub_38(WORK_Other* ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
    if (0 < ewk->wu.mvxy.a[0].sp) {
        if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            return 1;
        }
        return 0;
    }
    if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        ewk->wu.mvxy.a[0].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        return 1;
    }
    return 0;
}



s32 Move_Y_Sub_38(WORK_Other* ewk, s16 Target_Y) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
    if (0 > ewk->wu.mvxy.a[1].sp) {
        if (Target_Y >= ewk->wu.xyz[1].disp.pos) {
            ewk->wu.xyz[1].disp.pos = Target_Y;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            return 1;
        }
    } else if (Target_Y <= ewk->wu.xyz[1].disp.pos) {
        ewk->wu.xyz[1].disp.pos = Target_Y;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = 0;
        return 1;
    }
    return 0;
}



void EFF38_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 5) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Sel_PL_Complete[ewk->master_id] || plw[ewk->master_id].wu.operator == 0) {
            ewk->wu.routine_no[1] = 2;
        } else {
            ewk->wu.routine_no[1]++;
        }
    case 1:
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                      EFF38_Base_XY[ewk->master_id][Play_Type][0] +
                                      EFF38_Correct_Data[ewk->master_id][Play_Type][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                      EFF38_Base_XY[ewk->master_id][Play_Type][1] +
                                      EFF38_Correct_Data[ewk->master_id][Play_Type][ewk->wu.dir_step][1];
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 2:
        break;
    }
}



s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 38;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 64;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 16;
    ewk->wu.char_index = 2;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_old = Play_Status;
    ewk->wu.dir_old = dir_old;
    ewk->wu.vital_old = Your_Char;
    if (Your_Char == 0x7F) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y_low[ewk->master_id * 2]][Cursor_X[ewk->master_id]];
    } else {
        ewk->wu.dir_step = Your_Char;
    }
    ewk->wu.rl_flag = PL_id ^ 1;
    if (PL_id) {
        if (My_char[PL_id] == 22) {
            ewk->wu.dir_step++;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 272;
        ewk->wu.position_z = 75;
        ewk->wu.mvxy.a[0].sp = -0xF0000;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.mvxy.d[1].sp = 0;
        if (Play_Status == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][0][0] +
                                EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][0][1] +
                                                          EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][1];
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][1][1] +
                                                          EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
        }
    } else {
        if (Your_Char != 0x7F && My_char[PL_id] == PL_GILL) {
            ewk->wu.dir_step = 24;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 272;
        ewk->wu.position_z = 77;
        ewk->wu.mvxy.a[0].sp = 0xF0000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.mvxy.d[1].sp = 0;
        if (Play_Status == 0) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][0][0] +
                                EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][0][1] +
                                                          EFF38_Correct_Data[ewk->master_id][0][ewk->wu.dir_step][1];
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF38_Base_XY[ewk->master_id][1][0] +
                                EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][0];
            ewk->wu.xyz[1].disp.pos = ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                                          EFF38_Base_XY[ewk->master_id][1][1] +
                                                          EFF38_Correct_Data[ewk->master_id][1][ewk->wu.dir_step][1];
        }
    }
    return 0;
}
