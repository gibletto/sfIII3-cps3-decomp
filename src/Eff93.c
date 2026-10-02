/*
 * EFF93.C  Effects 87-93: stage objects, tilemap animations, win marks, face-select BG
 *
 * effect_87 / effect_88: stage background objects spawned from ROM records for the stage type and
 * compel flag; they animate while not paused and hide on compel_dead_check.
 * effect_89 (from Manage, Entry, EFF84, EFFA3, n_input): blinks the palette of a tilemap text
 * rectangle (eff89_cell_attr_set).
 * effect_90: a debug-toggled or master-following display on BG1.
 * effect_91: plays a tilemap cell animation into a rectangle, optionally looping.
 * effect_92_init (from Manage): draws a side's win marks from the win-mark request table and
 * raises the side's done flag.
 * effect_93 (from sel_pl): slides BG1 on the face-select screen (Eff93_SLIDE_L/R, SHIFT_L/R),
 * hiding and re-enabling the cursor; Bg_Family_Set_Ex sets up a BG family for sel_pl and Win.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "fifo.h"
#include "sys_test.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "Eff93.h"
#include "cps3.h"



void effect_87_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_s(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_87_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = eff87_loop_tbl[type][bg_w.compel_flag];
    s16 i;
    const s16* data_ptr;
    if (!lp_cnt) {
        return;
    }
    for (data_ptr = scr_obj_data87[type][bg_w.compel_flag], i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 87;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = type;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.hit_stop = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(ewk);
    }
    return 0;
}



void effect_88_move(WORK_Other* ewk) {
    if (obr_disp_off_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll && ewk->wu.hit_stop) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_88_init(s16 type) {
    s16 n;
    s16 i;
    s16 s;
    const s16* t;
    WORK_Other* o;
    n = eff88_loop_tbl[type][bg_w.compel_flag];
    if (n != 0) {
        t = scr_obj_data88[type][bg_w.compel_flag];
        for (i = 0; i < n; i++) {
            s = pull_effect_work(4);
            if (s == -1) {
                return -1;
            }
            o = (WORK_Other*)frw[s];
            o->wu.be_flag = 1;
            o->wu.id = 88;
            o->wu.work_id = 16;
            o->wu.cgromtype = 1;
            o->wu.rl_flag = 0;
            o->wu.my_col_mode = 0x4200;
            o->wu.dead_f = *t++;
            o->wu.my_family = *t++;
            o->wu.my_col_code = *t++;
            o->wu.xyz[0].disp.pos = *t++;
            o->wu.xyz[1].disp.pos = *t++;
            o->wu.my_priority = o->wu.position_z = *t++;
            o->wu.char_index = *t++;
            o->wu.hit_stop = *t++;
            o->wu.sync_suzi = *t++;
            o->wu.char_table[0] = char_add[bg_w.bg_index];
            suzi_offset_set(o);
        }
        return 0;
    }
}

/* Animated text-layer panel: steps through its attribute script, repainting
   the panel each step.  It freezes (and is removed) while a screen wipe or a
   break-in is running, unless it is type 6. */
