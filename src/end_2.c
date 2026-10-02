/*
 * END_2.C  Ending 2 (end_02000)
 *
 * end_02000 runs a five-scene ending on the ending timer table, handing over to the
 * staff roll after the last scene. Scene handlers run on three layers: end_200_move (BG0),
 * end_201_move (BG1) and end_202_move (BG2). In scene 1 BG0 and BG1 scroll left while
 * cycling tile animations (end_200_3000_anime, end_201_1000_anim); other scenes place the
 * layers from the scene position table, start effect E6 objects and show the messages.
 * end_200_cell_set writes the initial BG0 and BG1 cells.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "end_main.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_2.h"

void end_201_1000_anim(void);



void end_02000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_2_tbl[end_w.r_no_2];
        load_char_gfx(0xE3F0, 1);
        end_200_cell_set();
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
            end_w.timer = timer_2_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_200_move();
        end_201_move();
        end_202_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_200_move(void) {
    void (*end_100_jp[5])() = { end_200_0000, end_200_1000, end_200_2000, end_200_3000, end_200_3000 };
    bgw_ptr = &bg_w.bgw[0];
    end_100_jp[end_w.r_no_2]();
}



void end_200_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x1E;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_y = 0xC000;
        }
        break;
    case 2:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y;
        if (bgw_ptr->xy[1].disp.pos <= 0x200) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2000000;
        }
        break;
    }
}



void end_200_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 3;
        bgw_ptr->l_limit = 0;
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x7C);
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        end_200_3000_anime();
        break;
    }
}



void end_200_3000_anime(void) {
    bgw_ptr->free--;
    if (bgw_ptr->free <= 0) {
        bgw_ptr->free = 3;
        bgw_ptr->l_limit++;
        bgw_ptr->l_limit &= 3;
        bgw_ptr->r_limit = end_200_1000_anm_tbl[bgw_ptr->l_limit];
        end_bg_block_attr_set(0, 0, 32, 0x1000, 32);
    }
}



void end_200_2000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(1);
        Rewrite_End_Message(3);
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x7D);
        effect_E6_init(0x7E);
        break;
    case 1:
        end_X_com01();
        break;
    }
}



void end_200_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 3:
            Rewrite_End_Message(4);
            bgw_ptr->free = 3;
            bgw_ptr->l_limit = 0;
            break;
        case 4:
            Rewrite_End_Message(5);
            effect_E6_init(0x80);
            end_fade_flag = 1;
            end_fade_timer = timer_2_tbl[end_w.r_no_2] - 120;
            break;
        }
        break;
    case 1:
        end_200_3000_anime();
        break;
    }
}



void end_201_move(void) {
    void (*end_202_jp[5])() = { end_X_com01, end_201_1000, end_X_com01, end_201_3000, end_201_3000 };
    bgw_ptr = &bg_w.bgw[1];
    end_202_jp[end_w.r_no_2]();
}



void end_201_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 4;
        bgw_ptr->l_limit = 0;
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
    case 2:
        end_201_1000_anim();
        break;
    }
}



void end_201_1000_anim(void) {
    bgw_ptr->free--;
    if (bgw_ptr->free <= 0) {
        bgw_ptr->free = 4;
        bgw_ptr->l_limit++;
        if (bgw_ptr->l_limit >= 10) {
            bgw_ptr->l_limit = 0;
        }
        bgw_ptr->r_limit = end_201_anm_tbl[bgw_ptr->l_limit];
        end_bg_block_attr_set(1, 0, 32, 0x1000, 32);
    }
}



void end_201_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        if (end_w.r_no_2 == 3) {
            bgw_ptr->free = 4;
            bgw_ptr->l_limit = 0;
        }
        break;
    case 1:
    case 2:
        end_201_1000_anim();
        break;
    }
}



void end_202_move(void) {
    void (*end_202_jp[5])() = { end_X_com01, end_202_1000, end_X_com01, end_202_3000, end_202_4000 };
    bgw_ptr = &bg_w.bgw[2];
    end_202_jp[end_w.r_no_2]();
}



void end_202_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0xC000;
        effect_E6_init(0x7B);
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos <= 0x80) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_202_3000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        effect_E6_init(0x7F);
        bgw_ptr->speed_x = 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos >= 560) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        return;
    case 2:
        break;
    }
}



void end_202_4000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        effect_E6_init(0x80);
        bgw_ptr->abs_x = 512;
        break;
    case 1:
        break;
    }
}



void end_200_cell_set(void) {
    s16 i;
    const PANEL* p;
    for (p = end_200_panel0, i = 0; i < 6; i++, p++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_200_scrn_data, 0, 0x220);
    }
    for (i = 0, p = end_200_panel1; i < 2; i++, p++) {
        bg_cell_write(1, p->ofs, p->cell, (u32)end_200_scrn_data, 0, 0x220);
    }
}
