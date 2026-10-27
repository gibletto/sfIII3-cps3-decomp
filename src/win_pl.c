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
 * urien_dash handle Urien's dash. bonus_game_win_pause picks the pose after a bonus stage from
 * its result; meta_win_pause handles a winner who is not in his own character. Normal_normal_Winner is the default pose and
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
#include "charmove_2.h"
#include "EFF30.h"
#include "EFF31.h"
#include "EFF32.h"
#include "EFF82.h"
#include "EFF83.h"
#include "effL3.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "EFFM2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "lose_pl.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "SYS_sub.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sc_trans.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "end_main.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Com_Pl.h"
#include "win_pl.h"
#include "fighter.h"

/* win_rno[0] in Win_10000: Q's win */
#define QW_NORMAL       0       /* the plain pose (not the last round) */
#define QW_KEEP         1       /* walk up to the loser and stay (q_keeping_action) */
#define QW_LEAVE        2       /* walk up, then walk off (q_leave_after_action) */
#define QW_KEEP_67      3       /* QW_KEEP by a loser in animation 67; q_em_dir makes it QW_KEEP */
#define QW_LEAVE_67     4       /* QW_LEAVE by a loser in animation 67; q_em_dir makes it QW_LEAVE */

/* routine_no[3], Win_01000 */
#define W01_POSE        1       /* run the pose win_rno[0] chose */

/* wk->wu.routine_no[3] in a win or lose pose */
#define POSE_RUN        1       /* the pose runs until its script sets RN3_DONE */

/* win_rno[0] in Win_01000: Oro's win */
#define OW_NORMAL       0       /* the plain pose */
#define OW_FLY_UP       1       /* jijii_fly_up */
#define OW_JUMP         2       /* jijii_jump */
#define OW_FULL         3       /* jijii_full */

/* win_rno[1] in jijii_fly_up */
#define JF_START        0       /* until the take-off frame */
#define JF_RISE         1       /* rise off the top of the screen */
#define JF_END          2       /* the last pose */

/* win_rno[1] in jijii_jump */
#define JJ_START        0       /* until the jump frame */
#define JJ_JUMP         1       /* jump off the side of the screen */
#define JJ_SETUP        2       /* set up the return */
#define JJ_WAIT         3       /* wait win_free, then come in from the far side */
#define JJ_RETURN       4       /* walk back in */

/* win_rno[1] in jijii_full */
#define JFU_START       0       /* until the cue (cmwk[0] 1) */
#define JFU_RISE        1       /* rise to height 42 */
#define JFU_END         2       /* the last pose */

/* win_rno[1] in Win_05000 */
#define W5_FALL         0       /* fall to the ground */
#define W5_LAND         1       /* landed */

/* win_rno[1] in Win_09000 */
#define W9_START        0       /* until the cue (cmwk[0]) */
#define W9_POSE         1       /* the second pose */

/* win_rno[1] in the q_*_action routines */
#define Q_FACE          0       /* face the opponent, turning first if needed */
#define Q_TURN          1       /* until the turn is done */
#define Q_WALK_START    2       /* start walking */
#define Q_WALK          3       /* walk up to the opponent */
#define Q_STAND         4       /* stand there (q_leave_after_action: then turn away) */
#define Q_LEAVE         5       /* q_leave_after_action: walk off */

/* win_rno[0] in Win_11000: Twelve's win */
#define TW_NORMAL       0       /* the plain pose */
#define TW_AWAY         1       /* twelve_win_away */
#define TW_BACKJUMP     2       /* twelve_win_backjump */

/* win_rno[1] in twelve_win_away */
#define TA_START        0       /* until the take-off frame */
#define TA_RISE         1       /* rise */
#define TA_FLY          2       /* fly off the side of the screen */
#define TA_GONE         3       /* gone */

/* win_rno[1] in twelve_win_backjump */
#define TB_START        0       /* until the jump frame */
#define TB_JUMP         1       /* the back jump, until it lands */
#define TB_LAND         2       /* until the next cue */
#define TB_RISE         3       /* rise off the top of the screen */
#define TB_GONE         4       /* gone */

