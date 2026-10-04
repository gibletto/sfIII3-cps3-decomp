/*
 * EFFH6_CODE.C  Effect H6: staff-roll text
 *
 * Effect H6 is one staff-roll line: effect_H6_init (from end_sub.c) builds its character sprites
 * from the string through code_tab ('#' lines are single pictures) and the entry type sets how it
 * slides in, holds and leaves at roll_rate. Lines are freed on Suicide[4].
 * end_cut_check reports whether the winner's player is holding an attack button to skip the
 * scene, unless end_no_cut is set.
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
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "end_main.h"
#include "effh6_code.h"



/* provisional name */
s32 end_cut_check(void) {
    u16 sw;
    if (!end_no_cut) {
        if (WINNER) {
            sw = p2sw_0;
        } else {
            sw = p1sw_0;
        }
        if (sw & 0x3F0) {
            return 1;
        }
    }
    return 0;
}



void effect_H6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        roll_rate = 1;
        roll_rate_t = 1;
        if (!ewk->wu.dir_step) {
            ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        break;
    case 1:
        if (ewk->wu.dir_step) {
            switch (ewk->wu.dir_step) {
            case 1:
                break;
            default:
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (256 <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            if (Suicide[4]) {
                ewk->wu.routine_no[0] = 2;
            }
            sort_push_request4(&ewk->wu);
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[5] >= ewk->wu.xyz[0].disp.pos) {
                    ewk->wu.xyz[0].disp.pos = ewk->wu.routine_no[5];
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 48;
                }
                break;
            case 1:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case 2:
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (512 <= ewk->wu.xyz[0].disp.pos) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case 1:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[6] <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.xyz[1].disp.pos = ewk->wu.routine_no[6];
                    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 30;
                }
                break;
            case 1:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case 2:
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (256 <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case 2:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[5] <= ewk->wu.xyz[0].disp.pos) {
                    ewk->wu.xyz[0].disp.pos = ewk->wu.routine_no[5];
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 48;
                }
                break;
            case 1:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case 2:
                ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - roll_rate;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                if (ewk->wu.xyz[0].disp.pos <= -128) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case 3:
            ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
            if (ewk->wu.dir_timer <= 0) {
                ewk->wu.routine_no[0]++;
            }
            break;
        case 4:
            switch (ewk->wu.routine_no[2]) {
            case 0:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (ewk->wu.routine_no[6] <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.xyz[1].disp.pos = ewk->wu.routine_no[6];
                    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                    ewk->wu.routine_no[2]++;
                    ewk->wu.dir_timer = ewk->wu.dir_timer - 60;
                }
                break;
            case 1:
                ewk->wu.dir_timer = ewk->wu.dir_timer - roll_rate_t;
                if (ewk->wu.dir_timer <= 0) {
                    ewk->wu.routine_no[2]++;
                }
                break;
            case 2:
                ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                if (256 <= ewk->wu.xyz[1].disp.pos) {
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
            break;
        case 5:
            break;
        case 6:
            ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos + roll_rate;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            if (256 <= ewk->wu.xyz[1].disp.pos) {
                ewk->wu.routine_no[0]++;
            }
            break;
        case 7:
            ewk->wu.xyz[1].disp.pos = ewk->wu.xyz[1].disp.pos - roll_rate;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            if (0 < ewk->wu.xyz[1].disp.pos) {
                break;
            }
            ewk->wu.routine_no[0]++;
            break;
        }
        if (Suicide[4]) {
            ewk->wu.routine_no[0] = 2;
        }
        sort_push_request3(&ewk->wu);
        break;
    case 2:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_H6_init(timer, str, X, Y, Original_Color, unused)
s16 timer;
s8* str;
s16 X;
s16 Y;
s16 Original_Color;
s32 unused;
{
    WORK_Other_CONN* ewk;
    s16 i;
    s16 x;
    s16 c;
    s8* su = str;
    if ((x = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[x];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 176;
    ewk->wu.type = 0;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_family = 6;
    ewk->wu.my_priority = ewk->wu.position_z = 20;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dir_timer = timer;
    if (*su == '#') {
        switch (Original_Color) {
        case 0:
            ewk->wu.dir_step = 1;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = Y;
            ewk->wu.my_col_code = Original_Color + 0x20A5;
            ewk->wu.cg_number = 0x95EE;
            ewk->wu.my_col_code = 0x20A0;
            ewk->wu.cg_number = 0x9E65;
            break;
        case 1:
            ewk->wu.dir_step = 2;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[6] = Y;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = -32;
            ewk->wu.my_col_code = 0x20A0;
            ewk->wu.cg_number = 0x9E62;
            break;
        default:
            ewk->wu.dir_step = 2;
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[6] = Y;
            ewk->wu.xyz[0].disp.pos = X;
            ewk->wu.xyz[1].disp.pos = -32;
            ewk->wu.my_col_code = 0x20A0;
            ewk->wu.cg_number = 0x9E63;
            break;
        }
        return 0;
    }
    ewk->wu.dir_step = 0;
    switch (Original_Color) {
    case 0:
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[5] = X;
        ewk->wu.xyz[0].disp.pos = 384;
        ewk->wu.xyz[1].disp.pos = Y;
        break;
    case 1:
        ewk->wu.routine_no[1] = 1;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = 0;
        break;
    case 2:
        Original_Color = 0;
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[5] = X;
        ewk->wu.xyz[0].disp.pos = -64;
        ewk->wu.xyz[1].disp.pos = Y;
        break;
    case 3:
        ewk->wu.routine_no[1] = 3;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = Y;
        break;
    case 4:
        Original_Color = 1;
        ewk->wu.routine_no[1] = 4;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = 0;
        break;
    case 5:
        Original_Color = 1;
        ewk->wu.routine_no[1] = 5;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = Y;
        break;
    case 6:
        ewk->wu.routine_no[1] = 6;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = -32;
        break;
    case 7:
        ewk->wu.routine_no[1] = 7;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = 256;
        break;
    case 8:
        ewk->wu.routine_no[1] = 6;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = -32;
        break;
    case 9:
        ewk->wu.dir_step = 2;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = Y;
        ewk->wu.xyz[0].disp.pos = X;
        ewk->wu.xyz[1].disp.pos = 0;
        ewk->wu.my_col_code = 0x20A0;
        break;
    }
    ewk->wu.my_col_code = 0;
    for (x = 0, i = 0; *su != '\0'; i += 9, su++) {
        if ((c = code_tab[*su]) == -1) {
            continue;
        }
        ewk->conn[x].nx = i;
        ewk->conn[x].ny = 0;
        switch (Original_Color) {
        case 8:
            ewk->conn[x].chr = c + 0x9E08;
            if (*su == '(') {
                ewk->conn[x].chr = 0x9E66;
            }
            if (*su == ')') {
                ewk->conn[x].chr = 0x9E67;
            }
            break;
        default:
            ewk->conn[x].chr = c + 0x9DC8;
            if (*su == '{') {
                ewk->conn[x].chr = 0x9E5B;
            }
            if (*su == '[') {
                ewk->conn[x].chr = 0x9E59;
            }
            if (*su == ']') {
                ewk->conn[x].chr = 0x9E56;
            }
            if (*su == '^') {
                ewk->conn[x].chr = 0x9E5D;
            }
            if (*su == '|') {
                ewk->conn[x].chr = 0x9E5E;
            }
            if (*su == '=') {
                ewk->conn[x].chr = 0x9E4A;
            }
            if (*su == '&') {
                ewk->conn[x].chr = 0x9E50;
            }
            if (*su == '-') {
                ewk->conn[x].chr = 0x9E49;
            }
            if (*su == '\"') {
                ewk->conn[x].chr = 0x9E43;
            }
            if (*su == '%') {
                ewk->conn[x].chr = 0x9E52;
            }
            if (*su == '|') {
                ewk->conn[x].chr = 0x9E5F;
            }
            if (*su == '(') {
                ewk->conn[x].chr = 0x9E4C;
            }
            if (*su == ')') {
                ewk->conn[x].chr = 0x9E4D;
            }
            if (*su == '*') {
                ewk->conn[x].chr = 0x9E58;
            }
            if (*su == '/') {
                ewk->conn[x].chr = 0x9E4B;
            }
            break;
        }
        ewk->conn[x].col = 0x20A0;
        x++;
    }
    ewk->num_of_conn = x;
    return 0;
}
