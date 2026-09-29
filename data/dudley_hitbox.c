/*
 * DUDLEY_HITBOX.C  Dudley's hit boxes
 *
 * Each of Dudley's animation frames names an entry of dudley_hit_ix_table (cg_hit_ix in the frame
 * record). The entry picks the boxes that frame uses; set_char_base_data (CHARID) points the work
 * at these tables through char_init_data. A box is x, width, y, height from the character's
 * position, x mirrored when facing left; width 0 means no box.
 *
 * hit_ix_table  one row per animation frame pose (a script line's hit field picks it); each column
 *               picks a row of one box table (0 = none):
 *     boix  body box: where this character can be hit (body_box)
 *     bhix  hand box base + haix hand box offset: extra hurt boxes on an extended arm or leg
 *           (hand_box[bhix + haix])
 *     mf    two hit-kind codes the debug viewer names (hit_kind_tbl: u/a/d pairs); in play only the
 *           after-image effect reads them
 *     caix  catch box: this frame's throw reach (cat_box in _attbox.c)
 *     cuix  caught box: where this character can be thrown (cau_box in _attbox.c)
 *     atix  attack box: where this frame hits (att_box in _attbox.c)
 *     hoix  push box: keeps the two fighters apart (hos_box)
 * body_box      four damage boxes (head down to legs)
 * hand_box      four damage boxes for an extended arm or leg
 * hos_box       the push box: where two fighters' push boxes overlap they are moved apart
 *
 * Row comments: the moves whose frames use the row or box (debug viewer names). Row 0 of a
 * box table is no box.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const HIT_IX dudley_hit_ix_table[261] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +21 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +109 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    1 },  /* 2: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +2 */
    {    7,    0,    0, 0x0000,    0,    0,   67,    0 },  /* 3: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    {    3,    0,    0, 0x0000,    0,    8,    0,   29 },  /* 4: JUMP JUNBI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    {    5,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 5: L KICK C */
    {   12,    0,    0, 0x0000,    0,    1,   35,    1 },  /* 6: L KICK C */
    {    4,    0,    1, 0x0000,    0,    1,   36,    1 },  /* 7: L KICK C */
    {   77,    0,    0, 0x0000,    0,    8,   57,    5 },  /* 8: V JUMP K L A */
    {    8,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 9: KAGAMU, KAGAMI TURN, PARING DOWN +37 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 10: follow-up of AIR NORMAL, follow-up of APPEAR JUNBI 5, no name */
    {   10,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 11: PARING AIR F, GUARD AIR, V JUMP P S A +15 */
    {    7,    0,    0, 0x0000,    0,    0,   33,    0 },  /* 12: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script) +1 */
    {    6,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 13: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    {    9,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 14: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    {   14,    0,    2, 0x0000,    0,    1,    1,    1 },  /* 15: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    {   15,    0,    3, 0x0000,    0,    1,    2,    1 },  /* 16: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +3 */
    {   16,    0,    4, 0x0000,    0,    1,    3,    1 },  /* 17: S KICK A */
    {   16,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 18: S KICK A */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 19: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    {   18,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 20: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    {   68,    0,   21, 0x0000,    0,    1,    5,    1 },  /* 21: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    {   68,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 22: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    {   19,    0,    0, 0x0000,    0,   10,    0,    1 },  /* 23: S PUNCH C */
    {   20,    0,    5, 0x0000,    0,   10,    6,    1 },  /* 24: S PUNCH C */
    {   15,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 25: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +3 */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 26: L PUNCH A, L PUNCH C, M KICK C +13 */
    {   23,    0,    6, 0x0000,    0,    1,    7,    4 },  /* 27: M KICK C, ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) +2 */
    {   23,    0,    6, 0x0000,    0,    1,    0,    4 },  /* 28: M KICK C, ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) +2 */
    {   24,    0,    0, 0x0000,    0,    1,    8,    1 },  /* 29: L KICK A, no name, follow-up of M KICK A */
    {   25,    0,    7, 0x0000,    0,    1,    9,    1 },  /* 30: L KICK A, no name, follow-up of M KICK A +1 */
    {   26,    0,    8, 0x0000,    0,    1,   10,    1 },  /* 31: L KICK A, no name, follow-up of M KICK A +5 */
    {   26,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 32: L KICK A, no name, follow-up of M KICK A +5 */
    {   27,    0,    9, 0x0000,    0,    1,   11,    1 },  /* 33: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A, M KICK C +4 */
    {   27,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A, M KICK C +6 */
    {   28,    0,   10, 0x0000,    0,    7,   12,    3 },  /* 35: KAGAMI P A */
    {   29,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 36: KAGAMI P A, follow-up of JUDGMENT WAIT */
    {   30,    0,   11, 0x0000,    0,    6,   13,    3 },  /* 37: KAGAMI P A, follow-up of JUDGMENT WAIT */
    {   30,    0,   11, 0x0000,    0,    6,    0,    3 },  /* 38: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    {   31,    0,    0, 0x0000,    0,    6,    0,    1 },  /* 39: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    {   32,    0,   12, 0x0000,    0,    6,   14,    1 },  /* 40: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    {   33,    0,   13, 0x0000,    0,    6,   15,    1 },  /* 41: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    {   34,    0,   14, 0x0000,    0,    6,    0,    1 },  /* 42: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    {   35,    0,    0, 0x0000,    0,    6,    0,    1 },  /* 43: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +5 */
    {   36,    0,   15, 0x0000,    0,    7,   16,    3 },  /* 44: KAGAMI K A */
    {   36,    0,   15, 0x0000,    0,    7,    0,    3 },  /* 45: KAGAMI K A */
    {   37,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 46: KAGAMI K A */
    {   38,    0,   16, 0x0000,    0,    6,   17,    3 },  /* 47: KAGAMI K A */
    {   38,    0,   16, 0x0000,    0,    6,    0,    3 },  /* 48: KAGAMI K A */
    {   44,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 49: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   40,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 50: KAGAMI K A */
    {   41,    0,    0, 0x0000,    0,   13,    0,    3 },  /* 51: KAGAMI K A */
    {    4,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 52: L KICK C */
    {   43,    0,   17, 0x0000,    0,   13,   18,    3 },  /* 53: KAGAMI K A */
    {   43,    0,   17, 0x0000,    0,   13,    0,    3 },  /* 54: KAGAMI K A */
    {   83,    0,    0, 0x0000,    0,    8,   64,    5 },  /* 55: not started by a command */
    {   45,    0,   18, 0x0000,    0,    8,   19,    5 },  /* 56: V JUMP P S A, F JUMP P S A, no name */
    {   45,    0,   18, 0x0000,    0,    8,    0,    5 },  /* 57: V JUMP P S A, F JUMP P S A, no name */
    {   46,    0,   19, 0x0000,    0,    8,   20,    5 },  /* 58: V JUMP P M A, F JUMP P M A */
    {   46,    0,   19, 0x0000,    0,    8,    0,    5 },  /* 59: V JUMP P M A, F JUMP P M A */
    {   47,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 60: V JUMP P L A, F JUMP P L A */
    {   48,    0,    0, 0x0000,    0,    8,   21,    5 },  /* 61: V JUMP P L A, F JUMP P L A */
    {   48,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 62: V JUMP P L A, F JUMP P L A */
    {   75,    0,   22, 0x0000,    0,    8,   22,    5 },  /* 63: V JUMP K S A, F JUMP K S A */
    {   49,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 64: V JUMP K L A, F JUMP K L A */
    {   50,    0,    0, 0x0000,    0,    8,   23,    5 },  /* 65: F JUMP K L A */
    {   50,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 66: V JUMP K L A, F JUMP K L A */
    {   51,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 67: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {    8,    0,    0, 0x0000,    0,   22,   28,    3 },  /* 68: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 69: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 70: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   54,    0,    0, 0x0000,    0,    0,    0,   26 },  /* 71: no name */
    {   55,    0,    0, 0x0000,    0,   16,    0,   15 },  /* 72: not used by a script */
    {   55,    0,    0, 0x0000,    0,   16,   24,   15 },  /* 73: not used by a script */
    {   56,    0,    0, 0x0000,    0,   17,    0,   16 },  /* 74: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   70,    3 },  /* 75: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   57,    0,    0, 0x0000,    0,   22,   71,    3 },  /* 76: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {    1,    0,    0, 0x0000,    0,    1,   26,    1 },  /* 77: not used by a script */
    {   21,    0,    0, 0x0000,    0,   22,   28,    3 },  /* 78: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    {   13,    0,    0, 0x0000,    0,    8,   27,    5 },  /* 79: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   39,    0,    0, 0x0000,    0,   22,   29,    3 },  /* 80: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   88,    0,    0, 0x0000,    0,   22,   30,    3 },  /* 81: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    {   51,    0,    0, 0x0000,    0,    6,   31,    3 },  /* 82: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {   52,    0,    0, 0x0000,    0,   22,   32,    3 },  /* 83: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {   13,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 84: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +2 */
    {   13,    0,    0, 0x0000,    0,    8,   34,    5 },  /* 85: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   59,    0,    0, 0x0000,    0,    1,    0,   25 },  /* 86: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   60,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 87: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,    0,   20, 0x0000,    0,    1,   37,    1 },  /* 88: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,    0,   20, 0x0000,    0,    1,   38,    1 },  /* 89: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,    0,   20, 0x0000,    0,    1,   39,    1 },  /* 90: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   61,    0,   20, 0x0000,    0,    1,   40,    1 },  /* 91: ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    {   61,    0,   20, 0x0000,    0,    1,   41,    1 },  /* 92: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   61,    0,   20, 0x0000,    0,    1,   42,    1 },  /* 93: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 94: not used by a script */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 95: not used by a script */
    {   64,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 96: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,   43,    3 },  /* 97: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,    0,    0, 0x0000,    0,    1,   44,    3 },  /* 98: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,    0,    0, 0x0000,    0,    1,   45,    3 },  /* 99: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   66,    0,    0, 0x0000,    0,    1,   46,    3 },  /* 100: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   85,    0,   27, 0x0000,    0,    1,   47,    3 },  /* 101: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   85,    0,   27, 0x0000,    0,    1,    0,    3 },  /* 102: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   67,    0,    0, 0x0000,    0,   20,    0,   19 },  /* 103: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    {   89,    0,    0, 0x0000,    0,   19,    0,   28 },  /* 104: ATTACK 3 S: SA II 23623+P (plain script) */
    {   89,    0,    0, 0x0000,    0,   19,   48,   28 },  /* 105: ATTACK 3 S: SA II 23623+P (plain script) */
    {   69,    0,    0, 0x0000,    0,    1,   49,   13 },  /* 106: ATTACK 3 S: SA II 23623+P (plain script) */
    {   70,    0,    0, 0x0000,    0,    1,   50,   13 },  /* 107: ATTACK 3 S: SA II 23623+P (plain script) */
    {   70,    0,    0, 0x0000,    0,    1,   51,   13 },  /* 108: not used by a script */
    {   70,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 109: ATTACK 3 S: SA II 23623+P (plain script) */
    {   71,    0,    0, 0x0000,    0,   19,    0,   13 },  /* 110: ATTACK 3 S: SA II 23623+P (plain script) */
    {   72,    0,    0, 0x0000,    0,   19,    0,   13 },  /* 111: ATTACK 3 S: SA II 23623+P (plain script) */
    {   72,    0,    0, 0x0000,    0,   19,   52,   13 },  /* 112: ATTACK 3 S: SA II 23623+P (plain script) */
    {   73,    0,    0, 0x0000,    0,    1,   53,   13 },  /* 113: ATTACK 3 S: SA II 23623+P (plain script) */
    {   73,    0,    0, 0x0000,    0,    1,   54,   13 },  /* 114: not used by a script */
    {   73,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 115: ATTACK 3 S: SA II 23623+P (plain script) */
    {   52,    0,    0, 0x0000,    0,   22,   55,   12 },  /* 116: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   13,    0,    0, 0x0000,    0,    8,   56,    5 },  /* 117: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   52,    0,    0, 0x0000,    0,   22,   69,    3 },  /* 118: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   13,    0,    0, 0x0000,    0,    8,   58,    5 },  /* 119: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   74,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 120: not used by a script */
    {   76,    0,   23, 0x0000,    0,    8,   59,    5 },  /* 121: V JUMP K M A, F JUMP K M A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 122: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI), ATTACK 3 S: SA II 23623+P (plain script), ATTACK 6 SP: EX 6(123)4+KK (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 123: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 124: not used by a script */
    {    0,    0,    0, 0x0000,    0,    8,   56,    5 },  /* 125: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   69,    3 },  /* 126: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    1,    0,    0, 0x0000,    1,    1,   60,    1 },  /* 127: TUKAMIKAKARI A */
    {   78,    0,   24, 0x0000,    0,    1,   61,    1 },  /* 128: ATTACK 13 M: not started by a command */
    {   78,    0,   24, 0x0000,    0,    1,    0,    1 },  /* 129: ATTACK 13 M: not started by a command */
    {   79,    0,   25, 0x0000,    0,    1,   62,    1 },  /* 130: ATTACK 13 L: not started by a command */
    {   80,    0,   26, 0x0000,    0,    1,   63,    1 },  /* 131: ATTACK 13 L: not started by a command */
    {   80,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 132: ATTACK 13 L: not started by a command */
    {   81,    0,    0, 0x1010,    0,    1,    0,   20 },  /* 133: PIYO */
    {   82,    0,    0, 0x1010,    0,    1,    0,   10 },  /* 134: PIYO */
    {   13,    0,    0, 0x0000,    0,    8,   65,    5 },  /* 135: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,    0,   26 },  /* 136: NEKOROBI S, no name */
    {   84,    0,    0, 0x0000,    0,    9,    0,   14 },  /* 137: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   28,    0,   10, 0x0000,    0,    7,    0,    3 },  /* 138: KAGAMI P A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 139: follow-up of SP WIN 1 */
    {    8,    0,    0, 0x0000,    0,    6,    0,    3 },  /* 140: follow-up of SP WIN 1 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 141: LOSE SONABA, SHIMEOTASARE */
    {   86,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 142: not used by a script */
    {   86,    0,   28, 0x0000,    0,    8,   66,    5 },  /* 143: not used by a script */
    {   86,    0,   29, 0x0000,    0,    8,   66,    5 },  /* 144: ATTACK 8 S: not started by a command, ATTACK 8 SP: not started by a command */
    {    7,    0,    0, 0x0000,    0,    0,   68,    0 },  /* 145: ATTACK 12 SP: after 6(123)456+P (plain script), 6(123)4+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    {   87,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 146: KAGAMI K A */
    {   14,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 147: S PUNCH A, follow-up of S PUNCH A */
    {   20,    0,    5, 0x0000,    0,   10,    0,    1 },  /* 148: S PUNCH C */
    {   90,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 149: UPPER L */
    {   91,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 150: UPPER L */
    {   92,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 151: not used by a script */
    {   93,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 152: UPPER L */
    {   94,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 153: FACE S, FACE M, FACE L +7 */
    {   95,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 154: FACE M, FACE L, FOOK TEMAE L +3 */
    {   96,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 155: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    {   97,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 156: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    {   98,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 157: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {   99,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 158: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    {  100,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 159: NOUTEN L, BODY BROW L, BODY UPPER L */
    {  101,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 160: NOUTEN L, BODY BROW L, TATAKI S */
    {  102,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 161: KAGAMI S, KAGAMI M, KAGAMI L +5 */
    {  103,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 162: KAGAMI M, KAGAMI L, KGM TATAKI S +1 */
    {  104,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 163: KAGAMI L */
    {  105,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 164: KAGAMI L */
    {  106,    0,    0, 0x0000,    0,    1,    0,    3 },  /* 165: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  107,    0,    0, 0x0000,    0,    1,    0,    3 },  /* 166: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  108,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 167: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  109,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 168: M PUNCH C */
    {  110,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 169: M PUNCH C */
    {  111,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 170: M PUNCH C */
    {  112,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 171: M PUNCH C */
    {  113,    0,   30, 0x0000,    0,    1,   72,    1 },  /* 172: M PUNCH C */
    {  113,    0,   31, 0x0000,    0,    1,   73,    1 },  /* 173: M PUNCH C */
    {  113,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 174: M PUNCH C */
    {  113,    0,   32, 0x0000,    0,    1,    0,    1 },  /* 175: M PUNCH C */
    {  114,    0,   33, 0x0000,    0,    1,    0,    1 },  /* 176: M PUNCH C */
    {    3,    0,    0, 0x0000,    0,    1,    0,   29 },  /* 177: not started by a command */
    {  115,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 178: AIR NORMAL, BODY UPPER, ALEX B.D */
    {  116,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 179: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  117,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 180: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  118,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 181: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  119,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 182: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  120,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 183: NOKEZORI, UPPER, HARAYARARE +5 */
    {  121,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 184: NOKEZORI, UPPER, BODY UPPER +7 */
    {  122,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 185: NOKEZORI, UPPER, BODY UPPER +7 */
    {  123,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 186: NOKEZORI, UPPER, BODY UPPER +9 */
    {  124,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 187: NOKEZORI, UPPER, BODY UPPER +9 */
    {  125,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 188: NOKEZORI, UPPER, BODY UPPER +9 */
    {  126,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 189: NOKEZORI, UPPER, BODY UPPER +10 */
    {  127,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 190: NOKEZORI, UPPER, BODY UPPER +11 */
    {  128,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 191: NOKEZORI, UPPER, BODY UPPER +11 */
    {  129,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 192: KUNOJI, KUNOJI NOKE */
    {  130,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 193: KUNOJI, KUNOJI NOKE */
    {  131,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 194: KUNOJI */
    {  132,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 195: KIRIMOMI */
    {  133,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 196: KIRIMOMI */
    {  134,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 197: KIRIMOMI */
    {  135,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 198: KIRIMOMI */
    {  136,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 199: KIRIMOMI */
    {  137,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 200: KIRIMOMI */
    {  138,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 201: KIRIMOMI */
    {  139,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 202: KIRIMOMI */
    {  140,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 203: KIRIMOMI */
    {  141,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 204: KIRIMOMI */
    {  142,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 205: KIRIMOMI */
    {  143,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 206: KIRIMOMI */
    {  144,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 207: KIRIMOMI */
    {  145,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 208: KIRIMOMI */
    {  146,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 209: KIRIMOMI */
    {  147,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 210: KIRIMOMI */
    {  148,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 211: UPPER, TATUMAKIZANKU */
    {  149,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 212: UPPER, TATUMAKIZANKU */
    {  150,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 213: BODY UPPER, ALEX B.D */
    {  151,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 214: BODY UPPER, ALEX B.D */
    {  152,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 215: HARAYARARE, HANEKAERI HARA */
    {  153,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 216: TTKI V. AIR */
    {  154,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 217: TTKI V. AIR */
    {  155,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 218: HUMI ASIB */
    {  156,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 219: HUMI ASIB, TOMOE RYU, FLANKEN.S */
    {  157,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 220: FACE */
    {  158,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 221: DENKI */
    {  159,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 222: TOUKETSU A */
    {  160,    0,    0, 0x0000,    0,   21,    0,   24 },  /* 223: BODY SLAM, IPPONZEOI, TOMOE RYU +3 */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 224: KAMAE, DASH HUMIKOMI, DASH TOBINOKI +1 */
    {  161,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 225: KAMAE */
    {  162,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 226: KAMAE */
    {  163,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 227: KAMAE */
    {  164,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 228: KAMAE */
    {  165,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 229: KAMAE */
    {  166,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 230: KAMAE */
    {  167,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 231: HURIMUKI */
    {  168,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 232: FRONT WALK */
    {  169,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 233: FRONT WALK */
    {  170,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 234: BACK WALK */
    {  170,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 235: BACK WALK */
    {  171,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 236: BACK WALK */
    {  172,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 237: DASH HUMIKOMI */
    {  173,    0,    0, 0x1515,    0,    3,    0,   29 },  /* 238: DASH HUMIKOMI */
    {    3,    0,    0, 0x1010,    0,    1,    0,   29 },  /* 239: DASH HUMIKOMI */
    {  174,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 240: DASH TOBINOKI */
    {  175,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 241: DASH TOBINOKI */
    {  176,    0,    0, 0x1515,    0,    1,    0,    2 },  /* 242: DASH TOBINOKI */
    {    1,    0,    0, 0x1A1A,    0,    6,    0,    3 },  /* 243: KAGAMU */
    {    8,    0,    0, 0x1010,    0,    6,    0,    3 },  /* 244: KAGAMI KAMAE */
    {  177,    0,    0, 0x1010,    0,    6,    0,    3 },  /* 245: KAGAMI KAMAE */
    {  178,    0,    0, 0x1010,    0,    6,    0,    3 },  /* 246: KAGAMI KAMAE */
    {  179,    0,    0, 0x1515,    0,    6,    0,    3 },  /* 247: KAGAMI TURN */
    {  180,    0,    0, 0x1A1A,    0,    1,    0,   20 },  /* 248: STAND UP */
    {  181,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 249: STAND UP */
    {   53,    0,    0, 0x0000,    0,    8,    0,   20 },  /* 250: SP JUMP JUNBI */
    {  182,    0,    0, 0x1010,    0,    8,    0,    5 },  /* 251: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  183,    0,    0, 0x1010,    0,    8,    0,    5 },  /* 252: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  184,    0,    0, 0x1010,    0,    8,    0,    5 },  /* 253: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  185,    0,    0, 0x1515,    0,    8,    0,    5 },  /* 254: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    {  186,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 255: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    {  185,    0,    0, 0x0000,    0,    8,    0,    5 },  /* 256: PARING AIR F, GUARD AIR, P BREAK AIR F +2 */
    {    1,    0,   34, 0x0000,    0,    1,    0,    1 },  /* 257: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  187,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 258: TUKAMIHAZUSARE */
    {  188,    0,    0, 0x0000,    0,    1,    0,   20 },  /* 259: PIYO */
    {  188,    0,    0, 0x1010,    0,    1,    0,   20 },  /* 260: PIYO */
};

const BODY_BOX dudley_body_box[189] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -18,  28,  89,  17 },  {  -31,  60,  78,  18 },  {  -26,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +113 */
    { { {  -32,  61,  67,  39 },  {  -26,  55,  57,  10 },  {  -26,  55,  38,  19 },  {  -32,  70,   0,  38 } } },  /* 2: ATTACK 11 M: 6(123)4+P light (plain script), ATTACK 11 L: 6(123)4+P medium (plain script), ATTACK 11 SP: 6(123)4+P heavy (plain script) +2 */
    { { {  -39,  28,  70,  17 },  {  -35,  54,  62,  22 },  {  -29,  54,  40,  22 },  {  -34,  69,   0,  40 } } },  /* 3: JUMP JUNBI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    { { {  -33,  51,  80,  15 },  {  -52,  74,  59,  19 },  {  -40,  62,  36,  21 },  {  -40,  85,   0,  34 } } },  /* 4: L KICK C */
    { { {  -24,  53,  81,  18 },  {  -34,  67,  59,  23 },  {  -34,  60,  34,  25 },  {  -40,  81,   0,  34 } } },  /* 5: L KICK C */
    { { {  -30,  30,  82,  18 },  {  -52,  66,  62,  28 },  {  -38,  60,  40,  30 },  {  -50,  90,   0,  38 } } },  /* 6: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -38,  60,  40,  34 },  {  -50,  90,   0,  38 } } },  /* 7: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 12 L: after 6(123)456+P (plain script), 6(123)4+P (plain script) +1 */
    { { {  -18,  28,  55,  18 },  {  -37,  69,  48,  18 },  {  -38,  71,  29,  19 },  {  -40,  83,   0,  29 } } },  /* 8: KAGAMU, KAGAMI TURN, PARING DOWN +38 */
    { { {  -28,  30,  84,  18 },  {  -44,  70,  62,  26 },  {  -32,  64,  36,  24 },  {  -48,  92,   0,  36 } } },  /* 9: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    { { {  -23,  42,  96,  16 },  {  -32,  64,  84,  23 },  {  -30,  59,  64,  18 },  {  -30,  60,  41,  21 } } },  /* 10: PARING AIR F, GUARD AIR, V JUMP P S A +15 */
    { { {  -21,  33, 107,  41 },  {  -32,  61,  84,  24 },  {  -31,  59,  64,  20 },  {  -31,  59,  41,  23 } } },  /* 11: not used by a script */
    { { {  -35,  49,  81,  19 },  {  -45,  70,  59,  32 },  {  -40,  65,  34,  25 },  {  -40,  81,   0,  34 } } },  /* 12: L KICK C */
    { { {  -18,  30,  97,  44 },  {  -30,  56,  84,  22 },  {  -31,  57,  64,  20 },  {  -29,  52,  26,  38 } } },  /* 13: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -24,  26,  91,  16 },  {  -24,  52,  76,  23 },  {  -27,  54,  45,  29 },  {  -33,  68,   0,  43 } } },  /* 14: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    { { {  -24,  26,  91,  16 },  {  -29,  45,  73,  21 },  {  -33,  49,  41,  30 },  {  -39,  74,   0,  40 } } },  /* 15: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +4 */
    { { {  -18,  34,  92,  17 },  {  -23,  48,  73,  18 },  {  -55,  80,  53,  20 },  {  -35,  71,   0,  53 } } },  /* 16: S KICK A */
    { { {  -40,  29,  80,  18 },  {  -43,  59,  72,  17 },  {  -43,  69,  40,  32 },  {  -36,  82,   0,  40 } } },  /* 17: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    { { {  -33,  34,  93,  16 },  {  -48,  70,  83,  17 },  {  -46,  74,  48,  35 },  {  -40,  80,   0,  48 } } },  /* 18: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    { { {  -34,  37,  79,  13 },  {  -34,  52,  61,  19 },  {  -34,  61,  37,  22 },  {  -34,  81,   0,  35 } } },  /* 19: S PUNCH C */
    { { {  -28,  40,  83,  13 },  {  -27,  56,  62,  22 },  {  -28,  69,  38,  22 },  {  -33,  86,   0,  37 } } },  /* 20: S PUNCH C */
    { { {  -18,  31,  72,  17 },  {  -45,  77,  62,  17 },  {  -45,  77,  28,  33 },  {  -45,  89,   0,  28 } } },  /* 21: ATTACK 1 S: 623+P light (routine Att_SENPUUKYAKU) */
    { { {  -17,  35,  76,  16 },  {  -32,  68,  61,  22 },  {  -32,  68,  38,  21 },  {  -42,  88,   0,  37 } } },  /* 22: L PUNCH A, L PUNCH C, M KICK C +13 */
    { { {  -35,  39,  81,  16 },  {  -24,  45,  65,  15 },  {  -53,  74,  46,  19 },  {  -40,  75,   0,  47 } } },  /* 23: M KICK C, ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -31,  39,  77,  22 },  {  -37,  67,  61,  21 },  {  -43,  73,  39,  22 },  {  -37,  77,   0,  39 } } },  /* 24: L KICK A, no name, follow-up of M KICK A */
    { { {  -31,  43,  81,  18 },  {  -25,  51,  64,  15 },  {  -53,  83,  46,  18 },  {  -37,  72,   0,  46 } } },  /* 25: L KICK A, no name, follow-up of M KICK A +1 */
    { { {  -24,  34,  84,  18 },  {  -73, 103,  64,  20 },  {  -36,  67,  41,  23 },  {  -36,  72,   0,  40 } } },  /* 26: L KICK A, no name, follow-up of M KICK A +5 */
    { { {  -30,  42,  83,  16 },  {  -80, 106,  52,  39 },  {  -36,  63,  38,  14 },  {  -42,  88,   0,  38 } } },  /* 27: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A, M KICK C +6 */
    { { {  -22,  34,  59,  16 },  {  -39,  71,  47,  22 },  {  -38,  71,  29,  18 },  {  -39,  83,   0,  29 } } },  /* 28: KAGAMI P A */
    { { {  -29,  31,  62,  17 },  {  -34,  67,  53,  21 },  {  -37,  61,  33,  20 },  {  -40,  90,   0,  33 } } },  /* 29: KAGAMI P A, follow-up of JUDGMENT WAIT */
    { { {  -29,  31,  62,  17 },  {  -34,  67,  53,  21 },  {  -37,  61,  33,  20 },  {  -40,  90,   0,  33 } } },  /* 30: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    { { {  -46,  31,  72,  17 },  {  -54,  68,  53,  23 },  {  -37,  61,  33,  20 },  {  -42,  87,   0,  33 } } },  /* 31: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -35,  31,  82,  17 },  {  -49,  67,  60,  26 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 32: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -27,  31,  84,  17 },  {  -45,  66,  60,  30 },  {  -35,  64,  33,  27 },  {  -38,  87,   0,  33 } } },  /* 33: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -30,  31,  89,  17 },  {  -45,  63,  60,  30 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 34: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -30,  31,  89,  17 },  {  -45,  63,  60,  30 },  {  -37,  61,  33,  27 },  {  -42,  87,   0,  33 } } },  /* 35: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +5 */
    { { {  -18,  28,  58,  17 },  {  -39,  73,  46,  24 },  {  -38,  71,  29,  17 },  {  -43,  84,   0,  29 } } },  /* 36: KAGAMI K A */
    { { {  -29,  36,  56,  19 },  {  -47,  71,  50,  15 },  {  -48,  78,  29,  21 },  {  -48,  95,   0,  29 } } },  /* 37: KAGAMI K A */
    { { {  -46,  33,  47,  18 },  {  -54,  76,  35,  26 },  {  -66, 106,  25,  27 },  {  -55, 112,   0,  33 } } },  /* 38: KAGAMI K A */
    { { {  -41,  51,  82,  19 },  {  -51,  77,  61,  26 },  {  -26,  65,  42,  27 },  {  -14,  62,   0,  42 } } },  /* 39: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -32,  31,  63,  17 },  {  -39,  76,  49,  24 },  {  -39,  68,  29,  20 },  {  -40,  87,   0,  29 } } },  /* 40: KAGAMI K A */
    { { {  -55,  31,  61,  17 },  {  -50,  66,  53,  18 },  {  -48,  80,  29,  24 },  {  -45,  87,   0,  29 } } },  /* 41: KAGAMI K A */
    { { {  -24,  43,  99,  16 },  {  -32,  58,  84,  25 },  {  -30,  56,  64,  20 },  {  -29,  55,  41,  23 } } },  /* 42: not used by a script */
    { { {  -61,  33,  30,  29 },  {  -40,  48,  35,  31 },  {  -75, 109,  23,  24 },  {  -48, 104,   0,  28 } } },  /* 43: KAGAMI K A */
    { { {  -41,  50,  71,  20 },  {  -35,  63,  62,  20 },  {  -22,  57,  40,  22 },  {  -14,  60,   0,  40 } } },  /* 44: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {  -19,  28, 107,  16 },  {    0,   0,   0,   0 },  {  -29,  58,  79,  32 },  {  -26,  52,  50,  29 } } },  /* 45: V JUMP P S A, F JUMP P S A, no name */
    { { {  -35,  43, 104,  16 },  {    0,   0,   0,   0 },  {  -31,  61,  79,  34 },  {  -28,  56,  42,  37 } } },  /* 46: V JUMP P M A, F JUMP P M A */
    { { {    4,  31,  99,  18 },  {    0,   0,   0,   0 },  {  -21,  63,  71,  41 },  {  -21,  53,  43,  28 } } },  /* 47: V JUMP P L A, F JUMP P L A */
    { { {  -18,  37, 105,  15 },  {  -72, 102,  66,  44 },  {  -34,  74,  40,  37 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP P L A, F JUMP P L A */
    { { {  -45,  42,  96,  16 },  {  -37,  71,  84,  23 },  {  -35,  79,  64,  18 },  {  -26,  78,  48,  16 } } },  /* 49: V JUMP K L A, F JUMP K L A */
    { { {  -76,  50,  78,  15 },  {  -76,  72,  47,  31 },  {  -26,  79,  78,  27 },  {   -4,  57,  47,  31 } } },  /* 50: F JUMP K L A, V JUMP K L A */
    { { {  -33,  39,  71,  20 },  {  -35,  63,  62,  20 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 51: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    { { {  -29,  37,  82,  20 },  {  -43,  69,  62,  26 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 52: ATTACK 1 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    { { {  -38,  26,  55,  19 },  {  -27,  46,  54,  22 },  {  -30,  56,  40,  19 },  {  -34,  69,   0,  40 } } },  /* 53: SP JUMP JUNBI */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 54: no name */
    { { {   -1,  16,  99,  16 },  {  -19,  61,  82,  20 },  {  -12,  47,  56,  24 },  {  -17,  53,  12,  42 } } },  /* 55: not used by a script */
    { { {  -11,  16,  71,  16 },  {  -22,  56,  60,  16 },  {  -20,  50,  38,  20 },  {  -20,  53,   0,  36 } } },  /* 56: not used by a script */
    { { {  -29,  37,  82,  20 },  {  -43,  69,  62,  26 },  {  -35,  71,  40,  22 },  {  -35,  81,   0,  40 } } },  /* 57: ATTACK 1 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    { { {  -43,  16,  57,  16 },  {  -55,  56,  59,  12 },  {  -37,  53,  33,  22 },  {  -23,  53,   0,  40 } } },  /* 58: not used by a script */
    { { {  -33,  33,  71,  22 },  {  -42,  73,  65,  17 },  {  -42,  62,  50,  15 },  {  -42,  70,  35,  15 } } },  /* 59: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    { { {  -38,  34,  86,  17 },  {  -42,  62,  78,  14 },  {  -42,  74,  58,  20 },  {  -42,  78,   0,  58 } } },  /* 60: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -22,  16,  90,  16 },  {  -28,  50,  71,  20 },  {  -27,  46,  47,  24 },  {  -29,  52,   0,  47 } } },  /* 61: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    4,  16,  88,  14 },  {  -20,  46,  74,  16 },  {  -22,  36,  40,  32 },  {  -32,  60,   0,  38 } } },  /* 62: not used by a script */
    { { {   -4,  16,  90,  14 },  {  -22,  48,  74,  16 },  {  -24,  36,  40,  32 },  {  -36,  62,   0,  38 } } },  /* 63: not used by a script */
    { { {  -10,  16,  76,  14 },  {  -30,  50,  68,  16 },  {  -26,  36,  40,  26 },  {  -36,  62,   0,  38 } } },  /* 64: not used by a script */
    { { {  -26,  16,  74,  14 },  {  -42,  56,  60,  14 },  {  -20,  34,  38,  20 },  {  -36,  72,   0,  36 } } },  /* 65: not used by a script */
    { { {  -33,  36,  74,  17 },  {  -42,  74,  60,  14 },  {  -40,  75,  38,  22 },  {  -40,  79,   0,  38 } } },  /* 66: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -61,  26,  22,  20 },  {  -35,  19,  22,  20 },  {  -16,  36,  22,  20 },  {  -55, 102,   0,  22 } } },  /* 67: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    { { {  -50,  50,  96,  16 },  {  -72,  96,  83,  16 },  {  -45,  74,  48,  35 },  {  -45,  85,   0,  48 } } },  /* 68: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    { { {   -9,  16,  71,  16 },  {  -30,  64,  62,  16 },  {  -19,  49,  41,  20 },  {  -25,  53,   0,  39 } } },  /* 69: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {    8,  16,  79,  16 },  {  -20,  53,  69,  16 },  {  -17,  39,  36,  31 },  {  -30,  56,   0,  34 } } },  /* 70: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {   12,  16,  59,  16 },  {  -18,  53,  55,  15 },  {  -17,  41,  38,  15 },  {  -35,  53,   0,  36 } } },  /* 71: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -42,  16,  44,  16 },  {  -36,  54,  47,  19 },  {  -30,  48,  32,  13 },  {  -31,  57,   0,  30 } } },  /* 72: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -30,  16,  74,  16 },  {  -37,  51,  65,  19 },  {  -24,  39,  41,  22 },  {  -32,  50,   0,  40 } } },  /* 73: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {  -18,  47,  72,  17 },  {  -22,  55,  62,  18 },  {  -22,  55,  43,  17 },  {  -19,  49,  34,  14 } } },  /* 74: not used by a script */
    { { {  -34,  42, 104,  16 },  {  -28,  57,  80,  32 },  {  -29,  58,  41,  39 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K S A, F JUMP K S A */
    { { {  -34,  42, 104,  16 },  {  -28,  57,  80,  32 },  {  -29,  58,  41,  39 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP K M A, F JUMP K M A */
    { { {  -60,  34,  78,  15 },  {  -62,  58,  32,  46 },  {  -26,  79,  78,  27 },  {   -4,  57,  47,  31 } } },  /* 77: V JUMP K L A */
    { { {  -22,  32,  83,  16 },  {  -45,  71,  52,  36 },  {  -49,  75,  38,  14 },  {  -65, 110,   0,  38 } } },  /* 78: ATTACK 13 M: not started by a command */
    { { {  -34,  33,  82,  17 },  {  -47,  67,  60,  29 },  {  -28,  61,  33,  27 },  {  -12,  68,   0,  33 } } },  /* 79: ATTACK 13 L: not started by a command */
    { { {  -30,  35,  89,  17 },  {  -50,  68,  60,  30 },  {  -50,  74,  33,  27 },  {  -50,  95,   0,  33 } } },  /* 80: ATTACK 13 L: not started by a command */
    { { {  -53,  29,  47,  18 },  {  -47,  61,  51,  27 },  {  -40,  65,  29,  27 },  {  -39,  80,   0,  29 } } },  /* 81: PIYO */
    { { {  -52,  29,  43,  18 },  {  -46,  61,  49,  27 },  {  -40,  65,  29,  27 },  {  -39,  80,   0,  29 } } },  /* 82: PIYO */
    { { {  -34,  42, 104,  16 },  {  -70,  96,  85,  27 },  {  -68,  94,  60,  25 },  {  -47,  79,  44,  16 } } },  /* 83: not started by a command */
    { { {  -21,  31,  94,  17 },  {  -43,  74,  85,  14 },  {  -43,  74,  40,  45 },  {  -43,  74,   0,  40 } } },  /* 84: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -33,  36,  74,  17 },  {  -42,  74,  60,  14 },  {  -40,  75,  38,  22 },  {  -40,  79,   0,  38 } } },  /* 85: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -23,  42,  32,  16 },  {  -32,  64,  48,  23 },  {  -30,  59,  71,  18 },  {  -30,  60,  70,  59 } } },  /* 86: ATTACK 8 S: not started by a command, ATTACK 8 SP: not started by a command */
    { { {   11,  45, 105,  18 },  {   -2,  63,  88,  28 },  {  -15,  70,  45,  43 },  {  -33,  83,   0,  45 } } },  /* 87: KAGAMI K A */
    { { {  -41,  51,  82,  19 },  {  -51,  77,  61,  26 },  {  -41,  78,  42,  27 },  {  -33,  84,   0,  42 } } },  /* 88: ATTACK 1 M: 623+P medium (routine Att_SENPUUKYAKU) */
    { { {    0,   0,   0,   0 },  {  -35,  19,  22,  20 },  {  -16,  36,  22,  20 },  {  -51, 102,   0,  22 } } },  /* 89: ATTACK 3 S: SA II 23623+P (plain script) */
    { { {   -2,  28,  93,  17 },  {  -27,  60,  78,  18 },  {  -27,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 90: UPPER L */
    { { {    6,  28,  92,  17 },  {  -24,  60,  78,  18 },  {  -28,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 91: UPPER L */
    { { {   10,  28,  91,  17 },  {  -22,  60,  78,  18 },  {  -29,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 92: not used by a script */
    { { {   12,  28,  90,  17 },  {  -21,  60,  78,  18 },  {  -30,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 93: UPPER L */
    { { {   -2,  28,  87,  17 },  {  -23,  60,  77,  18 },  {  -22,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 94: FACE S, FACE M, FACE L +7 */
    { { {   10,  28,  85,  17 },  {  -17,  60,  76,  18 },  {  -19,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 95: FACE M, FACE L, FOOK TEMAE L +3 */
    { { {   18,  28,  83,  17 },  {  -13,  60,  75,  18 },  {  -17,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 96: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    { { {   22,  28,  81,  17 },  {  -11,  60,  74,  18 },  {  -16,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 97: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    { { {  -22,  28,  86,  17 },  {  -29,  60,  76,  18 },  {  -24,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 98: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -26,  28,  83,  17 },  {  -27,  60,  74,  18 },  {  -22,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 99: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    { { {  -30,  28,  80,  17 },  {  -25,  60,  72,  18 },  {  -20,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 100: NOUTEN L, BODY BROW L, BODY UPPER L */
    { { {  -34,  28,  77,  17 },  {  -23,  60,  70,  18 },  {  -18,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 101: NOUTEN L, BODY BROW L, TATAKI S */
    { { {  -12,  28,  55,  18 },  {  -35,  69,  48,  18 },  {  -37,  71,  29,  19 },  {  -40,  83,   0,  29 } } },  /* 102: KAGAMI S, KAGAMI M, KAGAMI L +5 */
    { { {   -6,  28,  55,  18 },  {  -33,  69,  48,  18 },  {  -36,  71,  29,  19 },  {  -40,  83,   0,  29 } } },  /* 103: KAGAMI M, KAGAMI L, KGM TATAKI S +1 */
    { { {    0,  28,  55,  18 },  {  -31,  69,  48,  18 },  {  -35,  71,  29,  19 },  {  -40,  83,   0,  29 } } },  /* 104: KAGAMI L */
    { { {    6,  28,  55,  18 },  {  -29,  69,  48,  18 },  {  -34,  71,  29,  19 },  {  -40,  83,   0,  29 } } },  /* 105: KAGAMI L */
    { { {    4,  28,  60,  16 },  {  -14,  60,  53,  15 },  {  -25,  58,  41,  13 },  {  -33,  70,   0,  40 } } },  /* 106: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {    8,  28,  66,  16 },  {   -9,  61,  48,  28 },  {  -21,  55,  41,  20 },  {  -35,  74,   0,  41 } } },  /* 107: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {   -3,  28,  69,  16 },  {  -19,  61,  54,  26 },  {  -26,  54,  41,  17 },  {  -37,  74,   0,  41 } } },  /* 108: ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 6 L: 6(123)4+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {   -1,  28,  87,  17 },  {  -18,  60,  75,  18 },  {  -22,  52,  40,  35 },  {  -33,  70,   0,  40 } } },  /* 109: M PUNCH C */
    { { {   -9,  28,  85,  17 },  {  -23,  60,  71,  19 },  {  -23,  52,  40,  31 },  {  -36,  73,   0,  40 } } },  /* 110: M PUNCH C */
    { { {  -14,  28,  85,  17 },  {  -23,  60,  71,  19 },  {  -23,  52,  40,  31 },  {  -39,  78,   0,  40 } } },  /* 111: M PUNCH C */
    { { {  -20,  28,  81,  17 },  {  -29,  48,  69,  19 },  {  -30,  52,  40,  31 },  {  -47,  88,   0,  41 } } },  /* 112: M PUNCH C */
    { { {  -37,  28,  81,  17 },  {  -41,  61,  68,  22 },  {  -41,  57,  40,  28 },  {  -47,  88,   0,  41 } } },  /* 113: M PUNCH C */
    { { {  -25,  28,  81,  17 },  {  -31,  60,  71,  18 },  {  -25,  54,  40,  31 },  {  -29,  71,   0,  40 } } },  /* 114: M PUNCH C */
    { { {    0,   0,   0,   0 },  {  -24,  55,  72,  23 },  {  -21,  56,  52,  25 },  {  -24,  55,  30,  22 } } },  /* 115: AIR NORMAL, BODY UPPER, ALEX B.D */
    { { {    0,   0,   0,   0 },  {  -16,  56,  73,  21 },  {  -26,  58,  55,  24 },  {  -36,  57,  28,  28 } } },  /* 116: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {  -13,  56,  74,  24 },  {  -19,  51,  60,  21 },  {  -39,  57,  38,  37 } } },  /* 117: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {  -13,  56,  74,  24 },  {  -23,  53,  51,  28 },  {  -39,  42,  66,  37 } } },  /* 118: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {  -11,  54,  55,  25 },  {  -21,  53,  34,  28 },  {  -36,  36,  55,  34 } } },  /* 119: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {  -19,  57,  80,  26 },  {  -31,  51,  66,  28 },  {  -39,  50,  42,  27 } } },  /* 120: NOKEZORI, UPPER, HARAYARARE +5 */
    { { {    0,   0,   0,   0 },  {    9,  33,  67,  33 },  {  -18,  32,  62,  33 },  {  -49,  42,  53,  32 } } },  /* 121: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   11,  33,  63,  33 },  {  -15,  32,  66,  33 },  {  -49,  42,  58,  34 } } },  /* 122: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   12,  33,  61,  35 },  {  -14,  32,  69,  33 },  {  -47,  33,  64,  33 } } },  /* 123: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   12,  33,  56,  35 },  {  -16,  32,  69,  33 },  {  -49,  33,  68,  33 } } },  /* 124: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   10,  37,  53,  36 },  {  -15,  32,  65,  31 },  {  -49,  33,  66,  33 } } },  /* 125: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {    3,  45,  44,  33 },  {  -14,  34,  58,  34 },  {  -46,  35,  63,  39 } } },  /* 126: NOKEZORI, UPPER, BODY UPPER +10 */
    { { {    0,   0,   0,   0 },  {   -4,  51,  32,  33 },  {  -12,  46,  53,  34 },  {  -30,  42,  70,  31 } } },  /* 127: NOKEZORI, UPPER, BODY UPPER +11 */
    { { {    0,   0,   0,   0 },  {  -12,  59,  12,  24 },  {  -12,  59,  35,  22 },  {  -12,  56,  57,  30 } } },  /* 128: NOKEZORI, UPPER, BODY UPPER +11 */
    { { {    0,   0,   0,   0 },  {  -19,  55,  69,  23 },  {  -14,  56,  48,  25 },  {  -21,  55,  30,  22 } } },  /* 129: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -19,  55,  60,  26 },  {   -9,  56,  47,  25 },  {  -21,  55,  31,  22 } } },  /* 130: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -27,  55,  55,  26 },  {  -13,  56,  43,  25 },  {  -27,  55,  30,  22 } } },  /* 131: KUNOJI */
    { { {    0,   0,   0,   0 },  {   -5,  51,  76,  22 },  {  -18,  58,  55,  24 },  {  -26,  62,  26,  29 } } },  /* 132: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -1,  51,  78,  23 },  {  -18,  58,  55,  24 },  {  -26,  62,  26,  29 } } },  /* 133: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    3,  54,  73,  31 },  {   -9,  54,  55,  29 },  {  -23,  62,  28,  27 } } },  /* 134: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   15,  55,  71,  32 },  {   -4,  57,  56,  26 },  {  -17,  56,  33,  24 } } },  /* 135: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   23,  44,  70,  29 },  {    5,  50,  54,  26 },  {  -20,  57,  29,  30 } } },  /* 136: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   27,  44,  64,  33 },  {    6,  50,  53,  26 },  {  -18,  57,  30,  25 } } },  /* 137: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   29,  44,  56,  37 },  {    6,  46,  43,  35 },  {  -23,  57,  26,  30 } } },  /* 138: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   31,  45,  53,  37 },  {    5,  46,  44,  35 },  {  -31,  52,  25,  39 } } },  /* 139: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   30,  45,  53,  33 },  {    4,  44,  44,  32 },  {  -33,  49,  32,  39 } } },  /* 140: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   26,  45,  48,  38 },  {    3,  44,  40,  35 },  {  -33,  45,  29,  32 } } },  /* 141: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   22,  45,  43,  41 },  {   -3,  39,  33,  37 },  {  -35,  45,  25,  40 } } },  /* 142: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   25,  43,  38,  43 },  {   -1,  36,  35,  37 },  {  -36,  45,  25,  41 } } },  /* 143: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   25,  42,  35,  39 },  {   -3,  36,  32,  35 },  {  -38,  39,  25,  36 } } },  /* 144: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   25,  42,  31,  39 },  {   -4,  34,  26,  35 },  {  -42,  39,  24,  36 } } },  /* 145: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   27,  36,  22,  39 },  {   -5,  31,  22,  38 },  {  -44,  39,  19,  42 } } },  /* 146: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   25,  36,   5,  39 },  {   -5,  31,   5,  37 },  {  -44,  39,  11,  37 } } },  /* 147: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -24,  55,  80,  23 },  {  -21,  48,  55,  25 },  {  -28,  55,  33,  22 } } },  /* 148: UPPER, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -17,  55,  82,  23 },  {  -18,  48,  57,  25 },  {  -21,  55,  32,  25 } } },  /* 149: UPPER, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -22,  55,  76,  23 },  {  -22,  54,  52,  25 },  {  -28,  51,  30,  22 } } },  /* 150: BODY UPPER, ALEX B.D */
    { { {    0,   0,   0,   0 },  {  -11,  53,  74,  27 },  {  -24,  49,  57,  26 },  {  -43,  49,  42,  26 } } },  /* 151: BODY UPPER, ALEX B.D */
    { { {    0,   0,   0,   0 },  {  -24,  54,  65,  23 },  {  -20,  54,  47,  21 },  {  -26,  55,  26,  22 } } },  /* 152: HARAYARARE, HANEKAERI HARA */
    { { {    0,   0,   0,   0 },  {  -24,  55,  70,  23 },  {  -14,  48,  52,  21 },  {  -24,  56,  29,  25 } } },  /* 153: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -16,  51,  50,  24 },  {   -5,  49,  39,  30 },  {  -16,  56,  27,  23 } } },  /* 154: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -22,  55,  76,  23 },  {  -19,  47,  53,  24 },  {  -12,  54,  32,  24 } } },  /* 155: HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -35,  44,  29,  28 },  {  -19,  37,  39,  33 },  {   11,  33,  26,  43 } } },  /* 156: HUMI ASIB, TOMOE RYU, FLANKEN.S */
    { { {    0,   0,   0,   0 },  {   -5,  52,  70,  24 },  {  -11,  47,  52,  25 },  {  -22,  55,  30,  22 } } },  /* 157: FACE */
    { { {    0,   0,   0,   0 },  {  -16,  52,  85,  20 },  {  -23,  45,  61,  24 },  {  -18,  49,  35,  26 } } },  /* 158: DENKI */
    { { {    0,   0,   0,   0 },  {   -8,  54,  70,  25 },  {  -13,  54,  54,  20 },  {  -22,  55,  28,  29 } } },  /* 159: TOUKETSU A */
    { { {    0,   0,   0,   0 },  {  -22,  55,  66,  22 },  {  -22,  55,  45,  21 },  {  -19,  49,  31,  14 } } },  /* 160: BODY SLAM, IPPONZEOI, TOMOE RYU +3 */
    { { {  -21,  28,  87,  17 },  {  -32,  60,  76,  18 },  {  -28,  52,  41,  35 },  {  -34,  70,   0,  40 } } },  /* 161: KAMAE */
    { { {  -15,  28,  87,  17 },  {  -30,  62,  76,  18 },  {  -25,  53,  41,  35 },  {  -32,  68,   0,  40 } } },  /* 162: KAMAE */
    { { {  -15,  28,  92,  17 },  {  -28,  57,  78,  18 },  {  -23,  49,  41,  36 },  {  -23,  54,   0,  40 } } },  /* 163: KAMAE */
    { { {  -14,  28,  89,  17 },  {  -28,  57,  76,  18 },  {  -23,  49,  41,  34 },  {  -23,  54,   0,  40 } } },  /* 164: KAMAE */
    { { {  -14,  28,  88,  17 },  {  -28,  57,  76,  18 },  {  -26,  52,  41,  35 },  {  -32,  68,   0,  40 } } },  /* 165: KAMAE */
    { { {  -21,  28,  85,  17 },  {  -30,  59,  75,  18 },  {  -26,  50,  41,  34 },  {  -30,  66,   0,  40 } } },  /* 166: KAMAE */
    { { {  -18,  25, 100,  17 },  {  -38,  64,  82,  20 },  {  -29,  52,  41,  41 },  {  -32,  68,   0,  40 } } },  /* 167: HURIMUKI */
    { { {  -18,  28,  89,  17 },  {  -27,  56,  78,  18 },  {  -26,  52,  41,  36 },  {  -32,  70,   0,  40 } } },  /* 168: FRONT WALK */
    { { {  -17,  28, 101,  17 },  {  -23,  52,  86,  21 },  {  -23,  47,  43,  43 },  {  -22,  46,   0,  43 } } },  /* 169: FRONT WALK */
    { { {  -17,  28,  93,  17 },  {  -30,  62,  78,  20 },  {  -23,  53,  41,  36 },  {  -36,  76,   0,  40 } } },  /* 170: BACK WALK */
    { { {  -12,  26, 105,  17 },  {  -29,  62,  86,  18 },  {  -23,  55,  43,  43 },  {  -24,  58,   0,  43 } } },  /* 171: BACK WALK */
    { { {  -35,  28,  84,  17 },  {  -32,  51,  73,  20 },  {  -27,  56,  43,  30 },  {  -35,  77,   0,  43 } } },  /* 172: DASH HUMIKOMI */
    { { {  -48,  28,  61,  18 },  {  -35,  54,  60,  22 },  {  -29,  56,  40,  22 },  {  -33,  71,   0,  40 } } },  /* 173: DASH HUMIKOMI */
    { { {  -15,  26,  95,  18 },  {  -29,  60,  79,  20 },  {  -26,  56,  43,  36 },  {  -29,  71,   0,  43 } } },  /* 174: DASH TOBINOKI */
    { { {  -14,  26,  94,  17 },  {  -31,  60,  78,  18 },  {  -26,  52,  41,  36 },  {  -32,  68,   0,  40 } } },  /* 175: DASH TOBINOKI */
    { { {  -20,  28,  84,  17 },  {  -30,  58,  72,  18 },  {  -27,  53,  40,  32 },  {  -36,  72,   0,  40 } } },  /* 176: DASH TOBINOKI */
    { { {  -21,  28,  52,  18 },  {  -39,  70,  47,  18 },  {  -38,  71,  29,  18 },  {  -40,  83,   0,  29 } } },  /* 177: KAGAMI KAMAE */
    { { {  -14,  28,  52,  18 },  {  -35,  70,  47,  18 },  {  -38,  71,  29,  18 },  {  -40,  83,   0,  29 } } },  /* 178: KAGAMI KAMAE */
    { { {  -17,  28,  60,  18 },  {  -37,  72,  49,  18 },  {  -38,  79,  29,  20 },  {  -40,  83,   0,  29 } } },  /* 179: KAGAMI TURN */
    { { {  -23,  28,  67,  17 },  {  -41,  69,  56,  20 },  {  -38,  70,  31,  25 },  {  -40,  83,   0,  31 } } },  /* 180: STAND UP */
    { { {  -17,  27,  97,  17 },  {  -31,  60,  80,  20 },  {  -26,  52,  41,  39 },  {  -32,  68,   0,  41 } } },  /* 181: STAND UP */
    { { {   -1,  30, 103,  17 },  {  -28,  61,  88,  20 },  {  -26,  54,  64,  24 },  {  -25,  52,  41,  23 } } },  /* 182: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    { { {  -15,  30, 103,  17 },  {  -31,  57,  88,  20 },  {  -26,  53,  64,  24 },  {  -29,  53,  41,  23 } } },  /* 183: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    { { {  -34,  26,  90,  18 },  {  -33,  58,  82,  22 },  {  -30,  58,  63,  19 },  {  -34,  60,  43,  20 } } },  /* 184: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    { { {  -35,  25,  83,  18 },  {  -36,  62,  81,  21 },  {  -33,  61,  63,  18 },  {  -36,  61,  45,  18 } } },  /* 185: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    { { {  -11,  28, 100,  18 },  {  -28,  60,  88,  20 },  {  -25,  53,  64,  24 },  {  -26,  52,  41,  23 } } },  /* 186: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    { { {  -29,  28,  80,  17 },  {  -37,  61,  74,  25 },  {  -34,  65,  39,  35 },  {  -33,  68,   0,  40 } } },  /* 187: TUKAMIHAZUSARE */
    { { {  -54,  29,  48,  18 },  {  -46,  60,  55,  28 },  {  -40,  65,  29,  29 },  {  -39,  80,   0,  29 } } },  /* 188: PIYO */
};

const HAND_BOX dudley_hand_box[35] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -74,  33,  20,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: L KICK C */
    { { {  -88,  63,  78,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A, follow-up of S PUNCH A, ATTACK 10 M: not started by a command +1 */
    { { {  -94,  66,  74,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A, follow-up of follow-up of S KICK A, follow-up of S PUNCH A +4 */
    { { {  -65,  43,  69,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S KICK A */
    { { {  -90,  63,  62,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH C */
    { { {  -72,  46,  63,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M KICK C, ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -72,  46,  65,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L KICK A, no name, follow-up of M KICK A +1 */
    { { {  -74,  50,  84,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: L KICK A, no name, follow-up of M KICK A +5 */
    { { {  -91,  11,  61,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH A, L PUNCH C, follow-up of follow-up of M PUNCH A, M KICK C +6 */
    { { {  -81,  44,  39,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -83,  44,  52,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A, follow-up of JUDGMENT WAIT, follow-up of follow-up of JUDGMENT WAIT */
    { { {  -83,  46,  57,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -79,  48,  76,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -79,  48,  76,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A, follow-up of follow-up of follow-up of S KICK A, follow-up of M KICK A, follow-up of follow-up of JUDGMENT WAIT +4 */
    { { {  -80,  52,  17,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A */
    { { {  -80,  37,  19,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI K A */
    { { {  -87,  39,  16,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI K A */
    { { {  -75,  47,  82,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P S A, F JUMP P S A, no name */
    { { {  -75,  47,  83,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP P M A, F JUMP P M A */
    { { {  -43,  14,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -73,  41,  99,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M KICK A, follow-up of L KICK C, KAGAMI K A +1, follow-up of M PUNCH A, M KICK C +4 */
    { { {  -56,  44,  75,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K S A, F JUMP K S A */
    { { {  -49,  36,  65,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: V JUMP K M A, F JUMP K M A */
    { { {  -88,  66,  62,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: ATTACK 13 M: not started by a command */
    { { {  -87,  55,  51,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: ATTACK 13 L: not started by a command */
    { { {  -81,  50,  72,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: ATTACK 13 L: not started by a command */
    { { {  -72,  28,  60,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: ATTACK 2 S: SA III 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -37,  35,  21,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: not used by a script */
    { { {  -37,  35,   7,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: ATTACK 8 S: not started by a command, ATTACK 8 SP: not started by a command */
    { { {  -82,  41,  54,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: M PUNCH C */
    { { {  -82,  41,  53,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: M PUNCH C */
    { { {  -74,  33,  55,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: M PUNCH C */
    { { {  -48,  23,  66,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: M PUNCH C */
    { { {  -65,  34,  76,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: TUKAMIHAZUSARE, TUKAMIKAKARI A */
};

const HOSEI_BOX dudley_hos_box[30] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   91 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +116 */
    { {  -25,   50,    0,   86 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -25,   50,    0,   61 } },  /* 3: KAGAMU, KAGAMI TURN, PARING DOWN +67 */
    { {  -20,   57,    0,   91 } },  /* 4: M KICK C, ATTACK 6 S: 6(123)4+K light (routine Att_CHOUCHUURENGEKI), ATTACK 6 M: 6(123)4+K medium (routine Att_CHOUCHUURENGEKI) +2 */
    { {  -25,   50,   49,   48 } },  /* 5: V JUMP K L A, follow-up of AIR NORMAL, follow-up of APPEAR JUNBI 5 +31 */
    { {  -12,   57,    0,   91 } },  /* 6: not used by a script */
    { {   -4,   57,    0,   91 } },  /* 7: not used by a script */
    { {  -24,   57,    0,   91 } },  /* 8: not used by a script */
    { {    4,   57,    0,   91 } },  /* 9: not used by a script */
    { {  -25,   50,    0,   70 } },  /* 10: PIYO */
    { {  -28,   57,    0,   40 } },  /* 11: ATTACK 12 M: after 6(123)4+P (plain script), 6(123)456+P (plain script), ATTACK 13 S: after 6(123)4+P (plain script), 6(123)456+P (plain script) */
    { {  -28,   57,    0,   50 } },  /* 12: ATTACK 7 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    { {  -12,   57,    0,   58 } },  /* 13: ATTACK 3 S: SA II 23623+P (plain script) */
    { {  -42,   71,    0,   91 } },  /* 14: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -17,   47,    6,   91 } },  /* 15: not used by a script */
    { {  -18,   48,   27,   48 } },  /* 16: not used by a script */
    { {  -32,   48,   27,   48 } },  /* 17: not used by a script */
    { {  -29,   48,   19,   44 } },  /* 18: not used by a script */
    { {  -55,   93,   19,   44 } },  /* 19: ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 M: 4(123)6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +12 */
    { {  -25,   50,    0,   73 } },  /* 20: PIYO, STAND UP, SP JUMP JUNBI */
    { {  -33,   57,    0,   91 } },  /* 21: not used by a script */
    { {  -53,   81,   41,   37 } },  /* 22: not used by a script */
    { {  -49,   94,   19,   44 } },  /* 23: not used by a script */
    { {  -20,   51,   40,   44 } },  /* 24: AIR NORMAL, BODY UPPER, ALEX B.D +28 */
    { {  -39,   74,    0,   79 } },  /* 25: ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU), ATTACK 5 SP: EX 4(123)6+PP (routine Att_SENPUUKYAKU) */
    { {  -28,   57,    0,   30 } },  /* 26: no name, NEKOROBI S */
    { {  -38,   67,    0,   91 } },  /* 27: ATTACK 5 S: 4(123)6+P light (routine Att_SENPUUKYAKU), ATTACK 5 M: 4(123)6+P medium (routine Att_SENPUUKYAKU), ATTACK 5 L: 4(123)6+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -28,   84,    0,   74 } },  /* 28: ATTACK 3 S: SA II 23623+P (plain script) */
    { {  -25,   50,    0,   76 } },  /* 29: JUMP JUNBI, ATTACK 3 S: SA II 23623+P (plain script), ATTACK 9 L: 4(123)6+K medium (routine Att_CHOUCHUURENGEKI) +21 */
};
