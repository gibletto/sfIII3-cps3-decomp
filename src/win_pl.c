/*
 * win_pl.c  Round winner poses
 *
 * Player routines for the winner at the end of a round. win_player sends a player who
 * is not in his own character to meta_win_pause, a bonus stage winner to bonus_game_win_pause,
 * and otherwise picks the character's win routine (Win_00000..Win_15000) by win_type_tbl.
 * Each win routine chooses a victory animation, often at random (win_select), with a different
 * set for the final round and some stage-specific poses. Several have their own movement:
 * the jijii_* routines fly up, jump or run a full sequence for the old man's poses, the q_*
 * routines make Q keep his distance, walk past or leave the opponent, and urien_dash_chk /
 * urien_dash handle Urien's dash. Normal_normal_Winner is the default pose and
 * Judge_normal_winner is used for a special match state. Appear_41000 is an entrance
 * routine (appearance type 41) and jijii_nebukuro is called from the player main loop.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFM7.h"
#include "PLS02.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "EFF30.h"
#include "EFF31.h"
#include "EFF32.h"
#include "EFF82.h"
#include "EFF83.h"
#include "effL3.h"
#include "EFFL4.h"
#include "EFFM2.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "lose_pl.h"
#include "win_pl.h"
#include "fighter.h"



void Appear_41000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        set_char_move_init(&wk->wu, 0, 0);
        app_counter[wk->wu.id] = 0x78;
        effect_M7_init(wk);
        break;
    case 1:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }
        break;
    }
}



void jijii_nebukuro(wk)
PLW* wk;
{
    if (wk->wu.cmwk[0] == 0) {
        char_move(&wk->wu);
        return;
    }
    switch (wk->wu.routine_no[6]) {
    case 0:
        wk->wu.routine_no[6]++;
        set_char_move_init(&wk->wu, 1, 60);
        char_move_z(&wk->wu);
        wk->wu.xyz[1].disp.pos = -6;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[6]++;
        }
    case 2:
        if (wk->player_number == PL_GILL) {
            Gill_Pos_X = wk->wu.xyz[0].disp.pos;
        }
        break;
    }
}



/* provisional name */
void win_player(PLW* wk) {
    void (*win_jp_tbl[16])(PLW*) = { Win_00000, Win_01000, Win_02000, Win_03000, Win_04000, Win_05000, Win_06000, Win_07000, Win_08000, Win_09000, Win_10000, Win_11000, Win_12000, Win_13000, Win_14000, Win_15000 };
    if (My_char[wk->wu.id] != wk->player_number) {
        meta_win_pause(wk);
    } else if (Bonus_Game_Flag) {
        bonus_game_win_pause(wk);
    } else if (pcon_rno[0] == 2 && pcon_rno[1] == 3) {
        Judge_normal_winner(wk);
    } else {
        win_jp_tbl[win_type_tbl[wk->player_number]](wk);
    }
}



/* Win pose type 0: the standard winning pose. */
void Win_00000(PLW* wk) {
    Normal_normal_Winner(wk);
}



void Win_01000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[1] = 0;
        win_rno[0] = 0;
        wk->wu.routine_no[3]++;
        work = random_16_com() & 7;
        if ((Round_num >= Battle_Round[Play_Type] * 2) || (PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1)) {
            if (Round_Result & 0x800) {
                wk->wu.cmwk[0] = 0;
                set_char_move_init(&wk->wu, 9, 42);
                win_rno[0] = 3;
                break;
            }
            if (bg_w.stage == 9) {
                set_char_move_init(&wk->wu, 9, 41);
                win_rno[0] = 1;
                break;
            }
            set_char_move_init(&wk->wu, 9, win_10000_tbl[work + 8]);
        } else {
            set_char_move_init(&wk->wu, 9, win_10000_tbl[work]);
        }
        if (work == 4) {
            win_rno[0] = 2;
        }
        break;
    case 1:
    case 9:
        switch (win_rno[0]) {
        case 0:
            char_move(&wk->wu);
            break;
        case 1:
            jijii_fly_up(wk);
            break;
        case 2:
            jijii_jump(wk);
            break;
        case 3:
            jijii_full(wk);
            break;
        }
        break;
    }
}



