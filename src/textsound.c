/*
 * textsound.c  Text layer printing, sprite DMA copies and the sound driver interface
 *
 * Text layer routines used by test mode, menus and messages: tilemap_chunk_copy_16b loads font
 * characters, tilemap_fill_all / rectfill / rect_fill clear areas, and the print routines
 * put characters, strings (with attribute), script sequences and signed decimal, raw and binary
 * numbers. palette_bank_set and palette_write copy rows of data (such as palettes) through
 * the sprite DMA, and tilemap_fill_column0 empties the sprite buffer. Sound driver interface:
 * sound_driver_init, sound_request / sound_seq_start start a sound or music sequence on the BGM
 * or sound-effect voices, and the sound_reg_* and voice_* routines trigger, set levels, read
 * status, mute and fade. sound_driver_tick, called from the vertical blank interrupt, runs the
 * master fade and then processes all 16 BGM and 16 effect voices through sound_voice.c. Small
 * library helpers close the file: memcmp, strlen, delay_cycles and dma0_transfer_wait (SH-2 on-chip
 * DMA channel 0).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
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
    s16 row;
    s16 col;
    s16 ret = 42;
    u16 bank;
    u16 v;
    if (attr == 0xFFFF && code == 0xFFFF) {
        return ret;
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
void tilemap_print_hex(x, y, attr, value, digits, mode)
u16 x;
u16 y;
u16 attr;
u32 value;
u16 digits;
u16 mode;
{
    TEXT_CELL* p;
    s32 n;
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


/* provisional name */
void bgm_tempo_set(s8 tempo) {
    bgm_tempo_add = tempo * 3;
}



/* provisional name */
s32 sound_driver_version(void)
{
  return (s32)((s16)(341));
}

/* provisional name */
void sound_sample_bank_set(u16 bank)
{
    snd_wave_bias = bank;
}



/* provisional name */
void sound_init(u8* data, SNDSAMPLE* bank_a, u8** bank_b, u8 stereo, u8 volume, u8 flag) {
    u16 init[21] = {
        3, 1, 3, 1, 3, 1, 3, 0, 2, 1, 3, 0, 2, 0, 2, 0, 2, 2, 6, 6, 2
    };
    u16* p;
    s32 n;
    volatile u16* reg;
    SNDVOICE* v;
    u8* q;
    snd_attack_ptr = snd_attack_rate_tbl;
    snd_decay_ptr = snd_decay_rate_tbl;
    snd_lfo_rate_ptr = snd_lfo_rate_tbl;
    snd_pitch_lfo_ptr = snd_pitch_lfo_tbl;
    snd_vol_lfo_ptr = snd_vol_lfo_tbl;
    snd_sample_tbl = bank_a;
    snd_bank_tbl = bank_b;
    snd_stereo = flag;
    for (p = init; p < &init[21]; p++) {
        *(volatile u16*)(EXT_SW + 0x202) = *p;
        n = 0x100;
        while (n--) {
        }
    }
    reg = (volatile u16*)SOUND_REG;
    for (n = 0x100; n != 0; n--) {
        *reg++ = 0;
    }
    snd_ctrl.w.hi = (volume << 8) | (stereo & 1) | 0x22;
    *(volatile u32*)(SOUND_REG + 0x210) = snd_ctrl.l;
    *(volatile u16*)(SOUND_REG + 0x200) = 0;
    snd_seq_data = (u32*)data;
    snd_seq_max = *data++;
    snd_seq_max <<= 8;
    snd_seq_max += *data++;
    bgm_master_vol = *data++;
    bgm_master_vol_init = bgm_master_vol;
    snd_master_vol = *data;
    sound_sample_submit_work7 = 1;
    voice_state_init_pair_work = 0;
    sound_sample_submit_work4 = 0;
    snd_fade_level = 0;
    snd_fade_speed = 0;
    bgm_tempo_add = 0;
    q = bgm_status_save;
    for (v = bgm_voice; v < &bgm_voice[16]; v++) {
        v->status = 0xC0;
        *q++ = 0xC0;
    }
    for (v = se_voice; v < &se_voice[16]; v++) {
        v->status = 0xC0;
    }
    for (q = (*(u8(*)[16])&gSeqStatus[0]); q < &(*(u8(*)[16])&gSeqStatus[0])[16]; q++) {
        *q = 0;
    }
}



