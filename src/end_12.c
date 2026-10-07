/*
 * END_12.C  Ending 12 (end_12000)
 *
 * end_12000 runs a seven-scene ending on timer_c_tbl and then hands over to the
 * staff roll. end_C00_move dispatches the BG0 scene handlers: BG1 scrolls down in scene 0
 * (end_C01_move), later scenes request fades, place BG0, start effect E6 objects and
 * effect F2 and show messages, and end_C00_anim flickers a 32x32 block of BG0 cells every
 * three frames. end_C00_cell_set writes the initial BG0 and BG1 cells.
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
#include "end_main.h"
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
#include "effe6.h"
#include "EFFF1.h"
#include "aboutspr.h"
#include "end_12.h"



void end_12000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_c_tbl[end_w.r_no_2];
        load_char_gfx(0xE280, 1);
        end_C00_cell_set();
        bgm_request(0x2C);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 7) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_c_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_C00_move();
        end_C01_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_C00_move(void) {
    void (*end_C00_jp[7])() = { end_C00_0000, end_C00_1000, end_C00_2000, end_C00_3000, end_C00_4000, end_C00_5000, end_C00_6000 };
    bgw_ptr = &bg_w.bgw[0];
    end_C00_jp[end_w.r_no_2]();
}



void end_C00_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(1);
        break;
    case 1:
        if (bgw_ptr->xy[1].disp.pos > 304) {
            bgw_ptr->r_no_1++;
            effect_F2_init();
        }
    case 2:
        bgw_ptr->xy[1].cal += 0x10000;
        if (bgw_ptr->xy[1].disp.pos > 384) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1800000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}


/* provisional name */
void end_C00_anim(void) {
    bgw_ptr->l_limit--;
    if (bgw_ptr->l_limit > 0) {
        return;
    }
    bgw_ptr->l_limit = 3;
    bgw_ptr->free++;
    if (bgw_ptr->free & 1) {
        bgw_ptr->r_limit = 32;
    } else {
        bgw_ptr->r_limit = 0;
    }
    end_bg_block_attr_set(0, 64, 32, 0x1800, 32);
}



void end_C00_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x39);
        Rewrite_End_Message(2);
        bgw_ptr->free = 0;
        bgw_ptr->l_limit = 3;
        break;
    case 1:
        end_C00_anim();
        break;
    }
}



void end_C00_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(39, 0) == 0) {
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



void end_C00_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        Rewrite_End_Message(3);
    case 1:
        if (Request_Fade(44, 0) == 0) {
            break;
        }
        end_no_cut = 1;
        bgw_ptr->r_no_1++;
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
        break;
    }
}



void end_C00_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        effect_E6_init(0x3B);
        Rewrite_End_Message(4);
        bgw_ptr->free = 0;
        bgw_ptr->l_limit = 3;
        break;
    case 1:
        end_C00_anim();
        break;
    }
}



void end_C00_5000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        effect_E6_init(0x3C);
        effect_E6_init(0x99);
        Rewrite_End_Message(5);
        break;
    case 1:
        break;
    }
}



void end_C00_6000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x3C;
        end_fade_flag = 1;
        end_fade_timer = timer_c_tbl[end_w.r_no_2] - 120;
        Rewrite_End_Message(6);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x3D);
        }
        break;
    case 2:
        break;
    }
}



void end_C01_move(void) {
    void (*end_C00_jp[7])() = { end_C01_0000, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_C00_jp[end_w.r_no_2]();
}



void end_C01_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[1].cal += 0x10000;
        if (bg_w.bgw[0].r_no_1 >= 3) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        break;
    }
}



/* provisional name */
void end_C00_cell_set(void) {
    s16 i;
    const PANEL* panel;
    for (panel = end_c00_bg0_cell_tbl, i = 0; i < 12; i++, panel++) {
        bg_cell_write(0, panel->ofs, panel->cell, (u32)end_c00_scrn_data, 0, 0x220);
    }
    for (panel = end_c00_bg1_cell_tbl, i = 0; i < 6; i++, panel++) {
        bg_cell_write(1, panel->ofs, panel->cell, (u32)end_c00_scrn_data, 0, 0x220);
    }
}
