#ifndef META_COL_H
#define META_COL_H

#include "structs.h"

void metamor_color_trans(s16 wkid, s16 plnum);
void metamor_color_copy(s16 wkid);
void metamor_color_reset(s16 wkid);
u32 hex_to_bcd(u32 dat);
u8 abcd(u8 a, u8 b);
void metamor_color_store(s16 pl);
u8 *memset(u8 *dst, u8 c, u32 n);
char * strcpy(char* dst, const char* src);
char * strstr(char* s, const char* sub);
u8 sbcd(u8 a, u8 b);
u8* strcat(u8* dst, u8* src);

#endif
