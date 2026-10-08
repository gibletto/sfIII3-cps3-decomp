/*
 * BG_SUB_4.C  Stage background subroutines: scrolling, zoom, family set, cell writers (part 4)
 *
 * Routines: suzi_line_calc2.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg_sub_2.h"
#include "bg_sub_4.h"

#pragma inline(remake_x_mvstep)



/* provisional name */
void suzi_line_calc2(s16 bg_num) {
    BGW* bgw;
    s32* line;
    u16* dst;
    u16* src;
    s16 dist;
    s16 i;
    if (bg_stop) {
        return;
    }
    if (bg_app_stop) {
        return;
    }
    bgw = &bg_w.bgw[bg_num];
    if ((bg_w.chase_flag & 0xF) == 0) {
        dist = bgw->wxy[0].disp.pos;
    } else {
        dist = bgw->chase_xy[0].disp.pos;
    }
    if (dist == bgw->old_pos_x) {
        return;
    }
    dist -= bgw->old_pos_x;
    line = (s32*)suzi_line_buf;
    if (dist < 0) {
        dist = -dist;
        suzi_calc_w[0] = bg_w.bgw[bg_num].zuubun * dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        suzi_calc_w[1] = suzi_calc_w[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line += suzi_calc_w[1];
            suzi_calc_w[1] -= suzi_calc_w[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    } else {
        suzi_calc_w[0] = bg_w.bgw[bg_num].zuubun * dist;
        dst = bg_w.bgw[bg_num].start_suzi;
        suzi_calc_w[1] = suzi_calc_w[0] * bg_w.bgw[bg_num].u_line;
        for (i = 0; i < bg_w.bgw[bg_num].u_line; i++) {
            *line -= suzi_calc_w[1];
            suzi_calc_w[1] -= suzi_calc_w[0];
            *dst = *(u16*)line;
            line++;
            dst += 2;
        }
    }
    src = bg_w.bgw[bg_num].suzi_adrs;
    dst = src;
    src += 1024;
    for (i = 0; i < 512; i++) {
        *dst = *src;
        dst += 2;
        src += 2;
    }
}


/* provisional name */
s32 bg_cell_offset(s16 x, s16 y) {
    return ((((0x400 - (y & 0x300) - (y & 0xF0)) & 0x3F0) << 4) + ((x & 0x3F0) >> 2)) >> 1;
}
