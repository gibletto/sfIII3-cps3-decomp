/*
 * GOUKI2_ATTR.C  Shin Gouki's attack attributes and random sound lists
 *
 * gouki2_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * gouki2_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR gouki2_catt_table[84] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2, 15,  2,  0, 26, 16,  5, 11,  0,  3, 10,-10, 28, 73),  /* 1: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 96,  2,  0,  1,  0,  0,  0,  2, 49, 63,  2,  0,  4,  0, 20, 16,  4, 11,  0,  3, 12,-12, 28, 73),  /* 2: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 29,  1, 63,  0, 13,  0,  0,  6, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 3: S PUNCH A, follow-up of UP P GUARD P L */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 29,  1, 63,  0, 12,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH B */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 30,  1, 62,  0, 12,  6,  0, 23, 30,  5,  4,  0,  3,  9, -9, 18, 73),  /* 5: M PUNCH A, UP P GUARD P M */
    ATTR( 32,  1,  0,  0,  1,  0,  0, 30,  1, 62,  0, 12,  6,  0, 21, 18,  4,  4,  0,  3,  9, -9, 18, 73),  /* 6: M PUNCH B, UP P GUARD P S: SA (all arts) 25252+PP (plain script) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 31,  1, 62,  0, 14,  6,  0, 27, 19,  7,  7,  0,  3, 12,-12, 23, 73),  /* 7: L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 31,  1, 62,  0, 12,  6,  0, 16, 19,  1,  1,  0,  3, 10,-12, 23, 73),  /* 8: follow-up of UP P GUARD P M, follow-up of M PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 31,  1, 62,  0, 12,  6,  0, 28, 19,  6,  7,  0,  3, 10,-14, 23, 73),  /* 9: L PUNCH B, follow-up of UP P GUARD P L, UP P GUARD P L */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 29,  1, 63,  0, 10,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: S KICK A */
    ATTR( 36,  2,  0,  1,  0,  0,  0, 33,  1, 54,  0,  9,  6,  0, 20, 21,  5,  4,  0,  3,  8, -8, 34, 73),  /* 11: F JUMP K M B */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 30,  1, 62,  0, 13,  6,  0, 23, 17,  4,  4,  0,  3,  9, -9, 34, 73),  /* 12: M KICK A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 30,  1, 62,  0, 12,  6,  0, 19, 18,  3,  4,  0,  3,  9, -9, 34, 73),  /* 13: M KICK B, UP P GUARD K S */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 31,  1, 63,  0, 15,  6,  0, 30, 19,  6,  7,  0,  3, 12,-12, 39, 73),  /* 14: not used by a script */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 31,  1, 63,  0, 15,  6,  0,  4, 17,  5,  7,  0,  3, 11,-11, 39, 73),  /* 15: not used by a script */
    ATTR( 64,  2,  0,  0,  0,  0,  0, 31,  1, 63,  0, 10,  0,  0,  4, 19,  3,  7,  0,  3, 11,-11, 39, 73),  /* 16: not used by a script */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 31,  1, 62,  0, 14,  6,  0, 29, 19,  5,  7,  0,  3, 12,-12, 39, 73),  /* 17: L KICK A */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 31,  1, 63,  0, 13,  2,  0, 32, 17,  7,  7,  0,  3, 14,-14, 39, 73),  /* 18: UP P GUARD K L */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 29,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 30,  1, 63,  0, 12,  6,  0, 19, 17,  3,  4,  0,  3,  9, -9, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 15,  6,  0, 27, 17,  5,  7,  0,  3, 11,-11, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 35,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 15,  6,  0, 27, 17,  5,  7,  0,  3, 11,-11, 23, 73),  /* 22: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 29,  1, 45,  0, 12,  6,  0,  4, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 30,  1, 45,  0, 12,  6,  0, 19, 16,  1,  4,  0,  3,  9, -9, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 45,  0, 12,  6,  0, 27, 17,  1,  7,  0,  3, 12,-10, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 32,  1, 54,  0, 11,  2,  0, 10, 21,  2,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A, S V JP S P A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 33,  1, 54,  0, 11,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 18, 73),  /* 27: V JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 17,  1, 54,  0, 12,  2,  0, 26, 21,  6,  7,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A, S V JP L P A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 32,  1, 54,  0, 11,  2,  0,  8, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 33,  1, 54,  0, 12,  2,  0, 16, 21,  3,  4,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A, S V JP M K A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 34,  1, 54,  0, 14,  2,  0, 24, 21,  5,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 32,  1, 54,  0,  8,  2,  0,  8, 21,  2,  1,  0,  3,  7, -7, 13, 72),  /* 32: F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 33,  1, 54,  0, 14,  2,  0, 10, 21,  3,  1,  0,  3, 12,-12, 18, 73),  /* 33: S V JP M P A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 17,  1, 54,  0, 12,  2,  0, 26, 21,  6,  7,  0,  3,  9, -9, 23, 73),  /* 34: F JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 32,  1, 54,  0, 12,  2,  0,  8, 21,  2,  1,  0,  3,  7, -7, 29, 72),  /* 35: F JUMP K S A, S V JP S K A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 33,  1, 54,  0, 12,  2,  0, 16, 21,  3,  4,  0,  3,  8, -8, 34, 73),  /* 36: F JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 34,  1, 54,  0, 12,  2,  0, 24, 21,  5,  7,  0,  3,  9, -9, 39, 73),  /* 37: F JUMP K L A, S V JP L K A */
    ATTR( 38,  1,  0,  0,  1,  0,  0, 30, 49, 62,  3, 11,  0,  0, 12, 17,  3, 12,  0,  3,  5, -5, 44, 73),  /* 38: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    ATTR(113,  0,  0,  0,  1,  0,  0,  6, 49, 62,  3, 13,  2,  0, 16, 17,  3, 12,  0,  3,  8, -8, 44, 73),  /* 39: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU) */
    ATTR( 34,  2,  0,  0,  1,  0,  0, 29, 49, 62,  3, 11,  6,  0,  6, 26,  2,  1,  0,  3,  5, -5, 44, 73),  /* 40: not used by a script */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  3, 81, 63,  1, 15,  7,  0, 20, 16,  1,  0,  0,  3,  6, -8, 28, 73),  /* 41: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  0,  0,  0,  3, 81, 63,  2,  0,  7,  0,  8, 16,  1,  0,  0,  3,  6, -8, 28, 73),  /* 42: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  3, 81, 63,  1, 15,  7,  0,  8, 16,  1,  0,  0,  3,  6,-14, 28, 73),  /* 43: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 35,  2,  0,  0,  0,  0,  0,  3, 81, 63,  2,  0,  7,  0,  8, 16,  1,  0,  0,  3,  6,-14, 28, 73),  /* 44: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  3, 81, 63,  2, 15,  7,  0,  8, 16,  1,  0,  0,  3,  6, -6, 28, 73),  /* 45: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  3, 81, 63,  2,  0,  7,  0,  8, 16,  1,  0,  0,  3,  6, -6, 28, 73),  /* 46: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  4,  1, 63,  0,  0,  0,  0, 22, 16,  4, 13,  0,  3,  8, -8,  0, 51),  /* 47: CATCH 1, CATCH 3 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 29,  1,  0,  0, 10,  0,  0,  0, 18,  0,  0,  1,  3, 10,-10,  0,  0),  /* 48: TUKAMIKAKARI A */
    ATTR( 96,  2,  0,  0,  0,  0,  0,  5,  1, 63,  0, 10,  0,  0, 22, 16,  7, 13,  0,  3,  8, -8,  0, 51),  /* 49: CATCH 5 */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 30,  1, 54,  0, 10,  0,  0,  8,  0,  4,  5,  0,  3,  8, -8, 18, 73),  /* 50: M PUNCH C */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 30,  1, 54,  0, 10,  0,  0, 10, 18,  3,  1,  0,  3, 12,-15, 18, 73),  /* 51: M PUNCH C */
    ATTR( 96,  3,  0,  1,  0,  0,  0, 18, 81, 63,  2,  0,  4,  0, 12, 16,  1,  1,  0,  3, 10,-10, 28, 73),  /* 52: S V JP M P A, ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  2, 49, 63,  2, 15,  2,  0, 20, 16,  5, 11,  0,  3, 10,-10, 28, 73),  /* 53: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 18, 49, 63,  2, 15,  0,  0, 12, 16,  7, 11,  0,  3, 10,-10, 28, 73),  /* 54: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 18, 49, 63,  2, 15,  0,  0, 12, 17,  1,  1,  0,  3, 10,-10, 28, 73),  /* 55: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  9, 81, 63,  3, 15,  0,  0,  8, 16,  1,  0,  0,  3,  6, -6, 28, 73),  /* 56: not used by a script */
    ATTR( 95,  3,  0,  0,  0,  1, 42, 15, 81,  0,  1,  0,  7,  0, 64, 16,  2,  0,  0,  3, 16,-16, 65, 73),  /* 57: not used by a script */
    ATTR( 37,  1,  0,  1,  0,  0,  0, 29,  1, 63,  0, 12,  0,  0, 24, 17,  5,  4,  0,  3,  8, -8, 18,  0),  /* 58: FUSHIN P S */
    ATTR(107,  3,  0,  0,  0,  0, 41, 10, 81,  0,  1,  0,  7,  0, 20, 19,  2,  0,  0,  3, 28,-28, 65, 52),  /* 59: not used by a script */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 31,  1, 62,  0, 14,  0,  0,  8, 19,  6,  7,  0,  3, 11,-11, 39, 73),  /* 60: follow-up of UP P GUARD P L */
    ATTR( 96,  2,  0,  1,  0,  0,  0,  2, 49, 63,  2,  0,  4,  0, 10, 16,  1,  1,  0,  3,  8, -8, 28, 73),  /* 61: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    ATTR( 96,  3,  0,  1,  0,  0,  0, 18, 49, 63,  2,  0,  2,  0, 12, 16,  1,  1,  0,  3,  8, -8, 28, 73),  /* 62: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    ATTR(107,  2,  0,  0,  0,  0,  0, 10, 81,  0,  1,  0,  6,  0, 44, 19,  1,  0,  0,  3, 32,-32, 65, 73),  /* 63: not used by a script */
    ATTR(100,  0,  0,  0,  1,  0,  0,  7, 49, 62,  3, 12,  2,  0,  6, 16,  1,  1,  0,  3,  4, -4, 44, 73),  /* 64: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    ATTR(113,  1,  0,  0,  1,  0,  0,  8, 49, 62,  3, 13,  0,  0,  6, 17,  1,  1,  0,  3,  8, -8, 44, 73),  /* 65: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU) */
    ATTR(113,  0,  0,  0,  1,  0,  0,  9, 49, 62,  3, 13,  0,  0,  6, 17,  1,  1,  0,  3,  8, -8, 44, 73),  /* 66: ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    ATTR( 96,  0,  0,  1,  1,  0,  0, 23, 81, 63,  3,  0,  7,  0,  8, 16,  0,  0,  0,  3,  2, -2, 28, 73),  /* 67: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 96,  0,  0,  1,  1,  0,  0, 24, 81, 63,  3,  0,  7,  0,  8, 16,  0,  0,  0,  3,  2, -2, 28, 73),  /* 68: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 33,  1, 54,  0, 12,  0,  0,  8, 21,  1,  1,  0,  3,  8, -8, 18, 73),  /* 69: ATTACK 9 S: not started by a command */
    ATTR( 95,  2,  0,  0,  0,  0,  0, 19,  1, 63,  0, 15,  6,  0, 22, 18,  1,  4,  0,  3, 10,-10, 23, 73),  /* 70: OKIAGARI P S */
    ATTR( 32,  0,  0,  0,  0,  1,  0, 29, 81,  0,  0, 12,  0,  0,  0, 34,  0,  0,  1,  3, 12,-12, 66,  0),  /* 71: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    ATTR( 95,  2,  0,  1,  1,  0,  0, 27, 81, 63,  3,  0,  7,  0, 12, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 72: SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 95,  2,  0,  1,  1,  0,  0, 26, 81, 63,  3,  0,  7,  0, 11, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 73: SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 32,  0,  0,  0,  0,  1, 70, 29,  1,  0,  0, 11,  0,  0,  0, 16,  0,  0,  0,  3,  0,  0,  0,  0),  /* 74: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  1, 70, 29,  1,  0,  0, 10,  0,  0,  0, 16,  0,  0,  0,  3,  0,  0,  0,  0),  /* 75: not used by a script */
    ATTR( 91,  0,  0,  0,  0,  0, 70, 21, 81,  0,  0,  8,  0,  0,112, 34,  0,  0,  0,  3,  0,  0,  0,106),  /* 76: CATCH 19 */
    ATTR( 96,  2,  0,  0,  1,  0,  0, 22, 81, 63,  3,  0,  7,  0, 12, 52,  0,  0,  0,  3,  4, -4, 28, 73),  /* 77: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 95,  1,  0,  1,  1,  0,  0, 22, 81, 63,  3,  0,  7,  0, 11, 16,  0,  0,  0,  3,  4, -4, 28, 73),  /* 78: not used by a script */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 23, 81, 63,  3,  0,  7,  0,  8, 16,  0,  0,  0,  3,  2, -2, 28, 73),  /* 79: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 24, 81, 63,  3,  0,  7,  0,  8, 16,  0,  0,  0,  3,  2, -2, 28, 73),  /* 80: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 91,  2,  0,  1,  1,  0,  0, 25, 81, 63,  3, 12,  4,  0, 20, 16,  1,  0,  0,  3, 10,-10, 28, 73),  /* 81: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 28, 49, 62,  3, 15,  0,  0, 16, 16,  1, 14,  0,  3,  5, -3, 44, 73),  /* 82: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
    ATTR( 95,  0,  0,  1,  1,  0,  0, 28, 49, 62,  3,  0,  4,  0, 16, 26,  2,  1,  0,  3,  5, -5, 44, 73),  /* 83: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
};

extern const u16 gouki2_se_random_0[];

const u16* const gouki2_se_random_table[1] = {
    gouki2_se_random_0,  /* 0 */
};

const u16 gouki2_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

