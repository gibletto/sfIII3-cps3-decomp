/*
 * PLPAT08_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL08_HEALING();
extern void Att_PL08_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

const u8 pl08_hcs_tbl[8] = {
    0, 0, 0, 1, 0, 1, 1, 1,
};

void (*const pl08_exatt_table[18])() = {
    Att_SHOURYUUKEN,         Att_SENPUUKYAKU,         Att_SENPUUKYAKU,         Att_SHOURYUUREPPA,  /* 0 */
    Att_SHOURYUUREPPA,       Att_PL08_HEALING,        Att_DUMMY,               Att_SLIDE_and_JUMP,  /* 4 */
    Att_HADOUKEN,            Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL08_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
