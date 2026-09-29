/*
 * PLPAT14_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL14_AT1();
extern void Att_PL14_AT2();
extern void Att_PL14_AT3();
extern void Att_PL14_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

const s16 pl14_HYAKKI_dat[24] = {
    4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 7, 6, 6, 4, 6, 6,
    14, 15, 16, 17,
    18,
};

void (*const pl14_exatt_table[18])() = {
    Att_HADOUKEN,               Att_SHOURYUUKEN,            Att_SENPUUKYAKU,            Att_KUUCHUUJINNCHUUWATARI,  /* 0 */
    Att_SHOURYUUREPPA,          Att_SLIDE_and_JUMP,         Att_KUUCHUUNICHIRINSHOU,    Att_PL14_AT1,  /* 4 */
    Att_CHOUCHUURENGEKI,        Att_PL14_AT2,               Att_HADOUKEN,               Att_PL14_AT3,  /* 8 */
    Att_DUMMY,                  Att_DUMMY,                  Att_PL14_TOKUSHUKOUDOU,     Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,           Att_METAMOR_REBIRTH,  /* 16 */
};
