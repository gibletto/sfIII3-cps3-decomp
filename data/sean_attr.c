/*
 * SEAN_ATTR.C  Sean's attack attributes and random sound lists
 *
 * sean_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * sean_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR sean_catt_table[106] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 25, 49, 63,  1, 15,  6,  0, 20, 16,  5,  4,  0,  3,  8, -8, 28, 73),  /* 1: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 25, 49, 63,  2, 15,  6,  0, 16, 16,  4,  8,  0,  3,  8, -8, 28, 73),  /* 2: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 13,  6,  0,  4, 16,  2,  1,  0,  3,  7, -7, 13, 72),  /* 3: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 62,  0, 12,  2,  0, 18, 30,  4,  4,  0,  3,  9, -9, 18, 73),  /* 5: M PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 26,  1, 62,  0, 12,  6,  0, 16, 18,  5,  4,  0,  3,  9, -9, 18, 73),  /* 6: M PUNCH B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 33,  1, 62,  0, 15,  6,  0, 24, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 7: L PUNCH A, L PUNCH C, follow-up of L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0, 14,  6,  0, 10, 19,  1,  1,  0,  3, 12,-12, 23, 73),  /* 8: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 24,  1, 62,  0, 14,  0,  0, 10, 19,  1,  1,  0,  3, 12,-12, 23, 73),  /* 9: follow-up of M PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 10,  6,  0,  6, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 13,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 11: not used by a script */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 26,  1, 63,  0, 13,  6,  0, 18, 18,  2,  4,  0,  3,  9,-12, 34, 73),  /* 12: M KICK A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0, 12,  6,  0, 29, 18,  5,  7,  0,  3, 11,-11, 39, 73),  /* 13: L KICK A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 27,  1, 63,  0, 14,  0,  0, 36, 19,  6,  7,  0,  3, 11,-11, 39, 73),  /* 14: not used by a script */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 27,  1, 63,  0, 14,  0,  0,  4, 19,  6,  7,  0,  3, 11,-11, 39, 73),  /* 15: not used by a script */
    ATTR( 64,  2,  0,  0,  0,  0,  0, 27,  1, 63,  0, 10,  0,  0,  4, 19,  6,  7,  0,  3, 11,-11, 39, 73),  /* 16: not used by a script */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 32,  1, 62,  0, 14,  6,  0, 28, 19,  8,  7,  0,  3, 11,-11, 39, 73),  /* 17: not used by a script */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 27,  1, 63,  0, 12,  6,  0, 40, 20,  7,  7,  0,  3, 12,-12, 39, 73),  /* 18: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 63,  0, 12,  6,  0, 16, 18,  3,  4,  0,  3,  9, -9, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 33,  1, 63,  0, 15,  6,  0, 24, 19,  6,  7,  0,  3, 11, -8, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 34,  1, 63,  0, 15,  6,  0, 24, 19,  6,  7,  0,  3, 11, -8, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 45,  0, 13,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1,  9,  0, 12,  6,  0, 14, 16,  1,  4,  0,  3,  9, -9, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1,  9,  0, 12,  6,  0, 24, 17,  1,  7,  0,  3, 12,-10, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 12,  2,  0,  8, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 18, 22,  5,  4,  0,  3,  8, -8, 23, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 26, 23,  7,  7,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 12,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 18, 22,  4,  4,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 26, 23,  6,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0,  8,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 10,  2,  0, 18, 22,  4,  4,  0,  3,  8, -8, 18, 73),  /* 33: F JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 26, 23,  6,  7,  0,  3,  9, -9, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 12,  2,  0, 10, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 35: F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 22, 22,  6,  7,  0,  3,  9, -9, 39, 73),  /* 37: F JUMP K L A */
    ATTR( 35,  2,  0,  0,  1,  0,  0,  6, 81, 63,  1, 14,  7,  0, 32, 20,  4,  4,  0,  3,  6,-16, 44, 73),  /* 38: not used by a script */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 25, 81, 63,  1, 13,  7,  0, 24, 20,  3,  5,  0,  3,  8,-16, 44, 73),  /* 39: not used by a script */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 25, 81, 63,  1, 14,  7,  0, 24, 20,  3,  5,  0,  3,  8,-16, 44, 73),  /* 40: not used by a script */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  3, 81, 63,  1, 15,  7,  0, 16, 20,  0,  0,  0,  3,  6, -6, 28, 73),  /* 41: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3, 81, 63,  2,  0,  7,  0, 10, 16,  0,  0,  0,  3,  6,-24, 28, 73),  /* 42: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3, 81, 63,  3,  0,  7,  0,  7, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 43: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  3, 81, 63,  3,  0,  7,  0,  4, 16,  0,  0,  0,  3,  4, -8, 28, 73),  /* 44: not used by a script */
    ATTR( 94,  2,  0,  0,  0,  0,  0, 14, 81, 63,  3, 15,  7,  0,  4, 16,  0,  0,  0,  3,  6,-12, 28, 73),  /* 45: not used by a script */
    ATTR( 95,  2,  0,  1,  0,  0,  0, 23, 81, 63,  3,  0,  7,  0,  8, 16,  0,  0,  0,  3,  2, -2, 28, 73),  /* 46: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  4,  1, 63,  2,  0,  0,  0, 24, 16,  5, 13,  0,  3,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 27,  1,  0,  0, 14,  0,  0,  0, 34,  0,  0,  1,  3, 10,-10,  0,  0),  /* 48: TUKAMIKAKARI A */
    ATTR( 32,  2,  0,  1,  0,  0,  0,  8,  1, 54,  2, 10,  0,  0, 24, 19,  9, 11,  0,  3, 12,-12, 44, 73),  /* 49: not used by a script */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 13,  1, 54,  2, 10,  2,  0, 24, 26,  9, 11,  0,  3, 12,-12, 44, 73),  /* 50: not used by a script */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  5,  1, 63,  0, 10,  0,  0, 28, 16,  2, 13,  0,  3,  8, -8,  0, 51),  /* 51: CATCH 5 */
    ATTR( 37,  2,  0,  0,  0,  1, 21, 27, 49, 45,  0, 10,  0,  0,  0, 17,  0,  0,  1,  3, 10,-10, 84, 60),  /* 52: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  2,  0,  0,  0,  1, 19, 27, 49, 36,  0, 10,  0,  0, 20, 20,  5,  4,  1,  3,  8, -8, 28, 50),  /* 53: CATCH 10 */
    ATTR( 37,  2,  0,  0,  0,  0, 19, 27, 49, 36,  0, 10,  0,  0, 16, 20,  3,  2,  1,  3,  8, -8, 28, 50),  /* 54: CATCH 10 */
    ATTR( 37,  0,  0,  0,  0,  0, 20,  6,  1,  9,  0, 10,  0,  0,  8, 16,  2,  1,  1,  3,  8, -8, 39, 73),  /* 55: CATCH 9 */
    ATTR( 32,  2,  0,  0,  1,  0,  0, 12, 49, 62,  2, 13,  4,  0, 10, 16,  2, 12,  0,  3,  7, -7, 39, 73),  /* 56: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0, 10, 16,  2,  1,  0,  3,  7, -7, 44, 73),  /* 57: ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0, 10, 16,  2,  1,  0,  3,  7, -7, 44, 73),  /* 58: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 12, 49, 62,  2, 14,  4,  0, 10, 16,  2, 12,  0,  3,  7, -7, 44, 73),  /* 59: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 91,  2,  0,  0,  1,  0,  0,  6, 81, 63,  0, 14,  7,  0, 12, 54,  0,  0,  0,  3,  6, -2, 44, 73),  /* 60: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  3,  0,  1,  1,  0,  0, 11, 81, 63,  2, 13,  7,  0, 12, 54,  0,  0,  0,  3,  3, -2, 44, 73),  /* 61: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  3,  0,  1,  1,  0,  0, 11, 81, 63,  3, 14,  7,  0, 12, 54,  0,  0,  0,  3,  3, -2, 44, 73),  /* 62: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 63,  0, 12,  0,  0, 24, 17,  5,  0,  0,  3,  8, -8, 18,  0),  /* 63: not used by a script */
    ATTR( 32,  2,  0,  0,  1,  0,  0, 27, 81, 63,  2,  8,  2,  0,  4, 54,  0,  0,  0,  3,  6,-12, 28, 73),  /* 64: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0, 27, 81, 63,  0, 14,  2,  0,  4, 52,  0,  0,  0,  3,  6,-16, 28, 73),  /* 65: not used by a script */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 27, 81, 63,  0, 14,  2,  0,  4, 52,  0,  0,  0,  3,  6,-16, 28, 73),  /* 66: not used by a script */
    ATTR( 32,  2,  0,  1,  1,  0,  0,  8, 81, 54,  3, 10,  0,  0, 12, 19,  9,  0,  0,  3,  5,-12, 44, 73),  /* 67: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 97,  2,  0,  1,  0,  0,  0, 13, 81, 54,  3,  8,  0,  0, 20, 20,  1,  0,  0,  3, 12, -8, 44, 73),  /* 68: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 11,  2,  0, 24, 16,  5,  4,  0,  3,  1, -1, 23, 73),  /* 69: L PUNCH B */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 36,  1, 62,  0,  9,  2,  0, 20, 16,  5,  4,  0,  3,  1, -1, 23, 73),  /* 70: L PUNCH B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 27, 81, 63,  0, 15,  0,  0, 12, 54,  1,  0,  0,  3,  6, -6, 28, 73),  /* 71: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27, 81, 63,  0, 15,  0,  0, 12, 54,  1,  0,  0,  3,  6, -6, 28, 73),  /* 72: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  2,  0,  0,  1,  0,  0, 27, 81, 63,  0,  8,  2,  0,  8, 54,  0,  0,  0,  3, 12,-18,  0, 73),  /* 73: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  2,  0,  0,  0,  0,  0, 16, 49, 63,  2, 15,  2,  0, 26, 16,  5,  4,  0,  3, 12,-12, 28, 73),  /* 74: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 95,  2,  0,  1,  0,  0,  0, 17, 49, 63,  2,  0,  2,  0, 18, 16,  3,  4,  0,  3, 10,-10, 28, 73),  /* 75: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 96,  2,  0,  1,  0,  0,  0, 18, 49, 63,  2,  0,  2,  0, 16, 16,  3,  4,  0,  3, 10,-10, 28, 73),  /* 76: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 29,  1, 54,  0,  8,  0,  0,  8, 16,  1,  1,  0,  3,  8, -8, 18, 73),  /* 77: ATTACK 10 S: not started by a command */
    ATTR( 88,  3,  0,  1,  0,  0,  0, 37,  1, 62,  0, 13,  2,  0, 18, 20,  4,  4,  0,  3, 11,-11, 39, 73),  /* 78: L KICK C */
    ATTR( 88,  2,  0,  1,  0,  0,  0, 37,  1, 62,  0, 13,  2,  0, 14, 20,  4,  4,  0,  3, 11,-11, 39, 73),  /* 79: L KICK C */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 19,  1, 63,  0, 15,  6,  0, 22, 18,  1,  4,  0,  3, 10,-10, 23, 73),  /* 80: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  0, 21, 27, 49, 63,  0, 10,  0,  0, 28, 17,  0,  4,  1,  3, 10,-10, 28, 45),  /* 81: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 38,  1, 62,  0, 14,  2,  0, 24, 20,  5,  4,  0,  3, 11,-11, 39, 73),  /* 82: L KICK B */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 38,  1, 62,  0, 14,  2,  0, 20, 20,  4,  4,  0,  3, 11,-11, 39, 73),  /* 83: L KICK B */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0,  8, 16,  2,  1,  0,  3,  7, -7, 44, 73),  /* 84: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0,  8, 16,  2,  1,  0,  3,  7, -7, 44, 73),  /* 85: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 26,  1, 54,  0, 11,  2,  0, 12, 17,  3,  8,  0,  3,  8, -8, 23, 73),  /* 86: L PUNCH C */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 54,  0, 11,  2,  0, 16, 17,  3,  1,  0,  3, 10,-10, 23, 73),  /* 87: L PUNCH C */
    ATTR( 37,  2,  0,  0,  0,  1, 21, 27, 49, 45,  0, 10,  0,  0,  0, 19,  0,  0,  1,  3, 10,-10, 84, 60),  /* 88: ATTACK 1 SP: EX 4(123)6+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  2,  0,  0,  0,  1, 19, 27, 49, 36,  0, 10,  0,  0,  8, 20,  3,  0,  1,  3,  8, -8, 28, 50),  /* 89: CATCH 19 */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 12, 49, 62,  2, 14,  4,  0, 12, 16,  4,  0,  0,  3,  7, -7, 39, 73),  /* 90: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0,  8, 16,  2,  0,  0,  3,  7, -7, 44, 73),  /* 91: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 49, 62,  3, 13,  1,  0,  8, 16,  2,  0,  0,  3,  7, -7, 44, 73),  /* 92: ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 19, 33, 54,  3, 13,  0,  0, 12, 19,  3,  0,  0,  3, 10,-10, 44, 73),  /* 93: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 20, 33, 54,  3, 11,  0,  0, 14, 19,  3,  0,  0,  3, 10,-10, 44, 73),  /* 94: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0, 19, 27, 49, 36,  0, 10,  0,  0, 20, 20,  3,  0,  1,  3,  8, -8, 28, 50),  /* 95: CATCH 19 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27, 81, 63,  0, 15,  0,  0, 12, 54,  1,  0,  0,  3,  6, -6, 28, 73),  /* 96: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 26,  1, 54,  0, 11,  2,  0, 10, 17,  2,  5,  0,  3,  8, -8, 23, 73),  /* 97: follow-up of L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 54,  0, 11,  2,  0, 12, 17,  1,  1,  0,  3, 10,-10, 23, 73),  /* 98: follow-up of L PUNCH A */
    ATTR( 36,  2,  0,  1,  0,  0,  0, 21, 33, 54,  2,  9,  0,  0, 14, 19,  3,  0,  0,  3, 10,-10, 44, 73),  /* 99: ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 19, 33, 54,  2, 13,  0,  0, 24, 19,  9, 11,  0,  3, 12,-12, 44, 73),  /* 100: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 20, 33, 54,  2, 11,  0,  0, 24, 19,  9, 11,  0,  3, 12,-12, 44, 73),  /* 101: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    ATTR( 36,  2,  0,  1,  0,  0,  0, 21, 33, 54,  2,  9,  0,  0, 24, 19,  9, 11,  0,  3, 12,-12, 44, 73),  /* 102: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI) */
    ATTR( 95,  2,  0,  0,  0,  0,  0, 16, 49, 63,  2, 15,  2,  0, 18, 16,  5,  0,  0,  3,  9, -9, 28, 73),  /* 103: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    ATTR( 96,  2,  0,  1,  0,  0,  0, 18, 49, 63,  3,  0,  2,  0, 18, 16,  3,  0,  0,  3, 11,-11, 28, 73),  /* 104: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    ATTR( 95,  2,  0,  1,  0,  0,  0, 18, 49, 63,  3,  0,  2,  0, 12, 16,  3,  0,  0,  3,  9, -9, 28, 73),  /* 105: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
};

extern const u16 sean_se_random_0[];

const u16* const sean_se_random_table[1] = {
    sean_se_random_0,  /* 0 */
};

const u16 sean_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

