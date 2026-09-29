/*
 * NECRO_ATTR.C  Necro's attack attributes and random sound lists
 *
 * necro_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * necro_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR necro_catt_table[92] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 12,  0,  0, 10, 24,  2,  1,  0,  3,  7, -7, 13, 72),  /* 1: S PUNCH C */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 12,  0,  0,  6, 24,  1,  1,  0,  3,  7, -7, 13, 72),  /* 2: S PUNCH A */
    ATTR( 33,  1,  0,  0,  0,  0,  0, 17,  1, 62,  0, 12,  2,  0, 10, 25,  5,  4,  0,  3,  9, -9, 18, 73),  /* 3: M PUNCH A, M PUNCH C */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  2,  1, 63,  0, 15,  2,  0, 26, 19,  7,  7,  0,  3, 11,-11, 23, 73),  /* 4: L PUNCH C */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18,  5, 62,  0, 12,  6,  0, 20, 19,  5,  7,  0,  3, 11,-11, 23, 73),  /* 5: L PUNCH A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 12,  0,  0,  9, 24,  3,  1,  0,  3,  7, -7, 29, 72),  /* 6: S KICK C */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 12,  0,  0,  8, 24,  2,  1,  0,  3,  7, -7, 29, 72),  /* 7: S KICK A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 17,  1, 62,  0, 13,  2,  0, 16, 25,  6,  4,  0,  3,  9, -9, 34, 73),  /* 8: M KICK C, ATTACK 7 S: SA II 23623+P (plain script) */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 17,  1, 63,  0, 13,  2,  0, 14, 25,  1,  4,  0,  3,  9, -9, 34, 73),  /* 9: M KICK A */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 18,  1, 62,  0, 14,  4,  0, 28, 25,  8,  7,  0,  3,-11,-11, 39, 73),  /* 10: L KICK C */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 18,  5, 62,  0, 13,  6,  0, 22, 25,  6,  7,  0,  3, 11,-11, 39, 73),  /* 11: L KICK A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 12,  0,  0,  6, 24,  1,  1,  0,  3,  7, -7, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 17,  1, 63,  0, 14,  4,  0, 12, 25,  3,  4,  0,  3,  9, -9, 18, 73),  /* 13: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  3,  1, 63,  0, 14,  0,  0, 18, 19,  2,  7,  0,  3, 11,-11, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 16,  1,  9,  0, 12,  0,  0,  7, 24,  1,  1,  0,  3,  7, -7, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0, 16,  1,  9,  0, 12,  0,  0, 24, 26,  1,  7,  0,  3, 11,-11, 39, 73),  /* 16: not used by a script */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1,  9,  0, 12,  2,  0, 20, 26,  1,  7,  0,  3, 11,-11, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 98,  2,  0,  1,  0,  0,  0,  4, 49, 54,  3, 11,  0,  0, 24, 26,  6,  7,  0,  3,-10,-10, 28, 73),  /* 18: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU) */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 19,  1, 54,  0, 13,  2,  0,  6, 16,  3,  1,  0,  3,  7, -7, 13, 72),  /* 19: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 20,  5, 54,  0, 13,  2,  0, 14, 18,  5,  4,  0,  3,  8, -8, 18, 73),  /* 20: V JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 21,  1, 54,  0, 12,  2,  0, 20, 19,  7,  7,  0,  3,  9, -9, 23, 73),  /* 21: V JUMP P L A, F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 19,  1, 54,  0, 10,  2,  0,  6, 16,  2,  1,  0,  3,  7, -7, 29, 72),  /* 22: V JUMP K S A, F JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 20,  1, 54,  0, 12,  2,  0, 14, 18,  4,  4,  0,  3,  8, -8, 34, 73),  /* 23: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 21,  1, 54,  0, 12,  2,  0, 24, 19,  6,  7,  0,  3,  9, -9, 39, 73),  /* 24: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 19,  1, 54,  0, 10,  2,  0,  8, 16,  3,  1,  0,  3,  7, -7, 13, 72),  /* 25: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 20,  1, 54,  0, 10,  2,  0, 16, 18,  5,  4,  0,  3,  8, -8, 18, 73),  /* 26: F JUMP P M A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 20,  1, 63,  0, 10,  2,  0, 12, 18,  1,  5,  0,  3,  8, -8, 36, 73),  /* 27: F JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 20,  1, 63,  0, 10,  2,  0,  4, 18,  1,  1,  0,  3,  8, -8, 36, 73),  /* 28: F JUMP K M A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 21,  1, 63,  0, 10,  2,  0, 16, 19,  2,  8,  0,  3,  8, -8, 40, 73),  /* 29: F JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 21,  1, 63,  0, 10,  2,  0,  4, 19,  2,  1,  0,  3,  8, -8, 40, 73),  /* 30: F JUMP K L A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 16,  1, 63,  0, 14,  0,  0,  1, 16,  0,  1,  0,  3,  7, -7,108,  0),  /* 31: ATTACK 10 SP: not started by a command */
    ATTR( 40,  1,  0,  0,  0,  0,  0, 10, 49, 54,  0, 10,  0,  0, 24, 25,  5,  4,  0,  3,  8, -8, 34, 73),  /* 32: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16,  1,  0,  0, 12,  0,  0,  0, 25,  0,  0,  2,  3, 10,-10, 70,  0),  /* 33: TUKAMIKAKARI A */
    ATTR( 32,  2,  0,  0,  0,  0,  3,  5,  1, 63,  0, 12,  0,  0, 24, 26,  6, 13,  2,  3, 10,-10, 23, 73),  /* 34: CATCH 1 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16, 49, 63,  0, 12,  0,  0, 40, 26,  5, 13,  1,  3, 10,-10, 63,  0),  /* 35: CATCH 2 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16, 49,  0,  0, 12,  0,  0,  0, 25,  0,  0,  1,  3, 10,-10, 70,  0),  /* 36: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16, 49, 44,  0, 11,  0,  0,  0, 24,  0,  4,  1,  3, 10,-10, 84,  0),  /* 37: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +1 */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  6, 49,  0,  0,  2,  2,  0, 28, 26,  5, 13,  1,  3, 10,-10, 73, 55),  /* 38: CATCH 4 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 22, 49, 62,  3, 12,  2,  0, 10, 24,  3, 10,  0,  3, 12,-12, 28, 73),  /* 39: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 94,  2,  0,  0,  1,  0,  0,  3, 49, 62,  3, 12,  2,  0, 14, 26,  2,  1,  0,  3, 12,-12, 28, 73),  /* 40: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 94,  2,  0,  0,  1,  0,  0, 22, 49, 62,  3, 12,  2,  0, 14, 24,  3,  1,  0,  3, 12,-12, 28, 73),  /* 41: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  1,  2,  0,  0,  0,  0,  8, 49, 62,  1,  0,  2,  0, 12, 16,  4,  7,  0,  3, 16,-16, 23, 73),  /* 42: ATTACK 3 S: 623+P light (plain script), ATTACK 3 M: 623+P medium (plain script), ATTACK 3 L: 623+P heavy/EX (plain script) */
    ATTR( 37,  1,  2,  0,  0,  0,  0,  8, 49, 62,  1,  0,  2,  0, 12, 17,  2,  1,  0,  3, 16,-16, 23, 73),  /* 43: ATTACK 3 S: 623+P light (plain script), ATTACK 3 M: 623+P medium (plain script), ATTACK 3 L: 623+P heavy/EX (plain script) */
    ATTR( 92,  2,  2,  0,  0,  0,  0,  9, 81, 63,  3,  0,  0,  0,  8, 53,  0,  0,  0,  7,  4, -6, 28, 73),  /* 44: ATTACK 4 S: SA I 23623+P (plain script) */
    ATTR( 37,  2,  2,  0,  0,  0,  0, 16, 81, 63,  3,  0,  0,  0,  8, 53,  0,  0,  0,  7,  4, -6, 28, 73),  /* 45: ATTACK 4 S: SA I 23623+P (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  7,  1,  0,  0,  2,  0,  0, 20, 26,  9, 13,  2,  3, 10,-10, 73, 55),  /* 46: CATCH 3 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16,  1,  0,  0, 11,  0,  0,  0, 25,  0,  0,  2,  3, 10,-10, 70,  0),  /* 47: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 11,  1, 63,  0,  0,  2,  0,  0, 26,  0,  0,  1,  3, 10,-10, 73, 73),  /* 48: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 11,  1, 63,  0,  0,  2,  0,  0, 26,  0,  0,  1,  3, 10,-10, 73,  0),  /* 49: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 12, 81, 63,  0,  2,  0,  0, 52, 26,  3,  0,  2,  3, 10,-10, 73,131),  /* 50: CATCH 6 */
    ATTR( 32,  2,  0,  0,  0,  1, 30, 16, 81, 63,  0, 12,  0,  0, 24, 26,  3,  0,  1,  3, 10,-10, 55, 73),  /* 51: CATCH 6 */
    ATTR( 32,  2,  0,  0,  0,  0, 37, 16, 81,  0,  0, 12,  0,  0,  0, 25,  0,  0,  1,  3, 10,-10, 70,  0),  /* 52: ATTACK 7 S: SA II 23623+P (plain script) */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 17,  1,  9,  0, 12,  0,  0, 12, 25,  1,  4,  0,  3,  9, -9, 34, 73),  /* 53: KAGAMI K A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 17,  1, 62,  0, 12,  0,  0, 14, 25,  5,  4,  0,  3,  9, -9, 18, 73),  /* 54: M PUNCH C */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16, 49, 54,  0, 11,  0,  0, 14, 16,  5,  7,  0,  3,  8, -8, 28, 73),  /* 55: not used by a script */
    ATTR( 37,  2,  2,  0,  0,  0,  0, 16, 81, 63,  3,  0,  7,  0, 32, 53,  0,  0,  0,  7,  4, -6, 28, 73),  /* 56: ATTACK 4 S: SA I 23623+P (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17, 49, 62,  3, 12,  2,  0, 10, 24,  3, 10,  0,  3,  8, -8, 28, 73),  /* 57: ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17, 49, 62,  3, 12,  2,  0, 16, 26,  2,  1,  0,  3, 12,-12, 28, 73),  /* 58: ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17, 49, 62,  3, 12,  2,  0, 16, 24,  3,  1,  0,  3, 12,-12, 28, 73),  /* 59: ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 26,  3, 10,  0,  3,  8, -8, 28, 73),  /* 60: ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  2,  0,  0,  1,  0,  0,  3, 49, 62,  3, 12,  2,  0, 16, 24,  2,  1,  0,  3, 12,-12, 28, 73),  /* 61: ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  3,  0,  0,  1,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 24,  2,  1,  0,  3, 12,-12, 28, 73),  /* 62: ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 98,  2,  0,  1,  0,  0,  0,  4, 49, 54,  3, 11,  0,  0, 28, 26,  6,  7,  0,  3,-10,-10, 28, 73),  /* 63: ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 98,  2,  0,  1,  0,  0,  0,  4, 49, 54,  3, 11,  0,  0, 32, 26,  6,  7,  0,  3,-10,-10, 28, 73),  /* 64: ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 26,  3,  1,  0,  3,  8, -8, 28, 73),  /* 65: ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 19,  1, 54,  0, 10,  0,  0, 16, 16,  3,  4,  0,  3,  8, -8, 18, 72),  /* 66: not used by a script */
    ATTR( 91,  2,  2,  0,  0,  0,  0,  8, 49, 63,  1,  0,  2,  0, 12, 17,  2,  1,  0,  3, 16,-16, 23, 73),  /* 67: ATTACK 3 M: 623+P medium (plain script), ATTACK 3 L: 623+P heavy/EX (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  6, 49, 63,  0,  2,  2,  0, 30, 26,  6, 13,  1,  3, 10,-10, 73, 55),  /* 68: CATCH 9 */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  6, 49, 63,  0,  2,  2,  0, 32, 26,  7, 13,  1,  3, 10,-10, 73, 55),  /* 69: CATCH 10 */
    ATTR( 40,  2,  0,  0,  0,  0,  0, 10, 49, 54,  3, 10,  0,  0, 26, 25,  3, 10,  0,  3, 10,-10, 44, 73),  /* 70: ATTACK 9 L: 214+K light (plain script) */
    ATTR( 40,  2,  0,  0,  0,  0,  0, 10, 49, 54,  3, 10,  0,  0, 30, 25,  4, 10,  0,  3, 10,-10, 44, 73),  /* 71: ATTACK 9 SP: 214+K medium (plain script) */
    ATTR( 40,  2,  0,  0,  0,  0,  0, 10, 49, 54,  3, 10,  0,  0, 34, 25,  5, 10,  0,  3, 10,-10, 44, 73),  /* 72: ATTACK 10 S: 214+K heavy (plain script) */
    ATTR( 37,  2,  2,  0,  0,  0,  0, 16, 81, 63,  0,  0,  0,  0,  6, 53,  0,  0,  0,  7,  4, -6, 28, 73),  /* 73: ATTACK 4 S: SA I 23623+P (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17,  1, 63,  0, 12,  0,  0, 48, 26,  6, 13,  1,  3, 10,-10, 63,  0),  /* 74: CATCH 11 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18,  1, 63,  0, 12,  0,  0, 56, 26,  7, 13,  1,  3, 10,-10, 63,  0),  /* 75: CATCH 12 */
    ATTR( 33,  1,  0,  0,  0,  0,  0, 17,  1, 62,  0, 12,  0,  0, 10, 25,  2,  4,  0,  3,  9, -9, 18, 73),  /* 76: follow-up of S KICK C */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18,  1, 63,  0, 12,  6,  0, 16, 26,  3,  4,  0,  3, 11,-11, 23, 73),  /* 77: follow-up of follow-up of S KICK C */
    ATTR( 92,  2,  2,  0,  0,  0,  0,  9, 81, 63,  3,  0,  0,  0,  4, 53,  0,  0,  0,  7,  4, -6, 28, 73),  /* 78: ATTACK 4 S: SA I 23623+P (plain script) */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 19,  1, 63,  0, 10,  2,  0, 10, 18,  1,  5,  0,  3,  7, -7, 36, 73),  /* 79: V JUMP K S B */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 19,  1, 63,  0, 10,  2,  0,  3, 18,  1,  1,  0,  3,  7, -7, 36, 73),  /* 80: V JUMP K S B */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  4, 49, 54,  3, 11,  0,  0, 16, 16,  6,  0,  0,  3,  2, -2, 28, 73),  /* 81: ATTACK 6 SP: EX 214+PP (routine Att_JINNCHUUWATARI) */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  4, 49, 54,  3, 11,  0,  0, 24, 26,  1,  0,  0,  3,  7, -7, 28, 73),  /* 82: ATTACK 6 SP: EX 214+PP (routine Att_JINNCHUUWATARI) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 10, 49, 54,  3, 10,  0,  0, 20, 25,  5,  0,  0,  3,  6, -6, 44, 73),  /* 83: ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 40,  2,  0,  0,  0,  0,  0, 10, 49, 54,  3, 10,  0,  0, 22, 25,  1,  0,  0,  3, 10,-10, 44, 73),  /* 84: ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 94,  1,  0,  0,  0,  0,  0, 15, 49, 62,  3, 12,  0,  0, 10, 26,  1,  0,  0,  3,  8, -8, 28, 73),  /* 85: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 26,  1,  0,  0,  3,  4, -4, 28, 73),  /* 86: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 25,  1,  0,  0,  3,  2, -2, 28, 73),  /* 87: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 18, 49, 62,  3, 12,  2,  0, 10, 25,  1,  0,  0,  3,  3, -3, 28, 73),  /* 88: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 94,  2,  0,  0,  0,  0,  0, 15, 49, 62,  3, 12,  2,  0, 10, 26,  1,  0,  0,  3,  4, -4, 28, 73),  /* 89: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  3,  1, 63,  0, 14,  0,  0, 28, 26,  5,  7,  0,  3, 11,-11, 23, 73),  /* 90: KAGAMI P C */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 20,  1, 54,  0, 10,  0,  0,  8, 16,  1,  1,  0,  3,  8, -8, 18, 73),  /* 91: ATTACK 8 L: not started by a command */
};

extern const u16 necro_se_random_0[];

const u16* const necro_se_random_table[1] = {
    necro_se_random_0,  /* 0 */
};

const u16 necro_se_random_0[16] = {
    0x032C, 0x0333, 0x0333, 0x032C, 0x0333, 0x032B, 0x032C, 0x0333,
    0x032C, 0x0333, 0x032B, 0x032C, 0x0333, 0x032B, 0x032C, 0x0333,
};

