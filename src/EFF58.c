/*
 * EFF58.C  Effect 58: timed screen commands
 *
 * Effect 58 is a timer: after time0 frames it performs one screen command - stop a scroll,
 * screen switch or fill, the title logo, sound and BGM requests, set Next_Step, slide a BG
 * layer to its target, set a Suicide flag or move a virtual BG. Used by the game flow,
 * select, continue and ranking screens (Game_Main, Manage, Win, sel_pl, next_cpu, ...).
 * EFF58_Type_05 is the type routine for a marker that follows the player.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Eff59.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sc_trans.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "aboutspr.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF58.h"
#include "sc_logo.h"

/* routine_no[0] */
#define R0_WAIT         0       /* count the start time down */
#define R0_MOVE         1       /* carry out the command */
#define R0_KILL         99      /* (default) put the work back */

/* routine_no[1]: command, from effect_58_init */
#define R1_STOP         0       /* stop the scroll */
#define R1_SWITCH       1       /* switch the screen back after the cover */
#define R1_SIGN         2       /* show a sign */
#define R1_CLEAR        3       /* clear the screen and tone it down */
#define R1_NONE         4       /* do nothing */
#define R1_AREA         5       /* marker that follows the player */
#define R1_SOUND        6       /* sound request */
#define R1_NEXT         7       /* set Next_Step */
#define R1_BGM          8       /* music request */
#define R1_FADE_IN      9       /* fade the music in */
#define R1_LOGO         10      /* title logo */
#define R1_TONE         11      /* tone the screen down step by step */
#define R1_SLIDE3       12      /* slide a BG to its target, speed 3 */
#define R1_SLIDE5       13      /* slide a BG to its target, speed 5 */
#define R1_SLIDE        14      /* slide a BG to its target */
#define R1_SUICIDE      15      /* set a Suicide flag */
#define R1_VBG_256      16      /* move a virtual BG by 256 */
#define R1_VBG_512      17      /* move a virtual BG by 512 */
#define R1_VBG_2        18      /* place virtual BG 2 */

/* routine_no[2], EFF58_Type_01 */
#define R2_WAIT         0       /* count the cover time down */
#define R2_SWITCH       1       /* until the screen is back */

/* routine_no[2], EFF58_Type_02 */
#define R2_INIT         0       /* first frame: set up */
#define R2_SHOW         1       /* show until told to go */
#define R2_END          2       /* one more frame */

/* routine_no[2], EFF58_Type_05 */
#define R2_FOLLOW       1       /* follow the player */

/* routine_no[2], EFF58_Type_11 */
#define R2_KILL         99      /* (default) put the work back */



void effect_58_move(WORK_Other* ewk) {
    s16 xx;
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_MOVE:
        switch (ewk->wu.routine_no[1]) {
        case R1_STOP:
            Scrn_Move_Set(4, 0, 0);
            ewk->wu.routine_no[0] = R0_KILL;
            break;
        case R1_SWITCH:
            EFF58_Type_01(ewk);
            break;
        case R1_SIGN:
            EFF58_Type_02(ewk);
            break;
        case R1_CLEAR:
            EFF58_Type_03(ewk);
            break;
        case R1_NONE:
            break;
        case R1_AREA:
            EFF58_Type_05(ewk);
            break;
        case R1_SOUND:
            if (Demo_Sound != 0 || Demo_Flag) {
                sound_request(ewk->wu.direction);
            }
            push_effect_work(&ewk->wu);
            break;
        case R1_NEXT:
            Next_Step = 1;
            push_effect_work(&ewk->wu);
            break;
        case R1_BGM:
            if (Demo_Sound != 0 || Demo_Flag) {
                if (PB_Music_Off == 0) {
                    bgm_request(ewk->wu.direction);
                }
            }
            push_effect_work(&ewk->wu);
            break;
        case R1_FADE_IN:
            if (Demo_Sound != 0 || Demo_Flag) {
                if (!PB_Music_Off) {
                    sound_fade_in_submit(ewk->wu.direction, 0x222);
                }
            }
            push_effect_work(&ewk->wu);
            break;
        case R1_LOGO:
            SF33rd_Logo(ewk);
            break;
        case R1_TONE:
            EFF58_Type_11(ewk);
            break;
        case R1_SLIDE3:
            if (Cut_Scroll == 0) {
                xx = 3;
            } else {
                xx = Cut_Cut_Sub(3);
            }
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case R1_SLIDE5:
            if (Cut_Scroll == 0) {
                xx = 5;
            } else {
                xx = Cut_Cut_Sub(5);
            }
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case R1_SLIDE:
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;
            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    push_effect_work(&ewk->wu);
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                push_effect_work(&ewk->wu);
            }
            break;
        case R1_SUICIDE:
            Suicide[ewk->wu.direction] = 1;
            push_effect_work(&ewk->wu);
            break;
        case R1_VBG_256:
            bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos += 256;
            Setup_Virtual_BG(ewk->wu.direction,
                         bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                         bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            push_effect_work(&ewk->wu);
            break;
        case R1_VBG_512:
            bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos += 512;
            Setup_Virtual_BG(ewk->wu.direction,
                         bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                         bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            push_effect_work(&ewk->wu);
            break;
        case R1_VBG_2:
            Setup_Virtual_BG(2, 0x480, 0);
            push_effect_work(&ewk->wu);
            break;
        }
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_58_init(s16 id, s16 time0, s16 option) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 58;
    ewk->wu.work_id = 16;
    ewk->wu.dir_timer = time0;
    ewk->wu.dir_old = time0;
    ewk->wu.direction = option;
    ewk->wu.routine_no[1] = id;
    return 0;
}



/* provisional name */
s32 effect_58_area_init(s16 time0, s16 step) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 58;
    ewk->wu.work_id = 16;
    ewk->wu.dir_timer = 1;
    ewk->wu.dir_old = time0;
    ewk->wu.dir_step = step;
    ewk->wu.routine_no[1] = R1_AREA;
    return 0;
}



