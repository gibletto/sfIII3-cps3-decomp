/*
 * RANKING.C  Ranking display screens
 *
 * Draws the score ranking. Ranking_Main runs either Ranking_00 (the attract-mode ranking shown
 * between demos) or Ranking_01 (the ranking shown during a game) step by step and returns 1
 * when finished. The steps clear the text layer, load the ranking background and effects,
 * change the BGM, flash the entries in, count down the display time and wipe out; Ranking_01
 * also sets up the next demo when needed.
 * Setup_Ranking_Obj, Setup_Name, Setup_Face, Setup_grade, Setup_Score/_Small and Setup_Wins
 * spawn the objects for each entry's name, portrait, grade, score and win count.
 * Ranking_Init loads the default table and, with the extra DIP switch set, inserts player 1's
 * present score into the top six.
 * Called from the game and attract-mode flow in Game_Main.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "Game_Main.h"
#include "demo00.h"
#include "demo01.h"
#include "demo02_code.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "cmb_win.h"
#include "sc_trans.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "eff65.h"
#include "eff66.h"
#include "Eff76.h"
#include "bg000.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "RANKING.h"



/* provisional name */
s32 Ranking_Main(void) {
    void (*jmp_tbl[2])() = { Ranking_01, Ranking_00 };
    Ranking_X = 0;
    jmp_tbl[D_No0]();
    return Ranking_X;
}



void Ranking_00(void) {
    void (*jmp_tbl[6])() = { Ranking_00_1st, Ranking_00_2nd, Ranking_00_3rd, Ranking_00_4th, Ranking_00_5th, Ranking_00_Last };
    Ranking_X = 0;
    jmp_tbl[D_No1]();
}

void Ranking_00_1st(void)
{
    D_No1++;
    Rank_Demo_Loop = 0;
    Flash_Sign[0] = 1;
    Ranking_Sub();
}



void Ranking_00_2nd(void) {
    s16 Char_Index;
    RANK_DATA* rd;
    D_No1++;
    D_Timer = 1;
    Rank_X = 0;
    Flash_Rank_Time = 0;
    Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos - 104;
    Rank_Pos_Y = bg_w.bgw[0].xy[1].disp.pos + 160;
    if (Rank_Type >= 10) {
        Order[85] = 3;
        Order_Timer[85] = 1;
        Order_Dir[85] = (u8)Rank_Type;
        effect_76_init(85);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 128, bg_w.bgw[0].xy[1].disp.pos + 80, 180, 10, 35, 5, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 120, bg_w.bgw[0].xy[1].disp.pos + 40, 180, 13, 35, 5, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 144, bg_w.bgw[0].xy[1].disp.pos + 68, 180, 7, 30, 5, 0);
        base_y_pos = 40;
        rd = Ranking_Data;
        switch (Rank_Type) {
        case 10:
            if (rd[10].cpu_grade == 0xFF) {
                Char_Index = 0;
            } else {
                Char_Index = rd[10].cpu_grade;
            }
            break;
        case 15:
            if (rd[15].grade == 0xFF) {
                Char_Index = 0;
            } else {
                Char_Index = rd[15].grade;
            }
            break;
        }
        effect_67_init(0, bg_w.bgw[0].xy[0].disp.pos - 136, bg_w.bgw[0].xy[1].disp.pos + 60, 180, Char_Index, 10, 6, 1);
        Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos - 72;
        Rank_Pos_Y = bg_w.bgw[0].xy[1].disp.pos + 120;
        Rank_Pos_X += 16;
        Rank_Pos_Y -= 48;
        Rank = Rank_Type;
        Rank_Pos_Y -= 1;
        Setup_Name(5);
        Rank_Pos_Y += 1;
        Rank_Pos_X += 16;
        Rank_Pos_Y += 1;
        Rank_Pos_Y += 256;
        Setup_Face(5);
        Rank_Pos_Y -= 256;
        Rank_Pos_Y -= 1;
        Rank_Pos_X -= 32;
        Rank_Pos_Y -= 40;
        if (Rank_Type == 10) {
            Rank_Pos_X -= 80;
            Setup_Score(5);
        } else {
            Rank_Pos_X -= 32;
            Setup_Wins2(5);
        }
    } else {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 143, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 4, 30, 5, 0);
        for (Rank = Rank_Type; Rank < (Rank_Type + 5); Rank++) {
            if ((Present_Rank[0] == (Rank - Rank_Type)) || (Present_Rank[1] == (Rank - Rank_Type))) {
                Flash_Rank_Interval = 1;
            } else {
                Flash_Rank_Interval = 0;
            }
            Setup_Name(5);
            if (Rank_Type == 0) {
                Setup_Score(5);
                Rank_Pos_X += 3;
                Setup_grade(5);
                Rank_Pos_X -= 3;
            } else {
                Setup_Wins(5);
                Setup_grade(5);
            }
            Setup_Face(5);
            Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos - 104;
            Rank_Pos_Y -= 32;
            Rank_X = 0;
            Flash_Rank_Time = 0;
        }
        if ((Present_Rank[0] < 5) || (Present_Rank[1] < 5)) {
            D_No1 += 1;
        } else {
            D_No1 = 4;
        }
    }
    switch (Rank_Type) {
    case 0:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 0, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 0, 10, 5, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 168, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 5, 20, 5, 0);
        break;
    case 5:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 0, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 2, 10, 5, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 168, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 5, 20, 5, 0);
        break;
    case 10:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 1, 10, 5, 0);
        break;
    case 15:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 3, 10, 5, 0);
        break;
    }
}



