/*
 * HUGO_ATTBOX.C  Hugo's attack, catch and caught boxes
 *
 * Selected per animation frame through hugo_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX hugo_att_box[65] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -121,  34,  61,  17 },  {  -85,  51,  61,  17 } } },  /* 1: S PUNCH A; attack 1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -111,  24,  62,  10 },  {  -86,  53,  62,  10 } } },  /* 2: S PUNCH A; attack 1 */
    { { { -117,  60,  58,  27 },  {  -89,  58,  78,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A; attack 2 */
    { { { -108,  49,  58,  29 },  {  -89,  58,  78,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A; attack 2 */
    { { {  -87,  36,  51,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A; attack 3 */
    { { {  -78,  21,  64,  23 },  {  -57,  13,  67,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A */
    { { {  -99,  35,  82,  30 },  {  -64,  40,  86,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH B; attack 6 */
    { { {  -92,  28,  92,  27 },  {  -64,  39,  88,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH B */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  13,  24,  22 },  {  -93,  60,  33,  13 } } },  /* 9: S KICK A; attack 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -96,  23,  26,  16 },  {  -73,  32,  34,  12 } } },  /* 10: S KICK A */
    { { { -103,  29,  88,  28 },  {  -79,  33,  70,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M KICK A; attack 8 */
    { { {  -98,  24,  88,  19 },  {  -74,  29,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M KICK A */
    { { { -106,  58,  24,  58 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2; attack 9, 10, 11, 33 ... */
    { { {  -98,  29,  56,  27 },  {  -68,  37,  67,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L KICK A; attack 12 */
    { { {  -88,  22,  63,  21 },  {  -66,  32,  63,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -120,  28,  32,  17 },  {  -92,  48,  32,  17 } } },  /* 16: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -114,  19,  32,  17 },  {  -96,  54,  33,  15 } } },  /* 17: KAGAMI P A; attack 14 */
    { { { -123,  32,  32,  17 },  {  -92,  50,  32,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P A; attack 15 */
    { { { -120,  29,  32,  17 },  {  -92,  47,  33,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -104,  19,   0,  16 },  {  -85,  50,   0,  16 } } },  /* 20: KAGAMI K A; attack 16 */
    { { { -123,  25,   0,  25 },  {  -98,  67,   0,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI K A; attack 24 */
    { { { -117,  21,   0,  24 },  {  -96,  65,   0,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI K A */
    { { {  -50,  24,  91,  16 },  {  -44,  27,  72,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A; attack 17 */
    { { {  -52,  26,  88,  15 },  {  -42,  27,  73,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI P A; attack 18 */
    { { {  -56,  27,  77,  14 },  {  -46,  24,  57,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: not used by a script */
    { { {  -63,  23,  75,  12 },  {  -50,  25,  60,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -52,  37,  44,  24 },  {  -39,  24,  37,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI K A; attack 19 */
    { { {  -46,  37,  42,  21 },  {  -33,  24,  35,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI K A; attack 19 */
    { { {  -44,  37,  38,  17 },  {  -31,  24,  31,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI K A; attack 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -99,  26,   0,  16 },  {  -73,  47,   0,  16 } } },  /* 30: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  29,  76,  20 },  {  -81,  37,  91,  16 } } },  /* 31: V JUMP P S A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -95,  30,  84,  19 },  {  -75,  38,  98,  15 } } },  /* 32: V JUMP P S A; attack 25 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  31,  95,  15 },  {  -67,  33, 102,  16 } } },  /* 33: V JUMP P S A; attack 25 */
    { { { -121,  37,  89,  32 },  {  -84,  52,  93,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP P L A; attack 28 */
    { { { -105,  27,  89,  31 },  {  -79,  46,  93,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P L A; attack 28 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -63,  19,  60,  24 },  {  -58,  30,  73,  16 } } },  /* 36: V JUMP K S A; attack 29 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -58,  16,  60,  22 },  {  -51,  27,  73,  14 } } },  /* 37: V JUMP K S A; attack 29 */
    { { {  -60,  19,  53,  27 },  {  -50,  30,  70,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP K M A; attack 30 */
    { { {  -56,  18,  53,  25 },  {  -48,  28,  70,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K M A */
    { { {  -96,  25,  60,  33 },  {  -71,  43,  67,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K L A; attack 31 */
    { { {  -92,  20,  62,  29 },  {  -72,  36,  69,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K L A; attack 31 */
    { { {  -89,  25,  58,  36 },  {  -70,  64,  66,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: not used by a script */
    { { {  -81,  35,  34,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: M KICK A; attack 32 */
    { { { -120,  41,  84,  17 },  {  -85,  41,  95,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P M A; attack 27 */
    { { { -109,  45,  87,  18 },  {  -79,  39,  98,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P M A; attack 27 */
    { { {  -99,  37,  95,  17 },  {  -67,  33, 103,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP P M A; attack 27 */
    { { {  -38,  18,  68,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +2; attack 41, 42, 43, 66 ... */
    { { {  -35,  18,  68,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -61,  38,  82,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -63,  62,  86,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: not used by a script */
    { { {  -44,  72,  71,  21 },  {  -69,  43,  79,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P L B; attack 53 */
    { { {  -90, 200,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: CATCH 29; attack 58 */
    { { {  -74,  59,  49,  66 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 62 */
    { { {  -63,  49,  36,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP); attack 59 */
    { { {  -57,  43,  36,  68 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    { { {  -72,  66,  56,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    { { { -103,  44,  60,  42 },  {  -59,  45,  68,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 60 */
    { { {  -98,  58,  47,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 61 */
    { { { -116,  71,  34,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 63 */
    { { { -100,  32, 108,  16 },  {  -68,  32, 100,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 9 M: not started by a command; attack 64 */
    { { {  -93,  36,  74,  38 },  {  -64,  52,  76,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 60 */
    { { {  -83,  29,  60,  31 },  {  -57,  26,  62,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP); attack 61 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -58,  40,  34,  32 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 10 S: not started by a command; attack 65 */
    { { {  -42,  52,  79,  54 },  {  -28,  49,  63,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: CATCH 38, CATCH 39, CATCH 40; attack 69 */
};

const CATCH_BOX hugo_cat_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -62,   32,    0,   16 } },  /* 1: TUKAMIKAKARI A */
    { {  -76,   44,    0,   16 } },  /* 2: ATTACK 3 S: 360+P light (plain script) */
    { {  -70,   38,    0,   16 } },  /* 3: ATTACK 3 M: 360+P medium (plain script) */
    { {  -64,   32,    0,   16 } },  /* 4: ATTACK 3 L: 360+P heavy/EX (plain script) */
    { {  -51,   30,   76,   41 } },  /* 5: ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    { {  -72,   51,   60,   73 } },  /* 6: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    { {  -87,   55,    0,   16 } },  /* 7: ATTACK 6 S: SA I 720+P (plain script) */
    { {  -55,   23,    0,   16 } },  /* 8: ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 4 M: 6(123)4+K medium (plain script), ATTACK 4 L: 6(123)4+K heavy/EX (plain script) */
    { {  -64,   32,    0,   16 } },  /* 9: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    { {  -60,   39,   75,   35 } },  /* 10: ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { {  -55,   34,   71,   51 } },  /* 11: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN) */
};

const CAUGHT_BOX hugo_cau_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -30,   60,    0,   16 } },  /* 1: KAMAE, DASH HUMIKOMI, DASH TOBINOKI +95 */
    { {  -34,   64,    0,    8 } },  /* 2: KAGAMI KAMAE, PARING DOWN, GUARD DOWN +30 */
    { {  -27,   54,   63,   58 } },  /* 3: GUARD AIR, V JUMP P S A, V JUMP P M A +30 */
    { {  -41,   67,    0,   16 } },  /* 4: DASH HUMIKOMI */
    { {  -38,   62,    0,   16 } },  /* 5: DASH TOBINOKI */
    { {  -41,   65,   34,   58 } },  /* 6: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   34,   58 } },  /* 7: AIR NORMAL, TTKI V. AIR, BODY SLAM +27 */
    { {  -57,   62,   23,   58 } },  /* 8: not used by a script */
    { {  -51,   81,   77,   41 } },  /* 9: V JUMP P L B */
    { {  -38,   68,    0,    8 } },  /* 10: KAGAMI P A, KAGAMI K A */
    { {  -40,   75,    0,   16 } },  /* 11: ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 6 S: SA I 720+P (plain script) +4 */
};

