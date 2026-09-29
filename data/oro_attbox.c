/*
 * ORO_ATTBOX.C  Oro's attack, catch and caught boxes
 *
 * Selected per animation frame through oro_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX oro_att_box[63] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  22,  82,  14 },  {  -49,  28,  48,  33 } } },  /* 1: no name, S PUNCH A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -85,   8,  51,  13 },  {  -77,  43,  54,   9 } } },  /* 2: S PUNCH B; attack 2 */
    { { {  -94,  23,  56,  15 },  {    0,   0,   0,   0 },  {  -71,  26,  58,  13 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH B; attack 18 */
    { { {  -91,  19,  59,  12 },  {    0,   0,   0,   0 },  {  -71,  26,  58,  13 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH B */
    { { {  -53,  21,  50,  14 },  {  -36,  21,  43,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A; attack 3 */
    { { {  -30,  17,  99,  33 },  {  -24,  14,  70,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A; attack 6 */
    { { {  -50,  15,  59,  22 },  {  -40,  14,  56,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH A; attack 7 */
    { { {  -74,  40,  12,  27 },  {  -33,  12,  29,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A; attack 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  14,  42,  34 },  {  -35,  19,  57,  36 } } },  /* 9: S KICK A; attack 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  10,  44,  18 },  {  -74,  57,  44,  12 } } },  /* 10: S KICK B; attack 10 */
    { { {  -42,  26,  37,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M KICK A, follow-up of S KICK A; attack 11, 89 */
    { { {  -90,  71,  57,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {  -79,  19,  62,  20 },  {  -60,  41,  62,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: L KICK A; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  43,  29,  13 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A; attack 15 */
    { { {  -88,  29,  47,  19 },  {  -67,  37,  37,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI P A; attack 16 */
    { { {  -76,  33,  56,  16 },  {  -43,  35,  45,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI P A */
    { { {  -47,  18,  74,  14 },  {  -30,  19,  62,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  28,   0,  10 },  {  -54,  37,   8,   9 } } },  /* 18: KAGAMI K A; attack 19 */
    { { {  -98,  67,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI K A; attack 53 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  20,  54,  14 },  {  -65,  28,  65,  13 } } },  /* 20: V JUMP P S A; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -54,  16,  55,  16 },  {  -38,  14,  49,  20 } } },  /* 21: V JUMP K S A; attack 22 */
    { { {  -65,  25,  56,  23 },  {  -44,  20,  45,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K M A; attack 23 */
    { { {  -91,  14,  49,  17 },  {  -75,  54,  49,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: V JUMP K L A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -69,  14,  42,  13 },  {  -54,  31,  47,  14 } } },  /* 24: F JUMP P S A; attack 25 */
    { { {  -69,  13,  35,  26 },  {  -56,  28,  42,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: F JUMP P M A; attack 26 */
    { { {  -44,  18,  14,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: F JUMP P L A; attack 27 */
    { { {  -45,  19,  85,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: F JUMP P L A; attack 28 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -42,  13,  24,  15 },  {    0,   0,   0,   0 } } },  /* 28: F JUMP K S A; attack 29 */
    { { {  -39,  24,  15,  19 },  {  -23,  28,  23,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: F JUMP K M A; attack 30 */
    { { {  -20,  14,   0,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI); attack 31, 61 */
    { { {  -92,  24,  44,  12 },  {  -71,  47,  44,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: not used by a script */
    { { { -107,  42,  50,  12 },  {  -67,  43,  52,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: not used by a script */
    { { {  -89,  42,  61,  12 },  {  -60,  43,  63,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: not used by a script */
    { { {  -62,  50,  26,  37 },  {  -54,  42,  12,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN); attack 39, 84 */
    { { {  -61,  60,  58,  35 },  {  -54,  28,  38,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1; attack 35, 37, 40, 85 */
    { { {  -29,  23, 108,  28 },  {  -44,  31,  82,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1; attack 36, 38, 40, 85 */
    { { {  -76,  32,  60,   8 },  {  -65,  36,  60,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -60,  12,  70,   8 },  {  -48,  11,  62,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -56,  10,  88,   8 },  {  -46,  10,  71,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -88,  13,  66,   7 },  {  -77,  14,  70,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { { -100,  18,  33,  15 },  {  -82,  13,  39,   9 },  {  -69,  26,  38,  11 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI P A; attack 52 */
    { { {  -90,  43,   0,  10 },  {  -54,  45,   8,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI K A; attack 20 */
    { { {  -96,  27,  48,  19 },  {  -79,  31,  58,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P M A; attack 54 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: no box */
    { { {  -29,  46,  99,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1; attack 41, 86 */
    { { {  -51,  33,  31,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: not used by a script */
    { { {  -41,  40,   0,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1; attack 67, 72, 74, 80 */
    { { {  -89,  73,  59,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: M KICK B; attack 12 */
    { { {  -83,  21,  65,  20 },  {  -60,  47,  68,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: not used by a script */
    { { { -100,  38,  70,  15 },  {  -60,  35,  77,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: V JUMP P L A; attack 55 */
    { { {  -88,  14,  40,  14 },  {  -73,  49,  39,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -50,  27,  30,  29 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 11 L: not started by a command; attack 69 */
    { { {  -28,  22,  -3,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI); attack 82, 83 */
    { { {  -41,  40,  -6,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1; attack 68, 73, 75, 80 ... */
    { { {  -91,  34,  71,  15 },  {  -56,  39,  72,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: M PUNCH C; attack 4 */
};

const CATCH_BOX oro_cat_box[10] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -48,   24,    0,   16 } },  /* 1: TUKAMIKAKARI A, TUKAMIKAKARI C */
    { {  -96,   62,    0,   16 } },  /* 2: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { {  -83,   56,    0,   16 } },  /* 3: follow-up of ZANNEN 2 */
    { {  -42,   20,   62,   29 } },  /* 4: TUKAMI AIR A */
    { {  -65,   42,   72,   22 } },  /* 5: follow-up of ZANNEN 7 */
    { {  -57,   28,    0,   16 } },  /* 6: follow-up of WIN 8 */
    { {  -69,   40,    0,   16 } },  /* 7: follow-up of SP WIN 1 */
    { {  -93,   64,    0,   16 } },  /* 8: ATTACK 9 S: after 6(123)4+P (plain script) */
    { {  -61,   37,    0,   16 } },  /* 9: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
};

const CAUGHT_BOX oro_cau_box[13] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +112 */
    { {  -43,   50,    0,   16 } },  /* 2: no name, P BREAK ZUJOU, TUKAMIHAZUSI +7 */
    { {  -28,   52,    0,    8 } },  /* 3: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +29 */
    { {  -23,   46,   39,   47 } },  /* 4: JUMP BACK, SP JUMP BACK, PARING AIR F +40 */
    { {  -25,   50,   31,   58 } },  /* 5: not used by a script */
    { {  -24,   48,    0,   16 } },  /* 6: M KICK B */
    { {  -23,   46,   39,   47 } },  /* 7: not used by a script */
    { {  -25,   50,   31,   58 } },  /* 8: not used by a script */
    { {  -21,   49,   22,   45 } },  /* 9: BODY SLAM, IPPONZEOI, TOMOE RYU +26 */
    { {  -24,   48,   28,   51 } },  /* 10: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { {  -32,   56,    0,    8 } },  /* 11: KAGAMI P A, KAGAMI K A */
    { {  -23,   46,   73,   47 } },  /* 12: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
};

