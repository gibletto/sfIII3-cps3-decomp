/*
 * SYS_CONFIG_TBL.C  test mode system configuration values
 *
 * coin_rate_tbl gives the coins and credits of each coin setting (SYS_CONFIG.C and
 * SYS_CONFIG_2.C). The coin_setting_, chute_mode_, on_off_, sound_mode_ and monitor_ string
 * tables place the value texts of the system configuration page (coin and chute settings,
 * on/off, sound output, language, monitor), which are the str_ strings; cursor_mark_str and
 * cursor_blank_str draw the menu cursor. Read by SYS_CONFIG_2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const TM_STRING chute_mode_str_tbl_0[];
extern const TM_STRING chute_mode_str_tbl_1[];
extern const TM_STRING chute_mode_str_tbl_10[];
extern const TM_STRING chute_mode_str_tbl_11[];
extern const TM_STRING chute_mode_str_tbl_2[];
extern const TM_STRING chute_mode_str_tbl_3[];
extern const TM_STRING chute_mode_str_tbl_4[];
extern const TM_STRING chute_mode_str_tbl_5[];
extern const TM_STRING chute_mode_str_tbl_6[];
extern const TM_STRING chute_mode_str_tbl_7[];
extern const TM_STRING chute_mode_str_tbl_8[];
extern const TM_STRING chute_mode_str_tbl_9[];
extern const TM_STRING coin_setting_str_tbl_0[];
extern const TM_STRING coin_setting_str_tbl_1[];
extern const TM_STRING coin_setting_str_tbl_10[];
extern const TM_STRING coin_setting_str_tbl_11[];
extern const TM_STRING coin_setting_str_tbl_12[];
extern const TM_STRING coin_setting_str_tbl_13[];
extern const TM_STRING coin_setting_str_tbl_14[];
extern const TM_STRING coin_setting_str_tbl_15[];
extern const TM_STRING coin_setting_str_tbl_16[];
extern const TM_STRING coin_setting_str_tbl_17[];
extern const TM_STRING coin_setting_str_tbl_18[];
extern const TM_STRING coin_setting_str_tbl_2[];
extern const TM_STRING coin_setting_str_tbl_3[];
extern const TM_STRING coin_setting_str_tbl_4[];
extern const TM_STRING coin_setting_str_tbl_5[];
extern const TM_STRING coin_setting_str_tbl_6[];
extern const TM_STRING coin_setting_str_tbl_7[];
extern const TM_STRING coin_setting_str_tbl_8[];
extern const TM_STRING coin_setting_str_tbl_9[];
extern const TM_STRING monitor_str_tbl_1[];
extern const TM_STRING on_off_str_tbl_0[];
extern const TM_STRING on_off_str_tbl_1[];
extern const TM_STRING sound_mode_str_tbl_0[];
extern const TM_STRING sound_mode_str_tbl_1[];
extern const TM_STRING sound_mode_str_tbl_2[];
extern const TM_STRING sound_mode_str_tbl_3[];
extern const TM_STRING sound_mode_str_tbl_4[];
extern const TM_STRING sound_mode_str_tbl_5[];

extern const s8 str_1coin_1credit[];
extern const s8 str_1coin_2credits[];
extern const s8 str_3coins_1credit[];
extern const s8 str_4coins_1credit[];
extern const s8 str_5coins_1credit[];
extern const s8 str_6coins_1credit[];
extern const s8 str_7coins_1credit[];
extern const s8 str_8coins_1credit[];
extern const s8 str_9coins_1credit[];
extern const s8 str_2coins_start_1coin_cont[];
extern const s8 str_coin_free_play[];
extern const s8 str_2pl_1chute_single[];
extern const s8 str_1coin_3credits[];
extern const s8 str_2pl_2chutes_single[];
extern const s8 str_2pl_2chutes_multi[];
extern const s8 str_3pl_1chute_single[];
extern const s8 str_3pl_2chutes_single[];
extern const s8 str_3pl_3chutes_single[];
extern const s8 str_3pl_3chutes_multi[];
extern const s8 str_4pl_1chute_single[];
extern const s8 str_4pl_2chutes_single[];
extern const s8 str_4pl_2chutes_multi[];
extern const s8 str_4pl_4chutes_single[];
extern const s8 str_1coin_4credits[];
extern const s8 str_4pl_4chutes_multi[];
extern const s8 str_cfg_on[];
extern const s8 str_cfg_off[];
extern const s8 str_cfg_external[];
extern const s8 str_cfg_jamma[];
extern const s8 str_cfg_english[];
extern const s8 str_cfg_spanish[];
extern const s8 str_cfg_portuguese[];
extern const s8 str_cfg_normal[];
extern const char str_cfg_flip[];
extern const s8 str_1coin_5credits[];
extern const s8 str_1coin_6credits[];
extern const s8 str_1coin_7credits[];
extern const s8 str_1coin_8credits[];
extern const s8 str_1coin_9credits[];
extern const s8 str_2coins_1credit[];

/* one row per coin setting (Coin_Mode): { coins, credits } */
const u8 coin_rate_tbl[20][2] = {
    { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 1, 6 }, { 1, 7 }, { 1, 8 },
    { 1, 9 }, { 2, 1 }, { 3, 1 }, { 4, 1 }, { 5, 1 }, { 6, 1 }, { 7, 1 }, { 8, 1 },
    { 9, 1 }, { 1, 1 }, { 0, 0 }, { 0, 0 },
};

