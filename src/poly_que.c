/*
 * POLY_QUE.C  Polygon transfer queue and sprite lists
 *
 * poly_queue_init / poly_bank_flip set up the double-buffered transfer queue for the video DMA unit,
 * polygon2d_submit_line / _quad queue transfers (sending a request directly when the unit is idle) and
 * sprite_polygon_flush_queue drains the queue. sprite_list_setup / _submit / _clear keep the four fixed
 * sprite lists in SIMM RAM and add them to the sprite entry pools.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_config.h"
#include "cps3.h"

/* provisional name */
u32 simmram_slot_to_offset(s16 slot) {
    return (slot - 1) << 12;
}



/* provisional name */
u32 simmram_slot_to_cg_no(s16 n) {
    return (n + 0xFFFF) << 5;
}

/* provisional name */
void poly_queue_init(s32 offset) {
    s32 unused[2];
    if ((*(volatile u16*)(VIDEO_REG + 0xC)) & 6) {
        if ((*(volatile u16*)(VIDEO_REG + 0xC)) & 2) {
            while ((*(volatile u16*)(VIDEO_REG + 0xC)) & 2) {
            }
        } else {
            while ((*(volatile u16*)(VIDEO_REG + 0xC)) & 4) {
            }
        }
    }
    poly_dma_state = 0;
    poly_reserve0 = 0;
    poly_reserve1 = 0;
    if (offset != -1) {
        poly_cram_bank = (offset >> 20) & 7;
        poly_buf_offset = offset;
    }
    poly_wr_bank = 0;
    poly_rd_bank = 1;
    poly_line_cnt[0] = 0;
    poly_line_cnt[1] = 0;
    poly_quad_cnt[0] = 0;
    poly_quad_cnt[1] = 0;
    poly_line_rd[0] = 0;
    poly_line_rd[1] = 0;
    poly_quad_rd[0] = 0;
    poly_quad_rd[1] = 0;
    poly_order_pos[0] = 0;
    poly_order_pos[1] = 0;
    *(volatile u16*)IRQ10_ACK = 0;
}



/* provisional name */
void poly_bank_flip(void) {
    s32 mask;
    if (poly_line_cnt[poly_wr_bank] + poly_quad_cnt[poly_wr_bank] > 0) {
        if (poly_line_cnt[((u32)poly_rd_bank)] + poly_quad_cnt[((u32)poly_rd_bank)] == 0) {
            mask = _builtin_get_imask();
            _builtin_set_imask(15);
            poly_wr_bank++;
            poly_wr_bank &= 1;
            poly_rd_bank++;
            poly_rd_bank &= 1;
            poly_line_cnt[poly_wr_bank] = 0;
            poly_quad_cnt[poly_wr_bank] = 0;
            poly_line_rd[poly_wr_bank] = 0;
            poly_quad_rd[poly_wr_bank] = 0;
            poly_order_pos[poly_wr_bank] = 0;
            _builtin_set_imask(mask);
        }
    }
}



/* provisional name */
s32 polygon2d_submit_line(addr, y, x, kind)
    u32 addr;
    u32 y;
    u32 x;
    u8 kind;
{
    register POLY_LINE* line;
    if (poly_line_cnt[poly_wr_bank] >= 0x155) {
        return -1;
    }
    line = &poly_line_buf[poly_wr_bank][poly_line_cnt[poly_wr_bank]];
    if (kind) {
        if (kind == 3) {
            x = 127;
            y = 0;
        }
        kind++;
    }
    if (kind == 4) {
        line->w0 = (kind << 21) | (x & 0x1FFFFF);
    } else {
        line->w0 = (((x << 1) & 0x1FFFFF) | (kind << 21)) + 1;
    }
    line->w1 = (y >> 3) & 0x1FFFFF;
    line->w2 = addr & 0x3FFFFFF;
    poly_line_cnt[poly_wr_bank]++;
    poly_order_kind[poly_wr_bank][poly_order_pos[poly_wr_bank]] = 1;
    return 0;
}