/* win_rno[1] in urien_dash */
#define UD_START        0       /* dash, or straight to the pose when close enough (urien_dash_chk) */
#define UD_RISE         1       /* until the dash starts */
#define UD_DASH         2       /* the dash, until it lands */
#define UD_LAND         3       /* dash again or stop */
#define UD_STOP         4       /* until the stop is done */
#define UD_POSE_INIT    5       /* set up the win pose */
#define UD_POSE         6       /* the win pose */

s16 poison_flag[2];  /* 020281A8 */
s16 win_rno[2];  /* 020281AC */
s16 a_rno;  /* 020281B0 */
s16 win_free[2];  /* 020281B2 */


void char_move(WORK* wk);
void char_move_cmja(WORK* wk);
void char_move_z(WORK* wk);
void set_char_move_init();
void set_char_move_init2();


/* provisional name */
void win_player(PLW* wk) {
    void (*win_jp_tbl[16])(PLW*) = { Win_00000, Win_01000, Win_02000, Win_03000, Win_04000, Win_05000, Win_06000, Win_07000, Win_08000, Win_09000, Win_10000, Win_11000, Win_12000, Win_13000, Win_14000, Win_15000 };
    if (My_char[wk->wu.id] != wk->player_number) {
        meta_win_pause(wk);
    } else if (Bonus_Game_Flag) {
        bonus_game_win_pause(wk);
    } else if (pcon_rno[0] == PCON_DIE && pcon_rno[1] == SETTLE_JUDGE) {
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
    case RN3_START:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        if ((Round_num >= Battle_Round[Play_Type] * 2) || (PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1)) {
            if (Round_Result & 0x800) {
                wk->wu.cmwk[0] = 0;
                set_char_move_init(&wk->wu, 9, 42);
                win_rno[0] = OW_FULL;
                break;
            }
            if (bg_w.stage == 9) {
                set_char_move_init(&wk->wu, 9, 41);
                win_rno[0] = OW_FLY_UP;
                break;
            }
            set_char_move_init(&wk->wu, 9, win_10000_tbl[1][work]);
            if (work == 4) {
                win_rno[0] = OW_JUMP;
            }
        } else {
            set_char_move_init(&wk->wu, 9, win_10000_tbl[0][work]);
            if (work == 4) {
                win_rno[0] = OW_JUMP;
            }
        }
        break;
    case W01_POSE:
    case RN3_DONE:
        switch (win_rno[0]) {
        case OW_NORMAL:
            char_move(&wk->wu);
            break;
        case OW_FLY_UP:
            jijii_fly_up(wk);
            break;
        case OW_JUMP:
            jijii_jump(wk);
            break;
        case OW_FULL:
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
    case JF_START:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            char_move_z(&wk->wu);
            wk->wu.mvxy.a[1].sp = 0xF0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }
        break;
    case JF_RISE:
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
    case JF_END:
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
    case JJ_START:
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
    case JJ_JUMP:
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
    case JJ_SETUP:
        win_rno[1]++;
        set_char_move_init2(&wk->wu, 9, 36, 7, 0);
        win_free[wk->wu.id] = 48;
        break;
    case JJ_WAIT:
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
    case JJ_RETURN:
        add_x_sub((WORK_Other*)wk);
        char_move(&wk->wu);
        break;
    }
}



void jijii_full(PLW* wk) {
    bg_app_stop = 1;
    switch (win_rno[1]) {
    case JFU_START:
        char_move(&wk->wu);
        if (wk->wu.cmwk[0] == 1) {
            win_rno[1]++;
        }
        break;
    case JFU_RISE:
        char_move(&wk->wu);
        wk->wu.xyz[1].cal += 0x10000;
        if (wk->wu.xyz[1].disp.pos >= 42) {
            win_rno[1]++;
            wk->wu.cmwk[0] = 2;
            set_char_move_init(&wk->wu, 9, 43);
        }
        break;
    case JFU_END:
        char_move(&wk->wu);
        break;
    }
}



void Win_02000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 3);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (win_2000_tbl[bg_w.bg_index]) {
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
    case RN3_START:
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
    s16 work;
    s16 work2;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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
    case POSE_RUN:
        char_move(&wk->wu);
        break;
    }
}



