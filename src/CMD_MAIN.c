/*
 * CMD_MAIN.C  Test-mode game configuration, debug menu and command input
 *
 * Game configuration: game_config_menu runs the test-mode GAME CONFIGURATION page (Japanese page
 * when Country is 1, English otherwise): screen mode, difficulty, damage, timer speed, 1P/2P round
 * counts, event and bonus settings, with lever repeat and star gauges.
 * Debug menu: the debug_* screens - OBJECT LOOK/EDIT, HIT and CATCH JUDGMENT box editors, the
 * HIT -A- JUDGEMENT grid, PARTS, BG select, player snapshots, a move recorder and on-screen dumps of
 * player state and cg data.
 * Command input: waza_check runs for each player every frame; cmd_move steps the 56 waza (special
 * move) slots of the player's pl_CMD table through the check_* input-state routines (lever
 * sequences, charges, buttons, parries) and command_ok / command_ok_move flag completed commands.
 * cmd_init and the waza_flag clear routines reset the command work.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "Com_Pl.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "CALDIR.h"
#include "end_sub.h"
#include "EFFECT.h"
#include "EFF00.h"
#include "EFF02.h"
#include "EFFK5.h"
#include "textsound.h"
#include "CHARMOVE.h"
#include "PLS01.h"
#include "sys_test.h"
#include "fifo.h"
#include "sys_config.h"
#include "bg000.h"
#include "HITCHECK.h"
#include "CHARSET.h"
#include "PLCNTDAT.h"
#include "CMD_MAIN.h"
#include "cps3.h"



/* provisional name */
void game_config_init_jp(void) {
    Config_No_2++;
    Config_Exit_jp = 0;
    tilemap_fill_all(0, 32);
    palette_write(0, sys_palette, 0x100);
    init_render_lists();
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)jp_menu_font_cg, 0x200);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0xCD00), (char*)config_jp_chr_0, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0xCB00), (char*)config_jp_chr_1, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0xCA00), (char*)jp_menu_cg_2, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8200), (char*)jp_menu_cg_3, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x9B00), (char*)jp_menu_cg_4, 4);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x9C00), (char*)jp_menu_cg_5, 4);
    tilemap_fill_all(0, 0x1200);
    tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)gcfg_title_scr_jp);
    Config_Attr_jp = 2;
    Config_Item_jp = 6;
    Config_New_jp = game_config_work.bonus & 1;
    Config_Old_jp = (*&Game_setting).bonus & 1;
    if (Config_New_jp != Config_Old_jp) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_value_jp(Config_Attr_jp, &gcfg_bonus_scr_jp[Config_New_jp]);
    Config_Item_jp = 5;
    Config_New_jp = game_config_work.set5;
    if (Config_New_jp != (*&Game_setting).set5) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_value_jp(Config_Attr_jp, &gcfg_event_scr_jp[Config_New_jp]);
    Config_Item_jp = 4;
    Config_New_jp = game_config_work.set4 / 16;
    Config_New_jp &= 3;
    Config_Org_jp = (*&Game_setting).set4 / 16;
    Config_Org_jp &= 3;
    if (Config_New_jp != Config_Org_jp) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    Config_Item_jp = 3;
    Config_New_jp = game_config_work.set4 & 3;
    Config_Org_jp = (*&Game_setting).set4 & 3;
    if (Config_New_jp != Config_Org_jp) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    Config_Item_jp = 2;
    Config_New_jp = game_config_work.set3;
    if (Config_New_jp != (*&Game_setting).set3) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    Config_Item_jp = 1;
    Config_New_jp = game_config_work.set2;
    if (Config_New_jp != (*&Game_setting).set2) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    Config_Item_jp = 0;
    Config_New_jp = game_config_work.level;
    if (Config_New_jp != (*&Game_setting).level) {
        Config_Attr_jp = 8;
    } else {
        Config_Attr_jp = 2;
    }
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    game_config_print_cursor_jp(gcfg_cursor_scr_jp);
}



/* provisional name */
void game_config_move_jp(void) {
    void (*Page_Tbl[8])() = { game_config_level_item_jp, game_config_damage_item_jp, game_config_timer_item_jp, game_config_1p_round_item_jp, game_config_2p_round_item_jp, game_config_event_item_jp, game_config_bonus_item_jp, game_config_exit_item_jp };
    game_config_cursor_move_jp();
    Page_Tbl[Config_Item_jp]();
    game_config_print_cursor_jp(gcfg_cursor_scr_jp);
    if (Config_Item_jp == 7) {
        tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)gcfg_exit_guide_scr_jp);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)gcfg_guide_scr_jp);
    }
}



/* provisional name */
void game_config_force_wide(void) {
    u16 sw1 = p1sw_0 & 0x3F0;
    u16 sw2 = p2sw_0 & 0x3F0;
    if (sw1 == 0x3F0 && sw2 == 0x3F0) {
        set_screen_mode(7);
        game_config_work.mode = 1;
        screen_flip_offsets_set();
    }
}



/* provisional name */
void game_config_screen_item_jp(void) {
    Config_Move_jp = 0;
    if (((s8)game_config_lever_repeat_jp(4, 2))) {
        Config_Move_jp = -1;
    } else if (((s8)game_config_lever_repeat_jp(8, 3))) {
        Config_Move_jp = 1;
    } else {
        if (p1sw_0 & ~p1sw_1 & 0x10) {
            Config_Move_jp = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.mode += Config_Move_jp;
        game_config_work.mode &= 1;
        set_screen_mode(game_config_work.mode ? 7 : 3);
        screen_flip_offsets_set();
        tilemap_print_script_seq(24, 2, 0xFFFF, (TMSCRIPT*)&gcfg_screen_scr_jp[game_config_work.mode]);
        if (game_config_work.mode != (*&Game_setting).mode) {
            tilemap_rect_fill(24, 2, 8, 2, 8, 0xFFFF);
        } else {
            tilemap_rect_fill(24, 2, 8, 2, 2, 0xFFFF);
        }
    } else {
        game_config_work.mode &= 1;
    }
}



/* provisional name */
void game_config_level_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    game_config_work.level &= 7;
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.level;
        game_config_work.level += Config_Move_jp;
        game_config_work.level &= 7;
        Config_New_jp = game_config_work.level;
        Config_Attr_jp = Config_New_jp != Game_setting.level ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_damage_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else {
        if (game_config_lever_repeat_jp(8, 3)) {
            Config_Move_jp = 1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.set2;
        game_config_work.set2 += Config_Move_jp;
        game_config_work.set2 &= 3;
        Config_New_jp = game_config_work.set2;
        Config_Attr_jp = Config_New_jp != Game_setting.set2 ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_timer_item_jp(void) {
    Config_Move_jp = 0;
    if (game_config_lever_repeat_jp(4, 2)) {
        Config_Move_jp = -1;
    } else if (game_config_lever_repeat_jp(8, 3)) {
        Config_Move_jp = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = game_config_work.set3;
        game_config_work.set3 += Config_Move_jp;
        game_config_work.set3 &= 3;
        Config_New_jp = game_config_work.set3;
        Config_Attr_jp = Config_New_jp != Game_setting.set3 ? 8 : 2;
        game_config_print_gauge_jp(Config_New_jp, Config_Old_jp, Config_Attr_jp);
    }
}



/* provisional name */
void game_config_1p_round_item_jp(void) {
    Config_Move_jp = 0;
    if (((s8)game_config_lever_repeat_jp(4, 2))) {
        Config_Move_jp = -1;
    } else if (((s8)game_config_lever_repeat_jp(8, 3))) {
        Config_Move_jp = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_jp = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = (*&Game_setting).set4 & 3;
        Config_New_jp = game_config_work.set4 & 3;
        Config_New_jp += Config_Move_jp;
        Config_New_jp &= 3;
        Config_Attr_jp = (Config_New_jp == Config_Old_jp) ? 2 : 8;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
        Config_Keep_Bits_jp = game_config_work.set4 & 0x30;
        game_config_work.set4 = Config_Keep_Bits_jp | Config_New_jp;
    }
}



/* provisional name */
void game_config_2p_round_item_jp(void) {
    Config_Move_jp = 0;
    if (((s8)game_config_lever_repeat_jp(4, 2))) {
        Config_Move_jp = -1;
    } else if (((s8)game_config_lever_repeat_jp(8, 3))) {
        Config_Move_jp = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_jp = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = (*&Game_setting).set4 & 0x30;
        Config_Old_jp /= 16;
        Config_Old_jp &= 3;
        Config_New_jp = game_config_work.set4 & 0x30;
        Config_New_jp /= 16;
        Config_New_jp &= 3;
        Config_New_jp += Config_Move_jp;
        Config_New_jp &= 3;
        Config_Attr_jp = (Config_New_jp == Config_Old_jp) ? 2 : 8;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
        Config_Keep_Bits_jp = game_config_work.set4 & 3;
        Config_New_jp *= 16;
        Config_New_jp &= 0x30;
        game_config_work.set4 = Config_Keep_Bits_jp | Config_New_jp;
    }
}



/* provisional name */
void game_config_event_item_jp(void) {
    Config_Move_jp = 0;
    if (((s8)game_config_lever_repeat_jp(4, 2))) {
        Config_Move_jp = -1;
    } else if (((s8)game_config_lever_repeat_jp(8, 3))) {
        Config_Move_jp = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_jp = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.set5 += Config_Move_jp;
        game_config_work.set5 &= 1;
        Config_New_jp = game_config_work.set5;
        Config_Attr_jp = (Config_New_jp != (*&Game_setting).set5) ? 8 : 2;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_event_scr_jp[Config_New_jp]);
    }
}



/* provisional name */
void game_config_bonus_item_jp(void) {
    Config_Move_jp = 0;
    if (((s8)game_config_lever_repeat_jp(4, 2))) {
        Config_Move_jp = -1;
    } else if (((s8)game_config_lever_repeat_jp(8, 3))) {
        Config_Move_jp = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_jp = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.bonus ^= 1;
        game_config_work.bonus &= 1;
        Config_New_jp = game_config_work.bonus & 1;
        Config_Old_jp = (*&Game_setting).bonus & 1;
        Config_Attr_jp = (Config_New_jp == Config_Old_jp) ? 2 : 8;
        game_config_print_value_jp(Config_Attr_jp, &gcfg_bonus_scr_jp[Config_New_jp]);
    }
}



/* provisional name */
void game_config_exit_item_jp(void) {
    if ((~p1sw_1 & p1sw_0) & 0x10) {
        Config_Exit_jp = 1;
    }
}



/* provisional name */
void game_config_settings_commit(void) {
    Game_setting.mode = game_config_work.mode;
    Game_setting.level = game_config_work.level;
    Game_setting.set2 = game_config_work.set2;
    Game_setting.set3 = game_config_work.set3;
    Game_setting.set4 = game_config_work.set4;
    Game_setting.set5 = game_config_work.set5;
    Game_setting.set6 = game_config_work.set6;
    Game_setting.bonus = game_config_work.bonus;
}



/* provisional name */
s8 game_config_lever_repeat_jp(u16 sw, s16 ix) {
    s32 cur = p1sw_0;
    s32 mm = sw;

    if (~p1sw_1 & cur & mm) {
        return 1;
    }
    if (cur & mm) {
        Config_Rep_Timer_jp[ix]++;
        if (Config_Rep_Timer_jp[ix] > 10) {
            s8* t = &Config_Rep_Count_jp[ix];
            ++*t;
            if (*t > 8) {
                Config_Rep_Count_jp[ix] = 0;
                return 1;
            }
        }
    } else {
        Config_Rep_Count_jp[ix] = Config_Rep_Timer_jp[ix] = 0;
    }
    return 0;
}



/* provisional name */
void game_config_cursor_move_jp(void) {
    game_config_print_cursor_jp(gcfg_cursor_clr_scr_jp);
    if (((s8)game_config_lever_repeat_jp(1, 0))) {
        Config_Item_jp--;
        if (Config_Item_jp < 0) {
            Config_Item_jp = 7;
        }
    }
    if (((s8)game_config_lever_repeat_jp(2, 1))) {
        Config_Item_jp++;
        if (Config_Item_jp > 7) {
            Config_Item_jp = 0;
        }
    }
}



/* provisional name */
void game_config_apply(void) {
    if (game_config_work.set5) {
        event_off_flag = 0;
    } else {
        event_off_flag = 1;
    }
    if (game_config_work.mode) {
        set_screen_mode(7);
    } else {
        set_screen_mode(3);
    }
    screen_flip_offsets_set();
}

/* provisional name */
void game_config_print_value_jp(s16 attr, const TMSCRIPT* script) {
    s32 y;

    y = Config_Item_jp;
    y += y;
    y += 2;
    ((void(*)(s32 x, s32 y, s32 attr, const TMSCRIPT* scr))tilemap_print_script_seq)(24, y, attr, script);
}



/* provisional name */
void game_config_print_gauge_jp(u32 newv, u32 oldv, s16 attr) {
    s32 y;
    u16 ix;

    y = Config_Item_jp;
    ix = newv;
    y += y;
    y += 2;
    newv += newv;
    newv += 26;
    if ((u16)oldv != 0xFFFF) {
        oldv += oldv;
        oldv += 26;
        tilemap_print_script_seq(oldv, y, 2, gcfg_gauge_clr_scr_jp);
    }
    tilemap_print_script_seq(newv, y, attr, &gcfg_gauge_scr_jp[ix]);
}

/* provisional name */
void game_config_print_cursor_jp(const TMSCRIPT* script) {
    s32 y;

    y = Config_Item_jp;
    y += y;
    y += 2;
    ((void(*)(s32 x, s32 y, s32 attr, const TMSCRIPT* scr))tilemap_print_script_seq)(1, y, 0xFFFF, script);
}



/* provisional name */
s32 game_config_menu_en(void) {
    void (*tbl[2])(void) = { game_config_init_en, game_config_move_en };

    tbl[Config_No_2]();
    if (Config_Exit_en) {
        return 1;
    }
    return 0;
}



/* provisional name */
void game_config_init_en(void) {
    Config_No_2++;
    Config_Exit_en = 0;
    init_render_lists();
    palette_bank_set(0);
    palette_write(0, sys_palette, 0x80);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)sys_font_cg, 0x8C);
    tilemap_fill_all(0, 32);
    tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)config_title_str_tbl);
    Config_Item_en = 6;
    Config_New_en = game_config_work.bonus & 1;
    Config_Old_en = (*&Game_setting).bonus & 1;
    Config_Attr_en = (Config_New_en != Config_Old_en) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_bonus_str_en[Config_New_en]);
    Config_Item_en = 5;
    Config_New_en = game_config_work.set5;
    Config_Attr_en = (Config_New_en != (*&Game_setting).set5) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_event_str_en[Config_New_en]);
    Config_Item_en = 4;
    Config_New_en = game_config_work.set4 / 16;
    Config_New_en &= 3;
    Config_Org_en = (*&Game_setting).set4 / 16;
    Config_Org_en &= 3;
    Config_Attr_en = (Config_New_en != Config_Org_en) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
    Config_Item_en = 3;
    Config_New_en = game_config_work.set4 & 3;
    Config_Org_en = (*&Game_setting).set4 & 3;
    Config_Attr_en = (Config_New_en != Config_Org_en) ? 8 : 2;
    game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
    Config_Item_en = 2;
    Config_New_en = game_config_work.set3;
    Config_Attr_en = (Config_New_en != (*&Game_setting).set3) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    Config_Item_en = 1;
    Config_New_en = game_config_work.set2;
    Config_Attr_en = (Config_New_en != (*&Game_setting).set2) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    Config_Item_en = 0;
    Config_New_en = game_config_work.level;
    Config_Attr_en = (Config_New_en != (*&Game_setting).level) ? 8 : 2;
    game_config_print_gauge_en(Config_New_en, 0xFFFF, Config_Attr_en);
    game_config_draw_cursor_en(62);
}



/* provisional name */
void game_config_move_en(void) {
    void (*Page_Tbl[8])() = { game_config_level_item_en, game_config_damage_item_en, game_config_timer_item_en, game_config_1p_round_item_en, game_config_2p_round_item_en, game_config_event_item_en, game_config_bonus_item_en, game_config_exit_item_en };
    game_config_cursor_move_en();
    Page_Tbl[Config_Item_en]();
    game_config_draw_cursor_en(62);
    if (Config_Item_en == 7) {
        tilemap_print_string(0, 0, 0xFFFF, config_help_return_str_tbl);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, config_help_modify_str_tbl);
    }
}



/* provisional name */
void game_config_screen_item_en(void) {
    Config_Move_en = 0;
    if (((s8)game_config_lever_repeat_en(4, 2))) {
        Config_Move_en = -1;
    } else if (((s8)game_config_lever_repeat_en(8, 3))) {
        Config_Move_en = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_en = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.mode = game_config_work.mode + Config_Move_en;
        game_config_work.mode = game_config_work.mode & 1;
        Config_New_en = game_config_work.mode;
        set_screen_mode(game_config_work.mode ? 7 : 3);
        screen_flip_offsets_set();
        Config_Attr_en = (Config_New_en == (*&Game_setting).mode) ? 2 : 8;
        game_config_print_value_en(Config_Attr_en, &gcfg_screen_str_en[Config_New_en]);
    }
}



/* provisional name */
void game_config_level_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.level;
        game_config_work.level += Config_Move_en;
        if (game_config_work.level < 0) {
            game_config_work.level = 7;
        }
        if (game_config_work.level > 7) {
            game_config_work.level = 0;
        }
        Config_New_en = game_config_work.level;
        Config_Attr_en = Config_New_en != Game_setting.level ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}



/* provisional name */
void game_config_damage_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.set2;
        game_config_work.set2 += Config_Move_en;
        game_config_work.set2 &= 3;
        Config_New_en = game_config_work.set2;
        Config_Attr_en = Config_New_en != Game_setting.set2 ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}



/* provisional name */
void game_config_timer_item_en(void) {
    Config_Move_en = 0;
    if (game_config_lever_repeat_en(4, 2)) {
        Config_Move_en = -1;
    } else if (game_config_lever_repeat_en(8, 3)) {
        Config_Move_en = 1;
    } else {
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_en = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = game_config_work.set3;
        game_config_work.set3 += Config_Move_en;
        game_config_work.set3 &= 3;
        Config_New_en = game_config_work.set3;
        Config_Attr_en = Config_New_en != Game_setting.set3 ? 8 : 2;
        game_config_print_gauge_en(Config_New_en, Config_Old_en, Config_Attr_en);
    }
}



/* provisional name */
void game_config_1p_round_item_en(void) {
    Config_Move_en = 0;
    if (((s8)game_config_lever_repeat_en(4, 2))) {
        Config_Move_en = -1;
    } else if (((s8)game_config_lever_repeat_en(8, 3))) {
        Config_Move_en = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_en = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = (*&Game_setting).set4 & 3;
        Config_New_en = game_config_work.set4 & 3;
        Config_New_en += Config_Move_en;
        Config_New_en &= 3;
        Config_Attr_en = (Config_New_en == Config_Old_en) ? 2 : 8;
        game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
        Config_Keep_Bits_en = game_config_work.set4 & 0x30;
        game_config_work.set4 = Config_Keep_Bits_en | Config_New_en;
    }
}



/* provisional name */
void game_config_2p_round_item_en(void) {
    Config_Move_en = 0;
    if (((s8)game_config_lever_repeat_en(4, 2))) {
        Config_Move_en = -1;
    } else if (((s8)game_config_lever_repeat_en(8, 3))) {
        Config_Move_en = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_en = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        Config_Old_en = (*&Game_setting).set4 & 0x30;
        Config_Old_en /= 16;
        Config_Old_en &= 3;
        Config_New_en = game_config_work.set4 & 0x30;
        Config_New_en /= 16;
        Config_New_en &= 3;
        Config_New_en += Config_Move_en;
        Config_New_en &= 3;
        Config_Attr_en = (Config_New_en == Config_Old_en) ? 2 : 8;
        game_config_print_value_en(Config_Attr_en, &gcfg_round_str_en[Config_New_en]);
        Config_Keep_Bits_en = game_config_work.set4 & 3;
        Config_New_en *= 16;
        Config_New_en &= 0x30;
        game_config_work.set4 = Config_Keep_Bits_en | Config_New_en;
    }
}



/* provisional name */
void game_config_event_item_en(void) {
    Config_Move_en = 0;
    if (((s8)game_config_lever_repeat_en(4, 2))) {
        Config_Move_en = -1;
    } else if (((s8)game_config_lever_repeat_en(8, 3))) {
        Config_Move_en = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_en = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.set5 += Config_Move_en;
        game_config_work.set5 &= 1;
        Config_New_en = game_config_work.set5;
        Config_Attr_en = (Config_New_en == (*&Game_setting).set5) ? 2 : 8;
        game_config_print_value_en(Config_Attr_en, &gcfg_event_str_en[Config_New_en]);
    }
}



/* provisional name */
void game_config_bonus_item_en(void) {
    Config_Move_en = 0;
    if (((s8)game_config_lever_repeat_en(4, 2))) {
        Config_Move_en = -1;
    } else if (((s8)game_config_lever_repeat_en(8, 3))) {
        Config_Move_en = 1;
    } else {
        if (~p1sw_1 & p1sw_0 & 0x10) {
            Config_Move_en = -1;
        }
        if (~p1sw_1 & p1sw_0 & 0x20) {
            Config_Move_en = 1;
        }
    }
    if (Config_Move_en) {
        game_config_work.bonus ^= 1;
        game_config_work.bonus &= 1;
        Config_New_en = game_config_work.bonus & 1;
        Config_Old_en = (*&Game_setting).bonus & 1;
        Config_Attr_en = (Config_New_en != Config_Old_en) ? 8 : 2;
        game_config_print_value_en(Config_Attr_en, &gcfg_bonus_str_en[Config_New_en]);
    }
}



/* provisional name */
void game_config_exit_item_en(void) {
    if ((~p1sw_1 & p1sw_0) & 0x10) {
        Config_Exit_en = 1;
    }
}



/* provisional name */
s8 game_config_lever_repeat_en(u16 sw, s16 ix) {
    s32 cur = p1sw_0;
    s32 mm = sw;

    if (~p1sw_1 & cur & mm) {
        return 1;
    }
    if (cur & mm) {
        Config_Rep_Timer_en[ix]++;
        if (Config_Rep_Timer_en[ix] > 10) {
            s8* t = &Config_Rep_Count_en[ix];
            ++*t;
            if (*t > 8) {
                Config_Rep_Count_en[ix] = 0;
                return 1;
            }
        }
    } else {
        Config_Rep_Timer_en[ix] = 0;
        Config_Rep_Count_en[ix] = 0;
    }
    return 0;
}



/* provisional name */
void game_config_cursor_move_en(void) {
    game_config_draw_cursor_en(32);
    if (((s8)game_config_lever_repeat_en(1, 0))) {
        Config_Item_en--;
        if (Config_Item_en < 0) {
            Config_Item_en = 7;
        }
    } else if (((s8)game_config_lever_repeat_en(2, 1))) {
        Config_Item_en++;
        if (Config_Item_en > 7) {
            Config_Item_en = 0;
        }
    }
}



/* provisional name */
void game_config_draw_cursor_en(s16 code) {
    s32 y;

    y = Config_Item_en;
    y += y;
    y += 4;
    tilemap_put_block(3, y, 2, code);
}

/* provisional name */
void game_config_print_gauge_en(u32 x, u32 old_x, s16 attr) {
    s32 y;
    u16 ix;

    y = Config_Item_en;
    ix = x;
    y += y;
    y += 4;
    x += 0x1F;
    if ((u16)old_x != 0xFFFF) {
        old_x += 0x1F;
        tilemap_put_block(old_x, y, 2, gcfg_gauge_clr_chr_en);
    }
    tilemap_put_block(x, y, attr, gcfg_gauge_chr_en[ix]);
}



/* provisional name */
void game_config_print_value_en(s16 attr, const TM_STRING* str) {
    s32 y;

    y = Config_Item_en;
    y += y;
    y += 4;
    ((void(*)(s32 x, s32 y, s32 attr, const TM_STRING* str))tilemap_print_string)(24, y, attr, str);
}



/* provisional name */
s32 debug_scene_outer_dispatch(void) {
    dbg_p1sw_1 = dbg_p1sw_0;
    dbg_p1sw_0 = p1sw_0;
    dbg_p2sw_1 = dbg_p2sw_0;
    dbg_p2sw_0 = p2sw_0;
    dbg_dipsw_1 = dbg_dipsw_0;
    dbg_dipsw_0 = exsw_1;
    plw[0].wu.old_rno[0] = plw[0].wu.cg_number;
    plw[1].wu.old_rno[0] = plw[1].wu.cg_number;
    switch (Debug_R_No) {
    case 0:
        debug_menu_work_init();
        break;
    case 1:
        debug_menu_gfx_load();
        break;
    case 2:
        debug_menu_player_setup();
        break;
    case 3: {
        void (*Stage_Tbl[2])() = { debug_menu_select_init, debug_menu_select_run };
        (*Stage_Tbl[Debug_Select_No])();
    }
        break;
    case 4:
        if (!debug_menu_exit_check()) {
            debug_main_dispatch();
            debug_effect_move_all();
        }
        break;
    }
    if ((dbg_p2sw_0 & 0xF0) == 0xF0) {
        return 1;
    }
    return 0;
}

/* provisional name */
void debug_effect_move_all(void)
{
    color_trans_dummy();
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
}



/* provisional name */
void debug_menu_work_init(void) {
    PLW* p0;
    PLW* p1;
    s32 i;
    u16 j;
    Debug_R_No++;
    palette_bank_set(0x3FC00);
    palette_write(0, sys_palette, 0x100);
    dbg_stage_sel = dbg_stage_sub = 0;
    debug_edit_slots_reset();
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 16; j++) {
            dbg_slot_w[i][j] = 0;
        }
        continue;
    }
    for (i = 0; i < 2; i++) {
        dbg_slot_w[i][1] = 1;
        dbg_slot_w[i][2] = 0;
        for (j = 0; j < 12; j++) {
            ((s16*)dbg_snap_w[i])[j] = 0;
        }
    }
    p0 = &plw[0];
    work_init_zero((s32*)p0, sizeof(PLW));
    p1 = &plw[1];
    work_init_zero((s32*)p1, sizeof(PLW));
    Game_pause = 0;
    G_No0 = 0;
    G_No1 = 0;
    G_No2 = 0;
    G_No3 = 0;
    p1->zuru_timer = 0;
    p0->zuru_timer = 0;
}

/* provisional name */
void debug_menu_gfx_load(void)
{
    Debug_R_No++;
    tilemap_fill_all(0, 0x20);
    init_char_gfx_tables();
    effect_work_quick_init();
    load_char_gfx(0x9000, 1);
    setup_kage_cells();
    Game_pause = 0;
}



/* provisional name */
void debug_menu_player_setup(void) {
    s16 i;
    s16 j;
    s16 ix;
    WORK_Other* ewk;
    Debug_R_No++;
    tilemap_fill_all(0, 32);
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    debug_pattern_edit_init_counts();
    debug_edit_slots_reset();
    debug_both_players_reset();
    plw[0].wu.hit_adrs = (u32*)&plw[1];
    plw[1].wu.hit_adrs = (u32*)&plw[0];
    plw[0].wu.dmg_adrs = (u32*)&plw[1];
    plw[1].wu.dmg_adrs = (u32*)&plw[0];
    init_color_trans_req();
    load_any_color(0);
    load_player_color(plw[0].player_number, 0, 0);
    load_player_color(plw[1].player_number, 1, 0);
    effect_00_init(&plw[0]);
    effect_00_init(&plw[1]);
    effect_01_init(&plw[0], 0);
    effect_01_init(&plw[0], 1);
    effect_01_init(&plw[0], 2);
    effect_01_init(&plw[0], 3);
    effect_01_init(&plw[1], 0);
    effect_01_init(&plw[1], 1);
    effect_01_init(&plw[1], 2);
    effect_01_init(&plw[1], 3);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if ((ix = pull_effect_work(7)) == -1) {
                return;
            }
            ewk = (WORK_Other*)frw[ix];
            ewk->wu.cgromtype = 1;
            ewk->wu.my_family = 1;
            if (i == 0) {
                ewk->wu.my_col_code = 0x2000;
            } else {
                ewk->wu.my_col_code = 0x2010;
            }
            ewk->wu.my_col_mode = 0x4200;
            ewk->wu.id = i;
            dbg_ghost_ewk[i][j] = ewk;
        }
        continue;
    }
    dbg_judge_eff_ix = search_effect_index(0, 0, 0);
    Debug_Rec_Frame = Debug_Rec_Count = 0;
    Debug_PL_id = 0;
    Debug_Dec_Disp = 0;
    dbg_cmd_panel = 0;
    dbg_hud_mode = 0;
    ixbfw_cut = 0;
    Game_pause = 0;
    if (Game_setting.mode != 0) {
        dbg_hud_x = 8;
    } else {
        dbg_hud_x = 0;
    }
}



/* provisional name */
void debug_menu_select_dispatch(void) {
    STAGE_TBL_T tbl;
    tbl = debug_select_jmp_data;
    tbl.f[Debug_Select_No]();
}

/* provisional name */
void debug_menu_select_init(void)
{
    Debug_Select_No++;
    tilemap_fill_all(0, 0x20);
    Debug_Menu_No += 4;
    tilemap_print_string(0, 0, 0xFFFF, dbg_menu_str);
    tilemap_print_string_attr(8, Debug_Menu_No, 6, debug_cursor_msg);
    Game_pause = 0;
}



/* provisional name */
void debug_menu_select_run(void) {
    u16 sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & 0x10) {
        Debug_Menu_No -= 4;
        Debug_R_No++;
        Debug_Tool_No = 0;
        debug_bg_stage_load();
        return;
    }
    if (sw & 1) {
        tilemap_print_string_attr(8, Debug_Menu_No, 6, debug_space_msg);
        Debug_Menu_No--;
        if (Debug_Menu_No < 4) {
            Debug_Menu_No = 17;
        }
    } else if (sw & 2) {
        tilemap_print_string_attr(8, Debug_Menu_No, 6, debug_space_msg);
        Debug_Menu_No++;
        if (Debug_Menu_No > 17) {
            Debug_Menu_No = 4;
        }
    }
    tilemap_print_string_attr(8, Debug_Menu_No, 6, debug_cursor_msg);
}



