/*
 * HUGO_ATTR.C  Hugo's attack attributes and random sound lists
 *
 * hugo_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * hugo_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR hugo_catt_table[72] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  0,  0,  7, 33,  2,  1,  0,  3,  9, -9, 18, 72),  /* 1: S PUNCH A */
    ATTR( 34,  1,  0,  0,  0,  0,  0, 26,  1, 62,  0, 12,  0,  0, 24, 34,  6,  4,  0,  3, 13,-14, 27, 73),  /* 2: M PUNCH A */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 32,  1, 54,  0,  9,  0,  0, 34, 35, 10,  7,  0,  3, 16,-18,117, 73),  /* 3: L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1,  0,  0, 10,  0,  0,  0, 34,  0,  0,  1,  3,  8, -8, 70,  0),  /* 4: TUKAMIKAKARI A */
    ATTR( 97,  2,  0,  0,  0,  0, 55,  1,  1, 63,  0,  7,  0,  0, 32, 34,  6, 13,  0,  3, 12,-12,  0, 60),  /* 5: CATCH 1 */
    ATTR( 33,  3,  0,  0,  0,  0,  0, 27,  1, 62,  0, 14,  0,  0, 32, 49, 10,  7,  0,  3, 14,-19,117, 73),  /* 6: L PUNCH B */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  0,  0, 10, 33,  1,  1,  0,  3, 10,-10, 34, 72),  /* 7: S KICK A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 26,  1, 62,  0, 13,  0,  0, 14, 34,  4,  5,  0,  3, 12,-16, 43, 73),  /* 8: M KICK A */
    ATTR( 37,  2,  0,  0,  0,  0, 62, 25, 49, 62,  2, 11,  3,  0, 22, 33,  7, 10,  0,  7, 11,-15,118, 73),  /* 9: ATTACK 1 S: 214+P light (plain script), ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0, 62, 26, 49, 62,  2, 11,  3,  0, 25, 33,  8, 10,  0,  7, 11,-18,118, 73),  /* 10: ATTACK 1 M: 214+P medium (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0, 62, 27, 49, 62,  2, 11,  3,  0, 28, 33,  9, 10,  0,  7, 11,-20,118, 73),  /* 11: ATTACK 1 L: 214+P heavy (plain script) */
    ATTR( 34,  3,  0,  0,  0,  0,  0, 11,  1, 54,  0, 13,  0,  0, 30, 49,  9,  7,  0,  3, 14,-14,121, 73),  /* 12: L KICK A */
    ATTR( 32,  0,  0,  0,  0,  0, 56,  2,  1,  9,  0, 14,  0,  0,  6, 32,  2,  1,  1,  3,  9, -9, 71, 53),  /* 13: CATCH 6, CATCH 7, CATCH 8 */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  0,  0,  6, 33,  1,  1,  0,  3,  9, -9, 18, 72),  /* 14: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 63,  0, 13,  0,  0, 18, 34,  1,  4,  0,  3, 13,-14, 27, 73),  /* 15: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 27,  1, 45,  0, 12,  0,  0,  8, 34,  1,  1,  0,  3,  9,-11, 34, 73),  /* 16: KAGAMI K A */
    ATTR( 92,  2,  0,  0,  0,  0,  0,  3,  1, 63,  0, 15,  4,  0, 22, 35,  6,  7,  0,  3, 13,-15,117, 73),  /* 17: KAGAMI P A */
    ATTR( 92,  2,  0,  0,  0,  0,  0, 27,  1, 63,  0, 12,  4,  0, 20, 49,  5,  7,  0,  3, 12,-14,117, 73),  /* 18: KAGAMI P A */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  4,  1, 63,  0, 10,  0,  0, 34, 49,  6,  7,  0,  3,  8,-10,121, 73),  /* 19: KAGAMI K A */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  5,  1, 54,  0, 10,  0,  0, 30, 35,  4,  7,  0,  3, 10,-12,121, 73),  /* 20: KAGAMI K A */
    ATTR(108,  0,  0,  0,  0,  0, 73, 19, 49, 63,  0, 12,  0,  0, 48, 34,  9, 11,  0,  3, 10,-10,127, 73),  /* 21: CATCH 9 */
    ATTR(108,  0,  0,  0,  0,  0, 73, 19, 49, 63,  0, 12,  0,  0, 51, 34,  9, 11,  0,  3, 10,-10,128, 73),  /* 22: CATCH 10 */
    ATTR(108,  0,  0,  0,  0,  0, 73, 19, 49, 63,  0, 12,  0,  0, 56, 34,  9, 11,  0,  3, 10,-10,129, 73),  /* 23: CATCH 11 */
    ATTR( 89,  2,  0,  0,  0,  0,  0, 18,  1, 45,  0, 12,  0,  0, 20, 36,  1,  4,  0,  3, 13,-14, 43, 73),  /* 24: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 10,  2,  0,  8, 38,  4,  1,  0,  3,  8, -8, 18, 72),  /* 25: V JUMP P S A */
    ATTR( 32,  1,  0,  0,  0,  1,  0, 26, 49,  0,  0, 10,  0,  0,  0, 34,  0,  4,  1,  3,  8, -8, 66,  0),  /* 26: ATTACK 3 S: 360+P light (plain script), ATTACK 3 M: 360+P medium (plain script), ATTACK 3 L: 360+P heavy/EX (plain script) */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 10,  2,  0, 20, 38,  6,  4,  0,  3,  9, -9, 43, 73),  /* 27: V JUMP P M A */
    ATTR( 36,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 30, 39,  8,  7,  0,  3, 10,-10,117, 73),  /* 28: V JUMP P L A, V JUMP P L B */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 11,  2,  0, 12, 38,  3,  1,  0,  3,  8, -8, 34, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 20, 38,  5,  4,  0,  3,  9, -9, 43, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 26, 39,  7,  7,  0,  3, 10,-10,121, 73),  /* 31: V JUMP K L A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 26,  1, 54,  0, 11,  0,  0, 10, 34,  2,  1,  0,  3, 12,-16, 43, 73),  /* 32: M KICK A */
    ATTR( 36,  2,  0,  0,  0,  0, 58, 27, 49, 62,  3, 12,  0,  0,  4, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 33: ATTACK 1 SP: EX 214+PP (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0, 59, 27, 49, 62,  3, 12,  0,  0, 12, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 34: ATTACK 1 SP: EX 214+PP (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0, 60, 27, 49, 62,  3, 12,  0,  0, 12, 35,  1,  0,  0,  7,  0, -2,117, 73),  /* 35: not used by a script */
    ATTR( 36,  2,  0,  0,  0,  0, 61, 27, 49, 62,  3, 12,  0,  0,  4, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 36: not used by a script */
    ATTR( 35,  2,  0,  0,  0,  0, 62, 27, 49, 62,  3, 12,  0,  0,  4, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 37: not used by a script */
    ATTR( 34,  2,  0,  0,  0,  0, 63, 27, 49, 62,  3, 12,  0,  0,  4, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 38: not used by a script */
    ATTR( 36,  2,  0,  0,  0,  0, 64, 27, 49, 62,  3, 12,  0,  0,  4, 34,  1,  0,  0,  7,  0, -2,118, 73),  /* 39: not used by a script */
    ATTR(106,  3,  0,  0,  0,  0, 64,  7, 49, 62,  2, 11,  2,  0, 28, 39,  4,  0,  0,  7, 10,-12,118, 73),  /* 40: ATTACK 1 SP: EX 214+PP (plain script) */
    ATTR(110,  2,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 30, 34,  5, 12,  0,  3, 16,-16,118, 73),  /* 41: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR(110,  2,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 32, 34,  6, 12,  0,  3, 17,-17,118, 73),  /* 42: ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR(110,  2,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 34, 34,  7, 12,  0,  3, 18,-18,118, 73),  /* 43: ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR(111,  3,  0,  0,  1,  0,  0,  9, 49, 63,  2, 14,  0,  0, 14, 39,  3, 12,  1,  3,  6, -6,  0, 73),  /* 44: CATCH 21 */
    ATTR(111,  3,  0,  0,  1,  0,  0, 14, 49, 63,  2, 14,  0,  0, 14, 39,  3, 12,  1,  3,  6, -6,  0, 73),  /* 45: CATCH 22 */
    ATTR(111,  3,  0,  0,  1,  0,  0, 16, 49, 63,  2, 14,  0,  0, 14, 39,  3, 12,  1,  3,  6, -6,  0, 73),  /* 46: CATCH 23 */
    ATTR( 91,  0,  0,  0,  0,  0, 70, 12, 49, 63,  0,  8,  4,  0, 36, 34,  7, 11,  0,  3, 10,-10,115,101),  /* 47: CATCH 17 */
    ATTR( 91,  0,  0,  0,  0,  0, 70, 12, 49, 63,  0,  8,  4,  0, 40, 34,  7, 11,  0,  3, 10,-10,116,101),  /* 48: not used by a script */
    ATTR( 91,  0,  0,  0,  0,  0, 70, 12, 49, 63,  0,  8,  4,  0, 44, 34,  7, 11,  0,  3, 10,-10,116,101),  /* 49: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1,  0, 25, 49, 56,  0, 12,  0,  0,  0, 34,  0,  4,  1,  3,  8, -8, 84,  0),  /* 50: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    ATTR( 32,  1,  0,  0,  0,  1,  0, 26, 49,  0,  0, 10,  0,  0,  0, 34,  0,  4,  1,  3,  8, -8, 66,  0),  /* 51: ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 4 M: 6(123)4+K medium (plain script), ATTACK 4 L: 6(123)4+K heavy/EX (plain script) */
    ATTR( 32,  1,  0,  0,  0,  1,  0, 26, 81,  0,  0, 10,  0,  0,  0, 34,  0,  0,  1,  3,  8, -8, 66,  0),  /* 52: ATTACK 6 S: SA I 720+P (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 30,  1, 54,  0, 10,  2,  0, 20, 39,  8,  7,  0,  3, 10,-10,117,  0),  /* 53: V JUMP P L B */
    ATTR( 91,  2,  0,  0,  0,  1, 70, 27, 81, 63,  0,  8,  0,  0, 36, 34,  3,  0,  0,  3, 10,-10,115, 73),  /* 54: CATCH 25 */
    ATTR(108,  0,  0,  0,  0,  0, 72, 20, 81, 63,  0,  8,  0,  0, 54, 34,  3,  0,  0,  3, 10,-10,129, 73),  /* 55: CATCH 25 */
    ATTR( 32,  0,  0,  0,  0,  1,  0, 25, 81,  0,  0, 12,  0,  0,  0, 34,  0,  0,  1,  3,  8, -8, 84,  0),  /* 56: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    ATTR( 91,  2,  0,  0,  0,  1,  0, 13, 81,  0,  0,  8,  0,  0, 14, 34,  5,  0,  0,  3, 10,-10,  0,106),  /* 57: CATCH 29 */
    ATTR(112,  0,  0,  0,  0,  0,  0, 21, 81,  0,  0,  8,  0,  0, 76, 34,  9,  0,  0,  3, 10,-10,130,  0),  /* 58: CATCH 29 */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 27, 81, 63,  1,  2,  0,  0, 16, 32,  3,  0,  0,  3, 10,-16,118, 73),  /* 59: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 27, 81, 63,  1, 14,  0,  0, 18, 32,  2,  0,  0,  3, 12,-16,118, 73),  /* 60: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  1,  0,  0,  1,  0,  0, 26, 81, 54,  1,  8,  0,  0, 16, 32,  2,  0,  0,  3, 15,-19,118, 73),  /* 61: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  1,  0,  0,  1,  0,  0, 26, 81, 54,  1,  2,  0,  0, 12,  0,  2,  0,  0,  3,  9,-19,118, 73),  /* 62: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR(106,  3,  0,  0,  1,  0,  0,  6, 81, 63,  1, 11,  4,  0, 24, 32,  3,  0,  0,  3, 14,-15,118, 73),  /* 63: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  0,  0,  0,  1,  0,  0, 25, 81, 63,  1, 13,  0,  0,  1, 32,  1,  1,  0,  7,  9, -9, 18, 73),  /* 64: ATTACK 9 M: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 29,  1, 54,  0, 11,  0,  0,  8, 32,  1, 15,  0,  3,  8, -8, 34, 73),  /* 65: ATTACK 10 S: not started by a command */
    ATTR(109,  1,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 28, 34,  6,  0,  0,  3, 22,-22,118, 73),  /* 66: ATTACK 2 SP: EX 236+KK (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1,  0,  0, 10,  0,  0,  0, 34,  0,  4,  1,  3,  8, -8, 70,  0),  /* 67: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    ATTR( 32,  0,  0,  0,  0,  0, 56,  2,  1,  9,  0, 14,  0,  0, 10, 32,  2,  1,  1,  3,  9, -9, 71, 53),  /* 68: no name */
    ATTR( 91,  2,  0,  1,  0,  0,  0, 31, 49, 63,  0, 12,  6,  0, 32, 32,  6, 11,  0,  3, 14,-14, 28, 73),  /* 69: CATCH 38, CATCH 39, CATCH 40 */
    ATTR(109,  1,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 32, 34,  7,  0,  0,  3, 22,-22,118, 73),  /* 70: ATTACK 2 SP: EX 236+KK (routine Att_PL06_HASHIRI_NAGE) */
    ATTR(109,  1,  0,  0,  0,  0,  0,  8, 49, 62,  2,  2,  6,  0, 36, 34,  8,  0,  0,  3, 22,-22,118, 73),  /* 71: ATTACK 2 SP: EX 236+KK (routine Att_PL06_HASHIRI_NAGE) */
};

extern const u16 hugo_se_random_0[];

const u16* const hugo_se_random_table[1] = {
    hugo_se_random_0,  /* 0 */
};

const u16 hugo_se_random_0[16] = {
    0x034C, 0x034D, 0x034C, 0x0355, 0x034C, 0x0355, 0x034C, 0x034C,
    0x0355, 0x0346, 0x0355, 0x034C, 0x0355, 0x034C, 0x0355, 0x0355,
};

