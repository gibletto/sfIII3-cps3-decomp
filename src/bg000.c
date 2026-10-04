/*
 * BG000.C  Stage background setup and stages BG000-BG030
 *
 * Common stage background services plus the first stage routines.
 * bg_initialize loads a stage: picks bg_index from stage and area, transfers its
 * scroll graphics and palette and initialises all seven layer works; bg_etc_write does the
 * same for the special screens, and akebono_initialize prepares the finish-screen BG3 pages.
 * reset_all_char_display_with_backup returns every layer to its work position;
 * bg_rect_attr_preset/add and oh_opening_demo patch map cell attributes and scroll_cell_write
 * writes one 16x16 cell. bg_base_move_common and bg_move_common are the standard main-layer
 * and follower-layer moves; capcom_logo_anim runs a timed count, music change
 * and fade at the end of a round. BG000, BG010, BG020 and BG030 run their stages' layers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "bg040.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFF61.h"
#include "EFF78.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "fifo.h"
#include "bg120.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF07.h"
#include "EFF11.h"
#include "eff14.h"
#include "EFF44.h"
#include "appear.h"
#include "aboutspr.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Com_Pl.h"
#include "ta_sub.h"
#include "bg000.h"
#include "fighter.h"
#include "ta_sub2.h"
#include "tate00.h"

#pragma inline(bg0101, bg0102)

/* provisional name */
void Bg_Family_Set_appoint(s32 num_of_bg) {
    s32 x = bg_w.bgw[num_of_bg].position_x;
    s32 y = bg_w.bgw[num_of_bg].position_y;
    Scrn_Move_Set(num_of_bg, x, y);
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



void Bg_Family_Set_2(void) {
    s32 i;
    s32 a, b, x, y;
    for (i = 0; i < bg_w.scno; i++) {
        x = bg_w.bgw[i].position_x;
        y = bg_w.bgw[i].position_y;
        y += 8;
        Scrn_Move_Set(i, x, y);
        a = -x & 0x3FF;
        b = (0x300 - (y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, a, b);
        continue;
    }
}



void Bg_Family_Set_2_appoint(s32 num_of_bg) {
    s32 x;
    s32 y;
    x = bg_w.bgw[num_of_bg].position_x;
    y = bg_w.bgw[num_of_bg].position_y;
    y += 8;
    Scrn_Move_Set(num_of_bg, x, y);
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(num_of_bg + 1, x, y);
}



/* provisional name */
void ake_Family_Set(void) {
    s32 pos_work_x = bg_w.bgw[3].position_x;
    s32 pos_work_y = bg_w.bgw[3].position_y;
    Scrn_Move_Set(3, pos_work_x, pos_work_y);
    pos_work_x = -pos_work_x & 0x3FF;
    pos_work_y = (768 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, pos_work_x, pos_work_y);
}



void ake_Family_Set2(void) {
    s32 x = bg_w.bgw[3].position_x;
    s32 y = bg_w.bgw[3].position_y;
    Scrn_Move_Set(3, x, y);
    x = 512 - bg_w.pos_offset;
    y = 0;
    x = -x & 0x3FF;
    y = (768 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, x, y);
}



void bg_pos_hosei_sub2(s32 bg_no) {
    u16 pos;
    u16 pos2;
    u16 work;
    pos2 = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos = pos2 & 0x3FF;
    pos -= bg_w.pos_offset;
    pos &= 0x3FF;
    pos += quake_x_tbl[bg_w.quake_x_index];
    bg_w.bgw[bg_no].position_x = pos & 0x3FF;
    pos2 -= bg_w.pos_offset;
    pos2 += quake_x_tbl[bg_w.quake_x_index];
    bg_w.bgw[bg_no].abs_x = pos2;
    pos2 = bg_w.bgw[bg_no].xy[1].disp.pos;
    pos = pos2 & 0x3FF;
    work = quake_y_tbl[bg_w.quake_y_index];
    pos += work;
    pos2 += work;
    bg_w.bgw[bg_no].position_y = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_y = pos2;
}



void bg_pos_hosei_sub3(s32 bg_no) {
    s32 pos;
    s32 pos2;
    volatile s16 work;
    volatile s16 work2;
    pos2 = bg_w.bgw[bg_no].wxy[0].disp.pos;
    pos = pos2 & 0x3FF;
    pos -= work = bg_w.pos_offset;
    pos &= 0x3FF;
    pos2 -= work;
    pos += work = quake_x_tbl[bg_w.quake_x_index];
    pos2 += work;
    bg_w.bgw[bg_no].position_x = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_x = pos2;
    pos2 = bg_w.bgw[bg_no].xy[1].disp.pos;
    pos = pos2 & 0x3FF;
    pos += work2 = quake_y_tbl[bg_w.quake_y_index];
    pos2 += work2;
    bg_w.bgw[bg_no].position_y = pos & 0x3FF;
    bg_w.bgw[bg_no].abs_y = pos2;
}

void bg_pos_hosei2(void)
{
    s16 x;
    s16 y;
    s16 quake;
    s16 i;

    for (i = 0; i < bg_w.scno; i++) {
        if (bg_w.chase_flag & 0xF) {
            x = bg_w.bgw[i].chase_xy[0].disp.pos;
        } else {
            x = bg_w.bgw[i].wxy[0].disp.pos;
        }
        bg_w.bgw[i].position_x = ((x & 0x3FF) - bg_w.pos_offset & 0x3FF) + quake_x_tbl[bg_w.quake_x_index] & 0x3FF;
        bg_w.bgw[i].abs_x = x - bg_w.pos_offset + quake_x_tbl[bg_w.quake_x_index];
        if (bg_w.chase_flag & 0xF0) {
            y = bg_w.bgw[i].chase_xy[1].disp.pos;
        } else {
            y = bg_w.bgw[i].xy[1].disp.pos;
        }
        quake = quake_y_tbl[bg_w.quake_y_index];
        bg_w.bgw[i].position_y = (y & 0x3FF) + quake & 0x3FF;
        bg_w.bgw[i].abs_y = y + quake;
        continue;
    }
}



s16 get_center_position(void) {
    if (Bonus_Game_Flag == 0x16) {
        return 0x200;
    }
    return bg_w.bgw[1].wxy[0].disp.pos;
}



s32 get_height_position(void) {
    BGW* blk = &bg_w.bgw[1];
    return blk->xy[1].disp.pos;
}


/* provisional name */
void bg_quake_x_index_set(s16 ix) {
    bg_w.quake_x_index = ix;
}


/* provisional name */
void bg_quake_y_index_set(s16 ix) {
    bg_w.quake_y_index = ix;
}



/* provisional name */
void blit_16x16_tile(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            *d++ = *src++ + code;
            *d++ = *src++ + attr;
        }
        dst += 0x80;
    }
}



