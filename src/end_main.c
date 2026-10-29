/*
 * end_main.c  Opening demo (second half) and character ending main control
 *
 * The first part holds the later bars of the opening demo: op_107_move..op_117_move step through
 * the scenes in time with the music sequence position, the Capcom splash/rights screen runs
 * from op_118_move, and op_bg0_xxxx / op_bg1_move drive the opening BG planes.
 * opening_title_00 and opening_title_01 set up the title and Capcom logo screens.
 * The ending part: Ending_init / Ending_main enter normal_ending, which clears the system, runs
 * the character's ending script through end_main_jp[], handles the continue-screen cards and
 * the cut (skip) button, fades to the staff roll and finally shows the winner's name. The shared
 * helpers used by the end_N modules live here too: common_end_init00/01 (scroll graphics
 * allocation and BG work setup), plane position/family updates, block attribute writes and the
 * BGM fade and fade-complete checks.
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
#include "Com_Pl.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "bg000.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "VITAL.h"
#include "count.h"
#include "cmb_win.h"
#include "efff7.h"
#include "efff8_code.h"
#include "EFFF9.h"
#include "fifo.h"
void bg_cell_write_yflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void bg_cell_write_xflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
void blit_16x16_tile();
void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, u16 u5, s16 attr);
void bg_cell_write_xyflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr);
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFE1.h"
#include "effe9.h"
#include "efff5.h"
#include "efff6.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "end_6.h"
#include "coin_cont.h"
#include "lose_pl.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "end_main.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "effe6.h"
#include "end_1.h"
#include "end_2.h"
#include "end_3.h"
#include "end_4.h"
#include "end_5.h"
#include "end_7.h"
#include "end_8.h"
#include "end_9.h"
#include "end_10.h"
#include "end_11.h"
#include "end_12.h"
#include "end_13.h"
#include "end_14.h"
#include "end_16.h"
#include "end_17.h"
#include "end_18.h"
#include "end_19.h"
#include "end_20.h"
#include "sc_trans.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFC1.h"
#include "PLS02.h"

/* end_w.r_no_0 in normal_ending */
#define END_INIT        0       /* clear the system and start the character's ending */
#define END_COVER       1       /* after Cover_Timer, set up the screen and wipe in */
#define END_REVIVAL     2       /* finish the wipe */
#define END_PLAY        3       /* the ending, until it ends or is cut */
#define END_TO_STAFF    4       /* fade out to the staff roll */
#define END_STAFF_SETUP 5       /* after the fade, set up the staff roll screen */
#define END_FRAME       6       /* draw the frame */
#define END_FADE_IN     7       /* fade the staff roll in */
#define END_FADE_WAIT   8       /* until the fade is done */
#define END_STAFF       9       /* the staff roll */
#define END_MUSIC       10      /* fade the music, longer when the name entry was cut short */
#define END_WAIT        11      /* wait end_w.timer */
#define END_DONE        12      /* finished */

extern s32 staff_r_no;

/* 02006860 */
void (*opening_move_jp[19])() = {
    op_100_move,
    op_101_move,
    op_102_move,
    op_103_move,
    op_104_move,
    op_105_move,
    op_106_move,
    op_107_move,
    op_108_move,
    op_109_move,
    op_110_move,
    op_111_move,
    op_112_move,
    op_113_move,
    op_114_move,
    op_115_move,
    op_116_move,
    op_117_move,
    op_118_move,
};
/* 020068AC */
s16 op_104_sound[8] = {
    0, 5, 6, 7, 9, 10, 11, 0,
};
/* 020068BC */
void (*end_main_jp[24])(s16) = {
    end_00000,
    end_01000,
    end_02000,
    end_03000,
    end_04000,
    end_05000,
    end_06000,
    end_07000,
    end_08000,
    end_09000,
    end_10000,
    end_11000,
    end_12000,
    end_13000,
    end_14000,
    end_14000,
    end_16000,
    end_17000,
    end_18000,
    end_19000,
    end_20000,
    end_01000,
    end_01000,
    end_01000,
};
/* 0200691C */
u32 end_map_tbl[4] = {
    (u32)end_map_data_0,
    (u32)end_map_data_1,
    (u32)end_map_data_2,
    (u32)end_map_data_3,
};


void Scrn_Move_Set(s32 n, s16 x, s16 y);
void scrn_attr_set(s16 n, u16 attr, u16 bits);



/* provisional name */
void op_w_clear(void) {
    op_w.r_no_0 = 0;
    op_w.r_no_1 = 0;
    op_w.r_no_2 = 0;
    op_w.index = 0;
    op_w.mv_ctr = 0;
}



void op_work_clear(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
    }
}



/* provisional name */
s16 opening_demo_tick(void) {
    void (*opening_demo_jp[3])() = { opening_init2, opening_move, opening_title };
    Game_timer += 1;
    opening_demo_jp[op_w.r_no_0]();
    update_all_disp_pos_ending();
    return op_end_flag;
}



void opening_init2(void) {
    Game_timer = 0;
    switch (op_w.r_no_1) {
    case 0:
        opning_init_00000();
        break;
    case 1:
        opning_init_01000();
        break;
    case 2:
        opning_init_02000();
        break;
    }
}



void opning_init_00000(void) {
    s16 i;
    op_w.r_no_1++;
    op_end_flag = 0;
    bg_vbl_trans_flag = 0;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    scr_cg_c_no = simmram_block_alloc_10(0x165, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = 3;
    polygon2d_submit_line(0x01D2C000, 0, 0, 3);
    polygon2d_submit_line(0x01D2C080, bg_w.scroll_cg_adr, 0x164AF, 1);
    if (Game_setting.mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    for (i = 0; i < 6; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0x2000000;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0x2000000;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].position_x = 0x200 - bg_w.pos_offset;
        bg_w.bgw[i].position_y = 0;
    }
    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, (u32)bg_w.bgw[i].bg_address);
        scrn_map_set(i, (u32)bg_w.bgw[i].bg_address);
        op_w.bgw[i].r_no_0 = 0;
        op_w.bgw[i].r_no_1 = 0;
        op_w.bgw[i].bg_no = i;
    }
    sprite_list_setup(0, 1, (s16*)op_scr_record_data_0);
    sprite_list_setup(1, 1, (s16*)op_scr_record_data_1);
    sprite_list_setup(2, 1, (s16*)op_scr_record_data_2);
    sprite_list_setup(3, 1, (s16*)op_scr_record_data_3);
clear_flags:
    op_w.r_no_2 = 0;
    op_end_flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    bg_w.chase_flag = 0;
}



void opning_init_01000(void) {
    s16 i;
    op_w.r_no_1++;
    for (i = 0; i < 4; i++) {
        Bg_On_R(1 << i);
        Bg_On_W(1 << i);
        scrn_attr_set(i, 0, 24);
        scrn_reg_w[i].ctrl &= 0xFE7F;
    }
    Bg_Off_R(0xFF);
    Bg_Off_W(0xFF);
    op_w.free_work = 8;
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    base_y_pos = 40;
    load_char_gfx(0xE3D0, 1);
    load_char_gfx(0xE470, 1);
    load_char_gfx(0xE520, 1);
}



/* provisional name */
void opning_init_02000(void) {
    op_w.free_work--;
    if (op_w.free_work < 0) {
        op_w.r_no_0++;
        op_w.r_no_1 = 0;
        op_w.r_no_2 = 0;
        wipe_pattern_set(0, 7, 0);
        scfont_page0_fill(0, 32);
    }
    Scrn_Move_Set(0, 512 - bg_w.pos_offset, 512);
    op_demo_index = 0;
    gSeqStatus[0] = 0;
    op_w.index = 0;
    op_sound_status = 0;
    op_plmove_timer = 0;
    if ((Demo_Sound == 0 && Demo_Flag == 0) || PB_Music_Off) {
        sound_reg_level_set(0, 128);
    } else {
        sound_reg_level_set(0, 0);
    }
}



void opening_move(void) {
    s16 work2;
    op_plmove_timer += 1;
    if (op_w.r_no_1 <= 17) {
        work2 = gSeqStatus[0];
        if (op_sound_status != work2) {
            if (work2 == op_change_sound_tbl[op_w.r_no_1]) {
                op_w.r_no_1 += 1;
                op_w.r_no_2 = 0;
                op_work_clear();
            }
        }
    }
    opening_move_jp[op_w.r_no_1]();
    op_sound_status = gSeqStatus[0];
}



