/*
 * ORO_HITBOX.C  Oro's hit boxes
 *
 * Each of Oro's animation frames names an entry of oro_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX oro_hit_ix_table[287] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +25 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +102 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 2: not used by a script */
    {    3,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 3: DASH HUMIKOMI */
    {   10,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 4: no name */
    {    5,    0,    0, 0x0000,    0,    2,    0,   19 },  /* 5: P BREAK ZUJOU, TUKAMIHAZUSI, no name */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 6: P BREAK ZUJOU, TUKAMIHAZUSI, no name */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: not used by a script */
    {    8,    0,    0, 0x0000,    0,    1,    0,   13 },  /* 8: DASH TOBINOKI */
    {   10,    0,    0, 0x0000,    0,    1,    0,    3 },  /* 9: not used by a script */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 10: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +24 */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 11: not used by a script */
    {   12,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 12: JUMP BACK, SP JUMP BACK, PARING AIR F +6 */
    {   13,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 13: PARING AIR F, TUKAMIHAZUSI, CATCH 14 +3 */
    {   14,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 14: JUMP FRONT, SP JUMP FRONT, PARING AIR F +11 */
    {   15,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 15: JUMP VERTICAL, SP JUMP V, TUKAMIHAZUSARE +11 */
    {   16,    0,    2, 0x0000,    0,    1,    1,    1 },  /* 16: no name, S PUNCH A */
    {   16,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 17: S PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 18: S PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 19: S PUNCH B */
    {   19,    0,    4, 0x0000,    0,    1,    2,    1 },  /* 20: S PUNCH B */
    {   19,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 21: S PUNCH B */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 22: not used by a script */
    {   21,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 23: not used by a script */
    {   21,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 24: not used by a script */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 25: M PUNCH B */
    {   23,    0,    6, 0x0000,    0,    1,    3,    1 },  /* 26: not used by a script */
    {   24,    0,    7, 0x0000,    0,    1,    3,    1 },  /* 27: M PUNCH B */
    {   24,    0,    7, 0x0000,    0,    1,    4,    1 },  /* 28: M PUNCH B */
    {   24,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 29: CATCH 6, M PUNCH B */
    {    1,    0,    0, 0x0000,    0,    1,    6,    1 },  /* 30: not used by a script */
    {   27,    0,    9, 0x0000,    0,    1,    5,    1 },  /* 31: M PUNCH A */
    {   28,    0,   10, 0x0000,    0,    1,    6,    1 },  /* 32: M PUNCH A */
    {   29,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 33: M PUNCH A */
    {   30,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 34: M PUNCH A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 35: M PUNCH A */
    {   32,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 36: L PUNCH A */
    {   33,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 37: L PUNCH A */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 38: L PUNCH A */
    {   35,    0,   13, 0x0000,    0,    1,    7,    1 },  /* 39: L PUNCH A */
    {   36,    0,   14, 0x0000,    0,    1,    8,    1 },  /* 40: L PUNCH A */
    {   36,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 41: L PUNCH A */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: L PUNCH A */
    {   38,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: S KICK A */
    {   40,    0,   15, 0x0000,    0,    1,    9,    1 },  /* 44: S KICK A */
    {   40,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 45: S KICK A */
    {   39,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 46: S KICK A, follow-up of S KICK A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 47: S KICK B */
    {   42,    0,   16, 0x0000,    0,    1,   10,    1 },  /* 48: S KICK B */
    {   42,    0,   16, 0x0000,    0,    1,    0,    1 },  /* 49: S KICK B */
    {   43,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 50: S KICK B */
    {   44,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 51: M KICK A, follow-up of S KICK A */
    {   46,    0,   18, 0x0000,    0,    1,   11,    1 },  /* 52: M KICK A, follow-up of S KICK A */
    {   46,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 53: M KICK A, follow-up of S KICK A */
    {   47,    0,   19, 0x0000,    0,    1,    0,    1 },  /* 54: M KICK A, follow-up of S KICK A */
    {   48,    0,    0, 0x0000,    0,    6,    0,    1 },  /* 55: M KICK B */
    {   49,    0,   20, 0x0000,    0,    6,   12,    1 },  /* 56: not used by a script */
    {   50,    0,   21, 0x0000,    0,    6,   51,    1 },  /* 57: M KICK B */
    {   50,    0,   21, 0x0000,    0,    6,    0,    1 },  /* 58: M KICK B */
    {   51,    0,   22, 0x0000,    0,    6,    0,    1 },  /* 59: M KICK B */
    {   52,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 60: M KICK B */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 61: L KICK A */
    {   54,    0,   23, 0x0000,    0,    1,   13,    1 },  /* 62: L KICK A */
    {   55,    0,   24, 0x0000,    0,    1,   52,    1 },  /* 63: not used by a script */
    {   55,    0,   24, 0x0000,    0,    1,    0,    1 },  /* 64: L KICK A */
    {   57,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 65: L KICK A */
    {   58,    0,    0, 0x0000,    0,   11,    0,    3 },  /* 66: KAGAMI P A */
    {   59,    0,   25, 0x0000,    0,   11,   14,    3 },  /* 67: KAGAMI P A */
    {   59,    0,   25, 0x0000,    0,   11,    0,    3 },  /* 68: KAGAMI P A */
    {   60,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 69: KAGAMI P A */
    {   61,    0,   26, 0x0000,    0,    3,   15,    3 },  /* 70: KAGAMI P A */
    {   62,    0,   27, 0x0000,    0,    3,   16,    3 },  /* 71: KAGAMI P A */
    {   60,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 72: KAGAMI P A */
    {   63,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 73: KAGAMI P A */
    {   64,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 74: KAGAMI P A */
    {   65,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 75: KAGAMI K A */
    {   66,    0,   28, 0x0000,    0,   11,   18,    3 },  /* 76: KAGAMI K A */
    {   66,    0,   28, 0x0000,    0,   11,    0,    3 },  /* 77: KAGAMI K A */
    {   65,    0,    0, 0x0000,    0,   11,    0,    3 },  /* 78: KAGAMI K A */
    {   68,    0,   29, 0x0000,    0,    3,   19,    3 },  /* 79: not used by a script */
    {   68,    0,   29, 0x0000,    0,    3,    0,    3 },  /* 80: KAGAMI K A */
    {   69,    0,   30, 0x0000,    0,    3,   19,    3 },  /* 81: KAGAMI K A */
    {   69,    0,   30, 0x0000,    0,    3,    0,    3 },  /* 82: KAGAMI K A */
    {   70,    0,   31, 0x0000,    0,    3,    0,    3 },  /* 83: KAGAMI K A */
    {   71,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 84: KAGAMI K A */
    {   72,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 85: KAGAMI K A */
    {   73,    0,   32, 0x0000,    0,    4,   20,    4 },  /* 86: V JUMP P S A */
    {   73,    0,   32, 0x0000,    0,    4,    0,    4 },  /* 87: V JUMP P S A */
    {  104,    0,   47, 0x0000,    0,    4,   21,    4 },  /* 88: V JUMP K S A */
    {  104,    0,   47, 0x0000,    0,    4,   22,    4 },  /* 89: V JUMP K M A */
    {   74,    0,   33, 0x0000,    0,    4,   23,    4 },  /* 90: V JUMP K L A */
    {   74,    0,   33, 0x0000,    0,    4,    0,    4 },  /* 91: V JUMP K L A */
    {   75,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 92: F JUMP P S A, F JUMP P M A, F JUMP P L A */
    {   76,    0,   34, 0x0000,    0,    4,    0,    4 },  /* 93: F JUMP P S A, F JUMP P M A */
    {  118,    0,   56, 0x0000,    0,    4,   24,    4 },  /* 94: F JUMP P S A */
    {  105,    0,   48, 0x0000,    0,    4,   25,    4 },  /* 95: F JUMP P M A */
    {   77,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 96: F JUMP P S A, F JUMP P M A */
    {  106,    0,   49, 0x0000,    0,    4,   26,    4 },  /* 97: F JUMP P L A */
    {  107,    0,   50, 0x0000,    0,    4,   27,    4 },  /* 98: F JUMP P L A */
    {   78,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 99: F JUMP K S A, F JUMP K M A */
    {   79,    0,   35, 0x0000,    0,    4,    0,    4 },  /* 100: GUARD AIR, F JUMP K S A, F JUMP K M A */
    {   79,    0,   35, 0x0000,    0,    4,   28,    4 },  /* 101: F JUMP K S A */
    {   79,    0,   35, 0x0000,    0,    4,   29,    4 },  /* 102: F JUMP K M A */
    {   80,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 103: GUARD AIR, F JUMP K S A, F JUMP K M A */
    {   81,    0,    0, 0x0000,    0,    4,   30,    4 },  /* 104: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    {   81,    0,    0, 0x0000,    0,    4,   50,    4 },  /* 105: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    {   82,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 106: F JUMP K M B, F JUMP K L A */
    {   17,    0,    0, 0x0000,    0,    0,    0,   20 },  /* 107: no name */
    {   83,    0,   36, 0x0000,    0,    4,    0,    4 },  /* 108: F JUMP K L A */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 109: PARING DOWN, GUARD DOWN, P BREAK DOWN */
    {   85,    0,   37, 0x0000,    0,    1,   32,    1 },  /* 110: not used by a script */
    {   85,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 111: not used by a script */
    {   86,    0,   38, 0x0000,    0,    1,   33,    1 },  /* 112: not used by a script */
    {   86,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 113: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 114: OKIAGARI, UKEMI MOVE F, UKEMI MOVE R +13 */
    {   87,    0,    0, 0x0000,    0,    0,    0,   15 },  /* 115: ATTACK 10 M: not started by a command */
    {    0,    0,    0, 0x0000,    0,    0,    0,   12 },  /* 116: not used by a script */
    {   88,    0,    0, 0x0000,    0,    0,    0,   12 },  /* 117: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    {   89,    0,    0, 0x0000,    0,    0,    0,   12 },  /* 118: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    {   90,    0,   39, 0x0000,    0,    1,   34,   12 },  /* 119: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {   91,    0,   40, 0x0000,    0,    1,   35,   13 },  /* 120: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   92,    0,    0, 0x0000,    0,   10,   36,   14 },  /* 121: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   93,    0,    0, 0x0000,    0,   10,    0,   14 },  /* 122: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   94,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 123: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   95,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 124: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   96,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 125: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    {   97,    0,   41, 0x0000,    0,    1,   37,    1 },  /* 126: not used by a script */
    {   97,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 127: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    {   98,    0,   42, 0x0000,    0,    1,   38,    1 },  /* 128: not used by a script */
    {   98,    0,   42, 0x0000,    0,    1,    0,    1 },  /* 129: ATTACK 4 M: [4]6+P medium (plain script) */
    {   99,    0,   43, 0x0000,    0,    1,   39,    1 },  /* 130: not used by a script */
    {   99,    0,   43, 0x0000,    0,    1,    0,    1 },  /* 131: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    {  100,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 132: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  101,    0,   44, 0x0000,    0,    4,    0,    4 },  /* 133: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  101,    0,   44, 0x0000,    0,    4,    0,    4 },  /* 134: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    {  109,    0,   51, 0x0000,    2,    1,   41,    1 },  /* 135: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    {  102,    0,   45, 0x0000,    0,    3,   42,    3 },  /* 136: KAGAMI P A */
    {  111,    0,   52, 0x0000,    0,    3,   43,    3 },  /* 137: KAGAMI K A */
    {  103,    0,   46, 0x0000,    0,    4,   44,    4 },  /* 138: V JUMP P M A */
    {  103,    0,   46, 0x0000,    0,    4,    0,    4 },  /* 139: V JUMP P M A, follow-up of ZANNEN 7 */
    {  108,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 140: F JUMP P L A */
    {    1,    0,    0, 0x0000,    1,    1,   45,    1 },  /* 141: not used by a script */
    {  110,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 142: BODY SLAM, IPPONZEOI, TOMOE RYU +4 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 143: ATTACK 6 S: SA III 23623+P light/medium/heavy (plain script), ATTACK 6 SP: SA III EX 23623+PP (routine Att_PL09_EX_TENGUIWA), ATTACK 7 S: SA II 23623+P light (plain script) +5 */
    {  113,    0,   53, 0x0000,    6,    1,   57,    1 },  /* 144: follow-up of WIN 8 */
    {  113,    0,   53, 0x0000,    3,    1,   46,    1 },  /* 145: follow-up of ZANNEN 2 */
    {  113,    0,   53, 0x0000,    0,    1,    0,    1 },  /* 146: follow-up of WIN 8, follow-up of SP WIN 1, follow-up of ZANNEN 2 +1 */
    {  113,    0,   53, 0x0000,    7,    1,   58,    1 },  /* 147: follow-up of SP WIN 1 */
    {   15,    0,    0, 0x0000,    4,    4,   47,    4 },  /* 148: not used by a script */
    {   93,    0,    0, 0x0000,    0,   10,   48,   14 },  /* 149: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    {   46,    0,   18, 0x0000,    0,    1,   49,    1 },  /* 150: not used by a script */
    {   81,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 151: ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) +3 */
    {  115,    0,   54, 0x0000,    0,    4,    0,    4 },  /* 152: V JUMP P L A */
    {   65,    0,    0, 0x0000,    0,    3,   43,    3 },  /* 153: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,   15 },  /* 154: OKIAGARI F, OKIAGARI B, OKIAGARI FRONT +1 */
    {  115,    0,   54, 0x0000,    0,    4,   53,    4 },  /* 155: V JUMP P L A */
    {  116,    0,    0, 0x0000,    0,    4,   22,    4 },  /* 156: not used by a script */
    {   15,    0,    0, 0x0000,    0,    4,   23,    4 },  /* 157: not used by a script */
    {   83,    0,   36, 0x0000,    0,    4,   54,    4 },  /* 158: F JUMP K L A */
    {    1,    0,    0, 0x0000,    0,    1,   55,    1 },  /* 159: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 160: follow-up of AIR NORMAL, ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    {  122,    0,   58, 0x0000,    5,    4,   56,    4 },  /* 161: follow-up of ZANNEN 7 */
    {  119,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 162: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    {  120,    0,    0, 0x0000,    0,    1,    0,   19 },  /* 163: not used by a script */
    {  121,    0,   57, 0x0000,    0,    4,   59,    4 },  /* 164: ATTACK 11 L: not started by a command */
    {  111,    0,   52, 0x0000,    0,    3,    0,    3 },  /* 165: KAGAMI K A */
    {    0,    0,    0, 0x0000,    0,    0,    0,   20 },  /* 166: NEKOROBI S, no name */
    {  123,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 167: ATTACK 6 S: SA III 23623+P light/medium/heavy (plain script), ATTACK 6 SP: SA III EX 23623+PP (routine Att_PL09_EX_TENGUIWA) */
    {   59,    0,   25, 0x0000,    0,    3,    0,    3 },  /* 168: KAGAMI P A */
    {   58,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 169: KAGAMI P A */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 170: follow-up of SP WIN 2 */
    {   10,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 171: follow-up of SP WIN 2 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 172: LOSE SONABA, SHIMEOTASARE */
    {  106,    0,   49, 0x0000,    0,    4,    0,    4 },  /* 173: F JUMP P L A */
    {  107,    0,   50, 0x0000,    0,    4,    0,    4 },  /* 174: F JUMP P L A */
    {    0,    0,    0, 0x0000,    0,    0,    0,   12 },  /* 175: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {    0,    0,    0, 0x0000,    0,    0,   34,   12 },  /* 176: ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    {   81,    0,    0, 0x0000,    0,    4,   60,    4 },  /* 177: ATTACK 10 S: air EX 236+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    {  113,    0,   53, 0x0000,    8,    1,    0,    1 },  /* 178: ATTACK 9 S: after 6(123)4+P (plain script) */
    {  124,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 179: BODY UPPER L, UPPER L */
    {  125,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 180: BODY UPPER L, UPPER L */
    {  126,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 181: UPPER L */
    {  127,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 182: UPPER L */
    {  128,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 183: FACE S, FACE M, FACE L +7 */
    {  129,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 184: FACE M, FACE L, FOOK TEMAE L +5 */
    {  130,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 185: FACE M, FACE L, FOOK TEMAE L +3 */
    {  131,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 186: FACE L, FOOK TEMAE SP, FOOK OKU SP */
    {  132,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 187: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    {  133,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 188: NOUTEN M, NOUTEN L, BODY BROW M */
    {  134,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 189: NOUTEN L */
    {  135,    0,    0, 0x0000,    0,    1,    0,   21 },  /* 190: NOUTEN L, TATAKI S */
    {  136,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 191: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  137,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 192: KAGAMI M, KAGAMI L, KGM TATAKI S +2 */
    {  138,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 193: KAGAMI L, KGM TOUKETU L */
    {  139,    0,    0, 0x0000,    0,    2,    0,    3 },  /* 194: KAGAMI L */
    {  140,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 195: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  141,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 196: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  142,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 197: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  143,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 198: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  144,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 199: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  145,    0,    0, 0x0000,    0,   12,    0,   17 },  /* 200: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  146,    0,    1, 0x0000,    0,    4,    0,    4 },  /* 201: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  147,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 202: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  148,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 203: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  149,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 204: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  150,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 205: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {  151,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 206: CATCH 14, ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    {   10,    0,    0, 0x0000,    0,    4,    0,    3 },  /* 207: JUMP JUNBI, SP JUMP JUNBI */
    {  152,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 208: AIR NORMAL, KUNOJI, KUNOJI NOKE */
    {  153,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 209: AIR NORMAL, UPPER, BODY UPPER +2 */
    {  154,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 210: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  155,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 211: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  156,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 212: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  157,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 213: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    {  158,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 214: NOKEZORI, UPPER, BODY UPPER +6 */
    {  159,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 215: NOKEZORI, UPPER, BODY UPPER +7 */
    {  160,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 216: NOKEZORI, UPPER, BODY UPPER +7 */
    {  161,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 217: NOKEZORI, UPPER, BODY UPPER +8 */
    {  162,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 218: NOKEZORI, UPPER, BODY UPPER +8 */
    {  163,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 219: NOKEZORI, UPPER, BODY UPPER +8 */
    {  164,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 220: NOKEZORI, UPPER, BODY UPPER +8 */
    {  165,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 221: NOKEZORI, UPPER, BODY UPPER +7 */
    {  166,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 222: KUNOJI, KUNOJI NOKE */
    {  167,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 223: KUNOJI, KUNOJI NOKE */
    {  168,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 224: KUNOJI */
    {  169,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 225: KIRIMOMI, HARAYARARE, FACE +1 */
    {  170,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 226: KIRIMOMI */
    {  171,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 227: KIRIMOMI */
    {  172,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 228: KIRIMOMI */
    {  173,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 229: KIRIMOMI */
    {  174,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 230: KIRIMOMI */
    {  175,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 231: KIRIMOMI */
    {  176,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 232: KIRIMOMI */
    {  177,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 233: KIRIMOMI */
    {  178,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 234: KIRIMOMI */
    {  179,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 235: KIRIMOMI */
    {  180,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 236: KIRIMOMI */
    {  181,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 237: KIRIMOMI */
    {  182,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 238: KIRIMOMI */
    {  183,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 239: KIRIMOMI */
    {  184,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 240: BODY UPPER, HARAYARARE, ALEX B.D +1 */
    {  185,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 241: TTKI V. AIR */
    {  186,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 242: TTKI V. AIR */
    {  187,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 243: HUMI ASIB */
    {  188,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 244: HUMI ASIB */
    {  189,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 245: FACE, TOUKETSU A */
    {  190,    0,    0, 0x0000,    0,    9,    0,   18 },  /* 246: DENKI */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 247: ATTACK 11 L: not started by a command */
    {  191,    0,   59, 0x0000,    0,    0,    0,    4 },  /* 248: not used by a script */
    {  192,    0,   60, 0x0000,    9,    0,    0,    1 },  /* 249: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    {  192,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 250: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    {  193,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 251: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    {   81,    0,    0, 0x0000,    0,    4,   61,    4 },  /* 252: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    {  194,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 253: TUKAMIKAKARI A, TUKAMIKAKARI C */
    {  194,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 254: TUKAMIKAKARI A, TUKAMIKAKARI C */
    {  194,    0,   62, 0x0000,    0,    1,    0,    1 },  /* 255: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  195,    0,   63, 0x0000,    0,    1,    0,    1 },  /* 256: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  196,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 257: TUKAMI AIR A */
    {  196,    0,   64, 0x0000,    0,    4,    0,    4 },  /* 258: TUKAMIHAZUSARE, TUKAMI AIR A */
    {  196,    0,   64, 0x0000,    4,    4,    0,    4 },  /* 259: TUKAMI AIR A */
    {  197,    0,   65, 0x0000,    0,    1,   62,    1 },  /* 260: M PUNCH C */
    {  197,    0,   65, 0x0000,    0,    1,    0,    1 },  /* 261: M PUNCH C */
    {  198,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 262: M PUNCH C */
    {  199,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 263: HURIMUKI */
    {  200,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 264: HURIMUKI */
    {  201,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 265: HURIMUKI */
    {  202,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 266: FRONT WALK, BACK WALK */
    {  203,    0,    0, 0x1212,    0,    1,    0,    1 },  /* 267: FRONT WALK, BACK WALK */
    {  204,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 268: FRONT WALK, BACK WALK */
    {  205,    0,    0, 0x1212,    0,    3,    0,    3 },  /* 269: KAGAMU */
    {  206,    0,    0, 0x1A1A,    0,    3,    0,    3 },  /* 270: KAGAMI TURN */
    {   10,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 271: DASH TOBINOKI, STAND UP */
    {  207,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 272: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    {   12,    0,    0, 0x1515,    0,    4,    0,    4 },  /* 273: JUMP FRONT, SP JUMP FRONT */
    {  208,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 274: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  208,    0,    0, 0x1515,    0,    4,    0,    4 },  /* 275: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    {  215,    0,    0, 0x1515,    0,    4,    0,    4 },  /* 276: JUMP BACK, SP JUMP BACK, no name */
    {  209,    0,    0, 0x1010,    0,    1,    0,   19 },  /* 277: PIYO */
    {  210,    0,    0, 0x1010,    0,    1,    0,   19 },  /* 278: PIYO */
    {  211,    0,    0, 0x0000,    0,    1,    0,   19 },  /* 279: DASH HUMIKOMI */
    {    5,    0,    0, 0x1010,    0,    1,    0,   19 },  /* 280: DASH HUMIKOMI */
    {  212,    0,    0, 0x0000,    0,    1,    0,   19 },  /* 281: DASH HUMIKOMI */
    {  212,    0,    0, 0x1010,    0,    1,    0,   19 },  /* 282: DASH HUMIKOMI */
    {  213,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 283: DASH HUMIKOMI */
    {  214,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 284: DASH HUMIKOMI */
    {  216,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 285: DASH TOBINOKI */
    {  217,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 286: DASH TOBINOKI */
};

const BODY_BOX oro_body_box[218] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -18,  22,  65,  22 },  {  -30,  57,  50,  14 },  {  -27,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +105 */
    { { {  -19,  21,  67,  21 },  {  -28,  49,  52,  16 },  {  -28,  50,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 2: not used by a script */
    { { {   -5,  21,  53,  23 },  {  -26,  47,  42,  15 },  {  -25,  44,  24,  17 },  {  -37,  64,   0,  27 } } },  /* 3: DASH HUMIKOMI */
    { { {  -24,  21,  33,  23 },  {  -42,  47,  30,  15 },  {  -46,  55,  21,  13 },  {  -50,  64,   0,  27 } } },  /* 4: not used by a script */
    { { {  -50,  21,  36,  23 },  {  -42,  47,  34,  15 },  {  -38,  55,  23,  13 },  {  -53,  90,   0,  27 } } },  /* 5: P BREAK ZUJOU, TUKAMIHAZUSI, no name +1 */
    { { {  -39,  21,  57,  23 },  {  -42,  47,  34,  15 },  {  -38,  55,  23,  13 },  {  -53,  90,   0,  27 } } },  /* 6: not used by a script */
    { { {  -22,  21,  53,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 7: not used by a script */
    { { {  -33,  21,  46,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 8: DASH TOBINOKI */
    { { {  -30,  21,  34,  23 },  {  -25,  49,  40,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 9: not used by a script */
    { { {  -32,  26,  31,  28 },  {  -19,  51,  29,  21 },  {  -27,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 10: no name, KAGAMU, KAGAMI KAMAE +32 */
    { { {   -6,  21,  39,  23 },  {  -22,  49,  32,  12 },  {  -20,  46,  18,  16 },  {  -34,  64,   0,  14 } } },  /* 11: not used by a script */
    { { {  -45,  21,  81,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 12: JUMP BACK, SP JUMP BACK, PARING AIR F +8 */
    { { {  -51,  21,  70,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 13: PARING AIR F, TUKAMIHAZUSI, CATCH 14 +3 */
    { { {  -51,  21,  63,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 14: JUMP FRONT, SP JUMP FRONT, PARING AIR F +11 */
    { { {  -10,  21,  95,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 15: JUMP VERTICAL, SP JUMP V, TUKAMIHAZUSARE +11 */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 16: no name, S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 17: no name */
    { { {  -22,  21,  64,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 18: not used by a script */
    { { {  -22,  21,  62,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 19: S PUNCH B */
    { { {  -22,  21,  69,  23 },  {  -33,  49,  54,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 20: not used by a script */
    { { {  -22,  21,  69,  23 },  {  -33,  49,  54,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 21: not used by a script */
    { { {  -10,  21,  74,  23 },  {  -22,  49,  61,  12 },  {  -19,  42,  32,  27 },  {  -30,  64,   0,  30 } } },  /* 22: not used by a script */
    { { {  -18,  21,  85,  23 },  {  -27,  44,  70,  15 },  {  -25,  42,  42,  26 },  {  -30,  64,   0,  39 } } },  /* 23: not used by a script */
    { { {  -24,  21,  71,  23 },  {  -36,  52,  58,  15 },  {  -26,  49,  39,  19 },  {  -30,  64,   0,  39 } } },  /* 24: M PUNCH B, CATCH 6 */
    { { {  -18,  21,  85,  23 },  {  -27,  44,  70,  15 },  {  -25,  42,  42,  26 },  {  -30,  64,   0,  39 } } },  /* 25: not used by a script */
    { { {  -13,  21,  62,  23 },  {  -28,  49,  52,  12 },  {  -15,  42,  27,  22 },  {  -35,  64,   0,  27 } } },  /* 26: not used by a script */
    { { {  -20,  29,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 27: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 28: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 29: M PUNCH A */
    { { {  -18,  21,  65,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 30: M PUNCH A */
    { { {   -4,  21,  66,  23 },  {  -28,  49,  52,  12 },  {  -15,  42,  27,  22 },  {  -24,  64,   0,  27 } } },  /* 31: not used by a script */
    { { {  -11,  27,  72,  23 },  {  -20,  52,  59,  12 },  {  -35,  68,  34,  25 },  {  -15,  52,   0,  34 } } },  /* 32: L PUNCH A */
    { { {  -11,  27,  72,  23 },  {  -17,  49,  59,  16 },  {  -26,  63,  33,  26 },  {  -31,  73,   0,  33 } } },  /* 33: L PUNCH A */
    { { {  -18,  26,  62,  24 },  {  -22,  50,  52,  17 },  {  -24,  57,  28,  24 },  {  -33,  74,   0,  33 } } },  /* 34: L PUNCH A */
    { { {  -21,  28,  56,  23 },  {  -24,  51,  47,  22 },  {  -23,  57,  27,  22 },  {  -30,  74,   0,  27 } } },  /* 35: L PUNCH A */
    { { {  -23,  30,  56,  23 },  {  -34,  62,  47,  19 },  {  -17,  56,  28,  22 },  {  -29,  77,   0,  27 } } },  /* 36: L PUNCH A */
    { { {   -5,  28,  69,  23 },  {  -25,  57,  56,  18 },  {  -28,  60,  33,  23 },  {  -38,  76,   0,  33 } } },  /* 37: L PUNCH A */
    { { {   12,  24,  77,  23 },  {   -6,  55,  59,  20 },  {  -25,  62,  38,  26 },  {  -31,  67,   0,  40 } } },  /* 38: S KICK A */
    { { {    9,  25,  77,  23 },  {  -13,  55,  59,  22 },  {  -30,  57,  37,  29 },  {   -2,  36,   0,  40 } } },  /* 39: S KICK A, follow-up of S KICK A */
    { { {   14,  26,  77,  23 },  {   -3,  50,  59,  22 },  {  -18,  44,  37,  22 },  {   -2,  34,   0,  40 } } },  /* 40: S KICK A */
    { { {   16,  21,  79,  23 },  {  -18,  60,  67,  12 },  {  -31,  69,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 41: S KICK B */
    { { {   27,  21,  78,  23 },  {  -18,  60,  67,  12 },  {  -15,  42,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 42: S KICK B */
    { { {   27,  21,  78,  23 },  {  -18,  60,  67,  12 },  {  -31,  69,  42,  26 },  {   -2,  34,   0,  42 } } },  /* 43: S KICK B */
    { { {    1,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  64,   0,  33 } } },  /* 44: M KICK A, follow-up of S KICK A */
    { { {  -30,  21,  45,  23 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 45: not used by a script */
    { { {    1,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  39,   0,  33 } } },  /* 46: M KICK A, follow-up of S KICK A */
    { { {  -16,  21,  75,  23 },  {  -14,  49,  62,  12 },  {  -16,  42,  35,  25 },  {  -17,  39,   0,  33 } } },  /* 47: M KICK A, follow-up of S KICK A */
    { { {    2,  21,  93,  23 },  {   -9,  49,  74,  18 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 48: M KICK B */
    { { {    2,  21,  93,  23 },  {   -9,  49,  75,  17 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 49: not used by a script */
    { { {   -5,  30,  87,  24 },  {  -13,  57,  75,  22 },  {  -15,  42,  45,  29 },  {  -10,  34,   0,  44 } } },  /* 50: M KICK B */
    { { {   -7,  26,  79,  24 },  {  -15,  55,  65,  24 },  {  -15,  42,  39,  29 },  {  -10,  34,   0,  37 } } },  /* 51: M KICK B */
    { { {  -18,  27,  78,  25 },  {  -28,  56,  62,  27 },  {  -29,  55,  37,  25 },  {  -35,  67,   0,  37 } } },  /* 52: M KICK B */
    { { {  -11,  25,  82,  23 },  {  -16,  51,  61,  25 },  {  -26,  50,  38,  28 },  {  -29,  34,   0,  36 } } },  /* 53: L KICK A */
    { { {   -2,  30,  82,  23 },  {  -36,  72,  66,  26 },  {  -18,  42,  38,  28 },  {  -29,  42,   0,  37 } } },  /* 54: L KICK A */
    { { {   -2,  30,  82,  23 },  {  -36,  72,  66,  26 },  {  -18,  42,  38,  28 },  {  -29,  42,   0,  37 } } },  /* 55: L KICK A */
    { { {   -8,  21,  81,  23 },  {  -16,  49,  66,  20 },  {  -18,  42,  38,  28 },  {  -29,  34,   0,  36 } } },  /* 56: not used by a script */
    { { {  -16,  33,  81,  23 },  {  -28,  59,  64,  20 },  {  -25,  50,  38,  28 },  {  -25,  42,   0,  37 } } },  /* 57: L KICK A */
    { { {  -30,  29,  45,  23 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 58: KAGAMI P A */
    { { {  -22,  24,  48,  23 },  {  -30,  58,  36,  20 },  {  -43,  72,  16,  20 },  {  -59,  90,   0,  14 } } },  /* 59: KAGAMI P A */
    { { {   -8,  26,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 60: KAGAMI P A */
    { { {   -8,  26,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 61: KAGAMI P A */
    { { {   -8,  29,  50,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 62: KAGAMI P A */
    { { {  -10,  31,  52,  28 },  {  -33,  62,  40,  23 },  {  -42,  70,  21,  17 },  {  -51,  80,   0,  19 } } },  /* 63: KAGAMI P A */
    { { {  -22,  30,  50,  25 },  {  -29,  58,  28,  23 },  {  -29,  59,  16,  14 },  {  -42,  76,   0,  14 } } },  /* 64: KAGAMI P A */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -46,  85,   0,  19 } } },  /* 65: KAGAMI K A */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -57,  93,   0,  32 } } },  /* 66: KAGAMI K A */
    { { {   30,  21,  39,  23 },  {  -15,  49,  41,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 67: not used by a script */
    { { {  -11,  35,  46,  17 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  19 },  {  -58,  91,   0,  27 } } },  /* 68: KAGAMI K A */
    { { {  -11,  35,  46,  17 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  19 },  {  -58,  91,   0,  27 } } },  /* 69: KAGAMI K A */
    { { {  -11,  35,  46,  17 },  {  -27,  61,  38,  17 },  {  -46,  78,  28,  19 },  {  -58,  91,   0,  27 } } },  /* 70: KAGAMI K A */
    { { {  -24,  38,  46,  17 },  {  -31,  61,  38,  17 },  {  -46,  78,  28,  22 },  {  -58,  91,   0,  27 } } },  /* 71: KAGAMI K A */
    { { {  -28,  27,  46,  22 },  {  -31,  62,  40,  15 },  {  -29,  59,  28,  18 },  {  -35,  77,   0,  27 } } },  /* 72: KAGAMI K A */
    { { {  -33,  26,  92,  23 },  {  -73,  98,  61,  30 },  {  -32,  58,  26,  51 },  {    0,   0,   0,   0 } } },  /* 73: V JUMP P S A */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -17,  39,  27,  48 },  {    0,   0,   0,   0 } } },  /* 74: V JUMP K L A */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 75: F JUMP P S A, F JUMP P M A, F JUMP P L A */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 76: F JUMP P S A, F JUMP P M A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  78,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP P S A, F JUMP P M A */
    { { {  -28,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 78: F JUMP K S A, F JUMP K M A */
    { { {    5,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 79: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {  -45,  21,  81,  23 },  {  -28,  49,  72,  12 },  {  -33,  57,  36,  39 },  {    0,   0,   0,   0 } } },  /* 80: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {  -47,  21,  62,  23 },  {  -30,  49,  78,  12 },  {  -26,  42,  32,  44 },  {  -35,  47,   5,  27 } } },  /* 81: F JUMP K M B, ATTACK 9 M: air 236+K light/medium/heavy (routine Att_KUUCHUUJINNCHUUWATARI), ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI) +4 */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -57,  36,  38,  30 },  {    0,   0,   0,   0 } } },  /* 82: F JUMP K M B, F JUMP K L A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -50,  71,  26,  48 },  {    0,   0,   0,   0 } } },  /* 83: F JUMP K L A */
    { { {   -5,  21,  39,  23 },  {  -16,  49,  28,  12 },  {  -12,  46,  12,  16 },  {  -29,  64,   0,  14 } } },  /* 84: not used by a script */
    { { {  -13,  21,  62,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -35,  64,   0,  27 } } },  /* 85: not used by a script */
    { { {  -13,  21,  62,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 86: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -29,  53,   0,  21 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 10 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -24,  42,  28,  18 },  {  -30,  64,   0,  26 } } },  /* 88: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -34,  42,  26,  18 },  {  -36,  64,   0,  26 } } },  /* 89: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) */
    { { {  -33,  42,  52,  18 },  {    0,   0,   0,   0 },  {  -28,  42,  30,  18 },  {  -24,  62,   0,  30 } } },  /* 90: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    { { {    0,   0,   0,   0 },  {  -28,  38,  66,  16 },  {  -27,  40,  38,  27 },  {  -14,  50,   0,  38 } } },  /* 91: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { { {  -10,  16,  96,  16 },  {  -20,  26,  78,  16 },  {  -26,  38,  52,  24 },  {  -20,  34,  26,  24 } } },  /* 92: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { { {  -10,  18, 100,  16 },  {  -20,  38,  80,  16 },  {  -24,  48,  52,  24 },  {  -18,  36,   0,  51 } } },  /* 93: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { { {  -30,  18,  50,  20 },  {  -30,  42,  44,  18 },  {  -24,  40,  28,  20 },  {  -40,  68,   0,  26 } } },  /* 94: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -16,  18,  76,  20 },  {  -24,  34,  58,  16 },  {  -26,  32,  34,  22 },  {  -46,  66,   0,  32 } } },  /* 95: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  33 } } },  /* 96: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 M: [4]6+P medium (plain script), ATTACK 4 L: [4]6+P heavy (plain script) +2 */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  33 } } },  /* 97: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -47,  81,   0,  34 } } },  /* 98: ATTACK 4 M: [4]6+P medium (plain script) */
    { { {  -34,  18,  70,  20 },  {  -38,  44,  54,  14 },  {  -34,  36,  34,  18 },  {  -52,  82,   0,  34 } } },  /* 99: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    { { {   -6,  18,  98,  22 },  {  -12,  48,  84,  12 },  {  -18,  46,  62,  20 },  {  -24,  42,  36,  24 } } },  /* 100: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { {  -28,  18,  96,  22 },  {  -32,  48,  84,  12 },  {  -22,  46,  62,  20 },  {  -24,  42,  36,  24 } } },  /* 101: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { {  -22,  24,  49,  23 },  {  -30,  58,  36,  20 },  {  -43,  72,  16,  20 },  {  -59,  90,   0,  14 } } },  /* 102: KAGAMI P A */
    { { {  -33,  26,  92,  23 },  {  -64,  94,  61,  30 },  {  -36,  63,  36,  34 },  {    0,   0,   0,   0 } } },  /* 103: V JUMP P M A, follow-up of ZANNEN 7 */
    { { {  -25,  21,  81,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 104: V JUMP K S A, V JUMP K M A */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  78,  12 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 105: F JUMP P M A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 106: F JUMP P L A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 107: F JUMP P L A */
    { { {  -72,  44,  50,  37 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 108: F JUMP P L A */
    { { {  -23,  21,  71,  23 },  {  -32,  56,  58,  23 },  {  -32,  58,  28,  29 },  {  -54,  86,   0,  33 } } },  /* 109: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { { {    0,   0,   0,   0 },  {  -26,  56,  55,  18 },  {  -26,  56,  39,  16 },  {  -24,  53,  22,  17 } } },  /* 110: BODY SLAM, IPPONZEOI, TOMOE RYU +4 */
    { { {    2,  24,  49,  23 },  {  -14,  55,  43,  15 },  {  -27,  67,  19,  23 },  {  -46,  85,   0,  19 } } },  /* 111: KAGAMI K A */
    { { {  -18,  18,  74,  18 },  {  -24,  34,  56,  16 },  {  -26,  38,  32,  22 },  {  -34,  60,   0,  30 } } },  /* 112: not used by a script */
    { { {  -20,  18,  72,  18 },  {  -48,  58,  58,  14 },  {  -26,  38,  32,  24 },  {  -34,  60,   0,  30 } } },  /* 113: follow-up of WIN 8, follow-up of ZANNEN 2, follow-up of SP WIN 1 +1 */
    { { {  -20,  18,  72,  18 },  {  -48,  58,  58,  14 },  {  -26,  38,  32,  24 },  {  -34,  60,   0,  30 } } },  /* 114: not used by a script */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  51 },  {    0,   0,   0,   0 } } },  /* 115: V JUMP P L A */
    { { {  -25,  21,  81,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  48 },  {    0,   0,   0,   0 } } },  /* 116: not used by a script */
    { { {  -51,  21,  63,  23 },  {  -28,  49,  72,  12 },  {  -50,  71,  26,  48 },  {    0,   0,   0,   0 } } },  /* 117: not used by a script */
    { { {  -46,  21,  66,  23 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 118: F JUMP P S A */
    { { {  -10,  21,  79,  13 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 119: ATTACK 10 L: 236+K light (routine Att_JINNCHUUWATARI), ATTACK 10 SP: 236+K medium (routine Att_JINNCHUUWATARI), ATTACK 11 S: 236+K heavy (routine Att_JINNCHUUWATARI) +1 */
    { { {  -20,  29,  57,  23 },  {  -29,  59,  45,  25 },  {  -32,  64,  28,  29 },  {  -35,  68,   0,  27 } } },  /* 120: not used by a script */
    { { {  -68,  42,  66,  25 },  {  -28,  49,  78,  12 },  {  -29,  48,  41,  38 },  {    0,   0,   0,   0 } } },  /* 121: ATTACK 11 L: not started by a command */
    { { {  -10,  21,  95,  23 },  {  -24,  49,  74,  20 },  {  -20,  43,  26,  51 },  {    0,   0,   0,   0 } } },  /* 122: follow-up of ZANNEN 7 */
    { { {  -11,  23,  84,  27 },  {  -34,  70,  70,  19 },  {  -32,  66,  42,  28 },  {  -29,  59,   0,  42 } } },  /* 123: ATTACK 6 S: SA III 23623+P light/medium/heavy (plain script), ATTACK 6 SP: SA III EX 23623+PP (routine Att_PL09_EX_TENGUIWA) */
    { { {   -2,  22,  69,  22 },  {  -26,  57,  50,  14 },  {  -28,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 124: BODY UPPER L, UPPER L */
    { { {    6,  22,  68,  22 },  {  -23,  57,  50,  14 },  {  -29,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 125: BODY UPPER L, UPPER L */
    { { {   10,  22,  67,  22 },  {  -21,  57,  50,  14 },  {  -30,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 126: UPPER L */
    { { {   12,  22,  66,  22 },  {  -20,  57,  50,  14 },  {  -31,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 127: UPPER L */
    { { {   -2,  22,  63,  22 },  {  -22,  57,  49,  14 },  {  -23,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 128: FACE S, FACE M, FACE L +7 */
    { { {   10,  22,  61,  22 },  {  -16,  57,  48,  14 },  {  -20,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 129: FACE M, FACE L, FOOK TEMAE L +5 */
    { { {   18,  22,  59,  22 },  {  -12,  57,  47,  14 },  {  -18,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 130: FACE M, FACE L, FOOK TEMAE L +3 */
    { { {   22,  22,  57,  22 },  {  -10,  57,  46,  14 },  {  -17,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 131: FACE L, FOOK TEMAE SP, FOOK OKU SP */
    { { {  -22,  22,  62,  22 },  {  -28,  57,  48,  14 },  {  -25,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 132: NOUTEN M, NOUTEN L, NOUTEN S +2 */
    { { {  -26,  22,  59,  22 },  {  -26,  57,  46,  14 },  {  -23,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 133: NOUTEN M, NOUTEN L, BODY BROW M */
    { { {  -30,  22,  56,  22 },  {  -24,  57,  44,  14 },  {  -21,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 134: NOUTEN L */
    { { {  -34,  22,  53,  22 },  {  -22,  57,  42,  14 },  {  -19,  49,  27,  22 },  {  -39,  70,   0,  27 } } },  /* 135: NOUTEN L, TATAKI S */
    { { {  -26,  26,  31,  28 },  {  -17,  51,  29,  21 },  {  -26,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 136: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {  -20,  26,  31,  28 },  {  -15,  51,  29,  21 },  {  -25,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 137: KAGAMI M, KAGAMI L, KGM TATAKI S +2 */
    { { {  -14,  26,  31,  28 },  {  -13,  51,  29,  21 },  {  -24,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 138: KAGAMI L, KGM TOUKETU L */
    { { {   -8,  26,  31,  28 },  {  -11,  51,  29,  21 },  {  -23,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 139: KAGAMI L */
    { { {  -10,  21, 121,  23 },  {  -22,  45, 104,  16 },  {  -21,  43,  75,  29 },  {  -21,  43,  58,  17 } } },  /* 140: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -10,  21, 121,  23 },  {  -27,  55, 104,  40 },  {  -21,  43,  75,  29 },  {  -21,  43,  58,  17 } } },  /* 141: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -10,  21, 113,  24 },  {  -20,  49, 104,  36 },  {  -21,  43,  75,  29 },  {  -21,  43,  58,  17 } } },  /* 142: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -19,  21, 111,  23 },  {  -33,  55, 104,  34 },  {  -21,  43,  75,  29 },  {  -21,  43,  58,  17 } } },  /* 143: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -29,  21, 104,  23 },  {  -46,  58,  98,  34 },  {  -31,  46,  84,  29 },  {  -38,  58,  73,  11 } } },  /* 144: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -42,  21,  78,  23 },  {  -67,  70,  74,  28 },  {  -31,  39,  70,  25 },  {  -19,  43,  68,  18 } } },  /* 145: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -39,  21,  58,  23 },  {  -39,  45,  61,  16 },  {  -26,  41,  77,  19 },  {  -39,  60,  57,  32 } } },  /* 146: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -38,  25,  22,  20 },  {  -36,  36,  39,  27 },  {  -26,  43,  48,  29 },  {   -2,  44,  23,  50 } } },  /* 147: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -10,  28,  12,  17 },  {  -29,  42,  27,  20 },  {  -29,  42,  48,  26 },  {  -22,  56,  73,  17 } } },  /* 148: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {   17,  20,   9,  20 },  {  -18,  39,  14,  21 },  {  -28,  52,  33,  32 },  {  -26,  50,  65,  25 } } },  /* 149: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {   33,  21,  14,  23 },  {    9,  26,  14,  45 },  {  -13,  21,  17,  44 },  {  -37,  24,  20,  40 } } },  /* 150: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -36,  71,  33,  59 },  {    0,   0,   0,   0 } } },  /* 151: CATCH 14, ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {    0,   0,   0,   0 },  {  -23,  50,  53,  17 },  {  -11,  45,  38,  18 },  {  -29,  56,  23,  23 } } },  /* 152: AIR NORMAL, KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -22,  45,  58,  20 },  {  -14,  42,  44,  18 },  {  -24,  51,  24,  21 } } },  /* 153: AIR NORMAL, UPPER, BODY UPPER +2 */
    { { {    0,   0,   0,   0 },  {  -18,  39,  56,  19 },  {  -22,  43,  39,  17 },  {  -32,  52,  22,  17 } } },  /* 154: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {   -3,  36,  57,  20 },  {  -20,  47,  36,  21 },  {  -36,  32,  45,  24 } } },  /* 155: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {    2,  36,  49,  22 },  {  -16,  43,  30,  19 },  {  -31,  32,  45,  24 } } },  /* 156: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {    7,  34,  36,  22 },  {  -10,  43,  22,  19 },  {  -20,  27,  33,  32 } } },  /* 157: ASIBARAI SIRI, ASIB TUNNOMERI, GILL */
    { { {    0,   0,   0,   0 },  {   -8,  31,  64,  25 },  {  -30,  36,  54,  29 },  {  -34,  38,  35,  19 } } },  /* 158: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    0,   0,   0,   0 },  {    2,  31,  40,  38 },  {  -26,  33,  38,  38 },  {  -45,  38,  34,  33 } } },  /* 159: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    5,  28,  36,  36 },  {  -21,  31,  36,  40 },  {  -40,  29,  35,  37 } } },  /* 160: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {    4,  27,  29,  38 },  {  -19,  29,  35,  38 },  {  -24,  26,  44,  32 } } },  /* 161: NOKEZORI, UPPER, BODY UPPER +8 */
    { { {    0,   0,   0,   0 },  {    3,  27,  28,  38 },  {  -19,  29,  33,  40 },  {  -38,  26,  43,  34 } } },  /* 162: NOKEZORI, UPPER, BODY UPPER +8 */
    { { {    0,   0,   0,   0 },  {    1,  32,  23,  40 },  {  -18,  32,  30,  43 },  {  -33,  31,  43,  39 } } },  /* 163: NOKEZORI, UPPER, BODY UPPER +8 */
    { { {    0,   0,   0,   0 },  {  -11,  46,  14,  24 },  {  -18,  47,  26,  28 },  {  -22,  43,  51,  26 } } },  /* 164: NOKEZORI, UPPER, BODY UPPER +8 */
    { { {    0,   0,   0,   0 },  {  -14,  48,  17,  22 },  {  -15,  50,  39,  21 },  {  -14,  46,  61,  17 } } },  /* 165: NOKEZORI, UPPER, BODY UPPER +7 */
    { { {    0,   0,   0,   0 },  {  -12,  56,  57,  19 },  {   -3,  63,  36,  26 },  {  -15,  66,  20,  19 } } },  /* 166: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -29,  56,  53,  19 },  {  -24,  58,  35,  26 },  {  -34,  62,  22,  21 } } },  /* 167: KUNOJI, KUNOJI NOKE */
    { { {    0,   0,   0,   0 },  {  -25,  50,  43,  22 },  {  -23,  53,  23,  26 },  {  -36,  39,  16,  34 } } },  /* 168: KUNOJI */
    { { {    0,   0,   0,   0 },  {  -14,  46,  66,  18 },  {  -21,  50,  49,  17 },  {  -26,  50,  26,  23 } } },  /* 169: KIRIMOMI, HARAYARARE, FACE +1 */
    { { {    0,   0,   0,   0 },  {  -13,  46,  66,  20 },  {  -19,  45,  49,  17 },  {  -29,  47,  26,  23 } } },  /* 170: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -13,  47,  65,  21 },  {  -18,  44,  49,  17 },  {  -26,  43,  26,  23 } } },  /* 171: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   -5,  44,  61,  26 },  {  -15,  44,  48,  23 },  {  -24,  38,  26,  23 } } },  /* 172: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    1,  38,  58,  26 },  {  -11,  39,  41,  26 },  {  -22,  36,  22,  30 } } },  /* 173: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    1,  40,  50,  31 },  {  -13,  37,  37,  30 },  {  -26,  35,  24,  28 } } },  /* 174: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    2,  39,  48,  30 },  {  -15,  38,  37,  33 },  {  -31,  35,  25,  31 } } },  /* 175: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    4,  37,  44,  30 },  {  -13,  34,  34,  30 },  {  -31,  32,  25,  30 } } },  /* 176: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    7,  38,  38,  32 },  {  -12,  35,  28,  33 },  {  -31,  32,  19,  34 } } },  /* 177: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {    7,  38,  35,  32 },  {  -11,  35,  25,  33 },  {  -31,  31,  17,  32 } } },  /* 178: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   10,  38,  32,  32 },  {  -11,  34,  24,  32 },  {  -30,  30,  15,  29 } } },  /* 179: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   12,  35,  28,  34 },  {   -9,  34,  21,  35 },  {  -30,  30,  15,  33 } } },  /* 180: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   13,  34,  18,  30 },  {   -9,  33,  16,  34 },  {  -31,  29,  16,  30 } } },  /* 181: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   13,  34,  11,  35 },  {   -9,  29,  10,  36 },  {  -31,  26,  11,  33 } } },  /* 182: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {   13,  34,   5,  31 },  {   -9,  29,   4,  35 },  {  -31,  26,   4,  31 } } },  /* 183: KIRIMOMI */
    { { {    0,   0,   0,   0 },  {  -22,  53,  58,  21 },  {  -18,  54,  45,  23 },  {  -22,  57,  28,  19 } } },  /* 184: BODY UPPER, HARAYARARE, ALEX B.D +1 */
    { { {    0,   0,   0,   0 },  {  -21,  46,  45,  18 },  {  -22,  48,  30,  15 },  {  -28,  57,  15,  15 } } },  /* 185: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -16,  44,  40,  18 },  {  -27,  46,  30,  15 },  {  -36,  54,  16,  20 } } },  /* 186: TTKI V. AIR */
    { { {    0,   0,   0,   0 },  {  -31,  43,  61,  21 },  {  -23,  42,  43,  22 },  {  -13,  42,  23,  20 } } },  /* 187: HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -39,  24,  26,  31 },  {  -23,  23,  33,  29 },  {   -4,  27,  42,  31 } } },  /* 188: HUMI ASIB */
    { { {    0,   0,   0,   0 },  {  -13,  44,  54,  15 },  {  -20,  52,  39,  16 },  {  -29,  60,  22,  17 } } },  /* 189: FACE, TOUKETSU A */
    { { {    0,   0,   0,   0 },  {  -16,  45,  60,  24 },  {  -25,  56,  45,  21 },  {  -38,  74,  22,  23 } } },  /* 190: DENKI */
    { { {  -54,  24,  69,  23 },  {  -34,  46,  71,  22 },  {  -43,  63,  60,  27 },  {  -34,  58,  50,  26 } } },  /* 191: not used by a script */
    { { {  -33,  21,  50,  18 },  {  -24,  43,  45,  20 },  {  -37,  63,  27,  18 },  {  -40,  81,   0,  27 } } },  /* 192: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    { { {  -11,  20,  63,  22 },  {  -19,  51,  45,  22 },  {  -25,  58,  27,  18 },  {  -35,  69,   0,  27 } } },  /* 193: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    { { {  -18,  22,  74,  22 },  {  -25,  36,  54,  20 },  {  -28,  42,  32,  22 },  {  -39,  66,   0,  32 } } },  /* 194: TUKAMIKAKARI A, TUKAMIKAKARI C, TUKAMIHAZUSARE */
    { { {  -24,  22,  73,  22 },  {  -34,  42,  54,  19 },  {  -30,  44,  32,  22 },  {  -37,  68,   0,  32 } } },  /* 195: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -22,  21,  89,  23 },  {  -26,  39,  71,  20 },  {  -29,  46,  29,  44 },  {    0,   0,   0,   0 } } },  /* 196: TUKAMI AIR A, TUKAMIHAZUSARE */
    { { {  -18,  21,  85,  23 },  {  -27,  52,  70,  15 },  {  -25,  49,  39,  32 },  {  -30,  64,   0,  39 } } },  /* 197: M PUNCH C */
    { { {  -18,  21,  85,  23 },  {  -27,  44,  70,  15 },  {  -25,  42,  42,  26 },  {  -30,  64,   0,  39 } } },  /* 198: M PUNCH C */
    { { {  -10,  22,  67,  22 },  {  -24,  57,  50,  14 },  {  -24,  49,  29,  20 },  {  -33,  70,   0,  28 } } },  /* 199: HURIMUKI */
    { { {  -22,  22,  68,  22 },  {  -30,  57,  55,  14 },  {  -27,  49,  31,  22 },  {  -39,  70,   0,  30 } } },  /* 200: HURIMUKI */
    { { {  -19,  22,  60,  22 },  {  -30,  57,  46,  14 },  {  -30,  53,  27,  18 },  {  -42,  78,   0,  26 } } },  /* 201: HURIMUKI */
    { { {  -25,  22,  69,  22 },  {  -30,  56,  54,  14 },  {  -27,  49,  27,  26 },  {  -34,  66,   0,  27 } } },  /* 202: FRONT WALK, BACK WALK */
    { { {  -25,  22,  65,  22 },  {  -32,  58,  49,  18 },  {  -25,  49,  23,  25 },  {  -25,  49,   0,  22 } } },  /* 203: FRONT WALK, BACK WALK */
    { { {  -25,  22,  71,  22 },  {  -30,  54,  55,  17 },  {  -27,  52,  37,  16 },  {  -40,  74,   0,  36 } } },  /* 204: FRONT WALK, BACK WALK */
    { { {  -20,  26,  61,  24 },  {  -24,  48,  43,  20 },  {  -25,  52,  25,  18 },  {  -36,  72,   0,  24 } } },  /* 205: KAGAMU */
    { { {   -9,  26,  39,  28 },  {  -25,  51,  29,  21 },  {  -27,  63,  18,  14 },  {  -35,  76,   0,  19 } } },  /* 206: KAGAMI TURN */
    { { {  -20,  26,  71,  24 },  {  -30,  50,  51,  20 },  {  -27,  50,  25,  25 },  {  -36,  68,   0,  24 } } },  /* 207: DASH HUMIKOMI, DASH TOBINOKI, STAND UP */
    { { {  -58,  21,  56,  23 },  {  -36,  59,  69,  20 },  {  -37,  60,  40,  29 },  {    0,   0,   0,   0 } } },  /* 208: JUMP FRONT, JUMP BACK, SP JUMP FRONT +2 */
    { { {  -29,  23,  47,  23 },  {  -15,  44,  40,  25 },  {  -32,  64,  28,  31 },  {  -32,  64,   0,  27 } } },  /* 209: PIYO */
    { { {  -18,  23,  55,  23 },  {  -15,  44,  40,  25 },  {  -32,  64,  28,  31 },  {  -32,  64,   0,  27 } } },  /* 210: PIYO */
    { { {  -32,  26,  31,  28 },  {  -43,  51,  29,  21 },  {  -55,  63,  18,  14 },  {  -41,  82,   0,  19 } } },  /* 211: DASH HUMIKOMI */
    { { {  -59,  21,  38,  23 },  {  -42,  42,  40,  20 },  {  -38,  57,  27,  13 },  {  -53,  90,   0,  27 } } },  /* 212: DASH HUMIKOMI */
    { { {  -59,  21,  38,  23 },  {  -42,  42,  40,  20 },  {  -38,  57,  27,  13 },  {  -39,  71,   0,  27 } } },  /* 213: DASH HUMIKOMI */
    { { {  -39,  22,  60,  22 },  {  -33,  57,  47,  17 },  {  -27,  49,  28,  18 },  {  -39,  70,   0,  27 } } },  /* 214: DASH HUMIKOMI */
    { { {  -51,  21,  71,  23 },  {  -27,  55,  74,  20 },  {  -20,  43,  29,  44 },  {    0,   0,   0,   0 } } },  /* 215: JUMP BACK, SP JUMP BACK, no name */
    { { {  -18,  21,  64,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 216: DASH TOBINOKI */
    { { {  -40,  21,  38,  23 },  {  -28,  49,  52,  12 },  {  -26,  42,  28,  22 },  {  -35,  64,   0,  27 } } },  /* 217: DASH TOBINOKI */
};

const HAND_BOX oro_hand_box[66] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -52,  47,  29,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { { {  -62,  39,  64,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no name, S PUNCH A */
    { { {  -38,  17,  57,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: not used by a script */
    { { {  -89,  55,  49,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -72,  40,  48,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: not used by a script */
    { { {  -81,  60,  62,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: not used by a script */
    { { {  -95,  59,  54,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH B */
    { { {  -66,  39,  51,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: CATCH 6, M PUNCH B */
    { { {  -54,  36,  38,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH A */
    { { {  -39,  28,  73,  56 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A */
    { { {  -37,  25,  78,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH A */
    { { {  -45,  27,  67,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH A */
    { { {  -56,  29,  54,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: L PUNCH A */
    { { {  -71,  54,  25,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A */
    { { {  -48,  44,  42,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: S KICK A */
    { { {  -82,  69,  40,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: S KICK B */
    { { {  -71,  54,  28,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { {  -44,  29,  34,  53 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: M KICK A, follow-up of S KICK A */
    { { {  -36,  21,  49,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: M KICK A, follow-up of S KICK A */
    { { {  -68,  43,  55,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: not used by a script */
    { { {  -83,  74,  53,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: M KICK B */
    { { {  -83,  74,  38,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: M KICK B */
    { { {  -86,  68,  55,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: L KICK A */
    { { {  -82,  65,  55,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: L KICK A */
    { { {  -86,  57,  29,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI P A */
    { { {  -79,  51,  36,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI P A */
    { { {  -69,  59,  44,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A */
    { { {  -91,  49,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI K A */
    { { {  -72,  41,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI K A */
    { { {  -98,  66,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI K A */
    { { {  -80,  49,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI K A */
    { { {  -93,  60,  48,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP P S A */
    { { {  -84,  62,  43,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP K L A */
    { { {  -53,  26,  43,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: F JUMP P S A, F JUMP P M A */
    { { {  -46,  46,  12,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: GUARD AIR, F JUMP K S A, F JUMP K M A */
    { { {  -92,  70,  32,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: F JUMP K L A */
    { { {  -69,  43,  52,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: not used by a script */
    { { {  -36,  49,  60,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: not used by a script */
    { { {  -40,  18,  25,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN), ATTACK 3 SP: EX [2](789)+PP (routine Att_SHOURYUUKEN) */
    { { {  -46,  17,  47,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { { { -108,  68,  60,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: ATTACK 4 S: [4]6+P light (plain script), ATTACK 4 SP: EX [4]6+PP (plain script) */
    { { {  -85,  55,  59,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: ATTACK 4 M: [4]6+P medium (plain script) */
    { { {  -65,  28,  63,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: ATTACK 4 L: [4]6+P heavy (plain script), ATTACK 13 M: not started by a command */
    { { {  -98,  40,  64,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: ATTACK 5 S: air (never)+P light (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 M: air (never)+P medium (routine Att_KUUCHUUNICHIRINSHOU), ATTACK 5 L: air (never)+P heavy/EX (routine Att_KUUCHUUNICHIRINSHOU) +1 */
    { { { -103,  73,  29,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: KAGAMI P A */
    { { {  -96,  64,  54,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP P M A, follow-up of ZANNEN 7 */
    { { {  -62,  41,  48,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: V JUMP K S A, V JUMP K M A */
    { { {  -80,  54,  40,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: F JUMP P M A */
    { { {  -58,  35,   9,  68 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: F JUMP P L A */
    { { {  -53,  34,  69,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: F JUMP P L A */
    { { {  -82,  48,  59,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 1 S: 6(123)4+P light (plain script), ATTACK 1 M: 6(123)4+P medium (plain script), ATTACK 1 L: 6(123)4+P heavy/EX (plain script) */
    { { {  -83,  56,   0,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: KAGAMI K A */
    { { {  -80,  34,  60,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: follow-up of WIN 8, follow-up of ZANNEN 2, follow-up of SP WIN 1 +1 */
    { { { -104,  78,  74,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: V JUMP P L A */
    { { { -102,  83,  32,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: not used by a script */
    { { {  -77,  53,  37,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: F JUMP P S A */
    { { {  -68,  40,  31,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 11 L: not started by a command */
    { { {  -98,  75,  62,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: follow-up of ZANNEN 7 */
    { { {  -66,  39,  94,  15 },  {  -10,  28,  94,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: not used by a script */
    { { {  -68,  35,  53,  23 },  {  -37,  50,  62,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    { { {  -47,  20,  29,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 8 SP: SA I EX 23623+PP (routine Att_PL09_EX_KISHINRIKI) */
    { { {  -56,  30,  55,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -56,  22,  54,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -53,  30,  69,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: TUKAMIHAZUSARE, TUKAMI AIR A */
    { { {  -86,  68,  68,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: M PUNCH C */
};

const HOSEI_BOX oro_hos_box[22] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -24,   48,    0,   60 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +109 */
    { {  -43,   50,    0,   64 } },  /* 2: no name */
    { {  -24,   48,    0,   44 } },  /* 3: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +47 */
    { {  -23,   46,   39,   47 } },  /* 4: JUMP BACK, SP JUMP BACK, PARING AIR F +40 */
    { {  -25,   50,   31,   58 } },  /* 5: not used by a script */
    { {  -14,   50,   28,   40 } },  /* 6: not used by a script */
    { {  -16,   50,   28,   60 } },  /* 7: not used by a script */
    { {  -28,   50,   28,   60 } },  /* 8: not used by a script */
    { {  -16,   50,   22,   34 } },  /* 9: not used by a script */
    { {  -28,   50,   31,   47 } },  /* 10: not used by a script */
    { {  -28,   50,   51,   47 } },  /* 11: not used by a script */
    { {  -24,   48,    0,   57 } },  /* 12: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { {  -28,   56,    0,   65 } },  /* 13: DASH TOBINOKI, ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN) +2 */
    { {  -24,   48,   28,   51 } },  /* 14: ATTACK 3 S: [2](789)+P light (routine Att_SHOURYUUKEN), ATTACK 3 M: [2](789)+P medium (routine Att_SHOURYUUKEN), ATTACK 3 L: [2](789)+P heavy (routine Att_SHOURYUUKEN) +1 */
    { {  -26,   44,    0,   25 } },  /* 15: ATTACK 10 M: not started by a command, OKIAGARI F, OKIAGARI B +2 */
    { {  -43,   64,    0,   55 } },  /* 16: not used by a script */
    { {  -23,   46,   73,   47 } },  /* 17: ATTACK 7 SP: SA II 23623+PP (routine Att_SP_YAGYOUDAMA) */
    { {  -21,   49,   22,   45 } },  /* 18: BODY SLAM, IPPONZEOI, TOMOE RYU +26 */
    { {  -29,   59,    0,   60 } },  /* 19: P BREAK ZUJOU, TUKAMIHAZUSI, no name +2 */
    { {  -29,   59,    0,   30 } },  /* 20: no name, NEKOROBI S */
    { {  -24,   48,    0,   54 } },  /* 21: BODY UPPER L, UPPER L, FACE S +15 */
};
