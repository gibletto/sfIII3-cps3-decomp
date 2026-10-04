/*
 * CMB_WIN.C  Combo window drawing
 *
 * Tilemap routines for the combo/bonus message windows at the side of the screen.
 * combo_message_set places a message frame for a player, combo_hitnum_set writes the two-digit
 * hit count, combo_pts_set writes a score in large digits followed by 00 and PTS.
 * combo_window_slide copies a prepared message into the visible window a column at a time,
 * combo_window_erase blanks one message and combo_window_all_clear clears both players'
 * areas for the current screen mode. sc_vram_to_ram saves the scroll character VRAM rows
 * into the RAM character buffer. Called from CMB_CONT.
 * end_waku_write draws or clears the ending letterbox.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "cmb_win.h"
#include "cps3.h"



void combo_message_set(s8 pl, s8 kind) {
    const CMB_FRAME* fr = &combo_mtbl[kind];
    s16 y = pl * 2 + 30;
    sc_chr_sheet_trans(fr->chr, pl * 32 + 0x140, fr->w, fr->h);
    scfont_sqput(combo_mpos_tbl[kind][pl], y, fr->w, fr->h, 16, pl * 32 + 0x140);
    tilemap_put_cell(combo_mclr_pos_tbl[kind][pl], y, 16, 32);
    tilemap_put_cell(combo_mclr_pos_tbl[kind][pl], y + 1, 16, 32);
}



/* provisional name */
void combo_hitnum_set(s8 pl, s8 kind, u16 hits) {
    s16 x = combo_hitpos_tbl[kind][pl];
    s16 y = pl * 2 + 30;
    s32 tens = hits / 10;
    u16 ones = hits - tens * 10;
    if (tens != 0) {
        tilemap_put_cell(x, y, 16, tens + 96);
        tilemap_put_cell(x, y + 1, 16, tens + 112);
    } else {
        tilemap_put_cell(x, y, 16, 32);
        tilemap_put_cell(x, y + 1, 16, 32);
    }
    tilemap_put_cell(x + 1, y, 16, ones + 96);
    tilemap_put_cell(x + 1, y + 1, 16, ones + 112);
    tilemap_put_cell(x + 2, y, 16, 32);
    tilemap_put_cell(x + 2, y + 1, 16, 32);
}



s16 combo_pts_set(s8 PL, u32 pts) {
    s16 digit[4];
    s16 i;
    s32 first;
    s32 xx;
    u16 x;
    s16 y;
    s16 x2;
    first = -1;
    xx = 100000;
    for (i = 3; i >= 0; i--) {
        digit[i] = pts / xx;
        if (first < 0) {
            if (digit[i] != 0) {
                first = i;
            }
        }
        pts -= digit[i] * xx;
        xx /= 10;
    }
    x = (15 - first) * PL;
    y = PL * 2 + 34;
    for (i = first; i >= 0; i--) {
        score8x16_put(x++, y, 16, digit[i]);
    }
    score8x16_put(x, y, 16, 0);
    score8x16_put(x + 1, y, 16, 0);
    tilemap_put_cell(x + 2, y, 16, 32);
    tilemap_put_cell(x + 2, y + 1, 16, 0xD6);
    tilemap_put_cell(x + 3, y, 16, 32);
    tilemap_put_cell(x + 3, y + 1, 16, 0xD7);
    x2 = (PL == 0) ? x + 4 : 14 - first;
    tilemap_put_cell(x2, y, 16, 32);
    tilemap_put_cell(x2, y + 1, 16, 32);
    return first + 6;
}



/* provisional name */
void combo_window_slide(s8 pl, s16 x, s16 y, s16 n) {
    u32* src = (u32*)(SS_RAM + ((y * 4 + pl * 2 + 30) << 8) + ((pl * 19) << 2));
    u32* dst = (u32*)((SS_RAM + 0x700) + x * 4 + ((y * 3) << 8));
    s32 d;
    u16 i;
    d = (pl == 0) ? 1 : -1;
    for (i = 0; i < n + 1; i++) {
        dst[0] = src[0];
        dst[0x40] = src[0x40];
        dst += d;
        src += d;
    }
}



/* provisional name */
void combo_window_erase(s8 col, s8 kind, s16 row) {
    u32* cell = (u32*)((SS_RAM + 0x700) + combo_erase_pos_tbl[Game_setting.mode][kind][col] * 4 + row * 0x300);
    u16 i;
    for (i = 0; i < combo_erase_len_tbl[kind]; i++) {
        cell[0] = 0x200000;
        cell[0x40] = 0x200000;
        cell++;
    }
}



/* provisional name */
void combo_window_all_clear(void) {
    if (Game_setting.mode == 0) {
        tilemap_clear_rect(0, 7, 20, 9);
        tilemap_clear_rect(0, 10, 18, 11);
        tilemap_clear_rect(27, 7, 47, 9);
        tilemap_clear_rect(29, 10, 47, 11);
        return;
    }
    tilemap_clear_rect(0, 7, 24, 11);
    tilemap_clear_rect(37, 7, 61, 11);
}



/* provisional name */
void sc_vram_to_ram(void) {
    sc_trans_dst = (u16*)(SS_RAM + 0x8000);
    sc_bak_ptr = sc_chr_ram;
    sc_chr_save(0x200);
}


/* provisional name */
void end_waku_write(s8 mode) {
    switch (mode) {
    case 0:
        ToneDown(16);
        ToneDown(17);
        sc_trans_src = end_waku_chr;
        sc_trans_dst = (u16*)(SS_RAM + 0x8800);
        sc_chr_trans(1);
        sc_fill_rect(0, 0, 48, 4, 0xAF, 62);
        sc_fill_rect(0, 4, 48, 18, 31, 62);
        sc_fill_rect(0, 22, 48, 6, 0xAF, 62);
        break;
    case 1:
        ToneDown(16);
        ToneDown(17);
        sc_trans_src = end_waku_chr;
        sc_trans_dst = (u16*)(SS_RAM + 0x8800);
        sc_chr_trans(1);
        sc_fill_rect(0, 0, 48, 4, 0xAF, 62);
        sc_fill_rect(0, 4, 48, 18, 31, 62);
        break;
    case 2:
        sc_fill_rect(0, 22, 48, 6, 0xAF, 62);
        break;
    case -1:
        ToneDown(18);
        ToneDown(19);
        sc_trans_src = sc_blank_chr;
        sc_trans_dst = (u16*)(SS_RAM + 0x8800);
        sc_chr_trans(1);
        tilemap_clear_rect(0, 0, 48, 27);
        break;
    }
}
