/*
 * SHELL12_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Shell12_0000();
extern void Shell12_0001();
extern void Shell12_0002();
extern void Shell12_0003();
extern void Shell12_0004();
extern void Shell12_0005();
extern void Shell12_0006();
extern void Shell12_0007();
extern void Shell12_0008();
extern void Shell12_0009();
extern void Shell12_0010();

void (*const Shell12_Tbl[11])() = {
    Shell12_0000,  Shell12_0001,  Shell12_0002,  Shell12_0003,  /* 0 */
    Shell12_0004,  Shell12_0005,  Shell12_0006,  Shell12_0007,  /* 4 */
    Shell12_0008,  Shell12_0009,  Shell12_0010,  /* 8 */
};
