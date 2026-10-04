/*
 * EFF39.C  Effect 39: character name object on the select screens
 *
 * Effect 39 is a select-screen object for a player (character, BG and option), created by
 * effect_39_init from sel_pl and next_cpu.
 * effect_39_move runs one routine per state through a jump table and draws the object with
 * sort_push_request4; the state is driven by the shared Order / Order_Timer arrays.
 * EFF39_WAIT waits for an order; EFF39_SUDDENLY shows the object at once at its Name_Pos_Data
 * position; EFF39_SLIDE_IN and EFF39_SLIDE_OUT slide it in from or out to the player's side;
 * EFF39_MOVE moves it; EFF39_KILL counts down, hides and releases it.
 * Get_Pos39 returns the resting position; Select_Start is decremented when a slide-in lands.
 * Effect 40, at the end of the file, is a select-screen zoom object: it waits for its delay,
 * appears at double size and shrinks to normal while moving forward in priority; it is placed by
 * direction from eff40_pos_x_tbl.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Eff76.h"
#include "EFFK7.h"
#include "EffK6.h"
#include "aboutspr.h"
#include "Eff59.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff39.h"
#include "EFFD9.h"
#include "Grade.h"
#include "EFF41.h"
#include "EFF42.h"



void effect_39_move(WORK_Other* ewk) {
    EFF39_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFF39_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    }
}



void EFF39_SUDDENLY(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }
    ewk->wu.disp_flag = 1;
    Order[ewk->wu.dir_old] = 0;
    ewk->wu.routine_no[0] = 0;
    ewk->wu.routine_no[6] = 0;
    ewk->wu.xyz[0].disp.pos =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Name_Pos_Data[ewk->master_id][1][ewk->wu.dir_step][0];
    ewk->wu.xyz[1].disp.pos =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Name_Pos_Data[ewk->master_id][1][ewk->wu.dir_step][1];
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}



void EFF39_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] == 5) {
        ewk->wu.routine_no[0] = 5;
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
        if (ewk->master_id) {
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 0);
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 256;
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 272;
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.hit_quake = Get_Pos39(ewk, ewk->wu.dir_step, 0) + 512;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake - 256;
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
        }
        set_char_move_init2(&ewk->wu, 0, (s16)(ewk->wu.char_index), (ewk->wu.dir_step) + 1, 0);
        break;
    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0] = 4;
                Order[ewk->wu.dir_old] = 4;
                ewk->wu.routine_no[6] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                if (--Select_Start[ewk->master_id] < 0) {
                    Select_Start[ewk->master_id] = 0;
                }
            }
            break;
        }
        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 4;
            Order[ewk->wu.dir_old] = 4;
            ewk->wu.routine_no[6] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            if (--Select_Start[ewk->master_id] < 0) {
                Select_Start[ewk->master_id] = 0;
            }
        }
        break;
    }
}



void EFF39_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case 0:
        if (ewk->wu.disp_flag == 0) {
            ewk->wu.routine_no[1] = 99;
        } else {
            if (--Order_Timer[ewk->wu.dir_old]) {
                break;
            }
            ewk->wu.routine_no[6]++;
        }
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 48)) {
            ewk->wu.routine_no[6]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFF39_KILL(WORK_Other* ewk) {
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



void EFF39_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 4) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
    } else {
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
                ewk->wu.dir_step += chkNameAkuma(ewk->wu.dir_step);
                ewk->wu.xyz[0].disp.pos =
                    bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 0);
                ewk->wu.xyz[1].disp.pos =
                    bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_Pos39(ewk, ewk->wu.dir_step, 1);
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
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 39;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.position_z = 71;
    ewk->wu.char_index = 1;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.dir_old = dir_old;
    if (Your_Char == 0x7F) {
        ewk->wu.dir_step = ID_of_Face[Cursor_Y_low[ewk->master_id * 2]][Cursor_X[ewk->master_id]];
    } else {
        ewk->wu.dir_step = Your_Char;
    }
    ewk->wu.dir_step += chkNameAkuma(ewk->wu.dir_step);
    ewk->wu.dir_step += chkNameExport(ewk->wu.dir_step);
    if (Option == 1) {
        effect_59_init(ewk, ewk->wu.my_family, 5, 1);
    }
    return 0;
}


s32 Get_Pos39(WORK_Other* ewk, s16 Who, s16 Get_Type) {
    return Name_Pos_Data[ewk->master_id][Play_Type][Who][Get_Type];
}



void effect_40_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dir_timer = 1;
        ewk->wu.mvxy.a[0].sp = 0x80000;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 2:
        ewk->wu.my_priority++;
        ewk->wu.position_z++;
        if ((ewk->wu.my_mr.size.x -= ewk->wu.mvxy.a[0].real.h) <= 63) {
            ewk->wu.my_mr.size.x = 63;
        }
        if ((ewk->wu.my_mr.size.y -= ewk->wu.mvxy.a[0].real.h) <= 63) {
            ewk->wu.my_mr.size.y = 63;
        }
        if (ewk->wu.my_mr.size.x <= 63 && ewk->wu.my_mr.size.y <= 63) {
            ewk->wu.routine_no[0]++;
        }
        break;
    default:
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



s32 effect_40_init(s16 dir, s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 40;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2043;
    ewk->wu.my_family = 1;
    ewk->wu.position_z = 40;
    ewk->wu.dir_timer = timer;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_step = dir;
    ewk->wu.char_index = 22;
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 127;
    ewk->wu.my_mr.size.y = 127;
    ewk->wu.xyz[0].disp.pos = eff40_pos_x_tbl[dir] + DE_X[10] + bg_w.bgw[0].position_x + 0xC0;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].position_y + 0x80;
    return 0;
}



