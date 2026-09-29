/*
 * sc_trans.c  Text (fix) layer character transfer and put routines
 *
 * Low-level routines for the fix layer used by the HUD, menus and result screens.
 * Character data from sc_chr_data is copied into the fix-layer character RAM a row at a time
 * (sc_chr_trans, sc_chr_block_trans, sc_chr_sheet_trans, sc_chr_list_trans, sc_chr_slot_trans),
 * or into a RAM buffer and later to video RAM (sc_chr_to_ram, sc_ram_to_vram); sc_chr_save /
 * sc_chr_load / sc_chr_backup preserve the name-entry letters while the whole font is reloaded
 * (Ranking_00_6th), and ToneDown loads the screen tone-down characters.
 * The put routines write cells to the text tilemap: square and line blocks (scfont_sqput,
 * scfont_lnput and reversed forms), fills and rectangles, single cells and attributes, cell
 * lists and pictures. HUD transfers built on them draw the player names, timer and count
 * digits, super art numbers, stock and max marks, and the round win marks.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "cps3.h"
#include "fighter.h"



/* Copies rows of font characters to the screen; returns the number of bytes copied. */
/* provisional name */
s32 sc_chr_trans(rows)
u16 rows;
{
    u16* dst = sc_trans_dst;
    volatile u8* src = sc_trans_src;
    s32 n = rows * 32;
    s32 i;
    for (i = 0; i < n; i++) {
        *dst = *src;
        dst++;
        src++;
    }
    return n;
}



/* provisional name */
void sc_chr_save(u16 rows) {
    s32 i;
    for (i = 0; i < rows * 32; i++) {
        *sc_bak_ptr = *sc_trans_dst;
        sc_bak_ptr++;
        sc_trans_dst++;
    }
}



/* provisional name */
void sc_chr_load(u16 rows) {
    s32 i;
    for (i = 0; i < rows * 32; i++) {
        *sc_trans_dst = *sc_bak_ptr;
        sc_bak_ptr++;
        sc_trans_dst++;
    }
}



/* provisional name */
void sc_chr_block_trans(u16 chr, u16 pos, u16 w, u16 h) {
    u16 i;
    u16 j;
    u16 k;
    u16* dst;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    dst = (u16*)((SS_RAM + 0x8000) + pos * 64);
    sc_trans_dst = dst;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            for (k = 0; k < 32; k++) {
                *sc_trans_dst = *sc_trans_src;
                sc_trans_src++;
                sc_trans_dst++;
            }
            continue;
        }
        dst += 0x200;
        sc_trans_dst = dst;
        continue;
    }
}



/* provisional name */
void sc_chr_sheet_trans(u16 chr, u16 pos, u16 w, u16 h) {
    u16 i;
    u16 j;
    u16 k;
    u8* src;
    u16* dst;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    dst = (u16*)((SS_RAM + 0x8000) + pos * 64);
    sc_trans_dst = dst;
    src = sc_trans_src;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            for (k = 0; k < 32; k++) {
                *sc_trans_dst = *sc_trans_src;
                sc_trans_dst++;
                sc_trans_src++;
            }
        }
        src += 0x200;
        sc_trans_src = src;
        dst += 0x200;
        sc_trans_dst = dst;
    }
}

void scfont_sqput(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code)
{
    u16 row;
    u16 col;

    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tilemap_put_cell(x + col, y + row, attr, code + row * 16 + col);
        }
    }
}



/* provisional name */
void scfont_sqput_rev(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 i;
    u16 j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            tilemap_put_cell(x + w - 1 - i, y + j, attr + 0x80, code + j * 16 + i);
        }
    }
}

/* provisional name */
void scfont_lnput(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code)
{
    u16 row;
    u16 col;
    s32 n;

    n = 0;
    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tilemap_put_cell(x + col, (s16)(y + row), attr, code + n);
            n++;
        }
    }
}

/* provisional name */
void scfont_lnput_rev(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code)
{
    u16 row;
    u16 col;
    s32 cx;
    u16 n;

    n = 0;
    attr += 128;
    for (row = 0; row < h; row++) {
        cx = (s16)(w + x);
        for (col = 0; col < w; col++) {
            cx--;
            tilemap_put_cell(cx, y + row, attr, code + n);
            n++;
        }
    }
}