/* provisional name */
void jijii_fly_up(PLW* wk) {
    bg_app_stop = 1;
    switch (win_rno[1]) {
    case 0:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            char_move_z(&wk->wu);
            wk->wu.mvxy.a[1].sp = 0xF0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }
        break;
    case 1:
        if (wk->wu.cg_type != 2) {
            char_move(&wk->wu);
        }
        add_y_sub((WORK_Other*)wk);
        if (wk->wu.xyz[1].disp.pos > 256) {
            win_rno[1]++;
            win_sp_flag = 2;
            set_char_move_init(&wk->wu, 9, 40);
            wk->wu.xyz[1].disp.pos = 200;
        }
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
}



void jijii_jump(PLW* wk) {
    s16 id_w;
    bg_app_stop = 1;
    id_w = wk->wu.id ^ 1;
    wk->wu.position_z = plw[id_w].wu.position_z - 1;
    wk->wu.my_priority = wk->wu.position_z;
    switch (win_rno[1]) {
    case 0:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            win_rno[1]++;
            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x60000;
                wk->wu.mvxy.d[0].sp = 0x1000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x60000;
                wk->wu.mvxy.d[0].sp = -0x1000;
            }
            wk->wu.mvxy.a[1].sp = 0xA0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }
        break;
    case 1:
        if (wk->wu.cg_type != 99) {
            char_move(&wk->wu);
        }
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        if (wk->wu.rl_flag) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].xy[0].disp.pos + 320) {
                win_rno[1]++;
                effect_work_kill(3, 13);
            }
            break;
        }
        if (wk->wu.xyz[0].disp.pos < bg_w.bgw[1].xy[0].disp.pos - 320) {
            win_rno[1]++;
            effect_work_kill(3, 13);
        }
        break;
    case 2:
        win_rno[1]++;
        set_char_move_init2(&wk->wu, 9, 36, 7, 0);
        win_free[wk->wu.id] = 48;
        break;
    case 3:
        win_free[wk->wu.id]--;
        if (win_free[wk->wu.id] > 0) {
            break;
        }
        win_rno[1]++;
        if (wk->wu.rl_flag) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos - 328;
            wk->wu.mvxy.a[0].sp = 0x18000;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + 328;
            wk->wu.mvxy.a[0].sp = -0x18000;
        }
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.xyz[1].cal = 0;
    case 4:
        add_x_sub((WORK_Other*)wk);
        char_move(&wk->wu);
        break;
    }
}



void jijii_full(PLW* wk) {
    bg_app_stop = 1;
    switch (win_rno[1]) {
    case 0:
        char_move(&wk->wu);
        if (wk->wu.cmwk[0] == 1) {
            win_rno[1]++;
        }
        break;
    case 1:
        char_move(&wk->wu);
        wk->wu.xyz[1].cal += 0x10000;
        if (wk->wu.xyz[1].disp.pos >= 42) {
            win_rno[1]++;
            wk->wu.cmwk[0] = 2;
            set_char_move_init(&wk->wu, 9, 43);
        }
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
}



void Win_02000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 3);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (win_02000_tbl[bg_w.bg_index]) {
                set_char_move_init(&wk->wu, 9, work + 36);
            } else if (work & 1) {
                set_char_move_init(&wk->wu, 9, 32);
            } else {
                set_char_move_init(&wk->wu, 9, 38);
            }
        } else {
            set_char_move_init(&wk->wu, 9, 32);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_03000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 15);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (bg_w.stage == 7) {
                set_char_move_init(&wk->wu, 9, 43);
                break;
            }
            set_char_move_init(&wk->wu, 9, Win_3001_tbl[work]);
            if (Win_3001_tbl[work] == 41) {
                win_rno[0] = 1;
            }
            break;
        }
        set_char_move_init(&wk->wu, 9, Win_3000_tbl[work]);
        break;
    default:
        if (win_rno[0]) {
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.disp_flag = 0;
                win_rno[0] = 0;
            }
            break;
        }
        char_move(&wk->wu);
        break;
    }
}



