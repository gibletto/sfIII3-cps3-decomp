/*
 * sc_face.c  Name plates, rank marks and player faces on the text layer
 *
 * Text-layer character transfers for the HUD and result screens. naming_set puts one letter of
 * a player's entered name into the fix-layer character RAM, rank_mark_set transfers a ranking
 * mark (or saves it to the RAM buffer while the screen is escaped), and winner_name_put draws
 * the winner's name plate from nwdata_tbl (with a shared plate outside Japan for characters 14
 * and 15). player_face and player_face_char_set load each player's face icon and its colour by
 * character and colour number; in versus play, player_grade_char_set and player_face also show
 * the champion's grade icon once he has a win record. player_face_default_set shows the
 * default face.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "Grade.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "sc_face.h"
#include "cps3.h"
#include "fighter.h"



/* Draws one name-entry character for a player. */
void sa_stock_chr_trans(s8 pl, s16 n) {
    sc_trans_dst = (u16*)((SS_RAM + 0xB440) + pl * 0xC0);
    sc_trans_src = (u8*)(sc_chr_data + (((n * 2 + 0x910) << 5) >> 1));
    sc_chr_trans(2);
}



/* provisional name */
void sa_max_level_trans(row, col)
s8 row;
s16 col;
{
    sc_trans_dst = (u16*)((SS_RAM + 0xB400) + row * 192);
    sc_trans_src = (u8*)&sc_chr_data[((row * 16 + col + 2352) * 32) >> 1];
    sc_chr_trans(1);
}



void sa_stock_trans(s16 n, s16 ix, s8 pl) {
    if (pl == 0) {
        sa_stock_chr_trans(0, n);
        tilemap_put_cell(3, 25, sa_color_data_tbl[ix], 0xD1);
        tilemap_put_cell(3, 26, sa_color_data_tbl[ix], 0xD2);
    } else {
        sa_stock_chr_trans(1, n);
        tilemap_put_cell(44, 25, sa_color_data_tbl[ix], 0xD4);
        tilemap_put_cell(44, 26, sa_color_data_tbl[ix], 0xD5);
    }
}



void sa_fullstock_trans(s8 side, s16 ix) {
    if (side == 0) {
        tilemap_put_cell(1, 26, sa_color_data_tbl[ix], 0xD0);
    } else {
        tilemap_put_cell(46, 26, sa_color_data_tbl[ix], 0xD3);
    }
}



/* provisional name */
void win_mark_put(s16 pl, u16 n, s16 attr) {
    const s16* e;
    sc_trans_src = (u8*)&sc_chr_data[n * 32] + 0xBDC0;
    sc_trans_dst = (u16*)((SS_RAM + 0x8400) + pl * 128);
    sc_chr_trans(2);
    e = &vmark_tbl[pl * 6];
    tilemap_put_cell(e[0] + DE_X[3], e[1], attr, e[2]);
    tilemap_put_cell(e[3] + DE_X[3], e[4], attr, e[5]);
}



/* provisional name */
void win_mark_ram_clear(void) {
    u16 i;
    u8* dst = &sc_chr_ram[0x200];
    volatile s32 blank = 0xBDC0;
    for (i = 0; i < 8; i++) {
        sc_trans_src = (u8*)((u32)sc_chr_data + blank);
        sc_bak_ptr = dst;
        sc_chr_to_ram(64);
        dst += 64;
    }
}



/* provisional name */
void win_mark_find_put(s16 x, s16 y, s16 pl) {
    s16 round = win_mark_find(pl);
    const s16* mark;
    if (round == -1) {
        cpu_hang_forever();
    }
    mark = &vmark_tbl[pl * 24 + round * 6];
    tilemap_put_cell(x, y, 14, mark[2]);
    tilemap_put_cell(x + 1, y, 14, mark[5]);
}



/* provisional name */
s32 win_mark_find(s16 pl) {
    s16 i;
    for (i = 0; i < Battle_Round[Play_Type] + 1; i++) {
        if (win_type[pl][i] == 3) {
            return i;
        }
    }
    return -1;
}



