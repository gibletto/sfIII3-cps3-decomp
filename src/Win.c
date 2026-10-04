/*
 * WIN.C  Short ending check
 *
 * Check_Short_Ending starts the short ending (G_No1 8, E_No0 10) for the winner in one region
 * (Version_Type 3) once the winner has beaten six opponents, outside versus play; it returns whether
 * it did.
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
#include "eff93.h"
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
#include "eff58.h"
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
#include "continue.h"
#include "Win.h"
#include "fighter.h"



/* provisional name */
s32 Check_Short_Ending(void) {
    if (Play_Type == 1) {
        return 0;
    }
    if (Version_Type == 3) {
        if (VS_Index[WINNER] >= 6) {
            G_No1 = 8;
            G_No2 = 4;
            E_No0 = 10;
            GO_No[0] = 0;
            GO_No[1] = 0;
            End_PL = My_char[WINNER];
            plw[WINNER].wu.operator = 0;
            Extra_Break = 0;
            sound_reg_level_set(0, 0);
            Control_Time = 481;
            Ending_init();
            Stock_My_char[WINNER] = My_char[WINNER];
            Stock_Player_Color[WINNER] = Player_Color[WINNER];
            Break_Com[WINNER][0] = 1;
            Final_Result_id = WINNER;
            WGJ_Target = WINNER;
            WGJ_Win = Win_Record[WINNER];
            WGJ_Score = Continue_Coin[WINNER] + Score[WINNER][0];
            return 1;
        }
    }
    return 0;
}



