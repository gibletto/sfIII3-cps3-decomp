/*
 * ABOUTSPR.C  Character sprite graphics and display lists
 *
 * Turns character and effect works into sprite-list entries. init_char_gfx_tables and
 * setup_hit_mark_cells set up the cg directory, the gfx-slot table and prebuilt cell tables for
 * shadows, hit marks, car parts and the seraph effect. load_char_gfx and purge_char_gfx move cg
 * sets in and out of sprite RAM slots; trans_char_cells makes a work's current cg displayable
 * and make_char_cells_n/x/y/xy build its cells for each flip.
 * The char_cell_* routines rebuild the current cell block for a flip change; set_conn_sprite
 * builds multi-part sprites; set_judge_area_sprite draws hit/hurt boxes.
 * push_char_sprite and the sort-push routines queue sprites by priority, with
 * shadow_drawing, zoom and rotation helpers. Called by the player and effect code each frame.
 * The file opens with Shell14_0012, the last pattern of the Shell14 CPU table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "end_sub.h"
#include "sys_config.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "cps3.h"

#pragma inline(check_cg_data)
#pragma inline(cg_data_exist)



void Shell14_0012(PLW* wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x20, 0xA, (0x380), -1, 0x30, 0, -1, -1, -1);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}



/* provisional name */
void init_char_gfx_tables(void) {
    s16 i;
    cg_data_list = cg_data_tbl;
    for (i = 0; i < 512; i++) {
        cg_slot_tbl[i].addr = cg_slot_tbl[i].handle = 0;
    }
    for (i = 0; i < 64; i++) {
        kage_gfx_ofs[i] = kage_gfx_cells[i] = 0;
    }
    for (i = 0; i < 288; i++) {
        car_gfx_ofs[i] = car_gfx_cells[i] = 0;
    }
    for (i = 0; i < 512; i++) {
        hitmark_gfx_cells[i] = hitmark_gfx_ofs[0][i] = hitmark_gfx_ofs[1][i] = 0;
    }
    for (i = 0; i < 64; i++) {
        seraph_gfx_ofs[i] = seraph_gfx_cells[i] = 0;
    }
}

/* provisional name */
void setup_kage_cells(void) {
    WORK* ewk;
    WORK* tmp;
    s16* handles;
    s16 ix;
    s16 i;
    if (kage_gfx_ofs[0] != 0) {
        return;
    }
    if (!load_char_gfx(0x9020, 1)) {
        return;
    }
    if ((ix = pull_effect_work(7)) == -1) {
        purge_char_gfx(0x9020);
        return;
    }
    ewk = (WORK*)frw[ix];
    ewk->my_col_code = 0x2000;
    if ((ix = pull_effect_work(7)) == -1) {
        purge_char_gfx(0x9020);
        push_effect_work(ewk);
        return;
    }
    tmp = (WORK*)frw[ix];
    handles = &tmp->routine_no[0];
    for (i = 0; i < 29; i++) {
        ewk->cg_number = 0x9020 + i;
        if (!trans_char_cells(ewk)) {
            goto fail;
        }
        kage_gfx_ofs[i] = ewk->spr.gfx_ofs;
        kage_gfx_cells[i] = ewk->spr.gfx_cells;
        handles[i] = ewk->spr.gfx_blk40[0];
        ewk->spr.gfx_blk40[0] = 0;
    }
    push_effect_work(ewk);
    push_effect_work(tmp);
    return;
fail:
    if (i != 0) {
        for (i--; i >= 0; i--) {
            simmram_block_free_40(handles[i]);
        }
    }
    purge_char_gfx(0x9020);
    push_effect_work(ewk);
    push_effect_work(tmp);
}



/* provisional name */
s32 setup_hit_mark_cells(void) {
    WORK* ewk;
    WORK* tmp;
    s16* handles;
    s16 ix;
    s16 i;
    if (hitmark_gfx_ofs[0][0]) {
        return hitmark_gfx_ofs[0][0];
    }
    load_any_color(1);
    if (!load_char_gfx(0x9EC8, 1)) {
        return 0;
    }
    if (!load_char_gfx(0xA9F8, 1)) {
        return 0;
    }
    if ((ix = pull_effect_work(7)) == -1) {
        return purge_char_gfx(0x9EC8);
    }
    ewk = (WORK*)frw[ix];
    ewk->my_col_code = 0;
    if ((ix = pull_effect_work(7)) == -1) {
        purge_char_gfx(0x9EC8);
        return push_effect_work(ewk);
    }
    tmp = (WORK*)frw[ix];
    handles = &tmp->routine_no[0];
    ewk->rl_flag = 0;
    for (i = 0; i < 303; i++) {
        ewk->cg_number = 0x9EC8 + i;
        if (!trans_char_cells(ewk)) {
            goto fail;
        }
        hitmark_gfx_ofs[0][i] = ewk->spr.gfx_ofs;
        hitmark_gfx_cells[i] = ewk->spr.gfx_cells;
        handles[i] = ewk->spr.gfx_blk40[0];
        ewk->spr.gfx_blk40[0] = 0;
    }
    ewk->rl_flag = 1;
    for (i = 0; i < 303; i++) {
        ewk->cg_number = 0x9EC8 + i;
        if (!trans_char_cells(ewk)) {
            goto fail;
        }
        hitmark_gfx_ofs[1][i] = ewk->spr.gfx_ofs;
        handles[303 + i] = ewk->spr.gfx_blk40[0];
        ewk->spr.gfx_blk40[0] = 0;
    }
    push_effect_work(ewk);
    return push_effect_work(tmp);
fail:
    if (i != 0) {
        for (i--; i >= 0; i--) {
            simmram_block_free_40(handles[i]);
        }
    }
    purge_char_gfx(0x9EC8);
    push_effect_work(ewk);
    return push_effect_work(tmp);
}

