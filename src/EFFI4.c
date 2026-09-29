/*
 * EFFI4.C  Projectile (shell) processes 06 to 11 of effect 13
 *
 * These routines are entries of the kind-of-projectile table used by the projectile effect 13
 * (EFF13.c / EFF13_KOTP.c); each takes the shell work and its TAMA data record.
 *   kotp_06000  homing shell: turns toward a point on the opponent (homing_empos_hos,
 *               caldir_pos_256, rate_256_table) and trails effect I9 after-images
 *   kotp_07000  shell whose flight changes on frame type 20, turned toward the opponent
 *   kotp_08000 / kotp_09000  shells that fly until the timer, screen edge or floor
 *   kotp_11000  shell that falls to the floor and plays its landing pattern
 * Hits reduce the shell's vitality: a light hit spawns an effect 96 flash, enough damage plays
 * the defeat / hit / explode pattern (erdf / erht / erex); some shells change owner when
 * reflected. kotp_10000 plays a pattern to its end and finishes the shell.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CALDIR.h"
#include "EFFI9.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "EFF13.h"
#include "EFF96.h"
#include "CHARSET.h"
#include "EFFI4.h"



void kotp_06000(WORK_Other* ewk, TAMA* twk) {
    PLW* mwk;
    PLW* emwk;
    s16 dir;
    s16 emdir;
    s16* target_x;
    s16* target_y;
    s32 t;
    mwk = (PLW*)ewk->my_master;
    emwk = (PLW*)mwk->wu.target_adrs;
    target_x = &ewk->wu.E3_work_index;
    target_y = &ewk->wu.E4_work_index;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        switch (ewk->wu.routine_no[3]) {
        case 0:
            ewk->wu.routine_no[3]++;
            ewk->wu.kow = 6;
            ewk->wu.direction = ewk->wu.rl_flag ? twk->data01 : 256 - twk->data01 & 0xFF;
            effect_I9_init(ewk, 2, 3, 0x77);
            break;
        case 1:
            if (ewk->wu.kow--) {
                break;
            }
            ewk->wu.routine_no[3]++;
            ewk->wu.kow = 0x70;
        case 2:
            *target_x = homing_empos_hos[0][ewk->master_player][0];
            *target_x = mwk->wu.rl_flag ? emwk->wu.xyz[0].disp.pos - *target_x : emwk->wu.xyz[0].disp.pos + *target_x;
            *target_y = homing_empos_hos[0][ewk->master_player][1] + emwk->wu.xyz[1].disp.pos;
            dir = ewk->wu.direction;
            emdir = caldir_pos_256(ewk->wu.xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos, *target_x, *target_y);
            dir += (emdir - (dir - 0x80) & 0xFF) > 0x80 ? 4 : -4;
            dir = dir & 0xFF;
            t = rate_256_table[dir][0];
            t *= 480;
            ewk->wu.mvxy.a[0].sp = t / 256;
            ewk->wu.mvxy.a[0].sp *= ewk->wu.rl_flag ? 1 : -1;
            ewk->wu.mvxy.a[1].sp = (rate_256_table[dir][1] * 512) / 256;
            ewk->wu.direction = dir;
            if (ewk->wu.mvxy.a[0].sp < 0) {
                ewk->wu.routine_no[3]++;
            } else if (!ewk->wu.kow--) {
                ewk->wu.routine_no[3]++;
            }
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if ((ewk->wu.xyz[1].disp.pos + ewk->wu.cg_jphos) <= 0) {
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, twk->erex);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.xyz[1].disp.pos = -ewk->wu.cg_jphos;
            return;
        }
        if (--ewk->wu.dir_timer < 0 || screen_range_check(&ewk->wu) != 0) {
            ewk->wu.mvxy.a[0].sp /= 4;
            ewk->wu.mvxy.a[1].sp /= 4;
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 256) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    effect_96_init(&ewk->wu, twk->erdf, ewk->wu.disp_flag, ewk->wu.hit_stop);
                } else {
                    effect_96_init(&ewk->wu, twk->erht, ewk->wu.disp_flag, ewk->wu.hit_stop);
                }
            } else {
                effect_96_init(&ewk->wu, twk->erex, ewk->wu.disp_flag, ewk->wu.hit_stop);
            }
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



void kotp_07000(WORK_Other* ewk, TAMA* twk) {
    WORK* awk;
    s16 dsst;
    PLW* mwk;
    PLW* emwk;
    s16 tama_x;
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if (bg_w.stage == 21) {
            ewk->wu.vs_id = 7;
        }
        if (ewk->wu.cg_type == 20) {
            setup_mvxy_data(&ewk->wu, ewk->wu.mvxy.index);
            ewk->wu.mvxy.index++;
            ewk->wu.cg_type = 0;
            mwk = (PLW*)ewk->my_master;
            emwk = (PLW*)mwk->wu.target_adrs;
            tama_x = ewk->wu.xyz[0].disp.pos;
            if (tama_x > emwk->wu.xyz[0].disp.pos) {
                ewk->wu.mvxy.a[0].sp *= ewk->wu.rl_flag ? -1 : 1;
                ewk->wu.mvxy.d[0].sp *= ewk->wu.rl_flag ? -1 : 1;
            } else {
                ewk->wu.mvxy.a[0].sp *= ewk->wu.rl_flag ? 1 : -1;
                ewk->wu.mvxy.d[0].sp *= ewk->wu.rl_flag ? 1 : -1;
            }
        }
        if (--ewk->wu.dir_timer < 0) {
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
        }
        break;
    case 1:
        if (ewk->wu.hf.hit_flag == 0) {
            awk = (WORK*)ewk->wu.dmg_adrs;
            if (awk->work_id == 1) {
                dsst = 3;
                if (!(ewk->wu.dm_kind_of_waza & 0xF8)) {
                    dsst = (ewk->wu.dm_kind_of_waza / 2) & 3;
                }
                ewk->wu.dm_vital = kotp_07_dm_vital[dsst];
            } else {
                ewk->wu.dm_vital = kotp_07_dm_vital[2];
            }
        }
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 0x100) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    effect_96_init(&ewk->wu, twk->erdf, ewk->wu.disp_flag, ewk->wu.hit_stop);
                } else {
                    effect_96_init(&ewk->wu, twk->erht, ewk->wu.disp_flag, ewk->wu.hit_stop);
                }
            } else {
                effect_96_init(&ewk->wu, twk->erex, ewk->wu.disp_flag, ewk->wu.hit_stop);
            }
            if (ewk->dm_refrect) {
                ewk->master_id = (ewk->master_id + 1) & 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->dm_refrect = 0;
            }
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



void kotp_08000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if ((ewk->wu.xyz[1].disp.pos + ewk->wu.cg_jphos) <= 0) {
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, twk->erex);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.xyz[1].disp.pos = -ewk->wu.cg_jphos;
            break;
        }
        if (--ewk->wu.dir_timer >= 0 && !screen_range_check(&ewk->wu)) {
            break;
        }
        ewk->wu.mvxy.a[0].sp /= 4;
        ewk->wu.mvxy.a[1].sp /= 4;
        set_char_move_init(&ewk->wu, 0, twk->ernm);
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 256) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    effect_96_init(&ewk->wu, twk->erdf, ewk->wu.disp_flag, ewk->wu.hit_stop);
                } else {
                    effect_96_init(&ewk->wu, twk->erht, ewk->wu.disp_flag, ewk->wu.hit_stop);
                }
            } else if (ewk->dm_refrect) {
                effect_96_init(&ewk->wu, twk->erex, ewk->wu.disp_flag, ewk->wu.hit_stop);
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
                ewk->wu.routine_no[1] = 2;
                ewk->wu.routine_no[2] = 1;
                ewk->wu.kage_flag = 0;
                ewk->wu.hit_stop = 0;
            }
            if (ewk->dm_refrect) {
                ewk->master_id = (ewk->master_id + 1) & 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->dm_refrect = 0;
            }
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



void kotp_09000(WORK_Other* ewk, TAMA* twk) {
    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            set_char_move_init(&ewk->wu, 0, twk->ernm);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 0;
            break;
        }
        if ((ewk->wu.xyz[1].disp.pos + ewk->wu.cg_jphos) <= 0) {
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            set_char_move_init(&ewk->wu, 0, twk->erex);
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.xyz[1].disp.pos = -ewk->wu.cg_jphos;
            break;
        }
        if (--ewk->wu.dir_timer >= 0 && !screen_range_check(&ewk->wu)) {
            break;
        }
        ewk->wu.mvxy.a[0].sp /= 4;
        ewk->wu.mvxy.a[1].sp /= 4;
        set_char_move_init(&ewk->wu, 0, twk->ernm);
        ewk->wu.routine_no[1] = 2;
        ewk->wu.routine_no[2] = 0;
        break;
    case 1:
        ewk->wu.vital_new -= ewk->wu.dm_vital;
        ewk->wu.dm_vital = 0;
        if (ewk->wu.vital_new < 256) {
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
            } else {
                set_char_move_init(&ewk->wu, 0, twk->erex);
            }
            ewk->wu.routine_no[1] = 2;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.kage_flag = 0;
            ewk->wu.hit_stop = 0;
        } else {
            ewk->wu.routine_no[1] = 0;
            if (ewk->wu.hf.hit.player) {
                if (ewk->wu.hf.hit.player & 0xF0) {
                    set_char_move_init(&ewk->wu, 0, twk->erdf);
                } else {
                    set_char_move_init(&ewk->wu, 0, twk->erht);
                }
                ewk->wu.routine_no[1] = 2;
                ewk->wu.routine_no[2] = 1;
                ewk->wu.kage_flag = 0;
                ewk->wu.hit_stop = 0;
            } else {
                effect_96_init(&ewk->wu, twk->erex, ewk->wu.disp_flag, ewk->wu.hit_stop);
            }
            if (ewk->dm_refrect) {
                ewk->master_id = (ewk->master_id + 1) & 1;
                ewk->wu.rl_flag = (ewk->wu.rl_flag) + 1 & 1;
                ewk->dm_refrect = 0;
            }
        }
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.hit_quake = 0;
        break;
    case 2:
        switch (ewk->wu.routine_no[2]) {
        case 0:
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);
        case 1:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
            break;
        }
        break;
    }
}



void kotp_10000(WORK_Other* ewk) {
    char_move(&ewk->wu);
    if (ewk->wu.cg_type == 0xFF) {
        ewk->wu.routine_no[0] = 2;
    }
}



void kotp_11000(WORK_Other* ewk, TAMA* twk) {
    PLW* mwk = (PLW*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
        if (mwk->sa_stop_flag == 1) {
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.xyz[1].disp.pos <= 0) {
            ewk->wu.mvxy.a[1].sp = ewk->wu.mvxy.d[1].sp = ewk->wu.mvxy.kop[1] = 0;
            set_char_move_init(&ewk->wu, 0, twk->erex);
            ewk->wu.xyz[1].disp.pos = 0;
            ewk->wu.routine_no[1] = 2;
        }
        break;
    case 2:
        if (mwk->sa_stop_flag == 1) {
            break;
        }
        char_move(&ewk->wu);
        add_mvxy_speed(&ewk->wu);
        cal_mvxy_speed(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        }
        break;
    }
    if (ewk->wu.position_z == ewk->wu.next_z) {
        ewk->wu.position_z = ewk->wu.my_priority;
    } else {
        ewk->wu.position_z = ewk->wu.next_z;
    }
}