void Win_04000(PLW* wk) {
    s32 work;
    s32 work2;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 3);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            set_char_move_init(&wk->wu, 9, work + 36);
            break;
        }
        switch (work) {
        case 1:
        case 3:
            if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
                work2 = wk->wu.cg_ix / wk->wu.cgd_type;
                work2 += 2;
                set_char_move_init2(&wk->wu, 9, work + 32, work2, 0);
            } else {
                set_char_move_init(&wk->wu, 9, work + 32);
            }
            break;
        default:
            set_char_move_init(&wk->wu, 9, work + 32);
            break;
        }
        break;
    default:
    case 1:
        char_move(&wk->wu);
        break;
    }
}



void Normal_normal_Winner(PLW* wk) {
    u16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void Judge_normal_winner(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);
        set_char_move_init(&wk->wu, 9, work + 52);
        break;
    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }
}



void Win_05000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type]) {
            set_char_move_init(&wk->wu, 9, 36);
            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x20000;
            }
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            win_rno[0] = 0;
            break;
        }
        work = random_16_com() & 3;
        set_char_move_init(&wk->wu, 9, work + 32);
        win_rno[0] = 1;
        break;
    default:
        if (win_rno[0]) {
            Normal_normal_Winner(wk);
            break;
        }
        switch (win_rno[1]) {
        case 0:
            char_move(&wk->wu);
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
            if (wk->wu.xyz[1].disp.pos < 0) {
                win_rno[1]++;
                wk->wu.xyz[1].cal = 0;
                char_move_z(&wk->wu);
            }
            break;
        case 1:
            char_move(&wk->wu);
            break;
        }
    }
}



void Win_06000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_07000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work = win_select(wk, 7);
            if (work <= 3) {
                if (plw[0].player_number == PL_NECRO && plw[1].player_number == PL_NECRO) {
                    win_rno[0] = 0;
                    set_char_move_init(&wk->wu, 9, work + 32);
                    break;
                }
                effect_82_init(&wk->wu);
                win_rno[0] = 1;
                set_char_move_init(&wk->wu, 9, 60);
                wk->wu.cmwk[1] = 0;
                break;
            }
            if (plw[0].player_number == PL_NECRO && plw[1].player_number == PL_NECRO) {
                win_rno[0] = 0;
                set_char_move_init(&wk->wu, 9, work + 32);
                break;
            }
            effect_83_init(&wk->wu);
            win_rno[0] = 2;
            set_char_move_init(&wk->wu, 9, 60);
            wk->wu.cmwk[1] = 0;
            break;
        }
        win_rno[0] = 0;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        break;
    default:
        switch (win_rno[0]) {
        case 0:
            char_move(&wk->wu);
            break;
        default:
            if (win_rno[1] == 0) {
                if (wk->wu.cmwk[1]) {
                    win_rno[1]++;
                    if (win_rno[0] == 1) {
                        set_char_move_init(&wk->wu, 9, 32);
                    } else {
                        set_char_move_init(&wk->wu, 9, 37);
                    }
                    break;
                }
                char_move(&wk->wu);
                break;
            }
            char_move(&wk->wu);
        }
    }
}



