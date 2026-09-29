/*
 * EFFL1.C  Effect L1: grade judgement and result plates
 *
 * Effect L1 draws the pieces of the grade judgement screens shown after a win and at the final
 * result. Win.c creates one work per item with effect_L1_init(type).
 * effect_L1_move sets the base data per type from effL1_base_data (priority, BG family, display
 * flag, delay, winner colour via Setup_Color_L1) and calls the item init from
 * effL1_item_init: win count (effL1_w_win_init), grade letters (effL1_w_grade_init, which starts
 * an effect M3 zoom per letter), the hidden opponent's grade (effL1_k_grade_init), score, the
 * per-category point bar graphs (grade_get_my_point_percentage) and the final-judge per-stage
 * ranks and totals (the effL1_f_xxx routines).
 * effL1_suuchi_bunkai_sub splits a number into digits; effL1_trans steps the pattern counter
 * and queues the work for drawing.
 * Type 10 cycles its characters on a timer; grade_data_disp is an empty per-frame hook.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "effM5.h"
#include "Eff76_COLOR.h"
#include "EFFECT.h"
#include "Grade.h"
#include "aboutspr.h"
#include "EFFL1.h"



void grade_data_disp(void) {}



void effect_L1_move(WORK_Other_CONN* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = effL1_base_data[ewk->wu.type][3];
        ewk->wu.dir_timer = effL1_base_data[ewk->wu.type][4];
        ewk->wu.old_cgnum = 0;
        ewk->wu.my_col_code = 64;
        if (effL1_base_data[ewk->wu.type][2]) {
            Setup_Color_L1((WORK_Other*)ewk);
        }
        ewk->wu.my_family = effL1_base_data[ewk->wu.type][1];
        ewk->wu.position_z = ewk->wu.my_priority = effL1_base_data[ewk->wu.type][0];
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
        ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos;
        effL1_item_init[ewk->wu.type](ewk);
        effL1_trans(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.type = 0;
            ewk->wu.disp_flag = 0;
            break;
        }
        switch (ewk->wu.type) {
        case 1:
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.dir_timer = 0;
                ewk->wu.disp_flag = 1;
            }
            grade_data_disp();
            break;
        case 10:
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.dir_timer = ewk->wu.dir_step;
                ewk->wu.direction = (ewk->wu.direction + 1) & ewk->wu.dir_old;
                for (i = 0; i < ewk->num_of_conn; i++) {
                    ewk->conn[i].chr = ewk->conn[ewk->num_of_conn + ewk->wu.direction].chr;
                }
            }
            break;
        }
        effL1_trans(&ewk->wu);
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



void effL1_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    sort_push_request3(ewk);
}



void effL1_w_win_init(WORK_Other_CONN* ewk) {
    s16 i;
    effL1_suuchi_bunkai_sub(ewk, WGJ_Win);
    ewk->num_of_conn = 3;
    for (i = 0; i < 3; i++) {
        ewk->conn[i] = gj_wins[i];
        ewk->conn[i].chr += ewk->wu.shell_ix[i];
    }
}



void effL1_w_grade_init(WORK_Other_CONN* ewk) {
    s16 i;
    ewk->wu.direction = grade_get_my_grade((s32)Winner_id);
    for (i = 0; i < 4; i++) {
        ewk->conn[i] = gj_grade[ewk->wu.direction][i];
        if (ewk->conn[i].chr < 0xA13B) {
            break;
        }
        effect_M3_init(ewk, i);
    }
    ewk->num_of_conn = ewk->conn[i].chr;
    ewk->wu.position_x -= 384;
}



void effL1_k_grade_init(WORK_Other_CONN* ewk) {
    s16 i;
    if (kakushi_op) {
        ewk->wu.direction = judge_item[kakushi_ix][1].grade;
    } else {
        ewk->wu.direction = judge_com[kakushi_ix].grade;
    }
    ewk->num_of_conn = 2;
    for (i = 0; i < 2; i++) {
        ewk->conn[i] = gj_loser[i];
    }
    ewk->conn[0].chr = gj_loser_face[My_char[kakushi_ix]];
    ewk->conn[1].chr += ewk->wu.direction;
    ewk->wu.position_x -= 384;
}



void effL1_w_score_init(WORK_Other_CONN* ewk) {
    s16 i;
    effL1_suuchi_bunkai_sub(ewk, WGJ_Score);
    ewk->num_of_conn = 8;
    for (i = 0; i < 8; i++) {
        ewk->conn[i] = gj_score[i];
        ewk->conn[i].chr += ewk->wu.shell_ix[i];
    }
    ewk->wu.position_x -= 384;
}



void effL1_w_graph_init(WORK_Other_CONN* ewk) {
    s16 i;
    ewk->wu.direction = grade_get_my_point_percentage((s32)Winner_id, (s16)(ewk->wu.type - 3));
    if (ewk->wu.direction) {
        ewk->wu.direction /= 2;
        if (ewk->wu.direction == 0) {
            ewk->wu.direction = 1;
        }
    }
    ewk->wu.dir_step = ewk->wu.direction % 10;
    ewk->wu.direction /= 10;
    for (i = 0; i < 6; i++) {
        ewk->conn[i] = gj_bar[i];
        ewk->conn[i].ny -= (ewk->wu.type - 3) * 4;
    }
    ewk->num_of_conn = ewk->wu.direction;
    if (ewk->wu.dir_step) {
        ewk->conn[ewk->num_of_conn].chr = (ewk->conn[ewk->num_of_conn].chr - 10) + ewk->wu.dir_step;
        ewk->num_of_conn++;
    }
    ewk->wu.position_x -= 384;
}



void effL1_k_graph_init(WORK_Other_CONN* ewk) {
    s16 i;
    if (kakushi_op) {
        ewk->wu.direction = grade_get_my_point_percentage((s32)kakushi_ix, (s16)(ewk->wu.type - 16));
    } else {
        ewk->wu.direction = grade_get_cm_point_percentage((s32)kakushi_ix, (s16)(ewk->wu.type - 16));
    }
    if (ewk->wu.direction) {
        ewk->wu.direction /= 2;
        if (ewk->wu.direction == 0) {
            ewk->wu.direction = 1;
        }
    }
    ewk->wu.dir_step = ewk->wu.direction % 10;
    ewk->wu.direction /= 10;
    for (i = 0; i < 6; i++) {
        ewk->conn[i] = gj_bar2[i];
        ewk->conn[i].ny -= (ewk->wu.type - 16) * 3;
    }
    ewk->num_of_conn = ewk->wu.direction;
    if (ewk->wu.dir_step) {
        ewk->conn[ewk->num_of_conn].chr = (ewk->conn[ewk->num_of_conn].chr - 10) + ewk->wu.dir_step;
        ewk->num_of_conn++;
    }
    ewk->wu.position_x -= 384;
}



void effL1_f_stage_p_init(WORK_Other_CONN* ewk) {

    s16 i;
    for (i = 0; i < 10; i++) {
        ewk->conn[i] = gj_f_stage_p[i];
        ewk->conn[i].chr += judge_final[WGJ_Target][Play_Type].fr_sort_data[i][0];
    }
    ewk->conn[i] = gj_f_stage_p[i];
    if (judge_final[WGJ_Target][Play_Type].vs_cpu_result[15] != -1) {
        ewk->num_of_conn = 11;
    } else {
        ewk->num_of_conn = 10;
        ewk->conn[9] = ewk->conn[10];
    }
    effL1_f_col_adjust(ewk, 6);
}



/* provisional name */
void effL1_f_col_adjust(WORK_Other_CONN* ewk, s16 n) {
    s16 i;
    if (Version_Type == 3) {
        ewk->num_of_conn = n;
        for (i = 0; i < n; i++) {
            ewk->conn[i].nx = ewk->conn[i].col;
            ewk->conn[i].col = 0;
        }
    } else {
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].col = 0;
        }
    }
}



