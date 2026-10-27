/*
 * EFF14.C  Background colour-cycle writer (effect 14)
 *
 * Animates part of a stage's scroll map by rewriting the palette bits of a rectangle of
 * map cells on a timed script, giving blinking lights and similar colour animation.
 * effect_14_init(id) allocates the work; effect_14_move loads the script, pattern mask and
 * target offset for that id from eff14_data_tbl/eff14_ofs_tbl, follows the scroll page
 * when it changes, and on each script step calls effect_14_write to patch the cell
 * attributes (1 = recolour, 2 = end of row). Scripts loop when they reach a -1 timer.
 * Started from the BG000-series, BG180, BG140 and BG190 stage init routines.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "ta_sub.h"
#include "eff14.h"

/* routine_no[0] */
#define R0_INIT         0       /* load the script for this id */
#define R0_MOVE         1       /* step the script, follow the page */
#define R0_KILL         2       /* put the work back */

E14_WORK eff14_work[8];  /* 02068AC8 */


static void effect_14_write(WORK_Other* ewk);



s32 effect_14_init(id, x, y, atr)
    s16 id;
    s16 x;
    s16 y;
    s16 atr;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 14;
    ewk->wu.work_id = 16;
    ewk->wu.type = id;
    return 0;
}



void effect_14_move(WORK_Other* ewk) {
    E14_SCR* scrn = (E14_SCR*)scrn_map_ptr;
    u32* data;
    u16* ofs;
    u32 scr;
    s8 put;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        data = eff14_data_tbl[ewk->wu.type];
        scr = *data;
        data++;
        ewk->wu.rl_flag = *data;
        data++;
        eff14_work[ewk->wu.rl_flag].scr = scr;
        eff14_work[ewk->wu.rl_flag].adrs = scrn[eff14_work[ewk->wu.rl_flag].scr].adrs;
        if (scrn_pos[eff14_work[ewk->wu.rl_flag].scr].cur_y.disp.pos < 0x200) {
            eff14_work[ewk->wu.rl_flag].adrs += 0x2000;
        }
        ofs = &eff14_ofs_tbl[ewk->wu.type];
        eff14_work[ewk->wu.rl_flag].dst = eff14_work[ewk->wu.rl_flag].adrs + *ofs;
        eff14_work[ewk->wu.rl_flag].row = eff14_work[ewk->wu.rl_flag].dst;
        eff14_work[ewk->wu.rl_flag].script_top = (s8*)*data;
        eff14_work[ewk->wu.rl_flag].script = (s8*)*data;
        data++;
        eff14_work[ewk->wu.rl_flag].pattern_top = *data;
        eff14_work[ewk->wu.rl_flag].pattern = (s8*)*data;
        data++;
        data = (u32*)*data;
        eff14_work[ewk->wu.rl_flag].cols = ((s8*)data)[0];
        eff14_work[ewk->wu.rl_flag].rows = ((s8*)data)[1];
        eff14_work[ewk->wu.rl_flag].timer = eff14_work[ewk->wu.rl_flag].script[1];
        eff14_work[ewk->wu.rl_flag].script += 2;
        eff14_work[ewk->wu.rl_flag].col = *(s16*)eff14_work[ewk->wu.rl_flag].script;
        eff14_work[ewk->wu.rl_flag].script += 2;
        ewk->wu.routine_no[0]++;
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (obr_no_disp_check() || EXE_flag || Game_pause || EXE_obroll) {
            break;
        }
        put = 0;
        if (eff14_work[ewk->wu.rl_flag].adrs != scrn[eff14_work[ewk->wu.rl_flag].scr].adrs) {
            eff14_work[ewk->wu.rl_flag].adrs = scrn[eff14_work[ewk->wu.rl_flag].scr].adrs;
            put = 1;
        }
        if (scrn_pos[eff14_work[ewk->wu.rl_flag].scr].cur_y.disp.pos < 0x200) {
            put = 1;
            eff14_work[ewk->wu.rl_flag].adrs += 0x2000;
        }
        ofs = &eff14_ofs_tbl[ewk->wu.type];
        eff14_work[ewk->wu.rl_flag].dst = *ofs + eff14_work[ewk->wu.rl_flag].adrs;
        eff14_work[ewk->wu.rl_flag].row = eff14_work[ewk->wu.rl_flag].dst;
        eff14_work[ewk->wu.rl_flag].timer--;
        if (eff14_work[ewk->wu.rl_flag].timer == 0) {
            eff14_work[ewk->wu.rl_flag].timer = eff14_work[ewk->wu.rl_flag].script[1];
            if (eff14_work[ewk->wu.rl_flag].timer == -1) {
                eff14_work[ewk->wu.rl_flag].script = eff14_work[ewk->wu.rl_flag].script_top;
                eff14_work[ewk->wu.rl_flag].timer = eff14_work[ewk->wu.rl_flag].script[1];
            }
            eff14_work[ewk->wu.rl_flag].script += 2;
            eff14_work[ewk->wu.rl_flag].col = *(s16*)eff14_work[ewk->wu.rl_flag].script;
            eff14_work[ewk->wu.rl_flag].script += 2;
            effect_14_write(ewk);
        } else if (put == 1) {
            effect_14_write(ewk);
        }
        break;
    case R0_KILL:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



static void eff14_flag_disp(s8 be_flag) {}

/* provisional name */
static void effect_14_write(WORK_Other* ewk) {
    s8* pattern;
    u16* dst;
    u32 row;
    volatile s16 col;
    volatile s8 rows;
    s8 cols;
    s16 i;
    s16 j;
    u16 mask;
    u16 v;
    (void)&((E14_WORK*)0)->rows;
    rows = eff14_work[ewk->wu.rl_flag].rows;
    mask = 0xFE00;
    cols = eff14_work[ewk->wu.rl_flag].cols;
    pattern = eff14_work[ewk->wu.rl_flag].pattern;
    dst = (u16*)eff14_work[ewk->wu.rl_flag].dst;
    col = eff14_work[ewk->wu.rl_flag].col;
    row = eff14_work[ewk->wu.rl_flag].row;
    eff14_flag_disp(ewk->wu.be_flag);
    i = 0;
    goto test;
loop:
    for (j = 0; j < cols; j++) {
        if (*pattern == 1) {
            dst++;
            v = *dst;
            v &= mask;
            v |= col;
            *dst = v;
            dst++;
            pattern++;
        } else if (*pattern == 2) {
            j = cols;
            pattern++;
        } else {
            dst += 2;
            pattern++;
        }
    }
    eff14_flag_disp(ewk->wu.be_flag);
    row = (u32)(dst = (u16*)(row + 0x100));
    (void)&((E14_WORK*)row)->rows;
    i++;
test:
    if (i < rows) {
        goto loop;
    }
    eff14_flag_disp(ewk->wu.be_flag);
}
