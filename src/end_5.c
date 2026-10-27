/*
 * end_5.c  Character ending 5 (end_05000)
 *
 * Scene script for one character ending, entered through end_main_jp[] from normal_ending in
 * end_main.c. end_05000 sets up the ending (common_end_init00/01, character graphics, BGM),
 * then steps through 13 scenes: each scene has a frame count in its timer table, and on expiry
 * the per-scene BG handlers are reset and the next scene begins. After the last scene it stops
 * the music, fades out to the staff roll and sets end_w.end_flag.
 * end_500_move / end_501_move dispatch the BG0 and BG1 handlers for the current scene through
 * jump tables; the handlers position the planes, print the ending text (Rewrite_End_Message),
 * start E6 ending effects, shake the screen (end_500_quake_y_sub) and scroll a looping BG1 strip
 * whose cells and palettes are rewritten as it wraps (end_5_bg1_cell_sub). end_500_cell_set
 * writes the initial BG0/BG1 cells.
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
#include "EFFF9.h"
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
#include "end_5.h"



extern const u8 end_5_bg1_cell_0[];

s8 end5_col_ix;  /* 02028264 */
s8 wr5_index;  /* 02028265 */
s16 end5_bg1_pos;  /* 02028266 */


/* 02006970 */
s8 end_5_bg1_cell[4] = {
    13, 14, 15, 13,
};
/* 02006974 */
/* provisional name */
/* The panel table and cell list of the ending 5 background, stored after end_5_bg1_cell. Nothing in the
   program refers to it. */
const void* end_5_bg1_refs[2] = {
    end_1100_bg0_cell_tbl,
    end_5_bg1_cell_0,
};
/* provisional name */
/* Stored after end_5_bg1_refs: steps 0 to 9. Nothing in the program refers to it. */
s16 end_5_bg1_steps[10][2] = {
    { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 },
    { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 },
};


void end_05000(u16 pl_num) {
    switch (end_w.r_no_1) {
    case END1_INIT:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        load_char_gfx(0xE170, 1);
        end_w.timer = timer_5_tbl[end_w.r_no_2];
        common_end_init01();
        end_500_cell_set();
        bgm_request(0x2D);
        break;
    case END1_SCENES:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;
            if (end_w.r_no_2 == 13) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                bgm_request(0x2E);
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }
            end_w.timer = timer_5_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }
        end_500_move();
        end_501_move();
    case END1_DONE:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}



void end_500_move(void) {
    void (*jmp_tbl[13])() = { end_500_comm, end_500_0001, end_500_0001, end_500_comm, end_500_comm, end_500_comm, end_500_0006, end_500_0007, end_500_0008, end_X_com01, end_X_com01, end_500_0011, end_X_com01 };
    bgw_ptr = &bg_w.bgw[0];
    jmp_tbl[end_w.r_no_2]();
}



void end_500_comm(void) {
    bgw_ptr = &bg_w.bgw[0];
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];
        switch (end_w.r_no_2) {
        case 0:
            Bg_On_W(1);
            Rewrite_End_Message(0);
            break;
        case 3:
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_y = 0;
            Rewrite_End_Message(3);
            break;
        case 4:
            effect_E6_init(0xB);
            Rewrite_End_Message(4);
            break;
        case 5:
            effect_E6_init(0xC);
            effect_E6_init(0xD);
            Rewrite_End_Message(5);
            break;
        }
    case 1:
        break;
    }
}



void end_500_0001(void) {
    bgw_ptr = bg_w.bgw;
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];
        bgw_ptr->frame_deff = 0;
        bgw_ptr->free = necro_quake_timer[bgw_ptr->frame_deff];
        switch (end_w.r_no_2) {
        case 1:
            effect_E6_init(9);
            Rewrite_End_Message(1);
            break;
        case 2:
            effect_E6_init(0xA);
            Rewrite_End_Message(2);
            break;
        }
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->frame_deff++;
            bgw_ptr->frame_deff &= 0x1F;
            bgw_ptr->free = necro_quake_timer[bgw_ptr->frame_deff];
            bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
            bgw_ptr->xy[0].disp.pos += necro_quake_tbl[bgw_ptr->frame_deff][0];
            bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];
            bgw_ptr->xy[1].disp.pos += necro_quake_tbl[bgw_ptr->frame_deff][1];
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_x += necro_quake_tbl[bgw_ptr->frame_deff][0];
            bgw_ptr->abs_y = 0;
            bgw_ptr->abs_y += necro_quake_tbl[bgw_ptr->frame_deff][1];
        }
        break;
    }
}



