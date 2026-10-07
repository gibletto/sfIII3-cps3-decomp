/*
 * meta_col_mem.c  memset and strcat
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "meta_col_mem.h"
#include "cps3.h"



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
