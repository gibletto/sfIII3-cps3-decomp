/*
 * DEMO.C  Attract mode: logos, title and demonstration play
 *
 * Ck_Coin leaves the attract loop when a coin, service input or free-play start is seen.
 * CAPCOM_Logo runs the warning, CAPCOM logo and other intro screens (Logo_Warning,
 * Logo_Capcom, Logo_Etc); Title and Title_At_a_Dash run the title sequence and opening.
 * Play_Demo runs the current demo step from Demo_Jmp_Data; Setup_Demo_PL, Setup_Demo_Arts
 * and Setup_Demo_Stage pick the characters, super arts and stage for demonstration fights.
 * draw_operator_info and Set_Mode_Pos place operator text for the current screen mode.
 * Driven by the attract sequence in Game_Main.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Game_Main.h"
#include "bg_sub.h"
#include "Entry.h"
#include "SE.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "cmb_win.h"
#include "meta_col.h"
#include "sys_test.h"
#include "eeprom.h"
#include "sc_trans.h"
#include "bg000.h"
#include "PLCNT.h"
#include "Grade.h"
#include "lose_pl.h"
#include "PLS02.h"
#include "SLOWF.h"
#include "textsound.h"
#include "DEMO.h"



s32 Ck_Coin(void) {
    s16 pl = -1;
    if (Free_Play) {
        if (~p1sw_1 & p1sw_0 & 0x1000) {
            pl = 0;
        } else if (~p2sw_1 & p2sw_0 & 0x1000) {
            pl = 1;
        }
        if (pl == -1) {
            return 0;
        }
        bg_vbl_trans_flag = 0;
        bookkeep_freeplay_count();
        if ((*&Game_setting).set5) {
            plw[0].wu.operator = 1;
            plw[1].wu.operator = 1;
            Operator_Status[0] = 1;
            Operator_Status[1] = 1;
            return 1;
        }
        plw[pl].wu.operator = 1;
        Operator_Status[pl] = 1;
        Champion = pl;
        plw[pl ^ 1].wu.operator = 0;
        Operator_Status[pl ^ 1] = 0;
        return 1;
    }
    if (coin_chute1_w[6] | coin_chute2_w[6]) {
        return 1;
    }
    return coin_chute1_w[1] | coin_chute2_w[1] | credit_1p | credit_2p;
}



/* provisional name */
void draw_operator_info(s32 y) {
    s16 y1;
    s16 y2;
    if (Country == 6 || Country == 5) {
        if (p1sw_0 & 0x10) {
            tilemap_print_string_attr(DE_X[18] + 36, y + 20, 18, Game_Data_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y1 = y + 21, 18, Income_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y2 = y + 22, 18, Service_msg);
            tilemap_print_string_attr(DE_X[18] + 31, y + 23, 18, Card_msg);
            tilemap_print_hex_block(DE_X[18] + 41, y1, 18, hex_to_bcd(book_coin_count[0]), 6, 0);
            tilemap_print_hex_block(DE_X[18] + 41, y2, 18, hex_to_bcd(book_coin_count[1]), 6, 0);
            tilemap_print_hex_block(DE_X[18] + 41, y + 23, 18, hex_to_bcd(book_coin_count[3]), 6, 0);
        } else {
            tilemap_clear_rect(DE_X[18] + 31, y + 20, DE_X[18] + 49, y + 23);
        }
    }
}



/* provisional name */
void Set_Mode_Pos(s16* value, s16 add, s16 init) {
    *value = init;
    if (Game_setting.mode) {
        *value += add;
    }
}



s32 CAPCOM_Logo(void) {
    void (*jmp_tbl[3])() = { Logo_Capcom, Logo_Warning, Logo_Etc };
    Next_Demo = 0;
    jmp_tbl[D_No[0]]();
    return Next_Demo;
}



/* provisional name */
void Logo_Capcom(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        tilemap_fill_all(0, 32);
        System_all_clear_Wait();
        bg_etc_write(4);
        Bg_Off_W(1);
        bg_pos_hosei2();
        Bg_Family_Set();
        D_Timer = 11;
        break;
    case 1:
        if (Request_Fade(93, 0)) {
            D_No[1]++;
        }
        break;
    case 2:
        if (Check_Fade_Complete()) {
            D_No[1]++;
        }
        break;
    case 3:
        if (--D_Timer <= 0) {
            D_No[1]++;
            ToneDown(0);
        }
        break;
    case 4:
        if (capcom_logo_anim()) {
            D_No[1]++;
            D_Timer = 0x100;
        }
        break;
    case 5:
        if (--D_Timer <= 0) {
            D_No[1]++;
        }
        break;
    case 6:
        if (Request_Fade(36, 0)) {
            D_No[1]++;
            Text_Fill_Lower(62, 30);
        }
        break;
    case 7:
        if (Check_Fade_Complete()) {
            D_No[1]++;
        }
        break;
    default:
        Next_Demo = 1;
        break;
    }
}



