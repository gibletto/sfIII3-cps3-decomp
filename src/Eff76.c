/*
 * EFF76.C  Effect 76: screen objects of the select, versus, win and ranking screens
 *
 * Effect 76 is a general screen object created by effect_76_init(object number) from sel_pl,
 * next_cpu, Win, RANKING and Manage. Object numbers 0x2B-0x44 select the graphic (Setup_Char_76,
 * using the grade, the winner's character and the Akuma name check isAkumaName) and the position
 * (Setup_Pos_76, from EFF76_Pos_Data_A/B and EFF76_Face_Pos_Data).
 * effect_76_move runs a routine per state, driven by Order / Order_Timer: EFF76_WAIT,
 * EFF76_WAIT_BREAK_INTO, EFF76_SLIDE_IN, EFF76_SUDDENLY, EFF76_BEFORE, EFF76_SHIFT (slides the
 * object 160 pixels left) and EFF76_DIE (counts down, hides and frees it); Check_Range_Out ends
 * it when it leaves the BG range.
 * Setup_Color_76 (used by Setup_Char_76) and Setup_Color_L1 (used by the EFFL1 result plates) set
 * a work's colour code from the per-character palette table for the winner's character.
 * chkNameAkuma returns 1 for character 14 outside mode type 1, selecting the alternative name
 * graphic on the select and result screens.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "EFFA6.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Grade.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff76.h"

#pragma inline(isAkumaName)



void effect_76_move(WORK_Other* ewk) {
    EFF76_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}



void EFF76_WAIT(WORK_Other* ewk) {
    if (Check_Range_Out(ewk)) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 0;
        Order_Timer[ewk->wu.dir_old] = 1;
    } else if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}



void EFF76_WAIT_BREAK_INTO(WORK_Other* ewk) {
    if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}



void EFF76_SLIDE_IN(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }
                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_old] = 0;
            }
            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    }
}



void EFF76_SLIDE_OUT(WORK_Other* ewk) {}



void EFF76_SUDDENLY(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
    case 1:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital)) {
            break;
        }
        ewk->wu.disp_flag = 1;
        switch (ewk->wu.dir_old) {
        case 0x3D:
            ewk->wu.routine_no[1] = 2;
            break;
        case 0x42:
            ewk->wu.routine_no[1] = 3;
            break;
        default:
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            break;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 2:
        if (Next_Step) {
            ewk->wu.my_family = 1;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + EFF76_Pos_Data_B[ewk->wu.dir_old - 59][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }
        break;
    case 3:
        if (Next_Step) {
            ewk->wu.my_family = 4;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[3].wxy[0].disp.pos - 16;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 43][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }
        break;
    }
}



void EFF76_BEFORE(WORK_Other* ewk) {
    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }
    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    ewk->wu.position_z = 2;
    ewk->wu.routine_no[0] = 0;
    ewk->wu.routine_no[1] = 0;
    Order[ewk->wu.dir_old] = 0;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}



void EFF76_DIE(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
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



void EFF76_SHIFT(WORK_Other* ewk) {
    s16 cut;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 160;
            ewk->wu.mvxy.a[0].sp = -0x60000;
            ewk->wu.mvxy.d[0].sp = -0x4000;
        }
        break;
    case 1:
        cut = Cut_Cut_Sub(3);
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    }
}



s32 effect_76_init(s16 dir_old) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 76;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.dir_old = dir_old;
    ewk->wu.direction = 2;
    ewk->wu.dm_vital = Width_Data_76[dir_old - 43];
    Setup_Char_76(ewk);
    Setup_Pos_76(ewk);
    return 0;
}

/* provisional name */
static s16 isAkumaName(s16 pl) {
    if (Country != 1 && pl == 14) {
        return 1;
    }
    return 0;
}



