/*
 * END_17.C  Ending 17 (end_17000)
 *
 * end_17000 runs a seven-scene ending and then hands over to the staff roll.
 * end_1100_move runs the BG0 scene handlers, mostly through end_1100_common, which places
 * the layer and per scene turns layers on or off, starts effect E6 objects, shows the
 * message and in scene 4 rewrites four BG0 cells (end_1100_cell_change);
 * end_1101_move and end_1102_move handle the other layers.
 * end_1100_cell_set writes the 16 initial BG0 cells.
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
#include "end_18.h"
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
#include "aboutspr.h"
#include "end_17.h"



void end_17000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE150, 1);
        common_end_init01();
        end_1100_cell_set();
        bgm_request(0x2C);
        end_w.timer = timer_11_tbl[end_w.r_no_2];
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
            end_w.timer = timer_11_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_1100_move();
        end_1101_move();
        end_1102_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_1100_move(void) {
    void (*end_1102_move_jp[7])() = { end_1100_common, end_1100_common, end_1100_common, end_1100_3, end_1100_common, end_1100_common, end_1100_6 };
    bgw_ptr = &bg_w.bgw[0];
    end_1102_move_jp[end_w.r_no_2]();
}



void end_1100_common(void) {
    const s16 (*tp)[2];
    END_W* ew;
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        tp = end_11_pos;
        ew = &end_w;
        bgw_ptr->xy[0].disp.pos = tp[ew->r_no_2][0];
        bgw_ptr->xy[1].disp.pos = tp[ew->r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        switch (ew->r_no_2) {
        case 0:
            Bg_On_W(1);
            effect_E6_init(0);
            effect_E6_init(1);
            Rewrite_End_Message(1);
            break;
        case 1:
            Bg_Off_W(1);
            Rewrite_End_Message(2);
            break;
        case 2:
            Bg_On_W(1);
            Rewrite_End_Message(3);
            effect_E6_init(0x81);
            effect_E6_init(0x82);
            break;
        case 4:
            bg_cell_write(0, 0x3000, 13, (u32)end_1100_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x3040, 14, (u32)end_1100_scrn_data, 0, 0x220);
            Rewrite_End_Message(5);
            if (Country == 8) {
                effect_E6_init(7);
            }
            end_1100_cell_change();
            break;
        case 5:
            effect_E6_init(3);
            effect_E6_init(4);
            effect_E6_init(5);
            Rewrite_End_Message(6);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_1100_3(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bg_cell_write(0, 0, 5, (u32)end_1100_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x40, 6, (u32)end_1100_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x2000, 5, (u32)end_1100_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x2040, 6, (u32)end_1100_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x3000, 5, (u32)end_1100_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x3040, 6, (u32)end_1100_scrn_data, 0, 0x220);
        bgw_ptr->xy[0].disp.pos = end_11_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_11_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(2);
        effect_E6_init(0x83);
        break;
    case 1:
        bg_w.bgw[0].xy[1].cal -= 0x30000;
        break;
    case 2:
        break;
    }
}



void end_1100_6(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->l_limit = 0;
        bgw_ptr->xy[0].disp.pos = end_11_115_pos[bgw_ptr->l_limit][0];
        bgw_ptr->xy[1].disp.pos = end_11_115_pos[bgw_ptr->l_limit][1];
        bgw_ptr->r_limit = end_11_115_pos[bgw_ptr->l_limit][2];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(6);
        effect_E6_init(8);
        Rewrite_End_Message(7);
        end_fade_flag = 1;
        end_fade_timer = timer_11_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->r_limit--;
        if (bgw_ptr->r_limit <= 0) {
            bgw_ptr->l_limit++;
            if (bgw_ptr->l_limit >= 4) {
                bgw_ptr->l_limit = 0;
            }
            bgw_ptr->xy[0].disp.pos = end_11_115_pos[bgw_ptr->l_limit][0];
            bgw_ptr->xy[1].disp.pos = end_11_115_pos[bgw_ptr->l_limit][1];
            bgw_ptr->r_limit = end_11_115_pos[bgw_ptr->l_limit][2];
        }
        break;
    }
}



void end_1101_move(void) {
    void (*end_1101_move_jp[7])() = { end_X_com01, end_X_com01, end_1101_2, end_1101_2, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_1101_move_jp[end_w.r_no_2]();
}



void end_1101_2(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 512;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 2:
            bgw_ptr->speed_y = 0;
            if (bgw_ptr->fam_no == 1) {
                bgw_ptr->speed_x = -0x8000;
            } else {
                bgw_ptr->speed_x = 0x8000;
            }
            break;
        case 3:
            bgw_ptr->speed_x = 0;
            bgw_ptr->speed_y = 0x4000;
            break;
        }
        break;
    case 1:
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x;
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_1102_move(void) {
    void (*end_1102_move_jp[7])() = { end_X_com01, end_X_com01, end_1101_2, end_X_com01, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[2];
    end_1102_move_jp[end_w.r_no_2]();
}



void end_1100_cell_set(void) {
    s16 i;
    for (i = 0; i < 16; i++) {
        bg_cell_write(0, end_1100_bg0_cell_tbl[i].ofs, end_1100_bg0_cell_tbl[i].cell, (u32)end_1100_scrn_data, 0, 0x220);
    }
}


void end_1100_cell_change(void) {
    bg_cell_write(0, 0, 11, (u32)end_1100_scrn_data, 0, 0x220);
    bg_cell_write(0, 0x40, 12, (u32)end_1100_scrn_data, 0, 0x220);
    bg_cell_write(0, 0x2000, 9, (u32)end_1100_scrn_data, 0, 0x220);
    bg_cell_write(0, 0x2040, 10, (u32)end_1100_scrn_data, 0, 0x220);
}
