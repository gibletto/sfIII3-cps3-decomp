#ifndef SOUND_VOICE_H
#define SOUND_VOICE_H

#include "structs.h"

u32 sound_envelope_rate(u32 level, u32 index, const u16* table);
void voice_process_null();
u32 voice_process_primary(SNDVOICE* voice, s8 is_bgm, u32 voice_index);

#endif
