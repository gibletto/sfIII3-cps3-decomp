/*
 * EFFK6.C  Effect K6: player name plates on the win and next-CPU screens
 *
 * Effect K6 (id 206) is a name plate created by effect_K6_init from sel_pl and next_cpu.
 * Setup_CharK6 and Setup_K6_Index choose the graphic, Setup_1st_PosK6 / Get_PosK6 the position
 * (Name_Cover_Pos_Data, with the Akuma and export name checks); chkNameSuv returns the
 * alternative name spelling index used outside region 1.
 * effect_K6_move follows the Order / Order_Timer controls: EFFK6_WAIT, EFFK6_SLIDE_IN,
 * EFFK6_SLIDE_OUT, EFFK6_SUDDENLY, EFFK6_MOVE and EFFK6_KILL.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Eff76.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "charmove_2.h"
#include "EffK6.h"

/* routine_no[0], the order carried out (EFFK6_Jmp_Tbl) */
#define R0_WAIT         0       /* wait for an order */
#define R0_MOVE         4       /* follow the cursor */
#define R0_KILL         5       /* hide after a while, then put back */

/* routine_no[1], first state of every order */
#define R1_DELAY        0       /* wait for the order timer */

/* routine_no[1], EFFK6_SLIDE_OUT */
#define R1_SLIDE        1       /* slide off the screen */
#define R1_KILL         99      /* (default) put the work back */

/* routine_no[1], EFFK6_MOVE */
#define R1_CHECK        0       /* see whether the choice is made */
#define R1_FOLLOW       1       /* follow the cursor until chosen */
#define R1_HOLD         2       /* stay on the chosen name */



void effect_K6_move(WORK_Other* ewk) {
    EFFK6_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



void EFFK6_WAIT(WORK_Other* ewk) {
    if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = R1_DELAY;
    }
}



void EFFK6_SLIDE_IN(WORK_Other* ewk) {
    s16 xx;
    if (Order[ewk->wu.dir_old] == R0_KILL) {
        ewk->wu.routine_no[0] = R0_KILL;
        ewk->wu.routine_no[1] = R1_DELAY;
    } else {
        switch (ewk->wu.routine_no[1]) {
        case R1_DELAY:
            if (--Order_Timer[ewk->wu.dir_old]) {
                break;
            }
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            if (ewk->wu.dir_old == 27 || ewk->wu.dir_old == 28) {
                xx = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            } else {
                xx = ewk->wu.dir_step;
            }
            Setup_1st_PosK6(ewk, xx, Play_Type);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            break;
        default:
            ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
            ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
            if (0 < ewk->wu.mvxy.a[0].sp) {
                if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                    if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                        Order[ewk->wu.dir_old] = R0_WAIT;
                    }
                    ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                    if (ewk->wu.dir_old < 31) {
                        Order[ewk->wu.dir_old] = R0_MOVE;
                        ewk->wu.routine_no[0] = R0_MOVE;
                        ewk->wu.routine_no[6] = 0;
                        break;
                    }
                    ewk->wu.routine_no[0] = R0_WAIT;
                }
                break;
            }
            if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = R0_WAIT;
                }
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
                if (ewk->wu.dir_old < 31) {
                    Order[ewk->wu.dir_old] = R0_MOVE;
                    ewk->wu.routine_no[0] = R0_MOVE;
                    ewk->wu.routine_no[6] = 0;
                    break;
                }
                ewk->wu.routine_no[0] = R0_WAIT;
            }
            break;
        }
    }
}



void EFFK6_SLIDE_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_DELAY:
        if (ewk->wu.disp_flag == 0) {
            ewk->wu.routine_no[1] = R1_KILL;
        } else {
            if (--Order_Timer[ewk->wu.dir_old]) {
                break;
            }
            ewk->wu.routine_no[1]++;
        }
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.mvxy.a[0].sp = -0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.mvxy.a[0].sp = 0xF0000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        break;
    case R1_SLIDE:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 64)) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void EFFK6_SUDDENLY(WORK_Other* ewk) {
    s16 xx;
    switch (ewk->wu.routine_no[1]) {
    case R1_DELAY:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        xx = Setup_K6_Index(ewk);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, xx, 0, 1);
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, xx, 1, 1);
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        if (ewk->wu.dir_old == 27 || ewk->wu.dir_old == 28) {
            Order[ewk->wu.dir_old] = R0_MOVE;
            ewk->wu.routine_no[0] = R0_MOVE;
            ewk->wu.routine_no[6] = 0;
            break;
        }
        ewk->wu.routine_no[0] = R0_WAIT;
        Order[ewk->wu.dir_old] = R0_WAIT;
        break;
    }
}