void Normal_normal_Winner(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        break;
    case POSE_RUN:
    case RN3_DONE:
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
    case RN3_START:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);
        set_char_move_init(&wk->wu, 9, work + 52);
        break;
    case POSE_RUN:
    case RN3_DONE:
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
    case RN3_START:
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
        work = win_select(wk, 3);
        set_char_move_init(&wk->wu, 9, work + 32);
        win_rno[0] = 1;
        break;
    default:
        if (win_rno[0]) {
            Normal_normal_Winner(wk);
            break;
        }
        switch (win_rno[1]) {
        case W5_FALL:
            char_move(&wk->wu);
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
            if (wk->wu.xyz[1].disp.pos < 0) {
                win_rno[1]++;
                wk->wu.xyz[1].cal = 0;
                char_move_z(&wk->wu);
            }
            break;
        case W5_LAND:
            char_move(&wk->wu);
            break;
        }
    }
}



void Win_06000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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
    case RN3_START:
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
                return;
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
            return;
        } else {
            win_rno[0] = 0;
            work = win_select(wk, 7);
            set_char_move_init(&wk->wu, 9, work + 32);
            break;
        }
    default:
        switch (win_rno[0]) {
        case 0:
            char_move(&wk->wu);
            return;
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
                return;
            }
            char_move(&wk->wu);
        }
    }
}



void Win_08000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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
    case RN3_START:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        if (work == 7) {
            set_char_move_init(&wk->wu, 9, 32);
        } else {
            set_char_move_init(&wk->wu, 9, (work) + 32);
        }
        if (Round_num < (Battle_Round[Play_Type] * 2) &&
            PL_Wins[wk->wu.id] < Battle_Round[Play_Type] + 1) {
            break;
        }
        if (!poison_flag[wk->wu.id]) {
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
        }
        break;
    default:
        if (win_rno[0]) {
            switch (win_rno[1]) {
            case W9_START:
                char_move(&wk->wu);
                if (wk->wu.cmwk[0]) {
                    win_rno[1]++;
                    set_char_move_init(&wk->wu, 9, 39);
                }
                break;
            case W9_POSE:
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
    s16 work;
    s16 work2;
    s16 id_w;
    bg_app_stop = 1;
    id_w = wk->wu.id ^ 1;
    wk->wu.position_z = wk->wu.next_z = plw[id_w].wu.position_z + 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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
                    win_rno[0] = QW_KEEP;
                } else {
                    win_rno[0] = QW_LEAVE;
                }
            } else if (work > 1) {
                if (work & 1) {
                    if (plw[id_w].wu.char_index != 67) {
                        win_rno[0] = QW_KEEP;
                    } else {
                        win_rno[0] = QW_KEEP_67;
                    }
                } else if (plw[id_w].wu.char_index != 67) {
                    win_rno[0] = QW_LEAVE;
                } else {
                    win_rno[0] = QW_LEAVE_67;
                }
            } else if (work & 1) {
                win_rno[0] = QW_KEEP;
            } else {
                win_rno[0] = QW_LEAVE;
            }
        } else {
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        switch (win_rno[0]) {
        case QW_NORMAL:
            Normal_normal_Winner(wk);
            break;
        case QW_KEEP:
        case QW_KEEP_67:
            q_keeping_action(wk);
            break;
        case QW_LEAVE:
        case QW_LEAVE_67:
            q_leave_after_action(wk);
            break;
        }
    }
}



s16 q_em_distance_chk(PLW* wk) {
    s16 work;
    s16 id_w;
    s16 rl_w;
    id_w = wk->wu.id ^ 1;
    rl_w = plw[id_w].wu.rl_flag ^ wk->wu.rl_flag;
    if (wk->wu.rl_flag) {
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
        if (win_rno[0] == QW_KEEP_67) {
            win_rno[0] = QW_KEEP;
            set_char_move_init(&wk->wu, 9, 36);
        } else if (win_rno[0] == QW_LEAVE_67) {
            win_rno[0] = QW_LEAVE;
            set_char_move_init(&wk->wu, 9, 36);
        }
        wk->wu.direction = wk->wu.rl_flag;
        win_rno[1] = Q_STAND;
        wk->wu.xyz[0].disp.pos = pos_w;
        return 0;
    }
    wk->wu.xyz[0].disp.pos = pos_w;
    return 1;
}



