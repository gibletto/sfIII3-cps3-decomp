/*
 * RYU_ATTBOX.C  Ryu's attack, catch and caught boxes
 *
 * Selected per animation frame through ryu_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX ryu_att_box[67] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  14,  70,  22 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  14,  84,  12 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  36,  72,   8 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B; attack 4 */
    { { {  -56,  24,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A; attack 5 */
    { { {  -80,  18,  64,  16 },  {  -60,  34,  72,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH B; attack 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  44,  70,   8 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH B */
    { { {  -64,  26,  54,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH C; attack 50 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  24,  30,  24 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH C; attack 51 */
    { { {  -68,  30,  66,  24 },  {  -62,  28,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, no name; attack 7 */
    { { {  -56,  18,  98,  14 },  {  -64,  20,  86,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A, no name; attack 8 */
    { { {  -76,  28,  76,  24 },  {    0,   0,   0,   0 },  {  -52,  22,  76,  18 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B; attack 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  38,  14,  10 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A; attack 10 */
    { { {  -70,  22,  56,  16 },  {    0,   0,   0,   0 },  {  -60,  22,  44,  16 },  {    0,   0,   0,   0 } } },  /* 13: M KICK A; attack 12 */
    { { {  -60,  42,  44,  10 },  {    0,   0,   0,   0 },  {  -88,  64,  54,  12 },  {    0,   0,   0,   0 } } },  /* 14: M KICK B; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  56,  50,  10 },  {    0,   0,   0,   0 } } },  /* 15: M KICK B */
    { { {  -86,  24,  86,  18 },  {  -60,  24,  66,  18 },  {  -74,  24,  76,  18 },  {    0,   0,   0,   0 } } },  /* 16: L KICK A, follow-up of L PUNCH B; attack 11, 17 */
    { { {  -82,  12,   0,  10 },  {    0,   0,   0,   0 },  {  -68,  38,   0,  14 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,   0,  14 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  44,  44,   8 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 19 */
    { { {  -76,  16,  38,  14 },  {    0,   0,   0,   0 },  {  -58,  32,  40,  12 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A; attack 20 */
    { { {  -60,  32,  32,  32 },  {    0,   0,   0,   0 },  {  -44,  28,  16,  24 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 21 */
    { { {  -46,  14,  84,  24 },  {    0,   0,   0,   0 },  {  -54,  14,  66,  24 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  14, 100,  12 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  52,   0,   8 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A; attack 23 */
    { { {  -88,  64,   0,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  24,  60,  12 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -76,  20,  62,  16 },  {    0,   0,   0,   0 },  {  -64,  20,  70,  16 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P M A; attack 27 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  22,  64,  18 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  14,  58,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P M A, F JUMP P L A */
    { { {  -94,  22,  76,  18 },  {  -50,  26,  50,  20 },  {  -74,  26,  62,  20 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1; attack 71, 72, 73, 79 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -88,  24,  72,  18 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -64,  40,  38,  32 },  {  -50,  24,  18,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1; attack 53, 55, 57, 59 */
    { { {  -48,  32,  46,  32 },  {  -36,  20,  82,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) +1; attack 56, 58, 60, 78 */
    { { {  -32,  18, 118,  20 },  {    0,   0,   0,   0 },  {  -44,  24,  56,  20 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1; attack 54 */
    { { {  -32,  16, 118,  14 },  {    0,   0,   0,   0 },  {  -38,  16,  54,  14 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1 */
    { { {  -66,  46,  36,  36 },  {  -48,  32,  16,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN); attack 74 */
    { { {  -64,  44,  52,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN); attack 75 */
    { { {  -62,  42,  60,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN); attack 76 */
    { { {  -60,  40,  96,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN); attack 77 */
    { { {  -76,  22,  46,  18 },  {    0,   0,   0,   0 },  {  -52,  22,  54,  18 },  {    0,   0,   0,   0 } } },  /* 40: F JUMP P L A; attack 34 */
    { { {  -70,  18,  52,  14 },  {    0,   0,   0,   0 },  {  -58,  18,  60,  14 },  {    0,   0,   0,   0 } } },  /* 41: F JUMP P L A */
    { { {  -50,  24,  60,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: F JUMP P M A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  24,  82,  30 },  {    0,   0,   0,   0 } } },  /* 43: F JUMP P M A; attack 2 */
    { { {  -86,  40,  86,  10 },  {    0,   0,   0,   0 },  {  -66,  36,  80,  10 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P L A; attack 28 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,  86,  10 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  24,  36,  14 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP K S A, F JUMP K S A; attack 29, 35 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -40,  18,  36,  10 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP K S A, F JUMP K S A */
    { { {  -88,  18,  52,  16 },  {    0,   0,   0,   0 },  {  -68,  34,  52,  12 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP K M A; attack 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  44,  54,  10 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP K M A */
    { { {  -82,  22,  82,  18 },  {  -50,  22,  62,  18 },  {  -66,  22,  72,  18 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP K L A; attack 31 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  18,  78,  14 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP K L A */
    { { {  -84,  16,  52,  16 },  {  -28,  40,  46,  12 },  {  -67,  38,  48,  12 },  {    0,   0,   0,   0 } } },  /* 52: F JUMP K M A; attack 36 */
    { { {  -28,  40,  46,  12 },  {    0,   0,   0,   0 },  {  -80,  50,  50,  12 },  {    0,   0,   0,   0 } } },  /* 53: F JUMP K M A */
    { { {  -88,  24,  40,  16 },  {  -62,  24,  44,  16 },  {  -36,  24,  48,  16 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A, ATTACK 7 S: not started by a command; attack 37, 38 */
    { { {  -82,  32,  46,  12 },  {  -48,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: F JUMP K L A, ATTACK 7 S: not started by a command */
    { { {  -72,  20,  62,  16 },  {    0,   0,   0,   0 },  {  -52,  24,  62,  14 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +4; attack 38, 40, 42, 86 ... */
    { { {   40,  20,  64,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU), ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) +2; attack 41, 43, 87, 89 ... */
    { { {  -78,  18,  44,  31 },  {  -59,  58,  44,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU); attack 44, 46 */
    { { {    1,  57,  44,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU); attack 45 */
    { { {  -64,  63,  45,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: not used by a script */
    { { {  -78,  18,  55,  27 },  {  -59,  48,  57,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU); attack 80 */
    { { {   11,  47,  57,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU); attack 81 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  42,  28,  18 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 9 S: not started by a command; attack 69 */
    { { {  -52,  30,  42,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: L PUNCH C; attack 14 */
    { { {  -76,  26,  44,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: L PUNCH C; attack 15 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  18,  46,  14 },  {    0,   0,   0,   0 } } },  /* 66: L PUNCH C */
};

const CATCH_BOX ryu_cat_box[2] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -49,   24,    0,   16 } },  /* 1: TUKAMIKAKARI A */
};

const CAUGHT_BOX ryu_cau_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +104 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +26 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +71 */
    { {  -33,   58,    0,    8 } },  /* 4: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 5: S KICK A */
};