void Ranking_00_3rd(void) {
    if (Flash_Sign[0] == 1) {
        D_No1 = D_No1 + 1;
        D_Timer = 1;
    }
}



void Ranking_00_4th(void) {
    if (!(--D_Timer)) {
        D_No1++;
        D_Timer = 30;
        Flash_Sign[0] = 0;
        Flash_Sign[1] = 1;
    }
}

void Ranking_00_5th(void)
{
    if (--D_Timer == 0) {
        D_No1++;
        D_Timer = 300;
        Flash_Sign[1] = 0;
    }
}



/* provisional name */
void Ranking_00_Last(void) {
    if (--D_Timer == 0) {
        D_Timer = 1;
        Ranking_X = 1;
    } else if (D_Timer == 0x3C) {
        bgm_fade_out(0x222);
        return;
    }
}



void Ranking_01(void) {
    void (*jmp_tbl[5])() = { Ranking_01_1st, Ranking_01_2nd, Ranking_00_3rd, Ranking_01_4th, Ranking_01_5th };
    Ranking_X = 0;
    jmp_tbl[D_No1]();
}



void Ranking_01_1st(void) {
    D_No1 = D_No1 + 1;
    Suicide[0] = 0;
    tilemap_fill_all(0, 32);
    Present_Rank[0] = 99;
    Present_Rank[1] = 99;
    Ranking_Sub();
    effect_58_init(1, 1, -1);
    bgm_request(7);
}



