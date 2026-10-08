/*
 * GAME_CONFIG_JP.C  Test-mode game configuration, Japanese page
 *
 * game_config_init_jp draws the GAME CONFIGURATION page shown when Country is 1 and
 * game_config_move_jp runs it: screen mode, difficulty, damage, timer speed, 1P/2P round counts,
 * event and bonus settings, with lever repeat and star gauges. game_config_apply copies the edited
 * settings back when the page is left.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "Com_Pl.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "CALDIR.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF00.h"
#include "EFF02.h"
#include "EFFK5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "fifo.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg000.h"
#include "HITCHECK.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "cmd_main_2.h"
#include "CMD_MAIN.h"
#include "cps3.h"

/* provisional name */
void game_config_init_jp(void) {
    s8 n;

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
    n = Config_Item_jp = 6;
    Config_New_jp = game_config_work.bonus & 1;
    Config_Old_jp = Game_setting.bonus & 1;
    Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_bonus_scr_jp[Config_New_jp]);
    n = Config_Item_jp = 5;
    Config_New_jp = game_config_work.set5;
    Config_Attr_jp = (Config_New_jp != Game_setting.set5) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_event_scr_jp[Config_New_jp]);
    n = Config_Item_jp = 4;
    Config_New_jp = game_config_work.set4 / 16;
    Config_New_jp &= 3;
    Config_Org_jp = Game_setting.set4 / 16;
    Config_Org_jp &= 3;
    Config_Attr_jp = (Config_New_jp != Config_Org_jp) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    n = Config_Item_jp = 3;
    Config_New_jp = game_config_work.set4 & n;
    Config_Org_jp = Game_setting.set4 & n;
    Config_Attr_jp = (Config_New_jp != Config_Org_jp) ? 8 : 2;
    game_config_print_value_jp(Config_Attr_jp, &gcfg_round_scr_jp[Config_New_jp]);
    n = Config_Item_jp = 2;
    Config_New_jp = game_config_work.set3;
    Config_Attr_jp = (Config_New_jp != Game_setting.set3) ? 8 : 2;
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    n = Config_Item_jp = 1;
    Config_New_jp = game_config_work.set2;
    Config_Attr_jp = (Config_New_jp != Game_setting.set2) ? 8 : 2;
    game_config_print_gauge_jp(Config_New_jp, 0xFFFF, Config_Attr_jp);
    n = Config_Item_jp = 0;
    Config_New_jp = game_config_work.level;
    Config_Attr_jp = (Config_New_jp != Game_setting.level) ? 8 : 2;
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
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.mode += Config_Move_jp;
        game_config_work.mode &= 1;
        if (game_config_work.mode) {
            set_screen_mode(7);
        } else {
            set_screen_mode(3);
        }
        screen_flip_offsets_set();
        tilemap_print_script_seq(24, 2, 0xFFFF, (TMSCRIPT*)&gcfg_screen_scr_jp[game_config_work.mode]);
        if (game_config_work.mode != Game_setting.mode) {
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
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = Game_setting.set4 & 3;
        Config_New_jp = game_config_work.set4 & 3;
        Config_New_jp += Config_Move_jp;
        Config_New_jp &= 3;
        Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
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
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        Config_Old_jp = Game_setting.set4 & 0x30;
        Config_Old_jp /= 16;
        Config_Old_jp &= 3;
        Config_New_jp = game_config_work.set4 & 0x30;
        Config_New_jp /= 16;
        Config_New_jp &= 3;
        Config_New_jp += Config_Move_jp;
        Config_New_jp &= 3;
        Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
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
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.set5 += Config_Move_jp;
        game_config_work.set5 &= 1;
        Config_New_jp = game_config_work.set5;
        Config_Attr_jp = (Config_New_jp != Game_setting.set5) ? 8 : 2;
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
        if ((p1sw_0 & ~p1sw_1) & 0x10) {
            Config_Move_jp = -1;
        }
        if ((p1sw_0 & ~p1sw_1) & 0x20) {
            Config_Move_jp = 1;
        }
    }
    if (Config_Move_jp) {
        game_config_work.bonus ^= 1;
        game_config_work.bonus &= 1;
        Config_New_jp = game_config_work.bonus & 1;
        Config_Old_jp = Game_setting.bonus & 1;
        Config_Attr_jp = (Config_New_jp != Config_Old_jp) ? 8 : 2;
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
    if (~p1sw_1 & p1sw_0 & sw) {
        return 1;
    }
    if (p1sw_0 & sw) {
        Config_Rep_Timer_jp[ix]++;
        if (Config_Rep_Timer_jp[ix] > 10) {
            Config_Rep_Count_jp[ix]++;
            if (Config_Rep_Count_jp[ix] > 8) {
                Config_Rep_Count_jp[ix] = 0;
                return 1;
            }
        }
    } else {
        Config_Rep_Timer_jp[ix] = 0;
        Config_Rep_Count_jp[ix] = 0;
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