void effect_89_move(WORK_Other* ewk)
{
    volatile s16 attr;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dir_timer = 1;
        ewk->wu.dir_step = ewk->wu.vitality;
        ewk->wu.step_xy_table = &EFF89_Step_Data[ewk->wu.direction];
        ewk->wu.move_xy_table = ewk->wu.step_xy_table;
        /* fall through */
    case 1:
        if (ewk->wu.type != 6 && (Exec_Wipe || Break_Into)) {
            ewk->wu.routine_no[0] = 99;
            break;
        }
        if (--ewk->wu.dir_timer != 0) {
            break;
        }
        attr = *ewk->wu.move_xy_table++;
        ewk->wu.dir_timer = *ewk->wu.move_xy_table++;
        eff89_cell_attr_set(ewk, attr);
        if (--ewk->wu.dir_step != 0) {
            break;
        }
        if (ewk->wu.dir_old) {
            ewk->wu.dir_step = ewk->wu.vitality;
            ewk->wu.move_xy_table = ewk->wu.step_xy_table;
        } else {
            ewk->wu.routine_no[0] = 2;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void eff89_cell_attr_set(WORK_Other* ewk, s16 attr) {
    SCR_CELL* cell;
    SCR_CELL* row;
    u16* p;
    s16 h;
    s16 w;
    cell = (SCR_CELL*)(ewk->wu.vital_new * 4 + (ewk->wu.vital_old << 8) + SS_RAM);
    row = cell;
    for (h = ewk->wu.dmcal_m; h > 0; h--) {
        for (w = ewk->wu.dm_vital; w > 0; w--) {
            p = &cell->attr;
            *p = (*p & 1) | attr;
            cell++;
        }
        row += 64;
        cell = row;
        continue;
    }
}



s32 effect_89_init(type, a, b, c, d)
s16 type;
s16 a;
s16 b;
s16 c;
s16 d;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 89;
    ewk->wu.type = type;
    ewk->wu.vital_new = a;
    ewk->wu.vital_old = b;
    ewk->wu.dm_vital = c;
    ewk->wu.dmcal_m = d;
    ewk->wu.direction = EFF89_Init_Data[type][0];
    ewk->wu.dir_old = EFF89_Init_Data[type][1];
    ewk->wu.vitality = EFF89_Init_Data[type][2];
    return 0;
}



void effect_90_move(WORK_Other* ewk) {
    WORK* mwk;
    s16 sw;
    if (ewk->wu.type == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        case 1:
            if (exsw_0 & 0x8000) {
                sw = p1sw_0 & ~p1sw_1;
                if (sw & 0x100) {
                    ewk->wu.disp_flag ^= 1;
                }
            }
            break;
        default:
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
            break;
        }
    } else {
        mwk = (WORK*)ewk->my_master;
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;
        case 1:
            if (mwk->disp_flag) {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos;
                ewk->wu.disp_flag = 1;
                suzi_sync_pos_set(ewk);
                sort_push_request4(ewk);
            }
            break;
        default:
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
            break;
        }
    }
}


/* provisional name */
s32 effect_90_dummy(void) {
    return 0;
}



void effect_91_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dir_timer = 1;
        ewk->wu.dir_step = ewk->wu.vitality;
        ewk->wu.step_xy_table = &EFF91_Step_Data[ewk->wu.direction];
        ewk->wu.move_xy_table = ewk->wu.step_xy_table;
    case 1:
        if (--ewk->wu.dir_timer == 0) {
            eff91_cell_data_set(ewk);
            if (--ewk->wu.dir_step == 0) {
                if (ewk->wu.dir_old) {
                    ewk->wu.dir_step = ewk->wu.vitality;
                    ewk->wu.move_xy_table = ewk->wu.step_xy_table;
                } else {
                    ewk->wu.routine_no[0] = 2;
                }
            }
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Paint the next frame of the text-layer panel: the script holds a
   { code, attr } pair for every cell of the dm_vital x dmcal_m rectangle
   whose top-left cell is (vital_new, vital_old).  Bit 8 of the attribute
   carries the code's bank bit. */
/* provisional name */
void eff91_cell_data_set(WORK_Other* ewk)
{
    SCR_CELL* row;
    SCR_CELL* cell;
    s16* code;
    u16 attr;
    s16 h;
    s16 w;

    row = (SCR_CELL*)(ewk->wu.vital_new * 4 + (ewk->wu.vital_old << 8) + SS_RAM);
    ewk->wu.dir_timer = *ewk->wu.move_xy_table++;
    for (h = ewk->wu.dmcal_m; h > 0; h--) {
        cell = row;
        for (w = ewk->wu.dm_vital; w > 0; w--) {
            code = ewk->wu.move_xy_table++;
            attr = *ewk->wu.move_xy_table++;
            cell->attr = attr;
            cell->code = *code | ((attr & 0x100) >> 8);
            cell++;
        }
        row += 64;
    }
}



s32 effect_91_init(s16 type, s16 a, s16 b, s16 c, s16 d) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 91;
    ewk->wu.vital_new = a;
    ewk->wu.vital_old = b;
    ewk->wu.dm_vital = c;
    ewk->wu.dmcal_m = d;
    ewk->wu.direction = EFF91_Init_Data[type][0];
    ewk->wu.dir_old = EFF91_Init_Data[type][1];
    ewk->wu.vitality = EFF91_Init_Data[type][2];
    return 0;
}



void effect_92_move(WORK_Other* ewk) {
    u16 kind;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        kind = *ewk->wu.move_xy_table++;
        ewk->wu.dir_timer = *ewk->wu.move_xy_table++;
        if (kind == 0x8000) {
            kind = ewk->wu.dmcal_m;
        }
        win_mark_put(ewk->master_id * 4 + PL_Wins[ewk->master_id] - 1, kind, win_mark_col_tbl[kind]);
        if (ewk->wu.dir_timer == -1) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 1;
        }
        break;
    default:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        win_mark_new[ewk->master_id] = 1;
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* provisional name */
s32 effect_92_init(s16 master_id, s16 cal) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 92;
    ewk->master_id = master_id;
    ewk->wu.dmcal_m = cal;
    ewk->wu.move_xy_table = Rewrite_Mark_Data;
    ewk->wu.dir_timer = 1;
    return 0;
}


