/*
 * NO12_HITBOX.C  Twelve's hit boxes
 *
 * Each of Twelve's animation frames names an entry of no12_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX no12_hit_ix_table[503] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, OKIAGARI F, OKIAGARI B +19 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +77 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +31 */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 3: KAMAE, FRONT WALK, BACK WALK +1 */
    {    3,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 4: KAMAE */
    {    4,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 5: KAMAE */
    {    5,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 6: KAMAE, WALK END */
    {    6,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 7: HURIMUKI, APPEAR 1 */
    {    6,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 8: HURIMUKI, APPEAR 1 */
    {    7,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 9: FRONT WALK, BACK WALK */
    {    8,    0,    0, 0x1010,    0,    1,    0,   26 },  /* 10: FRONT WALK, BACK WALK */
    {    9,    0,    0, 0x1010,    0,    2,    0,   26 },  /* 11: FRONT WALK, BACK WALK */
    {   10,    0,    0, 0x1010,    0,    2,    0,   26 },  /* 12: FRONT WALK, BACK WALK */
    {   11,    0,    0, 0x1010,    0,    2,    0,   26 },  /* 13: FRONT WALK, BACK WALK */
    {   12,    0,    0, 0x1010,    0,    2,    0,   26 },  /* 14: FRONT WALK, BACK WALK */
    {   13,    0,    0, 0x1818,    0,   14,    0,   22 },  /* 15: DASH HUMIKOMI */
    {   14,    0,    0, 0x0000,    0,   14,    0,   22 },  /* 16: DASH HUMIKOMI */
    {   15,    0,    0, 0x1A1A,    0,    1,    0,    1 },  /* 17: DASH HUMIKOMI */
    {   16,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 18: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +9 */
    {   17,    0,    0, 0x1A1A,    0,   14,    0,   22 },  /* 19: DASH TOBINOKI, P BREAK ZUJOU */
    {   18,    0,    0, 0x0000,    0,   14,    0,   22 },  /* 20: DASH TOBINOKI, P BREAK ZUJOU */
    {   19,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 21: DASH TOBINOKI */
    {   20,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 22: DASH TOBINOKI */
    {    1,    0,    0, 0x1111,    0,    2,    0,    2 },  /* 23: KAGAMU */
    {   21,    0,    0, 0x1818,    0,    2,    0,    2 },  /* 24: KAGAMI TURN */
    {   22,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 25: KAGAMI TURN */
    {   23,    0,    0, 0x1111,    0,    3,    0,    1 },  /* 26: JUMP JUNBI, SP JUMP JUNBI */
    {   24,    0,    0, 0x0000,    0,    3,    0,    2 },  /* 27: JUMP JUNBI, SP JUMP JUNBI */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 28: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    {   26,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 29: JUMP FRONT, JUMP VERTICAL, JUMP BACK +19 */
    {   27,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 30: JUMP FRONT, JUMP VERTICAL, JUMP BACK +13 */
    {   28,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 31: JUMP VERTICAL, SP JUMP V, PARING AIR F +15 */
    {   29,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 32: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    {   30,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 33: WALK END */
    {   31,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 34: PIYO */
    {   31,    0,    0, 0x1111,    0,    1,    0,    1 },  /* 35: PIYO */
    {   32,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 36: PIYO */
    {   33,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 37: PIYO */
    {   34,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 38: no name */
    {   34,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 39: no name */
    {   35,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 40: STAND UP */
    {   36,    0,    0, 0x1515,    0,    1,    0,    1 },  /* 41: STAND UP, no name, L KICK A */
    {   37,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 42: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +16 */
    {   38,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 43: S PUNCH A */
    {   39,    0,    1, 0x0000,    0,    1,    1,    1 },  /* 44: S PUNCH A */
    {   39,    0,    2, 0x0000,    0,    1,    2,    1 },  /* 45: S PUNCH A */
    {   39,    0,    3, 0x0000,    0,    1,    0,    1 },  /* 46: S PUNCH A */
    {   39,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 47: S PUNCH A */
    {   39,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 48: S PUNCH A */
    {   40,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 49: S PUNCH A */
    {   41,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 50: S PUNCH A */
    {   43,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 51: M PUNCH A */
    {   44,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 52: M PUNCH A */
    {   45,    0,    7, 0x0000,    0,    1,    3,    1 },  /* 53: M PUNCH A */
    {   46,    0,    8, 0x0000,    0,    1,    4,    1 },  /* 54: M PUNCH A */
    {   47,    0,    9, 0x0000,    0,    1,    0,    1 },  /* 55: M PUNCH A */
    {   48,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 56: M PUNCH A */
    {   49,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 57: M PUNCH A */
    {   50,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 58: M PUNCH A */
    {   51,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 59: M PUNCH A */
    {   52,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 60: M PUNCH A */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 61: M PUNCH A */
    {   54,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 62: M PUNCH B */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 63: M PUNCH B */
    {   56,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 64: M PUNCH B */
    {   57,    0,   15, 0x0000,    0,    1,    5,    1 },  /* 65: M PUNCH B */
    {   58,    0,   16, 0x0000,    0,    1,    6,    1 },  /* 66: M PUNCH B */
    {   59,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 67: M PUNCH B */
    {   60,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 68: M PUNCH B */
    {   61,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 69: M PUNCH B */
    {   62,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 70: M PUNCH B */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 71: M PUNCH B */
    {   64,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 72: M PUNCH B */
    {   65,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 73: L PUNCH A */
    {   66,    0,   19, 0x0000,    0,    1,    0,    1 },  /* 74: L PUNCH A */
    {   67,    0,   20, 0x0000,    0,    1,    0,    1 },  /* 75: L PUNCH A */
    {   68,    0,   21, 0x0000,    0,    1,    0,    1 },  /* 76: L PUNCH A */
    {   69,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 77: L PUNCH A */
    {   70,    0,   22, 0x0000,    0,    1,    0,    1 },  /* 78: L PUNCH A */
    {   71,    0,   23, 0x0000,    0,    1,    7,    1 },  /* 79: L PUNCH A */
    {   72,    0,   24, 0x0000,    0,    1,    8,    1 },  /* 80: L PUNCH A */
    {   73,    0,   25, 0x0000,    0,    1,    9,    1 },  /* 81: L PUNCH A */
    {   73,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 82: L PUNCH A */
    {   74,    0,   27, 0x0000,    0,    1,    0,    1 },  /* 83: L PUNCH A */
    {   74,    0,   28, 0x0000,    0,    1,    0,    1 },  /* 84: L PUNCH A */
    {   74,    0,   29, 0x0000,    0,    1,    0,    1 },  /* 85: L PUNCH A */
    {   75,    0,   30, 0x0000,    0,    1,    0,    1 },  /* 86: L PUNCH A */
    {   76,    0,   31, 0x0000,    0,    1,    0,    1 },  /* 87: L PUNCH A */
    {   77,    0,   32, 0x0000,    0,    1,    0,    1 },  /* 88: L PUNCH A */
    {   78,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 89: L PUNCH A */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 90: L PUNCH A */
    {   80,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 91: L PUNCH A */
    {   81,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 92: L PUNCH A */
    {    1,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 93: TUKAMIKAKARI A */
    {   82,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 94: BODY SLAM, IPPONZEOI, TOMOE RYU +8 */
    {   83,    0,    0, 0x0000,    0,    3,   10,    3 },  /* 95: ATTACK 8 L: not started by a command */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 96: follow-up of SP APPEAR 6 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 97: follow-up of SP APPEAR 6 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 98: not used by a script */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 99: OKIAGARI, OKIAGARI F, OKIAGARI B +16 */
    {    0,    0,    0, 0x0000,    0,    0,    0,   24 },  /* 100: NEKOROBI S, no name */
    {   84,    0,    0, 0x0000,    0,    0,    0,   24 },  /* 101: no name */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 102: ATTACK 5 S: SA I 23623+P (plain script) */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 103: GUARD HEAD, GUARD UP */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 104: GUARD DOWN */
    {   85,    0,   35, 0x0000,    0,    1,    0,    1 },  /* 105: S KICK A */
    {   86,    0,   36, 0x0000,    0,    1,    0,    1 },  /* 106: S KICK A */
    {   87,    0,   37, 0x0000,    0,    1,   11,    1 },  /* 107: S KICK A */
    {   88,    0,   38, 0x0000,    0,    1,   12,    1 },  /* 108: S KICK A */
    {   89,    0,   39, 0x0000,    0,    1,    0,    1 },  /* 109: S KICK A */
    {   90,    0,   40, 0x0000,    0,    1,    0,    1 },  /* 110: S KICK A */
    {   91,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 111: S KICK A */
    {   92,    0,   42, 0x0000,    0,    1,    0,    1 },  /* 112: S KICK A */
    {   93,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 113: S KICK A */
    {   94,    0,   44, 0x0000,    0,    1,    0,    1 },  /* 114: M KICK A */
    {   95,    0,   45, 0x0000,    0,    1,    0,    1 },  /* 115: M KICK A */
    {   96,    0,   46, 0x0000,    0,    1,   13,    1 },  /* 116: M KICK A */
    {   97,    0,   47, 0x0000,    0,    1,   14,    1 },  /* 117: M KICK A */
    {   98,    0,   47, 0x0000,    0,    1,   15,    1 },  /* 118: M KICK A */
    {   99,    0,   48, 0x0000,    0,    1,    0,    1 },  /* 119: M KICK A */
    {  100,    0,   49, 0x0000,    0,    1,    0,    1 },  /* 120: M KICK A */
    {  101,    0,   50, 0x0000,    0,    1,    0,    1 },  /* 121: M KICK A */
    {  102,    0,   51, 0x0000,    0,    1,    0,    1 },  /* 122: M KICK A */
    {  103,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 123: M KICK C */
    {  104,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 124: M KICK C */
    {  104,    0,   53, 0x0000,    0,    1,   16,    1 },  /* 125: M KICK C */
    {  105,    0,   54, 0x0000,    0,    1,   17,    1 },  /* 126: M KICK C */
    {  106,    0,   55, 0x0000,    0,    1,   18,    1 },  /* 127: M KICK C */
    {  106,    0,   56, 0x0000,    0,    1,    0,    1 },  /* 128: M KICK C */
    {  107,    0,   57, 0x0000,    0,    1,    0,    1 },  /* 129: M KICK C */
    {  108,    0,   58, 0x0000,    0,    1,    0,    1 },  /* 130: M KICK C */
    {  109,    0,   59, 0x0000,    0,    1,    0,    1 },  /* 131: M KICK C */
    {  110,    0,   60, 0x0000,    0,    1,    0,    1 },  /* 132: M KICK C */
    {  110,    0,   61, 0x0000,    0,    1,    0,    1 },  /* 133: M KICK C */
    {  110,    0,   62, 0x0000,    0,    1,    0,    1 },  /* 134: M KICK C */
    {  111,    0,   63, 0x0000,    0,    1,    0,    1 },  /* 135: M KICK C */
    {  112,    0,   64, 0x0000,    0,    1,    0,    1 },  /* 136: M KICK C */
    {  114,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 137: L KICK A */
    {  115,    0,   66, 0x0000,    0,    1,    0,    1 },  /* 138: L KICK A */
    {  115,    0,   67, 0x0000,    0,    1,    0,    1 },  /* 139: L KICK A */
    {  116,    0,   68, 0x0000,    0,    1,    0,    1 },  /* 140: L KICK A */
    {  116,    0,   69, 0x0000,    0,    1,   19,    1 },  /* 141: L KICK A */
    {  116,    0,   70, 0x0000,    0,    1,   20,    1 },  /* 142: L KICK A */
    {  116,    0,   71, 0x0000,    0,    1,   21,    1 },  /* 143: L KICK A */
    {  116,    0,   72, 0x0000,    0,    1,    0,    1 },  /* 144: L KICK A */
    {  117,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 145: L KICK A */
    {  118,    0,   73, 0x0000,    0,    1,    0,    1 },  /* 146: L KICK A */
    {  119,    0,   74, 0x0000,    0,    1,    0,    1 },  /* 147: L KICK A */
    {  120,    0,   75, 0x0000,    0,    1,    0,    1 },  /* 148: L KICK A */
    {  121,    0,   76, 0x0000,    0,    1,    0,    1 },  /* 149: L KICK A */
    {  122,    0,   77, 0x0000,    0,    1,    0,    1 },  /* 150: L KICK A */
    {  123,    0,   78, 0x0000,    0,    1,    0,    1 },  /* 151: L KICK A */
    {  124,    0,   79, 0x0000,    0,    1,    0,    1 },  /* 152: L KICK A */
    {  126,    0,   81, 0x0000,    0,   13,    0,    2 },  /* 153: KAGAMI P A */
    {  126,    0,   82, 0x0000,    0,   13,   22,    2 },  /* 154: KAGAMI P A */
    {  126,    0,   83, 0x0000,    0,   13,   23,    2 },  /* 155: KAGAMI P A */
    {  126,    0,   84, 0x0000,    0,   13,    0,    2 },  /* 156: KAGAMI P A */
    {  126,    0,   85, 0x0000,    0,   13,    0,    2 },  /* 157: KAGAMI P A */
    {  127,    0,   86, 0x0000,    0,   13,    0,    2 },  /* 158: KAGAMI P A */
    {  127,    0,    0, 0x0000,    0,   13,    0,    2 },  /* 159: KAGAMI P A */
    {  133,    0,   88, 0x0000,    0,    2,    0,    2 },  /* 160: KAGAMI P A */
    {  134,    0,   89, 0x0000,    0,    2,    0,    2 },  /* 161: KAGAMI P A */
    {  135,    0,   90, 0x0000,    0,    2,    0,    2 },  /* 162: KAGAMI P A */
    {  136,    0,   91, 0x0000,    0,    2,   24,    2 },  /* 163: KAGAMI P A */
    {  136,    0,   91, 0x0000,    0,    2,   25,    2 },  /* 164: KAGAMI P A */
    {  136,    0,   92, 0x0000,    0,    2,    0,    2 },  /* 165: KAGAMI P A */
    {  136,    0,   93, 0x0000,    0,    2,    0,    2 },  /* 166: KAGAMI P A */
    {  137,    0,   94, 0x0000,    0,    2,    0,    2 },  /* 167: KAGAMI P A */
    {  138,    0,   95, 0x0000,    0,    2,    0,    2 },  /* 168: KAGAMI P A */
    {  139,    0,   96, 0x0000,    0,    2,    0,    2 },  /* 169: KAGAMI P A */
    {  140,    0,   97, 0x0000,    0,    2,    0,    2 },  /* 170: KAGAMI P A */
    {  141,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 171: KAGAMI P A */
    {  143,    0,   99, 0x0000,    0,   13,    0,    2 },  /* 172: KAGAMI K A */
    {  144,    0,  100, 0x0000,    0,   13,   27,    2 },  /* 173: KAGAMI K A */
    {  144,    0,  101, 0x0000,    0,   13,   28,    2 },  /* 174: KAGAMI K A */
    {  144,    0,  102, 0x0000,    0,   13,    0,    2 },  /* 175: KAGAMI K A */
    {  145,    0,    0, 0x0000,    0,   13,    0,    2 },  /* 176: KAGAMI K A */
    {  147,    0,  104, 0x0000,    0,    2,    0,    2 },  /* 177: KAGAMI K A */
    {  148,    0,  105, 0x0000,    0,    2,    0,    2 },  /* 178: KAGAMI K A */
    {  148,    0,  106, 0x0000,    0,    2,    0,    2 },  /* 179: KAGAMI K A */
    {  148,    0,  107, 0x0000,    0,    2,   29,    2 },  /* 180: KAGAMI K A */
    {  148,    0,  108, 0x0000,    0,    2,   30,    2 },  /* 181: KAGAMI K A */
    {  148,    0,  109, 0x0000,    0,    2,    0,    2 },  /* 182: KAGAMI K A */
    {  148,    0,  110, 0x0000,    0,    2,    0,    2 },  /* 183: KAGAMI K A */
    {  149,    0,  111, 0x0000,    0,    2,    0,    2 },  /* 184: KAGAMI K A */
    {  149,    0,  112, 0x0000,    0,    2,    0,    2 },  /* 185: KAGAMI K A */
    {  149,    0,  113, 0x0000,    0,    2,    0,    2 },  /* 186: KAGAMI K A */
    {  150,    0,  114, 0x0000,    0,    2,    0,    2 },  /* 187: KAGAMI K A */
    {  152,    0,  116, 0x0000,    0,    2,    0,    2 },  /* 188: KAGAMI K A */
    {  153,    0,  117, 0x0000,    0,    2,    0,    2 },  /* 189: KAGAMI K A */
    {  153,    0,  118, 0x0000,    0,    2,    0,    2 },  /* 190: KAGAMI K A */
    {  154,    0,  119, 0x0000,    0,    2,    0,    2 },  /* 191: KAGAMI K A */
    {  154,    0,  120, 0x0000,    0,    2,    0,    2 },  /* 192: KAGAMI K A */
    {  155,    0,  121, 0x0000,    0,    2,    0,    2 },  /* 193: KAGAMI K A */
    {  156,    0,  122, 0x0000,    0,    2,   31,    2 },  /* 194: KAGAMI K A */
    {  157,    0,  123, 0x0000,    0,    2,    0,    2 },  /* 195: KAGAMI K A */
    {  157,    0,  124, 0x0000,    0,    2,    0,    2 },  /* 196: KAGAMI K A */
    {  158,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 197: KAGAMI K A */
    {  159,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 198: KAGAMI K A */
    {  160,    0,  125, 0x0000,    0,    2,    0,    2 },  /* 199: KAGAMI K A */
    {  161,    0,  126, 0x0000,    0,    2,    0,    2 },  /* 200: KAGAMI K A */
    {  162,    0,  127, 0x0000,    0,    2,    0,    2 },  /* 201: KAGAMI K A */
    {  164,    0,  129, 0x0000,    0,    3,    0,    3 },  /* 202: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  165,    0,  130, 0x0000,    0,    3,    0,    3 },  /* 203: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  166,    0,  131, 0x0000,    0,    3,   33,    3 },  /* 204: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  166,    0,  132, 0x0000,    0,    3,   34,    3 },  /* 205: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  167,    0,  133, 0x0000,    0,    3,    0,    3 },  /* 206: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  168,    0,  134, 0x0000,    0,    3,    0,    3 },  /* 207: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    {  169,    0,  135, 0x0000,    0,    3,    0,    3 },  /* 208: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    {  170,    0,  136, 0x0000,    0,    3,    0,    3 },  /* 209: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    {  170,    0,  137, 0x0000,    0,    3,    0,    3 },  /* 210: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    {  172,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 211: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  172,    0,  139, 0x0000,    0,    3,    0,    3 },  /* 212: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  173,    0,  140, 0x0000,    0,    3,   35,    3 },  /* 213: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  173,    0,  141, 0x0000,    0,    3,   36,    3 },  /* 214: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  173,    0,  142, 0x0000,    0,    3,    0,    3 },  /* 215: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  174,    0,  143, 0x0000,    0,    3,    0,    3 },  /* 216: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    {  176,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 217: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  176,    0,  145, 0x0000,    0,    3,    0,    3 },  /* 218: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  176,    0,  146, 0x0000,    0,    3,    0,    3 },  /* 219: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  177,    0,  147, 0x0000,    0,    3,    0,    3 },  /* 220: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  178,    0,  148, 0x0000,    0,    3,    0,    3 },  /* 221: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  179,    0,  149, 0x0000,    0,    3,   37,    3 },  /* 222: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  179,    0,  150, 0x0000,    0,    3,   38,    3 },  /* 223: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  179,    0,  151, 0x0000,    0,    3,    0,    3 },  /* 224: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  179,    0,  152, 0x0000,    0,    3,    0,    3 },  /* 225: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  180,    0,  153, 0x0000,    0,    3,    0,    3 },  /* 226: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  181,    0,  154, 0x0000,    0,    3,    0,    3 },  /* 227: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  182,    0,  155, 0x0000,    0,    3,    0,    3 },  /* 228: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  183,    0,  156, 0x0000,    0,    3,    0,    3 },  /* 229: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    {  185,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 230: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  186,    0,  158, 0x0000,    0,    3,    0,    3 },  /* 231: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  187,    0,  159, 0x0000,    0,    3,   40,    3 },  /* 232: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  187,    0,  159, 0x0000,    0,    3,   41,    3 },  /* 233: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  188,    0,  160, 0x0000,    0,    3,    0,    3 },  /* 234: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  189,    0,  161, 0x0000,    0,    3,    0,    3 },  /* 235: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    {  191,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 236: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  192,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 237: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  193,    0,  163, 0x0000,    0,    3,    0,    3 },  /* 238: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  194,    0,  164, 0x0000,    0,    3,   42,    3 },  /* 239: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  194,    0,  165, 0x0000,    0,    3,   43,    3 },  /* 240: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  194,    0,  166, 0x0000,    0,    3,    0,    3 },  /* 241: not used by a script */
    {  194,    0,  167, 0x0000,    0,    3,  118,    3 },  /* 242: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  195,    0,  168, 0x0000,    0,    3,    0,    3 },  /* 243: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  196,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 244: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    {  198,    0,  170, 0x0000,    0,    3,    0,    3 },  /* 245: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  198,    0,  171, 0x0000,    0,    3,    0,    3 },  /* 246: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  199,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 247: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  200,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 248: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  201,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 249: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  202,    0,  172, 0x0000,    0,    3,   44,    3 },  /* 250: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  202,    0,  173, 0x0000,    0,    3,   45,    3 },  /* 251: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  202,    0,  174, 0x0000,    0,    3,   46,    3 },  /* 252: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  203,    0,  175, 0x0000,    0,    3,    0,    3 },  /* 253: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  204,    0,  176, 0x0000,    0,    3,    0,    3 },  /* 254: F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    {  206,    0,  178, 0x0000,    0,    3,   47,    3 },  /* 255: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  206,    0,  179, 0x0000,    0,    3,   48,    3 },  /* 256: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  206,    0,  180, 0x0000,    0,    3,   49,    3 },  /* 257: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  209,    0,  181, 0x0000,    0,    3,   50,    3 },  /* 258: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  209,    0,  182, 0x0000,    0,    3,   51,    3 },  /* 259: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  209,    0,  183, 0x0000,    0,    3,   52,    3 },  /* 260: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  212,    0,  184, 0x0000,    0,    3,   53,    3 },  /* 261: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  212,    0,  185, 0x0000,    0,    3,   54,    3 },  /* 262: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  212,    0,  186, 0x0000,    0,    3,   55,    3 },  /* 263: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    {  215,    0,  187, 0x0000,    0,    3,   56,    3 },  /* 264: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    {  216,    0,  188, 0x0000,    0,    3,   57,    3 },  /* 265: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    {  216,    0,  189, 0x0000,    0,    3,   58,    3 },  /* 266: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    {  218,    0,  190, 0x0000,    0,    3,    0,    3 },  /* 267: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    {  219,    0,  191, 0x0000,    0,    3,    0,    3 },  /* 268: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    {  220,    0,  192, 0x0000,    0,    3,    0,    3 },  /* 269: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    {  221,    0,  193, 0x0000,    0,    3,    0,    3 },  /* 270: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  222,    0,  194, 0x0000,    0,    3,    0,    3 },  /* 271: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  223,    0,  195, 0x0000,    0,    3,    0,    3 },  /* 272: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  224,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 273: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  225,    0,  196, 0x0000,    0,    3,    0,    3 },  /* 274: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  226,    0,  197, 0x0000,    0,    3,    0,    3 },  /* 275: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    {  228,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 276: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  229,    0,  199, 0x0000,    0,    3,    0,    3 },  /* 277: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  230,    0,  200, 0x0000,    0,    3,    0,    3 },  /* 278: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  231,    0,  201, 0x0000,    0,    3,    0,    3 },  /* 279: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  232,    0,  202, 0x0000,    0,    3,    0,    3 },  /* 280: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  233,    0,  203, 0x0000,    0,    3,    0,    3 },  /* 281: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  234,    0,  204, 0x0000,    0,    3,    0,    3 },  /* 282: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    {  236,    0,  206, 0x0000,    0,    1,    0,    1 },  /* 283: ATTACK 3 L: 214+P heavy (plain script) */
    {  236,    0,  207, 0x0000,    0,    1,    0,    1 },  /* 284: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  236,    0,  208, 0x0000,    0,    1,    0,    1 },  /* 285: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) */
    {  236,    0,  209, 0x0000,    0,    1,    0,    1 },  /* 286: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) */
    {  236,    0,  210, 0x0000,    0,    1,    0,    1 },  /* 287: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  236,    0,  211, 0x0000,    0,    1,    0,    1 },  /* 288: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  236,    0,  212, 0x0000,    0,    1,    0,    1 },  /* 289: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  237,    0,  213, 0x0000,    0,    1,    0,    1 },  /* 290: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  237,    0,  214, 0x0000,    0,    1,    0,    1 },  /* 291: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  215, 0x0000,    0,    1,    0,    1 },  /* 292: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script), ATTACK 3 SP: EX 214+PP (plain script) */
    {  239,    0,  216, 0x0000,    0,    1,   59,    1 },  /* 293: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  240,    0,  217, 0x0000,    0,    1,   60,    1 },  /* 294: not used by a script */
    {  241,    0,  218, 0x0000,    0,    1,   61,    1 },  /* 295: not used by a script */
    {  242,    0,  219, 0x0000,    0,    1,   62,    1 },  /* 296: not used by a script */
    {  243,    0,  220, 0x0000,    0,    1,   63,    1 },  /* 297: not used by a script */
    {  244,    0,  221, 0x0000,    0,    1,   64,    1 },  /* 298: not used by a script */
    {  245,    0,  222, 0x0000,    0,    1,   65,    1 },  /* 299: not used by a script */
    {  246,    0,  223, 0x0000,    0,    1,   66,    1 },  /* 300: not used by a script */
    {  247,    0,  224, 0x0000,    0,    1,   67,    1 },  /* 301: not used by a script */
    {  248,    0,  225, 0x0000,    0,    1,   68,    1 },  /* 302: not used by a script */
    {  249,    0,  226, 0x0000,    0,    1,   69,    1 },  /* 303: not used by a script */
    {  238,    0,  227, 0x0000,    0,    1,    0,    1 },  /* 304: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  228, 0x0000,    0,    1,    0,    1 },  /* 305: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  229, 0x0000,    0,    1,    0,    1 },  /* 306: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  230, 0x0000,    0,    1,    0,    1 },  /* 307: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  231, 0x0000,    0,    1,    0,    1 },  /* 308: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  238,    0,  232, 0x0000,    0,    1,    0,    1 },  /* 309: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  250,    0,  233, 0x0000,    0,    1,    0,    1 },  /* 310: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  251,    0,  234, 0x0000,    0,    1,    0,    1 },  /* 311: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  252,    0,  235, 0x0000,    0,    1,    0,    1 },  /* 312: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    {  254,    0,  237, 0x0000,    0,    1,    0,    1 },  /* 313: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    {  255,    0,  238, 0x0000,    0,    1,    0,    1 },  /* 314: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    {  256,    0,  239, 0x0000,    0,    1,    0,    1 },  /* 315: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    {  257,    0,  240, 0x0000,    0,    1,    0,    1 },  /* 316: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    {  258,    0,  241, 0x0000,    0,    1,    0,    1 },  /* 317: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    {  259,    0,    0, 0x0000,    0,    2,    0,   26 },  /* 318: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    {  260,    0,    0, 0x0000,    0,    2,    0,   26 },  /* 319: ATTACK 5 S: SA I 23623+P (plain script) */
    {  260,  242,    0, 0x0000,    0,    2,   70,    2 },  /* 320: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,  243,    0, 0x0000,    0,    2,   71,    2 },  /* 321: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,  244,    0, 0x0000,    0,    2,   72,    2 },  /* 322: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,  245,    0, 0x0000,    0,    2,    0,    2 },  /* 323: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,  246,    0, 0x0000,    0,    2,    0,    2 },  /* 324: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 325: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,   26 },  /* 326: KAGAMI P A, ATTACK 4 SP: EX 236+PP (plain script), ATTACK 5 S: SA I 23623+P (plain script) +4 */
    {  261,    0,    0, 0x0000,    0,    2,    0,   26 },  /* 327: KAGAMI P A, ATTACK 4 SP: EX 236+PP (plain script), ATTACK 5 S: SA I 23623+P (plain script) +4 */
    {  262,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 328: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    {  263,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 329: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    {  264,    0,  248, 0x0000,    0,    2,    0,    2 },  /* 330: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    {  265,    0,  249, 0x0000,    0,    2,    0,    2 },  /* 331: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    {  266,    0,  250, 0x0000,    0,    2,    0,    2 },  /* 332: not used by a script */
    {  260,  252,    0, 0x0000,    0,    2,   76,    2 },  /* 333: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,  253,    0, 0x0000,    0,    2,   77,    2 },  /* 334: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,  254,    0, 0x0000,    0,    2,   78,    2 },  /* 335: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,  255,    0, 0x0000,    0,    2,    0,    2 },  /* 336: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,  256,    0, 0x0000,    0,    2,    0,    2 },  /* 337: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 338: ATTACK 9 SP: 236+K medium (plain script) */
    {  260,  259,    0, 0x0000,    0,    2,   82,    2 },  /* 339: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,  260,    0, 0x0000,    0,    2,   83,    2 },  /* 340: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,  261,    0, 0x0000,    0,    2,   84,    2 },  /* 341: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,  262,    0, 0x0000,    0,    2,    0,    2 },  /* 342: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,  263,    0, 0x0000,    0,    2,    0,    2 },  /* 343: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 344: ATTACK 10 S: 236+K heavy (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 345: ATTACK 4 SP: EX 236+PP (plain script), ATTACK 10 M: EX 236+KK (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 346: ATTACK 10 M: EX 236+KK (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 347: ATTACK 10 M: EX 236+KK (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 348: ATTACK 10 M: EX 236+KK (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 349: ATTACK 10 M: EX 236+KK (plain script) */
    {  260,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 350: ATTACK 4 SP: EX 236+PP (plain script), ATTACK 10 M: EX 236+KK (plain script) */
    {  259,  273,    0, 0x0000,    0,    2,    0,    2 },  /* 351: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  259,  274,    0, 0x0000,    0,    2,    0,    2 },  /* 352: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    {  259,  275,    0, 0x0000,    0,    2,    0,    2 },  /* 353: ATTACK 9 SP: 236+K medium (plain script) */
    {  259,  276,    0, 0x0000,    0,    2,    0,    2 },  /* 354: ATTACK 9 SP: 236+K medium (plain script) */
    {  259,  277,    0, 0x0000,    0,    2,    0,    2 },  /* 355: ATTACK 10 S: 236+K heavy (plain script) */
    {  259,  278,    0, 0x0000,    0,    2,    0,    2 },  /* 356: ATTACK 10 S: 236+K heavy (plain script) */
    {  259,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 357: ATTACK 4 SP: EX 236+PP (plain script), ATTACK 10 M: EX 236+KK (plain script) */
    {  259,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 358: ATTACK 4 SP: EX 236+PP (plain script), ATTACK 10 M: EX 236+KK (plain script) */
    {  268,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 359: ATTACK 8 L: not started by a command */
    {  269,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 360: ATTACK 8 L: not started by a command */
    {  270,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 361: UPPER L */
    {  271,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 362: UPPER L */
    {  272,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 363: UPPER L */
    {  273,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 364: UPPER L */
    {  274,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 365: TATI TOUKETU S, TATI TOUKETU M, TATI TOUKETU L */
    {  275,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 366: FACE S, FACE M, FACE L +3 */
    {  276,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 367: FACE M, FACE L, FOOK OKU L +1 */
    {  277,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 368: FACE L, FOOK OKU L, FOOK TEMAE L */
    {  278,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 369: BODY UPPER L, NOUTEN S, NOUTEN M +4 */
    {  279,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 370: BODY UPPER L, NOUTEN M, NOUTEN L +2 */
    {  280,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 371: BODY UPPER L, NOUTEN L, BODY BROW L */
    {  281,    0,    0, 0x0000,    0,    1,    0,   30 },  /* 372: BODY UPPER L, BODY BROW L, TATAKI S */
    {  282,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 373: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    {  283,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 374: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    {  284,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 375: KAGAMI L, KGM TOUKETU L */
    {  285,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 376: KAGAMI L, KGM TOUKETU L */
    {  286,    0,  281, 0x0000,    0,    3,    0,    3 },  /* 377: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  286,    0,  282, 0x0000,    0,    3,    0,    3 },  /* 378: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  286,    0,  283, 0x0000,    0,    3,    0,    3 },  /* 379: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  287,    0,  284, 0x0000,    0,    3,    0,    3 },  /* 380: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  285, 0x0000,    0,    3,    0,    3 },  /* 381: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  289,    0,  286, 0x0000,    0,    3,   94,    3 },  /* 382: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  287, 0x0000,    0,    3,    0,    3 },  /* 383: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  288, 0x0000,    0,    3,    0,    3 },  /* 384: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  289, 0x0000,    0,    3,    0,    3 },  /* 385: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  290, 0x0000,    0,    3,    0,    3 },  /* 386: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  291, 0x0000,    0,    3,    0,    3 },  /* 387: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  292, 0x0000,    0,    3,    0,    3 },  /* 388: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,  293, 0x0000,    0,    3,    0,    3 },  /* 389: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {  288,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 390: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    {   27,    0,    0, 0x0000,    0,    3,    0,    0 },  /* 391: ATTACK 11 M: started by routine Att_AIRDASH */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 392: ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A) */
    {  290,    0,    0, 0x0000,    0,    0,   95,    0 },  /* 393: not used by a script */
    {  291,    0,    0, 0x0000,    0,    0,   96,    0 },  /* 394: not used by a script */
    {  292,    0,    0, 0x0000,    0,    0,   97,    0 },  /* 395: ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A) */
    {  293,    0,    0, 0x0000,    0,    0,   98,    0 },  /* 396: not used by a script */
    {  294,    0,    0, 0x0000,    0,    0,   99,    0 },  /* 397: not used by a script */
    {  295,    0,    0, 0x0000,    0,    0,  100,    0 },  /* 398: not used by a script */
    {  296,    0,    0, 0x0000,    0,    0,  101,    0 },  /* 399: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    {  297,    0,    0, 0x0000,    0,    0,  102,    0 },  /* 400: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    {  298,    0,    0, 0x0000,    0,    0,  103,    0 },  /* 401: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    {  299,    0,    0, 0x0000,    0,    0,  104,    0 },  /* 402: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    {  300,    0,    0, 0x0000,    0,    0,  105,    0 },  /* 403: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 404: ATTACK 7 SP: not started by a command */
    {  260,  294,    0, 0x0000,    0,    2,  106,    2 },  /* 405: not used by a script */
    {  259,  294,    0, 0x0000,    0,    2,  106,    2 },  /* 406: not used by a script */
    {  259,  295,    0, 0x0000,    0,    2,  107,    2 },  /* 407: not used by a script */
    {  259,  296,    0, 0x0000,    0,    2,  108,    2 },  /* 408: not used by a script */
    {  261,  296,    0, 0x0000,    0,    2,  108,    2 },  /* 409: not used by a script */
    {  260,  297,    0, 0x0000,    0,    2,  109,    2 },  /* 410: not used by a script */
    {  259,  297,    0, 0x0000,    0,    2,  109,    2 },  /* 411: not used by a script */
    {  259,  298,    0, 0x0000,    0,    2,  110,    2 },  /* 412: not used by a script */
    {  259,  299,    0, 0x0000,    0,    2,  111,    2 },  /* 413: not used by a script */
    {  261,  299,    0, 0x0000,    0,    2,  111,    2 },  /* 414: not used by a script */
    {  260,  300,    0, 0x0000,    0,    2,  112,    2 },  /* 415: not used by a script */
    {  259,  300,    0, 0x0000,    0,    2,  112,    2 },  /* 416: not used by a script */
    {  259,  301,    0, 0x0000,    0,    2,  113,    2 },  /* 417: not used by a script */
    {  259,  302,    0, 0x0000,    0,    2,  114,    2 },  /* 418: not used by a script */
    {  261,  302,    0, 0x0000,    0,    2,  114,    2 },  /* 419: not used by a script */
    {  260,  303,    0, 0x0000,    0,    2,  115,    2 },  /* 420: not used by a script */
    {  259,  303,    0, 0x0000,    0,    2,  115,    2 },  /* 421: not used by a script */
    {  259,  304,    0, 0x0000,    0,    2,  116,    2 },  /* 422: not used by a script */
    {  259,  305,    0, 0x0000,    0,    2,  117,    2 },  /* 423: not used by a script */
    {  261,  305,    0, 0x0000,    0,    2,  117,    2 },  /* 424: not used by a script */
    {  301,    0,    0, 0x0000,    0,    2,    0,   27 },  /* 425: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    {    0,    0,    0, 0x0000,    0,    0,    0,   25 },  /* 426: ATTACK 5 S: SA I 23623+P (plain script) */
    {  302,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 427: KAGAMI P A */
    {  303,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 428: KAGAMI P A */
    {  304,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 429: KAGAMI P A */
    {  305,    0,    0, 0x0000,    0,    2,  119,    2 },  /* 430: KAGAMI P A */
    {  306,    0,    0, 0x0000,    0,    2,  120,    2 },  /* 431: KAGAMI P A */
    {  307,    0,    0, 0x0000,    0,    2,  120,    2 },  /* 432: KAGAMI P A */
    {  308,    0,    0, 0x0000,    0,    2,  120,    2 },  /* 433: KAGAMI P A */
    {  309,    0,    0, 0x0000,    0,    2,  120,    2 },  /* 434: KAGAMI P A */
    {  310,    0,    0, 0x0000,    0,    2,  120,    2 },  /* 435: KAGAMI P A */
    {  311,    0,    0, 0x0000,    0,    2,  121,    2 },  /* 436: KAGAMI P A */
    {  312,    0,    0, 0x0000,    0,    2,  122,    2 },  /* 437: KAGAMI P A */
    {  313,    0,    0, 0x0000,    0,    2,  122,    2 },  /* 438: KAGAMI P A */
    {  314,    0,    0, 0x0000,    0,    2,  122,    2 },  /* 439: KAGAMI P A */
    {  315,    0,    0, 0x0000,    0,    2,  122,    2 },  /* 440: KAGAMI P A */
    {  316,    0,    0, 0x0000,    0,    2,  122,    2 },  /* 441: KAGAMI P A */
    {  317,    0,    0, 0x0000,    0,    2,  123,    2 },  /* 442: KAGAMI P A */
    {  318,    0,    0, 0x0000,    0,    2,  124,    2 },  /* 443: KAGAMI P A */
    {  319,    0,    0, 0x0000,    0,    2,  124,    2 },  /* 444: KAGAMI P A */
    {  320,    0,    0, 0x0000,    0,    2,  124,    2 },  /* 445: KAGAMI P A */
    {  321,    0,    0, 0x0000,    0,    2,  124,    2 },  /* 446: KAGAMI P A */
    {  322,    0,    0, 0x0000,    0,    2,  124,    2 },  /* 447: KAGAMI P A */
    {  323,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 448: KAGAMI P A */
    {  324,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 449: KAGAMI P A */
    {  325,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 450: KAGAMI P A */
    {  326,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 451: KAGAMI P A */
    {  327,    0,    0, 0x0000,    0,   17,    0,   28 },  /* 452: UP P GUARD P M, ATTACK 8 M: not started by a command */
    {  328,    0,    0, 0x0000,    0,   18,    0,   29 },  /* 453: ATTACK 8 M: not started by a command */
    {  329,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 454: AIR NORMAL, BODY UPPER */
    {  330,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 455: AIR NORMAL */
    {  331,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 456: AIR NORMAL */
    {  332,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 457: ASIBARAI SIRI */
    {  333,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 458: ASIBARAI SIRI */
    {  334,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 459: ASIBARAI SIRI */
    {  335,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 460: ASIBARAI SIRI */
    {  336,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 461: ASIB TUNNOMERI, HUMI ASIB */
    {  337,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 462: ASIB TUNNOMERI, HUMI ASIB */
    {  338,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 463: ASIB TUNNOMERI */
    {  339,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 464: NOKEZORI, HARAYARARE, TATAKI AIR +3 */
    {  340,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 465: NOKEZORI, HARAYARARE, TATAKI AIR +2 */
    {  341,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 466: NOKEZORI, UPPER, BODY UPPER +6 */
    {  342,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 467: NOKEZORI, UPPER, BODY UPPER +6 */
    {  343,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 468: NOKEZORI, UPPER, BODY UPPER +6 */
    {  344,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 469: NOKEZORI, UPPER, BODY UPPER +6 */
    {  345,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 470: NOKEZORI, UPPER, BODY UPPER +6 */
    {  346,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 471: KUNOJI, KUNOJI NOKE */
    {  347,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 472: KUNOJI */
    {  348,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 473: KIRIMOMI */
    {  349,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 474: KIRIMOMI */
    {  350,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 475: KIRIMOMI */
    {  351,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 476: KIRIMOMI */
    {  352,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 477: KIRIMOMI */
    {  353,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 478: KIRIMOMI */
    {  354,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 479: KIRIMOMI */
    {  355,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 480: KIRIMOMI */
    {  356,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 481: KIRIMOMI */
    {  357,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 482: KIRIMOMI */
    {  358,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 483: KIRIMOMI */
    {  359,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 484: UPPER, HANEKAERI HARA, TATUMAKIZANKU */
    {  360,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 485: UPPER, TATUMAKIZANKU */
    {  361,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 486: UPPER, TATUMAKIZANKU */
    {  362,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 487: BODY UPPER */
    {  363,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 488: BODY UPPER */
    {  364,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 489: BODY UPPER */
    {  365,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 490: TTKI V. AIR */
    {  366,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 491: TTKI V. AIR */
    {  367,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 492: FACE */
    {  368,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 493: DENKI */
    {  369,    0,    0, 0x0000,    0,   12,    0,   23 },  /* 494: TOUKETSU A */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 495: follow-up of AIR NORMAL */
    {  370,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 496: GUARD DOWN */
    {  371,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 497: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    {  372,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 498: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    {  373,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 499: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    {  374,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 500: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 501: LOSE SONABA, SHIMEOTASARE */
    {    1,    0,   42, 0x0000,    0,    1,    0,    1 },  /* 502: not used by a script */
};

const BODY_BOX no12_body_box[375] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +84 */
    { { {  -30,  21,  44,  21 },  {  -15,  49,  44,  20 },  {  -26,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +31 */
    { { {  -26,  22,  71,  21 },  {  -31,  62,  64,  18 },  {  -25,  64,  37,  26 },  {  -30,  70,   0,  36 } } },  /* 3: KAMAE */
    { { {  -25,  22,  66,  21 },  {  -30,  64,  61,  18 },  {  -24,  69,  37,  23 },  {  -30,  71,   0,  36 } } },  /* 4: KAMAE */
    { { {  -30,  22,  70,  21 },  {  -31,  62,  65,  18 },  {  -25,  66,  37,  27 },  {  -30,  70,   0,  36 } } },  /* 5: KAMAE, WALK END */
    { { {  -36,  22,  78,  21 },  {  -30,  53,  69,  23 },  {  -27,  57,  37,  31 },  {  -30,  70,   0,  36 } } },  /* 6: HURIMUKI, APPEAR 1 */
    { { {  -23,  26,  58,  18 },  {  -30,  61,  50,  19 },  {  -29,  79,  29,  23 },  {  -36,  92,   0,  28 } } },  /* 7: FRONT WALK, BACK WALK */
    { { {  -32,  28,  49,  18 },  {  -24,  68,  43,  19 },  {  -29,  84,  24,  20 },  {  -43, 104,   0,  24 } } },  /* 8: FRONT WALK, BACK WALK */
    { { {  -47,  24,  31,  19 },  {  -27,  65,  29,  19 },  {  -29,  80,  16,  18 },  {  -47, 112,   0,  16 } } },  /* 9: FRONT WALK, BACK WALK */
    { { {  -47,  24,  31,  19 },  {  -27,  65,  29,  19 },  {  -29,  80,  16,  18 },  {  -36, 107,   0,  16 } } },  /* 10: FRONT WALK, BACK WALK */
    { { {  -40,  24,  31,  19 },  {  -27,  72,  29,  19 },  {  -44,  88,  16,  18 },  {  -63, 112,   0,  16 } } },  /* 11: FRONT WALK, BACK WALK */
    { { {  -43,  24,  31,  19 },  {  -27,  67,  29,  19 },  {  -29,  73,  16,  18 },  {  -39,  87,   0,  16 } } },  /* 12: FRONT WALK, BACK WALK */
    { { {  -31,  22,  67,  21 },  {  -32,  62,  63,  18 },  {  -22,  66,  37,  25 },  {  -27,  87,   0,  36 } } },  /* 13: DASH HUMIKOMI */
    { { {  -36,  24,  62,  21 },  {  -26,  62,  60,  18 },  {  -22,  70,  37,  22 },  {  -27,  87,   0,  36 } } },  /* 14: DASH HUMIKOMI */
    { { {  -36,  25,  57,  21 },  {  -27,  59,  59,  18 },  {  -24,  63,  37,  25 },  {  -30,  79,   0,  36 } } },  /* 15: DASH HUMIKOMI */
    { { {  -30,  22,  62,  21 },  {  -32,  59,  61,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 16: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +9 */
    { { {  -27,  22,  76,  21 },  {  -18,  56,  71,  21 },  {  -25,  58,  45,  25 },  {  -40,  81,   8,  36 } } },  /* 17: DASH TOBINOKI, P BREAK ZUJOU */
    { { {  -21,  22,  80,  21 },  {  -19,  55,  74,  21 },  {  -27,  59,  48,  25 },  {  -42,  82,  11,  36 } } },  /* 18: DASH TOBINOKI, P BREAK ZUJOU */
    { { {  -12,  22,  80,  21 },  {  -19,  58,  75,  18 },  {  -31,  65,  39,  36 },  {  -38,  80,   0,  40 } } },  /* 19: DASH TOBINOKI */
    { { {  -14,  22,  69,  21 },  {  -22,  59,  63,  18 },  {  -32,  65,  37,  25 },  {  -36,  76,   0,  36 } } },  /* 20: DASH TOBINOKI */
    { { {  -16,  21,  52,  21 },  {  -47,  74,  48,  20 },  {  -41,  75,  25,  24 },  {  -30,  63,   0,  28 } } },  /* 21: KAGAMI TURN */
    { { {  -33,  21,  50,  21 },  {  -32,  68,  48,  20 },  {  -29,  70,  25,  24 },  {  -30,  63,   0,  28 } } },  /* 22: KAGAMI TURN */
    { { {  -30,  22,  66,  21 },  {  -32,  67,  62,  18 },  {  -26,  57,  37,  25 },  {  -29,  62,   0,  36 } } },  /* 23: JUMP JUNBI, SP JUMP JUNBI */
    { { {  -34,  25,  47,  21 },  {  -20,  57,  49,  20 },  {  -25,  54,  28,  20 },  {  -26,  58,   0,  28 } } },  /* 24: JUMP JUNBI, SP JUMP JUNBI */
    { { {  -26,  54, 102,  16 },  {  -31,  64,  89,  21 },  {  -32,  66,  77,  21 },  {  -28,  57,  67,  16 } } },  /* 25: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    { { {  -10,  22, 104,  21 },  {  -26,  58,  95,  22 },  {  -23,  52,  74,  21 },  {  -22,  49,  57,  17 } } },  /* 26: JUMP FRONT, JUMP VERTICAL, JUMP BACK +19 */
    { { {  -17,  22,  97,  21 },  {  -29,  59,  94,  21 },  {  -31,  65,  82,  21 },  {  -25,  52,  64,  20 } } },  /* 27: JUMP FRONT, JUMP VERTICAL, JUMP BACK +14 */
    { { {  -19,  22, 100,  21 },  {  -30,  60,  91,  20 },  {  -23,  48,  74,  20 },  {  -24,  47,  53,  20 } } },  /* 28: JUMP VERTICAL, SP JUMP V, PARING AIR F +15 */
    { { {  -13,  25, 113,  19 },  {  -26,  58, 100,  22 },  {  -22,  51,  72,  28 },  {  -23,  50,  53,  18 } } },  /* 29: JUMP FRONT, JUMP BACK, SP JUMP FRONT +6 */
    { { {  -29,  22,  58,  21 },  {  -19,  52,  62,  24 },  {  -30,  72,  37,  27 },  {  -36,  82,   0,  36 } } },  /* 30: WALK END */
    { { {  -16,  26,  85,  19 },  {  -40,  69,  68,  22 },  {  -27,  53,  40,  36 },  {  -35,  75,   0,  40 } } },  /* 31: PIYO */
    { { {   -4,  26,  87,  19 },  {  -37,  68,  78,  20 },  {  -29,  56,  40,  38 },  {  -39,  79,   0,  40 } } },  /* 32: PIYO */
    { { {   -4,  26,  76,  19 },  {  -37,  69,  68,  20 },  {  -29,  56,  30,  38 },  {  -39,  76,   0,  30 } } },  /* 33: PIYO */
    { { {   -2,  27,  91,  17 },  {  -27,  73,  73,  20 },  {  -26,  56,  37,  36 },  {  -30,  70,   0,  36 } } },  /* 34: no name */
    { { {  -26,  22,  63,  21 },  {  -28,  55,  66,  21 },  {  -26,  59,  37,  29 },  {  -27,  57,   0,  36 } } },  /* 35: STAND UP */
    { { {  -30,  22,  71,  21 },  {  -32,  65,  67,  21 },  {  -26,  59,  37,  29 },  {  -27,  57,   0,  36 } } },  /* 36: STAND UP, no name, L KICK A */
    { { {  -29,  22,  71,  21 },  {  -31,  57,  65,  19 },  {  -26,  59,  37,  28 },  {  -30,  70,   0,  36 } } },  /* 37: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +16 */
    { { {  -30,  22,  72,  21 },  {  -34,  62,  66,  25 },  {  -29,  61,  36,  30 },  {  -30,  70,   0,  36 } } },  /* 38: S PUNCH A */
    { { {  -34,  24,  76,  18 },  {  -43,  68,  60,  29 },  {  -29,  64,  40,  24 },  {  -30,  86,   0,  38 } } },  /* 39: S PUNCH A */
    { { {  -34,  24,  76,  18 },  {  -43,  68,  60,  25 },  {  -29,  57,  40,  24 },  {  -30,  78,   0,  38 } } },  /* 40: S PUNCH A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 41: S PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: no box */
    { { {  -30,  22,  37,  21 },  {  -32,  72,  55,  18 },  {  -35,  85,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 43: M PUNCH A */
    { { {  -15,  22,  30,  21 },  {  -32,  72,  55,  18 },  {  -35,  85,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 44: M PUNCH A */
    { { {   -4,  22,  25,  21 },  {  -32,  58,  55,  18 },  {  -35,  85,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 45: M PUNCH A */
    { { {   -7,  22,  25,  21 },  {  -32,  57,  55,  18 },  {  -35,  80,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 46: M PUNCH A */
    { { {   -9,  22,  26,  21 },  {  -32,  63,  55,  26 },  {  -35,  78,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 47: M PUNCH A */
    { { {  -13,  22,  27,  21 },  {  -32,  72,  55,  28 },  {  -35,  78,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 48: M PUNCH A */
    { { {  -22,  22,  34,  21 },  {  -34,  66,  55,  32 },  {  -35,  77,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 49: M PUNCH A */
    { { {  -30,  22,  45,  21 },  {  -32,  66,  55,  23 },  {  -35,  73,  37,  25 },  {  -34,  91,   0,  36 } } },  /* 50: M PUNCH A */
    { { {  -28,  22,  62,  21 },  {  -30,  87,  63,  21 },  {  -26,  65,  37,  25 },  {  -30,  88,   0,  36 } } },  /* 51: M PUNCH A */
    { { {  -30,  22,  71,  21 },  {  -32,  59,  63,  24 },  {  -27,  68,  37,  39 },  {  -30,  78,   0,  36 } } },  /* 52: M PUNCH A */
    { { {  -30,  22,  71,  21 },  {  -32,  59,  63,  24 },  {  -27,  68,  37,  25 },  {  -30,  78,   0,  36 } } },  /* 53: M PUNCH A */
    { { {  -29,  22,  77,  21 },  {  -32,  59,  69,  21 },  {  -31,  61,  37,  32 },  {  -36,  87,   0,  36 } } },  /* 54: M PUNCH B */
    { { {  -29,  22,  77,  21 },  {  -41,  66,  69,  21 },  {  -31,  56,  37,  32 },  {  -46,  97,   0,  36 } } },  /* 55: M PUNCH B */
    { { {  -21,  44,  89,  11 },  {  -51,  90,  69,  21 },  {  -26,  51,  37,  32 },  {  -36,  87,   0,  36 } } },  /* 56: M PUNCH B */
    { { {  -21,  22,  79,  21 },  {  -32,  70,  66,  25 },  {  -25,  57,  37,  29 },  {  -41, 106,   0,  36 } } },  /* 57: M PUNCH B */
    { { {  -20,  22,  79,  21 },  {  -32,  59,  65,  24 },  {  -23,  50,  37,  28 },  {  -41,  98,   0,  37 } } },  /* 58: M PUNCH B */
    { { {  -12,  22,  79,  21 },  {  -25,  81,  69,  21 },  {  -25,  50,  37,  32 },  {  -36,  98,   0,  36 } } },  /* 59: M PUNCH B */
    { { {   -4,  22,  78,  21 },  {  -25,  73,  63,  24 },  {  -26,  55,  37,  26 },  {  -41,  97,   0,  36 } } },  /* 60: M PUNCH B */
    { { {  -11,  22,  81,  21 },  {  -25,  70,  66,  22 },  {  -26,  55,  37,  29 },  {  -61, 113,   0,  36 } } },  /* 61: M PUNCH B */
    { { {  -17,  22,  83,  21 },  {  -25,  76,  68,  21 },  {  -26,  55,  37,  31 },  {  -66, 108,   0,  36 } } },  /* 62: M PUNCH B */
    { { {  -23,  22,  80,  21 },  {  -31,  64,  72,  21 },  {  -30,  77,  37,  34 },  {  -64, 111,   0,  36 } } },  /* 63: M PUNCH B */
    { { {  -26,  22,  77,  21 },  {  -31,  65,  68,  19 },  {  -31,  75,  37,  32 },  {  -50, 100,   0,  36 } } },  /* 64: M PUNCH B */
    { { {  -30,  22,  67,  21 },  {  -35,  73,  63,  22 },  {  -26,  61,  37,  26 },  {  -34,  75,   0,  36 } } },  /* 65: L PUNCH A */
    { { {  -27,  22,  67,  21 },  {  -31,  58,  62,  23 },  {  -26,  61,  37,  25 },  {  -32,  78,   0,  36 } } },  /* 66: L PUNCH A */
    { { {  -30,  22,  67,  21 },  {  -32,  57,  63,  22 },  {  -26,  61,  37,  25 },  {  -34,  76,   0,  36 } } },  /* 67: L PUNCH A */
    { { {  -30,  22,  67,  21 },  {  -35,  59,  63,  19 },  {  -26,  61,  37,  25 },  {  -36,  79,   0,  36 } } },  /* 68: L PUNCH A */
    { { {  -37,  22,  73,  21 },  {  -33,  51,  63,  18 },  {  -31,  66,  37,  31 },  {  -34,  80,   0,  36 } } },  /* 69: L PUNCH A */
    { { {  -35,  22,  83,  21 },  {  -32,  42,  63,  29 },  {  -30,  56,  37,  25 },  {  -46,  84,   0,  36 } } },  /* 70: L PUNCH A */
    { { {  -22,  22,  83,  21 },  {  -32,  53,  74,  20 },  {  -36,  68,  36,  39 },  {  -53,  82,   0,  36 } } },  /* 71: L PUNCH A */
    { { {   -7,  22,  77,  21 },  {  -26,  56,  69,  26 },  {  -26,  64,  36,  33 },  {  -45,  86,   0,  45 } } },  /* 72: L PUNCH A */
    { { {  -11,  26,  80,  19 },  {  -26,  58,  68,  25 },  {  -26,  64,  40,  28 },  {  -45,  86,   0,  45 } } },  /* 73: L PUNCH A */
    { { {  -11,  26,  80,  19 },  {  -26,  58,  68,  25 },  {  -26,  64,  40,  28 },  {  -45,  85,   0,  45 } } },  /* 74: L PUNCH A */
    { { {  -15,  26,  83,  19 },  {  -26,  58,  68,  25 },  {  -26,  64,  40,  28 },  {  -45,  85,   0,  45 } } },  /* 75: L PUNCH A */
    { { {  -16,  26,  81,  19 },  {  -26,  58,  68,  25 },  {  -26,  64,  40,  28 },  {  -45,  85,   0,  45 } } },  /* 76: L PUNCH A */
    { { {  -17,  26,  80,  19 },  {  -26,  58,  68,  25 },  {  -26,  64,  40,  28 },  {  -45,  90,   0,  40 } } },  /* 77: L PUNCH A */
    { { {  -24,  26,  82,  19 },  {  -26,  55,  68,  24 },  {  -38,  76,  40,  28 },  {  -45,  90,   0,  40 } } },  /* 78: L PUNCH A */
    { { {  -33,  26,  80,  19 },  {  -26,  51,  68,  25 },  {  -36,  62,  40,  28 },  {  -36,  73,   0,  40 } } },  /* 79: L PUNCH A */
    { { {  -34,  26,  79,  19 },  {  -31,  56,  68,  25 },  {  -32,  58,  40,  28 },  {  -34,  72,   0,  40 } } },  /* 80: L PUNCH A */
    { { {  -34,  22,  75,  21 },  {  -37,  62,  68,  22 },  {  -37,  66,  37,  31 },  {  -33,  72,   0,  36 } } },  /* 81: L PUNCH A */
    { { {  -24,  47,  72,  17 },  {  -27,  55,  62,  18 },  {  -27,  55,  34,  27 },  {    0,   0,   0,   0 } } },  /* 82: BODY SLAM, IPPONZEOI, TOMOE RYU +8 */
    { { {  -17,  21, 103,  16 },  {  -69,  94,  91,  27 },  {  -70,  96,  53,  36 },  {  -35,  60,  43,  10 } } },  /* 83: ATTACK 8 L: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 84: no name */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 85: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 86: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 87: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 88: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 89: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 90: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 91: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 92: S KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 93: S KICK A */
    { { {   -5,  22,  79,  21 },  {  -18,  43,  68,  26 },  {  -31,  56,  37,  31 },  {  -43,  68,   0,  41 } } },  /* 94: M KICK A */
    { { {    5,  22,  79,  21 },  {  -18,  43,  68,  26 },  {  -31,  56,  37,  31 },  {  -43,  68,   0,  41 } } },  /* 95: M KICK A */
    { { {    6,  22,  74,  21 },  {  -20,  55,  67,  24 },  {  -35,  61,  37,  25 },  {  -36,  62,   0,  36 } } },  /* 96: M KICK A */
    { { {    6,  22,  74,  21 },  {  -20,  55,  67,  24 },  {  -35,  61,  37,  25 },  {  -36,  62,   0,  36 } } },  /* 97: M KICK A */
    { { {    6,  22,  74,  21 },  {  -20,  55,  67,  24 },  {  -35,  61,  37,  25 },  {  -36,  62,   0,  36 } } },  /* 98: M KICK A */
    { { {    6,  22,  74,  21 },  {  -20,  55,  67,  24 },  {  -35,  61,  37,  25 },  {  -36,  62,   0,  36 } } },  /* 99: M KICK A */
    { { {    0,  22,  85,  21 },  {  -18,  52,  75,  24 },  {  -35,  61,  37,  38 },  {  -36,  62,   0,  36 } } },  /* 100: M KICK A */
    { { {  -21,  22,  81,  21 },  {  -26,  59,  69,  23 },  {  -26,  61,  36,  33 },  {  -30,  70,   0,  36 } } },  /* 101: M KICK A */
    { { {  -30,  22,  67,  21 },  {  -32,  59,  63,  18 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 102: M KICK A */
    { { {   32,  22,  67,  21 },  {    7,  55,  56,  18 },  {  -26,  89,  37,  19 },  {  -32,  77,   0,  37 } } },  /* 103: M KICK C */
    { { {   36,  22,  47,  21 },  {  -30,  66,  57,  18 },  {  -32,  79,  36,  21 },  {  -44,  94,   0,  36 } } },  /* 104: M KICK C */
    { { {   18,  22,  60,  21 },  {    1,  52,  47,  18 },  {  -42,  96,  30,  25 },  {  -42,  97,   0,  30 } } },  /* 105: M KICK C */
    { { {   -5,  22,  62,  21 },  {  -24,  65,  52,  19 },  {  -26,  72,  27,  25 },  {  -37,  86,   0,  34 } } },  /* 106: M KICK C */
    { { {    0,  22,  62,  21 },  {  -24,  65,  52,  19 },  {  -26,  72,  27,  25 },  {  -37,  86,   0,  34 } } },  /* 107: M KICK C */
    { { {    2,  22,  62,  21 },  {  -24,  65,  52,  19 },  {  -26,  72,  27,  25 },  {  -37,  86,   0,  34 } } },  /* 108: M KICK C */
    { { {   10,  22,  62,  21 },  {  -33,  80,  52,  11 },  {  -34,  83,  27,  25 },  {  -37,  86,   0,  34 } } },  /* 109: M KICK C */
    { { {   20,  22,  63,  21 },  {  -41,  76,  57,  23 },  {  -44,  88,  37,  25 },  {  -44,  91,   0,  36 } } },  /* 110: M KICK C */
    { { {  -40,  22,  84,  21 },  {  -45,  59,  72,  21 },  {  -35,  67,  48,  25 },  {  -39,  71,   0,  48 } } },  /* 111: M KICK C */
    { { {  -41,  22,  78,  21 },  {  -45,  51,  69,  22 },  {  -31,  62,  37,  33 },  {  -38,  70,   0,  36 } } },  /* 112: M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: no box */
    { { {  -20,  22,  47,  21 },  {  -32,  50,  57,  17 },  {  -39,  70,  37,  25 },  {  -38,  79,   0,  36 } } },  /* 114: L KICK A */
    { { {   -8,  22,  45,  21 },  {  -28,  46,  62,  18 },  {  -28,  49,  37,  25 },  {  -35,  60,   0,  36 } } },  /* 115: L KICK A */
    { { {   -8,  22,  45,  21 },  {  -57,  55,  53,  24 },  {  -35,  50,  37,  25 },  {  -38,  63,   0,  36 } } },  /* 116: L KICK A */
    { { {   -8,  22,  45,  21 },  {  -50,  55,  52,  21 },  {  -45,  60,  37,  25 },  {  -42,  67,   0,  36 } } },  /* 117: L KICK A */
    { { {  -29,  22,  40,  21 },  {  -17,  29,  38,  33 },  {   12,  27,  38,  41 },  {  -36,  61,   0,  38 } } },  /* 118: L KICK A */
    { { {  -35,  22,  54,  21 },  {  -22,  27,  46,  34 },  {    5,  33,  45,  44 },  {  -30,  39,   0,  46 } } },  /* 119: L KICK A */
    { { {  -40,  22,  61,  21 },  {  -24,  26,  55,  33 },  {   -3,  43,  55,  43 },  {  -32,  32,   0,  61 } } },  /* 120: L KICK A */
    { { {  -42,  22,  68,  21 },  {  -24,  26,  55,  45 },  {    2,  33,  55,  51 },  {  -32,  32,  16,  52 } } },  /* 121: L KICK A */
    { { {  -45,  22,  75,  21 },  {  -32,  31,  57,  46 },  {   -1,  33,  57,  43 },  {  -29,  45,  32,  25 } } },  /* 122: L KICK A */
    { { {  -38,  22,  83,  21 },  {  -34,  46,  78,  28 },  {  -35,  71,  60,  22 },  {   -3,  35,  40,  20 } } },  /* 123: L KICK A */
    { { {  -36,  22,  84,  21 },  {  -39,  53,  74,  26 },  {  -41,  67,  59,  15 },  {   -7,  39,  32,  27 } } },  /* 124: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: no box */
    { { {  -26,  21,  54,  21 },  {  -33,  58,  43,  24 },  {  -33,  57,  24,  19 },  {  -34,  62,   0,  28 } } },  /* 126: KAGAMI P A */
    { { {  -30,  21,  44,  21 },  {  -15,  49,  44,  20 },  {  -26,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 127: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 132: no box */
    { { {  -25,  21,  49,  21 },  {  -29,  55,  44,  23 },  {  -26,  54,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 133: KAGAMI P A */
    { { {  -20,  21,  52,  21 },  {  -29,  55,  39,  23 },  {  -26,  54,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 134: KAGAMI P A */
    { { {  -22,  21,  54,  21 },  {  -29,  55,  39,  23 },  {  -26,  54,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 135: KAGAMI P A */
    { { {  -21,  21,  53,  21 },  {  -29,  48,  39,  21 },  {  -26,  54,  24,  24 },  {  -34,  68,   0,  28 } } },  /* 136: KAGAMI P A */
    { { {  -20,  21,  57,  21 },  {  -28,  56,  41,  22 },  {  -26,  54,  24,  24 },  {  -34,  68,   0,  28 } } },  /* 137: KAGAMI P A */
    { { {  -23,  21,  56,  21 },  {  -28,  57,  44,  24 },  {  -32,  61,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 138: KAGAMI P A */
    { { {  -25,  21,  53,  21 },  {  -27,  57,  44,  23 },  {  -28,  61,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 139: KAGAMI P A */
    { { {  -29,  21,  50,  21 },  {  -23,  50,  45,  20 },  {  -31,  64,  24,  24 },  {  -33,  66,   0,  28 } } },  /* 140: KAGAMI P A */
    { { {  -30,  21,  44,  21 },  {  -15,  49,  44,  20 },  {  -26,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 141: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 142: no box */
    { { {  -37,  21,  43,  21 },  {  -15,  49,  44,  20 },  {  -26,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 143: KAGAMI K A */
    { { {  -38,  21,  34,  21 },  {  -29,  44,  40,  20 },  {  -26,  57,  24,  28 },  {  -36,  67,   0,  28 } } },  /* 144: KAGAMI K A */
    { { {  -30,  21,  44,  21 },  {  -34,  52,  41,  22 },  {  -39,  70,  24,  26 },  {  -43,  74,   0,  28 } } },  /* 145: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: no box */
    { { {  -40,  21,  44,  21 },  {  -45,  57,  39,  25 },  {  -45,  63,  19,  24 },  {  -37,  62,   0,  28 } } },  /* 147: KAGAMI K A */
    { { {  -48,  21,  42,  21 },  {  -50,  62,  42,  22 },  {  -53,  63,  19,  23 },  {  -38,  64,   0,  28 } } },  /* 148: KAGAMI K A */
    { { {  -44,  21,  52,  21 },  {  -48,  58,  42,  28 },  {  -53,  63,  19,  23 },  {  -36,  61,   0,  28 } } },  /* 149: KAGAMI K A */
    { { {  -38,  21,  53,  21 },  {  -37,  57,  43,  27 },  {  -38,  67,  19,  24 },  {  -37,  62,   0,  28 } } },  /* 150: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 151: no box */
    { { {   11,  21,  58,  21 },  {   -3,  44,  48,  23 },  {  -30,  77,  25,  24 },  {  -30,  72,   0,  25 } } },  /* 152: KAGAMI K A */
    { { {   23,  21,  58,  21 },  {   -3,  44,  48,  23 },  {  -30,  77,  25,  33 },  {  -30,  72,   0,  25 } } },  /* 153: KAGAMI K A */
    { { {   30,  21,  53,  21 },  {   -3,  44,  48,  29 },  {  -26,  77,  25,  36 },  {  -30,  72,   0,  25 } } },  /* 154: KAGAMI K A */
    { { {   30,  21,  53,  21 },  {   -3,  44,  48,  29 },  {  -26,  77,  25,  36 },  {  -95,  72,  15,  24 } } },  /* 155: KAGAMI K A */
    { { {   39,  21,  38,  21 },  {    1,  45,  18,  48 },  {  -25,  26,  15,  35 },  {  -47,  23,  13,  27 } } },  /* 156: KAGAMI K A */
    { { {   39,  21,  38,  21 },  {    1,  45,  18,  48 },  {  -40,  42,  11,  38 },  {  -66,  30,   9,  29 } } },  /* 157: KAGAMI K A */
    { { {   41,  21,  37,  21 },  {   11,  36,  11,  52 },  {  -37,  48,  11,  46 },  {  -64,  27,  11,  33 } } },  /* 158: KAGAMI K A */
    { { {   25,  21,  47,  21 },  {   11,  36,  11,  57 },  {  -20,  31,  11,  57 },  {  -45,  26,  11,  55 } } },  /* 159: KAGAMI K A */
    { { {    1,  21,  57,  21 },  {  -19,  48,  52,  23 },  {  -26,  55,  24,  29 },  {  -42,  72,   0,  28 } } },  /* 160: KAGAMI K A */
    { { {  -22,  21,  61,  21 },  {  -27,  53,  51,  24 },  {  -31,  57,  27,  24 },  {  -40,  66,   0,  28 } } },  /* 161: KAGAMI K A */
    { { {  -32,  21,  54,  21 },  {  -32,  49,  48,  24 },  {  -33,  59,  28,  20 },  {  -33,  60,   0,  28 } } },  /* 162: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 163: no box */
    { { {  -14,  22,  95,  21 },  {  -24,  59,  94,  20 },  {  -31,  65,  82,  21 },  {  -39,  81,  64,  20 } } },  /* 164: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -19,  22,  85,  21 },  {  -29,  59,  94,  21 },  {  -31,  61,  82,  21 },  {  -36,  76,  71,  22 } } },  /* 165: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -28,  22,  68,  21 },  {  -36,  61,  90,  18 },  {  -35,  79,  76,  19 },  {  -36,  78,  65,  20 } } },  /* 166: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -20,  22,  84,  21 },  {  -34,  57,  92,  17 },  {  -45,  69,  79,  16 },  {  -42,  83,  70,  18 } } },  /* 167: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -17,  22,  91,  21 },  {  -26,  63,  93,  24 },  {  -34,  83,  82,  21 },  {  -35,  74,  64,  20 } } },  /* 168: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -17,  22,  97,  21 },  {  -23,  59,  94,  21 },  {  -25,  70,  82,  21 },  {  -25,  66,  51,  31 } } },  /* 169: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    { { {  -17,  22, 102,  21 },  {  -23,  56,  94,  21 },  {  -25,  68,  82,  21 },  {  -24,  58,  48,  34 } } },  /* 170: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 171: no box */
    { { {  -23,  22,  90,  21 },  {  -17,  47,  94,  23 },  {  -15,  53,  82,  21 },  {  -25,  82,  64,  20 } } },  /* 172: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {  -11,  22,  95,  21 },  {  -30,  51,  88,  23 },  {  -21,  46,  77,  21 },  {  -36,  83,  64,  20 } } },  /* 173: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {  -16,  22,  99,  21 },  {  -26,  59,  94,  22 },  {  -31,  78,  82,  21 },  {  -28,  73,  59,  23 } } },  /* 174: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 175: no box */
    { { {   -9,  22, 102,  21 },  {  -31,  62,  87,  21 },  {  -28,  55,  75,  21 },  {  -16,  51,  49,  36 } } },  /* 176: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -34,  22,  97,  21 },  {  -43,  54,  80,  26 },  {  -32,  49,  70,  21 },  {  -18,  53,  42,  38 } } },  /* 177: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -40,  22,  93,  21 },  {  -50,  58,  72,  29 },  {  -35,  62,  66,  21 },  {  -24,  60,  37,  36 } } },  /* 178: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -54,  22,  84,  21 },  {  -58,  56,  68,  32 },  {  -28,  40,  64,  21 },  {  -31,  68,  40,  35 } } },  /* 179: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -47,  22,  88,  21 },  {  -50,  56,  72,  33 },  {  -51,  69,  67,  14 },  {  -31,  56,  38,  35 } } },  /* 180: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -38,  22,  99,  21 },  {  -49,  62,  75,  33 },  {  -19,  39,  66,  24 },  {  -28,  63,  38,  35 } } },  /* 181: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -31,  22, 101,  21 },  {  -39,  56,  79,  33 },  {  -20,  40,  66,  17 },  {  -20,  49,  41,  25 } } },  /* 182: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -27,  22, 103,  21 },  {  -34,  59,  93,  21 },  {  -26,  51,  79,  14 },  {  -25,  52,  40,  39 } } },  /* 183: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 184: no box */
    { { {  -11,  22,  97,  21 },  {  -29,  59,  94,  21 },  {  -23,  49,  82,  21 },  {  -23,  54,  54,  28 } } },  /* 185: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -16,  22,  96,  21 },  {  -33,  67,  84,  28 },  {  -23,  49,  74,  21 },  {  -30,  63,  46,  30 } } },  /* 186: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -19,  22,  78,  21 },  {  -15,  58,  99,  23 },  {  -31,  67,  82,  21 },  {  -26,  60,  60,  22 } } },  /* 187: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -20,  22,  87,  21 },  {  -29,  66,  94,  21 },  {  -23,  47,  77,  21 },  {  -29,  67,  49,  38 } } },  /* 188: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -24,  22,  95,  21 },  {  -28,  58,  90,  24 },  {  -30,  63,  69,  21 },  {  -35,  67,  44,  25 } } },  /* 189: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 190: no box */
    { { {   -5,  22,  91,  21 },  {  -10,  54,  95,  21 },  {  -30,  76,  82,  19 },  {  -22,  59,  58,  24 } } },  /* 191: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {   -7,  22,  96,  21 },  {  -13,  52,  95,  21 },  {  -30,  72,  82,  19 },  {  -22,  59,  58,  24 } } },  /* 192: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {   -4,  22, 104,  21 },  {   -8,  49,  96,  21 },  {  -31,  81,  82,  21 },  {  -25,  70,  57,  26 } } },  /* 193: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {    3,  22, 105,  21 },  {  -30,  67,  96,  21 },  {  -33,  82,  87,  24 },  {  -20,  69,  66,  21 } } },  /* 194: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {   -9,  22, 107,  21 },  {  -26,  62,  94,  21 },  {  -33,  81,  82,  21 },  {  -35,  60,  56,  26 } } },  /* 195: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {   -9,  22, 107,  21 },  {  -26,  62,  94,  21 },  {  -33,  76,  82,  21 },  {  -35,  60,  56,  26 } } },  /* 196: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 197: no box */
    { { {  -10,  22, 112,  21 },  {  -28,  58,  94,  21 },  {  -29,  59,  84,  21 },  {  -30,  60,  48,  36 } } },  /* 198: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {   -3,  22, 106,  21 },  {  -37,  79,  94,  27 },  {  -11,  49,  84,  21 },  {  -30,  60,  48,  36 } } },  /* 199: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -11,  22, 103,  21 },  {  -44,  84,  92,  25 },  {  -11,  50,  84,  21 },  {  -30,  65,  48,  36 } } },  /* 200: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {   -2,  22, 107,  21 },  {  -12,  55,  92,  25 },  {  -48,  91,  84,  28 },  {  -36,  67,  37,  47 } } },  /* 201: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {   10,  22, 107,  21 },  {   -7,  57,  92,  19 },  {  -19,  76,  71,  21 },  {  -24,  44,  51,  19 } } },  /* 202: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {   -1,  22, 107,  21 },  {  -13,  57,  92,  19 },  {  -32,  90,  71,  21 },  {  -24,  44,  51,  19 } } },  /* 203: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {   -4,  22, 107,  21 },  {  -20,  61,  92,  20 },  {  -31,  82,  71,  28 },  {  -26,  45,  35,  35 } } },  /* 204: F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 205: no box */
    { { {  -47,  22,  51,  21 },  {  -40,  30,  58,  20 },  {  -32,  30,  66,  30 },  {  -26,  36,  76,  35 } } },  /* 206: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 207: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 208: no box */
    { { {  -68,  22,  64,  21 },  {  -62,  30,  59,  20 },  {  -53,  37,  65,  30 },  {  -40,  38,  71,  35 } } },  /* 209: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 210: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 211: no box */
    { { {  -66,  22,  63,  21 },  {  -59,  32,  67,  31 },  {  -47,  32,  71,  35 },  {  -32,  40,  76,  40 } } },  /* 212: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 213: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 214: no box */
    { { {  -62,  22,  63,  21 },  {  -61,  30,  63,  20 },  {  -53,  37,  65,  30 },  {  -40,  38,  71,  35 } } },  /* 215: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    { { {  -65,  22,  64,  21 },  {  -62,  30,  62,  20 },  {  -53,  37,  65,  30 },  {  -40,  38,  71,  35 } } },  /* 216: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 217: no box */
    { { {  -26,  22,  76,  21 },  {  -29,  52,  68,  25 },  {   -6,  49,  51,  28 },  {   -9,  53,  29,  22 } } },  /* 218: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {  -26,  22,  76,  21 },  {  -29,  52,  68,  25 },  {   -6,  49,  51,  28 },  {   -9,  53,  29,  22 } } },  /* 219: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {  -19,  22,  69,  21 },  {  -22,  57,  63,  25 },  {  -23,  58,  44,  28 },  {  -33,  67,  33,  32 } } },  /* 220: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {  -53,  22,  64,  21 },  {  -49,  37,  75,  35 },  {  -25,  42,  78,  42 },  {   13,  26,  75,  48 } } },  /* 221: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -32,  22, 108,  21 },  {  -32,  52, 101,  25 },  {  -14,  50,  82,  34 },  {  -18,  62,  60,  23 } } },  /* 222: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -21,  22, 108,  21 },  {  -29,  59, 103,  21 },  {  -31,  65,  82,  21 },  {  -25,  52,  64,  20 } } },  /* 223: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {   14,  22, 103,  21 },  {  -23,  67,  96,  21 },  {  -50,  93,  88,  15 },  {  -31,  65,  76,  20 } } },  /* 224: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {   23,  22, 100,  21 },  {  -23,  73,  96,  22 },  {  -36,  85,  88,  15 },  {  -17,  62,  74,  20 } } },  /* 225: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 226: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 227: no box */
    { { {  -44,  25,  96,  21 },  {  -60,  74,  94,  25 },  {  -31,  63,  83,  25 },  {  -20,  55,  64,  20 } } },  /* 228: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -38,  22,  99,  21 },  {  -45,  51,  90,  21 },  {  -32,  46,  78,  17 },  {  -14,  83,  69,  17 } } },  /* 229: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -37,  22,  98,  21 },  {  -45,  51,  90,  21 },  {  -31,  46,  81,  17 },  {  -10,  75,  70,  17 } } },  /* 230: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -37,  22,  98,  21 },  {  -45,  51,  90,  24 },  {  -32,  38,  83,  17 },  {  -12,  57,  72,  16 } } },  /* 231: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -39,  22, 104,  21 },  {  -32,  44,  91,  24 },  {  -23,  37,  79,  12 },  {  -27,  52,  51,  28 } } },  /* 232: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -32,  22, 107,  21 },  {  -43,  54,  98,  24 },  {  -27,  41,  79,  19 },  {  -33,  54,  51,  28 } } },  /* 233: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -17,  22, 100,  21 },  {  -25,  47,  83,  25 },  {  -21,  40,  64,  19 },  {  -22,  49,  35,  30 } } },  /* 234: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 235: no box */
    { { {  -38,  22,  70,  21 },  {  -45,  64,  63,  19 },  {  -26,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 236: ATTACK 3 L: 214+P heavy (plain script), ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script) +1 */
    { { {  -28,  22,  81,  21 },  {  -40,  65,  71,  21 },  {  -26,  60,  37,  34 },  {  -38,  88,   0,  36 } } },  /* 237: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -14,  22,  78,  21 },  {  -25,  56,  65,  23 },  {  -20,  52,  37,  28 },  {  -40,  93,   0,  42 } } },  /* 238: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script), ATTACK 3 SP: EX 214+PP (plain script) +1 */
    { { {  -18,  22,  83,  21 },  {  -30,  59,  71,  25 },  {  -20,  52,  37,  28 },  {  -54, 108,   0,  42 } } },  /* 239: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 240: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 241: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 242: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 243: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 244: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 245: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 246: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 247: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 248: not used by a script */
    { { {   22,  22,  89,  21 },  {  -36,  73,  97,  21 },  {  -30,  75,  88,  15 },  {  -22,  63,  74,  20 } } },  /* 249: not used by a script */
    { { {  -23,  22,  78,  21 },  {  -28,  56,  65,  23 },  {  -20,  52,  37,  28 },  {  -40,  93,   0,  42 } } },  /* 250: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -27,  22,  77,  21 },  {  -30,  57,  62,  29 },  {  -20,  52,  37,  25 },  {  -43,  93,   0,  42 } } },  /* 251: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -32,  22,  76,  21 },  {  -33,  53,  62,  29 },  {  -20,  52,  37,  45 },  {  -43,  93,   0,  42 } } },  /* 252: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 253: no box */
    { { {  -31,  21,  53,  21 },  {  -32,  56,  52,  21 },  {  -34,  68,  25,  27 },  {  -30,  64,   0,  28 } } },  /* 254: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -36,  21,  55,  21 },  {  -32,  56,  52,  21 },  {  -34,  72,  25,  29 },  {  -30,  66,   0,  28 } } },  /* 255: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -40,  21,  55,  21 },  {  -32,  56,  52,  21 },  {  -39,  72,  25,  29 },  {  -36,  72,   0,  28 } } },  /* 256: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -38,  21,  43,  21 },  {  -47,  84,  48,  20 },  {  -35,  70,  24,  24 },  {  -35,  74,   0,  28 } } },  /* 257: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -39,  21,  31,  21 },  {  -47,  84,  48,  20 },  {  -35,  70,  24,  24 },  {  -35,  74,   0,  28 } } },  /* 258: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -39,  21,   9,  21 },  {  -45,  80,  25,  18 },  {  -46,  83,  12,  18 },  {  -43,  83,   0,  15 } } },  /* 259: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -34,  21,   0,  21 },  {  -34,  72,  25,  18 },  {  -37,  78,  12,  18 },  {  -44,  88,   0,  15 } } },  /* 260: ATTACK 5 S: SA I 23623+P (plain script), KAGAMI P A, ATTACK 9 L: 236+K light (plain script) +4 */
    { { {  -27,  21,  11,  21 },  {  -17,  41,  35,  18 },  {  -34,  76,  12,  30 },  {  -36,  78,   0,  15 } } },  /* 261: KAGAMI P A, ATTACK 4 SP: EX 236+PP (plain script), ATTACK 5 S: SA I 23623+P (plain script) +4 */
    { { {  -42,  21,  37,  21 },  {  -36,  59,  39,  26 },  {  -46,  83,  12,  39 },  {  -44,  83,   0,  15 } } },  /* 262: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -37,  21,  49,  21 },  {  -44,  62,  41,  26 },  {  -51,  89,  18,  36 },  {  -40,  83,   0,  22 } } },  /* 263: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -33,  21,  57,  21 },  {  -38,  65,  47,  26 },  {  -34,  81,  29,  31 },  {  -37,  73,   0,  41 } } },  /* 264: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -33,  21,  57,  21 },  {  -37,  60,  46,  26 },  {  -38,  73,  28,  39 },  {  -38,  73,   0,  41 } } },  /* 265: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -32,  21,  54,  21 },  {  -33,  54,  47,  24 },  {  -34,  66,  28,  39 },  {  -38,  73,   0,  41 } } },  /* 266: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 267: no box */
    { { {  -34,  25,  47,  21 },  {  -20,  57,  49,  20 },  {  -25,  54,  28,  20 },  {  -26,  58,   0,  28 } } },  /* 268: ATTACK 8 L: not started by a command */
    { { {  -26,  54, 102,  16 },  {  -31,  64,  89,  21 },  {  -32,  66,  77,  21 },  {  -22,  49,  48,  29 } } },  /* 269: ATTACK 8 L: not started by a command */
    { { {  -14,  22,  71,  21 },  {  -28,  59,  63,  18 },  {  -27,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 270: UPPER L */
    { { {   -6,  22,  70,  21 },  {  -25,  59,  63,  18 },  {  -28,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 271: UPPER L */
    { { {   -2,  22,  69,  21 },  {  -23,  59,  63,  18 },  {  -29,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 272: UPPER L */
    { { {    0,  22,  68,  21 },  {  -22,  59,  63,  18 },  {  -30,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 273: UPPER L */
    { { {  -14,  22,  65,  21 },  {  -24,  59,  62,  18 },  {  -22,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 274: TATI TOUKETU S, TATI TOUKETU M, TATI TOUKETU L */
    { { {   -2,  22,  63,  21 },  {  -18,  59,  61,  18 },  {  -19,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 275: FACE S, FACE M, FACE L +3 */
    { { {    6,  22,  61,  21 },  {  -14,  59,  60,  18 },  {  -17,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 276: FACE M, FACE L, FOOK OKU L +1 */
    { { {   10,  22,  59,  21 },  {  -12,  59,  59,  18 },  {  -16,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 277: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {  -34,  22,  64,  21 },  {  -30,  59,  61,  18 },  {  -24,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 278: BODY UPPER L, NOUTEN S, NOUTEN M +4 */
    { { {  -38,  22,  61,  21 },  {  -28,  59,  59,  18 },  {  -22,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 279: BODY UPPER L, NOUTEN M, NOUTEN L +2 */
    { { {  -42,  22,  58,  21 },  {  -26,  59,  57,  18 },  {  -20,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 280: BODY UPPER L, NOUTEN L, BODY BROW L */
    { { {  -46,  22,  55,  21 },  {  -24,  59,  55,  18 },  {  -18,  61,  37,  25 },  {  -30,  70,   0,  36 } } },  /* 281: BODY UPPER L, BODY BROW L, TATAKI S */
    { { {  -24,  21,  44,  21 },  {  -13,  49,  44,  20 },  {  -25,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 282: KAGAMI S, KAGAMI M, KAGAMI L +4 */
    { { {  -18,  21,  44,  21 },  {  -11,  49,  44,  20 },  {  -24,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 283: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    { { {  -12,  21,  44,  21 },  {   -9,  49,  44,  20 },  {  -23,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 284: KAGAMI L, KGM TOUKETU L */
    { { {   -6,  21,  44,  21 },  {   -7,  49,  44,  20 },  {  -22,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 285: KAGAMI L, KGM TOUKETU L */
    { { {  -40,  22,  86,  21 },  {  -48,  66,  78,  35 },  {  -47,  79,  64,  21 },  {  -41,  77,  44,  20 } } },  /* 286: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -27,  22, 102,  21 },  {  -37,  61,  84,  23 },  {  -30,  67,  64,  21 },  {  -36,  86,  44,  20 } } },  /* 287: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -17,  22,  97,  21 },  {  -29,  59,  94,  21 },  {  -31,  65,  82,  21 },  {  -25,  52,  64,  20 } } },  /* 288: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -18,  22, 103,  21 },  {  -31,  64,  86,  28 },  {  -24,  53,  65,  28 },  {  -36,  78,  39,  42 } } },  /* 289: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -16,  22,  26,  28 },  {  -23,  35,  54,  30 },  {  -27,  41,  84,  32 },  {  -23,  39, 116,  60 } } },  /* 290: not used by a script */
    { { {  -55,  22,  37,  30 },  {  -40,  23,  55,  34 },  {  -29,  36,  65,  51 },  {   -4,  30,  95,  42 } } },  /* 291: not used by a script */
    { { {  -83,  36,  58,  30 },  {  -63,  49,  68,  35 },  {  -43,  61,  77,  41 },  {  -14,  72, 103,  36 } } },  /* 292: ATTACK 11 SP: SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -87,  37,  93,  21 },  {  -56,  41,  86,  33 },  {  -15,  43,  86,  40 },  {   29,  70,  87,  40 } } },  /* 293: not used by a script */
    { { {  -85,  36, 121,  20 },  {  -55,  95, 107,  22 },  {  -33,  61,  91,  25 },  {    2,  70,  72,  45 } } },  /* 294: not used by a script */
    { { {  -53,  29, 148,  19 },  {  -40,  38, 109,  45 },  {  -24,  52,  87,  46 },  {    3,  52,  55,  60 } } },  /* 295: not used by a script */
    { { {   -9,  27, 142,  32 },  {  -19,  48, 110,  32 },  {  -26,  25,  74,  36 },  {  -22,  44,  33,  41 } } },  /* 296: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -14,  27, 142,  32 },  {  -25,  48, 110,  32 },  {  -35,  65,  74,  36 },  {  -23,  44,  33,  41 } } },  /* 297: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -19,  27, 142,  32 },  {  -27,  48, 110,  32 },  {  -34,  65,  74,  36 },  {  -25,  44,  33,  41 } } },  /* 298: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -19,  27, 142,  32 },  {  -31,  48, 110,  32 },  {  -41,  65,  74,  36 },  {  -25,  44,  33,  41 } } },  /* 299: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {  -14,  27, 142,  32 },  {  -25,  48, 110,  32 },  {  -34,  65,  74,  36 },  {  -23,  44,  33,  41 } } },  /* 300: ATTACK 12 S: after SA II air 23623+K (routine Att_SA__D_R_A), ATTACK 12 M: after SA II air 23623+K (routine Att_SA__D_R_A) */
    { { {    0,   0,   0,   0 },  {  -37,  73,   0,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 301: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    { { {  -48,  29,  33,  21 },  {  -40,  70,  25,  32 },  {  -37,  71,  18,  19 },  {  -29,  67,   0,  18 } } },  /* 302: KAGAMI P A */
    { { {  -47,  29,  51,  21 },  {  -40,  52,  30,  32 },  {  -29,  61,  18,  26 },  {  -21,  73,   0,  18 } } },  /* 303: KAGAMI P A */
    { { {  -52,  27,  31,  21 },  {  -60,  56,  46,  37 },  {  -26,  39,  26,  50 },  {    8,  33,   0,  53 } } },  /* 304: KAGAMI P A */
    { { {  -51,  27,  29,  21 },  {  -55,  64,  35,  44 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 305: KAGAMI P A */
    { { {  -21,  27,  36,  21 },  {  -62,  69,  36,  45 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 306: KAGAMI P A */
    { { {  -20,  27,  54,  21 },  {  -62,  69,  36,  45 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 307: KAGAMI P A */
    { { {  -36,  27,  65,  21 },  {  -62,  69,  36,  45 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 308: KAGAMI P A */
    { { {  -65,  27,  55,  21 },  {  -62,  69,  36,  45 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 309: KAGAMI P A */
    { { {  -65,  27,  36,  21 },  {  -62,  69,  36,  45 },  {  -10,  35,  27,  12 },  {   12,  45,   0,  27 } } },  /* 310: KAGAMI P A */
    { { {  -55,  27,  21,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 311: KAGAMI P A */
    { { {  -27,  27,  29,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 312: KAGAMI P A */
    { { {  -26,  27,  47,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 313: KAGAMI P A */
    { { {  -42,  27,  55,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 314: KAGAMI P A */
    { { {  -71,  27,  47,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 315: KAGAMI P A */
    { { {  -71,  27,  27,  21 },  {  -68,  69,  28,  45 },  {   -8,  33,  19,  12 },  {    8,  53,   0,  19 } } },  /* 316: KAGAMI P A */
    { { {  -61,  27,   3,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 317: KAGAMI P A */
    { { {  -37,  27,  10,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 318: KAGAMI P A */
    { { {  -30,  27,  29,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 319: KAGAMI P A */
    { { {  -47,  27,  40,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 320: KAGAMI P A */
    { { {  -76,  27,  30,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 321: KAGAMI P A */
    { { {  -78,  27,  12,  21 },  {  -74,  69,   9,  45 },  {  -17,  36,  15,  12 },  {  -12,  76,   0,  19 } } },  /* 322: KAGAMI P A */
    { { {  -13,  27,  16,  21 },  {  -60,  69,   9,  48 },  {    0,   0,   0,   0 },  {  -31,  86,   0,  19 } } },  /* 323: KAGAMI P A */
    { { {  -13,  27,  34,  21 },  {  -55,  69,  13,  48 },  {    0,   0,   0,   0 },  {  -31,  86,   0,  19 } } },  /* 324: KAGAMI P A */
    { { {  -14,  27,  47,  21 },  {  -40,  69,  13,  48 },  {   -9,  50,  12,  31 },  {  -31,  86,   0,  19 } } },  /* 325: KAGAMI P A */
    { { {  -33,  27,  52,  21 },  {  -40,  69,  20,  48 },  {    0,   0,   0,   0 },  {  -33,  66,   0,  20 } } },  /* 326: KAGAMI P A */
    { { {  -12,  24, 122,  18 },  {  -38,  68, 106,  26 },  {  -24,  48,  74,  32 },  {  -20,  44,  36,  38 } } },  /* 327: UP P GUARD P M, ATTACK 8 M: not started by a command */
    { { {  -14,  24, 104,  18 },  {  -34,  68,  88,  26 },  {  -20,  48,  56,  32 },  {  -20,  44,  20,  36 } } },  /* 328: ATTACK 8 M: not started by a command */
    { { {  -43,  28,  73,  22 },  {  -32,  66,  72,  31 },  {  -23,  52,  55,  17 },  {  -35,  58,  35,  20 } } },  /* 329: AIR NORMAL, BODY UPPER */
    { { {  -14,  24, 108,  22 },  {  -19,  55,  97,  22 },  {  -23,  49,  66,  31 },  {  -46,  25,  55,  42 } } },  /* 330: AIR NORMAL */
    { { {   43,  26,  76,  23 },  {   11,  35,  61,  41 },  {  -25,  36,  64,  43 },  {  -49,  24,  65,  35 } } },  /* 331: AIR NORMAL */
    { { {  -25,  28,  78,  19 },  {  -29,  61,  67,  23 },  {  -37,  66,  40,  27 },  {    0,   0,   0,   0 } } },  /* 332: ASIBARAI SIRI */
    { { {   10,  29,  74,  20 },  {    1,  58,  55,  30 },  {   -1,  38,  34,  27 },  {  -26,  27,  35,  31 } } },  /* 333: ASIBARAI SIRI */
    { { {    2,  29,  65,  19 },  {    3,  48,  38,  29 },  {  -13,  48,  18,  20 },  {  -23,  26,  32,  39 } } },  /* 334: ASIBARAI SIRI */
    { { {    3,  29,  38,  17 },  {   -1,  42,  15,  23 },  {  -20,  46,  -9,  24 },  {  -22,  26,  15,  29 } } },  /* 335: ASIBARAI SIRI */
    { { {  -11,  25,  88,  17 },  {  -34,  57,  72,  19 },  {  -32,  46,  45,  27 },  {  -28,  45,  32,  13 } } },  /* 336: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -37,  29,  19,  18 },  {  -54,  59,  33,  27 },  {  -28,  35,  52,  28 },  {    6,  24,  50,  28 } } },  /* 337: ASIB TUNNOMERI, HUMI ASIB */
    { { {   16,  25,  -2,  17 },  {  -10,  55,   3,  25 },  {  -21,  40,  27,  27 },  {  -23,  48,  54,  16 } } },  /* 338: ASIB TUNNOMERI */
    { { {   24,  29,  94,  20 },  {   -6,  56,  74,  28 },  {  -24,  51,  58,  27 },  {  -33,  52,  42,  26 } } },  /* 339: NOKEZORI, HARAYARARE, TATAKI AIR +3 */
    { { {   46,  24,  69,  23 },  {    9,  45,  59,  33 },  {  -24,  40,  55,  33 },  {  -44,  54,  46,  26 } } },  /* 340: NOKEZORI, HARAYARARE, TATAKI AIR +2 */
    { { {   49,  24,  65,  23 },  {    8,  45,  57,  33 },  {  -24,  40,  55,  33 },  {  -51,  43,  51,  34 } } },  /* 341: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   50,  24,  57,  23 },  {   12,  45,  47,  36 },  {  -24,  40,  50,  36 },  {  -51,  43,  51,  34 } } },  /* 342: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   46,  24,  70,  23 },  {    8,  45,  57,  33 },  {  -24,  40,  55,  33 },  {  -36,  38,  69,  32 } } },  /* 343: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   43,  24,  53,  23 },  {    5,  45,  42,  36 },  {  -17,  40,  53,  33 },  {  -32,  43,  67,  34 } } },  /* 344: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {   30,  24,  36,  23 },  {   -7,  55,  37,  26 },  {  -18,  42,  53,  27 },  {  -29,  46,  71,  31 } } },  /* 345: NOKEZORI, UPPER, BODY UPPER +6 */
    { { {  -46,  29,  67,  21 },  {  -31,  48,  60,  27 },  {   17,  37,  41,  45 },  {  -35,  52,  28,  32 } } },  /* 346: KUNOJI, KUNOJI NOKE */
    { { {  -40,  29,  62,  21 },  {  -31,  48,  60,  27 },  {   17,  26,  41,  45 },  {  -35,  52,  35,  25 } } },  /* 347: KUNOJI */
    { { {  -30,  26,  73,  20 },  {  -27,  55,  62,  26 },  {  -39,  58,  34,  27 },  {    0,   0,   0,   0 } } },  /* 348: KIRIMOMI */
    { { {  -11,  26,  79,  20 },  {  -23,  55,  62,  26 },  {  -39,  58,  34,  27 },  {    0,   0,   0,   0 } } },  /* 349: KIRIMOMI */
    { { {   11,  26,  83,  20 },  {  -17,  63,  62,  26 },  {  -39,  58,  34,  27 },  {    0,   0,   0,   0 } } },  /* 350: KIRIMOMI */
    { { {   21,  26,  85,  20 },  {  -12,  66,  65,  32 },  {  -35,  59,  38,  27 },  {    0,   0,   0,   0 } } },  /* 351: KIRIMOMI */
    { { {   13,  26,  83,  20 },  {  -19,  62,  65,  33 },  {  -43,  59,  42,  27 },  {    0,   0,   0,   0 } } },  /* 352: KIRIMOMI */
    { { {   15,  29,  81,  21 },  {  -14,  51,  67,  26 },  {  -31,  55,  34,  33 },  {    0,   0,   0,   0 } } },  /* 353: KIRIMOMI */
    { { {   24,  29,  79,  21 },  {  -13,  68,  60,  32 },  {  -37,  59,  34,  29 },  {    0,   0,   0,   0 } } },  /* 354: KIRIMOMI */
    { { {   24,  29,  79,  21 },  {   -3,  55,  55,  32 },  {  -37,  54,  38,  29 },  {    0,   0,   0,   0 } } },  /* 355: KIRIMOMI */
    { { {   29,  29,  69,  21 },  {   -7,  55,  50,  37 },  {  -37,  54,  36,  34 },  {    0,   0,   0,   0 } } },  /* 356: KIRIMOMI */
    { { {   36,  25,  53,  21 },  {   -2,  48,  36,  44 },  {  -33,  43,  20,  39 },  {    0,   0,   0,   0 } } },  /* 357: KIRIMOMI */
    { { {   32,  25,  41,  21 },  {   -2,  48,  20,  44 },  {  -33,  43,  13,  39 },  {    0,   0,   0,   0 } } },  /* 358: KIRIMOMI */
    { { {  -32,  36,  96,  19 },  {  -28,  61,  76,  28 },  {  -21,  55,  54,  27 },  {  -27,  58,  38,  16 } } },  /* 359: UPPER, HANEKAERI HARA, TATUMAKIZANKU */
    { { {   -6,  33, 122,  19 },  {  -21,  56,  95,  28 },  {  -22,  51,  69,  26 },  {  -27,  56,  40,  29 } } },  /* 360: UPPER, TATUMAKIZANKU */
    { { {   37,  32,  56,  22 },  {   11,  40,  69,  39 },  {  -20,  36,  64,  34 },  {  -36,  40,  41,  38 } } },  /* 361: UPPER, TATUMAKIZANKU */
    { { {  -24,  25,  59,  21 },  {  -27,  51,  66,  24 },  {  -16,  55,  62,  36 },  {  -17,  56,  37,  33 } } },  /* 362: BODY UPPER */
    { { {  -19,  25,  66,  21 },  {  -23,  51,  66,  24 },  {  -13,  56,  62,  36 },  {  -26,  55,  40,  25 } } },  /* 363: BODY UPPER */
    { { {   16,  27,  92,  22 },  {    7,  59,  79,  24 },  {    3,  55,  55,  27 },  {  -20,  30,  55,  30 } } },  /* 364: BODY UPPER */
    { { {  -36,  25,  30,  19 },  {  -32,  57,  45,  34 },  {  -17,  56,  27,  46 },  {    0,   0,   0,   0 } } },  /* 365: TTKI V. AIR */
    { { {  -21,  25,  21,  19 },  {  -27,  48,  37,  36 },  {   -1,  39,  29,  37 },  {    0,   0,   0,   0 } } },  /* 366: TTKI V. AIR */
    { { {  -24,  29,  81,  17 },  {  -21,  50,  63,  23 },  {  -22,  46,  44,  21 },  {  -36,  53,  27,  23 } } },  /* 367: FACE */
    { { {    2,  29,  87,  20 },  {  -22,  56,  66,  21 },  {  -25,  47,  48,  18 },  {  -40,  65,  36,  12 } } },  /* 368: DENKI */
    { { {  -33,  26,  75,  21 },  {  -22,  47,  63,  25 },  {  -23,  50,  45,  25 },  {  -37,  60,  27,  23 } } },  /* 369: TOUKETSU A */
    { { {   -7,  21,  57,  21 },  {  -15,  49,  44,  20 },  {  -26,  66,  24,  24 },  {  -30,  63,   0,  28 } } },  /* 370: GUARD DOWN */
    { { {   26,  21,  11,  21 },  {  -26,  62,  52,  22 },  {  -35,  81,  28,  35 },  {  -31,  75,   0,  28 } } },  /* 371: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    { { {   33,  21,  33,  21 },  {  -14,  64,  52,  22 },  {  -40,  89,  28,  31 },  {  -36,  75,   0,  28 } } },  /* 372: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    { { {    5,  22,  86,  21 },  {  -27,  65,  70,  24 },  {  -24,  68,  37,  33 },  {  -34,  69,   0,  50 } } },  /* 373: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    { { {  -29,  28,  88,  19 },  {  -36,  65,  68,  24 },  {  -27,  68,  45,  23 },  {  -37,  70,   0,  55 } } },  /* 374: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
};

const HAND_BOX no12_hand_box[306] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { { -129,  99,  68,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { { -120,  90,  66,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH A */
    { { { -114,  80,  65,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH A */
    { { {  -86,  53,  61,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH A */
    { { {  -62,  19,  52,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH A */
    { { {  -86,  53,  61,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: not used by a script */
    { { {  -85,  60,  53,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH A */
    { { {  -71,  46,  53,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A */
    { { {  -55,  23,  53,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH A */
    { { {  -51,  19,  57,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A */
    { { {   32,  26,  65,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH A */
    { { {  -18,  52,  78,  15 },  {   34,  34,  58,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH A */
    { { {   57,  27,  41,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: no box */
    { { { -126, 105,  72,  21 },  {   -7,  33,  81,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: M PUNCH B */
    { { { -108,  89,  72,  21 },  {   17,  22,  69,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: M PUNCH B */
    { { { -102,  79,  73,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: not used by a script */
    { { {  -52,  18,  42,  17 },  {  -39,  13,  53,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: L PUNCH A */
    { { {  -49,  24,  44,  17 },  {  -35,  11,  61,  12 },  {   27,  19,  69,  20 },  {    0,   0,   0,   0 } } },  /* 19: L PUNCH A */
    { { {  -53,  19,  42,  17 },  {  -42,  16,  54,  18 },  {   25,  23,  67,  21 },  {    0,   0,   0,   0 } } },  /* 20: L PUNCH A */
    { { {  -53,  27,  46,  19 },  {   24,  21,  62,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L PUNCH A */
    { { {    9,  11,  63,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH A */
    { { {  -65,  51,  39,  27 },  {  -62,  30,  68,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: L PUNCH A */
    { { { -125,  53, 111,  27 },  {  -78,  15, 102,   9 },  {  -67,  21,  95,   9 },  {  -52,  26,  87,   9 } } },  /* 24: L PUNCH A */
    { { { -117,  54, 109,  27 },  {  -62,  17,  99,  10 },  {  -45,  19,  87,  12 },  {    0,   0,   0,   0 } } },  /* 25: L PUNCH A */
    { { { -112,  59, 106,  29 },  {  -52,  10,  87,  25 },  {  -41,  15,  79,  14 },  {    0,   0,   0,   0 } } },  /* 26: L PUNCH A */
    { { {  -97,  53, 111,  23 },  {  -57,   9,  83,  28 },  {  -48,  22,  77,  11 },  {    0,   0,   0,   0 } } },  /* 27: L PUNCH A */
    { { {  -76,  56, 111,  19 },  {  -76,  13,  87,  21 },  {  -62,  40,  86,  10 },  {    0,   0,   0,   0 } } },  /* 28: L PUNCH A */
    { { {  -56,  50, 103,  20 },  {  -76,  60,  87,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: L PUNCH A */
    { { {  -58,  34,  76,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: L PUNCH A */
    { { {  -50,  24,  60,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: L PUNCH A */
    { { {  -44,  19,  40,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: L PUNCH A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: no box */
    { { {  -88,  67,  36,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: not used by a script */
    { { {  -45,  21,  37,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 35: S KICK A */
    { { {  -49,  22,  36,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 36: S KICK A */
    { { { -117,  17,  15,  12 },  { -101,  33,  23,  11 },  {  -88,  64,  30,  12 },  {  -70,  46,  36,  11 } } },  /* 37: S KICK A */
    { { {  -96,  16,  23,  11 },  {  -86,  32,  28,  11 },  {  -76,  52,  31,  12 },  {  -53,  29,  39,  12 } } },  /* 38: S KICK A */
    { { {  -91,  19,  23,  10 },  {  -77,  53,  30,  11 },  {  -63,  39,  38,  10 },  {  -43,  19,  44,  10 } } },  /* 39: S KICK A */
    { { {  -50,  26,  24,  22 },  {  -39,  15,  41,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: S KICK A */
    { { {  -38,  13,  36,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: S KICK A */
    { { {  -39,  14,  36,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: S KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: no box */
    { { {  -35,  16,  68,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: M KICK A */
    { { {  -35,  16,  68,  21 },  {  -53,  22,  41,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: M KICK A */
    { { {  -75,  31,  68,  29 },  {  -67,  32,  59,  32 },  {  -56,  33,  51,  31 },  {  -47,  13,  35,  26 } } },  /* 46: M KICK A */
    { { {  -80,  36,  69,  33 },  {  -67,  32,  56,  36 },  {  -56,  33,  43,  38 },  {  -47,  13,  35,  26 } } },  /* 47: M KICK A */
    { { {  -78,  34,  76,  26 },  {  -67,  32,  71,  22 },  {  -56,  33,  61,  21 },  {  -47,  13,  35,  26 } } },  /* 48: M KICK A */
    { { {  -70,  34,  69,  26 },  {  -56,  32,  61,  21 },  {    0,   0,   0,   0 },  {  -47,  13,  35,  26 } } },  /* 49: M KICK A */
    { { {  -52,  17,  33,  47 },  {  -36,  18,  75,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: M KICK A */
    { { {  -43,  18,  53,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: M KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: no box */
    { { {  -72,  22,   0,  25 },  {  -65,  33,  23,  22 },  {  -44,  19,  42,  20 },  {    0,   0,   0,   0 } } },  /* 53: M KICK C */
    { { {  -80,  25,  23,  13 },  {  -68,  27,  27,  17 },  {  -58,  17,  37,  17 },  {    0,   0,   0,   0 } } },  /* 54: M KICK C */
    { { {  -23,  20,  71,  58 },  {  -50,  24,  23,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: M KICK C */
    { { {  -37,  18,  70,  55 },  {  -30,  25,  52,  23 },  {  -48,  22,  20,  28 },  {    0,   0,   0,   0 } } },  /* 56: M KICK C */
    { { {  -40,  14,  69,  52 },  {  -31,  17,  46,  32 },  {  -48,  22,  19,  28 },  {    0,   0,   0,   0 } } },  /* 57: M KICK C */
    { { {  -41,  17,  74,  46 },  {  -31,  18,  45,  35 },  {  -50,  19,  21,  26 },  {    0,   0,   0,   0 } } },  /* 58: M KICK C */
    { { {  -47,  12,  89,  26 },  {  -39,  18,  73,  19 },  {  -25,  20,  63,  20 },  {  -48,  14,  19,  31 } } },  /* 59: M KICK C */
    { { {  -59,  18,  61,  18 },  {  -56,  12,  21,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: M KICK C */
    { { {  -51,  10,  22,  55 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: M KICK C */
    { { {  -51,   7,  22,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 62: M KICK C */
    { { {  -51,  12,  32,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 63: M KICK C */
    { { {    6,  21,  70,  17 },  {  -48,  17,  45,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: M KICK C */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: no box */
    { { {   41,  18,  51,  59 },  {   14,  28,  81,  26 },  {   -1,  16,  81,  17 },  {  -11,  11,  81,  10 } } },  /* 66: L KICK A */
    { { {   49,  16,  81,  23 },  {    0,  37,  99,  14 },  {  -11,  60,  98,  10 },  {  -20,  33,  81,  18 } } },  /* 67: L KICK A */
    { { { -111,  94,  92,  13 },  {  -83,  26,  61,  33 },  {  -93,  46, 102,   8 },  {    0,   0,   0,   0 } } },  /* 68: L KICK A */
    { { { -193,  42,  63,  30 },  { -152,  32,  75,  11 },  { -124,  67,  67,  12 },  { -108,  52,  44,   9 } } },  /* 69: L KICK A */
    { { { -199,  46,  51,  30 },  { -180,  41,  41,  13 },  { -152,  95,  64,  13 },  {  -94,  37,  54,  10 } } },  /* 70: L KICK A */
    { { { -187,  49,  38,  23 },  { -167,  67,  31,   7 },  { -138,  81,  52,   8 },  { -103,  46,  61,  10 } } },  /* 71: L KICK A */
    { { { -124,  67,  31,  23 },  {  -77,  39,  25,  48 },  {  -89,  17,  27,  36 },  {    0,   0,   0,   0 } } },  /* 72: L KICK A */
    { { {  -41,  12,  11,  44 },  {   39,  40,  38,  35 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: L KICK A */
    { { {  -50,  20,  21,  36 },  {   37,  50,  53,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: L KICK A */
    { { {  -44,  12,  20,  30 },  {   40,  27,  53,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: L KICK A */
    { { {  -48,  16,  38,  17 },  {   35,  24,  54,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: L KICK A */
    { { {   32,  22,  63,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: L KICK A */
    { { {  -53,  19,  68,  21 },  {   12,  19,  82,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: L KICK A */
    { { {  -58,  18,  70,  22 },  {   13,  25,  60,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: L KICK A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: no box */
    { { {  -60,  27,  27,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: KAGAMI P A */
    { { { -115,  82,  24,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: KAGAMI P A */
    { { { -102,  70,  31,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: KAGAMI P A */
    { { {  -77,  16,  40,  14 },  {  -61,  14,  45,   8 },  {  -48,  15,  32,  18 },  {    0,   0,   0,   0 } } },  /* 84: KAGAMI P A */
    { { {  -53,  19,  13,  11 },  {  -39,   6,  24,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: KAGAMI P A */
    { { {  -38,   9,  14,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: no box */
    { { {  -35,   8,  29,  35 },  {   26,  17,  33,  25 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: KAGAMI P A */
    { { {  -42,  13,  43,  22 },  {   28,  15,  35,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: KAGAMI P A */
    { { {  -43,  14,  52,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 90: KAGAMI P A */
    { { {  -85,  20,  85,  17 },  {  -76,  19,  78,  16 },  {  -70,  22,  73,  14 },  {  -53,  22,  61,  17 } } },  /* 91: KAGAMI P A */
    { { {  -67,  17,  74,  14 },  {  -56,  21,  66,  14 },  {  -47,  22,  50,  23 },  {  -78,  16,  81,  13 } } },  /* 92: KAGAMI P A */
    { { {  -78,  18,  80,  20 },  {  -65,  14,  70,  14 },  {  -56,  18,  63,  14 },  {  -46,  22,  50,  21 } } },  /* 93: KAGAMI P A */
    { { {  -57,  10,  54,  21 },  {  -51,  12,  42,  16 },  {  -44,  18,  35,  17 },  {    1,  49,  56,  15 } } },  /* 94: KAGAMI P A */
    { { {  -67,   9,   9,  23 },  {  -61,  25,  13,   9 },  {  -41,  10,  14,  20 },  {   27,  23,  45,  22 } } },  /* 95: KAGAMI P A */
    { { {   30,  19,  44,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: KAGAMI P A */
    { { {   25,  17,  37,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: KAGAMI P A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 98: no box */
    { { {  -44,  18,   6,  37 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: KAGAMI K A */
    { { { -116,  41,  15,  14 },  {  -76,  50,  15,  14 },  {  -56,  31,  22,  11 },  {    0,   0,   0,   0 } } },  /* 100: KAGAMI K A */
    { { { -102,  26,  15,  14 },  {  -76,  50,  15,  14 },  {  -56,  31,  22,  11 },  {    0,   0,   0,   0 } } },  /* 101: KAGAMI K A */
    { { {  -75,  21,  15,  15 },  {  -55,  29,  19,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: no box */
    { { {   12,  21,  28,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: KAGAMI K A */
    { { {   10,  16,  28,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: KAGAMI K A */
    { { {   10,  14,  28,  32 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: KAGAMI K A */
    { { { -143,  43,  -5,  24 },  { -107,  34,   2,  24 },  {  -87,  49,   7,  25 },  {  -10,  16,  28,  31 } } },  /* 107: KAGAMI K A */
    { { { -131,  34,  -5,  24 },  { -100,  33,   0,  26 },  {  -87,  49,   7,  25 },  {   10,  16,  28,  31 } } },  /* 108: KAGAMI K A */
    { { { -116,  22,  -1,  25 },  {  -98,  60,   3,  26 },  {   10,  15,  28,  33 },  {    0,   0,   0,   0 } } },  /* 109: KAGAMI K A */
    { { {  -97,  18,   7,  19 },  {  -78,  38,  15,  15 },  {   10,  13,  28,  34 },  {    0,   0,   0,   0 } } },  /* 110: KAGAMI K A */
    { { {  -82,  19,   5,  16 },  {  -64,  21,   8,  22 },  {   10,  12,  28,  41 },  {    0,   0,   0,   0 } } },  /* 111: KAGAMI K A */
    { { {  -57,  21,   0,  19 },  {   10,  15,  28,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 112: KAGAMI K A */
    { { {   10,  18,  28,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 113: KAGAMI K A */
    { { {   20,  16,  27,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 115: no box */
    { { {  -48,  18,  14,  27 },  {  -44,  41,  50,  27 },  {  -17,  32,  69,  25 },  {    0,   0,   0,   0 } } },  /* 116: KAGAMI K A */
    { { {  -46,  16,  11,  31 },  {  -39,  36,  58,  13 },  {   -4,  36,  71,  18 },  {    0,   0,   0,   0 } } },  /* 117: KAGAMI K A */
    { { {  -60,  30,  11,  18 },  {    0,  24,  71,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: KAGAMI K A */
    { { {  -71,  41,  12,  18 },  {  -47,  22,  25,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: KAGAMI K A */
    { { {  -87,  26,  15,  32 },  {  -61,  19,  25,  25 },  {  -45,  19,  25,  33 },  {    0,   0,   0,   0 } } },  /* 120: KAGAMI K A */
    { { {  -67,  37,  38,   9 },  {  -40,  14,  38,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: KAGAMI K A */
    { { { -113,  19,   4,  14 },  {  -96,  22,   8,  15 },  {  -84,  27,  10,  19 },  {  -69,  25,  11,  25 } } },  /* 122: KAGAMI K A */
    { { {  -95,  14,   8,  10 },  {  -82,  16,   8,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: KAGAMI K A */
    { { {  -76,  10,  11,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: KAGAMI K A */
    { { {  -47,  28,  13,  56 },  {   29,  13,  18,  48 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: KAGAMI K A */
    { { {  -63,  19,  40,  12 },  {  -45,  18,  28,  37 },  {   26,  28,  29,  34 },  {    0,   0,   0,   0 } } },  /* 126: KAGAMI K A */
    { { {  -52,  19,  37,  17 },  {   17,  16,  37,  29 },  {   33,   7,  31,  27 },  {    0,   0,   0,   0 } } },  /* 127: KAGAMI K A */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: no box */
    { { {  -53,  10,  97,  19 },  {    8,  42, 115,  13 },  {   26,  22, 128,   7 },  {  -43,  12,  89,  23 } } },  /* 129: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -60,  43, 116,   9 },  {  -45,  36, 110,  13 },  {   27,  21,  96,  23 },  {    0,   0,   0,   0 } } },  /* 130: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -65,  25,  24,  19 },  {  -53,  27,  36,  19 },  {  -33,  24,  41,  24 },  {  -43,  57, 108,  13 } } },  /* 131: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -64,  26,  25,  22 },  {  -53,  27,  36,  19 },  {  -33,  24,  41,  24 },  {  -43,  57, 108,  13 } } },  /* 132: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -49,  34,  46,  18 },  {  -24,  36,  57,  13 },  {  -62,  44, 101,  16 },  {    0,   0,   0,   0 } } },  /* 133: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -48,  14,  83,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 134: V JUMP P S A, F JUMP P S A, follow-up of APPEAR JUNBI 8 */
    { { {  -41,  16,  77,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 135: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    { { {  -43,  18,  79,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 136: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    { { {  -41,  16,  79,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 137: V JUMP P S A, V JUMP P M A, V JUMP K S A +6 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 138: no box */
    { { {    8,  46, 104,  18 },  {  -41,  16,  84,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 139: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { { -103,  29, 100,  13 },  {  -80,  19,  94,  13 },  {  -63,  33,  90,  16 },  {   11,  46, 106,  19 } } },  /* 140: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { { -103,  30, 101,  18 },  {  -80,  19,  94,  13 },  {  -63,  33,  90,  16 },  {   11,  46, 106,  19 } } },  /* 141: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {  -91,  28,  95,  16 },  {  -64,  14,  90,  13 },  {  -50,  20,  84,  19 },  {   10,  48, 101,  19 } } },  /* 142: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {  -68,  16,  92,  15 },  {  -52,  21,  86,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 143: V JUMP P M A, F JUMP P M A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 144: no box */
    { { {  -47,  23,  93,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 145: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -47,  23,  93,  21 },  {   19,  27, 108,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 146: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -71,  17,  91,  15 },  {  -60,  17,  82,  21 },  {   11,  23,  87,  16 },  {   33,  18,  96,  10 } } },  /* 147: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -122,  72,  81,  11 },  {  -92,  42,  77,   4 },  {   27,  51,  75,  10 },  {    0,   0,   0,   0 } } },  /* 148: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -159,  36,  25,  34 },  { -129,  33,  38,  30 },  { -102,  27,  51,  25 },  {  -81,  23,  58,  25 } } },  /* 149: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -136,  24,  39,  16 },  { -118,  22,  47,  17 },  { -107,  27,  50,  23 },  {  -86,  30,  58,  26 } } },  /* 150: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -149,  32,  35,  15 },  { -130,  30,  44,  17 },  { -107,  27,  51,  22 },  {  -88,  32,  58,  25 } } },  /* 151: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -134,  28,  37,  25 },  { -116,  33,  46,  22 },  { -100,  31,  52,  24 },  {  -81,  30,  61,  25 } } },  /* 152: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -123,  36,  72,  11 },  {  -91,  40,  75,  14 },  {  -80,  16,  46,  13 },  {  -68,  21,  56,  19 } } },  /* 153: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { { -106,  57,  79,  13 },  {  -52,  23,  53,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 154: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -61,  25,  69,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 155: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {  -50,  16,  86,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 156: V JUMP P L A, F JUMP P L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 157: no box */
    { { {  -44,  92,  87,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 158: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -40,  28,  51,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 159: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -39,  23,  39,  28 },  {  -23,  27, 115,  14 },  {   22,  30, 114,  12 },  {    0,   0,   0,   0 } } },  /* 160: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {  -42,  12,  72,  17 },  {   30,  14,  79,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 161: V JUMP K S A, F JUMP K S A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 162: no box */
    { { {  -40,  15,  61,  41 },  {  -24,  20, 103,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 163: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { { -100,  28, 110,  18 },  {  -72,  15, 104,  16 },  {  -63,  30,  95,  18 },  {  -27,  18, 117,  17 } } },  /* 164: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {  -93,  22, 104,  22 },  {  -72,  15, 101,  19 },  {  -63,  30,  95,  18 },  {  -27,  18, 117,  17 } } },  /* 165: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {  -91,  21, 105,  20 },  {  -72,  15, 104,  15 },  {  -63,  30,  95,  18 },  {  -27,  18, 117,  17 } } },  /* 166: not used by a script */
    { { {  -88,  19, 104,  19 },  {  -72,  15, 104,  11 },  {  -60,  28,  95,  17 },  {  -27,  16, 117,  13 } } },  /* 167: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {  -71,  17,  63,  22 },  {  -54,  22,  73,  14 },  {  -42,   9,  84,   9 },  {    0,   0,   0,   0 } } },  /* 168: V JUMP K M A, F JUMP K M A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 169: no box */
    { { {  -44,  16,  87,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 170: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -37,  11,  92,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 171: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -33,  17,  -1,  16 },  {  -32,  20,   7,  13 },  {  -29,  26,  20,  16 },  {  -26,  36,  36,  15 } } },  /* 172: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -38,  18, -10,  24 },  {  -32,  20,   4,  16 },  {  -29,  26,  20,  16 },  {  -26,  36,  36,  15 } } },  /* 173: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -37,  19,  -1,   8 },  {  -32,  20,   7,  13 },  {  -29,  26,  20,  16 },  {  -26,  36,  36,  15 } } },  /* 174: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -32,  20,   7,  13 },  {  -29,  26,  20,  16 },  {  -26,  36,  36,  15 },  {    0,   0,   0,   0 } } },  /* 175: V JUMP K L A, F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {  -43,  12,  68,  16 },  {  -28,  37,  17,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 176: F JUMP K L A, follow-up of APPEAR JUNBI 8 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 177: no box */
    { { {  -17,  38,  88,  34 },  {  -64,  32,  37,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 178: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -17,  38,  88,  34 },  {  -63,  32,  40,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 179: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -17,  38,  88,  34 },  {  -61,  30,  42,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 180: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {  -81,  34,  48,  30 },  {    0,   0,   0,   0 } } },  /* 181: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {  -78,  34,  51,  30 },  {    0,   0,   0,   0 } } },  /* 182: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {  -76,  29,  55,  25 },  {    0,   0,   0,   0 } } },  /* 183: ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -17,  40,  85,  34 },  {   10,  31,  95,  30 },  {  -82,  30,  57,  25 },  {    0,   0,   0,   0 } } },  /* 184: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -17,  40,  85,  34 },  {   10,  31,  95,  30 },  {  -82,  31,  59,  27 },  {    0,   0,   0,   0 } } },  /* 185: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -17,  40,  85,  34 },  {   10,  31,  95,  30 },  {  -82,  31,  59,  27 },  {    0,   0,   0,   0 } } },  /* 186: ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU), ATTACK 13 M: not started by a command */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 187: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {  -69,  22,  61,  19 },  {    0,   0,   0,   0 } } },  /* 188: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    { { {  -31,  47,  81,  37 },  {  -14,  47,  98,  30 },  {  -70,  24,  60,  21 },  {    0,   0,   0,   0 } } },  /* 189: ATTACK 1 SP: air EX 214+KK (routine Att_KUUCHUUHISSATU) */
    { { {  -66,  16,  46,  14 },  {  -51,  19,  52,  18 },  {  -40,  23,  58,  20 },  {    0,   0,   0,   0 } } },  /* 190: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {  -66,  16,  46,  14 },  {  -51,  19,  52,  18 },  {  -40,  23,  58,  20 },  {    0,   0,   0,   0 } } },  /* 191: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {  -72,  14,  51,  17 },  {  -58,  35,  56,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 192: follow-up of ATTACK 1 S, ATTACK 1 M +3, ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU) +2 */
    { { {   33,  21,  76,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 193: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -69,  18,  81,  12 },  {  -54,  20,  86,  19 },  {  -39,  19,  92,  18 },  {    0,   0,   0,   0 } } },  /* 194: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -74,  15,  93,  13 },  {  -61,  33,  97,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 195: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -48,  22, 104,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 196: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {  -47,  33, 118,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 197: ATTACK 1 S: air 214+K light (routine Att_KUUCHUUHISSATU), ATTACK 1 M: air 214+K medium (routine Att_KUUCHUUHISSATU), ATTACK 1 L: air 214+K heavy (routine Att_KUUCHUUHISSATU) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 198: no box */
    { { {  -88,  43,  95,  13 },  {   -2,  32, 105,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 199: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -88,  43,  95,  13 },  {   -8,  33, 105,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 200: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -72,  28,  97,  13 },  {   -9,  32,  96,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 201: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -72,  40,  97,  17 },  {   -7,  29,  98,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 202: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -72,  29,  95,  15 },  {   11,  21,  96,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 203: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {  -57,  32,  89,  15 },  {   22,  17,  88,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 204: ATTACK 2 S: air (369)566... (routine Att_AIRDASH) */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 205: no box */
    { { {  -62,  37,  44,  38 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 206: ATTACK 3 L: 214+P heavy (plain script) */
    { { {  -72,  14,  50,  30 },  {  -59,  32,  48,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 207: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -68,   8,  46,  37 },  {  -61,  36,  47,  45 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 208: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) */
    { { {  -67,  14,  46,  36 },  {  -54,  28,  47,  57 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 209: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) */
    { { {  -83,  22,  32,  28 },  {  -54,  28,  47,  64 },  {  -66,  19,  57,  26 },  {    0,   0,   0,   0 } } },  /* 210: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -74,  30,  30,  27 },  {  -54,  28,  47,  36 },  {  -65,  19,  57,  26 },  {  -60,  24,  83,  31 } } },  /* 211: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -76,  24,  74,  26 },  {  -52,  26,  52,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 212: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -66,  26,  66,  19 },  {  -47,  21,  53,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 213: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -64,  30,  65,  25 },  {   10,  26,  87,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 214: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -69,  34,  75,  35 },  {  -53,  30,  58,  18 },  {  -35,  95,  85,  16 },  {    0,   0,   0,   0 } } },  /* 215: ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script), ATTACK 3 SP: EX 214+PP (plain script) */
    { { {    4,  53,  31,  81 },  {  -78,  59,  31,  81 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 216: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 217: no box */
    { { {  -73,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 218: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 219: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 220: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 221: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 222: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 223: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 224: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 225: not used by a script */
    { { {  -38,  22,  70,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 226: not used by a script */
    { { {  -78,  38,  32,  13 },  {  -49,  24,  44,  36 },  {  -30,  24,  42,  45 },  {  -53,  33,  37,  13 } } },  /* 227: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -73,  10,  28,  39 },  {  -66,  46,  48,  14 },  {   32,  29,  61,  15 },  {   62,  14,  28,  47 } } },  /* 228: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -81,  41,  33,  13 },  {  -46,  21,  45,  28 },  {   30,  18,  42,  40 },  {   47,  33,  43,  12 } } },  /* 229: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -61,  14,  26,  37 },  {  -47,  27,  52,  15 },  {   33,  18,  56,  21 },  {   52,  12,  37,  25 } } },  /* 230: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -65,  25,  40,  12 },  {  -44,  25,  42,  26 },  {   30,  20,  49,  29 },  {   49,  26,  44,  12 } } },  /* 231: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -64,  17,  32,  14 },  {  -49,  29,  42,  26 },  {   32,  20,  53,  24 },  {   52,  22,  37,  17 } } },  /* 232: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -67,  17,  37,  14 },  {  -52,  29,  42,  26 },  {   29,  20,  53,  28 },  {   46,  15,  39,  21 } } },  /* 233: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -69,  21,  42,  15 },  {  -49,  30,  50,  19 },  {   25,  18,  42,  36 },  {    0,   0,   0,   0 } } },  /* 234: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {  -65,  16,  43,  16 },  {  -50,  31,  49,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 235: ATTACK 3 S: 214+P light (plain script), ATTACK 3 M: 214+P medium (plain script), ATTACK 3 L: 214+P heavy (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 236: no box */
    { { {  -45,  12,   0,  46 },  {   34,  15,  13,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 237: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -42,  11,   9,  40 },  {   36,  10,   9,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 238: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {   24,  16,  19,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 239: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -45,  12,  12,  35 },  {   34,  10,   7,  54 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 240: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {  -43,  11,  14,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 241: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +6 */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 242: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 243: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 244: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 245: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -116,  14,   0,  36 },  { -102,  22,   0,  23 },  {    0,   0,   0,   0 } } },  /* 246: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 247: not used by a script */
    { { {  -60,  26,  29,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 248: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -63,  25,  25,  24 },  {    0,   0,   0,   0 },  {   28,  17,  22,  39 },  {    0,   0,   0,   0 } } },  /* 249: KAGAMI P A, ATTACK 4 S: 236+P light (plain script), ATTACK 4 M: 236+P medium (plain script) +7 */
    { { {  -69,  20,  28,  17 },  {  -50,  24,  37,  16 },  {   23,  17,  20,  40 },  {    0,   0,   0,   0 } } },  /* 250: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 251: no box */
    { { {    0,   0,   0,   0 },  { -203,  21,   0,  36 },  { -182,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 252: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -203,  21,   0,  36 },  { -182,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 253: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -203,  21,   0,  36 },  { -182,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 254: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -203,  21,   0,  36 },  { -182,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 255: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -196,  14,   0,  36 },  { -182,  22,   0,  23 },  {    0,   0,   0,   0 } } },  /* 256: ATTACK 9 SP: 236+K medium (plain script) */
    { { { -184,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 257: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 258: no box */
    { { {    0,   0,   0,   0 },  { -283,  21,   0,  36 },  { -262,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 259: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  { -283,  21,   0,  36 },  { -262,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 260: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  { -283,  21,   0,  36 },  { -262,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 261: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  { -283,  21,   0,  36 },  { -262,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 262: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  { -276,  14,   0,  36 },  { -262,  22,   0,  23 },  {    0,   0,   0,   0 } } },  /* 263: ATTACK 10 S: 236+K heavy (plain script) */
    { { { -264,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 264: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 265: no box */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 266: not used by a script */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 267: not used by a script */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 268: not used by a script */
    { { {    0,   0,   0,   0 },  { -123,  21,   0,  36 },  { -102,  22,   0,  24 },  {    0,   0,   0,   0 } } },  /* 269: not used by a script */
    { { {    0,   0,   0,   0 },  { -116,  14,   0,  36 },  { -102,  22,   0,  23 },  {    0,   0,   0,   0 } } },  /* 270: not used by a script */
    { { { -104,   8,   0,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 271: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 272: no box */
    { { {    0,   0,   0,   0 },  { -113,  21,   0,  27 },  {  -92,  16,   0,  19 },  {    0,   0,   0,   0 } } },  /* 273: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -113,  11,   0,  36 },  { -102,  27,   0,  25 },  {    0,   0,   0,   0 } } },  /* 274: KAGAMI P A, ATTACK 9 L: 236+K light (plain script) */
    { { {    0,   0,   0,   0 },  { -193,  21,   0,  27 },  { -172,  16,   0,  19 },  {    0,   0,   0,   0 } } },  /* 275: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -193,  11,   0,  36 },  { -182,  27,   0,  25 },  {    0,   0,   0,   0 } } },  /* 276: ATTACK 9 SP: 236+K medium (plain script) */
    { { {    0,   0,   0,   0 },  { -273,  21,   0,  27 },  { -252,  16,   0,  19 },  {    0,   0,   0,   0 } } },  /* 277: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  { -273,  11,   0,  36 },  { -262,  27,   0,  25 },  {    0,   0,   0,   0 } } },  /* 278: ATTACK 10 S: 236+K heavy (plain script) */
    { { {    0,   0,   0,   0 },  {  -17,  21,   0,  27 },  {    4,  16,   0,  19 },  {    0,   0,   0,   0 } } },  /* 279: not used by a script */
    { { {    0,   0,   0,   0 },  {  -17,  21,   0,  27 },  {    4,  16,   0,  19 },  {    0,   0,   0,   0 } } },  /* 280: not used by a script */
    { { {  -73,  36,  46,  84 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 281: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -76,  36,  81,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 282: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -73,  36,  75,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 283: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -73,  36,  78,  32 },  {    6,  31, 103,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 284: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -66,  35,  87,  43 },  {    1,  57, 106,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 285: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -76,  51,  35,  86 },  {   24,  29,  35,  87 },  {  -87,  62,  46,  69 },  {   23,  45,  46,  69 } } },  /* 286: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -79,  48,  69,  58 },  {   22,  58,  63,  56 },  {   15,  45, 119,  17 },  {  -60,  29, 127,  15 } } },  /* 287: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { { -103,  78,  65,  39 },  {   25,  71,  69,  41 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 288: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -85,  24,  31,  46 },  {  -74,  49,  71,  18 },  {   61,  23,  30,  52 },  {   34,  46,  82,  16 } } },  /* 289: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -88,  22,  32,  37 },  {  -66,  41,  59,  39 },  {   57,  25,  36,  44 },  {   26,  31,  66,  43 } } },  /* 290: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -91,  35,  44,  17 },  {  -62,  37,  56,  35 },  {   30,  24,  78,  23 },  {   50,  26,  51,  32 } } },  /* 291: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -76,  25,  39,  36 },  {  -54,  30,  66,  28 },  {   26,  27,  68,  34 },  {   51,  29,  56,  25 } } },  /* 292: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {  -73,  29,  52,  18 },  {  -54,  29,  64,  30 },  {   50,  27,  58,  21 },  {   34,  23,  73,  29 } } },  /* 293: ATTACK 6 M: air 214+P light (routine Att_AIR_A_X_E), ATTACK 6 L: air 214+P medium (routine Att_AIR_A_X_E), ATTACK 6 SP: air 214+P heavy (routine Att_AIR_A_X_E) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -97,  41,   0,  33 } } },  /* 294: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  41,   0,  33 } } },  /* 295: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -117,  41,   0,  33 } } },  /* 296: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -177,  41,   0,  33 } } },  /* 297: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -186,  41,   0,  33 } } },  /* 298: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -197,  41,   0,  33 } } },  /* 299: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -257,  41,   0,  33 } } },  /* 300: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -266,  41,   0,  33 } } },  /* 301: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -277,  41,   0,  33 } } },  /* 302: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -97,  41,   0,  33 } } },  /* 303: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -106,  41,   0,  33 } } },  /* 304: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  { -117,  41,   0,  33 } } },  /* 305: not used by a script */
};

const HOSEI_BOX no12_hos_box[31] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -25,   50,    0,   75 } },  /* 1: HURIMUKI, DASH HUMIKOMI, DASH TOBINOKI +94 */
    { {  -25,   50,    0,   59 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +56 */
    { {  -25,   50,   70,   44 } },  /* 3: JUMP FRONT, JUMP BACK, SP JUMP FRONT +40 */
    { {  -35,   48,   72,   40 } },  /* 4: not used by a script */
    { {  -24,   48,   67,   40 } },  /* 5: not used by a script */
    { {  -31,   48,   70,   40 } },  /* 6: not used by a script */
    { {  -22,   48,   70,   40 } },  /* 7: not used by a script */
    { {  -32,   48,   73,   40 } },  /* 8: not used by a script */
    { {  -21,   48,   30,   40 } },  /* 9: not used by a script */
    { {   -1,   48,   37,   40 } },  /* 10: not used by a script */
    { {  -19,   48,   27,   40 } },  /* 11: not used by a script */
    { {  -32,   48,   31,   40 } },  /* 12: not used by a script */
    { {  -28,   48,   46,   56 } },  /* 13: not used by a script */
    { {  -11,   48,   32,   56 } },  /* 14: not used by a script */
    { {  -25,   48,   32,   56 } },  /* 15: not used by a script */
    { {   -4,   48,   58,   40 } },  /* 16: not used by a script */
    { {  -21,   48,   58,   40 } },  /* 17: not used by a script */
    { {  -55,   48,    0,   54 } },  /* 18: not used by a script */
    { {  -72,   97,   22,   40 } },  /* 19: not used by a script */
    { {  -21,   27,   59,   43 } },  /* 20: not used by a script */
    { {  -43,   63,   61,   39 } },  /* 21: not used by a script */
    { {  -37,   64,    0,   79 } },  /* 22: DASH HUMIKOMI, DASH TOBINOKI, P BREAK ZUJOU */
    { {  -22,   48,   42,   37 } },  /* 23: BODY SLAM, IPPONZEOI, TOMOE RYU +27 */
    { {  -27,   54,    0,   30 } },  /* 24: NEKOROBI S, no name */
    { {  -80,  105,    0,   75 } },  /* 25: ATTACK 5 S: SA I 23623+P (plain script) */
    { {  -31,   62,    0,   40 } },  /* 26: FRONT WALK, BACK WALK, KAGAMI P A +9 */
    { {  -25,   50,    0,   29 } },  /* 27: follow-up of ATTACK 1 S, ATTACK 1 M +3, follow-up of ATTACK 11 SP */
    { {  -25,   50,   60,   64 } },  /* 28: UP P GUARD P M, ATTACK 8 M: not started by a command */
    { {  -25,   50,   38,   64 } },  /* 29: ATTACK 8 M: not started by a command */
    { {  -25,   50,    0,   64 } },  /* 30: UPPER L, TATI TOUKETU S, TATI TOUKETU M +14 */
};
