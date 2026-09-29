/*
 * Q_HITBOX.C  Q's hit boxes
 *
 * Each of Q's animation frames names an entry of q_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX q_hit_ix_table[489] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +18 */
    {    1,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +96 */
    {    2,    0,    2, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +20 */
    {    1,    0,    3, 0x0000,    0,    1,    1,    1 },  /* 3: S PUNCH A */
    {    1,    0,    3, 0x0000,    0,    1,    2,    1 },  /* 4: S PUNCH A */
    {    1,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 5: S PUNCH A */
    {    1,    0,    4, 0x0000,    0,    1,    3,    1 },  /* 6: S PUNCH B */
    {    1,    0,    5, 0x0000,    0,    1,    4,    1 },  /* 7: S PUNCH B */
    {    1,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 8: S PUNCH B */
    {  178,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 9: ATTACK 11 S: not started by a command */
    {  179,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 10: ATTACK 11 S: not started by a command */
    {  113,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 11: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +2 */
    {  114,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 12: not used by a script */
    {  115,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 13: not used by a script */
    {  180,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 14: ATTACK 11 S: not started by a command */
    {  181,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 15: ATTACK 11 S: not started by a command */
    {  182,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 16: ATTACK 11 S: not started by a command */
    {  183,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 17: ATTACK 11 S: not started by a command */
    {  184,    0,   67, 0x0000,    0,    1,    0,    1 },  /* 18: ATTACK 11 S: not started by a command */
    {  185,    0,   68, 0x0000,    0,    1,    0,    1 },  /* 19: ATTACK 11 S: not started by a command */
    {    3,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 20: M PUNCH A */
    {    4,    0,    6, 0x0000,    0,    1,    5,    1 },  /* 21: M PUNCH A */
    {    4,    0,    7, 0x0000,    0,    1,    6,    1 },  /* 22: M PUNCH A */
    {    4,    0,    8, 0x0000,    0,    1,    7,    1 },  /* 23: M PUNCH A */
    {    4,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 24: M PUNCH A */
    {    4,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 25: M PUNCH A */
    {    5,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 26: L PUNCH A, L PUNCH C */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 27: L PUNCH A, L PUNCH C */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 28: L PUNCH A, L PUNCH C */
    {    8,    0,   11, 0x0000,    0,    1,    8,    1 },  /* 29: L PUNCH A, L PUNCH C */
    {    9,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 30: L PUNCH A, L PUNCH C */
    {   10,    0,   12, 0x0000,    0,    1,    9,    1 },  /* 31: S KICK A */
    {   10,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 32: S KICK A */
    {   11,    0,   14, 0x0000,    0,    1,    0,    1 },  /* 33: M KICK A */
    {   12,    0,    0, 0x0000,    0,    1,   10,    1 },  /* 34: M KICK A */
    {   13,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 35: M KICK A */
    {   14,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 36: M KICK A */
    {   15,    0,   15, 0x0000,    0,    1,   11,    1 },  /* 37: M KICK B */
    {   16,    0,   16, 0x0000,    0,    1,   12,    1 },  /* 38: M KICK B */
    {   16,    0,   16, 0x0000,    0,    1,    0,    1 },  /* 39: M KICK B */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 40: L KICK C */
    {   18,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 41: L KICK C */
    {   19,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 42: L KICK C */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: L KICK C */
    {   21,    0,    0, 0x0000,    0,    1,   61,    1 },  /* 44: L KICK C */
    {   22,    0,   17, 0x0000,    0,    1,   13,    1 },  /* 45: L KICK C */
    {   22,    0,   17, 0x0000,    0,    1,   14,    1 },  /* 46: L KICK C */
    {   23,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 47: L KICK C */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 48: L KICK C */
    {   25,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 49: L KICK C */
    {   26,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 50: L KICK C */
    {   27,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 51: L KICK A */
    {   28,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: L KICK A */
    {   29,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 53: L KICK A */
    {   30,    0,   19, 0x0000,    0,    1,   15,    1 },  /* 54: L KICK A */
    {   30,    0,   19, 0x0000,    0,    1,   16,    1 },  /* 55: L KICK A */
    {   30,    0,   19, 0x0000,    0,    1,    0,    1 },  /* 56: L KICK A */
    {   31,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 57: L KICK A */
    {   32,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 58: L KICK A */
    {   33,    0,   22, 0x0000,    0,    1,    0,    1 },  /* 59: L KICK A */
    {   34,    0,   23, 0x0000,    0,    5,   17,    2 },  /* 60: KAGAMI P A */
    {   34,    0,   24, 0x0000,    0,    5,   18,    2 },  /* 61: KAGAMI P A */
    {   34,    0,  160, 0x0000,    0,    5,    0,    2 },  /* 62: KAGAMI P A */
    {   35,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 63: KAGAMI P A */
    {   36,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 64: KAGAMI P A */
    {   37,    0,   25, 0x0000,    0,    2,   19,    2 },  /* 65: KAGAMI P A */
    {   37,    0,   25, 0x0000,    0,    2,   20,    2 },  /* 66: KAGAMI P A */
    {   37,    0,   26, 0x0000,    0,    2,    0,    2 },  /* 67: KAGAMI P A */
    {   37,    0,   27, 0x0000,    0,    2,    0,    2 },  /* 68: KAGAMI P A */
    {   38,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 69: KAGAMI P A */
    {   39,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 70: KAGAMI P A */
    {   40,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 71: KAGAMI P A */
    {   41,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 72: KAGAMI P A */
    {   42,    0,   28, 0x0000,    0,    2,   21,    2 },  /* 73: KAGAMI P A */
    {   42,    0,   28, 0x0000,    0,    2,    0,    2 },  /* 74: KAGAMI P A */
    {   43,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 75: KAGAMI P A */
    {   44,    0,    0, 0x0000,    0,    5,    0,    2 },  /* 76: KAGAMI K A */
    {   45,    0,    0, 0x0000,    0,    5,    0,    2 },  /* 77: KAGAMI K A */
    {   46,    0,   29, 0x0000,    0,    5,   22,    2 },  /* 78: KAGAMI K A */
    {   46,    0,   29, 0x0000,    0,    5,   23,    2 },  /* 79: KAGAMI K A */
    {   47,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 80: KAGAMI K A */
    {   48,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 81: KAGAMI K A */
    {   49,    0,   30, 0x0000,    0,    2,   24,    2 },  /* 82: KAGAMI K A */
    {   49,    0,   31, 0x0000,    0,    2,   25,    2 },  /* 83: KAGAMI K A */
    {   49,    0,   31, 0x0000,    0,    2,    0,    2 },  /* 84: KAGAMI K A */
    {   50,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 85: KAGAMI K A */
    {   51,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 86: KAGAMI K A */
    {   52,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 87: KAGAMI K A */
    {   53,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 88: KAGAMI K A */
    {   54,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 89: KAGAMI K A */
    {   55,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 90: KAGAMI K A */
    {   56,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 91: KAGAMI K A */
    {   57,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 92: KAGAMI K A */
    {   57,    0,    0, 0x0000,    0,    2,   27,    2 },  /* 93: KAGAMI K A */
    {   57,    0,    0, 0x0000,    0,    2,   28,    2 },  /* 94: KAGAMI K A */
    {   58,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 95: KAGAMI K A */
    {   59,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 96: KAGAMI K A */
    {   60,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 97: KAGAMI K A */
    {   61,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 98: KAGAMI K A */
    {   62,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 99: KAGAMI K A */
    {   63,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 100: KAGAMI K A */
    {   64,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 101: KAGAMI K A */
    {   65,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: V JUMP P S A, F JUMP P S A */
    {   66,    0,   32, 0x0000,    0,    3,   29,    3 },  /* 103: V JUMP P S A */
    {   66,    0,   33, 0x0000,    0,    3,   30,    3 },  /* 104: V JUMP P S A */
    {   67,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 105: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   68,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 106: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   69,    0,   34, 0x0000,    0,    3,   31,    3 },  /* 107: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   70,    0,   35, 0x0000,    0,    3,   32,    3 },  /* 108: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   71,    0,   36, 0x0000,    0,    3,    0,    3 },  /* 109: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   71,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 110: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   72,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 111: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    {   73,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 112: V JUMP P M A, V JUMP P L A, F JUMP P M A +3 */
    {   74,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 113: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   75,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 114: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   76,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 115: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   77,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 116: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   78,    0,   37, 0x0000,    0,    3,   33,    3 },  /* 117: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   78,    0,   38, 0x0000,    0,    3,   34,    3 },  /* 118: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   79,    0,   38, 0x0000,    0,    3,   35,    3 },  /* 119: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   80,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 120: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   81,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 121: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    {   82,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 122: V JUMP K S A */
    {   83,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 123: V JUMP K S A */
    {   84,    0,   39, 0x0000,    0,    3,   36,    3 },  /* 124: V JUMP K S A */
    {   84,    0,   40, 0x0000,    0,    3,   37,    3 },  /* 125: V JUMP K S A */
    {   85,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 126: V JUMP K S A, ATTACK 10 S: not started by a command */
    {   86,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 127: V JUMP K S A, ATTACK 10 S: not started by a command */
    {   87,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 128: V JUMP K M A, ATTACK 10 S: not started by a command */
    {   88,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 129: V JUMP K M A */
    {   89,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 130: V JUMP K M A */
    {   90,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 131: V JUMP K M A */
    {   91,    0,   41, 0x0000,    0,    3,   38,    3 },  /* 132: V JUMP K M A */
    {   92,    0,   41, 0x0000,    0,    3,   39,    3 },  /* 133: V JUMP K M A */
    {   93,    0,   42, 0x0000,    0,    3,   40,    3 },  /* 134: V JUMP K M A */
    {   94,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 135: V JUMP K M A */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 136: V JUMP K M A */
    {   96,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 137: V JUMP K L A, S V JP S P A */
    {   97,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 138: V JUMP K L A, S V JP S P A */
    {   98,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 139: V JUMP K L A, S V JP S P A */
    {   99,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 140: V JUMP K L A, S V JP S P A */
    {  100,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 141: V JUMP K L A, S V JP S P A */
    {  101,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 142: V JUMP K L A, S V JP S P A */
    {  102,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 143: V JUMP K L A, S V JP S P A */
    {  103,    0,   43, 0x0000,    0,    3,   41,    3 },  /* 144: V JUMP K L A, S V JP S P A */
    {  104,    0,   44, 0x0000,    0,    3,   42,    3 },  /* 145: V JUMP K L A, S V JP S P A */
    {  105,    0,   45, 0x0000,    0,    3,    0,    3 },  /* 146: V JUMP K L A, S V JP S P A */
    {  106,    0,   46, 0x0000,    0,    3,    0,    3 },  /* 147: V JUMP K L A, S V JP S P A */
    {  107,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 148: V JUMP K L A, S V JP S P A */
    {  108,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 149: V JUMP K L A, S V JP S P A */
    {  109,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 150: V JUMP K L A, S V JP S P A */
    {  110,    0,   47, 0x0000,    0,    3,   43,    3 },  /* 151: F JUMP P S A */
    {  110,    0,   48, 0x0000,    0,    3,   44,    3 },  /* 152: F JUMP P S A */
    {  131,    0,   66, 0x0000,    0,    1,   53,    1 },  /* 153: not used by a script */
    {  111,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 154: not used by a script */
    {  112,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 155: not used by a script */
    {  116,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 156: not used by a script */
    {  117,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 157: not used by a script */
    {  118,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 158: not used by a script */
    {  119,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 159: not used by a script */
    {  120,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 160: not used by a script */
    {  121,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 161: not used by a script */
    {  122,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 162: not used by a script */
    {  123,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 163: not used by a script */
    {  124,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 164: not used by a script */
    {  125,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 165: not used by a script */
    {  126,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 166: not used by a script */
    {  127,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 167: not used by a script */
    {  128,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 168: not used by a script */
    {  129,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 169: not used by a script */
    {  130,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 170: not used by a script */
    {  292,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 171: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  132,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 172: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  133,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 173: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  134,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 174: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  135,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 175: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  136,    0,    0, 0x0000,    0,    1,   45,    1 },  /* 176: ATTACK 4 M: 214+P medium (plain script) */
    {  137,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 177: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  138,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 178: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  139,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 179: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  140,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 180: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  141,    0,  159, 0x0000,    0,    1,   46,    1 },  /* 181: ATTACK 4 M: 214+P medium (plain script) */
    {  142,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 182: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  143,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 183: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  144,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 184: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  145,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 185: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  146,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 186: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  147,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 187: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  148,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 188: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  149,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 189: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script) */
    {  150,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 190: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  151,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 191: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  152,    0,   49, 0x0000,    0,    1,   47,    1 },  /* 192: ATTACK 4 L: 214+P heavy (plain script) */
    {  153,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 193: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  154,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 194: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  155,    0,   51, 0x0000,    0,    1,    0,    1 },  /* 195: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  156,    0,   52, 0x0000,    0,    1,    0,    1 },  /* 196: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  157,    0,   53, 0x0000,    0,    1,   48,    1 },  /* 197: ATTACK 4 L: 214+P heavy (plain script) */
    {  158,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 198: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  159,    0,   54, 0x0000,    0,    1,    0,    1 },  /* 199: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    {  160,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 200: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  161,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 201: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  162,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 202: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    {  163,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 203: not used by a script */
    {  164,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 204: not used by a script */
    {  165,    0,   55, 0x0000,    0,    1,    0,    1 },  /* 205: ATTACK 4 SP: EX 214+PP (plain script) */
    {  166,    0,   56, 0x0000,    0,    1,   49,    1 },  /* 206: not used by a script */
    {  167,    0,   57, 0x0000,    0,    1,   50,    1 },  /* 207: ATTACK 4 SP: EX 214+PP (plain script) */
    {  167,    0,   58, 0x0000,    0,    1,   51,    1 },  /* 208: ATTACK 4 SP: EX 214+PP (plain script) */
    {  168,    0,   59, 0x0000,    0,    1,    0,    1 },  /* 209: ATTACK 4 SP: EX 214+PP (plain script) */
    {  168,    0,   60, 0x0000,    0,    1,    0,    1 },  /* 210: ATTACK 4 SP: EX 214+PP (plain script) */
    {  169,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 211: ATTACK 4 SP: EX 214+PP (plain script) */
    {  170,    0,   62, 0x0000,    0,    1,    0,    1 },  /* 212: ATTACK 4 SP: EX 214+PP (plain script) */
    {  171,    0,   63, 0x0000,    0,    1,    0,    1 },  /* 213: ATTACK 4 SP: EX 214+PP (plain script) */
    {  172,    0,   64, 0x0000,    0,    1,    0,    1 },  /* 214: ATTACK 4 SP: EX 214+PP (plain script) */
    {  173,    0,   65, 0x0000,    0,    1,   52,    1 },  /* 215: not used by a script */
    {  174,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 216: ATTACK 4 SP: EX 214+PP (plain script) */
    {  175,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 217: ATTACK 4 SP: EX 214+PP (plain script) */
    {  176,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 218: ATTACK 4 SP: EX 214+PP (plain script) */
    {  177,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 219: not used by a script */
    {  186,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 220: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  187,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 221: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  188,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 222: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  189,    0,   69, 0x0000,    2,    1,    0,    1 },  /* 223: ATTACK 5 S: 3214+K light (plain script) */
    {  190,    0,   70, 0x0000,    0,    1,    0,    1 },  /* 224: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  191,    0,   71, 0x0000,    0,    1,    0,    1 },  /* 225: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  192,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 226: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) +1 */
    {  189,    0,   69, 0x0000,    3,    1,    0,    1 },  /* 227: ATTACK 5 M: 3214+K medium (plain script) */
    {  189,    0,   69, 0x0000,    4,    1,    0,    1 },  /* 228: ATTACK 5 L: 3214+K heavy/EX (plain script) */
    {  193,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 229: ATTACK 10 S: not started by a command */
    {  194,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 230: ATTACK 10 S: not started by a command */
    {  195,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 231: ATTACK 10 S: not started by a command */
    {  196,    0,    0, 0x0000,    0,    3,   54,    3 },  /* 232: ATTACK 10 S: not started by a command */
    {  196,    0,    0, 0x0000,    0,    3,   55,    3 },  /* 233: not used by a script */
    {  197,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 234: follow-up of SP WIN 1 */
    {  198,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 235: UPPER L */
    {  199,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 236: UPPER L */
    {  200,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 237: UPPER L */
    {  201,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 238: UPPER L */
    {  202,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 239: FACE S, FACE M, FACE L +7 */
    {  203,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 240: FACE M, FACE L, FOOK OKU L +5 */
    {  204,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 241: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    {  205,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 242: FACE L, FOOK OKU SP, FOOK TEMAE SP */
    {  206,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 243: NOUTEN L, NOUTEN S, BODY BROW M +2 */
    {  207,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 244: NOUTEN L, BODY BROW M, BODY BROW L +1 */
    {  208,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 245: NOUTEN L, BODY BROW L, BODY UPPER L */
    {  209,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 246: BODY BROW L, TATAKI S */
    {  210,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 247: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  211,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 248: NOUTEN M, KAGAMI M, KAGAMI L +3 */
    {  212,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 249: KGM TOUKETU L */
    {  213,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 250: not used by a script */
    {  214,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 251: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    {  215,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 252: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    {  216,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 253: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +7 */
    {  217,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 254: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    {  218,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 255: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +8 */
    {  219,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 256: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +6 */
    {  220,    0,    1, 0x0000,    0,    1,    0,    6 },  /* 257: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +7 */
    {  221,    0,   72, 0x0000,    0,    1,    0,    6 },  /* 258: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  222,    0,   73, 0x0000,    0,    1,    0,    6 },  /* 259: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  223,    0,   74, 0x0000,    0,    1,    0,    6 },  /* 260: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  224,    0,   75, 0x0000,    0,    1,    0,    6 },  /* 261: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  225,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 262: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  131,    0,  158, 0x0000,    0,    1,    0,    1 },  /* 263: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  131,    0,   66, 0x0000,    0,    1,   53,    1 },  /* 264: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  226,    0,   76, 0x0000,    0,    1,   56,    1 },  /* 265: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  226,    0,   76, 0x0000,    0,    1,   57,    1 },  /* 266: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  227,    0,   77, 0x0000,    0,    1,    0,    1 },  /* 267: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  227,    0,   78, 0x0000,    0,    1,    0,    1 },  /* 268: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  228,    0,   79, 0x0000,    0,    1,    0,    1 },  /* 269: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    {  229,    0,   80, 0x0000,    0,    1,    0,    1 },  /* 270: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  230,    0,   81, 0x0000,    0,    1,    0,    1 },  /* 271: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  231,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 272: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  232,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 273: follow-up of SP APPEAR 2, SP APPEAR 4, ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP) +6 */
    {  233,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 274: ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) +3 */
    {  234,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 275: ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) +3 */
    {  235,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 276: ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  236,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 277: JUMP JUNBI */
    {  237,    0,    0, 0x0000,    0,    3,    0,    1 },  /* 278: SP JUMP JUNBI */
    {  238,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 279: AIR NORMAL, KUNOJI, HARAYARARE +13 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 280: follow-up of AIR NORMAL */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 281: NEKOROBI S, no name, HANEAGARI +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 282: OKIAGARI, OKIAGARI F, OKIAGARI B +13 */
    {  239,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 283: no name */
    {  207,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 284: not used by a script */
    {  208,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 285: not used by a script */
    {  209,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 286: not used by a script */
    {  210,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 287: not used by a script */
    {  240,    0,   82, 0x0000,    0,    1,    0,    6 },  /* 288: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  241,    0,   83, 0x0000,    0,    1,    0,    6 },  /* 289: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  242,    0,   84, 0x0000,    0,    1,    0,    6 },  /* 290: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  243,    0,   85, 0x0000,    0,    1,    0,    6 },  /* 291: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  244,    0,   86, 0x0000,    0,    1,   58,    6 },  /* 292: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  245,    0,   87, 0x0000,    0,    1,   59,    6 },  /* 293: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  246,    0,   88, 0x0000,    0,    1,    0,    6 },  /* 294: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  247,    0,   89, 0x0000,    0,    1,    0,    6 },  /* 295: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  248,    0,   90, 0x0000,    0,    1,    0,    6 },  /* 296: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    {  247,    0,   91, 0x0000,    0,    1,   60,    6 },  /* 297: ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    {  249,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 298: follow-up of SP APPEAR 2, SP APPEAR 4 */
    {  250,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 299: follow-up of SP APPEAR 2, SP APPEAR 4 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 300: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 7 S: SA II 23623+P (plain script), ATTACK 8 S: SA III 23623+P (plain script) +1 */
    {  251,    0,   92, 0x0000,    0,    1,   62,    1 },  /* 301: ATTACK 7 S: SA II 23623+P (plain script) */
    {  252,    0,   93, 0x0000,    0,    1,    0,    1 },  /* 302: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  253,    0,   94, 0x0000,    0,    1,    0,    1 },  /* 303: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  254,    0,   95, 0x0000,    0,    1,    0,    1 },  /* 304: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  255,    0,   96, 0x0000,    0,    1,    0,    1 },  /* 305: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  256,    0,   97, 0x0000,    0,    1,    0,    1 },  /* 306: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  257,    0,   98, 0x0000,    0,    1,    0,    1 },  /* 307: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  258,    0,   99, 0x0000,    0,    1,    0,    1 },  /* 308: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    {  259,    0,  100, 0x0000,    0,    1,    0,    1 },  /* 309: ATTACK 7 S: SA II 23623+P (plain script) */
    {  260,    0,  101, 0x0000,    0,    1,    0,    1 },  /* 310: ATTACK 7 S: SA II 23623+P (plain script) */
    {  261,    0,  102, 0x0000,    0,    1,    0,    1 },  /* 311: ATTACK 7 S: SA II 23623+P (plain script) */
    {  262,    0,  103, 0x0000,    0,    1,    0,    1 },  /* 312: ATTACK 7 S: SA II 23623+P (plain script) */
    {  263,    0,  104, 0x0000,    0,    1,    0,    1 },  /* 313: ATTACK 7 S: SA II 23623+P (plain script) */
    {  264,    0,  105, 0x0000,    0,    1,    0,    1 },  /* 314: ATTACK 7 S: SA II 23623+P (plain script) */
    {  265,    0,  106, 0x0000,    0,    1,    0,    1 },  /* 315: ATTACK 7 S: SA II 23623+P (plain script) */
    {  266,    0,  107, 0x0000,    0,    1,    0,    1 },  /* 316: ATTACK 7 S: SA II 23623+P (plain script) */
    {  267,    0,    0, 0x0000,    0,    1,   63,    1 },  /* 317: ATTACK 7 S: SA II 23623+P (plain script) */
    {  268,    0,  108, 0x0000,    0,    1,    0,    1 },  /* 318: ATTACK 7 S: SA II 23623+P (plain script) */
    {  269,    0,  109, 0x0000,    0,    1,    0,    1 },  /* 319: ATTACK 7 S: SA II 23623+P (plain script) */
    {  270,    0,  110, 0x0000,    0,    1,    0,    1 },  /* 320: ATTACK 7 S: SA II 23623+P (plain script) */
    {  271,    0,  111, 0x0000,    0,    1,    0,    1 },  /* 321: ATTACK 7 S: SA II 23623+P (plain script) */
    {  272,    0,  112, 0x0000,    0,    1,    0,    1 },  /* 322: M PUNCH C */
    {  273,    0,  113, 0x0000,    0,    1,    0,    1 },  /* 323: M PUNCH C */
    {  274,    0,  114, 0x0000,    0,    1,    0,    1 },  /* 324: M PUNCH C */
    {  275,    0,  115, 0x0000,    0,    1,   64,    1 },  /* 325: M PUNCH C */
    {  276,    0,  116, 0x0000,    0,    1,   65,    1 },  /* 326: M PUNCH C */
    {  277,    0,  116, 0x0000,    0,    1,    0,    1 },  /* 327: M PUNCH C */
    {  278,    0,  117, 0x0000,    0,    1,    0,    1 },  /* 328: M PUNCH C */
    {  279,    0,  118, 0x0000,    0,    1,    0,    1 },  /* 329: M PUNCH C */
    {  280,    0,  119, 0x0000,    0,    1,    0,    1 },  /* 330: M PUNCH C */
    {  281,    0,  120, 0x0000,    0,    1,    0,    1 },  /* 331: M PUNCH C */
    {  282,    0,  121, 0x0000,    0,    1,    0,    1 },  /* 332: M PUNCH C */
    {  283,    0,  122, 0x0000,    0,    1,    0,    1 },  /* 333: M PUNCH C */
    {  284,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 334: M PUNCH C */
    {  285,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 335: M PUNCH C */
    {  286,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 336: M PUNCH C */
    {    0,    0,    0, 0x0000,    0,    1,   66,    1 },  /* 337: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  226,    0,    0, 0x0000,    0,    1,   67,    1 },  /* 338: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  226,    0,    0, 0x0000,    0,    1,   67,    1 },  /* 339: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  131,    0,  123, 0x0000,    0,    1,   66,    1 },  /* 340: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  226,    0,  124, 0x0000,    0,    1,   67,    1 },  /* 341: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  226,    0,  124, 0x0000,    0,    1,   67,    1 },  /* 342: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  244,    0,   86, 0x0000,    0,    1,   68,    6 },  /* 343: ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  245,    0,   87, 0x0000,    0,    1,   69,    6 },  /* 344: ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    {  287,    0,  125, 0x0000,    0,    1,   70,    1 },  /* 345: ATTACK 4 S: 214+P light (plain script) */
    {  288,    0,  126, 0x0000,    0,    1,    0,    1 },  /* 346: ATTACK 4 S: 214+P light (plain script) */
    {  289,    0,  127, 0x0000,    0,    1,    0,    1 },  /* 347: ATTACK 4 S: 214+P light (plain script) */
    {  156,    0,  128, 0x0000,    0,    1,    0,    1 },  /* 348: ATTACK 4 S: 214+P light (plain script) */
    {  290,    0,  129, 0x0000,    0,    1,   71,    1 },  /* 349: ATTACK 4 S: 214+P light (plain script) */
    {  291,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 350: ATTACK 4 S: 214+P light (plain script) */
    {  292,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 351: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    {  293,    0,  130, 0x0000,    0,    1,    0,    1 },  /* 352: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  294,    0,  131, 0x0000,    0,    1,    0,    1 },  /* 353: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  295,    0,  132, 0x0000,    0,    1,    0,    1 },  /* 354: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  296,    0,  133, 0x0000,    0,    1,    0,    1 },  /* 355: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  297,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 356: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {  293,    0,  130, 0x0000,    5,    1,    0,    1 },  /* 357: ATTACK 8 L: 236+K (plain script) */
    {  298,    0,  134, 0x0000,    0,    1,    0,    1 },  /* 358: ATTACK 8 L: 236+K (plain script) */
    {  299,    0,  135, 0x0000,    0,    1,    0,    1 },  /* 359: ATTACK 8 L: 236+K (plain script) */
    {  300,    0,  136, 0x0000,    0,    1,    0,    1 },  /* 360: ATTACK 8 L: 236+K (plain script) */
    {  301,    0,  137, 0x0000,    0,    1,    0,    1 },  /* 361: ATTACK 8 L: 236+K (plain script) */
    {  302,    0,  138, 0x0000,    0,    1,    0,    1 },  /* 362: ATTACK 8 L: 236+K (plain script) */
    {  303,    0,  139, 0x0000,    0,    1,    0,    1 },  /* 363: ATTACK 8 L: 236+K (plain script) */
    {  304,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 364: ATTACK 8 L: 236+K (plain script) */
    {  305,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 365: ATTACK 8 L: 236+K (plain script) */
    {  306,    0,  140, 0x0000,    0,    1,    0,    1 },  /* 366: ATTACK 8 L: 236+K (plain script) */
    {  307,    0,  141, 0x0000,    0,    1,    0,    1 },  /* 367: ATTACK 8 L: 236+K (plain script) */
    {  308,    0,  142, 0x0000,    0,    1,    0,    1 },  /* 368: ATTACK 8 L: 236+K (plain script) */
    {  309,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 369: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  310,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 370: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  311,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 371: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {    0,    0,    0, 0x0000,    0,    0,   72,    1 },  /* 372: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  313,    0,  144, 0x0000,    0,    1,    0,    1 },  /* 373: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  314,    0,  144, 0x0000,    0,    1,    0,    1 },  /* 374: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  314,    0,  145, 0x0000,    0,    1,    0,    1 },  /* 375: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  315,    0,  146, 0x0000,    0,    1,    0,    1 },  /* 376: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  316,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 377: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    {  136,    0,    0, 0x0000,    0,    1,   73,    1 },  /* 378: ATTACK 4 SP: EX 214+PP (plain script) */
    {  141,    0,  159, 0x0000,    0,    1,   74,    1 },  /* 379: ATTACK 4 SP: EX 214+PP (plain script) */
    {  152,    0,   49, 0x0000,    0,    1,   75,    1 },  /* 380: ATTACK 4 SP: EX 214+PP (plain script) */
    {  157,    0,   53, 0x0000,    0,    1,   76,    1 },  /* 381: ATTACK 4 SP: EX 214+PP (plain script) */
    {  166,    0,   56, 0x0000,    0,    1,   77,    1 },  /* 382: ATTACK 4 SP: EX 214+PP (plain script) */
    {  173,    0,   65, 0x0000,    0,    1,   78,    1 },  /* 383: ATTACK 4 SP: EX 214+PP (plain script) */
    {  317,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 384: ATTACK 4 SP: EX 214+PP (plain script) */
    {  318,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 385: ATTACK 4 SP: EX 214+PP (plain script) */
    {  319,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 386: ATTACK 4 SP: EX 214+PP (plain script) */
    {  320,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 387: ATTACK 4 SP: EX 214+PP (plain script) */
    {  321,    0,  147, 0x0000,    0,    1,   79,    1 },  /* 388: ATTACK 4 SP: EX 214+PP (plain script) */
    {  321,    0,  148, 0x0000,    0,    1,   80,    1 },  /* 389: ATTACK 4 SP: EX 214+PP (plain script) */
    {  322,    0,  149, 0x0000,    0,    1,    0,    1 },  /* 390: ATTACK 4 SP: EX 214+PP (plain script) */
    {  322,    0,  150, 0x0000,    0,    1,    0,    1 },  /* 391: ATTACK 4 SP: EX 214+PP (plain script) */
    {  322,    0,  151, 0x0000,    0,    1,    0,    1 },  /* 392: ATTACK 4 SP: EX 214+PP (plain script) */
    {  323,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 393: AIR NORMAL */
    {  324,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 394: ASIBARAI SIRI, HUMI ASIB */
    {  325,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 395: ASIBARAI SIRI, HUMI ASIB */
    {  326,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 396: ASIBARAI SIRI, HUMI ASIB */
    {  327,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 397: ASIBARAI SIRI, HUMI ASIB */
    {  328,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 398: ASIB TUNNOMERI */
    {  329,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 399: ASIB TUNNOMERI */
    {  330,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 400: NOKEZORI, HARAYARARE, TATAKI AIR +4 */
    {  331,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 401: NOKEZORI, HARAYARARE, TATAKI AIR +2 */
    {  332,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 402: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  333,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 403: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  334,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 404: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  335,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 405: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  336,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 406: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  337,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 407: NOKEZORI, KIRIMOMI, UPPER +7 */
    {  338,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 408: KUNOJI, KUNOJI NOKE */
    {  339,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 409: KUNOJI */
    {  340,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 410: KUNOJI */
    {  341,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 411: KUNOJI */
    {  342,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 412: KIRIMOMI */
    {  343,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 413: KIRIMOMI */
    {  344,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 414: KIRIMOMI */
    {  345,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 415: KIRIMOMI */
    {  346,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 416: KIRIMOMI */
    {  347,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 417: KIRIMOMI */
    {  348,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 418: KIRIMOMI */
    {  349,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 419: KIRIMOMI */
    {  350,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 420: UPPER, TATUMAKIZANKU */
    {  351,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 421: UPPER, TATUMAKIZANKU */
    {  352,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 422: UPPER, TATUMAKIZANKU */
    {  353,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 423: UPPER, BODY UPPER, FACE +1 */
    {  354,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 424: BODY UPPER, HANEKAERI HARA */
    {  355,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 425: BODY UPPER */
    {  356,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 426: BODY UPPER */
    {  357,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 427: BODY UPPER */
    {  358,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 428: BODY UPPER */
    {  359,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 429: TTKI V. AIR */
    {  360,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 430: TTKI V. AIR */
    {  361,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 431: FACE */
    {  362,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 432: DENKI */
    {  222,    0,  152, 0x0000,    0,    1,    0,    6 },  /* 433: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  223,    0,  153, 0x0000,    0,    1,    0,    6 },  /* 434: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  363,    0,  154, 0x0000,    0,    1,    0,    1 },  /* 435: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  364,    0,  155, 0x0000,    0,    1,    0,    1 },  /* 436: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  365,    0,  156, 0x0000,    0,    1,   81,    1 },  /* 437: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  366,    0,  157, 0x0000,    0,    1,   82,    1 },  /* 438: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  367,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 439: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  368,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 440: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  369,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 441: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  370,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 442: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    {  371,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 443: L KICK A */
    {    1,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 444: KAMAE, KAGAMU */
    {  372,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 445: KAMAE, STAND UP */
    {  373,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 446: KAMAE */
    {  374,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 447: HURIMUKI */
    {    2,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 448: KAGAMI KAMAE, STAND UP */
    {  375,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 449: KAGAMU, KAGAMI KAMAE */
    {  376,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 450: KAGAMI TURN */
    {  377,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 451: KAGAMU */
    {  378,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 452: STAND UP, UP P GUARD P M */
    {  379,    0,    0, 0x1010,    0,    3,    0,    1 },  /* 453: STAND UP */
    {  236,    0,    0, 0x1010,    0,    3,    0,    1 },  /* 454: SP JUMP JUNBI */
    {  113,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 455: JUMP FRONT, JUMP VERTICAL, JUMP BACK +3 */
    {  114,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 456: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  115,    0,    0, 0x1010,    0,    3,    0,    3 },  /* 457: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  380,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 458: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {  381,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 459: FRONT WALK */
    {  382,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 460: FRONT WALK */
    {  383,    0,    0, 0x1414,    0,    1,    0,    1 },  /* 461: FRONT WALK */
    {  384,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 462: FRONT WALK */
    {  385,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 463: FRONT WALK */
    {  386,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 464: BACK WALK */
    {  387,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 465: BACK WALK */
    {  388,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 466: BACK WALK */
    {  389,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 467: BACK WALK */
    {  390,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 468: BACK WALK */
    {  391,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 469: BACK WALK */
    {  111,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 470: DASH HUMIKOMI */
    {  112,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 471: DASH HUMIKOMI */
    {  116,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 472: DASH HUMIKOMI */
    {  117,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 473: DASH HUMIKOMI */
    {  118,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 474: DASH HUMIKOMI */
    {  119,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 475: DASH HUMIKOMI */
    {  120,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 476: not used by a script */
    {  121,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 477: DASH TOBINOKI */
    {  122,    0,    0, 0x1414,    0,    4,    0,    5 },  /* 478: DASH TOBINOKI */
    {  124,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 479: DASH TOBINOKI */
    {  126,    0,    0, 0x1010,    0,    4,    0,    5 },  /* 480: DASH TOBINOKI */
    {  127,    0,    0, 0x0000,    0,    4,    0,    5 },  /* 481: DASH TOBINOKI */
    {  128,    0,    0, 0x1414,    0,    4,    0,    5 },  /* 482: DASH TOBINOKI */
    {  130,    0,    0, 0x1616,    0,    1,    0,    1 },  /* 483: DASH TOBINOKI */
    {  392,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 484: PIYO */
    {  393,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 485: PIYO */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 486: LOSE SONABA, SHIMEOTASARE */
    {  244,    0,   86, 0x0000,    0,    1,    0,    6 },  /* 487: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  365,    0,  156, 0x0000,    0,    1,    0,    1 },  /* 488: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
};

const BODY_BOX q_body_box[394] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -18,  23, 109,  18 },  {  -24,  48,  82,  27 },  {  -24,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +100 */
    { { {  -10,  22,  58,  19 },  {  -20,  54,  43,  17 },  {  -21,  59,  24,  18 },  {  -33,  63,   0,  23 } } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +21 */
    { { {  -14,  22, 100,  18 },  {  -26,  56,  73,  31 },  {  -30,  60,  46,  30 },  {  -36,  68,   0,  49 } } },  /* 3: M PUNCH A */
    { { {  -54,  22,  95,  16 },  {  -54,  67,  69,  31 },  {  -41,  52,  40,  29 },  {  -56,  79,   0,  47 } } },  /* 4: M PUNCH A */
    { { {   -1,  22, 105,  18 },  {  -32,  68,  76,  29 },  {  -35,  60,  46,  30 },  {  -37,  59,   0,  46 } } },  /* 5: L PUNCH A, L PUNCH C */
    { { {  -20,  22, 105,  18 },  {  -34,  68,  76,  29 },  {  -40,  60,  46,  30 },  {  -40,  59,   0,  46 } } },  /* 6: L PUNCH A, L PUNCH C */
    { { {  -28,  22, 101,  18 },  {  -45,  68,  75,  29 },  {  -40,  60,  46,  30 },  {  -53,  84,   0,  46 } } },  /* 7: L PUNCH A, L PUNCH C */
    { { {    0,   0,   0,   0 },  {  -45,  68,  75,  29 },  {  -40,  60,  46,  30 },  {  -53,  84,   0,  46 } } },  /* 8: L PUNCH A, L PUNCH C */
    { { {  -22,  22,  73,  18 },  {  -40,  63,  61,  20 },  {  -38,  61,  36,  27 },  {  -40,  65,   0,  36 } } },  /* 9: L PUNCH A, L PUNCH C */
    { { {  -20,  22, 102,  18 },  {  -24,  56,  79,  31 },  {  -32,  60,  49,  30 },  {  -40,  57,   0,  49 } } },  /* 10: S KICK A */
    { { {   -6,  22, 106,  18 },  {  -21,  56,  79,  31 },  {  -28,  60,  49,  30 },  {  -30,  57,   0,  49 } } },  /* 11: M KICK A */
    { { {  -17,  22, 107,  18 },  {  -31,  51,  79,  31 },  {  -47,  52,  49,  37 },  {  -63,  71,   0,  49 } } },  /* 12: M KICK A */
    { { {  -45,  22,  89,  18 },  {  -51,  59,  63,  35 },  {  -65,  67,  36,  34 },  {  -72,  80,   0,  49 } } },  /* 13: M KICK A */
    { { {  -41,  22,  97,  18 },  {  -45,  56,  65,  39 },  {  -54,  58,  43,  30 },  {  -64,  74,   0,  49 } } },  /* 14: M KICK A */
    { { {   10,  22, 101,  18 },  {   -4,  62,  73,  31 },  {  -40,  83,  44,  40 },  {  -29,  62,   0,  44 } } },  /* 15: M KICK B */
    { { {    5,  22, 101,  18 },  {  -10,  62,  73,  31 },  {  -38,  81,  44,  40 },  {  -29,  62,   0,  44 } } },  /* 16: M KICK B */
    { { {  -32,  22, 103,  18 },  {  -37,  59,  82,  26 },  {  -41,  63,  48,  34 },  {  -34,  68,   0,  49 } } },  /* 17: L KICK C */
    { { {  -37,  22,  94,  18 },  {  -38,  64,  75,  31 },  {  -32,  68,  41,  34 },  {  -32,  77,   0,  41 } } },  /* 18: L KICK C */
    { { {  -46,  22,  98,  18 },  {  -41,  69,  70,  38 },  {  -28,  75,  36,  34 },  {  -26,  88,   0,  50 } } },  /* 19: L KICK C */
    { { {  -51,  22, 103,  18 },  {  -52,  74,  82,  26 },  {  -51,  79,  55,  27 },  {  -37,  80,   0,  55 } } },  /* 20: L KICK C */
    { { {  -20,  22, 108,  18 },  {  -26,  49,  86,  27 },  {  -43,  69,  60,  27 },  {  -56,  87,   0,  60 } } },  /* 21: L KICK C */
    { { {   -2,  22, 108,  18 },  {  -33,  91,  80,  33 },  {  -29,  64,  49,  32 },  {  -31,  73,   0,  49 } } },  /* 22: L KICK C */
    { { {    7,  22, 104,  18 },  {  -33,  82,  80,  29 },  {  -34,  64,  49,  32 },  {  -38,  70,   0,  49 } } },  /* 23: L KICK C */
    { { {   18,  22,  92,  18 },  {  -52, 101,  82,  33 },  {  -51,  79,  56,  26 },  {  -60,  68,   0,  57 } } },  /* 24: L KICK C */
    { { {   47,  22,  17,  18 },  {    4,  43,   0,  55 },  {  -46,  54,   0,  69 },  {  -88,  43,   0,  46 } } },  /* 25: L KICK C */
    { { {   47,  22,   6,  18 },  {   10,  38,   0,  38 },  {  -15,  41,   0,  55 },  {  -81,  67,   0,  44 } } },  /* 26: L KICK C */
    { { {  -26,  22, 102,  18 },  {  -36,  54,  79,  31 },  {  -48,  65,  49,  30 },  {  -34,  54,   0,  49 } } },  /* 27: L KICK A */
    { { {  -18,  22, 100,  18 },  {  -49,  69,  79,  34 },  {  -38,  58,  59,  20 },  {  -45,  62,   0,  59 } } },  /* 28: L KICK A */
    { { {  -38,  53, 106,  19 },  {  -37,  54,  79,  27 },  {  -46,  59,  49,  30 },  {  -39,  54,   0,  49 } } },  /* 29: L KICK A */
    { { {  -13,  22, 108,  18 },  {  -27,  61,  88,  24 },  {  -43,  64,  48,  40 },  {  -30,  54,   0,  48 } } },  /* 30: L KICK A */
    { { {  -23,  22, 102,  18 },  {  -35,  55,  88,  22 },  {  -39,  58,  48,  40 },  {  -40,  62,   0,  48 } } },  /* 31: L KICK A */
    { { {  -24,  22, 102,  18 },  {  -37,  54,  84,  24 },  {  -43,  56,  48,  36 },  {  -42,  56,   0,  48 } } },  /* 32: L KICK A */
    { { {  -32,  22,  91,  18 },  {  -39,  54,  73,  24 },  {  -55,  69,  48,  36 },  {  -56,  69,   0,  48 } } },  /* 33: L KICK A */
    { { {  -26,  24,  59,  18 },  {  -34,  60,  46,  18 },  {  -23,  59,  22,  26 },  {  -37,  75,   0,  24 } } },  /* 34: KAGAMI P A */
    { { {  -22,  22,  68,  18 },  {  -30,  52,  48,  22 },  {  -28,  58,  35,  18 },  {  -46,  69,   0,  39 } } },  /* 35: KAGAMI P A */
    { { {  -35,  22,  73,  18 },  {  -34,  44,  50,  27 },  {  -31,  51,  42,  28 },  {  -48,  71,   0,  42 } } },  /* 36: KAGAMI P A */
    { { {  -41,  22,  75,  18 },  {  -53,  61,  51,  26 },  {  -42,  43,  36,  20 },  {  -54,  69,   0,  42 } } },  /* 37: KAGAMI P A */
    { { {  -22,  22,  60,  18 },  {  -25,  51,  42,  33 },  {  -21,  47,  22,  20 },  {  -42,  69,   0,  26 } } },  /* 38: KAGAMI P A */
    { { {  -19,  22,  61,  18 },  {  -17,  52,  47,  33 },  {  -22,  48,  22,  25 },  {  -46,  70,   0,  28 } } },  /* 39: KAGAMI P A */
    { { {  -25,  22,  68,  18 },  {  -30,  50,  47,  36 },  {  -31,  45,  22,  25 },  {  -48,  68,   0,  30 } } },  /* 40: KAGAMI P A */
    { { {  -36,  22,  71,  18 },  {  -39,  50,  47,  39 },  {  -34,  52,  24,  32 },  {  -48,  68,   0,  27 } } },  /* 41: KAGAMI P A */
    { { {  -66,  22,  47,  18 },  {  -52,  63,  35,  36 },  {  -67,  61,  27,  20 },  {  -71,  89,   0,  38 } } },  /* 42: KAGAMI P A */
    { { {  -38,  22,  56,  18 },  {  -35,  55,  39,  25 },  {  -37,  63,  26,  22 },  {  -60,  83,   0,  37 } } },  /* 43: KAGAMI P A */
    { { {  -10,  22,  50,  18 },  {  -16,  53,  37,  18 },  {  -23,  63,  23,  20 },  {  -38,  81,   0,  30 } } },  /* 44: KAGAMI K A */
    { { {   -6,  22,  45,  18 },  {  -24,  57,  35,  18 },  {  -33,  72,  23,  20 },  {  -38,  82,   0,  26 } } },  /* 45: KAGAMI K A */
    { { {   -5,  22,  47,  18 },  {  -40,  69,  35,  17 },  {  -45,  80,  17,  18 },  {  -38,  79,   0,  22 } } },  /* 46: KAGAMI K A */
    { { {  -14,  22,  56,  18 },  {  -13,  49,  33,  28 },  {  -17,  58,  20,  23 },  {  -45,  75,   0,  34 } } },  /* 47: KAGAMI K A */
    { { {  -10,  22,  57,  18 },  {  -10,  51,  33,  29 },  {  -15,  59,  20,  23 },  {  -45,  64,   0,  48 } } },  /* 48: KAGAMI K A */
    { { {    2,  22,  58,  18 },  {   -5,  54,  33,  28 },  {   -5,  60,  16,  27 },  {  -53,  73,   0,  48 } } },  /* 49: KAGAMI K A */
    { { {    5,  22,  59,  18 },  {   -7,  50,  35,  25 },  {  -11,  58,  20,  26 },  {  -49,  70,   0,  41 } } },  /* 50: KAGAMI K A */
    { { {   -1,  22,  60,  18 },  {   -7,  43,  36,  25 },  {  -10,  53,  20,  26 },  {  -35,  62,   0,  41 } } },  /* 51: KAGAMI K A */
    { { {   25,  22,  53,  18 },  {  -23,  65,  32,  27 },  {  -17,  60,  21,  16 },  {  -29,  63,   0,  25 } } },  /* 52: KAGAMI K A */
    { { {   24,  22,  48,  18 },  {  -25,  37,  43,  23 },  {  -17,  63,  21,  37 },  {  -19,  66,   0,  21 } } },  /* 53: KAGAMI K A */
    { { {   28,  22,  47,  18 },  {   -9,  37,  39,  33 },  {  -11,  62,  21,  26 },  {  -15,  68,   0,  21 } } },  /* 54: KAGAMI K A */
    { { {   35,  22,  41,  18 },  {   11,  28,  36,  34 },  {   -3,  47,  26,  25 },  {  -21,  74,   0,  37 } } },  /* 55: KAGAMI K A */
    { { {   28,  23,  31,  41 },  {   -1,  38,   0,  59 },  {  -26,  36,   0,  54 },  {  -54,  28,   0,  44 } } },  /* 56: KAGAMI K A */
    { { {   55,  28,  27,  34 },  {   17,  38,   0,  61 },  {  -19,  36,   6,  56 },  {  -93,  75,  17,  47 } } },  /* 57: KAGAMI K A */
    { { {   39,  30,  19,  36 },  {    7,  39,   0,  50 },  {  -37,  45,   0,  57 },  {  -81,  44,  11,  36 } } },  /* 58: KAGAMI K A */
    { { {   33,  29,   0,  35 },  {   -5,  38,   0,  32 },  {  -37,  32,   0,  39 },  {  -58,  21,   0,  30 } } },  /* 59: KAGAMI K A */
    { { {   28,  23,   0,  32 },  {   -5,  33,   0,  30 },  {  -37,  32,   0,  34 },  {  -57,  20,   0,  39 } } },  /* 60: KAGAMI K A */
    { { {   17,  24,   0,  34 },  {   -5,  28,   0,  45 },  {  -33,  29,   0,  41 },  {  -57,  24,   0,  37 } } },  /* 61: KAGAMI K A */
    { { {   22,  22,  28,  18 },  {   -2,  33,   0,  62 },  {  -28,  26,   0,  57 },  {  -47,  19,   0,  42 } } },  /* 62: KAGAMI K A */
    { { {   24,  22,  41,  18 },  {   -3,  38,   1,  72 },  {  -26,  23,  10,  56 },  {  -38,  12,  11,  32 } } },  /* 63: KAGAMI K A */
    { { {    9,  22,  52,  18 },  {  -16,  40,  17,  60 },  {  -29,  19,  21,  46 },  {  -44,  15,  21,  33 } } },  /* 64: KAGAMI K A */
    { { {  -33,  22, 110,  18 },  {  -48,  67,  87,  32 },  {  -42,  57,  59,  28 },  {  -44,  62,  44,  15 } } },  /* 65: V JUMP P S A, F JUMP P S A */
    { { {  -45,  22, 104,  18 },  {  -48,  71,  82,  33 },  {  -44,  63,  55,  27 },  {  -37,  65,  41,  19 } } },  /* 66: V JUMP P S A */
    { { {  -22,  22, 108,  18 },  {  -51,  67,  78,  32 },  {  -48,  57,  55,  28 },  {  -46,  57,  42,  13 } } },  /* 67: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -31,  22, 108,  18 },  {  -52,  67,  79,  34 },  {  -48,  63,  55,  28 },  {  -42,  53,  42,  13 } } },  /* 68: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -35,  22, 108,  18 },  {  -52,  67,  79,  34 },  {  -48,  63,  55,  28 },  {  -38,  57,  38,  17 } } },  /* 69: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -31,  22, 108,  18 },  {  -52,  67,  79,  34 },  {  -48,  63,  55,  28 },  {  -38,  57,  38,  17 } } },  /* 70: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -43,  22, 108,  18 },  {  -50,  67,  79,  34 },  {  -44,  70,  55,  28 },  {  -34,  69,  35,  30 } } },  /* 71: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -21,  22, 109,  18 },  {  -30,  58,  79,  32 },  {  -36,  65,  55,  24 },  {  -38,  67,  25,  30 } } },  /* 72: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -17,  22, 110,  18 },  {  -28,  55,  79,  31 },  {  -36,  70,  55,  30 },  {  -34,  60,  25,  30 } } },  /* 73: V JUMP P M A, V JUMP P L A, F JUMP P M A +3 */
    { { {  -13,  22, 109,  18 },  {  -44,  74,  94,  25 },  {  -31,  55,  66,  28 },  {  -26,  56,  51,  15 } } },  /* 74: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {   -7,  22, 107,  18 },  {  -42,  76,  92,  23 },  {  -31,  55,  66,  28 },  {  -26,  56,  51,  15 } } },  /* 75: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -11,  22, 106,  18 },  {  -40,  76,  88,  21 },  {  -29,  53,  66,  28 },  {  -26,  56,  51,  15 } } },  /* 76: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -56,  22,  99,  18 },  {  -53,  73,  74,  36 },  {  -36,  64,  52,  32 },  {  -30,  60,  33,  19 } } },  /* 77: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -52,  22,  91,  18 },  {  -53,  67,  66,  36 },  {  -36,  62,  52,  32 },  {  -43,  60,  33,  27 } } },  /* 78: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -49,  22,  91,  18 },  {  -51,  65,  66,  36 },  {  -36,  62,  52,  32 },  {  -43,  60,  33,  27 } } },  /* 79: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -44,  22,  96,  18 },  {  -62,  73,  69,  36 },  {  -38,  59,  54,  29 },  {  -32,  60,  35,  19 } } },  /* 80: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -27,  22,  99,  18 },  {  -37,  59,  73,  32 },  {  -48,  69,  60,  19 },  {  -34,  57,  25,  35 } } },  /* 81: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -33,  22, 112,  18 },  {  -47,  65,  87,  26 },  {  -38,  54,  59,  28 },  {  -44,  68,  44,  15 } } },  /* 82: V JUMP K S A */
    { { {  -37,  22, 112,  18 },  {  -49,  58,  79,  46 },  {  -45,  63,  59,  20 },  {  -34,  62,  42,  17 } } },  /* 83: V JUMP K S A */
    { { {  -48,  22, 112,  18 },  {  -44,  59,  87,  37 },  {  -51,  62,  59,  28 },  {  -64,  80,  42,  22 } } },  /* 84: V JUMP K S A */
    { { {  -47,  22, 105,  18 },  {  -52,  74,  91,  25 },  {  -40,  56,  59,  32 },  {  -47,  68,  42,  21 } } },  /* 85: V JUMP K S A, ATTACK 10 S: not started by a command */
    { { {  -40,  22, 107,  18 },  {  -45,  67,  85,  28 },  {  -46,  67,  59,  26 },  {  -53,  78,  42,  24 } } },  /* 86: V JUMP K S A, ATTACK 10 S: not started by a command */
    { { {  -28,  22, 108,  18 },  {  -36,  60,  85,  28 },  {  -55,  84,  59,  30 },  {  -52,  77,  42,  17 } } },  /* 87: V JUMP K M A, ATTACK 10 S: not started by a command */
    { { {  -15,  22, 108,  18 },  {  -40,  72,  85,  26 },  {  -37,  73,  59,  26 },  {  -44,  84,  44,  15 } } },  /* 88: V JUMP K M A */
    { { {  -16,  22, 110,  18 },  {  -50,  83,  94,  22 },  {  -35,  70,  59,  35 },  {  -47,  79,  44,  15 } } },  /* 89: V JUMP K M A */
    { { {  -11,  22, 113,  18 },  {  -59,  94, 106,  20 },  {  -38,  69,  59,  47 },  {  -47,  79,  44,  15 } } },  /* 90: V JUMP K M A */
    { { {  -15,  22, 113,  18 },  {  -59,  94, 106,  20 },  {  -47,  78,  59,  47 },  {  -54,  86,  44,  15 } } },  /* 91: V JUMP K M A */
    { { {  -25,  22, 113,  18 },  {  -59,  94, 106,  20 },  {  -47,  78,  59,  47 },  {  -54,  86,  44,  15 } } },  /* 92: V JUMP K M A */
    { { {  -29,  22, 113,  18 },  {  -59,  84, 106,  20 },  {  -47,  78,  59,  47 },  {  -54,  86,  44,  15 } } },  /* 93: V JUMP K M A */
    { { {  -27,  22, 110,  18 },  {  -40,  65,  85,  30 },  {  -46,  77,  59,  26 },  {  -55,  84,  44,  28 } } },  /* 94: V JUMP K M A */
    { { {  -32,  22, 107,  18 },  {  -55,  74,  89,  23 },  {  -37,  62,  67,  22 },  {  -53,  80,  44,  33 } } },  /* 95: V JUMP K M A */
    { { {  -43,  22,  98,  18 },  {  -48,  69,  85,  27 },  {  -62,  81,  59,  26 },  {  -58,  81,  42,  17 } } },  /* 96: V JUMP K L A, S V JP S P A */
    { { {  -42,  22,  83,  18 },  {  -48,  64,  85,  25 },  {  -56,  75,  59,  26 },  {  -55,  78,  46,  18 } } },  /* 97: V JUMP K L A, S V JP S P A */
    { { {  -44,  22,  65,  18 },  {  -50,  68,  85,  26 },  {  -55,  77,  59,  26 },  {  -45,  62,  48,  11 } } },  /* 98: V JUMP K L A, S V JP S P A */
    { { {  -23,  22,  60,  18 },  {  -53,  80,  85,  30 },  {  -49,  75,  65,  20 },  {  -42,  62,  56,   9 } } },  /* 99: V JUMP K L A, S V JP S P A */
    { { {    4,  22,  89,  18 },  {  -44,  63, 106,  23 },  {  -53,  77,  79,  27 },  {  -46,  62,  60,  19 } } },  /* 100: V JUMP K L A, S V JP S P A */
    { { {   -4,  22,  95,  18 },  {  -63,  83, 107,  25 },  {  -58,  88,  81,  34 },  {  -48,  67,  68,  13 } } },  /* 101: V JUMP K L A, S V JP S P A */
    { { {   -1,  22,  67,  18 },  {  -72,  96, 100,  25 },  {  -65, 102,  81,  19 },  {  -57, 108,  59,  22 } } },  /* 102: V JUMP K L A, S V JP S P A */
    { { {   10,  22, 100,  18 },  {  -75, 100,  83,  38 },  {  -92,  79,  68,  32 },  { -101,  54,  51,  23 } } },  /* 103: V JUMP K L A, S V JP S P A */
    { { {    8,  22, 106,  18 },  {  -71,  95,  85,  33 },  {  -84,  75,  68,  32 },  {  -97,  56,  51,  19 } } },  /* 104: V JUMP K L A, S V JP S P A */
    { { {    2,  22, 112,  18 },  {  -56, 104,  91,  24 },  {  -66,  97,  82,  21 },  {  -77,  67,  51,  31 } } },  /* 105: V JUMP K L A, S V JP S P A */
    { { {  -14,  22, 114,  18 },  {  -54,  94,  90,  26 },  {  -51,  66,  77,  18 },  {  -58,  60,  50,  31 } } },  /* 106: V JUMP K L A, S V JP S P A */
    { { {  -26,  22, 112,  18 },  {  -51,  81,  93,  24 },  {  -40,  48,  65,  28 },  {  -46,  49,  37,  28 } } },  /* 107: V JUMP K L A, S V JP S P A */
    { { {  -26,  22, 110,  18 },  {  -41,  62,  93,  19 },  {  -41,  54,  65,  28 },  {  -55,  61,  42,  24 } } },  /* 108: V JUMP K L A, S V JP S P A */
    { { {  -29,  22, 104,  18 },  {  -36,  58,  85,  21 },  {  -41,  61,  65,  22 },  {  -52,  59,  42,  23 } } },  /* 109: V JUMP K L A, S V JP S P A */
    { { {  -47,  22,  96,  18 },  {  -40,  68,  82,  33 },  {  -61,  80,  55,  35 },  {  -37,  65,  41,  19 } } },  /* 110: F JUMP P S A */
    { { {  -28,  22, 100,  18 },  {  -37,  59,  72,  30 },  {  -31,  55,  50,  22 },  {  -40,  73,   0,  55 } } },  /* 111: DASH HUMIKOMI */
    { { {  -16,  22, 100,  18 },  {  -43,  67,  72,  30 },  {  -27,  59,  50,  22 },  {  -46,  87,   0,  53 } } },  /* 112: DASH HUMIKOMI */
    { { {  -37,  22, 102,  18 },  {  -40,  62,  78,  33 },  {  -45,  70,  45,  33 },  {  -42,  64,  32,  13 } } },  /* 113: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +8 */
    { { {  -27,  22, 106,  18 },  {  -36,  58,  78,  33 },  {  -45,  70,  45,  40 },  {  -40,  60,  39,   6 } } },  /* 114: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -18,  22, 108,  18 },  {  -32,  54,  78,  33 },  {  -42,  74,  45,  40 },  {  -36,  58,  31,  14 } } },  /* 115: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -23,  22, 101,  18 },  {  -47,  65,  72,  30 },  {  -31,  57,  45,  27 },  {  -38,  79,   0,  44 } } },  /* 116: DASH HUMIKOMI */
    { { {  -34,  22,  94,  18 },  {  -38,  52,  75,  22 },  {  -43,  68,  39,  35 },  {  -42,  83,   0,  38 } } },  /* 117: DASH HUMIKOMI */
    { { {  -38,  22,  90,  18 },  {  -34,  48,  73,  28 },  {  -30,  54,  37,  36 },  {  -33,  64,   0,  36 } } },  /* 118: DASH HUMIKOMI */
    { { {  -39,  22,  95,  18 },  {  -29,  48,  74,  32 },  {  -32,  56,  39,  35 },  {  -32,  56,   0,  38 } } },  /* 119: DASH HUMIKOMI */
    { { {  -28,  22, 103,  18 },  {  -33,  52,  67,  40 },  {  -40,  59,  49,  20 },  {  -40,  64,   0,  49 } } },  /* 120: not used by a script */
    { { {    4,  22, 107,  18 },  {  -19,  52,  75,  32 },  {  -29,  59,  47,  27 },  {  -40,  77,   0,  46 } } },  /* 121: DASH TOBINOKI */
    { { {   23,  22, 107,  18 },  {   -7,  52,  75,  32 },  {  -29,  72,  47,  27 },  {  -32,  77,   0,  46 } } },  /* 122: DASH TOBINOKI */
    { { {  -28,  22, 103,  18 },  {  -33,  52,  67,  40 },  {  -40,  59,  49,  20 },  {  -40,  64,   0,  49 } } },  /* 123: not used by a script */
    { { {  -15,  22, 107,  18 },  {  -27,  52,  75,  32 },  {  -30,  64,  47,  27 },  {  -30,  68,   0,  46 } } },  /* 124: DASH TOBINOKI */
    { { {  -28,  22, 103,  18 },  {  -33,  52,  67,  40 },  {  -40,  59,  49,  20 },  {  -40,  64,   0,  49 } } },  /* 125: not used by a script */
    { { {  -27,  22, 107,  18 },  {  -31,  52,  75,  32 },  {  -40,  64,  47,  27 },  {  -40,  68,   0,  46 } } },  /* 126: DASH TOBINOKI */
    { { {  -17,  22,  97,  18 },  {  -29,  52,  75,  26 },  {  -36,  59,  43,  30 },  {  -40,  64,   0,  42 } } },  /* 127: DASH TOBINOKI */
    { { {  -15,  22,  93,  18 },  {  -23,  50,  75,  20 },  {  -32,  59,  37,  36 },  {  -44,  72,   0,  36 } } },  /* 128: DASH TOBINOKI */
    { { {  -28,  22, 103,  18 },  {  -33,  52,  67,  40 },  {  -40,  59,  49,  20 },  {  -40,  64,   0,  49 } } },  /* 129: not used by a script */
    { { {  -34,  22,  95,  18 },  {  -30,  52,  74,  30 },  {  -32,  56,  39,  34 },  {  -36,  61,   0,  38 } } },  /* 130: DASH TOBINOKI */
    { { {  -35,  22,  82,  18 },  {  -41,  81,  66,  28 },  {  -20,  74,  33,  31 },  {  -21,  84,   0,  33 } } },  /* 131: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {   -3,  22, 103,  18 },  {   -6,  68,  79,  29 },  {  -22,  79,  56,  31 },  {  -31,  69,   0,  56 } } },  /* 132: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -28,  22, 101,  18 },  {  -35,  90,  74,  30 },  {  -30,  59,  50,  31 },  {  -42,  76,   0,  56 } } },  /* 133: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -40,  22,  99,  18 },  {  -37,  84,  74,  30 },  {  -32,  48,  50,  28 },  {  -44,  76,   0,  56 } } },  /* 134: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -41,  22,  98,  18 },  {  -33,  59,  74,  30 },  {  -32,  48,  50,  28 },  {  -44,  76,   0,  56 } } },  /* 135: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -38,  22, 100,  18 },  {  -82, 109,  79,  31 },  {  -39,  57,  49,  30 },  {  -47,  71,   0,  49 } } },  /* 136: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -32,  22, 107,  18 },  {  -42,  69,  79,  31 },  {  -39,  57,  49,  30 },  {  -47,  71,   0,  49 } } },  /* 137: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -32,  22, 101,  18 },  {  -40,  67,  79,  35 },  {  -35,  53,  49,  30 },  {  -43,  67,   0,  49 } } },  /* 138: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -32,  22, 101,  18 },  {  -28,  51,  79,  45 },  {  -31,  49,  49,  30 },  {  -41,  65,   0,  49 } } },  /* 139: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -27,  22, 105,  18 },  {  -28,  58,  79,  27 },  {  -34,  52,  49,  30 },  {  -37,  61,   0,  49 } } },  /* 140: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -27,  22, 101,  18 },  {  -77,  99,  80,  25 },  {  -36,  54,  49,  31 },  {  -44,  68,   0,  49 } } },  /* 141: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -25,  22, 101,  18 },  {  -36,  62,  80,  25 },  {  -36,  54,  49,  31 },  {  -44,  68,   0,  49 } } },  /* 142: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -30,  22, 100,  18 },  {  -34,  82,  80,  25 },  {  -36,  54,  49,  31 },  {  -44,  68,   0,  49 } } },  /* 143: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -38,  22,  90,  18 },  {  -44,  64,  79,  27 },  {  -38,  64,  49,  31 },  {  -42,  66,   0,  49 } } },  /* 144: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -41,  22,  85,  18 },  {  -44,  63,  67,  29 },  {  -35,  58,  49,  24 },  {  -42,  64,   0,  49 } } },  /* 145: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -40,  22,  85,  18 },  {  -51,  64,  62,  32 },  {  -34,  50,  47,  24 },  {  -44,  60,   0,  47 } } },  /* 146: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -44,  22,  85,  18 },  {  -38,  50,  65,  35 },  {  -52,  68,  47,  24 },  {  -47,  60,   0,  47 } } },  /* 147: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -42,  22,  89,  18 },  {  -36,  52,  65,  39 },  {  -48,  68,  47,  24 },  {  -43,  62,   0,  47 } } },  /* 148: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -29,  22,  98,  18 },  {  -34,  88,  75,  26 },  {  -30,  50,  56,  23 },  {  -43,  77,   0,  56 } } },  /* 149: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script) */
    { { {  -39,  22,  98,  18 },  {  -41,  89,  75,  26 },  {  -33,  47,  56,  23 },  {  -50,  75,   0,  56 } } },  /* 150: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -39,  22,  98,  18 },  {  -32,  58,  75,  27 },  {  -35,  52,  48,  27 },  {  -49,  78,   0,  48 } } },  /* 151: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -31,  22,  97,  18 },  {  -38,  70,  75,  27 },  {  -31,  49,  48,  27 },  {  -52,  82,   0,  48 } } },  /* 152: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -36,  32,  99,  34 },  {  -37,  69,  75,  27 },  {  -31,  49,  48,  27 },  {  -46,  76,   0,  48 } } },  /* 153: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -30,  22,  98,  18 },  {  -42,  63,  75,  29 },  {  -35,  53,  48,  27 },  {  -46,  73,   0,  48 } } },  /* 154: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -29,  22,  99,  18 },  {  -28,  53,  75,  29 },  {  -31,  49,  48,  27 },  {  -42,  72,   0,  48 } } },  /* 155: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -26,  22,  99,  18 },  {  -32,  61,  75,  29 },  {  -33,  49,  48,  27 },  {  -36,  66,   0,  48 } } },  /* 156: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script), ATTACK 4 S: 214+P light (plain script) */
    { { {  -25,  22, 100,  18 },  {  -32,  55,  75,  30 },  {  -33,  49,  48,  27 },  {  -42,  72,   0,  48 } } },  /* 157: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -25,  22, 100,  18 },  {  -32,  55,  75,  30 },  {  -33,  49,  48,  27 },  {  -42,  72,   0,  48 } } },  /* 158: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -30,  22,  99,  18 },  {  -32,  55,  75,  30 },  {  -29,  49,  48,  27 },  {  -42,  72,   0,  48 } } },  /* 159: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -42,  22,  84,  18 },  {  -38,  53,  72,  30 },  {  -38,  57,  48,  30 },  {  -41,  65,   0,  49 } } },  /* 160: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -39,  22,  95,  18 },  {  -32,  48,  78,  30 },  {  -37,  57,  49,  30 },  {  -34,  56,   0,  49 } } },  /* 161: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {  -28,  22, 106,  18 },  {  -29,  51,  80,  30 },  {  -34,  57,  50,  30 },  {  -35,  59,   0,  50 } } },  /* 162: ATTACK 4 S: 214+P light (plain script), ATTACK 4 M: 214+P medium (plain script), ATTACK 4 L: 214+P heavy (plain script) +1 */
    { { {    3,  22, 102,  18 },  {   -4,  59,  79,  28 },  {  -22,  83,  56,  31 },  {  -35,  73,   0,  56 } } },  /* 163: not used by a script */
    { { {  -15,  22,  99,  18 },  {  -35,  59,  78,  24 },  {  -38,  71,  51,  27 },  {  -46,  85,   0,  51 } } },  /* 164: not used by a script */
    { { {  -13,  22,  95,  18 },  {  -27,  63,  78,  21 },  {  -40,  73,  51,  27 },  {  -48,  87,   0,  51 } } },  /* 165: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   -7,  22,  94,  18 },  {  -26,  68,  78,  21 },  {  -42,  79,  51,  27 },  {  -50,  89,   0,  51 } } },  /* 166: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   -7,  22,  98,  18 },  {  -29,  52,  78,  24 },  {  -35,  72,  51,  27 },  {  -48,  87,   0,  51 } } },  /* 167: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   -6,  22, 102,  18 },  {  -26,  55,  78,  25 },  {  -27,  63,  51,  27 },  {  -45,  84,   0,  51 } } },  /* 168: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -10,  22, 102,  18 },  {  -26,  55,  78,  25 },  {  -24,  60,  51,  27 },  {  -43,  82,   0,  51 } } },  /* 169: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -16,  22, 101,  18 },  {  -21,  57,  78,  25 },  {  -24,  47,  51,  27 },  {  -41,  80,   0,  51 } } },  /* 170: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -29,  22,  98,  18 },  {  -32,  60,  78,  25 },  {  -30,  48,  51,  27 },  {  -39,  74,   0,  51 } } },  /* 171: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -32,  22,  94,  18 },  {  -34,  62,  78,  20 },  {  -30,  48,  51,  27 },  {  -35,  70,   0,  51 } } },  /* 172: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -32,  22,  94,  18 },  {  -34,  66,  78,  25 },  {  -33,  51,  51,  27 },  {  -35,  70,   0,  51 } } },  /* 173: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -30,  22,  91,  18 },  {  -39,  71,  77,  26 },  {  -38,  56,  51,  27 },  {  -42,  77,   0,  51 } } },  /* 174: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -22,  22,  91,  18 },  {  -33,  68,  77,  20 },  {  -31,  52,  51,  27 },  {  -37,  72,   0,  51 } } },  /* 175: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -14,  22,  91,  18 },  {  -32,  63,  71,  26 },  {  -30,  50,  51,  21 },  {  -35,  70,   0,  51 } } },  /* 176: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -10,  22,  93,  18 },  {  -32,  58,  71,  25 },  {  -30,  63,  51,  25 },  {  -37,  72,   0,  51 } } },  /* 177: not used by a script */
    { { {  -49,  23,  84,  18 },  {  -44,  52,  59,  38 },  {  -35,  52,  41,  34 },  {  -44,  60,   0,  41 } } },  /* 178: ATTACK 11 S: not started by a command */
    { { {  -49,  23,  84,  18 },  {  -44,  52,  59,  38 },  {  -35,  52,  41,  34 },  {  -44,  60,   0,  41 } } },  /* 179: ATTACK 11 S: not started by a command */
    { { {  -38,  23,  93,  18 },  {  -48,  58,  73,  30 },  {  -30,  47,  44,  36 },  {  -44,  67,   0,  44 } } },  /* 180: ATTACK 11 S: not started by a command */
    { { {   -8,  23, 104,  18 },  {  -51, 107,  94,  18 },  {  -30,  50,  58,  36 },  {  -45,  75,   0,  60 } } },  /* 181: ATTACK 11 S: not started by a command */
    { { {  -12,  23, 105,  18 },  {  -49,  84,  95,  26 },  {  -30,  50,  58,  37 },  {  -44,  74,   0,  62 } } },  /* 182: ATTACK 11 S: not started by a command */
    { { {  -15,  23, 105,  18 },  {  -49,  79,  95,  28 },  {  -30,  50,  58,  37 },  {  -46,  76,   0,  62 } } },  /* 183: ATTACK 11 S: not started by a command */
    { { {  -21,  23, 107,  18 },  {  -34,  59,  82,  26 },  {  -32,  48,  58,  24 },  {  -42,  70,   0,  58 } } },  /* 184: ATTACK 11 S: not started by a command */
    { { {  -34,  23, 102,  18 },  {  -31,  50,  82,  26 },  {  -26,  50,  52,  37 },  {  -31,  64,   0,  52 } } },  /* 185: ATTACK 11 S: not started by a command */
    { { {  -16,  23, 109,  18 },  {  -18,  51,  86,  26 },  {  -26,  50,  52,  37 },  {  -28,  61,   0,  52 } } },  /* 186: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -16,  23, 109,  18 },  {  -24,  59,  86,  25 },  {  -28,  50,  46,  45 },  {  -30,  55,   0,  45 } } },  /* 187: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {   -9,  23, 107,  18 },  {  -19,  60,  88,  21 },  {  -25,  47,  46,  45 },  {  -32,  57,   0,  45 } } },  /* 188: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -38,  23, 100,  18 },  {  -38,  72,  84,  24 },  {  -31,  53,  46,  45 },  {  -41,  72,   0,  46 } } },  /* 189: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -37,  23, 100,  18 },  {  -37,  75,  83,  25 },  {  -31,  53,  46,  45 },  {  -41,  72,   0,  46 } } },  /* 190: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -22,  23, 102,  18 },  {  -26,  67,  87,  21 },  {  -18,  54,  46,  45 },  {  -38,  72,   0,  46 } } },  /* 191: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -16,  23, 109,  18 },  {  -21,  45,  87,  24 },  {  -28,  49,  46,  41 },  {  -31,  47,   0,  46 } } },  /* 192: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) +1 */
    { { {  -16,  23,  97,  18 },  {  -24,  48,  74,  27 },  {  -24,  48,  46,  28 },  {  -24,  49,   0,  45 } } },  /* 193: ATTACK 10 S: not started by a command */
    { { {  -33,  22, 112,  18 },  {  -47,  65,  87,  26 },  {  -44,  62,  59,  28 },  {  -51,  79,  39,  21 } } },  /* 194: ATTACK 10 S: not started by a command */
    { { {  -37,  22, 112,  18 },  {  -49,  58,  79,  46 },  {  -54,  73,  59,  20 },  {  -43,  70,  39,  20 } } },  /* 195: ATTACK 10 S: not started by a command */
    { { {  -48,  22, 111,  18 },  {  -47,  64,  87,  37 },  {  -59,  73,  59,  28 },  {  -79,  99,  36,  33 } } },  /* 196: ATTACK 10 S: not started by a command */
    { { {  -36,  23,  57,  18 },  {  -40,  58,  48,  18 },  {  -49,  78,  23,  25 },  {  -40,  65,   0,  23 } } },  /* 197: follow-up of SP WIN 1 */
    { { {   -2,  23, 113,  18 },  {  -20,  48,  82,  27 },  {  -25,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 198: UPPER L */
    { { {    6,  23, 112,  18 },  {  -17,  48,  82,  27 },  {  -26,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 199: UPPER L */
    { { {   10,  23, 111,  18 },  {  -15,  48,  82,  27 },  {  -27,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 200: UPPER L */
    { { {   12,  23, 110,  18 },  {  -14,  48,  82,  27 },  {  -28,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 201: UPPER L */
    { { {   -2,  23, 107,  18 },  {  -16,  48,  81,  27 },  {  -20,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 202: FACE S, FACE M, FACE L +7 */
    { { {   10,  23, 105,  18 },  {  -10,  48,  80,  27 },  {  -17,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 203: FACE M, FACE L, FOOK OKU L +5 */
    { { {   18,  23, 103,  18 },  {   -6,  48,  79,  27 },  {  -15,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 204: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    { { {   22,  23, 101,  18 },  {   -4,  48,  78,  27 },  {  -14,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 205: FACE L, FOOK OKU SP, FOOK TEMAE SP */
    { { {  -22,  23, 106,  18 },  {  -22,  48,  80,  27 },  {  -22,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 206: NOUTEN L, NOUTEN S, BODY BROW M +2 */
    { { {  -26,  23, 103,  18 },  {  -20,  48,  78,  27 },  {  -20,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 207: NOUTEN L, BODY BROW M, BODY BROW L +1 */
    { { {  -30,  23, 100,  18 },  {  -18,  48,  76,  27 },  {  -18,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 208: NOUTEN L, BODY BROW L, BODY UPPER L */
    { { {  -34,  23,  97,  18 },  {  -16,  48,  74,  27 },  {  -16,  48,  46,  35 },  {  -24,  49,   0,  45 } } },  /* 209: BODY BROW L, TATAKI S */
    { { {   -4,  22,  58,  19 },  {  -18,  54,  43,  17 },  {  -20,  59,  24,  18 },  {  -33,  63,   0,  23 } } },  /* 210: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {    2,  22,  58,  19 },  {  -16,  54,  43,  17 },  {  -19,  59,  24,  18 },  {  -33,  63,   0,  23 } } },  /* 211: NOUTEN M, KAGAMI M, KAGAMI L +3 */
    { { {    8,  22,  58,  19 },  {  -14,  54,  43,  17 },  {  -18,  59,  24,  18 },  {  -33,  63,   0,  23 } } },  /* 212: KGM TOUKETU L */
    { { {   14,  22,  58,  19 },  {  -12,  54,  43,  17 },  {  -17,  59,  24,  18 },  {  -33,  63,   0,  23 } } },  /* 213: not used by a script */
    { { {  -33,  23,  86,  18 },  {  -31,  49,  65,  28 },  {  -26,  54,  46,  38 },  {  -31,  56,   0,  53 } } },  /* 214: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    { { {  -45,  23,  64,  18 },  {  -39,  49,  46,  28 },  {  -29,  56,  25,  42 },  {  -35,  69,   0,  33 } } },  /* 215: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    { { {  -45,  23,  61,  18 },  {  -39,  50,  42,  31 },  {  -28,  55,  25,  40 },  {  -34,  82,   0,  33 } } },  /* 216: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +7 */
    { { {  -45,  23,  65,  18 },  {  -39,  60,  45,  30 },  {  -29,  61,  26,  28 },  {  -31,  86,   0,  33 } } },  /* 217: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +5 */
    { { {  -49,  23,  69,  18 },  {  -40,  67,  52,  34 },  {  -24,  54,  29,  28 },  {  -31,  86,   0,  32 } } },  /* 218: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +8 */
    { { {  -47,  23,  70,  18 },  {  -40,  67,  52,  36 },  {  -31,  59,  21,  31 },  {  -24,  72,   0,  40 } } },  /* 219: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +6 */
    { { {  -44,  23,  78,  18 },  {  -40,  70,  64,  29 },  {  -44,  72,  35,  29 },  {  -28,  67,   0,  49 } } },  /* 220: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +7 */
    { { {  -40,  23,  78,  18 },  {  -41,  57,  64,  29 },  {  -46,  72,  31,  33 },  {  -26,  66,   0,  52 } } },  /* 221: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -40,  23,  79,  18 },  {  -41,  57,  65,  29 },  {  -46,  75,  32,  38 },  {  -26,  66,   0,  52 } } },  /* 222: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +6 */
    { { {  -40,  23,  82,  18 },  {  -39,  57,  65,  29 },  {  -42,  74,  34,  38 },  {  -26,  66,   0,  52 } } },  /* 223: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +6 */
    { { {  -34,  23,  91,  18 },  {  -32,  52,  65,  37 },  {  -23,  53,  34,  37 },  {  -26,  70,   0,  41 } } },  /* 224: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -34,  23,  93,  18 },  {  -24,  51,  65,  40 },  {  -20,  50,  34,  31 },  {  -21,  66,   0,  38 } } },  /* 225: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -40,  22,  78,  18 },  {  -41,  75,  66,  27 },  {  -20,  70,  33,  31 },  {  -18,  77,   0,  33 } } },  /* 226: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -39,  22,  77,  18 },  {  -35,  65,  66,  28 },  {  -21,  54,  33,  33 },  {  -18,  67,   0,  47 } } },  /* 227: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -38,  22,  81,  18 },  {  -39,  66,  66,  30 },  {  -24,  56,  33,  33 },  {  -20,  68,   0,  49 } } },  /* 228: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -41,  22,  83,  18 },  {  -34,  61,  58,  35 },  {  -15,  47,  35,  44 },  {  -14,  58,   0,  44 } } },  /* 229: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -37,  22,  89,  18 },  {  -33,  52,  58,  37 },  {  -25,  52,  43,  39 },  {  -17,  58,   0,  43 } } },  /* 230: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -33,  22,  99,  18 },  {  -27,  48,  70,  36 },  {  -29,  56,  52,  24 },  {  -20,  49,   0,  52 } } },  /* 231: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -29,  22, 104,  18 },  {  -27,  48,  72,  36 },  {  -34,  54,  56,  23 },  {  -25,  48,   0,  56 } } },  /* 232: follow-up of SP APPEAR 2, SP APPEAR 4, ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP) +6 */
    { { {  -29,  23,  91,  18 },  {  -27,  48,  68,  29 },  {  -28,  55,  48,  37 },  {  -31,  56,   0,  56 } } },  /* 233: ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -38,  23,  77,  18 },  {  -32,  49,  60,  28 },  {  -26,  55,  45,  32 },  {  -32,  60,   0,  45 } } },  /* 234: ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -25,  23, 101,  18 },  {  -25,  50,  77,  27 },  {  -29,  51,  46,  31 },  {  -28,  51,   0,  46 } } },  /* 235: ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -23,  23, 104,  18 },  {  -26,  48,  82,  27 },  {  -28,  50,  46,  35 },  {  -28,  52,   0,  45 } } },  /* 236: JUMP JUNBI, SP JUMP JUNBI */
    { { {  -14,  25,  93,  18 },  {  -22,  47,  70,  23 },  {  -25,  49,  39,  30 },  {  -27,  55,   0,  38 } } },  /* 237: SP JUMP JUNBI */
    { { {  -25,  26,  90,  18 },  {  -26,  61,  73,  26 },  {  -17,  59,  47,  36 },  {  -19,  52,  35,  12 } } },  /* 238: AIR NORMAL, KUNOJI, HARAYARARE +13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 239: no name */
    { { {  -42,  23,  81,  18 },  {  -41,  55,  64,  29 },  {  -48,  76,  35,  29 },  {  -29,  69,   0,  49 } } },  /* 240: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -41,  23,  79,  18 },  {  -41,  55,  64,  29 },  {  -49,  77,  35,  29 },  {  -29,  69,   0,  49 } } },  /* 241: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -39,  23,  81,  18 },  {  -43,  54,  62,  29 },  {  -49,  73,  35,  27 },  {  -29,  69,   0,  49 } } },  /* 242: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -47,  23,  71,  18 },  {  -50,  54,  52,  29 },  {  -34,  69,  35,  43 },  {  -39,  85,   0,  41 } } },  /* 243: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -59,  23,  48,  18 },  {  -52,  51,  36,  28 },  {  -43,  56,  17,  25 },  {  -51,  95,   0,  26 } } },  /* 244: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -53,  23,  44,  18 },  {  -57,  52,  30,  28 },  {  -42,  55,  15,  25 },  {  -51,  95,   0,  26 } } },  /* 245: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -43,  23,  45,  18 },  {  -52,  59,  30,  31 },  {  -42,  55,  15,  25 },  {  -54,  91,   0,  30 } } },  /* 246: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -45,  23,  43,  18 },  {  -54,  55,  26,  31 },  {  -39,  55,  16,  25 },  {  -52,  91,   0,  26 } } },  /* 247: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -48,  23,  46,  18 },  {  -56,  55,  26,  31 },  {  -40,  55,  17,  25 },  {  -55,  92,   0,  26 } } },  /* 248: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -53,  23,  76,  18 },  {  -57,  50,  57,  30 },  {  -52,  60,  44,  33 },  {  -53,  65,   0,  44 } } },  /* 249: follow-up of SP APPEAR 2, SP APPEAR 4 */
    { { {  -50,  23,  85,  18 },  {  -58,  54,  57,  34 },  {  -53,  57,  44,  36 },  {  -51,  61,   0,  44 } } },  /* 250: follow-up of SP APPEAR 2, SP APPEAR 4 */
    { { {  -40,  23,  88,  18 },  {  -37,  51,  67,  34 },  {  -31,  51,  40,  29 },  {  -39,  78,   0,  40 } } },  /* 251: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -37,  23,  86,  18 },  {  -33,  53,  62,  34 },  {  -28,  52,  40,  22 },  {  -41,  80,   0,  40 } } },  /* 252: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -37,  23,  81,  18 },  {  -29,  46,  62,  32 },  {  -28,  52,  40,  25 },  {  -41,  74,   0,  45 } } },  /* 253: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -36,  23,  80,  18 },  {  -27,  46,  62,  29 },  {  -28,  52,  40,  25 },  {  -45,  74,   0,  45 } } },  /* 254: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -40,  23,  82,  18 },  {  -25,  39,  62,  34 },  {  -22,  43,  40,  25 },  {  -47,  72,   0,  44 } } },  /* 255: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -44,  23,  86,  18 },  {  -28,  45,  62,  39 },  {  -22,  43,  40,  26 },  {  -45,  70,   0,  42 } } },  /* 256: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -44,  23,  88,  18 },  {  -28,  46,  65,  38 },  {  -22,  45,  40,  26 },  {  -41,  66,   0,  42 } } },  /* 257: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -40,  23,  94,  18 },  {  -28,  48,  71,  36 },  {  -27,  52,  45,  26 },  {  -36,  66,   0,  45 } } },  /* 258: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -39,  23,  98,  18 },  {  -33,  45,  71,  36 },  {  -31,  51,  45,  29 },  {  -36,  65,   0,  45 } } },  /* 259: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -29,  23, 101,  18 },  {  -26,  42,  74,  34 },  {  -26,  46,  49,  25 },  {  -36,  64,   0,  49 } } },  /* 260: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -28,  23, 103,  19 },  {  -25,  42,  77,  32 },  {  -30,  49,  49,  28 },  {  -36,  62,   0,  49 } } },  /* 261: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -10,  23, 103,  19 },  {  -18,  41,  74,  34 },  {  -29,  41,  49,  25 },  {  -38,  57,   0,  49 } } },  /* 262: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   -1,  23, 103,  19 },  {  -13,  41,  77,  29 },  {  -31,  43,  51,  30 },  {  -36,  53,   0,  51 } } },  /* 263: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {    5,  23, 102,  19 },  {  -15,  41,  80,  26 },  {  -32,  40,  51,  36 },  {  -35,  51,   0,  51 } } },  /* 264: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {    0,  23, 101,  19 },  {  -24,  41,  82,  26 },  {  -29,  40,  53,  34 },  {  -37,  55,   0,  53 } } },  /* 265: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -29,  23,  88,  19 },  {  -36,  40,  66,  26 },  {  -31,  38,  47,  23 },  {  -40,  61,   0,  47 } } },  /* 266: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -46,  23,  60,  19 },  {  -38,  47,  65,  26 },  {  -35,  55,  47,  31 },  {  -40,  66,   0,  47 } } },  /* 267: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -41,  23,  73,  19 },  {  -33,  46,  66,  29 },  {  -31,  53,  44,  38 },  {  -36,  66,   0,  44 } } },  /* 268: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -42,  23,  76,  19 },  {  -33,  47,  69,  29 },  {  -31,  52,  46,  38 },  {  -32,  62,   0,  46 } } },  /* 269: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -42,  23,  84,  19 },  {  -33,  47,  73,  29 },  {  -21,  44,  46,  31 },  {  -32,  62,   0,  46 } } },  /* 270: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -34,  23, 102,  19 },  {  -31,  45,  81,  29 },  {  -25,  46,  50,  31 },  {  -27,  53,   0,  50 } } },  /* 271: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -15,  23, 101,  18 },  {  -28,  48,  77,  27 },  {  -31,  46,  54,  23 },  {  -36,  64,   0,  54 } } },  /* 272: M PUNCH C */
    { { {  -10,  23,  96,  18 },  {  -27,  50,  70,  27 },  {  -25,  42,  47,  23 },  {  -33,  57,   0,  48 } } },  /* 273: M PUNCH C */
    { { {   -8,  23,  96,  18 },  {  -18,  51,  70,  27 },  {  -27,  49,  47,  23 },  {  -35,  57,   0,  48 } } },  /* 274: M PUNCH C */
    { { {   -7,  23,  95,  18 },  {  -28,  53,  70,  29 },  {  -31,  44,  47,  23 },  {  -38,  57,   0,  51 } } },  /* 275: M PUNCH C */
    { { {   -7,  23, 100,  18 },  {  -26,  47,  76,  26 },  {  -32,  56,  53,  23 },  {  -38,  57,   0,  53 } } },  /* 276: M PUNCH C */
    { { {   -6,  23, 101,  18 },  {  -26,  49,  76,  26 },  {  -33,  56,  53,  23 },  {  -40,  57,   0,  53 } } },  /* 277: M PUNCH C */
    { { {   -5,  23, 103,  18 },  {  -21,  49,  79,  25 },  {  -27,  56,  53,  26 },  {  -38,  57,   0,  53 } } },  /* 278: M PUNCH C */
    { { {   -6,  23, 102,  18 },  {  -21,  47,  79,  25 },  {  -24,  54,  54,  29 },  {  -36,  55,   0,  55 } } },  /* 279: M PUNCH C */
    { { {  -10,  23, 102,  18 },  {  -22,  47,  79,  25 },  {  -17,  48,  54,  33 },  {  -34,  54,   0,  55 } } },  /* 280: M PUNCH C */
    { { {  -18,  23, 100,  18 },  {  -21,  41,  77,  25 },  {  -22,  47,  53,  28 },  {  -34,  54,   0,  53 } } },  /* 281: M PUNCH C */
    { { {  -39,  23,  85,  18 },  {  -31,  42,  71,  26 },  {  -29,  47,  43,  28 },  {  -37,  52,   0,  43 } } },  /* 282: M PUNCH C */
    { { {  -36,  23,  84,  18 },  {  -26,  42,  71,  27 },  {  -25,  47,  43,  28 },  {  -32,  50,   0,  43 } } },  /* 283: M PUNCH C */
    { { {  -42,  23,  87,  18 },  {  -29,  43,  72,  30 },  {  -31,  51,  45,  27 },  {  -34,  50,   0,  45 } } },  /* 284: M PUNCH C */
    { { {  -42,  23,  83,  18 },  {  -31,  45,  72,  30 },  {  -33,  52,  45,  27 },  {  -32,  50,   0,  45 } } },  /* 285: M PUNCH C */
    { { {  -39,  23,  96,  18 },  {  -31,  46,  75,  30 },  {  -33,  52,  48,  27 },  {  -31,  49,   0,  48 } } },  /* 286: M PUNCH C */
    { { {  -40,  22,  95,  18 },  {  -43,  70,  75,  27 },  {  -34,  49,  48,  27 },  {  -52,  82,   0,  48 } } },  /* 287: ATTACK 4 S: 214+P light (plain script) */
    { { {  -40,  22,  96,  18 },  {  -43,  65,  75,  27 },  {  -36,  48,  48,  27 },  {  -48,  74,   0,  48 } } },  /* 288: ATTACK 4 S: 214+P light (plain script) */
    { { {  -34,  22,  98,  18 },  {  -40,  65,  81,  23 },  {  -33,  48,  48,  33 },  {  -44,  71,   0,  48 } } },  /* 289: ATTACK 4 S: 214+P light (plain script) */
    { { {  -31,  22, 100,  18 },  {  -39,  53,  75,  30 },  {  -35,  49,  48,  27 },  {  -41,  70,   0,  48 } } },  /* 290: ATTACK 4 S: 214+P light (plain script) */
    { { {  -26,  22, 100,  18 },  {  -35,  51,  75,  29 },  {  -39,  55,  49,  32 },  {  -41,  70,   0,  48 } } },  /* 291: ATTACK 4 S: 214+P light (plain script) */
    { { {  -23,  23, 109,  18 },  {  -27,  50,  82,  29 },  {  -30,  51,  46,  35 },  {  -26,  51,   0,  45 } } },  /* 292: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    { { {  -38,  23,  97,  18 },  {  -32,  57,  78,  29 },  {  -27,  48,  46,  32 },  {  -38,  57,   0,  53 } } },  /* 293: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    { { {  -45,  23,  93,  18 },  {  -45,  52,  72,  35 },  {  -48,  61,  46,  34 },  {  -42,  65,   0,  46 } } },  /* 294: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {  -47,  23,  90,  18 },  {  -44,  50,  72,  33 },  {  -41,  58,  46,  34 },  {  -42,  65,   0,  46 } } },  /* 295: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {  -48,  23,  88,  18 },  {  -41,  51,  72,  33 },  {  -37,  57,  46,  34 },  {  -40,  63,   0,  46 } } },  /* 296: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {  -40,  23,  98,  18 },  {  -39,  51,  72,  36 },  {  -35,  59,  46,  47 },  {  -37,  63,   0,  46 } } },  /* 297: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {  -41,  23, 100,  18 },  {  -38,  53,  82,  28 },  {  -26,  53,  58,  45 },  {  -37,  57,   0,  58 } } },  /* 298: ATTACK 8 L: 236+K (plain script) */
    { { {  -28,  23, 102,  18 },  {  -24,  44,  82,  29 },  {  -27,  53,  58,  24 },  {  -27,  52,   0,  58 } } },  /* 299: ATTACK 8 L: 236+K (plain script) */
    { { {  -18,  23, 106,  18 },  {  -22,  48,  82,  29 },  {  -25,  51,  58,  24 },  {  -27,  52,   0,  58 } } },  /* 300: ATTACK 8 L: 236+K (plain script) */
    { { {   -8,  23, 106,  18 },  {  -16,  49,  82,  29 },  {  -22,  49,  58,  24 },  {  -30,  53,   0,  60 } } },  /* 301: ATTACK 8 L: 236+K (plain script) */
    { { {  -11,  23, 104,  18 },  {  -20,  49,  82,  26 },  {  -25,  52,  54,  28 },  {  -36,  69,   0,  54 } } },  /* 302: ATTACK 8 L: 236+K (plain script) */
    { { {  -32,  23,  92,  18 },  {  -32,  53,  76,  26 },  {  -30,  56,  47,  29 },  {  -40,  70,   0,  47 } } },  /* 303: ATTACK 8 L: 236+K (plain script) */
    { { {  -35,  23,  81,  18 },  {  -41,  58,  70,  24 },  {  -30,  55,  47,  33 },  {  -40,  70,   0,  47 } } },  /* 304: ATTACK 8 L: 236+K (plain script) */
    { { {  -32,  23,  88,  18 },  {  -35,  54,  70,  27 },  {  -30,  57,  47,  33 },  {  -40,  70,   0,  47 } } },  /* 305: ATTACK 8 L: 236+K (plain script) */
    { { {  -30,  23,  97,  18 },  {  -33,  54,  74,  27 },  {  -28,  54,  47,  33 },  {  -37,  67,   0,  47 } } },  /* 306: ATTACK 8 L: 236+K (plain script) */
    { { {  -11,  23, 104,  18 },  {  -18,  47,  73,  34 },  {  -25,  51,  47,  26 },  {  -36,  66,   0,  47 } } },  /* 307: ATTACK 8 L: 236+K (plain script) */
    { { {    3,  23, 104,  18 },  {   -5,  48,  74,  34 },  {  -12,  48,  48,  26 },  {  -29,  62,   0,  53 } } },  /* 308: ATTACK 8 L: 236+K (plain script) */
    { { {  -22,  23,  81,  18 },  {  -22,  48,  67,  27 },  {  -23,  57,  46,  35 },  {  -30,  60,   0,  46 } } },  /* 309: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -24,  23,  78,  18 },  {  -22,  48,  64,  27 },  {  -23,  53,  46,  30 },  {  -33,  63,   0,  46 } } },  /* 310: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -32,  23,  84,  18 },  {  -33,  49,  64,  29 },  {  -28,  52,  46,  30 },  {  -36,  67,   0,  48 } } },  /* 311: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -36,  23,  86,  18 },  {  -35,  58,  66,  28 },  {  -15,  47,  46,  30 },  {  -19,  64,   0,  50 } } },  /* 312: not used by a script */
    { { {  -42,  23,  84,  18 },  {  -35,  58,  66,  28 },  {  -15,  47,  46,  30 },  {  -19,  64,   0,  50 } } },  /* 313: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -43,  23,  88,  18 },  {  -39,  58,  69,  28 },  {  -21,  47,  46,  30 },  {  -28,  62,   0,  50 } } },  /* 314: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -48,  23,  88,  18 },  {  -45,  59,  74,  28 },  {  -26,  47,  50,  33 },  {  -30,  54,   0,  50 } } },  /* 315: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -37,  23,  99,  18 },  {  -32,  51,  74,  34 },  {  -35,  57,  50,  24 },  {  -30,  57,   0,  50 } } },  /* 316: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -31,  22,  92,  18 },  {  -32,  63,  71,  26 },  {  -25,  50,  51,  21 },  {  -35,  70,   0,  51 } } },  /* 317: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -35,  22,  90,  18 },  {  -30,  56,  69,  26 },  {  -25,  43,  51,  21 },  {  -37,  68,   0,  51 } } },  /* 318: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -35,  22,  87,  18 },  {  -30,  58,  69,  25 },  {  -25,  43,  51,  20 },  {  -37,  68,   0,  51 } } },  /* 319: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -39,  22,  87,  18 },  {  -34,  62,  69,  25 },  {  -29,  44,  51,  20 },  {  -37,  68,   0,  51 } } },  /* 320: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -34,  22,  90,  18 },  {  -40,  62,  69,  25 },  {  -29,  44,  51,  20 },  {  -37,  62,   0,  51 } } },  /* 321: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -30,  22,  90,  18 },  {  -39,  54,  69,  25 },  {  -29,  44,  51,  20 },  {  -37,  62,   0,  51 } } },  /* 322: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   16,  26,  78,  18 },  {    4,  29,  53,  47 },  {  -24,  43,  44,  58 },  {  -45,  25,  47,  57 } } },  /* 323: AIR NORMAL */
    { { {  -44,  26,  96,  18 },  {  -38,  43,  78,  32 },  {  -38,  52,  60,  40 },  {  -41,  52,  37,  23 } } },  /* 324: ASIBARAI SIRI, HUMI ASIB */
    { { {  -41,  26,  97,  18 },  {  -38,  43,  75,  32 },  {  -18,  45,  64,  36 },  {    5,  39,  53,  34 } } },  /* 325: ASIBARAI SIRI, HUMI ASIB */
    { { {  -48,  26,  77,  18 },  {  -44,  43,  56,  33 },  {  -20,  45,  46,  35 },  {   12,  35,  42,  37 } } },  /* 326: ASIBARAI SIRI, HUMI ASIB */
    { { {  -48,  26,  50,  18 },  {  -43,  43,  25,  35 },  {  -22,  45,  22,  40 },  {   12,  35,  25,  41 } } },  /* 327: ASIBARAI SIRI, HUMI ASIB */
    { { {  -32,  26,  98,  18 },  {  -29,  52,  77,  26 },  {  -14,  46,  62,  28 },  {    4,  41,  40,  37 } } },  /* 328: ASIB TUNNOMERI */
    { { {  -64,  26,  19,  18 },  {  -47,  41,  19,  36 },  {  -22,  39,  26,  39 },  {    9,  40,  15,  51 } } },  /* 329: ASIB TUNNOMERI */
    { { {   -4,  26,  97,  18 },  {  -26,  40,  79,  26 },  {  -37,  43,  54,  36 },  {  -45,  51,  39,  21 } } },  /* 330: NOKEZORI, HARAYARARE, TATAKI AIR +4 */
    { { {    8,  26,  71,  18 },  {  -12,  31,  65,  36 },  {  -42,  35,  58,  40 },  {  -62,  46,  44,  33 } } },  /* 331: NOKEZORI, HARAYARARE, TATAKI AIR +2 */
    { { {    9,  26,  63,  18 },  {  -12,  31,  58,  38 },  {  -38,  33,  56,  43 },  {  -64,  36,  38,  37 } } },  /* 332: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   14,  26,  58,  18 },  {  -10,  31,  55,  41 },  {  -34,  33,  52,  48 },  {  -64,  36,  44,  39 } } },  /* 333: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {   12,  26,  48,  18 },  {  -10,  31,  46,  41 },  {  -34,  33,  44,  49 },  {  -66,  38,  47,  39 } } },  /* 334: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {    9,  26,  38,  18 },  {   -7,  31,  44,  40 },  {  -31,  40,  44,  49 },  {  -66,  38,  53,  44 } } },  /* 335: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {    0,  26,  32,  18 },  {  -15,  36,  40,  41 },  {  -34,  44,  43,  46 },  {  -57,  36,  57,  43 } } },  /* 336: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {  -25,  26,  19,  18 },  {  -35,  46,  29,  30 },  {  -41,  56,  37,  37 },  {  -53,  46,  51,  47 } } },  /* 337: NOKEZORI, KIRIMOMI, UPPER +7 */
    { { {  -66,  26,  70,  18 },  {  -48,  47,  68,  26 },  {  -55,  66,  48,  33 },  {  -65,  63,  37,  13 } } },  /* 338: KUNOJI, KUNOJI NOKE */
    { { {  -60,  26,  67,  18 },  {  -43,  46,  67,  25 },  {  -36,  50,  48,  33 },  {  -53,  62,  36,  15 } } },  /* 339: KUNOJI */
    { { {  -23,  26,  69,  18 },  {  -36,  52,  58,  22 },  {  -32,  49,  36,  33 },  {  -52,  50,  23,  26 } } },  /* 340: KUNOJI */
    { { {   17,  26,  22,  18 },  {   -1,  35,   3,  34 },  {  -32,  38,   3,  47 },  {  -47,  43,  13,  50 } } },  /* 341: KUNOJI */
    { { {  -56,  26,  92,  18 },  {  -50,  41,  73,  28 },  {  -47,  33,  47,  35 },  {  -66,  40,  41,  21 } } },  /* 342: KIRIMOMI */
    { { {  -29,  26,  95,  18 },  {  -45,  43,  73,  27 },  {  -52,  34,  51,  25 },  {  -66,  40,  41,  22 } } },  /* 343: KIRIMOMI */
    { { {   -8,  26, 102,  18 },  {  -29,  50,  86,  26 },  {  -39,  49,  72,  27 },  {  -56,  42,  57,  27 } } },  /* 344: KIRIMOMI */
    { { {   -2,  26, 107,  18 },  {  -22,  38,  86,  29 },  {  -36,  43,  75,  27 },  {  -48,  42,  59,  27 } } },  /* 345: KIRIMOMI */
    { { {    5,  26, 106,  18 },  {  -14,  38,  86,  29 },  {  -22,  43,  74,  27 },  {  -34,  37,  59,  28 } } },  /* 346: KIRIMOMI */
    { { {    8,  26, 105,  18 },  {  -18,  41,  86,  29 },  {  -24,  39,  75,  27 },  {  -38,  36,  59,  28 } } },  /* 347: KIRIMOMI */
    { { {   14,  26,  89,  18 },  {  -20,  50,  71,  28 },  {  -31,  34,  59,  25 },  {  -47,  32,  52,  27 } } },  /* 348: KIRIMOMI */
    { { {   21,  26,  78,  18 },  {  -10,  37,  63,  34 },  {  -29,  34,  56,  25 },  {  -45,  32,  42,  31 } } },  /* 349: KIRIMOMI */
    { { {  -28,  26, 101,  18 },  {  -30,  52,  85,  29 },  {  -27,  46,  51,  34 },  {  -30,  48,  37,  14 } } },  /* 350: UPPER, TATUMAKIZANKU */
    { { {   20,  26, 103,  18 },  {  -12,  48,  90,  29 },  {  -23,  54,  76,  28 },  {  -25,  45,  40,  36 } } },  /* 351: UPPER, TATUMAKIZANKU */
    { { {   20,  26,  98,  18 },  {  -10,  46,  89,  29 },  {  -21,  53,  76,  28 },  {  -34,  45,  42,  41 } } },  /* 352: UPPER, TATUMAKIZANKU */
    { { {    1,  26,  99,  18 },  {  -13,  41,  76,  29 },  {  -32,  37,  62,  34 },  {  -47,  43,  48,  34 } } },  /* 353: UPPER, BODY UPPER, FACE +1 */
    { { {  -26,  26, 101,  18 },  {  -22,  45,  83,  26 },  {  -20,  48,  53,  43 },  {  -23,  47,  37,  16 } } },  /* 354: BODY UPPER, HANEKAERI HARA */
    { { {  -42,  26,  86,  18 },  {  -36,  56,  70,  26 },  {  -24,  49,  57,  25 },  {  -27,  48,  39,  18 } } },  /* 355: BODY UPPER */
    { { {  -37,  26,  58,  18 },  {  -32,  57,  70,  26 },  {  -40,  69,  57,  22 },  {  -42,  70,  41,  16 } } },  /* 356: BODY UPPER */
    { { {  -43,  26,  74,  18 },  {  -38,  52,  81,  26 },  {  -26,  48,  57,  36 },  {  -32,  51,  40,  26 } } },  /* 357: BODY UPPER */
    { { {  -37,  26, 102,  18 },  {  -34,  50,  94,  26 },  {  -29,  49,  71,  36 },  {  -37,  49,  46,  27 } } },  /* 358: BODY UPPER */
    { { {  -27,  26, 103,  18 },  {  -23,  46,  83,  28 },  {  -19,  49,  53,  45 },  {  -24,  50,  37,  16 } } },  /* 359: TTKI V. AIR */
    { { {  -58,  26,  45,  18 },  {  -46,  46,  41,  35 },  {  -27,  46,  25,  44 },  {  -15,  47,  17,  33 } } },  /* 360: TTKI V. AIR */
    { { {   -5,  26, 107,  18 },  {  -20,  44,  81,  32 },  {  -26,  45,  53,  28 },  {  -27,  46,  35,  18 } } },  /* 361: FACE */
    { { {  -12,  26, 115,  18 },  {  -16,  47, 101,  20 },  {  -18,  52,  70,  33 },  {  -21,  50,  37,  33 } } },  /* 362: DENKI */
    { { {  -37,  23,  91,  18 },  {  -36,  52,  65,  37 },  {  -27,  58,  34,  37 },  {  -30,  74,   0,  41 } } },  /* 363: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -23,  23,  93,  18 },  {  -27,  54,  65,  35 },  {  -23,  58,  34,  31 },  {  -23,  68,   0,  38 } } },  /* 364: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -45,  22,  75,  18 },  {  -46,  70,  60,  32 },  {  -25,  66,  33,  27 },  {  -21,  84,   0,  33 } } },  /* 365: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -38,  22,  70,  18 },  {  -40,  70,  60,  31 },  {  -21,  62,  33,  27 },  {  -17,  80,   0,  33 } } },  /* 366: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -32,  22,  66,  18 },  {  -36,  73,  58,  33 },  {  -25,  69,  41,  17 },  {  -15,  80,   0,  41 } } },  /* 367: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -23,  22,  66,  18 },  {  -33,  67,  58,  35 },  {  -25,  65,  41,  17 },  {  -15,  68,   0,  41 } } },  /* 368: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -26,  22,  91,  18 },  {  -30,  50,  69,  36 },  {  -22,  52,  42,  49 },  {  -16,  53,   0,  51 } } },  /* 369: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  22,  95,  18 },  {  -27,  52,  59,  43 },  {  -13,  47,  42,  48 },  {   -9,  49,   0,  48 } } },  /* 370: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -33,  22,  92,  18 },  {  -32,  48,  73,  27 },  {  -36,  54,  48,  25 },  {  -47,  60,   0,  55 } } },  /* 371: L KICK A */
    { { {  -21,  23, 116,  18 },  {  -24,  48,  85,  30 },  {  -24,  48,  46,  37 },  {  -24,  49,   0,  45 } } },  /* 372: KAMAE, STAND UP */
    { { {  -15,  23, 113,  18 },  {  -22,  48,  85,  27 },  {  -23,  48,  46,  37 },  {  -24,  49,   0,  45 } } },  /* 373: KAMAE */
    { { {  -14,  23, 109,  18 },  {  -31,  52,  82,  27 },  {  -29,  54,  46,  35 },  {  -32,  56,   0,  45 } } },  /* 374: HURIMUKI */
    { { {  -13,  22,  51,  19 },  {  -20,  54,  39,  17 },  {  -21,  59,  24,  14 },  {  -33,  63,   0,  23 } } },  /* 375: KAGAMU, KAGAMI KAMAE */
    { { {   -6,  22,  58,  19 },  {  -28,  54,  43,  17 },  {  -33,  59,  24,  18 },  {  -27,  63,   0,  23 } } },  /* 376: KAGAMI TURN */
    { { {  -14,  23,  94,  18 },  {  -22,  48,  74,  21 },  {  -24,  50,  33,  39 },  {  -28,  58,   0,  32 } } },  /* 377: KAGAMU */
    { { {  -30,  23,  91,  18 },  {  -27,  49,  74,  23 },  {  -28,  52,  40,  33 },  {  -32,  57,   0,  39 } } },  /* 378: STAND UP, UP P GUARD P M */
    { { {  -24,  23, 103,  18 },  {  -26,  48,  79,  27 },  {  -28,  50,  43,  35 },  {  -30,  53,   0,  42 } } },  /* 379: STAND UP */
    { { {  -12,  22, 112,  18 },  {  -25,  54,  78,  33 },  {  -37,  74,  45,  40 },  {  -30,  58,  31,  14 } } },  /* 380: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -24,  23, 112,  18 },  {  -24,  46,  86,  27 },  {  -24,  48,  42,  43 },  {  -24,  49,   0,  41 } } },  /* 381: FRONT WALK */
    { { {  -26,  23, 106,  18 },  {  -24,  48,  82,  27 },  {  -24,  48,  38,  43 },  {  -28,  51,   0,  37 } } },  /* 382: FRONT WALK */
    { { {  -24,  23, 111,  22 },  {  -24,  51,  88,  27 },  {  -24,  48,  42,  45 },  {  -24,  49,   0,  41 } } },  /* 383: FRONT WALK */
    { { {  -24,  23, 107,  18 },  {  -24,  48,  88,  27 },  {  -24,  48,  47,  41 },  {  -34,  61,   0,  46 } } },  /* 384: FRONT WALK */
    { { {  -24,  23, 104,  18 },  {  -24,  46,  81,  27 },  {  -24,  48,  42,  37 },  {  -28,  54,   0,  41 } } },  /* 385: FRONT WALK */
    { { {  -23,  23, 107,  22 },  {  -24,  48,  85,  27 },  {  -28,  52,  41,  43 },  {  -31,  55,   0,  40 } } },  /* 386: BACK WALK */
    { { {  -23,  23, 112,  22 },  {  -24,  48,  90,  27 },  {  -24,  48,  43,  45 },  {  -24,  55,   0,  42 } } },  /* 387: BACK WALK */
    { { {  -25,  23, 105,  22 },  {  -24,  48,  82,  27 },  {  -24,  48,  43,  39 },  {  -24,  49,   0,  42 } } },  /* 388: BACK WALK */
    { { {  -25,  23, 110,  22 },  {  -24,  48,  88,  27 },  {  -24,  48,  43,  43 },  {  -24,  49,   0,  42 } } },  /* 389: BACK WALK */
    { { {  -25,  23, 103,  22 },  {  -24,  48,  80,  27 },  {  -24,  48,  43,  35 },  {  -24,  49,   0,  42 } } },  /* 390: BACK WALK */
    { { {  -25,  23, 106,  22 },  {  -24,  48,  80,  27 },  {  -28,  52,  45,  33 },  {  -34,  59,   0,  44 } } },  /* 391: BACK WALK */
    { { {   27,  29, 103,  18 },  {   -4,  50,  82,  27 },  {  -24,  54,  41,  48 },  {  -24,  68,   0,  40 } } },  /* 392: PIYO */
    { { {   29,  29,  99,  18 },  {   -4,  50,  82,  27 },  {  -24,  54,  41,  48 },  {  -24,  68,   0,  40 } } },  /* 393: PIYO */
};

const HAND_BOX q_hand_box[161] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: no box */
    { { {  -68,  43,  86,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A */
    { { {  -86,  34,  70,  18 },  {  -64,  21,  78,  17 },  {  -47,  24,  86,  15 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -79,  27,  77,  17 },  {  -61,  21,  82,  16 },  {  -44,  24,  88,  14 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B */
    { { { -104,  50,  83,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A */
    { { { -101,  47,  83,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH A */
    { { { -100,  47,  76,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A */
    { { {  -89,  35,  71,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH A */
    { { {  -71,  17,  70,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A */
    { { {  -78,  63,  71,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: L PUNCH A, L PUNCH C */
    { { {  -90,  59,  24,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: S KICK A */
    { { {  -74,  34,  21,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: S KICK A */
    { { {  -47,  26,  53,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M KICK A */
    { { {  -94,  65,  39,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: M KICK B */
    { { {  -92,  63,  42,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M KICK B */
    { { {  -82,  80,  92,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: L KICK C */
    { { {  -50,  43,  88,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: L KICK C */
    { { { -121,  79,  48,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: L KICK A */
    { { { -104,  65,  45,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: L KICK A */
    { { {  -80,  37,  22,  45 },  {  -94,  28,  14,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L KICK A */
    { { {  -70,  15,  22,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: L KICK A */
    { { { -107,  84,  38,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: KAGAMI P A */
    { { {  -93,  70,  38,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: KAGAMI P A */
    { { {  -95,  34,  79,  22 },  {  -73,  23,  72,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: KAGAMI P A */
    { { {  -91,  50,  65,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: KAGAMI P A */
    { { {  -74,  34,  48,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: KAGAMI P A */
    { { { -100,  29,   0,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: KAGAMI P A */
    { { { -113,  75,   0,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: KAGAMI K A */
    { { { -105,  52,   0,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: KAGAMI K A */
    { { {  -99,  46,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: KAGAMI K A */
    { { { -113,  65,  83,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: V JUMP P S A */
    { { { -105,  57,  83,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: V JUMP P S A */
    { { { -102,  67,  98,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -96,  65,  97,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -72,  41,  96,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: V JUMP P M A, F JUMP P M A, B JUMP P M A */
    { { {  -89,  32,  51,  26 },  {  -73,  33,  62,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -89,  35,  49,  28 },  {  -68,  31,  61,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: V JUMP P L A, F JUMP P L A, B JUMP P L A */
    { { {  -84,  56,  40,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: V JUMP K S A */
    { { {  -72,  44,  40,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: V JUMP K S A */
    { { { -127,  80,  51,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: V JUMP K M A */
    { { { -123,  76,  51,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: V JUMP K M A */
    { { { -123,  54,  25,  38 },  {  -81,  24,  36,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: V JUMP K L A, S V JP S P A */
    { { { -114,  63,  27,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP K L A, S V JP S P A */
    { { {  -89,  57,  22,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP K L A, S V JP S P A */
    { { {  -67,  54,  25,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: V JUMP K L A, S V JP S P A */
    { { {  -96,  51,  54,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: F JUMP P S A */
    { { {  -91,  46,  55,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: F JUMP P S A */
    { { {  -64,  33,  80,  31 },  {  -78,  37,  89,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {    2,  26,  98,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   -4,  26, 101,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -19,  28, 104,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -77,  52,  88,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   14,  38,  78,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: ATTACK 4 S: 214+P light (plain script), ATTACK 4 L: 214+P heavy (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {    1,  32,  96,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -78,  53,  73,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -51,  44,  97,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 57: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -45,  38,  96,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 58: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -35,  46, 103,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -31,  40, 103,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -39,  34,  99,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -52,  31,  76,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {   -5,  31, 103,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -27,  31,  98,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -80,  46,  78,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -74,  54,  60,  27 },  {  -59,  18,  83,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -58,  25,  83,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: ATTACK 11 S: not started by a command */
    { { {  -43,  22,  68,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: ATTACK 11 S: not started by a command */
    { { {  -87,  32,  61,  24 },  {  -60,  20,  73,  15 },  {  -48,  18,  78,  14 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -61,  27,  76,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {  -51,  35,  79,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 5 S: 3214+K light (plain script), ATTACK 5 M: 3214+K medium (plain script), ATTACK 5 L: 3214+K heavy/EX (plain script) */
    { { {   -5,  30,  93,  11 },  {  -54,  16,  27,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -12,  32,  93,  15 },  {  -55,  16,  29,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -10,  41,  93,  15 },  {  -49,  14,  33,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {   11,  28,  93,  12 },  {  -37,  15,  47,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -83,  63,  61,  25 },  {  -59,  18,  83,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -80,  27,  57,  16 },  {  -60,  23,  62,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -70,  27,  58,  15 },  {  -53,  22,  63,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -58,  26,  58,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -51,  26,  54,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -46,  21,  53,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -53,  15,  31,  20 },  {   -6,  33,  93,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -58,  19,  31,  21 },  {  -10,  35,  93,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -62,  20,  37,  18 },  {    3,  35,  88,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -60,  22,  32,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { { -100,  49,   2,  30 },  {  -87,  36,  22,  26 },  {  -14,  33,  59,  14 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -88,  37,   2,  30 },  {  -75,  27,  23,  26 },  {  -24,  34,  59,  14 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -24,  47,  57,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -31,  46,  52,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -37,  46,  50,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP), ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP), ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -42,  56,  52,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    { { {  -54,  15,   0,  14 },  {   14,  20,  75,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -44,  16,  49,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -43,  15,  53,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -47,  21,  52,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -45,  23,  44,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -42,  20,  42,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -42,  20,  42,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -44,  17,  52,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: ATTACK 7 S: SA II 23623+P (plain script), ATTACK 11 SP: not started by a command */
    { { {  -51,  20,  61,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -44,  18,  77,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -36,  42,  98,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   10,  22, 102,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   14,  24, 102,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   19,  24,  93,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   19,  20,  93,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -17,  26,  92,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -51,  19,  59,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -51,  19,  54,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 109: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -49,  28,  61,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {  -41,  16,  61,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: ATTACK 7 S: SA II 23623+P (plain script) */
    { { {   20,  15,  73,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: M PUNCH C */
    { { {   17,  15,  65,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: M PUNCH C */
    { { {   15,  18,  97,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: M PUNCH C */
    { { {  -50,  22,  70,  22 },  {   21,  13,  63,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: M PUNCH C */
    { { {  -31,  31, 102,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: M PUNCH C */
    { { {  -29,  25, 102,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: M PUNCH C */
    { { {  -29,  23, 102,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: M PUNCH C */
    { { {  -32,  22,  96,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: M PUNCH C */
    { { {  -34,  14,  74,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: M PUNCH C */
    { { {  -39,  10,  61,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: M PUNCH C */
    { { {  -36,  11,  54,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: M PUNCH C */
    { { {  -51,  32,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -57,  38,  64,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    { { {  -59,  33,  59,  31 },  {  -87,  53,  46,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: ATTACK 4 S: 214+P light (plain script) */
    { { {  -71,  28,  79,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 126: ATTACK 4 S: 214+P light (plain script) */
    { { {  -62,  22,  84,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: ATTACK 4 S: 214+P light (plain script) */
    { { {  -64,  32,  89,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: ATTACK 4 S: 214+P light (plain script) */
    { { {  -57,  21,  71,  24 },  {  -68,  19,  63,  24 },  {  -81,  25,  52,  24 },  {    0,   0,   0,   0 } } },  /* 129: ATTACK 4 S: 214+P light (plain script) */
    { { {  -74,  42,  82,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    { { {   -3,  25,  98,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {   -4,  23, 104,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {   10,  19,  89,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    { { {  -66,  28,  79,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: ATTACK 8 L: 236+K (plain script) */
    { { {  -52,  28,  80,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 135: ATTACK 8 L: 236+K (plain script) */
    { { {  -50,  28,  80,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: ATTACK 8 L: 236+K (plain script) */
    { { {  -43,  28,  82,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 8 L: 236+K (plain script) */
    { { {  -41,  21,  82,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 138: ATTACK 8 L: 236+K (plain script) */
    { { {  -51,  21,  64,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 139: ATTACK 8 L: 236+K (plain script) */
    { { {  -49,  16,  66,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 140: ATTACK 8 L: 236+K (plain script) */
    { { {  -41,  23,  84,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 141: ATTACK 8 L: 236+K (plain script) */
    { { {  -26,  21,  74,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 142: ATTACK 8 L: 236+K (plain script) */
    { { {  -68,  32,  71,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 143: not used by a script */
    { { {  -79,  44,  66,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 144: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -67,  28,  66,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -51,  26,  63,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    { { {  -67,  39,  48,  26 },  {   15,  21,  62,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 147: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -84,  50,  71,  26 },  {   15,  21,  64,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 148: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -52,  37,  76,  48 },  {   15,  14,  60,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 149: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -43,  36,  83,  38 },  {   14,  14,  66,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 150: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -37,  38,  87,  29 },  {   14,  14,  71,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 151: ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -17,  33,  94,  23 },  {  -62,  23,  28,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 152: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -17,  27,  94,  25 },  {  -50,  24,  28,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 153: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -27,  34, 102,  20 },  {  -39,  15,  42,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 154: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -62,  39,  88,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 155: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -90,  38,  33,  38 },  {  -75,  30,  58,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -75,  32,  35,  35 },  {  -66,  26,  58,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 157: ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP), ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    { { {  -94,  32,  51,  28 },  {  -74,  54,  60,  27 },  {  -59,  18,  83,   9 },  {    0,   0,   0,   0 } } },  /* 158: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +3 */
    { { {  -88,  37,  74,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 159: ATTACK 4 M: 214+P medium (plain script), ATTACK 4 SP: EX 214+PP (plain script) */
    { { {  -66,  43,  31,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 160: KAGAMI P A */
};

const HOSEI_BOX q_hos_box[8] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -22,   44,    0,   90 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +110 */
    { {  -22,   44,    0,   57 } },  /* 2: KAGAMU, KAGAMI TURN, STAND UP +39 */
    { {  -26,   52,   48,   44 } },  /* 3: PARING AIR F, P BREAK AIR F, TUKAMIHAZUSI +53 */
    { {  -22,   44,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +2 */
    { {  -30,   54,    0,   74 } },  /* 5: DASH HUMIKOMI, DASH TOBINOKI */
    { {  -32,   58,    0,   74 } },  /* 6: ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP), ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP), ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) +11 */
    { {  -22,   44,    0,   82 } },  /* 7: UPPER L, FACE S, FACE M +14 */
};
