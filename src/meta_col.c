/*
 * meta_col.c  Metamorphosis palette handling
 *
 * Palette routines for a player who takes on another character's look: metamor_color_trans
 * copies the chosen metamorphosis palette (by the player's colour number) into both colour RAM
 * pages for that player, metamor_color_copy copies one player's palette block to the other
 * side, and metamor_color_store / metamor_color_reset save the original colours and put them
 * back afterwards.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "meta_col.h"
#include "cps3.h"



void metamor_color_trans(s16 pl, s16 ix) {
    u16* dst = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    u16* dst2 = dst + 0x200;
    u16* src;
    u16* src2;
    s16 i;
    if (ix) {
        src = ((u16(*)[64])metamor_color_ptr_tbl[ix])[Player_Color[pl]];
        for (i = 0; i < 64; i++) {
            *dst++ = *src;
            *dst2++ = *src++;
        }
    } else {
        src = ((u16(*)[64])metamor_color_ptr_tbl[ix])[Player_Color[pl] * 2];
        src2 = ((u16(*)[64])metamor_color_ptr_tbl[ix])[Player_Color[pl] * 2] + 64;
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
    s16 i;
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

