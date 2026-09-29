/*
 * NECRO_ATTBOX.C  Necro's attack, catch and caught boxes
 *
 * Selected per animation frame through necro_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX necro_att_box[59] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  21,  48,  15 },  {  -61,  36,  48,  15 } } },  /* 1: S PUNCH C; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -113,  19,  63,  12 },  {  -94,  65,  63,  12 } } },  /* 2: S PUNCH A; attack 2 */
    { { { -102,  26,  67,  18 },  {  -76,  54,  67,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A, follow-up of S KICK C; attack 3, 76 */
    { { {   -4,  33, 125,  46 },  {  -41,  24,  72,  59 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -194,  21,  56,  17 },  { -172, 151,  56,  17 } } },  /* 5: L PUNCH A, follow-up of follow-up of S KICK C; attack 5, 77 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  41,  34,  11 },  {    0,   0,   0,   0 } } },  /* 6: S KICK C; attack 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  11,  39,  24 },  {  -75,  53,  40,  15 } } },  /* 7: S KICK A; attack 7 */
    { { {  -73,  17,  70,  13 },  {  -60,  35,  40,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK C; attack 8 */
    { { { -124,  38,  28,  14 },  {  -84,  60,  28,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M KICK A; attack 9 */
    { { {  -71,  21,  86,  47 },  {  -49,  26,  42,  80 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L KICK C; attack 10 */
    { { {  -72,  52,  69,  18 },  { -116,  47,  79,  15 },  { -171,  20,  98,  24 },  { -151,  38,  92,  14 } } },  /* 11: L KICK A; attack 11 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -113,  15,  32,  11 },  {  -98,  74,  32,  11 } } },  /* 12: KAGAMI P A; attack 12 */
    { { { -115,  19, 108,  18 },  {  -97,  20,  94,  19 },  {  -79,  22,  79,  20 },  {  -61,  26,  62,  23 } } },  /* 13: KAGAMI P A; attack 13 */
    { { { -117,  28,  74,  21 },  { -100,  42,  48,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P C; attack 90 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -105,  77,   0,  20 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A; attack 15 */
    { { {   36,  68,   8,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: not used by a script */
    { { { -146,  19,   0,  24 },  { -127, 112,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 17 */
    { { {  -53,  26,  47,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: L PUNCH C; attack 4 */
    { { {  -86,  34,  24,  20 },  {  -73,  28,  42,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1; attack 18, 63, 64, 81 ... */
    { { { -169,  26,  92,   5 },  { -143, 117,  94,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: V JUMP P M A; attack 20 */
    { { { -135,  40,  55,  24 },  {  -93,  32,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP P L A, F JUMP P L A; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -47,  15,  43,  21 },  {  -32,  16,  52,  24 } } },  /* 22: V JUMP K S A, F JUMP K S A; attack 22 */
    { { { -121,  12,  66,  27 },  { -107,  78,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: V JUMP K L A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  17,  36,  17 },  {  -59,  37,  48,  11 } } },  /* 24: F JUMP P S A; attack 25 */
    { { {  -60,  27,  33,  17 },  {  -53,  20,  48,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: F JUMP K M A; attack 27, 28 */
    { { {  -60,  27,  33,  17 },  {  -33,  20,  48,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: F JUMP K M A; attack 28 */
    { { {  -78,  21,  86,  14 },  {  -62,  49,  79,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { {  -82,  30,  83,  18 },  {  -49,  25,  71,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1; attack 70, 71, 72, 83 */
    { { {  -97,  36,   0,  48 },  {  -59,  32,  42,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1; attack 84 */
    { { {  -43,  19,  77,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: no box */
    { { {  -92,  18,  52,  18 },  {  -73,  48,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: M PUNCH C; attack 54 */
    { { { -174,  40,   0,  11 },  { -133, 103,   0,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI K A; attack 53 */
    { { { -136,  32,  62,  23 },  { -104,  72,  62,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP K L A */
    { { {  -59,   9,  47,  20 },  {  -50,  29,  47,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1; attack 39, 57, 60, 65 ... */
    { { {  -84,  28,  58,  21 },  {  -55,  39,  52,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1; attack 40, 41, 58, 59 ... */
    { { {  -50, 102,  63,  27 },  {  -24,  53,  52,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 3 L: 623+P heavy/EX (plain script); attack 42, 43, 67 */
    { { {  -37,  75,  63,  27 },  {  -24,  53,  48,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 3 L: 623+P heavy/EX (plain script); attack 43, 67 */
    { { {  -63, 116,   7,  84 },  {  -24,  53,  52,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 4 S: SA I 23623+P (plain script); attack 44, 45, 56, 73 ... */
    { { {  -52, 105,   7,  84 },  {  -26,  54,  53,  59 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {  -89,  42,  63,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 10 SP: not started by a command; attack 31 */
    { { {  -77,  26,   0,  20 },  {  -53,  33,  13,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: not used by a script */
    { { {  -89,  32, 114,  32 },  {  -66,  51,  50,  73 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {  -97,  90,  51,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -121,  20, 113,   7 },  { -103,  61, 106,   6 } } },  /* 45: V JUMP P S A; attack 19 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {   -1,  26, 125,  46 },  {  -19,  24,  98,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: L PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  35,  27,  20 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 8 L: not started by a command; attack 91 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: no box */
    { { {  -39,  79,  63,  27 },  {  -24,  53,  58,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 3 S: 623+P light (plain script); attack 42, 43 */
    { { {  -44,  89,  63,  27 },  {  -24,  53,  54,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 3 M: 623+P medium (plain script); attack 42, 43, 67 */
    { { { -139,  31, 102,  22 },  { -108,  79,  87,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: V JUMP K M A; attack 23 */
    { { {  -34,  18,  17,  25 },  {  -51,  23,  38,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A; attack 29, 30 */
    { { {  -79,  17,  41,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP K S B; attack 79, 80 */
    { { { -146,  22,   3,  13 },  { -130,  21,  11,  13 },  { -114,  25,  19,  16 },  { -100,  29,  30,  15 } } },  /* 56: F JUMP P M A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -196,  99,  33,  10 },  {  -97,  75,  30,  11 } } },  /* 57: KAGAMI P A; attack 14 */
    { { { -179,  27,  91,  26 },  { -153,  52,  84,  14 },  { -107,  60,  69,  18 },  {  -47,  36,  58,  23 } } },  /* 58: not used by a script */
};

const CATCH_BOX necro_cat_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -49,   26,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { { -123,   56,    4,   16 } },  /* 2: ATTACK 5 S: 1236+K light (plain script), ATTACK 11 L: not started by a command */
    { { -131,   56,    4,   16 } },  /* 3: ATTACK 5 M: 1236+K medium (plain script) */
    { { -139,   56,    4,   16 } },  /* 4: ATTACK 5 L: 1236+K heavy/EX (plain script) */
    { {  -86,   61,    0,   16 } },  /* 5: ATTACK 7 S: SA II 23623+P (plain script) */
};

const CAUGHT_BOX necro_cau_box[17] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -23,   46,    0,   16 } },  /* 1: HURIMUKI, FRONT WALK, DASH HUMIKOMI +100 */
    { {  -27,   50,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, KAGAMI S +31 */
    { {  -25,   50,   68,   48 } },  /* 3: no name, TUKAMIHAZUSARE, V JUMP P S A +30 */
    { {  -34,   48,   80,   28 } },  /* 4: not used by a script */
    { {  -24,   48,   83,   28 } },  /* 5: not used by a script */
    { {  -31,   48,   84,   28 } },  /* 6: not used by a script */
    { {   -7,   48,   84,   28 } },  /* 7: not used by a script */
    { {  -32,   48,   83,   28 } },  /* 8: not used by a script */
    { {  -55,   48,    0,    8 } },  /* 9: KAGAMI P C */
    { {  -28,   35,   56,   58 } },  /* 10: not used by a script */
    { {  -24,   48,   44,   64 } },  /* 11: not used by a script */
    { {  -22,   48,   42,   37 } },  /* 12: BODY SLAM, TOMOE RYU, MONKEY FLIP +25 */
    { {  -31,   54,    0,    8 } },  /* 13: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   -8,   24 } },  /* 14: P BREAK ZUJOU, TUKAMIHAZUSI, no name +2 */
    { {  -35,   74,    0,   16 } },  /* 15: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { {  -60,   96,   48,   27 } },  /* 16: V JUMP K S B */
};

