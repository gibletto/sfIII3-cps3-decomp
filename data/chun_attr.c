/*
 * CHUN_ATTR.C  Chun-Li's attack attributes and random sound lists
 *
 * chun_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * chun_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR chun_catt_table[124] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 10,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 1: S KICK A */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  2, 17, 54,  0, 12,  0,  0, 22, 16,  6,  3,  0,  3, 15,-15, 43, 73),  /* 2: KAGAMI K C */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  0,  0,  6, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 3: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH B */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0, 12,  2,  0, 12, 30,  3,  2,  0,  3,  7,-11, 18, 73),  /* 5: M PUNCH C */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0, 12,  6,  0, 10, 16,  4,  1,  0,  3, 12,-12, 18, 73),  /* 6: M PUNCH C */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 20, 18,  5,  2,  0,  3,  9, -9, 18, 73),  /* 7: M PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 36,  1, 62,  0, 14,  6,  0, 26, 19,  7,  3,  0,  3, 12,-12, 23, 73),  /* 8: L PUNCH C */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 36,  1, 62,  0, 12,  6,  0, 22, 19,  5,  3,  0,  3, 12,-15, 23, 73),  /* 9: L PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 10,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 38,  1, 54,  0, 11,  0,  0,  8, 16,  1,  1,  0,  3,  8, -8, 18, 73),  /* 11: ATTACK 9 S: not started by a command */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0,  0,  6,  0, 16, 16,  2,  4,  0,  3,  8,-15, 34, 73),  /* 12: M KICK A */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0, 12,  6,  0,  4, 16,  3,  5,  0,  3,  9,-11, 34, 73),  /* 13: follow-up of M KICK A */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0, 12,  6,  0,  4, 16,  3,  5,  0,  3,  9, -9, 34, 73),  /* 14: follow-up of M KICK A */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 14,  6,  0, 18, 18,  5,  2,  0,  3,  9,-11, 34, 73),  /* 15: M KICK B */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 15,  1, 62,  0,  0,  1,  0, 24, 30,  7,  3,  0,  3, 14,-14, 39, 73),  /* 16: L KICK A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 15,  1, 62,  0,  0,  1,  0, 22, 30,  6,  3,  0,  3, 14,-14, 39, 73),  /* 17: L KICK A */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 36,  1, 62,  0, 14,  6,  0, 24, 17,  6,  3,  0,  3, 12,-12, 39, 73),  /* 18: L KICK B */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 45,  0, 12,  6,  0, 18, 17,  1,  2,  0,  3,  9,-11, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 12,  6,  0, 22, 17,  2,  3,  0,  3, 11,-11, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 12,  6,  0, 22, 17,  6,  3,  0,  3, 11,-11, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 45,  0, 13,  6,  0,  4, 16,  1,  1,  0,  3,  7,  7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 45,  0, 12,  6,  0, 18, 16,  1,  2,  0,  3,  9,-10, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  6,  0, 22, 17,  2,  3,  0,  3, 11,-11, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 12,  2,  0,  8, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 12,  2,  0, 16, 21,  5,  2,  0,  3,  8, -8, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  3,  1, 54,  0,  8,  2,  0, 26, 21,  7,  3,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 12,  2,  0,  8, 21,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 12,  2,  0, 16, 21,  4,  2,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 39,  1, 54,  0, 13,  2,  0, 26, 21,  6,  3,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 11,  2,  0,  8, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 11,  2,  0, 12, 21,  4,  2,  0,  3, 12,-12, 18, 73),  /* 33: F JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 17,  1, 54,  0, 12,  2,  0, 16, 19,  4,  3,  0,  3,  9, -9, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 12,  2,  0, 10, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 35: F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 38,  1, 54,  0, 12,  2,  0, 18, 21,  4,  2,  0,  3,  8, -8, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0,  4,  1, 54,  0,  9,  2,  0, 22, 17,  6,  3,  0,  3,  9, -9, 39, 73),  /* 37: F JUMP K L A, S V JP S P A */
    ATTR( 34,  1,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0, 10, 17,  3,  6,  0,  3,  3, -3, 43, 73),  /* 38: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  6, 16,  1,  1,  0,  3,  1, -1, 43, 73),  /* 39: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  6, 17,  2,  1,  0,  3,  4, -8, 43, 73),  /* 40: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  6,  1, 63,  0,  0,  0,  0, 24, 16,  4, 13,  0,  3,  8, -8,  0, 51),  /* 41: CATCH 1 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 36,  1,  0,  0, 10,  0,  0,  0, 18,  0,  0,  1,  3, 10,-10,  0,  0),  /* 42: TUKAMIKAKARI A, TUKAMI AIR A */
    ATTR( 96,  2,  0,  1,  0,  0,  0,  7,  1, 63,  0, 11,  2,  0, 16,  0,  4, 13,  0,  3,  7, -7,  0, 51),  /* 43: CATCH 9 */
    ATTR( 33,  2,  0,  0,  1,  0,  0,  8, 49, 62,  3, 13,  6,  0,  4, 46,  2,  1,  0,  3,  2, -4, 42, 73),  /* 44: ATTACK 3 S: after KKKKK (plain script), ATTACK 4 S: after KKKKK (plain script), ATTACK 11 SP: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 11,  6,  0,  6, 46,  1,  1,  0,  3,  2, -4, 42, 73),  /* 45: ATTACK 3 S: after KKKKK (plain script), ATTACK 4 S: after KKKKK (plain script), ATTACK 11 SP: after KKKKK (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 10, 49, 62,  0, 14,  5,  0,  4, 46,  3,  1,  0,  3,  2, -4, 42, 73),  /* 46: not used by a script */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 11, 49, 62,  3, 12,  6,  0,  4, 46,  1,  1,  0,  3,  2, -5, 42, 73),  /* 47: ATTACK 3 S: after KKKKK (plain script), ATTACK 4 S: after KKKKK (plain script), ATTACK 11 SP: after KKKKK (plain script) */
    ATTR( 33,  2,  0,  0,  1,  0,  0,  8, 49, 62,  3, 13,  6,  0,  4, 46,  2,  1,  0,  3,  2, -3, 43, 73),  /* 48: ATTACK 3 M: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 12 S: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 11,  6,  0,  6, 46,  1,  1,  0,  3,  2, -4, 43, 73),  /* 49: ATTACK 3 M: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 12 S: after KKKKK (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 10, 49, 62,  0, 14,  6,  0,  4, 46,  3,  1,  0,  3,  2, -3, 43, 73),  /* 50: not used by a script */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 11, 49, 62,  3, 12,  6,  0,  6, 46,  1,  1,  0,  3,  2, -3, 43, 73),  /* 51: ATTACK 3 M: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 12 S: after KKKKK (plain script) */
    ATTR( 33,  2,  0,  0,  1,  0,  0,  8, 49, 62,  3, 13,  6,  0,  4, 46,  2,  1,  0,  3,  1, -1, 44, 73),  /* 52: ATTACK 3 L: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script), ATTACK 12 M: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 11,  6,  0,  8, 46,  1,  1,  0,  3,  1, -2, 43, 73),  /* 53: ATTACK 3 L: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script), ATTACK 12 M: after KKKKK (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 10, 49, 62,  0, 14,  6,  0,  4, 46,  3,  1,  0,  3,  1, -1, 44, 73),  /* 54: not used by a script */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 11, 49, 62,  3, 12,  6,  0,  6, 46,  1,  1,  0,  3,  1, -1, 43, 73),  /* 55: ATTACK 3 L: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script), ATTACK 12 M: after KKKKK (plain script) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 17,  1, 54,  0, 12,  2,  0, 12, 18,  3,  1,  0,  3,  9, -9, 23, 73),  /* 56: F JUMP P L A */
    ATTR( 36,  2,  0,  1,  0,  0,  0, 18, 17, 54,  0,  8,  2,  0, 10, 16,  2,  1,  0,  3,  8, -8, 34, 73),  /* 57: V JUMP K M B */
    ATTR( 38,  2,  0,  0,  0,  0, 86, 12, 64, 63,  3, 12,  7,  0,  8, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 58: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 38,  2,  0,  0,  0,  0, 87, 12, 64, 63,  3, 12,  7,  0,  8, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 59: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 38,  2,  0,  0,  0,  0, 92, 12, 64, 63,  3, 12,  7,  0,  8, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 60: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 93, 12, 64, 63,  0, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 61: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 94, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 62: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 95, 12, 64, 63,  0, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 63: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 96, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 64: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 97, 12, 64, 63,  0, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 65: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 98, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 66: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 88, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 67: not used by a script */
    ATTR( 93,  2,  0,  0,  0,  0, 89, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 68: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 90, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 69: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0, 91, 12, 64, 63,  3, 12,  7,  0,  7, 14,  0,  0,  0,  7,  1, -2, 23, 73),  /* 70: ATTACK 6 S: SA I 23623+P (plain script) */
    ATTR( 32,  1,  0,  1,  1,  0,  0, 21, 49, 62,  3,  0,  0,  0, 10, 31,  3,  0,  0,  3,  3, -3, 40, 73),  /* 71: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  1,  1,  0,  0, 21, 49, 62,  3,  0,  0,  0,  8, 31,  1,  0,  0,  3,  3, -3, 40, 73),  /* 72: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    ATTR( 94,  2,  0,  1,  1,  0,  0, 22, 49, 62,  3,  0,  2,  0, 10, 47,  1,  0,  0,  3,  6, -6, 40, 73),  /* 73: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 24, 49, 62,  3, 13,  0,  0,  8, 46,  2,  0,  0,  3,  1, -1, 44, 73),  /* 74: ATTACK 3 SP: after KKKKK (plain script), ATTACK 4 SP: after KKKKK (plain script) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 25, 49, 62,  3, 11,  0,  0,  8, 46,  1,  0,  0,  3,  1, -2, 44, 73),  /* 75: ATTACK 3 SP: after KKKKK (plain script), ATTACK 4 SP: after KKKKK (plain script) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 26, 49, 62,  0, 14,  0,  0,  8, 46,  3,  0,  0,  3,  1, -1, 44, 73),  /* 76: not used by a script */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 27, 49, 62,  3, 12,  0,  0,  8, 46,  1,  0,  0,  3,  1, -1, 44, 73),  /* 77: ATTACK 3 SP: after KKKKK (plain script), ATTACK 4 SP: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 10,  6,  0,  8, 46,  1,  1,  0,  3,  2, -5, 42, 73),  /* 78: ATTACK 3 S: after KKKKK (plain script), ATTACK 4 S: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 10,  6,  0,  8, 46,  1,  1,  0,  3,  2, -5, 43, 73),  /* 79: ATTACK 3 M: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 49, 62,  3, 10,  6,  0, 10, 46,  1,  1,  0,  3,  1, -3, 44, 73),  /* 80: ATTACK 3 L: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) */
    ATTR( 93,  2,  0,  0,  1,  0,  0, 25, 49, 62,  3, 10,  0,  0, 12, 46,  1,  0,  0,  3,  1, -3, 44, 73),  /* 81: ATTACK 3 SP: after KKKKK (plain script), ATTACK 4 SP: after KKKKK (plain script) */
    ATTR( 33,  2,  0,  0,  1,  0,  0,  8, 65, 62,  3, 13,  0,  0,  6, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 82: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  0, 11,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 83: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 11, 65, 62,  3, 12,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 84: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  0, 10,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 85: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  3, 10,  0,  0,  8, 16,  1,  0,  0,  3,  3,-10, 44, 73),  /* 86: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  0,  0,  1,  0,  0,  8, 65, 62,  0, 13,  0,  0,  6, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 87: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  3, 11,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 88: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  0,  0,  1,  0,  0, 11, 65, 62,  0, 12,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 89: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  3, 10,  0,  0,  8, 63,  1,  0,  0,  3,  1, -2, 44, 73),  /* 90: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  9, 65, 62,  3, 10,  0,  0,  8, 63,  1,  0,  0,  3,  3,-12, 44, 73),  /* 91: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  3,  0,  0,  1,  0,  0, 14, 81, 62,  2, 14,  1,  0, 40, 20,  4,  0,  0,  3, 14,-14, 44, 73),  /* 92: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 91,  2,  0,  0,  1,  0,  0, 28, 81, 62,  2, 14,  1,  0, 36, 20,  4,  0,  0,  3, 10,-10, 44, 73),  /* 93: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 20, 17,  5,  6,  0,  3, 12,-12, 44, 73),  /* 94: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 18, 17,  4,  6,  0,  3, 11,-11, 44, 73),  /* 95: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 22, 18,  6,  7,  0,  3, 12,-12, 44, 73),  /* 96: ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 20, 18,  5,  7,  0,  3, 11,-11, 44, 73),  /* 97: ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 24, 19,  7,  8,  0,  3, 12,-12, 44, 73),  /* 98: ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 49, 54,  2,  8,  0,  0, 22, 19,  6,  8,  0,  3, 11,-11, 44, 73),  /* 99: ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 70,  2,  0,  0,  0,  0,  0, 33, 49, 54,  2,  8,  0,  0, 32, 19,  8,  0,  0,  3, 12,-12, 44, 73),  /* 100: ATTACK 10 SP: EX 3214+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 70,  2,  0,  0,  0,  0,  0, 33, 49, 54,  2,  8,  0,  0, 22, 19,  7,  0,  0,  3, 12,-12, 44, 73),  /* 101: not used by a script */
    ATTR( 95,  2,  0,  1,  0,  0,  0, 30, 65, 63,  3,  0,  7,  0,  5, 52,  1,  0,  0,  3,  3, -3, 40, 73),  /* 102: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 98,  2,  0,  1,  0,  0,  0, 31, 65, 63,  3,  8,  0,  0,  6, 18,  1,  0,  0,  3,  4, -4, 40, 73),  /* 103: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 98,  2,  0,  1,  0,  0,  0, 31, 65, 63,  3,  8,  0,  0,  6, 18,  1,  0,  0,  3,  4, -4, 40, 73),  /* 104: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 98,  2,  0,  1,  0,  0,  0, 31, 65, 63,  3,  8,  0,  0,  6, 18,  1,  0,  0,  3,  4, -5, 40, 73),  /* 105: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 95,  2,  0,  1,  0,  0,  0, 30, 65, 63,  3,  0,  7,  0, 16, 52,  1,  0,  0,  3,  3, -3, 40, 73),  /* 106: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 70,  2,  0,  0,  0,  0,  0, 32, 65, 54,  1,  0,  0,  0, 28, 19,  4,  0,  0,  3, 10,-10, 44, 73),  /* 107: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 29, 65, 54,  2,  0,  2,  0, 22, 19,  4,  0,  0,  3, 11,-11, 44, 73),  /* 108: not used by a script */
    ATTR( 34,  1,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0, 10, 17,  3,  7,  0,  3,  4, -4, 43, 73),  /* 109: ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  5, 16,  1,  1,  0,  3,  1, -1, 43, 73),  /* 110: ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  6, 17,  2,  1,  0,  3,  4, -8, 43, 73),  /* 111: not used by a script */
    ATTR( 34,  1,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0, 10, 17,  2,  8,  0,  3,  5, -5, 44, 73),  /* 112: ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  5, 16,  1,  1,  0,  3,  1, -1, 44, 73),  /* 113: ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  6, 17,  2,  1,  0,  3,  4, -8, 44, 73),  /* 114: not used by a script */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 11,  5,  0, 16, 18,  2,  2,  0,  3,  9,-13, 34, 73),  /* 115: M KICK C */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  9, 49, 62,  3, 10,  6,  0,  8, 46,  1,  6,  0,  3,  2, -5, 42, 73),  /* 116: ATTACK 11 SP: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  9, 49, 62,  3, 10,  6,  0,  8, 46,  1,  6,  0,  3,  2, -5, 43, 73),  /* 117: ATTACK 12 S: after KKKKK (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  9, 49, 62,  3, 10,  6,  0, 10, 46,  1,  6,  0,  3,  1, -3, 44, 73),  /* 118: ATTACK 12 M: after KKKKK (plain script) */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  3,  1, 54,  0,  9,  2,  0, 22, 16,  7,  4,  0,  3,  9,-12, 23, 73),  /* 119: F JUMP P L B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0,  8, 16,  2,  1,  0,  3,  9,-11, 18, 73),  /* 120: no name */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 14,  6,  0, 12, 18,  4,  2,  0,  3,  9,-11, 34, 73),  /* 121: no name */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  7, 17,  1,  1,  0,  3,  4, -8, 43, 73),  /* 122: ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  1,  1,  0,  0,  5, 49, 62,  3, 11,  2,  0,  6, 17,  1,  1,  0,  3,  4, -8, 43, 73),  /* 123: ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
};

extern const u16 chun_se_random_0[];

const u16* const chun_se_random_table[1] = {
    chun_se_random_0,  /* 0 */
};

const u16 chun_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