void naming_set(s8 pl, s16 place, u16 chr) {
    sc_trans_src = (u8*)&sc_chr_data[chr * 16] + 0x7000;
    if (pl == 0) {
        sc_trans_dst = (u16*)(place * 64 + (SS_RAM + 0x9E80));
    } else {
        sc_trans_dst = (u16*)(place * 64 + (SS_RAM + 0xCA80));
    }
    sc_chr_trans(1);
}



/* provisional name */
void rank_mark_set(s8 row, s8 n) {
    sc_trans_src = (u8*)&sc_chr_data[n * 32] + 0x7600;
    if (row == 0) {
        sc_trans_dst = (u16*)(SS_RAM + 0x9A80);
    } else {
        sc_trans_dst = (u16*)(SS_RAM + 0x9B00);
    }
    if (Escape_SS == 0) {
        sc_chr_trans(2);
    } else {
        sc_bak_ptr = &sc_chr_ram[row * 64] + 0xD40;
        sc_chr_to_ram(64);
    }
}



/* provisional name */
void winner_name_put(s8 ch) {
    const NAME_PLATE* p = &nwdata_tbl[ch];
    if (Country == 1) {
        sc_chr_block_trans(p->cell, 0x180, p->w, p->h);
    } else {
        if (ch == 14 || ch == 15) {
            p = &nwdata_tbl[21];
        }
        sc_chr_block_trans(p->cell, 0x180, p->w, p->h);
    }
    sc_chr_block_trans(0x1588, 0x1C0, 13, 4);
    scfont_sqput(DE_X[3] + p->x, p->y, p->w, p->h, 40, 0x180);
    scfont_sqput(p->x2 + DE_X[3], p->y2, 13, 4, 40, 0x1C0);
}



/* provisional name */
void player_face_char_set(s8 pl) {
    if (My_char[1] == PL_GILL && pl == 1) {
        sc_chr_slot_trans(1, 0x350, 0);
        sc_chr_slot_trans(3, 0x358, 0);
        return;
    }
    sc_chr_slot_trans(pl, My_char[pl] * 16 + 0x200, 0);
    sc_chr_slot_trans(pl + 2, My_char[pl] * 16 + 0x208, 0);
}

void player_grade_char_set(pl) s8 pl; {
    u16 grade;
    if (Play_Type == 0) {
        return;
    }
    grade = grade_get_my_grade(pl);
    sc_chr_slot_trans(4, (grade - grade / 3 * 3) * 5 + (grade / 3) * 16 + 0x950, 0);
}



/* provisional name */
void player_face_default_set(s8 pl) {
    polygon2d_submit_quad(0x03364820 + Player_Color[pl] * 32, 0x3FC00 + pl * 0x200, 32, 0, 0, 0);
    sc_chr_slot_trans(pl, 0x33B, 1);
    sc_chr_slot_trans(pl + 2, 0x343, 1);
}



void player_face(void) {
    s8 pl;
    player_face_char_set(0);
    player_face_char_set(1);
    polygon2d_submit_quad(0x03363B00 + My_char[0] * 0xE0 + Player_Color[0] * 32, 0x3FC00, 32, 0, 0, 0);
    polygon2d_submit_quad(0x03363B00 + My_char[1] * 0xE0 + Player_Color[1] * 32, 0x3FE00, 32, 0, 0, 0);
    sc_ram_to_vram(0, 0, 0);
    sc_ram_to_vram(1, 0, 0);
    if (Play_Type == 0) {
        return;
    }
    pl = Champion;
    if (Win_Record[pl] == 0) {
        return;
    }
    player_grade_char_set(pl);
    if (Champion) {
        if (grade_get_my_grade(1) < 24) {
            sc_ram_to_vram(14, 0, 0);
        } else {
            sc_ram_to_vram(15, 0, 0);
        }
    } else {
        if (grade_get_my_grade(0) < 24) {
            sc_ram_to_vram(12, 0, 0);
        } else {
            sc_ram_to_vram(13, 0, 0);
        }
    }
}
