/*
 * TEXTSOUND_3.C  Text layer printing, sprite DMA copies and the sound driver interface (part 3)
 *
 * Small library helpers close the file: memcmp, strlen, delay_cycles and dma0_transfer_wait (SH-2
 * on-chip DMA channel 0).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
#include "sound_voice_2.h"
#include "textsound_3.h"
#include "cps3.h"



s32 memcmp(const u8* a, const u8* b, u32 n) {
    u32 i;
    const u8* p = a;
    if (n == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (*p++ != *b++) {
            break;
        }
    }
    return p[-1] - b[-1];
}



s32 strlen(const char *s) {
    s32 n = 0;
    while (*s++) {
        n++;
    }
    return n;
}



/* provisional name */
void delay_cycles(s32 count) {
    do {
    } while (--count);
}



/* provisional name */
volatile u32* dma0_transfer_wait(u32 src, u32 dst, u32 count, u32 size) {
    *((volatile u32*)SH2_DMAOR);
    *((volatile u32*)SH2_DMAOR) = 0;
    *((volatile u32*)SH2_CHCR1);
    *((volatile u32*)SH2_CHCR1) = 0;
    *((volatile u32*)SH2_SAR0) = src;
    *((volatile u32*)SH2_DAR0) = dst;
    *((volatile u32*)SH2_TCR0) = count & 0xffffff;
    *((volatile u8*)SH2_DRCR0) = 0;
    *((volatile u32*)SH2_CHCR0);
    *((volatile u32*)SH2_CHCR0) = 0x5241 | ((size & 3) << 10);
    *((volatile u32*)SH2_DMAOR) = 1;
    while ((*((volatile u32*)SH2_CHCR0) & 2) == 0) {
    }
    *((volatile u32*)SH2_DMAOR);
    *((volatile u32*)SH2_DMAOR) = 0;
    return ((volatile u32*)SH2_DMAOR);
}
