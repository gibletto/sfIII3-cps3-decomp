/*
 * PLPAT13_TBL.C  Urien's special attack tables
 *
 * pl13_exatt_table is the list of Urien's special attack routines, indexed by attack routine
 * number minus 16. mnd_em_tall2 gives, per opponent character, the x/y offset the knee-drop
 * special aims at; glap_table2 is the vitality refill rate per cg_type of the resurrection
 * move. Read by PLPAT13.C.
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
    { 28, 56 },  /* Gill */
    { 24, 44 },  /* Alex */
    { 24, 40 },  /* Ryu */
    { 20, 32 },  /* Yun */
    { 24, 48 },  /* Dudley */
    { 24, 40 },  /* Necro */
    { 28, 60 },  /* Hugo */
    { 16, 44 },  /* Ibuki */
    { 32, 32 },  /* Elena */
    { 28, 24 },  /* Oro */
    { 20, 32 },  /* Yang */
    { 24, 40 },  /* Ken */
    { 24, 40 },  /* Sean */
    { 28, 56 },  /* Urien */
    { 24, 40 },  /* Gouki */
    { 24, 40 },  /* Shin Gouki */
    { 24, 40 },  /* Chun-Li */
    { 24, 40 },  /* Makoto */
    { 24, 40 },  /* Q */
    { 24, 40 },  /* Twelve */
    { 24, 40 },  /* Remy */
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
