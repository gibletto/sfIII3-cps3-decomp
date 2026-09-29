/*
 * EFFC9.C  Effect C9: the judge girls
 *
 * Effect C9 is one of the judges who appear for a judgement decision. effect_C9_init (called
 * from PLCNTAPP.c) chooses the judge's character set for the stage, round and slot from
 * ag_sel_table, with colour and character table from ag_cc_table / ag_char_table.
 * effect_C9_move places her at app_pos_hosei relative to the screen centre with a shadow from
 * judge_gals_kage_tbl (character set 7 drops in using efy_data, with dust and a landing sound),
 * then when Event_Judge_Gals is raised plays her judging patterns and spawns the effect 37 flag
 * for the player she votes for (EJG_Index). setup_EJG_index fills EJG_Index: all votes go to the
 * winner when the judge grades differ by more than 5, otherwise from sel_ejg_ix_table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFF03.h"
#include "EFF37.h"
#include "EFFECT.h"
#include "bg_sub.h"
#include "CHARSET.h"
#include "EFFC9.h"



void effect_C9_move(WORK_Other* ewk) {
    s16 scrc;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        scrc = get_center_position();
        ewk->wu.xyz[0].disp.pos = app_pos_hosei[ewk->wu.type][0] + scrc;
        ewk->wu.xyz[1].disp.pos = app_pos_hosei[ewk->wu.type][1];
        ewk->wu.xyz[2].disp.pos = app_pos_hosei[ewk->wu.type][2] + 32;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = judge_gals_kage_tbl[ewk->wu.charset_id][0];
        ewk->wu.kage_hy = judge_gals_kage_tbl[ewk->wu.charset_id][1];
        ewk->wu.kage_prio = judge_gals_kage_tbl[ewk->wu.charset_id][2];
        ewk->wu.kage_char = judge_gals_kage_tbl[ewk->wu.charset_id][3];
        if (ewk->wu.type == 1) {
            ewk->wu.kage_hy -= 2;
        }
        set_char_move_init(&ewk->wu, 0, 0);
        if (ewk->wu.charset_id == 7) {
            ewk->wu.next_x = efy_data[0];
            ewk->wu.xyz[0].disp.pos += efy_data[1];
            ewk->wu.next_y = ewk->wu.xyz[1].disp.pos;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    case 1:
        if ((ewk->wu.dead_f == 1) || (Suicide[0] != 0)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if ((EXE_flag == 0) && (Game_pause == 0)) {
            char_move(&ewk->wu);
            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (ewk->wu.charset_id == 7) {
                    switch (ewk->wu.routine_no[2]) {
                    case 0:
                        ewk->wu.next_x -= 1;
                        if (ewk->wu.next_x > 0) {
                            break;
                        }
                        ewk->wu.routine_no[2] += 1;
                    case 1:
                        ewk->wu.mvxy.a[0].sp = efy_data[2];
                        ewk->wu.mvxy.d[0].sp = efy_data[3];
                        ewk->wu.mvxy.a[1].sp = efy_data[4];
                        ewk->wu.mvxy.d[1].sp = efy_data[5];
                        ewk->wu.mvxy.kop[0] = 2;
                        ewk->wu.routine_no[2] += 1;
                    case 2:
                        add_mvxy_speed(&ewk->wu);
                        cal_mvxy_speed(&ewk->wu);
                        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
                            ewk->wu.routine_no[2] += 1;
                            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
                            ewk->wu.mvxy.d[1].sp = 0;
                            ewk->wu.mvxy.a[1].sp = 0;
                            ewk->wu.mvxy.kop[0] = 1;
                            effect_03_init(&ewk->wu, 110);
                            sound_effect_request[309](ewk, 309);
                            char_move_z(&ewk->wu);
                        }
                        break;
                    default:
                        add_mvxy_speed(&ewk->wu);
                        cal_mvxy_speed(&ewk->wu);
                        break;
                    }
                }
                if (Event_Judge_Gals) {
                    ewk->wu.routine_no[1] += 1;
                    set_char_move_init(&ewk->wu, 0, 1);
                }
                break;
            case 1:
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[1] += 1;
                    set_char_move_init(&ewk->wu, 0, 2);
                    effect_37_init(&ewk->wu, ewk->wu.charset_id, EJG_Index[ewk->wu.type]);
                }
                break;
            case 2:
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[1] += 1;
                    Event_Judge_Gals -= 1;
                }
                break;
            case 3:
                if (Event_Judge_Gals < 0) {
                    ewk->wu.routine_no[1] += 1;
                }
            case 4:
                if (bg_w.stage == 8 && Round_num == 0) {
                    ewk->wu.routine_no[1] += 1;
                    ewk->wu.routine_no[2] = 0;
                } else {
                    ewk->wu.routine_no[1] += 9;
                }
                break;
            case 5:
                switch (ewk->wu.routine_no[2]) {
                case 0:
                    break;
                case 1:
                    add_mvxy_speed(&ewk->wu);
                    cal_mvxy_speed(&ewk->wu);
                    if (ewk->wu.mvxy.a[1].sp < -0x100000) {
                        ewk->wu.mvxy.d[1].sp = 0;
                    }
                    break;
                }
                break;
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_C9_init(PLW* arg0, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 129;
    ewk->wu.work_id = 16;
    ewk->wu.type = data;
    ewk->wu.charset_id = ag_sel_table[bg_w.stage][Round_num & 3][data];
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = ag_cc_table[ewk->wu.charset_id];
    ewk->wu.char_table[0] = ag_char_table[ewk->wu.charset_id];
    return 0;
}



void setup_EJG_index(void) {
    s16 i;
    s16 gra;
    if (judge_gals[0].grade < judge_gals[1].grade) {
        gra = judge_gals[1].grade - judge_gals[0].grade;
    } else {
        gra = judge_gals[0].grade - judge_gals[1].grade;
    }
    if (gra > 5) {
        if (Winner_id) {
            EJG_Index[0] = 1;
            EJG_Index[1] = 1;
            EJG_Index[2] = 1;
            EJG_Index[3] = 0xFF;
        } else {
            EJG_Index[0] = 0;
            EJG_Index[1] = 0;
            EJG_Index[2] = 0;
            EJG_Index[3] = 0xFF;
        }
    } else {
        for (i = 0; i < 4; i++) {
            EJG_Index[i] = sel_ejg_ix_table[Winner_id][Game_timer & 1][i];
        }
    }
}
