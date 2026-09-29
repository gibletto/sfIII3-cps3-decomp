/*
 * PLPAT13_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_ABISEGERI();
extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_MOONSALT_KNEE_DROP2();
extern void Att_PL13_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

const s16 mnd_em_tall2[21][2] = {
    { 28, 56 }, { 24, 44 }, { 24, 40 }, { 20, 32 }, { 24, 48 }, { 24, 40 }, { 28, 60 }, { 16, 44 },
    { 32, 32 }, { 28, 24 }, { 20, 32 }, { 24, 40 }, { 24, 40 }, { 28, 56 }, { 24, 40 }, { 24, 40 },
    { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 },
};

const s16 glap_table2[6] = {
    1, 2, 3, 4, 0, 0,
};

void (*const pl13_exatt_table[18])() = {
    Att_HADOUKEN,             Att_MOONSALT_KNEE_DROP2,  Att_ABISEGERI,            Att_SENPUUKYAKU,  /* 0 */
    Att_CHOUCHUURENGEKI,      Att_CHOUCHUURENGEKI,      Att_HADOUKEN,             Att_CHOUCHUURENGEKI,  /* 4 */
    Att_SLIDE_and_JUMP,       Att_DUMMY,                Att_DUMMY,                Att_DUMMY,  /* 8 */
    Att_DUMMY,                Att_DUMMY,                Att_PL13_TOKUSHUKOUDOU,   Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,         Att_METAMOR_REBIRTH,  /* 16 */
};
