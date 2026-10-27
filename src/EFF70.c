/*
 * EFF70.C  Effect 70: character select face
 *
 * effect_70_init creates a face object at Face_Pos_Data for a character (from sel_pl) and
 * Setup_Eff70 fills in its id, colour, family and character table. effect_70_move shows it
 * after its delay, plays its animation, and when both players have finished selecting
 * shrinks it away.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF70.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait dir_timer, then appear */
#define R0_ANIM         1       /* play the face animation */
#define R0_STAY         2       /* until both players have chosen */
#define R0_PAUSE        3       /* wait dir_timer before shrinking */
#define R0_SHRINK       4       /* shrink away */
#define R0_KILL         99      /* (default) put the work back */

void effect_70_move(WORK_Other* ewk) {
    if (Suicide[0] == 1) {
        ewk->wu.routine_no[0] = R0_KILL;
        ewk->wu.disp_flag = 0;
    } else {
        switch (ewk->wu.routine_no[0]) {
        case R0_WAIT:
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 1;
                ewk->wu.position_z = 62;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
                ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
                set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
                sort_push_request4(&ewk->wu);
            }
            break;
        case R0_ANIM:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                Complete_Face--;
                ewk->wu.routine_no[0]++;
                ewk->wu.char_index = 0;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
            sort_push_request4(&ewk->wu);
            /* fallthrough */
        case R0_STAY:
            if (Play_Type == 1) {
                s16* complete;
                s32 mask;
                mask = 0x8000;
                complete = Sel_PL_Complete;
                if ((complete[0] & mask) && (complete[1] & mask)) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.dir_timer = 30;
                }
            }
            sort_push_request4(&ewk->wu);
            break;
        case R0_PAUSE:
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.my_mr_flag = 1;
                ewk->wu.my_mr.size.x = 63;
                ewk->wu.my_mr.size.y = 63;
                ewk->wu.mvxy.a[0].sp = 0x80000;
            }
            sort_push_request4(&ewk->wu);
            break;
        case R0_SHRINK:
            if ((ewk->wu.my_mr.size.x -= *(s16*)((u8*)ewk + 124)) <= 0) {
                ewk->wu.my_mr.size.x = 0;
            }
            if ((ewk->wu.my_mr.size.y -= *(s16*)((u8*)ewk + 124)) <= 0) {
                ewk->wu.my_mr.size.y = 0;
            }
            if (ewk->wu.my_mr.size.x <= 0 && ewk->wu.my_mr.size.y <= 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.my_mr_flag = 0;
                ewk->wu.disp_flag = 0;
                return;
            }
            sort_push_request4(&ewk->wu);
            break;
        default:
            all_cgps_put_back(ewk);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

s32 effect_70_init(s16 id) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    Setup_Eff70(&ewk->wu);
    ewk->wu.xyz[0].disp.pos = Face_Pos_Data[id][SEL_POS_X] + 512;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[id][SEL_POS_Y] + 0;
    ewk->wu.xyz[2].disp.pos = 62;
    ewk->wu.dir_step = id;
    ewk->wu.dir_timer = 10;
}



void Setup_Eff70(WORK* wk) {
    wk->be_flag = 1;
    wk->id = 70;
    wk->work_id = 16;
    wk->cgromtype = 1;
    wk->my_col_mode = 0x4200;
    wk->my_col_code = 0x2040;
    wk->my_family = 2;
    wk->char_index = 13;
    wk->char_table[0] = sel_pl_char_table;
}
