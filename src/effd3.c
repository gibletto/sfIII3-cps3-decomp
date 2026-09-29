/*
 * EFFD3.C  Screen wipe panels (D2) and special finish screens (D3)
 *
 * effect_D2 is one panel of the screen wipe used between scenes: effect_D2_init sets its
 * direction, delay and start point (effD2_pos_set); effD2_wipe_close slides it in and
 * effD2_wipe_open slides it out, both counting Wipe_Panel_Count down (created from SYS_sub).
 * effect_D3 runs the special finish screens (created from PLCNTSET): akebono_finish flashes
 * a sequence of BG3 pictures on the timings of ake_timer_tbl and then starts the effect G8
 * sparkles; syungoku_finish hides the fighters, shows the finishing picture with effect 20
 * and two effect L9 sprites, then sets the conclusion and requests the center message.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "SYS_sub.h"
#include "bg_sub.h"
#include "aboutspr.h"
#include "eff20.h"
#include "effg8.h"
#include "effect_L9_move.h"
#include "EFFECT.h"
#include "Manage.h"
#include "CHARMOVE.h"
#include "SE.h"
#include "textsound.h"
#include "effd3.h"



void effect_D2_move(WORK_Other* ewk) {
    EFFD3_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}



/* provisional name */
void effD2_wipe_close(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    case 2:
        if (ewk->wu.vital_new == 4) {
            tilemap_fill_all(62, 0xAF);
        }
        ewk->wu.routine_no[1]++;
        Wipe_Panel_Count--;
        break;
    }
    if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 0x100)) {
        ewk->wu.disp_flag = 0;
    } else {
        ewk->wu.disp_flag = 1;
    }
}



/* provisional name */
void effD2_wipe_open(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dir_timer = 3;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (--ewk->wu.dir_timer) {
            break;
        }
        ewk->wu.routine_no[1]++;
        tilemap_fill_all(0, 32);
        break;
    case 2:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
                Wipe_Panel_Count--;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Wipe_Panel_Count--;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_D2_init(s16 vital, s16 dir, s16 family, s16 timer) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 132;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x21FF;
    ewk->wu.my_family = family;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = 56;
    if (dir < 2) {
        ewk->wu.dir_step = 0;
    } else {
        ewk->wu.dir_step = 1;
    }
    ewk->wu.dm_vital = 512;
    ewk->wu.vital_new = vital;
    ewk->wu.direction = dir;
    ewk->wu.dir_timer = timer;
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 127;
    ewk->wu.my_mr.size.y = 127;
    effD2_pos_set(ewk);
    return 0;
}



/* provisional name */
void effD2_pos_set(WORK_Other* ewk) {
    if (ewk->wu.vital_new == 0) {
        switch (ewk->wu.direction) {
        case 0:
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 328;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 466;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + 496;
            break;
        case 1:
            ewk->wu.mvxy.a[0].sp = 0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 582;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 466;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos + 496;
            break;
        case 2:
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 582;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 240;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 512;
            break;
        case 3:
            ewk->wu.mvxy.a[0].sp = -0x100000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 328;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 240;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 512;
            break;
        }
    }
    ewk->wu.position_z = 6;
}



void effect_D3_move(WORK_Other* ewk) {
    if (ewk->wu.type == 0) {
        akebono_finish(ewk);
    } else {
        syungoku_finish(ewk);
    }
}