/* provisional name */
void debug_main_dispatch(void) {
    void (*Debug_Tbl[14])() = { debug_bg_select_dispatch, debug_object_look_dispatch, debug_object_edit_dispatch, debug_object_edit_all_char_dispatch, debug_hit_judgment_dispatch, debug_char_preview_dispatch, debug_parts_dispatch, debug_play07, debug_play08, debug_play09, debug_play10, debug_play11, debug_play12, debug_play13 };
    dbg_old_cgd_type = plw[0].wu.cgd_type;
    Debug_Tbl[Debug_Menu_No]();
}



/* provisional name */
void debug_bg_select_dispatch(void) {
    void (*BG_Tbl[2])() = { debug_bg_select_init, debug_bg_select_navigate_updown };
    BG_Tbl[Debug_Tool_No]();
    tilemap_print_string(0, 0, 0xFFFF, &dbg_bg_name_str[dbg_stage_sel]);
}

/* provisional name */
void debug_bg_select_init(void)
{
    Debug_Tool_No++;
    tilemap_fill_all(0, 0x20);
    tilemap_print_string_attr(0xF, 1, 0xE, bg_select_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_select_exit_str);
    debug_bg_stage_load();
}



/* provisional name */
void debug_bg_select_navigate_updown(void) {
    s16 moved = 0;
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_stage_sel--;
        moved = 1;
        if (dbg_stage_sel < 0) {
            dbg_stage_sel = 23;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_stage_sel++;
        moved = 1;
        if (dbg_stage_sel > 23) {
            dbg_stage_sel = 0;
        }
    }
    bg_w.stage = dbg_bg_select_tbl[dbg_stage_sel][0];
    bg_w.area = dbg_bg_select_tbl[dbg_stage_sel][1];
    if (moved) {
        Scr_all_clear_Wait();
        Debug_Tool_No = 0;
    }
}



/* provisional name */
void debug_object_look_dispatch(void) {
    void (*Look_Tbl[2])() = { debug_object_look_init, debug_object_look_run };
    dbg_pl = plw;
    dbg_slot = dbg_slot_w[0];
    Look_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_kakusyuku_frame_flags();
    debug_hud_mode_dispatch();
}



/* provisional name */
void debug_object_look_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, object_look_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    dbg_kakusyuku_mode = 0;
    dbg_look_mode = 0;
    dbg_zoom_x = 19;
    dbg_zoom_y = 19;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    Debug_Snap_Disp = 0;
    Debug_PL_id = 0;
    debug_both_players_reset();
    plw[1].wu.disp_flag = 0;
    plw[1].wu.be_flag = 0;
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
}



/* provisional name */
void debug_object_look_run(void) {
    Debug_Command = 0;
    debug_object_look_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        dbg_pl->wu.meoshi_hit_flag = 1;
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 2:
        dbg_pl->wu.meoshi_hit_flag = 1;
        if (dbg_slot[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 4:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        break;
    case 5:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    case 6:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move_cmoa(&dbg_pl->wu);
        debug_pattern_timer_update();
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= (&Debug_Flip_Mask[0])[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        break;
    }
    dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos;
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos;
    dbg_pl->wu.position_z = dbg_pl->wu.my_priority;
    sort_push_request(&dbg_pl->wu);
}



/* provisional name */
void debug_object_edit_dispatch(void) {
    void (*Edit_Tbl[2])() = { debug_object_edit_init, debug_object_edit_move };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = (s16*)((u8*)&dbg_slot_w + (s8)(Debug_PL_id * sizeof(EDIT_SLOTS)));
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    Edit_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_record_info();
}



/* provisional name */
void debug_object_edit_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, object_edit_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_edit_num_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_both_players_reset();
    dbg_save_mode = 2;
    dbg_rec_menu = 0;
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Edit_Sub = 0;
    dbg_rec_exist = 0;
    Debug_Snap_Disp = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    for (i = 0; i < 2; i++) {
        dbg_pl = &plw[i];
        dbg_slot = dbg_slot_w[i];
        debug_slot_char_load();
        debug_motion_list_count();
        debug_pattern_count();
        debug_pattern_timer_update();
    }
}



/* provisional name */
void debug_object_edit_move(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_object_edit_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 2:
        if (dbg_slot[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        Debug_Play_Flag = 0;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot[2]++;
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        Debug_Play_Flag = 0;
        break;
    case 6:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
            dbg_snap_req = 1;
            Debug_Play_Flag = 1;
            dbg_rec_exist = 1;
            dbg_snap_ptr->used++;
            if (dbg_snap_ptr->used > dbg_snap_ptr->cg_ctr) {
                dbg_snap_ptr->used = 1;
                Debug_Rec_Frame++;
                if (Debug_Rec_Frame > Debug_Rec_Count) {
                    Debug_Rec_Frame = 1;
                }
            }
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
        }
        break;
    case 7:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
            dbg_snap_req = 1;
            Debug_Play_Flag = 1;
            dbg_rec_exist = 1;
            dbg_snap_ptr->used = 1;
            Debug_Rec_Frame++;
            if (Debug_Rec_Frame > Debug_Rec_Count) {
                Debug_Rec_Frame = 1;
            }
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 8:
        debug_record_frame_save();
        Debug_Play_Flag = 1;
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    debug_object_edit_snapshot_restore();
    debug_draw_record_ghosts();
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
}



/* provisional name */
void debug_record_frame_save(void) {
    s32 i;
    s16 j;
    switch (dbg_save_mode) {
    case 0:
        dbg_snap_req = 1;
        debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
        debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        if (Debug_Rec_Frame < Debug_Rec_Count) {
            Debug_Rec_Frame++;
        }
        break;
    case 1:
        if (!dbg_rec_exist) {
            break;
        }
        if (Debug_Rec_Count > 128) {
            i = 127;
        } else {
            i = Debug_Rec_Count;
        }
        for (; i > Debug_Rec_Frame - 1; i--) {
            j = i + 1;
            debug_copy_player_snapshot(&dbg_snap_w[0][i], &dbg_snap_w[0][j]);
            debug_copy_player_snapshot(&dbg_snap_w[1][i], &dbg_snap_w[1][j]);
            continue;
        }
        debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
        debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        if (Debug_Rec_Count + 1 <= 128) {
            Debug_Rec_Count++;
        }
        break;
    case 2:
        if (!dbg_rec_exist) {
            if (Debug_Rec_Frame + 1 > 128) {
                break;
            }
            Debug_Rec_Frame++;
            if (Debug_Rec_Count + 1 > 128) {
                break;
            }
            Debug_Rec_Count++;
            debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
            debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        } else {
            if (Debug_Rec_Frame + 1 > 128) {
                break;
            }
            if (Debug_Rec_Count > 128) {
                i = 127;
            } else {
                i = Debug_Rec_Count;
            }
            for (; i > Debug_Rec_Frame; i--) {
                j = i + 1;
                debug_copy_player_snapshot(&dbg_snap_w[0][i], &dbg_snap_w[0][j]);
                debug_copy_player_snapshot(&dbg_snap_w[1][i], &dbg_snap_w[1][j]);
                continue;
            }
            Debug_Rec_Frame++;
            debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
            debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            if (Debug_Rec_Count + 1 <= 128) {
                Debug_Rec_Count++;
            }
        }
        break;
    }
}



/* provisional name */
void debug_object_edit_snapshot_restore(void) {
    if (Debug_Play_Flag) {
        debug_restore_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
        debug_restore_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        plw[0].wu.old_cgnum = 0;
        debug_char_disp(&plw[0].wu);
        plw[1].wu.old_cgnum = 0;
        debug_char_disp(&plw[1].wu);
        Debug_Snap_Disp = 1;
    } else if (dbg_snap_req) {
        if (Debug_Rec_Count) {
            debug_restore_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
            debug_restore_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            plw[0].wu.old_cgnum = 0;
            debug_char_disp(&plw[0].wu);
            plw[1].wu.old_cgnum = 0;
            debug_char_disp(&plw[1].wu);
        } else {
            plw[0].wu.old_cgnum = 0;
            debug_char_disp(&plw[0].wu);
            plw[1].wu.old_cgnum = 0;
            debug_char_disp(&plw[1].wu);
        }
        Debug_Snap_Disp = 1;
    } else {
        plw[0].wu.old_cgnum = 0;
        debug_char_disp(&plw[0].wu);
        plw[1].wu.old_cgnum = 0;
        debug_char_disp(&plw[1].wu);
        Debug_Snap_Disp = 0;
    }
}



/* provisional name */
void debug_object_edit_all_char_dispatch(void) {
    void (*All_Tbl[2])() = { debug_object_edit_all_char_init, debug_object_edit_all_char_move };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = dbg_slot_w[Debug_PL_id];
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    All_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_record_info();
}



/* provisional name */
void debug_object_edit_all_char_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(9, 1, 14, object_edit_all_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_edit_num_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_char_slot_init(1);
    debug_both_players_reset();
    dbg_save_mode = 2;
    dbg_rec_menu = 0;
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Edit_Sub = 0;
    Debug_Dec_Disp = 0;
    Debug_Snap_Disp = 0;
    dbg_rec_exist = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    plw[1].wu.old_cgnum = 0;
    plw[1].wu.cg_number = 1;
}



/* provisional name */
void debug_object_edit_all_char_move(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_edit_all_char_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 2:
        if (dbg_slot[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        Debug_Play_Flag = 0;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot[2]++;
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
        dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
        Debug_Play_Flag = 0;
        break;
    case 6:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
            dbg_snap_req = 1;
            Debug_Play_Flag = 1;
            dbg_rec_exist = 1;
            dbg_snap_ptr->used++;
            if (dbg_snap_ptr->used > dbg_snap_ptr->cg_ctr) {
                dbg_snap_ptr->used = 1;
                Debug_Rec_Frame++;
                if (Debug_Rec_Frame > Debug_Rec_Count) {
                    Debug_Rec_Frame = 1;
                }
            }
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
        }
        break;
    case 7:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
            dbg_snap_req = 1;
            Debug_Play_Flag = 1;
            dbg_rec_exist = 1;
            dbg_snap_ptr->used = 1;
            Debug_Rec_Frame++;
            if (Debug_Rec_Frame > Debug_Rec_Count) {
                Debug_Rec_Frame = 1;
            }
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 8:
        debug_record_frame_save();
        Debug_Play_Flag = 1;
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    debug_object_edit_snapshot_restore();
    debug_draw_record_ghosts();
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
}



/* provisional name */
void debug_zoom_out_by_dipsw(void) {
    u16 sw = ~dbg_dipsw_1 & dbg_dipsw_0 & 0xC0;
    switch (sw) {
    case 0x40:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 8, 8);
        break;
    case 0x80:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 16, 16);
        break;
    case 0xC0:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 24, 24);
        break;
    }
    sw = dbg_dipsw_0;
    sw &= 0xC0;
    if (sw == 0) {
        Zoomf_Init();
    }
}



/* provisional name */
void debug_player_color_next(void) {
    u16 sw;
    if (exsw_0 & 0x100) {
        sw = ~dbg_p1sw_1 & dbg_p1sw_0;
        if (sw & 0x1000) {
            dbg_col_ix[dbg_pl->wu.id] += 1;
            if (dbg_col_ix[dbg_pl->wu.id] > 12) {
                dbg_col_ix[dbg_pl->wu.id] = 12;
            }
            dbg_pl->wu.my_col_code = dbg_col_code_tbl[dbg_col_ix[dbg_pl->wu.id]];
            load_any_color(dbg_col_no_tbl[dbg_col_ix[dbg_pl->wu.id]]);
        }
    }
}



/* provisional name */
void debug_ghost_shift_left(WORK* wk) {
    u16 sw = exsw_1 & 3;
    switch (sw) {
    case 0:
        wk->position_x -= 104;
        wk->position_y += 96;
        break;
    case 1:
        wk->position_x -= 136;
        wk->position_y += 112;
        break;
    case 2:
        wk->position_x -= 168;
        wk->position_y += 128;
        break;
    case 3:
        wk->position_x -= 200;
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_ghost_shift_right(WORK* wk) {
    u16 sw = exsw_1 & 3;
    switch (sw) {
    case 0:
        wk->position_x += 104;
        wk->position_y += 96;
        break;
    case 1:
        wk->position_x += 136;
        wk->position_y += 112;
        break;
    case 2:
        wk->position_x += 168;
        wk->position_y += 128;
        break;
    case 3:
        wk->position_x += 200;
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_ghost_shift_up(WORK* wk) {
    u16 sw = exsw_1 & 6;
    switch (sw) {
    case 0:
        wk->position_y += 96;
        break;
    case 2:
        wk->position_y += 112;
        break;
    case 4:
        wk->position_y += 128;
        break;
    case 6:
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_draw_record_ghosts(void) {
    u16 sw = exsw_1 & 1;
    s16 i;
    WORK_Other* ewk;
    if (!sw) {
        return;
    }
    if (!Debug_Rec_Count) {
        return;
    }
    if (dbg_save_mode) {
        if (Debug_Rec_Frame > 0) {
            for (i = 0; i < 2; i++) {
                ewk = dbg_ghost_ewk[i][0];
                debug_snapshot_to_ghost(&ewk->wu, &dbg_snap_w[i][Debug_Rec_Frame]);
                ewk->wu.my_priority += 4;
                ewk->wu.position_z = ewk->wu.my_priority;
                debug_ghost_shift_left(&ewk->wu);
                ewk->wu.old_cgnum = 0;
                debug_char_disp_once(&ewk->wu);
            }
        }
        if (Debug_Rec_Frame < Debug_Rec_Count) {
            for (i = 0; i < 2; i++) {
                ewk = dbg_ghost_ewk[i][2];
                debug_snapshot_to_ghost(&ewk->wu, &dbg_snap_w[i][Debug_Rec_Frame + 1]);
                ewk->wu.my_priority += 4;
                ewk->wu.position_z = ewk->wu.my_priority;
                debug_ghost_shift_right(&ewk->wu);
                ewk->wu.old_cgnum = 0;
                debug_char_disp_once(&ewk->wu);
            }
        }
    } else {
        if (Debug_Rec_Frame > 1) {
            for (i = 0; i < 2; i++) {
                ewk = dbg_ghost_ewk[i][0];
                debug_snapshot_to_ghost(&ewk->wu, &dbg_snap_w[i][Debug_Rec_Frame - 1]);
                ewk->wu.my_priority += 4;
                ewk->wu.position_z = ewk->wu.my_priority;
                debug_ghost_shift_left(&ewk->wu);
                ewk->wu.old_cgnum = 0;
                debug_char_disp_once(&ewk->wu);
            }
        }
        for (i = 0; i < 2; i++) {
            ewk = dbg_ghost_ewk[i][1];
            debug_snapshot_to_ghost(&ewk->wu, &dbg_snap_w[i][Debug_Rec_Frame]);
            ewk->wu.my_priority += 2;
            ewk->wu.position_z = ewk->wu.my_priority;
            debug_ghost_shift_up(&ewk->wu);
            ewk->wu.old_cgnum = 0;
            debug_char_disp_once(&ewk->wu);
        }
        if (Debug_Rec_Frame < Debug_Rec_Count) {
            for (i = 0; i < 2; i++) {
                ewk = dbg_ghost_ewk[i][2];
                debug_snapshot_to_ghost(&ewk->wu, &dbg_snap_w[i][Debug_Rec_Frame + 1]);
                ewk->wu.my_priority += 4;
                ewk->wu.position_z = ewk->wu.my_priority;
                debug_ghost_shift_right(&ewk->wu);
                ewk->wu.old_cgnum = 0;
                debug_char_disp_once(&ewk->wu);
            }
        }
    }
}



/* provisional name */
void debug_hit_judgment_dispatch(void) {
    void (*Hit_Tbl[6])() = { debug_hit_judgment_init, debug_hit_judgment_move, debug_hit_a_judgement_init, debug_hit_a_judgement_run, debug_hit_a_exit_confirm, debug_hit_judgment_redraw };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = dbg_slot_w[Debug_PL_id];
    dbg_judge_ewk = (WORK_Other_JUDGE*)frw[dbg_judge_eff_ix];
    Hit_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_hit_judgment_init(void) {
    s32 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, hit_judgment_msg);
    tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_hit_size_str);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, (TM_STRING*)dbg_hit_part_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_clear_rgb_triplet_table();
    Debug_PL_id = 0;
    Debug_Hit_Sub = 0;
    Debug_Box_Edit = 0;
    dbg_copy_done = 0;
    Debug_Snap_Disp = 0;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    debug_both_players_reset();
    debug_slot_char_load();
    debug_motion_list_count();
    plw[1].wu.rl_flag = 1;
    dbg_look_buf.judge = dbg_look_judge;
    dbg_look_buf.body_adrs = dbg_look_buf.h_bod = dbg_look_body;
    dbg_look_buf.hand_adrs = dbg_look_buf.h_han = dbg_look_hand;
    dbg_look_buf.catch_adrs = dbg_look_buf.h_cat = dbg_look_catch;
    dbg_look_buf.caught_adrs = dbg_look_buf.h_cau = dbg_look_caught;
    dbg_look_buf.attack_adrs = dbg_look_buf.h_att = dbg_look_attack;
    dbg_look_buf.hosei_adrs = dbg_look_buf.h_hos = dbg_look_hosei;
    dbg_copy_buf.judge = dbg_copy_judge;
    dbg_copy_buf.body_adrs = dbg_copy_buf.h_bod = dbg_copy_body;
    dbg_copy_buf.hand_adrs = dbg_copy_buf.h_han = dbg_copy_hand;
    dbg_copy_buf.catch_adrs = dbg_copy_buf.h_cat = dbg_copy_catch;
    dbg_copy_buf.caught_adrs = dbg_copy_buf.h_cau = dbg_copy_caught;
    dbg_copy_buf.attack_adrs = dbg_copy_buf.h_att = dbg_copy_attack;
    dbg_copy_buf.hosei_adrs = dbg_copy_buf.h_hos = dbg_copy_hosei;
    dbg_edit_buf.judge = dbg_edit_judge;
    dbg_edit_buf.body_adrs = dbg_edit_buf.h_bod = dbg_edit_body;
    dbg_edit_buf.hand_adrs = dbg_edit_buf.h_han = dbg_edit_hand;
    dbg_edit_buf.catch_adrs = dbg_edit_buf.h_cat = dbg_edit_catch;
    dbg_edit_buf.caught_adrs = dbg_edit_buf.h_cau = dbg_edit_caught;
    dbg_edit_buf.attack_adrs = dbg_edit_buf.h_att = dbg_edit_attack;
    dbg_edit_buf.hosei_adrs = dbg_edit_buf.h_hos = dbg_edit_hosei;
    dbg_pl = &plw[1];
    dbg_slot = dbg_slot_w[1];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    debug_set_all_boxes(0);
    debug_pattern_list_build();
    debug_edit_pattern_timer_update();
    dbg_judge_ewk->curr_ja = 0;
    dbg_judge_ewk->look_up_flag = 0;
    dbg_edit_box = (s16*)dbg_look_buf.h_bod;
    dbg_col_no = 0;
    dbg_bgcol_ix = 0;
}



/* provisional name */
void debug_hit_judgment_move(void) {
    Debug_Command = 0;
    debug_hit_judgment_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load_keep_col();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        if (Debug_PL_id != 0) {
            debug_pattern_timer_update();
            debug_pattern_count();
        } else {
            debug_pattern_list_build();
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(1);
        }
        break;
    case 2:
        if (dbg_slot[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        if (Debug_PL_id != 0) {
            debug_pattern_count();
            debug_pattern_timer_update();
        } else {
            debug_pattern_list_build();
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(1);
        }
        break;
    case 4:
        if (Debug_PL_id != 0) {
            char_move(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
        } else {
            debug_pattern_preview_step(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(dbg_slot[2]);
        }
        break;
    case 5:
        if (Debug_PL_id != 0) {
            char_move_z(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
        } else {
            dbg_pl->wu.cg_ctr = 1;
            debug_pattern_preview_step(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(dbg_slot[2]);
        }
        break;
    }
    debug_char_disp(&plw[0].wu);
    debug_char_disp(&plw[1].wu);
    debug_bg_color_preset_next();
    debug_rgb_editor_print(0);
    debug_draw_object_info();
    debug_draw_hit_edit_info();
    if ((~dbg_p1sw_1 & dbg_p1sw_0 & 0x200) && dbg_slot[0] <= 0xD8) {
        Debug_Tool_No = 2;
    }
}



/* provisional name */
void debug_hit_a_judgement_init(void) {
    s16 i;
    Debug_Tool_No = 3;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 2, hit_a_judgement_msg);
    tilemap_print_string_attr(2, 1, 10, hit_tbl_label_msg);
    tilemap_print_string_attr(2, 3, 10, pattern_label_msg);
    dbg_hita_num = 0;
    for (i = 0; i < 7; i++) {
        if (debug_hit_a_judgement_alloc_slot(&dbg_hita_ewk[i]) == -1) {
            goto fail;
        }
        dbg_hita_num++;
    }
    debug_hit_a_judgement_build_table();
    debug_clear_rgb_triplet_table();
    return;
fail:
    Debug_Tool_No = 4;
}



/* provisional name */
void debug_hit_a_judgement_build_table(void) {
    WORK* wk = &dbg_hita_ewk[0]->wu;
    WORK_Other* slot;
    u32* dst;
    u32* src;
    HITA_PAT* pat;
    HITA_BOX* body;
    HITA_BOX* hand;
    HITA_BOX* att;
    HITA_KEY* keys;
    u32* ixkey;
    HITA_IX* ixtbl;
    HITA_KEY t;
    s16 i;
    s16 j;
    s16 n;
    plw[0].wu.before = wk->before;
    plw[0].wu.myself = wk->myself;
    plw[0].wu.behind = wk->behind;
    plw[0].wu.listix = wk->listix;
    plw[0].wu.dead_f = wk->dead_f;
    plw[0].wu.timing = wk->timing;
    dst = (u32*)dbg_hita_ewk[0];
    src = (u32*)&plw[0];
    for (i = 0; i < 512; i++) {
        *dst++ = *src++;
    }
    plw[0].wu.xyz[0].disp.pos += 0x180;
    plw[0].wu.position_x += 0x180;
    plw[1].wu.xyz[0].disp.pos += 0x180;
    plw[1].wu.position_x += 0x180;
    wk->hit_adrs = plw[0].wu.set_char_ad;
    wk->dmg_adrs = (u32*)plw[0].wu.hit_ix_table;
    slot = dbg_hita_ewk[1];
    slot->wu.routine_no[4] = 4;
    pat = (HITA_PAT*)((u8*)(slot) + 0x34);
    wk->set_char_ad = (u32*)pat;
    wk->cg_ix = 0;
    wk->cgd_type = 4;
    wk->dmcal_m = dbg_slot[6];
    for (i = 0; i < wk->dmcal_m; i++) {
        pat[i].frames = dbg_look_buf.rec[i + 1].u.frames;
        pat[i].param = dbg_look_buf.rec[i + 1].param;
    }
    pat[i].frames = 0;
    pat[i].kind = 2;
    pat[i].param = 1;
    wk->cg_ctr = pat[0].frames;
    body = (HITA_BOX*)((u8*)(dbg_hita_ewk[3]) + 0x34);
    wk->body_adrs = (BODY_BOX*)body;
    hand = (HITA_BOX*)((u8*)(dbg_hita_ewk[4]) + 0x34);
    wk->hand_adrs = (HAND_BOX*)hand;
    wk->catch_adrs = (CATCH_BOX*)hand;
    wk->caught_adrs = (CAUGHT_BOX*)hand;
    wk->hosei_adrs = (HOSEI_BOX*)hand;
    att = (HITA_BOX*)((u8*)(dbg_hita_ewk[5]) + 0x34);
    wk->attack_adrs = (ATTACK_BOX*)att;
    keys = (HITA_KEY*)((u8*)(dbg_hita_ewk[6]) + 0x34);
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (debug_memcmp_u32((u32*)&body[j], (u32*)&dbg_look_body[i], 8)) {
                keys[i].ix[0] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            body[n] = dbg_look_body[i];
            keys[i].ix[0] = n;
        }
        continue;
    }
    wk->vitality = n;
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (debug_memcmp_u32((u32*)&hand[j], (u32*)&dbg_look_hand[i], 8)) {
                keys[i].ix[1] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            hand[n] = dbg_look_hand[i];
            keys[i].ix[1] = n;
        }
    }
    wk->vital_new = n;
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (debug_memcmp_u32((u32*)&att[j], (u32*)&dbg_look_attack[i], 8)) {
                keys[i].ix[2] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            att[n] = dbg_look_attack[i];
            keys[i].ix[2] = n;
        }
    }
    wk->vital_old = n;
    n = 0;
    ixkey = (u32*)((u8*)(dbg_hita_ewk[2]) + 0x34);
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (keys[i].key == ixkey[j * 4]) {
                pat[i - 1].bits = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            ((HITA_KEY*)&ixkey[n * 4])->key = keys[i].key;
            pat[i - 1].bits = n;
        }
    }
    for (i = 0; i < wk->dmcal_m; i++) {
        pat[i].bits <<= 13;
    }
    ixtbl = (HITA_IX*)ixkey;
    wk->hit_ix_table = (HIT_IX*)ixtbl;
    for (i = 1; i <= n; i++) {
        t.key = ixkey[i * 4];
        ixtbl[i].body = t.ix[0];
        ixtbl[i].hand = t.ix[1];
        ixtbl[i].attack = t.ix[2];
        ixtbl[i].w2 = 0;
        ixtbl[i].w8 = 0;
        ixtbl[i].w10 = 0;
        ixtbl[i].w14 = 0;
        ixtbl[i].k.both = 0;
        continue;
    }
    wk->dmcal_d = n;
    wk->old_cgnum = 0;
    wk->spr.gfx_ofs = 0;
    wk->spr.gfx_cells = 0;
    for (i = 0; i < 4; i++) {
        wk->spr.gfx_blk10[i] = 0;
        wk->spr.gfx_blk40[i] = 0;
        wk->spr.gfx_blk_ex[i] = 0;
    }
    effect_K5_init((PLW*)wk);
    effect_00_init(wk);
    wk->cg_ix = -wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->K5_init_flag = 1;
    char_move(wk);
    wk->dir_timer = 0;
    wk->dir_step = 0;
    dbg_hita_grid_sw = 0;
}



/* provisional name */
s32 debug_memcmp_u32(u32* a, u32* b, s16 n) {
    s16 i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            break;
        }
    }
    return i == n;
}

/* provisional name */
u32 debug_hit_a_judgement_alloc_slot(u32 *slot)
{
    s16 ix;
    u8 *ewk;

    if ((ix = pull_effect_work(7)) == -1) {
        return 0xFFFFFFFF;
    }
    ewk = (u8 *)frw[ix];
    *ewk = 1;
    *slot = (u32)ewk;
    return 0;
}



/* provisional name */
void debug_hit_a_judgement_cleanup(void) {
    s16 i;
    plw[0].wu.myself = 0;
    plw[0].wu.before = 0;
    plw[0].wu.listix = 0;
    plw[0].wu.behind = 0;
    plw[0].wu.timing = 0;
    plw[0].wu.dead_f = 0;
    for (i = 0; i < dbg_hita_num; i++) {
        if (i == 0) {
            all_cgps_put_back(dbg_hita_ewk[i]);
        }
        push_effect_work(dbg_hita_ewk[i]);
        continue;
    }
}



/* provisional name */
void debug_hit_a_judgement_run(void) {
    WORK* wk = &dbg_hita_ewk[0]->wu;
    u16 sw1;
    u16 sw2;
    s16 group;
    wk->dir_timer++;
    sw1 = ~dbg_p1sw_1 & dbg_p1sw_0;
    sw2 = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw1 & 0x20) {
        char_move_z(wk);
    } else {
        switch (dbg_p1sw_0 & 0x70) {
        case 0x10:
            char_move(wk);
            break;
        case 0x30:
            if (!(wk->dir_timer & 1)) {
                char_move(wk);
            }
            break;
        case 0x20:
            if (!(wk->dir_timer & 3)) {
                char_move(wk);
            }
            break;
        case 0x60:
            if (!(wk->dir_timer & 7)) {
                char_move(wk);
            }
            break;
        case 0x40:
            if (!(wk->dir_timer & 15)) {
                char_move(wk);
            }
            break;
        }
    }
    if (sw2 & 0x80) {
        dbg_hita_grid_sw = (dbg_hita_grid_sw + 1) & 1;
    }
    debug_hit_a_judgement_navigate_xy(wk);
    if (debug_hit_a_judgement_column_nav(wk)) {
        wk->cg_ix -= wk->cgd_type;
        char_move_z(wk);
        debug_hit_a_judgement_print_footer();
    } else if (debug_hit_a_judgement_edit_grid(wk)) {
        wk->cg_ix -= wk->cgd_type;
        char_move_z(wk);
    }
    debug_hit_a_draw_cursor(wk->dir_step, wk->dir_timer);
    debug_hit_a_print_pattern_rows(wk, (GRID_REC*)(HITA_PAT*)wk->set_char_ad);
    debug_hit_a_print_hit_ix_rows(wk, (GRID9_REC*)(HITA_IX*)wk->hit_ix_table);
    debug_hit_a_print_counts(wk);
    debug_hit_a_print_box_values(wk);
    group = debug_cg_group_index(wk->cg_number);
    debug_draw_cg_group(wk->cg_number, group, 2, 25, 4);
    debug_draw_cg_group_offset(wk->cg_number, group, 8, 25, 4);
    if (sw1 & 0x200) {
        Debug_Tool_No = 4;
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_blank4_str);
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_exit_ok_str);
    }
    debug_rgb_editor_navigate(2);
    debug_rgb_editor_print(0);
    debug_char_disp(wk);
}



