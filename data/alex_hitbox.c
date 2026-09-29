/*
 * ALEX_HITBOX.C  Alex's hit boxes
 *
 * Each of Alex's animation frames names an entry of alex_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX alex_hit_ix_table[319] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +37 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +99 */
    {    3,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 2: DASH HUMIKOMI */
    {    0,    0,    0, 0x0000,    0,    0,    0,    7 },  /* 3: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    4,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 4: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +25 */
    {   42,    0,    0, 0x1010,    0,    3,    0,   27 },  /* 5: JUMP JUNBI, SP JUMP JUNBI */
    {    4,    0,    0, 0x0000,    0,    3,    0,    7 },  /* 6: SP JUMP JUNBI */
    {    0,    0,    0, 0x0000,    0,    0,    0,    8 },  /* 7: follow-up of AIR NORMAL */
    {    8,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 8: S PUNCH A */
    {    9,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 9: S PUNCH A */
    {    9,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 10: not used by a script */
    {   10,    0,    3, 0x0000,    0,    1,    2,    1 },  /* 11: S PUNCH B */
    {   11,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 12: S PUNCH B */
    {   12,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 13: PARING AIR F, GUARD AIR, CATCH 7 +13 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    8 },  /* 14: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   13,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 15: ATTACK 9 S: not started by a command */
    {   14,    0,    5, 0x0000,    0,    1,    3,    1 },  /* 16: M PUNCH A */
    {   15,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 17: not used by a script */
    {    5,    0,    0, 0x0000,    0,    1,    6,    1 },  /* 18: M PUNCH C */
    {   15,    0,    6, 0x0000,    0,    1,    5,    1 },  /* 19: L PUNCH A */
    {   16,    0,    7, 0x0000,    0,    1,   11,    4 },  /* 20: L PUNCH A */
    {   17,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 21: L PUNCH A */
    {   18,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 22: M PUNCH C */
    {   19,    0,   10, 0x0000,    0,    1,    7,    4 },  /* 23: M PUNCH C */
    {   20,    0,   11, 0x0000,    0,    1,   12,    5 },  /* 24: M PUNCH C */
    {   21,    0,   12, 0x0000,    0,    1,    0,    3 },  /* 25: M PUNCH C */
    {   22,    0,   13, 0x0000,    0,   15,    8,    3 },  /* 26: S KICK A */
    {   23,    0,   14, 0x0000,    0,   15,    0,    2 },  /* 27: S KICK A */
    {    2,    0,    0, 0x0000,    0,    1,    0,    4 },  /* 28: M KICK A */
    {   24,    0,    0, 0x0000,    0,    1,    9,    4 },  /* 29: M KICK A */
    {   13,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 30: M KICK A */
    {   25,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 31: M KICK B */
    {   26,    0,   15, 0x0000,    0,    1,   10,    2 },  /* 32: M KICK B */
    {   26,    0,   15, 0x0000,    0,    1,    0,    2 },  /* 33: M KICK B */
    {    0,    0,    0, 0x0000,    0,    0,    0,    7 },  /* 34: not used by a script */
    {   18,    0,    0, 0x0000,    0,    1,    0,    3 },  /* 35: M PUNCH C */
    {   24,    0,    0, 0x0000,    0,    1,   13,    1 },  /* 36: not used by a script */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 37: not used by a script */
    {   69,    0,   30, 0x0000,    0,    1,   38,    4 },  /* 38: L KICK A */
    {   69,    0,   30, 0x0000,    0,    1,    0,    4 },  /* 39: L KICK A */
    {  108,    0,    0, 0x0000,    0,   17,    0,   19 },  /* 40: L KICK A */
    {   30,    0,   17, 0x0000,    0,   16,   15,    7 },  /* 41: not used by a script */
    {   30,    0,   17, 0x0000,    0,    2,    0,    7 },  /* 42: KAGAMI P A */
    {   29,    0,   16, 0x0000,    0,    2,   16,    7 },  /* 43: KAGAMI P A */
    {   31,    0,    0, 0x0000,    0,    2,   17,    7 },  /* 44: KAGAMI P A */
    {   32,    0,    0, 0x0000,    0,    3,   18,    8 },  /* 45: KAGAMI P A */
    {   33,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 46: KAGAMI P A */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: follow-up of APPEAR JUNBI 7 */
    {   35,    0,   18, 0x0000,    0,   16,   19,    7 },  /* 48: KAGAMI K A */
    {   35,    0,   18, 0x0000,    0,   16,    0,    7 },  /* 49: KAGAMI K A */
    {   36,    0,   19, 0x0000,    0,    2,   20,    7 },  /* 50: KAGAMI K A */
    {   37,    0,   20, 0x0000,    0,    2,   21,    7 },  /* 51: KAGAMI K A */
    {   38,    0,    0, 0x0000,    0,    2,   22,    7 },  /* 52: not used by a script */
    {   38,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 53: KAGAMI K A */
    {   36,    0,   19, 0x0000,    0,    2,    0,    7 },  /* 54: KAGAMI K A */
    {   37,    0,   20, 0x0000,    0,    2,    0,    7 },  /* 55: KAGAMI K A */
    {   39,    0,   21, 0x0000,    0,    3,   23,    8 },  /* 56: V JUMP P S A */
    {   40,    0,   22, 0x0000,    0,    3,   24,    8 },  /* 57: not used by a script */
    {   65,    0,    0, 0x0000,    0,    2,    0,   23 },  /* 58: SP F JP L P B */
    {    6,    0,    0, 0x0000,    0,    3,   25,    8 },  /* 59: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    7 },  /* 60: OKIAGARI, OKIAGARI F, OKIAGARI B +18 */
    {   41,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 61: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,   22 },  /* 62: NEKOROBI S, no name */
    {   42,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 63: ATTACK 9 S: not started by a command */
    {   44,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 64: not used by a script */
    {   45,    0,   23, 0x0000,    0,    3,   26,    8 },  /* 65: not used by a script */
    {   45,    0,   23, 0x0000,    0,    3,    0,    8 },  /* 66: not used by a script */
    {   46,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 67: not used by a script */
    {   47,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 68: not used by a script */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 69: UP P GUARD P L */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 70: UP P GUARD P L */
    {   50,    0,    0, 0x0000,    0,    1,   27,    1 },  /* 71: UP P GUARD P L */
    {   51,    0,   24, 0x0000,    0,    1,   28,    1 },  /* 72: UP P GUARD P L */
    {   49,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 73: UP P GUARD P L */
    {   52,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 74: AIR NORMAL, BODY SLAM, IPPONZEOI +11 */
    {   53,    0,   25, 0x0000,    2,    1,    0,    3 },  /* 75: L PUNCH C */
    {   54,    0,   26, 0x0000,    0,    1,    0,    3 },  /* 76: L PUNCH C */
    {   54,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 77: not used by a script */
    {   55,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 78: V JUMP P L A */
    {   56,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 79: V JUMP P L A */
    {   57,    0,   27, 0x0000,    0,    3,   30,    8 },  /* 80: V JUMP P L A */
    {   58,    0,   28, 0x0000,    0,    3,   31,    8 },  /* 81: V JUMP P L A */
    {   59,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 82: V JUMP P L A */
    {   60,    0,    0, 0x0000,    0,    3,   32,    8 },  /* 83: V JUMP K S A */
    {   61,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 84: not used by a script */
    {   62,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 85: not used by a script */
    {   63,    0,    0, 0x0000,    0,    3,   33,    8 },  /* 86: not used by a script */
    {   63,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 87: not used by a script */
    {   64,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 88: ATTACK 9 S: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,   34,    1 },  /* 89: not used by a script */
    {    1,    0,    0, 0x0000,    1,    1,   39,    1 },  /* 90: TUKAMIKAKARI A */
    {    7,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 91: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   66,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 92: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   67,    0,   29, 0x0000,    0,   11,   36,   16 },  /* 93: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   80,    0,    0, 0x0000,    0,   11,    0,   16 },  /* 94: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    {   71,    0,   31, 0x0000,    3,    1,   35,    1 },  /* 95: ATTACK 3 S: 6(123)4+P light (plain script) */
    {   71,    0,   31, 0x0000,    4,    1,   37,    1 },  /* 96: ATTACK 3 M: 6(123)4+P medium (plain script) */
    {   70,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 97: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +1 */
    {   71,    0,   31, 0x0000,    5,    1,   40,    1 },  /* 98: ATTACK 3 L: 6(123)4+P heavy/EX (plain script) */
    {   71,    0,   31, 0x0000,    0,    4,    0,    9 },  /* 99: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    {    0,    0,    0, 0x0000,    9,    1,   49,    1 },  /* 100: ATTACK 4 S: SA I 360+P (plain script) */
    {   72,    0,   32, 0x0000,    0,    2,    0,    7 },  /* 101: KAGAMI P A */
    {   68,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 102: not used by a script */
    {   73,    0,    0, 0x0000,    6,   14,    0,   21 },  /* 103: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {   73,    0,    0, 0x0000,    7,   14,    0,   21 },  /* 104: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) +2 */
    {   74,    0,    0, 0x0000,    0,    7,    0,   12 },  /* 105: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   75,    0,    0, 0x0000,    0,    8,    0,   13 },  /* 106: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   76,    0,    0, 0x0000,    0,    9,    0,   14 },  /* 107: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    {   76,    0,    0, 0x0000,    0,    9,   44,   14 },  /* 108: not used by a script */
    {   77,    0,    0, 0x0000,    0,   10,   45,   15 },  /* 109: not used by a script */
    {   77,    0,    0, 0x0000,    0,   10,    0,   15 },  /* 110: not used by a script */
    {   78,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 111: ATTACK 9 S: not started by a command */
    {   40,    0,   22, 0x0000,    8,    3,   46,    8 },  /* 112: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   79,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 113: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 114: not used by a script */
    {    0,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 115: not used by a script */
    {   81,    0,    0, 0x0000,    0,    1,    0,   10 },  /* 116: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 117: ATTACK 4 S: SA I 360+P (plain script), ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI), ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    {   82,    0,    0, 0x0000,    0,    1,   47,    0 },  /* 118: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +1 */
    {   82,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 119: ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 9 S: not started by a command */
    {   78,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 120: ATTACK 9 S: not started by a command */
    {   83,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 121: V JUMP K L A */
    {   84,    0,    0, 0x0000,    0,    5,    0,    8 },  /* 122: V JUMP K L A */
    {   85,    0,    0, 0x0000,    0,    5,   48,    8 },  /* 123: V JUMP K L A */
    {   85,    0,    0, 0x0000,    0,    5,    0,    8 },  /* 124: V JUMP K L A */
    {    0,    0,    0, 0x0000,    0,    0,   50,    3 },  /* 125: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,    0,    0,   51,    3 },  /* 126: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   87,    0,    0, 0x0000,    0,    1,   52,    3 },  /* 127: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   87,    0,    0, 0x0000,    0,    1,   53,    3 },  /* 128: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   88,    0,    0, 0x0000,    0,    1,   54,    3 },  /* 129: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   88,    0,    0, 0x0000,    0,    1,   55,    3 },  /* 130: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   89,    0,    0, 0x0000,    0,    1,   56,    3 },  /* 131: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   89,    0,    0, 0x0000,    0,    1,   57,    3 },  /* 132: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   90,    0,    0, 0x0000,    0,    1,    0,    3 },  /* 133: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   91,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 134: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   92,    0,   33, 0x0000,    0,    1,   58,    1 },  /* 135: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   93,    0,   34, 0x0000,    0,    1,   59,    1 },  /* 136: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   94,    0,   35, 0x0000,    0,    1,    0,    1 },  /* 137: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    {   95,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 138: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   96,    0,   36, 0x0000,    0,    1,   60,    1 },  /* 139: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   97,    0,   37, 0x0000,    0,    1,   61,    1 },  /* 140: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   98,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 141: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    {   99,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 142: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  100,    0,   39, 0x0000,    0,    1,   62,    1 },  /* 143: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    {  101,    0,   40, 0x0000,    0,    1,   63,    1 },  /* 144: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    {  102,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 145: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  103,    0,    0, 0x0000,    0,   13,    0,   20 },  /* 146: PIYO */
    {  104,    0,    0, 0x1010,    0,   13,    0,   20 },  /* 147: PIYO */
    {  105,    0,    0, 0x1515,    0,   13,    0,   20 },  /* 148: PIYO */
    {   86,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 149: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  106,    0,   42, 0x0000,    0,   11,   64,   16 },  /* 150: F JUMP P L B, SP F JP L P B */
    {  107,    0,   43, 0x0000,    0,   11,   65,   16 },  /* 151: F JUMP P L B, SP F JP L P B */
    {   30,    0,   17, 0x0000,    0,   16,    0,    7 },  /* 152: not used by a script */
    {   72,    0,   32, 0x0000,    0,   16,    0,    7 },  /* 153: KAGAMI P A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 154: follow-up of APPEAR 8 */
    {    4,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 155: follow-up of APPEAR 8 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 156: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
    {   71,    0,   31, 0x0000,   10,    1,    0,    1 },  /* 157: ATTACK 5 SP: after SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  109,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 158: ATTACK 10 S: not started by a command */
    {  110,    0,    0, 0x0000,    0,    1,    0,   26 },  /* 159: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  111,    0,    0, 0x0000,    0,    1,    0,   24 },  /* 160: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  112,    0,    0, 0x0000,    0,    1,    0,   25 },  /* 161: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  113,    0,    0, 0x0000,    0,    1,    0,   25 },  /* 162: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  114,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 163: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   14,    0,   46, 0x0000,    0,    1,   66,    1 },  /* 164: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    {  113,    0,    0, 0x0000,    0,    1,   67,   25 },  /* 165: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    {  109,    0,    0, 0x0000,    0,    1,   29,    1 },  /* 166: not used by a script */
    {  115,    0,   45, 0x0000,    0,    1,   68,    1 },  /* 167: not used by a script */
    {  115,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 168: not used by a script */
    {  115,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 169: not used by a script */
    {   28,    0,    0, 0x0000,    0,    0,    0,   22 },  /* 170: no name */
    {  100,    0,    8, 0x0000,    0,    1,   62,    1 },  /* 171: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {  101,    0,    9, 0x0000,    0,    1,   63,    1 },  /* 172: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    {   14,    0,   44, 0x0000,    0,    1,   69,    1 },  /* 173: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    {   40,    0,   22, 0x0000,    0,    3,    0,    8 },  /* 174: not used by a script */
    {  116,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 175: UPPER L, BODY UPPER L */
    {  117,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 176: UPPER L, BODY UPPER L */
    {  118,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 177: not used by a script */
    {  119,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 178: UPPER L, BODY UPPER L */
    {  120,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 179: FACE S, FACE M, FACE L +5 */
    {  121,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 180: FACE M, FACE L, FOOK OKU L +3 */
    {  122,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 181: FACE L, FOOK OKU L, FOOK TEMAE L */
    {  123,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 182: FACE L, FOOK OKU L, FOOK TEMAE L */
    {  124,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 183: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  125,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 184: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    {  126,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 185: NOUTEN L, BODY BROW L */
    {  127,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 186: NOUTEN L, BODY BROW L, TATAKI S +3 */
    {  128,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 187: TATAKI V. S, TATAKI V. M, TATAKI V. L +15 */
    {  129,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 188: KAGAMI M, KAGAMI L, KGM TATAKI S +7 */
    {  130,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 189: KAGAMI L */
    {  131,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 190: KAGAMI L */
    {  132,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 191: V JUMP P M A */
    {  133,    0,   47, 0x0000,    0,    3,   70,    8 },  /* 192: V JUMP P M A */
    {  134,    0,   48, 0x0000,    0,    3,    0,    8 },  /* 193: V JUMP P M A */
    {  134,    0,   49, 0x0000,    0,    3,    0,    8 },  /* 194: V JUMP P M A */
    {  135,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 195: V JUMP K M A */
    {  136,    0,   50, 0x0000,    0,    3,    0,    8 },  /* 196: V JUMP K M A */
    {  137,    0,   51, 0x0000,    0,    3,   71,    8 },  /* 197: V JUMP K M A */
    {  137,    0,   51, 0x0000,    0,    3,   72,    8 },  /* 198: V JUMP K M A */
    {  137,    0,   52, 0x0000,    0,    3,    0,    8 },  /* 199: V JUMP K M A */
    {  138,    0,   53, 0x0000,    0,    3,    0,    8 },  /* 200: V JUMP K M A */
    {  139,    0,   54, 0x0000,    0,    3,    0,    8 },  /* 201: V JUMP K M A */
    {  140,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 202: V JUMP K M A */
    {  141,    0,    0, 0x0000,    0,    1,    0,   27 },  /* 203: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    {  142,    0,    0, 0x0000,    0,    3,    0,   28 },  /* 204: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    {  143,    0,    0, 0x0000,    0,    3,    0,   28 },  /* 205: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    {  173,    0,   56, 0x0000,   11,    3,    0,   28 },  /* 206: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    {   30,    0,   55, 0x0000,    0,   16,   73,    7 },  /* 207: KAGAMI P A */
    {   30,    0,   55, 0x0000,    0,   16,   74,    7 },  /* 208: KAGAMI P A */
    {   30,    0,   55, 0x0000,    0,   16,    0,    7 },  /* 209: KAGAMI P A */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 210: KAMAE */
    {  144,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 211: KAMAE */
    {  145,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 212: HURIMUKI */
    {  146,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 213: FRONT WALK */
    {  147,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 214: FRONT WALK */
    {  148,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 215: FRONT WALK */
    {  149,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 216: FRONT WALK */
    {  148,    0,    0, 0x1919,    0,    1,    0,    1 },  /* 217: FRONT WALK */
    {  150,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 218: FRONT WALK */
    {  151,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 219: BACK WALK */
    {  152,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 220: BACK WALK */
    {  153,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 221: BACK WALK */
    {  154,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 222: BACK WALK */
    {  155,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 223: BACK WALK */
    {  156,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 224: BACK WALK */
    {  157,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 225: DASH HUMIKOMI */
    {  158,    0,    0, 0x1010,    0,    1,    0,   27 },  /* 226: DASH HUMIKOMI */
    {  159,    0,    0, 0x1111,    0,    1,    0,   27 },  /* 227: DASH HUMIKOMI */
    {  160,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 228: DASH TOBINOKI */
    {  161,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 229: DASH TOBINOKI */
    {  162,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 230: DASH TOBINOKI */
    {  163,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 231: DASH TOBINOKI */
    {  164,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 232: DASH TOBINOKI, L PUNCH B */
    {    1,    0,    0, 0x1010,    0,    2,    0,   27 },  /* 233: KAGAMU */
    {  165,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 234: KAGAMI TURN */
    {    4,    0,    0, 0x1010,    0,    1,    0,    7 },  /* 235: STAND UP */
    {  166,    0,    0, 0x1010,    0,    1,    0,   27 },  /* 236: STAND UP */
    {  167,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 237: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  167,    0,    0, 0x1010,    0,    3,    0,    8 },  /* 238: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  168,    0,    0, 0x1010,    0,    3,    0,    8 },  /* 239: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  169,    0,    0, 0x1010,    0,    3,    0,    8 },  /* 240: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    {  170,    0,    0, 0x0000,    0,    3,    0,    8 },  /* 241: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    {  171,    0,    0, 0x0000,    0,    3,    0,   28 },  /* 242: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    {  172,    0,    0, 0x0000,    0,    3,    0,   28 },  /* 243: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    {  173,    0,   56, 0x0000,    0,    3,    0,   28 },  /* 244: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    {  174,    0,    0, 0x0000,    0,    3,   75,    8 },  /* 245: ATTACK 9 S: not started by a command */
    {  175,    0,   57, 0x0000,    0,    1,    0,    1 },  /* 246: L PUNCH B */
    {  176,    0,   58, 0x0000,    0,    1,    0,    1 },  /* 247: L PUNCH B */
    {  177,    0,   59, 0x0000,    0,    1,   76,    1 },  /* 248: L PUNCH B */
    {  178,    0,   60, 0x0000,    0,    1,   77,    1 },  /* 249: L PUNCH B */
    {  179,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 250: L PUNCH B */
    {  180,    0,   62, 0x0000,    0,    1,    0,    1 },  /* 251: L PUNCH B */
    {  181,    0,   63, 0x0000,    0,    1,    0,    1 },  /* 252: L PUNCH B */
    {  182,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 253: AIR NORMAL */
    {  183,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 254: ASIBARAI SIRI */
    {  184,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 255: ASIBARAI SIRI */
    {  185,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 256: ASIBARAI SIRI */
    {  186,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 257: ASIBARAI SIRI */
    {  187,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 258: ASIBARAI SIRI */
    {  188,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 259: ASIBARAI SIRI */
    {  189,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 260: ASIBARAI SIRI */
    {  190,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 261: ASIB TUNNOMERI, HUMI ASIB */
    {  191,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 262: ASIB TUNNOMERI, HUMI ASIB */
    {  192,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 263: NOKEZORI, BODY UPPER SP */
    {  193,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 264: NOKEZORI, UPPER, FACE +2 */
    {  194,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 265: NOKEZORI, UPPER, BODY UPPER SP +1 */
    {  195,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 266: NOKEZORI, UPPER, BODY UPPER SP +1 */
    {  196,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 267: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  197,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 268: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  198,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 269: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  199,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 270: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  200,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 271: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  201,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 272: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    {  202,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 273: KUNOJI, KUNOJI NOKE */
    {  203,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 274: KUNOJI, KUNOJI NOKE */
    {  204,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 275: KUNOJI, KUNOJI NOKE */
    {  205,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 276: KUNOJI, KUNOJI NOKE */
    {  206,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 277: KUNOJI, KUNOJI NOKE */
    {  207,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 278: KIRIMOMI */
    {  208,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 279: KIRIMOMI */
    {  209,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 280: KIRIMOMI */
    {  210,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 281: KIRIMOMI */
    {  211,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 282: KIRIMOMI */
    {  212,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 283: KIRIMOMI */
    {  213,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 284: KIRIMOMI */
    {  214,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 285: KIRIMOMI */
    {  215,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 286: KIRIMOMI */
    {  216,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 287: KIRIMOMI */
    {  217,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 288: KIRIMOMI */
    {  218,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 289: KIRIMOMI */
    {  219,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 290: KIRIMOMI */
    {  220,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 291: KIRIMOMI */
    {  221,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 292: KIRIMOMI */
    {  222,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 293: UPPER, HARAYARARE, TATAKI AIR +2 */
    {  223,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 294: UPPER, TATUMAKIZANKU */
    {  224,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 295: UPPER, TATUMAKIZANKU */
    {  225,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 296: UPPER, TATUMAKIZANKU */
    {  226,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 297: BODY UPPER */
    {  227,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 298: BODY UPPER */
    {  228,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 299: BODY UPPER */
    {  229,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 300: BODY UPPER */
    {  230,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 301: BODY UPPER, HARAYARARE, HANEKAERI HARA */
    {  231,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 302: BODY UPPER, HARAYARARE, FACE */
    {  232,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 303: BODY UPPER, HARAYARARE, FACE */
    {  233,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 304: BODY UPPER, HARAYARARE, FACE */
    {  234,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 305: BODY UPPER, HARAYARARE, FACE */
    {  235,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 306: BODY UPPER */
    {  236,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 307: BODY UPPER, HARAYARARE, FACE */
    {  237,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 308: BODY UPPER, HARAYARARE, FACE */
    {  238,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 309: not used by a script */
    {  239,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 310: TATAKI AIR */
    {  240,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 311: TATAKI AIR */
    {  241,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 312: TATAKI AIR */
    {  242,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 313: TATAKI AIR */
    {  243,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 314: TTKI V. AIR */
    {  244,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 315: TTKI V. AIR */
    {  245,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 316: TTKI V. AIR */
    {  246,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 317: FACE, TOUKETSU A */
    {  247,    0,    0, 0x0000,    0,   12,    0,   18 },  /* 318: DENKI */
};

const BODY_BOX alex_body_box[248] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -23,  32,  86,  19 },  {  -37,  74,  71,  19 },  {  -30,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +103 */
    { { {  -25,  34, 102,  18 },  {  -38,  76,  74,  26 },  {  -29,  66,  42,  30 },  {  -30,  89,   0,  40 } } },  /* 2: M KICK A */
    { { {  -18,  32,  76,  19 },  {  -30,  70,  65,  23 },  {  -33,  77,  37,  28 },  {  -37, 100,   0,  37 } } },  /* 3: DASH HUMIKOMI */
    { { {  -27,  44,  48,  20 },  {  -40,  72,  43,  20 },  {  -44,  86,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 4: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +27 */
    { { {  -50,  43, 102,  26 },  {  -50,  78,  74,  28 },  {  -41,  78,  39,  35 },  {  -43, 103,   0,  39 } } },  /* 5: M PUNCH C */
    { { {  -26,  37,  96,  23 },  {  -58,  89,  85,  14 },  {  -82, 113,  66,  18 },  {  -90, 123,  49,  17 } } },  /* 6: not used by a script */
    { { {  -37,  37,  93,  20 },  {  -43,  77,  84,  22 },  {  -48,  86,  76,  18 },  {  -48,  86,  55,  21 } } },  /* 7: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  30 },  {  -51,  95,   0,  32 } } },  /* 8: S PUNCH A */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 9: S PUNCH A */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  32 },  {  -53, 104,   0,  34 } } },  /* 10: S PUNCH B */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -38,  76,  34,  32 },  {  -44,  88,   0,  34 } } },  /* 11: S PUNCH B */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -36,  67,  58,  30 },  {  -41,  72,  38,  26 } } },  /* 12: PARING AIR F, GUARD AIR, CATCH 7 +13 */
    { { {  -55,  87,  92,  18 },  {  -47,  79,  76,  15 },  {  -58,  90,  52,  22 },  {  -14,  45,   0,  50 } } },  /* 13: ATTACK 9 S: not started by a command, M KICK A */
    { { {  -42,  46,  89,  16 },  {  -42,  81,  66,  30 },  {  -45,  84,  34,  32 },  {  -50, 102,   0,  34 } } },  /* 14: M PUNCH A, ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -34,  52,  68,  38 },  {  -34,  68,  60,  32 },  {  -30,  78,  34,  26 },  {  -30,  88,   0,  32 } } },  /* 15: L PUNCH A */
    { { {  -45,  79,  78,  22 },  {  -29,  63,  51,  27 },  {  -29,  77,  40,  21 },  {  -30,  88,   0,  40 } } },  /* 16: L PUNCH A */
    { { {  -38,  43,  88,  14 },  {  -38,  76,  56,  36 },  {  -30,  76,  34,  20 },  {  -30,  88,   0,  32 } } },  /* 17: L PUNCH A */
    { { {  -12,  34, 102,  18 },  {  -38,  83,  73,  28 },  {  -30,  76,  41,  31 },  {  -37,  92,   0,  39 } } },  /* 18: M PUNCH C */
    { { {  -43,  49,  81,  20 },  {  -34,  74,  58,  23 },  {  -42,  90,  32,  26 },  {  -41, 110,   0,  32 } } },  /* 19: M PUNCH C */
    { { {  -50,  88,  71,  19 },  {  -68, 114,  56,  15 },  {  -30,  76,  29,  27 },  {  -30, 118,   0,  29 } } },  /* 20: M PUNCH C */
    { { {  -50,  88,  71,  19 },  {  -50,  98,  56,  15 },  {  -29,  77,  29,  27 },  {  -30, 118,   0,  29 } } },  /* 21: M PUNCH C */
    { { {  -36,  54,  92,  19 },  {  -46,  79,  66,  26 },  {  -66,  99,  34,  32 },  {  -14,  47,   0,  34 } } },  /* 22: S KICK A */
    { { {  -36,  54,  92,  19 },  {  -46,  79,  66,  26 },  {  -66,  99,  34,  32 },  {  -14,  47,   0,  34 } } },  /* 23: S KICK A */
    { { {  -55,  87,  92,  18 },  {  -62,  94,  76,  16 },  {  -22,  54,  52,  22 },  {  -14,  46,   0,  52 } } },  /* 24: M KICK A */
    { { {  -37,  44,  94,  21 },  {  -55,  86,  66,  35 },  {  -35,  66,  34,  30 },  {  -30,  61,   0,  32 } } },  /* 25: M KICK B */
    { { {   40,  46,  66,  26 },  {  -38,  78,  66,  26 },  {  -52,  34,  49,  36 },  {  -30,  61,   0,  64 } } },  /* 26: M KICK B */
    { { {   -2,  22,  94,  14 },  {  -16,  64,  80,  14 },  {  -16,  60,  46,  30 },  {   -8,  36,   0,  44 } } },  /* 27: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 28: no name */
    { { {  -33,  67,  53,  18 },  {  -58,  96,  35,  27 },  {  -37,  74,  22,  20 },  {  -52, 100,   0,  22 } } },  /* 29: KAGAMI P A */
    { { {  -33,  50,  53,  18 },  {  -58,  96,  38,  27 },  {  -37,  74,  22,  20 },  {  -52, 100,   0,  22 } } },  /* 30: KAGAMI P A */
    { { {  -72,  73,  67,  33 },  {  -72,  84,  45,  22 },  {  -62,  97,  30,  15 },  {  -39, 103,   0,  30 } } },  /* 31: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 32: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 33: KAGAMI P A */
    { { {  -63,  82, 105,  29 },  {  -63,  97,  71,  34 },  {  -48,  89,  41,  30 },  {  -21,  82,  23,  25 } } },  /* 34: follow-up of APPEAR JUNBI 7 */
    { { {  -32,  54,  55,  18 },  {  -58,  97,  42,  23 },  {    0,   0,   0,   0 },  {  -30,  78,   0,  42 } } },  /* 35: KAGAMI K A */
    { { {  -32,  54,  58,  18 },  {  -59,  98,  42,  27 },  {    0,   0,   0,   0 },  {  -30,  70,   0,  42 } } },  /* 36: KAGAMI K A */
    { { {  -42,  76,  47,  18 },  {  -74, 113,  30,  26 },  {    0,   0,   0,   0 },  {  -30,  78,   0,  40 } } },  /* 37: KAGAMI K A */
    { { {  -38,  71,  50,  18 },  {  -85, 124,  27,  30 },  {    0,   0,   0,   0 },  {  -92, 140,   0,  40 } } },  /* 38: KAGAMI K A */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -64,  97,  58,  36 },  {  -45,  84,  33,  28 } } },  /* 39: V JUMP P S A */
    { { {  -30,  37, 101,  20 },  {  -44,  75,  81,  31 },  {  -63,  96,  63,  28 },  {  -44,  81,  36,  29 } } },  /* 40: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { { {  -48,  26,  84,  19 },  {  -42,  62,  81,  25 },  {  -41,  68,  64,  21 },  {  -36,  65,  40,  26 } } },  /* 41: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +1 */
    { { {  -23,  32,  65,  19 },  {  -37,  74,  55,  19 },  {  -35,  69,  34,  21 },  {  -44,  88,   0,  34 } } },  /* 42: JUMP JUNBI, SP JUMP JUNBI, ATTACK 9 S: not started by a command */
    { { {   -6,  22,  88,  16 },  {    2,  38,  84,  18 },  {    4,  40,  48,  34 },  {  -18,  52,  16,  30 } } },  /* 43: not used by a script */
    { { {  -18,  22,  94,  16 },  {  -22,  52,  88,  12 },  {  -12,  38,  48,  38 },  {  -30,  56,  16,  30 } } },  /* 44: not used by a script */
    { { {  -18,  22,  94,  16 },  {  -22,  52,  88,  12 },  {  -12,  38,  48,  38 },  {  -30,  56,  16,  30 } } },  /* 45: not used by a script */
    { { {   -8,  22,  98,  16 },  {  -12,  48,  88,  16 },  {   -8,  40,  48,  38 },  {  -22,  44,  16,  30 } } },  /* 46: not used by a script */
    { { {  -26,  22,  98,  16 },  {  -32,  50,  88,  16 },  {  -22,  40,  48,  38 },  {  -28,  50,  16,  30 } } },  /* 47: not used by a script */
    { { {   -7,  32,  84,  16 },  {  -26,  59,  66,  18 },  {  -41,  76,  44,  22 },  {  -56,  93,   0,  44 } } },  /* 48: UP P GUARD P L */
    { { {  -30,  51,  87,  16 },  {  -39,  70,  73,  14 },  {  -47,  81,  52,  20 },  {  -59,  96,   0,  52 } } },  /* 49: UP P GUARD P L */
    { { {  -46,  53,  98,  16 },  {  -45,  65,  84,  15 },  {  -48,  63,  52,  32 },  {  -59,  96,   0,  52 } } },  /* 50: UP P GUARD P L */
    { { {  -12,  22, 102,  16 },  {  -34,  54,  84,  18 },  {  -30,  36,  52,  30 },  {  -30,  48,   0,  50 } } },  /* 51: UP P GUARD P L */
    { { {  -33,  53,  95,  17 },  {  -38,  67,  75,  30 },  {  -37,  67,  43,  32 },  {  -32,  53,  36,  16 } } },  /* 52: AIR NORMAL, BODY SLAM, IPPONZEOI +11 */
    { { {  -38,  76,  82,  16 },  {  -38,  76,  66,  16 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 53: L PUNCH C */
    { { {  -38,  76,  82,  16 },  {  -38,  76,  66,  16 },  {  -38,  76,  34,  30 },  {  -44,  88,   0,  32 } } },  /* 54: L PUNCH C */
    { { {  -35,  52, 109,  17 },  {  -65,  97,  73,  36 },  {  -43,  75,  42,  31 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP P L A */
    { { {  -35,  52, 109,  17 },  {  -65,  97,  73,  36 },  {  -43,  75,  42,  31 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP P L A */
    { { {  -44,  42,  95,  17 },  {  -28,  48,  83,  22 },  {  -41,  77,  38,  45 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP P L A */
    { { {  -51,  48,  95,  17 },  {  -51,  71,  83,  22 },  {  -27,  63,  38,  45 },  {    0,   0,   0,   0 } } },  /* 58: V JUMP P L A */
    { { {  -53,  88,  87,  24 },  {  -44,  78,  57,  30 },  {  -34,  67,  38,  19 },  {    0,   0,   0,   0 } } },  /* 59: V JUMP P L A */
    { { {  -31,  71,  86,  37 },  {  -60, 116,  56,  30 },  {  -49,  80,  44,  12 },  {    0,   0,   0,   0 } } },  /* 60: V JUMP K S A */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 61: not used by a script */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 62: not used by a script */
    { { {   42,  27,  61,  30 },  {    2,  40,  45,  46 },  { -120, 122,  52,  35 },  {    0,   0,   0,   0 } } },  /* 63: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -44,  89,   0,  49 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 9 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -57, 104,   0,  66 },  {    0,   0,   0,   0 } } },  /* 65: SP F JP L P B */
    { { {  -60,  33,  43,  50 },  {  -44,  61,  62,  43 },  {  -39,  72,  32,  30 },  {    0,   0,   0,   0 } } },  /* 66: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  66,  62,  39 },  {    0,   0,   0,   0 } } },  /* 67: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {  -33,  50,  53,  18 },  {  -46,  92,  41,  22 },  {  -91, 140,  24,  15 },  {  -91, 143,   0,  22 } } },  /* 68: not used by a script */
    { { {  -15,  56, 101,  23 },  {  -35,  80,  82,  27 },  {  -20,  54,  48,  53 },  {   -3,  56,   0,  59 } } },  /* 69: L KICK A */
    { { {  -20,  22,  80,  16 },  {  -32,  66,  69,  13 },  {  -33,  50,  43,  28 },  {  -49,  79,   0,  40 } } },  /* 70: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +1 */
    { { {  -61,  42,  69,  22 },  {  -61,  72,  50,  29 },  {  -51,  83,  30,  28 },  {  -51, 108,   0,  29 } } },  /* 71: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { { {  -27,  44,  48,  22 },  {  -48,  87,  43,  21 },  {  -48,  92,  23,  19 },  {  -50,  95,   0,  22 } } },  /* 72: KAGAMI P A */
    { { {  -27,  61,  78,  25 },  {  -27,  62,  55,  23 },  {  -41,  86,  35,  20 },  {  -15,  68,  12,  23 } } },  /* 73: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) +2 */
    { { {  -30,  34, 143,  20 },  {  -52,  89, 139,  21 },  {  -46,  78, 115,  24 },  {  -34,  60,  82,  33 } } },  /* 74: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -30,  34, 143,  20 },  {  -52,  89, 139,  21 },  {  -46,  78, 115,  24 },  {  -34,  60,  82,  33 } } },  /* 75: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -35,  38, 146,  19 },  {  -54,  87, 137,  22 },  {  -47,  76, 116,  21 },  {  -44,  68,  93,  23 } } },  /* 76: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -6,  19, 113,  17 },  {  -24,  57,  98,  23 },  {  -32,  44,  72,  24 },  {  -38,  45,   4,  66 } } },  /* 77: not used by a script */
    { { {  -29,  19,  97,  18 },  {  -33,  50,  84,  20 },  {  -23,  45,  55,  28 },  {  -27,  49,  -2,  56 } } },  /* 78: ATTACK 9 S: not started by a command */
    { { {  -42,  22,  60,  16 },  {  -36,  50,  50,  20 },  {  -26,  46,  32,  20 },  {  -42,  68,   0,  36 } } },  /* 79: not used by a script */
    { { {  -90,  53,  38,  41 },  {  -59,  68,  59,  37 },  {   -9,  48,  41,  55 },  {    0,   0,   0,   0 } } },  /* 80: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  76,   0,  33 } } },  /* 81: not used by a script */
    { { {   -8,  20, 110,  20 },  {  -24,  56,  94,  24 },  {  -26,  44,  68,  28 },  {  -30,  44,   4,  62 } } },  /* 82: ATTACK 8 S: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 M: after [2](789)+K (routine Att_SENPUUKYAKU), ATTACK 8 L: after [2](789)+K (routine Att_HOMING_JUMP), [2](789)+K (routine Att_SENPUUKYAKU) +2 */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 83: V JUMP K L A */
    { { {  -12,  59,  95,  23 },  {  -34,  88,  64,  31 },  {  -49,  74,  42,  43 },  {    0,   0,   0,   0 } } },  /* 84: V JUMP K L A */
    { { {   26,  24,  59,  27 },  {   -1,  44,  43,  43 },  {  -52,  51,  45,  47 },  { -114,  62,  51,  41 } } },  /* 85: V JUMP K L A */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  78,  14 },  {  -61, 100,  34,  44 },  {  -66, 124,   0,  34 } } },  /* 86: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -45,  83,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 87: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -50, 103,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 88: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -25,  34,  89,  18 },  {  -38,  76,  66,  26 },  {  -50, 103,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 89: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -38,  43,  83,  18 },  {  -38,  76,  66,  26 },  {  -46,  84,  32,  34 },  {  -66, 124,   0,  32 } } },  /* 90: ATTACK 5 S: SA II 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 91: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  27 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 92: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 93: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  31,  85,  17 },  {  -34,  55,  78,  15 },  {  -31,  65,  40,  38 },  {  -34,  89,   0,  40 } } },  /* 94: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 95: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 96: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 97: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -73, 100,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 98: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {    9,  50,  75,  19 },  {    2,  45,  53,  22 },  {  -10,  52,  30,  23 },  {  -62, 104,   0,  30 } } },  /* 99: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 100: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -43,  76,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 101: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -34,  49,  84,  18 },  {  -73, 100,  66,  19 },  {  -43,  76,  40,  26 },  {  -34,  89,   0,  40 } } },  /* 102: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -57,  32,  48,  19 },  {  -47,  58,  46,  36 },  {  -50,  76,  25,  21 },  {  -51,  99,   0,  25 } } },  /* 103: PIYO */
    { { {  -44,  32,  52,  19 },  {  -35,  57,  46,  38 },  {  -48,  76,  25,  21 },  {  -51,  99,   0,  25 } } },  /* 104: PIYO */
    { { {  -46,  32,  57,  19 },  {  -34,  55,  46,  43 },  {  -48,  76,  25,  21 },  {  -51,  99,   0,  25 } } },  /* 105: PIYO */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  66,  62,  39 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L B, SP F JP L P B */
    { { { -100,  60,  81,  17 },  {  -40,  30,  48,  50 },  {  -10,  66,  62,  39 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L B, SP F JP L P B */
    { { {  -32,  61,  89,  18 },  {  -52,  94,  78,  14 },  {  -52,  94,  34,  44 },  {  -59, 107,   0,  34 } } },  /* 108: L KICK A */
    { { {  -25,  34, 104,  18 },  {  -42,  76,  91,  13 },  {  -37,  68,  47,  44 },  {  -36,  66,   0,  47 } } },  /* 109: ATTACK 10 S: not started by a command */
    { { {  -22,  34,  74,  18 },  {  -38,  76,  67,  13 },  {  -42,  76,  23,  44 },  {  -52,  95,   0,  29 } } },  /* 110: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -22,  34,  65,  18 },  {  -38,  69,  60,  13 },  {  -47,  76,  23,  37 },  {  -59,  99,   0,  28 } } },  /* 111: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -46,  34,  63,  18 },  {  -58,  69,  57,  13 },  {  -63,  91,  26,  33 },  {  -50, 100,   0,  28 } } },  /* 112: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -46,  34,  58,  18 },  {  -56,  69,  52,  13 },  {  -63,  91,  24,  33 },  {  -49, 100,   0,  28 } } },  /* 113: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -48,  34,  74,  18 },  {  -61,  75,  67,  16 },  {  -45,  64,  23,  44 },  {  -52,  95,   0,  29 } } },  /* 114: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -27,  41, 105,  18 },  {  -44,  78,  85,  24 },  {  -45,  82,  34,  51 },  {  -44,  81,   0,  34 } } },  /* 115: not used by a script */
    { { {   -7,  34,  89,  18 },  {  -33,  74,  71,  19 },  {  -31,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 116: UPPER L, BODY UPPER L */
    { { {    1,  34,  88,  18 },  {  -30,  74,  71,  19 },  {  -32,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 117: UPPER L, BODY UPPER L */
    { { {    5,  34,  87,  18 },  {  -28,  74,  71,  19 },  {  -33,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 118: not used by a script */
    { { {    7,  34,  86,  18 },  {  -27,  74,  71,  19 },  {  -34,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 119: UPPER L, BODY UPPER L */
    { { {   -7,  34,  83,  18 },  {  -29,  74,  70,  19 },  {  -26,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 120: FACE S, FACE M, FACE L +5 */
    { { {    5,  34,  81,  18 },  {  -23,  74,  69,  19 },  {  -23,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 121: FACE M, FACE L, FOOK OKU L +3 */
    { { {   13,  34,  79,  18 },  {  -19,  74,  68,  19 },  {  -21,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 122: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {   17,  34,  77,  18 },  {  -17,  74,  67,  19 },  {  -20,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 123: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {  -27,  34,  82,  18 },  {  -35,  74,  69,  19 },  {  -28,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 124: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -31,  34,  79,  18 },  {  -33,  74,  67,  19 },  {  -26,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 125: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    { { {  -35,  34,  76,  18 },  {  -31,  74,  65,  19 },  {  -24,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 126: NOUTEN L, BODY BROW L */
    { { {  -39,  34,  73,  18 },  {  -29,  74,  63,  19 },  {  -22,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 127: NOUTEN L, BODY BROW L, TATAKI S +3 */
    { { {  -21,  44,  48,  20 },  {  -38,  72,  43,  20 },  {  -43,  86,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 128: TATAKI V. S, TATAKI V. M, TATAKI V. L +15 */
    { { {  -15,  44,  48,  20 },  {  -36,  72,  43,  20 },  {  -42,  86,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 129: KAGAMI M, KAGAMI L, KGM TATAKI S +7 */
    { { {   -9,  44,  48,  20 },  {  -34,  72,  43,  20 },  {  -41,  86,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 130: KAGAMI L */
    { { {   -3,  44,  48,  20 },  {  -32,  72,  43,  20 },  {  -40,  86,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 131: KAGAMI L */
    { { {  -28,  37, 109,  20 },  {  -38,  80,  92,  31 },  {  -36,  67,  62,  30 },  {  -39,  72,  42,  20 } } },  /* 132: V JUMP P M A */
    { { {  -32,  37, 109,  20 },  {  -41,  72,  90,  30 },  {  -42,  70,  62,  28 },  {  -43,  68,  42,  20 } } },  /* 133: V JUMP P M A */
    { { {  -43,  37, 108,  20 },  {  -45,  76,  89,  33 },  {  -37,  64,  62,  28 },  {  -36,  67,  42,  20 } } },  /* 134: V JUMP P M A */
    { { {   17,  37, 108,  20 },  {  -23,  74,  90,  31 },  {  -18,  71,  60,  30 },  {  -11,  65,  38,  22 } } },  /* 135: V JUMP K M A */
    { { {   12,  37, 108,  20 },  {  -26,  74,  90,  33 },  {  -23,  71,  60,  30 },  {   -1,  57,  40,  20 } } },  /* 136: V JUMP K M A */
    { { {   -4,  37, 115,  20 },  {  -13,  58,  94,  29 },  {  -30,  71,  64,  30 },  {    3,  52,  44,  20 } } },  /* 137: V JUMP K M A */
    { { {   -5,  37, 114,  20 },  {  -24,  65,  94,  28 },  {  -25,  68,  64,  30 },  {  -35,  82,  42,  37 } } },  /* 138: V JUMP K M A */
    { { {  -10,  37, 114,  20 },  {  -27,  68,  94,  28 },  {  -26,  70,  64,  30 },  {  -40,  72,  42,  29 } } },  /* 139: V JUMP K M A */
    { { {  -16,  37, 113,  20 },  {  -31,  69,  94,  27 },  {  -27,  68,  67,  27 },  {  -31,  62,  42,  25 } } },  /* 140: V JUMP K M A */
    { { {  -28,  34,  67,  18 },  {  -34,  74,  60,  20 },  {  -31,  67,  32,  28 },  {  -44,  88,   0,  34 } } },  /* 141: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    { { {  -43,  24,  91,  22 },  {  -59,  70,  75,  31 },  {  -34,  56,  57,  44 },  {  -39,  53,  41,  16 } } },  /* 142: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    { { {  -31,  24,  90,  22 },  {  -37,  56,  84,  30 },  {  -35,  65,  57,  37 },  {  -40,  73,  44,  13 } } },  /* 143: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    { { {  -21,  32,  81,  19 },  {  -36,  74,  70,  19 },  {  -30,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 144: KAMAE */
    { { {  -23,  32,  89,  19 },  {  -37,  74,  71,  21 },  {  -30,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 145: HURIMUKI */
    { { {  -31,  32,  88,  19 },  {  -40,  73,  76,  19 },  {  -34,  65,  38,  37 },  {  -44,  88,   0,  37 } } },  /* 146: FRONT WALK */
    { { {  -41,  32,  94,  19 },  {  -44,  67,  81,  21 },  {  -37,  66,  43,  37 },  {  -42,  88,   0,  42 } } },  /* 147: FRONT WALK */
    { { {  -39,  32,  97,  19 },  {  -41,  63,  83,  23 },  {  -31,  60,  43,  39 },  {  -31,  65,   0,  42 } } },  /* 148: FRONT WALK */
    { { {  -39,  32,  89,  19 },  {  -41,  65,  81,  21 },  {  -30,  61,  43,  38 },  {  -35,  81,   0,  42 } } },  /* 149: FRONT WALK */
    { { {  -39,  32,  90,  19 },  {  -41,  62,  81,  21 },  {  -34,  63,  43,  38 },  {  -45,  90,   0,  42 } } },  /* 150: FRONT WALK */
    { { {  -36,  32,  94,  19 },  {  -43,  67,  80,  21 },  {  -38,  66,  42,  38 },  {  -46,  85,   0,  42 } } },  /* 151: BACK WALK */
    { { {  -24,  32, 101,  19 },  {  -31,  63,  83,  23 },  {  -33,  66,  43,  39 },  {  -39,  74,   0,  42 } } },  /* 152: BACK WALK */
    { { {  -26,  32,  99,  19 },  {  -31,  63,  83,  23 },  {  -32,  63,  43,  39 },  {  -36,  70,   0,  42 } } },  /* 153: BACK WALK */
    { { {  -26,  32,  94,  19 },  {  -31,  63,  80,  23 },  {  -30,  60,  42,  37 },  {  -32,  72,   0,  42 } } },  /* 154: BACK WALK */
    { { {  -26,  32, 101,  19 },  {  -31,  63,  83,  23 },  {  -30,  60,  43,  39 },  {  -30,  63,   0,  42 } } },  /* 155: BACK WALK */
    { { {  -26,  32,  94,  19 },  {  -31,  63,  80,  23 },  {  -32,  63,  42,  37 },  {  -45,  89,   0,  42 } } },  /* 156: BACK WALK */
    { { {  -34,  32,  86,  19 },  {  -37,  62,  71,  21 },  {  -33,  65,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 157: DASH HUMIKOMI */
    { { {  -19,  32,  72,  19 },  {  -27,  70,  64,  23 },  {  -30,  77,  34,  30 },  {  -39,  92,   0,  34 } } },  /* 158: DASH HUMIKOMI */
    { { {  -26,  32,  63,  19 },  {  -33,  71,  56,  23 },  {  -35,  71,  32,  24 },  {  -45,  92,   0,  32 } } },  /* 159: DASH HUMIKOMI */
    { { {  -10,  32,  92,  19 },  {  -21,  64,  77,  23 },  {  -28,  66,  39,  38 },  {  -47,  86,   0,  39 } } },  /* 160: DASH TOBINOKI */
    { { {  -14,  32, 100,  19 },  {  -22,  60,  81,  25 },  {  -32,  61,  42,  39 },  {  -44,  72,   0,  42 } } },  /* 161: DASH TOBINOKI */
    { { {  -43,  32,  98,  19 },  {  -52,  63,  82,  25 },  {  -42,  61,  42,  40 },  {  -40,  68,   0,  42 } } },  /* 162: DASH TOBINOKI */
    { { {  -44,  32,  90,  19 },  {  -51,  62,  75,  23 },  {  -41,  65,  42,  33 },  {  -42,  74,   0,  42 } } },  /* 163: DASH TOBINOKI */
    { { {  -21,  32,  77,  19 },  {  -29,  63,  70,  19 },  {  -26,  66,  34,  36 },  {  -44,  88,   0,  34 } } },  /* 164: DASH TOBINOKI, L PUNCH B */
    { { {  -19,  44,  47,  19 },  {  -33,  72,  43,  19 },  {  -43,  87,  23,  19 },  {  -46,  91,   0,  22 } } },  /* 165: KAGAMI TURN */
    { { {  -31,  41,  69,  19 },  {  -37,  69,  62,  19 },  {  -38,  75,  31,  31 },  {  -44,  88,   0,  31 } } },  /* 166: STAND UP */
    { { {  -15,  26, 102,  19 },  {  -43,  70,  92,  25 },  {  -33,  55,  64,  28 },  {  -30,  55,  38,  26 } } },  /* 167: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    { { {  -37,  26,  98,  19 },  {  -45,  65,  83,  25 },  {  -33,  55,  64,  28 },  {  -30,  55,  38,  26 } } },  /* 168: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -45,  26,  88,  19 },  {  -48,  76,  81,  23 },  {  -42,  68,  64,  21 },  {  -51,  73,  49,  21 } } },  /* 169: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    { { {  -36,  26,  98,  19 },  {  -43,  63,  89,  25 },  {  -35,  58,  64,  25 },  {  -38,  57,  38,  26 } } },  /* 170: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    { { {  -30,  24,  88,  22 },  {  -41,  70,  74,  30 },  {  -32,  69,  57,  37 },  {  -38,  73,  42,  15 } } },  /* 171: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    { { {  -29,  24,  96,  22 },  {  -25,  56,  78,  33 },  {  -35,  60,  57,  21 },  {  -40,  66,  44,  16 } } },  /* 172: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
    { { {  -29,  24,  98,  22 },  {  -27,  61,  78,  35 },  {  -36,  58,  57,  21 },  {  -40,  64,  44,  16 } } },  /* 173: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    { { {  -37,  77,  86,  37 },  {  -66, 120,  50,  36 },  {  -53,  82,  34,  16 },  {    0,   0,   0,   0 } } },  /* 174: ATTACK 9 S: not started by a command */
    { { {   -9,  32,  81,  19 },  {  -17,  70,  66,  19 },  {  -13,  77,  51,  19 },  {  -36,  72,   0,  51 } } },  /* 175: L PUNCH B */
    { { {  -15,  32,  88,  19 },  {  -23,  54,  74,  23 },  {  -33,  70,  51,  32 },  {  -45,  61,   0,  56 } } },  /* 176: L PUNCH B */
    { { {  -24,  32, 105,  19 },  {  -43,  65,  76,  28 },  {  -42,  48,  51,  25 },  {  -38,  53,   0,  51 } } },  /* 177: L PUNCH B */
    { { {  -17,  32, 104,  19 },  {  -38,  65,  76,  28 },  {  -37,  47,  51,  25 },  {  -36,  51,   0,  51 } } },  /* 178: L PUNCH B */
    { { {  -11,  32, 104,  19 },  {  -35,  62,  76,  28 },  {  -37,  49,  51,  25 },  {  -39,  54,   0,  51 } } },  /* 179: L PUNCH B */
    { { {   -4,  32,  99,  19 },  {  -35,  57,  76,  38 },  {  -37,  68,  56,  23 },  {  -39,  56,   0,  56 } } },  /* 180: L PUNCH B */
    { { {   -7,  32,  83,  19 },  {  -32,  69,  76,  21 },  {  -35,  71,  56,  20 },  {  -36,  66,   0,  56 } } },  /* 181: L PUNCH B */
    { { {  -14,  32,  83,  19 },  {  -24,  62,  70,  27 },  {  -39,  73,  49,  30 },  {  -58,  61,  41,  21 } } },  /* 182: AIR NORMAL */
    { { {   -1,  32,  95,  19 },  {  -13,  51,  72,  36 },  {   -5,  53,  62,  33 },  {  -35,  55,  45,  28 } } },  /* 183: ASIBARAI SIRI */
    { { {    9,  32,  94,  19 },  {   -2,  49,  72,  36 },  {  -10,  55,  53,  26 },  {  -38,  39,  49,  32 } } },  /* 184: ASIBARAI SIRI */
    { { {   20,  32,  83,  19 },  {    4,  45,  73,  28 },  {   -8,  55,  50,  30 },  {  -38,  53,  45,  35 } } },  /* 185: ASIBARAI SIRI */
    { { {   40,  32,  50,  19 },  {   14,  45,  36,  37 },  {  -15,  29,  38,  27 },  {  -31,  31,  47,  38 } } },  /* 186: ASIBARAI SIRI */
    { { {   40,  32,  45,  19 },  {   17,  45,  23,  38 },  {    0,  29,  26,  27 },  {  -26,  36,  35,  39 } } },  /* 187: ASIBARAI SIRI */
    { { {   34,  32,  21,  19 },  {   10,  43,   7,  36 },  {   -8,  32,  12,  27 },  {  -22,  42,  34,  35 } } },  /* 188: ASIBARAI SIRI */
    { { {   32,  32,   0,  19 },  {    4,  47,   0,  32 },  {   -9,  38,   7,  27 },  {  -13,  45,  30,  32 } } },  /* 189: ASIBARAI SIRI */
    { { {  -13,  32,  95,  19 },  {  -28,  56,  70,  29 },  {  -24,  47,  43,  32 },  {  -16,  51,  27,  22 } } },  /* 190: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -57,  32,  35,  19 },  {  -49,  56,  44,  34 },  {   -2,  25,  36,  39 },  {   10,  29,  24,  43 } } },  /* 191: ASIB TUNNOMERI, HUMI ASIB */
    { { {   21,  32,  77,  19 },  {  -14,  45,  69,  35 },  {  -24,  65,  61,  19 },  {  -37,  52,  37,  32 } } },  /* 192: NOKEZORI, BODY UPPER SP */
    { { {   39,  32,  69,  19 },  {    9,  42,  52,  47 },  {  -17,  46,  44,  34 },  {  -42,  48,  36,  35 } } },  /* 193: NOKEZORI, UPPER, FACE +2 */
    { { {   43,  32,  64,  19 },  {   15,  40,  52,  46 },  {  -17,  46,  51,  36 },  {  -46,  47,  46,  35 } } },  /* 194: NOKEZORI, UPPER, BODY UPPER SP +1 */
    { { {   47,  32,  64,  19 },  {   18,  40,  52,  44 },  {  -17,  46,  55,  32 },  {  -46,  45,  50,  33 } } },  /* 195: NOKEZORI, UPPER, BODY UPPER SP +1 */
    { { {   49,  32,  59,  19 },  {   18,  41,  52,  38 },  {  -13,  44,  56,  31 },  {  -43,  43,  58,  28 } } },  /* 196: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {   47,  32,  55,  19 },  {   20,  38,  50,  36 },  {  -10,  44,  54,  32 },  {  -41,  43,  59,  28 } } },  /* 197: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {   41,  32,  40,  19 },  {   15,  39,  28,  40 },  {  -20,  44,  30,  24 },  {  -35,  36,  40,  33 } } },  /* 198: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {   40,  32,  37,  19 },  {   22,  40,  15,  39 },  {   -4,  36,  18,  27 },  {  -26,  38,  28,  39 } } },  /* 199: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {   34,  32,  19,  19 },  {   14,  40,   4,  41 },  {   -4,  36,   9,  29 },  {  -18,  38,  27,  38 } } },  /* 200: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {   32,  32,   0,  19 },  {    3,  51,   0,  31 },  {   -9,  37,   9,  28 },  {  -15,  48,  27,  35 } } },  /* 201: NOKEZORI, UPPER, KUNOJI NOKE +2 */
    { { {  -59,  32,  78,  20 },  {  -53,  55,  65,  30 },  {  -41,  52,  45,  41 },  {  -54,  55,  34,  20 } } },  /* 202: KUNOJI, KUNOJI NOKE */
    { { {  -68,  32,  72,  20 },  {  -53,  48,  69,  31 },  {  -48,  55,  54,  37 },  {  -60,  58,  41,  16 } } },  /* 203: KUNOJI, KUNOJI NOKE */
    { { {  -55,  32,  71,  20 },  {  -43,  48,  70,  34 },  {  -36,  52,  58,  38 },  {  -60,  61,  50,  20 } } },  /* 204: KUNOJI, KUNOJI NOKE */
    { { {  -55,  32,  75,  20 },  {  -36,  49,  71,  38 },  {  -52,  61,  50,  26 },  {  -66,  28,  57,  18 } } },  /* 205: KUNOJI, KUNOJI NOKE */
    { { {  -43,  32,  86,  20 },  {  -22,  48,  67,  39 },  {  -47,  60,  50,  24 },  {  -60,  38,  68,  21 } } },  /* 206: KUNOJI, KUNOJI NOKE */
    { { {   -3,  32,  89,  19 },  {   -7,  50,  65,  31 },  {  -22,  49,  43,  22 },  {  -34,  63,  32,  19 } } },  /* 207: KIRIMOMI */
    { { {    7,  32,  90,  19 },  {   -2,  50,  69,  26 },  {   -5,  36,  47,  22 },  {  -30,  57,  32,  23 } } },  /* 208: KIRIMOMI */
    { { {   11,  32,  90,  19 },  {   -8,  55,  71,  24 },  {  -16,  46,  49,  22 },  {  -34,  55,  37,  21 } } },  /* 209: KIRIMOMI */
    { { {   15,  32,  91,  19 },  {   -6,  56,  67,  32 },  {  -16,  40,  49,  22 },  {  -29,  34,  35,  21 } } },  /* 210: KIRIMOMI */
    { { {   19,  32,  88,  19 },  {   -1,  42,  63,  34 },  {  -15,  36,  49,  29 },  {  -30,  45,  34,  28 } } },  /* 211: KIRIMOMI */
    { { {   22,  32,  87,  19 },  {    0,  44,  63,  36 },  {  -12,  34,  44,  28 },  {  -17,  31,  25,  24 } } },  /* 212: KIRIMOMI */
    { { {   25,  32,  82,  19 },  {    2,  44,  55,  41 },  {  -19,  46,  45,  25 },  {  -25,  38,  28,  22 } } },  /* 213: KIRIMOMI */
    { { {   29,  32,  76,  19 },  {    4,  47,  56,  35 },  {  -13,  37,  44,  25 },  {  -31,  41,  31,  30 } } },  /* 214: KIRIMOMI */
    { { {   33,  32,  71,  19 },  {    5,  51,  51,  31 },  {  -16,  35,  42,  25 },  {  -34,  41,  33,  28 } } },  /* 215: KIRIMOMI */
    { { {   33,  32,  66,  19 },  {    8,  41,  47,  36 },  {   -8,  28,  37,  28 },  {  -32,  30,  27,  25 } } },  /* 216: KIRIMOMI */
    { { {   34,  32,  60,  19 },  {    6,  40,  40,  40 },  {  -15,  31,  30,  32 },  {  -34,  34,  21,  33 } } },  /* 217: KIRIMOMI */
    { { {   34,  32,  55,  19 },  {    6,  41,  36,  38 },  {  -15,  31,  27,  30 },  {  -32,  29,  14,  38 } } },  /* 218: KIRIMOMI */
    { { {   34,  32,  49,  19 },  {   10,  34,  34,  34 },  {  -10,  28,  21,  27 },  {  -25,  27,   6,  27 } } },  /* 219: KIRIMOMI */
    { { {   35,  32,  41,  19 },  {   11,  33,  23,  37 },  {  -10,  28,  16,  28 },  {  -30,  29,   6,  33 } } },  /* 220: KIRIMOMI */
    { { {   39,  32,  31,  19 },  {   11,  42,  17,  32 },  {  -12,  30,  14,  28 },  {  -31,  29,   9,  36 } } },  /* 221: KIRIMOMI */
    { { {  -28,  32,  84,  19 },  {  -25,  50,  72,  29 },  {  -15,  47,  49,  39 },  {  -34,  67,  34,  23 } } },  /* 222: UPPER, HARAYARARE, TATAKI AIR +2 */
    { { {  -29,  32,  92,  19 },  {  -25,  52,  87,  31 },  {  -19,  43,  57,  31 },  {  -30,  50,  41,  23 } } },  /* 223: UPPER, TATUMAKIZANKU */
    { { {    1,  32, 115,  19 },  {  -22,  51,  91,  31 },  {  -28,  40,  61,  38 },  {  -29,  44,  43,  18 } } },  /* 224: UPPER, TATUMAKIZANKU */
    { { {   10,  32, 100,  19 },  {  -17,  49,  78,  32 },  {  -27,  41,  53,  34 },  {  -39,  50,  42,  21 } } },  /* 225: UPPER, TATUMAKIZANKU */
    { { {  -36,  32,  79,  19 },  {  -27,  49,  65,  29 },  {  -14,  46,  44,  40 },  {  -31,  56,  32,  19 } } },  /* 226: BODY UPPER */
    { { {  -42,  32,  65,  19 },  {  -28,  50,  62,  30 },  {  -19,  53,  46,  35 },  {  -34,  57,  33,  18 } } },  /* 227: BODY UPPER */
    { { {  -41,  32,  55,  19 },  {  -35,  59,  59,  31 },  {  -23,  54,  47,  35 },  {  -36,  54,  33,  22 } } },  /* 228: BODY UPPER */
    { { {  -36,  32,  62,  19 },  {  -29,  54,  69,  28 },  {  -14,  46,  51,  41 },  {  -41,  52,  35,  27 } } },  /* 229: BODY UPPER */
    { { {   -1,  32,  81,  19 },  {   -5,  53,  69,  28 },  {    1,  51,  53,  39 },  {  -34,  54,  41,  28 } } },  /* 230: BODY UPPER, HARAYARARE, HANEKAERI HARA */
    { { {   51,  32,  54,  19 },  {   26,  34,  46,  41 },  {   -6,  42,  41,  38 },  {  -43,  53,  42,  33 } } },  /* 231: BODY UPPER, HARAYARARE, FACE */
    { { {   51,  32,  50,  19 },  {   25,  35,  42,  39 },  {   -6,  42,  44,  34 },  {  -41,  51,  47,  29 } } },  /* 232: BODY UPPER, HARAYARARE, FACE */
    { { {   49,  32,  43,  19 },  {   25,  35,  37,  38 },  {   -9,  42,  43,  31 },  {  -37,  35,  48,  28 } } },  /* 233: BODY UPPER, HARAYARARE, FACE */
    { { {   49,  32,  43,  19 },  {   23,  38,  32,  37 },  {  -10,  42,  34,  25 },  {  -27,  34,  47,  29 } } },  /* 234: BODY UPPER, HARAYARARE, FACE */
    { { {   47,  32,  45,  19 },  {   25,  42,  23,  37 },  {   -3,  36,  27,  26 },  {  -18,  35,  40,  33 } } },  /* 235: BODY UPPER */
    { { {   45,  32,  25,  19 },  {   21,  42,  11,  37 },  {    1,  30,  18,  33 },  {  -12,  45,  37,  39 } } },  /* 236: BODY UPPER, HARAYARARE, FACE */
    { { {   43,  32,   2,  19 },  {   11,  51,   0,  32 },  {    0,  39,  13,  33 },  {   -3,  50,  33,  34 } } },  /* 237: BODY UPPER, HARAYARARE, FACE */
    { { {   43,  32,   2,  19 },  {   11,  51,   0,  32 },  {    0,  39,  13,  33 },  {   -3,  50,  33,  34 } } },  /* 238: not used by a script */
    { { {  -11,  32,  76,  19 },  {   -8,  50,  59,  32 },  {  -26,  64,  42,  23 },  {  -53,  66,  34,  24 } } },  /* 239: TATAKI AIR */
    { { {    5,  32,  69,  19 },  {    1,  51,  38,  36 },  {  -18,  59,  29,  38 },  {  -32,  38,  37,  42 } } },  /* 240: TATAKI AIR */
    { { {   33,  32,  38,  19 },  {    7,  51,  14,  37 },  {  -13,  25,  20,  38 },  {  -33,  40,  32,  35 } } },  /* 241: TATAKI AIR */
    { { {   34,  32,  11,  19 },  {    0,  53,   0,  37 },  {  -11,  38,  14,  23 },  {  -22,  42,  27,  33 } } },  /* 242: TATAKI AIR */
    { { {  -26,  32,  84,  19 },  {  -31,  58,  62,  29 },  {  -13,  48,  43,  34 },  {  -24,  64,  35,  21 } } },  /* 243: TTKI V. AIR */
    { { {  -29,  32,  61,  19 },  {  -25,  59,  48,  29 },  {  -13,  55,  35,  34 },  {  -32,  78,  23,  25 } } },  /* 244: TTKI V. AIR */
    { { {  -42,  32,  36,  19 },  {  -20,  51,  29,  30 },  {  -21,  55,   9,  33 },  {  -46,  25,   9,  39 } } },  /* 245: TTKI V. AIR */
    { { {   -3,  32,  87,  19 },  {   -1,  48,  63,  34 },  {   -7,  50,  50,  32 },  {  -26,  66,  33,  21 } } },  /* 246: FACE, TOUKETSU A */
    { { {  -19,  32, 100,  19 },  {  -37,  57,  76,  26 },  {  -31,  47,  47,  29 },  {  -44,  70,  24,  33 } } },  /* 247: DENKI */
};

const HAND_BOX alex_hand_box[64] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -85,  47,  43,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -80,  41,  45,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {  -90,  66,  67,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B */
    { { {  -90,  66,  67,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -68,  25,  65,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A */
    { { {  -96,  62,  68,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A */
    { { {  -79,  50,  40,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH A */
    { { {  -51,  19,  68,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -62,  36,  66,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { {  -81,  47,  60,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH C */
    { { {  -85,  57,  29,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH C */
    { { {  -71,  42,  25,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH C */
    { { {  -94,  80,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: S KICK A */
    { { {  -94,  80,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: S KICK A */
    { { { -116,  64,  54,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: M KICK B */
    { { { -114,  56,  36,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI P A */
    { { { -110,  52,  39,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI P A */
    { { { -118,  88,   0,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI K A */
    { { { -126,  96,   0,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI K A */
    { { { -114,  84,   0,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI K A */
    { { {  -93,  51,  39,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP P S A */
    { { {  -85,  51,  39,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: ATTACK 6 S: SA III 23623+P (routine Att_SENPUUKYAKU2) */
    { { {  -64,  40,  78,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { {  -72,  50,  98,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: UP P GUARD P L */
    { { {  -99,  61,  66,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: L PUNCH C */
    { { {  -99,  61,  66,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: L PUNCH C */
    { { {  -86,  56,  38,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP P L A */
    { { {  -71,  44,  23,  62 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP P L A */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { { {  -99,  79,  48,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L KICK A */
    { { {  -84,  31,  44,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { { {  -82,  34,  33,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI P A */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { {  -87,  69,  79,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  71,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    { { { -102,  68,  68,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  66,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -86,  68,  71,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: F JUMP P L B, SP F JP L P B */
    { { { -118,  78,  44,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: F JUMP P L B, SP F JP L P B */
    { { {  -69,  39,  75,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 11 L: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    { { {  -77,  51,  99,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -69,  39,  44,  63 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    { { {  -85,  46,  81,  24 },  {  -67,  26, 102,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP P M A */
    { { {  -57,  20,  69,  20 },  {   31,  23, 107,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP P M A */
    { { {  -57,  20,  82,  27 },  {   31,  19, 100,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP P M A */
    { { {  -30,  42, 123,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP K M A */
    { { {  -97,  84,  59,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP K M A */
    { { {  -83,  70,  62,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: V JUMP K M A */
    { { {  -62,  27,  40,  31 },  {  -30,  27, 120,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: V JUMP K M A */
    { { {  -36,  26, 112,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: V JUMP K M A */
    { { {  -99,  50,  35,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: KAGAMI P A */
    { { {  -59,  32,  78,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT) */
    { { {  -40,  31,  78,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: L PUNCH B */
    { { {   11,  28,  79,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: L PUNCH B */
    { { {  -86,  62,  92,  28 },  {   18,  20,  65,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: L PUNCH B */
    { { {  -86,  69,  95,  28 },  {   18,  18,  65,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: L PUNCH B */
    { { {  -67,  32, 104,  23 },  {   12,  22,  62,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: L PUNCH B */
    { { {  -29,  42, 114,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: L PUNCH B */
    { { {  -20,  52,  97,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: L PUNCH B */
};

const HOSEI_BOX alex_hos_box[29] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -28,   56,    0,   86 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +103 */
    { {  -22,   61,    0,   86 } },  /* 2: L PUNCH A, S KICK A, M KICK A +1 */
    { {  -14,   61,    0,   86 } },  /* 3: M PUNCH C, S KICK A, L PUNCH C +1 */
    { {   -6,   61,    0,   86 } },  /* 4: L PUNCH A, M PUNCH C, M KICK A +1 */
    { {    2,   61,    0,   86 } },  /* 5: M PUNCH C */
    { {   10,   61,    0,   86 } },  /* 6: not used by a script */
    { {  -28,   56,    0,   59 } },  /* 7: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), KAGAMU, KAGAMI KAMAE +60 */
    { {  -28,   56,   52,   50 } },  /* 8: follow-up of AIR NORMAL, PARING AIR F, GUARD AIR +32 */
    { {  -46,   61,    0,   86 } },  /* 9: ATTACK 3 S: 6(123)4+P light (plain script), ATTACK 3 M: 6(123)4+P medium (plain script), ATTACK 3 L: 6(123)4+P heavy/EX (plain script) +2 */
    { {  -38,   73,    0,   83 } },  /* 10: not used by a script */
    { {  -12,   48,   60,   39 } },  /* 11: not used by a script */
    { {  -23,   47,   92,   50 } },  /* 12: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 13: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -25,   50,  115,   40 } },  /* 14: ATTACK 7 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 7 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 7 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -26,   42,   60,   58 } },  /* 15: not used by a script */
    { {  -36,   56,   63,   32 } },  /* 16: F JUMP P L B, SP F JP L P B, ATTACK 9 S: not started by a command */
    { {  -42,   62,   45,   58 } },  /* 17: not used by a script */
    { {  -21,   45,   45,   44 } },  /* 18: AIR NORMAL, BODY SLAM, IPPONZEOI +29 */
    { {  -48,   88,    0,   86 } },  /* 19: L KICK A */
    { {  -35,   70,    0,   66 } },  /* 20: PIYO */
    { {  -24,   55,   45,   40 } },  /* 21: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) +2 */
    { {  -28,   56,    0,   30 } },  /* 22: NEKOROBI S, no name */
    { {  -28,   56,    0,   56 } },  /* 23: SP F JP L P B */
    { {  -37,   95,    0,   74 } },  /* 24: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { {  -56,   98,    0,   74 } },  /* 25: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { {  -37,   95,    0,   74 } },  /* 26: ATTACK 10 SP: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 11 S: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 11 M: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { {  -28,   56,    0,   72 } },  /* 27: JUMP JUNBI, SP JUMP JUNBI, ATTACK 9 S: not started by a command +25 */
    { {  -28,   56,   56,   24 } },  /* 28: ATTACK 11 SP: 6(123)4+K light (routine Att_PL01_DDT), ATTACK 12 S: 6(123)4+K medium (routine Att_PL01_DDT), ATTACK 12 M: 6(123)4+K heavy/EX (routine Att_PL01_DDT) */
};
