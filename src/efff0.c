/*
 * EFFF0.C  Alternate background controller (effect F0)
 *
 * Switches the stage display to a special full-screen background while either player's
 * another_bg request is set. effect_F0_move turns the stage layers off, chooses the BG3
 * source page from ake_scrl_w by request type, lowers sound register 0 while active,
 * tracks which player's request has priority, and on release restores the layers
 * (effF0_scroll_reset). effF0_scroll_set positions BG3 and family 4 from the scroll records
 * and BG1. seraph_flag tells other effects it is active; it yields to the finish screen.
 * effect_F0_init creates it together with two effect B6 objects.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "EFFB6.h"
#include "fifo.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "efff0.h"



void effect_F0_move(WORK_Other* ewk) {
    s16 i;
    if (akebono_flag) {
        seraph_flag = 0;
    } else {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            scrn_map_set_now(3, ake_scrl_w[0].adrs);
        case 1:
            seraph_flag = 0;
            if (!akebono_flag && !sa_pa_flag) {
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_On_W(1 << i);
                }
                Bg_Off_W(8);
            }
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_old = 0;
        case 2:
            if (!another_bg[0] && !another_bg[1]) {
                break;
            }
            ewk->wu.routine_no[0]++;
            if (another_bg[0] && another_bg[1]) {
                ewk->wu.type = 0;
            } else {
                if (another_bg[0]) {
                    ewk->wu.type = 0;
                } else {
                    ewk->wu.type = 1;
                }
            }
            seraph_flag = 1;
            break;
        case 3:
            ewk->wu.routine_no[0]++;
            for (i = 0; i < bg_w.scno; i++) {
                Bg_Off_W(1 << i);
            }
            Bg_Off_W(8);
            switch (another_bg[ewk->wu.type]) {
            case 1:
            case 4:
                ewk->wu.dir_old = 1;
                break;
            default:
                ewk->wu.dir_old = 0;
                break;
            }
            sound_reg_level_set(0, 0xF0);
        case 4:
            if (ewk->wu.type) {
                if (another_bg[0] && another_bg_old[0] == 0) {
                    ewk->wu.type = 0;
                }
            } else if (another_bg[1] && another_bg_old[1] == 0) {
                ewk->wu.type = 1;
            }
            if (ewk->wu.type) {
                if (!another_bg[1] && another_bg[0]) {
                    ewk->wu.type = 0;
                }
            } else if (!another_bg[0] && another_bg[1]) {
                ewk->wu.type = 1;
            }
            Bg_Off_W(8);
            switch (another_bg[ewk->wu.type]) {
            case 2:
            case 3:
                scrn_map_set(3, ake_scrl_w[3].adrs);
                break;
            case 4:
                if (!ewk->wu.dir_old) {
                    ewk->wu.dir_old = 1;
                }
                scrn_map_set(3, ake_scrl_w[4].adrs);
                break;
            default:
                if (!ewk->wu.dir_old) {
                    ewk->wu.dir_old = 1;
                }
                scrn_map_set(3, ake_scrl_w[0].adrs);
                break;
            }
            if (another_bg[0] || another_bg[1]) {
                seraph_flag = 1;
                effF0_scroll_set(ewk);
                break;
            }
            ewk->wu.routine_no[0] = 5;
            sound_reg_level_set(0, 0);
            another_bg_old[0] = another_bg_old[1] = 0;
            effF0_scroll_set(ewk);
            seraph_flag = 0;
            break;
        case 5:
            ewk->wu.routine_no[0] = 1;
            another_bg_old[0] = another_bg_old[1] = 0;
            effF0_scroll_reset(ewk);
            effF0_scroll_set(ewk);
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
    another_bg_old[0] = another_bg[0];
    another_bg_old[1] = another_bg[1];
}
