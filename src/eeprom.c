/*
 * EEPROM.C  EEPROM access and bookkeeping counters
 *
 * Low-level serial EEPROM routines: eeprom_read and eeprom_write transfer words with the
 * command sequence and ready polling (eeprom_wait_ready), eeprom_test saves the 64 words,
 * writes and verifies test patterns (eeprom_fill_verify) and restores them.
 * The bookkeeping counters kept in EEPROM (coins, service credits, free-play games,
 * dispensed cards) are incremented by bookkeep_*_count, flushed from pending counts by
 * bookkeep_flush and cleared by bookkeep_clear_all; a write error halts with an error screen.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "eeprom.h"
#include "cps3.h"



/* provisional name */
s8 eeprom_test(u16* buf) {
    register s16 i;
    u16* p;
    u16* q;
    if (eeprom_read(64, (volatile u16*)(EEP_ROM + 0x100), buf)) {
        return 1;
    }
    for (p = buf, q = eeprom_test_save, i = 0; i < 64; i++) {
        *q = *p;
        p++;
        q++;
    }
    if (eeprom_fill_verify(0xFFFF, buf)) {
        return 1;
    }
    if (eeprom_fill_verify(0xAAAA, buf)) {
        return 1;
    }
    if (eeprom_fill_verify(0x5555, buf)) {
        return 1;
    }
    if (eeprom_fill_verify(0, buf)) {
        return 1;
    }
    for (p = buf, q = eeprom_test_save, i = 0; i < 64; i++) {
        *p = *q;
        p++;
        q++;
    }
    if (eeprom_write(64, (volatile u16*)(EEP_ROM + 0x80), buf)) {
        return 1;
    }
    return 0;
}



/* provisional name */
s8 eeprom_fill_verify(u16 fill, u16* buf) {
    register s16 i;
    register u16* p;
    for (p = buf, i = 0; i < 64; i++) {
        *p = fill;
        p++;
    }
    if (eeprom_write(64, (volatile u16*)(EEP_ROM + 0x80), buf)) {
        return 1;
    }
    if (eeprom_read(64, (volatile u16*)(EEP_ROM + 0x100), buf)) {
        return 1;
    }
    for (p = buf, i = 0; i < 64; i++) {
        if (*p != fill) {
            return 1;
        }
        p++;
    }
    return 0;
}



/* provisional name */
s8 eeprom_read(s16 n, volatile u16* rom, u16* buf) {
    register s16 i;
    eep_strobe_0 = (*(volatile u16*)(EEP_ROM + 0x60));
    eep_strobe_1 = (*(volatile u16*)(EEP_ROM + 0x60));
    eep_strobe_2 = (*(volatile u16*)(EEP_ROM + 0x60));
    delay_cycles(161);
    eep_dummy = *rom;
    delay_cycles(161);
    if (eeprom_wait_ready()) {
        return 1;
    }
    eep_dummy = (*(volatile u16*)(EEP_ROM + 0x202));
    delay_cycles(161);
    if (eeprom_wait_ready()) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        eep_dummy = *rom;
        delay_cycles(161);
        if (eeprom_wait_ready()) {
            return 1;
        }
        *buf = (*(volatile u16*)(EEP_ROM + 0x202));
        delay_cycles(161);
        if (eeprom_wait_ready()) {
            return 1;
        }
        rom++;
        buf++;
    }
    eep_strobe_0 = (*(volatile u16*)EEP_ROM);
    eep_strobe_1 = (*(volatile u16*)EEP_ROM);
    eep_strobe_2 = (*(volatile u16*)EEP_ROM);
    delay_cycles(3);
    return 0;
}



