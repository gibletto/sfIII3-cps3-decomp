/*
 * PLPAT02_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DENJINHADOUKEN();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL02_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHINSHOURYUUKEN();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

const s16 lgix_table[8] = {
    0, 1, 2, 3, 3, 4, 4, 5,
};

void (*const pl02_exatt_table[18])() = {
    Att_HADOUKEN,             Att_SHOURYUUKEN,          Att_SENPUUKYAKU,          Att_HADOUKEN,  /* 0 */
    Att_SHINSHOURYUUKEN,      Att_DENJINHADOUKEN,       Att_KUUCHUUNICHIRINSHOU,  Att_SLIDE_and_JUMP,  /* 4 */
    Att_DUMMY,                Att_DUMMY,                Att_DUMMY,                Att_DUMMY,  /* 8 */
    Att_DUMMY,                Att_DUMMY,                Att_PL02_TOKUSHUKOUDOU,   Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,         Att_METAMOR_REBIRTH,  /* 16 */
};
