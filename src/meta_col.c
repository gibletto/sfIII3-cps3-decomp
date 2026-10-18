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



extern const u16 metamor_color_bank_00[];
extern const u16 metamor_color_bank_01[];
extern const u16 metamor_color_bank_02[];
extern const u16 metamor_color_bank_03[];
extern const u16 metamor_color_bank_04[];
extern const u16 metamor_color_bank_05[];
extern const u16 metamor_color_bank_06[];
extern const u16 metamor_color_bank_07[];
extern const u16 metamor_color_bank_08[];
extern const u16 metamor_color_bank_09[];
extern const u16 metamor_color_bank_10[];
extern const u16 metamor_color_bank_11[];
extern const u16 metamor_color_bank_12[];
extern const u16 metamor_color_bank_13[];
extern const u16 metamor_color_bank_14[];
extern const u16 metamor_color_bank_15[];
extern const u16 metamor_color_bank_16[];
extern const u16 metamor_color_bank_17[];
extern const u16 metamor_color_bank_18[];
extern const u16 metamor_color_bank_19[];

u16 metamor_original[64];  /* 02069F80 */
u16 metamor_original2[64];  /* 0206A000 */


/* 02007C30 */
u16* metamor_color_ptr_tbl[24] = {
    (u16*)metamor_color_bank_00,
    (u16*)metamor_color_bank_01,
    (u16*)metamor_color_bank_02,
    (u16*)metamor_color_bank_03,
    (u16*)metamor_color_bank_04,
    (u16*)metamor_color_bank_05,
    (u16*)metamor_color_bank_06,
    (u16*)metamor_color_bank_07,
    (u16*)metamor_color_bank_08,
    (u16*)metamor_color_bank_09,
    (u16*)metamor_color_bank_10,
    (u16*)metamor_color_bank_11,
    (u16*)metamor_color_bank_12,
    (u16*)metamor_color_bank_13,
    (u16*)metamor_color_bank_14,
    (u16*)metamor_color_bank_14,
    (u16*)metamor_color_bank_15,
    (u16*)metamor_color_bank_16,
    (u16*)metamor_color_bank_17,
    (u16*)metamor_color_bank_18,
    (u16*)metamor_color_bank_19,
    (u16*)metamor_color_bank_00,
    (u16*)metamor_color_bank_00,
    (u16*)metamor_color_bank_00,
};


void metamor_color_trans(s16 pl, s16 ix) {
    u16* dst = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    u16* dst2 = dst + 0x200;
    struct PaletteBank { u16 color[7 * 2][64]; };
    u16* src;
    u16* src2;
    s16 i;
    if (ix) {
        src = metamor_color_ptr_tbl[ix];
        (void)&((WORK*)&metamor_color_ptr_tbl[ix])->be_flag;
        src += Player_Color[pl] * 64;
        for (i = 0; i < 64; i++) {
            *dst++ = *src;
            *dst2++ = *src++;
        }
    } else {
        src = ((struct PaletteBank*)metamor_color_ptr_tbl[ix])->color[Player_Color[pl] * 2];
        src2 = ((struct PaletteBank*)metamor_color_ptr_tbl[ix])->color[Player_Color[pl] * 2] + 64;
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
    dst = (u16*)((page == 1) * 0x800 + COLOR_RAM);
    dst = dst + 0x40;
    dst2 = dst + 0x200;
    src = (u16*)((page == 0) * 0x800 + COLOR_RAM);
    src = src + 0x40;
    src2 = src + 0x200;
    for (i = 0; i < 0x180; i++) {
        *dst++ = *src++;
        *dst2++ = *src2++;
    }
}



void metamor_color_store(s16 pl) {
    u16* src;
    s16 i;
    u16* src2;
    src = (u16*)COLOR_RAM + (pl == 1) * 0x400;
    src = src + 0x40;
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
    dst3 = dst + 0x80;
    dst2 += 0x40;
    dst4 = dst2 + 0x80;
    for (i = 0; i < 64; i++) {
        *dst++ = metamor_original[i];
        *dst3++ = metamor_original2[i];
        *dst2++ = metamor_original[i];
        *dst4++ = metamor_original2[i];
    }
}