/* provisional name */
void debug_hit_a_judgement_navigate_xy(WORK* wk) {
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        wk->xyz[1].disp.pos++;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        wk->xyz[1].disp.pos--;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        wk->xyz[0].disp.pos--;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        wk->xyz[0].disp.pos++;
    }
}



/* provisional name */
s32 debug_hit_a_judgement_edit_grid(WORK* wk) {
    HITA_IX* ixtbl = (HITA_IX*)wk->hit_ix_table;
    HITA_PAT* pat = (HITA_PAT*)wk->set_char_ad;
    s16 ix = wk->cg_ix / wk->cgd_type;
    HITA_PAT* p = &pat[ix];
    HITA_IX* h = &ixtbl[(s16)(p->bits >> 13)];
    const HIT_KIND* kinds = hit_kind_tbl;
    s16 step;
    s16 i;
    s32 sw;
    s32 ret = 0;
    s32 ofs;
    if ((step = debug_hit_a_judgement_held_step()) != 0) {
        ofs = ((s8*)&wk->dir_step)[1];
        ofs *= sizeof(JUDGE_COLUMN);
        switch ((((const JUDGE_COLUMN*)((const u8*)judge_column_tbl + (s8)(ofs)))->rest[0])) {
        case 0:
            step += p->frames;
            if (step < 1) {
                step = 1;
            }
            if (step > 250) {
                step = 250;
            }
            p->frames = step;
            break;
        case 1:
            step += p->bits >> 13;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->dmcal_d) {
                step = wk->dmcal_d;
            }
            p->bits = step << 13;
            break;
        case 2:
            step += h->body;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vitality) {
                step = wk->vitality;
            }
            h->body = step;
            break;
        case 3:
            step += h->hand;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vital_new) {
                step = wk->vital_new;
            }
            h->hand = step;
            break;
        case 4:
            if (step > 0) {
                h->k.kind[0] = kinds[h->k.kind[0]].held_up;
            } else {
                h->k.kind[0] = kinds[h->k.kind[0]].held_down;
            }
            break;
        case 5:
            if (step > 0) {
                h->k.kind[1] = kinds[h->k.kind[1]].held_up;
            } else {
                h->k.kind[1] = kinds[h->k.kind[1]].held_down;
            }
            break;
        case 6:
            step += h->attack;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vital_old) {
                step = wk->vital_old;
            }
            h->attack = step;
            break;
        }
        return 1;
    } else if ((step = debug_hit_a_judgement_edit_step()) != 0) {
        ofs = ((s8*)&wk->dir_step)[1];
        ofs *= sizeof(JUDGE_COLUMN);
        switch ((((const JUDGE_COLUMN*)((const u8*)judge_column_tbl + (s8)(ofs)))->rest[0])) {
        case 0:
            step += p->frames;
            if (step < 1) {
                step = 1;
            }
            if (step > 250) {
                step = 250;
            }
            p->frames = step;
            break;
        case 1:
            step += p->bits >> 13;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->dmcal_d) {
                step = wk->dmcal_d;
            }
            p->bits = step << 13;
            break;
        case 2:
            step += h->body;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vitality) {
                step = wk->vitality;
            }
            h->body = step;
            break;
        case 3:
            step += h->hand;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vital_new) {
                step = wk->vital_new;
            }
            h->hand = step;
            break;
        case 4:
            if (step > 0) {
                h->k.kind[0] = kinds[h->k.kind[0]].up;
            } else {
                h->k.kind[0] = kinds[h->k.kind[0]].down;
            }
            break;
        case 5:
            if (step > 0) {
                h->k.kind[1] = kinds[h->k.kind[1]].up;
            } else {
                h->k.kind[1] = kinds[h->k.kind[1]].down;
            }
            break;
        case 6:
            step += h->attack;
            if (step < 0) {
                step = 0;
            }
            if (step > wk->vital_old) {
                step = wk->vital_old;
            }
            h->attack = step;
            break;
        }
        return 1;
    } else {
        sw = ~dbg_p1sw_1 & dbg_p1sw_0;
        if (sw & 0x80) {
            if (wk->dir_step < 2) {
                if (wk->dmcal_m <= 95) {
                    wk->dmcal_m++;
                    for (i = wk->dmcal_m + 1; i > ix; i--) {
                        pat[i] = pat[i - 1];
                    }
                    ret = 1;
                }
            } else if (wk->dmcal_d <= 95) {
                wk->dmcal_d++;
                ixtbl[wk->dmcal_d] = *h;
                ret = 1;
            }
        } else if (sw & 0x100) {
            if (wk->dir_step < 2) {
                if (wk->dmcal_m >= 2) {
                    for (i = ix; i < wk->dmcal_m; i++) {
                        pat[i] = pat[i + 1];
                        continue;
                    }
                    wk->dmcal_m--;
                    ret = 1;
                }
            } else {
                *h = ixtbl[0];
                ret = 1;
            }
        }
    }
    return ret;
}



/* provisional name */
s16 debug_hit_a_judgement_held_step(void) {
    if (!(dbg_p2sw_0 & 0x10)) {
        return 0;
    }
    if (debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        return -1;
    }
    if (debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 debug_hit_a_judgement_edit_step(void) {
    u16 sw;
    if (dbg_p2sw_0 & 0x10) {
        return 0;
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw & 0x20) {
        return 1;
    }
    if (sw & 0x40) {
        return -1;
    }
    return 0;
}



/* Hit-box editor: moves through the judgement columns; returns 1 when the selection changed. */
/* provisional name */
s32 debug_hit_a_judgement_column_nav(WORK* wk) {
    u32* tbl = wk->set_char_ad;
    s16 ix = wk->cg_ix / wk->cgd_type;
    s16 page = tbl[ix * 4 + 2] >> 13;
    s32 dir;
    s16 i;
    u32 target;
    s16 ret;
    if (dbg_p2sw_0 & 0x70) {
        return 0;
    }
    dir = debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4);
    dir += debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5) * 2;
    dir += debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6) * 4;
    dir += debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7) * 8;
    ret = 0;
    switch (dir) {
    case 1:
        if (wk->dir_step < 2) {
            if (ix == 0) {
                wk->cg_ix = (wk->dmcal_m - 1) * wk->cgd_type;
            } else {
                wk->cg_ix -= wk->cgd_type;
            }
        } else {
            if (page == 0) {
                break;
            }
            target = (page - 1) << 13;
            for (i = 0; i < wk->dmcal_m; i++) {
                if (tbl[i * 4 + 2] == target) {
                    break;
                }
            }
            if (i != wk->dmcal_m) {
                wk->cg_ix = i * wk->cgd_type;
            }
        }
        ret = 1;
        break;
    case 2:
        if (wk->dir_step < 2) {
            wk->cg_ix += wk->cgd_type;
        } else {
            if (page == wk->dmcal_d) {
                break;
            }
            target = (page + 1) << 13;
            for (i = 0; i < wk->dmcal_m; i++) {
                if (tbl[i * 4 + 2] == target) {
                    break;
                }
                continue;
            }
            if (i != wk->dmcal_m) {
                wk->cg_ix = i * wk->cgd_type;
            }
        }
        ret = 1;
        break;
    case 4:
        wk->dir_step = ((const JUDGE_COLUMN*)((const s8*)judge_column_tbl + (s8)((s8)(wk->dir_step) * sizeof(JUDGE_COLUMN))))->rest[3];
        ret = 1;
        break;
    case 8:
        ret = 1;
        wk->dir_step = ((const JUDGE_COLUMN*)((const s8*)judge_column_tbl + (s8)((s8)(wk->dir_step) * sizeof(JUDGE_COLUMN))))->rest[4];
        break;
    }
    return ret;
}



/* provisional name */
void debug_hit_a_judgement_print_footer(void) {
    tilemap_print_string_attr(3, 15, 0, debug_blank6_msg);
    tilemap_print_string_attr(29, 15, 0, debug_blank18_msg);
}



/* provisional name */
void debug_hit_a_draw_cursor(s16 col, s16 flags) {
    tilemap_print_string_attr(judge_column_tbl[(s8)col].x, judge_column_tbl[(s8)col].y, 4, dbg_sign_str[(flags & 0x20) == 0]);
}



/* provisional name */
void debug_hit_a_print_counts(WORK* wk) {
    tilemap_print_string_attr(10, 1, 10, debug_zero2_msg);
    tilemap_print_hex(10, 1, 10, Convert_BCD(wk->dmcal_d, 2), 2, 2);
    tilemap_print_string_attr(10, 3, 10, debug_zero2_msg);
    tilemap_print_hex(10, 3, 10, Convert_BCD(wk->dmcal_m, 2), 2, 2);
    tilemap_print_string_attr(13, 3, 10, debug_zero2_msg);
    tilemap_print_hex(13, 3, 10, Convert_BCD(wk->cg_ix / wk->cgd_type + 1, 2), 2, 2);
}



/* provisional name */
void debug_hit_a_print_pattern_rows(WORK* wk, GRID_REC* recs) {
    s16 i;
    s16 ix;
    s32 attr;
    u16 v;
    ix = wk->cg_ix / wk->cgd_type - 4;
    for (i = 0; i < 9; i++, ix++) {
        if (ix < 0 || ix >= wk->dmcal_m) {
            tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_empty_row_msg);
        } else {
            attr = 14;
            if (i == 4) {
                attr = 4;
            }
            tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_row_frame_msg);
            v = recs[ix].frames;
            tilemap_print_string_attr(hit_grid5_pos_tbl[i].x, hit_grid5_pos_tbl[i].y, attr, debug_blank3_msg);
            tilemap_print_hex(hit_grid5_pos_tbl[i].x, hit_grid5_pos_tbl[i].y, attr, Convert_BCD(v, 3), 3, 2);
            v = recs[ix].bits >> 13;
            tilemap_print_string_attr(hit_grid5_pos_tbl[i].x2, hit_grid5_pos_tbl[i].y2, attr, debug_zero2_msg);
            tilemap_print_hex(hit_grid5_pos_tbl[i].x2, hit_grid5_pos_tbl[i].y2, attr, Convert_BCD(v, 2), 2, 2);
        }
    }
}



/* provisional name */
void debug_hit_a_print_hit_ix_rows(WORK* wk, GRID9_REC* recs) {
    u16 i;
    s16 ix;
    u16 attr;
    ix = wk->cg_hit_ix;
    ix -= 3;
    for (i = 0; i < 7; i++, ix++) {
        if (ix < 0 || ix > wk->dmcal_d) {
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y + 0xFFFF, 0, grid9_empty_box_msg);
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y, 0, dbg_hit_row_empty_str);
        } else {
            attr = 14;
            if (i == 3) {
                attr = 4;
            }
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y + 0xFFFF, 0, dbg_hit_row_ix_str);
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y, 0, dbg_hit_row_blank_str);
            tilemap_print_string_attr(38, hit_grid9_pos_tbl[i].y, attr, dbg_hit_row_mb_str);
            tilemap_print_string_attr(32, hit_grid9_pos_tbl[i].y + 0xFFFF, attr, debug_zero2_msg);
            tilemap_print_hex(32, hit_grid9_pos_tbl[i].y + 0xFFFF, attr, Convert_BCD(ix, 2), 2, 2);
            tilemap_print_string_attr(32, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(32, hit_grid9_pos_tbl[i].y, attr, Convert_BCD(recs[ix].w0, 2), 2, 2);
            tilemap_print_string_attr(35, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(35, hit_grid9_pos_tbl[i].y, attr, Convert_BCD(recs[ix].w4, 2), 2, 2);
            tilemap_print_string_attr(39, hit_grid9_pos_tbl[i].y, attr, hit_kind_tbl[recs[ix].kind6].name);
            tilemap_print_string_attr(42, hit_grid9_pos_tbl[i].y, attr, hit_kind_tbl[recs[ix].kind7].name);
            tilemap_print_string_attr(45, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(45, hit_grid9_pos_tbl[i].y, attr, Convert_BCD(recs[ix].w12, 2), 2, 2);
        }
    }
}



/* provisional name */
void debug_hit_a_print_box_values(WORK* wk) {
    HITBOX* box;
    s32 i;
    s16 v;
    if (dbg_hita_grid_sw != 0 && wk->dir_step >= 2 && wk->dir_step != 4 && wk->dir_step != 5) {
        switch (wk->dir_step) {
        case 2:
            box = (HITBOX*)wk->h_bod;
            break;
        case 3:
            box = (HITBOX*)wk->h_han;
            break;
        default:
            box = (HITBOX*)wk->h_att;
            break;
        }
        for (i = 0; i < 4; i++) {
            tilemap_print_string_attr(11, i + 5, 2, dbg_hitbox_row_str);
            v = box[i].x;
            if (v < 0) {
                tilemap_print_string_attr(11, i + 5, 2, dbg_minus_str);
                v = -v;
            }
            tilemap_print_hex(12, i + 5, 2, v, 3, 0);
            tilemap_print_hex(16, i + 5, 2, box[i].w, 3, 0);
            v = box[i].y;
            if (v < 0) {
                tilemap_print_string_attr(20, i + 5, 2, dbg_minus_str);
                v = -v;
            }
            tilemap_print_hex(21, i + 5, 2, v, 3, 0);
            tilemap_print_hex(25, i + 5, 2, box[i].h, 3, 0);
        }
    } else {
        tilemap_print_string(0, 0, 0xFFFF, dbg_blank4_str);
    }
}



/* provisional name */
void debug_hit_a_exit_confirm(void) {
    s16 sw1 = ~dbg_p1sw_1 & dbg_p1sw_0 & 0x3F0;
    s16 sw2 = ~dbg_p2sw_1 & dbg_p2sw_0 & 0x3F0;
    if (dbg_hita_num < 7) {
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_work_empty_str);
        if (sw1 + sw2) {
            if (dbg_hita_num) {
                debug_hit_a_judgement_cleanup();
            }
            Debug_Tool_No = 5;
        }
        return;
    }
    if (sw2 & 0x200) {
        plw[0].wu.xyz[0].disp.pos -= 0x180;
        plw[0].wu.position_x -= 0x180;
        plw[1].wu.xyz[0].disp.pos -= 0x180;
        plw[1].wu.position_x -= 0x180;
        debug_hit_a_judgement_cleanup();
        Debug_Tool_No = 5;
        return;
    }
    if (sw1 & 0x200) {
        Debug_Tool_No = 3;
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)dbg_blank4_str);
    }
    debug_char_disp(&dbg_hita_ewk[0]->wu);
}



/* provisional name */
void debug_hit_judgment_redraw(void) {
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, hit_judgment_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_hit_size_str);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hit_part_str);
    Debug_Tool_No = 1;
}



/* provisional name */
void debug_clear_rgb_triplet_table(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        Debug_RGB[i] = 0;
    }
}



/* provisional name */
void debug_rgb_editor_navigate(s16 mode) {
    u16 sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    s16 i;
    switch (mode) {
    case 2:
        if (dbg_p2sw_0 & 0x200) {
            for (i = 0; i < 3; i++) {
                Debug_RGB[i]++;
            }
        }
        if (sw & 0x200) {
            for (i = 0; i < 3; i++) {
                Debug_RGB[i] += 3;
            }
        }
        break;
    default:
        if (dbg_p2sw_0 & 0x10) {
            Debug_RGB[0]--;
            if (sw & 0x10) {
                Debug_RGB[0] -= 3;
            }
        }
        if (dbg_p2sw_0 & 0x20) {
            Debug_RGB[1]--;
            if (sw & 0x20) {
                Debug_RGB[1] -= 3;
            }
        }
        if (dbg_p2sw_0 & 0x40) {
            Debug_RGB[2]--;
            if (sw & 0x40) {
                Debug_RGB[2] -= 3;
            }
        }
    case 1:
        if (dbg_p2sw_0 & 0x80) {
            Debug_RGB[0]++;
            if (sw & 0x80) {
                Debug_RGB[0] += 3;
            }
        }
        if (dbg_p2sw_0 & 0x100) {
            Debug_RGB[1]++;
            if (sw & 0x100) {
                Debug_RGB[1] += 3;
            }
        }
        if (dbg_p2sw_0 & 0x200) {
            Debug_RGB[2]++;
            if (sw & 0x200) {
                Debug_RGB[2] += 3;
            }
        }
        break;
    }
    Debug_RGB[0] &= 127;
    Debug_RGB[1] &= 127;
    Debug_RGB[2] &= 127;
}



/* provisional name */
void debug_bg_color_preset_next(void) {
    u16 sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & 0x40) {
        dbg_bgcol_ix++;
        dbg_bgcol_ix &= 7;
    }
    Debug_RGB[0] = dbg_rgb_preset_tbl[(s8)dbg_bgcol_ix][0];
    Debug_RGB[1] = dbg_rgb_preset_tbl[(s8)dbg_bgcol_ix][1];
    Debug_RGB[2] = dbg_rgb_preset_tbl[(s8)dbg_bgcol_ix][2];
}



/* provisional name */
void debug_rgb_editor_print(s16 print) {
    s16 r = (Debug_RGB[0] >> 2) & 31;
    u16 g = (Debug_RGB[1] >> 2) & 31;
    u16 b = (Debug_RGB[2] >> 2) & 31;
    if (print) {
        tilemap_print_hex(13, 12, 2, (u16)r, 2, 0);
        tilemap_print_hex(13, 13, 2, g, 2, 0);
        tilemap_print_hex(13, 14, 2, b, 2, 0);
    }
    *(u16*)COLOR_RAM = ((b << 10) | (g << 5) | r) & 0x7FFF;
}



/* provisional name */
void debug_catch_judgment_dispatch(void) {
    void (*Catch_Tbl[2])() = { debug_catch_judgment_init, debug_catch_judgment_run };
    dbg_pl = (PLW*)((u8*)plw + (s16)(Debug_PL_id * sizeof(PLW)));
    dbg_slot = (s16*)((u8*)dbg_slot_w + (s8)(Debug_PL_id * 18));
    Catch_Tbl[Debug_Tool_No]();
    if (!Debug_PL_id) {
        dbg_slot = dbg_slot_w[0];
    }
    debug_draw_object_info();
    debug_draw_position_delta();
    debug_draw_edit_side();
    debug_draw_cm_summary();
}



/* provisional name */
void debug_catch_judgment_init(void) {
    s32 i;
    PLW* wk;
    s16* sp;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, dbg_catch_judge_title);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    debug_both_players_reset();
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    Debug_PL_id = 0;
    dbg_cmd_panel = 0;
    Debug_Snap_Disp = 0;
    Debug_Dec_Disp = 0;
    for (i = 0, wk = &plw[0], sp = dbg_slot_w[0]; i < 2; i++, wk++, sp += 9) {
        dbg_pl = wk;
        dbg_slot = sp;
        debug_slot_char_load();
        debug_motion_list_count();
        debug_pattern_count();
        debug_pattern_timer_update();
    }
}



