/*
 * END_1.C  Ending 1 (end_01000)
 *
 * end_01000(pl_num) is the ending script: on entry it runs the common ending inits,
 * loads the ending graphics, writes BG0's first cells (end_100_cell_set) and issues sound
 * 0x2C; then it counts down timer_1_tbl through five scenes, calling end_100_move each
 * frame, and after the last scene hands over to the staff roll (fadeout_to_staff_roll,
 * sound 0x2E). end_100_move dispatches the BG0 scene handlers end_100_0000-0004, which
 * place the layer, request fades, start effect E6 objects and show the ending messages.
 * end_ake_cell_put writes a cell into the overlay scroll map and is shared with other endings.
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
#include "end_1.h"



/* provisional name */
void end_01000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE598, 1);
        end_w.timer = timer_1_tbl[end_w.r_no_2];
        common_end_init01();
        end_100_cell_set();
        bgm_request(0x2C);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 5) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                bgm_request(0x2E);
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_1_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_100_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_100_move(void) {
    void (*end_200_jp[5])() = { end_100_0000, end_100_0001, end_100_0002, end_100_0002, end_100_0004 };
    bgw_ptr = &bg_w.bgw[0];
    end_200_jp[end_w.r_no_2]();
}



void end_100_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = 0;
        Bg_On_W(1);
        effect_E6_init(0xA1);
        Rewrite_End_Message(1);
        bgw_ptr->free = 0x46;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[0].cal += 0x8000;
        if (384 < bgw_ptr->xy[0].disp.pos) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1800000;
            bgw_ptr->free = 0x5A;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 3:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 4:
        if (Request_Fade(110, 0) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 5:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 0x28;
        }
        break;
    case 6:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }
    }
}



void end_100_0001(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(0x6F, 1) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 0x200;
        effect_E6_init(0xA3);
        Rewrite_End_Message(2);
        break;
    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
        break;
    case 2:
        break;
    }
}



void end_100_0002(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 2:
            effect_E6_init(0xA4U);
            Rewrite_End_Message(3U);
            break;
        case 3:
            Rewrite_End_Message(4U);
            break;
        }
        break;
    case 1:
        break;
    }
}



void end_100_0004(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1 += 1;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0xA6);
        Rewrite_End_Message(5);
        end_fade_flag = 1;
        end_fade_timer = timer_1_tbl[end_w.r_no_2] - 120;
        bgw_ptr->speed_y = 0x4000;
        break;
    case 1:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        if ((bgw_ptr->xy[1].disp.pos) > 272) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
    case 2:
        break;
    }
}



void end_100_cell_set(void) {
    s16 i;
    const PANEL* p;

    p = end_100_panel;
    for (i = 0; i < 11; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_100_scrn_data, 0, 0x220);
    }
}