void Ranking_01_2nd(void) {
    s16 Char_Index;
    RANK_DATA* rd;
    D_No1++;
    D_Timer = 420;
    Rank_X = 0;
    Flash_Rank_Time = 0;
    Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos - 104;
    Rank_Pos_Y = bg_w.bgw[0].xy[1].disp.pos + 160;
    Setup_Ranking_Obj();
    Setup_Score_Obj();
    if (Rank_Type == 0) {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 168, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 5, 20, 0, 0);
    } else {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 168, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 5, 20, 0, 0);
    }
    for (Rank = Rank_Type; Rank < (Rank_Type + 5); Rank++) {
        if ((Present_Rank[0] == (Rank - Rank_Type)) || (Present_Rank[1] == (Rank - Rank_Type))) {
            Flash_Rank_Interval = 1;
        } else {
            Flash_Rank_Interval = 0;
        }
        Setup_Name(0);
        if (Rank_Type == 0) {
            Setup_Score(0);
            Rank_Pos_X += 4;
            Setup_grade(0);
            Rank_Pos_X -= 4;
        } else {
            Setup_Wins(0);
            Setup_grade(0);
        }
        Setup_Face(0);
        Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos - 104;
        Rank_Pos_Y -= 32;
        Rank_X = 0;
        Flash_Rank_Time = 0;
    }
    Order[85] = 1;
    Order_Timer[85] = 180;
    Order_Dir[85] = Rank_Type + 10;
    effect_76_init(85);
    effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 512, bg_w.bgw[0].xy[1].disp.pos + 80, 180, 10, 35, 0, 0);
    effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 504, bg_w.bgw[0].xy[1].disp.pos + 40, 180, 13, 35, 0, 0);
    effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos + 240, bg_w.bgw[0].xy[1].disp.pos + 68, 180, 7, 30, 0, 0);
    base_y_pos = 40;
    rd = Ranking_Data;
    switch (Rank_Type) {
    case 0:
        if (rd[10].cpu_grade == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = rd[10].cpu_grade;
        }
        break;
    case 5:
        if (rd[15].grade == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = rd[15].grade;
        }
        break;
    }
    effect_67_init(0, bg_w.bgw[0].xy[0].disp.pos + 248, bg_w.bgw[0].xy[1].disp.pos + 60, 180, Char_Index, 10, 2, 1);
    Rank_Pos_X = bg_w.bgw[0].xy[0].disp.pos + 312;
    Rank_Pos_Y = bg_w.bgw[0].xy[1].disp.pos + 120;
    Rank_Pos_X += 16;
    Rank_Pos_Y -= 48;
    Rank = Rank_Type + 10;
    Rank_Pos_Y -= 1;
    Setup_Name(0);
    Rank_Pos_Y += 1;
    Rank_Pos_X += 16;
    Rank_Pos_Y += 1;
    Rank_Pos_Y += 256;
    Setup_Face(0);
    Rank_Pos_Y -= 256;
    Rank_Pos_Y -= 1;
    Rank_Pos_X -= 32;
    Rank_Pos_Y -= 40;
    if (Rank_Type == 0) {
        Rank_Pos_X -= 80;
        Setup_Score(0);
    } else {
        Rank_Pos_X -= 32;
        Setup_Wins2(0);
    }
    Rank -= 10;
    if ((Present_Rank[0] < 5) || (Present_Rank[1] < 5)) {
        D_No1++;
    } else {
        D_No1 = 4;
    }
}



void Ranking_01_4th(void) {
    if (!(--D_Timer)) {
        D_No1++;
        D_Timer = 240;
    }
}



void Ranking_01_5th(void) {
    switch (D_No2) {
    case 0:
        if (--D_Timer) {
            break;
        }
        D_No2++;
        if ((Demo_Flag == 0) && (Rank_Demo_Loop == 0)) {
            Text_Page_Y = 0;
            Setup_Demo_PL();
            Setup_Demo_Arts();
            Setup_Demo_Stage();
            Clear_Personal_Data(0);
            Clear_Personal_Data(1);
            Ranking_00_6th(0);
            Game01_Sub();
        }
        sc_vram_to_ram();
        Switch_Screen_Init(3, 3);
        break;
    case 1:
        if (Switch_Screen() != 0) {
            D_No2++;
            Cover_Timer = 24;
        }
        break;
    default:
        Ranking_X = 1;
        break;
    }
}

void Ranking_Sub(void)
{
    System_all_clear_Wait();
    if (Rank_Type == 0) {
        bg_etc_write(2);
    } else {
        bg_etc_write(11);
    }
    bg_pos_hosei2();
    Bg_Family_Set();
    load_any_color(4);
    load_any_color(5);
}