void EFF58_Type_01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_WAIT:
        if (--Cover_Timer) {
            break;
        }
        ewk->wu.routine_no[2]++;
        Switch_Screen_Init(0, 0);
        break;
    case R2_SWITCH:
        if (Switch_Screen_Revival()) {
            ewk->wu.routine_no[0] = R0_KILL;
        }
        break;
    }
}



void EFF58_Type_03(WORK_Other* ewk) {
    tilemap_fill_all(0, 32);
    ToneDown(0);
    ewk->wu.routine_no[0] = R0_KILL;
}



void EFF58_Type_02(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2]++;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2180;
        ewk->wu.my_family = 2;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].position_x + DE_X[10] + 0xC0;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].position_y + 200;
        ewk->wu.position_z = 38;
        if (Country == 1) {
            ewk->wu.dir_step = 34;
        } else {
            ewk->wu.dir_step = 37;
        }
        ewk->wu.char_index = 9;
        ewk->wu.char_table[0] = sel_pl_char_table;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case R2_SHOW:
        if (Suicide[0]) {
            ewk->wu.routine_no[2]++;
            break;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
            break;
        }
    case R2_END:
        ewk->wu.routine_no[2]++;
        return;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}


void EFF58_Type_05(WORK_Other* ewk) {
    s16 x;
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2]++;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.my_family = 2;
        ewk->wu.my_priority = plw[ewk->wu.dir_old].wu.my_priority - 10;
        ewk->wu.position_z = plw[ewk->wu.dir_old].wu.position_z - 10;
        ewk->wu.char_index = 26;
        ewk->wu.char_table[0] = sel_pl_char_table;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 11, 0);
        break;
    case R2_FOLLOW:
        x = Separate_Area[ewk->wu.dir_old][ewk->wu.dir_step - 1];
        if (plw[ewk->wu.dir_old].wu.rl_waza == 0) {
            x = -x;
        }
        ewk->wu.xyz[0].disp.pos = plw[ewk->wu.dir_old].wu.xyz[0].disp.pos + x;
        ewk->wu.xyz[1].disp.pos = plw[ewk->wu.dir_old].wu.xyz[1].disp.pos + 32;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void SF33rd_Logo(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case R2_INIT:
        ewk->wu.routine_no[2]++;
        SF3_logo(0);
        Switch_Screen_Init(5, 5);
        Stop_SG = 0;
        break;
    case R2_SWITCH:
        if (Switch_Screen_Revival()) {
            ewk->wu.routine_no[2]++;
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



void EFF58_Type_11(WORK_Other* ewk) {
    if (Break_Into) {
        ewk->wu.routine_no[2] = R2_KILL;
    }
    switch (ewk->wu.routine_no[2]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        ToneDown((s8)ewk->wu.routine_no[2] + 10);
        ewk->wu.routine_no[2]++;
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
