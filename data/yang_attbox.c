/*
 * YANG_ATTBOX.C  Yang's attack, catch and caught boxes
 *
 * Selected per animation frame through yang_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX yang_att_box[116] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -39,  32,  50,  16 },  {  -31,  40,  22,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: not used by a script */
    { { {    0,   0,   0,   0 },  {  -73,  31,  95,  21 },  {  -52,  34,  55,  39 },  {    0,   0,   0,   0 } } },  /* 2: M KICK A, no name; attack 1, 106 */
    { { {  -80,  22,  54,  22 },  {  -56,  22,  51,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: not used by a script */
    { { {  -76,  26,  54,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -84,  26,  62,  12 },  {  -56,  26,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  64,  66,  10 },  {  -38,  21,  51,  17 } } },  /* 6: S PUNCH A, follow-up of ZANNEN 2; attack 6, 99 */
    { { {  -64,  40,  51,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, no name; attack 7, 101 */
    { { {  -53,  35,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, follow-up of ZANNEN 4; attack 8, 100 */
    { { {  -60,  48,  45,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of JUDGMENT WAIT; attack 9, 102 */
    { { {  -83,  68,  57,  13 },  {  -60,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6; attack 11, 104 */
    { { {  -86,  32,  66,  12 },  {  -60,  32,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B; attack 10 */
    { { {  -84,  40,  18,  12 },  {  -60,  40,  30,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {  -76,  36,  20,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  54,  50,   8 },  {    0,   0,   0,   0 } } },  /* 14: follow-up of WIN 2, KAGAMI P A; attack 14, 109 */
    { { {  -88,  65,  47,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: not used by a script */
    { { {  -74,  36,  50,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -73,  56,   0,   8 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 15 */
    { { {  -84,  50,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  36,  49,   9 },  {    0,   0,   0,   0 } } },  /* 19: follow-up of WIN 2, KAGAMI P A */
    { { {  -70,  53,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: M KICK C, follow-up of JUDGMENT WAIT, no name; attack 18, 107 */
    { { {  -68,  49,  40,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -42,  14,  80,  29 },  {  -30,  15,  62,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -83,  38,  53,  14 },  {  -49,  35,  56,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -68,  46,  58,  11 },  {  -50,  40,  44,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: ATTACK 12 M: not started by a command; attack 98 */
    { { {  -76,  49,  68,  10 },  {  -24,  16,  41,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: ATTACK 12 M: not started by a command; attack 97 */
    { { {  -64,  53,  46,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command, follow-up of follow-up of M PUNCH A, M PUNCH B; attack 22, 76, 80 */
    { { {  -71,  25,  53,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command; attack 22, 23, 80 */
    { { {  -36,  24,  34,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: follow-up of S KICK A; attack 77 */
    { { {  -96,  73,  52,  28 },  {  -57,  39,  42,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: follow-up of APPEAR USE, ATTACK 5 S: not started by a command; attack 25, 129, 130 */
    { { {  -69,  34,  44,  80 },  {  -64,  80,   9,  73 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI); attack 26, 27, 75 */
    { { {  -52,  18,  84,  32 },  {  -36,  18,  68,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 5 S: not started by a command; attack 27 */
    { { {  -57,  52,  16,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4; attack 28, 57, 60, 81 ... */
    { { {  -47,  43,   0,  78 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4; attack 81, 133 */
    { { {  -58,  33, 112,  17 },  {  -42,  32,  60,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5; attack 29, 56, 58, 61 ... */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -35,  14,  69,  15 },  {    0,   0,   0,   0 } } },  /* 35: F JUMP P S A, follow-up of SEAN BALL HIT; attack 65, 122 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -37,  23,  70,  23 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P S A, follow-up of JUDGMENT LOSE; attack 31, 116 */
    { { {  -50,  29,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1; attack 32, 66, 117, 123 */
    { { {    0,   0,   0,   0 },  {  -48,  14,  62,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  32,  70,   6 },  {    0,   0,   0,   0 } } },  /* 39: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -48,  29,  57,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -56,  24,  51,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: M PUNCH B, no name */
    { { {  -62,  41,  91,  16 },  {  -47,  27,  60,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: L PUNCH A, follow-up of JUDGMENT WAIT; attack 41, 103 */
    { { {  -57,  21,  85,  16 },  {  -47,  39,  66,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: L PUNCH A, follow-up of JUDGMENT WAIT; attack 9 */
    { { {  -75,  59,  56,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -78,  32,  64,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: L PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  14,  16,  20 },  {  -52,  33,   0,  42 } } },  /* 46: S KICK A, follow-up of ZANNEN 7; attack 12, 105 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  33,   8,  28 },  {    0,   0,   0,   0 } } },  /* 47: S KICK A, follow-up of ZANNEN 7; attack 12 */
    { { {  -54,  18,  89,  19 },  {  -37,  17,  65,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: M KICK A, follow-up of S KICK A, no name; attack 2 */
    { { {  -64,  20,  48,  16 },  {  -52,  20,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: F JUMP P L A, follow-up of BONUS WIN 1; attack 67, 124 */
    { { {  -60,  18,  52,  14 },  {  -50,  18,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: F JUMP P L A, follow-up of BONUS WIN 1 */
    { { {  -54,  40,  56,  29 },  {  -45,  34,   0,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: not used by a script */
    { { {  -64,  59,  58,  25 },  {  -54,  31,   0,  77 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: no box */
    { { {  -78,  57,  48,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI P A, follow-up of WIN 3; attack 45, 110 */
    { { {  -65,  44,  49,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: KAGAMI P A, follow-up of WIN 3 */
    { { {  -93,  24,  29,  19 },  {  -67,  43,  29,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: KAGAMI P A, follow-up of WIN 4; attack 46, 111 */
    { { {  -97,  25,   0,   8 },  {  -72,  34,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: follow-up of WIN 5, follow-up of WIN 6, KAGAMI K A +1; attack 48, 113, 156 */
    { { {  -88,  65,   0,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7, KAGAMI K A; attack 50, 115, 157 */
    { { {  -76,  53,   6,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -86,  22,  53,  28 },  {  -62,  30,  51,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: not used by a script */
    { { {  -76,  25,  53,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {  -84,  40,  64,  12 },  {  -60,  40,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: not used by a script */
    { { {  -72,  32,  62,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: not used by a script */
    { { {  -44,  20,  90,  30 },  {  -29,  12,  58,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4; attack 30, 59, 62, 81 ... */
    { { {  -26,  35,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 11 SP: not started by a command +1; attack 96 */
    { { {  -32,  22,  42,  18 },  {  -24,  20,  32,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: not used by a script */
    { { {  -86,  65,  86,   8 },  {  -52,  34,  78,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: not used by a script */
    { { {  -82,  40,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: not used by a script */
    { { {  -71,  51,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -81,  67,  87,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: not used by a script */
    { { {  -82,  40,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: not used by a script */
    { { {  -89,  77,  79,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: V JUMP P L A, follow-up of JUDGMENT LOSE; attack 33, 118 */
    { { {  -86,  44,  84,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -67,  20,  92,  18 },  {  -48,  24,  43,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3; attack 4, 36, 72, 121 ... */
    { { {  -56,  32,  77,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2; attack 72 */
    { { {  -53,  39,  83,  19 },  {  -34,  14,  53,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: not used by a script */
    { { {  -67,  20,  92,  18 },  {  -56,  38,  62,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -71,  51,  82,  12 },  {    0,   0,   0,   0 } } },  /* 78: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1; attack 34, 68, 119, 125 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  46,  84,   9 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    { { {  -82,  21,  43,  13 },  {  -61,  35,  52,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1; attack 69 */
    { { {  -76,  15,  43,  13 },  {  -61,  35,  52,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 82: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1; attack 71, 128 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M B, F JUMP K L B, follow-up of F JUMP K M A +2 */
    { { {  -39,  49,  66,  22 },  {  -52,  28,  43,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: KAGAMI P A, follow-up of WIN 4; attack 112 */
    { { {  -99,  77,  45,  29 },  {  -46,  27,  32,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: follow-up of follow-up of S KICK A, no name; attack 78, 108 */
    { { {  -80,  56,  59,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: follow-up of follow-up of S KICK A, no name */
    { { {  -43,  51,   0,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI); attack 54 */
    { { {  -57,  68,   0,  82 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI); attack 55 */
    { { {  -79,  53,  41,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: not used by a script */
    { { {  -60,  33,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: KAGAMI P A, follow-up of WIN 4; attack 47 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  26,  33,  30 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 12 L: not started by a command, not started by a command; attack 131, 165 */
    { { {  -85,  88,  86,  38 },  {  -71,  74,  14,  71 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI); attack 56 */
    { { {  -82,  42,  98,  19 },  {  -76,  48,  57,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: follow-up of S KICK A */
    { { {  -77,  51,  77,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: not used by a script */
    { { {  -71,  45,  77,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -32,  18,  96,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: not started by a command; attack 137 */
    { { {  -67,   7,  28,  23 },  {  -59,  27,  28,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 138, 141, 144, 147 ... */
    { { {  -91,  25,  48,  20 },  {  -65,  35,  41,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 139, 142, 145, 148 */
    { { {  -89,  17,  39,  25 },  {  -72,  24,  39,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1; attack 140, 143, 146, 149 */
    { { {  -75,  17,  37,  26 },  {  -57,  15,  37,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -89,  22,  40,  31 },  {  -65,  43,  40,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI); attack 152 */
    { { {  -97,  26,  41,  24 },  {  -71, 211,  41,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 8 S: not started by a command; attack 153, 154, 155 */
    { { {  -38,  20,  16,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: follow-up of F JUMP K M A; attack 73 */
    { { { -106,  46,  70,  14 },  {  -59,  31,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: not used by a script */
    { { { -122,  50,  77,  11 },  {  -77,  34,  61,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: not used by a script */
    { { {    0,   0,   0,   0 },  {   -1,   0,  -1,   0 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 } } },  /* 106: not used by a script */
    { { { -102,  19,  77,  12 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 },  {   -1,   0,   0,   0 } } },  /* 107: not used by a script */
    { { {  -96,  17,  75,  11 },  {    0,   0,   0,   0 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 } } },  /* 108: M KICK B */
    { { { -109,  42,  65,  12 },  {  -69,  31,  56,  15 },  {  -54,  24,  51,  12 },  {    0,   0,   0,   0 } } },  /* 109: L KICK A; attack 42 */
    { { { -103,  35,  65,  12 },  {  -67,  29,  56,  15 },  {  -54,  24,  51,  12 },  {    0,   0,   0,   0 } } },  /* 110: L KICK A; attack 42 */
    { { {  -36,  24,  34,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: M KICK A */
    { { { -102,  19,  77,  12 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 },  {    0,   0,   0,   0 } } },  /* 112: M KICK B; attack 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 113: F JUMP K S B; attack 71 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 114: F JUMP K S B */
    { { {  -80,  20,   4,  11 },  {  -64,  17,  14,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: KAGAMI P A; attack 45 */
};

const CATCH_BOX yang_cat_box[3] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -39,   18,    0,   16 } },  /* 1: TUKAMIKAKARI C, TUKAMIKAKARI A, TUKAMIKAKARI B */
    { {  -32,   12,    0,   16 } },  /* 2: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
};

const CAUGHT_BOX yang_cau_box[19] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +123 */
    { {  -25,   46,    0,    8 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +46 */
    { {  -20,   40,   51,   44 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +49 */
    { {  -21,   42,   41,   37 } },  /* 4: M KICK C, follow-up of JUDGMENT WAIT, follow-up of APPEAR USE +2 */
    { {  -21,   42,   34,   36 } },  /* 5: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    { {  -44,   65,    0,   16 } },  /* 6: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    { {  -42,   48,    0,   74 } },  /* 7: not used by a script */
    { {  -14,   46,   94,   28 } },  /* 8: not used by a script */
    { {    0,    0,    0,    0 } },  /* 9: no box */
    { {    0,    0,    0,    0 } },  /* 10: no box */
    { {   -4,   48,    0,   74 } },  /* 11: not used by a script */
    { {   -4,   48,   31,   74 } },  /* 12: not used by a script */
    { {  -32,   48,   16,   74 } },  /* 13: not used by a script */
    { {  -19,   48,   16,   74 } },  /* 14: not used by a script */
    { {   -6,   48,   16,   74 } },  /* 15: not used by a script */
    { {  -17,   48,   15,   74 } },  /* 16: not used by a script */
    { {  -17,   42,   35,   32 } },  /* 17: BODY SLAM, IPPONZEOI, TOMOE RYU +28 */
    { {  -29,   50,    0,    8 } },  /* 18: KAGAMI P A, KAGAMI K A */
};