/* provisional name */
void blit_8x16_tile(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* d;
    u16* s;
    for (i = 0; i < 16; i++) {
        d = dst;
        s = src;
        for (j = 0; j < 8; j++) {
            *d++ = *s++ + code;
            *d++ = *s++ + attr;
        }
        dst += 0x80;
        src += 0x20;
    }
}



/* provisional name */
void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u32 dst;
    u32 s;
    u16 code;
    dst = (u32)bg_w.bgw[bg].bg_address + ofs;
    s = (cell << 10) + src;
    code = (u32)bg_w.scroll_cg_adr >> 7;
    blit_16x16_tile((u16*)s, code, (u16*)dst, attr);
}



/* provisional name */
void blit_16x16_xflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* s;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            s = &src[i * 32 + 30 - j * 2];
            *d++ = *s++ + code;
            *d = *s + attr;
            *d++ |= 0x1000;
        }
        dst = dst + 0x80;
    }
}



/* provisional name */
void bg_cell_write_xflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_xflip(s, code, dst, attr);
}



/* provisional name */
void blit_16x16_yflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16* pi = &i;
    u16 j;
    s32 off;
    u16* d;
    register u16* s;
    s32 q = (s32)src + -0x440;
    i = 0;
    off = 0x800;
    do {
        d = dst;
        for (j = 0; j < 16; j = j + 1) {
            s = (u16*)(off + q);
            *d++ = *s++ + code;
            *d = *s + attr;
            *d++ |= 0x800;
            q += 4;
        }
        dst += 0x80;
        i++;
        off += -0x80;
    } while (i < 16);
}



/* provisional name */
void bg_cell_write_yflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_yflip(s, code, dst, attr);
}



