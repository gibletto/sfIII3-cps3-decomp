/*
 * CMD_DATA.C  command input records
 *
 * The fighters' command records (format in CMD_DATA.H): pc_cmd_ records shared by every
 * fighter (dashes, high jump, parries, button mashing) and the pN_cmd_ records of each
 * fighter's special moves and super arts. pl_cmd_list holds each fighter's 56 command slots,
 * reached through pl_CMD (read by CMD_MAIN_2.C, the command input check) and player_cmd (read
 * by COM_PL.C and COM_SUB.C, which feed the records to the computer player). Also read by
 * CMD_MAIN_2.C: pl_cmd_num (slot counts per fighter), lever_gacha_tbl (lever bits set per
 * lever value, for mashing), ukemi_time_tbl (recovery-roll input timing) and lvr_chk_tbl (the
 * lever bits counted for held inputs). player_cmd_0 - 11, lvr_chk_tbl_0 - 2 and the line
 * tables after player_cmd and lvr_chk_tbl are the key-assignment and lever-check display
 * texts.
 */

/*
 * Record format (CMD_DATA.H names every field and flag): a 12-word header, then 4-word steps,
 * then CMD_END.  Ryu's Hadoken, 236+P:
 *
 *   CMD_RESET, CMD_LV_UP, 0,          reset: once entered, the command waits 12 frames for the
 *                                     move to start; dead, dead2: holding up (a jump) drops it
 *   CMD_WAZA(RYU_HADOKEN),            rno[4]: the attack routine each strength starts
 *   CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL,   btix: the button is a new press, there is an EX
 *                                     version, and not while the fireball is out
 *   CMD_EX_PUNCHES,                   exdt[4]: LP, MP, HP, and two punches for the EX version
 *   CMD_LEVER(0, CMD_LV_DOWN),        steps: down,
 *   CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),   down-forward within 10 frames,
 *   CMD_LEVER(10, CMD_LV_FORWARD),    forward within 10 frames
 *   CMD_END,
 */

#include "types.h"
#include "structs.h"
#include "cmd_data.h"

#pragma section TBL

extern const char lvr_chk_tbl_0[];
extern const char lvr_chk_tbl_1[];
extern const char lvr_chk_tbl_2[];
extern const char player_cmd_0[];
extern const char player_cmd_1[];
extern const char player_cmd_11[];
extern const char player_cmd_2[];
extern const char player_cmd_3[];
extern const char player_cmd_4[];
extern const char player_cmd_5[];


/* number of lever bits set in each lever value */
const s16 lever_gacha_tbl[16] = {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4,
};

const s16 pl_cmd_num[24][7] = {
    { 16, 23, 26, 32, 38, 42, 46 },  /* Gill */
    { 16, 23, 24, 34, 38, 42, 46 },  /* Alex */
    { 16, 23, 24, 32, 38, 42, 47 },  /* Ryu */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Yun */
    { 16, 23, 24, 34, 38, 42, 46 },  /* Dudley */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Necro */
    { 16, 23, 24, 34, 38, 42, 46 },  /* Hugo */
    { 16, 22, 24, 35, 39, 42, 47 },  /* Ibuki */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Elena */
    { 16, 23, 25, 32, 38, 42, 48 },  /* Oro */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Yang */
    { 16, 23, 24, 31, 38, 42, 47 },  /* Ken */
    { 16, 23, 24, 33, 38, 42, 46 },  /* Sean */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Urien */
    { 16, 23, 26, 36, 40, 42, 48 },  /* Gouki */
    { 16, 23, 25, 35, 40, 42, 48 },  /* Shin Gouki */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Chun-Li */
    { 16, 23, 24, 32, 38, 42, 47 },  /* Makoto */
    { 16, 23, 24, 34, 38, 42, 46 },  /* Q */
    { 16, 22, 24, 30, 39, 42, 50 },  /* Twelve */
    { 16, 23, 24, 32, 38, 42, 46 },  /* Remy */
    { 16, 20, 24, 28, 38, 42, 46 },  /* 21 */
    { 16, 20, 24, 28, 38, 42, 46 },  /* 22 */
    { 16, 20, 24, 28, 38, 42, 46 },  /* 23 */
};

/* The fighters' command records (format: cmd_data.h). pl_cmd_list holds, for each fighter, the record
 * of each of its 56 command slots; a record is named after the first slot that uses it.
 * The comment on each record names the move from the published move lists, checked against its
 * motion, buttons, slot group and the plNN_exatt_table routine its rno starts; (?) marks a guess.
 * A super art's number (SA I - III) is the one whose super_arts_data entry (PLCNT_tbl.c) names the
 * record's slot; the slot order is not the super art order. The input after the name is in numpad
 * notation (2 down, 6 forward, [4]6 charge back then forward), as the record's steps accept it. */