/* provisional name */
s32 polygon2d_submit_quad(a, b, c, lo, hi, pri)
u32 a;
u32 b;
u32 c;
u16 lo;
u16 hi;
s16 pri;
{
    register POLYCMD* cmd;
    s32 unused;
    if ((*(volatile u16*)(VIDEO_REG + 0xC) & 6) || poly_dma_state != 0) {
        if (poly_quad_cnt[poly_wr_bank] >= 32) {
            return -1;
        }
        cmd = &poly_quad_buf[poly_wr_bank][poly_quad_cnt[poly_wr_bank]];
        cmd->a_lo = a >> 1;
        cmd->a_hi = ((a >> 1) & 0x7FF0000) >> 16;
        cmd->b_lo = b >> 1;
        cmd->b_hi = ((b >> 1) & 0x10000) >> 16;
        cmd->c_lo = c >> 1;
        cmd->c_hi = ((c >> 1) & 0x10000) >> 16;
        cmd->attr = (hi << 8 | lo) & 0x7F7F;
        cmd->pri = pri & 0x7F;
        poly_quad_cnt[poly_wr_bank]++;
        poly_order_kind[poly_wr_bank][poly_order_pos[poly_wr_bank]] = 2;
    } else {
        poly_dma_state = 3;
        *(volatile u16*)(VIDEO_REG + 0xA0) = ((a >> 1) & 0x7FF0000) >> 16;
        *(volatile u16*)(VIDEO_REG + 0xA2) = a >> 1;
        *(volatile u16*)(VIDEO_REG + 0xA4) = ((b >> 1) & 0x10000) >> 16;
        *(volatile u16*)(VIDEO_REG + 0xA6) = b >> 1;
        *(volatile u16*)(VIDEO_REG + 0xA8) = (hi << 8 | lo) & 0x7F7F;
        *(volatile u16*)(VIDEO_REG + 0xAA) = pri & 0x7F;
        *(volatile u16*)(VIDEO_REG + 0xAC) = c >> 1;
        *(volatile u16*)(VIDEO_REG + 0xAE) = ((c >> 1) & 0x10000) >> 16 | 2;
    }
    return 0;
}



/* provisional name */
s32 polygon2d_queue_quad(u32 a, u32 b, u32 c, u16 lo, u16 hi, s16 pri) {
    register POLYCMD* cmd;
    s32 unused;
    if (poly_quad_cnt[poly_wr_bank] >= 32) {
        return -1;
    }
    cmd = &poly_quad_buf[poly_wr_bank][poly_quad_cnt[poly_wr_bank]];
    cmd->a_lo = a >> 1;
    cmd->a_hi = ((a >> 1) & 0x7FF0000) >> 16;
    cmd->b_lo = b >> 1;
    cmd->b_hi = ((b >> 1) & 0x10000) >> 16;
    cmd->c_lo = c >> 1;
    cmd->c_hi = ((c >> 1) & 0x10000) >> 16;
    cmd->attr = (hi << 8 | lo) & 0x7F7F;
    cmd->pri = pri & 0x7F;
    poly_quad_cnt[poly_wr_bank]++;
    poly_order_kind[poly_wr_bank][poly_order_pos[poly_wr_bank]] = 2;
    return 0;
}

/* provisional name */
void sprite_poly_queue_drain_try(void)
{
    if ((*(volatile u16 *)(VIDEO_REG + 0xC) & 6) == 0 && poly_dma_state == 0) {
        if (poly_line_cnt[poly_rd_bank] > 0) {
            sprite_polygon_flush_queue(1);
        } else if (poly_quad_cnt[poly_rd_bank] > 0) {
            sprite_polygon_flush_queue(2);
        }
    }
}



/* Wait until the video DMA has finished with the sprite and polygon lists, then
   send the waiting polygon queue: the line queue if it holds entries, otherwise
   the quad queue.  A request in state 3 is simply dropped. */
/* provisional name */
void sprite_poly_queue_drain_wait(void)
{
    while (*(volatile u16 *)(VIDEO_REG + 0xC) & 6) {
    }
    switch (poly_dma_state) {
    case 1:
    case 2:
        poly_dma_state = 0;
        if (poly_line_cnt[poly_rd_bank] > 0) {
            sprite_polygon_flush_queue(1);
        } else if (poly_quad_cnt[poly_rd_bank] > 0) {
            sprite_polygon_flush_queue(2);
        }
        break;
    case 3:
        poly_dma_state = 0;
    case 0:
    default:
        break;
    }
}



