/*
 * YUN_ATTR.C  Yun's attack attributes and random sound lists
 *
 * yun_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * yun_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR yun_catt_table[174] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 18,  1, 62,  0, 15,  6,  0, 16,  2,  4,  4,  0,  3,  6, -6, 34, 73),  /* 1: M KICK B */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 18,  1, 62,  0, 15,  2,  0, 16,  2,  4,  4,  0,  3,  6, -6, 34, 73),  /* 2: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE +1 */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  0,  0,  8,  0,  3,  1,  0,  3,  8, -8, 13, 72),  /* 3: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  0,  0, 16,  0,  5,  4,  0,  3, 10,-10, 18, 73),  /* 4: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 35,  1, 63,  0, 13,  0,  0, 24,  0,  4,  7,  0,  3, 10,-10, 23, 73),  /* 5: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 6: S PUNCH A, S PUNCH B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34,  1, 62,  0, 14,  6,  0, 10,  3,  2,  4,  0,  3,  9, -9, 18, 73),  /* 7: M PUNCH B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34,  1, 62,  0, 12,  6,  0, 12,  1,  2,  4,  0,  3,  9, -9, 18, 73),  /* 8: M PUNCH A */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 14,  6,  0,  8,  3,  3,  8,  0,  3, 11,-11, 23, 73),  /* 9: L PUNCH A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 13,  1, 62,  0, 13,  4,  0, 26,  4,  7,  7,  0,  3, 11,-11, 23, 73),  /* 10: L PUNCH B */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 14,  1, 62,  0, 12,  0,  0, 10, 62,  2,  1,  0,  3, 12,-12, 23, 73),  /* 11: follow-up of M PUNCH A, M PUNCH B */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  6,  0,  7,  0,  1,  1,  0,  3,  7, -7, 29, 72),  /* 12: S KICK A, follow-up of S PUNCH A, S PUNCH B */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  6,  0,  1,  0,  0, 15,  0,  3,  7, -7, 13, 72),  /* 13: not started by a command */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 13,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 14: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 33,  1, 45,  0, 11,  6,  0,  6,  0,  1,  1,  0,  3,  7, -7, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  0,  0, 16,  0,  5,  4,  0,  3,  8, -8, 23, 73),  /* 16: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 33,  1, 63,  0, 14,  0,  0, 32,  3,  4,  7,  0,  3, 10,-10, 39, 73),  /* 17: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34,  1, 54,  0, 11,  6,  0, 16,  3,  5,  4,  0,  3, 10,-10, 39, 73),  /* 18: M KICK C */
    ATTR( 40,  2,  0,  0,  0,  0,  0,  3,  1, 54,  0, 10,  6,  0, 36,  3,  4,  7,  0,  3, 11,-11, 39, 73),  /* 19: not used by a script */
    ATTR( 93,  2,  0,  0,  1,  0,  0,  4, 49, 62,  2, 13,  4,  0, 20,  4,  4, 12,  0,  3,  6, -6, 28, 73),  /* 20: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0,  4, 49, 62,  2, 12,  4,  0, 20,  4,  2, 12,  0,  3,  6, -6, 28, 73),  /* 21: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) */
    ATTR(106,  0,  0,  0,  0,  0, 31,  5, 49, 62,  2, 11,  0,  0, 36,  3, 11, 10,  0,  7, 10,-12, 87, 73),  /* 22: ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    ATTR(106,  0,  0,  0,  0,  0,  0,  5, 49, 62,  2, 12,  0,  0, 28,  3,  8, 10,  0,  7,  6, -8, 23, 73),  /* 23: ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    ATTR( 34,  2,  0,  0,  0,  0,  0,  6, 81, 63,  1, 13,  7,  0, 16,  3,  1,  0,  0,  3,  6, -6, 39, 73),  /* 24: ATTACK 5 S: not started by a command */
    ATTR( 34,  2,  0,  0,  0,  0,  0,  6, 81, 63,  1, 14,  7,  0, 16,  3,  1,  0,  0,  3,  6, -6, 39, 73),  /* 25: ATTACK 5 S: not started by a command */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  7, 81, 63,  1, 15,  7,  0, 20,  3,  1,  0,  0,  3, 12,-12, 44, 73),  /* 26: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  7, 81, 63,  1, 14,  6,  0, 20,  3,  1,  0,  0,  3, 10,-10, 44, 73),  /* 27: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  0,  0, 16,  3,  3, 11,  0,  3,  8, -8, 44, 73),  /* 28: not used by a script */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1,  0,  0,  0, 12,  3,  2,  1,  0,  3, 10,-10, 44, 73),  /* 29: not used by a script */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  9, 49, 63,  1,  0,  0,  0, 10,  3,  2,  1,  0,  3, 10,-10, 40, 73),  /* 30: not used by a script */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  2,  0,  8,  5,  3,  1,  0,  3,  7, -7, 13, 72),  /* 31: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 16,  6,  5,  4,  0,  3,  8, -8, 18, 73),  /* 32: V JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 24,  7,  7,  7,  0,  3,  9, -9, 23, 73),  /* 33: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 13,  2,  0,  8,  5,  2,  1,  0,  3,  7, -7, 29, 72),  /* 34: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 13,  2,  0, 14,  6,  4,  4,  0,  3,  8, -8, 34, 73),  /* 35: not used by a script */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 13,  2,  0, 22,  7,  6,  7,  0,  3,  9, -9, 39, 73),  /* 36: V JUMP K L A, F JUMP K L A */
    ATTR( 32,  1,  0,  0,  1,  0,  0, 10, 81, 62,  2, 10,  0,  0, 14,  0,  1,  0,  0,  3,  1, -8, 23, 73),  /* 37: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 32,  0,  0,  0,  1,  0,  0, 10, 81, 62,  2, 12,  0,  0, 14,  0,  0,  0,  0,  3,  1, -8, 23, 73),  /* 38: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 37,  1,  0,  0,  1,  0,  0, 10, 81, 62,  2, 12,  0,  0, 10,  0,  2,  0,  0,  3,  1, -8, 23, 73),  /* 39: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 32,  2,  0,  0,  1,  0,  0, 31, 81, 62,  2, 13,  0,  0, 10,  5,  0,  0,  0,  3,  1, -8, 24, 73),  /* 40: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 35,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0,  0,  2,  0, 12,  3,  3,  1,  0,  3, 11,-11, 23, 73),  /* 41: L PUNCH A */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 21,  1, 62,  0, 10,  0,  0, 20,  2,  5,  7,  0,  3,  8, -8, 39, 73),  /* 42: L KICK A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 33, 49,  0,  0, 12,  0,  0,  0, 18,  0,  0,  2,  3, 10,-14,  0,  0),  /* 43: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    ATTR( 96,  0,  0,  0,  0,  0, 28, 17,  1, 63,  0, 14,  6,  0,  8, 16,  2,  1,  0,  3,  8, -8, 39, 73),  /* 44: CATCH 4, CATCH 7, CATCH 8 +1 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 34,  1, 63,  0, 12,  0,  0, 14,  0,  2,  4,  0,  3,  9, -9, 18, 73),  /* 45: KAGAMI P A */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 35,  1, 63,  0, 13,  6,  0,  6,  0,  1,  8,  0,  3, -6, -6, 18, 73),  /* 46: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 35,  1, 63,  0, 13,  6,  0, 16,  0,  2,  1,  0,  3,  9, -9, 23, 73),  /* 47: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 34,  1, 45,  0, 12,  0,  0, 10,  0,  1,  4,  0,  3,  9, -9, 34, 73),  /* 48: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  2,  1, 45,  0,  0,  0,  0, 18,  2,  1,  7,  0,  3,  4, -4, 35, 73),  /* 49: not used by a script */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 45,  0, 13,  0,  0, 18,  2,  1,  7,  0,  3,  4, -4, 39, 73),  /* 50: KAGAMI K A */
    ATTR( 89,  1,  0,  0,  0,  0,  0,  2,  1, 45,  0, 11,  0,  0, 18,  2,  1,  7,  0,  3,  4, -4, 35, 73),  /* 51: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 33,  1, 63,  0,  3,  0,  0,  0, 48,  0,  0,  0,  3,  8, -8,  0,  0),  /* 52: CATCH 1, CATCH 5 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 34, 81, 63,  1, 12,  0,  0, 16, 53,  2,  0,  0,  3,  8,-10, 39, 73),  /* 53: not used by a script */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  8, 81, 63,  3, 14,  7,  0,  4, 48,  1,  0,  0,  3,  2, -2, 44, 73),  /* 54: ATTACK 13 SP: not started by a command */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  8, 81, 63,  3, 15,  7,  0,  6,  3,  0,  0,  0,  3,  2, -2, 44, 73),  /* 55: ATTACK 13 SP: not started by a command */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  9, 81, 63,  3, 15,  7,  0,  6,  3,  0,  0,  0,  3, 16,-16, 44, 73),  /* 56: ATTACK 13 SP: not started by a command */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  0,  0, 16,  3,  4, 11,  0,  3,  8, -8, 44, 73),  /* 57: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1,  0,  0,  0, 14,  3,  3,  1,  0,  3, 10,-10, 44, 73),  /* 58: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  9, 49, 63,  1,  0,  0,  0, 12,  3,  3,  1,  0,  3, 10,-10, 44, 73),  /* 59: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  0,  0, 16,  3,  5, 11,  0,  3,  8, -8, 44, 73),  /* 60: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1,  0,  0,  0, 16,  3,  4,  1,  0,  3, 10,-10, 44, 73),  /* 61: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  9, 49, 63,  1,  0,  0,  0, 14,  3,  4,  1,  0,  3, 10,-10, 44, 73),  /* 62: ATTACK 2 SP: EX 214+PP (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 35,  1,  0,  0, 10,  0,  0,  0,  2,  0,  0,  1,  3, 10,-10, 70, 73),  /* 63: TUKAMIKAKARI A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 35,  1,  0,  0,  2,  0,  0,  0,  2,  0,  0,  2,  3, 10,-10, 70, 51),  /* 64: TUKAMIKAKARI C */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  2,  0,  8,  5,  3,  1,  0,  3,  9, -9, 13, 72),  /* 65: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 16,  6,  4,  4,  0,  3,  8, -8, 18, 73),  /* 66: F JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 20,  7,  6,  7,  0,  3,  9, -9, 23, 73),  /* 67: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 13,  2,  0,  8,  5,  2,  1,  0,  3,  7, -7, 29, 72),  /* 68: F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 13,  2,  0, 14,  6,  4,  4,  0,  3,  8, -8, 34, 73),  /* 69: V JUMP K M A, F JUMP K M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 13,  2,  0, 18,  7,  6,  7,  0,  3,  9, -9, 39, 73),  /* 70: not used by a script */
    ATTR( 36,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0,  9,  6,  0, 14,  3,  3,  4,  0,  3,  8, -8, 34, 73),  /* 71: F JUMP K S B, F JUMP K M B, F JUMP K L B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33, 81, 54,  3, 13,  0,  0, 24,  7,  1,  0,  0,  3, 12,-12, 39, 73),  /* 72: ATTACK 5 S: not started by a command */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  2,  0, 18,  7,  3,  1,  0,  3, 11,-11, 23, 73),  /* 73: follow-up of V JUMP P S A, F JUMP P S A */
    ATTR( 95,  2,  0,  1,  0,  0,  0,  7,  1, 54,  0, 13,  0,  0,  8,  5,  1,  0,  0,  3,  8, -8, 40, 73),  /* 74: not used by a script */
    ATTR( 95,  2,  0,  1,  0,  0,  0,  7,  1, 54,  0, 13,  0,  0, 12,  6,  1,  0,  0,  3,  8, -8, 40, 73),  /* 75: ATTACK 13 SP: not started by a command */
    ATTR( 93,  2,  0,  0,  0,  0, 31,  5,  1, 62,  0, 11,  0,  0, 12,  3,  3,  1,  0,  7, 12,-14, 87, 73),  /* 76: follow-up of follow-up of M PUNCH A, M PUNCH B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 34,  1, 62,  0,  0,  2,  0, 10,  2,  2,  1,  0,  3,  6, -6, 34, 73),  /* 77: follow-up of S KICK A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 10,  0,  0, 12, 20,  4,  8,  0,  3,  8, -8, 39, 73),  /* 78: follow-up of follow-up of S KICK A */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 15, 81, 63,  0, 14,  7,  0,  8,  2,  0,  0,  0,  3,  4, -8, 39, 73),  /* 79: not used by a script */
    ATTR(106,  2,  0,  0,  0,  0, 31,  5, 81, 62,  2, 11,  0,  0, 24,  3,  0,  0,  0,  7, 12,-14, 87, 73),  /* 80: ATTACK 11 M: not started by a command */
    ATTR( 96,  3,  0,  0,  0,  0,  0,  8, 81, 63,  1, 15,  7,  0,  8,  3,  0,  0,  0,  3,  4, -5, 44, 73),  /* 81: not used by a script */
    ATTR(100,  2,  0,  0,  1,  0,  0, 29, 81, 62,  2, 13,  0,  0,  8,  3,  1,  0,  0,  3,  4, -4, 40, 73),  /* 82: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 94,  2,  0,  0,  1,  0,  0, 30, 81, 62,  2, 12,  0,  0, 20,  3,  1,  0,  0,  3, 14,-14, 40, 73),  /* 83: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  0,  0,  8,  0,  1,  5,  0,  3,  8, -8, 29, 72),  /* 84: not used by a script */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1, 81, 45,  0, 13,  0,  0, 12,  3,  0,  0,  0,  3,  4, -4, 44, 73),  /* 85: not used by a script */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 33, 81, 45,  0, 12,  0,  0,  8,  1,  0,  0,  0,  3,  4, -8, 39, 73),  /* 86: not used by a script */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 19, 49, 62,  2, 13,  4,  0, 22,  4,  4, 12,  0,  3,  6, -6, 28, 73),  /* 87: ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 19, 49, 62,  2, 12,  4,  0, 22,  4,  2, 12,  0,  3,  6, -6, 28, 73),  /* 88: ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 20, 49, 62,  2, 13,  4,  0, 24,  4,  4, 12,  0,  3,  6, -6, 28, 73),  /* 89: ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 20, 49, 62,  2, 12,  4,  0, 24,  4,  2, 12,  0,  3,  6, -6, 28, 73),  /* 90: ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 35,  1, 63,  0, 10,  0,  0, 24,  4,  0,  0,  0,  3,  8, -8, 39, 73),  /* 91: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16,  1, 63,  0,  2,  0,  0, 24,  0,  4, 13,  0,  3,  8, -8,  0, 51),  /* 92: CATCH 2, CATCH 3, CATCH 6 */
    ATTR( 37,  1,  0,  0,  1,  0,  0, 34, 49, 63,  3, 12,  0,  0, 16, 54,  1, 11,  0,  3,  8,-12, 44, 73),  /* 93: not used by a script */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  6,  0, 16,  6,  5,  4,  0,  3,  8, -8, 18, 73),  /* 94: not used by a script */
    ATTR( 95,  2,  0,  0,  0,  0,  0, 21,  1, 63,  0, 15,  6,  0, 20,  2,  4,  1,  0,  3, 10,-10, 39, 73),  /* 95: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 34, 81, 63,  0, 14,  7,  0,  8,  2,  0,  0,  0,  3,  1, -2, 18, 73),  /* 96: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 33, 81, 62,  0, 15,  7,  0,  6,  1,  0,  0,  0,  3, -6, -6, 28, 73),  /* 97: ATTACK 12 M: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 33, 81, 62,  1, 15,  7,  0,  8,  1,  0,  0,  0,  3, -6, -6, 28, 73),  /* 98: ATTACK 12 M: not started by a command */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33, 81, 63,  0, 14,  7,  0,  4,  0,  0,  0,  0,  3,  4, -6, 28, 73),  /* 99: follow-up of ZANNEN 2, follow-up of ZANNEN 3 */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34, 81, 62,  0, 14,  7,  0,  8,  5,  0,  0,  0,  3,  4, -4, 28, 73),  /* 100: follow-up of ZANNEN 4 */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34, 81, 62,  0, 15,  7,  0,  8,  1,  0,  0,  0,  3, -6, -6, 28, 73),  /* 101: no name */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 35, 81, 62,  0, 15,  7,  0,  8,  1,  0,  0,  0,  3, -8, -8, 28, 73),  /* 102: follow-up of JUDGMENT WAIT */
    ATTR( 35,  1,  0,  0,  0,  0,  0, 35, 81, 62,  0, 15,  7,  0,  8,  1,  0,  0,  0,  3, -8, -8, 28, 73),  /* 103: follow-up of JUDGMENT WAIT */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 35, 81, 62,  0, 15,  7,  0, 12,  1,  0,  0,  0,  3, -6, -8, 28, 73),  /* 104: follow-up of ZANNEN 6 */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33, 81, 63,  0, 14,  7,  0,  6,  0,  0,  0,  0,  3,  4, -6, 44, 73),  /* 105: follow-up of ZANNEN 7 */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 15, 81, 62,  0, 14,  7,  0,  6,  2,  0,  0,  0,  3,  4, -8, 44, 73),  /* 106: follow-up of APPEAR USE */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 34, 81, 54,  0, 11,  7,  0, 16,  3,  0,  0,  0,  3,  8, -8, 44, 73),  /* 107: follow-up of JUDGMENT WAIT */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 35, 81, 62,  0, 10,  7,  0, 10,  4,  0,  0,  0,  3,  6, -8, 44, 73),  /* 108: no name */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 33, 81, 63,  0, 12,  7,  0,  4,  0,  0,  0,  0,  3,  4, -7, 28, 73),  /* 109: follow-up of WIN 2 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 34, 81, 63,  0, 12,  7,  0,  8,  5,  0,  0,  0,  3,  6, -8, 28, 73),  /* 110: follow-up of WIN 3 */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 35, 81, 63,  0, 12,  7,  0, 10,  5,  0,  0,  0,  3,  6, -8, 28, 73),  /* 111: follow-up of WIN 4 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35, 81, 63,  0, 12,  7,  0,  8,  5,  0,  0,  0,  3,  6, -8, 28, 73),  /* 112: follow-up of WIN 4 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 33, 81, 45,  0, 12,  7,  0,  4,  0,  0,  0,  0,  3,  4, -7, 44, 73),  /* 113: follow-up of WIN 5 */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 34, 81, 45,  0, 12,  7,  0,  6,  6,  0,  0,  0,  3,  6, -6, 44, 73),  /* 114: follow-up of WIN 6 */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1, 81, 45,  0, 13,  7,  0, 10,  2,  0,  0,  0,  3,  6, -6, 44, 73),  /* 115: follow-up of WIN 7 */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  2,  0,  8,  5,  0,  0,  0,  3,  7, -7, 28, 72),  /* 116: follow-up of JUDGMENT LOSE */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 16,  6,  0,  0,  0,  3,  8, -8, 28, 73),  /* 117: follow-up of JUDGMENT LOSE */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 24,  7,  0,  0,  0,  3,  9, -9, 28, 73),  /* 118: follow-up of JUDGMENT LOSE */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 13,  2,  0,  8,  5,  0,  0,  0,  3,  7, -7, 44, 72),  /* 119: follow-up of WAIT */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 13,  2,  0, 14,  6,  0,  0,  0,  3,  8, -8, 44, 73),  /* 120: follow-up of AFRICA JUMP */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 13,  2,  0, 22,  7,  0,  0,  0,  3,  9, -9, 44, 73),  /* 121: follow-up of AFRICA LAND */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 11,  4,  0,  8,  5,  0,  0,  0,  3,  9, -9, 28, 72),  /* 122: follow-up of SEAN BALL HIT */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0, 16,  6,  0,  0,  0,  3,  8, -8, 28, 73),  /* 123: follow-up of follow-up of F JUMP P M A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 20,  7,  0,  0,  0,  3,  9, -9, 28, 73),  /* 124: follow-up of BONUS WIN 1 */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 36,  1, 54,  0, 13,  2,  0,  8,  5,  0,  0,  0,  3,  7, -7, 44, 72),  /* 125: follow-up of BONUS WIN 2 */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0, 13,  2,  0, 14,  6,  0,  0,  0,  3,  8, -8, 44, 73),  /* 126: follow-up of APPEAR USE */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 13,  2,  0, 18,  7,  0,  0,  0,  3,  9, -9, 44, 73),  /* 127: follow-up of APPEAR USE */
    ATTR( 36,  1,  0,  1,  0,  0,  0, 37,  1, 54,  0,  9,  4,  0, 12,  3,  0,  0,  0,  3,  8, -8, 44, 73),  /* 128: follow-up of BONUS WIN 3, follow-up of APPEAR USE */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 38,  1, 54,  0,  5,  2,  0,  8,  7,  0,  0,  0,  3, 12,-16, 44, 73),  /* 129: follow-up of APPEAR USE */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 38,  1, 54,  0,  5,  4,  0,  8,  7,  0,  0,  0,  3, 12,-16, 44, 73),  /* 130: follow-up of APPEAR USE */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 36,  1, 54,  0, 11,  7,  0,  8,  0,  0,  0,  0,  3,  8, -8, 28, 73),  /* 131: not started by a command */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  2, 15,  0,  0, 16,  3,  5,  0,  0,  3,  1, -1, 44, 73),  /* 132: not used by a script */
    ATTR( 95,  1,  0,  0,  1,  0,  0,  8, 49, 63,  2,  0,  0,  0,  4,  3,  2,  0,  0,  3,  1, -1, 44, 73),  /* 133: not used by a script */
    ATTR( 95,  3,  0,  0,  1,  0,  0,  9, 49, 63,  2,  0,  0,  0, 16,  3,  1,  0,  0,  3, 10,-10, 44, 73),  /* 134: not used by a script */
    ATTR( 32,  2,  0,  0,  1,  0,  0, 32, 49, 62,  2, 13,  6,  0, 12,  4,  3,  0,  0,  3,  1, -1, 28, 73),  /* 135: ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 32, 49, 62,  2, 12,  6,  0, 20,  4,  2,  0,  0,  3,  6, -6, 28, 73),  /* 136: ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
    ATTR(106,  0,  0,  0,  0,  0, 31, 22, 49, 62,  2, 11,  0,  0, 44,  3, 11,  0,  0,  7, 10,-12, 87, 73),  /* 137: not used by a script */
    ATTR(106,  0,  0,  0,  0,  0,  0, 22, 49, 62,  2, 12,  0,  0, 36,  3,  8,  0,  0,  7,  6, -8, 23, 73),  /* 138: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  1,  0, 35, 49, 63,  3, 13,  0,  0, 16, 48,  4,  0,  0,  3,  8,-16, 28, 73),  /* 139: EX 623+PP (routine Att_SLIDE_and_JUMP) */
    ATTR( 91,  2,  0,  0,  0,  0,  0, 22, 49, 63,  3, 12,  0,  0, 16,  1,  2,  0,  0,  3,  4, -4, 28, 73),  /* 140: EX 623+PP (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 33, 49, 63,  3, 12,  2,  0, 22,  1,  4, 12,  0,  3,  4, -4, 28, 73),  /* 141: 623+P light (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 23, 49, 63,  3, 12,  2,  0, 25,  1,  4, 12,  0,  3,  5, -5, 28, 73),  /* 142: 623+P medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 24, 49, 63,  3, 12,  2,  0, 28,  1,  4, 12,  0,  3,  6, -6, 28, 73),  /* 143: 623+P heavy (routine Att_SLIDE_and_JUMP) */
    ATTR(107,  1,  0,  0,  1,  0,  0, 25, 80, 62,  1, 15,  0,  0, 46,  1,  4,  0,  0,  3,  8, -8, 98, 73),  /* 144: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  1,  0,  0,  1,  0,  0, 26, 80, 62,  1, 14,  7,  0, 12, 52,  3,  0,  0,  3,  4,-12, 98, 73),  /* 145: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 96,  3,  0,  0,  1,  0,  0, 27, 80, 62,  1, 12,  7,  0, 24, 16,  4,  0,  0,  3,  4,-10, 98, 73),  /* 146: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR(106,  0,  0,  0,  0,  0, 31,  5, 49, 62,  3, 11,  0,  0, 40,  3, 11, 10,  0,  3, 10,-12, 87, 73),  /* 147: not used by a script */
    ATTR(106,  0,  0,  0,  0,  0,  0,  5, 49, 62,  3, 12,  0,  0, 32,  3,  8, 10,  0,  3,  6, -8, 23, 73),  /* 148: not used by a script */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 33, 81, 63,  1, 12,  7,  0,  8,  1,  0,  0,  0,  3,  4, -4, 28, 73),  /* 149: not started by a command */
    ATTR( 95,  3,  0,  0,  0,  0,  0, 28, 81, 63,  1, 12,  7,  0, 12,  1,  0,  0,  0,  3,  4, -4, 28, 73),  /* 150: not started by a command */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 21,  1, 62,  0, 10,  0,  0, 12,  2,  4,  1,  0,  3,  8, -8, 39, 73),  /* 151: follow-up of KAGAMI K A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 12,  7,  1,  4,  0,  3,  9, -9, 23, 73),  /* 152: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 33,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  6, -9, 29, 72),  /* 153: follow-up of S PUNCH A, S PUNCH B */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 34,  1, 62,  0, 12,  6,  0, 10,  1,  2,  4,  0,  3, 12,-12, 18, 73),  /* 154: follow-up of follow-up of S PUNCH A, S PUNCH B */
    ATTR( 38,  1,  0,  0,  0,  0,  0, 35,  1, 63,  0, 15,  6,  0,  4,  0,  1,  1,  0,  3, -9, -9, 18, 73),  /* 155: follow-up of KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 35,  1, 63,  0, 13,  6,  0, 14,  0,  1,  1,  0,  3,  9, -9, 23, 73),  /* 156: follow-up of KAGAMI P A */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  2,  0, 16,  3,  3, 11,  0,  3,  8, -8, 44, 73),  /* 157: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  1,  0,  0, 40, 49, 63,  1,  0,  2,  0, 10,  3,  2,  1,  0,  3, 10,-10, 44, 73),  /* 158: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN) */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  2,  0, 16,  3,  3, 11,  0,  3,  8, -8, 44, 73),  /* 159: ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  1,  0,  0, 40, 49, 63,  1,  0,  2,  0, 12,  3,  2,  1,  0,  3, 10,-10, 44, 73),  /* 160: ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN) */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  2,  0, 16,  3,  3, 11,  0,  3,  8, -8, 44, 73),  /* 161: ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  1,  0,  0, 40, 49, 63,  1,  0,  2,  0, 14,  3,  2,  1,  0,  3, 10,-10, 44, 73),  /* 162: ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    ATTR( 96,  1,  0,  0,  1,  0,  0,  8, 49, 63,  1, 15,  0,  0, 16,  3,  4,  0,  0,  3,  1, -1, 44, 73),  /* 163: ATTACK 3 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 95,  1,  0,  0,  1,  0,  0, 39, 49, 63,  1,  0,  1,  0,  4,  3,  2,  0,  0,  3,  1, -1, 44, 73),  /* 164: not used by a script */
    ATTR( 95,  3,  0,  0,  1,  0,  0, 40, 49, 63,  1,  0,  1,  0, 18,  3,  2,  0,  0,  3, 10,-10, 44, 73),  /* 165: ATTACK 3 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    ATTR( 96,  3,  0,  0,  0,  0,  0,  8, 81, 63,  1, 15,  7,  0,  8,  3,  0,  0,  0,  3,  4, -5, 44, 73),  /* 166: ATTACK 11 L: not started by a command */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 40, 81, 63,  1, 15,  7,  0,  8,  3,  0,  0,  0,  3,  4, -5, 44, 73),  /* 167: ATTACK 11 L: not started by a command */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 41,  1,  0,  0,  2,  0,  0,  0,  2,  0,  0,  2,  3, 10,-10, 70, 51),  /* 168: TUKAMIKAKARI B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 18, 81, 62,  0, 15,  7,  0,  8,  1,  0,  0,  0,  3,  6, -6, 34, 73),  /* 169: follow-up of ZANNEN 8 */
    ATTR( 91,  2,  0,  0,  0,  0,  0, 21, 33, 62,  0, 10,  0,  0, 28,  2,  8,  7,  0,  3,  8, -8, 39, 73),  /* 170: L PUNCH C */
    ATTR( 91,  2,  0,  0,  0,  0,  0, 21, 81, 62,  0, 10,  7,  0, 12,  1,  0,  0,  0,  3,  8, -8, 39, 73),  /* 171: follow-up of APPEAR USE */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 36, 64, 54,  0, 11,  2,  0, 18,  7,  0,  0,  0,  3, 11,-11, 23, 73),  /* 172: follow-up of follow-up of SEAN BALL HIT */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 37,  1, 54,  0, 11,  0,  0,  8,  0,  1,  1,  0,  3,  8, -8, 18, 73),  /* 173: ATTACK 12 L: not started by a command */
};