void end_500_0006(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(0x10, 0) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 0x1E;
        }
        break;
    case 3:
        break;
    }
}



void end_500_quake_y_sub(void) {
    bgw_ptr->frame_deff--;
    if (bgw_ptr->frame_deff <= 0) {
        bgw_ptr->frame_deff = 4;
        bg_w.quake_y_index++;
        bg_w.quake_y_index &= 7;
        bgw_ptr->xy[1].disp.pos += end_500_quake_tbl[bg_w.quake_y_index];
        bgw_ptr->abs_y += end_500_quake_tbl[bg_w.quake_y_index];
    }
}



void end_500_0007(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1);
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 768;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0xF);
        effect_E6_init(0x49);
        break;
    case 1:
        break;
    case 2:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x28;
        break;
    case 3:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 4:
        end_5_bg0_move_sub();
        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x11);
            bg_w.quake_y_index = 0;
            bgw_ptr->frame_deff = 4;
        }
        break;
    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos <= -128) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }
        break;
    }
}



void end_500_0008(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
    case 1:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos < -240) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x12);
        }
        break;
    case 2:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos < -624) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x14);
        }
        break;
    case 3:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos < -1008) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x15);
        }
        break;
    case 4:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos < -1376) {
            bgw_ptr->r_no_1++;
            end_etc_flag = 0;
            effect_E6_init(0x13);
        }
        break;
    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();
        if (bgw_ptr->xy[0].disp.pos < -1472) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 6:
        end_5_bg0_move_sub();
        if (bgw_ptr->xy[0].disp.pos <= -1856) {
            bgw_ptr->r_no_1++;
            end_w.timer = 18;
        }
        break;
    }
}



void end_500_0011(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        Rewrite_End_Message(6);
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;
    case 1:
        end_X_com01();
        break;
    }
}



void end_5_bg0_move_sub(void) {
    if (end_w.r_no_2 == 7) {
        bgw_ptr->xy[0].cal -= 0xA0000;
    } else {
        bgw_ptr->xy[0].cal -= 0x60000;
    }
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
}



void end_5_bg1_move_sub(void) {
    bgw_ptr->xy[0].cal -= 0x100000;
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
}



void end_5_bg1_move_sub2(void) {
    bgw_ptr->xy[0].cal += 0x180000;
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
}



const s16 necro_quake_tbl[32][2] = {
    { 2, -2 }, { 4, -4 }, { 6, -8 }, { 8, -4 }, { 6, 0 }, { 8, -4 }, { 4, 0 }, { 0, 0 },
    { -2, 0 }, { -4, 4 }, { -4, 8 }, { -6, 2 }, { 0, 6 }, { 4, 0 }, { -5, -4 }, { -5, 2 },
    { 0, 0 }, { 2, -4 }, { 4, -8 }, { 6, -10 }, { 2, 2 }, { -2, 6 }, { 0, 4 }, { 3, 1 },
    { 6, 0 }, { 4, -2 }, { -6, 4 }, { -2, 8 }, { 0, 0 }, { 6, 6 }, { 0, -8 }, { 4, 4 },
};


const s16 necro_quake_timer[32] = {
    4, 4, 4, 4, 8, 4, 4, 4,
    4, 4, 4, 4, 8, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 8, 4, 8,
};


const s16 end_500_quake_tbl[8] = {
    2, 4, -2, -4, -2, -4, 2, 4,
};


void end_501_move(void) {
    void (*end_500_jp[13])() = { end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_X_com01, end_501_0007, end_501_0008, end_501_0009, end_501_0010, end_501_0011, end_501_0012 };
    bgw_ptr = &bg_w.bgw[1];
    end_500_jp[end_w.r_no_2]();
}



