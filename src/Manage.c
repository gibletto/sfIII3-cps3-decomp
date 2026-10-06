/*
 * MANAGE.C  Round and match management
 *
 * Other routines: stage BGM selection (Check_Stage_BGM), win records (Disp_Win_Record),
 * request_center_message for the centre-screen messages and the FBI warning screen (FBI_Warning).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "manage_2.h"
#include "Manage.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "EM_Cand.h"
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
#include "sc_trans.h"
#include "cmb_win.h"
#include "VITAL.h"
#include "count.h"
#include "spgauge.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "EffG0.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "Eff81.h"
#include "effb2.h"
#include "Grade.h"
#include "appear.h"
#include "ta_sub.h"
#include "eff35.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "Eff76.h"
#include "EFF84.h"
#include "bg000.h"
#include "Win.h"
#include "win_2.h"
#include "continue.h"
#include "end_main.h"
#include "Entry.h"
#include "entry_2.h"



/* provisional name */
void FBI_Warning(void) {
    JMP_TBL2 jmp_tbl;
    jmp_tbl = FBI_Warning_Jmp_Data;
    jmp_tbl.fn[D_No0]();
}



/* provisional name */
void FBI_Warning_1st(void) {
    s16 x;
    switch (D_No1) {
    case 0:
        D_No1++;
        D_Timer = 120;
        Set_Mode_Pos(&x, 8, 21);
        tilemap_print_string_attr(x, 8, 18, FBI_msg);
        break;
    case 1:
        if (--D_Timer == 0) {
            D_No1++;
            scfont_page0_fill(0, 32);
            D_Timer = 40;
        }
        break;
    case 2:
        if (--D_Timer == 0) {
            if (G_No1 == 12) {
                G_No1 = 1;
                D_No3 = 0;
                D_No2 = 0;
                D_No1 = 0;
                D_No0 = 0;
                return;
            }
            G_No1++;
            D_No3 = 0;
            D_No2 = 0;
            D_No1 = 0;
            D_No0 = 0;
        }
        break;
    }
}



/* provisional name */
void FBI_Warning_2nd(void) {}