/* provisional name */
void blit_16x16_xyflip(u16* src, s16 code, u16* dst, s16 attr) {
    u16 i;
    u16 j;
    u16* s;
    u16* d;
    for (i = 0; i < 16; i++) {
        d = dst;
        for (j = 0; j < 16; j++) {
            s = &src[(15 - i) * 32 + (15 - j) * 2];
            *d++ = s[0] + code;
            *d = s[1] + attr;
            *d++ |= 0x1800;
        }
        dst += 0x80;
    }
}



/* provisional name */
void bg_cell_write_xyflip(s16 bg, s32 ofs, s32 cell, u32 src, s16 u5, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)((u32)bg_w.bgw[bg].bg_address + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.scroll_cg_adr >> 7;
    blit_16x16_xyflip(s, code, dst, attr);
}



/* provisional name */
void bg_cell_fill(s16 bg, s16 attr) {
    bg_cell_write(bg, 0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x40, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x80, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0xC0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1000, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1040, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x1080, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
    bg_cell_write(bg, 0x10C0, 0, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
}



/* provisional name */
void bg_scr_write(void) {
    s32 attr = bg_attr_tbl[bg_w.bg_index] + bg_attr_add_tbl[bg_w.bg_index];
    s16 set;
    HUD_CELL** cells;
    HUD_CELL* c;
    s16 i;
    s16 j;
    set = (Country == 8) ? bg_cell_set_tbl[bg_w.stage] : 0;
    cells = bg_rewrite_cell_tbl[set];
    for (i = 0; i < bg_w.scno; i++) {
        bg_cell_fill(i, attr);
        for (j = 0; j < bg_cell_cnt_tbl[bg_w.bg_index][i]; j++) {
            c = &cells[i][j];
            bg_cell_write(i, c->ofs, c->cell, bg_cg_src_tbl[bg_w.bg_index], 0, attr);
            continue;
        }
        continue;
    }
}



/* provisional name */
void ake_cell_write(s8 map, s32 ofs, s32 cell, u32 src) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)(ake_scrl_w[map].adrs + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.ake_cg_adr >> 7;
    blit_16x16_tile(s, code, dst, 0x3C0);
}



/* provisional name */
void ake_cell_write_attr(s8 map, s32 ofs, s32 cell, u32 src, s16 attr) {
    u16* dst;
    u16* s;
    u16 code = 0;
    dst = (u16*)(ake_scrl_w[map].adrs + ofs);
    s = (u16*)((cell << 10) + src);
    code += bg_w.ake_cg_adr >> 7;
    blit_16x16_tile(s, code, dst, attr + 0x3C0);
}



/* provisional name */
void akebono_cell_fill(void) {
    ake_cell_write(1, 0x2000, 1, (u32)ake_scrn_data);
    ake_cell_write(1, 0x2040, 2, (u32)ake_scrn_data);
    ake_cell_write(1, 0x2080, 3, (u32)ake_scrn_data);
    ake_cell_write(1, 0x20C0, 4, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3000, 5, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3040, 6, (u32)ake_scrn_data);
    ake_cell_write(1, 0x3080, 7, (u32)ake_scrn_data);
    ake_cell_write(1, 0x30C0, 8, (u32)ake_scrn_data);
}


/* provisional name */
void akebono_scrn_move(s16 ix) {
    const s16* p = akebono_scrn_pos_tbl[ix];
    s32 x = p[0] - bg_w.pos_offset;
    Scrn_Move_Set(0, x, p[1]);
}

/* provisional name */
void akebono_scr_write(void)
{
    s16 *attr = (s16 *)ake_attr_tbl;
    PANEL *cell;
    s16 i;

    cell = (PANEL *)ake_cell1_data;
    for (i = 0; i < 16; i++) {
        ake_cell_write_attr(1, cell->ofs, cell->cell, (u32)ake_scrn_data, *attr);
        attr++;
        cell++;
    }
    cell = (PANEL *)ake_cell2_data;
    for (i = 0; i < 8; i++) {
        ake_cell_write(2, cell->ofs, cell->cell, (u32)ake_scrn_data);
        cell++;
    }
}



/* provisional name */
void bg_etc_scr_write(s16 n) {
    s16 i;
    s16 j;
    TILEREQ* t;
    s16 attr;

    for (i = 0; i < bg_w.scno; i++) {
        j = 0;
        while (j < etc_bg_cell_cnt_tbl[n][(s16)i]) {
            t = bg_etc_cell_tbl[n][i];
            t += j;
            attr = etc_bg_attr_tbl[n] + t->attr;
            bg_cell_write(i, t->ofs, t->cell, etc_bg_cg_src_tbl[n], 0, attr);
            j++;
        }
        continue;
    }
}



/* provisional name */
void bg_scr_clear_all(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < bg_w.scno; i++) {
        for (j = 0; j < bg_w.scno; j++) {
            u32 dst = (u32)bg_w.bgw[(s16)i].bg_address + (j << 12);
            for (k = 0; k < 4; k++) {
                blit_16x16_tile((u16*)bg_cg_src_tbl[bg_w.bg_index], bg_w.scroll_cg_adr >> 7, (u16*)(dst + k * 0x40), 0);
            }
            continue;
        }
        continue;
    }
}



