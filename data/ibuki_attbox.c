/*
 * IBUKI_ATTBOX.C  Ibuki's attack, catch and caught boxes
 *
 * Selected per animation frame through ibuki_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX ibuki_att_box[129] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -54,  24,  64,  10 },  {  -37,  25,  60,   8 } } },  /* 1: no name, S PUNCH A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -85,  12,  63,  16 },  {  -73,  52,  64,  10 } } },  /* 2: S PUNCH B; attack 2 */
    { { {  -87,  23,  41,  24 },  {  -64,  41,  53,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M KICK C, follow-up of M KICK A; attack 3, 174 */
    { { {  -62,  18,  14,  16 },  {  -46,  15,  26,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M KICK C, follow-up of M KICK A; attack 4, 174 */
    { { {  -95,  38,   0,   7 },  {  -58,  47,   0,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A; attack 5, 126 */
    { { {  -60,  23,  86,  28 },  {  -46,  18,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: V JUMP K L A, F JUMP K L A; attack 6 */
    { { {  -82,  35,  41,  22 },  {  -47,  31,  44,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: V JUMP K L A, F JUMP K L A; attack 7 */
    { { {  -62,  24,   9,  22 },  {  -43,  20,  23,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { { -106,  28,  44,  25 },  {  -77,  55,  56,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L KICK C; attack 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  19,  24,  17 },  {  -33,  19,  40,  16 } } },  /* 10: F JUMP K S A; attack 10 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -39,  19,  32,  15 },  {    0,   0,   0,   0 } } },  /* 11: F JUMP K S A */
    { { {  -88,  33,  40,  16 },  {    0,   0,   0,   0 },  {  -55,  66,  42,  13 },  {    0,   0,   0,   0 } } },  /* 12: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A; attack 11, 127 */
    { { {  -76,  30,  41,  16 },  {    0,   0,   0,   0 },  {  -46,  58,  45,  12 },  {    0,   0,   0,   0 } } },  /* 13: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A; attack 12, 128 */
    { { {  -48,  22,  67,  15 },  {  -40,  16,  53,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M PUNCH C, follow-up of S PUNCH A; attack 13 */
    { { {  -62,  25,  90,  21 },  {    0,   0,   0,   0 },  {  -58,  31,  71,  26 },  {    0,   0,   0,   0 } } },  /* 15: M PUNCH C, follow-up of S PUNCH A; attack 14 */
    { { {  -50,  14,  88,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M PUNCH C, follow-up of S PUNCH A; attack 15 */
    { { {  -84,  22,  64,  12 },  {  -60,  22,  65,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: M PUNCH A; attack 16 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  41,  64,   9 },  {    0,   0,   0,   0 } } },  /* 18: M PUNCH A; attack 17 */
    { { {  -43,  21,  71,  16 },  {  -34,  16,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: L PUNCH A; attack 18 */
    { { {  -55,  21,  55,  17 },  {  -48,  27,  67,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: L PUNCH A; attack 19 */
    { { {  -47,  25,  34,  24 },  {  -43,  13,  53,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L PUNCH A; attack 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -102,  40,  50,   8 },  {  -70,  40,  46,   8 } } },  /* 22: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  14,  45,  22 },  {  -58,  48,  49,   7 } } },  /* 23: S KICK A; attack 21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -84,  20,  11,  24 },  {  -75,  32,  28,  11 } } },  /* 24: S KICK B; attack 23, 113 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  20,  11,  24 },  {  -63,  26,  28,  11 } } },  /* 25: S KICK B; attack 24, 114 */
    { { {  -44,  22,  68,  20 },  {  -36,  18,  56,  16 },  {  -41,  18,  41,  27 },  {    0,   0,   0,   0 } } },  /* 26: M KICK B, follow-up of S KICK A; attack 25, 140 */
    { { {  -94,  84,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: M KICK A; attack 26 */
    { { {  -46,  18,  84,  52 },  {  -60,  18,  70,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: L KICK A; attack 27 */
    { { {  -34,  16, 102,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: L KICK A; attack 28 */
    { { {  -66,  28,  50,  14 },  {  -48,  28,  56,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L PUNCH B; attack 29 */
    { { {  -49,  22,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: L PUNCH B; attack 30 */
    { { {  -46,  18,  64,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: M KICK B, follow-up of S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  32,  36,   6 },  {  -50,  32,  33,   6 } } },  /* 33: KAGAMI P A; attack 32 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  32,  36,   8 },  {    0,   0,   0,   0 } } },  /* 34: no name, KAGAMI P A */
    { { {  -59,  21,  80,  29 },  {  -45,  17,  67,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: KAGAMI P A, no name; attack 33, 172, 175 */
    { { {  -52,  14,  86,  14 },  {  -44,  14,  78,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: KAGAMI P A, no name; attack 34, 172, 176 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -85,  50,   8,   8 },  {  -64,  50,  12,   7 } } },  /* 37: KAGAMI K A; attack 35 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  54,  10,   8 },  {    0,   0,   0,   0 } } },  /* 38: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  50,  74,  11 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP P S A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -81,  39,  69,  14 },  {  -42,  32,  73,  12 } } },  /* 40: V JUMP P S A; attack 36 */
    { { {  -75,  30,  46,  24 },  {  -45,  23,  61,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP P L A, follow-up of F JUMP P S A; attack 39, 133 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -88,  32,  45,  17 },  {  -56,  43,  48,  11 } } },  /* 42: V JUMP K S A; attack 43 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  24,  48,  15 },  {  -51,  29,  48,  10 } } },  /* 43: V JUMP K S A, V JUMP K M A; attack 107 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  17,  28,  20 },  {  -55,  17,  46,  21 } } },  /* 44: F JUMP P S A; attack 40 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  16,  41,  13 },  {    0,   0,   0,   0 } } },  /* 45: F JUMP P S A */
    { { {  -76,  26,  48,   9 },  {  -49,  26,  51,   5 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -87,  30,  78,  22 },  {  -58,  23,  69,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: follow-up of M PUNCH C; attack 48 */
    { { {  -52,  22,  42,  18 },  {  -40,  20,  34,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: L KICK A, ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command +3; attack 49, 58, 63, 66 ... */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no box */
    { { {  -61,  46,  60,  37 },  {  -60,  24,  97,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: not used by a script */
    { { {  -64,  12,  42,  39 },  {  -49,  18,  67,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command, ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) +2; attack 59, 95, 150, 173 */
    { { {  -36,  20,  88,  45 },  {  -57,  18,  53,  60 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command, ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 61, 64, 96 */
    { { {  -35,  17,  74,  46 },  {  -55,  20,  63,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command, ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 61, 64, 68, 97 */
    { { {  -60,  18,  34,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +1; attack 62, 65, 68, 153 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: no box */
    { { { -100,  34,  70,  28 },  {  -67,  53,  61,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A; attack 72, 141, 177 */
    { { {  -72,  23,  73,  20 },  {  -52,  36,  62,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A; attack 72, 141 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: no box */
    { { {  -84,  13,  69,  16 },  {  -75,  31,  58,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: L PUNCH B; attack 75 */
    { { {  -83,  23,  55,  40 },  {  -60,  50,  65,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: not used by a script */
    { { {  -93,  31,  28,  35 },  {  -62,  48,  42,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {  -73,  47,   6,  22 },  {  -47,  29,  28,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: not used by a script */
    { { {  -58,  44,  45,  45 },  {  -59,  33,  37,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: not used by a script */
    { { {  -59,  36,  52,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: not used by a script */
    { { {  -92,  40,  12,  26 },  {  -60,  35,  28,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1; attack 81, 147 */
    { { {  -82,  42,  13,  29 },  {  -59,  33,  29,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1; attack 82, 89, 90, 148 */
    { { { -166,  86,  21,  64 },  {  -81,  56,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2); attack 83, 84, 85, 86 ... */
    { { { -174,  88,  47,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2); attack 88, 167 */
    { { { -182,  31,  47,  25 },  { -115,  27,  48,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2); attack 168, 169 */
    { { { -187,  31,  48,  24 },  { -115,  27,  48,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2); attack 170 */
    { { { -202,  22,  52,  12 },  { -101,  21,  48,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: not used by a script */
    { { { -206,  16,  52,  10 },  {  -99,  18,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: not used by a script */
    { { {  -73,  44,   0,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {  -84,  70,   0,  13 },  {  -47,  33,  13,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: KAGAMI K C; attack 103 */
    { { {  -60,  17,  53,  16 },  {  -42,  30,  64,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -52,  14,  61,  31 },  {  -17,  24,  52,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {  -81,  19,  34,  17 },  {  -62,  43,  37,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no name; attack 171 */
    { { {  -88,  80,  58,  12 },  { -114,  27,  55,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI); attack 77, 78, 80, 142 ... */
    { { { -108,  44,   0,   8 },  {  -64,  50,   0,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI); attack 112, 160, 161, 182 */
    { { {  -90,  32,  44,  18 },  {  -58,  42,  47,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: V JUMP K M A; attack 106 */
    { { {  -83,  24,  71,  18 },  {  -59,  44,  72,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: V JUMP P M A; attack 37 */
    { { {  -67,  25,  71,  18 },  {  -42,  28,  74,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP P M A; attack 38 */
    { { {  -80,  28,  43,  25 },  {  -52,  50,  45,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {  -75,  21,  29,  20 },  {  -58,  23,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -58,  14,  45,  18 },  {  -44,  34,  49,   7 } } },  /* 87: S KICK A; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {  -66,  18,  36,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 62 */
    { { {  -71,  18,  37,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 62 */
    { { {  -78,  18,  38,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 62 */
    { { {  -84,  18,  40,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 62 */
    { { {  -91,  18,  42,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN); attack 62 */
    { { {  -60,  18,  37,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 65 */
    { { {  -63,  18,  38,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 65 */
    { { {  -68,  18,  40,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 65 */
    { { {  -74,  18,  43,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 65 */
    { { {  -80,  18,  48,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN); attack 65 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -66,  27,  26,  27 },  {  -70,   4,  39,   9 } } },  /* 100: not started by a command; attack 115 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  27,  30,  21 },  {  -66,   5,  44,   6 } } },  /* 101: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  19,  77,  28 },  {  -42,  18,  61,  23 } } },  /* 102: not started by a command; attack 117 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -71,  30,  36,  26 },  {  -46,  31,  42,  16 } } },  /* 103: not started by a command; attack 118 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -54,  24,   8,  22 },  {  -37,  20,  23,  24 } } },  /* 104: not started by a command; attack 119 */
    { { {  -65,  33,  37,  30 },  {  -50,  37,  52,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: not used by a script */
    { { {  -60,  47,  38,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: not used by a script */
    { { { -100,  34,  59,  35 },  {  -72,  55,  51,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: not used by a script */
    { { {  -80,  23,  66,  28 },  {  -57,  41,  55,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: not used by a script */
    { { {  -49,  24,  60,  20 },  {  -42,  18,  43,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { {  -44,  24,  62,  50 },  {  -57,  36,  48,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: not used by a script */
    { { {  -47,  26,  62,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: not used by a script */
    { { {  -36,  22,  79,  40 },  {  -57,  21,  64,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 60, 151 */
    { { {  -36,  22,  79,  36 },  {  -55,  19,  64,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 67, 152 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: no box */
    { { {  -88,  72,  59,  10 },  { -118,  30,  56,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI); attack 146, 154, 155, 156 */
    { { {  -61,  20,  41,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 68, 153 */
    { { {  -65,  20,  45,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 68, 153 */
    { { {  -69,  20,  49,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 68, 153 */
    { { {  -73,  20,  53,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 68, 153 */
    { { {  -77,  20,  57,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN); attack 68, 153 */
    { { { -113,  38,  47,  10 },  {  -86,  43,  49,   5 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: KAGAMI P A; attack 108 */
    { { {  -95,  20,  47,  10 },  {  -78,  35,  49,   5 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: KAGAMI P A */
    { { { -110,  20,   0,  11 },  {    0,   0,   0,   0 },  {  -93,  67,   5,  14 },  {    0,   0,   0,   0 } } },  /* 124: KAGAMI K A; attack 178 */
    { { {  -98,  13,   0,  11 },  {    0,   0,   0,   0 },  {  -85,  59,   6,  10 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A */
    { { {  -77,  12,  34,  11 },  {    0,   0,   0,   0 },  {  -67,  13,  39,  10 },  {  -57,  11,  45,   9 } } },  /* 126: F JUMP P M A; attack 37 */
    { { {  -67,  12,  39,  11 },  {    0,   0,   0,   0 },  {  -59,  12,  44,  10 },  {    0,   0,   0,   0 } } },  /* 127: F JUMP P M A; attack 38 */
    { { {  -24, 232,  30,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: ATTACK 8 SP: not started by a command; attack 179, 180, 181 */
};

const CATCH_BOX ibuki_cat_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -40,   16,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {  -54,   44,    0,   16 } },  /* 2: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI) */
    { { -110,   95,   36,   62 } },  /* 3: not used by a script */
    { {  -40,   40,    0,   16 } },  /* 4: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) +1 */
    { {  -36,   22,   44,   23 } },  /* 5: TUKAMI AIR A */
    { {  -53,   28,   41,   52 } },  /* 6: not used by a script */
    { {  -56,   46,    0,   16 } },  /* 7: ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) */
    { {  -58,   48,    0,   16 } },  /* 8: ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { {  -44,   28,  -24,   16 } },  /* 9: not started by a command */
    { {  -48,   88,    0,   84 } },  /* 10: CATCH 22, CATCH 23 */
    { {  -56,   46,    0,   16 } },  /* 11: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
};

const CAUGHT_BOX ibuki_cau_box[13] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +135 */
    { {  -28,   52,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +56 */
    { {  -25,   48,   44,   48 } },  /* 3: SP JUMP FRONT, GUARD AIR, TUKAMIHAZUSI +76 */
    { {  -30,   60,    0,   16 } },  /* 4: CATCH 5, CATCH 24, DASH TOBINOKI +5 */
    { {  -38,   38,    0,   16 } },  /* 5: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    { {  -15,   40,   44,   38 } },  /* 6: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    { {  -28,   28,    0,    8 } },  /* 7: not used by a script */
    { {  -25,   48,   64,   48 } },  /* 8: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +16 */
    { {  -36,   44,   64,   22 } },  /* 9: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +2 */
    { {  -30,   60,    0,   16 } },  /* 10: PIYO */
    { {  -32,   56,    0,    8 } },  /* 11: KAGAMI P A, KAGAMI K A */
    { {  -46,   58,    0,   16 } },  /* 12: not used by a script */
};

