/*
 * TEXTSOUND.C  Text layer printing, sprite DMA copies and the sound driver interface
 *
 * Text layer routines used by test mode, menus and messages: tilemap_chunk_copy_16b loads font
 * characters, tilemap_fill_all / rectfill / rect_fill clear areas, and the print routines put
 * characters, strings (with attribute), script sequences and signed decimal, raw and binary numbers.
 * palette_bank_set and palette_write copy rows of data (such as palettes) through the sprite DMA,
 * and tilemap_fill_column0 empties the sprite buffer.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
#include "sound_voice_2.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "textsound.h"
#include "cps3.h"

struct PLW_tag;void tilemap_chunk_copy_16b(s16 *dst, char *src, s32 chunks)
{
    s32 i;
    s32 n;
    for (i = 0; i < chunks; i++) {
        n = 32;
        do {
            n -= 2;
            dst[0] = src[0];
            dst[1] = src[1];
            dst += 2;
            src += 2;
        } while (n != 0);
    }
}

/* provisional name */
void palette_bank_set(s32 offset)
{
    u32 addr;
    addr = offset + COLOR_RAM;
    palette_base = addr;
    *(volatile u16 *)(SS_REG + 0x24) = (u16)(addr >> 10) & 0xFF;
}

/* provisional name */
u32 palette_write(s32 offset, u16 *src, s32 count)
{
    u16 *dst;
    s32 i;
    dst = (u16 *)(offset + palette_base);
    for (i = 0; i < count; i++) {
        if (*src != 0xFFFF) {
            *dst = *src;
        }
        src++;
        dst++;
    }
    return 0xFFFF;
}



/* provisional name */
void tilemap_fill_all(u16 attr, u16 code) {
    u16* p;
    u16* q;
    if (attr == 0xFFFF && code == 0xFFFF) {
        return;
    }
    if (attr != 0xFFFF && code == 0xFFFF) {
        p = (u16*)(SS_RAM + 0x2);
        for (q = (u16*)SS_RAM; q < (u16*)(SS_RAM + 0x3FFF); q += 2) {
            *p = (*p & 1) | attr;
            p += 2;
        }
    } else if (attr == 0xFFFF && code != 0xFFFF) {
        for (p = (u16*)SS_RAM; p < (u16*)(SS_RAM + 0x3FFF); p += 2) {
            p[0] = code;
            p[1] = (p[1] & 0xFFFE) | ((code & 0x100) >> 8);
        }
    } else {
        for (p = (u16*)SS_RAM; p < (u16*)(SS_RAM + 0x3FFF); p += 2) {
            p[0] = code;
            p[1] = attr | ((code & 0x100) >> 8);
        }
    }
}



/* provisional name */
void tilemap_put_block(x, y, attr, code)
u16 x;
u16 y;
u16 attr;
u16 code;
{
    u16* p = (u16*)(SS_RAM + (x << 2) + (y << 8));
    u32 w = ((code & 0x0E00) >> 9) + 1;
    u32 h = ((code & 0x7000) >> 12) + 1;
    s32 adv = (128 - w * 2) * 2;
    u32 i;
    u32 j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            p[0] = code;
            p[1] = attr | ((code & 0x100) >> 8);
            p += 2;
            if (p > (u16*)(SS_RAM + 0x3FFF)) {
                p = (u16*)SS_RAM;
            }
            code++;
        }
        p = (u16*)((u8*)p + adv);
        if (p > (u16*)(SS_RAM + 0x3FFF)) {
            p = (u16*)SS_RAM;
        }
    }
}



/* provisional name */
u16* tilemap_put_block_next(u16* p, u16 attr, u16 code) {
    u32 w = ((code & 0x0E00) >> 9) + 1;
    u32 h = ((code & 0x7000) >> 12) + 1;
    s32 adv = (128 - w * 2) * 2;
    u32 i;
    u32 j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            p[0] = code;
            p[1] = attr | ((code & 0x100) >> 8);
            p += 2;
            if (p > (u16*)(SS_RAM + 0x3FFF)) {
                p = (u16*)SS_RAM;
            }
            code++;
        }
        p = (u16*)((u8*)p + adv);
        if (p > (u16*)(SS_RAM + 0x3FFF)) {
            p = (u16*)SS_RAM;
        }
    }
    p = (u16*)((u8*)p + w * 2 * 2 - h * 256);
    if (p > (u16*)(SS_RAM + 0x3FFF)) {
        p = (u16*)SS_RAM;
    }
    return p;
}



/* provisional name */
void tilemap_put_char(u16 x, u16 y, u16 attr, u16 code) {
    u16* cell = (u16*)(SS_RAM + x * 4 + y * 0x100);
    cell[0] = code;
    cell[1] = ((code & 0x100) >> 8) | attr;
}



/* provisional name */
void tilemap_print_string_attr(u16 x, u16 y, u16 attr, const s8* str) {
    u16* p = (u16*)(SS_RAM + (x << 2) + (y << 8));
    while (*str) {
        p[0] = *str;
        p[1] = attr;
        p += 2;
        if (p > (u16*)(SS_RAM + 0x3FFF)) {
            p = (u16*)SS_RAM;
        }
        str++;
    }
}