void bg_work_clear(void) {
    s16 i;
    bg_w.bg_routine = 0;
    bg_w.bg_r_1 = 0;
    bg_w.bg_r_2 = 0;
    bg_w.compel_on[0] = 0;
    win_sp_flag = 0;
    bg_stop = 0;
    bg_stop2 = 0;
    akebono_flag = 0;
    seraph_flag = 0;
    aku_flag = 0;
    sa_pa_flag = 0;
    bg_app = 0;
    bg_app_stop = 0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
    }
}


/* provisional name */
void bg_work_clear_dummy(void) {}



/* provisional name */
void compel_bg_init_position(void) {
    s16 i;
    bg_w.compel_on[0] = 1;
    Zoomf_Init();
    bg_w.bg_f_x = 64;
    bg_w.old_bg_f[0] = 64;
    bg_w.bg_f_y = 64;
    bg_w.old_bg_f[1] = 64;
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].xy[0].disp.pos = bg_w.bgw[i].wxy[0].disp.pos = bg_w.bgw[i].pos_x_work;
        bg_w.bgw[i].xy[1].disp.pos = bg_w.bgw[i].wxy[1].disp.pos = bg_w.bgw[i].pos_y_work;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        if (bg_w.bgw[i].zuubun) {
            suzi_line_clear(i);
        }
    }
}



void reset_all_char_display_with_backup(void) {
    s16 i;
    bg_w.compel_on[0] = 0;
    Zoomf_Init();
    bg_w.bg_f_x = 64;
    bg_w.old_bg_f[0] = 64;
    bg_w.bg_f_y = 64;
    bg_w.old_bg_f[1] = 64;
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].xy[0].disp.pos = bg_w.bgw[i].wxy[0].disp.pos = bg_w.bgw[i].pos_x_work;
        bg_w.bgw[i].xy[1].disp.pos = bg_w.bgw[i].wxy[1].disp.pos = bg_w.bgw[i].pos_y_work;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].xy[0].disp.low = bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].old_pos_x = bg_w.bgw[i].wxy[0].disp.pos;
        if (bg_w.bgw[i].zuubun) {
            suzi_line_clear(i);
        }
    }
}



/* provisional name */
void bg_rect_attr_preset(void) {
    u16* p = (u16*)scrn_map_ptr[0].ptr2;
    oh_opening_demo(p, 0x20, 0x20, 0x1800, 0x10, 0x40, 0x24);
}



void oh_opening_demo(u16* adrs, s32 x, s16 w, s32 y, s16 h, s16 attr, s16 prio) {
    s16 i;
    s16 j;
    u16* p;
    adrs += x;
    adrs += y;
    i = 0;
    while (i < h) {
        p = adrs;
        for (j = 0; j < w; j++) {
            p++;
            *p = (*p & 0xFE00) | attr | prio;
            p++;
        }
        adrs += 0x80;
        i++;
    }
}



/* provisional name */
void bg_rect_attr_add(u16* adrs, s32 x, s16 w, s32 y, s16 h, s16 bits, s16 add) {
    s16 i;
    s16 j;
    u16* p;
    adrs = adrs + x;
    adrs = adrs + y;
    i = 0;
    while (i < h) {
        p = adrs;
        for (j = 0; j < w; j++) {
            p++;
            *p = (*p | bits) + add;
            p++;
        }
        adrs = adrs + 0x80;
        i++;
    }
}