/* provisional name */
void debug_catch_judgment_run(void) {
    Debug_Command = 0;
    debug_catch_judgment_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip = dbg_pl->wu.cg_flip ^ Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 2:
        if (dbg_slot[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip = dbg_pl->wu.cg_flip ^ Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        if (dbg_slot[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip = dbg_pl->wu.cg_flip ^ Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        debug_pattern_timer_update();
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip = dbg_pl->wu.cg_flip ^ Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    }
    debug_char_disp(&plw[0].wu);
    debug_char_disp(&plw[1].wu);
}



/* provisional name */
void debug_char_preview_dispatch(void) {
    void (*Preview_Tbl[2])() = { debug_char_preview_init, debug_char_preview_run };
    dbg_pl = plw;
    dbg_slot = dbg_slot_w[0];
    Preview_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_char_preview_init(void) {
    s32 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string(0, 0, 0xFFFF, dbg_all_char_str);
    debug_char_slot_init(0);
    debug_char_slot_init(1);
    dbg_pl->wu.be_flag = 1;
    dbg_pl->wu.disp_flag = 1;
    dbg_pl->wu.cgromtype = 1;
    dbg_pl->wu.my_family = 1;
    dbg_pl->wu.my_col_code = 0x2000;
    dbg_pl->wu.my_col_mode = 0x4200;
    dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos = 0x220;
    dbg_pl->wu.my_priority = 62;
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos = 0;
    dbg_pl->wu.xyz[2].disp.pos = dbg_pl->wu.my_priority;
    dbg_pl->wu.xyz[0].disp.low = 0;
    dbg_pl->wu.xyz[1].disp.low = 0;
    dbg_pl->wu.xyz[2].disp.low = 0;
    dbg_pl->wu.charset_id = debug_charset_tbl[0];
    plw[0].wu.cg_number = plw[1].wu.cg_number = 0;
    plw[0].wu.old_cgnum = 1;
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    Debug_PL_id = 0;
    Debug_Snap_Disp = 0;
    Debug_Dec_Disp = 0;
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    Debug_RL_Flag[0] = 0;
    Debug_Flip_Work[0] = Debug_CG_Flip[0] = 0;
    Debug_Flip_Mask[0] = 0;
    Debug_RL_Flag[1] = 0;
    Debug_CG_Flip[1] = 0;
    Debug_Flip_Work[1] = 0;
    Debug_Flip_Mask[1] = 0;
    debug_clear_rgb_triplet_table();
    dbg_col_no = 0;
}

/* provisional name */
void debug_char_preview_run(void) {
    s32 kind;
    u16 group;
    u16 code;
    u16 cells;
    s32 pal;
    u16 shown;
    CharGfxSetHead* set;
    debug_position_by_pad();
    kind = debug_cg_bank_kind(dbg_pl->wu.cg_number);
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_pl->wu.cg_number -= 1;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0xE5B7;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number < 0x9000) {
                dbg_pl->wu.cg_number = 0x77FF;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number < 0xD800) {
                dbg_pl->wu.cg_number = 0xBDE7;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_pl->wu.cg_number += 1;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0x77FF) {
                dbg_pl->wu.cg_number = 0x9000;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number > 0xBDE8) {
                dbg_pl->wu.cg_number = 0xD800;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        dbg_pl->wu.cg_number -= 0x80;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0xE5B7;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number < 0x9000) {
                dbg_pl->wu.cg_number = 0x77FF;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number < 0xD800) {
                dbg_pl->wu.cg_number = 0xBDE7;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        dbg_pl->wu.cg_number += 0x80;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0x77FF) {
                dbg_pl->wu.cg_number = 0x9000;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number > 0xBDE8) {
                dbg_pl->wu.cg_number = 0xD800;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0;
            }
            break;
        }
    }
    if (~dbg_p1sw_1 & dbg_p1sw_0 & 0x100) {
        dbg_col_no++;
        if (((u16)dbg_col_no) > 14) {
            dbg_col_no = 0;
        }
        if (((u16)dbg_col_no) >= 7) {
            load_player_color(dbg_col_char, 1, ((u16)dbg_col_no) - 7);
            dbg_pl->wu.my_col_code = 0x2010;
        } else {
            load_player_color(dbg_col_char, 0, ((u16)dbg_col_no));
            dbg_pl->wu.my_col_code = 0x2000;
        }
    }
    if (dbg_pl->wu.cg_number < 0x8A00) {
        pal = dbg_pl->wu.cg_number / 0x600;
        if (dbg_pl->wu.cg_number >= 0x5A00) {
            pal++;
        }
        if (dbg_col_char != pal) {
            dbg_col_char = pal;
            if (((u16)dbg_col_no) >= 7) {
                load_player_color(dbg_col_char, 1, ((u16)dbg_col_no) - 7);
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                load_player_color(dbg_col_char, 0, ((u16)dbg_col_no));
                dbg_pl->wu.my_col_code = 0x2000;
            }
        }
    } else {
        if (dbg_pl->wu.cg_number > 0x9000 && dbg_pl->wu.cg_number < 0x9020) {
            dbg_col_char = 20;
        }
        if (dbg_pl->wu.cg_number > 0x9020 && dbg_pl->wu.cg_number < 0x9060 && dbg_col_char != 21) {
            dbg_col_char = 21;
        }
        if (dbg_pl->wu.cg_number >= 0xABF8 && dbg_pl->wu.cg_number <= 0xADF8) {
            load_player_color(17, 0, ((u16)dbg_col_no));
        }
        if (dbg_pl->wu.cg_number >= 0xB478 && dbg_pl->wu.cg_number <= 0xB498) {
            load_any_color(9);
            dbg_pl->wu.my_col_code = 0x2140;
        }
    }
    tilemap_print_hex(10, 7, 2, dbg_pl->wu.cg_number, 4, 0);
    group = debug_cg_group_index(plw[0].wu.cg_number);
    debug_draw_cg_group(plw[0].wu.cg_number, group, 4, 5, 2);
    debug_draw_cg_group_offset(plw[0].wu.cg_number, group, 10, 5, 2);
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (!dbg_pl->wu.disp_flag) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    shown = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (dbg_pl->zuru_timer != shown) {
        switch (debug_cg_bank_kind((u16)(dbg_pl->zuru_timer & 0x7FFF) / 4)) {
        case 0:
            code = bcp_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            purge_char_gfx(code);
            break;
        case 1:
            code = bce_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            if (code != 0x9000 && code != 0x9020) {
                purge_char_gfx(code);
            }
            break;
        case 2:
            code = bcb_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            purge_char_gfx(code);
            break;
        }
        dbg_pl->zuru_timer = shown;
    }
    dbg_pl->wu.cg_olc_ix = 0;
    dbg_pl->wu.cg_olc_ix = 0;
    debug_char_disp(&dbg_pl->wu);
    set = cg_data_list[dbg_pl->wu.cg_number].set;
    if (set->slot & 0x8000) {
        tilemap_print_string_attr(4, 10, 2, dbg_tikuji_str);
    } else {
        tilemap_print_string_attr(4, 10, 2, dbg_ikkatu_str);
    }
    cells = set->slot & 0x7FFF;
    tilemap_print_hex(11, 11, 2, cells, 4, 0);
    debug_rgb_editor_navigate(0);
    debug_rgb_editor_print(1);
}



/* provisional name */
void debug_parts_dispatch(void) {
    void (*Parts_Tbl[2])(void) = { debug_parts_init, debug_parts_run };

    if (Debug_PL_id) {
        dbg_pl = &dbg_parts_plw[dbg_parts_sel & 3];
    } else {
        dbg_pl = &plw[0];
    }
    dbg_slot = (s16*)&dbg_slot_w[Debug_PL_id];
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    Parts_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_parts_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(9, 1, 14, dbg_parts_title);
    tilemap_print_string(0, 0, 0xFFFF, dbg_parts_info_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_char_slot_init(1);
    debug_p1_reset();
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Snap_Disp = 0;
    dbg_rec_exist = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    dbg_parts_sel = 0;
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    for (i = 0; i < 4; i++) {
        dbg_parts_plw[i].wu.be_flag = 1;
        dbg_parts_plw[i].wu.disp_flag = 1;
        dbg_parts_plw[i].wu.cgromtype = 1;
        dbg_parts_plw[i].wu.my_family = 1;
        dbg_parts_plw[i].wu.my_col_mode = 0x4200;
        dbg_parts_plw[i].wu.work_id = 1;
        dbg_parts_plw[i].wu.xyz[0].disp.low = 0;
        dbg_parts_plw[i].wu.xyz[2].disp.low = dbg_parts_plw[i].wu.xyz[1].disp.low = 0;
        dbg_parts_plw[i].wu.my_col_code = 0x2000;
    }
    debug_parts_copy_overlap();
    for (i = 0; i < 4; i++) {
        Debug_RGB[i] = 0;
    }
}



/* provisional name */
void debug_parts_run(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_parts_input();
    switch (Debug_Command) {
    case 1:
        if (Debug_PL_id == 0) {
            debug_slot_char_load();
            debug_motion_list_count();
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
            dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
            debug_pattern_count();
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 2:
        if (Debug_PL_id == 0) {
            if (dbg_slot[0] > 0xD8) {
                set_char_move_init(&dbg_pl->wu, 0, dbg_slot[1] - 1);
            } else {
                set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
            }
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
            dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
            debug_pattern_count();
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 4:
        if (Debug_PL_id == 0) {
            char_move(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
            if (dbg_slot[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
                Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
                dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
                Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
                dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
            }
            dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
            dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 5:
        if (Debug_PL_id == 0) {
            char_move_z(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_slot[2]++;
            dbg_slot[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
            dbg_snap_ptr->dbg_val[1] = dbg_slot[7];
            dbg_snap_ptr->dbg_val[0] = dbg_slot[3];
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
    debug_parts_flip_apply();
    debug_char_disp(&plw[0].wu);
    debug_draw_parts_info();
    debug_parts_disp();
    if (Debug_PL_id == 0) {
        debug_rgb_editor_navigate(0);
        debug_rgb_editor_print(0);
    }
}



/* provisional name */
void debug_parts_copy_overlap(void) {
    s16 i;
    OVERLAP_PARTS* oct;
    PLW* pw;
    for (i = 0; i < 4; i++) {
        pw = &dbg_parts_plw[i];
        oct = &plw[0].wu.overlap_char_tbl[plw[0].wu.cg_olc.olc_ix[i]];
        pw->wu.cg_olc.olc_ix[i] = plw[0].wu.cg_olc.olc_ix[i];
        pw->wu.cg_olc_ix = plw[0].wu.cg_olc_ix;
        pw->wu.dir_step = oct->parts_hos_x;
        pw->wu.dir_timer = oct->parts_hos_y;
        pw->wu.xyz[0].disp.pos = plw[0].wu.xyz[0].disp.pos;
        pw->wu.xyz[1].disp.pos = plw[0].wu.xyz[1].disp.pos;
        pw->wu.xyz[0].disp.low = pw->wu.xyz[1].disp.low = 0;
        pw->wu.dir_old = oct->parts_flip;
        pw->wu.cg_flip = pw->wu.dir_old & 3;
        pw->wu.cg_number = oct->parts_char;
        pw->wu.old_rno[1] = oct->parts_prio;
    }
    for (i = 0; i < 4; i++) {
        dbg_parts_olc_ix[i] = plw[0].wu.cg_olc.olc_ix[i];
        plw[0].wu.cg_olc.olc_ix[i] = 0;
        continue;
    }
}



/* provisional name */
void debug_parts_flip_apply(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        if (dbg_parts_plw[i].wu.dir_old & 4) {
            dbg_parts_plw[i].wu.cg_flip = plw[0].wu.cg_flip ^ (s8)dbg_parts_plw[i].wu.dir_old;
        }
        plw[0].wu.cg_olc.olc_ix[i] = 0;
    }
}



/* provisional name */
/* The first loop writes slot 0 eight times. */
void debug_char_slot_init(s16 id) {
    PLW* save_wk;
    s16* save_sp;
    PLW* wk;
    s16* sp;
    s16 i;
    s16* p = (s16*)((s8*)dbg_slot_w + (s8)(id * 18));

    for (i = 0; i < 8; i++) {
        p[0] = 1;
    }
    sp = (s16*)((s8*)dbg_slot_w + (s8)(id * 18));
    sp[8] = 0;
    wk = (PLW*)((s8*)plw + (s16)(id * sizeof(PLW)));
    wk->player_number = 0;
    wk->wu.charset_id = debug_charset_tbl[0];
    wk->zuru_timer = 0;
    save_wk = dbg_pl;
    dbg_pl = wk;
    save_sp = dbg_slot;
    dbg_slot = sp;
    dbg_pl->wu.id = id;
    debug_char_init();
    dbg_pl->wu.disp_flag = 0;
    dbg_pl = save_wk;
    dbg_slot = save_sp;
}



/* provisional name */
void debug_edit_slots_reset(void) {
    s16 i;
    s16* sp = dbg_slot_w[0];

    for (i = 0; i < 2; i++) {
        s16* p = sp;
        sp[0] = 1;
        p[1] = 1;
        p[2] = 0;
        p[3] = 1;
        p[8] = 0;
        sp += 9;
    }
}



/* provisional name */
s32 debug_slot_all_select()
{
    s16 moved;
    s16 row;
    if (!(dbg_p1sw_0 & 0x1000)) {
        return 0;
    }
    if (!(dbg_p1sw_0 & 3)) {
        return 0;
    }
    moved = 0;
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_slot[0]--;
        moved = 1;
        if (dbg_slot[0] < 1) {
            dbg_slot[0] = dbg_slot[4];
        }
    } else if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_slot[0]++;
        moved = 1;
        if (dbg_slot[0] > dbg_slot[4]) {
            dbg_slot[0] = 1;
        }
    }
    if (dbg_slot[0] > 216) {
        row = 0;
    } else {
        if (dbg_slot[0] < 10) {
            row = dbg_slot[0] - 1;
        } else {
            row = dbg_slot[0] - 1;
            row -= row / 9 * 9;
        }
        if (row >= 8) {
            row++;
        }
    }
    dbg_slot[8] = row;
    if (moved) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 debug_slot_motion_select(void) {
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        dbg_slot[1]++;
        if (dbg_slot[1] > dbg_slot[5]) {
            dbg_slot[1] = 1;
        }
        return 2;
    } else if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        dbg_slot[1]--;
        if (dbg_slot[1] < 1) {
            dbg_slot[1] = dbg_slot[5];
        }
        return 2;
    }
    return 0;
}



/* provisional name: command 4 (step one frame) on P1 button 1, unreferenced */
s32 debug_check_step(void) {
    if (dbg_p1sw_0 & 0x10) {
        return 4;
    }
    return 0;
}



/* provisional name: command 6 (next recorded frame) on P2 button 1, unreferenced */
s32 debug_check_rec_step(void) {
    if (Debug_Rec_Count != 0 && (dbg_p2sw_0 & 0x10) != 0) {
        return 6;
    }
    return 0;
}



/* provisional name: command 5 on button 2, unreferenced */
s32 debug_check_step_z(u16 sw) {
    if (sw & 0x20) {
        return 5;
    }
    return 0;
}



/* provisional name: command 7 (restart recorded frame) on button 2, unreferenced */
s32 debug_check_rec_frame(u16 sw) {
    if (Debug_Rec_Count != 0 && (sw & 0x20) != 0) {
        return 7;
    }
    return 0;
}



/* provisional name */
s32 debug_flip_cycle(u16 sw) {
    s8 keep;
    if (sw & 0x80) {
        keep = dbg_pl->wu.cg_flip & 4;
        dbg_pl->wu.cg_flip++;
        dbg_pl->wu.cg_flip &= 3;
        dbg_pl->wu.cg_flip |= keep;
        keep = Debug_Flip_Mask[dbg_pl->wu.id] & 4;
        Debug_Flip_Mask[dbg_pl->wu.id]++;
        Debug_Flip_Mask[dbg_pl->wu.id] &= 3;
        Debug_Flip_Mask[dbg_pl->wu.id] |= keep;
        return 3;
    }
    return 0;
}



/* provisional name */
s32 debug_parts_flip_cycle(u16 sw) {
    s8 keep;
    if (sw & 0x80) {
        keep = dbg_pl->wu.cg_flip & 4;
        dbg_pl->wu.cg_flip++;
        dbg_pl->wu.cg_flip &= 3;
        dbg_pl->wu.cg_flip |= keep;
        if (!Debug_PL_id) {
            keep = Debug_Flip_Mask[dbg_pl->wu.id] & 4;
            Debug_Flip_Mask[dbg_pl->wu.id]++;
            Debug_Flip_Mask[dbg_pl->wu.id] &= 3;
            Debug_Flip_Mask[dbg_pl->wu.id] |= keep;
        }
        return 3;
    }
    return 0;
}



/* provisional name */
s32 debug_priority_swap(u16 sw) {
    if (sw & 0x40) {
        if (plw[0].wu.my_priority == 50) {
            plw[0].wu.my_priority = 51;
            plw[1].wu.my_priority = 50;
        } else {
            plw[0].wu.my_priority = 50;
            plw[1].wu.my_priority = 51;
        }
        return 3;
    }
    if ((plw[0].wu.my_priority == 50 && plw[1].wu.my_priority == 51)
        || (plw[1].wu.my_priority == 50 && plw[0].wu.my_priority == 51)) {
        return 0;
    }
    if (plw[0].wu.my_priority > plw[1].wu.my_priority) {
        plw[0].wu.my_priority = 51;
        plw[1].wu.my_priority = 50;
    } else {
        plw[0].wu.my_priority = 50;
        plw[1].wu.my_priority = 51;
    }
    return 0;
}



/* provisional name */
void debug_move_record_start(u16 sw) {
    s16 n;
    if (sw & 0x100) {
        if (Debug_Rec_Count != 0) {
            dbg_rec_menu = 15;
            return;
        }
        dbg_rec_menu = 0;
        n = debug_catch_move_record(dbg_snap_w[0], dbg_snap_w[1]);
        if (n != 0) {
            dbg_rec_exist = 1;
            Debug_Rec_Frame = 1;
        } else {
            Debug_Rec_Count = 0;
            Debug_Rec_Frame = 0;
        }
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
    }
}


/* provisional name */
void debug_pl_id_input(u16 sw) {
    if (sw & 0x40) {
        Debug_PL_id ^= 1;
    }
}


/* provisional name */
s32 debug_record_sw_check(u16 sw) {
    if (sw & 0x80) {
        return 8;
    }
    return 0;
}



/* provisional name */
void debug_record_frame_adjust(u16 sw) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x100, 19)) {
        dbg_snap_ptr->cg_ctr++;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x200, 20)) {
        dbg_snap_ptr->cg_ctr--;
        if (dbg_snap_ptr->cg_ctr < 0) {
            dbg_snap_ptr->cg_ctr = 0;
        }
    }
}

/* provisional name */
void debug_move_record_menu(void)
{
    s16 sw;
    s16 i;
    s16 cur;
    s16 next;

    if (Debug_Rec_Count) {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_menu_str);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_nodata_str);
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & 0x80) {
        /* clear all recorded frames */
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        Debug_Rec_Frame = 0;
        Debug_Rec_Count = 0;
        dbg_save_mode = 2;
        dbg_snap_req = 0;
        dbg_rec_menu = 0;
        dbg_rec_exist = 0;
        Debug_Play_Flag = 0;
    }
    if (sw & 0x100) {
        /* delete the current frame: pull the following snapshots down one slot */
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        for (i = Debug_Rec_Frame; i < Debug_Rec_Count; i++) {
            cur = i * sizeof(SNAPSHOT);
            next = (i + 1) * sizeof(SNAPSHOT);
            debug_copy_player_snapshot((SNAPSHOT *)((u8 *)dbg_snap_w[0] + next), (SNAPSHOT *)((u8 *)dbg_snap_w[0] + cur));
            debug_copy_player_snapshot((SNAPSHOT *)((u8 *)dbg_snap_w[1] + next), (SNAPSHOT *)((u8 *)dbg_snap_w[1] + cur));
        }
        Debug_Rec_Count--;
        dbg_rec_menu = 0;
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
    }
    if (sw & 0x200) {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        dbg_rec_menu = 0;
    }
}

/* provisional name */
void debug_playback_mode_cycle(u16 sw) {
    if ((sw & 0x200) != 0) {
        if (Debug_Rec_Count != 0) {
            dbg_rec_exist = 1;
            dbg_save_mode = dbg_save_mode + 1;
            if (2 < dbg_save_mode) {
                dbg_save_mode = 0;
            }
        }
    }
}



/* provisional name */
void debug_position_by_pad(void) {
    if (!(dbg_p1sw_0 & 0x1000)) {
        if (dbg_p1sw_0 & 2) {
            debug_bg_scroll_by_pad();
            return;
        }
        if ((dbg_p1sw_0 & 1) && (dbg_p2sw_0 & 0xF)) {
            debug_bg_position_reset();
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        dbg_pl->wu.xyz[1].disp.pos++;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        dbg_pl->wu.xyz[1].disp.pos--;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
        dbg_pl->wu.xyz[0].disp.pos--;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
        dbg_pl->wu.xyz[0].disp.pos++;
    }
}



/* provisional name: debug_bg_scroll_by_pad for BG layer 0 only, unreferenced */
void debug_bg0_scroll_by_pad(void) {
    if (p2sw_0 & 4) {
        bg_w.bgw[0].position_x--;
        bg_w.bgw[0].xy[0].disp.pos--;
    }
    if (p2sw_0 & 8) {
        bg_w.bgw[0].position_x++;
        bg_w.bgw[0].xy[0].disp.pos++;
    }
    if (p2sw_0 & 1) {
        bg_w.bgw[0].position_y++;
        bg_w.bgw[0].xy[1].disp.pos++;
    }
    if (p2sw_0 & 2) {
        bg_w.bgw[0].position_y--;
        bg_w.bgw[0].xy[1].disp.pos--;
    }
    Bg_Family_Set();
}



/* provisional name */
void debug_bg_position_reset(void) {
    s16 i;
    i = 0;
    while (i < bg_w.scno) {
        bg_w.bgw[i].xy[0].disp.pos = 0x100;
        bg_w.bgw[i].xy[1].disp.pos = 0;
        bg_w.bgw[i].xy[0].disp.low = 0;
        bg_w.bgw[i].xy[1].disp.low = 0;
        bg_w.bgw[i].position_x = 0x100;
        bg_w.bgw[i].position_y = 0;
        i++;
    }
    Bg_Family_Set();
}



/* provisional name */
void debug_bg_scroll_by_pad(void) {
    s16 i;
    if (p2sw_0 & 4) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_x--;
            bg_w.bgw[i].xy[0].disp.pos--;
        }
    }
    if (p2sw_0 & 8) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_x++;
            bg_w.bgw[i].xy[0].disp.pos++;
            continue;
        }
    }
    if (p2sw_0 & 1) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_y++;
            bg_w.bgw[i].xy[1].disp.pos++;
            continue;
        }
    }
    if (p2sw_0 & 2) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_y--;
            bg_w.bgw[i].xy[1].disp.pos--;
            continue;
        }
    }
    if (!bg_w.stage) {
        bg_w.bgw[4].hos_xy[0].cal = bg_w.bgw[4].xy[0].cal = bg_w.bgw[0].xy[0].cal;
        bg_w.bgw[4].hos_xy[0].cal = bg_w.bgw[4].xy[1].cal = bg_w.bgw[0].xy[1].cal;
    }
    Bg_Family_Set();
}



/* provisional name */
void debug_hit_box_edit(void) {
    u8* body;
    u8* hand;
    u8* attack;
    s16* box;
    u16 pad;
    if (Debug_PL_id == 0) {
        if ((u16)(~dbg_p2sw_1 & dbg_p2sw_0) & 0x20) {
            dbg_judge_ewk->look_up_flag ^= 1;
        }
        if (Debug_Box_Edit) {
            body = dbg_copy_buf.h_bod;
            hand = dbg_copy_buf.h_han;
            attack = dbg_copy_buf.h_att;
            switch (dbg_judge_ewk->curr_ja) {
            case 0:
                box = (s16*)body;
                break;
            case 1:
                box = (s16*)(body + 8);
                break;
            case 2:
                box = (s16*)(body + 16);
                break;
            case 3:
                box = (s16*)(body + 24);
                break;
            case 4:
                box = (s16*)hand;
                break;
            case 5:
                box = (s16*)(hand + 8);
                break;
            case 6:
                box = (s16*)(hand + 16);
                break;
            case 7:
                box = (s16*)(hand + 24);
                break;
            case 8:
                box = (s16*)dbg_copy_buf.h_cat;
                break;
            case 9:
                box = (s16*)dbg_copy_buf.h_cau;
                break;
            case 10:
                box = (s16*)attack;
                break;
            case 11:
                box = (s16*)(attack + 8);
                break;
            case 12:
                box = (s16*)(attack + 16);
                break;
            case 13:
                box = (s16*)(attack + 24);
                break;
            case 14:
                box = (s16*)dbg_copy_buf.h_hos;
                break;
            default:
                box = (s16*)&dbg_judge_ewk;
                break;
            }
            dbg_edit_box = box;
        } else if (dbg_judge_ewk->look_up_flag) {
            pad = dbg_p2sw_0;
            body = dbg_look_buf.h_bod;
            hand = dbg_look_buf.h_han;
            attack = dbg_look_buf.h_att;
            switch (dbg_judge_ewk->curr_ja) {
            case 0:
                box = (s16*)body;
                break;
            case 1:
                box = (s16*)(body + 8);
                break;
            case 2:
                box = (s16*)(body + 16);
                break;
            case 3:
                box = (s16*)(body + 24);
                break;
            case 4:
                box = (s16*)hand;
                break;
            case 5:
                box = (s16*)(hand + 8);
                break;
            case 6:
                box = (s16*)(hand + 16);
                break;
            case 7:
                box = (s16*)(hand + 24);
                break;
            case 8:
                box = (s16*)dbg_look_buf.h_cat;
                break;
            case 9:
                box = (s16*)dbg_look_buf.h_cau;
                break;
            case 10:
                box = (s16*)attack;
                break;
            case 11:
                box = (s16*)(attack + 8);
                break;
            case 12:
                box = (s16*)(attack + 16);
                break;
            case 13:
                box = (s16*)(attack + 24);
                break;
            case 14:
                box = (s16*)dbg_look_buf.h_hos;
                break;
            }
            dbg_edit_box = box;
            if (Debug_Box_Edit == 0) {
                if (pad & 0x10) {
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
                        box[3]++;
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
                        box[3]--;
                        if (box[3] < 0) {
                            box[3] = 0;
                        }
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
                        box[1]++;
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
                        box[1]--;
                        if (box[1] < 0) {
                            box[1] = 0;
                        }
                    }
                } else {
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
                        box[2]++;
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
                        box[2]--;
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
                        box[0]--;
                    }
                    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
                        box[0]++;
                    }
                }
            }
        } else {
            body = dbg_edit_buf.h_bod;
            hand = dbg_edit_buf.h_han;
            attack = dbg_edit_buf.h_att;
            switch (dbg_judge_ewk->curr_ja) {
            case 0:
                box = (s16*)body;
                break;
            case 1:
                box = (s16*)(body + 8);
                break;
            case 2:
                box = (s16*)(body + 16);
                break;
            case 3:
                box = (s16*)(body + 24);
                break;
            case 4:
                box = (s16*)hand;
                break;
            case 5:
                box = (s16*)(hand + 8);
                break;
            case 6:
                box = (s16*)(hand + 16);
                break;
            case 7:
                box = (s16*)(hand + 24);
                break;
            case 8:
                box = (s16*)dbg_edit_buf.h_cat;
                break;
            case 9:
                box = (s16*)dbg_edit_buf.h_cau;
                break;
            case 10:
                box = (s16*)attack;
                break;
            case 11:
                box = (s16*)(attack + 8);
                break;
            case 12:
                box = (s16*)(attack + 16);
                break;
            case 13:
                box = (s16*)(attack + 24);
                break;
            case 14:
                box = (s16*)dbg_edit_buf.h_hos;
                break;
            default:
                box = (s16*)&dbg_judge_ewk;
                break;
            }
            dbg_edit_box = box;
        }
    }
}



/* provisional name */
void debug_set_dummy_box(void) {
}



void debug_set_body_box(s16 n) {
    dbg_look_buf.h_bod = dbg_look_buf.body_adrs + n * 32;
    dbg_edit_buf.h_bod = dbg_edit_buf.body_adrs + n * 32;
}



/* provisional name */
void debug_set_hand_box(s16 n) {
    dbg_look_buf.h_han = dbg_look_buf.hand_adrs + n * 32;
    dbg_edit_buf.h_han = dbg_edit_buf.hand_adrs + n * 32;
}



/* provisional name */
void debug_set_catch_box(s16 n) {
    dbg_look_buf.h_cat = dbg_look_buf.catch_adrs + n * 8;
    dbg_edit_buf.h_cat = dbg_edit_buf.catch_adrs + n * 8;
}



/* provisional name */
void debug_set_caught_box(s16 n) {
    dbg_look_buf.h_cau = dbg_look_buf.caught_adrs + n * 8;
    dbg_edit_buf.h_cau = dbg_edit_buf.caught_adrs + n * 8;
}



/* provisional name */
void debug_set_attack_box(s16 n) {
    dbg_look_buf.h_att = dbg_look_buf.attack_adrs + n * 32;
    dbg_edit_buf.h_att = dbg_edit_buf.attack_adrs + n * 32;
}



/* provisional name */
void debug_set_hosei_box(s16 n) {
    dbg_look_buf.h_hos = dbg_look_buf.hosei_adrs + n * 8;
    dbg_edit_buf.h_hos = dbg_edit_buf.hosei_adrs + n * 8;
}

/* Point every hit-box cursor of the look and edit buffers at box number n. */
/* provisional name */
void debug_set_all_boxes(s16 n)
{
    debug_set_dummy_box();
    debug_set_body_box(n);
    debug_set_hand_box(n);
    debug_set_catch_box(n);
    debug_set_caught_box(n);
    debug_set_attack_box(n);
    debug_set_hosei_box(n);
}



/* provisional name */
void debug_hit_box_cursor(void) {
    u16 now;
    u16 sw;
    if (Debug_PL_id) {
        return;
    }
    now = dbg_p2sw_0;
    sw = ~dbg_p2sw_1 & now;
    if (!(now & 0x240)) {
        return;
    }
    tilemap_rect_fill(dbg_hud_x + 40, (s8)((WORK_Other*)dbg_judge_ewk)->refrected + 12, 8, 1, 2, 0xFFFF);
    if (sw & 0x40) {
        ((WORK_Other*)dbg_judge_ewk)->refrected--;
        if ((s8)((WORK_Other*)dbg_judge_ewk)->refrected < 0) {
            ((WORK_Other*)dbg_judge_ewk)->refrected = 14;
        }
    }
    if (sw & 0x200) {
        ((WORK_Other*)dbg_judge_ewk)->refrected++;
        if ((s8)((WORK_Other*)dbg_judge_ewk)->refrected > 14) {
            ((WORK_Other*)dbg_judge_ewk)->refrected = 0;
        }
    }
}



/* provisional name */
void debug_memcpy_u16(u16* src, u16* dst, s16 n) {
    s16 i;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
}



/* provisional name */
void debug_hit_box_copy(void) {
    u16 sw;
    if (!Debug_PL_id) {
        sw = ~dbg_p2sw_1 & dbg_p2sw_0;
        if (sw & 0x100) {
            Debug_Box_Edit ^= 1;
            if (Debug_Box_Edit) {
                if (dbg_judge_ewk->look_up_flag) {
                    debug_memcpy_u16((u16*)dbg_look_buf.h_bod, (u16*)dbg_copy_buf.h_bod, 16);
                    debug_memcpy_u16((u16*)dbg_look_buf.h_han, (u16*)dbg_copy_buf.h_han, 16);
                    debug_memcpy_u16((u16*)dbg_look_buf.h_att, (u16*)dbg_copy_buf.h_att, 16);
                    debug_memcpy_u16((u16*)dbg_look_buf.h_cat, (u16*)dbg_copy_buf.h_cat, 4);
                    debug_memcpy_u16((u16*)dbg_look_buf.h_cau, (u16*)dbg_copy_buf.h_cau, 4);
                    debug_memcpy_u16((u16*)dbg_look_buf.h_hos, (u16*)dbg_copy_buf.h_hos, 4);
                } else {
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_bod, (u16*)dbg_copy_buf.h_bod, 16);
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_han, (u16*)dbg_copy_buf.h_han, 16);
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_att, (u16*)dbg_copy_buf.h_att, 16);
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_cat, (u16*)dbg_copy_buf.h_cat, 4);
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_cau, (u16*)dbg_copy_buf.h_cau, 4);
                    debug_memcpy_u16((u16*)dbg_pl->wu.h_hos, (u16*)dbg_copy_buf.h_hos, 4);
                }
            } else {
                dbg_copy_done = 0;
            }
        }
        if ((sw & 0x80) && Debug_Box_Edit) {
            dbg_copy_done = 1;
            dbg_copy_pat = dbg_slot[2];
            dbg_copy_char = dbg_pl->wu.char_index;
            debug_set_body_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_bod, (u16*)dbg_look_buf.h_bod, 16);
            debug_set_hand_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_han, (u16*)dbg_look_buf.h_han, 16);
            debug_set_attack_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_att, (u16*)dbg_look_buf.h_att, 16);
            debug_set_catch_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_cat, (u16*)dbg_look_buf.h_cat, 4);
            debug_set_caught_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_cau, (u16*)dbg_look_buf.h_cau, 4);
            debug_set_hosei_box(dbg_slot[2]);
            debug_memcpy_u16((u16*)dbg_copy_buf.h_hos, (u16*)dbg_look_buf.h_hos, 4);
        }
    }
}

/* provisional name */
void debug_hit_box_show_select(void) {
    u16 sw = exsw_1;
    dbg_judge_ewk->ja_disp_bit = 0;
    dbg_judge_ewk->wu.spr.gfx_cells = 0;
    if (sw & 0x100) {
        dbg_judge_ewk->ja_disp_bit |= 0x120;
        dbg_judge_ewk->wu.spr.gfx_cells += 8;
    }
    if (sw & 0x200) {
        dbg_judge_ewk->ja_disp_bit |= 0x200;
        dbg_judge_ewk->wu.spr.gfx_cells += 4;
    }
    if (sw & 0x400) {
        dbg_judge_ewk->ja_disp_bit |= 0xC0;
        dbg_judge_ewk->wu.spr.gfx_cells += 8;
    }
    if (sw & 0x800) {
        dbg_judge_ewk->ja_disp_bit |= 0x1F;
        dbg_judge_ewk->wu.spr.gfx_cells += 20;
    }
    if (sw & 0x1000) {
        dbg_judge_ewk->ja_disp_bit |= 0x400;
        dbg_judge_ewk->wu.spr.gfx_cells += 2;
    }
}



/* provisional name */
u32 debug_edit_common_input(void)
{
    u32 sw;
    u32 ret;
    s32 i;

    if (Debug_Menu_No != 4) {
        debug_position_by_pad();
    }
    sw = ~(s16)dbg_p1sw_1 & (s16)dbg_p1sw_0;
    if ((Debug_Command = debug_slot_all_select(sw)) != 0) {
        return Debug_Command;
    }
    if ((Debug_Command = debug_slot_motion_select()) != 0) {
        return Debug_Command;
    }
    if ((Debug_Command = (sw & 0x20) ? 5 : 0) != 0) {
        return sw & 0xFFFF;
    }
    if ((Debug_Command = (dbg_p1sw_0 & 0x10) ? 4 : 0) != 0) {
        return dbg_p1sw_0;
    }
    ret = debug_flip_cycle(sw);
    Debug_Command = ret;
    if (sw & 0x800) {
        dbg_cmd_panel ^= 1;
        /* the value of the last print call is passed back (callers ignore it) */
        if (dbg_cmd_panel == 0) {
            for (i = 0; i < 6; i++) {
                tilemap_print_string_attr(0x14, i + 3, 2, dbg_space10_str);
                ret = ((u32 (*)())tilemap_print_string_attr)(0x21, i + 3, 2, dbg_space10_str);
                continue;
            }
        } else {
            tilemap_print_string_attr(0x14, 3, 2, dbg_slot_1p_s1_str);
            tilemap_print_string_attr(0x14, 4, 2, dbg_slot_1p_s2_str);
            tilemap_print_string_attr(0x14, 5, 2, dbg_slot_1p_s3_str);
            tilemap_print_string_attr(0x14, 6, 2, dbg_slot_1p_s4_str);
            tilemap_print_string_attr(0x14, 7, 2, dbg_slot_s5_str);
            tilemap_print_string_attr(0x14, 8, 2, dbg_slot_s6_str);
            tilemap_print_string_attr(0x21, 3, 2, dbg_slot_2p_s1_str);
            tilemap_print_string_attr(0x21, 4, 2, dbg_slot_2p_s2_str);
            tilemap_print_string_attr(0x21, 5, 2, dbg_slot_2p_s3_str);
            tilemap_print_string_attr(0x21, 6, 2, dbg_slot_2p_s4_str);
            tilemap_print_string_attr(0x21, 7, 2, dbg_slot_s5_str);
            ret = ((u32 (*)())tilemap_print_string_attr)(0x21, 8, 2, dbg_slot_s6_str);
        }
    }
    return ret;
}



/* provisional name */
void debug_kakusyuku_mode_cycle(u16 sw) {
    if (sw & 0x200) {
        dbg_kakusyuku_mode++;
        dbg_kakusyuku_mode &= 3;
        switch (dbg_kakusyuku_mode) {
        case 0:
            dbg_pl->wu.my_mr_flag = 0;
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            Zoomf_Init();
            break;
        case 1:
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            dbg_pl->wu.my_mr_flag = 0;
            break;
        case 2:
            dbg_pl->wu.my_mr_flag = 1;
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            Zoomf_Init();
            break;
        case 3:
            Zoomf_Init();
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            dbg_pl->wu.my_mr_flag = 1;
            break;
        }
    }
}



/* provisional name */
void debug_screen_zoom_by_pad(void) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 64, 16)) {
        dbg_zoom_x--;
        dbg_zoom_y--;
        if (dbg_zoom_x > 0) {
            Frame_Down(0xc0, 0xe0, 1, 1);
        } else {
            dbg_zoom_x = 0;
            dbg_zoom_y = 0;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x200, 19)) {
        dbg_zoom_x++;
        dbg_zoom_y++;
        if (dbg_zoom_x < 38) {
            Frame_Up(0xc0, 0xe0, 1, 1);
        } else {
            dbg_zoom_x = 38;
            dbg_zoom_y = 38;
        }
    }
}



/* provisional name */
void debug_char_scale_by_pad(void) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 16, 14)) {
        if (dbg_pl->wu.my_mr.size.x != 0) {
            dbg_pl->wu.my_mr.size.x--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 32, 15)) {
        if (dbg_pl->wu.my_mr.size.y != 0) {
            dbg_pl->wu.my_mr.size.y--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 128, 17)) {
        dbg_pl->wu.my_mr.size.x++;
        if (dbg_pl->wu.my_mr.size.x > 127) {
            dbg_pl->wu.my_mr.size.x = 127;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x100, 18)) {
        dbg_pl->wu.my_mr.size.y++;
        if (dbg_pl->wu.my_mr.size.y > 127) {
            dbg_pl->wu.my_mr.size.y = 127;
        }
    }
}



/* provisional name */
void debug_kakusyuku_input(void) {
    switch (dbg_kakusyuku_mode) {
    case 1:
        debug_screen_zoom_by_pad();
        break;
    case 2:
        debug_char_scale_by_pad();
        break;
    case 3:
        debug_screen_zoom_by_pad();
        debug_char_scale_by_pad();
        break;
    }
}


/* provisional name */
void debug_dec_disp_input(u16 sw) {
    if (sw & 0x1000) {
        Debug_Dec_Disp ^= 1;
    }
}



