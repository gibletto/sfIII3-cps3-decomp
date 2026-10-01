/*
 * END_14.C  Ending 14 (end_14000)
 *
 * end_14000 runs an eight-scene ending on timer_e_tbl, calling the BG0, BG1 and BG2
 * scene handlers (end_e00_move, end_e01_move, end_e02_move) each frame, and then hands over
 * to the staff roll. Scenes include a 12-step colour animation that rewrites the BG0 cell
 * block every 7 frames (end_e00_0000_col_sub), a fade and downward scroll, a scene that
 * waits for end_etc_flag before its fade, and layer placements with effect E6 objects and
 * the ending messages. Its initial cells are written by end_e00_cell_set in END_16.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "end_main.h"
#include "end_1.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "effe6.h"
#include "end_16.h"
#include "aboutspr.h"
#include "end_14.h"



void end_14000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE1B0, 1);
        end_w.timer = timer_e_tbl[end_w.r_no_2];
        common_end_init01();
        end_e00_cell_set();
        bgm_request(0x2D);
        break;
    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 8) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                bgm_request(0x2E);
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_e_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_e00_move();
        end_e01_move();
        end_e02_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_e00_move(void) {
    void (*end_e00_jp[8])() = { end_e00_0000, end_e00_1000, end_e00_2000, end_e00_3000, end_e00_4000, end_e00_5000, end_e00_6000, end_e00_7000 };
    bgw_ptr = &bg_w.bgw[0];
    end_e00_jp[end_w.r_no_2]();
}



void end_e00_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[0].disp.pos += 64;
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->free = 60;
        Rewrite_End_Message(1);
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        if (bgw_ptr->xy[1].disp.pos < 273) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x19);
            bg_cell_write(0, 0, 6, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x40, 7, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x1000, 8, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x1040, 9, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x2000, 1, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x2040, 1, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x3000, 1, (u32)end_e00_scrn_data, 0, 0x220);
            bg_cell_write(0, 0x3040, 1, (u32)end_e00_scrn_data, 0, 0x220);
        }
        break;
    case 3:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 4:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 7;
        bgw_ptr->l_limit = 0;
    case 5:
        if (end_e00_0000_col_sub()) {
            bgw_ptr->r_no_1++;
        }
    case 6:
        bgw_ptr->xy[1].cal -= 0x4000;
        if (bgw_ptr->xy[1].disp.pos < -311) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0xFEC80000;
            end_w.timer = 20;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 7:
        break;
    }
}



s16 end_e00_0000_col_sub(void) {
    bgw_ptr->free--;
    if (bgw_ptr->free <= 0) {
        bgw_ptr->free = 7;
        bgw_ptr->l_limit++;
        if (bgw_ptr->l_limit >= 12) {
            return 1;
        }
        bgw_ptr->r_limit = end_e00_0000_col_tbl[bgw_ptr->l_limit];
        end_bg_block_attr_set(0, 0, 32, 0, 32);
    }
    return 0;
}



void end_e00_1000_col_sub(void) {
    if (bgw_ptr->l_limit > 7) {
        return;
    }
    bgw_ptr->free--;
    if (bgw_ptr->free > 0) {
        return;
    }
    bgw_ptr->l_limit++;
    if (bgw_ptr->l_limit < 7) {
        bgw_ptr->free = 8;
        bgw_ptr->r_limit = end_e00_1000_col_tbl[bgw_ptr->l_limit];
        end_bg_block_attr_set(0, 64, 32, 0x1800, 32);
    }
}



void end_e00_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 128;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 128;
        bgw_ptr->free = 8;
        bgw_ptr->l_limit = 0;
        Rewrite_End_Message(2);
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;
        if (bgw_ptr->xy[1].disp.pos < 36) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x240000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
    case 2:
        end_e00_1000_col_sub();
        break;
    }
}



void end_e00_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        break;
    case 1:
        bgw_ptr->xy[1].cal += 0x10000;
        if (bgw_ptr->xy[1].disp.pos > 80) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x500000;
            bgw_ptr->free = 78;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 8;
            bgw_ptr->l_limit = 0;
        }
        break;
    case 3:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit++;
            if (bgw_ptr->l_limit >= 8) {
                bgw_ptr->r_no_1++;
                end_w.timer = 120;
                break;
            }
            bgw_ptr->free = 8;
            bgw_ptr->r_limit = end_e00_2000_col_tbl[bgw_ptr->l_limit];
            end_bg_block_attr_set(0, 64, 32, 0x1800, 32);
        }
        break;
    case 4:
        break;
    }
}



void end_e00_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1);
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x1A);
        bgw_ptr->free = 0x30;
        Rewrite_End_Message(0);
        break;
    case 1:
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            Frame_Up(0xC0, 0x30, 1, 1);
        }
        break;
    case 3:
        if (Request_Fade(29, 0) == 0) {
            break;
        }
        end_no_cut = 1;
        bgw_ptr->r_no_1++;
        break;
    case 4:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 10;
        }
        break;
    case 5:
        break;
    }
}



void end_e00_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x1D);
        effect_E6_init(0x1E);
        break;
    case 1:
        if (Request_Fade(49, 0)) {
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
        bgw_ptr->xy[1].cal += 0x4000;
        if (bgw_ptr->xy[1].disp.pos >= 64) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x400000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 4:
        break;
    }
}



void end_e00_5000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Bg_On_W(1);
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(3);
        break;
    case 1:
        break;
    }
}



void end_e00_6000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Bg_Off_W(1);
        effect_E6_init(0x1E);
        end_etc_flag = 0;
        effect_E6_init(0x1F);
        Rewrite_End_Message(4);
        break;
    case 1:
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 10;
        }
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 3:
        if (Request_Fade(29, 0) == 0) {
            break;
        }
        end_no_cut = 1;
        bgw_ptr->r_no_1++;
        break;
    case 4:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 10;
        }
        break;
    case 5:
        break;
    }
}



void end_e00_7000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bg_cell_write(0, 0, 2, (u32)end_e00_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x40, 3, (u32)end_e00_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x1000, 4, (u32)end_e00_scrn_data, 0, 0x220);
        bg_cell_write(0, 0x1040, 5, (u32)end_e00_scrn_data, 0, 0x220);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->xy[1].disp.pos += 48;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Bg_On_W(1);
        end_fade_flag = 1;
        end_fade_timer = timer_e_tbl[end_w.r_no_2] - 120;
        Rewrite_End_Message(5);
    case 1:
        if (Request_Fade(49, 0)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }
    case 3:
        bgw_ptr->xy[1].cal -= 0x3000;
        if (bgw_ptr->xy[1].disp.pos < 697) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2B80000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 4:
        break;
    }
}



void end_e01_move(void) {
    void (*end_101_jp[8])() = { end_e01_0000, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_e01_7000 };
    bgw_ptr = &bg_w.bgw[1];
    end_101_jp[end_w.r_no_2]();
}



void end_e01_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        scrn_map_set_now(1, ake_scrl_w[0].adrs);
        scrn_map_set(1, ake_scrl_w[0].adrs);
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 60;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        if (bgw_ptr->xy[1].disp.pos <= 256) {
            bgw_ptr->r_no_1++;
            end_ake_cell_put(0, 0, 0, (u32)end_ake_scrn_data);
            end_ake_cell_put(0, 0x40, 0, (u32)end_ake_scrn_data);
            end_ake_cell_put(0, 0x1000, 0, (u32)end_ake_scrn_data);
            end_ake_cell_put(0, 0x1040, 0, (u32)end_ake_scrn_data);
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    default:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_e01_7000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x23);
        break;
    case 1:
        if (bg_w.bgw[0].r_no_1 >= 4) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[1].cal -= 0x7000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_e02_move(void) {
    void (*end_102_jp[8])() = { end_e02_0000, end_e02_1000, end_e02_2000, end_e02_3000, end_e02_4000, end_X_com01, end_X_com01, end_e02_7000 };
    bgw_ptr = &bg_w.bgw[2];
    end_102_jp[end_w.r_no_2]();
}



void end_e02_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x16);
        effect_E6_init(0x17);
        effect_E6_init(0x18);
        effect_E6_init(0x1B);
        effect_E6_init(0x1C);
        bgw_ptr->free = 0x3C;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[0].cal -= 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal -= 0x22000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_e02_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(4);
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        break;
    }
}



void end_e02_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 256;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[1].cal += 0xF000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        if (bgw_ptr->xy[1].disp.pos >= 432) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        break;
    }
}



void end_e02_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 408;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x18000;
        if (bgw_ptr->xy[1].disp.pos <= 352) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1600000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        return;
    case 2:
        break;
    }
}



void end_e02_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        bgw_ptr->r_no_1++;
        Bg_Off_W(4);
        break;
    case 2:
        break;
    }
}



void end_e02_7000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x20);
        effect_E6_init(0x21);
        effect_E6_init(0x22);
        break;
    case 1:
        if (bg_w.bgw[0].r_no_1 >= 4) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[1].cal -= 0x6000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        break;
    }
}
