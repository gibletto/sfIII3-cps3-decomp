/*
 * SHELL03_TBL.C  CPU anti-projectile pattern table 03
 *
 * Shell03_Tbl lists the Shell03_nnnn pattern scripts run against a projectile by the
 * computer-controlled players 3, 6, 8, 9 and 10, indexed by Pattern_Index. Read by SHELL03.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Shell03_0000();
extern void Shell03_0001();
extern void Shell03_0002();
extern void Shell03_0003();
extern void Shell03_0004();
extern void Shell03_0005();
extern void Shell03_0006();
extern void Shell03_0007();
extern void Shell03_0008();
extern void Shell03_0009();
extern void Shell03_0010();

void (*const Shell03_Tbl[11])() = {
    Shell03_0000,  Shell03_0001,  Shell03_0002,  Shell03_0003,  /* 0 */
    Shell03_0004,  Shell03_0005,  Shell03_0006,  Shell03_0007,  /* 4 */
    Shell03_0008,  Shell03_0009,  Shell03_0010,  /* 8 */
};
