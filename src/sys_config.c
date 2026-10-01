/*
 * sys_config.c  Settings storage, configuration menu and render list setup
 *
 * EEPROM settings: eeprom_config_load / save / reset / default / verify read and write the
 * operator settings record, and eeprom_config_apply puts a loaded record into effect.
 * The configuration menu of test mode (config_menu_*, sysconfig_* and gameconfig_page) lets the
 * operator change coin and chute settings, continue, monitor, demo sound, sound mode, voice
 * type, card dispenser, win points and extra options, then save and exit.
 * Display management: init_render_lists sets up the sprite pools (SPR_POOL.C), the SIMM RAM free lists
 * (SIMMRAM.C), the polygon transfer queue and the fixed sprite lists (POLY_QUE.C) and the sprite templates;
 * dma_src_ack_seq and sprite_dma_end_wait drive the sprite DMA handshake.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CMD_MAIN.h"
#include "meta_col.h"
#include "eeprom.h"
#include "textsound.h"
#include "cram_bank.h"
#include "game_config_main.h"
#include "sys_config.h"
#include "cps3.h"
/* provisional name */
u32 *eeprom_config_load(void)
{
    u32 *rv;
    s16 i;
    s8 ix;
    u8 *name;
    u8 *ref;

    eeprom_config_verify();
    if (Area_Type) {
        ix = Area_Type;
    } else if (Area_Alt_Flag) {
        ix = 6;
    } else {
        ix = Area_Type;
    }
    if ((s8)eeprom_w[0] == **(s8 **)(sys_cfg_default_tbl[Cabinet_Type] + ix * 4)) {
        ref = eeprom_game_cfg + 8;
        name = game_cfg_default_tbl[ix] + 8;
        for (i = 0; i < 8; i++) {
            if (*ref != *name) {
                rv = ((u32 *(*)())eeprom_config_reset)();
                return rv;
            }
            ref++;
            name++;
        }
        eeprom_config_apply((u32)eeprom_w);
        /* the bookkeeping counters follow the two config copies in the EEPROM image */
        book_coin_count[0] = *(u32 *)&eeprom_w[0x60];
        book_coin_count[1] = *(u32 *)&eeprom_w[0x64];
        book_coin_count[2] = *(u32 *)&eeprom_w[0x68];
        rv = (u32 *)&eeprom_w[0x6C];
        book_coin_count[3] = *rv;
    } else {
        rv = ((u32 *(*)())eeprom_config_reset)();
    }
    return rv;
}



/* provisional name */
void eeprom_config_reset(void) {
    register s8 ix;
    register s16 k;
    register s16 j;
    u32 table;
    u8* rec;
    u8* ref;
    u8* key;
    u8* name;
    for (eeprom_retry = 10; eeprom_retry > 0; eeprom_retry--) {
        eeprom_config_default();
        if (eeprom_write(64, (u16*)(EEP_ROM + 0x80), (u16*)eeprom_w)) {
            eeprom_error_halt();
        }
        if (eeprom_read(64, (u16*)(EEP_ROM + 0x100), (u16*)eeprom_w)) {
            eeprom_error_halt();
        }
        rec = eeprom_w;
        table = sys_cfg_default_tbl[Cabinet_Type];
        if (Area_Type) {
            ix = Area_Type;
        } else if (Area_Alt_Flag) {
            ix = 6;
        } else {
            ix = Area_Type;
        }
        key = *(u8**)(table + ix * 4);
        ref = eeprom_game_cfg;
        name = game_cfg_default_tbl[ix];
        if (config_bytes_equal(rec, key, 32) && config_bytes_equal(ref, name, 16)) {
            eeprom_config_apply(eeprom_w);
            return;
        }
    }
    eeprom_error_halt();
}



