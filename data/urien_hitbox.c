/*
 * URIEN_HITBOX.C  Urien's hit boxes
 *
 * Each of Urien's animation frames names an entry of urien_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX urien_hit_ix_table[243] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +12 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +75 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +34 */
    {    3,    0,    0, 0x0000,    0,    6,    0,    9 },  /* 3: not used by a script */
    {    4,    0,    0, 0x0000,    0,    6,    0,    9 },  /* 4: DASH HUMIKOMI, no name */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 5: S KICK A */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: DASH TOBINOKI */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: DASH HUMIKOMI */
    {    8,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 8: GUARD AIR, V JUMP P M A, V JUMP P L A +6 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 9: ATTACK 8 M: not started by a command */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 10: not used by a script */
    {   11,    0,    2, 0x0000,    0,    1,    1,    1 },  /* 11: S PUNCH A */
    {   11,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 12: S PUNCH A */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 13: L PUNCH A */
    {   12,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 14: not used by a script */
    {   96,    0,   28, 0x0000,    0,    1,    3,    1 },  /* 15: not used by a script */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 16: not used by a script */
    {   19,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 17: S KICK A */
    {   19,    0,    8, 0x0000,    0,    1,    7,    1 },  /* 18: S KICK A */
    {   21,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 19: M KICK A */
    {   22,    0,   10, 0x0000,    0,    1,    8,    1 },  /* 20: not used by a script */
    {   22,    0,   10, 0x0000,    0,    1,    9,    1 },  /* 21: M KICK A */
    {   22,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 22: M KICK A */
    {   23,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: L KICK A */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 24: L KICK A */
    {   88,    0,   25, 0x0000,    0,    1,   38,    1 },  /* 25: L KICK A */
    {   25,    0,   11, 0x0000,    0,    1,   39,    1 },  /* 26: L KICK A */
    {   26,    0,   12, 0x0000,    0,    1,   40,    1 },  /* 27: L KICK A */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 28: L KICK A */
    {   31,    0,   13, 0x0000,    0,    5,   13,    2 },  /* 29: KAGAMI P A */
    {   31,    0,   13, 0x0000,    0,    5,    0,    2 },  /* 30: KAGAMI P A */
    {   33,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 31: KAGAMI P A, no name */
    {   34,    0,   15, 0x0000,    0,    5,   15,    2 },  /* 32: KAGAMI K A */
    {   34,    0,   15, 0x0000,    0,    2,   41,    2 },  /* 33: KAGAMI K A */
    {   29,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 34: not used by a script */
    {   30,    0,    0, 0x0000,    0,    1,   12,    5 },  /* 35: not used by a script */
    {   30,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 36: not used by a script */
    {    2,    0,   13, 0x0000,    0,    2,   54,    2 },  /* 37: KAGAMI P A */
    {   32,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 38: KAGAMI P A, no name */
    {   32,    0,    0, 0x0000,    0,    2,   14,    2 },  /* 39: KAGAMI P A, no name */
    {   33,    0,   43, 0x0000,    0,    1,   11,    1 },  /* 40: KAGAMI P A, no name */
    {   34,    0,   15, 0x0000,    0,    5,    0,    2 },  /* 41: KAGAMI P A, KAGAMI K A */
    {   35,    0,   16, 0x0000,    0,    2,   42,    2 },  /* 42: KAGAMI K A */
    {   35,    0,   16, 0x0000,    0,    2,    0,    2 },  /* 43: KAGAMI K A */
    {   89,    0,   26, 0x0000,    0,    3,   44,    3 },  /* 44: V JUMP P L A */
    {   89,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 45: V JUMP P L A */
    {   89,    0,   26, 0x0000,    0,    3,   16,    3 },  /* 46: V JUMP P L A */
    {   87,    0,   24, 0x0000,    0,    3,   18,    3 },  /* 47: V JUMP P M A */
    {   86,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 48: V JUMP P M A, V JUMP P L A */
    {   87,    0,   24, 0x0000,    0,    3,   43,    3 },  /* 49: V JUMP P M A */
    {   87,    0,   24, 0x0000,    0,    3,    0,    3 },  /* 50: V JUMP P M A */
    {   49,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 51: V JUMP K S A, V JUMP K M A */
    {   49,    0,    0, 0x0000,    0,    3,   19,    3 },  /* 52: V JUMP K S A */
    {   40,    0,   19, 0x0000,    0,    3,   21,    3 },  /* 53: V JUMP K M A */
    {   40,    0,   19, 0x0000,    0,    3,   22,    3 },  /* 54: V JUMP K M A, ATTACK 4 M: not started by a command */
    {   91,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 55: JUMP FRONT, JUMP VERTICAL, JUMP BACK +5 */
    {   92,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 56: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    {   93,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 57: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 4 M: not started by a command */
    {   94,    0,   27, 0x0000,    0,    3,   45,    3 },  /* 58: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    {   90,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 59: FRONT WALK, BACK WALK */
    {   47,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 60: V JUMP P S A, V JUMP P M A, V JUMP P L A +4 */
    {   48,    0,    0, 0x0000,    0,    3,   17,    3 },  /* 61: V JUMP P S A */
    {   52,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 62: follow-up of APPEAR JUNBI 6 */
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
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 75: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    {   64,    0,    0, 0x0000,    0,    4,    0,    1 },  /* 77: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    {   65,    0,    0, 0x0000,    0,    4,    0,    1 },  /* 78: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    {   66,    0,    0, 0x0000,    0,    4,    0,    1 },  /* 79: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    {   67,    0,    0, 0x0000,    0,    4,    0,    1 },  /* 80: not used by a script */
    {   68,    0,    0, 0x0000,    0,    4,    0,    1 },  /* 81: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 82: NEKOROBI S, OKIAGARI, OKIAGARI F +10 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 83: follow-up of AIR NORMAL */
    {   69,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 84: not used by a script */
    {   70,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: PIYO */
    {   71,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 86: not used by a script */
    {   72,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 87: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    {   73,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 88: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   74,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 89: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {   75,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 90: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {   75,    0,    0, 0x0000,    0,    3,   31,    3 },  /* 91: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {   76,    0,    0, 0x0000,    0,    3,   32,    3 },  /* 92: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2) */
    {   76,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 93: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {   77,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 94: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {   78,    0,    0, 0x0000,    0,    0,   33,    0 },  /* 95: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 96: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   80,    0,   23, 0x0000,    0,    1,   34,    1 },  /* 97: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   81,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 98: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   82,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 99: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   83,    0,    0, 0x0000,    0,    8,   35,   12 },  /* 100: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) */
    {   83,    0,    0, 0x0000,    0,    8,    0,   12 },  /* 101: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    {   84,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: not used by a script */
    {   85,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 103: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 104: follow-up of APPEAR 2 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 105: follow-up of APPEAR 2 */
    {   14,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 106: M PUNCH A, follow-up of S PUNCH A */
    {   14,    0,    5, 0x0000,    0,    1,   37,    1 },  /* 107: M PUNCH A, follow-up of S PUNCH A */
    {   14,    0,    5, 0x0000,    0,    1,   37,    1 },  /* 108: M PUNCH A, follow-up of S PUNCH A */
    {   15,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 109: L PUNCH A, follow-up of M PUNCH C */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 110: L PUNCH A, follow-up of M PUNCH C */
    {   17,    0,    7, 0x0000,    0,    1,    5,    1 },  /* 111: L PUNCH A */
    {   17,    0,    6, 0x0000,    0,    1,    6,    1 },  /* 112: L PUNCH A, follow-up of M PUNCH C */
    {   17,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 113: L PUNCH A, follow-up of M PUNCH C */
    {   41,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   42,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 115: V JUMP K L A */
    {   40,    0,   19, 0x0000,    0,    3,    0,    3 },  /* 116: V JUMP K M A */
    {   43,    0,   20, 0x0000,    0,    3,   23,    3 },  /* 117: V JUMP K L A */
    {   43,    0,   20, 0x0000,    0,    3,    0,    3 },  /* 118: V JUMP K L A */
    {   44,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 119: V JUMP K L A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 120: not used by a script */
    {   78,    0,    0, 0x0000,    0,    0,   33,    1 },  /* 121: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 122: PARING AIR F, GUARD AIR, P BREAK AIR F +1 */
    {    2,    0,    0, 0x0000,    0,    2,    0,   10 },  /* 123: KAGAMI P A */
    {   97,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 124: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {   97,    0,    0, 0x0000,    0,    1,   49,    1 },  /* 125: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   97,    0,   29, 0x0000,    0,    1,   49,    1 },  /* 126: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {   98,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 127: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    5,    0,    1, 0x0000,    0,    1,   47,    1 },  /* 128: M KICK C */
    {    5,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 129: M KICK C */
    {    5,    0,   30, 0x0000,    0,    1,    0,    1 },  /* 130: M KICK C */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 131: M KICK C */
    {  100,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 132: BODY SLAM, TOMOE RYU, MONKEY FLIP +6 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 133: ATTACK 10 L: SA III 23623+P light (plain script), ATTACK 10 SP: SA III 23623+P medium (plain script), ATTACK 11 S: SA III 23623+P heavy (plain script) +3 */
    {    2,    0,    0, 0x0000,    0,    2,   48,    2 },  /* 134: ATTACK 8 SP: not started by a command */
    {  101,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 135: no name */
    {    0,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 136: ATTACK 10 M: EX [4]6+KK (routine Att_CHOUCHUURENGEKI) */
    {   97,    0,    0, 0x0000,    0,    1,   46,    1 },  /* 137: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    {  102,    0,    0, 0x0000,    0,    8,   50,   12 },  /* 138: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    {   24,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 139: L KICK A */
    {  103,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 140: V JUMP K L A */
    {   92,    0,    0, 0x0000,    0,    3,    0,   13 },  /* 141: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +5 */
    {    8,    0,    0, 0x0000,    0,    3,    0,   13 },  /* 142: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    {  104,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 143: UPPER L */
    {  105,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 144: UPPER L */
    {  106,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 145: UPPER L */
    {  107,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 146: UPPER L */
    {  108,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 147: FACE S, FACE M, FOOK OKU L +4 */
    {  109,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 148: FACE M, FACE L, FOOK OKU L +4 */
    {  110,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 149: FACE L, FOOK OKU L, FOOK OKU SP +1 */
    {  111,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 150: FACE L, FOOK OKU SP */
    {  112,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 151: NOUTEN S, BODY BROW M, BODY BROW L +8 */
    {  113,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 152: BODY BROW M, BODY BROW L */
    {  114,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 153: not used by a script */
    {  115,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 154: not used by a script */
    {  116,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 155: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    {  117,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 156: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    {  118,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 157: KAGAMI L */
    {  119,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 158: KAGAMI L */
    {  120,    0,   32, 0x0000,    0,    1,    0,    1 },  /* 159: L PUNCH C, follow-up of M PUNCH C */
    {  121,    0,   33, 0x0000,    0,    1,    0,    1 },  /* 160: L PUNCH C, follow-up of M PUNCH C */
    {  122,    0,   34, 0x0000,    0,    1,    0,    1 },  /* 161: L PUNCH C, follow-up of M PUNCH C */
    {  123,    0,   35, 0x0000,    0,    1,    0,    1 },  /* 162: L PUNCH C, follow-up of M PUNCH C */
    {  123,    0,   36, 0x0000,    0,    1,   51,    1 },  /* 163: L PUNCH C, follow-up of M PUNCH C */
    {  123,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 164: L PUNCH C, follow-up of M PUNCH C */
    {  124,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 165: L PUNCH C, follow-up of M PUNCH C */
    {  125,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 166: L PUNCH C, follow-up of M PUNCH C */
    {    7,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 167: not used by a script */
    {  126,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 168: M PUNCH C */
    {  127,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 169: M PUNCH C */
    {  126,    0,   39, 0x0000,    0,    1,   52,    1 },  /* 170: M PUNCH C */
    {  126,    0,   40, 0x0000,    0,    1,    0,    1 },  /* 171: M PUNCH C */
    {  126,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 172: M PUNCH C */
    {  126,    0,   42, 0x0000,    0,    1,    0,    1 },  /* 173: M PUNCH C */
    {  128,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 174: M PUNCH C */
    {  129,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 175: KAGAMI P A */
    {  130,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 176: AIR NORMAL, ASIB TUNNOMERI, HUMI ASIB */
    {  131,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 177: AIR NORMAL, ASIB TUNNOMERI, NOKEZORI +7 */
    {  132,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 178: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  133,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 179: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  134,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 180: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    {  135,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 181: ASIBARAI SIRI, KUNOJI, HARAYARARE */
    {  136,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 182: ASIB TUNNOMERI, HUMI ASIB */
    {  137,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 183: ASIB TUNNOMERI, HUMI ASIB */
    {  138,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 184: ASIB TUNNOMERI, HUMI ASIB */
    {  139,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 185: ASIB TUNNOMERI, HUMI ASIB */
    {  140,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 186: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  141,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 187: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  142,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 188: NOKEZORI, KIRIMOMI, UPPER +3 */
    {  143,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 189: NOKEZORI, KIRIMOMI, UPPER +4 */
    {  144,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 190: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  145,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 191: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  146,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 192: NOKEZORI, KIRIMOMI, UPPER +5 */
    {  147,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 193: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    {  148,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 194: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    {  149,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 195: DENKI */
    {  150,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 196: not used by a script */
    {  151,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 197: not used by a script */
    {  152,    0,    0, 0x0000,    0,    7,    0,   11 },  /* 198: TOUKETSU A */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 199: ATTACK 7 M: not started by a command */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 200: KAMAE */
    {  153,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 201: KAMAE */
    {  153,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 202: KAMAE */
    {  154,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 203: HURIMUKI */
    {  155,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 204: FRONT WALK */
    {  156,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 205: FRONT WALK */
    {  157,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 206: FRONT WALK */
    {  158,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 207: FRONT WALK */
    {  159,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 208: FRONT WALK */
    {  160,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 209: BACK WALK */
    {  161,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 210: BACK WALK */
    {  162,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 211: BACK WALK */
    {  163,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 212: BACK WALK */
    {  164,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 213: BACK WALK */
    {  165,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 214: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +1 */
    {  166,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 215: DASH HUMIKOMI */
    {  167,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 216: DASH HUMIKOMI */
    {  168,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 217: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    {  169,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 218: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    {  170,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 219: DASH TOBINOKI, KAGAMU */
    {  171,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 220: DASH TOBINOKI */
    {  172,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 221: DASH TOBINOKI */
    {  174,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 222: KAGAMI KAMAE */
    {  174,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 223: KAGAMI KAMAE */
    {  175,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 224: KAGAMI KAMAE */
    {  175,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 225: KAGAMI KAMAE */
    {  177,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 226: KAGAMI TURN */
    {  178,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 227: KAGAMI TURN */
    {  179,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 228: JUMP JUNBI */
    {  180,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 229: SP JUMP JUNBI */
    {   92,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 230: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  181,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 231: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  182,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 232: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  182,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 233: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
    {   70,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 234: PIYO */
    {  176,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 235: PIYO */
    {  176,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 236: PIYO */
    {  173,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 237: DASH TOBINOKI */
    {   33,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 238: KAGAMI P A */
    {   31,    0,   13, 0x0000,    0,    2,   10,    2 },  /* 239: KAGAMI P A */
    {    4,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 240: DASH HUMIKOMI */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 241: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
    {    0,    0,    0, 0x0000,    0,    0,   46,    1 },  /* 242: ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
};

const BODY_BOX urien_body_box[183] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -21,  27, 102,  18 },  {  -35,  65,  79,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +78 */
    { { {  -12,  32,  54,  18 },  {  -32,  70,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +34 */
    { { {  -50,  22,  92,  18 },  {  -38,  60,  94,  12 },  {  -32,  60,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 3: not used by a script */
    { { {  -34,  22,  86,  18 },  {  -28,  59,  75,  22 },  {  -28,  57,  41,  33 },  {  -32,  72,   0,  40 } } },  /* 4: DASH HUMIKOMI, no name */
    { { {  -10,  34,  96,  18 },  {  -58,  92,  70,  26 },  {  -41,  64,  48,  26 },  {  -36,  64,   0,  48 } } },  /* 5: M KICK C */
    { { {   -2,  22, 113,  18 },  {  -18,  60,  94,  19 },  {  -23,  62,  51,  43 },  {  -32,  72,   0,  50 } } },  /* 6: DASH TOBINOKI */
    { { {  -22,  22,  90,  18 },  {  -26,  64,  72,  22 },  {  -26,  66,  41,  30 },  {  -32,  72,   0,  40 } } },  /* 7: DASH HUMIKOMI, ATTACK 7 M: not started by a command */
    { { {  -11,  24, 125,  18 },  {  -29,  68, 106,  30 },  {  -29,  54,  64,  42 },  {  -24,  54,  28,  36 } } },  /* 8: GUARD AIR, V JUMP P M A, V JUMP P L A +15 */
    { { {  -34,  40, 105,  18 },  {  -45,  75,  92,  16 },  {  -50,  75,  50,  42 },  {  -36,  64,   0,  50 } } },  /* 9: M KICK C */
    { { {  -48,  22,  92,  18 },  {  -28,  56,  88,  28 },  {  -32,  60,  50,  38 },  {    0,   0,   0,   0 } } },  /* 10: not used by a script */
    { { {  -18,  24, 102,  18 },  {  -39,  71,  92,  14 },  {  -31,  56,  50,  42 },  {  -31,  65,   0,  50 } } },  /* 11: S PUNCH A */
    { { {  -22,  24,  94,  18 },  {  -36,  71,  82,  19 },  {  -28,  56,  46,  36 },  {  -34,  82,   0,  46 } } },  /* 12: not used by a script */
    { { {  -22,  42,  92,  20 },  {  -36,  76,  79,  18 },  {  -29,  58,  46,  42 },  {  -36,  80,   0,  46 } } },  /* 13: L PUNCH A */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 14: M PUNCH A, follow-up of S PUNCH A */
    { { {   -3,  24, 100,  18 },  {  -32,  76,  90,  17 },  {  -24,  58,  52,  38 },  {  -34,  70,   0,  52 } } },  /* 15: L PUNCH A, follow-up of M PUNCH C */
    { { {  -48,  48, 100,  22 },  {  -44,  71,  88,  15 },  {  -38,  57,  48,  41 },  {  -43,  84,   0,  48 } } },  /* 16: L PUNCH A, follow-up of M PUNCH C */
    { { {  -34,  60,  80,  28 },  {  -50,  72,  54,  27 },  {  -34,  62,  40,  24 },  {  -46,  96,   0,  40 } } },  /* 17: L PUNCH A, follow-up of M PUNCH C */
    { { {  -10,  22, 102,  18 },  {  -32,  64,  94,  12 },  {  -32,  64,  41,  52 },  {  -32,  72,   0,  40 } } },  /* 18: not used by a script */
    { { {  -35,  24,  99,  18 },  {  -50,  74,  88,  16 },  {  -44,  56,  48,  40 },  {  -60,  68,   0,  48 } } },  /* 19: S KICK A */
    { { {  -15,  19, 103,  16 },  {  -27,  51,  94,  12 },  {  -20,  30,  41,  52 },  {  -22,  41,   0,  40 } } },  /* 20: not used by a script */
    { { {  -16,  40,  94,  21 },  {  -42,  73,  86,  19 },  {  -36,  63,  52,  38 },  {  -27,  40,   0,  52 } } },  /* 21: M KICK A */
    { { {  -32,  58,  94,  21 },  {  -58,  93,  70,  24 },  {  -36,  43,  50,  26 },  {  -27,  40,   0,  50 } } },  /* 22: M KICK A */
    { { {  -12,  24, 106,  18 },  {  -24,  68,  92,  15 },  {  -22,  50,  52,  40 },  {  -34,  62,   0,  52 } } },  /* 23: L KICK A */
    { { {   -3,  24, 108,  18 },  {  -26,  72,  94,  16 },  {  -32,  70,  58,  36 },  {  -14,  38,   0,  58 } } },  /* 24: L KICK A */
    { { {    3,  24, 103,  18 },  {  -20,  69,  90,  17 },  {  -44,  76,  56,  34 },  {  -14,  38,   0,  56 } } },  /* 25: L KICK A */
    { { {   12,  24,  96,  18 },  {  -16,  70,  84,  16 },  {  -30,  78,  60,  24 },  {  -24,  48,   0,  60 } } },  /* 26: L KICK A */
    { { {    1,  41,  94,  18 },  {  -26,  85,  66,  30 },  {  -50,  73,  36,  32 },  {  -26,  50,   0,  40 } } },  /* 27: L KICK A */
    { { {   20,  22,  96,  18 },  {  -12,  72,  78,  24 },  {  -36,  80,  41,  36 },  {  -16,  48,   0,  40 } } },  /* 28: not used by a script */
    { { {   -8,  22, 106,  18 },  {  -24,  60,  94,  12 },  {  -24,  60,  41,  52 },  {  -12,  48,   0,  40 } } },  /* 29: not used by a script */
    { { {  -30,  22, 108,  18 },  {  -16,  56, 100,  28 },  {  -24,  64,  48,  52 },  {    0,   0,   0,   0 } } },  /* 30: not used by a script */
    { { {  -24,  32,  54,  18 },  {  -44,  70,  44,  14 },  {  -40,  84,  22,  24 },  {  -40,  80,   0,  22 } } },  /* 31: KAGAMI P A */
    { { {  -22,  26,  74,  18 },  {  -40,  66,  58,  20 },  {  -48,  78,  34,  24 },  {  -48,  92,   0,  34 } } },  /* 32: KAGAMI P A, no name */
    { { {  -15,  24, 103,  18 },  {  -28,  60,  88,  18 },  {  -30,  58,  34,  54 },  {  -38,  82,   0,  34 } } },  /* 33: KAGAMI P A, no name */
    { { {  -18,  46,  52,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 34: KAGAMI K A, KAGAMI P A */
    { { {  -18,  46,  50,  18 },  {  -36,  74,  44,  14 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 35: KAGAMI K A */
    { { {  -18,  19, 107,  16 },  {  -24,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 36: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -46,  19,  93,  16 },  {  -27,  46,  88,  21 },  {  -22,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 39: not used by a script */
    { { {   -3,  40, 110,  16 },  {  -24,  68,  88,  27 },  {  -36,  82,  62,  34 },  {  -14,  48,  48,  22 } } },  /* 40: V JUMP K M A, ATTACK 4 M: not started by a command */
    { { {   -7,  24, 116,  18 },  {  -35,  69, 102,  21 },  {  -31,  62,  76,  26 },  {  -28,  57,  42,  34 } } },  /* 41: V JUMP K L A */
    { { {  -17,  24, 113,  18 },  {  -29,  62, 102,  20 },  {  -47,  76,  81,  26 },  {  -41,  77,  54,  27 } } },  /* 42: V JUMP K L A */
    { { {  -39,  24, 111,  18 },  {  -26,  58, 102,  23 },  {  -51,  86,  78,  27 },  {  -58,  96,  60,  28 } } },  /* 43: V JUMP K L A */
    { { {  -38,  28, 115,  18 },  {  -34,  63, 104,  18 },  {  -48,  77,  75,  29 },  {  -61,  85,  52,  40 } } },  /* 44: V JUMP K L A */
    { { {   -8,  19, 115,  16 },  {  -17,  46,  98,  21 },  {  -13,  30,  49,  46 },  {    0,   0,   0,   0 } } },  /* 45: not used by a script */
    { { {  -32,  16, 106,  16 },  {  -23,  46,  96,  21 },  {  -16,  30,  57,  46 },  {    0,   0,   0,   0 } } },  /* 46: not used by a script */
    { { {  -25,  24, 118,  18 },  {  -39,  71, 106,  20 },  {  -35,  62,  78,  28 },  {  -38,  63,  48,  30 } } },  /* 47: V JUMP P S A, V JUMP P M A, V JUMP P L A +4 */
    { { {  -40,  24, 108,  18 },  {  -48,  72,  98,  14 },  {  -52,  86,  72,  24 },  {  -32,  60,  48,  26 } } },  /* 48: V JUMP P S A */
    { { {   -4,  40, 109,  16 },  {  -28,  67,  88,  25 },  {  -40,  86,  62,  26 },  {  -24,  57,  50,  18 } } },  /* 49: V JUMP K S A, V JUMP K M A */
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
    { { {   -8,  24,  94,  18 },  {  -35,  71,  90,  15 },  {  -32,  60,  50,  40 },  {  -67, 108,   0,  50 } } },  /* 62: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    { { {  -28,  62,  82,  18 },  {  -55,  93,  62,  18 },  {  -34,  71,  42,  28 },  {  -71, 116,   0,  44 } } },  /* 63: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    { { {   -9,  57,  82,  18 },  {  -19,  68,  69,  14 },  {  -23,  67,  40,  28 },  {  -71, 116,   0,  44 } } },  /* 64: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    { { {  -44,  75,  82,  18 },  {  -39,  78,  68,  17 },  {  -30,  65,  40,  28 },  {  -69, 114,   0,  44 } } },  /* 65: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +3 */
    { { {  -26,  24,  98,  18 },  {  -44,  72,  88,  16 },  {  -32,  52,  52,  38 },  {  -54,  94,   0,  50 } } },  /* 66: ATTACK 3 M: 236+P light (plain script), ATTACK 3 L: 236+P medium (plain script), ATTACK 3 SP: 236+P heavy (plain script) +2 */
    { { {  -28,  62,  85,  18 },  {  -50,  87,  75,  20 },  {  -34,  71,  44,  34 },  {  -71, 116,   0,  44 } } },  /* 67: not used by a script */
    { { {  -28,  62,  82,  20 },  {  -42,  33,  92,  17 },  {  -34,  71,  44,  38 },  {  -71, 116,   0,  44 } } },  /* 68: not used by a script */
    { { {  -36,  22, 104,  18 },  {  -28,  56,  82,  28 },  {  -48,  64,  48,  34 },  {    0,   0,   0,   0 } } },  /* 69: not used by a script */
    { { {  -11,  30, 102,  18 },  {  -30,  68,  85,  22 },  {  -30,  65,  41,  43 },  {  -32,  72,   0,  40 } } },  /* 70: PIYO */
    { { {  -29,  33, 102,  18 },  {  -37,  63,  94,  12 },  {  -37,  65,  41,  52 },  {  -36,  74,   0,  40 } } },  /* 71: not used by a script */
    { { {  -26,  22,  84,  18 },  {  -32,  58,  82,  12 },  {  -24,  50,  40,  40 },  {  -36,  72,   0,  40 } } },  /* 72: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    { { {   14,  22, 126,  18 },  {  -18,  58, 120,  15 },  {  -22,  50,  80,  40 },  {  -13,  53,  50,  29 } } },  /* 73: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {    0,   0,   0,   0 },  {  -36,  64,  92,  32 },  {  -36,  64,  58,  34 },  {    0,   0,   0,   0 } } },  /* 74: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -14,  22, 110,  18 },  {  -32,  56, 104,  16 },  {  -20,  42,  72,  30 },  {  -31,  63,  54,  32 } } },  /* 75: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {    0,   0,   0,   0 },  {  -50,  64,  94,  20 },  {  -36,  51,  72,  21 },  {  -46,  60,  56,  24 } } },  /* 76: ATTACK 2 S: EX [2](789)+KK (routine Att_MOONSALT_KNEE_DROP2), no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -38,  22, 106,  18 },  {  -34,  58,  94,  20 },  {  -18,  36,  72,  24 },  {  -38,  50,  50,  28 } } },  /* 77: no name, ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { { -105,  22,  92,  18 },  { -109,  88,  82,  22 },  {  -99,  64,  40,  40 },  {  -79,  88,   0,  40 } } },  /* 78: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  22 },  {  -31,  52,  46,  36 },  {  -36,  78,   0,  46 } } },  /* 79: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -30,  22,  88,  18 },  {  -24,  56,  82,  22 },  {  -31,  52,  46,  36 },  {  -36,  78,   0,  46 } } },  /* 80: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -40,  23,  70,  26 },  {  -16,  56,  80,  22 },  {  -31,  65,  36,  44 },  {  -34,  82,   0,  36 } } },  /* 81: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {    8,  22, 104,  18 },  {  -24,  70,  92,  14 },  {  -16,  48,  60,  32 },  {   -4,  50,  32,  26 } } },  /* 82: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -44,  58,  92,  26 },  {  -62,  30,  70,  34 },  {  -42,  61,  68,  24 },  {  -46,  65,  32,  38 } } },  /* 83: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -28,  22, 108,  18 },  {  -34,  60,  98,  20 },  {  -14,  38,  72,  24 },  {  -28,  48,  42,  28 } } },  /* 84: not used by a script */
    { { {   -8,  22, 118,  18 },  {  -24,  56,  98,  20 },  {  -22,  42,  70,  26 },  {  -14,  38,  28,  40 } } },  /* 85: not used by a script */
    { { {  -54,  78, 103,  24 },  {  -62,  80,  86,  21 },  {  -40,  64,  50,  37 },  {  -32,  68,  41,  16 } } },  /* 86: V JUMP P M A, V JUMP P L A */
    { { {  -52,  54, 102,  18 },  {  -60,  72,  88,  18 },  {  -36,  64,  51,  37 },  {   -4,  50,  48,  20 } } },  /* 87: V JUMP P M A */
    { { {   -2,  24, 109,  18 },  {  -26,  68,  94,  16 },  {  -22,  60,  58,  36 },  {  -14,  38,   0,  58 } } },  /* 88: L KICK A */
    { { {  -52,  60, 103,  18 },  {  -60,  84,  88,  18 },  {  -36,  71,  56,  32 },  {  -14,  60,  43,  20 } } },  /* 89: V JUMP P L A */
    { { {  -20,  24, 104,  18 },  {  -36,  68,  80,  25 },  {  -30,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 90: FRONT WALK, BACK WALK */
    { { {   -8,  24, 118,  18 },  {  -24,  60, 104,  22 },  {  -22,  46,  70,  32 },  {  -16,  48,  42,  26 } } },  /* 91: JUMP FRONT, JUMP VERTICAL, JUMP BACK +5 */
    { { {  -24,  24, 110,  18 },  {  -32,  60, 100,  22 },  {  -16,  44,  70,  28 },  {  -30,  52,  44,  24 } } },  /* 92: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) +12 */
    { { {  -46,  24,  94,  18 },  {  -28,  56, 100,  14 },  {  -10,  40,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 93: TUKAMIHAZUSI, TUKAMIHAZUSARE, ATTACK 4 M: not started by a command */
    { { {  -44,  42, 108,  18 },  {  -60,  92,  98,  14 },  {  -70, 108,  72,  24 },  {  -44,  77,  36,  36 } } },  /* 94: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -20,  24, 116,  18 },  {  -44,  72, 108,  14 },  {  -40,  72,  80,  30 },  {  -46,  80,  62,  24 } } },  /* 95: PARING AIR F, GUARD AIR, P BREAK AIR F +1 */
    { { {  -22,  24,  96,  18 },  {  -34,  70,  82,  20 },  {  -28,  56,  46,  36 },  {  -38,  86,   0,  46 } } },  /* 96: not used by a script */
    { { {  -38,  24,  52,  45 },  {  -32,  64,  68,  35 },  {  -32,  55,  50,  35 },  {  -32,  78,   0,  50 } } },  /* 97: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -40,  24,  69,  21 },  {  -32,  60,  67,  28 },  {  -44,  67,  50,  35 },  {  -48,  91,   0,  50 } } },  /* 98: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -22,  24,  94,  18 },  {  -44,  68,  82,  14 },  {  -28,  48,  48,  32 },  {  -34,  68,   0,  46 } } },  /* 99: not used by a script */
    { { {  -26,  53,  95,  17 },  {  -33,  67,  75,  30 },  {  -33,  67,  43,  32 },  {  -26,  53,  36,  16 } } },  /* 100: BODY SLAM, TOMOE RYU, MONKEY FLIP +6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 101: no name */
    { { {  -52,  62,  94,  20 },  {    0,   0,   0,   0 },  {  -48,  58,  68,  26 },  {  -48,  59,  38,  30 } } },  /* 102: ATTACK 6 S: EX [2](789)+PP (routine Att_SENPUUKYAKU) */
    { { {  -22,  24, 118,  18 },  {  -27,  62, 106,  16 },  {  -34,  58,  62,  44 },  {  -27,  50,  28,  36 } } },  /* 103: V JUMP K L A */
    { { {   -5,  27, 106,  18 },  {  -31,  65,  79,  25 },  {  -29,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 104: UPPER L */
    { { {    3,  27, 105,  18 },  {  -28,  65,  79,  25 },  {  -30,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 105: UPPER L */
    { { {    7,  27, 104,  18 },  {  -26,  65,  79,  25 },  {  -31,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 106: UPPER L */
    { { {    9,  27, 103,  18 },  {  -25,  65,  79,  25 },  {  -32,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 107: UPPER L */
    { { {   -5,  27, 100,  18 },  {  -27,  65,  78,  25 },  {  -24,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 108: FACE S, FACE M, FOOK OKU L +4 */
    { { {    7,  27,  98,  18 },  {  -21,  65,  77,  25 },  {  -21,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 109: FACE M, FACE L, FOOK OKU L +4 */
    { { {   15,  27,  96,  18 },  {  -17,  65,  76,  25 },  {  -19,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 110: FACE L, FOOK OKU L, FOOK OKU SP +1 */
    { { {   19,  27,  94,  18 },  {  -15,  65,  75,  25 },  {  -18,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 111: FACE L, FOOK OKU SP */
    { { {  -25,  27,  99,  18 },  {  -33,  65,  77,  25 },  {  -26,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 112: NOUTEN S, BODY BROW M, BODY BROW L +8 */
    { { {  -29,  27,  96,  18 },  {  -31,  65,  75,  25 },  {  -24,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 113: BODY BROW M, BODY BROW L */
    { { {  -33,  27,  93,  18 },  {  -29,  65,  73,  25 },  {  -22,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 114: not used by a script */
    { { {  -37,  27,  90,  18 },  {  -27,  65,  71,  25 },  {  -20,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 115: not used by a script */
    { { {   -6,  25,  54,  18 },  {  -27,  63,  43,  16 },  {  -37,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 116: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    { { {    0,  25,  54,  18 },  {  -25,  63,  43,  16 },  {  -36,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 117: KAGAMI S, KAGAMI M, KAGAMI L +8 */
    { { {    6,  25,  54,  18 },  {  -23,  63,  43,  16 },  {  -35,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 118: KAGAMI L */
    { { {   12,  25,  54,  18 },  {  -21,  63,  43,  16 },  {  -34,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 119: KAGAMI L */
    { { {  -29,  24, 101,  18 },  {  -37,  71,  90,  17 },  {  -37,  60,  52,  38 },  {  -36,  68,   0,  52 } } },  /* 120: L PUNCH C, follow-up of M PUNCH C */
    { { {  -45,  24,  97,  18 },  {  -39,  58,  85,  25 },  {  -39,  55,  52,  33 },  {  -46,  78,   0,  52 } } },  /* 121: L PUNCH C, follow-up of M PUNCH C */
    { { {  -45,  24,  90,  18 },  {  -39,  58,  81,  23 },  {  -39,  60,  52,  29 },  {  -45,  81,   0,  52 } } },  /* 122: L PUNCH C, follow-up of M PUNCH C */
    { { {  -51,  24,  73,  22 },  {  -38,  56,  66,  29 },  {  -33,  56,  48,  18 },  {  -49,  87,   0,  48 } } },  /* 123: L PUNCH C, follow-up of M PUNCH C */
    { { {  -40,  25,  84,  19 },  {  -36,  64,  72,  24 },  {  -34,  62,  40,  32 },  {  -48,  87,   0,  40 } } },  /* 124: L PUNCH C, follow-up of M PUNCH C */
    { { {  -32,  27,  98,  20 },  {  -32,  52,  83,  21 },  {  -33,  61,  42,  41 },  {  -37,  76,   0,  42 } } },  /* 125: L PUNCH C, follow-up of M PUNCH C */
    { { {  -46,  24,  93,  18 },  {  -45,  64,  81,  19 },  {  -48,  65,  52,  29 },  {  -45,  76,   0,  52 } } },  /* 126: M PUNCH C */
    { { {  -44,  24,  87,  18 },  {  -38,  52,  77,  22 },  {  -43,  68,  52,  25 },  {  -50,  89,   0,  52 } } },  /* 127: M PUNCH C */
    { { {  -28,  24, 103,  18 },  {  -36,  62,  81,  25 },  {  -35,  60,  52,  29 },  {  -39,  76,   0,  52 } } },  /* 128: M PUNCH C */
    { { {  -41,  25,  59,  18 },  {  -64,  63,  47,  17 },  {  -68,  78,  24,  23 },  {  -77,  98,   0,  24 } } },  /* 129: KAGAMI P A */
    { { {    2,  29, 101,  19 },  {  -15,  49,  75,  30 },  {  -19,  43,  51,  24 },  {  -25,  51,  35,  16 } } },  /* 130: AIR NORMAL, ASIB TUNNOMERI, HUMI ASIB */
    { { {    2,  29, 102,  19 },  {  -31,  59,  83,  30 },  {  -36,  46,  59,  24 },  {  -34,  52,  38,  21 } } },  /* 131: AIR NORMAL, ASIB TUNNOMERI, NOKEZORI +7 */
    { { {  -15,  27,  91,  17 },  {  -18,  71,  71,  29 },  {    0,  48,  51,  20 },  {  -20,  62,  30,  31 } } },  /* 132: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {  -33,  24,  86,  17 },  {  -26,  59,  70,  30 },  {   -6,  30,  54,  26 },  {  -35,  46,  40,  30 } } },  /* 133: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {  -27,  24,  89,  17 },  {  -20,  45,  70,  30 },  {  -20,  36,  50,  20 },  {  -42,  33,  50,  36 } } },  /* 134: ASIBARAI SIRI, KUNOJI, HARAYARARE +1 */
    { { {   18,  24,  86,  17 },  {    5,  38,  55,  30 },  {  -20,  36,  49,  26 },  {  -33,  31,  56,  42 } } },  /* 135: ASIBARAI SIRI, KUNOJI, HARAYARARE */
    { { {  -56,  26,  39,  22 },  {  -51,  39,  30,  35 },  {  -41,  48,  50,  30 },  {  -12,  49,  35,  38 } } },  /* 136: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -17,  26,  23,  22 },  {  -32,  46,  31,  35 },  {  -28,  48,  52,  30 },  {    0,  33,  47,  42 } } },  /* 137: ASIB TUNNOMERI, HUMI ASIB */
    { { {   11,  32,  15,  21 },  {  -15,  50,   4,  31 },  {  -22,  38,  22,  28 },  {  -13,  51,  39,  30 } } },  /* 138: ASIB TUNNOMERI, HUMI ASIB */
    { { {   31,  32,  -2,  21 },  {   -8,  53, -10,  31 },  {  -23,  42,   9,  28 },  {  -36,  47,  22,  37 } } },  /* 139: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -46,  23,  90,  19 },  {  -38,  51,  85,  30 },  {  -10,  35,  67,  35 },  {  -28,  53,  47,  32 } } },  /* 140: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {  -45,  23,  95,  19 },  {  -41,  56,  91,  33 },  {  -24,  42,  72,  31 },  {  -37,  49,  47,  36 } } },  /* 141: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {  -13,  25, 114,  19 },  {  -34,  49,  87,  32 },  {  -38,  42,  65,  31 },  {  -37,  47,  38,  36 } } },  /* 142: NOKEZORI, KIRIMOMI, UPPER +3 */
    { { {   25,  31, 107,  19 },  {   -4,  55,  86,  30 },  {  -21,  46,  71,  25 },  {  -42,  53,  53,  31 } } },  /* 143: NOKEZORI, KIRIMOMI, UPPER +4 */
    { { {   38,  30,  83,  21 },  {    3,  42,  66,  45 },  {  -21,  29,  59,  43 },  {  -55,  41,  51,  40 } } },  /* 144: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   38,  30,  76,  21 },  {    3,  42,  60,  45 },  {  -21,  29,  57,  43 },  {  -55,  41,  54,  40 } } },  /* 145: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   52,  30,  65,  21 },  {   10,  42,  52,  39 },  {  -20,  35,  62,  34 },  {  -38,  37,  67,  37 } } },  /* 146: NOKEZORI, KIRIMOMI, UPPER +5 */
    { { {   37,  30,  54,  21 },  {    8,  42,  38,  39 },  {  -15,  40,  56,  34 },  {  -27,  38,  73,  36 } } },  /* 147: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    { { {   27,  30,  36,  21 },  {   -8,  42,  31,  36 },  {  -24,  41,  47,  32 },  {  -25,  48,  71,  26 } } },  /* 148: NOKEZORI, KUNOJI, KIRIMOMI +7 */
    { { {  -20,  28, 113,  17 },  {  -33,  51,  90,  24 },  {  -43,  48,  66,  29 },  {  -39,  53,  36,  30 } } },  /* 149: DENKI */
    { { {  -49,  32,  73,  20 },  {  -43,  60,  80,  28 },  {  -39,  56,  53,  34 },  {    0,   0,   0,   0 } } },  /* 150: not used by a script */
    { { {  -20,  32, 101,  20 },  {  -23,  56,  87,  28 },  {  -30,  50,  70,  21 },  {  -43,  49,  55,  25 } } },  /* 151: not used by a script */
    { { {    0,  28,  95,  18 },  {   -9,  53,  75,  30 },  {  -20,  49,  50,  25 },  {  -33,  59,  31,  26 } } },  /* 152: TOUKETSU A */
    { { {  -19,  27, 105,  18 },  {  -34,  65,  81,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 153: KAMAE */
    { { {  -13,  27, 102,  18 },  {  -34,  65,  80,  25 },  {  -27,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 154: HURIMUKI */
    { { {  -24,  24, 106,  18 },  {  -36,  62,  81,  25 },  {  -30,  52,  52,  38 },  {  -28,  54,   0,  50 } } },  /* 155: FRONT WALK */
    { { {  -24,  24, 105,  18 },  {  -36,  62,  82,  25 },  {  -30,  52,  52,  38 },  {  -30,  56,   0,  50 } } },  /* 156: FRONT WALK */
    { { {  -24,  24, 109,  18 },  {  -34,  59,  83,  25 },  {  -30,  52,  52,  38 },  {  -30,  56,   0,  50 } } },  /* 157: FRONT WALK */
    { { {  -24,  24, 106,  18 },  {  -31,  54,  84,  25 },  {  -34,  52,  52,  38 },  {  -40,  69,   0,  50 } } },  /* 158: FRONT WALK */
    { { {  -22,  24, 108,  18 },  {  -34,  60,  84,  25 },  {  -28,  52,  52,  38 },  {  -26,  52,   0,  50 } } },  /* 159: FRONT WALK */
    { { {  -16,  24, 110,  18 },  {  -25,  54,  92,  22 },  {  -28,  52,  52,  38 },  {  -30,  58,   0,  50 } } },  /* 160: BACK WALK */
    { { {  -18,  24, 108,  18 },  {  -26,  56,  92,  22 },  {  -28,  52,  52,  38 },  {  -26,  54,   0,  50 } } },  /* 161: BACK WALK */
    { { {  -16,  24, 110,  18 },  {  -24,  54,  92,  22 },  {  -28,  52,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 162: BACK WALK */
    { { {  -14,  24, 108,  18 },  {  -24,  54,  92,  22 },  {  -28,  52,  52,  38 },  {  -40,  68,   0,  50 } } },  /* 163: BACK WALK */
    { { {  -14,  24, 108,  18 },  {  -21,  50,  92,  22 },  {  -30,  54,  52,  38 },  {  -34,  62,   0,  50 } } },  /* 164: BACK WALK */
    { { {  -17,  22,  74,  18 },  {  -27,  64,  61,  22 },  {  -26,  66,  41,  18 },  {  -36,  76,   0,  40 } } },  /* 165: DASH HUMIKOMI, DASH TOBINOKI, KAGAMU +1 */
    { { {  -50,  22,  92,  18 },  {  -36,  60,  82,  25 },  {  -32,  60,  41,  40 },  {  -32,  72,   0,  40 } } },  /* 166: DASH HUMIKOMI */
    { { {  -46,  22,  96,  18 },  {  -36,  60,  82,  25 },  {  -32,  60,  41,  40 },  {  -32,  72,   0,  40 } } },  /* 167: DASH HUMIKOMI */
    { { {  -18,  28,  89,  18 },  {  -28,  65,  69,  25 },  {  -24,  52,  52,  28 },  {  -32,  68,   0,  50 } } },  /* 168: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    { { {  -21,  28, 107,  18 },  {  -33,  65,  83,  25 },  {  -28,  52,  52,  38 },  {  -26,  62,   0,  50 } } },  /* 169: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    { { {  -16,  22,  88,  18 },  {  -26,  64,  74,  20 },  {  -25,  58,  35,  38 },  {  -32,  69,   0,  34 } } },  /* 170: DASH TOBINOKI, KAGAMU */
    { { {   -1,  22, 113,  18 },  {  -20,  60,  94,  19 },  {  -24,  62,  51,  43 },  {  -36,  72,   0,  50 } } },  /* 171: DASH TOBINOKI */
    { { {  -22,  22,  90,  18 },  {  -22,  60,  70,  25 },  {  -26,  62,  42,  26 },  {  -40,  76,   0,  41 } } },  /* 172: DASH TOBINOKI */
    { { {  -19,  27, 105,  18 },  {  -28,  62,  83,  25 },  {  -24,  52,  52,  36 },  {  -36,  72,   0,  50 } } },  /* 173: DASH TOBINOKI */
    { { {  -12,  32,  58,  18 },  {  -33,  70,  43,  16 },  {  -44,  88,  24,  22 },  {  -40,  80,   0,  22 } } },  /* 174: KAGAMI KAMAE */
    { { {  -12,  32,  52,  20 },  {  -29,  66,  40,  16 },  {  -40,  82,  22,  22 },  {  -40,  80,   0,  22 } } },  /* 175: KAGAMI KAMAE */
    { { {  -33,  33, 103,  18 },  {  -40,  63,  88,  22 },  {  -31,  53,  41,  45 },  {  -31,  62,   0,  40 } } },  /* 176: PIYO */
    { { {  -17,  32,  58,  18 },  {  -33,  65,  43,  16 },  {  -38,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 177: KAGAMI TURN */
    { { {  -19,  32,  56,  18 },  {  -33,  67,  43,  16 },  {  -38,  78,  24,  23 },  {  -39,  79,   0,  22 } } },  /* 178: KAGAMI TURN */
    { { {  -16,  22,  98,  18 },  {  -28,  64,  77,  25 },  {  -26,  62,  41,  35 },  {  -32,  69,   0,  40 } } },  /* 179: JUMP JUNBI */
    { { {  -16,  27,  90,  18 },  {  -26,  64,  73,  22 },  {  -26,  60,  37,  34 },  {  -32,  72,   0,  36 } } },  /* 180: SP JUMP JUNBI */
    { { {  -46,  24,  98,  18 },  {  -28,  56,  94,  22 },  {  -18,  46,  72,  26 },  {  -36,  60,  50,  26 } } },  /* 181: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    { { {  -46,  24,  87,  18 },  {  -28,  56,  94,  22 },  {  -18,  46,  72,  26 },  {  -40,  64,  54,  26 } } },  /* 182: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
};

const HAND_BOX urien_hand_box[44] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -124,  82,  53,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: M KICK C */
    { { {  -88,  48,  70,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {  -60,  40,  68,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: not used by a script */
    { { {  -40,  26,  98,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: not used by a script */
    { { {  -82,  60,  76,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A, follow-up of S PUNCH A */
    { { {  -84,  54,  42,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A, follow-up of M PUNCH C */
    { { {  -72,  38,  40,  62 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH A */
    { { {  -80,  48,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: S KICK A */
    { { {  -78,  58,  74,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: not used by a script */
    { { { -118,  60,  68,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M KICK A */
    { { {  -98,  78,  64,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L KICK A */
    { { {  -88,  58,  20,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: L KICK A */
    { { {  -84,  38,  42,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI P A */
    { { {  -56,  41,  76,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI P A, no name */
    { { { -114,  74,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: KAGAMI K A, KAGAMI P A */
    { { { -120,  81,   0,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: KAGAMI K A */
    { { {  -68,  57,  83,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { {  -38,  18,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: not used by a script */
    { { { -110,  74,  70,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: V JUMP K M A, ATTACK 4 M: not started by a command */
    { { { -108,  87,  49,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: V JUMP K L A */
    { { {  -50,  28,  72,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: follow-up of APPEAR JUNBI 6 */
    { { {  -64,  16,  32,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -60,  38,  66,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 2 M: not started by a command, ATTACK 12 L: SA I 23623+P (routine Att_CHOUCHUURENGEKI) */
    { { {  -90,  53,  70,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: V JUMP P M A */
    { { {  -58,  40,  84,  66 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A */
    { { {  -86,  50,  60,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P L A */
    { { {  -66,  32,  54,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: ATTACK 4 M: not started by a command, ATTACK 7 M: not started by a command */
    { { {  -68,  48,  78,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: not used by a script */
    { { {  -44,  19,  31,  70 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: ATTACK 9 L: [4]6+K light (routine Att_CHOUCHUURENGEKI), ATTACK 9 SP: [4]6+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 10 S: [4]6+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    { { {  -99,  69,  25,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: M KICK C */
    { { {  -30,  38,  93,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: L KICK A */
    { { {  -58,  21,  64,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: L PUNCH C, follow-up of M PUNCH C */
    { { {  -21,  40, 110,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: L PUNCH C, follow-up of M PUNCH C */
    { { {  -25,  42, 104,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: L PUNCH C, follow-up of M PUNCH C */
    { { {  -27,  32,  87,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: L PUNCH C, follow-up of M PUNCH C */
    { { {  -98,  35,  26,  25 },  {  -84,  35,  35,  28 },  {  -68,  35,  47,  27 },  {    0,   0,   0,   0 } } },  /* 36: L PUNCH C, follow-up of M PUNCH C */
    { { {  -27,  46,  87,  13 },  {  -56,  23,  48,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: L PUNCH C, follow-up of M PUNCH C */
    { { {  -51,  17,  40,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L PUNCH C, follow-up of M PUNCH C */
    { { {  -80,  48,  77,  29 },  {  -95,  35,  92,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: M PUNCH C */
    { { {  -75,  30,  75,  30 },  {   -7,  35,  80,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: M PUNCH C */
    { { {  -77,  32,  71,  28 },  {  -18,  39,  80,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: M PUNCH C */
    { { {  -69,  24,  67,  24 },  {  -19,  45,  86,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: M PUNCH C */
    { { {  -52,  40,  76,  62 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI P A, no name */
};

const HOSEI_BOX urien_hos_box[15] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   94 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +87 */
    { {  -24,   48,    0,   54 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +55 */
    { {  -24,   48,   54,   58 } },  /* 3: GUARD AIR, V JUMP P M A, V JUMP P L A +27 */
    { {   -4,   48,    0,  100 } },  /* 4: not used by a script */
    { {  -11,   48,    0,  100 } },  /* 5: not used by a script */
    { {    7,   48,    0,   54 } },  /* 6: not used by a script */
    { {  -24,   48,    0,  100 } },  /* 7: not used by a script */
    { {  -24,   48,    0,   84 } },  /* 8: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +10 */
    { {  -32,   64,    0,   94 } },  /* 9: DASH HUMIKOMI, no name */
    { {  -48,   72,    0,   56 } },  /* 10: KAGAMI P A */
    { {  -23,   48,   34,   58 } },  /* 11: BODY SLAM, TOMOE RYU, MONKEY FLIP +24 */
    { {  -44,   54,   48,   63 } },  /* 12: ATTACK 5 M: [2](789)+P light (routine Att_SENPUUKYAKU), ATTACK 5 L: [2](789)+P medium (routine Att_SENPUUKYAKU), ATTACK 5 SP: [2](789)+P heavy (routine Att_SENPUUKYAKU) +1 */
    { {  -24,   48,   50,   62 } },  /* 13: ATTACK 1 M: [2](789)+K light (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [2](789)+K medium (routine Att_SLIDE_and_JUMP), ATTACK 1 SP: [2](789)+K heavy (routine Att_SLIDE_and_JUMP) +6 */
    { {  -24,   48,    0,   82 } },  /* 14: UPPER L, FACE S, FACE M +18 */
};
