/*
 * KEN_ATTBOX.C  Ken's attack, catch and caught boxes
 *
 * Selected per animation frame through ken_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX ken_att_box[72] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  14,  70,  22 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  14,  84,  12 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  36,  72,   8 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B; attack 4 */
    { { {  -56,  24,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A; attack 5 */
    { { {  -80,  18,  64,  16 },  {  -60,  34,  72,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH B; attack 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  44,  70,   8 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  14,  84,  16 },  {    0,   0,   0,   0 } } },  /* 7: ATTACK 10 M: not started by a command; attack 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  42,  28,  18 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 9 M: not started by a command; attack 1 */
    { { {  -68,  30,  66,  24 },  {  -62,  28,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of M PUNCH A; attack 7, 8 */
    { { {  -56,  18,  98,  14 },  {  -64,  20,  86,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A, follow-up of M PUNCH A */
    { { {  -76,  28,  76,  24 },  {    0,   0,   0,   0 },  {  -52,  22,  76,  18 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B; attack 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  38,  14,  10 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A; attack 10 */
    { { {  -80,  22,  74,  18 },  {  -54,  22,  54,  18 },  {  -72,  24,  66,  20 },  {    0,   0,   0,   0 } } },  /* 13: M KICK A; attack 13 */
    { { {  -84,  28,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M KICK C; attack 11 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  28,  30,  14 },  {    0,   0,   0,   0 } } },  /* 15: M KICK C; attack 12 */
    { { {  -88,  28,  36,  22 },  {  -58,  28,  40,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: no name, L KICK A; attack 14 */
    { { {  -84,  12,   0,  10 },  {    0,   0,   0,   0 },  {  -68,  38,   0,  14 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,   0,  14 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  44,  44,   8 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 19 */
    { { {  -76,  16,  38,  14 },  {    0,   0,   0,   0 },  {  -58,  32,  40,  12 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A; attack 20 */
    { { {  -60,  32,  32,  32 },  {    0,   0,   0,   0 },  {  -44,  28,  16,  24 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 21 */
    { { {  -54,  14,  66,  24 },  {    0,   0,   0,   0 },  {  -46,  14,  84,  24 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  14, 100,  12 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  52,   0,   8 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A; attack 23 */
    { { {  -84,  64,   0,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  24,  60,  12 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -76,  20,  62,  16 },  {    0,   0,   0,   0 },  {  -64,  20,  70,  16 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P M A, F JUMP P M A; attack 27, 33 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  22,  64,  18 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  14,  58,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    { { {  -50,  26,  50,  22 },  {  -36,  22,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1; attack 38, 75, 87 */
    { { {  -60,  38,  22,  32 },  {  -40,  26,  12,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command, ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN); attack 15, 83 */
    { { {  -64,  40,  42,  32 },  {  -50,  26,  20,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2; attack 16, 50, 76, 84 */
    { { {  -48,  32,  46,  32 },  {  -36,  20,  82,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2; attack 17, 51, 77, 85 */
    { { {  -32,  18, 118,  20 },  {    0,   0,   0,   0 },  {  -44,  24,  56,  20 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) +1; attack 18, 78, 86 */
    { { {  -32,  16, 118,  14 },  {    0,   0,   0,   0 },  {  -38,  16,  54,  14 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2; attack 52 */
    { { {  -60,  38,  22,  32 },  {  -40,  26,  12,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 110, 113, 116 */
    { { {  -64,  40,  42,  32 },  {  -50,  26,  20,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 111, 114, 116 */
    { { {  -48,  32,  46,  32 },  {  -36,  20,  82,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA); attack 112, 115, 117, 118 */
    { { {  -32,  18, 118,  20 },  {  -44,  24,  56,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -76,  22,  46,  18 },  {    0,   0,   0,   0 },  {  -52,  22,  54,  18 },  {    0,   0,   0,   0 } } },  /* 40: F JUMP P L A; attack 34 */
    { { {  -70,  18,  52,  14 },  {    0,   0,   0,   0 },  {  -58,  18,  60,  14 },  {    0,   0,   0,   0 } } },  /* 41: F JUMP P L A */
    { { {  -50,  24,  60,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  24,  82,  30 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {  -84,  50,  90,  10 },  {    0,   0,   0,   0 },  {  -62,  32,  84,  10 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P L A; attack 28 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,  86,  10 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  24,  36,  14 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP K S A, F JUMP K S A; attack 29, 35 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -40,  18,  36,  10 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP K S A, F JUMP K S A */
    { { {  -88,  18,  54,  16 },  {    0,   0,   0,   0 },  {  -68,  34,  58,  12 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP K M A; attack 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  44,  60,  10 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP K M A */
    { { {  -82,  22,  82,  18 },  {  -50,  22,  62,  18 },  {  -66,  22,  72,  18 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP K L A; attack 31 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  18,  78,  14 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP K L A */
    { { {  -76,  20,  54,  16 },  {  -22,  46,  42,  16 },  {  -54,  32,  58,  16 },  {    0,   0,   0,   0 } } },  /* 52: F JUMP K M A; attack 36 */
    { { {  -18,  42,  44,  12 },  {    0,   0,   0,   0 },  {  -70,  50,  56,  12 },  {    0,   0,   0,   0 } } },  /* 53: F JUMP K M A */
    { { {  -88,  24,  40,  16 },  {  -62,  24,  44,  16 },  {  -36,  24,  48,  16 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A; attack 37 */
    { { {  -82,  32,  46,  12 },  {  -48,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: F JUMP K L A */
    { { {  -76,  22,  58,  12 },  {    0,   0,   0,   0 },  {  -64,  32,  58,  18 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +5; attack 39, 40, 81, 82 ... */
    { { {   44,  20,  62,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +5; attack 39, 40, 88, 91 ... */
    { { {  -72,  56,   8,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 105 */
    { { {  -68,  52,  32,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 105 */
    { { {  -28,  56,  74,  50 },  {  -48,  50,  38,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 106 */
    { { {  -28,  56,  74,  50 },  {  -28,  56,  38,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 107, 108 */
    { { {  -28,  56,  74,  50 },  {   -2,  50,  38,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA); attack 107 */
    { { {  -96,  64,  34,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 97, 99 */
    { { {  -80,  32,  60,  32 },  {  -60,  32,  44,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 98 */
    { { {  -74,  38,  48,  30 },  {  -54,  28,  30,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP); attack 100 */
    { { {  -78,  52,  56,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 8 S: not started by a command; attack 101, 103 */
    { { {   26,  52,  56,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 8 S: not started by a command; attack 102, 104 */
    { { {  -76,  26,  40,  12 },  {    0,   0,   0,   0 },  {  -50,  32,  32,  18 },  {    0,   0,   0,   0 } } },  /* 68: M KICK B, no name; attack 43 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  40,  40,  10 },  {    0,   0,   0,   0 } } },  /* 69: M KICK B, no name */
    { { {  -70,  18,  56,  30 },  {  -60,  16,  80,  22 },  {  -50,  18,  52,  26 },  {    0,   0,   0,   0 } } },  /* 70: L KICK C, no name; attack 41 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  18,  45,  14 },  {  -66,  16,  32,  12 } } },  /* 71: L KICK C, no name; attack 42 */
};

const CATCH_BOX ken_cat_box[2] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -49,   24,    0,   16 } },  /* 1: TUKAMIKAKARI A */
};

const CAUGHT_BOX ken_cau_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +98 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +23 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +71 */
    { {  -33,   58,    0,    8 } },  /* 4: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 5: S KICK A */
};

