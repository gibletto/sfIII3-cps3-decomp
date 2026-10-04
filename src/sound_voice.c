/*
 * SOUND_VOICE.C  Sound driver voice sequencer
 *
 * The per-voice core of the sound driver, called every tick from the driver tick in textsound.c for
 * each of the 16 BGM voices and 16 sound-effect voices. voice_process_primary reads the voice's
 * event stream: note events look up the instrument patch for the note in the current bank, set the
 * sample and pitch and compute the attack, decay and release rates (sound_envelope_rate); control
 * events change program, volume, pan, tempo, loops and ties. voice_process_secondary counts down the
 * event and note times, runs the envelope and pan automation, works out pitch (sound_note_to_pitch)
 * and volume (sound_voice_volume_compute) and writes the result to that voice's sound chip
 * registers, handling key-on/key-off. A BGM voice only reaches the hardware while no sound effect
 * holds the same channel. midi_vlq_decode_* decode variable-length delta times from the sequence
 * data.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sound_voice_2.h"
#include "sound_voice.h"
#include "cps3.h"
/* provisional name */
u32 sound_envelope_rate(u32 level, u32 index, const u16* table) {
    u32 rate;

    table += (u8)index;
    rate = (u32)((u16)level * (*table + 1)) >> 16;
    if (rate) {
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
    u8 voice_status = voice->status;
    u8* argument;
    u8 event;
    u8 loop_index;
    u16 note;
    u32 event_mask = 0x80;
    s32 note_resolved;
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
    paired_bgm_voice = &bgm_voice[(u8)voice_index];
    automation = &se_pan_ramp[(u8)voice_index];
    sfx_ticks = &se_tick_step[(u8)voice_index];
    bgm_ticks = &bgm_tick_step;
next_event:
    argument = voice->cursor;
    event = *argument++;
    if (event >= 0xC0) {
        switch (event - 0xC0) {
        case 0:
            break;
        case 1:
            if (is_bgm) {
                *bgm_ticks = *argument++ << 8;
                *bgm_ticks += *argument++;
            } else {
                *sfx_ticks = *argument++ << 8;
                *sfx_ticks += *argument++;
            }
            break;
        case 2:
            voice->instrument_bank = *argument++ & 0x0f;
            break;
        case 3:
            voice->coarse_pitch_bend = *argument++;
            break;
        case 0x27:
            voice->fine_pitch_control = *argument++;
            break;
        case 0x28:
            event = *argument++;
            (*(u8(*)[])&gSeqStatus[0])[event] = *argument++;
            break;
        case 4:
            voice->program_index = *argument++ & 0x7f;
            break;
        case 5:
            voice->pitch_lfo_depth = snd_pitch_lfo_ptr[*argument++];
            break;
        case 6:
            voice->volume = *argument++;
            break;
        case 7:
            voice->pan_override = *argument++;
            break;
        case 8:
            voice->expression = *argument++;
            break;
        case 9:
            voice->saved_portamento_step = voice->portamento_step;
            event = *argument++;
            if (event != 0) {
                voice->portamento_step = (event + 1) * 2;
                voice->saved_portamento_step = voice->portamento_step;
            } else {
                voice->status &= ~0x02;
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
                relative = (s8)argument[0] * 0x100 + argument[1] + 2;
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument += 2;
            }
            break;
        case 0x0d:
            if (voice->loop_latch) {
                relative = (s8)*argument++ * 0x100;
                relative += (s8)*argument++;
                argument += relative;
                voice->loop_latch = 1;
            } else {
                argument += 2;
            }
            break;
        case 0x0e:
            relative = (s8)*argument++;
            relative <<= 8;
            relative |= *argument++;
            argument += relative;
            break;
        case 0x0f:
            argument = bgm_voice[*argument].origin;
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
            if (voice->loop_count[loop_index]) {
                voice->loop_count[loop_index]--;
                if (!voice->loop_count[loop_index]) {
                    argument++;
                    break;
                }
            } else {
                voice->loop_count[loop_index] = *argument;
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
                relative = (argument[0] << 8) + argument[1];
                argument += 2;
                argument += relative;
            } else {
                argument += 2;
            }
            break;
        case 0x1c:
            voice->transpose = (s8)*argument++;
            break;
        case 0x1d:
            voice->transpose += (s8)*argument++;
            break;
        case 0x1e:
            voice->fine_tune = (s8)*argument++;
            break;
        case 0x1f:
            voice->fine_tune += (s8)*argument++;
            break;
        case 0x20:
            if (*argument++) {
                voice->status |= 0x01;
            } else {
                voice->status &= ~0x01;
            }
            break;
        case 0x21:
            voice->lfo_rate = snd_lfo_rate_ptr[*argument++];
            break;
        case 0x22:
            voice->volume_lfo_depth = snd_vol_lfo_ptr[*argument++];
            break;
        case 0x23:
            voice->priority_flags = *argument++;
            break;
        case 0x24:
        case 0x25:
            argument += 2;
            break;
        case 0x26:
            argument++;
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
        default:
            break;
        }
    } else {
        u8** bank;
        note_resolved = 1;
        voice->velocity = (event & 0x3f) << 1;
        note = *argument & 0x7f;
        voice->control_70 = note;
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
                voice->patch = patch;
                voice->sample = snd_sample_tbl;
                voice->decoded_pitch = (s16)(((note - (voice->sample += voice->patch->sample_index & 0x7FFF)->base_pitch + voice->transpose + 7) << 8) + event_mask + voice->patch->pitch_bias);
                voice->attack_peak = voice->velocity << 8;
                voice->sustain_level = ((voice->patch->velocity_scale + 1) * voice->attack_peak) >> 7;
                voice->attack_rate = sound_envelope_rate(voice->attack_peak, voice->patch->attack_curve, snd_attack_ptr);
                voice->attack_rate = ((voice->velocity + 1) * voice->attack_rate) >> 7;
                voice->decay_rate = sound_envelope_rate(voice->attack_peak, voice->patch->decay_curve, snd_decay_ptr);
                voice->release_rate = sound_envelope_rate(voice->sustain_level, voice->patch->release_curve, snd_decay_ptr);
                voice->note_event_pending = 1;
            }
        }
        if (note_resolved) {
            voice->key_on_pending = voice->tie ? 0 : 1;
            if (!(*argument++ & event_mask)) {
                voice->duration_enabled = 1;
                voice->tie = 0;
            } else {
                voice->duration_enabled = 0;
                voice->tie = 1;
            }
        } else {
            argument++;
            voice->note_event_pending = 0;
            voice->duration_enabled = 0;
            voice->key_on_pending = 0;
            voice->tie = 0;
        }
        consumed = midi_vlq_decode_leading(argument, &ticks);
        ticks <<= 8;
        voice->note_ticks = ticks;
        argument += consumed;
    }
    consumed = midi_vlq_decode_while(argument, &ticks);
    ticks <<= 8;
    voice->event_ticks += ticks;
    argument += consumed;
    voice->cursor = argument;
    if (ticks <= 0) {
        goto next_event;
    }
    voice->status |= 0x20;
    return 0x5e;
}