/* provisional name */
s8 config_bytes_equal(u8* a, u8* b, s32 n) {
    register s32 i;
    for (i = 0; i < n; i++) {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}



/* provisional name */
void eeprom_config_apply(rec)
u32 rec;
{
    s32 i;
    u8* src;
    s8* dst;
    Coin_Mode = *(s8*)(rec + 1);
    Continue_Flag = *(s8*)(rec + 2);
    Chute_Mode = *(s8*)(rec + 3);
    Sound_Mode = *(s8*)(rec + 4);
    Demo_Sound = *(s8*)(rec + 5);
    Monitor_Flip = *(s8*)(rec + 6);
    Language = *(s8*)(rec + 9);
    Free_Play_Enable = *(s8*)(rec + 8);
    if (Sound_Mode == 0) {
        sound_init(snd_seq_rom_data, snd_sample_rom_tbl, snd_bank_rom_tbl, 1, 0, 1);
    } else {
        sound_init(snd_seq_rom_data, snd_sample_rom_tbl, snd_bank_rom_tbl, 1, 0, 0);
    }
    Card_Dispenser = *(s8*)(rec + 10);
    Win_Point_Com = *(s8*)(rec + 11);
    Win_Point_Human = *(s8*)(rec + 12);
    Voice_Type = *(s8*)(rec + 13);
    if (Coin_Mode > 18) {
        Coin_Mode = 8;
    }
    if (Free_Play_Enable != 0 && Coin_Mode == 18) {
        Free_Play = 1;
    } else {
        Free_Play = 0;
    }
    if (Win_Point_Com < Win_Point_Com_Min || Win_Point_Com > Win_Point_Com_Max) {
        Win_Point_Com = 2;
    }
    if (Win_Point_Human < Win_Point_Human_Min || Win_Point_Human > Win_Point_Human_Max) {
        Win_Point_Human = 2;
    }
    (*(u8*)((void*)&(*(s8*)&(coin_chute1_w[2])))) = coin_rate_tbl[Coin_Mode][0];
    coin_chute1_w[3] = coin_rate_tbl[Coin_Mode][1];
    (*(u8*)((void*)&coin_chute2_w[2])) = coin_rate_tbl[Coin_Mode][0];
    (*(u8*)&(coin_chute2_w[3])) = coin_rate_tbl[Coin_Mode][1];
    coin3_coin_rate = coin_rate_tbl[Coin_Mode][0];
    coin3_credit_rate = coin_rate_tbl[Coin_Mode][1];
    coin4_coin_rate = coin_rate_tbl[Coin_Mode][0];
    coin4_credit_rate = coin_rate_tbl[Coin_Mode][1];
    if (Coin_Mode != 17) {
        Two_Coin_Start = 0;
    } else {
        Two_Coin_Start = 1;
        Continue_Flag = 1;
    }
    src = eeprom_game_cfg;
    dst = (s8 *)&Game_setting;
    for (i = 0; i < 16; i++) {
        *dst = *src;
        dst++;
        src++;
    }
}



/* provisional name */
void eeprom_config_save(void) {
    register s16 k;
    register s16 j;
    u32 p;
    s8* src;
    p = (u32)eeprom_w;
    for (k = 0; k < 2; k++) {
        *(u8*)(p + 1) = Coin_Mode;
        *(u8*)(p + 2) = Continue_Flag;
        *(u8*)(p + 3) = Chute_Mode;
        *(u8*)(p + 4) = Sound_Mode;
        *(u8*)(p + 5) = Demo_Sound;
        *(u8*)(p + 6) = Monitor_Flip;
        *(u8*)(p + 9) = Language;
        *(u8*)(p + 8) = Free_Play_Enable;
        *(u8*)(p + 10) = ((s8)Card_Dispenser);
        *(u8*)(p + 11) = Win_Point_Com;
        *(u8*)(p + 12) = Win_Point_Human;
        *(u8*)(p + 13) = Voice_Type;
        if (Sound_Mode == 0) {
            sound_init(snd_seq_rom_data, snd_sample_rom_tbl, snd_bank_rom_tbl, 1, 0, 1);
        } else {
            sound_init(snd_seq_rom_data, snd_sample_rom_tbl, snd_bank_rom_tbl, 1, 0, 0);
        }
        if (Free_Play_Enable == 0) {
            *(u8*)(p + 8) = 0;
        }
        p += 32;
        src = (s8 *)&Game_setting;
        for (j = 0; j < 16; j++) {
            *(u8*)p = *src;
            p++;
            src++;
        }
    }
    if (eeprom_write(48, (u16*)(EEP_ROM + 0x80), (u16*)eeprom_w)) {
        eeprom_error_halt();
    }
    eeprom_config_apply(eeprom_w);
}



/* provisional name */
void eeprom_config_default(void) {
    register s8 ix;
    register s16 k;
    register s16 j;
    u32 table;
    u8* dst;
    u8* src;
    dst = eeprom_w;
    for (k = 0; k < 2; k++) {
        table = sys_cfg_default_tbl[Cabinet_Type];
        if (Area_Type) {
            ix = Area_Type;
        } else if (Area_Alt_Flag) {
            ix = 6;
        } else {
            ix = Area_Type;
        }
        src = *(u8**)(table + ix * 4);
        for (j = 0; j < 32; j++) {
            *dst = *src;
            dst++;
            src++;
        }
        src = game_cfg_default_tbl[ix];
        for (j = 0; j < 16; j++) {
            *dst = *src;
            dst++;
            src++;
        }
    }
    for (j = 0; j < 32; j++) {
        *dst = 0;
        dst++;
    }
}



/* provisional name */
void eeprom_config_verify(void) {
    register s16 i;
    u8* a;
    u8* b;
    eeprom_retry = 10;
    while (eeprom_retry > 0) {
        if (eeprom_read(64, (u16*)(EEP_ROM + 0x100), (u16*)eeprom_w)) {
            eeprom_error_halt();
        }
        a = eeprom_w;
        b = eeprom_backup_cfg;
        for (i = 0; i < 48; i++) {
            if (*a != *b) {
                break;
            }
            a++;
            b++;
        }
        if (i == 48) {
            return;
        }
        eeprom_retry--;
    }
    eeprom_config_reset();
}



/* provisional name */
s32 config_menu_run(void)
{
  config_menu_tbl[Config_No_0]();
  return (s32)(char)cfg_reserve;
}



/* provisional name */
void config_menu_init(void) {
    s32 i;
    u32 table;
    u32 dst;
    s8* src;
    Config_No_0++;
    Config_No_1 = 0;
    Config_No_2 = 0;
    cfg_top_cursor = 0;
    cfg_cont_forced = 0;
    cfg_reserve = 0;
    cfg_coin_special = Free_Play;
    cfg_coin = Coin_Mode;
    cfg_continue = Continue_Flag;
    cfg_free_play = Two_Coin_Start;
    cfg_sound_mode = Sound_Mode;
    cfg_voice = Language;
    cfg_flip_old = Monitor_Flip;
    cfg_demo_sound = Demo_Sound;
    cfg_chute = Chute_Mode;
    cfg_dispenser = ((s8)Card_Dispenser);
    cfg_win_point = Win_Point_Com;
    cfg_win_point_vs = Win_Point_Human;
    cfg_extra = Voice_Type;
    dst = (u32)&game_config_work;
    src = (s8 *)&Game_setting;
    for (i = 0; i < 16; i++) {
        *(u8*)dst = *src;
        dst++;
        src++;
    }
    game_config_apply();
    if (event_off_flag == 0) {
        if (cfg_coin == 17) {
            table = sys_cfg_default_tbl[Cabinet_Type];
            if (Area_Type) {
                i = Area_Type;
            } else if (Area_Alt_Flag) {
                i = 6;
            } else {
                i = Area_Type;
            }
            dst = *(u32*)(table + i * 4);
            cfg_coin = *(u8*)(dst + 1);
        }
        cfg_continue = 0;
    }
}

/* provisional name */
u32 config_menu_dispatch(void)
{
    u32 rv;

    /* per-page handler table in work RAM (02007E04), indexed by Config_No_1 */
    rv = config_page_tbl[Config_No_1]();
    return rv;
}

/* Configuration top page: draw it, then run its menu (step Config_No_2). */
/* provisional name */
void config_top_page(void)
{
    config_top_step_tbl[Config_No_2]();
}

/* Draw the configuration top page.  Overseas boards print the English menu;
   Japanese boards load the kana font and the glyphs for the menu headings
   into the text layer and print the Japanese menu. */
/* provisional name */
void config_top_draw(void)
{
    Config_No_2++;
    if (Area_Type) {
        tilemap_fill_all(0, 0x20);
    } else {
        tilemap_fill_all(0, 0x1200);
    }
    task_sleep(1);
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, config_top_menu_scr);
    } else {
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0x8000), (char *)jp_menu_font_cg, 512);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xCA00), (char *)config_jp_chr_0 + 0x080, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0x8200), (char *)config_jp_chr_0 + 0x100, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xCC00), (char *)config_jp_chr_0 + 0x180, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xCE00), (char *)config_jp_chr_0 + 0x200, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0x9B00), (char *)config_jp_chr_0 + 0x280, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xA500), (char *)config_jp_chr_0 + 0x300, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xC300), (char *)config_jp_chr_0 + 0x380, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0xF400), (char *)config_jp_chr_0 + 0x400, 4);
        tilemap_chunk_copy_16b((short *)(SS_RAM + 0x9C00), (char *)config_jp_chr_0 + 0x480, 4);
        tilemap_print_script_seq(0, 0, 0xFFFF, config_top_scr_jp);
    }
}