s32 setup_GILL_exsa_obj(void) {
    WORK* ewk;
    WORK* tmp;
    s16* handles;
    s16 ix;
    s16 i;
    if (seraph_gfx_ofs[0] != 0) {
        return seraph_gfx_ofs[0];
    }
    if (!load_char_gfx(0xB478, 1)) {
        return 0;
    }
    if ((ix = pull_effect_work(7)) == -1) {
        return purge_char_gfx(0xB478);
    }
    ewk = (WORK*)frw[ix];
    ewk->my_col_code = 320;
    ewk->my_mr_flag = 1;
    ewk->my_mr.size.x = 0x7F;
    ewk->my_mr.size.y = 0x7F;
    if ((ix = pull_effect_work(7)) == -1) {
        purge_char_gfx(0xB478);
        return push_effect_work(ewk);
    }
    tmp = (WORK*)frw[ix];
    handles = &tmp->routine_no[0];
    for (i = 0; i < 8; i++) {
        ewk->cg_number = 0xB478 + i;
        if (!trans_char_cells(ewk)) {
            goto fail;
        }
        char_sprite_zoom_cells(ewk);
        seraph_gfx_ofs[i] = ewk->spr.gfx_ofs;
        seraph_gfx_cells[i] = ewk->spr.gfx_cells;
        handles[i] = ewk->spr.gfx_blk40[0];
        ewk->spr.gfx_blk40[0] = 0;
    }
    push_effect_work(ewk);
    return push_effect_work(tmp);
fail:
    if (i != 0) {
        for (i--; i >= 0; i--) {
            simmram_block_free_40(handles[i]);
        }
    }
    purge_char_gfx(0xB478);
    push_effect_work(ewk);
    return push_effect_work(tmp);
}

s32 setup_bonus_car_parts(void) {
    WORK* ewk;
    WORK* tmp;
    s16* handles;
    s16 ix;
    s16 i;
    if (car_gfx_ofs[0] != 0) {
        return car_gfx_ofs[0];
    }
    if (!load_char_gfx(0xB0C8, 1)) {
        return 0;
    }
    if ((ix = pull_effect_work(7)) == -1) {
        return purge_char_gfx(0xB0C8);
    }
    ewk = (WORK*)frw[ix];
    ewk->my_col_code = 0x2080;
    if ((ix = pull_effect_work(7)) == -1) {
        purge_char_gfx(0xB0C8);
        return push_effect_work(ewk);
    }
    tmp = (WORK*)frw[ix];
    handles = &tmp->routine_no[0];
    for (i = 0; i < 288; i++) {
        ewk->cg_number = 0xB0C8 + i;
        if (!trans_char_cells(ewk)) {
            goto fail;
        }
        car_gfx_ofs[i] = ewk->spr.gfx_ofs;
        car_gfx_cells[i] = ewk->spr.gfx_cells;
        handles[i] = ewk->spr.gfx_blk40[0];
        ewk->spr.gfx_blk40[0] = 0;
    }
    push_effect_work(ewk);
    return push_effect_work(tmp);
fail:
    if (i != 0) {
        for (i--; i >= 0; i--) {
            simmram_block_free_40(handles[i]);
        }
    }
    purge_char_gfx(0xB0C8);
    push_effect_work(ewk);
    return push_effect_work(tmp);
}



/* provisional name */
u32 get_cg_slot_no(id)
    u16 id;
{
    return cg_data_list[id].set->slot;
}

/* provisional name */
u16 get_cg_slot_addr(u16 id) {
    return cg_slot_tbl[id].addr;
}



/* provisional name */
s32 cg_data_exist(u16 id) {
    if (cg_data_list[id].set != 0) {
        return 1;
    }
    return 0;
}

/* provisional name */
s32 load_char_gfx(id, mode)
    u16 id;
    s8 mode;
{
    CharGfxSet* set = cg_data_list[id].set;
    s16 handle;
    u32 base;
    s16 i;
    CharGfxChunk* chunk;
    if (!cg_data_exist(id)) {
        return 0;
    }
    if (!(set->slot & 0x8000)) {
        if (cg_slot_tbl[set->slot].addr != 0) {
            return 1;
        }
        polygon2d_submit_line(set->prep, 0, 0, 3);
        handle = ((s16)simmram_block_alloc_10((set->size >> 5) + 1, 1));
        if (handle == 0) {
            return 0;
        }
        base = simmram_slot_to_offset(handle);
        cg_slot_tbl[set->slot].addr = ((u16)simmram_slot_to_cg_no(handle));
        cg_slot_tbl[set->slot].handle = handle;
        chunk = set->chunk;
        for (i = 0; i < set->count; i++) {
            if (polygon2d_submit_line(chunk[i].src, base + chunk[i].dst * 16, chunk[i].size, mode) != 0) {
                cg_slot_tbl[set->slot].addr = cg_slot_tbl[set->slot].handle = 0;
                ((void(*)(s16 handle))simmram_block_free_10)(handle);
                return 0;
            }
        }
    }
    return 1;
}


/* provisional name */
s32 purge_char_gfx(id)
    u16 id;
{
    CharGfxSet* set = cg_data_list[id].set;
    s16 no = set->slot & 0x7FFF;
    if (cg_slot_tbl[no].addr == 0) {
        return 0;
    }
    simmram_block_free_10(cg_slot_tbl[no].handle);
    cg_slot_tbl[no].addr = cg_slot_tbl[no].handle = 0;
    return 1;
}



