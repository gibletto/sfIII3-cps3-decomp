/*
 * end_6.c  Character ending 6 (end_06000)
 *
 * Scene script for one character ending, entered through end_main_jp[] from normal_ending in
 * end_main.c. end_06000 sets up the ending (common_end_init00/01, character graphics, BGM),
 * then steps through 6 scenes: each scene has a frame count in its timer table, and on expiry
 * the per-scene BG handlers are reset and the next scene begins. After the last scene it stops
 * the music, fades out to the staff roll and sets end_w.end_flag.
 * end_600_move / end_601_move dispatch the BG0 and BG1 scene handlers (end_600_xxxx,
 * end_601_xxxx), which place the planes, print the ending text and start E6 ending effects.
 * end_600_cell_set writes the initial scroll cells.
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
#include "end_6.h"



void end_06000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE220, 1);
        end_w.timer = timer_6_tbl[end_w.r_no_2];
        common_end_init01();
        end_600_cell_set();
        bgm_request(0x2D);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 >= 6) {
                end_w.r_no_1++;
                load_any_color(46);
                bgm_request(0x2E);
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_6_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }
        end_600_move();
        end_601_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_600_move(void) {
    void (*end_1000_jp[6])() = { end_600_0000, end_600_1000, end_600_2000, end_600_3000, end_600_4000, end_600_5000 };
    bgw_ptr = &bg_w.bgw[0];
    end_1000_jp[end_w.r_no_2]();
}



void end_600_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(1);
        break;
    case 1:
        break;
    }
}



void end_600_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 0;
        bgw_ptr->old_pos_x = 0;
        Rewrite_End_Message(2);
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;
        if (bgw_ptr->xy[1].disp.pos <= 624) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2700000;
        }
    case 2:
        bgw_ptr->old_pos_x++;
        if (bgw_ptr->old_pos_x > 2) {
            bgw_ptr->old_pos_x = 0;
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_600_1000_tbl[bgw_ptr->free][0] + 0x100;
            bgw_ptr->xy[1].disp.pos += end_600_1000_tbl[bgw_ptr->free][1];
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_600_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][1] + 16;
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1] + 16;
        bgw_ptr->abs_x = 0x210;
        bgw_ptr->abs_y = 16;
        bgw_ptr->free = 0;
        bgw_ptr->old_pos_x = 16;
        effect_E6_init(0x2B);
        Rewrite_End_Message(0);
        break;
    case 1:
        bgw_ptr->old_pos_x--;
        if (bgw_ptr->old_pos_x < 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->old_pos_x = end_600_2000_tbl[bgw_ptr->free][0];
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0] + end_600_2000_tbl[bgw_ptr->free][1];
            bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1] + end_600_2000_tbl[bgw_ptr->free + 1][0];
            bgw_ptr->abs_x = end_600_2000_tbl[bgw_ptr->free][0] + 0x200;
            bgw_ptr->abs_y = end_600_2000_tbl[bgw_ptr->free][1];
        }
        break;
    case 2:
        bgw_ptr->old_pos_x--;
        if (bgw_ptr->old_pos_x < 0) {
            bgw_ptr->old_pos_x = end_600_2000_tbl[bgw_ptr->free][0];
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0] + end_600_2000_tbl[bgw_ptr->free][1];
            bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1] + end_600_2000_tbl[bgw_ptr->free + 1][0];
            bgw_ptr->abs_x = end_600_2000_tbl[bgw_ptr->free][0] + 0x200;
            bgw_ptr->abs_y = end_600_2000_tbl[bgw_ptr->free][1];
        }
        break;
    }
}



void end_600_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(3);
        effect_E6_init(0x2D);
        effect_E6_init(0x2E);
        bgw_ptr->free = 0x1E;
        break;
    case 1:
    case 2:
    case 3:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 0x1E;
            effect_E6_init(0x31);
        }
        break;
    case 4:
        break;
    }
}



void end_600_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(4);
        break;
    case 1:
        break;
    }
}



void end_600_5000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(5);
        bgw_ptr->free = 0x1E;
        end_fade_flag = 1;
        end_fade_timer = timer_6_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 3;
            bgw_ptr->l_limit = 0;
        }
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 3;
            bgw_ptr->l_limit++;
            if (bgw_ptr->l_limit >= 4) {
                bgw_ptr->l_limit = 0;
            }
            load_any_color(end_600_5000_pal_tbl[bgw_ptr->l_limit]);
        }
        break;
    }
}



void end_601_move(void) {
    END601_JP end_601_jp;
    end_601_jp = end_601_jp_tbl;
    bgw_ptr = &bg_w.bgw[1];
    end_601_jp.jp[end_w.r_no_2]();
}



void end_601_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        break;
    }
}



void end_601_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x2000;
        if (bg_w.bgw[0].r_no_1 >= 2) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_601_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1 << (bgw_ptr->fam_no));
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][1] - 16;
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1] - 16;
        bgw_ptr->abs_x = 0x1F0;
        bgw_ptr->abs_y = -16;
        bgw_ptr->free = 0;
        bgw_ptr->old_pos_x = 16;
        if (Country == 1) {
            effect_E6_init(0x2C);
            break;
        }
        effect_E6_init(0x98);
        break;
    case 1:
        bgw_ptr->old_pos_x--;
        if (bgw_ptr->old_pos_x < 0) {
            bgw_ptr->old_pos_x = end_600_2000_tbl[bgw_ptr->free][0];
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0] - end_600_2000_tbl[bgw_ptr->free][1];
            bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1] - end_600_2000_tbl[bgw_ptr->free + 1][0];
            bgw_ptr->abs_x = 0x200 - end_600_2000_tbl[bgw_ptr->free][0];
            bgw_ptr->abs_y = -end_600_2000_tbl[bgw_ptr->free][1];
        }
        break;
    case 2:
        break;
    }
}



void end_601_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        if (!(scrn_reg_w[bgw_ptr->fam_no].ctrl & 0x8000)) {
            Bg_On_W(1 << bgw_ptr->fam_no);
        }
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        break;
    }
}



void end_600_cell_set(void) {
    s16 i;
    for (i = 0; i < 12; i++) {
        bg_cell_write(0, end_600_bg0_cell_tbl[i].ofs, end_600_bg0_cell_tbl[i].cell, (u32)end_600_scrn_data, 0, 0x220);
    }
    for (i = 0; i < 4; i++) {
        bg_cell_write(1, end_600_bg1_cell_tbl[i].ofs, end_600_bg1_cell_tbl[i].cell, (u32)end_600_scrn_data, 0, 0x220);
    }
}
