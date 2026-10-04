/*
 * END_11.C  Ending 11 (end_11000)
 *
 * end_11000 runs a seven-scene ending and then hands over to the staff roll.
 * end_b00_move and end_b01_move are the BG0 and BG1 scene handlers: they turn layers on and
 * off, place them at the scene positions, start effect E6 objects and show the ending
 * messages. end_b00_cell_set writes the initial cells of BG0 and BG1.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "efff7.h"
#include "efff8_code.h"
#include "efff9.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "end_main.h"
#include "effe6.h"
#include "end_11.h"



void end_11000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_b00_cell_set();
        bgm_request(0x2C);
        end_w.timer = timer_b_tbl[end_w.r_no_2];
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 7) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_b_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        if (bg_w.quake_y_index > 0) {
            bg_w.quake_y_index--;
        }
        end_b00_move();
        end_b01_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_b00_move(void) {
    void (*end_b00_jp[7])() = { end_b00_0000, end_b00_1000, end_b00_0000, end_b00_3000, end_b00_0000, end_b00_0000, end_b00_0000 };
    bgw_ptr = &bg_w.bgw[0];
    end_b00_jp[end_w.r_no_2]();
}



void end_b00_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 0:
            Bg_Off_W(1);
            effect_E6_init(0x60);
            Rewrite_End_Message(1);
            break;
        case 2:
            Bg_Off_W(1);
            effect_E6_init(0x62);
            Rewrite_End_Message(0);
            break;
        case 4:
            effect_E6_init(0x65);
            effect_E6_init(0x66);
            effect_E6_init(0x67);
            effect_E6_init(0x68);
            Rewrite_End_Message(3);
            break;
        case 5:
            effect_E6_init(0x69);
            effect_E6_init(0x6A);
            effect_E6_init(0x6D);
            effect_E6_init(0x6E);
            effect_E6_init(0x6B);
            Rewrite_End_Message(4);
            break;
        case 6:
            effect_E6_init(0x6C);
            Rewrite_End_Message(5);
            end_fade_flag = 1;
            end_fade_timer = timer_b_tbl[end_w.r_no_2] - 120;
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_b00_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        end_etc_flag = 0;
        effect_E6_init(0x61);
        Rewrite_End_Message(0);
        break;
    case 1:
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            end_w.timer = 10;
        }
    case 2:
        break;
    }
}



void end_b00_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = 0;
        Bg_On_W(1);
        bg_w.quake_y_index = 24;
        bgw_ptr->free = 2;
        effect_E6_init(0x63);
        Rewrite_End_Message(2);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->free = 2;
            if (bg_w.quake_y_index <= 0) {
                bgw_ptr->r_no_1++;
                bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
                bgw_ptr->abs_y = 0;
                effect_E6_init(0x64);
                break;
            }
            bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][0] + quake_y_tbl[bg_w.quake_y_index];
            bgw_ptr->abs_y = quake_y_tbl[bg_w.quake_y_index];
        }
        break;
    case 2:
        break;
    }
}



void end_b01_move(void) {
    void (*end_b01_jp[7])() = { end_b01_0000, end_X_com01, end_b01_0000, end_b01_3000, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_b01_jp[end_w.r_no_2]();
}



void end_b01_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        if (end_w.r_no_2 == 1) {
            bgw_ptr->speed_y = 0x100000;
            break;
        }
        bgw_ptr->speed_y = -0x40000;
        break;
    case 1:
        bgw_ptr->r_no_1++;
        Bg_On_W(2U);
    case 2:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        bgw_ptr->abs_y += bgw_ptr->speed_y;
        break;
    }
}



void end_b01_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bg_cell_write(1, 0x80, 10, (u32)end_b00_scrn_data, 0, 0x220);
        bg_cell_write(1, 0xC0, 11, (u32)end_b00_scrn_data, 0, 0x220);
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Bg_On_W(2);
        break;
    case 1:
        if (bg_w.quake_y_index) {
            bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][0] + quake_y_tbl[bg_w.quake_y_index];
            bgw_ptr->abs_y = quake_y_tbl[bg_w.quake_y_index];
            break;
        }
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = 0;
        break;
    case 2:
        break;
    }
}



/* provisional name */
void end_b00_cell_set(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        bg_cell_write(0, end_b00_bg0_cell_tbl[i].ofs, end_b00_bg0_cell_tbl[i].cell, (u32)end_b00_scrn_data, 0, 0x220);
    }
    for (i = 0; i < 16; i++) {
        bg_cell_write(1, end_b00_bg1_cell_tbl[i].ofs, end_b00_bg1_cell_tbl[i].cell, (u32)end_b00_scrn_data, 0, 0x220);
    }
}
