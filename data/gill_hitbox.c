/*
 * GILL_HITBOX.C  Gill's hit boxes
 *
 * Each of Gill's animation frames names an entry of gill_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX gill_hit_ix_table[216] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +14 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +63 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    {    3,    0,    0, 0x0000,    0,    6,    0,    9 },  /* 3: not used by a script */
    {    4,    0,    0, 0x0000,    0,    6,    0,    9 },  /* 4: DASH HUMIKOMI, no name */
    {    5,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 5: not used by a script */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: DASH TOBINOKI, ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: DASH HUMIKOMI, DASH TOBINOKI */
    {    8,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: GUARD AIR, V JUMP P M A, V JUMP P L A +10 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 9: ATTACK 8 M: SA I (never)+P (routine Att_RESURRECTION); SA II (never)+P (routine Att_RESURRECTION); SA III (never)+P (routine Att_RESURRECTION) */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 10: not used by a script */
    {   11,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 11: S PUNCH A */
    {   11,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 12: S PUNCH A */
    {   12,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 13: M PUNCH C, L PUNCH A */
    {   12,    0,    0, 0x0000,    0,    1,    2,    1 },  /* 14: P BREAK AIR F, TUKAMIHAZUSI, M PUNCH C */
    {   96,    0,   24, 0x0000,    0,    1,    3,    1 },  /* 15: M PUNCH C */
    {   13,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 16: M PUNCH C */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 17: S KICK A */
    {   19,    0,    0, 0x0000,    0,    1,    7,    1 },  /* 18: S KICK A */
    {   21,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 19: M KICK A, M KICK C */
    {   22,    0,    6, 0x0000,    0,    1,    8,    1 },  /* 20: M KICK A, M KICK C */
    {   22,    0,    6, 0x0000,    0,    1,    9,    1 },  /* 21: M KICK A, M KICK C */
    {   22,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 22: M KICK A, M KICK C */
    {   23,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: L KICK A */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 24: L KICK A */
    {   88,    0,   21, 0x0000,    0,    1,   38,    1 },  /* 25: L KICK A */
    {   25,    0,    7, 0x0000,    0,    1,   39,    1 },  /* 26: L KICK A */
    {   26,    0,    8, 0x0000,    0,    1,   40,    1 },  /* 27: L KICK A */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 28: L KICK A */
    {   31,    0,    9, 0x0000,    0,    5,   13,    2 },  /* 29: KAGAMI P A, no name */
    {   31,    0,    9, 0x0000,    0,    5,    0,    2 },  /* 30: KAGAMI P A, no name */
    {   33,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 31: KAGAMI P A */
    {   34,    0,   11, 0x0000,    0,    5,   15,    2 },  /* 32: KAGAMI K A */
    {   34,    0,   11, 0x0000,    0,    2,   41,    2 },  /* 33: not used by a script */
    {   29,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 34: not used by a script */
    {   30,    0,    0, 0x0000,    0,    1,   12,    5 },  /* 35: not used by a script */
    {   30,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 36: not used by a script */
    {   31,    0,    9, 0x0000,    0,    2,   10,    2 },  /* 37: KAGAMI P A, no name */
    {   32,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 38: KAGAMI P A */
    {   32,    0,    0, 0x0000,    0,    2,   14,    2 },  /* 39: KAGAMI P A */
    {   33,    0,   10, 0x0000,    0,    1,   11,    1 },  /* 40: KAGAMI P A */
    {   34,    0,   11, 0x0000,    0,    5,    0,    2 },  /* 41: KAGAMI K A */
    {   35,    0,   12, 0x0000,    0,    2,   42,    2 },  /* 42: KAGAMI K A */
    {   35,    0,   12, 0x0000,    0,    2,    0,    2 },  /* 43: KAGAMI K A */
    {   89,    0,   22, 0x0000,    0,    3,   44,    3 },  /* 44: V JUMP P L A */
    {   89,    0,   22, 0x0000,    0,    3,    0,    3 },  /* 45: V JUMP P L A */
    {   89,    0,   22, 0x0000,    0,    3,   16,    3 },  /* 46: V JUMP P L A */
    {   87,    0,   20, 0x0000,    0,    3,   18,    3 },  /* 47: V JUMP P M A */
    {   86,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 48: V JUMP P M A, V JUMP P L A */
    {   87,    0,   20, 0x0000,    0,    3,   43,    3 },  /* 49: V JUMP P M A */
    {   87,    0,   20, 0x0000,    0,    3,    0,    3 },  /* 50: V JUMP P M A */
    {   49,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 51: V JUMP K S A, V JUMP K M A */
    {   49,    0,    0, 0x0000,    0,    3,   19,    3 },  /* 52: V JUMP K S A */
    {   40,    0,   15, 0x0000,    0,    3,   21,    3 },  /* 53: V JUMP K M A */
    {   40,    0,   15, 0x0000,    0,    3,   22,    3 },  /* 54: V JUMP K M A, ATTACK 4 M: not started by a command */
    {   91,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 55: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    {   92,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 56: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) +3 */
    {   93,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 57: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 4 M: not started by a command */
    {   94,    0,   23, 0x0000,    0,    3,   45,    3 },  /* 58: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    {   90,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 59: FRONT WALK, BACK WALK */
    {   47,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 60: V JUMP P S A, V JUMP P M A, V JUMP P L A +4 */
    {   48,    0,    0, 0x0000,    0,    3,   17,    3 },  /* 61: V JUMP P S A */
    {   52,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 62: follow-up of APPEAR JUNBI 6 */
    {   53,    0,    0, 0x0000,    0,    1,   25,    1 },  /* 63: follow-up of APPEAR JUNBI 6 */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 64: not used by a script */
    {   54,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 65: not used by a script */
    {   55,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 66: not used by a script */
    {   56,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 67: follow-up of APPEAR JUNBI 6 */
    {   57,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 68: not used by a script */
    {   58,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 69: not used by a script */
    {   59,    0,    0, 0x0000,    0,    3,   26,    3 },  /* 70: not used by a script */
    {    8,    0,    0, 0x0000,    0,    3,   27,    3 },  /* 71: not used by a script */
    {   30,    0,    0, 0x0000,    0,    1,   28,    5 },  /* 72: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,   29,    1 },  /* 73: not used by a script */
    {    1,    0,    0, 0x0000,    1,    1,   30,    1 },  /* 74: TUKAMIKAKARI A */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 75: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: ATTACK 3 M: 236+P light (plain script) */
    {   64,    0,    0, 0x0000,    0,    4,    0,    7 },  /* 77: ATTACK 3 M: 236+P light (plain script) */
    {   65,    0,    0, 0x0000,    0,    4,    0,    7 },  /* 78: ATTACK 3 M: 236+P light (plain script) */
    {   66,    0,    0, 0x0000,    0,    4,    0,    7 },  /* 79: ATTACK 3 M: 236+P light (plain script) */
    {   67,    0,    0, 0x0000,    0,    4,    0,    7 },  /* 80: ATTACK 3 L: 236+P medium (plain script) */
    {   68,    0,    0, 0x0000,    0,    4,    0,    7 },  /* 81: ATTACK 3 SP: 236+P heavy/EX (plain script) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 82: NEKOROBI S, OKIAGARI, OKIAGARI F +10 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 83: follow-up of AIR NORMAL, ATTACK 10 M: not started by a command */
    {   69,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 84: not used by a script */
    {   70,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: PIYO */
    {   71,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 86: not used by a script */
    {   72,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 87: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   73,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 88: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   74,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 89: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   75,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 90: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   75,    0,    0, 0x0000,    0,    3,   31,    3 },  /* 91: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   76,    0,    0, 0x0000,    0,    3,   32,    3 },  /* 92: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   76,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 93: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   77,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 94: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    {   78,    0,    0, 0x0000,    0,    0,   33,    0 },  /* 95: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 96: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   80,    0,   19, 0x0000,    0,    1,   34,    1 },  /* 97: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   81,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 98: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   82,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 99: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   83,    0,    0, 0x0000,    0,    3,   35,    3 },  /* 100: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   83,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 101: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    {   84,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: not used by a script */
    {   85,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 103: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 104: follow-up of APPEAR 2 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 105: follow-up of APPEAR 2 */
    {   14,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 106: M PUNCH A */
    {   14,    0,    3, 0x0000,    0,    1,   37,    1 },  /* 107: M PUNCH A */
    {   14,    0,    3, 0x0000,    0,    1,   37,    1 },  /* 108: M PUNCH A */
    {   15,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 109: L PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 110: L PUNCH A */
    {   17,    0,    4, 0x0000,    0,    1,    5,    1 },  /* 111: L PUNCH A */
    {   17,    0,    4, 0x0000,    0,    1,    6,    1 },  /* 112: L PUNCH A */
    {   17,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 113: L PUNCH A */
    {   41,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   42,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 115: V JUMP K L A */
    {   43,    0,   16, 0x0000,    0,    3,   24,    3 },  /* 116: V JUMP K L A */
    {   43,    0,   16, 0x0000,    0,    3,   24,    3 },  /* 117: V JUMP K L A */
    {   43,    0,   16, 0x0000,    0,    3,    0,    3 },  /* 118: V JUMP K L A */
    {   44,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 119: V JUMP K L A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 120: not used by a script */
    {   78,    0,    0, 0x0000,    0,    0,   33,    1 },  /* 121: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 122: PARING AIR F, GUARD AIR */
    {    2,    0,    0, 0x0000,    0,    2,    0,   10 },  /* 123: KAGAMI P A, no name */
    {   97,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 124: TUKAMIHAZUSI, no name, BODY SLAM +8 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 125: ATTACK 9 L: SA (all arts) 23623+P (plain script), ATTACK 10 M: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,   10 },  /* 126: ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    {   98,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 127: no name */
    {   99,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 128: UPPER L */
    {  100,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 129: UPPER L */
    {  101,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 130: UPPER L */
    {  102,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 131: UPPER L */
    {  103,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 132: FACE S, FACE M, FACE L +3 */
    {  104,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 133: FACE M, FACE L, FOOK OKU L +5 */
    {  105,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 134: FACE L, FOOK OKU L, FOOK OKU SP */
    {  106,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 135: FACE L, FOOK OKU SP */
    {  107,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 136: NOUTEN S, BODY BROW M, BODY BROW L +8 */
    {  108,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 137: BODY BROW M, BODY BROW L */
    {  109,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 138: not used by a script */
    {  110,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 139: not used by a script */
    {  111,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 140: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    {  112,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 141: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    {  113,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 142: KAGAMI L */
    {  114,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 143: KAGAMI L */
    {    7,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 144: not used by a script */
    {  115,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 145: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  116,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 146: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  117,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 147: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  118,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 148: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  119,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 149: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  120,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 150: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  121,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 151: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  122,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 152: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    {  123,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 153: AIR NORMAL, ASIB TUNNOMERI, HUMI ASIB */
    {  124,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 154: AIR NORMAL, ASIB TUNNOMERI, NOKEZORI +7 */
    {  125,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 155: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  126,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 156: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  127,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 157: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  128,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 158: ASIBARAI SIRI, KUNOJI, HARAYARARE */
    {  129,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 159: ASIB TUNNOMERI, HUMI ASIB */
    {  130,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 160: ASIB TUNNOMERI, HUMI ASIB */
    {  131,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 161: ASIB TUNNOMERI, HUMI ASIB */
    {  132,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 162: ASIB TUNNOMERI, HUMI ASIB */
    {  133,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 163: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  134,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 164: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  135,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 165: NOKEZORI, KIRIMOMI, UPPER +3 */
    {  136,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 166: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  137,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 167: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  138,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 168: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  139,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 169: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  140,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 170: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    {  141,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 171: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    {  142,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 172: DENKI */
    {  143,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 173: not used by a script */
    {  144,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 174: not used by a script */
    {  145,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 175: TOUKETSU A */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 176: ATTACK 7 M: not started by a command */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 177: KAMAE */
    {  146,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 178: KAMAE */
    {  146,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 179: KAMAE */
    {  147,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 180: HURIMUKI */
    {  148,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 181: FRONT WALK */
    {  149,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 182: FRONT WALK */
    {  150,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 183: FRONT WALK */
    {  151,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 184: FRONT WALK */
    {  152,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 185: FRONT WALK */
    {  153,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 186: BACK WALK */
    {  154,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 187: BACK WALK */
    {  155,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 188: BACK WALK */
    {  156,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 189: BACK WALK */
    {  157,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 190: BACK WALK */
    {  158,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 191: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +1 */
    {  159,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 192: DASH HUMIKOMI */
    {  160,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 193: DASH HUMIKOMI */
    {  161,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 194: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    {  162,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 195: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    {  163,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 196: DASH TOBINOKI, KAGAMU */
    {  164,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 197: DASH TOBINOKI */
    {  165,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 198: not used by a script */
    {  167,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 199: not used by a script */
    {  167,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 200: not used by a script */
    {  168,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 201: not used by a script */
    {  168,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 202: not used by a script */
    {  170,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 203: KAGAMI TURN */
    {  171,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 204: KAGAMI TURN */
    {  172,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 205: JUMP JUNBI */
    {  173,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 206: SP JUMP JUNBI */
    {   92,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 207: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  174,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 208: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  175,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 209: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  175,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 210: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
    {   70,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 211: PIYO */
    {  169,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 212: PIYO */
    {  169,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 213: PIYO */
    {  166,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 214: DASH TOBINOKI */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 215: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
};

const BODY_BOX gill_body_box[176] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -21,  27, 102,  18 },  {  -35,  66,  79,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +66 */
    { { {  -12,  28,  54,  20 },  {  -32,  70,  44,  16 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    { { {  -50,  22,  92,  18 },  {  -38,  60,  94,  12 },  {  -32,  60,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 3: not used by a script */
    { { {  -34,  22,  86,  18 },  {  -28,  52,  81,  16 },  {  -28,  52,  41,  39 },  {  -32,  72,   0,  40 } } },  /* 4: DASH HUMIKOMI, no name */
    { { {  -16,  22,  74,  18 },  {  -28,  52,  33,  16 },  {  -24,  48,  44,  20 },  {  -32,  72,   0,  44 } } },  /* 5: not used by a script */
    { { {   -2,  22, 113,  18 },  {  -18,  60,  94,  19 },  {  -23,  62,  51,  43 },  {  -32,  72,   0,  50 } } },  /* 6: DASH TOBINOKI, ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -22,  22,  90,  18 },  {  -26,  64,  85,  12 },  {  -26,  66,  41,  42 },  {  -32,  72,   0,  40 } } },  /* 7: DASH HUMIKOMI, DASH TOBINOKI, ATTACK 7 M: not started by a command */
    { { {   -8,  24, 118,  18 },  {  -26,  62, 106,  16 },  {  -22,  46,  62,  42 },  {  -12,  44,  28,  36 } } },  /* 8: GUARD AIR, V JUMP P M A, V JUMP P L A +10 */
    { { {  -32,  22, 106,  18 },  {  -28,  56,  92,  24 },  {  -20,  44,  50,  44 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {  -48,  22,  92,  18 },  {  -28,  56,  88,  28 },  {  -32,  60,  50,  38 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -18,  24, 102,  18 },  {  -40,  68,  92,  14 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 11: S PUNCH A */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 12: M PUNCH C, L PUNCH A, P BREAK AIR F +1 */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 13: M PUNCH C */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 14: M PUNCH A */
    { { {   -2,  24, 100,  18 },  {  -32,  76,  92,  14 },  {  -20,  52,  52,  38 },  {  -34,  70,   0,  50 } } },  /* 15: L PUNCH A */
    { { {  -44,  40, 100,  16 },  {  -40,  68,  88,  14 },  {  -32,  52,  48,  38 },  {  -36,  78,   0,  46 } } },  /* 16: L PUNCH A */
    { { {  -34,  50,  80,  22 },  {  -50,  70,  54,  24 },  {  -30,  56,  40,  24 },  {  -40,  92,   0,  40 } } },  /* 17: L PUNCH A */
    { { {  -10,  22, 102,  18 },  {  -32,  64,  94,  12 },  {  -32,  64,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 18: not used by a script */
    { { {  -34,  24,  98,  18 },  {  -44,  66,  88,  14 },  {  -30,  46,  50,  36 },  {  -52,  60,   0,  48 } } },  /* 19: S KICK A */
    { { {  -15,  19, 103,  16 },  {  -27,  51,  94,  12 },  {  -20,  30,  41,  52 },  {  -22,  41,   0,  40 } } },  /* 20: not used by a script */
    { { {   -2,  24,  98,  18 },  {  -40,  68,  88,  14 },  {  -26,  52,  52,  38 },  {  -14,  36,   0,  50 } } },  /* 21: M KICK A, M KICK C */
    { { {   -8,  32,  96,  18 },  {  -58,  92,  70,  24 },  {  -34,  38,  50,  26 },  {  -16,  34,   0,  48 } } },  /* 22: M KICK A, M KICK C */
    { { {  -12,  24, 104,  18 },  {  -24,  68,  92,  14 },  {  -22,  50,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 23: L KICK A */
    { { {   -2,  24, 106,  18 },  {  -26,  68,  94,  14 },  {  -22,  60,  58,  34 },  {   -8,  34,   0,  56 } } },  /* 24: L KICK A */
    { { {   10,  24,  96,  18 },  {  -20,  68,  86,  14 },  {  -44,  76,  56,  30 },  {  -10,  34,   0,  54 } } },  /* 25: L KICK A */
    { { {   16,  24,  94,  18 },  {   -8,  68,  84,  14 },  {  -28,  78,  60,  24 },  {  -14,  34,   0,  58 } } },  /* 26: L KICK A */
    { { {   20,  28,  94,  18 },  {  -16,  78,  66,  30 },  {  -44,  58,  36,  32 },  {  -12,  34,   0,  40 } } },  /* 27: L KICK A */
    { { {   20,  22,  96,  18 },  {  -12,  72,  78,  24 },  {  -36,  80,  41,  36 },  {  -16,  48,   0,  40 } } },  /* 28: not used by a script */
    { { {   -8,  22, 106,  18 },  {  -24,  60,  94,  12 },  {  -24,  60,  41,  52 },  {  -12,  48,   0,  40 } } },  /* 29: not used by a script */
    { { {  -30,  22, 108,  18 },  {  -16,  56, 100,  28 },  {  -24,  64,  48,  52 },  {    0,   0,   0,   0 } } },  /* 30: not used by a script */
    { { {  -24,  32,  54,  18 },  {  -44,  70,  44,  14 },  {  -32,  76,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 31: KAGAMI P A, no name */
    { { {  -20,  26,  70,  18 },  {  -34,  56,  60,  14 },  {  -46,  76,  36,  22 },  {  -44,  88,   0,  34 } } },  /* 32: KAGAMI P A */
    { { {  -16,  24, 100,  18 },  {  -26,  54,  88,  14 },  {  -22,  48,  36,  50 },  {  -38,  82,   0,  34 } } },  /* 33: KAGAMI P A */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 34: KAGAMI K A */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 35: KAGAMI K A */
    { { {  -18,  19, 107,  16 },  {  -24,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {   -2,  40, 106,  16 },  {  -18,  60,  88,  22 },  {  -36,  82,  66,  30 },  {   -6,  40,  48,  22 } } },  /* 40: V JUMP K M A, ATTACK 4 M: not started by a command */
    { { {   -2,  24, 110,  18 },  {  -32,  66, 102,  14 },  {  -28,  56,  76,  26 },  {  -24,  56,  42,  32 } } },  /* 41: V JUMP K L A */
    { { {  -12,  24, 110,  18 },  {  -20,  54, 102,  20 },  {  -32,  66,  78,  24 },  {  -40,  76,  58,  24 } } },  /* 42: V JUMP K L A */
    { { {  -34,  24, 108,  18 },  {  -24,  54, 102,  20 },  {  -40,  68,  78,  24 },  {  -52,  90,  60,  26 } } },  /* 43: V JUMP K L A */
    { { {  -30,  28, 112,  18 },  {  -32,  60, 106,  14 },  {  -32,  56,  78,  26 },  {  -50,  62,  58,  28 } } },  /* 44: V JUMP K L A */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -32,  16, 106,  16 },  {  -23,  46,  96,  21 },  {  -16,  30,  57,  46 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -20,  24, 118,  18 },  {  -34,  66, 106,  14 },  {  -28,  56,  78,  26 },  {  -32,  64,  50,  26 } } },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +4 */
    { { {  -40,  24, 108,  18 },  {  -48,  72,  98,  14 },  {  -52,  86,  72,  24 },  {  -32,  60,  48,  26 } } },  /* 48: V JUMP P S A */
    { { {   -2,  40, 106,  16 },  {  -18,  60,  88,  22 },  {  -40,  86,  62,  24 },  {  -18,  50,  50,  18 } } },  /* 49: V JUMP K S A, V JUMP K M A */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {  -45,  29,  72,  12 } } },  /* 50: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {  -50,  28,  66,  24 } } },  /* 51: not used by a script */
    { { {  -32,  19,  86,  16 },  {  -26,  51,  68,  21 },  {  -20,  30,  44,  39 },  {  -22,  41,   0,  44 } } },  /* 52: follow-up of APPEAR JUNBI 6 */
    { { {  -39,  19,  71,  16 },  {  -18,  46,  65,  32 },  {  -20,  30,  44,  39 },  {  -22,  41,   0,  44 } } },  /* 53: follow-up of APPEAR JUNBI 6 */
    { { {   13,  11, 129,  16 },  {  -17,  46, 113,  21 },  {  -13,  30,  69,  46 },  {    0,   0,   0,   0 } } },  /* 54: not used by a script */
    { { {   40,  19,  97,  16 },  {    4,  35,  84,  44 },  {  -21,  30,  69,  46 },  {    0,   0,   0,   0 } } },  /* 55: not used by a script */
    { { {   11,  19,  55,  16 },  {   -6,  46,  70,  21 },  {  -32,  58,  85,  25 },  {    0,   0,   0,   0 } } },  /* 56: follow-up of APPEAR JUNBI 6 */
    { { {   -7,  19,  51,  16 },  {  -24,  46,  66,  21 },  {  -19,  41,  88,  34 },  {    0,   0,   0,   0 } } },  /* 57: not used by a script */
    { { {  -34,  19, 106,  16 },  {  -23,  28,  75,  36 },  {    6,  41,  85,  20 },  {    0,   0,   0,   0 } } },  /* 58: not used by a script */
    { { {  -18,  19, 117,  16 },  {  -24,  46,  98,  21 },  {  -20,  30,  59,  46 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -22,  19,  88,  16 },  {  -27,  51,  68,  21 },  {  -22,  32,  40,  39 },  {  -32,  64,   0,  44 } } },  /* 60: not used by a script */
    { { {  -64,  19,  72,  16 },  {  -45,  51,  68,  21 },  {  -32,  32,  40,  39 },  {  -48,  64,   0,  44 } } },  /* 61: not used by a script */
    { { {   -8,  24,  94,  18 },  {  -32,  68,  90,  14 },  {  -28,  52,  52,  36 },  {  -54,  94,   0,  50 } } },  /* 62: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { { {  -28,  62,  82,  18 },  {  -48,  86,  70,  14 },  {  -24,  60,  42,  28 },  {  -62, 102,   0,  44 } } },  /* 63: ATTACK 3 M: 236+P light (plain script) */
    { { {   -4,  52,  82,  18 },  {  -12,  58,  70,  14 },  {  -18,  58,  40,  28 },  {  -62, 102,   0,  44 } } },  /* 64: ATTACK 3 M: 236+P light (plain script) */
    { { {  -42,  68,  82,  18 },  {  -34,  66,  70,  14 },  {  -22,  58,  40,  28 },  {  -62, 102,   0,  44 } } },  /* 65: ATTACK 3 M: 236+P light (plain script) */
    { { {  -26,  24,  98,  18 },  {  -44,  68,  88,  14 },  {  -32,  52,  52,  38 },  {  -54,  94,   0,  50 } } },  /* 66: ATTACK 3 M: 236+P light (plain script) */
    { { {  -28,  62,  82,  18 },  {  -44,  82,  78,  14 },  {  -24,  60,  44,  32 },  {  -62, 102,   0,  44 } } },  /* 67: ATTACK 3 L: 236+P medium (plain script) */
    { { {  -28,  62,  82,  18 },  {  -38,  18,  94,  12 },  {  -22,  58,  44,  36 },  {  -62, 102,   0,  44 } } },  /* 68: ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { { {  -36,  22, 104,  18 },  {  -28,  56,  82,  28 },  {  -48,  64,  48,  34 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {  -11,  30, 102,  18 },  {  -30,  68,  94,  12 },  {  -30,  65,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 70: PIYO */
    { { {  -29,  33, 102,  18 },  {  -37,  63,  94,  12 },  {  -37,  65,  41,  52 },  {  -36,  74,   0,  40 } } },  /* 71: not used by a script */
    { { {  -26,  22,  84,  18 },  {  -32,  58,  82,  12 },  {  -24,  50,  40,  40 },  {  -36,  72,   0,  40 } } },  /* 72: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {   14,  22, 126,  18 },  {  -18,  58, 122,  12 },  {  -22,  50,  80,  40 },  {   -4,  44,  50,  20 } } },  /* 73: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {    0,   0,   0,   0 },  {  -36,  64,  96,  28 },  {  -36,  64,  64,  28 },  {    0,   0,   0,   0 } } },  /* 74: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {  -14,  22, 110,  18 },  {  -32,  56, 104,  16 },  {  -20,  42,  72,  30 },  {  -28,  46,  56,  24 } } },  /* 75: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { {    0,   0,   0,   0 },  {  -50,  64,  94,  20 },  {  -26,  42,  72,  14 },  {  -46,  60,  56,  24 } } },  /* 76: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), no name */
    { { {  -38,  22, 106,  18 },  {  -34,  58,  94,  20 },  {  -18,  36,  72,  24 },  {  -38,  50,  50,  28 } } },  /* 77: no name, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) */
    { { { -105,  22,  92,  18 },  { -109,  88,  82,  16 },  {  -99,  64,  40,  40 },  {  -53,  56,   0,  40 } } },  /* 78: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  18 },  {  -20,  44,  46,  34 },  {  -36,  78,   0,  46 } } },  /* 79: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  18 },  {  -20,  44,  46,  34 },  {  -36,  78,   0,  46 } } },  /* 80: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  22,  70,  18 },  {  -16,  56,  80,  18 },  {  -26,  54,  38,  40 },  {  -34,  82,   0,  36 } } },  /* 81: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {    8,  22, 104,  18 },  {  -24,  70,  92,  14 },  {  -16,  48,  60,  32 },  {   -4,  50,  32,  26 } } },  /* 82: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {  -44,  50,  94,  18 },  {  -64,  28,  70,  22 },  {  -38,  54,  68,  24 },  {  -40,  54,  40,  26 } } },  /* 83: ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) */
    { { {  -28,  22, 108,  18 },  {  -34,  60,  98,  20 },  {  -14,  38,  72,  24 },  {  -28,  48,  42,  28 } } },  /* 84: not used by a script */
    { { {   -8,  22, 118,  18 },  {  -24,  56,  98,  20 },  {  -22,  42,  70,  26 },  {  -14,  38,  28,  40 } } },  /* 85: not used by a script */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 86: V JUMP P M A, V JUMP P L A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 87: V JUMP P M A */
    { { {   -2,  24, 106,  18 },  {  -26,  68,  94,  14 },  {  -22,  60,  58,  34 },  {   -8,  34,   0,  56 } } },  /* 88: L KICK A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  56,  30 },  {   -4,  50,  48,  20 } } },  /* 89: V JUMP P L A */
    { { {  -20,  24, 104,  18 },  {  -36,  68,  92,  14 },  {  -30,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 90: FRONT WALK, BACK WALK */
    { { {   -8,  24, 118,  18 },  {  -24,  60, 108,  14 },  {  -22,  46,  70,  36 },  {  -16,  48,  42,  26 } } },  /* 91: JUMP FRONT, JUMP VERTICAL, JUMP BACK +6 */
    { { {  -24,  24, 110,  18 },  {  -32,  60, 106,  14 },  {  -16,  44,  70,  36 },  {  -30,  52,  44,  24 } } },  /* 92: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP) +7 */
    { { {  -46,  24,  94,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 93: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 4 M: not started by a command */
    { { {  -44,  42, 108,  18 },  {  -60,  92,  98,  14 },  {  -70, 108,  72,  24 },  {  -44,  77,  36,  36 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -20,  24, 116,  18 },  {  -44,  72, 108,  14 },  {  -40,  72,  80,  30 },  {  -46,  80,  62,  24 } } },  /* 95: PARING AIR F, GUARD AIR */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 96: M PUNCH C */
    { { {  -26,  53,  95,  17 },  {  -33,  67,  75,  30 },  {  -33,  67,  43,  32 },  {  -26,  53,  36,  16 } } },  /* 97: TUKAMIHAZUSI, no name, BODY SLAM +8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 98: no name */
    { { {   -5,  27, 106,  18 },  {  -31,  66,  79,  25 },  {  -29,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 99: UPPER L */
    { { {    3,  27, 105,  18 },  {  -28,  66,  79,  25 },  {  -30,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 100: UPPER L */
    { { {    7,  27, 104,  18 },  {  -26,  66,  79,  25 },  {  -31,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 101: UPPER L */
    { { {    9,  27, 103,  18 },  {  -25,  66,  79,  25 },  {  -32,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 102: UPPER L */
    { { {   -5,  27, 100,  18 },  {  -27,  66,  78,  25 },  {  -24,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 103: FACE S, FACE M, FACE L +3 */
    { { {    7,  27,  98,  18 },  {  -21,  66,  77,  25 },  {  -21,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 104: FACE M, FACE L, FOOK OKU L +5 */
    { { {   15,  27,  96,  18 },  {  -17,  66,  76,  25 },  {  -19,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 105: FACE L, FOOK OKU L, FOOK OKU SP */
    { { {   19,  27,  94,  18 },  {  -15,  66,  75,  25 },  {  -18,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 106: FACE L, FOOK OKU SP */
    { { {  -25,  27,  99,  18 },  {  -33,  66,  77,  25 },  {  -26,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 107: NOUTEN S, BODY BROW M, BODY BROW L +8 */
    { { {  -29,  27,  96,  18 },  {  -31,  66,  75,  25 },  {  -24,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 108: BODY BROW M, BODY BROW L */
    { { {  -33,  27,  93,  18 },  {  -29,  66,  73,  25 },  {  -22,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 109: not used by a script */
    { { {  -37,  27,  90,  18 },  {  -27,  66,  71,  25 },  {  -20,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 110: not used by a script */
    { { {   -6,  28,  54,  20 },  {  -30,  70,  44,  16 },  {  -43,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 111: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    { { {    0,  28,  54,  20 },  {  -28,  70,  44,  16 },  {  -42,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 112: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    { { {    6,  28,  54,  20 },  {  -26,  70,  44,  16 },  {  -41,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 113: KAGAMI L */
    { { {   12,  28,  54,  20 },  {  -24,  70,  44,  16 },  {  -40,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 114: KAGAMI L */
    { { {  -18,  26, 114,  18 },  {  -30,  52, 100,  18 },  {  -24,  40,  70,  30 },  {  -18,  42,  44,  28 } } },  /* 115: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -32,  26, 114,  18 },  {  -30,  52, 100,  18 },  {  -24,  40,  70,  30 },  {  -30,  42,  44,  28 } } },  /* 116: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -42,  26, 108,  18 },  {  -32,  46, 100,  18 },  {  -24,  40,  70,  30 },  {  -40,  42,  46,  28 } } },  /* 117: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -44,  26, 102,  18 },  {  -34,  44, 100,  18 },  {  -28,  40,  70,  30 },  {  -42,  42,  48,  28 } } },  /* 118: ATTACK 9 SP: SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -26,  26,  82,  20 },  {  -32,  66,  72,  22 },  {  -16,  44,  48,  28 },  {  -32,  70,   0,  48 } } },  /* 119: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -52,  26,  56,  20 },  {  -46,  64,  62,  24 },  {  -36,  62,  40,  24 },  {  -50,  96,   0,  40 } } },  /* 120: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -16,  26,  88,  20 },  {  -30,  66,  72,  20 },  {  -20,  50,  48,  26 },  {  -26,  62,   0,  50 } } },  /* 121: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {  -18,  27,  96,  20 },  {  -30,  66,  78,  22 },  {  -24,  50,  52,  32 },  {  -26,  62,   0,  50 } } },  /* 122: ATTACK 10 S: after SA (all arts) 23623+K (routine Att_JYOUKA) */
    { { {    2,  29, 101,  19 },  {  -15,  49,  75,  30 },  {  -19,  43,  51,  24 },  {  -25,  51,  35,  16 } } },  /* 123: AIR NORMAL, ASIB TUNNOMERI, HUMI ASIB */
    { { {    2,  29, 102,  19 },  {  -31,  59,  83,  30 },  {  -36,  46,  59,  24 },  {  -34,  52,  38,  21 } } },  /* 124: AIR NORMAL, ASIB TUNNOMERI, NOKEZORI +7 */
    { { {  -15,  27,  91,  17 },  {  -18,  71,  71,  29 },  {    0,  48,  51,  20 },  {  -20,  62,  30,  31 } } },  /* 125: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {  -33,  24,  86,  17 },  {  -26,  59,  70,  30 },  {   -6,  30,  54,  26 },  {  -35,  46,  40,  30 } } },  /* 126: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {  -27,  24,  89,  17 },  {  -20,  45,  70,  30 },  {  -20,  36,  50,  20 },  {  -42,  33,  50,  36 } } },  /* 127: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {   18,  24,  86,  17 },  {    5,  38,  55,  30 },  {  -20,  36,  49,  26 },  {  -33,  31,  56,  42 } } },  /* 128: ASIBARAI SIRI, KUNOJI, HARAYARARE */
    { { {  -56,  26,  39,  22 },  {  -51,  39,  30,  35 },  {  -41,  48,  50,  30 },  {  -12,  49,  35,  38 } } },  /* 129: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -17,  26,  23,  22 },  {  -32,  46,  31,  35 },  {  -28,  48,  52,  30 },  {    0,  33,  47,  42 } } },  /* 130: ASIB TUNNOMERI, HUMI ASIB */
    { { {   11,  32,  15,  21 },  {  -15,  50,   4,  31 },  {  -22,  38,  22,  28 },  {  -13,  51,  39,  30 } } },  /* 131: ASIB TUNNOMERI, HUMI ASIB */
    { { {   31,  32,  -2,  21 },  {   -8,  53, -10,  31 },  {  -23,  42,   9,  28 },  {  -36,  47,  22,  37 } } },  /* 132: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -46,  23,  90,  19 },  {  -38,  51,  85,  30 },  {  -10,  35,  67,  35 },  {  -28,  53,  47,  32 } } },  /* 133: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {  -45,  23,  95,  19 },  {  -41,  56,  91,  33 },  {  -24,  42,  72,  31 },  {  -37,  49,  47,  36 } } },  /* 134: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {  -13,  25, 114,  19 },  {  -34,  49,  87,  32 },  {  -38,  42,  65,  31 },  {  -37,  47,  38,  36 } } },  /* 135: NOKEZORI, KIRIMOMI, UPPER +3 */
    { { {   25,  31, 107,  19 },  {   -4,  55,  86,  30 },  {  -21,  46,  71,  25 },  {  -42,  53,  53,  31 } } },  /* 136: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {   38,  30,  83,  21 },  {    3,  42,  66,  45 },  {  -21,  29,  59,  43 },  {  -55,  41,  51,  40 } } },  /* 137: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   38,  30,  76,  21 },  {    3,  42,  60,  45 },  {  -21,  29,  57,  43 },  {  -55,  41,  54,  40 } } },  /* 138: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   52,  30,  65,  21 },  {   10,  42,  52,  39 },  {  -20,  35,  62,  34 },  {  -38,  37,  67,  37 } } },  /* 139: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   37,  30,  54,  21 },  {    8,  42,  38,  39 },  {  -15,  40,  56,  34 },  {  -27,  38,  73,  36 } } },  /* 140: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    { { {   27,  30,  36,  21 },  {   -8,  42,  31,  36 },  {  -24,  41,  47,  32 },  {  -25,  48,  71,  26 } } },  /* 141: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    { { {  -20,  28, 113,  17 },  {  -33,  51,  90,  24 },  {  -43,  48,  66,  29 },  {  -39,  53,  36,  30 } } },  /* 142: DENKI */
    { { {  -49,  32,  73,  20 },  {  -43,  60,  80,  28 },  {  -39,  56,  53,  34 },  {    0,   0,   0,   0 } } },  /* 143: not used by a script */
    { { {  -20,  32, 101,  20 },  {  -23,  56,  87,  28 },  {  -30,  50,  70,  21 },  {  -43,  49,  55,  25 } } },  /* 144: not used by a script */
    { { {    0,  28,  95,  18 },  {   -9,  53,  75,  30 },  {  -20,  49,  50,  25 },  {  -33,  59,  31,  26 } } },  /* 145: TOUKETSU A */
    { { {  -19,  27, 105,  18 },  {  -34,  65,  81,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 146: KAMAE */
    { { {  -13,  27, 102,  18 },  {  -34,  65,  80,  25 },  {  -27,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 147: HURIMUKI */
    { { {  -24,  24, 106,  18 },  {  -36,  62,  92,  14 },  {  -30,  52,  52,  38 },  {  -28,  54,   0,  50 } } },  /* 148: FRONT WALK */
    { { {  -24,  24, 105,  18 },  {  -36,  62,  92,  14 },  {  -30,  52,  52,  38 },  {  -30,  56,   0,  50 } } },  /* 149: FRONT WALK */
    { { {  -24,  24, 109,  18 },  {  -32,  59,  92,  14 },  {  -30,  52,  52,  38 },  {  -30,  56,   0,  50 } } },  /* 150: FRONT WALK */
    { { {  -24,  24, 106,  18 },  {  -32,  54,  92,  14 },  {  -34,  52,  52,  38 },  {  -40,  69,   0,  50 } } },  /* 151: FRONT WALK */
    { { {  -22,  24, 108,  18 },  {  -34,  60,  92,  14 },  {  -28,  52,  52,  38 },  {  -26,  52,   0,  50 } } },  /* 152: FRONT WALK */
    { { {  -16,  24, 110,  18 },  {  -25,  54,  92,  18 },  {  -28,  52,  52,  38 },  {  -30,  58,   0,  50 } } },  /* 153: BACK WALK */
    { { {  -18,  24, 108,  18 },  {  -26,  56,  92,  18 },  {  -28,  52,  52,  38 },  {  -26,  54,   0,  50 } } },  /* 154: BACK WALK */
    { { {  -16,  24, 110,  18 },  {  -24,  54,  92,  18 },  {  -28,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 155: BACK WALK */
    { { {  -14,  24, 108,  18 },  {  -24,  54,  92,  18 },  {  -28,  52,  52,  38 },  {  -40,  68,   0,  50 } } },  /* 156: BACK WALK */
    { { {  -14,  24, 108,  18 },  {  -21,  50,  92,  18 },  {  -30,  54,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 157: BACK WALK */
    { { {  -17,  22,  74,  18 },  {  -28,  64,  64,  14 },  {  -26,  66,  41,  22 },  {  -36,  76,   0,  40 } } },  /* 158: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +1 */
    { { {  -50,  22,  92,  18 },  {  -38,  60,  94,  12 },  {  -32,  60,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 159: DASH HUMIKOMI */
    { { {  -34,  22,  86,  18 },  {  -24,  60,  78,  19 },  {  -28,  62,  47,  31 },  {  -40,  72,   0,  46 } } },  /* 160: DASH HUMIKOMI */
    { { {  -18,  27,  89,  18 },  {  -28,  65,  69,  25 },  {  -24,  52,  52,  28 },  {  -32,  68,   0,  50 } } },  /* 161: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    { { {  -21,  27, 107,  18 },  {  -33,  65,  83,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 162: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    { { {  -16,  22,  88,  18 },  {  -26,  64,  74,  20 },  {  -25,  58,  35,  38 },  {  -32,  69,   0,  34 } } },  /* 163: DASH TOBINOKI, KAGAMU */
    { { {   -1,  22, 113,  18 },  {  -20,  60,  94,  19 },  {  -24,  62,  51,  43 },  {  -36,  72,   0,  50 } } },  /* 164: DASH TOBINOKI */
    { { {  -22,  22,  90,  18 },  {  -20,  60,  94,  19 },  {  -24,  62,  51,  43 },  {  -32,  68,   0,  50 } } },  /* 165: not used by a script */
    { { {  -19,  27, 105,  18 },  {  -28,  62,  83,  25 },  {  -24,  52,  52,  36 },  {  -36,  72,   0,  50 } } },  /* 166: DASH TOBINOKI */
    { { {  -11,  25,  58,  18 },  {  -33,  70,  43,  16 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 167: not used by a script */
    { { {  -12,  25,  52,  20 },  {  -29,  66,  40,  16 },  {  -40,  82,  22,  22 },  {  -40,  80,   0,  22 } } },  /* 168: not used by a script */
    { { {  -33,  33, 103,  18 },  {  -37,  63,  94,  12 },  {  -31,  53,  41,  52 },  {  -31,  62,   0,  40 } } },  /* 169: PIYO */
    { { {  -17,  25,  58,  18 },  {  -33,  65,  43,  16 },  {  -38,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 170: KAGAMI TURN */
    { { {  -19,  25,  56,  18 },  {  -33,  67,  43,  16 },  {  -38,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 171: KAGAMI TURN */
    { { {  -16,  22,  98,  18 },  {  -26,  64,  85,  14 },  {  -26,  66,  41,  42 },  {  -32,  72,   0,  40 } } },  /* 172: JUMP JUNBI */
    { { {  -16,  27,  90,  18 },  {  -26,  64,  81,  14 },  {  -26,  66,  37,  42 },  {  -32,  72,   0,  36 } } },  /* 173: SP JUMP JUNBI */
    { { {  -46,  24,  98,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 174: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    { { {  -46,  24,  87,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -40,  64,  54,  26 } } },  /* 175: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
};

const HAND_BOX gill_hand_box[25] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -88,  48,  70,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -40,  26,  98,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: M PUNCH C */
    { { {  -82,  52,  76,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH A */
    { { {  -68,  34,  42,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: L PUNCH A */
    { { {  -78,  58,  74,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { { -112,  52,  70,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M KICK A, M KICK C */
    { { {  -78,  44,  64,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L KICK A */
    { { {  -72,  42,  26,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: L KICK A */
    { { {  -84,  38,  42,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: KAGAMI P A, no name */
    { { {  -40,  24,  76,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -92,  50,   0,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI K A */
    { { {  -98,  56,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A */
    { { {  -68,  57,  83,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: not used by a script */
    { { {  -38,  18,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: not used by a script */
    { { { -100,  62,  70,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: V JUMP K M A, ATTACK 4 M: not started by a command */
    { { { -100,  46,  58,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP K L A */
    { { {  -50,  28,  72,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: follow-up of APPEAR JUNBI 6 */
    { { {  -64,  16,  32,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: not used by a script */
    { { {  -60,  38,  66,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -90,  44,  80,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: V JUMP P M A */
    { { {  -50,  24,  88,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L KICK A */
    { { {  -68,  30,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP P L A */
    { { {  -66,  32,  54,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -60,  40,  80,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: M PUNCH C */
};

const HOSEI_BOX gill_hos_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   94 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +74 */
    { {  -24,   48,    0,   54 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +49 */
    { {  -24,   48,   62,   50 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP P L A +24 */
    { {   -4,   48,    0,  100 } },  /* 4: not used by a script */
    { {  -11,   48,    0,  100 } },  /* 5: not used by a script */
    { {    7,   48,    0,   54 } },  /* 6: not used by a script */
    { {  -24,   48,    0,  100 } },  /* 7: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy/EX (plain script) */
    { {  -24,   48,    0,   84 } },  /* 8: ATTACK 1 M: 6(123)4+K (routine Att_MOONSALT_KNEE_DROP), ATTACK 2 M: 623+P (routine Att_SLIDE_and_JUMP), ATTACK 5 M: 214+P (routine Att_SENPUUKYAKU) +26 */
    { {  -32,   64,    0,   94 } },  /* 9: DASH HUMIKOMI, no name */
    { {  -74,   96,    0,   54 } },  /* 10: KAGAMI P A, no name, ATTACK 9 L: SA (all arts) 23623+P (plain script) */
    { {  -23,   48,   34,   58 } },  /* 11: TUKAMIHAZUSI, no name, BODY SLAM +26 */
};