/* provisional name */
s32 sound_request(s32 code) {
    return ((s32(*)(s32 code, s32 ramp))sound_seq_start)(code, -1);
}



/* provisional name */
void sound_seq_start(u16 code, s16 ramp) {
    u8* seq;
    u8* p;
    u8* track;
    u8* bank;
    SNDVOICE* v;
    SNDVOICE* mv;
    SNDRAMP* rec;
    u32 ofs;
    s32 ticks;
    s32 n;
    u16 off;
    u8 hdr;
    u8 ch;
    u8 i;
    for (;;) {
        if (code < snd_seq_max) {
            break;
        }
        code -= snd_seq_max;
    }
    ofs = snd_seq_data[code + 1];
    if (ofs == 0) {
        return;
    }
    seq = (u8*)snd_seq_data + ofs;
    p = seq;
    hdr = *p++;
    if (hdr == 0) {
        bgm_stop();
        mv = bgm_voice;
        v = bgm_voice;
        for (i = 0; i < 16; i++, mv++, v++) {
            off = *p++ << 8;
            off += *p++;
            if (off == 0) {
                mv->status = 0xC0;
            } else {
                track = seq + off;
                v->origin = track;
                n = midi_vlq_decode_while(track, &ticks);
                ticks <<= 8;
                v->event_ticks = ticks;
                v->cursor = track + n;
                v->status = 0x20;
                bank = *snd_bank_tbl;
                v->patch = (SNDPATCH*)(bank + *(u16*)bank);
                v->sample = &snd_sample_tbl[v->patch->sample_index];
                v->note_ticks = 0;
                v->decoded_pitch = 0;
                v->target_pitch = 0;
                v->current_pitch = 0;
                v->pitch_lfo = 0;
                v->volume_lfo = 0;
                v->pitch_lfo_depth = 0;
                v->volume_lfo_depth = 0;
                v->lfo_rate = 0;
                v->envelope_level = 0;
                v->saved_portamento_step = 0;
                v->portamento_step = 0;
                v->program_index = 0;
                v->attack_peak = 0;
                v->attack_rate = 0;
                v->sustain_level = 0;
                v->decay_rate = 0;
                v->release_rate = 0;
                v->forced_release_rate = 0;
                v->loop_count[0] = 0;
                v->loop_count[1] = 0;
                v->loop_count[2] = 0;
                v->loop_count[3] = 0;
                v->loop_latch = 0;
                v->envelope_phase = 0;
                v->lfo_phase_flags = 0;
                v->priority_flags = hdr;
                v->volume = 0;
                v->velocity = 0;
                v->expression = 0x40;
                v->fine_tune = 0;
                v->transpose = 0;
                v->coarse_pitch_bend = 0;
                v->fine_pitch_control = 0x40;
                v->key_on_pending = 0;
                v->duration_enabled = 0;
                v->note_event_pending = 0;
                v->tie = 0;
                v->release_pending = 0;
                v->restart_pending = 0;
                v->pan_override = 0x40;
                v->control_70 = 0;
            }
        }
        if (!(sound_sample_submit_work7 & 8)) {
            snd_fade_level = 0x8000;
        }
        bgm_tempo_add = 0;
        bgm_tick_step = 0;
        sound_sample_submit_work7 |= 2;
        return;
    }
    if (!(hdr & 0x80)) {
        for (i = 0; i < 16; i++) {
            off = *p++ << 8;
            off += *p++;
            if (off != 0) {
                if (hdr >= SE_VOICE(i).priority_flags || (SE_VOICE(i).status & 0x80)) {
                    track = seq + off;
                    n = midi_vlq_decode_while(track, &ticks);
                    ticks <<= 8;
                    SE_VOICE(i).event_ticks = ticks;
                    SE_VOICE(i).cursor = track + n;
                    SE_VOICE(i).status = 0;
                    bank = *snd_bank_tbl;
                    SE_VOICE(i).patch = (SNDPATCH*)(bank + *(u16*)bank);
                    SE_VOICE(i).sample = &snd_sample_tbl[SE_VOICE(i).patch->sample_index];
                    SE_VOICE(i).decoded_pitch = 0;
                    SE_VOICE(i).target_pitch = 0;
                    SE_VOICE(i).current_pitch = 0;
                    SE_VOICE(i).pitch_lfo = 0;
                    SE_VOICE(i).volume_lfo = 0;
                    SE_VOICE(i).pitch_lfo_depth = 0;
                    SE_VOICE(i).volume_lfo_depth = 0;
                    SE_VOICE(i).lfo_rate = 0;
                    SE_VOICE(i).envelope_level = 0;
                    SE_VOICE(i).saved_portamento_step = 0;
                    SE_VOICE(i).portamento_step = 0;
                    SE_VOICE(i).program_index = 0;
                    SE_VOICE(i).attack_peak = 0;
                    SE_VOICE(i).attack_rate = 0;
                    SE_VOICE(i).sustain_level = 0;
                    SE_VOICE(i).decay_rate = 0;
                    SE_VOICE(i).release_rate = 0;
                    SE_VOICE(i).forced_release_rate = 0;
                    SE_VOICE(i).loop_count[0] = 0;
                    SE_VOICE(i).loop_count[1] = 0;
                    SE_VOICE(i).loop_count[2] = 0;
                    SE_VOICE(i).loop_count[3] = 0;
                    SE_VOICE(i).loop_latch = 0;
                    SE_VOICE(i).envelope_phase = 0;
                    SE_VOICE(i).pan_override = 0x40;
                    SE_VOICE(i).lfo_phase_flags = 0;
                    SE_VOICE(i).priority_flags = hdr;
                    SE_VOICE(i).volume = 0;
                    bgm_voice[i].velocity = 0x7F;
                    SE_VOICE(i).expression = 0x7F;
                    SE_VOICE(i).fine_tune = 0;
                    SE_VOICE(i).transpose = 0;
                    SE_VOICE(i).coarse_pitch_bend = 0;
                    SE_VOICE(i).fine_pitch_control = 0x40;
                    SE_VOICE(i).key_on_pending = 0;
                    SE_VOICE(i).duration_enabled = 0;
                    SE_VOICE(i).note_event_pending = 0;
                    SE_VOICE(i).tie = 0;
                    SE_VOICE(i).release_pending = 0;
                    SE_VOICE(i).pan_override = 0x40;
                    SE_VOICE(i).control_70 = 0;
                    rec = &se_pan_ramp[i];
                    if (ramp != -1) {
                        rec->current = se_ramp_req.current;
                        rec->target = se_ramp_req.target;
                        rec->step = se_ramp_req.step;
                        rec->mode = se_ramp_req.mode;
                    } else {
                        rec->current = 0;
                        rec->target = 0;
                        rec->step = 0;
                        rec->mode = -1;
                    }
                    se_tick_step[i] = 0;
                }
            }
        }
        return;
    }
    ch = hdr & 15;
    v = &se_voice[ch];
    if ((*p & 0x7F) < (v->priority_flags & 0x7F) && !(v->status & 0x80)) {
        return;
    }
    v->cursor = p;
    bank = *snd_bank_tbl;
    v->patch = (SNDPATCH*)(bank + *(u16*)bank);
    v->sample = &snd_sample_tbl[v->patch->sample_index];
    v->envelope_level = 0;
    v->program_index = 0;
    v->attack_peak = 0;
    v->attack_rate = 0;
    v->sustain_level = 0;
    v->decay_rate = 0;
    v->release_rate = 0;
    v->forced_release_rate = 0;
    v->volume = 0;
    v->velocity = 0x7F;
    v->expression = 0x7F;
    v->fine_tune = 0;
    v->transpose = 0;
    v->coarse_pitch_bend = 0;
    v->fine_pitch_control = 0x40;
    v->priority_flags = *p | 0x80;
    v->pan_override = 0x40;
    rec = &se_pan_ramp[ch];
    if (ramp != -1) {
        rec->current = se_ramp_req.current;
        rec->target = se_ramp_req.target;
        rec->step = se_ramp_req.step;
        rec->mode = se_ramp_req.mode;
    } else {
        rec->current = 0;
        rec->target = 0;
        rec->step = 0;
        rec->mode = -1;
    }
    se_voice[ch].status = 0;
}



