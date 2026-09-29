/*
 * GOUKI1_HITBOX.C  Gouki's hit boxes
 *
 * Each of Gouki's animation frames names an entry of gouki1_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX gouki1_hit_ix_table[281] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +19 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +96 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +24 */
    {    3,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    {    4,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +29 */
    {    5,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 5: JUMP JUNBI, SP JUMP JUNBI */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 6: DASH TOBINOKI, follow-up of APPEAR JUNBI 1, follow-up of SP WIN 1 +5 */
    {    6,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 7: not used by a script */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: not used by a script */
    {    8,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 9: PARING HEAD */
    {    9,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 10: PARING HEAD */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 11: NEKOROBI S, no name, HANEAGARI +4 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 12: OKIAGARI, OKIAGARI F, OKIAGARI B +13 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 13: not used by a script */
    {   10,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 14: not used by a script */
    {   11,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 15: S V JP S P A, S V JP L P A, S V JP M K A */
    {   12,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 16: GUARD AIR, no name */
    {   13,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 17: no name */
    {   14,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 18: no name */
    {    1,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 19: S PUNCH A */
    {    1,    0,    1, 0x0000,    0,    1,    2,    1 },  /* 20: S PUNCH A */
    {    1,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 21: S PUNCH A */
    {    1,    0,    2, 0x0000,    0,    1,    3,    1 },  /* 22: S PUNCH B */
    {    1,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 23: S PUNCH B */
    {    1,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 24: M PUNCH A */
    {    1,    0,    3, 0x0000,    0,    1,    5,    1 },  /* 25: M PUNCH B, S V JP S P A */
    {    1,    0,    3, 0x0000,    0,    1,    6,    1 },  /* 26: M PUNCH B */
    {    1,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 27: M PUNCH B */
    {    1,    0,    0, 0x0000,    2,    1,    0,    1 },  /* 28: not used by a script */
    {   15,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 29: follow-up of ATTACK 11 S, ATTACK 11 S: not started by a command, ATTACK 13 S: 3214+P light (plain script) +2 */
    {   40,    0,   36, 0x0000,    0,    3,   68,    3 },  /* 30: ATTACK 9 S: not started by a command */
    {   16,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,    9,    1 },  /* 32: L PUNCH A */
    {   16,    0,    0, 0x0000,    0,    1,   10,    1 },  /* 33: L PUNCH A */
    {   16,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH A */
    {   41,    0,   29, 0x0000,    0,    3,    0,    3 },  /* 35: F JUMP K M B */
    {   41,    0,   29, 0x0000,    0,    3,   69,    3 },  /* 36: F JUMP K M B */
    {   18,    0,    6, 0x0000,    0,    5,   12,    1 },  /* 37: S KICK A */
    {   18,    0,    6, 0x0000,    0,    5,    0,    1 },  /* 38: S KICK A */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 39: not used by a script */
    {   19,    0,    0, 0x0000,    0,    1,   13,    1 },  /* 40: not used by a script */
    {   19,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 41: not used by a script */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: M KICK B */
    {   21,    0,    0, 0x0000,    0,    1,   14,    1 },  /* 43: M KICK B */
    {   21,    0,    0, 0x0000,    0,    1,   15,    1 },  /* 44: M KICK B */
    {   21,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 45: M KICK B */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 46: L KICK B */
    {   22,    0,    9, 0x0000,    0,    1,   16,    1 },  /* 47: L KICK B */
    {   22,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 48: L KICK B */
    {    5,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 49: ATTACK 9 S: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,   30,    1 },  /* 50: ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
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
    {   27,    0,   19, 0x0000,    0,    1,    0,    5 },  /* 75: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +5 */
    {   17,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 76: L PUNCH B, follow-up of M PUNCH A */
    {   17,    0,    4, 0x0000,    0,    1,   11,    5 },  /* 77: L PUNCH B, follow-up of M PUNCH A */
    {   17,    0,    4, 0x0000,    0,    1,    0,    5 },  /* 78: L PUNCH B, follow-up of M PUNCH A */
    {   30,    0,    0, 0x0000,    0,    0,   31,    1 },  /* 79: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   31,    1 },  /* 80: ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    {   30,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 81: not used by a script */
    {   30,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 82: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    {   31,    0,    0, 0x0000,    0,    3,   33,    3 },  /* 83: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    {   31,    0,   23, 0x0000,    0,    3,   34,    3 },  /* 84: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    {   32,    0,   23, 0x0000,    0,    3,   35,    3 },  /* 85: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) */
    {   32,    0,   23, 0x0000,    0,    3,    0,    3 },  /* 86: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) */
    {   32,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 87: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 88: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   32,    1 },  /* 89: not used by a script */
    {   28,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 90: M PUNCH C */
    {   29,    0,   21, 0x0000,    0,    0,    7,    5 },  /* 91: M PUNCH C */
    {   29,    0,   20, 0x0000,    0,    0,    8,    5 },  /* 92: M PUNCH C */
    {   29,    0,   20, 0x0000,    0,    0,    0,    5 },  /* 93: M PUNCH C */
    {   81,   41,    0, 0x0000,    2,    1,    0,    1 },  /* 94: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,    3,    0,    0,    1 },  /* 95: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 96: follow-up of AIR NORMAL, SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 97: TUKAMIKAKARI A */
    {   26,    0,   24, 0x0000,    0,    3,   40,    3 },  /* 98: F JUMP P L A */
    {   26,    0,   24, 0x0000,    0,    3,   41,    3 },  /* 99: F JUMP P L A, S V JP S P A */
    {    4,    0,    0, 0x0000,    0,    3,   42,    3 },  /* 100: S V JP S P A */
    {    4,    0,    0, 0x0000,    0,    3,   43,    3 },  /* 101: S V JP M P A, S V JP M K A */
    {    4,    0,   25, 0x0000,    0,    3,   43,    3 },  /* 102: not used by a script */
    {    4,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 103: not used by a script */
    {    4,    0,    0, 0x0000,    0,    3,   44,    3 },  /* 104: V JUMP P L A, S V JP M K A */
    {    4,    0,    0, 0x0000,    0,    3,   45,    3 },  /* 105: V JUMP P L A, S V JP M K A */
    {    4,    0,   26, 0x0000,    0,    3,    0,    3 },  /* 106: V JUMP P L A */
    {    4,    0,    0, 0x0000,    0,    3,   46,    3 },  /* 107: V JUMP K S A, F JUMP K S A */
    {    4,    0,    0, 0x0000,    0,    3,   47,    3 },  /* 108: V JUMP K S A, F JUMP K S A, S V JP S K A */
    {   33,    0,    0, 0x0000,    0,    3,   48,    3 },  /* 109: V JUMP K M A, S V JP S K A */
    {   33,    0,   27, 0x0000,    0,    3,   49,    3 },  /* 110: V JUMP K M A */
    {   33,    0,   27, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP K M A, S V JP L K A */
    {    4,    0,   28, 0x0000,    0,    3,   50,    3 },  /* 112: V JUMP K L A */
    {    4,    0,   28, 0x0000,    0,    3,   51,    3 },  /* 113: V JUMP K L A, S V JP M P A */
    {    4,    0,   28, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP K L A */
    {   34,    0,   30, 0x0000,    0,    3,   52,    3 },  /* 115: F JUMP K M A */
    {   34,    0,   31, 0x0000,    0,    3,   53,    3 },  /* 116: F JUMP K M A */
    {   34,    0,   32, 0x0000,    0,    3,    0,    3 },  /* 117: F JUMP K M A, F JUMP K L A */
    {   34,    0,   33, 0x0000,    0,    3,   54,    3 },  /* 118: F JUMP K L A */
    {   34,    0,   34, 0x0000,    0,    3,   55,    3 },  /* 119: F JUMP K L A */
    {   35,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 120: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    {   36,    0,   35, 0x0000,    0,    3,   56,    3 },  /* 121: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    {   36,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 122: ATTACK 8 S: air 214+K light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 M: air 214+K medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 8 L: air 214+K heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) */
    {   37,    0,   35, 0x0000,    0,    3,   57,    3 },  /* 123: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    {   37,    0,   35, 0x0000,    0,    3,    0,    3 },  /* 124: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    {   38,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 125: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +1 */
    {   39,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 126: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 127: (never)+K light (routine Att_SLIDE_and_JUMP) */
    {   45,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 128: (never)+K light (routine Att_SLIDE_and_JUMP) */
    {   46,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 129: (never)+K light (routine Att_SLIDE_and_JUMP) */
    {   47,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 130: (never)+K light (routine Att_SLIDE_and_JUMP), (never)+K medium (routine Att_SLIDE_and_JUMP), (never)+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 131: S V JP M P A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 132: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 133: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 134: follow-up of ATTACK 4 S, ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN) +6 */
    {    0,    0,    0, 0x0000,    0,    0,   36,    1 },  /* 135: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   37,    1 },  /* 136: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {    0,    0,    0, 0x0000,    0,    0,   38,    3 },  /* 137: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 138: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,   36,    1 },  /* 139: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   30,    0,    0, 0x0000,    0,    1,   37,    1 },  /* 140: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   31,    0,    0, 0x0000,    0,    3,   38,    3 },  /* 141: ATTACK 5 S: SA II 23623+P (routine Att_SHOURYUUREPPA) */
    {   31,    0,   23, 0x0000,    0,    3,   39,    3 },  /* 142: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   58,    1 },  /* 143: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 144: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN) */
    {   42,    0,    0, 0x0000,    0,    3,   59,    3 },  /* 145: S V JP L K A, ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   42,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 146: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   43,    0,   37, 0x0000,    0,    3,   60,    3 },  /* 147: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   44,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 148: not used by a script */
    {   42,    0,    0, 0x0000,    0,    3,   61,    3 },  /* 149: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 150: L KICK A */
    {   48,    0,    0, 0x0000,    0,    1,   62,    1 },  /* 151: L KICK A */
    {   48,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 152: L KICK A */
    {   49,    0,   39, 0x0000,    0,    1,   63,    1 },  /* 153: L KICK A */
    {   49,    0,   40, 0x0000,    0,    1,   64,    1 },  /* 154: L KICK A */
    {   50,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 155: L KICK A */
    {   51,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 156: KAMAE */
    {   52,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 157: KAMAE */
    {   53,    0,    0, 0x1914,    0,    1,    0,    1 },  /* 158: FRONT WALK */
    {   54,    0,    0, 0x1A16,    0,    1,    0,    1 },  /* 159: FRONT WALK, S V JP L P A */
    {   55,    0,    0, 0x1519,    0,    1,    0,    1 },  /* 160: BACK WALK, S V JP L P A */
    {   56,    0,    0, 0x1A19,    0,    1,    0,    1 },  /* 161: BACK WALK, S V JP M K A */
    {    1,    0,    0, 0x1212,    0,    2,    0,    2 },  /* 162: KAGAMU */
    {    2,    0,    0, 0x1212,    0,    1,    0,    5 },  /* 163: STAND UP */
    {   57,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 164: KAGAMI KAMAE */
    {   58,    0,    0, 0x1110,    0,    2,    0,    2 },  /* 165: KAGAMI KAMAE */
    {   59,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 166: UPPER L */
    {   60,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 167: UPPER L, BODY UPPER L */
    {   61,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 168: UPPER L, BODY UPPER L */
    {   62,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 169: BODY UPPER L */
    {   63,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 170: FACE S, FACE M, FACE L +9 */
    {   64,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 171: FACE M, FACE L, FOOK OKU L +3 */
    {   65,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 172: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {   66,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 173: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    {   67,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 174: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {   68,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 175: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {   69,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 176: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    {   70,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 177: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    {   71,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 178: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {   72,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 179: KAGAMI S, KAGAMI M, KAGAMI L */
    {   73,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 180: KAGAMI M, KAGAMI L */
    {   74,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 181: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,   65,    2 },  /* 182: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {    0,    0,    0, 0x0000,    0,    0,   66,    2 },  /* 183: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   75,    0,    0, 0x0000,    0,    2,   67,    2 },  /* 184: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   75,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 185: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   76,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 186: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   77,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 187: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   78,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 188: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 189: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {   80,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 190: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    {  131,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 191: M KICK A */
    {  132,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 192: M KICK A */
    {  133,    0,    0, 0x0000,    0,    1,   70,    1 },  /* 193: M KICK A */
    {  133,    0,    0, 0x0000,    0,    1,   71,    1 },  /* 194: M KICK A */
    {  133,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 195: M KICK A */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 196: M KICK A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 197: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 198: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 199: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 200: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 201: not used by a script */
    {   96,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 202: LOSE SONABA, SHIMEOTASARE */
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
    {  135,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 237: 623+K (routine Att_PL14_AT3) */
    {  136,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 238: 623+K (routine Att_PL14_AT3) */
    {  137,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 239: 623+K (routine Att_PL14_AT3) */
    {  138,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 240: 623+K (routine Att_PL14_AT3) */
    {  139,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 241: 623+K (routine Att_PL14_AT3), not started by a command */
    {  140,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 242: 623+K (routine Att_PL14_AT3) */
    {  141,    0,   42, 0x0000,    0,    2,   72,    2 },  /* 243: 623+K (routine Att_PL14_AT3) */
    {  142,    0,   43, 0x0000,    0,    2,   73,    2 },  /* 244: 623+K (routine Att_PL14_AT3) */
    {  142,    0,   43, 0x0000,    0,    2,   74,    2 },  /* 245: 623+K (routine Att_PL14_AT3) */
    {  143,    0,   44, 0x0000,    0,    1,    0,    1 },  /* 246: 623+K (routine Att_PL14_AT3) */
    {  144,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 247: 623+K (routine Att_PL14_AT3) */
    {  145,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 248: 623+K (routine Att_PL14_AT3) */
    {  146,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 249: not started by a command */
    {  147,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 250: not started by a command */
    {  148,    0,   45, 0x0000,    0,    3,   75,    3 },  /* 251: not started by a command */
    {  148,    0,   46, 0x0000,    0,    3,   76,    3 },  /* 252: not started by a command */
    {  148,    0,   46, 0x0000,    0,    3,    0,    3 },  /* 253: not started by a command */
    {  149,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 254: not started by a command */
    {  150,    0,   47, 0x0000,    0,    3,   77,    3 },  /* 255: not started by a command */
    {  150,    0,   48, 0x0000,    0,    3,   78,    3 },  /* 256: not started by a command */
    {    4,    0,    0, 0x0000,    4,    3,    0,    3 },  /* 257: not started by a command */
    {  151,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 258: HURIMUKI */
    {  152,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 259: KAGAMI TURN */
    {  153,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 260: JUMP FRONT, SP JUMP FRONT */
    {  154,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 261: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  155,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 262: JUMP FRONT, SP JUMP FRONT */
    {  155,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 263: JUMP BACK, SP JUMP BACK */
    {  153,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 264: JUMP BACK, SP JUMP BACK, no name */
    {    4,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 265: JUMP VERTICAL, SP JUMP V */
    {  156,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 266: JUMP VERTICAL, SP JUMP V */
    {  157,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 267: PIYO */
    {  158,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 268: PIYO */
    {  159,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 269: PIYO */
    {  160,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 270: PIYO */
    {  161,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 271: PIYO */
    {  162,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 272: KAGAMU */
    {    5,    0,    0, 0x1010,    0,    1,    0,    5 },  /* 273: DASH HUMIKOMI */
    {  163,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 274: DASH HUMIKOMI */
    {  164,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 275: DASH HUMIKOMI */
    {  165,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 276: DASH HUMIKOMI */
    {  166,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 277: DASH TOBINOKI */
    {  167,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 278: DASH TOBINOKI */
    {  168,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 279: DASH TOBINOKI */
    {  169,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 280: DASH TOBINOKI */
};

const BODY_BOX gouki1_body_box[170] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -14,  22,  83,  20 },  {  -31,  62,  72,  20 },  {  -25,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +97 */
    { { {  -15,  22,  51,  19 },  {  -25,  56,  45,  17 },  {  -28,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +26 */
    { { {    0,   0,   0,   0 },  {  -30,  60,  43,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +3 */
    { { {  -14,  22,  92,  18 },  {  -26,  51,  80,  18 },  {  -29,  54,  46,  32 },  {  -21,  43,  31,  16 } } },  /* 4: JUMP FRONT, JUMP VERTICAL, JUMP BACK +33 */
    { { {  -20,  24,  64,  18 },  {  -30,  58,  56,  18 },  {  -26,  56,  36,  20 },  {  -36,  70,   0,  36 } } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +9 */
    { { {  -22,  24,  74,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  38,  26 },  {  -38,  76,   0,  36 } } },  /* 6: not used by a script */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 7: not used by a script */
    { { {  -14,  24,  74,  18 },  {  -30,  60,  66,  16 },  {  -22,  54,  38,  26 },  {  -30,  66,   0,  36 } } },  /* 8: PARING HEAD */
    { { {  -14,  24,  62,  18 },  {  -34,  64,  52,  18 },  {  -24,  58,  36,  20 },  {  -38,  82,   0,  36 } } },  /* 9: PARING HEAD */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 10: not used by a script */
    { { {  -14,  24,  82,  18 },  {  -32,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 11: S V JP S P A, S V JP L P A, S V JP M K A */
    { { {    4,  24,  82,  18 },  {  -18,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -32,  66,   0,  36 } } },  /* 12: GUARD AIR, no name */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 13: no name */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 14: no name */
    { { {  -20,  24,  68,  18 },  {  -32,  62,  60,  18 },  {  -24,  54,  42,  20 },  {  -40,  82,   0,  44 } } },  /* 15: follow-up of ATTACK 11 S, ATTACK 11 S: not started by a command, ATTACK 13 S: 3214+P light (plain script) +2 */
    { { {  -26,  24,  80,  18 },  {  -30,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 16: L PUNCH A */
    { { {  -16,  24,  76,  18 },  {  -32,  68,  64,  18 },  {  -24,  54,  38,  24 },  {  -36,  92,   0,  36 } } },  /* 17: L PUNCH B, follow-up of M PUNCH A */
    { { {  -14,  22,  83,  20 },  {  -31,  62,  72,  20 },  {  -25,  54,  38,  32 },  {  -58,  91,   0,  36 } } },  /* 18: S KICK A */
    { { {  -26,  24,  84,  18 },  {  -34,  60,  72,  18 },  {  -36,  64,  38,  32 },  {  -40,  70,   0,  36 } } },  /* 19: not used by a script */
    { { {    4,  24,  84,  18 },  {  -26,  70,  72,  18 },  {  -32,  68,  38,  32 },  {   -4,  40,   0,  36 } } },  /* 20: M KICK B */
    { { {   14,  24,  80,  18 },  {  -24,  78,  66,  18 },  {  -32,  72,  38,  32 },  {   -4,  40,   0,  36 } } },  /* 21: M KICK B */
    { { {    2,  24,  76,  18 },  {  -34,  64,  66,  18 },  {  -42,  68,  38,  32 },  {  -30,  54,   0,  36 } } },  /* 22: L KICK B */
    { { {  -14,  24,  64,  18 },  {  -30,  60,  60,  14 },  {  -28,  60,  34,  24 },  {  -38,  72,   0,  32 } } },  /* 23: KAGAMI P A */
    { { {   -6,  24,  76,  18 },  {  -28,  60,  68,  14 },  {  -28,  60,  34,  32 },  {  -38,  72,   0,  32 } } },  /* 24: KAGAMI P A */
    { { {  -36,  24,  90,  18 },  {  -50,  76,  80,  18 },  {  -24,  62,  44,  34 },  {    0,   0,   0,   0 } } },  /* 25: V JUMP P S A, F JUMP P S A */
    { { {  -30,  24,  92,  18 },  {  -36,  62,  80,  18 },  {  -32,  68,  42,  36 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P M A, F JUMP P L A, ATTACK 9 S: not started by a command +1 */
    { { {  -24,  24,  70,  18 },  {  -32,  62,  60,  18 },  {  -24,  54,  38,  20 },  {  -42,  92,   0,  36 } } },  /* 27: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +5 */
    { { {  -30,  24,  84,  18 },  {  -36,  62,  70,  18 },  {  -32,  52,  40,  28 },  {  -34,  72,   0,  38 } } },  /* 28: M PUNCH C */
    { { {  -36,  24,  70,  18 },  {  -40,  62,  60,  18 },  {  -34,  52,  34,  24 },  {  -34,  72,   0,  32 } } },  /* 29: M PUNCH C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  48,  28,  20 },  {  -24,  56,   0,  26 } } },  /* 30: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) +1 */
    { { {   -6,  24,  92,  18 },  {  -24,  50,  80,  18 },  {  -22,  48,  46,  32 },  {  -20,  48,  20,  24 } } },  /* 31: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) +1 */
    { { {  -10,  24,  92,  18 },  {  -30,  56,  78,  18 },  {  -26,  52,  46,  32 },  {  -20,  50,  20,  24 } } },  /* 32: ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN), ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN) +1 */
    { { {  -14,  24,  92,  18 },  {  -28,  56,  80,  18 },  {  -34,  62,  46,  32 },  {  -24,  50,  30,  16 } } },  /* 33: V JUMP K M A, S V JP S K A, S V JP L K A */
    { { {  -14,  22,  91,  17 },  {  -28,  56,  80,  18 },  {  -36,  64,  40,  38 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K M A, F JUMP K L A */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -50,  20,  58,  24 } } },  /* 36: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {   30,  20,  58,  24 } } },  /* 37: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    { { {  -16,  24,  96,  18 },  {  -30,  60,  88,  18 },  {  -28,  56,  58,  28 },  {  -30,  60,  28,  28 } } },  /* 38: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +1 */
    { { {  -16,  24,  90,  18 },  {  -30,  60,  80,  18 },  {  -28,  54,  46,  32 },  {  -34,  66,  12,  32 } } },  /* 39: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) */
    { { {  -30,  24,  90,  18 },  {  -52,  80,  78,  18 },  {  -46,  82,  40,  36 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 9 S: not started by a command */
    { { {  -30,  24,  98,  18 },  {  -34,  54,  84,  22 },  {  -40,  70,  56,  28 },  {  -48,  48,  40,  16 } } },  /* 41: F JUMP K M B */
    { { {  -10,  18,  98,  14 },  {  -24,  48,  88,  14 },  {  -29,  60,  49,  43 },  {    0,   0,   0,   0 } } },  /* 42: S V JP L K A, ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -13,  22, 100,  17 },  {  -34,  65,  88,  14 },  {  -29,  60,  49,  43 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -12,  18,  90,  14 },  {  -26,  50,  80,  14 },  {  -20,  34,  50,  28 },  {  -30,  54,  10,  38 } } },  /* 44: not used by a script */
    { { {  -63,  19,  70,  11 },  {  -66,  43,  67,   8 },  {  -39,  30,  22,  45 },  {    0,   0,   0,   0 } } },  /* 45: (never)+K light (routine Att_SLIDE_and_JUMP) */
    { { {  -42,  20,  21,  14 },  {  -38,  23,  35,  15 },  {  -17,  51,  37,  26 },  {    0,   0,   0,   0 } } },  /* 46: (never)+K light (routine Att_SLIDE_and_JUMP) */
    { { {    0,   0,   0,   0 },  {  -23,  50,  22,  18 },  {  -18,  43,   9,  26 },  {  -28,  55,   0,  23 } } },  /* 47: (never)+K light (routine Att_SLIDE_and_JUMP), (never)+K medium (routine Att_SLIDE_and_JUMP), (never)+K heavy/EX (routine Att_SLIDE_and_JUMP) */
    { { {   -4,  22,  90,  18 },  {  -32,  62,  76,  18 },  {  -30,  54,  40,  34 },  {  -20,  38,   0,  38 } } },  /* 48: L KICK A */
    { { {   -2,  22,  82,  18 },  {  -28,  62,  68,  18 },  {  -34,  56,  38,  28 },  {  -18,  38,   0,  36 } } },  /* 49: L KICK A */
    { { {  -14,  22,  84,  18 },  {  -34,  62,  72,  18 },  {  -36,  54,  38,  32 },  {  -30,  52,   0,  36 } } },  /* 50: L KICK A */
    { { {  -14,  22,  90,  20 },  {  -31,  62,  78,  20 },  {  -25,  54,  41,  37 },  {  -32,  65,   0,  40 } } },  /* 51: KAMAE */
    { { {  -14,  22,  81,  20 },  {  -31,  62,  68,  20 },  {  -25,  54,  36,  32 },  {  -32,  65,   0,  36 } } },  /* 52: KAMAE */
    { { {  -16,  22,  90,  20 },  {  -31,  62,  78,  20 },  {  -25,  54,  42,  36 },  {  -28,  57,   0,  42 } } },  /* 53: FRONT WALK */
    { { {  -16,  22,  84,  20 },  {  -31,  62,  70,  20 },  {  -25,  54,  38,  32 },  {  -32,  81,   0,  36 } } },  /* 54: FRONT WALK, S V JP L P A */
    { { {  -16,  22,  90,  20 },  {  -31,  62,  78,  20 },  {  -27,  52,  42,  36 },  {  -28,  57,   0,  42 } } },  /* 55: BACK WALK, S V JP L P A */
    { { {  -16,  22,  84,  20 },  {  -31,  62,  72,  20 },  {  -27,  52,  38,  34 },  {  -42,  70,   0,  38 } } },  /* 56: BACK WALK, S V JP M K A */
    { { {  -16,  22,  51,  19 },  {  -25,  56,  45,  15 },  {  -28,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 57: KAGAMI KAMAE */
    { { {  -16,  22,  49,  19 },  {  -23,  54,  47,  15 },  {  -28,  57,  30,  18 },  {  -37,  71,   0,  33 } } },  /* 58: KAGAMI KAMAE */
    { { {    2,  22,  87,  20 },  {  -27,  62,  72,  20 },  {  -26,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 59: UPPER L */
    { { {   10,  22,  86,  20 },  {  -24,  62,  72,  20 },  {  -27,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 60: UPPER L, BODY UPPER L */
    { { {   14,  22,  85,  20 },  {  -22,  62,  72,  20 },  {  -28,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 61: UPPER L, BODY UPPER L */
    { { {   16,  22,  84,  20 },  {  -21,  62,  72,  20 },  {  -29,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 62: BODY UPPER L */
    { { {    2,  22,  81,  20 },  {  -23,  62,  71,  20 },  {  -21,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 63: FACE S, FACE M, FACE L +9 */
    { { {   14,  22,  79,  20 },  {  -17,  62,  70,  20 },  {  -18,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 64: FACE M, FACE L, FOOK OKU L +3 */
    { { {   22,  22,  77,  20 },  {  -13,  62,  69,  20 },  {  -16,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 65: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {   26,  22,  75,  20 },  {  -11,  62,  68,  20 },  {  -15,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 66: FOOK OKU L, FOOK OKU SP, FOOK TEMAE L +1 */
    { { {  -18,  22,  80,  20 },  {  -29,  62,  70,  20 },  {  -23,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 67: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -22,  22,  77,  20 },  {  -27,  62,  68,  20 },  {  -21,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 68: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -26,  22,  74,  20 },  {  -25,  62,  66,  20 },  {  -19,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 69: NOUTEN M, NOUTEN L, BODY BROW M +1 */
    { { {  -30,  22,  71,  20 },  {  -23,  62,  64,  20 },  {  -17,  54,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 70: NOUTEN L, BODY BROW L, BODY UPPER L +1 */
    { { {   -9,  22,  51,  19 },  {  -23,  56,  45,  17 },  {  -27,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 71: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {   -3,  22,  51,  19 },  {  -21,  56,  45,  17 },  {  -26,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 72: KAGAMI S, KAGAMI M, KAGAMI L */
    { { {    3,  22,  51,  19 },  {  -19,  56,  45,  17 },  {  -25,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 73: KAGAMI M, KAGAMI L */
    { { {    9,  22,  51,  19 },  {  -17,  56,  45,  17 },  {  -24,  57,  28,  18 },  {  -37,  71,   0,  33 } } },  /* 74: not used by a script */
    { { {  -46,  22,  24,  20 },  {  -44,  50,  38,  20 },  {  -30,  52,  20,  22 },  {  -50, 108,   0,  24 } } },  /* 75: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -44,  22,  42,  20 },  {  -40,  50,  56,  20 },  {  -32,  54,  30,  20 },  {  -48, 106,   0,  30 } } },  /* 76: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -40,  22,  52,  20 },  {  -34,  50,  50,  20 },  {  -28,  58,  32,  22 },  {  -46, 102,   0,  32 } } },  /* 77: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -21,  22,  74,  20 },  {  -26,  54,  64,  20 },  {  -27,  50,  36,  28 },  {  -46,  87,   0,  34 } } },  /* 78: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -17,  22,  80,  20 },  {  -28,  58,  68,  20 },  {  -25,  50,  38,  30 },  {  -42,  81,   0,  36 } } },  /* 79: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -16,  22,  83,  20 },  {  -30,  60,  70,  20 },  {  -25,  52,  38,  32 },  {  -36,  69,   0,  36 } } },  /* 80: ATTACK 10 SP: SA (all arts) 25252+PP (plain script) */
    { { {  -14,  24,  90,  20 },  {  -30,  50,  74,  22 },  {  -20,  36,  44,  30 },  {  -16,  36,  22,  22 } } },  /* 81: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: no box */
    { { {   -2,  22,  80,  18 },  {  -16,  58,  70,  18 },  {  -20,  54,  38,  30 },  {  -30,  62,   0,  36 } } },  /* 96: LOSE SONABA, SHIMEOTASARE */
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
    { { {  -28,  22,  82,  18 },  {  -31,  51,  70,  19 },  {  -28,  45,  38,  32 },  {  -32,  62,   0,  36 } } },  /* 131: M KICK A */
    { { {  -24,  24,  84,  18 },  {  -32,  52,  72,  18 },  {  -34,  49,  44,  32 },  {  -34,  40,   0,  42 } } },  /* 132: M KICK A */
    { { {  -20,  24,  90,  18 },  {  -28,  48,  76,  18 },  {  -36,  49,  44,  32 },  {  -34,  40,   0,  42 } } },  /* 133: M KICK A */
    { { {  -18,  24,  84,  18 },  {  -28,  54,  72,  18 },  {  -34,  54,  38,  32 },  {  -34,  51,   0,  36 } } },  /* 134: M KICK A */
    { { {  -43,  22,  78,  18 },  {  -32,  51,  76,  23 },  {  -34,  57,  46,  32 },  {  -21,  43,  31,  16 } } },  /* 135: 623+K (routine Att_PL14_AT3) */
    { { {  -43,  22,  59,  18 },  {  -30,  51,  70,  23 },  {  -30,  57,  46,  32 },  {  -21,  43,  31,  16 } } },  /* 136: 623+K (routine Att_PL14_AT3) */
    { { {  -27,  22,  40,  18 },  {  -30,  51,  70,  23 },  {  -30,  57,  46,  32 },  {  -21,  43,  31,  16 } } },  /* 137: 623+K (routine Att_PL14_AT3) */
    { { {   16,  22,  84,  18 },  {   -3,  49,  64,  27 },  {  -12,  40,  51,  32 },  {  -35,  35,  41,  47 } } },  /* 138: 623+K (routine Att_PL14_AT3) */
    { { {   -2,  22,  89,  18 },  {  -14,  56,  77,  20 },  {  -29,  60,  46,  32 },  {  -21,  43,  31,  16 } } },  /* 139: 623+K (routine Att_PL14_AT3), not started by a command */
    { { {   -2,  22,  77,  20 },  {  -20,  55,  68,  20 },  {  -25,  54,  38,  32 },  {  -32,  59,   0,  36 } } },  /* 140: 623+K (routine Att_PL14_AT3) */
    { { {   28,  22,  49,  19 },  {   -2,  56,  45,  15 },  {  -17,  68,  28,  18 },  {  -48,  94,   0,  33 } } },  /* 141: 623+K (routine Att_PL14_AT3) */
    { { {   17,  22,  52,  19 },  {   -5,  53,  45,  21 },  {  -35,  81,  28,  18 },  {  -48,  86,   0,  35 } } },  /* 142: 623+K (routine Att_PL14_AT3) */
    { { {   18,  24,  65,  18 },  {   -8,  62,  56,  18 },  {  -21,  68,  36,  20 },  {  -36,  73,   0,  40 } } },  /* 143: 623+K (routine Att_PL14_AT3) */
    { { {   10,  22,  82,  20 },  {   -8,  59,  68,  20 },  {  -16,  58,  38,  32 },  {  -33,  69,   0,  50 } } },  /* 144: 623+K (routine Att_PL14_AT3) */
    { { {  -22,  22,  83,  20 },  {  -31,  51,  72,  20 },  {  -35,  48,  38,  32 },  {  -32,  65,   0,  36 } } },  /* 145: 623+K (routine Att_PL14_AT3) */
    { { {  -15,  22,  81,  18 },  {  -28,  59,  72,  19 },  {  -25,  54,  46,  32 },  {  -33,  66,  31,  22 } } },  /* 146: not started by a command */
    { { {  -22,  22,  83,  18 },  {  -29,  58,  72,  21 },  {  -23,  72,  46,  32 },  {  -30,  73,  31,  22 } } },  /* 147: not started by a command */
    { { {  -21,  22,  75,  18 },  {  -20,  51,  69,  27 },  {  -29,  56,  46,  32 },  {  -23,  70,  31,  24 } } },  /* 148: not started by a command */
    { { {  -22,  22,  91,  18 },  {  -35,  69,  80,  24 },  {  -34,  66,  46,  34 },  {  -33,  67,  31,  16 } } },  /* 149: not started by a command */
    { { {  -36,  24,  93,  18 },  {  -37,  54,  79,  32 },  {  -41,  76,  56,  37 },  {  -43,  43,  30,  26 } } },  /* 150: not started by a command */
    { { {  -12,  22,  83,  20 },  {  -32,  62,  72,  20 },  {  -28,  54,  38,  32 },  {  -34,  65,   0,  36 } } },  /* 151: HURIMUKI */
    { { {  -11,  22,  51,  19 },  {  -25,  56,  45,  17 },  {  -26,  57,  28,  18 },  {  -32,  71,   0,  33 } } },  /* 152: KAGAMI TURN */
    { { {  -21,  22,  94,  17 },  {  -26,  51,  80,  18 },  {  -29,  54,  46,  32 },  {  -21,  43,  32,  15 } } },  /* 153: JUMP FRONT, SP JUMP FRONT, JUMP BACK +2 */
    { { {  -42,  22,  78,  17 },  {  -26,  51,  80,  18 },  {  -29,  54,  46,  32 },  {  -21,  43,  32,  15 } } },  /* 154: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -12,  22,  92,  17 },  {  -26,  51,  82,  18 },  {  -29,  54,  52,  28 },  {  -27,  43,  36,  15 } } },  /* 155: JUMP FRONT, SP JUMP FRONT, JUMP BACK +1 */
    { { {  -20,  22,  88,  17 },  {  -26,  51,  80,  18 },  {  -29,  54,  57,  21 },  {  -37,  62,  40,  15 } } },  /* 156: JUMP VERTICAL, SP JUMP V */
    { { {  -29,  24,  78,  18 },  {  -45,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 157: PIYO */
    { { {  -26,  24,  78,  18 },  {  -42,  60,  68,  18 },  {  -30,  54,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 158: PIYO */
    { { {  -11,  24,  79,  18 },  {  -28,  60,  72,  18 },  {  -24,  54,  38,  32 },  {  -32,  66,   0,  36 } } },  /* 159: PIYO */
    { { {    4,  24,  83,  18 },  {  -16,  60,  74,  18 },  {  -14,  54,  38,  34 },  {  -28,  62,   0,  36 } } },  /* 160: PIYO */
    { { {  -10,  22,  83,  18 },  {  -32,  60,  78,  18 },  {  -24,  50,  38,  38 },  {  -32,  66,   0,  36 } } },  /* 161: PIYO */
    { { {  -15,  22,  47,  19 },  {  -25,  56,  42,  17 },  {  -28,  57,  27,  18 },  {  -37,  71,   0,  36 } } },  /* 162: KAGAMU */
    { { {  -20,  24,  80,  18 },  {  -34,  58,  70,  18 },  {  -30,  54,  38,  30 },  {  -42,  76,   0,  36 } } },  /* 163: DASH HUMIKOMI */
    { { {  -18,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  34,  30 },  {  -36,  76,   0,  32 } } },  /* 164: DASH HUMIKOMI */
    { { {  -24,  24,  76,  18 },  {  -34,  58,  66,  18 },  {  -30,  54,  36,  28 },  {  -38,  76,   0,  34 } } },  /* 165: DASH HUMIKOMI */
    { { {   -6,  24,  80,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 166: DASH TOBINOKI */
    { { {    0,  24,  76,  18 },  {  -24,  60,  66,  18 },  {  -24,  56,  38,  28 },  {  -36,  70,   0,  36 } } },  /* 167: DASH TOBINOKI */
    { { {   -9,  24,  81,  18 },  {  -28,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -32,  66,   0,  36 } } },  /* 168: DASH TOBINOKI */
    { { {   -6,  22,  80,  18 },  {  -24,  60,  68,  18 },  {  -24,  56,  38,  28 },  {  -26,  66,   0,  36 } } },  /* 169: DASH TOBINOKI */
};

const HAND_BOX gouki1_hand_box[49] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  22,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -76,  44,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH B */
    { { {  -70,  40,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: M PUNCH B, S V JP S P A */
    { { {  -72,  38,  64,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: L PUNCH B, follow-up of M PUNCH A */
    { { {  -50,  30,  80,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: L PUNCH A */
    { { {  -64,  38,  20,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: S KICK A */
    { { {  -62,  32,  44,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M KICK A */
    { { {  -80,  52,  46,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M KICK B */
    { { {  -62,  36,  58,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: L KICK B */
    { { {  -60,  28,  40,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: KAGAMI P A */
    { { {  -30,  28,  80,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: KAGAMI P A */
    { { {  -74,  34,   0,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: KAGAMI K A */
    { { {  -62,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: KAGAMI K A */
    { { {  -72,  32,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: KAGAMI K A */
    { { {  -54,  28,  74,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: V JUMP P S A, F JUMP P S A */
    { { {  -54,  28,  56,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: V JUMP P S A, F JUMP P S A */
    { { {  -58,  26,  52,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: V JUMP P M A */
    { { {  -58,  26,  52,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: V JUMP P M A, F JUMP P L A */
    { { {  -66,  32,  50,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: follow-up of ATTACK 4 S, ATTACK 1 S: 236+P light (plain script), ATTACK 1 M: 236+P medium (plain script) +5 */
    { { {  -60,  34,  38,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: M PUNCH C */
    { { {  -66,  24,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M PUNCH C */
    { { {  -66,  28,  30,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: not used by a script */
    { { {  -28,  18,  98,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: ATTACK 2 M: 623+P medium (routine Att_SHOURYUUKEN), ATTACK 2 L: 623+P heavy/EX (routine Att_SHOURYUUKEN), ATTACK 2 S: 623+P light (routine Att_SHOURYUUKEN) */
    { { {  -64,  26,  72,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: F JUMP P L A, S V JP S P A */
    { { {  -58,  28,  76,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: not used by a script */
    { { {  -70,  40,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: V JUMP P L A */
    { { {  -60,  24,  50,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: V JUMP K M A, S V JP L K A */
    { { {  -52,  24,  66,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: V JUMP K L A, S V JP M P A */
    { { {  -56,  26,  30,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: F JUMP K M B */
    { { {  -52,  28,  60,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: F JUMP K M A */
    { { {  -66,  38,  54,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: F JUMP K M A */
    { { {  -68,  38,  44,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: F JUMP K M A, F JUMP K L A */
    { { {  -72,  42,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: F JUMP K L A */
    { { {  -70,  40,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP K L A */
    { { {  -20,  40,  38,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: ATTACK 3 S: 214+K light (routine Att_SENPUUKYAKU), ATTACK 3 M: 214+K medium (routine Att_SENPUUKYAKU), ATTACK 3 L: 214+K heavy/EX (routine Att_SENPUUKYAKU) +3 */
    { { {  -80,  32,  48,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: ATTACK 9 S: not started by a command */
    { { {   23,  56,  61,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: ATTACK 6 S: SA III 23623+K (routine Att_SHOURYUUKEN), SA III air 23623+K (routine Att_KUUCHUUJINNCHUUWATARI) */
    { { {  -34,  36,  96,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: L KICK A */
    { { {  -52,  32,  72,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L KICK A */
    { { {  -60,  40,   4,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK A */
    { { {  -40,  18,  44,  22 },  {    4,  22,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 10 L: SA (all arts) LP LP (369) LK+HP (routine Att_CHOUCHUURENGEKI) */
    { { {  -72,  24,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: 623+K (routine Att_PL14_AT3) */
    { { {  -83,  20,   0,  23 },  {  -73,  25,   0,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: 623+K (routine Att_PL14_AT3) */
    { { {  -59,  23,   8,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: 623+K (routine Att_PL14_AT3) */
    { { {  -59,  28,  38,  21 },  {  -44,  27,  50,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: not started by a command */
    { { {  -59,  28,  38,  21 },  {  -44,  27,  50,  24 },  {  -65,  26,  28,  18 },  {    0,   0,   0,   0 } } },  /* 46: not started by a command */
    { { {  -48,  26,  18,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: not started by a command */
    { { {  -48,  26,  18,  18 },  {  -54,  24,  10,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: not started by a command */
};

const HOSEI_BOX gouki1_hos_box[6] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   84 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +107 */
    { {  -25,   50,    0,   53 } },  /* 2: KAGAMU, KAGAMI TURN, PARING DOWN +52 */
    { {  -25,   50,   48,   40 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +78 */
    { {  -25,   50,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +4 */
    { {  -25,   50,    0,   72 } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH TOBINOKI +46 */
};
