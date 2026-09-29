/*
 * PLPAT19_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_AIRDASH();
extern void Att_AIR_A_X_E();
extern void Att_DUMMY();
extern void Att_EX__D_R_A();
extern void Att_HADOUKEN();
extern void Att_JINNCHUUWATARI();
extern void Att_KUUCHUUHISSATU();
extern void Att_METAMORPHOSE();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_SA__D_R_A();
extern void Att_SLIDE_and_JUMP();
extern void Att_pl19_TOKUSHUKOUDOU();

const s16 dra_em_tall[24][2] = {
    { 24, 16 }, { 28, 16 }, { 16, 16 }, { 16, 16 }, { 20, 16 }, { 20, 16 }, { 18, 16 }, { 18, 16 },
    { 28, 16 }, { 25, 16 }, { 16, 16 }, { 16, 16 }, { 16, 16 }, { 24, 16 }, { 16, 16 }, { 16, 16 },
    { 16, 16 }, { 16, 16 }, { 24, 16 }, { 20, 16 },
    { 20, 16 },
};

void (*const pl19_exatt_table[18])() = {
    Att_HADOUKEN,            Att_AIRDASH,             Att_KUUCHUUHISSATU,      Att_HADOUKEN,  /* 0 */
    Att_HADOUKEN,            Att_EX__D_R_A,           Att_METAMORPHOSE,        Att_AIR_A_X_E,  /* 4 */
    Att_HADOUKEN,            Att_JINNCHUUWATARI,      Att_SLIDE_and_JUMP,      Att_SA__D_R_A,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_pl19_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
