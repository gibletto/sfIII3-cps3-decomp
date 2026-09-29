/*
 * YUN_ATTBOX.C  Yun's attack, catch and caught boxes
 *
 * Selected per animation frame through yun_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX yun_att_box[120] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -39,  32,  50,  16 },  {  -31,  40,  22,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: not used by a script */
    { { {    0,   0,   0,   0 },  {  -73,  31,  95,  21 },  {  -52,  34,  55,  39 },  {    0,   0,   0,   0 } } },  /* 2: M KICK A, follow-up of APPEAR USE; attack 2 */
    { { {  -80,  22,  54,  22 },  {  -56,  22,  51,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command; attack 39 */
    { { {  -76,  26,  54,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -84,  26,  62,  12 },  {  -56,  26,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { {  -76,  64,  66,  10 },  {  -38,  21,  51,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: not used by a script */
    { { {  -63,  46,  53,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name; attack 7, 101, 154 */
    { { {  -53,  35,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, follow-up of ZANNEN 4; attack 8, 100 */
    { { {  -60,  48,  45,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, follow-up of JUDGMENT WAIT; attack 9, 102 */
    { { {  -83,  68,  57,  13 },  {  -60,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B, follow-up of ZANNEN 6; attack 10, 104 */
    { { {  -86,  32,  66,  12 },  {  -60,  32,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: follow-up of M PUNCH A, M PUNCH B; attack 11 */
    { { {  -84,  40,  18,  12 },  {  -60,  40,  30,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {  -76,  36,  20,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  48,  50,   8 },  {    0,   0,   0,   0 } } },  /* 14: follow-up of WIN 2, KAGAMI P A; attack 14, 109 */
    { { {  -80,  57,  47,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4; attack 47, 112, 156 */
    { { {  -74,  43,  49,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -73,  56,   0,   8 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A, follow-up of WIN 5; attack 15, 113 */
    { { {  -84,  50,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  36,  49,   9 },  {    0,   0,   0,   0 } } },  /* 19: follow-up of WIN 2, KAGAMI P A */
    { { {  -70,  53,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: M KICK C, follow-up of JUDGMENT WAIT, no name; attack 18, 107 */
    { { {  -68,  49,  40,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -42,  14,  80,  29 },  {  -30,  15,  62,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -83,  38,  53,  14 },  {  -49,  35,  56,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -68,  46,  58,  11 },  {  -50,  40,  44,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +2; attack 20, 21, 87, 88 ... */
    { { {  -76,  49,  68,  10 },  {  -24,  16,  41,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: ATTACK 12 M: not started by a command; attack 97 */
    { { {  -64,  53,  46,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command; attack 22, 76, 80 */
    { { {  -71,  25,  53,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command; attack 23, 80 */
    { { {  -36,  24,  34,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE; attack 2, 77, 106 */
    { { {  -96,  73,  52,  28 },  {  -57,  39,  42,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +1; attack 25, 82, 83, 129 ... */
    { { {  -69,  34,  44,  80 },  {  -64,  80,   9,  73 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command; attack 26, 27, 75 */
    { { {  -52,  18,  84,  32 },  {  -36,  18,  68,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 5 S: not started by a command; attack 27 */
    { { {  -57,  52,  16,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 2 SP: EX 214+PP (plain script); attack 57, 60 */
    { { {  -47,  43,   0,  78 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 SP: EX 214+PP (plain script) */
    { { {  -58,  33, 112,  17 },  {  -42,  32,  60,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command; attack 56, 58, 61 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -37,  14,  66,  17 },  {    0,   0,   0,   0 } } },  /* 35: F JUMP P S A, follow-up of SEAN BALL HIT; attack 65, 122 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -37,  23,  70,  23 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P S A, follow-up of JUDGMENT LOSE; attack 31, 116 */
    { { {  -50,  29,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1; attack 32, 66, 117, 123 */
    { { {    0,   0,   0,   0 },  {  -48,  14,  62,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -74,  32,  70,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -48,  29,  57,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -54,  24,  66,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name */
    { { {  -62,  41,  91,  16 },  {  -47,  27,  60,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: L PUNCH A, follow-up of JUDGMENT WAIT; attack 41, 103 */
    { { {  -57,  21,  85,  16 },  {  -47,  39,  66,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: L PUNCH A, follow-up of JUDGMENT WAIT; attack 9 */
    { { {  -75,  59,  56,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: L PUNCH B, follow-up of ZANNEN 6 */
    { { {  -78,  32,  64,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: follow-up of M PUNCH A, M PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  14,  16,  20 },  {  -52,  33,   0,  42 } } },  /* 46: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7; attack 12, 105, 153 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  33,   8,  28 },  {    0,   0,   0,   0 } } },  /* 47: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7; attack 12 */
    { { {  -54,  18,  89,  19 },  {  -37,  17,  65,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE; attack 2 */
    { { {  -64,  20,  48,  16 },  {  -52,  20,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: F JUMP P L A, follow-up of BONUS WIN 1; attack 67, 124 */
    { { {  -60,  18,  52,  14 },  {  -50,  18,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: F JUMP P L A, follow-up of BONUS WIN 1 */
    { { {  -54,  40,  56,  29 },  {  -45,  34,   0,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: not started by a command; attack 37 */
    { { {  -64,  59,  58,  25 },  {  -54,  31,   0,  77 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command; attack 38 */
    { { {  -47,  22,  85,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: not started by a command; attack 13 */
    { { {  -76,  54,  48,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI P A, follow-up of WIN 3; attack 45, 110 */
    { { {  -65,  44,  49,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: KAGAMI P A, follow-up of WIN 3 */
    { { {  -51,  27,  38,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4; attack 46, 111, 155 */
    { { {  -97,  25,   0,   8 },  {  -72,  34,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: KAGAMI K A, follow-up of WIN 6; attack 48, 114 */
    { { {  -88,  65,   0,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: not used by a script */
    { { {  -76,  53,   6,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -86,  22,  53,  28 },  {  -62,  30,  51,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command; attack 40 */
    { { {  -76,  25,  53,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -84,  40,  64,  12 },  {  -60,  40,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: not used by a script */
    { { {  -72,  32,  62,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: not used by a script */
    { { {  -44,  20,  90,  30 },  {  -29,  12,  58,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 2 SP: EX 214+PP (plain script); attack 59, 62 */
    { { {  -26,  35,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: not used by a script */
    { { {  -32,  22,  42,  18 },  {  -24,  20,  32,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: not used by a script */
    { { {  -86,  65,  86,   8 },  {  -52,  34,  78,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: not used by a script */
    { { {  -82,  40,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: not used by a script */
    { { {  -71,  51,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -81,  67,  87,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: not used by a script */
    { { {  -82,  40,  86,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: not used by a script */
    { { {  -89,  77,  79,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1; attack 33, 73, 118, 172 */
    { { {  -86,  44,  84,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -67,  20,  92,  18 },  {  -48,  24,  43,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2; attack 36, 72, 121, 127 */
    { { {  -56,  32,  77,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2; attack 72 */
    { { {  -53,  39,  83,  19 },  {  -34,  14,  53,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: not used by a script */
    { { {  -67,  20,  92,  18 },  {  -56,  38,  62,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -71,  51,  82,  12 },  {    0,   0,   0,   0 } } },  /* 78: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1; attack 34, 68, 119, 125 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  46,  84,   9 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    { { {  -82,  21,  43,  13 },  {  -61,  35,  52,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1; attack 69, 120, 126 */
    { { {  -76,  15,  43,  13 },  {  -61,  35,  52,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 82: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1; attack 71, 128 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1 */
    { { {  -66,  47,  83,  34 },  {  -39,  27,  51,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 144 */
    { { {  -99,  77,  45,  29 },  {  -46,  27,  32,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: L KICK A, follow-up of follow-up of S KICK A, no name +1; attack 42, 78, 108, 151 */
    { { {  -80,  56,  59,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    { { {  -43,  51,   0,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 13 SP: not started by a command; attack 54 */
    { { {  -57,  68,   0,  82 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 13 SP: not started by a command; attack 55 */
    { { {  -79,  53,  41,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  24,  33,  30 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 12 L: not started by a command, not started by a command; attack 131, 173 */
    { { {  -85,  88,  86,  38 },  {  -71,  74,  14,  71 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 13 SP: not started by a command; attack 56 */
    { { {  -82,  42,  98,  19 },  {  -76,  48,  57,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: follow-up of S KICK A */
    { { {  -36,  20,  25,  14 },  {  -36,  20,  12,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: EX 623+PP (routine Att_SLIDE_and_JUMP), not started by a command; attack 139, 149 */
    { { {  -50,  22,  63,  17 },  {  -42,  15,  39,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy (routine Att_SLIDE_and_JUMP) +2; attack 140, 141, 142, 143 ... */
    { { {  -77,  51,  77,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: not used by a script */
    { { {  -71,  45,  77,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: not used by a script */
    { { {  -62,  31,  59,  46 },  {  -54,  30,  31,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -50,  48,  63,  38 },  {  -50,  30,  34,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 146 */
    { { {  -74,  34,  59,  46 },  {  -59,  36,  31,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: not used by a script */
    { { { -106,  46,  70,  14 },  {  -59,  31,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: not used by a script */
    { { {  -95,  20,  51,  14 },  {    0,   0,   0,   0 },  {   24,  20,  51,  15 },  {  -93,  44,  48,  20 } } },  /* 102: L PUNCH C, follow-up of APPEAR USE; attack 170, 171 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  16,  51,  14 },  {   29,  20,  51,  14 } } },  /* 103: L PUNCH C, follow-up of APPEAR USE */
    { { {  -96,  17,  75,  11 },  {    0,   0,   0,   0 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 } } },  /* 104: M KICK B, follow-up of ZANNEN 8 */
    { { { -102,  19,  77,  12 },  {  -83,  49,  67,  14 },  {  -55,  20,  54,  12 },  {    0,   0,   0,   0 } } },  /* 105: M KICK B, follow-up of ZANNEN 8; attack 1, 169 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -91,  31,  71,  12 },  {  -63,  27,  60,  15 } } },  /* 106: not used by a script */
    { { {  -48,  24,  90,  27 },  {  -35,  24,  66,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2; attack 157, 159, 161, 163 ... */
    { { {  -58,  24,  81,  27 },  {  -43,  24,  69,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2; attack 158, 160, 162, 165 ... */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  39,  39,  15 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { {  -96,  30,  35,  15 },  {    0,   0,   0,   0 },  {  -66,  39,  27,  17 },  {    0,   0,   0,   0 } } },  /* 110: not used by a script */
    { { { -100,  23,  22,  13 },  {    0,   0,   0,   0 },  {  -77,  48,  16,  16 },  {    0,   0,   0,   0 } } },  /* 111: follow-up of WIN 7, KAGAMI K A; attack 50, 115 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  52,  12,  11 },  {    0,   0,   0,   0 } } },  /* 112: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -53,  29,  56,  19 },  {    0,   0,   0,   0 } } },  /* 113: S PUNCH A, follow-up of ZANNEN 2; attack 6, 99 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -98,  24,  61,  10 },  {    0,   0,   0,   0 } } },  /* 114: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  32,  60,  10 },  {    0,   0,   0,   0 } } },  /* 115: S PUNCH B, follow-up of ZANNEN 3; attack 6, 99 */
    { { {  -81,  54,  46,  34 },  {  -68,  25,  -4,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP); attack 37 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 117: F JUMP K S B; attack 71 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -16,  20,  22,   7 },  {    0,   0,   0,   0 } } },  /* 118: F JUMP K S B */
    { { {  -65,  34,  59,  46 },  {  -59,  36,  31,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP); attack 145 */
};

const CATCH_BOX yun_cat_box[3] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -39,   18,    0,   16 } },  /* 1: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { {  -32,   12,    0,   16 } },  /* 2: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
};

const CAUGHT_BOX yun_cau_box[19] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   16 } },  /* 1: no name, HURIMUKI, DASH HUMIKOMI +131 */
    { {  -25,   46,    0,    8 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +45 */
    { {  -21,   42,   51,   44 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +50 */
    { {  -21,   42,   41,   37 } },  /* 4: M KICK C, follow-up of JUDGMENT WAIT, follow-up of APPEAR USE +5 */
    { {  -21,   42,   34,   36 } },  /* 5: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
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
    { {  -29,   50,    0,    8 } },  /* 18: KAGAMI P A, KAGAMI K A, follow-up of WIN 5 */
};

