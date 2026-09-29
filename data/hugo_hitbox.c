/*
 * HUGO_HITBOX.C  Hugo's hit boxes
 *
 * Each of Hugo's animation frames names an entry of hugo_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX hugo_hit_ix_table[258] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +31 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, DASH HUMIKOMI, DASH TOBINOKI +86 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMI KAMAE, PARING DOWN, GUARD DOWN +17 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: GUARD AIR, V JUMP P S A, V JUMP P M A +10 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: PARING AIR F, GUARD AIR, TUKAMIHAZUSI +16 */
    {    5,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 5: PARING AIR F, GUARD AIR, P BREAK AIR F +1 */
    {    6,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 6: DASH HUMIKOMI */
    {    7,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 7: DASH HUMIKOMI */
    {    8,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: S PUNCH A */
    {    8,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 9: S PUNCH A */
    {    8,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 10: S PUNCH A */
    {    8,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 11: S PUNCH A */
    {    1,    0,    4, 0x0000,    0,    1,    3,    1 },  /* 12: M PUNCH A */
    {    1,    0,    5, 0x0000,    0,    1,    4,    1 },  /* 13: M PUNCH A */
    {    1,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 14: M PUNCH A */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 15: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   10,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 16: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   10,    0,    7, 0x0000,    0,    1,    5,    1 },  /* 17: L PUNCH A */
    {   10,    0,    8, 0x0000,    0,    1,    6,    1 },  /* 18: L PUNCH A */
    {   10,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 19: L PUNCH A, ZANNEN 3 */
    {   10,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 20: L PUNCH A, ZANNEN 3 */
    {   93,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 21: JUMP JUNBI, SP JUMP JUNBI */
    {    1,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 22: L PUNCH B */
    {    1,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 23: L PUNCH B */
    {    1,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 24: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,   12, 0x0000,    0,    1,    7,    1 },  /* 25: L PUNCH B */
    {    1,    0,   13, 0x0000,    0,    1,    8,    1 },  /* 26: L PUNCH B */
    {    1,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 27: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   54,    0,   15, 0x0000,    0,    1,    9,    1 },  /* 28: S KICK A */
    {   54,    0,   15, 0x0000,    0,    1,   10,    1 },  /* 29: S KICK A */
    {   54,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 30: S KICK A */
    {   11,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: M KICK A */
    {   56,    0,   16, 0x0000,    0,    1,   11,    1 },  /* 32: M KICK A */
    {   56,    0,   17, 0x0000,    0,    1,   12,    1 },  /* 33: M KICK A */
    {   56,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 34: M KICK A */
    {   56,    0,   19, 0x0000,    0,    1,   43,    1 },  /* 35: M KICK A */
    {   12,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 36: ATTACK 1 S: 214+P light (plain script) */
    {   13,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 37: ATTACK 1 S: 214+P light (plain script) */
    {   14,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 38: ATTACK 1 S: 214+P light (plain script) */
    {   15,    0,   19, 0x0000,    0,    1,   13,   11 },  /* 39: ATTACK 1 S: 214+P light (plain script) */
    {   15,    0,   20, 0x0000,    0,    1,    0,   11 },  /* 40: ATTACK 1 S: 214+P light (plain script) */
    {   12,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 41: ATTACK 1 M: 214+P medium (plain script) */
    {   13,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 42: ATTACK 1 M: 214+P medium (plain script) */
    {   14,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 43: ATTACK 1 M: 214+P medium (plain script) */
    {   15,    0,   19, 0x0000,    0,    1,   13,   11 },  /* 44: ATTACK 1 M: 214+P medium (plain script) */
    {   15,    0,   20, 0x0000,    0,    1,    0,   11 },  /* 45: ATTACK 1 M: 214+P medium (plain script) */
    {   12,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 46: ATTACK 1 L: 214+P heavy (plain script), ATTACK 1 SP: EX 214+PP (plain script) */
    {   13,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 47: ATTACK 1 L: 214+P heavy (plain script), ATTACK 1 SP: EX 214+PP (plain script) */
    {   14,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 48: ATTACK 1 L: 214+P heavy (plain script), ATTACK 1 SP: EX 214+PP (plain script) */
    {   15,    0,   19, 0x0000,    0,    1,   13,   11 },  /* 49: ATTACK 1 L: 214+P heavy (plain script), ATTACK 1 SP: EX 214+PP (plain script) */
    {   15,    0,   20, 0x0000,    0,    1,    0,   11 },  /* 50: ATTACK 1 L: 214+P heavy (plain script), ATTACK 1 SP: EX 214+PP (plain script) */
    {   24,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 51: L KICK A */
    {   24,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 52: L KICK A */
    {   24,    0,   26, 0x0000,    0,    3,   14,    3 },  /* 53: L KICK A */
    {   24,    0,   25, 0x0000,    0,    3,   15,    3 },  /* 54: L KICK A */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 55: L KICK A */
    {    2,    0,   27, 0x0000,    0,   10,   17,    2 },  /* 56: not used by a script */
    {    2,    0,   27, 0x0000,    0,   10,   17,    2 },  /* 57: KAGAMI P A */
    {    2,    0,   27, 0x0000,    0,   10,    0,    2 },  /* 58: KAGAMI P A */
    {    2,    0,   28, 0x0000,    0,    2,   18,    2 },  /* 59: KAGAMI P A */
    {    2,    0,   28, 0x0000,    0,    2,   19,    2 },  /* 60: KAGAMI P A */
    {    2,    0,   28, 0x0000,    0,    2,    0,    2 },  /* 61: KAGAMI P A */
    {   55,    0,   30, 0x0000,    0,   10,   20,    2 },  /* 62: KAGAMI K A */
    {   55,    0,   30, 0x0000,    0,   10,   20,    2 },  /* 63: KAGAMI K A */
    {   55,    0,   30, 0x0000,    0,   10,    0,    2 },  /* 64: KAGAMI K A */
    {   55,    0,   31, 0x0000,    0,    2,   21,    2 },  /* 65: KAGAMI K A */
    {   55,    0,   32, 0x0000,    0,    2,   22,    2 },  /* 66: KAGAMI K A */
    {   26,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 67: L KICK A, follow-up of APPEAR JUNBI 7 */
    {   27,    0,    0, 0x0000,    0,    2,    0,    7 },  /* 68: PIYO */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 69: CATCH 33, follow-up of ASIBARAI SIRI, follow-up of HUMI ASIB +2 */
    {   28,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 70: KAGAMI P A */
    {   29,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 71: KAGAMI P A */
    {   30,    0,    0, 0x0000,    0,    6,   23,    8 },  /* 72: KAGAMI P A */
    {   30,    0,    0, 0x0000,    0,    6,   24,    8 },  /* 73: KAGAMI P A */
    {   31,    0,    0, 0x0000,    0,    6,   25,    8 },  /* 74: not used by a script */
    {   32,    0,    0, 0x0000,    0,    6,    0,    8 },  /* 75: KAGAMI P A */
    {   33,    0,    0, 0x0000,    0,    6,    0,    8 },  /* 76: not used by a script */
    {   34,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 77: KAGAMI K A */
    {   35,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 78: KAGAMI K A */
    {   36,    0,    0, 0x0000,    0,    6,   27,    8 },  /* 79: KAGAMI K A */
    {   36,    0,    0, 0x0000,    0,    6,   28,    8 },  /* 80: KAGAMI K A */
    {   36,    0,    0, 0x0000,    0,    6,   29,    8 },  /* 81: KAGAMI K A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 82: NEKOROBI S, OKIAGARI, OKIAGARI F +16 */
    {   37,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 83: AIR NORMAL, TTKI V. AIR, BODY SLAM +11 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 84: CATCH 33, follow-up of AIR NORMAL */
    {   55,    0,   32, 0x0000,    0,    2,    0,    2 },  /* 85: KAGAMI K A */
    {    4,    0,   33, 0x0000,    0,    3,   31,    3 },  /* 86: V JUMP P S A */
    {    4,    0,   34, 0x0000,    0,    3,   32,    3 },  /* 87: V JUMP P S A */
    {    4,    0,   35, 0x0000,    0,    3,   33,    3 },  /* 88: V JUMP P S A */
    {    4,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 89: V JUMP P S A */
    {    4,    0,   33, 0x0000,    0,    3,   44,    3 },  /* 90: V JUMP P M A */
    {    4,    0,   34, 0x0000,    0,    3,   45,    3 },  /* 91: V JUMP P M A */
    {    4,    0,   35, 0x0000,    0,    3,   46,    3 },  /* 92: V JUMP P M A */
    {    4,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 93: V JUMP P M A */
    {   45,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 94: V JUMP P L A */
    {   45,    0,   43, 0x0000,    0,    3,    0,    3 },  /* 95: V JUMP P L A */
    {   45,    0,   36, 0x0000,    0,    3,    0,    3 },  /* 96: V JUMP P L A */
    {   45,    0,   36, 0x0000,    0,    3,   34,    3 },  /* 97: V JUMP P L A */
    {   45,    0,   36, 0x0000,    0,    3,   35,    3 },  /* 98: V JUMP P L A */
    {    1,    0,    0, 0x0000,    2,    1,    0,    1 },  /* 99: ATTACK 3 S: 360+P light (plain script) */
    {    1,    0,    0, 0x0000,    3,    1,    0,    1 },  /* 100: ATTACK 3 M: 360+P medium (plain script) */
    {    1,    0,    0, 0x0000,    4,    1,    0,    1 },  /* 101: ATTACK 3 L: 360+P heavy/EX (plain script) */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: V JUMP K S A, ATTACK 10 S: not started by a command */
    {   38,    0,   37, 0x0000,    0,    3,   36,    3 },  /* 103: V JUMP K S A */
    {   38,    0,   37, 0x0000,    0,    3,   37,    3 },  /* 104: V JUMP K S A */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 105: V JUMP K M A */
    {   38,    0,   38, 0x0000,    0,    3,   38,    3 },  /* 106: V JUMP K M A */
    {   38,    0,   38, 0x0000,    0,    3,   39,    3 },  /* 107: V JUMP K M A */
    {   39,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 108: V JUMP K L A */
    {   40,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 109: V JUMP K L A */
    {   41,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 110: V JUMP K L A */
    {   42,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP K L A */
    {   43,    0,   39, 0x0000,    0,    3,   40,    3 },  /* 112: V JUMP K L A */
    {   43,    0,   40, 0x0000,    0,    3,   41,    3 },  /* 113: V JUMP K L A */
    {   43,    0,   41, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   44,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 115: V JUMP K L A */
    {   59,    0,    0, 0x0000,    0,    1,   47,    1 },  /* 116: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {    1,    0,    0, 0x0000,    0,    1,   48,    1 },  /* 117: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    1,    0,   49, 0x0000,    0,    1,   49,    1 },  /* 118: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    1,    0,    0, 0x0000,    0,    1,   50,    1 },  /* 119: not used by a script */
    {   46,    0,    0, 0x0000,    0,    3,    0,   12 },  /* 120: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    {   47,    0,    0, 0x0000,    5,    3,    0,   12 },  /* 121: ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    {   52,    0,    0, 0x0000,    0,    3,    0,   12 },  /* 122: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    {   53,    0,    0, 0x0000,    6,    3,    0,   12 },  /* 123: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    {   49,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 124: V JUMP P L B */
    {   50,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 125: V JUMP P L B */
    {   51,    0,   46, 0x0000,    0,    9,   51,   10 },  /* 126: V JUMP P L B */
    {   51,    0,   46, 0x0000,    0,    9,    0,   10 },  /* 127: V JUMP P L B */
    {   50,    0,   47, 0x0000,    0,    3,    0,    3 },  /* 128: V JUMP P L B */
    {   50,    0,   47, 0x0000,    0,    3,    0,    3 },  /* 129: V JUMP P L B */
    {    0,    0,    0, 0x0000,    0,    0,   52,    0 },  /* 130: CATCH 29 */
    {    1,    0,    0, 0x0000,    0,    1,   53,    1 },  /* 131: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   59,    0,    0, 0x0000,    0,    1,   54,    1 },  /* 132: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    1,   55,    1 },  /* 133: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    {    1,    0,   49, 0x0000,    0,    1,   56,    1 },  /* 134: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    {    1,    0,   12, 0x0000,    0,    1,   57,    1 },  /* 135: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   10,    0,    7, 0x0000,    0,    1,   58,    1 },  /* 136: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   15,    0,   19, 0x0000,    0,    1,   59,   13 },  /* 137: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {    1,    0,   48, 0x0000,    0,    1,   60,    1 },  /* 138: ATTACK 9 M: not started by a command */
    {    1,    0,   48, 0x0000,    0,    1,    0,    1 },  /* 139: not used by a script */
    {    1,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 140: L PUNCH B */
    {   54,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 141: S KICK A */
    {    0,    0,    0, 0x0000,    7,    1,    0,    1 },  /* 142: ATTACK 6 S: SA I 720+P (plain script) */
    {   38,    0,   37, 0x0000,    0,    3,    0,    3 },  /* 143: V JUMP K S A, V JUMP K M A */
    {   48,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 144: follow-up of SP APPEAR 7 */
    {   57,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 145: L KICK A, follow-up of APPEAR JUNBI 7 */
    {   58,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 146: no name */
    {   59,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 147: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +3 */
    {    1,    0,   44, 0x0000,    0,    1,    0,    1 },  /* 148: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {    1,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 149: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +3 */
    {    1,    0,    0, 0x0000,    8,    1,    0,    1 },  /* 150: ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 4 M: 6(123)4+K medium (plain script), ATTACK 4 L: 6(123)4+K heavy/EX (plain script) */
    {   60,    0,    0, 0x0000,    0,   11,    0,    1 },  /* 151: ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 6 S: SA I 720+P (plain script) +3 */
    {   61,    0,    0, 0x0000,    0,   11,    0,    7 },  /* 152: ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 6 S: SA I 720+P (plain script) +3 */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 153: ATTACK 9 M: not started by a command */
    {   63,    0,    0, 0x0000,    0,   11,    0,    7 },  /* 154: ATTACK 9 M: not started by a command */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 155: TUKAMIKAKARI A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 156: CATCH 33, ATTACK 6 S: SA I 720+P (plain script), ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN) +3 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    0 },  /* 157: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    1,    0,   49, 0x0000,    0,    1,    0,    0 },  /* 158: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    {    1,    0,   44, 0x0000,    0,    1,    0,    0 },  /* 159: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +1 */
    {    0,    0,    0, 0x0000,    0,    0,   54,    1 },  /* 160: ATTACK 8 S: SA III 23623+P light (routine Att_SLIDE_and_JUMP) */
    {    1,    0,   13, 0x0000,    0,    1,   61,    1 },  /* 161: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   10,    0,    8, 0x0000,    0,    1,   62,    1 },  /* 162: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   12,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 163: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   13,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 164: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   14,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 165: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   15,    0,   19, 0x0000,    0,    1,   13,   13 },  /* 166: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   15,    0,   20, 0x0000,    0,    1,    0,   13 },  /* 167: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    {   64,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 168: follow-up of APPEAR JUNBI 7 */
    {   65,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 169: follow-up of APPEAR JUNBI 7 */
    {   66,    0,   50, 0x0000,    0,    3,   63,    3 },  /* 170: ATTACK 10 S: not started by a command */
    {    1,    0,    0, 0x0000,    9,    1,    0,    1 },  /* 171: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    {   83,    0,    0, 0x0000,    0,    3,   64,    3 },  /* 172: CATCH 38, CATCH 39, CATCH 40 */
    {   83,    0,    0, 0x0000,    0,    3,   64,    3 },  /* 173: CATCH 38, CATCH 39, CATCH 40 */
    {   67,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 174: UPPER L */
    {   68,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 175: UPPER L */
    {   69,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 176: UPPER L */
    {   70,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 177: UPPER L */
    {   71,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 178: FACE S, FACE M, FACE L +5 */
    {   72,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 179: FACE M, FACE L, FOOK OKU L +1 */
    {   73,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 180: FACE L, FOOK OKU L, FOOK TEMAE L */
    {   74,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 181: FACE L, FOOK OKU L, FOOK TEMAE L */
    {   75,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 182: NOUTEN S, NOUTEN M, NOUTEN L +2 */
    {   76,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 183: NOUTEN M, NOUTEN L, BODY BROW L +1 */
    {   77,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 184: NOUTEN L, BODY BROW L, BODY UPPER L */
    {   78,    0,    0, 0x0000,    0,    1,    0,   15 },  /* 185: NOUTEN L, BODY BROW L, BODY UPPER L +4 */
    {   79,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 186: KAGAMI S, KAGAMI M, KAGAMI L +7 */
    {   80,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 187: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    {   81,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 188: KAGAMI L */
    {   82,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 189: KAGAMI L */
    {   84,    0,    0, 0x0000,    0,    1,    0,   14 },  /* 190: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 191: KAMAE, HURIMUKI, follow-up of APPEAR JUNBI 2 */
    {   85,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 192: KAMAE */
    {   86,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 193: KAMAE */
    {   87,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 194: HURIMUKI */
    {   88,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 195: HURIMUKI */
    {   89,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 196: FRONT WALK */
    {   90,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 197: FRONT WALK */
    {   91,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 198: BACK WALK */
    {   92,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 199: BACK WALK */
    {   93,    0,    0, 0x1010,    0,    1,    0,    4 },  /* 200: DASH HUMIKOMI, DASH TOBINOKI, follow-up of APPEAR 8 +1 */
    {   94,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 201: DASH HUMIKOMI, DASH TOBINOKI, follow-up of APPEAR 8 +1 */
    {   94,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 202: DASH HUMIKOMI, DASH TOBINOKI, follow-up of CATCH 38, CATCH 39 +1 */
    {   95,    0,    0, 0x1010,    0,    5,    0,    1 },  /* 203: DASH TOBINOKI */
    {   96,    0,    0, 0x1010,    0,    5,    0,    1 },  /* 204: DASH TOBINOKI */
    {   97,    0,    0, 0x0000,    0,    5,    0,    1 },  /* 205: DASH TOBINOKI */
    {   93,    0,    0, 0x1010,    0,    2,    0,    4 },  /* 206: KAGAMU, follow-up of APPEAR 8 */
    {   94,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 207: KAGAMU, follow-up of APPEAR 8 */
    {   98,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 208: KAGAMI TURN */
    {   99,    0,    0, 0x1818,    0,    2,    0,    2 },  /* 209: KAGAMI TURN */
    {  100,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 210: KAGAMI TURN */
    {   94,    0,    0, 0x1010,    0,    1,    0,    4 },  /* 211: STAND UP, follow-up of APPEAR 8 */
    {  101,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 212: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  102,    0,    0, 0x1919,    0,    3,    0,    3 },  /* 213: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    {  103,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 214: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
    {  104,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 215: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  105,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 216: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  106,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 217: AIR NORMAL */
    {  107,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 218: ASIBARAI SIRI, HUMI ASIB */
    {  108,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 219: ASIBARAI SIRI, TTKI V. AIR */
    {  109,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 220: ASIBARAI SIRI */
    {  110,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 221: ASIBARAI SIRI */
    {  111,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 222: ASIBARAI SIRI, TTKI V. AIR, HUMI ASIB */
    {  112,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 223: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  113,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 224: NOKEZORI, KIRIMOMI, UPPER +6 */
    {  114,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 225: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  115,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 226: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  116,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 227: NOKEZORI, KIRIMOMI, UPPER +6 */
    {  117,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 228: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  118,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 229: NOKEZORI, KIRIMOMI, UPPER +6 */
    {  119,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 230: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  120,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 231: KUNOJI, HARAYARARE, KUNOJI NOKE +1 */
    {  121,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 232: KUNOJI, HARAYARARE, KUNOJI NOKE +1 */
    {  122,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 233: KUNOJI, HARAYARARE, KUNOJI NOKE */
    {  123,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 234: KUNOJI, HARAYARARE, KUNOJI NOKE */
    {  124,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 235: KUNOJI */
    {  125,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 236: KUNOJI */
    {  126,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 237: KUNOJI */
    {  127,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 238: KUNOJI */
    {  128,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 239: UPPER, TATUMAKIZANKU */
    {  129,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 240: UPPER, TATUMAKIZANKU */
    {  130,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 241: UPPER, TATUMAKIZANKU */
    {  131,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 242: UPPER, TATUMAKIZANKU */
    {  132,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 243: BODY UPPER */
    {  133,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 244: BODY UPPER, TTKI V. AIR */
    {  134,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 245: BODY UPPER */
    {  135,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 246: BODY UPPER */
    {  136,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 247: BODY UPPER */
    {  137,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 248: BODY UPPER */
    {  138,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 249: DENKI */
    {  139,    0,    0, 0x0000,    0,    7,    0,    9 },  /* 250: TOUKETSU A */
    {   93,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 251: ATTACK 10 S: not started by a command */
    {   47,    0,    0, 0x0000,   10,    3,    0,   12 },  /* 252: ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN) */
    {   47,    0,    0, 0x0000,   11,    3,    0,   12 },  /* 253: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN) */
    {  140,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 254: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN) */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 255: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
    {   31,    0,    0, 0x0000,    0,    6,    0,    8 },  /* 256: KAGAMI P A */
    {  141,    0,    0, 0x1010,    0,    1,    0,   15 },  /* 257: follow-up of APPEAR JUNBI 2 */
};

const BODY_BOX hugo_body_box[142] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -20,  39, 109,  27 },  {  -34,  70,  83,  26 },  {  -33,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 1: KAMAE, DASH HUMIKOMI, DASH TOBINOKI +90 */
    { { {  -34,  38,  71,  25 },  {  -35,  69,  53,  24 },  {  -38,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 2: KAGAMI KAMAE, PARING DOWN, GUARD DOWN +17 */
    { { {  -19,  39, 131,  27 },  {  -33,  68, 102,  28 },  {  -31,  62,  73,  29 },  {  -35,  62,  46,  27 } } },  /* 3: GUARD AIR, V JUMP P S A, V JUMP P M A +10 */
    { { {  -24,  39, 127,  27 },  {  -35,  71, 106,  28 },  {  -30,  62,  80,  26 },  {  -38,  72,  54,  26 } } },  /* 4: PARING AIR F, GUARD AIR, TUKAMIHAZUSI +16 */
    { { {  -20,  39, 120,  27 },  {  -33,  68, 102,  28 },  {  -30,  63,  78,  26 },  {  -37,  69,  54,  26 } } },  /* 5: PARING AIR F, GUARD AIR, P BREAK AIR F +1 */
    { { {  -45,  41, 107,  27 },  {  -63,  83,  80,  26 },  {  -38,  69,  50,  30 },  {  -46, 101,   0,  50 } } },  /* 6: DASH HUMIKOMI */
    { { {  -32,  41, 113,  27 },  {  -43,  81,  85,  28 },  {  -35,  68,  50,  35 },  {  -48,  93,   0,  50 } } },  /* 7: DASH HUMIKOMI */
    { { {  -50,  41, 108,  20 },  {  -51,  77,  82,  26 },  {  -51,  81,  52,  30 },  {  -53,  88,   0,  52 } } },  /* 8: S PUNCH A */
    { { {  -24,  41, 108,  34 },  {  -55,  81,  82,  26 },  {  -56,  86,  52,  30 },  {  -57,  89,   0,  52 } } },  /* 9: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -50,  41,  90,  35 },  {  -55,  81,  82,  26 },  {  -56,  86,  52,  30 },  {  -57,  89,   0,  52 } } },  /* 10: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP), ZANNEN 3 */
    { { {  -12,  57, 108,  20 },  {  -31,  82,  82,  26 },  {  -46,  81,  52,  30 },  {  -48,  88,   0,  52 } } },  /* 11: M KICK A */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 12: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2 */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 13: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2 */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 14: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2 */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 15: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2 */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 16: not used by a script */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 17: not used by a script */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 18: not used by a script */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 19: not used by a script */
    { { {   -3,  41, 107,  20 },  {  -38,  85,  81,  26 },  {  -38,  93,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 20: not used by a script */
    { { {  -40,  41, 107,  20 },  {  -46,  87,  81,  26 },  {  -42,  80,  51,  30 },  {  -48,  88,   0,  52 } } },  /* 21: not used by a script */
    { { {   -2,  41, 114,  20 },  {  -43, 106,  88,  26 },  {  -40,  64,  58,  30 },  {  -48,  88,   0,  52 } } },  /* 22: not used by a script */
    { { {  -57,  41,  82,  22 },  {  -41,  71,  45,  49 },  {    0,   0,   0,   0 },  {  -50,  90,   0,  45 } } },  /* 23: not used by a script */
    { { {    1,  41, 108,  22 },  {  -31,  83,  84,  37 },  {  -49,  81,  63,  40 },  {  -66,  72,  47,  38 } } },  /* 24: L KICK A */
    { { {   30,  30,  70,  22 },  {  -21,  77,  50,  26 },  {  -68,  99,  63,  40 },  {  -66,  66,  47,  27 } } },  /* 25: L KICK A */
    { { {    0,   0,   0,   0 },  {  -24,  96,   0,  54 },  {    0,   0,   0,   0 },  {  -83,  59,   0,  42 } } },  /* 26: L KICK A, follow-up of APPEAR JUNBI 7 */
    { { {  -13,  39,  79,  27 },  {  -49,  84,  53,  28 },  {  -43,  71,  30,  23 },  {  -55,  94,   0,  30 } } },  /* 27: PIYO */
    { { {  -56,  48,  54,  24 },  {    0,   0,   0,   0 },  {  -64,  95,   0,  62 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { {  -60,  43,  27,  34 },  {    0,   0,   0,   0 },  {  -46,  93,   0,  74 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI P A */
    { { {  -68,  70,  72,  25 },  {  -56,  75,  51,  36 },  {  -48,  85,  41,  30 },  {  -15,  80,  16,  25 } } },  /* 30: KAGAMI P A */
    { { {  -70,  48,  69,  36 },  {  -63,  83,  45,  44 },  {  -40,  79,  31,  44 },  {  -16,  79,  17,  33 } } },  /* 31: KAGAMI P A */
    { { {  -76,  45,  67,  32 },  {  -61,  94,  50,  40 },  {  -43,  68,  36,  30 },  {   15,  58,  28,  46 } } },  /* 32: KAGAMI P A */
    { { {  -85,  43,  10,  26 },  {  -66,  93,  17,  42 },  {    0,   0,   0,   0 },  {    1,  49,  25,  48 } } },  /* 33: not used by a script */
    { { {  -28,  43,  71,  22 },  {  -60, 106,  51,  33 },  {  -30,  72,  33,  18 },  {  -32,  79,   0,  33 } } },  /* 34: KAGAMI K A */
    { { {  -40,  55,  71,  22 },  {  -60, 106,  47,  35 },  {  -26,  73,  27,  20 },  {   -3,  65,   0,  27 } } },  /* 35: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {  -40, 116,  46,  47 },  {    0,   0,   0,   0 },  {  -31,  63,  32,  14 } } },  /* 36: KAGAMI K A */
    { { {  -43,  36,  75,  28 },  {  -27,  64,  57,  44 },  {  -11,  63,  44,  45 },  {  -20,  63,  28,  16 } } },  /* 37: AIR NORMAL, TTKI V. AIR, BODY SLAM +11 */
    { { {   -9,  41, 128,  22 },  {  -31,  75,  95,  33 },  {  -33,  91,  69,  26 },  {  -37,  72,  46,  23 } } },  /* 38: V JUMP K S A, ATTACK 10 S: not started by a command, V JUMP K M A */
    { { {  -14,  50, 127,  22 },  {  -34,  76,  97,  38 },  {  -39,  71,  71,  26 },  {  -46,  78,  44,  27 } } },  /* 39: V JUMP K L A */
    { { {  -10,  60, 122,  24 },  {  -35,  91,  90,  33 },  {  -54,  92,  64,  26 },  {  -59,  80,  48,  16 } } },  /* 40: V JUMP K L A */
    { { {  -10,  60, 130,  22 },  {  -45, 106, 101,  36 },  {  -59, 107,  63,  41 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K L A */
    { { {  -19,  52, 116,  22 },  {  -40, 106,  93,  33 },  {  -38, 108,  58,  35 },  {  -76,  38,  59,  51 } } },  /* 42: V JUMP K L A */
    { { {   21,  45,  94,  38 },  {  -32,  93,  54,  73 },  {  -60,  46,  56,  53 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP K L A */
    { { {   18,  46, 103,  34 },  {  -33,  92,  54,  71 },  {  -48,  46,  46,  59 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP K L A */
    { { {  -29,  41, 122,  22 },  {  -45,  85,  96,  35 },  {  -38,  72,  70,  26 },  {  -34,  65,  49,  21 } } },  /* 45: V JUMP P L A */
    { { {  -50,  41, 115,  26 },  {  -47,  79,  97,  31 },  {  -38,  67,  67,  30 },  {  -36,  74,  37,  30 } } },  /* 46: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) */
    { { {  -50,  41, 115,  26 },  {  -55,  99,  97,  31 },  {  -49,  84,  67,  31 },  {  -26,  77,  37,  30 } } },  /* 47: ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN), ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -45,  90,  42,  25 },  {  -51,  96,  24,  18 },  {  -53,  99,   0,  24 } } },  /* 48: follow-up of SP APPEAR 7 */
    { { {  -46,  41, 112,  28 },  {  -68, 109,  96,  35 },  {  -38,  72,  70,  26 },  {  -31,  74,  33,  37 } } },  /* 49: V JUMP P L B */
    { { {  -40,  41, 118,  25 },  {  -45,  85,  96,  26 },  {  -38,  72,  58,  38 },  {  -28,  82,  31,  28 } } },  /* 50: V JUMP P L B */
    { { {  -68,  59,  95,  34 },  {  -63,  81,  79,  37 },  {  -78, 118,  66,  41 },  {    0,   0,   0,   0 } } },  /* 51: V JUMP P L B */
    { { {  -28,  41, 111,  26 },  {  -32,  56,  94,  30 },  {  -27,  58,  71,  23 },  {  -31,  65,  47,  24 } } },  /* 52: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -34,  64,  78,  19 },  {  -30,  67,  61,  26 },  {  -24,  71,  43,  25 } } },  /* 53: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN), ATTACK 7 M: SA II 23623+K medium (routine Att_SHOURYUUKEN), ATTACK 7 L: SA II 23623+K heavy/EX (routine Att_SHOURYUUKEN) */
    { { {  -24,  59,  95,  23 },  {  -34,  80,  73,  26 },  {  -34,  81,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 54: S KICK A */
    { { {  -27,  64,  67,  20 },  {  -45,  90,  42,  25 },  {  -51,  96,  24,  18 },  {  -53,  99,   0,  24 } } },  /* 55: KAGAMI K A */
    { { {  -12,  57, 108,  20 },  {  -31,  82,  82,  26 },  {  -46,  81,  52,  30 },  {  -35,  75,   0,  52 } } },  /* 56: M KICK A */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  54 },  {    0,   0,   0,   0 },  {   16,  59,   0,  42 } } },  /* 57: L KICK A, follow-up of APPEAR JUNBI 7 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 58: no name */
    { { {  -12,  46, 108,  20 },  {  -32,  93,  82,  30 },  {  -43,  79,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 59: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { { {  -63,  51,  90,  29 },  {  -72,  95,  75,  35 },  {  -65, 100,  52,  30 },  {  -54, 109,   0,  52 } } },  /* 60: ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 6 S: SA I 720+P (plain script) +3 */
    { { {  -66,  51,  72,  28 },  {  -75,  96,  57,  34 },  {  -68, 106,  38,  36 },  {  -54, 109,   0,  52 } } },  /* 61: ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script), ATTACK 6 S: SA I 720+P (plain script) +3 */
    { { {  -49,  44,  94,  29 },  {  -60,  90,  65,  44 },  {  -43,  79,  52,  30 },  {  -43,  82,   0,  52 } } },  /* 62: ATTACK 9 M: not started by a command */
    { { {  -59,  42,  84,  25 },  {  -65,  87,  66,  29 },  {  -68,  99,  41,  30 },  {  -52,  90,   0,  52 } } },  /* 63: ATTACK 9 M: not started by a command */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  66 },  {    0,   0,   0,   0 },  {   16,  59,   0,  48 } } },  /* 64: follow-up of APPEAR JUNBI 7 */
    { { {    0,   0,   0,   0 },  {  -80,  96,   0,  70 },  {    0,   0,   0,   0 },  {   16,  59,   0,  56 } } },  /* 65: follow-up of APPEAR JUNBI 7 */
    { { {  -10,  44,-110,  22 },  {  -26,  80,  82,  32 },  {  -58, 116,  66,  28 },  {  -34,  76,  46,  24 } } },  /* 66: ATTACK 10 S: not started by a command */
    { { {   -4,  39, 113,  27 },  {  -30,  70,  83,  26 },  {  -34,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 67: UPPER L */
    { { {    4,  39, 112,  27 },  {  -27,  70,  83,  26 },  {  -35,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 68: UPPER L */
    { { {    8,  39, 111,  27 },  {  -25,  70,  83,  26 },  {  -36,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 69: UPPER L */
    { { {   10,  39, 110,  27 },  {  -24,  70,  83,  26 },  {  -37,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 70: UPPER L */
    { { {   -4,  39, 107,  27 },  {  -26,  70,  82,  26 },  {  -29,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 71: FACE S, FACE M, FACE L +5 */
    { { {    8,  39, 105,  27 },  {  -20,  70,  81,  26 },  {  -26,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 72: FACE M, FACE L, FOOK OKU L +1 */
    { { {   16,  39, 103,  27 },  {  -16,  70,  80,  26 },  {  -24,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 73: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {   20,  39, 101,  27 },  {  -14,  70,  79,  26 },  {  -23,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 74: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {  -24,  39, 106,  27 },  {  -32,  70,  81,  26 },  {  -31,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 75: NOUTEN S, NOUTEN M, NOUTEN L +2 */
    { { {  -28,  39, 103,  27 },  {  -30,  70,  79,  26 },  {  -29,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 76: NOUTEN M, NOUTEN L, BODY BROW L +1 */
    { { {  -32,  39, 100,  27 },  {  -28,  70,  77,  26 },  {  -27,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 77: NOUTEN L, BODY BROW L, BODY UPPER L */
    { { {  -36,  39,  97,  27 },  {  -26,  70,  75,  26 },  {  -25,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 78: NOUTEN L, BODY BROW L, BODY UPPER L +4 */
    { { {  -28,  38,  71,  25 },  {  -33,  69,  53,  24 },  {  -37,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 79: KAGAMI S, KAGAMI M, KAGAMI L +7 */
    { { {  -22,  38,  71,  25 },  {  -31,  69,  53,  24 },  {  -36,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 80: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    { { {  -16,  38,  71,  25 },  {  -29,  69,  53,  24 },  {  -35,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 81: KAGAMI L */
    { { {  -10,  38,  71,  25 },  {  -27,  69,  53,  24 },  {  -34,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 82: KAGAMI L */
    { { {  -16,  38, 133,  24 },  {  -37,  67,  97,  37 },  {  -38,  65,  68,  41 },  {  -23,  66,  49,  29 } } },  /* 83: CATCH 38, CATCH 39, CATCH 40 */
    { { {   -5,  39, 109,  27 },  {  -34,  73,  83,  26 },  {  -36,  69,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 84: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    { { {  -26,  42, 109,  27 },  {  -34,  70,  83,  26 },  {  -33,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 85: KAMAE */
    { { {  -13,  36, 109,  27 },  {  -30,  70,  83,  26 },  {  -33,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 86: KAMAE */
    { { {  -11,  39, 113,  27 },  {  -29,  70,  88,  30 },  {  -27,  67,  47,  40 },  {  -37,  81,   0,  46 } } },  /* 87: HURIMUKI */
    { { {  -17,  39, 113,  27 },  {  -31,  70,  85,  28 },  {  -33,  67,  47,  37 },  {  -42,  81,   0,  46 } } },  /* 88: HURIMUKI */
    { { {  -21,  39, 114,  27 },  {  -31,  71,  83,  30 },  {  -30,  63,  47,  35 },  {  -33,  63,   0,  46 } } },  /* 89: FRONT WALK */
    { { {  -23,  39, 112,  27 },  {  -34,  66,  83,  28 },  {  -37,  67,  50,  33 },  {  -47,  89,   0,  50 } } },  /* 90: FRONT WALK */
    { { {  -21,  39, 114,  27 },  {  -32,  75,  83,  30 },  {  -30,  63,  47,  35 },  {  -33,  63,   0,  46 } } },  /* 91: BACK WALK */
    { { {  -22,  39, 112,  27 },  {  -32,  70,  83,  28 },  {  -34,  68,  50,  33 },  {  -47,  89,   0,  50 } } },  /* 92: BACK WALK */
    { { {  -24,  39, 109,  27 },  {  -34,  70,  83,  26 },  {  -33,  67,  47,  35 },  {  -42,  81,   0,  46 } } },  /* 93: JUMP JUNBI, SP JUMP JUNBI, DASH HUMIKOMI +5 */
    { { {  -23,  38,  76,  25 },  {  -33,  71,  53,  24 },  {  -36,  76,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 94: DASH HUMIKOMI, DASH TOBINOKI, follow-up of APPEAR 8 +3 */
    { { {  -18,  39, 117,  27 },  {  -36,  88,  92,  30 },  {  -44,  65,  60,  31 },  {  -61,  76,   0,  60 } } },  /* 95: DASH TOBINOKI */
    { { {  -22,  39, 118,  27 },  {  -38,  88,  92,  28 },  {  -48,  65,  64,  28 },  {  -68,  76,   0,  64 } } },  /* 96: DASH TOBINOKI */
    { { {  -34,  39, 121,  27 },  {  -42,  79,  92,  28 },  {  -39,  63,  60,  32 },  {  -46,  72,   0,  60 } } },  /* 97: DASH TOBINOKI */
    { { {   -3,  38,  71,  25 },  {  -34,  69,  53,  24 },  {  -39,  78,  28,  24 },  {  -40,  92,   0,  27 } } },  /* 98: KAGAMI TURN */
    { { {   -3,  38,  72,  25 },  {  -35,  69,  53,  26 },  {  -39,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 99: KAGAMI TURN */
    { { {  -31,  38,  77,  25 },  {  -35,  69,  53,  26 },  {  -38,  78,  28,  24 },  {  -51,  92,   0,  27 } } },  /* 100: KAGAMI TURN */
    { { {  -17,  39, 131,  27 },  {  -30,  67, 102,  28 },  {  -28,  60,  71,  30 },  {  -26,  55,  46,  24 } } },  /* 101: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    { { {  -34,  39, 128,  27 },  {  -30,  67, 102,  28 },  {  -30,  60,  71,  30 },  {  -33,  59,  49,  24 } } },  /* 102: JUMP FRONT, JUMP VERTICAL, JUMP BACK +1 */
    { { {  -28,  39, 127,  27 },  {  -30,  69, 102,  28 },  {  -34,  63,  79,  25 },  {  -50,  81,  54,  28 } } },  /* 103: JUMP FRONT, JUMP VERTICAL, JUMP BACK +2 */
    { { {  -22,  39, 131,  27 },  {  -30,  68, 102,  28 },  {  -31,  60,  74,  27 },  {  -41,  72,  49,  25 } } },  /* 104: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -17,  39, 131,  27 },  {  -30,  67, 102,  28 },  {  -28,  58,  71,  30 },  {  -33,  59,  46,  24 } } },  /* 105: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -52,  34,  96,  26 },  {  -35,  49,  82,  42 },  {  -27,  52,  73,  42 },  {  -55,  67,  45,  30 } } },  /* 106: AIR NORMAL */
    { { {  -42,  34, 105,  26 },  {  -42,  52,  73,  36 },  {  -28,  51,  57,  43 },  {  -27,  55,  30,  39 } } },  /* 107: ASIBARAI SIRI, HUMI ASIB */
    { { {  -60,  34,  91,  26 },  {  -63,  76,  75,  28 },  {  -49,  80,  62,  30 },  {    1,  38,  48,  32 } } },  /* 108: ASIBARAI SIRI, TTKI V. AIR */
    { { {  -58,  34,  93,  26 },  {  -57,  58,  79,  29 },  {  -53,  62,  60,  25 },  {  -26,  61,  54,  29 } } },  /* 109: ASIBARAI SIRI */
    { { {  -62,  34,  95,  26 },  {  -58,  51,  77,  28 },  {  -54,  60,  61,  35 },  {  -33,  65,  56,  35 } } },  /* 110: ASIBARAI SIRI */
    { { {  -66,  34,  74,  26 },  {  -55,  49,  64,  27 },  {  -43,  55,  52,  36 },  {    4,  35,  61,  33 } } },  /* 111: ASIBARAI SIRI, TTKI V. AIR, HUMI ASIB */
    { { {   24,  34, 109,  26 },  {   -7,  66,  77,  39 },  {  -32,  61,  68,  30 },  {  -51,  60,  57,  28 } } },  /* 112: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   48,  34,  88,  26 },  {   19,  37,  68,  48 },  {   -6,  25,  68,  45 },  {  -43,  50,  57,  41 } } },  /* 113: NOKEZORI, KIRIMOMI, UPPER +6 */
    { { {   52,  34,  77,  26 },  {   15,  37,  62,  49 },  {   -7,  33,  68,  45 },  {  -40,  39,  55,  46 } } },  /* 114: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   52,  34,  71,  26 },  {   15,  37,  59,  51 },  {   -3,  31,  61,  52 },  {  -37,  34,  56,  48 } } },  /* 115: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   52,  34,  71,  26 },  {   15,  37,  57,  53 },  {   -3,  31,  59,  53 },  {  -35,  32,  59,  45 } } },  /* 116: NOKEZORI, KIRIMOMI, UPPER +6 */
    { { {   52,  34,  60,  26 },  {   16,  39,  58,  40 },  {   -6,  43,  58,  50 },  {  -35,  29,  71,  33 } } },  /* 117: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   40,  34,  41,  26 },  {   16,  40,  44,  37 },  {   -9,  51,  49,  39 },  {  -35,  36,  63,  34 } } },  /* 118: NOKEZORI, KIRIMOMI, UPPER +6 */
    { { {   41,  34,  32,  26 },  {   22,  42,  41,  36 },  {   -3,  47,  47,  36 },  {  -19,  44,  64,  32 } } },  /* 119: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {  -50,  34, 105,  26 },  {  -45,  53,  80,  34 },  {  -39,  60,  69,  35 },  {  -21,  61,  38,  43 } } },  /* 120: KUNOJI, HARAYARARE, KUNOJI NOKE +1 */
    { { {  -58,  34,  88,  26 },  {  -47,  61,  69,  35 },  {  -37,  68,  60,  34 },  {  -22,  64,  45,  37 } } },  /* 121: KUNOJI, HARAYARARE, KUNOJI NOKE +1 */
    { { {  -58,  34,  84,  26 },  {  -47,  61,  69,  35 },  {  -31,  62,  60,  38 },  {  -25,  64,  46,  40 } } },  /* 122: KUNOJI, HARAYARARE, KUNOJI NOKE */
    { { {  -56,  34,  77,  26 },  {  -44,  64,  68,  33 },  {  -26,  59,  58,  36 },  {  -24,  63,  42,  40 } } },  /* 123: KUNOJI, HARAYARARE, KUNOJI NOKE */
    { { {  -57,  34,  65,  26 },  {  -37,  53,  65,  32 },  {  -30,  59,  57,  33 },  {  -22,  60,  40,  41 } } },  /* 124: KUNOJI */
    { { {  -62,  34,  44,  26 },  {  -39,  53,  56,  29 },  {  -24,  68,  56,  33 },  {  -28,  69,  39,  28 } } },  /* 125: KUNOJI */
    { { {  -68,  34,  46,  26 },  {  -42,  52,  42,  39 },  {    0,  45,  55,  33 },  {   -8,  58,  37,  37 } } },  /* 126: KUNOJI */
    { { {  -72,  34,  51,  26 },  {  -53,  66,  40,  39 },  {  -16,  49,  58,  32 },  {   13,  32,  41,  37 } } },  /* 127: KUNOJI */
    { { {  -25,  34, 118,  26 },  {  -23,  51,  75,  45 },  {  -28,  51,  57,  35 },  {  -33,  49,  39,  20 } } },  /* 128: UPPER, TATUMAKIZANKU */
    { { {  -15,  34, 120,  26 },  {   -9,  40,  83,  46 },  {  -27,  38,  57,  59 },  {  -36,  48,  43,  59 } } },  /* 129: UPPER, TATUMAKIZANKU */
    { { {   14,  34, 117,  26 },  {  -29,  60,  86,  38 },  {  -41,  37,  58,  59 },  {  -50,  49,  49,  59 } } },  /* 130: UPPER, TATUMAKIZANKU */
    { { {   23,  34, 110,  26 },  {  -29,  70,  80,  38 },  {  -42,  44,  63,  40 },  {  -50,  49,  53,  31 } } },  /* 131: UPPER, TATUMAKIZANKU */
    { { {  -42,  34,  88,  26 },  {  -33,  54,  65,  40 },  {  -19,  54,  53,  44 },  {  -26,  68,  34,  47 } } },  /* 132: BODY UPPER */
    { { {  -63,  34,  65,  26 },  {  -48,  57,  57,  39 },  {   -1,  42,  65,  37 },  {  -24,  56,  47,  29 } } },  /* 133: BODY UPPER, TTKI V. AIR */
    { { {  -64,  34,  62,  26 },  {  -42,  56,  66,  31 },  {  -25,  55,  66,  37 },  {  -30,  66,  55,  38 } } },  /* 134: BODY UPPER */
    { { {  -60,  34,  80,  26 },  {  -37,  51,  76,  34 },  {  -24,  49,  66,  33 },  {  -38,  66,  52,  17 } } },  /* 135: BODY UPPER */
    { { {  -56,  34,  86,  26 },  {  -36,  48,  82,  34 },  {  -27,  49,  76,  32 },  {  -46,  72,  60,  16 } } },  /* 136: BODY UPPER */
    { { {  -52,  34,  93,  26 },  {  -32,  43,  89,  33 },  {  -27,  50,  75,  39 },  {  -52,  65,  56,  20 } } },  /* 137: BODY UPPER */
    { { {    6,  34, 124,  26 },  {  -34,  72, 106,  27 },  {  -32,  75,  86,  35 },  {  -38,  66,  42,  44 } } },  /* 138: DENKI */
    { { {  -17,  34, 112,  26 },  {   -9,  38,  75,  44 },  {  -20,  53,  62,  44 },  {  -36,  66,  38,  24 } } },  /* 139: TOUKETSU A */
    { { {  -19,  39, 112,  27 },  {  -21,  53,  97,  32 },  {  -25,  51,  73,  29 },  {  -31,  53,  52,  23 } } },  /* 140: ATTACK 7 S: SA II 23623+K light (routine Att_SHOURYUUKEN) */
    { { {  -32,  38,  92,  22 },  {  -30,  69,  80,  26 },  {  -38,  78,  42,  36 },  {  -50,  92,   0,  40 } } },  /* 141: follow-up of APPEAR JUNBI 2 */
};

const HAND_BOX hugo_hand_box[51] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -130,  84,  60,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { { -124,  74,  60,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { { -120,  74,  60,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A */
    { { { -106,  74,  64,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: M PUNCH A */
    { { { -111,  80,  64,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: M PUNCH A */
    { { {  -68,  45,  96,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -77,  45,  64,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: L PUNCH A, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -86,  37,  59,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: L PUNCH A, ZANNEN 3, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -68, 133,  91,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L PUNCH B */
    { { {  -28, 133,  91,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: L PUNCH B */
    { { {  -66,  44,  53,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -82,  57,  86,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -97,  70,  83,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -60,  45,  82,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH B, ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { { { -103,  63,  23,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: S KICK A */
    { { {  -94,  63,  69,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M KICK A */
    { { { -102,  72,  69,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: M KICK A */
    { { { -102,  72,  69,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: M KICK A */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: M KICK A, ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script) +3 */
    { { {  -94,  59,  39,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +2 */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: not used by a script */
    { { { -101,  61,  39,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -81,  41,  45,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: not used by a script */
    { { { -101,  61,  39,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: not used by a script */
    { { { -105,  57,  50,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: L KICK A */
    { { {  -87,  38,  73,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: L KICK A */
    { { { -118,  81,  27,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A */
    { { { -122,  82,  27,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { { -133,  96,  27,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: not used by a script */
    { { { -107,  79,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI K A */
    { { { -116,  95,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI K A */
    { { { -120,  96,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: KAGAMI K A */
    { { { -116,  84,  79,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP P S A, V JUMP P M A */
    { { { -108,  76,  84,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP P S A, V JUMP P M A */
    { { { -101,  74,  95,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P S A, V JUMP P M A */
    { { { -108,  76,  93,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P L A */
    { { {  -69,  51,  50,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP K S A, V JUMP K M A */
    { { {  -59,  41,  52,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP K M A */
    { { {  -89,  29,  60,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K L A */
    { { { -104,  43,  52,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K L A */
    { { { -104,  47,  52,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K L A */
    { { {  -96,  48,  44,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP K L A */
    { { {  -69,  24,  94,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP P L A */
    { { { -104,  79,  82,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +2 */
    { { {  -65,  37,  59,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { { {  -83,  53, 109,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP P L B */
    { { {  -93,  54,  92,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP P L B */
    { { { -104,  80,  96,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: ATTACK 9 M: not started by a command */
    { { {  -58,  43,  82,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 2 S: 236+K light (routine Att_CHOUCHUURENGEKI), ATTACK 2 M: 236+K medium (routine Att_CHOUCHUURENGEKI), ATTACK 2 L: 236+K heavy (routine Att_CHOUCHUURENGEKI) +3 */
    { { {  -78,  44,  48,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 10 S: not started by a command */
};

const HOSEI_BOX hugo_hos_box[16] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -30,   60,    0,  101 } },  /* 1: KAMAE, DASH HUMIKOMI, DASH TOBINOKI +96 */
    { {  -30,   60,    0,   66 } },  /* 2: KAGAMI KAMAE, PARING DOWN, GUARD DOWN +55 */
    { {  -27,   54,   63,   58 } },  /* 3: GUARD AIR, V JUMP P S A, V JUMP P M A +30 */
    { {  -30,   60,    0,   82 } },  /* 4: DASH HUMIKOMI, DASH TOBINOKI, follow-up of APPEAR 8 +3 */
    { {  -41,   67,    0,   98 } },  /* 5: DASH HUMIKOMI */
    { {  -44,   67,    0,   98 } },  /* 6: not used by a script */
    { {  -30,   60,    0,   74 } },  /* 7: PIYO, ATTACK 3 S: 360+P light (plain script), ATTACK 4 S: 6(123)4+K light (plain script) +5 */
    { {  -41,   66,   34,   50 } },  /* 8: KAGAMI P A, KAGAMI K A */
    { {  -27,   54,   34,   58 } },  /* 9: AIR NORMAL, TTKI V. AIR, BODY SLAM +27 */
    { {  -51,   81,   77,   41 } },  /* 10: V JUMP P L B */
    { {  -38,   74,    0,   98 } },  /* 11: ATTACK 1 S: 214+P light (plain script), ATTACK 1 M: 214+P medium (plain script), ATTACK 1 L: 214+P heavy (plain script) +1 */
    { {  -22,   50,   63,   58 } },  /* 12: ATTACK 5 S: 623+K light (routine Att_SHOURYUUKEN), ATTACK 5 M: 623+K medium (routine Att_SHOURYUUKEN), ATTACK 5 L: 623+K heavy/EX (routine Att_SHOURYUUKEN) +3 */
    { {  -22,   68,    0,   98 } },  /* 13: ATTACK 9 S: after SA III 23623+P (routine Att_SLIDE_and_JUMP) */
    { {  -62,   92,    0,  101 } },  /* 14: ATTACK 11 S: 360+K light (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 M: 360+K medium (routine Att_PL06_HASHIRI_NAGE), ATTACK 11 L: 360+K heavy/EX (routine Att_PL06_HASHIRI_NAGE) */
    { {  -30,   60,    0,   88 } },  /* 15: UPPER L, FACE S, FACE M +16 */
};