const s16 pc_cmd_00[29] = {  /* forward dash */
    8, CMD_LV_BACK, CMD_LV_DOWN, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER, 1, 1, CMD_LV_FORWARD),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_END,
};
const s16 pc_cmd_01[29] = {  /* back dash */
    8, CMD_LV_FORWARD, CMD_LV_DOWN, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_LEVER_ANY(1, CMD_LV_BACK),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_BACK)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_BACK)),
    CMD_END,
};
const s16 pc_cmd_02[21] = {  /* high jump */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER_NEW, 1, 0, CMD_LV_DOWN),
    CMD_STEP(CK_LEVER_NEW, 8, 0, CMD_LV_UP),
    CMD_END,
};
const s16 pc_cmd_03[17] = {  /* parry (forward) */
    11, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pc_cmd_04[17] = {  /* low parry (down) */
    11, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_DOWN),
    CMD_END,
};
const s16 pc_cmd_05[17] = {  /* air parry (forward) */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pc_cmd_06[17] = {  /* air parry (down) */
    8, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_DOWN),
    CMD_END,
};
const s16 pc_cmd_07[17] = {  /* red parry window (down) (?) */
    2, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY_STRICT, 8, 0, CMD_LV_DOWN),
    CMD_END,
};
const s16 pc_cmd_08[17] = {  /* punch mashing */
    7, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_RENDA3, 48, 48, CMD_SW_LP),
    CMD_END,
};
const s16 pc_cmd_09[17] = {  /* punch mashing, longer window */
    11, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_RENDA3, 72, 72, CMD_SW_LP),
    CMD_END,
};
const s16 pc_cmd_10[17] = {  /* kick mashing */
    7, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_RENDA3, 48, 48, CMD_SW_LK),
    CMD_END,
};
const s16 pc_cmd_11[17] = {  /* kick mashing, longer window */
    11, 0, 0, 0, 1, 2, 3, CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_RENDA3, 72, 72, CMD_SW_LK),
    CMD_END,
};
const s16 pc_cmd_12[17] = {  /* parry (forward), short hold */
    6, 0, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_PARRY, 0, 0, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pc_cmd_13[25] = {  /* down, down */
    4, CMD_LV_UP, 0, 0, 0, 0, 0, CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};
const s16 pc_cmd_14[25] = {  /* down, down + punch */
    CMD_RESET, CMD_LV_UP, 0, 10, 10, 10, 10, CMD_BT_NOW, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};
const s16 pc_cmd_15[25] = {  /* down, down + kick */
    CMD_RESET, CMD_LV_UP, 0, 10, 10, 10, 10, CMD_BT_NOW, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};
const s16 dm_cmd_xx[25] = {  /* unused slot (a dummy fireball motion) */
    CMD_RESET, 0, 0, 0, 0, 0, 0, CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Gill's attack routines (routine_no[2]; 16 and up index pl00_exatt_table) */
#define GILL_PYROKINESIS          16  /* Att_HADOUKEN */
#define GILL_MOONSAULT_KNEE_DROP  17  /* Att_MOONSALT_KNEE_DROP */
#define GILL_CYBER_LARIAT         18  /* Att_SLIDE_and_JUMP */
#define GILL_PSYCHO_HEADBUTT      19  /* Att_SENPUUKYAKU */
#define GILL_METEOR_STRIKE        20  /* Att_HADOUKEN */
#define GILL_RESURRECTION         21  /* Att_RESURRECTION */
#define GILL_SERAPHIC_WING        22  /* Att_JYOUKA */

const s16 p0_cmd_20[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};
const s16 p0_cmd_21[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};
const s16 p0_cmd_22[13] = {  /* Gill: super art slot, disabled */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_RESURRECTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled; check_init reads the rest of the step from the next record */
};
const s16 p0_cmd_24[33] = {  /* Gill: Meteor Strike, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_METEOR_STRIKE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p0_cmd_25[33] = {  /* Gill: Seraphic Wing, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_SERAPHIC_WING), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p0_cmd_28[25] = {  /* Gill: Cyber Lariat, 623+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_CYBER_LARIAT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p0_cmd_29[25] = {  /* Gill: Moonsault Knee Drop, 63214+K */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_MOONSAULT_KNEE_DROP), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p0_cmd_30[25] = {  /* Gill: Pyrokinesis, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GILL_PYROKINESIS), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p0_cmd_31[25] = {  /* Gill: Psycho Headbutt, 214+P */
    CMD_RESET, 0, 0, CMD_WAZA(GILL_PSYCHO_HEADBUTT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Alex's attack routines (routine_no[2]; 16 and up index pl01_exatt_table) */
#define ALEX_FLASH_CHOP         16  /* Att_CHOUCHUURENGEKI */
#define ALEX_AIR_KNEE_SMASH     17  /* Att_SHOURYUUKEN */
#define ALEX_POWER_BOMB         18  /* Att_HADOUKEN */
#define ALEX_HYPER_BOMB         19  /* Att_HADOUKEN2 */
#define ALEX_BOOMERANG_RAID     20  /* Att_CHOUCHUURENGEKI */
#define ALEX_STUN_GUN_HEADBUTT  21  /* Att_SENPUUKYAKU2 */
#define ALEX_AIR_STAMPEDE       22  /* Att_SENPUUKYAKU */
#define ALEX_SPIRAL_DDT         24  /* Att_PL01_DDT */
#define ALEX_AIR_STAMPEDE_EX    25  /* Att_HOMING_JUMP */
#define ALEX_SLASH_ELBOW        26  /* Att_SLIDE_and_JUMP */

const s16 p1_cmd_20[17] = {  /* Alex: SA I Hyper Bomb, 360+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_HYPER_BOMB), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};
const s16 p1_cmd_21[33] = {  /* Alex: SA II Boomerang Raid, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_BOOMERANG_RAID), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p1_cmd_22[33] = {  /* Alex: SA III Stun Gun Headbutt, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ALEX_STUN_GUN_HEADBUTT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p1_cmd_28[25] = {  /* Alex: Air Knee Smash, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_AIR_KNEE_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p1_cmd_29[25] = {  /* Alex: Power Bomb, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_POWER_BOMB), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p1_cmd_30[25] = {  /* Alex: Flash Chop, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_FLASH_CHOP), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p1_cmd_31[21] = {  /* Alex: Air Stampede, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ALEX_AIR_STAMPEDE, ALEX_AIR_STAMPEDE_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};
const s16 p1_cmd_32[21] = {  /* Alex: Slash Elbow, [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_SLASH_ELBOW), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p1_cmd_33[25] = {  /* Alex: Spiral DDT, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ALEX_SPIRAL_DDT), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

/* Ryu's attack routines (routine_no[2]; 16 and up index pl02_exatt_table) */
#define RYU_HADOKEN                   16  /* Att_HADOUKEN */
#define RYU_SHORYUKEN                 17  /* Att_SHOURYUUKEN */
#define RYU_TATSUMAKI_SENPUKYAKU      18  /* Att_SENPUUKYAKU */
#define RYU_SHINKUU_HADOKEN           19  /* Att_HADOUKEN */
#define RYU_SHIN_SHORYUKEN            20  /* Att_SHINSHOURYUUKEN */
#define RYU_DENJIN_HADOKEN            21  /* Att_DENJINHADOUKEN */
#define RYU_AIR_TATSUMAKI_SENPUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */
#define RYU_JOUDAN_SOKUTOU_GERI       23  /* Att_SLIDE_and_JUMP */

const s16 p2_cmd_20[33] = {  /* Ryu: SA I Shinkuu Hadoken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_SHINKUU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_21[33] = {  /* Ryu: SA III Denjin Hadoken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_DENJIN_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_22[33] = {  /* Ryu: SA II Shin Shoryuken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(RYU_SHIN_SHORYUKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_28[25] = {  /* Ryu: Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_SHORYUKEN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_29[25] = {  /* Ryu: Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_HADOKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_30[25] = {  /* Ryu: Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p2_cmd_31[29] = {  /* Ryu: Joudan Sokutou Geri, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_JOUDAN_SOKUTOU_GERI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p2_cmd_46[25] = {  /* Ryu: air Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_AIR_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Yun's attack routines (routine_no[2]; 16 and up index pl03_exatt_table) */
#define YUN_KOBOKUSHI       16  /* Att_HADOUKEN */
#define YUN_NISHOUKYAKU     17  /* Att_SHOURYUUKEN */
#define YUN_ZESSHOU_HOHOU   18  /* Att_SENPUUKYAKU */
#define YUN_GENEI_JIN       19  /* Att_HADOUKEN */
#define YUN_SOURAI_RENGEKI  20  /* Att_SLIDE_and_JUMP */
#define YUN_YOU_HOU         21  /* Att_SLIDE_and_JUMP */
#define YUN_ZENPOU_TENSHIN  22  /* Att_HADOUKEN */
#define YUN_TETSUZAN_KOU    24  /* Att_SLIDE_and_JUMP */

const s16 p3_cmd_20[33] = {  /* Yun: SA III Genei Jin, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_GENEI_JIN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p3_cmd_21[33] = {  /* Yun: SA II Sourai Rengeki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_SOURAI_RENGEKI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p3_cmd_22[33] = {  /* Yun: SA I You Hou, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YUN_YOU_HOU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p3_cmd_28[25] = {  /* Yun: Zenpou Tenshin, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p3_cmd_29[25] = {  /* Yun: Tetsuzan Kou, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_TETSUZAN_KOU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p3_cmd_30[25] = {  /* Yun: Kobokushi, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_KOBOKUSHI), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p3_cmd_31[25] = {  /* Yun: Nishoukyaku, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_NISHOUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p3_cmd_32[25] = {  /* Yun: Zesshou Hohou, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YUN_ZESSHOU_HOHOU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Dudley's attack routines (routine_no[2]; 16 and up index pl04_exatt_table) */
#define DUDLEY_JET_UPPER         16  /* Att_SENPUUKYAKU */
#define DUDLEY_MACHINE_GUN_BLOW  17  /* Att_SENPUUKYAKU */
#define DUDLEY_CROSS_COUNTER     18  /* Att_HADOUKEN */
#define DUDLEY_ROCKET_UPPERCUT   19  /* Att_SHOURYUUREPPA */
#define DUDLEY_ROLLING_THUNDER   20  /* Att_HADOUKEN2 */
#define DUDLEY_CORKSCREW_BLOW    21  /* Att_CHOUCHUURENGEKI */
#define DUDLEY_DUCKING           22  /* Att_CHOUCHUURENGEKI */
#define DUDLEY_PUNCH_AND_CROSS   25  /* Att_HADOUKEN */

const s16 p4_cmd_20[33] = {  /* Dudley: SA I Rocket Uppercut, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_ROCKET_UPPERCUT), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_21[33] = {  /* Dudley: SA II Rolling Thunder, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_ROLLING_THUNDER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_22[33] = {  /* Dudley: SA III Corkscrew Blow, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(DUDLEY_CORKSCREW_BLOW), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_28[25] = {  /* Dudley: Jet Upper, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_JET_UPPER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_29[33] = {  /* Dudley: Punch and Cross, 6321456+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_PUNCH_AND_CROSS), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_NEUTRAL),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_30[25] = {  /* Dudley: Cross Counter, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_CROSS_COUNTER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p4_cmd_31[25] = {  /* Dudley: Machine Gun Blow, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_MACHINE_GUN_BLOW), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_32[25] = {  /* Dudley: Ducking, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_DUCKING), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p4_cmd_33[25] = {  /* Dudley: Short Swing Blow, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(DUDLEY_DUCKING), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

/* Necro's attack routines (routine_no[2]; 16 and up index pl05_exatt_table) */
#define NECRO_TORNADO_HOOK     16  /* Att_CHOUCHUURENGEKI */
#define NECRO_DENJI_BLAST      17  /* Att_HADOUKEN */
#define NECRO_MAGNETIC_STORM   18  /* Att_HADOUKEN */
#define NECRO_SNAKE_FANG       19  /* Att_HADOUKEN */
#define NECRO_ELECTRIC_SNAKE   20  /* Att_HADOUKEN */
#define NECRO_FLYING_VIPER     21  /* Att_SENPUUKYAKU */
#define NECRO_SLAM_DANCE       22  /* Att_HADOUKEN */
#define NECRO_RISING_COBRA     24  /* Att_HADOUKEN */
#define NECRO_FLYING_VIPER_EX  25  /* Att_JINNCHUUWATARI */
#define NECRO_RISING_COBRA_EX  26  /* Att_SLIDE_and_JUMP */

const s16 p5_cmd_20[33] = {  /* Necro: SA I Magnetic Storm, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_MAGNETIC_STORM), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_21[33] = {  /* Necro: SA III Electric Snake, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_ELECTRIC_SNAKE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_22[33] = {  /* Necro: SA II Slam Dance, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_SLAM_DANCE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_28[29] = {  /* Necro: Snake Fang, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(NECRO_SNAKE_FANG), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_29[25] = {  /* Necro: Denji Blast, 623+P */
    CMD_RESET, 0, 0, CMD_WAZA(NECRO_DENJI_BLAST), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_30[29] = {  /* Necro: Tornado Hook, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(NECRO_TORNADO_HOOK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p5_cmd_31[25] = {  /* Necro: Flying Viper, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(NECRO_FLYING_VIPER, NECRO_FLYING_VIPER_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p5_cmd_32[25] = {  /* Necro: Rising Cobra, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(NECRO_RISING_COBRA, NECRO_RISING_COBRA_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Hugo's attack routines (routine_no[2]; 16 and up index pl06_exatt_table) */
#define HUGO_GIANT_PALM_BOMBER      16  /* Att_HADOUKEN2 */
#define HUGO_MOONSAULT_PRESS        17  /* Att_HADOUKEN2 */
#define HUGO_MONSTER_LARIAT         18  /* Att_CHOUCHUURENGEKI */
#define HUGO_ULTRA_THROW            19  /* Att_HADOUKEN2 */
#define HUGO_SHOOTDOWN_BACKBREAKER  20  /* Att_SHOURYUUKEN */
#define HUGO_HAMMER_FRENZY          21  /* Att_SLIDE_and_JUMP */
#define HUGO_GIGAS_BREAKER          22  /* Att_HADOUKEN2 */
#define HUGO_MEGATON_PRESS          23  /* Att_SHOURYUUKEN */
#define HUGO_MEAT_SQUASHER          24  /* Att_PL06_HASHIRI_NAGE */
#define HUGO_MONSTER_LARIAT_EX      25  /* Att_PL06_HASHIRI_NAGE */

const s16 p6_cmd_20[21] = {  /* Hugo: SA I Gigas Breaker, 720+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_GIGAS_BREAKER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};
const s16 p6_cmd_21[33] = {  /* Hugo: SA II Megaton Press, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_MEGATON_PRESS), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p6_cmd_22[33] = {  /* Hugo: SA III Hammer Frenzy, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_HAMMER_FRENZY), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p6_cmd_28[17] = {  /* Hugo: Moonsault Press, 360+P */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_MOONSAULT_PRESS), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};
const s16 p6_cmd_29[17] = {  /* Hugo: Meat Squasher, 360+K */
    CMD_RESET, 0, 0, CMD_WAZA(HUGO_MEAT_SQUASHER), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_TURN, 32, 32, 0),
    CMD_END,
};
const s16 p6_cmd_30[25] = {  /* Hugo: Shootdown Backbreaker, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_SHOOTDOWN_BACKBREAKER), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p6_cmd_31[25] = {  /* Hugo: Giant Palm Bomber, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_GIANT_PALM_BOMBER), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p6_cmd_32[25] = {  /* Hugo: Monster Lariat, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(HUGO_MONSTER_LARIAT, HUGO_MONSTER_LARIAT_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p6_cmd_33[25] = {  /* Hugo: Ultra Throw, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(HUGO_ULTRA_THROW), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};

/* Ibuki's attack routines (routine_no[2]; 16 and up index pl07_exatt_table) */
#define IBUKI_KAZEKIRI       16  /* Att_SHOURYUUKEN */
#define IBUKI_KUBIORI        17  /* Att_PL07_AT1 */
#define IBUKI_RAIDA          18  /* Att_CHOUCHUURENGEKI */
#define IBUKI_YAMI_SHIGURE   19  /* Att_SLIDE_and_JUMP */
#define IBUKI_TSUMUJI        20  /* Att_CHOUCHUURENGEKI */
#define IBUKI_YOROI_DOSHI    21  /* Att_PL07_SA2 */
#define IBUKI_HIEN           22  /* Att_PL07_AT2 */
#define IBUKI_KUNAI          23  /* Att_PL07_AT3 */
#define IBUKI_KASUMI_SUZAKU  24  /* Att_PL07_SA3 */
#define IBUKI_TSUIJI_GOE     25  /* Att_SLIDE_and_JUMP */
#define IBUKI_HIEN_EX        26  /* Att_HOMING_JUMP */

const s16 p7_cmd_20[33] = {  /* Ibuki: SA III Yami Shigure, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_YAMI_SHIGURE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_21[33] = {  /* Ibuki: SA II Yoroi Doshi, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_YOROI_DOSHI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_38[33] = {  /* Ibuki: SA I Kasumi Suzaku (air), 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(IBUKI_KASUMI_SUZAKU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_28[25] = {  /* Ibuki: Kazekiri, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KAZEKIRI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_29[25] = {  /* Ibuki: Raida, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_RAIDA), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p7_cmd_30[25] = {  /* Ibuki: Hien, 421+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(IBUKI_HIEN, IBUKI_HIEN_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_END,
};
const s16 p7_cmd_31[25] = {  /* Ibuki: Tsuiji Goe, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_TSUIJI_GOE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_32[25] = {  /* Ibuki: Tsumuji, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_TSUMUJI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p7_cmd_33[25] = {  /* Ibuki: Kubiori, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KUBIORI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_34[25] = {  /* Ibuki: Kasumi Gake, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_TSUIJI_GOE), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p7_cmd_46[25] = {  /* Ibuki: Kunai (air), 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(IBUKI_KUNAI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Elena's attack routines (routine_no[2]; 16 and up index pl08_exatt_table) */
#define ELENA_SCRATCH_WHEEL  16  /* Att_SHOURYUUKEN */
#define ELENA_RHINO_HORN     17  /* Att_SENPUUKYAKU */
#define ELENA_MALLET_SMASH   18  /* Att_SENPUUKYAKU */
#define ELENA_SPINNING_BEAT  19  /* Att_SHOURYUUREPPA */
#define ELENA_BRAVE_DANCE    20  /* Att_SHOURYUUREPPA */
#define ELENA_HEALING        21  /* Att_PL08_HEALING */
#define ELENA_SPIN_SCYTHE    23  /* Att_SLIDE_and_JUMP */
#define ELENA_LYNX_TAIL      24  /* Att_HADOUKEN */

const s16 p8_cmd_20[33] = {  /* Elena: SA I Spinning Beat, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_SPINNING_BEAT), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p8_cmd_21[33] = {  /* Elena: SA II Brave Dance, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_BRAVE_DANCE), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p8_cmd_22[33] = {  /* Elena: SA III Healing, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ELENA_HEALING), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p8_cmd_28[25] = {  /* Elena: Scratch Wheel, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_SCRATCH_WHEEL), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p8_cmd_29[25] = {  /* Elena: Rhino Horn, 41236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_RHINO_HORN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p8_cmd_30[25] = {  /* Elena: Mallet Smash, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_MALLET_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p8_cmd_31[25] = {  /* Elena: Lynx Tail, 421+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_LYNX_TAIL), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_END,
};
const s16 p8_cmd_32[25] = {  /* Elena: Spin Scythe, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ELENA_SPIN_SCYTHE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Oro's attack routines (routine_no[2]; 16 and up index pl09_exatt_table) */
#define ORO_NICHIRIN_SHOU          16  /* Att_HADOUKEN */
#define ORO_ONI_YANMA              17  /* Att_SHOURYUUKEN */
#define ORO_AIR_NICHIRIN_SHOU      18  /* Att_KUUCHUUNICHIRINSHOU */
#define ORO_NIOU_RIKI              19  /* Att_HADOUKEN */
#define ORO_TENGU_STONE            20  /* Att_HADOUKEN */
#define ORO_YAGYOU_DAMA            21  /* Att_HADOUKEN */
#define ORO_KISHIN_RIKI            22  /* Att_HADOUKEN */
#define ORO_AIR_JINCHUU_WATARI     23  /* Att_KUUCHUUJINNCHUUWATARI */
#define ORO_JINCHUU_WATARI         24  /* Att_JINNCHUUWATARI */
#define ORO_JINCHUU_WATARI_EX      25  /* Att_JINNCHUUWATARI_EX */
#define ORO_YAGYOU_DAMA_TWO_PUNCH  26  /* Att_SP_YAGYOUDAMA */
#define ORO_TENGU_STONE_EX         27  /* Att_PL09_EX_TENGUIWA */
#define ORO_KISHIN_RIKI_EX         28  /* Att_PL09_EX_KISHINRIKI */

const s16 p9_cmd_20[33] = {  /* Oro: SA III Tengu Stone, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ORO_TENGU_STONE, ORO_TENGU_STONE_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_21[33] = {  /* Oro: SA II Yagyou Dama, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_YAGYOU_DAMA), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_22[33] = {  /* Oro: SA I Kishin Riki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ORO_KISHIN_RIKI, ORO_KISHIN_RIKI_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_24[33] = {  /* Oro: SA II Yagyou Dama, two-punch version, 236236+PP */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_YAGYOU_DAMA_TWO_PUNCH), CMD_BT_CHG, CMD_EX_PP, CMD_EX_PP, CMD_EX_PP, CMD_EX_ONLY(CMD_EX_PP),
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_28[21] = {  /* Oro: Oni Yanma, [2]8+P */
    CMD_RESET, 0, 0, CMD_WAZA(ORO_ONI_YANMA), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};
const s16 p9_cmd_29[25] = {  /* Oro: Niou Riki, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_NIOU_RIKI), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 p9_cmd_30[21] = {  /* Oro: Nichirin Shou, [4]6+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_NICHIRIN_SHOU), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_31[25] = {  /* Oro: Jinchuu Watari, 236+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(ORO_JINCHUU_WATARI, ORO_JINCHUU_WATARI_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_46[26] = {  /* Oro: air Nichirin Shou, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_AIR_NICHIRIN_SHOU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CK_NONE,                /* disabled: placed ahead of the steps below */
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p9_cmd_47[25] = {  /* Oro: air Jinchuu Watari, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(ORO_AIR_JINCHUU_WATARI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Yang's attack routines (routine_no[2]; 16 and up index pl10_exatt_table) */
#define YANG_BYAKKO_SOUSHOUDA    16  /* Att_HADOUKEN */
#define YANG_SENKYUUTAI          17  /* Att_TENSHINSENKYUUTAI */
#define YANG_TOUROU_ZAN          18  /* Att_SLIDE_and_JUMP */
#define YANG_SEI_EI_ENBU         19  /* Att_HADOUKEN */
#define YANG_RAISHIN_MAHHAKEN    20  /* Att_SLIDE_and_JUMP */
#define YANG_TENSHIN_SENKYUUTAI  21  /* Att_TENSHINSENKYUUTAI */
#define YANG_ZENPOU_TENSHIN      22  /* Att_HADOUKEN */
#define YANG_KAIHOU              23  /* Att_PL10_MACH_SLIDE2 */

const s16 pA_cmd_20[33] = {  /* Yang: SA III Sei-ei Enbu, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_SEI_EI_ENBU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_21[33] = {  /* Yang: SA I Raishin Mahhaken, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_RAISHIN_MAHHAKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_22[33] = {  /* Yang: SA II Tenshin Senkyuutai, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(YANG_TENSHIN_SENKYUUTAI), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_28[25] = {  /* Yang: Zenpou Tenshin, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_ZENPOU_TENSHIN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_FORWARD),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_BACK),
    CMD_END,
};
const s16 pA_cmd_29[25] = {  /* Yang: Kaihou, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_KAIHOU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_30[25] = {  /* Yang: Tourou Zan, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_TOUROU_ZAN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_31[25] = {  /* Yang: Senkyuutai, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_SENKYUUTAI), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pA_cmd_32[25] = {  /* Yang: Byakko Soushouda, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(YANG_BYAKKO_SOUSHOUDA), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Ken's attack routines (routine_no[2]; 16 and up index pl11_exatt_table) */
#define KEN_HADOKEN                   16  /* Att_HADOUKEN */
#define KEN_SHORYUKEN                 17  /* Att_SHOURYUUKEN */
#define KEN_TATSUMAKI_SENPUKYAKU      18  /* Att_SENPUUKYAKU */
#define KEN_SHORYU_REPPA              19  /* Att_SHOURYUUREPPA */
#define KEN_SHINRYUKEN                20  /* Att_SHOURYUUREPPA */
#define KEN_SHIPPU_JINRAIKYAKU        21  /* Att_SLIDE_and_JUMP */
#define KEN_AIR_TATSUMAKI_SENPUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */

const s16 pB_cmd_20[33] = {  /* Ken: SA I Shoryu Reppa, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHORYU_REPPA), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pB_cmd_21[33] = {  /* Ken: SA II Shinryuken, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHINRYUKEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pB_cmd_22[33] = {  /* Ken: SA III Shippu Jinraikyaku, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(KEN_SHIPPU_JINRAIKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pB_cmd_28[25] = {  /* Ken: Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_SHORYUKEN), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pB_cmd_29[25] = {  /* Ken: Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_HADOKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pB_cmd_30[25] = {  /* Ken: Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 pB_cmd_46[25] = {  /* Ken: air Tatsumaki Senpukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(KEN_AIR_TATSUMAKI_SENPUKYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Sean's attack routines (routine_no[2]; 16 and up index pl12_exatt_table) */
#define SEAN_HADOU_BURST      16  /* Att_HADOUKEN */
#define SEAN_SHORYU_CANNON    17  /* Att_SHOURYUUREPPA */
#define SEAN_HYPER_TORNADO    18  /* Att_SLIDE_and_JUMP */
#define SEAN_RYUUBI_KYAKU     19  /* Att_ABISEGERI */
#define SEAN_ZENTEN           20  /* Att_CHOUCHUURENGEKI */
#define SEAN_TORNADO          21  /* Att_SHOURYUUKEN */
#define SEAN_SEAN_TACKLE      22  /* Att_CHOUCHUURENGEKI */
#define SEAN_DRAGON_SMASH     24  /* Att_SENPUUKYAKU */
#define SEAN_RYUUBI_KYAKU_EX  25  /* Att_HOMING_JUMP */

const s16 pC_cmd_20[33] = {  /* Sean: SA I Hadou Burst, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_HADOU_BURST), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_21[33] = {  /* Sean: SA II Shoryu Cannon, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_SHORYU_CANNON), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_22[33] = {  /* Sean: SA III Hyper Tornado, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(SEAN_HYPER_TORNADO), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_28[25] = {  /* Sean: Sean Tackle, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_SEAN_TACKLE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER_ANY(14, CMD_LV_DOWN),
    CMD_LEVER(14, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_29[25] = {  /* Sean: Dragon Smash, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_DRAGON_SMASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_30[25] = {  /* Sean: Ryuubi Kyaku, 236+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA_EX(SEAN_RYUUBI_KYAKU, SEAN_RYUUBI_KYAKU_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pC_cmd_31[25] = {  /* Sean: Zenten (roll), 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_ZENTEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 pC_cmd_32[25] = {  /* Sean: Tornado, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(SEAN_TORNADO), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Urien's attack routines (routine_no[2]; 16 and up index pl13_exatt_table) */
#define URIEN_METALLIC_SPHERE        16  /* Att_HADOUKEN */
#define URIEN_VIOLENCE_KNEE_DROP_EX  17  /* Att_MOONSALT_KNEE_DROP2 */
#define URIEN_DANGEROUS_HEADBUTT     19  /* Att_SENPUUKYAKU */
#define URIEN_TYRANT_SLAUGHTER       20  /* Att_CHOUCHUURENGEKI */
#define URIEN_TEMPORAL_THUNDER       21  /* Att_CHOUCHUURENGEKI */
#define URIEN_AEGIS_REFLECTOR        22  /* Att_HADOUKEN */
#define URIEN_CHARIOT_TACKLE         23  /* Att_CHOUCHUURENGEKI */
#define URIEN_VIOLENCE_KNEE_DROP     24  /* Att_SLIDE_and_JUMP */

const s16 pD_cmd_20[33] = {  /* Urien: SA I Tyrant Slaughter, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_TYRANT_SLAUGHTER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pD_cmd_21[33] = {  /* Urien: SA II Temporal Thunder, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_TEMPORAL_THUNDER), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pD_cmd_22[33] = {  /* Urien: SA III Aegis Reflector, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_AEGIS_REFLECTOR), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pD_cmd_28[21] = {  /* Urien: Chariot Tackle, [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(URIEN_CHARIOT_TACKLE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pD_cmd_29[21] = {  /* Urien: Violence Knee Drop, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA_EX(URIEN_VIOLENCE_KNEE_DROP, URIEN_VIOLENCE_KNEE_DROP_EX), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};
const s16 pD_cmd_30[25] = {  /* Urien: Metallic Sphere, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(URIEN_METALLIC_SPHERE), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pD_cmd_31[21] = {  /* Urien: Dangerous Headbutt, [2]8+P */
    CMD_RESET, 0, 0, CMD_WAZA(URIEN_DANGEROUS_HEADBUTT), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};

/* Gouki's attack routines (routine_no[2]; 16 and up index pl14_exatt_table) */
#define GOUKI_GOU_HADOKEN                16  /* Att_HADOUKEN */
#define GOUKI_GOU_SHORYUKEN              17  /* Att_SHOURYUUKEN */
#define GOUKI_TATSUMAKI_ZANKUUKYAKU      18  /* Att_SENPUUKYAKU */
#define GOUKI_MESSATSU_GOU_RASEN         19  /* Att_KUUCHUUJINNCHUUWATARI */
#define GOUKI_MESSATSU_GOU_SHORYU        20  /* Att_SHOURYUUREPPA */
#define GOUKI_AIR_TATSUMAKI_ZANKUUKYAKU  22  /* Att_KUUCHUUNICHIRINSHOU */
#define GOUKI_ZANKU_HADOKEN              25  /* Att_PL14_AT2 */
#define GOUKI_HYAKKISHUU                 27  /* Att_PL14_AT3 */

const s16 pE_cmd_20[33] = {  /* Gouki: SA I Messatsu Gou Hadou, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_GOU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_21[33] = {  /* Gouki: SA II Messatsu Gou Shoryu, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_MESSATSU_GOU_SHORYU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_22[33] = {  /* Gouki: SA III Messatsu Gou Rasen, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_GOU_SHORYUKEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_24[33] = {  /* Gouki: Shun Goku Satsu */
    CMD_RESET, 0, 0, 24, 24, 24, 24, CMD_BT_NOW | CMD_BT_ALWAYS,
    CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP), CMD_EX_ONLY(CMD_EX_HP),
    CMD_STEP(CK_PRESS, 0, 0, CMD_SW_LP),
    CMD_STEP(CK_PRESS, 10, 0, 0),
    CMD_STEP(CK_PRESS, 10, 0, CMD_SW_LP),
    CMD_STEP(CK_LEVER_PRESS, 16, 0, CMD_LV_FORWARD),
    CMD_STEP(CK_PRESS, 10, 0, CMD_SW_LK),
    CMD_END,
};
const s16 pE_cmd_25[33] = {  /* Gouki: Kongou Kokuretsu Zan */
    CMD_RESET, 0, 0, 26, 26, 26, 26, CMD_BT_CHG,
    CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP),
    CMD_STEP(CK_LEVER_PRESS, 1, 1, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_CHANGE, 6, 0, CMD_EXACT(CMD_LV_DOWN)),
    CMD_END,
};
const s16 pE_cmd_28[25] = {  /* Gouki: Ashura Senkuu (forward) */
    CMD_RESET, CMD_LV_UP, 0, 23, 23, 23, 23, CMD_BT_CHG,
    CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_KK), CMD_EX_ONLY(CMD_EX_KK),
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_29[25] = {  /* Gouki: Ashura Senkuu (back) */
    CMD_RESET, CMD_LV_UP, 0, 23, 23, 23, 23, CMD_BT_CHG,
    CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_PP), CMD_EX_ONLY(CMD_EX_KK), CMD_EX_ONLY(CMD_EX_KK),
    CMD_LEVER(0, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_END,
};
const s16 pE_cmd_30[25] = {  /* Gouki: Gou Shoryuken, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_GOU_SHORYUKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_31[25] = {  /* Gouki: Gou Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_GOU_HADOKEN), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_32[25] = {  /* Gouki: Tatsumaki Zankuukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_TATSUMAKI_ZANKUUKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 pE_cmd_33[29] = {  /* Gouki: Shakunetsu Hadoken, 63214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_GOU_HADOKEN), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 pE_cmd_34[17] = {  /* Gouki: disabled slot */
    CMD_RESET, CMD_LV_UP, 0, 21, 21, 21, 21, CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_NONE, 0, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_END,
};
const s16 pE_cmd_35[25] = {  /* Gouki: Hyakkishuu, 623+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_HYAKKISHUU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_38[33] = {  /* Gouki: SA I Messatsu Gou Hadou (air), 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_ZANKU_HADOKEN), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_39[33] = {  /* Gouki: SA III Messatsu Gou Rasen (air), 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(GOUKI_MESSATSU_GOU_RASEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_46[25] = {  /* Gouki: Zanku Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_ZANKU_HADOKEN), CMD_BT_CHG | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 pE_cmd_47[25] = {  /* Gouki: air Tatsumaki Zankuukyaku, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(GOUKI_AIR_TATSUMAKI_ZANKUUKYAKU), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Chun-Li's attack routines (routine_no[2]; 16 and up index pl16_exatt_table) */
#define CHUN_LI_SPINNING_BIRD_KICK  16  /* Att_SENPUUKYAKU */
#define CHUN_LI_HYAKURETSU_KYAKU    17  /* Att_HADOUKEN2 */
#define CHUN_LI_KIKOUSHOU           18  /* Att_HADOUKEN */
#define CHUN_LI_KIKOUKEN            19  /* Att_HADOUKEN */
#define CHUN_LI_HOUYOKU_SEN         20  /* Att_SLIDE_and_JUMP */
#define CHUN_LI_HAZAN_SHUU          21  /* Att_SLIDE_and_JUMP */
#define CHUN_LI_TENSEI_RANKA        22  /* Att_SLIDE_and_JUMP */

const s16 p10_cmd_20[33] = {  /* Chun-Li: SA I Kikoushou, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(CHUN_LI_KIKOUSHOU), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p10_cmd_21[33] = {  /* Chun-Li: SA II Houyoku Sen, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(CHUN_LI_HOUYOKU_SEN), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p10_cmd_22[33] = {  /* Chun-Li: SA III Tensei Ranka, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(CHUN_LI_TENSEI_RANKA), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p10_cmd_28[21] = {  /* Chun-Li: Spinning Bird Kick, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA(CHUN_LI_SPINNING_BIRD_KICK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};
const s16 p10_cmd_29[17] = {  /* Chun-Li: Hyakuretsu Kyaku, K five times */
    10, CMD_LV_UP, 0, CMD_WAZA(CHUN_LI_HYAKURETSU_KYAKU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_RENDA, 98, 98, CMD_SW_LK),
    CMD_END,
};
const s16 p10_cmd_30[29] = {  /* Chun-Li: Kikouken, 41236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(CHUN_LI_KIKOUKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p10_cmd_31[29] = {  /* Chun-Li: Hazan Shuu, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(CHUN_LI_HAZAN_SHUU), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Makoto's attack routines (routine_no[2]; 16 and up index pl17_exatt_table) */
#define MAKOTO_HAYATE          16  /* Att_CHOUCHUURENGEKI */
#define MAKOTO_ABARE_TOSANAMI  17  /* Att_PL17_AT1 */
#define MAKOTO_FUKIAGE         18  /* Att_HADOUKEN2 */
#define MAKOTO_TANDEN_RENKI    19  /* Att_PL17_AT2 */
#define MAKOTO_TSURUGI         20  /* Att_KUUCHUUJINNCHUUWATARI */

const s16 p11_cmd_20[33] = {  /* Makoto: SA II Abare Tosanami, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(MAKOTO_ABARE_TOSANAMI), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p11_cmd_21[33] = {  /* Makoto: SA III Tanden Renki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(MAKOTO_TANDEN_RENKI), CMD_BT_CHG | CMD_BT_FOURTH, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p11_cmd_22[33] = {  /* Makoto: SA I Seichuusen Godanzuki, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(MAKOTO_FUKIAGE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p11_cmd_28[25] = {  /* Makoto: Fukiage, 623+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(MAKOTO_FUKIAGE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_LEVER_OFF, 1, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_LEVER(5, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p11_cmd_29[25] = {  /* Makoto: Oroshi, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(MAKOTO_FUKIAGE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p11_cmd_30[25] = {  /* Makoto: Hayate, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(MAKOTO_HAYATE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p11_cmd_31[29] = {  /* Makoto: Karakusa, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(MAKOTO_HAYATE), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p11_cmd_46[25] = {  /* Makoto: Tsurugi, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(MAKOTO_TSURUGI), CMD_BT_CHG | CMD_BT_EX | CMD_BT_NOT_BACK, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

/* Q's attack routines (routine_no[2]; 16 and up index pl18_exatt_table) */
#define Q_DASHING_HEAD_ATTACK        16  /* Att_SLIDE_and_JUMP */
#define Q_DASHING_LEG_ATTACK         17  /* Att_SLIDE_and_JUMP */
#define Q_HIGH_SPEED_BARRAGE         18  /* Att_HADOUKEN2 */
#define Q_CAPTURE_AND_DEADLY_BLOW    19  /* Att_HADOUKEN2 */
#define Q_CRITICAL_COMBO_ATTACK      20  /* Att_SLIDE_and_JUMP */
#define Q_DEADLY_DOUBLE_COMBINATION  21  /* Att_HADOUKEN2 */
#define Q_TOTAL_DESTRUCTION          22  /* Att_HADOUKEN */
#define Q_NINGENBAKUDAN              23  /* Att_PL18_NINGENBAKUDAN */

const s16 p12_cmd_20[33] = {  /* Q: SA I Critical Combo Attack, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(Q_CRITICAL_COMBO_ATTACK), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_21[33] = {  /* Q: SA II Deadly Double Combination, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(Q_DEADLY_DOUBLE_COMBINATION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_22[33] = {  /* Q: SA III Total Destruction, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(Q_TOTAL_DESTRUCTION), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_28[21] = {  /* Q: Dashing Head Attack, [4]6+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(Q_DASHING_HEAD_ATTACK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_29[21] = {  /* Q: Dashing Leg Attack, [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(Q_DASHING_LEG_ATTACK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_30[25] = {  /* Q: High Speed Barrage, 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(Q_HIGH_SPEED_BARRAGE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p12_cmd_31[29] = {  /* Q: Capture and Deadly Blow, 63214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(Q_CAPTURE_AND_DEADLY_BLOW), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p12_cmd_32[25] = {  /* Q: Ningen Bakudan (Att_PL18_NINGENBAKUDAN), only while the super art is active (?) */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(Q_NINGENBAKUDAN), CMD_BT_CHG | CMD_BT_SA_ONLY, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p12_cmd_33[25] = {  /* Q: the same motion with a kick, only while the super art is active (?) */
    CMD_RESET, CMD_LV_UP, 0, 24, 24, 24, 24, CMD_BT_CHG | CMD_BT_SA_ONLY, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};

/* Twelve's attack routines (routine_no[2]; 16 and up index pl19_exatt_table) */
#define TWELVE_AXE               16  /* Att_HADOUKEN */
#define TWELVE_AIR_DASH_FORWARD  17  /* Att_AIRDASH */
#define TWELVE_DRA               18  /* Att_KUUCHUUHISSATU */
#define TWELVE_NDL               19  /* Att_HADOUKEN */
#define TWELVE_XNDL              20  /* Att_HADOUKEN */
#define TWELVE_XCOPY             22  /* Att_METAMORPHOSE */
#define TWELVE_AIR_AXE           23  /* Att_AIR_A_X_E */
#define TWELVE_XFLAT             27  /* Att_SA__D_R_A */

const s16 p13_cmd_20[33] = {  /* Twelve: SA I X.N.D.L., 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_XNDL), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p13_cmd_21[33] = {  /* Twelve: SA III X.C.O.P.Y., 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_XCOPY), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p13_cmd_38[33] = {  /* Twelve: SA II X.F.L.A.T. (air), 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_XFLAT), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p13_cmd_28[25] = {  /* Twelve: A.X.E., 214+P */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_AXE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p13_cmd_29[25] = {  /* Twelve: N.D.L., 236+P */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_NDL), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p13_cmd_30[25] = {  /* Twelve: N.D.L. (kick), 236+K */
    CMD_RESET, 0, 0, CMD_WAZA(TWELVE_NDL), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p13_cmd_46[29] = {  /* Twelve: air dash forward */
    8, CMD_LV_BACK, CMD_LV_DOWN, CMD_WAZA(TWELVE_AIR_DASH_FORWARD), CMD_BT_NONE, 0, 0, 0, 0,
    CMD_STEP(CK_LEVER, 1, 1, CMD_LV_FORWARD),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_FORWARD)),
    CMD_END,
};
const s16 p13_cmd_47[25] = {  /* Twelve: D.R.A., 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(TWELVE_DRA), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p13_cmd_48[25] = {  /* Twelve: air A.X.E., 214+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(TWELVE_AIR_AXE), CMD_BT_CHG | CMD_BT_EX, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};
const s16 p13_cmd_49[29] = {  /* Twelve: air dash back */
    8, CMD_LV_FORWARD, CMD_LV_DOWN, CMD_WAZA(TWELVE_AIR_DASH_FORWARD), CMD_BT_NONE, 0, 0, 0, 0,
    CMD_LEVER_ANY(1, CMD_LV_BACK),
    CMD_LEVER_ANY(6, CMD_LV_NEUTRAL),
    CMD_STEP(CK_LEVER_SET, 6, 0, CMD_EXACT(CMD_LV_BACK)),
    CMD_STEP(CK_LEVER_REPEAT, 6, 6, CMD_EXACT(CMD_LV_BACK)),
    CMD_END,
};

/* Remy's attack routines (routine_no[2]; 16 and up index pl20_exatt_table) */
#define REMY_LIGHT_OF_VIRTUE    16  /* Att_HADOUKEN */
#define REMY_RISING_RAGE_FLASH  17  /* Att_PL20_AT1 */
#define REMY_COLD_BLUE_KICK     18  /* Att_PL20_AT2 */
#define REMY_BLUE_NOCTURNE      20  /* Att_HADOUKEN */

const s16 p14_cmd_20[33] = {  /* Remy: SA I Light of Justice, 236236+P */
    CMD_RESET, 0, 0, CMD_WAZA(REMY_LIGHT_OF_VIRTUE), CMD_BT_CHG, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p14_cmd_21[33] = {  /* Remy: SA III Blue Nocturne, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(REMY_BLUE_NOCTURNE), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p14_cmd_22[33] = {  /* Remy: SA II Supreme Rising Rage Flash, 236236+K */
    CMD_RESET, 0, 0, CMD_WAZA(REMY_RISING_RAGE_FLASH), CMD_BT_CHG, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_LEVER(14, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),
    CMD_END,
};
const s16 p14_cmd_28[21] = {  /* Remy: Rising Rage Flash, [2]8+K */
    CMD_RESET, 0, 0, CMD_WAZA(REMY_RISING_RAGE_FLASH), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_DOWN),
    CMD_LEVER_ANY(10, CMD_LV_UP),
    CMD_END,
};
const s16 p14_cmd_29[21] = {  /* Remy: Light of Virtue (high), [4]6+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(REMY_LIGHT_OF_VIRTUE), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p14_cmd_30[21] = {  /* Remy: Light of Virtue (low), [4]6+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(REMY_LIGHT_OF_VIRTUE), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_KICKS,
    CMD_STEP(CK_CHARGE, 42, 42, CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_FORWARD),
    CMD_END,
};
const s16 p14_cmd_31[25] = {  /* Remy: Cold Blue Kick, 214+K */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(REMY_COLD_BLUE_KICK), CMD_BT_CHG | CMD_BT_EX, CMD_EX_KICKS,
    CMD_LEVER(0, CMD_LV_DOWN),
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_BACK),
    CMD_LEVER(10, CMD_LV_BACK),
    CMD_END,
};

const s16 ukemi_time_tbl[17] = {
    0, 0, 1, 1, 2, 2, 3, 3,
    4, 4, 5, 5, 6, 6, 7, 7,
    7,
};

const char player_cmd_0[20] = "UP    =    SHOT1 =\n";

const char player_cmd_1[20] = "DOWN  =    SHOT2 =\n";

const char player_cmd_2[20] = "LEFT  =    SHOT3 =\n";

const char player_cmd_3[20] = "RIGHT =    SHOT4 =\n";

const char player_cmd_4[20] = "DIR        SHOT5 =\n";

const char player_cmd_5[12] = "SHOT6 =\n";

const char player_cmd_11[8] = "SHOT6 =";

const char lvr_chk_tbl_0[4] = "S ";

const char lvr_chk_tbl_1[4] = "M ";

const char lvr_chk_tbl_2[4] = "L ";

#pragma section

/* 02005024 */
const s16* pl_cmd_list[21][56] = {
    { /* gill */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p0_cmd_20, p0_cmd_21, p0_cmd_22, dm_cmd_xx,
        p0_cmd_24, p0_cmd_25, dm_cmd_xx, dm_cmd_xx,
        p0_cmd_28, p0_cmd_29, p0_cmd_30, p0_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* alex */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p1_cmd_20, p1_cmd_21, p1_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p1_cmd_28, p1_cmd_29, p1_cmd_30, p1_cmd_31,
        p1_cmd_32, p1_cmd_33, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* ryu */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p2_cmd_20, p2_cmd_21, p2_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p2_cmd_28, p2_cmd_29, p2_cmd_30, p2_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p2_cmd_46, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* yun */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p3_cmd_20, p3_cmd_21, p3_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p3_cmd_28, p3_cmd_29, p3_cmd_30, p3_cmd_31,
        p3_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* dudley */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p4_cmd_20, p4_cmd_21, p4_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p4_cmd_28, p4_cmd_29, p4_cmd_30, p4_cmd_31,
        p4_cmd_32, p4_cmd_33, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* necro */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p5_cmd_20, p5_cmd_21, p5_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p5_cmd_28, p5_cmd_29, p5_cmd_30, p5_cmd_31,
        p5_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* hugo */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p6_cmd_20, p6_cmd_21, p6_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p6_cmd_28, p6_cmd_29, p6_cmd_30, p6_cmd_31,
        p6_cmd_32, p6_cmd_33, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* ibuki */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p7_cmd_20, p7_cmd_21, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p7_cmd_28, p7_cmd_29, p7_cmd_30, p7_cmd_31,
        p7_cmd_32, p7_cmd_33, p7_cmd_34, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p7_cmd_38, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p7_cmd_46, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* elena */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p8_cmd_20, p8_cmd_21, p8_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p8_cmd_28, p8_cmd_29, p8_cmd_30, p8_cmd_31,
        p8_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* oro */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p9_cmd_20, p9_cmd_21, p9_cmd_22, dm_cmd_xx,
        p9_cmd_24, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p9_cmd_28, p9_cmd_29, p9_cmd_30, p9_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p9_cmd_46, p9_cmd_47,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* yang */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pA_cmd_20, pA_cmd_21, pA_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pA_cmd_28, pA_cmd_29, pA_cmd_30, pA_cmd_31,
        pA_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* ken */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pB_cmd_20, pB_cmd_21, pB_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pB_cmd_28, pB_cmd_29, pB_cmd_30, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, pB_cmd_46, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* sean */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pC_cmd_20, pC_cmd_21, pC_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pC_cmd_28, pC_cmd_29, pC_cmd_30, pC_cmd_31,
        pC_cmd_32, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* urien */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pD_cmd_20, pD_cmd_21, pD_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pD_cmd_28, pD_cmd_29, pD_cmd_30, pD_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* gouki1 */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pE_cmd_20, pE_cmd_21, pE_cmd_22, dm_cmd_xx,
        pE_cmd_24, pE_cmd_25, dm_cmd_xx, dm_cmd_xx,
        pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31,
        pE_cmd_32, pE_cmd_33, pE_cmd_34, pE_cmd_35,
        dm_cmd_xx, dm_cmd_xx, pE_cmd_38, pE_cmd_39,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* gouki2 */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        pE_cmd_20, pE_cmd_21, pE_cmd_22, dm_cmd_xx,
        pE_cmd_24, pE_cmd_25, dm_cmd_xx, dm_cmd_xx,
        pE_cmd_28, pE_cmd_29, pE_cmd_30, pE_cmd_31,
        pE_cmd_32, pE_cmd_33, pE_cmd_34, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, pE_cmd_38, pE_cmd_39,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, pE_cmd_46, pE_cmd_47,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* chun */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p10_cmd_20, p10_cmd_21, p10_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p10_cmd_28, p10_cmd_29, p10_cmd_30, p10_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* makoto */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p11_cmd_20, p11_cmd_21, p11_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p11_cmd_28, p11_cmd_29, p11_cmd_30, p11_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p11_cmd_46, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* q */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p12_cmd_20, p12_cmd_21, p12_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p12_cmd_28, p12_cmd_29, p12_cmd_30, p12_cmd_31,
        p12_cmd_32, p12_cmd_33, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* no12 */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p13_cmd_20, p13_cmd_21, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p13_cmd_28, p13_cmd_29, p13_cmd_30, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p13_cmd_38, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, p13_cmd_46, p13_cmd_47,
        p13_cmd_48, p13_cmd_49, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
    { /* remy */
        pc_cmd_00, pc_cmd_01, pc_cmd_02, pc_cmd_03,
        pc_cmd_04, pc_cmd_05, pc_cmd_06, pc_cmd_07,
        pc_cmd_08, pc_cmd_09, pc_cmd_10, pc_cmd_11,
        pc_cmd_12, pc_cmd_13, pc_cmd_14, pc_cmd_15,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p14_cmd_20, p14_cmd_21, p14_cmd_22, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        p14_cmd_28, p14_cmd_29, p14_cmd_30, p14_cmd_31,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
        dm_cmd_xx, dm_cmd_xx, dm_cmd_xx, dm_cmd_xx,
    },
};
/* 02006284 */
void* pl_CMD[24] = {
    pl_cmd_list[0],
    pl_cmd_list[1],
    pl_cmd_list[2],
    pl_cmd_list[3],
    pl_cmd_list[4],
    pl_cmd_list[5],
    pl_cmd_list[6],
    pl_cmd_list[7],
    pl_cmd_list[8],
    pl_cmd_list[9],
    pl_cmd_list[10],
    pl_cmd_list[11],
    pl_cmd_list[12],
    pl_cmd_list[13],
    pl_cmd_list[14],
    pl_cmd_list[15],
    pl_cmd_list[16],
    pl_cmd_list[17],
    pl_cmd_list[18],
    pl_cmd_list[19],
    pl_cmd_list[20],
    pl_cmd_list[0],
    pl_cmd_list[0],
    pl_cmd_list[0],
};
/* 020062E4 */
const_s16_arr* player_cmd[24] = {
    pl_cmd_list[0],
    pl_cmd_list[1],
    pl_cmd_list[2],
    pl_cmd_list[3],
    pl_cmd_list[4],
    pl_cmd_list[5],
    pl_cmd_list[6],
    pl_cmd_list[7],
    pl_cmd_list[8],
    pl_cmd_list[9],
    pl_cmd_list[10],
    pl_cmd_list[11],
    pl_cmd_list[12],
    pl_cmd_list[13],
    pl_cmd_list[14],
    pl_cmd_list[15],
    pl_cmd_list[16],
    pl_cmd_list[17],
    pl_cmd_list[18],
    pl_cmd_list[19],
    pl_cmd_list[20],
    pl_cmd_list[0],
    pl_cmd_list[0],
    pl_cmd_list[0],
};
/* provisional name */
/* Text lines of the key-assignment display, stored after player_cmd. Nothing in the program refers to
   them. */
TMLINE player_cmd_lines[12] = {
    { 1, 12, 14, 0, (u8*)player_cmd_0 },
    { 1, 13, 14, 0, (u8*)player_cmd_1 },
    { 1, 14, 14, 0, (u8*)player_cmd_2 },
    { 1, 15, 14, 0, (u8*)player_cmd_3 },
    { 1, 16, 14, 0, (u8*)player_cmd_4 },
    { 12, 17, 14, 0, (u8*)player_cmd_5 },
    { 23, 12, 14, 0, (u8*)player_cmd_0 },
    { 23, 13, 14, 0, (u8*)player_cmd_1 },
    { 23, 14, 14, 0, (u8*)player_cmd_2 },
    { 23, 15, 14, 0, (u8*)player_cmd_3 },
    { 23, 16, 14, 0, (u8*)player_cmd_4 },
    { 34, 17, 14, 0, (u8*)player_cmd_11 },
};
/* provisional name */
/* Stored after player_cmd_lines: (x, y) cell positions. Nothing in the program refers to it. */
u16 player_cmd_cells[28][2] = {
    { 11, 3 }, { 26, 3 }, { 11, 7 }, { 26, 7 },
    { 15, 3 }, { 30, 3 }, { 15, 7 }, { 30, 7 },
    { 13, 3 }, { 28, 3 }, { 13, 7 }, { 28, 7 },
    { 11, 5 }, { 26, 5 }, { 15, 5 }, { 30, 5 },
    { 11, 9 }, { 26, 9 }, { 13, 9 }, { 28, 9 },
    { 15, 9 }, { 30, 9 }, { 11, 10 }, { 26, 10 },
    { 13, 10 }, { 28, 10 }, { 15, 10 }, { 30, 10 },
};
/* 02006444 */
s16 lvr_chk_tbl[2][4] = {
    { 5, 6, 9, 10 },
    { 1, 2, 4, 8 },
};
/* 02006454 */
/* provisional name */
/* Text lines of the lever-check display, stored after lvr_chk_tbl. Nothing in the program refers to them. */
TMLINE lvr_chk_lines[6] = {
    { 6, 19, 6, 0, (u8*)lvr_chk_tbl_0 },
    { 6, 19, 6, 0, (u8*)lvr_chk_tbl_1 },
    { 6, 19, 6, 0, (u8*)lvr_chk_tbl_2 },
    { 29, 19, 6, 0, (u8*)lvr_chk_tbl_0 },
    { 29, 19, 6, 0, (u8*)lvr_chk_tbl_1 },
    { 29, 19, 6, 0, (u8*)lvr_chk_tbl_2 },
};

T_PL_LVR t_pl_lvr[2];  /* 0202563C */
WAZA_WORK waza_work[2][56];  /* 020256C4 */
u8 waza_work_tail[2];  /* after waza_work; nothing refers to it by name or address */
u16 sw_work;  /* 02026306 */
s16 * cmd_tbl_ptr;  /* 02026308 */
s16 waza_type[2];  /* 0202630C */
T_PL_LVR * chk_pl;  /* 02026310 */
WAZA_WORK * waza_ptr;  /* 02026314 */
WORK_CP wcp[2];  /* 02026318 */
s16 cmd_id;  /* 02026B24 */
PLW * cmd_pl;  /* 02026B28 */
u8 cmd_pl_tail[4];  /* after cmd_pl; nothing refers to it by name or address */
