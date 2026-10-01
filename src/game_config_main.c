/*
 * game_config_main.c  Game configuration menu dispatch
 *
 * One routine called from gameconfig_page in the configuration test menu (sys_config.c).
 * For Country 1 it steps the Japanese-language settings screen through Setting_Tbl
 * (game_config_init_jp, then game_config_move_jp) and reports exit when Config_Exit_jp is
 * set; for the other regions it runs the English menu, game_config_menu_en. Returns 1 when the
 * operator leaves the page so the caller can apply and save the new settings.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CMD_MAIN.h"
#include "game_config_main.h"
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
#include "cps3.h"



/* provisional name */
s32 game_config_main(void) {
    void (*Setting_Tbl[2])() = { game_config_init_jp, game_config_move_jp };

    if (Country == 1) {
        Setting_Tbl[Config_No_2]();
        if (Config_Exit_jp) {
            return 1;
        }
        return 0;
    } else {
        if (game_config_menu_en()) {
            return 1;
        }
        return 0;
    }
}



s32 game_config_menu(void) {
    void (*Setting_Tbl[2])() = { game_config_init_jp, game_config_move_jp };
    if (Country == 1) {
        Setting_Tbl[Config_No_2]();
    } else {
        game_config_menu_en();
    }
    if (Config_Exit_jp) {
        return 1;
    }
    return 0;
}



/* provisional name */