void q_keeping_action(PLW* wk) {
    switch (win_rno[1]) {
    case Q_FACE:
        if (q_em_dir(wk) != 0) {
            if (wk->wu.direction == wk->wu.rl_flag) {
                win_rno[1] = Q_WALK_START;
            } else {
                win_rno[1] = Q_TURN;
                set_char_move_init(&wk->wu, 9, 40);
                wk->wu.rl_flag ^= 1;
            }
        }
        break;
    case Q_TURN:
        char_move(&wk->wu);
        if ((u8)wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }
        break;
    case Q_WALK_START:
        (win_rno[1])++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
        } else {
            wk->wu.mvxy.a[0].sp = -0x1C000;
        }
        break;
    case Q_WALK:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (q_em_distance_chk(wk)) {
            win_rno[1]++;
            set_char_move_init(&wk->wu, 9, win_rno[0] == 1 ? 36 : 37);
        }
        break;
    case Q_STAND:
        char_move(&wk->wu);
        break;
    }
}



void q_leave_after_action(PLW* wk) {
    s16 work;
    switch (win_rno[1]) {
    case Q_FACE:
        if (q_em_dir(wk)) {
            if (wk->wu.direction == wk->wu.rl_flag) {
                win_rno[1] = Q_WALK_START;
                break;
            }
            win_rno[1] = Q_TURN;
            set_char_move_init(&wk->wu, 9, 40);
            wk->wu.rl_flag ^= 1;
        }
        break;
    case Q_TURN:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }
        break;
    case Q_WALK_START:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }
        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;
    case Q_WALK:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (q_em_distance_chk(wk)) {
            win_rno[1]++;
            if (win_rno[0] == 2) {
                set_char_move_init(&wk->wu, 9, 36);
            } else {
                set_char_move_init(&wk->wu, 9, 39);
            }
        }
        break;
    case Q_STAND:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            set_char_move_init(&wk->wu, 9, 41);
            wk->wu.mvxy.d[0].sp = 0;
            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x1C000;
                break;
            }
            wk->wu.mvxy.a[0].sp = -0x1C000;
        }
        break;
    case Q_LEAVE:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (wk->wu.rl_flag) {
            work = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
            work += 64;
            if (work < wk->wu.xyz[0].disp.pos) {
                win_rno[1]++;
            }
        } else {
            work = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
            work -= 64;
            if (work > wk->wu.xyz[0].disp.pos) {
                win_rno[1]++;
            }
        }
        break;
    }
}



/* provisional name */
void q_walk_past_action(PLW* wk) {
    switch (win_rno[1]) {
    case Q_FACE:
        q_em_dir(wk);
        if (wk->wu.direction == wk->wu.rl_flag) {
            win_rno[1] = Q_WALK_START;
            break;
        }
        win_rno[1] = Q_TURN;
        set_char_move_init(&wk->wu, 9, 40);
        wk->wu.rl_flag ^= 1;
        break;
    case Q_TURN:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }
        break;
    case Q_WALK_START:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }
        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;
    case Q_WALK:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)wk);
        if (q_em_distance_chk(wk)) {
            win_rno[1]++;
            set_char_move_init(&wk->wu, 9, 37);
        }
        break;
    case Q_STAND:
        char_move(&wk->wu);
        break;
    }
}



void Win_11000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        if (set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset), 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], (bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset), 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (Perfect_Flag) {
                win_rno[0] = TW_AWAY;
                set_char_move_init(&wk->wu, 9, 38);
                effect_L3_init(wk);
            } else {
                set_char_move_init(&wk->wu, 9, work + 36);
                switch (work) {
                case 0:
                    win_rno[0] = TW_BACKJUMP;
                    break;
                case 1:
                    break;
                default:
                    effect_L3_init(wk);
                    win_rno[0] = TW_AWAY;
                    break;
                }
            }
        } else {
            win_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, work + 32);
        }
        break;
    default:
        switch (win_rno[0]) {
        case TW_NORMAL:
            Normal_normal_Winner(wk);
            break;
        case TW_AWAY:
            twelve_win_away(wk);
            break;
        case TW_BACKJUMP:
            twelve_win_backjump(wk);
            break;
        }
        break;
    }
}