void Win_08000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_Result & 0x800) {
            set_char_move_init(&wk->wu, 9, 40);
        } else if (Round_num >= (Battle_Round[Play_Type] * 2) ||
                   PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_09000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = random_16_com() & 7;
        if (work == 7) {
            set_char_move_init(&wk->wu, 9, 32);
        } else {
            set_char_move_init(&wk->wu, 9, (work) + 32);
        }
        if (Round_num < (Battle_Round[Play_Type] * 2) &&
            PL_Wins[wk->wu.id] < Battle_Round[Play_Type] + 1) {
            break;
        }
        if (poison_flag[wk->wu.id] != 0) {
            break;
        }
        switch (work) {
        case 0:
            effect_L6_init(&wk->wu, 0);
            break;
        case 3:
            effect_30_init(&wk->wu);
            break;
        case 4:
            effect_31_init(&wk->wu);
            break;
        case 5:
            effect_32_init(&wk->wu);
            break;
        case 7:
            wk->wu.cmwk[0] = 0;
            effect_L6_init(&wk->wu, 1);
            set_char_move_init(&wk->wu, 0, 0);
            win_rno[0] = 1;
            break;
        }
        break;
    default:
        if (win_rno[0] != 0) {
            switch (win_rno[1]) {
            case 0:
                char_move(&wk->wu);
                if (wk->wu.cmwk[0] != 0) {
                    win_rno[1]++;
                    set_char_move_init(&wk->wu, 9, 39);
                }
                break;
            case 1:
                char_move(&wk->wu);
                break;
            }
            break;
        }
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_10000(PLW* wk) {
    u16 work;
    u16 work2;
    u16 id_w;
    bg_app_stop = 1;
    id_w = wk->wu.id ^ 1;
    wk->wu.position_z = wk->wu.next_z = plw[id_w].wu.position_z + 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work2 = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;
            if (work2 < 0) {
                work2 = -work2;
            }
            if (work2 > 224) {
                if (work & 1) {
                    win_rno[0] = 1;
                } else {
                    win_rno[0] = 2;
                }
            } else if (work > 1) {
                if (work & 1) {
                    if (plw[id_w].wu.char_index != 67) {
                        win_rno[0] = 1;
                    } else {
                        win_rno[0] = 3;
                    }
                } else if (plw[id_w].wu.char_index != 67) {
                    win_rno[0] = 2;
                } else {
                    win_rno[0] = 4;
                }
            } else if (work & 1) {
                win_rno[0] = 1;
            } else {
                win_rno[0] = 2;
            }
        } else {
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        switch (win_rno[0]) {
        case 0:
            Normal_normal_Winner(wk);
            break;
        case 1:
        case 3:
            q_keeping_action(wk);
            break;
        case 2:
        case 4:
            q_leave_after_action(wk);
            break;
        }
    }
}



s16 q_em_distance_chk(PLW* wk) {
    s16 work;
    s16 id_w = wk->wu.id ^ 1;
    s16 rl_w = wk->wu.rl_flag ^ plw[id_w].wu.rl_flag;
    if (wk->wu.rl_flag != 0) {
        work = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;
        if (work >= q_em_distance_tbl[plw[id_w].player_number][rl_w]) {
            return 1;
        }
    } else {
        work = plw[id_w].wu.xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
        if (work >= q_em_distance_tbl[plw[id_w].player_number][rl_w]) {
            return 1;
        }
    }
    return 0;
}



s32 q_em_dir(PLW* wk) {
    s16 work;
    s16 pos_w;
    s16 id_w = wk->wu.id ^ 1;
    work = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;
    if (work < 0) {
        wk->wu.direction = 1;
    } else {
        wk->wu.direction = 0;
    }
    pos_w = wk->wu.xyz[0].disp.pos;
    if (q_em_distance_chk(wk)) {
        if (win_rno[0] == 3) {
            win_rno[0] = 1;
            set_char_move_init(&wk->wu, 9, 36);
        } else if (win_rno[0] == 4) {
            win_rno[0] = 2;
            set_char_move_init(&wk->wu, 9, 36);
        }
        wk->wu.direction = wk->wu.rl_flag;
        win_rno[1] = 4;
        wk->wu.xyz[0].disp.pos = pos_w;
        return 0;
    }
    wk->wu.xyz[0].disp.pos = pos_w;
    return 1;
}



void q_keeping_action(PLW* wk) {
    switch (win_rno[1]) {
    case 0:
        if (!q_em_dir(wk)) {
            break;
        }
        if (wk->wu.direction == wk->wu.rl_flag) {
            win_rno[1] = 2;
            break;
        }
        win_rno[1] = 1;
        set_char_move_init(&wk->wu, 9, 40);
        wk->wu.rl_flag = wk->wu.rl_flag ^ 1;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            break;
        }
        break;
    case 2:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }
        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;
    case 3:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (!q_em_distance_chk(wk)) {
            break;
        }
        win_rno[1]++;
        if (win_rno[0] == 1) {
            set_char_move_init(&wk->wu, 9, 36);
            break;
        }
        set_char_move_init(&wk->wu, 9, 37);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