/* provisional name */
s8 eeprom_write(n, dst, src)
s16 n;
u16* dst;
u16* src;
{
    register s16 i;
    eep_strobe_0 = *(volatile u16*)(EEP_ROM + 0x60);
    eep_strobe_1 = *(volatile u16*)(EEP_ROM + 0x60);
    eep_strobe_2 = *(volatile u16*)(EEP_ROM + 0x60);
    delay_cycles(0xA1);
    for (i = 0; i < n; i++) {
        *(u16*)((u8*)dst + 0x100) = 0;
        delay_cycles(0xA1);
        if (eeprom_wait_ready()) {
            return 1;
        }
        *dst = *src;
        delay_cycles(0xA1);
        if (eeprom_wait_ready()) {
            return 1;
        }
        dst += 1;
        src += 1;
    }
    eep_strobe_0 = *(volatile u16*)EEP_ROM;
    eep_strobe_1 = *(volatile u16*)EEP_ROM;
    eep_strobe_2 = *(volatile u16*)EEP_ROM;
    delay_cycles(0xA1);
    return 0;
}



/* provisional name */
s8 eeprom_wait_ready(void) {
    s32 i;
    for (i = 0; i < 0x30000; i++) {
        if ((*(volatile u16*)(EEP_ROM + 0x200) & 1) == 0) {
            return 0;
        }
    }
    return 1;
}

/* provisional name */
void eeprom_error_halt(void)
{
    tilemap_fill_all(0, 0x20);
    tilemap_print_string_attr(15, 8, 12, eeprom_error_str);    /* "EEPROM  ERROR" */
    while (1) {
        task_sleep(1);
    }
}



/* provisional name */
void bookkeep_coin_count(void) {
    book_coin_count[0]++;
    if (eeprom_write(2, (volatile u16*)(EEP_ROM + 0xE0), &book_coin_count[0])) {
        eeprom_error_halt();
    }
}



/* provisional name */
void bookkeep_service_count(void) {
    book_coin_count[1]++;
    if (eeprom_write(2, (volatile u16*)(EEP_ROM + 0xE4), &book_coin_count[1])) {
        eeprom_error_halt();
    }
}



/* provisional name */
void bookkeep_freeplay_count(void) {
    book_coin_count[2]++;
    if (eeprom_write(2, (volatile u16*)(EEP_ROM + 0xE8), (u16*)&book_coin_count[2])) {
        eeprom_error_halt();
    }
}



/* provisional name */
void bookkeep_card_count(void) {
    book_coin_count[3]++;
    if (eeprom_write(2, (volatile u16*)(EEP_ROM + 0xEC), (u16*)&book_coin_count[3])) {
        eeprom_error_halt();
    }
}



/* provisional name */
void bookkeep_clear_all(void) {
    u32 buf[4];
    book_coin_count[0] = buf[0] = 0;
    book_coin_count[1] = buf[1] = 0;
    book_coin_count[2] = buf[2] = 0;
    book_coin_count[3] = buf[3] = 0;
    if (eeprom_write(8, (u16*)(EEP_ROM + 0xE0), (u16*)buf)) {
        eeprom_error_halt();
    }
}



/* provisional name */
s32 bookkeep_flush(void) {
    s32 r;
    if (bookkeep_add[0] != 0) { book_coin_count[0] += bookkeep_add[0]; if ((r = eeprom_write(2, (volatile u16*)((EEP_ROM + 0xE0) + (0) * 4), &book_coin_count[0])) != 0) { eeprom_error_halt(); } bookkeep_add[0] = 0; } else { r = 0; };
    if (bookkeep_add[1] != 0) { book_coin_count[1] += bookkeep_add[1]; if ((r = eeprom_write(2, (volatile u16*)((EEP_ROM + 0xE0) + (1) * 4), &book_coin_count[1])) != 0) { eeprom_error_halt(); } bookkeep_add[1] = 0; } else { r = 0; };
    if (bookkeep_add[2] != 0) { book_coin_count[2] += bookkeep_add[2]; if ((r = eeprom_write(2, (volatile u16*)((EEP_ROM + 0xE0) + (2) * 4), &book_coin_count[2])) != 0) { eeprom_error_halt(); } bookkeep_add[2] = 0; } else { r = 0; };
    if (bookkeep_add[3] != 0) { book_coin_count[3] += bookkeep_add[3]; if ((r = eeprom_write(2, (volatile u16*)((EEP_ROM + 0xE0) + (3) * 4), &book_coin_count[3])) != 0) { eeprom_error_halt(); } bookkeep_add[3] = 0; } else { r = 0; };
    return r;
}