/* provisional name */
void config_top_select(void) {
    if (Area_Type) {
        cfg_top_cursor = menu_cursor_vtick(16, 6, 3, cfg_top_cursor, 0);
    } else {
        cfg_top_cursor = menu_cursor_vtick(6, 4, 3, cfg_top_cursor, 0);
    }
    config_top_item_tbl[cfg_top_cursor]();
    if (config_differs_from_default()) {
        if (Area_Type) {
            tilemap_rect_fill(18, 10, 10, 1, 8, 0xFFFF);
        } else {
            tilemap_rect_fill(8, 8, 34, 2, 8, 0xFFFF);
        }
    } else {
        if (Area_Type) {
            tilemap_rect_fill(18, 10, 10, 1, 2, 0xFFFF);
        } else {
            tilemap_rect_fill(8, 8, 34, 2, 2, 0xFFFF);
        }
    }
}



/* provisional name */
void config_top_system(void) {
    u16 trig;
    trig = ~p1sw_1 & p1sw_0;
    if (trig & 0x10) {
        Config_No_1 = 1;
        Config_No_2 = 0;
    } else if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, config_top_guide_scr);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, cfg_top_guide_jp);
    }
}



/* provisional name */
void config_top_game(void) {
    u16 trig;
    trig = ~p1sw_1 & p1sw_0;
    if (trig & 0x10) {
        Config_No_1 = 2;
        Config_No_2 = 0;
    } else if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, config_top_guide_scr);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, cfg_top_guide_jp);
    }
}



/* provisional name */
void config_top_default(void) {
    register s8 ix;
    u32 table;
    u32 p;
    s8* dst;
    if ((p1sw_0 & 0x30) == 0x30 && (p1sw_1 & 0x30) != 0x30) {
        table = sys_cfg_default_tbl[Cabinet_Type];
        if (Area_Type != 0) {
            ix = Area_Type;
        } else if (Area_Alt_Flag != 0) {
            ix = 6;
        } else {
            ix = Area_Type;
        }
        p = *(u32*)(table + ix * 4);
        cfg_coin = *(u8*)(p + 1);
        cfg_continue = *(u8*)(p + 2);
        cfg_chute = *(u8*)(p + 3);
        cfg_sound_mode = *(u8*)(p + 4);
        cfg_voice = *(u8*)(p + 9);
        Monitor_Flip = *(u8*)(p + 6);
        cfg_demo_sound = *(u8*)(p + 5);
        cfg_coin_special = Free_Play;
        cfg_dispenser = *(u8*)(p + 10);
        cfg_win_point = *(u8*)(p + 11);
        cfg_win_point_vs = *(u8*)(p + 12);
        cfg_extra = *(u8*)(p + 13);
        if (Coin_Mode == 17) {
            cfg_free_play = 1;
            cfg_continue = 1;
        } else {
            cfg_free_play = 0;
        }
        p = (u32)game_cfg_default_tbl[ix];
        dst = (s8 *)&game_config_work;
        for (ix = 0; ix < 16; ix++) {
            *dst = *(s8*)p;
            dst++;
            p++;
        }
        game_config_apply();
        Config_No_1 = 0;
        Config_No_2 = 0;
    }
    if (Area_Type != 0) {
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)config_reset_guide_scr);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)cfg_top_guide_jp);
        tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)cfg_top_reset_guide_jp);
    }
}