/* provisional name */
s32 scfont_fill(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 i;
    u16 j;
    s32 ret = 54;
    for (j = 0; j < h; j++) {
        ret = (s16)w;
        for (i = 0; i < w; i++) {
            ret = tilemap_put_cell(x + i, y + j, attr, code);
        }
    }
    return ret;
}



void sq_paint_chenge(s16 x, s16 y, u16 w, u16 h, s16 attr) {
    u16 i;
    u16 j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            sc_attr_put(x + i, y + j, attr);
        }
    }
}



/* provisional name */
void sc_chr_clear(pos, n)
u16 pos;
u16 n;
{
    u16 i;
    u16 k;
    sc_trans_src = sc_blank_chr;
    sc_trans_dst = (u16*)((SS_RAM + 0x8000) + pos * 64);
    for (i = 0; i < n; i++) {
        for (k = 0; k < 16; k++) {
            *sc_trans_dst = *sc_trans_src;
            sc_trans_dst++;
            sc_trans_src++;
            *sc_trans_dst = *sc_trans_src;
            sc_trans_dst++;
            sc_trans_src++;
        }
        sc_trans_src = sc_blank_chr;
    }
}



/* provisional name */
void sc_chr_to_ram(u16 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        *sc_bak_ptr = *sc_trans_src;
        sc_bak_ptr++;
        sc_trans_src++;
    }
}



/* provisional name */
void sc_chr_sheet_to_ram(u16 chr, u16 pos, u16 w, u16 h) {
    u16 i;
    u16 j;
    u16 k;
    u8* src;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    sc_bak_ptr = sc_chr_ram + pos * 32;
    src = sc_trans_src;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            for (k = 0; k < 32; k++) {
                *sc_bak_ptr = *sc_trans_src;
                sc_bak_ptr++;
                sc_trans_src++;
            }
        }
        src += 0x200;
        sc_trans_src = src;
        sc_bak_ptr += 0x200;
    }
}



/* provisional name */
void sc_chr_backup(s8 restore) {
    sc_trans_dst = (u16*)(SS_RAM + 0x9E80);
    sc_bak_ptr = sc_chr_bak_1p;
    if (restore) {
        sc_chr_load(4);
    } else {
        sc_chr_save(4);
    }
    sc_trans_dst = (u16*)(SS_RAM + 0xCA80);
    sc_bak_ptr = sc_chr_bak_2p;
    if (restore) {
        sc_chr_load(4);
    } else {
        sc_chr_save(4);
    }
}



void Ranking_00_6th(s8 flag) {
    s32 n;
    if (flag) {
        sc_chr_backup(0);
    }
    sc_trans_src = (u8 *)sc_chr_data;
    sc_trans_dst = (volatile u16*)(SS_RAM + 0x8000);
    for (n = 0; n < 0x2800; n++) {
        sc_trans_word = 0;
        sc_trans_word = *sc_trans_src;
        *sc_trans_dst = sc_trans_word;
        sc_trans_dst++;
        sc_trans_src++;
    }
    if (flag) {
        sc_chr_backup(1);
    }
}



/* Darkens a screen area with the tone-down characters; returns the number of bytes copied. */
s32 ToneDown(s8 tone) {
    const TONE_ENTRY* e = (const TONE_ENTRY*)((const s8*)tone_down_tbl + (s8)(tone * sizeof(TONE_ENTRY)));
    sc_trans_src = (u8*)sc_chr_data + e->chr * 32;
    sc_trans_dst = (u16*)((SS_RAM + 0x8000) + e->pos * 64);
    return sc_chr_trans(e->n);
}



/* provisional name */
void sc_chr_list_trans(s8 ix) {
    const u16* slot = sc_chr_list_tbl[ix].slot;
    const u16* src = sc_chr_list_tbl[ix].src;
    u16 n = *slot++;
    u16 i;
    for (i = 0; i < n; i++) {
        sc_trans_dst = (u16*)((SS_RAM + 0x8000) + *slot++ * 64);
        sc_trans_src = &sc_chr_data[*src++ * 32];
        sc_trans_src = &sc_chr_data[(s32)(*src++ * 32) / 2 * 2];
        *sc_trans_dst = *sc_trans_src;
    }
}



