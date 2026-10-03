/*
 * END_16.C  Ending 16 (end_16000)
 *
 * end_16000 runs a six-scene ending and then hands over to the staff roll.
 * end_1600_move dispatches the BG0 scene handlers: a rightward scroll with the first
 * message, a fade, and scenes that place the layer, start effect E6 objects with their
 * messages and alternate two palettes (end_16_col_change).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "SYS_sub.h"
#include "end_1.h"
#include "end_sub.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "bg000.h"
#include "end_16.h"



/* provisional name */
void end_16000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE320, 1);
        common_end_init01();
        end_1600_cell_set();
        bgm_request(0x2C);
        end_w.timer = timer_16_tbl[end_w.r_no_2];
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
            } else {
                end_w.timer = timer_16_tbl[end_w.r_no_2];
                bg_w.bgw[0].r_no_1 = 0;
            }
        }
        end_1600_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_1600_move(void) {
    void (*end_1600_move_jp[6])() = { end_1600_0000, end_1600_1000, end_1600_2000, end_1600_3000, end_1600_3000, end_1600_5000 };
    bgw_ptr = &bg_w.bgw[0];
    end_1600_move_jp[end_w.r_no_2]();
}



void end_1600_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_16_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_16_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        Rewrite_End_Message(1);
        break;
    case 1:
        bgw_ptr->xy[0].cal += 0x8000;
        if (bgw_ptr->xy[0].disp.pos >= 480) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1E00000;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_1600_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
    case 1:
        if (Request_Fade(80, 0) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 10;
        }
        break;
    case 3:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }
        break;
    }
}



void end_1600_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_16_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_16_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
    case 1:
        if (Request_Fade(79, 0)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
            Rewrite_End_Message(2);
        }
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
        break;
    case 3:
        bgw_ptr->xy[1].cal += 0x10000;
        if (bgw_ptr->xy[1].disp.pos >= 384) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1800000;
        }
        break;
    }
}



void end_1600_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_16_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_16_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 3:
            effect_E6_init(0x56);
            Rewrite_End_Message(3);
            bgw_ptr->l_limit2 = 2;
            bgw_ptr->l_limit = 0;
            break;
        case 4:
            effect_E6_init(0x57);
            Rewrite_End_Message(4);
            break;
        }
        break;
    case 1:
        end_16_col_change();
        break;
    }
}



void end_1600_5000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_16_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_16_pos[end_w.r_no_2][1];
        effect_E6_init(0x58);
        Rewrite_End_Message(5);
        bgw_ptr->free = 2;
        bgw_ptr->rewrite_flag = 0;
        bgw_ptr->l_limit2 = 2;
        bgw_ptr->l_limit = 0;
        load_any_color(33);
        end_fade_flag = 1;
        end_fade_timer = timer_16_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->free = 2;
            bgw_ptr->rewrite_flag ^= 1;
            if (bgw_ptr->rewrite_flag) {
                bgw_ptr->xy[0].disp.pos = 768;
                break;
            }
            bgw_ptr->xy[0].disp.pos = 256;
        }
        break;
    }
}

void end_1600_cell_set(void) {
    s16 i;
    const PANEL* p;

    p = (const PANEL*)end_1600_bg0_cell_tbl;
    i = 0;
    do {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_1600_scrn_data, 0, 0x220);
        i++;
        p++;
    } while (i < 13);
}



void end_16_col_change(void) {
    bgw_ptr->l_limit2--;
    if (bgw_ptr->l_limit2 <= 0) {
        bgw_ptr->l_limit2 = 1;
        bgw_ptr->l_limit++;
        bgw_ptr->l_limit &= 1;
        if (bgw_ptr->l_limit & 1) {
            load_any_color(32);
        } else {
            load_any_color(33);
        }
    }
}