void EFFK6_KILL(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case R1_DELAY:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void EFFK6_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != R0_MOVE) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = R1_DELAY;
        ewk->wu.routine_no[6] = 0;
    } else {
        switch (ewk->wu.routine_no[1]) {
        case R1_CHECK:
            if (Sel_PL_Complete[ewk->master_id] || plw[ewk->master_id].wu.operator == 0) {
                ewk->wu.routine_no[1] = R1_HOLD;
            } else {
                ewk->wu.routine_no[1]++;
            }
        case R1_FOLLOW:
            if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
                ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
                ewk->wu.xyz[0].disp.pos =
                    bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, ewk->wu.dir_step, 0, Play_Type);
                ewk->wu.xyz[1].disp.pos =
                    bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, ewk->wu.dir_step, 1, Play_Type);
                if (ewk->wu.direction == 19) {
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.dir_step) + 1, 0);
                }
            }
            if (Sel_PL_Complete[ewk->master_id]) {
                ewk->wu.routine_no[1]++;
            }
            break;
        case R1_HOLD:
            break;
        }
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 206;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.direction = dm_vital;
    ewk->wu.dir_old = dir_old;
    Setup_CharK6(ewk, dm_vital);
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}



void Setup_1st_PosK6(ewk, Who, Play_Style)
WORK_Other* ewk;
s16 Who;
s16 Play_Style;
{
    if (ewk->master_id) {
        ewk->wu.mvxy.a[0].sp = -0xF0000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, Who, 0, Play_Style);
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 256;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, Who, 1, Play_Style);
    } else {
        ewk->wu.mvxy.a[0].sp = 0xF0000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, Who, 0, Play_Style);
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake - 256;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, Who, 1, Play_Style);
    }
}



s16 Get_PosK6(ewk, Who, Get_Type, Play_Style)
WORK_Other* ewk;
s16 Who;
s16 Get_Type;
s16 Play_Style;
{
    if (ewk->master_id == 0) {
        switch (ewk->wu.direction) {
        case 25:
        case 29:
            Who += chkNameAkuma(Who);
            {
                s16 x = Who;
                x = (Country != 1 && x == 21) ? 2 : 0;
                Who += x;
            }
            return Name_Cover_Pos_Data[ewk->master_id][Play_Style][Who][Get_Type];
        case 31:
        case 35:
            if (Play_Style == 1) {
                if (Get_Type == 0) {
                    return -160;
                } else {
                    return 44;
                }
            } else if (Get_Type == 0) {
                return -152;
            } else {
                return 208;
            }
            break;
        }
    } else {
        switch (ewk->wu.direction) {
        case 25:
        case 29:
            Who += chkNameAkuma(Who);
            return Name_Cover_Pos_Data[ewk->master_id][Play_Style][Who][Get_Type];
        case 31:
        case 35:
            if (Play_Style == 1) {
                if (Get_Type == 0) {
                    return 160;
                } else {
                    return 189;
                }
            } else if (Get_Type == 0) {
                return -152;
            } else {
                return 208;
            }
            break;
        }
    }
}



void Setup_CharK6(WORK_Other* ewk, s16 dm_vital) {
    s16 x;
    switch (dm_vital) {
    case 25:
    case 29:
        ewk->wu.char_index = 16;
        ewk->wu.dir_step = 0;
        ewk->wu.position_z = 71;
        break;
    case 31:
        ewk->wu.char_index = 15;
        x = Play_Type & 1;
        ewk->wu.dir_step = ewk->master_id + (x * 2);
        ewk->wu.position_z = 71;
        break;
    case 35:
        ewk->wu.char_index = 15;
        ewk->wu.dir_step = ewk->master_id + 2;
        ewk->wu.position_z = 71;
        break;
    }
}



s16 Setup_K6_Index(WORK_Other* ewk) {
    switch (ewk->wu.dir_old) {
    case 25:
    case 26:
    case 27:
    case 28:
        return ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
    case 29:
    case 30:
        return My_char[ewk->master_id];
    default:
        return ewk->wu.dir_step;
    }
}


/* Outside region 1, name 21 is shown with its alternative spelling, two entries on. */
s32 chkNameSuv(s16 name_no)
{
    if (Country != 1 && name_no == 21) {
        return 2;
    }
    return 0;
}
