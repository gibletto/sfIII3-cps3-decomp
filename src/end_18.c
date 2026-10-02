/*
 * END_18.C  Ending 18 (end_18000)
 *
 * end_18000 runs an eleven-scene ending and then hands over to the staff roll.
 * end_1800_move dispatches the BG0 scene handlers, which place the layer, load palettes,
 * start effect E6 objects and show messages; scene 9 flickers the layer by alternating its
 * X position every frame. end_1800_cell_set writes the 12 initial BG0 cells.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "end_sub.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_18.h"
/* provisional name */
void end_18000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE3B0, 1);
        common_end_init01();
        end_1800_cell_set();
        bgm_request(0x2D);
        end_w.timer = timer_18_tbl[end_w.r_no_2];
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 11) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                load_any_color(0x24);
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_18_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_1800_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_1800_move(void) {
    void (*end_1800_move_jp[11])() = { end_1800_0005, end_1800_0001, end_1800_0001, end_1800_0001, end_1800_0001, end_1800_0005, end_1800_0006, end_1800_0001, end_1800_0008, end_1800_0009, end_1800_0010 };
    bgw_ptr = &bg_w.bgw[0];
    end_1800_move_jp[end_w.r_no_2]();
}



void end_1800_0001(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 1:
            Bg_On_W(1);
            effect_E6_init(0x6F);
            effect_E6_init(0x74);
            bgw_ptr->l_limit = 0;
            bgw_ptr->free = 3;
            Rewrite_End_Message(2);
            break;
        case 2:
            effect_E6_init(0x70);
            break;
        case 3:
            effect_E6_init(0x71);
            break;
        case 4:
            effect_E6_init(0x72);
            break;
        case 7:
            effect_E6_init(0x77);
            effect_E6_init(0x7A);
            Rewrite_End_Message(4);
            bgw_ptr->l_limit = 0;
            bgw_ptr->free = 3;
            break;
        }
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
            if (bgw_ptr->l_limit) {
                load_any_color(49);
                load_any_color(50);
            } else {
                load_any_color(51);
                load_any_color(52);
            }
        }
        break;
    }
}



void end_1800_0005(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x73);
        effect_E6_init(0x75);
        if (end_w.r_no_2) {
            Rewrite_End_Message(3);
        } else {
            Rewrite_End_Message(1);
        }
        bgw_ptr->l_limit = 0;
        bgw_ptr->free = 3;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 2;
            bgw_ptr->l_limit ^= 1;
            if (bgw_ptr->l_limit) {
                load_any_color(53);
            } else {
                load_any_color(54);
            }
        }
        break;
    }
}



void end_1800_0006(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x76);
        Rewrite_End_Message(6);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
            if (bgw_ptr->l_limit) {
                load_any_color(55);
            } else {
                load_any_color(56);
            }
        }
        break;
    }
}



void end_1800_0008(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x78);
        Rewrite_End_Message(5);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
            if (bgw_ptr->l_limit) {
                load_any_color(57);
            } else {
                load_any_color(58);
            }
        }
        break;
    }
}



void end_1800_0009(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0;
        Rewrite_End_Message(0);
        break;
    case 1:
        bgw_ptr->free++;
        bgw_ptr->free &= 1;
        if (bgw_ptr->free) {
            bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        } else {
            bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0] + 512;
        }
        break;
    }
}



void end_1800_0010(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x79);
        effect_E6_init(0xA2);
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
        end_fade_flag = 1;
        end_fade_timer = timer_18_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit++;
            bgw_ptr->l_limit &= 1;
            if (bgw_ptr->l_limit) {
                load_any_color(37);
            } else {
                load_any_color(38);
            }
        }
        break;
    }
}



void end_1800_cell_set(void) {
    s16 i;
    for (i = 0; i < 12; i++) {
        bg_cell_write(0, end_1800_bg0_cell_tbl[i].ofs, end_1800_bg0_cell_tbl[i].cell, (u32)end_1800_scrn_data, 0, 0x220);
    }
}