/* provisional name */
s16 capcom_logo_color_step(void) {
    s16 ret = 0;
    switch (bg_w.bgw[1].r_no_2) {
    case 0:
        bg_w.bgw[1].l_limit--;
        if (bg_w.bgw[1].l_limit < 0) {
            bg_w.bgw[1].r_limit++;
            bg_w.bgw[1].l_limit = 1;
            if (bg_w.bgw[1].r_limit >= 90) {
                bg_w.bgw[1].r_no_2++;
                ret = 1;
            }
            bg_vbl_trans_flag = 1;
        } else {
            bg_vbl_trans_flag = 0;
        }
        break;
    case 1:
        ret = 2;
        bg_w.bgw[1].l_limit--;
        if (bg_w.bgw[1].l_limit < 0) {
            bg_w.bgw[1].r_limit++;
            bg_w.bgw[1].l_limit = 1;
            if (bg_w.bgw[1].r_limit >= 95) {
                bg_w.bgw[1].r_no_2++;
                ret = 3;
                bg_vbl_trans_flag = 0;
                Bg_Off_W(2);
            } else {
                bg_vbl_trans_flag = 1;
            }
        } else {
            bg_vbl_trans_flag = 0;
        }
        break;
    case 2:
        ret = 3;
        break;
    }
    return ret;
}



/* provisional name */
s16 capcom_logo_anim(void) {
    s32 ret = 0;
    switch (bg_w.bgw[1].r_no_1) {
    case 0:
        bg_w.bgw[1].r_no_1++;
        bg_w.bgw[1].l_limit = 2;
        bg_w.bgw[1].r_limit = 64;
        bg_vbl_trans_flag = 0;
        if (Demo_Sound != 0 || Keep_BGM_Flag != 0) {
            bgm_request(48);
        }
        break;
    case 1:
        if (capcom_logo_color_step()) {
            bg_w.bgw[1].r_no_1 = 2;
        }
        break;
    case 2:
        if (Request_Fade(35, 0)) {
            bg_w.bgw[1].r_no_1++;
            Bg_On_W(1);
        }
        break;
    case 3:
        capcom_logo_color_step();
        if (Check_Fade_Complete()) {
            bg_w.bgw[1].r_no_1++;
        }
        break;
    case 4:
        switch (capcom_logo_color_step()) {
        case 1:
        case 2:
            break;
        case 3:
            bg_w.bgw[1].r_no_1++;
            ret = 1;
            break;
        }
        break;
    case 5:
        break;
    }
    return ret;
}



/* provisional name */
void scroll_cell_write(i, ofs, cell, tbl)
s16 i;
u32 ofs;
u32 cell;
u32 tbl;
{
    u16* dst;
    u32 base;
    s16 code;
    u16* src;
    base = eff_bg_adrs[i].adrs;
    ofs += base;
    dst = (u16*)ofs;
    code = bg_w.scroll_cg_adr >> 7;
    cell = (cell << 10) + tbl;
    src = (u16*)cell;
    ((void(*)())blit_16x16_tile)(src, code, dst, 0x280);
}



/* provisional name */
void bg_extra_color_trans(void)
{
    load_bg_color(0x2c);
    load_bg_color(0x2d);
}

void bg_base_move_common(void) {
    s32 r;
    bg_base_x_move_check();
    bg_base_y_move_check();
    if (Bonus_Game_Flag) {
        goto end;
    }
    chase_start_check();
    if (bg_w.chase_flag) {
        r = chase_xy_move();
    }
end:
    ;
}



void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}


/* provisional name */
void bg_move_common_dummy(void) {}



