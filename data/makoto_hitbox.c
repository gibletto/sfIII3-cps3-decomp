/*
 * MAKOTO_HITBOX.C  Makoto's hit boxes
 *
 * Each of Makoto's animation frames names an entry of makoto_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX makoto_hit_ix_table[360] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, LOSE NO STAND, LOSE SONABA +9 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +82 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +20 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 3: ATTACK 8 L: SA III 23623+P light (routine Att_PL17_AT2), ATTACK 8 SP: SA III 23623+P medium (routine Att_PL17_AT2), ATTACK 9 S: SA III 23623+P heavy (routine Att_PL17_AT2) +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 4: no name, OKIAGARI, UKEMI MOVE F +14 */
    {    3,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 5: not used by a script */
    {    4,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: no name, PIYO */
    {    5,    0,    0, 0x0000,    0,    4,    0,   15 },  /* 7: JUMP JUNBI, SP JUMP JUNBI */
    {    6,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 8: PARING AIR F, TUKAMIHAZUSI, TUKAMIHAZUSARE +7 */
    {    7,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 9: V JUMP K L A, F JUMP K L A, B JUMP K L A +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 10: NEKOROBI S, no name */
    {    8,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 11: no name, S V JP S P A */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 12: L KICK A */
    {   10,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 13: L KICK A, follow-up of M KICK C */
    {   11,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 14: L KICK A, follow-up of M KICK C */
    {   11,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 15: L KICK A, follow-up of M KICK C */
    {   11,    0,    3, 0x0000,    0,    1,    3,    1 },  /* 16: L KICK A, follow-up of M KICK C */
    {   11,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 17: L KICK A, follow-up of M KICK C */
    {   12,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 18: L KICK A, follow-up of M KICK C */
    {   13,    0,    5, 0x0000,    0,    1,    4,    1 },  /* 19: S PUNCH A */
    {   13,    0,    6, 0x0000,    0,    1,    5,    1 },  /* 20: S PUNCH A */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 21: S PUNCH A */
    {   14,    0,    7, 0x0000,    0,    1,    6,    1 },  /* 22: S PUNCH C */
    {   14,    0,    7, 0x0000,    0,    1,    7,    1 },  /* 23: S PUNCH C */
    {   14,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 24: S PUNCH C */
    {   14,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 25: S PUNCH C */
    {   15,    0,    9, 0x0000,    0,    1,    8,    1 },  /* 26: M PUNCH C */
    {   15,    0,   10, 0x0000,    0,    1,    9,    1 },  /* 27: M PUNCH C */
    {   15,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 28: M PUNCH C */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 29: L PUNCH A */
    {   16,    0,   11, 0x0000,    0,    1,   10,    1 },  /* 30: L PUNCH A */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH C */
    {   18,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 32: L PUNCH C */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 33: L PUNCH C */
    {   20,    0,   12, 0x0000,    0,    1,   11,    1 },  /* 34: L PUNCH C, follow-up of L PUNCH C */
    {   20,    0,   12, 0x0000,    0,    1,   12,    1 },  /* 35: L PUNCH C, follow-up of L PUNCH C */
    {    1,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 36: L PUNCH C, follow-up of L PUNCH C */
    {   21,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 37: S KICK A, M KICK A */
    {   22,    0,   14, 0x0000,    0,    1,   13,    7 },  /* 38: S KICK A */
    {   22,    0,   14, 0x0000,    0,    1,   13,    7 },  /* 39: not used by a script */
    {   22,    0,   14, 0x0000,    0,    1,   14,    7 },  /* 40: S KICK A */
    {   22,    0,   17, 0x0000,    0,    1,    0,    7 },  /* 41: S KICK A, follow-up of S KICK A */
    {   22,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 42: S KICK A, M KICK A, follow-up of S KICK A */
    {   23,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 43: M KICK A */
    {   23,    0,   18, 0x0000,    0,    1,   15,    7 },  /* 44: M KICK A, follow-up of S KICK A */
    {   23,    0,   18, 0x0000,    0,    1,   16,    7 },  /* 45: M KICK A, follow-up of S KICK A */
    {   23,    0,   18, 0x0000,    0,    1,    0,    7 },  /* 46: M KICK A */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: M KICK C */
    {   25,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: M KICK C */
    {   26,    0,   19, 0x0000,    0,    1,   17,    1 },  /* 49: M KICK C */
    {   26,    0,   19, 0x0000,    0,    1,   18,    1 },  /* 50: M KICK C */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 51: M KICK C, follow-up of M KICK C */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: follow-up of L PUNCH C */
    {   28,    0,   20, 0x0000,    0,   16,   19,    2 },  /* 53: KAGAMI P A */
    {   28,    0,    0, 0x0000,    0,   16,    0,    2 },  /* 54: KAGAMI P A */
    {   29,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 55: KAGAMI P A */
    {   30,    0,   21, 0x0000,    0,    2,   20,    2 },  /* 56: KAGAMI P A */
    {   31,    0,   22, 0x0000,    0,    2,    0,    2 },  /* 57: KAGAMI P A */
    {   32,    0,   23, 0x0000,    0,    2,   21,    2 },  /* 58: KAGAMI P A */
    {   32,    0,   24, 0x0000,    0,    2,    0,    2 },  /* 59: KAGAMI P A */
    {   32,    0,   25, 0x0000,    0,    2,    0,    2 },  /* 60: KAGAMI P A */
    {   31,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 61: KAGAMI P A */
    {   33,    0,    0, 0x0000,    0,   16,    0,    2 },  /* 62: KAGAMI K A */
    {   34,    0,   26, 0x0000,    0,   16,   22,    2 },  /* 63: KAGAMI K A */
    {   34,    0,    0, 0x0000,    0,   16,    0,    2 },  /* 64: KAGAMI K A */
    {   35,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 65: KAGAMI K A */
    {   36,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 66: KAGAMI K A */
    {   36,    0,   27, 0x0000,    0,    2,   23,    2 },  /* 67: KAGAMI K A */
    {   36,    0,   27, 0x0000,    0,    2,   24,    2 },  /* 68: KAGAMI K A */
    {   36,    0,   27, 0x0000,    0,    2,    0,    2 },  /* 69: KAGAMI K A */
    {   36,    0,   28, 0x0000,    0,    2,    0,    2 },  /* 70: KAGAMI K A */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 71: S KICK C */
    {   37,    0,   29, 0x0000,    0,    1,   25,    1 },  /* 72: S KICK C */
    {   37,    0,   29, 0x0000,    0,    1,   26,    1 },  /* 73: S KICK C */
    {   38,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 74: L KICK C */
    {   39,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 75: L KICK C */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: L KICK C, follow-up of L KICK C */
    {   41,    0,   30, 0x0000,    0,    1,   27,    1 },  /* 77: L KICK C */
    {   41,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 78: L KICK C */
    {   42,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 79: KAGAMI K A */
    {   43,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 80: KAGAMI K A */
    {   44,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 81: KAGAMI K A */
    {   45,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 82: KAGAMI K A */
    {   46,    0,   32, 0x0000,    0,    1,   28,    1 },  /* 83: KAGAMI K A */
    {   46,    0,   33, 0x0000,    0,    1,    0,    1 },  /* 84: KAGAMI K A */
    {   46,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: KAGAMI K A */
    {   47,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 86: KAGAMI K A */
    {   48,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 87: V JUMP P S A */
    {   49,    0,    0, 0x0000,    0,    4,   29,    4 },  /* 88: V JUMP P S A */
    {   50,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 89: V JUMP P M A */
    {   51,    0,   35, 0x0000,    0,    4,   30,    4 },  /* 90: V JUMP P M A */
    {   52,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 91: V JUMP P L A */
    {   53,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 92: V JUMP P L A */
    {   53,    0,   36, 0x0000,    0,    4,   31,    4 },  /* 93: V JUMP P L A */
    {   54,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 94: V JUMP K S A, F JUMP K S A, B JUMP K S A */
    {   55,    0,    0, 0x0000,    0,    4,   32,    4 },  /* 95: V JUMP K S A, F JUMP K S A, B JUMP K S A */
    {   56,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 96: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    {   57,    0,   38, 0x0000,    0,    4,   33,    4 },  /* 97: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    {   58,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 98: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    {   59,    0,   39, 0x0000,    0,    4,   34,    4 },  /* 99: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    {   59,    0,   39, 0x0000,    0,    4,   35,    4 },  /* 100: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    {   59,    0,   40, 0x0000,    0,    4,    0,    4 },  /* 101: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    {   59,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 102: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    {   60,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 103: F JUMP P S A, B JUMP P S A */
    {   61,    0,   41, 0x0000,    0,    4,   36,    4 },  /* 104: F JUMP P S A, B JUMP P S A */
    {   62,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 105: F JUMP P M A, B JUMP P M A */
    {   63,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 106: F JUMP P M A, B JUMP P M A */
    {   64,    0,   42, 0x0000,    0,    4,   37,    4 },  /* 107: F JUMP P M A, B JUMP P M A */
    {   65,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 108: F JUMP P L A, B JUMP P L A */
    {   66,    0,   43, 0x0000,    0,    4,   38,    4 },  /* 109: F JUMP P L A, B JUMP P L A */
    {   67,    0,   44, 0x0000,    0,    4,   39,    4 },  /* 110: F JUMP P L A, B JUMP P L A */
    {   67,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 111: F JUMP P L A, B JUMP P L A, S V JP S P A */
    {   68,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 112: M PUNCH A */
    {   69,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 113: M PUNCH A */
    {   70,    0,   45, 0x0000,    0,    1,   40,    1 },  /* 114: M PUNCH A */
    {   70,    0,   45, 0x0000,    0,    1,   41,    1 },  /* 115: M PUNCH A */
    {   70,    0,   46, 0x0000,    0,    1,    0,    1 },  /* 116: M PUNCH A */
    {   71,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 117: ATTACK 1 S: not started by a command */
    {   72,    0,   47, 0x0000,    0,    4,   42,    4 },  /* 118: ATTACK 1 S: not started by a command */
    {   46,    0,   48, 0x0000,    0,    1,   43,    1 },  /* 119: KAGAMI K A */
    {   73,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 120: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {   74,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 121: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {   75,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 122: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {   76,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 123: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {   76,    0,   49, 0x0000,    0,    1,    0,    1 },  /* 124: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  174,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 125: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  175,    0,   51, 0x0000,    0,    1,    0,    1 },  /* 126: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  176,    0,   52, 0x0000,    0,    7,    0,    8 },  /* 127: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {   77,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 128: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) */
    {  171,    0,    0, 0x0000,    0,    1,   47,    1 },  /* 129: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) */
    {   78,    0,   55, 0x0000,    0,    1,   48,    1 },  /* 130: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) +1 */
    {   78,    0,   55, 0x0000,    0,    1,    0,    1 },  /* 131: ATTACK 4 S: 623+P light (plain script) */
    {    1,    0,    0, 0x0000,    0,    1,   49,    1 },  /* 132: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,   19 },  /* 133: ATTACK 6 L: after SA II 23623+K (routine Att_PL17_AT1) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 134: follow-up of AIR NORMAL */
    {  183,    0,    0, 0x0000,    2,    1,    0,    1 },  /* 135: TUKAMIKAKARI A */
    {   79,    0,    0, 0x0000,    0,    8,    0,   10 },  /* 136: not used by a script */
    {   79,    0,    0, 0x0000,    0,    9,    0,   10 },  /* 137: not used by a script */
    {   80,    0,   56, 0x0000,    0,    4,   50,    4 },  /* 138: ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1) */
    {   81,    0,   57, 0x0000,    0,    4,   51,    4 },  /* 139: ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1) */
    {   82,    0,   58, 0x0000,    0,   10,   52,   11 },  /* 140: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    {   83,    0,    0, 0x0000,    0,    5,    0,    6 },  /* 141: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   84,    0,   59, 0x0000,    0,    1,   53,    7 },  /* 142: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   84,    0,   60, 0x0000,    0,    1,   54,    7 },  /* 143: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   84,    0,   61, 0x0000,    0,    1,    0,    7 },  /* 144: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   84,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 145: S V JP S P A, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   85,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 146: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   86,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 147: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   87,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 148: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   88,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 149: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   89,    0,   62, 0x0000,    0,    1,   55,    1 },  /* 150: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   89,    0,   63, 0x0000,    0,    1,   56,    1 },  /* 151: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   89,    0,   64, 0x0000,    0,    1,    0,    1 },  /* 152: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   89,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 153: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   90,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 154: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   91,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 155: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   92,    0,   65, 0x0000,    0,    1,   57,    1 },  /* 156: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   92,    0,   66, 0x0000,    0,    1,   58,    1 },  /* 157: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {   92,    0,   66, 0x0000,    0,    1,    0,    1 },  /* 158: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1), ATTACK 13 S: after SA II 23623+K (routine Att_PL17_AT1) */
    {   93,    0,   90, 0x0000,    0,   11,    0,   12 },  /* 159: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +4 */
    {   94,    0,    0, 0x0000,    0,   12,    0,   13 },  /* 160: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +3 */
    {   95,    0,    0, 0x0000,    0,   13,    0,   14 },  /* 161: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) +2 */
    {   96,    0,   67, 0x0000,    0,    1,   59,    1 },  /* 162: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    {   96,    0,   67, 0x0000,    0,    1,   60,    1 },  /* 163: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    {   96,    0,   67, 0x0000,    0,    1,    0,    1 },  /* 164: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    {   96,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 165: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    {   97,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 166: not started by a command, ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI) +6 */
    {   98,    0,    0, 0x1918,    0,    1,    0,    1 },  /* 167: HURIMUKI */
    {   99,    0,    0, 0x1510,    0,    1,    0,    1 },  /* 168: HURIMUKI */
    {  100,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 169: FRONT WALK, BACK WALK */
    {  101,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 170: FRONT WALK, BACK WALK */
    {  102,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 171: FRONT WALK, BACK WALK */
    {  103,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 172: FRONT WALK, BACK WALK */
    {  104,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 173: FRONT WALK, BACK WALK */
    {  105,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 174: FRONT WALK, BACK WALK */
    {  106,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 175: FRONT WALK, BACK WALK */
    {  107,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 176: FRONT WALK, BACK WALK */
    {  108,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 177: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {  109,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 178: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {  110,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 179: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    {  111,    0,    0, 0x1515,    0,    1,    0,   15 },  /* 180: DASH HUMIKOMI, no name */
    {  112,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 181: DASH TOBINOKI, no name */
    {  113,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 182: DASH TOBINOKI */
    {  114,    0,    0, 0x181A,    0,    1,    0,   15 },  /* 183: DASH TOBINOKI */
    {    1,    0,    0, 0x1212,    0,    2,    0,    2 },  /* 184: KAGAMU */
    {  115,    0,    0, 0x1918,    0,    2,    0,    2 },  /* 185: KAGAMI TURN */
    {  116,    0,    0, 0x1414,    0,    2,    0,    2 },  /* 186: KAGAMI TURN */
    {    2,    0,    0, 0x1818,    0,    1,    0,    2 },  /* 187: STAND UP */
    {  117,    0,    0, 0x1810,    0,    4,    0,    4 },  /* 188: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  118,    0,    0, 0x1510,    0,    4,    0,    4 },  /* 189: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    {  119,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 190: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    {  120,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 191: WALK END */
    {  121,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 192: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   61,    1 },  /* 193: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  122,    0,   68, 0x0000,    0,    1,   62,    1 },  /* 194: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  122,    0,   69, 0x0000,    0,    1,    0,    1 },  /* 195: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  123,    0,   70, 0x0000,    0,    1,    0,    1 },  /* 196: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  124,    0,   71, 0x0000,    0,    1,    0,    1 },  /* 197: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  125,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 198: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  126,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 199: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  127,    0,   72, 0x0000,    0,    1,   63,    1 },  /* 200: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  127,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 201: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  127,    0,   73, 0x0000,    0,    1,   64,    1 },  /* 202: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  127,    0,   74, 0x0000,    0,    1,   65,    1 },  /* 203: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  128,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 204: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  129,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 205: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  130,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 206: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  131,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 207: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  132,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 208: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  133,    0,   75, 0x0000,    0,    1,    0,    1 },  /* 209: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  134,    0,    0, 0x0000,    0,    1,   66,    1 },  /* 210: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  134,    0,   76, 0x0000,    0,    1,   67,    1 },  /* 211: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  134,    0,   77, 0x0000,    0,    1,    0,    1 },  /* 212: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  135,    0,   78, 0x0000,    0,    1,    0,    1 },  /* 213: ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  136,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 214: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  137,    0,   79, 0x0000,    0,    1,    0,    1 },  /* 215: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    {  138,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 216: UPPER L */
    {  139,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 217: UPPER L, BODY UPPER L */
    {  140,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 218: BODY UPPER L */
    {  141,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 219: not used by a script */
    {  142,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 220: FACE S, FACE M, FACE L +13 */
    {  143,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 221: FACE M, FACE L, FOOK OKU M +8 */
    {  144,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 222: FOOK OKU L, FOOK OKU SP, FOOK TEMAE SP */
    {  145,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 223: FOOK OKU SP, FOOK TEMAE SP */
    {  146,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 224: NOUTEN M, NOUTEN S, BODY BROW M +2 */
    {  147,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 225: NOUTEN M, BODY BROW M, BODY BROW L */
    {  148,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 226: NOUTEN M, BODY BROW M, BODY BROW L */
    {  149,    0,    0, 0x0000,    0,    1,    0,   18 },  /* 227: BODY BROW L, TATAKI S */
    {  150,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 228: KAGAMI S, KAGAMI L, KGM TATAKI S */
    {  151,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 229: KAGAMI S, KAGAMI L, KGM TATAKI S */
    {  152,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 230: KAGAMI S, KAGAMI L */
    {  153,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 231: KAGAMI L */
    {  154,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 232: ATTACK 7 S: not started by a command */
    {  155,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 233: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  156,    0,   80, 0x0000,    0,    4,   68,    4 },  /* 234: ATTACK 7 S: not started by a command */
    {  156,    0,   81, 0x0000,    0,    4,   69,    4 },  /* 235: ATTACK 7 S: not started by a command */
    {  157,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 236: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  158,    0,   82, 0x0000,    0,    4,   70,    4 },  /* 237: ATTACK 7 S: not started by a command */
    {  158,    0,   82, 0x0000,    0,    4,   71,    4 },  /* 238: ATTACK 7 S: not started by a command */
    {  158,    0,   83, 0x0000,    0,    4,    0,    4 },  /* 239: ATTACK 7 S: not started by a command */
    {  159,    0,   84, 0x0000,    0,    4,    0,    4 },  /* 240: ATTACK 7 S: not started by a command */
    {  160,    0,   84, 0x0000,    0,    4,    0,    4 },  /* 241: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  161,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 242: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  162,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 243: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  163,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 244: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  164,    0,   85, 0x0000,    0,    4,    0,    4 },  /* 245: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  165,    0,   86, 0x0000,    0,    4,    0,    4 },  /* 246: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  165,    0,   87, 0x0000,    0,    4,    0,    4 },  /* 247: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  166,    0,   88, 0x0000,    0,    4,   72,    4 },  /* 248: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  166,    0,   89, 0x0000,    0,    4,   73,    4 },  /* 249: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    {  167,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 250: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  168,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 251: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  169,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 252: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  170,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 253: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  186,    0,    0, 0x0000,    3,   14,    0,   16 },  /* 254: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI) */
    {  186,    0,    0, 0x0000,    4,   14,    0,   16 },  /* 255: ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) */
    {  186,    0,    0, 0x0000,    5,   14,    0,   16 },  /* 256: ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  172,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 257: ATTACK 4 SP: EX 623+PP (plain script) */
    {  173,    0,    0, 0x0000,    0,    1,   74,    1 },  /* 258: ATTACK 4 SP: EX 623+PP (plain script) */
    {  177,    0,    0, 0x0000,    0,    7,   44,    8 },  /* 259: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  178,    0,    0, 0x0000,    0,    7,   45,    9 },  /* 260: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  179,    0,   53, 0x0000,    0,    7,   46,    9 },  /* 261: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  180,    0,   53, 0x0000,    0,    7,    0,    9 },  /* 262: ATTACK 3 S: 214+P light (plain script) */
    {  178,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 263: ATTACK 3 S: 214+P light (plain script) */
    {  181,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 264: ATTACK 3 S: 214+P light (plain script) */
    {  182,    0,    0, 0x0000,    0,    7,    0,    8 },  /* 265: ATTACK 3 S: 214+P light (plain script) */
    {  183,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 266: TUKAMIKAKARI A, ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    {  184,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 267: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  185,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 268: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  186,    0,    0, 0x0000,    0,   14,    0,   16 },  /* 269: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  187,    0,    0, 0x0000,    0,   14,    0,   16 },  /* 270: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  188,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 271: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    {  189,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 272: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    {  190,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 273: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    {  191,    0,   91, 0x0000,    0,    1,    0,    1 },  /* 274: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    {  192,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 275: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    {  193,    0,   92, 0x0000,    0,    1,    0,    1 },  /* 276: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    {  194,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 277: AIR NORMAL, BODY UPPER */
    {  195,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 278: ASIBARAI SIRI, GILL */
    {  196,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 279: ASIBARAI SIRI, GILL */
    {  197,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 280: ASIBARAI SIRI, BODY SLAM */
    {  198,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 281: ASIB TUNNOMERI, HUMI ASIB, FLANKEN.S */
    {  199,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 282: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  200,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 283: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  201,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 284: NOKEZORI, UPPER, HARAYARARE +4 */
    {  202,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 285: NOKEZORI, UPPER, HARAYARARE +4 */
    {  203,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 286: NOKEZORI, UPPER, HARAYARARE +6 */
    {  204,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 287: NOKEZORI, UPPER, HARAYARARE +6 */
    {  205,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 288: NOKEZORI, UPPER, HARAYARARE +6 */
    {  206,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 289: NOKEZORI, UPPER, HARAYARARE +6 */
    {  207,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 290: NOKEZORI, UPPER, HARAYARARE +6 */
    {  208,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 291: NOKEZORI, UPPER, HARAYARARE +5 */
    {  209,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 292: KUNOJI, KUNOJI NOKE */
    {  210,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 293: KUNOJI, KUNOJI NOKE */
    {  211,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 294: KUNOJI */
    {  212,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 295: KIRIMOMI */
    {  213,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 296: KIRIMOMI */
    {  214,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 297: UPPER, TATUMAKIZANKU */
    {  215,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 298: UPPER, TATUMAKIZANKU */
    {  216,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 299: UPPER, HARAYARARE, FACE +2 */
    {  217,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 300: BODY UPPER */
    {  218,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 301: BODY UPPER */
    {  219,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 302: BODY UPPER */
    {  220,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 303: BODY UPPER */
    {  221,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 304: BODY UPPER */
    {  222,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 305: BODY UPPER */
    {  223,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 306: BODY UPPER */
    {  224,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 307: BODY UPPER, TOMOE ORO */
    {  225,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 308: BODY UPPER, TOMOE ORO, GILL */
    {  226,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 309: BODY UPPER, TTKI V. AIR, TOMOE ORO +1 */
    {  227,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 310: HARAYARARE, HANEKAERI HARA */
    {  228,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 311: TTKI V. AIR */
    {  229,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 312: TTKI V. AIR */
    {  230,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 313: TTKI V. AIR, BODY SLAM, TOMOE RYU +2 */
    {  231,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 314: FACE */
    {  232,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 315: DENKI */
    {  233,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 316: TOUKETSU A */
    {  234,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 317: IPPONZEOI */
    {  235,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 318: IPPONZEOI */
    {  236,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 319: TOMOE RYU, MONKEY FLIP */
    {  237,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 320: TOMOE RYU, MONKEY FLIP */
    {  238,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 321: TOMOE RYU, MONKEY FLIP, HARAIGOSHI */
    {  239,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 322: KISHINRIKI */
    {  240,    0,    0, 0x0000,    0,   15,    0,   17 },  /* 323: KISHINRIKI */
    {    5,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 324: ATTACK 1 S: not started by a command */
    {  241,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 325: TUKAMIKAKARI A */
    {  242,    0,   34, 0x0000,    0,    1,    0,    1 },  /* 326: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  243,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 327: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 328: LOSE SONABA, SHIMEOTASARE */
    {  244,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 329: ATTACK 5 S: not started by a command */
    {  245,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 330: ATTACK 5 S: not started by a command */
    {  246,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 331: ATTACK 5 S: not started by a command */
    {  247,    0,    0, 0x1110,    0,    1,    0,    1 },  /* 332: ATTACK 5 S: not started by a command */
    {  248,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 333: ATTACK 5 S: not started by a command */
    {  249,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 334: ATTACK 5 S: not started by a command */
    {  250,    0,    0, 0x1515,    0,    1,    0,   15 },  /* 335: ATTACK 5 S: not started by a command */
    {  251,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 336: ATTACK 5 S: not started by a command */
    {  252,    0,    0, 0x1212,    0,    1,   49,   15 },  /* 337: ATTACK 5 S: not started by a command */
    {  252,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 338: ATTACK 5 S: not started by a command */
    {  253,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 339: ATTACK 5 S: not started by a command */
    {  254,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 340: ATTACK 5 S: not started by a command */
    {  255,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 341: ATTACK 5 S: not started by a command */
    {  256,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 342: ATTACK 5 S: not started by a command */
    {  257,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 343: ATTACK 5 S: not started by a command */
    {  258,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 344: ATTACK 5 S: not started by a command */
    {  259,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 345: ATTACK 5 S: not started by a command */
    {  260,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 346: ATTACK 5 S: not started by a command */
    {  261,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 347: ATTACK 5 S: not started by a command */
    {  262,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 348: ATTACK 5 S: not started by a command */
    {  263,    0,    0, 0x1111,    0,    1,    0,   15 },  /* 349: ATTACK 5 S: not started by a command */
    {  264,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 350: ATTACK 5 S: not started by a command */
    {  265,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 351: ATTACK 5 S: not started by a command */
    {  266,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 352: ATTACK 5 S: not started by a command */
    {  267,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 353: ATTACK 5 S: not started by a command */
    {  268,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 354: ATTACK 5 S: not started by a command */
    {  269,    0,    0, 0x1515,    0,    1,    0,   15 },  /* 355: ATTACK 5 S: not started by a command */
    {  270,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 356: ATTACK 5 S: not started by a command */
    {  271,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 357: ATTACK 5 S: not started by a command */
    {  272,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 358: ATTACK 5 S: not started by a command */
    {  273,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 359: ATTACK 5 S: not started by a command */
};

const BODY_BOX makoto_body_box[274] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -13,  23,  73,  16 },  {  -25,  55,  59,  16 },  {  -30,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +85 */
    { { {  -13,  24,  47,  18 },  {  -23,  54,  40,  13 },  {  -35,  70,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +21 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -27,  54,  39,  45 },  {    0,   0,   0,   0 } } },  /* 3: not used by a script */
    { { {  -13,  23,  89,  16 },  {  -22,  44,  71,  17 },  {  -24,  48,  34,  37 },  {  -26,  52,   0,  33 } } },  /* 4: no name, PIYO */
    { { {  -15,  23,  61,  16 },  {  -25,  58,  48,  16 },  {  -30,  61,  32,  15 },  {  -41,  78,   0,  31 } } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, ATTACK 1 S: not started by a command */
    { { {    0,   0,   0,   0 },  {  -43,  66,  44,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: PARING AIR F, TUKAMIHAZUSI, TUKAMIHAZUSARE +7 */
    { { {  -16,  26,  98,  16 },  {  -27,  52,  91,  13 },  {  -28,  54,  46,  44 },  {  -24,  44,  29,  17 } } },  /* 7: V JUMP K L A, F JUMP K L A, B JUMP K L A +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 8: no name, S V JP S P A */
    { { {  -13,  23,  76,  16 },  {  -30,  48,  55,  23 },  {  -50,  68,  20,  35 },  {  -11,  36,   0,  20 } } },  /* 9: L KICK A */
    { { {  -19,  23,  76,  16 },  {  -36,  57,  68,  11 },  {  -53,  79,  39,  30 },  {  -16,  41,   0,  39 } } },  /* 10: L KICK A, follow-up of M KICK C */
    { { {    6,  23,  67,  16 },  {   -2,  31,  61,  11 },  {  -40,  69,  42,  22 },  {  -16,  45,   0,  43 } } },  /* 11: L KICK A, follow-up of M KICK C */
    { { {   -6,  23,  72,  16 },  {  -32,  61,  61,  11 },  {  -61,  90,  27,  33 },  {   -6,  35,   0,  31 } } },  /* 12: L KICK A, follow-up of M KICK C */
    { { {  -22,  23,  72,  17 },  {  -29,  39,  63,  12 },  {  -30,  53,  32,  31 },  {  -38,  72,   0,  31 } } },  /* 13: S PUNCH A */
    { { {  -25,  23,  74,  17 },  {  -35,  41,  63,  12 },  {  -40,  56,  32,  31 },  {  -52,  94,   0,  31 } } },  /* 14: S PUNCH C */
    { { {  -17,  23,  65,  15 },  {  -24,  39,  54,  12 },  {  -29,  62,  31,  23 },  {  -37, 103,   0,  31 } } },  /* 15: M PUNCH C */
    { { {  -25,  23,  74,  18 },  {  -36,  42,  63,  12 },  {  -47,  59,  32,  31 },  {  -55,  95,   0,  31 } } },  /* 16: L PUNCH A */
    { { {  -27,  23,  72,  18 },  {  -33,  44,  63,  12 },  {  -36,  50,  32,  31 },  {  -51,  89,   0,  31 } } },  /* 17: L PUNCH C */
    { { {  -14,  23,  74,  18 },  {  -27,  54,  63,  12 },  {  -29,  59,  32,  31 },  {  -35,  72,   0,  31 } } },  /* 18: L PUNCH C */
    { { {   -1,  23,  71,  18 },  {  -11,  41,  63,  12 },  {  -31,  63,  32,  31 },  {  -56,  88,   0,  31 } } },  /* 19: L PUNCH C */
    { { {  -25,  23,  66,  18 },  {  -33,  41,  62,  12 },  {  -31,  51,  32,  31 },  {  -37,  93,   0,  31 } } },  /* 20: L PUNCH C, follow-up of L PUNCH C */
    { { {  -30,  23,  76,  18 },  {  -37,  38,  68,  12 },  {  -36,  49,  36,  31 },  {  -40,  79,   0,  36 } } },  /* 21: S KICK A, M KICK A */
    { { {  -19,  23,  86,  15 },  {  -31,  44,  70,  17 },  {  -34,  54,  47,  23 },  {  -27,  39,   0,  47 } } },  /* 22: S KICK A, follow-up of S KICK A, M KICK A */
    { { {  -25,  30,  84,  19 },  {  -32,  48,  75,  17 },  {  -31,  55,  51,  24 },  {  -23,  39,   0,  52 } } },  /* 23: M KICK A, follow-up of S KICK A */
    { { {  -36,  23,  79,  18 },  {  -48,  54,  68,  12 },  {  -48,  59,  37,  31 },  {  -48,  93,   0,  38 } } },  /* 24: M KICK C */
    { { {    1,  23,  80,  18 },  {  -27,  56,  72,  15 },  {  -29,  59,  44,  31 },  {  -29,  60,   0,  44 } } },  /* 25: M KICK C */
    { { {   10,  29,  69,  16 },  {  -13,  62,  63,  14 },  {  -14,  50,  43,  22 },  {  -27,  52,   0,  43 } } },  /* 26: M KICK C */
    { { {   10,  29,  69,  16 },  {  -30,  62,  69,  14 },  {  -43,  78,  43,  28 },  {  -27,  52,   0,  43 } } },  /* 27: M KICK C, follow-up of M KICK C */
    { { {  -36,  26,  52,  18 },  {  -57,  58,  43,  13 },  {  -57,  65,  26,  20 },  {  -56,  98,   0,  30 } } },  /* 28: KAGAMI P A */
    { { {  -23,  26,  53,  18 },  {  -32,  53,  45,  11 },  {  -33,  57,  32,  16 },  {  -47,  95,   0,  34 } } },  /* 29: KAGAMI P A */
    { { {  -37,  26,  50,  18 },  {  -41,  52,  39,  14 },  {  -28,  60,  28,  15 },  {  -35,  99,   0,  29 } } },  /* 30: KAGAMI P A */
    { { {  -43,  26,  47,  18 },  {  -47,  48,  41,  13 },  {  -52,  54,  26,  20 },  {  -51,  93,   0,  30 } } },  /* 31: KAGAMI P A */
    { { {  -57,  26,  43,  18 },  {  -58,  47,  35,  14 },  {  -54,  45,  26,  15 },  {  -54, 100,   0,  30 } } },  /* 32: KAGAMI P A */
    { { {   14,  26,  47,  18 },  {   -7,  58,  41,  13 },  {  -17,  68,  26,  20 },  {  -31,  77,   0,  30 } } },  /* 33: KAGAMI K A */
    { { {   16,  26,  50,  18 },  {    5,  48,  39,  13 },  {  -18,  74,  26,  16 },  {  -37,  85,   0,  32 } } },  /* 34: KAGAMI K A */
    { { {    6,  26,  45,  18 },  {   -6,  50,  38,  13 },  {  -19,  65,  24,  14 },  {  -35,  82,   0,  29 } } },  /* 35: KAGAMI K A */
    { { {    6,  26,  45,  18 },  {   -6,  50,  38,  13 },  {  -19,  65,  24,  14 },  {  -22,  70,   0,  29 } } },  /* 36: KAGAMI K A */
    { { {  -14,  29,  74,  18 },  {  -27,  54,  63,  12 },  {  -43,  71,  32,  31 },  {  -33,  61,   0,  32 } } },  /* 37: S KICK C */
    { { {  -26,  23,  74,  18 },  {  -33,  54,  63,  12 },  {  -35,  59,  32,  31 },  {  -37,  67,   0,  31 } } },  /* 38: L KICK C */
    { { {  -14,  25,  74,  18 },  {  -32,  57,  63,  12 },  {  -41,  73,  32,  31 },  {  -60, 114,   0,  31 } } },  /* 39: L KICK C */
    { { {  -14,  23,  74,  18 },  {  -41,  69,  63,  12 },  {  -40,  70,  40,  24 },  {  -47,  87,   0,  41 } } },  /* 40: L KICK C, follow-up of L KICK C */
    { { {  -11,  29,  71,  18 },  {  -19,  54,  63,  12 },  {  -24,  55,  32,  31 },  {  -32,  58,   0,  31 } } },  /* 41: L KICK C */
    { { {   -8,  26,  50,  18 },  {  -24,  58,  43,  13 },  {  -33,  70,  26,  20 },  {  -46,  96,   0,  30 } } },  /* 42: KAGAMI K A */
    { { {    4,  26,  66,  18 },  {  -22,  52,  58,  15 },  {  -28,  70,  38,  20 },  {  -34, 103,   0,  38 } } },  /* 43: KAGAMI K A */
    { { {   -6,  29,  70,  19 },  {  -31,  58,  62,  20 },  {  -35,  69,  36,  26 },  {  -37, 105,   0,  36 } } },  /* 44: KAGAMI K A */
    { { {   -7,  26,  76,  18 },  {  -25,  58,  67,  21 },  {  -27,  63,  47,  20 },  {  -33,  85,   0,  47 } } },  /* 45: KAGAMI K A */
    { { {    3,  26,  76,  18 },  {  -24,  58,  66,  21 },  {  -26,  63,  47,  20 },  {  -27,  66,   0,  47 } } },  /* 46: KAGAMI K A */
    { { {  -21,  26,  66,  18 },  {  -36,  56,  58,  13 },  {  -40,  66,  38,  20 },  {  -46,  72,   0,  38 } } },  /* 47: KAGAMI K A */
    { { {  -25,  34,  96,  17 },  {  -32,  54,  81,  20 },  {  -37,  64,  39,  49 },  {    0,   0,   0,   0 } } },  /* 48: V JUMP P S A */
    { { {  -42,  34,  92,  17 },  {  -44,  59,  78,  20 },  {  -37,  64,  39,  49 },  {    0,   0,   0,   0 } } },  /* 49: V JUMP P S A */
    { { {  -25,  34,  96,  17 },  {  -32,  54,  81,  20 },  {  -37,  64,  39,  49 },  {    0,   0,   0,   0 } } },  /* 50: V JUMP P M A */
    { { {  -42,  34,  92,  17 },  {  -44,  59,  78,  20 },  {  -37,  64,  39,  49 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P M A */
    { { {  -25,  36, 100,  17 },  {  -33,  53,  81,  22 },  {  -40,  61,  41,  40 },  {    0,   0,   0,   0 } } },  /* 52: V JUMP P L A */
    { { {  -42,  34,  92,  17 },  {  -44,  59,  78,  20 },  {  -37,  64,  39,  49 },  {    0,   0,   0,   0 } } },  /* 53: V JUMP P L A */
    { { {  -27,  29, 100,  17 },  {  -36,  51,  86,  20 },  {  -40,  64,  37,  49 },  {    0,   0,   0,   0 } } },  /* 54: V JUMP K S A, F JUMP K S A, B JUMP K S A */
    { { {  -21,  32,  97,  16 },  {  -22,  51,  85,  16 },  {  -31,  62,  47,  41 },  {    0,   0,   0,   0 } } },  /* 55: V JUMP K S A, F JUMP K S A, B JUMP K S A */
    { { {  -27,  23,  92,  16 },  {  -34,  55,  81,  15 },  {  -45,  65,  37,  45 },  {    0,   0,   0,   0 } } },  /* 56: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    { { {   -8,  26,  98,  15 },  {  -33,  56,  78,  20 },  {  -57,  85,  49,  37 },  {    0,   0,   0,   0 } } },  /* 57: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    { { {  -21,  29,  99,  15 },  {  -37,  56,  84,  19 },  {  -41,  65,  41,  48 },  {    0,   0,   0,   0 } } },  /* 58: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    { { {   -3,  30,  88,  20 },  {   -9,  55,  67,  29 },  {  -48,  74,  54,  39 },  {    0,   0,   0,   0 } } },  /* 59: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    { { {  -39,  38,  91,  19 },  {  -39,  57,  73,  24 },  {  -33,  65,  38,  45 },  {    0,   0,   0,   0 } } },  /* 60: F JUMP P S A, B JUMP P S A */
    { { {  -51,  38,  86,  19 },  {  -49,  55,  76,  22 },  {  -34,  65,  38,  55 },  {    0,   0,   0,   0 } } },  /* 61: F JUMP P S A, B JUMP P S A */
    { { {  -33,  59,  95,  21 },  {  -42,  61,  80,  23 },  {  -29,  65,  34,  51 },  {    0,   0,   0,   0 } } },  /* 62: F JUMP P M A, B JUMP P M A */
    { { {  -39,  38,  91,  19 },  {  -39,  57,  73,  24 },  {  -33,  65,  38,  45 },  {    0,   0,   0,   0 } } },  /* 63: F JUMP P M A, B JUMP P M A */
    { { {  -51,  38,  86,  19 },  {  -49,  55,  76,  22 },  {  -34,  65,  38,  55 },  {    0,   0,   0,   0 } } },  /* 64: F JUMP P M A, B JUMP P M A */
    { { {  -44,  58,  97,  18 },  {  -53,  63,  75,  24 },  {  -42,  70,  44,  49 },  {    0,   0,   0,   0 } } },  /* 65: F JUMP P L A, B JUMP P L A */
    { { {  -55,  35,  70,  31 },  {  -45,  51,  63,  32 },  {  -32,  57,  40,  40 },  {    0,   0,   0,   0 } } },  /* 66: F JUMP P L A, B JUMP P L A */
    { { {    0,   0,   0,   0 },  {  -39,  69,  44,  60 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: F JUMP P L A, B JUMP P L A, S V JP S P A */
    { { {    1,  23,  74,  18 },  {  -10,  54,  63,  12 },  {  -25,  64,  36,  31 },  {  -38,  79,   0,  38 } } },  /* 68: M PUNCH A */
    { { {  -14,  23,  74,  18 },  {  -30,  61,  63,  12 },  {  -46,  68,  32,  31 },  {  -52,  97,   0,  32 } } },  /* 69: M PUNCH A */
    { { {  -28,  23,  74,  15 },  {  -38,  39,  63,  12 },  {  -43,  49,  41,  23 },  {  -59, 103,   0,  41 } } },  /* 70: M PUNCH A */
    { { {  -32,  50,  98,  19 },  {  -41,  64,  78,  20 },  {  -31,  61,  39,  39 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 1 S: not started by a command */
    { { {  -53,  34,  87,  20 },  {  -51,  56,  76,  21 },  {  -37,  64,  39,  52 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 1 S: not started by a command */
    { { {  -24,  23,  63,  16 },  {  -28,  47,  56,  14 },  {  -34,  59,  31,  25 },  {  -41,  73,   0,  31 } } },  /* 73: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -19,  23,  66,  16 },  {  -19,  48,  56,  14 },  {  -30,  60,  34,  22 },  {  -40,  72,   0,  34 } } },  /* 74: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -14,  23,  69,  16 },  {  -19,  49,  59,  18 },  {  -27,  60,  34,  25 },  {  -38,  72,   0,  34 } } },  /* 75: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -14,  23,  76,  16 },  {  -21,  49,  60,  18 },  {  -27,  60,  34,  26 },  {  -38,  72,   0,  34 } } },  /* 76: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -16,  24,  41,  10 },  {  -34,  49,  31,  10 },  {  -34,  58,  15,  16 },  {  -42,  79,   0,  16 } } },  /* 77: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) */
    { { {  -14,  19,  57,  15 },  {   -7,  34,  53,  16 },  {  -20,  53,  34,  19 },  {  -42,  84,   0,  34 } } },  /* 78: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) +1 */
    { { {    0,   0,   0,   0 },  {  -30,  60,  -6,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: not used by a script */
    { { {  -31,  22,  95,  18 },  {  -35,  47,  74,  28 },  {  -40,  69,  50,  34 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1) */
    { { {  -19,  19,  98,  16 },  {  -31,  48,  80,  19 },  {  -41,  70,  48,  35 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1) */
    { { {  -13,  25,  97,  18 },  {  -34,  60,  78,  21 },  {  -51,  76,  50,  38 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    { { {  -40,  23,  76,  18 },  {  -41,  38,  68,  12 },  {  -41,  49,  36,  31 },  {  -48,  83,   0,  36 } } },  /* 83: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -19,  23,  86,  15 },  {  -31,  44,  70,  17 },  {  -34,  54,  47,  23 },  {  -36,  57,   0,  47 } } },  /* 84: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1), S V JP S P A */
    { { {   -8,  26,  50,  18 },  {  -24,  58,  43,  13 },  {  -33,  70,  26,  20 },  {  -46,  96,   0,  30 } } },  /* 85: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {    4,  26,  66,  18 },  {  -22,  52,  58,  15 },  {  -28,  70,  38,  20 },  {  -34, 103,   0,  38 } } },  /* 86: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {   -6,  29,  70,  19 },  {  -31,  58,  62,  20 },  {  -35,  69,  36,  26 },  {  -37, 105,   0,  36 } } },  /* 87: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {   -7,  26,  76,  18 },  {  -25,  58,  67,  21 },  {  -27,  63,  47,  20 },  {  -33,  85,   0,  47 } } },  /* 88: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {    3,  26,  76,  18 },  {  -24,  58,  66,  21 },  {  -26,  63,  47,  20 },  {  -27,  66,   0,  47 } } },  /* 89: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -21,  26,  66,  18 },  {  -36,  56,  58,  13 },  {  -40,  66,  38,  20 },  {  -46,  72,   0,  38 } } },  /* 90: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {   -3,  23,  45,  16 },  {  -19,  56,  35,  14 },  {  -23,  61,  18,  22 },  {  -33,  79,   0,  23 } } },  /* 91: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {   -6,  23,  62,  16 },  {  -33,  57,  55,  14 },  {  -36,  63,  32,  23 },  {  -41,  84,   0,  33 } } },  /* 92: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1), ATTACK 13 S: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {    1,  23,  62,  16 },  {  -11,  62,  52,  18 },  {  -22,  66,  37,  15 },  {  -38,  86,   0,  36 } } },  /* 93: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +4 */
    { { {  -28,  23,  48,  14 },  {  -38,  59,  42,  14 },  {  -44,  67,  30,  14 },  {  -50,  81,   0,  31 } } },  /* 94: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { { {  -49,  23,  56,  14 },  {  -51,  48,  47,  15 },  {  -60,  71,  34,  14 },  {  -65,  96,   0,  39 } } },  /* 95: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -16,  23,  63,  14 },  {  -25,  48,  47,  17 },  {  -28,  55,  34,  14 },  {  -46,  84,   0,  35 } } },  /* 96: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    { { {  -10,  23,  59,  14 },  {  -10,  50,  46,  17 },  {  -25,  63,  32,  15 },  {  -39,  77,   0,  32 } } },  /* 97: not started by a command, ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI) +6 */
    { { {  -19,  23,  73,  16 },  {  -34,  53,  59,  16 },  {  -32,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 98: HURIMUKI */
    { { {  -21,  23,  79,  16 },  {  -31,  45,  59,  20 },  {  -35,  57,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 99: HURIMUKI */
    { { {  -20,  23,  69,  16 },  {  -34,  55,  55,  16 },  {  -36,  61,  31,  22 },  {  -48,  85,   0,  31 } } },  /* 100: FRONT WALK, BACK WALK */
    { { {  -24,  23,  71,  16 },  {  -37,  55,  57,  16 },  {  -32,  61,  34,  22 },  {  -42, 103,   0,  34 } } },  /* 101: FRONT WALK, BACK WALK */
    { { {  -27,  23,  73,  16 },  {  -35,  48,  59,  16 },  {  -33,  49,  32,  26 },  {  -35,  48,   0,  31 } } },  /* 102: FRONT WALK, BACK WALK */
    { { {  -18,  23,  77,  16 },  {  -27,  43,  60,  19 },  {  -22,  41,  32,  26 },  {  -21,  53,   0,  31 } } },  /* 103: FRONT WALK, BACK WALK */
    { { {  -16,  23,  69,  16 },  {  -33,  53,  55,  18 },  {  -39,  63,  34,  20 },  {  -52,  89,   0,  34 } } },  /* 104: FRONT WALK, BACK WALK */
    { { {  -28,  23,  71,  16 },  {  -40,  52,  57,  17 },  {  -32,  61,  34,  22 },  {  -38, 102,   0,  34 } } },  /* 105: FRONT WALK, BACK WALK */
    { { {  -30,  23,  72,  16 },  {  -32,  45,  57,  19 },  {  -36,  53,  32,  24 },  {  -46,  57,   0,  31 } } },  /* 106: FRONT WALK, BACK WALK */
    { { {  -16,  23,  77,  16 },  {  -13,  33,  62,  17 },  {  -19,  39,  31,  29 },  {  -21,  53,   0,  31 } } },  /* 107: FRONT WALK, BACK WALK */
    { { {  -38,  25,  59,  16 },  {  -33,  51,  45,  20 },  {  -44,  70,  26,  18 },  {  -46,  88,   0,  25 } } },  /* 108: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -52,  23,  48,  16 },  {  -29,  44,  46,  17 },  {  -34,  65,  33,  13 },  {  -43, 108,   0,  33 } } },  /* 109: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -47,  23,  48,  16 },  {  -25,  35,  46,  17 },  {  -34,  59,  33,  13 },  {  -52, 109,   0,  33 } } },  /* 110: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -35,  23,  53,  16 },  {  -26,  41,  43,  18 },  {  -34,  54,  29,  16 },  {  -45,  89,   0,  29 } } },  /* 111: DASH HUMIKOMI, no name */
    { { {  -24,  23,  69,  16 },  {  -22,  48,  53,  18 },  {  -28,  56,  30,  22 },  {  -50,  92,   0,  30 } } },  /* 112: DASH TOBINOKI, no name */
    { { {  -34,  23,  62,  16 },  {  -25,  40,  52,  18 },  {  -35,  59,  30,  22 },  {  -55, 106,   0,  30 } } },  /* 113: DASH TOBINOKI */
    { { {  -17,  23,  60,  16 },  {  -20,  40,  52,  18 },  {  -27,  48,  32,  19 },  {  -45,  93,   0,  31 } } },  /* 114: DASH TOBINOKI */
    { { {  -25,  24,  45,  18 },  {  -33,  47,  39,  13 },  {  -35,  61,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 115: KAGAMI TURN */
    { { {  -24,  24,  49,  18 },  {  -30,  44,  40,  13 },  {  -34,  49,  26,  13 },  {  -49,  92,   0,  30 } } },  /* 116: KAGAMI TURN */
    { { {  -16,  23,  98,  16 },  {  -25,  43,  86,  16 },  {  -28,  43,  56,  30 },  {  -30,  39,  43,  13 } } },  /* 117: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    { { {  -38,  23,  82,  18 },  {  -22,  43,  79,  24 },  {  -29,  56,  65,  17 },  {  -37,  54,  51,  17 } } },  /* 118: JUMP FRONT, JUMP VERTICAL, JUMP BACK +7 */
    { { {  -15,  23, 101,  16 },  {  -21,  45,  86,  16 },  {  -27,  43,  56,  30 },  {  -24,  39,  43,  13 } } },  /* 119: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    { { {  -12,  23,  68,  16 },  {  -25,  55,  55,  16 },  {  -30,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 120: WALK END */
    { { {   -5,  23,  66,  16 },  {  -16,  42,  54,  16 },  {  -21,  49,  36,  19 },  {  -33,  63,   0,  37 } } },  /* 121: not used by a script */
    { { {   -9,  23,  64,  16 },  {  -35,  55,  53,  16 },  {  -25,  46,  32,  22 },  {  -37,  66,   0,  33 } } },  /* 122: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -17,  23,  60,  16 },  {  -21,  42,  51,  16 },  {  -26,  58,  31,  29 },  {  -36,  67,   0,  32 } } },  /* 123: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -16,  23,  57,  16 },  {  -14,  37,  49,  16 },  {  -21,  55,  31,  27 },  {  -33,  67,   0,  32 } } },  /* 124: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -11,  23,  64,  16 },  {  -16,  52,  51,  18 },  {  -21,  48,  31,  26 },  {  -33,  61,   0,  32 } } },  /* 125: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -11,  23,  66,  16 },  {  -12,  47,  52,  18 },  {  -18,  44,  31,  24 },  {  -31,  61,   0,  38 } } },  /* 126: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -11,  23,  66,  16 },  {  -20,  47,  52,  18 },  {  -20,  44,  35,  23 },  {  -30,  59,   0,  38 } } },  /* 127: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {   -9,  23,  64,  16 },  {  -17,  43,  52,  16 },  {  -25,  52,  35,  22 },  {  -37,  62,   0,  38 } } },  /* 128: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -10,  23,  60,  16 },  {  -15,  40,  50,  16 },  {  -22,  50,  34,  21 },  {  -38,  65,   0,  40 } } },  /* 129: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {   -7,  23,  55,  16 },  {   -9,  47,  40,  23 },  {  -41,  69,  23,  18 },  {  -68, 102,   0,  25 } } },  /* 130: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {    5,  23,  51,  16 },  {  -10,  55,  35,  16 },  {  -39,  74,  22,  13 },  {  -62, 103,   0,  22 } } },  /* 131: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {    5,  23,  47,  16 },  {   -9,  55,  35,  19 },  {  -39,  74,  21,  14 },  {  -60, 106,   0,  22 } } },  /* 132: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {    7,  23,  57,  16 },  {   -9,  57,  36,  22 },  {  -35,  75,  20,  16 },  {  -55, 106,   0,  22 } } },  /* 133: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {    6,  23,  65,  19 },  {  -11,  38,  47,  28 },  {  -25,  71,  24,  25 },  {  -54, 105,   0,  26 } } },  /* 134: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -13,  23,  73,  16 },  {  -25,  55,  59,  16 },  {  -30,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 135: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -13,  23,  78,  16 },  {  -25,  47,  65,  19 },  {  -32,  60,  36,  29 },  {  -41,  78,   0,  36 } } },  /* 136: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -13,  23,  68,  16 },  {  -25,  55,  55,  20 },  {  -37,  68,  30,  26 },  {  -41,  78,   0,  31 } } },  /* 137: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {    3,  23,  77,  16 },  {  -21,  55,  59,  16 },  {  -31,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 138: UPPER L */
    { { {   11,  23,  76,  16 },  {  -18,  55,  59,  16 },  {  -32,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 139: UPPER L, BODY UPPER L */
    { { {   15,  23,  75,  16 },  {  -16,  55,  59,  16 },  {  -33,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 140: BODY UPPER L */
    { { {   17,  23,  74,  16 },  {  -15,  55,  59,  16 },  {  -34,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 141: not used by a script */
    { { {    3,  23,  71,  16 },  {  -17,  55,  58,  16 },  {  -26,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 142: FACE S, FACE M, FACE L +13 */
    { { {   15,  23,  69,  16 },  {  -11,  55,  57,  16 },  {  -23,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 143: FACE M, FACE L, FOOK OKU M +8 */
    { { {   23,  23,  67,  16 },  {   -7,  55,  56,  16 },  {  -21,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 144: FOOK OKU L, FOOK OKU SP, FOOK TEMAE SP */
    { { {   27,  23,  65,  16 },  {   -5,  55,  55,  16 },  {  -20,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 145: FOOK OKU SP, FOOK TEMAE SP */
    { { {  -17,  23,  70,  16 },  {  -23,  55,  57,  16 },  {  -28,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 146: NOUTEN M, NOUTEN S, BODY BROW M +2 */
    { { {  -21,  23,  67,  16 },  {  -21,  55,  55,  16 },  {  -26,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 147: NOUTEN M, BODY BROW M, BODY BROW L */
    { { {  -25,  23,  64,  16 },  {  -19,  55,  53,  16 },  {  -24,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 148: NOUTEN M, BODY BROW M, BODY BROW L */
    { { {  -29,  23,  61,  16 },  {  -17,  55,  51,  16 },  {  -22,  61,  32,  26 },  {  -41,  78,   0,  31 } } },  /* 149: BODY BROW L, TATAKI S */
    { { {   -7,  24,  47,  18 },  {  -21,  54,  40,  13 },  {  -34,  70,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 150: KAGAMI S, KAGAMI L, KGM TATAKI S */
    { { {   -1,  24,  47,  18 },  {  -19,  54,  40,  13 },  {  -33,  70,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 151: KAGAMI S, KAGAMI L, KGM TATAKI S */
    { { {    5,  24,  47,  18 },  {  -17,  54,  40,  13 },  {  -32,  70,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 152: KAGAMI S, KAGAMI L */
    { { {   11,  24,  47,  18 },  {  -15,  54,  40,  13 },  {  -31,  70,  26,  13 },  {  -43,  85,   0,  25 } } },  /* 153: KAGAMI L */
    { { {  -31,  23,  76,  16 },  {  -36,  39,  61,  23 },  {  -33,  54,  37,  24 },  {  -39,  75,   0,  37 } } },  /* 154: ATTACK 7 S: not started by a command */
    { { {  -29,  24,  97,  16 },  {  -38,  49,  91,  16 },  {  -36,  52,  78,  13 },  {  -36,  56,  48,  30 } } },  /* 155: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -13,  24,  95,  16 },  {  -17,  54,  85,  15 },  {  -26,  53,  74,  13 },  {  -25,  44,  49,  25 } } },  /* 156: ATTACK 7 S: not started by a command */
    { { {  -10,  24,  95,  16 },  {  -35,  60,  85,  18 },  {  -34,  56,  74,  13 },  {  -34,  46,  49,  25 } } },  /* 157: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {   -5,  24,  92,  16 },  {   -1,  43,  69,  27 },  {  -23,  29,  66,  25 },  {  -18,  42,  49,  21 } } },  /* 158: ATTACK 7 S: not started by a command */
    { { {    9,  24,  92,  16 },  {   -3,  43,  69,  33 },  {  -21,  18,  70,  30 },  {  -22,  41,  47,  24 } } },  /* 159: ATTACK 7 S: not started by a command */
    { { {    9,  24,  92,  16 },  {   -3,  43,  69,  33 },  {  -21,  18,  70,  30 },  {  -38,  41,  47,  27 } } },  /* 160: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {   24,  24,  80,  16 },  {  -17,  40,  73,  35 },  {  -18,  61,  60,  20 },  {  -27,  50,  44,  26 } } },  /* 161: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {    8,  24,  81,  16 },  {  -20,  40,  66,  35 },  {  -34,  39,  62,  28 },  {  -36,  50,  44,  26 } } },  /* 162: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {    2,  24,  92,  16 },  {  -26,  57,  77,  24 },  {  -32,  59,  67,  14 },  {  -22,  50,  45,  24 } } },  /* 163: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {   -6,  24,  95,  16 },  {  -26,  57,  77,  24 },  {  -32,  59,  67,  14 },  {  -24,  50,  45,  24 } } },  /* 164: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -14,  24,  95,  16 },  {  -27,  57,  77,  24 },  {  -27,  56,  67,  14 },  {  -24,  50,  45,  24 } } },  /* 165: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {    2,  24,  91,  16 },  {  -11,  46,  68,  31 },  {  -31,  38,  66,  23 },  {  -25,  35,  45,  24 } } },  /* 166: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {   -7,  24, 100,  16 },  {  -18,  46,  79,  24 },  {  -31,  38,  66,  23 },  {  -46,  53,  45,  29 } } },  /* 167: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -24,  24, 100,  16 },  {  -25,  41,  82,  20 },  {  -32,  38,  67,  19 },  {  -36,  48,  43,  29 } } },  /* 168: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -29,  24,  96,  16 },  {  -25,  41,  82,  20 },  {  -26,  38,  67,  15 },  {  -31,  51,  43,  25 } } },  /* 169: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -15,  23, 101,  16 },  {  -21,  45,  86,  16 },  {  -27,  43,  56,  30 },  {  -24,  39,  43,  13 } } },  /* 170: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {    0,   0,   0,   0 },  {  -22,  57,  55,  14 },  {  -25,  63,  32,  23 },  {  -42,  84,   0,  33 } } },  /* 171: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -46,  88,   0,  23 } } },  /* 172: ATTACK 4 SP: EX 623+PP (plain script) */
    { { {    0,   0,   0,   0 },  {  -13,  45,  48,  13 },  {  -28,  67,  32,  15 },  {  -42,  84,   0,  33 } } },  /* 173: ATTACK 4 SP: EX 623+PP (plain script) */
    { { {  -20,  23,  77,  16 },  {  -21,  39,  59,  18 },  {  -32,  58,  34,  25 },  {  -38,  72,   0,  34 } } },  /* 174: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -27,  23,  75,  16 },  {  -27,  38,  59,  18 },  {  -36,  58,  34,  25 },  {  -41,  75,   0,  34 } } },  /* 175: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -36,  23,  67,  16 },  {  -41,  42,  49,  18 },  {  -50,  62,  34,  15 },  {  -53,  85,   0,  34 } } },  /* 176: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -49,  23,  59,  16 },  {  -41,  42,  49,  18 },  {  -51,  62,  34,  15 },  {  -55,  85,   0,  34 } } },  /* 177: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -60,  23,  28,  16 },  {  -50,  30,  18,  31 },  {  -20,  26,  15,  29 },  {  -53,  74,   0,  18 } } },  /* 178: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -61,  23,  18,  16 },  {  -51,  30,  15,  30 },  {  -30,  34,  15,  25 },  {  -53,  78,   0,  17 } } },  /* 179: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -61,  23,  22,  16 },  {  -51,  30,  15,  30 },  {  -30,  34,  15,  25 },  {  -53,  78,   0,  17 } } },  /* 180: ATTACK 3 S: 214+P light (plain script) */
    { { {  -58,  23,  43,  16 },  {  -47,  30,  21,  38 },  {  -18,  24,  20,  32 },  {  -52,  74,   0,  21 } } },  /* 181: ATTACK 3 S: 214+P light (plain script) */
    { { {  -42,  23,  59,  16 },  {  -37,  39,  50,  20 },  {  -45,  63,  32,  18 },  {  -48,  82,   0,  32 } } },  /* 182: ATTACK 3 S: 214+P light (plain script) */
    { { {  -10,  23,  72,  16 },  {  -14,  44,  59,  16 },  {  -30,  61,  31,  27 },  {  -41,  78,   0,  31 } } },  /* 183: TUKAMIKAKARI A, ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) +1 */
    { { {   -3,  23,  72,  16 },  {   -4,  44,  52,  20 },  {  -25,  61,  38,  14 },  {  -39,  78,   0,  38 } } },  /* 184: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {  -19,  23,  68,  16 },  {  -25,  53,  50,  22 },  {  -37,  61,  30,  20 },  {  -43,  78,   0,  31 } } },  /* 185: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {  -47,  23,  61,  16 },  {  -54,  47,  48,  20 },  {  -47,  61,  30,  20 },  {  -54,  88,   0,  31 } } },  /* 186: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {  -36,  23,  61,  16 },  {  -46,  50,  48,  20 },  {  -47,  61,  30,  20 },  {  -54,  88,   0,  31 } } },  /* 187: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {  -23,  23,  57,  16 },  {  -29,  50,  47,  19 },  {  -37,  61,  30,  17 },  {  -44,  76,   0,  30 } } },  /* 188: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { { {  -29,  23,  55,  16 },  {  -19,  46,  48,  21 },  {  -33,  62,  30,  17 },  {  -41,  78,   0,  31 } } },  /* 189: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -41,  23,  63,  16 },  {  -43,  47,  48,  21 },  {  -46,  68,  30,  17 },  {  -49,  87,   0,  31 } } },  /* 190: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -41,  23,  63,  16 },  {  -45,  47,  47,  21 },  {  -46,  68,  30,  17 },  {  -49,  87,   0,  31 } } },  /* 191: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -35,  23,  68,  16 },  {  -43,  47,  51,  25 },  {  -48,  62,  30,  22 },  {  -52,  87,   0,  31 } } },  /* 192: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -17,  23,  73,  16 },  {  -30,  51,  58,  14 },  {  -30,  51,  32,  26 },  {  -44,  78,   0,  33 } } },  /* 193: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {  -36,  51,  55,  18 },  {  -30,  48,  43,  23 },  {  -39,  53,  30,  16 } } },  /* 194: AIR NORMAL, BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -22,  41,  64,  22 },  {  -24,  53,  42,  23 },  {  -20,  54,  27,  15 } } },  /* 195: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {  -33,  25,  36,  34 },  {   -8,  26,  32,  40 },  {   19,  26,  27,  44 } } },  /* 196: ASIBARAI SIRI, GILL */
    { { {    0,   0,   0,   0 },  {  -34,  39,  31,  27 },  {  -20,  42,  42,  26 },  {    0,  50,  54,  28 } } },  /* 197: ASIBARAI SIRI, BODY SLAM */
    { { {    0,   0,   0,   0 },  {  -42,  47,  35,  29 },  {  -28,  42,  29,  27 },  {   -9,  47,  18,  33 } } },  /* 198: ASIB TUNNOMERI, HUMI ASIB, FLANKEN.S */
    { { {    0,   0,   0,   0 },  {  -11,  44,  58,  27 },  {  -34,  49,  43,  28 },  {  -45,  53,  28,  25 } } },  /* 199: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {    0,   0,   0,   0 },  {  -11,  44,  56,  27 },  {  -38,  49,  43,  28 },  {  -53,  53,  29,  25 } } },  /* 200: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {    0,   0,   0,   0 },  {    3,  32,  45,  32 },  {  -29,  32,  42,  32 },  {  -53,  27,  37,  30 } } },  /* 201: NOKEZORI, UPPER, HARAYARARE +4 */
    { { {    0,   0,   0,   0 },  {    3,  32,  41,  32 },  {  -29,  32,  46,  32 },  {  -55,  26,  42,  33 } } },  /* 202: NOKEZORI, UPPER, HARAYARARE +4 */
    { { {    0,   0,   0,   0 },  {  -10,  39,  35,  32 },  {  -29,  35,  46,  34 },  {  -57,  28,  50,  32 } } },  /* 203: NOKEZORI, UPPER, HARAYARARE +6 */
    { { {    0,   0,   0,   0 },  {  -16,  41,  35,  30 },  {  -28,  40,  52,  29 },  {  -49,  39,  60,  32 } } },  /* 204: NOKEZORI, UPPER, HARAYARARE +6 */
    { { {    0,   0,   0,   0 },  {  -22,  43,  34,  27 },  {  -28,  44,  53,  29 },  {  -44,  43,  65,  31 } } },  /* 205: NOKEZORI, UPPER, HARAYARARE +6 */
    { { {    0,   0,   0,   0 },  {  -23,  41,  33,  24 },  {  -30,  47,  57,  25 },  {  -39,  47,  76,  27 } } },  /* 206: NOKEZORI, UPPER, HARAYARARE +6 */
    { { {    0,   0,   0,   0 },  {  -23,  41,  33,  24 },  {  -27,  47,  57,  25 },  {  -29,  47,  82,  23 } } },  /* 207: NOKEZORI, UPPER, HARAYARARE +6 */
    { { {    0,   0,   0,   0 },  {  -23,  41,  26,  25 },  {  -27,  47,  51,  25 },  {  -27,  47,  77,  23 } } },  /* 208: NOKEZORI, UPPER, HARAYARARE +5 */
    { { {    0,   0,   0,   0 },  {  -32,  50,  54,  18 },  {  -28,  49,  37,  22 },  {  -41,  65,  21,  17 } } },  /* 209: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -44,  50,  42,  27 },  {  -38,  55,  32,  27 },  {  -51,  60,  19,  16 } } },  /* 210: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -44,  50,  34,  27 },  {  -38,  55,  24,  27 },  {  -51,  60,  11,  16 } } },  /* 211: KUNOJI */
    { { {    0,   0,   0,   0 },  {  -19,  44,  65,  17 },  {  -30,  56,  44,  21 },  {  -37,  66,  21,  24 } } },  /* 212: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -22,  44,  73,  17 },  {  -27,  54,  47,  26 },  {  -23,  47,  23,  24 } } },  /* 213: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -19,  42,  59,  15 },  {  -34,  58,  41,  19 },  {  -43,  66,  19,  22 } } },  /* 214: UPPER, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -17,  44,  65,  18 },  {  -26,  52,  46,  19 },  {  -30,  55,  20,  26 } } },  /* 215: UPPER, TATUMAKIZANKU */
    { { {    0,   0,   0,   0 },  {  -17,  44,  63,  21 },  {  -29,  50,  49,  19 },  {  -35,  57,  23,  26 } } },  /* 216: UPPER, HARAYARARE, FACE +2 */
    { { {    0,   0,   0,   0 },  {  -30,  50,  58,  15 },  {  -32,  55,  37,  21 },  {  -38,  64,  17,  20 } } },  /* 217: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -22,  36,  48,  32 },  {  -16,  44,  66,  24 },  {  -21,  49,  31,  35 } } },  /* 218: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -25,  36,  48,  32 },  {  -16,  44,  67,  24 },  {  -16,  45,  31,  35 } } },  /* 219: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -30,  36,  50,  32 },  {  -16,  44,  67,  24 },  {  -18,  46,  31,  37 } } },  /* 220: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -40,  38,  53,  32 },  {  -16,  44,  61,  31 },  {  -14,  49,  36,  31 } } },  /* 221: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -38,  38,  56,  31 },  {  -16,  44,  62,  33 },  {   -6,  54,  46,  30 } } },  /* 222: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -37,  38,  57,  31 },  {  -14,  44,  61,  33 },  {    8,  54,  48,  32 } } },  /* 223: BODY UPPER */
    { { {    0,   0,   0,   0 },  {  -39,  32,  57,  31 },  {  -15,  35,  62,  33 },  {   20,  40,  66,  36 } } },  /* 224: BODY UPPER, TOMOE ORO */
    { { {    0,   0,   0,   0 },  {  -40,  32,  29,  31 },  {  -11,  31,  29,  31 },  {   19,  32,  36,  34 } } },  /* 225: BODY UPPER, TOMOE ORO, GILL */
    { { {    0,   0,   0,   0 },  {  -34,  32,  13,  31 },  {  -11,  31,   8,  31 },  {   11,  33,  19,  36 } } },  /* 226: BODY UPPER, TTKI V. AIR, TOMOE ORO +1 */
    { { {    0,   0,   0,   0 },  {  -26,  46,  55,  17 },  {  -37,  56,  38,  20 },  {  -47,  63,  19,  20 } } },  /* 227: HARAYARARE, HANEKAERI HARA */
    { { {    0,   0,   0,   0 },  {  -29,  56,  59,  18 },  {  -32,  59,  38,  21 },  {  -37,  68,  19,  19 } } },  /* 228: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -29,  58,  34,  18 },  {  -28,  59,  37,  22 },  {  -37,  68,  19,  19 } } },  /* 229: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -34,  32,   0,  31 },  {  -11,  31,   4,  31 },  {   11,  33,  12,  36 } } },  /* 230: TTKI V. AIR, BODY SLAM, TOMOE RYU +2 */
    { { {    0,   0,   0,   0 },  {  -19,  42,  59,  15 },  {  -34,  58,  41,  19 },  {  -43,  66,  19,  22 } } },  /* 231: FACE */
    { { {    0,   0,   0,   0 },  {  -23,  50,  74,  17 },  {  -28,  52,  48,  26 },  {  -25,  55,  25,  22 } } },  /* 232: DENKI */
    { { {    0,   0,   0,   0 },  {  -25,  48,  62,  16 },  {  -31,  55,  45,  17 },  {  -38,  63,  22,  23 } } },  /* 233: TOUKETSU A */
    { { {    0,   0,   0,   0 },  {    5,  17,   0,  27 },  {  -19,  24,   0,  28 },  {  -49,  30,   3,  30 } } },  /* 234: IPPONZEOI */
    { { {    0,   0,   0,   0 },  {    4,  26,   0,  26 },  {  -15,  33,   8,  26 },  {  -29,  42,  20,  32 } } },  /* 235: IPPONZEOI */
    { { {    0,   0,   0,   0 },  {  -36,  27,   0,  28 },  {   -9,  23,   0,  32 },  {   14,  35,   0,  29 } } },  /* 236: TOMOE RYU, MONKEY FLIP */
    { { {    0,   0,   0,   0 },  {  -36,  27,   0,  28 },  {   -9,  23,   3,  31 },  {   14,  35,   6,  34 } } },  /* 237: TOMOE RYU, MONKEY FLIP */
    { { {    0,   0,   0,   0 },  {  -24,  50,   0,  18 },  {  -27,  54,  19,  22 },  {  -24,  46,  41,  25 } } },  /* 238: TOMOE RYU, MONKEY FLIP, HARAIGOSHI */
    { { {    0,   0,   0,   0 },  {    8,  25,  36,  34 },  {  -18,  26,  32,  40 },  {  -44,  26,  27,  44 } } },  /* 239: KISHINRIKI */
    { { {    0,   0,   0,   0 },  {   -6,  39,  31,  27 },  {  -21,  42,  42,  26 },  {  -49,  50,  54,  28 } } },  /* 240: KISHINRIKI */
    { { {  -15,  23,  71,  16 },  {  -35,  55,  57,  16 },  {  -36,  56,  31,  26 },  {  -47,  78,   0,  31 } } },  /* 241: TUKAMIKAKARI A */
    { { {  -15,  23,  71,  16 },  {  -35,  49,  57,  16 },  {  -40,  60,  31,  26 },  {  -47,  78,   0,  31 } } },  /* 242: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -16,  23,  65,  16 },  {  -37,  46,  53,  16 },  {  -44,  62,  31,  22 },  {  -44,  74,   0,  32 } } },  /* 243: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -16,  23,  74,  16 },  {  -22,  46,  59,  16 },  {  -32,  59,  32,  26 },  {  -38,  80,   0,  33 } } },  /* 244: ATTACK 5 S: not started by a command */
    { { {  -25,  23,  70,  16 },  {  -21,  40,  58,  16 },  {  -27,  50,  32,  26 },  {  -34,  59,   0,  32 } } },  /* 245: ATTACK 5 S: not started by a command */
    { { {  -19,  23,  62,  16 },  {  -20,  39,  52,  17 },  {  -28,  48,  32,  20 },  {  -35,  62,   0,  32 } } },  /* 246: ATTACK 5 S: not started by a command */
    { { {  -14,  23,  64,  16 },  {  -14,  38,  52,  18 },  {  -26,  47,  32,  21 },  {  -36,  66,   0,  32 } } },  /* 247: ATTACK 5 S: not started by a command */
    { { {  -13,  23,  82,  16 },  {  -16,  39,  62,  23 },  {  -23,  46,  38,  24 },  {  -29,  63,   0,  38 } } },  /* 248: ATTACK 5 S: not started by a command */
    { { {  -13,  23,  83,  16 },  {  -18,  44,  64,  23 },  {  -24,  45,  38,  26 },  {  -30,  64,   0,  38 } } },  /* 249: ATTACK 5 S: not started by a command */
    { { {  -23,  23,  69,  16 },  {  -25,  48,  54,  17 },  {  -32,  54,  35,  19 },  {  -40,  75,   0,  35 } } },  /* 250: ATTACK 5 S: not started by a command */
    { { {  -23,  23,  59,  16 },  {  -22,  49,  46,  21 },  {  -34,  53,  30,  16 },  {  -43,  73,   0,  31 } } },  /* 251: ATTACK 5 S: not started by a command */
    { { {  -25,  23,  57,  16 },  {  -25,  51,  43,  21 },  {  -33,  46,  30,  21 },  {  -43,  73,   0,  31 } } },  /* 252: ATTACK 5 S: not started by a command */
    { { {  -22,  23,  58,  16 },  {  -21,  49,  46,  19 },  {  -32,  48,  30,  16 },  {  -43,  73,   0,  31 } } },  /* 253: ATTACK 5 S: not started by a command */
    { { {  -13,  23,  73,  16 },  {  -15,  47,  54,  22 },  {  -29,  56,  32,  22 },  {  -35,  67,   0,  32 } } },  /* 254: ATTACK 5 S: not started by a command */
    { { {  -20,  23,  80,  16 },  {  -20,  41,  63,  22 },  {  -26,  47,  38,  25 },  {  -29,  63,   0,  38 } } },  /* 255: ATTACK 5 S: not started by a command */
    { { {  -20,  22,  64,  16 },  {  -20,  38,  47,  23 },  {  -34,  54,  30,  17 },  {  -40,  74,   0,  30 } } },  /* 256: ATTACK 5 S: not started by a command */
    { { {  -22,  22,  56,  16 },  {  -23,  40,  38,  26 },  {  -40,  56,  25,  15 },  {  -44,  82,   0,  25 } } },  /* 257: ATTACK 5 S: not started by a command */
    { { {  -22,  22,  57,  16 },  {  -24,  41,  38,  26 },  {  -40,  56,  25,  15 },  {  -44,  82,   0,  25 } } },  /* 258: ATTACK 5 S: not started by a command */
    { { {  -27,  23,  66,  16 },  {  -34,  44,  56,  18 },  {  -30,  49,  32,  24 },  {  -38,  71,   0,  31 } } },  /* 259: ATTACK 5 S: not started by a command */
    { { {  -22,  20,  74,  16 },  {  -31,  40,  56,  24 },  {  -28,  47,  33,  23 },  {  -32,  67,   0,  33 } } },  /* 260: ATTACK 5 S: not started by a command */
    { { {  -12,  20,  78,  16 },  {  -22,  41,  58,  23 },  {  -24,  50,  35,  23 },  {  -29,  61,   0,  35 } } },  /* 261: ATTACK 5 S: not started by a command */
    { { {   -1,  20,  76,  16 },  {  -20,  50,  58,  20 },  {  -22,  53,  35,  23 },  {  -29,  64,   0,  35 } } },  /* 262: ATTACK 5 S: not started by a command */
    { { {   -4,  20,  61,  16 },  {  -22,  38,  51,  18 },  {  -20,  48,  35,  16 },  {  -28,  66,   0,  35 } } },  /* 263: ATTACK 5 S: not started by a command */
    { { {   -9,  20,  79,  16 },  {  -24,  38,  63,  20 },  {  -22,  44,  38,  25 },  {  -34,  66,   0,  38 } } },  /* 264: ATTACK 5 S: not started by a command */
    { { {   -9,  20,  82,  16 },  {  -24,  41,  63,  22 },  {  -22,  44,  38,  25 },  {  -34,  66,   0,  38 } } },  /* 265: ATTACK 5 S: not started by a command */
    { { {    0,  20,  69,  16 },  {  -21,  46,  53,  20 },  {  -20,  46,  36,  17 },  {  -32,  69,   0,  36 } } },  /* 266: ATTACK 5 S: not started by a command */
    { { {    0,  20,  59,  16 },  {  -26,  52,  43,  22 },  {  -19,  58,  26,  18 },  {  -32,  76,   0,  26 } } },  /* 267: ATTACK 5 S: not started by a command */
    { { {    0,  20,  58,  16 },  {  -24,  56,  42,  22 },  {  -17,  58,  26,  16 },  {  -32,  78,   0,  26 } } },  /* 268: ATTACK 5 S: not started by a command */
    { { {    9,  23,  54,  16 },  {  -11,  47,  41,  22 },  {  -17,  57,  28,  14 },  {  -34,  82,   0,  28 } } },  /* 269: ATTACK 5 S: not started by a command */
    { { {    2,  23,  60,  16 },  {  -14,  49,  47,  23 },  {  -14,  55,  32,  14 },  {  -34,  80,   0,  32 } } },  /* 270: ATTACK 5 S: not started by a command */
    { { {  -21,  23,  73,  16 },  {  -31,  47,  59,  16 },  {  -32,  57,  32,  27 },  {  -38,  77,   0,  32 } } },  /* 271: ATTACK 5 S: not started by a command */
    { { {  -24,  23,  76,  16 },  {  -32,  46,  59,  19 },  {  -35,  57,  32,  27 },  {  -38,  77,   0,  32 } } },  /* 272: ATTACK 5 S: not started by a command */
    { { {  -15,  22,  78,  16 },  {  -28,  53,  59,  20 },  {  -32,  58,  32,  27 },  {  -40,  79,   0,  32 } } },  /* 273: ATTACK 5 S: not started by a command */
};

const HAND_BOX makoto_hand_box[93] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -90,  50,  46,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: L KICK A, follow-up of M KICK C */
    { { {  -90,  51,  38,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: L KICK A, follow-up of M KICK C */
    { { {  -90,  51,  43,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: L KICK A, follow-up of M KICK C */
    { { {  -77,  36,  44,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: L KICK A, follow-up of M KICK C */
    { { {  -57,  40,  58,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH A */
    { { {  -56,  38,  53,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S PUNCH A */
    { { {  -78,  47,  59,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: S PUNCH C */
    { { {  -64,  28,  56,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: S PUNCH C */
    { { {  -51,  28,  44,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH C */
    { { {  -50,  34,  47,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH C */
    { { {  -79,  54,  64,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH A */
    { { {  -83,  56,  55,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH C, follow-up of L PUNCH C */
    { { {  -56,  27,  53,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH C, follow-up of L PUNCH C */
    { { {  -58,  27,  45,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: S KICK A */
    { { {  -64,  34,  37,  56 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: not used by a script */
    { { {  -56,  26,  37,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: not used by a script */
    { { {  -49,  19,  45,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: S KICK A, follow-up of S KICK A */
    { { {  -82,  57,  80,  23 },  {  -69,  44,  70,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: M KICK A, follow-up of S KICK A */
    { { {  -78,  90,  60,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: M KICK C */
    { { {  -90,  38,  41,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: KAGAMI P A */
    { { {  -90,  50,  37,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: KAGAMI P A */
    { { {    3,  26,  33,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: KAGAMI P A */
    { { { -109,  55,  13,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {  -74,  68,  49,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI P A */
    { { {  -29,  29,  52,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI P A */
    { { {  -79,  45,  17,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI K A */
    { { {  -82,  89,  34,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI K A */
    { { {  -43,  43,  21,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI K A */
    { { {  -97,  60,  45,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: S KICK C */
    { { {  -85,  58,  10,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L KICK C */
    { { {  -57,  36,   4,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: L KICK C */
    { { {  -57,  47,  76,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI K A */
    { { {  -66,  47,  54,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: KAGAMI K A */
    { { {  -66,  30,  57,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -84,  40,  78,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P M A */
    { { {  -85,  61,  85,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P L A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: no box */
    { { { -104,  47,  40,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP K M A, F JUMP K M A, B JUMP K M A */
    { { { -101,  62,  67,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    { { {  -82,  35,  67,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K L A, F JUMP K L A, B JUMP K L A */
    { { {  -70,  38,  52,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: F JUMP P S A, B JUMP P S A */
    { { {  -70,  38,  52,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: F JUMP P M A, B JUMP P M A */
    { { {  -73,  52,  89,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: F JUMP P L A, B JUMP P L A */
    { { {  -75,  50,  23,  74 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: F JUMP P L A, B JUMP P L A */
    { { {  -72,  46,  43,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: M PUNCH A */
    { { {  -55,  24,  50,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: M PUNCH A */
    { { {  -77,  46,  45,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: ATTACK 1 S: not started by a command */
    { { {  -75,  54,  74,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: KAGAMI K A */
    { { {    9,  30,  77,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    3,  30,  78,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {   -4,  28,  77,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -14,  33,  67,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -67,  23,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    7,  14,  76,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: not used by a script */
    { { {    4,  19,  68,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 4 S: 623+P light (plain script), ATTACK 4 M: 623+P medium (plain script), ATTACK 4 L: 623+P heavy (plain script) +1 */
    { { {  -46,  25,  32,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1) */
    { { {  -55,  22,  40,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1) */
    { { {  -68,  25,  51,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    { { {  -53,  24,  54,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -56,  31,  46,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -46,  27,  57,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -57,  47,  76,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -75,  54,  74,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -66,  47,  54,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -21,  14,  76,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -24,  19,  76,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1), ATTACK 13 S: after SA II 23623+K (routine Att_PL17_AT1) */
    { { {  -58,  38,  51,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI), ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) +4 */
    { { {  -45,  22,  46,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -48,  23,  43,  15 },  {  -66,  26,  35,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -57,  33,  39,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -31,  20,  40,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -41,  30,  46,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -45,  34,  55,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -39,  21,  61,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -13,  19,  56,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -18,  25,  73,  11 },  {  -22,  18,  81,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -27,  19,  84,  22 },  {  -17,  17,  75,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -19,  20,  80,  18 },  {  -31,  21,  65,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -57,  33,  44,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 9 L: SA I 23623+P (plain script), ATTACK 11 SP: after SA I 23623+P (plain script) */
    { { {  -55,  39,  66,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 7 S: not started by a command */
    { { {  -53,  36,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 7 S: not started by a command */
    { { {  -93,  70,  66,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 7 S: not started by a command */
    { { {  -81,  59,  69,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 7 S: not started by a command */
    { { {  -53,  32,  74,  26 },  {  -33,  42,  99,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {   -2,  19, 110,  22 },  {   12,  17, 124,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -22,  17, 101,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -38,  24,  88,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -88,  33,  82,  29 },  {  -67,  55,  73,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -81,  32,  36,  41 },  {  -66,  41,  55,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 7 S: not started by a command, ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) +2 */
    { { {  -39,  28,  52,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +4 */
    { { {  -70,  24,  31,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -54,  25,  31,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
};

const HOSEI_BOX makoto_hos_box[20] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   71 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +107 */
    { {  -25,   50,    0,   49 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +42 */
    { {  -38,   63,    0,   58 } },  /* 3: DASH HUMIKOMI, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { {  -25,   50,   56,   36 } },  /* 4: PARING AIR F, TUKAMIHAZUSI, TUKAMIHAZUSARE +39 */
    { {  -25,   50,    0,   30 } },  /* 5: NEKOROBI S, no name, S V JP S P A */
    { {  -31,   50,    0,   74 } },  /* 6: S KICK A, M KICK A, ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    { {  -25,   50,    0,   80 } },  /* 7: S KICK A, follow-up of S KICK A, M KICK A +2 */
    { {  -41,   52,    0,   62 } },  /* 8: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { {  -41,   52,    0,   41 } },  /* 9: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { {  -25,   50,   -3,   40 } },  /* 10: not used by a script */
    { {  -52,   77,   50,   40 } },  /* 11: ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    { {  -42,   88,    0,   67 } },  /* 12: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +4 */
    { {  -47,   93,    0,   57 } },  /* 13: ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { {  -52,   86,    0,   70 } },  /* 14: ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI), ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) +2 */
    { {  -25,   50,    0,   60 } },  /* 15: JUMP JUNBI, SP JUMP JUNBI, DASH HUMIKOMI +5 */
    { {  -41,   52,    0,   66 } },  /* 16: ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI), ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    { {  -25,   50,   42,   36 } },  /* 17: AIR NORMAL, BODY UPPER, ASIBARAI SIRI +26 */
    { {  -25,   50,    0,   64 } },  /* 18: UPPER L, BODY UPPER L, FACE S +20 */
    { {   -9,   49,   59,   43 } },  /* 19: ATTACK 6 L: after SA II 23623+K (routine Att_PL17_AT1) */
};