/* provisional name */
void Logo_Warning(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        D_Timer = 10;
        load_any_color(2);
        Text_Fill_Upper(0, 32);
        tilemap_print_string(DE_X[3], 0, 0xFFFF, parental_advisory_msg);
        break;
    case 1:
        if (--D_Timer == 0) {
            D_No[1]++;
            D_Timer = 120;
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    case 2:
        if (--D_Timer == 0) {
            if (Request_Fade(34, 0)) {
                D_No[1]++;
            } else {
                D_Timer = 1;
            }
        }
        break;
    case 3:
        if (Check_Fade_Complete()) {
            D_No[1]++;
        }
        break;
    default:
        Next_Demo = 1;
        break;
    }
}



/* provisional name */
void Logo_Etc(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        D_Timer = 10;
        Text_Fill_Upper(0, 32);
        System_all_clear_Wait();
        bg_etc_write(3);
        bg_pos_hosei2();
        Bg_Family_Set();
        break;
    case 1:
        if (--D_Timer == 0) {
            D_No[1]++;
            D_Timer = 120;
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    case 2:
        if (--D_Timer == 0) {
            if (Request_Fade(36, 0)) {
                D_No[1]++;
            } else {
                D_Timer = 1;
            }
        }
        break;
    case 3:
        if (Check_Fade_Complete()) {
            D_No[1]++;
        }
        break;
    default:
        Next_Demo = 1;
        break;
    }
}



s32 Title(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        D_Timer = 10;
        wipe_pattern_set(0, 7, 0);
        tilemap_fill_all(0, 32);
        load_any_color(39);
        load_any_color(2);
        Text_Page_Y = 32;
        Scrn_Move_Set(4, 0, 0x100);
        E_No[1] = 1;
        op_w.r_no_0 = 0;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        op_w.index = 0;
        op_work_clear();
        Get_Demo_Index = 0;
        break;
    case 1:
        D_No[1]++;
        load_char_eff_color(My_char[0], 0);
        load_char_eff_color(My_char[1], 1);
        break;
    case 2:
        set_EXE_flag();
        if (opening_demo_tick()) {
            D_No[1]++;
            D_Timer = 40;
        }
        break;
    case 3:
        if (--D_Timer == 0) {
            D_No[1]++;
            sc_vram_to_ram();
            Switch_Screen_Init(0, 1);
        }
        break;
    case 4:
        if (Switch_Screen()) {
            D_No[1]++;
            Cover_Timer = 22;
            Scrn_Move_Set(4, 0, 0);
        }
        break;
    default:
        return 1;
    }
    return 0;
}



s32 Title_At_a_Dash(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        Scrn_Move_Set(4, 0, 0);
        System_all_clear_Wait();
        load_any_color(39);
        load_any_color(2);
        op_w.r_no_0 = 2;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        op_w.index = 0;
        op_work_clear();
        break;
    case 1:
        if (opening_demo_tick()) {
            D_No[1]++;
            D_Timer = 20;
            credit_display_render(1);
            Disp_Start_Message();
        }
        break;
    default:
        if (--D_Timer == 0) {
            ToneDown(0);
            return 1;
        }
        break;
    }
    return 0;
}



s32 Play_Demo(void) {
    DEMO_JMP2 jmp_tbl;
    jmp_tbl = Demo_Jmp_Data;
    Next_Demo = 0;
    jmp_tbl.f[D_No[0]]();
    return Next_Demo;
}

