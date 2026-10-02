/*
 * sc_sub.c  HUD win marks, palette fade control and stun gauge
 *
 * Per-player HUD pieces drawn on the text layer during a fight. The win mark routines
 * (win_mark_control, win_mark_pos_set, win_mark_write, win_mark_all_write) place one
 * mark per round won and blink a newly won mark using win_mark_blink_tbl.
 * fade_cont_init / fade_cont_main run a multi-layer palette fade: the fade number selects a
 * list of palette groups and step parameters, and each frame the groups due for an update are
 * re-sent through the colour request queue with the next brightness until every layer has
 * reached its target, after which the fade flags are cleared.
 * stngauge_cont_init / stngauge_cont_main / stngauge_control keep each player's stun gauge in
 * step with the stun value, with stun_put, stun_mark_write and stun_gauge_waku_write drawing the
 * gauge, its "stun" mark and its frame.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "sc_sub.h"
#include "cps3.h"



/* provisional name */
void win_mark_control(s16 pl) {
    if (Exec_Wipe) {
        return;
    }
    switch (win_mark_rno[pl]) {
    case 0:
        win_mark_new[pl] = 0;
        if (PL_Wins[pl] == 0) {
            win_mark_rno[pl] = 99;
            return;
        }
        win_mark_rno[pl]++;
        win_mark_timer[pl] = 1;
        win_mark_phase[pl] = 0;
        win_mark_pos_set(pl);
        return;
    case 1:
        if (win_mark_new[pl]) {
            win_mark_new_check(pl);
        }
        if (--win_mark_timer[pl] != 0) {
            return;
        }
        win_mark_write(pl);
        win_mark_timer[pl] = (*(const s16(*)[])((&win_mark_blink_tbl[0][1])))[win_mark_phase[pl]];
        if (win_mark_phase[pl] == 2) {
            win_mark_phase[pl] = 0;
        } else {
            win_mark_phase[pl] = win_mark_phase[pl] + 2;
        }
        return;
    default:
        if (win_mark_new[pl] && win_mark_phase[pl ^ 1] == 0) {
            win_mark_rno[pl] = 1;
            win_mark_new[pl] = 0;
            win_mark_timer[pl] = 1;
            win_mark_phase[pl] = 0;
            win_mark_pos_set(pl);
        }
        return;
    }
}



/* provisional name */
void win_mark_pos_set(s16 pl) {
    win_mark_num[pl] = PL_Wins[pl] * 2;
    if (pl != 0) {
        win_mark_pos[1] = win_mark_pos_tbl[(*&Game_setting).mode][4];
    } else {
        win_mark_pos[0] = win_mark_pos_tbl[(*&Game_setting).mode][0];
    }
}



/* provisional name */
void win_mark_new_check(s16 pl) {
    if (win_mark_phase[pl] == 0) {
        win_mark_new[pl] = 0;
        win_mark_pos_set(pl);
    }
}



/* provisional name */
void win_mark_write(s16 pl) {
    u32 cell = (SS_RAM + 0x400) + win_mark_pos[pl] * 4;
    s16* type = win_type[pl];
    s16* phase = &win_mark_phase[pl];
    s16 n = win_mark_num[pl];
    if (pl == 0) {
        for (; n > 0; n -= 2) {
            *(u16*)(cell + 2) = win_mark_blink_tbl[*type][*phase] | (*(u16*)(cell + 2) & 1);
            *(u16*)(cell + 6) = win_mark_blink_tbl[*type++][*phase] | (*(u16*)(cell - 2) & 1);
            cell -= 8;
        }
    } else {
        for (; n > 0; n -= 2) {
            *(u16*)(cell + 2) = win_mark_blink_tbl[*type][*phase] | (*(u16*)(cell + 2) & 1);
            *(u16*)(cell + 6) = win_mark_blink_tbl[*type++][*phase] | (*(u16*)(cell + 6) & 1);
            cell += 8;
        }
    }
}

/* provisional name */
u32 win_mark_all_write(u32 pl)
{
    s16 side;
    s16 count;
    s16 n;
    u32 rv;
    u16 *cell;
    s16 *type;

    side = (s16)pl;
    win_mark_phase[side] = 0;
    rv = ((u32 (*)())win_mark_pos_set)(pl);
    cell = (u16 *)((SS_RAM + 0x400) + win_mark_pos[side] * 4);
    if (!side) {
        count = Battle_Round[Play_Type] + 1;
        n = count * 2;
        rv = 0;
        type = win_type[side];
        if (count != 0) {
            do {
                n -= 2;
                cell[1] = win_mark_blink_tbl[*type][win_mark_phase[side]] | (cell[1] & 1);
                rv = (((s16 *)cell)[-1] & 1) | win_mark_blink_tbl[*type][win_mark_phase[side]];
                cell[3] = rv;
                cell -= 4;
                type++;
            } while (n > 0);
        }
    } else {
        count = Battle_Round[Play_Type] + 1;
        n = count * 2;
        type = win_type[side];
        if (count != 0) {
            do {
                n -= 2;
                cell[1] = win_mark_blink_tbl[*type][win_mark_phase[side]] | (cell[1] & 1);
                rv = ((s16 *)cell)[3] & 1;
                cell[3] = win_mark_blink_tbl[*type][win_mark_phase[side]] | rv;
                cell += 4;
                type++;
            } while (n > 0);
        }
    }
    return rv;
}