void op_100_move(void) {
    op_w.r_no_1++;
    sound_request(1);
    wipe_pattern_set(0, 7, 0);
    scfont_page0_fill(0, 32);
    op_101_move();
}



void op_101_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        ToneDown(0);
        op_bg_move(0);
        effect_F6_init(0);
        effect_F6_init(1);
        op_obj_disp = 0;
        effect_48_init(0);
        break;
    case 1:
        if (gSeqStatus[0] >= op_101_sound[op_w.r_no_2] && gSeqStatus[0] != 101) {
            op_w.r_no_2 += 1;
            op_w.index = 1;
            op_obj_disp = 1;
            op_work_clear();
        } else {
            op_bg_move(0);
        }
        break;
    default:
        op_bg_move(1);
        break;
    }
}



void op_102_move(void) {
    register OP_W* r = &op_w;
    register s8 s = r->r_no_2;
    u8* g = gSeqStatus;
    s16* t = &op_102_sound[s];
    switch (s) {
    case 0:
        r->r_no_2++;
        r->index = 2;
        effect_F6_init(2);
        effect_F6_init(3);
        effect_F6_init(4);
        op_obj_disp = 0;
        effect_48_init(1);
        op_work_clear();
        op_bg_move(2);
        break;
    case 1:
        if (*g >= *t && *g != 102) {
            r->r_no_2++;
            r->index = 3;
            op_obj_disp = 1;
            op_work_clear();
            op_bg_move(3);
        } else {
            op_bg_move(2);
        }
        break;
    case 2:
        if (*g >= *t) {
            r->r_no_2++;
            r->index = 4;
            op_work_clear();
            op_bg_move(4);
        } else {
            op_bg_move(3);
        }
        break;
    default:
        op_bg_move(4);
        break;
    }
}



void op_103_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_w.index = 5;
        effect_F6_init(5);
        effect_F6_init(6);
        effect_F6_init(7);
        effect_F6_init(8);
        effect_F6_init(9);
        effect_F6_init(10);
        op_work_clear();
        op_bg_move(5);
        break;
    case 1:
        if ((*gSeqStatus >= op_103_tbl[op_w.r_no_2]) && (*gSeqStatus != 0x67)) {
            op_w.r_no_2 += 1;
            op_w.index = 6;
            op_work_clear();
            effect_F6_init(11);
            effect_F6_init(12);
            effect_F6_init(13);
            effect_F6_init(14);
            effect_F6_init(15);
            effect_F6_init(16);
        } else {
            op_bg_move(5);
        }
        break;
    case 2:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 7;
            op_obj_disp = 0;
            effect_48_init(8);
        } else {
            op_bg_move(6);
        }
        break;
    case 3:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 8;
            op_obj_disp = 1;
            op_scrn_end = 0;
            effect_36_init(22);
        } else {
            op_bg_move(7);
        }
        break;
    case 4:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 9;
        } else {
            op_bg_move(8);
        }
        break;
    case 5:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 10;
        } else {
            op_bg_move(9);
        }
        break;
    case 6:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 11;
        } else {
            op_bg_move(10);
        }
        break;
    case 7:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 12;
            op_obj_disp = 0;
            effect_48_init(9);
        } else {
            op_bg_move(11);
        }
        break;
    case 8:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 13;
            op_obj_disp = 1;
        } else {
            op_bg_move(12);
        }
        break;
    case 9:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 14;
            op_scrn_end = 0;
            effect_36_init(23);
        } else {
            op_bg_move(13);
        }
        break;
    case 10:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 15;
        }
        op_bg_move(14);
        break;
    case 11:
        if (*gSeqStatus >= op_103_tbl[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 16;
        } else {
            op_bg_move(15);
        }
        break;
    default:
        op_bg_move(16);
        break;
    }
}



void op_104_move(void) {
    s16* e = &op_obj_disp;
    OP_W* r = &op_w;
    s8 s = r->r_no_2;
    u8* g = gSeqStatus;
    s16* t = &op_104_sound[s];
    switch (s) {
    case 0:
        r->r_no_2++;
        op_work_clear();
        r->index = 17;
        op_bg_move(17);
        effect_F6_init(17);
        effect_F6_init(18);
        effect_F6_init(19);
        effect_F6_init(20);
        effect_F6_init(21);
        effect_F6_init(22);
        effect_F6_init(23);
        break;
    case 1:
        if (*g >= *t && *g != 104) {
            r->r_no_2++;
            op_work_clear();
            r->index = 18;
        } else {
            op_bg_move(17);
        }
        break;
    case 2:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 19;
            *e = 0;
            effect_48_init(10);
        } else {
            op_bg_move(18);
        }
        break;
    case 3:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 20;
            *e = 1;
        } else {
            op_bg_move(19);
        }
        break;
    case 4:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 21;
            *e = 0;
            effect_48_init(11);
        } else {
            op_bg_move(20);
        }
        break;
    case 5:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 22;
            *e = 1;
        } else {
            op_bg_move(21);
        }
        break;
    case 6:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 23;
        } else {
            op_bg_move(22);
        }
        break;
    case 7:
        op_bg_move(23);
        break;
    default:
        op_bg_move(23);
        break;
    }
}



void op_105_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        purge_char_gfx(0xE520);
        load_char_gfx(0xE528, 1);
        op_work_clear();
        op_w.index = 24;
        op_bg_move(24);
        effect_F6_init(24);
        op_obj_disp = 0;
        effect_48_init(12);
        break;
    case 1:
    default:
        op_bg_move(24);
        break;
    }
}



void op_106_move(void) {
    OP_W* r = &op_w;
    u8* g = gSeqStatus;
    s8 s = r->r_no_2;
    register s16* t = &op_106_sound[s];
    switch (s) {
    case 0:
        r->r_no_2++;
        op_work_clear();
        r->index = 25;
        op_obj_disp = 1;
        op_bg_move(25);
        effect_F6_init(25);
        effect_F6_init(26);
        effect_F6_init(27);
        effect_F6_init(28);
        effect_36_init(18);
        effect_36_init(19);
        effect_36_init(20);
        effect_36_init(21);
        break;
    case 1:
        if (*g >= *t && *g != 106) {
            r->r_no_2++;
            op_work_clear();
            r->index = 26;
        } else {
            op_bg_move(25);
        }
        break;
    case 2:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 27;
        } else {
            op_bg_move(26);
        }
        break;
    case 3:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 28;
            op_obj_disp = 0;
            effect_48_init(15);
        } else {
            op_bg_move(27);
        }
        break;
    default:
        op_bg_move(28);
        break;
    }
}



void op_107_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_obj_disp = 1;
        op_w.r_no_2++;
        op_work_clear();
        op_w.index = 29;
        op_bg_move(29);
        effect_F6_init(29);
        effect_F6_init(30);
        effect_F6_init(31);
        effect_F6_init(32);
        effect_F6_init(33);
        effect_F6_init(34);
        break;
    case 1:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2] && gSeqStatus[0] != 107) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 30;
        } else {
            op_bg_move(29);
        }
        break;
    case 2:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 31;
        } else {
            op_bg_move(30);
        }
        break;
    case 3:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 32;
            op_obj_disp = 0;
            effect_48_init(13);
        } else {
            op_bg_move(31);
        }
        break;
    case 4:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 33;
            op_obj_disp = 1;
        } else {
            op_bg_move(32);
        }
        break;
    case 5:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 34;
            effect_F6_init(35);
            effect_F6_init(36);
            effect_F6_init(37);
            effect_F6_init(38);
            effect_F6_init(39);
            effect_F6_init(40);
        } else {
            op_bg_move(33);
        }
        break;
    case 6:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 35;
        } else {
            op_bg_move(34);
        }
        break;
    case 7:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 36;
            op_obj_disp = 0;
            effect_48_init(14);
        } else {
            op_bg_move(35);
        }
        break;
    case 8:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 37;
            op_obj_disp = 1;
        } else {
            op_bg_move(36);
        }
        break;
    case 9:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 38;
        } else {
            op_bg_move(37);
        }
        break;
    case 10:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 39;
        } else {
            op_bg_move(38);
        }
        break;
    case 11:
        if (gSeqStatus[0] >= op_107_tbl[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 40;
        } else {
            op_bg_move(39);
        }
        break;
    default:
        op_bg_move(40);
        break;
    }
}



