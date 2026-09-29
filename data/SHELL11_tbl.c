/*
 * SHELL11_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Shell11_0000();
extern void Shell11_0001();
extern void Shell11_0002();
extern void Shell11_0003();
extern void Shell11_0004();
extern void Shell11_0005();
extern void Shell11_0006();
extern void Shell11_0007();
extern void Shell11_0008();
extern void Shell11_0009();
extern void Shell11_0010();
extern void Shell11_0011();
extern void Shell11_0012();
extern void Shell11_0013();

void (*const Shell11_Tbl[14])() = {
    Shell11_0000,  Shell11_0001,  Shell11_0002,  Shell11_0003,  /* 0 */
    Shell11_0004,  Shell11_0005,  Shell11_0006,  Shell11_0007,  /* 4 */
    Shell11_0008,  Shell11_0009,  Shell11_0010,  Shell11_0011,  /* 8 */
    Shell11_0012,  Shell11_0013,  /* 12 */
};