/* provisional name */
void debug_cmd_panel_run(void) {
    u16 trg = ~dbg_p1sw_1 & dbg_p1sw_0;
    u16 sel = (~dbg_p2sw_1 & dbg_p2sw_0 & 0x3f0) * 16 + (0x3f0 & trg) / 16;
    s32 i;
    s32 y;
    if (dbg_cmd_panel != 0) {
        switch (sel) {
        case 1:
            char_move_cmja(&dbg_pl->wu);
            break;
        case 2:
            char_move_cmj2(&dbg_pl->wu);
            break;
        case 4:
            char_move_cmj3(&dbg_pl->wu);
            break;
        case 8:
            char_move_cmj4(&dbg_pl->wu);
            break;
        case 0x100:
            char_move_cmoa(&dbg_pl->wu);
            break;
        case 0x200:
            if (dbg_pl->wu.cg_wca_ix != -1) {
                char_move_wca(&dbg_pl->wu);
            } else {
                tilemap_print_string_attr(20, 2, 2, dbg_no_wca_str);
            }
            break;
        case 0x400:
            if (dbg_pl->wu.cmja.pat != 0) {
                char_move_cmja(&dbg_pl->wu);
            } else {
                tilemap_print_string_attr(20, 2, 2, dbg_no_cmja_str);
            }
            break;
        default:
            if (trg & 0x800) {
                dbg_cmd_panel ^= 1;
            }
            goto draw;
        }
    }
    dbg_cmd_panel = 0;
    task_sleep(4);
draw:
    if (dbg_cmd_panel != 0) {
        tilemap_print_string_attr(20, 3, 2, dbg_slot_1p_s1_str);
        tilemap_print_string_attr(20, 4, 2, dbg_slot_1p_s2_str);
        tilemap_print_string_attr(20, 5, 2, dbg_slot_1p_s3_str);
        tilemap_print_string_attr(20, 6, 2, dbg_slot_1p_s4_str);
        tilemap_print_string_attr(20, 7, 2, dbg_slot_s5_str);
        tilemap_print_string_attr(20, 8, 2, dbg_slot_s6_str);
        tilemap_print_string_attr(33, 3, 2, dbg_slot_2p_s1_str);
        tilemap_print_string_attr(33, 4, 2, dbg_slot_2p_s2_str);
        tilemap_print_string_attr(33, 5, 2, dbg_slot_2p_s3_str);
        tilemap_print_string_attr(33, 6, 2, dbg_slot_2p_s4_str);
        tilemap_print_string_attr(33, 7, 2, dbg_slot_s5_str);
        tilemap_print_string_attr(33, 8, 2, dbg_slot_s6_str);
    } else {
        tilemap_print_string_attr(20, 2, 2, dbg_space10_str);
        for (i = 0, y = 3; i < 6; i++) {
            tilemap_print_string_attr(20, y, 2, dbg_space10_str);
            tilemap_print_string_attr(33, y++, 2, dbg_space10_str);
        }
    }
}



/* provisional name */
void debug_cg_number_browse(void) {
    u16 kind;
    s16 moved;
    s16 ix;
    u16 code;
    u16 group;
    debug_position_by_pad();
    debug_flip_cycle(~dbg_p1sw_1 & dbg_p1sw_0);
    kind = debug_cg_bank_kind((s16)dbg_pl->wu.cg_number);
    moved = 0;
    if (dbg_p1sw_0 & 0x1000) {
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
            dbg_pl->wu.cg_number--;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0xe5b7;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number < 0x9000) {
                    dbg_pl->wu.cg_number = 0x77ff;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number < 0xd800) {
                    dbg_pl->wu.cg_number = 0xbde7;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
            dbg_pl->wu.cg_number++;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0x77ff) {
                    dbg_pl->wu.cg_number = 0x9000;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number > 0xbde8) {
                    dbg_pl->wu.cg_number = 0xd800;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
            dbg_pl->wu.cg_number -= 0x80;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0xe5b7;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number < 0x9000) {
                    dbg_pl->wu.cg_number = 0x77ff;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number < 0xd800) {
                    dbg_pl->wu.cg_number = 0xbde7;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
            dbg_pl->wu.cg_number += 0x80;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0x77ff) {
                    dbg_pl->wu.cg_number = 0x9000;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number > 0xbde8) {
                    dbg_pl->wu.cg_number = 0xd800;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0;
                }
                break;
            }
        }
        if (moved == 0) {
            return;
        }
        if (dbg_pl->wu.cg_number < 0x8a00) {
            code = dbg_pl->wu.cg_number;
            ix = code / 0x600;
            if (code >= 0x5a00) {
                ix++;
            }
            if (ix != dbg_col_char) {
                dbg_col_char = ix;
                load_player_color(dbg_col_char, 1, 0);
                dbg_pl->wu.charset_id = debug_charset_tbl[dbg_col_char];
                dbg_pl->wu.my_col_mode = 0x4200;
                debug_char_table_load();
                set_char_base_data_init(&dbg_pl->wu);
                dbg_pl->wu.my_col_code = 0x2010;
            }
            dbg_pl->player_number = ix;
        } else {
            if (dbg_pl->wu.cg_number > 0x9000 && dbg_pl->wu.cg_number < 0x9020) {
                dbg_col_char = 20;
            }
            if (dbg_pl->wu.cg_number > 0x9020 && dbg_pl->wu.cg_number < 0x9060
                && dbg_col_char != 21) {
                dbg_col_char = 21;
            }
            if (dbg_pl->wu.cg_number >= 0xb478 && dbg_pl->wu.cg_number <= 0xb498) {
                load_any_color(9);
                dbg_pl->wu.my_col_code = 0x2140;
            }
        }
    }
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (dbg_pl->zuru_timer != group) {
        purge_char_gfx((u16)bcp_group_top_tbl[(dbg_pl->zuru_timer & 0x7fff) / 4]);
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_object_look_input(void) {
    u16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & 0x40) {
        Debug_Command = 6;
        return;
    }
    debug_kakusyuku_mode_cycle(sw);
    debug_kakusyuku_input();
}

/* provisional name */
void debug_object_edit_input(void)
{
    u32 sw;

    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    if (dbg_rec_menu) {
        debug_move_record_menu();
        return;
    }
    debug_edit_common_input();
    if (Debug_Command) {
        return;
    }
    sw = ~(s16)dbg_p1sw_1 & (s16)dbg_p1sw_0;
    if ((Debug_Command = debug_priority_swap(sw)) != 0) {
        return;
    }
    debug_move_record_start(sw);
    debug_playback_mode_cycle(sw);
    sw = ~(s16)dbg_p2sw_1 & (s16)dbg_p2sw_0;
    if ((Debug_Command = (Debug_Rec_Count && (sw & 0x20)) ? 7 : 0) != 0) {
        return;
    }
    if ((Debug_Command = (Debug_Rec_Count && (dbg_p2sw_0 & 0x10)) ? 6 : 0) != 0) {
        return;
    }
    if ((Debug_Command = (sw & 0x80) ? 8 : 0) != 0) {
        return;
    }
    if (sw & 0x1000) {
        Debug_Dec_Disp ^= 1;
    }
    debug_record_frame_adjust(sw);
    if (sw & 0x40) {
        Debug_PL_id ^= 1;
    }
    debug_zoom_out_by_dipsw();
    debug_player_color_next();
}



/* provisional name */
void debug_edit_all_char_input(void) {
    u16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    if (dbg_rec_menu) {
        debug_move_record_menu();
        return;
    }
    if (!dbg_pl->wu.id) {
        debug_edit_common_input();
    } else {
        debug_cg_number_browse();
    }
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if ((Debug_Command = debug_priority_swap(sw))) {
        return;
    }
    debug_move_record_start(sw);
    debug_playback_mode_cycle(sw);
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if ((Debug_Command = (Debug_Rec_Count && (sw & 0x20)) ? 7 : 0)) {
        return;
    }
    if ((Debug_Command = (Debug_Rec_Count && (dbg_p2sw_0 & 0x10)) ? 6 : 0)) {
        return;
    }
    if ((Debug_Command = (sw & 0x80) ? 8 : 0)) {
        return;
    }
    debug_record_frame_adjust(sw);
    if (sw & 0x40) {
        Debug_PL_id ^= 1;
    }
    if (sw & 0x1000) {
        Debug_Dec_Disp ^= 1;
    }
    debug_zoom_out_by_dipsw();
    debug_player_color_next();
}



/* provisional name */
void debug_hit_judgment_input(void) {
    s16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    debug_hit_box_edit();
    debug_hit_box_cursor();
    debug_hit_box_copy();
    if (!((WORK_Other*)dbg_judge_ewk)->dm_refrect) {
        debug_position_by_pad();
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw & 0x1000) {
        Debug_PL_id = Debug_PL_id ^ 1;
    }
    if (Debug_PL_id && (sw & 0x10)) {
        plw[1].wu.disp_flag = plw[1].wu.disp_flag ^ 1;
    }
    if ((~dbg_p1sw_1 & dbg_p1sw_0) & 0x100) {
        dbg_col_no++;
        if ((u16)dbg_col_no > 7) {
            dbg_col_no = 0;
        }
        load_player_color(dbg_pl->player_number, dbg_pl->wu.id, (u16)dbg_col_no);
    }
}



/* provisional name */
void debug_catch_judgment_input(void) {
    u16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    if (!Debug_Command) {
        sw = ~dbg_p2sw_1 & dbg_p2sw_0;
        if (sw & 0x40) {
            Debug_PL_id ^= 1;
        }
        if (sw & 0x1000) {
            Debug_Dec_Disp ^= 1;
        }
    }
}



/* provisional name */
void debug_parts_input(void) {
    u16 sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    s16 sw2;
    s16 i;
    if (!Debug_PL_id) {
        if ((Debug_Command = debug_slot_all_select(sw))) {
            return;
        }
        if ((Debug_Command = debug_slot_motion_select())) {
            return;
        }
    } else {
        if (sw & 0x100) {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step = -dbg_parts_plw[dbg_parts_sel].wu.dir_step;
        }
        if (sw & 0x200) {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer = -dbg_parts_plw[dbg_parts_sel].wu.dir_timer;
        }
    }
    if ((Debug_Command = (sw & 0x20) ? 5 : 0)) {
        return;
    }
    if ((Debug_Command = (dbg_p1sw_0 & 0x10) ? 4 : 0)) {
        return;
    }
    Debug_Command = debug_parts_flip_cycle(sw);
    if (Debug_Command) {
        return;
    }
    if ((Debug_Command = debug_priority_swap(~dbg_p1sw_1 & dbg_p1sw_0))) {
        return;
    }
    sw2 = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw2 & 0x10) {
        dbg_parts_sel++;
        dbg_parts_sel &= 3;
    }
    if (sw2 & 0x1000) {
        Debug_Dec_Disp ^= 1;
    }
    if (sw2 & 0x40) {
        Debug_PL_id ^= 1;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[1].disp.pos++;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[1].disp.pos++;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[1].disp.pos--;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[1].disp.pos--;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer++;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[0].disp.pos--;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[0].disp.pos--;
                continue;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[0].disp.pos++;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[0].disp.pos++;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step++;
        }
    }
}



/* provisional name */
s32 debug_lever_repeat(sw, old, mask, ix)
    u16 sw;
    u16 old;
    u16 mask;
    s16 ix;
{
    if (sw & mask) {
        if (Debug_Menu_No == 5 && (sw & 0x10)) {
            return 1;
        }
        Debug_Rep_Timer[ix]++;
        if (~old & sw & mask) {
            Debug_Rep_Timer[ix] = 0;
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
        if (ix > 3) {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                return 1;
            }
            return 0;
        }
        if (Debug_Rep_Timer[ix] > 10) {
            Debug_Rep_Count[ix]++;
            if (Debug_Rep_Count[ix] > 4) {
                Debug_Rep_Count[ix] = 0;
                return 1;
            }
        }
        return 0;
    }
    Debug_Rep_Count[ix] = Debug_Rep_Timer[ix] = 0;
    return 0;
}



/* provisional name */
s32 debug_lever_repeat_fast(u16 sw, u16 old, u16 mask, s16 ix) {
    if (sw & mask) {
        if (sw & 0x10) {
            return 1;
        }
        Debug_Rep_Timer[ix]++;
        if (~old & sw & mask) {
            Debug_Rep_Timer[ix] = 0;
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
        if (ix > 3) {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                return 1;
            }
            return 0;
        }
        if (Debug_Rep_Timer[ix] > 10) {
            Debug_Rep_Count[ix]++;
            if (Debug_Rep_Count[ix] > 4) {
                Debug_Rep_Count[ix] = 0;
                return 1;
            }
        }
        return 0;
    }
    Debug_Rep_Count[ix] = Debug_Rep_Timer[ix] = 0;
    return 0;
}

/* provisional name */
u32 debug_held_pad_repeat(sw_now, sw_old, mask, ix)
u16 sw_now;
u16 sw_old;
u16 mask;
u16 ix;
{
    if (!(mask & sw_now)) {
        Debug_Rep_Count[ix] = Debug_Rep_Timer[ix] = 0;
        return 0;
    }
    if (mask & ~sw_old & sw_now) {
        Debug_Rep_Timer[ix] = 0;
        Debug_Rep_Count[ix] = 0;
        return 1;
    }
    Debug_Rep_Timer[ix]++;
    if (ix < 4) {
        if (Debug_Rep_Timer[ix] > 12) {
            Debug_Rep_Timer[ix] = 12;
            return 1;
        }
    } else if (Debug_Rep_Timer[ix] > 16) {
        if (++Debug_Rep_Count[ix] > 4) {
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
    }
    return 0;
}



/* provisional name */
void debug_pattern_timer_update(void) {
    u32* p = dbg_pl->wu.set_char_ad + dbg_pl->wu.cg_ix;

    dbg_slot[7] = *(s8*)p;
    dbg_slot[3] = dbg_slot[7] - dbg_pl->wu.cg_ctr + 1;
}



/* provisional name */
void debug_edit_pattern_timer_update(void) {
    dbg_slot[7] = dbg_edit_buf.rec[dbg_slot[2]].u.frames;
    dbg_slot[3] = dbg_slot[7] + 1 - dbg_pl->wu.cg_ctr;
}



/* provisional name */
void debug_char_table_load(void) {
    dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[dbg_pl->player_number][0];
    dbg_pl->wu.char_table[1] = dbg_pl_char_tbl[dbg_pl->player_number][1];
    dbg_pl->wu.char_table[2] = dbg_pl_char_tbl[dbg_pl->player_number][2];
    dbg_pl->wu.char_table[3] = dbg_pl_char_tbl[dbg_pl->player_number][3];
    dbg_pl->wu.char_table[4] = dbg_pl_char_tbl[dbg_pl->player_number][4];
    dbg_pl->wu.char_table[5] = dbg_pl_char_tbl[dbg_pl->player_number][5];
    dbg_pl->wu.char_table[6] = dbg_pl_char_tbl[dbg_pl->player_number][6];
    dbg_pl->wu.char_table[7] = dbg_pl_char_tbl[dbg_pl->player_number][7];
    dbg_pl->wu.char_table[8] = dbg_pl_char_tbl[dbg_pl->player_number][8];
    dbg_pl->wu.char_table[9] = dbg_pl_char_tbl[dbg_pl->player_number][8];
}



/* provisional name */
void debug_slot_char_load(void) {
    s16 ix;
    s16 n;
    s16 row;
    s16 col;
    u16 group;
    if (*dbg_slot <= 0xd8) {
        dbg_pl->wu.operator = 0;
        if (*dbg_slot < 10) {
            ix = 0;
        } else {
            ix = (*dbg_slot - 1) / 9;
        }
        if (dbg_pl->player_number != ix) {
            dbg_pl->player_number = ix;
            dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
            dbg_pl->wu.my_col_mode = 0x4200;
            debug_char_table_load();
            set_char_base_data_init(&dbg_pl->wu);
            if (dbg_pl->wu.id) {
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                dbg_pl->wu.my_col_code = 0x2000;
            }
            load_player_color(dbg_pl_color_tbl[dbg_pl->player_number], dbg_pl->wu.id, 0);
            set_player_shadow(dbg_pl);
        }
        set_char_move_init(&dbg_pl->wu, dbg_slot[8], 0);
    } else {
        switch (*dbg_slot) {
        case 0xd9:
            load_player_color(1, 0, 0);
            dbg_pl->wu.my_col_code = 0x4007;
            break;
        case 0xda:
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[*dbg_slot - 0xd7]);
            dbg_pl->wu.my_col_code = 0x4020;
            break;
        case 0xdb:
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[*dbg_slot - 0xd7]);
            break;
        case 0xfb:
            dbg_pl->wu.my_col_code = 0x4140;
            load_any_color(dbg_obj_color_tbl[*dbg_slot - 0xd7]);
            break;
        default:
            dbg_pl->wu.my_col_mode = 0x4200;
            dbg_pl->wu.my_col_code = 0x4080;
            break;
        }
        dbg_pl->player_number = 0x99;
        dbg_pl->wu.operator = 1;
        n = *dbg_slot - 0xd8;
        if (n < 10) {
            col = n - 1;
            row = 0;
        } else {
            col = (n - 1) % 9;
            row = (n - 1) / 9;
        }
        row += 24;
        dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[row][col];
        set_char_move_init(&dbg_pl->wu, 0, 0);
    }
    Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
    dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
    Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (group & 0x8000) {
        purge_char_gfx(dbg_pl->wu.old_rno[0]);
        dbg_pl->zuru_timer = group;
    } else if (!get_cg_slot_addr(group)) {
        if (!(dbg_pl->zuru_timer & 0x8000)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
        }
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_slot_char_load_keep_col(void) {
    s16 ix;
    s16 n;
    s16 row;
    s16 col;
    s32 group;
    if (*dbg_slot <= 0xd8) {
        dbg_pl->wu.operator = 0;
        if (*dbg_slot < 10) {
            ix = 0;
        } else {
            ix = (*dbg_slot - 1) / 9;
        }
        if (dbg_pl->player_number != ix) {
            dbg_pl->player_number = ix;
            dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
            dbg_pl->wu.my_col_mode = 0x4200;
            debug_char_table_load();
            set_char_base_data_init(&dbg_pl->wu);
            if (dbg_pl->wu.id) {
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                dbg_pl->wu.my_col_code = 0x2000;
            }
            load_player_color(dbg_pl_color_tbl[dbg_pl->player_number], 0, dbg_pl->wu.id, (u16)dbg_col_no);
            set_player_shadow(dbg_pl);
        }
        set_char_move_init(&dbg_pl->wu, dbg_slot[8], 0);
    } else {
        dbg_pl->wu.my_col_mode = 0x4200;
        dbg_pl->wu.my_col_code = 0x4080;
        if (*dbg_slot == 0xd9) {
            load_player_color(1, 0, 0);
            dbg_pl->wu.my_col_code = 0x4007;
        }
        if (*dbg_slot == 0xda) {
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[*dbg_slot - 0xda]);
            dbg_pl->wu.my_col_code = 0x4020;
        }
        if (*dbg_slot == 0xdb) {
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[*dbg_slot - 0xdb]);
            dbg_pl->wu.my_col_code = 0x4040;
        }
        dbg_pl->player_number = 0x99;
        dbg_pl->wu.operator = 1;
        n = *dbg_slot - 0xd8;
        if (n < 10) {
            col = n - 1;
            row = 0;
        } else {
            col = (n - 1) % 9;
            row = (n - 1) / 9;
        }
        row += 24;
        dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[row][col];
        set_char_move_init(&dbg_pl->wu, 0, 0);
    }
    Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
    dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
    Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (group & 0x8000) {
        purge_char_gfx(dbg_pl->wu.old_rno[0]);
        dbg_pl->zuru_timer = group;
    } else if (!get_cg_slot_addr(group)) {
        if (!(dbg_pl->zuru_timer & 0x8000)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
        }
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_char_disp(WORK* wk) {
    wk->position_x = wk->xyz[0].disp.pos;
    wk->position_y = wk->xyz[1].disp.pos;
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
}


/* provisional name */
void debug_char_disp_sort(WORK* wk) {
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
}



/* provisional name */
void debug_char_disp_once(WORK* wk) {
    wk->be_flag = 1;
    wk->disp_flag = 1;
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
    wk->be_flag = 0;
    wk->disp_flag = 0;
}



/* provisional name */
void debug_parts_disp(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        dbg_parts_plw[i].wu.position_x = plw[0].wu.position_x;
        dbg_parts_plw[i].wu.position_y = plw[0].wu.position_y;
        dbg_parts_plw[i].wu.position_z = plw[0].wu.position_z;
        dbg_parts_plw[i].wu.rl_flag = plw[0].wu.rl_flag;
        if (dbg_parts_plw[i].wu.dir_old & 4) {
            dbg_parts_plw[i].wu.cg_flip = dbg_parts_plw[i].wu.dir_old ^= plw[0].wu.cg_flip;
            if (plw[0].wu.cg_flip & 1) {
                dbg_parts_plw[i].wu.rl_flag = (dbg_parts_plw[i].wu.rl_flag + 1) & 1;
            }
        }
        if (dbg_parts_plw[i].wu.rl_flag) {
            dbg_parts_plw[i].wu.position_x -= dbg_parts_plw[i].wu.dir_step;
        } else {
            dbg_parts_plw[i].wu.position_x += dbg_parts_plw[i].wu.dir_step;
        }
        dbg_parts_plw[i].wu.position_y += dbg_parts_plw[i].wu.dir_timer;
        if ((dbg_parts_plw[i].wu.dir_old & 4) && (plw[0].wu.cg_flip & 2)) {
            dbg_parts_plw[i].wu.position_y -= dbg_parts_plw[i].wu.dir_timer * 2;
        }
        if (dbg_parts_plw[i].wu.old_rno[1] == 2) {
            dbg_parts_plw[i].wu.position_z -= (i + 1) * 2;
        } else {
            dbg_parts_plw[i].wu.position_z += (i + 1) * 2;
        }
        sort_push_request(&dbg_parts_plw[i].wu);
    }
}



/* provisional name */
void debug_pattern_edit_init_counts(void) {
    u32* pat = dbg_pl_char_tbl;
    dbg_slot_w[0][0] = 1;
    dbg_slot_w[1][0] = 1;
    dbg_slot_w[0][4] = 0;
    dbg_slot_w[1][4] = 0;
    while (*pat) {
        pat++;
        dbg_slot_w[0][4]++;
        dbg_slot_w[1][4]++;
    }
}



/* provisional name */
void debug_motion_list_count(void) {
    u32* p;
    dbg_slot[1] = 1;
    if (dbg_slot[0] > 0xD8) {
        p = dbg_pl->wu.char_table[0];
    } else {
        switch (dbg_slot[8]) {
        case 0:
            p = dbg_pl->wu.char_table[0];
            break;
        case 1:
            p = dbg_pl->wu.char_table[1];
            break;
        case 2:
            p = dbg_pl->wu.char_table[2];
            break;
        case 3:
            p = dbg_pl->wu.char_table[3];
            break;
        case 4:
            p = dbg_pl->wu.char_table[4];
            break;
        case 5:
            p = dbg_pl->wu.char_table[5];
            break;
        case 6:
            p = dbg_pl->wu.char_table[6];
            break;
        case 7:
            p = dbg_pl->wu.char_table[7];
            break;
        case 8:
        case 9:
            p = dbg_pl->wu.char_table[9];
            break;
        }
    }
    dbg_slot[5] = 0;
    while (*p) {
        p++;
        dbg_slot[5]++;
    }
}



/* provisional name */
void debug_pattern_count(void) {
    u32* p;
    s16 m = 0x100;
    dbg_slot[2] = 0;
    p = dbg_pl->wu.set_char_ad;
    dbg_slot[6] = 0;
    for (;;) {
        u32* q = p;
        if (*(u16*)q == 1) {
            break;
        }
        if (*(u16*)q >= m) {
            dbg_slot[6]++;
        }
        p += dbg_pl->wu.cgd_type;
    }
}



/* provisional name */
void debug_pattern_entry_copy_dual(s16 n, s16 box) {
    u16* src;
    u16* a;
    u16* b;
    s16 i;
    HIT_IX* ix;
    src = (u16*)&dbg_pl->wu.hit_ix_table[box];
    a = dbg_look_buf.hit_ix[n];
    b = dbg_edit_buf.hit_ix[n];
    for (i = 0; i < 8; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    ix = &dbg_pl->wu.hit_ix_table[box];
    src = (u16*)&dbg_pl->wu.body_adrs[ix->boix];
    a = (u16*)(dbg_look_buf.body_adrs + n * 32);
    b = (u16*)(dbg_edit_buf.body_adrs + n * 32);
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.hand_adrs[ix->bhix + ix->haix];
    a = (u16*)(dbg_look_buf.hand_adrs + n * 32);
    b = (u16*)(dbg_edit_buf.hand_adrs + n * 32);
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
        continue;
    }
    src = (u16*)&dbg_pl->wu.attack_adrs[ix->atix];
    a = (u16*)(dbg_look_buf.attack_adrs + n * 32);
    b = (u16*)(dbg_edit_buf.attack_adrs + n * 32);
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.catch_adrs[ix->caix];
    a = (u16*)(dbg_look_buf.catch_adrs + n * 8);
    b = (u16*)(dbg_edit_buf.catch_adrs + n * 8);
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
        continue;
    }
    src = (u16*)&dbg_pl->wu.caught_adrs[ix->cuix];
    a = (u16*)(dbg_look_buf.caught_adrs + n * 8);
    b = (u16*)(dbg_edit_buf.caught_adrs + n * 8);
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.hosei_adrs[ix->hoix];
    a = (u16*)(dbg_look_buf.hosei_adrs + n * 8);
    b = (u16*)(dbg_edit_buf.hosei_adrs + n * 8);
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
}



/* provisional name */
void debug_pattern_list_build(void) {
    union {
        u32 l;
        struct {
            s16 hi;
            s16 lo;
        } w;
    } v;
    s16 n;
    u16* p;
    dbg_slot[2] = 1;
    dbg_slot[6] = 0;
    n = 0;
    for (p = (u16*)dbg_pl->wu.set_char_ad; *p != 1; p += dbg_pl->wu.cgd_type * 2) {
        if (*p < 0x100) {
            continue;
        }
        n++;
        dbg_slot[6]++;
        dbg_look_buf.rec[dbg_slot[6]].u.code = p[0];
        dbg_edit_buf.rec[dbg_slot[6]].u.code = p[0];
        dbg_look_buf.rec[dbg_slot[6]].type = dbg_pl->wu.cgd_type;
        dbg_look_buf.rec[dbg_slot[6]].param = p[3];
        if (dbg_pl->wu.cgd_type == 2) {
            v.w.hi = 0;
            v.w.lo = 0;
        } else {
            v.w.hi = p[4];
            v.w.lo = p[5];
        }
        v.l <<= 3;
        dbg_look_buf.rec[dbg_slot[6]].box = v.w.hi & 0x1FF;
        dbg_edit_buf.rec[dbg_slot[6]].type = dbg_pl->wu.cgd_type;
        dbg_edit_buf.rec[dbg_slot[6]].param = p[3];
        if (dbg_pl->wu.cgd_type == 2) {
            v.w.hi = 0;
            v.w.lo = 0;
        } else {
            v.w.hi = p[4];
            v.w.lo = p[5];
        }
        v.l <<= 3;
        dbg_edit_buf.rec[dbg_slot[6]].box = v.w.hi & 0x1FF;
        debug_pattern_entry_copy_dual(n, dbg_look_buf.rec[n].box);
    }
}

/* provisional name */
void debug_pattern_preview_step(WORK* wk)
{
    OLC_IX *olc;
    HIT_IX *ja;

    if (--dbg_pl->wu.cg_ctr != 0) {
        return;
    }
    dbg_slot[2]++;
    if (dbg_slot[2] > dbg_slot[6]) {
        dbg_slot[2] = 1;
    }
    olc = &wk->olc_ix_table[wk->cg_olc_ix];
    wk->cg_olc = *olc;
    if (((WORK_Other_JUDGE *)dbg_judge_ewk)->look_up_flag) {
        wk->cgd_type = dbg_look_buf.rec[dbg_slot[2]].type;
        wk->cg_ctr = dbg_look_buf.rec[dbg_slot[2]].u.frames;
        wk->cg_number = dbg_look_buf.rec[dbg_slot[2]].param;
        wk->cg_hit_ix = dbg_look_buf.rec[dbg_slot[2]].box;
        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }
        ja = &wk->hit_ix_table[wk->cg_hit_ix];
        wk->cg_ja = *ja;
        wk->h_bod = wk->body_adrs + dbg_look_buf.hit_ix[dbg_slot[2]][0];
        wk->h_han = wk->hand_adrs + (dbg_look_buf.hit_ix[dbg_slot[2]][2] + dbg_look_buf.hit_ix[dbg_slot[2]][1]);
        wk->h_cat = wk->catch_adrs + dbg_look_buf.hit_ix[dbg_slot[2]][4];
        wk->h_cau = wk->caught_adrs + dbg_look_buf.hit_ix[dbg_slot[2]][5];
        wk->h_att = wk->attack_adrs + dbg_look_buf.hit_ix[dbg_slot[2]][6];
        wk->h_hos = wk->hosei_adrs + dbg_look_buf.hit_ix[dbg_slot[2]][7];
    } else {
        wk->cgd_type = dbg_edit_buf.rec[dbg_slot[2]].type;
        wk->cg_ctr = dbg_edit_buf.rec[dbg_slot[2]].u.frames;
        wk->cg_number = dbg_edit_buf.rec[dbg_slot[2]].param;
        wk->cg_hit_ix = dbg_edit_buf.rec[dbg_slot[2]].box;
        wk->h_bod = wk->body_adrs + dbg_edit_buf.hit_ix[dbg_slot[2]][0];
        wk->h_han = wk->hand_adrs + (dbg_edit_buf.hit_ix[dbg_slot[2]][2] + dbg_edit_buf.hit_ix[dbg_slot[2]][1]);
        wk->h_cat = wk->catch_adrs + dbg_edit_buf.hit_ix[dbg_slot[2]][4];
        wk->h_cau = wk->caught_adrs + dbg_edit_buf.hit_ix[dbg_slot[2]][5];
        wk->h_att = wk->attack_adrs + dbg_edit_buf.hit_ix[dbg_slot[2]][6];
        wk->h_hos = wk->hosei_adrs + dbg_edit_buf.hit_ix[dbg_slot[2]][7];
    }
    if (wk->cg_type == 0xFF) {
        return;
    }
    if (!(wk->cg_type & 0x80)) {
        return;
    }
    wk->cg_wca_ix = wk->cg_type & 0x7F;
    wk->cg_type = 0;
}



/* provisional name */
void debug_save_player_snapshot(SNAPSHOT* rec, WORK* wk) {
    rec->pos_x = wk->xyz[0].disp.pos;
    rec->pos_y = wk->xyz[1].disp.pos;
    rec->priority = wk->my_priority;
    rec->cg_number = wk->cg_number;
    rec->v8 = Debug_RL_Flag[wk->id];
    rec->v9 = Debug_CG_Flip[wk->id];
    rec->used = 1;
    rec->col_mode = wk->my_col_mode;
    rec->col_code = wk->my_col_code;
    rec->olc_ix = wk->cg_olc_ix;
    rec->rl_flag = wk->rl_flag;
    rec->cg_flip = wk->cg_flip;
    if (dbg_save_mode) {
        rec->cg_ctr = wk->cg_ctr;
    }
}