void twelve_win_away(PLW* wk) {
    switch (win_rno[1]) {
    case TA_START:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x78000;
            wk->wu.mvxy.d[1].sp = -0x6000;
        }
        break;
    case TA_RISE:
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
    case TA_FLY:
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        if (!range_x_check3((WORK*)wk, 208)) {
            win_rno[1]++;
        }
        break;
    case TA_GONE:
        break;
    }
}

void twelve_win_backjump(PLW* wk) {
    switch (win_rno[1]) {
    case TB_START:
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
    case TB_JUMP:
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
    case TB_LAND:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            win_rno[1]++;
        }
        break;
    case TB_RISE:
        char_move(&wk->wu);
        wk->wu.xyz[1].cal += 0x20000;
        if (wk->wu.xyz[1].disp.pos > 256) {
            win_rno[1]++;
        }
        break;
    case TB_GONE:
        break;
    }
}



void Win_12000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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
    case RN3_START:
        if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
        }
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        if (Round_num >= (Battle_Round[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= Battle_Round[Play_Type] + 1) {
            if (wk->wu.id) {
                if (p2sw_0 & BUTTON_START) {
                    set_char_move_init(&wk->wu, 9, 40);
                    break;
                }
            } else {
                if (p1sw_0 & BUTTON_START) {
                    set_char_move_init(&wk->wu, 9, 40);
                    break;
                }
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
    case RN3_START:
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
    case UD_START:
        win_rno[1]++;
        if (urien_dash_chk(wk)) {
            win_rno[1] = UD_POSE_INIT;
        } else {
            wk->wu.rl_flag = wk->wu.rl_waza;
            set_char_move_init(&wk->wu, 0, 4);
            setup_mvxy_data(&wk->wu, 2);
        }
    case UD_RISE:
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            add_mvxy_speed(&wk->wu);
            break;
        }
        char_move(&wk->wu);
        break;
    case UD_DASH:
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
    case UD_LAND:
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
    case UD_STOP:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 0xFF) {
            break;
        }
        win_rno[1]++;
    case UD_POSE_INIT:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 36);
        break;
    case UD_POSE:
        char_move(&wk->wu);
        break;
    }
}



void Win_15000(PLW* wk) {
    s16 work;
    bg_app_stop = 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
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


void bonus_game_win_pause(wk)
PLW *wk;
{
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[1],
                             bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset,
                             1)) {
        set_field_hosei_flag(&plw[1],
                             bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset,
                             0);
    }
    if (set_field_hosei_flag(&plw[0],
                             bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset,
                             1)) {
        set_field_hosei_flag(&plw[0],
                             bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset,
                             0);
    }

    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        if (Bonus_Game_Flag == BONUS_CAR) {
            if (wk->wu.operator) {
                if (Time_Over) {
                    set_char_move_init(&wk->wu, 9, 67);
                } else {
                    set_char_move_init(&wk->wu, 9, 65);
                }
            } else {
                wk->wu.routine_no[3] = 99;
            }
        } else {
            if (wk->wu.operator) {
                if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
                    set_char_move_init(&wk->wu, 9, 65);
                } else if (Bonus_Game_result > 10) {
                    set_char_move_init(&wk->wu, 9, 66);
                } else {
                    set_char_move_init(&wk->wu, 9, 67);
                }
            } else {
                if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
                    win_rno[0] = 1;
                    if (wk->wu.rl_flag) {
                        wk->wu.mvxy.a[0].sp = 0x20000;
                    } else {
                        wk->wu.mvxy.a[0].sp = -0x20000;
                    }
                    wk->wu.mvxy.d[0].sp = 0;
                    wk->wu.mvxy.a[1].sp = 0x80000;
                    wk->wu.mvxy.d[1].sp = -0x6000;
                    win_rno[0] = 0;
                    set_char_move_init(&wk->wu, 9, 66);
                } else {
                    set_char_move_init(&wk->wu, 9, 52);
                }
            }
        }
        break;

    case POSE_RUN:
    case RN3_DONE:
        char_move(&wk->wu);
        break;
    }
}



void meta_win_pause(PLW* wk) {
    bg_app_stop = 1;
    if (set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset, 0);
    }
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, meta_win_tbl[wk->player_number]);
        break;
    case POSE_RUN:
    case RN3_DONE:
        char_move(&wk->wu);
        break;
    }
}
