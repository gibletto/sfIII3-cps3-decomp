/*
 * RYU_HITBOX.C  Ryu's hit boxes
 *
 * Each of Ryu's animation frames names an entry of ryu_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX ryu_hit_ix_table[283] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +14 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +84 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +20 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +21 */
    {    5,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 5: JUMP JUNBI, SP JUMP JUNBI */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 6: DASH TOBINOKI, follow-up of APPEAR JUNBI 1, follow-up of SP WIN 1 +5 */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: not used by a script */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: not used by a script */
    {    8,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: PARING HEAD, ATTACK 11 S: not started by a command */
    {    9,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 10: PARING HEAD, ATTACK 11 S: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 11: NEKOROBI S, no name, HANEAGARI +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 12: OKIAGARI, OKIAGARI F, OKIAGARI B +13 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 13: not used by a script */
    {   10,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 14: not used by a script */
    {   11,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 15: not used by a script */
    {   12,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 16: not used by a script */
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
    {   15,    0,    0, 0x0000,    0,    1,    7,    1 },  /* 28: M PUNCH C */
    {   15,    0,    4, 0x0000,    0,    1,    8,    1 },  /* 29: M PUNCH C */
    {   15,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 30: M PUNCH C */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH A, no name */
    {   16,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 32: L PUNCH A, no name */
    {   16,    0,    0, 0x0000,    0,    1,   10,    1 },  /* 33: L PUNCH A, no name */
    {   16,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH A, no name */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 35: L PUNCH B */
    {   17,    0,    0, 0x0000,    0,    1,   11,    1 },  /* 36: L PUNCH B */
    {   18,    0,    6, 0x0000,    0,    5,   12,    1 },  /* 37: S KICK A */
    {   18,    0,    6, 0x0000,    0,    5,    0,    1 },  /* 38: S KICK A */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 39: M KICK A */
    {   19,    0,    0, 0x0000,    0,    1,   13,    1 },  /* 40: M KICK A */
    {   19,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 41: M KICK A */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: M KICK B */
    {   21,    0,    0, 0x0000,    0,    1,   14,    1 },  /* 43: M KICK B */
    {   21,    0,    0, 0x0000,    0,    1,   15,    1 },  /* 44: M KICK B */
    {   21,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 45: M KICK B */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 46: L KICK A, follow-up of L PUNCH B */
    {   22,    0,    9, 0x0000,    0,    1,   16,    1 },  /* 47: L KICK A, follow-up of L PUNCH B */
    {   22,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 48: L KICK A, follow-up of L PUNCH B */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 49: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 50: not used by a script */
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
    {   26,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 69: V JUMP P M A, F JUMP P L A, ATTACK 9 S: not started by a command */
    {   26,    0,   17, 0x0000,    0,    3,   27,    3 },  /* 70: V JUMP P M A */
    {   26,    0,   17, 0x0000,    0,    3,   28,    3 },  /* 71: V JUMP P M A */
    {   26,    0,   18, 0x0000,    0,    3,   29,    3 },  /* 72: V JUMP P M A, F JUMP P L A */
    {   26,    0,   18, 0x0000,    0,    3,    0,    3 },  /* 73: V JUMP P M A, F JUMP P L A */
    {   27,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 74: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +5 */
    {   27,    0,   19, 0x0000,    0,    1,    0,    5 },  /* 75: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +9 */
    {   28,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   29,    0,   20, 0x0000,    0,    1,   30,    5 },  /* 77: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   29,    0,   21, 0x0000,    0,    1,   31,    5 },  /* 78: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   29,    0,   21, 0x0000,    0,    1,    0,    5 },  /* 79: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   29,    0,   22, 0x0000,    0,    1,    0,    5 },  /* 80: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   30,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 81: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    {   30,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 82: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    {   31,    0,    0, 0x0000,    0,    3,   33,    3 },  /* 83: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {   31,    0,   23, 0x0000,    0,    3,   34,    3 },  /* 84: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   32,    0,   23, 0x0000,    0,    3,   35,    3 },  /* 85: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   32,    0,   23, 0x0000,    0,    3,    0,    3 },  /* 86: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2 */
    {   32,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 87: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN), ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 88: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 89: ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 90: ATTACK 4 S: SA I 23623+P (plain script), ATTACK 5 S: SA III 23623+P light (routine Att_DENJINHADOUKEN), ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) +1 */
    {    0,    0,    0, 0x0000,    0,    0,   36,    1 },  /* 91: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   37,    1 },  /* 92: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   38,    3 },  /* 93: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   39,    3 },  /* 94: ATTACK 12 S: after SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   33,    3 },  /* 95: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 96: follow-up of AIR NORMAL */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 97: TUKAMIKAKARI A */
    {   26,    0,   24, 0x0000,    0,    3,   40,    3 },  /* 98: F JUMP P L A */
    {   26,    0,   24, 0x0000,    0,    3,   41,    3 },  /* 99: F JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   42,    3 },  /* 100: F JUMP P M A */
    {    4,    0,    0, 0x0000,    0,    3,   43,    3 },  /* 101: F JUMP P M A */
    {    4,    0,   25, 0x0000,    0,    3,   43,    3 },  /* 102: F JUMP P M A */
    {    4,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 103: F JUMP P M A */
    {    4,    0,    0, 0x0000,    0,    3,   44,    3 },  /* 104: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   45,    3 },  /* 105: V JUMP P L A */
    {    4,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 106: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   46,    3 },  /* 107: V JUMP K S A, F JUMP K S A */
    {    4,    0,    0, 0x0000,    0,    3,   47,    3 },  /* 108: V JUMP K S A, F JUMP K S A */
    {   33,    0,    0, 0x0000,    0,    3,   48,    3 },  /* 109: V JUMP K M A */
    {   33,    0,   27, 0x0000,    0,    3,   49,    3 },  /* 110: V JUMP K M A */
    {   33,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP K M A, S V JP S P A */
    {    4,    0,   28, 0x0000,    0,    3,   50,    3 },  /* 112: V JUMP K L A */
    {    4,    0,   28, 0x0000,    0,    3,   51,    3 },  /* 113: V JUMP K L A */
    {    4,    0,   28, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   34,    0,   30, 0x0000,    0,    3,   52,    3 },  /* 115: F JUMP K M A */
    {   34,    0,   31, 0x0000,    0,    3,   53,    3 },  /* 116: F JUMP K M A */
    {   34,    0,   32, 0x0000,    0,    3,    0,    3 },  /* 117: F JUMP K M A, F JUMP K L A */
    {   34,    0,   33, 0x0000,    0,    3,   54,    3 },  /* 118: F JUMP K L A, ATTACK 7 S: not started by a command */
    {   34,    0,   34, 0x0000,    0,    3,   55,    3 },  /* 119: F JUMP K L A, ATTACK 7 S: not started by a command */
    {   35,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 120: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +5 */
    {   36,    0,   35, 0x0000,    0,    3,   56,    3 },  /* 121: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +4 */
    {   36,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +4 */
    {   37,    0,   35, 0x0000,    0,    3,   57,    3 },  /* 123: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU), ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) +2 */
    {   37,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 124: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +3 */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 125: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +2 */
    {   39,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 126: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   35,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 127: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    {   36,    0,   35, 0x0000,    0,    3,   61,    0 },  /* 128: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    {   36,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 129: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    {   37,    0,   35, 0x0000,    0,    3,   62,    0 },  /* 130: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    {   37,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 131: ATTACK 8 SP: air EX 214+KK (routine Att_KUUCHUUNICHIRINSHOU) */
    {   35,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 132: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    {   36,    0,   35, 0x0000,    0,    3,   58,    0 },  /* 133: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    {   36,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 134: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    {   37,    0,   35, 0x0000,    0,    3,   59,    0 },  /* 135: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    {   37,    0,   35, 0x0000,    0,    3,    0,    0 },  /* 136: ATTACK 3 SP: EX 214+KK (routine Att_SENPUUKYAKU) */
    {   37,    0,   35, 0x0000,    0,    3,   60,    0 },  /* 137: not used by a script */
    {   40,    0,   36, 0x0000,    0,    3,   63,    3 },  /* 138: ATTACK 9 S: not started by a command */
    {   32,    0,    0, 0x0000,    0,    3,   33,    3 },  /* 139: ATTACK 11 SP: SA II 23623+P (routine Att_SHINSHOURYUUKEN) */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 140: L PUNCH C */
    {   41,    0,    0, 0x0000,    0,    1,   64,    1 },  /* 141: L PUNCH C */
    {   41,    0,   29, 0x0000,    0,    1,   65,    1 },  /* 142: L PUNCH C */
    {   41,    0,   29, 0x0000,    0,    1,   66,    1 },  /* 143: L PUNCH C */
    {   41,    0,   29, 0x0000,    0,    1,    0,    1 },  /* 144: L PUNCH C */
    {   42,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 145: KAMAE, S V JP S P A */
    {   43,    0,    0, 0x1011,    0,    1,    0,    1 },  /* 146: KAMAE */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 147: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 148: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 149: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 150: not used by a script */
    {    1,    0,    0, 0x1210,    0,    2,    0,    2 },  /* 151: KAGAMU */
    {    2,    0,    0, 0x1210,    0,    1,    0,    5 },  /* 152: STAND UP */
    {   48,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 153: KAGAMI KAMAE */
    {   49,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 154: KAGAMI KAMAE */
    {   50,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 155: not used by a script */
    {   51,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 156: not used by a script */
    {   52,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 157: not used by a script */
    {   53,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 158: not used by a script */
    {   54,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 159: not used by a script */
    {   55,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 160: not used by a script */
    {   56,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 161: not used by a script */
    {   57,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 162: not used by a script */
    {   58,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 163: not used by a script */
    {   59,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 164: not used by a script */
    {   60,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 165: not used by a script */
    {   61,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 166: not used by a script */
    {   62,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 167: not used by a script */
    {   63,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 168: not used by a script */
    {   64,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 169: not used by a script */
    {   65,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 170: not used by a script */
    {   66,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 171: not used by a script */
    {   67,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 172: not used by a script */
    {   68,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 173: not used by a script */
    {   69,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 174: not used by a script */
    {   70,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 175: not used by a script */
    {   71,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 176: not used by a script */
    {   72,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 177: not used by a script */
    {   73,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 178: not used by a script */
    {   74,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 179: not used by a script */
    {   75,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 180: not used by a script */
    {   76,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 181: not used by a script */
    {   77,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 182: not used by a script */
    {   78,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 183: not used by a script */
    {   79,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 184: not used by a script */
    {   80,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 185: not used by a script */
    {   81,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 186: not used by a script */
    {   82,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 187: not used by a script */
    {   83,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 188: not used by a script */
    {   84,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 189: not used by a script */
    {   85,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 190: not used by a script */
    {   86,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 191: not used by a script */
    {   87,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 192: not used by a script */
    {   88,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 193: not used by a script */
    {   89,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 194: not used by a script */
    {   90,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 195: not used by a script */
    {   91,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 196: not used by a script */
    {   92,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 197: not used by a script */
    {   93,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 198: not used by a script */
    {   94,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 199: not used by a script */
    {   95,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 200: not used by a script */
    {   96,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 201: not used by a script */
    {   50,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 202: LOSE SONABA, SHIMEOTASARE */
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
    {  131,    0,    0, 0x1519,    0,    1,    0,    1 },  /* 237: FRONT WALK */
    {  132,    0,    0, 0x1218,    0,    1,    0,    1 },  /* 238: FRONT WALK */
    {  133,    0,    0, 0x1914,    0,    1,    0,    1 },  /* 239: FRONT WALK */
    {  134,    0,    0, 0x1814,    0,    1,    0,    1 },  /* 240: BACK WALK */
    {  135,    0,    0, 0x1218,    0,    1,    0,    1 },  /* 241: BACK WALK */
    {  136,    0,    0, 0x1518,    0,    1,    0,    1 },  /* 242: BACK WALK */
    {  137,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 243: FACE S, FACE M, FACE L +9 */
    {  138,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 244: FACE M, FACE L, FOOK OKU L +4 */
    {  139,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 245: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {  140,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 246: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {  141,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 247: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  142,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 248: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  143,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 249: NOUTEN M, NOUTEN L, BODY BROW L */
    {  144,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 250: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    {  145,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 251: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  146,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 252: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    {  147,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 253: KAGAMI M, KAGAMI L */
    {  148,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 254: KAGAMI L */
    {  149,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 255: UPPER L, BODY UPPER L */
    {  150,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 256: UPPER L, BODY UPPER L */
    {  151,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 257: UPPER L, BODY UPPER L */
    {  152,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 258: UPPER L, BODY UPPER L */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 259: ATTACK 9 S: not started by a command */
    {  153,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 260: HURIMUKI */
    {  154,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 261: KAGAMI TURN */
    {  155,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 262: JUMP FRONT, SP JUMP FRONT */
    {  156,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 263: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  157,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 264: JUMP FRONT, SP JUMP FRONT */
    {  157,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 265: JUMP BACK, SP JUMP BACK */
    {  155,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 266: JUMP BACK, SP JUMP BACK, no name */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 267: JUMP VERTICAL, SP JUMP V */
    {  158,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 268: JUMP VERTICAL, SP JUMP V */
    {  159,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 269: PIYO */
    {  160,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 270: PIYO */
    {  161,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 271: PIYO */
    {  162,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 272: PIYO */
    {  163,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 273: PIYO */
    {  164,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 274: KAGAMU */
    {    5,    0,    0, 0x1010,    0,    1,    0,    5 },  /* 275: DASH HUMIKOMI */
    {  165,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 276: DASH HUMIKOMI */
    {  166,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 277: DASH HUMIKOMI */
    {  167,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 278: DASH HUMIKOMI */
    {  168,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 279: DASH TOBINOKI */
    {  169,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 280: DASH TOBINOKI */
    {  170,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 281: DASH TOBINOKI */
    {  171,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 282: DASH TOBINOKI */
};

const BODY_BOX ryu_body_box[172] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -14,  22,  82,  18 },  {  -29,  58,  72,  18 },  {  -24,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +85 */
    { { {  -14,  22,  50,  18 },  {  -24,  54,  44,  16 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +21 */
    { { {    0,   0,   0,   0 },  {  -29,  58,  44,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    { { {  -14,  22,  91,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +21 */
    { { {  -20,  24,  64,  18 },  {  -30,  58,  56,  18 },  {  -26,  56,  36,  20 },  {  -36,  70,   0,  36 } } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +9 */
    { { {  -22,  24,  74,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  38,  26 },  {  -38,  76,   0,  36 } } },  /* 6: not used by a script */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 7: not used by a script */
    { { {  -14,  24,  74,  18 },  {  -30,  60,  66,  16 },  {  -22,  54,  38,  26 },  {  -30,  66,   0,  36 } } },  /* 8: PARING HEAD, ATTACK 11 S: not started by a command */
    { { {  -14,  24,  62,  18 },  {  -34,  64,  52,  18 },  {  -24,  58,  36,  20 },  {  -38,  82,   0,  36 } } },  /* 9: PARING HEAD, ATTACK 11 S: not started by a command */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 10: not used by a script */
    { { {  -14,  24,  82,  18 },  {  -32,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 11: not used by a script */
    { { {    4,  24,  82,  18 },  {  -18,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -32,  66,   0,  36 } } },  /* 12: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 13: no name */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 14: no name */
    { { {  -42,  24,  76,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 15: M PUNCH C */
    { { {  -26,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 16: L PUNCH A, no name */
    { { {   -8,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -30,  60,  38,  32 },  {  -42,  76,   0,  36 } } },  /* 17: L PUNCH B */
    { { {  -16,  24,  82,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -58,  92,   0,  36 } } },  /* 18: S KICK A */
    { { {  -26,  24,  84,  18 },  {  -34,  60,  72,  18 },  {  -36,  64,  38,  32 },  {  -40,  70,   0,  36 } } },  /* 19: M KICK A */
    { { {    4,  24,  84,  18 },  {  -26,  70,  72,  18 },  {  -32,  68,  38,  32 },  {   -4,  40,   0,  36 } } },  /* 20: M KICK B */
    { { {   14,  24,  80,  18 },  {  -24,  78,  66,  18 },  {  -32,  72,  38,  32 },  {   -4,  40,   0,  36 } } },  /* 21: M KICK B */
    { { {    2,  24,  76,  18 },  {  -34,  64,  66,  18 },  {  -42,  68,  38,  32 },  {  -30,  54,   0,  36 } } },  /* 22: L KICK A, follow-up of L PUNCH B */
    { { {  -14,  24,  64,  18 },  {  -30,  60,  60,  14 },  {  -28,  60,  34,  24 },  {  -38,  72,   0,  32 } } },  /* 23: KAGAMI P A */
    { { {   -6,  24,  76,  18 },  {  -28,  60,  68,  14 },  {  -28,  60,  34,  32 },  {  -38,  72,   0,  32 } } },  /* 24: KAGAMI P A */
    { { {  -36,  24,  90,  18 },  {  -50,  76,  80,  18 },  {  -24,  62,  44,  34 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP P S A, F JUMP P S A */
    { { {  -30,  24,  92,  18 },  {  -36,  62,  80,  18 },  {  -32,  68,  42,  36 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P M A, F JUMP P L A, ATTACK 9 S: not started by a command */
    { { {  -24,  24,  70,  18 },  {  -32,  62,  60,  18 },  {  -24,  54,  38,  20 },  {  -42,  92,   0,  36 } } },  /* 27: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +10 */
    { { {   16,  24,  78,  18 },  {  -24,  70,  70,  18 },  {  -26,  60,  38,  30 },  {  -36,  62,   0,  36 } } },  /* 28: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -24,  78,  54,  28 },  {  -36,  68,  42,  18 },  {  -26,  44,   0,  40 } } },  /* 29: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  48,  28,  20 },  {  -24,  56,   0,  26 } } },  /* 30: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) */
    { { {   -6,  24,  92,  18 },  {  -24,  50,  80,  18 },  {  -22,  48,  46,  32 },  {  -20,  48,  20,  24 } } },  /* 31: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN), ATTACK 2 SP: EX 623+PP (routine Att_SHOURYUUKEN) +1 */
    { { {  -10,  24,  92,  18 },  {  -30,  56,  78,  18 },  {  -26,  52,  46,  32 },  {  -20,  50,  20,  24 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +3 */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 33: V JUMP K M A, S V JP S P A */
    { { {  -14,  22,  91,  17 },  {  -28,  56,  80,  18 },  {  -36,  64,  40,  38 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K M A, F JUMP K L A, ATTACK 7 S: not started by a command */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -50,  20,  58,  24 } } },  /* 36: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {   30,  20,  58,  24 } } },  /* 37: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU), ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU) +5 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -30,  60,  28,  28 } } },  /* 38: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -16,  24,  90,  18 },  {  -30,  60,  80,  18 },  {  -28,  54,  46,  32 },  {  -34,  66,  12,  32 } } },  /* 39: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -30,  24,  90,  18 },  {  -52,  80,  78,  18 },  {  -46,  82,  40,  36 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 9 S: not started by a command */
    { { {  -18,  22,  74,  18 },  {  -30,  62,  66,  18 },  {  -26,  54,  36,  30 },  {  -42,  82,   0,  36 } } },  /* 41: L PUNCH C */
    { { {  -16,  22,  81,  18 },  {  -30,  60,  70,  18 },  {  -22,  52,  38,  32 },  {  -30,  62,   0,  38 } } },  /* 42: KAMAE, S V JP S P A */
    { { {  -16,  22,  87,  20 },  {  -30,  60,  78,  18 },  {  -22,  52,  42,  36 },  {  -30,  62,   0,  42 } } },  /* 43: KAMAE */
    { { {  -16,  22,  88,  18 },  {  -30,  60,  78,  18 },  {  -22,  52,  40,  36 },  {  -26,  56,   0,  38 } } },  /* 44: not used by a script */
    { { {  -16,  22,  82,  18 },  {  -30,  60,  72,  18 },  {  -22,  52,  38,  32 },  {  -34,  76,   0,  36 } } },  /* 45: not used by a script */
    { { {  -16,  22,  88,  18 },  {  -30,  60,  78,  18 },  {  -22,  52,  40,  36 },  {  -26,  56,   0,  38 } } },  /* 46: not used by a script */
    { { {  -16,  22,  82,  18 },  {  -30,  60,  72,  18 },  {  -22,  52,  38,  32 },  {  -42,  76,   0,  36 } } },  /* 47: not used by a script */
    { { {  -14,  22,  50,  18 },  {  -22,  52,  46,  14 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 48: KAGAMI KAMAE */
    { { {  -14,  22,  47,  18 },  {  -24,  54,  44,  14 },  {  -26,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 49: KAGAMI KAMAE */
    { { {   -2,  22,  80,  18 },  {  -16,  58,  70,  18 },  {  -20,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 50: LOSE SONABA, SHIMEOTASARE */
    { { {   14,  22,  80,  18 },  {  -14,  58,  70,  18 },  {  -20,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 51: not used by a script */
    { { {   24,  22,  78,  18 },  {   -8,  58,  68,  18 },  {  -18,  54,  38,  28 },  {  -30,  62,   0,  36 } } },  /* 52: not used by a script */
    { { {   18,  22,  76,  18 },  {  -14,  58,  68,  18 },  {  -20,  56,  38,  28 },  {  -30,  62,   0,  36 } } },  /* 53: not used by a script */
    { { {   -8,  22,  82,  18 },  {  -24,  58,  72,  18 },  {  -22,  54,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 54: not used by a script */
    { { {   22,  22,  78,  18 },  {   -6,  58,  68,  18 },  {  -18,  52,  38,  28 },  {  -30,  62,   0,  36 } } },  /* 55: not used by a script */
    { { {   36,  22,  66,  18 },  {   -6,  46,  66,  18 },  {  -16,  54,  38,  28 },  {  -30,  62,   0,  36 } } },  /* 56: not used by a script */
    { { {   18,  22,  54,  18 },  {  -28,  58,  64,  18 },  {  -28,  48,  38,  28 },  {  -44,  76,   0,  36 } } },  /* 57: not used by a script */
    { { {    4,  22,  60,  18 },  {  -14,  54,  56,  18 },  {  -10,  50,  36,  24 },  {  -38,  72,   0,  36 } } },  /* 58: not used by a script */
    { { {   -2,  22,  70,  18 },  {  -14,  54,  58,  18 },  {  -12,  50,  36,  24 },  {  -32,  68,   0,  36 } } },  /* 59: not used by a script */
    { { {  -10,  22,  76,  18 },  {  -22,  56,  66,  18 },  {  -18,  50,  38,  26 },  {  -30,  62,   0,  36 } } },  /* 60: not used by a script */
    { { {   46,  22,  62,  18 },  {   12,  52,  58,  18 },  {   -4,  56,  36,  22 },  {  -20,  68,   0,  34 } } },  /* 61: not used by a script */
    { { {   58,  22,  56,  18 },  {   16,  52,  58,  18 },  {    0,  56,  36,  22 },  {  -12,  60,   0,  34 } } },  /* 62: not used by a script */
    { { {   56,  22,  60,  18 },  {   16,  52,  60,  18 },  {    2,  51,  36,  24 },  {  -12,  62,   0,  34 } } },  /* 63: not used by a script */
    { { {   -6,  22,  84,  18 },  {  -12,  58,  72,  18 },  {  -18,  54,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 64: not used by a script */
    { { {   10,  22,  82,  18 },  {   -8,  58,  70,  18 },  {  -18,  54,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 65: not used by a script */
    { { {    4,  22,  82,  18 },  {  -12,  58,  72,  18 },  {  -16,  54,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 66: not used by a script */
    { { {   14,  22,  80,  18 },  {   -4,  58,  68,  18 },  {  -14,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 67: not used by a script */
    { { {   28,  22,  76,  18 },  {   -4,  58,  68,  18 },  {  -14,  54,  36,  30 },  {  -30,  62,   0,  36 } } },  /* 68: not used by a script */
    { { {   36,  22,  68,  18 },  {   -4,  58,  64,  18 },  {  -12,  52,  36,  28 },  {  -30,  62,   0,  36 } } },  /* 69: not used by a script */
    { { {   44,  22,  66,  18 },  {   10,  50,  62,  18 },  {   -2,  46,  36,  28 },  {  -14,  54,   0,  36 } } },  /* 70: not used by a script */
    { { {    0,  22,  88,  18 },  {  -18,  52,  74,  18 },  {  -24,  50,  40,  32 },  {  -30,  62,   0,  38 } } },  /* 71: not used by a script */
    { { {   32,  22,  68,  18 },  {  -10,  52,  80,  18 },  {  -30,  48,  48,  32 },  {  -30,  54,   0,  46 } } },  /* 72: not used by a script */
    { { {   30,  22,  60,  18 },  {   -8,  52,  76,  18 },  {  -32,  46,  48,  30 },  {  -36,  54,   0,  46 } } },  /* 73: not used by a script */
    { { {   22,  22,  78,  18 },  {  -14,  52,  70,  18 },  {  -28,  46,  40,  30 },  {  -32,  60,   0,  38 } } },  /* 74: not used by a script */
    { { {  -16,  22,  76,  18 },  {  -14,  50,  70,  18 },  {   -6,  48,  38,  30 },  {  -26,  62,   0,  36 } } },  /* 75: not used by a script */
    { { {  -12,  22,  70,  18 },  {  -12,  54,  66,  18 },  {   -6,  46,  38,  26 },  {  -26,  62,   0,  36 } } },  /* 76: not used by a script */
    { { {  -12,  22,  74,  18 },  {  -14,  54,  66,  18 },  {  -10,  46,  38,  28 },  {  -26,  62,   0,  36 } } },  /* 77: not used by a script */
    { { {  -14,  22,  78,  18 },  {  -22,  58,  70,  18 },  {  -20,  52,  38,  30 },  {  -28,  62,   0,  36 } } },  /* 78: not used by a script */
    { { {  -24,  22,  52,  18 },  {  -32,  60,  58,  18 },  {  -20,  48,  38,  20 },  {  -30,  62,   0,  36 } } },  /* 79: not used by a script */
    { { {  -24,  22,  48,  18 },  {  -32,  62,  58,  18 },  {  -20,  48,  38,  20 },  {  -30,  62,   0,  36 } } },  /* 80: not used by a script */
    { { {  -24,  22,  52,  18 },  {  -30,  60,  60,  18 },  {  -22,  48,  38,  22 },  {  -30,  62,   0,  36 } } },  /* 81: not used by a script */
    { { {  -24,  22,  54,  18 },  {  -28,  56,  62,  18 },  {  -22,  48,  38,  22 },  {  -30,  62,   0,  36 } } },  /* 82: not used by a script */
    { { {  -22,  22,  76,  18 },  {  -24,  54,  80,  18 },  {  -16,  46,  46,  32 },  {  -30,  62,   0,  44 } } },  /* 83: not used by a script */
    { { {   -8,  22,  66,  18 },  {   -8,  54,  62,  18 },  {   -4,  46,  38,  26 },  {  -26,  62,   0,  36 } } },  /* 84: not used by a script */
    { { {   -4,  22,  58,  18 },  {   -4,  50,  58,  18 },  {    8,  46,  38,  22 },  {  -18,  62,   0,  36 } } },  /* 85: not used by a script */
    { { {  -26,  22,  50,  18 },  {  -18,  54,  56,  18 },  {  -10,  50,  32,  24 },  {  -40,  60,   0,  36 } } },  /* 86: not used by a script */
    { { {  -34,  22,  48,  18 },  {  -24,  48,  48,  18 },  {  -20,  48,  30,  22 },  {  -44,  78,   0,  30 } } },  /* 87: not used by a script */
    { { {  -20,  22,  48,  18 },  {  -12,  48,  50,  18 },  {  -12,  48,  30,  22 },  {  -42,  78,   0,  30 } } },  /* 88: not used by a script */
    { { {  -14,  22,  52,  18 },  {   -8,  52,  58,  18 },  {   -4,  48,  32,  24 },  {  -38,  76,   0,  30 } } },  /* 89: not used by a script */
    { { {  -14,  22,  70,  18 },  {  -18,  54,  66,  18 },  {  -12,  48,  36,  28 },  {  -34,  70,   0,  34 } } },  /* 90: not used by a script */
    { { {  -20,  22,  34,  18 },  {  -18,  52,  54,  18 },  {    2,  38,  38,  26 },  {  -30,  62,   0,  36 } } },  /* 91: not used by a script */
    { { {  -12,  22,  20,  18 },  {   -8,  46,  36,  18 },  {    2,  42,  18,  22 },  {  -30,  44,   0,  40 } } },  /* 92: not used by a script */
    { { {   -8,  22,  50,  18 },  {  -22,  54,  42,  16 },  {  -14,  48,  20,  22 },  {  -36,  72,   0,  32 } } },  /* 93: not used by a script */
    { { {   24,  22,  48,  18 },  {   -4,  54,  40,  16 },  {  -12,  56,  22,  22 },  {  -34,  72,   0,  28 } } },  /* 94: not used by a script */
    { { {    2,  22,  50,  18 },  {  -12,  56,  42,  16 },  {  -14,  50,  20,  22 },  {  -36,  72,   0,  30 } } },  /* 95: not used by a script */
    { { {   42,  22,  34,  18 },  {   -2,  52,  36,  16 },  {    4,  56,  18,  20 },  {  -34,  74,   0,  26 } } },  /* 96: not used by a script */
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
    { { {  -16,  22,  86,  18 },  {  -30,  60,  73,  18 },  {  -22,  52,  38,  34 },  {  -30,  72,   0,  38 } } },  /* 131: FRONT WALK */
    { { {  -16,  22,  83,  18 },  {  -30,  60,  72,  18 },  {  -22,  52,  36,  36 },  {  -22,  74,   0,  36 } } },  /* 132: FRONT WALK */
    { { {  -16,  22,  88,  18 },  {  -30,  60,  78,  18 },  {  -22,  52,  42,  36 },  {  -22,  52,   0,  42 } } },  /* 133: FRONT WALK */
    { { {  -17,  22,  85,  18 },  {  -32,  60,  74,  18 },  {  -22,  48,  38,  36 },  {  -34,  70,   0,  38 } } },  /* 134: BACK WALK */
    { { {  -17,  22,  83,  18 },  {  -32,  60,  73,  18 },  {  -22,  48,  38,  34 },  {  -46,  70,   0,  38 } } },  /* 135: BACK WALK */
    { { {  -17,  22,  89,  18 },  {  -32,  60,  78,  18 },  {  -22,  48,  42,  36 },  {  -26,  50,   0,  42 } } },  /* 136: BACK WALK */
    { { {    2,  22,  80,  18 },  {  -21,  58,  71,  18 },  {  -20,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 137: FACE S, FACE M, FACE L +9 */
    { { {   14,  22,  78,  18 },  {  -15,  58,  70,  18 },  {  -17,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 138: FACE M, FACE L, FOOK OKU L +4 */
    { { {   22,  22,  76,  18 },  {  -11,  58,  69,  18 },  {  -15,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 139: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {   26,  22,  74,  18 },  {   -9,  58,  68,  18 },  {  -14,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 140: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {  -18,  22,  79,  18 },  {  -27,  58,  70,  18 },  {  -22,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 141: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -22,  22,  76,  18 },  {  -25,  58,  68,  18 },  {  -20,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 142: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -26,  22,  73,  18 },  {  -23,  58,  66,  18 },  {  -18,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 143: NOUTEN M, NOUTEN L, BODY BROW L */
    { { {  -30,  22,  70,  18 },  {  -21,  58,  64,  18 },  {  -16,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 144: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    { { {   -8,  22,  50,  18 },  {  -22,  54,  44,  16 },  {  -25,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 145: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {   -2,  22,  50,  18 },  {  -20,  54,  44,  16 },  {  -24,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 146: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    { { {    4,  22,  50,  18 },  {  -18,  54,  44,  16 },  {  -23,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 147: KAGAMI M, KAGAMI L */
    { { {   10,  22,  50,  18 },  {  -16,  54,  44,  16 },  {  -22,  55,  28,  18 },  {  -36,  70,   0,  32 } } },  /* 148: KAGAMI L */
    { { {    2,  22,  86,  18 },  {  -25,  58,  72,  18 },  {  -25,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 149: UPPER L, BODY UPPER L */
    { { {   10,  22,  85,  18 },  {  -22,  58,  72,  18 },  {  -26,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 150: UPPER L, BODY UPPER L */
    { { {   14,  22,  84,  18 },  {  -20,  58,  72,  18 },  {  -27,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 151: UPPER L, BODY UPPER L */
    { { {   16,  22,  83,  18 },  {  -19,  58,  72,  18 },  {  -28,  53,  38,  32 },  {  -30,  62,   0,  36 } } },  /* 152: UPPER L, BODY UPPER L */
    { { {  -10,  22,  82,  18 },  {  -31,  58,  72,  18 },  {  -28,  53,  38,  32 },  {  -34,  62,   0,  36 } } },  /* 153: HURIMUKI */
    { { {  -10,  22,  50,  18 },  {  -24,  54,  44,  16 },  {  -26,  55,  28,  18 },  {  -32,  70,   0,  32 } } },  /* 154: KAGAMI TURN */
    { { {  -21,  22,  93,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 155: JUMP FRONT, SP JUMP FRONT, JUMP BACK +2 */
    { { {  -42,  22,  77,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  46,  32 },  {  -20,  42,  32,  15 } } },  /* 156: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -12,  22,  91,  17 },  {  -25,  50,  82,  18 },  {  -28,  53,  52,  28 },  {  -26,  42,  36,  15 } } },  /* 157: JUMP FRONT, SP JUMP FRONT, JUMP BACK +1 */
    { { {  -20,  22,  87,  17 },  {  -25,  50,  80,  18 },  {  -28,  53,  57,  21 },  {  -36,  61,  40,  15 } } },  /* 158: JUMP VERTICAL, SP JUMP V */
    { { {  -29,  24,  78,  18 },  {  -45,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 159: PIYO */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 160: PIYO */
    { { {  -11,  24,  79,  18 },  {  -28,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 161: PIYO */
    { { {    4,  24,  83,  18 },  {  -16,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -28,  62,   0,  36 } } },  /* 162: PIYO */
    { { {  -10,  22,  83,  18 },  {  -32,  60,  78,  18 },  {  -24,  50,  38,  38 },  {  -32,  66,   0,  36 } } },  /* 163: PIYO */
    { { {  -14,  22,  46,  18 },  {  -24,  54,  42,  16 },  {  -26,  55,  24,  18 },  {  -36,  70,   0,  36 } } },  /* 164: KAGAMU */
    { { {  -20,  24,  80,  18 },  {  -34,  58,  70,  18 },  {  -30,  54,  38,  30 },  {  -42,  76,   0,  36 } } },  /* 165: DASH HUMIKOMI */
    { { {  -18,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  34,  30 },  {  -36,  76,   0,  32 } } },  /* 166: DASH HUMIKOMI */
    { { {  -24,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  36,  28 },  {  -38,  76,   0,  34 } } },  /* 167: DASH HUMIKOMI */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 168: DASH TOBINOKI */
    { { {    0,  24,  76,  18 },  {  -24,  60,  66,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 169: DASH TOBINOKI */
    { { {   -9,  24,  81,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 170: DASH TOBINOKI */
    { { {   -6,  22,  80,  18 },  {  -24,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -26,  66,   0,  36 } } },  /* 171: DASH TOBINOKI */
};

const HAND_BOX ryu_hand_box[37] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  22,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -76,  44,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH B */
    { { {  -70,  40,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH B */
    { { {  -56,  22,  44,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH C */
    { { {  -50,  30,  80,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A, no name */
    { { {  -64,  38,  20,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S KICK A */
    { { {  -66,  28,  40,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M KICK A */
    { { {  -80,  52,  46,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK B */
    { { {  -62,  36,  58,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L KICK A, follow-up of L PUNCH B */
    { { {  -60,  28,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -30,  28,  80,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A */
    { { {  -74,  34,   0,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A */
    { { {  -62,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI K A */
    { { {  -72,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI K A */
    { { {  -54,  28,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: V JUMP P S A, F JUMP P S A */
    { { {  -54,  28,  56,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P S A, F JUMP P S A */
    { { {  -58,  26,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P M A */
    { { {  -58,  26,  52,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A, F JUMP P L A */
    { { {  -64,  30,  52,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +9 */
    { { {  -54,  34,  46,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -64,  38,  56,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -64,  38,  42,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: ATTACK 10 S: 4123+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 4123+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 4123+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -28,  18,  98,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -64,  30,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: F JUMP P L A */
    { { {  -58,  28,  76,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: F JUMP P M A */
    { { {  -70,  40,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P L A */
    { { {  -60,  24,  50,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP K M A, S V JP S P A */
    { { {  -60,  30,  62,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP K L A */
    { { {  -56,  32,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: L PUNCH C */
    { { {  -52,  28,  60,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M A */
    { { {  -66,  38,  54,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP K M A */
    { { {  -68,  38,  44,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP K M A, F JUMP K L A */
    { { {  -72,  42,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: F JUMP K L A, ATTACK 7 S: not started by a command */
    { { {  -70,  40,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K L A, ATTACK 7 S: not started by a command */
    { { {  -20,  40,  38,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy (routine Att_SENPUUKYAKU) +6 */
    { { {  -80,  32,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 9 S: not started by a command */
};

const HOSEI_BOX ryu_hos_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +96 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +44 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +70 */
    { {  -25,   50,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +2 */
    { {  -25,   50,    0,   72 } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +48 */
};
