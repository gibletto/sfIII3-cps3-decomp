/*
 * END_19.C  Ending 19 (end_19000)
 *
 * end_19000 runs a six-scene ending and then hands over to the staff roll.
 * end_1900_move runs the BG0 scene handler: end_1900_0 for scene 0 and end_1900_common for
 * scenes 1-5, which places BG0 at the scene position, starts that scene's effect E6 objects
 * and message, and arms the end fade in the last scene.
 * end_1900_cell_set writes the 10 initial BG0 cells.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_19.h"



void end_19000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE150, 1);
        common_end_init01();
        end_1900_cell_set();
        bgm_request(0x2D);
        end_w.timer = timer_19_tbl[end_w.r_no_2];
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
            end_w.timer = timer_19_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_1900_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_1900_move(void) {
    void (*end_1900_move_jp[6])() = { end_1900_0, end_1900_common, end_1900_common, end_1900_common, end_1900_common, end_1900_common };
    bgw_ptr = &bg_w.bgw[0];
    end_1900_move_jp[end_w.r_no_2]();
}



void end_1900_0(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_19_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_19_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = 0;
        bgw_ptr->speed_x = 0x10000;
        effect_E6_init(0x84);
        effect_E6_init(0x85);
        effect_E6_init(0x86);
        effect_E6_init(0x87);
        Rewrite_End_Message(1);
        bgw_ptr->free = 0x28;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos < 320) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1400000;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 3:
        break;
    }
}



void end_1900_common(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_19_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_19_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        switch (end_w.r_no_2) {
        case 1:
            effect_E6_init(0x88);
            effect_E6_init(0x89);
            effect_E6_init(0x8A);
            effect_E6_init(0x8B);
            effect_E6_init(0x8C);
            effect_E6_init(0x8D);
            Rewrite_End_Message(2);
            break;
        case 2:
            Rewrite_End_Message(3);
            break;
        case 3:
            Rewrite_End_Message(4);
            break;
        case 4:
            effect_E6_init(0x8F);
            Rewrite_End_Message(5);
            break;
        case 5:
            effect_E6_init(0x90);
            Rewrite_End_Message(0);
            end_fade_flag = 1;
            end_fade_timer = timer_19_tbl[end_w.r_no_2] - 120;
            break;
        }
    case 1:
        break;
    }
}



void end_1900_cell_set(void) {
    s16 i;
    for (i = 0; i < 10; i++) {
        bg_cell_write(0, end_1900_bg0_cell_tbl[i].ofs, end_1900_bg0_cell_tbl[i].cell, (u32)end_1900_scrn_data, 0, 0x220);
    }
}