void effL1_f_stage_r_init(WORK_Other_CONN* ewk) {
    s16 i;
    for (i = 0; i < 22; i++) {
        ewk->conn[i] = gj_f_stage_r[i];
        ewk->conn[i].chr += judge_final[WGJ_Target][Play_Type].fr_sort_data[i / 2][(i & 1) + 1];
    }
    ewk->num_of_conn = judge_final[WGJ_Target][Play_Type].fr_ix * 2;
    if (judge_final[WGJ_Target][Play_Type].vs_cpu_result[15] == -1) {
        ewk->conn[18].nx = ewk->conn[20].nx;
        ewk->conn[18].ny = ewk->conn[20].ny;
        ewk->conn[19].nx = ewk->conn[21].nx;
        ewk->conn[19].ny = ewk->conn[21].ny;
    }
    effL1_f_col_adjust(ewk, ewk->num_of_conn);
}



void effL1_f_grade_init(WORK_Other_CONN* ewk) {
    s16 i;
    ewk->wu.direction = judge_final[WGJ_Target]->grade;
    for (i = 0; i < 4; i++) {
        ewk->conn[i] = gj_grade[ewk->wu.direction][i];
        ewk->conn[i].nx += 184;
        ewk->conn[i].ny -= 64;
        if (ewk->conn[i].chr < 0xA13B) {
            break;
        }
    }
    ewk->num_of_conn = ewk->conn[i].chr;
}