/* provisional name */
s32 check_cg_data(id)
    u16 id;
{
    if (cg_data_list[id].set != 0) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 trans_char_cells(WORK* wk) {
    CharGfxSet* set;
    CHAR_CELL* cells;
    CHAR_SPRITE* dst;
    u32 base;
    u16 no;
    u16 addr;
    s16 blk10;
    s16 blk40;
    s16 i;
    no = wk->cg_number;
    set = cg_data_list[no].set;
    if (!(set->slot & 0x8000)) {
        if (wk->old_cgnum == wk->cg_number) {
            goto cached;
        }
        if (cg_slot_tbl[set->slot].addr == 0 && !load_char_gfx(no, wk->cgromtype)) {
            return 0;
        }
        cells = (CHAR_CELL*)&set->chunk[set->count];
        addr = cg_slot_tbl[set->slot].addr;
        wk->spr.slot_addr = addr;
        wk->spr.cells = cells;
        blk40 = ((s16)simmram_block_alloc_40((set->cells >> 4) + 1, 1));
        if (blk40 == 0) {
            return 0;
        }
        dst = (CHAR_SPRITE*)simmram_slot_addr(blk40);
    } else {
        if (wk->old_cgnum == wk->cg_number) {
        cached:
            if (wk->spr.done_flip != wk->cg_flip) {
                if (wk->spr.done_rl == wk->rl_flag) {
                    if (!char_cell_flip_tbl[wk->spr.done_flip][wk->cg_flip](wk)) {
                        return 0;
                    }
                    wk->spr.done_flip = wk->cg_flip;
                    wk->spr.sprite_flip = wk->rl_flag ^ wk->cg_flip;
                    return 1;
                }
                if (!char_cell_flip_tbl[wk->spr.done_flip ^ wk->spr.done_rl][wk->cg_flip ^ wk->rl_flag](wk)) {
                    return 0;
                }
                wk->spr.done_flip = wk->cg_flip;
                wk->spr.done_rl = wk->rl_flag;
                wk->spr.sprite_flip = wk->rl_flag ^ wk->cg_flip;
                return 1;
            }
            if (wk->spr.done_rl == wk->rl_flag) {
                return char_cell_flip_none(wk);
            }
            if (!char_cell_flip_x(wk)) {
                return 0;
            }
            wk->spr.done_rl = wk->rl_flag;
            wk->spr.sprite_flip = wk->rl_flag ^ wk->cg_flip;
            return 1;
        }
        polygon2d_submit_line(set->prep, 0, 0, 3);
        blk10 = ((s16)simmram_block_alloc_10((set->size >> 5) + 1, 1));
        if (blk10 == 0) {
            return 0;
        }
        base = simmram_slot_to_offset(blk10);
        addr = ((u16)simmram_slot_to_cg_no(blk10));
        wk->spr.slot_addr = addr;
        for (i = 0; i < set->count; i++) {
            if (polygon2d_submit_line(set->chunk[i].src, base + set->chunk[i].dst * 16, set->chunk[i].size,
                                      wk->cgromtype) != 0) {
                ((void(*)(s16 handle))simmram_block_free_10)(blk10);
                return 0;
            }
        }
        cells = (CHAR_CELL*)&set->chunk[i];
        wk->spr.cells = cells;
        blk40 = ((s16)simmram_block_alloc_40((set->cells >> 4) + 1, 1));
        if (blk40 == 0) {
            ((void(*)(s16 handle))simmram_block_free_10)(blk10);
            return 0;
        }
        dst = (CHAR_SPRITE*)simmram_slot_addr(blk40);
        if (wk->spr.gfx_blk10[2] != 0) {
            ((void(*)(s16 handle))simmram_block_free_10)(wk->spr.gfx_blk10[2]);
        }
        wk->spr.gfx_blk10[2] = wk->spr.gfx_blk10[1];
        wk->spr.gfx_blk10[1] = wk->spr.gfx_blk10[0];
        wk->spr.gfx_blk10[0] = blk10;
    }
    if (wk->spr.gfx_blk40[2] != 0) {
        ((void(*)(s16 handle))simmram_block_free_40)(wk->spr.gfx_blk40[2]);
    }
    wk->spr.gfx_blk40[2] = wk->spr.gfx_blk40[1];
    wk->spr.gfx_blk40[1] = wk->spr.gfx_blk40[0];
    wk->spr.gfx_blk40[0] = blk40;
    wk->spr.gfx_ofs = ((u16)simmram_slot_to_code(blk40));
    wk->spr.gfx_cells = set->cells;
    wk->cg_ofs_x = cg_data_list[no].x;
    wk->spr.cg_ofs_y = -cg_data_list[no].y;
    wk->spr.sprite_flip = wk->rl_flag ^ wk->cg_flip;
    wk->spr.done_flip = wk->cg_flip;
    wk->spr.done_rl = wk->rl_flag;
    wk->spr.old_mr.x = 63;
    wk->spr.old_mr.y = 63;
    wk->spr.disp_colcd = wk->my_col_code;
    if (wk->my_col_code & 0x2000) {
        wk->spr.disp_colcd += cells->col & 0x1FF;
        wk->current_colcd = wk->spr.disp_colcd;
        make_char_cells_tbl[wk->spr.sprite_flip](wk, cells, dst, set->cells, addr, 0);
    } else {
        wk->spr.disp_colcd &= 0x1FF;
        wk->current_colcd = wk->spr.disp_colcd;
        make_char_cells_tbl[wk->spr.sprite_flip](wk, cells, dst, set->cells, addr, wk->spr.disp_colcd);
    }
    wk->old_cgnum = wk->cg_number;
    return 1;
}



/* provisional name */
void make_char_cells_n(WORK* wk, CHAR_CELL* cell, CHAR_SPRITE* spr, u16 count, s16 x, s16 y) {
    s16 i;
    u16 size;
    CHAR_CELL* c;
    CHAR_SPRITE* s;
    for (i = 0; i < count; i++) {
        s = &spr[i];
        c = &cell[i];
        s->x = x + c->code;
        s->y = y + c->col;
        s->sx = (c->x + wk->cg_ofs_x) & 0x3FF;
        s->sy = (-c->y + wk->spr.cg_ofs_y) & 0x3FF;
        size = *((u8*)c + 6) >> 4;
        s->attr = size | 0x300;
        s->size = cell_size_tbl[size];
    }
}



/* provisional name */
void make_char_cells_x(WORK* wk, CHAR_CELL* cell, CHAR_SPRITE* spr, u16 count, s16 x, s16 y) {
    s16 i;
    u16 size;
    CHAR_CELL* c;
    CHAR_SPRITE* s;
    for (i = 0; i < count; i++) {
        s = &spr[i];
        c = &cell[i];
        s->x = x + c->code;
        s->y = y + c->col;
        s->sx = (-c->x - wk->cg_ofs_x) & 0x3FF;
        s->sy = (-c->y + wk->spr.cg_ofs_y) & 0x3FF;
        size = *((u8*)c + 6) >> 4;
        s->attr = size | 0x300;
        s->size = cell_size_tbl[size];
    }
}



/* provisional name */
void make_char_cells_y(WORK* wk, CHAR_CELL* cell, CHAR_SPRITE* spr, u16 count, s16 x, s16 y) {
    s16 i;
    u16 size;
    CHAR_CELL* c;
    CHAR_SPRITE* s;
    for (i = 0; i < count; i++) {
        s = &spr[i];
        c = &cell[i];
        s->x = x + c->code;
        s->y = y + c->col;
        s->sx = (c->x + wk->cg_ofs_x) & 0x3FF;
        s->sy = (c->y - wk->spr.cg_ofs_y) & 0x3FF;
        size = *((u8*)c + 6) >> 4;
        s->attr = size | 0x300;
        s->size = cell_size_tbl[size];
    }
}



/* provisional name */
void make_char_cells_xy(WORK* wk, CHAR_CELL* cell, CHAR_SPRITE* spr, u16 count, s16 x, s16 y) {
    s16 i;
    u16 size;
    CHAR_CELL* c;
    CHAR_SPRITE* s;
    for (i = 0; i < count; i++) {
        s = &spr[i];
        c = &cell[i];
        s->x = x + c->code;
        s->y = y + c->col;
        s->sx = (-c->x - wk->cg_ofs_x) & 0x3FF;
        s->sy = (c->y - wk->spr.cg_ofs_y) & 0x3FF;
        size = *((u8*)c + 6) >> 4;
        s->attr = size | 0x300;
        s->size = cell_size_tbl[size];
    }
}



/* provisional name */
s32 char_cell_flip_none(WORK* wk) {
    if (wk->spr.gfx_blk10[2] != 0) {
        simmram_block_free_10(wk->spr.gfx_blk10[2]);
    }
    wk->spr.gfx_blk10[2] = wk->spr.gfx_blk10[1];
    wk->spr.gfx_blk10[1] = 0;
    if (wk->spr.gfx_blk40[2] != 0) {
        simmram_block_free_40(wk->spr.gfx_blk40[2]);
    }
    wk->spr.gfx_blk40[2] = wk->spr.gfx_blk40[1];
    wk->spr.gfx_blk40[1] = 0;
    return 1;
}



/* provisional name */
s32 char_cell_push_block(WORK* wk, s16 handle) {
    if (wk->spr.gfx_blk10[2] != 0) {
        simmram_block_free_10(wk->spr.gfx_blk10[2]);
    }
    wk->spr.gfx_blk10[2] = wk->spr.gfx_blk10[1];
    wk->spr.gfx_blk10[1] = 0;
    if (wk->spr.gfx_blk40[2] != 0) {
        simmram_block_free_40(wk->spr.gfx_blk40[2]);
    }
    wk->spr.gfx_blk40[2] = wk->spr.gfx_blk40[1];
    wk->spr.gfx_blk40[1] = wk->spr.gfx_blk40[0];
    wk->spr.gfx_blk40[0] = handle;
    wk->spr.gfx_ofs = simmram_slot_to_code(handle);
    return 1;
}



/* provisional name */
s32 char_cell_flip_x(WORK* wk) {
    s16 handle;
    GFX_CELL* dst;
    GFX_CELL* src;
    GFX_CELL* cell;
    s16 i;
    handle = simmram_block_alloc_40((wk->spr.gfx_cells >> 4) + 1, 1);
    if (handle == 0) {
        return 0;
    }
    dst = (GFX_CELL*)simmram_slot_addr(handle);
    src = (GFX_CELL*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    for (i = 0; i < wk->spr.gfx_cells; i++) {
        cell = &dst[i];
        *cell = src[i];
        cell->w[2] = -cell->w[2] & 0x3FF;
    }
    return char_cell_push_block(wk, handle);
}



/* provisional name */
s32 char_cell_flip_y(WORK* wk) {
    s16 handle;
    GFX_CELL* dst;
    GFX_CELL* src;
    GFX_CELL* cell;
    s16 i;
    handle = simmram_block_alloc_40((wk->spr.gfx_cells >> 4) + 1, 1);
    if (handle == 0) {
        return 0;
    }
    dst = (GFX_CELL*)simmram_slot_addr(handle);
    src = (GFX_CELL*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    for (i = 0; i < wk->spr.gfx_cells; i++) {
        cell = &dst[i];
        *cell = src[i];
        cell->w[3] = -cell->w[3] & 0x3FF;
    }
    return char_cell_push_block(wk, handle);
}



/* provisional name */
s32 char_cell_unflip_y(WORK* wk) {
    s16 handle;
    GFX_CELL* dst;
    GFX_CELL* src;
    GFX_CELL* cell;
    s16 i;
    handle = simmram_block_alloc_40((wk->spr.gfx_cells >> 4) + 1, 1);
    if (handle == 0) {
        return 0;
    }
    dst = (GFX_CELL*)simmram_slot_addr(handle);
    src = (GFX_CELL*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    for (i = 0; i < wk->spr.gfx_cells; i++) {
        cell = &dst[i];
        *cell = src[i];
        cell->w[3] = -cell->w[3] & 0x3FF;
    }
    return char_cell_push_block(wk, handle);
}



/* provisional name */
s32 char_cell_flip_xy(WORK* wk) {
    s16 handle;
    GFX_CELL* dst;
    GFX_CELL* src;
    GFX_CELL* cell;
    s16 i;
    handle = simmram_block_alloc_40((wk->spr.gfx_cells >> 4) + 1, 1);
    if (handle == 0) {
        return 0;
    }
    dst = (GFX_CELL*)simmram_slot_addr(handle);
    src = (GFX_CELL*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    for (i = 0; i < wk->spr.gfx_cells; i++) {
        cell = &dst[i];
        *cell = src[i];
        cell->w[2] = -cell->w[2] & 0x3FF;
        cell->w[3] = -cell->w[3] & 0x3FF;
    }
    return char_cell_push_block(wk, handle);
}



/* provisional name */
s32 char_cell_unflip_xy(WORK* wk) {
    s16 handle;
    GFX_CELL* dst;
    GFX_CELL* src;
    GFX_CELL* cell;
    s16 i;
    handle = simmram_block_alloc_40((wk->spr.gfx_cells >> 4) + 1, 1);
    if (handle == 0) {
        return 0;
    }
    dst = (GFX_CELL*)simmram_slot_addr(handle);
    src = (GFX_CELL*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    for (i = 0; i < wk->spr.gfx_cells; i++) {
        cell = &dst[i];
        *cell = src[i];
        cell->w[2] = -cell->w[2] & 0x3FF;
        cell->w[3] = -cell->w[3] & 0x3FF;
    }
    return char_cell_push_block(wk, handle);
}



s32 set_judge_area_sprite(WORK_Other* owk) {
    WORK_Other_JUDGE* wk = (WORK_Other_JUDGE*)owk;
    SPR_LIST_HEAD* g = (SPR_LIST_HEAD*)&wk->wu.spr.done_flip;
    u16* base;
    u16* dst;
    s16 blk;
    s16 base_code;
    s16 cell;
    s16 y_ofs;
    s16 i;
    s16 k;
    u32 bit;
    if (g->gfx_cells == 0) {
        return 0;
    }
    base_code = cg_slot_tbl[(u16)cg_data_list[wk->wu.cg_number].set->slot].addr;
    if ((blk = simmram_block_alloc_40((((g->gfx_cells < 0) ? g->gfx_cells + 15 : g->gfx_cells) >> 4) + 1, 1)) == 0) {
        return 0;
    }
    base = ((u16 *(*)(s16 handle))simmram_slot_addr)(blk);
    if (g->gfx_blk40[2] != 0) {
        simmram_block_free_40(g->gfx_blk40[2]);
    }
    g->gfx_blk40[2] = g->gfx_blk40[1];
    g->gfx_blk40[1] = g->gfx_blk40[0];
    g->gfx_blk40[0] = blk;
    g->gfx_ofs = simmram_slot_to_code(blk);
    g->done_rl = 0;
    cell = 0;
    for (i = 0, bit = 1; i < 14; i++, bit <<= 1) {
        if (!(wk->ja_disp_bit & bit)) {
            continue;
        }
        y_ofs = 0;
        if (i == wk->curr_ja) {
            y_ofs = wk->fade_cja.w * 2;
        }
        for (k = 0; k < 4; k++) {
            dst = base + cell * 8;
            cell++;
            dst[0] = judge_area_code_tbl[i] + base_code + y_ofs;
            dst[1] = flip_attr_tbl[k];
            dst[2] = (&wk->ja[i * 4])[k][0] & 0x3FF;
            dst[3] = (&wk->ja[i * 4])[k][1] & 0x3FF;
            dst[5] = 0x305;
            dst[4] = cell_size_tbl[5];
        }
    }
    if (wk->ja_disp_bit & 0x4000) {
        for (k = 0; k < 4; k++) {
            dst = base + cell * 8;
            cell++;
            dst[0] = judge_area_code_tbl[14] + base_code;
            dst[1] = flip_attr_tbl[k];
            dst[2] = wk->ja[56 + k][0] & 0x3FF;
            dst[3] = wk->ja[56 + k][1] & 0x3FF;
            dst[5] = 0x305;
            dst[4] = cell_size_tbl[5];
        }
    }
    if (wk->ja_disp_bit & 0x8000) {
        for (k = 0; k < 2; k++) {
            dst = base + cell * 8;
            cell++;
            dst[0] = judge_area_code_tbl[15 + k] + base_code;
            dst[1] = flip_attr_tbl[0];
            dst[2] = wk->ja[60 + k][0] & 0x3FF;
            dst[3] = wk->ja[60 + k][1] & 0x3FF;
            dst[5] = 0x305;
            dst[4] = cell_size_tbl[5];
        }
    }
    if (cell == g->gfx_cells) {
        return 1;
    }
    return 2;
}



s32 set_conn_sprite(WORK_Other_CONN* wk) {
    CharGfxEntry* ent;
    CharGfxSet* set;
    CHAR_CELL* parts;
    CHAR_CELL* p;
    u16* base;
    u16* dst;
    s16 blk;
    s16 cell;
    s16 base_code;
    s16 i;
    s16 j;
    u16 chr;
    u16 size;
    if (wk->wu.old_cgnum == wk->wu.cg_number) {
        return 1;
    }
    count_conn_cells(wk);
    if (wk->wu.spr.gfx_cells == 0) {
        return 0;
    }
    if ((blk = simmram_block_alloc_40((((wk->wu.spr.gfx_cells < 0) ? wk->wu.spr.gfx_cells + 15 : wk->wu.spr.gfx_cells) >> 4) + 1, 1)) == 0) {
        return 0;
    }
    base = (u16 *)simmram_slot_addr(blk);
    if (wk->wu.spr.gfx_blk40[2] != 0) {
        simmram_block_free_40(wk->wu.spr.gfx_blk40[2]);
    }
    wk->wu.spr.gfx_blk40[2] = wk->wu.spr.gfx_blk40[1];
    wk->wu.spr.gfx_blk40[1] = wk->wu.spr.gfx_blk40[0];
    wk->wu.spr.gfx_blk40[0] = blk;
    wk->wu.spr.gfx_ofs = simmram_slot_to_code(blk);
    wk->wu.spr.done_rl = 0;
    if (wk->wu.my_col_code & 0x2000) {
        wk->wu.spr.disp_colcd = wk->wu.my_col_code;
    } else {
        wk->wu.spr.disp_colcd = wk->wu.my_col_code & 0x1FF;
    }
    for (cell = i = 0; i < wk->num_of_conn; i++) {
        chr = wk->conn[i].chr;
        ent = &cg_data_list[chr];
        set = ent->set;
        base_code = cg_slot_tbl[(u16)set->slot].addr;
        parts = (CHAR_CELL*)((u8*)set + 12) + set->count;
        for (j = 0; j < set->cells; j++) {
            p = &parts[j];
            dst = base + cell * 8;
            dst[0] = p->code + base_code;
            dst[1] = p->col + wk->wu.spr.disp_colcd + wk->conn[i].col;
            dst[2] = (p->x + wk->conn[i].nx + cg_data_list[chr].x) & 0x3FF;
            dst[3] = (wk->conn[i].ny - (u16)p->y - cg_data_list[chr].y) & 0x3FF;
            size = *(u8*)&p->y >> 4;
            dst[5] = size | 0x300;
            dst[4] = ((u16)cell_size_tbl[size]);
            cell++;
            continue;
        }
        continue;
    }
    return 1;
}



/* provisional name */
void count_conn_cells(WORK_Other_CONN* ewk) {
    s16 i;
    ewk->wu.spr.gfx_cells = 0;
    for (i = 0; i < ewk->num_of_conn; i++) {
        if (ewk->conn[i].chr == 0) {
            continue;
        }
        ewk->wu.spr.gfx_cells += cg_data_list[ewk->conn[i].chr].set->cells;
    }
}



/* provisional name */
s32 make_conn_cells(WORK_Other_CONN* ewk) {
    s16 handle;
    CharSpriteK* dst;
    CharSpriteK* s;
    CHAR_CELL* cells;
    CHAR_CELL* c;
    CharGfxSet* set;
    s16 base;
    u16 chr;
    s16 i;
    s16 j;
    s16 n;
    s32 blocks;
    if (ewk->wu.old_cgnum == ewk->wu.cg_number) {
        return 1;
    }
    count_conn_cells(ewk);
    if (ewk->wu.spr.gfx_cells == 0) {
        return 0;
    }
    blocks = ewk->wu.spr.gfx_cells;
    if (blocks < 0) {
        blocks += 15;
    }
    handle = ((s16)simmram_block_alloc_40((blocks >> 4) + 1, 1));
    if (handle == 0) {
        return 0;
    }
    dst = (CharSpriteK*)simmram_slot_addr(handle);
    if (ewk->wu.spr.gfx_blk40[2] != 0) {
        simmram_block_free_40(ewk->wu.spr.gfx_blk40[2]);
    }
    ewk->wu.spr.gfx_blk40[2] = ewk->wu.spr.gfx_blk40[1];
    ewk->wu.spr.gfx_blk40[1] = ewk->wu.spr.gfx_blk40[0];
    ewk->wu.spr.gfx_blk40[0] = handle;
    ewk->wu.spr.gfx_ofs = ((s16)simmram_slot_to_code(handle));
    ewk->wu.spr.done_rl = 0;
    if (ewk->wu.my_col_code & 0x2000) {
        ewk->wu.spr.disp_colcd = ewk->wu.my_col_code;
    } else {
        ewk->wu.spr.disp_colcd = ewk->wu.my_col_code & 0x1FF;
    }
    for (n = i = 0; i < ewk->num_of_conn; i++) {
        chr = ewk->conn[i].chr;
        set = cg_data_list[chr].set;
        base = cg_slot_tbl[set->slot].addr;
        cells = (CHAR_CELL*)set->chunk;
        cells += set->count;
        for (j = 0; j < set->cells; j++) {
            s = &dst[n];
            c = &cells[j];
            s->code = base + c->code;
            s->pal = c->col + ewk->wu.spr.disp_colcd + ewk->conn[i].col;
            n++;
            s->x = (c->x + ewk->conn[i].nx + cg_data_list[chr].x) & 0x3FF;
            s->y = (ewk->conn[i].ny - c->y - cg_data_list[chr].y) & 0x3FF;
            s->attr = (*((u8*)c + 6) >> 4) | 0x300;
            s->zoom = 0x3F3F;
        }
    }
    return 1;
}



void all_cgps_put_back(WORK* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (wk->spr.gfx_blk10[i] != 0) {
            simmram_block_free_10(wk->spr.gfx_blk10[i]);
        }
        wk->spr.gfx_blk10[i] = 0;
        if (wk->spr.gfx_blk40[i] != 0) {
            simmram_block_free_40(wk->spr.gfx_blk40[i]);
        }
        wk->spr.gfx_blk40[i] = 0;
    }
    wk->cg_number = 0;
    wk->old_cgnum = 0;
}



/* provisional name */
void release_char_cell_blocks(WORK* wk) {
    s16 i;
    for (i = 0; i < 3; i++) {
        if (wk->spr.gfx_blk40[i] != 0) {
            simmram_block_free_40(wk->spr.gfx_blk40[i]);
        }
        wk->spr.gfx_blk40[i] = 0;
    }
    wk->cg_number = 0;
    wk->old_cgnum = 0;
}

s32 sort_push_request(WORK* wk) {
    u16* spr;
    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }
    if (wk->disp_flag == 2 && ((wk->blink_timing + Game_timer) & 1)) {
        return 1;
    }
    if (!trans_char_cells(wk)) {
        return 0;
    }
    if ((spr = (u16*)sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    wk->spr.disp_colcd = wk->current_colcd;
    if (wk->extra_col_2 != 0) {
        wk->spr.disp_colcd = wk->extra_col_2;
    }
    if (wk->extra_col != 0) {
        wk->spr.disp_colcd = wk->extra_col;
    }
    push_char_sprite(wk, spr, base_y_pos);
    if (wk->my_mr_flag != 0 && *(u32*)&wk->spr.old_mr != *(u32*)&wk->my_mr) {
        char_sprite_zoom_cells(wk);
    }
    if (wk->work_id == 1 && (wk->spr.sprite_flip & 1)) {
        spr[4] |= 8;
    }
    if (wk->work_id == 0x20 && wk->my_col_code == ((WORK*)((WORK_Other*)wk)->my_master)->my_col_code &&
        (wk->spr.sprite_flip & 1)) {
        spr[4] |= 8;
    }
    if (wk->kage_flag) {
        shadow_drawing(wk, base_y_pos);
    }
    return 2;
}



s32 sort_push_request2(WORK_Other* wk) {
    u16* spr;
    u16* cell;
    s16 i;
    if (wk->wu.disp_flag == 0 && wk->master_work_id == 1) {
        return 1;
    }
    if (!set_judge_area_sprite(wk)) {
        return 0;
    }
    if ((spr = sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    push_char_sprite(&wk->wu, spr, base_y_pos);
    if (wk->wu.spr.done_rl != wk->wu.rl_flag) {
        wk->wu.spr.done_rl = wk->wu.rl_flag;
        spr[4] ^= 0x1000;
        cell = (u16*)(SPRITE_RAM + wk->wu.spr.gfx_ofs * 16);
        for (i = 0; i < wk->wu.spr.gfx_cells; i++) {
            cell[i * 8 + 2] = -cell[i * 8 + 2] & 0x3FF;
        }
    } else if (wk->wu.spr.done_rl) {
        spr[4] ^= 0x1000;
    }
    return 2;
}



s32 sort_push_request3(WORK* wk) {
    u16* spr;
    u16* cell;
    s16 i;
    if (wk->disp_flag == 0) {
        return 1;
    }
    if (wk->disp_flag == 2 && ((wk->blink_timing + Game_timer) & 1)) {
        return 1;
    }
    if (!set_conn_sprite((WORK_Other_CONN*)wk)) {
        return 0;
    }
    wk->old_cgnum = wk->cg_number;
    if ((spr = sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    push_char_sprite(wk, spr, base_y_pos);
    if (wk->spr.done_rl != wk->rl_flag) {
        wk->spr.done_rl = wk->rl_flag;
        spr[4] ^= 0x1000;
        cell = (u16*)(SPRITE_RAM + wk->spr.gfx_ofs * 16);
        for (i = 0; i < wk->spr.gfx_cells; i++) {
            cell[i * 8 + 2] = -cell[i * 8 + 2] & 0x3FF;
        }
    } else if (wk->spr.done_rl) {
        spr[4] |= 0x1000;
    }
    if (wk->kage_flag) {
        shadow_drawing(wk, base_y_pos);
    }
    return 2;
}

s32 sort_push_request4(WORK* wk) {
    u16* spr;
    if (wk->disp_flag == 0 || wk->cg_number == 0) {
    no_draw:
        return 1;
    }
    if (wk->disp_flag == 2 && ((wk->blink_timing + Game_timer) & 1)) {
        goto no_draw;
    }
    if (trans_char_cells(wk) == 0) {
        return 0;
    }
    if ((spr = (u16*)sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    wk->spr.disp_colcd = wk->current_colcd;
    if (wk->extra_col_2 != 0) {
        wk->spr.disp_colcd = wk->extra_col_2;
    }
    if (wk->extra_col != 0) {
        wk->spr.disp_colcd = wk->extra_col;
    }
    push_char_sprite(wk, spr, 0);
    if (wk->my_mr_flag != 0 && *(u32*)&wk->spr.old_mr != *(u32*)&wk->my_mr) {
        char_sprite_zoom_cells(wk);
    }
    if (wk->kage_flag) {
        shadow_drawing(wk, 0);
    }
    return 2;
}



/* provisional name */
void push_char_sprite(WORK* wk, u16* spr, s16 y_ofs) {
    spr[0] = wk->spr.gfx_cells;
    spr[0] |= wk->my_family << 12;
    spr[1] = wk->spr.gfx_ofs;
    spr[2] = wk->position_x;
    spr[3] = wk->position_y + y_ofs;
    spr[8] = wk->position_z;
    spr[4] = wk->spr.disp_colcd | wk->my_col_mode | flip_attr_tbl[wk->spr.sprite_flip];
    spr[5] = wk->my_ext_pri;
    sprite_entry_push_prio(spr, wk->position_z);
}



/* provisional name */
s32 disp_seraph_cells(WORK* wk) {
    u16* spr;
    u16 ix;
    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }
    if (cg_slot_tbl[cg_data_list[wk->cg_number].set->slot & 0x7FFF].addr == 0) {
        return (s32)cg_slot_tbl;
    }
    if ((spr = sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    ix = wk->cg_number - 0xB478;
    spr[0] = seraph_gfx_cells[ix];
    spr[0] |= wk->my_family << 12;
    spr[1] = seraph_gfx_ofs[ix];
    spr[2] = wk->position_x;
    spr[3] = wk->position_y + base_y_pos;
    spr[8] = wk->position_z;
    spr[4] = wk->my_col_mode | wk->my_col_code | flip_attr_tbl[wk->rl_flag];
    spr[5] = 0;
    sprite_entry_push_prio(spr, wk->position_z);
    return 2;
}



s32 sort_push_request8(WORK* wk) {
    u16 no;
    u16* spr;
    u16 ix;
    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }
    if (wk->disp_flag == 2 && ((wk->blink_timing + Game_timer) & 1)) {
        return 1;
    }
    no = cg_data_list[wk->cg_number].set->slot & 0x7FFF;
    if (no != 0x130) {
        return sort_push_request(wk);
    }
    if (cg_slot_tbl[no].addr == 0) {
        return;
    }
    spr = sprite_entry_alloc(0);
    if (spr == 0) {
        return 0;
    }
    ix = wk->cg_number - 0x9EC8;
    spr[0] = ((u16)hitmark_gfx_cells[ix]);
    spr[0] |= wk->my_family << 12;
    spr[1] = ((u16)hitmark_gfx_ofs[wk->rl_flag][ix]);
    spr[2] = wk->position_x;
    spr[3] = wk->position_y + base_y_pos;
    spr[8] = wk->position_z;
    spr[4] = wk->my_col_code | wk->my_col_mode | flip_attr_tbl[wk->rl_flag];
    spr[5] = 0;
    sprite_entry_push_prio(spr, wk->position_z);
    return 2;
}



/* provisional name */
s32 disp_car_parts_cells(WORK* wk) {
    u16* spr;
    u16 ix;
    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }
    if (cg_slot_tbl[cg_data_list[wk->cg_number].set->slot & 0x7FFF].addr == 0) {
        return (s32)cg_slot_tbl;
    }
    if ((spr = sprite_entry_alloc(0)) == 0) {
        return 0;
    }
    ix = wk->cg_number - 0xB0C8;
    spr[0] = car_gfx_cells[ix];
    spr[0] |= wk->my_family << 12;
    spr[1] = car_gfx_ofs[ix];
    spr[2] = wk->position_x;
    spr[3] = wk->position_y + base_y_pos;
    spr[8] = wk->position_z;
    spr[4] = wk->my_col_mode | wk->my_col_code | flip_attr_tbl[wk->rl_flag];
    spr[5] = 0;
    sprite_entry_push_prio(spr, wk->position_z);
    return 2;
}



void shadow_drawing(WORK* wk, s16 y_ofs) {
    u16* spr;
    s16 size;
    if (Combo_Demo_Flag) {
        return;
    }
    if (cg_slot_tbl[cg_data_list[0x9020].set->slot].addr == 0) {
        return;
    }
    if ((spr = sprite_entry_alloc(0)) == 0) {
        return;
    }
    size = wk->kage_char - get_kage_width(wk->xyz[1].disp.pos - wk->kage_hy);
    if (size > 28) {
        size = 28;
    } else if (size < 0) {
        size = 0;
    }
    spr[0] = kage_gfx_cells[size];
    spr[0] |= wk->my_family << 12;
    spr[1] = kage_gfx_ofs[size];
    spr[2] = wk->kage_hx * (wk->rl_flag ? -1 : 1) + wk->position_x;
    spr[3] = wk->kage_hy + y_ofs;
    spr[8] = wk->kage_prio;
    spr[4] = 0x6400;
    spr[5] = 0;
    sprite_entry_push_prio(spr, wk->kage_prio);
}



s16 get_kage_width(s16 v) {
    if (v <= 0) {
        return 0;
    }
    v /= 4;
    if (v >= 64) {
        return 16;
    }
    return kage_width_tbl[v];
}



/* provisional name */
void char_sprite_zoom_cells(WORK* wk) {
    CharSpriteK* spr;
    /* one stack slot holds the cell pointer, then the sprite pointer: the arcade loop keeps i in a
       register this way, and the loop's cost decides slowdown frames in zoomed scenes */
    CharSpriteK* volatile s;
    XY16K pos;
    s16 m[4];
    s16 base_x;
    s16 base_y;
    s16 i;
    s16* volatile mp;
    spr = (CharSpriteK*)(SPRITE_RAM + (u16)wk->spr.gfx_ofs * 16);
    *(u32*)&wk->spr.old_mr = *(u32*)&wk->my_mr;
    switch (wk->my_mr.size.x) {
    case 0:
        m[0] = 0;
        m[1] = 1;
        break;
    case 63:
        m[0] = 1;
        m[1] = 1;
        break;
    case 127:
        m[0] = 2;
        m[1] = 1;
        break;
    default:
        m[0] = wk->my_mr.size.x - 1;
        m[1] = 64;
        break;
    }
    switch (wk->my_mr.size.y) {
    case 0:
        m[2] = 0;
        m[3] = 1;
        break;
    case 63:
        m[2] = 1;
        m[3] = 1;
        break;
    case 127:
        m[2] = 2;
        m[3] = 1;
        break;
    default:
        m[2] = wk->my_mr.size.y - 1;
        m[3] = 64;
        break;
    }
    pos.l = zoom_cell_position(m, (u16)wk->cg_ofs_x, wk->spr.cg_ofs_y);
    base_x = pos.s.x;
    base_y = pos.s.y;
    switch (wk->spr.sprite_flip) {
    case 0:
        mp = m;
        for (i = 0; i < wk->spr.gfx_cells; i++) {
            s = (CharSpriteK*)&wk->spr.cells[i];
            pos.l = zoom_cell_position(mp, (u16)((CHAR_CELL*)s)->x, (u16)((CHAR_CELL*)s)->y);
            s = &spr[i];
            s->x = (pos.s.x + base_x) & 0x3FF;
            s->y = (base_y - pos.s.y) & 0x3FF;
            s->zoom = get_cell_zoom(wk->my_mr.size.x, wk->my_mr.size.y, (u16)s->attr);
            continue;
        }
        break;
    case 1:
        mp = m;
        for (i = 0; i < wk->spr.gfx_cells; i++) {
            s = (CharSpriteK*)&wk->spr.cells[i];
            pos.l = zoom_cell_position(mp, (u16)((CHAR_CELL*)s)->x, (u16)((CHAR_CELL*)s)->y);
            s = &spr[i];
            s->x = (-pos.s.x - base_x) & 0x3FF;
            s->y = (base_y - pos.s.y) & 0x3FF;
            s->zoom = get_cell_zoom(wk->my_mr.size.x, wk->my_mr.size.y, (u16)s->attr);
            continue;
        }
        break;
    case 2:
        mp = m;
        for (i = 0; i < wk->spr.gfx_cells; i++) {
            s = (CharSpriteK*)&wk->spr.cells[i];
            pos.l = zoom_cell_position(mp, (u16)((CHAR_CELL*)s)->x, (u16)((CHAR_CELL*)s)->y);
            s = &spr[i];
            s->x = (pos.s.x + base_x) & 0x3FF;
            s->y = (pos.s.y - base_y) & 0x3FF;
            s->zoom = get_cell_zoom(wk->my_mr.size.x, wk->my_mr.size.y, (u16)s->attr);
            continue;
        }
        break;
    default:
        mp = m;
        for (i = 0; i < wk->spr.gfx_cells; i++) {
            s = (CharSpriteK*)&wk->spr.cells[i];
            pos.l = zoom_cell_position(mp, (u16)((CHAR_CELL*)s)->x, (u16)((CHAR_CELL*)s)->y);
            s = &spr[i];
            s->x = (-pos.s.x - base_x) & 0x3FF;
            s->y = (pos.s.y - base_y) & 0x3FF;
            s->zoom = get_cell_zoom(wk->my_mr.size.x, wk->my_mr.size.y, (u16)s->attr);
            continue;
        }
        break;
    }
}



/* provisional name */
s32 zoom_cell_position(m, x, y)
    s16 *m;
    s16 x;
    s16 y;
{
    XY16 pos;
    if (x & 0x200) {
        x |= 0xFC00;
    } else {
        x &= 0x3FF;
    }
    if (y & 0x200) {
        y |= 0xFC00;
    } else {
        y &= 0x3FF;
    }
    pos.s.x = m[0] * x / m[1];
    m += 2;
    pos.s.y = m[0] * y / m[1];
    return pos.l;
}



/* provisional name */
s32 get_cell_zoom(lo, hi, rows)
    u16 lo;
    u16 hi;
    u16 rows;
{
    volatile s16 lo_row = rows & 3;
    s16 hi_row = (rows & 12) >> 2;
    s32 value = cell_zoom_tbl[hi_row][hi] << 8;
    if (lo < 4) {
        lo = 4;
    }
    return (s16)(value | cell_zoom_tbl[lo_row][lo]);
}
