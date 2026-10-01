/*
 * sound_voice.c  Sound driver voice sequencer
 *
 * The per-voice core of the sound driver, called every tick from the driver tick in textsound.c
 * for each of the 16 BGM voices and 16 sound-effect voices. voice_process_primary reads the
 * voice's event stream: note events look up the instrument patch for the note in the current
 * bank, set the sample and pitch and compute the attack, decay and release rates
 * (sound_envelope_rate); control events change program, volume, pan, tempo, loops and ties.
 * voice_process_secondary counts down the event and note times, runs the envelope and pan
 * automation, works out pitch (sound_note_to_pitch) and volume (sound_voice_volume_compute) and
 * writes the result to that voice's sound chip registers, handling key-on/key-off. A BGM voice
 * only reaches the hardware while no sound effect holds the same channel. midi_vlq_decode_*
 * decode variable-length delta times from the sequence data.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice.h"
#include "cps3.h"
/* provisional name */
u32 sound_envelope_rate(u32 level, u32 index, const u16* table)
{
    u32 rate;

    rate = (table[index & 0xFF] + 1) * (level & 0xFFFF) >> 16;
    if (rate != 0) {
        return rate;
    }
    return 1;
}



/* provisional name */
void voice_process_null(void)
{
  return;
}



/* provisional name */
u32 voice_process_primary(SNDVOICE* voice, s8 is_bgm, u32 voice_index) {
    u8* cursor;
    u8* argument;
    u8 event;
    u8 slot;
    u8 voice_status = voice->status;
    u16 note;
    u16 event_mask = 0x80;
    u32 loop_index;
    s32 consumed;
    s32 ticks;
    s32 relative;
    SNDPATCH* patch;
    SNDVOICE* paired_bgm_voice;
    SNDRAMP* automation;
    u32* sfx_ticks;
    u32* bgm_ticks;
    if (voice_status & 0x60) {
        return voice_status;
    }
    slot = (u8)voice_index;
    paired_bgm_voice = &bgm_voice[slot];
    automation = &se_pan_ramp[slot];
    sfx_ticks = &se_tick_step[slot];
    bgm_ticks = &bgm_tick_step;
    do {
        cursor = voice->cursor;
        event = *cursor;
        argument = cursor + 1;
        if (event < 0xC0) {
            u8** bank;
            s32 note_resolved = 1;
            voice->velocity = (u8)((event & 0x3f) << 1);
            note = (u16)(*argument & 0x7f);
            voice->control_70 = (u8)note;
            bank = &snd_bank_tbl[voice->instrument_bank];
            if (*bank == 0) {
                note_resolved = 0;
            } else if (((u16*)*bank)[voice->program_index] == 0) {
                note_resolved = 0;
            } else {
                patch = (SNDPATCH*)(((u16*)*bank)[voice->program_index] + *bank);
                for (;;) {
                    if (patch->note_ceiling == -1) {
                        patch = 0;
                        break;
                    }
                    if ((s16)note <= patch->note_ceiling) {
                        break;
                    }
                    patch++;
                }
                if (!patch) {
                    note_resolved = 0;
                } else {
                    ((volatile SNDVOICE*)voice)->patch = patch;
                    ((volatile SNDVOICE*)voice)->sample = snd_sample_tbl;
                    ((volatile SNDVOICE*)voice)->decoded_pitch = (s16)(((note - (((volatile SNDVOICE*)voice)->sample += ((volatile SNDVOICE*)voice)->patch->sample_index & 0x7FFF)->base_pitch + ((volatile SNDVOICE*)voice)->transpose + 7) << 8) +
                                              event_mask + ((volatile SNDVOICE*)voice)->patch->pitch_bias);
                    ((volatile SNDVOICE*)voice)->attack_peak = ((volatile SNDVOICE*)voice)->velocity << 8;
                    ((volatile SNDVOICE*)voice)->sustain_level = (u32)((((volatile SNDVOICE*)voice)->patch->velocity_scale + 1) * ((volatile SNDVOICE*)voice)->attack_peak) >> 7;
                    ((volatile SNDVOICE*)voice)->attack_rate = sound_envelope_rate(((volatile SNDVOICE*)voice)->attack_peak, ((volatile SNDVOICE*)voice)->patch->attack_curve, snd_attack_ptr);
                    ((volatile SNDVOICE*)voice)->attack_rate = (u32)((((volatile SNDVOICE*)voice)->velocity + 1) * ((volatile SNDVOICE*)voice)->attack_rate) >> 7;
                    ((volatile SNDVOICE*)voice)->decay_rate = sound_envelope_rate(((volatile SNDVOICE*)voice)->attack_peak, ((volatile SNDVOICE*)voice)->patch->decay_curve, snd_decay_ptr);
                    ((volatile SNDVOICE*)voice)->release_rate = sound_envelope_rate(((volatile SNDVOICE*)voice)->sustain_level, ((volatile SNDVOICE*)voice)->patch->release_curve, snd_decay_ptr);
                    voice->note_event_pending = 1;
                }
            }
            if (!note_resolved) {
                voice->note_event_pending = 0;
                voice->duration_enabled = 0;
                voice->key_on_pending = 0;
                voice->tie = 0;
            } else {
                voice->key_on_pending = voice->tie ? 0 : 1;
                if ((event_mask & *argument) == 0) {
                    voice->duration_enabled = 1;
                    voice->tie = 0;
                } else {
                    voice->duration_enabled = 0;
                    voice->tie = 1;
                }
            }
            cursor += 2;
            consumed = midi_vlq_decode_leading(cursor, &ticks);
            ticks <<= 8;
            voice->note_ticks = ticks;
            argument = cursor + consumed;
            goto decode_event_ticks;
        }
        switch (event - 0xC0) {
        case 0:
            break;
        case 1:
            if (!is_bgm) {
                *sfx_ticks = (u32)*argument << 8;
                argument = cursor + 3;
                *sfx_ticks += cursor[2];
            } else {
                *bgm_ticks = (u32)*argument << 8;
                argument = cursor + 3;
                *bgm_ticks += cursor[2];
            }
            break;
        case 2:
            voice->instrument_bank = *argument & 0x0f;
            argument = cursor + 2;
            break;
        case 3:
            voice->coarse_pitch_bend = (s8)*argument;
            argument = cursor + 2;
            break;
        case 4:
            voice->program_index = *argument & 0x7f;
            argument = cursor + 2;
            break;
        case 5:
            voice->pitch_lfo_depth = snd_pitch_lfo_ptr[*argument];
            argument = cursor + 2;
            break;
        case 6:
            voice->volume = *argument;
            argument = cursor + 2;
            break;
        case 7:
            voice->pan_override = *argument;
            argument = cursor + 2;
            break;
        case 8:
            voice->expression = *argument;
            argument = cursor + 2;
            break;
        case 9:
            voice->saved_portamento_step = voice->portamento_step;
            event = *argument;
            argument = cursor + 2;
            if (event != 0) {
                voice->portamento_step = (u16)((event + 1) * 2);
                voice->saved_portamento_step = voice->portamento_step;
            } else {
                voice->status &= (u8)~0x02;
                voice->portamento_step = 0;
            }
            break;
        case 10:
            if (!voice->loop_latch) {
                argument = voice->origin;
                voice->loop_latch = 1;
            }
            break;
        case 0x0b:
            if (voice->loop_latch) {
                voice->status |= 0x40;
                return 0x5e;
            }
            break;
        case 0x0c:
            if (!voice->loop_latch) {
                relative = (s8)*argument * 0x100 + cursor[2] + 2;
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument = cursor + 3;
            }
            break;
        case 0x0d:
            if (voice->loop_latch) {
                event = *argument;
                argument = cursor + 3;
                relative = (s8)event * 0x100 + (s8)cursor[2];
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument = cursor + 3;
            }
            break;
        case 0x0e:
            relative = (s8)*argument++;     /* the offset is read a byte at a time: it can sit at an odd address */
            relative <<= 8;
            relative |= *argument++;
            argument += relative;
            break;
        case 0x0f:
            argument = bgm_voice[(u16)*argument].origin;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            voice->loop_cursor[event - 0xd0] = argument;
            break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            loop_index = event - 0xd4;
            if (!voice->loop_count[loop_index]) {
                voice->loop_count[loop_index] = *argument;
            } else {
                voice->loop_count[loop_index]--;
                if (!voice->loop_count[loop_index]) {
                    argument = cursor + 2;
                    break;
                }
            }
            argument = voice->loop_cursor[loop_index];
            break;
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
            loop_index = event - 0xd8;
            if (voice->loop_count[loop_index] == 1) {
                voice->loop_count[loop_index] = 0;
                relative = (u32)*argument * 0x100 + cursor[2];
                cursor += 3;
                argument = cursor + relative;
            } else {
                argument = cursor + 3;
            }
            break;
        case 0x1c:
            voice->transpose = (s8)*argument;
            argument = cursor + 2;
            break;
        case 0x1d:
            voice->transpose += (s8)*argument;
            argument = cursor + 2;
            break;
        case 0x1e:
            voice->fine_tune = (s8)*argument;
            argument = cursor + 2;
            break;
        case 0x1f:
            voice->fine_tune += (s8)*argument;
            argument = cursor + 2;
            break;
        case 0x20:
            if (*argument == 0) {
                voice->status &= (u8)~0x01;
            } else {
                voice->status |= 0x01;
            }
            argument = cursor + 2;
            break;
        case 0x21:
            voice->lfo_rate = snd_lfo_rate_ptr[*argument];
            argument = cursor + 2;
            break;
        case 0x22:
            voice->volume_lfo_depth = snd_vol_lfo_ptr[*argument];
            argument = cursor + 2;
            break;
        case 0x23:
            voice->priority_flags = *argument;
            argument = cursor + 2;
            break;
        case 0x24:
        case 0x25:
            argument = cursor + 3;
            break;
        case 0x26:
            argument = cursor + 2;
            break;
        case 0x27:
            voice->fine_pitch_control = (s8)*argument;
            argument = cursor + 2;
            break;
        case 0x28:
            event = *argument;
            argument = cursor + 3;
            (*(u8(*)[])&gSeqStatus[0])[event] = cursor[2];
            break;
        default:
            break;
        case 0x3f:
            voice->status |= 0x40;
            if (!is_bgm && !(paired_bgm_voice->status & 0x80)) {
                paired_bgm_voice->restart_pending = 1;
                if (!(paired_bgm_voice->patch->sample_index & 0x8000)) {
                    paired_bgm_voice->envelope_level = 0;
                    paired_bgm_voice->envelope_phase = 0;
                }
            }
            automation->mode = -1;
            return 0xffffffff;
        }
decode_event_ticks:
        consumed = midi_vlq_decode_while(argument, &ticks);
        ticks *= 0x100;
        voice->event_ticks += ticks;
        voice->cursor = argument + consumed;
    } while (ticks <= 0);
    voice->status |= 0x20;
    return 0x5e;
}



