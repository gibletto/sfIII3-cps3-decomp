/*
 * vbl_hook.c  Empty vertical blank user hook
 *
 * Holds vblank_user_hook, an empty routine. The vertical blank interrupt handler in intr.src
 * calls it once per frame when bit 1 of the frame flag byte is set, giving a place for a
 * per-frame user callback; in this build it does nothing.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "vbl_hook.h"



/* provisional name */
void vblank_user_hook(void) {
}