void Setup_Pos_76(WORK_Other* ewk) {
    s16 ix;
    u8 my_char;
    switch (ewk->wu.dir_old) {
    case 0x2B:
    case 0x2C:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x40:
    case 0x42:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][2];
        break;
    case 0x41:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + EFF76_Face_Pos_Data[My_char[Final_Result_id]][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + EFF76_Face_Pos_Data[My_char[Final_Result_id]][1];
        ewk->wu.position_z = 72;
        break;
    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + EFF76_Pos_Data_B[ewk->wu.dir_old - 0x3B][0] + 458;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos + EFF76_Pos_Data_B[ewk->wu.dir_old - 0x3B][1];
        ewk->wu.position_z = EFF76_Pos_Data_B[ewk->wu.dir_old - 0x3B][2];
        break;
    case 0x43:
    case 0x44:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][2];
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 64;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 64;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        break;
    case 0x2D:
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][0];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][1];
        ewk->wu.position_z = EFF76_Pos_Data_A[ewk->wu.dir_old - 0x2B][2];
        if (Order_Dir[ewk->wu.dir_old] == 4) {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 32;
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 32;
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        break;
    case 0x48:
        ix = isAkumaName(My_char[Champion]);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                  Win_Name_Pos_Data[Champion][1][My_char[Champion] + ix][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Win_Name_Pos_Data[Champion][1][My_char[Champion] + ix][1];
        ewk->wu.position_z = 70;
        if (Champion == 0) {
            ewk->wu.xyz[0].disp.pos += 24;
            break;
        }
        ewk->wu.xyz[0].disp.pos -= 24;
        break;
    case 0x49:
        ix = isAkumaName(My_char[Champion]);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                  Win_Name_Pos_Data[Champion][1][My_char[Champion] + ix][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Win_Name_Pos_Data[Champion][1][My_char[Champion] + ix][1] - 2;
        ewk->wu.position_z = 69;
        if (Champion == 0) {
            ewk->wu.xyz[0].disp.pos += 23;
        } else {
            ewk->wu.xyz[0].disp.pos -= 25;
        }
        break;
    case 0x37:
    case 0x55:
        if (ewk->wu.dir_old == 0x37) {
            my_char = My_char[Winner_id];
        } else {
            my_char = Ranking_Data[Order_Dir[ewk->wu.dir_old]].player;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + EFF76_Face_Pos_Data[my_char][0] - 48;
        ewk->wu.hit_quake = bg_w.bgw[0].wxy[0].disp.pos + EFF76_Face_Pos_Data[my_char][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + EFF76_Face_Pos_Data[my_char][1];
        if (ewk->wu.dir_old == 0x37) {
            ewk->wu.position_z = 72;
            ewk->wu.mvxy.a[0].sp = 0x10000;
            ewk->wu.mvxy.d[0].sp = 0;
            break;
        }
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + EFF76_Face_Pos_Data[my_char][1] - 32;
        if (Order[ewk->wu.dir_old] == 1) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos + EFF76_Face_Pos_Data[my_char][0] + 384;
        }
        ewk->wu.position_z = 79;
        ewk->wu.mvxy.a[0].sp = -0xA0000;
        ewk->wu.mvxy.d[0].sp = 0;
        return;
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
        if (Perfect_Flag) {
            ix = 1;
        } else {
            ix = 0;
        }
        ewk->wu.hit_quake =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + EFF76_Score_Pos_Data[ix][Order_Dir[ewk->wu.dir_old]][0];
        ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake + 0x1A0;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  EFF76_Score_Pos_Data[ix][Order_Dir[ewk->wu.dir_old]][1] + base_y_pos;
        ewk->wu.position_z = EFF76_Score_Pos_Data[ix][ewk->wu.dir_old - 0x4A][2];
        ewk->wu.mvxy.a[0].sp = -0x18000;
        ewk->wu.mvxy.d[0].sp = -0x28000;
        break;
    }
}



void Setup_Char_76(WORK_Other* ewk) {
    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_family = 1;
        ewk->wu.char_index = 19;
        ewk->wu.dir_step = 4;
        ewk->wu.direction = 0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        break;
    case 0x39:
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 7;
        Setup_Color_76(ewk);
        break;
    case 0x3A:
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 8;
        break;
    case 0x36:
        ewk->wu.my_family = 1;
    case 0x34:
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.char_index = 9;
        ewk->wu.dir_step = My_char[Winner_id] + 0x15;
        ewk->wu.dir_step += isAkumaName(My_char[Winner_id]);
        break;
    case 0x2D:
    case 0x30:
    case 0x31:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        break;
    case 0x43:
    case 0x44:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = 2;
        ewk->wu.direction = 3;
        effect_A6_init(ewk);
        break;
    case 0x2E:
    case 0x2F:
        ewk->wu.my_family = 1;
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        Setup_Color_76(ewk);
        break;
    case 0x2B:
    case 0x2C:
        ewk->wu.char_index = 4;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x2B;
        Setup_Color_76(ewk);
        break;
    case 0x37:
    case 0x55:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 64;
        ewk->wu.char_index = 2;
        ewk->wu.direction = 3;
        if (ewk->wu.dir_old == 0x37) {
            ewk->wu.dir_step = My_char[Winner_id];
        } else {
            ewk->wu.dir_step = Ranking_Data[Order_Dir[ewk->wu.dir_old]].player;
            ewk->wu.direction = 7;
        }
        break;
    case 0x41:
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 64;
        ewk->wu.char_index = 2;
        ewk->wu.dir_step = My_char[Final_Result_id];
        ewk->wu.direction = 0;
        break;
    case 0x40:
        ewk->wu.my_family = 1;
    case 0x35:
        ewk->wu.char_index = 9;
        ewk->wu.dir_step = My_char[Winner_id];
        ewk->wu.dir_step += isAkumaName(My_char[Winner_id]);
        Setup_Color_76(ewk);
        break;
    case 0x3D:
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0x5F;
        ewk->wu.my_mr.size.y = 0x3F;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = 0x53;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x3B;
    case 0x3B:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        ewk->wu.direction = 3;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = 0x53;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x3B;
        break;
    case 0x32:
    case 0x33:
        ewk->wu.my_family = 1;
        ewk->wu.char_index = 0x56;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x32;
        ewk->wu.direction = 7;
        break;
    case 0x48:
        ewk->wu.my_family = 3;
        ewk->wu.char_index = 0x50;
        ewk->wu.dir_step = grade_get_my_grade(Champion);
        break;
    case 0x49:
        ewk->wu.my_family = 3;
        ewk->wu.char_index = 0x10;
        ewk->wu.dir_step = 8;
        break;
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x21E0;
        ewk->wu.char_index = 0x3D;
        ewk->wu.dir_step = ewk->wu.dir_old - 0x4A;
        break;
    }
}



/* provisional name */
s32 Check_Range_Out(WORK_Other* ewk) {
    if (!ewk->wu.disp_flag) {
        return 0;
    }
    return Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital);
}


void Setup_Color_76(ewk)
s32 ewk;
{
    ((WORK *)ewk)->my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2040;
}

void Setup_Color_L1(ewk)
s32 ewk;
{
    ((WORK *)ewk)->my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x40;
}

s32 chkNameAkuma(char_id)
s16 char_id;
{
    if (Country != 1 && char_id == 14) {
        return 1;
    }
    return 0;
}