void Setup_grade(s16 y) {
    s16 Char_Index;
    switch (Rank_Type) {
    case 0:
        if ((Ranking_Data[Rank].cpu_grade) == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = Ranking_Data[Rank].cpu_grade;
        }
        break;
    case 5:
        if ((Ranking_Data[Rank].grade) == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = Ranking_Data[Rank].grade;
        }
    case 10:
        if ((Ranking_Data[Rank].cpu_grade) == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = Ranking_Data[Rank].cpu_grade;
        }
    case 15:
        if ((Ranking_Data[Rank].grade) == 0xFF) {
            Char_Index = 0;
        } else {
            Char_Index = Ranking_Data[Rank].grade;
        }
        break;
    }
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Char_Index + 98, 10, y, 0);
    if ((Rank_Type) == 0) {
        Rank_Pos_X += 16;
        if (Ranking_Data[Rank].all_clear) {
            Rank_Pos_Y += 16;
            effect_67_init(26, Rank_Pos_X - 4, Rank_Pos_Y + 3, 180, 74, 10, y, 0);
            Rank_Pos_Y -= 16;
        }
        Rank_Pos_X -= 16;
    }
    Rank_Pos_X += 48;
}



void Setup_Name(s16 y) {
    Name_Sub(0, y);
    Name_Sub(1, y);
    Name_Sub(2, y);
    if (Rank_Type == 0) {
        Rank_Pos_X;
    } else {
        Rank_Pos_X += 16;
    }
    Rank_X += 3;
}



void Name_Sub(s32 name_ix, s32 disp_y) {
    s16 xx = name_ix;
    s16 y = disp_y;
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Ranking_Data[Rank].name[xx], 10, y, 0);
    Flash_Rank_Time += Flash_Rank_Interval;
    Rank_Pos_X += 24;
}



void Setup_Face(s16 y) {
    Rank_Pos_Y += 16;
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Ranking_Data[Rank].player + 46, 10, y, 1);
    Flash_Rank_Time += Flash_Rank_Interval;
    Rank_Pos_X += 40;
    Rank_Pos_Y -= 16;
    Rank_X += 2;
    Flash_Rank_Time += Flash_Rank_Interval;
}



void Setup_Score(s16 y) {
    s16 i;
    s16 First_Digit;
    u32 xx;
    u32 Score_Buff;
    s16 Digit[8];
    Score_Buff = Ranking_Data[Rank].score;
    First_Digit = -1;
    for (i = 7, xx = 10000000; i > 0; i--, xx = xx / 10) {
        Digit[i] = Score_Buff / xx;
        Score_Buff -= Digit[i] * xx;
        if (First_Digit < 0) {
            if (Digit[i]) {
                First_Digit = i;
            }
        }
    }
    Digit[0] = Score_Buff;
    if (First_Digit < 0) {
        First_Digit = 0;
    }
    for (i = 0, xx = 7; i < 8; i++, xx--) {
        Flash_Rank_Time += Flash_Rank_Interval;
        Rank_Pos_X += 16;
        if (First_Digit < xx) {
            continue;
        }
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[xx] + 75, 10, y, 0);
    }
    Rank_Pos_X += 24;
}



/* provisional name */
void Setup_Score_Small(s16 y) {
    s16 i;
    s16 First_Digit;
    u32 xx;
    u32 Score_Buff;
    s16 Digit[7];
    Score_Buff = Ranking_Data[Rank].score;
    First_Digit = -1;
    for (i = 6, xx = 1000000; i > 0; i--, xx = xx / 10) {
        Digit[i] = Score_Buff / xx;
        Score_Buff -= Digit[i] * xx;
        if (First_Digit < 0) {
            if (Digit[i]) {
                First_Digit = i;
            }
        }
    }
    Digit[0] = Score_Buff;
    if (First_Digit < 0) {
        First_Digit = 0;
    }
    for (i = 0, xx = 6; i < 7; i++, xx--) {
        Flash_Rank_Time += Flash_Rank_Interval;
        Rank_Pos_X += 8;
        if (First_Digit < xx) {
            continue;
        }
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[xx] + 87, 10, y, 0);
    }
    Rank_Pos_X += 32;
}



