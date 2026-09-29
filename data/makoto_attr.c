/*
 * MAKOTO_ATTR.C  Makoto's attack attributes and random sound lists
 *
 * makoto_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * makoto_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR makoto_catt_table[78] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  0,  0,  6, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  6,  0,  5, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 2: S PUNCH C */
    ATTR( 37,  1,  0,  0,  0,  0,  0,  2,  1, 62,  0, 12,  1,  0, 16, 30,  4,  4,  0,  3,  9, -9, 18, 73),  /* 3: M PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0,  2,  1, 62,  0, 12,  6,  0, 17, 18,  2,  4,  0,  3,  9, -9, 18, 73),  /* 4: M PUNCH C */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 13,  1,  0, 24, 17,  7,  7,  0,  3, 10,-12, 23, 73),  /* 5: L PUNCH A */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0, 30, 63,  6,  8,  0,  3, 10,-12, 23, 73),  /* 6: L PUNCH C */
    ATTR( 38,  1,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0,  4, 16,  1,  9,  0,  3,  8,-12, 23, 73),  /* 7: follow-up of L PUNCH C */
    ATTR( 37,  1,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0,  4, 18,  1,  9,  0,  3,  8,-12, 23, 73),  /* 8: follow-up of L PUNCH C */
    ATTR( 37,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 13,  6,  0,  8, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 9: S KICK A */
    ATTR( 37,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 10,  6,  0,  7, 16,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: not used by a script */
    ATTR( 38,  1,  0,  0,  0,  0,  0,  2,  1, 62,  0, 14,  6,  0, 18, 17,  3,  4,  0,  3,  9, -9, 34, 73),  /* 11: M KICK A */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  2,  1, 62,  0, 13,  6,  0, 20, 18,  4,  4,  0,  3,  9, -9, 34, 73),  /* 12: M KICK C */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0, 26, 26,  3,  7,  0,  3, 12,-12, 39, 73),  /* 13: L KICK A */
    ATTR( 32,  0,  0,  0,  0,  0,  0,  3,  1, 63,  0, 12,  0,  0,  0, 19,  5,  7,  0,  3,  0, 18,  4,  0),  /* 14: L KICK A */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0, 24, 19,  2,  7,  0,  3, 12,-12, 39, 73),  /* 15: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  6,  0,  4,  0,  1,  1,  0,  3,  7, -7, 13, 72),  /* 16: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0,  2,  1, 63,  0, 12,  6,  0, 14, 17,  2,  4,  0,  3,  9, -9, 18, 73),  /* 17: KAGAMI P A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  7,  1, 45,  0, 10,  6,  0, 20, 17,  1,  7,  0,  3, 11,-11, 39, 73),  /* 18: KAGAMI P A */
    ATTR( 37,  0,  0,  0,  0,  0,  0,  1,  1, 45,  0, 13,  6,  0,  6, 16,  1,  1,  0,  3,  7,  7, 29, 72),  /* 19: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0,  2,  1, 63,  0, 12,  6,  0, 18, 16,  2,  4,  0,  3,  9, -9, 34, 73),  /* 20: KAGAMI K A */
    ATTR( 37,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  6,  0,  7, 16,  2,  1,  0,  3,  7, -7, 29, 72),  /* 21: S KICK C */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  7,  1, 45,  0, 10,  6,  0, 24, 17,  2,  7,  0,  3, 11,-11, 39, 73),  /* 22: L KICK C */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 14,  6,  0, 26, 19,  7,  7,  0,  3, 12,-12, 39, 73),  /* 23: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0,  4,  1, 54,  0, 12,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 24: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0,  5,  1, 54,  0, 12,  2,  0, 16, 21,  5,  4,  0,  3,  8, -8, 18, 73),  /* 25: V JUMP P M A */
    ATTR( 33,  2,  0,  1,  0,  0,  0,  8,  1, 54,  0, 12,  2,  0, 26, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 26: V JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0,  4,  1, 54,  0, 12,  2,  0, 12, 21,  3,  1,  0,  3,  7, -7, 29, 72),  /* 27: V JUMP K S A, F JUMP K S A, B JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0,  5,  1, 54,  0, 12,  2,  0, 18, 21,  4,  4,  0,  3,  8, -8, 34, 73),  /* 28: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0,  6,  1, 54,  0, 12,  2,  0, 26, 21,  5,  7,  0,  3,  9, -9, 39, 73),  /* 29: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0,  4,  1, 54,  0, 10,  2,  0, 10, 21,  3,  1,  0,  3,  7, -7, 13, 72),  /* 30: F JUMP P S A, B JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0,  5,  1, 54,  0, 10,  2,  0, 14, 22,  5,  4,  0,  3,  6, -6, 14, 73),  /* 31: F JUMP P M A, B JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0,  8,  1, 54,  0, 12,  2,  0, 26, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 32: F JUMP P L A, B JUMP P L A */
    ATTR( 32,  2,  0,  1,  0,  0,  0,  8,  1, 54,  0, 10,  2,  0, 30, 21,  7,  7,  0,  3,  9, -9, 23, 73),  /* 33: F JUMP P L A, B JUMP P L A */
    ATTR( 32,  1,  0,  0,  0,  0,  0,  5,  1, 54,  0, 10,  0,  0,  8, 16,  1,  1,  0,  3,  8, -8, 18, 73),  /* 34: ATTACK 1 S: not started by a command */
    ATTR( 38,  1,  0,  0,  0,  0,  0,  2,  1, 62,  0, 14,  6,  0, 14, 17,  3,  4,  0,  3,  9, -9, 34, 73),  /* 35: follow-up of S KICK A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 33,  1, 63,  0,  3,  0,  0,  0, 48,  0,  0,  0,  3,  8, -8,  0,  0),  /* 36: not used by a script */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 33, 33, 54,  1,  9,  0,  0, 20, 18,  3, 11,  0,  3, 12,-15, 24, 73),  /* 37: S V JP S P A, ATTACK 3 S: 214+P light (plain script) */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 17, 49, 63,  2,  0,  3,  0, 24, 16, 14, 12,  0,  3, 12,-12, 24, 73),  /* 38: ATTACK 4 S: 623+P light (plain script) */
    ATTR( 32,  0,  0,  0,  0,  0,  0,  1,  1, 63,  0, 12,  0,  0,  2, 16,  1,  1,  0,  3,  7, -7, 13, 72),  /* 39: ATTACK 5 S: not started by a command */
    ATTR( 37,  2,  0,  0,  0,  1,  0,  3,  1,  0,  0, 12,  0,  0,  0, 18,  0,  0,  1,  3, 10,-10,  0,  0),  /* 40: TUKAMIKAKARI A, ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    ATTR( 36,  2,  0,  0,  0,  0, 74, 16,  1, 63,  0, 12,  0,  0, 18, 20,  8, 13,  0,  3, 10,-10,115, 73),  /* 41: CATCH 1 */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 32, 81, 54,  2, 10,  0,  0, 20, 21,  4,  0,  0,  3,  9, -9, 23, 73),  /* 42: ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1), ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1), ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    ATTR( 96,  1,  0,  0,  0,  0,  0, 21, 81, 62,  2, 13,  0,  0,  8, 16,  1,  0,  0,  3,  6,-12, 37, 72),  /* 43: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    ATTR( 95,  2,  0,  0,  0,  0,  0, 22, 81, 62,  2, 14,  0,  0, 16, 16,  2,  0,  0,  3,  6,-12, 39, 73),  /* 44: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    ATTR( 96,  3,  0,  0,  0,  0,  0,  9, 81, 63,  1,  0,  7,  0, 34, 16,  4,  0,  0,  3, 12,-12, 28, 73),  /* 45: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    ATTR( 36,  3,  0,  0,  0,  1, 78,  3,  1,  0,  0, 13,  0,  0,  0, 49,  0, 13,  0,  3, 10,-12, 28, 73),  /* 46: not used by a script */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  3, 33,  0,  0, 13,  0,  0,  6, 48,  4, 13,  0,  3,  4, -8,  0,  0),  /* 47: CATCH 4 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 10, 49, 62,  2, 12,  2,  0, 20, 16,  4, 10,  0,  3,  8,-12, 24, 73),  /* 48: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 11, 49, 62,  2, 12,  3,  0, 22, 16,  5, 10,  0,  3,  8,-12, 24, 73),  /* 49: ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 12, 49, 62,  2, 12,  3,  0, 24, 17,  6, 10,  0,  3,  8,-12, 28, 73),  /* 50: ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  3,  0,  0,  1,  0,  0, 13, 49, 62,  1, 12,  3,  0, 26, 18,  7, 10,  0,  3,  8,-12, 28, 73),  /* 51: ATTACK 11 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  3,  0,  0,  1,  0,  0, 14, 49, 62,  1, 12,  3,  0, 28, 18,  8, 10,  0,  3,  8,-12, 28, 73),  /* 52: ATTACK 11 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 36,  0,  0,  0,  0,  1, 79,  3,  1, 63,  0,  1,  0,  0,  6, 54,  1,  0,  0,  3, 10,-10, 39,  0),  /* 53: CATCH 3 */
    ATTR( 36,  0,  0,  0,  0,  1, 80,  3,  1, 63,  0,  9,  0,  0,  4, 54,  1,  0,  0,  3, 10,-10, 18, 73),  /* 54: CATCH 3 */
    ATTR( 36,  2,  0,  0,  0,  0, 81,  3,  1, 63,  0,  8,  0,  0, 20, 54,  3, 13,  0,  3, 10,-10,115, 73),  /* 55: CATCH 3 */
    ATTR( 37,  3,  0,  0,  1,  0,  0,  3, 80, 63,  1, 10,  7,  0, 30, 52,  2,  0,  0,  3,  2,-38, 28, 73),  /* 56: ATTACK 9 L: SA I 23623+P (plain script) */
    ATTR( 32,  1,  0,  0,  1,  1,  0,  2, 80, 63,  1, 11,  7,  0,  8, 54,  2,  0,  0,  3,  1, -4, 22, 73),  /* 57: ATTACK 11 SP: after SA I 23623+P (plain script) */
    ATTR( 38,  1,  0,  0,  1,  1,  0,  2, 80, 63,  1, 12,  7,  0,  8, 54,  2,  0,  0,  3,  1, -4, 22, 73),  /* 58: ATTACK 11 SP: after SA I 23623+P (plain script) */
    ATTR( 35,  1,  0,  0,  1,  1,  0,  2, 80, 63,  1, 14,  7,  0,  8, 54,  2,  0,  0,  3,  1,-26, 22, 73),  /* 59: ATTACK 11 SP: after SA I 23623+P (plain script) */
    ATTR(107,  3,  0,  0,  1,  0, 99, 15, 80, 63,  1, 15,  7,  0, 60, 19,  2,  0,  0,  3, 34,-34, 97, 52),  /* 60: ATTACK 11 SP: after SA I 23623+P (plain script) */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 18, 49, 63,  2,  0,  3,  0, 28, 16, 15, 12,  0,  3, 12,-12, 24, 73),  /* 61: ATTACK 4 M: 623+P medium (plain script) */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 19, 49, 63,  2,  0,  3,  0, 32, 16, 15, 12,  0,  3, 12,-12, 28, 73),  /* 62: ATTACK 4 L: 623+P heavy (plain script) */
    ATTR( 96,  3,  0,  0,  0,  0,  0, 20, 49, 63,  2,  0,  3,  0, 28, 16, 10,  0,  0,  3, 12,-12, 28, 73),  /* 63: ATTACK 4 SP: EX 623+PP (plain script) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 33, 33, 54,  1,  9,  0,  0, 22, 18,  5, 11,  0,  3, 12,-15, 28, 73),  /* 64: ATTACK 3 M: 214+P medium (plain script) */
    ATTR( 40,  3,  0,  0,  0,  0,  0, 33, 33, 54,  1,  9,  0,  0, 28, 18,  6, 11,  0,  3, 15,-20, 28, 73),  /* 65: ATTACK 3 L: 214+P heavy (plain script) */
    ATTR( 40,  3,  0,  0,  0,  0,  0, 33, 33, 54,  1,  9,  0,  0, 32, 18,  4,  0,  0,  3, 15,-24, 28, 73),  /* 66: ATTACK 3 SP: EX 214+PP (plain script) */
    ATTR( 93,  3,  0,  0,  1,  0,  0, 14, 49, 62,  2, 12,  3,  0, 32, 20,  8,  0,  0,  3,  8,-12, 28, 73),  /* 67: ATTACK 12 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  3,  0,  0,  1,  0,  0, 23, 81, 62,  2, 12,  0,  0, 40, 20,  8,  0,  0,  3, 12,-12, 28, 73),  /* 68: ATTACK 13 M: not started by a command */
    ATTR( 38,  1,  0,  1,  0,  0,  0, 24, 81, 54,  2, 14,  0,  0, 10, 17,  4,  0,  0,  3, 10,-10, 39, 72),  /* 69: ATTACK 7 S: not started by a command */
    ATTR( 37,  2,  0,  1,  0,  0,  0, 25, 81, 54,  2, 14,  0,  0, 10, 17,  4,  0,  0,  3,  8,-14, 40, 73),  /* 70: ATTACK 7 S: not started by a command */
    ATTR( 97,  3,  0,  1,  0,  0,  0, 26, 81, 54,  2,  9,  1,  0, 16, 20,  6,  0,  0,  3, 14,-14, 44, 73),  /* 71: ATTACK 7 S: not started by a command */
    ATTR( 37,  2,  0,  1,  0,  0,  0, 27, 49, 54,  2,  9,  0,  0, 28, 18,  6, 14,  0,  3,  8, -8, 40, 73),  /* 72: ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 37,  3,  0,  1,  0,  0,  0, 28, 49, 54,  2,  9,  0,  0, 30, 18,  6, 14,  0,  3,  8, -8, 40, 73),  /* 73: ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 97,  3,  0,  1,  0,  0,  0, 29, 49, 54,  2,  9,  0,  0, 32, 19,  6, 14,  0,  3,  8, -8, 44, 73),  /* 74: air 214+K heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 37,  2,  0,  1,  0,  0,  0, 30, 49, 54,  2, 10,  0,  0, 16, 18,  4,  0,  0,  3,  6, -6, 40, 73),  /* 75: air EX 214+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 97,  3,  0,  1,  0,  0,  0, 31, 49, 54,  2,  9,  0,  0, 20, 19,  4,  0,  0,  3,  8, -8, 44, 73),  /* 76: air EX 214+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    ATTR( 33,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 12,  6,  0, 16, 26,  3,  9,  0,  3, 12,-12, 39, 73),  /* 77: follow-up of M KICK C */
};

extern const u16 makoto_se_random_0[];

const u16* const makoto_se_random_table[1] = {
    makoto_se_random_0,  /* 0 */
};

const u16 makoto_se_random_0[16] = {
    0x01CC, 0x01CF, 0x01CF, 0x01DE, 0x01DE, 0x01CF, 0x01CC, 0x01D0,
    0x01D0, 0x01DE, 0x01D0, 0x01CC, 0x01D0, 0x01CC, 0x01DE, 0x01CF,
};