void fade_cont_init(void) {
    const s16* tbl;
    const s16* dat;
    FADE_LAYER* fw;
    s8 i;
    s8 num;
    s16 no;
    fade_layer_num = 0;
    fade_cont_rno = 0;
    fade_end_timer = 1;
    no = Fade_Number;
    tbl = fade_data_tbl[no];
    fade_layer_num = num = *tbl++;
    for (i = 0; i < num; i++) {
        fw = &fade_layer[i];
        fw->adrs = fade_adrs_tbl[tbl[0]];
        fw->cur = fw->adrs;
        dat = fade_param_tbl[tbl[1]];
        fw->v8 = dat[0];
        fw->v10 = dat[1];
        fw->v12 = fw->v10;
        fw->v14 = fw->v10;
        fw->v16 = dat[2];
        fw->kind = dat[3];
        fw->v20 = dat[4];
        fw->v22 = fw->v20;
        fw->v24 = dat[5];
        fw->on = 1;
        switch (fw->kind) {
        case 0:
        case 1:
            fade_layer[i].step = 64;
            break;
        case 2:
        case 3:
            fade_layer[i].step = 96;
            break;
        }
        tbl += 2;
    }
}

s32 fade_cont_main(void)
{
    FADE_LAYER *fl;
    s32 rv;
    u16 j;
    s8 i;
    s8 done;

    rv = fade_cont_rno;
    if (rv == 0) {
        for (i = 0; i < fade_layer_num; i++) {
            fl = &fade_layer[i];
            if (fl->on == 0) {
                continue;
            }
            if (--fl->v20 != 0) {
                continue;
            }
            fl->v20 = fl->v22;
            for (j = 0; j < fl->v8; j++) {
                load_any_color_req(*(u32 *)fl->adrs, fl->v10 + fl->step, fl->v12 + fl->step, fl->v14 + fl->step);
                fl->adrs += 4;
            }
            if (fl->v10 == fl->v16) {
                fl->on = 0;
                continue;
            }
            fl->adrs = fl->cur;
            fl->v10 += fl->v24;
            fl->v12 = fl->v10;
            fl->v14 = fl->v10;
            switch (fl->kind) {
            case 0:
            case 2:
                if (fl->v10 < fl->v16) {
                    fl->v10 = fl->v16;
                    fl->v12 = fl->v10;
                    fl->v14 = fl->v10;
                }
                break;
            case 1:
            case 3:
                if (fl->v16 < fl->v10) {
                    fl->v10 = fl->v16;
                    fl->v12 = fl->v10;
                    fl->v14 = fl->v10;
                }
                break;
            }
        }
        done = 0;
        for (i = 0; i < fade_layer_num; i++) {
            rv = 26; /* the value returned when no layer is fading: offset of .on in the layer record */
            if (fade_layer[i].on == 0) {
                done++;
            }
        }
        if (done == (u8)fade_layer_num) {
            fade_cont_rno = 1;
        }
    } else if (rv == 1) {
        if (--fade_end_timer == 0) {
            Fade_Flag = 0;
            Fade_Mode = 0;
        }
    }
    return rv;
}



void stngauge_cont_init(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        sdat[i].cstn = 0;
        sdat[i].ostn = 0;
        sdat[i].stncol_number = i ? 0x94 : 20;
        sdat[i].stntbl_ptr = stngauge_puttbl[0];
        sdat[i].sflag = 0;
        sdat[i].osflag = 0;
        sdat[i].g_or_s = 0;
        sdat[i].stimer = 2;
        sdat[i].slen = piyori_type[i].genkai / 8;
        sdat[i].dotlen = piyori_type[i].genkai;
        sdat[i].proccess_dead = 0;
    }
    sdat[0].stnptbl_ptr = stngauge_postbl[0];
    sdat[1].stnptbl_ptr = stngauge_postbl[1];
    stun_gauge_waku_write(0);
    stun_gauge_waku_write(1);
    stun_mark_write(0, 0);
    stun_mark_write(1, 1);
}



