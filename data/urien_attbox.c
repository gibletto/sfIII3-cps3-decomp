/*
 * URIEN_ATTBOX.C  Urien's attack, catch and caught boxes
 *
 * Selected per animation frame through urien_hit_ix_table (atix, caix, cuix). A box is x, width,
 * y, height from the character's position, x mirrored when facing left; width 0 means no box.
 *
 * att_box  four boxes per entry: the attack boxes the hit check tests against the opponent's
 *          damage boxes, the last two also standing in as damage boxes while attacking
 * cat_box  the reach of a throw: the opponent's caught box must overlap it
 * cau_box  where this character can be thrown from
 *
 * Row comments: the moves whose frames use the box (debug viewer names) and, for att_box, the
 * catt_table attacks dealt through it (rows of the fighter's _attr.c). Row 0 is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const ATTACK_BOX urien_att_box[55] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  26,  74,  16 },  {  -66,  26,  82,  12 } } },  /* 1: S PUNCH A; attack 1 */
    { { {  -56,  36,  92,  24 },  {  -76,  32, 104,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: not used by a script */
    { { {  -76,  32, 104,  24 },  {  -56,  36,  92,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: not used by a script */
    { { {  -56,  22, 104,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -68,  36,  56,  38 },  {  -84,  40,  36,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A; attack 5 */
    { { {  -90,  24,  44,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A, follow-up of M PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  32,  10,  14 },  {  -62,  30,  22,  12 } } },  /* 7: S KICK A; attack 6 */
    { { { -118,  28,  70,  12 },  {  -89,  54,  66,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { { -112,  24,  70,  12 },  {  -89,  54,  66,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M KICK A; attack 8 */
    { { {  -66,  20,  38,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -45,  21, 106,  15 },  {  -49,  22,  80,  26 } } },  /* 11: KAGAMI P A, no name; attack 14, 50 */
    { { { -104,  54,  50,  18 },  {  -80,  80,  68,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  20,  46,  16 },  {  -66,  20,  38,  16 } } },  /* 13: KAGAMI P A; attack 12, 13 */
    { { {  -52,  28,  60,  20 },  {  -44,  24,  42,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A, no name; attack 28, 49 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -97,  66,   0,  12 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A; attack 15 */
    { { {  -78,  22,  61,  18 },  {  -62,  22,  53,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -56,  22,  68,  12 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P S A; attack 18 */
    { { {  -92,  24,  86,  14 },  {  -74,  24,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  20,  58,  16 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP K S A; attack 29 */
    { { {  -50,  24,  71,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { { -104,  86,  80,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP K M A; attack 30 */
    { { {  -94,  56,  80,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K M A, ATTACK 4 M: not started by a command; attack 20 */
    { { { -107,  32,  50,  16 },  {  -81,  52,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: V JUMP K L A; attack 31 */
    { { { -108,  40,  52,  16 },  {  -74,  44,  60,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: not used by a script */
    { { {  -89,  56,  55,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: follow-up of APPEAR JUNBI 6 */
    { { {  -30,  56,  54,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -36,  56,  40,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { { -120,  56,  42,  22 },  {  -84,  84,  64,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -38,  44,  46,  20 },  {  -18,  30,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 24, 47 */
    { { {  -54,  28,  62,  22 },  {  -38,  22,  54,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2); attack 48 */
    { { {  -33,  12,  56,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 32, 41 */
    { { {  -78,  50,  56,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 33, 42 */
    { { {  -74,  26,  68,  20 },  {  -69,  24,  77,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU); attack 26, 52, 53 */
    { { { -104,  40,  66,  22 },  {  -70,  42,  78,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -94,  30,  72,  16 },  {  -70,  30,  78,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: M PUNCH A, follow-up of S PUNCH A; attack 3, 51 */
    { { {  -66,  34, 102,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L KICK A; attack 9 */
    { { { -113,  68,  64,  26 },  {  -91,  52,  88,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L KICK A; attack 10 */
    { { {  -87,  36,  12,  28 },  {  -92,  32,  32,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK A */
    { { { -107,  76,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: KAGAMI K A; attack 16 */
    { { { -116,  84,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI K A; attack 17 */
    { { { -110,  22,  76,  16 },  {  -88,  48,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP P M A; attack 19 */
    { { {  -88,  28,  70,  24 },  {  -76,  24,  88,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P L A; attack 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  38,  31,  30 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command; attack 34 */
    { { {  -45,  17,  52,  34 },  {  -38,  11,  32,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI); attack 39, 40 */
    { { { -112,  22,  61,  15 },  {  -90,  53,  58,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: M KICK C; attack 38 */
    { { {  -64, 128,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 8 SP: not started by a command; attack 46 */
    { { {  -30,  14,  50,  28 },  {  -23,  10,  32,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1; attack 35, 36, 37, 43 ... */
    { { {  -76,  28,  66,  20 },  {  -69,  24,  78,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU); attack 45, 56 */
    { { {  -84,  22,  23,  20 },  {  -73,  18,  35,  16 },  {  -63,  18,  46,  14 },  {  -53,  27,  51,  12 } } },  /* 51: L PUNCH C, follow-up of M PUNCH C; attack 54, 55 */
    { { { -101,  28, 103,  19 },  {    0,   0,   0,   0 },  {  -88,  24,  93,  19 },  {  -75,  40,  84,  18 } } },  /* 52: M PUNCH C; attack 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  19, 106,  13 },  {  -45,  19,  89,  17 } } },  /* 53: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -66,  20,  38,  16 } } },  /* 54: KAGAMI P A */
};

const CATCH_BOX urien_cat_box[2] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -50,   26,    0,   16 } },  /* 1: TUKAMIKAKARI A */
};

const CAUGHT_BOX urien_cau_box[9] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +101 */
    { {  -28,   52,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +43 */
    { {  -24,   48,   56,   56 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP P L A +29 */
    { {  -24,   48,    0,   16 } },  /* 4: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    { {  -32,   56,    0,    8 } },  /* 5: KAGAMI P A, KAGAMI K A */
    { {  -32,   64,    0,   16 } },  /* 6: DASH HUMIKOMI, no name */
    { {  -23,   48,   34,   58 } },  /* 7: BODY SLAM, TOMOE RYU, MONKEY FLIP +24 */
    { {  -43,   52,   52,   59 } },  /* 8: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
};

