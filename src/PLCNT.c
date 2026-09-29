/*
 * PLCNT.C  Player control reset helpers
 *
 * All_Clear_Suicide clears the eight Suicide (effect kill) flags; it is used when screens and
 * fights start (Manage, next_cpu, sel_pl, Win).
 * clear_chainex_check clears a player's chain-combo check table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLCNT.h"



void All_Clear_Suicide(void) {
    s16 i;
    for (i = 0; i < 8; i++) {
        Suicide[i] = 0;
    }
}



void clear_chainex_check(s16 ix) {
    s16 i;
    for (i = 0; i <= 20; i++) {
        Break_Com[ix][i] = 0;
    }
}
