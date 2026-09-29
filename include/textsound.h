#ifndef TEXTSOUND_H
#define TEXTSOUND_H

#include "structs.h"

void tilemap_put_char(u16 x, u16 y, u16 attr, u16 code);
s32 tilemap_rect_fill(u16 x, u16 y, u16 w, u16 h, u16 attr, u16 code);
s32 sound_request(s32 code);
s32 memcmp(const u8* a, const u8* b, u32 n);
volatile u32* dma0_transfer_wait(u32 src, u32 dst, u32 count, u32 size);
void sound_init(u8* data, SNDSAMPLE* bank_a, u8** bank_b, u8 stereo, u8 volume, u8 flag);
void delay_cycles(s32 count);
void sound_request_pan(u16 code, s16 vol_l, s16 vol_r, s16 time, s16 ramp);
void sound_driver_init(void);
void sound_driver_tick(void);
void sound_reg_level_set();
s8 sound_status_read(void);
void bgm_fade_out();
void sound_seq_start(u16 code, s16 ramp);
u32 sound_fade_in_submit(u32 code_no, u16 speed);
void bgm_pause(void);
void tilemap_fill_column0(u16 attr, u16 code);
u32 palette_write(s32 offset, u16 *src, s32 count);
void palette_bank_set(s32 offset);
s32 strlen(const char *s);
u16* tilemap_put_block_next(u16* p, u16 attr, u16 code);
void tilemap_put_block();
void tilemap_fill_all(u16 attr, u16 code);
void tilemap_chunk_copy_16b(s16 *dst, char *src, s32 chunks);
void tilemap_print_binary(u16 x, u16 y, u16 attr, const s8* data, u16 n);
void tilemap_print_script_seq(u16 x, u16 y, u16 pal, const TMSCRIPT* scr);
void tilemap_print_hex_block(u16 x, u16 y, u16 attr, u32 value, u16 digits, u16 mode);
void tilemap_print_hex();
void tilemap_print_string(u16 x, u16 y, u16 attr, const TM_STRING* sc);
void tilemap_print_string_attr(u16 x, u16 y, u16 attr, const s8* str);
s32 sound_driver_version(void);
void sound_sample_bank_set(u16 bank);
void bgm_stop(void);
void se_voice_stop(u8 ch);
void se_voice_stop_all(void);

#endif
