/*
 * meta_col.c  Metamorphosis palette handling and small C library routines
 *
 * Palette routines for a player who takes on another character's look: metamor_color_trans
 * copies the chosen metamorphosis palette (by the player's colour number) into both colour RAM
 * pages for that player, metamor_color_copy copies one player's palette block to the other
 * side, and metamor_color_store / metamor_color_reset save the original colours and put them
 * back afterwards.
 * The rest is library code: memset, strcat, strcpy and strstr, and the BCD helpers hex_to_bcd
 * (binary to BCD), abcd and sbcd (BCD add and subtract) used for scores and counters.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "meta_col.h"
#include "cps3.h"



void metamor_color_trans(s16 pl, s16 ix) {
    u16* dst = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    u16* dst2 = dst + 0x200;
    u16* src;
    u16* src2;
    s16 i;
    if (ix) {
        src = metamor_color_ptr_tbl[ix] + Player_Color[pl] * 64;
        for (i = 0; i < 64; i++) {
            *dst++ = *src;
            *dst2++ = *src++;
        }
    } else {
        src = metamor_color_ptr_tbl[ix] + Player_Color[pl] * 128;
        src2 = src + 64;
        for (i = 0; i < 64; i++) {
            *dst++ = *src++;
            *dst2++ = *src2++;
        }
    }
}



void metamor_color_copy(s16 page) {
    u16* dst;
    u16* dst2;
    u16* src;
    u16* src2;
    s16 i;
    dst = (u16*)COLOR_RAM + (page == 1) * 0x400;
    dst += 0x40;
    dst2 = dst + 0x200;
    src = (u16*)COLOR_RAM + (!page) * 0x400;
    src += 0x40;
    src2 = src + 0x200;
    for (i = 0; i < 0x180; i++) {
        *dst++ = *src++;
        *dst2++ = *src2++;
    }
}



void metamor_color_store(s16 pl) {
    u16* src = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    u16* src2;
    s32 i;
    src += 0x40;
    src2 = src + 0x80;
    for (i = 0; i < 64; i++) {
        metamor_original[i] = *src++;
        metamor_original2[i] = *src2++;
    }
}



/* provisional name */
void metamor_color_reset(s16 pl) {
    u16* dst = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    u16* dst2 = dst + 0x200;
    u16* dst3;
    u16* dst4;
    s16 i;
    dst += 0x40;
    dst2 += 0x40;
    dst3 = dst + 0x80;
    dst4 = dst2 + 0x80;
    for (i = 0; i < 64; i++) {
        *dst++ = metamor_original[i];
        *dst3++ = metamor_original2[i];
        *dst2++ = metamor_original[i];
        *dst4++ = metamor_original2[i];
    }
}

u8 *memset(u8 *dst, u8 c, u32 n)
{
    u32 i;
    u8 *p;

    p = dst;
    for (i = 0; i < n; i++) {
        *p++ = c;
    }
    return dst;
}



u8* strcat(u8* dst, u8* src) {
    u8* p = dst;
    u8* s = src;
    for (; *p != 0; p++) {
    }
    while ((*p++ = *s++) != 0) {
    }
    return dst;
}



char* strcpy(char* dst, const char* src) {
    return _builtin_strcpy(dst, src);
}



/* provisional name */
char* strstr(char* s, const char* sub) {
    u32 sublen = strlen(sub);
    s32 n = strlen(s) - sublen + 1;
    u32 i;
    if (n > 0 && sublen > 0) {
        for (i = 0; i < n; i++) {
            if (memcmp(s + i, sub, sublen) == 0) {
                return s + i;
            }
        }
    }
    return 0;
}



/* provisional name */
u32 hex_to_bcd(u32 dat) {
    u32 sum;
    u8* bcd = (u8*)&sum;
    const u8* p = bcd_weight_end;
    u32 mask;
    sum = 0;
    for (mask = 0x8000; mask != 0; mask >>= 1) {
        if (dat & mask) {
            bcdext = 0;
            bcd[3] = abcd(bcd[3], *--p);
            bcd[2] = abcd(bcd[2], *--p);
            bcd[1] = abcd(bcd[1], *--p);
            bcd[0] = abcd(bcd[0], *--p);
        } else {
            p -= 4;
        }
    }
    return sum;
}



/* provisional name */
u8 abcd(u8 a, u8 b) {
    u16 c;
    u16 d;
    if ((d = (a & 0xF) + (bcdext & 1) + (b & 0xF)) > 9) {
        d -= 10;
        d |= 16;
    }
    c = (a & 0xF0) + (b & 0xF0);
    if ((d += c) > 0x99) {
        d -= 160;
        d &= 0xFF;
        bcdext = 1;
    } else {
        bcdext = 0;
    }
    return d;
}


u8 sbcd(u8 a, u8 b) {
    s16 c, d;
    if ((d = (b & 0xF) - (a & 0xF) - (bcdext & 1)) < 0) {
        d += 10;
        d |= 16;
    }
    c = (b & 0xF0) - (a & 0xF0) - (d & 0xF0);
    d &= 0xF;
    if ((d |= c) < 0) {
        d += 160;
        bcdext = 1;
    } else {
        bcdext = 0;
    }
    return d;
}
