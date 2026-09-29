/*
 * KEN_HITBOX.C  Ken's hit boxes
 *
 * Each of Ken's animation frames names an entry of ken_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX ken_hit_ix_table[260] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +20 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +83 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +21 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +4 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +22 */
    {    5,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 5: JUMP JUNBI, SP JUMP JUNBI */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 6: DASH TOBINOKI, follow-up of APPEAR JUNBI 1, follow-up of APPEAR 8 +6 */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: not used by a script */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: SP WIN 1 */
    {    8,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: PARING HEAD */
    {    9,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 10: PARING HEAD */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 11: NEKOROBI S, no name, HANEAGARI +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 12: OKIAGARI, OKIAGARI F, OKIAGARI B +12 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 13: not used by a script */
    {   10,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 14: not used by a script */
    {   11,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 15: not used by a script */
    {   12,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 16: not used by a script */
    {   13,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 17: no name */
    {   14,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 18: no name */
    {    1,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 19: S PUNCH A */
    {    1,    0,    1, 0x0000,    0,    1,    2,    1 },  /* 20: S PUNCH A */
    {    1,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 21: S PUNCH A */
    {    1,    0,    2, 0x0000,    0,    1,    3,    1 },  /* 22: S PUNCH B */
    {    1,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 23: S PUNCH B */
    {    1,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 24: M PUNCH A */
    {    1,    0,    3, 0x0000,    0,    1,    5,    1 },  /* 25: M PUNCH B */
    {    1,    0,    3, 0x0000,    0,    1,    6,    1 },  /* 26: M PUNCH B */
    {    1,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 27: M PUNCH B */
    {    1,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 28: ATTACK 10 M: not started by a command */
    {    1,    0,    4, 0x0000,    0,    1,    7,    1 },  /* 29: ATTACK 10 M: not started by a command */
    {   40,    0,   34, 0x0000,    0,    3,    8,    3 },  /* 30: ATTACK 9 M: not started by a command */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH A, follow-up of M PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 32: L PUNCH A, follow-up of M PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,   10,    1 },  /* 33: L PUNCH A, follow-up of M PUNCH A */
    {   16,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH A, follow-up of M PUNCH A */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 35: L PUNCH B */
    {   17,    0,    0, 0x0000,    0,    1,   11,    1 },  /* 36: L PUNCH B */
    {   18,    0,    6, 0x0000,    0,    5,   12,    1 },  /* 37: S KICK A */
    {   18,    0,    6, 0x0000,    0,    5,    0,    1 },  /* 38: S KICK A */
    {   19,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 39: M KICK A, follow-up of M KICK A */
    {   19,    0,    7, 0x0000,    0,    1,   13,    1 },  /* 40: M KICK A */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 41: M KICK A */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: M KICK C, follow-up of M KICK A */
    {   20,    0,    8, 0x0000,    0,    1,   14,    1 },  /* 43: M KICK C */
    {   20,    0,    9, 0x0000,    0,    1,   15,    1 },  /* 44: M KICK C */
    {   20,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 45: M KICK C */
    {    1,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 46: no name, L KICK A */
    {   22,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 47: no name, L KICK A */
    {   22,    0,   20, 0x0000,    0,    1,   16,    1 },  /* 48: no name, L KICK A */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 49: L KICK A */
    {    1,    0,    0, 0x0000,    0,    1,   30,    1 },  /* 50: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1 */
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
    {   27,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 74: ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script), ATTACK 1 L: 236+P heavy (plain script) +1 */
    {   27,    0,   19, 0x0000,    0,    1,    0,    5 },  /* 75: ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script), ATTACK 1 L: 236+P heavy (plain script) +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 76: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 77: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 78: not used by a script */
    {   30,    0,    0, 0x0000,    0,    0,   31,    1 },  /* 79: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,   31,    1 },  /* 80: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {   30,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 81: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command */
    {   30,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 82: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   31,    0,    0, 0x0000,    0,    3,   33,    3 },  /* 83: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2 */
    {   31,    0,   21, 0x0000,    0,    3,   34,    3 },  /* 84: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) +1 */
    {   32,    0,   21, 0x0000,    0,    3,   35,    3 },  /* 85: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2 */
    {   32,    0,   21, 0x0000,    0,    3,    0,    3 },  /* 86: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +4 */
    {   32,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 87: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 88: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 89: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 90: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   36,    2 },  /* 91: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   37,    1 },  /* 92: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   38,    3 },  /* 93: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   39,    3 },  /* 94: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   33,    3 },  /* 95: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 96: follow-up of AIR NORMAL */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 97: TUKAMIKAKARI A */
    {   26,    0,   22, 0x0000,    0,    3,   40,    3 },  /* 98: F JUMP P L A */
    {   26,    0,   22, 0x0000,    0,    3,   41,    3 },  /* 99: F JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   42,    3 },  /* 100: not used by a script */
    {    4,    0,    0, 0x0000,    0,    3,   43,    3 },  /* 101: not used by a script */
    {    4,    0,   23, 0x0000,    0,    3,   43,    3 },  /* 102: not used by a script */
    {    4,    0,   23, 0x0000,    0,    3,    0,    3 },  /* 103: not used by a script */
    {    4,    0,    0, 0x0000,    0,    3,   44,    3 },  /* 104: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   45,    3 },  /* 105: V JUMP P L A */
    {    4,    0,   24, 0x0000,    0,    3,    0,    3 },  /* 106: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   46,    3 },  /* 107: V JUMP K S A, F JUMP K S A */
    {    4,    0,    0, 0x0000,    0,    3,   47,    3 },  /* 108: V JUMP K S A, F JUMP K S A */
    {   33,    0,    0, 0x0000,    0,    3,   48,    3 },  /* 109: V JUMP K M A */
    {   33,    0,   25, 0x0000,    0,    3,   49,    3 },  /* 110: V JUMP K M A */
    {   33,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP K M A */
    {    4,    0,   26, 0x0000,    0,    3,   50,    3 },  /* 112: V JUMP K L A */
    {    4,    0,   26, 0x0000,    0,    3,   51,    3 },  /* 113: V JUMP K L A */
    {    4,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   34,    0,   28, 0x0000,    0,    3,   52,    3 },  /* 115: F JUMP K M A */
    {   34,    0,   29, 0x0000,    0,    3,   53,    3 },  /* 116: F JUMP K M A */
    {   34,    0,   30, 0x0000,    0,    3,    0,    3 },  /* 117: F JUMP K M A, F JUMP K L A */
    {   34,    0,   31, 0x0000,    0,    3,   54,    3 },  /* 118: F JUMP K L A */
    {   34,    0,   32, 0x0000,    0,    3,   55,    3 },  /* 119: F JUMP K L A */
    {   35,    0,   33, 0x0000,    0,    3,    0,    3 },  /* 120: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    {   36,    0,   33, 0x0000,    0,    3,   56,    3 },  /* 121: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +5 */
    {   36,    0,   33, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    {   37,    0,   33, 0x0000,    0,    3,   57,    3 },  /* 123: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +5 */
    {   37,    0,   33, 0x0000,    0,    3,    0,    3 },  /* 124: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 125: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +2 */
    {   39,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 126: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 127: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   58,    2 },  /* 128: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   59,    1 },  /* 129: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   60,    3 },  /* 130: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   15,    0,    0, 0x0000,    0,    0,   60,    0 },  /* 131: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   15,    0,    0, 0x0000,    0,    0,   61,    0 },  /* 132: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {   15,    0,    0, 0x0000,    0,    0,   62,    0 },  /* 133: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 134: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   36,    1 },  /* 135: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   37,    1 },  /* 136: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   38,    3 },  /* 137: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 138: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,   36,    1 },  /* 139: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,   37,    1 },  /* 140: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   31,    0,    0, 0x0000,    0,    3,   38,    3 },  /* 141: ATTACK 4 S: SA I 23623+P (routine Att_SHOURYUUREPPA) */
    {   31,    0,   21, 0x0000,    0,    3,   39,    3 },  /* 142: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 143: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 144: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   63,    1 },  /* 145: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   64,    1 },  /* 146: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   65,    1 },  /* 147: ATTACK 6 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {   36,    0,   33, 0x0000,    0,    3,   66,    3 },  /* 148: ATTACK 8 S: not started by a command */
    {   36,    0,   33, 0x0000,    0,    3,   67,    3 },  /* 149: ATTACK 8 S: not started by a command */
    {   41,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 150: KAMAE */
    {   42,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 151: KAMAE */
    {   43,    0,    0, 0x1A16,    0,    1,    0,    1 },  /* 152: FRONT WALK */
    {   44,    0,    0, 0x1914,    0,    1,    0,    1 },  /* 153: FRONT WALK */
    {   45,    0,    0, 0x1A19,    0,    1,    0,    1 },  /* 154: BACK WALK */
    {   46,    0,    0, 0x1519,    0,    1,    0,    1 },  /* 155: BACK WALK */
    {    1,    0,    0, 0x1212,    0,    2,    0,    2 },  /* 156: KAGAMU */
    {    2,    0,    0, 0x1212,    0,    1,    0,    5 },  /* 157: STAND UP */
    {   47,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 158: KAGAMI KAMAE */
    {   48,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 159: KAGAMI KAMAE */
    {   49,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 160: UPPER L */
    {   50,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 161: UPPER L */
    {   51,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 162: UPPER L, BODY UPPER L */
    {   52,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 163: BODY UPPER L */
    {   53,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 164: FACE S, FACE M, FACE L +10 */
    {   54,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 165: FACE M, FACE L, FOOK OKU L +5 */
    {   55,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 166: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    {   56,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 167: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {   57,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 168: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {   58,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 169: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {   59,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 170: NOUTEN L, BODY BROW M, BODY BROW L */
    {   60,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 171: BODY BROW L, BODY UPPER L, TATAKI S */
    {   61,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 172: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {   62,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 173: KAGAMI S, KAGAMI M, KAGAMI L */
    {   63,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 174: KAGAMI M, KAGAMI L */
    {   64,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 175: KAGAMI L */
    {   65,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 176: M KICK B, L KICK C, no name */
    {   66,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 177: M KICK B, L KICK C, no name */
    {   67,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 178: M KICK B, L KICK C, no name */
    {   68,    0,   35, 0x0000,    0,    1,   68,    5 },  /* 179: M KICK B, no name */
    {   68,    0,   35, 0x0000,    0,    1,   69,    5 },  /* 180: M KICK B, no name */
    {   68,    0,   36, 0x0000,    0,    1,    0,    5 },  /* 181: M KICK B, no name */
    {   67,    0,   37, 0x0000,    0,    1,    0,    5 },  /* 182: M KICK B, no name */
    {   69,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 183: M KICK B, no name */
    {   70,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 184: L KICK C, no name */
    {   70,    0,   39, 0x0000,    0,    1,   70,    1 },  /* 185: L KICK C, no name */
    {   71,    0,   40, 0x0000,    0,    1,   71,    1 },  /* 186: L KICK C, no name */
    {   71,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 187: L KICK C, no name */
    {   72,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 188: L KICK C, no name */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 189: ATTACK 9 M: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 190: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 191: not used by a script */
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
    {   96,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 202: LOSE SONABA, SHIMEOTASARE */
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
    {  131,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 237: HURIMUKI */
    {  132,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 238: KAGAMI TURN */
    {  133,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 239: JUMP FRONT, SP JUMP FRONT */
    {  134,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 240: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  135,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 241: JUMP FRONT, SP JUMP FRONT */
    {  135,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 242: JUMP BACK, SP JUMP BACK */
    {  133,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 243: JUMP BACK, SP JUMP BACK, no name */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 244: JUMP VERTICAL, SP JUMP V */
    {  136,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 245: JUMP VERTICAL, SP JUMP V */
    {  137,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 246: PIYO */
    {  138,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 247: PIYO */
    {  139,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 248: PIYO */
    {  140,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 249: PIYO */
    {  141,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 250: PIYO */
    {  142,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 251: KAGAMU */
    {    5,    0,    0, 0x1010,    0,    1,    0,    5 },  /* 252: DASH HUMIKOMI */
    {  143,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 253: DASH HUMIKOMI */
    {  144,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 254: DASH HUMIKOMI */
    {  145,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 255: DASH HUMIKOMI */
    {  146,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 256: DASH TOBINOKI */
    {  147,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 257: DASH TOBINOKI */
    {  148,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 258: DASH TOBINOKI */
    {  149,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 259: DASH TOBINOKI */
};

const BODY_BOX ken_body_box[150] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -14,  22,  82,  18 },  {  -29,  59,  72,  18 },  {  -24,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +84 */
    { { {  -14,  22,  50,  18 },  {  -24,  55,  45,  16 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +22 */
    { { {    0,   0,   0,   0 },  {  -29,  58,  44,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +4 */
    { { {  -14,  22,  92,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +22 */
    { { {  -20,  24,  64,  18 },  {  -30,  58,  56,  18 },  {  -26,  56,  36,  20 },  {  -36,  70,   0,  36 } } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +10 */
    { { {  -22,  24,  74,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  38,  26 },  {  -38,  76,   0,  36 } } },  /* 6: not used by a script */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 7: SP WIN 1 */
    { { {  -14,  24,  74,  18 },  {  -30,  60,  66,  16 },  {  -22,  54,  38,  26 },  {  -30,  66,   0,  36 } } },  /* 8: PARING HEAD */
    { { {  -14,  24,  62,  18 },  {  -34,  64,  52,  18 },  {  -24,  58,  36,  20 },  {  -38,  82,   0,  36 } } },  /* 9: PARING HEAD */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 10: not used by a script */
    { { {  -14,  24,  82,  18 },  {  -32,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 11: not used by a script */
    { { {    4,  24,  82,  18 },  {  -18,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -32,  66,   0,  36 } } },  /* 12: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 13: no name */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 14: no name */
    { { {    0,   0,   0,   0 },  {  -16,  32,  68,  20 },  {  -20,  40,  46,  20 },  {    0,   0,   0,   0 } } },  /* 15: ATTACK 5 S: SA II 23623+K (routine Att_SHOURYUUREPPA) */
    { { {  -26,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 16: L PUNCH A, follow-up of M PUNCH A */
    { { {   -8,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -30,  60,  38,  32 },  {  -42,  76,   0,  36 } } },  /* 17: L PUNCH B */
    { { {  -16,  24,  82,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -58,  92,   0,  36 } } },  /* 18: S KICK A */
    { { {   -2,  24,  82,  18 },  {  -24,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -18,  42,   0,  36 } } },  /* 19: M KICK A, follow-up of M KICK A */
    { { {   -8,  24,  82,  18 },  {  -26,  60,  72,  18 },  {  -30,  54,  38,  32 },  {  -32,  48,   0,  36 } } },  /* 20: M KICK C, follow-up of M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: no box */
    { { {   -4,  24,  82,  18 },  {  -22,  60,  72,  18 },  {  -24,  56,  38,  32 },  {  -20,  42,   0,  36 } } },  /* 22: no name, L KICK A */
    { { {  -14,  24,  64,  18 },  {  -30,  60,  60,  14 },  {  -28,  60,  34,  24 },  {  -38,  72,   0,  32 } } },  /* 23: KAGAMI P A */
    { { {   -6,  24,  76,  18 },  {  -28,  60,  68,  14 },  {  -28,  60,  34,  32 },  {  -38,  72,   0,  32 } } },  /* 24: KAGAMI P A */
    { { {  -36,  24,  90,  18 },  {  -50,  76,  80,  18 },  {  -24,  62,  44,  34 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP P S A, F JUMP P S A */
    { { {  -30,  24,  92,  18 },  {  -36,  62,  80,  18 },  {  -32,  68,  42,  36 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P M A, F JUMP P M A, F JUMP P L A +1 */
    { { {  -24,  24,  70,  18 },  {  -32,  62,  60,  18 },  {  -24,  54,  38,  20 },  {  -42,  92,   0,  36 } } },  /* 27: ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script), ATTACK 1 L: 236+P heavy (plain script) +1 */
    { { {   16,  24,  78,  18 },  {  -24,  70,  70,  18 },  {  -26,  60,  38,  30 },  {  -36,  62,   0,  36 } } },  /* 28: not used by a script */
    { { {    0,   0,   0,   0 },  {  -24,  78,  54,  28 },  {  -36,  68,  42,  18 },  {  -26,  44,   0,  40 } } },  /* 29: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  48,  28,  20 },  {  -24,  56,   0,  26 } } },  /* 30: ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 11 S: not started by a command, ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) +2 */
    { { {   -6,  24,  92,  18 },  {  -24,  50,  80,  18 },  {  -22,  48,  46,  32 },  {  -20,  48,  20,  24 } } },  /* 31: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +3 */
    { { {  -10,  24,  92,  18 },  {  -30,  56,  78,  18 },  {  -26,  52,  46,  32 },  {  -20,  50,  20,  24 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +4 */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 33: V JUMP K M A */
    { { {  -14,  22,  91,  17 },  {  -28,  56,  80,  18 },  {  -36,  64,  40,  38 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K M A, F JUMP K L A */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -50,  20,  58,  24 } } },  /* 36: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {   30,  20,  58,  24 } } },  /* 37: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -30,  60,  28,  28 } } },  /* 38: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -16,  24,  90,  18 },  {  -30,  60,  80,  18 },  {  -28,  54,  46,  32 },  {  -34,  66,  12,  32 } } },  /* 39: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -30,  24,  90,  18 },  {  -52,  80,  78,  18 },  {  -46,  82,  40,  36 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 9 M: not started by a command */
    { { {  -14,  22,  80,  18 },  {  -29,  59,  70,  18 },  {  -24,  53,  37,  32 },  {  -29,  61,   0,  36 } } },  /* 41: KAMAE */
    { { {  -14,  22,  88,  18 },  {  -29,  59,  79,  18 },  {  -24,  53,  42,  36 },  {  -29,  61,   0,  42 } } },  /* 42: KAMAE */
    { { {  -16,  22,  82,  18 },  {  -29,  59,  72,  18 },  {  -24,  53,  38,  32 },  {  -34,  76,   0,  36 } } },  /* 43: FRONT WALK */
    { { {  -16,  22,  88,  18 },  {  -29,  59,  78,  18 },  {  -24,  53,  40,  36 },  {  -26,  56,   0,  38 } } },  /* 44: FRONT WALK */
    { { {  -16,  22,  82,  18 },  {  -29,  59,  72,  18 },  {  -24,  53,  38,  32 },  {  -42,  76,   0,  36 } } },  /* 45: BACK WALK */
    { { {  -16,  22,  88,  18 },  {  -29,  59,  78,  18 },  {  -24,  53,  40,  36 },  {  -26,  56,   0,  38 } } },  /* 46: BACK WALK */
    { { {  -14,  22,  50,  18 },  {  -24,  55,  45,  14 },  {  -28,  57,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 47: KAGAMI KAMAE */
    { { {  -14,  22,  48,  18 },  {  -22,  53,  45,  14 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 48: KAGAMI KAMAE */
    { { {    2,  22,  86,  18 },  {  -25,  59,  72,  18 },  {  -25,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 49: UPPER L */
    { { {   10,  22,  85,  18 },  {  -22,  59,  72,  18 },  {  -26,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 50: UPPER L */
    { { {   14,  22,  84,  18 },  {  -20,  59,  72,  18 },  {  -27,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 51: UPPER L, BODY UPPER L */
    { { {   16,  22,  83,  18 },  {  -19,  59,  72,  18 },  {  -28,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 52: BODY UPPER L */
    { { {    2,  22,  80,  18 },  {  -21,  59,  71,  18 },  {  -20,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 53: FACE S, FACE M, FACE L +10 */
    { { {   14,  22,  78,  18 },  {  -15,  59,  70,  18 },  {  -17,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 54: FACE M, FACE L, FOOK OKU L +5 */
    { { {   22,  22,  76,  18 },  {  -11,  59,  69,  18 },  {  -15,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 55: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    { { {   26,  22,  74,  18 },  {   -9,  59,  68,  18 },  {  -14,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 56: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {  -18,  22,  79,  18 },  {  -27,  59,  70,  18 },  {  -22,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 57: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -22,  22,  76,  18 },  {  -25,  59,  68,  18 },  {  -20,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 58: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -26,  22,  73,  18 },  {  -23,  59,  66,  18 },  {  -18,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 59: NOUTEN L, BODY BROW M, BODY BROW L */
    { { {  -30,  22,  70,  18 },  {  -21,  59,  64,  18 },  {  -16,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 60: BODY BROW L, BODY UPPER L, TATAKI S */
    { { {   -8,  22,  50,  18 },  {  -22,  55,  45,  16 },  {  -25,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 61: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {   -2,  22,  50,  18 },  {  -20,  55,  45,  16 },  {  -24,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 62: KAGAMI S, KAGAMI M, KAGAMI L */
    { { {    4,  22,  50,  18 },  {  -18,  55,  45,  16 },  {  -23,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 63: KAGAMI M, KAGAMI L */
    { { {   10,  22,  50,  18 },  {  -16,  55,  45,  16 },  {  -22,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 64: KAGAMI L */
    { { {  -34,  22,  78,  18 },  {  -36,  58,  68,  18 },  {  -30,  50,  38,  32 },  {  -36,  64,   0,  36 } } },  /* 65: M KICK B, L KICK C, no name */
    { { {  -26,  22,  76,  18 },  {  -29,  59,  68,  18 },  {  -22,  51,  38,  32 },  {  -29,  57,   0,  36 } } },  /* 66: M KICK B, L KICK C, no name */
    { { {   12,  22,  86,  18 },  {   -4,  59,  72,  18 },  {  -28,  60,  44,  34 },  {   -8,  38,   0,  44 } } },  /* 67: M KICK B, L KICK C, no name */
    { { {   14,  22,  84,  18 },  {   -2,  59,  70,  18 },  {  -32,  72,  44,  26 },  {   -2,  38,   0,  44 } } },  /* 68: M KICK B, no name */
    { { {    4,  22,  86,  18 },  {  -18,  60,  72,  18 },  {  -22,  53,  38,  32 },  {  -33,  65,   0,  36 } } },  /* 69: M KICK B, no name */
    { { {   12,  22,  86,  18 },  {  -14,  66,  72,  18 },  {  -18,  54,  50,  26 },  {  -10,  40,   0,  50 } } },  /* 70: L KICK C, no name */
    { { {    4,  22,  86,  18 },  {  -10,  56,  72,  18 },  {  -28,  58,  42,  30 },  {  -10,  40,   0,  40 } } },  /* 71: L KICK C, no name */
    { { {   -2,  22,  84,  18 },  {  -19,  59,  72,  18 },  {  -22,  53,  38,  32 },  {  -29,  61,   0,  36 } } },  /* 72: L KICK C, no name */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {   -2,  22,  80,  18 },  {  -16,  58,  70,  18 },  {  -20,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 96: LOSE SONABA, SHIMEOTASARE */
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
    { { {  -11,  22,  82,  18 },  {  -31,  59,  72,  18 },  {  -28,  53,  38,  32 },  {  -34,  61,   0,  36 } } },  /* 131: HURIMUKI */
    { { {  -10,  22,  50,  18 },  {  -24,  55,  45,  16 },  {  -26,  55,  28,  18 },  {  -32,  70,   0,  32 } } },  /* 132: KAGAMI TURN */
    { { {  -21,  22,  94,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 133: JUMP FRONT, SP JUMP FRONT, JUMP BACK +2 */
    { { {  -42,  22,  78,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 134: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -12,  22,  92,  17 },  {  -25,  50,  82,  18 },  {  -28,  53,  52,  28 },  {  -26,  42,  36,  15 } } },  /* 135: JUMP FRONT, SP JUMP FRONT, JUMP BACK +1 */
    { { {  -20,  22,  88,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  57,  21 },  {  -36,  61,  40,  15 } } },  /* 136: JUMP VERTICAL, SP JUMP V */
    { { {  -29,  24,  78,  18 },  {  -45,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 137: PIYO */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 138: PIYO */
    { { {  -11,  24,  79,  18 },  {  -28,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 139: PIYO */
    { { {    4,  24,  83,  18 },  {  -16,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -28,  62,   0,  36 } } },  /* 140: PIYO */
    { { {  -10,  22,  83,  18 },  {  -32,  60,  78,  18 },  {  -24,  50,  38,  38 },  {  -32,  66,   0,  36 } } },  /* 141: PIYO */
    { { {  -14,  22,  46,  18 },  {  -24,  55,  43,  16 },  {  -26,  55,  24,  18 },  {  -32,  70,   0,  36 } } },  /* 142: KAGAMU */
    { { {  -20,  24,  80,  18 },  {  -34,  58,  70,  18 },  {  -30,  54,  38,  30 },  {  -42,  76,   0,  36 } } },  /* 143: DASH HUMIKOMI */
    { { {  -18,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  34,  30 },  {  -36,  76,   0,  32 } } },  /* 144: DASH HUMIKOMI */
    { { {  -24,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  36,  28 },  {  -38,  76,   0,  34 } } },  /* 145: DASH HUMIKOMI */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 146: DASH TOBINOKI */
    { { {    0,  24,  76,  18 },  {  -24,  60,  66,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 147: DASH TOBINOKI */
    { { {   -9,  24,  81,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 148: DASH TOBINOKI */
    { { {   -6,  22,  80,  18 },  {  -24,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -26,  66,   0,  36 } } },  /* 149: DASH TOBINOKI */
};

const HAND_BOX ken_hand_box[42] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  22,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -76,  44,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH B */
    { { {  -70,  40,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH B */
    { { {  -54,  36,  80,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: ATTACK 10 M: not started by a command */
    { { {  -50,  30,  80,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A, follow-up of M PUNCH A */
    { { {  -64,  38,  20,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S KICK A */
    { { {  -58,  32,  44,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M KICK A, follow-up of M KICK A */
    { { {  -64,  34,  64,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK C */
    { { {  -64,  34,  36,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M KICK C */
    { { {  -60,  28,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -30,  28,  80,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A */
    { { {  -74,  34,   0,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A */
    { { {  -62,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI K A */
    { { {  -72,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI K A */
    { { {  -54,  28,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: V JUMP P S A, F JUMP P S A */
    { { {  -54,  28,  56,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P S A, F JUMP P S A */
    { { {  -58,  26,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P M A, F JUMP P M A */
    { { {  -58,  26,  52,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A, F JUMP P M A, F JUMP P L A */
    { { {  -66,  32,  50,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script), ATTACK 1 L: 236+P heavy (plain script) +1 */
    { { {  -60,  34,  38,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: no name, L KICK A */
    { { {  -28,  18,  98,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) +4 */
    { { {  -64,  26,  72,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: F JUMP P L A */
    { { {  -58,  28,  76,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -70,  40,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: V JUMP P L A */
    { { {  -60,  24,  50,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP K M A */
    { { {  -52,  24,  66,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP K L A */
    { { {  -60,  30,  62,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: not used by a script */
    { { {  -52,  28,  60,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: F JUMP K M A */
    { { {  -66,  38,  54,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: F JUMP K M A */
    { { {  -68,  38,  44,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M A, F JUMP K L A */
    { { {  -72,  42,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP K L A */
    { { {  -70,  40,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP K L A */
    { { {  -20,  40,  38,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -80,  32,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 9 M: not started by a command */
    { { {  -56,  34,  46,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: M KICK B, no name */
    { { {  -68,  40,  34,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: M KICK B, no name */
    { { {  -58,  40,  20,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: M KICK B, no name */
    { { {  -14,  28,  90,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L KICK C, no name */
    { { {  -44,  30,  56,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L KICK C, no name */
    { { {  -52,  28,  36,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK C, no name */
    { { {  -48,  36,  26,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: L KICK C, no name */
};

const HOSEI_BOX ken_hos_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +96 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +40 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +70 */
    { {  -25,   50,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +1 */
    { {  -25,   50,    0,   72 } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +39 */
};
