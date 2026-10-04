/*
 * EFFI6.C  Effect I6: round-call line
 *
 * Effect I6 is a child of the round-call effect (effect_I6_init, called from effb2.c) placed at
 * screen centre on BG4. It follows its parent's state: it starts pattern 3 at zero size
 * (effi6_line_move), copies the parent's zoom, hides with it and is freed with it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "effi6.h"



void effect_I6_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr = (WORK_Other*)ewk->my_master;
    switch (oya_ptr->wu.routine_no[0]) {
    case 2:
        effi6_line_move(ewk);
    case 3:
        ewk->wu.my_mr.size.x = oya_ptr->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_ptr->wu.my_mr.size.y;
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        ewk->wu.disp_flag = 0;
        disp_pos_trans_entry5(ewk);
        break;
    case 5:
    case 99:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effi6_line_move(WORK_Other* ewk) {
    WORK_Other* oya_ptr = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.my_mr.size.y = 0;
        set_char_move_init2(&ewk->wu, 0, 2, 3, 0);
    case 1:
        break;
    }
}



s32 effect_I6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xBA;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)oya;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x1E0;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = 0x90;
    return 0;
}
