/*
 * GILL_ATTBOX.C  Gill's attack, catch and caught boxes
 *
 * Selected per animation frame through gill_hit_ix_table (atix, caix, cuix). A box is x, width,
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

const ATTACK_BOX gill_att_box[46] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -84,  26,  74,  16 },  {  -66,  26,  82,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A; attack 1 */
    { { {  -72,  22,  72,  18 },  {  -62,  20,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: P BREAK AIR F, TUKAMIHAZUSI, M PUNCH C; attack 2 */
    { { {  -74,  22,  92,  20 },  {  -70,  22, 114,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH C */
    { { {  -56,  22, 104,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -94,  28,  70,  24 },  {  -84,  40,  36,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A; attack 5 */
    { { {  -90,  24,  44,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A */
    { { {  -72,  32,  10,  14 },  {  -62,  30,  22,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: S KICK A; attack 6 */
    { { { -124,  40,  70,  12 },  {  -82,  46,  66,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK A, M KICK C; attack 8 */
    { { { -112,  36,  70,  12 },  {  -74,  38,  66,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M KICK A, M KICK C; attack 8 */
    { { {  -96,  26,  52,  20 },  {  -74,  24,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A, no name; attack 13 */
    { { {  -50,  22, 106,  24 },  {  -54,  22,  72,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A; attack 14 */
    { { { -104,  54,  50,  18 },  {  -80,  80,  68,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {  -82,  20,  46,  16 },  {  -66,  20,  38,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI P A, no name; attack 12 */
    { { {  -54,  28,  62,  20 },  {  -46,  24,  42,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A; attack 28 */
    { { { -100,  72,   0,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A; attack 15, 16 */
    { { {  -80,  22,  64,  18 },  {  -62,  22,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P L A */
    { { {  -56,  22,  68,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P S A; attack 18 */
    { { {  -92,  24,  86,  14 },  {  -74,  24,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A */
    { { {  -48,  20,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP K S A; attack 29 */
    { { {  -50,  24,  71,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { { -108,  76,  80,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP K M A; attack 30 */
    { { {  -94,  56,  80,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K M A, ATTACK 4 M: not started by a command; attack 20 */
    { { { -120,  44,  48,  16 },  {  -82,  52,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { { -108,  40,  52,  16 },  {  -74,  44,  60,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: V JUMP K L A; attack 31 */
    { { {  -89,  56,  55,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: follow-up of APPEAR JUNBI 6 */
    { { {  -30,  56,  54,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -36,  56,  40,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { { -120,  56,  42,  22 },  {  -84,  84,  64,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: no box */
    { { {  -38,  44,  46,  20 },  {  -18,  30,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP); attack 24 */
    { { {  -54,  28,  62,  22 },  {  -38,  22,  54,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP); attack 25 */
    { { {  -33,  12,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP); attack 32 */
    { { {  -78,  50,  68,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP); attack 33 */
    { { {  -74,  28,  76,  22 },  {  -64,  24,  92,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU); attack 26 */
    { { { -104,  40,  66,  22 },  {  -70,  42,  78,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -94,  30,  72,  16 },  {  -70,  30,  78,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: M PUNCH A; attack 3 */
    { { {  -58,  34, 122,  24 },  {  -28,  28, 132,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L KICK A; attack 9 */
    { { { -112,  60,  64,  48 },  {  -90,  50,  96,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L KICK A; attack 10 */
    { { {  -92,  36,  12,  28 },  { -104,  32,  32,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK A */
    { { { -108,  80,   0,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: not used by a script */
    { { { -124,  94,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI K A; attack 17 */
    { { { -112,  22,  76,  16 },  {  -88,  48,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP P M A; attack 19 */
    { { {  -96,  28,  70,  24 },  { -100,  26,  90,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P L A; attack 20 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  38,  31,  30 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command; attack 34 */
};

const CATCH_BOX gill_cat_box[2] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -52,   28,    0,   16 } },  /* 1: TUKAMIKAKARI A */
};

const CAUGHT_BOX gill_cau_box[8] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   16 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +81 */
    { {  -28,   52,    0,    8 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +36 */
    { {  -24,   48,   54,   60 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP P L A +25 */
    { {  -24,   48,    0,   16 } },  /* 4: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { {  -32,   56,    0,    8 } },  /* 5: KAGAMI P A, no name, KAGAMI K A */
    { {  -32,   64,    0,   16 } },  /* 6: DASH HUMIKOMI, no name */
    { {  -23,   48,   34,   58 } },  /* 7: TUKAMIHAZUSI, no name, BODY SLAM +26 */
};

