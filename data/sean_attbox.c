/*
 * SEAN_ATTBOX.C  Sean's attack, catch and caught boxes
 *
 * Selected per animation frame through sean_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX sean_att_box[128] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  14,  70,  22 },  {    0,   0,   0,   0 } } },  /* 1: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  14,  84,  12 },  {    0,   0,   0,   0 } } },  /* 2: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  36,  72,   8 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A; attack 4 */
    { { {  -56,  24,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A; attack 5 */
    { { {  -80,  18,  64,  16 },  {  -60,  34,  72,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH B; attack 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  44,  70,   8 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH B */
    { { {  -54,  26,  28,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 41, 43 */
    { { {  -29,  29,  34,  77 },  {  -46,  24,  48,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 42, 46 */
    { { {  -68,  30,  66,  24 },  {  -62,  28,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A; attack 7 */
    { { {  -56,  18,  98,  14 },  {  -64,  20,  86,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A */
    { { {  -76,  28,  76,  24 },  {    0,   0,   0,   0 },  {  -52,  22,  76,  18 },  {    0,   0,   0,   0 } } },  /* 11: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  38,  14,  10 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A; attack 10 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: no box */
    { { {  -68,  20,  36,  16 },  {    0,   0,   0,   0 },  {  -92,  24,  24,  18 },  {    0,   0,   0,   0 } } },  /* 14: M KICK A; attack 12 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  22,  18,  18 },  {    0,   0,   0,   0 } } },  /* 15: M KICK A */
    { { {  -80,  22,  74,  18 },  {  -54,  22,  54,  18 },  {  -72,  24,  66,  20 },  {    0,   0,   0,   0 } } },  /* 16: follow-up of M PUNCH A; attack 9 */
    { { {  -80,  12,   0,  10 },  {    0,   0,   0,   0 },  {  -68,  38,   0,  14 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,   0,  14 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  44,  44,   8 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 19 */
    { { {  -76,  16,  38,  14 },  {    0,   0,   0,   0 },  {  -58,  32,  40,  12 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A; attack 20 */
    { { {  -60,  32,  32,  32 },  {    0,   0,   0,   0 },  {  -44,  28,  16,  24 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 21 */
    { { {  -54,  14,  66,  24 },  {    0,   0,   0,   0 },  {  -46,  14,  84,  24 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  14, 100,  12 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  52,   0,   8 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A; attack 23 */
    { { {  -82,  64,   0,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  24,  60,  12 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -76,  20,  62,  16 },  {    0,   0,   0,   0 },  {  -64,  20,  70,  16 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P M A, F JUMP P M A; attack 27, 33 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  22,  64,  18 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P M A, F JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  14,  58,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    { { {   24,  18,  90,  14 },  {   36,  16,  78,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: not used by a script */
    { { {  -48,  20, 100,  16 },  {  -32,  18, 106,  14 },  {  -38,  20,  84,  16 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP); attack 100 */
    { { {  -70,  20,  80,  16 },  {  -62,  18,  96,  14 },  {  -58,  20,  68,  16 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP); attack 93, 101 */
    { { {  -78,  20,  48,  16 },  {  -76,  18,  66,  14 },  {  -60,  20,  46,  16 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP); attack 94, 102 */
    { { {  -66,  20,  18,  16 },  {  -72,  18,  34,  14 },  {  -48,  20,  30,  16 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 99 */
    { { {  -79,  21,  31,  30 },  {  -58,  30,   0,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 64, 73 */
    { { {  -79,  58,  24,  72 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 71, 72, 96 */
    { { {  -56,  40,  32,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 60 */
    { { {  -56,  20,  58,  16 },  {    0,   0,   0,   0 },  {  -46,  18,  48,  14 },  {  -36,  14,  40,  10 } } },  /* 38: L KICK A; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -56,  20,  56,  16 },  {    0,   0,   0,   0 } } },  /* 39: L KICK A */
    { { {  -76,  22,  46,  18 },  {    0,   0,   0,   0 },  {  -52,  22,  54,  18 },  {    0,   0,   0,   0 } } },  /* 40: F JUMP P L A; attack 34 */
    { { {  -70,  18,  52,  14 },  {    0,   0,   0,   0 },  {  -58,  18,  60,  14 },  {    0,   0,   0,   0 } } },  /* 41: F JUMP P L A */
    { { {  -50,  24,  60,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  24,  82,  30 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
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
    { { {  -88,  24,  40,  16 },  {  -62,  24,  44,  16 },  {  -36,  24,  48,  16 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A; attack 37 */
    { { {  -82,  32,  46,  12 },  {  -48,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: F JUMP K L A */
    { { {  -76,  12,  56,  10 },  {    0,   0,   0,   0 },  {  -64,  14,  52,  12 },  {  -50,  18,  48,  14 } } },  /* 56: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +1; attack 56, 57, 58, 84 ... */
    { { {  -76,  16,  80,  14 },  {  -44,  20,  52,  16 },  {  -62,  20,  66,  16 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN); attack 59, 90 */
    { { {  -58,  32,  46,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU); attack 103 */
    { { {  -54,  28,  52,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU); attack 74 */
    { { {  -38,  24,  60,  24 },  {    0,   0,   0,   0 },  {  -14,  40, 108,  28 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU); attack 75, 104 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -12,  36, 108,  24 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1; attack 75, 105 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   -4,  28, 112,  18 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  42,  28,  18 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 10 S: not started by a command; attack 77 */
    { { {  -44,  28,  50,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: L PUNCH C, follow-up of L PUNCH A; attack 86, 97 */
    { { {  -66,  28,  25,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: L PUNCH C, follow-up of L PUNCH A; attack 87, 98 */
    { { {  -59,  19,  32,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: L PUNCH C, follow-up of L PUNCH A; attack 7 */
    { { {  -85,  33,  74,  10 },  {  -52,  37,  63,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: not used by a script */
    { { {  -78,  18,  66,  10 },  {    0,   0,   0,   0 },  {  -62,  18,  62,  10 },  {    0,   0,   0,   0 } } },  /* 68: L PUNCH B; attack 69 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  16,  40,  12 },  {  -50,  16,  46,  12 } } },  /* 69: L PUNCH B; attack 70 */
    { { {  -78,  24,  66,   8 },  {  -58,  24,  60,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: L KICK C; attack 78 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  24,  66,   8 },  {  -58,  24,  60,   8 } } },  /* 71: L KICK C; attack 79 */
    { { {  -68,  10,  82,  14 },  {  -56,  10,  74,  18 },  {  -44,  10,  64,  24 },  {  -32,  10,  52,  30 } } },  /* 72: L KICK B; attack 82 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  16,  80,  14 },  {  -52,  16,  76,  14 } } },  /* 73: L KICK B; attack 83 */
    { { {  -92,  68,  48,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 61, 62 */
    { { {  -68,  52,  76,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 67 */
    { { {  -86,  52,  58,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -90,  52,  42,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 68 */
    { { {  -54,  26,  28,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -29,  29,  34,  77 } } },  /* 78: not used by a script */
    { { {  -46,  24,  48,  29 },  {    0,   0,   0,   0 },  {  -40,  18,  58,  16 },  {  -26,  14, 122,  20 } } },  /* 79: not used by a script */
    { { {    0,   0,   0,   0 },  {  -52,  11,  78,  18 },  {  -38,  12,  68,  20 },  {    0,   0,   0,   0 } } },  /* 80: not used by a script */
    { { {  -70,  52,  74,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  38,  44,  27 } } },  /* 81: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  65,  64,  18 },  {    0,   0,   0,   0 } } },  /* 82: not used by a script */
    { { {    0,   0,   0,   0 },  {  -69,  44,  49,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: not used by a script */
    { { {  -51,  31,  80,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  28,  78,  16 } } },  /* 84: not used by a script */
    { { {  -47,  25,  77,  13 },  {    0,   0,   0,   0 },  {  -62,  38,  11,  36 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {    0,   0,   0,   0 },  {  -75,  46,  65,  15 },  {  -35,  35,  59,  13 },  {    0,   0,   0,   0 } } },  /* 86: not used by a script */
    { { {  -87,  32,  12,  20 },  {  -64,  42,  34,  18 },  {    0,   0,   0,   0 },  {  -88,  63,   7,  14 } } },  /* 87: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  44,  48,  24 },  {    0,   0,   0,   0 } } },  /* 88: not used by a script */
    { { {    0,   0,   0,   0 },  {  -44,  28,  50,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: not used by a script */
    { { {  -66,  28,  25,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -59,  19,  32,  20 } } },  /* 90: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -85,  33,  74,  10 },  {  -52,  37,  63,  15 } } },  /* 91: not used by a script */
    { { {    0,   0,   0,   0 },  {  -78,  42,  74,  14 },  {  -50,  39,  63,  12 },  {    0,   0,   0,   0 } } },  /* 92: not used by a script */
    { { {  -62,  54,  41,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  52,  40,  14 } } },  /* 93: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  36,  30,  35 },  {    0,   0,   0,   0 } } },  /* 94: not used by a script */
    { { {    0,   0,   0,   0 },  {  -23,  20,  89,  33 },  {  -38,  23,  61,  28 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -80,  54,   0,   5 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -86,  76,   0,   5 } } },  /* 96: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -96,  75,   0,   6 },  {  -57,  45,   2,  21 } } },  /* 97: not used by a script */
    { { {    0,   0,   0,   0 },  {  -47,  19,  59,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: not used by a script */
    { { {  -90,  60,  91,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  65,  57,  18 } } },  /* 99: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 } } },  /* 100: not used by a script */
    { { {    0,   0,   0,   0 },  {  -77,  40,  49,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: not used by a script */
    { { {  -38,  18,  42,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  18,  38,  21 } } },  /* 102: not used by a script */
    { { {  -63,  77,  52,  13 },  {    0,   0,   0,   0 },  {  -71,  42,  58,  20 },  {    0,   0,   0,   0 } } },  /* 103: not used by a script */
    { { {    0,   0,   0,   0 },  {  -55,  16,  91,  25 },  {  -46,  20,  74,  20 },  {    0,   0,   0,   0 } } },  /* 104: not used by a script */
    { { {  -66,  48,  80,  20 },  {  -81,  25,  93,  18 },  {    0,   0,   0,   0 },  {  -47,  40,  25,  48 } } },  /* 105: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -75,  55,  56,  14 },  {    0,   0,   0,   0 } } },  /* 106: not used by a script */
    { { {    0,   0,   0,   0 },  { -108,  39,  52,  13 },  {  -72,  32,  55,  13 },  {    0,   0,   0,   0 } } },  /* 107: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -26,  30,  90,  29 } } },  /* 108: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  47,  50,  11 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { {    0,   0,   0,   0 },  {  -85,  64,  36,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {   23,  31,  85,  10 } } },  /* 111: not used by a script */
    { { {    9,  27,  75,  15 },  {    0,   0,   0,   0 },  {  -66,  18,  72,  16 },  {  -48,  40,  75,  10 } } },  /* 112: not used by a script */
    { { {    0,   0,   0,   0 },  {  -79,  21,  31,  30 },  {  -58,  30,   0,  64 },  {    0,   0,   0,   0 } } },  /* 113: not used by a script */
    { { {  -86,  16,  52,  18 },  {  -70,  47,  54,  17 },  {    0,   0,   0,   0 },  { -100,  37,   0,  19 } } },  /* 114: not used by a script */
    { { {  -57,  45,   2,  21 },  {    0,   0,   0,   0 },  {  -79,  58,  24,  72 },  {    0,   0,   0,   0 } } },  /* 115: not used by a script */
    { { {    0,   0,   0,   0 },  {  -96, 109,  30,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { {  -51,  55,  41,  85 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -92,  83,  34,  73 } } },  /* 117: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: no box */
    { { {    0,   0,   0,   0 },  {    2,  34,  80,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: not used by a script */
    { { {  -44,  42, 106,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -66,  58,  91,  29 } } },  /* 120: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -65,  90,  88,  29 },  {    0,   0,   0,   0 } } },  /* 121: not used by a script */
    { { {    0,   0,   0,   0 },  {  -49,  26,  29,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: not used by a script */
    { { {  -71,  35,  87,  16 },  {  -34,  15,  66,  31 },  {    0,   0,   0,   0 },  {  -41,  81,   0,  24 } } },  /* 123: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -42,  27,  42,  33 },  {  -30,  26, 100,  39 } } },  /* 124: not used by a script */
    { { {    0,   0,   0,   0 },  {  -66,  47,  74,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: not used by a script */
    { { {  -70,  47,  62,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -85,  33,  76,  30 } } },  /* 126: not used by a script */
    { { {  -57,  37,  64,  15 },  {    0,   0,   0,   0 },  {  -83,  31,  74,  20 },  {  -57,  35,  64,  11 } } },  /* 127: not used by a script */
};

/* entry 128 is cut short: only its first 1 box(es) are stored, the catch boxes follow */
const s16 sean_att_box_128[1][4] = { {    0,   0,   0,   0 } };

const CATCH_BOX sean_cat_box[3] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -45,   20,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {  -78,   34,    0,   16 } },  /* 2: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
};

const CAUGHT_BOX sean_cau_box[26] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +107 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +37 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +71 */
    { {  -33,   58,    0,    8 } },  /* 4: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 5: S KICK A */
    { {  -25,   50,    0,   16 } },  /* 6: not used by a script */
    { {  -29,   54,    0,    8 } },  /* 7: not used by a script */
    { {  -25,   50,   48,   40 } },  /* 8: not used by a script */
    { {  -25,   50,   48,   40 } },  /* 9: not used by a script */
    { {  -42,   42,    0,   16 } },  /* 10: not used by a script */
    { {  -21,   36,    0,   90 } },  /* 11: not used by a script */
    { {  -36,   36,    0,   90 } },  /* 12: not used by a script */
    { {  -29,   54,    0,   16 } },  /* 13: not used by a script */
    { {  -33,   58,    0,    8 } },  /* 14: not used by a script */
    { {  -18,   45,   48,   45 } },  /* 15: not used by a script */
    { {  -28,   44,   48,   47 } },  /* 16: not used by a script */
    { {  -27,   47,   52,   45 } },  /* 17: not used by a script */
    { {  -25,   50,   48,   40 } },  /* 18: not used by a script */
    { {   -8,   40,   66,   25 } },  /* 19: not used by a script */
    { {  -46,   80,    0,   16 } },  /* 20: not used by a script */
    { {  -41,   81,    0,   16 } },  /* 21: not used by a script */
    { {  -36,   73,   46,   49 } },  /* 22: not used by a script */
    { {  -38,   63,    0,   16 } },  /* 23: not used by a script */
    { {  -35,   70,    0,   16 } },  /* 24: not used by a script */
    { {  -25,   50,   24,   40 } },  /* 25: not used by a script */
};