/* provisional name */
void bg_initialize(void) {
    const s16* ptr;
    const BG_GFX* gfx;
    s16 i;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    bg_w.bg_index = bg_index_tbl[bg_w.stage][bg_w.area];
    bg_w.scno = bg_scno_tbl[bg_w.bg_index];
    scr_cg_c_no = ((s16)simmram_block_alloc_10(((bg_gfx_tbl[bg_w.bg_index].size << 4) + 0xFFF) / 0x1000, 1));
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    gfx = &bg_gfx_tbl[bg_w.bg_index];
    load_bg_color(((s16)bg_palette_no_tbl[bg_w.bg_index]));
    polygon2d_submit_line(gfx->prep, 0, 0, 3);
    polygon2d_submit_line(gfx->src, bg_w.scroll_cg_adr, gfx->size, 1);
    bg_w.pos_offset = (Game_setting.mode) ? 0xF8 : 0xC0;
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].speed_x = 0;
        bg_w.bgw[i].speed_y = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].speed_x = 0;
    }
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = (u16 *)simmram_slot_addr(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, bg_w.bgw[i].bg_address);
        scrn_map_set(i, bg_w.bgw[i].bg_address);
        sprite_list_setup((s16)i, 1, (s16*)bg_map_tbl[bg_w.bg_index][i]);
    }
    bg_scr_write();
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_w.bg_f_x = 64;
    bg_w.old_bg_f[0] = 64;
    bg_w.bg_f_y = 64;
    bg_w.old_bg_f[1] = 64;
    bg_w.dmm1[0] = 1;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_sp_work = 0;
    bg_land_flag = 0;
    bg_etc_flag = 0;
    bg_stop2 = 0;
    bg_w.max_x = 8;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_zoom_x_pos = 0xC0;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    bg_w.frame_deff = 64;
    bg_ofs_work[0] = bg_ofs_work[1] = bg_ofs_work[2] = 0;
    for (i = 0; i < bg_w.scno; i++) {
        scroll_layer_mask_enable(1 << i);
        scroll_layer_mask_disable(16 << i);
        scrn_attr_set(i, 0, bg_prio_tbl[(u8)bg_w.bg_index][i]);
        scrn_reg_w[i].ctrl &= 0xFE7F;
        bg_w.bgw[i].speed_x = bg_speed_tbl[bg_w.bg_index][i][0];
        bg_w.bgw[i].speed_y = bg_speed_tbl[bg_w.bg_index][i][1];
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].xy[1].disp.pos = bg_w.bgw[i].wxy[1].disp.pos = bg_w.bgw[i].pos_y_work = 0;
        ptr = bg_limit_tbl[bg_w.bg_index][i];
        bg_w.bgw[i].l_limit = *ptr++;
        bg_w.bgw[i].r_limit = *ptr++;
        bg_w.bgw[i].l_limit2 = *ptr++;
        bg_w.bgw[i].r_limit2 = *ptr++;
        bg_w.bgw[i].y_limit = *ptr++;
        bg_w.bgw[i].y_limit2 = *ptr;
        if (!Game_setting.mode) {
            bg_w.bgw[i].r_limit2 = bg_w.bgw[i].r_limit;
            bg_w.bgw[i].l_limit2 = bg_w.bgw[i].l_limit;
        }
        bg_w.bgw[i].frame_deff = 0;
        bg_w.bgw[i].max_x_limit = bg_w.bgw[i].speed_x * bg_w.max_x;
    }
    base_y_pos = (bg_w.stage != 4) ? 40 : 48;
    bg_pos_hosei2();
    Bg_Family_Set();
}

/* provisional name */
void bg_color_trans(void) {
    load_bg_color(bg_color2_tbl[bg_w.bg_index]);
}



void akebono_initialize(void) {
    ake_cg_c_no = ((s16)simmram_block_alloc_10(21, 1));
    bg_w.ake_cg_adr = simmram_slot_to_offset(ake_cg_c_no);
    load_any_color(140);
    load_any_color(143);
    polygon2d_submit_line(0x0209F800, 0, 0, 3);
    polygon2d_submit_line(0x0209F880, bg_w.ake_cg_adr, 0x14FF, 1);
    ake_scrl_w[1].handle = simmram_big_page_alloc_40(1);
    ake_scrl_w[1].adrs = simmram_slot_addr(ake_scrl_w[1].handle);
    ake_scrl_w[2].handle = simmram_big_page_alloc_40(1);
    ake_scrl_w[2].adrs = simmram_slot_addr(ake_scrl_w[2].handle);
    scrn_map_set_now(3, (u32)bg_w.bgw[3].bg_address);
    scrn_map_set(3, (u32)bg_w.bgw[3].bg_address);
    bg_w.bgw[3].wxy[0].cal = bg_w.bgw[3].xy[0].cal = 0x100000;
    bg_w.bgw[3].xy[1].cal = bg_w.bgw[3].wxy[1].cal = 0;
    bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    ake_Family_Set();
    ake_scrl_w[0].pos[0] = 512 - bg_w.pos_offset;
    ake_scrl_w[0].pos[1] = 0;
    ake_scrl_w[0].xy[0].cal = 0x2000000;
    ake_scrl_w[0].xy[1].cal = 0;
    sprite_list_setup(3, 1, (s16*)((u32)ake_scr_record_data));
    bg_w.bgw[3].r_no_2 = bg_w.bgw[3].r_no_1 = 0;
    bg_w.bgw[3].fam_no = 3;
    akebono_scr_write();
    scrn_reg_w[3].ctrl &= 0xFE7F;
    scrn_attr_set(3, 0, 24);
    scroll_layer_mask_disable(8);
}



