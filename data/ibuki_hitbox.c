/*
 * IBUKI_HITBOX.C  Ibuki's hit boxes
 *
 * Each of Ibuki's animation frames names an entry of ibuki_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX ibuki_hit_ix_table[407] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +24 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +122 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +53 */
    {    3,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 3: S PUNCH A, ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) +1 */
    {    9,    0,    3, 0x0000,    0,    1,    1,    1 },  /* 4: no name, S PUNCH A */
    {    4,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 5: S PUNCH B */
    {    5,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 6: S PUNCH B */
    {    5,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 7: S PUNCH B */
    {    6,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: SP JUMP FRONT, GUARD AIR, TUKAMIHAZUSI +4 */
    {    7,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 9: JUMP FRONT, JUMP BACK, SP JUMP FRONT +21 */
    {    8,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 10: JUMP FRONT, TUKAMIHAZUSI, TUKAMIHAZUSARE +27 */
    {    9,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 11: S PUNCH A */
    {   10,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 12: GUARD HEAD, GUARD UP */
    {   11,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 13: GUARD DOWN */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 14: not used by a script */
    {   13,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 15: not used by a script */
    {   14,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 16: not used by a script */
    {   15,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 17: CATCH 5, CATCH 24 */
    {   16,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 18: DASH TOBINOKI, not started by a command */
    {   17,    0,    0, 0x0000,    0,    9,    0,   11 },  /* 19: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   18,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 20: M KICK C, follow-up of M KICK A */
    {   19,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 21: M KICK C, follow-up of M KICK A */
    {   20,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 22: M KICK C, follow-up of M KICK A */
    {   21,    0,    4, 0x0000,    0,    3,    3,    3 },  /* 23: M KICK C, follow-up of M KICK A */
    {   22,    0,    0, 0x0000,    0,    3,    4,    3 },  /* 24: M KICK C, follow-up of M KICK A */
    {   22,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 25: M KICK C, follow-up of M KICK A */
    {   23,    0,    5, 0x0000,    0,    2,    5,    2 },  /* 26: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A */
    {   24,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 27: V JUMP K L A, F JUMP K L A, not started by a command */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 28: V JUMP K L A, F JUMP K L A, not started by a command */
    {   70,    0,   25, 0x0000,    0,    3,    6,    3 },  /* 29: V JUMP K L A, F JUMP K L A */
    {   71,    0,   26, 0x0000,    0,    3,    7,    3 },  /* 30: V JUMP K L A, F JUMP K L A */
    {   72,    0,   27, 0x0000,    0,    3,    8,    3 },  /* 31: not used by a script */
    {   26,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 32: L KICK C */
    {   27,    0,    6, 0x0000,    0,    3,    0,    3 },  /* 33: L KICK C */
    {   28,    0,    7, 0x0000,    0,    3,    9,    3 },  /* 34: L KICK C */
    {  101,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 35: L KICK C */
    {   29,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 36: F JUMP K S A */
    {   73,    0,   28, 0x0000,    0,    3,   10,    3 },  /* 37: F JUMP K S A */
    {   73,    0,   28, 0x0000,    0,    3,   11,    3 },  /* 38: F JUMP K S A */
    {   30,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 39: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    {   31,    0,    8, 0x0000,    0,    3,   12,    3 },  /* 40: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    {   31,    0,    8, 0x0000,    0,    3,   13,    3 },  /* 41: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    {  111,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 42: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A, ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) +1 */
    {   32,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: M PUNCH C, follow-up of S PUNCH A */
    {   32,    0,    0, 0x0000,    0,    1,   14,    1 },  /* 44: M PUNCH C, follow-up of S PUNCH A */
    {  124,    0,   56, 0x0000,    0,    1,   15,    1 },  /* 45: M PUNCH C, follow-up of S PUNCH A */
    {   33,    0,    9, 0x0000,    0,    1,   16,    1 },  /* 46: M PUNCH C, follow-up of S PUNCH A */
    {   33,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 47: M PUNCH C, follow-up of S PUNCH A */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: M PUNCH A */
    {   35,    0,   10, 0x0000,    0,    1,   17,    1 },  /* 49: M PUNCH A */
    {  105,    0,   46, 0x0000,    0,    1,   18,    1 },  /* 50: M PUNCH A */
    {  105,    0,   46, 0x0000,    0,    1,    0,    1 },  /* 51: M PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,   19,    1 },  /* 52: L PUNCH A */
    {   36,    0,   11, 0x0000,    0,    1,   20,    1 },  /* 53: L PUNCH A */
    {   36,    0,   11, 0x0000,    0,    1,   21,    1 },  /* 54: L PUNCH A */
    {  106,    0,   47, 0x0000,    0,    1,    0,    1 },  /* 55: L PUNCH A */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 56: S KICK A */
    {   38,    0,   12, 0x0000,    0,    1,   22,    1 },  /* 57: not used by a script */
    {   38,    0,   12, 0x0000,    0,    1,   23,    1 },  /* 58: S KICK A */
    {   38,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 59: S KICK A */
    {   39,    0,   13, 0x0000,    0,    1,   24,    1 },  /* 60: S KICK B */
    {   39,    0,   13, 0x0000,    0,    1,   25,    1 },  /* 61: S KICK B */
    {  102,    0,   43, 0x0000,    0,    1,    0,    1 },  /* 62: S KICK B */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 63: M KICK B, follow-up of S KICK A */
    {   50,    0,    0, 0x0000,    0,    1,   26,    1 },  /* 64: M KICK B, follow-up of S KICK A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 65: M KICK A, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    {   42,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 66: M KICK A */
    {  100,    0,   41, 0x0000,    0,    1,   27,    1 },  /* 67: M KICK A */
    {   43,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 68: M KICK A, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +9 */
    {   45,    0,   15, 0x0000,    0,    1,   28,    1 },  /* 69: L KICK A */
    {   45,    0,   15, 0x0000,    0,    1,   29,    1 },  /* 70: L KICK A */
    {   45,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 71: L KICK A, ATTACK 6 S: not started by a command */
    {   44,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 72: L KICK A, ATTACK 6 S: not started by a command */
    {   47,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 73: L PUNCH B */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 74: L PUNCH B */
    {   49,    0,   16, 0x0000,    0,    1,   30,    1 },  /* 75: L PUNCH B */
    {   49,    0,   16, 0x0000,    0,    1,   31,    1 },  /* 76: L PUNCH B */
    {  107,    0,   48, 0x0000,    0,    1,    0,    1 },  /* 77: L PUNCH B */
    {   50,    0,    0, 0x0000,    0,    1,   32,    1 },  /* 78: M KICK B, follow-up of S KICK A */
    {  103,    0,   44, 0x0000,    0,    1,    0,    1 },  /* 79: M KICK B, follow-up of S KICK A */
    {   51,    0,   17, 0x0000,    0,   11,   33,    2 },  /* 80: KAGAMI P A */
    {   51,    0,   17, 0x0000,    0,    2,   34,    2 },  /* 81: no name */
    {   51,    0,   17, 0x0000,    0,    2,    0,    2 },  /* 82: no name */
    {   52,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 83: KAGAMI P A, no name */
    {   53,    0,   18, 0x0000,    0,    2,   35,    2 },  /* 84: KAGAMI P A, no name */
    {   53,    0,   18, 0x0000,    0,    2,   36,    2 },  /* 85: KAGAMI P A, no name */
    {  104,    0,   45, 0x0000,    0,    2,    0,    2 },  /* 86: KAGAMI P A, no name */
    {   54,    0,   19, 0x0000,    0,   11,   37,    2 },  /* 87: KAGAMI K A */
    {   54,    0,   19, 0x0000,    0,   11,   38,    2 },  /* 88: KAGAMI K A */
    {   54,    0,   19, 0x0000,    0,   11,    0,    2 },  /* 89: KAGAMI K A */
    {   55,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 90: V JUMP P S A, V JUMP P M A, TUKAMI AIR A */
    {  117,    0,   52, 0x0000,    0,    3,   39,    3 },  /* 91: V JUMP P S A */
    {  117,    0,   52, 0x0000,    0,    3,    0,    3 },  /* 92: V JUMP P S A, V JUMP P M A */
    {   56,    0,   20, 0x0000,    0,    3,   40,    3 },  /* 93: V JUMP P S A */
    {   57,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 94: V JUMP P L A */
    {   58,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 95: V JUMP P L A, follow-up of F JUMP P S A */
    {   59,    0,   21, 0x0000,    0,    3,   41,    3 },  /* 96: V JUMP P L A, follow-up of F JUMP P S A */
    {   59,    0,   21, 0x0000,    0,    3,   76,    3 },  /* 97: V JUMP P L A, follow-up of F JUMP P S A */
    {   60,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 98: V JUMP K S A, V JUMP K M A */
    {   61,    0,   22, 0x0000,    0,    3,   42,    3 },  /* 99: V JUMP K S A */
    {   61,    0,   22, 0x0000,    0,    3,   43,    3 },  /* 100: V JUMP K S A, V JUMP K M A */
    {   61,    0,   22, 0x0000,    0,    3,    0,    3 },  /* 101: V JUMP K M A */
    {   62,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: V JUMP K M A */
    {   63,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 103: F JUMP P S A, not started by a command */
    {   64,    0,   23, 0x0000,    0,    3,   44,    3 },  /* 104: F JUMP P S A */
    {   64,    0,   23, 0x0000,    0,    3,   45,    3 },  /* 105: F JUMP P S A */
    {   65,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 106: not used by a script */
    {   66,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 107: not used by a script */
    {   67,    0,   24, 0x0000,    0,    2,   46,    2 },  /* 108: not used by a script */
    {   67,    0,   24, 0x0000,    0,    2,    0,    2 },  /* 109: not used by a script */
    {  116,    0,    0, 0x0000,    0,    1,   47,    1 },  /* 110: follow-up of M PUNCH C */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 111: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {   68,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 112: not used by a script */
    {   69,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 113: L KICK A */
    {   69,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 114: L KICK A */
    {    1,    0,    0, 0x0000,    2,    1,   49,    1 },  /* 115: not used by a script */
    {   74,    0,    0, 0x0000,    0,    3,   50,    3 },  /* 116: not used by a script */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 117: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  134,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 118: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  134,    0,    0, 0x0000,    0,    3,   51,    1 },  /* 119: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  135,    0,   61, 0x0000,    0,    3,   52,    1 },  /* 120: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {  135,    0,   61, 0x0000,    0,    3,   53,    1 },  /* 121: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    {    1,    0,    0, 0x0000,    1,    1,   55,    1 },  /* 122: TUKAMIKAKARI A */
    {   76,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 123: not used by a script */
    {   77,    0,   30, 0x0000,    0,    2,    0,    2 },  /* 124: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    {   78,    0,   31, 0x0000,    0,    2,   56,    2 },  /* 125: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    {  122,    0,   55, 0x0000,    0,    2,   57,    2 },  /* 126: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    {   79,    0,    0, 0x0000,    3,    3,   58,    3 },  /* 127: not used by a script */
    {   80,    0,   32, 0x0000,    0,    1,    0,    5 },  /* 128: L PUNCH B */
    {   81,    0,   33, 0x0000,    0,    1,   59,    5 },  /* 129: L PUNCH B */
    {   82,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 130: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    {   82,    0,    0, 0x0000,    2,    5,   49,    6 },  /* 131: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI) */
    {   83,    0,   34, 0x0000,    0,    3,   60,    3 },  /* 132: not used by a script */
    {   84,    0,   35, 0x0000,    0,    3,   61,    3 },  /* 133: not used by a script */
    {   85,    0,   36, 0x0000,    0,    3,   62,    3 },  /* 134: not used by a script */
    {   86,    0,    0, 0x0000,    0,    1,   63,    1 },  /* 135: not used by a script */
    {   86,    0,    0, 0x0000,    0,    1,   64,    1 },  /* 136: not used by a script */
    {   87,    0,    0, 0x0000,    0,    6,    0,    7 },  /* 137: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    {   88,    0,    0, 0x0000,    0,    7,    0,    8 },  /* 138: not used by a script */
    {   93,    0,    0, 0x0000,    0,    3,    0,    9 },  /* 139: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   89,    0,    0, 0x0000,    0,    3,   65,    9 },  /* 140: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   90,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 141: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   90,    0,    0, 0x0000,    0,    3,   66,    3 },  /* 142: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    {   92,    0,   38, 0x0000,    0,    5,   67,    6 },  /* 143: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   91,    0,   37, 0x0000,    0,    5,    0,    6 },  /* 144: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,    0,   38, 0x0000,    0,    5,    0,    6 },  /* 145: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,    0,   38, 0x0000,    0,    5,   68,    6 },  /* 146: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,    0,   38, 0x0000,    0,    5,   69,    6 },  /* 147: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,    0,   38, 0x0000,    0,    5,   70,    6 },  /* 148: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   92,    0,   38, 0x0000,    0,    5,   71,    6 },  /* 149: not used by a script */
    {   92,    0,   38, 0x0000,    0,    5,   72,    6 },  /* 150: not used by a script */
    {   94,    0,   39, 0x0000,    0,    2,    0,    2 },  /* 151: KAGAMI K C, ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1) +2 */
    {   94,    0,   39, 0x0000,    0,    2,   73,    2 },  /* 152: not used by a script */
    {   95,    0,   40, 0x0000,    4,    2,   74,    2 },  /* 153: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 154: follow-up of AIR NORMAL */
    {  110,    0,   50, 0x0000,    0,    2,   75,    2 },  /* 155: KAGAMI K C */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 156: not used by a script */
    {   97,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 157: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    {   98,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 158: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    {   99,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 159: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  135,    0,   61, 0x0000,    0,    3,   54,    1 },  /* 160: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,    0,   61, 0x0000,    0,    3,   89,    1 },  /* 161: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    8 },  /* 162: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    6 },  /* 163: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {    0,    0,    0, 0x0000,    0,    0,    0,   10 },  /* 164: ATTACK 10 S: SA I air 23623+P light (routine Att_PL07_SA3), ATTACK 10 M: SA I air 23623+P medium (routine Att_PL07_SA3), ATTACK 10 L: SA I air 23623+P heavy/EX (routine Att_PL07_SA3) */
    {   57,    0,    0, 0x0000,    5,    3,   78,    3 },  /* 165: not used by a script */
    {  108,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 166: L KICK C */
    {  109,    0,   49, 0x0000,    0,    2,   79,    2 },  /* 167: no name */
    {  140,    0,   64, 0x0000,    0,    1,   80,    1 },  /* 168: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    {   23,    0,    5, 0x0000,    0,    2,   81,    2 },  /* 169: ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {  112,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 170: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  113,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 171: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    {  114,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 172: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +3 */
    {    0,    0,    0, 0x0000,   11,    0,   49,    6 },  /* 173: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {  115,    0,   51, 0x0000,    0,    3,   82,    3 },  /* 174: V JUMP K M A */
    {  118,    0,   53, 0x0000,    0,    3,   83,    3 },  /* 175: V JUMP P M A */
    {  119,    0,   54, 0x0000,    0,    3,   84,    3 },  /* 176: V JUMP P M A */
    {  120,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 177: not used by a script */
    {  121,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 178: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    {  123,    0,    0, 0x0000,    0,    3,    0,    9 },  /* 179: ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2), ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    {   38,    0,   12, 0x0000,    0,    1,   85,    1 },  /* 180: not used by a script */
    {  125,    0,   57, 0x0000,    0,    3,    0,    3 },  /* 181: M KICK C */
    {   23,    0,    5, 0x0000,    0,    2,    0,    2 },  /* 182: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A */
    {  126,    0,   58, 0x0000,    0,    3,   86,    3 },  /* 183: not used by a script */
    {   38,    0,   12, 0x0000,    0,    1,   87,    1 },  /* 184: S KICK A */
    {    1,    0,    0, 0x0000,    0,    1,   88,    1 },  /* 185: not used by a script */
    {  135,    0,   61, 0x0000,    0,    3,   90,    1 },  /* 186: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,    0,   61, 0x0000,    0,    3,   91,    1 },  /* 187: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,    0,   61, 0x0000,    0,    3,   92,    1 },  /* 188: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,    0,   61, 0x0000,    0,    3,   93,    1 },  /* 189: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  135,    0,   61, 0x0000,    0,    3,    0,    1 },  /* 190: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {   44,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 191: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  132,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 192: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  132,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 193: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  132,    0,    0, 0x0000,    0,    1,   51,    1 },  /* 194: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,   52,    1 },  /* 195: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,   53,    1 },  /* 196: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,   54,    1 },  /* 197: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,   94,    1 },  /* 198: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   55,    0,    0, 0x0000,    5,    3,   78,    3 },  /* 199: TUKAMI AIR A */
    {   63,    0,    0, 0x0000,    6,    3,   99,    3 },  /* 200: not used by a script */
    {  127,    0,    0, 0x0000,    0,   10,    0,   12 },  /* 201: PIYO */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 202: CATCH 5, CATCH 22, CATCH 23 +2 */
    {  126,    0,   87, 0x0000,    0,    3,  100,    3 },  /* 203: not started by a command */
    {   64,    0,   87, 0x0000,    0,    3,  101,    3 },  /* 204: not started by a command */
    {   70,    0,   25, 0x0000,    0,    3,  102,    3 },  /* 205: not started by a command */
    {   71,    0,   26, 0x0000,    0,    3,  103,    3 },  /* 206: not started by a command */
    {   72,    0,   27, 0x0000,    0,    3,  104,    3 },  /* 207: not started by a command */
    {  128,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 208: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) */
    {  129,    0,    0, 0x0000,    0,   10,    0,   12 },  /* 209: PIYO */
    {    0,    0,    0, 0x0000,    0,    0,    0,   13 },  /* 210: NEKOROBI S, no name */
    {  130,    0,   59, 0x0000,    0,    1,  105,    1 },  /* 211: not used by a script */
    {  131,    0,   60, 0x0000,    0,    1,  106,    1 },  /* 212: not used by a script */
    {   45,    0,   15, 0x0000,    0,    3,   95,    1 },  /* 213: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   45,    0,   15, 0x0000,    0,    3,   96,    1 },  /* 214: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   78,    0,   31, 0x0000,    0,    2,  107,    2 },  /* 215: not used by a script */
    {  122,    0,   55, 0x0000,    0,    2,  108,    2 },  /* 216: not used by a script */
    {   50,    0,    0, 0x0000,    0,    1,  109,    1 },  /* 217: not used by a script */
    {   45,    0,   15, 0x0000,    0,    1,  110,    1 },  /* 218: not used by a script */
    {   45,    0,   15, 0x0000,    0,   12,  111,    1 },  /* 219: not used by a script */
    {  137,    0,   62, 0x0000,    0,    3,   97,    1 },  /* 220: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,   98,    1 },  /* 221: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  137,    0,   62, 0x0000,    0,    3,    0,    1 },  /* 222: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   44,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 223: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {  133,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 224: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  133,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 225: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN) */
    {  133,    0,    0, 0x0000,    0,    1,   51,    1 },  /* 226: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  112,    1 },  /* 227: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  113,    1 },  /* 228: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,   54,    1 },  /* 229: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  117,    1 },  /* 230: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  118,    1 },  /* 231: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  119,    1 },  /* 232: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  120,    1 },  /* 233: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,  121,    1 },  /* 234: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  138,    0,   63, 0x0000,    0,    3,    0,    1 },  /* 235: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {   44,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 236: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 237: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN), ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP) +1 */
    {  139,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 238: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    {   51,    0,   17, 0x0000,    0,   11,   34,    2 },  /* 239: KAGAMI P A */
    {   51,    0,   17, 0x0000,    0,   11,    0,    2 },  /* 240: KAGAMI P A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 241: follow-up of SP WIN 2 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 242: follow-up of SP WIN 2 */
    {   82,    0,    0, 0x0000,    7,    5,  114,    6 },  /* 243: ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) */
    {   82,    0,    0, 0x0000,    8,    5,  115,    6 },  /* 244: ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 245: LOSE SONABA, SHIMEOTASARE */
    {   45,    0,   15, 0x0000,    0,   12,    0,    1 },  /* 246: not used by a script */
    {   44,    0,    0, 0x0000,    0,   12,    0,    1 },  /* 247: not used by a script */
    {  141,    0,    0, 0x0000,    9,    3,    0,    3 },  /* 248: not started by a command */
    {    6,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 249: CATCH 20, CATCH 21 */
    {   12,    0,    0, 0x0000,    0,    0,    0,   13 },  /* 250: no name */
    {    0,    0,    0, 0x0000,    0,    0,   48,    1 },  /* 251: ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    {  142,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 252: not started by a command */
    {   14,    0,    0, 0x0000,    0,    4,    0,    0 },  /* 253: not used by a script */
    {  140,    0,   68, 0x0000,    0,    1,  116,    1 },  /* 254: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,   10,    0,    0,    0 },  /* 255: CATCH 22, CATCH 23 */
    {  143,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 256: ATTACK 4 SP: EX 236+PP (routine Att_PL07_AT1) */
    {   42,    0,   65, 0x0000,    0,    1,    0,    1 },  /* 257: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    {   42,    0,   66, 0x0000,    0,    1,    0,    1 },  /* 258: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    {   42,    0,   67, 0x0000,    0,    1,    0,    1 },  /* 259: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    {   42,    0,   68, 0x0000,    0,    1,    0,    1 },  /* 260: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    {  140,    0,   69, 0x0000,    0,    1,   80,    1 },  /* 261: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    {  140,    0,   70, 0x0000,    0,    1,   80,    1 },  /* 262: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    {  144,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 263: KAGAMI P A */
    {  145,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 264: KAGAMI P A */
    {  146,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 265: KAGAMI P A */
    {  147,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 266: KAGAMI P A */
    {  148,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 267: KAGAMI P A */
    {  149,    0,   71, 0x0000,    0,    2,  122,    2 },  /* 268: KAGAMI P A */
    {  150,    0,   72, 0x0000,    0,    2,  123,    2 },  /* 269: KAGAMI P A */
    {  150,    0,   73, 0x0000,    0,    2,    0,    2 },  /* 270: KAGAMI P A */
    {  151,    0,   74, 0x0000,    0,    2,    0,    2 },  /* 271: KAGAMI P A */
    {  152,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 272: KAGAMI P A */
    {  153,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 273: KAGAMI K A */
    {  154,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 274: KAGAMI K A */
    {  155,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 275: KAGAMI K A */
    {  156,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 276: KAGAMI K A */
    {  157,    0,   77, 0x0000,    0,    2,  124,    2 },  /* 277: KAGAMI K A */
    {  158,    0,   78, 0x0000,    0,    2,  125,    2 },  /* 278: KAGAMI K A */
    {  159,    0,   79, 0x0000,    0,    2,    0,    2 },  /* 279: KAGAMI K A */
    {  160,    0,   80, 0x0000,    0,    2,    0,    2 },  /* 280: KAGAMI K A */
    {  161,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 281: KAGAMI K A */
    {  162,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 282: KAGAMI K A */
    {  163,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 283: UPPER L */
    {  164,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 284: UPPER L */
    {  165,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 285: UPPER L */
    {  166,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 286: not used by a script */
    {  167,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 287: FACE S, FACE M, FACE L +7 */
    {  168,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 288: FACE M, FACE L, FOOK TEMAE L +5 */
    {  169,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 289: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    {  170,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 290: FACE L, FOOK TEMAE SP, FOOK OKU SP */
    {  171,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 291: NOUTEN L, BODY UPPER L, NOUTEN S +2 */
    {  172,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 292: NOUTEN L, BODY UPPER L, NOUTEN M +1 */
    {  173,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 293: NOUTEN L, BODY UPPER L, BODY BROW L */
    {  174,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 294: BODY UPPER L, TATAKI S, BODY BROW L */
    {  175,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 295: KAGAMI S, KAGAMI M, KAGAMI L +3 */
    {  176,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 296: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    {  177,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 297: KAGAMI L */
    {  178,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 298: not used by a script */
    {    2,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 299: JUMP JUNBI, SP JUMP JUNBI */
    {  179,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 300: F JUMP P M A */
    {  180,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 301: F JUMP P M A */
    {  181,    0,   75, 0x0000,    0,    3,  126,    3 },  /* 302: F JUMP P M A */
    {  181,    0,   76, 0x0000,    0,    3,  127,    3 },  /* 303: F JUMP P M A */
    {  181,    0,   75, 0x0000,    0,    3,    0,    3 },  /* 304: F JUMP P M A */
    {  181,    0,   76, 0x0000,    0,    3,    0,    3 },  /* 305: F JUMP P M A */
    {  182,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 306: F JUMP P M A */
    {  183,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 307: F JUMP P M A */
    {  184,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 308: F JUMP P M A */
    {  185,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 309: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  186,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 310: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  187,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 311: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  188,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 312: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  189,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 313: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  190,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 314: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  191,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 315: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  192,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 316: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  193,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 317: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  194,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 318: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  195,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 319: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  196,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 320: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  197,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 321: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  198,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 322: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  199,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 323: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  200,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 324: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  201,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 325: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  202,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 326: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  203,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 327: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  204,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 328: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  205,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 329: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  206,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 330: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  207,    0,    0, 0x0000,    0,    1,    0,   16 },  /* 331: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  208,    0,   81, 0x0000,    0,    1,    0,    1 },  /* 332: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  209,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 333: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  210,    0,   82, 0x0000,    0,    1,    0,    1 },  /* 334: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  211,    0,   83, 0x0000,    0,    1,    0,    1 },  /* 335: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  212,    0,   84, 0x0000,    0,    1,    0,    1 },  /* 336: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  213,    0,   85, 0x0000,    0,    1,    0,    1 },  /* 337: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  214,    0,   86, 0x0000,    0,    1,    0,    1 },  /* 338: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  215,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 339: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  216,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 340: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  217,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 341: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    {  218,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 342: ATTACK 8 SP: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,  128,    0 },  /* 343: ATTACK 8 SP: not started by a command */
    {  219,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 344: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    {  220,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 345: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    {  221,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 346: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    {  222,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 347: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    {  223,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 348: NOKEZORI, UPPER, BODY UPPER +4 */
    {  224,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 349: NOKEZORI, UPPER, BODY UPPER +5 */
    {  225,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 350: NOKEZORI, UPPER, BODY UPPER +4 */
    {  226,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 351: NOKEZORI, UPPER, BODY UPPER +4 */
    {  227,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 352: NOKEZORI, UPPER, BODY UPPER +4 */
    {  228,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 353: NOKEZORI, UPPER, BODY UPPER +5 */
    {  229,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 354: NOKEZORI, UPPER, BODY UPPER +5 */
    {  230,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 355: NOKEZORI, UPPER, BODY UPPER +5 */
    {  231,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 356: NOKEZORI, UPPER, BODY UPPER +5 */
    {  232,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 357: NOKEZORI, UPPER, BODY UPPER +5 */
    {  233,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 358: NOKEZORI, UPPER, BODY UPPER +4 */
    {  234,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 359: KUNOJI, KUNOJI NOKE */
    {  235,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 360: KUNOJI, KUNOJI NOKE */
    {  236,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 361: KIRIMOMI */
    {  237,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 362: KIRIMOMI */
    {  238,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 363: KIRIMOMI */
    {  239,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 364: KIRIMOMI */
    {  240,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 365: KIRIMOMI */
    {  241,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 366: KIRIMOMI */
    {  242,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 367: KIRIMOMI */
    {  243,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 368: KIRIMOMI */
    {  244,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 369: KIRIMOMI */
    {  245,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 370: KIRIMOMI */
    {  246,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 371: KIRIMOMI */
    {  247,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 372: KIRIMOMI */
    {  248,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 373: KIRIMOMI */
    {  249,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 374: KIRIMOMI */
    {  250,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 375: KIRIMOMI */
    {  251,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 376: KIRIMOMI */
    {  252,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 377: TATAKI AIR, TTKI V. AIR */
    {  253,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 378: TATAKI AIR, TTKI V. AIR */
    {  254,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 379: TATAKI AIR, TTKI V. AIR */
    {  255,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 380: HUMI ASIB */
    {  256,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 381: HUMI ASIB */
    {  257,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 382: HUMI ASIB */
    {  258,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 383: DENKI */
    {  259,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 384: TOUKETSU A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 385: not started by a command */
    {  260,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 386: FRONT WALK, BACK WALK */
    {  261,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 387: FRONT WALK, BACK WALK */
    {  262,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 388: HURIMUKI */
    {  263,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 389: KAGAMI TURN */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 390: KAGAMU */
    {    2,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 391: DASH TOBINOKI, STAND UP, follow-up of JUDGMENT LOSE */
    {  127,    0,    0, 0x1010,    0,   10,    0,   12 },  /* 392: PIYO */
    {  129,    0,    0, 0x1010,    0,   10,    0,   12 },  /* 393: PIYO */
    {   13,    0,    0, 0x1010,    0,    4,    0,    4 },  /* 394: DASH HUMIKOMI */
    {  264,    0,    0, 0x1010,    0,    4,    0,    0 },  /* 395: DASH HUMIKOMI */
    {  265,    0,    0, 0x1010,    0,    4,    0,    4 },  /* 396: DASH HUMIKOMI */
    {  266,    0,    0, 0x1010,    0,    4,    0,    4 },  /* 397: DASH HUMIKOMI */
    {  267,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 398: DASH HUMIKOMI */
    {  268,    0,    0, 0x1010,    0,    9,    0,   11 },  /* 399: DASH TOBINOKI */
    {  269,    0,    0, 0x1010,    0,    9,    0,   11 },  /* 400: DASH TOBINOKI */
    {  270,    0,    0, 0x1010,    0,    4,    0,    4 },  /* 401: DASH TOBINOKI, follow-up of JUDGMENT LOSE */
    {    8,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 402: JUMP VERTICAL, JUMP BACK, SP JUMP V +1 */
    {  271,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 403: JUMP VERTICAL, JUMP BACK, SP JUMP V +1 */
    {  271,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 404: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  272,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 405: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {    6,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 406: JUMP FRONT, SP JUMP FRONT */
};

const BODY_BOX ibuki_body_box[273] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -15,  20,  75,  16 },  {  -28,  48,  66,  14 },  {  -26,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +125 */
    { { {  -19,  20,  42,  18 },  {  -29,  50,  37,  17 },  {  -32,  55,  27,  14 },  {  -42,  78,   0,  27 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +57 */
    { { {  -28,  20,  74,  18 },  {  -44,  56,  66,  15 },  {  -30,  36,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 3: S PUNCH A, ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -28,  20,  74,  18 },  {  -36,  48,  66,  15 },  {  -24,  34,  37,  29 },  {  -36,  68,   0,  37 } } },  /* 4: S PUNCH B */
    { { {  -28,  20,  74,  18 },  {  -36,  48,  66,  15 },  {  -24,  34,  37,  29 },  {  -36,  68,   0,  37 } } },  /* 5: S PUNCH B */
    { { {  -14,  20,  92,  18 },  {  -28,  46,  86,  12 },  {  -19,  38,  70,  19 },  {  -38,  60,  45,  25 } } },  /* 6: SP JUMP FRONT, GUARD AIR, TUKAMIHAZUSI +6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  64,  44,  50 },  {    0,   0,   0,   0 } } },  /* 7: JUMP FRONT, JUMP BACK, SP JUMP FRONT +21 */
    { { {  -13,  20,  91,  18 },  {  -27,  47,  86,  12 },  {  -21,  41,  67,  19 },  {  -25,  50,  38,  29 } } },  /* 8: JUMP FRONT, TUKAMIHAZUSI, TUKAMIHAZUSARE +31 */
    { { {  -28,  20,  74,  18 },  {  -35,  44,  62,  16 },  {  -30,  36,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 9: no name, S PUNCH A */
    { { {   -3,  20,  72,  18 },  {  -22,  54,  66,  15 },  {  -11,  39,  34,  32 },  {  -30,  68,   0,  37 } } },  /* 10: GUARD HEAD, GUARD UP */
    { { {  -15,  20,  45,  18 },  {    0,   0,   0,   0 },  {  -34,  58,   0,  56 },  {  -44,  78,   0,  27 } } },  /* 11: GUARD DOWN */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 12: no name */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 13: DASH HUMIKOMI */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 14: not used by a script */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -40,  72,   0,  37 } } },  /* 15: CATCH 5, CATCH 24 */
    { { {  -22,  20,  63,  18 },  {    0,   0,   0,   0 },  {  -30,  48,  27,  44 },  {  -40,  72,   0,  37 } } },  /* 16: DASH TOBINOKI, not started by a command */
    { { {  -22,  20,  88,  18 },  {  -45,  59,  80,  14 },  {  -39,  48,  17,  63 },  {  -34,  44,  34,  20 } } },  /* 17: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {  -20,  20,  62,  18 },  {  -29,  48,  54,  15 },  {  -43,  70,  38,  20 },  {  -36,  68,   0,  37 } } },  /* 18: M KICK C, follow-up of M KICK A */
    { { {  -16,  20,  82,  18 },  {  -23,  52,  76,  15 },  {  -16,  43,  36,  40 },  {    0,   0,   0,   0 } } },  /* 19: M KICK C, follow-up of M KICK A */
    { { {  -16,  20,  92,  18 },  {  -43,  61,  81,  15 },  {  -28,  51,  59,  22 },  {  -11,  34,  44,  16 } } },  /* 20: M KICK C, follow-up of M KICK A */
    { { {   -8,  20,  88,  18 },  {  -30,  48,  78,  15 },  {  -45,  62,  54,  25 },  {  -27,  44,  36,  19 } } },  /* 21: M KICK C, follow-up of M KICK A */
    { { {    2,  20,  84,  18 },  {  -26,  48,  69,  15 },  {  -38,  48,  18,  51 },  {  -64,  46,  29,  31 } } },  /* 22: M KICK C, follow-up of M KICK A */
    { { {  -18,  20,  48,  18 },  {  -36,  54,  40,  19 },  {    0,   0,   0,   0 },  {  -48,  75,   0,  40 } } },  /* 23: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A, ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -14,  20,  84,  18 },  {  -28,  46,  75,  15 },  {  -30,  52,  53,  22 },  {  -27,  45,  21,  32 } } },  /* 24: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -28,  46,  75,  15 },  {  -34,  64,  56,  19 },  {  -18,  45,  21,  36 } } },  /* 25: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -16,  20,  86,  18 },  {  -24,  54,  78,  15 },  {  -26,  55,  34,  44 },  {    0,   0,   0,   0 } } },  /* 26: L KICK C */
    { { {  -16,  20,  90,  18 },  {  -30,  48,  83,  15 },  {  -18,  40,  62,  26 },  {  -10,  39,  27,  44 } } },  /* 27: L KICK C */
    { { {  -16,  20,  98,  18 },  {  -27,  48,  88,  15 },  {  -39,  74,  63,  26 },  {    0,   0,   0,   0 } } },  /* 28: L KICK C */
    { { {  -20,  20,  84,  18 },  {  -25,  48,  73,  15 },  {  -32,  43,  64,   9 },  {  -19,  44,  33,  15 } } },  /* 29: F JUMP K S A */
    { { {   -8,  20,  87,  18 },  {  -16,  49,  82,  15 },  {  -39,  65,  58,  24 },  {  -44,  70,  38,  26 } } },  /* 30: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    { { {   -8,  20,  87,  18 },  {  -16,  49,  82,  15 },  {  -39,  65,  58,  24 },  {  -41,  80,  41,  18 } } },  /* 31: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 32: M PUNCH C, follow-up of S PUNCH A */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 33: M PUNCH C, follow-up of S PUNCH A */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 34: M PUNCH A */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 35: M PUNCH A */
    { { {  -20,  20,  72,  18 },  {  -36,  56,  63,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 36: L PUNCH A */
    { { {   -2,  20,  74,  18 },  {  -28,  56,  66,  15 },  {  -26,  42,  34,  32 },  {   -7,  40,   0,  44 } } },  /* 37: S KICK A */
    { { {   -2,  20,  74,  18 },  {  -28,  56,  66,  15 },  {  -26,  42,  34,  32 },  {   -7,  40,   0,  44 } } },  /* 38: S KICK A */
    { { {  -16,  20,  70,  18 },  {  -36,  56,  62,  15 },  {  -26,  42,  34,  32 },  {  -38,  46,   0,  38 } } },  /* 39: S KICK B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 40: M KICK B, follow-up of S KICK A */
    { { {    4,  20,  76,  18 },  {  -28,  54,  67,  15 },  {  -20,  40,  39,  28 },  {  -20,  51,   0,  39 } } },  /* 41: M KICK A, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 42: M KICK A, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +3 */
    { { {    4,  20,  72,  18 },  {  -13,  40,  62,  20 },  {  -36,  47,  39,  23 },  {  -20,  51,   0,  39 } } },  /* 43: M KICK A, ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) +9 */
    { { {  -16,  20,  78,  18 },  {  -43,  50,  72,  15 },  {  -39,  51,  46,  24 },  {  -34,  47,   0,  34 } } },  /* 44: L KICK A, ATTACK 6 S: not started by a command, ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN) +3 */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,   0,  34 } } },  /* 45: L KICK A, ATTACK 6 S: not started by a command, ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: no box */
    { { {  -16,  20,  74,  18 },  {  -30,  46,  65,  15 },  {  -27,  40,  36,  29 },  {  -24,  55,   0,  37 } } },  /* 47: L PUNCH B */
    { { {  -16,  20,  74,  18 },  {  -30,  46,  65,  15 },  {  -27,  40,  36,  29 },  {  -48,  76,   0,  34 } } },  /* 48: L PUNCH B */
    { { {  -21,  20,  66,  18 },  {  -27,  46,  54,  15 },  {  -26,  40,  29,  29 },  {  -40,  76,   0,  34 } } },  /* 49: L PUNCH B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 50: M KICK B, follow-up of S KICK A */
    { { {  -19,  20,  44,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  80,   0,  38 } } },  /* 51: KAGAMI P A, no name */
    { { {  -25,  20,  62,  18 },  {  -39,  46,  53,  15 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  33 } } },  /* 52: KAGAMI P A, no name */
    { { {  -19,  20,  66,  18 },  {  -39,  56,  53,  23 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  34 } } },  /* 53: KAGAMI P A, no name */
    { { {   -2,  20,  41,  18 },  {  -18,  50,  32,  19 },  {  -26,  63,   0,  38 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K A */
    { { {  -10,  20,  86,  18 },  {  -26,  56,  78,  15 },  {  -19,  46,  60,  18 },  {  -36,  69,  41,  19 } } },  /* 55: V JUMP P S A, V JUMP P M A, TUKAMI AIR A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 56: V JUMP P S A */
    { { {  -16,  20,  87,  18 },  {  -34,  44,  76,  15 },  {  -24,  30,  62,  14 },  {  -36,  52,  29,  33 } } },  /* 57: V JUMP P L A */
    { { {  -10,  20,  87,  18 },  {  -22,  44,  77,  15 },  {  -18,  31,  63,  14 },  {  -16,  50,  31,  32 } } },  /* 58: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -20,  20,  82,  18 },  {  -30,  42,  72,  15 },  {    0,   0,   0,   0 },  {  -18,  48,  33,  39 } } },  /* 59: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -18,  20,  87,  18 },  {  -26,  42,  77,  15 },  {    0,   0,   0,   0 },  {  -33,  56,  33,  44 } } },  /* 60: V JUMP K S A, V JUMP K M A */
    { { {  -18,  20,  87,  18 },  {  -32,  47,  74,  19 },  {  -23,  42,  52,  22 },  {  -16,  33,  16,  36 } } },  /* 61: V JUMP K S A, V JUMP K M A */
    { { {  -18,  20,  87,  18 },  {  -26,  44,  78,  15 },  {  -21,  43,  18,  60 },  {  -63,  43,  43,  22 } } },  /* 62: V JUMP K M A */
    { { {  -43,  20,  76,  18 },  {  -46,  50,  70,  15 },  {  -43,  51,  50,  20 },  {  -35,  67,  29,  21 } } },  /* 63: F JUMP P S A, not started by a command */
    { { {  -43,  20,  76,  18 },  {  -47,  58,  73,  15 },  {  -42,  51,  53,  20 },  {  -23,  51,  28,  25 } } },  /* 64: F JUMP P S A, not started by a command */
    { { {   -8,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 65: not used by a script */
    { { {  -25,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 66: not used by a script */
    { { {  -25,  16,  51,  14 },  {  -19,  40,  42,  12 },  {  -16,  32,  26,  12 },  {  -32,  62,   0,  26 } } },  /* 67: not used by a script */
    { { {    0,   0,   0,   0 },  {  -22,  38,  66,  12 },  {  -16,  28,  40,  24 },  {  -30,  54,   0,  38 } } },  /* 68: not used by a script */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,   0,  34 } } },  /* 69: L KICK A */
    { { {  -14,  20,  84,  18 },  {  -26,  48,  66,  24 },  {  -38,  58,  48,  28 },  {  -10,  37,  17,  43 } } },  /* 70: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -25,  43,  66,  27 },  {  -42,  62,  45,  21 },  {  -10,  40,  14,  43 } } },  /* 71: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -14,  20,  84,  18 },  {  -25,  43,  66,  24 },  {  -37,  56,  43,  23 },  {  -10,  40,  14,  43 } } },  /* 72: not started by a command */
    { { {  -18,  20,  84,  18 },  {  -23,  48,  76,  15 },  {  -28,  54,  45,  31 },  {    0,   0,   0,   0 } } },  /* 73: F JUMP K S A */
    { { {   -7,  20,  86,  18 },  {  -19,  44,  80,  15 },  {  -19,  42,  46,  32 },  {    0,   0,   0,   0 } } },  /* 74: not used by a script */
    { { {  -27,  16,  73,  14 },  {  -32,  38,  64,  13 },  {  -27,  32,  42,  20 },  {  -32,  54,   0,  40 } } },  /* 75: not used by a script */
    { { {    0,   0,   0,   0 },  {  -22,  44,  33,  18 },  {  -26,  48,  15,  22 },  {    0,   0,   0,   0 } } },  /* 76: not used by a script */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -24,  50,   0,  84 },  {    0,   0,   0,   0 } } },  /* 77: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -28,  56,   0,  68 },  {  -73,  63,  80,  22 } } },  /* 78: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {  -19,  16,  85,  14 },  {  -37,  48,  71,  13 },  {  -23,  30,  51,  22 },  {   -2,  47,   0,  48 } } },  /* 79: not used by a script */
    { { {  -39,  20,  63,  18 },  {  -58,  46,  55,  15 },  {  -45,  28,  34,  21 },  {  -51,  71,   0,  34 } } },  /* 80: L PUNCH B */
    { { {  -41,  20,  63,  18 },  {  -51,  46,  55,  15 },  {  -42,  42,  34,  21 },  {  -51,  71,   0,  34 } } },  /* 81: L PUNCH B */
    { { {  -47,  41,  70,  18 },  {  -69,  81,  59,  17 },  {  -54,  68,  36,  24 },  {  -62,  86,   0,  37 } } },  /* 82: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -11,  20,  90,  18 },  {  -22,  43,  83,  15 },  {  -27,  42,  64,  24 },  {  -18,  30,  21,  47 } } },  /* 83: not used by a script */
    { { {   -6,  20,  87,  18 },  {  -23,  46,  80,  15 },  {  -37,  55,  54,  26 },  {  -21,  33,  16,  38 } } },  /* 84: not used by a script */
    { { {   -3,  20,  84,  18 },  {  -23,  48,  75,  15 },  {  -18,  34,  50,  25 },  {  -44,  45,  23,  37 } } },  /* 85: not used by a script */
    { { {   -5,  20,  79,  18 },  {  -19,  56,  70,  15 },  {  -34,  62,  38,  32 },  {  -11,  40,   0,  38 } } },  /* 86: not used by a script */
    { { {  -20,  20,  75,  16 },  {  -16,  42,  76,  17 },  {  -16,  46,  54,  22 },  {  -21,  51,  34,  20 } } },  /* 87: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    { { {  -21,  20,  43,  18 },  {  -24,  39,  37,  15 },  {  -19,  52,  13,  24 },  {  -30,  68,   0,  15 } } },  /* 88: not used by a script */
    { { {  -24,  20,  78,  18 },  {  -33,  48,  73,  15 },  {  -19,  50,  48,  25 },  {  -86, 116,  19,  29 } } },  /* 89: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  68,  53,  23 },  {  -66,  60,  28,  25 } } },  /* 90: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {  -41,  20,  74,  18 },  {  -53,  65,  60,  21 },  {  -53,  63,  37,  24 },  {  -62,  81,   0,  37 } } },  /* 91: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {  -51,  20,  70,  18 },  {  -49,  62,  57,  19 },  {  -55,  48,  37,  19 },  {  -62,  81,   0,  37 } } },  /* 92: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  54,  51,  25 },  {  -42,  66,   1,  50 } } },  /* 93: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  49,   0,  26 },  {  -45,  29,  26,  16 } } },  /* 94: KAGAMI K C, ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1) +2 */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  46,   0,  37 },  {  -37,  21,  26,  21 } } },  /* 95: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) +1 */
    { { {  -21,  16,  78,  14 },  {  -29,  41,  75,  12 },  {  -30,  47,  33,  48 },  {    0,   0,   0,   0 } } },  /* 96: not used by a script */
    { { {  -23,  20,  60,  18 },  {  -53, 106,  67,  27 },  {    0,   0,   0,   0 },  {  -38,  70,  90,  66 } } },  /* 97: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    { { {  -30,  20,  63,  18 },  {  -55, 100,  76,  23 },  {  -24,  53,  94,  22 },  {  -21,  75, 116,  31 } } },  /* 98: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +10 */
    { { {  -19,  20,  58,  18 },  {  -34,  59,  63,  16 },  {  -29,  48,  79,  16 },  {  -43,  69,  95,  38 } } },  /* 99: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 100: M KICK A */
    { { {  -16,  20,  98,  18 },  {  -27,  48,  88,  15 },  {  -39,  74,  63,  26 },  {    0,   0,   0,   0 } } },  /* 101: L KICK C */
    { { {  -16,  20,  70,  18 },  {  -36,  56,  62,  15 },  {  -26,  42,  34,  32 },  {  -38,  46,   0,  38 } } },  /* 102: S KICK B */
    { { {  -16,  20,  78,  18 },  {  -36,  56,  70,  15 },  {  -26,  42,  38,  32 },  {  -30,  56,   0,  44 } } },  /* 103: M KICK B, follow-up of S KICK A */
    { { {  -23,  20,  68,  18 },  {  -39,  47,  53,  22 },  {  -39,  55,  33,  20 },  {  -40,  78,   0,  34 } } },  /* 104: KAGAMI P A, no name */
    { { {  -16,  20,  74,  18 },  {  -36,  56,  66,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 105: M PUNCH A */
    { { {  -20,  20,  72,  18 },  {  -36,  56,  63,  15 },  {  -26,  42,  34,  32 },  {  -36,  68,   0,  37 } } },  /* 106: L PUNCH A */
    { { {  -21,  20,  66,  18 },  {  -27,  46,  54,  15 },  {  -26,  40,  29,  29 },  {  -40,  76,   0,  34 } } },  /* 107: L PUNCH B */
    { { {  -16,  20,  98,  18 },  {  -44,  82,  94,  13 },  {  -29,  53,  63,  32 },  {  -52,  95,  34,  28 } } },  /* 108: L KICK C */
    { { {  -19,  20,  50,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -48,  80,   0,  38 } } },  /* 109: no name */
    { { {   -2,  20,  30,  18 },  {  -16,  44,  26,  18 },  {  -16,  49,   0,  26 },  {    0,   0,   0,   0 } } },  /* 110: KAGAMI K C */
    { { {  -18,  20,  47,  18 },  {    0,   0,   0,   0 },  {  -36,  59,   0,  59 },  {  -68,  97,   0,  27 } } },  /* 111: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A, ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -39,  20,  59,  18 },  {  -55,  96,  72,  25 },  {    0,   0,   0,   0 },  {  -25,  84,  96,  33 } } },  /* 112: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {  -41,  20,  64,  18 },  {  -21,  72,  62,  29 },  {    0,   0,   0,   0 },  {   -9,  55,  91,  22 } } },  /* 113: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +4 */
    { { {  -41,  20,  64,  18 },  {  -21,  68,  62,  29 },  {    0,   0,   0,   0 },  {  -41,  34,  62,  40 } } },  /* 114: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +3 */
    { { {  -18,  20,  87,  18 },  {  -32,  47,  74,  19 },  {  -23,  42,  52,  22 },  {  -16,  33,  16,  36 } } },  /* 115: V JUMP K M A */
    { { {  -15,  20,  75,  18 },  {  -34,  58,  66,  18 },  {  -26,  42,  34,  32 },  {  -44,  76,   0,  37 } } },  /* 116: follow-up of M PUNCH C */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 117: V JUMP P S A, V JUMP P M A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 118: V JUMP P M A */
    { { {  -10,  20,  87,  18 },  {  -34,  52,  80,  15 },  {  -19,  36,  60,  20 },  {  -32,  60,  39,  21 } } },  /* 119: V JUMP P M A */
    { { {   -8,  20,  78,  18 },  {  -22,  46,  70,  15 },  {  -20,  49,  46,  24 },  {  -28,  60,   0,  46 } } },  /* 120: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  63,  28,  52 },  {  -26,  63,   0,  28 } } },  /* 121: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {   20,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -28,  56,   0,  68 },  {  -60,  50,  78,  20 } } },  /* 122: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {  -18,  20,  84,  18 },  {  -36,  48,  76,  15 },  {  -39,  54,  51,  25 },  {  -33,  51,  39,  12 } } },  /* 123: ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2), ATTACK 2 SP: EX 421+KK (routine Att_HOMING_JUMP) */
    { { {  -26,  20,  67,  18 },  {  -36,  56,  58,  15 },  {  -26,  42,  30,  32 },  {  -36,  68,   0,  37 } } },  /* 124: M PUNCH C, follow-up of S PUNCH A */
    { { {  -16,  20,  92,  18 },  {  -43,  61,  81,  15 },  {  -28,  51,  59,  22 },  {  -11,  34,  44,  16 } } },  /* 125: M KICK C */
    { { {  -43,  20,  76,  18 },  {  -47,  58,  73,  15 },  {  -42,  51,  53,  20 },  {  -23,  51,  28,  25 } } },  /* 126: not started by a command */
    { { {  -52,  20,  49,  18 },  {  -44,  62,  58,  19 },  {  -46,  70,  28,  29 },  {  -41,  79,   0,  27 } } },  /* 127: PIYO */
    { { {  -19,  20,  51,  18 },  {    0,   0,   0,   0 },  {  -36,  58,   0,  64 },  {  -48,  80,   0,  27 } } },  /* 128: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) */
    { { {  -36,  28,  49,  18 },  {  -32,  62,  59,  19 },  {  -33,  68,  31,  28 },  {  -37,  77,   0,  30 } } },  /* 129: PIYO */
    { { {  -21,  20,  68,  18 },  {  -27,  52,  54,  15 },  {  -26,  42,  29,  29 },  {  -38,  78,   0,  34 } } },  /* 130: not used by a script */
    { { {  -21,  20,  68,  18 },  {  -27,  52,  54,  15 },  {  -26,  42,  29,  29 },  {  -38,  78,   0,  34 } } },  /* 131: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  45,  37,  39 },  {  -30,  44,   0,  37 } } },  /* 132: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -30,  53,  23,  38 },  {  -38,  70,   0,  23 } } },  /* 133: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -15,  20,  73,  18 },  {  -26,  46,  66,  15 },  {  -18,  34,  34,  32 },  {  -24,  56,   0,  37 } } },  /* 134: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {  -15,  20,  80,  18 },  {  -32,  50,  68,  16 },  {  -26,  36,  34,  34 },  {  -24,  31,  22,  12 } } },  /* 135: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {  -15,  20,  73,  18 },  {  -26,  46,  66,  15 },  {  -18,  34,  34,  32 },  {  -24,  56,   0,  37 } } },  /* 136: not used by a script */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,  18,  16 } } },  /* 137: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -16,  20,  78,  18 },  {  -36,  52,  70,  12 },  {  -28,  36,  34,  36 },  {  -34,  47,  18,  16 } } },  /* 138: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { {  -49,  20,  70,  18 },  {  -75,  84,  57,  25 },  {  -56,  39,  36,  24 },  {  -62,  81,   0,  37 } } },  /* 139: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {    4,  20,  74,  18 },  {  -27,  52,  63,  19 },  {  -26,  40,  40,  24 },  {  -34,  57,   0,  45 } } },  /* 140: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI), EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -10,  20,  84,  16 },  {  -32,  46,  76,  12 },  {  -30,  38,  54,  20 },  {  -26,  48,  16,  36 } } },  /* 141: not started by a command */
    { { {  -14,  20,  83,  18 },  {  -29,  48,  79,  12 },  {  -24,  41,  60,  19 },  {  -29,  54,  21,  39 } } },  /* 142: not started by a command */
    { { {  -19,  20,  43,  18 },  {    0,   0,   0,   0 },  {  -36,  58,   0,  56 },  {  -48,  80,   0,  27 } } },  /* 143: ATTACK 4 SP: EX 236+PP (routine Att_PL07_AT1) */
    { { {  -16,  20,  49,  18 },  {    0,   0,   0,   0 },  {  -38,  60,   0,  58 },  {  -54,  86,   0,  27 } } },  /* 144: KAGAMI P A */
    { { {  -21,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -32,  54,   0,  58 },  {  -54,  86,   0,  29 } } },  /* 145: KAGAMI P A */
    { { {  -31,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -38,  60,   0,  58 },  {  -58,  90,   0,  29 } } },  /* 146: KAGAMI P A */
    { { {  -49,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -58,  58,   0,  60 },  {  -62,  79,   0,  33 } } },  /* 147: KAGAMI P A */
    { { {  -54,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -55,  50,   0,  62 },  {  -65,  79,   0,  34 } } },  /* 148: KAGAMI P A */
    { { {  -59,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -55,  46,   0,  63 },  {  -59,  68,   0,  34 } } },  /* 149: KAGAMI P A */
    { { {  -58,  20,  55,  18 },  {    0,   0,   0,   0 },  {  -55,  48,   0,  63 },  {  -59,  68,   0,  34 } } },  /* 150: KAGAMI P A */
    { { {  -52,  20,  52,  18 },  {    0,   0,   0,   0 },  {  -55,  53,   0,  61 },  {  -61,  72,   0,  34 } } },  /* 151: KAGAMI P A */
    { { {  -49,  20,  47,  18 },  {  -66,  52,  34,  18 },  {  -51,  48,   0,  46 },  {  -63,  76,   0,  34 } } },  /* 152: KAGAMI P A */
    { { {  -18,  20,  49,  18 },  {    0,   0,   0,   0 },  {  -36,  53,   0,  55 },  {  -54,  80,   0,  27 } } },  /* 153: KAGAMI K A */
    { { {  -27,  20,  47,  18 },  {    0,   0,   0,   0 },  {  -43,  52,   0,  55 },  {  -54,  78,   0,  27 } } },  /* 154: KAGAMI K A */
    { { {  -23,  20,  43,  18 },  {    0,   0,   0,   0 },  {  -49,  57,   0,  54 },  {  -56,  73,   0,  27 } } },  /* 155: KAGAMI K A */
    { { {   -9,  20,  41,  18 },  {    0,   0,   0,   0 },  {  -49,  62,   0,  53 },  {  -52,  76,   0,  27 } } },  /* 156: KAGAMI K A */
    { { {   -3,  20,  39,  18 },  {    0,   0,   0,   0 },  {  -32,  59,   0,  49 },  { -117,  96,   0,  15 } } },  /* 157: KAGAMI K A */
    { { {   -8,  20,  40,  18 },  {    0,   0,   0,   0 },  {  -31,  55,   0,  50 },  { -106,  92,   0,  17 } } },  /* 158: KAGAMI K A */
    { { {  -13,  20,  40,  18 },  {    0,   0,   0,   0 },  {  -32,  50,   0,  49 },  {  -98,  84,   0,  20 } } },  /* 159: KAGAMI K A */
    { { {  -18,  20,  40,  18 },  {    0,   0,   0,   0 },  {  -34,  52,   0,  52 },  {  -85,  71,   0,  19 } } },  /* 160: KAGAMI K A */
    { { {  -22,  20,  41,  18 },  {    0,   0,   0,   0 },  {  -45,  61,   0,  54 },  {  -56,  42,   0,  37 } } },  /* 161: KAGAMI K A */
    { { {  -33,  20,  43,  18 },  {    0,   0,   0,   0 },  {  -54,  62,   0,  53 },  {    0,   0,   0,   0 } } },  /* 162: KAGAMI K A */
    { { {    1,  20,  79,  16 },  {  -24,  48,  66,  14 },  {  -27,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 163: UPPER L */
    { { {    9,  20,  78,  16 },  {  -21,  48,  66,  14 },  {  -28,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 164: UPPER L */
    { { {   13,  20,  77,  16 },  {  -19,  48,  66,  14 },  {  -29,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 165: UPPER L */
    { { {   15,  20,  76,  16 },  {  -18,  48,  66,  14 },  {  -30,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 166: not used by a script */
    { { {    1,  20,  73,  16 },  {  -20,  48,  65,  14 },  {  -22,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 167: FACE S, FACE M, FACE L +7 */
    { { {   13,  20,  71,  16 },  {  -14,  48,  64,  14 },  {  -19,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 168: FACE M, FACE L, FOOK TEMAE L +5 */
    { { {   21,  20,  69,  16 },  {  -10,  48,  63,  14 },  {  -17,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 169: FACE L, FOOK TEMAE L, FOOK TEMAE SP +2 */
    { { {   25,  20,  67,  16 },  {   -8,  48,  62,  14 },  {  -16,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 170: FACE L, FOOK TEMAE SP, FOOK OKU SP */
    { { {  -19,  20,  72,  16 },  {  -26,  48,  64,  14 },  {  -24,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 171: NOUTEN L, BODY UPPER L, NOUTEN S +2 */
    { { {  -23,  20,  69,  16 },  {  -24,  48,  62,  14 },  {  -22,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 172: NOUTEN L, BODY UPPER L, NOUTEN M +1 */
    { { {  -27,  20,  66,  16 },  {  -22,  48,  60,  14 },  {  -20,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 173: NOUTEN L, BODY UPPER L, BODY BROW L */
    { { {  -31,  20,  63,  16 },  {  -20,  48,  58,  14 },  {  -18,  42,  37,  28 },  {  -33,  67,   0,  36 } } },  /* 174: BODY UPPER L, TATAKI S, BODY BROW L */
    { { {  -13,  20,  42,  18 },  {  -27,  50,  37,  17 },  {  -31,  55,  27,  14 },  {  -42,  78,   0,  27 } } },  /* 175: KAGAMI S, KAGAMI M, KAGAMI L +3 */
    { { {   -7,  20,  42,  18 },  {  -25,  50,  37,  17 },  {  -30,  55,  27,  14 },  {  -42,  78,   0,  27 } } },  /* 176: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    { { {   -1,  20,  42,  18 },  {  -23,  50,  37,  17 },  {  -29,  55,  27,  14 },  {  -42,  78,   0,  27 } } },  /* 177: KAGAMI L */
    { { {    5,  20,  42,  18 },  {  -21,  50,  37,  17 },  {  -28,  55,  27,  14 },  {  -42,  78,   0,  27 } } },  /* 178: not used by a script */
    { { {  -46,  20,  75,  18 },  {  -44,  47,  71,  16 },  {  -39,  48,  54,  17 },  {  -43,  65,  33,  23 } } },  /* 179: F JUMP P M A */
    { { {  -47,  20,  73,  18 },  {  -48,  47,  67,  19 },  {  -35,  45,  51,  18 },  {  -29,  52,  34,  21 } } },  /* 180: F JUMP P M A */
    { { {  -45,  20,  73,  18 },  {  -47,  43,  61,  25 },  {  -35,  45,  51,  18 },  {  -29,  52,  34,  21 } } },  /* 181: F JUMP P M A */
    { { {  -43,  20,  73,  18 },  {  -41,  44,  61,  25 },  {  -39,  48,  51,  18 },  {  -29,  48,  34,  21 } } },  /* 182: F JUMP P M A */
    { { {  -29,  20,  80,  18 },  {  -35,  44,  65,  25 },  {  -23,  37,  51,  18 },  {  -27,  47,  36,  18 } } },  /* 183: F JUMP P M A */
    { { {  -21,  20,  82,  18 },  {  -29,  43,  68,  24 },  {  -19,  35,  51,  18 },  {  -26,  45,  36,  18 } } },  /* 184: F JUMP P M A */
    { { {   18,  20,  70,  18 },  {  -13,  41,  75,  18 },  {  -20,  41,  61,  19 },  {  -27,  41,  36,  31 } } },  /* 185: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   21,  20,  72,  18 },  {   10,  24,  67,  33 },  {  -12,  22,  63,  33 },  {  -34,  27,  54,  39 } } },  /* 186: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   19,  20,  70,  18 },  {    5,  24,  71,  33 },  {  -13,  22,  75,  31 },  {  -37,  27,  73,  35 } } },  /* 187: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   15,  20,  74,  18 },  {   -3,  24,  75,  35 },  {  -20,  22,  79,  29 },  {  -39,  23,  82,  30 } } },  /* 188: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {    9,  20,  68,  18 },  {   -6,  25,  71,  32 },  {  -20,  22,  76,  32 },  {  -34,  26,  84,  34 } } },  /* 189: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {    3,  20,  65,  18 },  {   -9,  27,  71,  30 },  {  -24,  27,  76,  32 },  {  -36,  33,  87,  33 } } },  /* 190: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {    0,  20,  62,  18 },  {  -20,  38,  71,  21 },  {  -26,  32,  78,  25 },  {  -38,  40,  93,  24 } } },  /* 191: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   -5,  20,  59,  18 },  {  -25,  39,  71,  19 },  {  -30,  38,  81,  21 },  {  -36,  42,  94,  23 } } },  /* 192: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   -9,  20,  57,  18 },  {  -28,  40,  71,  19 },  {  -26,  36,  83,  21 },  {  -30,  41,  99,  20 } } },  /* 193: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -17,  20,  57,  18 },  {  -31,  40,  71,  19 },  {  -33,  38,  83,  21 },  {  -26,  37,  99,  20 } } },  /* 194: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -23,  20,  57,  18 },  {  -33,  43,  72,  17 },  {  -35,  42,  83,  18 },  {  -22,  37,  99,  20 } } },  /* 195: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -29,  20,  59,  18 },  {  -31,  45,  72,  18 },  {  -25,  38,  83,  18 },  {  -20,  42,  99,  20 } } },  /* 196: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -32,  20,  59,  18 },  {  -36,  43,  70,  18 },  {  -29,  39,  83,  18 },  {  -16,  47,  94,  19 } } },  /* 197: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -39,  20,  60,  18 },  {  -42,  45,  69,  19 },  {  -29,  39,  80,  18 },  {   -9,  36,  83,  25 } } },  /* 198: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -46,  20,  73,  18 },  {  -34,  27,  69,  32 },  {  -15,  22,  71,  24 },  {    4,  25,  61,  36 } } },  /* 199: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -31,  20,  94,  18 },  {  -27,  39,  83,  18 },  {  -19,  32,  70,  16 },  {  -20,  43,  47,  23 } } },  /* 200: 623+P light (routine Att_SLIDE_and_JUMP), 623+P medium (routine Att_SLIDE_and_JUMP), 623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  20,  49,  16 },  {  -32,  49,  42,  21 },  {  -25,  46,  28,  20 },  {  -33,  67,   0,  36 } } },  /* 201: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -41,  20,  47,  16 },  {  -32,  49,  42,  23 },  {  -25,  46,  28,  20 },  {  -36,  70,   0,  32 } } },  /* 202: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  20,  50,  16 },  {  -30,  49,  44,  23 },  {  -25,  48,  28,  20 },  {  -31,  62,   0,  32 } } },  /* 203: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  20,  53,  16 },  {  -30,  49,  46,  23 },  {  -28,  49,  28,  20 },  {  -30,  56,   0,  32 } } },  /* 204: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -41,  20,  59,  16 },  {  -31,  49,  50,  23 },  {  -38,  58,  38,  12 },  {  -33,  58,   0,  38 } } },  /* 205: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -31,  20,  69,  16 },  {  -24,  43,  57,  22 },  {  -39,  60,  45,  12 },  {  -32,  57,   0,  45 } } },  /* 206: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -15,  20,  74,  16 },  {  -18,  36,  56,  22 },  {  -25,  44,  45,  21 },  {  -32,  57,   0,  45 } } },  /* 207: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -21,  20,  70,  16 },  {  -27,  48,  60,  18 },  {  -23,  41,  36,  24 },  {  -37,  74,   0,  36 } } },  /* 208: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -36,  20,  59,  16 },  {  -45,  50,  53,  16 },  {  -28,  46,  36,  18 },  {  -39,  76,   0,  36 } } },  /* 209: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -39,  20,  55,  16 },  {  -36,  39,  49,  17 },  {  -27,  41,  37,  17 },  {  -39,  70,   0,  37 } } },  /* 210: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -38,  20,  53,  16 },  {  -31,  39,  49,  17 },  {  -25,  40,  37,  17 },  {  -37,  66,   0,  37 } } },  /* 211: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -35,  20,  53,  16 },  {  -31,  39,  50,  17 },  {  -25,  39,  37,  17 },  {  -37,  66,   0,  37 } } },  /* 212: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -39,  20,  58,  16 },  {  -31,  38,  54,  18 },  {  -26,  42,  37,  17 },  {  -33,  63,   0,  37 } } },  /* 213: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -33,  20,  70,  16 },  {  -25,  35,  63,  17 },  {  -23,  38,  46,  17 },  {  -30,  44,   0,  46 } } },  /* 214: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -23,  20,  72,  16 },  {  -14,  32,  63,  18 },  {  -19,  41,  46,  17 },  {  -26,  41,   0,  46 } } },  /* 215: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -13,  20,  74,  16 },  {  -26,  43,  59,  17 },  {  -18,  33,  42,  17 },  {  -27,  45,   0,  42 } } },  /* 216: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -16,  20,  75,  16 },  {  -27,  42,  61,  17 },  {  -19,  35,  44,  17 },  {  -29,  50,   0,  44 } } },  /* 217: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -15,  20,  59,  16 },  {  -28,  48,  53,  14 },  {  -26,  42,  37,  16 },  {  -35,  64,   0,  36 } } },  /* 218: ATTACK 8 SP: not started by a command */
    { { {   -9,  20,  73,  16 },  {  -17,  40,  58,  20 },  {  -28,  40,  49,  14 },  {  -34,  44,  30,  19 } } },  /* 219: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    { { {   11,  20,  73,  16 },  {    4,  41,  58,  20 },  {   -5,  28,  40,  30 },  {  -34,  29,  37,  31 } } },  /* 220: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    { { {   12,  20,  69,  16 },  {    6,  42,  52,  20 },  {    0,  37,  36,  31 },  {  -24,  24,  40,  30 } } },  /* 221: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    { { {   21,  20,  52,  16 },  {   11,  42,  36,  20 },  {   -3,  32,  21,  30 },  {  -19,  22,  33,  27 } } },  /* 222: ASIBARAI SIRI, ASIB TUNNOMERI, ASIB SIRI LOSE +1 */
    { { {    0,  20,  70,  16 },  {  -17,  42,  56,  17 },  {  -24,  42,  42,  14 },  {  -31,  43,  30,  17 } } },  /* 223: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   33,  20,  81,  16 },  {    7,  38,  72,  22 },  {  -13,  38,  58,  26 },  {  -20,  42,  39,  22 } } },  /* 224: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {   42,  20,  82,  16 },  {   12,  35,  75,  25 },  {   -5,  29,  66,  25 },  {  -19,  37,  51,  28 } } },  /* 225: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   46,  20,  80,  16 },  {   13,  35,  77,  25 },  {   -5,  29,  72,  25 },  {  -21,  34,  58,  30 } } },  /* 226: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   52,  20,  77,  16 },  {   17,  35,  78,  24 },  {   -4,  29,  73,  26 },  {  -22,  31,  61,  30 } } },  /* 227: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   52,  20,  74,  16 },  {   19,  35,  78,  23 },  {   -4,  29,  76,  23 },  {  -21,  25,  68,  25 } } },  /* 228: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {   48,  20,  62,  16 },  {   29,  26,  73,  23 },  {    0,  29,  78,  23 },  {  -26,  30,  72,  25 } } },  /* 229: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {   44,  20,  54,  16 },  {   29,  25,  60,  23 },  {   10,  29,  72,  21 },  {  -24,  34,  72,  24 } } },  /* 230: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {   38,  20,  41,  16 },  {   21,  26,  45,  25 },  {   11,  30,  61,  21 },  {  -22,  50,  70,  23 } } },  /* 231: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {   28,  20,  26,  16 },  {   17,  29,  35,  25 },  {   11,  30,  56,  21 },  {  -25,  54,  66,  22 } } },  /* 232: NOKEZORI, UPPER, BODY UPPER +5 */
    { { {    2,  20,   1,  16 },  {  -11,  37,  16,  25 },  {  -15,  41,  36,  21 },  {  -18,  43,  57,  19 } } },  /* 233: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {  -41,  20,  64,  16 },  {  -35,  42,  59,  17 },  {  -29,  48,  45,  19 },  {  -33,  45,  27,  18 } } },  /* 234: KUNOJI, KUNOJI NOKE */
    { { {  -19,  20,  53,  16 },  {  -10,  42,  55,  17 },  {   -7,  46,  42,  21 },  {  -22,  42,  30,  18 } } },  /* 235: KUNOJI, KUNOJI NOKE */
    { { {   -2,  20,  75,  16 },  {  -12,  34,  61,  17 },  {  -19,  34,  45,  24 },  {  -28,  46,  29,  16 } } },  /* 236: KIRIMOMI */
    { { {   15,  20,  79,  16 },  {   -1,  31,  64,  21 },  {  -10,  29,  49,  24 },  {  -21,  37,  29,  20 } } },  /* 237: KIRIMOMI */
    { { {   18,  20,  85,  16 },  {   -3,  31,  72,  21 },  {  -13,  29,  57,  24 },  {  -23,  30,  39,  24 } } },  /* 238: KIRIMOMI */
    { { {   19,  20,  87,  16 },  {   -2,  32,  74,  21 },  {  -12,  32,  59,  24 },  {  -23,  28,  43,  24 } } },  /* 239: KIRIMOMI */
    { { {   17,  20,  86,  16 },  {   -3,  28,  70,  21 },  {  -14,  31,  59,  21 },  {  -26,  32,  45,  21 } } },  /* 240: KIRIMOMI */
    { { {   12,  20,  92,  16 },  {   -6,  30,  76,  21 },  {  -18,  29,  63,  18 },  {  -30,  33,  49,  18 } } },  /* 241: KIRIMOMI */
    { { {   13,  20,  87,  16 },  {   -6,  33,  71,  22 },  {  -18,  31,  57,  23 },  {  -31,  32,  46,  23 } } },  /* 242: KIRIMOMI */
    { { {   10,  20,  81,  16 },  {   -7,  28,  64,  21 },  {  -23,  32,  55,  20 },  {  -41,  35,  42,  25 } } },  /* 243: KIRIMOMI */
    { { {   10,  20,  71,  16 },  {   -8,  28,  59,  21 },  {  -23,  32,  51,  22 },  {  -45,  32,  40,  25 } } },  /* 244: KIRIMOMI */
    { { {   15,  20,  64,  16 },  {   -8,  28,  55,  22 },  {  -23,  25,  46,  25 },  {  -43,  27,  40,  21 } } },  /* 245: KIRIMOMI */
    { { {   16,  20,  60,  16 },  {   -7,  28,  51,  23 },  {  -23,  25,  43,  23 },  {  -47,  30,  33,  26 } } },  /* 246: KIRIMOMI */
    { { {   17,  20,  51,  16 },  {   -5,  28,  43,  23 },  {  -22,  25,  36,  22 },  {  -42,  30,  25,  26 } } },  /* 247: KIRIMOMI */
    { { {   19,  20,  42,  16 },  {   -5,  28,  36,  19 },  {  -22,  25,  31,  20 },  {  -44,  30,  24,  19 } } },  /* 248: KIRIMOMI */
    { { {   21,  20,  38,  16 },  {   -2,  28,  30,  22 },  {  -20,  25,  23,  23 },  {  -45,  31,  16,  25 } } },  /* 249: KIRIMOMI */
    { { {   25,  20,  29,  29 },  {    1,  28,  20,  22 },  {  -20,  25,  13,  25 },  {  -45,  31,  10,  30 } } },  /* 250: KIRIMOMI */
    { { {   24,  20,  24,  16 },  {    2,  28,  13,  20 },  {  -16,  18,  10,  25 },  {  -45,  29,  11,  27 } } },  /* 251: KIRIMOMI */
    { { {  -26,  20,  64,  16 },  {  -22,  39,  60,  17 },  {  -14,  29,  41,  19 },  {  -24,  41,  27,  19 } } },  /* 252: TATAKI AIR, TTKI V. AIR */
    { { {  -34,  20,  22,  16 },  {  -31,  39,  36,  23 },  {  -19,  34,  32,  23 },  {  -27,  40,  15,  17 } } },  /* 253: TATAKI AIR, TTKI V. AIR */
    { { {   -4,  20,   3,  16 },  {  -27,  40,   6,  17 },  {  -33,  36,  16,  22 },  {    3,  25,  13,  20 } } },  /* 254: TATAKI AIR, TTKI V. AIR */
    { { {   -4,  20,  82,  16 },  {  -16,  42,  70,  17 },  {  -17,  32,  54,  20 },  {  -12,  35,  33,  21 } } },  /* 255: HUMI ASIB */
    { { {  -34,  20,  51,  16 },  {  -26,  25,  45,  34 },  {  -11,  25,  43,  33 },  {    2,  25,  34,  33 } } },  /* 256: HUMI ASIB */
    { { {    1,  20,  26,  16 },  {  -22,  34,  27,  21 },  {  -29,  29,  38,  29 },  {    0,  24,  34,  28 } } },  /* 257: HUMI ASIB */
    { { {  -18,  20,  79,  16 },  {  -18,  38,  68,  17 },  {  -14,  32,  52,  21 },  {  -23,  48,  32,  25 } } },  /* 258: DENKI */
    { { {    7,  20,  72,  18 },  {   -5,  41,  60,  15 },  {  -14,  34,  36,  24 },  {  -29,  51,  15,  33 } } },  /* 259: TOUKETSU A */
    { { {  -15,  20,  73,  16 },  {  -28,  48,  64,  14 },  {  -26,  42,  37,  26 },  {  -33,  67,   0,  36 } } },  /* 260: FRONT WALK, BACK WALK */
    { { {  -15,  20,  79,  16 },  {  -25,  48,  69,  14 },  {  -23,  42,  39,  28 },  {  -27,  53,   0,  38 } } },  /* 261: FRONT WALK, BACK WALK */
    { { {   -9,  20,  79,  16 },  {  -22,  48,  69,  14 },  {  -20,  42,  39,  28 },  {  -27,  53,   0,  38 } } },  /* 262: HURIMUKI */
    { { {   -9,  20,  42,  18 },  {  -23,  50,  37,  17 },  {  -26,  55,  27,  14 },  {  -38,  78,   0,  27 } } },  /* 263: KAGAMI TURN */
    { { {  -24,  20,  70,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  29,  48 },  {  -40,  72,   0,  37 } } },  /* 264: DASH HUMIKOMI */
    { { {  -22,  20,  74,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  33,  48 },  {  -34,  72,   0,  37 } } },  /* 265: DASH HUMIKOMI */
    { { {  -15,  20,  62,  18 },  {    0,   0,   0,   0 },  {  -29,  52,  25,  48 },  {  -32,  72,   0,  37 } } },  /* 266: DASH HUMIKOMI */
    { { {  -22,  20,  64,  18 },  {    0,   0,   0,   0 },  {  -32,  52,  25,  48 },  {  -36,  72,   0,  37 } } },  /* 267: DASH HUMIKOMI */
    { { {  -14,  20,  88,  18 },  {  -31,  59,  80,  14 },  {  -39,  48,  17,  63 },  {  -34,  44,  34,  20 } } },  /* 268: DASH TOBINOKI */
    { { {  -20,  20,  82,  18 },  {  -37,  54,  80,  14 },  {  -35,  48,  17,  63 },  {  -34,  44,  34,  20 } } },  /* 269: DASH TOBINOKI */
    { { {  -32,  20,  81,  18 },  {  -40,  59,  74,  14 },  {  -30,  48,  29,  44 },  {  -36,  72,   0,  37 } } },  /* 270: DASH TOBINOKI, follow-up of JUDGMENT LOSE */
    { { {  -17,  20,  81,  18 },  {  -30,  46,  86,  12 },  {  -19,  38,  70,  19 },  {  -38,  60,  45,  25 } } },  /* 271: JUMP VERTICAL, JUMP BACK, SP JUMP V +4 */
    { { {  -13,  20,  83,  18 },  {  -27,  47,  86,  12 },  {  -21,  41,  67,  19 },  {  -25,  50,  38,  29 } } },  /* 272: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
};

const HAND_BOX ibuki_hand_box[88] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -63,  35,  61,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH B */
    { { {  -78,  50,  61,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH B */
    { { {  -58,  30,  63,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: no name, S PUNCH A */
    { { {  -91,  61,  50,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M KICK C, follow-up of M KICK A */
    { { {  -86,  38,   0,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: KAGAMI K A, follow-up of M PUNCH C, L PUNCH A, ATTACK 5 SP: after 214+K (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -54,  36,  62,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L KICK C */
    { { {  -93,  69,  62,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L KICK C */
    { { {  -77,  50,  36,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: F JUMP K M A, follow-up of V JUMP P L A, F JUMP K S A */
    { { {  -63,  37,  75,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH C, follow-up of S PUNCH A */
    { { {  -75,  39,  62,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A */
    { { {  -57,  37,  61,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH A */
    { { {  -66,  60,  45,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A */
    { { {  -91,  65,  25,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: S KICK B */
    { { {  -75,  48,  58,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M KICK A */
    { { {  -52,  42,  58,  68 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L KICK A, ATTACK 6 S: not started by a command, ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -56,  35,  49,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH B */
    { { {  -78, 106,  38,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: KAGAMI P A, no name */
    { { {  -67,  52,  65,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: KAGAMI P A, no name */
    { { {  -90,  64,   6,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: KAGAMI K A */
    { { {  -87,  68,  65,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: V JUMP P S A */
    { { {  -67,  49,  57,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: V JUMP P L A, follow-up of F JUMP P S A */
    { { {  -92,  69,  39,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: V JUMP K S A, V JUMP K M A */
    { { {  -76,  43,  36,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: F JUMP P S A */
    { { {  -53,  35,  48,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: not used by a script */
    { { {  -50,  36,  59,  59 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -73,  49,  38,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP K L A, F JUMP K L A, not started by a command */
    { { {  -65,  37,  12,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: not started by a command */
    { { {  -47,  38,  28,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: F JUMP K S A */
    { { {  -44,  11,  53,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { {  -78,  54,  48,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { { -106, 116,  60,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {  -73,  34,  49,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: L PUNCH B */
    { { {  -77,  36,  46,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: L PUNCH B */
    { { {  -49,  38,  81,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {  -41,  35,  74,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: not used by a script */
    { { {  -36,  33,  71,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -85,  44,  44,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { { -104, 124,  49,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: ATTACK 9 S: SA II 23623+P (routine Att_PL07_SA2) */
    { { {  -75,  60,   0,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: KAGAMI K C, ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1) +2 */
    { { {  -52,  49,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 4 S: 236+P light (routine Att_PL07_AT1), ATTACK 4 M: 236+P medium (routine Att_PL07_AT1), ATTACK 4 L: 236+P heavy (routine Att_PL07_AT1) +1 */
    { { { -104,  77,  60,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: M KICK A */
    { { {  -87,  48,  53,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: L KICK C */
    { { {  -79,  56,  16,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: S KICK B */
    { { {  -54,  38,  34,  56 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: M KICK B, follow-up of S KICK A */
    { { {  -59,  34,  61,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: KAGAMI P A, no name */
    { { {  -75,  39,  62,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: M PUNCH A */
    { { {  -50,  29,  32,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: L PUNCH A */
    { { {  -56,  35,  49,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: L PUNCH B */
    { { {  -68,  96,  38,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: no name */
    { { {  -98,  82,   0,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: KAGAMI K C */
    { { {  -78,  55,  40,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP K M A */
    { { {  -68,  49,  69,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: V JUMP P S A, V JUMP P M A */
    { { {  -78,  59,  72,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: V JUMP P M A */
    { { {  -70,  51,  72,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: V JUMP P M A */
    { { {  -88,  98,  60,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: L KICK B, follow-up of M KICK B, follow-up of follow-up of M PUNCH C, L PUNCH A */
    { { {  -67,  41,  71,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: M PUNCH C, follow-up of S PUNCH A */
    { { {  -78,  62,  71,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: M KICK C */
    { { {  -72,  41,  40,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: not used by a script */
    { { {  -40,  50,  55,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -48,  52,  48,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: not used by a script */
    { { {  -42,  40,  58,  78 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 1 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 6 S: not started by a command */
    { { {  -49,  39,  58,  63 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 1 M: 623+K medium (routine Att_SHOURYUUKEN) */
    { { {  -52,  36,  51,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 1 L: 623+K heavy (routine Att_SHOURYUUKEN), ATTACK 1 SP: EX 623+KK (routine Att_SHOURYUUKEN) */
    { { { -122,  95,  60,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    { { {  -82,  55,  54,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 5 S: 214+K light (routine Att_CHOUCHUURENGEKI) */
    { { {  -66,  39,  56,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -46,  19,  57,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    { { {  -50,  23,  54,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: EX 214+KK (routine Att_CHOUCHUURENGEKI), after 214+K (routine Att_CHOUCHUURENGEKI) */
    { { { -110,  83,  60,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 5 M: 214+K medium (routine Att_CHOUCHUURENGEKI) */
    { { {  -92,  65,  54,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 5 L: 214+K heavy (routine Att_CHOUCHUURENGEKI) */
    { { { -113,  65,  45,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: KAGAMI P A */
    { { { -102,  54,  45,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: KAGAMI P A */
    { { {  -88,  40,  45,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: KAGAMI P A */
    { { {  -76,  30,  41,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: KAGAMI P A */
    { { {  -74,  21,  35,  21 },  {  -57,  17,  47,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: F JUMP P M A */
    { { {  -76,  24,  34,  22 },  {  -57,  17,  47,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: F JUMP P M A */
    { { {  -99,  68,  13,   8 },  {  -79,  49,  21,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: KAGAMI K A */
    { { {  -79,  42,  17,   7 },  {  -63,  26,  24,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: KAGAMI K A */
    { { {  -73,  41,  20,   9 },  {  -63,  31,  29,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: KAGAMI K A */
    { { {  -67,  35,  19,  11 },  {  -58,  26,  30,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: KAGAMI K A */
    { { {  -60,  17,  74,  20 },  {  -53,  19,  65,  15 },  {  -44,  22,  58,  12 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -51,  24,  46,  11 },  {    3,  24,  54,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -44,  19,  37,  17 },  {    2,  18,  60,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -42,  17,  37,  17 },  {    2,  16,  63,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -40,  14,  37,  12 },  {    0,  19,  66,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {    9,  15,  60,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP), ATTACK 8 M: SA III 23623+P medium (routine Att_SLIDE_and_JUMP), ATTACK 8 L: SA III 23623+P heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {  -73,  42,  32,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: not started by a command */
};

const HOSEI_BOX ibuki_hos_box[18] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   76 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +136 */
    { {  -24,   48,    0,   48 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +74 */
    { {  -24,   48,   44,   48 } },  /* 3: SP JUMP FRONT, GUARD AIR, TUKAMIHAZUSI +69 */
    { {  -30,   60,    0,   72 } },  /* 4: CATCH 5, CATCH 24, DASH TOBINOKI +5 */
    { {  -24,   48,   28,   36 } },  /* 5: L PUNCH B, UPPER L, FACE S +15 */
    { {  -32,   64,    0,   77 } },  /* 6: ATTACK 3 S: 6(123)4+P light (routine Att_CHOUCHUURENGEKI), ATTACK 3 M: 6(123)4+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 3 L: 6(123)4+P heavy/EX (routine Att_CHOUCHUURENGEKI) +1 */
    { {  -15,   40,   44,   38 } },  /* 7: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    { {  -28,   56,    0,   56 } },  /* 8: not used by a script */
    { {  -32,   61,   21,   58 } },  /* 9: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +1 */
    { {  -25,   48,   64,   53 } },  /* 10: ATTACK 7 S: air 236+P light (routine Att_PL07_AT3), ATTACK 7 M: air 236+P medium (routine Att_PL07_AT3), ATTACK 7 L: air 236+P heavy (routine Att_PL07_AT3) +16 */
    { {  -32,   64,   14,   78 } },  /* 11: ATTACK 2 S: 421+K light (routine Att_PL07_AT2), ATTACK 2 M: 421+K medium (routine Att_PL07_AT2), ATTACK 2 L: 421+K heavy (routine Att_PL07_AT2) +2 */
    { {  -30,   60,    0,   62 } },  /* 12: PIYO */
    { {  -28,   56,    0,   30 } },  /* 13: NEKOROBI S, no name */
    { {  -14,   48,    0,   76 } },  /* 14: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { {  -18,   48,    0,   76 } },  /* 15: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { {  -21,   48,    0,   76 } },  /* 16: 236+K light (routine Att_SLIDE_and_JUMP), 236+K medium (routine Att_SLIDE_and_JUMP), 236+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { {  -24,   48,    0,   64 } },  /* 17: not used by a script */
};
