/*
 * BG100.C  Stage background BG100
 *
 * BG100 runs one frame of stage BG100: it moves bgw[1] and bgw[0] through their ROM jump
 * tables, then zoom check, display positions and family set. bg1000 dispatches the main
 * layer to bg1000_init00 or the common layer move; the init starts effects 23 and 29.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFF23.h"
#include "bg000.h"
#include "EFF29.h"
#include "bg100.h"



void BG100(void) {
    bgw_ptr = &bg_w.bgw[1];
    {
        BG_JMP2 bg1001_jmp;
        bg1001_jmp = bg1001_jmp_tbl;
        bg1001_jmp.f[bgw_ptr->r_no_0]();
    }
    bgw_ptr = &bg_w.bgw[0];
    {
        BG_JMP2 bg1000_jmp;
        bg1000_jmp = bg1000_jmp_tbl;
        bg1000_jmp.f[bgw_ptr->r_no_0]();
    }
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1000(void) {
    void (*bg0602_jmp[2])() = { bg1000_init00, bg_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



void bg1000_init00(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    effect_23_init();
    effect_29_init();
}
