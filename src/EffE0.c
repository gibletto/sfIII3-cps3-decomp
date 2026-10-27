/*
 * EFFE0.C  Effect E0: opponent choice plates on the next-CPU screen
 *
 * Effect E0 (id 140) is created by effect_E0_init from next_cpu: the two choice plates and their
 * frame, positioned from Plate_Pos_Data_E0 on BG4.
 * effect_E0_move highlights the plate matching Temporary_EM as the player moves the choice
 * (Moving_Plate, Setup_Char_E0), and once Sel_EM_Complete is set flashes the chosen plate, marks
 * the selection finished and stays until the plate scrolls out of the BG range.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EffE0.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait until on the screen */
#define R0_SELECT       1       /* follow the choice */
#define R0_DECIDE       2       /* a frame, then the chosen pattern */
#define R0_FLASH        3       /* flash for 20 frames */
#define R0_HOLD         4       /* stay until scrolled out */
#define R0_KILL         5       /* (default) put the work back */



void effect_E0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 64)) {
            return;
        }
        ewk->wu.disp_flag = 1;
        if (ewk->wu.dm_vital == 1) {
            ewk->wu.routine_no[0] = R0_HOLD;
        } else {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_SELECT:
        if (Sel_EM_Complete[Player_id] != 0) {
            if (VS_Index[Player_id] >= 8) {
                ewk->wu.routine_no[0] = R0_HOLD;
            } else {
                ewk->wu.routine_no[0] = R0_DECIDE;
            }
            ewk->wu.dir_timer = 1;
        } else if (Moving_Plate[Player_id] != 0 && ewk->wu.dm_vital == 0) {
            if (--Moving_Plate_Counter[Player_id] == 0) {
                Moving_Plate[Player_id] = 0;
            }
            Setup_Char_E0(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case R0_DECIDE:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 20;
            if (Temporary_EM[Player_id] == ewk->wu.direction) {
                ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 38;
            } else {
                ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 37;
            }
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case R0_FLASH:
        if (Exec_Wipe == 0) {
            char_move(&ewk->wu);
        }
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            Sel_EM_Complete[Player_id] |= 0x80;
            ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 35;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case R0_HOLD:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 64)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    if (ewk->wu.dm_vital == 0 && Exec_Wipe == 0) {
        char_move(&ewk->wu);
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}


void Setup_Char_E0(WORK_Other* ewk) {
    ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 35;
    ewk->wu.dir_step = 0;
    if (ewk->wu.direction == Temporary_EM[Player_id]) {
        ewk->wu.char_index++;
    }
}



s32 effect_E0_init(s16 Direction, s16 dm_vital, s16 Pos_Type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 140;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 4;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.dm_vital = dm_vital;
    ewk->wu.direction = Direction;
    ewk->wu.xyz[0].disp.pos = Offset_BG_X[3] + bg_w.bgw[3].wxy[0].disp.pos + Plate_Pos_Data_E0[Pos_Type][0];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Plate_Pos_Data_E0[Pos_Type][1];
    ewk->wu.position_z = 17;
    if (Direction == 2) {
        ewk->wu.xyz[1].disp.pos -= 104;
        ewk->wu.position_z++;
    }
    if (dm_vital == 1) {
        ewk->wu.xyz[0].disp.pos += 3;
        ewk->wu.xyz[1].disp.pos--;
        ewk->wu.char_index = 17;
        ewk->wu.dir_step = Direction - 1;
    } else {
        Setup_Char_E0(ewk);
    }
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}
