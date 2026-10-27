/*
 * PLPAT00_TBL.C  Gill special attack tables
 *
 * pl00_exatt_table is the special attack routines of character 0 (Gill) by attack routine
 * number; mnd_em_tall gives, by opponent character, the { x, y } target of the moonsault knee
 * drop; glap_table the vitality gained per frame step of the resurrection. Read by PLPAT00.C.
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
