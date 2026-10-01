/*
 * EFFE6.C  Ending scene objects (effect E6)
 *
 * The general-purpose sprite used by every character ending (END_1 to END_20).
 * effect_E6_init(char_num) reads family, position, priority, animation and behaviour type
 * from effe6_data_tbl and records the ending scene (end_w.r_no_2) it belongs to.
 * effect_E6_move dispatches on type to one of about thirty routines (effe6_0000-0030):
 * still or animated pictures that end with their scene, objects that scroll with the BG,
 * drift, rise or descend to a point, wrap around, wait for their scene, or raise
 * end_etc_flag to signal the ending script; one type is a joystick-driven positioning aid.
 * Objects remove themselves once the ending moves past their scene.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "textsound.h"
#include "effe6.h"



void effect_E6_move(WORK_Other* ewk) {
    void (*effe6_jp[31])(WORK_Other*) = { effe6_0000, effe6_0001, effe6_0002, effe6_0003, effe6_0004, effe6_0005, effe6_0006, effe6_0007, effe6_0007, effe6_0009, effe6_0010, effe6_0011, effe6_0012, effe6_0013, effe6_0014, effe6_0015, effe6_0016, effe6_0017, effe6_0018, effe6_0019, effe6_0020, effe6_0021, effe6_0022, effe6_0023, effe6_0024, effe6_0025, effe6_0026, effe6_0027, effe6_0028, effe6_0029, effe6_0030 };
    switch (ewk->wu.routine_no[2]) {
    case 0x0:
        effe6_jp[ewk->wu.routine_no[0]](ewk);
        break;
    case 99:
        ewk->wu.routine_no[2]++;
        break;
    case 100:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effe6_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    }
}



void effe6_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            char_move(&ewk->wu);
            disp_pos_trans_entry(ewk);
        }
        break;
    }
}



void effe6_0002(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            end_etc_flag = 1;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}

s32 effe6_0003(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if ((s8)ewk->wu.cg_type) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        disp_pos_trans_entry(ewk);
        return;
    }
}



void effe6_0004(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 1;
        ewk->wu.old_rno[5] = 1;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            ewk->wu.old_rno[5]--;
            if (ewk->wu.old_rno[5] <= 0) {
                ewk->wu.disp_flag ^= 1;
                ewk->wu.old_rno[5] = ewk->wu.old_rno[2];
            }
            disp_pos_trans_entry(ewk);
        }
        break;
    }
}



void effe6_0005(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].sp = 0x80000;
            ewk->wu.mvxy.d[0].sp = 0x40000;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        add_x_sub(ewk);
        if (ewk->wu.xyz[0].disp.pos > -1216) {
            ewk->wu.routine_no[2] = 99;
            ewk->wu.disp_flag = 0;
            end_etc_flag = 1;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    }
}



void effe6_0006(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = ewk->wu.xyz[0].disp.pos;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        if (ewk->wu.type == 73) {
            work = ewk->wu.old_rno[2] - 704;
        } else {
            work = ewk->wu.old_rno[2] - 384;
        }
        if (work > bg_w.bgw[ewk->wu.my_family - 1].xy[0].disp.pos) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0007(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        switch (ewk->wu.type) {
        case 22:
            ewk->wu.my_col_code = 32;
            break;
        case 23:
            ewk->wu.my_col_code = 33;
            break;
        case 24:
        case 27:
        case 28:
            ewk->wu.my_col_code = 34;
            break;
        }
        ewk->wu.my_col_mode = 0x200;
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        if (ewk->wu.routine_no[0] & 1) {
            char_move(&ewk->wu);
        }
        switch (ewk->wu.type) {
        case 22:
        case 23:
        case 24:
        case 27:
        case 28:
            disp_pos_trans_entry_r4(ewk);
            break;
        default:
            disp_pos_trans_entry_r(ewk);
            break;
        }
        break;
    }
}



void effe6_0009(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.xyz[0].cal -= 0xB000;
        ewk->wu.xyz[1].cal += -0x1A000;
        if (ewk->wu.xyz[1].disp.pos < -199) {
            ewk->wu.routine_no[1]++;
            bg_w.bgw[0].r_no_1++;
            bg_w.bgw[1].r_no_1++;
        }
        char_move(&ewk->wu);
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        ewk->wu.xyz[1].cal += 0x800;
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0010(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[2] = 0;
        ewk->wu.old_rno[5] = 8;
        ewk->wu.my_col_mode = 0x200;
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.xyz[1].cal += 0x20000;
        if (ewk->wu.xyz[1].disp.pos > 160) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0xA00000;
            bg_w.bgw[0].r_no_1++;
        }
    case 2:
        effe6_0010_sub(ewk);
    case 3:
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void effe6_0010_sub(WORK_Other* ewk) {
    ewk->wu.old_rno[5]--;
    if (ewk->wu.old_rno[5] >= 0) {
        return;
    }
    ewk->wu.old_rno[5] = 8;
    ewk->wu.old_rno[2]++;
    if (ewk->wu.old_rno[2] >= 8) {
        ewk->wu.routine_no[1]++;
    }
    ewk->wu.old_rno[2] &= 7;
    ewk->wu.extra_col = effe6_0010_col_tbl[ewk->wu.old_rno[2]];
}



void effe6_0011(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 30;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[1]++;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (ewk->wu.old_rno[6] < end_w.r_no_2) {
            ewk->wu.routine_no[2] = 99;
        } else {
            if (ewk->wu.type == 30) {
                ewk->wu.xyz[1].cal -= 0x8000;
                if (ewk->wu.xyz[1].disp.pos <= 64) {
                    ewk->wu.routine_no[2] = 99;
                    ewk->wu.xyz[1].cal = 0x400000;
                }
            }
            disp_pos_trans_entry(ewk);
        }
        break;
    }
}



void effe6_0012(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[1].sp = -0x5000;
            ewk->wu.mvxy.d[1].sp = -0x2000;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < 48) {
            ewk->wu.routine_no[2] = 99;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0013(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        if (ewk->wu.type == 50) {
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0x400;
        } else {
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x400;
        }
        break;
    case 1:
        add_y_sub(ewk);
        if (ewk->wu.type == 50) {
            if (ewk->wu.xyz[1].disp.pos > 272) {
                ewk->wu.routine_no[2] = 99;
            }
        } else if (ewk->wu.xyz[1].disp.pos < 32) {
            ewk->wu.routine_no[2] = 99;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0014(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.old_rno[2] = 4;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[2] = 4;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 2;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;
            if (ewk->wu.my_mr.size.x <= 59) {
                ewk->wu.routine_no[1]++;
                set_char_move_init2(&ewk->wu, 0, 21, 9, 0);
                ewk->wu.old_rno[2] = 4;
            } else {
                ewk->wu.old_rno[2] = 3;
            }
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 3:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 3;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;
            if (ewk->wu.my_mr.size.x <= 55) {
                ewk->wu.routine_no[1]++;
                set_char_move_init2(&ewk->wu, 0, 21, 10, 0);
                ewk->wu.old_rno[2] = 4;
            }
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.old_rno[2] = 4;
            ewk->wu.my_mr.size.x--;
            ewk->wu.my_mr.size.y--;
            if (ewk->wu.my_mr.size.x <= 0) {
                ewk->wu.routine_no[2] = 99;
                ewk->wu.my_mr.size.x = 0;
                ewk->wu.my_mr.size.y = 0;
            }
        }
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void effe6_0015(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 40;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[2], 544, 48, 2, 2);
        break;
    case 1:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1] = 3;
            ewk->wu.xyz[0].disp.pos = 544;
            ewk->wu.xyz[1].disp.pos = 48;
        } else {
            ewk->wu.old_rno[2]--;
            if (ewk->wu.old_rno[2] <= 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = 544;
                ewk->wu.xyz[1].disp.pos = 48;
            } else {
                add_x_sub(ewk);
                add_y_sub(ewk);
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1] = 3;
        } else {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[1] = 3;
            }
        }
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0016(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;
    case 1:
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            if (ewk->wu.routine_no[1] == 1) {
                ewk->wu.old_rno[2] = 10;
            } else {
                ewk->wu.old_rno[2] = 80;
            }
            ewk->wu.routine_no[1]++;
            char_move_z(&ewk->wu);
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    case 2:
    case 4:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[1]++;
        }
        break;
    case 5:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0017(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
            ewk->wu.old_rno[2] = 60;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[2] = 99;
            ewk->wu.disp_flag = 0;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0018(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 70;
        break;
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            effe6_init_common(ewk);
            disp_pos_trans_entry(ewk);
        }
        break;
    case 2:
        ewk->wu.xyz[1].cal += 0x10000;
        if (ewk->wu.xyz[1].disp.pos >= 48) {
            ewk->wu.routine_no[1]++;
        }
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0019(WORK_Other* ewk) {
    if (ewk->wu.old_rno[0] != end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 496;
            ewk->wu.xyz[1].disp.pos = 16;
            set_char_move_init2(&ewk->wu, 0, 37, 1, 0);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = 416;
            ewk->wu.xyz[1].disp.pos = 48;
            set_char_move_init2(&ewk->wu, 0, 37, 1, 0);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[2] = 99;
            end_etc_flag = 1;
            ewk->wu.disp_flag = 0;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0020(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 1;
        break;
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            effe6_init_common(ewk);
            disp_pos_trans_entry(ewk);
        }
        break;
    case 2:
        ewk->wu.xyz[1].cal += -0x18000;
        if (ewk->wu.xyz[1].disp.pos <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0;
        }
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0021(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 48;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.xyz[0].disp.pos >= 576) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].cal = 0x2400000;
        }
    case 2:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0022(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[2] = 180;
        break;
    case 1:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.mvxy.a[1].sp = 0x28000;
            effe6_init_common(ewk);
            disp_pos_trans_entry(ewk);
        }
        break;
    case 2:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        if (ewk->wu.xyz[1].disp.pos >= 48) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[1].cal = 0x300000;
        }
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0023(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.mvxy.a[0].sp = 0x12000;
        ewk->wu.mvxy.a[1].sp = 0x18000;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.xyz[1].cal -= ewk->wu.mvxy.a[1].sp;
        if (ewk->wu.xyz[1].disp.pos <= -208) {
            ewk->wu.xyz[0].cal = 0x1400000;
            ewk->wu.xyz[1].cal = 0x1300000;
        }
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0024(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (ewk->wu.old_rno[6] == end_w.r_no_2) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[2] = 0;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        char_move(&ewk->wu);
        if (ewk->wu.type == 138) {
            if (ewk->wu.xyz[0].disp.pos <= 640) {
                ewk->wu.routine_no[1]++;
            }
        } else if (ewk->wu.xyz[0].disp.pos >= 424) {
            ewk->wu.routine_no[1]++;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}



void effe6_0025(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        ewk->wu.old_rno[2] = 0;
        break;
    case 1:
        if (ewk->wu.type == 150) {
            if (p1sw_0 & 8) {
                ewk->wu.xyz[0].disp.pos++;
            }
            if (p1sw_0 & 4) {
                ewk->wu.xyz[0].disp.pos--;
            }
            if (p1sw_0 & 1) {
                ewk->wu.xyz[1].disp.pos++;
            }
            if (p1sw_0 & 2) {
                ewk->wu.xyz[1].disp.pos--;
            }
            tilemap_print_hex(8, 24, 14, ewk->wu.xyz[0].disp.pos, 4, 0);
            tilemap_print_hex(8, 25, 14, ewk->wu.xyz[1].disp.pos, 4, 0);
        } else {
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
            tilemap_print_hex(8, 26, 14, ewk->wu.xyz[0].disp.pos, 4, 0);
            tilemap_print_hex(8, 27, 14, ewk->wu.xyz[1].disp.pos, 4, 0);
            tilemap_print_hex(18, 26, 14, (u16)ewk->wu.cg_number, 4, 0);
            {
                u16 work = ~p2sw_1 & p2sw_0;
                if (work & 0x10) {
                    char_move_z(&ewk->wu);
                    ewk->wu.old_rno[2]++;
                    if (ewk->wu.old_rno[2] >= 7) {
                        ewk->wu.old_rno[2] = 0;
                    }
                }
            }
            switch (ewk->wu.old_rno[2]) {
            case 0:
                ewk->wu.xyz[0].disp.pos = 608;
                break;
            case 1:
                ewk->wu.xyz[0].disp.pos = 609;
                break;
            case 2:
                ewk->wu.xyz[0].disp.pos = 610;
                break;
            case 3:
                ewk->wu.xyz[0].disp.pos = 607;
                break;
            case 4:
                ewk->wu.xyz[0].disp.pos = 606;
                break;
            case 5:
                ewk->wu.xyz[0].disp.pos = 611;
                break;
            }
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effe6_0026(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.xyz[1].disp.pos < 152) {
            ewk->wu.routine_no[1]++;
        }
    case 2:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effe6_0027(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            effect_E6_init(0xA7);
        }
    case 2:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effe6_0028(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.disp_flag = 1;
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effe6_0029(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 5;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.xyz[0].disp.pos < 224) {
            ewk->wu.routine_no[2] = 99;
            break;
        }
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.old_rno[2] = 5;
            ewk->wu.my_mr.size.x++;
            ewk->wu.my_mr.size.y++;
            if (ewk->wu.my_mr.size.x >= 127) {
                ewk->wu.routine_no[1]++;
                ewk->wu.my_mr.size.x = 127;
                ewk->wu.my_mr.size.y = 127;
            }
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        disp_pos_trans_entry5(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effe6_0030(WORK_Other* ewk) {
    if (ewk->wu.old_rno[6] < end_w.r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (end_etc_flag) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
            ewk->wu.old_rno[2] = 30;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[2]--;
        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[2] = 99;
        } else {
            disp_pos_trans_entry(ewk);
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effe6_init_common(WORK_Other* ewk) {
    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[4], ewk->wu.char_index, 0);
}



s32 effect_E6_init(u8 char_num) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 146;
    ewk->wu.be_flag = 1;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[0] = end_w.r_no_2;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = end_char_table;
    ewk->wu.my_col_code = 32;
    data_ptr = &effe6_data_tbl[char_num][0];
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.old_rno[6] = *data_ptr++;
    ewk->wu.old_rno[6] += end_w.r_no_2;
    ewk->wu.old_rno[4] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.char_index - 1;
    ewk->wu.routine_no[0] = *data_ptr;
    return 0;
}