/* provisional name */
void sprite_polygon_flush_queue(s32 kind) {
    union {
        POLY_LINE* line;
        POLYCMD* quad;
    } cmd;
    POLY_LINE* out;
    s32 i;
    s32 n;
    s32 unused;
    switch (kind) {
    case 1:
        if (poly_line_cnt[poly_rd_bank] > 0x155) {
            n = 0x155;
        } else {
            n = poly_line_cnt[poly_rd_bank];
        }
        out = (POLY_LINE*)((poly_buf_offset & 0xFFFFF) + CHARACTER_RAM);
        cram_bank_set(poly_cram_bank);
        for (i = 0; i < n; i++) {
            cmd.line = &poly_line_buf[poly_rd_bank][poly_line_rd[poly_rd_bank] + i];
            out[i].w0 = cmd.line->w0;
            out[i].w1 = cmd.line->w1;
            out[i].w2 = cmd.line->w2;
            poly_line_cnt[poly_rd_bank]--;
        }
        poly_line_rd[poly_rd_bank] += n;
        out[i].w0 = 0x01000000;
        out[i].w1 = 0;
        out[i].w2 = 0;
        *(volatile u16*)(VIDEO_REG + 0x96) = ((u32)out - CHARACTER_RAM) >> 2;
        *(volatile u16*)(VIDEO_REG + 0x98) = ((((u32)out - CHARACTER_RAM) >> 18) & 63) | 64;
        cram_bank_restore();
        break;
    case 2:
        cmd.quad = &poly_quad_buf[poly_rd_bank][poly_quad_rd[poly_rd_bank]];
        poly_dma_state = 2;
        *(volatile u16*)(VIDEO_REG + 0xA0) = cmd.quad->a_hi;
        *(volatile u16*)(VIDEO_REG + 0xA2) = cmd.quad->a_lo;
        *(volatile u16*)(VIDEO_REG + 0xA4) = cmd.quad->b_hi;
        *(volatile u16*)(VIDEO_REG + 0xA6) = cmd.quad->b_lo;
        *(volatile u16*)(VIDEO_REG + 0xA8) = cmd.quad->attr;
        *(volatile u16*)(VIDEO_REG + 0xAA) = cmd.quad->pri;
        *(volatile u16*)(VIDEO_REG + 0xAC) = cmd.quad->c_lo;
        *(volatile u16*)(VIDEO_REG + 0xAE) = cmd.quad->c_hi | 2;
        poly_quad_cnt[poly_rd_bank]--;
        poly_quad_rd[poly_rd_bank]++;
        break;
    }
}



/* provisional name */
s32 sprite_list_setup(s16 slot, s16 owner, s16* data) {
    s16 n_grp;
    s16 n_ent;
    s16* p;
    SPRITE_ENTRY* g;
    SPRENTRY* e;
    n_grp = 0;
    n_ent = 0;
    p = data;
    while (*p != -1) {
        p += 2;
        n_grp++;
        while (*p != -1) {
            n_ent++;
            p += 3;
        }
        p++;
    }
    if ((sprite_list_w[slot].count = n_grp) == 0) {
        return 0;
    }
    if (n_ent == 0) {
        return 0;
    }
    if ((sprite_list_w[slot].slot = simmram_block_alloc_40(n_ent / 16 + 1, owner)) == 0) {
        return 0;
    }
    e = ((SPRENTRY *(*)(s16 handle))simmram_slot_addr)(sprite_list_w[slot].slot);
    n_grp = 0;
    while (*data != -1) {
        g = &sprite_list_w[slot].rec[n_grp];
        g->w0 = (*data & 7) << 12;
        data++;
        g->prio = *data;
        data++;
        g->w4 = 0;
        g->w6 = 0;
        g->w2 = ((s32)e - SPRITE_RAM) / 16;
        g->flag = 1;
        n_grp++;
        while (*data != -1) {
            g->w0++;
            e->w0 = 0;
            e->w2 = 0;
            e->w4 = 0;
            e->code = *data;
            data++;
            e->pos = *data;
            data++;
            e->attr = (slot & 3) * 16 | (*data & 0xF);
            data++;
            e++;
        }
        data++;
    }
    if (sprite_list_submit(slot) == 0) {
        return 0;
    }
    return 1;
}



/* provisional name */
s32 sprite_list_submit(s16 list) {
    s16 j;
    SPRITE_ENTRY* rec;
    SPRITE_ENTRY* e;
    if (sprite_list_w[list].count == 0) {
        return 0;
    }
    for (j = 0; j < sprite_list_w[list].count; j++) {
        rec = &sprite_list_w[list].rec[j];
        if (rec->flag == 1) {
            e = sprite_entry_alloc(1);
            if (e == 0) {
                return 0;
            }
        }
        e->w0 = rec->w0;
        e->w4 = rec->w4;
        e->w6 = rec->w6;
        e->w2 = rec->w2;
        sprite_entry_push_prio(e, (s16)rec->prio);
    }
    return 1;
}



/* provisional name */
s32 sprite_list_clear(s16 list) {
    s16 j;
    s16 unused;
    unused = 0;
    if (sprite_list_w[list].count == 0) {
        return 0;
    }
    sprite_list_w[list].count = 0;
    for (j = 0; j < sprite_list_w[list].count; j++) {
        sprite_list_w[list].rec[j].flag = 0;
    }
    simmram_block_free_40(sprite_list_w[list].slot);
    return 1;
}
