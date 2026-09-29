/*
 * SHELL07_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Shell07_0000();
extern void Shell07_0001();
extern void Shell07_0002();
extern void Shell07_0003();
extern void Shell07_0004();
extern void Shell07_0005();
extern void Shell07_0006();
extern void Shell07_0007();
extern void Shell07_0008();
extern void Shell07_0009();
extern void Shell07_0010();
extern void Shell07_0011();

void (*const Shell07_Tbl[12])() = {
    Shell07_0000,  Shell07_0001,  Shell07_0002,  Shell07_0003,  /* 0 */
    Shell07_0004,  Shell07_0005,  Shell07_0006,  Shell07_0007,  /* 4 */
    Shell07_0008,  Shell07_0009,  Shell07_0010,  Shell07_0011,  /* 8 */
};
