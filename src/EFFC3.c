/*
 * EFFC3.C  Effect C3: the breakable parts of the bonus-stage car
 *
 * Seven C3 works (types 1-7) are spawned by the car effect C2 (EFFC2.C); each is one part of the
 * car with its own hit boxes, so the player's attacks land on the parts. effect_C3_move loads
 * the car's character set and part data, then each frame passes new damage to the car
 * (c3_new_damage), scores and throws debris when the part's break level rises
 * (check_parts_break_level, setup_effK2 / K3 / K4), and picks the cell and hit data for the
 * current break level from car_parts (set_display_car_parts). Parts 1-2 are drawn as cell sets
 * (disp_car_parts_cells), the rest as normal sprites (bs2_display_C3). When the car collapses
 * each part plays its break pattern; part 3 then follows the car's frame through effC3_nsc.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFC2.h"
#include "PLMAIN.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "HITCHECK.h"
#include "CHARID.h"
#include "CHARMOVE.h"
#include "EFFK2.h"
#include "EFFK3.h"
#include "EFFK4.h"
#include "EFFC3.h"



void effect_C3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.charset_id = 0x17;
        set_char_base_data(&ewk->wu);
        get_bs2_parts_data(&ewk->wu);
        clear_parts_hit_data(&ewk->wu);
        set_display_car_parts(ewk);
        clear_attack_num(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[1] = 1;
            break;
        }
        ewk->wu.dir_old = bs2_sync_bomb(&ewk->wu);
        if (EXE_flag == 0 && Game_pause == 0) {
            effC3_main_process(ewk);
        }
        if (ewk->wu.dir_old == 0) {
            hit_push_request(&ewk->wu);
        }
        bs2_display_C3(&ewk->wu);
        break;
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (check_effc2_p2_rno(&ewk->wu) == 0) {
                bs2_display_C3(&ewk->wu);
                break;
            }
            ewk->wu.disp_flag = 0;
            clear_parts_hit_data(&ewk->wu);
            if (ewk->wu.type != 3) {
                ewk->wu.routine_no[1] = 1;
            } else {
                ewk->wu.routine_no[1] = 10;
            }
            break;
        case 1:
            ewk->wu.routine_no[0] = 3;
            ewk->wu.routine_no[1] = 0;
            break;
        case 10:
            switch (get_efffC3_nsc(&ewk->wu, (WORK*)ewk->wu.my_effadrs)) {
            case 0:
                ewk->wu.disp_flag = 0;
                break;
            case 1:
                ewk->wu.disp_flag = 1;
                break;
            default:
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[1] = 1;
                break;
            }
            sort_push_request(&ewk->wu);
            break;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void bs2_display_C3(WORK* wk) {
    wk->position_x = wk->xyz[0].disp.pos + wk->next_x;
    wk->position_y = wk->xyz[1].disp.pos + wk->next_y;
    wk->next_y = 0;
    set_parts_priority(wk);
    if (wk->type < 3) {
        disp_car_parts_cells(wk);
        return;
    }
    sort_push_request(wk);
}



void set_display_car_parts(WORK_Other* wk) {
    const u16* adrs;
    bs2_get_parts_break(&wk->wu);
    adrs = car_parts[wk->wu.type - 1][wk->wu.scr_mv_y][wk->wu.scr_mv_x - 1];
    wk->wu.cg_number = adrs[0];
    wk->wu.h_bod = wk->wu.body_adrs + (wk->wu.cg_hit_ix = adrs[1]);
}



void clear_parts_hit_data(WORK* wk) {
    wk->cg_ja = wk->hit_ix_table[0];
    wk->h_bod = &wk->body_adrs[wk->cg_ja.boix];
    wk->h_cat = &wk->catch_adrs[wk->cg_ja.caix];
    wk->h_cau = &wk->caught_adrs[wk->cg_ja.cuix];
    wk->h_att = &wk->attack_adrs[wk->cg_ja.atix];
    wk->h_hos = &wk->hosei_adrs[wk->cg_ja.hoix];
    wk->h_han = &wk->hand_adrs[wk->cg_ja.bhix + wk->cg_ja.haix];
}



void effC3_main_process(WORK_Other* ewk) {
    if (ewk->wu.dir_old) {
        ewk->wu.routine_no[0] = 2;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
        bs2_get_parts_break(&ewk->wu);
        set_char_move_init2(&ewk->wu, 0, ewk->wu.dir_step + 7, ewk->wu.scr_mv_x, 0);
        if (ewk->wu.vital_old < 7) {
            setup_effK2_sync_bomb(&ewk->wu);
        }
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        break;
    case 1:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            c3_new_damage(&ewk->wu);
            ewk->wu.routine_no[2] = 1;
            break;
        case 1:
            if (check_parts_break_level(&ewk->wu)) {
                setup_effK2(&ewk->wu);
            }
            if (!setup_effK3(&ewk->wu)) {
                setup_effK4(&ewk->wu);
            }
            ewk->wu.routine_no[1] = 0;
            ewk->wu.routine_no[2] = 0;
            break;
        }
        break;
    }
    set_display_car_parts(ewk);
    get_shizumi_guai(&ewk->wu);
}



s32 get_efffC3_nsc(wk, c2wk)
WORK* wk;
WORK* c2wk;
{
    u16 num = c2wk->cg_number - 0xB202;
    wk->position_x = c2wk->position_x;
    wk->position_y = c2wk->position_y;
    wk->position_z = c2wk->position_z + 2;
    if (num < 6) {
        wk->cg_number = effC3_nsc[num];
        return 1;
    }
    if (c2wk->routine_no[0] == 2 && c2wk->routine_no[1] == 1) {
        return -1;
    }
    return 0;
}



s32 effect_C3_init(WORK_Other* wk, s16 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 123;
    ewk->wu.type = data;
    ewk->my_master = (u32*)wk->my_master;
    ewk->wu.target_adrs = wk->wu.target_adrs;
    ewk->wu.my_effadrs = (u32*)wk;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    return 0;
}