/* provisional name */
s32 sound_note_to_pitch(s32 note) {
    s8 oct = 0;
    s32 pitch;
    while (note >= 3072) {
        note -= 3072;
        oct++;
    }
    while (note < 0) {
        note += 3072;
        oct--;
    }
    pitch = snd_pitch_tbl[note] + 1;
    while (oct > 0) {
        pitch <<= 1;
        oct--;
    }
    while (oct < 0) {
        pitch = (u16)pitch >> 1;
        oct++;
    }
    return pitch - 1;
}



/* provisional name */
u32 sound_voice_volume_compute(u16 level, u32 pan_scale, s8 pan, SOUND_VOICE* v) {
    volatile s32 a;
    s32 t;
    u32 vol;
    u16 out;
    s32 comp;
    SOUND_CTRL ctrl;
    a = v->velocity * ((vol = v->volume) ? vol + 1 : vol) * 2;
    a = (a * ((v->expression + 64) & 127)) >> 6;
    a = (a * ((v->track[2] + 64) & 127)) >> 6;
    t = (a * ((snd_master_vol + 64) & 127)) >> 6;
    if (!v->no_master) {
        t = (t * ((bgm_master_vol + 64) & 127)) >> 6;
    }
    out = (level * (t + 1)) >> 15;
    if (pan == -128) {
        t = 0;
    } else {
        t = (s16)((out * pan_scale) >> 16) + (pan << 8) + out;
    }
    if (t > 0x7FFF) {
        out = 0x7FFF;
    } else if (t < 0) {
        out = 0;
    } else {
        out = t;
    }
    ctrl = snd_ctrl;
    if ((u8)ctrl.b[1] & 1) {
        if (!v->no_master) {
            t = (out * (u16)((u32)snd_fade_level >> 8)) >> 7;
            return t;
        }
        return out;
    }
    if (out <= 0x1000) {
        comp = out << 2;
    } else if (out <= 0x2000) {
        comp = (out << 1) + 0x2000;
    } else if (out <= 0x4000) {
        comp = (out >> 1) + 0x5000;
    } else {
        comp = (out >> 2) + 0x6000;
    }
    if (comp >= 0x8000) {
        comp = 0x7FFF;
    }
    return comp << 1;
}



