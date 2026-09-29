/*
 * NO12_ATTBOX.C  Twelve's attack, catch and caught boxes
 *
 * Selected per animation frame through no12_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX no12_att_box[131] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -112,  19,  72,   5 },  {  -93,  59,  73,   6 } } },  /* 1: S PUNCH A; attack 2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  13,  72,   5 },  {  -93,  59,  73,   6 } } },  /* 2: S PUNCH A */
    { { {  -67,  12,  60,   4 },  {    0,   0,   0,   0 },  {  -55,  29,  59,  11 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A; attack 1 */
    { { {  -67,  12,  60,   4 },  {    0,   0,   0,   0 },  {  -55,  29,  59,  11 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A */
    { { { -117,  21,  81,   4 },  {    0,   0,   0,   0 },  {  -96,  72,  79,   4 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH B; attack 3 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -98,  21,  82,   4 },  {  -78,  55,  80,   4 } } },  /* 6: M PUNCH B */
    { { {  -69,  34,  44,  26 },  {    0,   0,   0,   0 },  {  -43,  29,  53,  17 },  {  -78,  27,  61,  28 } } },  /* 7: L PUNCH A; attack 5 */
    { { { -109,  16, 109,  13 },  {  -99,  10,  99,  15 },  { -129,  46, 117,  24 },  {  -95,  20,  87,  16 } } },  /* 8: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -109,  37, 113,  17 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  20,  25,  17 },  {  -44,  26,  35,  23 } } },  /* 10: ATTACK 8 L: not started by a command; attack 102 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -105,  22,  22,   8 },  {  -83,  59,  30,   9 } } },  /* 11: S KICK A; attack 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -105,  22,  22,   8 },  {  -83,  59,  30,   9 } } },  /* 12: S KICK A */
    { { {  -81,  29,  77,  24 },  {    0,   0,   0,   0 },  {  -63,  25,  65,  26 },  {  -52,  28,  54,  27 } } },  /* 13: M KICK A; attack 9 */
    { { {  -78,  29,  77,  19 },  {    0,   0,   0,   0 },  {  -60,  22,  71,  18 },  {  -52,  28,  50,  33 } } },  /* 14: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -60,  13,  77,  11 },  {  -51,  19,  67,   9 } } },  /* 15: M KICK A */
    { { {  -75,  15,   3,  25 },  {    0,   0,   0,   0 },  {  -68,  15,  24,  17 },  {  -56,  30,  38,  13 } } },  /* 16: M KICK C */
    { { {  -75,  14,  28,  11 },  {    0,   0,   0,   0 },  {  -64,  15,  36,  12 },  {  -52,  27,  44,  12 } } },  /* 17: M KICK C; attack 8 */
    { { {  -28,  13,  96,  28 },  {    0,   0,   0,   0 },  {  -42,  14,  86,  23 },  {  -49,  11,  73,  21 } } },  /* 18: M KICK C */
    { { { -186,  30,  57,  29 },  { -156,  29,  73,   8 },  { -127,  31,  69,   9 },  {  -96,  72,  61,  11 } } },  /* 19: L KICK A; attack 11 */
    { { { -194,  35,  57,  19 },  {    0,   0,   0,   0 },  { -170,  14,  46,  11 },  { -159, 136,  66,   6 } } },  /* 20: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -152,  43,  33,   4 },  { -167,  22,  38,  16 } } },  /* 21: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  65,  32,   3 },  {  -41,  11,  35,   5 } } },  /* 22: KAGAMI P A; attack 12 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -101,  25,  37,   4 },  {  -75,  43,  36,   4 } } },  /* 23: KAGAMI P A */
    { { {  -82,  11,  90,   9 },  {  -74,  12,  83,   8 },  {  -62,  20,  69,  15 },  {  -47,  23,  52,  19 } } },  /* 24: KAGAMI P A; attack 13, 16 */
    { { {  -80,   9,  91,   7 },  {  -72,   9,  83,   7 },  {  -62,  20,  69,  15 },  {  -47,  23,  52,  19 } } },  /* 25: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -83,  15,  87,  14 },  {  -73,  17,  79,  12 } } },  /* 26: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -103,  22,  19,   4 },  {  -81,  57,  21,   4 } } },  /* 27: KAGAMI K A; attack 15 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -103,  22,  21,   4 },  {  -81,  57,  21,   4 } } },  /* 28: KAGAMI K A */
    { { { -126,  26,   6,   8 },  {    0,   0,   0,   0 },  { -102,  31,  15,   5 },  {  -71,  47,  20,   5 } } },  /* 29: KAGAMI K A; attack 53 */
    { { { -115,  18,   6,  10 },  {    0,   0,   0,   0 },  { -102,  31,  15,   5 },  {  -71,  47,  20,   5 } } },  /* 30: KAGAMI K A */
    { { { -100,   8,   9,   3 },  {  -92,  15,  12,   3 },  {  -77,  33,  16,   4 },  {  -45,  49,  21,  10 } } },  /* 31: KAGAMI K A; attack 17, 100 */
    { { { -100,   8,   9,   3 },  {  -92,  15,  12,   3 },  {  -77,  33,  16,   4 },  {  -45,  49,  21,  10 } } },  /* 32: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  24,  19,  20 },  {  -49,  22,  33,  18 } } },  /* 33: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8; attack 19, 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -65,  23,  23,  19 },  {  -49,  22,  33,  18 } } },  /* 34: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { { -100,  20, 105,   9 },  {    0,   0,   0,   0 },  {  -81,  57, 100,   9 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8; attack 20, 26 */
    { { {  -95,  13, 105,   8 },  {    0,   0,   0,   0 },  {  -81,  57, 100,   5 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {  -92,  33,  62,  10 },  { -111,  28,  57,   6 },  { -125,  19,  45,  13 },  { -137,  20,  40,  13 } } },  /* 37: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8; attack 21 */
    { { {  -80,  20,  66,  10 },  { -102,  20,  59,   6 },  { -118,  17,  50,   9 },  { -130,  11,  42,   9 } } },  /* 38: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -98,  29,  61,   9 },  { -120,  20,  50,   8 } } },  /* 39: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  22,  46,  17 },  {  -33,  17,  58,  16 } } },  /* 40: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8; attack 22 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  19,  47,  16 },  {  -33,  12,  60,  12 } } },  /* 41: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -97,  19, 119,   9 },  {  -81,  20, 115,   8 },  {  -64,  15, 108,   8 },  {  -53,  28,  98,  15 } } },  /* 42: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8; attack 23 */
    { { {  -87,  13, 117,   4 },  {  -74,  12, 113,   4 },  {  -64,  15, 108,   6 },  {  -53,  28,  96,  15 } } },  /* 43: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {  -36,  16,  -4,  15 },  {  -32,  18,   6,  21 },  {  -28,  27,  22,  16 },  {  -24,  23,  38,  25 } } },  /* 44: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8; attack 24 */
    { { {  -34,  12,   1,   8 },  {  -31,  17,   9,  13 },  {  -28,  27,  22,  21 },  {  -24,  23,  38,  25 } } },  /* 45: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  20,  22,  17 },  {  -24,  21,  39,  22 } } },  /* 46: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -58,  23,  43,  19 },  {  -46,  23,  51,  20 },  {  -36,  26,  58,  23 },  {  -22,  25,  71,  21 } } },  /* 47: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command; attack 27 */
    { { {  -56,  22,  46,  18 },  {  -46,  19,  54,  15 },  {  -36,  23,  59,  21 },  {  -22,  23,  71,  20 } } },  /* 48: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -49,  13,  52,  11 },  {  -40,  13,  58,  12 },  {  -34,  19,  65,  15 },  {  -23,  17,  75,  14 } } },  /* 49: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -75,  24,  53,  22 },  {  -61,  23,  61,  20 },  {  -49,  26,  67,  23 },  {  -32,  25,  79,  21 } } },  /* 50: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command; attack 28 */
    { { {  -71,  22,  57,  18 },  {  -57,  19,  64,  15 },  {  -49,  26,  67,  22 },  {  -34,  25,  78,  20 } } },  /* 51: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -63,  13,  64,  11 },  {  -51,  15,  69,  10 },  {  -42,  19,  73,  12 },  {  -31,  19,  80,  12 } } },  /* 52: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -76,  20,  62,  16 },  {  -61,  23,  68,  11 },  {  -49,  26,  75,  14 },  {  -29,  18,  79,  11 } } },  /* 53: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command; attack 29 */
    { { {  -74,  18,  65,  14 },  {  -57,  15,  69,  11 },  {  -48,  25,  75,  11 },  {  -29,  16,  79,  10 } } },  /* 54: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -65,   8,  70,   7 },  {  -58,  15,  72,   9 },  {  -48,  19,  75,  10 },  {  -34,  15,  81,   9 } } },  /* 55: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -75,  24,  53,  22 },  {  -61,  23,  61,  20 },  {  -49,  26,  67,  23 },  {  -32,  25,  79,  21 } } },  /* 56: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU); attack 30 */
    { { {  -71,  22,  57,  18 },  {  -57,  19,  64,  15 },  {  -49,  26,  67,  22 },  {  -34,  25,  78,  20 } } },  /* 57: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU); attack 30 */
    { { {  -63,  13,  64,  11 },  {  -51,  15,  69,  10 },  {  -42,  19,  73,  12 },  {  -31,  19,  80,  12 } } },  /* 58: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU); attack 30, 31 */
    { { {  -92,  66,  41,  47 },  {   30,  41,  43,  47 },  {  -84,  58,  82,  15 },  {   29,  36,  83,  14 } } },  /* 59: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1; attack 43, 44, 45, 46 ... */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 60: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 61: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 62: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 63: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 64: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 65: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 66: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 67: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 68: not used by a script */
    { { {  -75,  49,  41,  47 },  {   30,  32,  43,  47 },  {  -64,  38,  82,  15 },  {   29,  24,  83,  14 } } },  /* 69: not used by a script */
    { { { -117,   8,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -109,  27,   0,  18 } } },  /* 70: KAGAMI P A, ATTACK 9 L: 236+K light (plain script); attack 37 */
    { { { -117,   8,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -109,  27,   0,  18 } } },  /* 71: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -121,  16,   0,  45 },  { -109,  27,   0,  18 } } },  /* 72: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { { -197,   8,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 9 SP: 236+K medium (plain script) */
    { { { -197,   8,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -201,  16,   0,  45 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 9 SP: 236+K medium (plain script) */
    { { { -184,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: not used by a script */
    { { { -184,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: not used by a script */
    { { { -184,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: not used by a script */
    { { { -277,   8,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 10 S: 236+K heavy (plain script) */
    { { { -277,   8,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -281,  16,   0,  45 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 10 S: 236+K heavy (plain script) */
    { { { -264,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { { -264,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: not used by a script */
    { { { -264,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: not used by a script */
    { { { -117,   8,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: not used by a script */
    { { { -117,   8,   0,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -121,  16,   0,  45 },  {    0,   0,   0,   0 } } },  /* 90: not used by a script */
    { { { -104,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: not used by a script */
    { { { -104,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: not used by a script */
    { { { -104,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: not used by a script */
    { { {  -86,  61,  60,  45 },  {   24,  42,  60,  45 },  {  -80,  55,  52,  62 },  {   24,  34,  52,  62 } } },  /* 94: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1; attack 56, 57, 58, 59 ... */
    { { {  -30,  50,  40, 133 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: not used by a script */
    { { {  -56,  36,  39,  48 },  {  -34,  41,  62,  54 },  {  -13,  43,  89,  54 },  {   22,  25, 130,  35 } } },  /* 96: not used by a script */
    { { {  -61,  13,  73,  11 },  {  -37,  13,  86,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A); attack 94 */
    { { {  -91, 185,  89,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: not used by a script */
    { { {  -86,  49, 117,  27 },  {  -53, 111,  99,  31 },  {  -19,  89,  79,  31 },  {   28,  57,  65,  25 } } },  /* 99: not used by a script */
    { { {  -57,  36, 142,  32 },  {  -39,  45, 107,  41 },  {  -19,  62,  79,  47 },  {    7,  61,  51,  58 } } },  /* 100: not used by a script */
    { { {  -13,  38, 142,  36 },  {  -23,  62,  22, 120 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A); attack 95, 96, 103 */
    { { {  -18,  38, 142,  36 },  {  -32,  62,  22, 120 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A); attack 95, 103 */
    { { {  -25,  38, 142,  36 },  {  -33,  62,  22, 120 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -24,  38, 142,  36 },  {  -35,  62,  22, 120 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A); attack 95, 103 */
    { { {  -19,  38, 142,  36 },  {  -32,  62,  83, 226 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -92,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: not used by a script */
    { { { -101,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: not used by a script */
    { { { -112,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: not used by a script */
    { { { -180,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 109: not used by a script */
    { { { -181,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: not used by a script */
    { { { -192,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: not used by a script */
    { { { -260,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: not used by a script */
    { { { -261,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: not used by a script */
    { { { -272,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: not used by a script */
    { { {  -92,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: not used by a script */
    { { { -101,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { { -112,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -82,  30, 105,   5 },  {  -56,  31, 101,   7 } } },  /* 118: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {  -58,  40,  38,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: KAGAMI P A; attack 48 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -58,  40,  38,  26 },  {    0,   0,   0,   0 } } },  /* 120: KAGAMI P A */
    { { {  -64,  42,  30,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: KAGAMI P A; attack 48, 49 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -64,  42,  30,  28 },  {    0,   0,   0,   0 } } },  /* 122: KAGAMI P A */
    { { {  -68,  42,  14,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: KAGAMI P A; attack 50 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -68,  42,  14,  26 },  {    0,   0,   0,   0 } } },  /* 124: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -104,   8,   0,  39 },  {    0,   0,   0,   0 } } },  /* 125: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -184,   8,   0,  39 },  {    0,   0,   0,   0 } } },  /* 126: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -264,   8,   0,  39 },  {    0,   0,   0,   0 } } },  /* 127: not used by a script */
    { { {  -86,   7,  98,   3 },  {  -78,   6,  91,   6 },  {  -73,   8,  83,   8 },  {  -65,  32,  55,  28 } } },  /* 128: not used by a script */
    { { { -166,   5,  51,  21 },  { -172,   4,  59,  22 },  { -184,  12,  63,  27 },  { -172,  16,  90,   6 } } },  /* 129: not used by a script */
    { { { -147,   8,  39,   4 },  { -154,   6,  42,   8 },  { -175,  19,  50,  21 },  { -191,  20,  60,  25 } } },  /* 130: not used by a script */
};

const CATCH_BOX no12_cat_box[53] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -38,   13,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {    0,    0,    0,    0 } },  /* 2: no box */
    { {    0,    0,    0,    0 } },  /* 3: no box */
    { {    0,    0,    0,    0 } },  /* 4: no box */
    { {    0,    0,    0,    0 } },  /* 5: no box */
    { {    0,    0,    0,    0 } },  /* 6: no box */
    { {    0,    0,    0,    0 } },  /* 7: no box */
    { {    0,    0,    0,    0 } },  /* 8: no box */
    { {    0,    0,    0,    0 } },  /* 9: no box */
    { {    0,    0,    0,    0 } },  /* 10: no box */
    { {    0,    0,    0,    0 } },  /* 11: no box */
    { {    0,    0,    0,    0 } },  /* 12: no box */
    { {    0,    0,    0,    0 } },  /* 13: no box */
    { {    0,    0,    0,    0 } },  /* 14: no box */
    { {    0,    0,    0,    0 } },  /* 15: no box */
    { {    0,    0,    0,    0 } },  /* 16: no box */
    { {    0,    0,    0,    0 } },  /* 17: no box */
    { {    0,    0,    0,    0 } },  /* 18: no box */
    { {    0,    0,    0,    0 } },  /* 19: no box */
    { {    0,    0,    0,    0 } },  /* 20: no box */
    { {    0,    0,    0,    0 } },  /* 21: no box */
    { {    0,    0,    0,    0 } },  /* 22: no box */
    { {    0,    0,    0,    0 } },  /* 23: no box */
    { {    0,    0,    0,    0 } },  /* 24: no box */
    { {    0,    0,    0,    0 } },  /* 25: no box */
    { {    0,    0,    0,    0 } },  /* 26: no box */
    { {    0,    0,    0,    0 } },  /* 27: no box */
    { {    0,    0,    0,    0 } },  /* 28: no box */
    { {    0,    0,    0,    0 } },  /* 29: no box */
    { {  -33,    6,    0,   16 } },  /* 30: not used by a script */
    { { -131,   56,    4,   16 } },  /* 31: not used by a script */
    { {    0,    0,    0,    0 } },  /* 32: no box */
    { {    0,    0,    0,    0 } },  /* 33: no box */
    { {    0,    0,    0,    0 } },  /* 34: no box */
    { {    0,    0,    0,    0 } },  /* 35: no box */
    { {    0,    0,    0,    0 } },  /* 36: no box */
    { {    0,    0,    0,    0 } },  /* 37: no box */
    { {    0,    0,    0,    0 } },  /* 38: no box */
    { {    0,    0,    0,    0 } },  /* 39: no box */
    { {    0,    0,    0,    0 } },  /* 40: no box */
    { {  -86,   61,    0,   16 } },  /* 41: not used by a script */
    { {    0,    0,    0,    0 } },  /* 42: no box */
    { {    0,    0,    0,    0 } },  /* 43: no box */
    { {    0,    0,    0,    0 } },  /* 44: no box */
    { {    0,    0,    0,    0 } },  /* 45: no box */
    { {  -37,   10,    0,   16 } },  /* 46: not used by a script */
    { {    0,    0,    0,    0 } },  /* 47: no box */
    { {    0,    0,    0,    0 } },  /* 48: no box */
    { { -127,   40,    4,   16 } },  /* 49: not used by a script */
    { { -123,   40,    4,   16 } },  /* 50: not used by a script */
    { {    0,    0,    0,    0 } },  /* 51: no box */
    { {    0,    0,    0,    0 } },  /* 52: no box */
};

const CAUGHT_BOX no12_cau_box[19] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   16 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +93 */
    { {  -29,   54,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +34 */
    { {  -25,   50,   70,   44 } },  /* 3: JUMP JUNBI, SP JUMP JUNBI, JUMP FRONT +41 */
    { {  -34,   48,   80,   28 } },  /* 4: not used by a script */
    { {  -24,   48,   83,   28 } },  /* 5: not used by a script */
    { {  -31,   48,   84,   28 } },  /* 6: not used by a script */
    { {   -7,   48,   84,   28 } },  /* 7: not used by a script */
    { {  -32,   48,   83,   28 } },  /* 8: not used by a script */
    { {  -55,   48,    0,    8 } },  /* 9: not used by a script */
    { {  -28,   35,   56,   58 } },  /* 10: not used by a script */
    { {  -24,   48,   44,   64 } },  /* 11: not used by a script */
    { {  -22,   48,   42,   37 } },  /* 12: BODY SLAM, IPPONZEOI, TOMOE RYU +27 */
    { {  -33,   58,    0,    8 } },  /* 13: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   -8,   24 } },  /* 14: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU */
    { {  -35,   74,    0,   16 } },  /* 15: not used by a script */
    { {  -60,   96,   48,   27 } },  /* 16: not used by a script */
    { {  -25,   50,   34,   90 } },  /* 17: UP P GUARD P M, ATTACK 8 M: not started by a command */
    { {  -25,   50,    8,   98 } },  /* 18: ATTACK 8 M: not started by a command */
};

