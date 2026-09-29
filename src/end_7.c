/*
 * end_7.c  Character ending 7 (end_07000)
 *
 * Scene script for one character ending, entered through end_main_jp[] from normal_ending in
 * end_main.c. end_07000 sets up the ending (common_end_init00/01, character graphics, BGM),
 * then steps through 4 scenes: each scene has a frame count in its timer table, and on expiry
 * the per-scene BG handlers are reset and the next scene begins. After the last scene it stops
 * the music, fades out to the staff roll and sets end_w.end_flag.
 * end_700_move / end_701_move run the BG0 and BG1 scene handlers; the scenes print the ending
 * text, start E6 effects and the B0 effect. end_700_cell_set writes the initial scroll cells.
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
#include "EFFB0.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_7.h"



void end_07000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE330, 1);
        end_w.timer = timer_7_tbl[end_w.r_no_2];
        common_end_init01();
        end_700_cell_set();
        bgm_request(0x2C);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 4) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                bgm_request(0x2E);
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_7_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_700_move();
        end_701_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_700_move(void) {
    void (*end_800_jp[4])() = { end_700_0000, end_700_0000, end_700_2000, end_700_0000 };
    bgw_ptr = &bg_w.bgw[0];
    end_800_jp[end_w.r_no_2]();
}



void end_701_move(void) {
    void (*end_701_jp[4])() = { end_X_com01, end_700_0000, end_X_com01, end_700_0000 };
    bgw_ptr = &bg_w.bgw[1];
    end_701_jp[end_w.r_no_2]();
}



void end_700_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_7_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_7_pos[end_w.r_no_2][1];
        if (bgw_ptr->fam_no == 0) {
            switch (end_w.r_no_2) {
            case 0:
                effect_E6_init(0x5B);
                Rewrite_End_Message(1);
                break;
            case 1:
                effect_B0_init();
                Rewrite_End_Message(2);
                break;
            case 3:
                bgw_ptr->abs_x = 512;
                effect_E6_init(0x5A);
                Rewrite_End_Message(4);
                end_fade_flag = 1;
                end_fade_timer = timer_7_tbl[end_w.r_no_2] - 120;
                break;
            }
        }
        break;
    case 1:
        break;
    }
}



void end_700_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_7_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_7_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x59);
        Rewrite_End_Message(3);
        break;
    case 1:
        bgw_ptr->xy[0].cal -= 0x8000;
        if (bgw_ptr->xy[0].disp.pos <= 288) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1200000;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}



void end_700_cell_set(void) {
    s16 i;
    for (i = 0; i < 10; i++) {
        bg_cell_write(0, end_700_bg0_cell_tbl[i].ofs, end_700_bg0_cell_tbl[i].cell, (u32)end_700_scrn_data, 0, 0x220);
    }
    for (i = 0; i < 4; i++) {
        bg_cell_write(1, end_700_bg1_cell_tbl[i].ofs, end_700_bg1_cell_tbl[i].cell, (u32)end_700_scrn_data, 0, 0x220);
    }
}
