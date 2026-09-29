/*
 * GILL_ATTR.C  Gill's attack attributes and random sound lists
 *
 * gill_catt_table has one attack attribute per row, written with ATTR (charscr.h): strength, attribute,
 *   guard type and chip damage, knock-back, damage (pow), stun (piyo), super art gain, hit stop and
 *   marks. A frame line's att picks the row (negative: a new hit). Each row names the moves using it.
 *
 * gill_se_random_table lists the sound effects a frame picks from at random: a frame whose sound
 * code names an entry here plays one of that list's sixteen codes.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

const ATTACK_ATTR gill_catt_table[35] = {
    /*   rea lvl att jmp zu  nd  mkh but dip grd kez dir zur fre pow imp piy art ng  vs  hsme hsyou hit dmg */
    ATTR(  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0),  /* 0: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 15,  1, 63,  0, 11,  0,  0,  7, 32,  2,  1,  0,  3,  7, -7, 13, 72),  /* 1: S PUNCH A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 16,  1, 62,  0, 15,  0,  0, 24, 33,  6,  4,  0,  3,  9, -9, 18, 72),  /* 2: M PUNCH C */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 16,  1, 62,  0, 12,  0,  0, 22, 34,  6,  4,  0,  3,  9, -9, 18, 72),  /* 3: M PUNCH A */
    ATTR( 32,  1,  1,  0,  0,  0,  0, 17,  1, 63,  0, 12,  0,  0, 16, 35,  8,  7,  0,  3, 11,-11, 23, 73),  /* 4: not used by a script */
    ATTR( 36,  2,  1,  0,  0,  0,  0,  9,  1, 63,  3, 10,  0,  0, 32, 35,  8,  7,  0,  3, 11,-11, 23, 73),  /* 5: L PUNCH A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 15,  1, 63,  0, 11,  0,  0,  8, 32,  3,  1,  0,  3,  7, -7, 29, 72),  /* 6: S KICK A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 15,  1, 63,  0, 12,  0,  0, 16, 32,  4,  1,  0,  3,  7, -7, 29,  0),  /* 7: not used by a script */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 16,  1, 62,  0, 13,  0,  0, 20, 34,  6,  4,  0,  3,  9, -9, 34, 72),  /* 8: M KICK A, M KICK C, no name */
    ATTR( 32,  2,  1,  0,  0,  0,  0,  9,  1, 54,  3, 11,  0,  0, 14, 35,  2,  8,  0,  3, 11,-11, 39, 73),  /* 9: L KICK A */
    ATTR( 36,  2,  1,  0,  0,  0,  0,  9,  1, 54,  3,  9,  0,  0, 22, 35,  8,  1,  0,  3, 11,-11, 39, 73),  /* 10: L KICK A */
    ATTR( 32,  2,  0,  0,  0,  0,  0, 17,  1, 63,  0, 11,  0,  0, 36, 36,  8,  7,  0,  3, 11,-11, 39,  0),  /* 11: not used by a script */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 15,  1, 63,  0, 13,  0,  0,  4, 32,  2,  1,  0,  3,  7, -7, 13, 72),  /* 12: KAGAMI P A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 16,  1, 63,  0, 14,  0,  0, 16, 34,  6,  4,  0,  3,  9, -9, 18, 72),  /* 13: KAGAMI P A, no name */
    ATTR( 95,  3,  3,  0,  0,  0,  0,  8,  1, 63,  3, 15,  0,  0, 14, 35,  4,  1,  0,  3, 11,-11, 23, 73),  /* 14: KAGAMI P A */
    ATTR( 32,  0,  0,  0,  0,  0,  0, 15,  1, 45,  0, 11,  0,  0,  4, 32,  1,  1,  0,  3,  7, -7, 29, 72),  /* 15: KAGAMI K A */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 16,  1, 45,  0, 12,  0,  0, 18, 34,  3,  4,  0,  3,  9, -9, 34, 72),  /* 16: KAGAMI K A */
    ATTR( 89,  0,  1,  0,  0,  0,  0,  1,  1, 45,  3, 13,  0,  0, 26, 36,  4,  7,  0,  3, 11,-11, 39, 73),  /* 17: KAGAMI K A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 18,  1, 54,  0,  9,  2,  0, 12, 37,  4,  1,  0,  3,  7, -7, 13, 72),  /* 18: V JUMP P S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 19,  1, 54,  0, 11,  2,  0, 20, 38,  6,  4,  0,  3,  8, -8, 18, 72),  /* 19: V JUMP P M A */
    ATTR( 32,  2,  3,  1,  0,  0,  0, 20,  1, 54,  3, 10,  2,  0, 28, 39,  8,  7,  0,  3,  9, -9, 23, 73),  /* 20: V JUMP P L A, ATTACK 4 M: not started by a command */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 17,  1,  0,  0, 11,  0,  0,  0, 34,  0,  0,  1,  3,  8, -8,  0, 73),  /* 21: TUKAMIKAKARI A */
    ATTR( 32,  1,  0,  0,  0,  0, 54,  2,  1, 63,  0, 10,  0,  0, 40, 38,  9, 13,  0,  3, 10,-10, 55, 73),  /* 22: CATCH 1 */
    ATTR( 32,  2,  0,  0,  0,  0, 38,  4,  1, 63,  0,  6,  0,  0, 10, 36,  2,  1,  0,  3, 12,-12, 71, 72),  /* 23: CATCH 2 */
    ATTR( 36,  2,  0,  1,  0,  0,  0,  5, 49, 54,  2, 10,  0,  0, 12, 36,  4,  4,  0,  3,  8, -8, 44, 73),  /* 24: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    ATTR( 35,  2,  0,  1,  0,  0,  0,  6, 49, 54,  2, 13,  0,  0, 28, 36,  6,  1,  0,  3, 16,-16, 44, 73),  /* 25: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    ATTR( 32,  2,  0,  1,  0,  0,  0, 12, 49, 54,  2, 13,  2,  0, 26, 36,  9,  4,  0,  3, 12,-12, 96, 73),  /* 26: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    ATTR( 32,  1,  0,  0,  0,  0,  0,  6,  1, 63,  3, 12,  0,  0,  6, 36,  2,  1,  0,  3, 12,-12, 28, 73),  /* 27: not used by a script */
    ATTR( 37,  2,  3,  0,  1,  0,  0,  7,  1, 63,  3, 13,  0,  0, 20, 35,  3,  8,  0,  3, 11,-11, 23, 73),  /* 28: KAGAMI P A */
    ATTR( 32,  0,  0,  1,  0,  0,  0, 18,  1, 54,  0, 12,  2,  0, 12, 37,  4,  1,  0,  3,  7, -7, 29, 72),  /* 29: V JUMP K S A */
    ATTR( 32,  1,  0,  1,  0,  0,  0, 19,  1, 54,  0, 13,  2,  0, 20, 38,  6,  4,  0,  3,  8, -8, 34, 72),  /* 30: V JUMP K M A */
    ATTR( 32,  2,  3,  1,  0,  0,  0, 20,  1, 54,  3, 11,  2,  0, 28, 39,  8,  7,  0,  3,  9, -9, 39, 73),  /* 31: V JUMP K L A */
    ATTR(110,  1,  0,  0,  1,  0, 53, 10,  1, 62,  2,  2,  0,  0, 40, 39,  2,  7,  0,  3, 16,-16, 28, 60),  /* 32: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 33,  2,  1,  0,  0,  0,  0, 11,  1, 62,  2, 11,  0,  0, 16, 39,  8,  1,  0,  3, 12,-12, 28, 72),  /* 33: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    ATTR( 32,  1,  0,  0,  0,  0,  0, 19,  1, 54,  0,  9,  0,  0,  8, 32,  1,  1,  0,  3,  8, -8, 18, 73),  /* 34: ATTACK 7 M: not started by a command */
};

extern const u16 gill_se_random_0[];

const u16* const gill_se_random_table[1] = {
    gill_se_random_0,  /* 0 */
};

const u16 gill_se_random_0[16] = {
    0x036F, 0x036B, 0x036B, 0x036B, 0x036F, 0x036F, 0x036F, 0x036F,
    0x036F, 0x036C, 0x036C, 0x036F, 0x036C, 0x036B, 0x036C, 0x036F,
};