/* provisional name */
void op_108_move(void) {
    s16* t = op_108_sound;
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        purge_char_gfx(0xE528);
        load_char_gfx(0xE530, 1);
        load_char_gfx(0xE538, 1);
        op_work_clear();
        op_w.index = 41;
        op_bg_move(41);
        op_w.mv_ctr = 0;
        effect_36_init(0);
        effect_36_init(1);
        effect_36_init(2);
        effect_36_init(3);
        effect_36_init(4);
        effect_36_init(5);
        effect_36_init(6);
        effect_36_init(7);
        break;
    case 1:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 42;
            op_bg_move(42);
        }
        break;
    case 2:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 43;
            op_bg_move(43);
            effect_36_init(8);
            effect_36_init(9);
            effect_36_init(10);
            effect_36_init(11);
            effect_36_init(12);
            effect_36_init(13);
            effect_36_init(14);
            effect_36_init(15);
        }
        break;
    case 3:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 44;
            op_bg_move(44);
        }
        break;
    case 4:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 45;
            op_bg_move(45);
        }
        break;
    case 5:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 46;
            op_bg_move(46);
        }
        break;
    case 6:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 47;
            op_bg_move(47);
        }
        break;
    case 7:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 48;
            op_bg_move(48);
        }
        break;
    case 8:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 49;
            op_bg_move(49);
        }
        break;
    case 9:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 50;
            op_bg_move(50);
        }
        break;
    case 10:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 51;
            op_bg_move(51);
        }
        break;
    case 11:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 52;
            op_bg_move(52);
        }
        break;
    case 12:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= t[op_w.r_no_2]) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 53;
            op_bg_move(53);
        }
        break;
    }
}



void op_109_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        purge_char_gfx(0xE530);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 54;
        op_bg_move(54);
        op_obj_disp = 0;
        effect_48_init(16);
        break;
    case 1:
        if ((*gSeqStatus >= op_109_sound[op_w.r_no_2]) && (*gSeqStatus != 0x6D)) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 55;
            op_obj_disp = 1;
        } else {
            op_bg_move(54);
        }
        break;
    case 2:
        if (*gSeqStatus >= op_109_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 56;
        } else {
            op_bg_move(55);
        }
        break;
    case 3:
        if (*gSeqStatus >= op_109_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 57;
            op_obj_disp = 0;
            effect_48_init(17);
        } else {
            op_bg_move(56);
        }
        break;
    case 4:
        if (*gSeqStatus >= op_109_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 58;
            op_obj_disp = 1;
        } else {
            op_bg_move(57);
        }
        break;
    default:
        op_bg_move(58);
        break;
    }
}



void op_110_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_work_clear();
        op_w.index = 59;
        op_bg_move(59);
        op_obj_disp = 0;
        effect_48_init(2);
        break;
    case 1:
        if ((*gSeqStatus >= op_110_sound[op_w.r_no_2]) && (*gSeqStatus != 0x6E)) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 60;
            op_obj_disp = 1;
        } else {
            op_bg_move(59);
        }
        break;
    case 2:
        if (*gSeqStatus >= op_110_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 61;
            op_obj_disp = 0;
            effect_48_init(3);
        } else {
            op_bg_move(60);
        }
        break;
    case 3:
        if (*gSeqStatus >= op_110_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 62;
            op_obj_disp = 1;
        } else {
            op_bg_move(61);
        }
        break;
    case 4:
        if (*gSeqStatus >= op_110_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 63;
            op_obj_disp = 0;
            effect_48_init(4);
        } else {
            op_bg_move(62);
        }
        break;
    case 5:
        if (*gSeqStatus >= op_110_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 64;
            op_obj_disp = 1;
        } else {
            op_bg_move(63);
        }
        break;
    default:
        op_bg_move(64);
        break;
    }
}



void op_111_move(void) {
    OP_W* r = &op_w;
    u8* g = gSeqStatus;
    s8 s = r->r_no_2;
    s16* t = &op_111_sound[s];
    switch (s) {
    case 0:
        r->r_no_2++;
        op_work_clear();
        r->index = 0x41;
        op_bg_move(0x41);
        effect_F6_init(0x29);
        effect_F6_init(0x2A);
        effect_F6_init(0x2B);
        break;
    case 1:
        if (*g >= *t && *g != 0x6F) {
            r->r_no_2++;
            op_work_clear();
            r->index = 0x42;
        } else {
            op_bg_move(0x41);
        }
        break;
    case 2:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 0x43;
        } else {
            op_bg_move(0x42);
        }
        break;
    case 3:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 0x44;
        } else {
            op_bg_move(0x43);
        }
        break;
    case 4:
        if (*g >= *t) {
            r->r_no_2++;
            op_work_clear();
            r->index = 0x45;
        } else {
            op_bg_move(0x44);
        }
        break;
    default:
        op_bg_move(0x45);
        break;
    }
}



void op_112_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_work_clear();
        op_w.index = 70;
        op_bg_move(70);
        effect_F6_init(54);
        effect_F6_init(44);
        effect_F6_init(45);
        effect_F6_init(46);
        effect_F6_init(47);
        effect_F6_init(48);
        effect_F6_init(49);
        effect_F6_init(50);
        effect_F6_init(51);
        break;
    case 1:
        if (gSeqStatus[0] >= op_112_sound[op_w.r_no_2] && gSeqStatus[0] != 112) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 71;
            op_w.mv_ctr = 0;
        } else {
            op_bg_move(70);
        }
        break;
    case 2:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 72;
        } else {
            op_bg_move(71);
        }
        break;
    case 3:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 73;
            op_obj_disp = 0;
            effect_48_init(18);
        } else {
            op_bg_move(72);
        }
        break;
    case 4:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 74;
            op_obj_disp = 1;
        } else {
            op_bg_move(73);
        }
        break;
    case 5:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 75;
        } else {
            op_bg_move(74);
        }
        break;
    case 6:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 76;
            op_obj_disp = 0;
            effect_48_init(19);
        } else {
            op_bg_move(75);
        }
        break;
    case 7:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 = op_w.r_no_2 + 1;
            op_work_clear();
            op_w.index = 77;
            op_obj_disp = 1;
        } else {
            op_bg_move(76);
        }
        break;
    case 8:
        op_w.mv_ctr++;
        if (op_w.mv_ctr >= op_112_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 78;
        } else {
            op_bg_move(77);
        }
        break;
    default:
        op_bg_move(78);
        break;
    }
}



void op_113_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        purge_char_gfx(0xE538);
        op_scrn_end = 0;
        op_work_clear();
        op_w.index = 79;
        op_bg_move(79);
        effect_F6_init(52);
        effect_F6_init(53);
        op_obj_disp = 0;
        effect_48_init(20);
        break;
    case 1:
        if ((gSeqStatus[0] >= op_113_sound[op_w.r_no_2]) && (gSeqStatus[0] != 0x71)) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 80;
            op_obj_disp = 1;
        } else {
            op_bg_move(79);
        }
        break;
    case 2:
        if (gSeqStatus[0] >= op_113_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_scrn_end = 0;
            op_work_clear();
            op_w.index = 81;
            op_obj_disp = 0;
            effect_48_init(21);
        } else {
            op_bg_move(80);
        }
        break;
    case 3:
        if (gSeqStatus[0] >= op_113_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 82;
            op_obj_disp = 1;
        } else {
            op_bg_move(81);
        }
        break;
    default:
        op_bg_move(82);
        break;
    }
}



void op_114_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_work_clear();
        op_w.index = 83;
        op_bg_move(83);
        op_obj_disp = 0;
        effect_48_init(5);
        break;
    case 1:
        if ((*gSeqStatus >= op_114_sound[op_w.r_no_2]) && (*gSeqStatus != 0x72)) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 84;
            op_obj_disp = 1;
        } else {
            op_bg_move(83);
        }
        break;
    case 2:
        if (*gSeqStatus >= op_114_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 85;
            op_obj_disp = 0;
            effect_48_init(6);
        } else {
            op_bg_move(84);
        }
        break;
    case 3:
        if (*gSeqStatus >= op_114_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 86;
            op_obj_disp = 1;
        } else {
            op_bg_move(85);
        }
        break;
    case 4:
        if (*gSeqStatus >= op_114_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 87;
            op_obj_disp = 0;
            effect_48_init(7);
        } else {
            op_bg_move(86);
        }
        break;
    case 5:
        if (*gSeqStatus >= op_114_sound[op_w.r_no_2]) {
            op_w.r_no_2 += 1;
            op_work_clear();
            op_w.index = 88;
            op_obj_disp = 1;
        } else {
            op_bg_move(87);
        }
        break;
    default:
        op_bg_move(88);
        break;
    }
}