/* provisional name */
s32 tilemap_rect_fill(u16 x, u16 y, u16 w, u16 h, u16 attr, u16 code) {
    u16* p;
    s16 skip;
    s32 row;
    s32 col;
    s32 ret = 42;
    s16 bank;
    u16 v;
    if (attr == 0xFFFF) {
        if (code == 0xFFFF) {
            return ret;
        }
    }
    p = (u16*)((u32)((u16*)SS_RAM) + (x << 2) + (y << 8));
    skip = 0x80 - w * 2;
    if (attr != 0xFFFF && code == 0xFFFF) {
        for (row = 0; row < h; row++) {
            for (col = 0; col < w; col++) {
                v = (p[1] & 1) | attr;
                p[1] = v;
                ret = (s16)v;
                p += 2;
                if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                    p = ((u16*)SS_RAM);
                }
            }
            p += skip;
            if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                p = ((u16*)SS_RAM);
            }
            continue;
        }
    } else if (attr == 0xFFFF && code != 0xFFFF) {
        bank = (code >> 8) & 1;
        for (row = 0; row < h; row++) {
            for (col = 0; col < w; col++) {
                p[0] = code;
                p[1] = (p[1] & 0xFFFE) | bank;
                p += 2;
                if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                    p = ((u16*)SS_RAM);
                }
            }
            p += skip;
            if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                p = ((u16*)SS_RAM);
            }
        }
    } else {
        attr |= (code >> 8) & 1;
        for (row = 0; row < h; row++) {
            for (col = 0; col < w; col++) {
                p[0] = code;
                p[1] = attr;
                ret = (s16)attr;
                p += 2;
                if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                    p = ((u16*)SS_RAM);
                }
            }
            p += skip;
            if (p > ((u16*)(SS_RAM + 0x3FFF))) {
                p = ((u16*)SS_RAM);
            }
        }
    }
    return ret;
}



/* provisional name */
void tilemap_print_hex_block(u16 x, u16 y, u16 attr, u32 value, u16 digits, u16 mode) {
    TEXT_CELL* p;
    s32 n;
    u32 mask;
    s32 started;
    s32 sign;
    s32 i;
    u16 d;
    u16 font;
    s32 cells;
    s32 code;
    font = num_font_code;
    cells = (((font & 0x7000) >> 12) + 1) * (((font & 0xE00) >> 9) + 1);
    p = (TEXT_CELL*)((u32)((u16*)SS_RAM) + (x << 2) + (y << 8));
    started = 0;
    n = digits;
    mask = 15 << ((n - 1) * 4);
    sign = (mode & 4) != 0;
    for (i = n; i > 0; i--) {
        d = (value & mask) >> ((i - 1) * 4);
        if (i == n && sign) {
            if (d < 0) {
                p->code = '-';
                d &= 0x7FFF;
            } else {
                p->code = '+';
            }
            p->attr = attr;
            p++;
        }
        code = cells * d + (s16)num_font_code;
        if (started == 0) {
            if (d == 0) {
                if (i == 1) {
                    p = tilemap_put_block_next(p, attr, code);
                } else {
                    switch (mode & 3) {
                    case 1:
                        p->code = ' ';
                        p->attr = attr;
                    case 2:
                        p++;
                        break;
                    case 3:
                        break;
                    default:
                        p = tilemap_put_block_next(p, attr, code);
                        break;
                    }
                }
            } else {
                started = 1;
                p = tilemap_put_block_next(p, attr, code);
            }
        } else {
            p = tilemap_put_block_next(p, attr, code);
        }
        if ((u32)p > (u32)((u16*)(SS_RAM + 0x3FFF))) {
            p = (TEXT_CELL*)((u16*)SS_RAM);
        }
        mask >>= 4;
    }
}



/* provisional name */
void tilemap_print_hex(u16 x, u16 y, u16 attr, u32 value, u16 digits, u16 mode) {
    TEXT_CELL* p;
    u16 n;
    u32 mask;
    s32 started;
    s32 sign;
    s32 i;
    u16 d;
    p = (TEXT_CELL*)((u32)((u16*)SS_RAM) + (x << 2) + (y << 8));
    started = 0;
    n = digits;
    mask = 15 << ((n - 1) * 4);
    sign = (mode & 4) != 0;
    for (i = n; i > 0; i--) {
        d = (value & mask) >> ((i - 1) * 4);
        if (i == n && sign) {
            if (d < 0) {
                p->code = '-';
                d &= 0x7FFF;
            } else {
                p->code = '+';
            }
            p->attr = attr;
            p++;
        }
        if (started == 0) {
            if (d == 0) {
                if (i == 1) {
                    p->code = d;
                    p->attr = attr;
                } else {
                    switch (mode & 3) {
                    case 1:
                        p->code = ' ';
                        p->attr = attr;
                    case 2:
                        p++;
                        break;
                    case 3:
                        break;
                    default:
                        p->code = d;
                        p->attr = attr;
                        p++;
                        break;
                    }
                }
            } else {
                p->code = d;
                p->attr = attr;
                started = 1;
                p++;
            }
        } else {
            p->code = d;
            p->attr = attr;
            p++;
        }
        if ((u32)p > (u32)((u16*)(SS_RAM + 0x3FFF))) {
            p = (TEXT_CELL*)((u16*)SS_RAM);
        }
        mask >>= 4;
    }
}



