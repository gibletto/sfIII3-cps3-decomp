/*
 * end_9.c  Character ending 9 (end_09000)
 *
 * Scene script for one character ending, entered through end_main_jp[] from normal_ending in
 * end_main.c. end_09000 sets up the ending (common_end_init00/01, character graphics, BGM),
 * then steps through 6 scenes: each scene has a frame count in its timer table, and on expiry
 * the per-scene BG handlers are reset and the next scene begins. After the last scene it stops
 * the music, fades out to the staff roll and sets end_w.end_flag.
 * end_900_move dispatches the BG0 scene handlers (end_900_0000, end_900_5000), which print the
 * ending text for each scene and start the E6 ending effects. end_900_cell_set writes the
 * initial scroll cells.
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
#include "aboutspr.h"
#include "end_9.h"



void end_09000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_9_tbl[end_w.r_no_2];
        load_char_gfx(0xE1F0, 1);
        end_900_cell_set();
        bgm_request(0x2D);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_9_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_900_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_900_move(void) {
    void (*end_1000_jp[6])() = { end_900_0000, end_900_0000, end_900_0000, end_900_0000, end_900_0000, end_900_5000 };
    bgw_ptr = &bg_w.bgw[0];
    end_1000_jp[end_w.r_no_2]();
}



void end_900_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 0:
            Bg_On_W(1);
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_y = 0;
            effect_E6_init(0x24);
            Rewrite_End_Message(1);
            break;
        case 1:
            Rewrite_End_Message(2);
            effect_E6_init(0x25);
            break;
        case 2:
            Rewrite_End_Message(3);
            break;
        case 3:
            effect_E6_init(0x26);
            effect_E6_init(0x27);
            effect_E6_init(0x28);
            effect_E6_init(0x29);
            Rewrite_End_Message(4);
            break;
        case 4:
            Rewrite_End_Message(5);
            effect_E6_init(0x25);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_900_5000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(0x2A);
        bgw_ptr->free = 0x1E;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_9_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal -= 0x8000;
        if (bgw_ptr->xy[1].disp.pos <= 0x150) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1500000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}



void end_900_cell_set(void) {
    s16 i;
    const PANEL* p;

    p = end_900_bg0_cell_tbl;
    for (i = 0; i < 8; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_900_scrn_data, 0, 0x220);
    }
}
