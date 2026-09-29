/*
 * CHUN_HITBOX.C  Chun-Li's hit boxes
 *
 * Each of Chun-Li's animation frames names an entry of chun_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX chun_hit_ix_table[511] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +89 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +26 */
    {    3,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 3: S PUNCH A */
    {    4,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 4: S PUNCH A */
    {    5,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 5: S PUNCH A */
    {    6,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 6: S PUNCH A */
    {    7,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: S PUNCH A */
    {    8,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 8: S PUNCH B */
    {    9,    0,    4, 0x0000,    0,    1,    3,    1 },  /* 9: S PUNCH B */
    {    9,    0,    5, 0x0000,    0,    1,    4,    1 },  /* 10: S PUNCH B */
    {   10,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 11: M PUNCH C, S V JP S P A */
    {   11,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 12: M PUNCH C */
    {   12,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 13: M PUNCH C */
    {   13,    0,    7, 0x0000,    0,    1,    5,    1 },  /* 14: M PUNCH C */
    {   14,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 15: M PUNCH C */
    {   15,    0,    8, 0x0000,    0,    1,    0,    1 },  /* 16: M PUNCH C */
    {   16,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 17: M PUNCH C */
    {   17,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 18: M PUNCH C */
    {   18,    0,   10, 0x0000,    0,    1,    6,    1 },  /* 19: M PUNCH C */
    {   19,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 20: M PUNCH C */
    {   20,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 21: M PUNCH C */
    {   21,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 22: M PUNCH C */
    {   22,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 23: M PUNCH C */
    {   23,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 24: M PUNCH C */
    {   24,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 25: M PUNCH A, no name */
    {   25,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 26: M PUNCH A, no name */
    {   26,    0,   14, 0x0000,    0,    1,    7,    1 },  /* 27: M PUNCH A, no name */
    {   27,    0,   14, 0x0000,    0,    1,    8,    1 },  /* 28: M PUNCH A, no name */
    {   28,    0,   15, 0x0000,    0,    1,    0,    1 },  /* 29: M PUNCH A, no name */
    {   29,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 30: M PUNCH A, no name */
    {   30,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 31: L PUNCH C */
    {   31,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 32: L PUNCH C */
    {   32,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 33: L PUNCH C */
    {   33,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 34: L PUNCH C */
    {   34,    0,   16, 0x0000,    0,    1,    9,    1 },  /* 35: L PUNCH C */
    {   34,    0,   17, 0x0000,    0,    1,   10,    1 },  /* 36: L PUNCH C */
    {   34,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 37: L PUNCH C */
    {   35,    0,   19, 0x0000,    0,    1,    0,    1 },  /* 38: L PUNCH C */
    {   36,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 39: L PUNCH C */
    {   37,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 40: L PUNCH C */
    {   38,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 41: L PUNCH A */
    {   39,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 42: L PUNCH A */
    {   40,    0,   22, 0x0000,    0,    1,    0,    1 },  /* 43: L PUNCH A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 44: L PUNCH A */
    {   42,    0,   23, 0x0000,    0,    1,   11,    1 },  /* 45: L PUNCH A */
    {   43,    0,   24, 0x0000,    0,    1,   12,    1 },  /* 46: L PUNCH A */
    {   43,    0,   24, 0x0000,    0,    1,   13,    1 },  /* 47: L PUNCH A */
    {   43,    0,   24, 0x0000,    0,    1,   14,    1 },  /* 48: L PUNCH A */
    {   44,    0,   25, 0x0000,    0,    1,    0,    1 },  /* 49: L PUNCH A */
    {   45,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 50: L PUNCH A */
    {   46,    0,   27, 0x0000,    0,    1,    0,    1 },  /* 51: L PUNCH A */
    {   47,    0,   28, 0x0000,    0,    1,    0,    1 },  /* 52: L PUNCH A */
    {   48,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 53: L PUNCH A */
    {   50,    0,   29, 0x0000,    0,    1,   15,    1 },  /* 54: M KICK C */
    {   51,    0,   30, 0x0000,    0,    1,   16,    1 },  /* 55: M KICK C */
    {   51,    0,   30, 0x0000,    0,    1,   17,    1 },  /* 56: M KICK C */
    {   52,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 57: M KICK C */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 58: M KICK C */
    {   54,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 59: M KICK C */
    {   49,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 60: M KICK C */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 61: M KICK A */
    {   56,    0,   32, 0x0000,    0,    1,    0,    1 },  /* 62: M KICK A */
    {   57,    0,   33, 0x0000,    0,    1,    0,    1 },  /* 63: M KICK A */
    {   58,    0,   34, 0x0000,    0,    1,    0,    1 },  /* 64: M KICK A */
    {   59,    0,   35, 0x0000,    0,    1,   18,    1 },  /* 65: M KICK A */
    {   60,    0,   36, 0x0000,    0,    1,   19,    1 },  /* 66: M KICK A */
    {   60,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 67: M KICK A */
    {   61,    0,   38, 0x0000,    0,    1,    0,    1 },  /* 68: M KICK A */
    {   62,    0,   39, 0x0000,    0,    3,    0,    3 },  /* 69: L KICK B */
    {   63,    0,   40, 0x0000,    0,    3,    0,    3 },  /* 70: L KICK B */
    {   64,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 71: L KICK B */
    {   65,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 72: L KICK B */
    {   66,    0,   41, 0x0000,    0,    3,   20,    3 },  /* 73: L KICK B */
    {   67,    0,   42, 0x0000,    0,    3,    0,    3 },  /* 74: L KICK B */
    {   67,    0,   43, 0x0000,    0,    3,    0,    3 },  /* 75: L KICK B */
    {   67,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 76: L KICK B */
    {   68,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 77: L KICK B */
    {   69,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 78: follow-up of APPEAR JUNBI 1 */
    {   70,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 79: follow-up of APPEAR JUNBI 1 */
    {   71,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 80: V JUMP P S A, V JUMP P M A, F JUMP P L A */
    {   72,    0,   44, 0x0000,    0,    3,    0,    3 },  /* 81: V JUMP P S A, V JUMP P M A */
    {   72,    0,   45, 0x0000,    0,    3,   21,    3 },  /* 82: V JUMP P S A */
    {   72,    0,   45, 0x0000,    0,    3,   22,    3 },  /* 83: V JUMP P S A */
    {   73,    0,   46, 0x0000,    0,    1,    0,    1 },  /* 84: S KICK A */
    {   74,    0,   47, 0x0000,    0,    1,    0,    1 },  /* 85: S KICK A */
    {   75,    0,   48, 0x0000,    0,    1,   23,    1 },  /* 86: S KICK A */
    {   76,    0,   49, 0x0000,    0,    1,   24,    1 },  /* 87: S KICK A */
    {   77,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 88: S KICK A, no name */
    {   78,    0,   51, 0x0000,    0,    1,    0,    1 },  /* 89: S KICK A, no name */
    {   79,    0,   52, 0x0000,    0,    1,    0,    1 },  /* 90: S KICK A, no name */
    {   80,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 91: S KICK A */
    {   81,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 92: JUMP FRONT, SP JUMP FRONT */
    {   84,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 93: JUMP BACK, SP JUMP BACK */
    {   85,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 94: JUMP VERTICAL, SP JUMP V */
    {   82,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 95: JUMP FRONT, JUMP VERTICAL, JUMP BACK +11 */
    {   83,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 96: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    {   86,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 97: JUMP JUNBI, SP JUMP JUNBI */
    {   87,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 98: KAGAMI K C */
    {   88,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 99: KAGAMI K C */
    {   89,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 100: KAGAMI K C */
    {   90,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 101: KAGAMI K C */
    {   91,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 102: KAGAMI K C */
    {   92,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 103: KAGAMI K C */
    {   93,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 104: KAGAMI K C */
    {   94,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 105: KAGAMI K C */
    {   95,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 106: KAGAMI K C */
    {   96,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 107: KAGAMI K C */
    {   97,    0,   53, 0x0000,    0,    3,   25,    3 },  /* 108: KAGAMI K C */
    {   98,    0,   54, 0x0000,    0,    3,    0,    3 },  /* 109: KAGAMI K C */
    {   99,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 110: M KICK B, no name */
    {  100,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 111: M KICK B, S V JP S P A, no name */
    {  101,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 112: M KICK B, no name */
    {  102,    0,   55, 0x0000,    0,    1,   26,    1 },  /* 113: M KICK B, no name */
    {  102,    0,   56, 0x0000,    0,    1,   27,    1 },  /* 114: M KICK B, no name */
    {  103,    0,   57, 0x0000,    0,    1,   28,    1 },  /* 115: M KICK B, no name */
    {  104,    0,   58, 0x0000,    0,    1,    0,    1 },  /* 116: M KICK B, no name */
    {  104,    0,   59, 0x0000,    0,    1,    0,    1 },  /* 117: M KICK B, no name */
    {  105,    0,   60, 0x0000,    0,    1,    0,    1 },  /* 118: M KICK B, no name */
    {  106,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 119: M KICK B, no name */
    {  107,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 120: M KICK B, no name */
    {  108,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 121: M KICK B, no name */
    {  109,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 122: DASH HUMIKOMI */
    {  110,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 123: DASH HUMIKOMI */
    {  111,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 124: DASH HUMIKOMI, TUKAMIHAZUSI */
    {  112,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 125: DASH HUMIKOMI */
    {  113,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 126: DASH TOBINOKI, UP P GUARD P L */
    {  114,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 127: DASH TOBINOKI */
    {  115,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 128: DASH TOBINOKI */
    {  116,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 129: DASH TOBINOKI */
    {  117,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 130: DASH TOBINOKI */
    {  118,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 131: DASH TOBINOKI */
    {  119,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 132: DASH TOBINOKI */
    {  120,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 133: DASH TOBINOKI */
    {  121,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 134: V JUMP K S A, V JUMP K M A */
    {  122,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 135: V JUMP K S A, V JUMP K M A */
    {  123,    0,   62, 0x0000,    0,    3,   29,    3 },  /* 136: V JUMP K S A */
    {  124,    0,   63, 0x0000,    0,    3,    0,    3 },  /* 137: V JUMP K M A */
    {  125,    0,   64, 0x0000,    0,    3,    0,    3 },  /* 138: V JUMP K M A */
    {  126,    0,   65, 0x0000,    0,    3,    0,    3 },  /* 139: V JUMP K S A, V JUMP K M A */
    {  127,    0,   66, 0x0000,    0,    3,    0,    3 },  /* 140: V JUMP K S A, V JUMP K M A */
    {  128,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 141: V JUMP K S A, V JUMP K M A */
    {  123,    0,   62, 0x0000,    0,    3,   30,    3 },  /* 142: V JUMP K M A */
    {  129,    0,   67, 0x0000,    0,    3,    0,    3 },  /* 143: F JUMP K L A */
    {  130,    0,   68, 0x0000,    0,    3,    0,    3 },  /* 144: F JUMP K L A */
    {  131,    0,   69, 0x0000,    0,    3,    0,    3 },  /* 145: F JUMP K L A, S V JP S P A */
    {  132,    0,   70, 0x0000,    0,    3,    0,    3 },  /* 146: F JUMP K L A */
    {  133,    0,   71, 0x0000,    0,    3,   31,    3 },  /* 147: F JUMP K L A */
    {  134,    0,   72, 0x0000,    0,    3,    0,    3 },  /* 148: F JUMP K L A */
    {  135,    0,   73, 0x0000,    0,    3,    0,    3 },  /* 149: F JUMP K L A */
    {  136,    0,   74, 0x0000,    0,    3,    0,    3 },  /* 150: F JUMP K L A */
    {  137,    0,   75, 0x0000,    0,    3,    0,    3 },  /* 151: F JUMP K L A */
    {  138,    0,   76, 0x0000,    0,    3,    0,    3 },  /* 152: F JUMP K L A */
    {  139,    0,   77, 0x0000,    0,    3,    0,    3 },  /* 153: F JUMP K L A */
    {  140,    0,   78, 0x0000,    0,    3,    0,    3 },  /* 154: F JUMP K L A */
    {   72,    0,   79, 0x0000,    0,    3,   32,    3 },  /* 155: V JUMP P M A */
    {   72,    0,   79, 0x0000,    0,    3,   33,    3 },  /* 156: V JUMP P M A */
    {  141,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 157: V JUMP P L A, F JUMP P L B */
    {  142,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 158: V JUMP P L A, F JUMP P L B */
    {  143,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 159: V JUMP P L A, F JUMP P L B */
    {  144,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 160: V JUMP P L A, F JUMP P L B */
    {  145,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 161: V JUMP P L A, F JUMP P L B */
    {  146,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 162: V JUMP P L A, F JUMP P L B */
    {  147,    0,   80, 0x0000,    0,    3,    0,    3 },  /* 163: V JUMP P L A, F JUMP P L B */
    {  148,    0,   81, 0x0000,    0,    3,   34,    3 },  /* 164: V JUMP P L A, F JUMP P L B */
    {  149,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 165: V JUMP P L A, F JUMP P L B */
    {  150,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 166: V JUMP P L A, F JUMP P L B */
    {  151,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 167: V JUMP P L A, F JUMP P L B */
    {  152,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 168: V JUMP K L A */
    {  153,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 169: V JUMP K L A */
    {  154,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 170: V JUMP K L A */
    {  155,    0,   82, 0x0000,    0,    3,    0,    3 },  /* 171: V JUMP K L A */
    {  156,    0,   83, 0x0000,    0,    3,   35,    3 },  /* 172: V JUMP K L A */
    {  157,    0,   84, 0x0000,    0,    3,   36,    3 },  /* 173: V JUMP K L A */
    {  158,    0,   85, 0x0000,    0,    3,    0,    3 },  /* 174: V JUMP K L A */
    {  159,    0,   86, 0x0000,    0,    3,    0,    3 },  /* 175: V JUMP K L A */
    {  160,    0,   87, 0x0000,    0,    3,    0,    3 },  /* 176: V JUMP K L A */
    {  161,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 177: V JUMP K L A */
    {  162,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 178: F JUMP K S A, F JUMP K M A */
    {  163,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 179: F JUMP K S A, F JUMP K M A */
    {  164,    0,   88, 0x0000,    0,    3,   37,    3 },  /* 180: F JUMP K S A */
    {  164,    0,   88, 0x0000,    0,    3,   38,    3 },  /* 181: F JUMP K S A */
    {  164,    0,   89, 0x0000,    0,    3,   39,    3 },  /* 182: F JUMP K M A */
    {  164,    0,   89, 0x0000,    0,    3,   40,    3 },  /* 183: F JUMP K M A */
    {  165,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 184: F JUMP P S A, F JUMP P M A */
    {  166,    0,   90, 0x0000,    0,    3,   41,    3 },  /* 185: F JUMP P S A */
    {  166,    0,   90, 0x0000,    0,    3,   42,    3 },  /* 186: F JUMP P S A */
    {  166,    0,   91, 0x0000,    0,    3,   43,    3 },  /* 187: F JUMP P M A */
    {  166,    0,   91, 0x0000,    0,    3,   44,    3 },  /* 188: F JUMP P M A */
    {  167,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 189: F JUMP P L A */
    {  168,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 190: F JUMP P L A */
    {  169,    0,   92, 0x0000,    0,    3,    0,    3 },  /* 191: F JUMP P L A */
    {  170,    0,   93, 0x0000,    0,    3,    0,    3 },  /* 192: F JUMP P L A */
    {  171,    0,   94, 0x0000,    0,    3,   45,    3 },  /* 193: F JUMP P L A */
    {  172,    0,   94, 0x0000,    0,    3,   46,    3 },  /* 194: F JUMP P L A */
    {  173,    0,   95, 0x0000,    0,    3,    0,    3 },  /* 195: F JUMP P L A */
    {  174,    0,   96, 0x0000,    0,    3,    0,    3 },  /* 196: F JUMP P L A */
    {  175,    0,   97, 0x0000,    0,    3,    0,    3 },  /* 197: F JUMP P L A */
    {  176,    0,   98, 0x0000,    0,    3,   47,    3 },  /* 198: F JUMP P L A */
    {  177,    0,   98, 0x0000,    0,    3,   48,    3 },  /* 199: F JUMP P L A */
    {  178,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 200: L KICK A */
    {  179,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 201: L KICK A */
    {  180,    0,   99, 0x0000,    0,    1,   49,    1 },  /* 202: L KICK A */
    {  180,    0,  100, 0x0000,    0,    1,   50,    1 },  /* 203: L KICK A */
    {  181,    0,  101, 0x0000,    0,    1,    0,    1 },  /* 204: L KICK A */
    {  182,    0,  102, 0x0000,    0,    1,    0,    1 },  /* 205: M KICK A */
    {  183,    0,  103, 0x0000,    0,    1,    0,    1 },  /* 206: M KICK A */
    {  184,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 207: M KICK A */
    {  185,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 208: M KICK A */
    {  186,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 209: M KICK A */
    {  187,    0,  104, 0x0000,    0,    1,   51,    1 },  /* 210: follow-up of M KICK A */
    {  187,    0,  105, 0x0000,    0,    1,    0,    1 },  /* 211: follow-up of M KICK A */
    {  187,    0,  106, 0x0000,    0,    1,   52,    1 },  /* 212: follow-up of M KICK A */
    {   59,    0,   35, 0x0000,    0,    1,    0,    1 },  /* 213: follow-up of M KICK A */
    {  188,    0,    0, 0x0000,    0,    8,    0,    2 },  /* 214: KAGAMI P A, KAGAMI K A */
    {  189,    0,  107, 0x0000,    0,    8,   53,    2 },  /* 215: KAGAMI P A */
    {  189,    0,  107, 0x0000,    0,    8,   54,    2 },  /* 216: KAGAMI P A */
    {  190,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 217: KAGAMI P A */
    {  191,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 218: KAGAMI P A */
    {  192,    0,  108, 0x0000,    0,    2,   55,    2 },  /* 219: KAGAMI P A */
    {  192,    0,  109, 0x0000,    0,    2,   56,    2 },  /* 220: KAGAMI P A */
    {  193,    0,  110, 0x0000,    0,    2,    0,    2 },  /* 221: KAGAMI P A */
    {  194,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 222: KAGAMI P A */
    {  195,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 223: KAGAMI P A */
    {  196,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 224: KAGAMI P A */
    {  197,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 225: KAGAMI P A */
    {  198,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 226: KAGAMI P A */
    {  199,    0,  111, 0x0000,    0,    2,   57,    2 },  /* 227: KAGAMI P A */
    {  199,    0,  112, 0x0000,    0,    2,    0,    2 },  /* 228: KAGAMI P A */
    {  200,    0,  113, 0x0000,    0,    2,    0,    2 },  /* 229: KAGAMI P A */
    {  201,    0,  114, 0x0000,    0,    2,    0,    2 },  /* 230: KAGAMI P A, follow-up of SP APPEAR 7, follow-up of SP APPEAR 8 +3 */
    {  202,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 231: KAGAMI P A, follow-up of SP APPEAR 7, follow-up of SP APPEAR 8 +3 */
    {  203,    0,    0, 0x0000,    0,    8,    0,    2 },  /* 232: KAGAMI K A */
    {  204,    0,  115, 0x0000,    0,    8,   58,    2 },  /* 233: KAGAMI K A */
    {  205,    0,  116, 0x0000,    0,    8,   59,    2 },  /* 234: KAGAMI K A */
    {  206,    0,  117, 0x0000,    0,    8,    0,    2 },  /* 235: KAGAMI K A */
    {  207,    0,    0, 0x0000,    0,    8,    0,    2 },  /* 236: KAGAMI K A */
    {  208,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 237: KAGAMI K A */
    {  209,    0,  118, 0x0000,    0,    2,    0,    2 },  /* 238: KAGAMI K A */
    {  210,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 239: KAGAMI K A */
    {  211,    0,  119, 0x0000,    0,    2,   60,    2 },  /* 240: KAGAMI K A */
    {  212,    0,  120, 0x0000,    0,    2,    0,    2 },  /* 241: KAGAMI K A */
    {  213,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 242: KAGAMI K A */
    {  214,    0,  121, 0x0000,    0,    2,    0,    2 },  /* 243: KAGAMI K A */
    {  215,    0,  122, 0x0000,    0,    2,    0,    2 },  /* 244: KAGAMI K A */
    {  216,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 245: KAGAMI K A */
    {  217,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 246: KAGAMI K A */
    {  218,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 247: KAGAMI K A */
    {  219,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 248: KAGAMI K A */
    {  220,    0,  123, 0x0000,    0,    2,   61,    2 },  /* 249: KAGAMI K A */
    {  220,    0,  124, 0x0000,    0,    2,   62,    2 },  /* 250: KAGAMI K A */
    {  220,    0,  124, 0x0000,    0,    2,    0,    2 },  /* 251: KAGAMI K A */
    {  221,    0,  125, 0x0000,    0,    2,    0,    2 },  /* 252: KAGAMI K A */
    {  222,    0,  126, 0x0000,    0,    2,    0,    2 },  /* 253: KAGAMI K A */
    {  223,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 254: KAGAMI K A */
    {  224,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 255: follow-up of SP WIN 1 */
    {  109,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 256: ATTACK 9 S: not started by a command */
    {  225,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 257: ATTACK 9 S: not started by a command */
    {  226,    0,  127, 0x0000,    0,    3,   63,    3 },  /* 258: ATTACK 9 S: not started by a command */
    {  227,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 259: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  228,    0,  128, 0x0000,    0,    1,    0,    1 },  /* 260: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  228,    0,  129, 0x0000,    0,    1,    0,    1 },  /* 261: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  229,    0,  130, 0x0000,    0,    1,    0,    1 },  /* 262: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  230,    0,  131, 0x0000,    0,    1,    0,    1 },  /* 263: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  231,    0,  132, 0x0000,    0,    1,    0,    1 },  /* 264: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  232,    0,  133, 0x0000,    0,    1,    0,    1 },  /* 265: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  233,    0,  134, 0x0000,    0,    1,    0,    1 },  /* 266: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  234,    0,  135, 0x0000,    0,    3,   64,    6 },  /* 267: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  235,    0,  136, 0x0000,    0,    3,   65,    6 },  /* 268: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  236,    0,  137, 0x0000,    0,    3,    0,    6 },  /* 269: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  237,    0,    0, 0x0000,    0,    3,    0,    6 },  /* 270: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  238,    0,  138, 0x0000,    0,    3,    0,    6 },  /* 271: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  239,    0,  139, 0x0000,    0,    3,   66,    6 },  /* 272: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  240,    0,  140, 0x0000,    0,    3,    0,    6 },  /* 273: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  241,    0,    0, 0x0000,    0,    3,    0,    6 },  /* 274: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  242,    0,  141, 0x0000,    0,    3,    0,    6 },  /* 275: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  243,    0,  142, 0x0000,    0,    3,    0,    6 },  /* 276: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  244,    0,  143, 0x0000,    0,    3,    0,    6 },  /* 277: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  245,    0,  144, 0x0000,    0,    3,    0,    5 },  /* 278: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  246,    0,  145, 0x0000,    0,    3,    0,    5 },  /* 279: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  247,    0,    0, 0x0000,    0,    3,    0,    5 },  /* 280: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    {  248,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 281: follow-up of APPEAR JUNBI 8 */
    {  249,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 282: follow-up of APPEAR JUNBI 8 */
    {  250,    0,  146, 0x0000,    0,    2,    0,    2 },  /* 283: follow-up of APPEAR JUNBI 8 */
    {  251,    0,  147, 0x0000,    0,    2,    0,    2 },  /* 284: follow-up of APPEAR JUNBI 8 */
    {  252,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 285: follow-up of APPEAR JUNBI 8 */
    {  253,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 286: follow-up of APPEAR JUNBI 8 */
    {  254,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 287: follow-up of APPEAR JUNBI 8 */
    {  255,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 288: TUKAMIKAKARI A */
    {  256,    0,  148, 0x0000,    0,    1,    0,    1 },  /* 289: TUKAMIKAKARI A */
    {  257,    0,  149, 0x0000,    0,    1,    0,    1 },  /* 290: TUKAMIKAKARI A */
    {  258,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 291: TUKAMIKAKARI A */
    {  259,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 292: TUKAMIKAKARI A */
    {  260,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 293: TUKAMI AIR A */
    {  261,    0,  150, 0x0000,    0,    3,    0,    3 },  /* 294: TUKAMI AIR A */
    {  262,    0,  151, 0x0000,    0,    3,    0,    3 },  /* 295: TUKAMI AIR A */
    {  263,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 296: TUKAMI AIR A */
    {  264,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 297: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +1 */
    {  265,    0,  152, 0x0000,    0,    1,    0,    1 },  /* 298: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +1 */
    {  266,    0,  153, 0x0000,    0,    1,    0,    1 },  /* 299: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    {  267,    0,  154, 0x0000,    0,    1,    0,    1 },  /* 300: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    {  268,    0,  155, 0x0000,    0,    1,    0,    1 },  /* 301: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    {  269,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 302: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    {  270,    0,  156, 0x0000,    0,    1,    0,    1 },  /* 303: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  271,    0,  157, 0x0000,    0,    1,   67,    1 },  /* 304: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  272,    0,  158, 0x0000,    0,    1,    0,    1 },  /* 305: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +5 */
    {  271,    0,  159, 0x0000,    0,    1,   68,    1 },  /* 306: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  272,    0,  160, 0x0000,    0,    1,    0,    1 },  /* 307: not used by a script */
    {  271,    0,  161, 0x0000,    0,    1,   69,    1 },  /* 308: not used by a script */
    {  272,    0,  162, 0x0000,    0,    1,    0,    1 },  /* 309: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +5 */
    {  271,    0,  163, 0x0000,    0,    1,   70,    1 },  /* 310: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  273,    0,  157, 0x0000,    0,    1,   67,    1 },  /* 311: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +1 */
    {  274,    0,  158, 0x0000,    0,    1,    0,    1 },  /* 312: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +2 */
    {  273,    0,  159, 0x0000,    0,    1,   68,    1 },  /* 313: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +1 */
    {  274,    0,  160, 0x0000,    0,    1,    0,    1 },  /* 314: not used by a script */
    {  273,    0,  161, 0x0000,    0,    1,   69,    1 },  /* 315: not used by a script */
    {  274,    0,  162, 0x0000,    0,    1,    0,    1 },  /* 316: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +2 */
    {  273,    0,  163, 0x0000,    0,    1,   70,    1 },  /* 317: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +1 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 318: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU), ATTACK 6 S: SA I 23623+P (plain script), ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) +2 */
    {  275,    0,  164, 0x0000,    0,    3,   71,    7 },  /* 319: V JUMP K M B */
    {  275,    0,  164, 0x0000,    0,    3,    0,    7 },  /* 320: V JUMP K M B */
    {   82,    0,    0, 0x0000,    0,    3,    0,    7 },  /* 321: V JUMP K M B */
    {   83,    0,    0, 0x0000,    0,    3,    0,    7 },  /* 322: V JUMP K M B */
    {  276,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 323: UPPER L */
    {  277,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 324: UPPER L */
    {  278,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 325: UPPER L */
    {  279,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 326: not used by a script */
    {  280,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 327: FACE S, FACE M, FACE L +7 */
    {  281,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 328: FACE M, FACE L, FOOK OKU L +3 */
    {  282,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 329: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    {  283,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 330: FACE L, FOOK OKU L, FOOK OKU SP +1 */
    {  284,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 331: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {  285,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 332: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    {  286,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 333: NOUTEN L, BODY BROW L, BODY UPPER L */
    {  287,    0,    0, 0x0000,    0,    1,    0,    5 },  /* 334: BODY UPPER L */
    {  288,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 335: TATAKI S, KAGAMI S, KAGAMI M +5 */
    {  289,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 336: TATAKI S, KAGAMI M, KAGAMI L +2 */
    {  290,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 337: KAGAMI L */
    {  291,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 338: KAGAMI L */
    {  292,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 339: not used by a script */
    {  293,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 340: not used by a script */
    {  294,    0,  165, 0x0000,    0,    1,    0,    1 },  /* 341: not used by a script */
    {  295,    0,  166, 0x0000,    0,    1,    0,    1 },  /* 342: follow-up of ATTACK 6 S, ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   72,    1 },  /* 343: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   73,    1 },  /* 344: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   74,    1 },  /* 345: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   75,    1 },  /* 346: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   76,    1 },  /* 347: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   77,    1 },  /* 348: ATTACK 6 S: SA I 23623+P (plain script) */
    {  295,    0,  166, 0x0000,    0,    1,   78,    1 },  /* 349: not used by a script */
    {  296,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 350: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  297,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 351: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  298,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 352: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  299,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 353: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  300,    0,  167, 0x0000,    0,    1,    0,    8 },  /* 354: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  301,    0,  168, 0x0000,    0,    1,    0,    8 },  /* 355: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  302,    0,  169, 0x0000,    0,    1,    0,    8 },  /* 356: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  303,    0,  170, 0x0000,    0,    1,    0,    8 },  /* 357: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  304,    0,  171, 0x0000,    0,    1,    0,    8 },  /* 358: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  305,    0,  172, 0x0000,    0,    1,    0,    8 },  /* 359: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  306,    0,  173, 0x0000,    0,    1,    0,    1 },  /* 360: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  307,    0,  174, 0x0000,    0,    1,    0,    1 },  /* 361: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  308,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 362: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  309,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 363: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    {  310,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 364: KAGAMI K C */
    {  235,    0,  136, 0x0000,    0,    3,   79,    0 },  /* 365: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  239,    0,  139, 0x0000,    0,    3,   80,    0 },  /* 366: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  234,    0,  135, 0x0000,    0,    3,    0,    0 },  /* 367: not used by a script */
    {  236,    0,  137, 0x0000,    0,    3,    0,    0 },  /* 368: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  237,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 369: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  238,    0,  138, 0x0000,    0,    3,    0,    0 },  /* 370: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  240,    0,  140, 0x0000,    0,    3,    0,    0 },  /* 371: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  241,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 372: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  242,    0,  141, 0x0000,    0,    3,    0,    0 },  /* 373: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  311,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 374: AIR NORMAL, UPPER, BODY SLAM +13 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 375: follow-up of AIR NORMAL */
    {    0,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 376: NEKOROBI S, no name, HANEAGARI +2 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 377: OKIAGARI, OKIAGARI F, OKIAGARI B +13 */
    {  312,    0,    0, 0x0000,    0,    0,    0,    4 },  /* 378: no name */
    {  261,    0,  150, 0x0000,    2,    3,    0,    3 },  /* 379: TUKAMI AIR A */
    {  272,    0,  175, 0x0000,    0,    1,    0,    1 },  /* 380: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  271,    0,  176, 0x0000,    0,    1,   81,    1 },  /* 381: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  272,    0,  177, 0x0000,    0,    1,    0,    1 },  /* 382: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  274,    0,  175, 0x0000,    0,    1,    0,    1 },  /* 383: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +4 */
    {  273,    0,  176, 0x0000,    0,    1,   81,    1 },  /* 384: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +1 */
    {  274,    0,  177, 0x0000,    0,    1,    0,    1 },  /* 385: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +1 */
    {  271,    0,  178, 0x0000,    0,    1,   82,    1 },  /* 386: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  271,    0,  179, 0x0000,    0,    1,   83,    1 },  /* 387: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  271,    0,  180, 0x0000,    0,    1,   84,    1 },  /* 388: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  271,    0,  181, 0x0000,    0,    1,   85,    1 },  /* 389: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  273,    0,  178, 0x0000,    0,    1,   82,    1 },  /* 390: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  273,    0,  179, 0x0000,    0,    1,   83,    1 },  /* 391: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  273,    0,  180, 0x0000,    0,    1,   84,    1 },  /* 392: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  273,    0,  181, 0x0000,    0,    1,   85,    1 },  /* 393: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  313,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 394: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  314,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 395: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  315,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 396: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  316,    0,  182, 0x0000,    0,    1,   86,    1 },  /* 397: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  317,    0,  183, 0x0000,    0,    1,    0,    1 },  /* 398: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  316,    0,  184, 0x0000,    0,    1,   87,    1 },  /* 399: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  317,    0,  185, 0x0000,    0,    1,    0,    1 },  /* 400: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  316,    0,  186, 0x0000,    0,    1,   88,    1 },  /* 401: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  317,    0,  187, 0x0000,    0,    1,    0,    1 },  /* 402: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  316,    0,  188, 0x0000,    0,    1,   89,    1 },  /* 403: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  318,    0,  189, 0x0000,    0,    1,    0,    1 },  /* 404: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  319,    0,  190, 0x0000,    0,    1,   86,    1 },  /* 405: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  318,    0,  191, 0x0000,    0,    1,    0,    1 },  /* 406: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  319,    0,  192, 0x0000,    0,    1,   87,    1 },  /* 407: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  318,    0,  193, 0x0000,    0,    1,    0,    1 },  /* 408: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  319,    0,  194, 0x0000,    0,    1,   88,    1 },  /* 409: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  318,    0,  195, 0x0000,    0,    1,    0,    1 },  /* 410: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  319,    0,  196, 0x0000,    0,    1,   89,    1 },  /* 411: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  318,    0,  197, 0x0000,    0,    1,    0,    1 },  /* 412: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  272,    0,  175, 0x0000,    0,    1,    0,    1 },  /* 413: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  274,    0,  175, 0x0000,    0,    1,    0,    1 },  /* 414: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  320,    0,  198, 0x0000,    0,    1,    0,    1 },  /* 415: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  321,    0,  199, 0x0000,    0,    1,    0,    1 },  /* 416: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  322,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 417: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  323,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 418: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  324,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 419: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  325,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 420: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  326,    0,  200, 0x0000,    0,    1,   90,    1 },  /* 421: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  326,    0,  200, 0x0000,    0,    1,   91,    1 },  /* 422: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  326,    0,  201, 0x0000,    0,    1,    0,    1 },  /* 423: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  327,    0,  202, 0x0000,    0,    1,    0,    1 },  /* 424: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  328,    0,  203, 0x0000,    0,    1,    0,    1 },  /* 425: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  329,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 426: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    {  330,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 427: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    {  331,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 428: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {  332,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 429: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  333,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 430: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  334,    0,  204, 0x0000,    0,    3,    0,    3 },  /* 431: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  335,    0,  205, 0x0000,    0,    3,    0,    3 },  /* 432: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {  336,    0,  206, 0x0000,    0,    2,   92,    2 },  /* 433: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    {  337,    0,  207, 0x0000,    0,    2,   93,    2 },  /* 434: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    {  337,    0,  207, 0x0000,    0,    2,    0,    2 },  /* 435: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    {  331,    0,    0, 0x0000,    0,    3,   94,    3 },  /* 436: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {  335,    0,  205, 0x0000,    0,    3,   95,    3 },  /* 437: not used by a script */
    {  332,    0,  208, 0x0000,    0,    3,   96,    3 },  /* 438: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {  333,    0,  209, 0x0000,    0,    3,   97,    3 },  /* 439: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {  334,    0,  210, 0x0000,    0,    3,   98,    3 },  /* 440: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {  338,    0,  211, 0x0000,    0,    2,    0,    2 },  /* 441: KAGAMI K A */
    {  339,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 442: F JUMP K S A, F JUMP K M A */
    {  340,    0,  212, 0x0000,    0,    3,    0,    3 },  /* 443: F JUMP K M A */
    {  341,    0,  213, 0x0000,    0,    3,    0,    3 },  /* 444: F JUMP K M A */
    {  342,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 445: F JUMP K M A */
    {  343,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 446: M KICK C */
    {  344,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 447: M KICK C */
    {  345,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 448: M KICK C */
    {  346,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 449: M KICK C */
    {  347,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 450: ASIBARAI SIRI */
    {  348,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 451: ASIBARAI SIRI */
    {  349,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 452: ASIBARAI SIRI, UP P GUARD P M */
    {  350,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 453: ASIBARAI SIRI */
    {  351,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 454: ASIB TUNNOMERI, HUMI ASIB */
    {  352,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 455: ASIB TUNNOMERI, HUMI ASIB */
    {  353,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 456: ASIB TUNNOMERI, HUMI ASIB */
    {  354,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 457: ASIB TUNNOMERI, HUMI ASIB */
    {  355,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 458: NOKEZORI, FACE, HANEKAERI HARA */
    {  356,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 459: NOKEZORI, UPPER, BODY UPPER +6 */
    {  357,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 460: NOKEZORI, UPPER, BODY UPPER +6 */
    {  358,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 461: NOKEZORI, UPPER, BODY UPPER +6 */
    {  359,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 462: NOKEZORI, UPPER, BODY UPPER +6 */
    {  360,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 463: NOKEZORI, UPPER, BODY UPPER +6 */
    {  361,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 464: NOKEZORI, UPPER, BODY UPPER +6 */
    {  362,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 465: NOKEZORI, UPPER, BODY UPPER +6 */
    {  363,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 466: NOKEZORI, UPPER, BODY UPPER +6 */
    {  364,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 467: KUNOJI, KUNOJI NOKE */
    {  365,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 468: KUNOJI, KUNOJI NOKE */
    {  366,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 469: KUNOJI, KUNOJI NOKE */
    {  367,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 470: KUNOJI, KUNOJI NOKE */
    {  368,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 471: KUNOJI */
    {  369,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 472: KIRIMOMI */
    {  370,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 473: KIRIMOMI */
    {  371,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 474: KIRIMOMI */
    {  372,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 475: KIRIMOMI */
    {  373,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 476: KIRIMOMI */
    {  374,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 477: KIRIMOMI */
    {  375,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 478: KIRIMOMI */
    {  376,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 479: UPPER, TATUMAKIZANKU */
    {  377,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 480: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    {  378,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 481: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    {  379,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 482: BODY UPPER */
    {  380,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 483: BODY UPPER */
    {  381,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 484: BODY UPPER */
    {  382,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 485: BODY UPPER */
    {  383,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 486: HARAYARARE */
    {  384,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 487: TTKI V. AIR */
    {  385,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 488: TTKI V. AIR */
    {  386,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 489: TTKI V. AIR */
    {  387,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 490: DENKI */
    {  388,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 491: TOUKETSU A */
    {  389,    0,  214, 0x0000,    0,    1,    0,    1 },  /* 492: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    {  390,    0,  215, 0x0000,    0,    3,    0,    3 },  /* 493: F JUMP K L A */
    {  336,    0,  206, 0x0000,    0,    2,   99,    2 },  /* 494: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {  123,    0,   62, 0x0000,    0,    3,  100,    3 },  /* 495: V JUMP K S A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 496: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 497: LOSE SONABA, SHIMEOTASARE */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 498: FRONT WALK, BACK WALK */
    {  391,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 499: FRONT WALK */
    {  392,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 500: HURIMUKI, FRONT WALK, BACK WALK */
    {  393,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 501: FRONT WALK, BACK WALK */
    {  394,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 502: HURIMUKI, BACK WALK */
    {  395,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 503: FRONT WALK */
    {  396,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 504: PIYO */
    {  397,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 505: PIYO */
    {  192,    0,  109, 0x0000,    0,    2,    0,    2 },  /* 506: KAGAMI P A */
    {  398,    0,  132, 0x0000,    0,    3,    0,    1 },  /* 507: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  399,    0,  133, 0x0000,    0,    3,    0,    1 },  /* 508: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  400,    0,  134, 0x0000,    0,    3,    0,    1 },  /* 509: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    {  401,    0,  135, 0x0000,    0,    3,    0,    0 },  /* 510: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
};

const BODY_BOX chun_body_box[402] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {   -8,  22,  79,  17 },  {  -24,  53,  66,  16 },  {  -22,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +93 */
    { { {  -19,  24,  41,  18 },  {  -25,  53,  33,  17 },  {  -21,  53,  19,  16 },  {  -34,  69,   0,  24 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +26 */
    { { {  -24,  22,  74,  17 },  {  -42,  59,  71,   7 },  {  -40,  59,  33,  38 },  {  -44,  67,   0,  34 } } },  /* 3: S PUNCH A */
    { { {  -20,  22,  73,  17 },  {  -36,  59,  70,  12 },  {  -34,  63,  33,  38 },  {  -46,  78,   0,  38 } } },  /* 4: S PUNCH A */
    { { {  -20,  22,  76,  17 },  {  -36,  59,  72,  12 },  {  -34,  63,  33,  40 },  {  -46,  78,   0,  38 } } },  /* 5: S PUNCH A */
    { { {  -18,  22,  77,  17 },  {  -36,  59,  72,  12 },  {  -34,  63,  33,  40 },  {  -46,  78,   0,  38 } } },  /* 6: S PUNCH A */
    { { {  -16,  22,  78,  17 },  {  -37,  60,  72,  12 },  {  -33,  62,  33,  40 },  {  -44,  76,   0,  38 } } },  /* 7: S PUNCH A */
    { { {  -21,  22,  80,  17 },  {  -43,  60,  75,  10 },  {  -34,  52,  32,  47 },  {  -40,  68,   0,  32 } } },  /* 8: S PUNCH B */
    { { {  -35,  22,  81,  17 },  {  -50,  52,  69,  21 },  {  -53,  51,  32,  37 },  {  -52,  69,   0,  32 } } },  /* 9: S PUNCH B */
    { { {  -28,  22,  81,  17 },  {  -29,  66,  75,  20 },  {  -31,  54,  32,  47 },  {  -41,  69,   0,  32 } } },  /* 10: M PUNCH C, S V JP S P A */
    { { {  -30,  22,  77,  17 },  {  -29,  66,  71,  20 },  {  -32,  56,  30,  45 },  {  -43,  71,   0,  32 } } },  /* 11: M PUNCH C */
    { { {  -24,  22,  83,  17 },  {  -40,  66,  72,  20 },  {  -27,  57,  30,  43 },  {  -43,  84,   0,  32 } } },  /* 12: M PUNCH C */
    { { {  -20,  22,  83,  17 },  {  -30,  60,  72,  25 },  {  -20,  54,  30,  43 },  {  -39,  80,   0,  32 } } },  /* 13: M PUNCH C */
    { { {  -20,  22,  83,  17 },  {  -30,  60,  72,  25 },  {  -20,  54,  30,  43 },  {  -39,  80,   0,  32 } } },  /* 14: M PUNCH C */
    { { {  -12,  22,  80,  17 },  {  -19,  52,  59,  29 },  {  -22,  61,  32,  27 },  {  -38,  79,   0,  32 } } },  /* 15: M PUNCH C */
    { { {  -13,  22,  78,  17 },  {  -19,  52,  55,  30 },  {  -22,  62,  32,  23 },  {  -40,  81,   0,  32 } } },  /* 16: M PUNCH C */
    { { {  -22,  22,  84,  17 },  {  -35,  58,  71,  21 },  {  -38,  64,  32,  39 },  {  -46,  87,   0,  32 } } },  /* 17: M PUNCH C */
    { { {  -15,  22,  85,  17 },  {  -17,  56,  71,  28 },  {  -38,  54,  32,  39 },  {  -46,  83,   0,  32 } } },  /* 18: M PUNCH C */
    { { {  -15,  22,  85,  17 },  {  -29,  61,  71,  28 },  {  -38,  54,  32,  39 },  {  -46,  83,   0,  32 } } },  /* 19: M PUNCH C */
    { { {  -15,  22,  85,  17 },  {  -29,  61,  71,  28 },  {  -38,  54,  32,  39 },  {  -46,  83,   0,  32 } } },  /* 20: M PUNCH C */
    { { {  -13,  22,  85,  17 },  {  -24,  50,  72,  23 },  {  -33,  52,  32,  40 },  {  -43,  80,   0,  32 } } },  /* 21: M PUNCH C */
    { { {  -11,  22,  87,  17 },  {  -20,  46,  72,  21 },  {  -28,  53,  32,  40 },  {  -39,  76,   0,  32 } } },  /* 22: M PUNCH C */
    { { {  -12,  22,  81,  17 },  {  -13,  44,  48,  38 },  {  -29,  60,  32,  16 },  {  -40,  77,   0,  32 } } },  /* 23: M PUNCH C */
    { { {  -15,  22,  78,  17 },  {  -41,  68,  70,  15 },  {  -32,  57,  32,  38 },  {  -40,  68,   0,  32 } } },  /* 24: M PUNCH A, no name */
    { { {  -26,  22,  76,  17 },  {  -42,  69,  70,  15 },  {  -32,  57,  32,  38 },  {  -42,  70,   0,  32 } } },  /* 25: M PUNCH A, no name */
    { { {  -38,  22,  76,  17 },  {  -39,  44,  48,  42 },  {  -44,  59,  32,  16 },  {  -48,  81,   0,  33 } } },  /* 26: M PUNCH A, no name */
    { { {  -38,  22,  75,  17 },  {  -39,  44,  48,  41 },  {  -44,  59,  32,  16 },  {  -48,  81,   0,  33 } } },  /* 27: M PUNCH A, no name */
    { { {  -49,  22,  75,  17 },  {  -62,  48,  59,  30 },  {  -47,  48,  38,  38 },  {  -57,  70,   0,  38 } } },  /* 28: M PUNCH A, no name */
    { { {  -24,  22,  76,  17 },  {  -51,  73,  65,  19 },  {  -36,  57,  37,  29 },  {  -53,  78,   0,  37 } } },  /* 29: M PUNCH A, no name */
    { { {   -7,  22,  77,  17 },  {  -27,  56,  66,  16 },  {  -28,  54,  32,  38 },  {  -36,  64,   0,  32 } } },  /* 30: L PUNCH C */
    { { {   -9,  22,  77,  17 },  {  -18,  46,  69,  15 },  {  -22,  52,  44,  25 },  {  -40,  71,   0,  44 } } },  /* 31: L PUNCH C */
    { { {  -15,  22,  75,  17 },  {  -20,  47,  39,  43 },  {  -41,  61,  28,  11 },  {  -65,  86,   0,  28 } } },  /* 32: L PUNCH C */
    { { {  -10,  22,  74,  17 },  {  -18,  46,  39,  41 },  {  -44,  66,  28,  13 },  {  -61,  88,   0,  28 } } },  /* 33: L PUNCH C */
    { { {  -21,  22,  74,  17 },  {  -29,  46,  44,  36 },  {  -48,  68,  28,  16 },  {  -52,  84,   0,  28 } } },  /* 34: L PUNCH C */
    { { {  -13,  22,  76,  17 },  {  -21,  46,  46,  36 },  {  -39,  67,  28,  18 },  {  -46,  86,   0,  28 } } },  /* 35: L PUNCH C */
    { { {  -14,  22,  76,  17 },  {  -26,  49,  38,  43 },  {  -34,  60,  28,  10 },  {  -46,  76,   0,  28 } } },  /* 36: L PUNCH C */
    { { {  -18,  22,  76,  17 },  {  -27,  49,  38,  43 },  {  -33,  57,  28,  10 },  {  -38,  64,   0,  28 } } },  /* 37: L PUNCH C */
    { { {   -6,  22,  58,  17 },  {  -39,  68,  46,  14 },  {  -27,  58,  20,  26 },  {  -69,  99,   0,  21 } } },  /* 38: L PUNCH A */
    { { {   -6,  22,  55,  17 },  {  -45,  74,  43,  12 },  {  -41,  72,  20,  23 },  {  -69,  99,   0,  21 } } },  /* 39: L PUNCH A */
    { { {   -8,  22,  55,  17 },  {  -50,  79,  43,  14 },  {  -43,  74,  20,  23 },  {  -69,  99,   0,  21 } } },  /* 40: L PUNCH A */
    { { {  -12,  22,  51,  17 },  {  -35,  58,  26,  39 },  {  -45,  77,  17,   9 },  {  -59,  94,   0,  18 } } },  /* 41: L PUNCH A */
    { { {  -38,  22,  60,  17 },  {  -51,  61,  51,  23 },  {  -43,  63,  24,  27 },  {  -41,  82,   0,  24 } } },  /* 42: L PUNCH A */
    { { {  -36,  22,  60,  17 },  {  -49,  59,  51,  23 },  {  -41,  61,  24,  27 },  {  -39,  80,   0,  24 } } },  /* 43: L PUNCH A */
    { { {  -37,  22,  62,  17 },  {  -49,  60,  51,  24 },  {  -42,  62,  24,  27 },  {  -40,  81,   0,  24 } } },  /* 44: L PUNCH A */
    { { {  -43,  22,  62,  17 },  {  -49,  49,  51,  21 },  {  -43,  59,  24,  27 },  {  -41,  77,   0,  24 } } },  /* 45: L PUNCH A */
    { { {  -46,  22,  64,  17 },  {  -52,  52,  51,  23 },  {  -46,  55,  24,  27 },  {  -43,  75,   0,  24 } } },  /* 46: L PUNCH A */
    { { {  -42,  22,  65,  17 },  {  -47,  48,  51,  23 },  {  -42,  53,  24,  27 },  {  -41,  73,   0,  24 } } },  /* 47: L PUNCH A */
    { { {  -40,  22,  67,  17 },  {  -47,  54,  51,  24 },  {  -43,  64,  24,  27 },  {  -45,  77,   0,  24 } } },  /* 48: L PUNCH A */
    { { {  -19,  22,  80,  17 },  {  -31,  53,  70,  15 },  {  -34,  53,  38,  32 },  {  -41,  63,   0,  44 } } },  /* 49: M KICK C */
    { { {   16,  22,  79,  17 },  {  -29,  91,  70,  19 },  {  -10,  46,  38,  33 },  {  -17,  36,   0,  38 } } },  /* 50: M KICK C */
    { { {   19,  22,  80,  17 },  {  -26,  88,  70,  21 },  {  -10,  46,  38,  33 },  {  -18,  37,   0,  38 } } },  /* 51: M KICK C */
    { { {   20,  22,  80,  17 },  {  -25,  79,  63,  25 },  {  -10,  50,  38,  33 },  {  -18,  37,   0,  38 } } },  /* 52: M KICK C */
    { { {   -5,  22,  82,  17 },  {  -23,  54,  63,  28 },  {  -31,  61,  38,  25 },  {  -20,  48,   0,  38 } } },  /* 53: M KICK C */
    { { {  -18,  22,  75,  17 },  {  -34,  58,  63,  22 },  {  -30,  51,  44,  19 },  {  -41,  63,   0,  44 } } },  /* 54: M KICK C */
    { { {  -22,  22,  77,  17 },  {  -37,  53,  69,  15 },  {  -35,  52,  38,  31 },  {  -41,  61,   0,  38 } } },  /* 55: M KICK A */
    { { {  -25,  22,  79,  17 },  {  -35,  51,  69,  15 },  {  -35,  52,  38,  31 },  {  -43,  63,   0,  38 } } },  /* 56: M KICK A */
    { { {  -15,  22,  80,  17 },  {  -28,  52,  69,  16 },  {  -38,  59,  38,  31 },  {  -35,  41,   0,  38 } } },  /* 57: M KICK A */
    { { {   -9,  22,  82,  17 },  {  -29,  54,  69,  18 },  {  -39,  71,  46,  23 },  {  -25,  37,   0,  46 } } },  /* 58: M KICK A */
    { { {   -9,  22,  82,  17 },  {  -29,  55,  69,  19 },  {  -30,  62,  46,  23 },  {  -25,  37,   0,  46 } } },  /* 59: M KICK A, follow-up of M KICK A */
    { { {  -11,  22,  82,  17 },  {  -29,  55,  69,  19 },  {  -30,  58,  46,  23 },  {  -25,  37,   0,  46 } } },  /* 60: M KICK A */
    { { {  -11,  22,  82,  17 },  {  -29,  55,  69,  19 },  {  -30,  58,  46,  23 },  {  -25,  37,   0,  46 } } },  /* 61: M KICK A */
    { { {  -27,  22, 100,  17 },  {  -34,  57,  85,  27 },  {  -23,  64,  62,  23 },  {  -26,  28,  30,  32 } } },  /* 62: L KICK B */
    { { {  -26,  22, 100,  17 },  {  -34,  54,  85,  27 },  {  -23,  52,  62,  29 },  {   -8,  30,  38,  24 } } },  /* 63: L KICK B */
    { { {  -26,  22,  98,  17 },  {  -34,  53,  85,  26 },  {  -36,  65,  62,  29 },  {    3,  29,  40,  22 } } },  /* 64: L KICK B */
    { { {  -29,  22,  96,  17 },  {  -23,  41,  76,  42 },  {  -41,  70,  52,  35 },  {   11,  26,  42,  21 } } },  /* 65: L KICK B */
    { { {  -19,  22,  99,  17 },  {  -29,  64,  92,  20 },  {  -37,  64,  76,  16 },  {  -33,  78,  50,  26 } } },  /* 66: L KICK B */
    { { {  -17,  22,  97,  17 },  {  -29,  71,  92,  20 },  {  -36,  64,  62,  38 },  {  -21,  28,  24,  38 } } },  /* 67: L KICK B */
    { { {   -9,  22,  96,  17 },  {  -23,  48,  85,  19 },  {  -29,  58,  57,  32 },  {  -15,  30,  20,  38 } } },  /* 68: L KICK B */
    { { {  -13,  22,  94,  17 },  {  -37,  66,  83,  17 },  {  -30,  63,  57,  29 },  {   -9,  34,   0,  59 } } },  /* 69: follow-up of APPEAR JUNBI 1 */
    { { {  -15,  22,  85,  17 },  {  -27,  57,  72,  17 },  {  -29,  62,  43,  29 },  {  -35,  65,   0,  43 } } },  /* 70: follow-up of APPEAR JUNBI 1 */
    { { {  -19,  22,  96,  17 },  {  -26,  51,  88,  22 },  {  -22,  44,  55,  33 },  {  -18,  34,  38,  17 } } },  /* 71: V JUMP P S A, V JUMP P M A, F JUMP P L A */
    { { {  -19,  22,  96,  17 },  {  -24,  61,  91,  19 },  {  -22,  44,  55,  37 },  {  -27,  54,  38,  17 } } },  /* 72: V JUMP P S A, V JUMP P M A */
    { { {  -12,  22,  79,  17 },  {  -27,  54,  66,  16 },  {  -26,  49,  33,  32 },  {  -40,  66,   0,  32 } } },  /* 73: S KICK A */
    { { {  -14,  22,  83,  17 },  {  -28,  54,  71,  16 },  {  -28,  48,  33,  38 },  {  -37,  50,   0,  32 } } },  /* 74: S KICK A */
    { { {  -10,  22,  84,  17 },  {  -24,  50,  71,  18 },  {  -28,  48,  33,  38 },  {  -25,  35,   0,  32 } } },  /* 75: S KICK A */
    { { {   -9,  22,  83,  17 },  {  -24,  50,  71,  19 },  {  -28,  48,  33,  38 },  {  -25,  35,   0,  32 } } },  /* 76: S KICK A */
    { { {   -7,  22,  83,  17 },  {  -24,  50,  71,  17 },  {  -27,  47,  33,  38 },  {  -25,  35,   0,  32 } } },  /* 77: S KICK A, no name */
    { { {   -7,  22,  82,  17 },  {  -24,  50,  69,  16 },  {  -23,  46,  33,  36 },  {  -23,  33,   0,  32 } } },  /* 78: S KICK A, no name */
    { { {   -6,  22,  80,  17 },  {  -17,  50,  69,  16 },  {  -22,  51,  35,  34 },  {  -28,  52,   0,  37 } } },  /* 79: S KICK A, no name */
    { { {  -12,  22,  80,  17 },  {  -31,  55,  66,  16 },  {  -27,  49,  33,  32 },  {  -38,  63,   0,  38 } } },  /* 80: S KICK A */
    { { {  -28,  22,  96,  17 },  {  -33,  46,  82,  22 },  {  -28,  47,  65,  24 },  {  -24,  48,  46,  23 } } },  /* 81: JUMP FRONT, SP JUMP FRONT */
    { { {  -16,  22,  96,  17 },  {  -29,  49,  84,  22 },  {  -26,  47,  68,  19 },  {  -29,  48,  50,  22 } } },  /* 82: JUMP FRONT, JUMP VERTICAL, JUMP BACK +12 */
    { { {  -12,  22, 101,  17 },  {  -24,  47,  87,  22 },  {  -22,  40,  71,  18 },  {  -29,  49,  48,  30 } } },  /* 83: JUMP FRONT, JUMP VERTICAL, JUMP BACK +10 */
    { { {  -12,  22, 101,  17 },  {  -24,  47,  87,  22 },  {  -22,  40,  71,  18 },  {  -29,  49,  53,  25 } } },  /* 84: JUMP BACK, SP JUMP BACK */
    { { {  -12,  22,  99,  17 },  {  -23,  43,  87,  20 },  {  -19,  36,  71,  18 },  {  -23,  46,  49,  26 } } },  /* 85: JUMP VERTICAL, SP JUMP V */
    { { {  -23,  22,  58,  17 },  {  -19,  53,  52,  17 },  {  -12,  53,  35,  26 },  {  -26,  61,   0,  35 } } },  /* 86: JUMP JUNBI, SP JUMP JUNBI */
    { { {   27,  22,  50,  17 },  {   -1,  43,  50,  28 },  {  -28,  35,  46,  25 },  {  -51,  40,  31,  29 } } },  /* 87: KAGAMI K C */
    { { {   27,  22,  40,  17 },  {   -1,  43,  49,  29 },  {  -36,  35,  50,  29 },  {  -54,  24,  42,  33 } } },  /* 88: KAGAMI K C */
    { { {   15,  22,  35,  17 },  {   -3,  36,  49,  32 },  {  -47,  44,  54,  32 },  {  -55,  14,  46,  35 } } },  /* 89: KAGAMI K C */
    { { {    8,  22,  34,  17 },  {   -8,  33,  44,  24 },  {  -21,  35,  60,  29 },  {  -21,  42,  89,  19 } } },  /* 90: KAGAMI K C */
    { { {   -9,  22,  34,  17 },  {  -15,  33,  46,  24 },  {  -15,  56,  70,  21 },  {    5,  26,  90,  18 } } },  /* 91: KAGAMI K C */
    { { {  -28,  22,  39,  17 },  {  -22,  35,  47,  25 },  {    1,  32,  55,  31 },  {   30,  22,  52,  39 } } },  /* 92: KAGAMI K C */
    { { {  -37,  22,  54,  17 },  {  -26,  35,  50,  28 },  {    9,  25,  42,  39 },  {   34,  27,  48,  21 } } },  /* 93: KAGAMI K C */
    { { {  -28,  22,  76,  17 },  {  -22,  33,  58,  28 },  {  -24,  49,  41,  27 },  {   -8,  38,  27,  17 } } },  /* 94: KAGAMI K C */
    { { {   -9,  22,  81,  17 },  {  -22,  43,  61,  24 },  {  -35,  51,  42,  24 },  {  -30,  26,  24,  18 } } },  /* 95: KAGAMI K C */
    { { {    6,  22,  77,  17 },  {   -7,  38,  57,  28 },  {  -29,  46,  44,  36 },  {  -47,  20,  39,  35 } } },  /* 96: KAGAMI K C */
    { { {   25,  22,  72,  17 },  {    2,  41,  54,  26 },  {  -37,  39,  50,  26 },  {  -73,  36,  59,  21 } } },  /* 97: KAGAMI K C */
    { { {   20,  22,  72,  17 },  {    2,  49,  52,  31 },  {  -38,  40,  50,  28 },  {  -72,  34,  59,  21 } } },  /* 98: KAGAMI K C */
    { { {    9,  22,  84,  17 },  {  -16,  45,  69,  27 },  {  -42,  57,  32,  48 },  {    7,  23,   0,  36 } } },  /* 99: M KICK B, no name */
    { { {   11,  22,  82,  17 },  {  -15,  43,  67,  26 },  {  -39,  57,  32,  47 },  {  -31,  60,   6,  26 } } },  /* 100: M KICK B, S V JP S P A, no name */
    { { {   11,  22,  76,  17 },  {  -15,  43,  62,  27 },  {  -51,  52,  50,  29 },  {  -38,  32,   0,  51 } } },  /* 101: M KICK B, no name */
    { { {   12,  22,  72,  17 },  {  -11,  52,  58,  27 },  {  -36,  52,  48,  33 },  {  -37,  33,   0,  48 } } },  /* 102: M KICK B, no name */
    { { {   11,  22,  77,  17 },  {  -34,  75,  59,  31 },  {  -31,  32,  38,  21 },  {  -36,  32,   0,  38 } } },  /* 103: M KICK B, no name */
    { { {   11,  22,  77,  17 },  {  -34,  75,  62,  26 },  {  -31,  32,  38,  24 },  {  -36,  32,   0,  38 } } },  /* 104: M KICK B, no name */
    { { {    7,  22,  77,  17 },  {  -35,  76,  62,  26 },  {  -32,  28,  38,  24 },  {  -39,  30,   0,  38 } } },  /* 105: M KICK B, no name */
    { { {    1,  22,  77,  17 },  {  -35,  63,  62,  28 },  {  -34,  24,  38,  24 },  {  -41,  26,   0,  38 } } },  /* 106: M KICK B, no name */
    { { {  -18,  22,  78,  17 },  {  -29,  56,  51,  38 },  {  -36,  55,  40,  11 },  {  -44,  69,   0,  40 } } },  /* 107: M KICK B, no name */
    { { {  -14,  22,  78,  17 },  {  -20,  45,  44,  39 },  {  -32,  55,  29,  15 },  {  -42,  68,   0,  29 } } },  /* 108: M KICK B, no name */
    { { {  -32,  22,  60,  17 },  {  -42,  57,  43,  24 },  {  -31,  50,  30,  21 },  {  -42,  65,   0,  30 } } },  /* 109: DASH HUMIKOMI, ATTACK 9 S: not started by a command */
    { { {  -37,  22,  63,  17 },  {  -43,  58,  43,  29 },  {  -34,  65,  28,  35 },  {  -53, 102,   0,  28 } } },  /* 110: DASH HUMIKOMI */
    { { {  -12,  22,  71,  17 },  {  -18,  49,  47,  33 },  {  -24,  52,  32,  15 },  {  -34,  59,   0,  37 } } },  /* 111: DASH HUMIKOMI, TUKAMIHAZUSI */
    { { {   -8,  22,  73,  17 },  {  -27,  64,  61,  19 },  {  -19,  54,  36,  25 },  {  -37,  70,   0,  37 } } },  /* 112: DASH HUMIKOMI */
    { { {    7,  22,  85,  17 },  {  -12,  49,  67,  25 },  {  -29,  62,  38,  39 },  {  -42,  70,   0,  43 } } },  /* 113: DASH TOBINOKI, UP P GUARD P L */
    { { {    6,  22,  88,  17 },  {  -13,  46,  67,  28 },  {  -27,  61,  34,  41 },  {  -42,  79,   0,  34 } } },  /* 114: DASH TOBINOKI */
    { { {   -5,  22,  91,  17 },  {  -10,  34,  72,  28 },  {  -16,  41,  36,  47 },  {  -23,  43,   0,  36 } } },  /* 115: DASH TOBINOKI */
    { { {  -24,  22,  90,  17 },  {  -32,  50,  65,  31 },  {  -19,  43,  36,  44 },  {  -11,  40,   0,  36 } } },  /* 116: DASH TOBINOKI */
    { { {  -31,  22,  90,  17 },  {  -33,  44,  58,  37 },  {  -16,  35,  43,  37 },  {   -7,  35,   0,  52 } } },  /* 117: DASH TOBINOKI */
    { { {  -22,  22,  80,  17 },  {  -29,  45,  58,  27 },  {  -20,  44,  35,  31 },  {  -25,  52,   0,  41 } } },  /* 118: DASH TOBINOKI */
    { { {  -24,  22,  80,  17 },  {  -31,  38,  58,  27 },  {  -29,  43,  39,  27 },  {  -38,  67,   0,  41 } } },  /* 119: DASH TOBINOKI */
    { { {  -20,  22,  81,  17 },  {  -31,  48,  66,  18 },  {  -30,  50,  33,  32 },  {  -39,  65,   0,  37 } } },  /* 120: DASH TOBINOKI */
    { { {  -16,  22, 106,  17 },  {  -26,  41,  87,  29 },  {  -37,  43,  67,  20 },  {  -48,  44,  58,  22 } } },  /* 121: V JUMP K S A, V JUMP K M A */
    { { {  -13,  22, 104,  17 },  {  -28,  44,  87,  26 },  {  -51,  59,  76,  20 },  {  -48,  50,  58,  22 } } },  /* 122: V JUMP K S A, V JUMP K M A */
    { { {  -16,  22, 101,  17 },  {  -44,  65,  93,  23 },  {  -36,  46,  76,  17 },  {  -28,  29,  46,  30 } } },  /* 123: V JUMP K S A, V JUMP K M A */
    { { {  -16,  22, 102,  17 },  {  -46,  67,  93,  24 },  {  -38,  48,  76,  17 },  {  -28,  29,  46,  30 } } },  /* 124: V JUMP K M A */
    { { {  -16,  22, 102,  17 },  {  -48,  69,  93,  24 },  {  -39,  49,  76,  17 },  {  -28,  29,  46,  30 } } },  /* 125: V JUMP K M A */
    { { {  -17,  22, 101,  17 },  {  -52,  71,  93,  22 },  {  -43,  53,  74,  19 },  {  -27,  29,  46,  28 } } },  /* 126: V JUMP K S A, V JUMP K M A */
    { { {  -17,  22, 103,  17 },  {  -51,  67,  93,  16 },  {  -38,  48,  74,  19 },  {  -25,  27,  46,  28 } } },  /* 127: V JUMP K S A, V JUMP K M A */
    { { {  -13,  22, 105,  17 },  {  -24,  37,  93,  14 },  {  -42,  49,  74,  23 },  {  -39,  51,  48,  26 } } },  /* 128: V JUMP K S A, V JUMP K M A */
    { { {  -14,  22,  92,  17 },  {  -26,  58,  81,  24 },  {  -16,  43,  65,  16 },  {  -45,  39,  60,  22 } } },  /* 129: F JUMP K L A */
    { { {   -8,  22,  90,  17 },  {  -28,  50,  81,  41 },  {   -5,  36,  66,  23 },  {  -32,  36,  56,  25 } } },  /* 130: F JUMP K L A */
    { { {   -2,  22,  90,  17 },  {  -32,  57,  84,  25 },  {  -20,  53,  73,  17 },  {  -14,  28,  54,  19 } } },  /* 131: F JUMP K L A, S V JP S P A */
    { { {    3,  22,  90,  17 },  {  -27,  52,  85,  24 },  {  -19,  52,  73,  17 },  {  -10,  27,  54,  19 } } },  /* 132: F JUMP K L A */
    { { {   -8,  22,  99,  17 },  {  -31,  66,  85,  24 },  {  -36,  83,  62,  23 },  {  -45,  14,  93,  17 } } },  /* 133: F JUMP K L A */
    { { {  -11,  22, 100,  17 },  {  -26,  59,  85,  25 },  {  -38,  66,  68,  26 },  {   -9,  61,  61,  10 } } },  /* 134: F JUMP K L A */
    { { {  -20,  22, 100,  17 },  {  -28,  53,  85,  24 },  {  -33,  55,  70,  17 },  {  -11,  37,  63,  12 } } },  /* 135: F JUMP K L A */
    { { {  -25,  22,  99,  17 },  {  -32,  41,  85,  22 },  {  -28,  46,  70,  25 },  {  -13,  25,  62,  12 } } },  /* 136: F JUMP K L A */
    { { {  -30,  22,  98,  17 },  {  -37,  43,  85,  24 },  {  -19,  40,  74,  29 },  {  -27,  39,  58,  19 } } },  /* 137: F JUMP K L A */
    { { {  -30,  22,  97,  17 },  {  -36,  46,  80,  21 },  {  -19,  39,  74,  38 },  {  -24,  36,  60,  16 } } },  /* 138: F JUMP K L A */
    { { {  -30,  22,  97,  17 },  {  -24,  41,  80,  35 },  {  -21,  42,  69,  26 },  {  -18,  26,  53,  16 } } },  /* 139: F JUMP K L A */
    { { {  -29,  22,  99,  17 },  {  -21,  30,  82,  37 },  {  -21,  40,  69,  36 },  {  -29,  37,  58,  21 } } },  /* 140: F JUMP K L A */
    { { {  -11,  22, 101,  17 },  {  -14,  41,  86,  20 },  {  -17,  43,  71,  18 },  {  -11,  32,  49,  26 } } },  /* 141: V JUMP P L A, F JUMP P L B */
    { { {   -8,  22, 101,  17 },  {   -9,  41,  86,  21 },  {  -14,  44,  71,  18 },  {  -10,  37,  49,  26 } } },  /* 142: V JUMP P L A, F JUMP P L B */
    { { {   -3,  22, 102,  17 },  {   -9,  50,  86,  22 },  {  -19,  49,  71,  16 },  {  -16,  43,  49,  26 } } },  /* 143: V JUMP P L A, F JUMP P L B */
    { { {    0,  22, 102,  17 },  {   -6,  56,  88,  23 },  {  -21,  52,  71,  21 },  {  -24,  57,  49,  26 } } },  /* 144: V JUMP P L A, F JUMP P L B */
    { { {    3,  22, 104,  17 },  {  -10,  62,  88,  23 },  {  -24,  55,  69,  27 },  {  -29,  61,  49,  20 } } },  /* 145: V JUMP P L A, F JUMP P L B */
    { { {   -4,  22, 104,  17 },  {  -10,  63,  90,  18 },  {  -23,  55,  69,  28 },  {  -29,  60,  49,  22 } } },  /* 146: V JUMP P L A, F JUMP P L B */
    { { {  -17,  22,  94,  17 },  {  -23,  42,  79,  18 },  {  -20,  42,  57,  28 },  {  -23,  47,  49,   8 } } },  /* 147: V JUMP P L A, F JUMP P L B */
    { { {  -17,  22,  93,  17 },  {  -25,  44,  79,  24 },  {  -22,  44,  57,  28 },  {  -15,  35,  49,   8 } } },  /* 148: V JUMP P L A, F JUMP P L B */
    { { {  -15,  22,  94,  17 },  {  -27,  51,  78,  25 },  {  -24,  49,  57,  28 },  {  -22,  48,  49,   8 } } },  /* 149: V JUMP P L A, F JUMP P L B */
    { { {  -12,  22,  94,  17 },  {  -27,  51,  72,  27 },  {  -16,  40,  57,  19 },  {  -13,  39,  49,   8 } } },  /* 150: V JUMP P L A, F JUMP P L B */
    { { {  -13,  22,  99,  17 },  {  -25,  49,  72,  29 },  {  -17,  40,  57,  19 },  {  -13,  33,  49,   8 } } },  /* 151: V JUMP P L A, F JUMP P L B */
    { { {  -31,  22,  97,  17 },  {  -28,  39,  87,  21 },  {  -36,  52,  70,  20 },  {  -28,  38,  56,  14 } } },  /* 152: V JUMP K L A */
    { { {  -30,  22,  98,  17 },  {  -26,  36,  87,  21 },  {  -39,  55,  70,  20 },  {  -35,  44,  56,  14 } } },  /* 153: V JUMP K L A */
    { { {  -29,  22, 100,  17 },  {  -40,  49,  87,  23 },  {  -44,  68,  75,  16 },  {  -50,  67,  63,  12 } } },  /* 154: V JUMP K L A */
    { { {  -28,  22, 100,  17 },  {  -30,  51,  87,  27 },  {  -54,  92,  75,  17 },  {  -39,  64,  65,  10 } } },  /* 155: V JUMP K L A */
    { { {  -24,  22, 100,  17 },  {  -29,  46,  87,  25 },  {  -38,  61,  75,  16 },  {  -47,  73,  63,  12 } } },  /* 156: V JUMP K L A */
    { { {  -24,  22, 100,  17 },  {  -29,  46,  87,  25 },  {  -39,  62,  75,  16 },  {  -47,  73,  61,  14 } } },  /* 157: V JUMP K L A */
    { { {  -24,  22, 101,  17 },  {  -30,  47,  87,  25 },  {  -40,  61,  75,  23 },  {  -45,  71,  61,  16 } } },  /* 158: V JUMP K L A */
    { { {  -25,  22, 101,  17 },  {  -30,  41,  87,  25 },  {  -34,  46,  61,  26 },  {   -6,  13,  54,  12 } } },  /* 159: V JUMP K L A */
    { { {  -22,  22, 105,  17 },  {  -30,  44,  87,  25 },  {  -27,  34,  61,  26 },  {  -33,  46,  46,  24 } } },  /* 160: V JUMP K L A */
    { { {  -13,  22, 106,  17 },  {  -25,  50,  81,  37 },  {  -39,  58,  61,  20 },  {  -21,  39,  46,  15 } } },  /* 161: V JUMP K L A */
    { { {  -18,  22,  96,  17 },  {  -29,  47,  83,  20 },  {  -37,  55,  71,  15 },  {  -29,  56,  53,  21 } } },  /* 162: F JUMP K S A, F JUMP K M A */
    { { {   -9,  22,  95,  17 },  {  -30,  55,  83,  21 },  {  -25,  53,  71,  15 },  {  -21,  53,  51,  20 } } },  /* 163: F JUMP K S A, F JUMP K M A */
    { { {  -14,  22,  95,  17 },  {  -34,  65,  83,  22 },  {  -55,  71,  68,  19 },  {  -22,  42,  47,  24 } } },  /* 164: F JUMP K S A, F JUMP K M A */
    { { {  -34,  22,  90,  17 },  {  -47,  68,  76,  20 },  {  -33,  65,  59,  18 },  {  -23,  60,  49,  14 } } },  /* 165: F JUMP P S A, F JUMP P M A */
    { { {  -53,  22,  82,  17 },  {  -49,  43,  73,  23 },  {  -39,  52,  59,  30 },  {  -34,  47,  48,  11 } } },  /* 166: F JUMP P S A, F JUMP P M A */
    { { {  -30,  22,  91,  17 },  {  -40,  49,  72,  22 },  {  -32,  52,  55,  31 },  {  -24,  60,  46,  29 } } },  /* 167: F JUMP P L A */
    { { {  -33,  22,  91,  17 },  {  -48,  68,  75,  19 },  {  -34,  54,  55,  31 },  {  -24,  60,  42,  30 } } },  /* 168: F JUMP P L A */
    { { {  -37,  22,  91,  17 },  {  -53,  69,  82,  20 },  {  -34,  41,  73,   9 },  {  -48,  80,  48,  25 } } },  /* 169: F JUMP P L A */
    { { {  -41,  22,  88,  17 },  {  -54,  58,  76,  21 },  {  -35,  43,  69,   8 },  {  -56,  80,  44,  25 } } },  /* 170: F JUMP P L A */
    { { {  -51,  22,  84,  17 },  {  -58,  51,  74,  20 },  {  -40,  48,  64,  14 },  {  -36,  55,  47,  17 } } },  /* 171: F JUMP P L A */
    { { {  -49,  22,  84,  17 },  {  -54,  51,  74,  20 },  {  -40,  48,  59,  19 },  {  -36,  52,  47,  17 } } },  /* 172: F JUMP P L A */
    { { {  -47,  22,  87,  17 },  {  -52,  49,  74,  22 },  {  -32,  39,  59,  32 },  {  -38,  43,  43,  31 } } },  /* 173: F JUMP P L A */
    { { {  -45,  22,  89,  17 },  {  -41,  36,  74,  25 },  {  -33,  41,  59,  32 },  {  -38,  38,  43,  19 } } },  /* 174: F JUMP P L A */
    { { {  -42,  22,  91,  17 },  {  -44,  44,  84,  17 },  {  -45,  36,  58,  26 },  {  -41,  38,  43,  19 } } },  /* 175: F JUMP P L A */
    { { {  -57,  22,  90,  17 },  {  -65,  44,  76,  19 },  {  -42,  48,  67,  36 },  {  -36,  37,  43,  25 } } },  /* 176: F JUMP P L A */
    { { {  -55,  22,  88,  17 },  {  -61,  44,  76,  19 },  {  -42,  48,  67,  35 },  {  -35,  37,  43,  25 } } },  /* 177: F JUMP P L A */
    { { {  -17,  22,  80,  17 },  {  -31,  51,  62,  23 },  {  -31,  57,  33,  29 },  {  -38,  66,   0,  32 } } },  /* 178: L KICK A */
    { { {  -24,  22,  82,  17 },  {  -37,  51,  66,  23 },  {  -36,  56,  33,  33 },  {  -42,  60,   0,  32 } } },  /* 179: L KICK A */
    { { {   12,  22,  54,  17 },  {    3,  27,  43,  41 },  {  -24,  31,  31,  39 },  {  -17,  23,   0,  32 } } },  /* 180: L KICK A */
    { { {   14,  22,  66,  17 },  {    3,  30,  43,  41 },  {  -14,  27,  31,  41 },  {  -14,  24,   0,  32 } } },  /* 181: L KICK A */
    { { {   -3,  22,  80,  17 },  {  -27,  57,  66,  17 },  {  -26,  30,  27,  39 },  {  -58,  61,   0,  27 } } },  /* 182: M KICK A */
    { { {   -6,  22,  81,  17 },  {  -25,  52,  66,  18 },  {  -26,  28,  27,  39 },  {  -48,  51,   0,  27 } } },  /* 183: M KICK A */
    { { {  -16,  22,  81,  17 },  {  -31,  48,  66,  18 },  {  -25,  30,  27,  39 },  {  -23,  39,   0,  27 } } },  /* 184: M KICK A */
    { { {  -21,  22,  80,  17 },  {  -33,  50,  66,  18 },  {  -30,  41,  27,  39 },  {  -29,  47,   0,  27 } } },  /* 185: M KICK A */
    { { {  -24,  22,  80,  17 },  {  -32,  45,  54,  27 },  {  -38,  44,  27,  27 },  {  -43,  62,   0,  25 } } },  /* 186: M KICK A */
    { { {  -12,  23,  82,  17 },  {  -29,  54,  69,  20 },  {  -27,  41,  46,  23 },  {  -25,  31,   0,  46 } } },  /* 187: follow-up of M KICK A */
    { { {  -22,  26,  42,  17 },  {  -36,  58,  33,  15 },  {  -27,  56,  16,  20 },  {  -37,  71,   0,  23 } } },  /* 188: KAGAMI P A, KAGAMI K A */
    { { {  -26,  26,  42,  17 },  {  -37,  56,  33,  15 },  {  -32,  49,  20,  16 },  {  -37,  62,   0,  23 } } },  /* 189: KAGAMI P A */
    { { {  -46,  26,  37,  17 },  {  -42,  64,  19,  31 },  {  -35,  64,  11,  31 },  {  -30,  66,   0,  23 } } },  /* 190: KAGAMI P A */
    { { {  -50,  26,  33,  17 },  {  -46,  66,  19,  27 },  {  -44,  50,   9,  25 },  {  -34,  69,   0,  27 } } },  /* 191: KAGAMI P A */
    { { {  -58,  26,  25,  17 },  {  -54,  63,  12,  27 },  {  -36,  50,   7,  25 },  {  -34,  72,   0,  20 } } },  /* 192: KAGAMI P A */
    { { {  -46,  26,  28,  17 },  {  -41,  43,  12,  28 },  {  -47,  56,   6,  13 },  {  -58,  84,   0,  14 } } },  /* 193: KAGAMI P A */
    { { {  -14,  26,  41,  17 },  {  -28,  52,  21,  27 },  {  -25,  37,   8,  13 },  {  -54,  83,   0,  17 } } },  /* 194: KAGAMI P A */
    { { {  -23,  26,  39,  17 },  {  -34,  54,  19,  27 },  {  -47,  21,  12,  27 },  {  -53,  84,   0,  19 } } },  /* 195: KAGAMI P A */
    { { {  -31,  26,  39,  17 },  {  -28,  44,  19,  28 },  {  -11,  31,  12,  17 },  {  -46,  75,   0,  21 } } },  /* 196: KAGAMI P A */
    { { {    1,  26,  46,  17 },  {  -17,  47,  41,  13 },  {  -25,  66,  24,  20 },  {  -35,  76,   0,  31 } } },  /* 197: KAGAMI P A */
    { { {  -30,  26,  48,  17 },  {  -46,  42,  39,  21 },  {  -31,  48,  24,  29 },  {  -41,  77,   0,  24 } } },  /* 198: KAGAMI P A */
    { { {  -27,  26,  45,  17 },  {  -35,  53,  33,  21 },  {  -40,  68,  16,  25 },  {  -47,  88,   0,  24 } } },  /* 199: KAGAMI P A */
    { { {  -25,  26,  45,  17 },  {  -33,  53,  33,  20 },  {  -40,  63,  16,  25 },  {  -46,  86,   0,  25 } } },  /* 200: KAGAMI P A */
    { { {  -26,  26,  43,  17 },  {  -32,  53,  30,  20 },  {  -20,  56,  16,  30 },  {  -46,  77,   0,  16 } } },  /* 201: KAGAMI P A, follow-up of SP APPEAR 7, follow-up of SP APPEAR 8 +3 */
    { { {  -25,  26,  42,  17 },  {  -34,  57,  29,  20 },  {  -24,  53,   7,  32 },  {  -36,  66,   0,  16 } } },  /* 202: KAGAMI P A, follow-up of SP APPEAR 7, follow-up of SP APPEAR 8 +3 */
    { { {  -18,  26,  46,  17 },  {  -30,  55,  36,  20 },  {  -22,  60,  18,  26 },  {  -36,  72,   0,  18 } } },  /* 203: KAGAMI K A */
    { { {   -6,  26,  47,  17 },  {  -18,  55,  33,  20 },  {  -39,  80,  16,  20 },  {  -36,  74,   0,  16 } } },  /* 204: KAGAMI K A */
    { { {   -7,  26,  46,  17 },  {  -18,  55,  33,  20 },  {  -40,  81,  16,  21 },  {  -36,  74,   0,  16 } } },  /* 205: KAGAMI K A */
    { { {   -6,  26,  47,  17 },  {  -16,  55,  35,  20 },  {  -35,  79,  25,  18 },  {  -20,  59,   0,  25 } } },  /* 206: KAGAMI K A */
    { { {   -7,  26,  46,  17 },  {  -15,  54,  34,  20 },  {  -34,  84,  27,  17 },  {  -24,  62,   0,  27 } } },  /* 207: KAGAMI K A */
    { { {  -17,  26,  44,  17 },  {  -32,  55,  41,  14 },  {  -31,  52,  22,  19 },  {  -40,  66,   0,  27 } } },  /* 208: KAGAMI K A */
    { { {    2,  26,  41,  17 },  {  -20,  54,  32,  21 },  {  -12,  56,  14,  20 },  {  -39,  65,   0,  25 } } },  /* 209: KAGAMI K A */
    { { {    7,  26,  29,  17 },  {  -18,  60,  40,  15 },  {  -25,  71,  10,  30 },  {  -34,  66,   0,  31 } } },  /* 210: KAGAMI K A */
    { { {   11,  26,  25,  17 },  {  -18,  55,  35,  18 },  {  -27,  68,  12,  23 },  {  -34,  72,   0,  27 } } },  /* 211: KAGAMI K A */
    { { {   10,  26,  26,  17 },  {  -20,  55,  35,  19 },  {  -29,  68,  12,  26 },  {  -37,  72,   0,  29 } } },  /* 212: KAGAMI K A */
    { { {  -11,  26,  29,  17 },  {  -27,  51,  32,  19 },  {  -33,  62,  12,  26 },  {  -44,  79,   0,  29 } } },  /* 213: KAGAMI K A */
    { { {  -35,  26,  40,  17 },  {  -29,  40,  20,  32 },  {  -21,  51,  12,  29 },  {  -36,  78,   0,  20 } } },  /* 214: KAGAMI K A */
    { { {  -30,  26,  39,  17 },  {  -19,  41,  20,  31 },  {   -6,  43,  12,  29 },  {  -33,  77,   0,  23 } } },  /* 215: KAGAMI K A */
    { { {  -26,  26,  38,  17 },  {  -19,  41,  20,  30 },  {   -6,  43,  12,  29 },  {  -31,  75,   0,  23 } } },  /* 216: KAGAMI K A */
    { { {  -18,  26,  45,  17 },  {  -29,  56,  41,  14 },  {  -25,  51,  24,  20 },  {  -35,  64,   0,  26 } } },  /* 217: KAGAMI K A */
    { { {   10,  26,   1,  17 },  {  -26,  59,   5,  25 },  {  -19,  48,  19,  22 },  {  -36,  58,  21,  33 } } },  /* 218: KAGAMI K A */
    { { {   17,  26,  32,  17 },  {    6,  30,  14,  43 },  {  -10,  20,  15,  35 },  {  -40,  36,  14,  46 } } },  /* 219: KAGAMI K A */
    { { {   20,  26,  46,  17 },  {    1,  31,   0,  75 },  {  -22,  24,  31,  49 },  {  -58,  36,  34,  41 } } },  /* 220: KAGAMI K A */
    { { {    4,  26,  47,  17 },  {  -11,  49,  17,  38 },  {  -33,  42,  12,  37 },  {   -3,  33,   0,  18 } } },  /* 221: KAGAMI K A */
    { { {  -17,  26,  44,  17 },  {  -22,  50,  24,  29 },  {  -35,  60,  12,  21 },  {  -30,  57,   0,  12 } } },  /* 222: KAGAMI K A */
    { { {  -23,  26,  41,  17 },  {  -27,  48,  21,  28 },  {  -37,  64,  12,  22 },  {  -44,  74,   0,  15 } } },  /* 223: KAGAMI K A */
    { { {  -34,  22,  62,  17 },  {  -49,  56,  47,  22 },  {  -36,  49,  24,  32 },  {  -45,  65,   0,  26 } } },  /* 224: follow-up of SP WIN 1 */
    { { {  -34,  22,  91,  17 },  {  -51,  73,  76,  21 },  {  -40,  72,  58,  18 },  {  -33,  70,  44,  19 } } },  /* 225: ATTACK 9 S: not started by a command */
    { { {  -56,  22,  82,  17 },  {  -52,  47,  73,  23 },  {  -41,  54,  59,  30 },  {  -38,  48,  44,  15 } } },  /* 226: ATTACK 9 S: not started by a command */
    { { {   -1,  22,  68,  17 },  {  -14,  45,  47,  28 },  {  -36,  63,  27,  20 },  {  -49,  87,   0,  27 } } },  /* 227: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   16,  22,  62,  17 },  {   -2,  55,  49,  26 },  {  -28,  63,  25,  24 },  {  -47,  85,   0,  25 } } },  /* 228: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   18,  22,  57,  17 },  {    0,  48,  49,  23 },  {  -31,  66,  25,  24 },  {  -49,  87,   0,  25 } } },  /* 229: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   22,  22,  33,  17 },  {  -16,  49,  32,  23 },  {  -31,  66,  25,  26 },  {  -46,  86,   0,  25 } } },  /* 230: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -19,  22,  20,  17 },  {  -14,  50,  35,  23 },  {  -29,  77,  24,  19 },  {  -39,  44,   0,  25 } } },  /* 231: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -40,  22,  24,  17 },  {  -34,  35,  22,  33 },  {   -5,  36,  24,  40 },  {  -10,  34,   0,  24 } } },  /* 232: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -22,  22,  33,  17 },  {  -11,  35,  30,  29 },  {    0,  37,  27,  44 },  {   12,  30,   0,  33 } } },  /* 233: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   -9,  22,  30,  17 },  {  -24,  54,  34,  21 },  {  -14,  43,  55,  25 },  {    8,  25,   0,  33 } } },  /* 234: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -10,  22,  24,  17 },  {  -18,  44,  30,  17 },  {  -10,  33,  47,  24 },  {  -36,  83,  69,  18 } } },  /* 235: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -4,  22,  24,  17 },  {  -12,  44,  30,  17 },  {  -10,  33,  47,  24 },  {  -36,  83,  69,  18 } } },  /* 236: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    3,  22,  24,  17 },  {   -9,  39,  30,  17 },  {  -10,  32,  47,  22 },  {  -25,  52,  69,  20 } } },  /* 237: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {    3,  22,  26,  17 },  {   -9,  39,  32,  17 },  {  -12,  32,  47,  24 },  {  -32,  67,  69,  18 } } },  /* 238: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -1,  22,  25,  17 },  {  -12,  44,  30,  17 },  {  -11,  33,  47,  24 },  {  -36,  83,  69,  18 } } },  /* 239: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -5,  22,  25,  17 },  {  -17,  46,  30,  17 },  {  -12,  33,  47,  24 },  {  -36,  83,  69,  18 } } },  /* 240: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   -4,  22,  24,  17 },  {  -12,  39,  30,  18 },  {  -15,  34,  47,  22 },  {  -17,  54,  69,  17 } } },  /* 241: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -14,  22,  26,  17 },  {   -9,  31,  34,  17 },  {   -8,  33,  47,  24 },  {  -32,  67,  69,  18 } } },  /* 242: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -19,  22,  42,  17 },  {  -30,  43,  55,  20 },  {  -25,  55,  75,  21 },  {   13,  24,  42,  33 } } },  /* 243: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -37,  22,  57,  17 },  {  -30,  32,  52,  35 },  {  -25,  55,  75,  22 },  {    2,  24,  39,  36 } } },  /* 244: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -13,  22,  87,  17 },  {  -28,  53,  74,  24 },  {  -21,  52,  61,  23 },  {  -17,  26,  41,  20 } } },  /* 245: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   -4,  22,  87,  17 },  {  -17,  44,  74,  26 },  {  -20,  59,  56,  24 },  {   -7,  38,  41,  15 } } },  /* 246: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   -4,  22,  87,  17 },  {  -18,  33,  74,  26 },  {  -23,  40,  56,  24 },  {  -29,  54,  40,  20 } } },  /* 247: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -17,  22,  66,  17 },  {  -32,  53,  62,  16 },  {  -22,  52,  23,  51 },  {  -39,  84,   0,  23 } } },  /* 248: follow-up of APPEAR JUNBI 8 */
    { { {  -29,  22,  50,  17 },  {  -42,  63,  43,  19 },  {  -28,  47,  20,  23 },  {  -39,  66,   0,  23 } } },  /* 249: follow-up of APPEAR JUNBI 8 */
    { { {  -33,  22,  49,  17 },  {  -42,  55,  38,  21 },  {  -35,  58,  20,  23 },  {  -36,  70,   0,  23 } } },  /* 250: follow-up of APPEAR JUNBI 8 */
    { { {  -36,  22,  50,  17 },  {  -47,  54,  39,  22 },  {  -38,  53,  20,  23 },  {  -39,  67,   0,  30 } } },  /* 251: follow-up of APPEAR JUNBI 8 */
    { { {  -39,  22,  51,  17 },  {  -45,  53,  39,  26 },  {  -40,  55,  20,  23 },  {  -41,  65,   0,  33 } } },  /* 252: follow-up of APPEAR JUNBI 8 */
    { { {  -34,  22,  56,  17 },  {  -37,  48,  40,  26 },  {  -36,  54,  20,  25 },  {  -40,  64,   0,  32 } } },  /* 253: follow-up of APPEAR JUNBI 8 */
    { { {  -21,  22,  69,  17 },  {  -29,  49,  48,  27 },  {  -33,  58,  28,  27 },  {  -39,  64,   0,  28 } } },  /* 254: follow-up of APPEAR JUNBI 8 */
    { { {  -14,  22,  79,  17 },  {  -30,  53,  66,  16 },  {  -27,  49,  33,  32 },  {  -38,  66,   0,  39 } } },  /* 255: TUKAMIKAKARI A */
    { { {  -20,  22,  78,  17 },  {  -32,  53,  66,  16 },  {  -27,  49,  33,  32 },  {  -38,  66,   0,  39 } } },  /* 256: TUKAMIKAKARI A */
    { { {  -43,  22,  74,  17 },  {  -50,  54,  66,  16 },  {  -40,  51,  33,  36 },  {  -47,  66,   0,  41 } } },  /* 257: TUKAMIKAKARI A */
    { { {  -56,  22,  73,  17 },  {  -64,  60,  66,  16 },  {  -66,  69,  33,  41 },  {  -56,  72,   0,  34 } } },  /* 258: TUKAMIKAKARI A */
    { { {  -21,  22,  79,  17 },  {  -38,  53,  66,  16 },  {  -33,  49,  33,  32 },  {  -43,  66,   0,  39 } } },  /* 259: TUKAMIKAKARI A */
    { { {  -16,  22,  95,  17 },  {  -25,  47,  78,  22 },  {  -32,  51,  71,  20 },  {  -29,  49,  48,  30 } } },  /* 260: TUKAMI AIR A */
    { { {  -22,  22,  95,  17 },  {  -25,  47,  78,  22 },  {  -32,  51,  71,  20 },  {  -31,  51,  48,  30 } } },  /* 261: TUKAMI AIR A */
    { { {  -30,  22,  91,  17 },  {  -30,  49,  78,  19 },  {  -24,  49,  65,  26 },  {  -39,  54,  41,  24 } } },  /* 262: TUKAMI AIR A */
    { { {  -28,  22,  89,  17 },  {  -32,  57,  77,  19 },  {  -36,  69,  61,  28 },  {  -29,  65,  41,  20 } } },  /* 263: TUKAMI AIR A */
    { { {   -3,  22,  81,  17 },  {  -23,  57,  64,  19 },  {  -21,  48,  45,  19 },  {  -38,  66,   0,  45 } } },  /* 264: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +1 */
    { { {    8,  22,  87,  17 },  {   -3,  50,  68,  23 },  {  -23,  58,  45,  23 },  {    0,  32,   0,  45 } } },  /* 265: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +1 */
    { { {   31,  22,  79,  17 },  {   19,  44,  70,  19 },  {   14,  45,  53,  30 },  {  -10,  38,   0,  54 } } },  /* 266: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {   23,  22,  82,  17 },  {   10,  46,  70,  18 },  {   14,  35,  56,  25 },  {   -6,  34,   0,  54 } } },  /* 267: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {   10,  22,  87,  17 },  {   -1,  47,  68,  23 },  {  -13,  43,  54,  14 },  {    0,  32,   0,  54 } } },  /* 268: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {   -2,  22,  81,  17 },  {  -24,  59,  59,  26 },  {  -24,  51,  44,  15 },  {  -36,  66,   0,  44 } } },  /* 269: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {   34,  22,  81,  17 },  {   18,  53,  77,  16 },  {   14,  49,  53,  32 },  {  -10,  38,   0,  53 } } },  /* 270: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   35,  22,  80,  17 },  {   18,  53,  76,  16 },  {   14,  49,  53,  32 },  {  -10,  38,   0,  53 } } },  /* 271: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +5 */
    { { {   34,  22,  80,  17 },  {   18,  52,  76,  16 },  {   14,  49,  53,  32 },  {  -10,  38,   0,  53 } } },  /* 272: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +5 */
    { { {   35,  22,  82,  17 },  {   18,  53,  77,  16 },  {   14,  49,  53,  33 },  {  -10,  38,   0,  53 } } },  /* 273: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +2 */
    { { {   34,  22,  82,  17 },  {   18,  52,  77,  16 },  {   14,  49,  53,  33 },  {  -10,  38,   0,  53 } } },  /* 274: ATTACK 4 S: after KKKKK (plain script), ATTACK 4 M: after KKKKK (plain script), ATTACK 4 L: after KKKKK (plain script) +9 */
    { { {  -16,  22, 102,  17 },  {  -26,  54,  93,  22 },  {  -35,  55,  69,  26 },  {  -29,  46,  46,  23 } } },  /* 275: V JUMP K M B */
    { { {    8,  22,  83,  17 },  {  -20,  53,  66,  16 },  {  -23,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 276: UPPER L */
    { { {   16,  22,  82,  17 },  {  -17,  53,  66,  16 },  {  -24,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 277: UPPER L */
    { { {   20,  22,  81,  17 },  {  -15,  53,  66,  16 },  {  -25,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 278: UPPER L */
    { { {   22,  22,  80,  17 },  {  -14,  53,  66,  16 },  {  -26,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 279: not used by a script */
    { { {    8,  22,  77,  17 },  {  -16,  53,  65,  16 },  {  -18,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 280: FACE S, FACE M, FACE L +7 */
    { { {   20,  22,  75,  17 },  {  -10,  53,  64,  16 },  {  -15,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 281: FACE M, FACE L, FOOK OKU L +3 */
    { { {   28,  22,  73,  17 },  {   -6,  53,  63,  16 },  {  -13,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 282: FACE L, FOOK OKU L, FOOK OKU SP +2 */
    { { {   32,  22,  71,  17 },  {   -4,  53,  62,  16 },  {  -12,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 283: FACE L, FOOK OKU L, FOOK OKU SP +1 */
    { { {  -12,  22,  76,  17 },  {  -22,  53,  64,  16 },  {  -20,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 284: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -16,  22,  73,  17 },  {  -20,  53,  62,  16 },  {  -18,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 285: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    { { {  -20,  22,  70,  17 },  {  -18,  53,  60,  16 },  {  -16,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 286: NOUTEN L, BODY BROW L, BODY UPPER L */
    { { {  -24,  22,  67,  17 },  {  -16,  53,  58,  16 },  {  -14,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 287: BODY UPPER L */
    { { {  -13,  24,  41,  18 },  {  -23,  53,  33,  17 },  {  -20,  53,  19,  16 },  {  -34,  69,   0,  24 } } },  /* 288: TATAKI S, KAGAMI S, KAGAMI M +5 */
    { { {   -7,  24,  41,  18 },  {  -21,  53,  33,  17 },  {  -19,  53,  19,  16 },  {  -34,  69,   0,  24 } } },  /* 289: TATAKI S, KAGAMI M, KAGAMI L +2 */
    { { {   -1,  24,  41,  18 },  {  -19,  53,  33,  17 },  {  -18,  53,  19,  16 },  {  -34,  69,   0,  24 } } },  /* 290: KAGAMI L */
    { { {    5,  24,  41,  18 },  {  -17,  53,  33,  17 },  {  -17,  53,  19,  16 },  {  -34,  69,   0,  24 } } },  /* 291: KAGAMI L */
    { { {   -6,  22,  76,  17 },  {  -22,  50,  66,  16 },  {  -21,  45,  34,  32 },  {  -34,  65,   0,  43 } } },  /* 292: not used by a script */
    { { {  -14,  22,  65,  17 },  {  -18,  50,  57,  16 },  {  -15,  41,  36,  21 },  {  -34,  70,   0,  36 } } },  /* 293: not used by a script */
    { { {  -14,  22,  65,  17 },  {  -18,  43,  57,  16 },  {  -15,  41,  32,  25 },  {  -43,  87,   0,  32 } } },  /* 294: not used by a script */
    { { {  -15,  22,  67,  17 },  {  -18,  41,  59,  16 },  {  -17,  38,  37,  22 },  {  -43,  87,   0,  37 } } },  /* 295: follow-up of ATTACK 6 S, ATTACK 6 S: SA I 23623+P (plain script) */
    { { {  -17,  22,  89,  17 },  {  -25,  45,  79,  19 },  {  -35,  51,  33,  46 },  {  -43,  61,   0,  33 } } },  /* 296: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {   -3,  22,  93,  17 },  {  -22,  49,  79,  19 },  {  -35,  46,  33,  54 },  {  -41,  55,   0,  33 } } },  /* 297: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {   17,  22,  86,  17 },  {  -22,  48,  77,  27 },  {  -36,  39,  33,  48 },  {  -37,  48,   0,  33 } } },  /* 298: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {   11,  22,  83,  17 },  {  -16,  44,  72,  26 },  {  -28,  34,  38,  35 },  {  -37,  43,   0,  58 } } },  /* 299: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -23,  22,  77,  17 },  {  -31,  48,  67,  20 },  {  -24,  36,  53,  16 },  {  -46,  59,   0,  58 } } },  /* 300: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -23,  22,  73,  17 },  {  -30,  48,  64,  17 },  {  -23,  36,  53,  14 },  {  -48,  60,   0,  58 } } },  /* 301: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -18,  22,  68,  17 },  {  -22,  52,  58,  19 },  {  -17,  32,  46,  14 },  {  -52,  63,   0,  52 } } },  /* 302: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -20,  22,  68,  17 },  {  -25,  42,  58,  20 },  {  -22,  34,  40,  18 },  {  -50,  73,   0,  40 } } },  /* 303: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -29,  22,  65,  17 },  {  -37,  49,  49,  24 },  {  -20,  38,  35,  23 },  {  -42,  78,   0,  35 } } },  /* 304: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -25,  22,  66,  17 },  {  -33,  49,  49,  23 },  {  -26,  51,  35,  17 },  {  -39,  75,   0,  35 } } },  /* 305: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -25,  22,  66,  17 },  {  -33,  49,  49,  23 },  {  -26,  47,  35,  17 },  {  -42,  74,   0,  35 } } },  /* 306: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -22,  22,  68,  17 },  {  -31,  49,  53,  23 },  {  -27,  48,  38,  15 },  {  -42,  71,   0,  38 } } },  /* 307: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -24,  22,  71,  17 },  {  -35,  47,  55,  24 },  {  -31,  45,  40,  15 },  {  -42,  71,   0,  40 } } },  /* 308: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -24,  22,  76,  17 },  {  -36,  47,  63,  21 },  {  -37,  50,  34,  29 },  {  -51,  68,   0,  34 } } },  /* 309: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {    5,  22,  83,  17 },  {   -1,  37,  54,  35 },  {  -38,  37,  51,  40 },  {  -67,  29,  53,  30 } } },  /* 310: KAGAMI K C */
    { { {  -22,  22,  75,  17 },  {  -24,  50,  70,  20 },  {  -25,  55,  48,  22 },  {  -27,  51,  35,  13 } } },  /* 311: AIR NORMAL, UPPER, BODY SLAM +13 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -32,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 312: no name */
    { { {    6,  22,  82,  17 },  {  -16,  47,  72,  23 },  {  -42,  57,  38,  42 },  {  -12,  44,   0,  50 } } },  /* 313: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   16,  22,  80,  17 },  {  -12,  41,  72,  23 },  {  -31,  47,  37,  41 },  {  -21,  50,   0,  43 } } },  /* 314: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   37,  22,  77,  17 },  {    5,  53,  74,  16 },  {  -19,  67,  48,  31 },  {  -12,  38,   0,  48 } } },  /* 315: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   35,  22,  80,  17 },  {   18,  47,  76,  16 },  {    4,  49,  56,  32 },  {  -10,  38,   0,  56 } } },  /* 316: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   34,  22,  80,  17 },  {   18,  45,  76,  16 },  {    4,  48,  53,  32 },  {  -10,  38,   0,  53 } } },  /* 317: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   34,  22,  82,  17 },  {   18,  45,  77,  16 },  {    4,  48,  55,  32 },  {  -10,  38,   0,  55 } } },  /* 318: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   35,  22,  82,  17 },  {   18,  47,  77,  16 },  {    4,  49,  58,  32 },  {  -10,  38,   0,  58 } } },  /* 319: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   32,  22,  81,  17 },  {   18,  43,  75,  16 },  {    2,  53,  55,  32 },  {   -9,  38,   0,  55 } } },  /* 320: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   24,  22,  84,  17 },  {   11,  45,  74,  16 },  {   -4,  53,  52,  32 },  {   -2,  38,   0,  52 } } },  /* 321: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   -5,  22,  81,  17 },  {  -15,  48,  69,  16 },  {  -26,  54,  33,  36 },  {  -38,  66,   0,  33 } } },  /* 322: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   -1,  22,  80,  17 },  {  -16,  51,  69,  16 },  {  -19,  51,  33,  36 },  {  -24,  60,   0,  33 } } },  /* 323: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   16,  22,  66,  17 },  {  -11,  54,  61,  16 },  {  -18,  49,  33,  32 },  {  -26,  52,   0,  33 } } },  /* 324: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   22,  22,  48,  17 },  {    3,  27,  40,  39 },  {  -26,  46,  33,  41 },  {  -26,  42,   0,  33 } } },  /* 325: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   48,  22,  40,  17 },  {   34,  27,  29,  36 },  {   -8,  54,  33,  40 },  {   -7,  36,   0,  33 } } },  /* 326: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   52,  22,  46,  17 },  {   36,  27,  32,  37 },  {   -6,  54,  35,  40 },  {   -5,  36,   0,  35 } } },  /* 327: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   40,  22,  74,  17 },  {   30,  27,  54,  35 },  {   -6,  39,  46,  41 },  {   -5,  36,   0,  46 } } },  /* 328: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -42,  22,  44,  17 },  {  -38,  27,  38,  40 },  {  -15,  35,  35,  41 },  {   11,  31,  25,  55 } } },  /* 329: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    { { {  -28,  22,  32,  17 },  {  -39,  61,  42,  23 },  {  -24,  54,  62,  18 },  {  -14,  49,  74,  20 } } },  /* 330: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) */
    { { {  -14,  22,  27,  17 },  {  -29,  52,  41,  23 },  {  -26,  51,  62,  18 },  {  -14,  35,  80,  18 } } },  /* 331: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {   -8,  22,  27,  17 },  {  -31,  62,  39,  25 },  {  -30,  44,  64,  16 },  {  -35,  25,  80,  17 } } },  /* 332: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {    8,  22,  46,  17 },  {  -26,  49,  29,  26 },  {  -16,  50,  55,  29 },  {  -44,  29,  53,  18 } } },  /* 333: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   12,  22,  53,  17 },  {    5,  25,  31,  44 },  {  -17,  22,  35,  43 },  {  -37,  20,  31,  31 } } },  /* 334: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   11,  22,  51,  17 },  {    8,  27,  33,  44 },  {  -14,  22,  27,  45 },  {  -30,  48,  62,  23 } } },  /* 335: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -32,  22,  13,  17 },  {  -18,  27,  12,  44 },  {  -26,  51,   0,  46 },  {    9,  41,   0,  20 } } },  /* 336: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -31,  22,  19,  17 },  {  -18,  27,  12,  46 },  {  -26,  51,   0,  48 },  {    9,  41,   0,  20 } } },  /* 337: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {   12,  26,  42,  17 },  {   -9,  45,  24,  35 },  {  -33,  42,  20,  37 },  {   -3,  33,   0,  24 } } },  /* 338: KAGAMI K A */
    { { {   -3,  22,  95,  17 },  {  -13,  55,  84,  21 },  {  -20,  53,  51,  33 },  {  -38,  25,  61,  39 } } },  /* 339: F JUMP K S A, F JUMP K M A */
    { { {  -16,  22,  95,  17 },  {  -34,  65,  83,  22 },  {  -55,  71,  68,  19 },  {  -22,  36,  47,  21 } } },  /* 340: F JUMP K M A */
    { { {  -19,  22,  98,  17 },  {  -34,  65,  83,  24 },  {  -55,  67,  66,  21 },  {  -22,  36,  47,  21 } } },  /* 341: F JUMP K M A */
    { { {  -19,  22, 101,  17 },  {  -28,  49,  85,  24 },  {  -42,  59,  66,  20 },  {  -32,  42,  45,  21 } } },  /* 342: F JUMP K M A */
    { { {  -12,  22,  87,  17 },  {  -26,  53,  76,  16 },  {  -24,  51,  44,  32 },  {  -27,  58,   0,  44 } } },  /* 343: M KICK C */
    { { {  -12,  22,  88,  17 },  {  -26,  53,  77,  16 },  {  -24,  51,  45,  32 },  {  -22,  47,   0,  45 } } },  /* 344: M KICK C */
    { { {  -15,  22,  86,  17 },  {  -32,  55,  74,  16 },  {  -36,  50,  45,  33 },  {  -33,  45,   0,  45 } } },  /* 345: M KICK C */
    { { {   -6,  22,  84,  17 },  {  -24,  53,  75,  16 },  {  -22,  45,  45,  33 },  {  -36,  50,   0,  68 } } },  /* 346: M KICK C */
    { { {   -2,  22,  78,  17 },  {  -13,  51,  69,  20 },  {  -20,  55,  48,  22 },  {  -27,  51,  35,  13 } } },  /* 347: ASIBARAI SIRI */
    { { {   17,  22,  84,  17 },  {   -1,  54,  71,  20 },  {  -21,  59,  57,  22 },  {  -35,  60,  42,  30 } } },  /* 348: ASIBARAI SIRI */
    { { {    6,  22,  70,  17 },  {   -8,  51,  59,  20 },  {  -22,  60,  32,  31 },  {  -40,  35,  42,  33 } } },  /* 349: ASIBARAI SIRI, UP P GUARD P M */
    { { {    2,  22,  60,  17 },  {   -8,  45,  46,  20 },  {  -30,  57,  23,  25 },  {  -39,  31,  41,  29 } } },  /* 350: ASIBARAI SIRI */
    { { {  -18,  22,  81,  17 },  {  -35,  48,  70,  20 },  {  -33,  48,  48,  22 },  {  -31,  39,  33,  15 } } },  /* 351: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -21,  22,  81,  17 },  {  -38,  48,  70,  20 },  {  -36,  44,  48,  22 },  {  -41,  39,  33,  15 } } },  /* 352: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -60,  22,  54,  17 },  {  -49,  29,  41,  43 },  {  -27,  23,  32,  41 },  {  -14,  25,  25,  42 } } },  /* 353: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -16,  22,  29,  17 },  {  -37,  31,  22,  36 },  {  -46,  48,  40,  34 },  {   -3,  30,  43,  25 } } },  /* 354: ASIB TUNNOMERI, HUMI ASIB */
    { { {   -1,  22,  79,  17 },  {   -6,  45,  68,  20 },  {  -19,  53,  48,  22 },  {  -27,  54,  35,  13 } } },  /* 355: NOKEZORI, FACE, HANEKAERI HARA */
    { { {   10,  22,  77,  17 },  {  -21,  57,  66,  21 },  {  -39,  48,  52,  22 },  {  -52,  51,  38,  21 } } },  /* 356: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   16,  22,  67,  17 },  {   -8,  44,  58,  24 },  {  -36,  41,  53,  25 },  {  -52,  45,  43,  25 } } },  /* 357: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   14,  22,  46,  17 },  {  -10,  44,  54,  24 },  {  -37,  41,  54,  25 },  {  -55,  45,  48,  25 } } },  /* 358: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    9,  22,  38,  17 },  {  -10,  43,  47,  22 },  {  -29,  33,  48,  29 },  {  -47,  25,  42,  34 } } },  /* 359: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    7,  22,  23,  17 },  {  -11,  44,  35,  22 },  {  -14,  29,  42,  31 },  {  -36,  22,  47,  31 } } },  /* 360: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {    2,  22,  10,  17 },  {  -12,  43,  22,  22 },  {  -21,  44,  35,  22 },  {  -34,  45,  48,  21 } } },  /* 361: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   -2,  22,   1,  17 },  {  -14,  42,  13,  21 },  {  -21,  40,  28,  22 },  {  -30,  40,  42,  22 } } },  /* 362: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {  -10,  22,  -2,  17 },  {  -20,  39,  10,  21 },  {  -25,  42,  25,  19 },  {  -31,  44,  40,  22 } } },  /* 363: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {  -30,  22,  70,  17 },  {  -28,  50,  64,  20 },  {  -23,  49,  46,  22 },  {  -31,  52,  32,  16 } } },  /* 364: KUNOJI, KUNOJI NOKE */
    { { {  -25,  22,  61,  17 },  {  -21,  50,  56,  20 },  {  -16,  51,  41,  22 },  {  -27,  52,  28,  16 } } },  /* 365: KUNOJI, KUNOJI NOKE */
    { { {  -14,  22,  57,  17 },  {   -4,  52,  55,  20 },  {   -4,  48,  41,  22 },  {  -18,  52,  27,  18 } } },  /* 366: KUNOJI, KUNOJI NOKE */
    { { {  -14,  22,  50,  17 },  {   -4,  51,  46,  20 },  {  -10,  55,  31,  22 },  {  -27,  58,  23,  16 } } },  /* 367: KUNOJI, KUNOJI NOKE */
    { { {    7,  22,  45,  17 },  {   -1,  36,  25,  33 },  {  -15,  34,  16,  34 },  {  -38,  23,  13,  32 } } },  /* 368: KUNOJI */
    { { {   -3,  22,  79,  17 },  {  -21,  46,  70,  15 },  {  -20,  42,  48,  22 },  {  -26,  50,  33,  15 } } },  /* 369: KIRIMOMI */
    { { {   12,  22,  79,  17 },  {   -7,  46,  68,  20 },  {  -18,  42,  53,  23 },  {  -26,  40,  33,  23 } } },  /* 370: KIRIMOMI */
    { { {   24,  22,  74,  17 },  {    1,  46,  59,  22 },  {  -11,  43,  45,  26 },  {  -25,  41,  31,  25 } } },  /* 371: KIRIMOMI */
    { { {   32,  22,  61,  17 },  {    9,  36,  52,  22 },  {   -7,  36,  39,  25 },  {  -25,  38,  30,  25 } } },  /* 372: KIRIMOMI */
    { { {   32,  22,  43,  17 },  {    9,  31,  33,  27 },  {   -6,  33,  28,  25 },  {  -27,  32,  18,  30 } } },  /* 373: KIRIMOMI */
    { { {   32,  22,  26,  17 },  {    9,  31,  18,  30 },  {   -6,  26,  15,  31 },  {  -27,  32,  11,  30 } } },  /* 374: KIRIMOMI */
    { { {   32,  22,  19,  17 },  {    9,  31,   5,  27 },  {   -6,  26,  -3,  30 },  {  -29,  31,  -1,  30 } } },  /* 375: KIRIMOMI */
    { { {  -11,  22,  82,  17 },  {  -27,  41,  70,  20 },  {  -31,  43,  48,  22 },  {  -33,  43,  35,  13 } } },  /* 376: UPPER, TATUMAKIZANKU */
    { { {    0,  22,  79,  17 },  {  -25,  41,  69,  20 },  {  -36,  39,  48,  22 },  {  -35,  36,  35,  13 } } },  /* 377: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    { { {    6,  22,  77,  17 },  {  -21,  44,  67,  21 },  {  -35,  35,  51,  22 },  {  -47,  39,  36,  27 } } },  /* 378: UPPER, BODY UPPER SP, TATUMAKIZANKU */
    { { {  -15,  22,  77,  17 },  {  -17,  46,  70,  20 },  {  -15,  48,  48,  22 },  {  -19,  50,  35,  13 } } },  /* 379: BODY UPPER */
    { { {  -27,  22,  62,  17 },  {  -22,  45,  66,  21 },  {  -15,  44,  48,  24 },  {  -21,  42,  35,  15 } } },  /* 380: BODY UPPER */
    { { {  -34,  22,  66,  17 },  {  -26,  40,  66,  21 },  {  -23,  43,  48,  24 },  {  -34,  45,  35,  19 } } },  /* 381: BODY UPPER */
    { { {  -20,  22,  83,  17 },  {  -26,  40,  68,  21 },  {  -31,  39,  48,  24 },  {  -42,  40,  36,  24 } } },  /* 382: BODY UPPER */
    { { {   -9,  22,  74,  17 },  {  -16,  46,  61,  19 },  {  -13,  47,  46,  17 },  {  -21,  53,  35,  13 } } },  /* 383: HARAYARARE */
    { { {  -43,  22,  53,  17 },  {  -31,  45,  47,  25 },  {  -27,  45,  35,  21 },  {  -38,  48,  23,  16 } } },  /* 384: TTKI V. AIR */
    { { {  -52,  22,  28,  17 },  {  -48,  45,  31,  25 },  {  -36,  45,  25,  21 },  {  -48,  48,  13,  16 } } },  /* 385: TTKI V. AIR */
    { { {  -51,  22,  14,  17 },  {  -39,  45,  13,  25 },  {  -36,  45,   0,  21 },  {  -59,  46,   0,  18 } } },  /* 386: TTKI V. AIR */
    { { {    8,  22,  78,  17 },  {  -10,  50,  67,  20 },  {  -17,  50,  48,  22 },  {  -22,  49,  35,  13 } } },  /* 387: DENKI */
    { { {  -22,  22,  69,  17 },  {  -25,  50,  64,  16 },  {  -21,  49,  33,  32 },  {  -30,  54,  16,  21 } } },  /* 388: TOUKETSU A */
    { { {   13,  22,  86,  17 },  {    6,  48,  73,  19 },  {   -2,  45,  47,  30 },  {    0,  37,   0,  54 } } },  /* 389: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {   -9,  22,  99,  17 },  {  -29,  64,  85,  25 },  {  -30,  76,  65,  28 },  {  -22,  64,  55,  10 } } },  /* 390: F JUMP K L A */
    { { {  -18,  22,  79,  17 },  {  -27,  53,  66,  16 },  {  -25,  49,  33,  32 },  {  -38,  66,   0,  32 } } },  /* 391: FRONT WALK */
    { { {   -8,  22,  79,  17 },  {  -20,  53,  66,  16 },  {  -19,  49,  33,  32 },  {  -22,  66,   0,  32 } } },  /* 392: HURIMUKI, FRONT WALK, BACK WALK */
    { { {  -18,  22,  79,  17 },  {  -32,  53,  66,  16 },  {  -29,  49,  33,  32 },  {  -32,  58,   0,  32 } } },  /* 393: FRONT WALK, BACK WALK */
    { { {  -20,  22,  79,  17 },  {  -34,  53,  66,  16 },  {  -29,  49,  33,  32 },  {  -42,  66,   0,  32 } } },  /* 394: HURIMUKI, BACK WALK */
    { { {   -8,  22,  79,  17 },  {  -21,  53,  66,  16 },  {  -19,  49,  33,  32 },  {  -28,  66,   0,  32 } } },  /* 395: FRONT WALK */
    { { {   -6,  22,  67,  17 },  {  -24,  53,  60,  16 },  {  -22,  49,  34,  24 },  {  -38,  66,   0,  32 } } },  /* 396: PIYO */
    { { {  -32,  22,  65,  17 },  {  -30,  53,  64,  16 },  {  -28,  49,  38,  24 },  {  -44,  72,   0,  36 } } },  /* 397: PIYO */
    { { {  -19,  22,  23,  17 },  {  -14,  50,  35,  23 },  {  -29,  77,  24,  19 },  {    0,   0,   0,   0 } } },  /* 398: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    { { {  -40,  22,  24,  17 },  {  -34,  35,  23,  33 },  {   -5,  36,  24,  40 },  {    0,   0,   0,   0 } } },  /* 399: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    { { {  -22,  22,  33,  17 },  {  -11,  35,  30,  29 },  {    0,  37,  27,  44 },  {    0,   0,   0,   0 } } },  /* 400: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
    { { {   -9,  22,  30,  17 },  {  -24,  54,  34,  21 },  {  -14,  43,  55,  25 },  {    0,   0,   0,   0 } } },  /* 401: ATTACK 1 SP: EX [2](789)+KK (routine Att_SENPUUKYAKU) */
};

const HAND_BOX chun_hand_box[216] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -54,  34,  67,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -52,  32,  67,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { {  -49,  29,  67,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A */
    { { {  -91,  41,  75,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -87,  37,  75,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B */
    { { {  -48,  24,  87,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH C */
    { { {  -58,  28,  75,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH C */
    { { {   11,  29,  84,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH C */
    { { {   11,  29,  84,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH C */
    { { {  -48,  31,  72,  27 },  {  -58,  10,  79,  15 },  {   31,  22,  93,  10 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH C */
    { { {   30,  22,  95,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH C */
    { { {   10,  30,  93,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH C */
    { { {  -35,  23,  68,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH C */
    { { {  -71,  35,  64,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: M PUNCH A, no name */
    { { {  -72,  10,  61,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: M PUNCH A, no name */
    { { {  -57,  42,  52,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH C */
    { { {  -60,  38,  50,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH C */
    { { {  -47,  18,  53,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: L PUNCH C */
    { { {  -32,  12,  58,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: L PUNCH C */
    { { {   13,  17,  60,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: L PUNCH A */
    { { {   13,  17,  55,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L PUNCH A */
    { { {   14,  23,  57,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH A */
    { { {  -84,  33,  58,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: L PUNCH A */
    { { {  -89,  40,  56,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: L PUNCH A */
    { { {  -81,  32,  56,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: L PUNCH A */
    { { {  -72,  23,  51,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: L PUNCH A */
    { { {  -66,  14,  51,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: L PUNCH A */
    { { {  -58,  11,  49,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: L PUNCH A */
    { { {  -83,  73,  51,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: M KICK C */
    { { {  -80,  71,  48,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: M KICK C */
    { { {  -45,  35,  48,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: M KICK C */
    { { {  -53,  18,  60,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: M KICK A */
    { { {  -52,  24,  65,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: M KICK A */
    { { {  -48,  24,  69,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: M KICK A */
    { { {  -74,  46,  69,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: M KICK A, follow-up of M KICK A */
    { { {  -49,  41,  70,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: M KICK A */
    { { {  -45,  34,  72,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: M KICK A */
    { { {  -45,  34,  72,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 38: M KICK A */
    { { {  -51,  28,  74,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 39: L KICK B */
    { { {  -41,  25,  65,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK B */
    { { {  -92,  59,  52,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: L KICK B */
    { { {  -48,  12,  76,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: L KICK B */
    { { {  -54,  18,  76,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: L KICK B */
    { { {  -65,  45,  87,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: V JUMP P S A, V JUMP P M A */
    { { {  -70,  50,  87,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: V JUMP P S A */
    { { {  -45,  20,  59,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: S KICK A */
    { { {  -44,  16,  58,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: S KICK A */
    { { {  -43,  19,  28,  31 },  {  -64,  31,  29,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: S KICK A */
    { { {  -39,  15,  25,  41 },  {  -60,  27,  26,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: S KICK A */
    { { {  -42,  18,  15,  11 },  {  -36,  12,  55,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: S KICK A, no name */
    { { {  -35,  12,  62,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: S KICK A, no name */
    { { {  -32,  18,  66,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: S KICK A, no name */
    { { { -101,  28,  65,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: KAGAMI K C */
    { { {  -90,  25,  67,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: KAGAMI K C */
    { { {  -93,  33,  82,  17 },  {  -67,  56,  78,  15 },  {  -45,  34,  70,   9 },  {    0,   0,   0,   0 } } },  /* 55: M KICK B, no name */
    { { {  -86,  31,  87,  18 },  {  -65,  54,  79,  16 },  {  -45,  34,  70,   9 },  {    0,   0,   0,   0 } } },  /* 56: M KICK B, no name */
    { { {   10,  36, 102,  17 },  {   -7,  22,  90,  25 },  {  -25,  26,  88,  23 },  {    0,   0,   0,   0 } } },  /* 57: M KICK B, no name */
    { { {   24,  31,  96,  14 },  {   11,  18,  87,  15 },  {   -1,  18,  86,   8 },  {    0,   0,   0,   0 } } },  /* 58: M KICK B, no name */
    { { {   35,  31,  88,  16 },  {   17,  18,  87,  13 },  {    4,  16,  83,   8 },  {    0,   0,   0,   0 } } },  /* 59: M KICK B, no name */
    { { {   41,  13,  65,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: M KICK B, no name */
    { { {    3,  24,  56,   6 },  {   19,  22,  50,   7 },  {   37,  16,  44,   9 },  {    0,   0,   0,   0 } } },  /* 61: M KICK B, no name */
    { { {  -49,  23, 116,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: V JUMP K S A, V JUMP K M A */
    { { {  -50,  24, 116,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: V JUMP K M A */
    { { {  -52,  26, 116,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: V JUMP K M A */
    { { {  -55,  15, 115,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: V JUMP K S A, V JUMP K M A */
    { { {  -56,  10, 105,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: V JUMP K S A, V JUMP K M A */
    { { {    0,  19, 105,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: F JUMP K L A */
    { { {   -6,  18, 119,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: F JUMP K L A */
    { { {  -37,  34, 105,  16 },  {  -30,  28, 121,   8 },  {  -20,  20, 129,   5 },  {    0,   0,   0,   0 } } },  /* 69: F JUMP K L A, S V JP S P A */
    { { {  -38,  35,  91,  20 },  {  -46,  37, 102,  18 },  {  -42,  30, 121,  12 },  {    0,   0,   0,   0 } } },  /* 70: F JUMP K L A */
    { { {  -70,  26,  23,  26 },  {  -59,  24,  34,  22 },  {  -48,  18,  50,  14 },  {  -41,  21,  55,  17 } } },  /* 71: F JUMP K L A */
    { { {  -46,   9,  70,  15 },  {   28,  13, 103,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: F JUMP K L A */
    { { {   18,  16,  59,   8 },  {   16,  12, 107,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: F JUMP K L A */
    { { {   -3,  16,  52,  10 },  {  -11,  15, 107,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: F JUMP K L A */
    { { {  -30,  20,  46,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: F JUMP K L A */
    { { {  -27,  19,  45,  15 },  {  -55,  20,  84,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: F JUMP K L A */
    { { {  -20,  16,  44,   9 },  {  -53,  32,  71,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: F JUMP K L A */
    { { {  -13,  14,  43,  15 },  {  -36,  12,  64,  12 },  {  -44,  13,  60,  11 },  {  -52,  12,  56,   9 } } },  /* 78: F JUMP K L A */
    { { {  -58,  38,  86,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: V JUMP P M A */
    { { {  -32,  33, 119,   7 },  {   -9,  12, 111,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: V JUMP P L A, F JUMP P L B */
    { { {  -64,  25,  81,  21 },  {  -50,  17,  98,  15 },  {  -33,   9,  97,  10 },  {    0,   0,   0,   0 } } },  /* 81: V JUMP P L A, F JUMP P L B */
    { { {  -77,  22,  60,  17 },  {  -63,  15,  70,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: V JUMP K L A */
    { { {  -93,  33,  56,  22 },  {  -60,  29,  60,  17 },  {  -23,  38,  67,  13 },  {   17,  20, 106,  10 } } },  /* 83: V JUMP K L A */
    { { {  -97,  37,  56,  23 },  {  -60,  29,  59,  18 },  {  -23,  38,  64,  15 },  {   17,  20, 106,  10 } } },  /* 84: V JUMP K L A */
    { { {  -95,  35,  55,  19 },  {  -60,  29,  59,  16 },  {  -23,  34,  64,   9 },  {   17,  20, 106,  10 } } },  /* 85: V JUMP K L A */
    { { {  -68,  18,  44,  15 },  {  -57,  19,  51,  16 },  {  -46,  18,  55,  19 },  {  -46,  79, 109,   9 } } },  /* 86: V JUMP K L A */
    { { {  -36,  14, 112,  15 },  {   12,  11, 109,   9 },  {   20,   9, 116,  11 },  {    0,   0,   0,   0 } } },  /* 87: V JUMP K L A */
    { { { -111,  32,  65,  20 },  {  -79,  24,  67,  21 },  {   28,  10, 102,  11 },  {    0,   0,   0,   0 } } },  /* 88: F JUMP K S A */
    { { { -103,  24,  72,  11 },  {  -79,  24,  70,  18 },  {   28,  10, 102,  11 },  {    0,   0,   0,   0 } } },  /* 89: F JUMP K M A */
    { { {  -70,  25,  49,  21 },  {  -52,  13,  65,  11 },  {   13,  24,  56,  15 },  {   34,  10,  52,  12 } } },  /* 90: F JUMP P S A */
    { { {  -66,  23,  53,  15 },  {  -57,  18,  62,  14 },  {   13,  24,  56,  15 },  {   34,  10,  52,  12 } } },  /* 91: F JUMP P M A */
    { { {  -55,  10,  46,  16 },  {   30,   9,  45,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: F JUMP P L A */
    { { {   -7,  25,  95,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: F JUMP P L A */
    { { {  -95,  22,  50,  25 },  {  -87,  20,  61,  21 },  {  -75,  22,  70,  18 },  {  -24,  26,  88,  10 } } },  /* 94: F JUMP P L A */
    { { {  -67,  18,  69,  11 },  {  -57,  12,  72,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 95: F JUMP P L A */
    { { {  -59,  18,  75,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: F JUMP P L A */
    { { {  -58,  16,  58,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: F JUMP P L A */
    { { {  -96,  54,  70,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: F JUMP P L A */
    { { {  -44,  37,  49,  26 },  {    8,  19,  84,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: L KICK A */
    { { {  -44,  37,  49,  26 },  {    5,  18,  84,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: L KICK A */
    { { {  -44,  34,  49,  29 },  {    4,  17,  84,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 101: L KICK A */
    { { {  -47,  21,  27,  12 },  {  -37,  12,  38,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: M KICK A */
    { { {  -40,  14,  27,  12 },  {  -32,   7,  38,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: M KICK A */
    { { {  -70,  41,  71,  19 },  {   23,   8,  64,  12 },  {   32,   6,  62,  10 },  {    0,   0,   0,   0 } } },  /* 104: follow-up of M KICK A */
    { { {  -57,  28,  71,  17 },  {   23,   8,  64,  12 },  {   32,   6,  62,  10 },  {    0,   0,   0,   0 } } },  /* 105: follow-up of M KICK A */
    { { {  -75,  46,  71,  19 },  {   23,   8,  64,  12 },  {   32,   6,  62,  10 },  {    0,   0,   0,   0 } } },  /* 106: follow-up of M KICK A */
    { { {  -73,  41,  28,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: KAGAMI P A */
    { { { -104,  70,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: KAGAMI P A */
    { { {  -98,  64,   0,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 109: KAGAMI P A */
    { { {  -10,  24,  35,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: KAGAMI P A */
    { { {  -57,  22,  18,  32 },  {   18,  23,  41,  15 },  {   35,  16,  46,  12 },  {    0,   0,   0,   0 } } },  /* 111: KAGAMI P A */
    { { {  -53,  21,  18,  21 },  {   18,  23,  41,  15 },  {   37,  16,  47,  12 },  {    0,   0,   0,   0 } } },  /* 112: KAGAMI P A */
    { { {   18,  23,  41,  11 },  {   35,  15,  43,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: KAGAMI P A */
    { { {  -42,  25,  25,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: KAGAMI P A, follow-up of SP APPEAR 7, follow-up of SP APPEAR 8 +3 */
    { { {  -85,  33,   0,   8 },  {  -73,  25,   0,  11 },  {  -60,  24,   0,  14 },  {    0,   0,   0,   0 } } },  /* 115: KAGAMI K A */
    { { {  -85,  33,   0,  10 },  {  -73,  25,   0,  13 },  {  -60,  24,   0,  16 },  {    0,   0,   0,   0 } } },  /* 116: KAGAMI K A */
    { { {  -53,  33,   0,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: KAGAMI K A */
    { { {  -28,  15,  49,  13 },  {   22,  17,   0,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: KAGAMI K A */
    { { { -106,  72,   0,  13 },  {  -82,  48,  10,   8 },  {  -50,  16,  14,   9 },  {    0,   0,   0,   0 } } },  /* 119: KAGAMI K A */
    { { {  -86,  49,   0,  12 },  {  -72,  36,  10,   9 },  {  -53,  17,  17,   7 },  {    0,   0,   0,   0 } } },  /* 120: KAGAMI K A */
    { { {  -45,  16,  29,  14 },  {   32,  29,   0,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: KAGAMI K A */
    { { {  -39,  19,  30,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 122: KAGAMI K A */
    { { {  -82,  47,  33,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  15,  71,  12 } } },  /* 123: KAGAMI K A */
    { { {  -82,  47,  33,  16 },  {    0,   0,   0,   0 },  {  -71,  26,  60,  17 },  {  -31,  15,  71,  12 } } },  /* 124: KAGAMI K A */
    { { {  -37,  29,  43,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A */
    { { {  -43,  21,  28,  13 },  {  -48,  16,  34,  12 },  {  -52,   9,  40,  10 },  {    0,   0,   0,   0 } } },  /* 126: KAGAMI K A */
    { { {  -76,  38,  40,  20 },  {  -71,  30,  60,  15 },  {   13,  24,  56,  15 },  {   34,  10,  52,  12 } } },  /* 127: ATTACK 9 S: not started by a command */
    { { {  -11,  15,  71,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -18,  16,  65,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -18,  16,  64,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   22,  14,  55,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   36,  25,  22,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {   30,  24,  38,  16 },  {   54,  15,  37,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 133: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -28,  17,  23,  13 },  {   37,  23,  47,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -37,  16,  31,  11 },  {  -31,  17,  68,  16 },  {  -47,  21,  77,  13 },  {   29,  17,  48,  12 } } },  /* 135: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -73,  37,  73,  16 },  {   48,  21,  73,  15 },  {   22,  21,  51,  13 },  {    0,   0,   0,   0 } } },  /* 136: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -67,  31,  73,  16 },  {   48,  17,  73,  15 },  {   22,  16,  47,  22 },  {    0,   0,   0,   0 } } },  /* 137: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -43,  15,  78,  13 },  {  -24,  12,  50,  19 },  {   35,  10,  75,  14 },  {    0,   0,   0,   0 } } },  /* 138: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -73,  37,  73,  16 },  {   48,  21,  73,  15 },  {  -33,  21,  46,  23 },  {    0,   0,   0,   0 } } },  /* 139: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -67,  31,  74,  15 },  {   48,  17,  74,  14 },  {  -30,  18,  46,  23 },  {    0,   0,   0,   0 } } },  /* 140: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -46,  15,  78,  11 },  {   35,  10,  73,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 141: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) +1 */
    { { {  -48,  23,  88,  13 },  {   26,  14,  31,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 142: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {   30,  25,  82,  14 },  {   55,  18,  87,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 143: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -37,  16,  68,  17 },  {   25,  16,  68,  31 },  {   41,  24,  69,  11 },  {    0,   0,   0,   0 } } },  /* 144: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -32,  15,  70,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { { {  -54,  12,  40,  10 },  {    9,  11,  54,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: follow-up of APPEAR JUNBI 8 */
    { { {    3,  12,  56,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 147: follow-up of APPEAR JUNBI 8 */
    { { {  -50,  24,  63,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 148: TUKAMIKAKARI A */
    { { {  -83,  33,  63,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 149: TUKAMIKAKARI A */
    { { {  -54,  22,  78,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 150: TUKAMI AIR A */
    { { {  -63,  33,  77,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 151: TUKAMI AIR A */
    { { {  -19,  16,  69,  14 },  {  -21,  21,  24,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 152: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +1 */
    { { {  -24,  38,  54,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 153: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {  -22,  32,  46,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 154: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {  -22,  22,  29,  56 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 155: ATTACK 2 S: KKKKK [EX KK] (plain script), ATTACK 2 M: KKKKK [EX KK] (plain script), ATTACK 2 L: KKKKK [EX KK] (plain script) +2 */
    { { {  -20,  38,  53,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -14,  32,  53,  42 },  {  -45,  31,  80,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 157: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8 */
    { { {  -20,  38,  53,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 158: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +9 */
    { { {  -14,  32,  53,  35 },  {  -47,  33,  60,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 159: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8 */
    { { {  -20,  38,  53,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 160: not used by a script */
    { { {  -14,  32,  53,  36 },  {  -27,  31,  83,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 161: not used by a script */
    { { {  -20,  38,  53,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 162: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +9 */
    { { {  -14,  32,  53,  38 },  {  -45,  31,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 163: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8 */
    { { {  -41,  17, 108,  12 },  {   25,  19, 106,  14 },  {  -25,  40,   5,  44 },  {    0,   0,   0,   0 } } },  /* 164: V JUMP K M B */
    { { {  -46,  31,  52,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 165: not used by a script */
    { { {  -44,  27,  53,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 166: follow-up of ATTACK 6 S, ATTACK 6 S: SA I 23623+P (plain script) */
    { { {  -41,  12,  82,  14 },  {   17,  15,  75,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 167: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -41,  12,  78,  13 },  {   18,  13,  73,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 168: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -36,  14,  72,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 169: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -31,  11,  78,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 170: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -69,  32,  51,  17 },  {    3,  15,  71,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 171: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -63,  30,  52,  15 },  {    5,  16,  70,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 172: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -61,  28,  53,  13 },  {    6,  14,  68,   6 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 173: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -49,  18,  59,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 174: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
    { { {  -20,  38,  53,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 175: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +5 */
    { { {  -14,  32,  53,  33 },  {  -47,  33,  46,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 176: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8 */
    { { {  -20,  38,  53,  42 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 177: ATTACK 3 S: after KKKKK (plain script), ATTACK 3 M: after KKKKK (plain script), ATTACK 3 L: after KKKKK (plain script) +8 */
    { { {  -14,  32,  53,  36 },  {  -31,  29,  75,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 178: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -14,  32,  53,  33 },  {  -38,  24,  60,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 179: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -14,  32,  53,  36 },  {  -41,  27,  70,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 180: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -14,  32,  53,  33 },  {  -41,  27,  46,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 181: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  56,  34 },  {  -32,  28,  76,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 182: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  53,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 183: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  56,  30 },  {  -32,  28,  64,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 184: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  53,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 185: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  56,  34 },  {  -32,  28,  68,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 186: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  50,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 187: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  56,  29 },  {  -33,  28,  51,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 188: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  53,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 189: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  58,  34 },  {  -32,  28,  76,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 190: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  53,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 191: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  58,  32 },  {  -32,  28,  61,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 192: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  55,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 193: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  58,  33 },  {  -32,  28,  69,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 194: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  51,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 195: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  30,  58,  29 },  {  -32,  28,  50,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 196: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -20,  38,  55,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 197: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -29,  31,  55,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 198: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -35,  31,  55,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 199: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  50,  73,  22 },  {  -16,  40,  95,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 200: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  50,  73,  22 },  {  -16,  40,  95,  12 },  {  -22,  29, 107,  12 },  {    0,   0,   0,   0 } } },  /* 201: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  36,  73,  12 },  {  -17,  28,  85,  10 },  {  -24,  22,  95,  11 },  {    0,   0,   0,   0 } } },  /* 202: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -12,  24,  73,  18 },  {  -37,  36,  82,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 203: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -11,  35,  78,  20 },  {    5,  27,  94,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 204: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +1 */
    { { {  -36,  32,  85,  13 },  {  -24,  25,  98,   9 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 205: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP), ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -75,  49,   0,  24 },  {  -66,  40,  24,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 206: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -75,  49,   0,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 207: ATTACK 10 S: 3214+K light (routine Att_SLIDE_and_JUMP), ATTACK 10 M: 3214+K medium (routine Att_SLIDE_and_JUMP), ATTACK 10 L: 3214+K heavy (routine Att_SLIDE_and_JUMP) +2 */
    { { {  -41,  35,  43,  61 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 208: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -35,  27,  34,  47 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 209: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -11,  35,  78,  20 },  {    5,  27,  94,  12 },  {  -31,  30,  52,  36 },  {    0,   0,   0,   0 } } },  /* 210: ATTACK 8 S: SA III 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -51,  28,  36,  32 },  {  -62,  24,  50,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 211: KAGAMI K A */
    { { {  -82,  27,  66,  18 },  {   28,  10,  96,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 212: F JUMP K M A */
    { { {  -62,  16,  60,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 213: F JUMP K M A */
    { { {  -14,  20,  47,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 214: ATTACK 7 S: SA II 23623+K (routine Att_SLIDE_and_JUMP) */
    { { {  -43,  15,  83,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 215: F JUMP K L A */
};

const HOSEI_BOX chun_hos_box[9] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -22,   44,    0,   77 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +113 */
    { {  -22,   44,    0,   44 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +51 */
    { {  -22,   44,   48,   40 } },  /* 3: L KICK B, V JUMP P S A, V JUMP P M A +65 */
    { {  -22,   44,    0,   30 } },  /* 4: NEKOROBI S, no name, HANEAGARI +2 */
    { {  -22,   44,    0,   66 } },  /* 5: JUMP JUNBI, SP JUMP JUNBI, DASH HUMIKOMI +22 */
    { {  -22,   44,   64,   24 } },  /* 6: ATTACK 1 S: [2](789)+K light (routine Att_SENPUUKYAKU), ATTACK 1 M: [2](789)+K medium (routine Att_SENPUUKYAKU), ATTACK 1 L: [2](789)+K heavy (routine Att_SENPUUKYAKU) */
    { {  -20,   40,   64,   35 } },  /* 7: V JUMP K M B */
    { {  -28,   50,    0,   77 } },  /* 8: ATTACK 5 S: 1236+P light (plain script), ATTACK 5 M: 1236+P medium (plain script), ATTACK 5 L: 1236+P heavy (plain script) +1 */
};
