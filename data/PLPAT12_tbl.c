/*
 * PLPAT12_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_ABISEGERI();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HOMING_JUMP();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL12_BONUS_STAGE();
extern void Att_PL12_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl12_exatt_table[18])() = {
    Att_HADOUKEN,             Att_SHOURYUUREPPA,        Att_SLIDE_and_JUMP,       Att_ABISEGERI,  /* 0 */
    Att_CHOUCHUURENGEKI,      Att_SHOURYUUKEN,          Att_CHOUCHUURENGEKI,      Att_KUUCHUUNICHIRINSHOU,  /* 4 */
    Att_SENPUUKYAKU,          Att_HOMING_JUMP,          Att_DUMMY,                Att_DUMMY,  /* 8 */
    Att_DUMMY,                Att_DUMMY,                Att_PL12_TOKUSHUKOUDOU,   Att_PL12_BONUS_STAGE,  /* 12 */
    Att_METAMOR_WAIT,         Att_METAMOR_REBIRTH,  /* 16 */
};