void effL1_f_mk_spp_init(WORK_Other_CONN* ewk) {

    s16 i;
    s16 k = 0;
    if (judge_final[WGJ_Target][Play_Type].vs_cpu_result[15] == -1) {
        for (i = 0; i < 10; i++) {
            if (judge_final[WGJ_Target][Play_Type].fr_sort_data[i][3]) {
                ewk->conn[k] = gj_f_mk_spp[i];
                k++;
            }
        }
    } else {
        for (i = 0; i < 11; i++) {
            if (judge_final[WGJ_Target][Play_Type].fr_sort_data[i][3]) {
                ewk->conn[k] = gj_f_mk_spp_Q[i];
                k++;
            }
        }
    }
    ewk->num_of_conn = k;
    ewk->wu.dir_old = 3;
    ewk->wu.dir_step = 8;
    ewk->wu.direction = 0;
    ewk->conn[k].chr = 0xA173;
    ewk->conn[k + 1].chr = 0xA174;
    ewk->conn[k + 2].chr = 0xA175;
    ewk->conn[k + 3].chr = 0xA174;
    effL1_f_col_adjust(ewk, ewk->num_of_conn);
}



s32 effL1_f_mk_all_init(WORK_Other_CONN* ewk) {
    s16 i;
    s32 rc;
    ewk->num_of_conn = 6;
    for (i = 0; i < 6; i++) {
        ewk->conn[i] = gj_f_mk_all[i];
    }
    if ((rc = Version_Type) == 3) {
        return rc;
    }
    if (!(rc = judge_final[WGJ_Target][Play_Type].all_clear)) {
        return rc;
    }
    ewk->conn[4].nx -= 4;
    ewk->conn[5].nx -= 6;
    ewk->conn[5].chr++;
    return 0x46C;
}



void effL1_f_kz_cont_init(WORK_Other_CONN* ewk) {
    s16 i;
    effL1_suuchi_bunkai_sub(ewk, judge_final[WGJ_Target][Play_Type].keizoku);
    ewk->num_of_conn = 7;
    for (i = 0; i < 7; i++) {
        ewk->conn[i] = gj_f_kz_cont[i];
    }
    ewk->conn[6].chr += ewk->wu.shell_ix[0];
    ewk->conn[5].chr += ewk->wu.shell_ix[1];
}



void effL1_f_kz_spp_init(WORK_Other_CONN* ewk) {
    s16 i;
    effL1_suuchi_bunkai_sub(ewk, judge_final[WGJ_Target][Play_Type].sp_point);
    ewk->num_of_conn = 8;
    for (i = 0; i < 8; i++) {
        ewk->conn[i] = gj_f_kz_spp[i];
    }
    ewk->conn[7].chr += ewk->wu.shell_ix[0];
    ewk->conn[6].chr += ewk->wu.shell_ix[1];
}



void effL1_f_score_init(WORK_Other_CONN* ewk) {
    s16 i;
    effL1_suuchi_bunkai_sub(ewk, WGJ_Score);
    ewk->num_of_conn = 10;
    for (i = 0; i < 10; i++) {
        ewk->conn[i] = gj_f_score[i];
    }
    for (i = 0; i < 8; i++) {
        ewk->conn[i].chr += ewk->wu.shell_ix[i];
    }
}


void effL1_suuchi_bunkai_sub(WORK_Other_CONN* ewk, u32 tsc) {
    s16 i;
    for (i = 7; i > 0; i--) {
        ewk->wu.shell_ix[i] = tsc / bunkai_table_l1[i];
        tsc %= bunkai_table_l1[i];
    }
    ewk->wu.shell_ix[i] = tsc;
}



s32 effect_L1_init(s16 flag) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 211;
    ewk->wu.type = flag;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    return 0;
}
