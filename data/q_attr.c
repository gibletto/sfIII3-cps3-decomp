/*
 * Q_ATTR.C  Q's attack attributes and random sound lists
 *
 * q_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * q_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR q_catt_table[77] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 95,  2,  0,  0,  0,  0, 34, 36, 49,  0,  0, 10,  0,  0,  0, 33,  0,  2,  1,  3,  8, -8, 66,  0),  /* 1: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    ATTR( 95,  2,  0,  0,  0,  0, 82,  8, 49,  0,  0, 15,  1,  0, 22, 49,  5,  7,  0,  3, 14,-14,118, 79),  /* 2: CATCH 13 */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 13,  0,  0,  7, 32,  1,  1,  0,  3,  7, -7, 13, 72),  /* 3: S PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 14,  6,  0,  6, 32,  1,  1,  0,  3,  7, -7, 13, 72),  /* 4: S PUNCH B */
    ATTR( 95,  2,  0,  0,  0,  0, 82,  9, 49,  0,  0, 15,  1,  0, 24, 49,  5,  8,  0,  3, 15,-15,118, 78),  /* 5: CATCH 14 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 12,  6,  0, 18, 44,  4,  2,  0,  3,  9,-14, 18, 73),  /* 6: M PUNCH A */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  2,  1, 62,  0, 14,  6,  0, 24, 35,  7,  3,  0,  3,  8,-17, 23, 73),  /* 7: L PUNCH C */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  3,  1, 62,  0, 14,  6,  0, 22, 34,  6,  3,  0,  3,  8,-16, 23, 73),  /* 8: L PUNCH C */
    ATTR( 37,  2,  0,  0,  0,  0,  0,  2,  1, 62,  0, 12,  6,  0, 22, 35,  7,  3,  0,  3,  8, -8, 23, 73),  /* 9: L PUNCH A, L PUNCH C */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 10,  6,  0,  8, 32,  1,  1,  0,  3,  7, -7, 29, 72),  /* 10: S KICK A */
    ATTR( 95,  2,  0,  0,  0,  0, 82, 10, 49,  0,  0, 15,  1,  0, 26, 49,  5,  9,  0,  3, 16,-16,118, 78),  /* 11: CATCH 15 */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 13,  6,  0, 20, 33,  1,  2,  0,  3,  9, -9, 34, 73),  /* 12: M KICK A */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 35,  1, 62,  0, 13,  6,  0, 22, 33,  3,  2,  0,  3,  9, -9, 34, 73),  /* 13: M KICK B */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 38,  1, 54,  0, 11,  0,  0,  8, 32,  1,  1,  0,  3,  8, -8, 34, 73),  /* 14: ATTACK 10 S: not started by a command */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 35,  1, 62,  0, 14,  0,  0, 20, 34,  6,  2,  0,  3, 10,-14, 18, 73),  /* 15: M PUNCH C */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  5, 49, 62,  3, 12,  4,  0, 28, 36,  8,  6,  0,  3, 10,-10, 28, 73),  /* 16: not used by a script */
    ATTR( 34,  3,  0,  0,  1,  0,  0,  4,  1, 62,  0, 11,  6,  0, 26, 55,  7,  3,  0,  3, 10,-10,121, 73),  /* 17: L KICK C */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 14, 17, 62,  0, 12,  0,  0, 30, 49,  4,  3,  0,  3, 13,-17,121, 73),  /* 18: L KICK A */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 63,  0, 12,  6,  0,  4, 33,  1,  1,  0,  3,  7, -7, 13, 72),  /* 19: KAGAMI P A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 63,  0, 12,  6,  0, 18, 33,  4,  2,  0,  3,  9,-10, 18, 73),  /* 20: KAGAMI P A */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 13,  1, 45,  0, 15,  6,  0, 24, 33,  2,  3,  0,  3, 11,-12, 23, 73),  /* 21: KAGAMI P A */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  5, 49, 54,  3, 11,  4,  0, 28, 36,  8,  6,  0,  3, 10,-10, 28, 73),  /* 22: not used by a script */
    ATTR( 37,  0,  0,  0,  0,  0,  0, 34,  1, 45,  0, 13,  6,  0,  4, 33,  1,  1,  0,  3,  7,  7, 29, 72),  /* 23: KAGAMI K A */
    ATTR( 37,  1,  0,  0,  0,  0,  0, 35,  1, 45,  0, 12,  6,  0, 16, 32,  1,  2,  0,  3,  9, -9, 34, 73),  /* 24: KAGAMI K A */
    ATTR( 89,  2,  0,  0,  0,  0,  0,  1,  1, 45,  0, 12,  6,  0, 26, 32,  1,  3,  0,  3, 11,-11, 39, 73),  /* 25: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 12,  2,  0,  8, 37,  3,  1,  0,  3,  7, -7, 13, 72),  /* 26: V JUMP P S A, F JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 39,  1, 54,  0, 12,  2,  0, 20, 37,  5,  2,  0,  3,  8, -8, 18, 73),  /* 27: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 11,  1, 54,  0, 11,  2,  0, 26, 37,  7,  3,  0,  3,  9, -9, 23, 73),  /* 28: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 37,  1, 54,  0, 12,  2,  0,  8, 37,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 39,  1, 54,  0, 12,  2,  0, 18, 37,  4,  2,  0,  3,  8, -8, 34, 73),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 12,  1, 54,  0,  9,  2,  0, 29, 37,  6,  3,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A, S V JP S P A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 12,  1, 54,  0,  9,  2,  0, 26, 37,  5,  3,  0,  3,  9, -9, 39, 73),  /* 32: V JUMP K L A, S V JP S P A */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 12,  2,  0, 10, 63,  2,  7,  0,  3,  5,-12, 28, 73),  /* 33: ATTACK 4 M: 214+P medium (plain script) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 12,  2,  0, 10, 63,  1,  1,  0,  3,  5,-12, 28, 73),  /* 34: ATTACK 4 M: 214+P medium (plain script) */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 12,  2,  0, 10, 32,  2,  1,  0,  3,  7,-12, 28, 73),  /* 35: ATTACK 4 M: 214+P medium (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 48, 62,  3, 13,  2,  0, 10, 63,  2,  7,  0,  3,  5,-12, 28, 73),  /* 36: ATTACK 4 L: 214+P heavy (plain script) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 34, 48, 62,  3, 12,  2,  0, 10, 63,  1,  1,  0,  3,  5,-12, 28, 73),  /* 37: ATTACK 4 L: 214+P heavy (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 48, 62,  3, 13,  2,  0, 10, 32,  2,  1,  0,  3,  7,-12, 28, 73),  /* 38: ATTACK 4 L: 214+P heavy (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 48, 62,  3,  0,  0,  0, 10, 63,  3,  7,  0,  3,  5,-12, 28, 73),  /* 39: not used by a script */
    ATTR( 36,  2,  0,  0,  1,  0,  0, 34, 48, 62,  3, 12,  0,  0, 10, 63,  3,  1,  0,  3,  5,-12, 28, 73),  /* 40: not used by a script */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 48, 62,  3, 13,  1,  0, 10, 63,  3,  1,  0,  3,  7,-12, 28, 73),  /* 41: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0, 54,  6,  1, 63,  0, 10,  0,  0, 28, 38,  6, 13,  0,  3, 10,-10, 55, 73),  /* 42: CATCH 1, CATCH 2 */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 36,  1,  0,  0, 10,  0,  0,  0, 34,  0,  0,  1,  3, 10,-10,  0,  0),  /* 43: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    ATTR( 96,  2,  0,  0,  0,  0, 75,  7,  1, 63,  0, 10,  0,  0, 22, 32,  8, 13,  1,  3, 18,-18,118, 51),  /* 44: CATCH 5, CATCH 6 */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 15, 49, 62,  3, 12,  2,  0, 24, 36,  5,  8,  0,  3, 10,-11, 28, 73),  /* 45: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 16, 49, 62,  3, 12,  2,  0, 28, 36,  6,  8,  0,  3, 11,-12, 28, 73),  /* 46: ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17, 49, 62,  3, 12,  2,  0, 31, 36,  7,  8,  0,  3, 12,-13, 28, 73),  /* 47: ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) */
    ATTR(111,  2,  0,  0,  0,  0,  0, 18, 49, 62,  3, 13,  2,  0, 32, 33,  4,  0,  0,  3, 13,-15, 44, 73),  /* 48: ATTACK 1 SP: EX [4]6+PP (routine Att_SLIDE_and_JUMP) */
    ATTR( 89,  3,  0,  0,  0,  0,  0, 20, 49, 45,  3, 10,  2,  0, 22, 32,  1,  6,  0,  3, 10,-10, 28, 73),  /* 49: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) */
    ATTR( 89,  3,  0,  0,  0,  0,  0, 21, 49, 45,  3, 10,  2,  0, 25, 32,  1,  6,  0,  3, 11,-11, 28, 73),  /* 50: ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
    ATTR( 89,  3,  0,  0,  0,  0,  0, 22, 49, 45,  3, 10,  2,  0, 28, 32,  1,  6,  0,  3, 12,-12, 28, 73),  /* 51: ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 22, 49, 45,  3, 10,  2,  0, 18, 32,  1,  0,  0,  3, 11,-11, 28, 73),  /* 52: ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 93,  2,  0,  0,  0,  0,  0,  5, 49, 62,  3, 12,  2,  0, 16, 33,  2,  0,  0,  3, 16,-16, 28, 73),  /* 53: ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 36, 49, 62,  3, 12,  2,  0,  6, 54,  1,  0,  0,  3,  6, -7, 28, 73),  /* 54: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 36, 49, 62,  3, 12,  2,  0,  6, 54,  2,  0,  0,  3,  6, -7, 28, 73),  /* 55: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 49, 62,  3, 13,  2,  0,  8, 54,  2,  0,  0,  3,  6, -7, 28, 73),  /* 56: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 34, 49, 62,  3, 12,  2,  0,  8, 54,  2,  0,  0,  3,  6, -7, 28, 73),  /* 57: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 35,  2,  0,  0,  1,  0,  0, 34, 49, 62,  3,  0,  2,  0,  8, 54,  2,  0,  0,  3,  6, -7, 28, 73),  /* 58: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 36,  2,  0,  0,  1,  0,  0, 34, 49, 62,  3, 12,  2,  0,  8, 54,  2,  0,  0,  3,  7, -7, 28, 73),  /* 59: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 96,  2,  0,  0,  0,  0,  0, 23, 49, 62,  3, 14,  2,  0, 10, 63,  2,  0,  0,  3, 14,-14, 28, 73),  /* 60: ATTACK 4 SP: EX 214+PP (plain script) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 24, 81, 62,  2, 12,  2,  0, 15, 34,  1,  0,  0,  3, 10,-10, 28, 73),  /* 61: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 37,  2,  0,  0,  0,  0,  0, 25, 81, 45,  2, 10,  2,  0, 14, 34,  1,  0,  0,  3, 11,-11, 28, 73),  /* 62: ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR(111,  2,  0,  0,  0,  0,  0, 26, 81, 62,  1, 13,  4,  0, 26, 33,  3,  0,  0,  3, 16,-16, 44, 73),  /* 63: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 89,  2,  0,  0,  0,  0,  0, 28,  1, 63,  0, 12,  6,  0, 28, 33,  1,  3,  0,  3, 11,-11,121, 73),  /* 64: L KICK C */
    ATTR( 91,  2,  0,  0,  1,  0,100, 29, 80, 63,  1, 13,  0,  0, 30, 32,  2,  0,  0,  3,-38,-74, 65, 73),  /* 65: ATTACK 7 S: SA II 23623+P (plain script) */
    ATTR(114,  2,  0,  0,  1,  0,101, 30, 80, 54,  1,  8,  0,  0, 66, 63,  8,  0,  0,  3, -2, -6, 65, 79),  /* 66: ATTACK 7 S: SA II 23623+P (plain script) */
    ATTR( 91,  2,  1,  0,  1,  0,  0, 31, 80, 63,  2, 13,  0,  0, 70, 33, 12,  0,  0,  3, 24,-30,145, 79),  /* 67: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    ATTR( 91,  2,  1,  0,  1,  0,  0, 32, 81,  0,  3, 13,  0,  0, 94, 33, 10,  0,  0,  3, 20,-20,  0, 79),  /* 68: CATCH 17 */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 11,  2,  0, 10, 63,  1,  7,  0,  3,  5,-12, 28, 73),  /* 69: ATTACK 4 S: 214+P light (plain script) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 13,  2,  0, 10, 63,  1,  1,  0,  3,  5,-12, 28, 73),  /* 70: ATTACK 4 S: 214+P light (plain script) */
    ATTR( 38,  2,  0,  0,  0,  0,  0, 36, 48, 62,  3, 11,  2,  0, 10, 32,  1,  1,  0,  3,  7,-12, 28, 73),  /* 71: ATTACK 4 S: 214+P light (plain script) */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 40,  1, 62,  0, 14,  6,  0, 26, 36,  7,  3,  0,  3,  9, -9, 23, 73),  /* 72: L PUNCH A */
    ATTR( 93,  2,  0,  0,  0,  0,  0, 41,  1, 62,  0, 14,  6,  0, 24, 36,  6,  3,  0,  3,  9, -9, 23, 73),  /* 73: L PUNCH A */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 42, 49, 54,  3, 11,  2,  0, 20, 35,  4,  5,  0,  3, 10,-10, 28, 73),  /* 74: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 43, 49, 54,  3, 11,  2,  0, 23, 35,  4,  5,  0,  3, 11,-11, 28, 73),  /* 75: ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 36,  2,  0,  0,  0,  0,  0, 44, 49, 54,  3, 11,  2,  0, 26, 35,  4,  5,  0,  3, 12,-12, 28, 73),  /* 76: ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
};

extern const u16 q_se_random_0[];

const u16* const q_se_random_table[1] = {
    q_se_random_0,  /* 0 */
};

const u16 q_se_random_0[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