void effect_93_move(WORK_Other* ewk) {
    Eff93_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
}



void Eff93_SLIDE_L(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.hit_quake = 0x25C;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
            ewk->wu.direction = bg_w.bgw[1].xy[1].disp.pos + 16;
            ewk->wu.mvxy.a[0].sp = 0x90000;
            ewk->wu.mvxy.a[1].sp = 0;
            cal_delta_speed(&ewk->wu, 10, ewk->wu.hit_quake, ewk->wu.direction, 1, 1);
            bg_mvxy.a[0].sp = ewk->wu.mvxy.a[0].sp;
            bg_mvxy.a[1].sp = ewk->wu.mvxy.a[1].sp;
            bg_mvxy.d[0].sp = ewk->wu.mvxy.d[0].sp;
            bg_mvxy.d[1].sp = ewk->wu.mvxy.d[1].sp;
            ewk->wu.dir_timer = 10;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        bg_w.bgw[1].wxy[1].cal += bg_mvxy.a[1].sp;
        bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
        bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
        if (--ewk->wu.dir_timer == 0) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].xy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].wxy[1].disp.pos = ewk->wu.direction;
            bg_w.bgw[1].xy[1].disp.pos = ewk->wu.direction;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_R(WORK_Other* ewk) {
    s16 arrived_x;
    s16 arrived_y;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = -0x90000;
            bg_mvxy.d[0].sp = -0x8000;
            ewk->wu.hit_quake = 0x25C;
            bg_mvxy.a[1].sp = -0x10000;
            bg_mvxy.d[1].sp = 0;
            bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
            ewk->wu.direction = bg_w.bgw[1].xy[1].disp.pos - 8;
        }
        break;
    default:
        arrived_x = 0;
        arrived_y = 0;
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            bg_w.bgw[1].xy[0].disp.pos = ewk->wu.hit_quake;
            arrived_x = 1;
        }
        bg_w.bgw[1].wxy[1].cal += bg_mvxy.a[1].sp;
        bg_mvxy.a[1].sp += bg_mvxy.d[1].sp;
        bg_w.bgw[1].xy[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos;
        if (ewk->wu.direction >= bg_w.bgw[1].wxy[1].disp.pos) {
            bg_w.bgw[1].wxy[1].disp.pos = ewk->wu.direction;
            bg_w.bgw[1].xy[1].disp.pos = ewk->wu.direction;
            arrived_y = 1;
        }
        if ((arrived_x != 0) && (arrived_y != 0)) {
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_L_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = 0x80000;
            bg_mvxy.d[0].sp = 0x28000;
            ewk->wu.hit_quake = bg_w.bgw[1].wxy[0].disp.pos + 208;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake <= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Eff93_SLIDE_R_OUT(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1] += 1;
            bg_mvxy.a[0].sp = -0x80000;
            bg_mvxy.d[0].sp = -0x28000;
            ewk->wu.hit_quake = 0x130;
        }
        break;
    default:
        bg_w.bgw[1].wxy[0].cal += bg_mvxy.a[0].sp;
        bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= bg_w.bgw[1].wxy[0].disp.pos) {
            bg_w.bgw[1].wxy[0].disp.pos = ewk->wu.hit_quake;
            Appear_Cursor = 1;
            Face_Move = 0;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void Bg_Family_Set_Ex(s16 xx) {
    s16 pos_work_x;
    s16 pos_work_y;
    bg_w.bgw[xx].position_x = bg_w.bgw[xx].xy[0].disp.pos & 0x3FF;
    pos_work_x = bg_w.bgw[xx].position_x;
    bg_w.bgw[xx].position_y = bg_w.bgw[xx].xy[1].disp.pos & 0x3FF;
    pos_work_y = bg_w.bgw[xx].position_y;
    Scrn_Move_Set(xx, pos_work_x, pos_work_y);
    pos_work_x = -pos_work_x & 0x3FF;
    pos_work_y = (0x300 - (pos_work_y & 0x3FF)) & 0x3FF;
    Family_Set_W(xx + 1, pos_work_x, pos_work_y);
}



s32 effect_93_init(s8 Move_Type, s16 Time) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x5D;
    ewk->wu.dir_timer = Time;
    ewk->wu.routine_no[0] = Move_Type;
    Appear_Cursor = 0;
    return 0;
}