extern const u16 yun_se_random_0[], yun_se_random_1[], yun_se_random_2[], yun_se_random_3[];

const u16* const yun_se_random_table[4] = {
    yun_se_random_0,  /* 0 */
    yun_se_random_1,  /* 1 */
    yun_se_random_2,  /* 2 */
    yun_se_random_3,  /* 3 */
};

const u16 yun_se_random_0[16] = {
    0x026B, 0x026C, 0x026B, 0x026C, 0x026B, 0x026C, 0x026B, 0x026C,
    0x026A, 0x026B, 0x026A, 0x026B, 0x026C, 0x026B, 0x026C, 0x026B,
};

const u16 yun_se_random_1[16] = {
    0x0264, 0x0264, 0x026E, 0x0264, 0x026E, 0x0264, 0x0264, 0x026E,
    0x0264, 0x026B, 0x026E, 0x0264, 0x0266, 0x026E, 0x0264, 0x0264,
};

const u16 yun_se_random_2[16] = {
    0x026F, 0x0265, 0x026F, 0x0265, 0x026E, 0x026F, 0x0265, 0x026F,
    0x026E, 0x0267, 0x026E, 0x026F, 0x0267, 0x0265, 0x026F, 0x026E,
};

const u16 yun_se_random_3[16] = {
    0x0270, 0x026A, 0x0270, 0x026A, 0x0270, 0x026A, 0x0270, 0x026A,
    0x0270, 0x026A, 0x0270, 0x026A, 0x0270, 0x026A, 0x0000, 0x0000,
};

