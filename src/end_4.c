/*
 * END_4.C  Ending 4 (end_04000)
 *
 * end_04000 runs a five-scene ending on timer_4_tbl, calling the BG0, BG1 and BG2
 * scene handlers (end_400_move, end_401_move, end_402_move) each frame, and hands over to
 * the staff roll after the last scene. The scenes hold and drift the picture layers,
 * redraw the panel frames with end_waku_write, start effect E6 objects and effect H1, and
 * show the ending messages. end_400_cell_set writes the initial panel cells of BG0 and BG1.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "Com_Pl.h"
#include "VITAL.h"
#include "cmb_win.h"
#include "EFFF9.h"
#include "SE.h"
#include "bg_sub.h"
#include "end_main.h"
#include "effe6.h"
#include "EFFECT.h"
#include "EFFH1.h"
#include "aboutspr.h"
#include "end_4.h"



void end_04000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_4_tbl[end_w.r_no_2];
        load_char_gfx(0xE360, 1);
        end_400_cell_set();
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
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                bgm_request(0x2E);
                return;
            }
            if (end_w.r_no_2 == 2) {
                end_no_cut = 1;
            }
            end_w.timer = timer_4_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_400_move();
        end_401_move();
        end_402_move();
    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_400_move(void)
{
    void (**jp)() = end_400_jp;

    bgw_ptr = &bg_w.bgw[0];
    jp[end_w.r_no_2]();
}



void end_400_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = 720;
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0x8000;
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos < 416) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1A00000;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}



void end_400_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(2);
        bgw_ptr->free = 0x12C;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0x5000;
            bgw_ptr->speed_y = 0x3000;
            bgw_ptr->free = 0xF0;
        }
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}

void end_401_move(void)
{
    void (**jp)() = end_401_jp;

    bgw_ptr = &bg_w.bgw[1];
    jp[end_w.r_no_2]();
}



void end_401_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5D);
        effect_H1_init();
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos <= 0xA0) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_401_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5F);
        bgw_ptr->free = 0x12C;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0xA000;
            bgw_ptr->speed_y = 0x6000;
            bgw_ptr->free = 0xF0;
        }
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}



void end_401_2000(void) {

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        Rewrite_End_Message(0);
        effect_work_kill(4, 0x95);
        end_waku_write(0);
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        bg_w.center_x = 0xC0;
        bg_w.center_y = 0x70;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E, 0x1E);
        bg_w.frame_deff = 0x33;
        bg_w.frame_vol = 1;
        break;
    case 1:
        bgw_ptr->r_no_1++;
        end_no_cut = 0;
    case 2:
        bg_w.frame_vol--;
        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 1;
            bg_w.frame_deff--;
            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 0;
                break;
            }
            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }
        break;
    case 3:
        break;
    }
}



void end_401_3000(void) {

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        break;
    case 1:
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bg_w.center_x = 176;
        bg_w.center_y = 128;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E, 0x1E);
        bg_w.frame_deff = 48;
        bg_w.frame_vol = 1;
    case 2:
        bg_w.frame_vol--;
        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 1;
            bg_w.frame_deff--;
            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 0;
                break;
            }
            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }
        break;
    case 3:
        break;
    }
}



void end_401_4000(void) {

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        end_fade_flag = 1;
        end_fade_timer = timer_4_tbl[end_w.r_no_2] - 120;
        break;
    case 1:
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bg_w.center_x = 160;
        bg_w.center_y = 128;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E, 0x1E);
        bg_w.frame_deff = 0x2E;
        bg_w.frame_vol = 1;
    case 2:
        bg_w.frame_vol--;
        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 2;
            bg_w.frame_deff--;
            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 60;
                break;
            }
            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }
        break;
    case 3:
        break;
    }
}



void end_402_move(void) {
    bgw_ptr = &bg_w.bgw[2];
    end_402_jp[end_w.r_no_2]();
}



void end_402_0000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
        if (bgw_ptr->xy[0].disp.pos <= 0xA0) {
            bgw_ptr->r_no_1++;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    case 2:
        break;
    }
}



void end_402_1000(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5E);
        bgw_ptr->free = 0x12C;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0xA000;
            bgw_ptr->speed_y = 0x4000;
            bgw_ptr->free = 0xF0;
            break;
        }
        break;
    case 2:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    case 3:
        break;
    }
}



void end_400_cell_set(void) {
    s16 i;
    s16 j;
    const PANEL* p;
    for (j = 0; j < 2; j++) {
        p = end_400_panel_tbl[j];
        for (i = 0; i < 12; i++) {
            bg_cell_write(j, p->ofs, p->cell, (u32)end_400_scrn_data, 0, 0x220);
            p++;
        }
    }
}