/* provisional name */
u8* sc_chr_slot_trans(s8 ix, u16 code, s8 to_ram) {
    const u16* const* list = &sc_chr_slot_tbl[ix];
    const u16* p = *list;
    u8* base;
    u16 n;
    u16 i;
    u16 k;
    sc_trans_src = (u8*)&sc_chr_data[code * 32 / 2];
    n = *p++;
    if (to_ram == 0) {
        base = (u8*)(SS_RAM + 0x8000);
        for (i = 0; i < n; i++) {
            sc_trans_dst = (u16*)(base + *p++ * 64);
            for (k = 0; k < 32; k++) {
                *sc_trans_dst = *sc_trans_src;
                sc_trans_dst++;
                sc_trans_src++;
            }
        }
    } else {
        base = sc_chr_ram;
        for (i = 0; i < n; i++) {
            sc_bak_ptr = base + *p++ * 32;
            for (k = 0; k < 32; k++) {
                *sc_bak_ptr = *sc_trans_src;
                sc_bak_ptr++;
                sc_trans_src++;
            }
        }
    }
    return base;
}

void sc_ram_to_vram(ix, dx, dy)
char ix;
char dx;
char dy;
{
    const CELL_SET *set;
    const u16 *pos;
    const u16 *code;
    const u16 *attr;
    u16 *cell;
    u16 n;
    u16 i;

    set = &sc_ram_vram_tbl[ix];
    pos = set->pos;
    attr = set->attr;
    code = set->code;
    n = *code++;
    if (dx == 0 && dy == 0) {
        for (i = 0; i < n; i++) {
            cell = (u16 *)(SS_RAM + *pos++);
            cell[0] = *code;
            cell[1] = ((*code++ >> 8) & 1) | *attr++;
        }
    } else {
        for (i = 0; i < n; i++) {
            cell = (u16 *)(SS_RAM + *pos++ + dx * 4 + dy * 0x100);
            cell[0] = *code;
            cell[1] = ((*code++ >> 8) & 1) | *attr++;
        }
    }
}



void sc_ram_to_vram_opc(s8 ix, s8 dx, s8 dy, u16 attr) {
    const CELL_SET* set = &sc_ram_vram_tbl[ix];
    const u16* pos = set->pos;
    const u16* code = set->code;
    u16 n = *code++;
    u16* cell;
    u16 i;
    s32 x = dx;
    if (x == 0 && dy == 0) {
        for (i = 0; i < n; i++) {
            cell = (u16*)(SS_RAM + *pos++);
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | attr;
        }
    } else {
        for (i = 0; i < n; i++) {
            cell = (u16*)(SS_RAM + *pos++ + x * 4 + dy * 0x100);
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | attr;
        }
    }
}



/* Writes one text cell (code and attribute); returns the attribute word written. */
/* provisional name */
s32 tilemap_put_cell(u16 x, u16 y, u16 attr, u16 code) {
    u16* cell = (u16*)(SS_RAM + x * 4 + y * 0x100);
    cell[0] = code;
    return cell[1] = ((code & 0x100) >> 8) | attr;
}



void score8x16_put(u16 x, u16 y, u16 attr, u16 code) {
    code += 0x60;
    tilemap_put_cell(x, y, attr, code);
    tilemap_put_cell(x, y + 1, attr, code + 0x10);
}



void score16x24_put(s16 x, s16 y, s16 attr, s16 n) {
    s16 code = n * 6 + 0x130;
    tilemap_put_cell(x, y, attr, code);
    tilemap_put_cell(x + 1, y, attr, code + 1);
    tilemap_put_cell(x, y + 1, attr, code + 2);
    tilemap_put_cell(x + 1, y + 1, attr, code + 3);
    tilemap_put_cell(x, y + 2, attr, code + 4);
    tilemap_put_cell(x + 1, y + 2, attr, code + 5);
}