/* provisional name */
void sound_request_pan(u16 code, s16 vol_l, s16 vol_r, s16 time, s16 ramp) {
    if (vol_l < 0) {
        vol_l = 0;
    } else if (vol_l > 127) {
        vol_l = 127;
    }
    if (vol_r < 0) {
        vol_r = 0;
    } else if (vol_r > 127) {
        vol_r = 127;
    }
    se_ramp_req.current = vol_l << 8;
    se_ramp_req.target = vol_r << 8;
    se_ramp_req.step = (se_ramp_req.target - se_ramp_req.current) / time;
    se_ramp_req.mode = ramp;
    sound_seq_start(code, ramp);
}



/* provisional name */
void bgm_stop(void) {
    u8 i;
    if (!(sound_sample_submit_work7 & 2)) {
        return;
    }
    for (i = 0; i < 16; i++) {
        bgm_voice[i].status = 192;
    }
    sound_sample_submit_work7 = 1;
    snd_reg_save = 0;
}



/* provisional name */
void bgm_pause(void) {
    u8* save = bgm_status_save;
    u8 i;
    if (!(sound_sample_submit_work7 & 2)) {
        return;
    }
    if (sound_sample_submit_work7 & 4) {
        return;
    }
    snd_reg_save = *(u16*)(SOUND_REG + 0x200);
    for (i = 0; i < 16; i++) {
        save[i] = bgm_voice[i].status;
        bgm_voice[i].status = 192;
    }
    sound_sample_submit_work7 |= 4;
}