/* provisional name */
u32 config_top_save_exit(void)
{
    s32 i;
    s8 *src;
    s8 *dst;
    u32 ret;
    if ((~p1sw_1 & p1sw_0 & 0x10) == 0) {
        if (!Area_Type) {
            return ((s32 (*)())tilemap_print_script_seq)(0, 0, 0xFFFF, cfg_top_guide_jp);
        }
        return ((s32 (*)())tilemap_print_string)(0, 0, 0xFFFF, config_top_guide_scr);
    }
    config_check_changed();
    Free_Play = cfg_coin_special;
    Two_Coin_Start = cfg_free_play;
    Coin_Mode = cfg_coin;
    Chute_Mode = cfg_chute;
    Continue_Flag = cfg_continue;
    cfg_flip_old = Monitor_Flip;
    Demo_Sound = cfg_demo_sound;
    Sound_Mode = cfg_sound_mode;
    Language = cfg_voice;
    Card_Dispenser = cfg_dispenser;
    Win_Point_Com = cfg_win_point;
    Win_Point_Human = cfg_win_point_vs;
    Voice_Type = cfg_extra;
    src = (s8 *)&game_config_work;
    dst = (s8 *)&Game_setting;
    for (i = 0; i < 16; i++) {
        *dst = *src;
        src++;
        dst++;
    }
    coin_chute1_w[2] = coin_rate_tbl[Coin_Mode][0];
    coin_chute1_w[3] = coin_rate_tbl[Coin_Mode][1];
    coin_chute2_w[2] = coin_rate_tbl[Coin_Mode][0];
    coin_chute2_w[3] = coin_rate_tbl[Coin_Mode][1];
    coin3_coin_rate = coin_rate_tbl[Coin_Mode][0];
    coin3_credit_rate = coin_rate_tbl[Coin_Mode][1];
    coin4_coin_rate = coin_rate_tbl[Coin_Mode][0];
    coin4_credit_rate = coin_rate_tbl[Coin_Mode][1];
    if (Coin_Mode == 17) {
        Two_Coin_Start = 1;
        Continue_Flag = 1;
    } else {
        Two_Coin_Start = 0;
    }
    ret = 0;
    if (cfg_changed != 0) {
        if (!Area_Type) {
            tilemap_chunk_copy_16b((s16 *)(SS_RAM + 0x8000), (char *)sys_font_cg, 140);
        }
        tilemap_fill_all(0, 0x20);
        tilemap_print_string(0, 0, 0xFFFF, config_saving_scr);
        task_sleep(1);
        eeprom_config_save();
        task_sleep(1);
        ret = ((s32 (*)())tilemap_fill_all)(0, 0x20);
    }
    cfg_reserve = 1;
    return ret;
}

/* provisional name */
u32 sysconfig_page(void)
{
    s32 (**page_tbl)();
    page_tbl = sysconfig_step_tbl;
    return page_tbl[Config_No_2]();
}



/* provisional name */
void sysconfig_draw(void) {
    Config_No_2++;
    cfg_cursor = 0;
    cfg_cursor_old = 0;
    cfg_coin_step = 0;
    if (Area_Type) {
        tilemap_fill_all(0, 32);
    } else {
        tilemap_fill_all(0, 0x1200);
    }
    task_sleep(1);
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_scr);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_page_scr_jp);
    }
    switch (Area_Type) {
    case 0:
        cfg_item_max = 6;
        break;
    case 2:
    case 8:
        cfg_item_max = 6;
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_exit_scr);
        break;
    case 3:
    case 4:
        if (Win_Point_Split == 0) {
            cfg_item_max = 8;
            tilemap_print_string(0, 0, 0xFFFF, sysconfig_dispenser_scr);
        } else {
            cfg_item_max = 9;
            tilemap_print_string(0, 0, 0xFFFF, sysconfig_winpoint_scr);
        }
        break;
    case 5:
        cfg_item_max = 6;
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_exit_scr);
        break;
    default:
        cfg_item_max = 6;
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_exit_scr);
        break;
    }
}



