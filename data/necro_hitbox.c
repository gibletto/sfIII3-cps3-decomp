/*
 * NECRO_HITBOX.C  Necro's hit boxes
 *
 * Each of Necro's animation frames names an entry of necro_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX necro_hit_ix_table[321] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +21 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, FRONT WALK, DASH HUMIKOMI +93 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, KAGAMI S +22 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: not used by a script */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: no name */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 5: not used by a script */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 6: TUKAMIHAZUSARE, V JUMP P S A, V JUMP P M A +4 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 7: PARING AIR F, TUKAMIHAZUSI, TUKAMIHAZUSARE +1 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: PARING AIR F, PARING AIR B, GUARD AIR +2 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 9: TUKAMIHAZUSI */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 10: not used by a script */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 11: TUKAMIHAZUSI */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 12: S PUNCH C */
    {   13,    0,    6, 0x0000,    0,    1,    1,    9 },  /* 13: S PUNCH C */
    {   13,    0,    6, 0x0000,    0,    1,    0,    9 },  /* 14: S PUNCH C */
    {   91,    0,    0, 0x0000,    0,    1,    0,    9 },  /* 15: S PUNCH C */
    {   14,    0,    0, 0x0000,    0,    1,    0,    9 },  /* 16: no name, S PUNCH C */
    {   15,    0,    7, 0x0000,    0,    1,    2,    1 },  /* 17: S PUNCH A */
    {   15,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 18: S PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 19: M PUNCH A, follow-up of S KICK C */
    {   17,    0,    8, 0x0000,    0,    1,    3,    1 },  /* 20: M PUNCH A, follow-up of S KICK C */
    {   97,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 21: M PUNCH A, follow-up of S KICK C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 22: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 24: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 25: L PUNCH C */
    {  124,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 26: ATTACK 10 SP: not started by a command */
    {   22,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 27: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 28: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 29: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 30: L PUNCH A, follow-up of follow-up of S KICK C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH A, follow-up of follow-up of S KICK C */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 32: L PUNCH A, follow-up of follow-up of S KICK C */
    {   28,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 33: L PUNCH A, follow-up of follow-up of S KICK C */
    {   29,   11,    0, 0x0000,    0,    1,    5,    1 },  /* 34: L PUNCH A, follow-up of follow-up of S KICK C */
    {   29,   11,    0, 0x0000,    0,    1,    0,    1 },  /* 35: L PUNCH A, follow-up of follow-up of S KICK C */
    {    1,    0,   12, 0x0000,    0,    1,    6,    1 },  /* 36: S KICK C */
    {    1,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 37: S KICK C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 38: S KICK A */
    {   32,    0,   13, 0x0000,    0,    1,    7,    1 },  /* 39: S KICK A */
    {   32,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 40: S KICK A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 41: M KICK C */
    {   34,    0,    0, 0x0000,    0,    1,    8,    1 },  /* 42: M KICK C */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: M KICK C */
    {   35,    0,   14, 0x0000,    0,    1,    9,    1 },  /* 44: M KICK A */
    {   35,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 45: M KICK A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 46: L KICK C */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: L KICK C */
    {   38,    0,   15, 0x0000,    0,    1,   10,    1 },  /* 48: L KICK C */
    {   38,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 49: L KICK C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 50: L KICK A */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 51: L KICK A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: L KICK A */
    {   42,   16,    0, 0x0000,    0,    1,   11,    1 },  /* 53: L KICK A */
    {   42,    0,   16, 0x0000,    0,    1,    0,    1 },  /* 54: L KICK A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 55: L KICK A */
    {  225,    0,   66, 0x0000,    0,    2,    0,    2 },  /* 56: KAGAMI P A */
    {   46,    0,   18, 0x0000,    0,   13,   12,    2 },  /* 57: KAGAMI P A */
    {   46,    0,   18, 0x0000,    0,   13,    0,    2 },  /* 58: KAGAMI P A */
    {   47,    0,   68, 0x0000,    0,    2,   13,    2 },  /* 59: KAGAMI P A */
    {   47,    0,   68, 0x0000,    0,    2,    0,    2 },  /* 60: KAGAMI P A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 61: KAGAMI P A */
    {   49,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 62: KAGAMI P C */
    {   50,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 63: KAGAMI P C */
    {   51,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 64: KAGAMI P C */
    {   52,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 65: KAGAMI P C */
    {   53,    0,   20, 0x0000,    0,    9,   14,   18 },  /* 66: KAGAMI P C */
    {   53,    0,   20, 0x0000,    0,    9,    0,   18 },  /* 67: KAGAMI P C */
    {   51,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 68: KAGAMI P C */
    {   54,    0,   21, 0x0000,    0,   13,   15,    2 },  /* 69: KAGAMI K A */
    {   54,    0,   21, 0x0000,    0,   13,    0,    2 },  /* 70: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 71: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 72: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 73: KAGAMI K A */
    {   58,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 74: KAGAMI K A */
    {   58,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 75: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 76: KAGAMI K A */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 77: KAGAMI K A */
    {   61,    0,   22, 0x0000,    0,    2,    0,    2 },  /* 78: KAGAMI K A */
    {   62,   41,    0, 0x0000,    0,    2,   17,    2 },  /* 79: KAGAMI K A */
    {  102,    0,   41, 0x0000,    0,    2,    0,    2 },  /* 80: KAGAMI K A */
    {   63,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 81: KAGAMI K A */
    {   64,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 82: KAGAMI K A */
    {    1,    0,    0, 0x0000,    0,    1,   18,    1 },  /* 83: L PUNCH C */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 84: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 85: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   67,    0,   24, 0x0000,    0,    3,   19,    3 },  /* 86: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   67,    0,   24, 0x0000,    0,    3,    0,    3 },  /* 87: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 88: V JUMP P S A, V JUMP P M A, V JUMP P L A +3 */
    {   69,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 89: V JUMP P M A */
    {   69,    0,   25, 0x0000,    0,    3,   20,    3 },  /* 90: V JUMP P M A */
    {   70,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 91: V JUMP P S A */
    {   70,    0,   26, 0x0000,    0,    3,   45,    3 },  /* 92: V JUMP P S A */
    {   71,    0,   27, 0x0000,    0,    3,   21,    3 },  /* 93: V JUMP P L A, F JUMP P L A */
    {   71,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 94: V JUMP P L A, F JUMP P L A */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 95: V JUMP K S A, V JUMP K L A, F JUMP P S A +3 */
    {  115,    0,   49, 0x0000,    0,    3,   22,    3 },  /* 96: V JUMP K S A, F JUMP K S A */
    {   73,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 97: V JUMP K L A */
    {   74,    0,   28, 0x0000,    0,    3,   23,    6 },  /* 98: V JUMP K L A */
    {   75,    0,   29, 0x0000,    0,    3,   34,    6 },  /* 99: V JUMP K L A */
    {   76,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 100: V JUMP P L A, F JUMP P L A */
    {   77,    0,   30, 0x0000,    0,    3,   24,    3 },  /* 101: F JUMP P S A */
    {   77,    0,   30, 0x0000,    0,    3,    0,    3 },  /* 102: F JUMP P S A */
    {   78,    0,   31, 0x0000,    0,    3,   56,    3 },  /* 103: F JUMP P M A */
    {  128,    0,   54, 0x0000,    0,    3,    0,    3 },  /* 104: F JUMP P M A */
    {   79,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 105: V JUMP K S B, F JUMP K M A, F JUMP K L A */
    {   80,    0,    0, 0x0000,    0,    3,   25,    3 },  /* 106: F JUMP K M A */
    {   80,    0,    0, 0x0000,    0,    3,   26,    3 },  /* 107: F JUMP K M A */
    {   80,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 108: F JUMP K M A */
    {   78,    0,   31, 0x0000,    0,    3,    0,    3 },  /* 109: F JUMP P M A */
    {   82,    0,    0, 0x0000,    0,    3,   54,    3 },  /* 110: F JUMP K L A */
    {   82,    0,   32, 0x0000,    0,    3,   54,    3 },  /* 111: F JUMP K L A */
    {   82,    0,   32, 0x0000,    0,    3,    0,    3 },  /* 112: F JUMP K L A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 113: GUARD HEAD, GUARD UP, P BREAK ZUJOU +2 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 114: PARING DOWN, GUARD DOWN, P BREAK DOWN */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 115: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {   85,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 116: not used by a script */
    {  121,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 117: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    {    1,    0,    0, 0x0000,    0,    1,   27,    1 },  /* 118: not used by a script */
    {  108,    0,   45, 0x0000,    0,    1,   28,    1 },  /* 119: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) */
    {  109,    0,   46, 0x0000,    0,    1,   29,    1 },  /* 120: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 121: TUKAMIKAKARI A */
    {   87,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 122: CATCH 5, ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script) +2 */
    {   88,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 123: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +1 */
    {   89,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 124: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +1 */
    {   90,    0,   33, 0x0000,    2,    2,   31,    2 },  /* 125: ATTACK 5 S: 1236+K light (plain script), ATTACK 11 L: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 126: M PUNCH C */
    {   92,    0,   34, 0x0000,    0,    1,   32,    1 },  /* 127: M PUNCH C */
    {   93,    0,   35, 0x0000,    0,    1,    0,    1 },  /* 128: M PUNCH C */
    {   95,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 129: M PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 130: M PUNCH C */
    {   96,    0,   36, 0x0000,    0,    1,    0,    1 },  /* 131: S PUNCH A, ATTACK 7 S: SA II 23623+P (plain script) */
    {   98,    0,   38, 0x0000,    0,   13,    0,    2 },  /* 132: KAGAMI P A */
    {   99,    0,    0, 0x0000,    0,   13,    0,    2 },  /* 133: KAGAMI K A */
    {  103,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 134: KAGAMI K A */
    {  103,    0,   42, 0x0000,    0,    2,    0,    2 },  /* 135: KAGAMI K A */
    {  103,    0,   42, 0x0000,    0,    2,   33,    2 },  /* 136: KAGAMI K A */
    {    3,    0,    1, 0x0000,    0,    3,    0,    3 },  /* 137: V JUMP K M A, V JUMP K L A */
    {  100,    0,   39, 0x0000,    0,    3,    0,    3 },  /* 138: V JUMP K L A */
    {  101,    0,   40, 0x0000,    0,    9,    0,   18 },  /* 139: KAGAMI P C */
    {  104,    0,   43, 0x0000,    0,   15,   35,    1 },  /* 140: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  105,    0,   44, 0x0000,    0,   15,   36,    1 },  /* 141: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {  106,    0,    0, 0x0000,    0,    1,   37,    1 },  /* 142: ATTACK 3 L: 623+P heavy/EX (plain script) */
    {  106,    0,    0, 0x0000,    0,    1,   38,    1 },  /* 143: ATTACK 3 L: 623+P heavy/EX (plain script) */
    {  111,    0,    0, 0x0000,    0,    1,   39,    1 },  /* 144: ATTACK 4 S: SA I 23623+P (plain script) */
    {  111,    0,    0, 0x0000,    0,    1,   40,    1 },  /* 145: ATTACK 4 S: SA I 23623+P (plain script) */
    {   68,    0,    0, 0x0000,    0,   14,    0,   22 },  /* 146: P BREAK ZUJOU, TUKAMIHAZUSI, no name */
    {  107,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 147: BODY SLAM, TOMOE RYU, MONKEY FLIP +6 */
    {    1,    0,    0, 0x0000,    5,    1,    0,    1 },  /* 148: ATTACK 7 S: SA II 23623+P (plain script) */
    {  108,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 149: not used by a script */
    {  109,    0,   46, 0x0000,    0,    1,   42,    1 },  /* 150: not used by a script */
    {  113,    0,    0, 0x0000,    0,    1,   43,    1 },  /* 151: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,   24 },  /* 152: not used by a script */
    {  110,    0,    0, 0x0000,    0,    2,    0,   24 },  /* 153: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 154: ATTACK 1 S: SA III 23623+P (plain script), ATTACK 4 S: SA I 23623+P (plain script), ATTACK 7 S: SA II 23623+P (plain script) */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 155: not used by a script */
    {  112,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 156: L PUNCH C */
    {    1,    0,    0, 0x0000,    0,    1,   46,    1 },  /* 157: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 158: follow-up of AIR NORMAL */
    {   62,    0,   23, 0x0000,    0,    2,    0,    2 },  /* 159: not used by a script */
    {  114,    0,   48, 0x0000,    0,    1,   47,    1 },  /* 160: L PUNCH C */
    {  116,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 161: ATTACK 1 S: SA III 23623+P (plain script) */
    {  117,    0,   51, 0x0000,    0,    3,   48,    3 },  /* 162: ATTACK 8 L: not started by a command */
    {  118,    0,    0, 0x0000,    0,   15,    0,    1 },  /* 163: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {  119,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 164: not used by a script */
    {   17,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 165: M PUNCH A, follow-up of S KICK C */
    {   90,    0,   33, 0x0000,    3,    2,   49,    2 },  /* 166: not used by a script */
    {   90,    0,   33, 0x0000,    4,    2,   50,    2 },  /* 167: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,   24 },  /* 168: NEKOROBI S, no name */
    {  106,    0,    0, 0x0000,    0,    1,   51,    1 },  /* 169: ATTACK 3 S: 623+P light (plain script) */
    {  106,    0,    0, 0x0000,    0,    1,   51,    1 },  /* 170: not used by a script */
    {  106,    0,    0, 0x0000,    0,    1,   52,    1 },  /* 171: ATTACK 3 M: 623+P medium (plain script) */
    {  106,    0,    0, 0x0000,    0,    1,   52,    1 },  /* 172: not used by a script */
    {  120,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 173: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 174: follow-up of SP APPEAR 6 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 175: follow-up of SP APPEAR 6 */
    {  106,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 176: ATTACK 3 S: 623+P light (plain script), ATTACK 3 M: 623+P medium (plain script) */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 177: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
    {   90,    0,   33, 0x0000,    0,    2,    0,    2 },  /* 178: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +1 */
    {   25,    0,    2, 0x0000,    0,    3,    0,    3 },  /* 179: V JUMP K M A */
    {   25,    0,    3, 0x0000,    0,    3,   53,    3 },  /* 180: V JUMP K M A */
    {   25,    0,    4, 0x0000,    0,    3,   53,    3 },  /* 181: V JUMP K M A */
    {   25,    0,    4, 0x0000,    0,    3,    0,    3 },  /* 182: V JUMP K M A */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 183: not used by a script */
    {   26,    0,    0, 0x0000,    0,   16,   55,   25 },  /* 184: V JUMP K S B */
    {   26,    0,    0, 0x0000,    0,   16,    0,   25 },  /* 185: V JUMP K S B */
    {  122,    0,   47, 0x0000,    0,    1,   30,    1 },  /* 186: L PUNCH C */
    {  123,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 187: M KICK A */
    {  124,    0,    5, 0x0000,    0,    1,   41,    1 },  /* 188: ATTACK 10 SP: not started by a command */
    {  125,    0,    0, 0x0000,    0,    0,    0,   24 },  /* 189: no name */
    {  126,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 190: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1 */
    {   67,    0,    0, 0x0000,    0,    3,   19,    3 },  /* 191: ATTACK 6 SP: EX 214+PP (routine Att_JINNCHUUWATARI) */
    {  108,    0,    0, 0x0000,    0,    1,   28,    1 },  /* 192: ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    {  109,    0,    0, 0x0000,    0,    1,   29,    1 },  /* 193: ATTACK 10 M: EX 214+KK (routine Att_SLIDE_and_JUMP) */
    {  127,    0,    0, 0x0000,    0,   15,   35,    1 },  /* 194: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    {  103,    0,   52, 0x0000,    0,    2,    0,    2 },  /* 195: KAGAMI K A */
    {   69,    0,   55, 0x0000,    0,    3,    0,    3 },  /* 196: V JUMP P M A */
    {   69,    0,   56, 0x0000,    0,    3,    0,    3 },  /* 197: V JUMP P M A */
    {   70,    0,   57, 0x0000,    0,    3,    0,    3 },  /* 198: V JUMP P S A */
    {   70,    0,   58, 0x0000,    0,    3,    0,    3 },  /* 199: V JUMP P S A */
    {  145,   60,    0, 0x0000,    0,    2,   57,    2 },  /* 200: KAGAMI P A */
    {  145,    0,   60, 0x0000,    0,    2,    0,    2 },  /* 201: KAGAMI P A */
    {    2,    0,   61, 0x0000,    0,    2,    0,    2 },  /* 202: KAGAMI P A */
    {    2,    0,   62, 0x0000,    0,    2,    0,    2 },  /* 203: KAGAMI P A */
    {  129,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 204: BODY UPPER L, UPPER L, BODY BROW S +2 */
    {  130,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 205: BODY UPPER L, UPPER L, BODY BROW M +1 */
    {  131,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 206: BODY UPPER L, UPPER L, BODY BROW L */
    {  132,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 207: BODY UPPER L, UPPER L, BODY BROW L */
    {  133,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 208: FACE S, FACE M, FACE L +7 */
    {  134,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 209: FACE M, FACE L, FOOK TEMAE L +4 */
    {  135,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 210: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    {  136,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 211: FACE L, FOOK TEMAE SP, TATI TOUKETU L */
    {  137,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 212: NOUTEN S, NOUTEN M, NOUTEN L */
    {  138,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 213: NOUTEN M, NOUTEN L */
    {  139,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 214: NOUTEN L */
    {  140,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 215: NOUTEN L, TATAKI S */
    {  141,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 216: KAGAMI S, KAGAMI M, KAGAMI L +3 */
    {  142,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 217: KAGAMI M, KAGAMI L, KGM TATAKI S +2 */
    {  143,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 218: KAGAMI L, KGM TOUKETU L */
    {  144,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 219: KAGAMI L */
    {    1,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 220: JUMP JUNBI, SP JUMP JUNBI */
    {  145,    0,   63, 0x0000,    0,    2,    0,    2 },  /* 221: KAGAMI P A */
    {   29,    0,   29, 0x0000,    0,    1,    0,    1 },  /* 222: L PUNCH A */
    {   42,   16,    0, 0x0000,    0,    1,    0,    1 },  /* 223: L KICK A */
    {  146,    0,   65, 0x0000,    0,    1,    0,    1 },  /* 224: L KICK A */
    {  147,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 225: L KICK A */
    {  148,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 226: AIR NORMAL, UPPER, HARAYARARE +2 */
    {  149,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 227: AIR NORMAL, BODY UPPER */
    {  150,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 228: BODY UPPER */
    {  151,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 229: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  152,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 230: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  153,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 231: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  154,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 232: ASIBARAI SIRI, ASIB TUNNOMERI */
    {  155,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 233: NOKEZORI, HARAYARARE, TATAKI AIR +3 */
    {  156,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 234: NOKEZORI, BODY UPPER, HARAYARARE +3 */
    {  157,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 235: NOKEZORI, UPPER, BODY UPPER +6 */
    {  158,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 236: NOKEZORI, UPPER, BODY UPPER +6 */
    {  159,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 237: NOKEZORI, UPPER, BODY UPPER +6 */
    {  160,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 238: NOKEZORI, UPPER, BODY UPPER +6 */
    {  161,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 239: NOKEZORI, UPPER, BODY UPPER +6 */
    {  162,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 240: KUNOJI, KUNOJI NOKE */
    {  163,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 241: KIRIMOMI */
    {  164,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 242: KIRIMOMI */
    {  165,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 243: KIRIMOMI */
    {  166,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 244: KIRIMOMI */
    {  167,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 245: KIRIMOMI */
    {  168,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 246: KIRIMOMI */
    {  169,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 247: KIRIMOMI */
    {  170,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 248: KIRIMOMI */
    {  171,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 249: KIRIMOMI */
    {  172,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 250: KIRIMOMI */
    {  173,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 251: KIRIMOMI */
    {  174,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 252: UPPER, TATUMAKIZANKU */
    {  175,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 253: BODY UPPER */
    {  176,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 254: BODY UPPER */
    {  177,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 255: TTKI V. AIR */
    {  178,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 256: TTKI V. AIR */
    {  179,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 257: HUMI ASIB */
    {  180,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 258: HUMI ASIB */
    {  181,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 259: FACE */
    {  182,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 260: DENKI */
    {  183,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 261: TOUKETSU A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 262: ATTACK 8 L: not started by a command */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 263: KAMAE */
    {  184,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 264: KAMAE */
    {  185,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 265: KAMAE */
    {  186,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 266: KAMAE */
    {  187,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 267: KAMAE */
    {  188,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 268: HURIMUKI */
    {  188,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 269: HURIMUKI */
    {  189,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 270: STAND UP */
    {  190,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 271: STAND UP */
    {  191,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 272: HURIMUKI, STAND UP */
    {  192,    0,    0, 0x1818,    0,   14,    0,   22 },  /* 273: DASH HUMIKOMI */
    {  193,    0,    0, 0x0000,    0,   14,    0,   22 },  /* 274: DASH HUMIKOMI */
    {  194,    0,    0, 0x1A1A,    0,    1,    0,   26 },  /* 275: DASH HUMIKOMI */
    {  195,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 276: HURIMUKI, DASH HUMIKOMI */
    {  195,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 277: DASH HUMIKOMI */
    {  196,    0,    0, 0x1A1A,    0,   14,    0,   22 },  /* 278: DASH TOBINOKI */
    {  197,    0,    0, 0x0000,    0,   14,    0,   22 },  /* 279: DASH TOBINOKI */
    {  198,    0,    0, 0x1010,    0,    1,    0,   26 },  /* 280: DASH TOBINOKI */
    {  199,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 281: DASH TOBINOKI */
    {  199,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 282: DASH TOBINOKI */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 283: FRONT WALK */
    {  200,    0,    0, 0x1818,    0,    1,    0,    1 },  /* 284: FRONT WALK */
    {  201,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 285: FRONT WALK */
    {  202,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 286: FRONT WALK */
    {  203,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 287: FRONT WALK */
    {  204,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 288: BACK WALK */
    {  205,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 289: BACK WALK */
    {  206,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 290: BACK WALK */
    {  207,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 291: BACK WALK */
    {  208,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 292: BACK WALK */
    {  209,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 293: BACK WALK */
    {    1,    0,    0, 0x1111,    0,    2,    0,    2 },  /* 294: KAGAMU */
    {  210,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 295: KAGAMI KAMAE */
    {  211,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 296: KAGAMI KAMAE */
    {  212,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 297: KAGAMI KAMAE */
    {  213,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 298: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  214,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 299: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  215,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 300: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  216,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 301: JUMP FRONT, JUMP VERTICAL, SP JUMP FRONT +2 */
    {  217,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 302: not used by a script */
    {  218,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 303: KAGAMI TURN */
    {  219,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 304: KAGAMI TURN */
    {    2,    0,    0, 0x0000,    0,    3,    0,    2 },  /* 305: not used by a script */
    {  220,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 306: PIYO */
    {  221,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 307: PIYO */
    {  222,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 308: PIYO */
    {  223,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 309: PIYO */
    {  224,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 310: STAND UP */
    {  226,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 311: KAGAMI P A */
    {  226,    0,   67, 0x0000,    0,    2,    0,    2 },  /* 312: KAGAMI P A */
    {   47,    0,   19, 0x0000,    0,    2,    0,    2 },  /* 313: KAGAMI P A */
    {  227,    0,   69, 0x0000,    0,    2,    0,    2 },  /* 314: KAGAMI P A */
    {    2,    0,   70, 0x0000,    0,    2,    0,    2 },  /* 315: KAGAMI P A */
    {   90,    0,   33, 0x0000,    3,    2,   31,    2 },  /* 316: ATTACK 5 M: 1236+K medium (plain script) */
    {   90,    0,   33, 0x0000,    4,    2,   31,    2 },  /* 317: ATTACK 5 L: 1236+K heavy/EX (plain script) */
    {   90,    0,   71, 0x0000,    0,    2,    0,    2 },  /* 318: CATCH 5 */
    {   89,    0,   72, 0x0000,    0,    2,    0,    2 },  /* 319: CATCH 5 */
    {   89,    0,   73, 0x0000,    0,    2,    0,    2 },  /* 320: CATCH 5 */
};

const BODY_BOX necro_body_box[228] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -34,  24,  70,  18 },  {  -29,  58,  70,  18 },  {  -24,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 1: HURIMUKI, FRONT WALK, DASH HUMIKOMI +103 */
    { { {  -28,  21,  43,  18 },  {  -15,  46,  43,  23 },  {  -23,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 2: KAGAMU, KAGAMI TURN, KAGAMI S +25 */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 3: no name, TUKAMIHAZUSARE, V JUMP P S A +19 */
    { { {  -47,  25,  79,  17 },  {  -40,  48,  83,  18 },  {  -32,  46,  73,  41 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {    0,   0,   0,   0 },  {  -40,  48,  83,  18 },  {  -32,  46,  55,  41 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { {  -15,  25,  95,  17 },  {  -23,  48,  89,  18 },  {  -23,  46,  48,  41 },  {    0,   0,   0,   0 } } },  /* 6: not used by a script */
    { { {  -16,  21,  99,  14 },  {  -29,  47,  91,  18 },  {  -26,  41,  71,  23 },  {    0,   0,   0,   0 } } },  /* 7: not used by a script */
    { { {    4,  25, 100,  17 },  {   -7,  48,  95,  18 },  {  -15,  33,  69,  41 },  {    0,   0,   0,   0 } } },  /* 8: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -33,  44,  73,  52 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -29,  46,  59,  41 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -19,  25, 100,  17 },  {  -28,  48,  88,  18 },  {  -27,  46,  50,  41 },  {    0,   0,   0,   0 } } },  /* 11: not used by a script */
    { { {  -16,  24,  76,  18 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 12: not used by a script */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 13: S PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 14: no name, S PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 15: S PUNCH A */
    { { {  -31,  25,  71,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 16: not used by a script */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 17: M PUNCH A, follow-up of S KICK C */
    { { {    2,  25,  76,  17 },  {   -2,  48,  67,  18 },  {    6,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 18: not used by a script */
    { { {   16,  25,  48,  17 },  {  -20,  48,  43,  18 },  {  -39,  46,  24,  24 },  {  -38,  44,   0,  23 } } },  /* 19: not used by a script */
    { { {   -6,  25,  60,  17 },  {  -20,  48,  43,  18 },  {  -39,  46,  24,  24 },  {  -38,  44,   0,  23 } } },  /* 20: not used by a script */
    { { {  -11,  25,  66,  17 },  {  -27,  48,  53,  18 },  {  -38,  46,  29,  24 },  {  -38,  44,   0,  29 } } },  /* 21: not used by a script */
    { { {  -36,  26,  96,  31 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 22: L PUNCH C */
    { { {    0,  25,  81,  17 },  {   -9,  48,  70,  18 },  {   -9,  46,  33,  38 },  {  -10,  44,   0,  45 } } },  /* 23: not used by a script */
    { { {  -21,  25,  81,  17 },  {  -24,  48,  70,  18 },  {  -22,  46,  33,  38 },  {  -24,  44,   0,  45 } } },  /* 24: not used by a script */
    { { {  -29,  61,  93,  25 },  { -121, 155,  77,  24 },  {  -47,  79,  60,  22 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP K M A */
    { { {   25,  41,  66,  38 },  {  -18,  69,  55,  41 },  {  -61,  60,  40,  49 },  {  -85,  46,  33,  42 } } },  /* 26: V JUMP K S B */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -43,  82,   0,  40 } } },  /* 27: L PUNCH A, follow-up of follow-up of S KICK C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -45,  84,   0,  40 } } },  /* 28: L PUNCH A, follow-up of follow-up of S KICK C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -45,  84,   0,  40 } } },  /* 29: L PUNCH A, follow-up of follow-up of S KICK C */
    { { {  -31,  25,  71,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -51,  75,   0,  39 } } },  /* 30: not used by a script */
    { { {    1,  25,  71,  17 },  {   10,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 31: not used by a script */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 32: S KICK A */
    { { {  -19,  25,  89,  17 },  {  -21,  48,  79,  18 },  {  -19,  46,  41,  36 },  {  -19,  44,   0,  39 } } },  /* 33: not used by a script */
    { { {  -19,  25,  89,  17 },  {  -21,  48,  79,  18 },  {  -66,  92,  37,  39 },  {  -30,  65,   0,  38 } } },  /* 34: M KICK C */
    { { {  -31,  25,  71,  17 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 35: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 36: not used by a script */
    { { {   10,  25,  95,  17 },  {  -22,  74,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 37: L KICK C */
    { { {   10,  25,  95,  17 },  {  -44,  91,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 38: L KICK C */
    { { {  -11,  25,  83,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 39: not used by a script */
    { { {    9,  25,  88,  21 },  {   -4,  75,  79,  18 },  {  -19,  46,  55,  24 },  {  -19,  44,   0,  53 } } },  /* 40: L KICK A */
    { { {    9,  25,  88,  21 },  {  -18,  75,  79,  20 },  {  -91, 118,  52,  33 },  {  -19,  44,   0,  53 } } },  /* 41: L KICK A */
    { { {   21,  23,  84,  19 },  {  -11,  86,  68,  33 },  {  -29, 112,  54,  28 },  {  -30,  86,   0,  54 } } },  /* 42: L KICK A */
    { { {    1,  25,  87,  17 },  {  -18,  75,  79,  18 },  {  -23,  49,  55,  24 },  {  -19,  44,   0,  53 } } },  /* 43: not used by a script */
    { { {  -31,  25,  87,  17 },  {  -21,  48,  79,  18 },  {  -19,  45,  55,  24 },  {  -18,  44,   0,  53 } } },  /* 44: not used by a script */
    { { {  -16,  25,  55,  17 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 45: not used by a script */
    { { {  -28,  40,  56,  18 },  {  -47,  88,  40,  27 },  {  -24,  60,  24,  20 },  {  -49,  90,   0,  28 } } },  /* 46: KAGAMI P A */
    { { {  -22,  31,  53,  22 },  {  -34,  65,  39,  31 },  {  -32,  71,  24,  22 },  {  -32,  69,   0,  28 } } },  /* 47: KAGAMI P A */
    { { {  -16,  25,  55,  17 },  {  -38,  68,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 48: not used by a script */
    { { {   -9,  37,  58,  19 },  {  -27,  79,  45,  25 },  {  -40,  71,  26,  24 },  {  -50,  87,   0,  26 } } },  /* 49: KAGAMI P C */
    { { {   -9,  37,  58,  19 },  {  -27,  79,  45,  25 },  {  -40,  71,  26,  24 },  {  -50,  87,   0,  26 } } },  /* 50: KAGAMI P C */
    { { {  -25,  37,  57,  19 },  {  -52,  77,  45,  28 },  {  -56,  69,  26,  24 },  {  -55,  77,   0,  26 } } },  /* 51: KAGAMI P C */
    { { {  -44,  31,  57,  19 },  {  -52,  77,  45,  28 },  {  -56,  69,  26,  24 },  {  -55,  77,   0,  26 } } },  /* 52: KAGAMI P C */
    { { {  -54,  25,  65,  18 },  {  -84,  74,  52,  29 },  {  -84,  74,  26,  24 },  {  -84, 112,   0,  26 } } },  /* 53: KAGAMI P C */
    { { {  -41,  28,  38,  24 },  {  -13,  48,  38,  28 },  {  -67, 106,  24,  26 },  {  -28,  67,   0,  28 } } },  /* 54: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 55: not used by a script */
    { { {   26,  25,  35,  17 },  {  -21,  48,  45,  18 },  {  -19,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 56: not used by a script */
    { { {  -63,  25,  33,  17 },  {  -60,  48,  45,  18 },  {  -36,  46,  26,  24 },  {  -19,  44,   0,  26 } } },  /* 57: not used by a script */
    { { {  -81,  52,  18,  33 },  {  -60,  52,  35,  28 },  {  -36,  71,  26,  34 },  {  -39, 138,   0,  34 } } },  /* 58: KAGAMI K A */
    { { {  -51,  25,  24,  17 },  {  -45,  48,  34,  18 },  {  -23,  46,  24,  24 },  {  -19,  44,   0,  26 } } },  /* 59: not used by a script */
    { { {    0,   0,   0,   0 },  {  -17,  48,  34,  18 },  {  -23,  46,  24,  24 },  {  -19,  44,   0,  26 } } },  /* 60: not used by a script */
    { { {   13,  25,  34,  22 },  {  -13,  74,  32,  28 },  {  -16,  80,   0,  42 },  {  -16,  43,   0,  42 } } },  /* 61: KAGAMI K A */
    { { {   26,  25,  47,  22 },  {   15,  67,  42,  22 },  {  -16,  80,   0,  42 },  {  -16,  43,   0,  42 } } },  /* 62: KAGAMI K A */
    { { {    6,  25,  64,  20 },  {  -20,  75,  57,  22 },  {  -17,  70,  38,  24 },  {  -59, 116,   0,  42 } } },  /* 63: KAGAMI K A */
    { { {  -29,  39,  60,  20 },  {  -30,  65,  50,  24 },  {  -30,  73,  38,  24 },  {  -34,  86,   0,  42 } } },  /* 64: KAGAMI K A */
    { { {  -31,  25, 104,  17 },  {  -35,  41,  90,  18 },  {  -17,  28,  55,  34 },  {    0,   0,   0,   0 } } },  /* 65: not used by a script */
    { { {  -48,  25,  91,  17 },  {  -35,  41,  90,  18 },  {  -17,  28,  55,  34 },  {    0,   0,   0,   0 } } },  /* 66: not used by a script */
    { { {  -48,  25,  91,  17 },  {  -35,  41,  90,  18 },  {  -80,  87,  55,  34 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -30,  65,  -8,  49 } } },  /* 68: P BREAK ZUJOU, TUKAMIHAZUSI, no name */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 69: V JUMP P M A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 70: V JUMP P S A */
    { { { -108,  80,  70,  27 },  {  -60,  65,  69,  34 },  {  -24,  49,  64,  47 },  {    0,   0,   0,   0 } } },  /* 71: V JUMP P L A, F JUMP P L A */
    { { {  -13,  25,  94,  17 },  {  -21,  48,  83,  18 },  {  -19,  46,  62,  29 },  {    0,   0,   0,   0 } } },  /* 72: not used by a script */
    { { {  -49,  50,  87,  34 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP K L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 75: V JUMP K L A */
    { { {  -54,  85,  90,  29 },  {  -70, 100,  72,  27 },  {  -47,  78,  53,  36 },  {    0,   0,   0,   0 } } },  /* 76: V JUMP P L A, F JUMP P L A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP P S A */
    { { {  -51,  80,  57,  61 },  {  -66,  43,  46,  28 },  {  -95,  45,  31,  28 },  { -123,  43,  16,  27 } } },  /* 78: F JUMP P M A */
    { { {   16,  29,  94,  25 },  {  -25,  61,  56,  51 },  {  -55,  54,  37,  51 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP K S B, F JUMP K M A, F JUMP K L A */
    { { {   15,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -57,  55,  63,  25 },  {  -68,  46,  27,  42 } } },  /* 80: F JUMP K M A */
    { { {  -10,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -57,  55,  63,  25 },  {    0,   0,   0,   0 } } },  /* 81: not used by a script */
    { { {   15,  25,  94,  17 },  {  -37,  79,  82,  33 },  {  -45,  62,  63,  25 },  {  -64,  73,  36,  30 } } },  /* 82: F JUMP K L A */
    { { {  -14,  25,  77,  17 },  {  -21,  48,  65,  18 },  {   -9,  27,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 83: not used by a script */
    { { {  -18,  25,  59,  17 },  {  -29,  48,  48,  18 },  {  -22,  36,  26,  24 },  {  -28,  44,   0,  26 } } },  /* 84: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -17,  39,   0,  35 },  {    0,   0,   0,   0 } } },  /* 85: not used by a script */
    { { {  -13,  25,  83,  17 },  {  -21,  48,  65,  18 },  {  -19,  46,  41,  24 },  {  -19,  44,   0,  39 } } },  /* 86: not used by a script */
    { { {  -20,  34,  64,  17 },  {  -29,  67,  58,  17 },  {  -29,  64,  38,  20 },  {  -37,  73,   0,  38 } } },  /* 87: CATCH 5, ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script) +2 */
    { { {   -8,  45,  64,  17 },  {  -28,  79,  58,  17 },  {  -34,  72,  38,  20 },  {  -53,  90,   0,  38 } } },  /* 88: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +1 */
    { { {  -32,  45,  64,  17 },  {  -40,  72,  57,  19 },  {  -42,  73,  38,  20 },  {  -50,  88,   0,  38 } } },  /* 89: ATTACK 5 S: 1236+K light (plain script), ATTACK 5 M: 1236+K medium (plain script), ATTACK 5 L: 1236+K heavy/EX (plain script) +2 */
    { { {  -52,  33,  45,  18 },  {  -34,  74,  44,  28 },  {  -60,  89,  20,  27 },  {  -40,  83,   0,  28 } } },  /* 90: ATTACK 5 S: 1236+K light (plain script), ATTACK 11 L: not started by a command, ATTACK 5 M: 1236+K medium (plain script) +2 */
    { { {  -64,  44,  58,  20 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 91: S PUNCH C */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 92: M PUNCH C */
    { { {    0,   0,   0,   0 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 93: M PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 94: not used by a script */
    { { {  -64,  44,  58,  20 },  {  -30,  58,  60,  26 },  {  -20,  44,  40,  24 },  {  -20,  54,   0,  38 } } },  /* 95: M PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 96: S PUNCH A, ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -16,  24,  76,  18 },  {  -35,  72,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  65,   0,  38 } } },  /* 97: M PUNCH A, follow-up of S KICK C */
    { { {  -16,  25,  55,  17 },  {  -32,  63,  44,  24 },  {  -35,  79,  24,  28 },  {  -31,  68,   0,  28 } } },  /* 98: KAGAMI P A */
    { { {  -41,  28,  38,  24 },  {  -13,  48,  38,  28 },  {  -67, 106,  24,  26 },  {  -84, 112,   0,  28 } } },  /* 99: KAGAMI K A */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 100: V JUMP K L A */
    { { {  -54,  25,  68,  18 },  {  -84,  74,  52,  29 },  {  -84,  74,  26,  24 },  {  -84, 112,   0,  26 } } },  /* 101: KAGAMI P C */
    { { {   15,  25,  57,  21 },  {   10,  56,  41,  37 },  {  -16,  80,   0,  42 },  {  -16,  43,   0,  42 } } },  /* 102: KAGAMI K A */
    { { {  -41,  28,  42,  24 },  {  -13,  48,  41,  27 },  {  -67, 106,  24,  26 },  {  -54,  93,   0,  28 } } },  /* 103: KAGAMI K A */
    { { {  -31,  25,  71,  17 },  {  -61,  86,  65,  18 },  {  -19,  46,  41,  24 },  {  -65,  91,   0,  39 } } },  /* 104: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -74,  64,  57,  20 },  {  -21,  48,  65,  18 },  {  -54,  83,  41,  24 },  {  -55,  84,   0,  39 } } },  /* 105: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -36,  25,  62,  28 },  {  -21,  48,  65,  18 },  {  -33,  60,  41,  24 },  {  -50, 104,   0,  44 } } },  /* 106: ATTACK 3 L: 623+P heavy/EX (plain script), ATTACK 3 S: 623+P light (plain script), ATTACK 3 M: 623+P medium (plain script) */
    { { {  -24,  47,  72,  17 },  {  -27,  55,  62,  18 },  {  -27,  55,  34,  27 },  {    0,   0,   0,   0 } } },  /* 107: BODY SLAM, TOMOE RYU, MONKEY FLIP +6 */
    { { {  -47,  44,  82,  23 },  {  -29,  64,  72,  28 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 108: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1 */
    { { {  -32,  33,  76,  19 },  {  -39,  75,  71,  19 },  {  -85, 121,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 109: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,  79,   0,  60 },  {    0,   0,   0,   0 } } },  /* 110: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -19,  46,  41,  24 },  {  -42,  86,   0,  39 } } },  /* 111: ATTACK 4 S: SA I 23623+P (plain script) */
    { { {  -13,  25,  96,  17 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 112: L PUNCH C */
    { { {   10,  25,  95,  17 },  {  -44,  91,  73,  29 },  {  -19,  46,  41,  45 },  {  -19,  44,   0,  39 } } },  /* 113: not used by a script */
    { { {  -26,  30,  96,  38 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 114: L PUNCH C */
    { { {  -17,  21, 103,  16 },  {  -29,  61,  91,  27 },  {  -26,  52,  53,  36 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP K S A, F JUMP K S A */
    { { {  -28,  24,  40,  30 },  {    4,  33,  71,  16 },  {  -10,  64,  40,  31 },  {  -24,  79,   0,  38 } } },  /* 116: ATTACK 1 S: SA III 23623+P (plain script) */
    { { {  -17,  21, 103,  16 },  {  -69,  94,  91,  27 },  {  -70,  96,  53,  36 },  {    0,   0,   0,   0 } } },  /* 117: ATTACK 8 L: not started by a command */
    { { {  -16,  24,  76,  18 },  {  -42,  89,  72,  16 },  {  -42,  88,  40,  31 },  {  -43,  89,   0,  38 } } },  /* 118: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -33,  24,  48,  23 },  {  -29,  62,  60,  18 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 119: not used by a script */
    { { {    0,   0,   0,   0 },  {   32,  44,  63,  30 },  {  -13,  81,  37,  29 },  {  -13,  96,   0,  37 } } },  /* 120: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    { { {   -4,  39,  71,  36 },  {  -25,  37,  72,  56 },  {  -29,  64,  40,  31 },  {  -30,  65,   0,  38 } } },  /* 121: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +2 */
    { { {  -34,  30,  96,  39 },  {  -40,  57,  84,  18 },  {  -40,  63,  45,  38 },  {  -25,  67,   0,  45 } } },  /* 122: L PUNCH C */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -45,  81,   0,  38 } } },  /* 123: M KICK A */
    { { {  -16,  24,  76,  18 },  {  -29,  64,  72,  16 },  {  -29,  64,  40,  31 },  {  -50,  85,   0,  38 } } },  /* 124: ATTACK 10 SP: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 125: no name */
    { { {    0,   0,   0,   0 },  {   -2,  44,  74,  35 },  {  -20,  84,  37,  37 },  {  -27, 107,   0,  37 } } },  /* 126: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) +1 */
    { { {  -31,  25,  71,  17 },  {  -33,  62,  65,  18 },  {  -19,  46,  41,  24 },  {  -65,  91,   0,  39 } } },  /* 127: ATTACK 2 SP: EX 1236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -35,  21,  79,  16 },  {  -51,  63, 102,  27 },  {  -54,  93,  84,  18 },  {  -54,  83,  62,  21 } } },  /* 128: F JUMP P M A */
    { { {    0,  24,  80,  18 },  {  -25,  58,  70,  18 },  {  -25,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 129: BODY UPPER L, UPPER L, BODY BROW S +2 */
    { { {    8,  24,  79,  18 },  {  -22,  58,  70,  18 },  {  -26,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 130: BODY UPPER L, UPPER L, BODY BROW M +1 */
    { { {   12,  24,  78,  18 },  {  -20,  58,  70,  18 },  {  -27,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 131: BODY UPPER L, UPPER L, BODY BROW L */
    { { {   14,  24,  77,  18 },  {  -19,  58,  70,  18 },  {  -28,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 132: BODY UPPER L, UPPER L, BODY BROW L */
    { { {    0,  24,  74,  18 },  {  -21,  58,  69,  18 },  {  -20,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 133: FACE S, FACE M, FACE L +7 */
    { { {   12,  24,  72,  18 },  {  -15,  58,  68,  18 },  {  -17,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 134: FACE M, FACE L, FOOK TEMAE L +4 */
    { { {   20,  24,  70,  18 },  {  -11,  58,  67,  18 },  {  -15,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 135: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    { { {   24,  24,  68,  18 },  {   -9,  58,  66,  18 },  {  -14,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 136: FACE L, FOOK TEMAE SP, TATI TOUKETU L */
    { { {  -20,  24,  73,  18 },  {  -27,  58,  68,  18 },  {  -22,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 137: NOUTEN S, NOUTEN M, NOUTEN L */
    { { {  -24,  24,  70,  18 },  {  -25,  58,  66,  18 },  {  -20,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 138: NOUTEN M, NOUTEN L */
    { { {  -28,  24,  67,  18 },  {  -23,  58,  64,  18 },  {  -18,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 139: NOUTEN L */
    { { {  -32,  24,  64,  18 },  {  -21,  58,  62,  18 },  {  -16,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 140: NOUTEN L, TATAKI S */
    { { {  -22,  21,  43,  18 },  {  -13,  46,  43,  23 },  {  -22,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 141: KAGAMI S, KAGAMI M, KAGAMI L +3 */
    { { {  -16,  21,  43,  18 },  {  -11,  46,  43,  23 },  {  -21,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 142: KAGAMI M, KAGAMI L, KGM TATAKI S +2 */
    { { {  -10,  21,  43,  18 },  {   -9,  46,  43,  23 },  {  -20,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 143: KAGAMI L, KGM TOUKETU L */
    { { {   -4,  21,  43,  18 },  {   -7,  46,  43,  23 },  {  -19,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 144: KAGAMI L */
    { { {  -41,  22,  36,  25 },  {  -56,  90,  23,  33 },  {  -41,  76,  16,  23 },  {  -42,  76,   0,  16 } } },  /* 145: KAGAMI P A */
    { { {    9,  25,  88,  21 },  {  -17,  81,  68,  35 },  {  -35,  90,  48,  28 },  {  -30,  86,   0,  48 } } },  /* 146: L KICK A */
    { { {  -14,  25,  85,  21 },  {  -28,  67,  79,  22 },  {  -45,  82,  33,  46 },  {  -25,  64,   0,  47 } } },  /* 147: L KICK A */
    { { {  -25,  35,  83,  19 },  {  -21,  54,  76,  22 },  {  -19,  53,  50,  26 },  {  -26,  54,  30,  20 } } },  /* 148: AIR NORMAL, UPPER, HARAYARARE +2 */
    { { {   14,  24,  77,  19 },  {  -15,  60,  66,  22 },  {  -25,  62,  38,  28 },  {    0,   0,   0,   0 } } },  /* 149: AIR NORMAL, BODY UPPER */
    { { {   14,  24,  79,  17 },  {    5,  51,  66,  26 },  {    5,  39,  50,  27 },  {  -26,  52,  42,  31 } } },  /* 150: BODY UPPER */
    { { {  -17,  26,  68,  17 },  {  -22,  61,  62,  24 },  {  -11,  54,  44,  18 },  {  -32,  56,  26,  21 } } },  /* 151: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {    8,  26,  55,  17 },  {    3,  47,  31,  28 },  {  -10,  40,  19,  30 },  {  -43,  33,  19,  34 } } },  /* 152: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {   -2,  25,  48,  17 },  {    2,  46,  29,  26 },  {  -16,  53,   9,  21 },  {  -21,  27,  27,  33 } } },  /* 153: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {    7,  25,  42,  17 },  {   -3,  40,  22,  26 },  {  -21,  47,   0,  22 },  {  -21,  28,  22,  33 } } },  /* 154: ASIBARAI SIRI, ASIB TUNNOMERI */
    { { {   37,  24,  68,  19 },  {    8,  43,  60,  37 },  {  -12,  40,  55,  30 },  {  -38,  56,  35,  36 } } },  /* 155: NOKEZORI, HARAYARARE, TATAKI AIR +3 */
    { { {   39,  24,  81,  19 },  {    8,  43,  68,  44 },  {  -15,  28,  73,  30 },  {  -48,  45,  63,  39 } } },  /* 156: NOKEZORI, BODY UPPER, HARAYARARE +3 */
    { { {   42,  24,  63,  19 },  {   11,  43,  52,  44 },  {  -14,  28,  60,  32 },  {  -48,  34,  55,  37 } } },  /* 157: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   42,  24,  52,  19 },  {    0,  54,  45,  41 },  {  -14,  28,  59,  29 },  {  -39,  34,  61,  31 } } },  /* 158: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   32,  24,  53,  19 },  {    5,  37,  45,  35 },  {  -14,  28,  48,  25 },  {  -34,  34,  54,  39 } } },  /* 159: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   23,  24,  51,  19 },  {    0,  42,  31,  39 },  {  -21,  31,  38,  25 },  {  -35,  39,  51,  34 } } },  /* 160: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   28,  24,  32,  19 },  {   -4,  45,  16,  39 },  {  -19,  32,  29,  30 },  {  -32,  48,  46,  34 } } },  /* 161: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {  -24,  28,  64,  19 },  {   -1,  42,  55,  31 },  {   36,  30,  42,  40 },  {  -18,  57,  34,  21 } } },  /* 162: KUNOJI, KUNOJI NOKE */
    { { {  -10,  24,  68,  17 },  {    1,  42,  54,  29 },  {   -7,  41,  40,  14 },  {  -29,  57,  25,  23 } } },  /* 163: KIRIMOMI */
    { { {    9,  24,  75,  17 },  {   -9,  51,  54,  28 },  {  -16,  45,  40,  14 },  {  -39,  59,  25,  23 } } },  /* 164: KIRIMOMI */
    { { {   24,  24,  84,  17 },  {   -5,  61,  64,  29 },  {  -17,  50,  50,  14 },  {  -39,  50,  25,  25 } } },  /* 165: KIRIMOMI */
    { { {   25,  24,  81,  17 },  {   -3,  46,  55,  31 },  {  -12,  37,  48,  15 },  {  -26,  44,  29,  26 } } },  /* 166: KIRIMOMI */
    { { {   25,  24,  73,  17 },  {   -5,  48,  49,  34 },  {  -10,  37,  41,  22 },  {  -28,  44,  23,  30 } } },  /* 167: KIRIMOMI */
    { { {   27,  24,  71,  17 },  {   -5,  48,  47,  34 },  {  -20,  37,  42,  22 },  {  -49,  47,  32,  30 } } },  /* 168: KIRIMOMI */
    { { {   33,  24,  63,  17 },  {   -1,  48,  45,  36 },  {  -15,  29,  39,  23 },  {  -36,  35,  30,  26 } } },  /* 169: KIRIMOMI */
    { { {   33,  24,  56,  17 },  {    0,  43,  35,  43 },  {  -11,  29,  34,  26 },  {  -43,  50,  21,  33 } } },  /* 170: KIRIMOMI */
    { { {   38,  24,  49,  18 },  {    5,  43,  33,  40 },  {   -9,  29,  32,  26 },  {  -38,  39,  12,  41 } } },  /* 171: KIRIMOMI */
    { { {   33,  24,  47,  18 },  {    5,  34,  33,  40 },  {  -10,  29,  27,  26 },  {  -33,  39,  12,  30 } } },  /* 172: KIRIMOMI */
    { { {   36,  24,  42,  18 },  {    5,  38,  22,  42 },  {  -10,  29,  23,  26 },  {  -39,  36,   4,  43 } } },  /* 173: KIRIMOMI */
    { { {   33,  25,  45,  24 },  {  -11,  55,  64,  28 },  {  -32,  35,  50,  36 },  {  -46,  45,  35,  30 } } },  /* 174: UPPER, TATUMAKIZANKU */
    { { {  -24,  25,  73,  17 },  {  -21,  75,  69,  23 },  {    5,  43,  49,  53 },  {  -24,  65,  30,  21 } } },  /* 175: BODY UPPER */
    { { {  -25,  28,  51,  17 },  {  -20,  61,  62,  22 },  {   -3,  47,  38,  27 },  {  -25,  61,  28,  22 } } },  /* 176: BODY UPPER */
    { { {  -52,  26,  19,  19 },  {  -40,  43,  34,  35 },  {  -18,  40,  34,  38 },  {  -28,  38,  13,  18 } } },  /* 177: TTKI V. AIR */
    { { {  -26,  26,  19,  19 },  {  -35,  60,  19,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 178: TTKI V. AIR */
    { { {    0,  25,  67,  17 },  {  -44,  58,  58,  24 },  {  -36,  37,  34,  27 },  {  -33,  54,  16,  18 } } },  /* 179: HUMI ASIB */
    { { {  -44,  29,  21,  18 },  {  -64,  56,  35,  36 },  {  -27,  38,  43,  34 },  {    2,  29,  38,  38 } } },  /* 180: HUMI ASIB */
    { { {   -6,  24,  84,  17 },  {  -29,  59,  71,  20 },  {  -24,  49,  50,  21 },  {  -29,  47,  31,  19 } } },  /* 181: FACE */
    { { {   13,  26, 101,  20 },  {  -17,  63,  78,  30 },  {  -19,  42,  58,  20 },  {  -29,  58,  36,  22 } } },  /* 182: DENKI */
    { { {   15,  24,  76,  18 },  {  -10,  58,  66,  22 },  {   -7,  44,  45,  21 },  {  -19,  56,  23,  22 } } },  /* 183: TOUKETSU A */
    { { {  -36,  24,  73,  18 },  {  -29,  52,  73,  18 },  {  -24,  51,  39,  34 },  {  -25,  60,   0,  38 } } },  /* 184: KAMAE */
    { { {  -36,  24,  64,  18 },  {  -29,  58,  65,  20 },  {  -24,  51,  33,  34 },  {  -25,  60,   0,  32 } } },  /* 185: KAMAE */
    { { {  -18,  24,  70,  18 },  {  -23,  58,  68,  20 },  {  -23,  58,  33,  36 },  {  -25,  60,   0,  32 } } },  /* 186: KAMAE */
    { { {  -20,  24,  66,  18 },  {  -25,  56,  66,  18 },  {  -25,  60,  33,  32 },  {  -25,  60,   0,  32 } } },  /* 187: KAMAE */
    { { {   15,  22,  69,  21 },  {  -24,  48,  69,  23 },  {  -27,  57,  37,  31 },  {  -30,  70,   0,  36 } } },  /* 188: HURIMUKI */
    { { {  -32,  22,  44,  21 },  {  -19,  48,  52,  16 },  {  -26,  58,  29,  22 },  {  -30,  64,   0,  28 } } },  /* 189: STAND UP */
    { { {  -34,  22,  69,  21 },  {  -30,  52,  66,  23 },  {  -26,  59,  33,  33 },  {  -28,  60,   0,  32 } } },  /* 190: STAND UP */
    { { {  -29,  22,  71,  21 },  {  -32,  57,  66,  21 },  {  -26,  59,  37,  28 },  {  -26,  60,   0,  36 } } },  /* 191: HURIMUKI, STAND UP */
    { { {  -31,  22,  67,  21 },  {  -32,  62,  63,  18 },  {  -22,  66,  37,  25 },  {  -27,  87,   0,  36 } } },  /* 192: DASH HUMIKOMI */
    { { {  -36,  24,  62,  21 },  {  -26,  62,  60,  18 },  {  -22,  70,  37,  22 },  {  -27,  87,   0,  36 } } },  /* 193: DASH HUMIKOMI */
    { { {  -36,  25,  57,  21 },  {  -27,  59,  59,  18 },  {  -24,  63,  37,  25 },  {  -30,  79,   0,  36 } } },  /* 194: DASH HUMIKOMI */
    { { {  -30,  22,  62,  21 },  {  -32,  59,  61,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 195: HURIMUKI, DASH HUMIKOMI */
    { { {  -31,  22,  64,  21 },  {  -18,  56,  63,  21 },  {  -25,  58,  37,  25 },  {  -40,  81,   0,  36 } } },  /* 196: DASH TOBINOKI */
    { { {  -21,  22,  64,  21 },  {  -19,  55,  58,  21 },  {  -27,  59,  32,  25 },  {  -42,  82,   0,  36 } } },  /* 197: DASH TOBINOKI */
    { { {  -30,  22,  60,  21 },  {  -19,  58,  61,  21 },  {  -26,  65,  39,  22 },  {  -38,  80,   0,  40 } } },  /* 198: DASH TOBINOKI */
    { { {  -30,  22,  53,  21 },  {  -18,  59,  53,  21 },  {  -26,  62,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 199: DASH TOBINOKI */
    { { {  -40,  24,  61,  18 },  {  -29,  44,  70,  22 },  {  -24,  51,  33,  48 },  {  -25,  60,   0,  32 } } },  /* 200: FRONT WALK */
    { { {  -40,  24,  82,  18 },  {  -29,  46,  81,  24 },  {  -24,  47,  47,  34 },  {  -33,  68,   0,  46 } } },  /* 201: FRONT WALK */
    { { {  -41,  24,  62,  18 },  {  -34,  46,  72,  18 },  {  -24,  47,  39,  43 },  {  -29,  64,   0,  38 } } },  /* 202: FRONT WALK */
    { { {  -38,  24,  83,  18 },  {  -32,  49,  80,  22 },  {  -24,  47,  49,  30 },  {  -29,  64,   0,  48 } } },  /* 203: FRONT WALK */
    { { {  -23,  24,  73,  18 },  {  -20,  52,  70,  23 },  {  -24,  51,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 204: BACK WALK */
    { { {  -34,  24,  81,  18 },  {  -29,  47,  80,  23 },  {  -31,  51,  41,  39 },  {  -36,  64,   0,  40 } } },  /* 205: BACK WALK */
    { { {  -31,  24,  79,  18 },  {  -29,  51,  74,  27 },  {  -22,  49,  39,  36 },  {  -23,  53,   0,  38 } } },  /* 206: BACK WALK */
    { { {  -31,  24,  89,  18 },  {  -25,  45,  81,  27 },  {  -22,  49,  42,  39 },  {  -23,  53,   0,  42 } } },  /* 207: BACK WALK */
    { { {  -31,  24,  79,  18 },  {  -25,  45,  70,  30 },  {  -26,  49,  38,  33 },  {  -33,  62,   0,  38 } } },  /* 208: BACK WALK */
    { { {  -31,  24,  89,  18 },  {  -23,  43,  82,  27 },  {  -23,  49,  41,  41 },  {  -22,  62,   0,  40 } } },  /* 209: BACK WALK */
    { { {  -28,  21,  43,  18 },  {  -15,  43,  43,  23 },  {  -23,  64,  29,  29 },  {  -25,  65,   0,  28 } } },  /* 210: KAGAMI KAMAE */
    { { {  -32,  21,  36,  18 },  {  -22,  52,  42,  23 },  {  -23,  58,  29,  29 },  {  -28,  65,   0,  28 } } },  /* 211: KAGAMI KAMAE */
    { { {  -26,  21,  43,  18 },  {  -12,  54,  42,  23 },  {  -19,  64,  29,  29 },  {  -23,  65,   0,  28 } } },  /* 212: KAGAMI KAMAE */
    { { {  -26,  54, 102,  16 },  {  -31,  64,  89,  21 },  {  -32,  66,  77,  21 },  {  -28,  57,  67,  16 } } },  /* 213: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -10,  22, 104,  21 },  {  -26,  58,  95,  22 },  {  -23,  52,  74,  21 },  {  -22,  49,  57,  17 } } },  /* 214: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -17,  22,  97,  21 },  {  -29,  59,  94,  21 },  {  -31,  65,  82,  21 },  {  -25,  52,  64,  20 } } },  /* 215: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -19,  22, 100,  21 },  {  -30,  60,  91,  20 },  {  -23,  48,  74,  20 },  {  -24,  47,  53,  20 } } },  /* 216: JUMP FRONT, JUMP VERTICAL, SP JUMP FRONT +2 */
    { { {  -13,  25, 113,  19 },  {  -26,  58, 100,  22 },  {  -22,  51,  72,  28 },  {  -23,  50,  53,  18 } } },  /* 217: not used by a script */
    { { {    7,  21,  41,  21 },  {  -34,  56,  47,  18 },  {  -41,  75,  25,  24 },  {  -30,  63,   0,  28 } } },  /* 218: KAGAMI TURN */
    { { {  -33,  21,  50,  21 },  {  -32,  68,  48,  21 },  {  -29,  70,  25,  24 },  {  -30,  63,   0,  28 } } },  /* 219: KAGAMI TURN */
    { { {  -28,  24,  43,  18 },  {  -31,  53,  55,  20 },  {  -24,  51,  31,  30 },  {  -25,  60,   0,  30 } } },  /* 220: PIYO */
    { { {  -23,  24,  70,  18 },  {  -16,  50,  70,  24 },  {  -24,  59,  39,  30 },  {  -25,  60,   0,  38 } } },  /* 221: PIYO */
    { { {  -30,  24,  68,  18 },  {  -24,  50,  62,  26 },  {  -24,  59,  31,  30 },  {  -25,  60,   0,  30 } } },  /* 222: PIYO */
    { { {  -36,  24,  49,  18 },  {  -28,  50,  50,  20 },  {  -24,  53,  31,  18 },  {  -25,  60,   0,  30 } } },  /* 223: PIYO */
    { { {  -32,  22,  52,  21 },  {  -18,  52,  52,  22 },  {  -24,  53,  29,  22 },  {  -30,  64,   0,  28 } } },  /* 224: STAND UP */
    { { {  -16,  21,  57,  18 },  {  -32,  62,  44,  23 },  {  -30,  77,  28,  26 },  {  -32,  69,   0,  28 } } },  /* 225: KAGAMI P A */
    { { {  -20,  21,  53,  18 },  {  -27,  56,  41,  23 },  {  -33,  70,  24,  29 },  {  -30,  67,   0,  28 } } },  /* 226: KAGAMI P A */
    { { {  -28,  21,  43,  18 },  {  -15,  46,  49,  23 },  {  -23,  64,  28,  29 },  {  -28,  65,   0,  28 } } },  /* 227: KAGAMI P A */
};

const HAND_BOX necro_hand_box[74] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -64,  38,  53,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: V JUMP K M A, V JUMP K L A */
    { { { -167,  47,  98,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: V JUMP K M A */
    { { { -130,  41,  92,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: V JUMP K M A */
    { { { -140,  51,  92,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: V JUMP K M A */
    { { {  -90,  67,  49,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: ATTACK 10 SP: not started by a command */
    { { {  -92,  72,  42,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S PUNCH C */
    { { { -126, 100,  57,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: S PUNCH A */
    { { { -102,  79,  73,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, follow-up of S KICK C */
    { { {   -3,  29,  97,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH C */
    { { {  -99,  72,  50,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH A, follow-up of follow-up of S KICK C */
    { { { -204, 184,  50,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH A, follow-up of follow-up of S KICK C */
    { { {  -63,  31,  20,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: S KICK C */
    { { {  -92,  71,  33,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: S KICK A */
    { { { -132, 106,  23,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M KICK A */
    { { {  -63,  39,  67,  59 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L KICK C */
    { { { -177,  25,  96,  31 },  { -152,  38,  88,  22 },  { -114,  61,  77,  23 },  {  -53,  42,  65,  25 } } },  /* 16: L KICK A */
    { { { -116, 102,  64,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { { -121,  96,  29,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P A */
    { { { -101,  34,  85,  31 },  {  -81,  38,  68,  32 },  {  -60,  41,  50,  33 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI P A */
    { { { -110,  48,  64,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P C */
    { { { -115,  91,   0,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI K A */
    { { { -108,  95,   0,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI K A */
    { { { -150, 137,   0,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -96,  65,  20,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: ATTACK 6 S: 214+P light (routine Att_SENPUUKYAKU), ATTACK 6 M: 214+P medium (routine Att_SENPUUKYAKU), ATTACK 6 L: 214+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { { -171, 142,  85,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP P M A */
    { { { -132, 104,  97,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P S A */
    { { { -140,  82,  46,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P L A, F JUMP P L A */
    { { { -118,  93,  56,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP K L A */
    { { { -130, 103,  54,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: V JUMP K L A, L PUNCH A */
    { { {  -75,  58,  30,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP P S A */
    { { { -153,  50,  -9,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP P M A */
    { { {  -52,  53,   0,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP K L A */
    { { {  -93,  33,  20,  21 },  { -120,  28,   8,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 5 S: 1236+K light (plain script), ATTACK 11 L: not started by a command, ATTACK 5 M: 1236+K medium (plain script) +1 */
    { { {  -88,  62,  56,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: M PUNCH C */
    { { {  -92,  66,  56,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: M PUNCH C */
    { { {  -86,  64,  60,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: S PUNCH A, ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -68,  48,  73,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: M PUNCH A, follow-up of S KICK C */
    { { {  -72,  48,  28,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: KAGAMI P A */
    { { { -118,  93,  56,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K L A */
    { { {  -88,  29,  54,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: KAGAMI P C */
    { { { -150, 151,   0,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: KAGAMI K A */
    { { { -182, 162,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI K A */
    { { {  -66,  51,  43,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -95,  85,  73,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 2 S: 1236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 1236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 1236+P heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -84,  37,  96,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) */
    { { { -106,  44,  21,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script), ATTACK 10 S: 214+K heavy (plain script) */
    { { {  -16,  29,  93,  68 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: L PUNCH C */
    { { {    5,  20,  96,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: L PUNCH C */
    { { {  -54,  45,  37,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP K S A, F JUMP K S A */
    { { {  -68,  39,   0,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 1 S: SA III 23623+P (plain script) */
    { { {  -88,  67,  36,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 8 L: not started by a command */
    { { { -154, 134,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: KAGAMI K A */
    { { { -150, 151,   0,  51 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: not used by a script */
    { { {  -71,  49,  29,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP P M A */
    { { { -119,  92,  86,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP P M A */
    { { {  -85,  60,  88,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP P M A */
    { { { -107,  78,  90,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP P S A */
    { { {  -94,  65,  88,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: V JUMP P S A */
    { { { -199, 172,  30,  18 },  {   23,  33,  29,  16 },  {   55,  18,  20,  17 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { { -199,  24,  30,  21 },  { -175, 141,  29,  22 },  {   23,  27,  27,  15 },  {   50,  21,  16,  17 } } },  /* 60: KAGAMI P A */
    { { { -128,  35,  29,  17 },  {  -93,  25,  37,  14 },  {  -74,  54,  40,  20 },  {    0,   0,   0,   0 } } },  /* 61: KAGAMI P A */
    { { {  -76,  18,  33,  14 },  {  -65,  15,  43,  13 },  {  -53,  14,  54,  14 },  {  -46,  40,  62,  20 } } },  /* 62: KAGAMI P A */
    { { { -178,  14,  38,  17 },  { -163, 141,  35,  17 },  {   20,  18,  33,  16 },  {   37,  19,  21,  19 } } },  /* 63: KAGAMI P A */
    { { { -173,  25,  88,  27 },  { -149,  58,  80,  22 },  { -104,  61,  69,  23 },  {  -45,  34,  60,  25 } } },  /* 64: not used by a script */
    { { { -155,  37,  83,  30 },  { -118,  56,  76,  22 },  {  -63,  46,  66,  22 },  {    0,   0,   0,   0 } } },  /* 65: L KICK A */
    { { {  -63,  32,  28,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: KAGAMI P A */
    { { {  -58,  35,  33,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: KAGAMI P A */
    { { { -121,  33, 104,  28 },  { -103,  38,  87,  30 },  {  -79,  37,  70,  28 },  {  -65,  45,  51,  36 } } },  /* 68: KAGAMI P A */
    { { {  -63,  49,  35,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: KAGAMI P A */
    { { {  -55,  27,  52,  14 },  {  -38,  29,  59,  14 },  {  -22,  34,  65,  13 },  {    0,   0,   0,   0 } } },  /* 70: KAGAMI P A */
    { { {  -91,  40,  39,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: CATCH 5 */
    { { {  -53,  42,  65,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: CATCH 5 */
    { { {  -34,  54,  74,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: CATCH 5 */
};

const HOSEI_BOX necro_hos_box[27] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -23,   46,    0,   82 } },  /* 1: HURIMUKI, FRONT WALK, DASH HUMIKOMI +100 */
    { {  -23,   46,    0,   58 } },  /* 2: KAGAMU, KAGAMI TURN, KAGAMI S +52 */
    { {  -25,   50,   68,   48 } },  /* 3: no name, TUKAMIHAZUSARE, V JUMP P S A +29 */
    { {  -35,   48,   72,   40 } },  /* 4: not used by a script */
    { {  -24,   48,   67,   40 } },  /* 5: not used by a script */
    { {  -31,   48,   70,   40 } },  /* 6: V JUMP K L A */
    { {  -22,   48,   70,   40 } },  /* 7: not used by a script */
    { {  -32,   48,   73,   40 } },  /* 8: not used by a script */
    { {  -21,   48,   30,   40 } },  /* 9: S PUNCH C, no name */
    { {   -1,   48,   37,   40 } },  /* 10: not used by a script */
    { {  -19,   48,   27,   40 } },  /* 11: not used by a script */
    { {  -32,   48,   31,   40 } },  /* 12: not used by a script */
    { {  -28,   48,   46,   56 } },  /* 13: not used by a script */
    { {  -11,   48,   32,   56 } },  /* 14: not used by a script */
    { {  -25,   48,   32,   56 } },  /* 15: not used by a script */
    { {   -4,   48,   58,   40 } },  /* 16: not used by a script */
    { {  -21,   48,   58,   40 } },  /* 17: not used by a script */
    { {  -55,   48,    0,   54 } },  /* 18: KAGAMI P C */
    { {  -72,   97,   22,   40 } },  /* 19: not used by a script */
    { {  -21,   27,   59,   43 } },  /* 20: not used by a script */
    { {  -43,   63,   61,   39 } },  /* 21: not used by a script */
    { {  -37,   64,    0,   79 } },  /* 22: P BREAK ZUJOU, TUKAMIHAZUSI, no name +2 */
    { {  -22,   48,   42,   37 } },  /* 23: BODY SLAM, TOMOE RYU, MONKEY FLIP +25 */
    { {  -27,   54,    0,   30 } },  /* 24: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 9 L: 214+K light (plain script), ATTACK 9 SP: 214+K medium (plain script) +4 */
    { {  -60,   96,   48,   27 } },  /* 25: V JUMP K S B */
    { {  -23,   46,    0,   76 } },  /* 26: BODY UPPER L, UPPER L, BODY BROW S +19 */
};
