/*
 * END_20.C  Ending 20 (end_20000)
 *
 * end_20000 is the ending script: on entry it runs the common ending inits, allocates and
 * clears a line-scroll buffer for BG1, loads the graphics and music, then steps six timed
 * scenes calling the BG0 and BG1 handlers (end_2000_move, end_2001_move) until it fades to
 * the staff roll. Scenes scroll BG0 up or down, drift it, turn layers on and off, map BG1
 * onto the overlay scroll map, and start effect E6 objects with the ending messages.
 * end_2000_cell_set writes the initial BG0 and overlay cells.
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
#include "end_1.h"
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
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "effe6.h"
#include "aboutspr.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "end_20.h"



void end_20000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        bg_w.bgw[1].suzi_c_no = simmram_small_page_alloc_40(1);
        bg_w.bgw[1].suzi_adrs = (u16*)simmram_slot_addr(bg_w.bgw[1].suzi_c_no);
        scrn_linescroll_set_now(1, bg_w.bgw[1].suzi_adrs);
        memset(bg_w.bgw[1].suzi_adrs, 0, 0x1000);
        end_w.timer = timer_20_tbl[end_w.r_no_2];
        load_char_gfx(0xE2A0, 1);
        end_2000_cell_set();
        bgm_request(0x2C);
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
            end_w.timer = timer_20_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_2000_move();
        end_2001_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_2000_move(void) {
    void (*end_900_jp[6])() = { end_2000_0000, end_2000_0001, end_2000_0002, end_2000_0003, end_2000_0002, end_2000_0005 };
    bgw_ptr = &bg_w.bgw[0];
    end_900_jp[end_w.r_no_2]();
}



void end_2000_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x3E);
        Rewrite_End_Message(1);
        break;
    case 1:
        bgw_ptr->xy[0].cal += 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal += 0x4000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_2000_0001(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(2);
        effect_E6_init(0x3F);
        effect_E6_init(0x40);
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x4000;
        if (bgw_ptr->xy[1].disp.pos < 272) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1100000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_2000_0002(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        switch (end_w.r_no_2) {
        case 2:
            Rewrite_End_Message(3);
            break;
        case 4:
            Rewrite_End_Message(5);
            effect_E6_init(0x42);
            effect_E6_init(0x43);
            break;
        }
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        break;
    }
}



void end_2000_0003(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(4);
        effect_E6_init(0x91);
        effect_E6_init(0x92);
        effect_E6_init(0x93);
        effect_E6_init(0x94);
        effect_E6_init(0x95);
        break;
    case 1:
        bgw_ptr->xy[0].cal -= 0x4000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal += 0x6000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}



void end_2000_0005(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x44);
        effect_E6_init(0x45);
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_20_tbl[end_w.r_no_2] - 120;
        bgw_ptr->free = 0x5A;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal += 0x10000;
        if (bgw_ptr->xy[1].disp.pos > 544) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2200000;
        }
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}



void end_2001_move(void) {
    void (
        *end_2001_jp[6])() = { end_2001_0000, end_X_com01, end_2001_0002, end_2001_0003, end_2001_0004, end_2001_0005 };
    bgw_ptr = &bg_w.bgw[1];
    end_2001_jp[end_w.r_no_2]();
}



void end_2001_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        scrn_map_set_now(1, ake_scrl_w[0].adrs);
        scrn_map_set(1, ake_scrl_w[0].adrs);
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        effect_E6_init(0x38);
        break;
    case 1:
        break;
    }
}



void end_2001_0002(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x41);
        break;
    case 1:
        bgw_ptr->xy[0].disp.pos += 0x1000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}

void end_2001_0003(void)
{
    s16 *line;
    u16 i;
    s32 ix;
    XY work;

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Bg_On_W(0x20);
        Bg_On_W(2);
        ls_cnt1 = 0;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        break;
    case 1:
        ls_rate1 = 0x40;
        line = (s16 *)bg_w.bgw[1].suzi_adrs;
        for (i = 0; i < 512; i++) {
            ix = (ls_cnt1 + i * 4) & 0xFF;
            work.cal = (rate_256_table[ix][0] * ls_rate1) >> 4;
            *line = work.disp.pos;
            line += 2;
        }
        ls_cnt1 = (ls_cnt1 + 2) & 0x1FF;
        break;
    }
}



void end_2001_0004(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        Bg_Off_W(32);
    case 1:
        end_X_com01();
        break;
    }
}



void end_2001_0005(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
    case 1:
    case 2:
        break;
    }
}



void end_2000_cell_set(void) {
    s16 i;
    const PANEL* cell;
    cell = end_2000_bg0_cell_tbl;
    for (i = 0; i < 4; i++, cell++) {
        bg_cell_write(0, cell->ofs, cell->cell, (u32)end_2000_scrn_data, 0, 0x220);
    }
    cell = end_2000_ake_cell_tbl;
    for (i = 0; i < 4; i++, cell++) {
        end_ake_cell_put(0, cell->ofs, cell->cell, (u32)end_ake_scrn_data);
    }
}
