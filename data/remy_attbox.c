/*
 * REMY_ATTBOX.C  Remy's attack, catch and caught boxes
 *
 * Selected per animation frame through remy_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX remy_att_box[79] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -79,  58,  24,  72 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: follow-up of CATCH 2; attack 3 */
    { { {  -79,  58,  24,  72 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: follow-up of CATCH 2; attack 4 */
    { { {  -79,  58,  24,  90 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: follow-up of CATCH 2; attack 5 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  17,  87,  13 },  {  -55,  28,  78,  21 } } },  /* 4: S PUNCH A; attack 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -55,  12,  84,  14 },  {  -47,  22,  76,  12 } } },  /* 5: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -83,  31,  74,   5 },  {    0,   0,   0,   0 } } },  /* 6: S PUNCH B; attack 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  31,  74,   5 },  {    0,   0,   0,   0 } } },  /* 7: S PUNCH B */
    { { {  -24,  22,  84,  18 },  {  -10,  21,  99,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script); attack 9, 57 */
    { { {  -64,  56,  62,  15 },  {  -48,  30,  77,   9 },  {  -37,  22,  86,   7 },  {  -26,  15,  93,   6 } } },  /* 9: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -55,  27,  63,   4 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -90,  21,  99,  13 },  {    0,   0,   0,   0 },  {  -73,  20,  94,  13 },  {  -62,  33,  88,  14 } } },  /* 11: M PUNCH B; attack 10 */
    { { {  -82,  16, 101,   6 },  {  -72,  19,  96,   8 },  {  -58,  31,  90,  10 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -44,  23,  73,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH A; attack 11 */
    { { {  -38,  21, 105,  40 },  {  -28,  21, 141,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A; attack 12 */
    { { {  -11,  16, 134,  25 },  {    0,   0,   0,   0 },  {  -19,  14, 111,  28 },  {    0,   0,   0,   0 } } },  /* 15: L PUNCH A */
    { { {  -74,  22,  42,  20 },  {  -60,  22,  34,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script); attack 13, 59 */
    { { {  -66,  16,  54,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -43,  25,  59,  24 },  {  -35,  18,  38,  22 } } },  /* 18: S KICK A; attack 14 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -81,  14,  11,  18 },  {  -72,  16,  23,  15 } } },  /* 19: S KICK B; attack 15 */
    { { {  -43,  25,  59,  24 },  {  -35,  18,  38,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: M KICK A; attack 16 */
    { { { -103,  30,  45,  17 },  {    0,   0,   0,   0 },  {  -73,  19,  45,  17 },  {    0,   0,   0,   0 } } },  /* 21: M KICK B; attack 17 */
    { { {  -97,  30,  52,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: M KICK B */
    { { {  -33,  25,  58,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: L KICK A; attack 18 */
    { { {  -63,  22,  95,  26 },  {  -50,  20,  81,  27 },  {  -36,  19,  69,  25 },  {    0,   0,   0,   0 } } },  /* 24: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script); attack 19 */
    { { {  -84,  13,  88,   8 },  {  -72,  20,  84,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script); attack 20, 60, 78 */
    { { {  -82,  29,  79,  18 },  {    0,   0,   0,   0 },  {  -51,  18,  75,  17 },  {    0,   0,   0,   0 } } },  /* 26: L KICK B, follow-up of M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -93,  59,  35,   6 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A; attack 21, 44 */
    { { {  -91,  34,  45,  11 },  {  -62,  21,  41,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A; attack 22 */
    { { {  -83,  26,  45,  11 },  {  -62,  21,  41,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI P A */
    { { {  -53,  20,  38,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI P A */
    { { {  -41,  22,  94,  27 },  {    0,   0,   0,   0 },  {  -42,  10,  65,  29 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI P A; attack 23 */
    { { {  -41,  13,  93,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -73,  19,  55,  21 },  {  -61,  18,  65,  21 } } },  /* 33: F JUMP P S A; attack 28 */
    { { {  -73,  19,  55,  21 },  {  -61,  18,  65,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP P M A; attack 29 */
    { { {  -61,  18,  55,  17 },  {  -47,  17,  65,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: F JUMP P L A; attack 30 */
    { { {  -52,  13,  69,  13 },  {  -42,  12,  78,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: F JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  20,  48,  24 },  {    0,   0,   0,   0 } } },  /* 37: F JUMP K S A; attack 31 */
    { { {  -83,  26,  67,   8 },  { -101,  19,  65,   5 },  {  -57,  30,  70,   8 },  {    0,   0,   0,   0 } } },  /* 38: F JUMP K M A; attack 32 */
    { { {  -83,  26,  67,   8 },  {  -94,  11,  65,   6 },  {  -57,  30,  70,   8 },  {    0,   0,   0,   0 } } },  /* 39: F JUMP K M A */
    { { {  -79,  12,  34,  11 },  {  -67,  14,  41,   9 },  {  -53,  12,  48,   9 },  {  -40,   9,  54,   7 } } },  /* 40: F JUMP K L A; attack 33 */
    { { {  -76,  10,  36,   9 },  {  -67,  10,  42,   8 },  {  -56,   9,  48,   8 },  {  -46,   9,  53,   8 } } },  /* 41: F JUMP K L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  56,   0,   8 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI K A; attack 24 */
    { { {  -93,  17,   0,  14 },  {  -82,  22,   0,  20 },  {  -67,  45,   0,  22 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI K A; attack 25 */
    { { { -104,  42,  10,  20 },  {    0,   0,   0,   0 },  {  -61,  34,  12,  21 },  {    0,   0,   0,   0 } } },  /* 44: KAGAMI K A; attack 26 */
    { { { -106,  49,   0,  10 },  {    0,   0,   0,   0 },  {  -78,  47,   8,   9 },  {    0,   0,   0,   0 } } },  /* 45: KAGAMI K A; attack 27 */
    { { {  -99,  42,   0,  10 },  {    0,   0,   0,   0 },  {  -78,  47,   8,   9 },  {    0,   0,   0,   0 } } },  /* 46: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  26,  31,  29 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 3 S: not started by a command; attack 77 */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: not used by a script */
    { { { -103,  25,  59,  42 },  {  -93,  14,  34,  25 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1); attack 34 */
    { { {  -75,  34, 123,  25 },  {  -90,  15, 106,  27 },  { -101,  12,  81,  35 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1); attack 35 */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: not used by a script */
    { { { -103,  25,  59,  42 },  {  -93,  14,  34,  25 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1); attack 37 */
    { { {  -75,  34, 123,  25 },  {  -90,  15, 106,  27 },  { -101,  12,  81,  35 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    { { { -103,  25,  59,  42 },  {  -93,  14,  34,  25 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1); attack 40 */
    { { {  -75,  34, 123,  25 },  {  -90,  15, 106,  27 },  { -101,  12,  81,  35 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { { -103,  25,  59,  42 },  {  -93,  14,  34,  25 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1); attack 41 */
    { { {  -75,  34, 123,  25 },  {  -90,  15, 106,  27 },  { -101,  12,  81,  35 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1); attack 42, 43 */
    { { {  -95,  27,  41,  16 },  {  -82,  24,  47,  16 },  {  -62,  21,  55,  15 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2; attack 45, 62, 73, 74 ... */
    { { {  -93,  23,  43,  13 },  {  -79,  24,  49,  13 },  {  -62,  21,  56,  13 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -91,  20,  45,  11 },  {  -77,  20,  51,  11 },  {  -62,  21,  57,  11 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1; attack 76 */
    { { { -107,  17,  96,  13 },  {  -94,  18,  76,  26 },  {  -74,  29,  60,  33 },  {  -46,  26,  51,  36 } } },  /* 63: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command; attack 51 */
    { { {  -89,  16,  86,  14 },  {    0,   0,   0,   0 },  {  -74,  29,  82,  13 },  {  -46,  26,  74,  14 } } },  /* 64: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  36,  82,  13 },  {  -46,  26,  74,  14 } } },  /* 65: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {  -49,  29,  53,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 10 SP: not started by a command; attack 61 */
    { { {  -55,  39,  12,  85 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: not used by a script */
    { { { -106,  26, 106,  11 },  {  -94,  26,  83,  26 },  {  -81,  28,  70,  35 },  {  -62,  33,  56,  45 } } },  /* 68: ATTACK 9 S: after SA III 23623+K (plain script); attack 58 */
    { { {  -66,  17,  38,  18 },  {  -49,  22,  38,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: M KICK C; attack 52 */
    { { {  -76,  19,   0,  26 },  {  -66,  19,  10,  25 },  {  -49,  27,  24,  17 },  {    0,   0,   0,   0 } } },  /* 70: M KICK C */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1); attack 63, 66, 69 */
    { { { -107,  29,  59,  42 },  {  -97,  19,  30,  29 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1); attack 64, 67, 70, 71 */
    { { {  -75,  38, 108,  48 },  {  -90,  17,  84,  57 },  { -106,  16,  68,  56 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1); attack 65, 68, 72 */
    { { {  -82,  29,  70,  25 },  {    0,   0,   0,   0 },  {  -51,  29,  60,  27 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 9 S: after SA III 23623+K (plain script) */
    { { { -113,  52,  41,  36 },  { -108,  47,  25,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: not used by a script */
    { { { -103,  25,  59,  42 },  {  -93,  14,  34,  25 },  {  -78,  29,  34,  52 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 9 M: after SA III 23623+K (plain script); attack 61 */
    { { {  -75,  34, 123,  25 },  {  -90,  15, 106,  27 },  { -101,  12,  81,  35 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 9 M: after SA III 23623+K (plain script); attack 62 */
    { { {  -63,  52,   0, 114 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 9 S: after SA III 23623+K (plain script); attack 56 */
};

const CATCH_BOX remy_cat_box[2] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -30,    9,    0,   16 } },  /* 1: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
};

const CAUGHT_BOX remy_cau_box[7] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +93 */
    { {  -25,   46,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +45 */
    { {  -21,   42,   56,   50 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, ATTACK 6 L: 214+K light (routine Att_PL20_AT2) +29 */
    { {  -21,   42,   45,   46 } },  /* 4: AIR NORMAL, BODY SLAM, IPPONZEOI +27 */
    { {  -49,   47,   42,   50 } },  /* 5: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +3 */
    { {  -29,   50,    0,    8 } },  /* 6: KAGAMI P A, KAGAMI K A */
};