/* provisional name */
void sysconfig_select(void) {
    if (Area_Type != 0) {
        cfg_cursor = menu_cursor_vtick(1, 5, cfg_item_max, cfg_cursor, 1);
    } else {
        cfg_cursor = menu_cursor_vtick(2, 4, cfg_item_max, cfg_cursor, 1);
    }
    if (cfg_cursor != cfg_cursor_old) {
        if (cfg_cursor == 2 && (cfg_coin == 17 || event_off_flag == 0)) {
            if (cfg_cursor > cfg_cursor_old) {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor++;
            } else {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor--;
            }
            if (Area_Type == 0) {
                menu_cursor_redraw(2, 4, cfg_cursor, cfg_cursor_old);
            } else {
                menu_cursor_redraw(1, 5, cfg_cursor, cfg_cursor_old);
            }
        }
        if (cfg_cursor == 7 && (Area_Type == 3 || Area_Type == 4) && cfg_dispenser == 0) {
            if (cfg_cursor > cfg_cursor_old) {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor++;
                if (Win_Point_Split != 0) {
                    cfg_cursor++;
                }
            } else {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor--;
            }
            if (Area_Type == 0) {
                menu_cursor_redraw(2, 4, cfg_cursor, cfg_cursor_old);
            } else {
                menu_cursor_redraw(1, 5, cfg_cursor, cfg_cursor_old);
            }
        }
        if (cfg_cursor == 8 && (Area_Type == 3 || Area_Type == 4) && cfg_dispenser == 0) {
            if (cfg_cursor > cfg_cursor_old) {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor++;
            } else {
                cfg_cursor_old = cfg_cursor;
                cfg_cursor--;
                if (Win_Point_Split != 0) {
                    cfg_cursor--;
                }
            }
            if (Area_Type == 0) {
                menu_cursor_redraw(2, 4, cfg_cursor, cfg_cursor_old);
            } else {
                menu_cursor_redraw(1, 5, cfg_cursor, cfg_cursor_old);
            }
        }
        cfg_cursor_old = cfg_cursor;
        if (cfg_cursor == 0) {
            cfg_coin_step = 0;
        }
    }
    switch (Area_Type) {
    case 2:
    case 8:
        sysconfig_item_tbl_c[cfg_cursor]();
        break;
    case 3:
    case 4:
        if (Win_Point_Split == 0) {
            sysconfig_item_card_tbl[cfg_cursor]();
        } else {
            sysconfig_item_card_tbl2[cfg_cursor]();
        }
        break;
    case 5:
        sysconfig_item_tbl_b[cfg_cursor]();
        break;
    default:
        sysconfig_item_tbl[cfg_cursor]();
        break;
    }
    sysconfig_draw_values();
}