/* provisional name */
void debug_copy_player_snapshot(SNAPSHOT* src, SNAPSHOT* dst) {
    dst->pos_x = src->pos_x;
    dst->pos_y = src->pos_y;
    dst->priority = src->priority;
    dst->cg_number = src->cg_number;
    dst->v8 = src->v8;
    dst->v9 = src->v9;
    dst->used = 1;
    dst->cg_ctr = src->cg_ctr;
    dst->col_mode = src->col_mode;
    dst->col_code = src->col_code;
    dst->olc_ix = src->olc_ix;
    dst->rl_flag = src->rl_flag;
    dst->cg_flip = src->cg_flip;
}



/* provisional name */
void debug_restore_player_snapshot(SNAPSHOT* rec, WORK* wk) {
    wk->xyz[0].disp.pos = rec->pos_x;
    wk->xyz[1].disp.pos = rec->pos_y;
    wk->my_priority = rec->priority;
    wk->cg_number = rec->cg_number;
    wk->my_col_mode = rec->col_mode;
    wk->my_col_code = rec->col_code;
    wk->cg_olc_ix = rec->olc_ix;
    wk->rl_flag = rec->rl_flag;
    wk->cg_flip = rec->cg_flip;
    set_char_olc_data(wk);
}



/* provisional name */
void debug_snapshot_to_ghost(WORK* wk, SNAPSHOT* rec) {
    wk->position_x = rec->pos_x;
    wk->position_y = rec->pos_y;
    wk->my_priority = rec->priority;
    wk->cg_number = rec->cg_number;
    wk->my_col_mode = rec->col_mode;
    wk->my_col_code = rec->col_code;
    wk->cg_olc_ix = rec->olc_ix;
    wk->rl_flag = rec->rl_flag;
    wk->cg_flip = rec->cg_flip;
}



/* provisional name */
s32 debug_hex4_to_bcd(s16 x) {
    s16 digit[4];
    s16* p = digit;
    s16 i;
    s32 n;
    s16 div = 1000;
    for (i = 0; i < 4; i++) {
        n = 0;
        while ((x -= div) >= 0) {
            n++;
        }
        *p++ = n;
        x = x + div;
        div /= 10;
    }
    return (s16)(((digit[0] << 12) & 0xF000) | ((digit[1] << 8) & 0xF00) | ((digit[2] << 4) & 0xF0)
                 | digit[3]);
}



/* provisional name */
s16 debug_cg_bank_kind(u16 code) {
    if (code >= 0xD800) {
        return 2;
    } else if (code >= 0x9000) {
        return 1;
    } else {
        return 0;
    }
}

/* provisional name */
void debug_draw_cg_group(code, n, x, y, attr)
    u16 code;
    s16 n;
    s32 x;
    s32 y;
    s16 attr;
{
    switch (debug_cg_bank_kind(code)) {
    case 0:
        tilemap_print_string_attr(x, y, attr, dbg_bcp_str);
        break;
    case 1:
        tilemap_print_string_attr(x, y, attr, dbg_bce_str);
        break;
    case 2:
        tilemap_print_string_attr(x, y, attr, dbg_bcb_str);
        break;
    }
    n = debug_hex4_to_bcd(n);
    tilemap_print_hex(x + 3, y, attr, n, 2, 0);
}

/* provisional name */
void debug_draw_cg_group_offset(code, ix, x, y, attr)
    u16 code;
    s16 ix;
    s16 x;
    s16 y;
    s16 attr;
{
    s16 base;
    switch (debug_cg_bank_kind(code)) {
    case 0:
        base = bcp_group_top_tbl[ix];
        break;
    case 1:
        base = bce_group_top_tbl[ix];
        break;
    case 2:
        base = bcb_group_top_tbl[ix];
        break;
    }
    tilemap_print_string_attr(x - 1, y, attr, dbg_plus_str);
    base = code - base;
    tilemap_print_hex(x, y, attr, base, 4, 0);
}



/* provisional name */
void debug_draw_object_info(void) {
    volatile s16 num;
    s16 pat;
    num = debug_hex4_to_bcd(dbg_slot[0]);
    tilemap_print_hex(10, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[4]);
    tilemap_print_hex(14, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[1]);
    tilemap_print_hex(10, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[5]);
    tilemap_print_hex(14, 6, 2, num, 3, 0);
    pat = debug_hex4_to_bcd((Debug_Menu_No == 4) ? dbg_slot[2] : dbg_slot[2] + 1);
    tilemap_print_hex(11, 8, 2, pat, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[6]);
    tilemap_print_hex(14, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[3]);
    tilemap_print_hex(11, 9, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[7]);
    tilemap_print_hex(14, 9, 2, num, 2, 0);
    tilemap_print_hex(11, 10, 2, dbg_pl->wu.cg_number, 4, 0);
    switch (Debug_CG_Flip[dbg_pl->wu.id]) {
    case 0:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_hv_str);
        break;
    }
    if (Debug_RL_Flag[dbg_pl->wu.id]) {
        tilemap_print_string_attr(13, 11, 2, dbg_flag_on_str);
    } else {
        tilemap_print_string_attr(13, 11, 2, dbg_flag_off_str);
    }
    switch (dbg_pl->wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_hv_str);
        break;
    }
    if (dbg_pl->wu.rl_flag) {
        tilemap_print_string_attr(13, 12, 2, dbg_flag_on_str);
    } else {
        tilemap_print_string_attr(13, 12, 2, dbg_flag_off_str);
    }
    tilemap_print_hex(11, 13, 2, dbg_pl->wu.position_x, 4, 0);
    tilemap_print_hex(11, 14, 2, dbg_pl->wu.position_y, 4, 0);
    if (dbg_slot[0] <= 216) {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[dbg_slot[8]]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_name_tbl[dbg_slot[8]][dbg_slot[1] - 1]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[dbg_pl->player_number]);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[10]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_name_tbl[10][dbg_slot[0] - 217]);
        tilemap_print_string(0, 0, 0xFFFF, (*(const TM_STRING(*)[])(&dbg_char_name_str[16])));
    }
}



/* provisional name */
void debug_draw_kakusyuku_frame_flags(void) {
    switch (dbg_kakusyuku_mode) {
    case 0:
        tilemap_print_string_attr(1, 16, 2, dbg_kakusyuku_off_str);
        tilemap_print_string_attr(1, 17, 2, dbg_frame_off_str);
        break;
    case 1:
        tilemap_print_string_attr(1, 17, 2, dbg_frame_on_str);
        break;
    case 2:
        tilemap_print_string_attr(1, 16, 2, dbg_kakusyuku_on_str);
        tilemap_print_string_attr(1, 17, 2, dbg_frame_off_str);
        break;
    case 3:
        tilemap_print_string_attr(1, 17, 2, dbg_frame_on_str);
        break;
    }
}



/* provisional name */
void debug_draw_position_delta(void) {
    s16 d;
    s32 bcd;
    d = plw[1].wu.xyz[0].disp.pos;
    d -= plw[0].wu.xyz[0].disp.pos;
    if (d < 0) {
        tilemap_print_string_attr(10, 15, 2, dbg_minus_str);
        d = -d;
    } else {
        tilemap_print_string_attr(10, 15, 2, debug_space_msg);
    }
    if (Debug_Dec_Disp) {
        bcd = debug_hex4_to_bcd(d);
        tilemap_print_hex(11, 15, 2, bcd, 4, 0);
        tilemap_print_string_attr(15, 15, 2, dbg_space2_str);
    } else {
        tilemap_print_hex(11, 15, 2, d, 4, 0);
        tilemap_print_string_attr(15, 15, 2, dbg_hex_mark_str);
    }
    d = plw[1].wu.xyz[1].disp.pos;
    d -= plw[0].wu.xyz[1].disp.pos;
    if (d < 0) {
        tilemap_print_string_attr(10, 16, 2, dbg_minus_str);
        d = -d;
    } else {
        tilemap_print_string_attr(10, 16, 2, debug_space_msg);
    }
    if (Debug_Dec_Disp) {
        bcd = debug_hex4_to_bcd(d);
        tilemap_print_hex(11, 16, 2, bcd, 4, 0);
        tilemap_print_string_attr(15, 16, 2, dbg_space2_str);
    } else {
        tilemap_print_hex(11, 16, 2, d, 4, 0);
        tilemap_print_string_attr(15, 16, 2, dbg_hex_mark_str);
    }
}

/* provisional name */
void debug_draw_edit_side(void) {
    if (Debug_PL_id) {
        tilemap_print_string_attr(11, 17, 2, dbg_2p_str);
    } else {
        tilemap_print_string_attr(11, 17, 2, dbg_1p_str);
    }
}

/* provisional name */
void debug_draw_hit_edit_info(void)
{
    const char *str;
    u16 attr;
    s16 i;
    s16 num;
    HIT_IX *hit;

    tilemap_rect_fill(dbg_hud_x + 40, ((WORK_Other_JUDGE *)dbg_judge_ewk)->curr_ja + 12, 8, 1, 14, 0xFFFF);
    if (!Debug_Box_Edit) {
        attr = 14;
        str = dbg_free_str;
    } else {
        attr = 6;
        str = dbg_hold_str;
    }
    tilemap_print_string_attr(dbg_hud_x + 40, 8, attr, str);
    if (!dbg_copy_done) {
        tilemap_print_string_attr(dbg_hud_x + 40, 9, 14, dbg_copy_str);
    } else {
        attr = (dbg_copy_pat == dbg_slot[2] && dbg_pl->wu.char_index == dbg_copy_char) ? 6 : 14;
        tilemap_print_string_attr(dbg_hud_x + 40, 9, attr, dbg_copy_str);
    }
    str = dbg_define_str;
    if (((WORK_Other_JUDGE *)dbg_judge_ewk)->look_up_flag) {
        str = dbg_user_str;
    }
    tilemap_print_string_attr(dbg_hud_x + 40, 10, 2, str);

    /* the four edit-box values, signed */
    for (i = 0; i < 4; i++) {
        num = dbg_edit_box[i];
        if (num < 0) {
            tilemap_print_string_attr(10, i + 15, 2, dbg_minus_str);
            num = -num;
        } else {
            tilemap_print_string_attr(10, i + 15, 2, debug_space_msg);
        }
        tilemap_print_hex(11, i + 15, 2, num, 4, 0);
    }

    /* hit-index row of the current pattern */
    num = Convert_BCD((u16)dbg_edit_buf.rec[dbg_slot[2]].box, 3);
    tilemap_print_hex(4, 20, 2, num, 3, 0);
    hit = &dbg_pl->wu.hit_ix_table[(u16)dbg_edit_buf.rec[dbg_slot[2]].box];
    tilemap_print_hex(12, 20, 2, Convert_BCD(hit->boix, 3), 3, 0);
    tilemap_print_hex(12, 21, 2, Convert_BCD(hit->bhix, 3), 3, 0);
    tilemap_print_hex(12, 22, 2, Convert_BCD(hit->haix, 3), 3, 0);
    tilemap_print_hex(12, 23, 2, Convert_BCD(hit->caix, 3), 3, 0);
    tilemap_print_hex(12, 24, 2, Convert_BCD(hit->cuix, 3), 3, 0);
    tilemap_print_hex(12, 25, 2, Convert_BCD(hit->atix, 3), 3, 0);
    tilemap_print_hex(12, 26, 2, Convert_BCD(hit->hoix, 3), 3, 0);
    tilemap_print_string_attr(2, 24, 2, hit_kind_tbl[hit->mf.half.bx].name);
    tilemap_print_string_attr(5, 24, 2, hit_kind_tbl[hit->mf.half.mv].name);

    str = dbg_1p_str;
    if (Debug_PL_id != 0) {
        str = dbg_2p_str;
    }
    tilemap_print_string_attr(dbg_hud_x + 5, 21, 2, str);
}



/* provisional name */
void debug_draw_cm_summary(void) {
    volatile s16 num;
    tilemap_print_string_attr(5, 25, 10, dbg_lp_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.code);
    tilemap_print_hex(8, 25, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmlp_str[dbg_pl->wu.cmlp.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.ix);
    tilemap_print_hex(15, 25, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.pat);
    tilemap_print_string_attr(19, 25, 10, dbg_nix_str);
    tilemap_print_hex(22, 25, 10, num, 2, 0);
    tilemap_print_string_attr(5, 26, 10, dbg_l2_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.code);
    tilemap_print_hex(8, 26, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cml2_str[dbg_pl->wu.cml2.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.ix);
    tilemap_print_hex(15, 26, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.pat);
    tilemap_print_string_attr(19, 26, 10, dbg_nix_str);
    tilemap_print_hex(22, 26, 10, num, 2, 0);
    tilemap_print_string_attr(5, 27, 10, dbg_sw_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.code);
    tilemap_print_hex(8, 27, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmsw_str[dbg_pl->wu.cmsw.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.ix);
    tilemap_print_hex(15, 27, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.pat);
    tilemap_print_string_attr(19, 27, 10, dbg_nix_str);
    tilemap_print_hex(22, 27, 10, num, 2, 0);
    tilemap_print_string_attr(25, 25, 10, dbg_ja_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.code);
    tilemap_print_hex(28, 25, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmja_str[dbg_pl->wu.cmja.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.ix);
    tilemap_print_hex(35, 25, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.pat);
    tilemap_print_string_attr(39, 25, 10, dbg_nix_str);
    tilemap_print_hex(42, 25, 10, num, 2, 0);
    tilemap_print_string_attr(25, 26, 10, dbg_j2_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.code);
    tilemap_print_hex(28, 26, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmja_str[dbg_pl->wu.cmj2.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.ix);
    tilemap_print_hex(35, 26, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.pat);
    tilemap_print_string_attr(39, 26, 10, dbg_nix_str);
    tilemap_print_hex(42, 26, 10, num, 2, 0);
    tilemap_print_string_attr(25, 27, 10, dbg_oa_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.code);
    tilemap_print_hex(28, 27, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmoa_str[dbg_pl->wu.cmoa.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.ix);
    tilemap_print_hex(35, 27, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.pat);
    tilemap_print_string_attr(39, 27, 10, dbg_nix_str);
    tilemap_print_hex(42, 27, 10, num, 2, 0);
}

/* provisional name */
void debug_draw_cm_data(void)
{
    /* kind-of-command names: the table that follows the nine dbg_koc_cmoa_str entries */
    const TM_STRING *koc_str = &dbg_koc_cmoa_str[9];
    s16 bcd;
    u16 attr = 0xFFFF;

    tilemap_print_string(dbg_hud_x, 0, attr, &koc_str[dbg_pl->wu.cmoa.koc]);
    tilemap_print_string(dbg_hud_x, 1, attr, &koc_str[dbg_pl->wu.cmsw.koc]);
    tilemap_print_string(dbg_hud_x, 2, attr, &koc_str[dbg_pl->wu.cmlp.koc]);
    tilemap_print_string(dbg_hud_x, 3, attr, &koc_str[dbg_pl->wu.cml2.koc]);
    tilemap_print_string(dbg_hud_x, 4, attr, &koc_str[dbg_pl->wu.cmja.koc]);
    tilemap_print_string(dbg_hud_x, 5, attr, &koc_str[dbg_pl->wu.cmj2.koc]);
    tilemap_print_string(dbg_hud_x, 6, attr, &koc_str[dbg_pl->wu.cmj3.koc]);
    tilemap_print_string(dbg_hud_x, 7, attr, &koc_str[dbg_pl->wu.cmj4.koc]);
    tilemap_print_string(dbg_hud_x, 8, attr, &koc_str[dbg_pl->wu.cmms.koc]);
    tilemap_print_hex(dbg_hud_x + 32, 11, 10, dbg_pl->wu.cmmd.koc, 2, 0);
    tilemap_print_hex(dbg_hud_x + 32, 12, 10, dbg_pl->wu.cmyd.koc, 2, 0);
    tilemap_print_string(dbg_hud_x, 11, attr, &koc_str[dbg_pl->wu.cmcf.koc]);
    tilemap_print_string(dbg_hud_x, 12, attr, &koc_str[dbg_pl->wu.cmcr.koc]);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmoa.ix);
    tilemap_print_hex(dbg_hud_x + 35, 2, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmoa.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 2, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 2, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmsw.ix);
    tilemap_print_hex(dbg_hud_x + 35, 3, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmsw.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 3, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 3, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmlp.ix);
    tilemap_print_hex(dbg_hud_x + 35, 4, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmlp.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 4, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 4, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cml2.ix);
    tilemap_print_hex(dbg_hud_x + 35, 5, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cml2.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 5, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 5, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmja.ix);
    tilemap_print_hex(dbg_hud_x + 35, 6, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmja.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 6, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 6, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj2.ix);
    tilemap_print_hex(dbg_hud_x + 35, 7, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj2.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 7, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 7, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj3.ix);
    tilemap_print_hex(dbg_hud_x + 35, 8, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj3.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 8, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 8, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj4.ix);
    tilemap_print_hex(dbg_hud_x + 35, 9, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj4.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 9, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 9, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmms.ix);
    tilemap_print_hex(dbg_hud_x + 35, 10, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmms.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 10, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 10, 10, bcd, 2, 0);
    tilemap_print_hex(dbg_hud_x + 35, 11, 10, dbg_pl->wu.cmmd.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 11, 10, dbg_pl->wu.cmmd.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 12, 10, dbg_pl->wu.cmyd.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 12, 10, dbg_pl->wu.cmyd.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 13, 10, dbg_pl->wu.cmcf.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 13, 10, dbg_pl->wu.cmcf.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 14, 10, dbg_pl->wu.cmcr.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 14, 10, dbg_pl->wu.cmcr.pat, 3, 0);
}



/* provisional name */
void debug_draw_delta_and_side(void)
{
  debug_draw_position_delta();
  debug_draw_edit_side();
  return;
}



/* provisional name */
void debug_draw_record_info(void) {
    s16 bcd;
    debug_draw_position_delta();
    debug_draw_edit_side();
    bcd = ((s16)debug_hex4_to_bcd(Debug_Rec_Count));
    tilemap_print_hex(11, 19, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(Debug_Rec_Frame));
    tilemap_print_hex(11, 18, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(dbg_snap_ptr->used));
    tilemap_print_hex(11, 20, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(dbg_snap_ptr->cg_ctr));
    tilemap_print_hex(11, 21, 2, bcd, 4, 0);
    switch (dbg_save_mode) {
    case 0:
        tilemap_print_string_attr(1, 23, 6, dbg_over_write_str);
        break;
    case 1:
        tilemap_print_string_attr(1, 23, 6, dbg_insert_str);
        break;
    case 2:
        tilemap_print_string_attr(1, 23, 6, dbg_addition_str);
        break;
    }
}

/* provisional name */
void debug_draw_parts_info(void)
{
    const char *str;
    s16 num;

    num = debug_hex4_to_bcd(dbg_slot[0]);
    tilemap_print_hex(10, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[4]);
    tilemap_print_hex(14, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[1]);
    tilemap_print_hex(10, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[5]);
    tilemap_print_hex(14, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot[2] + 1);
    tilemap_print_hex(11, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[6]);
    tilemap_print_hex(14, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[3]);
    tilemap_print_hex(11, 9, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot[7]);
    tilemap_print_hex(14, 9, 2, num, 2, 0);
    tilemap_print_hex(11, 10, 2, dbg_pl->wu.cg_number, 4, 0);

    switch (Debug_CG_Flip[dbg_pl->wu.id]) {
    case 0:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_hv_str);
        break;
    }
    str = dbg_flag_off_str;
    if (Debug_RL_Flag[dbg_pl->wu.id]) {
        str = dbg_flag_on_str;
    }
    tilemap_print_string_attr(13, 11, 2, str);

    switch (dbg_pl->wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_hv_str);
        break;
    }
    str = dbg_flag_off_str;
    if (dbg_pl->wu.rl_flag) {
        str = dbg_flag_on_str;
    }
    tilemap_print_string_attr(13, 12, 2, str);

    if (dbg_slot[0] > 216) {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[10]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_name_tbl[10][dbg_slot[0] - 217]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[26]);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[dbg_slot[8]]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_name_tbl[dbg_slot[8]][dbg_slot[1] - 1]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[dbg_pl->player_number]);
    }

    str = dbg_1p_str;
    if (Debug_PL_id) {
        str = dbg_2p_str;
    }
    tilemap_print_string_attr(11, 13, 2, str);

    /* the selected part */
    num = dbg_parts_plw[dbg_parts_sel].wu.dir_step;
    if (num < 0) {
        tilemap_print_string_attr(10, 14, 10, dbg_minus_str);
        num = -num;
    } else {
        tilemap_print_string_attr(10, 14, 10, debug_space_msg);
    }
    tilemap_print_hex(11, 14, 2, num, 4, 0);
    num = dbg_parts_plw[dbg_parts_sel].wu.dir_timer;
    if (num < 0) {
        tilemap_print_string_attr(10, 15, 10, dbg_minus_str);
        num = -num;
    } else {
        tilemap_print_string_attr(10, 15, 10, debug_space_msg);
    }
    tilemap_print_hex(11, 15, 2, num, 4, 0);
    switch (dbg_parts_plw[dbg_parts_sel].wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_hv_str);
        break;
    }

    str = dbg_nothing_str;
    switch (dbg_parts_sel) {
    case 0:
        tilemap_print_string_attr(1, 23, 6, dbg_parts1_str);
        if (dbg_parts_olc_ix[0]) {
            str = dbg_blank8_str;
        }
        tilemap_print_string_attr(8, 23, 6, str);
        break;
    case 1:
        tilemap_print_string_attr(1, 23, 6, dbg_parts2_str);
        if (dbg_parts_olc_ix[1]) {
            str = dbg_blank8_str;
        }
        tilemap_print_string_attr(8, 23, 6, str);
        break;
    case 2:
        tilemap_print_string_attr(1, 23, 6, dbg_parts3_str);
        if (dbg_parts_olc_ix[2]) {
            str = dbg_blank8_str;
        }
        tilemap_print_string_attr(8, 23, 6, str);
        break;
    case 3:
        tilemap_print_string_attr(1, 23, 6, dbg_parts4_str);
        if (dbg_parts_olc_ix[3]) {
            str = dbg_blank8_str;
        }
        tilemap_print_string_attr(8, 23, 6, str);
        break;
    }

    num = debug_hex4_to_bcd(dbg_parts_plw[0].wu.cg_olc_ix);
    tilemap_print_hex(11, 17, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[0].wu.cg_olc.olc_ix[0]);
    tilemap_print_hex(11, 18, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[1].wu.cg_olc.olc_ix[1]);
    tilemap_print_hex(11, 19, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[2].wu.cg_olc.olc_ix[2]);
    tilemap_print_hex(11, 20, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[3].wu.cg_olc.olc_ix[3]);
    tilemap_print_hex(11, 21, 2, num, 4, 0);
}



/* provisional name */
void debug_char_init(void) {
    s16 x = Game_setting.mode ? 32 : 0;
    dbg_pl->wu.be_flag = 1;
    dbg_pl->wu.disp_flag = 1;
    dbg_pl->wu.cgromtype = 1;
    dbg_pl->wu.my_family = 1;
    dbg_pl->wu.my_col_mode = 0x4200;
    dbg_pl->wu.work_id = 1;
    if (dbg_pl->wu.id != 0) {
        x += 0x270;
        dbg_pl->wu.xyz[0].disp.pos = x;
        dbg_pl->wu.position_x = x;
        dbg_pl->wu.my_priority = 64;
        dbg_pl->wu.target_adrs = (u32*)&plw[0];
    } else {
        x += 0x200;
        dbg_pl->wu.xyz[0].disp.pos = x;
        dbg_pl->wu.position_x = x;
        dbg_pl->wu.my_priority = 62;
        dbg_pl->wu.target_adrs = (u32*)&plw[1];
    }
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos = 0;
    dbg_pl->wu.xyz[2].disp.pos = dbg_pl->wu.my_priority;
    dbg_pl->wu.xyz[0].disp.low = 0;
    dbg_pl->wu.xyz[2].disp.low = dbg_pl->wu.xyz[1].disp.low = 0;
    dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
    debug_char_table_load();
    set_char_base_data_init(&dbg_pl->wu);
    set_char_move_init(&dbg_pl->wu, dbg_slot[8], dbg_slot[1] - 1);
    dbg_pl->wu.rl_flag = 0;
    Debug_RL_Flag[dbg_pl->wu.id] = 0;
    dbg_pl->wu.cg_flip = Debug_Flip_Work[dbg_pl->wu.id] = 0;
    Debug_Flip_Mask[dbg_pl->wu.id] = Debug_CG_Flip[dbg_pl->wu.id] = 0;
    dbg_pl->wu.my_col_code = (dbg_pl->wu.id != 0) ? 0x2010 : 0x2000;
}



/* provisional name */
void debug_p1_reset(void) {
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    dbg_pl->wu.id = 0;
    debug_char_init();
}



/* provisional name */
void debug_both_players_reset(void) {
    dbg_pl = &plw[0];
    dbg_slot = dbg_slot_w[0];
    dbg_pl->wu.id = 0;
    debug_char_init();
    dbg_pl->wu.id = 0;
    dbg_pl = &plw[1];
    dbg_pl->wu.id = 1;
    debug_char_init();
    dbg_pl->wu.id = 1;
}



/* provisional name */
s32 debug_menu_exit_check(void) {
    if ((dbg_p1sw_0 & 0x1000) && (dbg_p2sw_0 & 0x1000)) {
        if (Debug_Menu_No >= 7) {
            Debug_R_No = 0;
        } else {
            Debug_R_No = 2;
        }
        Debug_Select_No = 0;
        Debug_Tool_No = 0;
        Scr_all_clear_Wait();
        dbg_hud_mode = 0;
        tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_str);
        return 1;
    }
    return 0;
}

/* provisional name */
void debug_bg_stage_load(void)
{
    s16 i;

    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();

    switch (dbg_stage_sel) {
    case 0:
        debug_bg_alloc_scene_init();
        bg_w.scno = 3;
        break;

    case 1:
        debug_bg_alloc_init();
        bg_w.scno = 3;
        break;

    case 21:
        scr_cg_c_no = simmram_block_alloc_10(31, 1);
        bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
        load_any_color(0x16);
        load_any_color(0x17);
        polygon2d_submit_line(0x020B0000, 0, 0, 3);
        polygon2d_submit_line(0x020B0080, bg_w.scroll_cg_adr, 0x1E5F, 1);
        if (Game_setting.mode) {
            bg_w.pos_offset = 248;
        } else {
            bg_w.pos_offset = 192;
        }
        for (i = 0; i < 7; i++) {
            bg_w.bgw[i].pos_y_work = 512;
            bg_w.bgw[i].pos_x_work = 512;
            bg_w.bgw[i].zuubun = 0;
            bg_w.bgw[i].xy[0].cal = WORK_RAM;        /* pos 512, low 0 */
            bg_w.bgw[i].xy[1].cal = 0;
            bg_w.bgw[i].wxy[0].cal = WORK_RAM;
            bg_w.bgw[i].wxy[1].cal = 0;
            bg_w.bgw[i].hos_xy[0].cal = 0;
            bg_w.bgw[i].hos_xy[1].cal = 0;
            bg_w.bgw[i].speed_x = 0;
            bg_w.bgw[i].speed_y = 0;
            bg_w.bgw[i].rewrite_flag = 0;
            bg_w.bgw[i].fam_no = i;
            bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
            bg_w.bgw[i].speed_x = 0;
        }
        bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[0].bg_address = (u16 *)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
        scrn_map_set_now(0, bg_w.bgw[0].bg_address);
        scrn_map_set(0, bg_w.bgw[0].bg_address);
        sprite_list_setup(0, 1, bg_scr_record_data);
        bg_cell_write(0, 0x2000, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x2040, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x2080, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x20C0, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3000, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3040, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3080, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x30C0, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_zoom_x_pos = 192;
        scroll_layer_mask_enable(1);
        scroll_layer_mask_disable(16);
        scrn_attr_set(0, 0, 24);
        scrn_reg_w[0].ctrl &= 0xFE7F;
        bg_w.bgw[0].speed_x = 0x10000;
        bg_w.bgw[0].speed_y = 0x10000;
        bg_w.bgw[0].rewrite_flag = 0;
        bg_w.bgw[0].pos_y_work = 0;
        bg_w.bgw[0].xy[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos = 0;
        base_y_pos = 40;
        bg_pos_hosei2();
        Bg_Family_Set();
        break;

    default:
        bg_initialize();
        if (bg_w.stage == 10) {
            bg_cell_write(0, 0x2000, 0x11, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x2040, 0x12, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x2080, 0x13, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x20C0, 0x14, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3000, 0x15, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3040, 0x16, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3080, 0x17, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x30C0, 0x18, (u32)eff23_scrn_data, 0, 0x280);
        }
        break;
    }

    if (!Game_setting.mode) {
        bg_w.pos_offset = 192;
    } else {
        bg_w.pos_offset = 248;
    }
    for (i = 0; i < 3; i++) {
        bg_w.bgw[i].xy[0].disp.pos = 512;
        bg_w.bgw[i].xy[1].disp.pos = 0;
        bg_w.bgw[i].wxy[0].disp.pos = 512;
        bg_w.bgw[i].wxy[1].disp.pos = 0;
        bg_w.bgw[i].xy[0].disp.low = 0;
        bg_w.bgw[i].xy[1].disp.low = 0;
        bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].wxy[1].disp.low = 0;
        bg_w.bgw[i].position_x = 512;
        bg_w.bgw[i].position_y = 0;
    }
    if (bg_w.stage == 8) {
        base_y_pos = 48;
    } else {
        base_y_pos = 40;
    }
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
s32 debug_cg_group_index(code)
    u16 code;
{
    u16 i;
    if (code >= 0xD800) {
        for (i = 0; i < 47; i++) {
            if (code < bcb_group_top_tbl[i + 1]) {
                break;
            }
        }
    } else if (code >= 0x9000) {
        for (i = 0; i < 58; i++) {
            if (code < bce_group_top_tbl[i + 1]) {
                break;
            }
        }
    } else {
        for (i = 0; i < 24; i++) {
            if (code < bcp_group_top_tbl[i + 1]) {
                i = bcp_group_no_tbl[i];
                break;
            }
        }
    }
    return i;
}

/* provisional name */
void debug_draw_att_data(void)
{
    s16 bcd;

    if (plw[0].wu.meoshi_hit_flag == 1) {
        tilemap_print_string_attr(dbg_hud_x + 36, 2, 14, debug_space_msg);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 36, 2, 10, dbg_minus_str);
    }
    bcd = debug_hex4_to_bcd(plw[0].wu.cg_att_ix);
    tilemap_print_hex(dbg_hud_x + 37, 2, 10, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 3, 10, plw[0].wu.att.reaction, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.reaction);
    tilemap_print_hex(dbg_hud_x + 42, 3, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 4, 10, plw[0].wu.att.mkh_ix, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.mkh_ix);
    tilemap_print_hex(dbg_hud_x + 42, 4, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 5, 10, plw[0].wu.att.dipsw, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dipsw);
    tilemap_print_hex(dbg_hud_x + 42, 5, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.att.dir, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dir);
    tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.att.dir, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dir);
    tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 8, 10, plw[0].wu.att.guard, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.guard);
    tilemap_print_hex(dbg_hud_x + 42, 8, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 9, 10, plw[0].wu.att.pow, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.pow);
    tilemap_print_hex(dbg_hud_x + 42, 9, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 10, 10, plw[0].wu.att.impact, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.impact);
    tilemap_print_hex(dbg_hud_x + 42, 10, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 11, 10, plw[0].wu.att.piyo, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.piyo);
    tilemap_print_hex(dbg_hud_x + 42, 11, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 12, 10, plw[0].wu.att.ng_type, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.ng_type);
    tilemap_print_hex(dbg_hud_x + 42, 12, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 13, 10, plw[0].wu.att.hs_me, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.hs_me);
    tilemap_print_hex(dbg_hud_x + 42, 13, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 14, 10, plw[0].wu.att.hs_you, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.hs_you);
    tilemap_print_hex(dbg_hud_x + 42, 14, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 15, 10, plw[0].wu.zu_flag, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.zu_flag);
    tilemap_print_hex(dbg_hud_x + 42, 15, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 16, 10, plw[0].wu.at_attribute, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.at_attribute);
    tilemap_print_hex(dbg_hud_x + 42, 16, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 17, 10, plw[0].wu.att.level, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.level);
    tilemap_print_hex(dbg_hud_x + 42, 17, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 18, 10, plw[0].wu.add_arts_point, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.add_arts_point);
    tilemap_print_hex(dbg_hud_x + 42, 18, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 19, 10, plw[0].wu.att.but_ix, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.but_ix);
    tilemap_print_hex(dbg_hud_x + 42, 19, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 21, 10, plw[0].wu.dir_atthit, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.dir_atthit);
    tilemap_print_hex(dbg_hud_x + 42, 21, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 22, 10, plw[0].wu.vs_id, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.vs_id);
    tilemap_print_hex(dbg_hud_x + 42, 22, 2, bcd, 4, 0);
}



