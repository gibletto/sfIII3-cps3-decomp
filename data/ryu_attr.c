/*
 * RYU_ATTR.C  Ryu's attack attributes and random sound lists
 *
 * ryu_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * ryu_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR ryu_catt_table[92] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 13,  2,  0, 10, 22,  3,  5,  0,  3,  7, -7, 14, 73),  /* 1: F JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 15,  2,  0, 10, 21,  3,  1,  0,  3,  9, -9, 18, 73),  /* 2: F JUMP P M A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 15,  0,  0,  6, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 3: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH B */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 22, 30,  3,  4,  0,  3,  9, -9, 18, 73),  /* 5: M PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 20, 18,  5,  4,  0,  3,  9, -9, 18, 73),  /* 6: M PUNCH B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 41,  1, 62,  0,  0,  6,  0, 26, 19,  7,  7,  0,  3, 11,-11, 23, 73),  /* 7: L PUNCH A, no name */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 41,  1, 63,  0,  1,  6,  0, 20, 19,  6,  6,  0,  3, 11,-11, 23, 73),  /* 8: L PUNCH A, no name */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 42,  1, 62,  0, 13,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 9: L PUNCH B */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 12,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: S KICK A */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 40,  1, 62,  0, 14,  0,  0, 12, 19,  1,  1,  0,  3, 11,-11, 39, 73),  /* 11: follow-up of L PUNCH B */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 14,  6,  0, 22, 17,  5,  4,  0,  3,  9, -9, 34, 73),  /* 12: M KICK A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 18, 18,  4,  4,  0,  3,  9, -9, 34, 73),  /* 13: M KICK B */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 14, 30,  3,  4,  0,  3,  9, -9, 23, 73),  /* 14: L PUNCH C */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 16, 30,  3,  4,  0,  3, 11,-11, 23, 73),  /* 15: L PUNCH C */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 16: not used by a script */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 40,  1, 62,  0, 13,  6,  0, 28, 19,  6,  7,  0,  3, 11,-11, 39, 73),  /* 17: L KICK A */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 18: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 63,  0, 12,  6,  0, 18, 17,  3,  4,  0,  3,  9, -9, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 15,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 43,  1, 63,  0,  0,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 45,  0, 13,  6,  0,  4, 16,  1,  1,  0,  3,  7,  7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 45,  0, 12,  6,  0, 16, 16,  1,  4,  0,  3,  9, -9, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 45,  0, 13,  6,  0, 26, 17,  1,  7,  0,  3, 11,-11, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0,  9,  2,  0, 12, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 20, 21,  5,  4,  0,  3,  8, -8, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 39,  1, 54,  0, 12,  2,  0, 28, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 12,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 39,  1, 54,  0, 13,  2,  0, 26, 21,  6,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 38,  1, 54,  0, 10,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 32: F JUMP P S A */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 33: not used by a script */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 17,  1, 54,  0, 11,  2,  0, 28, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 10, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 35: F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 13,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 39,  1, 54,  0, 12,  2,  0, 24, 21,  6,  7,  0,  3,  9, -9, 39, 73),  /* 37: F JUMP K L A, S V JP S P A */
    ATTR(100,  1,  0,  0,  0,  0,  0,  7, 49, 62,  3, 13,  6,  0, 26, 20,  7, 12,  0,  3, 12,-12, 40, 73),  /* 38: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 7 S: not started by a command */
    ATTR(100,  1,  0,  0,  0,  0,  0, 14, 49, 62,  3,  3,  6,  0, 26, 26,  7,  1,  0,  3, 10,-10, 40, 73),  /* 39: ATTACK 7 S: not started by a command */
    ATTR(100,  1,  0,  0,  0,  0,  0,  7, 49, 62,  3, 13,  6,  0, 30, 20,  7, 14,  0,  3, 12,-12, 40, 73),  /* 40: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 7 S: not started by a command */
    ATTR(100,  1,  0,  0,  0,  0,  0,  7, 49, 62,  3,  3,  6,  0, 30, 20,  7,  1,  0,  3, 10,-10, 40, 73),  /* 41: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    ATTR(100,  1,  0,  0,  0,  0,  0,  7, 49, 62,  3, 13,  6,  0, 34, 20,  7, 14,  0,  3, 12,-12, 40, 73),  /* 42: ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ATTR(100,  1,  0,  0,  0,  0,  0,  7, 49, 62,  3,  3,  6,  0, 34, 20,  7,  1,  0,  3, 10,-10, 40, 73),  /* 43: ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33, 49, 62,  3,  0,  0,  0, 10, 31,  1,  0,  0,  3,  3, -3, 40, 73),  /* 44: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33, 49, 62,  3,  0,  0,  0,  9, 31,  2,  0,  0,  3,  3, -3, 40, 73),  /* 45: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR( 94,  2,  0,  0,  1,  0,  0, 28, 49, 62,  3,  0,  2,  0,  7, 47,  1,  0,  0,  3,  6, -6, 40, 73),  /* 46: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  4,  1, 63,  0,  0,  0,  0, 24, 16,  4, 13,  0,  3,  8, -8,  0, 51),  /* 47: CATCH 1 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 36,  1,  0,  0, 10,  0,  0,  0, 18,  0,  0,  1,  3, 10,-10,  0,  0),  /* 48: TUKAMIKAKARI A */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  5,  1, 63,  0, 10,  0,  0, 22, 16,  7, 13,  0,  3,  8, -8,  0, 51),  /* 49: CATCH 5 */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 35,  1, 54,  0, 11,  0,  0,  8,  0,  4,  5,  0,  3, 10,-10, 18, 73),  /* 50: M PUNCH C */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 35,  1, 54,  0, 10,  0,  0, 12, 18,  3,  1,  0,  3, 10,-12, 18, 73),  /* 51: M PUNCH C */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 52: not used by a script */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2,  0,  4,  0, 28, 16,  6, 11,  0,  3, 14,-14, 28, 73),  /* 53: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 96,  2,  0,  1,  0,  0,  0,  2, 49, 63,  3,  0,  4,  0, 20, 16,  4, 11,  0,  3, 12,-12, 28, 73),  /* 54: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2,  0,  4,  0, 31, 17,  7, 11,  0,  3, 15,-15, 28, 73),  /* 55: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 96,  2,  0,  1,  0,  0,  0,  2, 49, 63,  3,  0,  4,  0, 24, 16,  4, 11,  0,  3, 12,-12, 28, 73),  /* 56: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 18, 49, 63,  2,  0,  6,  0, 34, 16,  8, 11,  0,  3, 16,-16, 28, 73),  /* 57: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    ATTR( 96,  2,  0,  1,  0,  0,  0, 18, 49, 63,  3,  0,  4,  0, 26, 16,  4, 11,  0,  3, 12,-12, 28, 73),  /* 58: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 18, 49, 63,  2,  0,  0,  0, 22, 19,  5,  0,  0,  3, 12,-12, 28, 73),  /* 59: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR( 96,  3,  0,  1,  0,  0,  0, 18, 49, 63,  3,  0,  2,  0, 16, 16,  1,  0,  0,  3, 12,-12, 28, 73),  /* 60: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 61: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 62: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 63: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 64: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 65: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 66: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 67: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 68: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 38,  1, 54,  0, 11,  0,  0,  8, 21,  1,  1,  0,  3,  8, -8, 18, 73),  /* 69: ATTACK 9 S: not started by a command */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 70: not used by a script */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  6, 49, 62,  2, 14,  2,  0, 24, 17,  8,  7,  0,  3, 12,-14, 44, 73),  /* 71: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  6, 49, 62,  2, 14,  2,  0, 28, 17,  8,  7,  0,  3, 12,-14, 44, 73),  /* 72: ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  6, 49, 62,  2, 14,  2,  0, 32, 17,  8,  7,  0,  3, 12,-14, 44, 73),  /* 73: ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  1,  0,  0,  1,  0, 65, 24, 80, 63,  1,  0,  7,  0, 12, 52,  2,  0,  0,  3,-60,-61, 65, 73),  /* 74: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ATTR( 96,  2,  0,  0,  1,  1, 66, 25, 81,  0,  1,  0,  7,  0, 40, 16,  2,  0,  0,  3, 52,-52, 65, 73),  /* 75: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ATTR( 95,  3,  0,  1,  1,  1, 67, 26, 81,  0,  2,  0,  7,  0, 40, 16,  2,  0,  0,  3,  5, -4, 97, 73),  /* 76: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ATTR(107,  3,  0,  1,  1,  0, 68, 27, 81,  0,  2,  0,  7,  0, 28, 19,  2,  0,  0,  3, 36,-36, 97, 52),  /* 77: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ATTR( 95,  2,  0,  1,  0,  0,  0,  9, 81, 63,  2, 15,  0,  0,  8, 16,  1,  0,  0,  3,  5, -5, 28, 73),  /* 78: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    ATTR(111,  2,  0,  0,  0,  0,  0, 31, 49, 62,  2, 14,  2,  0, 24, 17,  3,  0,  0,  3, 12,-14, 44, 73),  /* 79: ATTACK 10 SP: EX 4123+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 91,  1,  0,  1,  0,  0,  0, 22, 49, 62,  3, 13,  0,  0,  8, 20,  2,  0,  0,  3,  5, -5, 40, 73),  /* 80: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR( 91,  1,  0,  1,  0,  0,  0, 23, 49, 62,  3,  3,  0,  0,  8, 26,  1,  0,  0,  3,  5, -5, 40, 73),  /* 81: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 82: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 83: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 84: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 85: not used by a script */
    ATTR(100,  1,  0,  1,  0,  0,  0, 29, 49, 62,  3, 13,  6,  0, 20, 20,  4,  5,  0,  3,  6, -6, 40, 73),  /* 86: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 30, 49, 62,  3,  3,  6,  0, 20, 26,  4,  1,  0,  3,  6, -6, 40, 73),  /* 87: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 29, 49, 62,  3, 13,  6,  0, 22, 20,  4,  5,  0,  3,  6, -6, 40, 73),  /* 88: ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 30, 49, 62,  3,  3,  6,  0, 22, 26,  4,  1,  0,  3,  6, -6, 40, 73),  /* 89: ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 29, 49, 62,  3, 13,  6,  0, 24, 20,  4,  5,  0,  3,  6, -6, 40, 73),  /* 90: ATTACK 8 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 30, 49, 62,  3,  3,  6,  0, 24, 26,  4,  1,  0,  3,  6, -6, 40, 73),  /* 91: ATTACK 8 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
};

extern const u16 ryu_se_random_0[];

const u16* const ryu_se_random_table[1] = {
    ryu_se_random_0,  /* 0 */
};

const u16 ryu_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