const TM_STRING coin_setting_str_tbl_0[1] = {
    { 18, 5, 0xE, str_1coin_1credit },
};

const TM_STRING coin_setting_str_tbl_1[1] = {
    { 18, 5, 0xE, str_1coin_2credits },
};

const TM_STRING coin_setting_str_tbl_2[1] = {
    { 18, 5, 0xE, str_1coin_3credits },
};

const TM_STRING coin_setting_str_tbl_3[1] = {
    { 18, 5, 0xE, str_1coin_4credits },
};

const TM_STRING coin_setting_str_tbl_4[1] = {
    { 18, 5, 0xE, str_1coin_5credits },
};

const TM_STRING coin_setting_str_tbl_5[1] = {
    { 18, 5, 0xE, str_1coin_6credits },
};

const TM_STRING coin_setting_str_tbl_6[1] = {
    { 18, 5, 0xE, str_1coin_7credits },
};

const TM_STRING coin_setting_str_tbl_7[1] = {
    { 18, 5, 0xE, str_1coin_8credits },
};

const TM_STRING coin_setting_str_tbl_8[1] = {
    { 18, 5, 0xE, str_1coin_9credits },
};

const TM_STRING coin_setting_str_tbl_9[1] = {
    { 18, 5, 0xE, str_2coins_1credit },
};

const TM_STRING coin_setting_str_tbl_10[1] = {
    { 18, 5, 0xE, str_3coins_1credit },
};

const TM_STRING coin_setting_str_tbl_11[1] = {
    { 18, 5, 0xE, str_4coins_1credit },
};

const TM_STRING coin_setting_str_tbl_12[1] = {
    { 18, 5, 0xE, str_5coins_1credit },
};

const TM_STRING coin_setting_str_tbl_13[1] = {
    { 18, 5, 0xE, str_6coins_1credit },
};

const TM_STRING coin_setting_str_tbl_14[1] = {
    { 18, 5, 0xE, str_7coins_1credit },
};

const TM_STRING coin_setting_str_tbl_15[1] = {
    { 18, 5, 0xE, str_8coins_1credit },
};

const TM_STRING coin_setting_str_tbl_16[1] = {
    { 18, 5, 0xE, str_9coins_1credit },
};

const TM_STRING coin_setting_str_tbl_17[1] = {
    { 18, 5, 0xE, str_2coins_start_1coin_cont },
};

const TM_STRING coin_setting_str_tbl_18[1] = {
    { 18, 5, 0xE, str_coin_free_play },
};

