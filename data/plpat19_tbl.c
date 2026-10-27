/*
 * PLPAT19_TBL.C  Twelve's special attack tables
 *
 * pl19_exatt_table lists the routines of attack numbers 16 and up of character 19 (Twelve);
 * dra_em_tall gives, by opponent character, the x offset and height of the target point of
 * the EX D.R.A. dive. Read by PLPAT19.C.
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
    { 24, 16 },  /* Gill */
    { 28, 16 },  /* Alex */
    { 16, 16 },  /* Ryu */
    { 16, 16 },  /* Yun */
    { 20, 16 },  /* Dudley */
    { 20, 16 },  /* Necro */
    { 18, 16 },  /* Hugo */
    { 18, 16 },  /* Ibuki */
    { 28, 16 },  /* Elena */
    { 25, 16 },  /* Oro */
    { 16, 16 },  /* Yang */
    { 16, 16 },  /* Ken */
    { 16, 16 },  /* Sean */
    { 24, 16 },  /* Urien */
    { 16, 16 },  /* Gouki */
    { 16, 16 },  /* Shin Gouki */
    { 16, 16 },  /* Chun-Li */
    { 16, 16 },  /* Makoto */
    { 24, 16 },  /* Q */
    { 20, 16 },  /* Twelve */
    { 20, 16 },  /* Remy */
};

void (*const pl19_exatt_table[18])() = {
    Att_HADOUKEN,            Att_AIRDASH,             Att_KUUCHUUHISSATU,      Att_HADOUKEN,  /* 0 */
    Att_HADOUKEN,            Att_EX__D_R_A,           Att_METAMORPHOSE,        Att_AIR_A_X_E,  /* 4 */
    Att_HADOUKEN,            Att_JINNCHUUWATARI,      Att_SLIDE_and_JUMP,      Att_SA__D_R_A,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_pl19_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
