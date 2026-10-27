/*
 * PLPAT01_TBL.C  Alex special attack tables
 *
 * pl01_exatt_table is the special attack routines of character 1 (Alex) by attack routine
 * number; pl01_ddt_dat gives, by victim character, the DDT jump height and catch box. Read by
 * PLPAT01.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_HOMING_JUMP();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_NM_OKIAGARI();
extern void Att_PL01_DDT();
extern void Att_PL01_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SENPUUKYAKU2();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

const s16 pl01_ddt_dat[24][2] = {
    { 46, 11 },  /* Gill */
    { 32, 12 },  /* Alex */
    { 28, 13 },  /* Ryu */
    { 16, 14 },  /* Yun */
    { 36, 15 },  /* Dudley */
    { 16, 16 },  /* Necro */
    { 60, 17 },  /* Hugo */
    { 20, 18 },  /* Ibuki */
    { 24, 19 },  /* Elena */
    { 12, 20 },  /* Oro */
    { 16, 14 },  /* Yang */
    { 28, 13 },  /* Ken */
    { 28, 13 },  /* Sean */
    { 46, 11 },  /* Urien */
    { 28, 13 },  /* Gouki */
    { 28, 0 },  /* Shin Gouki */
    { 24, 21 },  /* Chun-Li */
    { 18, 22 },  /* Makoto */
    { 52, 23 },  /* Q */
    { 18, 16 },  /* Twelve */
    { 38, 24 },  /* Remy */
    { 16, 0 },  /* 21 */
    { 16, 0 },  /* 22 */
    { 16, 0 },  /* 23 */
};

void (*const pl01_exatt_table[18])() = {
    Att_CHOUCHUURENGEKI,     Att_SHOURYUUKEN,         Att_HADOUKEN,            Att_HADOUKEN2,  /* 0 */
    Att_CHOUCHUURENGEKI,     Att_SENPUUKYAKU2,        Att_SENPUUKYAKU,         Att_NM_OKIAGARI,  /* 4 */
    Att_PL01_DDT,            Att_HOMING_JUMP,         Att_SLIDE_and_JUMP,      Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL01_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};