s32 q_leave_after_action(PLW* wk) {
    s16 work;
    s16 rc;
    switch (rc = win_rno[1]) {
    case 0:
        if ((rc = q_em_dir(wk)) == 0) {
            return rc;
        }
        if (wk->wu.direction == wk->wu.rl_flag) {
            return win_rno[1] = 2;
        }
        win_rno[1] = 1;
        set_char_move_init(&wk->wu, 9, 40);
        return wk->wu.rl_flag ^= 1;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            return ++win_rno[1];
        }
        return 0x215;
    case 2:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.mvxy.a[0].sp = (wk->wu.rl_flag) ? 0x1C000 : -0x1C000;
        return 124;
    case 3:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if ((rc = q_em_distance_chk(wk)) == 0) {
            return rc;
        }
        win_rno[1]++;
        if (win_rno[0] == 2) {
            set_char_move_init(&wk->wu, 9, 36);
        } else {
            set_char_move_init(&wk->wu, 9, 39);
        }
        return;
    case 4:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 0xFF) {
            return 0x215;
        }
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.mvxy.a[0].sp = (wk->wu.rl_flag) ? 0x1C000 : -0x1C000;
        return 124;
    case 5:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (wk->wu.rl_flag) {
            work = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
            work += 64;
            if (work < wk->wu.xyz[0].disp.pos) {
                return ++win_rno[1];
            }
            return 100;
        }
        work = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
        work -= 64;
        if (work > wk->wu.xyz[0].disp.pos) {
            return ++win_rno[1];
        }
        return 100;
    }
    return rc;
}



/* provisional name */
void q_walk_past_action(PLW* wk) {
    switch (win_rno[1]) {
    case 0:
        q_em_dir(wk);
        if (wk->wu.direction == wk->wu.rl_flag) {
            win_rno[1] = 2;
            break;
        }
        win_rno[1] = 1;
        set_char_move_init(&wk->wu, 9, 40);
        wk->wu.rl_flag ^= 1;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }
        break;
    case 2:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }
        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;
    case 3:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (q_em_distance_chk(wk)) {
            win_rno[1]++;
            set_char_move_init(&wk->wu, 9, 37);
        }
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Win_11000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (wk->wu.routine_no[3] == 0) {
        if (set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset), 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset), 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = random_16_com() & 3;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (Perfect_Flag) {
                win_rno[0] = 1;
                set_char_move_init(&wk->wu, 9, 38);
                effect_L3_init(wk);
                return;
            }
            set_char_move_init(&wk->wu, 9, work + 36);
            switch (work) {
            case 0:
                win_rno[0] = 2;
                break;
            case 1:
                break;
            default:
                effect_L3_init(wk);
                win_rno[0] = 1;
                break;
            }
        } else {
            win_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        return;
    }
    switch (win_rno[0]) {
    case 0:
        Normal_normal_Winner(wk);
        break;
    case 1:
        switch (win_rno[1]) {
        case 0:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 1) {
                win_rno[1]++;
                wk->wu.mvxy.a[0].sp = 0;
                wk->wu.mvxy.d[0].sp = 0;
                wk->wu.mvxy.a[1].sp = 0x78000;
                wk->wu.mvxy.d[1].sp = -0x6000;
            }
            break;
        case 1:
            add_y_sub((WORK_Other*)wk);
            char_move(&wk->wu);
            if (wk->wu.cg_type != 2) {
                break;
            }
            win_rno[1]++;
            wk->wu.mvxy.d[0].sp = 0;
            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x80000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x80000;
            }
            wk->wu.mvxy.a[1].sp = -0x8000;
            wk->wu.mvxy.d[1].sp = 0x4000;
            break;
        case 2:
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
            if (!range_x_check3((WORK_Other*)wk, 208)) {
                win_rno[1]++;
            }
            break;
        }
        break;
    case 2:
        switch (win_rno[1]) {
        case 0:
            if (set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset), 1)) {
                set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset), 0);
            }
            char_move(&wk->wu);
            if (wk->wu.cg_type == 1) {
                win_rno[1]++;
                wk->wu.mvxy.a[0].sp = 0x30000;
                wk->wu.mvxy.d[0].sp = 0;
                wk->wu.mvxy.a[1].sp = 0x78000;
                wk->wu.mvxy.d[1].sp = -0x5000;
                if (wk->wu.rl_flag) {
                    wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
                }
            }
            break;
        case 1:
            if (set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset), 1)) {
                set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset), 0);
            }
            add_y_sub((WORK_Other*)wk);
            add_x_sub((WORK_Other*)wk);
            char_move(&wk->wu);
            if (wk->wu.cg_type == 2) {
                win_rno[1]++;
                char_move_z(&wk->wu);
                wk->wu.xyz[1].cal = 0;
            }
            break;
        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 9) {
                win_rno[1]++;
            }
            break;
        case 3:
            char_move(&wk->wu);
            wk->wu.xyz[1].cal += 0x20000;
            if (wk->wu.xyz[1].disp.pos > 256) {
                win_rno[1]++;
            }
            break;
        }
        break;
    }
}



