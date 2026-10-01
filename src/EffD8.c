/*
 * EFFD8.C  Effect D8: face cursor on the character select screen
 *
 * effect_D8_entry (from sel_pl) allocates the face cursor for a player and cursor type, and
 * effect_D8_init places it on the face grid; Setup_Face_Offset_X gives the grid offset for the
 * play type.
 * effect_D8_move appears once the face screen is ready, jumps to the new face whenever the
 * player's Cursor_X / Cursor_Y change, animates while choosing and plays the decided animation
 * when Sel_PL_Complete is set.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EffD8.h"



void effect_D8_move(WORK_Other* ewk) {
    s32 offset_x;
    ewk->wu.hit_quake += 1;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Complete_Face == 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.dir_timer = 10;
        }
        break;
    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 2:
        if ((ewk->wu.vital_new != Cursor_X[ewk->master_id]) || (ewk->wu.vital_old != Cursor_Y[ewk->master_id])) {
            ewk->wu.vital_new = Cursor_X[ewk->master_id];
            ewk->wu.vital_old = Cursor_Y[ewk->master_id];
            if (Play_Type == 1) {
                offset_x = Setup_Face_Offset_X(99);
            } else {
                offset_x = Setup_Face_Offset_X(Play_Type_1st);
            }
            ((s32(*)())effect_D8_init)(ewk, offset_x);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.cg_ix / ewk->wu.cgd_type) + 1, 0);
        }
        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.dir_timer = 20;
            ewk->wu.char_index += 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        } else {
            char_move(&ewk->wu);
        }
        break;
    case 3:
        if (--ewk->wu.dir_timer) {
            char_move(&ewk->wu);
        } else {
            ewk->wu.routine_no[0] += 1;
            Sel_PL_Complete[ewk->master_id] = -0x8000;
            if (Select_Start[ewk->master_id] == 0) {
                Select_Timer = 32;
            }
            Unit_Of_Timer = 50;
            ewk->wu.char_index += 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case 4:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    if (ewk->wu.direction == 0) {
        if (ewk->wu.hit_quake & 1) {
            ewk->wu.position_z = 56;
        } else {
            ewk->wu.position_z = 54;
        }
    }
    sort_push_request4(&ewk->wu);
}



/* provisional name */
/* PL_id is reused for the face offset. */
s32 effect_D8_entry(s16 PL_id, s16 Type) {
    s16 ix;
    WORK_Other* ewk;

    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8A;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 2;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = (Type * 3) + 43;
    ewk->master_id = PL_id;
    ewk->wu.vital_new = Cursor_X[ewk->master_id];
    ewk->wu.vital_old = Cursor_Y[ewk->master_id];
    ewk->wu.position_z = D8_Priority_Data[Type];
    ewk->wu.direction = Type;
    ewk->wu.hit_quake = 0;
    PL_id = Setup_Face_Offset_X(Play_Type_1st);
L1:
    effect_D8_init(ewk, PL_id);
    return 0;
}



void effect_D8_init(WORK_Other* ewk, s16 offset_x) {
    s16 xx = ID_of_Face[Cursor_Y_low[ewk->master_id * 2]][Cursor_X[ewk->master_id]];
    ewk->wu.xyz[0].disp.pos = Face_Pos_Data[xx][0] + 512;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[xx][1] + 0;
}



s32 Setup_Face_Offset_X(x)
s32 x;
{
    switch (x) {
    case 0:
        return 0;
    case 1:
        return -184;
    default:
        return -92;
    }
}
