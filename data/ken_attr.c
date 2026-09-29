/*
 * KEN_ATTR.C  Ken's attack attributes and random sound lists
 *
 * ken_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * ken_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR ken_catt_table[119] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 29,  1, 54,  0,  8,  0,  0,  8, 16,  1,  1,  0,  3,  8, -8, 18, 73),  /* 1: ATTACK 9 M: not started by a command */
    ATTR( 35,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0,  0,  4,  0,  1, 48,  1,  1,  0,  3,  7, -7, 13, 73),  /* 2: ATTACK 10 M: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 15,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 3: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 13,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH B */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 62,  0, 12,  6,  0, 20, 30,  3,  4,  0,  3,  9, -9, 18, 73),  /* 5: M PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 26,  1, 62,  0, 12,  6,  0, 18, 18,  5,  4,  0,  3,  9, -9, 18, 73),  /* 6: M PUNCH B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0,  0,  6,  0, 26, 17,  7,  7,  0,  3, 11,-11, 23, 73),  /* 7: L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0,  0,  6,  0, 12, 19,  2,  1,  0,  3, 11,-11, 23, 73),  /* 8: follow-up of M PUNCH A */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0, 13,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 9: L PUNCH B */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 12,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: S KICK A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 38,  1, 54,  0,  9,  1,  0, 12, 16,  3,  5,  0,  3,  7, -7, 39, 73),  /* 11: M KICK C */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 38,  1, 54,  0,  8,  1,  0, 16, 18,  3,  1,  0,  3,  9, -9, 39, 73),  /* 12: M KICK C */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 37,  1, 62,  0, 14,  4,  0, 22, 16,  7,  4,  0,  3,  9, -9, 34, 73),  /* 13: M KICK A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 27,  1, 62,  0, 13,  6,  0, 30, 26,  5,  7,  0,  3, 11,-11, 39, 73),  /* 14: no name, L KICK A */
    ATTR( 37,  2,  1,  0,  0,  0,  0,  2, 49, 63,  2, 15,  2,  0, 16, 19,  5, 11,  0,  3,  8,-10, 28, 73),  /* 15: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    ATTR( 38,  2,  1,  0,  0,  0,  0,  2, 49, 63,  2,  0,  2,  0, 12, 19,  1,  1,  0,  3,  8,-10, 28, 73),  /* 16: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    ATTR( 95,  2,  1,  1,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0, 10, 19,  1,  1,  0,  3, 10,-10, 28, 73),  /* 17: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    ATTR( 95,  1,  1,  1,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0, 10, 19,  1,  1,  0,  3, 10,-10, 28, 73),  /* 18: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 63,  0, 13,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 63,  0, 12,  6,  0, 18, 17,  3,  4,  0,  3,  9, -9, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 21,  1, 63,  0, 15,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 33,  1, 63,  0,  0,  6,  0, 26, 17,  6,  7,  0,  3, 11,-11, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 25,  1, 45,  0, 13,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 26,  1, 45,  0, 12,  6,  0, 17, 16,  1,  4,  0,  3,  9, -9, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 45,  0, 13,  6,  0, 26, 17,  1,  7,  0,  3, 11,-11, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0,  9,  2,  0, 12, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 11,  2,  0, 20, 21,  5,  4,  0,  3,  8, -8, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 26, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 11,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 13,  2,  0, 26, 21,  6,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 10,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 12,  2,  0, 20, 22,  5,  4,  0,  3,  8, -8, 18, 73),  /* 33: F JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 11,  2,  0, 26, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 28,  1, 54,  0, 11,  2,  0, 10, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 35: F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 29,  1, 54,  0, 13,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 30,  1, 54,  0, 12,  2,  0, 25, 21,  6,  7,  0,  3,  9, -9, 39, 73),  /* 37: F JUMP K L A */
    ATTR( 38,  1,  0,  0,  1,  0,  0,  6, 49, 62,  2, 11,  2,  0, 12, 17,  3, 12,  0,  3,  5, -5, 44, 73),  /* 38: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 11,  2,  0,  6, 17,  1,  1,  0,  3,  5, -3, 44, 73),  /* 39: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 11,  6,  0,  6, 26,  1,  1,  0,  3,  5, -5, 44, 73),  /* 40: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 34,  1, 54,  0,  9,  1,  0, 24, 16,  5,  7,  0,  3, 11,-11, 39, 73),  /* 41: L KICK C, no name */
    ATTR( 36,  1,  0,  0,  0,  0,  0, 35,  1, 54,  0,  8,  1,  0, 16, 16,  4,  1,  0,  3, 11,-11, 39, 73),  /* 42: L KICK C, no name */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 36,  1, 62,  0, 12,  2,  0, 16, 16,  3,  7,  0,  3,  9, -9, 34, 73),  /* 43: M KICK B, no name */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 44: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 45: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 46: not used by a script */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  4,  1, 63,  0,  0,  0,  0, 24, 16,  4, 13,  0,  3,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  6,  1,  0,  0, 10,  0,  0,  0, 18,  0,  0,  1,  3, 10,-10,  0,  0),  /* 48: TUKAMIKAKARI A */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  5,  1, 63,  0, 10,  0,  0, 22, 16,  7, 13,  0,  3,  8, -8,  0, 51),  /* 49: CATCH 5, CATCH 22 */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2,  0,  2,  0, 30, 16,  5, 11,  0,  3, 14,-14, 28, 73),  /* 50: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0, 20, 16,  5, 11,  0,  3, 12,-12, 28, 73),  /* 51: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0, 12, 16,  5, 11,  0,  3, 10,-10, 28, 73),  /* 52: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 53: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 54: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0, 22,  6,  1,  9,  0, 14,  0,  0,  8, 16,  1,  1,  1,  3,  8, -8, 34, 73),  /* 55: CATCH 19, CATCH 20, CATCH 21 */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 56: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 57: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 58: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 59: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 60: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 61: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 62: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 63: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 64: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 65: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 66: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 67: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 68: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 69: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 70: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 71: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 72: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 73: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 74: not used by a script */
    ATTR( 38,  1,  0,  0,  1,  0,  0,  6, 49, 62,  2, 11,  2,  0, 16, 17,  3, 12,  0,  3,  4, -4, 44, 73),  /* 75: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2,  0,  2,  0, 22, 16,  5, 11,  0,  3, 12,-12, 28, 73),  /* 76: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2,  0,  2,  0, 11, 16,  2,  1,  0,  3, 12,-12, 28, 73),  /* 77: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0, 10, 16,  2,  1,  0,  3, 10,-10, 28, 73),  /* 78: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 79: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 80: not used by a script */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 11,  6,  0,  6, 26,  1,  1,  0,  3,  5, -5, 44, 73),  /* 81: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 11,  6,  0,  6, 27,  1,  1,  0,  3,  5, -5, 44, 73),  /* 82: ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 37,  2,  1,  0,  0,  0,  0,  2, 49, 63,  2, 15,  0,  0, 16, 19,  5,  0,  0,  3,  7, -8, 28, 73),  /* 83: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR( 38,  2,  1,  0,  0,  0,  0,  2, 49, 63,  2,  0,  0,  0, 10, 19,  1,  0,  0,  3,  7, -8, 28, 73),  /* 84: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR( 95,  2,  1,  1,  0,  0,  0,  2, 49, 63,  2,  0,  2,  0,  8, 19,  1,  0,  0,  3,  8, -8, 28, 73),  /* 85: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR( 95,  2,  1,  1,  0,  0,  0,  2, 49, 63,  3,  0,  2,  0,  8, 19,  1,  0,  0,  3, 10,-10, 28, 73),  /* 86: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    ATTR( 38,  1,  0,  0,  1,  0,  0,  6, 49, 62,  2, 15,  2,  0, 12, 17,  3,  0,  0,  3,  3, -3, 44, 73),  /* 87: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 13,  2,  0,  7, 16,  1,  0,  0,  3,  3, -2, 44, 73),  /* 88: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 31, 49, 62,  3, 12,  6,  0,  6, 26,  1,  0,  0,  3,  3, -3, 44, 73),  /* 89: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 22, 49, 62,  3, 13,  0,  0, 16, 16,  2,  0,  0,  3,  4, -6, 44, 73),  /* 90: ATTACK 7 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(100,  1,  0,  1,  0,  0,  0, 23, 49, 62,  3, 13,  0,  0, 16, 26,  2,  0,  0,  3,  4, -6, 44, 73),  /* 91: ATTACK 7 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 92: not used by a script */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 93: not used by a script */
    ATTR( 34,  2,  0,  1,  1,  0,  0, 32, 49, 62,  3, 11,  2,  0, 16, 16,  2, 14,  0,  3,  5, -3, 44, 73),  /* 94: ATTACK 7 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 7 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 7 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0, 32, 49, 62,  3, 11,  6,  0, 16, 26,  2,  1,  0,  3,  5, -5, 44, 73),  /* 95: ATTACK 7 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 7 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 7 L: air 214+K heavy (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 96: not used by a script */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 27, 81, 62,  2, 12,  7,  0, 16, 53,  3,  0,  0,  3,  6, -6, 44, 73),  /* 97: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  1,  0,  0,  1,  0,  0, 27, 81, 62,  2, 13,  7,  0,  8,  0,  1,  0,  0,  3,  4, -4, 44, 73),  /* 98: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 26, 81, 62,  2, 12,  7,  0, 10, 54,  1,  0,  0,  3,  5, -5, 44, 73),  /* 99: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 38,  2,  0,  0,  1,  0,  0, 26, 81, 62,  3, 14,  7,  0,  8, 54,  1,  0,  0,  3,  8, -8, 44, 73),  /* 100: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 15, 81, 62,  3, 13,  7,  0,  6, 54,  0,  0,  0,  3,  2, -4, 44, 73),  /* 101: ATTACK 8 S: not started by a command */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 15, 81, 62,  3,  3,  7,  0,  6, 54,  1,  0,  0,  3,  2, -4, 44, 73),  /* 102: ATTACK 8 S: not started by a command */
    ATTR( 96,  2,  0,  1,  1,  0,  0, 14, 81, 62,  3, 13,  6,  0, 10, 54,  1,  0,  0,  3,  6,-14, 44, 73),  /* 103: ATTACK 8 S: not started by a command */
    ATTR( 96,  2,  0,  1,  1,  0,  0, 14, 81, 62,  3,  3,  6,  0, 10, 54,  1,  0,  0,  3,  6,-14, 44, 73),  /* 104: ATTACK 8 S: not started by a command */
    ATTR( 91,  2,  0,  0,  1,  0,  0,  7, 81, 63,  1, 15,  7,  0, 17, 52,  0,  0,  0,  3,  4, -4, 28, 73),  /* 105: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  1,  0,  1,  1,  0,  0,  7, 81, 63,  2,  0,  7,  0, 13, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 106: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  1,  0,  1,  1,  0,  0,  8, 81, 63,  3,  0,  7,  0,  5, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 107: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  1,  0,  1,  1,  0,  0,  9, 81, 63,  3,  0,  7,  0, 13, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 108: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  2,  0,  0,  1,  0,  0, 10, 81, 63,  2, 12,  7,  0,  8, 16,  0,  0,  0,  3,  8, -8, 28, 73),  /* 109: not used by a script */
    ATTR( 38,  2,  0,  0,  1,  0,  0,  3, 81, 63,  2, 14,  7,  0, 16, 17,  0,  0,  0,  3,  6, -7, 28, 73),  /* 110: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  1,  0,  0,  3, 81, 63,  2, 15,  7,  0, 10, 17,  0,  0,  0,  3,  6, -7, 28, 73),  /* 111: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  1,  0,  0,  3, 81, 63,  2,  0,  7,  0, 12, 17,  0,  0,  0,  3,  2, -7, 28, 73),  /* 112: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 38,  2,  0,  0,  1,  0,  0,  3, 81, 63,  3, 14,  7,  0, 14, 17,  0,  0,  0,  3,  6, -7, 28, 73),  /* 113: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  1,  0,  0,  3, 81, 63,  3, 15,  7,  0,  8, 17,  0,  0,  0,  3,  6, -7, 28, 73),  /* 114: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  1,  0,  0,  3, 81, 63,  3,  0,  7,  0,  8, 17,  0,  0,  0,  3,  2, -7, 28, 73),  /* 115: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 91,  2,  1,  0,  1,  0,  0,  3, 81, 63,  3, 14,  7,  0,  8, 19,  0,  0,  0,  3,  5, -5, 28, 73),  /* 116: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  2,  1,  0,  1,  0,  0, 11, 81, 63,  3, 15,  7,  0,  8, 19,  2,  0,  0,  3,  5, -5, 28, 73),  /* 117: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 95,  3,  1,  1,  1,  0,  0, 11, 81, 63,  3,  0,  6,  0,  8, 19,  1,  0,  0,  3,  5, -5, 28, 73),  /* 118: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
};

extern const u16 ken_se_random_0[];

const u16* const ken_se_random_table[1] = {
    ken_se_random_0,  /* 0 */
};

const u16 ken_se_random_0[16] = {
    0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194,
    0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194, 0x0194,
};

