/*
 * EFFH3.C  Effects H3 to H6: ending pictures, ending objects and staff-roll text
 *
 * Effect H3: effect_H3_init loads the picture palette and graphics, homes BG2 and creates five
 * still pictures from effH3_data_tbl, which effect_H3_move draws until they are freed.
 * Effect H4 grows an object from zoom 14 to full size while it moves (effH4_sp_tbl), then flies
 * it off the side of the screen.
 * Effect H5 objects read family, colour, pattern, position, priority and behaviour from
 * effH5_data_tbl; effH5_0000..0004 give a still frame, a loop, a single play, a bobbing flight
 * and a two-step move into place. They are freed when the ending scene changes.
 * Effect H6 is one staff-roll line: effect_H6_init (from end_sub.c) builds its character sprites
 * from the string through code_tab ('#' lines are single pictures) and the entry type sets how it
 * slides in, holds and leaves at roll_rate. Lines are freed on Suicide[4].
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "end_main.h"
#include "EFFH3.h"



void effect_H3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 58, ewk->wu.char_index + 1, 0);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_H3_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;
    load_any_color(0x8E);
    load_char_gfx(0xDC30, 1);
    bg_w.bgw[2].wxy[0].cal = bg_w.bgw[2].xy[0].cal = 0x2000000;
    bg_w.bgw[2].xy[1].cal = 0;
    bg_w.bgw[2].position_x = 512 - bg_w.pos_offset;
    bg_w.bgw[2].position_y = 0;
    end_fam_set(2);
    data_ptr = &effH3_data_tbl[0][0];
    for (i = 0; i < 5; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 173;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = etc2_char_table;
        ewk->wu.my_family = 3;
        ewk->wu.my_col_code = 1;
        ewk->wu.position_z = 40;
        ewk->wu.my_priority = 40;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
    }
    return 0;
}



void effect_H4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[1], ewk->wu.char_index, 0);
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 14;
        ewk->wu.my_mr.size.y = 14;
        ewk->wu.mvxy.a[0].sp = effH4_sp_tbl[ewk->wu.type][0];
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = effH4_sp_tbl[ewk->wu.type][2];
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(ewk);
        break;
    case 1:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.my_mr.size.x < 63) {
            ewk->wu.my_mr.size.x++;
            ewk->wu.my_mr.size.y++;
        } else {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.d[0].sp = effH4_sp_tbl[ewk->wu.type][1];
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(ewk);
        break;
    case 2:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.xyz[0].disp.pos < 288 || ewk->wu.xyz[0].disp.pos > 736) {
            ewk->wu.routine_no[1]++;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effect_H5_move(WORK_Other* ewk) {
    void (*H5_Jmp_Tbl[5])(WORK_Other*) = { effH5_0000, effH5_0001, effH5_0002, effH5_0003, effH5_0004 };
    H5_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
}



void effH5_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effH5_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[0] != end_w.r_no_2) {
            ewk->wu.routine_no[1] = 99;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effH5_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effH5_init_common(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[0] != end_w.r_no_2) {
            ewk->wu.routine_no[1] = 99;
            break;
        }
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effH5_0002(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effH5_init_common(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effH5_0003(WORK_Other* ewk) {
    if (ewk->wu.old_rno[0] != end_w.r_no_2) {
        ewk->wu.routine_no[1] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effH5_init_common(ewk);
        ewk->wu.old_rno[5] = 20;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], 512, 56, 1, 1);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (bg_w.bgw[0].r_no_1 == 2) {
            ewk->wu.routine_no[1]++;
            char_move_z(&ewk->wu);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[5] = 16;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], 512, 40, 1, 1);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]--;
            ewk->wu.old_rno[5] = 16;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], 512, 56, 1, 1);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effH5_0004(WORK_Other* ewk) {
    if (ewk->wu.old_rno[0] != end_w.r_no_2) {
        ewk->wu.routine_no[1] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effH5_init_common(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_priority = ewk->wu.position_z = 85;
            ewk->wu.old_rno[5] = 20;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], 474, 131, 1, 1);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[5] = 40;
            cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[5], 484, 141, 1, 1);
            char_move_z(&ewk->wu);
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        ewk->wu.old_rno[5]--;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[1]++;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
void effH5_init_common(WORK_Other* ewk) {
    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[4], ewk->wu.char_index, 0);
}



s32 effect_H5_init(u8 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 175;
    ewk->wu.be_flag = 1;
    ewk->wu.type = type;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[0] = end_w.r_no_2;
    ewk->wu.my_col_mode = 0x4200;
    data_ptr = effH5_data_tbl[type];
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.char_index - 1;
    ewk->wu.routine_no[0] = *data_ptr;
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