/* provisional name */
void debug_draw_cg_data(void) {
    const TM_STRING* off;
    const TM_STRING* on;
    s16 bcd;
    s16 n;
    s16 i;
    s16 bit;
    s32 group;
    if (dbg_old_cgd_type != plw[0].wu.cgd_type) {
        switch (plw[0].wu.cgd_type) {
        case 2:
            tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_mid_str);
        case 4:
            tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_low_str);
            break;
        }
    }
    switch (plw[0].wu.cgd_type) {
    case 6:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_rival_str);
        tilemap_print_hex(dbg_hud_x + 37, 16, 10, plw[0].wu.cg_rival, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_rival);
        tilemap_print_hex(dbg_hud_x + 42, 16, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 17, 10, plw[0].wu.cg_add_xy, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_add_xy);
        tilemap_print_hex(dbg_hud_x + 42, 17, 2, bcd, 4, 0);
        tilemap_print_string_attr(dbg_hud_x + 37, 18, 10, dbg_nix_str);
        tilemap_print_hex(dbg_hud_x + 40, 18, 10, plw[0].wu.cg_next_ix, 2, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_status);
        tilemap_print_hex(dbg_hud_x + 37, 19, 10, bcd, 4, 0);
    case 4:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_att_str);
        if (plw[0].wu.cg_att_ix < 0) {
            tilemap_print_string_attr(dbg_hud_x + 37, 14, 2, dbg_minus_str);
            n = -plw[0].wu.cg_att_ix;
            tilemap_print_string_attr(dbg_hud_x + 42, 14, 2, dbg_minus_str);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 14, 2, debug_space_msg);
            tilemap_print_string_attr(dbg_hud_x + 42, 14, 2, debug_space_msg);
            n = plw[0].wu.cg_att_ix;
        }
        tilemap_print_hex(dbg_hud_x + 38, 10, 10, plw[0].wu.cg_att_ix, 3, 0);
        bcd = debug_hex4_to_bcd(n);
        tilemap_print_hex(dbg_hud_x + 43, 10, 2, bcd, 3, 0);
        tilemap_print_hex(dbg_hud_x + 37, 11, 10, plw[0].wu.cg_hit_ix, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_hit_ix);
        tilemap_print_hex(dbg_hud_x + 42, 11, 2, bcd, 4, 0);
        if (plw[0].wu.cg_extdat) {
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_extdat_str[(s16)(plw[0].wu.cg_extdat & 0xC0) >> 6]);
            bcd = debug_hex4_to_bcd(plw[0].wu.cg_extdat & 0x3F);
            tilemap_print_hex(dbg_hud_x + 39, 12, 10, bcd, 2, 0);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 12, 10, dbg_no_extdat_str);
        }
        bit = 1;
        off = dbg_cancel_off_str;
        on = dbg_cancel_on_str;
        for (i = 0; i < 8; i++) {
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, (plw[0].wu.cg_cancel & bit) ? on : off);
            bit = bit << 1;
            off++;
            on++;
        }
        if (plw[0].wu.cg_cancel & 8) {
            n = plw[0].wu.cg_eftype & 15;
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, (n > 8) ? &dbg_eftype_names[8] : &dbg_eftype_names[n]);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_s_str[(s16)((plw[0].wu.cg_eftype >> 8) & 7)]);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF,
                                 (plw[0].wu.cg_eftype & 0x80) ? &dbg_eftype_usemj_str[1] : &dbg_eftype_usemj_str[0]);
        } else if (plw[0].wu.cg_eftype) {
            tilemap_print_string_attr(dbg_hud_x + 37, 15, 10, dbg_eftype_str);
            bcd = debug_hex4_to_bcd(plw[0].wu.cg_eftype);
            tilemap_print_hex(dbg_hud_x + 40, 15, 10, bcd, 2, 0);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 15, 10, debug_blank6_msg);
        }
        tilemap_print_hex(dbg_hud_x + 37, 14, 10, plw[0].wu.cg_effect, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_effect);
        tilemap_print_hex(dbg_hud_x + 42, 14, 2, bcd, 4, 0);
    case 2:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_cgd_type_str[plw[0].wu.cgd_type / 2]);
        tilemap_print_hex(dbg_hud_x + 37, 3, 10, plw[0].wu.cg_ctr, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_ctr);
        tilemap_print_hex(dbg_hud_x + 42, 3, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 4, 10, plw[0].wu.cg_type, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_type);
        tilemap_print_hex(dbg_hud_x + 42, 4, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 5, 10, (s16)plw[0].wu.cg_se, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_se);
        tilemap_print_hex(dbg_hud_x + 42, 5, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.cg_flip, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_flip);
        tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.cg_olc_ix, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_olc_ix);
        tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
        group = debug_cg_group_index((s16)dbg_pl->wu.cg_number);
        debug_draw_cg_group((s16)plw[0].wu.cg_number, group, dbg_hud_x + 37, 8, 2);
        debug_draw_cg_group_offset((s16)plw[0].wu.cg_number, group, dbg_hud_x + 43, 8, 2);
        break;
    }
}



/* provisional name */
void debug_draw_cgd_info(void) {
    s16 bcd;
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_pat_status_str[plw[0].wu.pat_status / 2]);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_cgd_type_str[plw[0].wu.cgd_type / 2]);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_waza_kind_str[(s16)plw[0].wu.kind_of_waza >> 4]);
    tilemap_print_string_attr(dbg_hud_x + 40, 4, 10,
                              (plw[0].wu.kind_of_waza & 1) ? dbg_waza_k_str : dbg_waza_p_str);
    if (plw[0].wu.kind_of_waza & 2) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit0_str);
    }
    if (plw[0].wu.kind_of_waza & 4) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit1_str);
    }
    if (plw[0].wu.kind_of_waza & 6) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit2_str);
    }
    tilemap_print_hex(dbg_hud_x + 37, 5, 10, plw[0].wu.hit_range, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.total_paring, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.total_paring);
    tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.total_att_set, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.total_att_set);
    tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 8, 10, plw[0].wu.sp_tech_id, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.sp_tech_id);
    tilemap_print_hex(dbg_hud_x + 42, 8, 2, bcd, 4, 0);
    if (plw[0].wu.cg_wca_ix) {
        tilemap_print_string_attr(dbg_hud_x + 37, 9, 10, dbg_wca_str);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_wca_ix);
        tilemap_print_hex(dbg_hud_x + 40, 9, 10, bcd, 2, 0);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 37, 9, 10, debug_blank6_msg);
    }
}



/* provisional name */
void debug_hud_mode_dispatch(void) {
    u16 trg = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (trg & 0x1000) {
        dbg_hud_mode++;
        if (dbg_hud_mode > 4) {
            dbg_hud_mode = 0;
        }
        switch (dbg_hud_mode) {
        case 0:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            break;
        case 1:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_head_str);
            break;
        case 2:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            switch (plw[0].wu.cgd_type) {
            case 6:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_low_str);
            case 4:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_mid_str);
            case 2:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
                break;
            }
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_att_data_str);
            break;
        case 3:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cm_label_str);
            break;
        case 4:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cgd_info_str);
            break;
        }
    }
    switch (dbg_hud_mode) {
    case 1:
        debug_draw_cg_data();
        break;
    case 2:
        debug_draw_att_data();
        break;
    case 3:
        debug_draw_cm_data();
        break;
    case 4:
        debug_draw_cgd_info();
        break;
    }
}



/* provisional name */
s16 debug_catch_move_record(SNAPSHOT* p1, SNAPSHOT* p2) {
    PLW* a = &plw[0];
    PLW* d = &plw[1];
    SNAPSHOT* s1;
    SNAPSHOT* s2;
    CatchTable* rca;
    EDIT_SLOTS* e = &dbg_slot_w;
    s32 n;
    if (a->wu.now_koc != 2) {
        return 0;
    }
    a->tsukami_num = d->player_number;
    set_char_move_init(&a->wu, 2, e->slot[1] - 1);
    set_char_move_init(&d->wu, 3, a->wu.cmyd.ix);
    if (a->wu.cmyd.pat == 0) {
        return 0;
    }
    Debug_CG_Flip[0] = a->wu.cg_flip;
    Debug_Flip_Mask[0] = 0;
    Debug_RL_Flag[0] = a->wu.rl_flag;
    Debug_CG_Flip[1] = d->wu.cg_flip;
    Debug_Flip_Mask[1] = 0;
    Debug_RL_Flag[1] = d->wu.rl_flag;
    Debug_Rec_Count = 0;
    ixbfw_cut = 1;
    if (p1sw_0 & 0x200) {
        ixbfw_cut += 4;
    }
    if (a->wu.cmyd.pat == 1) {
        do {
            Debug_Rec_Count++;
            n = Debug_Rec_Count;
            n *= sizeof(SNAPSHOT);
            s1 = (SNAPSHOT*)((u8*)p1 + n);
            s2 = (SNAPSHOT*)((u8*)p2 + n);
            if (a->wu.cg_rival) {
                rca = a->wu.curr_rca;
                char_move_index(&d->wu, rca->catch_nix);
                d->wu.rl_flag = a->wu.rl_flag ^ a->wu.curr_rca->catch_flip;
                if (a->wu.rl_flag) {
                    d->wu.xyz[0].disp.pos = a->wu.xyz[0].disp.pos - a->wu.curr_rca->catch_hos_x;
                } else {
                    d->wu.xyz[0].disp.pos = a->wu.xyz[0].disp.pos + a->wu.curr_rca->catch_hos_x;
                }
                d->wu.xyz[1].disp.pos = a->wu.curr_rca->catch_hos_y + a->wu.xyz[1].disp.pos;
                if (a->wu.curr_rca->catch_prio == 2) {
                    d->wu.next_z = a->wu.xyz[2].disp.pos - 1;
                } else {
                    d->wu.next_z = a->wu.xyz[2].disp.pos + 1;
                }
            }
            debug_move_snapshot_frame(s1, &a->wu, a->wu.xyz[2].disp.pos);
            debug_move_snapshot_frame(s2, &d->wu, d->wu.next_z);
            char_move_z(&a->wu);
            Debug_CG_Flip[0] = a->wu.cg_flip;
            Debug_Flip_Mask[0] = 0;
            Debug_RL_Flag[0] = a->wu.rl_flag;
        } while (a->wu.cg_type != 0xFF && (!(((s8)ixbfw_cut) & 4) || a->wu.cg_rival));
    } else {
        do {
            Debug_Rec_Count++;
            n = Debug_Rec_Count;
            n *= sizeof(SNAPSHOT);
            s1 = (SNAPSHOT*)((u8*)p1 + n);
            s2 = (SNAPSHOT*)((u8*)p2 + n);
            if (a->wu.cg_rival) {
                rca = a->wu.curr_rca;
                char_move_index(&d->wu, rca->catch_nix);
                d->wu.rl_flag = a->wu.rl_flag ^ a->wu.curr_rca->catch_flip;
                if (a->wu.rl_flag) {
                    a->wu.xyz[0].disp.pos = d->wu.xyz[0].disp.pos + a->wu.curr_rca->catch_hos_x;
                } else {
                    a->wu.xyz[0].disp.pos = d->wu.xyz[0].disp.pos - a->wu.curr_rca->catch_hos_x;
                }
                a->wu.xyz[1].disp.pos = d->wu.xyz[1].disp.pos - a->wu.curr_rca->catch_hos_y;
                if (a->wu.curr_rca->catch_prio == 2) {
                    d->wu.next_z = a->wu.xyz[2].disp.pos - 1;
                } else {
                    d->wu.next_z = a->wu.xyz[2].disp.pos + 1;
                }
            }
            debug_move_snapshot_frame(s1, &a->wu, a->wu.xyz[2].disp.pos);
            debug_move_snapshot_frame(s2, &d->wu, d->wu.next_z);
            char_move_z(&a->wu);
            Debug_CG_Flip[0] = a->wu.cg_flip;
            Debug_Flip_Mask[0] = 0;
            Debug_RL_Flag[0] = a->wu.rl_flag;
        } while (a->wu.cg_type != 0xFF && (!(((s8)ixbfw_cut) & 4) || a->wu.cg_rival));
    }
    ixbfw_cut = 0;
    return 1;
}



/* provisional name */
void debug_move_snapshot_frame(SNAPSHOT* rec, WORK* wk, s16 priority) {
    rec->pos_x = wk->xyz[0].disp.pos;
    rec->pos_y = wk->xyz[1].disp.pos;
    rec->priority = priority;
    rec->cg_number = wk->cg_number;
    rec->v8 = wk->rl_flag;
    rec->v9 = wk->cg_flip;
    rec->used = 1;
    rec->cg_ctr = wk->cg_ctr;
    rec->col_mode = wk->my_col_mode;
    rec->col_code = wk->my_col_code;
    rec->olc_ix = wk->cg_olc_ix;
    rec->rl_flag = wk->rl_flag;
    rec->cg_flip = wk->cg_flip;
}

/* provisional name */
void debug_bg_tile_put(s16 bg, s32 ofs, s32 page, s32 src) {
    u16* dst;
    u16* sp;
    s32 x;
    s32 adr;

    adr = (s32)bg_w.bgw[bg].bg_address;
    ofs += adr;
    dst = (u16*)ofs;
    x = 0;
    x += bg_w.ake_cg_adr >> 7;
    page = (page << 10) + src;
    sp = (u16*)page;
    ((void (*)())blit_16x16_tile)(sp, (u16)x, dst, 0x2C0);
}



/* provisional name */
void debug_bg_alloc_init(void) {
    scr_cg_c_no = ((s16)simmram_block_alloc_10(104, 1));
    bg_w.ake_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    load_any_color(0x8C);
    load_any_color(0x8F);
    polygon2d_submit_line(0x020F0000, 0, 0, 3);
    polygon2d_submit_line(0x020F0080, bg_w.ake_cg_adr, 0x14FF, 1);
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, (s16*)bg_map_tbl[0][0]);
    bg_w.bgw[0].r_no_1 = bg_w.bgw[0].r_no_2 = 0;
    bg_w.bgw[0].fam_no = 0;
    debug_bg_tile_put(0, 0x3000, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x3040, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x3080, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x30C0, 3, (s32)ake_scrn_data);
    scroll_layer_mask_enable(1);
    scroll_layer_mask_disable(16);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
}



/* provisional name */
void debug_bg_alloc_scene_init(void) {
    s32 blocks = ((*(const s32(*)[3])&(bg_gfx_tbl[1]))[1] * 16 + 0xFFF) / 0x1000;
    scr_cg_c_no = ((s16)simmram_block_alloc_10(blocks, 1));
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    load_bg_color(1);
    load_bg_color(16);
    polygon2d_submit_line((*(const s32(*)[3])&(bg_gfx_tbl[1]))[0], 0, 0, 3);
    polygon2d_submit_line((*(const s32(*)[3])&(bg_gfx_tbl[1]))[2], bg_w.scroll_cg_adr, (*(const s32(*)[3])&(bg_gfx_tbl[1]))[1], 1);
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, (s16*)bg_map_tbl[1][0]);
    bg_w.bgw[0].r_no_2 = 0;
    bg_w.bgw[0].fam_no = bg_w.bgw[0].r_no_1 = 0;
    bg_cell_write(0, 0x2000, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x2040, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x2080, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x20C0, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3000, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3040, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3080, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x30C0, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    scroll_layer_mask_enable(1);
    scroll_layer_mask_disable(16);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
}

/* provisional name */
void screen_work_clear_all(void)
{
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
}



void waza_check(PLW* pl) {
    cmd_pl = pl;
    cmd_id = cmd_pl->wu.id;
    chk_pl = &t_pl_lvr[cmd_id];
    sw_pick_up();
    cmd_move();
}



void key_thru(PLW* pl) {
    cmd_pl = pl;
    cmd_id = cmd_pl->wu.id;
    chk_pl = &t_pl_lvr[cmd_id];
    sw_pick_up();
}



void cmd_data_set(PLW* _p0, s16 i) {
    u8* ptr3;
    u16* ptr4;
    wcp[cmd_id].reset[i] = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead2 = *cmd_tbl_ptr++;
    ptr3 = &wcp[cmd_id].waza_r[i][0];
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    wcp[cmd_id].btix[i] = *cmd_tbl_ptr++;
    ptr4 = &wcp[cmd_id].exdt[i][0];
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
}



void cmd_init(PLW* pl) {
    s16 i;
    s16 j;
    s32* ptr;
    cmd_id = pl->wu.id;
    pl->cp = &wcp[cmd_id];
    ptr = (s32*)&waza_work[cmd_id][0];
    for (i = 0; i < 56; i++) {
        for (j = 0; j < 6; j++) {
            *ptr++ = 0;
        }
    }
    for (i = 0; i < 56; i++) {
        wcp[cmd_id].waza_flag[i] = 0;
        for (j = 0; j < 4; j++) {
            wcp[cmd_id].waza_r[i][j] = 0;
        }
    }
    waza_compel_all_init(pl);
}



void cmd_move(void) {
    s32 j;
    intptr_t* adrs;
    cmd_id = cmd_pl->wu.id;
    adrs = pl_CMD[cmd_pl->player_number];
    for (j = 0; j < 56; j++) {
        if (wcp[cmd_id].waza_flag[j] != -1) {
            waza_type[cmd_id] = j;
            cmd_tbl_ptr = (s16*)adrs[j];
            waza_ptr = &waza_work[cmd_id][j];
            chk_move_jp[waza_ptr->w_type]();
        }
    }
    for (j = 0; j < 56; j++) {
        if ((wcp[cmd_id].waza_flag[j] != -1) && (wcp[cmd_id].waza_flag[j] != 0)) {
            waza_ptr = &waza_work[cmd_id][j];
            command_ok_move(j);
        }
    }
}



void check_init(void) {
    cmd_tbl_ptr += 12;
    waza_ptr->w_type = *cmd_tbl_ptr++;
    waza_ptr->w_int = *cmd_tbl_ptr++;
    waza_ptr->free1 = *cmd_tbl_ptr;
    waza_ptr->free2 = *cmd_tbl_ptr++;
    waza_ptr->w_lvr = *cmd_tbl_ptr++;
    waza_ptr->w_ptr = cmd_tbl_ptr;
    waza_ptr->uni0.tame.flag = 0;
    waza_ptr->uni0.tame.shot_flag = 0;
    waza_ptr->uni0.tame.shot_flag2 = 0;
    waza_ptr->shot_ok = 0;
    waza_ptr->free3 = 0;
    chk_move_jp[waza_ptr->w_type]();
}



void check_next(void) {
    s16* next_ptr = waza_ptr->w_ptr;
    waza_ptr->w_type = *next_ptr++;
    waza_ptr->w_int = *next_ptr++;
    waza_ptr->free1 = *next_ptr;
    waza_ptr->free2 = *next_ptr++;
    waza_ptr->w_lvr = *next_ptr++;
    waza_ptr->w_ptr = next_ptr;
    if (waza_ptr->w_type != 10) {
        chk_move_jp[waza_ptr->w_type]();
    }
}



void check_0(void) {
    u16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    sw_lever = chk_pl->sw_lever & 0xF;
    if (dead_lvr_check() == 0) {
        if (waza_ptr->w_lvr & 0x8000) {
            sw_work = waza_ptr->w_lvr & 0xF;
            if (sw_lever == sw_work) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (sw_lever == 0) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if (chk_pl->now_lvbt & 0xF && sw_lever & waza_ptr->w_lvr) {
            if (*waza_ptr->w_ptr == 28) {
                command_ok();
                return;
            }
            check_next();
        }
    }
}



void check_1(void) {
    if (dead_lvr_check() == 0) {
        sw_work = waza_ptr->w_lvr & 0xF;
        if (waza_ptr->w_lvr & 0x8000) {
            if (sw_work == chk_pl->sw_lever) {
                waza_ptr->free2--;
                if (!waza_ptr->uni0.tame.flag && waza_ptr->free2 < 0) {
                    waza_ptr->uni0.tame.flag = 1;
                }
            } else {
                if (waza_ptr->uni0.tame.flag) {
                    waza_ptr->uni0.tame.flag = 0;
                    if (*waza_ptr->w_ptr == 0x1C) {
                        command_ok();
                    } else {
                        check_next();
                    }
                    return;
                }
                waza_ptr->free2 = waza_ptr->free1;
                waza_ptr->w_int--;
                if (waza_ptr->w_int < 0) {
                    waza_ptr->w_type = 0;
                }
            }
        } else {
            if (sw_work & chk_pl->sw_lever) {
                if (!waza_ptr->uni0.tame.flag) {
                    waza_ptr->free1--;
                    if (waza_ptr->free1 < 0) {
                        waza_ptr->uni0.tame.flag = 1;
                    }
                }
            } else {
                if (waza_ptr->uni0.tame.flag) {
                    waza_ptr->uni0.tame.flag = 0;
                    if (*waza_ptr->w_ptr == 0x1C) {
                        command_ok();
                    } else {
                        check_next();
                    }
                    return;
                }
                waza_ptr->free2 = waza_ptr->free1;
                waza_ptr->w_int--;
                if (waza_ptr->w_int < 0) {
                    waza_ptr->w_type = 0;
                }
            }
        }
    }
}



void check_2(void) {
    sw_work = chk_pl->sw_new & waza_ptr->w_lvr;
    if (waza_ptr->w_lvr == sw_work) {
        if (!waza_ptr->uni0.tame.flag) {
            waza_ptr->free2--;
            if (waza_ptr->free2 < 0) {
                waza_ptr->uni0.tame.flag = 1;
            }
        }
    } else {
        if (waza_ptr->uni0.tame.flag && sw_work == 0) {
            waza_ptr->uni0.tame.flag = 0;
            if (*waza_ptr->w_ptr == 28) {
                command_ok();
            } else {
                check_next();
            }
            return;
        }
        waza_ptr->free2 = waza_ptr->free1;
        waza_ptr->w_int--;
        if (waza_ptr->w_int < 0) {
            waza_ptr->w_type = 0;
        }
    }
}



void check_3(void) {
    s16 i;
    s16 w_flag;
    s16* shot_cnt_adrs;
    sw_work = chk_pl->sw_new & 0x770;
    waza_ptr->uni0.tame.shot_flag2 = waza_ptr->uni0.tame.shot_flag;
    waza_ptr->uni0.tame.shot_flag = 0;
    shot_cnt_adrs = &chk_pl->s1_cnt;
    w_flag = 0x10;
    for (i = 0; i < 6; i++) {
        if (*shot_cnt_adrs >= waza_ptr->w_int) {
            waza_ptr->uni0.tame.shot_flag |= w_flag;
        }
        *shot_cnt_adrs++;
        if (chk_pl->shot_down & w_flag) {
            if (waza_ptr->uni0.tame.shot_flag2 & w_flag) {
                waza_ptr->shot_ok++;
            }
        }
        w_flag <<= 1;
    }
    if (waza_ptr->shot_ok) {
        waza_ptr->free2--;
        if (waza_ptr->free2 < 0) {
            waza_ptr->shot_ok = 0;
            waza_ptr->free2 = waza_ptr->free1;
        }
    }
    if (waza_ptr->shot_ok >= waza_ptr->w_lvr) {
        waza_ptr->shot_ok = 0;
        waza_ptr->free2 = waza_ptr->free1;
        if (*waza_ptr->w_ptr == 28) {
            command_ok();
            return;
        }
        check_next();
    }
}



void check_4(void) {
    WORK_CP* cp;
    s16* wtype;
    if (waza_ptr->w_lvr == 0x10) {
        if (chk_pl->sw_now & 0x10) {
            waza_ptr->uni0.tame.flag++;
        }
        if (chk_pl->sw_now & 0x20) {
            waza_ptr->uni0.tame.shot_flag++;
        }
        if (chk_pl->sw_now & 0x40) {
            waza_ptr->uni0.tame.shot_flag2++;
        }
    } else {
        if (chk_pl->sw_now & 0x100) {
            waza_ptr->uni0.tame.flag++;
        }
        if (chk_pl->sw_now & 0x200) {
            waza_ptr->uni0.tame.shot_flag++;
        }
        if (chk_pl->sw_now & 0x400) {
            waza_ptr->uni0.tame.shot_flag2++;
        }
    }
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->uni0.tame.flag = 0;
        waza_ptr->uni0.tame.shot_flag = 0;
        waza_ptr->uni0.tame.shot_flag2 = 0;
        waza_ptr->w_int = waza_ptr->free1;
    }
    cp = &wcp[cmd_id];
    wtype = &waza_type[cmd_id];
    if (cp->waza_flag[*wtype]) {
        if (waza_ptr->w_int > 0 && waza_ptr->uni0.tame.shot_flag2) {
            cp->waza_flag[*wtype] = cp->reset[*wtype];
            waza_ptr->uni0.tame.shot_flag2 = 0;
            waza_ptr->w_int = 9;
            return;
        }
    } else if (waza_ptr->uni0.tame.shot_flag2 >= 5) {
        cp->waza_flag[*wtype] = cp->reset[*wtype];
        waza_ptr->uni0.tame.shot_flag2 = 0;
        waza_ptr->w_int = 9;
        chk_pl->waza_no = waza_type[cmd_id];
        return;
    }
    if (cp->waza_flag[*wtype]) {
        if (waza_ptr->w_int > 0 && waza_ptr->uni0.tame.shot_flag) {
            cp->waza_flag[*wtype] = cp->reset[*wtype];
            waza_ptr->uni0.tame.shot_flag = 0;
            waza_ptr->w_int = 12;
            return;
        }
    } else if (waza_ptr->uni0.tame.shot_flag >= 5) {
        cp->waza_flag[*wtype] = cp->reset[*wtype];
        waza_ptr->uni0.tame.shot_flag = 0;
        waza_ptr->w_int = 12;
        chk_pl->waza_no = waza_type[cmd_id];
        return;
    }
    if (cp->waza_flag[*wtype]) {
        if (waza_ptr->w_int > 0 && waza_ptr->uni0.tame.flag) {
            cp->waza_flag[*wtype] = cp->reset[*wtype];
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = 15;
        }
    } else if (waza_ptr->uni0.tame.flag >= 5) {
        cp->waza_flag[*wtype] = cp->reset[*wtype];
        waza_ptr->uni0.tame.flag = 0;
        waza_ptr->w_int = 15;
        chk_pl->waza_no = waza_type[cmd_id];
    }
}



void check_5(void) {
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    if (dead_lvr_check() == 0 && waza_ptr->w_lvr == chk_pl->sw_now) {
        if (*waza_ptr->w_ptr == 0x1C) {
            command_ok();
            return;
        }
        check_next();
    }
}