void op_115_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        op_work_clear();
        op_w.index = 0x59;
        op_bg_move(0x59);
        effect_36_init(0x10);
        break;
    case 1:
        if (gSeqStatus[0] >= op_115_sound[op_w.r_no_2] && gSeqStatus[0] != 0x73) {
            op_w.r_no_2++;
            op_work_clear();
            op_w.index = 0x5A;
        } else {
            op_bg_move(0x59);
        }
        break;
    default:
        op_bg_move(0x5A);
        break;
    }
}

void op_116_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2++;
        op_work_clear();
        op_w.index = 0x5B;
        op_bg_move(0x5B);
        effect_36_init(0x11);
        effect_36_init(0x1C);
        op_w.mv_ctr = 0x58;
        break;
    case 1:
        op_bg_move(0x5B);
        op_w.mv_ctr--;
        if (op_w.mv_ctr > 0) {
            break;
        }
        op_w.r_no_2++;
    case 2:
        if (Request_Fade(0x29, 0) == 0) {
            break;
        }
        op_w.r_no_2++;
        effect_F6_init(0x37);
        effect_F6_init(0x38);
        effect_F6_init(0x39);
        effect_F6_init(0x3A);
        effect_F6_init(0x3B);
        effect_F6_init(0x3C);
        op_bg_move(0x5B);
        break;
    case 3:
        if (Check_Fade_Complete() != 0) {
            op_w.r_no_2++;
        }
        op_bg_move(0x5B);
        break;
    default:
        op_bg_move(0x5B);
        break;
    }
}



void op_117_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        Zoomf_Init();
        op_work_clear();
        op_w.index = 92;
        op_bg_move(92);
        effect_E1_init(1, 0, 1);
        effect_E1_init(0, 0, 1);
        effect_F5_init(16);
        effect_F5_init(17);
        effect_F5_init(18);
        effect_F5_init(9);
        op_bg_move(92);
        op_w.r_no_1 += 1;
        op_w.r_no_2 = 0;
        op_work_clear();
        break;
    }
}



/* provisional name */
void op_118_move(void) {
    switch (op_w.r_no_2) {
    case 0:
        op_w.r_no_2 += 1;
        op_w.mv_ctr = 60;
        break;
    case 1:
        op_w.mv_ctr -= 1;
        if (op_w.mv_ctr < 0) {
            op_w.r_no_2 += 1;
        }
        break;
    case 2:
        if (Request_Fade(0x28, 0) != 0) {
            op_w.r_no_2 += 1;
        }
        break;
    case 3:
        if (Check_Fade_Complete() != 0) {
            op_w.r_no_2 += 1;
            Disp_Capcom_Rights();
            op_w.mv_ctr = 240;
        }
        op_w.index = 93;
        op_bg_move(93);
        break;
    case 4:
        op_w.mv_ctr -= 1;
        if (op_w.mv_ctr < 0) {
            op_w.r_no_2 += 1;
        }
        break;
    case 5:
        op_end_flag = 1;
        Bg_Off_W(0xFE);
        if ((Demo_Sound == 0 && Demo_Flag == 0) || PB_Music_Off) {
            sound_reg_level_set(0, 0);
        }
        op_bg_move(93);
        break;
    }
}


/* provisional name */
void op_119_move(void) {}



/* provisional name */
void op_bg_off(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_Off_W(1 << opw_ptr->bg_no);
        break;
    case 1:
        break;
    }
}



void op_bg_move(r_index)
s16 r_index;
{
    op_bg0_move(r_index);
    op_bg1_move(r_index);
    op_bg2_move(r_index);
}



const s16 op_101_sound[2] = {
    0, 11,
};


const s16 op_102_sound[3] = {
    0, 9, 12,
};


const s16 op_103_tbl[12] = {
    0, 1, 2, 3, 4, 5, 7, 8,
    9, 11, 12, 13,
};


const s16 op_106_sound[4] = {
    0, 1, 3, 7,
};


const s16 op_107_tbl[12] = {
    0, 1, 2, 3, 4, 5, 7, 8,
    9, 11, 12, 13,
};


const s16 op_108_sound[13] = {
    0, 4, 20, 24, 28, 32, 48, 52,
    60, 64, 76, 80, 86,
};


const s16 op_109_sound[5] = {
    0, 3, 5, 7, 11,
};


const s16 op_110_sound[6] = {
    0, 0, 3, 4, 7, 9,
};


const s16 op_111_sound[5] = {
    0, 2, 4, 7, 11,
};


const s16 op_112_sound[9] = {
    0, 8, 8, 14, 19, 26, 34, 40,
    44,
};


const s16 op_113_sound[4] = {
    0, 3, 7, 11,
};


const s16 op_114_sound[6] = {
    0, 2, 3, 4, 7, 9,
};


const s16 op_115_sound[2] = {
    0, 7,
};


/* provisional name */
void op_bg0_move(r_index)
s16 r_index;
{
    void (*op_bg0_move_jp[94])() = {
        op_bg0_0000, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0001,
        op_bg0_0000, op_bg0_0001, op_bg0_0015, op_bg0_0001, op_bg0_0000, op_bg0_0001,
        op_bg0_0001, op_bg0_0000, op_bg0_0015, op_bg0_0001, op_bg0_0000, op_bg0_0000,
        op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000,
        op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000, op_bg0_0000,
        op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001,
        op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0002,
        op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002,
        op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0002, op_bg0_0003, op_bg0_0000,
        op_bg0_0004, op_bg0_0001, op_bg0_0001, op_bg0_0004, op_bg0_0005, op_bg0_0002,
        op_bg0_0001, op_bg0_0002, op_bg0_0001, op_bg0_0002, op_bg0_0006, op_bg0_0001,
        op_bg0_0001, op_bg0_0001, op_bg0_0007, op_bg0_0008, op_bg0_0000, op_bg0_0000,
        op_bg0_0001, op_bg0_0001, op_bg0_0000, op_bg0_0001, op_bg0_0001, op_bg0_0000,
        op_bg0_0000, op_bg0_0004, op_bg0_0001, op_bg0_0004, op_bg0_0001, op_bg0_0002,
        op_bg1_0003, op_bg0_0002, op_bg0_0010, op_bg0_0002, op_bg0_0011, op_bg0_0012,
        op_bg0_0013, op_bg0_0014, op_bg0_0002, op_bg0_0016,
    };
    opw_ptr = &op_w.bgw[0];
    bgw_ptr = &bg_w.bgw[0];
    op_bg0_move_jp[r_index](r_index);
}