void Win_12000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            effect_M2_init(&wk->wu, 1);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_13000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (wk->wu.id ? (p2sw_0 & 0x1000) : (p1sw_0 & 0x1000)) {
                set_char_move_init(&wk->wu, 9, 40);
                break;
            }
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



void Win_14000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work = win_select(wk, 3);
            if (!(work & 1)) {
                win_rno[0] = 1;
            } else {
                set_char_move_init(&wk->wu, 9, work + 36);
            }
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        if (win_rno[0]) {
            urien_dash(wk);
        } else {
            Normal_normal_Winner(wk);
        }
        break;
    }
}


s32 urien_dash_chk(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;
    s16 pos_w = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;
    if (pos_w < 0) {
        pos_w = -pos_w;
        if (!wk->wu.rl_waza) {
            wk->wu.rl_waza = 1;
        }
    } else if (wk->wu.rl_waza) {
        wk->wu.rl_waza = 0;
    }
    if (pos_w < 88) {
        return 1;
    }
    return 0;
}



void urien_dash(PLW* wk) {
    switch (win_rno[1]) {
    case 0:
        win_rno[1]++;
        if (urien_dash_chk(wk)) {
            win_rno[1] = 5;
        } else {
            wk->wu.rl_flag = wk->wu.rl_waza;
            set_char_move_init(&wk->wu, 0, 4);
            setup_mvxy_data(&wk->wu, 2);
        }
    case 1:
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            add_mvxy_speed(&wk->wu);
            break;
        }
        char_move(&wk->wu);
        break;
    case 2:
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        if (wk->wu.xyz[1].disp.pos + wk->wu.cg_jphos > 0) {
            break;
        }
        win_rno[1]++;
        wk->wu.position_y = 0;
        wk->wu.xyz[1].cal = 0;
        wk->wu.mvxy.a[1].sp = 0;
        char_move_cmja(&wk->wu);
        break;
    case 3:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 64) {
            break;
        }
        if (urien_dash_chk(wk)) {
            win_rno[1]++;
        } else {
            win_rno[1] = 0;
        }
        break;
    case 4:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 0xFF) {
            break;
        }
        win_rno[1]++;
    case 5:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 36);
        break;
    case 6:
        char_move(&wk->wu);
        break;
    }
}



void Win_15000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case 0:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            work = win_select(wk, 7);
            set_char_move_init(&wk->wu, 9, Win_15000_tbl[work]);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        Normal_normal_Winner(wk);
        break;
    }
}



s32 win_select(PLW* wk, s16 num) {
    s16 work = random_16_com();
    work &= num;
    return work;
}
