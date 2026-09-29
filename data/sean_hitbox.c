/*
 * SEAN_HITBOX.C  Sean's hit boxes
 *
 * Each of Sean's animation frames names an entry of sean_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX sean_hit_ix_table[272] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +85 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +32 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +22 */
    {    5,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 5: JUMP JUNBI, SP JUMP JUNBI */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 6: DASH TOBINOKI, KAGAMU, L PUNCH C +18 */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: not used by a script */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: not used by a script */
    {    8,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: PARING HEAD */
    {    9,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 10: PARING HEAD */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 11: NEKOROBI S, no name, HANEAGARI +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 12: OKIAGARI, OKIAGARI F, OKIAGARI B +12 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 13: not used by a script */
    {   10,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 14: not used by a script */
    {   11,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 15: not used by a script */
    {   12,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 16: GUARD AIR */
    {   13,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 17: no name */
    {   14,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 18: no name */
    {    1,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 19: not used by a script */
    {    1,    0,    1, 0x0000,    0,    1,    2,    1 },  /* 20: not used by a script */
    {    1,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 21: not used by a script */
    {    1,    0,    2, 0x0000,    0,    1,    3,    1 },  /* 22: S PUNCH A */
    {    1,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 23: S PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 24: M PUNCH A */
    {    1,    0,    3, 0x0000,    0,    1,    5,    1 },  /* 25: M PUNCH B */
    {    1,    0,    3, 0x0000,    0,    1,    6,    1 },  /* 26: M PUNCH B */
    {    1,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 27: M PUNCH B */
    {   15,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 28: ATTACK 12 S: not started by a command, ATTACK 12 M: not started by a command, ATTACK 12 SP: not started by a command */
    {   31,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 29: ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI), ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 30: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 32: L PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,   10,    1 },  /* 33: L PUNCH A */
    {   16,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH A */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 35: not used by a script */
    {   17,    0,    0, 0x0000,    0,    1,   11,    1 },  /* 36: not used by a script */
    {   18,    0,    6, 0x0000,    0,    5,   12,    1 },  /* 37: S KICK A */
    {   18,    0,    6, 0x0000,    0,    5,    0,    1 },  /* 38: S KICK A */
    {   50,    0,   20, 0x0000,    0,    3,   75,    3 },  /* 39: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   50,    0,   21, 0x0000,    0,    3,   76,    3 },  /* 40: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   50,    0,   22, 0x0000,    0,    3,   77,    3 },  /* 41: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: M KICK A */
    {   21,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 43: M KICK A */
    {   21,    0,    8, 0x0000,    0,    1,   14,    1 },  /* 44: M KICK A */
    {   21,    0,    8, 0x0000,    0,    1,   15,    1 },  /* 45: M KICK A */
    {   22,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 46: follow-up of M PUNCH A */
    {   22,    0,    9, 0x0000,    0,    1,   16,    1 },  /* 47: follow-up of M PUNCH A */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: follow-up of M PUNCH A */
    {   36,    0,   35, 0x0000,    0,    3,   74,    3 },  /* 49: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 50: ATTACK 10 S: not started by a command */
    {    2,    0,   10, 0x0000,    0,    4,   19,    2 },  /* 51: KAGAMI P A */
    {    2,    0,   10, 0x0000,    0,    4,    0,    2 },  /* 52: KAGAMI P A */
    {    2,    0,    0, 0x0000,    0,    2,   20,    2 },  /* 53: KAGAMI P A */
    {   23,    0,    0, 0x0000,    0,    2,   21,    2 },  /* 54: KAGAMI P A */
    {   24,    0,    0, 0x0000,    0,    1,   22,    1 },  /* 55: KAGAMI P A */
    {   24,    0,   11, 0x0000,    0,    1,   23,    1 },  /* 56: KAGAMI P A */
    {   24,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 57: KAGAMI P A */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 58: KAGAMI P A */
    {   23,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 59: KAGAMI P A */
    {    2,    0,   12, 0x0000,    0,    4,   24,    2 },  /* 60: KAGAMI K A */
    {    2,    0,   13, 0x0000,    0,    2,   17,    2 },  /* 61: KAGAMI K A */
    {    2,    0,   13, 0x0000,    0,    2,   18,    2 },  /* 62: KAGAMI K A */
    {    2,    0,   13, 0x0000,    0,    2,    0,    2 },  /* 63: KAGAMI K A */
    {    2,    0,   14, 0x0000,    0,    2,   25,    2 },  /* 64: KAGAMI K A */
    {    2,    0,   14, 0x0000,    0,    2,    0,    2 },  /* 65: KAGAMI K A */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 66: V JUMP P S A, F JUMP P S A */
    {   25,    0,   15, 0x0000,    0,    3,   26,    3 },  /* 67: V JUMP P S A, F JUMP P S A */
    {   25,    0,   16, 0x0000,    0,    3,    0,    3 },  /* 68: V JUMP P S A, F JUMP P S A */
    {   26,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 69: V JUMP P M A, F JUMP P M A, F JUMP P L A +1 */
    {   26,    0,   17, 0x0000,    0,    3,   27,    3 },  /* 70: V JUMP P M A, F JUMP P M A */
    {   26,    0,   17, 0x0000,    0,    3,   28,    3 },  /* 71: V JUMP P M A, F JUMP P M A */
    {   26,    0,   18, 0x0000,    0,    3,   29,    3 },  /* 72: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    {   26,    0,   18, 0x0000,    0,    3,    0,    3 },  /* 73: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 74: ATTACK 4 S: SA I 23623+P (plain script), ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   27,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 75: ATTACK 4 S: SA I 23623+P (plain script) */
    {   27,    0,   19, 0x0000,    0,    1,    0,    5 },  /* 76: ATTACK 4 S: SA I 23623+P (plain script) */
    {   28,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 77: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   29,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 78: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {   29,    0,    0, 0x0000,    2,    2,    0,    2 },  /* 79: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   30,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 80: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   47,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 81: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   48,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 82: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   49,    0,    0, 0x0000,    0,    3,    0,    6 },  /* 83: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   50,    0,   23, 0x0000,    0,    3,    0,    6 },  /* 84: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   50,    0,   20, 0x0000,    0,    3,   31,    6 },  /* 85: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   50,    0,   21, 0x0000,    0,    3,   32,    6 },  /* 86: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   50,    0,   22, 0x0000,    0,    3,   33,    6 },  /* 87: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    {   50,    0,   23, 0x0000,    0,    3,   34,    6 },  /* 88: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    0,    0,    0, 0x0000,    0,    0,    7,    1 },  /* 89: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,    8,    3 },  /* 90: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   51,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 91: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   52,    0,    0, 0x0000,    0,    1,    7,    1 },  /* 92: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   53,    0,    0, 0x0000,    0,    3,    8,    3 },  /* 93: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   38,    0,    0, 0x0000,    0,    1,   58,    5 },  /* 94: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   38,    0,    0, 0x0000,    0,    1,   59,    5 },  /* 95: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 96: follow-up of AIR NORMAL */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 97: TUKAMIKAKARI A */
    {   26,    0,   24, 0x0000,    0,    3,   40,    3 },  /* 98: F JUMP P L A */
    {   26,    0,   24, 0x0000,    0,    3,   41,    3 },  /* 99: F JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   42,    3 },  /* 100: not used by a script */
    {    4,    0,    0, 0x0000,    0,    3,   43,    3 },  /* 101: not used by a script */
    {    4,    0,   25, 0x0000,    0,    3,   43,    3 },  /* 102: not used by a script */
    {    4,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 103: not used by a script */
    {    4,    0,    0, 0x0000,    0,    3,   44,    3 },  /* 104: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   45,    3 },  /* 105: V JUMP P L A */
    {    4,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 106: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   46,    3 },  /* 107: V JUMP K S A, F JUMP K S A */
    {    4,    0,    0, 0x0000,    0,    3,   47,    3 },  /* 108: V JUMP K S A, F JUMP K S A */
    {   33,    0,    0, 0x0000,    0,    3,   48,    3 },  /* 109: V JUMP K M A */
    {   33,    0,   27, 0x0000,    0,    3,   49,    3 },  /* 110: V JUMP K M A */
    {   33,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP K M A */
    {    4,    0,   28, 0x0000,    0,    3,   50,    3 },  /* 112: V JUMP K L A */
    {    4,    0,   28, 0x0000,    0,    3,   51,    3 },  /* 113: V JUMP K L A */
    {    4,    0,   28, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   34,    0,   30, 0x0000,    0,    3,   52,    3 },  /* 115: F JUMP K M A */
    {   34,    0,   31, 0x0000,    0,    3,   53,    3 },  /* 116: F JUMP K M A */
    {   34,    0,   32, 0x0000,    0,    3,    0,    3 },  /* 117: F JUMP K M A, F JUMP K L A */
    {   34,    0,   33, 0x0000,    0,    3,   54,    3 },  /* 118: F JUMP K L A */
    {   34,    0,   34, 0x0000,    0,    3,   55,    3 },  /* 119: F JUMP K L A */
    {   35,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 120: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +2 */
    {   36,    0,   35, 0x0000,    0,    3,   56,    3 },  /* 121: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +1 */
    {   36,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +2 */
    {   37,    0,   35, 0x0000,    0,    3,   57,    3 },  /* 123: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    {   37,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 124: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   35,    1 },  /* 125: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    0,    0,    0, 0x0000,    0,    0,   35,    1 },  /* 126: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   54,    0,    0, 0x0000,    0,    0,   35,    1 },  /* 127: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   54,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 128: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   36,    1 },  /* 129: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   37,    1 },  /* 130: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   79,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 131: L KICK C */
    {   80,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 132: L KICK C */
    {   81,    0,   42, 0x0000,    0,    3,   70,    3 },  /* 133: L KICK C */
    {   82,    0,   43, 0x0000,    0,    3,   71,    3 },  /* 134: L KICK C */
    {   83,    0,   44, 0x0000,    0,    3,    0,    3 },  /* 135: L KICK C */
    {   84,    0,   45, 0x0000,    0,    3,    0,    1 },  /* 136: L KICK C */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 137: not used by a script */
    {   40,    0,   36, 0x0000,    0,    3,   63,    3 },  /* 138: ATTACK 10 S: not started by a command */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 139: L PUNCH C, follow-up of L PUNCH A */
    {   42,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 140: L PUNCH C, follow-up of L PUNCH A */
    {   43,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 141: L PUNCH C, follow-up of L PUNCH A */
    {   44,    0,   37, 0x0000,    0,    1,   64,    2 },  /* 142: L PUNCH C, follow-up of L PUNCH A */
    {   45,    0,   38, 0x0000,    0,    1,   65,    2 },  /* 143: L PUNCH C, follow-up of L PUNCH A */
    {   45,    0,   39, 0x0000,    0,    1,   66,    2 },  /* 144: L PUNCH C, follow-up of L PUNCH A */
    {   45,    0,   39, 0x0000,    0,    1,    0,    2 },  /* 145: L PUNCH C, follow-up of L PUNCH A */
    {   46,    0,   40, 0x0000,    0,    1,    0,    2 },  /* 146: L PUNCH C, follow-up of L PUNCH A */
    {   55,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 147: UPPER L */
    {   56,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 148: UPPER L, BODY UPPER L */
    {   57,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 149: UPPER L, BODY UPPER L */
    {   58,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 150: BODY UPPER L */
    {   59,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 151: FACE S, FACE M, FACE L +9 */
    {   60,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 152: FACE M, FACE L, FOOK OKU L +3 */
    {   61,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 153: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    {   62,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 154: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {   63,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 155: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {   64,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 156: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {   65,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 157: NOUTEN L, BODY BROW M, BODY BROW L */
    {   66,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 158: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    {   67,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 159: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {   68,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 160: KAGAMI S, KAGAMI M, KAGAMI L */
    {   69,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 161: KAGAMI M, KAGAMI L */
    {   70,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 162: KAGAMI L */
    {   71,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 163: L PUNCH B */
    {   72,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 164: L PUNCH B */
    {   73,    0,    0, 0x0000,    0,    1,   68,    5 },  /* 165: L PUNCH B */
    {   74,    0,   41, 0x0000,    0,    1,   69,    5 },  /* 166: L PUNCH B */
    {   75,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 167: L PUNCH B */
    {   76,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 168: L PUNCH B */
    {   77,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 169: L PUNCH B */
    {   78,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 170: L PUNCH B */
    {   85,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 171: L KICK B */
    {   86,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 172: L KICK B */
    {   87,    0,   46, 0x0000,    0,    1,   72,    5 },  /* 173: L KICK B */
    {   87,    0,   46, 0x0000,    0,    1,   73,    5 },  /* 174: L KICK B */
    {   87,    0,   47, 0x0000,    0,    1,    0,    5 },  /* 175: L KICK B */
    {   88,    0,   48, 0x0000,    0,    1,    0,    5 },  /* 176: L KICK B */
    {   89,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 177: L KICK B */
    {   90,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 178: L KICK B */
    {   91,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 179: L KICK B */
    {   92,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 180: L KICK B */
    {   93,    0,    0, 0x0000,    0,    3,   60,    3 },  /* 181: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   94,    0,    0, 0x0000,    0,    3,   61,    3 },  /* 182: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   95,    0,    0, 0x0000,    0,    3,   62,    3 },  /* 183: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 184: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   96,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 185: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    {  131,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 186: L KICK A */
    {  132,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 187: L KICK A */
    {  133,    0,    0, 0x0000,    0,    1,   38,    1 },  /* 188: L KICK A */
    {  133,    0,    0, 0x0000,    0,    1,   39,    1 },  /* 189: L KICK A */
    {  133,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 190: L KICK A */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 191: L KICK A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 192: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 193: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 194: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 195: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 196: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 197: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 198: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 199: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 200: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 201: not used by a script */
    {   32,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 202: LOSE SONABA, SHIMEOTASARE */
    {   97,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 203: LOSE SONABA, SHIMEOTASARE */
    {   98,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 204: LOSE SONABA, SHIMEOTASARE */
    {   99,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 205: LOSE SONABA, SHIMEOTASARE */
    {  100,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 206: TATI DENGEKI S, TATI DENGEKI M, TATI DENGEKI L */
    {  101,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 207: AIR NORMAL, KUNOJI, HARAYARARE +1 */
    {  102,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 208: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  103,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 209: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  104,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 210: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  105,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 211: NOKEZORI, UPPER, BODY UPPER +5 */
    {  106,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 212: NOKEZORI, UPPER, BODY UPPER +6 */
    {  107,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 213: NOKEZORI, UPPER, BODY UPPER +6 */
    {  108,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 214: NOKEZORI, UPPER, BODY UPPER +7 */
    {  109,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 215: NOKEZORI, UPPER, BODY UPPER +7 */
    {  110,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 216: NOKEZORI, UPPER, BODY UPPER +7 */
    {  111,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 217: NOKEZORI, UPPER, BODY UPPER +7 */
    {  112,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 218: NOKEZORI, UPPER, BODY UPPER +7 */
    {  113,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 219: KUNOJI, TTKI V. AIR, KUNOJI NOKE */
    {  114,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 220: KIRIMOMI */
    {  115,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 221: KIRIMOMI */
    {  116,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 222: KIRIMOMI */
    {  117,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 223: KIRIMOMI */
    {  118,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 224: KIRIMOMI */
    {  119,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 225: UPPER, TATUMAKIZANKU */
    {  120,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 226: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    {  121,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 227: UPPER, HARAYARARE, BODY UPPER SP +1 */
    {  122,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 228: BODY UPPER */
    {  123,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 229: BODY UPPER */
    {  124,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 230: FACE */
    {  125,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 231: DENKI */
    {  126,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 232: TOUKETSU A */
    {  127,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 233: HUMI ASIB */
    {  128,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 234: HUMI ASIB */
    {  129,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 235: TTKI V. AIR */
    {  130,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 236: BODY SLAM, IPPONZEOI, TOMOE RYU +10 */
    {    1,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 237: KAMAE */
    {  135,    0,    0, 0x1011,    0,    1,    0,    1 },  /* 238: KAMAE */
    {  136,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 239: HURIMUKI */
    {  137,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 240: FRONT WALK */
    {  138,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 241: FRONT WALK */
    {  138,    0,    0, 0x1616,    0,    1,    0,    1 },  /* 242: FRONT WALK */
    {  139,    0,    0, 0x1616,    0,    1,    0,    1 },  /* 243: FRONT WALK */
    {  140,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 244: BACK WALK */
    {  141,    0,    0, 0x1919,    0,    1,    0,    1 },  /* 245: BACK WALK */
    {  142,    0,    0, 0x1912,    0,    1,    0,    1 },  /* 246: BACK WALK */
    {  143,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 247: BACK WALK */
    {  144,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 248: KAGAMU */
    {  145,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 249: KAGAMI TURN */
    {  146,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 250: JUMP FRONT, SP JUMP FRONT */
    {  147,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 251: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  148,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 252: JUMP FRONT, SP JUMP FRONT */
    {  148,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 253: JUMP BACK, SP JUMP BACK */
    {  146,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 254: JUMP BACK, SP JUMP BACK, no name */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 255: JUMP VERTICAL, SP JUMP V */
    {  149,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 256: JUMP VERTICAL, SP JUMP V */
    {    5,    0,    0, 0x1010,    0,    1,    0,    5 },  /* 257: DASH HUMIKOMI */
    {  150,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 258: DASH HUMIKOMI */
    {  151,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 259: DASH HUMIKOMI */
    {  152,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 260: DASH HUMIKOMI */
    {  153,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 261: DASH TOBINOKI */
    {  154,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 262: DASH TOBINOKI */
    {  155,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 263: DASH TOBINOKI */
    {  156,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 264: DASH TOBINOKI */
    {  157,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 265: PIYO */
    {  158,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 266: PIYO */
    {  159,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 267: PIYO */
    {  160,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 268: PIYO */
    {  161,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 269: PIYO */
    {  162,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 270: KAGAMI KAMAE */
    {  163,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 271: KAGAMI KAMAE */
};

const BODY_BOX sean_body_box[164] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -14,  22,  83,  18 },  {  -27,  55,  72,  19 },  {  -23,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +86 */
    { { {  -14,  22,  50,  19 },  {  -23,  54,  45,  16 },  {  -25,  54,  28,  18 },  {  -35,  69,   0,  32 } } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +32 */
    { { {    0,   0,   0,   0 },  {  -28,  57,  45,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    { { {  -14,  22,  91,  17 },  {  -25,  50,  80,  18 },  {  -27,  52,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +22 */
    { { {  -20,  24,  64,  18 },  {  -30,  58,  56,  18 },  {  -26,  56,  36,  20 },  {  -36,  70,   0,  36 } } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +22 */
    { { {  -22,  24,  74,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  38,  26 },  {  -38,  76,   0,  36 } } },  /* 6: not used by a script */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 7: not used by a script */
    { { {  -14,  24,  74,  18 },  {  -30,  60,  66,  16 },  {  -22,  54,  38,  26 },  {  -30,  66,   0,  36 } } },  /* 8: PARING HEAD */
    { { {  -14,  24,  62,  18 },  {  -34,  64,  52,  18 },  {  -24,  58,  36,  20 },  {  -38,  82,   0,  36 } } },  /* 9: PARING HEAD */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 10: not used by a script */
    { { {  -14,  24,  82,  18 },  {  -32,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 11: not used by a script */
    { { {    4,  24,  82,  18 },  {  -18,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -32,  66,   0,  36 } } },  /* 12: GUARD AIR */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 13: no name */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 14: no name */
    { { {  -14,  20,  98,  18 },  {  -32,  54,  92,  12 },  {  -28,  46,  58,  32 },  {  -30,  48,  20,  36 } } },  /* 15: ATTACK 12 S: not started by a command, ATTACK 12 M: not started by a command, ATTACK 12 SP: not started by a command */
    { { {  -26,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 16: L PUNCH A */
    { { {   -8,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -30,  60,  38,  32 },  {  -42,  76,   0,  36 } } },  /* 17: not used by a script */
    { { {  -16,  24,  82,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -58,  91,   0,  36 } } },  /* 18: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: no box */
    { { {  -22,  22,  80,  18 },  {  -29,  59,  72,  18 },  {  -24,  54,  38,  32 },  {  -30,  63,   0,  36 } } },  /* 20: M KICK A */
    { { {  -22,  22,  80,  18 },  {  -29,  59,  72,  18 },  {  -24,  54,  38,  32 },  {  -12,  45,   0,  36 } } },  /* 21: M KICK A */
    { { {   -2,  24,  82,  18 },  {  -24,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -18,  42,   0,  36 } } },  /* 22: follow-up of M PUNCH A */
    { { {  -14,  24,  64,  18 },  {  -30,  60,  60,  14 },  {  -28,  60,  34,  24 },  {  -38,  72,   0,  32 } } },  /* 23: KAGAMI P A */
    { { {   -6,  24,  76,  18 },  {  -28,  60,  68,  14 },  {  -28,  60,  34,  32 },  {  -38,  72,   0,  32 } } },  /* 24: KAGAMI P A */
    { { {  -36,  24,  90,  18 },  {  -50,  76,  80,  18 },  {  -24,  62,  44,  34 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP P S A, F JUMP P S A */
    { { {  -30,  24,  92,  18 },  {  -36,  62,  80,  18 },  {  -32,  68,  42,  36 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P M A, F JUMP P M A, F JUMP P L A +1 */
    { { {  -24,  24,  70,  18 },  {  -32,  62,  60,  18 },  {  -24,  54,  38,  20 },  {  -42,  92,   0,  36 } } },  /* 27: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {    0,   0,   0,   0 },  {  -46,  68,  54,  16 },  {  -42,  64,  34,  18 },  {  -50,  84,   0,  32 } } },  /* 28: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {    0,   0,   0,   0 },  {  -62,  68,  40,  14 },  {  -54,  74,  24,  18 },  {  -58,  96,   0,  24 } } },  /* 29: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 1 M: 4(123)6+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 1 L: 4(123)6+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {    0,   0,   0,   0 },  {  -48,  58,  40,  14 },  {  -52,  74,  24,  18 },  {  -56,  88,   0,  24 } } },  /* 30: ATTACK 1 S: 4(123)6+P light (routine Att_CHOUCHUURENGEKI), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  74,   0,  50 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 7 S: 214+P light (routine Att_CHOUCHUURENGEKI), ATTACK 7 M: 214+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 7 L: 214+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {   -2,  22,  80,  18 },  {  -16,  58,  70,  18 },  {  -20,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 32: LOSE SONABA, SHIMEOTASARE */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 33: V JUMP K M A */
    { { {  -14,  22,  91,  17 },  {  -28,  56,  80,  18 },  {  -36,  64,  40,  38 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K M A, F JUMP K L A */
    { { {  -16,  24,  94,  18 },  {  -30,  60,  84,  18 },  {  -28,  56,  54,  28 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -16,  24,  94,  18 },  {  -30,  60,  84,  18 },  {  -28,  56,  54,  28 },  {  -64,  34,  54,  24 } } },  /* 36: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -16,  24,  94,  18 },  {  -30,  60,  84,  18 },  {  -28,  56,  54,  28 },  {  -56,  26,  60,  32 } } },  /* 37: ATTACK 2 L: 214+K heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 214+KK (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -26,  56,  56,  14 },  {  -26,  58,  38,  18 },  {  -28,  64,   0,  36 } } },  /* 38: ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU), ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU) +1 */
    { { {  -16,  24,  90,  18 },  {  -30,  60,  80,  18 },  {  -28,  54,  46,  32 },  {  -34,  66,  12,  32 } } },  /* 39: not used by a script */
    { { {  -30,  24,  90,  18 },  {  -52,  80,  78,  18 },  {  -46,  82,  40,  36 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 10 S: not started by a command */
    { { {  -30,  23,  82,  16 },  {  -36,  53,  66,  20 },  {  -32,  49,  36,  29 },  {  -32,  69,   0,  35 } } },  /* 41: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  23,  82,  16 },  {  -36,  53,  66,  20 },  {  -32,  43,  36,  29 },  {  -32,  55,   0,  35 } } },  /* 42: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  49,  82,  16 },  {  -36,  67,  66,  20 },  {  -32,  56,  36,  29 },  {  -32,  92,   0,  35 } } },  /* 43: L PUNCH C, follow-up of L PUNCH A */
    { { {  -30,  29,  67,  16 },  {  -36,  62,  59,  13 },  {  -32,  56,  36,  23 },  {  -32,  92,   0,  35 } } },  /* 44: L PUNCH C, follow-up of L PUNCH A */
    { { {  -52,  21,  41,  30 },  {  -47,  49,  53,  13 },  {  -33,  47,  36,  23 },  {  -35,  92,   0,  35 } } },  /* 45: L PUNCH C, follow-up of L PUNCH A */
    { { {  -35,  21,  56,  20 },  {  -32,  49,  53,  13 },  {  -33,  47,  36,  23 },  {  -35,  92,   0,  35 } } },  /* 46: L PUNCH C, follow-up of L PUNCH A */
    { { {    0,   0,   0,   0 },  {  -16,  50,  64,  18 },  {  -22,  50,  34,  30 },  {  -14,  60,   0,  36 } } },  /* 47: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {    0,   0,   0,   0 },  {  -16,  50,  64,  18 },  {  -22,  50,  34,  30 },  {   -2,  56,  16,  26 } } },  /* 48: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {    0,   0,   0,   0 },  {  -24,  54,  66,  18 },  {  -28,  72,  36,  28 },  {    2,  54,  28,  22 } } },  /* 49: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -24,  54,  66,  18 },  {  -28,  62,  36,  28 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {  -10,  24,  92,  18 },  {  -30,  56,  78,  18 },  {  -26,  52,  46,  32 },  {  -20,  50,  20,  24 } } },  /* 51: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {  -28,  48,  58,  18 },  {  -28,  54,  36,  24 },  {  -28,  60,   0,  36 } } },  /* 52: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    { { {   -6,  24,  92,  18 },  {  -24,  50,  80,  18 },  {  -22,  48,  46,  32 },  {  -20,  48,  20,  24 } } },  /* 53: ATTACK 6 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -87,  99,  30,  50 },  {  -86,  98,   0,  36 } } },  /* 54: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {    2,  22,  87,  18 },  {  -23,  55,  72,  19 },  {  -24,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 55: UPPER L */
    { { {   10,  22,  86,  18 },  {  -20,  55,  72,  19 },  {  -25,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 56: UPPER L, BODY UPPER L */
    { { {   14,  22,  85,  18 },  {  -18,  55,  72,  19 },  {  -26,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 57: UPPER L, BODY UPPER L */
    { { {   16,  22,  84,  18 },  {  -17,  55,  72,  19 },  {  -27,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 58: BODY UPPER L */
    { { {    2,  22,  81,  18 },  {  -19,  55,  71,  19 },  {  -19,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 59: FACE S, FACE M, FACE L +9 */
    { { {   14,  22,  79,  18 },  {  -13,  55,  70,  19 },  {  -16,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 60: FACE M, FACE L, FOOK OKU L +3 */
    { { {   22,  22,  77,  18 },  {   -9,  55,  69,  19 },  {  -14,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 61: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    { { {   26,  22,  75,  18 },  {   -7,  55,  68,  19 },  {  -13,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 62: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {  -18,  22,  80,  18 },  {  -25,  55,  70,  19 },  {  -21,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 63: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -22,  22,  77,  18 },  {  -23,  55,  68,  19 },  {  -19,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 64: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -26,  22,  74,  18 },  {  -21,  55,  66,  19 },  {  -17,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 65: NOUTEN L, BODY BROW M, BODY BROW L */
    { { {  -30,  22,  71,  18 },  {  -19,  55,  64,  19 },  {  -15,  51,  38,  32 },  {  -28,  60,   0,  36 } } },  /* 66: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    { { {   -8,  22,  50,  19 },  {  -21,  54,  45,  16 },  {  -24,  54,  28,  18 },  {  -35,  69,   0,  32 } } },  /* 67: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {   -2,  22,  50,  19 },  {  -19,  54,  45,  16 },  {  -23,  54,  28,  18 },  {  -35,  69,   0,  32 } } },  /* 68: KAGAMI S, KAGAMI M, KAGAMI L */
    { { {    4,  22,  50,  19 },  {  -17,  54,  45,  16 },  {  -22,  54,  28,  18 },  {  -35,  69,   0,  32 } } },  /* 69: KAGAMI M, KAGAMI L */
    { { {   10,  22,  50,  19 },  {  -15,  54,  45,  16 },  {  -21,  54,  28,  18 },  {  -35,  69,   0,  32 } } },  /* 70: KAGAMI L */
    { { {  -14,  22,  80,  18 },  {  -24,  55,  72,  19 },  {  -27,  51,  39,  31 },  {  -38,  86,   0,  37 } } },  /* 71: L PUNCH B */
    { { {  -22,  22,  71,  18 },  {  -28,  55,  59,  19 },  {  -31,  51,  35,  25 },  {  -40,  88,   0,  34 } } },  /* 72: L PUNCH B */
    { { {  -17,  22,  59,  18 },  {  -40,  55,  57,  19 },  {  -35,  51,  33,  23 },  {  -40,  88,   0,  34 } } },  /* 73: L PUNCH B */
    { { {    2,  22,  53,  18 },  {  -29,  55,  47,  19 },  {  -25,  51,  33,  23 },  {  -40,  88,   0,  34 } } },  /* 74: L PUNCH B */
    { { {   -2,  22,  62,  18 },  {  -37,  55,  59,  19 },  {  -28,  51,  35,  23 },  {  -40,  88,   0,  34 } } },  /* 75: L PUNCH B */
    { { {   -2,  22,  70,  18 },  {  -28,  55,  62,  19 },  {  -28,  51,  35,  25 },  {  -40,  88,   0,  34 } } },  /* 76: L PUNCH B */
    { { {   -6,  22,  76,  18 },  {  -26,  55,  66,  19 },  {  -28,  51,  35,  29 },  {  -40,  84,   0,  34 } } },  /* 77: L PUNCH B */
    { { {  -12,  22,  79,  18 },  {  -27,  55,  68,  19 },  {  -27,  51,  36,  32 },  {  -36,  70,   0,  36 } } },  /* 78: L PUNCH B */
    { { {  -16,  22, 103,  18 },  {  -38,  55,  91,  19 },  {  -36,  51,  66,  24 },  {  -32,  60,  44,  24 } } },  /* 79: L KICK C */
    { { {  -13,  22, 105,  18 },  {  -32,  55,  93,  19 },  {  -29,  45,  61,  31 },  {  -11,  44,  50,  32 } } },  /* 80: L KICK C */
    { { {   11,  22, 100,  18 },  {   -9,  55,  91,  19 },  {  -20,  55,  63,  27 },  {   12,  34,  54,  24 } } },  /* 81: L KICK C */
    { { {   11,  22, 100,  18 },  {   -9,  55,  91,  19 },  {  -15,  53,  61,  29 },  {    8,  40,  44,  26 } } },  /* 82: L KICK C */
    { { {   11,  22,  98,  18 },  {   -9,  55,  87,  19 },  {  -15,  51,  57,  29 },  {    2,  38,  24,  36 } } },  /* 83: L KICK C */
    { { {   14,  22,  95,  18 },  {  -11,  55,  82,  19 },  {  -15,  51,  51,  29 },  {    4,  38,   6,  44 } } },  /* 84: L KICK C */
    { { {  -12,  22,  94,  18 },  {  -21,  55,  81,  19 },  {  -21,  47,  45,  35 },  {  -23,  44,   0,  44 } } },  /* 85: L KICK B */
    { { {    8,  22,  86,  18 },  {  -10,  55,  75,  19 },  {  -26,  58,  40,  33 },  {  -12,  36,   0,  40 } } },  /* 86: L KICK B */
    { { {   29,  22,  82,  18 },  {    8,  55,  71,  19 },  {  -20,  65,  51,  26 },  {  -12,  36,   0,  50 } } },  /* 87: L KICK B */
    { { {   16,  22,  89,  18 },  {   -1,  55,  76,  19 },  {  -20,  55,  51,  32 },  {  -20,  40,   0,  50 } } },  /* 88: L KICK B */
    { { {  -10,  22,  94,  18 },  {  -23,  55,  81,  19 },  {  -44,  66,  46,  34 },  {  -18,  38,   0,  44 } } },  /* 89: L KICK B */
    { { {  -14,  22,  94,  18 },  {  -27,  59,  81,  19 },  {  -32,  57,  46,  34 },  {  -18,  38,   0,  44 } } },  /* 90: L KICK B */
    { { {  -18,  22,  94,  18 },  {  -30,  56,  82,  19 },  {  -27,  51,  44,  37 },  {  -32,  60,   0,  43 } } },  /* 91: L KICK B */
    { { {  -16,  22,  92,  18 },  {  -27,  55,  80,  19 },  {  -23,  51,  42,  36 },  {  -30,  62,   0,  40 } } },  /* 92: L KICK B */
    { { {   -6,  24,  92,  18 },  {  -18,  50,  80,  18 },  {  -22,  48,  46,  32 },  {  -10,  38,  20,  24 } } },  /* 93: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) */
    { { {   -6,  24,  92,  18 },  {  -18,  50,  80,  18 },  {  -34,  60,  46,  32 },  {  -10,  38,  20,  24 } } },  /* 94: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -6,  24,  92,  18 },  {  -22,  50,  80,  18 },  {  -24,  52,  46,  32 },  {  -16,  48,  28,  20 } } },  /* 95: ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU), ATTACK 11 SP: EX 623+PP (routine Att_SENPUUKYAKU) +1 */
    { { {   -6,  24,  92,  18 },  {  -22,  50,  80,  18 },  {  -24,  52,  46,  32 },  {  -32,  60,  28,  20 } } },  /* 96: ATTACK 11 S: 623+P light (routine Att_SENPUUKYAKU), ATTACK 11 M: 623+P medium (routine Att_SENPUUKYAKU), ATTACK 11 L: 623+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -6,  22,  82,  18 },  {  -20,  54,  68,  18 },  {  -30,  54,  38,  30 },  {  -26,  62,   0,  36 } } },  /* 97: LOSE SONABA, SHIMEOTASARE */
    { { {    4,  22,  66,  18 },  {  -18,  50,  50,  18 },  {  -32,  50,  28,  24 },  {  -42,  74,   0,  28 } } },  /* 98: LOSE SONABA, SHIMEOTASARE */
    { { {    2,  22,  58,  18 },  {  -18,  50,  44,  18 },  {  -32,  50,  24,  24 },  {  -44,  76,   0,  26 } } },  /* 99: LOSE SONABA, SHIMEOTASARE */
    { { {  -16,  22,  92,  18 },  {  -30,  58,  76,  18 },  {  -24,  52,  42,  32 },  {  -30,  62,   0,  40 } } },  /* 100: TATI DENGEKI S, TATI DENGEKI M, TATI DENGEKI L */
    { { {    0,   0,   0,   0 },  {  -26,  50,  64,  18 },  {  -18,  50,  42,  26 },  {  -30,  54,  30,  16 } } },  /* 101: AIR NORMAL, KUNOJI, HARAYARARE +1 */
    { { {    0,   0,   0,   0 },  {  -10,  50,  70,  18 },  {  -18,  50,  52,  24 },  {  -30,  54,  34,  20 } } },  /* 102: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {    0,   0,   0,   0 },  {   -8,  50,  56,  18 },  {  -14,  50,  36,  26 },  {  -26,  54,  26,  16 } } },  /* 103: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {    0,   0,   0,   0 },  {  -24,  42,  56,  18 },  {  -20,  54,  36,  26 },  {  -18,  54,  18,  16 } } },  /* 104: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {    0,   0,   0,   0 },  {   -6,  36,  62,  28 },  {  -30,  40,  52,  30 },  {  -44,  50,  28,  30 } } },  /* 105: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {    0,   0,   0,   0 },  {   -2,  36,  60,  28 },  {  -30,  40,  54,  30 },  {  -54,  46,  38,  30 } } },  /* 106: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    0,   0,   0,   0 },  {    2,  36,  54,  28 },  {  -26,  40,  54,  30 },  {  -50,  40,  42,  30 } } },  /* 107: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    0,   0,   0,   0 },  {    6,  36,  48,  28 },  {  -18,  40,  54,  30 },  {  -50,  40,  48,  30 } } },  /* 108: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    6,  36,  42,  28 },  {  -18,  40,  52,  30 },  {  -50,  40,  50,  30 } } },  /* 109: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    6,  36,  38,  28 },  {  -16,  40,  48,  30 },  {  -46,  40,  52,  30 } } },  /* 110: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    8,  36,  30,  28 },  {  -12,  40,  44,  30 },  {  -42,  40,  54,  30 } } },  /* 111: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    4,  36,  24,  28 },  {   -4,  40,  42,  30 },  {  -28,  40,  60,  30 } } },  /* 112: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {  -24,  50,  58,  18 },  {  -10,  50,  34,  28 },  {  -32,  56,  26,  16 } } },  /* 113: KUNOJI, TTKI V. AIR, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -10,  40,  70,  22 },  {  -18,  40,  46,  30 },  {  -34,  54,  24,  30 } } },  /* 114: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    6,  38,  58,  28 },  {  -18,  40,  44,  30 },  {  -38,  46,  22,  30 } } },  /* 115: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   10,  36,  44,  30 },  {  -16,  38,  36,  30 },  {  -40,  38,  20,  30 } } },  /* 116: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   10,  36,  28,  30 },  {  -16,  38,  24,  30 },  {  -40,  38,  18,  30 } } },  /* 117: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   14,  30,  14,  30 },  {  -16,  36,  18,  30 },  {  -42,  32,  16,  30 } } },  /* 118: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -24,  50,  78,  20 },  {  -18,  50,  50,  28 },  {  -30,  54,  28,  22 } } },  /* 119: UPPER, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -22,  50,  78,  20 },  {  -26,  50,  50,  28 },  {  -30,  50,  28,  24 } } },  /* 120: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -14,  40,  66,  26 },  {  -30,  50,  50,  28 },  {  -30,  50,  28,  26 } } },  /* 121: UPPER, HARAYARARE, BODY UPPER SP +1 */
    { { {    0,   0,   0,   0 },  {  -28,  50,  68,  18 },  {  -18,  48,  44,  26 },  {  -30,  54,  28,  18 } } },  /* 122: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -16,  44,  66,  22 },  {  -24,  50,  42,  26 },  {  -40,  54,  28,  24 } } },  /* 123: BODY UPPER */
    { { {    0,   0,   0,   0 },  {   -8,  36,  62,  28 },  {  -18,  40,  42,  30 },  {  -22,  50,  22,  30 } } },  /* 124: FACE */
    { { {    0,   0,   0,   0 },  {  -28,  56,  76,  18 },  {  -22,  50,  46,  32 },  {  -24,  56,  28,  18 } } },  /* 125: DENKI */
    { { {    0,   0,   0,   0 },  {   -6,  52,  64,  24 },  {  -22,  56,  46,  28 },  {  -28,  60,  24,  22 } } },  /* 126: TOUKETSU A */
    { { {    0,   0,   0,   0 },  {  -18,  50,  72,  18 },  {  -18,  50,  48,  24 },  {  -12,  50,  28,  20 } } },  /* 127: HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -26,  34,  56,  24 },  {   -6,  44,  42,  28 },  {    2,  50,  24,  20 } } },  /* 128: HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -24,  50,  58,  18 },  {  -10,  50,  34,  28 },  {  -32,  56,  26,  16 } } },  /* 129: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -26,  52,  70,  18 },  {  -26,  52,  48,  22 },  {  -26,  52,  30,  18 } } },  /* 130: BODY SLAM, IPPONZEOI, TOMOE RYU +10 */
    { { {  -28,  22,  82,  18 },  {  -31,  51,  70,  19 },  {  -28,  45,  38,  32 },  {  -32,  62,   0,  36 } } },  /* 131: L KICK A */
    { { {  -24,  24,  84,  18 },  {  -32,  52,  72,  18 },  {  -34,  49,  44,  32 },  {  -34,  40,   0,  42 } } },  /* 132: L KICK A */
    { { {  -20,  24,  90,  18 },  {  -28,  48,  76,  18 },  {  -36,  49,  44,  32 },  {  -34,  40,   0,  42 } } },  /* 133: L KICK A */
    { { {  -18,  24,  84,  18 },  {  -28,  54,  72,  18 },  {  -34,  54,  38,  32 },  {  -34,  51,   0,  36 } } },  /* 134: L KICK A */
    { { {  -14,  22,  90,  18 },  {  -27,  55,  78,  19 },  {  -23,  51,  40,  36 },  {  -28,  60,   0,  38 } } },  /* 135: KAMAE */
    { { {  -11,  22,  83,  18 },  {  -29,  55,  72,  19 },  {  -29,  51,  38,  32 },  {  -32,  60,   0,  36 } } },  /* 136: HURIMUKI */
    { { {  -16,  22,  83,  18 },  {  -27,  55,  72,  19 },  {  -23,  55,  38,  32 },  {  -24,  70,   0,  36 } } },  /* 137: FRONT WALK */
    { { {  -16,  22,  90,  18 },  {  -27,  55,  78,  19 },  {  -23,  55,  42,  34 },  {  -24,  58,   0,  40 } } },  /* 138: FRONT WALK */
    { { {  -16,  22,  86,  18 },  {  -27,  55,  74,  19 },  {  -23,  55,  42,  30 },  {  -36,  76,   0,  40 } } },  /* 139: FRONT WALK */
    { { {  -15,  22,  83,  18 },  {  -29,  55,  72,  19 },  {  -27,  55,  38,  32 },  {  -40,  70,   0,  36 } } },  /* 140: BACK WALK */
    { { {  -16,  22,  87,  18 },  {  -29,  56,  76,  19 },  {  -27,  54,  40,  34 },  {  -36,  66,   0,  38 } } },  /* 141: BACK WALK */
    { { {  -16,  22,  91,  18 },  {  -28,  55,  77,  19 },  {  -28,  55,  42,  33 },  {  -26,  55,   0,  40 } } },  /* 142: BACK WALK */
    { { {  -15,  22,  86,  18 },  {  -27,  55,  72,  19 },  {  -23,  51,  36,  34 },  {  -34,  76,   0,  34 } } },  /* 143: BACK WALK */
    { { {  -17,  22,  45,  19 },  {  -23,  54,  43,  16 },  {  -25,  54,  24,  18 },  {  -35,  69,   0,  36 } } },  /* 144: KAGAMU */
    { { {  -10,  22,  50,  19 },  {  -27,  54,  45,  16 },  {  -27,  54,  28,  18 },  {  -30,  68,   0,  32 } } },  /* 145: KAGAMI TURN */
    { { {  -21,  22,  93,  17 },  {  -25,  50,  80,  18 },  {  -27,  52,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 146: JUMP FRONT, SP JUMP FRONT, JUMP BACK +2 */
    { { {  -42,  22,  77,  17 },  {  -25,  50,  80,  18 },  {  -27,  52,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 147: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -12,  22,  91,  17 },  {  -25,  50,  82,  18 },  {  -27,  52,  52,  28 },  {  -26,  42,  36,  15 } } },  /* 148: JUMP FRONT, SP JUMP FRONT, JUMP BACK +1 */
    { { {  -20,  22,  87,  17 },  {  -25,  50,  80,  18 },  {  -27,  52,  57,  21 },  {  -36,  61,  40,  15 } } },  /* 149: JUMP VERTICAL, SP JUMP V */
    { { {  -20,  24,  80,  18 },  {  -34,  58,  70,  18 },  {  -30,  54,  38,  30 },  {  -42,  76,   0,  36 } } },  /* 150: DASH HUMIKOMI */
    { { {  -18,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  34,  30 },  {  -36,  76,   0,  32 } } },  /* 151: DASH HUMIKOMI */
    { { {  -24,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  36,  28 },  {  -38,  76,   0,  34 } } },  /* 152: DASH HUMIKOMI */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 153: DASH TOBINOKI */
    { { {    0,  24,  76,  18 },  {  -24,  60,  66,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 154: DASH TOBINOKI */
    { { {   -9,  24,  81,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 155: DASH TOBINOKI */
    { { {   -6,  22,  80,  18 },  {  -24,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -26,  66,   0,  36 } } },  /* 156: DASH TOBINOKI */
    { { {  -29,  24,  78,  18 },  {  -45,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 157: PIYO */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 158: PIYO */
    { { {  -11,  24,  79,  18 },  {  -28,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 159: PIYO */
    { { {    4,  24,  83,  18 },  {  -16,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -28,  62,   0,  36 } } },  /* 160: PIYO */
    { { {  -10,  22,  83,  18 },  {  -32,  60,  78,  18 },  {  -24,  50,  38,  38 },  {  -32,  66,   0,  36 } } },  /* 161: PIYO */
    { { {  -14,  22,  50,  19 },  {  -24,  55,  45,  16 },  {  -28,  57,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 162: KAGAMI KAMAE */
    { { {  -14,  22,  48,  19 },  {  -22,  53,  45,  16 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 163: KAGAMI KAMAE */
};

const HAND_BOX sean_hand_box[49] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  22,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: not used by a script */
    { { {  -76,  44,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {  -70,  40,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH B */
    { { {  -56,  22,  44,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -50,  30,  80,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A */
    { { {  -64,  38,  20,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S KICK A */
    { { {  -62,  32,  44,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L KICK A */
    { { {  -62,  48,  24,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK A */
    { { {  -58,  32,  44,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: follow-up of M PUNCH A */
    { { {  -60,  28,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -30,  28,  80,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A */
    { { {  -74,  34,   0,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A */
    { { {  -62,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI K A */
    { { {  -72,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI K A */
    { { {  -54,  28,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: V JUMP P S A, F JUMP P S A */
    { { {  -54,  28,  56,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P S A, F JUMP P S A */
    { { {  -58,  26,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P M A, F JUMP P M A */
    { { {  -58,  26,  52,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    { { {  -64,  30,  52,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {  -32,  32,  82,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {  -60,  30,  62,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {  -62,  32,  48,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP) */
    { { {  -60,  34,  22,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -64,  30,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: F JUMP P L A */
    { { {  -58,  28,  76,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: not used by a script */
    { { {  -70,  40,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P L A */
    { { {  -60,  24,  50,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP K M A */
    { { {  -60,  30,  62,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP K L A */
    { { {  -60,  30,  74,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { {  -52,  28,  60,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M A */
    { { {  -66,  38,  54,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP K M A */
    { { {  -68,  38,  44,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP K M A, F JUMP K L A */
    { { {  -72,  42,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: F JUMP K L A */
    { { {  -70,  40,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K L A */
    { { {  -20,  40,  34,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 2 S: 214+K light (routine Att_SHOURYUUKEN), ATTACK 2 M: 214+K medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -80,  32,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 10 S: not started by a command */
    { { {  -36,  17,  56,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: L PUNCH C, follow-up of L PUNCH A */
    { { {  -55,  17,  36,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L PUNCH C, follow-up of L PUNCH A */
    { { {  -60,  25,  29,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L PUNCH C, follow-up of L PUNCH A */
    { { {  -46,  25,  36,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L PUNCH C, follow-up of L PUNCH A */
    { { {  -56,  26,  40,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: L PUNCH B */
    { { {  -70,  48,  70,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: L KICK C */
    { { {  -64,  48,  64,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: L KICK C */
    { { {  -62,  46,  54,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: L KICK C */
    { { {  -60,  44,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: L KICK C */
    { { {  -40,  30,  68,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: L KICK B */
    { { {  -40,  30,  68,  24 },  {  -56,  24,  76,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: L KICK B */
    { { {  -50,  30,  68,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: L KICK B */
};

const HOSEI_BOX sean_hos_box[7] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +91 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +56 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +68 */
    { {  -25,   50,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +1 */
    { {  -25,   50,    0,   72 } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +52 */
    { {  -25,   50,   34,   40 } },  /* 6: ATTACK 3 S: 236+K light/medium/heavy (routine Att_ABISEGERI), ATTACK 3 SP: EX 236+KK (routine Att_HOMING_JUMP), ATTACK 5 S: SA III 23623+P (routine Att_SLIDE_and_JUMP) */
};