const TM_STRING chute_mode_str_tbl_0[1] = {
    { 18, 7, 0xE, str_2pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_1[1] = {
    { 18, 7, 0xE, str_2pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_2[1] = {
    { 18, 7, 0xE, str_2pl_2chutes_multi },
};

const TM_STRING chute_mode_str_tbl_3[1] = {
    { 18, 7, 0xE, str_3pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_4[1] = {
    { 18, 7, 0xE, str_3pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_5[1] = {
    { 18, 7, 0xE, str_3pl_3chutes_single },
};

const TM_STRING chute_mode_str_tbl_6[1] = {
    { 18, 7, 0xE, str_3pl_3chutes_multi },
};

const TM_STRING chute_mode_str_tbl_7[1] = {
    { 18, 7, 0xE, str_4pl_1chute_single },
};

const TM_STRING chute_mode_str_tbl_8[1] = {
    { 18, 7, 0xE, str_4pl_2chutes_single },
};

const TM_STRING chute_mode_str_tbl_9[1] = {
    { 18, 7, 0xE, str_4pl_2chutes_multi },
};

const TM_STRING chute_mode_str_tbl_10[1] = {
    { 18, 7, 0xE, str_4pl_4chutes_single },
};

const TM_STRING chute_mode_str_tbl_11[1] = {
    { 18, 7, 0xE, str_4pl_4chutes_multi },
};

const TM_STRING on_off_str_tbl_1[1] = {
    { 18, 11, 0xE, str_cfg_on },
};

const TM_STRING on_off_str_tbl_0[1] = {
    { 18, 11, 0xE, str_cfg_off },
};

const TM_STRING sound_mode_str_tbl_0[1] = {
    { 18, 16, 0xE, str_cfg_external },
};

const TM_STRING sound_mode_str_tbl_1[1] = {
    { 18, 16, 0xE, str_cfg_jamma },
};

const TM_STRING sound_mode_str_tbl_2[1] = {
    { 18, 19, 0xE, str_cfg_english },
};

const TM_STRING sound_mode_str_tbl_3[1] = {
    { 18, 19, 0xE, str_cfg_spanish },
};

const TM_STRING sound_mode_str_tbl_4[1] = {
    { 18, 19, 0xE, str_cfg_portuguese },
};

const TM_STRING sound_mode_str_tbl_5[1] = {
    { 18, 11, 0xE, str_cfg_normal },
};

const TM_STRING monitor_str_tbl_1[1] = {
    { 18, 11, 0xE, (void*)str_cfg_flip },
};

const s8 cursor_blank_str[4] = {
    32, 0, 0, 0,
};

const s8 cursor_mark_str[4] = {
    62, 0, 0, 0,
};

/* provisional name */
const s8 str_1coin_1credit[32] = "1 COIN  1 CREDIT             ";

/* provisional name */
const s8 str_1coin_2credits[32] = "1 COIN  2 CREDITS            ";

/* provisional name */
const s8 str_1coin_3credits[32] = "1 COIN  3 CREDITS            ";

/* provisional name */
const s8 str_1coin_4credits[32] = "1 COIN  4 CREDITS            ";

/* provisional name */
const s8 str_1coin_5credits[32] = "1 COIN  5 CREDITS            ";

/* provisional name */
const s8 str_1coin_6credits[32] = "1 COIN  6 CREDITS            ";

/* provisional name */
const s8 str_1coin_7credits[32] = "1 COIN  7 CREDITS            ";

/* provisional name */
const s8 str_1coin_8credits[32] = "1 COIN  8 CREDITS            ";

/* provisional name */
const s8 str_1coin_9credits[32] = "1 COIN  9 CREDITS            ";

/* provisional name */
const s8 str_2coins_1credit[32] = "2 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_3coins_1credit[32] = "3 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_4coins_1credit[32] = "4 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_5coins_1credit[32] = "5 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_6coins_1credit[32] = "6 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_7coins_1credit[32] = "7 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_8coins_1credit[32] = "8 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_9coins_1credit[32] = "9 COINS 1 CREDIT             ";

/* provisional name */
const s8 str_2coins_start_1coin_cont[32] = "2 COINS START 1 COIN CONTINUE";

/* provisional name */
const s8 str_coin_free_play[32] = "FREE PLAY                    ";

/* provisional name */
const s8 str_2pl_1chute_single[28] = "2 PLAYERS 1 CHUTER  SINGLE ";

/* provisional name */
const s8 str_2pl_2chutes_single[28] = "2 PLAYERS 2 CHUTERS SINGLE ";

/* provisional name */
const s8 str_2pl_2chutes_multi[28] = "2 PLAYERS 2 CHUTERS MULTI  ";

/* provisional name */
const s8 str_3pl_1chute_single[28] = "3 PLAYERS 1 CHUTER  SINGLE ";

/* provisional name */
const s8 str_3pl_2chutes_single[28] = "3 PLAYERS 2 CHUTERS SINGLE ";

/* provisional name */
const s8 str_3pl_3chutes_single[28] = "3 PLAYERS 3 CHUTERS SINGLE ";

/* provisional name */
const s8 str_3pl_3chutes_multi[28] = "3 PLAYERS 3 CHUTERS MULTI  ";

/* provisional name */
const s8 str_4pl_1chute_single[28] = "4 PLAYERS 1 CHUTER  SINGLE ";

/* provisional name */
const s8 str_4pl_2chutes_single[28] = "4 PLAYERS 2 CHUTERS SINGLE ";

/* provisional name */
const s8 str_4pl_2chutes_multi[28] = "4 PLAYERS 2 CHUTERS MULTI  ";

/* provisional name */
const s8 str_4pl_4chutes_single[28] = "4 PLAYERS 4 CHUTERS SINGLE ";

/* provisional name */
const s8 str_4pl_4chutes_multi[28] = "4 PLAYERS 4 CHUTERS MULTI  ";

/* provisional name */
const s8 str_cfg_on[8] = "ON    ";

/* provisional name */
const s8 str_cfg_off[8] = "OFF   ";

/* provisional name */
const s8 str_cfg_external[12] = "EXTERNAL";

/* provisional name */
const s8 str_cfg_jamma[12] = "JAMMA   ";

/* provisional name */
const s8 str_cfg_english[16] = "ENGLISH     ";

/* provisional name */
const s8 str_cfg_spanish[16] = "SPANISH     ";

/* provisional name */
const s8 str_cfg_portuguese[16] = "PORTUGUESE  ";

/* provisional name */
const s8 str_cfg_normal[8] = "NORMAL";

/* provisional name */
const char str_cfg_flip[8] = "FLIP  ";

/* Stored after str_cfg_flip. Nothing in the program refers to it by name or address. */
const s8 str_cfg_flip_tail[64] = {
    0, 0, 1, -1, 2, 0, 3, -1,
    63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, -65,
    63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, 127,
    63, 15, 0, 13, 0, 0, 0, 0,
    0, 0, 1, -1, 2, 0, 3, 63,
    63, 15, 0, 13, 0, 0, 0, 0,
};
