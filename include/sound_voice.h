#ifndef SOUND_VOICE_H
#define SOUND_VOICE_H

#include "structs.h"

u32 sound_envelope_rate(u32 level, u32 index, const u16* table);
s32 midi_vlq_decode_leading();
s32 midi_vlq_decode_while();
s32 sound_note_to_pitch(s32 note);
void sound_reg_write_verify(s16 *reg, s16 value);
u32 sound_voice_volume_compute(u16 level, u32 pan_scale, s8 pan, SOUND_VOICE* v);
void voice_process_null();
u32 voice_process_primary(SNDVOICE* voice, s8 is_bgm, u32 voice_index);
u32 voice_process_secondary(SNDVOICE* voice, u8 voice_index, u8 is_bgm);

#endif
