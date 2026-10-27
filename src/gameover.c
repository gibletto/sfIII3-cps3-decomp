/*
 * GAMEOVER.C  Game-over and short ending scenes
 *
 * GameOver_2nd and GameOver_3rd are the later steps of the game-over screen, Setup_Result_OBJ
 * starts the result display objects, and Short_Ending_Scene runs the short ending used in one
 * region.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "Eff93.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "end_main.h"
#include "EM_Cand.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "cmb_win.h"
#include "Eff95.h"
#include "EFFB8.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFF49.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "Eff76.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFL1.h"
#include "aboutspr.h"
#include "bg000.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "win_2.h"
#include "gameover.h"
#include "fighter.h"

/* GO_No[0] in Short_Ending_Scene */
#define SHORT_WIPE      0       /* save the screen and wipe */
#define SHORT_SETUP     1       /* set up the short ending screen */
#define SHORT_COVER     2       /* after Cover_Timer, wipe in */
#define SHORT_REVIVAL   3       /* finish the wipe */
#define SHORT_SHOW      4       /* show it for G_Timer */
#define SHORT_DONE      5       /* finished */



s16 Cont_No;  /* 0201700C */
s16 Cont_Sub_No;  /* 0201700E */
s16 Cont_Sub2_No;  /* 02017010 */
s16 Cont_Sub3_No;  /* 02017012 */
s16 Cont_Timer;  /* 02017014 */


void GameOver_2nd(void) {
    switch (GO_No[1]) {
    case GO2_START:
        GO_No[1]++;
    case GO2_FADE:
        if (Version_Type == 3 && Break_Com[Player_id][0]) {
            if (Request_Fade(108, 0) == 0) {
                break;
            }
            GO_No[1]++;
            load_char_gfx(0xA0F8, 1);
            break;
        }
        if (Request_Fade(97, 0) == 0) {
            break;
        }
        GO_No[1]++;
        Forbid_Break = 0;
        load_char_gfx(0xA0F8, 1);
        return;
    case GO2_FADE_WAIT:
        if (Check_Fade_Complete_SP() == 0) {
            break;
        }
        if (Game_setting.set5) {
            GO_No[0] = GO_DONE;
            break;
        }
        GO_No[1]++;
        Cover_Timer = 5;
        Suicide[3] = 1;
        Suicide[2] = 0;
        if (Version_Type != 3 || Break_Com[Player_id][0] == 0) {
            Setup_Result_OBJ();
            effect_76_init(65);
            Order[65] = 3;
            Order_Timer[65] = 1;
        } else {
            GO_No[1] = GO2_BREAK_COM;
            G_Timer = 5;
        }
        break;
    case GO2_RESULT_FADE:
        if (--Cover_Timer == 0) {
            if (Request_Fade(98, 0)) {
                GO_No[1]++;
                Forbid_Break = -1;
            } else {
                Cover_Timer = 1;
            }
        }
        break;
    case GO2_RESULT_IN:
        if (Check_Fade_Complete_SP()) {
            Forbid_Break = 0;
            bgm_request(47);
            Ignore_Entry[LOSER] = 0;
            if (E_Number[0][0] != ENTRY_NAME && E_Number[1][0] != ENTRY_NAME) {
                GO_No[1] += 2;
                G_Timer = 60;
                break;
            }
            GO_No[1]++;
        }
        break;
    case GO2_NAME_WAIT:
        if (E_Number[0][0] != ENTRY_NAME && E_Number[1][0] != ENTRY_NAME) {
            GO_No[1]++;
            G_Timer = 60;
        }
        break;
    case GO2_PAUSE:
        if (--G_Timer == 0) {
            GO_No[1]++;
            G_Timer = Result_Timer[Player_id];
        }
        break;
    case GO2_RESULT:
        if (Scene_Cut) {
            G_Timer = 1;
        }
        if (--G_Timer == 0) {
            GO_No[0]++;
            bgm_fade_out(0x222);
            WIN_X = 1;
        }
        break;
    case GO2_BREAK_COM:
        if (--G_Timer == 0) {
            Request_Fade(109, 0);
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            Check_Fade_Complete_SP();
            GO_No[1] = GO2_RESULT_FADE;
            Forbid_Break = 0;
            Setup_Result_OBJ();
            effect_76_init(65);
            Order[65] = 3;
            Order_Timer[65] = 1;
            effect_76_init(56);
            Order[56] = 3;
            Order_Timer[56] = 1;
        }
        break;
    }
}



void GameOver_3rd(void) {
    WIN_X = 1;
}



void Setup_Result_OBJ(void) {
    effect_76_init(0x32);
    Order[0x32] = 3;
    Order_Timer[0x32] = 1;
    effect_76_init(0x33);
    Order[0x33] = 3;
    Order_Timer[0x33] = 1;
    effect_L1_init(7);
    effect_L1_init(8);
    effect_L1_init(9);
    effect_L1_init(0xA);
    effect_L1_init(0xB);
    effect_L1_init(0xC);
    effect_L1_init(0xD);
    effect_L1_init(0xE);
}



/* provisional name */
s32 Short_Ending_Scene(void) {
    bg_pos_hosei_sub3(0);
    bg_pos_hosei_sub3(2);
    bg_pos_hosei_sub3(1);
    bg_pos_hosei_sub3(3);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(2);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(3);
    switch (GO_No[0]) {
    case SHORT_WIPE:
        GO_No[0]++;
        sc_vram_to_ram();
        Switch_Screen_Init(0, 1);
        break;
    case SHORT_SETUP:
        if (Switch_Screen() != 0) {
            GO_No[0]++;
            Cover_Timer = 24;
            Order[55] = 4;
            Order_Timer[55] = 1;
            System_all_clear_Wait();
            bg_etc_write(7);
            Setup_Virtual_BG(0, 0x200, 0);
        }
        break;
    case SHORT_COVER:
        if (--Cover_Timer == 0) {
            GO_No[0]++;
            Clear_Flash_No();
            Switch_Screen_Init(0, 1);
        }
        break;
    case SHORT_REVIVAL:
        if (Switch_Screen_Revival() != 0) {
            GO_No[0]++;
            G_Timer = 150;
            Ignore_Entry[LOSER] = 0;
        }
        break;
    case SHORT_SHOW:
        if (--G_Timer == 0) {
            GO_No[0]++;
        }
        break;
    case SHORT_DONE:
        return 1;
    }
    return 0;
}