s32 Demo00(void)
{
    s32 ret;

    ret = D_No[1];
    switch (ret) {
    case 0:
        D_No[1]++;
        G_No[2] = 0;
        Game_pause = 0;
        Conclusion_Flag = 0;
        appear_type = 1;
        Control_Time = 2048;
        Round_Level = 7;
        Text_Page_Y = 0;
        Weak_PL = random_16_com() & 1;
        return Text_Fill_Lower(0, 32);
    case 1:
        ret = ((s32 (*)())Game02)();
        if (--Cover_Timer == 0) {
            D_No[1]++;
            ret = ((s32 (*)())Switch_Screen_Init)(3, 3);
        }
        break;
    case 2:
        Game02();
        ret = Switch_Screen_Revival();
        if (ret != 0) {
            D_No[1]++;
            D_Timer = 1800;
            Stop_SG = 0;
        }
        break;
    case 3:
        Game02();
        if (--D_Timer == 1) {
            D_No[1]++;
            Stop_Combo = 1;
            ret = 1;
        } else {
            ret = Conclusion_Flag;
            if (ret != 0) {
                D_No[1]++;
                Stop_Combo = 1;
                D_Timer = 90;
            }
        }
        break;
    case 4:
        ret = ((s32 (*)())Game02)();
        if (--D_Timer == 0) {
            D_No[1]++;
            Game_pause = 1;
            ret = ((s32 (*)())Switch_Screen_Init)(5, 5);
        }
        break;
    case 5:
        Game02();
        ret = 0;
        if (Switch_Screen()) {
            D_No[1]++;
            sc_vram_to_ram();
            tilemap_clear_rect(DE_X[3] + 16, 10, DE_X[3] + 35, 20);
            ret = ((s32 (*)())Switch_Screen_Init)(3, 3);
        }
        break;
    case 6:
        Game02();
        ret = 0;
        if (Switch_Screen()) {
            D_No[1]++;
            Demo_Flag = 0;
            Cover_Timer = 23;
            ret = ((s32 (*)())voice_all_off)();
            if (++Select_Demo_Index > 3) {
                Select_Demo_Index = 0;
            }
        }
        break;
    default:
        Next_Demo = 1;
        break;
    }
    return ret;
}



void Demo01(void) {
    switch (D_No[1]) {
    case 0:
        D_No[1]++;
        Game_pause = 0;
        Demo_Step_Flag = 0;
        Text_Page_Y = 32;
        Text_Fill_Lower(0, 32);
        Before_Select_Sub();
        Setup_Select_Demo_PL();
        Setup_Demo_Arts();
        Weak_PL = random_16_com() & 1;
        clear_chainex_check(0);
        grade_check_work_1st_init(0, 0);
        grade_check_work_1st_init(0, 1);
        clear_chainex_check(1);
        grade_check_work_1st_init(1, 0);
        grade_check_work_1st_init(1, 1);
        break;
    case 1:
        Game01();
        if (Demo_Step_Flag) {
            D_No[1]++;
            G_No[2] = 0;
        }
        break;
    case 2:
        Game02();
        if (--Cover_Timer == 0) {
            D_No[1]++;
            Switch_Screen_Init(3, 3);
        }
        break;
    case 3:
        Game02();
        if (Switch_Screen_Revival()) {
            D_No[1]++;
            D_Timer = 1200;
            Stop_SG = 0;
        }
        break;
    case 4:
        Game02();
        if (--D_Timer == 1) {
            Stop_Combo = 1;
            Switch_Screen_Init(5, 5);
            return;
        }
        if (D_Timer == 0) {
            D_No[1]++;
            Demo_Step_Flag = 1;
            Game_pause = 1;
        }
        break;
    case 5:
        Game02();
        if (Switch_Screen()) {
            D_No[1]++;
            sc_vram_to_ram();
            tilemap_clear_rect(DE_X[3] + 16, 10, DE_X[3] + 35, 20);
            Switch_Screen_Init(3, 3);
        }
        break;
    case 6:
        Game02();
        if (Switch_Screen()) {
            D_No[1]++;
            Cover_Timer = 23;
            voice_all_off();
        }
        break;
    default:
        Next_Demo = 1;
        break;
    }
}



void Setup_Demo_PL(void) {
    My_char[0] = Demo_Char_Data[Demo_PL_Index][0];
    My_char[1] = Demo_Char_Data[Demo_PL_Index][1];
}



void Setup_Demo_Arts(void) {
    Super_Arts[0] = Arts_Rnd_Demo_Data[random_16_com() & 7];
    Super_Arts[1] = Arts_Rnd_Demo_Data[random_16_com() & 7];
    Player_Color[0] = 0;
    Player_Color[1] = 0;
}



void Setup_Demo_Stage(void) {
    s16 rnd = random_16_com() & 1;
    bg_w.area = 0;
    bg_w.stage = Demo_Stage_Play_Data[Demo_Stage_Index][rnd];
    Demo_Stage_Index += 1;
    if (++Demo_PL_Index > 3) {
        Demo_PL_Index = 0;
        Demo_Stage_Index = 0;
    }
}



void Setup_Select_Demo_PL(void) {
    plw[0].wu.operator = 0;
    plw[1].wu.operator = 0;
    Operator_Status[0] = 0;
    Operator_Status[1] = 0;
    plw[Demo_PL_Data[Select_Demo_Index]].wu.operator = 1;
    Operator_Status[Demo_PL_Data[Select_Demo_Index]] = 1;
}