void Setup_Wins(s16 y) {
    u32 Score_Buff;
    s16 Digit[3];
    Score_Buff = Ranking_Data[Rank].wins;
    Digit[2] = Score_Buff / 100;
    Score_Buff -= Digit[2] * 100;
    Digit[1] = Score_Buff / 10;
    Score_Buff -= Digit[1] * 10;
    Digit[0] = Score_Buff;
    if (Digit[2]) {
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[2] + 130, 10, y, 0);
        Rank_Pos_X += 16;
        effect_67_init(26, Rank_Pos_X + 3, Rank_Pos_Y, 180, Digit[1] + 130, 10, y, 0);
        Rank_Pos_X += 16;
    } else {
        Rank_Pos_X += 16;
        if (Digit[1]) {
            effect_67_init(26, Rank_Pos_X + 3, Rank_Pos_Y, 180, Digit[1] + 130, 10, y, 0);
        }
        Rank_Pos_X += 16;
    }
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(26, Rank_Pos_X + 6, Rank_Pos_Y, 180, Digit[0] + 130, 10, y, 0);
    Rank_Pos_X += 40;
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(24, Rank_Pos_X, Rank_Pos_Y, 180, 6, 10, y, 0);
    Rank_Pos_X += 64;
    Rank_X += 1;
}



void Setup_Wins2(s16 y) {
    u32 Score_Buff;
    s16 Digit[3];
    Score_Buff = Ranking_Data[Rank].wins;
    Digit[2] = Score_Buff / 100;
    Score_Buff -= Digit[2] * 100;
    Digit[1] = Score_Buff / 10;
    Score_Buff -= Digit[1] * 10;
    Digit[0] = Score_Buff;
    if (Digit[2]) {
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[2] + 75, 10, y, 0);
        Rank_Pos_X += 16;
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[1] + 75, 10, y, 0);
        Rank_Pos_X += 16;
    } else {
        Rank_Pos_X += 16;
        if (Digit[1]) {
            effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[1] + 75, 10, y, 0);
        }
        Rank_Pos_X += 16;
    }
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Digit[0] + 75, 10, y, 0);
    Rank_Pos_X += 40;
    effect_67_init(24, Rank_Pos_X, Rank_Pos_Y + 8, 180, 11, 10, y, 0);
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
}



void Setup_Ranking_Obj(void) {
    effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 143, bg_w.bgw[0].xy[1].disp.pos + 32, 180, 4, 30, 0, 0);
}



void Setup_Score_Obj(void) {
    if (Rank_Type == 0) {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 0, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 0, 10, 1, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 384, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 1, 10, 1, 0);
    } else {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 0, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 2, 10, 1, 0);
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos - 384, bg_w.bgw[0].xy[1].disp.pos + 200, 180, 3, 10, 1, 0);
    }
}


/* provisional name */
void Ranking_Init(void) {
    s16 ix;
    u16 j;
    RANK_DATA* dst = Ranking_Data;
    const RANK_DATA* src = Rank_Default_Data;
    RANK_DATA* entry;
    for (ix = 0; ix < 20; ix++) {
        *dst = *src;
        src++;
        dst++;
    }
    if (exsw_3 & 0x80) {
        /* insert player 1's present score into the top six */
        entry = &Present_Data[0];
        for (ix = 0; ix < 6; ix++) {
            if (Ranking_Data[ix].score < entry->score) {
                for (j = 4; j >= ix; j--) {
                    Ranking_Data[j + 1] = Ranking_Data[j];
                }
                Ranking_Data[ix] = *entry;
                break;
            }
        }
    }
}
