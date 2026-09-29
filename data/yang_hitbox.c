/*
 * YANG_HITBOX.C  Yang's hit boxes
 *
 * Each of Yang's animation frames names an entry of yang_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX yang_hit_ix_table[388] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +27 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +108 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +33 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +6 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: TUKAMIHAZUSI, TUKAMIHAZUSARE, no name +4 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 5: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: GUARD AIR */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 7: not used by a script */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: GUARD AIR */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: not used by a script */
    {   14,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 10: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    {   10,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 11: not used by a script */
    {   11,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 12: M KICK A, no name */
    {   11,    0,    2, 0x0000,    0,    1,   48,    1 },  /* 13: M KICK A, follow-up of S KICK A, no name */
    {   11,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 14: M KICK A, follow-up of S KICK A, no name */
    {   12,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 15: M KICK A, follow-up of S KICK A, no name */
    {   15,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 16: not used by a script */
    {   16,    0,    0, 0x0000,    0,    0,    0,   21 },  /* 17: no name */
    {   17,    0,    0, 0x0000,    0,    1,    3,    1 },  /* 18: not used by a script */
    {   17,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 19: not used by a script */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 20: not used by a script */
    {   18,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 21: not used by a script */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 22: not used by a script */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: not used by a script */
    {   21,    0,   12, 0x0000,    0,    1,   60,    1 },  /* 24: not used by a script */
    {   21,    0,   12, 0x0000,    0,    1,   61,    1 },  /* 25: not used by a script */
    {   21,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 26: not used by a script */
    {   23,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 27: S PUNCH A, follow-up of ZANNEN 2 */
    {   24,    0,   14, 0x0000,    0,    1,    6,    1 },  /* 28: S PUNCH A, follow-up of ZANNEN 2 */
    {   24,    0,   14, 0x0000,    0,    1,   39,    1 },  /* 29: S PUNCH A, follow-up of ZANNEN 2 */
    {   25,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 30: M PUNCH B, no name */
    {   26,    0,   15, 0x0000,    0,    1,    7,    1 },  /* 31: M PUNCH B, no name */
    {   26,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 32: not used by a script */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 33: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,    0,   16, 0x0000,    0,    1,    8,    1 },  /* 34: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,    0,   16, 0x0000,    0,    1,   40,    1 },  /* 35: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,    0,   16, 0x0000,    0,    1,    0,    1 },  /* 36: M PUNCH A, follow-up of ZANNEN 4 */
    {   31,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 37: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   31,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 38: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   32,    0,   19, 0x0000,    0,    1,   42,    1 },  /* 39: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,    0,   20, 0x0000,    0,    1,   43,    1 },  /* 40: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 41: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    {   35,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: follow-up of M PUNCH A, M PUNCH B */
    {   36,    0,   21, 0x0000,    0,    1,   10,    1 },  /* 44: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    {   36,    0,   21, 0x0000,    0,    1,   44,    1 },  /* 45: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    {   36,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 46: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: L PUNCH B, follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    {   38,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: L PUNCH B */
    {   39,    0,   22, 0x0000,    0,    1,   11,    1 },  /* 49: L PUNCH B */
    {   39,    0,   22, 0x0000,    0,    1,   45,    1 },  /* 50: L PUNCH B */
    {   39,    0,   22, 0x0000,    0,    1,    0,    1 },  /* 51: L PUNCH B */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: S KICK A, follow-up of ZANNEN 7 */
    {   41,    0,   23, 0x0000,    0,    1,   12,    1 },  /* 53: not used by a script */
    {   41,    0,   23, 0x0000,    0,    1,   13,    1 },  /* 54: not used by a script */
    {   41,    0,   23, 0x0000,    0,    1,    0,    1 },  /* 55: not used by a script */
    {   41,    0,   23, 0x0000,    0,    1,   46,    1 },  /* 56: S KICK A, follow-up of ZANNEN 7 */
    {   41,    0,   23, 0x0000,    0,    1,   47,    1 },  /* 57: S KICK A, follow-up of ZANNEN 7 */
    {   24,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 58: S PUNCH A, follow-up of ZANNEN 2 */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 59: M KICK A, follow-up of S KICK A, no name */
    {   46,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 60: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {   47,    0,   27, 0x0000,    0,    2,   14,    2 },  /* 61: follow-up of WIN 2 */
    {   47,    0,   27, 0x0000,    0,    2,   19,    2 },  /* 62: follow-up of WIN 2 */
    {   47,    0,   27, 0x0000,    0,    2,    0,    2 },  /* 63: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {    2,    0,   28, 0x0000,    0,    2,   56,    2 },  /* 64: KAGAMI P A, follow-up of WIN 4 */
    {    2,    0,   29, 0x0000,    0,    2,   56,    2 },  /* 65: KAGAMI P A, follow-up of WIN 4 */
    {    2,    0,    4, 0x0000,    0,    2,   90,    2 },  /* 66: KAGAMI P A, follow-up of WIN 4 */
    {    2,    0,   32, 0x0000,    0,    2,    0,    2 },  /* 67: follow-up of follow-up of KAGAMI K A, follow-up of WIN 5, follow-up of WIN 6 */
    {    2,    0,    1, 0x0000,    0,    2,   57,    2 },  /* 68: follow-up of WIN 5, follow-up of WIN 6 */
    {    2,    0,    3, 0x0000,    0,    2,   57,    2 },  /* 69: follow-up of WIN 5, follow-up of WIN 6 */
    {    2,    0,    3, 0x0000,    0,    2,    0,    2 },  /* 70: follow-up of follow-up of KAGAMI K A, follow-up of WIN 6 */
    {   56,    0,    0, 0x0000,    0,    2,    0,    8 },  /* 71: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   57,    0,    0, 0x0000,    0,    2,    0,    8 },  /* 72: follow-up of WIN 7 */
    {   58,    0,   31, 0x0000,    0,    2,   18,    8 },  /* 73: not used by a script */
    {   58,    0,   31, 0x0000,    0,    2,   58,    8 },  /* 74: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   58,    0,   31, 0x0000,    0,    2,    0,    8 },  /* 75: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: not used by a script */
    {   17,    0,    8, 0x0000,    0,    1,    5,    1 },  /* 77: not used by a script */
    {   22,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 78: not used by a script */
    {   50,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 79: not used by a script */
    {  100,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 80: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +2 */
    {   53,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 81: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    {   51,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 82: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    {   52,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 83: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    {   61,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 84: not used by a script */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 86: GUARD HEAD */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 87: GUARD UP, P BREAK ZUJOU, TUKAMIHAZUSI +1 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 88: GUARD DOWN, P BREAK DOWN */
    {   72,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 89: not used by a script */
    {   73,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 90: DASH HUMIKOMI */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 91: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {   74,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 92: not used by a script */
    {   47,    0,   27, 0x0000,    0,    2,   54,    2 },  /* 93: KAGAMI P A, follow-up of WIN 3 */
    {   47,    0,   27, 0x0000,    0,    2,   55,    2 },  /* 94: KAGAMI P A, follow-up of WIN 3 */
    {    2,    0,    5, 0x0000,    0,    2,   84,    2 },  /* 95: KAGAMI P A, follow-up of WIN 4 */
    {    2,    0,    6, 0x0000,    0,    2,    0,    2 },  /* 96: KAGAMI P A, follow-up of WIN 4, ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {  107,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 97: follow-up of HANASARE, APPEAR JUNBI 2, follow-up of SP APPEAR 2, follow-up of APPEAR JUNBI 5 +7 */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 98: M KICK C, follow-up of JUDGMENT WAIT */
    {   80,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 99: M KICK C, follow-up of JUDGMENT WAIT */
    {   81,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 100: M KICK C, follow-up of JUDGMENT WAIT */
    {   82,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 101: M KICK C, follow-up of JUDGMENT WAIT */
    {   42,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 102: M KICK C, follow-up of JUDGMENT WAIT */
    {   43,    0,   24, 0x0000,    0,    1,   20,    1 },  /* 103: M KICK C, follow-up of JUDGMENT WAIT, no name */
    {   83,    0,    0, 0x0000,    0,   17,    0,   18 },  /* 104: not used by a script */
    {   83,    0,    0, 0x0000,    0,   17,   22,   18 },  /* 105: not used by a script */
    {   84,    0,    0, 0x0000,    0,   17,   23,   18 },  /* 106: not used by a script */
    {   84,    0,    0, 0x0000,    0,   17,    0,   18 },  /* 107: not used by a script */
    {   85,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 108: ATTACK 12 M: not started by a command */
    {   86,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 109: ATTACK 12 M: not started by a command */
    {   87,    0,   36, 0x0000,    0,    1,   24,    1 },  /* 110: ATTACK 12 M: not started by a command */
    {   88,    0,    0, 0x0000,    0,    1,   25,    1 },  /* 111: ATTACK 12 M: not started by a command */
    {   89,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 112: ATTACK 12 M: not started by a command */
    {   90,    0,    0, 0x0000,    0,    1,   26,    1 },  /* 113: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {   90,    0,    0, 0x0000,    0,    1,   27,    1 },  /* 114: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {  138,    0,   54, 0x0000,    0,    1,   27,    1 },  /* 115: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {   93,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 116: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   91,    0,   38, 0x0000,    0,    4,    0,    4 },  /* 117: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    {   91,    0,   38, 0x0000,    0,    4,   29,    4 },  /* 118: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    {   92,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 119: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    {   93,    0,    0, 0x0000,    0,    3,   30,    3 },  /* 120: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   94,    0,   39, 0x0000,    0,    4,   31,    4 },  /* 121: ATTACK 5 S: not started by a command */
    {   94,    0,   39, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   95,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 123: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   96,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 124: ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI), ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) +2 */
    {   97,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 125: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 11 L: not started by a command */
    {   97,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 126: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 11 L: not started by a command */
    {   97,    0,    0, 0x0000,    0,    2,   32,    2 },  /* 127: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    {   99,    0,    0, 0x0000,    0,    2,   33,    2 },  /* 128: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    {  100,    0,    0, 0x0000,    0,    5,   34,    1 },  /* 129: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    {  100,    0,    0, 0x0000,    0,    5,   64,    1 },  /* 130: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    {  103,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 131: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {  104,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 132: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,    0,   41, 0x0000,    0,    3,   37,    3 },  /* 133: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,    0,   41, 0x0000,    0,    3,   38,    3 },  /* 134: not used by a script */
    {  106,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 135: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {   29,    0,   17, 0x0000,    0,    1,   41,    1 },  /* 136: M PUNCH B, no name */
    {   29,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 137: M PUNCH B, no name */
    {   30,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 138: M PUNCH B, no name */
    {  101,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 139: V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {  102,    0,   40, 0x0000,    0,    3,   35,    3 },  /* 140: F JUMP P S A, follow-up of SEAN BALL HIT */
    {  102,    0,   40, 0x0000,    0,    3,   36,    3 },  /* 141: V JUMP P S A, follow-up of JUDGMENT LOSE */
    {  105,    0,   41, 0x0000,    0,    3,   49,    3 },  /* 142: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,    0,   41, 0x0000,    0,    3,   50,    3 },  /* 143: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,    0,   41, 0x0000,    0,    3,    0,    3 },  /* 144: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {   44,    0,   25, 0x0000,    0,    1,   21,    1 },  /* 145: M KICK C, follow-up of JUDGMENT WAIT */
    {   45,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 146: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    {    1,    0,    0, 0x0000,    1,    1,   53,    1 },  /* 147: TUKAMIKAKARI C, TUKAMIKAKARI A, TUKAMIKAKARI B */
    {  110,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 148: not used by a script */
    {  111,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 149: not used by a script */
    {  112,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 150: not used by a script */
    {  113,    0,   45, 0x0000,    0,    1,   62,    1 },  /* 151: not used by a script */
    {  113,    0,   45, 0x0000,    0,    1,   63,    1 },  /* 152: not used by a script */
    {  113,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 153: not used by a script */
    {  114,    0,   46, 0x0000,    0,    1,    0,    1 },  /* 154: not used by a script */
    {  115,    0,   47, 0x0000,    0,    1,    0,    1 },  /* 155: not used by a script */
    {   63,    0,    0, 0x0000,    0,    2,   65,    9 },  /* 156: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   98,    0,    0, 0x0000,    0,    2,   66,    9 },  /* 157: not used by a script */
    {   64,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 158: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   65,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 159: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,    0,   33, 0x0000,    0,    3,   67,    3 },  /* 160: not used by a script */
    {   66,    0,   33, 0x0000,    0,    3,   68,    3 },  /* 161: not used by a script */
    {   66,    0,   33, 0x0000,    0,    3,   69,    3 },  /* 162: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,    0,   33, 0x0000,    0,    3,   70,    3 },  /* 163: not used by a script */
    {   66,    0,   33, 0x0000,    0,    3,   71,    3 },  /* 164: not used by a script */
    {   66,    0,   33, 0x0000,    0,    3,   72,    3 },  /* 165: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   66,    0,   33, 0x0000,    0,    3,   73,    3 },  /* 166: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {   67,    0,   34, 0x0000,    0,    3,    0,    3 },  /* 167: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    {   68,    0,   35, 0x0000,    0,    3,   74,    3 },  /* 168: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    {   68,    0,   35, 0x0000,    0,    3,   75,    3 },  /* 169: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    {   68,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 170: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +1 */
    {  118,    0,   48, 0x0000,    0,    3,    0,    3 },  /* 171: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    {  116,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 172: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  117,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 173: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  118,    0,   48, 0x0000,    0,    3,   78,    3 },  /* 174: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,    0,   48, 0x0000,    0,    3,   79,    3 },  /* 175: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,    0,   48, 0x0000,    0,    3,   80,    3 },  /* 176: not used by a script */
    {  118,    0,   48, 0x0000,    0,    3,   81,    3 },  /* 177: not used by a script */
    {  119,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 178: F JUMP K S B, F JUMP K M B, F JUMP K L B +3 */
    {  120,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 179: F JUMP K S B, F JUMP K M B, F JUMP K L B +3 */
    {  121,    0,   49, 0x0000,    0,    3,   82,    3 },  /* 180: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1 */
    {  121,    0,   49, 0x0000,    0,    3,   83,    3 },  /* 181: F JUMP K M B, F JUMP K L B, follow-up of F JUMP K M A +2 */
    {  122,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 182: follow-up of SP APPEAR 4 */
    {  123,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 183: follow-up of APPEAR 4 */
    {  124,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 184: follow-up of APPEAR 5 */
    {  125,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 185: follow-up of APPEAR 5 */
    {  126,    0,   50, 0x0000,    2,    1,    0,    1 },  /* 186: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    {  127,    0,   51, 0x0000,    0,    1,    0,    1 },  /* 187: TUKAMIKAKARI A, TUKAMIKAKARI B, ATTACK 9 S: 6(123)4+K (plain script) +1 */
    {  128,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 188: BODY SLAM, IPPONZEOI, TOMOE RYU +5 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 189: ATTACK 5 S: not started by a command, ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 10 M: SA III 23623+P (plain script) +1 */
    {    0,    0,    0, 0x0000,    0,    0,   51,    1 },  /* 190: not used by a script */
    {   29,    0,   17, 0x0000,    0,    1,   52,    1 },  /* 191: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 192: follow-up of AIR NORMAL, CATCH 10 */
    {  131,    0,    0, 0x0000,    0,    6,    0,    1 },  /* 193: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    {  132,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 194: ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI), ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) +2 */
    {  133,    0,   52, 0x0000,    0,    1,   85,    1 },  /* 195: follow-up of follow-up of S KICK A, no name */
    {  133,    0,   52, 0x0000,    0,    1,   86,    1 },  /* 196: follow-up of follow-up of S KICK A, no name */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 197: follow-up of follow-up of S KICK A, no name */
    {   98,    0,    0, 0x0000,    0,    2,   87,    2 },  /* 198: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   99,    0,    0, 0x0000,    0,    1,   88,    2 },  /* 199: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {   17,    0,    8, 0x0000,    0,    1,   89,    1 },  /* 200: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 201: not used by a script */
    {  136,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 202: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 2 SP: EX 214+PP (plain script), not started by a command */
    {  137,    0,   73, 0x0000,    0,    3,   91,    3 },  /* 203: ATTACK 12 L: not started by a command, not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,   21 },  /* 204: NEKOROBI S, no name */
    {  133,    0,   52, 0x0000,    0,    1,    0,    1 },  /* 205: follow-up of follow-up of S KICK A */
    {   46,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 206: KAGAMI P A */
    {   47,    0,   27, 0x0000,    0,   18,   14,    2 },  /* 207: KAGAMI P A */
    {   47,    0,   27, 0x0000,    0,   18,   19,    2 },  /* 208: KAGAMI P A */
    {   47,    0,   27, 0x0000,    0,   18,    0,    2 },  /* 209: KAGAMI P A */
    {   59,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 210: not used by a script */
    {   54,    0,   30, 0x0000,    0,   18,   17,    2 },  /* 211: not used by a script */
    {   54,    0,   30, 0x0000,    0,   18,    0,    2 },  /* 212: not used by a script */
    {  100,    0,    0, 0x0000,    0,    5,   92,    1 },  /* 213: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    {  107,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 214: not used by a script */
    {   66,    0,   33, 0x0000,    0,    3,    0,    3 },  /* 215: V JUMP P L A, follow-up of JUDGMENT LOSE */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 216: LOSE SONABA */
    {  132,    0,    0, 0x0000,    0,    1,   65,    2 },  /* 217: ATTACK 11 SP: not started by a command, ATTACK 12 S: not started by a command */
    {  138,    0,   54, 0x0000,    0,    1,    0,    1 },  /* 218: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    {  138,    0,   54, 0x0000,    0,    1,   26,    1 },  /* 219: follow-up of follow-up of M PUNCH A, M PUNCH B */
    {   14,    0,    5, 0x0000,    0,    1,   28,    1 },  /* 220: follow-up of S KICK A */
    {   11,    0,    2, 0x0000,    0,    1,   93,    1 },  /* 221: follow-up of S KICK A */
    {  139,    0,   55, 0x0000,    0,    3,   80,    3 },  /* 222: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,    0,   56, 0x0000,    0,    3,   81,    3 },  /* 223: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,    0,   56, 0x0000,    0,    3,    0,    3 },  /* 224: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  140,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 225: not used by a script */
    {  141,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 226: not used by a script */
    {  142,    0,   57, 0x0000,    0,    3,   94,    3 },  /* 227: not used by a script */
    {  143,    0,   58, 0x0000,    0,    3,   95,    3 },  /* 228: not used by a script */
    {    1,    0,   11, 0x0000,    0,    1,   96,    1 },  /* 229: not started by a command */
    {  144,    0,    0, 0x0000,    0,    1,    0,   22 },  /* 230: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +4 */
    {  144,    0,    7, 0x0000,    0,    1,   97,   22 },  /* 231: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  144,    0,    7, 0x0000,    0,    1,    0,   22 },  /* 232: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  145,    0,    0, 0x0000,    0,    1,    0,   22 },  /* 233: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  145,    0,    8, 0x0000,    0,    1,   98,   22 },  /* 234: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  145,    0,    8, 0x0000,    0,    1,    0,   22 },  /* 235: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  146,    0,    0, 0x0000,    0,    1,    0,   22 },  /* 236: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  146,    0,    9, 0x0000,    0,    1,   99,   22 },  /* 237: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  146,    0,    9, 0x0000,    0,    1,  100,   22 },  /* 238: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  146,    0,    9, 0x0000,    0,    1,    0,   22 },  /* 239: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  146,    0,    9, 0x0000,    0,    1,    0,    0 },  /* 240: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), after 236+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,  101,    1 },  /* 241: ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  147,    0,    0, 0x0000,    0,    1,  101,    1 },  /* 242: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  147,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 243: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 244: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 8 S: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,  102,    0 },  /* 245: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 8 S: not started by a command */
    {  144,    0,    0, 0x0000,    0,    1,   97,   22 },  /* 246: ATTACK 4 SP: EX 236+PP (routine Att_SLIDE_and_JUMP) */
    {  148,    0,    0, 0x0000,    0,    5,   34,    1 },  /* 247: ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) */
    {  121,    0,   49, 0x0000,    0,    3,  103,    3 },  /* 248: follow-up of F JUMP K M A */
    {   14,    0,    5, 0x0000,    0,    1,  104,    1 },  /* 249: not used by a script */
    {  133,    0,   52, 0x0000,    0,    1,  105,    1 },  /* 250: not used by a script */
    {  149,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 251: UPPER L, BODY UPPER L */
    {  150,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 252: UPPER L, BODY UPPER L */
    {  151,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 253: UPPER L, BODY UPPER L */
    {  152,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 254: UPPER L, BODY UPPER L */
    {  153,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 255: FACE S, FACE M, FACE L +5 */
    {  154,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 256: FACE M, FACE L, FOOK OKU L +3 */
    {  155,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 257: not used by a script */
    {  156,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 258: not used by a script */
    {  157,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 259: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  158,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 260: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    {  159,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 261: NOUTEN M, NOUTEN L, BODY BROW L */
    {  160,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 262: NOUTEN L, BODY BROW L, TATAKI S */
    {  161,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 263: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  162,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 264: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    {  163,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 265: KAGAMI M, KAGAMI L */
    {  164,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 266: KAGAMI L */
    {  144,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 267: 623+K light (routine Att_PL10_MACH_SLIDE2), 623+K medium (routine Att_PL10_MACH_SLIDE2), 623+K heavy/EX (routine Att_PL10_MACH_SLIDE2) */
    {  165,    0,   59, 0x0000,    0,    1,    0,    1 },  /* 268: M KICK B */
    {  165,    0,   60, 0x0000,    0,    1,    0,    1 },  /* 269: M KICK B */
    {  166,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 270: M KICK B */
    {  167,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 271: M KICK B */
    {  167,    0,   65, 0x0000,    0,    1,  106,    1 },  /* 272: not used by a script */
    {  167,    0,   65, 0x0000,    0,    1,  107,    1 },  /* 273: not used by a script */
    {  167,    0,   66, 0x0000,    0,    1,    0,    1 },  /* 274: M KICK B */
    {  167,    0,   62, 0x0000,    0,    1,    0,    1 },  /* 275: M KICK B */
    {  168,    0,   64, 0x0000,    0,    1,  109,    1 },  /* 276: L KICK A */
    {  168,    0,   64, 0x0000,    0,    1,  110,    1 },  /* 277: L KICK A */
    {  168,    0,   63, 0x0000,    0,    1,    0,    1 },  /* 278: L KICK A */
    {  168,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 279: L KICK A */
    {  126,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 280: TUKAMIKAKARI A, TUKAMIKAKARI B */
    {    1,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 281: JUMP JUNBI */
    {   14,    0,    0, 0x0000,    0,    1,  111,    1 },  /* 282: M KICK A */
    {  167,    0,   66, 0x0000,    0,    1,  112,    1 },  /* 283: M KICK B */
    {  167,    0,   66, 0x0000,    0,    1,  108,    1 },  /* 284: M KICK B */
    {  114,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 285: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {  115,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 286: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {  121,    0,   49, 0x0000,    0,    3,  113,    3 },  /* 287: F JUMP K S B */
    {  121,    0,   49, 0x0000,    0,    3,  114,    3 },  /* 288: F JUMP K S B */
    {  169,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 289: AIR NORMAL, UPPER, BODY UPPER +5 */
    {  170,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 290: ASIBARAI SIRI, GILL */
    {  171,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 291: ASIBARAI SIRI, GILL */
    {  172,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 292: ASIBARAI SIRI, GILL */
    {  173,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 293: ASIBARAI SIRI, GILL */
    {  174,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 294: ASIB TUNNOMERI, HUMI ASIB */
    {  175,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 295: ASIB TUNNOMERI, HUMI ASIB */
    {  176,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 296: ASIB TUNNOMERI, HUMI ASIB */
    {  177,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 297: ASIB TUNNOMERI, HUMI ASIB */
    {  178,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 298: NOKEZORI, UPPER, BODY UPPER +5 */
    {  179,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 299: NOKEZORI, UPPER, BODY UPPER +7 */
    {  180,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 300: NOKEZORI, UPPER, BODY UPPER +7 */
    {  181,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 301: NOKEZORI, UPPER, BODY UPPER +9 */
    {  182,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 302: NOKEZORI, UPPER, BODY UPPER +9 */
    {  183,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 303: NOKEZORI, UPPER, BODY UPPER +9 */
    {  184,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 304: NOKEZORI, UPPER, BODY UPPER +9 */
    {  185,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 305: NOKEZORI, UPPER, BODY UPPER +9 */
    {  186,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 306: KUNOJI, KUNOJI NOKE */
    {  187,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 307: KUNOJI, KUNOJI NOKE */
    {  188,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 308: KUNOJI, KUNOJI NOKE */
    {  189,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 309: KUNOJI, TTKI V. AIR */
    {  190,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 310: KIRIMOMI */
    {  191,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 311: KIRIMOMI */
    {  192,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 312: KIRIMOMI */
    {  193,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 313: KIRIMOMI */
    {  194,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 314: KIRIMOMI */
    {  195,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 315: KIRIMOMI */
    {  196,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 316: KIRIMOMI */
    {  197,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 317: KIRIMOMI */
    {  198,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 318: KIRIMOMI */
    {  199,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 319: KIRIMOMI */
    {  200,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 320: KIRIMOMI */
    {  201,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 321: KIRIMOMI */
    {  202,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 322: UPPER, BODY UPPER, ALEX B.D +1 */
    {  203,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 323: UPPER, BODY UPPER, ALEX B.D +1 */
    {  204,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 324: TTKI V. AIR */
    {  205,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 325: TTKI V. AIR */
    {  206,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 326: TTKI V. AIR */
    {  207,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 327: DENKI */
    {  208,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 328: TOUKETSU A */
    {  209,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 329: BODY UPPER SP */
    {   46,    0,   67, 0x0000,    0,    2,    0,    2 },  /* 330: KAGAMI P A */
    {   46,    0,   67, 0x0000,    0,    2,  115,    2 },  /* 331: KAGAMI P A */
    {   46,    0,   68, 0x0000,    0,    2,    0,    2 },  /* 332: KAGAMI P A */
    {   46,    0,   69, 0x0000,    0,    2,    0,    2 },  /* 333: KAGAMI P A */
    {  218,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 334: ATTACK 12 L: not started by a command */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 335: FRONT WALK, BACK WALK */
    {  210,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 336: FRONT WALK */
    {  211,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 337: FRONT WALK */
    {  212,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 338: BACK WALK */
    {  213,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 339: BACK WALK */
    {  214,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 340: HURIMUKI */
    {  215,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 341: HURIMUKI */
    {  216,    0,    0, 0x1515,    0,    2,    0,    2 },  /* 342: KAGAMI TURN */
    {    2,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 343: STAND UP */
    {  217,    0,    0, 0x1010,    0,    2,    0,   10 },  /* 344: STAND UP */
    {  217,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 345: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU */
    {  218,    0,    0, 0x0000,    0,    3,    0,   10 },  /* 346: SP JUMP JUNBI */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 347: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  219,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 348: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  220,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 349: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  221,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 350: PIYO */
    {  222,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 351: PIYO */
    {  223,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 352: KAMAE */
    {  224,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 353: KAMAE */
    {  225,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 354: KAMAE */
    {  226,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 355: DASH HUMIKOMI */
    {  227,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 356: DASH HUMIKOMI */
    {   73,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 357: DASH HUMIKOMI */
    {  228,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 358: DASH HUMIKOMI */
    {  229,    0,    0, 0x1A1A,    0,    1,    0,   10 },  /* 359: DASH HUMIKOMI */
    {  230,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 360: DASH TOBINOKI */
    {  231,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 361: DASH TOBINOKI */
    {  232,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 362: DASH TOBINOKI */
    {  233,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 363: DASH TOBINOKI */
    {  234,    0,    0, 0x1010,    0,    1,    0,   10 },  /* 364: DASH TOBINOKI */
    {  235,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 365: DASH TOBINOKI */
    {  236,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 366: DASH TOBINOKI */
    {  237,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 367: DASH TOBINOKI */
    {  238,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 368: DASH TOBINOKI */
    {  239,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 369: DASH HUMIKOMI, DASH TOBINOKI */
    {  240,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 370: KAMAE */
    {  241,    0,    0, 0x1010,    0,    1,    0,   10 },  /* 371: KAGAMU */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 372: LOSE SONABA, SHIMEOTASARE */
    {  242,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 373: KAGAMI K A */
    {  242,    0,   30, 0x0000,    0,   18,   17,    2 },  /* 374: KAGAMI K A */
    {  242,    0,   30, 0x0000,    0,   18,    0,    2 },  /* 375: KAGAMI K A */
    {  243,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 376: KAGAMI K A */
    {  244,    0,   32, 0x0000,    0,    2,    0,    2 },  /* 377: KAGAMI K A, follow-up of KAGAMI K A */
    {  244,    0,    1, 0x0000,    0,    2,   57,    2 },  /* 378: KAGAMI K A, follow-up of KAGAMI K A */
    {  244,    0,    3, 0x0000,    0,    2,   57,    2 },  /* 379: KAGAMI K A, follow-up of KAGAMI K A */
    {  244,    0,    3, 0x0000,    0,    2,    0,    2 },  /* 380: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 381: KAGAMI K A */
    {    2,    0,   70, 0x0000,    0,    2,    0,    2 },  /* 382: KAGAMI K A */
    {    2,    0,   71, 0x0000,    0,    2,   58,    2 },  /* 383: KAGAMI K A */
    {    2,    0,   72, 0x0000,    0,    2,    0,    2 },  /* 384: KAGAMI K A */
    {  244,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 385: not used by a script */
    {  244,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 386: KAGAMI K A, follow-up of KAGAMI K A */
    {  244,    0,    1, 0x0000,    0,    2,    0,    2 },  /* 387: KAGAMI K A, follow-up of KAGAMI K A */
};

const BODY_BOX yang_body_box[245] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -10,  23,  70,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +113 */
    { { {  -13,  24,  43,  20 },  {  -24,  52,  36,  18 },  {  -29,  56,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +37 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +7 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 4: TUKAMIHAZUSI, TUKAMIHAZUSARE, no name +10 */
    { { {    6,  22,  74,  14 },  {   -8,  44,  60,  14 },  {   -2,  38,  36,  22 },  {  -26,  54,   0,  34 } } },  /* 5: not used by a script */
    { { {   -4,  18,  74,  14 },  {  -18,  46,  62,  14 },  {   -6,  36,  36,  26 },  {  -28,  56,   0,  34 } } },  /* 6: not used by a script */
    { { {   -4,  18,  46,  14 },  {    0,   0,   0,   0 },  {  -20,  48,  34,  18 },  {  -26,  54,   0,  32 } } },  /* 7: not used by a script */
    { { {  -18,  18,  68,  14 },  {  -30,  48,  58,  14 },  {  -24,  42,  36,  22 },  {  -24,  40,  14,  20 } } },  /* 8: not used by a script */
    { { {    0,  25,  79,  20 },  {  -16,  53,  67,  16 },  {  -32,  63,  21,  47 },  {  -21,  48,   0,  34 } } },  /* 9: not used by a script */
    { { {   18,  26,  68,  21 },  {  -11,  53,  57,  24 },  {  -36,  69,  44,  22 },  {  -20,  49,   0,  56 } } },  /* 10: not used by a script */
    { { {   13,  40,  70,  16 },  {   -2,  44,  60,  16 },  {  -46,  53,  40,  50 },  {  -40,  65,   0,  56 } } },  /* 11: M KICK A, no name, follow-up of S KICK A */
    { { {   16,  29,  70,  19 },  {  -19,  63,  65,  16 },  {  -64, 104,  42,  24 },  {  -32,  61,   0,  36 } } },  /* 12: M KICK A, follow-up of S KICK A, no name */
    { { {    6,  28,  70,  21 },  {  -35,  72,  58,  16 },  {  -58,  94,  27,  31 },  {  -32,  58,   0,  34 } } },  /* 13: M KICK A, follow-up of S KICK A, no name */
    { { {    5,  27,  74,  21 },  {  -17,  60,  64,  16 },  {  -31,  76,  38,  28 },  {  -32,  61,   0,  36 } } },  /* 14: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    { { {  -10,  16,  74,  14 },  {  -26,  46,  62,  14 },  {  -16,  34,  34,  26 },  {  -38,  60,   0,  32 } } },  /* 15: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 16: no name */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 17: not used by a script */
    { { {   -6,  16,  70,  14 },  {  -20,  46,  58,  12 },  {  -20,  46,  36,  22 },  {  -22,  50,   0,  34 } } },  /* 18: not used by a script */
    { { {   -6,  16,  70,  14 },  {  -20,  46,  58,  12 },  {  -20,  46,  36,  22 },  {  -22,  50,   0,  34 } } },  /* 19: not used by a script */
    { { {  -20,  16,  60,  14 },  {  -22,  40,  54,  14 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 20: not used by a script */
    { { {  -26,  16,  64,  14 },  {  -34,  46,  56,  12 },  {  -24,  30,  36,  22 },  {  -40,  74,   0,  34 } } },  /* 21: not used by a script */
    { { {  -20,  16,  68,  14 },  {  -28,  46,  58,  12 },  {  -22,  30,  36,  22 },  {  -40,  66,   0,  34 } } },  /* 22: not used by a script */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 23: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 24: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -23,  37,  69,  16 },  {  -37,  66,  54,  18 },  {  -37,  64,  34,  22 },  {  -57,  87,   0,  32 } } },  /* 25: M PUNCH B, no name */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 26: M PUNCH B, no name */
    { { {  -18,  20,  70,  16 },  {  -31,  54,  54,  18 },  {  -26,  44,  34,  22 },  {  -42,  66,   0,  32 } } },  /* 27: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -18,  21,  70,  18 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -55,  98,   0,  32 } } },  /* 28: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -24,  16,  66,  14 },  {  -30,  60,  58,  10 },  {  -37,  66,  34,  22 },  {  -52,  87,   0,  32 } } },  /* 29: M PUNCH B, no name */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 30: M PUNCH B, no name */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 31: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 32: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 33: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -30,  26,  68,  21 },  {  -60,  88,  62,  17 },  {  -42,  69,  34,  35 },  {  -34,  58,   0,  32 } } },  /* 34: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 35: follow-up of M PUNCH A, M PUNCH B */
    { { {  -32,  30,  64,  20 },  {  -38,  67,  59,  12 },  {  -40,  65,  36,  22 },  {  -56,  95,   0,  34 } } },  /* 36: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -23,  28,  66,  21 },  {  -61,  89,  56,  14 },  {  -36,  57,  36,  20 },  {  -55,  88,   0,  34 } } },  /* 37: L PUNCH B, follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 38: L PUNCH B */
    { { {  -26,  16,  64,  14 },  {  -38,  56,  56,  12 },  {  -24,  36,  36,  20 },  {  -38,  68,   0,  34 } } },  /* 39: L PUNCH B */
    { { {  -14,  16,  78,  14 },  {  -28,  46,  68,  12 },  {  -16,  30,  38,  28 },  {  -30,  54,   0,  36 } } },  /* 40: S KICK A, follow-up of ZANNEN 7 */
    { { {  -12,  23,  79,  19 },  {  -30,  54,  68,  16 },  {  -40,  72,  40,  30 },  {  -37,  61,   0,  41 } } },  /* 41: S KICK A, follow-up of ZANNEN 7 */
    { { {  -20,  36,  86,  19 },  {  -51,  86,  76,  12 },  {  -43,  60,  23,  54 },  {    0,   0,   0,   0 } } },  /* 42: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  87,  19 },  {  -48,  89,  78,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 43: M KICK C, follow-up of JUDGMENT WAIT, no name */
    { { {  -17,  26,  81,  19 },  {  -48,  80,  73,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 44: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  76,  19 },  {  -48,  94,  67,  12 },  {  -37,  66,  44,  25 },  {  -36,  60,   0,  42 } } },  /* 45: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {  -30,  34,  47,  20 },  {  -41,  69,  36,  16 },  {    0,   0,   0,   0 },  {  -39,  78,   0,  36 } } },  /* 46: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    { { {  -33,  49,  48,  20 },  {  -41,  69,  40,  16 },  {    0,   0,   0,   0 },  {  -46,  79,   0,  40 } } },  /* 47: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -26,  34,  55,  20 },  {  -55,  81,  36,  30 },  {    0,   0,   0,   0 },  {  -52,  83,   0,  36 } } },  /* 48: not used by a script */
    { { {  -26,  41,  55,  20 },  {  -54,  89,  36,  20 },  {    0,   0,   0,   0 },  {  -55,  89,   0,  36 } } },  /* 49: not used by a script */
    { { {  -28,  16,  68,  14 },  {  -32,  46,  58,  14 },  {  -22,  34,  34,  26 },  {  -36,  64,   0,  32 } } },  /* 50: not used by a script */
    { { {    2,  16,  80,  14 },  {  -16,  44,  70,  14 },  {  -38,  64,  54,  16 },  {  -26,  50,  34,  18 } } },  /* 51: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    { { {  -12,  16,  82,  14 },  {  -22,  44,  72,  14 },  {  -12,  30,  46,  24 },  {  -26,  42,   8,  36 } } },  /* 52: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +4 */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 53: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 54: not used by a script */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 55: not used by a script */
    { { {   -3,  32,  52,  21 },  {  -36,  78,  39,  18 },  {  -43,  90,   0,  41 },  {    0,   0,   0,   0 } } },  /* 56: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {   -4,  24,  56,  14 },  {  -34,  71,  40,  18 },  {  -55,  99,   0,  41 },  {    0,   0,   0,   0 } } },  /* 57: follow-up of WIN 7 */
    { { {  -12,  35,  56,  15 },  {  -42,  69,  33,  26 },  {  -52,  87,   0,  34 },  {  -48,  80,   0,  18 } } },  /* 58: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 59: not used by a script */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 60: not used by a script */
    { { {    2,  16,  72,  14 },  {  -16,  44,  62,  14 },  {  -38,  64,  46,  16 },  {  -26,  50,  26,  18 } } },  /* 61: not used by a script */
    { { {   -4,  16,  68,  14 },  {  -16,  44,  56,  14 },  {  -24,  52,  38,  16 },  {  -32,  50,   8,  28 } } },  /* 62: not used by a script */
    { { {  -16,  36,  20,  10 },  {    0,   0,   0,   0 },  {  -18,  40,   0,  18 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  14 },  {  -12,  32,  62,  22 },  {  -30,  46,  46,  26 } } },  /* 64: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -26,  16,  96,  14 },  {  -34,  46,  84,  14 },  {  -12,  40,  60,  22 },  {  -24,  46,  40,  22 } } },  /* 65: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -34,  16,  96,  14 },  {  -40,  52,  86,  14 },  {  -20,  56,  62,  22 },  {  -16,  32,  28,  32 } } },  /* 66: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  18 },  {  -12,  32,  62,  22 },  {  -36,  46,  46,  26 } } },  /* 67: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -20,  16,  96,  14 },  {  -28,  42,  86,  18 },  {  -28,  46,  68,  16 },  {  -20,  36,  32,  36 } } },  /* 68: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {    6,  22,  74,  14 },  {    1,  34,  60,  14 },  {   -2,  38,  36,  22 },  {  -26,  54,   0,  34 } } },  /* 69: not used by a script */
    { { {   -4,  18,  74,  14 },  {  -18,  46,  62,  14 },  {    2,  22,  36,  26 },  {  -21,  49,   0,  34 } } },  /* 70: not used by a script */
    { { {   -4,  18,  47,  14 },  {    0,   0,   0,   0 },  {  -20,  48,  35,  14 },  {  -20,  50,   0,  30 } } },  /* 71: not used by a script */
    { { {  -11,  16,  61,  14 },  {  -15,  39,  49,  14 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 72: not used by a script */
    { { {  -31,  26,  76,  14 },  {  -32,  57,  65,  14 },  {  -32,  57,  42,  22 },  {  -37,  88,   0,  42 } } },  /* 73: DASH HUMIKOMI */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -23,  35,   0,  47 },  {    0,   0,   0,   0 } } },  /* 74: not used by a script */
    { { {    1,  16,  77,  14 },  {  -11,  46,  62,  14 },  {   -1,  34,  36,  22 },  {  -17,  54,   0,  34 } } },  /* 75: not used by a script */
    { { {   13,  16,  83,  14 },  {    5,  35,  65,  16 },  {   11,  28,  36,  29 },  {   -4,  42,   0,  34 } } },  /* 76: not used by a script */
    { { {   13,  16,  98,  14 },  {    5,  35,  82,  16 },  {    2,  28,  44,  36 },  {  -17,  40,  69,  25 } } },  /* 77: not used by a script */
    { { {   13,  16,  98,  14 },  {    5,  35,  82,  16 },  {    2,  28,  44,  36 },  {    0,   0,   0,   0 } } },  /* 78: not used by a script */
    { { {   -8,  29,  79,  15 },  {  -24,  45,  66,  12 },  {  -32,  63,  34,  31 },  {  -25,  65,   0,  34 } } },  /* 79: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -12,  28,  79,  22 },  {  -28,  53,  71,  12 },  {  -32,  63,  34,  36 },  {  -21,  57,   0,  34 } } },  /* 80: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -19,  32,  82,  18 },  {  -29,  72,  74,  13 },  {  -28,  60,  27,  49 },  {    0,   0,   0,   0 } } },  /* 81: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -16,  29,  87,  19 },  {  -38,  93,  77,  15 },  {  -48,  74,  24,  52 },  {    0,   0,   0,   0 } } },  /* 82: M KICK C, follow-up of JUDGMENT WAIT */
    { { {   -4,  16,  85,  14 },  {  -20,  31,  66,  19 },  {  -11,  36,  28,  37 },  {    0,   0,   0,   0 } } },  /* 83: not used by a script */
    { { {   -4,  16,  85,  14 },  {  -20,  31,  66,  19 },  {  -11,  36,  28,  37 },  {  -42,  35,  55,  17 } } },  /* 84: not used by a script */
    { { {  -20,  16,  64,  14 },  {  -28,  46,  56,  12 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 85: ATTACK 12 M: not started by a command */
    { { {  -24,  16,  58,  14 },  {  -28,  46,  50,  12 },  {  -12,  34,  32,  22 },  {  -18,  50,   0,  32 } } },  /* 86: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -32,  57,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 87: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -16,  34,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 88: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  68,  14 },  {  -28,  46,  58,  14 },  {  -16,  34,  36,  22 },  {  -71, 124,   5,  30 } } },  /* 89: ATTACK 12 M: not started by a command */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 90: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    { { {  -11,  23,  81,  18 },  {  -20,  46,  71,  15 },  {  -37,  58,  32,  39 },  {    0,   0,   0,   0 } } },  /* 91: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    { { {    6,  16,  86,  14 },  {  -10,  42,  72,  14 },  {  -22,  42,  46,  20 },  {   -8,  28,  16,  36 } } },  /* 92: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 93: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 94: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -10,  16,  84,  14 },  {  -20,  40,  74,  12 },  {  -10,  30,  50,  22 },  {  -22,  32,  18,  34 } } },  /* 95: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -28,  16,  46,  14 },  {  -12,  36,  48,  12 },  {    0,   0,   0,   0 },  {  -18,  54,   0,  32 } } },  /* 96: ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI), ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) +2 */
    { { {  -30,  53,  48,  12 },  {    0,   0,   0,   0 },  {  -50,  72,   0,  47 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 11 L: not started by a command, ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI) +4 */
    { { {  -26,  50,  36,  10 },  {    0,   0,   0,   0 },  {  -43,  73,  13,  35 },  {   14,  18,   0,  16 } } },  /* 98: ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -26,  26,  48,  22 },  {  -30,  54,  40,  14 },  {  -43,  76,  22,  37 },  {   16,  20,   0,  24 } } },  /* 99: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    { { {  -44,  37,  36,  73 },  {  -32,  58,  52,  14 },  {  -36,  70,  34,  16 },  {   10,  16,   0,  36 } } },  /* 100: ATTACK 3 S: 236+K light (routine Att_TENSHINSENKYUUTAI), ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI) +5 */
    { { {  -20,  16,  96,  14 },  {  -26,  42,  88,  14 },  {  -12,  30,  74,  16 },  {  -26,  44,  52,  20 } } },  /* 101: V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -24,  16,  96,  14 },  {  -34,  46,  88,  14 },  {  -16,  48,  72,  14 },  {  -25,  54,  44,  34 } } },  /* 102: F JUMP P S A, follow-up of SEAN BALL HIT, V JUMP P S A +1 */
    { { {  -20,  16,  96,  14 },  {  -26,  42,  86,  14 },  {  -10,  28,  72,  16 },  {  -30,  48,  54,  20 } } },  /* 103: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -26,  16,  92,  14 },  {  -20,  36,  84,  14 },  {   -8,  28,  72,  16 },  {  -28,  56,  56,  20 } } },  /* 104: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    { { {  -26,  36,  90,  14 },  {  -34,  48,  76,  12 },  {  -42,  14,  68,  12 },  {  -24,  62,  56,  20 } } },  /* 105: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +3 */
    { { {  -22,  16,  92,  14 },  {  -20,  36,  86,  14 },  {  -12,  30,  72,  16 },  {  -28,  56,  56,  20 } } },  /* 106: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -10,  16,  86,  14 },  {   -4,  28,  64,  28 },  {  -20,  44,  38,  24 },  {   -4,  28,   0,  36 } } },  /* 107: follow-up of HANASARE, APPEAR JUNBI 2, follow-up of SP APPEAR 2, follow-up of APPEAR JUNBI 5 +7 */
    { { {  -33,  16,  96,  14 },  {  -20,  40,  90,  14 },  {   -4,  28,  72,  20 },  {  -20,  42,  54,  20 } } },  /* 108: not used by a script */
    { { {  -33,  16,  96,  14 },  {  -20,  40,  90,  14 },  {   -4,  28,  72,  20 },  {  -20,  42,  54,  20 } } },  /* 109: not used by a script */
    { { {  -18,  16,  74,  14 },  {  -26,  44,  68,  12 },  {   -6,  28,  38,  28 },  {  -26,  32,  16,  26 } } },  /* 110: not used by a script */
    { { {  -10,  16,  76,  14 },  {  -26,  44,  68,  12 },  {  -10,  30,  44,  22 },  {  -26,  34,  30,  26 } } },  /* 111: not used by a script */
    { { {    2,  16,  78,  14 },  {  -12,  42,  72,  12 },  {  -28,  44,  50,  20 },  {  -12,  28,  16,  32 } } },  /* 112: not used by a script */
    { { {   12,  16,  78,  14 },  {   -4,  36,  62,  22 },  {  -30,  46,  52,  20 },  {  -10,  28,  16,  34 } } },  /* 113: not used by a script */
    { { {   -2,  16,  80,  14 },  {  -12,  38,  62,  22 },  {  -30,  48,  52,  20 },  {   -8,  28,   0,  50 } } },  /* 114: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {   -8,  16,  74,  14 },  {  -20,  46,  58,  18 },  {  -22,  44,  24,  32 },  {   -6,  28,   0,  22 } } },  /* 115: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    { { {   -2,  16,  96,  14 },  {  -18,  44,  86,  14 },  {   -8,  30,  66,  22 },  {  -26,  38,  48,  26 } } },  /* 116: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    { { {    8,  16,  94,  14 },  {   -8,  42,  86,  14 },  {  -24,  44,  68,  20 },  {   -8,  28,  36,  30 } } },  /* 117: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    { { {    9,  25,  94,  20 },  {  -50,  89,  90,  16 },  {  -18,  61,  70,  20 },  {  -32,  61,  42,  27 } } },  /* 118: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    { { {  -12,  16,  98,  14 },  {  -10,  30,  86,  16 },  {   -4,  28,  68,  20 },  {  -24,  36,  48,  28 } } },  /* 119: F JUMP K S B, F JUMP K M B, F JUMP K L B +3 */
    { { {  -10,  16,  98,  14 },  {   -4,  30,  90,  16 },  {  -20,  42,  62,  26 },  {  -16,  28,  38,  22 } } },  /* 120: F JUMP K S B, F JUMP K M B, F JUMP K L B +3 */
    { { {  -10,  44,  98,  19 },  {  -15,  54,  92,   8 },  {  -20,  58,  62,  31 },  {    0,   0,   0,   0 } } },  /* 121: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +3 */
    { { {  -10,  16,  78,  14 },  {   -6,  32,  60,  24 },  {  -30,  52,  32,  26 },  {  -16,  26,   0,  32 } } },  /* 122: follow-up of SP APPEAR 4 */
    { { {  -18,  16,  84,  14 },  {  -24,  46,  70,  16 },  {  -10,  32,  32,  36 },  {  -20,  24,   0,  44 } } },  /* 123: follow-up of APPEAR 4 */
    { { {   -6,  16,  92,  14 },  {  -12,  32,  78,  18 },  {  -36,  54,  56,  20 },  {   -6,  24,   0,  54 } } },  /* 124: follow-up of APPEAR 5 */
    { { {   -6,  16,  84,  14 },  {  -12,  30,  60,  28 },  {  -38,  54,  30,  28 },  {   -4,  24,   0,  28 } } },  /* 125: follow-up of APPEAR 5 */
    { { {  -28,  34,  74,  16 },  {  -31,  52,  59,  19 },  {  -22,  51,  34,  25 },  {  -30,  76,   0,  34 } } },  /* 126: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command, TUKAMIKAKARI A +1 */
    { { {  -19,  31,  72,  16 },  {  -24,  46,  52,  22 },  {  -21,  41,  34,  22 },  {  -30,  54,   0,  34 } } },  /* 127: TUKAMIKAKARI A, TUKAMIKAKARI B, ATTACK 9 S: 6(123)4+K (plain script) +1 */
    { { {    0,   0,   0,   0 },  {  -16,  45,  65,  15 },  {  -17,  47,  46,  18 },  {  -17,  46,  28,  17 } } },  /* 128: BODY SLAM, IPPONZEOI, TOMOE RYU +5 */
    { { {  -68,  30,  70,  16 },  {  -82,  73,  52,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 129: not used by a script */
    { { {  -86,  36,  59,  20 },  {  -95,  73,  42,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 130: not used by a script */
    { { {  -80,  44,  63,  17 },  {  -95,  81,  39,  29 },  {  -82,  84,  34,  26 },  {  -69,  95,   0,  34 } } },  /* 131: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    { { {  -49,  81,   0,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: ATTACK 3 M: 236+K medium (routine Att_TENSHINSENKYUUTAI), ATTACK 3 L: 236+K heavy (routine Att_TENSHINSENKYUUTAI), ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) +2 */
    { { {  -64,  98,  73,  22 },  {  -63,  98,  70,   7 },  {  -67, 101,  34,  35 },  {  -48,  82,   0,  32 } } },  /* 133: follow-up of follow-up of S KICK A, no name */
    { { {  -10,  39,  71,  21 },  {  -28,  69,  70,   7 },  {  -67, 110,  34,  35 },  {  -31,  74,   0,  32 } } },  /* 134: follow-up of follow-up of S KICK A, no name */
    { { {   -9,  26,  85,  22 },  {  -25,  48,  54,  35 },  {  -54,  74,  30,  43 },  {    0,   0,   0,   0 } } },  /* 135: not used by a script */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -15,  38,  34,  35 },  {  -16,  41,   0,  32 } } },  /* 136: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 2 SP: EX 214+PP (plain script), not started by a command */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -62,  93,  47,  57 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 12 L: not started by a command, not started by a command */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 138: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command, follow-up of follow-up of M PUNCH A, M PUNCH B */
    { { {  -28,  16,  96,  14 },  {  -34,  58,  86,  18 },  {  -73,  83,  61,  25 },  {  -26,  38,  48,  26 } } },  /* 139: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {   -4,  16,  98,  14 },  {  -23,  49,  88,  14 },  {  -13,  35,  66,  22 },  {  -30,  44,  47,  27 } } },  /* 140: not used by a script */
    { { {    6,  16,  96,  14 },  {  -26,  57,  86,  16 },  {  -39,  64,  66,  20 },  {  -10,  30,  37,  29 } } },  /* 141: not used by a script */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 142: not used by a script */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 143: not used by a script */
    { { {  -32,  22,  49,  21 },  {  -29,  53,  59,   7 },  {  -29,  53,  32,  27 },  {  -34,  87,   0,  32 } } },  /* 144: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +4 */
    { { {  -49,  22,  62,  21 },  {  -61,  77,  60,  12 },  {  -51,  71,  32,  27 },  {  -63, 104,   0,  32 } } },  /* 145: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -50,  22,  55,  21 },  {  -67,  88,  56,   8 },  {  -65,  84,  23,  31 },  {  -75,  94,   0,  32 } } },  /* 146: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +4 */
    { { {  -42,  24,  70,  17 },  {  -53,  47,  61,  10 },  {  -52,  47,  33,  26 },  {  -56,  75,   0,  33 } } },  /* 147: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -44,  37,  44,  34 },  {  -32,  58,  52,  14 },  {  -36,  70,  34,  16 },  {   10,  16,   0,  36 } } },  /* 148: ATTACK 3 SP: EX 236+KK (routine Att_TENSHINSENKYUUTAI) */
    { { {    6,  23,  74,  18 },  {  -19,  51,  60,  14 },  {  -22,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 149: UPPER L, BODY UPPER L */
    { { {   14,  23,  73,  18 },  {  -16,  51,  60,  14 },  {  -23,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 150: UPPER L, BODY UPPER L */
    { { {   18,  23,  72,  18 },  {  -14,  51,  60,  14 },  {  -24,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 151: UPPER L, BODY UPPER L */
    { { {   20,  23,  71,  18 },  {  -13,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 152: UPPER L, BODY UPPER L */
    { { {    6,  23,  68,  18 },  {  -15,  51,  59,  14 },  {  -17,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 153: FACE S, FACE M, FACE L +5 */
    { { {   18,  23,  66,  18 },  {   -9,  51,  58,  14 },  {  -14,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 154: FACE M, FACE L, FOOK OKU L +3 */
    { { {   26,  23,  64,  18 },  {   -5,  51,  57,  14 },  {  -12,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 155: not used by a script */
    { { {   30,  23,  62,  18 },  {   -3,  51,  56,  14 },  {  -11,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 156: not used by a script */
    { { {  -14,  23,  67,  18 },  {  -21,  51,  58,  14 },  {  -19,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 157: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -18,  23,  64,  18 },  {  -19,  51,  56,  14 },  {  -17,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 158: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    { { {  -22,  23,  61,  18 },  {  -17,  51,  54,  14 },  {  -15,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 159: NOUTEN M, NOUTEN L, BODY BROW L */
    { { {  -26,  23,  58,  18 },  {  -15,  51,  52,  14 },  {  -13,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 160: NOUTEN L, BODY BROW L, TATAKI S */
    { { {   -7,  24,  43,  20 },  {  -22,  52,  36,  18 },  {  -28,  56,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 161: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {   -1,  24,  43,  20 },  {  -20,  52,  36,  18 },  {  -27,  56,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 162: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    { { {    5,  24,  43,  20 },  {  -18,  52,  36,  18 },  {  -26,  56,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 163: KAGAMI M, KAGAMI L */
    { { {   11,  24,  43,  20 },  {  -16,  52,  36,  18 },  {  -25,  56,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 164: KAGAMI L */
    { { {  -25,  23,  79,  18 },  {  -37,  51,  65,  14 },  {  -30,  42,  33,  31 },  {  -34,  58,   0,  32 } } },  /* 165: M KICK B */
    { { {  -26,  19,  78,  16 },  {  -24,  35,  68,  11 },  {  -26,  34,  38,  30 },  {  -37,  41,  -3,  41 } } },  /* 166: M KICK B */
    { { {  -17,  27,  77,   9 },  {  -32,  48,  62,  16 },  {  -39,  52,  35,  28 },  {  -32,  39,   0,  36 } } },  /* 167: M KICK B */
    { { {   -2,  19,  73,  14 },  {  -10,  44,  67,   7 },  {  -32,  68,  36,  31 },  {  -33,  31,   0,  36 } } },  /* 168: L KICK A */
    { { {    0,   0,   0,   0 },  {  -14,  41,  67,  16 },  {  -19,  47,  46,  18 },  {  -25,  49,  27,  19 } } },  /* 169: AIR NORMAL, UPPER, BODY UPPER +5 */
    { { {    0,   0,   0,   0 },  {   13,  44,  59,  15 },  {   -1,  55,  41,  18 },  {  -18,  59,  26,  18 } } },  /* 170: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   23,  42,  56,  16 },  {    3,  53,  42,  19 },  {  -15,  58,  32,  23 } } },  /* 171: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   36,  33,  34,  25 },  {   18,  34,  40,  25 },  {   -7,  39,  32,  27 } } },  /* 172: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   32,  33,   5,  25 },  {   18,  34,   0,  25 },  {   -4,  39,   0,  40 } } },  /* 173: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {  -40,  36,  56,  15 },  {  -39,  35,  38,  18 },  {  -30,  50,  19,  19 } } },  /* 174: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -40,  36,  51,  15 },  {  -28,  32,  34,  18 },  {  -17,  50,  19,  18 } } },  /* 175: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -37,  34,  47,  18 },  {  -19,  32,  34,  19 },  {   -8,  44,  19,  19 } } },  /* 176: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -38,  34,  21,  22 },  {  -26,  33,  27,  25 },  {   -5,  35,  19,  26 } } },  /* 177: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {   13,  26,  68,  21 },  {   -9,  26,  62,  22 },  {  -28,  40,  37,  33 } } },  /* 178: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {    0,   0,   0,   0 },  {   17,  26,  63,  21 },  {   -2,  26,  59,  22 },  {  -32,  39,  41,  31 } } },  /* 179: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   21,  26,  54,  21 },  {   -1,  26,  50,  25 },  {  -32,  38,  38,  33 } } },  /* 180: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   24,  24,  42,  25 },  {    2,  24,  41,  29 },  {  -29,  30,  37,  34 } } },  /* 181: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   24,  26,  37,  22 },  {    4,  26,  39,  29 },  {  -27,  31,  43,  31 } } },  /* 182: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   20,  26,  28,  25 },  {    2,  30,  36,  29 },  {  -25,  30,  44,  31 } } },  /* 183: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   17,  31,  22,  22 },  {    2,  31,  36,  26 },  {  -21,  32,  47,  32 } } },  /* 184: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   16,  37,  14,  25 },  {    3,  36,  30,  27 },  {  -15,  38,  44,  29 } } },  /* 185: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {  -14,  45,  51,  21 },  {    3,  36,  38,  20 },  {  -19,  46,  22,  20 } } },  /* 186: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -7,  45,  49,  23 },  {   19,  29,  35,  29 },  {  -19,  52,  27,  22 } } },  /* 187: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -7,  45,  45,  23 },  {   19,  29,  32,  29 },  {  -19,  52,  22,  22 } } },  /* 188: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -5,  45,  32,  23 },  {   13,  29,  16,  26 },  {  -24,  45,  11,  24 } } },  /* 189: KUNOJI, TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {   -8,  38,  60,  15 },  {  -16,  41,  42,  18 },  {  -29,  50,  22,  20 } } },  /* 190: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -4,  39,  62,  17 },  {  -15,  40,  47,  18 },  {  -32,  48,  28,  20 } } },  /* 191: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -4,  39,  62,  17 },  {  -13,  40,  47,  18 },  {  -28,  45,  28,  20 } } },  /* 192: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -2,  39,  63,  17 },  {  -12,  40,  47,  18 },  {  -25,  45,  28,  20 } } },  /* 193: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    0,  39,  62,  17 },  {  -12,  40,  46,  18 },  {  -24,  45,  27,  20 } } },  /* 194: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    1,  42,  57,  20 },  {  -11,  41,  43,  20 },  {  -25,  45,  27,  21 } } },  /* 195: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    5,  42,  53,  21 },  {   -9,  41,  40,  22 },  {  -28,  43,  25,  26 } } },  /* 196: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   14,  33,  44,  21 },  {   -2,  32,  34,  22 },  {  -26,  40,  23,  26 } } },  /* 197: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  29,  31 },  {    0,  26,  28,  27 },  {  -29,  40,  19,  30 } } },  /* 198: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  22,  31 },  {   -1,  26,  25,  27 },  {  -31,  35,  18,  30 } } },  /* 199: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  16,  28 },  {   -2,  26,  15,  27 },  {  -31,  33,  11,  31 } } },  /* 200: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,   4,  21 },  {   -3,  26,   4,  21 },  {  -32,  30,   5,  25 } } },  /* 201: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -5,  36,  75,  18 },  {  -19,  38,  59,  19 },  {  -31,  47,  34,  25 } } },  /* 202: UPPER, BODY UPPER, ALEX B.D +1 */
    { { {    0,   0,   0,   0 },  {   13,  26,  68,  21 },  {   -9,  26,  62,  22 },  {  -28,  40,  37,  33 } } },  /* 203: UPPER, BODY UPPER, ALEX B.D +1 */
    { { {    0,   0,   0,   0 },  {  -12,  39,  54,  17 },  {  -20,  46,  36,  18 },  {  -32,  54,  18,  19 } } },  /* 204: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  39,  34,  21 },  {   11,  22,  21,  30 },  {  -29,  49,  14,  21 } } },  /* 205: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  39,  18,  21 },  {   11,  22,   0,  30 },  {  -29,  40,   0,  28 } } },  /* 206: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  40,  77,  16 },  {  -18,  32,  58,  21 },  {  -21,  42,  32,  26 } } },  /* 207: DENKI */
    { { {    0,   0,   0,   0 },  {   -4,  46,  49,  20 },  {  -21,  51,  37,  15 },  {  -36,  57,  22,  18 } } },  /* 208: TOUKETSU A */
    { { {    0,   0,   0,   0 },  {  -16,  37,  13,  21 },  {  -17,  42,  34,  21 },  {  -17,  41,  55,  20 } } },  /* 209: BODY UPPER SP */
    { { {  -10,  23,  73,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -28,  64,   0,  32 } } },  /* 210: FRONT WALK */
    { { {  -10,  23,  75,  18 },  {  -23,  51,  60,  17 },  {  -21,  47,  33,  26 },  {  -21,  48,   0,  32 } } },  /* 211: FRONT WALK */
    { { {   -6,  23,  73,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -28,  64,   0,  32 } } },  /* 212: BACK WALK */
    { { {   -6,  23,  75,  18 },  {  -23,  51,  60,  17 },  {  -21,  47,  33,  26 },  {  -21,  48,   0,  32 } } },  /* 213: BACK WALK */
    { { {  -12,  23,  70,  18 },  {  -27,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -23,  58,   0,  32 } } },  /* 214: HURIMUKI */
    { { {  -12,  23,  70,  18 },  {  -25,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -26,  54,   0,  32 } } },  /* 215: HURIMUKI */
    { { {  -12,  24,  43,  20 },  {  -30,  52,  36,  18 },  {  -28,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 216: KAGAMI TURN */
    { { {  -12,  23,  58,  18 },  {  -23,  51,  45,  16 },  {  -21,  47,  23,  21 },  {  -34,  58,   0,  22 } } },  /* 217: STAND UP, DASH HUMIKOMI, DASH TOBINOKI +1 */
    { { {  -28,  23,  56,  18 },  {  -25,  46,  50,  20 },  {  -28,  52,  29,  20 },  {  -34,  58,   0,  28 } } },  /* 218: ATTACK 12 L: not started by a command, SP JUMP JUNBI */
    { { {  -17,  19,  96,  20 },  {  -29,  50,  92,  14 },  {  -20,  44,  77,  14 },  {  -30,  54,  46,  30 } } },  /* 219: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -18,  19,  92,  20 },  {  -21,  50,  89,  14 },  {  -16,  44,  77,  11 },  {  -30,  58,  40,  36 } } },  /* 220: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -16,  23,  69,  18 },  {  -22,  47,  56,  18 },  {  -26,  52,  30,  26 },  {  -39,  65,   0,  29 } } },  /* 221: PIYO */
    { { {  -10,  23,  65,  18 },  {  -22,  54,  54,  18 },  {  -22,  52,  26,  26 },  {  -35,  68,   0,  25 } } },  /* 222: PIYO */
    { { {  -12,  23,  72,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 223: KAMAE */
    { { {  -17,  23,  67,  18 },  {  -27,  51,  60,  14 },  {  -25,  46,  29,  30 },  {  -42,  66,   0,  28 } } },  /* 224: KAMAE */
    { { {  -12,  23,  73,  18 },  {  -26,  51,  63,  14 },  {  -23,  47,  33,  29 },  {  -34,  58,   0,  32 } } },  /* 225: KAMAE */
    { { {  -16,  23,  65,  18 },  {  -23,  51,  56,  14 },  {  -25,  51,  29,  26 },  {  -38,  64,   0,  28 } } },  /* 226: DASH HUMIKOMI */
    { { {  -25,  23,  60,  18 },  {  -23,  44,  50,  14 },  {  -25,  49,  29,  20 },  {  -38,  64,   0,  28 } } },  /* 227: DASH HUMIKOMI */
    { { {  -31,  26,  72,  14 },  {  -32,  57,  65,  14 },  {  -32,  57,  35,  28 },  {  -36,  64,   0,  34 } } },  /* 228: DASH HUMIKOMI */
    { { {  -14,  23,  58,  18 },  {  -21,  46,  50,  12 },  {  -22,  52,  29,  20 },  {  -25,  58,   0,  28 } } },  /* 229: DASH HUMIKOMI */
    { { {  -20,  23,  72,  18 },  {  -27,  48,  60,  14 },  {  -21,  47,  33,  26 },  {  -22,  48,   0,  32 } } },  /* 230: DASH TOBINOKI */
    { { {    7,  23,  65,  18 },  {  -21,  48,  60,  14 },  {  -21,  45,  33,  26 },  {  -36,  57,   0,  32 } } },  /* 231: DASH TOBINOKI */
    { { {   35,  23,  53,  18 },  {  -21,  56,  60,  14 },  {  -44,  78,  41,  18 },  {  -52,  73,   0,  40 } } },  /* 232: DASH TOBINOKI */
    { { {   13,  23,  21,  18 },  {    8,  29,  39,  31 },  {  -58,  64,  41,  28 },  {  -21,  73,   0,  40 } } },  /* 233: DASH TOBINOKI */
    { { {  -15,  23,  11,  18 },  {  -21,  43,  28,  19 },  {  -21,  43,  48,  38 },  {  -21,  43,   0,  27 } } },  /* 234: DASH TOBINOKI */
    { { {  -52,  23,  43,  18 },  {  -33,  53,  27,  42 },  {  -21,  68,  27,  52 },  {  -21,  43,   0,  26 } } },  /* 235: DASH TOBINOKI */
    { { {  -55,  23,  56,  18 },  {  -33,  22,  44,  31 },  {  -21,  47,  27,  47 },  {  -21,  43,   0,  26 } } },  /* 236: DASH TOBINOKI */
    { { {  -40,  23,  69,  18 },  {  -29,  51,  60,  20 },  {  -21,  47,  31,  29 },  {  -21,  56,   0,  30 } } },  /* 237: DASH TOBINOKI */
    { { {  -10,  23,  70,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -22,  49,   0,  32 } } },  /* 238: DASH TOBINOKI */
    { { {  -12,  23,  66,  18 },  {  -23,  51,  58,  14 },  {  -27,  53,  29,  28 },  {  -38,  62,   0,  28 } } },  /* 239: DASH HUMIKOMI, DASH TOBINOKI */
    { { {  -12,  23,  74,  18 },  {  -23,  51,  61,  14 },  {  -21,  47,  35,  24 },  {  -34,  58,   0,  34 } } },  /* 240: KAMAE */
    { { {  -14,  23,  68,  18 },  {  -23,  51,  56,  14 },  {  -21,  47,  29,  26 },  {  -34,  58,   0,  28 } } },  /* 241: KAGAMU */
    { { {   -4,  24,  41,  20 },  {  -24,  52,  34,  18 },  {  -28,  55,  19,  15 },  {  -42,  73,   0,  19 } } },  /* 242: KAGAMI K A */
    { { {   -5,  24,  42,  20 },  {  -24,  52,  36,  18 },  {  -28,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 243: KAGAMI K A */
    { { {  -18,  24,  41,  16 },  {  -35,  52,  36,  11 },  {  -51,  72,  19,  17 },  {  -49,  67,   0,  19 } } },  /* 244: KAGAMI K A, follow-up of KAGAMI K A */
};

const HAND_BOX yang_hand_box[74] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -96,  61,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: follow-up of WIN 5, follow-up of WIN 6, KAGAMI K A +1 */
    { { {  -78,  60,  56,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: M KICK A, no name, follow-up of S KICK A */
    { { { -113,  78,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: follow-up of WIN 5, follow-up of WIN 6, follow-up of follow-up of KAGAMI K A +2 */
    { { {  -70,  52,  34,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: KAGAMI P A, follow-up of WIN 4 */
    { { {  -61,  40,  34,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: KAGAMI P A, follow-up of WIN 4, follow-up of S KICK A */
    { { {  -61,  58,  34,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: KAGAMI P A, follow-up of WIN 4, ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -63,  45,  17,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -86,  39,  39,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -74,  22,  33,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +4 */
    { { {  -89,  52,  48,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 7 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -38,  30,  79,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: not started by a command */
    { { {  -64,  28,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: not used by a script */
    { { {  -58,  28,  62,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {  -80,  66,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -68,  55,  45,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: M PUNCH B, no name */
    { { {  -61,  40,  51,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -63,  53,  44,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: M PUNCH B, no name */
    { { {  -43,  22,  50,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: M PUNCH B, no name */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -70,  54,  43,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 */
    { { {  -66,  24,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH B */
    { { {  -66,  42,   0,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: S KICK A, follow-up of ZANNEN 7 */
    { { {  -80,  62,  53,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: M KICK C, follow-up of JUDGMENT WAIT, no name */
    { { {  -80,  62,  41,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -67,  62,  30,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {  -82,  60,  45,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -73,  38,  23,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A, follow-up of WIN 4 */
    { { {  -86,  58,  23,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI P A, follow-up of WIN 4 */
    { { {  -82,  65,   0,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI K A */
    { { {  -77,  27,   0,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { { {  -73,  34,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: follow-up of follow-up of KAGAMI K A, follow-up of WIN 5, follow-up of WIN 6 +2 */
    { { {  -79,  60,  81,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP P L A, follow-up of JUDGMENT LOSE */
    { { {    0,   0,   6,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -61,  50,  54,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -40,  29,  36,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 12 M: not started by a command */
    { { {  -62,  32,  64,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 12 M: not started by a command */
    { { {  -83,  62,  51,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: follow-up of APPEAR USE, ATTACK 5 S: not started by a command */
    { { {  -46,  24,  68,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 5 S: not started by a command, ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { { {  -46,  26,  61,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: F JUMP P S A, follow-up of SEAN BALL HIT, V JUMP P S A +1 */
    { { {  -58,  36,  56,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +3 */
    { { {  -52,  30,  76,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -36,  17,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: not used by a script */
    { { {  -36,  15,  71,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: not used by a script */
    { { {  -68,  36,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -56,  28,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -46,  22,  24,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: not used by a script */
    { { {  -83,  65,  67,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    { { {  -20,  49,  20,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +3 */
    { { {  -54,  23,  62,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command, TUKAMIKAKARI A +1 */
    { { {  -46,  32,  56,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: TUKAMIKAKARI A, TUKAMIKAKARI B, ATTACK 9 S: 6(123)4+K (plain script) +1 */
    { { {  -85,  21,  43,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: follow-up of follow-up of S KICK A, no name */
    { { {  -84,  73,  44,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: not used by a script */
    { { {  -56,  46,  42,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command, follow-up of follow-up of M PUNCH A, M PUNCH B */
    { { {  -75,  52,  35,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -90,  62,  34,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: not used by a script */
    { { {  -39,  12,  81,  17 },  {   15,   9,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: M KICK B */
    { { {  -59,  20,  71,   9 },  {   15,   9,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: M KICK B */
    { { {  -40,  16,  58,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: M KICK B */
    { { {  -56,  12,  51,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: M KICK B */
    { { {  -77,  51,  61,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: L KICK A */
    { { {  -73,  39,  54,  13 },  { -105,  68,  63,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: L KICK A */
    { { {  -99,  64,  63,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: not used by a script */
    { { {  -93,  34,  68,  19 },  {  -67,  33,  57,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: M KICK B */
    { { {  -58,  17,  16,  30 },  {  -78,  20,  16,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: KAGAMI P A */
    { { {  -58,  17,  16,  30 },  {  -78,  20,   5,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: KAGAMI P A */
    { { {  -58,  17,  16,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: KAGAMI P A */
    { { {  -73,  44,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: KAGAMI K A */
    { { {  -82,  53,   0,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: KAGAMI K A */
    { { {   27,  36,  -2,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: KAGAMI K A */
    { { {  -58,  42,  30,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 12 L: not started by a command, not started by a command */
};

const HOSEI_BOX yang_hos_box[23] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   70 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +124 */
    { {  -21,   42,    0,   48 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +65 */
    { {  -20,   40,   51,   44 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +41 */
    { {  -21,   42,   41,   37 } },  /* 4: M KICK C, follow-up of JUDGMENT WAIT, follow-up of APPEAR USE +2 */
    { {  -32,   46,   36,   36 } },  /* 5: not used by a script */
    { {  -44,   46,   36,   36 } },  /* 6: not used by a script */
    { {  -41,   46,   36,   36 } },  /* 7: not used by a script */
    { {  -21,   60,    0,   54 } },  /* 8: follow-up of follow-up of KAGAMI K A, follow-up of WIN 7 */
    { {  -21,   42,    0,   42 } },  /* 9: ATTACK 6 S: SA II 23623+K (routine Att_TENSHINSENKYUUTAI), ATTACK 13 SP: after SA II 23623+K (routine Att_TENSHINSENKYUUTAI) */
    { {  -21,   42,    0,   62 } },  /* 10: UPPER L, BODY UPPER L, FACE S +18 */
    { {  -10,   46,   36,   36 } },  /* 11: not used by a script */
    { {    6,   36,   43,   36 } },  /* 12: not used by a script */
    { {    0,   36,   62,   36 } },  /* 13: not used by a script */
    { {    0,    0,    0,    0 } },  /* 14: no box */
    { {  -27,   32,   47,   36 } },  /* 15: not used by a script */
    { {   -4,   32,   52,   36 } },  /* 16: not used by a script */
    { {   10,   32,   52,   36 } },  /* 17: not used by a script */
    { {  -15,   38,   36,   45 } },  /* 18: not used by a script */
    { {  -17,   42,   35,   32 } },  /* 19: BODY SLAM, IPPONZEOI, TOMOE RYU +28 */
    { {  -20,   40,   60,   24 } },  /* 20: not used by a script */
    { {  -21,   42,    0,   30 } },  /* 21: no name, NEKOROBI S */
    { {  -28,   49,    0,   54 } },  /* 22: ATTACK 4 S: 236+P light (routine Att_SLIDE_and_JUMP), ATTACK 4 M: 236+P medium (routine Att_SLIDE_and_JUMP), ATTACK 4 L: 236+P heavy (routine Att_SLIDE_and_JUMP) +4 */
};
