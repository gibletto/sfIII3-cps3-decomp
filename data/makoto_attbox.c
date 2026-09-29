/*
 * MAKOTO_ATTBOX.C  Makoto's attack, catch and caught boxes
 *
 * Selected per animation frame through makoto_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX makoto_att_box[75] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -97,  56,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: L KICK A, follow-up of M KICK C; attack 13, 77 */
    { { {  -87,  48,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: L KICK A, follow-up of M KICK C */
    { { {  -87,  48,  49,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: L KICK A, follow-up of M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  40,  58,  16 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -50,  28,  57,  14 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  49,  61,  11 },  {    0,   0,   0,   0 } } },  /* 6: S PUNCH C; attack 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -75,  43,  61,  11 },  {    0,   0,   0,   0 } } },  /* 7: S PUNCH C */
    { { {  -53,  24,  45,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH C; attack 4 */
    { { {  -46,  25,  49,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH C */
    { { {  -82,  44,  68,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A; attack 5 */
    { { {  -89,  41,  54,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH C, follow-up of L PUNCH C; attack 6, 7, 8 */
    { { {  -80,  41,  54,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH C, follow-up of L PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -54,  20,  38,  48 },  {    0,   0,   0,   0 } } },  /* 13: S KICK A; attack 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -53,  17,  43,  41 },  {    0,   0,   0,   0 } } },  /* 14: S KICK A */
    { { {  -91,  33,  80,  21 },  {  -66,  25,  75,  22 },  {  -42,  18,  61,  29 },  {    0,   0,   0,   0 } } },  /* 15: M KICK A, follow-up of S KICK A; attack 11, 35 */
    { { {  -85,  31,  84,  14 },  {  -61,  18,  78,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M KICK A, follow-up of S KICK A */
    { { {  -85,  37,  70,  16 },  {  -57,  35,  65,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: M KICK C; attack 12 */
    { { {  -79,  37,  74,   6 },  {  -57,  26,  69,   5 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  29,  44,   6 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 16 */
    { { {  -89,  47,  41,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A; attack 17 */
    { { { -112,  15,   3,  15 },  {  -98,  33,  15,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 18 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -81,  43,  20,   7 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI K A; attack 19 */
    { { {  -88,  27,  41,  19 },  {  -68,  30,  32,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI K A; attack 20 */
    { { {  -81,  27,  40,  16 },  {  -54,  21,  33,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -102,  47,  44,  18 },  {    0,   0,   0,   0 } } },  /* 25: S KICK C; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -89,  44,  47,  11 },  {    0,   0,   0,   0 } } },  /* 26: S KICK C */
    { { {  -88,  28,   8,  17 },  {  -74,  28,  21,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: L KICK C; attack 22 */
    { { {  -61,  35,  84,  16 },  {  -36,  14,  67,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI K A; attack 23 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -91,  47,  78,  19 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P S A; attack 24 */
    { { {  -91,  39,  78,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP P M A; attack 25 */
    { { {  -90,  48,  85,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: V JUMP P L A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  26,  63,  28 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP K S A, F JUMP K S A, B JUMP K S A; attack 27 */
    { { { -100,  21,  39,  14 },  {  -85,  20,  44,  15 },  {  -64,  67,  53,  13 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K M A, F JUMP K M A, B JUMP K M A; attack 28 */
    { { { -105,  47,  72,  16 },  {    0,   0,   0,   0 },  {  -57,  31,  71,  18 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP K L A, F JUMP K L A, B JUMP K L A; attack 29 */
    { { {  -97,  41,  72,  13 },  {    0,   0,   0,   0 },  {  -57,  31,  72,  14 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  23,  51,  25 },  {    0,   0,   0,   0 } } },  /* 36: F JUMP P S A, B JUMP P S A; attack 30 */
    { { {  -74,  23,  46,  18 },  {  -58,  17,  59,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: F JUMP P M A, B JUMP P M A; attack 31 */
    { { {  -72,  35,  89,  28 },  {  -53,  35, 105,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: F JUMP P L A, B JUMP P L A; attack 32 */
    { { {  -60,  37,  17,  26 },  {  -79,  25,  34,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: F JUMP P L A, B JUMP P L A; attack 33 */
    { { {  -78,  30,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: M PUNCH A; attack 3 */
    { { {  -72,  25,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  30,  24,  44 },  {    0,   0,   0,   0 } } },  /* 42: ATTACK 1 S: not started by a command; attack 34 */
    { { {  -70,  28,  76,  16 },  {  -43,  19,  64,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI K A */
    { { {  -76,  27,  50,  35 },  {  -66,  43,  75,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1; attack 37, 64, 65, 66 */
    { { {  -82,  27,  15,  40 },  {  -70,  23,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -70,  23,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    1,  21,  82,  40 },  {   -7,  34,  51,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script); attack 38, 61, 62 */
    { { {    5,  18,  69,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) +1 */
    { { {  -56,   7,  48,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 5 S: not started by a command; attack 39 */
    { { {  -64,  22,   6,  19 },  {  -54,  29,  19,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1); attack 42 */
    { { {  -85,  23,  18,  20 },  {  -73,  35,  29,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1); attack 42 */
    { { { -105,  25,  36,  19 },  {  -87,  32,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1); attack 42 */
    { { {  -59,  28,  64,  27 },  {  -49,  23,  39,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1); attack 43 */
    { { {  -52,  20,  38,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -61,  35,  84,  16 },  {  -36,  14,  67,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1); attack 44 */
    { { {  -70,  28,  76,  16 },  {  -43,  19,  64,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -43,  35,  80,  43 },  {  -64,  70,   0,  83 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1); attack 45 */
    { { {  -18,   6,  84,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -62,  28,  47,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4; attack 48, 49, 50, 51 ... */
    { { {  -56,  25,  53,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    { { {  -78,  41,  11,  36 },  {  -53,  27,  40,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script); attack 56 */
    { { {  -67,  16,  33,  14 },  {  -57,  22,  40,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -64,  27,  36,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 11 SP: after SA I 23623+P (plain script); attack 57 */
    { { {  -67,  28,  47,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 11 SP: after SA I 23623+P (plain script); attack 58 */
    { { {  -67,  30,  59,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 11 SP: after SA I 23623+P (plain script); attack 59 */
    { { {  -52,  59,  50,  66 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 11 SP: after SA I 23623+P (plain script); attack 60 */
    { { {  -29,  19,  94,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -63,  36,  62,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 7 S: not started by a command; attack 69 */
    { { {  -52,  29,  67,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 7 S: not started by a command */
    { { { -107,  68,  69,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 7 S: not started by a command; attack 70 */
    { { {  -99,  60,  69,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 7 S: not started by a command */
    { { {  -92,  18,  79,  29 },  {  -78,  24,  79,  24 },  {  -63,  22,  78,  20 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2; attack 71, 72, 73, 74 ... */
    { { {  -83,  20,  31,  36 },  {  -63,  13,  40,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2; attack 76 */
    { { {    0,  25,  82,  39 },  {   -7,  34,  51,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 4 SP: EX 623+PP (plain script); attack 63 */
};

const CATCH_BOX makoto_cat_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -36,   11,    0,   16 } },  /* 1: not used by a script */
    { {  -45,   20,    0,   16 } },  /* 2: TUKAMIKAKARI A */
    { {  -64,   53,    0,   16 } },  /* 3: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI) */
    { {  -68,   57,    0,   16 } },  /* 4: ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) */
    { {  -72,   61,    0,   16 } },  /* 5: ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
};

const CAUGHT_BOX makoto_cau_box[17] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +108 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +25 */
    { {  -38,   63,    0,   16 } },  /* 3: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { {  -25,   50,   56,   36 } },  /* 4: JUMP JUNBI, SP JUMP JUNBI, PARING AIR F +40 */
    { {  -31,   50,    0,   16 } },  /* 5: S KICK A, M KICK A, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { {  -69,   50,    0,   16 } },  /* 6: not used by a script */
    { {  -41,   52,    0,   16 } },  /* 7: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { {  -25,   50,    0,   16 } },  /* 8: not used by a script */
    { {  -25,   50,   -3,   40 } },  /* 9: not used by a script */
    { {  -52,   77,   50,   40 } },  /* 10: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    { {  -22,   64,    0,   16 } },  /* 11: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +4 */
    { {  -37,   66,    0,   16 } },  /* 12: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { {  -52,   75,    0,   16 } },  /* 13: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) +2 */
    { {  -41,   52,    0,   16 } },  /* 14: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { {  -25,   50,   42,   36 } },  /* 15: AIR NORMAL, BODY UPPER, ASIBARAI SIRI +26 */
    { {  -33,   58,    0,    8 } },  /* 16: KAGAMI P A, KAGAMI K A */
};