/* provisional name */
void sysconfig_coin(void) {
    register s8 step;
    switch (cfg_coin_step) {
    case 0:
        cfg_coin_step++;
        cfg_coin_sel = cfg_coin;
        if (cfg_coin_sel == 9) {
            if (Area_Type == 3) {
                cfg_coin_sel = 2;
            } else if (Area_Type == 4) {
                cfg_coin_sel = 3;
            }
        }
    case 1:
    default:
        cfg_coin_special = 0;
        if (Area_Type == 3) {
            step = config_modify_step();
            cfg_coin_sel += step;
            if (cfg_coin_sel < 0) {
                cfg_coin_sel = 2;
            }
            if (cfg_coin_sel >= 3) {
                cfg_coin_sel = 0;
            }
            if (cfg_coin_sel == 2) {
                cfg_coin = 9;
            } else {
                cfg_coin = cfg_coin_sel;
            }
        } else if (Area_Type == 4) {
            step = config_modify_step();
            cfg_coin_sel += step;
            if (cfg_coin_sel < 0) {
                cfg_coin_sel = 3;
            }
            if (cfg_coin_sel >= 4) {
                cfg_coin_sel = 0;
            }
            if (cfg_coin_sel == 3) {
                cfg_coin = 9;
            } else {
                cfg_coin = cfg_coin_sel;
            }
        } else {
            if (Free_Play_Enable != 0) {
                step = config_modify_step();
                cfg_coin += step;
                if (event_off_flag != 0) {
                    if (cfg_coin < 0) {
                        cfg_coin = 18;
                    }
                    if (cfg_coin >= 19) {
                        cfg_coin = 0;
                    }
                } else {
                    if (cfg_coin == 17) {
                        if (step == 1) {
                            cfg_coin = 18;
                        } else if (step == -1) {
                            cfg_coin = 16;
                        }
                    }
                    if (cfg_coin < 0) {
                        cfg_coin = 18;
                    }
                    if (cfg_coin >= 19) {
                        cfg_coin = 0;
                    }
                }
            } else {
                step = config_modify_step();
                cfg_coin += step;
                if (event_off_flag != 0) {
                    if (cfg_coin < 0) {
                        cfg_coin = 17;
                    }
                    if (cfg_coin >= 18) {
                        cfg_coin = 0;
                    }
                } else {
                    if (cfg_coin < 0) {
                        cfg_coin = 16;
                    }
                    if (cfg_coin >= 17) {
                        cfg_coin = 0;
                    }
                }
            }
            if (cfg_coin == 17) {
                if (cfg_continue == 0) {
                    cfg_cont_forced = 1;
                    cfg_continue = 1;
                }
            } else if (Free_Play_Enable != 0 && cfg_coin == 18) {
                cfg_coin_special = 1;
                cfg_cont_forced = 0;
            } else if (cfg_cont_forced != 0) {
                cfg_cont_forced = 0;
                cfg_continue = 0;
            }
        }
        break;
    }
    if (Area_Type != 0) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_chute_mode(void) {
    register s8 step;
    step = config_modify_step();
    cfg_chute += step;
    switch (Cabinet_Type) {
    case 0:
        if (cfg_chute < 0) {
            cfg_chute = 2;
        } else if (cfg_chute >= 3) {
            cfg_chute = 0;
        }
        break;
    case 1:
        if (cfg_chute < 3) {
            cfg_chute = 6;
        } else if (cfg_chute >= 7) {
            cfg_chute = 3;
        }
        break;
    case 2:
        if (cfg_chute < 7) {
            cfg_chute = 11;
        } else if (cfg_chute >= 12) {
            cfg_chute = 7;
        }
        break;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_continue(void) {
    if (cfg_coin != 17 && event_off_flag != 0 && config_modify_step()) {
        cfg_continue ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_monitor(void) {
    if (config_modify_step()) {
        Monitor_Flip ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_demo_sound(void) {
    if (config_modify_step()) {
        cfg_demo_sound ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_sound_mode(void) {
    if (config_modify_step()) {
        cfg_sound_mode ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_language(void) {
    register s8 step;
    step = config_modify_step();
    cfg_voice += step;
    if (cfg_voice < 0) {
        cfg_voice = 1;
    } else if (cfg_voice > 1) {
        cfg_voice = 0;
    }
    tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_dispenser(void) {
    if (config_modify_step()) {
        cfg_dispenser ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_win_point(void) {
    register s8 step;
    step = config_modify_step();
    cfg_win_point += step;
    if (cfg_win_point < Win_Point_Com_Min) {
        cfg_win_point = Win_Point_Com_Max;
    } else if (cfg_win_point > Win_Point_Com_Max) {
        cfg_win_point = Win_Point_Com_Min;
    }
    if (Win_Point_Split == 0) {
        tilemap_print_hex_block(18, 19, 2, hex_to_bcd(cfg_win_point), 2, 1);
    } else {
        tilemap_print_hex_block(25, 19, 2, hex_to_bcd(cfg_win_point), 2, 1);
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_win_point_human(void) {
    register s8 step;
    step = config_modify_step();
    cfg_win_point_vs += step;
    if (cfg_win_point_vs < Win_Point_Human_Min) {
        cfg_win_point_vs = Win_Point_Human_Max;
    } else if (cfg_win_point_vs > Win_Point_Human_Max) {
        cfg_win_point_vs = Win_Point_Human_Min;
    }
    tilemap_print_hex_block(25, 21, 2, hex_to_bcd(cfg_win_point_vs), 2, 1);
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_voice_type_toggle(void) {
    if (config_modify_step()) {
        cfg_extra ^= 1;
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
    if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_modify_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_item_guide_jp);
    }
}



/* provisional name */
void sysconfig_exit(void) {
    u16 trig;
    trig = ~p1sw_1 & p1sw_0;
    if (trig & 0x10) {
        Config_No_1 = 0;
        Config_No_2 = 0;
    } else if (Area_Type) {
        tilemap_print_string(0, 0, 0xFFFF, sysconfig_return_guide);
    } else {
        tilemap_print_script_seq(0, 0, 0xFFFF, sys_cfg_exit_guide_jp);
    }
}



/* provisional name */
void gameconfig_page(void) {
    u32 p;
    u32 table;
    s32 ix;
    switch (game_config_main()) {
    case 1:
        Config_No_1 = 0;
        Config_No_2 = 0;
        game_config_apply();
        if (event_off_flag == 0) {
            if (cfg_coin == 17) {
                table = sys_cfg_default_tbl[Cabinet_Type];
                if (Area_Type) {
                    ix = Area_Type;
                } else if (Area_Alt_Flag) {
                    ix = 6;
                } else {
                    ix = Area_Type;
                }
                p = *(u32*)(table + ix * 4);
                cfg_coin = *(u8*)(p + 1);
            }
            cfg_continue = 0;
        }
    case 0:
        break;
    }
}



/* provisional name */
void sysconfig_draw_values(void) {
    s16 attr;
    attr = 2;
    if (cfg_coin != Coin_Mode) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(coin_setting_str_tbl[cfg_coin], 5, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_coin_scr_jp[cfg_coin]);
    }
    attr = 2;
    if (cfg_chute != Chute_Mode) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(chute_mode_str_tbl[cfg_chute], 7, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_chute_scr_jp[cfg_chute]);
    }
    attr = 2;
    if (cfg_continue != Continue_Flag) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(on_off_str_tbl[cfg_continue], 9, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_continue_scr_jp[cfg_continue]);
    }
    attr = 2;
    if (Monitor_Flip != eeprom_saved_flip) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(monitor_str_tbl[Monitor_Flip], 11, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_monitor_scr_jp[Monitor_Flip]);
    }
    attr = 2;
    if (cfg_demo_sound != Demo_Sound) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(on_off_str_tbl[cfg_demo_sound], 13, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_demo_scr_jp[cfg_demo_sound]);
    }
    attr = 2;
    if (cfg_sound_mode != Sound_Mode) {
        attr = 8;
    }
    if (Area_Type) {
        config_print_setting(sound_mode_str_tbl[cfg_sound_mode], 15, attr);
    } else {
        tilemap_print_script_seq(0, 0, attr, sys_cfg_sound_scr_jp[cfg_sound_mode]);
    }
    if (Area_Type == 5) {
    }
    if (Area_Type == 3 || Area_Type == 4) {
        attr = 2;
        if (cfg_dispenser != Card_Dispenser) {
            attr = 8;
        }
        config_print_setting(on_off_str_tbl[cfg_dispenser], 17, attr);
        if (Win_Point_Split == 0) {
            attr = 2;
            if (cfg_win_point != Win_Point_Com) {
                attr = 8;
            }
            tilemap_print_hex_block(18, 19, attr, hex_to_bcd(cfg_win_point), 2, 2);
        } else {
            attr = 2;
            if (cfg_win_point != Win_Point_Com) {
                attr = 8;
            }
            tilemap_print_hex_block(25, 19, attr, hex_to_bcd(cfg_win_point), 2, 2);
            attr = 2;
            if (cfg_win_point_vs != Win_Point_Human) {
                attr = 8;
            }
            tilemap_print_hex_block(25, 21, attr, hex_to_bcd(cfg_win_point_vs), 2, 2);
        }
    }
    if (Area_Type == 2 || Area_Type == 8) {
    }
}



/* provisional name */
void config_print_setting(const TM_STRING* src, s32 y, s16 attr) {
    TM_STRING e;
    e.x = src->x;
    e.y = y;
    e.attr = attr;
    e.str = src->str;
    tilemap_print_string(0, 0, 0xFFFF, &e);
}



/* provisional name */
void test_menu_print_script_at(const void* script, s16 x, s16 y) {
    tilemap_print_script_seq(0, x, y, script);
}



/* provisional name */
void config_check_changed(void) {
    register s8 i;
    s8* saved;
    s8* edited;
    s32 unused[4];
    cfg_changed = 0;
    if (cfg_coin != Coin_Mode) {
        cfg_changed = 1;
    } else if (cfg_chute != Chute_Mode) {
        cfg_changed = 1;
    } else if (cfg_continue != Continue_Flag) {
        cfg_changed = 1;
    } else if (cfg_flip_old != Monitor_Flip) {
        cfg_changed = 1;
    } else if (cfg_demo_sound != Demo_Sound) {
        cfg_changed = 1;
    } else if (cfg_sound_mode != Sound_Mode) {
        cfg_changed = 1;
    } else if (cfg_voice != Language) {
        cfg_changed = 1;
    } else if (cfg_dispenser != ((s8)Card_Dispenser)) {
        cfg_changed = 1;
    } else if (cfg_win_point != Win_Point_Com) {
        cfg_changed = 1;
    } else if (cfg_win_point_vs != Win_Point_Human) {
        cfg_changed = 1;
    } else if (cfg_extra != Voice_Type) {
        cfg_changed = 1;
    }
    saved = (s8 *)&game_config_work;
    edited = (s8 *)&Game_setting;
    for (i = 0; i < 8; i++) {
        if (*edited != *saved) {
            cfg_changed = 1;
        }
        edited++;
        saved++;
    }
}



/* provisional name */
s32 config_differs_from_default(void) {
    register s8 ix;
    u32 table;
    u32 p;
    s8* name;
    s32 result;
    result = 0;
    table = sys_cfg_default_tbl[Cabinet_Type];
    if (Area_Type) {
        ix = Area_Type;
    } else if (Area_Alt_Flag) {
        ix = 6;
    } else {
        ix = Area_Type;
    }
    p = *(u32*)(table + ix * 4);
    if (*(u8*)(p + 1) != cfg_coin) {
        result = -1;
    } else if (*(u8*)(p + 2) != cfg_continue) {
        result = -1;
    } else if (*(u8*)(p + 3) != cfg_chute) {
        result = -1;
    } else if (*(u8*)(p + 4) != cfg_sound_mode) {
        result = -1;
    } else if (*(u8*)(p + 5) != cfg_demo_sound) {
        result = -1;
    } else if (*(u8*)(p + 6) != Monitor_Flip) {
        result = -1;
    } else if (*(u8*)(p + 9) != cfg_voice) {
        result = -1;
    } else if (*(u8*)(p + 10) != cfg_dispenser) {
        result = -1;
    } else if (*(u8*)(p + 11) != cfg_win_point) {
        result = -1;
    } else if (*(u8*)(p + 12) != cfg_win_point_vs) {
        result = -1;
    } else if (*(u8*)(p + 13) != cfg_extra) {
        result = -1;
    }
    p = (u32)game_cfg_default_tbl[ix];
    name = (s8 *)&game_config_work;
    for (ix = 0; ix < 8; ix++) {
        if (*name != *(s8*)p) {
            result = -1;
        }
        name++;
        p++;
    }
    return result;
}



/* provisional name */
s8 config_modify_step(void) {
    u16 trig;
    s8 step;
    trig = ~p1sw_1 & p1sw_0;
    step = 0;
    if (trig & 0xC) {
        if (trig & 8) {
            step = 1;
        } else {
            step = -1;
        }
    }
    if (trig & 0x10) {
        step = 1;
    }
    if (trig & 0x20) {
        step = -1;
    }
    return step;
}



/* provisional name */
s8 menu_cursor_vtick(s32 x, s32 y, s8 last, s8 row, s8 wrap) {
    u16 trig;
    s32 off;
    trig = ~p1sw_1 & p1sw_0;
    if (trig & 3) {
        if (trig & 2) {
            off = row * 2;
            if (Area_Type) {
                tilemap_print_string_attr(x, y + off, 2, cursor_blank_str);
            } else {
                if (wrap) {
                    if (row == last) {
                        off += 2;
                    }
                } else {
                    if (row == last) {
                        off += 2;
                    }
                }
                tilemap_put_block(x, y + off, 2, 0x1200);
            }
            row++;
            if (wrap) {
                if (row > last) {
                    row = 0;
                }
            } else {
                if (row > last) {
                    row = 0;
                }
            }
        } else {
            off = row * 2;
            if (Area_Type) {
                tilemap_print_string_attr(x, y + off, 2, cursor_blank_str);
            } else {
                if (wrap) {
                    if (row == last) {
                        off += 2;
                    }
                } else {
                    if (row == last) {
                        off += 2;
                    }
                }
                tilemap_put_block(x, y + off, 2, 0x1200);
            }
            row--;
            if (wrap) {
                if (row < 0) {
                    row = last;
                }
            } else {
                if (row < 0) {
                    row = last;
                }
            }
        }
    }
    off = row * 2;
    if (Area_Type) {
        tilemap_print_string_attr(x, y + off, 2, cursor_mark_str);
    } else {
        if (wrap) {
            if (row == last) {
                off += 2;
            }
        } else {
            if (row == last) {
                off += 2;
            }
        }
        tilemap_put_block(x, y + off, 2, 0x1204);
    }
    return row;
}



/* provisional name */
void menu_cursor_redraw(s32 x, s32 y, s32 cur, s32 old) {
    s32 off;
    off = old * 2;
    if (Area_Type) {
        tilemap_print_string_attr(x, y + off, 2, cursor_blank_str);
    } else {
        tilemap_put_block(x, y + off, 2, 0x1200);
    }
    off = cur * 2;
    if (Area_Type) {
        tilemap_print_string_attr(x, y + off, 2, cursor_mark_str);
    } else {
        tilemap_put_block(x, y + off, 2, 0x1204);
    }
}



/* provisional name */
void config_menu_load_settings(void) {
    s32 i;
    u32 table;
    u32 dst;
    s8* src;
    cfg_top_cursor = 0;
    cfg_cont_forced = 0;
    cfg_reserve = 0;
    cfg_coin_special = Free_Play;
    cfg_coin = Coin_Mode;
    cfg_continue = Continue_Flag;
    cfg_free_play = Two_Coin_Start;
    cfg_sound_mode = Sound_Mode;
    cfg_voice = Language;
    cfg_flip_old = Monitor_Flip;
    cfg_demo_sound = Demo_Sound;
    cfg_chute = Chute_Mode;
    cfg_dispenser = ((s8)Card_Dispenser);
    cfg_win_point = Win_Point_Com;
    cfg_win_point_vs = Win_Point_Human;
    cfg_extra = Voice_Type;
    dst = (u32)&game_config_work;
    src = (s8 *)&Game_setting;
    for (i = 0; i < 16; i++) {
        *(u8*)dst = *src;
        dst++;
        src++;
    }
    game_config_apply();
    if (event_off_flag == 0) {
        if (cfg_coin == 17) {
            table = sys_cfg_default_tbl[Cabinet_Type];
            if (Area_Type) {
                i = Area_Type;
            } else if (Area_Alt_Flag) {
                i = 6;
            } else {
                i = Area_Type;
            }
            dst = *(u32*)(table + i * 4);
            cfg_coin = *(u8*)(dst + 1);
        }
        cfg_continue = 0;
    }
}



/* provisional name */
void init_render_lists(void) {
    s32 unused;
    sprite_template_pool_init();
    cram_bank_init();
    sprite_pools_init();
    simmram_freelist_init();
    simmram_freelist_init_10();
    render_list_primary_alloc();
    poly_queue_init(simmram_slot_to_offset(simmram_block_alloc_10(2, 0)));
    sprite_template_chain_init();
    sprite_list_clear(0);
    sprite_list_clear(1);
    sprite_list_clear(2);
    sprite_list_clear(3);
}



/* provisional name */
void render_list_primary_alloc(void) {
    u16* p;
    s32 i;
    p = (u16*)(simmram_slot_to_offset(simmram_block_alloc_10(1, 0)) + CHARACTER_RAM);
    for (i = 0; i < 0x800; i++) {
        *p = 0;
        p++;
    }
}



/* provisional name */
void sprite_template_pool_init(void) {
    s32 unused;
    s32 i;
    u16* p;
    p = (u16*)SPRITE_RAM;
    *p = 16;
    p++;
    *p = sprite_dummy_code;
    p++;
    *p = sprite_head_x;
    p++;
    *p = sprite_head_y;
    p++;
    *p = 0;
    p++;
    *p = 0;
    p += 3;
    for (i = 0; i < 22; i++) {
        *p = 16;
        p++;
        *p = sprite_dummy_code;
        p++;
        *p = sprite_pad_x;
        p++;
        *p = sprite_pad_y;
        p++;
        *p = 0;
        p++;
        *p = 0;
        p += 3;
    }
    *p = 0x8000;
    dma_src_ack_seq();
    sprite_dma_end_wait();
}



/* provisional name */
void sprite_template_chain_init(void) {
    s32 i;
    u16 slot;
    u16 link;
    u16* p;
    slot = simmram_block_alloc_40(1, 0);
    if (slot == 0) {
        return;
    }
    sprite_dummy_code = simmram_slot_to_code(slot);
    p = (u16*)simmram_slot_addr(slot);
    link = 0x3FF;
    for (i = 0; i < 16; i++) {
        p[0] = 0;
        p[1] = 0x1FF;
        p[2] = 0x200;
        p[3] = link;
        p[4] = 0x0F0F;
        p[5] = 5;
        link = (link + 0xFFF0) & 0x3FF;
        p += 8;
    }
}

/* provisional name */
void dma_src_ack_seq(void)
{
    s32 unused;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 8;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 9;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 8;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 9;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 8;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 9;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 8;
    *(volatile u16 *)(VIDEO_REG + 0x82) = 9;
}

/* Called from the vertical blank interrupt: wait until the sprite DMA has
   finished, then clear the DMA control register. */
/* provisional name */
void sprite_dma_end_wait(void)
{
    while (*(volatile u16 *)(VIDEO_REG + 0xC) & 1) {
    }
    *(volatile u16 *)(VIDEO_REG + 0x82) = 0;
}
