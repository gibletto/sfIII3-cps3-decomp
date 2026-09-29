/*
 * COM_ALGO.C  Recorded lever input for demonstration play
 *
 * cpu_algorithm returns the next lever/button word from Demo_Ptr[id] and advances the
 * pointer. PLMAIN uses it as the input source when a player is driven by recorded data
 * (demo and combo demonstration play) instead of a joystick or the CPU logic.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Algo.h"



s32 cpu_algorithm(s16 id) {
    u16 lvr = *Demo_Ptr[id];
    Demo_Ptr[id]++;
    return lvr;
}
