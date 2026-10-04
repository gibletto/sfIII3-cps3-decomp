/*
 * TEXTSOUND_2.C  Text layer printing, sprite DMA copies and the sound driver interface (part 2)
 *
 * Sound driver interface: sound_driver_init, sound_request / sound_seq_start start a sound or music
 * sequence on the BGM or sound-effect voices, and the sound_reg_* and voice_* routines trigger, set
 * levels, read status, mute and fade. sound_driver_tick, called from the vertical blank interrupt,
 * runs the master fade and then processes all 16 BGM and 16 effect voices through sound_voice.c.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
#include "sound_voice_2.h"
#include "textsound_2.h"
#include "cps3.h"



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
void bgm_resume(void) {
    u8 i;
    if (!(sound_sample_submit_work7 & 2)) {
        return;
    }
    if (!(sound_sample_submit_work7 & 4)) {
        return;
    }
    for (i = 0; i < 16; i++) {
        bgm_voice[i].status = bgm_status_save[i];
    }
    sound_sample_submit_work7 &= ~4;
    *(u16*)(SOUND_REG + 0x200) |= snd_reg_save;
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
u8 sound_status_read(void) {
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
