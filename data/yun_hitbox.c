/*
 * YUN_HITBOX.C  Yun's hit boxes
 *
 * Each of Yun's animation frames names an entry of yun_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX yun_hit_ix_table[395] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +23 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: no name, HURIMUKI, DASH HUMIKOMI +117 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +32 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +5 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: TUKAMIHAZUSI, TUKAMIHAZUSARE, no name +5 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 5: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: GUARD AIR */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 7: not used by a script */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: GUARD AIR */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: not used by a script */
    {   14,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 10: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    {   10,    0,    0, 0x0000,    0,    1,    1,    1 },  /* 11: not used by a script */
    {   11,    0,    3, 0x0000,    0,    1,    2,    1 },  /* 12: M KICK A, follow-up of APPEAR USE */
    {   11,    0,    3, 0x0000,    0,    1,   48,    1 },  /* 13: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    {   11,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 14: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    {   12,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 15: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    {   15,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 16: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 17: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   17,    0,    5, 0x0000,    0,    1,    3,    1 },  /* 18: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   17,    0,    5, 0x0000,    0,    1,    4,    1 },  /* 19: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   17,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 20: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   18,    0,    0, 0x0000,    0,    0,    0,   21 },  /* 21: no name */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 22: not used by a script */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: not used by a script */
    {   21,    0,    7, 0x0000,    0,    1,   60,    1 },  /* 24: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   21,    0,    7, 0x0000,    0,    1,   61,    1 },  /* 25: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   21,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 26: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   23,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 27: S PUNCH B, follow-up of ZANNEN 3 */
    {   24,    0,    9, 0x0000,    0,    1,    6,    1 },  /* 28: not used by a script */
    {   24,    0,    9, 0x0000,    0,    1,   39,    1 },  /* 29: not used by a script */
    {   25,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 30: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +2 */
    {   26,    0,   10, 0x0000,    0,    1,    7,    1 },  /* 31: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name */
    {   26,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 32: not used by a script */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 33: M PUNCH A, follow-up of ZANNEN 4, not started by a command */
    {   28,    0,   11, 0x0000,    0,    1,    8,    1 },  /* 34: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,    0,   11, 0x0000,    0,    1,   40,    1 },  /* 35: M PUNCH A, follow-up of ZANNEN 4 */
    {   28,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 36: M PUNCH A, follow-up of ZANNEN 4 */
    {   31,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 37: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   31,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 38: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   32,    0,   14, 0x0000,    0,    1,   42,    1 },  /* 39: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,    0,   15, 0x0000,    0,    1,   43,    1 },  /* 40: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   33,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 41: L PUNCH A, follow-up of JUDGMENT WAIT */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: L PUNCH B, follow-up of ZANNEN 6 */
    {   35,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: not used by a script */
    {   36,    0,   16, 0x0000,    0,    1,   10,    1 },  /* 44: L PUNCH B, follow-up of ZANNEN 6 */
    {   36,    0,   16, 0x0000,    0,    1,   44,    1 },  /* 45: L PUNCH B, follow-up of ZANNEN 6 */
    {   36,    0,   16, 0x0000,    0,    1,    0,    1 },  /* 46: L PUNCH B, follow-up of ZANNEN 6 */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: L PUNCH B, follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 +1 */
    {   38,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: follow-up of M PUNCH A, M PUNCH B */
    {   39,    0,   17, 0x0000,    0,    1,   11,    1 },  /* 49: follow-up of M PUNCH A, M PUNCH B */
    {   39,    0,   17, 0x0000,    0,    1,   45,    1 },  /* 50: follow-up of M PUNCH A, M PUNCH B */
    {   39,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 51: follow-up of M PUNCH A, M PUNCH B */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    {   41,    0,   18, 0x0000,    0,    1,   12,    1 },  /* 53: not used by a script */
    {   41,    0,   18, 0x0000,    0,    1,   13,    1 },  /* 54: not used by a script */
    {   41,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 55: not used by a script */
    {   41,    0,   18, 0x0000,    0,    1,   46,    1 },  /* 56: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    {   41,    0,   18, 0x0000,    0,    1,   47,    1 },  /* 57: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    {   24,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 58: not used by a script */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 59: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    {   46,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 60: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {   47,    0,   22, 0x0000,    0,    2,   14,    2 },  /* 61: follow-up of WIN 2 */
    {   47,    0,   22, 0x0000,    0,    2,   19,    2 },  /* 62: follow-up of WIN 2 */
    {   47,    0,   22, 0x0000,    0,    2,    0,    2 },  /* 63: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    {   48,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 64: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    {   48,    0,    0, 0x0000,    0,    2,   56,    2 },  /* 65: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    {   49,    0,   23, 0x0000,    0,    2,    0,    2 },  /* 66: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 67: not used by a script */
    {    2,    0,    2, 0x0000,    0,    2,   57,    2 },  /* 68: not used by a script */
    {    2,    0,    4, 0x0000,    0,    2,   57,    2 },  /* 69: not used by a script */
    {    2,    0,    4, 0x0000,    0,    2,    0,    2 },  /* 70: not used by a script */
    {   56,    0,    0, 0x0000,    0,    2,    0,    8 },  /* 71: not used by a script */
    {   57,    0,    0, 0x0000,    0,    2,    0,    8 },  /* 72: not used by a script */
    {   58,    0,   25, 0x0000,    0,    2,   18,    8 },  /* 73: not used by a script */
    {   58,    0,   25, 0x0000,    0,    2,   58,    8 },  /* 74: not used by a script */
    {   58,    0,   25, 0x0000,    0,    2,    0,    8 },  /* 75: not used by a script */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: not used by a script */
    {   17,    0,    5, 0x0000,    0,    1,    5,    1 },  /* 77: not used by a script */
    {   22,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 78: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {   50,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 79: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {  100,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 80: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    {   53,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 81: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    {   51,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 82: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    {   52,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 83: ATTACK 2 SP: EX 214+PP (plain script) */
    {   61,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 84: not used by a script */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 86: GUARD HEAD */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 87: GUARD UP, P BREAK ZUJOU, TUKAMIHAZUSI +1 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 88: GUARD DOWN, P BREAK DOWN */
    {   72,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 89: not used by a script */
    {   73,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 90: DASH HUMIKOMI */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 91: OKIAGARI, OKIAGARI F, OKIAGARI B +15 */
    {   74,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 92: not used by a script */
    {   47,    0,   22, 0x0000,    0,    2,   54,    2 },  /* 93: KAGAMI P A, follow-up of WIN 3 */
    {   47,    0,   22, 0x0000,    0,    2,   55,    2 },  /* 94: KAGAMI P A, follow-up of WIN 3 */
    {   49,    0,   23, 0x0000,    0,    2,   15,    2 },  /* 95: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    {   49,    0,   23, 0x0000,    0,    2,   16,    2 },  /* 96: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    {  107,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 97: follow-up of HANASARE, APPEAR JUNBI 2, follow-up of SP APPEAR 2, follow-up of APPEAR JUNBI 5 +7 */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 98: M KICK C, follow-up of JUDGMENT WAIT */
    {   80,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 99: M KICK C, follow-up of JUDGMENT WAIT */
    {   81,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 100: M KICK C, follow-up of JUDGMENT WAIT */
    {   82,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 101: M KICK C, follow-up of JUDGMENT WAIT */
    {   42,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 102: M KICK C, follow-up of JUDGMENT WAIT */
    {   43,    0,   19, 0x0000,    0,    1,   20,    1 },  /* 103: M KICK C, follow-up of JUDGMENT WAIT, no name */
    {   83,    0,    0, 0x0000,    0,   17,    0,   18 },  /* 104: not used by a script */
    {   83,    0,    0, 0x0000,    0,   17,   22,   18 },  /* 105: not used by a script */
    {   84,    0,    0, 0x0000,    0,   17,   23,   18 },  /* 106: not used by a script */
    {   84,    0,    0, 0x0000,    0,   17,    0,   18 },  /* 107: not used by a script */
    {   85,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 108: L PUNCH C, follow-up of APPEAR USE, ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) +9 */
    {   86,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 109: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +2 */
    {   87,    0,   30, 0x0000,    0,    1,   24,    1 },  /* 110: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   88,    0,   31, 0x0000,    0,    1,   25,    1 },  /* 111: ATTACK 12 M: not started by a command */
    {   89,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 112: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +2 */
    {   90,    0,    0, 0x0000,    0,    1,   26,    1 },  /* 113: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {   90,    0,    0, 0x0000,    0,    1,   27,    1 },  /* 114: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {  138,    0,   48, 0x0000,    0,    1,   27,    1 },  /* 115: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    {   93,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 116: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +2 */
    {   91,    0,   32, 0x0000,    0,    4,    0,    4 },  /* 117: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +1 */
    {   91,    0,   32, 0x0000,    0,    4,   29,    4 },  /* 118: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +1 */
    {   92,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 119: follow-up of APPEAR USE, HANASARE, ATTACK 5 S: not started by a command +2 */
    {   93,    0,    0, 0x0000,    0,    3,   30,    3 },  /* 120: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   94,    0,   33, 0x0000,    0,    4,   31,    4 },  /* 121: ATTACK 5 S: not started by a command */
    {   94,    0,   33, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    {   95,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 123: ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 13 SP: not started by a command +1 */
    {   96,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 124: ATTACK 2 SP: EX 214+PP (plain script) */
    {   97,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 125: ATTACK 2 SP: EX 214+PP (plain script) */
    {   97,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 126: not used by a script */
    {   97,    0,    0, 0x0000,    0,    2,   32,    2 },  /* 127: ATTACK 2 SP: EX 214+PP (plain script) */
    {   99,    0,    0, 0x0000,    0,    1,   33,    2 },  /* 128: ATTACK 2 SP: EX 214+PP (plain script) */
    {  100,    0,    0, 0x0000,    0,    5,   34,    1 },  /* 129: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    {  100,    0,    0, 0x0000,    0,    5,   64,    1 },  /* 130: ATTACK 2 SP: EX 214+PP (plain script) */
    {  103,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 131: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {  104,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 132: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,    0,   35, 0x0000,    0,    3,   37,    3 },  /* 133: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {  105,    0,   35, 0x0000,    0,    3,   38,    3 },  /* 134: not used by a script */
    {  106,    0,   36, 0x0000,    0,    3,    0,    3 },  /* 135: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    {   29,    0,   12, 0x0000,    0,    1,   41,    1 },  /* 136: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name */
    {   29,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 137: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +3 */
    {   30,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 138: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +1 */
    {  101,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 139: V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {  102,    0,   34, 0x0000,    0,    3,   35,    3 },  /* 140: F JUMP P S A, follow-up of SEAN BALL HIT */
    {  102,    0,   34, 0x0000,    0,    3,   36,    3 },  /* 141: V JUMP P S A, follow-up of JUDGMENT LOSE */
    {  105,    0,   35, 0x0000,    0,    3,   49,    3 },  /* 142: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,    0,   35, 0x0000,    0,    3,   50,    3 },  /* 143: F JUMP P L A, follow-up of BONUS WIN 1 */
    {  105,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 144: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +1 */
    {   44,    0,   20, 0x0000,    0,    1,   21,    1 },  /* 145: M KICK C, follow-up of JUDGMENT WAIT */
    {   45,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 146: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 147: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  110,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 148: not used by a script */
    {  111,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 149: not used by a script */
    {  112,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 150: not used by a script */
    {  113,    0,   39, 0x0000,    0,    1,   62,    1 },  /* 151: not used by a script */
    {  113,    0,   39, 0x0000,    0,    1,   63,    1 },  /* 152: not used by a script */
    {  113,    0,   39, 0x0000,    0,    1,    0,    1 },  /* 153: not used by a script */
    {  114,    0,   40, 0x0000,    0,    1,    0,    1 },  /* 154: not used by a script */
    {  115,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 155: not used by a script */
    {   63,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 156: ATTACK 13 SP: not started by a command */
    {   98,    0,    0, 0x0000,    0,    2,   66,    2 },  /* 157: not used by a script */
    {   64,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 158: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {   65,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 159: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {   66,    0,   27, 0x0000,    0,    3,   67,    3 },  /* 160: not used by a script */
    {   66,    0,   27, 0x0000,    0,    3,   68,    3 },  /* 161: not used by a script */
    {   66,    0,   27, 0x0000,    0,    3,   69,    3 },  /* 162: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {   66,    0,   27, 0x0000,    0,    3,   70,    3 },  /* 163: not used by a script */
    {   66,    0,   27, 0x0000,    0,    3,   71,    3 },  /* 164: not used by a script */
    {   66,    0,   27, 0x0000,    0,    3,   72,    3 },  /* 165: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {   66,    0,   27, 0x0000,    0,    3,   73,    3 },  /* 166: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {   67,    0,   28, 0x0000,    0,    3,    0,    3 },  /* 167: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    {   68,    0,   29, 0x0000,    0,    3,   74,    3 },  /* 168: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    {   68,    0,   29, 0x0000,    0,    3,   75,    3 },  /* 169: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    {   68,    0,   29, 0x0000,    0,    3,    0,    3 },  /* 170: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +1 */
    {  118,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 171: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    {  116,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 172: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  117,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 173: V JUMP K S A, V JUMP K M A, F JUMP K S A +5 */
    {  118,    0,   42, 0x0000,    0,    3,   78,    3 },  /* 174: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,    0,   42, 0x0000,    0,    3,   79,    3 },  /* 175: V JUMP K S A, F JUMP K S A, follow-up of WAIT +1 */
    {  118,    0,   42, 0x0000,    0,    3,   80,    3 },  /* 176: not used by a script */
    {  118,    0,   42, 0x0000,    0,    3,   81,    3 },  /* 177: not used by a script */
    {  119,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 178: F JUMP K S B, F JUMP K M B, F JUMP K L B +2 */
    {  120,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 179: F JUMP K S B, F JUMP K M B, F JUMP K L B +2 */
    {  121,    0,   43, 0x0000,    0,    3,   82,    3 },  /* 180: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1 */
    {  121,    0,   43, 0x0000,    0,    3,   83,    3 },  /* 181: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +1 */
    {  122,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 182: follow-up of SP APPEAR 4 */
    {  123,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 183: follow-up of APPEAR 4 */
    {  124,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 184: follow-up of APPEAR 5 */
    {  125,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 185: follow-up of APPEAR 5 */
    {  126,    0,   44, 0x0000,    2,    1,    0,    1 },  /* 186: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    {  127,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 187: TUKAMIKAKARI A, ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    {  128,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 188: BODY SLAM, IPPONZEOI, TOMOE RYU +5 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 189: ATTACK 5 S: not started by a command, ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) +4 */
    {    0,    0,    0, 0x0000,    0,    0,   51,    1 },  /* 190: not started by a command */
    {   29,    0,   12, 0x0000,    0,    1,   52,    1 },  /* 191: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 192: follow-up of AIR NORMAL, ATTACK 3 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  131,    0,    0, 0x0000,    0,    6,    0,    1 },  /* 193: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    {  132,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 194: ATTACK 2 SP: EX 214+PP (plain script) */
    {  133,    0,   46, 0x0000,    0,    1,   85,    1 },  /* 195: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    {  133,    0,   46, 0x0000,    0,    1,   86,    1 },  /* 196: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 197: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    {   98,    0,    0, 0x0000,    0,    2,   87,    2 },  /* 198: ATTACK 13 SP: not started by a command */
    {   99,    0,    0, 0x0000,    0,    1,   88,    2 },  /* 199: ATTACK 13 SP: not started by a command */
    {   17,    0,    5, 0x0000,    0,    1,   89,    1 },  /* 200: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,   90,    1 },  /* 201: not used by a script */
    {  136,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 202: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 2 SP: EX 214+PP (plain script) +1 */
    {  137,    0,   74, 0x0000,    0,    3,   91,    3 },  /* 203: ATTACK 12 L: not started by a command, not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,   21 },  /* 204: NEKOROBI S, no name */
    {  133,    0,   46, 0x0000,    0,    1,    0,    1 },  /* 205: L KICK A, follow-up of follow-up of S KICK A, follow-up of KAGAMI K A */
    {   46,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 206: KAGAMI P A */
    {   47,    0,   22, 0x0000,    0,   18,   14,    2 },  /* 207: KAGAMI P A */
    {   47,    0,   22, 0x0000,    0,   18,   19,    2 },  /* 208: KAGAMI P A */
    {   47,    0,   22, 0x0000,    0,   18,    0,    2 },  /* 209: KAGAMI P A */
    {   59,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 210: not used by a script */
    {   54,    0,   24, 0x0000,    0,   18,   17,    2 },  /* 211: not used by a script */
    {   54,    0,   24, 0x0000,    0,   18,    0,    2 },  /* 212: not used by a script */
    {  100,    0,    0, 0x0000,    0,    5,   92,    1 },  /* 213: ATTACK 13 SP: not started by a command */
    {  107,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 214: not used by a script */
    {   66,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 215: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 216: LOSE SONABA */
    {  132,    0,    0, 0x0000,    0,    1,   65,    2 },  /* 217: not used by a script */
    {  138,    0,   48, 0x0000,    0,    1,    0,    1 },  /* 218: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script) */
    {  138,    0,   48, 0x0000,    0,    1,   26,    1 },  /* 219: not used by a script */
    {   14,    0,    0, 0x0000,    0,    1,   28,    1 },  /* 220: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    {   11,    0,    3, 0x0000,    0,    1,   93,    1 },  /* 221: follow-up of S KICK A */
    {  139,    0,   49, 0x0000,    0,    3,   80,    3 },  /* 222: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,    0,   50, 0x0000,    0,    3,   81,    3 },  /* 223: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  139,    0,   50, 0x0000,    0,    3,    0,    3 },  /* 224: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    {  140,    0,    0, 0x0000,    0,    1,    0,    9 },  /* 225: L PUNCH C, follow-up of APPEAR USE, ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) +6 */
    {  141,    0,    0, 0x0000,    0,    2,    0,    9 },  /* 226: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP) +4 */
    {  141,    0,    0, 0x0000,    0,    2,   94,    9 },  /* 227: EX 623+PP (routine Att_SLIDE_and_JUMP), not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,   95,    1 },  /* 228: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {    1,    0,    1, 0x0000,    0,    1,   95,    1 },  /* 229: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  142,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 230: not used by a script */
    {  143,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 231: not used by a script */
    {  144,    0,   51, 0x0000,    0,    3,   96,    3 },  /* 232: not used by a script */
    {  145,    0,   52, 0x0000,    0,    3,   97,    3 },  /* 233: not used by a script */
    {    1,    0,    6, 0x0000,    0,    1,   53,    1 },  /* 234: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,   84,    1 },  /* 235: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {    0,    0,    0, 0x0000,    0,    0,  119,    1 },  /* 236: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   99,    1 },  /* 237: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {    0,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 238: not used by a script */
    {    0,    0,    0, 0x0000,    0,    2,   32,    2 },  /* 239: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,   98,    1 },  /* 240: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  148,    0,    0, 0x0000,    0,    1,   24,    1 },  /* 241: ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
    {   14,    0,    0, 0x0000,    0,    1,  101,    1 },  /* 242: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,  102,    1 },  /* 243: not used by a script */
    {  149,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 244: UPPER L, BODY UPPER L */
    {  150,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 245: UPPER L, BODY UPPER L */
    {  151,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 246: UPPER L, BODY UPPER L */
    {  152,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 247: UPPER L, BODY UPPER L */
    {  153,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 248: FACE S, FACE M, FACE L +5 */
    {  154,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 249: FACE M, FACE L, FOOK OKU L +1 */
    {  155,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 250: not used by a script */
    {  156,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 251: not used by a script */
    {  157,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 252: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  158,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 253: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    {  159,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 254: NOUTEN M, NOUTEN L, BODY BROW L */
    {  160,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 255: NOUTEN L, BODY BROW L, TATAKI S */
    {  161,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 256: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  162,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 257: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    {  163,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 258: KAGAMI M, KAGAMI L */
    {  164,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 259: KAGAMI L */
    {  100,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 260: not used by a script */
    {  165,    0,   54, 0x0000,    0,    1,  102,    1 },  /* 261: L PUNCH C, follow-up of APPEAR USE */
    {  166,    0,   55, 0x0000,    0,    1,  103,    1 },  /* 262: L PUNCH C, follow-up of APPEAR USE */
    {  166,    0,   56, 0x0000,    0,    1,    0,    1 },  /* 263: L PUNCH C, follow-up of APPEAR USE, ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    {  167,    0,   57, 0x0000,    0,    1,    0,    1 },  /* 264: M KICK B, follow-up of ZANNEN 8 */
    {  167,    0,   58, 0x0000,    0,    1,    0,    1 },  /* 265: M KICK B, follow-up of ZANNEN 8 */
    {  168,    0,   59, 0x0000,    0,    1,    0,    1 },  /* 266: M KICK B, follow-up of ZANNEN 8 */
    {  169,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 267: M KICK B, follow-up of ZANNEN 8 */
    {  169,    0,   60, 0x0000,    0,    1,  105,    1 },  /* 268: M KICK B, follow-up of ZANNEN 8 */
    {  169,    0,   60, 0x0000,    0,    1,  104,    1 },  /* 269: M KICK B, follow-up of ZANNEN 8 */
    {  169,    0,   60, 0x0000,    0,    1,    0,    1 },  /* 270: M KICK B, follow-up of ZANNEN 8 */
    {  169,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 271: M KICK B, follow-up of ZANNEN 8 */
    {  170,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 272: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +1 */
    {  171,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 273: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +1 */
    {  172,    0,   75, 0x0000,    0,    3,  107,    3 },  /* 274: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  172,    0,   75, 0x0000,    0,    3,    0,    3 },  /* 275: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  173,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 276: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  174,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 277: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  175,    0,   62, 0x0000,    0,    3,  108,    3 },  /* 278: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  175,    0,   62, 0x0000,    0,    3,    0,    3 },  /* 279: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  176,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 280: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {  178,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 281: follow-up of WIN 7, KAGAMI K A */
    {  179,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 282: follow-up of WIN 7, KAGAMI K A */
    {  178,    0,   65, 0x0000,    0,    2,    0,    2 },  /* 283: follow-up of WIN 7, KAGAMI K A */
    {  178,    0,   66, 0x0000,    0,    2,    0,    2 },  /* 284: follow-up of WIN 7, KAGAMI K A */
    {  178,    0,   67, 0x0000,    0,    2,  111,    2 },  /* 285: follow-up of WIN 7, KAGAMI K A */
    {  178,    0,   68, 0x0000,    0,    2,    0,    2 },  /* 286: follow-up of WIN 7, KAGAMI K A */
    {  178,    0,   69, 0x0000,    0,    2,    0,    2 },  /* 287: follow-up of WIN 7, KAGAMI K A */
    {   23,    0,   63, 0x0000,    0,    1,  113,    1 },  /* 288: S PUNCH A, follow-up of ZANNEN 2 */
    {   23,    0,   64, 0x0000,    0,    1,    0,    1 },  /* 289: S PUNCH A, follow-up of ZANNEN 2 */
    {  126,    0,   44, 0x0000,    0,    1,    0,    1 },  /* 290: TUKAMIKAKARI A */
    {    1,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 291: JUMP JUNBI */
    {  180,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 292: S PUNCH B, follow-up of ZANNEN 3 */
    {  181,    0,   70, 0x0000,    0,    1,  114,    1 },  /* 293: not used by a script */
    {  182,    0,   71, 0x0000,    0,    1,  115,    1 },  /* 294: S PUNCH B, follow-up of ZANNEN 3 */
    {  182,    0,   72, 0x0000,    0,    1,    0,    1 },  /* 295: S PUNCH B, follow-up of ZANNEN 3 */
    {  183,    0,   73, 0x0000,    0,    1,    0,    1 },  /* 296: S PUNCH B, follow-up of ZANNEN 3 */
    {  183,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 297: S PUNCH B, follow-up of ZANNEN 3 */
    {  166,    0,   56, 0x0000,    0,    1,  116,    1 },  /* 298: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    {  114,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 299: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {  115,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 300: follow-up of SP APPEAR 3, JUDGMENT WIN, follow-up of ZANNEN 1, HANASARE */
    {  121,    0,   43, 0x0000,    0,    3,  117,    3 },  /* 301: F JUMP K S B */
    {  121,    0,   43, 0x0000,    0,    3,  118,    3 },  /* 302: F JUMP K S B */
    {  184,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 303: AIR NORMAL, UPPER, BODY UPPER +5 */
    {  185,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 304: ASIBARAI SIRI, GILL */
    {  186,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 305: ASIBARAI SIRI, GILL */
    {  187,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 306: ASIBARAI SIRI, GILL */
    {  188,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 307: ASIBARAI SIRI, GILL */
    {  189,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 308: ASIB TUNNOMERI, HUMI ASIB */
    {  190,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 309: ASIB TUNNOMERI, HUMI ASIB */
    {  191,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 310: ASIB TUNNOMERI, HUMI ASIB */
    {  192,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 311: ASIB TUNNOMERI, HUMI ASIB */
    {  193,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 312: NOKEZORI, UPPER, BODY UPPER +5 */
    {  194,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 313: NOKEZORI, UPPER, BODY UPPER +7 */
    {  195,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 314: NOKEZORI, UPPER, BODY UPPER +7 */
    {  196,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 315: NOKEZORI, UPPER, BODY UPPER +9 */
    {  197,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 316: NOKEZORI, UPPER, BODY UPPER +9 */
    {  198,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 317: NOKEZORI, UPPER, BODY UPPER +9 */
    {  199,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 318: NOKEZORI, UPPER, BODY UPPER +9 */
    {  200,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 319: NOKEZORI, UPPER, BODY UPPER +9 */
    {  201,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 320: KUNOJI, KUNOJI NOKE */
    {  202,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 321: KUNOJI, KUNOJI NOKE */
    {  203,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 322: KUNOJI, KUNOJI NOKE */
    {  204,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 323: KUNOJI, TTKI V. AIR */
    {  205,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 324: KIRIMOMI */
    {  206,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 325: KIRIMOMI */
    {  207,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 326: KIRIMOMI */
    {  208,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 327: KIRIMOMI */
    {  209,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 328: KIRIMOMI */
    {  210,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 329: KIRIMOMI */
    {  211,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 330: KIRIMOMI */
    {  212,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 331: KIRIMOMI */
    {  213,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 332: KIRIMOMI */
    {  214,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 333: KIRIMOMI */
    {  215,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 334: KIRIMOMI */
    {  216,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 335: KIRIMOMI */
    {  217,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 336: UPPER, BODY UPPER, ALEX B.D +1 */
    {  218,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 337: UPPER, BODY UPPER, ALEX B.D +1 */
    {  219,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 338: TTKI V. AIR */
    {  220,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 339: TTKI V. AIR */
    {  221,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 340: TTKI V. AIR */
    {  222,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 341: DENKI */
    {  223,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 342: TOUKETSU A */
    {  224,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 343: BODY UPPER SP */
    {  233,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 344: ATTACK 12 L: not started by a command, not started by a command */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 345: FRONT WALK, BACK WALK, KAGAMU +1 */
    {  225,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 346: FRONT WALK */
    {  226,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 347: FRONT WALK */
    {  227,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 348: BACK WALK */
    {  228,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 349: BACK WALK */
    {  229,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 350: HURIMUKI */
    {  230,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 351: HURIMUKI */
    {  231,    0,    0, 0x1515,    0,    2,    0,    2 },  /* 352: KAGAMI TURN */
    {    2,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 353: STAND UP */
    {  232,    0,    0, 0x1010,    0,    2,    0,   10 },  /* 354: STAND UP */
    {  232,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 355: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU */
    {  233,    0,    0, 0x0000,    0,    3,    0,   10 },  /* 356: SP JUMP JUNBI */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 357: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  234,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 358: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  235,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 359: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  236,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 360: PIYO */
    {  237,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 361: PIYO */
    {  238,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 362: KAMAE */
    {  238,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 363: KAMAE */
    {  239,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 364: KAMAE */
    {  240,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 365: DASH HUMIKOMI */
    {  241,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 366: DASH HUMIKOMI */
    {   73,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 367: DASH HUMIKOMI */
    {  242,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 368: DASH HUMIKOMI */
    {  243,    0,    0, 0x1A1A,    0,    1,    0,   10 },  /* 369: DASH HUMIKOMI */
    {  244,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 370: DASH TOBINOKI */
    {  245,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 371: DASH TOBINOKI */
    {  246,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 372: DASH TOBINOKI */
    {  247,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 373: DASH TOBINOKI */
    {  248,    0,    0, 0x1010,    0,    1,    0,   10 },  /* 374: DASH TOBINOKI */
    {  249,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 375: DASH TOBINOKI */
    {  250,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 376: DASH TOBINOKI */
    {  251,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 377: DASH TOBINOKI */
    {  252,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 378: DASH TOBINOKI */
    {  253,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 379: DASH HUMIKOMI, DASH TOBINOKI */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 380: LOSE SONABA, SHIMEOTASARE */
    {  254,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 381: KAGAMI K A */
    {  254,    0,   24, 0x0000,    0,   18,   17,    2 },  /* 382: KAGAMI K A */
    {  254,    0,   24, 0x0000,    0,   18,    0,    2 },  /* 383: KAGAMI K A */
    {  255,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 384: KAGAMI K A */
    {  254,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 385: follow-up of WIN 5 */
    {  254,    0,   24, 0x0000,    0,   18,   17,    2 },  /* 386: follow-up of WIN 5 */
    {  254,    0,   24, 0x0000,    0,   18,   17,    2 },  /* 387: follow-up of WIN 5 */
    {  255,    0,    0, 0x0000,    0,   18,    0,    2 },  /* 388: follow-up of WIN 5 */
    {  256,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 389: KAGAMI K A, follow-up of WIN 6 */
    {  256,    0,    2, 0x0000,    0,    2,   57,    2 },  /* 390: KAGAMI K A, follow-up of WIN 6 */
    {  256,    0,    4, 0x0000,    0,    2,   57,    2 },  /* 391: KAGAMI K A, follow-up of WIN 6 */
    {  256,    0,    4, 0x0000,    0,    2,    0,    2 },  /* 392: KAGAMI K A, follow-up of WIN 6 */
    {  256,    0,    2, 0x0000,    0,    2,    0,    2 },  /* 393: KAGAMI K A, follow-up of WIN 6 */
    {    1,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 394: not started by a command */
};

const BODY_BOX yun_body_box[257] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -10,  23,  70,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 1: no name, HURIMUKI, DASH HUMIKOMI +124 */
    { { {  -12,  24,  43,  20 },  {  -24,  52,  36,  18 },  {  -28,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +35 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +6 */
    { { {   -7,  19,  98,  20 },  {  -21,  50,  88,  14 },  {  -16,  44,  70,  20 },  {  -24,  48,  32,  36 } } },  /* 4: TUKAMIHAZUSI, TUKAMIHAZUSARE, no name +11 */
    { { {    6,  22,  74,  14 },  {   -8,  44,  60,  14 },  {   -2,  38,  36,  22 },  {  -26,  54,   0,  34 } } },  /* 5: not used by a script */
    { { {   -4,  18,  74,  14 },  {  -18,  46,  62,  14 },  {   -6,  36,  36,  26 },  {  -28,  56,   0,  34 } } },  /* 6: not used by a script */
    { { {   -4,  18,  46,  14 },  {    0,   0,   0,   0 },  {  -20,  48,  34,  18 },  {  -26,  54,   0,  32 } } },  /* 7: not used by a script */
    { { {  -18,  18,  68,  14 },  {  -30,  48,  58,  14 },  {  -24,  42,  36,  22 },  {  -24,  40,  14,  20 } } },  /* 8: not used by a script */
    { { {    0,  25,  79,  20 },  {  -16,  53,  67,  16 },  {  -32,  63,  21,  47 },  {  -21,  48,   0,  34 } } },  /* 9: not used by a script */
    { { {   18,  26,  68,  21 },  {  -11,  53,  57,  24 },  {  -36,  69,  44,  22 },  {  -20,  49,   0,  56 } } },  /* 10: not used by a script */
    { { {   13,  40,  70,  16 },  {   -2,  44,  60,  16 },  {  -46,  53,  40,  50 },  {  -40,  65,   0,  56 } } },  /* 11: M KICK A, follow-up of APPEAR USE, follow-up of S KICK A */
    { { {   16,  29,  70,  19 },  {  -19,  63,  65,  16 },  {  -64, 104,  42,  24 },  {  -32,  61,   0,  36 } } },  /* 12: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    { { {    6,  28,  70,  21 },  {  -35,  72,  58,  16 },  {  -58,  94,  27,  31 },  {  -32,  58,   0,  34 } } },  /* 13: M KICK A, follow-up of S KICK A, follow-up of APPEAR USE */
    { { {    5,  27,  74,  21 },  {  -17,  60,  64,  16 },  {  -31,  76,  38,  28 },  {  -32,  61,   0,  36 } } },  /* 14: M KICK A, follow-up of S KICK A, follow-up of follow-up of S KICK A +1 */
    { { {  -10,  16,  74,  14 },  {  -26,  46,  62,  14 },  {  -16,  34,  34,  26 },  {  -38,  60,   0,  32 } } },  /* 15: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -18,  16,  68,  14 },  {  -24,  44,  58,  12 },  {   -8,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 16: ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 17: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 18: no name */
    { { {   -6,  16,  70,  14 },  {  -20,  46,  58,  12 },  {  -20,  46,  36,  22 },  {  -22,  50,   0,  34 } } },  /* 19: not used by a script */
    { { {  -20,  16,  60,  14 },  {  -22,  40,  54,  14 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 20: not used by a script */
    { { {  -26,  16,  64,  14 },  {  -34,  46,  56,  12 },  {  -24,  30,  36,  22 },  {  -40,  74,   0,  34 } } },  /* 21: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -20,  16,  68,  14 },  {  -28,  46,  58,  12 },  {  -22,  30,  36,  22 },  {  -40,  66,   0,  34 } } },  /* 22: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 23: S PUNCH B, follow-up of ZANNEN 3, S PUNCH A +1 */
    { { {  -23,  20,  70,  16 },  {  -37,  61,  54,  18 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 24: not used by a script */
    { { {  -23,  37,  69,  16 },  {  -37,  66,  54,  18 },  {  -37,  64,  34,  22 },  {  -57,  87,   0,  32 } } },  /* 25: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +2 */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 26: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name */
    { { {  -18,  20,  70,  16 },  {  -31,  54,  54,  18 },  {  -26,  44,  34,  22 },  {  -42,  66,   0,  32 } } },  /* 27: M PUNCH A, follow-up of ZANNEN 4, not started by a command */
    { { {  -18,  21,  70,  18 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -55,  98,   0,  32 } } },  /* 28: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -24,  16,  66,  14 },  {  -30,  60,  58,  10 },  {  -37,  66,  34,  22 },  {  -52,  87,   0,  32 } } },  /* 29: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +3 */
    { { {  -30,  29,  67,  16 },  {  -37,  66,  54,  18 },  {  -31,  57,  34,  22 },  {  -46,  87,   0,  32 } } },  /* 30: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +1 */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 31: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 32: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 33: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -30,  26,  68,  21 },  {  -60,  88,  62,  17 },  {  -42,  69,  34,  35 },  {  -34,  58,   0,  32 } } },  /* 34: L PUNCH B, follow-up of ZANNEN 6 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 35: not used by a script */
    { { {  -32,  30,  64,  20 },  {  -38,  67,  59,  12 },  {  -40,  65,  36,  22 },  {  -56,  95,   0,  34 } } },  /* 36: L PUNCH B, follow-up of ZANNEN 6 */
    { { {  -23,  28,  66,  21 },  {  -61,  89,  56,  14 },  {  -36,  57,  36,  20 },  {  -55,  88,   0,  34 } } },  /* 37: L PUNCH B, follow-up of M PUNCH A, M PUNCH B, follow-up of ZANNEN 6 +1 */
    { { {  -28,  16,  66,  14 },  {  -30,  46,  60,  12 },  {  -16,  36,  34,  24 },  {  -38,  68,   0,  34 } } },  /* 38: follow-up of M PUNCH A, M PUNCH B */
    { { {  -26,  16,  64,  14 },  {  -38,  56,  56,  12 },  {  -24,  36,  36,  20 },  {  -38,  68,   0,  34 } } },  /* 39: follow-up of M PUNCH A, M PUNCH B */
    { { {  -14,  16,  78,  14 },  {  -28,  46,  68,  12 },  {  -16,  30,  38,  28 },  {  -30,  54,   0,  36 } } },  /* 40: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    { { {  -12,  23,  79,  19 },  {  -30,  54,  68,  16 },  {  -40,  72,  40,  30 },  {  -37,  61,   0,  41 } } },  /* 41: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    { { {  -20,  36,  86,  19 },  {  -51,  86,  76,  12 },  {  -43,  60,  23,  54 },  {    0,   0,   0,   0 } } },  /* 42: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  87,  19 },  {  -48,  89,  78,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 43: M KICK C, follow-up of JUDGMENT WAIT, no name */
    { { {  -17,  26,  81,  19 },  {  -48,  80,  73,  12 },  {  -37,  66,  44,  35 },  {  -36,  60,   0,  42 } } },  /* 44: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -17,  26,  76,  19 },  {  -48,  94,  67,  12 },  {  -37,  66,  44,  25 },  {  -36,  60,   0,  42 } } },  /* 45: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {  -24,  34,  47,  20 },  {  -41,  69,  36,  16 },  {    0,   0,   0,   0 },  {  -39,  78,   0,  36 } } },  /* 46: KAGAMI P A, follow-up of WIN 2, follow-up of WIN 3 */
    { { {  -31,  49,  47,  20 },  {  -41,  69,  40,  16 },  {    0,   0,   0,   0 },  {  -46,  79,   0,  40 } } },  /* 47: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -25,  28,  49,  18 },  {  -39,  60,  36,  19 },  {  -22,  48,  19,  17 },  {  -34,  61,   0,  19 } } },  /* 48: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    { { {  -30,  33,  49,  18 },  {  -45,  64,  36,  23 },  {  -25,  51,  19,  17 },  {  -36,  64,   0,  19 } } },  /* 49: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    { { {  -28,  16,  68,  14 },  {  -32,  46,  58,  14 },  {  -22,  34,  34,  26 },  {  -36,  64,   0,  32 } } },  /* 50: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {    2,  16,  80,  14 },  {  -16,  44,  70,  14 },  {  -38,  64,  54,  16 },  {  -26,  50,  34,  18 } } },  /* 51: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    { { {  -12,  16,  82,  14 },  {  -22,  44,  72,  14 },  {  -12,  30,  46,  24 },  {  -26,  42,   8,  36 } } },  /* 52: ATTACK 2 SP: EX 214+PP (plain script) */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 53: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 54: not used by a script */
    { { {  -28,  16,  68,  14 },  {  -32,  44,  58,  12 },  {  -16,  30,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 55: not used by a script */
    { { {   -3,  32,  52,  21 },  {  -36,  78,  39,  18 },  {  -43,  90,   0,  41 },  {    0,   0,   0,   0 } } },  /* 56: not used by a script */
    { { {   -4,  24,  56,  14 },  {  -34,  71,  40,  18 },  {  -55,  99,   0,  41 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { {  -12,  35,  56,  15 },  {  -42,  69,  33,  26 },  {  -52,  87,   0,  34 },  {  -48,  80,   0,  18 } } },  /* 58: not used by a script */
    { { {    3,  30,  48,  23 },  {  -34,  69,  39,  19 },  {  -35,  69,  16,  23 },  {  -36,  70,   0,  16 } } },  /* 59: not used by a script */
    { { {  -36,  22,  64,  28 },  {  -28,  56,  52,  14 },  {  -30,  64,  40,  14 },  {   14,  16,  22,  24 } } },  /* 60: not used by a script */
    { { {    2,  16,  72,  14 },  {  -16,  44,  62,  14 },  {  -38,  64,  46,  16 },  {  -26,  50,  26,  18 } } },  /* 61: not used by a script */
    { { {   -4,  16,  68,  14 },  {  -16,  44,  56,  14 },  {  -24,  52,  38,  16 },  {  -32,  50,   8,  28 } } },  /* 62: not used by a script */
    { { {  -16,  36,  20,  10 },  {    0,   0,   0,   0 },  {  -18,  40,   0,  18 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 13 SP: not started by a command */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  14 },  {  -12,  32,  62,  22 },  {  -30,  46,  46,  26 } } },  /* 64: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -26,  16,  96,  14 },  {  -34,  46,  84,  14 },  {  -12,  40,  60,  22 },  {  -24,  46,  40,  22 } } },  /* 65: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -34,  16,  96,  14 },  {  -40,  52,  86,  14 },  {  -20,  56,  62,  22 },  {  -16,  32,  28,  32 } } },  /* 66: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {  -16,  16,  96,  14 },  {  -28,  44,  86,  18 },  {  -12,  32,  62,  22 },  {  -36,  46,  46,  26 } } },  /* 67: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -20,  16,  96,  14 },  {  -28,  42,  86,  18 },  {  -28,  46,  68,  16 },  {  -20,  36,  32,  36 } } },  /* 68: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
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
    { { {  -20,  16,  64,  14 },  {  -28,  46,  56,  12 },  {  -12,  34,  36,  22 },  {  -30,  54,   0,  34 } } },  /* 85: L PUNCH C, follow-up of APPEAR USE, ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU) +9 */
    { { {  -24,  16,  58,  14 },  {  -28,  46,  50,  12 },  {  -12,  34,  32,  22 },  {  -18,  50,   0,  32 } } },  /* 86: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -32,  57,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 87: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -16,  34,  36,  22 },  {  -77, 135,   7,  29 } } },  /* 88: ATTACK 12 M: not started by a command */
    { { {  -28,  16,  68,  14 },  {  -28,  46,  58,  14 },  {  -16,  34,  36,  22 },  {  -71, 124,   5,  30 } } },  /* 89: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +2 */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 90: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    { { {  -11,  23,  81,  18 },  {  -20,  46,  71,  15 },  {  -37,  58,  32,  39 },  {    0,   0,   0,   0 } } },  /* 91: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +1 */
    { { {    6,  16,  86,  14 },  {  -10,  42,  72,  14 },  {  -22,  42,  46,  20 },  {   -8,  28,  16,  36 } } },  /* 92: follow-up of APPEAR USE, HANASARE, ATTACK 5 S: not started by a command +2 */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 93: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +2 */
    { { {   -4,  16,  92,  14 },  {  -12,  40,  80,  14 },  {  -14,  30,  56,  22 },  {  -14,  22,  18,  40 } } },  /* 94: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {  -10,  16,  84,  14 },  {  -20,  40,  74,  12 },  {  -10,  30,  50,  22 },  {  -22,  32,  18,  34 } } },  /* 95: ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 13 SP: not started by a command +1 */
    { { {  -28,  16,  46,  14 },  {  -12,  36,  48,  12 },  {    0,   0,   0,   0 },  {  -18,  54,   0,  32 } } },  /* 96: ATTACK 2 SP: EX 214+PP (plain script) */
    { { {  -30,  53,  48,  12 },  {    0,   0,   0,   0 },  {  -50,  72,   0,  47 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 2 SP: EX 214+PP (plain script) */
    { { {  -26,  50,  36,  10 },  {    0,   0,   0,   0 },  {  -43,  73,  13,  35 },  {   14,  18,   0,  16 } } },  /* 98: ATTACK 13 SP: not started by a command */
    { { {  -26,  26,  48,  22 },  {  -30,  54,  40,  14 },  {  -43,  76,  22,  37 },  {   16,  20,   0,  24 } } },  /* 99: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
    { { {  -44,  37,  36,  73 },  {  -32,  58,  52,  14 },  {  -36,  70,  34,  16 },  {   10,  16,   0,  36 } } },  /* 100: ATTACK 2 SP: EX 214+PP (plain script), ATTACK 13 SP: not started by a command */
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
    { { {  -12,  16,  98,  14 },  {  -10,  30,  86,  16 },  {   -4,  28,  68,  20 },  {  -24,  36,  48,  28 } } },  /* 119: F JUMP K S B, F JUMP K M B, F JUMP K L B +2 */
    { { {  -10,  16,  98,  14 },  {   -4,  30,  90,  16 },  {  -20,  42,  62,  26 },  {  -16,  28,  38,  22 } } },  /* 120: F JUMP K S B, F JUMP K M B, F JUMP K L B +2 */
    { { {  -10,  44,  98,  19 },  {  -15,  54,  92,   8 },  {  -20,  58,  62,  31 },  {    0,   0,   0,   0 } } },  /* 121: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +2 */
    { { {  -10,  16,  78,  14 },  {   -6,  32,  60,  24 },  {  -30,  52,  32,  26 },  {  -16,  26,   0,  32 } } },  /* 122: follow-up of SP APPEAR 4 */
    { { {  -18,  16,  84,  14 },  {  -24,  46,  70,  16 },  {  -10,  32,  32,  36 },  {  -20,  24,   0,  44 } } },  /* 123: follow-up of APPEAR 4 */
    { { {   -6,  16,  92,  14 },  {  -12,  32,  78,  18 },  {  -36,  54,  56,  20 },  {   -6,  24,   0,  54 } } },  /* 124: follow-up of APPEAR 5 */
    { { {   -6,  16,  84,  14 },  {  -12,  30,  60,  28 },  {  -38,  54,  30,  28 },  {   -4,  24,   0,  28 } } },  /* 125: follow-up of APPEAR 5 */
    { { {  -28,  34,  74,  16 },  {  -31,  52,  59,  19 },  {  -22,  51,  34,  25 },  {  -30,  76,   0,  34 } } },  /* 126: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command, TUKAMIKAKARI A */
    { { {  -19,  31,  72,  16 },  {  -24,  46,  52,  22 },  {  -21,  41,  34,  22 },  {  -30,  54,   0,  34 } } },  /* 127: TUKAMIKAKARI A, ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    { { {    0,   0,   0,   0 },  {  -16,  45,  65,  15 },  {  -17,  47,  46,  18 },  {  -17,  46,  28,  17 } } },  /* 128: BODY SLAM, IPPONZEOI, TOMOE RYU +5 */
    { { {  -68,  30,  70,  16 },  {  -82,  73,  52,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 129: not used by a script */
    { { {  -86,  36,  59,  20 },  {  -95,  73,  42,  18 },  {  -59,  54,  34,  22 },  {  -65,  91,   0,  32 } } },  /* 130: not used by a script */
    { { {  -80,  44,  63,  17 },  {  -95,  81,  39,  29 },  {  -82,  84,  34,  26 },  {  -69,  95,   0,  34 } } },  /* 131: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    { { {  -49,  81,   0,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: ATTACK 2 SP: EX 214+PP (plain script) */
    { { {  -64,  98,  73,  22 },  {  -63,  98,  70,   7 },  {  -67, 101,  34,  35 },  {  -48,  82,   0,  32 } } },  /* 133: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    { { {  -10,  39,  71,  21 },  {  -28,  69,  70,   7 },  {  -67, 110,  34,  35 },  {  -31,  74,   0,  32 } } },  /* 134: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    { { {   -9,  26,  85,  22 },  {  -25,  48,  54,  35 },  {  -54,  74,  30,  43 },  {    0,   0,   0,   0 } } },  /* 135: not used by a script */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -15,  38,  34,  35 },  {  -16,  41,   0,  32 } } },  /* 136: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 2 SP: EX 214+PP (plain script) +1 */
    { { {  -10,  22,  71,  21 },  {  -16,  39,  70,   7 },  {  -62,  93,  47,  57 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 12 L: not started by a command, not started by a command */
    { { {  -24,  16,  68,  14 },  {  -22,  32,  58,  12 },  {  -10,  30,  36,  22 },  {  -30,  54,   0,  36 } } },  /* 138: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    { { {  -28,  16,  96,  14 },  {  -34,  58,  86,  18 },  {  -73,  83,  61,  25 },  {  -26,  38,  48,  26 } } },  /* 139: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -18,  22,  48,  11 },  {  -28,  59,  37,  12 },  {  -28,  60,  21,  18 },  {  -29,  61,   0,  26 } } },  /* 140: L PUNCH C, follow-up of APPEAR USE, ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) +6 */
    { { {  -22,  22,  28,  11 },  {  -28,  46,  27,  12 },  {  -15,  34,  21,  18 },  {  -30,  54,   0,  26 } } },  /* 141: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP) +4 */
    { { {   -4,  16,  98,  14 },  {  -23,  49,  88,  14 },  {  -13,  35,  66,  22 },  {  -30,  44,  47,  27 } } },  /* 142: not used by a script */
    { { {    6,  16,  96,  14 },  {  -26,  57,  86,  16 },  {  -39,  64,  66,  20 },  {  -10,  30,  37,  29 } } },  /* 143: not used by a script */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 144: not used by a script */
    { { {    8,  25,  95,  20 },  {  -52,  91,  90,  16 },  {  -18,  61,  69,  21 },  {  -32,  61,  43,  26 } } },  /* 145: not used by a script */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 146: not used by a script */
    { { {  -23,  31,  70,  20 },  {  -39,  66,  55,  16 },  {  -32,  54,  36,  22 },  {  -45,  76,   0,  34 } } },  /* 147: not used by a script */
    { { {  -28,  16,  66,  14 },  {  -28,  46,  56,  14 },  {  -32,  57,  36,  22 },  {  -57, 112,   7,  29 } } },  /* 148: ATTACK 4 SP: EX 236+PP (routine Att_SENPUUKYAKU) */
    { { {    6,  23,  74,  18 },  {  -19,  51,  60,  14 },  {  -22,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 149: UPPER L, BODY UPPER L */
    { { {   14,  23,  73,  18 },  {  -16,  51,  60,  14 },  {  -23,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 150: UPPER L, BODY UPPER L */
    { { {   18,  23,  72,  18 },  {  -14,  51,  60,  14 },  {  -24,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 151: UPPER L, BODY UPPER L */
    { { {   20,  23,  71,  18 },  {  -13,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 152: UPPER L, BODY UPPER L */
    { { {    6,  23,  68,  18 },  {  -15,  51,  59,  14 },  {  -17,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 153: FACE S, FACE M, FACE L +5 */
    { { {   18,  23,  66,  18 },  {   -9,  51,  58,  14 },  {  -14,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 154: FACE M, FACE L, FOOK OKU L +1 */
    { { {   26,  23,  64,  18 },  {   -5,  51,  57,  14 },  {  -12,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 155: not used by a script */
    { { {   30,  23,  62,  18 },  {   -3,  51,  56,  14 },  {  -11,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 156: not used by a script */
    { { {  -14,  23,  67,  18 },  {  -21,  51,  58,  14 },  {  -19,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 157: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -18,  23,  64,  18 },  {  -19,  51,  56,  14 },  {  -17,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 158: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    { { {  -22,  23,  61,  18 },  {  -17,  51,  54,  14 },  {  -15,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 159: NOUTEN M, NOUTEN L, BODY BROW L */
    { { {  -26,  23,  58,  18 },  {  -15,  51,  52,  14 },  {  -13,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 160: NOUTEN L, BODY BROW L, TATAKI S */
    { { {   -6,  24,  43,  20 },  {  -22,  52,  36,  18 },  {  -27,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 161: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {    0,  24,  43,  20 },  {  -20,  52,  36,  18 },  {  -26,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 162: KAGAMI S, KAGAMI M, KAGAMI L +1 */
    { { {    6,  24,  43,  20 },  {  -18,  52,  36,  18 },  {  -25,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 163: KAGAMI M, KAGAMI L */
    { { {   12,  24,  43,  20 },  {  -16,  52,  36,  18 },  {  -24,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 164: KAGAMI L */
    { { {  -39,  21,  55,  18 },  {  -44,  51,  50,  14 },  {  -47,  47,  32,  17 },  {  -50,  58,   0,  32 } } },  /* 165: L PUNCH C, follow-up of APPEAR USE */
    { { {  -26,  21,  56,  18 },  {  -35,  51,  50,  14 },  {  -31,  47,  32,  17 },  {  -42,  58,   0,  32 } } },  /* 166: L PUNCH C, follow-up of APPEAR USE, ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -25,  23,  79,  18 },  {  -37,  51,  65,  14 },  {  -30,  42,  33,  31 },  {  -34,  58,   0,  32 } } },  /* 167: M KICK B, follow-up of ZANNEN 8 */
    { { {  -26,  19,  78,  16 },  {  -24,  35,  68,  11 },  {  -26,  34,  38,  30 },  {  -37,  41,  -3,  41 } } },  /* 168: M KICK B, follow-up of ZANNEN 8 */
    { { {  -17,  27,  77,   9 },  {  -32,  48,  62,  16 },  {  -39,  52,  35,  28 },  {  -32,  39,   0,  36 } } },  /* 169: M KICK B, follow-up of ZANNEN 8 */
    { { {  -12,  23,  75,  17 },  {  -19,  40,  59,  18 },  {  -20,  41,  34,  25 },  {  -27,  49,   0,  33 } } },  /* 170: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +1 */
    { { {   -2,  23,  83,  17 },  {  -18,  48,  62,  22 },  {  -26,  55,  37,  24 },  {  -24,  41,  10,  27 } } },  /* 171: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +1 */
    { { {  -10,  29,  93,  18 },  {  -23,  52,  77,  18 },  {  -20,  46,  59,  18 },  {  -21,  39,  16,  43 } } },  /* 172: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -10,  28,  87,  18 },  {  -23,  50,  77,  18 },  {  -33,  58,  47,  30 },  {  -26,  40,  16,  31 } } },  /* 173: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -20,  23,  95,  18 },  {  -27,  48,  80,  21 },  {  -35,  56,  59,  22 },  {  -32,  44,  31,  28 } } },  /* 174: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -22,  29,  94,  18 },  {  -30,  51,  77,  19 },  {  -27,  46,  59,  18 },  {  -21,  39,  17,  42 } } },  /* 175: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -20,  24,  95,  18 },  {  -24,  49,  80,  21 },  {  -27,  53,  49,  31 },  {  -17,  42,   8,  41 } } },  /* 176: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {   -9,  23,  95,  15 },  {  -15,  38,  77,  18 },  {  -22,  46,  59,  18 },  {  -21,  39,   0,  59 } } },  /* 177: not used by a script */
    { { {  -19,  29,  43,  18 },  {  -29,  54,  36,  16 },  {  -36,  63,  19,  17 },  {  -44,  72,   0,  19 } } },  /* 178: follow-up of WIN 7, KAGAMI K A */
    { { {  -28,  24,  48,  18 },  {  -41,  51,  36,  16 },  {  -40,  55,  19,  17 },  {  -42,  63,   0,  19 } } },  /* 179: follow-up of WIN 7, KAGAMI K A */
    { { {  -13,  20,  70,  16 },  {  -27,  49,  54,  18 },  {  -15,  40,  32,  22 },  {  -32,  54,   0,  32 } } },  /* 180: S PUNCH B, follow-up of ZANNEN 3 */
    { { {  -45,  20,  70,  16 },  {  -55,  61,  54,  18 },  {  -38,  44,  33,  22 },  {  -40,  63,   0,  32 } } },  /* 181: not used by a script */
    { { {  -37,  20,  70,  16 },  {  -46,  49,  55,  15 },  {  -38,  44,  33,  22 },  {  -40,  63,   0,  32 } } },  /* 182: S PUNCH B, follow-up of ZANNEN 3 */
    { { {  -28,  20,  70,  16 },  {  -28,  44,  57,  14 },  {  -28,  44,  34,  22 },  {  -40,  63,   0,  32 } } },  /* 183: S PUNCH B, follow-up of ZANNEN 3 */
    { { {    0,   0,   0,   0 },  {  -14,  41,  67,  16 },  {  -19,  47,  46,  18 },  {  -25,  49,  27,  19 } } },  /* 184: AIR NORMAL, UPPER, BODY UPPER +5 */
    { { {    0,   0,   0,   0 },  {   13,  44,  59,  15 },  {   -1,  55,  41,  18 },  {  -18,  59,  26,  18 } } },  /* 185: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   23,  42,  56,  16 },  {    3,  53,  42,  19 },  {  -15,  58,  32,  23 } } },  /* 186: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   36,  33,  34,  25 },  {   18,  34,  40,  25 },  {   -7,  39,  32,  27 } } },  /* 187: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {   32,  33,   5,  25 },  {   18,  34,   0,  25 },  {   -4,  39,   0,  40 } } },  /* 188: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {  -40,  36,  56,  15 },  {  -39,  35,  38,  18 },  {  -30,  50,  19,  19 } } },  /* 189: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -40,  36,  51,  15 },  {  -28,  32,  34,  18 },  {  -17,  50,  19,  18 } } },  /* 190: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -37,  34,  47,  18 },  {  -19,  32,  34,  19 },  {   -8,  44,  19,  19 } } },  /* 191: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -38,  34,  21,  22 },  {  -26,  33,  27,  25 },  {   -5,  35,  19,  26 } } },  /* 192: ASIB TUNNOMERI, HUMI ASIB */
    { { {    0,   0,   0,   0 },  {   13,  26,  68,  21 },  {   -9,  26,  62,  22 },  {  -28,  40,  37,  33 } } },  /* 193: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {    0,   0,   0,   0 },  {   17,  26,  63,  21 },  {   -2,  26,  59,  22 },  {  -32,  39,  41,  31 } } },  /* 194: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   21,  26,  54,  21 },  {   -1,  26,  50,  25 },  {  -32,  38,  38,  33 } } },  /* 195: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {   24,  24,  42,  25 },  {    2,  24,  41,  29 },  {  -29,  30,  37,  34 } } },  /* 196: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   24,  26,  37,  22 },  {    4,  26,  39,  29 },  {  -27,  31,  43,  31 } } },  /* 197: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   20,  26,  28,  25 },  {    2,  30,  36,  29 },  {  -25,  30,  44,  31 } } },  /* 198: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   17,  31,  22,  22 },  {    2,  31,  36,  26 },  {  -21,  32,  47,  32 } } },  /* 199: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {   16,  37,  14,  25 },  {    3,  36,  30,  27 },  {  -15,  38,  44,  29 } } },  /* 200: NOKEZORI, UPPER, BODY UPPER +9 */
    { { {    0,   0,   0,   0 },  {  -14,  45,  51,  21 },  {    3,  36,  38,  20 },  {  -19,  46,  22,  20 } } },  /* 201: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -7,  45,  49,  23 },  {   19,  29,  35,  29 },  {  -19,  52,  27,  22 } } },  /* 202: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -7,  45,  45,  23 },  {   19,  29,  32,  29 },  {  -19,  52,  22,  22 } } },  /* 203: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {   -5,  45,  32,  23 },  {   13,  29,  16,  26 },  {  -24,  45,  11,  24 } } },  /* 204: KUNOJI, TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {   -8,  38,  60,  15 },  {  -16,  41,  42,  18 },  {  -29,  50,  22,  20 } } },  /* 205: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -4,  39,  62,  17 },  {  -15,  40,  47,  18 },  {  -32,  48,  28,  20 } } },  /* 206: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -4,  39,  62,  17 },  {  -13,  40,  47,  18 },  {  -28,  45,  28,  20 } } },  /* 207: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -2,  39,  63,  17 },  {  -12,  40,  47,  18 },  {  -25,  45,  28,  20 } } },  /* 208: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    0,  39,  62,  17 },  {  -12,  40,  46,  18 },  {  -24,  45,  27,  20 } } },  /* 209: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    1,  42,  57,  20 },  {  -11,  41,  43,  20 },  {  -25,  45,  27,  21 } } },  /* 210: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    5,  42,  53,  21 },  {   -9,  41,  40,  22 },  {  -28,  43,  25,  26 } } },  /* 211: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   14,  33,  44,  21 },  {   -2,  32,  34,  22 },  {  -26,  40,  23,  26 } } },  /* 212: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  29,  31 },  {    0,  26,  28,  27 },  {  -29,  40,  19,  30 } } },  /* 213: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  22,  31 },  {   -1,  26,  25,  27 },  {  -31,  35,  18,  30 } } },  /* 214: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,  16,  28 },  {   -2,  26,  15,  27 },  {  -31,  33,  11,  31 } } },  /* 215: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   18,  25,   4,  21 },  {   -3,  26,   4,  21 },  {  -32,  30,   5,  25 } } },  /* 216: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -5,  36,  75,  18 },  {  -19,  38,  59,  19 },  {  -31,  47,  34,  25 } } },  /* 217: UPPER, BODY UPPER, ALEX B.D +1 */
    { { {    0,   0,   0,   0 },  {   13,  26,  68,  21 },  {   -9,  26,  62,  22 },  {  -28,  40,  37,  33 } } },  /* 218: UPPER, BODY UPPER, ALEX B.D +1 */
    { { {    0,   0,   0,   0 },  {  -12,  39,  54,  17 },  {  -20,  46,  36,  18 },  {  -32,  54,  18,  19 } } },  /* 219: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  39,  34,  21 },  {   11,  22,  21,  30 },  {  -29,  49,  14,  21 } } },  /* 220: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  39,  18,  21 },  {   11,  22,   0,  30 },  {  -29,  40,   0,  28 } } },  /* 221: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -13,  40,  77,  16 },  {  -18,  32,  58,  21 },  {  -21,  42,  32,  26 } } },  /* 222: DENKI */
    { { {    0,   0,   0,   0 },  {   -4,  46,  49,  20 },  {  -21,  51,  37,  15 },  {  -36,  57,  22,  18 } } },  /* 223: TOUKETSU A */
    { { {    0,   0,   0,   0 },  {  -16,  37,  13,  21 },  {  -17,  42,  34,  21 },  {  -17,  41,  55,  20 } } },  /* 224: BODY UPPER SP */
    { { {  -10,  23,  73,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -28,  64,   0,  32 } } },  /* 225: FRONT WALK */
    { { {  -10,  23,  75,  18 },  {  -23,  51,  60,  17 },  {  -21,  47,  33,  26 },  {  -21,  48,   0,  32 } } },  /* 226: FRONT WALK */
    { { {   -6,  23,  73,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -28,  64,   0,  32 } } },  /* 227: BACK WALK */
    { { {   -6,  23,  75,  18 },  {  -23,  51,  60,  17 },  {  -21,  47,  33,  26 },  {  -21,  48,   0,  32 } } },  /* 228: BACK WALK */
    { { {  -12,  23,  70,  18 },  {  -27,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -23,  58,   0,  32 } } },  /* 229: HURIMUKI */
    { { {  -12,  23,  70,  18 },  {  -25,  51,  60,  14 },  {  -25,  47,  33,  26 },  {  -26,  54,   0,  32 } } },  /* 230: HURIMUKI */
    { { {  -12,  24,  43,  20 },  {  -30,  52,  36,  18 },  {  -28,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 231: KAGAMI TURN */
    { { {  -12,  23,  58,  18 },  {  -23,  51,  45,  16 },  {  -21,  47,  23,  21 },  {  -34,  58,   0,  22 } } },  /* 232: STAND UP, DASH HUMIKOMI, DASH TOBINOKI +1 */
    { { {  -28,  23,  56,  18 },  {  -25,  46,  50,  20 },  {  -28,  52,  29,  20 },  {  -34,  58,   0,  28 } } },  /* 233: ATTACK 12 L: not started by a command, not started by a command, SP JUMP JUNBI */
    { { {  -17,  19,  96,  20 },  {  -29,  50,  92,  14 },  {  -20,  44,  77,  14 },  {  -30,  54,  46,  30 } } },  /* 234: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -18,  19,  92,  20 },  {  -21,  50,  89,  14 },  {  -16,  44,  77,  11 },  {  -30,  58,  40,  36 } } },  /* 235: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -16,  23,  69,  18 },  {  -22,  47,  56,  18 },  {  -26,  52,  30,  26 },  {  -39,  65,   0,  29 } } },  /* 236: PIYO */
    { { {  -10,  23,  65,  18 },  {  -22,  54,  54,  18 },  {  -22,  52,  26,  26 },  {  -35,  68,   0,  25 } } },  /* 237: PIYO */
    { { {  -10,  23,  73,  18 },  {  -23,  51,  60,  17 },  {  -21,  47,  33,  26 },  {  -34,  58,   0,  32 } } },  /* 238: KAMAE */
    { { {  -10,  23,  66,  18 },  {  -23,  51,  56,  17 },  {  -25,  51,  27,  27 },  {  -38,  66,   0,  26 } } },  /* 239: KAMAE */
    { { {  -16,  23,  65,  18 },  {  -23,  51,  56,  14 },  {  -25,  51,  29,  26 },  {  -38,  64,   0,  28 } } },  /* 240: DASH HUMIKOMI */
    { { {  -25,  23,  60,  18 },  {  -23,  44,  50,  14 },  {  -25,  49,  29,  20 },  {  -38,  64,   0,  28 } } },  /* 241: DASH HUMIKOMI */
    { { {  -31,  26,  72,  14 },  {  -32,  57,  65,  14 },  {  -32,  57,  35,  28 },  {  -36,  64,   0,  34 } } },  /* 242: DASH HUMIKOMI */
    { { {  -14,  23,  58,  18 },  {  -21,  46,  50,  12 },  {  -22,  52,  29,  20 },  {  -25,  58,   0,  28 } } },  /* 243: DASH HUMIKOMI */
    { { {  -20,  23,  72,  18 },  {  -27,  48,  60,  14 },  {  -21,  47,  33,  26 },  {  -22,  48,   0,  32 } } },  /* 244: DASH TOBINOKI */
    { { {    7,  23,  65,  18 },  {  -21,  48,  60,  14 },  {  -21,  45,  33,  26 },  {  -36,  57,   0,  32 } } },  /* 245: DASH TOBINOKI */
    { { {   35,  23,  53,  18 },  {  -21,  56,  60,  14 },  {  -44,  78,  41,  18 },  {  -52,  73,   0,  40 } } },  /* 246: DASH TOBINOKI */
    { { {   13,  23,  21,  18 },  {    8,  29,  39,  31 },  {  -58,  64,  41,  28 },  {  -21,  73,   0,  40 } } },  /* 247: DASH TOBINOKI */
    { { {  -15,  23,  11,  18 },  {  -21,  43,  28,  19 },  {  -21,  43,  48,  38 },  {  -21,  43,   0,  27 } } },  /* 248: DASH TOBINOKI */
    { { {  -52,  23,  43,  18 },  {  -33,  53,  27,  42 },  {  -21,  68,  27,  52 },  {  -21,  43,   0,  26 } } },  /* 249: DASH TOBINOKI */
    { { {  -55,  23,  56,  18 },  {  -33,  22,  44,  31 },  {  -21,  47,  27,  47 },  {  -21,  43,   0,  26 } } },  /* 250: DASH TOBINOKI */
    { { {  -40,  23,  69,  18 },  {  -29,  51,  60,  20 },  {  -21,  47,  31,  29 },  {  -21,  56,   0,  30 } } },  /* 251: DASH TOBINOKI */
    { { {  -10,  23,  70,  18 },  {  -23,  51,  60,  14 },  {  -21,  47,  33,  26 },  {  -22,  49,   0,  32 } } },  /* 252: DASH TOBINOKI */
    { { {  -12,  23,  66,  18 },  {  -23,  51,  58,  14 },  {  -27,  53,  29,  28 },  {  -38,  62,   0,  28 } } },  /* 253: DASH HUMIKOMI, DASH TOBINOKI */
    { { {   -4,  24,  41,  20 },  {  -24,  52,  34,  18 },  {  -28,  55,  19,  15 },  {  -42,  73,   0,  19 } } },  /* 254: KAGAMI K A, follow-up of WIN 5 */
    { { {   -5,  24,  42,  20 },  {  -24,  52,  36,  18 },  {  -28,  55,  19,  17 },  {  -34,  63,   0,  19 } } },  /* 255: KAGAMI K A, follow-up of WIN 5 */
    { { {  -18,  24,  41,  16 },  {  -35,  52,  36,  11 },  {  -51,  72,  19,  17 },  {  -49,  67,   0,  19 } } },  /* 256: KAGAMI K A, follow-up of WIN 6 */
};

const HAND_BOX yun_hand_box[76] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -51,  25,  36,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -96,  61,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: KAGAMI K A, follow-up of WIN 6 */
    { { {  -78,  60,  56,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M KICK A, follow-up of APPEAR USE, follow-up of S KICK A */
    { { { -113,  78,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: KAGAMI K A, follow-up of WIN 6 */
    { { {  -66,  32,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -52,  40,  78,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: not started by a command */
    { { {  -64,  28,  58,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -58,  28,  62,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP), not started by a command */
    { { {  -80,  66,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {  -68,  55,  45,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name */
    { { {  -61,  40,  51,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH A, follow-up of ZANNEN 4 */
    { { {  -63,  53,  49,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +3 */
    { { {  -43,  22,  50,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH B, follow-up of follow-up of S PUNCH A, S PUNCH B, no name +1 */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L PUNCH A, follow-up of JUDGMENT WAIT */
    { { {  -70,  54,  43,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH B, follow-up of ZANNEN 6 */
    { { {  -66,  24,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: follow-up of M PUNCH A, M PUNCH B */
    { { {  -72,  49,   0,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: S KICK A, follow-up of S PUNCH A, S PUNCH B, follow-up of ZANNEN 7 */
    { { {  -80,  62,  53,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: M KICK C, follow-up of JUDGMENT WAIT, no name */
    { { {  -80,  62,  41,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: M KICK C, follow-up of JUDGMENT WAIT */
    { { {  -67,  62,  30,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M KICK C, follow-up of JUDGMENT WAIT, follow-up of SP WIN 5 */
    { { {  -78,  56,  45,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: follow-up of WIN 2, KAGAMI P A, follow-up of WIN 3 */
    { { {  -69,  41,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A, follow-up of KAGAMI P A, follow-up of WIN 4 */
    { { {  -82,  65,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI K A, follow-up of WIN 5 */
    { { {  -77,  27,   0,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: not used by a script */
    { { {  -73,  34,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: not used by a script */
    { { {  -79,  60,  81,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P L A, follow-up of V JUMP P S A, F JUMP P S A, follow-up of JUDGMENT LOSE +1 */
    { { {    0,   0,   6,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +3 */
    { { {  -61,  50,  54,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP K L A, F JUMP K L A, follow-up of AFRICA LAND +2 */
    { { {  -60,  49,  36,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU), ATTACK 4 L: 236+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -73,  53,  49,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 12 M: not started by a command, ATTACK 4 S: 236+P light (routine Att_SENPUUKYAKU), ATTACK 4 M: 236+P medium (routine Att_SENPUUKYAKU) +2 */
    { { {  -83,  62,  51,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: follow-up of APPEAR USE, ATTACK 5 S: not started by a command, ATTACK 8 S: after SA II 23623+P (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -46,  24,  68,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 5 S: not started by a command, ATTACK 13 SP: not started by a command */
    { { {  -46,  26,  61,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP P S A, follow-up of SEAN BALL HIT, V JUMP P S A +1 */
    { { {  -58,  36,  56,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P M A, F JUMP P M A, follow-up of JUDGMENT LOSE +3 */
    { { {  -52,  30,  76,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P M A, F JUMP P M A, F JUMP P L A +5 */
    { { {  -36,  17,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -36,  15,  71,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -68,  36,  58,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {  -56,  28,  48,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: not used by a script */
    { { {  -46,  22,  24,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: not used by a script */
    { { {  -83,  65,  67,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP K S A, F JUMP K S A, follow-up of WAIT +2 */
    { { {  -20,  49,  20,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: F JUMP K M B, F JUMP K L B, follow-up of BONUS WIN 3 +2 */
    { { {  -54,  23,  62,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command, TUKAMIKAKARI A */
    { { {  -46,  32,  56,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: TUKAMIKAKARI A, ATTACK 9 S: 6(123)4+K (plain script), ATTACK 13 L: not started by a command */
    { { {  -85,  21,  43,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: L KICK A, follow-up of follow-up of S KICK A, no name +1 */
    { { {  -84,  73,  44,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: not used by a script */
    { { {  -56,  46,  42,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: follow-up of follow-up of M PUNCH A, M PUNCH B, ATTACK 2 S: 214+P light/medium/heavy (plain script), ATTACK 11 M: not started by a command */
    { { {  -75,  52,  35,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -90,  62,  34,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP K M A, F JUMP K M A, follow-up of AFRICA JUMP +1 */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: not used by a script */
    { { {  -82,  64,  69,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: not used by a script */
    { { {  -57,  46,  53,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: not used by a script */
    { { {  -78,  37,  46,  19 },  {   -7,  44,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: L PUNCH C, follow-up of APPEAR USE */
    { { {  -52,  15,  51,  14 },  {   17,  11,  54,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: L PUNCH C, follow-up of APPEAR USE */
    { { {  -59,  24,  51,  14 },  {   18,  20,  50,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: L PUNCH C, follow-up of APPEAR USE, ATTACK 7 S: SA II 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -39,  12,  81,  17 },  {   15,   9,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: M KICK B, follow-up of ZANNEN 8 */
    { { {  -59,  20,  71,   9 },  {   15,   9,  44,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: M KICK B, follow-up of ZANNEN 8 */
    { { {  -40,  16,  58,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: M KICK B, follow-up of ZANNEN 8 */
    { { {  -93,  34,  68,  19 },  {  -67,  33,  57,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: M KICK B, follow-up of ZANNEN 8 */
    { { {  -56,  12,  51,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: M KICK B, follow-up of ZANNEN 8 */
    { { {  -57,  35,  69,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    { { {  -57,  36,  56,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -52,  31,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: S PUNCH A, follow-up of ZANNEN 2 */
    { { {  -69,  57,  35,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: follow-up of WIN 7, KAGAMI K A */
    { { {  -91,  62,  23,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: follow-up of WIN 7, KAGAMI K A */
    { { {  -97,  68,  15,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: follow-up of WIN 7, KAGAMI K A */
    { { {  -97,  61,   0,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: follow-up of WIN 7, KAGAMI K A */
    { { {  -82,  46,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: follow-up of WIN 7, KAGAMI K A */
    { { {  -97,  42,  57,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: not used by a script */
    { { {  -88,  42,  56,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: S PUNCH B, follow-up of ZANNEN 3 */
    { { {  -75,  30,  61,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: S PUNCH B, follow-up of ZANNEN 3 */
    { { {  -48,  20,  58,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: S PUNCH B, follow-up of ZANNEN 3 */
    { { {  -55,  42,  30,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 12 L: not started by a command, not started by a command */
    { { {  -42,  32,  66,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 3 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 3 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 3 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
};

const HOSEI_BOX yun_hos_box[22] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   70 } },  /* 1: no name, HURIMUKI, DASH HUMIKOMI +132 */
    { {  -21,   42,    0,   48 } },  /* 2: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +56 */
    { {  -20,   40,   51,   44 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +48 */
    { {  -21,   42,   41,   37 } },  /* 4: M KICK C, follow-up of JUDGMENT WAIT, follow-up of APPEAR USE +5 */
    { {  -32,   46,   36,   36 } },  /* 5: not used by a script */
    { {  -44,   46,   36,   36 } },  /* 6: not used by a script */
    { {  -41,   46,   36,   36 } },  /* 7: not used by a script */
    { {  -21,   60,    0,   54 } },  /* 8: not used by a script */
    { {  -21,   57,    0,   54 } },  /* 9: L PUNCH C, follow-up of APPEAR USE, ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) +6 */
    { {  -21,   42,    0,   62 } },  /* 10: UPPER L, BODY UPPER L, FACE S +17 */
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
};
