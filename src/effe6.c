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
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "effe6.h"



const s16 effe6_data_tbl[168][8] = {
    { 1, 0, 1, 512, 64, 80, 1, 0 },
    { 1, 0, 1, 512, 64, 80, 2, 0 },
    { 1, 0, 1, 512, 64, 80, 4, 0 },
    { 1, 0, 1, 576, 64, 78, 5, 0 },
    { 1, 0, 1, 512, 64, 80, 6, 0 },
    { 1, 0, 1, 512, 64, 82, 8, 0 },
    { 1, 1, 1, 512, 64, 80, 7, 0 },
    { 1, 0, 1, 480, 96, 80, 9, 0 },
    { 1, 1, 1, 512, 64, 78, 10, 4 },
    { 1, 0, 2, 512, 16, 80, 1, 0 },
    { 1, 0, 2, 512, 0, 80, 2, 0 },
    { 1, 0, 2, 512, 136, 80, 3, 0 },
    { 1, 1, 3, 608, 136, 80, 4, 0 },
    { 1, 1, 4, 432, 136, 80, 1, 17 },
    { 2, 1, 5, 512, 144, 78, 1, 1 },
    { 1, 0, 2, 704, 136, 80, 4, 0 },
    { 2, 2, 2, 512, 144, 80, 7, 0 },
    { 1, 1, 2, -256, 136, 80, 5, 6 },
    { 1, 1, 2, -640, 136, 80, 5, 6 },
    { 1, 0, 2, -1792, 136, 80, 6, 5 },
    { 1, 1, 2, -1024, 136, 80, 5, 6 },
    { 1, 1, 2, -1408, 136, 80, 5, 6 },
    { 3, 0, 6, 384, 768, 40, 1, 7 },
    { 3, 0, 6, 128, 544, 40, 1, 7 },
    { 3, 0, 7, 256, 160, 40, 1, 7 },
    { 1, 0, 8, 704, 384, 80, 1, 9 },
    { 1, 0, 9, 512, 80, 80, 1, 10 },
    { 3, 0, 7, 128, 0, 40, 1, 7 },
    { 3, 0, 7, -128, -160, 40, 1, 7 },
    { 1, 0, 9, 512, 64, 78, 2, 0 },
    { 1, 0, 9, 512, 128, 80, 3, 0 },
    { 1, 0, 10, 512, 64, 78, 1, 2 },
    { 3, 1, 9, 320, 896, 80, 5, 0 },
    { 3, 1, 9, 544, 928, 80, 6, 0 },
    { 3, 1, 9, 496, 832, 78, 7, 0 },
    { 2, 1, 9, 512, -256, 81, 4, 0 },
    { 1, 0, 13, 512, 166, 80, 1, 1 },
    { 1, 0, 11, 512, 64, 80, 2, 0 },
    { 1, 0, 11, 512, 64, 80, 3, 0 },
    { 1, 0, 11, 496, 64, 78, 4, 0 },
    { 1, 0, 11, 512, 96, 78, 5, 0 },
    { 1, 0, 12, 448, 144, 76, 1, 12 },
    { 1, 1, 14, 512, 686, 80, 1, 1 },
    { 1, 0, 15, 512, 136, 78, 1, 4 },
    { 2, 0, 15, 512, 136, 76, 2, 0 },
    { 1, 0, 15, 512, 136, 80, 3, 0 },
    { 1, 0, 16, 608, 80, 78, 1, 3 },
    { 1, 0, 15, 512, 136, 80, 4, 0 },
    { 1, 1, 15, 512, 136, 80, 5, 0 },
    { 1, 0, 16, 608, 80, 78, 1, 3 },
    { 1, 0, 17, 512, 96, 78, 1, 13 },
    { 1, 0, 17, 511, 64, 78, 2, 13 },
    { 1, 1, 17, 512, 80, 80, 3, 0 },
    { 1, 0, 17, 512, 64, 78, 4, 0 },
    { 2, 0, 17, 544, 64, 78, 5, 0 },
    { 1, 0, 17, 224, 96, 80, 6, 0 },
    { 2, 0, 21, 511, 64, 78, 1, 0 },
    { 1, 1, 18, 511, 136, 80, 1, 0 },
    { 1, 0, 18, 512, 136, 80, 2, 0 },
    { 1, 0, 18, 512, 136, 80, 3, 0 },
    { 1, 2, 18, 544, 136, 80, 4, 0 },
    { 1, 1, 20, 511, 136, 78, 1, 1 },
    { 1, 0, 21, 424, 824, 78, 2, 0 },
    { 1, 0, 21, 512, 376, 80, 3, 0 },
    { 1, 0, 21, 512, 304, 78, 4, 0 },
    { 2, 0, 21, 288, 64, 80, 5, 0 },
    { 1, 0, 22, 512, 64, 80, 1, 1 },
    { 1, 0, 21, 512, 144, 78, 6, 14 },
    { 1, 1, 21, 512, 376, 80, 7, 0 },
    { 1, 1, 21, 512, 304, 78, 8, 0 },
    { 1, 0, 23, 567, 136, 80, 1, 0 },
    { 1, 1, 23, 512, 136, 80, 2, 0 },
    { 1, 1, 24, 544, 88, 80, 1, 1 },
    { 1, 1, 2, 448, 136, 80, 8, 6 },
    { 1, 2, 17, 512, 64, 78, 7, 0 },
    { 1, 2, 25, 512, 80, 80, 1, 2 },
    { 1, 0, 26, 512, 64, 80, 1, 0 },
    { 2, 0, 26, 512, 464, 78, 2, 0 },
    { 3, 0, 26, 512, 400, 80, 3, 0 },
    { 6, 3, 26, 512, 496, 88, 4, 0 },
    { 1, 2, 26, 512, 64, 80, 5, 0 },
    { 1, 1, 27, 576, -64, 80, 1, 15 },
    { 1, 1, 26, 512, 64, 78, 7, 0 },
    { 1, 1, 26, 544, 80, 80, 8, 0 },
    { 1, 1, 27, 672, 48, 80, 6, 0 },
    { 1, 1, 28, 575, 136, 80, 1, 0 },
    { 1, 0, 28, 511, 136, 80, 2, 0 },
    { 1, 0, 28, 511, 136, 80, 3, 0 },
    { 1, 1, 28, 511, 136, 80, 4, 0 },
    { 1, 0, 30, 432, 64, 80, 1, 0 },
    { 1, 0, 31, 464, 64, 80, 1, 16 },
    { 1, 0, 32, 512, 64, 80, 1, 1 },
    { 1, 0, 26, 512, 64, 78, 9, 0 },
    { 2, 0, 33, 768, 136, 78, 2, 0 },
    { 3, 0, 33, 536, 392, 80, 3, 0 },
    { 2, 0, 33, 368, 320, 80, 4, 0 },
    { 1, 0, 36, 512, -112, 80, 1, 18 },
    { 1, 0, 37, 576, 0, 80, 1, 19 },
    { 1, 0, 36, 512, 232, 80, 2, 20 },
    { 1, 0, 36, 544, 48, 80, 3, 0 },
    { 1, 0, 38, 392, 48, 78, 1, 21 },
    { 1, 0, 36, 512, 64, 80, 5, 0 },
    { 1, 0, 36, 511, 64, 78, 6, 0 },
    { 1, 0, 36, 480, 64, 76, 7, 0 },
    { 1, 0, 36, 512, 112, 74, 8, 0 },
    { 1, 0, 36, 512, 48, 80, 9, 0 },
    { 1, 2, 36, 512, 48, 76, 10, 23 },
    { 1, 0, 36, 512, -64, 78, 11, 22 },
    { 1, 1, 36, 512, 48, 80, 12, 0 },
    { 1, 2, 36, 320, 304, 76, 10, 23 },
    { 1, 2, 36, 704, -208, 76, 10, 23 },
    { 1, 0, 39, 511, 64, 80, 1, 1 },
    { 1, 0, 40, 511, 64, 80, 1, 1 },
    { 1, 0, 41, 511, 64, 80, 1, 1 },
    { 1, 0, 42, 511, 64, 80, 1, 1 },
    { 1, 0, 43, 511, 80, 80, 1, 1 },
    { 1, 3, 45, 560, 64, 78, 1, 0 },
    { 1, 0, 45, 512, 64, 78, 2, 0 },
    { 1, 0, 45, 512, 64, 80, 3, 0 },
    { 1, 0, 44, 495, 64, 80, 1, 1 },
    { 1, 0, 45, 512, 64, 80, 4, 0 },
    { 1, 1, 65, 544, 64, 80, 1, 29 },
    { 1, 0, 45, 560, 64, 78, 1, 0 },
    { 3, 0, 46, 128, 0, 80, 1, 0 },
    { 1, 0, 47, 304, 0, 78, 1, 1 },
    { 1, 0, 48, 511, 0, 80, 1, 1 },
    { 1, 0, 49, 512, 0, 78, 1, 1 },
    { 3, 0, 46, 560, 0, 78, 2, 0 },
    { 3, 1, 50, 512, 0, 78, 1, 1 },
    { 2, 0, 1, 416, 64, 78, 3, 0 },
    { 3, 0, 1, 576, 64, 80, 12, 0 },
    { 2, 0, 1, 512, 64, 78, 11, 0 },
    { 1, 0, 52, 671, 160, 78, 1, 28 },
    { 1, 0, 53, 567, 184, 78, 1, 28 },
    { 1, 0, 54, 551, 96, 78, 1, 28 },
    { 1, 0, 55, 319, 128, 78, 1, 28 },
    { 1, 1, 61, 512, 208, 78, 1, 1 },
    { 1, 1, 66, 512, 176, 79, 1, 26 },
    { 1, 1, 60, 704, 135, 76, 1, 24 },
    { 1, 1, 67, 368, 135, 76, 1, 24 },
    { 1, 1, 57, 448, 208, 77, 1, 1 },
    { 1, 1, 58, 576, 208, 77, 1, 1 },
    { 1, 0, 26, 512, 64, 78, 10, 0 },
    { 1, 0, 56, 512, 135, 78, 6, 0 },
    { 1, 1, 59, 512, 136, 78, 1, 27 },
    { 1, 0, 21, 208, 992, 80, 11, 0 },
    { 1, 0, 64, 120, 1016, 78, 1, 1 },
    { 1, 0, 64, 104, 1048, 82, 1, 1 },
    { 1, 0, 64, 304, 1008, 78, 1, 1 },
    { 1, 0, 64, 264, 1040, 82, 1, 1 },
    { 1, 0, 15, 512, 136, 80, 3, 0 },
    { 1, 0, 16, 608, 80, 78, 1, 25 },
    { 2, 0, 15, 512, 136, 76, 6, 0 },
    { 1, 2, 18, 512, 136, 79, 5, 0 },
    { 1, 0, 62, 512, 64, 80, 1, 0 },
    { 1, 0, 62, 512, 64, 80, 2, 0 },
    { 1, 0, 26, 512, 64, 78, 11, 0 },
    { 1, 0, 62, 511, 512, 80, 4, 0 },
    { 1, 0, 62, 512, 64, 80, 5, 0 },
    { 1, 0, 62, 464, 80, 80, 6, 30 },
    { 1, 1, 62, 480, 64, 80, 7, 0 },
    { 1, 0, 63, 256, 64, 80, 1, 0 },
    { 1, 1, 45, 576, 64, 78, 6, 0 },
    { 1, 0, 63, 512, 64, 78, 3, 0 },
    { 1, 0, 63, 512, 64, 80, 4, 0 },
    { 1, 0, 26, 544, 48, 78, 12, 0 },
    { 1, 1, 63, 512, 272, 80, 6, 0 },
    { 1, 1, 68, 544, 135, 76, 1, 3 },
};

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

void effe6_0003(WORK_Other* ewk) {
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
        ewk->wu.xyz[1].cal -= 0x1A000;
        if (ewk->wu.xyz[1].disp.pos <= -200) {
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



const s16 effe6_0010_col_tbl[8] = {
    8253, 8256, 8257, 8258, 8259, 8258, 8257, 8256,
};

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
    END_W* ew = &end_w;
    if (ewk->wu.old_rno[6] < ew->r_no_2) {
        ewk->wu.routine_no[2] = 99;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        effe6_init_common(ewk);
        ewk->wu.old_rno[2] = 40;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[2], 544, 48, 2, 2);
        break;
    case 1:
        if (ewk->wu.old_rno[6] == ew->r_no_2) {
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
        if (ewk->wu.old_rno[6] == ew->r_no_2) {
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
        } else {
            disp_pos_trans_entry(ewk);
        }
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
        ewk->wu.xyz[1].cal -= 0x18000;
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
        } else {
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
        }
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
