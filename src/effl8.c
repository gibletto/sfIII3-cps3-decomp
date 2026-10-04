/*
 * EFFL8.C  Super art palette effect for player 17 (effect L8)
 *
 * Created from player 17's move code (PLPAT17) during its super art. effect_L8_init only
 * starts for player number 17 and uses the player's colour choice as its type.
 * effect_L8_move saves 12 words of each of the player's two palette blocks in palette RAM
 * (COLOR_RAM), loads timed colours from effL8_data_tbl (check_new_color_data_L8,
 * get_new_color_data_L8), raises the player's att_plus to 14 and blocks special moves; when
 * the effect ends or the super art finishes it restores the palettes and settings.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effl8.h"
#include "cps3.h"
#include "fighter.h"



s32 effect_L8_move(WORK_Other* ewk) {
    PLW* mwk;
    s16* save_old_col_ptr;

    mwk = (PLW*)ewk->my_master;
    save_old_col_ptr = (s16*)&ewk->wu.zu_flag;
    ewk->wu.rl_flag = mwk->wu.rl_flag;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.hit_adrs = (u32*)effL8_data_tbl[ewk->wu.type];
        ewk->wu.step_xy_table = (s16*)((ewk->master_id == 1) * 0x800 + COLOR_RAM);
        ewk->wu.move_xy_table = (s16*)((u8*)ewk->wu.step_xy_table + 0x400);
        ewk->wu.dir_timer = 0;
        ewk->wu.dir_step = 0;
        ewk->wu.dir_old = 1;
        save_old_color_data(save_old_col_ptr, ewk->wu.step_xy_table);
        check_new_color_data_L8(&ewk->wu);
        mwk->att_plus = 14;
        spmv_ng_save = mwk->spmv_ng_flag;
        mwk->spmv_ng_flag |= 16;
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (mwk->sa->ok != -1) {
            ewk->wu.routine_no[0]++;
            break;
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        load_old_color_data(save_old_col_ptr, ewk->wu.step_xy_table);
        load_old_color_data(save_old_col_ptr, ewk->wu.move_xy_table);
        mwk->att_plus = 8;
        mwk->spmv_ng_flag = spmv_ng_save;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



void check_new_color_data_L8(WORK_Other* ewk) {
    if (--ewk->wu.dir_timer >= 0) {
        return;
    }
    if (ewk->wu.dir_old) {
        ewk->wu.dir_step = 0;
    } else {
        ewk->wu.dir_step++;
    }
    if (ewk->wu.rl_flag) {
        get_new_color_data_L8(ewk, ewk->wu.hit_adrs, ewk->wu.step_xy_table);
        get_new_color_data_L8(ewk, ewk->wu.hit_adrs, ewk->wu.move_xy_table);
    } else {
        get_new_color_data_L8(ewk, ewk->wu.hit_adrs, ewk->wu.move_xy_table);
        get_new_color_data_L8(ewk, ewk->wu.hit_adrs, ewk->wu.step_xy_table);
    }
}



void get_new_color_data_L8(WORK* wk, ColorCode* trom, s16* tram) {
    const s16* data;
    s16 i;
    wk->dir_timer = trom[wk->dir_step].timer;
    wk->dir_old = trom[wk->dir_step].endcode;
    data = trom[wk->dir_step].adrs;
    for (i = 0; i < 12; i++) {
        *tram++ = *data++;
    }
}


void save_old_color_data(s16* wram, s16* tram) {
    s16 i;
    for (i = 0; i < 12; i++) {
        *wram++ = *tram++;
    }
}



void load_old_color_data(s16* wram, s16* tram) {
    s16 i;
    for (i = 0; i < 12; i++) {
        *tram++ = *wram++;
    }
}



s32 effect_L8_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (wk->player_number != PL_KARATE) {
        return 0;
    }
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 218;
    ewk->wu.work_id = 16;
    ewk->wu.type = Player_Color[wk->wu.id];
    ewk->my_master = (u32*)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    return 0;
}