/* provisional name */
void sc_celllist_put(u8 ix) {
    const CELL_ENTRY* const* tbl = &sc_celllist_tbl[ix];
    const CELL_ENTRY* p = *tbl;
    while (p->x != 100) {
        tilemap_put_cell(p->x, p->y, p->attr, p->code);
        p++;
    }
}



/* provisional name */
void sc_celllist_put_scr(u8 ix) {
    const CELL_ENTRY* cell = sc_celllist_tbl[ix];
    s16* pos = &DE_X[sc_celllist_scr_tbl[ix]];
    while (cell->x != 100) {
        tilemap_put_cell(cell->x + *pos, cell->y, cell->attr, cell->code);
        cell++;
    }
}



/* provisional name */
void sc_celllist_put_pos(u8 kind, u8 dx, u8 dy) {
    const CELL_ENTRY* p = sc_celllist_tbl[kind];
    s16* ofs = &DE_X[sc_celllist_scr_tbl[kind]];
    while (p->x != 100) {
        tilemap_put_cell(dx + (*ofs + p->x), p->y + dy, p->attr, p->code);
        p++;
    }
}



/* provisional name */
void sc_attr_put(u16 x, u16 y, u16 attr) {
    u16* cell = (u16*)(SS_RAM + x * 4 + y * 0x100);
    cell[1] = (cell[1] & 1) | attr;
}



/* provisional name */
void player_name_trans(void) {
    u16 i;
    sc_trans_dst = (u16*)(SS_RAM + 0x8D40);
    if (Country == 1) {
        for (i = 0; i < 2; i++) {
            sc_trans_src = (u8*)(sc_chr_data + (((My_char[i] * 8 + 0x408) << 5) >> 1));
            sc_chr_trans(5);
            sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
        }
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((My_char[i] & 0x7F) == 14 || (My_char[i] & 0x7F) == 15) {
            sc_trans_src = sc_name_export_chr;
        } else {
            sc_trans_src = (u8*)(sc_chr_data + (((My_char[i] * 8 + 0x408) << 5) >> 1));
        }
        sc_chr_trans(5);
        sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
    }
}



void player_name(void) {
    u16 i;
    player_name_trans();
    for (i = 0; i < 5; i++) {
        tilemap_put_cell(i + 6, 3, 2, i + 53);
    }
    for (i = 0; i < 5; i++) {
        tilemap_put_cell(i + 37, 3, 2, i + 58);
    }
}



/* provisional name */
void sa_number_trans(void) {
    sc_trans_dst = (u16*)(SS_RAM + 0xB600);
    if (My_char[0] == PL_GILL) {
        sc_trans_src = (u8*)gill_sa_number_chr;
    } else {
        sc_trans_src = (u8*)&sc_chr_data[((Super_Arts[0] * 4 + 2304) * 32) >> 1];
    }
    sc_chr_trans(4);
    sc_trans_dst = (u16*)(SS_RAM + 0xB700);
    if (My_char[1] == PL_GILL) {
        sc_trans_src = (u8*)gill_sa_number_chr;
    } else {
        sc_trans_src = (u8*)&sc_chr_data[((Super_Arts[1] * 4 + 2304) * 32) >> 1];
    }
    sc_chr_trans(4);
}



/* provisional name */
void stun_mark_put(pl)
s8 pl;
{
    u16 i;
    const s16* pos = &smark_pos_tbl[My_char[pl]][pl];
    s16 code = smark_kind_tbl[My_char[pl]] * 4;
    for (i = 0; i < smark_kind_tbl[My_char[pl]] + 4; i++) {
        tilemap_put_cell(*pos + i, 3, 20, code + i + 33);
    }
}

void max_mark_write(char side, s32 left, u32 count, s32 x, char mark)
{
    u16 i;

    for (i = 0; i < (u16)count; i++) {
        if (side == 0) {
            tilemap_put_cell(x + 6 + i, 26, 34, mark * 6 + 42 + i);
        } else {
            tilemap_put_cell(x - left + 42 + i, 26, 34, mark * 6 + 42 + i);
        }
    }
}

