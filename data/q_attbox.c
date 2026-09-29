/*
 * Q_ATTBOX.C  Q's attack, catch and caught boxes
 *
 * Selected per animation frame through q_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX q_att_box[83] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  29,  80,  28 },  {  -39,  18,  76,  24 } } },  /* 1: S PUNCH A; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  18,  86,  19 },  {  -43,  22,  86,  10 } } },  /* 2: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  24,  67,  19 },  {  -62,  30,  77,  17 } } },  /* 3: S PUNCH B; attack 4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  22,  79,  11 },  {  -57,  22,  86,  10 } } },  /* 4: S PUNCH B */
    { { { -106,  32,  88,  11 },  {    0,   0,   0,   0 },  {  -79,  39,  83,  11 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A; attack 6 */
    { { { -101,  29,  88,  10 },  {    0,   0,   0,   0 },  {  -79,  39,  84,  10 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A */
    { { {  -92,  18,  72,  14 },  {    0,   0,   0,   0 },  {  -87,  38,  82,   9 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH A */
    { { {  -79,  30,  71,  21 },  {    0,   0,   0,   0 },  {  -49,  28,  77,  10 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, L PUNCH C; attack 7, 8, 9, 72 ... */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  57,  28,  16 },  {    0,   0,   0,   0 } } },  /* 9: S KICK A; attack 10 */
    { { {  -70,  23,   0,  23 },  {    0,   0,   0,   0 },  {  -58,  18,  19,  19 },  {  -49,  23,  29,  12 } } },  /* 10: M KICK A; attack 12 */
    { { { -103,  49,  42,  20 },  {    0,   0,   0,   0 },  {  -54,  32,  49,  18 },  {    0,   0,   0,   0 } } },  /* 11: M KICK B; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -81,  20,  45,  20 },  {  -60,  38,  55,  13 } } },  /* 12: M KICK B */
    { { {  -78,  31, 103,  27 },  {    0,   0,   0,   0 },  {  -47,  25,  90,  21 },  {  -86,  19,  72,  40 } } },  /* 13: L KICK C; attack 17 */
    { { {  -65,  27, 106,  23 },  {    0,   0,   0,   0 },  {  -46,  24,  92,  20 },  {    0,   0,   0,   0 } } },  /* 14: L KICK C */
    { { { -133,  22,  43,  22 },  {    0,   0,   0,   0 },  { -101,  70,  55,  14 },  { -115,  19,  50,  17 } } },  /* 15: L KICK A; attack 18 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -115,  26,  51,  15 },  {  -89,  58,  55,  14 } } },  /* 16: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -96,  74,  43,   8 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI P A; attack 19 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  60,  44,   6 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P A */
    { { {  -91,  17,  88,  20 },  {  -80,  17,  83,  15 },  {  -70,  24,  74,  12 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 20 */
    { { {  -89,  14,  77,  12 },  {    0,   0,   0,   0 },  {  -78,  21,  74,  11 },  {  -66,  20,  67,  12 } } },  /* 20: KAGAMI P A */
    { { { -111,  17,   0,  22 },  {  -94,  15,  12,  31 },  {  -79,  23,  35,  17 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -101,  44,   3,   9 },  {  -77,  50,   8,   7 } } },  /* 22: KAGAMI K A; attack 23 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -96,  37,   3,   9 },  {  -77,  50,   8,   7 } } },  /* 23: KAGAMI K A */
    { { {  -95,  17,   0,  16 },  {    0,   0,   0,   0 },  {  -78,  26,   3,   9 },  {  -52,  29,   7,   8 } } },  /* 24: KAGAMI K A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  23,   3,  13 },  {  -64,  36,   7,   9 } } },  /* 25: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -98,  42,   0,  14 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { { -101,  17,  24,  31 },  {  -84,  47,  27,  15 },  {  -84,  59,  30,  20 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI K A; attack 25 */
    { { {  -91,   8,  27,  22 },  {  -83,  31,  28,  12 },  {  -83,  58,  29,  17 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -101,  61,  91,   8 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P S A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -93,  53,  91,   8 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP P S A */
    { { {  -95,  22, 104,  19 },  {    0,   0,   0,   0 },  {  -75,  36, 103,  12 },  {  -83,  47,  91,  13 } } },  /* 31: V JUMP P M A, F JUMP P M A, B JUMP P M A; attack 27 */
    { { {  -85,  22, 105,  13 },  {    0,   0,   0,   0 },  {  -71,  36, 103,   9 },  {  -74,  42,  93,  12 } } },  /* 32: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -94,  26,  44,  18 },  {  -81,  22,  59,  11 },  {  -68,  20,  65,  14 },  {  -55,  23,  74,  10 } } },  /* 33: V JUMP P L A, F JUMP P L A, B JUMP P L A; attack 28 */
    { { {  -81,  19,  53,  17 },  {  -71,  20,  63,  12 },  {  -61,  23,  69,  14 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -79,  21,  58,  16 },  {  -65,  20,  67,  15 } } },  /* 35: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  40,  45,  10 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP K S A; attack 29 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -66,  28,  45,  10 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP K S A */
    { { { -119,  21,  54,  18 },  {    0,   0,   0,   0 },  {  -98,  20,  61,   9 },  {  -78,  39,  65,   8 } } },  /* 38: V JUMP K M A; attack 30 */
    { { { -112,  14,  56,  15 },  {    0,   0,   0,   0 },  {  -98,  20,  61,   9 },  {  -78,  39,  65,   8 } } },  /* 39: V JUMP K M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -108,  30,  60,   8 },  {  -78,  39,  63,   6 } } },  /* 40: V JUMP K M A */
    { { { -103,  22,  41,  12 },  {    0,   0,   0,   0 },  {  -94,  21,  45,  15 },  {  -85,  21,  51,  17 } } },  /* 41: V JUMP K L A, S V JP S P A; attack 31 */
    { { {  -90,  26,  42,  12 },  {    0,   0,   0,   0 },  {  -79,  21,  46,  18 },  {  -71,  21,  51,  19 } } },  /* 42: V JUMP K L A, S V JP S P A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -89,  28,  57,  14 },  {  -71,  20,  66,  13 } } },  /* 43: F JUMP P S A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  25,  60,  11 },  {  -68,  13,  67,  10 } } },  /* 44: F JUMP P S A */
    { { {  -96,  63,  85,  14 },  {  -81,  59,  75,  14 },  {  -67,  46,  65,  10 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 4 M: 214+P medium (plain script); attack 33, 35 */
    { { {  -91,  22,  74,  16 },  {  -80,  15,  67,  15 },  {  -77,  54,  82,  12 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 4 M: 214+P medium (plain script); attack 34 */
    { { {  -81,  26, 113,  15 },  {  -71,  21,  99,  19 },  {  -61,  32,  79,  26 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 4 L: 214+P heavy (plain script); attack 36, 38 */
    { { {  -85,  28, 100,  14 },  {    0,   0,   0,   0 },  {  -61,  33,  87,  21 },  {  -76,  15,  84,  35 } } },  /* 48: ATTACK 4 L: 214+P heavy (plain script); attack 37 */
    { { {  -70,  26,  85,  17 },  {  -62,  21,  75,  14 },  {  -53,  32,  75,  10 },  {    0,   0,   0,   0 } } },  /* 49: not used by a script */
    { { {  -50,  29, 130,  18 },  {  -43,  18, 115,  15 },  {  -33,  16,  98,  17 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -22,  25, 132,  15 },  {  -25,  14, 117,  15 },  {  -27,  14, 102,  15 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -76,  21,  73,  19 },  {  -69,  25,  87,  14 },  {  -44,  18,  88,  11 },  {    0,   0,   0,   0 } } },  /* 52: not used by a script */
    { { {  -91,  25,  52,  24 },  {  -77,  23,  61,  20 },  {  -63,  41,  73,  11 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 45, 46, 47, 48 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  38,  29,  18 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 10 S: not started by a command; attack 14 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  38,  27,  20 },  {    0,   0,   0,   0 } } },  /* 55: not used by a script */
    { { {  -87,  23,  58,  17 },  {  -73,  19,  66,  13 },  {  -63,  41,  73,  11 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 45, 46, 47, 48 */
    { { {  -83,  19,  61,  11 },  {    0,   0,   0,   0 },  {  -63,  41,  73,  11 },  {  -73,  19,  66,  13 } } },  /* 57: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 45, 46, 47, 48 */
    { { {  -86,  19,   0,  26 },  {    0,   0,   0,   0 },  {  -76,  19,  21,  17 },  {  -65,  26,  34,  12 } } },  /* 58: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 49, 50, 51, 52 */
    { { {  -71,  19,   0,  26 },  {    0,   0,   0,   0 },  {  -65,  19,  21,  17 },  {  -55,  15,  35,  12 } } },  /* 59: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 49, 50, 51, 52 */
    { { {  -60,  29,  34,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP); attack 53 */
    { { {  -77,  24,  21,  23 },  {    0,   0,   0,   0 },  {  -53,  32,  21,  15 },  {    0,   0,   0,   0 } } },  /* 61: L KICK C; attack 64 */
    { { {  -68,  41,  50,  19 },  {  -45,  23,  47,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 7 S: SA II 23623+P (plain script); attack 65 */
    { { {  -74,  34,  23,  37 },  {  -62,  22,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 7 S: SA II 23623+P (plain script); attack 66 */
    { { {  -61,  14,  70,  15 },  {    0,   0,   0,   0 },  {  -47,  26,  73,   7 },  {  -55,  28,  53,  20 } } },  /* 64: M PUNCH C; attack 15 */
    { { {  -14,  16, 133,  12 },  {    0,   0,   0,   0 },  {  -23,  15, 104,  34 },  {  -31,   8, 109,  21 } } },  /* 65: M PUNCH C */
    { { {  -93,  57,  48,  30 },  {  -78,  51,  61,  22 },  {  -62,  42,  68,  20 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 61, 63 */
    { { {  -91,  33,  51,  23 },  {  -77,  25,  59,  20 },  {  -62,  42,  71,  13 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 61, 63 */
    { { {  -90,  40,   0,  29 },  {  -76,  32,  22,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 62 */
    { { {  -77,  32,   0,  26 },  {    0,   0,   0,   0 },  {  -65,  19,  21,  17 },  {  -55,  15,  35,  12 } } },  /* 69: ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 62 */
    { { {  -95,  26,  39,  21 },  {    0,   0,   0,   0 },  {  -76,  21,  44,  20 },  {  -69,  31,  53,  21 } } },  /* 70: ATTACK 4 S: 214+P light (plain script); attack 69, 71 */
    { { {  -86,  20,  42,  19 },  {    0,   0,   0,   0 },  {  -77,  21,  50,  19 },  {  -70,  36,  56,  26 } } },  /* 71: ATTACK 4 S: 214+P light (plain script); attack 70 */
    { { {  -90,  43,  72,  13 },  {  -77,  30,  63,   9 },  {  -60,  38,  56,  29 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN); attack 67 */
    { { {  -96,  63,  80,  19 },  {  -81,  59,  68,  20 },  {  -61,  40,  59,   9 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 4 SP: EX 214+PP (plain script); attack 54 */
    { { {  -90,  26,  67,  23 },  {  -77,  54,  75,  19 },  {  -84,  28,  59,  43 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 4 SP: EX 214+PP (plain script); attack 55 */
    { { {  -82,  30, 102,  25 },  {  -73,  26,  84,  34 },  {  -78,  49,  57,  45 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 4 SP: EX 214+PP (plain script); attack 56 */
    { { {  -85,  35,  96,  20 },  {    0,   0,   0,   0 },  {  -52,  27,  83,  23 },  {  -83,  32,  65,  51 } } },  /* 76: ATTACK 4 SP: EX 214+PP (plain script); attack 57 */
    { { {  -71,  27,  80,  22 },  {    0,   0,   0,   0 },  {  -53,  32,  60,  27 },  {  -74,  34,  48,  43 } } },  /* 77: ATTACK 4 SP: EX 214+PP (plain script); attack 58 */
    { { {  -79,  35,  82,  19 },  {    0,   0,   0,   0 },  {  -77,  26,  58,  52 },  {  -44,  22,  81,  20 } } },  /* 78: ATTACK 4 SP: EX 214+PP (plain script); attack 59 */
    { { {  -79,  35,  40,  26 },  {    0,   0,   0,   0 },  {  -53,  32,  47,  24 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 4 SP: EX 214+PP (plain script); attack 60 */
    { { {  -89,  23,  74,  27 },  {    0,   0,   0,   0 },  {  -87,  30,  60,  32 },  {  -61,  38,  68,  18 } } },  /* 80: ATTACK 4 SP: EX 214+PP (plain script); attack 60 */
    { { {  -79,  20,  35,  21 },  {    0,   0,   0,   0 },  {  -69,  35,  51,  15 },  {  -57,  30,  58,  14 } } },  /* 81: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP); attack 74, 75, 76 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -56,  20,  37,  27 },  {  -50,  30,  61,  11 } } },  /* 82: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
};

const CATCH_BOX q_cat_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -46,   24,    0,   16 } },  /* 1: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { {  -66,   44,    0,   16 } },  /* 2: ATTACK 5 S: 3214+K light (plain script) */
    { {  -68,   46,    0,   16 } },  /* 3: ATTACK 5 M: 3214+K medium (plain script) */
    { {  -70,   48,    0,   16 } },  /* 4: ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { {  -78,   56,    0,   16 } },  /* 5: ATTACK 8 L: 236+K (plain script) */
};

const CAUGHT_BOX q_cau_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -22,   44,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +110 */
    { {  -26,   48,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +23 */
    { {  -25,   50,   48,   40 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +55 */
    { {  -37,   61,    0,   16 } },  /* 4: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -30,   52,    0,    8 } },  /* 5: KAGAMI P A, KAGAMI K A */
};