void bg_etc_write(s16 type) {
    const BG_GFX* gfx;
    s32 i;
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
    scr_cg_c_no = ((s16)simmram_block_alloc_10(((etc_bg_gfx_tbl[type].size << 4) + 0xFFF) / 0x1000, 1));
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    bg_w.scno = etc_bg_scno_tbl[type];
    switch (type) {
    case 4:
        load_any_color(etc_bg_color_tbl[type]);
        load_any_color(40);
        break;
    case 5:
    case 6:
        break;
    default:
        load_any_color(etc_bg_color_tbl[type]);
        break;
    }
    gfx = &etc_bg_gfx_tbl[type];
    polygon2d_submit_line(gfx->prep, 0, 0, 3);
    polygon2d_submit_line(gfx->src, bg_w.scroll_cg_adr, gfx->size, (u8)gfx->mode);
    if (Game_setting.mode) {
        bg_w.pos_offset = 0xF8;
    } else {
        bg_w.pos_offset = 0xC0;
    }
    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].pos_x_work = 0;
        bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].speed_y = bg_w.bgw[i].speed_x = 0;
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
    }
    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[i].bg_address = ((u16 *(*)(s16 handle))simmram_slot_addr)(bg_w.bgw[i].bg_adrs_c_no);
        scrn_map_set_now(i, bg_w.bgw[i].bg_address);
        scrn_map_set(i, bg_w.bgw[i].bg_address);
        sprite_list_setup((s16)i, 1, (s16*)bg_map_tbl2[type][i]);
    }
    bg_etc_scr_write(type);
    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.dmm0[0] = 0;
    bg_land_flag = 0;
    bg_etc_flag = 0;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_w.bg_f_x = 64;
    bg_w.old_bg_f[0] = 64;
    bg_w.bg_f_y = 64;
    bg_w.old_bg_f[1] = 64;
    bg_w.dmm1[0] = 1;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_sp_work = 0;
    bg_stop2 = 0;
    bg_w.max_x = 8;
    bg_zoom_x_pos = 0xC0;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;
    for (i = 0; i < bg_w.scno; i++) {
        scroll_layer_mask_disable(16 << i);
        scroll_layer_mask_enable(1 << i);
        scrn_attr_set(i, 0, 24);
        scrn_reg_w[i].ctrl &= 0xFE7F;
        bg_w.bgw[i].hos_xy[0].cal = bg_w.bgw[i].wxy[0].cal = bg_w.bgw[i].xy[0].cal = etc_bg_pos_tbl[type][i][0];
        bg_w.bgw[i].hos_xy[1].cal = bg_w.bgw[i].wxy[1].cal = bg_w.bgw[i].xy[1].cal = etc_bg_pos_tbl[type][i][1];
        bg_w.bgw[i].pos_y_work = bg_w.bgw[i].xy[1].disp.pos;
        bg_w.bgw[i].old_pos_x = bg_w.bgw[i].pos_x_work = bg_w.bgw[i].xy[0].disp.pos;
        bg_w.bgw[i].speed_x = etc_bg_speed_tbl[type][i][0];
        bg_w.bgw[i].speed_y = etc_bg_speed_tbl[type][i][1];
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].zuubun = etc_bg_zuubun_tbl[type][i];
        bg_w.bgw[i].frame_deff = 64;
        bg_w.bgw[i].max_x_limit = bg_w.bgw[i].speed_x * bg_w.max_x;
    }
    if (type == 1 && Game_setting.mode) {
        bg_w.bgw[0].xy[0].cal = 0x2000000;
        bg_w.bgw[0].wxy[0].cal = 0x2000000;
        bg_w.bgw[0].pos_x_work = 0x200;
    }
    base_y_pos = 40;
}



void BG000(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        JMP_TBL3 bg0402_jmp;
        bg0402_jmp = bg0402_jmp_tbl;
        bg0402_jmp.fn[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        JMP_TBL3 bg0401_jmp;
        bg0401_jmp = bg0401_jmp_tbl;
        bg0401_jmp.fn[bgw_ptr->r_no_0]();
    }
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0001_ctrl(void) {
    void (*bg0401_jmp[3])() = { bg0001_init00, bg0000_demo, bg_base_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}



void bg0001_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDC40, 1);
    effect_06_init();
    effect_44_init(7);
    effect_60_init(2);
    if (bg_w.area != 0) {
        bgw_ptr->r_no_0 = 2;
        return;
    } else if (gill_appear_check()) {
        bgw_ptr->r_no_0 = 2;
        return;
    }
    if (plw[0].player_number == PL_GILL) {
        bgw_ptr->u_line = 0;
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xE0;
        bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        return;
    }
    bgw_ptr->u_line = 1;
    bgw_ptr->xy[0].cal -= bgw_ptr->speed_x * 0xC0;
    bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}