/* provisional name */
void tilemap_print_binary(u16 x, u16 y, u16 attr, const s8* data, u16 n) {
    u16* p = (u16*)(SS_RAM + (x << 2) + (y << 8));
    u32 mask = 0x80;
    while (n > 0) {
        if (*data & mask) {
            p[0] = '1';
        } else {
            p[0] = '0';
        }
        p[1] = attr;
        p += 2;
        if (p > (u16*)(SS_RAM + 0x3FFF)) {
            p = (u16*)SS_RAM;
        }
        mask >>= 1;
        if (mask == 0) {
            mask = 0x80;
            data++;
        }
        n--;
    }
}



/* provisional name */
void tilemap_print_script_seq(u16 x, u16 y, u16 pal, const TMSCRIPT* scr) {
    u16* dst;
    u16* blk;
    TMLINE* line;
    u8* s;
    u16 d;
    u16 attr;
    s32 ofs = (x * 2 + y * 0x80) * 2;
    s32 n;
    s32 i;
    u32 w;
    u32 h;
    u32 row;
    u32 col;
    if (scr->kind == 0) {
        line = (TMLINE*)scr->data;
        dst = (u16*)((u8*)((u16*)SS_RAM) + (line->x << 2) + (line->y << 8));
        if (x + y != 0) {
            dst = (u16*)((u8*)dst + ofs);
        }
        for (s = line->str; *s != 0; s++) {
            if (*s == 10) {
                line++;
                dst = (u16*)((u8*)((u16*)SS_RAM) + (line->x << 2) + (line->y << 8));
                if (x + y != 0) {
                    dst = (u16*)((u8*)dst + ofs);
                }
                s = line->str;
            }
            dst[0] = *s;
            if (pal == 0xFFFF) {
                dst[1] = line->attr;
            } else {
                dst[1] = pal;
            }
            dst = dst + 2;
            if (dst > ((u16*)(SS_RAM + 0x3FFF))) {
                dst = ((u16*)SS_RAM);
            }
        }
    } else {
        for (blk = (u16*)scr->data; *blk != 0;) {
            n = blk[0];
            attr = blk[3];
            dst = (u16*)((u8*)((u16*)SS_RAM) + (blk[1] << 2) + (blk[2] << 8));
            if (x + y != 0) {
                dst = (u16*)((u8*)dst + ofs);
            }
            blk = blk + 4;
            for (i = 0; i < n; i++) {
                d = *blk;
                w = ((d & 0xE00) >> 9) + 1;
                h = ((d & 0x7000) >> 12) + 1;
                for (row = 0; row < h; row++) {
                    for (col = 0; col < w; col++) {
                        dst[0] = d;
                        if (pal == 0xFFFF) {
                            dst[1] = attr | ((d & 0x100) >> 8);
                        } else {
                            dst[1] = ((d & 0x100) >> 8) | pal;
                        }
                        dst = dst + 2;
                        d++;
                        if (dst > ((u16*)(SS_RAM + 0x3FFF))) {
                            dst = ((u16*)SS_RAM);
                        }
                    }
                    dst += 0x80 - w * 2;
                    if (dst > ((u16*)(SS_RAM + 0x3FFF))) {
                        dst = ((u16*)SS_RAM);
                    }
                }
                dst += w * 2 - h * 0x80;
                blk++;
                if (dst > ((u16*)(SS_RAM + 0x3FFF))) {
                    dst = ((u16*)SS_RAM);
                }
                continue;
            }
        }
    }
}



/* provisional name */
void tilemap_print_string(u16 x, u16 y, u16 attr, const TM_STRING* sc) {
    u16* p;
    const u8* s;
    p = (u16*)(SS_RAM + (sc->x << 2) + (sc->y << 8));
    if (x + y) {
        p += x * 2 + y * 128;
    }
    s = (const u8*)sc->str;
    while (*s) {
        if (*s == 10) {
            sc++;
            p = (u16*)(SS_RAM + (sc->x << 2) + (sc->y << 8));
            if (x + y) {
                p += x * 2 + y * 128;
            }
            s = (const u8*)sc->str;
        }
        p[0] = *s;
        if (attr == 0xFFFF) {
            p[1] = sc->attr;
        } else {
            p[1] = attr;
        }
        p += 2;
        if (p > (u16*)(SS_RAM + 0x3FFF)) {
            p = (u16*)SS_RAM;
        }
        s++;
    }
}



/* provisional name */
void tilemap_fill_column0(u16 attr, u16 code) {
    u16* p;
    if ((system_ctrl_flag & 0x81) != 0x81) {
        return;
    }
    for (p = (u16*)SS_RAM; p < (u16*)(SS_RAM + 0x3FFF); p += 128) {
        p[0] = code;
        p[1] = attr | ((code & 0x100) >> 8);
    }
}


