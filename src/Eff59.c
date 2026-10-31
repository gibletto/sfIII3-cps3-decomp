/*
 * EFF59.C  Effects 59 and 60: attached select-screen parts, flashing stage object
 *
 * Effect 59 is a part attached to a master object (from Eff39, EFF69 and EFFA7). effect_59_init
 * sets its ID, BG family, depth and the EFF59_Correct_Data offset from the master.
 * effect_59_move keeps it at that offset from the master while it is on screen, hides it when it
 * leaves the BG range and frees it when the master goes away; Check_Break_Into_59 and
 * Check_Break_Into_59_ID04 follow the master's pattern and restart the name when a new
 * challenger breaks in.
 * Effect 60, at the end of the file, is a flashing stage object: effect_60_init creates it from
 * flash_obj_data61 and it blinks with a fixed period and animates (used by bg000 and bg050).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "sc_logo.h"
#include "sc_trans.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "charmove_2.h"
#include "Eff59.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "ta_sub.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF61.h"

/* routine_no[0], effect 59 */
#define R0_INIT         0       /* start the animation */
#define R0_ENTER        1       /* wait to come into the bg range */
#define R0_FOLLOW       2       /* follow the master while on screen */
#define R0_HIDE         3       /* hidden for a frame */
#define R0_BREAK        4       /* new challenger: pinned to the bg */
#define R0_KILL         99      /* (default) put the work back */

/* routine_no[0], effect 60 */
#define R0_FLASH        1       /* blink and animate until retired */
#define R0_END          2       /* hidden for a frame */

extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];
extern const s16 flash_obj_data61_2[];

/* 02006D48 */
const s16* flash_obj_data61[3] = {
    flash_obj_data61_0,
    flash_obj_data61_1,
    flash_obj_data61_2,
};


void effect_59_move(WORK_Other* ewk) {
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;
    if (mwk->wu.be_flag == 0) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = R0_HIDE;
        return;
    }
    Check_Break_Into_59_ID04(ewk);
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        return;
    case R0_ENTER:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 224)) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->wu.position_x + ewk->wu.vital_new;
        } else {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_FOLLOW:
        Check_Break_Into_59(ewk);
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 224)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        break;
    case R0_HIDE:
        ewk->wu.routine_no[0] = R0_KILL;
        return;
    case R0_BREAK:
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
        ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 128;
        sort_push_request4(&ewk->wu);
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->wu.position_x + ewk->wu.vital_new;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->wu.position_y + ewk->wu.vital_old;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z + ewk->wu.direction;
    sort_push_request4(&ewk->wu);
}



s32 Check_Break_Into_59(WORK_Other* ewk) {
    WORK_Other* mwk;
    if (ewk->wu.dm_vital == 5) {
        mwk = (WORK_Other*)ewk->my_master;
        if (ewk->wu.dir_step != mwk->wu.dir_step) {
            ewk->wu.dir_step = mwk->wu.dir_step;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
    }
}



s32 effect_59_init(WORK_Other* mwk, s16 Synchro_BG, s16 ID, s16 direction) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 59;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4400;
    ewk->wu.my_col_code = 0x2000;
    ewk->wu.my_family = Synchro_BG;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->my_master = (u32*)mwk;
    ewk->wu.char_index = 19;
    ewk->wu.dir_step = ID;
    ewk->wu.dm_vital = ID;
    ewk->wu.direction = direction;
    ewk->wu.vital_new = EFF59_Correct_Data[ID][SEL_POS_X];
    ewk->wu.vital_old = EFF59_Correct_Data[ID][SEL_POS_Y];
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos + ewk->wu.vital_new;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos + ewk->wu.vital_old;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.xyz[2].disp.pos + ewk->wu.direction;
    switch (ID) {
    case 4:
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        break;
    case 5:
        ewk->wu.dm_vital = ID;
        ewk->wu.char_index = 82;
        ewk->wu.dir_step = mwk->wu.dir_step;
        break;
    }
    return 0;
}



/* provisional name */
s32 Check_Break_Into_59_ID04(WORK_Other* ewk) {
    if (ewk->wu.dm_vital != 4 || ewk->wu.routine_no[0] == R0_BREAK) {
        return 0;
    }
    if (Break_Into) {
        ewk->wu.routine_no[0] = R0_BREAK;
        ewk->wu.my_family = 1;
        ewk->wu.position_z = 2;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        return 1;
    }
    return 0;
}



void effect_60_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 1;
        break;
    case R0_FLASH:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[1]--;
            if (ewk->wu.old_rno[1] <= 0) {
                ewk->wu.disp_flag ^= 1;
                ewk->wu.old_rno[1] = ewk->wu.old_rno[0];
                if (ewk->wu.hit_stop) {
                    char_move(&ewk->wu);
                }
            }
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_60_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    data_ptr = flash_obj_data61[type];
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 60;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = type;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set(&ewk->wu);
    return 0;
}



