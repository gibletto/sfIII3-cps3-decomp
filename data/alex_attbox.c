/*
 * ALEX_ATTBOX.C  Alex's attack, catch and caught boxes
 *
 * Selected per animation frame through alex_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX alex_att_box[78] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  20,  47,  26 },  {  -56,  23,  43,  30 } } },  /* 1: S PUNCH A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  19,  74,  15 },  {  -67,  38,  72,  17 } } },  /* 2: S PUNCH B; attack 2 */
    { { {  -82,  21,  72,  26 },  {  -62,  25,  68,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A; attack 3 */
    { { {  -80,  18,  76,  18 },  {  -62,  18,  72,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -81,  52,  60,  22 },  {  -60,  31,  82,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A; attack 7 */
    { { {  -46,  27, 101,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH C; attack 5 */
    { { {  -91,  26,  69,  24 },  {  -66,  33,  62,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  30,   0,  23 },  {  -69,  25,  19,  15 } } },  /* 8: S KICK A; attack 10 */
    { { {  -62,  38,  49,  25 },  {  -41,  42,  19,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M KICK A; attack 11 */
    { { { -123,  41,  50,  17 },  {  -82,  64,  46,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M KICK B; attack 13 */
    { { {  -58,  44,  33,  15 },  {  -64,  25,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH A; attack 9 */
    { { {  -73,  22,  33,  19 },  {  -50,  31,  40,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH C; attack 8 */
    { { {  -62,  45,  43,  31 },  {  -37,  37,  25,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { { -108,  32,  70,  20 },  {  -72,  42,  66,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -92,  25,  42,   9 },  {  -67,  44,  41,  11 } } },  /* 15: not used by a script */
    { { { -110,  29,  43,  16 },  {  -81,  51,  41,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI P A; attack 16 */
    { { {  -43,  31,  80,  15 },  {  -50,  28,  39,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI P A; attack 17 */
    { { {  -47,  22,  99,  17 },  {  -38,  53, 110,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P A; attack 18 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -90,  34,   0,  21 },  {  -56,  40,  15,  19 } } },  /* 19: KAGAMI K A; attack 19 */
    { { { -105,  39,   0,  21 },  {  -66,  36,  13,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI K A; attack 20 */
    { { { -108,  40,   0,  20 },  {  -68,  52,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI K A; attack 21 */
    { { { -116,  35,  30,  18 },  {  -81,  50,  23,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -77,  21,  46,  15 },  {  -55,  22,  57,  18 } } },  /* 23: V JUMP P S A; attack 23, 24 */
    { { {  -92,  26,  53,  17 },  {  -66,  32,  62,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -69,  54,  26,  26 },  {    0,   0,   0,   0 } } },  /* 25: not used by a script */
    { { {  -98,  40,  82,  12 },  {  -72,  40,  72,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -92,  56,  98,  27 },  {  -76,  46,  76,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: UP P GUARD P L; attack 27 */
    { { {  -46,  59, 111,  20 },  {  -79,  58,  96,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: UP P GUARD P L */
    { { {  -35,  58, 106,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { {  -77,  31,  52,  21 },  {    0,   0,   0,   0 },  {  -86,  30,  73,  42 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP P L A; attack 29 */
    { { {  -58,  31,  43,  20 },  {    0,   0,   0,   0 },  {  -51,  24,  63,  18 },  {    0,   0,   0,   0 } } },  /* 31: V JUMP P L A; attack 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  15,  42,  20 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP K S A; attack 31 */
    { { {  -97,  52,  58,  18 },  {  -44,  32,  56,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: no box */
    { { {  -67,  32,  60,  24 },  {  -35,  26,  60,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command; attack 38 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { {  -95,  21,  63,  25 },  {  -74,  69,  63,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L KICK A; attack 14, 42 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {  -48,  50,  83,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -48,  54,  -2, 103 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {  -34,  44,   0,  88 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +1; attack 73, 74, 75, 85 */
    { { { -106,  58,  69,  17 },  {  -48,  33,  63,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP K L A; attack 33 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {  -97,  35,  63,  30 },  {  -75,  62,  76,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 64 */
    { { {  -89,  75,  49,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 65 */
    { { { -102,  32,  58,  34 },  {  -70,  39,  44,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 66 */
    { { {  -76,  61,  83,  19 },  {  -99,  85,  70,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 67 */
    { { {  -97,  35,  63,  30 },  {  -75,  62,  76,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 68 */
    { { {  -89,  75,  49,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 69 */
    { { { -102,  35,  63,  30 },  {  -70,  39,  44,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 70 */
    { { {  -76,  61,  83,  19 },  {  -99,  85,  70,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI); attack 71 */
    { { {  -60,  30,  48,  18 },  {  -91,  61,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI); attack 39 */
    { { {  -91,  60,  73,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -63,  33,  48,  18 },  {  -93,  63,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI); attack 52 */
    { { {  -95,  65,  73,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -67,  37,  48,  18 },  {  -97,  67,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI); attack 53, 84 */
    { { {  -99,  69,  73,  17 },  {  -64,  44,  86,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI); attack 90 */
    { { {  -59,  28,  62,  23 },  {  -31,  22,  62,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: F JUMP P L B, SP F JP L P B */
    { { {  -51,  20,  64,  19 },  {  -31,  20,  64,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: F JUMP P L B, SP F JP L P B */
    { { {  -82,  29,  46,  51 },  {  -53,  26,  59,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP); attack 87, 88, 89 */
    { { {  -73,  41,  36,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP); attack 91 */
    { { {  -93,  60,  95,  23 },  {  -70,  38,  78,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: not used by a script */
    { { {  -92,  39,  46,  51 },  {  -53,  26,  59,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP); attack 92 */
    { { {  -83,  29,  85,  13 },  {    0,   0,   0,   0 },  {  -90,  31,  75,  18 },  {  -66,  29,  93,  12 } } },  /* 70: V JUMP P M A; attack 25 */
    { { { -111,  39,  65,  18 },  {    0,   0,   0,   0 },  {  -72,  59,  66,  20 },  {  -94,  71,  55,  11 } } },  /* 71: V JUMP K M A; attack 32 */
    { { {  -96,  38,  68,  15 },  {    0,   0,   0,   0 },  {  -72,  59,  68,  12 },  {  -92,  69,  57,  11 } } },  /* 72: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  24,  39,  10 },  {  -63,  36,  38,   9 } } },  /* 73: KAGAMI P A; attack 15 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  21,  39,  10 },  {  -63,  36,  38,   9 } } },  /* 74: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -57,  28,  32,  32 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 9 S: not started by a command; attack 81 */
    { { {  -93,  29,  93,  25 },  {    0,   0,   0,   0 },  {  -75,  29,  81,  29 },  {  -60,  26,  72,  21 } } },  /* 76: L PUNCH B; attack 100 */
    { { {  -80,  22, 100,  20 },  {    0,   0,   0,   0 },  {  -74,  23,  93,  23 },  {  -62,  24,  89,  22 } } },  /* 77: L PUNCH B */
};

const CATCH_BOX alex_cat_box[25] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -58,   30,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { { -103,   72,    8,    8 } },  /* 2: L PUNCH C */
    { {  -76,   48,    0,   16 } },  /* 3: ATTACK 3 S: 6(123)4+P light (plain script) */
    { {  -72,   44,    0,   16 } },  /* 4: ATTACK 3 M: 6(123)4+P medium (plain script) */
    { {  -68,   40,    0,   16 } },  /* 5: ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    { {  -44,   32,   -8,  100 } },  /* 6: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { {  -51,   43,   52,   40 } },  /* 7: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { {  -98,   61,   -8,   78 } },  /* 8: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { {  -96,   68,    0,   16 } },  /* 9: ATTACK 4 S: SA I 360+P (plain script) */
    { {  -96,   68,    0,   16 } },  /* 10: ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { {  -44,   12,  -31,    2 } },  /* 11: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    { {  -44,   12,  -17,    2 } },  /* 12: not used by a script */
    { {  -40,   12,  -13,    2 } },  /* 13: not used by a script */
    { {  -40,   12,   -1,    2 } },  /* 14: not used by a script */
    { {  -44,   12,  -21,    2 } },  /* 15: not used by a script */
    { {  -56,   12,   -1,    2 } },  /* 16: not used by a script */
    { {  -44,   12,  -45,    2 } },  /* 17: not used by a script */
    { {  -44,   12,   -5,    2 } },  /* 18: not used by a script */
    { {  -56,   12,   -9,    2 } },  /* 19: not used by a script */
    { {  -48,   12,    3,    2 } },  /* 20: not used by a script */
    { {  -36,   12,   -9,    2 } },  /* 21: not used by a script */
    { {  -40,   12,   -3,    2 } },  /* 22: not used by a script */
    { {  -48,   12,  -37,    2 } },  /* 23: not used by a script */
    { {  -40,   12,  -23,    2 } },  /* 24: not used by a script */
};

const CAUGHT_BOX alex_cau_box[18] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -28,   56,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +109 */
    { {  -32,   60,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +38 */
    { {  -28,   56,   52,   50 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, PARING AIR F +35 */
    { {  -46,   61,    0,   16 } },  /* 4: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { {   -7,   41,   54,   21 } },  /* 5: V JUMP K L A */
    { {  -46,   93,    0,    8 } },  /* 6: not used by a script */
    { {  -23,   47,   92,   50 } },  /* 7: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 8: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 9: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -27,   53,  103,   43 } },  /* 10: not used by a script */
    { {  -36,   56,   63,   32 } },  /* 11: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { {  -21,   45,   45,   44 } },  /* 12: AIR NORMAL, BODY SLAM, IPPONZEOI +29 */
    { {  -35,   70,    0,   16 } },  /* 13: PIYO */
    { {  -24,   55,   45,   40 } },  /* 14: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) +2 */
    { {  -34,   62,    0,   16 } },  /* 15: S KICK A */
    { {  -36,   64,    0,    8 } },  /* 16: KAGAMI K A, KAGAMI P A */
    { {  -48,   88,    0,   16 } },  /* 17: L KICK A */
};