void bg0000(void) {
    void (*bg0000_jmp[3])() = { bg0000_init00, bg0000_demo, bg_move_common };
    bg0000_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg_main_layer_dispatch(void) {
    void (*bg_jmp[2])() = { bg1101_init00, bg1101_move };
    bg_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg_back_layer_dispatch(void) {
    void (*bg_jmp[2])() = { bg1100_init00, bg1100_move };
    bg_jmp[bgw_ptr->r_no_0]();
}



void bg0000_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x1D0;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    if (gill_appear_check()) {
        bgw_ptr->r_no_0 = 2;
        bg_app = 0;
    } else {
        bg_app = 1;
        if (plw[0].player_number == PL_GILL) {
            bgw_ptr->u_line = 0;
            bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xE0;
            bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        } else {
            bgw_ptr->u_line = 1;
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x * 0xC0;
            bgw_ptr->old_pos_x = bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        }
    }
}



void bg0000_demo(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x1E;
        break;
    case 1:
        bgw_ptr->free--;
        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1 += 1;
        }
        break;
    case 2:
        if (bgw_ptr->u_line) {
            bgw_ptr->wxy[0].cal += bgw_ptr->speed_x;
            if (bgw_ptr->wxy[0].disp.pos > 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                break;
            }
        } else {
            bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x;
            if (bgw_ptr->wxy[0].disp.pos < 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                break;
            }
        }
        break;
    case 3:
        bg_app = 0;
        bgw_ptr->r_no_0 = 2;
        break;
    }
}



void BG010(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0102();
    bgw_ptr = &bg_w.bgw[0];
    bg0101();
    bgw_ptr = &bg_w.bgw[2];
    bg0103();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0101(void) {
    void (*bg1601_jmp[2])() = { bg0101_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



void bg0101_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xD8D0, 1);
    effect_07_init();
    effect_05_init();
    effect_06_init();
    effect_11_init();
}



void bg0102(void) {
    void (*bg0602_jmp[2])() = { bg0102_init00, bg_base_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg0102_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0103(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xB000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;
    case 1:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}



void bg0201_BG020(void) {
    void (*bg0201_jmp[2])() = { bg0201_init00, bg_move_common };
    bg0201_jmp[bgw_ptr->r_no_0]();
}



void bg0202_BG020(void) {
    void (*bg0202_jmp[2])() = { bg0202_init00, bg_base_move_common };
    bg0202_jmp[bgw_ptr->r_no_0]();
}



void bg020_sync_common_BG020(void) {
    void (*bg020_sync_jmp[2])() = { bg020_sync_init, bg020_sync_move };
    bg020_sync_jmp[bgw_ptr->r_no_0]();
}



void bg020_sync_common_bg020(void) {
    void (*bg020_sync_jmp[2])() = { bg020_sync_init, bg020_sync_move };
    bg020_sync_jmp[bgw_ptr->r_no_0]();
}



void BG020(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0202_BG020();
    bgw_ptr = &bg_w.bgw[0];
    bg0201_BG020();
    bgw_ptr = &bg_w.bgw[2];
    bg0201_BG020();
    bgw_ptr = &bg_w.bgw[5];
    bg020_sync_common_BG020();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_2_appoint(0);
    Bg_Family_Set_appoint(2);
}



void bg0201(void) {
    void (*bg0201_jmp[2])() = { bg0201_init00, bg_move_common };
    bg0201_jmp[bgw_ptr->r_no_0]();
}



void bg0201_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg0202(void) {
    void (*bg0202_jmp[2])() = { bg0202_init00, bg_base_move_common };
    bg0202_jmp[bgw_ptr->r_no_0]();
}



void bg0202_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0xDF20, 1);
    effect_06_init();
    effect_78_entry();
}



void bg020_sync_common(void) {
    void (*bg0602_jmp[2])() = { bg020_sync_init, bg020_sync_move };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg020_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0xE000;
    sync_fam_set3(5);
}

void bg020_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(5);
}



