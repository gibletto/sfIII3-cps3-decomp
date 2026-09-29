/*
 * ELENA_HITBOX.C  Elena's hit boxes
 *
 * Each of Elena's animation frames names an entry of elena_hit_ix_table (cg_hit_ix in the frame
 * record). The entry picks the boxes that frame uses; set_char_base_data (CHARID) points the work
 * at these tables through char_init_data. A box is x, width, y, height from the character's
 * position, x mirrored when facing left; width 0 means no box.
 *
 * hit_ix_table  one row per animation frame pose (a script line's hit field picks it); each column
 *               picks a row of one box table (0 = none):
 *     boix  body box: where this character can be hit (body_box)
 *     bhix  hand box base + haix hand box offset: extra hurt boxes on an extended arm or leg
 *           (hand_box[bhix + haix])
 *     mf    two hit-kind codes the debug viewer names (hit_kind_tbl: u/a/d pairs); in play only the
 *           after-image effect reads them
 *     caix  catch box: this frame's throw reach (cat_box in _attbox.c)
 *     cuix  caught box: where this character can be thrown (cau_box in _attbox.c)
 *     atix  attack box: where this frame hits (att_box in _attbox.c)
 *     hoix  push box: keeps the two fighters apart (hos_box)
 * body_box      four damage boxes (head down to legs)
 * hand_box      four damage boxes for an extended arm or leg
 * hos_box       the push box: where two fighters' push boxes overlap they are moved apart
 *
 * Row comments: the moves whose frames use the row or box (debug viewer names). Row 0 of a
 * box table is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const HIT_IX elena_hit_ix_table[465] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +11 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: STAND UP, WALK END, PARING HEAD +64 */
    {    2,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 2: BODY SLAM, TOMOE RYU, TOMOE ORO +1 */
    {    3,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 3: KAGAMU, KAGAMI KAMAE, PARING DOWN +31 */
    {   11,    0,    0, 0x1510,    0,    1,    0,   10 },  /* 4: follow-up of S PUNCH A, S PUNCH C +14, no name, PIYO +1 */
    {    4,    0,    0, 0x1515,    0,    3,    0,    3 },  /* 5: JUMP FRONT, SP JUMP FRONT, GUARD AIR +1 */
    {    5,    0,    0, 0x1616,    0,    3,    0,    3 },  /* 6: JUMP FRONT, SP JUMP FRONT, PARING AIR F +18 */
    {    6,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 7: JUMP FRONT, SP JUMP FRONT, PARING AIR F +3 */
    {    7,    0,    0, 0x1010,    0,    6,    0,    5 },  /* 8: DASH HUMIKOMI */
    {    8,    0,    0, 0x0000,    0,    6,    0,    5 },  /* 9: DASH HUMIKOMI */
    {    9,    0,    0, 0x1A16,    0,    1,    0,    1 },  /* 10: DASH HUMIKOMI, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   10,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 11: DASH HUMIKOMI */
    {   12,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 12: GUARD AIR */
    {  185,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 13: ATTACK 7 M: not started by a command, SP APPEAR 1 */
    {   13,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 14: KAGAMI TURN */
    {   14,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 15: KAGAMI TURN */
    {   15,    0,    0, 0x1111,    0,    1,    0,   10 },  /* 16: HURIMUKI */
    {   16,    0,    0, 0x1111,    0,    1,    0,   10 },  /* 17: HURIMUKI */
    {   17,    0,    0, 0x1111,    0,    1,    0,   10 },  /* 18: HURIMUKI */
    {   18,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 19: HURIMUKI */
    {   19,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 20: KAGAMI P A */
    {   21,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 21: KAGAMI P A */
    {   22,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 22: KAGAMI P A */
    {   21,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 23: KAGAMI P A */
    {   22,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 24: KAGAMI P A */
    {   23,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 25: KAGAMI K A */
    {   24,    0,    2, 0x0000,    0,    7,    2,    2 },  /* 26: KAGAMI K A */
    {   24,    0,    2, 0x0000,    0,    7,    0,    2 },  /* 27: KAGAMI K A */
    {   25,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 28: KAGAMI K A */
    {   26,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 29: KAGAMI K A */
    {   27,    0,    3, 0x0000,    0,    2,    3,    2 },  /* 30: not used by a script */
    {   27,    0,    3, 0x0000,    0,    2,    0,    2 },  /* 31: KAGAMI P A */
    {   28,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 32: KAGAMI P A, KAGAMI K A, follow-up of M KICK A +2 */
    {   29,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 33: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   30,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 34: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   31,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 35: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   32,    0,    4, 0x0000,    0,    2,    4,    2 },  /* 36: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   32,    0,    4, 0x0000,    0,    2,    0,    2 },  /* 37: KAGAMI P A, follow-up of M KICK A, ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) */
    {   33,    0,    5, 0x0000,    0,    2,    0,    2 },  /* 38: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   34,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 39: KAGAMI K A */
    {   35,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 40: KAGAMI K A */
    {   36,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 41: KAGAMI K A */
    {   37,    0,    6, 0x0000,    0,    2,    5,    2 },  /* 42: not used by a script */
    {   37,    0,    6, 0x0000,    0,    2,    0,    2 },  /* 43: KAGAMI K A */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 44: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   39,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 45: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   40,    0,    0, 0x0000,    0,    3,    6,    3 },  /* 46: V JUMP P S A, F JUMP P S A */
    {  107,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +10 */
    {  108,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 48: V JUMP P M A, V JUMP P L A, V JUMP K S A +7 */
    {  109,    0,   27, 0x0000,    0,    3,    7,    3 },  /* 49: V JUMP P M A, F JUMP P M A */
    {  109,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 50: V JUMP P M A, F JUMP P M A */
    {  110,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 51: V JUMP P L A, F JUMP P L A */
    {  111,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 52: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  112,    0,   28, 0x0000,    0,    3,    8,    3 },  /* 53: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  112,    0,   28, 0x0000,    0,    3,    0,    3 },  /* 54: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    {  114,    0,   29, 0x0000,    0,    3,    0,    3 },  /* 55: V JUMP K S A, F JUMP K S A */
    {  114,    0,   29, 0x0000,    0,    3,    9,    3 },  /* 56: V JUMP K S A, F JUMP K S A */
    {  115,    0,   30, 0x0000,    0,    3,   10,    3 },  /* 57: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    {  115,    0,   30, 0x0000,    0,    3,    0,    3 },  /* 58: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    {    0,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 59: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 60: follow-up of AIR NORMAL */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 61: GUARD HEAD, GUARD UP, APPEAR 1 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 62: GUARD UP, GUARD AIR, HUSHIN HEAD +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 63: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    {   32,    0,    4, 0x0000,    0,    2,   91,    2 },  /* 64: follow-up of M KICK A */
    {   46,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 65: not used by a script */
    {   47,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 66: not used by a script */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 67: follow-up of SP WIN 2 */
    {   49,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 68: HUSHIN HEAD, HUSHIN DOWN, follow-up of SP WIN 2 */
    {   50,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 69: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI */
    {   51,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 70: not used by a script */
    {   52,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 71: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 72: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   54,    0,   11, 0x0000,    0,    1,   26,    1 },  /* 73: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   54,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 74: M PUNCH C */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 75: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   56,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 76: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   57,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 77: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   58,    0,   12, 0x0000,    0,    1,   49,    2 },  /* 78: M PUNCH A */
    {   59,    0,   13, 0x0000,    0,    1,   27,    2 },  /* 79: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   59,    0,   13, 0x0000,    0,    1,    0,    2 },  /* 80: M PUNCH A */
    {   60,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 81: M PUNCH A */
    {   61,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 82: M PUNCH A */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 83: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 84: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   64,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   65,    0,   14, 0x0000,    0,    1,   28,    1 },  /* 86: not used by a script */
    {   65,    0,   14, 0x0000,    0,    1,   41,    1 },  /* 87: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   66,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 88: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {   67,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 89: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   68,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 90: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   69,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 91: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   70,    0,   15, 0x0000,    0,    8,   29,    8 },  /* 92: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   71,    0,   16, 0x0000,    0,    8,   29,    8 },  /* 93: L KICK A, follow-up of L PUNCH A */
    {   71,    0,   16, 0x0000,    0,    8,    0,    8 },  /* 94: L KICK A, follow-up of L PUNCH A */
    {   72,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 95: L KICK A, follow-up of L PUNCH A */
    {   73,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 96: L KICK A, follow-up of L PUNCH A */
    {   74,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 97: S PUNCH A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   75,    0,   17, 0x0000,    0,    1,   30,    1 },  /* 98: S PUNCH A */
    {   75,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 99: S PUNCH A */
    {   75,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 100: not used by a script */
    {   76,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 101: S PUNCH A */
    {   77,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 102: S PUNCH A */
    {   78,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 103: S KICK A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   79,    0,   18, 0x0000,    0,    1,   32,    1 },  /* 104: S KICK A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   79,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 105: S KICK A */
    {   81,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 106: S KICK A */
    {   82,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 107: KAGAMI K C */
    {   83,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 108: KAGAMI K C */
    {  206,    0,    0, 0x0000,    0,    2,   33,    2 },  /* 109: not used by a script */
    {   84,    0,   19, 0x0000,    0,    2,   33,    2 },  /* 110: KAGAMI K C */
    {   84,    0,   19, 0x0000,    0,    2,    0,    2 },  /* 111: KAGAMI K C */
    {   86,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 112: KAGAMI K C */
    {   87,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 113: KAGAMI K C */
    {   88,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 114: KAGAMI K C */
    {   89,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 115: KAGAMI K C */
    {   90,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 116: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
    {   91,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 117: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   92,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 118: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   93,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 119: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   94,    0,   21, 0x0000,    0,    3,    0,    3 },  /* 120: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 121: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +5 */
    {   96,    0,   22, 0x0000,    0,    1,   35,    1 },  /* 122: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   97,    0,   23, 0x0000,    0,    1,   36,    1 },  /* 123: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   98,    0,   24, 0x0000,    0,    1,    0,    1 },  /* 124: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    {   99,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 125: not used by a script */
    {  100,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 126: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  101,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 127: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  102,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 128: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  103,    0,   25, 0x0000,    0,    1,   37,    2 },  /* 129: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  104,    0,   26, 0x0000,    0,    1,    0,    2 },  /* 130: M KICK A */
    {  105,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 131: M KICK A */
    {  106,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 132: M KICK A */
    {   97,    0,   23, 0x0000,    0,    1,    0,    1 },  /* 133: not used by a script */
    {  116,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 134: V JUMP K L A, F JUMP K L A */
    {  117,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 135: V JUMP K L A, F JUMP K L A */
    {  118,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 136: V JUMP K L A, F JUMP K L A */
    {  119,    0,   31, 0x0000,    0,    3,   11,    3 },  /* 137: V JUMP K L A, F JUMP K L A */
    {  120,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 138: V JUMP K L A, F JUMP K L A */
    {  121,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 139: V JUMP K L A, F JUMP K L A */
    {  122,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 140: V JUMP K L A, F JUMP K L A */
    {  123,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 141: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  124,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 142: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  125,    0,   32, 0x0000,    0,    2,   12,    2 },  /* 143: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  126,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 144: KAGAMI K A */
    {  127,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 145: KAGAMI K A */
    {  128,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 146: KAGAMI K A */
    {  129,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 147: KAGAMI K A */
    {  130,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 148: KAGAMI K A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 149: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {  131,    0,    0, 0x0000,    0,    2,    0,    4 },  /* 150: not used by a script */
    {  132,    0,   33, 0x0000,    0,    2,   13,    4 },  /* 151: not used by a script */
    {  132,    0,   33, 0x0000,    0,    2,    0,    4 },  /* 152: not used by a script */
    {  133,    0,    0, 0x0000,    0,    2,    0,    4 },  /* 153: not used by a script */
    {  134,    0,    0, 0x0000,    0,    2,    0,    4 },  /* 154: not used by a script */
    {  135,    0,    0, 0x0000,    0,    2,    0,    4 },  /* 155: not used by a script */
    {  136,    0,    0, 0x0000,    0,    2,    0,    4 },  /* 156: not used by a script */
    {  137,    0,   34, 0x0000,    0,    3,   14,    3 },  /* 157: not used by a script */
    {  138,    0,   35, 0x0000,    0,    3,   15,    3 },  /* 158: not used by a script */
    {   80,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 159: not used by a script */
    {  140,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 160: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  141,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 161: not used by a script */
    {  142,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 162: not used by a script */
    {  143,    0,    0, 0x1515,    0,    1,    0,    2 },  /* 163: DASH TOBINOKI */
    {  144,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 164: DASH TOBINOKI */
    {  145,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 165: DASH TOBINOKI */
    {  146,    0,    0, 0x1414,    0,    1,    0,    2 },  /* 166: DASH TOBINOKI */
    {  147,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 167: DASH TOBINOKI */
    {  148,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 168: DASH TOBINOKI */
    {  149,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 169: DASH TOBINOKI */
    {  150,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 170: DASH TOBINOKI */
    {    1,    0,    0, 0x0000,    0,    1,   16,    1 },  /* 171: not used by a script */
    {  181,    0,    0, 0x0000,    0,    5,   54,    6 },  /* 172: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  182,    0,   45, 0x0000,    0,    5,   38,    6 },  /* 173: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {   98,    0,   24, 0x0000,    0,    1,   25,    1 },  /* 174: follow-up of APPEAR 1, follow-up of SP WIN 3, follow-up of SP WIN 4 */
    {  183,    0,   46, 0x0000,    0,    9,   39,    9 },  /* 175: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  184,    0,   47, 0x0000,    0,    9,   40,    9 },  /* 176: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  118,    0,    0, 0x0000,    0,    3,   42,    3 },  /* 177: V JUMP K L A, F JUMP K L A */
    {  156,    0,    0, 0x0000,    0,    0,    0,    6 },  /* 178: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  157,    0,   37, 0x0000,    0,    5,   17,    6 },  /* 179: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  158,    0,   38, 0x0000,    0,    9,   18,    9 },  /* 180: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  159,    0,   39, 0x0000,    0,    9,    0,    9 },  /* 181: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  160,    0,    0, 0x0000,    0,    9,    0,    9 },  /* 182: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  161,    0,    0, 0x0000,    0,    9,    0,    9 },  /* 183: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  162,    0,    0, 0x0000,    0,    9,    0,    9 },  /* 184: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  163,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 185: follow-up of APPEAR JUNBI 7, follow-up of SP WIN 6, follow-up of SP WIN 7 */
    {  164,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 186: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  165,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 187: S PUNCH C, ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  166,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 188: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  167,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 189: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  168,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 190: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  169,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 191: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  170,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 192: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    {  171,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 193: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  172,    0,   40, 0x0000,    0,    3,   20,    3 },  /* 194: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  173,    0,   41, 0x0000,    0,    3,   21,    3 },  /* 195: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  174,    0,   42, 0x0000,    0,    3,   22,    3 },  /* 196: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  175,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 197: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  176,    0,   43, 0x0000,    0,    3,   23,    3 },  /* 198: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  176,    0,   43, 0x0000,    0,    3,    0,    3 },  /* 199: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  177,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 200: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  178,    0,    0, 0x0000,    0,    9,    0,    9 },  /* 201: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  179,    0,   44, 0x0000,    0,    5,   24,    6 },  /* 202: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  179,    0,   44, 0x0000,    0,    5,    0,    6 },  /* 203: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    {  180,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 204: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    {  186,    0,   48, 0x0000,    0,    1,    0,    1 },  /* 205: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  187,    0,   49, 0x0000,    0,    1,   43,    1 },  /* 206: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  188,    0,   50, 0x0000,    0,    1,   44,    1 },  /* 207: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  189,    0,   51, 0x0000,    0,    1,   45,    1 },  /* 208: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  190,    0,   52, 0x0000,    0,    1,   46,    1 },  /* 209: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  191,    0,   53, 0x0000,    0,    1,   47,    1 },  /* 210: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  192,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 211: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  193,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 212: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  194,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 213: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  195,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 214: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  196,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 215: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  197,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 216: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  198,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 217: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  199,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 218: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  200,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 219: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  201,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 220: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  202,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 221: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  203,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 222: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  204,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 223: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    1,   44,    1 },  /* 224: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  223,    0,   67, 0x0000,    0,    1,   31,    1 },  /* 225: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  119,    0,   31, 0x0000,    0,    3,    0,    3 },  /* 226: V JUMP K L A, F JUMP K L A */
    {  260,    0,    0, 0x0000,    0,    3,   62,    3 },  /* 227: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  103,    0,   25, 0x0000,    0,    1,    0,    2 },  /* 228: M KICK A, follow-up of M KICK A */
    {  205,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 229: not used by a script */
    {  209,    0,   56, 0x0000,    0,    7,    1,    2 },  /* 230: KAGAMI P A */
    {   27,    0,    3, 0x0000,    0,    2,    3,    2 },  /* 231: KAGAMI P A */
    {   55,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 232: M PUNCH C */
    {  211,    0,   57, 0x0000,    0,    2,    0,    2 },  /* 233: KAGAMI K A */
    {  211,    0,   57, 0x0000,    0,    2,    5,    2 },  /* 234: KAGAMI K A */
    {  125,    0,   32, 0x0000,    0,    2,    0,    2 },  /* 235: KAGAMI K A */
    {  174,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 236: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    {  224,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 237: ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    {  207,    0,   54, 0x0000,    0,    1,   28,    1 },  /* 238: L PUNCH A */
    {   65,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 239: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  208,    0,   55, 0x0000,    0,    1,    0,    1 },  /* 240: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    {  210,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 241: KAGAMI P A */
    {  212,    0,   58, 0x0000,    0,    1,    0,    2 },  /* 242: M PUNCH A */
    {  213,    0,   59, 0x0000,    0,    8,   50,    8 },  /* 243: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {  214,    0,   60, 0x0000,    0,    8,   51,    8 },  /* 244: L KICK A, follow-up of L PUNCH A */
    {  215,    0,   61, 0x0000,    0,    1,    0,    2 },  /* 245: M KICK A, follow-up of M KICK A */
    {  216,    0,    0, 0x0000,    0,    0,    0,    6 },  /* 246: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  217,    0,   62, 0x0000,    0,    5,    0,    6 },  /* 247: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  218,    0,   63, 0x0000,    0,    9,   19,    9 },  /* 248: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  219,    0,    0, 0x0000,    0,    0,    0,    6 },  /* 249: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  219,    0,    0, 0x0000,    0,    5,   54,    6 },  /* 250: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  220,    0,   64, 0x0000,    0,    5,   52,    6 },  /* 251: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  221,    0,   65, 0x0000,    0,    9,   53,    9 },  /* 252: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  388,    0,    0, 0x0000,    1,    1,   58,    1 },  /* 253: TUKAMIKAKARI B */
    {  273,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 254: ATTACK 7 L: not started by a command */
    {  222,    0,   66, 0x0000,    0,    3,   11,    3 },  /* 255: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    7 },  /* 256: NEKOROBI S, no name */
    {  210,    0,    0, 0x0000,    0,    7,    0,    2 },  /* 257: KAGAMI P A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 258: follow-up of JUDGMENT WIN */
    {    3,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 259: follow-up of JUDGMENT WIN */
    {   40,    0,    0, 0x0000,    0,    3,   63,    3 },  /* 260: ATTACK 7 L: not started by a command */
    {  207,    0,   54, 0x0000,    0,    1,   64,    1 },  /* 261: ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 262: LOSE SONABA, SHIMEOTASARE */
    {  225,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 263: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  226,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 264: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  227,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 265: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  228,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 266: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  229,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 267: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  230,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 268: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  231,    0,   68, 0x0000,    0,    1,   65,    2 },  /* 269: not used by a script */
    {  232,    0,   69, 0x0000,    0,    1,    0,    2 },  /* 270: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  232,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 271: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  233,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 272: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  234,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 273: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  235,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 274: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    {  236,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 275: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  237,    0,   70, 0x0000,    0,    1,    0,    1 },  /* 276: not used by a script */
    {  238,    0,   71, 0x0000,    0,    1,    0,    1 },  /* 277: not used by a script */
    {  239,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 278: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  240,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 279: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  241,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 280: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  242,    0,   72, 0x0000,    0,    1,   67,    2 },  /* 281: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  243,    0,   73, 0x0000,    0,    1,   68,    2 },  /* 282: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  244,    0,   74, 0x0000,    0,    1,    0,    2 },  /* 283: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  245,    0,   75, 0x0000,    0,    1,    0,    2 },  /* 284: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  246,    0,   76, 0x0000,    0,    1,   70,    2 },  /* 285: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  247,    0,   77, 0x0000,    0,    1,    0,    2 },  /* 286: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  248,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 287: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  249,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 288: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  250,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 289: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  251,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 290: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  252,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 291: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  253,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 292: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  254,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 293: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {    1,    0,    7, 0x0000,    0,    1,   72,    1 },  /* 294: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    {    1,    0,    8, 0x0000,    0,    1,   73,    1 },  /* 295: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 296: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   74,    6 },  /* 297: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  256,    0,    0, 0x0000,    0,    5,   75,    6 },  /* 298: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  257,    0,    9, 0x0000,    0,    9,   76,    9 },  /* 299: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  258,    0,   10, 0x0000,    0,    9,   77,    9 },  /* 300: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  258,    0,   10, 0x0000,    0,    9,    0,    9 },  /* 301: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  180,    0,    0, 0x0000,    0,    1,   78,    1 },  /* 302: not used by a script */
    {  259,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 303: ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
    {  151,    0,    0, 0x0000,    0,    0,    0,    7 },  /* 304: no name */
    {    0,    0,    0, 0x0000,    0,    1,   45,    1 },  /* 305: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  190,    0,    0, 0x0000,    0,    1,   46,    1 },  /* 306: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  191,    0,    0, 0x0000,    0,    1,   47,    1 },  /* 307: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    {  172,    0,    0, 0x0000,    0,    3,   20,    3 },  /* 308: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  173,    0,   78, 0x0000,    0,    3,   21,    3 },  /* 309: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  174,    0,   79, 0x0000,    0,    3,   22,    3 },  /* 310: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  176,    0,   80, 0x0000,    0,    3,   23,    3 },  /* 311: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  179,    0,   81, 0x0000,    0,    5,   24,    6 },  /* 312: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    {  261,    0,    0, 0x1414,    0,    1,    0,   10 },  /* 313: KAMAE */
    {  262,    0,    0, 0x1914,    0,    1,    0,   10 },  /* 314: KAMAE */
    {  263,    0,    0, 0x1018,    0,    1,    0,   10 },  /* 315: KAMAE */
    {  264,    0,    0, 0x1210,    0,    1,    0,   10 },  /* 316: KAMAE */
    {  265,    0,    0, 0x1810,    0,    1,    0,   10 },  /* 317: KAMAE */
    {  266,    0,    0, 0x1010,    0,    1,    0,   10 },  /* 318: KAMAE */
    {  267,    0,    0, 0x1A14,    0,    1,    0,   10 },  /* 319: KAMAE */
    {  268,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 320: FRONT WALK, BACK WALK */
    {  269,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 321: FRONT WALK, BACK WALK */
    {  270,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 322: FRONT WALK, BACK WALK */
    {    1,    0,    0, 0x1212,    0,    2,    0,    2 },  /* 323: KAGAMU */
    {    3,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 324: STAND UP */
    {  271,    0,    0, 0x1010,    0,    3,    0,   10 },  /* 325: JUMP JUNBI */
    {  272,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 326: JUMP JUNBI, SP JUMP JUNBI */
    {  273,    0,    0, 0x1010,    0,    3,    0,   10 },  /* 327: SP JUMP JUNBI */
    {    3,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 328: KAGAMI KAMAE */
    {  274,    0,    0, 0x1410,    0,    2,    0,    2 },  /* 329: not used by a script */
    {  275,    0,    0, 0x1110,    0,    1,    0,   10 },  /* 330: PIYO */
    {  276,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 331: UPPER L */
    {  277,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 332: UPPER L */
    {  278,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 333: UPPER L */
    {  279,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 334: UPPER L */
    {  280,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 335: FACE S, FACE M, FACE L +7 */
    {  281,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 336: FACE M, FACE L, FOOK TEMAE L +4 */
    {  282,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 337: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    {  283,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 338: FACE L, FOOK TEMAE SP */
    {  284,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 339: BODY BROW S, NOUTEN M, NOUTEN L +2 */
    {  285,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 340: NOUTEN M, NOUTEN L */
    {  286,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 341: NOUTEN L */
    {  287,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 342: NOUTEN L, TATAKI S, TATAKI V. S */
    {  288,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 343: KAGAMI S, KAGAMI M, KAGAMI L +5 */
    {  289,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 344: KAGAMI M, KAGAMI L, KGM TATAKI S +3 */
    {  290,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 345: KAGAMI L */
    {  291,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 346: KAGAMI L */
    {  292,    0,   82, 0x0000,    0,    1,    0,    1 },  /* 347: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  293,    0,   83, 0x0000,    0,    1,    0,    1 },  /* 348: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  294,    0,   84, 0x0000,    0,    1,    0,    1 },  /* 349: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  295,    0,   85, 0x0000,    0,    1,   79,    1 },  /* 350: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  296,    0,   86, 0x0000,    0,    1,   80,    1 },  /* 351: ATTACK 12 S: EX 421+KK (plain script) */
    {  297,    0,   87, 0x0000,    0,    1,    0,    1 },  /* 352: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  298,    0,   88, 0x0000,    0,    1,    0,    1 },  /* 353: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  299,    0,   89, 0x0000,    0,    1,   81,    1 },  /* 354: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  300,    0,   90, 0x0000,    0,    1,   82,    1 },  /* 355: ATTACK 12 S: EX 421+KK (plain script) */
    {  301,    0,   91, 0x0000,    0,    1,    0,    1 },  /* 356: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  302,    0,   92, 0x0000,    0,    1,    0,    1 },  /* 357: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  303,    0,   93, 0x0000,    0,    1,    0,    1 },  /* 358: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  304,    0,   94, 0x0000,    0,    1,    0,    1 },  /* 359: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  305,    0,   95, 0x0000,    0,    1,    0,    1 },  /* 360: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    {  306,    0,   96, 0x0000,    0,    1,    0,    1 },  /* 361: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    {  307,    0,   97, 0x0000,    0,    1,    0,    1 },  /* 362: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    {  308,    0,   98, 0x0000,    0,    1,    0,    1 },  /* 363: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    {  309,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 364: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    {  310,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 365: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    {  311,    0,   99, 0x0000,    0,    1,    0,    1 },  /* 366: M KICK C */
    {  312,    0,  100, 0x0000,    0,    1,    0,    1 },  /* 367: M KICK C */
    {  313,    0,  101, 0x0000,    0,    1,    0,    1 },  /* 368: M KICK C */
    {  314,    0,  102, 0x0000,    0,    1,   83,    1 },  /* 369: M KICK C */
    {  315,    0,  103, 0x0000,    0,    1,   84,    1 },  /* 370: M KICK C */
    {  316,    0,  104, 0x0000,    0,    1,    0,    1 },  /* 371: M KICK C */
    {  317,    0,  105, 0x0000,    0,    1,    0,    1 },  /* 372: M KICK C */
    {  318,    0,  106, 0x0000,    0,    1,    0,    1 },  /* 373: ATTACK 11 SP: 421+K heavy (plain script), ATTACK 12 S: EX 421+KK (plain script), ATTACK 12 M: not started by a command */
    {  319,    0,  107, 0x0000,    0,    1,    0,    1 },  /* 374: ATTACK 12 S: EX 421+KK (plain script) */
    {  320,    0,  108, 0x0000,    0,    1,    0,    1 },  /* 375: ATTACK 12 S: EX 421+KK (plain script) */
    {  321,    0,  109, 0x0000,    0,    1,    0,    1 },  /* 376: ATTACK 12 S: EX 421+KK (plain script) */
    {  322,    0,  110, 0x0000,    0,    1,    0,    1 },  /* 377: ATTACK 12 S: EX 421+KK (plain script) */
    {  323,    0,  111, 0x0000,    0,    1,   85,    1 },  /* 378: ATTACK 12 S: EX 421+KK (plain script) */
    {  323,    0,  112, 0x0000,    0,    1,   86,    1 },  /* 379: ATTACK 12 S: EX 421+KK (plain script) */
    {  324,    0,  113, 0x0000,    0,    1,    0,    1 },  /* 380: ATTACK 12 S: EX 421+KK (plain script) */
    {  324,    0,  114, 0x0000,    0,    1,    0,    1 },  /* 381: ATTACK 12 S: EX 421+KK (plain script) */
    {  324,    0,  115, 0x0000,    0,    1,    0,    1 },  /* 382: ATTACK 12 S: EX 421+KK (plain script) */
    {  324,    0,  116, 0x0000,    0,    1,    0,    1 },  /* 383: ATTACK 12 S: EX 421+KK (plain script) */
    {  325,    0,  117, 0x0000,    0,    1,    0,    1 },  /* 384: ATTACK 12 S: EX 421+KK (plain script) */
    {  326,    0,  118, 0x0000,    0,    1,    0,    1 },  /* 385: ATTACK 12 S: EX 421+KK (plain script) */
    {  327,    0,  119, 0x0000,    0,    1,    0,    1 },  /* 386: ATTACK 12 S: EX 421+KK (plain script) */
    {  328,    0,  120, 0x0000,    0,    1,    0,    1 },  /* 387: ATTACK 12 S: EX 421+KK (plain script) */
    {  329,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 388: ATTACK 12 S: EX 421+KK (plain script) */
    {  295,    0,   85, 0x0000,    0,    1,   87,    1 },  /* 389: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) */
    {  296,    0,  121, 0x0000,    0,    1,    0,    1 },  /* 390: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +1 */
    {  299,    0,   89, 0x0000,    0,    1,   88,    1 },  /* 391: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) */
    {  300,    0,  122, 0x0000,    0,    1,    0,    1 },  /* 392: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +1 */
    {  330,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 393: L KICK C */
    {  331,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 394: L KICK C */
    {  332,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 395: L KICK C */
    {  333,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 396: L KICK C */
    {  334,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 397: L KICK C */
    {  335,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 398: L KICK C */
    {  335,    0,  123, 0x0000,    0,    8,    0,    8 },  /* 399: L KICK C */
    {  335,    0,  124, 0x0000,    0,    8,    0,    8 },  /* 400: L KICK C */
    {  336,    0,  125, 0x0000,    0,    8,   89,    8 },  /* 401: L KICK C */
    {  336,    0,  126, 0x0000,    0,    8,   90,    8 },  /* 402: L KICK C */
    {  336,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 403: L KICK C */
    {  337,    0,    0, 0x0000,    0,    8,    0,    8 },  /* 404: L KICK C */
    {  338,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 405: L KICK C */
    {  339,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 406: L KICK C */
    {  340,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 407: L KICK C */
    {  341,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 408: AIR NORMAL */
    {  342,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 409: AIR NORMAL */
    {  343,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 410: AIR NORMAL */
    {  344,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 411: ASIBARAI SIRI, KUNOJI NOKE, GILL */
    {  345,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 412: ASIBARAI SIRI, TTKI V. AIR, GILL */
    {  346,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 413: ASIBARAI SIRI, TTKI V. AIR, GILL */
    {  347,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 414: ASIBARAI SIRI, TTKI V. AIR, HARAIGOSHI +1 */
    {  348,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 415: ASIB TUNNOMERI, HUMI ASIB */
    {  349,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 416: ASIB TUNNOMERI, HUMI ASIB */
    {  350,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 417: ASIB TUNNOMERI, HUMI ASIB */
    {  351,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 418: ASIB TUNNOMERI, HUMI ASIB */
    {  352,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 419: NOKEZORI, KUNOJI NOKE, TATUMAKIZANKU */
    {  353,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 420: NOKEZORI, KUNOJI NOKE, TATUMAKIZANKU */
    {  354,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 421: NOKEZORI, KUNOJI NOKE, TATAKI AIR +1 */
    {  355,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 422: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  356,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 423: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  357,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 424: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  358,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 425: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  359,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 426: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    {  360,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 427: NOKEZORI, KUNOJI, KIRIMOMI +6 */
    {  361,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 428: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    {  362,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 429: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    {  363,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 430: NOKEZORI, KUNOJI, KIRIMOMI +6 */
    {  364,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 431: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  365,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 432: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  366,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 433: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    {  367,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 434: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    {  368,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 435: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    {  369,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 436: KUNOJI, ALEX B.D, HANEKAERI HARA */
    {  370,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 437: KUNOJI, ALEX B.D, HANEKAERI HARA */
    {  371,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 438: KIRIMOMI */
    {  372,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 439: KIRIMOMI */
    {  373,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 440: KIRIMOMI */
    {  374,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 441: KIRIMOMI */
    {  375,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 442: KIRIMOMI */
    {  376,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 443: KIRIMOMI */
    {  377,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 444: KIRIMOMI */
    {  378,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 445: KIRIMOMI */
    {  379,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 446: KIRIMOMI */
    {  380,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 447: KIRIMOMI */
    {  381,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 448: KIRIMOMI */
    {  382,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 449: KIRIMOMI */
    {  383,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 450: KIRIMOMI */
    {  384,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 451: KIRIMOMI */
    {  385,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 452: TTKI V. AIR, UP P GUARD P M */
    {  386,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 453: DENKI */
    {  387,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 454: KUNOJI NOKE */
    {  388,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 455: TUKAMIKAKARI B */
    {  389,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 456: TUKAMIKAKARI B */
    {  390,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 457: TUKAMIKAKARI B */
    {  391,    0,  127, 0x0000,    0,    1,    0,    1 },  /* 458: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    {  392,    0,  128, 0x0000,    0,    1,    0,    1 },  /* 459: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    {  393,    0,  129, 0x0000,    0,    1,    0,    1 },  /* 460: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    {  394,    0,  130, 0x0000,    0,    1,    0,    1 },  /* 461: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    {  395,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 462: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    {  231,    0,  131, 0x0000,    0,    1,   92,    2 },  /* 463: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  231,    0,  132, 0x0000,    0,    1,   93,    2 },  /* 464: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
};

const BODY_BOX elena_body_box[396] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -30,  22,  72,  18 },  {  -26,  49,  60,  18 },  {  -24,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 1: STAND UP, WALK END, PARING HEAD +73 */
    { { {    0,   0,   0,   0 },  {  -22,  45,  61,  19 },  {  -26,  52,  44,  18 },  {  -23,  46,  25,  19 } } },  /* 2: BODY SLAM, TOMOE RYU, TOMOE ORO +1 */
    { { {  -32,  28,  39,  20 },  {  -19,  41,  36,  18 },  {  -29,  62,  23,  19 },  {  -34,  76,   0,  22 } } },  /* 3: KAGAMU, KAGAMI KAMAE, PARING DOWN +32 */
    { { {  -10,  21, 105,  18 },  {  -21,  40,  88,  18 },  {  -21,  40,  68,  19 },  {  -21,  37,  53,  14 } } },  /* 4: JUMP FRONT, SP JUMP FRONT, GUARD AIR +1 */
    { { {  -33,  21,  96,  18 },  {  -27,  39,  88,  18 },  {  -25,  42,  75,  19 },  {  -44,  58,  54,  27 } } },  /* 5: JUMP FRONT, SP JUMP FRONT, PARING AIR F +18 */
    { { {  -28,  21, 100,  18 },  {  -27,  39,  88,  18 },  {  -29,  40,  75,  18 },  {  -33,  43,  53,  34 } } },  /* 6: JUMP FRONT, SP JUMP FRONT, PARING AIR F +3 */
    { { {  -35,  27,  52,  18 },  {  -20,  45,  41,  23 },  {  -13,  46,  30,  23 },  {  -19,  54,   0,  32 } } },  /* 7: DASH HUMIKOMI */
    { { {  -51,  25,  59,  19 },  {  -32,  41,  52,  24 },  {  -30,  57,  32,  39 },  {  -21,  82,   0,  36 } } },  /* 8: DASH HUMIKOMI */
    { { {  -40,  23,  64,  18 },  {  -30,  39,  51,  24 },  {  -24,  47,  36,  34 },  {  -37,  85,   0,  36 } } },  /* 9: DASH HUMIKOMI, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -36,  23,  69,  18 },  {  -26,  43,  60,  19 },  {  -22,  48,  36,  30 },  {  -31,  69,   0,  36 } } },  /* 10: DASH HUMIKOMI */
    { { {  -57,  22,  61,  18 },  {  -38,  41,  55,  18 },  {  -31,  44,  37,  30 },  {  -38,  68,   0,  36 } } },  /* 11: follow-up of S PUNCH A, S PUNCH C +14, no name, PIYO +1 */
    { { {  -32,  16,  80,  16 },  {  -16,  32,  72,  22 },  {  -28,  50,  46,  26 },  {    0,   0,   0,   0 } } },  /* 12: GUARD AIR */
    { { {    9,  28,  41,  19 },  {  -16,  33,  30,  22 },  {  -22,  48,  14,  27 },  {  -29,  67,   0,  27 } } },  /* 13: KAGAMI TURN */
    { { {  -19,  25,  48,  16 },  {  -27,  46,  36,  18 },  {  -30,  59,  22,  16 },  {  -32,  67,   0,  22 } } },  /* 14: KAGAMI TURN */
    { { {   13,  24,  52,  20 },  {  -10,  33,  48,  18 },  {  -27,  51,  35,  24 },  {  -29,  58,   0,  35 } } },  /* 15: HURIMUKI */
    { { {  -30,  24,  81,  19 },  {  -28,  44,  73,  17 },  {  -25,  53,  43,  31 },  {  -19,  48,   0,  43 } } },  /* 16: HURIMUKI */
    { { {  -42,  23,  47,  20 },  {  -22,  38,  42,  22 },  {  -17,  40,  27,  24 },  {  -29,  54,   0,  40 } } },  /* 17: HURIMUKI */
    { { {  -39,  23,  62,  19 },  {  -24,  38,  54,  23 },  {  -21,  42,  33,  27 },  {  -28,  53,   0,  40 } } },  /* 18: HURIMUKI */
    { { {  -37,  28,  41,  19 },  {  -28,  45,  31,  24 },  {  -20,  44,  18,  27 },  {  -40,  68,   0,  31 } } },  /* 19: KAGAMI P A */
    { { {  -38,  16,  40,  16 },  {  -28,  44,  28,  32 },  {  -68,  48,   0,  34 },  {  -20,  40,   0,  28 } } },  /* 20: not used by a script */
    { { {  -43,  24,  42,  17 },  {  -19,  31,  40,  17 },  {  -44,  58,  18,  24 },  {  -48,  67,   0,  24 } } },  /* 21: KAGAMI P A */
    { { {  -45,  28,  41,  19 },  {  -17,  36,  41,  15 },  {  -44,  66,  22,  19 },  {  -42,  67,   0,  24 } } },  /* 22: KAGAMI P A */
    { { {   30,  16,  44,  16 },  {    4,  48,  24,  32 },  {  -28,  32,  24,  26 },  {  -36,  88,   0,  24 } } },  /* 23: KAGAMI K A */
    { { {   44,  17,  32,  20 },  {  -16,  60,  24,  29 },  {  -47,  31,  25,  14 },  {  -36,  91,   0,  24 } } },  /* 24: KAGAMI K A */
    { { {   44,  17,  32,  20 },  {    4,  44,  24,  32 },  {  -28,  32,  24,  26 },  {  -40,  92,   0,  24 } } },  /* 25: KAGAMI K A */
    { { {   -6,  41,  42,  18 },  {    4,  44,  24,  28 },  {  -28,  32,  24,  26 },  {  -36,  88,   0,  24 } } },  /* 26: KAGAMI K A */
    { { {  -43,  20,  40,  18 },  {  -22,  37,  25,  36 },  {  -64,  44,   0,  32 },  {  -20,  40,   0,  24 } } },  /* 27: KAGAMI P A */
    { { {   -4,  16,  44,  16 },  {  -24,  48,  36,  20 },  {  -32,  66,  24,  12 },  {  -36,  80,   0,  24 } } },  /* 28: KAGAMI P A, KAGAMI K A, follow-up of M KICK A +2 */
    { { {    0,   0,   0,   0 },  {  -20,  48,  38,  20 },  {  -32,  72,  24,  16 },  {  -36,  88,   0,  24 } } },  /* 29: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    0,   0,   0,   0 },  {  -24,  60,  44,  20 },  {  -32,  72,  24,  20 },  {  -36,  88,   0,  24 } } },  /* 30: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    0,   0,   0,   0 },  {  -48,  83,  44,  24 },  {  -44,  90,  24,  20 },  {  -45,  97,   0,  24 } } },  /* 31: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    0,   0,   0,   0 },  {  -34,  71,  28,  34 },  {  -51,  57,  52,  39 },  {  -50,  99,   0,  33 } } },  /* 32: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -36,  64,  44,  26 },  {  -24,  68,  24,  20 },  {  -36,  88,   0,  24 } } },  /* 33: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    8,  16,  40,  16 },  {   -2,  44,  24,  26 },  {  -30,  32,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 34: KAGAMI K A */
    { { {   22,  16,  38,  16 },  {   -2,  40,  24,  28 },  {  -30,  32,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 35: KAGAMI K A */
    { { {   40,  16,  32,  16 },  {    8,  36,  24,  30 },  {  -32,  40,  24,  24 },  {  -40,  88,   0,  24 } } },  /* 36: KAGAMI K A */
    { { {   44,  16,  32,  16 },  {    8,  40,  24,  34 },  {  -40,  48,  24,  28 },  {  -40,  88,   0,  24 } } },  /* 37: KAGAMI K A */
    { { {  -30,  23,  87,  18 },  {  -24,  48,  72,  27 },  {  -36,  64,  50,  27 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {   -6,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -49,  82,  43,  29 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP P S A, F JUMP P S A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -7,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -49,  82,  43,  29 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP P S A, F JUMP P S A, ATTACK 7 L: not started by a command */
    { { {   -2,  16,  79,  15 },  {    0,  32,  64,  17 },  {   -6,  36,  42,  22 },  {  -28,  54,   0,  42 } } },  /* 41: not used by a script */
    { { {  -11,  16,  79,  15 },  {  -14,  34,  66,  18 },  {   -6,  34,  38,  28 },  {  -12,  40,   0,  38 } } },  /* 42: not used by a script */
    { { {  -28,  16, 100,  16 },  {  -16,  28,  76,  32 },  {  -36,  44,  58,  26 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {  -30,  16, 100,  16 },  {  -26,  40,  84,  22 },  {  -26,  36,  44,  40 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -28,  16,  98,  16 },  {  -36,  48,  76,  24 },  {  -36,  44,  36,  40 },  {  -36,  54,   0,  36 } } },  /* 45: not used by a script */
    { { {  -28,  16,  80,  16 },  {  -18,  32,  68,  18 },  {  -16,  34,  36,  32 },  {  -30,  54,   0,  36 } } },  /* 46: not used by a script */
    { { {  -38,  16,  64,  16 },  {  -20,  32,  62,  18 },  {  -20,  32,  36,  26 },  {  -32,  54,   0,  36 } } },  /* 47: not used by a script */
    { { {  -38,  16,  46,  16 },  {  -22,  40,  46,  18 },  {  -24,  52,  24,  22 },  {  -36,  68,   0,  24 } } },  /* 48: follow-up of SP WIN 2 */
    { { {  -34,  16,  66,  16 },  {  -26,  40,  62,  18 },  {  -22,  44,  36,  24 },  {  -28,  52,   0,  36 } } },  /* 49: HUSHIN HEAD, HUSHIN DOWN, follow-up of SP WIN 2 */
    { { {  -38,  16,  64,  16 },  {  -22,  36,  64,  18 },  {  -24,  40,  32,  32 },  {    0,   0,   0,   0 } } },  /* 50: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI */
    { { {  -30,  16,  72,  16 },  {  -18,  36,  66,  18 },  {  -28,  50,  29,  36 },  {    0,   0,   0,   0 } } },  /* 51: not used by a script */
    { { {    0,   0,   0,   0 },  {  -44,  72,  24,  22 },  {  -16,  66,  46,  24 },  {  -48,  80,   0,  24 } } },  /* 52: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -32,  54,  24,  22 },  {  -16,  48,  46,  43 },  {  -36,  72,   0,  24 } } },  /* 53: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -12,  52,  24,  22 },  {  -24,  64,  46,  43 },  {  -18,  72,   0,  24 } } },  /* 54: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -46,  16,  60,  16 },  {  -36,  56,  50,  22 },  {  -32,  60,  30,  24 },  {  -32,  68,   0,  30 } } },  /* 55: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -16,  16,  56,  16 },  {  -30,  52,  44,  18 },  {  -30,  52,  28,  16 },  {  -36,  64,   0,  28 } } },  /* 56: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   24,  16,  52,  16 },  {  -20,  44,  52,  18 },  {  -28,  60,  32,  20 },  {  -28,  74,   0,  32 } } },  /* 57: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   32,  23,  36,  18 },  {    8,  28,  32,  32 },  {  -29,  50,  32,  40 },  {  -31,  75,   0,  36 } } },  /* 58: M PUNCH A */
    { { {   32,  21,  36,  17 },  {  -39,  71,  32,  31 },  {  -51,  41,  52,  37 },  {  -41,  83,   0,  32 } } },  /* 59: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   23,  16,  37,  23 },  {  -28,  52,  42,  22 },  {  -30,  60,  24,  18 },  {  -40,  80,   0,  24 } } },  /* 60: M PUNCH A */
    { { {  -17,  25,  60,  15 },  {  -28,  52,  42,  22 },  {  -30,  56,  24,  18 },  {  -40,  80,   0,  24 } } },  /* 61: M PUNCH A */
    { { {   -4,  25,  88,  16 },  {  -18,  48,  66,  22 },  {  -18,  50,  40,  26 },  {  -20,  52,   0,  40 } } },  /* 62: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -2,  27,  94,  14 },  {  -20,  52,  74,  20 },  {  -24,  48,  40,  34 },  {  -28,  52,   0,  40 } } },  /* 63: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {   -2,  24,  96,  16 },  {  -16,  44,  76,  20 },  {  -34,  54,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 64: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -5,  26,  96,  16 },  {  -63,  94,  70,  28 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 65: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {    6,  24,  84,  18 },  {  -16,  48,  68,  22 },  {  -20,  48,  40,  28 },  {  -26,  64,   0,  40 } } },  /* 66: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {  -24,  24,  80,  16 },  {  -28,  55,  60,  20 },  {  -14,  50,  36,  26 },  {   -8,  48,   0,  36 } } },  /* 67: L KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -14,  24,  94,  16 },  {  -20,  48,  80,  20 },  {  -14,  46,  44,  36 },  {   -8,  48,   0,  44 } } },  /* 68: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -11,  24,  94,  16 },  {  -21,  49,  84,  18 },  {  -21,  43,  51,  34 },  {   -5,  28,   3,  48 } } },  /* 69: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -13,  25,  85,  16 },  {  -22,  51,  76,  20 },  {  -16,  40,  38,  38 },  {    0,   0,   0,   0 } } },  /* 70: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -13,  25,  85,  16 },  {  -22,  51,  76,  20 },  {  -16,  40,  38,  38 },  {    0,   0,   0,   0 } } },  /* 71: L KICK A, follow-up of L PUNCH A */
    { { {  -31,  24,  84,  17 },  {  -26,  50,  70,  26 },  {  -28,  53,  34,  36 },  {    0,   0,   0,   0 } } },  /* 72: L KICK A, follow-up of L PUNCH A */
    { { {  -44,  24,  80,  16 },  {  -34,  48,  70,  18 },  {  -36,  60,  40,  30 },  {  -36,  80,   0,  40 } } },  /* 73: L KICK A, follow-up of L PUNCH A */
    { { {    4,  23,  82,  16 },  {  -12,  47,  60,  22 },  {  -14,  48,  36,  24 },  {  -22,  68,   0,  36 } } },  /* 74: S PUNCH A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -5,  26,  86,  15 },  {  -49,  82,  61,  29 },  {  -23,  57,  36,  40 },  {  -21,  56,   0,  36 } } },  /* 75: S PUNCH A */
    { { {   -3,  25,  83,  16 },  {  -14,  50,  64,  18 },  {  -14,  48,  36,  28 },  {  -22,  60,   0,  36 } } },  /* 76: S PUNCH A */
    { { {   -9,  26,  80,  16 },  {  -14,  48,  60,  22 },  {  -14,  48,  32,  28 },  {  -22,  60,   0,  32 } } },  /* 77: S PUNCH A */
    { { {  -24,  22,  90,  16 },  {  -20,  40,  72,  22 },  {  -16,  40,  44,  32 },  {  -32,  64,   0,  44 } } },  /* 78: S KICK A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -28,  24,  86,  16 },  {  -22,  42,  68,  24 },  {  -28,  56,  40,  32 },  {  -32,  60,   0,  40 } } },  /* 79: S KICK A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -28,  16,  88,  16 },  {  -22,  44,  70,  22 },  {  -24,  52,  40,  32 },  {  -36,  64,   0,  40 } } },  /* 80: not used by a script */
    { { {  -38,  24,  80,  16 },  {  -22,  40,  64,  24 },  {  -26,  52,  40,  28 },  {  -30,  60,   0,  40 } } },  /* 81: S KICK A */
    { { {   -8,  22,  57,  16 },  {  -18,  48,  46,  14 },  {  -26,  68,  30,  16 },  {  -44,  88,   0,  30 } } },  /* 82: KAGAMI K C */
    { { {    4,  16,  50,  16 },  {  -18,  52,  38,  18 },  {  -28,  72,  26,  12 },  {  -44,  96,   0,  26 } } },  /* 83: KAGAMI K C */
    { { {    8,  16,  42,  16 },  {   -2,  40,  24,  28 },  {  -28,  26,  24,  24 },  {  -50,  21,  25,  13 } } },  /* 84: KAGAMI K C */
    { { {   32,  16,  30,  16 },  {    6,  26,  28,  34 },  {  -32,  38,  28,  26 },  {  -24,  72,   0,  28 } } },  /* 85: not used by a script */
    { { {   36,  16,  28,  16 },  {   12,  24,  28,  32 },  {  -20,  32,  28,  30 },  {  -40,  88,   0,  28 } } },  /* 86: KAGAMI K C */
    { { {    0,   0,   0,   0 },  {   12,  40,  28,  26 },  {  -24,  36,  28,  32 },  {  -36,  88,   0,  28 } } },  /* 87: KAGAMI K C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  64,  32,  28 },  {  -40,  88,   0,  32 } } },  /* 88: KAGAMI K C */
    { { {  -50,  23,  56,  18 },  {  -34,  47,  50,  18 },  {  -32,  53,  28,  22 },  {  -36,  71,   0,  28 } } },  /* 89: KAGAMI K C */
    { { {  -58,  16,  46,  16 },  {  -42,  30,  40,  36 },  {  -12,  30,  40,  32 },  {  -38,  84,   0,  40 } } },  /* 90: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {  -54,  32,  42,  40 },  {  -22,  40,  42,  46 },  {  -26,  40,   0,  42 } } },  /* 91: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -40,  56,  56,  14 },  {  -32,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -30,  46,  58,  14 },  {  -36,  56,  70,  24 },  {    0,   0,   0,   0 } } },  /* 93: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -16,  40,  58,  24 },  {  -36,  20,  58,  24 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    0,   0,   0,   0 },  {  -32,  40,  50,  32 },  {   -8,  24,  50,  32 },  {    0,   0,   0,   0 } } },  /* 95: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +5 */
    { { {  -39,  19,  49,  25 },  {  -20,  28,  42,  40 },  {    8,  32,  42,  44 },  {   -8,  40,   0,  42 } } },  /* 96: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -39,  18,  48,  22 },  {  -20,  28,  42,  40 },  {    8,  32,  42,  44 },  {   -8,  40,   0,  42 } } },  /* 97: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -38,  16,  54,  22 },  {  -20,  52,  60,  18 },  {  -18,  56,  36,  24 },  {  -16,  60,   0,  36 } } },  /* 98: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -26,  30,  71,  16 },  {  -20,  55,  60,  18 },  {  -18,  60,  36,  24 },  {  -16,  80,   0,  36 } } },  /* 99: not used by a script */
    { { {  -36,  16,  52,  16 },  {  -20,  40,  46,  18 },  {  -24,  52,  28,  18 },  {  -28,  68,   0,  28 } } },  /* 100: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  56,  32,  28 },  {  -40,  80,   0,  32 } } },  /* 101: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    2,  34,  28,  30 },  {  -34,  36,  28,  32 },  {  -66, 110,   0,  28 } } },  /* 102: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   20,  16,  28,  16 },  {   -8,  28,  28,  36 },  {  -54,  45,  28,  38 },  {  -66, 110,   0,  28 } } },  /* 103: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), follow-up of M KICK A */
    { { {    4,  21,  40,  16 },  {  -14,  39,  28,  24 },  {  -58,  43,  28,  31 },  {  -66, 110,   0,  28 } } },  /* 104: M KICK A */
    { { {  -11,  27,  54,  17 },  {  -24,  50,  38,  22 },  {  -50,  78,  26,  18 },  {  -66, 110,   0,  26 } } },  /* 105: M KICK A */
    { { {  -14,  23,  70,  16 },  {  -24,  56,  50,  21 },  {  -33,  73,  26,  24 },  {  -53,  97,   0,  26 } } },  /* 106: M KICK A */
    { { {  -26,  25,  97,  16 },  {  -33,  53,  80,  22 },  {  -44,  63,  48,  31 },  {    0,   0,   0,   0 } } },  /* 107: V JUMP P S A, V JUMP P M A, V JUMP P L A +10 */
    { { {  -15,  26,  94,  16 },  {  -40,  70,  76,  22 },  {  -47,  70,  48,  29 },  {    0,   0,   0,   0 } } },  /* 108: V JUMP P M A, V JUMP P L A, V JUMP K S A +7 */
    { { {    2,  26,  94,  16 },  {  -24,  63,  78,  21 },  {  -40,  76,  46,  32 },  {    0,   0,   0,   0 } } },  /* 109: V JUMP P M A, F JUMP P M A */
    { { {  -14,  24,  96,  16 },  {  -28,  57,  76,  24 },  {  -40,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 110: V JUMP P L A, F JUMP P L A */
    { { {   -8,  25,  94,  16 },  {  -20,  60,  76,  22 },  {  -24,  72,  46,  30 },  {    0,   0,   0,   0 } } },  /* 111: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { {  -11,  25,  96,  16 },  {  -28,  56,  76,  24 },  {  -28,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 112: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { {   -4,  16,  94,  16 },  {  -28,  64,  76,  22 },  {  -40,  72,  48,  28 },  {    0,   0,   0,   0 } } },  /* 113: not used by a script */
    { { {   -6,  25,  94,  16 },  {  -28,  64,  76,  22 },  {  -75, 111,  45,  32 },  {    0,   0,   0,   0 } } },  /* 114: V JUMP K S A, F JUMP K S A */
    { { {    8,  24,  94,  16 },  {  -34,  77,  76,  22 },  {  -61,  92,  49,  32 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    { { {  -54,  16,  64,  16 },  {  -38,  32,  50,  44 },  {   -8,  56,  46,  40 },  {    0,   0,   0,   0 } } },  /* 116: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -34,  32,  34,  56 },  {   -2,  56,  52,  44 },  {    0,   0,   0,   0 } } },  /* 117: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -24,  56,  34,  32 },  {  -37,  72,  66,  39 },  {    0,   0,   0,   0 } } },  /* 118: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -27,  65,  34,  40 },  {  -33,  47,  69,  52 },  {    0,   0,   0,   0 } } },  /* 119: V JUMP K L A, F JUMP K L A */
    { { {    0,   0,   0,   0 },  {  -51,  85,  34,  40 },  {  -22,  48,  72,  33 },  {    0,   0,   0,   0 } } },  /* 120: V JUMP K L A, F JUMP K L A */
    { { {   32,  16,  52,  16 },  {    8,  24,  44,  42 },  {  -45,  52,  30,  56 },  {    0,   0,   0,   0 } } },  /* 121: V JUMP K L A, F JUMP K L A */
    { { {   -8,  25,  74,  16 },  {  -28,  60,  62,  21 },  {  -32,  72,  38,  24 },  {    0,   0,   0,   0 } } },  /* 122: V JUMP K L A, F JUMP K L A */
    { { {   14,  16,  40,  16 },  {  -24,  48,  38,  14 },  {  -32,  72,  24,  14 },  {  -40,  88,   0,  24 } } },  /* 123: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   40,  16,  30,  16 },  {    8,  32,  28,  28 },  {  -28,  36,  28,  28 },  {  -40,  88,   0,  28 } } },  /* 124: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   44,  16,  18,  16 },  {   12,  32,   0,  36 },  {   -8,  20,   0,  40 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   44,  16,  10,  16 },  {   12,  32,   0,  32 },  {   -8,  20,   0,  36 },  {  -92,  83,   0,  33 } } },  /* 126: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    4,  32,  24,  26 },  {  -36,  38,  24,  30 },  {  -85, 138,   0,  24 } } },  /* 127: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    8,  36,  24,  28 },  {  -32,  40,  24,  32 },  {  -69, 123,   0,  29 } } },  /* 128: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    8,  36,  24,  24 },  {  -32,  40,  24,  28 },  {  -36,  88,   0,  24 } } },  /* 129: KAGAMI K A */
    { { {   26,  16,  40,  16 },  {    8,  36,  24,  24 },  {  -24,  32,  24,  28 },  {  -32,  84,   0,  24 } } },  /* 130: KAGAMI K A */
    { { {   52,  16,   0,  16 },  {   24,  28,   0,  30 },  {  -24,  48,   0,  36 },  {    0,   0,   0,   0 } } },  /* 131: not used by a script */
    { { {   52,  16,   0,  16 },  {   24,  28,   0,  30 },  {  -24,  48,   0,  36 },  {    0,   0,   0,   0 } } },  /* 132: not used by a script */
    { { {   48,  16,   8,  16 },  {   24,  24,   0,  36 },  {  -24,  48,  24,  32 },  {  -24,  48,   0,  24 } } },  /* 133: not used by a script */
    { { {   36,  16,  16,  16 },  {    8,  28,  28,  22 },  {  -24,  32,  28,  22 },  {  -32,  56,   0,  24 } } },  /* 134: not used by a script */
    { { {   44,  16,  34,  16 },  {   16,  28,  28,  32 },  {  -16,  32,  28,  32 },  {  -32,  56,   0,  28 } } },  /* 135: not used by a script */
    { { {   30,  16,  40,  16 },  {   -2,  32,  28,  36 },  {  -30,  28,  28,  32 },  {  -32,  56,   0,  28 } } },  /* 136: not used by a script */
    { { {  -12,  16, 104,  16 },  {  -26,  40,  92,  18 },  {  -20,  34,  54,  38 },  {    0,   0,   0,   0 } } },  /* 137: not used by a script */
    { { {  -12,  16, 104,  16 },  {  -22,  40,  92,  18 },  {  -16,  34,  54,  38 },  {    0,   0,   0,   0 } } },  /* 138: not used by a script */
    { { {  -22,  16,  42,  16 },  {  -16,  40,  34,  20 },  {   -8,  40,  12,  24 },  {  -30,  56,   0,  22 } } },  /* 139: not used by a script */
    { { {  -22,  25,  86,  16 },  {  -24,  42,  66,  24 },  {  -26,  48,  40,  26 },  {  -30,  64,   0,  40 } } },  /* 140: L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 SP: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -26,  16,  80,  16 },  {  -22,  40,  62,  18 },  {  -18,  44,  36,  26 },  {  -18,  52,   0,  36 } } },  /* 141: not used by a script */
    { { {  -12,  16,  94,  16 },  {  -18,  40,  80,  16 },  {  -14,  44,  44,  36 },  {   -8,  52,   0,  44 } } },  /* 142: not used by a script */
    { { {  -27,  20,  50,  17 },  {  -24,  32,  40,  18 },  {  -24,  44,  24,  16 },  {  -32,  56,   0,  24 } } },  /* 143: DASH TOBINOKI */
    { { {   12,  22,  41,  17 },  {  -14,  32,  36,  18 },  {  -20,  44,  24,  16 },  {  -40,  56,   0,  24 } } },  /* 144: DASH TOBINOKI */
    { { {   27,  20,  21,  17 },  {    4,  24,  24,  24 },  {  -40,  44,  24,  20 },  {  -44,  64,   0,  24 } } },  /* 145: DASH TOBINOKI */
    { { {    4,  24,   8,  17 },  {  -13,  51,  24,  20 },  {  -33,  52,  44,  30 },  {  -22,  56,   0,  24 } } },  /* 146: DASH TOBINOKI */
    { { {  -16,  24,   7,  18 },  {  -26,  52,  24,  20 },  {  -16,  47,  44,  33 },  {  -30,  60,   0,  24 } } },  /* 147: DASH TOBINOKI */
    { { {  -42,  20,  16,  18 },  {  -45,  36,  24,  24 },  {  -13,  36,  24,  36 },  {  -36,  66,   0,  24 } } },  /* 148: DASH TOBINOKI */
    { { {  -52,  20,  37,  18 },  {  -34,  41,  41,  21 },  {  -22,  43,  28,  27 },  {  -26,  58,   0,  28 } } },  /* 149: DASH TOBINOKI */
    { { {  -48,  20,  57,  18 },  {  -33,  39,  48,  21 },  {  -22,  42,  28,  28 },  {  -26,  58,   0,  28 } } },  /* 150: DASH TOBINOKI */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 151: no name */
    { { {   20,  16,  68,  16 },  {  -12,  40,  60,  18 },  {  -20,  44,  36,  24 },  {  -24,  52,   0,  36 } } },  /* 152: not used by a script */
    { { {   28,  16,  54,  16 },  {  -12,  40,  60,  18 },  {  -20,  44,  36,  24 },  {  -28,  56,   0,  36 } } },  /* 153: not used by a script */
    { { {   28,  16,  54,  16 },  {    2,  26,  36,  36 },  {  -24,  26,  36,  36 },  {  -36,  56,   0,  36 } } },  /* 154: not used by a script */
    { { {   28,  16,  54,  16 },  {    2,  26,  36,  36 },  {  -36,  38,  36,  36 },  {  -36,  56,   0,  36 } } },  /* 155: not used by a script */
    { { {    2,  16,  72,  16 },  {   -8,  36,  56,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  25 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 157: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    0,  30,  86,  16 },  {  -66,  95,  41,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 158: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {   28,  16,  82,  16 },  {  -14,  48,  68,  22 },  {  -28,  54,  32,  36 },  {    0,   0,   0,   0 } } },  /* 159: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {   36,  16,  50,  16 },  {    8,  31,  52,  36 },  {  -22,  30,  42,  44 },  {    0,   0,   0,   0 } } },  /* 160: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {    0,   0,   0,   0 },  {  -26,  50,  40,  24 },  {  -26,  50,  64,  24 },  {    0,   0,   0,   0 } } },  /* 161: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -48,  23,  46,  16 },  {  -40,  30,  52,  29 },  {  -13,  35,  38,  47 },  {    0,   0,   0,   0 } } },  /* 162: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -64,  16,  50,  16 },  {  -48,  32,  40,  40 },  {  -16,  32,  40,  48 },  {  -28,  40,   0,  40 } } },  /* 163: follow-up of APPEAR JUNBI 7, follow-up of SP WIN 6, follow-up of SP WIN 7 */
    { { {    4,  16,  82,  16 },  {  -12,  40,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 164: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {    6,  16,  82,  16 },  {   -4,  36,  66,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 165: S PUNCH C, ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {   12,  16,  78,  16 },  {    2,  32,  64,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 166: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   16,  16,  74,  16 },  {    2,  32,  60,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 167: S PUNCH C, ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -10,  16,  82,  16 },  {  -18,  40,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 168: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -20,  16,  84,  16 },  {  -22,  36,  68,  18 },  {  -16,  38,  36,  32 },  {  -24,  52,   0,  36 } } },  /* 169: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -16,  16,  88,  16 },  {  -22,  36,  72,  18 },  {  -18,  38,  36,  36 },  {  -24,  52,   0,  36 } } },  /* 170: S PUNCH C, ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU) +2 */
    { { {   -8,  16,  86,  16 },  {  -18,  34,  72,  18 },  {  -18,  38,  36,  36 },  {  -24,  52,   0,  36 } } },  /* 171: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -14,  40,  80,  18 },  {  -14,  36,  52,  28 },  {    0,   0,   0,   0 } } },  /* 172: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -14,  40,  80,  18 },  {  -14,  36,  52,  28 },  {    0,   0,   0,   0 } } },  /* 173: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -2,  16,  92,  16 },  {  -18,  40,  84,  18 },  {  -48,  64,  68,  16 },  {    0,   0,   0,   0 } } },  /* 174: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU), ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) +1 */
    { { {   10,  16,  88,  16 },  {  -18,  40,  84,  18 },  {  -83, 103,  70,  21 },  {    0,   0,   0,   0 } } },  /* 175: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   18,  16,  84,  16 },  {   -2,  24,  66,  28 },  {  -85, 106,  62,  20 },  {    0,   0,   0,   0 } } },  /* 176: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   28,  16,  70,  16 },  {    2,  26,  64,  28 },  {  -51,  50,  50,  53 },  {    0,   0,   0,   0 } } },  /* 177: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   32,  16,  56,  16 },  {    4,  28,  40,  40 },  {  -35,  38,  41,  47 },  {    0,   0,   0,   0 } } },  /* 178: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   32,  16,  56,  16 },  {  -34,  67,  25,  58 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 179: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   24,  23,  46,  22 },  {  -10,  34,  18,  50 },  {  -71,  60,  31,  37 },  {    0,   0,   0,   0 } } },  /* 180: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -11,  36,  72,  16 },  {  -23,  47,  56,  18 },  {  -34,  59,  11,  44 },  {    0,   0,   0,   0 } } },  /* 181: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 182: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   14,  16,  86,  16 },  {  -22,  50,  68,  22 },  {  -18,  40,  32,  36 },  {    0,   0,   0,   0 } } },  /* 183: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   28,  16,  82,  16 },  {  -14,  48,  68,  22 },  {  -28,  54,  32,  36 },  {    0,   0,   0,   0 } } },  /* 184: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  50,   0,  28 },  {    0,   0,   0,   0 } } },  /* 185: ATTACK 7 M: not started by a command, SP APPEAR 1 */
    { { {   38,  16,  46,  16 },  {    8,  30,  40,  36 },  {  -22,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 186: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {    8,  30,  40,  36 },  {  -22,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 187: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {   24,  30,  40,  36 },  {  -14,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 188: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   38,  16,  46,  16 },  {   24,  30,  40,  36 },  {  -14,  30,  40,  32 },  {   -8,  48,   0,  40 } } },  /* 189: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   20,  32,  40,  40 },  {  -12,  32,  40,  46 },  {    0,   0,   0,   0 } } },  /* 190: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 191: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 192: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 193: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 194: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {   -8,  56,  56,  14 },  {   -6,  50,  70,  24 },  {    0,   0,   0,   0 } } },  /* 195: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -28,  40,  48,  35 },  {   12,  20,  44,  35 },  {    0,   0,   0,   0 } } },  /* 196: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -28,  40,  48,  35 },  {   12,  20,  44,  35 },  {    0,   0,   0,   0 } } },  /* 197: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 198: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 199: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 200: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -40,  16,  50,  16 },  {  -26,  28,  42,  36 },  {    2,  28,  42,  40 },  {  -10,  40,   0,  42 } } },  /* 201: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -30,  16,  66,  16 },  {  -20,  40,  54,  18 },  {  -16,  48,  36,  24 },  {  -16,  56,   0,  36 } } },  /* 202: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -30,  16,  66,  16 },  {  -20,  40,  54,  18 },  {  -16,  48,  36,  24 },  {  -16,  56,   0,  36 } } },  /* 203: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    6,  16,  80,  16 },  {  -14,  40,  62,  18 },  {  -18,  48,  36,  26 },  {  -28,  56,   0,  36 } } },  /* 204: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   32,  21,  36,  17 },  {   -8,  40,  32,  31 },  {  -39,  31,  32,  57 },  {  -41,  83,   0,  32 } } },  /* 205: not used by a script */
    { { {   44,  16,  18,  16 },  {   12,  32,   0,  36 },  {   -8,  20,   0,  40 },  {  -32,  24,   0,  24 } } },  /* 206: not used by a script */
    { { {   -7,  25,  96,  16 },  {  -16,  45,  76,  22 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 207: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {   -6,  26,  94,  16 },  {  -25,  56,  76,  21 },  {  -24,  44,  44,  32 },  {  -32,  44,   0,  44 } } },  /* 208: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {  -43,  20,  42,  16 },  {  -22,  34,  40,  20 },  {  -45,  59,  21,  19 },  {  -48,  64,   0,  26 } } },  /* 209: KAGAMI P A */
    { { {  -43,  20,  39,  17 },  {  -22,  34,  35,  23 },  {  -79,  56,   0,  39 },  {  -23,  41,   0,  35 } } },  /* 210: KAGAMI P A */
    { { {   44,  16,  32,  16 },  {    8,  40,  24,  36 },  {  -40,  48,  24,  28 },  {  -40,  88,   0,  24 } } },  /* 211: KAGAMI K A */
    { { {   32,  21,  36,  17 },  {  -39,  71,  32,  31 },  {  -51,  42,  52,  26 },  {  -41,  83,   0,  32 } } },  /* 212: M PUNCH A */
    { { {  -22,  24,  84,  16 },  {  -28,  54,  72,  24 },  {  -57,  83,  50,  24 },  {    0,   0,   0,   0 } } },  /* 213: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -28,  24,  84,  16 },  {  -33,  58,  78,  20 },  {  -41,  65,  50,  28 },  {    0,   0,   0,   0 } } },  /* 214: L KICK A, follow-up of L PUNCH A */
    { { {   -5,  22,  41,  16 },  {  -14,  36,  28,  24 },  {  -56,  42,  28,  26 },  {  -66, 110,   0,  28 } } },  /* 215: M KICK A, follow-up of M KICK A */
    { { {   -2,  16,  72,  16 },  {   -8,  36,  56,  18 },  {  -44,  68,  14,  41 },  {    0,   0,   0,   0 } } },  /* 216: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -36,  49,   0,  56 },  {    0,   0,   0,   0 } } },  /* 217: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {   13,  16,  85,  11 },  {  -34,  63,  68,  17 },  {  -34,  58,  32,  36 },  {    0,   0,   0,   0 } } },  /* 218: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {  -11,  36,  72,  16 },  {  -23,  47,  56,  18 },  {  -36,  61,  11,  50 },  {    0,   0,   0,   0 } } },  /* 219: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {    6,  16,  72,  16 },  {  -22,  50,  56,  18 },  {  -22,  40,  30,  26 },  {    0,   0,   0,   0 } } },  /* 220: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {   14,  16,  86,  16 },  {  -22,  50,  68,  22 },  {  -18,  40,  32,  36 },  {    0,   0,   0,   0 } } },  /* 221: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -27,  65,  34,  40 },  {  -32,  44,  68,  56 },  {    0,   0,   0,   0 } } },  /* 222: not used by a script */
    { { {   -2,  16,  88,  16 },  {  -25,  58,  72,  21 },  {  -43,  74,  53,  26 },  {  -21,  49,   0,  54 } } },  /* 223: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  84,   0,  59 },  {    0,   0,   0,   0 } } },  /* 224: ATTACK 7 S: SA III 23623+P (routine Att_PL08_HEALING) */
    { { {  -26,  29,  67,  17 },  {  -41,  58,  64,  12 },  {  -46,  72,  38,  26 },  {  -53, 106,   0,  38 } } },  /* 225: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -38,  26,  43,  20 },  {  -44,  61,  41,  19 },  {  -44,  77,  35,  17 },  {  -50, 100,   0,  35 } } },  /* 226: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -20,  22,  31,  19 },  {  -24,  57,  39,  10 },  {  -34,  72,  31,  26 },  {  -47,  97,   0,  31 } } },  /* 227: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {    3,  22,  27,  19 },  {  -12,  57,  37,  10 },  {  -22,  64,  37,  23 },  {  -47,  97,   0,  37 } } },  /* 228: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   16,  22,  32,  19 },  {   -9,  55,  44,  15 },  {  -25,  64,  44,  25 },  {  -47,  95,   0,  44 } } },  /* 229: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   10,  22,  34,  19 },  {  -10,  44,  42,  17 },  {  -43,  74,  43,  31 },  {  -50,  90,   0,  43 } } },  /* 230: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   -5,  23,  43,  21 },  {  -15,  26,  40,  32 },  {  -50,  35,  43,  37 },  {  -50,  76,   0,  43 } } },  /* 231: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -11,  22,  42,  29 },  {  -27,  27,  42,  35 },  {  -65,  38,  41,  42 },  {  -50,  76,   0,  41 } } },  /* 232: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -34,  27,  62,  19 },  {  -34,  36,  46,  29 },  {  -54,  20,  46,  32 },  {  -53,  79,   0,  46 } } },  /* 233: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -50,  36,  64,  17 },  {  -53,  55,  57,  18 },  {  -54,  74,  44,  19 },  {  -55,  90,   0,  44 } } },  /* 234: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -56,  34,  62,  15 },  {  -53,  50,  56,  16 },  {  -55,  77,  42,  20 },  {  -55,  99,   0,  42 } } },  /* 235: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    { { {  -48,  20,  45,  20 },  {  -28,  47,  45,  17 },  {  -49,  81,  32,  13 },  {  -50,  93,   0,  33 } } },  /* 236: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -54,  22,  42,  19 },  {  -41,  38,  40,  22 },  {  -21,  36,  37,  19 },  {  -55, 109,   0,  42 } } },  /* 237: not used by a script */
    { { {  -23,  22,  33,  19 },  {  -24,  38,  37,  22 },  {   -3,  27,  40,  19 },  {  -45,  93,   0,  38 } } },  /* 238: not used by a script */
    { { {  -52,  22,  53,  20 },  {  -33,  42,  41,  31 },  {   -3,  34,  41,  25 },  {  -49, 107,   0,  41 } } },  /* 239: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -32,  66,  39,  28 },  {    0,   0,   0,   0 },  {  -48, 104,   0,  39 } } },  /* 240: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -49,  74,  37,  24 },  {  -47,  93,   0,  37 } } },  /* 241: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -59,  45,  60,  19 },  {  -57,  67,  37,  23 },  {  -49,  74,   0,  37 } } },  /* 242: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -86,  58,  46,  35 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 243: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 244: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  26,  33 },  {  -52,  77,   0,  37 } } },  /* 245: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -67,  74,  29,  37 },  {  -52,  77,   0,  37 } } },  /* 246: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -65,  73,  32,  35 },  {  -50,  75,   0,  37 } } },  /* 247: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -61,  76,  37,  36 },  {  -42,  75,   0,  37 } } },  /* 248: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -50,  58,  51,  31 },  {  -40,  64,  37,  25 },  {  -34,  74,   0,  37 } } },  /* 249: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -41,  66,  59,  24 },  {  -32,  68,  37,  25 },  {  -25,  72,   0,  37 } } },  /* 250: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -17,  30,  68,  21 },  {  -14,  51,  60,  24 },  {   -8,  57,  37,  31 },  {   -5,  67,   0,  37 } } },  /* 251: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -24,  25,  57,  23 },  {    1,  32,  52,  23 },  {  -10,  53,  37,  20 },  {  -11,  63,   0,  37 } } },  /* 252: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -29,  24,  54,  24 },  {   -5,  39,  47,  27 },  {  -23,  67,  38,  17 },  {  -28,  80,   0,  38 } } },  /* 253: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -37,  19,  59,  23 },  {  -19,  47,  51,  26 },  {  -31,  65,  38,  21 },  {  -33,  78,   0,  38 } } },  /* 254: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    2,  18,  70,  16 },  {  -12,  50,  58,  18 },  {  -36,  48,  32,  28 },  {    0,   0,   0,   0 } } },  /* 255: not used by a script */
    { { {    6,  18,  74,  16 },  {  -10,  50,  54,  24 },  {  -50,  54,  40,  30 },  {  -32,  36,  10,  28 } } },  /* 256: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {   14,  18,  86,  16 },  {   -8,  36,  74,  18 },  {  -22,  40,  56,  24 },  {  -30,  36,  16,  38 } } },  /* 257: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {   26,  18,  82,  16 },  {   -6,  40,  74,  18 },  {  -16,  42,  58,  22 },  {  -38,  34,  16,  40 } } },  /* 258: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -58,  16,  46,  16 },  {  -42,  30,  40,  36 },  {  -12,  30,  40,  32 },  {    0,   0,   0,   0 } } },  /* 259: ATTACK 3 SP: EX 6(123)4+PP (routine Att_SENPUUKYAKU) */
    { { {   -7,  28,  92,  16 },  {  -36,  70,  72,  24 },  {  -36,  70,  46,  26 },  {    0,   0,   0,   0 } } },  /* 260: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -46,  22,  60,  18 },  {  -30,  32,  50,  22 },  {  -12,  38,  42,  22 },  {  -38,  86,   0,  42 } } },  /* 261: KAMAE */
    { { {  -34,  22,  78,  18 },  {  -22,  32,  66,  22 },  {  -14,  38,  46,  22 },  {  -38,  86,   0,  46 } } },  /* 262: KAMAE */
    { { {  -44,  22,  66,  18 },  {  -26,  32,  58,  22 },  {  -14,  38,  46,  22 },  {  -34,  62,   0,  46 } } },  /* 263: KAMAE */
    { { {  -42,  22,  72,  18 },  {  -26,  32,  62,  22 },  {  -14,  38,  46,  22 },  {  -26,  46,   0,  46 } } },  /* 264: KAMAE */
    { { {  -44,  22,  60,  18 },  {  -26,  32,  50,  22 },  {  -14,  38,  38,  22 },  {  -28,  68,   0,  38 } } },  /* 265: KAMAE */
    { { {  -36,  22,  82,  18 },  {  -24,  32,  66,  22 },  {  -16,  36,  44,  22 },  {  -34,  78,   0,  44 } } },  /* 266: KAMAE */
    { { {  -36,  22,  80,  18 },  {  -24,  32,  64,  22 },  {  -16,  36,  44,  22 },  {  -22,  52,   0,  44 } } },  /* 267: KAMAE */
    { { {  -26,  21,  84,  18 },  {  -25,  50,  72,  18 },  {  -29,  55,  40,  32 },  {  -33,  62,   0,  40 } } },  /* 268: FRONT WALK, BACK WALK */
    { { {  -23,  21,  88,  18 },  {  -24,  49,  73,  22 },  {  -31,  55,  40,  32 },  {  -43,  67,   0,  40 } } },  /* 269: FRONT WALK, BACK WALK */
    { { {  -22,  21,  94,  18 },  {  -23,  47,  79,  22 },  {  -26,  50,  45,  32 },  {  -30,  55,   0,  44 } } },  /* 270: FRONT WALK, BACK WALK */
    { { {  -39,  21,  62,  18 },  {  -26,  41,  51,  24 },  {  -22,  45,  32,  19 },  {  -28,  53,   0,  31 } } },  /* 271: JUMP JUNBI */
    { { {  -21,  21,  95,  18 },  {  -28,  42,  72,  24 },  {  -25,  42,  40,  31 },  {  -26,  46,   0,  39 } } },  /* 272: JUMP JUNBI, SP JUMP JUNBI */
    { { {  -39,  21,  47,  18 },  {  -26,  41,  38,  24 },  {  -20,  43,  25,  19 },  {  -33,  58,   0,  25 } } },  /* 273: ATTACK 7 L: not started by a command, SP JUMP JUNBI */
    { { {  -36,  28,  40,  20 },  {  -23,  41,  37,  18 },  {  -32,  62,  23,  19 },  {  -39,  80,   0,  22 } } },  /* 274: not used by a script */
    { { {  -47,  22,  66,  18 },  {  -28,  41,  59,  18 },  {  -23,  44,  36,  30 },  {  -31,  65,   0,  36 } } },  /* 275: PIYO */
    { { {  -14,  22,  76,  18 },  {  -22,  49,  60,  18 },  {  -25,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 276: UPPER L */
    { { {   -6,  22,  75,  18 },  {  -19,  49,  60,  18 },  {  -26,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 277: UPPER L */
    { { {   -2,  22,  74,  18 },  {  -17,  49,  60,  18 },  {  -27,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 278: UPPER L */
    { { {    0,  22,  73,  18 },  {  -16,  49,  60,  18 },  {  -28,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 279: UPPER L */
    { { {  -14,  22,  70,  18 },  {  -18,  49,  59,  18 },  {  -20,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 280: FACE S, FACE M, FACE L +7 */
    { { {   -2,  22,  68,  18 },  {  -12,  49,  58,  18 },  {  -17,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 281: FACE M, FACE L, FOOK TEMAE L +4 */
    { { {    6,  22,  66,  18 },  {   -8,  49,  57,  18 },  {  -15,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 282: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    { { {   10,  22,  64,  18 },  {   -6,  49,  56,  18 },  {  -14,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 283: FACE L, FOOK TEMAE SP */
    { { {  -34,  22,  69,  18 },  {  -24,  49,  58,  18 },  {  -22,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 284: BODY BROW S, NOUTEN M, NOUTEN L +2 */
    { { {  -38,  22,  66,  18 },  {  -22,  49,  56,  18 },  {  -20,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 285: NOUTEN M, NOUTEN L */
    { { {  -42,  22,  63,  18 },  {  -20,  49,  54,  18 },  {  -18,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 286: NOUTEN L */
    { { {  -46,  22,  60,  18 },  {  -18,  49,  52,  18 },  {  -16,  53,  37,  23 },  {  -31,  62,   0,  36 } } },  /* 287: NOUTEN L, TATAKI S, TATAKI V. S */
    { { {  -26,  28,  39,  20 },  {  -17,  41,  36,  18 },  {  -28,  62,  23,  19 },  {  -34,  76,   0,  22 } } },  /* 288: KAGAMI S, KAGAMI M, KAGAMI L +5 */
    { { {  -20,  28,  39,  20 },  {  -15,  41,  36,  18 },  {  -27,  62,  23,  19 },  {  -34,  76,   0,  22 } } },  /* 289: KAGAMI M, KAGAMI L, KGM TATAKI S +3 */
    { { {  -14,  28,  39,  20 },  {  -13,  41,  36,  18 },  {  -26,  62,  23,  19 },  {  -34,  76,   0,  22 } } },  /* 290: KAGAMI L */
    { { {   -8,  28,  39,  20 },  {  -11,  41,  36,  18 },  {  -25,  62,  23,  19 },  {  -34,  76,   0,  22 } } },  /* 291: KAGAMI L */
    { { {  -67,  24,  58,  17 },  {  -53,  29,  53,  28 },  {  -24,  44,  52,  36 },  {  -53, 100,   0,  53 } } },  /* 292: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -53,  22,  46,  17 },  {  -37,  20,  35,  31 },  {  -27,  50,  34,  47 },  {  -37, 113,   0,  35 } } },  /* 293: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -38,  24,  48,  17 },  {  -35,  23,  40,  18 },  {  -27,  34,  18,  54 },  {  -27,  79,   0,  18 } } },  /* 294: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -13,  26,  42,  20 },  {  -12,  40,  34,  12 },  {  -23,  50,  17,  17 },  {  -23,  55,   0,  17 } } },  /* 295: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   -9,  26,  43,  20 },  {  -10,  43,  34,  12 },  {  -20,  50,  17,  17 },  {  -23,  59,   0,  17 } } },  /* 296: ATTACK 12 S: EX 421+KK (plain script), ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {   -2,  22,  43,  19 },  {   -3,  36,  32,  17 },  {  -13,  49,  22,  14 },  {  -31,  65,   0,  24 } } },  /* 297: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   -2,  22,  43,  19 },  {   -4,  39,  34,  21 },  {  -29,  74,  19,  25 },  {  -29,  91,   0,  19 } } },  /* 298: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   15,  22,  43,  19 },  {   15,  38,  34,  25 },  {   -6,  56,  20,  26 },  {  -23,  76,   0,  32 } } },  /* 299: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   15,  22,  48,  19 },  {   15,  34,  34,  41 },  {   -6,  54,  20,  26 },  {  -23,  73,   0,  32 } } },  /* 300: ATTACK 12 S: EX 421+KK (plain script), ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {   -3,  22,  44,  19 },  {   -8,  41,  33,  27 },  {  -11,  44,  18,  30 },  {  -23,  59,   0,  36 } } },  /* 301: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -24,  22,  35,  19 },  {  -12,  22,  27,  32 },  {   10,  23,  27,  36 },  {  -20,  53,   0,  31 } } },  /* 302: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -39,  22,  26,  19 },  {  -27,  25,  26,  27 },  {  -16,  39,  36,  33 },  {  -23,  75,   0,  36 } } },  /* 303: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -52,  22,  23,  19 },  {  -39,  22,  20,  31 },  {  -28,  46,  28,  30 },  {  -41, 112,   0,  28 } } },  /* 304: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -69,  22,  34,  19 },  {  -55,  29,  24,  38 },  {  -28,  30,  39,  52 },  {  -50,  38,   0,  24 } } },  /* 305: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -50,  22,  41,  19 },  {  -32,  23,  33,  49 },  {   -9,  36,  33,  36 },  {  -33,  56,   0,  33 } } },  /* 306: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -57,  22,  57,  19 },  {  -38,  25,  47,  37 },  {  -29,  44,  36,  39 },  {  -40,  41,   0,  36 } } },  /* 307: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -46,  22,  72,  19 },  {  -36,  38,  60,  30 },  {  -33,  48,  40,  26 },  {  -44,  80,   0,  43 } } },  /* 308: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -29,  22,  75,  19 },  {  -23,  39,  62,  24 },  {  -31,  59,  37,  25 },  {  -38,  70,   0,  37 } } },  /* 309: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -34,  22,  69,  19 },  {  -27,  42,  58,  24 },  {  -33,  63,  37,  34 },  {  -41,  84,   0,  37 } } },  /* 310: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -57,  16,  58,  16 },  {  -44,  26,  47,  36 },  {  -18,  36,  66,  22 },  {  -41,  57,   0,  66 } } },  /* 311: M KICK C */
    { { {  -53,  16,  39,  16 },  {  -39,  30,  36,  36 },  {   -9,  32,  49,  34 },  {  -36,  59,   0,  49 } } },  /* 312: M KICK C */
    { { {  -40,  16,  42,  16 },  {  -26,  23,  33,  33 },  {   -3,  36,  32,  38 },  {  -28,  61,   0,  32 } } },  /* 313: M KICK C */
    { { {  -40,  23,  40,  18 },  {  -24,  21,  23,  35 },  {   -4,  22,  31,  34 },  {  -25,  37,   0,  31 } } },  /* 314: M KICK C */
    { { {  -42,  23,  38,  18 },  {  -35,  31,  24,  33 },  {   -4,  22,  31,  34 },  {  -25,  37,   0,  31 } } },  /* 315: M KICK C */
    { { {  -37,  21,  37,  17 },  {  -28,  27,  28,  35 },  {   -1,  39,  28,  33 },  {  -28,  43,   0,  28 } } },  /* 316: M KICK C */
    { { {  -40,  21,  37,  17 },  {  -28,  27,  28,  33 },  {   -1,  30,  25,  45 },  {  -28,  39,   0,  28 } } },  /* 317: M KICK C */
    { { {  -63,  22,  45,  19 },  {  -48,  29,  30,  39 },  {  -36,  37,  30,  51 },  {  -50,  38,   0,  30 } } },  /* 318: ATTACK 11 SP: 421+K heavy (plain script), ATTACK 12 S: EX 421+KK (plain script), ATTACK 12 M: not started by a command */
    { { {  -69,  22,  34,  19 },  {  -55,  27,  24,  52 },  {  -34,  30,  39,  52 },  {  -55,  48,   0,  24 } } },  /* 319: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -63,  22,  38,  19 },  {  -49,  22,  24,  47 },  {  -28,  29,  23,  46 },  {  -50,  38,   0,  24 } } },  /* 320: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -14,  22,  32,  19 },  {  -31,  36,  22,  43 },  {  -20,  54,  50,  22 },  {  -32,  75,   0,  22 } } },  /* 321: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -11,  22,  27,  19 },  {  -54,  92,  34,  22 },  {  -59,  72,  56,  31 },  {  -30,  47,   0,  34 } } },  /* 322: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -16,  22,  22,  19 },  {  -17,  35,  34,  22 },  {  -25,  39,  56,  33 },  {  -23,  53,   0,  34 } } },  /* 323: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -16,  22,  22,  19 },  {  -17,  35,  34,  22 },  {  -19,  39,  56,  54 },  {  -23,  53,   0,  34 } } },  /* 324: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -22,  22,  17,  19 },  {  -21,  28,  34,  32 },  {  -21,  59,  63,  22 },  {  -28,  51,   0,  34 } } },  /* 325: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -41,  22,  17,  19 },  {  -40,  30,  32,  32 },  {  -34,  46,  53,  27 },  {  -48,  51,   0,  34 } } },  /* 326: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -46,  22,  18,  19 },  {  -41,  71,  32,  25 },  {  -29,  50,  53,  27 },  {  -49,  93,   0,  34 } } },  /* 327: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -57,  22,  52,  19 },  {  -43,  51,  47,  33 },  {  -12,  34,  47,  22 },  {  -23,  48,   0,  47 } } },  /* 328: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -41,  22,  84,  19 },  {  -34,  37,  74,  22 },  {  -44,  62,  45,  29 },  {  -25,  47,   0,  45 } } },  /* 329: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -31,  24,  78,  16 },  {  -32,  55,  60,  20 },  {  -21,  50,  36,  26 },  {  -13,  48,   0,  36 } } },  /* 330: L KICK C */
    { { {  -24,  24,  80,  16 },  {  -28,  55,  60,  20 },  {  -14,  50,  36,  26 },  {   -8,  48,   0,  36 } } },  /* 331: L KICK C */
    { { {  -24,  24,  89,  16 },  {  -28,  48,  69,  20 },  {  -12,  46,  43,  26 },  {   -8,  49,   0,  44 } } },  /* 332: L KICK C */
    { { {  -15,  24,  92,  16 },  {  -23,  49,  76,  18 },  {  -21,  43,  51,  25 },  {   -5,  28,   3,  48 } } },  /* 333: L KICK C */
    { { {   -9,  25,  93,  16 },  {  -22,  51,  76,  20 },  {  -16,  40,  38,  38 },  {    0,   0,   0,   0 } } },  /* 334: L KICK C */
    { { {  -11,  25, 101,  16 },  {  -22,  51,  87,  20 },  {  -16,  40,  49,  38 },  {    0,   0,   0,   0 } } },  /* 335: L KICK C */
    { { {  -20,  25,  98,  16 },  {  -27,  56,  87,  22 },  {  -21,  45,  49,  38 },  {    0,   0,   0,   0 } } },  /* 336: L KICK C */
    { { {  -34,  24,  93,  17 },  {  -28,  47,  79,  23 },  {  -28,  53,  43,  36 },  {    0,   0,   0,   0 } } },  /* 337: L KICK C */
    { { {  -40,  24,  92,  16 },  {  -37,  48,  81,  18 },  {  -32,  59,  51,  34 },  {  -32,  61,   0,  51 } } },  /* 338: L KICK C */
    { { {  -46,  24,  87,  16 },  {  -37,  36,  74,  18 },  {  -30,  48,  51,  24 },  {  -32,  61,   0,  51 } } },  /* 339: L KICK C */
    { { {  -44,  24,  80,  16 },  {  -34,  48,  70,  18 },  {  -36,  60,  40,  30 },  {  -36,  80,   0,  40 } } },  /* 340: L KICK C */
    { { {    0,   0,   0,   0 },  {  -19,  42,  61,  20 },  {  -24,  48,  44,  17 },  {  -30,  55,  25,  19 } } },  /* 341: AIR NORMAL */
    { { {    0,   0,   0,   0 },  {  -11,  47,  72,  20 },  {  -23,  44,  58,  20 },  {  -37,  55,  36,  22 } } },  /* 342: AIR NORMAL */
    { { {    0,   0,   0,   0 },  {  -12,  39,  58,  19 },  {  -31,  49,  52,  20 },  {  -42,  55,  33,  21 } } },  /* 343: AIR NORMAL */
    { { {    0,   0,   0,   0 },  {  -19,  42,  56,  20 },  {  -22,  47,  42,  14 },  {  -33,  57,  24,  19 } } },  /* 344: ASIBARAI SIRI, KUNOJI NOKE, GILL */
    { { {    0,   0,   0,   0 },  {  -17,  48,  53,  19 },  {   -5,  47,  44,  17 },  {  -24,  57,  24,  28 } } },  /* 345: ASIBARAI SIRI, TTKI V. AIR, GILL */
    { { {    0,   0,   0,   0 },  {    2,  41,  46,  17 },  {  -12,  56,  33,  19 },  {  -23,  59,  19,  22 } } },  /* 346: ASIBARAI SIRI, TTKI V. AIR, GILL */
    { { {    0,   0,   0,   0 },  {    3,  44,  23,  24 },  {   -3,  38,  14,  19 },  {  -40,  36,  15,  28 } } },  /* 347: ASIBARAI SIRI, TTKI V. AIR, HARAIGOSHI +1 */
    { { {    0,   0,   0,   0 },  {  -19,  42,  46,  20 },  {  -15,  48,  33,  17 },  {  -20,  55,  17,  19 } } },  /* 348: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -24,  42,  46,  20 },  {  -18,  48,  33,  17 },  {  -22,  55,  17,  19 } } },  /* 349: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -38,  39,  34,  20 },  {  -31,  35,  21,  18 },  {   -7,  47,  10,  32 } } },  /* 350: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -42,  39,  30,  20 },  {  -35,  34,  16,  18 },  {  -19,  48,  12,  32 } } },  /* 351: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -20,  42,  58,  20 },  {  -24,  48,  44,  14 },  {  -32,  55,  25,  19 } } },  /* 352: NOKEZORI, KUNOJI NOKE, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -19,  38,  71,  19 },  {  -22,  42,  54,  17 },  {  -28,  47,  27,  27 } } },  /* 353: NOKEZORI, KUNOJI NOKE, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {   -9,  38,  71,  19 },  {  -19,  42,  57,  17 },  {  -28,  40,  31,  27 } } },  /* 354: NOKEZORI, KUNOJI NOKE, TATAKI AIR +1 */
    { { {    0,   0,   0,   0 },  {    9,  29,  53,  29 },  {  -14,  34,  48,  27 },  {  -22,  37,  24,  27 } } },  /* 355: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {    9,  29,  48,  29 },  {  -14,  34,  43,  27 },  {  -26,  37,  24,  33 } } },  /* 356: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {   12,  29,  42,  29 },  {  -13,  30,  37,  30 },  {  -30,  39,  24,  33 } } },  /* 357: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {   12,  29,  37,  29 },  {  -13,  29,  32,  30 },  {  -36,  38,  25,  29 } } },  /* 358: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {    7,  29,  29,  26 },  {  -17,  28,  28,  28 },  {  -42,  40,  19,  31 } } },  /* 359: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    { { {    0,   0,   0,   0 },  {    7,  30,  19,  31 },  {  -18,  28,  21,  29 },  {  -40,  42,  17,  30 } } },  /* 360: NOKEZORI, KUNOJI, KIRIMOMI +6 */
    { { {    0,   0,   0,   0 },  {    7,  30,  15,  31 },  {   -9,  28,  21,  28 },  {  -38,  36,  16,  33 } } },  /* 361: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    { { {    0,   0,   0,   0 },  {    7,  30,  15,  31 },  {   -8,  28,  22,  25 },  {  -41,  36,  18,  37 } } },  /* 362: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    { { {    0,   0,   0,   0 },  {   12,  31,  12,  27 },  {   -6,  28,  20,  23 },  {  -39,  38,  19,  37 } } },  /* 363: NOKEZORI, KUNOJI, KIRIMOMI +6 */
    { { {    0,   0,   0,   0 },  {   12,  31,  12,  27 },  {   -5,  28,  18,  27 },  {  -39,  38,  13,  38 } } },  /* 364: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {   12,  31,  12,  22 },  {   -5,  27,  18,  24 },  {  -39,  38,  13,  37 } } },  /* 365: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {   12,  31,   8,  22 },  {   -5,  27,  17,  21 },  {  -40,  38,  10,  38 } } },  /* 366: NOKEZORI, KUNOJI, KIRIMOMI +4 */
    { { {    0,   0,   0,   0 },  {   12,  31,   7,  20 },  {   -5,  27,  14,  21 },  {  -38,  35,  13,  31 } } },  /* 367: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    { { {    0,   0,   0,   0 },  {   12,  31,   7,  20 },  {   -5,  27,  11,  17 },  {  -37,  33,  11,  24 } } },  /* 368: NOKEZORI, KUNOJI, KIRIMOMI +5 */
    { { {    0,   0,   0,   0 },  {  -19,  45,  58,  19 },  {  -25,  53,  44,  14 },  {  -32,  58,  25,  19 } } },  /* 369: KUNOJI, ALEX B.D, HANEKAERI HARA */
    { { {    0,   0,   0,   0 },  {    9,  41,  61,  22 },  {   -9,  40,  42,  20 },  {  -27,  41,  25,  20 } } },  /* 370: KUNOJI, ALEX B.D, HANEKAERI HARA */
    { { {    0,   0,   0,   0 },  {  -22,  41,  63,  20 },  {  -24,  48,  46,  17 },  {  -30,  55,  25,  21 } } },  /* 371: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -17,  38,  62,  20 },  {  -23,  47,  46,  17 },  {  -32,  55,  25,  21 } } },  /* 372: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    7,  38,  63,  21 },  {   -7,  40,  46,  17 },  {  -20,  50,  25,  21 } } },  /* 373: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   14,  38,  61,  23 },  {   -1,  38,  50,  19 },  {  -27,  58,  29,  22 } } },  /* 374: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    9,  38,  64,  21 },  {   -1,  35,  54,  19 },  {  -16,  46,  30,  23 } } },  /* 375: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   14,  33,  54,  23 },  {    6,  33,  53,  22 },  {  -22,  45,  40,  30 } } },  /* 376: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   13,  31,  46,  23 },  {    8,  33,  53,  22 },  {  -18,  58,  64,  31 } } },  /* 377: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -2,  39,  44,  20 },  {    6,  33,  53,  22 },  {    1,  50,  71,  28 } } },  /* 378: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -7,  39,  41,  22 },  {    7,  31,  53,  20 },  {   13,  47,  64,  32 } } },  /* 379: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -6,  36,  42,  22 },  {    4,  29,  51,  18 },  {   17,  47,  59,  32 } } },  /* 380: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -1,  27,  44,  26 },  {   12,  26,  48,  24 },  {   25,  46,  55,  36 } } },  /* 381: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -1,  32,  52,  26 },  {   13,  25,  44,  25 },  {   25,  28,  35,  46 } } },  /* 382: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    2,  39,  64,  21 },  {    2,  37,  48,  16 },  {    2,  44,  24,  25 } } },  /* 383: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    8,  39,  65,  21 },  {    0,  35,  51,  19 },  {   -8,  39,  26,  25 } } },  /* 384: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -21,  42,  57,  19 },  {  -18,  48,  45,  17 },  {  -30,  55,  25,  21 } } },  /* 385: TTKI V. AIR, UP P GUARD P M */
    { { {    0,   0,   0,   0 },  {    3,  35,  48,  31 },  {  -19,  39,  43,  23 },  {  -28,  41,  22,  27 } } },  /* 386: DENKI */
    { { {    0,   0,   0,   0 },  {   15,  29,   0,  23 },  {  -10,  25,   0,  20 },  {  -35,  26,   0,  30 } } },  /* 387: KUNOJI NOKE */
    { { {    0,  22,  77,  18 },  {  -21,  46,  62,  18 },  {  -26,  53,  39,  23 },  {  -29,  54,   0,  39 } } },  /* 388: TUKAMIKAKARI B */
    { { {   15,  22,  68,  18 },  {  -14,  46,  60,  18 },  {  -22,  60,  39,  23 },  {  -28,  54,   0,  39 } } },  /* 389: TUKAMIKAKARI B */
    { { {   26,  22,  65,  18 },  {    8,  40,  44,  31 },  {  -17,  34,  40,  34 },  {  -30,  56,   0,  41 } } },  /* 390: TUKAMIKAKARI B */
    { { {   33,  22,  63,  18 },  {   12,  38,  44,  36 },  {  -13,  33,  40,  35 },  {  -16,  46,   0,  40 } } },  /* 391: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {   26,  22,  70,  18 },  {   12,  32,  41,  42 },  {  -27,  40,  48,  30 },  {  -16,  38,   0,  48 } } },  /* 392: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {    8,  22,  93,  18 },  {  -13,  45,  74,  25 },  {  -23,  34,  53,  27 },  {  -23,  38,   0,  53 } } },  /* 393: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {  -24,  22,  93,  18 },  {  -30,  47,  74,  22 },  {  -23,  48,  53,  27 },  {  -23,  48,   0,  53 } } },  /* 394: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {  -35,  22,  89,  18 },  {  -30,  41,  72,  22 },  {  -28,  56,  43,  29 },  {  -28,  74,   0,  43 } } },  /* 395: TUKAMIHAZUSARE, TUKAMIKAKARI B */
};

const HAND_BOX elena_hand_box[133] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -108,  84,  32,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: not used by a script */
    { { {  -92,  56,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: KAGAMI K A */
    { { { -100,  82,  32,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: KAGAMI P A */
    { { {  -79,  49,  76,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: KAGAMI P A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 11 S: after 214+K (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -68,  35,  58,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: KAGAMI P A, follow-up of M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {  -89,  49,  24,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: KAGAMI K A */
    { { { -104,  72,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    { { {  -16,  18, 112,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 8 L: not started by a command, WIN 1, WIN 6 */
    { { {  -72,  42,  56,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -56,  48,  68,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -84,  72,  51,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH C, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -38,  37,  59,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH A */
    { { {  -77,  42,  78,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -79,  30,  86,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { {  -63,  62,  57,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -73,  65,  54,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L KICK A, follow-up of L PUNCH A */
    { { {  -69,  41,  77,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: S PUNCH A */
    { { {  -62,  30,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: S KICK A, ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -88, 142,   0,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI K C */
    { { {  -48,  24,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {  -20,  20,  80,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: ATTACK 3 S: 6(123)4+P light (routine Att_SENPUUKYAKU), ATTACK 3 M: 6(123)4+P medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 6(123)4+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   40,  40,  86,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {   40,  48,  56,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {   36,  49,  46,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: follow-up of SP WIN 1, follow-up of APPEAR 1, follow-up of SP WIN 3 +1 */
    { { {  -97,  41,  49,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: M KICK A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA), follow-up of M KICK A */
    { { {  -95,  43,  48,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: M KICK A */
    { { {  -94,  68,  65,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P M A, F JUMP P M A */
    { { {  -84,  55,  47,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P L A, F JUMP P L A, follow-up of V JUMP P M A, F JUMP P M A */
    { { { -101,  60,  41,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP K S A, F JUMP K S A */
    { { {  -87,  42,  45,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: V JUMP K M A, F JUMP K M A, follow-up of V JUMP P S A, F JUMP P S A */
    { { {  -80,  62,  45,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: V JUMP K L A, F JUMP K L A */
    { { {  -90,  82,   0,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI K A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -24,  24,  36,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: not used by a script */
    { { {  -48,  22,  94,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {  -82,  58,  72,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: not used by a script */
    { { {  -72,  36,  36,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -51,  27,  30,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -80,  63,  76,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -24,  48,  84,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {  -28,  14,  80,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -67,  53,  73,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -84,  63,  74,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU), ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU) */
    { { {  -30,  26,  85,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -96,  76,  58,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 2 S: 4(123)6+K light (routine Att_SENPUUKYAKU), ATTACK 2 M: 4(123)6+K medium (routine Att_SENPUUKYAKU), ATTACK 2 L: 4(123)6+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -34,  12,  30,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -66,  44,  64,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -42,  67,  85,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -38,  33,   0,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -38,  33,   0,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -50,  37,  49,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -53,  39,  59,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -63,  52,  77,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -44,  39,  89,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -81,  71,  63,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -61,  36,  88,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: L PUNCH A, follow-up of L PUNCH A, ATTACK 6 L: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { { { -101,  64,  27,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: KAGAMI P A */
    { { { -108,  68,  11,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: KAGAMI K A */
    { { {  -82,  40,  66,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: M PUNCH A */
    { { {  -76,  48,  40,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -55,  30,  31,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: L KICK A, follow-up of L PUNCH A */
    { { {  -85,  42,  41,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: M KICK A, follow-up of M KICK A */
    { { {  -41,  18,  29,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {  -74,  55,  49,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {  -52,  31,  32,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {  -77,  53,  55,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    { { {  -92,  68,  48,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: not used by a script */
    { { {  -67,  41,  74,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { { -106,  56,  48,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: not used by a script */
    { { { -118,  52,  52,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -46,  24,  62,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: not used by a script */
    { { {  -69,  45,  58,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: not used by a script */
    { { { -103,  44,  53,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -148,  61,  50,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -138,  61,  50,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -134,  62,  41,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -134,  66,  41,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { { -128,  85,  41,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -55,  42,  73,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -63,  44,  74,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -12,   9,  85,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -81,  62,  58,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 2 SP: EX 4(123)6+KK (routine Att_SENPUUKYAKU) */
    { { {  -62,  26,  75,  19 },  {   -4,  61,  87,   9 },  {   41,  58,  93,  11 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   -5,  21,  81,  12 },  {    8,  12,  89,  10 },  {   15,  12,  96,   8 },  {   23,  14, 101,   8 } } },  /* 83: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -22,  21,  72,  26 },  {  -16,  15,  98,  23 },  {    6,  20,  47,  18 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { { -112,  89,  19,  16 },  {   13,  18,  46,  21 },  {   23,  13,  66,  15 },  {   27,  15,  81,  16 } } },  /* 85: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { { -113,  92,  22,  15 },  {   17,  18,  46,  21 },  {   27,  13,  60,  15 },  {   31,  15,  71,  16 } } },  /* 86: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -37,  24,  25,  17 },  {  -45,  13,  35,  16 },  {   33,  22,  27,  14 },  {   50,  23,  37,  12 } } },  /* 87: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -28,  17,  44,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -89,  65,  13,  15 },  {    1,  17,  46,  41 },  {    6,  17,  86,  13 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -91,  68,  13,  16 },  {   -4,  19,  46,  41 },  {   -1,  17,  86,  20 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -83,  60,  21,  14 },  {   -8,  17,  63,  29 },  {  -15,  12,  92,  12 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   -5,  18,  59,  12 },  {  -14,  13,  69,  13 },  {  -24,  11,  79,   8 },  {  -38,  15,  85,   8 } } },  /* 92: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -45,  18,  45,  14 },  {  -26,  11,  53,  11 },  {   23,  12,  36,  18 },  {    0,   0,   0,   0 } } },  /* 93: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -21,  27,  58,   9 },  {   18,  13,  28,  21 },  {   30,  20,  28,  14 },  {   50,   9,  27,   9 } } },  /* 94: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {  -17,  23,  91,  10 },  {   -3,  26, 101,  16 },  {    2,  72,  38,  16 },  {  -51,  16,  62,  19 } } },  /* 95: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +2 */
    { { {   -3,  27,  69,  21 },  {    5,  26,  88,  13 },  {   26,  22,  97,  17 },  {    0,   0,   0,   0 } } },  /* 96: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -13,  17,  75,  18 },  {   15,  27,  55,  17 },  {   40,  18,  51,  12 },  {   52,  19,  47,  11 } } },  /* 97: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {   -4,  17,  77,  17 },  {   11,  17,  39,  18 },  {   32,  26,  21,  14 },  {    0,   0,   0,   0 } } },  /* 98: M KICK C, ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script) +2 */
    { { {  -55,  21,  74,  16 },  {    0,  55,  82,  13 },  {   42,  30,  89,  13 },  {   72,  25,  95,   9 } } },  /* 99: M KICK C */
    { { {    1,  18,  83,  15 },  {   13,  16,  98,  19 },  {   25,  11, 116,  10 },  {   35,  10, 124,   9 } } },  /* 100: M KICK C */
    { { {   -8,  22,  69,  11 },  {  -12,  17,  77,  31 },  {   -8,  18, 108,  18 },  {   33,  41,  39,  15 } } },  /* 101: M KICK C */
    { { {    0,   0,   0,   0 },  {   -9,  14,  58,  11 },  {   18,  25,  33,  25 },  {   33,  15,  58,  23 } } },  /* 102: M KICK C */
    { { {    0,   0,   0,   0 },  {   -9,  14,  58,  11 },  {   12,  25,  23,  31 },  {   29,  15,  53,  24 } } },  /* 103: M KICK C */
    { { {  -25,  45,  58,  13 },  {  -50,  40,  69,  11 },  {  -72,  23,  68,  12 },  {   37,  11,  47,  24 } } },  /* 104: M KICK C */
    { { {  -37,  57,  61,  15 },  {  -12,  19,  75,  19 },  {  -20,  12,  89,  10 },  {  -38,  21,  99,  10 } } },  /* 105: M KICK C */
    { { {  -27,  21,  81,  22 },  {  -21,  21, 103,  16 },  {   -4,  40,  24,  16 },  {   28,  42,  20,  14 } } },  /* 106: ATTACK 11 SP: 421+K heavy (plain script), ATTACK 12 S: EX 421+KK (plain script), ATTACK 12 M: not started by a command */
    { { {  -30,  19,  91,  10 },  {  -24,  19, 101,  20 },  {   -4,  57,  42,  18 },  {   53,  24,  50,  13 } } },  /* 107: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -32,  16,  70,  24 },  {  -39,  12,  92,  16 },  {  -49,  12, 107,  18 },  {    1,  79,  30,  12 } } },  /* 108: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -15,  19,  72,  26 },  {  -11,  16,  98,  27 },  {  -13,  16, 125,  12 },  {    0,   0,   0,   0 } } },  /* 109: ATTACK 12 S: EX 421+KK (plain script) */
    { { {    0,  18,  79,  18 },  {   12,  15,  94,  15 },  {   20,  20, 106,  17 },  {   37,  18, 119,  15 } } },  /* 110: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -99,  75,  69,  17 },  {    9,  18,  83,  20 },  {   19,  21,  99,  20 },  {   35,  25, 114,  15 } } },  /* 111: ATTACK 12 S: EX 421+KK (plain script) */
    { { { -101,  50, 100,  14 },  {  -36,  59,  80,  17 },  {   12,  22,  95,  29 },  {   26,  35, 119,  15 } } },  /* 112: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -40,  18, 140,  18 },  {  -35,  17, 104,  37 },  {    6,  23, 106,  29 },  {   26,  21, 131,  22 } } },  /* 113: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -29,  18, 140,  18 },  {  -24,  16, 110,  30 },  {    7,  18, 108,  26 },  {   21,  19, 132,  19 } } },  /* 114: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -17,  28, 140,  18 },  {  -14,  25, 110,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -15,  19, 140,  18 },  {  -14,  34, 110,  30 },  {   11,  18,  76,  38 },  {    0,   0,   0,   0 } } },  /* 116: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -27,  19, 114,  42 },  {  -21,  25,  85,  30 },  {   31,  20,  77,  27 },  {   46,  20, 101,  17 } } },  /* 117: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -24,  20, 110,  39 },  {  -26,  26,  81,  29 },  {    7,  44,  48,  13 },  {   43,  25,  40,  10 } } },  /* 118: ATTACK 12 S: EX 421+KK (plain script) */
    { { {   -4,  37,  75,  12 },  {   21,  21,  87,  20 },  {   38,  14, 102,  13 },  {   47,  21, 111,  12 } } },  /* 119: ATTACK 12 S: EX 421+KK (plain script) */
    { { {  -54,  31,  29,  23 },  {   22,  24,  44,  16 },  {   45,  12,  53,  11 },  {   55,  29,  59,  11 } } },  /* 120: ATTACK 12 S: EX 421+KK (plain script) */
    { { { -113,  93,  17,  18 },  {   17,  18,  46,  21 },  {   27,  13,  60,  15 },  {   31,  15,  71,  16 } } },  /* 121: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +1 */
    { { {  -90,  67,  13,  16 },  {   -4,  19,  46,  41 },  {   -1,  17,  86,  20 },  {    0,   0,   0,   0 } } },  /* 122: ATTACK 11 M: 421+K light (plain script), ATTACK 11 L: 421+K medium (plain script), ATTACK 11 SP: 421+K heavy (plain script) +1 */
    { { {  -35,  22,  97,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: L KICK C */
    { { {  -64,  28, 118,  21 },  {  -54,  23, 103,  20 },  {  -41,  21,  88,  21 },  {    0,   0,   0,   0 } } },  /* 124: L KICK C */
    { { {  -95,  71,  58,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: L KICK C */
    { { {  -70,  33,  38,  30 },  {  -43,  22,  50,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 126: L KICK C */
    { { {  -62,  25,  27,  19 },  {  -45,  21,  34,  19 },  {  -27,  18,  42,  26 },  {    0,   0,   0,   0 } } },  /* 127: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {  -39,  22,  29,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {  -40,  17,  34,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { {   24,  36,  13,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: TUKAMIHAZUSARE, TUKAMIKAKARI B */
    { { { -115,  27,  62,  28 },  {  -98,  35,  54,  32 },  {  -79,  29,  47,  33 },  {    0,   0,   0,   0 } } },  /* 131: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { { -119,  31,  62,  28 },  {  -98,  35,  54,  32 },  {  -79,  29,  47,  33 },  {    0,   0,   0,   0 } } },  /* 132: ATTACK 9 M: 214+K light (routine Att_SLIDE_and_JUMP), ATTACK 9 L: 214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 9 SP: 214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
};

const HOSEI_BOX elena_hos_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -23,   46,    0,   74 } },  /* 1: STAND UP, WALK END, PARING HEAD +105 */
    { {  -23,   46,    0,   47 } },  /* 2: KAGAMU, KAGAMI KAMAE, PARING DOWN +53 */
    { {  -23,   46,   56,   44 } },  /* 3: JUMP FRONT, SP JUMP FRONT, GUARD AIR +33 */
    { {  -23,   46,    0,   36 } },  /* 4: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    { {  -31,   62,    0,   67 } },  /* 5: DASH HUMIKOMI */
    { {  -23,   46,   28,   44 } },  /* 6: BODY SLAM, TOMOE RYU, TOMOE ORO +33 */
    { {  -23,   46,    0,   30 } },  /* 7: NEKOROBI S, no name */
    { {  -23,   46,   56,   41 } },  /* 8: L KICK A, follow-up of L PUNCH A, ATTACK 6 S: after SA II 23623+K (routine Att_SHOURYUUREPPA) +1 */
    { {  -23,   46,   38,   44 } },  /* 9: ATTACK 4 S: SA I 23623+K (routine Att_SHOURYUUREPPA), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +6 */
    { {  -23,   46,    0,   64 } },  /* 10: follow-up of S PUNCH A, S PUNCH C +14, no name, PIYO +6 */
    { {  -23,   46,    0,   58 } },  /* 11: UPPER L, FACE S, FACE M +13 */
};
