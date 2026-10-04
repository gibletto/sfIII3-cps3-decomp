/*
 * EFFF7.C  Effect F7: object viewer
 *
 * Effect F7 is a debug viewer for op_char_table objects: player 2 picks the object (0-25), zooms
 * it, toggles its priority and moves it, with the values printed on the text layer.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "efff7.h"



void effect_F7_move(WORK_Other* ewk) {
    s16 work;
    s16 mr;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = ewk->wu.old_rno[1];
        ewk->wu.my_mr.size.y = ewk->wu.old_rno[1];
        set_char_move_init2(&ewk->wu, 0, 3, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        switch ((s16)(p2sw_0 & ~p2sw_1)) {
        case 0x10:
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[0]++;
            if (ewk->wu.old_rno[0] >= 26) {
                ewk->wu.old_rno[0] = 0;
            }
            break;
        case 0x20:
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.old_rno[0] = 25;
            }
            break;
        case 0x40:
            ewk->wu.old_rno[1]++;
            if (ewk->wu.old_rno[1] > 127) {
                ewk->wu.old_rno[1] = 127;
            }
            break;
        case 0x100:
            ewk->wu.old_rno[2] ^= 1;
            ewk->wu.my_priority = ewk->wu.position_z = ewk->wu.old_rno[2] ? 10 : 100;
            break;
        case 0x200:
            ewk->wu.old_rno[1]--;
            if (ewk->wu.old_rno[1] < 0) {
                ewk->wu.old_rno[1] = 0;
            }
            break;
        }
        if (p2sw_0 & 8) {
            ewk->wu.xyz[0].disp.pos++;
        }
        if (p2sw_0 & 4) {
            ewk->wu.xyz[0].disp.pos--;
        }
        if (p2sw_0 & 1) {
            ewk->wu.xyz[1].disp.pos++;
        }
        if (p2sw_0 & 2) {
            ewk->wu.xyz[1].disp.pos--;
        }
        work = debug_hex4_to_bcd(ewk->wu.old_rno[0]);
        tilemap_print_hex(8, 4, 14, work, 4, 0);
        mr = ewk->wu.old_rno[1] - 63;
        if (mr < 0) {
            tilemap_print_string_attr(7, 6, 14, "-");
            mr = -mr;
        } else {
            tilemap_print_string_attr(7, 6, 14, " ");
        }
        work = debug_hex4_to_bcd(mr);
        tilemap_print_hex(8, 6, 14, work, 4, 0);
        tilemap_print_hex(8, 8, 14, ewk->wu.xyz[0].disp.pos, 4, 0);
        tilemap_print_hex(8, 10, 14, ewk->wu.xyz[1].disp.pos, 4, 0);
        ewk->wu.my_mr.size.x = ewk->wu.old_rno[1];
        ewk->wu.my_mr.size.y = ewk->wu.old_rno[1];
        disp_pos_trans_entry5(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_F7_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 157;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 192;
    ewk->wu.char_table[0] = op_char_table;
    ewk->wu.xyz[0].cal = 0x2000000;
    ewk->wu.xyz[1].cal = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 100;
    ewk->wu.old_rno[0] = 0;
    ewk->wu.old_rno[2] = 0;
    ewk->wu.old_rno[1] = 63;
    tilemap_print_string_attr(2, 2, 14, effF7_blk_msg);
    tilemap_print_string_attr(2, 4, 14, effF7_obj_msg);
    tilemap_print_string_attr(2, 6, 14, effF7_mr_msg);
    tilemap_print_string_attr(2, 8, 14, effF7_pos_msg);
}

