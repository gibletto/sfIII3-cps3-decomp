/*
 * CHUN_ATTBOX.C  Chun-Li's attack, catch and caught boxes
 *
 * Selected per animation frame through chun_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX chun_att_box[101] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  30,  72,   6 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -43,  21,  72,   4 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -83,  48,  79,   5 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B; attack 4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -77,  40,  80,   3 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -69,  16,  75,  16 },  {  -54,  13,  82,   4 },  {  -42,  21,  82,   7 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH C; attack 5 */
    { { {  -71,  20,  77,  16 },  {    0,   0,   0,   0 },  {  -55,  38,  86,  10 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH C; attack 6 */
    { { {  -82,  47,  67,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH A, no name; attack 7, 120 */
    { { {  -70,  35,  67,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, no name */
    { { {  -73,  33,  44,  27 },  {  -46,  26,  48,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH C; attack 8 */
    { { {  -69,  29,  44,  23 },  {  -46,  26,  48,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH C */
    { { {  -99,  22,  58,  15 },  {  -77,  23,  60,   7 },  {  -83,  40,  50,  13 },  {  -69,  37,  45,  11 } } },  /* 11: L PUNCH A; attack 9 */
    { { {  -86,  13,  59,  11 },  {  -74,  19,  61,   5 },  {  -65,  34,  53,  11 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH A */
    { { {  -84,  11,  59,  11 },  {  -74,  19,  61,   5 },  {  -54,  23,  59,   5 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH A */
    { { {  -83,  10,  60,   9 },  {  -74,  19,  61,   4 },  {  -54,  23,  59,   4 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A */
    { { {  -87,  18,  48,  12 },  {  -73,  29,  53,  10 },  {  -62,  49,  51,  15 },  {    0,   0,   0,   0 } } },  /* 15: M KICK C; attack 115 */
    { { {  -76,  15,  49,  12 },  {  -69,  22,  54,  11 },  {  -54,  48,  56,  11 },  {    0,   0,   0,   0 } } },  /* 16: M KICK C */
    { { {  -74,  13,  52,   9 },  {  -67,  21,  56,   8 },  {  -50,  44,  57,   9 },  {    0,   0,   0,   0 } } },  /* 17: M KICK C */
    { { {  -63,  35,  76,   4 },  {  -59,   5,  60,  16 },  {  -56,   5,  45,  18 },  {    0,   0,   0,   0 } } },  /* 18: M KICK A; attack 12 */
    { { {  -30,  14, 104,   7 },  {  -36,   8,  94,  12 },  {  -40,   7,  86,  13 },  {    0,   0,   0,   0 } } },  /* 19: M KICK A */
    { { {  -99,  23,  50,  20 },  {  -80,  29,  57,  13 },  {  -52,  30,  60,  12 },  {    0,   0,   0,   0 } } },  /* 20: L KICK B; attack 18 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  43,  86,  10 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP P S A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  40,  92,   5 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -65,  44,  31,   6 },  {    0,   0,   0,   0 } } },  /* 23: S KICK A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -54,  33,  30,   5 },  {    0,   0,   0,   0 } } },  /* 24: S KICK A */
    { { {  -99,  23,  60,  19 },  {    0,   0,   0,   0 },  {  -77,  17,  66,   9 },  {  -60,  44,  63,   9 } } },  /* 25: KAGAMI K C; attack 2 */
    { { {  -88,  18,  85,  18 },  {  -80,  18,  82,  14 },  {  -67,  20,  78,  12 },  {  -55,  25,  73,  12 } } },  /* 26: M KICK B, no name; attack 15, 121 */
    { { {  -78,  12,  92,   9 },  {  -68,  11,  87,   8 },  {  -58,  17,  83,   8 },  {  -46,  26,  74,  12 } } },  /* 27: M KICK B, no name */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   12,  29, 106,   6 },  {   22,  38, 103,   5 } } },  /* 28: M KICK B, no name */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -57,  20,  93,  43 },  {  -55,   9,  76,  17 } } },  /* 29: V JUMP K S A; attack 29 */
    { { {  -61,   9,  76,  19 },  {  -64,  11,  91,  15 },  {  -60,  21,  74,  54 },  {  -58,  23,  61,  20 } } },  /* 30: V JUMP K M A; attack 30 */
    { { {  -62,  12,  28,  13 },  {  -53,  10,  38,  12 },  {  -46,  12,  45,  13 },  {  -37,  12,  53,  13 } } },  /* 31: F JUMP K L A; attack 37 */
    { { {  -68,  12,  87,  11 },  {    0,   0,   0,   0 },  {  -56,  35,  87,   8 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP P M A; attack 27 */
    { { {  -64,   8,  89,  10 },  {    0,   0,   0,   0 },  {  -56,  35,  89,   5 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP P M A */
    { { {  -63,  20,  73,  15 },  {  -51,   8,  79,  20 },  {  -46,  25,  74,  24 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP P L A, F JUMP P L B; attack 28, 119 */
    { { {  -98,  27,  59,  15 },  {    0,   0,   0,   0 },  {  -73,  27,  63,  10 },  {  -50,  31,  66,   9 } } },  /* 35: V JUMP K L A; attack 31 */
    { { {  -90,  24,  63,   8 },  {    0,   0,   0,   0 },  {  -65,  21,  66,   6 },  {  -49,  31,  69,   5 } } },  /* 36: V JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  30,  70,   8 },  {  -76,  49,  75,   6 } } },  /* 37: F JUMP K S A; attack 35 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -100,  24,  73,   5 },  {  -76,  49,  76,   4 } } },  /* 38: F JUMP K S A */
    { { { -107,  16,  68,   9 },  {    0,   0,   0,   0 },  {  -96,  20,  72,   7 },  {  -76,  49,  75,   7 } } },  /* 39: F JUMP K M A; attack 36 */
    { { {  -96,   8,  72,   6 },  {    0,   0,   0,   0 },  {  -88,  12,  73,   5 },  {  -76,  49,  76,   4 } } },  /* 40: F JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  11,  54,   8 },  {  -55,  21,  58,  10 } } },  /* 41: F JUMP P S A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,   8,  57,   5 },  {  -55,  21,  59,   9 } } },  /* 42: F JUMP P S A; attack 32 */
    { { {  -70,  15,  49,  11 },  {    0,   0,   0,   0 },  {  -57,  23,  56,  11 },  {    0,   0,   0,   0 } } },  /* 43: F JUMP P M A; attack 33 */
    { { {  -63,  11,  54,   8 },  {    0,   0,   0,   0 },  {  -57,  23,  57,  10 },  {    0,   0,   0,   0 } } },  /* 44: F JUMP P M A; attack 33 */
    { { {  -98,  19,  48,  15 },  {  -85,  10,  61,   9 },  {  -80,  16,  66,   9 },  {  -70,  27,  71,  10 } } },  /* 45: F JUMP P L A; attack 34 */
    { { {  -93,  14,  53,  12 },  {  -84,   9,  62,   8 },  {  -80,  16,  66,   9 },  {  -70,  27,  71,  10 } } },  /* 46: F JUMP P L A */
    { { {  -92,  15,  82,   9 },  {  -87,  16,  77,   7 },  {  -60,  30,  73,  10 },  {    0,   0,   0,   0 } } },  /* 47: F JUMP P L A; attack 56 */
    { { {  -92,  14,  73,   8 },  {    0,   0,   0,   0 },  {  -78,  45,  71,  12 },  {    0,   0,   0,   0 } } },  /* 48: F JUMP P L A */
    { { {  -49,  28,  60,  22 },  {    0,   0,   0,   0 },  {  -44,  38,  52,  24 },  {  -39,  36,  42,  18 } } },  /* 49: L KICK A; attack 16 */
    { { {  -36,  18,  64,  15 },  {    0,   0,   0,   0 },  {  -34,  27,  53,  22 },  {    0,   0,   0,   0 } } },  /* 50: L KICK A; attack 17 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  47,  76,   8 },  {    0,   0,   0,   0 } } },  /* 51: follow-up of M KICK A; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  51,  76,   8 },  {    0,   0,   0,   0 } } },  /* 52: follow-up of M KICK A; attack 14 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  52,  30,   9 },  {    0,   0,   0,   0 } } },  /* 53: KAGAMI P A; attack 19 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  42,  32,   5 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI P A */
    { { {  -96,  17,   0,  12 },  {    0,   0,   0,   0 },  {  -79,  50,   0,   5 },  {    0,   0,   0,   0 } } },  /* 55: KAGAMI P A; attack 20 */
    { { {  -88,  14,   0,   9 },  {    0,   0,   0,   0 },  {  -74,  45,   0,   5 },  {    0,   0,   0,   0 } } },  /* 56: KAGAMI P A */
    { { {  -72,  22,  20,  18 },  {  -59,  14,  31,  13 },  {  -52,  35,  25,   6 },  {  -49,  12,  39,  10 } } },  /* 57: KAGAMI P A; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -81,  21,   0,   7 },  {  -60,  40,   0,   9 } } },  /* 58: KAGAMI K A; attack 23 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -75,  18,   0,   7 },  {  -57,  37,   0,   9 } } },  /* 59: KAGAMI K A */
    { { { -101,  20,   0,  10 },  {  -85,  24,   5,   7 },  {  -61,  41,   7,   9 },  {    0,   0,   0,   0 } } },  /* 60: KAGAMI K A; attack 24 */
    { { { -113,  52,  36,  10 },  {  -92,  26,  68,  13 },  {  -70,  49,  28,  13 },  {  -71,  26,  60,  17 } } },  /* 61: KAGAMI K A; attack 25 */
    { { { -109,  48,  36,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -92,  34,  67,  13 } } },  /* 62: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  38,  30,  28 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 9 S: not started by a command; attack 11 */
    { { {  -65,  22,  75,  19 },  {  -45,  12,  75,  14 },  {  -37,  17,  72,  13 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU); attack 38, 109, 112 */
    { { {  -92,  19,  67,  17 },  {  -73,  27,  70,  11 },  {  -46,  25,  73,   9 },  {   21,  18,  71,  11 } } },  /* 65: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU); attack 39, 40, 110, 113 ... */
    { { {  -86,  19,  73,  18 },  {  -71,  27,  72,  11 },  {  -44,  23,  74,   9 },  {   21,  18,  69,  11 } } },  /* 66: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU); attack 39, 110, 113 */
    { { {  -66,  25,  90,  13 },  {  -45,  20,  87,  11 },  {  -28,  24,  73,  22 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8; attack 44, 48, 52, 74 */
    { { {  -71,  24,  53,  14 },  {  -51,  20,  59,  11 },  {  -31,  22,  60,  13 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8; attack 45, 49, 53, 75 */
    { { {  -60,  23, 102,  16 },  {  -43,  20,  97,  12 },  {  -26,  24,  85,  18 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {  -71,  21,  73,  14 },  {  -50,  20,  75,  11 },  {  -30,  25,  71,  12 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8; attack 47, 51, 55, 77 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -7,  10,  21,  37 },  {  -12,  11,  13,  11 } } },  /* 71: V JUMP K M B; attack 57 */
    { { {  -94,  32,  39,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 6 S: SA I 23623+P (plain script); attack 58 */
    { { { -100,  32,  35,  56 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 6 S: SA I 23623+P (plain script); attack 59 */
    { { { -106,  34,  32,  64 },  {  -91,  45,  21,  78 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 6 S: SA I 23623+P (plain script); attack 60 */
    { { { -106,  34,  32,  64 },  {  -91,  64,  21,  86 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 6 S: SA I 23623+P (plain script); attack 63 */
    { { { -106,  34,  32,  64 },  {  -91,  77,  15,  95 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 6 S: SA I 23623+P (plain script); attack 64 */
    { { { -106,  34,  32,  64 },  {  -91,  90,  15,  98 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 6 S: SA I 23623+P (plain script); attack 61, 62, 63, 64 ... */
    { { { -102,  30,  33,  62 },  {  -83,  65,  17,  94 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: not used by a script */
    { { {  -80,  23,  57,  27 },  {  -56,  55,  56,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU); attack 71, 73 */
    { { {   56,  24,  57,  27 },  {    1,  55,  56,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU); attack 72 */
    { { {  -72,  28,  34,  17 },  {  -57,  22,  44,  16 },  {  -35,  22,  53,  13 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8; attack 78, 79, 80, 81 ... */
    { { {  -70,  27,  79,  24 },  {  -45,  23,  71,  26 },  {  -36,  37,  55,  35 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 82 */
    { { {  -75,  26,  49,  24 },  {  -51,  26,  56,  20 },  {  -25,  26,  59,  20 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 83 */
    { { {  -74,  25,  67,  21 },  {  -50,  25,  66,  21 },  {  -25,  25,  61,  22 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 84 */
    { { {  -77,  28,  31,  23 },  {  -57,  24,  40,  22 },  {  -40,  34,  47,  22 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 85, 86 */
    { { {  -71,  31,  84,  19 },  {  -45,  24,  77,  20 },  {  -28,  28,  67,  23 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 87 */
    { { {  -74,  31,  52,  20 },  {  -45,  24,  56,  20 },  {  -28,  28,  55,  23 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 88 */
    { { {  -73,  31,  69,  22 },  {  -45,  24,  66,  22 },  {  -28,  31,  61,  24 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 89 */
    { { {  -73,  31,  31,  23 },  {  -52,  28,  41,  24 },  {  -30,  28,  48,  23 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 90, 91 */
    { { {  -34,  16, 104,  20 },  {  -30,  21,  53,  51 },  {  -44,  55,  44,  41 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 92 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  20,  97,  22 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP); attack 93 */
    { { {  -90,  31,   0,  30 },  {    0,   0,   0,   0 },  {  -59,  27,   0,  31 },  {  -82,  29,  21,  29 } } },  /* 92: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 94, 96, 98, 100 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -59,  27,   0,  22 },  {  -80,  21,   0,  28 } } },  /* 93: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP); attack 95, 97, 99 */
    { { {  -59,  45,  26,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 102, 106 */
    { { {  -50,  29,  65,  30 },  {    0,   0,   0,   0 },  {  -45,  48,  52,  55 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -65,  44,  72,  38 },  {    0,   0,   0,   0 },  {  -51,  37,  65,  33 },  {    0,   0,   0,   0 } } },  /* 96: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 103 */
    { { {  -73,  40,  37,  34 },  {    0,   0,   0,   0 },  {  -58,  39,  44,  34 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 104 */
    { { {  -51,  30,  26,  32 },  {    0,   0,   0,   0 },  {  -58,  39,  20,  47 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 105 */
    { { { -102,  43,   0,  43 },  {  -94,  58,  21,  70 },  {  -59,  27,   0,  41 },  {    0,   0,   0,   0 } } },  /* 99: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 107 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -51,  18, 112,  28 },  {    0,   0,   0,   0 } } },  /* 100: V JUMP K S A */
};

const CATCH_BOX chun_cat_box[3] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -48,   26,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {  -42,   25,   53,   36 } },  /* 2: TUKAMI AIR A */
};

const CAUGHT_BOX chun_cau_box[21] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -22,   44,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +111 */
    { {  -26,   48,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +35 */
    { {  -22,   44,   48,   40 } },  /* 3: L KICK B, V JUMP P S A, V JUMP P M A +71 */
    { {  -25,   50,   48,   40 } },  /* 4: not used by a script */
    { {   -1,   48,    0,   90 } },  /* 5: not used by a script */
    { {  -21,   36,    0,   90 } },  /* 6: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 7: not used by a script */
    { {  -30,   52,    0,    8 } },  /* 8: KAGAMI P A, KAGAMI K A */
    { {  -26,   48,    0,   16 } },  /* 9: not used by a script */
    { {  -28,   48,    0,   58 } },  /* 10: not used by a script */
    { {  -28,   45,   46,   61 } },  /* 11: not used by a script */
    { {  -24,   44,   54,   52 } },  /* 12: not used by a script */
    { {  -25,   50,   48,   40 } },  /* 13: not used by a script */
    { {   -8,   40,   66,   25 } },  /* 14: not used by a script */
    { {  -16,   48,    0,   82 } },  /* 15: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 16: not used by a script */
    { {  -41,   81,    0,   16 } },  /* 17: not used by a script */
    { {  -36,   73,   46,   49 } },  /* 18: not used by a script */
    { {  -38,   63,    0,   16 } },  /* 19: not used by a script */
    { {  -25,   71,    0,   16 } },  /* 20: not used by a script */
};

