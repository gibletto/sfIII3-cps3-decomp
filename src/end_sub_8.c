/*
 * END_SUB_8.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads (part 9)
 *
 * Routines: load_player_color_fade, load_char_eff_color, load_side_color, load_player_sub_color,
 * load_opt_color.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "vital_2.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Manage.h"
#include "manage_2.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "entry_2.h"
#include "meta_col.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "end_sub_8.h"
#include "cps3.h"

#pragma inline(card_pl_work_clear)



/* provisional name */
void load_player_color_fade(u16 a, s16 b, s16 c, u8 d, u8 e, u8 f) {
    const XFER* p = player_color_tbl[a][b][c];
    s8 i;
    for (i = 0; i < 13; i++, p++) {
        col_trans_result = polygon2d_submit_quad(p->src, p->dst, p->size, d + 64, e + 64, f + 64);
    }
}



/* provisional name */
void load_char_eff_color(ix, slot)
u16 ix;
u16 slot;
{
    col_trans_result = polygon2d_submit_quad(char_eff_color_tbl[ix], slot * 0x400 + 0x2000, 0x400, 0, 0, 0);
}



/* provisional name */
void load_side_color(u8 side, u16 ix) {
    s16 zero = 0;
    if (side) {
        polygon2d_submit_quad(side_color_2p_tbl[ix].src, 0xF000, side_color_2p_tbl[ix].size, zero, zero, zero);
    } else {
        polygon2d_submit_quad(side_color_1p_tbl[ix].src, 0xE000, side_color_1p_tbl[ix].size, zero, zero, zero);
    }
}

/* provisional name */
void load_player_sub_color(void)
{
    polygon2d_submit_quad(Player_Color[0] * 0x300 + 0x03389900, 0x2E00, 0x300, 0, 0, 0);
    polygon2d_submit_quad(Player_Color[1] * 0x300 + 0x03389900, 0x3100, 0x300, 0, 0, 0);
}



/* provisional name */
void load_opt_color(u16 ix) {
    const u32* p = &opt_color_tbl[ix];
    if (*p != 0) {
        polygon2d_submit_quad(*p, 0x2980, 0x80, 0, 0, 0);
    }
}
