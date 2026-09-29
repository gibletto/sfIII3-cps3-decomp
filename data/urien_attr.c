/*
 * URIEN_ATTR.C  Urien's attack attributes and random sound lists
 *
 * urien_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * urien_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR urien_catt_table[57] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 18,  1, 63,  0, 11,  0,  0,  4, 32,  1,  1,  0,  3,  7, -7, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 62,  0, 14,  0,  0, 16, 34,  4,  4,  0,  3,  9, -9, 18, 72),  /* 2: M PUNCH C */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 62,  0, 12,  0,  0, 16, 34,  4,  4,  0,  3,  9, -9, 18, 72),  /* 3: M PUNCH A, follow-up of S PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 20,  1, 63,  0, 12,  0,  0, 10, 35,  5,  7,  0,  3, 11,-11, 23, 73),  /* 4: not used by a script */
    ATTR( 36,  2,  0,  0,  0,  0,  0,  9,  1, 62,  0, 10,  0,  0, 26, 35,  7,  7,  0,  3, 11,-11, 23, 73),  /* 5: L PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 18,  1, 63,  0, 11,  0,  0,  6, 32,  1,  1,  0,  3,  7, -7, 29, 72),  /* 6: S KICK A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 18,  1, 63,  0, 12,  0,  0, 10, 32,  3,  1,  0,  3,  7, -7, 29,  0),  /* 7: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 62,  0, 12,  0,  0, 16, 34,  4,  4,  0,  3,  9, -9, 34, 72),  /* 8: M KICK A, KAGAMI P A */
    ATTR( 32,  2,  0,  0,  0,  0,  0,  9,  1, 54,  0, 11,  0,  0, 10, 35,  1,  1,  0,  3, 11,-11, 39, 73),  /* 9: L KICK A */
    ATTR( 36,  2,  0,  0,  0,  0,  0,  9,  1, 54,  0,  9,  0,  0, 18, 35,  4,  8,  0,  3, 11,-11, 39, 73),  /* 10: L KICK A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 20,  1, 63,  0, 11,  0,  0, 30, 36,  7,  7,  0,  3, 11,-11, 39,  0),  /* 11: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 18,  1, 63,  0, 13,  0,  0,  4, 32,  1,  1,  0,  3,  7, -7, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 18,  1, 63,  0, 14,  0,  0, 12, 34,  1,  4,  0,  3,  9, -9, 18, 72),  /* 13: KAGAMI P A */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  8,  1, 63,  0, 15,  1,  0,  8, 33,  2,  1,  0,  3, 11,-11, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 18,  1, 45,  0, 11,  0,  0,  4, 33,  1,  1,  0,  3,  7, -7, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 45,  0, 12,  0,  0, 14, 34,  1,  4,  0,  3,  9, -9, 34, 72),  /* 16: KAGAMI K A */
    ATTR( 89,  0,  0,  0,  0,  0,  0,  1,  1, 45,  0, 13,  0,  0, 20, 36,  1,  7,  0,  3, 11,-11, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 21,  1, 54,  0,  9,  2,  0, 10, 37,  3,  1,  0,  3,  7, -7, 13, 72),  /* 18: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 22,  1, 54,  0, 11,  2,  0, 18, 38,  4,  4,  0,  3,  8, -8, 18, 72),  /* 19: V JUMP P M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 23,  1, 54,  0, 10,  2,  0, 26, 39,  5,  7,  0,  3,  9, -9, 23, 73),  /* 20: V JUMP P L A, ATTACK 4 M: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 20,  1,  0,  0, 11,  0,  0,  0, 34,  0,  0,  1,  3,  8, -8,  0, 73),  /* 21: TUKAMIKAKARI A */
    ATTR( 32,  1,  0,  0,  0,  0, 54,  2,  1, 63,  0, 10,  0,  0, 28, 38,  4, 13,  0,  3, 10,-10, 55, 73),  /* 22: CATCH 1 */
    ATTR( 32,  2,  0,  0,  0,  0, 38,  4,  1, 63,  0,  6,  0,  0,  5, 36,  2,  1,  0,  3, 12,-12, 71, 72),  /* 23: CATCH 2 */
    ATTR( 39,  2,  0,  1,  0,  0,  0,  5, 49, 54,  2, 10,  0,  0, 22, 32,  5, 12,  0,  3, 10,-10, 44, 73),  /* 24: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) */
    ATTR( 35,  2,  0,  1,  0,  0,  0,  6, 49, 54,  2, 13,  0,  0,  6, 36,  5, 12,  0,  3, 12,-16, 44, 73),  /* 25: not used by a script */
    ATTR( 93,  2,  0,  1,  0,  0,  0, 12, 49, 62,  2, 13,  2,  0, 24, 36,  6, 10,  0,  3, 12,-12, 28, 73),  /* 26: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  0,  0,  0,  0,  6,  1, 62,  3, 12,  0,  0,  6, 36,  1,  1,  0,  3, 12,-12, 28, 73),  /* 27: not used by a script */
    ATTR( 37,  2,  0,  0,  1,  0,  0,  7,  1, 63,  0, 13,  0,  0, 14, 32,  2,  8,  0,  3, 11,-11, 23, 73),  /* 28: KAGAMI P A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 21,  1, 54,  0, 12,  2,  0, 10, 37,  3,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 22,  1, 54,  0, 13,  2,  0, 18, 38,  4,  4,  0,  3,  8, -8, 34, 72),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 23,  1, 54,  0, 11,  2,  0, 26, 39,  5,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR(110,  1,  0,  0,  1,  0, 53, 10,  1, 62,  2,  2,  0,  0, 24, 39,  2,  7,  0,  3, 16,-16, 28, 60),  /* 32: ATTACK 2 M: not started by a command */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 11,  1, 62,  2, 11,  0,  0, 16, 39,  5,  1,  0,  3, 12,-12, 28, 72),  /* 33: ATTACK 2 M: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 22,  1, 54,  0,  9,  0,  0,  8, 32,  1,  1,  0,  3,  8, -8, 18, 73),  /* 34: ATTACK 7 M: not started by a command */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 13, 49, 62,  3, 12,  0,  0, 24, 43,  3,  7,  0,  3, 12,-12, 28, 73),  /* 35: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 13, 49, 62,  3, 12,  0,  0, 27, 43,  4,  7,  0,  3, 12,-12, 28, 73),  /* 36: ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 13, 49, 62,  3, 12,  0,  0, 30, 43,  5,  7,  0,  3, 12,-12, 28, 73),  /* 37: ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 62,  0, 13,  0,  0, 18, 34,  4,  4,  0,  3,  9, -9, 34, 72),  /* 38: M KICK C */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 13, 81, 62,  2, 12,  0,  0, 10, 35,  0,  0,  0,  3,  4,-12, 28, 73),  /* 39: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 13, 81, 62,  2, 12,  0,  0, 16, 35,  0,  0,  0,  3,  4,-12, 28, 73),  /* 40: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR(110,  1,  0,  0,  1,  0, 53, 10, 81, 62,  2,  2,  4,  0, 46, 39,  0,  0,  0,  3, 16,-16, 28, 60),  /* 41: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 91,  2,  0,  0,  1,  0,  0, 11, 81, 62,  2, 11,  4,  0, 20, 39,  5,  0,  0,  3, 12,-12, 28, 72),  /* 42: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    ATTR( 33,  2,  0,  0,  0,  0,  0, 13, 49, 62,  3, 12,  0,  0, 18, 34,  4,  0,  0,  3,  4,-12, 28, 73),  /* 43: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    ATTR( 34,  2,  0,  0,  0,  0,  0, 13, 49, 62,  3, 12,  0,  0, 16, 32,  4,  0,  0,  3,  9,-12, 28, 73),  /* 44: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    ATTR( 93,  2,  2,  1,  0,  0,  0, 17, 49, 62,  2, 13,  0,  0, 16, 36,  5,  0,  0,  3, 12,-12, 28, 73),  /* 45: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    ATTR( 89,  3,  0,  0,  0,  1,  0, 16,  1,  9,  0,  8,  2,  0,  1, 36,  0,  1,  0,  3, -1, -1,  0, 80),  /* 46: ATTACK 8 SP: not started by a command */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  5, 49, 54,  2, 10,  0,  0,  6, 34,  2,  0,  0,  3,  8, -8, 44, 73),  /* 47: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2) */
    ATTR( 35,  2,  0,  1,  0,  0,  0,  6, 49, 54,  2, 13,  0,  0, 22, 36,  6,  0,  0,  3, 16,-16, 44, 73),  /* 48: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2) */
    ATTR( 38,  2,  0,  0,  0,  0,  0,  7,  1, 63,  0, 13,  2,  0,  6, 35,  1,  8,  0,  3, 11,-11, 23, 73),  /* 49: no name */
    ATTR( 95,  2,  0,  0,  0,  0,  0,  8,  1, 63,  0, 15,  2,  0,  6, 35,  1,  1,  0,  3, 11,-11, 23, 73),  /* 50: no name */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 62,  0, 12,  0,  0,  8, 34,  2,  4,  0,  3,  9, -9, 18, 72),  /* 51: follow-up of S PUNCH A */
    ATTR( 93,  2,  0,  1,  0,  0,  0, 12, 49, 62,  2, 13,  2,  0, 26, 36,  7, 10,  0,  3, 12,-12, 28, 73),  /* 52: ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU) */
    ATTR( 93,  2,  0,  1,  0,  0,  0, 12, 49, 62,  2, 13,  2,  0, 28, 36,  8, 10,  0,  3, 12,-12, 28, 73),  /* 53: ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) */
    ATTR( 36,  2,  0,  0,  0,  0,  0,  9,  1, 54,  0, 10,  0,  0, 24, 35,  1,  7,  0,  3, 11,-11, 23, 73),  /* 54: L PUNCH C */
    ATTR( 36,  2,  0,  0,  0,  0,  0,  9,  1, 54,  0, 10,  0,  0, 12, 35,  1,  4,  0,  3, 11,-11, 23, 73),  /* 55: follow-up of M PUNCH C */
    ATTR( 93,  2,  2,  1,  0,  0,  0, 17, 49, 62,  2, 13,  1,  0, 16, 36,  5,  0,  0,  3, 12,-12, 28, 73),  /* 56: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
};

extern const u16 urien_se_random_0[];

const u16* const urien_se_random_table[1] = {
    urien_se_random_0,  /* 0 */
};

const u16 urien_se_random_0[16] = {
    0x02F0, 0x02EF, 0x02F3, 0x02F0, 0x02EF, 0x02F3, 0x02F0, 0x02EF,
    0x02F0, 0x02EF, 0x02F3, 0x02F0, 0x02EF, 0x02F3, 0x02F0, 0x02EF,
};

