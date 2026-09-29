/*
 * CD_VOLUME.C  the CD-ROM's volume identifier (section CDVOL, 067FFFE0)
 *
 * The self test reads the CD's primary volume descriptor and compares its volume identifier with the
 * first 11 characters. The last word's use is not known: nothing in the program reads it.
 */

#include "types.h"

#pragma section CDVOL

const s8 game_volume_id[28] = "CAP-33S-1   ";
const u32 game_volume_word = 0xD19C;
