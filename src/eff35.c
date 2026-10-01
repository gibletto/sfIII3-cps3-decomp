/*
 * EFF35.C  Bonus-stage objects (effect 35)
 *
 * Sprites for the bonus games' presentation: title pieces, props that slide or zoom in,
 * and result signs, all drawn from bns_char_table.
 * effect_35_init(wait, c_type) picks an entry of eff35_data_tbl (for some types the choice
 * depends on Country or on Bonus_Game_result); after the wait timer effect_35_move runs
 * one of seven behaviours eff35_0000-0006: static display, horizontal zoom-in, repeating
 * sliding pieces, a reaction to the bonus result, and pieces pinned to BG1. Several of
 * them set Next_Step when done and most exit early on Break_Into.
 * Created from Game_Main, Manage and the second bonus-stage BG init (bns11_init00).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "EFF58.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "eff35.h"


void effect_35_move(WORK_Other* ewk) {
    void (*eff35_jp[7])(WORK_Other*) = { eff35_0000, eff35_0001, eff35_0002, eff35_0003, eff35_0004, eff35_0005, eff35_0006 };
    eff35_jp[ewk->wu.routine_no[0]](ewk);
}



void eff35_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff35_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0x7F;
        ewk->wu.my_mr.size.y = 0x3F;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.my_mr.size.x -= 12;
        if (ewk->wu.my_mr.size.x <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.my_mr.size.x += 12;
        if (ewk->wu.my_mr.size.x >= 0x3F) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0x3F;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 3:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff35_0002(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        effect_58_init(6, 4, 0xA8);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff35_0003(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[4] = 0;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 99;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        if (ewk->wu.type == 2) {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[2][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[2][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = -0x78000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[3][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[3][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = 0x5C000;
            ewk->wu.mvxy.d[0].sp = 0;
        }
        break;
    case 2:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 99;
            break;
        }
        add_x_sub(ewk);
        if (ewk->wu.type == 2) {
            if (ewk->wu.xyz[0].disp.pos < 416) {
                ewk->wu.routine_no[1] = 1;
                ewk->wu.disp_flag = 0;
                ewk->wu.old_rno[4]++;
                ewk->wu.old_rno[4] &= 3;
                ewk->wu.old_rno[1] = eff35_03_b[ewk->wu.old_rno[4]];
            }
        } else if (ewk->wu.xyz[0].disp.pos > 768) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_rno[4]++;
            ewk->wu.old_rno[4] &= 3;
            ewk->wu.old_rno[1] = eff35_03_s[ewk->wu.old_rno[4]];
        }
        disp_pos_trans_entry(ewk);
        break;
    case 99:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff35_0004(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        if (pcon_rno[0] == 2 && pcon_rno[2] >= 3) {
            if (Bonus_Game_result >= 10 || Bonus_Game_ex_result >= 10) {
                ewk->wu.routine_no[1]++;
            } else {
                ewk->wu.routine_no[1] = 3;
            }
        } else {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        if ((u8)ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 8);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff35_0005(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_code = 0x5C;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



void eff35_0006(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_code = 0x5C;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



s32 effect_35_init(s16 wait_timer, s16 c_type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    u8 char_num;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 35;
    switch (c_type) {
    case 5:
        if (Country == 1) {
            char_num = 5;
        } else {
            char_num = 9;
        }
        break;
    case 7:
        if (Country == 1) {
            char_num = 7;
        } else {
            char_num = 8;
        }
        break;
    case 10:
        switch (Bonus_Game_result) {
        case 2:
            char_num = 11;
            break;
        case 3:
            char_num = 10;
            break;
        default:
            char_num = 10;
            ewk->wu.routine_no[1] = 99;
            Next_Step = 1;
            break;
        }
        break;
    default:
        char_num = c_type;
        break;
    }
    data_ptr = eff35_data_tbl[char_num];
    ewk->wu.be_flag = 1;
    ewk->wu.old_rno[1] = wait_timer;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = bns_char_table;
    ewk->wu.my_col_code = 0x80;
    ewk->wu.my_family = 2;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[3] = *data_ptr++;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr++;
    return 0;
}