/* provisional name */
void tilemap_clear_rect(x0, y0, x1, y1)
    u32 x0;
    u32 y0;
    u32 x1;
    u32 y1;
{
    u16 *line;
    u16 *cell;
    s32 width;
    u16 row;
    u16 col;

    line = (u16 *)(SS_RAM + (u16)x0 * 4 + (u16)y0 * 0x100);
    width = (u16)x1 - (u16)x0 + 1;
    for (row = 0; row < (s32)((u16)y1 - (u16)y0 + 1); row++) {
        cell = line;
        for (col = 0; col < width; col++) {
            cell[0] = 0x20;
            cell[1] = 0;
            cell += 2;
        }
        line = (u16 *)((u8 *)line + 0x100);
    }
}

/* provisional name */
void sc_fill_rect(u32 x, u32 y, u16 w, u16 h, u16 code, u16 attr)
{
    u16 *line;
    u16 *cell;
    u16 row;
    u16 col;

    line = (u16 *)(SS_RAM + (u16)x * 4 + (u16)y * 0x100);
    for (row = 0; row < h; row++) {
        cell = line;
        for (col = 0; col < w; col++) {
            cell[0] = code;
            cell[1] = ((code >> 8) & 1) | attr;
            cell += 2;
        }
        line = (u16 *)((u8 *)line + 0x100);
    }
}

void Sa_frame_Clear(void)
{
  tilemap_clear_rect(0,0x19,0x37,0x1b);
  return;
}



/* provisional name */
void sc_picture_put(u8 ix, s8 dx, s8 dy) {
    sc_trans_dst = (u16*)(SS_RAM + 0xE000);
    sc_trans_src = (u8*)sc_chr_data + picture_chr_tbl[ix] * 32;
    sc_chr_trans(128);
    sc_ram_to_vram_opc(picture_set_tbl[ix], dx, dy, picture_attr_tbl[ix]);
}



/* provisional name */
void count_digit_trans(mode, top, bottom)
u8 mode;
u16 top;
u16 bottom;
{
    sc_trans_src = (u8*)&sc_chr_data[(top * 256) >> 1] + 0x14000;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xB800);
        sc_chr_trans(8);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1C00];
        sc_chr_to_ram(0x100);
        break;
    }
    sc_trans_src = (u8*)&sc_chr_data[(bottom * 256) >> 1] + 0x14000;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xBC00);
        sc_chr_trans(8);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1E00];
        sc_chr_to_ram(0x100);
        break;
    }
}


/* provisional name */
void count_small_digit_trans(u8 mode, u16 top, u16 bottom) {
    sc_trans_src = (u8*)&sc_chr_data[(top * 32) >> 1] + 0x15400;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xC800);
        sc_chr_trans(1);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x2400];
        sc_chr_to_ram(32);
        break;
    }
    sc_trans_src = (u8*)&sc_chr_data[(bottom * 32) >> 1] + 0x15400;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xC840);
        sc_chr_trans(1);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x2420];
        sc_chr_to_ram(32);
        break;
    }
}



/* provisional name */
void bcount_digit_trans(u8 mode, u16 top, u16 bottom) {
    sc_trans_src = (u8*)&sc_chr_data[(top * 3 * 64) >> 1] + 0x20000;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xB800);
        sc_chr_trans(6);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1C00];
        sc_chr_to_ram(192);
        break;
    }
    sc_trans_src = (u8*)&sc_chr_data[(bottom * 3 * 64) >> 1] + 0x20000;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xBC00);
        sc_chr_trans(6);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1E00];
        sc_chr_to_ram(192);
        break;
    }
}



/* provisional name */
void bcount_mark_trans(u8 mode) {
    sc_trans_src = bcount_mark_chr;
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xB980);
        sc_chr_trans(1);
        break;
    case 1:
        sc_bak_ptr = bcount_mark_chr_w;
        sc_chr_to_ram(32);
        break;
    }
}



/* provisional name */
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
    tilemap_put_cell(e[3] + (*&DE_X)[3], e[4], attr, e[5]);
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
s16 win_mark_find(s16 pl) {
    s16 i;
    for (i = 0; i < Battle_Round[Play_Type] + 1; i++) {
        if (win_type[pl][i] == 3) {
            return i;
        }
    }
    return -1;
}
