/*
 * EFFA9.C  Effect A9: result-screen objects
 *
 * Effect A9 places sel_pl_char_table objects on BG3 from Position_Data_A9 for the win screen
 * (Win.c) and next-opponent screen (next_cpu.c); Setup_A9 sets per-object options and can
 * add an effect 59 companion.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "sc_trans.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Eff59.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "PLS02.h"
#include "effa9.h"



void effect_A9_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new)) {
            return;
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.routine_no[0]++;
        break;
    case 2:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        if (ewk->wu.char_index == 55) {
            if (E_07_Flag[LOSER]) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 20;
                sound_request(0x68);
            }
            break;
        }
        if (ewk->wu.char_index == 57) {
            char_move(&ewk->wu);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (--ewk->wu.dir_timer == 0) {
            if (ewk->wu.cg_type == 1) {
                ewk->wu.dir_timer = 1;
            } else {
                ewk->wu.routine_no[0] = 4;
            }
        }
        break;
    case 4:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
    sort_push_request4(&ewk->wu);
}



s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 109;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 4;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = Char_Index;
    ewk->wu.xyz[0].disp.pos = Offset_BG_X[3] + bg_w.bgw[3].wxy[0].disp.pos + Position_Data_A9[Pos_Index][0];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Position_Data_A9[Pos_Index][1];
    ewk->wu.xyz[2].disp.pos = Position_Data_A9[Pos_Index][2];
    ewk->wu.vital_new = Position_Data_A9[Pos_Index][3];
    Setup_A9(ewk, Char_Index, Option, Option2);
    return 0;
}



/* provisional name */
void Setup_A9(WORK_Other* ewk, s16 Char_Index, s16 Option, s16 Option2) {
    switch (Char_Index) {
    case 32:
        if (Option2) {
            effect_59_init(ewk, ewk->wu.my_family, 4, 1);
        }
    case 33:
    case 34:
    case 81:
    case 12:
    case 16:
    case 79:
    case 6:
    case 80:
    case 58:
    case 60:
    case 59:
        ewk->wu.dir_step = Option;
        break;
    }
}