void stngauge_cont_main(void) {
    if (!EXE_flag) {
        if (((s16)gauge_stop_flag[0]) == 0) {
            stngauge_control(0);
        }
        if (((s16)gauge_stop_flag[1]) == 0) {
            stngauge_control(1);
        }
    }
}



void stngauge_control(s32 player) {
    s8 pl = player;
    STN_DAT* sd = &sdat[pl];
    PLW* wk = &plw[pl];
    if (Exec_Wipe) {
        sd->cstn = wk->py->now.quantity.h;
        return;
    }
    if (sd->proccess_dead) {
        return;
    }
    if (wk->dead_flag) {
        sd->proccess_dead = 1;
        sd->cstn = 0;
        stun_put(pl);
        return;
    }
    if ((wk->wu.routine_no[1] == 1 && wk->wu.routine_no[2] == 25 && wk->wu.routine_no[3] != 0) ||
        wk->py->flag == 1) {
        sd->sflag = 1;
        if (sd->osflag == 0) {
            sd->cstn = stun_genkai_tbl[My_char[pl] & 0x7F];
        }
        sd->stimer--;
        if (sd->g_or_s == 0) {
            if (sd->stimer == 0) {
                stun_mark_put(pl);
                sd->g_or_s = 1;
                sd->stimer = 2;
            }
        } else if (sd->stimer == 0) {
            stun_put(pl);
            sd->g_or_s = 0;
            sd->stimer = 2;
        }
        sd->osflag = sd->sflag;
        return;
    }
    sd->sflag = 0;
    if (sd->osflag == 1) {
        sd->osflag = sd->sflag;
        sd->g_or_s = 0;
        sd->stimer = 2;
        sd->cstn = wk->py->now.quantity.h;
        sd->osflag = sd->sflag;
        stun_put(pl);
        return;
    }
    if (sdat[pl].cstn != plw[pl].py->now.quantity.h) {
        sdat[pl].cstn = plw[pl].py->now.quantity.h;
        stun_put(pl);
    }
}



void stun_put(pl)
s8 pl;
{
    STN_DAT* g = &sdat[pl];
    s8 i;
    stn_work = 0;
    stn_number = 0;
    for (i = 0; i < g->slen; i++) {
        stn_work += 8;
        if (stn_work >= g->cstn) {
            if (g->cstn >= stn_work - 8) {
                stn_offset = g->cstn - i * 8;
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, g->stncol_number, g->stntbl_ptr[stn_offset]);
            } else {
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, g->stncol_number, g->stntbl_ptr[0]);
            }
        } else {
            tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, g->stncol_number, g->stntbl_ptr[8]);
        }
        stn_number++;
    }
}



void stun_mark_write(s8 pl, s8 kind) {
    const u16* cells;
    s16 attr;
    PiyoriType* pt;
    STN_DAT* g;
    s8 i;
    stn_work = 0;
    stn_number = 0;
    if (pl == 1 && kind == 0) {
        ToneDown(7);
    }
    attr = 20;
    if (kind == 2) {
        cells = stngauge_puttbl[1];
    } else {
        cells = stngauge_puttbl[pl - kind];
    }
    if (kind == 1 && pl == 1) {
        attr = 148;
    }
    pt = &piyori_type[pl];
    g = &sdat[pl];
    for (i = 0; i < pt->genkai / 8; i++) {
        stn_work += 8;
        if (stn_work >= g->cstn) {
            if (g->cstn >= stn_work - 8) {
                stn_offset = g->cstn - i * 8;
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[stn_offset]);
            } else {
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[0]);
            }
        } else {
            tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[8]);
        }
        stn_number++;
    }
}



void stun_gauge_waku_write(s8 pl) {
    s8 i;
    if (pl == 0) {
        for (i = 0; i < 9 - sdat[0].slen; i++) {
            tilemap_put_cell(i + 11, 3, 2, 63);
        }
        tilemap_put_cell(i + 11, 3, 2, 110);
    } else {
        for (i = 0; i < 9 - sdat[1].slen; i++) {
            tilemap_put_cell(36 - i, 3, 2, 63);
        }
        tilemap_put_cell(36 - i, 3, 130, 110);
    }
}



void stngauge_work_clear(void) {
    sdat[0].cstn = 0;
    sdat[0].ostn = 0;
    sdat[0].sflag = 0;
    sdat[0].osflag = 0;
    sdat[0].g_or_s = 0;
    sdat[0].stimer = 2;
    sdat[0].proccess_dead = 0;
    stun_mark_write(0, 0);
    sdat[1].cstn = 0;
    sdat[1].ostn = 0;
    sdat[1].sflag = 0;
    sdat[1].osflag = 0;
    sdat[1].g_or_s = 0;
    sdat[1].stimer = 2;
    sdat[1].proccess_dead = 0;
    stun_mark_write(1, 1);
}