void op_bg0_0000(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_Off_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0001(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        switch (r_index) {
        case 1:
            bg_cell_write(0, 0x3040, 48, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 49, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 3:
            bg_cell_write_yflip(0, 0x3040, 70, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write_yflip(0, 0x3080, 71, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 4:
        case 22:
        case 33:
            bg_cell_write_xflip(0, 0x3080, 52, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write_xflip(0, 0x3040, 53, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 7:
            bg_cell_write(0, 0x3040, 64, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write(0, 0x3080, 65, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        case 9:
        case 72:
            bg_cell_write(0, 0x3040, 50, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write(0, 0x3080, 51, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        case 11:
        case 30:
            bg_cell_write_xflip(0, 0x3080, 50, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write_xflip(0, 0x3040, 51, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 12:
            bg_cell_write(0, 0x3040, 68, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write(0, 0x3080, 69, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        case 15:
            bg_cell_write_xflip(0, 0x3080, 52, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write_xflip(0, 0x3040, 53, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        case 18:
            bg_cell_write_yflip(0, 0x3040, 50, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write_yflip(0, 0x3080, 51, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 19:
            bg_cell_write(0, 0x3040, 72, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 73, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 21:
            bg_cell_write(0, 0x3040, 56, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 0, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 31:
            bg_cell_write(0, 0x3040, 74, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 75, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 32:
            bg_cell_write(0, 0x3040, 76, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 77, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 35:
            bg_cell_write(0, 0x3040, 74, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            bg_cell_write(0, 0x3080, 75, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            break;
        case 36:
            bg_cell_write(0, 0x3040, 76, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            bg_cell_write(0, 0x3080, 77, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            break;
        case 38:
            bg_cell_write(0, 0x3040, 52, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            bg_cell_write(0, 0x3080, 53, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            break;
        case 39:
            bg_cell_write(0, 0x3040, 52, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            bg_cell_write(0, 0x3080, 53, (u32)&op_bg0_scrn_data, 0, 0x2C8);
            break;
        case 55:
        case 56:
            bg_cell_write(0, 0x3040, 78, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 79, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 60:
        case 62:
        case 80:
        case 82:
            bg_cell_write(0, 0x3040, 88, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 89, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 65:
            bg_cell_write(0, 0x3040, 80, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 81, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 66:
            bg_cell_write(0, 0x3040, 82, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 83, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 73:
            bg_cell_write(0, 0x3040, 84, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 85, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 75:
            bg_cell_write_xyflip(0, 0x3080, 84, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write_xyflip(0, 0x3040, 85, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 76:
            bg_cell_write(0, 0x3040, 86, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 87, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        }
    case 1:
        bgw_ptr->free -= 1;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->frame_deff += 1;
            bgw_ptr->frame_deff &= 0xF;
            bgw_ptr->xy[1].disp.pos += op_quake_y_tbl0[bgw_ptr->frame_deff];
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0002(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        Bg_On_W(1);
        if (r_index == 0x57) {
            Zoomf_Init();
        }
        bgw_ptr->wxy[0].cal = 0x02000000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 0x39, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 0x39, (u32)&op_bg0_scrn_data[0], 0, 0x2C0);
        break;
    case 1:
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0003(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 = opw_ptr->r_no_0 + 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        switch (r_index) {
        case 42:
            bg_cell_write(0, 0x3040, 36, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 37, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 44:
            bg_cell_write(0, 0x3040, 38, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 39, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 46:
            bg_cell_write(0, 0x3040, 40, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 41, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 48:
            bg_cell_write(0, 0x3040, 42, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 43, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 50:
            bg_cell_write(0, 0x3040, 44, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 45, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        case 52:
            bg_cell_write(0, 0x3040, 46, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            bg_cell_write(0, 0x3080, 47, (u32)&op_bg0_scrn_data, 0, 0x2C0);
            break;
        }
        break;
    case 1:
        break;
    default:
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0004(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 57, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 57, (u32)op_bg0_scrn_data, 0, 0x2C0);
        break;
    case 3:
        break;
    case 1:
        if (!op_scrn_end) {
            break;
        }
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
    case 2:
        bgw_ptr->free -= 1;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit += 1;
            if (bgw_ptr->l_limit >= 6) {
                opw_ptr->r_no_0 += 1;
            } else {
                bgw_ptr->free = 1;
                oh_opening_demo(bgw_ptr->bg_address, 32, 32, 0x1800, 16, 0x2C0, op_bg0_0004_tbl[bgw_ptr->l_limit]);
            }
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0005(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 5, (u32)op_bg0_scrn_data, 0, 0x2CB);
        bg_cell_write(0, 0x3080, 6, (u32)op_bg0_scrn_data, 0, 0x2CB);
        bgw_ptr->frame_deff = 12;
        Frame_Up(0xC0, 0xE0, bgw_ptr->frame_deff, bgw_ptr->frame_deff);
        break;
    case 1:
        bgw_ptr->frame_deff -= 2;
        if (bgw_ptr->frame_deff <= 0) {
            opw_ptr->r_no_0 += 1;
            Zoomf_Init();
            bgw_ptr->free = 0;
            bgw_ptr->wxy[0].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
            bgw_ptr->xy[1].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
        } else {
            Frame_Down(0xC0, 0xE0, 2, 2);
        }
        break;
    case 2:
        bgw_ptr->free += 1;
        if (bgw_ptr->free >= 16) {
            opw_ptr->r_no_0 += 1;
        } else {
            bgw_ptr->wxy[0].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
            bgw_ptr->xy[1].disp.pos += op_bg0_0005_tbl[bgw_ptr->free];
        }
        break;
    default:
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0006(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        bgw_ptr->free = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x00C00000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3000, 0xD, (u32)op_bg0_scrn_data, 0, 0x2DB);
        bg_cell_write(0, 0x3040, 0xE, (u32)&op_bg0_scrn_data[0], 0, 0x2DB);
        bg_cell_write(0, 0x3080, 0xF, (u32)&op_bg0_scrn_data, 0, 0x2DB);
        break;
    case 1:
        bgw_ptr->wxy[0].cal += 0x40000;
        if (bgw_ptr->wxy[0].disp.pos > 0x2C0) {
            opw_ptr->r_no_0++;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0007(s16 r_index) {
    BGW** pp = &bgw_ptr;

    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        (*pp)->free = 1;
        (*pp)->frame_deff = 0;
        Bg_On_W(1);
        (*pp)->wxy[0].cal = 0x1D00000;
        (*pp)->xy[1].cal = 0xFFF00000;
        bg_cell_write(0, 0x3040, 0x16, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 0x17, (u32)&op_bg0_scrn_data[0], 0, 0x2C0);
        break;
    case 1:
        if ((*pp)->wxy[0].disp.pos < 0x200) {
            (*pp)->wxy[0].cal += 0xC000;
        } else {
            (*pp)->wxy[0].cal = 0x2000000;
        }
        if ((*pp)->xy[1].disp.pos < 0) {
            (*pp)->xy[1].cal += 0x4000;
        } else {
            (*pp)->xy[1].cal = 0;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0008(s16 r_index) {
    BGW** pp = &bgw_ptr;

    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        (*pp)->free = 1;
        (*pp)->frame_deff = 0;
        Bg_On_W(1);
        (*pp)->wxy[0].cal = 0x2300000;
        (*pp)->xy[1].cal = 0xFFF00000;
        bg_cell_write_xflip(0, 0x3080, 0x16, (u32)op_bg0_scrn_data, 0, 0x2C1);
        bg_cell_write_xflip(0, 0x3040, 0x17, (u32)&op_bg0_scrn_data[0], 0, 0x2C1);
    case 1:
        if ((*pp)->wxy[0].disp.pos > 0x200) {
            (*pp)->wxy[0].cal -= 0xC000;
        } else {
            (*pp)->wxy[0].cal = 0x2000000;
        }
        if ((*pp)->xy[1].disp.pos < 0) {
            (*pp)->xy[1].cal += 0x4000;
        } else {
            (*pp)->xy[1].cal = 0;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0009(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x02000000;
        bgw_ptr->xy[1].cal = -0x100000;
        bg_cell_write(0, 0x3040, 0x18, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 0x19, (u32)&op_bg0_scrn_data[0], 0, 0x2C0);
    case 1:
        bgw_ptr->xy[1].cal += 0x8000;
        if (bgw_ptr->xy[1].disp.pos >= 0) {
            opw_ptr->r_no_0++;
            bgw_ptr->xy[1].cal = 0;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0010(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 18, (u32)op_bg0_scrn_data, 0, 0x2E3);
        bg_cell_write(0, 0x3080, 19, (u32)op_bg0_scrn_data, 0, 0x2E3);
        break;
    case 1:
        opw_ptr->r_no_0 += 1;
        break;
    case 2:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->frame_deff = 12;
        Frame_Up(0xC0, 0xE0, bgw_ptr->frame_deff, bgw_ptr->frame_deff);
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0011(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_On_W(1);
        Zoomf_Init();
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        bg_cell_write(0, 0x3040, 20, (u32)op_bg0_scrn_data, 0, 0x2CB);
        bg_cell_write(0, 0x3080, 21, (u32)op_bg0_scrn_data, 0, 0x2CB);
        break;
    case 1:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->frame_deff = 56;
        Frame_Up(0xC0, 0x40, bgw_ptr->frame_deff, bgw_ptr->frame_deff);
        bgw_ptr->xy[1].cal = 0xFFE00000;
    case 2:
        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].cal += 0x20000;
        }
        if (bgw_ptr->frame_deff > 0) {
            bgw_ptr->frame_deff -= 1;
            Frame_Down(0xC0, 0x40, 1, 1);
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0012(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        Bg_On_W(1);
        Zoomf_Init();
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0x1000000;
        bg_cell_write(0, 0x2040, 30, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 31, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 32, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 33, (u32)op_bg0_scrn_data, 0, 0x2C0);
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0x20000;
        if (bgw_ptr->xy[1].disp.pos <= 0x60) {
            opw_ptr->r_no_0 += 1;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0013(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->frame_deff = 0;
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0x600000;
        bg_cell_write(0, 0x2040, 34, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x2080, 35, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3040, 60, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 61, (u32)op_bg0_scrn_data, 0, 0x2C0);
        break;
    case 1:
        bgw_ptr->xy[1].cal += 0x20000;
        if (bgw_ptr->xy[1].disp.pos > 0x100) {
            opw_ptr->r_no_0 += 1;
        }
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0014(s16 r_index) {
    op_bg0_0000(r_index);
}



void op_bg0_0015(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        switch (r_index) {
        case 8:
            bg_cell_write(0, 0x3040, 66, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write(0, 0x3080, 67, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        case 14:
            bg_cell_write(0, 0x3040, 70, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            bg_cell_write(0, 0x3080, 71, (u32)&op_bg0_scrn_data, 0, 0x2C7);
            break;
        }
        break;
    case 1:
        bgw_ptr->free -= 1;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit += 1;
            if (bgw_ptr->l_limit >= 6) {
                opw_ptr->r_no_0 += 1;
            } else {
                bgw_ptr->free = 1;
                oh_opening_demo(bgw_ptr->bg_address, 32, 32, 0x1800, 16, 0x2C0, op_bg0_0015_tbl[bgw_ptr->l_limit]);
            }
        }
        break;
    case 2:
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg0_0016(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_On_W(1);
        bgw_ptr->wxy[0].cal = 0x2000000;
        bgw_ptr->xy[1].cal = 0;
        op_scrn_end = 0;
        bg_cell_write(0, 0x3040, 57, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bg_cell_write(0, 0x3080, 57, (u32)op_bg0_scrn_data, 0, 0x2C0);
        bgw_ptr->frame_deff = 19;
        Frame_Up(0xC0, 0x70, bgw_ptr->frame_deff, bgw_ptr->frame_deff);
        bgw_ptr->free = 10;
        break;
    case 1:
        bgw_ptr->free -= 1;
        if (bgw_ptr->free <= 0) {
            opw_ptr->r_no_0 += 1;
        }
        break;
    case 2:
        bgw_ptr->frame_deff -= 1;
        if (bgw_ptr->frame_deff >= 0) {
            Frame_Down(0xC0, 0x70, 1, 1);
        } else {
            opw_ptr->r_no_0 += 1;
            op_scrn_end = 1;
        }
        break;
    case 3:
        break;
    }
    opening_bgw_commit_pos(0);
}



void op_bg1_move(r_index)
s16 r_index;
{
    opw_ptr = &op_w.bgw[1];
    bgw_ptr = &bg_w.bgw[1];
    switch (r_index) {
    case 55:
    case 56:
        op_bg1_0001(r_index);
        break;
    case 60:
        op_bg1_0002(r_index);
        break;
    case 62:
        op_bg1_0003(r_index);
        break;
    default:
        op_bg1_0000(r_index);
        break;
    }
}



void op_bg1_0000(r_index)
s16 r_index;
{
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->wxy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        Bg_Off_W(2);
        break;
    case 1:
    case 2:
        break;
    }
}



void op_bg1_0001(r_index)
s16 r_index;
{
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0++;
        Bg_On_W(1 << bgw_ptr->fam_no);
        bgw_ptr->wxy[0].cal = 0x02000000;
        bgw_ptr->xy[1].cal = 0;
        switch (r_index) {
        case 0x37:
            bg_cell_write(1, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2CF);
            bg_cell_write(1, 0x3080, 2, (u32)&op_bg0_scrn_data[0], 0, 0x2CF);
            break;
        case 0x38:
            bg_cell_write(1, 0x3040, 3, (u32)&op_bg0_scrn_data, 0, 0x2CE);
            bg_cell_write(1, 0x3080, 4, (u32)&op_bg0_scrn_data, 0, 0x2CE);
            break;
        }
        break;
    case 1:
        break;
    }
}



void op_bg1_0002(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_On_W(1 << bgw_ptr->fam_no);
        switch (r_index) {
        case 60:
            bgw_ptr->wxy[0].cal = 0x1000000;
            bgw_ptr->xy[1].cal = 0;
            bg_cell_write(1, 0x3000, 7, (u32)op_bg0_scrn_data, 0, 0x2D0);
            bg_cell_write(1, 0x3040, 8, (u32)op_bg0_scrn_data, 0, 0x2D0);
            bg_cell_write(1, 0x3080, 9, (u32)op_bg0_scrn_data, 0, 0x2D0);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0xC0000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            bgw_ptr->r_limit = 0x1E0;
            break;
        }
        break;
    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;
        if (bgw_ptr->wxy[0].disp.pos >= bgw_ptr->r_limit) {
            opw_ptr->r_no_0 += 1;
        }
        break;
    case 2:
        break;
    }
}



void op_bg1_0003(s16 r_index) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        Bg_On_W(1 << bgw_ptr->fam_no);
        switch (r_index) {
        case 83:
            bgw_ptr->wxy[0].cal = 0x2200000;
            bgw_ptr->xy[1].cal = 0;
            bg_cell_write(0, 0x3040, 16, (u32)op_bg0_scrn_data, 0, 0x2E7);
            bg_cell_write(0, 0x3080, 17, (u32)op_bg0_scrn_data, 0, 0x2E7);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0x80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = -0x8000;
            bgw_ptr->r_limit = 0x200;
            break;
        case 62:
            bgw_ptr->wxy[0].cal = 0x1E00000;
            bgw_ptr->xy[1].cal = 0;
            bg_cell_write(1, 0x3000, 10, (u32)op_bg0_scrn_data, 0, 0x2E3);
            bg_cell_write(1, 0x3040, 11, (u32)op_bg0_scrn_data, 0, 0x2E3);
            bg_cell_write(1, 0x3080, 12, (u32)op_bg0_scrn_data, 0, 0x2E3);
            op_bg_mvxy[bgw_ptr->fam_no].a[0].sp = 0xFFF80000;
            op_bg_mvxy[bgw_ptr->fam_no].d[0].sp = 0;
            break;
        }
        break;
    case 1:
        op_bg_mvxy[bgw_ptr->fam_no].a[0].sp += op_bg_mvxy[bgw_ptr->fam_no].d[0].sp;
        bgw_ptr->wxy[0].cal += op_bg_mvxy[bgw_ptr->fam_no].a[0].sp;
        if (bgw_ptr->wxy[0].disp.pos <= bgw_ptr->l_limit) {
            opw_ptr->r_no_0 += 1;
        }
        break;
    case 2:
        break;
    }
}

void op_bg2_move(r_index)
s16 r_index;
{
    opw_ptr = &op_w.bgw[2];
    bgw_ptr = &bg_w.bgw[2];
    switch (r_index) {
    case 0:
    case 24:
        op_bg2_0000();
        break;
    case 2:
        op_bg2_0002();
        break;
    case 28:
        op_bg2_0003();
        break;
    default:
        op_bg2_0001();
        break;
    }
}



void op_bg2_0000(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->wxy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        break;
    case 1:
        bgw_ptr->wxy[0].cal -= 0x10000;
        break;
    case 2:
        break;
    }
}



void op_bg2_0001(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->wxy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        break;
    case 1:
        break;
    }
}



void op_bg2_0002(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->wxy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        break;
    case 1:
        bgw_ptr->xy[1].cal += 0x10000;
        break;
    case 2:
        break;
    }
}



void op_bg2_0003(void) {
    switch (opw_ptr->r_no_0) {
    case 0:
        opw_ptr->r_no_0 += 1;
        bgw_ptr->wxy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        break;
    case 1:
        bgw_ptr->wxy[0].cal += 0x10000;
        break;
    case 2:
        break;
    }
}



void opening_title(void) {
    OP_W* r = &op_w;
    switch (r->r_no_1) {
    case 0:
        r->r_no_1++;
        opening_title_00();
        break;
    case 1:
        r->free_work--;
        if (r->free_work <= 0) {
            opening_title_01();
            r->r_no_1++;
        }
        break;
    case 2:
        break;
    }
}



void opening_title_00(void) {
    Zoomf_Init();
    op_w.free_work = 8;
    op_end_flag = 0;
    bg_vbl_trans_flag = 0;
    scr_cg_c_no = simmram_block_alloc_10(0x165, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = 1;
    polygon2d_submit_line(0x01D2C000, 0, 0, 3);
    polygon2d_submit_line(0x01D2C080, bg_w.scroll_cg_adr, 0x164AF, 1);
    if (Game_setting.mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    bg_w.bgw[0].pos_x_work = bg_w.bgw[0].pos_y_work = 0;
    bg_w.bgw[0].rewrite_flag = 0;
    bg_w.bgw[0].fam_no = 0;
    bg_w.bgw[0].zuubun = 0;
    bg_w.bgw[0].wxy[0].cal = 0x2000000;
    bg_w.bgw[0].xy[1].cal = 0;
    bg_w.bgw[0].wxy[0].cal = 0x2000000;
    bg_w.bgw[0].wxy[1].cal = 0;
    bg_w.bgw[0].hos_xy[0].cal = 0x2000000;
    bg_w.bgw[0].hos_xy[1].cal = 0;
    bg_w.bgw[0].position_x = 0x200 - bg_w.pos_offset;
    bg_w.bgw[0].position_y = 0;
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, (s16*)op_scr_record_data_0);
    load_char_gfx(0xE3D0, 1);
}



void opening_title_01(void) {
    s32 pos;
    effect_E1_init(1, 0, 1);
    effect_E1_init(0, 0, 1);
    effect_F5_init(0x10);
    effect_F5_init(0x11);
    effect_F5_init(0x12);
    effect_F5_init(9);
    Disp_Capcom_Rights();
    bg_cell_write(0, 0x3040, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
    bg_cell_write(0, 0x3080, 1, (u32)op_bg0_scrn_data, 0, 0x2C0);
    Bg_Off_W(0xFF);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
    Scrn_Move_Set(0, 0x200 - bg_w.pos_offset, 0);
    Scrn_Move_Set(1, 0x200 - bg_w.pos_offset, 0);
    pos = (s16)-(0x200 - bg_w.pos_offset) & 0x3FF;
    Family_Set_W(1, pos, 0x300);
    op_end_flag = 1;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_w.chase_flag = 0;
}

/* provisional name */
void opening_bgw_commit_pos(bg_no)
s16 bg_no;
{
    s16 pos_x = bg_w.bgw[bg_no].wxy[0].disp.pos & 0x3FF;
    s16 pos_y = bg_w.bgw[bg_no].xy[1].disp.pos & 0x3FF;
    Scrn_Move_Set(bg_no, pos_x - bg_w.pos_offset, pos_y);
}



/* provisional name */
void update_all_disp_pos_ending(void) {
    s32 pos_work_x;
    s32 pos_work_y;
    s16 i;
    for (i = 0; i < 4; i++) {
        bg_w.bgw[i].xy[0].cal = bg_w.bgw[i].wxy[0].cal;
        bg_w.bgw[i].position_y = bg_w.bgw[i].xy[1].disp.pos & 0x3FF;
        bg_w.bgw[i].position_x = bg_w.bgw[i].wxy[0].disp.pos - bg_w.pos_offset;
        bg_w.bgw[i].position_x &= 0x3FF;
        pos_work_x = (s16)-bg_w.bgw[i].position_x & 0x3FF;
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, pos_work_x, pos_work_y);
    }
    bg_w.bgw[5].position_y = bg_w.bgw[5].xy[1].disp.pos & 0x3FF;
    bg_w.bgw[5].position_x = bg_w.bgw[5].wxy[0].disp.pos - bg_w.pos_offset;
    bg_w.bgw[5].position_x &= 0x3FF;
    pos_work_x = (s16)-bg_w.bgw[5].position_x & 0x3FF;
    pos_work_y = bg_w.bgw[5].position_y;
    pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(6, pos_work_x, pos_work_y);
}



/* provisional name */
void ending_effects_cleanup(void) {
    effect_work_kill(2, -1);
    effect_work_kill(0, 0);
    effect_work_kill(1, 1);
    effect_work_kill(3, 3);
    effect_work_kill(3, 0x91);
    effect_work_kill(3, 0x93);
    effect_work_kill(3, 0x94);
    effect_work_kill(3, 0xA5);
    effect_work_kill(3, 0xA6);
    effect_work_kill(3, 0xA9);
    effect_work_kill(3, 0xB4);
}



void Ending_init(void) {
    end_w.r_no_0 = 0;
    end_w.r_no_1 = 0;
    end_w.r_no_2 = 0;
    end_w.type = 0;
    end_w.end_flag = 0;
    Game_timer = 0;
    ending_all_end = 0;
    end_fade_timer = 0;
    end_fade_flag = 0;
    end_no_cut = 0;
    staff_r_no = 0;
    end_staff_flag = 0;
    end_obj_sync = 0;
}



s32 Ending_main(s16 pl_num) {
    Game_timer++;
    normal_ending(pl_num);
    return ending_all_end;
}



#pragma inline(end_main_move)
void normal_ending(pl_num)
s16 pl_num;
{
    switch (end_w.r_no_0) {
    case END_INIT:
        end_w.r_no_0 += 1;
        System_all_clear_Wait();
        load_any_color(0x8D);
        load_any_color(0x94);
        Cover_Timer = 29;
        end_main_jp[pl_num](pl_num);
        card_win_check(1);
        break;
    case END_COVER:
        if (Cover_Timer -= 1) {
            break;
        }
        end_w.r_no_0 += 1;
        load_any_color(end_color_tbl[end_w.type]);
        tilemap_fill_all(0, 32);
        Redisp_Continue_Count(0);
        Redisp_Continue_Count(1);
        Switch_Screen_Init(0, 1);
        end_main_jp[pl_num](pl_num);
        card_msg_disp();
        load_any_color(0x93);
        load_char_gfx(0x9DC8, 1);
        load_char_gfx(0xA0F8, 1);
        break;
    case END_REVIVAL:
        if (Switch_Screen_Revival()) {
            end_w.r_no_0 += 1;
            Ignore_Entry[LOSER] = 0;
            Forbid_Break = -1;
        }
        break;
    case END_PLAY:
        end_main_move(pl_num);
        card_msg_disp();
        if (end_w.end_flag) {
            end_w.r_no_0 += 1;
            end_no_cut = 1;
            effect_work_kill(4, 0x9F);
        } else if (Cut_Cut_Cut_t()) {
            end_w.timer = 0;
            effect_work_kill(4, 0x9F);
            end_main_move(pl_num);
            end_fade_flag = 0;
        }
        Forbid_Break = -1;
        break;
    case END_TO_STAFF:
        if (end_no_cut == 0) {
            fadeout_to_staff_roll();
        } else {
            end_w.r_no_0 += 1;
        }
        Forbid_Break = -1;
        break;
    case END_STAFF_SETUP:
        if (end_fade_complete()) {
            end_w.r_no_0 += 1;
            end_w.r_no_2 += 1;
            if (end_w.type == 4) {
                Zoomf_Init();
                effect_E9_init();
            } else {
                end_w.r_no_0 += 1;
            }
            end_no_cut = 1;
            bg_w.bgw[0].xy[0].disp.pos = 256;
            bg_w.bgw[0].abs_x = 512;
            bg_w.bgw[0].xy[1].disp.pos = 0;
            bg_w.bgw[0].abs_y = 0;
            bg_cell_write(0, 0x3000, 0, end_cg_src_tbl[end_w.type], 0, 0x220);
            bg_cell_write(0, 0x3040, 0, end_cg_src_tbl[end_w.type], 0, 0x220);
            end_scn_pos_set2();
            end_bg_pos_hosei2();
            end_fam_set2();
            Bg_Off_W(2);
            Bg_Off_W(4);
            Bg_Off_W(8);
        }
        Forbid_Break = -1;
        break;
    case END_FRAME:
        end_w.r_no_0 += 1;
        end_waku_write(-1);
        break;
    case END_FADE_IN:
        end_w.r_no_0 += 1;
        Request_Fade(end_fade_tbl[end_w.type], 0);
        end_no_cut = 1;
        Forbid_Break = -1;
        break;
    case END_FADE_WAIT:
        if (end_fade_complete()) {
            end_w.r_no_0 += 1;
            end_no_cut = 0;
        }
        Forbid_Break = -1;
        break;
    case END_STAFF:
        Forbid_Break = 0;
        if (staff_roll_main(end_staff_flag)) {
            end_w.r_no_0 += 1;
        }
        break;
    case END_MUSIC:
        end_w.r_no_0 += 1;
        if (name_wk[WINNER].timer > 0) {
            name_wk[WINNER].timer = 0;
            end_name_cut[WINNER] = 1;
            end_w.timer = 180;
            bgm_fade_out(0xB6);
            break;
        }
        end_w.timer = 60;
        bgm_fade_out(0x222);
        break;
    case END_WAIT:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_0 += 1;
            ending_all_end = 1;
        }
        Forbid_Break = 0;
        break;
    case END_DONE:
        Forbid_Break = 0;
        ending_all_end = 1;
        break;
    }
}



void end_main_move(s16 pl_num) {
    end_main_jp[pl_num](pl_num);
    end_fade_bgm();
}

void end_00000(void)
{
    end_06000(6);
}

/* provisional name */
void end_color_load(void) {
    load_any_color(end_color_tbl[end_w.type]);
}



void fadeout_to_staff_roll(void) {
    Request_Fade(staff_fade_tbl[end_w.type], 0);
    end_no_cut = 1;
    Forbid_Break = -1;
}



void common_end_init00(s16 pl_num) {
    s16 i;
    s32 n;
    u32 blocks;
    const END_BG_GFX* gfx;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    end_cont_coin = Continue_Coin[WINNER];
    end_w.type = pl_num;
    bg_w.bg_index = end_bg_index_tbl[end_w.type];
    bg_w.scno = end_scno_tbl[end_w.type];
    n = ((end_bg_gfx_tbl[bg_w.bg_index].size << 4) + 0xFFF) / 0x1000;
    blocks = n;
    scr_cg_c_no = simmram_block_alloc_10(blocks, 1);
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    gfx = &end_bg_gfx_tbl[bg_w.bg_index];
    polygon2d_submit_line(gfx->prep, 0, 0, 3);
    polygon2d_submit_line(gfx->src, bg_w.scroll_cg_adr, gfx->size, 1);
    switch (end_w.type) {
    case 14:
    case 15:
    case 20:
        gfx = &end_bg_gfx_tbl[3];
        n = ((gfx->size << 4) + 0xFFF) / 0x1000;
        blocks = n;
        ake_cg_c_no = simmram_block_alloc_10(blocks, 1);
        bg_w.ake_cg_adr = simmram_slot_to_offset(ake_cg_c_no);
        polygon2d_submit_line(gfx->prep, 0, 0, 3);
        polygon2d_submit_line(end_bg_gfx_tbl[3].src, bg_w.ake_cg_adr, gfx->size, 1);
        ake_scrl_w[0].handle = simmram_big_page_alloc_40(1);
        ake_scrl_w[0].adrs = (u32)simmram_slot_addr(ake_scrl_w[0].handle);
        break;
    }
    if (Game_setting.mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    base_y_pos = 40;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].rewrite_flag = 0;
    }
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = (u16 *)simmram_slot_addr(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, (u32)bg_w.bgw[i].bg_address);
        scrn_map_set(i, (u32)bg_w.bgw[i].bg_address);
        sprite_list_setup(i, 1, (s16*)end_map_tbl[i]);
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].fam_no = i;
    }
}



void common_end_init01(void) {
    s16 i;
    for (i = 0; i < bg_w.scno; i++) {
        scrn_attr_set(i, 0, 31);
        scrn_reg_w[i].ctrl &= 0xFE7F;
    }
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg_f_x = 9;
    bg_w.old_bg_f_x = 9;
    bg_w.bg_f_y = 9;
    bg_w.old_bg_f_y = 9;
    bg_w.dmm1 = 1;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_sp_work = 0;
    bg_land_flag = 0;
    bg_etc_flag = 0;
    bg_stop2 = 0;
    bg_w.max_x = 6;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_zoom_x_pos = 0xC0;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    bg_ofs_work[0] = bg_ofs_work[1] = bg_ofs_work[2] = 0;
    end_etc_flag = 0;
    end_reset_etc();
    bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x2000000;
    bg_w.bgw[3].xy[1].cal = 0;
    bg_w.bgw[3].position_x = 512 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    end_fam_set(3);
    load_char_gfx(0xDC30, 1);
    effect_E9_init();
    load_any_color(0x8E);
    effect_F9_init(end_w.type);
}



void end_fam_set(s16 i) {
    BGW* l = &bg_w.bgw[i];
    s32 a, b, m;
    a = l->position_x;
    b = l->position_y;
    a = -a;
    m = 0x3FF;
    a &= m;
    b &= m;
    b = (0x300 - b) & m;
    Family_Set_W(i + 1, a, b);
}



void end_fam_set2(void) {
    s16 i;
    s32 pos_work_x;
    s32 pos_work_y;
    for (i = 0; i < bg_w.scno; i++) {
        pos_work_x = bg_w.bgw[i].position_x;
        pos_work_y = bg_w.bgw[i].position_y;
        pos_work_x = -pos_work_x & 0x3FF;
        pos_work_y = (0x300 - (pos_work_y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, pos_work_x, pos_work_y);
    }
}



void end_bg_pos_hosei(s16 bg_no) {
    s16 pos_work = bg_w.bgw[bg_no].abs_x & 0x3FF;
    pos_work -= bg_w.pos_offset;
    bg_w.bgw[bg_no].position_x = pos_work & 0x3FF;
    pos_work = bg_w.bgw[bg_no].abs_y & 0x3FF;
    bg_w.bgw[bg_no].position_y = pos_work;
}



void end_bg_pos_hosei2(void) {
    s16 bg_no;
    u16 pos_work;
    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        pos_work = bg_w.bgw[bg_no].abs_x & 0x3FF;
        pos_work -= bg_w.pos_offset;
        bg_w.bgw[bg_no].position_x = pos_work & 0x3FF;
        pos_work = bg_w.bgw[bg_no].abs_y & 0x3FF;
        bg_w.bgw[bg_no].position_y = pos_work;
    }
}



/* provisional name */
void end_scn_pos_set(u16 bg_no) {
    Scrn_Move_Set(bg_w.bgw[bg_no].fam_no, (bg_w.bgw[bg_no].xy[0].disp.pos & 0x3FF) - bg_w.pos_offset,
                 bg_w.bgw[bg_no].xy[1].disp.pos);
    bg_w.bgw[bg_no].wxy[0].cal = bg_w.bgw[bg_no].xy[0].cal;
    bg_w.bgw[bg_no].wxy[1].cal = bg_w.bgw[bg_no].xy[1].cal;
}



void end_scn_pos_set2(void) {
    s16 bg_no;
    for (bg_no = 0; bg_no < bg_w.scno; bg_no++) {
        Scrn_Move_Set(bg_w.bgw[bg_no].fam_no,
                      (bg_w.bgw[bg_no].xy[0].disp.pos & 0x3FF) - bg_w.pos_offset,
                      bg_w.bgw[bg_no].xy[1].disp.pos);
        bg_w.bgw[bg_no].wxy[0].cal = bg_w.bgw[bg_no].xy[0].cal;
        bg_w.bgw[bg_no].wxy[1].cal = bg_w.bgw[bg_no].xy[1].cal;
    }
}


/* provisional name */
void end_bg_block_attr_set(s16 ix, s32 x, s16 w, s32 y, s16 h) {
    BGW* bgw;
    u16* adrs;
    adrs = (bgw = &bg_w.bgw[ix])->bg_address;
    oh_opening_demo(adrs, x, w, y, h, 0x220, bgw->r_limit);
}


/* provisional name */
void end_bg_block_attr_add(s16 bg, s32 ofs, s16 w, s32 cell, s16 h) {
    BGW* bgw;
    u16* adrs;
    adrs = (bgw = &bg_w.bgw[bg])->bg_address;
    bg_rect_attr_add(adrs, ofs, w, cell, h, 0x220, bgw->r_limit);
}



void end_reset_etc(void) {
    s16 i;
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].abs_x = bg_w.bgw[i].xy[0].disp.pos = 0x200;
        bg_w.bgw[i].abs_y = bg_w.bgw[i].xy[1].disp.pos = 0;
    }
}



void end_X_com01(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_Off_W(1 << bgw_ptr->fam_no);
        break;
    case 1:
        break;
    }
}



void end_fade_bgm(void) {
    if (end_fade_flag != 0) {
        end_fade_timer -= 1;
        if (end_fade_timer < 0) {
            end_fade_flag = 0;
            bgm_fade_out(0x111);
        }
    }
}



s16 end_fade_complete(void) {
    if (Check_Fade_Complete()) {
        Forbid_Break = -1;
        Text_Page_Y = 32;
        commit_name_entry_row_both_players(32);
        return 1;
    }
    return 0;
}



s32 Cut_Cut_Cut_t(void) {
    u16 sw_w;
    if (end_no_cut == 0) {
        if (WINNER) {
            sw_w = p2sw_0 & ~p2sw_1;
        } else {
            sw_w = p1sw_0 & ~p1sw_1;
        }
        if (sw_w & BUTTON_SHOTS) {
            return 1;
        }
    }
    return 0;
}


/* provisional name */
void Cut_Cut_Cut_dummy(void) {}



void end_ake_cell_put(s8 map, s32 ofs, s32 cell, u32 src) {
    register u16* s;
    s32 x;
    u16* dst;
    u32 adrs;
    adrs = ake_scrl_w[map].adrs;
    ofs += adrs;
    x = 0;
    cell = (cell << 10) + src;
    dst = (u16*)ofs;
    s = (u16*)cell;
    x += bg_w.ake_cg_adr >> 7;
    blit_16x16_tile(s, (u16)x, dst, 0x220);
}



/* provisional name */
