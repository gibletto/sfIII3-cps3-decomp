/*
 * PLS03_TBL.C  attack button and command check tables
 *
 * Button decoding tables for the normal attack, throw and cancel checks: shot_prio,
 * shot_refresh and rc_shot_conv turn pressed buttons into an attack strength, cnmc_conv_data
 * with cnmc_Z_lever_data and cnmc_z_lever_data list the lever and button combinations for
 * target combos, renda_status_table the rapid-fire postures, nml_catch_h2_ok the per-character
 * throw permissions and gml_real_lever_data the real lever direction; these are read by
 * PLS03ATT.C. cmdshot_conv_tbl turns command button codes into button bits for the super art
 * checks in PLS03.C.
 */

#include "types.h"
#include "structs.h"
#include "cmd_data.h"

#pragma section TBL


const u8 nml_catch_h2_ok[2][24] = {
    { 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 17, 0, 17, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0 },
};

const s16 shot_prio[6][2] = {
    { 256, 3 }, { 16, 0 }, { 512, 4 }, { 32, 1 }, { 1024, 5 }, { 64, 2 },
};

const s16 shot_refresh[6] = {
    CMD_SW_LP, CMD_SW_MP, CMD_SW_HP, CMD_SW_LK, CMD_SW_MK, CMD_SW_HK,
};

const s16 rc_shot_conv[16] = {
    16, 32, 64, 112, 128, 256, 512, 896,
    144, 288, 576, 1008, 0, 0, 0, 0,
};

const u8 renda_status_table[4] = {
    0, 20, 32, 0,
};

const s16 cnmc_conv_data[16] = {
    5, 8, 2, 0, 4, 7, 1, 0,
    6, 9, 3, 0, 0, 0, 0, 0,
};

const s16 cnmc_Z_lever_data[16][6] = {
    { 0, -1, -1, -1, -1, -1 },
    { 1, -1, -1, -1, -1, -1 },
    { 2, -1, -1, -1, -1, -1 },
    { 3, -1, -1, -1, -1, -1 },
    { 4, -1, -1, -1, -1, -1 },
    { 5, -1, -1, -1, -1, -1 },
    { 6, -1, -1, -1, -1, -1 },
    { 7, -1, -1, -1, -1, -1 },
    { 8, -1, -1, -1, -1, -1 },
    { 9, -1, -1, -1, -1, -1 },
    { 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6 },
    { 4, 5, -1, -1, -1, -1 },
    { 5, 6, -1, -1, -1, -1 },
    { 4, 6, -1, -1, -1, -1 },
    { 4, 5, 6, -1, -1, -1 },
};

const s16 cnmc_z_lever_data[16][8] = {
    { -1, -1, -1, -1, -1, -1, -1, -1 },
    { 4, 1, 2, -1, -1, -1, -1, -1 },
    { 1, 2, 3, -1, -1, -1, -1, -1 },
    { 2, 3, 6, -1, -1, -1, -1, -1 },
    { 1, 4, 7, -1, -1, -1, -1, -1 },
    { 1, 2, 3, 4, 6, 7, 8, 9 },
    { 3, 6, 9, -1, -1, -1, -1, -1 },
    { 4, 7, 8, -1, -1, -1, -1, -1 },
    { 7, 8, 9, -1, -1, -1, -1, -1 },
    { 8, 9, 6, -1, -1, -1, -1, -1 },
    { 1, 3, 4, 5, 6, 7, 8, 9 },
    { 1, 2, 3, 4, 5, 6, 7, 9 },
    { 1, 4, 5, 7, -1, -1, -1, -1 },
    { 3, 5, 6, 9, -1, -1, -1, -1 },
    { 1, 4, 7, 3, 6, 9, -1, -1 },
    { 1, 4, 7, 5, 3, 6, 9, -1 },
};

const s16 gml_real_lever_data[16] = {
    0, 6, 2, 10, 4, 0, 8, 5,
    1, 9, 0, 0, 4, 8, 4, 8,
};

/* exdt codes (cmd_data.h) to buttons: [ex & CMD_EX_BUTTON] the buttons needed, [ex] the buttons
   looked at */
const s16 cmdshot_conv_tbl[32] = {
    CMD_SW_LP, CMD_SW_MP, CMD_SW_HP, CMD_SW_PP,
    CMD_SW_LK, CMD_SW_MK, CMD_SW_HK, CMD_SW_KK,
    CMD_SW_LP | CMD_SW_LK, CMD_SW_MP | CMD_SW_MK, CMD_SW_HP | CMD_SW_HK, CMD_SW_PP | CMD_SW_KK,
    0, 0, 0, 0,
    CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_PP | CMD_SW_KICK,
    CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_PUNCH | CMD_SW_KK,
    CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_SHOT, CMD_SW_PP | CMD_SW_KK,
    0, 0, 0, 0,
};
