/*
 * COLOR3RD.C  Colour loads
 *
 * The colour transfer routines (load_any_color, load_bg_color, load_player_color, fade variants,
 * side/effect/option colours) send palette blocks from ROM tables to colour RAM through the transfer
 * queue.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
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
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "color3rd.h"
#include "cps3.h"

void init_color_trans_req(void)
{
    /* colour transfer request work: 256-byte request table and its three counters */
    col_trans_req_cnt0 = 0;
    col_trans_req_cnt1 = 0;
    col_trans_req_cnt2 = 0;
    memset(col_trans_req_tbl, 0, 256);
}



void load_any_color(ix)
u8 ix;
{
    const XFER* p = &any_color_tbl[ix];
    s32 zero = 0;
    polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
}



/* provisional name */
void load_bg_color(ix)
u8 ix;
{
    const XFER* p = &bg_color_tbl[ix];
    s32 zero = 0;
    polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
}

/* provisional name */
void load_bg_color_fade(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &bg_color_tbl[(u8)col_no];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r + 0x40, g + 0x40, b + 0x40);
}

/* provisional name */
void load_any_color_fade(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &any_color_tbl[(u8)col_no];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r + 0x40, g + 0x40, b + 0x40);
}

/* provisional name */
void load_any_color_attr(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &any_color_tbl[(u8)col_no];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r, g, b);
}

/* provisional name */
void load_any_color_req(col_no, r, g, b)
u16 col_no;
u8 r;
u8 g;
u8 b;
{
    const XFER *xfer = &any_color_tbl[(u8)col_no];

    polygon2d_queue_quad(xfer->src, xfer->dst, xfer->size, r, g, b);
}



/* provisional name */
void color_trans_dummy(void)
{
  return;
}

/* provisional name */
void color_dma_error_disp(void)
{
    if (col_trans_result == -1) {
        tilemap_print_string_attr(16, Text_Page_Y + 7, 18, "COLOR DMA ERROR");
    }
}



/* provisional name */
void load_player_color(a, b, c)
    u16 a;
    s16 b;
    s16 c;
{
    s32 zero;
    const XFER* p = player_color_tbl[a][b][c];
    s8 i;
    for (zero = i = 0; i < 14; i++, p++) {
        if (p->size) {
            col_trans_result = polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
        }
    }
}



void metamor_color_restore(u16 wkid) {
    s16 zero = 0;
    const u32* p = metamor_color_tbl[wkid][Player_Color[wkid]][0];
    col_trans_result = polygon2d_submit_quad(p[0], p[1], p[2], zero, zero, zero);
    col_trans_result = polygon2d_submit_quad(p[0], p[1] + 0x400, p[2], zero, zero, zero);
}
