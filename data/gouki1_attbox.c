/*
 * GOUKI1_ATTBOX.C  Gouki's attack, catch and caught boxes
 *
 * Selected per animation frame through gouki1_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX gouki1_att_box[79] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  14,  70,  22 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  14,  84,  12 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  36,  72,   8 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B; attack 4 */
    { { {  -56,  24,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A; attack 5 */
    { { {  -80,  18,  64,  16 },  {  -60,  34,  72,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH B, S V JP S P A; attack 6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -76,  44,  70,   8 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH B */
    { { {  -78,  24,  58,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH C; attack 50 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  22,  28,  16 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH C; attack 51 */
    { { {  -68,  30,  66,  24 },  {  -62,  28,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A; attack 7 */
    { { {  -56,  18,  98,  14 },  {  -64,  20,  86,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A; attack 8 */
    { { {  -92,  50,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B, follow-up of M PUNCH A; attack 8, 9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -72,  38,  14,  10 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A; attack 10 */
    { { {  -70,  22,  56,  16 },  {    0,   0,   0,   0 },  {  -60,  22,  44,  16 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {  -60,  42,  44,  10 },  {    0,   0,   0,   0 },  {  -88,  64,  54,  12 },  {    0,   0,   0,   0 } } },  /* 14: M KICK B; attack 13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  56,  50,  10 },  {    0,   0,   0,   0 } } },  /* 15: M KICK B */
    { { {  -86,  24,  86,  18 },  {  -60,  24,  66,  18 },  {  -74,  24,  76,  18 },  {    0,   0,   0,   0 } } },  /* 16: L KICK B; attack 17 */
    { { {  -86,  16,   0,  10 },  {    0,   0,   0,   0 },  {  -68,  38,   0,  14 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A; attack 24 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,   0,  14 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  44,  44,   8 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A; attack 19 */
    { { {  -76,  16,  38,  14 },  {    0,   0,   0,   0 },  {  -58,  32,  40,  12 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A; attack 20 */
    { { {  -60,  32,  32,  32 },  {    0,   0,   0,   0 },  {  -44,  28,  16,  24 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A; attack 21 */
    { { {  -54,  14,  66,  24 },  {    0,   0,   0,   0 },  {  -46,  14,  84,  24 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  14, 100,  12 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -80,  52,   0,   8 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A; attack 23 */
    { { {  -90,  68,   0,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI K A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -52,  24,  60,  12 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P S A, F JUMP P S A; attack 26, 32 */
    { { {  -76,  20,  62,  16 },  {    0,   0,   0,   0 },  {  -64,  20,  70,  16 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P M A; attack 27 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  22,  64,  18 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P M A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  14,  58,  12 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP P M A, F JUMP P L A */
    { { {  -50,  26,  50,  22 },  {  -36,  22,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU); attack 38 */
    { { {  -60,  38,  22,  32 },  {  -40,  26,  12,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN); attack 54 */
    { { {  -64,  40,  42,  32 },  {  -50,  26,  20,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN); attack 1, 53, 55 */
    { { {  -48,  32,  46,  32 },  {  -36,  20,  82,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN); attack 2, 61, 62 */
    { { {  -32,  18, 118,  20 },  {    0,   0,   0,   0 },  {  -44,  24,  56,  20 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN); attack 61, 62 */
    { { {  -32,  16, 118,  14 },  {    0,   0,   0,   0 },  {  -38,  16,  54,  14 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    { { {  -60,  38,  22,  32 },  {  -40,  26,  12,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 89, 91, 93 */
    { { {  -64,  40,  42,  32 },  {  -50,  26,  20,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 90, 92, 94 */
    { { {  -48,  32,  46,  32 },  {  -36,  20,  82,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA); attack 95 */
    { { {  -32,  18, 118,  20 },  {  -44,  24,  56,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -76,  22,  46,  18 },  {    0,   0,   0,   0 },  {  -52,  22,  54,  18 },  {    0,   0,   0,   0 } } },  /* 40: F JUMP P L A; attack 34 */
    { { {  -70,  18,  52,  14 },  {    0,   0,   0,   0 },  {  -58,  18,  60,  14 },  {    0,   0,   0,   0 } } },  /* 41: F JUMP P L A, S V JP S P A */
    { { {  -50,  24,  60,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: S V JP S P A; attack 26 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  24,  82,  30 },  {    0,   0,   0,   0 } } },  /* 43: S V JP M P A, S V JP M K A */
    { { {  -84,  50,  90,  10 },  {    0,   0,   0,   0 },  {  -62,  32,  84,  10 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P L A, S V JP M K A; attack 28, 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -78,  48,  86,  10 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P L A, S V JP M K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  24,  36,  14 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP K S A, F JUMP K S A; attack 29, 35 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -40,  18,  36,  10 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP K S A, F JUMP K S A, S V JP S K A; attack 35 */
    { { {  -88,  18,  54,  16 },  {    0,   0,   0,   0 },  {  -68,  34,  58,  12 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP K M A, S V JP S K A; attack 30 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  44,  60,  10 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP K M A */
    { { {  -82,  22,  82,  18 },  {  -50,  22,  62,  18 },  {  -66,  22,  72,  18 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP K L A; attack 31 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -74,  18,  78,  14 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP K L A, S V JP M P A; attack 33 */
    { { {  -84,  16,  52,  16 },  {  -28,  40,  46,  12 },  {  -67,  38,  48,  12 },  {    0,   0,   0,   0 } } },  /* 52: F JUMP K M A; attack 36 */
    { { {  -28,  40,  46,  12 },  {    0,   0,   0,   0 },  {  -80,  50,  50,  12 },  {    0,   0,   0,   0 } } },  /* 53: F JUMP K M A */
    { { {  -88,  24,  40,  16 },  {  -62,  24,  44,  16 },  {  -36,  24,  48,  16 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP K L A; attack 37 */
    { { {  -82,  32,  46,  12 },  {  -48,  32,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: F JUMP K L A */
    { { {  -76,  22,  58,  12 },  {    0,   0,   0,   0 },  {  -64,  32,  58,  18 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3; attack 39, 64, 65, 66 ... */
    { { {   44,  20,  60,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3; attack 39, 64, 65, 66 ... */
    { { {  -60,  52,  38,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN); attack 77 */
    { { {  -84,  56,  42,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: S V JP L K A, ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 37, 67, 73, 77 ... */
    { { {   32,  56,  42,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 68, 72, 80 */
    { { {  -96,  64,  64,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI); attack 81 */
    { { {  -46,  12,  72,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: L KICK A; attack 14 */
    { { {  -76,  28,  78,  22 },  {  -60,  22,  96,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: L KICK A; attack 15 */
    { { {  -68,  20,  20,  20 },  {    0,   0,   0,   0 },  {  -74,  18,  42,  22 },  {    0,   0,   0,   0 } } },  /* 64: L KICK A; attack 16 */
    { { {  -56, 112,  16,  56 },  {  -40,  80,   0,  80 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 10 SP: SA (all arts) 25252+PP (plain script); attack 56 */
    { { {  -44,  88,   8,  48 },  {  -16,  32,   0, 120 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 10 SP: SA (all arts) 25252+PP (plain script); attack 57 */
    { { {  -28,  56,   0,  32 },  {   -4,   8,   0, 200 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -70,  44,  28,  18 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 9 S: not started by a command; attack 69 */
    { { {  -54,  12,  24,  10 },  {    0,   0,   0,   0 },  {  -48,  12,  32,  10 },  {    0,   0,   0,   0 } } },  /* 69: F JUMP K M B */
    { { {  -60,  24,  58,  20 },  {  -46,  18,  48,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: M KICK A; attack 12 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -56,  20,  56,  16 },  {    0,   0,   0,   0 } } },  /* 71: M KICK A */
    { { {  -76,  19,   0,  13 },  {  -68,  22,   9,  12 },  {  -59,  34,   0,  21 },  {    0,   0,   0,   0 } } },  /* 72: 623+K (routine Att_PL14_AT3); attack 84 */
    { { {  -76,  18,   4,  13 },  {  -66,  32,  13,  14 },  {  -58,  33,   0,  27 },  {    0,   0,   0,   0 } } },  /* 73: 623+K (routine Att_PL14_AT3) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  36,   0,  22 },  {  -70,  29,   8,  14 } } },  /* 74: 623+K (routine Att_PL14_AT3) */
    { { {  -66,  24,  30,  17 },  {    0,   0,   0,   0 },  {  -52,  17,  42,  15 },  {  -38,  21,  49,  18 } } },  /* 75: not started by a command; attack 85 */
    { { {  -58,  13,  34,  11 },  {    0,   0,   0,   0 },  {  -52,  17,  42,  15 },  {  -38,  21,  49,  18 } } },  /* 76: not started by a command */
    { { {  -50,  14,  12,  11 },  {    0,   0,   0,   0 },  {  -43,  13,  19,  13 },  {    0,   0,   0,   0 } } },  /* 77: not started by a command; attack 86 */
    { { {  -50,  14,  15,  11 },  {    0,   0,   0,   0 },  {  -42,  12,  22,  11 },  {    0,   0,   0,   0 } } },  /* 78: not started by a command */
};

const CATCH_BOX gouki1_cat_box[19] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -49,   24,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {  -33,    8,    0,   16 } },  /* 2: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    { {  -37,   12,    0,   16 } },  /* 3: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    { {  -42,   33,  -69,   34 } },  /* 4: not started by a command */
    { {  -41,   42,  -56,   31 } },  /* 5: not used by a script */
    { {  -36,   36,  -48,   29 } },  /* 6: not used by a script */
    { {  -37,   35,  -37,   29 } },  /* 7: not used by a script */
    { {  -40,   39,  -55,   31 } },  /* 8: not used by a script */
    { {  -43,   41,  -39,   32 } },  /* 9: not used by a script */
    { {  -41,   39,  -79,   36 } },  /* 10: not used by a script */
    { {  -43,   41,  -40,   30 } },  /* 11: not used by a script */
    { {  -41,   38,  -30,   31 } },  /* 12: not used by a script */
    { {  -41,   39,  -35,   31 } },  /* 13: not used by a script */
    { {  -39,   37,  -45,   32 } },  /* 14: not used by a script */
    { {  -37,   35,  -39,   31 } },  /* 15: not used by a script */
    { {  -44,   42,  -74,   38 } },  /* 16: not used by a script */
    { {  -43,   42,  -34,   34 } },  /* 17: not used by a script */
    { {  -37,   36,  -60,   36 } },  /* 18: not used by a script */
};

const CAUGHT_BOX gouki1_cau_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +110 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +31 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +78 */
    { {  -33,   58,    0,    8 } },  /* 4: KAGAMI P A, KAGAMI K A */
    { {  -29,   54,    0,   16 } },  /* 5: S KICK A */
};

