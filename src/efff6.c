/*
 * EFFF6.C  Opening demo moving sprites (effect F6)
 *
 * Sprites of the attract-mode opening that slide into place. Like EFF36, each object is
 * active between a start and an end value of the opening timeline op_w.index.
 * effect_F6_init(typenum) reads colour, position, priority, animation and timing from
 * efff6_data_tbl00 and direction, target point, zoom and speeds from efff6_etc_data.
 * efff6_move_common moves the sprite along X, Y or a diagonal until it reaches its target;
 * efff6_move01 adds a short colour ramp (type 0x1B). Created from end_main.c and LOSE_PL.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "efff6.h"



void effect_F6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (ewk->wu.old_rno[1] <= op_w.index) {
            ewk->wu.routine_no[0] += 1;
        } else if (ewk->wu.old_rno[2] <= op_w.index) {
            if (ewk->wu.type == 0x1B) {
                efff6_move01(ewk);
            } else {
                efff6_move(ewk);
            }
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void efff6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        if (ewk->wu.my_mr.size.x == 0x3F) {
            ewk->wu.my_mr_flag = 0;
        } else {
            ewk->wu.my_mr_flag = 1;
        }
    case 1:
        efff6_move_common(ewk);
        disp_pos_trans_entry5(ewk);
        break;
    }
}



void efff6_move_common(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[3]) {
    case 0:
        switch (ewk->wu.direction) {
        case 0x20:
            add_x_sub(ewk);
            if (ewk->wu.xyz[0].disp.pos <= ewk->wu.old_rno[3]) {
                ewk->wu.routine_no[3] += 1;
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
            }
            break;
        default:
            break;
        case 0x10:
            add_x_sub(ewk);
            if (ewk->wu.xyz[0].disp.pos >= ewk->wu.old_rno[3]) {
                ewk->wu.routine_no[3] += 1;
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
            }
            break;
        case 0x200:
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos <= ewk->wu.old_rno[4]) {
                ewk->wu.routine_no[3] += 1;
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
            }
            break;
        case 0x100:
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos >= ewk->wu.old_rno[4]) {
                ewk->wu.routine_no[3] += 1;
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
            }
            break;
        case 0x120:
            work = 0;
            if (ewk->wu.xyz[0].disp.pos > ewk->wu.old_rno[3]) {
                add_x_sub(ewk);
            } else {
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
                work |= 1;
            }
            if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[4]) {
                add_y_sub(ewk);
            } else {
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
                work |= 0x10;
            }
            if (work == 0x11) {
                ewk->wu.routine_no[3] += 1;
            }
            break;
        case 0x220:
            work = 0;
            if (ewk->wu.xyz[0].disp.pos > ewk->wu.old_rno[3]) {
                add_x_sub(ewk);
            } else {
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
                work |= 1;
            }
            if (ewk->wu.xyz[1].disp.pos > ewk->wu.old_rno[4]) {
                add_y_sub(ewk);
            } else {
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
                work |= 0x10;
            }
            if (work == 0x11) {
                ewk->wu.routine_no[3] += 1;
            }
            break;
        case 0x110:
            work = 0;
            if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[3]) {
                add_x_sub(ewk);
            } else {
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
                work |= 1;
            }
            if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[4]) {
                add_y_sub(ewk);
            } else {
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
                work |= 0x10;
            }
            if (work == 0x11) {
                ewk->wu.routine_no[3] += 1;
            }
            break;
        case 0x210:
            work = 0;
            if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[3]) {
                add_x_sub(ewk);
            } else {
                ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[3];
                work |= 1;
            }
            if (ewk->wu.xyz[1].disp.pos > ewk->wu.old_rno[4]) {
                add_y_sub(ewk);
            } else {
                ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[4];
                work |= 0x10;
            }
            if (work == 0x11) {
                ewk->wu.routine_no[3] += 1;
            }
            break;
        }
        break;
    case 1:
        break;
    }
}



void efff6_move01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        if (ewk->wu.my_mr.size.x == 0x3F) {
            ewk->wu.my_mr_flag = 0;
        } else {
            ewk->wu.my_mr_flag = 1;
        }
        ewk->wu.old_rno[5] = 1;
        ewk->wu.old_rno[6] = 0;
    case 1:
        ewk->wu.old_rno[5] -= 1;
        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.old_rno[5] = 2;
            ewk->wu.old_rno[6] += 1;
            if (ewk->wu.old_rno[6] >= 6) {
                ewk->wu.routine_no[2] += 1;
            } else {
                ewk->wu.extra_col_2 = efff6_move01_tbl[ewk->wu.old_rno[6]];
            }
        }
    case 2:
        efff6_move_common(ewk);
        disp_pos_trans_entry5(ewk);
        break;
    }
}



s32 effect_F6_init(typenum)
u8 typenum;
{
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    data_ptr = efff6_data_tbl00[typenum];
    ewk->wu.id = 0x9C;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 0x10;
    ewk->wu.type = typenum;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = op_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0xC0;
    ewk->wu.my_col_code += *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    ewk->wu.direction = efff6_etc_data[typenum].dir;
    ewk->wu.old_rno[3] = efff6_etc_data[typenum].limit_x_pos;
    ewk->wu.old_rno[4] = efff6_etc_data[typenum].limit_y_pos;
    ewk->wu.my_mr.size.x = efff6_etc_data[typenum].zoom_v;
    ewk->wu.my_mr.size.y = efff6_etc_data[typenum].zoom_v;
    ewk->wu.mvxy.a[0].sp = efff6_etc_data[typenum].sp_x_a;
    ewk->wu.mvxy.d[0].sp = efff6_etc_data[typenum].sp_x_d;
    ewk->wu.mvxy.a[1].sp = efff6_etc_data[typenum].sp_y_a;
    ewk->wu.mvxy.d[1].sp = efff6_etc_data[typenum].sp_y_d;
    effect_F6_move(ewk);
    return 0;
}