void end_501_0007(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 0x200;
        bgw_ptr->xy[1].disp.pos = 0x300;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        end5_col_ix = 0;
        wr5_index = 0;
        end5_bg1_pos = 0x200;
    case 1:
        if (Request_Fade(0x11, 0) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 2:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
    case 3:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            bg_w.bgw[0].r_no_1 = 2;
        }
    case 4:
        end_5_bg1_move_sub();
        end_5_bg1_cell_sub(0);
        break;
    }
}



void end_501_0008(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
    case 1:
        end_5_bg1_move_sub();
        end_5_bg1_cell_sub(0);
        break;
    }
}

void end_501_0009(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        wr5_index--;
        break;
    case 1:
        end_5_bg1_move_sub2();
        end_5_bg1_cell_sub(1);
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }
        break;
    }
}



void end_501_0010(void) {
    end_5_bg1_move_sub2();
    end_5_bg1_cell_sub(1);
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(0x15, 0) == 0) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 0x1E;
        }
        break;
    case 2:
        break;
    }
}



void end_501_0011(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x10);
        bg_cell_write(1, 0, 16, (u32)end_500_scrn_data, 0, 0x220);
        bg_cell_write(1, 0x40, 17, (u32)end_500_scrn_data, 0, 0x220);
        bg_cell_write(1, 0x1000, 16, (u32)end_500_scrn_data, 0, 0x220);
        bg_cell_write(1, 0x1040, 17, (u32)end_500_scrn_data, 0, 0x220);
        if (!Request_Fade(22, 0)) {
            break;
        }
        bgw_ptr->r_no_1++;
        end_no_cut = 1;
        break;
    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1 += 1;
            end_no_cut = 0;
        }
    case 3:
        bgw_ptr->xy[1].cal += 0x40000;
        break;
    }
}



void end_501_0012(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(14);
        end_fade_flag = 1;
        end_fade_timer = timer_5_tbl[end_w.r_no_2] - 120;
    case 1:
        bgw_ptr->xy[1].cal += 0x40000;
        break;
    }
}



/* provisional name */
void end_5_bg1_cell_sub(s8 dir) {
    s16 pos;
    pos = bgw_ptr->xy[0].disp.pos & 0x300;
    if (end5_bg1_pos != pos) {
        end5_bg1_pos = pos;
        if (dir) {
            end5_col_ix++;
            if (end5_col_ix > 11) {
                end5_col_ix = 0;
            }
            wr5_index++;
            if (wr5_index > 3) {
                wr5_index = 0;
            }
            (&end_5_bg1_cell[0])[wr5_index] = end_5_bg1_cell_tbl[end5_col_ix];
            bg_cell_write(1, end_5_bg1_ofs_tbl[wr5_index], end_5_bg1_cell_tbl[end5_col_ix], (u32)end_500_scrn_data, 0, 0x220);
        } else {
            end5_col_ix--;
            if (end5_col_ix < 0) {
                end5_col_ix = 11;
            }
            wr5_index--;
            if (wr5_index < 0) {
                wr5_index = 3;
            }
            (&end_5_bg1_cell[0])[wr5_index] = end_5_bg1_cell_tbl[end5_col_ix];
            bg_cell_write(1, end_5_bg1_ofs_tbl[wr5_index], end_5_bg1_cell_tbl[end5_col_ix], (u32)end_500_scrn_data, 0, 0x220);
        }
    }
}



void end_500_cell_set(void) {
    s16 i;
    const PANEL* p;
    p = end_500_bg0_cell_tbl;
    for (i = 0; i < 12; i++) {
        bg_cell_write(0, p->ofs, p->cell, (u32)end_500_scrn_data, 0, 0x220);
        p++;
    }
    p = end_500_bg1_cell_tbl;
    for (i = 0; i < 10; i++) {
        bg_cell_write(1, p->ofs, p->cell, (u32)end_500_scrn_data, 0, 0x220);
        p++;
    }
}
