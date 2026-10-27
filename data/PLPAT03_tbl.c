/*
 * PLPAT03_TBL.C  Yun special attack table
 *
 * pl03_exatt_table is the special attack routines of character 3 (Yun) by attack routine
 * number. Read by PLPAT03.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL03_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

void (*const pl03_exatt_table[18])() = {
    Att_HADOUKEN,            Att_SHOURYUUKEN,         Att_SENPUUKYAKU,         Att_HADOUKEN,  /* 0 */
    Att_SLIDE_and_JUMP,      Att_SLIDE_and_JUMP,      Att_HADOUKEN,            Att_DUMMY,  /* 4 */
    Att_SLIDE_and_JUMP,      Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL03_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
