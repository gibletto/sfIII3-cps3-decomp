/*
 * END_3.C  Ending 3 (end_03000)
 *
 * end_03000 runs a six-scene ending on its timer table and then hands over to the
 * staff roll. end_300_move dispatches the BG0 scene handlers: they place the layer, request
 * fades, start effect E6 objects and show messages; scene 4 steps through a palette sequence
 * every 16 frames and raises end_etc_flag, and the last scene arms the end fade 120 frames
 * before its timer runs out. end_301_move places BG1 in scene 3.
 * end_300_cell_set writes the 12 initial BG0 cells.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_3.h"



void end_03000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE578, 1);
        end_w.timer = timer_3_tbl[end_w.r_no_2];
        common_end_init01();
        end_300_cell_set();
        bgm_request(0x2D);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_3_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_300_move();
        end_301_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_300_move(void) {
    void (*end_1000_jp[6])() = { end_300_0000, end_300_0000, end_300_0002, end_300_0003, end_300_0004, end_300_0005 };
    bgw_ptr = &bg_w.bgw[0];
    end_1000_jp[end_w.r_no_2]();
}



void end_300_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 0:
            Bg_On_W(1);
            effect_E6_init(0x9A);
            Rewrite_End_Message(1);
            break;
        case 1:
            effect_E6_init(0x9B);
            Rewrite_End_Message(2);
            break;
        }
    }
}



void end_300_0002(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(3);
        bgw_ptr->free = 0x258;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        if (Request_Fade(105, 0)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }
        break;
    case 3:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 20;
        }
        break;
    }
}



void end_300_0003(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x9D);
        Rewrite_End_Message(4);
    case 1:
        if (Request_Fade(106, 0)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
        break;
    case 3:
        bgw_ptr->xy[1].cal -= 0x4000;
        if (bgw_ptr->xy[1].disp.pos <= 448) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1C00000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_300_0004(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x9E);
        end_etc_flag = 0;
        effect_E6_init(0x9F);
        Rewrite_End_Message(5);
        bgw_ptr->free = 0x21C;
        bgw_ptr->l_limit = -1;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->free = 0x10;
            bgw_ptr->l_limit++;
            if (bgw_ptr->l_limit >= 3) {
                bgw_ptr->r_no_1++;
                load_any_color(62);
                load_any_color(64);
                load_any_color(65);
                load_any_color(66);
                end_w.timer = 50;
                end_etc_flag = 1;
            } else {
                load_any_color(end_300_col_tbl[bgw_ptr->l_limit]);
            }
        }
        break;
    }
}



void end_300_0005(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0xA0);
        Rewrite_End_Message(6);
        load_any_color(63);
        end_fade_flag = 1;
        end_fade_timer = timer_3_tbl[end_w.r_no_2] - 120;
    }
}



void end_301_move(void) {
    void (*end_301_jp[6])() = { end_X_com01, end_X_com01, end_X_com01, end_301_0003, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_301_jp[end_w.r_no_2]();
}



void end_301_0003(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
    }
}



void end_300_cell_set(void) {
    s16 i;
    for (i = 0; i < 12; i++) {
        bg_cell_write(0, end_300_bg0_cell_tbl[i].ofs, end_300_bg0_cell_tbl[i].cell, (u32)end_300_scrn_data, 0, 0x220);
    }
}