/* provisional name */
u32 sound_fade_in_submit(u32 code_no, u16 speed)
{
    snd_fade_level = 0;
    snd_fade_speed = speed & 0x7FFF;
    sound_sample_submit_work7 |= 8;
    return ((s32 (*)())sound_seq_start)(code_no, -1);
}



/* provisional name */
void bgm_fade_out(cmd)
u16 cmd;
{
    if (sound_sample_submit_work7 & 2) {
        snd_fade_speed = cmd & 0x7FFF;
        sound_sample_submit_work7 &= 0xF7;
        sound_sample_submit_work7 |= 16;
    }
}



/* provisional name */
void sound_reg_level_set(level, flag)
s16 level;
s8 flag;
{
    voice_state_init_pair_work = level;
    sound_sample_submit_work4 = flag;
}



/* provisional name */
s8 sound_status_read(void) {
    return sound_sample_submit_work7;
}



/* provisional name */
void sound_driver_init(void) {
    u8 i;
    for (i = 0; i < 16; i++) {
        bgm_voice[i].status = 192;
        se_voice[i].status = 192;
        se_voice[i].priority_flags = 0;
    }
    sound_sample_submit_work7 = 1;
    *(u16*)(SOUND_REG + 0x200) = 0;
    snd_reg_save = 0;
}



/* provisional name */
void se_voice_stop(u8 ch) {
    se_voice[ch].status = 192;
    se_voice[ch].priority_flags = 0;
}



/* provisional name */
void se_voice_stop_all(void) {
    u8 i;
    for (i = 0; i < 16; i++) {
        se_voice[i].status = 192;
        se_voice[i].priority_flags = 0;
    }
}



/* provisional name */
void sound_driver_tick(void) {
    u32 i;
    if ((sound_sample_submit_work7 & 8) && !(sound_sample_submit_work7 & 4)) {
        snd_fade_level += snd_fade_speed;
        if (snd_fade_level >= 0x8000) {
            snd_fade_level = 0x8000;
            sound_sample_submit_work7 &= ~8;
        }
    }
    if ((sound_sample_submit_work7 & 0x10) && !(sound_sample_submit_work7 & 4)) {
        if (snd_fade_speed >= snd_fade_level) {
            bgm_stop();
            snd_fade_level = 0;
            sound_sample_submit_work7 &= ~0x10;
        } else {
            snd_fade_level -= snd_fade_speed;
        }
    }
    for (i = 0; i < 16; i++) {
        voice_process_primary(&bgm_voice[i], 1, i);
    }
    for (i = 0; i < 16; i++) {
        if (se_voice[i].priority_flags & 0x80) {
            voice_process_null(&se_voice[i], i);
        } else {
            voice_process_primary(&se_voice[i], 0, i);
        }
    }
    for (i = 0; i < 16; i++) {
        voice_process_secondary(&bgm_voice[i], i, 1);
    }
    for (i = 0; i < 16; i++) {
        if (!(se_voice[i].priority_flags & 0x80)) {
            voice_process_secondary(&SE_VOICE(i), i, 0);
        }
    }
}



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
