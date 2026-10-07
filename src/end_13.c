/*
 * END_13.C  Ending 13 (end_13000)
 *
 * end_13000 runs an eight-scene ending and then hands over to the staff roll.
 * end_d00_move dispatches the BG0 scene handlers: fades with timed scene ends, a scene
 * that scrolls BG0 right while effect E6 objects play, and scenes that place the layer and
 * show the ending messages; end_d01_move resets BG1 in scene 4.
 * end_d00_cell_set writes the initial BG0 cells.
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
#include "SYS_sub.h"
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
#include "end_13.h"



void end_13000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE240, 1);
        end_w.timer = timer_d_tbl[end_w.r_no_2];
        common_end_init01();
        end_d00_cell_set();
        bgm_request(0x2D);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 1) {
                effect_E6_init(0x32);
                effect_E6_init(0x33);
            }
            if (end_w.r_no_2 >= 8) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                bgm_request(0x2E);
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_d_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_d00_move();
        end_d01_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_d00_move(void) {
    void (*end_101_jp[8])() = { end_d00_1000, end_d00_1000, end_d00_2000, end_d00_3000, end_d00_4000, end_d00_1000, end_d00_6000, end_d00_7000 };
    bgw_ptr = &bg_w.bgw[0];
    end_101_jp[end_w.r_no_2]();
}



void end_d00_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 0:
            break;
        case 1:
            effect_E6_init(0x34);
            break;
        case 5:
            Bg_Off_W(1);
            Rewrite_End_Message(3);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_d00_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(42, 0) == 0) {
            break;
        }
        end_no_cut = 1;
        bgw_ptr->r_no_1++;
        break;
    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 20;
        }
        break;
    }
}



void end_d00_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        effect_E6_init(0x35);
    case 1:
        if (!Request_Fade(43, 0)) {
            break;
        }
        end_no_cut = 1;
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
        break;
    }
}



void end_d00_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        Rewrite_End_Message(2);
        effect_E6_init(0x36);
        effect_E6_init(0x37);
        break;
    case 1:
        bgw_ptr->xy[0].cal += 0x8000;
        if (bgw_ptr->xy[0].disp.pos > 304) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1300000;
            bgw_ptr->free = 10;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_d00_6000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x4A);
        bgw_ptr->free = 0x3C;
        Rewrite_End_Message(0);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            end_etc_flag = 0;
            effect_E6_init(0x4B);
            bgw_ptr->free = 0;
        }
        break;
    case 2:
        if (!end_etc_flag) {
            bgw_ptr->free++;
            bgw_ptr->free &= 1;
            if (bgw_ptr->free) {
                bgw_ptr->xy[1].disp.pos += 8;
                bgw_ptr->abs_y += 8;
            } else {
                bgw_ptr->xy[1].disp.pos -= 8;
                bgw_ptr->abs_y -= 8;
            }
            break;
        }
        bgw_ptr->r_no_1++;
        end_w.timer = 30;
        break;
    case 3:
        bgw_ptr->free++;
        bgw_ptr->free &= 1;
        if (bgw_ptr->free) {
            bgw_ptr->xy[1].disp.pos += 8;
            bgw_ptr->abs_y += 8;
        } else {
            bgw_ptr->xy[1].disp.pos -= 8;
            bgw_ptr->abs_y -= 8;
        }
        break;
    }
}



void end_d00_7000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(4);
        end_fade_flag = 1;
        end_fade_timer = timer_d_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        break;
    }
}



void end_d01_move(void) {
    void (*end_d01_jp[8])() = { end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_d01_4000, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_d01_jp[end_w.r_no_2]();
}



void end_d01_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos = 0;
        break;
    case 1:
        break;
    }
}



/* provisional name */
void end_d00_cell_set(void) {
    s16 i;
    for (i = 0; i < 8; i++) {
        bg_cell_write(0, end_d00_bg0_cell_tbl[i].ofs, end_d00_bg0_cell_tbl[i].cell, (u32)end_d00_scrn_data, 0, 0x220);
    }
}