/* provisional name */
u32 voice_process_secondary(SNDVOICE* voice, u8 voice_index, u8 is_bgm) {
    s32 owns_hardware_voice = 1;
    volatile SNDREGS* regs;
    u32 result;
    s32 status;
    s32 next;
    u32 depth;
    s32 step;
    s32 pan;
    s8 output_pan;
    u16 key_clear_mask;
    s8 key_state_changed = 0;
    SNDRAMP* ramp;
    if (is_bgm && !(se_voice[voice_index].status & 0x80)) {
        owns_hardware_voice = 0;
    }
    regs = &((volatile SNDREGS*)SOUND_REG)[voice_index];
    key_clear_mask = (u16)~(u16)(1u << voice_index);
    status = voice->status;
    if (status & 0x80) {
        if (is_bgm && owns_hardware_voice) {
            snd_key_on_reg &= key_clear_mask;
        }
        return status;
    }
    if (is_bgm) {
        voice->event_ticks -= bgm_tick_step + bgm_tempo_add;
    } else {
        voice->event_ticks -= se_tick_step[voice_index];
    }
    if (voice->duration_enabled) {
        if (is_bgm) {
            voice->note_ticks -= bgm_tick_step + bgm_tempo_add;
        } else {
            voice->note_ticks -= se_tick_step[voice_index];
        }
    }
    if (voice->event_ticks <= 0) {
        voice->status &= 0xdf;
    }
    if (voice->note_ticks <= 0 && voice->duration_enabled) {
        voice->duration_enabled = 0;
        voice->release_pending = 0;
        if (owns_hardware_voice) {
            sound_reg_write_verify(
                (volatile s16*)&regs->sample_loop_enable, 0);
        }
        if (voice->envelope_phase != 4) {
            voice->envelope_phase = 4;
            voice->forced_release_rate =
                (u16)sound_envelope_rate(voice->envelope_level,
                                   (u8)voice->patch->forced_release_curve,
                                   snd_decay_ptr);
        }
    }
    if (voice->note_event_pending) {
        voice->note_event_pending = 0;
        voice->current_pitch = voice->target_pitch;
        voice->target_pitch = voice->decoded_pitch;
        if (!voice->key_on_pending) {
            if (!voice->portamento_step) {
                voice->status &= 0xfd;
                voice->current_pitch = voice->target_pitch;
            } else {
                voice->status |= 0x02;
            }
            voice->envelope_phase = 3;
        } else {
            voice->key_on_pending = 0;
            voice->release_pending = 1;
            voice->envelope_level = 0;
            if (owns_hardware_voice) {
                snd_key_on_reg &= key_clear_mask;
                do { u32 bias; s16 loop_on; sound_reg_write_verify((volatile s16*)&(regs)->sample_control, 0); bias = snd_wave_bias; sound_reg_write_verify((volatile s16*)&(regs)->sample_start_low, (u16)(voice->sample)->start); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_high, (u16)((voice->sample)->start >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_low, (u16)(voice->sample)->loop); sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_high, (u16)((voice->sample)->loop >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_low_a, (u16)(voice->sample)->end); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_low_b, (u16)(voice->sample)->end); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_high_a, (u16)((voice->sample)->end >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_high_b, (u16)((voice->sample)->end >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_control, 0); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_low, (u16)(voice->sample)->start); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_high, (u16)((voice->sample)->start >> 16) + bias); if ((voice->sample)->loop == (voice->sample)->end) { loop_on = 0; } else { loop_on = 1; } sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_enable, loop_on); } while (0);
            }
            if (!voice->portamento_step) {
                voice->status &= 0xfd;
                voice->current_pitch = voice->target_pitch;
            } else {
                voice->status |= 0x02;
            }
            voice->envelope_phase = 1;
            if (voice->status & 0x01) {
                voice->lfo_phase_flags &= 0xfc;
                voice->pitch_lfo = 0;
                voice->volume_lfo = 0;
            }
        }
        key_state_changed = 1;
    }
    if (is_bgm && voice->restart_pending && owns_hardware_voice) {
        voice->restart_pending = 0;
        snd_key_on_reg &= key_clear_mask;
        do { u32 bias; s16 loop_on; sound_reg_write_verify((volatile s16*)&(regs)->sample_control, 0); bias = snd_wave_bias; sound_reg_write_verify((volatile s16*)&(regs)->sample_start_low, (u16)(voice->sample)->start); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_high, (u16)((voice->sample)->start >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_low, (u16)(voice->sample)->loop); sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_high, (u16)((voice->sample)->loop >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_low_a, (u16)(voice->sample)->end); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_low_b, (u16)(voice->sample)->end); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_high_a, (u16)((voice->sample)->end >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_end_high_b, (u16)((voice->sample)->end >> 16) + bias); sound_reg_write_verify((volatile s16*)&(regs)->sample_control, 0); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_low, (u16)(voice->sample)->start); sound_reg_write_verify((volatile s16*)&(regs)->sample_start_high, (u16)((voice->sample)->start >> 16) + bias); if ((voice->sample)->loop == (voice->sample)->end) { loop_on = 0; } else { loop_on = 1; } sound_reg_write_verify((volatile s16*)&(regs)->sample_loop_enable, loop_on); } while (0);
        key_state_changed = 1;
    }
    if (voice->status & 0x40) {
        if (!voice->envelope_level) {
            voice->status |= 0x80;
            voice->priority_flags = 0;
            return 0x6f;
        }
        voice->envelope_phase = 4;
        if (owns_hardware_voice) {
            sound_reg_write_verify(
                (volatile s16*)&regs->sample_loop_enable, 0);
        }
    }
    if ((voice->status & 0x02) &&
        voice->current_pitch != voice->target_pitch) {
        if (voice->target_pitch < voice->current_pitch) {
            next = voice->current_pitch - voice->portamento_step;
            voice->current_pitch = next;
            if (next <= voice->target_pitch) {
                voice->current_pitch = voice->target_pitch;
            }
        } else {
            next = voice->current_pitch + voice->portamento_step;
            voice->current_pitch = next;
            if (voice->target_pitch <= next) {
                voice->current_pitch = voice->target_pitch;
            }
        }
    }
    switch (voice->envelope_phase) {
    case 0:
        break;
    case 1:
        result = (u32)voice->envelope_level + voice->attack_rate;
        if (result < voice->attack_peak) {
            voice->envelope_level = (u16)result;
        } else {
            voice->envelope_level = voice->attack_peak;
            voice->envelope_phase = 2;
        }
        break;
    case 2:
        if ((u32)voice->sustain_level + voice->decay_rate <
            voice->envelope_level) {
            voice->envelope_level -= voice->decay_rate;
        } else {
            voice->envelope_level = voice->sustain_level;
            voice->envelope_phase = 3;
        }
        break;
    case 3: {
        u32 rate = voice->release_rate;
        u32 level = voice->envelope_level;
        if (level > rate) {
            voice->envelope_level = (u16)(level - rate);
        } else {
            voice->envelope_level = 0;
            voice->envelope_phase = 0;
        }
        break;
    }
    case 4: {
        u32 rate = voice->forced_release_rate;
        u32 level = voice->envelope_level;
        if (level > rate) {
            voice->envelope_level = (u16)(level - rate);
        } else {
            voice->envelope_level = 0;
            voice->envelope_phase = 0;
            if (is_bgm && owns_hardware_voice) {
                snd_key_on_reg &= key_clear_mask;
            }
        }
        break;
    }
    }
    if (voice->lfo_rate) {
        if (voice->pitch_lfo_depth) {
            depth = voice->pitch_lfo_depth;
            step = (s32)(depth * voice->lfo_rate);
            if (!(voice->lfo_phase_flags & 0x01)) {
                if (voice->pitch_lfo < (s32)(depth * 0x10000 - step)) {
                    voice->pitch_lfo += step;
                } else {
                    voice->pitch_lfo = (s32)(depth * 0x10000);
                    voice->lfo_phase_flags |= 0x01;
                }
            } else if ((s32)(step - depth * 0x10000) < voice->pitch_lfo) {
                voice->pitch_lfo -= step;
            } else {
                voice->pitch_lfo = -(s32)(depth * 0x10000);
                voice->lfo_phase_flags &= 0xfe;
            }
        }
        result = 0;
        if (voice->volume_lfo_depth) {
            depth = voice->volume_lfo_depth;
            step = (s16)((depth * voice->lfo_rate) >> 16);
            if (!(voice->lfo_phase_flags & 0x02)) {
                if (voice->volume_lfo < (s32)(depth - step)) {
                    voice->volume_lfo += step;
                } else {
                    voice->volume_lfo = (s32)depth;
                    result = 0x6e;
                    voice->lfo_phase_flags |= 0x02;
                }
            } else if ((s32)(step - depth) < voice->volume_lfo) {
                voice->volume_lfo -= step;
            } else {
                result = 0x6e;
                voice->volume_lfo = -(s32)depth;
                voice->lfo_phase_flags &= 0xfd;
            }
        }
    } else {
        voice->pitch_lfo = 0;
        voice->volume_lfo = 0;
        result = 0x40;
    }
    ramp = &se_pan_ramp[voice_index];
    if (!is_bgm && ramp->mode != -1 && ramp->mode != 0) {
        next = se_pan_ramp[voice_index].current + se_pan_ramp[voice_index].step;
        if (se_pan_ramp[voice_index].step < 0) {
            if (se_pan_ramp[voice_index].target < next) {
                se_pan_ramp[voice_index].current = (s16)next;
            } else {
                se_pan_ramp[voice_index].current = se_pan_ramp[voice_index].target;
                if (se_pan_ramp[voice_index].mode == 1) {
                    se_voice[voice_index].status |= 0x40;
                }
                se_pan_ramp[voice_index].mode = 0;
                result = 0;
            }
        } else if (next < se_pan_ramp[voice_index].target) {
            se_pan_ramp[voice_index].current = (s16)next;
        } else {
            se_pan_ramp[voice_index].current = se_pan_ramp[voice_index].target;
            if (se_pan_ramp[voice_index].mode == 1) {
                se_voice[voice_index].status |= 0x40;
            }
            se_pan_ramp[voice_index].mode = 0;
            result = 0;
        }
    }
    if (!owns_hardware_voice) {
        return result;
    }
    output_pan = ((u8)sound_sample_submit_work4);
    if (!snd_stereo) {
        if (is_bgm) {
            regs->volume_right = (u16)sound_voice_volume_compute(
                voice->envelope_level, voice->volume_lfo, output_pan, voice);
            regs->volume_left = (u16)sound_voice_volume_compute(
                voice->envelope_level, voice->volume_lfo,
                ((u8)sound_sample_submit_work4), voice);
        } else {
            regs->volume_left = (u16)sound_voice_volume_compute(
                voice->envelope_level, voice->volume_lfo, 0, voice);
            regs->volume_right = (u16)sound_voice_volume_compute(
                voice->envelope_level, voice->volume_lfo, 0, voice);
        }
    } else {
        if (!is_bgm && se_pan_ramp[voice_index].mode != -1) {
            pan = (u8)(se_pan_ramp[voice_index].current >> 8);
        } else {
            pan = voice->patch->pan;
            if (pan == 0xff) {
                pan = voice->pan_override;
            }
        }
        result = (0x7f - pan) & 0xffff;
        if (is_bgm) {
            if (pan > 0x3f) {
                regs->volume_left = (u16)sound_voice_volume_compute(
                    (result * voice->envelope_level) >> 6,
                    voice->volume_lfo, output_pan, voice);
                regs->volume_right = (u16)sound_voice_volume_compute(
                    voice->envelope_level, voice->volume_lfo,
                    ((u8)sound_sample_submit_work4), voice);
            } else {
                regs->volume_right = (u16)sound_voice_volume_compute(
                    (pan * voice->envelope_level) >> 6,
                    voice->volume_lfo, output_pan, voice);
                regs->volume_left = (u16)sound_voice_volume_compute(
                    voice->envelope_level, voice->volume_lfo,
                    ((u8)sound_sample_submit_work4), voice);
            }
        } else {
            if (pan > 0x3f) {
                regs->volume_left = (u16)sound_voice_volume_compute(
                    (result * voice->envelope_level) >> 6,
                    voice->volume_lfo, 0, voice);
                regs->volume_right = (u16)sound_voice_volume_compute(
                    voice->envelope_level, voice->volume_lfo, 0, voice);
            } else {
                regs->volume_right = (u16)sound_voice_volume_compute(
                    (pan * voice->envelope_level) >> 6,
                    voice->volume_lfo, 0, voice);
                regs->volume_left = (u16)sound_voice_volume_compute(
                    voice->envelope_level, voice->volume_lfo, 0, voice);
            }
        }
    }
    if (is_bgm) {
        regs->pitch = (u16)sound_note_to_pitch(
            (s16)((u32)voice->pitch_lfo >> 16) + voice->current_pitch +
            ((voice->coarse_pitch_bend * 0xc00) >> 7) +
            (((voice->fine_pitch_control - 0x40) * 0x100) >> 6) +
            voice_state_init_pair_work);
    } else {
        regs->pitch = (u16)sound_note_to_pitch(
            (s16)((u32)voice->pitch_lfo >> 16) + voice->current_pitch +
            ((voice->coarse_pitch_bend * 0xc00) >> 7) +
            (((voice->fine_pitch_control - 0x40) * 0x100) >> 6));
    }
    if (key_state_changed && owns_hardware_voice) {
        result = 1;
        result <<= voice_index;
        snd_key_on_reg |= (u16)result;
        return result;
    }
    return key_state_changed;
}

/* provisional name */
void sound_reg_write_verify(s16 *reg, s16 value)
{
    *reg = value;
    while ((u16)value != *(volatile u16 *)reg) {
        *reg = value;
    }
}



/* provisional name */
s32 midi_vlq_decode_while(p, out)
u8* p;
u32* out;
{
    u8* start = p;
    u32 val = 0;
    while (!(*p & 0x80)) {
        val = (val << 7) + *p++;
    }
    *out = val;
    return p - start;
}



/* provisional name */
s32 midi_vlq_decode_leading(p, out)
u8* p;
u32* out;
{
    u8* start = p;
    u32 val;
    val = *p++;
    if (val & 0x80) {
        val &= 0x7F;
        do {
            val = (val << 7) + (*p & 0x7F);
        } while (*p++ & 0x80);
    }
    *out = val;
    return p - start;
}