void akebono_finish(WORK_Other* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.dir_timer = ake_timer_tbl[0];
        ewk->wu.old_rno[0] = 13;
        ewk->wu.disp_flag = 0;
        for (i = 0; i < bg_w.scno; i++) {
            scroll_layer_mask_disable(1 << i);
        }
        scroll_layer_mask_enable(8);
        akebono_flag = 1;
        Sound_SE(117);
        scroll_layer_mask_disable(0x80);
        scrn_map_set(3, ake_scrl_w[1].adrs);
        Scrn_Move_Set(3, ake_pos_tbl[0][0] - bg_w.pos_offset, ake_pos_tbl[0][1]);
        bg_w.bgw[3].position_x = ake_pos_tbl[0][0] - bg_w.pos_offset;
        bg_w.bgw[3].position_y = ake_pos_tbl[0][1];
        break;
    case 1:
        ewk->wu.dir_timer -= 1;
        if (ewk->wu.dir_timer < 0) {
            akebono_flag = 1;
            ewk->wu.old_rno[1] += 1;
            if (ewk->wu.old_rno[1] < 4) {
                ewk->wu.dir_timer = ake_timer_tbl[ewk->wu.old_rno[1]];
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_Off_W(1 << i);
                }
                Bg_On_W(8);
            } else {
                ewk->wu.routine_no[0] += 1;
                effect_G8_init();
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_Off_W(1 << i);
                }
                Bg_On_W(8);
            }
        }
        scrn_map_set(3, ake_scrl_w[1].adrs);
        bg_w.bgw[3].position_x = ake_pos_tbl[ewk->wu.old_rno[1]][0] - bg_w.pos_offset;
        bg_w.bgw[3].position_y = ake_pos_tbl[ewk->wu.old_rno[1]][1];
        ake_Family_Set2();
        break;
    case 2:
        ewk->wu.dir_timer -= 1;
        if (ewk->wu.dir_timer < 0) {
            ewk->wu.old_rno[1] += 1;
            if (ewk->wu.old_rno[1] < ewk->wu.old_rno[0]) {
                ewk->wu.dir_timer = ake_timer_tbl[ewk->wu.old_rno[1]];
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_Off_W(1 << i);
                }
                Bg_On_W(8);
                akebono_flag = 1;
            } else {
                ewk->wu.routine_no[0] += 1;
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_On_W(1 << i);
                }
                if (scrn_reg_w[3].ctrl & 0x8000) {
                    Bg_Off_W(8);
                }
                akebono_flag = 0;
            }
        }
        scrn_map_set(3, ake_scrl_w[1].adrs);
        bg_w.bgw[3].position_x = ake_pos_tbl[ewk->wu.old_rno[1]][0] - bg_w.pos_offset;
        bg_w.bgw[3].position_y = ake_pos_tbl[ewk->wu.old_rno[1]][1];
        ake_Family_Set2();
        break;
    default:
        akebono_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void syungoku_finish(WORK_Other* ewk) {
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        akebono_flag = 1;
        Extra_Break = 1;
        Sound_SE(126);
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        Pause_Hit_Marks = 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_W(1 << i);
        }
        Bg_On_W(8);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ewk->wu.dir_timer = 2;
        scrn_map_set(3, ake_scrl_w[2].adrs);
        ake_Family_Set();
        break;
    case 1:
        ewk->wu.dir_timer -= 1;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.old_rno[0] = 0;
            effect_20_init(ewk);
            effect_L9_init(ewk, 0);
            effect_L9_init(ewk, 1);
        }
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    case 2:
        if (ewk->wu.old_rno[0]) {
            ewk->wu.routine_no[0] += 1;
            akebono_flag = 0;
            plw[0].wu.disp_flag = 1;
            plw[1].wu.disp_flag = 1;
            Pause_Hit_Marks = 0;
        }
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 768 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    case 3:
        ewk->wu.routine_no[0] += 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_On_W(1 << i);
        }
        Bg_Off_W(8);
        Conclusion_Flag = 1;
        Conclusion_Type = 0;
        request_center_message(0);
        scrn_map_set(3, ake_scrl_w[2].adrs);
        bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
        bg_w.bgw[3].position_y = 0;
        ake_Family_Set();
        break;
    default:
        akebono_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_D3_init(u8 ake_type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 133;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.old_rno[1] = 0;
    ewk->wu.type = ake_type;
    return 0;
}
