/*
 * REMY_HITBOX.C  Remy's hit boxes
 *
 * Each of Remy's animation frames names an entry of remy_hit_ix_table (cg_hit_ix in the frame
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

const HIT_IX remy_hit_ix_table[401] = {
    /* boix  bhix  haix      mf  caix  cuix  atix  hoix */
    {    0,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 0: OKIAGARI, LOSE NO STAND, LOSE SONABA +11 */
    {    1,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +57 */
    {    2,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +28 */
    {    1,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 3: FRONT WALK, BACK WALK, follow-up of KAMAE */
    {    3,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 4: follow-up of KAMAE */
    {    4,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 5: HURIMUKI */
    {    5,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 6: FRONT WALK */
    {    6,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 7: FRONT WALK */
    {    7,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 8: FRONT WALK, BACK WALK */
    {    8,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 9: FRONT WALK, BACK WALK */
    {    9,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 10: FRONT WALK, BACK WALK */
    {   10,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 11: BACK WALK */
    {   11,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 12: BACK WALK */
    {   12,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 13: DASH HUMIKOMI */
    {   13,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 14: DASH HUMIKOMI */
    {   14,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 15: DASH HUMIKOMI */
    {   15,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 16: DASH TOBINOKI */
    {   16,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 17: DASH TOBINOKI */
    {   17,    0,    0, 0x1111,    0,    2,    0,    6 },  /* 18: KAGAMU */
    {   18,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 19: KAGAMU */
    {    2,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 20: KAGAMI KAMAE */
    {   19,    0,    0, 0x1010,    0,    2,    0,    2 },  /* 21: KAGAMI KAMAE */
    {   20,    0,    0, 0x1414,    0,    2,    0,    2 },  /* 22: KAGAMI TURN */
    {   21,    0,    0, 0x1111,    0,    2,    0,    2 },  /* 23: KAGAMI TURN */
    {    2,    0,    0, 0x1010,    0,    1,    0,    2 },  /* 24: STAND UP */
    {   22,    0,    0, 0x1010,    0,    1,    0,    6 },  /* 25: STAND UP */
    {   22,    0,    0, 0x1010,    0,    2,    0,    6 },  /* 26: KAGAMU */
    {   22,    0,    0, 0x0000,    0,    3,    0,    6 },  /* 27: JUMP JUNBI, SP JUMP JUNBI, ATTACK 6 L: 214+K light (routine Att_PL20_AT2) +3 */
    {   23,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 28: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    {   23,    0,    0, 0x1212,    0,    3,    0,    3 },  /* 29: JUMP FRONT, JUMP VERTICAL, SP JUMP FRONT +1 */
    {   24,    0,    0, 0x1515,    0,    3,    0,    3 },  /* 30: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    {   25,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 31: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    {   25,    0,    0, 0x1A1A,    0,    3,    0,    3 },  /* 32: JUMP BACK, SP JUMP BACK */
    {   26,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 33: PIYO */
    {    0,    0,    0, 0x0000,    0,    0,    0,    3 },  /* 34: follow-up of AIR NORMAL */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 35: OKIAGARI, OKIAGARI F, OKIAGARI B +17 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 36: NEKOROBI S, no name */
    {   27,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 37: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    {  308,    0,    0, 0x0000,    1,    1,    0,    1 },  /* 38: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C */
    {    1,    0,    0, 0x0000,    0,    1,    1,    1 },  /* 39: follow-up of CATCH 2 */
    {    1,    0,    0, 0x0000,    0,    1,    2,    1 },  /* 40: follow-up of CATCH 2 */
    {    1,    0,    0, 0x0000,    0,    1,    3,    1 },  /* 41: follow-up of CATCH 2 */
    {    1,    0,    0, 0x0000,    0,    0,    0,    0 },  /* 42: LOSE SONABA, LOSE KAGAMI, SHIMEOTASARE */
    {   28,    0,    0, 0x0000,    0,    0,    0,    5 },  /* 43: no name */
    {   29,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 44: UPPER L */
    {   30,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 45: UPPER L */
    {   31,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 46: UPPER L */
    {   32,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 47: UPPER L */
    {   33,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 48: FACE S, FACE M, FACE L +3 */
    {   34,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 49: FACE M, FACE L, FOOK OKU L +1 */
    {   35,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 50: FACE L, FOOK OKU L, FOOK TEMAE L */
    {   36,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 51: FACE L, FOOK OKU L, FOOK TEMAE L */
    {   37,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 52: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    {   38,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 53: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    {   39,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 54: NOUTEN L, BODY BROW L, BODY UPPER L */
    {   40,    0,    0, 0x0000,    0,    1,    0,   11 },  /* 55: NOUTEN L, BODY BROW L, BODY UPPER L +8 */
    {   41,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 56: TATAKI S, TATAKI M, TATAKI L +19 */
    {   42,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 57: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    {   43,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 58: KAGAMI L, KGM TOUKETU L */
    {   44,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 59: KAGAMI L */
    {   45,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 60: S PUNCH A */
    {   45,    0,    0, 0x0000,    0,    1,    4,    1 },  /* 61: S PUNCH A */
    {   45,    0,    0, 0x0000,    0,    1,    5,    1 },  /* 62: S PUNCH A */
    {   45,    0,    1, 0x0000,    0,    1,    0,    1 },  /* 63: S PUNCH A */
    {   46,    0,    2, 0x0000,    0,    1,    0,    1 },  /* 64: S PUNCH B, ATTACK 10 SP: not started by a command */
    {   46,    0,    3, 0x0000,    0,    1,    6,    1 },  /* 65: S PUNCH B */
    {   46,    0,    3, 0x0000,    0,    1,    7,    1 },  /* 66: S PUNCH B */
    {   46,    0,    4, 0x0000,    0,    1,    0,    1 },  /* 67: S PUNCH B */
    {   46,    0,    5, 0x0000,    0,    1,    0,    1 },  /* 68: S PUNCH B */
    {   47,    0,    6, 0x0000,    0,    1,    0,    1 },  /* 69: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   48,    0,    7, 0x0000,    0,    1,    0,    1 },  /* 70: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   49,    0,    8, 0x0000,    0,    1,    8,    1 },  /* 71: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   50,    0,    9, 0x0000,    0,    1,    9,    1 },  /* 72: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   50,    0,   10, 0x0000,    0,    1,   10,    1 },  /* 73: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   50,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 74: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   51,    0,   10, 0x0000,    0,    1,    0,    1 },  /* 75: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   47,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 76: M PUNCH A */
    {   52,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 77: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   53,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 78: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   54,    0,   25, 0x0000,    0,    1,   11,    1 },  /* 79: M PUNCH B */
    {   54,    0,   11, 0x0000,    0,    1,   12,    1 },  /* 80: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   54,    0,   11, 0x0000,    0,    1,    0,    1 },  /* 81: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   53,    0,   12, 0x0000,    0,    1,    0,    1 },  /* 82: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   55,    0,   13, 0x0000,    0,    1,    0,    1 },  /* 83: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   55,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 84: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   56,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 85: L PUNCH A */
    {   57,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 86: L PUNCH A */
    {   58,    0,   14, 0x0000,    0,    1,   13,    1 },  /* 87: L PUNCH A */
    {   59,    0,   15, 0x0000,    0,    1,   14,    1 },  /* 88: L PUNCH A */
    {   59,    0,   16, 0x0000,    0,    1,   15,    1 },  /* 89: L PUNCH A */
    {   59,    0,   17, 0x0000,    0,    1,    0,    1 },  /* 90: L PUNCH A */
    {   59,    0,   18, 0x0000,    0,    1,    0,    1 },  /* 91: L PUNCH A */
    {   60,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 92: L PUNCH A */
    {   61,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 93: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   62,    0,   19, 0x0000,    0,    1,    0,    1 },  /* 94: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   63,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 95: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   64,    0,   20, 0x0000,    0,    1,   16,    1 },  /* 96: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   64,    0,   21, 0x0000,    0,    1,   17,    1 },  /* 97: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   64,    0,  123, 0x0000,    0,    1,    0,    1 },  /* 98: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   64,    0,   22, 0x0000,    0,    1,    0,    1 },  /* 99: L PUNCH B */
    {   65,    0,   23, 0x0000,    0,    1,    0,    1 },  /* 100: L PUNCH B */
    {   66,    0,   24, 0x0000,    0,    1,    0,    1 },  /* 101: L PUNCH B */
    {   67,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 102: S KICK A */
    {   68,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 103: S KICK A */
    {   69,    0,    0, 0x0000,    0,    1,   18,    1 },  /* 104: S KICK A */
    {   69,    0,   26, 0x0000,    0,    1,    0,    1 },  /* 105: S KICK A */
    {   70,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 106: S KICK A */
    {   71,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 107: S KICK B */
    {   71,    0,   27, 0x0000,    0,    1,   19,    1 },  /* 108: S KICK B */
    {   71,    0,   28, 0x0000,    0,    1,    0,    1 },  /* 109: S KICK B */
    {   72,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 110: S KICK B */
    {   73,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 111: S KICK B */
    {   74,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 112: M KICK A */
    {   75,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 113: M KICK A */
    {   76,    0,   29, 0x0000,    0,    1,   20,    1 },  /* 114: M KICK A */
    {   76,    0,   29, 0x0000,    0,    1,    0,    1 },  /* 115: M KICK A */
    {   77,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 116: M KICK A */
    {   78,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 117: M KICK B */
    {   79,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 118: M KICK B */
    {   80,   30,    0, 0x0000,    0,    1,   21,    1 },  /* 119: M KICK B */
    {   80,   31,    0, 0x0000,    0,    1,   22,    1 },  /* 120: M KICK B */
    {   80,   31,    0, 0x0000,    0,    1,    0,    1 },  /* 121: M KICK B */
    {   81,   32,    0, 0x0000,    0,    1,    0,    1 },  /* 122: M KICK B */
    {   82,    0,   33, 0x0000,    0,    1,    0,    1 },  /* 123: M KICK B */
    {   83,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 124: L KICK A */
    {   84,    0,   34, 0x0000,    0,    1,   23,    1 },  /* 125: L KICK A */
    {   85,    0,   35, 0x0000,    0,    1,   24,    1 },  /* 126: L KICK A */
    {   85,    0,   36, 0x0000,    0,    1,   24,    1 },  /* 127: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   85,    0,   36, 0x0000,    0,    1,    0,    1 },  /* 128: L KICK A */
    {   85,    0,   37, 0x0000,    0,    1,    0,    1 },  /* 129: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   86,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 130: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   87,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 131: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   88,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 132: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   89,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 133: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   90,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 134: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   91,    0,   38, 0x0000,    0,    1,   25,    1 },  /* 135: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   91,    0,   39, 0x0000,    0,    1,   26,    1 },  /* 136: L KICK B, follow-up of M KICK A */
    {   91,    0,   40, 0x0000,    0,    1,    0,    1 },  /* 137: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   91,    0,   41, 0x0000,    0,    1,    0,    1 },  /* 138: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   91,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 139: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   92,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 140: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    {   93,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 141: L KICK B, follow-up of M KICK A */
    {   94,    0,   42, 0x0000,    0,    6,    0,    2 },  /* 142: KAGAMI P A */
    {   94,    0,   42, 0x0000,    0,    6,   27,    2 },  /* 143: KAGAMI P A */
    {   94,    0,    0, 0x0000,    0,    6,    0,    2 },  /* 144: KAGAMI P A */
    {   95,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 145: KAGAMI P A */
    {   96,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 146: KAGAMI P A */
    {   96,    0,   43, 0x0000,    0,    2,   28,    2 },  /* 147: KAGAMI P A */
    {   96,    0,   43, 0x0000,    0,    2,   29,    2 },  /* 148: KAGAMI P A */
    {   96,    0,   43, 0x0000,    0,    2,    0,    2 },  /* 149: KAGAMI P A */
    {    2,    0,   44, 0x0000,    0,    2,    0,    2 },  /* 150: KAGAMI P A */
    {   97,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 151: KAGAMI P A */
    {   98,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 152: KAGAMI P A */
    {   99,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 153: KAGAMI P A */
    {  100,    0,   45, 0x0000,    0,    2,   30,    2 },  /* 154: KAGAMI P A */
    {  101,    0,   46, 0x0000,    0,    2,   31,    2 },  /* 155: KAGAMI P A */
    {  102,    0,   47, 0x0000,    0,    2,   32,    2 },  /* 156: KAGAMI P A */
    {  102,    0,   47, 0x0000,    0,    2,    0,    2 },  /* 157: KAGAMI P A */
    {  103,    0,   48, 0x0000,    0,    2,    0,    2 },  /* 158: KAGAMI P A */
    {  104,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 159: KAGAMI P A */
    {  105,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 160: F JUMP P S A */
    {  106,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 161: F JUMP P S A */
    {  107,    0,   49, 0x0000,    0,    3,   33,    3 },  /* 162: F JUMP P S A */
    {  108,    0,   50, 0x0000,    0,    3,    0,    3 },  /* 163: F JUMP P S A */
    {  108,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 164: F JUMP P S A */
    {  109,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 165: F JUMP P M A */
    {  110,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 166: F JUMP P M A */
    {  111,    0,   51, 0x0000,    0,    3,   34,    3 },  /* 167: F JUMP P M A */
    {  112,    0,   52, 0x0000,    0,    3,    0,    3 },  /* 168: F JUMP P M A */
    {  112,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 169: F JUMP P M A */
    {  113,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 170: F JUMP P L A */
    {  114,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 171: F JUMP P L A, ATTACK 10 SP: not started by a command */
    {  115,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 172: F JUMP P L A, ATTACK 10 SP: not started by a command */
    {  116,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 173: F JUMP P L A, ATTACK 10 SP: not started by a command */
    {  117,    0,   53, 0x0000,    0,    3,   35,    3 },  /* 174: F JUMP P L A */
    {  117,    0,   54, 0x0000,    0,    3,   36,    3 },  /* 175: F JUMP P L A */
    {  117,    0,   54, 0x0000,    0,    3,    0,    3 },  /* 176: F JUMP P L A */
    {  118,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 177: F JUMP P L A */
    {  119,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 178: F JUMP P L A */
    {  120,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 179: F JUMP P L A */
    {  121,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 180: F JUMP K S A */
    {  122,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 181: F JUMP K S A */
    {  123,    0,    0, 0x0000,    0,    3,   37,    3 },  /* 182: F JUMP K S A */
    {  124,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 183: F JUMP K S A */
    {  125,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 184: F JUMP K S A */
    {  126,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 185: F JUMP K M A */
    {  127,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 186: F JUMP K M A */
    {  128,    0,   55, 0x0000,    0,    3,   38,    3 },  /* 187: F JUMP K M A */
    {  128,    0,   55, 0x0000,    0,    3,   39,    3 },  /* 188: F JUMP K M A */
    {  128,    0,   55, 0x0000,    0,    3,    0,    3 },  /* 189: F JUMP K M A */
    {  128,    0,   56, 0x0000,    0,    3,    0,    3 },  /* 190: F JUMP K M A */
    {  129,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 191: F JUMP K M A */
    {  130,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 192: F JUMP K L A */
    {  131,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 193: F JUMP K L A */
    {  132,    0,   57, 0x0000,    0,    3,   40,    3 },  /* 194: F JUMP K L A */
    {  132,    0,   58, 0x0000,    0,    3,   41,    3 },  /* 195: F JUMP K L A */
    {  132,    0,   58, 0x0000,    0,    3,    0,    3 },  /* 196: F JUMP K L A */
    {  133,    0,   59, 0x0000,    0,    3,    0,    3 },  /* 197: F JUMP K L A */
    {  134,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 198: F JUMP K L A */
    {  135,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 199: F JUMP K L A */
    {  136,    0,    0, 0x0000,    0,    6,    0,    2 },  /* 200: KAGAMI K A */
    {  137,    0,   60, 0x0000,    0,    6,   42,    2 },  /* 201: KAGAMI K A */
    {  137,    0,   60, 0x0000,    0,    6,    0,    2 },  /* 202: KAGAMI K A */
    {  138,    0,    0, 0x0000,    0,    6,    0,    2 },  /* 203: KAGAMI K A */
    {  139,    0,    0, 0x0000,    0,    6,    0,    2 },  /* 204: KAGAMI K A */
    {  140,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 205: KAGAMI K A */
    {  141,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 206: KAGAMI K A */
    {  142,    0,   61, 0x0000,    0,    2,   43,    2 },  /* 207: KAGAMI K A */
    {  142,    0,   62, 0x0000,    0,    2,   43,    2 },  /* 208: KAGAMI K A */
    {  142,    0,   62, 0x0000,    0,    2,    0,    2 },  /* 209: KAGAMI K A */
    {  143,    0,   63, 0x0000,    0,    2,    0,    2 },  /* 210: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    {  144,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 211: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    {  145,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 212: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    {  146,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 213: not used by a script */
    {  147,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 214: KAGAMI K A */
    {  148,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 215: KAGAMI K A */
    {  149,    0,   64, 0x0000,    0,    2,    0,    2 },  /* 216: KAGAMI K A */
    {  149,    0,   64, 0x0000,    0,    2,   44,    2 },  /* 217: KAGAMI K A */
    {  149,    0,   65, 0x0000,    0,    2,    0,    2 },  /* 218: KAGAMI K A */
    {  150,    0,   66, 0x0000,    0,    2,    0,    2 },  /* 219: KAGAMI K A */
    {  151,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 220: KAGAMI K A */
    {  152,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 221: KAGAMI K A */
    {  153,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 222: KAGAMI K A */
    {  154,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 223: KAGAMI K A */
    {  155,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 224: KAGAMI K A */
    {  156,    0,   67, 0x0000,    0,    2,   45,    2 },  /* 225: KAGAMI K A */
    {  156,    0,   67, 0x0000,    0,    2,   46,    2 },  /* 226: KAGAMI K A */
    {  156,    0,   68, 0x0000,    0,    2,    0,    2 },  /* 227: KAGAMI K A */
    {  157,    0,    0, 0x0000,    0,    2,    0,    2 },  /* 228: KAGAMI K A */
    {  158,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 229: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    {  159,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 230: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    {  160,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 231: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    {  161,    0,    0, 0x0000,    0,    1,    0,    7 },  /* 232: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    {  162,    0,   69, 0x0000,    0,    1,    0,    7 },  /* 233: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script) +2 */
    {  163,    0,   70, 0x0000,    0,    1,    0,    1 },  /* 234: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    {  163,    0,   71, 0x0000,    0,    1,    0,    1 },  /* 235: ATTACK 4 M: [4]6+P light (plain script) */
    {  163,    0,   72, 0x0000,    0,    1,    0,    1 },  /* 236: ATTACK 4 M: [4]6+P light (plain script) */
    {  163,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 237: ATTACK 4 M: [4]6+P light (plain script) */
    {  163,    0,   73, 0x0000,    0,    1,    0,    1 },  /* 238: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    {  163,    0,   74, 0x0000,    0,    1,    0,    1 },  /* 239: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    {  164,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 240: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    {  165,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 241: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    {  166,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 242: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    {  167,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 243: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    {  168,    0,    0, 0x0000,    0,    1,    0,    8 },  /* 244: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    {  169,    0,   75, 0x0000,    0,    1,    0,    8 },  /* 245: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    {  170,    0,   76, 0x0000,    0,    1,    0,    8 },  /* 246: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    {  171,    0,   77, 0x0000,    0,    1,    0,    8 },  /* 247: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    {  172,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 248: ATTACK 5 M: [4]6+K light (plain script) */
    {  173,    0,    0, 0x0000,    0,    1,    0,    6 },  /* 249: ATTACK 5 M: [4]6+K light (plain script) */
    {  174,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 250: ATTACK 5 M: [4]6+K light (plain script) */
    {  175,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 251: ATTACK 5 M: [4]6+K light (plain script) */
    {  176,    0,   78, 0x0000,    0,    1,    0,    6 },  /* 252: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    {  177,    0,   79, 0x0000,    0,    1,    0,    6 },  /* 253: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    {  178,    0,   80, 0x0000,    0,    1,    0,    6 },  /* 254: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    {  179,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 255: ATTACK 1 S: SA I 23623+P (plain script) */
    {  180,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 256: ATTACK 1 S: SA I 23623+P (plain script) */
    {  181,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 257: ATTACK 1 S: SA I 23623+P (plain script) */
    {  182,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 258: ATTACK 1 S: SA I 23623+P (plain script) */
    {  183,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 259: ATTACK 1 S: SA I 23623+P (plain script) */
    {  184,    0,   81, 0x0000,    0,    1,    0,    1 },  /* 260: ATTACK 1 S: SA I 23623+P (plain script) */
    {  185,    0,   82, 0x0000,    0,    1,    0,    1 },  /* 261: ATTACK 1 S: SA I 23623+P (plain script) */
    {  186,    0,   83, 0x0000,    0,    1,    0,    1 },  /* 262: ATTACK 1 S: SA I 23623+P (plain script) */
    {  187,    0,   84, 0x0000,    0,    1,    0,    1 },  /* 263: ATTACK 1 S: SA I 23623+P (plain script) */
    {  188,    0,   85, 0x0000,    0,    1,    0,    1 },  /* 264: ATTACK 1 S: SA I 23623+P (plain script) */
    {  189,    0,   86, 0x0000,    0,    1,    0,    1 },  /* 265: ATTACK 1 S: SA I 23623+P (plain script) */
    {  190,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 266: ATTACK 1 S: SA I 23623+P (plain script) */
    {  191,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 267: ATTACK 3 S: not started by a command */
    {  192,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 268: ATTACK 3 S: not started by a command */
    {  193,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 269: ATTACK 3 S: not started by a command */
    {  194,    0,   87, 0x0000,    0,    3,   47,    3 },  /* 270: ATTACK 3 S: not started by a command */
    {  195,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 271: ATTACK 3 S: not started by a command */
    {  196,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 272: ATTACK 3 S: not started by a command */
    {  197,    0,    0, 0x0000,    0,    0,    0,    9 },  /* 273: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +1 */
    {  197,    0,   88, 0x0000,    0,    0,   48,    9 },  /* 274: not used by a script */
    {  198,    0,   89, 0x0000,    0,    5,   49,   10 },  /* 275: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1) */
    {  199,    0,   90, 0x0000,    0,    3,   50,    3 },  /* 276: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1) */
    {  200,    0,   91, 0x0000,    0,    3,    0,    3 },  /* 277: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    {  201,    0,   92, 0x0000,    0,    3,    0,    3 },  /* 278: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    {  202,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 279: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    {  203,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 280: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    {  204,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 281: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    {  197,    0,   93, 0x0000,    0,    0,   51,    9 },  /* 282: not used by a script */
    {  198,    0,   94, 0x0000,    0,    5,   52,   10 },  /* 283: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    {  199,    0,   95, 0x0000,    0,    3,   53,    3 },  /* 284: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    {  197,    0,   96, 0x0000,    0,    0,   54,    9 },  /* 285: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    {  198,    0,   97, 0x0000,    0,    5,   55,   10 },  /* 286: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    {  199,    0,   98, 0x0000,    0,    3,   56,    3 },  /* 287: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    {    0,    0,    0, 0x0000,    0,    0,   57,    9 },  /* 288: not used by a script */
    {    0,    0,    0, 0x0000,    0,    5,   58,   10 },  /* 289: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) */
    {  199,    0,  101, 0x0000,    0,    3,   59,    3 },  /* 290: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) */
    {    0,    0,    0, 0x0000,    0,    0,    0,    1 },  /* 291: follow-up of CATCH 2, ATTACK 1 S: SA I 23623+P (plain script), ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) +5 */
    {  205,    0,    0, 0x0000,    0,    1,    0,    2 },  /* 292: follow-up of APPEAR 2, follow-up of SP APPEAR 5, follow-up of SP APPEAR 6 +4 */
    {    0,    0,    0, 0x0000,    0,    0,    0,    2 },  /* 293: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1), ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    {  226,    0,  102, 0x0000,    0,    3,    0,    3 },  /* 294: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    {  227,    0,  103, 0x0000,    0,    3,    0,    3 },  /* 295: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    {  228,    0,  104, 0x0000,    0,    3,    0,    3 },  /* 296: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  229,    0,  105, 0x0000,    0,    3,    0,    3 },  /* 297: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  230,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 298: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  231,    0,  106, 0x0000,    0,    3,    0,    3 },  /* 299: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  232,    0,  107, 0x0000,    0,    3,   60,    3 },  /* 300: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  232,    0,  108, 0x0000,    0,    3,   61,    3 },  /* 301: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    {  232,    0,  109, 0x0000,    0,    3,   62,    3 },  /* 302: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    {  233,    0,  110, 0x0000,    0,    1,    0,    1 },  /* 303: ATTACK 7 L: SA III 23623+K (plain script) */
    {  234,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 304: ATTACK 7 L: SA III 23623+K (plain script) */
    {  235,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 305: ATTACK 10 L: not started by a command */
    {  236,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 306: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    {  237,    0,  112, 0x0000,    0,    1,   63,    1 },  /* 307: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    {  237,    0,  113, 0x0000,    0,    1,   64,    1 },  /* 308: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    {  237,    0,  114, 0x0000,    0,    1,   65,    1 },  /* 309: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    {  238,    0,  115, 0x0000,    0,    1,    0,    1 },  /* 310: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    {  239,    0,  116, 0x0000,    0,    1,    0,    1 },  /* 311: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    {  240,    0,  117, 0x0000,    0,    1,    0,    1 },  /* 312: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    {  241,    0,  118, 0x0000,    0,    1,    0,    1 },  /* 313: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    {  242,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 314: ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    {   84,    0,   34, 0x0000,    0,    1,    0,    1 },  /* 315: not used by a script */
    {  227,    0,  103, 0x0000,    0,    3,   66,    3 },  /* 316: ATTACK 10 SP: not started by a command */
    {   84,    0,   34, 0x0000,    0,    1,   67,    1 },  /* 317: not used by a script */
    {   54,    0,   25, 0x0000,    0,    1,   68,    1 },  /* 318: ATTACK 9 S: after SA III 23623+K (plain script) */
    {  243,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 319: M KICK C */
    {  244,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 320: M KICK C */
    {  245,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 321: M KICK C */
    {  246,    0,  119, 0x0000,    0,    1,    0,    1 },  /* 322: M KICK C */
    {  247,    0,  120, 0x0000,    0,    1,    0,    1 },  /* 323: M KICK C */
    {  247,    0,  121, 0x0000,    0,    1,   69,    1 },  /* 324: M KICK C */
    {  248,    0,  122, 0x0000,    0,    1,   70,    1 },  /* 325: M KICK C */
    {  248,    0,  122, 0x0000,    0,    1,    0,    1 },  /* 326: M KICK C */
    {  249,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 327: M KICK C */
    {  250,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 328: M KICK C */
    {  251,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 329: M KICK C */
    {  252,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 330: M KICK C */
    {  253,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 331: M KICK C */
    {  206,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 332: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +1 */
    {  207,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 333: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1), ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1), ATTACK 9 M: after SA III 23623+K (plain script) +1 */
    {    0,    0,    0, 0x0000,    0,    0,   71,    1 },  /* 334: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    {  197,    0,   88, 0x0000,    0,    0,   71,    9 },  /* 335: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    {  198,    0,   89, 0x0000,    0,    5,   72,   10 },  /* 336: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    {  199,    0,   90, 0x0000,    0,    3,   73,    3 },  /* 337: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    {  254,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 338: AIR NORMAL, HARAYARARE */
    {  255,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 339: ASIBARAI SIRI */
    {  256,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 340: ASIBARAI SIRI */
    {  257,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 341: ASIBARAI SIRI */
    {  258,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 342: ASIBARAI SIRI */
    {  259,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 343: ASIBARAI SIRI */
    {  260,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 344: ASIB TUNNOMERI, HUMI ASIB */
    {  261,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 345: ASIB TUNNOMERI, HUMI ASIB */
    {  262,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 346: ASIB TUNNOMERI, HUMI ASIB */
    {  263,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 347: NOKEZORI, FACE, BODY UPPER SP */
    {  264,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 348: NOKEZORI, UPPER, FACE +2 */
    {  265,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 349: NOKEZORI, UPPER, BODY UPPER +3 */
    {  266,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 350: NOKEZORI, UPPER, BODY UPPER +3 */
    {  267,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 351: NOKEZORI, UPPER, BODY UPPER +4 */
    {  268,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 352: NOKEZORI, UPPER, BODY UPPER +4 */
    {  269,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 353: NOKEZORI, UPPER, BODY UPPER +4 */
    {  270,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 354: NOKEZORI, UPPER, BODY UPPER +4 */
    {  271,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 355: KUNOJI, BODY UPPER, KUNOJI NOKE */
    {  272,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 356: KUNOJI, KUNOJI NOKE */
    {  273,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 357: KIRIMOMI */
    {  274,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 358: KIRIMOMI */
    {  275,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 359: KIRIMOMI */
    {  276,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 360: KIRIMOMI */
    {  277,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 361: KIRIMOMI */
    {  278,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 362: KIRIMOMI */
    {  279,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 363: KIRIMOMI */
    {  280,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 364: KIRIMOMI */
    {  281,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 365: KIRIMOMI */
    {  282,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 366: KIRIMOMI */
    {  283,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 367: KIRIMOMI */
    {  284,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 368: KIRIMOMI */
    {  285,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 369: UPPER, TATUMAKIZANKU */
    {  286,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 370: UPPER, TATUMAKIZANKU */
    {  287,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 371: UPPER, TATUMAKIZANKU */
    {  288,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 372: BODY UPPER, HANEKAERI HARA */
    {  289,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 373: BODY UPPER, HARAYARARE, HANEKAERI HARA */
    {  290,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 374: BODY UPPER */
    {  291,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 375: TATAKI AIR, TTKI V. AIR */
    {  292,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 376: TATAKI AIR, TTKI V. AIR */
    {  293,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 377: TATAKI AIR, TTKI V. AIR */
    {  294,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 378: TATAKI AIR, TTKI V. AIR */
    {  295,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 379: FACE, TOUKETSU A */
    {  296,    0,    0, 0x0000,    0,    4,    0,    4 },  /* 380: DENKI */
    {   91,    0,   39, 0x0000,    0,    1,   74,    1 },  /* 381: ATTACK 9 S: after SA III 23623+K (plain script) */
    {  297,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 382: follow-up of KAMAE */
    {  298,    0,    0, 0x1010,    0,    1,    0,    1 },  /* 383: follow-up of KAMAE */
    {  299,    0,    0, 0x0000,    0,    0,    0,    9 },  /* 384: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  299,    0,  124, 0x0000,    0,    0,   75,    9 },  /* 385: not used by a script */
    {  300,    0,  125, 0x0000,    0,    5,   76,   10 },  /* 386: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  301,    0,  126, 0x0000,    0,    3,   77,    3 },  /* 387: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  302,    0,  127, 0x0000,    0,    3,    0,    3 },  /* 388: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  303,    0,  128, 0x0000,    0,    3,    0,    3 },  /* 389: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  304,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 390: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  305,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 391: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  306,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 392: ATTACK 9 M: after SA III 23623+K (plain script) */
    {  307,    0,    0, 0x0000,    0,    3,    0,    3 },  /* 393: ATTACK 9 M: after SA III 23623+K (plain script) */
    {   85,    0,   35, 0x0000,    0,    1,   78,    1 },  /* 394: ATTACK 9 S: after SA III 23623+K (plain script) */
    {  308,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 395: TUKAMIHAZUSARE, TUKAMIKAKARI A, TUKAMIKAKARI B +1 */
    {  309,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 396: TUKAMIKAKARI A */
    {  310,    0,  129, 0x0000,    0,    1,    0,    1 },  /* 397: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  311,    0,  130, 0x0000,    0,    1,    0,    1 },  /* 398: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  310,    0,    0, 0x0000,    0,    1,    0,    1 },  /* 399: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    {  312,    0,  131, 0x0000,    0,    1,    0,    1 },  /* 400: TUKAMIHAZUSARE */
};

const BODY_BOX remy_body_box[313] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +62 */
    { { {  -29,  26,  47,  20 },  {  -26,  43,  35,  19 },  {  -40,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +29 */
    { { {  -10,  23,  97,  19 },  {  -19,  48,  80,  18 },  {  -22,  46,  41,  38 },  {  -31,  55,   0,  40 } } },  /* 3: follow-up of KAMAE */
    { { {  -28,  23,  95,  19 },  {  -34,  48,  77,  18 },  {  -29,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 4: HURIMUKI */
    { { {  -15,  24,  99,  19 },  {  -21,  43,  80,  18 },  {  -22,  46,  25,  55 },  {  -23,  47,   0,  24 } } },  /* 5: FRONT WALK */
    { { {  -16,  24, 100,  19 },  {  -21,  43,  81,  18 },  {  -22,  46,  25,  55 },  {  -22,  46,   0,  24 } } },  /* 6: FRONT WALK */
    { { {  -14,  24,  98,  19 },  {  -19,  43,  81,  18 },  {  -24,  46,  25,  55 },  {  -47,  76,   0,  24 } } },  /* 7: FRONT WALK, BACK WALK */
    { { {  -15,  24, 100,  19 },  {  -21,  45,  81,  18 },  {  -22,  46,  25,  55 },  {  -23,  47,   0,  24 } } },  /* 8: FRONT WALK, BACK WALK */
    { { {  -17,  24,  98,  19 },  {  -21,  47,  81,  18 },  {  -24,  46,  25,  55 },  {  -40,  68,   0,  24 } } },  /* 9: FRONT WALK, BACK WALK */
    { { {  -13,  24,  99,  19 },  {  -21,  43,  80,  18 },  {  -22,  46,  25,  55 },  {  -23,  47,   0,  24 } } },  /* 10: BACK WALK */
    { { {  -16,  24, 100,  19 },  {  -21,  43,  81,  18 },  {  -22,  46,  25,  55 },  {  -22,  46,   0,  24 } } },  /* 11: BACK WALK */
    { { {  -34,  24,  82,  20 },  {  -22,  51,  73,  18 },  {  -32,  66,  45,  27 },  {  -43, 101,   0,  44 } } },  /* 12: DASH HUMIKOMI */
    { { {  -27,  23,  81,  20 },  {  -16,  44,  74,  18 },  {  -22,  46,  41,  32 },  {  -37,  74,   0,  40 } } },  /* 13: DASH HUMIKOMI */
    { { {  -10,  23,  86,  19 },  {  -19,  48,  71,  18 },  {  -22,  46,  37,  33 },  {  -28,  55,   0,  36 } } },  /* 14: DASH HUMIKOMI */
    { { {  -10,  23, 101,  19 },  {  -16,  48,  87,  18 },  {  -20,  47,  41,  45 },  {  -38,  59,   0,  40 } } },  /* 15: DASH TOBINOKI */
    { { {  -13,  23, 103,  19 },  {  -18,  48,  88,  18 },  {  -20,  46,  41,  46 },  {  -22,  58,   0,  40 } } },  /* 16: DASH TOBINOKI */
    { { {  -11,  23,  88,  19 },  {  -19,  48,  73,  18 },  {  -22,  46,  41,  31 },  {  -31,  55,   0,  40 } } },  /* 17: KAGAMU */
    { { {  -35,  26,  42,  20 },  {  -29,  43,  35,  20 },  {  -42,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 18: KAGAMU */
    { { {  -22,  26,  49,  20 },  {  -21,  45,  36,  20 },  {  -37,  63,  21,  14 },  {  -42,  69,   0,  21 } } },  /* 19: KAGAMI KAMAE */
    { { {  -39,  25,  46,  20 },  {  -47,  44,  35,  19 },  {  -50,  62,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 20: KAGAMI TURN */
    { { {  -38,  25,  47,  20 },  {  -35,  44,  35,  20 },  {  -44,  60,  21,  30 },  {  -42,  69,   0,  21 } } },  /* 21: KAGAMI TURN */
    { { {  -24,  24,  72,  19 },  {  -22,  42,  60,  19 },  {  -25,  47,  38,  21 },  {  -33,  57,   0,  37 } } },  /* 22: STAND UP, KAGAMU, JUMP JUNBI +5 */
    { { {  -23,  23, 105,  20 },  {  -22,  48,  95,  19 },  {  -21,  51,  69,  25 },  {  -19,  44,  49,  19 } } },  /* 23: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    { { {  -33,  23,  92,  20 },  {  -22,  51,  91,  19 },  {  -26,  45,  69,  25 },  {  -32,  57,  54,  14 } } },  /* 24: JUMP FRONT, JUMP VERTICAL, JUMP BACK +4 */
    { { {  -18,  23, 105,  20 },  {  -19,  48,  94,  19 },  {  -20,  51,  69,  25 },  {  -31,  54,  49,  19 } } },  /* 25: JUMP FRONT, JUMP VERTICAL, JUMP BACK +9 */
    { { {  -22,  23,  73,  19 },  {  -27,  51,  66,  18 },  {  -29,  55,  37,  28 },  {  -45,  74,   0,  36 } } },  /* 26: PIYO */
    { { {  -24,  23,  87,  19 },  {  -27,  51,  81,  18 },  {  -33,  54,  58,  22 },  {  -35,  52,  39,  18 } } },  /* 27: AIR NORMAL, BODY SLAM, IPPONZEOI +9 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -31,  52,   0,  26 },  {    0,   0,   0,   0 } } },  /* 28: no name */
    { { {    6,  23,  98,  19 },  {  -15,  48,  77,  18 },  {  -23,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 29: UPPER L */
    { { {   14,  23,  97,  19 },  {  -12,  48,  77,  18 },  {  -24,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 30: UPPER L */
    { { {   18,  23,  96,  19 },  {  -10,  48,  77,  18 },  {  -25,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 31: UPPER L */
    { { {   20,  23,  95,  19 },  {   -9,  48,  77,  18 },  {  -26,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 32: UPPER L */
    { { {    6,  23,  92,  19 },  {  -11,  48,  76,  18 },  {  -18,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 33: FACE S, FACE M, FACE L +3 */
    { { {   18,  23,  90,  19 },  {   -5,  48,  75,  18 },  {  -15,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 34: FACE M, FACE L, FOOK OKU L +1 */
    { { {   26,  23,  88,  19 },  {   -1,  48,  74,  18 },  {  -13,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 35: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {   30,  23,  86,  19 },  {    1,  48,  73,  18 },  {  -12,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 36: FACE L, FOOK OKU L, FOOK TEMAE L */
    { { {  -14,  23,  91,  19 },  {  -17,  48,  75,  18 },  {  -20,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 37: NOUTEN M, NOUTEN L, NOUTEN S +3 */
    { { {  -18,  23,  88,  19 },  {  -15,  48,  73,  18 },  {  -18,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 38: NOUTEN M, NOUTEN L, BODY BROW M +2 */
    { { {  -22,  23,  85,  19 },  {  -13,  48,  71,  18 },  {  -16,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 39: NOUTEN L, BODY BROW L, BODY UPPER L */
    { { {  -26,  23,  82,  19 },  {  -11,  48,  69,  18 },  {  -14,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 40: NOUTEN L, BODY BROW L, BODY UPPER L +8 */
    { { {  -23,  26,  47,  20 },  {  -24,  43,  35,  20 },  {  -39,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 41: TATAKI S, TATAKI M, TATAKI L +19 */
    { { {  -17,  26,  47,  20 },  {  -22,  43,  35,  20 },  {  -38,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 42: KAGAMI M, KAGAMI L, KGM TOUKETU M +1 */
    { { {  -11,  26,  47,  20 },  {  -20,  43,  35,  20 },  {  -37,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 43: KAGAMI L, KGM TOUKETU L */
    { { {   -5,  26,  47,  20 },  {  -18,  43,  35,  20 },  {  -36,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 44: KAGAMI L */
    { { {  -19,  23,  94,  19 },  {  -26,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 45: S PUNCH A */
    { { {  -15,  23,  94,  19 },  {  -25,  48,  80,  18 },  {  -25,  51,  41,  38 },  {  -31,  55,   0,  41 } } },  /* 46: S PUNCH B, ATTACK 10 SP: not started by a command */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  67,   0,  40 } } },  /* 47: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -10,  23,  94,  19 },  {  -13,  40,  77,  18 },  {  -22,  46,  41,  35 },  {  -25,  67,   0,  41 } } },  /* 48: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -15,  23,  90,  19 },  {  -16,  40,  74,  18 },  {  -13,  46,  41,  35 },  {  -21,  68,   0,  41 } } },  /* 49: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -27,  29,  82,  21 },  {  -21,  53,  75,  17 },  {  -14,  55,  41,  35 },  {  -21,  68,   0,  41 } } },  /* 50: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -19,  29,  88,  21 },  {  -18,  46,  75,  17 },  {  -19,  47,  41,  35 },  {  -21,  68,   0,  41 } } },  /* 51: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -10,  23,  94,  19 },  {  -38,  61,  76,  19 },  {  -22,  46,  41,  35 },  {  -28,  64,   0,  42 } } },  /* 52: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -22,  23,  94,  19 },  {  -24,  48,  77,  18 },  {  -23,  46,  41,  35 },  {  -28,  64,   0,  42 } } },  /* 53: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -28,  27,  94,  19 },  {  -33,  46,  77,  18 },  {  -23,  52,  41,  37 },  {  -24,  70,   0,  42 } } },  /* 54: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 55: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -17,  27,  94,  19 },  {  -35,  59,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 56: L PUNCH A */
    { { {  -10,  23,  90,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -28,  63,   0,  41 } } },  /* 57: L PUNCH A */
    { { {  -16,  24,  91,  21 },  {  -22,  51,  76,  20 },  {  -22,  46,  41,  35 },  {  -28,  63,   0,  41 } } },  /* 58: L PUNCH A */
    { { {   -3,  29,  96,  24 },  {  -22,  37,  87,  25 },  {  -22,  46,  54,  35 },  {  -24,  57,   0,  54 } } },  /* 59: L PUNCH A */
    { { {  -10,  24,  94,  24 },  {  -19,  48,  80,  20 },  {  -22,  46,  44,  36 },  {  -31,  55,   0,  44 } } },  /* 60: L PUNCH A */
    { { {  -11,  23,  89,  19 },  {  -24,  48,  75,  18 },  {  -28,  46,  48,  28 },  {  -37,  62,   0,  49 } } },  /* 61: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   -5,  23,  87,  19 },  {  -14,  47,  71,  18 },  {  -25,  46,  47,  27 },  {  -37,  76,   0,  49 } } },  /* 62: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   -5,  23,  87,  19 },  {  -13,  59,  73,  21 },  {  -17,  52,  46,  29 },  {  -37,  85,   0,  49 } } },  /* 63: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -21,  26,  74,  20 },  {  -25,  63,  60,  19 },  {  -22,  46,  41,  22 },  {  -38,  95,   0,  41 } } },  /* 64: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   -7,  26,  83,  20 },  {  -16,  49,  68,  19 },  {  -22,  61,  41,  27 },  {  -39,  85,   0,  45 } } },  /* 65: L PUNCH B */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 66: L PUNCH B */
    { { {  -19,  23,  94,  19 },  {  -25,  48,  77,  18 },  {  -22,  46,  40,  36 },  {  -25,  60,   0,  40 } } },  /* 67: S KICK A */
    { { {  -10,  23,  94,  19 },  {  -23,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -19,  61,   0,  41 } } },  /* 68: S KICK A */
    { { {   -9,  25,  94,  22 },  {  -16,  48,  81,  18 },  {  -18,  36,  58,  25 },  {  -18,  31,   0,  59 } } },  /* 69: S KICK A */
    { { {  -14,  25,  94,  23 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 70: S KICK A */
    { { {  -11,  25,  93,  19 },  {  -12,  48,  77,  18 },  {  -17,  53,  57,  21 },  {  -36,  57,   0,  60 } } },  /* 71: S KICK B */
    { { {   -4,  25,  93,  19 },  {  -12,  48,  77,  18 },  {  -17,  53,  57,  21 },  {  -36,  57,   0,  60 } } },  /* 72: S KICK B */
    { { {   -7,  25,  93,  19 },  {  -16,  48,  77,  18 },  {  -25,  53,  57,  21 },  {  -36,  57,   0,  60 } } },  /* 73: S KICK B */
    { { {  -19,  23,  94,  19 },  {  -25,  48,  77,  18 },  {  -22,  46,  40,  36 },  {  -25,  60,   0,  40 } } },  /* 74: M KICK A */
    { { {  -10,  23,  94,  19 },  {  -23,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -19,  61,   0,  41 } } },  /* 75: M KICK A */
    { { {   -9,  25,  94,  22 },  {  -16,  48,  81,  18 },  {  -18,  36,  58,  25 },  {  -18,  31,   0,  59 } } },  /* 76: M KICK A */
    { { {  -14,  25,  94,  23 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 77: M KICK A */
    { { {   -5,  26,  94,  19 },  {  -13,  48,  71,  24 },  {  -28,  47,  54,  20 },  {  -36,  54,   0,  54 } } },  /* 78: M KICK B */
    { { {    5,  29,  92,  20 },  {   -8,  52,  71,  24 },  {  -46,  63,  41,  30 },  {    2,  26,   0,  41 } } },  /* 79: M KICK B */
    { { {    7,  28,  86,  21 },  {   -6,  54,  70,  24 },  {  -26,  47,  51,  19 },  {   -2,  31,   0,  52 } } },  /* 80: M KICK B */
    { { {    5,  29,  92,  20 },  {   -8,  52,  71,  24 },  {  -36,  53,  52,  19 },  {   -3,  32,   0,  53 } } },  /* 81: M KICK B */
    { { {   -4,  26,  95,  20 },  {  -14,  52,  68,  27 },  {  -18,  38,  45,  24 },  {   -2,  25,   0,  46 } } },  /* 82: M KICK B */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -11,  35,   0,  42 } } },  /* 83: L KICK A */
    { { {    2,  23,  91,  19 },  {   -6,  41,  68,  24 },  {  -18,  38,  41,  35 },  {  -17,  37,   0,  42 } } },  /* 84: L KICK A */
    { { {   13,  23,  87,  19 },  {    0,  41,  72,  24 },  {  -16,  38,  39,  46 },  {  -16,  36,   0,  40 } } },  /* 85: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    4,  23,  93,  19 },  {   -6,  47,  70,  24 },  {  -27,  47,  41,  44 },  {  -17,  37,   0,  42 } } },  /* 86: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   -4,  23,  94,  19 },  {  -14,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 87: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    0,  25,  90,  19 },  {  -17,  41,  73,  18 },  {  -18,  47,  41,  33 },  {  -18,  65,   0,  41 } } },  /* 88: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    2,  25,  90,  19 },  {  -17,  46,  73,  18 },  {  -14,  49,  41,  33 },  {  -16,  56,   0,  41 } } },  /* 89: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    2,  27,  89,  23 },  {   -6,  48,  73,  18 },  {  -20,  42,  41,  33 },  {  -22,  45,   0,  42 } } },  /* 90: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {    0,  25,  91,  20 },  {   -6,  41,  77,  18 },  {  -22,  46,  56,  29 },  {  -20,  42,   0,  56 } } },  /* 91: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   -5,  23,  91,  19 },  {  -14,  48,  76,  17 },  {  -21,  53,  41,  35 },  {  -23,  55,   1,  40 } } },  /* 92: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 93: L KICK B, follow-up of M KICK A */
    { { {  -33,  26,  47,  20 },  {  -34,  56,  35,  19 },  {  -40,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 94: KAGAMI P A */
    { { {  -27,  26,  46,  20 },  {  -21,  47,  35,  19 },  {  -40,  68,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 95: KAGAMI P A */
    { { {  -27,  26,  46,  20 },  {  -26,  61,  35,  19 },  {  -32,  60,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 96: KAGAMI P A */
    { { {  -25,  27,  47,  21 },  {  -26,  47,  35,  19 },  {  -37,  62,  21,  14 },  {  -37,  63,   0,  21 } } },  /* 97: KAGAMI P A */
    { { {  -24,  27,  46,  21 },  {  -26,  50,  35,  19 },  {  -36,  60,  21,  14 },  {  -36,  65,   0,  21 } } },  /* 98: KAGAMI P A */
    { { {  -24,  27,  49,  21 },  {  -31,  62,  35,  21 },  {  -30,  57,  21,  14 },  {  -32,  66,   0,  21 } } },  /* 99: KAGAMI P A */
    { { {  -24,  27,  55,  21 },  {  -31,  62,  35,  21 },  {  -27,  54,  24,  12 },  {  -31,  67,   0,  26 } } },  /* 100: KAGAMI P A */
    { { {  -24,  27,  70,  21 },  {  -26,  46,  49,  21 },  {  -27,  58,  29,  21 },  {  -29,  67,   0,  29 } } },  /* 101: KAGAMI P A */
    { { {  -21,  27,  65,  21 },  {  -26,  46,  47,  19 },  {  -27,  58,  28,  19 },  {  -28,  68,   0,  28 } } },  /* 102: KAGAMI P A */
    { { {  -21,  27,  61,  21 },  {  -26,  46,  44,  19 },  {  -28,  57,  28,  16 },  {  -34,  69,   0,  28 } } },  /* 103: KAGAMI P A */
    { { {  -26,  27,  56,  21 },  {  -29,  46,  43,  19 },  {  -29,  55,  28,  16 },  {  -39,  68,   0,  32 } } },  /* 104: KAGAMI P A */
    { { {  -27,  23, 100,  20 },  {  -21,  44,  93,  23 },  {  -21,  42,  80,  13 },  {  -35,  51,  61,  20 } } },  /* 105: F JUMP P S A */
    { { {  -27,  23, 100,  20 },  {  -21,  44,  93,  23 },  {  -21,  42,  80,  13 },  {  -32,  51,  58,  21 } } },  /* 106: F JUMP P S A */
    { { {  -38,  25,  97,  24 },  {  -29,  47,  87,  31 },  {  -22,  40,  73,  16 },  {  -25,  44,  57,  17 } } },  /* 107: F JUMP P S A */
    { { {  -27,  23, 101,  21 },  {  -23,  46,  88,  26 },  {  -21,  42,  80,   8 },  {  -30,  48,  58,  21 } } },  /* 108: F JUMP P S A */
    { { {  -27,  23, 100,  20 },  {  -21,  44,  93,  23 },  {  -21,  42,  80,  13 },  {  -35,  51,  61,  20 } } },  /* 109: F JUMP P M A */
    { { {  -27,  23, 100,  20 },  {  -21,  44,  93,  23 },  {  -21,  42,  80,  13 },  {  -32,  51,  58,  21 } } },  /* 110: F JUMP P M A */
    { { {  -38,  25,  97,  24 },  {  -29,  47,  87,  31 },  {  -22,  40,  73,  16 },  {  -25,  44,  57,  17 } } },  /* 111: F JUMP P M A */
    { { {  -27,  23, 101,  21 },  {  -23,  46,  88,  26 },  {  -21,  42,  80,   8 },  {  -30,  48,  58,  21 } } },  /* 112: F JUMP P M A */
    { { {  -17,  23, 102,  20 },  {  -27,  45,  93,  20 },  {  -24,  40,  77,  16 },  {  -20,  39,  62,  15 } } },  /* 113: F JUMP P L A */
    { { {   -3,  23, 100,  20 },  {  -15,  51,  90,  21 },  {  -17,  48,  77,  16 },  {  -10,  43,  62,  15 } } },  /* 114: F JUMP P L A, ATTACK 10 SP: not started by a command */
    { { {    0,  23, 101,  20 },  {  -16,  59,  92,  23 },  {  -16,  46,  77,  16 },  {  -10,  44,  62,  15 } } },  /* 115: F JUMP P L A, ATTACK 10 SP: not started by a command */
    { { {   -9,  23, 101,  20 },  {  -20,  60,  92,  23 },  {  -19,  41,  78,  14 },  {  -10,  48,  62,  20 } } },  /* 116: F JUMP P L A, ATTACK 10 SP: not started by a command */
    { { {  -29,  23,  92,  20 },  {  -33,  67,  85,  22 },  {  -25,  42,  70,  19 },  {   -1,  44,  61,  26 } } },  /* 117: F JUMP P L A */
    { { {  -30,  26,  98,  21 },  {  -41,  68,  83,  20 },  {  -22,  41,  74,  15 },  {  -12,  36,  61,  14 } } },  /* 118: F JUMP P L A */
    { { {  -29,  23,  99,  20 },  {  -37,  47,  84,  23 },  {  -19,  40,  70,  22 },  {  -26,  43,  58,  14 } } },  /* 119: F JUMP P L A */
    { { {  -23,  23, 103,  20 },  {  -21,  42,  93,  20 },  {  -23,  45,  71,  25 },  {  -24,  43,  54,  18 } } },  /* 120: F JUMP P L A */
    { { {  -17,  23, 107,  20 },  {  -43,  72,  89,  19 },  {  -36,  55,  73,  18 },  {  -36,  51,  56,  17 } } },  /* 121: F JUMP K S A */
    { { {   -9,  23, 101,  20 },  {  -17,  48,  87,  21 },  {  -24,  42,  75,  16 },  {  -33,  45,  61,  25 } } },  /* 122: F JUMP K S A */
    { { {   -7,  23,  88,  20 },  {  -22,  46,  80,  23 },  {  -24,  49,  69,  14 },  {  -24,  48,  55,  14 } } },  /* 123: F JUMP K S A */
    { { {   -8,  23,  96,  20 },  {  -14,  38,  80,  22 },  {  -22,  46,  69,  14 },  {  -39,  58,  56,  19 } } },  /* 124: F JUMP K S A */
    { { {  -13,  23, 102,  20 },  {  -14,  48,  85,  23 },  {  -21,  42,  73,  14 },  {  -40,  54,  56,  20 } } },  /* 125: F JUMP K S A */
    { { {  -17,  23, 107,  20 },  {  -43,  72,  89,  19 },  {  -36,  55,  73,  18 },  {  -36,  51,  56,  17 } } },  /* 126: F JUMP K M A */
    { { {   -9,  23, 101,  20 },  {  -17,  48,  87,  21 },  {  -24,  42,  75,  16 },  {  -33,  45,  61,  25 } } },  /* 127: F JUMP K M A */
    { { {   -5,  23,  90,  20 },  {   -9,  41,  83,  28 },  {  -16,  41,  73,  16 },  {  -14,  42,  57,  15 } } },  /* 128: F JUMP K M A */
    { { {  -13,  23, 102,  20 },  {  -14,  48,  85,  23 },  {  -21,  42,  73,  14 },  {  -40,  54,  56,  20 } } },  /* 129: F JUMP K M A */
    { { {   -7,  23, 107,  20 },  {  -18,  48,  88,  21 },  {  -25,  44,  77,  16 },  {  -33,  55,  56,  24 } } },  /* 130: F JUMP K L A */
    { { {   -5,  23, 107,  20 },  {  -18,  48,  88,  21 },  {  -24,  44,  76,  16 },  {  -30,  55,  56,  24 } } },  /* 131: F JUMP K L A */
    { { {    1,  23,  99,  20 },  {  -11,  47,  88,  21 },  {  -14,  44,  76,  16 },  {  -24,  62,  58,  23 } } },  /* 132: F JUMP K L A */
    { { {   -5,  23, 106,  20 },  {   -9,  41,  91,  19 },  {  -22,  43,  76,  16 },  {  -35,  52,  60,  20 } } },  /* 133: F JUMP K L A */
    { { {  -10,  23, 106,  20 },  {  -18,  46,  91,  21 },  {  -20,  41,  78,  16 },  {  -38,  53,  60,  21 } } },  /* 134: F JUMP K L A */
    { { {  -13,  23, 102,  20 },  {  -14,  44,  85,  23 },  {  -21,  42,  73,  14 },  {  -36,  51,  56,  20 } } },  /* 135: F JUMP K L A */
    { { {  -24,  26,  42,  20 },  {  -26,  43,  33,  19 },  {  -24,  61,  21,  13 },  {  -41,  63,   0,  21 } } },  /* 136: KAGAMI K A */
    { { {  -11,  26,  42,  20 },  {  -14,  43,  33,  19 },  {  -16,  47,  21,  13 },  {  -30,  63,   0,  21 } } },  /* 137: KAGAMI K A */
    { { {  -38,  26,  46,  20 },  {  -35,  43,  35,  19 },  {  -42,  61,  21,  13 },  {  -45,  69,   0,  21 } } },  /* 138: KAGAMI K A */
    { { {  -29,  26,  47,  20 },  {  -26,  43,  35,  19 },  {  -40,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 139: KAGAMI K A */
    { { {  -22,  26,  52,  20 },  {  -35,  57,  35,  19 },  {  -36,  61,  21,  13 },  {  -36,  72,   0,  21 } } },  /* 140: KAGAMI K A */
    { { {   -1,  26,  49,  20 },  {   -7,  43,  34,  19 },  {  -11,  56,  21,  13 },  {  -24,  69,   0,  21 } } },  /* 141: KAGAMI K A */
    { { {    8,  26,  46,  20 },  {   -7,  46,  32,  20 },  {  -17,  58,  14,  20 },  {  -17,  63,   0,  14 } } },  /* 142: KAGAMI K A */
    { { {    2,  26,  46,  20 },  {   -8,  46,  32,  20 },  {  -20,  58,  14,  20 },  {  -22,  63,   0,  14 } } },  /* 143: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    { { {  -14,  26,  49,  20 },  {  -20,  45,  35,  19 },  {  -27,  56,  21,  13 },  {  -37,  71,   0,  21 } } },  /* 144: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    { { {  -29,  26,  47,  20 },  {  -26,  43,  35,  19 },  {  -40,  61,  21,  13 },  {  -42,  69,   0,  21 } } },  /* 145: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    { { {  -24,  26,  43,  20 },  {  -39,  56,  33,  19 },  {  -33,  57,  21,  12 },  {  -33,  69,   0,  21 } } },  /* 146: not used by a script */
    { { {  -12,  26,  43,  20 },  {  -29,  56,  33,  19 },  {  -17,  57,  21,  12 },  {  -33,  69,   0,  21 } } },  /* 147: KAGAMI K A */
    { { {   -3,  26,  41,  20 },  {  -17,  51,  30,  27 },  {  -17,  57,  21,  12 },  {  -29,  71,   0,  21 } } },  /* 148: KAGAMI K A */
    { { {    0,  26,  39,  20 },  {   -9,  48,  32,  23 },  {  -16,  56,  21,  18 },  {  -17,  71,   0,  21 } } },  /* 149: KAGAMI K A */
    { { {   10,  27,  37,  21 },  {   -5,  42,  30,  32 },  {  -17,  57,  24,  13 },  {  -27,  74,   0,  28 } } },  /* 150: KAGAMI K A */
    { { {   14,  27,  37,  21 },  {  -15,  47,  30,  25 },  {  -25,  63,  24,  13 },  {  -27,  74,   0,  26 } } },  /* 151: KAGAMI K A */
    { { {   14,  27,  39,  21 },  {   -6,  47,  30,  22 },  {  -22,  64,  24,  13 },  {  -24,  78,   0,  26 } } },  /* 152: KAGAMI K A */
    { { {    6,  27,  43,  21 },  {  -11,  49,  30,  22 },  {  -18,  64,  23,  13 },  {  -24,  78,   0,  26 } } },  /* 153: KAGAMI K A */
    { { {    3,  27,  44,  21 },  {  -23,  56,  34,  22 },  {  -24,  58,  23,  13 },  {  -24,  78,   0,  26 } } },  /* 154: KAGAMI K A */
    { { {    5,  27,  42,  21 },  {  -23,  56,  34,  19 },  {  -23,  61,  23,  13 },  {  -22,  78,   0,  26 } } },  /* 155: KAGAMI K A */
    { { {    6,  27,  42,  21 },  {   -7,  44,  27,  24 },  {  -18,  57,  20,  14 },  {  -27,  72,   0,  28 } } },  /* 156: KAGAMI K A */
    { { {  -14,  26,  48,  20 },  {  -18,  43,  35,  19 },  {  -25,  54,  21,  13 },  {  -35,  69,   0,  21 } } },  /* 157: KAGAMI K A */
    { { {  -15,  23,  92,  19 },  {  -22,  48,  76,  21 },  {  -28,  48,  41,  35 },  {  -34,  59,   0,  41 } } },  /* 158: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    { { {  -11,  23,  90,  19 },  {  -15,  50,  74,  21 },  {  -29,  52,  41,  33 },  {  -34,  65,   0,  41 } } },  /* 159: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    { { {   -8,  23,  89,  19 },  {  -12,  50,  72,  21 },  {  -26,  52,  41,  32 },  {  -34,  65,   0,  41 } } },  /* 160: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    { { {  -11,  23,  89,  19 },  {  -26,  57,  72,  21 },  {  -30,  52,  41,  31 },  {  -33,  66,   0,  42 } } },  /* 161: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +1 */
    { { {   -6,  23,  86,  19 },  {  -22,  54,  71,  24 },  {  -29,  52,  41,  31 },  {  -34,  71,   0,  42 } } },  /* 162: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script) +2 */
    { { {   -2,  23,  83,  21 },  {  -17,  48,  65,  25 },  {  -28,  51,  41,  25 },  {  -32,  71,   0,  41 } } },  /* 163: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    { { {   -7,  23,  87,  19 },  {  -21,  54,  74,  20 },  {  -26,  49,  41,  33 },  {  -31,  57,   0,  41 } } },  /* 164: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    { { {  -18,  23,  86,  19 },  {  -24,  50,  76,  19 },  {  -21,  45,  41,  35 },  {  -41,  67,   0,  41 } } },  /* 165: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {   -3,  23,  67,  19 },  {  -20,  57,  53,  19 },  {  -21,  55,  39,  14 },  {  -41,  84,   0,  40 } } },  /* 166: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {   -3,  23,  59,  19 },  {  -20,  57,  50,  19 },  {  -21,  55,  35,  16 },  {  -49,  95,   0,  35 } } },  /* 167: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {  -16,  23,  53,  19 },  {  -30,  72,  43,  18 },  {  -31,  61,  33,  11 },  {  -49,  95,   0,  34 } } },  /* 168: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {  -25,  23,  50,  19 },  {  -30,  72,  43,  18 },  {  -31,  57,  33,  11 },  {  -46, 101,   0,  34 } } },  /* 169: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {  -25,  23,  50,  19 },  {  -30,  72,  43,  18 },  {  -34,  63,  33,  11 },  {  -46, 101,   0,  34 } } },  /* 170: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -22,  23,  55,  19 },  {  -18,  54,  43,  26 },  {  -32,  76,  36,  10 },  {  -46, 101,   0,  39 } } },  /* 171: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -18,  23,  63,  19 },  {  -11,  45,  52,  30 },  {  -28,  62,  39,  13 },  {  -46, 101,   0,  43 } } },  /* 172: ATTACK 5 M: [4]6+K light (plain script) */
    { { {  -12,  23,  77,  19 },  {  -11,  46,  61,  24 },  {  -26,  62,  42,  19 },  {  -45,  93,   0,  42 } } },  /* 173: ATTACK 5 M: [4]6+K light (plain script) */
    { { {   -7,  23,  82,  19 },  {  -11,  46,  61,  24 },  {  -33,  64,  42,  19 },  {  -54,  93,   0,  42 } } },  /* 174: ATTACK 5 M: [4]6+K light (plain script) */
    { { {   -9,  23,  92,  19 },  {  -19,  48,  77,  18 },  {  -30,  55,  41,  35 },  {  -39,  64,   0,  40 } } },  /* 175: ATTACK 5 M: [4]6+K light (plain script) */
    { { {  -18,  23,  63,  19 },  {  -18,  51,  48,  27 },  {  -34,  76,  37,  11 },  {  -46, 101,   0,  39 } } },  /* 176: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -18,  23,  66,  19 },  {  -18,  51,  50,  25 },  {  -36,  78,  37,  13 },  {  -46, 101,   0,  39 } } },  /* 177: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -10,  23,  71,  19 },  {  -18,  46,  50,  25 },  {  -42,  79,  37,  13 },  {  -53, 101,   0,  39 } } },  /* 178: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -17,  23,  91,  19 },  {  -17,  41,  77,  18 },  {  -22,  46,  41,  35 },  {  -27,  52,   0,  40 } } },  /* 179: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -10,  23,  91,  19 },  {  -29,  60,  77,  15 },  {  -33,  58,  41,  35 },  {  -25,  55,   0,  40 } } },  /* 180: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   -6,  23,  90,  19 },  {  -15,  53,  77,  15 },  {  -32,  57,  41,  35 },  {  -36,  65,   0,  40 } } },  /* 181: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   -6,  23,  85,  19 },  {  -13,  55,  69,  23 },  {  -28,  54,  43,  26 },  {  -36,  66,   0,  43 } } },  /* 182: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -16,  23,  85,  19 },  {  -16,  58,  69,  23 },  {  -28,  54,  43,  25 },  {  -36,  66,   0,  43 } } },  /* 183: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -13,  23,  83,  19 },  {  -19,  48,  71,  20 },  {  -25,  49,  46,  25 },  {  -37,  74,   0,  45 } } },  /* 184: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -13,  23,  83,  19 },  {  -19,  48,  71,  20 },  {  -25,  49,  46,  25 },  {  -37,  74,   0,  45 } } },  /* 185: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -21,  23,  83,  19 },  {  -17,  41,  71,  20 },  {  -25,  50,  46,  25 },  {  -37,  74,   0,  45 } } },  /* 186: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -15,  23,  86,  19 },  {  -14,  43,  71,  23 },  {  -25,  50,  46,  25 },  {  -37,  77,   0,  45 } } },  /* 187: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -18,  23,  86,  19 },  {  -14,  43,  71,  23 },  {  -25,  50,  46,  25 },  {  -37,  77,   0,  45 } } },  /* 188: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   -7,  23,  87,  19 },  {  -12,  43,  71,  22 },  {  -24,  50,  46,  25 },  {  -37,  77,   0,  45 } } },  /* 189: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -10,  23,  90,  19 },  {  -16,  48,  76,  18 },  {  -27,  47,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 190: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -27,  23,  73,  19 },  {  -25,  42,  60,  18 },  {  -22,  39,  41,  21 },  {  -36,  55,   0,  41 } } },  /* 191: ATTACK 3 S: not started by a command */
    { { {  -17,  23, 107,  20 },  {  -43,  72,  89,  19 },  {  -36,  55,  73,  18 },  {  -36,  51,  56,  17 } } },  /* 192: ATTACK 3 S: not started by a command */
    { { {   -9,  23, 101,  20 },  {  -28,  57,  87,  21 },  {  -36,  59,  75,  16 },  {  -46,  63,  50,  29 } } },  /* 193: ATTACK 3 S: not started by a command */
    { { {   -7,  23,  88,  20 },  {  -30,  55,  80,  23 },  {  -37,  62,  69,  18 },  {  -49,  75,  41,  29 } } },  /* 194: ATTACK 3 S: not started by a command */
    { { {   -8,  23,  96,  20 },  {  -22,  48,  80,  22 },  {  -31,  52,  69,  18 },  {  -43,  63,  51,  21 } } },  /* 195: ATTACK 3 S: not started by a command */
    { { {  -13,  23, 102,  20 },  {  -21,  52,  85,  25 },  {  -29,  51,  73,  19 },  {  -42,  59,  49,  25 } } },  /* 196: ATTACK 3 S: not started by a command */
    { { {  -20,  25,  46,  23 },  {  -31,  36,  61,  27 },  {  -60,  29,  60,  28 },  {  -65,  45,   1,  60 } } },  /* 197: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +1 */
    { { {  -28,  25,  38,  23 },  {  -29,  36,  61,  27 },  {  -52,  37,  72,  22 },  {  -68,  39,  38,  46 } } },  /* 198: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +1 */
    { { {  -31,  25,  41,  23 },  {  -24,  41,  59,  20 },  {  -29,  52,  79,  22 },  {  -33,  30, 100,  17 } } },  /* 199: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -38,  25,  45,  23 },  {  -28,  41,  63,  20 },  {  -29,  48,  83,  22 },  {  -28,  30, 104,  17 } } },  /* 200: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -42,  25,  42,  23 },  {  -28,  39,  63,  28 },  {  -20,  50,  91,  22 },  {   -9,  30, 112,  17 } } },  /* 201: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -45,  25,  81,  23 },  {  -27,  31,  72,  27 },  {    0,  37,  78,  28 },  {   26,  29, 102,  17 } } },  /* 202: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -36,  25,  92,  23 },  {  -27,  31,  75,  27 },  {    4,  31,  71,  28 },  {   33,  29,  78,  26 } } },  /* 203: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -31,  25,  99,  23 },  {  -20,  46,  85,  22 },  {   -3,  51,  75,  20 },  {    8,  50,  67,  22 } } },  /* 204: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -45,  43,  53,  29 },  {  -36,  67,  44,  22 },  {  -30,  55,  33,  11 },  {  -39,  71,   0,  33 } } },  /* 205: follow-up of APPEAR 2, follow-up of SP APPEAR 5, follow-up of SP APPEAR 6 +4 */
    { { {  -30,  25,  99,  23 },  {  -18,  46,  87,  22 },  {   -6,  49,  69,  19 },  {    4,  50,  47,  22 } } },  /* 206: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +1 */
    { { {  -29,  25,  98,  23 },  {  -18,  48,  90,  24 },  {  -19,  49,  69,  21 },  {  -21,  51,  35,  34 } } },  /* 207: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1), ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1), ATTACK 9 M: after SA III 23623+K (plain script) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 208: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 209: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 210: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 211: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 212: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 213: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 214: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 215: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 216: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 217: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 218: no box */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 219: no box */
    { { {    0,   0,   0,  13 },  {    0,   0,   0,   0 },  {  -23,  49,  23,  61 },  {    0,   0,   0,   0 } } },  /* 220: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 221: no box */
    { { {    0,   0,   0,   0 },  {  -25,  45,  42,  67 },  {  -47,  37, 111,  28 },  {    0,   0,   0,   0 } } },  /* 222: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  49,  53,  87 },  {    0,   0,   0,   0 } } },  /* 223: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -41,  80,  69,  38 },  {    0,   0,   0,   0 } } },  /* 224: not used by a script */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {  -28,  61,  34,  54 },  {    0,   0,   0,   0 } } },  /* 225: not used by a script */
    { { {  -25,  23, 105,  19 },  {  -31,  48,  90,  18 },  {  -24,  51,  71,  19 },  {  -20,  55,  35,  36 } } },  /* 226: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    { { {  -13,  23, 105,  19 },  {  -23,  50,  90,  18 },  {  -20,  46,  71,  19 },  {  -20,  58,  35,  36 } } },  /* 227: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -13,  23, 105,  19 },  {  -27,  52,  90,  18 },  {  -24,  51,  71,  19 },  {  -20,  59,  35,  36 } } },  /* 228: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {    0,  23, 104,  19 },  {  -27,  65,  90,  19 },  {  -22,  51,  71,  19 },  {  -23,  73,  35,  36 } } },  /* 229: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {    0,  23, 102,  19 },  {  -18,  63,  89,  19 },  {  -25,  54,  71,  19 },  {  -31,  73,  35,  36 } } },  /* 230: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {    9,  23,  99,  19 },  {   -7,  68,  83,  19 },  {  -16,  49,  71,  14 },  {  -30,  62,  43,  39 } } },  /* 231: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {   11,  23,  93,  19 },  {  -25, 113,  80,  19 },  {  -16,  56,  71,  14 },  {  -30,  68,  43,  37 } } },  /* 232: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {   -1,  23,  97,  14 },  {  -34,  61,   0,  97 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 233: ATTACK 7 L: SA III 23623+K (plain script) */
    { { {   -5,  23,  95,  19 },  {  -14,  48,  81,  18 },  {  -21,  57,  67,  14 },  {  -38,  60,   0,  67 } } },  /* 234: ATTACK 7 L: SA III 23623+K (plain script) */
    { { {    4,  25,  78,  19 },  {  -23,  47,  73,  18 },  {  -35,  59,  57,  21 },  {  -51,  71,   0,  57 } } },  /* 235: ATTACK 10 L: not started by a command */
    { { {   30,  25,  49,  19 },  {   13,  23,  35,  53 },  {  -25,  40,  60,  36 },  {  -39,  60,   0,  60 } } },  /* 236: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {   38,  25,  45,  19 },  {   20,  23,  35,  47 },  {  -25,  45,  60,  36 },  {  -20,  40,   0,  60 } } },  /* 237: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {   37,  25,  57,  19 },  {   20,  25,  52,  32 },  {  -30,  50,  61,  29 },  {  -13,  41,   0,  60 } } },  /* 238: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {   27,  25,  65,  19 },  {  -12,  45,  73,  14 },  {  -19,  51,  61,  12 },  {  -23,  51,   0,  60 } } },  /* 239: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {   15,  25,  89,  19 },  {   -5,  45,  77,  20 },  {  -14,  54,  57,  20 },  {  -23,  57,   0,  65 } } },  /* 240: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {    1,  25,  90,  19 },  {  -10,  44,  77,  16 },  {   -8,  36,  57,  20 },  {  -26,  60,   0,  57 } } },  /* 241: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {  -13,  25,  93,  19 },  {  -19,  46,  77,  18 },  {  -27,  61,  57,  20 },  {  -37,  67,   0,  57 } } },  /* 242: ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {   -9,  26,  94,  19 },  {  -22,  50,  71,  24 },  {  -30,  51,  54,  20 },  {  -29,  51,   0,  54 } } },  /* 243: M KICK C */
    { { {   -5,  26,  95,  19 },  {  -22,  53,  71,  24 },  {  -32,  51,  54,  20 },  {  -32,  52,   0,  54 } } },  /* 244: M KICK C */
    { { {    5,  26,  95,  19 },  {   -9,  53,  71,  24 },  {  -19,  42,  54,  21 },  {   -7,  35,   0,  54 } } },  /* 245: M KICK C */
    { { {   13,  26,  90,  19 },  {   -6,  55,  71,  29 },  {  -19,  42,  54,  21 },  {   -4,  35,   0,  54 } } },  /* 246: M KICK C */
    { { {   20,  26,  80,  19 },  {   -6,  55,  71,  29 },  {  -19,  42,  54,  21 },  {   -4,  35,   0,  54 } } },  /* 247: M KICK C */
    { { {   18,  26,  77,  19 },  {  -16,  71,  65,  27 },  {  -23,  35,  51,  18 },  {   -4,  36,   0,  54 } } },  /* 248: M KICK C */
    { { {    9,  26,  80,  19 },  {  -16,  58,  57,  33 },  {  -35,  68,  39,  19 },  {  -43,  84,   0,  40 } } },  /* 249: M KICK C */
    { { {   -2,  26,  82,  19 },  {  -16,  51,  57,  33 },  {  -35,  68,  39,  19 },  {  -43,  84,   0,  40 } } },  /* 250: M KICK C */
    { { {  -14,  26,  89,  19 },  {  -22,  51,  58,  33 },  {  -35,  68,  39,  19 },  {  -43,  84,   0,  40 } } },  /* 251: M KICK C */
    { { {  -14,  26,  92,  19 },  {  -22,  47,  60,  33 },  {  -31,  59,  39,  21 },  {  -35,  71,   0,  39 } } },  /* 252: M KICK C */
    { { {   -9,  26,  94,  19 },  {  -16,  50,  71,  25 },  {  -21,  51,  54,  17 },  {  -25,  53,   0,  54 } } },  /* 253: M KICK C */
    { { {  -33,  23,  81,  19 },  {  -33,  44,  70,  16 },  {  -29,  50,  48,  22 },  {  -37,  49,  30,  18 } } },  /* 254: AIR NORMAL, HARAYARARE */
    { { {  -11,  23,  91,  19 },  {  -16,  43,  77,  18 },  {  -20,  45,  58,  19 },  {  -39,  56,  37,  21 } } },  /* 255: ASIBARAI SIRI */
    { { {   -1,  23,  72,  19 },  {   -5,  47,  59,  18 },  {   -9,  45,  33,  26 },  {  -29,  24,  40,  37 } } },  /* 256: ASIBARAI SIRI */
    { { {    3,  23,  62,  19 },  {    1,  39,  45,  18 },  {  -19,  51,  28,  22 },  {  -22,  30,  50,  27 } } },  /* 257: ASIBARAI SIRI */
    { { {    3,  23,  54,  19 },  {    1,  33,  33,  21 },  {  -21,  41,  14,  24 },  {  -24,  30,  38,  31 } } },  /* 258: ASIBARAI SIRI */
    { { {    0,  23,  27,  19 },  {   -1,  35,  12,  18 },  {  -27,  50,  -6,  22 },  {  -25,  30,  16,  36 } } },  /* 259: ASIBARAI SIRI */
    { { {   -2,  23,  91,  19 },  {  -13,  49,  76,  18 },  {  -15,  45,  57,  19 },  {  -13,  41,  38,  19 } } },  /* 260: ASIB TUNNOMERI, HUMI ASIB */
    { { {  -41,  23,  37,  19 },  {  -37,  36,  34,  39 },  {  -10,  26,  31,  36 },  {   -4,  27,  14,  42 } } },  /* 261: ASIB TUNNOMERI, HUMI ASIB */
    { { {   -3,  23,   5,  19 },  {  -26,  41,  13,  26 },  {  -19,  39,  39,  22 },  {    7,  29,  18,  38 } } },  /* 262: ASIB TUNNOMERI, HUMI ASIB */
    { { {   27,  23,  85,  19 },  {  -16,  62,  74,  20 },  {  -31,  55,  58,  22 },  {  -39,  60,  36,  22 } } },  /* 263: NOKEZORI, FACE, BODY UPPER SP */
    { { {   36,  23,  74,  19 },  {   11,  35,  65,  28 },  {  -15,  38,  57,  30 },  {  -38,  49,  41,  35 } } },  /* 264: NOKEZORI, UPPER, FACE +2 */
    { { {   43,  23,  63,  19 },  {   14,  29,  60,  30 },  {  -13,  35,  56,  29 },  {  -37,  36,  46,  32 } } },  /* 265: NOKEZORI, UPPER, BODY UPPER +3 */
    { { {   43,  23,  54,  19 },  {   14,  29,  55,  31 },  {  -13,  35,  54,  30 },  {  -40,  36,  47,  33 } } },  /* 266: NOKEZORI, UPPER, BODY UPPER +3 */
    { { {   36,  23,  44,  19 },  {   14,  29,  48,  33 },  {  -13,  35,  52,  29 },  {  -40,  36,  52,  29 } } },  /* 267: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   23,  23,  30,  19 },  {    4,  37,  41,  29 },  {  -10,  34,  55,  24 },  {  -37,  35,  60,  30 } } },  /* 268: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {   16,  23,  18,  19 },  {   -1,  42,  32,  23 },  {  -12,  43,  50,  23 },  {  -25,  41,  65,  27 } } },  /* 269: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {    6,  23,  -3,  19 },  {   -7,  44,  13,  19 },  {   -9,  44,  32,  22 },  {  -17,  45,  54,  26 } } },  /* 270: NOKEZORI, UPPER, BODY UPPER +4 */
    { { {  -24,  23,  87,  19 },  {  -30,  51,  80,  18 },  {  -29,  54,  58,  22 },  {  -34,  56,  34,  24 } } },  /* 271: KUNOJI, BODY UPPER, KUNOJI NOKE */
    { { {  -45,  23,  66,  19 },  {  -33,  51,  64,  24 },  {  -14,  40,  49,  31 },  {  -48,  42,  39,  32 } } },  /* 272: KUNOJI, KUNOJI NOKE */
    { { {   -5,  23,  94,  19 },  {  -27,  53,  81,  18 },  {  -33,  50,  58,  22 },  {  -39,  53,  32,  26 } } },  /* 273: KIRIMOMI */
    { { {   10,  23,  91,  19 },  {  -21,  50,  81,  20 },  {  -33,  52,  58,  22 },  {  -41,  47,  35,  23 } } },  /* 274: KIRIMOMI */
    { { {   18,  23,  90,  19 },  {  -10,  48,  74,  30 },  {  -27,  48,  58,  22 },  {  -34,  41,  35,  23 } } },  /* 275: KIRIMOMI */
    { { {   18,  23,  89,  19 },  {   -8,  44,  69,  30 },  {  -19,  44,  57,  23 },  {  -32,  44,  35,  26 } } },  /* 276: KIRIMOMI */
    { { {   31,  23,  80,  19 },  {   -1,  44,  61,  30 },  {  -14,  38,  51,  23 },  {  -31,  41,  35,  26 } } },  /* 277: KIRIMOMI */
    { { {   31,  23,  72,  19 },  {    3,  38,  56,  30 },  {  -13,  36,  49,  25 },  {  -31,  41,  35,  28 } } },  /* 278: KIRIMOMI */
    { { {   33,  23,  64,  19 },  {    3,  38,  54,  32 },  {  -13,  38,  49,  27 },  {  -31,  41,  37,  28 } } },  /* 279: KIRIMOMI */
    { { {   38,  23,  57,  19 },  {    3,  38,  44,  38 },  {  -15,  38,  47,  27 },  {  -35,  41,  34,  30 } } },  /* 280: KIRIMOMI */
    { { {   38,  23,  53,  19 },  {    3,  38,  39,  38 },  {  -13,  30,  37,  27 },  {  -36,  38,  26,  31 } } },  /* 281: KIRIMOMI */
    { { {   42,  23,  42,  19 },  {    4,  38,  34,  29 },  {  -13,  30,  29,  27 },  {  -35,  34,  17,  30 } } },  /* 282: KIRIMOMI */
    { { {   43,  23,  25,  19 },  {    6,  38,  12,  40 },  {  -15,  26,  14,  34 },  {  -46,  34,  14,  36 } } },  /* 283: KIRIMOMI */
    { { {   40,  23,   9,  19 },  {    6,  34,   1,  28 },  {  -20,  26,   2,  27 },  {  -42,  22,   8,  31 } } },  /* 284: KIRIMOMI */
    { { {  -24,  23,  87,  19 },  {  -27,  51,  81,  23 },  {  -33,  59,  58,  23 },  {  -35,  54,  39,  19 } } },  /* 285: UPPER, TATUMAKIZANKU */
    { { {   11,  23, 100,  19 },  {  -16,  50,  85,  21 },  {  -25,  52,  60,  25 },  {  -23,  47,  39,  21 } } },  /* 286: UPPER, TATUMAKIZANKU */
    { { {   26,  23,  90,  19 },  {  -11,  50,  83,  21 },  {  -22,  48,  60,  25 },  {  -26,  47,  39,  21 } } },  /* 287: UPPER, TATUMAKIZANKU */
    { { {  -34,  23,  69,  19 },  {  -27,  51,  79,  18 },  {  -27,  49,  57,  22 },  {  -36,  54,  37,  20 } } },  /* 288: BODY UPPER, HANEKAERI HARA */
    { { {  -24,  23,  87,  19 },  {  -27,  53,  81,  20 },  {  -34,  55,  58,  23 },  {  -44,  54,  39,  19 } } },  /* 289: BODY UPPER, HARAYARARE, HANEKAERI HARA */
    { { {   10,  23,  93,  19 },  {  -13,  50,  73,  21 },  {  -27,  45,  58,  23 },  {  -40,  50,  44,  25 } } },  /* 290: BODY UPPER */
    { { {  -27,  23,  53,  19 },  {  -25,  47,  55,  20 },  {  -23,  55,  41,  27 },  {  -39,  59,  21,  26 } } },  /* 291: TATAKI AIR, TTKI V. AIR */
    { { {  -16,  23,  32,  19 },  {  -25,  60,  38,  18 },  {   -2,  39,   9,  36 },  {  -31,  39,  13,  29 } } },  /* 292: TATAKI AIR, TTKI V. AIR */
    { { {  -10,  23,  28,  19 },  {   -9,  35,  13,  20 },  {  -29,  54,  -5,  22 },  {  -43,  34,  10,  26 } } },  /* 293: TATAKI AIR, TTKI V. AIR */
    { { {   15,  23,   8,  19 },  {   -1,  37,  -8,  28 },  {  -31,  30,  -7,  29 },  {  -27,  34,  19,  18 } } },  /* 294: TATAKI AIR, TTKI V. AIR */
    { { {   -4,  23,  89,  19 },  {  -21,  49,  76,  18 },  {  -31,  54,  57,  22 },  {  -38,  52,  38,  19 } } },  /* 295: FACE, TOUKETSU A */
    { { {  -16,  23,  97,  19 },  {  -22,  48,  85,  20 },  {  -29,  52,  59,  26 },  {  -31,  61,  38,  22 } } },  /* 296: DENKI */
    { { {   -8,  23,  95,  20 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 297: follow-up of KAMAE */
    { { {   -9,  23,  95,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  55,   0,  40 } } },  /* 298: follow-up of KAMAE */
    { { {  -20,  25,  46,  23 },  {  -31,  36,  61,  27 },  {  -60,  29,  60,  28 },  {  -65,  45,   1,  60 } } },  /* 299: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -28,  25,  38,  23 },  {  -29,  36,  61,  27 },  {  -52,  37,  72,  22 },  {  -68,  39,  38,  46 } } },  /* 300: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -31,  25,  41,  23 },  {  -24,  41,  59,  20 },  {  -29,  52,  79,  22 },  {  -33,  30, 100,  17 } } },  /* 301: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -38,  25,  45,  23 },  {  -28,  41,  63,  20 },  {  -29,  48,  83,  22 },  {  -28,  30, 104,  17 } } },  /* 302: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -42,  25,  42,  23 },  {  -28,  39,  63,  28 },  {  -20,  50,  91,  22 },  {   -9,  30, 112,  17 } } },  /* 303: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -45,  25,  81,  23 },  {  -27,  31,  72,  27 },  {    0,  37,  78,  28 },  {   26,  29, 102,  17 } } },  /* 304: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -36,  25,  92,  23 },  {  -27,  31,  75,  27 },  {    4,  31,  71,  28 },  {   33,  29,  78,  26 } } },  /* 305: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -31,  25,  99,  23 },  {  -20,  46,  85,  22 },  {   -3,  51,  75,  20 },  {    8,  50,  67,  22 } } },  /* 306: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -30,  25,  99,  23 },  {  -18,  46,  87,  22 },  {   -6,  49,  69,  19 },  {    4,  50,  47,  22 } } },  /* 307: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -10,  23,  94,  19 },  {  -19,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -31,  65,   0,  40 } } },  /* 308: TUKAMIKAKARI A, TUKAMIKAKARI B, TUKAMIKAKARI C +1 */
    { { {  -10,  23,  94,  19 },  {  -13,  48,  77,  18 },  {  -22,  46,  41,  35 },  {  -25,  65,   0,  41 } } },  /* 309: TUKAMIKAKARI A */
    { { {  -16,  23,  89,  19 },  {  -23,  48,  77,  18 },  {  -17,  46,  41,  35 },  {  -20,  65,   0,  41 } } },  /* 310: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -20,  23,  86,  19 },  {  -24,  48,  73,  18 },  {  -15,  46,  41,  35 },  {  -20,  65,   0,  41 } } },  /* 311: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -26,  23,  81,  19 },  {  -27,  57,  68,  21 },  {  -18,  46,  40,  28 },  {  -26,  68,   0,  39 } } },  /* 312: TUKAMIHAZUSARE */
};

const HAND_BOX remy_hand_box[132] = {
    /*   x    w    y    h        x    w    y    h        x    w    y    h        x    w    y    h */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 0: no box */
    { { {  -41,  20,  73,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 1: S PUNCH A */
    { { {  -40,  18,  55,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 2: S PUNCH B, ATTACK 10 SP: not started by a command */
    { { {  -65,  39,  70,  15 },  {  -38,  17,  85,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 3: S PUNCH B */
    { { {  -64,  24,  63,  15 },  {  -40,  15,  73,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 4: S PUNCH B */
    { { {  -48,  24,  56,  15 },  {  -35,  13,  70,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 5: S PUNCH B */
    { { {   24,  22,  73,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 6: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {   24,  23,  78,  19 },  {   39,  19,  89,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 7: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -20,  27,  83,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 8: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -61,  50,  57,  20 },  {  -52,  37,  75,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 9: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -61,  50,  57,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 10: M PUNCH A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -84,  30,  94,  17 },  {  -60,  33,  87,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 11: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -71,  27,  91,  14 },  {  -54,  38,  83,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 12: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -54,  40,  67,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 13: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -48,  33,  70,  46 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 14: L PUNCH A */
    { { {  -33,  25,  98,  45 },  {  -23,  29, 105,  60 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 15: L PUNCH A */
    { { {  -16,  28, 112,  50 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 16: L PUNCH A */
    { { {  -18,  23, 112,  24 },  {   -6,  18, 120,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 17: L PUNCH A */
    { { {  -11,  29, 114,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 18: L PUNCH A */
    { { {   19,  29,  88,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 19: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -50,  30,  44,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 20: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -58,  34,  46,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 21: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -57,  17,  60,  18 },  {  -41,  16,  55,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 22: L PUNCH B */
    { { {  -47,  33,  61,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 23: L PUNCH B */
    { { {  -49,  28,  58,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 24: L PUNCH B */
    { { {  -98,  36,  89,  23 },  {  -78,  50,  85,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 25: M PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -39,  22,  53,  31 },  {  -30,  13,  31,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 26: S KICK A */
    { { {  -61,  18,  28,  21 },  {  -49,  19,  35,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 27: S KICK B */
    { { {  -51,  16,  33,  24 },  {  -63,  22,  15,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 28: S KICK B */
    { { {  -39,  22,  53,  31 },  {  -30,  13,  31,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 29: M KICK A */
    { { {  -99,  73,  47,  23 },  {  -57,  52,  68,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 30: M KICK B */
    { { { -103,  78,  47,  22 },  {  -57,  52,  68,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 31: M KICK B */
    { { {  -68,  36,  41,  27 },  {  -44,  36,  71,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 32: M KICK B */
    { { {  -42,  28,  35,  49 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 33: M KICK B */
    { { {  -29,  26,  53,  40 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 34: L KICK A */
    { { {  -61,  25,  90,  28 },  {  -53,  27,  78,  31 },  {  -37,  40,  65,  31 },  {    0,   0,   0,   0 } } },  /* 35: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -67,  33,  90,  35 },  {  -53,  29,  76,  36 },  {  -39,  44,  65,  34 },  {    0,   0,   0,   0 } } },  /* 36: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -65,  38,  91,  18 },  {  -38,  38,  82,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 37: L KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -88,  88,  89,  15 },  {  -77,  70,  81,   8 },  {  -35,  14,  69,  12 },  {    0,   0,   0,   0 } } },  /* 38: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { { -104, 105,  87,  18 },  {  -88,  66,  76,  12 },  {  -31,   9,  65,  11 },  {    0,   0,   0,   0 } } },  /* 39: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { { -104, 105,  80,  22 },  {  -36,  15,  69,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 40: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -70,  51,  45,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 41: L KICK B, follow-up of M KICK A, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -84,  51,  32,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 42: KAGAMI P A */
    { { {  -87,  36,  45,  21 },  {  -65,  39,  38,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 43: KAGAMI P A */
    { { {  -60,  33,  31,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 44: KAGAMI P A */
    { { {  -50,  27,  33,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 45: KAGAMI P A */
    { { {  -45,  41,  61,  52 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 46: KAGAMI P A */
    { { {  -49,  28,  89,  25 },  {  -38,  23,  66,  28 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 47: KAGAMI P A */
    { { {  -48,  28,  60,  36 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 48: KAGAMI P A */
    { { {  -46,  25,  74,  23 },  {  -70,  28,  58,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 49: F JUMP P S A */
    { { {  -59,  43,  66,  20 },  {  -38,  21,  83,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 50: F JUMP P S A */
    { { {  -46,  25,  74,  23 },  {  -70,  28,  58,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 51: F JUMP P M A */
    { { {  -59,  43,  66,  20 },  {  -38,  21,  83,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 52: F JUMP P M A */
    { { {  -56,  32,  61,  27 },  {  -50,  26,  82,  14 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 53: F JUMP P L A */
    { { {  -56,  22,  66,  23 },  {  -46,  24,  74,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 54: F JUMP P L A */
    { { { -104,  90,  57,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 55: F JUMP K M A */
    { { {  -72,  59,  57,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 56: F JUMP K M A */
    { { {  -92,  29,  30,  23 },  {  -74,  27,  35,  26 },  {  -58,  25,  42,  27 },  {  -42,  24,  50,  27 } } },  /* 57: F JUMP K L A */
    { { {  -94,  32,  25,  26 },  {  -76,  29,  33,  28 },  {  -60,  27,  40,  29 },  {  -44,  26,  48,  29 } } },  /* 58: F JUMP K L A */
    { { {  -69,  20,  38,  23 },  {  -51,  18,  47,  24 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 59: F JUMP K L A */
    { { {  -66,  36,   0,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 60: KAGAMI K A */
    { { {  -86,  31,   0,  21 },  {  -58,  42,  22,  10 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 61: KAGAMI K A */
    { { {  -86,  69,   0,  24 },  { -104,  19,   0,  16 },  {  -58,  42,  22,  11 },  {    0,   0,   0,   0 } } },  /* 62: KAGAMI K A */
    { { {  -62,  41,   0,  15 },  {  -54,  34,  13,  11 },  {  -35,  15,  23,  11 },  {    0,   0,   0,   0 } } },  /* 63: KAGAMI K A, follow-up of ATTACK 6 L, ATTACK 6 SP +3 */
    { { { -102,  93,   4,  40 },  {   19,  22,  55,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 64: KAGAMI K A */
    { { {  -89,  80,   4,  37 },  {   16,  23,  53,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 65: KAGAMI K A */
    { { {  -54,  27,   0,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 66: KAGAMI K A */
    { { {  -99,  69,   0,  17 },  {  -74,  48,  14,  11 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 67: KAGAMI K A */
    { { {  -54,  27,   0,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 68: KAGAMI K A */
    { { {  -32,  26,  90,  16 },  {   24,  28,  54,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 69: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script) +2 */
    { { {   19,  15,  84,  24 },  {   23,  24,  43,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 70: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 4 M: [4]6+P light (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    { { {   23,  25,  81,  28 },  {   20,  16,  43,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 71: ATTACK 4 M: [4]6+P light (plain script) */
    { { {   23,  32,  81,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 72: ATTACK 4 M: [4]6+P light (plain script) */
    { { {   19,  36,  78,  26 },  {  -49,  38,  76,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 73: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    { { {   31,  17,  67,  24 },  {  -39,  21,  75,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 74: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 S: EX [4]6+PP (plain script) */
    { { {  -45,  20,  61,  15 },  {   41,  26,  50,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 75: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { { {  -24,  21,  69,   9 },  {   41,  21,  44,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 76: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -13,  20,  74,   7 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 77: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -52,  33,  48,  18 },  {    3,  18,  75,  12 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 78: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -47,  29,  55,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 79: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -35,  17,  62,  15 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 80: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 6 S: EX [4]6+KK (plain script) */
    { { {  -37,  16,  71,  20 },  {   25,  19,  45,  31 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 81: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {    1,  18,  91,  19 },  {   24,  17,  45,  30 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 82: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   27,  17,  94,  10 },  {    3,  27,  84,  13 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 83: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   52,  18,  81,  20 },  {   30,  22,  77,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 84: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   29,  33,  77,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 85: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {   26,  32,  64,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 86: ATTACK 1 S: SA I 23623+P (plain script) */
    { { {  -41,  19,  74,  18 },  {  -52,  29,  53,  21 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 87: ATTACK 3 S: not started by a command */
    { { {  -94,  34,  17,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 88: ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    { { {  -85,  38,  35,  63 },  {  -95,  13,  59,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 89: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    { { {  -77,  45,  95,  33 },  {  -89,  11,  88,  30 },  {  -66,  33, 128,  12 },  {    0,   0,   0,   0 } } },  /* 90: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 9 L: SA II 23623+K (routine Att_PL20_AT1) */
    { { {  -48,  37, 122,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 91: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {   -3,  36, 128,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 92: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { { {  -94,  34,  17,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 93: not used by a script */
    { { {  -85,  38,  35,  63 },  {  -95,  13,  59,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 94: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    { { {  -77,  45,  95,  33 },  {  -89,  11,  88,  30 },  {  -66,  33, 128,  12 },  {    0,   0,   0,   0 } } },  /* 95: ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1) */
    { { {  -94,  34,  17,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 96: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    { { {  -85,  38,  35,  63 },  {  -95,  13,  59,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 97: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    { { {  -77,  45,  95,  33 },  {  -89,  11,  88,  30 },  {  -66,  33, 128,  12 },  {    0,   0,   0,   0 } } },  /* 98: ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) */
    { { {  -94,  34,  17,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 99: not used by a script */
    { { {  -85,  38,  35,  63 },  {  -95,  13,  59,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 100: not used by a script */
    { { {  -77,  45,  95,  33 },  {  -89,  11,  88,  30 },  {  -66,  33, 128,  12 },  {    0,   0,   0,   0 } } },  /* 101: ATTACK 2 SP: EX [2](789)+KK (routine Att_PL20_AT1) */
    { { {  -62,  31,  93,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 102: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    { { {  -54,  31,  93,  16 },  {  -44,  24,  55,  27 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 103: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -50,  23,  93,  16 },  {   25,  35,  78,  17 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 104: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {    0,   0,   0,   0 },  {   28,  29,  81,  22 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 105: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -62,  32,  45,  35 },  {  -23,  26,  94,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 106: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -99,  70,  39,  25 },  {  -71,  41,  52,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 107: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -99,  70,  39,  25 },  {  -71,  41,  52,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 108: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +2 */
    { { {  -99,  70,  39,  25 },  {  -71,  41,  52,  23 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 109: ATTACK 6 L: 214+K light (routine Att_PL20_AT2), ATTACK 6 SP: 214+K medium (routine Att_PL20_AT2), ATTACK 7 S: 214+K heavy (routine Att_PL20_AT2) +1 */
    { { {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 110: no box */
    { { {  -46,  24,  40,  18 },  {  -37,  15,  58,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 111: not used by a script */
    { { { -100,  16, 102,  10 },  {  -69,  15,  90,   9 },  {  -53,  18,  84,   8 },  {  -84,  16,  95,  10 } } },  /* 112: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {  -84,  22,  92,  10 },  {  -66,  13,  90,   8 },  {  -51,  16,  86,   6 },  {    0,   0,   0,   0 } } },  /* 113: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {  -89,  23,  92,  12 },  {  -66,  13,  91,   8 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 114: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command */
    { { {  -77,  18,  51,  27 },  {  -61,  21,  54,  17 },  {  -40,  27,  52,  15 },  {    0,   0,   0,   0 } } },  /* 115: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {  -46,  24,  19,  19 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 116: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {  -18,  13,  73,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 117: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {  -26,  18,  57,  26 },  {   28,  16,  57,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 118: ATTACK 9 S: after SA III 23623+K (plain script), ATTACK 10 L: not started by a command, ATTACK 10 SP: not started by a command */
    { { {  -41,  35,  53,  29 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 119: M KICK C */
    { { {  -54,  48,  47,  34 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 120: M KICK C */
    { { {  -65,  46,  34,  33 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 121: M KICK C */
    { { {  -76,  41,   0,  35 },  {  -51,  33,  20,  24 },  {  -35,  33,  39,  14 },  {    0,   0,   0,   0 } } },  /* 122: M KICK C */
    { { {  -66,  45,  52,  26 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 123: L PUNCH B, ATTACK 9 S: after SA III 23623+K (plain script) */
    { { {  -94,  34,  17,  64 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 124: not used by a script */
    { { {  -85,  38,  35,  63 },  {  -95,  13,  59,  43 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 125: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -77,  45,  95,  33 },  {  -89,  11,  88,  30 },  {  -66,  33, 128,  12 },  {    0,   0,   0,   0 } } },  /* 126: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -48,  37, 122,  39 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 127: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {   -3,  36, 128,  44 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 128: ATTACK 9 M: after SA III 23623+K (plain script) */
    { { {  -46,  22,  76,  20 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 129: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -44,  28,  61,  18 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 130: TUKAMIHAZUSARE, TUKAMIKAKARI A */
    { { {  -72,  44,  67,  16 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 },  {    0,   0,   0,   0 } } },  /* 131: TUKAMIHAZUSARE */
};

const HOSEI_BOX remy_hos_box[12] = {
    /*    x     w     y     h */
    { {    0,    0,    0,    0 } },  /* 0: no box */
    { {  -21,   42,    0,   88 } },  /* 1: KAMAE, HURIMUKI, DASH HUMIKOMI +81 */
    { {  -21,   42,    0,   50 } },  /* 2: KAGAMU, KAGAMI KAMAE, KAGAMI TURN +69 */
    { {  -21,   42,   56,   50 } },  /* 3: JUMP FRONT, JUMP VERTICAL, JUMP BACK +28 */
    { {  -21,   42,   45,   46 } },  /* 4: AIR NORMAL, BODY SLAM, IPPONZEOI +27 */
    { {  -21,   42,    0,   30 } },  /* 5: NEKOROBI S, no name */
    { {  -21,   42,    0,   69 } },  /* 6: KAGAMU, STAND UP, JUMP JUNBI +11 */
    { {  -24,   52,    0,   88 } },  /* 7: ATTACK 4 M: [4]6+P light (plain script), ATTACK 4 L: [4]6+P medium (plain script), ATTACK 4 SP: [4]6+P heavy (plain script) +2 */
    { {  -33,   54,    0,   50 } },  /* 8: ATTACK 1 S: SA I 23623+P (plain script), ATTACK 5 M: [4]6+K light (plain script), ATTACK 5 L: [4]6+K medium (plain script) +2 */
    { {  -42,   42,    0,   78 } },  /* 9: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +2 */
    { {  -49,   47,   42,   50 } },  /* 10: ATTACK 2 S: [2](789)+K light (routine Att_PL20_AT1), ATTACK 2 M: [2](789)+K medium (routine Att_PL20_AT1), ATTACK 2 L: [2](789)+K heavy (routine Att_PL20_AT1) +3 */
    { {  -21,   42,    0,   78 } },  /* 11: UPPER L, FACE S, FACE M +18 */
};
