/*
 * EFF54.C  Effects 54 and 55: parts of the blinking stage object, a sliding stage object
 *
 * effect_54_init creates two parts for an effect 53 parent from a position table.
 * effect_54_move animates them and copies the parent's display flag, so they blink with it.
 * Effect 55, at the end of the file, is a bg120 object that slides down, holds, slides up and
 * repeats.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF54.h"
#include "SYS_sub.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Eff59.h"
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
#include "sc_trans.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "sc_logo.h"

/* routine_no[0], effect_54_move */
#define R0_INIT         0       /* start the animation */
#define R0_MOVE         1       /* blink with the parent */

/* routine_no[0], effect_55_move */
#define R0_SLIDE        1       /* slide out to y 128 */
#define R0_HOLD         2       /* hold for a while */
#define R0_RETURN       3       /* slide back to y 96 */
#define R0_WAIT         4       /* wait, then go again */



void effect_54_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_MOVE:
        ewk->wu.disp_flag = oya->wu.disp_flag;
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}



s32 effect_54_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff29_data_tbl;
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 54;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->my_master = (u32*)oya;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2080;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = eng_char_table;
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}



void effect_55_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 3);
        break;
    case R0_SLIDE:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal += 0x3000;
            if (ewk->wu.xyz[1].disp.pos >= 128) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 300;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case R0_HOLD:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case R0_RETURN:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal -= 0x4000;
            if (ewk->wu.xyz[1].disp.pos <= 96) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 480;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case R0_WAIT:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0] = R0_SLIDE;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_55_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 55;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2080;
    ewk->wu.xyz[0].disp.pos = 511;
    ewk->wu.xyz[1].disp.pos = 96;
    ewk->wu.my_priority = 86;
    ewk->wu.position_z = 86;
    ewk->wu.hit_stop = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = brz_char_table;
    suzi_offset_set(&ewk->wu);
    return 0;
}

/* Start the flashing palette effect for one side (rl_flag 0 or 1). */