void check_6(void) {
    s16 i;
    s32 lvr_work;
    WAZA_WORK** wp = &waza_ptr;
    (*wp)->w_int--;
    if ((*wp)->w_int < 0) {
        cmd_tbl_ptr += 12;
        (*wp)->w_type = *cmd_tbl_ptr++;
        (*wp)->w_int = *cmd_tbl_ptr++;
        (*wp)->free2 = *cmd_tbl_ptr++;
        (*wp)->w_lvr = *cmd_tbl_ptr++;
        (*wp)->w_ptr = cmd_tbl_ptr;
        (*wp)->uni0.tame.flag = 0;
        (*wp)->uni0.tame.shot_flag = 0;
        (*wp)->uni0.tame.shot_flag2 = 0;
        (*wp)->free1 = 14;
        (*wp)->shot_ok = 0;
    } else {
        (*wp)->free1--;
        if ((*wp)->free1 <= 0) {
            (*wp)->free1 = 14;
            (*wp)->shot_ok = 0;
        }
    }
    lvr_work = 1;
    for (i = 0; i < 4; i++) {
        if (chk_pl->sw_lever == (u16)lvr_work) {
            (*wp)->shot_ok |= lvr_work;
            (*wp)->free1 = 14;
        }
        lvr_work <<= 1;
    }
    if ((*wp)->shot_ok != 15) {
        return;
    }
    if (*(*wp)->w_ptr == 0x1C) {
        command_ok();
    } else {
        (*wp)->shot_ok = 0;
        check_next();
    }
}



/* provisional name: steps to the next command entry twice (w_type, w_int, free2, w_lvr, then free1 too), unreferenced */
void check_6_sub1(void) {
    cmd_tbl_ptr += 12;
    waza_ptr->w_type = *cmd_tbl_ptr++;
    waza_ptr->w_int = *cmd_tbl_ptr++;
    waza_ptr->free2 = *cmd_tbl_ptr++;
    waza_ptr->w_lvr = *cmd_tbl_ptr++;
    waza_ptr->w_ptr = cmd_tbl_ptr;
    waza_ptr->uni0.tame.flag = 0;
    waza_ptr->free3 = 0;
    waza_ptr->w_type = *cmd_tbl_ptr++;
    waza_ptr->w_int = *cmd_tbl_ptr++;
    waza_ptr->free1 = *cmd_tbl_ptr;
    waza_ptr->free2 = *cmd_tbl_ptr++;
    waza_ptr->w_lvr = *cmd_tbl_ptr++;
    waza_ptr->w_ptr = cmd_tbl_ptr;
    waza_ptr->uni0.tame.flag = 0;
    waza_ptr->uni0.tame.shot_flag = 0;
    waza_ptr->uni0.tame.shot_flag2 = 0;
    waza_ptr->shot_ok = 0;
    waza_ptr->free3 = 0;
}



/* provisional name: steps to the next command entry (w_type, w_int, free1, w_lvr), unreferenced */
void check_6_sub2(void) {
    cmd_tbl_ptr += 12;
    waza_ptr->w_type = *cmd_tbl_ptr++;
    waza_ptr->w_int = *cmd_tbl_ptr++;
    waza_ptr->free1 = *cmd_tbl_ptr++;
    waza_ptr->w_lvr = *cmd_tbl_ptr++;
    waza_ptr->w_ptr = cmd_tbl_ptr;
    waza_ptr->uni0.tame.shot_flag = 0;
    waza_ptr->shot_ok = 0;
}



void check_7(void) {
    s16 i;
    s16 w_flag;
    s16* shot_cnt_adrs;
    waza_ptr->w_int--;
    if (waza_ptr->w_type == 8) {
        sw_work = chk_pl->sw_new & 0x70;
        shot_cnt_adrs = &chk_pl->s1_cnt;
        w_flag = 0x10;
    } else {
        sw_work = chk_pl->sw_new & 0x780;
        shot_cnt_adrs = &chk_pl->s4_cnt;
        w_flag = 0x100;
    }
    waza_ptr->uni0.tame.shot_flag2 = waza_ptr->uni0.tame.shot_flag;
    waza_ptr->uni0.tame.shot_flag = 0;
    for (i = 0; i < 3; i++) {
        if (*shot_cnt_adrs & waza_ptr->w_lvr) {
            waza_ptr->uni0.tame.shot_flag |= w_flag;
        }
        *shot_cnt_adrs++;
        if (chk_pl->shot_down & w_flag && waza_ptr->uni0.tame.shot_flag2 & w_flag) {
            waza_ptr->shot_ok += 1;
        }
        w_flag *= 2;
    }
    if (waza_ptr->shot_ok) {
        waza_ptr->free2--;
        if (waza_ptr->free2 < 0) {
            waza_ptr->shot_ok = 0;
            waza_ptr->free2 = waza_ptr->free1;
            waza_ptr->uni0.tame.shot_flag = 0;
        }
    }
    if (waza_ptr->shot_ok >= waza_ptr->w_lvr) {
        waza_ptr->shot_ok = 0;
        waza_ptr->free2 = waza_ptr->free1;
        if (*waza_ptr->w_ptr == 28) {
            command_ok();
            return;
        }
        check_next();
    }
}



void check_9(void) {
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    if (waza_ptr->w_lvr & 0x8000) {
        sw_work = waza_ptr->w_lvr & 0xF;
        if (waza_ptr->w_lvr == 0) {
            if (chk_pl->new_lvbt == 0) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF)) {
            if (chk_pl->sw_lever == sw_work) {
                if (*waza_ptr->w_ptr == 0x1C) {
                    command_ok();
                    return;
                }
                check_next();
                return;
            }
            waza_ptr->w_type = 0;
        }
    } else if (waza_ptr->w_lvr == 0) {
        if (chk_pl->new_lvbt == 0) {
            if (*waza_ptr->w_ptr == 28) {
                command_ok();
                return;
            }
            check_next();
            return;
        }
        if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF)) {
            waza_ptr->w_type = 0;
        }
    } else if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF)) {
        if (chk_pl->sw_lever & waza_ptr->w_lvr) {
            if (*waza_ptr->w_ptr == 28) {
                command_ok();
                return;
            }
            check_next();
            return;
        }
        waza_ptr->w_type = 0;
    }
}



s32 paring_miss_init(void) {
    s32 zero = 0;
    waza_ptr->free3 = zero;
    waza_ptr->uni0.tame.flag = waza_ptr->w_type = zero;
    wcp[cmd_id].waza_flag[waza_type[cmd_id]] = zero;
}



void check_10(void) {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
        }
        break;
    case 1:
        if ((cmd_pl->wu.xyz[1].disp.pos > 0 || (waza_type[cmd_id] != 5 && waza_type[cmd_id] != 6)) &&
            chk_pl->now_lvbt & 0xF) {
            if (chk_pl->sw_lever == waza_ptr->w_lvr) {
                waza_ptr->shot_ok++;
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                waza_ptr->free3 = wcp[cmd_id].reset[waza_type[cmd_id]] + 10;
                waza_ptr->w_int = 6;
                switch (waza_type[cmd_id]) {
                case 3:
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 4:
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 5:
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    if (waza_work[cmd_id][6].free3 > 0) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    break;
                case 6:
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    if (waza_work[cmd_id][5].free3 > 0) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    break;
                case 12:
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    break;
                }
            } else {
                waza_ptr->shot_ok = 0;
                break;
            }
        }
        break;
    case 2:
        waza_ptr->w_int--;
        waza_ptr->free3--;
        if (waza_ptr->w_int > 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever != waza_ptr->w_lvr) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
        } else {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->shot_ok++;
        }
        break;
    case 3:
        waza_ptr->free3--;
        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            break;
        }
        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }
        if (chk_pl->sw_now & 0xF) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
        }
        break;
    case 4:
        waza_ptr->free3--;
        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
        }
        break;
    }
}



void check_11(void) {
    if (dead_lvr_check()) {
        paring_miss_init();
        return;
    }
    switch (waza_ptr->uni0.tame.flag) {
    case 0:
        if (chk_pl->sw_lever & 8) {
            waza_ptr->uni0.tame.flag = 1;
            break;
        }
        waza_ptr->uni0.tame.flag = 0;
        break;
    case 1:
        if (chk_pl->sw_lever == 2) {
            check_next();
            break;
        }
        if (!(chk_pl->sw_lever & 8)) {
            waza_ptr->uni0.tame.flag = 0;
        }
        break;
    }
}



void check_12(void) {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
        }
        break;
    case 1:
        if (cmd_pl->wu.xyz[1].disp.pos >= 1 && (chk_pl->now_lvbt & 0xF) != 0) {
            if (chk_pl->sw_lever == waza_ptr->w_lvr) {
                waza_ptr->shot_ok++;
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                waza_ptr->free3 = wcp[cmd_id].reset[waza_type[cmd_id]] + 10;
                waza_ptr->w_int = 6;
                switch (waza_type[cmd_id]) {
                case 3:
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 4:
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 5:
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 6:
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }
                    break;
                case 12:
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }
                    break;
                }
            } else {
                waza_ptr->shot_ok = 0;
                break;
            }
        }
        break;
    case 2:
        waza_ptr->w_int--;
        waza_ptr->free3--;
        if (waza_ptr->w_int >= 1) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever != waza_ptr->w_lvr) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
        } else {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->shot_ok++;
        }
        break;
    case 3:
        waza_ptr->free3--;
        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            break;
        }
        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }
        if (chk_pl->sw_now & 0xF) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
        }
        break;
    case 4:
        waza_ptr->free3--;
        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
        }
        break;
    }
}



void check_13(void) {
    u16 sw_w;
    if (waza_ptr->free3 > 0) {
        waza_ptr->free3--;
        if (waza_ptr->free3 <= 0) {
            waza_ptr->w_type = 0;
        }
    }
    if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF) && (chk_pl->sw_lever) == 2) {
        wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0x10 - ukemi_time_tbl[wcp[cmd_id].waza_flag[waza_type[cmd_id]]];
        waza_ptr->free3 = 0x10;
        chk_pl->waza_no = waza_type[cmd_id];
    }
    sw_w = (chk_pl->sw_now | chk_pl->old_now) & 0x70;
    if (sw_w == 0x70) {
        wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0x10 - ukemi_time_tbl[wcp[cmd_id].waza_flag[waza_type[cmd_id]]];
        waza_ptr->free3 = 0x10;
        chk_pl->waza_no = waza_type[cmd_id];
    }
}



void check_14(void) {
    s16 ofs;
    waza_ptr->w_int--;
    if (waza_ptr->w_lvr == 0x10) {
        if (chk_pl->sw_now & 0x70) {
            waza_ptr->uni0.tame.flag++;
        }
    } else if (chk_pl->sw_now & 0x700) {
        waza_ptr->uni0.tame.flag = waza_ptr->uni0.tame.flag + 1;
    }
    if (WCP_AT(ofs = cmd_id * (s16)sizeof(WORK_CP)).waza_flag[waza_type[cmd_id]]) {
        if (waza_ptr->w_int <= 0) {
            if (waza_ptr->uni0.tame.flag) {
                WCP_OFS(ofs, cmd_id);
                WCP_AT(ofs).waza_flag[waza_type[cmd_id]] = WCP_AT(ofs).reset[waza_type[cmd_id]];
                waza_ptr->uni0.tame.flag = 0;
                if (waza_type[cmd_id] & 1) {
                    waza_ptr->w_int = 10;
                } else {
                    waza_ptr->w_int = 6;
                }
                return;
            }
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = waza_ptr->free1;
        }
    } else if (waza_type[cmd_id] & 1) {
        if (waza_ptr->uni0.tame.flag >= 3) {
            WCP_OFS(ofs, cmd_id);
            WCP_AT(ofs).waza_flag[waza_type[cmd_id]] = WCP_AT(ofs).reset[waza_type[cmd_id]];
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = 0xA;
            chk_pl->waza_no = waza_type[cmd_id];
            return;
        }
        if (waza_ptr->w_int < 0) {
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = waza_ptr->free1;
        }
    } else {
        if (waza_ptr->uni0.tame.flag >= 3) {
            WCP_OFS(ofs, cmd_id);
            WCP_AT(ofs).waza_flag[waza_type[cmd_id]] = WCP_AT(ofs).reset[waza_type[cmd_id]];
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = 6;
            chk_pl->waza_no = waza_type[cmd_id];
            return;
        }
        if (waza_ptr->w_int < 0) {
            waza_ptr->uni0.tame.flag = 0;
            waza_ptr->w_int = waza_ptr->free1;
        }
    }
}



void check_15(void) {
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
        return;
    }
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            sw_work = waza_ptr->w_lvr & 0xF;
            if (chk_pl->sw_lever == sw_work) {
                waza_ptr->shot_ok++;
                if (waza_ptr->shot_ok >= waza_ptr->free1) {
                    if (*waza_ptr->w_ptr == 28) {
                        command_ok();
                        return;
                    }
                    check_next();
                }
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok += 1;
                if (waza_ptr->shot_ok >= waza_ptr->free1) {
                    if (*waza_ptr->w_ptr == 28) {
                        command_ok();
                        return;
                    }
                    check_next();
                }
            }
        } else if (((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF)) && (chk_pl->sw_lever & waza_ptr->w_lvr) &&
                   (waza_ptr->shot_ok += 1, waza_ptr->shot_ok < waza_ptr->free1 == 0)) {
            if (*waza_ptr->w_ptr == 0x1C) {
                command_ok();
                return;
            }
            check_next();
        }
    }
}



void check_16(void) {
    s16 i;
    u16 w_flag;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
        waza_ptr->shot_ok = 0;
        return;
    }
    if (waza_ptr->w_type == 17) {
        sw_work = chk_pl->sw_now & 0x70;
        w_flag = 0x10;
    } else {
        sw_work = chk_pl->sw_now & 0x700;
        w_flag = 0x100;
    }
    waza_ptr->uni0.tame.shot_flag2 = waza_ptr->uni0.tame.shot_flag;
    waza_ptr->uni0.tame.shot_flag = 0;
    for (i = 0; i < 3; i++) {
        if (sw_work & w_flag) {
            waza_ptr->shot_ok++;
        }
        w_flag *= 2;
    }
    if (waza_ptr->shot_ok >= waza_ptr->w_lvr) {
        waza_ptr->shot_ok = 0;
        if (*waza_ptr->w_ptr == 0x1C) {
            command_ok();
            return;
        }
        check_next();
    }
}



void check_18(void) {
    u16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
        return;
    }
    sw_lever = chk_pl->sw_lever & 0xF;
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF)) {
                sw_work = waza_ptr->w_lvr & 0xF;
                if (sw_lever == sw_work) {
                    waza_ptr->w_int = waza_ptr->free1;
                    wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                }
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->w_int = waza_ptr->free1;
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
            }
        } else if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF) && (sw_lever & waza_ptr->w_lvr)) {
            waza_ptr->w_int = waza_ptr->free1;
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
        }
    }
}



void check_19(void) {
    s16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    sw_lever = chk_pl->sw_lever & 0xF;
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            if (chk_pl->now_lvbt & 0xF) {
                if (sw_lever == (sw_work = waza_ptr->w_lvr & 0xF)) {
                    wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                    check_next();
                }
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (chk_pl->sw_lever == 0) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                check_next();
            }
        } else if ((chk_pl->now_lvbt & 0xF) != 0 && (sw_lever & waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
            check_next();
        }
    }
}



void check_20(void) {
}



void check_21(void) {
    u16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    sw_lever = chk_pl->sw_lever & 0xF;
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            sw_work = waza_ptr->w_lvr & 0xF;
            if (!sw_work) {
                if (!sw_lever) {
                    if (((*waza_ptr->w_ptr)) == 0x1C) {
                        command_ok();
                        return;
                    }
                    check_next();
                }
            } else if (chk_pl->now_lvbt & 0xF) {
                if (sw_lever == sw_work) {
                    if (*waza_ptr->w_ptr == 28) {
                        command_ok();
                        return;
                    }
                    check_next();
                }
            }
        } else if (!waza_ptr->w_lvr) {
            if (!sw_lever) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if ((chk_pl->now_lvbt & 0xF) && (sw_lever & waza_ptr->w_lvr)) {
            if (*waza_ptr->w_ptr == 28) {
                command_ok();
                return;
            }
            check_next();
        }
    }
}



void check_22(void) {
    s16 i;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_int = waza_ptr->free2;
        cmd_tbl_ptr += 12;
        waza_ptr->w_type = *cmd_tbl_ptr++;
        waza_ptr->w_int = *cmd_tbl_ptr++;
        waza_ptr->free1 = *cmd_tbl_ptr;
        waza_ptr->free2 = *cmd_tbl_ptr++;
        waza_ptr->w_lvr = *cmd_tbl_ptr++;
        waza_ptr->w_ptr = cmd_tbl_ptr;
        waza_ptr->uni0.tame.flag = 0;
        waza_ptr->uni0.tame.shot_flag = 0;
        waza_ptr->uni0.tame.shot_flag2 = 0;
        waza_ptr->shot_ok = 0;
        waza_ptr->free3 = 0;
    }
    for (i = 0; i < 8; i++) {
        if (chk_pl->sw_lever == kaiten_lever_tbl[i]) {
            waza_ptr->free3 |= 1 << i;
        }
    }
    if (waza_ptr->free3 == 0xFF) {
        if (((*waza_ptr->w_ptr)) == 0x1C) {
            command_ok();
            return;
        }
        waza_ptr->free3 = 0;
        check_next();
    }
}



void check_23(void) {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
            break;
        }
        break;
    case 1:
        if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF) && chk_pl->sw_lever == waza_ptr->w_lvr) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = wcp[cmd_id].reset[(waza_type[cmd_id])];
            waza_ptr->free3 = (s16)(((((wcp[cmd_id].reset[(waza_type[cmd_id])])) + 3)));
            waza_ptr->w_int = 6;
        }
        break;
    case 2:
        waza_ptr->w_int -= 1;
        waza_ptr->free3 -= 1;
        if (((waza_ptr->w_int)) > 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
                waza_ptr->shot_ok++;
                break;
            }
            if (chk_pl->sw_lever != ((waza_ptr->w_lvr))) {
                wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
                waza_ptr->w_type = 0;
                break;
            }
        } else {
            wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
            waza_ptr->shot_ok++;
        }
        break;
    case 3:
        waza_ptr->free3--;
        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            break;
        }
        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }
        if (chk_pl->sw_now & 0xF) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->w_type = 0;
        }
        break;
    }
}



void check_24(void) {
    u16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    sw_lever = chk_pl->now_lvbt & 0xF;
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            sw_work = waza_ptr->w_lvr & 0xF;
            if (sw_lever == sw_work) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (sw_lever == 0) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else {
            if (sw_lever & waza_ptr->w_lvr) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        }
    }
}



void check_25(void) {
    u16 sw_lever;
    waza_ptr->w_int--;
    if (waza_ptr->w_int < 0) {
        waza_ptr->w_type = 0;
    }
    sw_lever = chk_pl->sw_lever & 0xF;
    if (!dead_lvr_check()) {
        if (waza_ptr->w_lvr & 0x8000) {
            sw_work = waza_ptr->w_lvr & 0xF;
            if (sw_lever == sw_work) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else if (waza_ptr->w_lvr == 0) {
            if (sw_lever == 0) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else {
            if (sw_lever & waza_ptr->w_lvr) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        }
    }
}



void check_26(void) {
    u16 sw_lever = chk_pl->sw_now & 0xF;
    s16 sw_now_lvr = chk_pl->sw_lever & 0xF;
    if (!dead_lvr_check()) {
        sw_work = waza_ptr->w_lvr & 0xF;
        if (sw_lever != sw_work) {
            if (sw_now_lvr != sw_work && waza_ptr->uni0.tame.flag) {
                if (*waza_ptr->w_ptr == 28) {
                    command_ok();
                    return;
                }
                check_next();
            }
        } else {
            waza_ptr->uni0.tame.flag = 1;
        }
    }
}



void command_ok(void) {
    wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
    if (waza_ptr->w_type != 14) {
        waza_ptr->w_type = 0;
        chk_pl->waza_no = waza_type[cmd_id];
    }
}



void command_ok_move(s16 waza_num) {
    if (dead_lvr_check()) {
        wcp[cmd_id].waza_flag[waza_num] = 0;
    } else {
        wcp[cmd_id].waza_flag[waza_num]--;
    }
}



s8 dead_lvr_check(void) {
    WAZA_WORK* wk = waza_ptr;
    T_PL_LVR* pl = chk_pl;
    if ((wk->w_dead == 0 || wk->w_dead != pl->sw_new) && (wk->w_dead2 == 0 || wk->w_dead2 != pl->sw_new)) {
        return 0;
    }
    wk->w_type = 0;
    return 1;
}



void pl_lvr_set(void) {
    s16 ofs;
    u16 sw_work;
    u16 work2;
    u16 sw_0;
    u16 sw_hana;
    u16 hana2;
    sw_0 = WCP_MUL(ofs, cmd_id).sw_lvbt;
    sw_work = sw_0 & 0xC;
    if (check_rl_on_car(cmd_pl)) {
        if (cmd_pl->wu.rl_flag) {
            if (sw_work) {
                sw_0 &= 0xFF3;
                sw_work ^= 0xC;
                sw_0 |= sw_work;
            }
        }
    } else if (cmd_pl->wu.rl_waza) {
        if (sw_work) {
            sw_0 &= 0xFF3;
            sw_work ^= 0xC;
            sw_0 |= sw_work;
        }
    }
    WCP_MUL(ofs, cmd_id).old_now = chk_pl->sw_now;
    chk_pl->old_now = chk_pl->sw_now;
    chk_pl->old_lvbt = chk_pl->new_lvbt;
    sw_work = ~(chk_pl->old_lvbt) & (WCP_MUL(ofs, cmd_id).sw_lvbt);
    sw_hana = chk_pl->sw_new & ~(sw_0);
    work2 = sw_work & 0xF0;
    hana2 = sw_hana & 0xF0;
    switch (work2) {
    case 0x70:
    case 0x30:
    case 0x50:
    case 0x60:
        WCP_MUL(ofs, cmd_id).sw_lvbt |= 0x80;
        sw_0 |= 0x80;
        break;
    default:
        switch (hana2) {
        case 0x70:
        case 0x30:
        case 0x50:
        case 0x60:
            WCP_MUL(ofs, cmd_id).sw_lvbt |= 0x80;
            sw_0 |= 0x80;
            break;
        default:
            WCP_MUL(ofs, cmd_id).sw_lvbt &= 0xFF7F;
            sw_0 &= 0xFF7F;
            break;
        }
        break;
    }
    work2 = sw_work & 0xF00;
    hana2 = sw_hana & 0xF00;
    switch (work2) {
    case 0x700:
    case 0x300:
    case 0x500:
    case 0x600:
        WCP_MUL(ofs, cmd_id).sw_lvbt |= 0x800;
        sw_0 |= 0x800;
        break;
    default:
        switch (hana2) {
        case 0x700:
        case 0x300:
        case 0x500:
        case 0x600:
            WCP_MUL(ofs, cmd_id).sw_lvbt |= 0x800;
            sw_0 |= 0x800;
            break;
        default:
            WCP_MUL(ofs, cmd_id).sw_lvbt &= 0xF7FF;
            sw_0 &= 0xF7FF;
            break;
        }
        break;
    }
    chk_pl->new_lvbt = WCP_MUL(ofs, cmd_id).sw_lvbt;
    chk_pl->sw_old = chk_pl->sw_new;
    chk_pl->sw_new = sw_0;
    chk_pl->sw_now = sw_0 & ~(chk_pl->sw_old);
    chk_pl->now_lvbt = ~(chk_pl->old_lvbt) & (WCP_MUL(ofs, cmd_id).sw_lvbt);
    chk_pl->sw_chg = (chk_pl->sw_now) | (chk_pl->sw_old & ~(sw_0));
    chk_pl->sw_lever = sw_0 & 0xF;
    chk_pl->shot_up = chk_pl->sw_now & 0x770;
    chk_pl->shot_down = chk_pl->sw_old & ~(sw_0) & 0x770;
    chk_pl->shot_ud = ((chk_pl->shot_up) | (chk_pl->shot_down));
    sw_work = ((chk_pl->sw_now) | (WCP_MUL(ofs, cmd_id).old_now));
    if ((sw_work & 0x110) == 0x110) {
        WCP_MUL(ofs, cmd_id).ca14 = 1;
    } else {
        WCP_MUL(ofs, cmd_id).ca14 = 0;
    }
    if ((sw_work & 0x220) == 0x220) {
        WCP_MUL(ofs, cmd_id).ca25 = 1;
    } else {
        WCP_MUL(ofs, cmd_id).ca25 = 0;
    }
    if ((sw_work & 0x440) == 0x440) {
        WCP_MUL(ofs, cmd_id).ca36 = 1;
    } else {
        WCP_MUL(ofs, cmd_id).ca36 = 0;
    }
    WCP_MUL(ofs, cmd_id).lgp = lever_gacha_tbl[cmd_pl->cp->sw_now & 0xF] * 4;
    WCP_MUL(ofs, cmd_id).lgp += lever_gacha_tbl[cmd_pl->cp->sw_off & 0xF] * 2;
    WCP_MUL(ofs, cmd_id).lgp += lever_gacha_tbl[(cmd_pl->cp->sw_now / 16) & 7] * 2;
    WCP_MUL(ofs, cmd_id).lgp += lever_gacha_tbl[(cmd_pl->cp->sw_now / 256) & 7] * 1;
}



void sw_pick_up(void) {
    s16 i;
    s16* cnt_address1;
    pl_lvr_set();
    sw_work = 1;
    cnt_address1 = &chk_pl->up_cnt;
    for (i = 0; i < 10; i++) {
        if (chk_pl->sw_new & sw_work) {
            *cnt_address1 += 1;
        } else {
            *cnt_address1 = 0;
        }
        *cnt_address1++;
        sw_work *= 2;
    }
    for (i = 0; i < 4; i++) {
        if (chk_pl->sw_new & lvr_chk_tbl[i]) {
            *cnt_address1 += 1;
        } else {
            *cnt_address1 = 0;
        }
        *cnt_address1++;
    }
    wcp[cmd_id].sw_new = chk_pl->sw_new;
    wcp[cmd_id].sw_old = chk_pl->sw_old;
    wcp[cmd_id].sw_chg = chk_pl->sw_chg;
    wcp[cmd_id].sw_now = chk_pl->sw_now;
    wcp[cmd_id].sw_off = chk_pl->shot_down;
    if ((i = wcp[cmd_id].sw_lvbt & 0xC)) {
        if (cmd_pl->wu.rl_flag) {
            wcp[cmd_id].lever_dir = (i & 8) ? 1 : 2;
        } else if (i & 4) {
            wcp[cmd_id].lever_dir = 1;
        } else {
            wcp[cmd_id].lever_dir = 2;
        }
    } else {
        wcp[cmd_id].lever_dir = 0;
    }
    wcp[cmd_id].calf = ((chk_pl->left_cnt != 0) && (chk_pl->left_cnt < 12)) ? 1 : 0;
    if ((chk_pl->right_cnt != 0) && (chk_pl->right_cnt < 12)) {
        wcp[cmd_id].calr = 1;
        return;
    }
    wcp[cmd_id].calr = 0;
}



void dash_flag_clear(s16 pl_id) {
    intptr_t* adrs;
    adrs = pl_CMD[plw[pl_id].player_number];
    waza_compel_init(pl_id, 0, adrs);
    waza_compel_init(pl_id, 1, adrs);
}



void hi_jump_flag_clear(s16 pl_id) {
    waza_compel_init(pl_id, 2, pl_CMD[plw[pl_id].player_number]);
}



/* provisional name */
void basic_waza_flag_clear(s16 pl_id) {
    intptr_t* adrs = pl_CMD[plw[pl_id].player_number];
    waza_compel_init(pl_id, 0, adrs);
    waza_compel_init(pl_id, 1, adrs);
    waza_compel_init(pl_id, 3, adrs);
    waza_compel_init(pl_id, 4, adrs);
    waza_compel_init(pl_id, 12, adrs);
    waza_compel_init(pl_id, 5, adrs);
    waza_compel_init(pl_id, 6, adrs);
}



void waza_flag_clear_only_1(s16 pl_id, s16 wznum) {
    waza_compel_init(pl_id, wznum, pl_CMD[plw[pl_id].player_number]);
}



void waza_compel_init(s16 pl_id, s16 num, intptr_t* adrs) {
    WAZA_WORK* w_ptr;
    s16* ptr;
    ptr = (s16*)adrs[num];
    ptr += 12;
    w_ptr = &waza_work[pl_id][num];
    w_ptr->w_type = *ptr++;
    w_ptr->w_int = *ptr++;
    w_ptr->free1 = *ptr;
    w_ptr->free2 = *ptr++;
    w_ptr->w_lvr = *ptr++;
    w_ptr->w_ptr = ptr;
    w_ptr->uni0.tame.flag = 0;
    w_ptr->uni0.tame.shot_flag = 0;
    w_ptr->uni0.tame.shot_flag2 = 0;
    w_ptr->shot_ok = 0;
    w_ptr->free3 = 0;
    wcp[pl_id].waza_flag[num] = 0;
}



void waza_compel_all_init(PLW* pl) {
    s16 i;
    intptr_t* adrs;
    adrs = pl_CMD[pl->player_number];
    for (i = 0; i < (pl_cmd_num[pl->player_number][0]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][0]); i < 20; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
    for (i = 20; i < (pl_cmd_num[pl->player_number][1]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][1]); i < 24; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
    for (i = 24; i < (pl_cmd_num[pl->player_number][2]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][2]); i < 28; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
        continue;
    }
    for (i = 28; i < (pl_cmd_num[pl->player_number][3]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][3]); i < 38; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
    for (i = 38; i < (pl_cmd_num[pl->player_number][4]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][4]); i < 42; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
    for (i = 42; i < (pl_cmd_num[pl->player_number][5]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][5]); i < 46; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
    for (i = 46; i < (pl_cmd_num[pl->player_number][6]); i++) {
        cmd_tbl_ptr = (s16*)adrs[i];
        cmd_data_set(pl, i);
        continue;
    }
    for (i = (pl_cmd_num[pl->player_number][6]); i < 56; i++) {
        wcp[cmd_id].waza_flag[i] = -1;
    }
}
