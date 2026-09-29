/*
 * PLPAT00_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_JYOUKA();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_MOONSALT_KNEE_DROP();
extern void Att_PL00_TOKUSHUKOUDOU();
extern void Att_RESURRECTION();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

const s16 mnd_em_tall[21][2] = {
    { 28, 56 }, { 24, 44 }, { 24, 40 }, { 20, 32 }, { 24, 48 }, { 24, 40 }, { 28, 60 }, { 16, 44 },
    { 32, 32 }, { 28, 24 }, { 20, 32 }, { 24, 40 }, { 24, 40 }, { 28, 56 }, { 24, 40 }, { 24, 40 },
    { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 }, { 24, 40 },
};

const s16 glap_table[5] = {
    1, 2, 3, 4, 0,
};

void (*const pl00_exatt_table[18])() = {
    Att_HADOUKEN,            Att_MOONSALT_KNEE_DROP,  Att_SLIDE_and_JUMP,      Att_SENPUUKYAKU,  /* 0 */
    Att_HADOUKEN,            Att_RESURRECTION,        Att_JYOUKA,              Att_DUMMY,  /* 4 */
    Att_DUMMY,               Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL00_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
