/*
 * NEXT_CPU_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 gcfg_bonus_scr_jp_0[];
extern const u8 gcfg_bonus_scr_jp_1[];
extern const u32 gcfg_cursor_clr_scr_jp_0[];
extern const u32 gcfg_cursor_scr_jp_0[];
extern const u8 gcfg_event_scr_jp_0[];
extern const u8 gcfg_event_scr_jp_1[];
extern const u32 gcfg_exit_guide_scr_jp_0[];
extern const u32 gcfg_gauge_clr_scr_jp_0[];
extern const u32 gcfg_gauge_scr_jp_0[];
extern const u32 gcfg_gauge_scr_jp_1[];
extern const u32 gcfg_gauge_scr_jp_2[];
extern const u32 gcfg_gauge_scr_jp_3[];
extern const u32 gcfg_gauge_scr_jp_4[];
extern const u32 gcfg_gauge_scr_jp_5[];
extern const u32 gcfg_gauge_scr_jp_6[];
extern const u32 gcfg_gauge_scr_jp_7[];
extern const u32 gcfg_guide_scr_jp_0[];
extern const u8 gcfg_round_scr_jp_0[];
extern const u8 gcfg_round_scr_jp_1[];
extern const u8 gcfg_round_scr_jp_2[];
extern const u8 gcfg_round_scr_jp_3[];
extern const u8 gcfg_screen_scr_jp_0[];
extern const u8 gcfg_screen_scr_jp_1[];
extern const u32 gcfg_title_scr_jp_0[];

extern void game_config_1p_round_item_jp();
extern void game_config_2p_round_item_jp();
extern void game_config_bonus_item_jp();
extern void game_config_damage_item_jp();
extern void game_config_event_item_jp();
extern void game_config_exit_item_jp();
extern void game_config_init_jp();
extern void game_config_level_item_jp();
extern void game_config_move_jp();
extern void game_config_timer_item_jp();

const u8 Arts_Rnd_Data[8] = {
    0, 0, 0, 1, 1, 1, 2, 2,
};

const u32 gcfg_guide_scr_jp_0[12] = {
    0x130005, 0x180002, 0x13541350, 0x12741278, 0x127C12A8, 0x132412C0, 0x12CC1218, 0x128412A8,
    0x132412C0, 0x12CC121C, 0x12541378, 0x137C0000,
};

const u32 gcfg_exit_guide_scr_jp_0[13] = {
    0x150005, 0x180002, 0x12001218, 0x13C412A8, 0x132412C0, 0x12CC1218, 0x1254133C, 0x13401300,
    0x12D41308, 0x13C8125C, 0x13441264, 0x12001200, 0x12000000,
};

const u8 gcfg_screen_scr_jp_1[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 19, 52, 18, 136, 18, 208, 18, 0,
    0, 0,
};

const u8 gcfg_screen_scr_jp_0[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 216, 19, 200, 18, 248, 19, 20,
    0, 0,
};

const u8 gcfg_round_scr_jp_0[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 24, 19, 180, 19, 136, 19, 140,
    0, 0,
};

const u8 gcfg_round_scr_jp_1[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 32, 19, 180, 19, 136, 19, 140,
    0, 0,
};

const u8 gcfg_round_scr_jp_2[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 40, 19, 180, 19, 136, 19, 140,
    0, 0,
};

const u8 gcfg_round_scr_jp_3[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 48, 19, 180, 19, 136, 19, 140,
    0, 0,
};

const u8 gcfg_event_scr_jp_0[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 216, 19, 200, 18, 248, 19, 20,
    0, 0,
};

const u8 gcfg_event_scr_jp_1[18] = {
    0, 4, 0, 0, 0, 0, 0, 2, 18, 24, 18, 248, 18, 192, 18, 188,
    0, 0,
};

const u8 gcfg_bonus_scr_jp_0[14] = {
    0, 2, 0, 0, 0, 0, 0, 2, 18, 88, 18, 72, 0, 0,
};

const u8 gcfg_bonus_scr_jp_1[14] = {
    0, 2, 0, 0, 0, 0, 0, 2, 18, 60, 18, 104, 0, 0,
};

const u32 gcfg_cursor_scr_jp_0[3] = {
    0x10001, 2, 0x12040000,
};

const u32 gcfg_cursor_clr_scr_jp_0[3] = {
    0x10001, 2, 0x12000000,
};

const u32 gcfg_gauge_scr_jp_0[3] = {
    0x10001, 2, 0x12180000,
};

const u32 gcfg_gauge_scr_jp_1[3] = {
    0x10001, 2, 0x121C0000,
};

const u32 gcfg_gauge_scr_jp_2[3] = {
    0x10001, 2, 0x12200000,
};

const u32 gcfg_gauge_scr_jp_3[3] = {
    0x10001, 2, 0x12240000,
};

const u32 gcfg_gauge_scr_jp_4[3] = {
    0x10001, 2, 0x12280000,
};

const u32 gcfg_gauge_scr_jp_5[3] = {
    0x10001, 2, 0x122C0000,
};

const u32 gcfg_gauge_scr_jp_6[3] = {
    0x10001, 2, 0x12300000,
};

const u32 gcfg_gauge_scr_jp_7[3] = {
    0x10001, 2, 0x12340000,
};

const u32 gcfg_gauge_clr_scr_jp_0[3] = {
    0x10001, 2, 0x13CC0000,
};

const u32 gcfg_title_scr_jp_0[79] = {
    0x50013, 2, 0x129C13C8, 0x12FC133C, 0x13400002, 0x40002, 0x21398, 0x13A0000A,
    0x190002, 0x2139C, 0x13CC13CC, 0x13CC13CC, 0x13CC13CC, 0x13CC13CC, 0x13980003, 0x40004,
    0x21390, 0x13941330, 0x60019, 0x40002, 0x13A413CC, 0x13CC13CC, 0x13CC13A8, 0x40004,
    0x60002, 0x12B81288, 0x12F813C8, 0x60019, 0x60002, 0x13AC13CC, 0x13CC13CC, 0x13CC13B0,
    0x70004, 0x80002, 0x1328126C, 0x13C41270, 0x1388138C, 0x12080007, 0x4000A, 0x2121C,
    0x13C41328, 0x132C1388, 0x138C1208, 0x40004, 0xC0002, 0x128812F0, 0x131C12CC, 0x70004,
    0xE0002, 0x12F413C8, 0x133412B0, 0x129C13C8, 0x12FC0009, 0x40010, 0x2133C, 0x13401300,
    0x12D41308, 0x13C8125C, 0x13441264, 0xA000E, 0x160002, 0x121813C4, 0x131812DC, 0x13C81348,
    0x134C1254, 0x1358135C, 0, (u32)game_config_init_jp, (u32)game_config_move_jp, (u32)game_config_init_jp, (u32)game_config_move_jp, (u32)game_config_level_item_jp,
    (u32)game_config_damage_item_jp, (u32)game_config_timer_item_jp, (u32)game_config_1p_round_item_jp, (u32)game_config_2p_round_item_jp, (u32)game_config_event_item_jp, (u32)game_config_bonus_item_jp, (u32)game_config_exit_item_jp,
};

