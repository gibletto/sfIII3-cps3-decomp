/*
 * EFF79.C  Effect 79: super art selection plates
 *
 * Effect 79 is one of the super art plates on the art selection screen, created by effect_79_init
 * (from sel_pl) with the player, plate number, position slot, delay and BG.
 * effect_79_move follows the player's input state (Check_Play_Status_79) and rotates the plates
 * when the selection moves (Setup_Move_79, Move_79, EFF79_Move_X / EFF79_Move_Y with speed and
 * depth helpers), changing depth once the plate reaches the front (Check_Priority).
 * Setup_Command_Name decides which plate shows its command name (Disp_Command_Name, drawn by
 * effect 80), and Select_End_Sub_79 sends the chosen plate to its finish state and the
 * others off screen when the choice is made. Plate positions come from Plate_Pos_Data_79.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "Eff80.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Eff79.h"

/* routine_no[0] */
#define R0_WAIT         0       /* front plate: count the delay down */
#define R0_APPEAR       1       /* front plate: play the appearing pattern */
#define R0_START        2       /* front plate: start the selection */
#define R0_FAN_OUT      3       /* back plate: move out to its slot */
#define R0_START_BACK   4       /* back plate: start the selection */
#define R0_SELECT       5       /* turn with the selection until chosen */
#define R0_LEAVE        6       /* not chosen: go behind the chosen one */
#define R0_CHOSEN       7       /* chosen: move to the finish spot */
#define R0_DONE         8       /* stay at the finish spot */
#define R0_STAY         9       /* stay until told to die */
#define R0_END          10      /* hidden for a frame */
#define R0_KILL         11      /* (default) put the work back */

/* routine_no[1], back plate moving out */
#define R1_WAIT         0       /* wait for the front plate */
#define R1_MOVE         1       /* move out to its slot */

/* routine_no[1], selecting */
#define R1_IDLE         0       /* wait for the selection to move */
#define R1_TURN         1       /* turn with the other plates */
#define R1_REARRANGE    2       /* rearrange for the new play type */

/* routine_no[1], plate not chosen */
#define R1_DELAY        0       /* count the delay down */
#define R1_BEHIND       1       /* move behind the chosen one, hide */

/* routine_no[1], chosen plate */
#define R1_FLASH        1       /* play the chosen pattern */
#define R1_HOLD         2       /* wait for the others to go */
#define R1_FINISH       3       /* move to the finish spot */

/* routine_no[2], moving the plates */
#define R2_DELAY        0       /* count the delay down */
#define R2_MOVE         1       /* move to the new slot */
#define R2_WAIT         2       /* wait for the other plates */
#define R2_END          3       /* back to waiting for a turn */

/* routine_no[5] */
#define R5_MOVE         0       /* move toward the target x */
#define R5_ARRIVED      1       /* arrived */
#define R5_TURN         2       /* move on after the turn */

/* routine_no[6] */
#define R6_ARC          0       /* arc out to the turning point */
#define R6_MOVE         1       /* move to the target y */
#define R6_ARRIVED      99      /* (default) arrived */

/* routine_no[7] */
#define R7_WAIT         0       /* wait for the depth change */
#define R7_COUNT        1       /* count down, then change depth */
#define R7_DONE         99      /* (default) depth set */



u8 OK_Appear79[2];  /* 02068C0C */
u8 Extra_Counter[2];  /* 02068C0E */


void effect_79_move(WORK_Other* ewk) {
    s16 arrived[2];
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_APPEAR:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 1) {
            OK_Appear79[ewk->master_id] = 1;
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 1;
        }
        break;
    case R0_START:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0] = R0_SELECT;
            Move_Super_Arts[ewk->master_id]--;
            Select_Arts[ewk->master_id]--;
            effect_80_init(ewk, ewk->master_id, ewk->master_player, ewk->wu.my_family - 1);
        }
        break;
    case R0_FAN_OUT:
        switch (ewk->wu.routine_no[1]) {
        case R1_WAIT:
            if (OK_Appear79[ewk->master_id]) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[5] = R5_MOVE;
                ewk->wu.routine_no[6] = R6_MOVE;
                ewk->wu.disp_flag = 1;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
            break;
        case R1_MOVE:
            arrived[0] = EFF79_Move_X(ewk);
            arrived[1] = EFF79_Move_Y(ewk);
            if (arrived[0] != 0 && arrived[1] != 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.routine_no[1] = R1_IDLE;
                ewk->wu.routine_no[5] = R5_MOVE;
                ewk->wu.routine_no[6] = R6_ARC;
                ewk->wu.dir_timer = 1;
            }
            break;
        }
        break;
    case R0_START_BACK:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            Move_Super_Arts[ewk->master_id]--;
            Select_Arts[ewk->master_id]--;
            effect_80_init(ewk, ewk->master_id, ewk->master_player, ewk->wu.my_family - 1);
        }
        break;
    case R0_SELECT:
        switch (ewk->wu.routine_no[1]) {
        case R1_IDLE:
            Plate_Disposal_No[ewk->master_id][ewk->master_player] = 0;
            if (Check_Play_Status_79(ewk)) {
                break;
            }
            switch (Moving_Plate[ewk->master_id]) {
            case 1:
                switch (ewk->wu.hit_quake) {
                case 0:
                    ewk->wu.dmcal_m = 1;
                    ewk->wu.dm_vital = 3;
                    Setup_Move_79(ewk, 2, 0x60000, -0x20000, 0);
                    break;
                case 1:
                    ewk->wu.dmcal_m = 2;
                    ewk->wu.dm_vital = 1;
                    Setup_Move_79(ewk, 2, 0x60000, -0x20000, 0);
                    break;
                default:
                    ewk->wu.dmcal_m = 0;
                    ewk->wu.dm_vital = 2;
                    Setup_Move_79(ewk, 2, 0x20000, -0x80000, 2);
                    break;
                }
                break;
            case 2:
                switch (ewk->wu.hit_quake) {
                case 0:
                    ewk->wu.dmcal_m = 2;
                    ewk->wu.dm_vital = 3;
                    Setup_Move_79(ewk, 2, 0x60000, -0x80000, 1);
                    break;
                case 1:
                    ewk->wu.dmcal_m = 0;
                    ewk->wu.dm_vital = 1;
                    Setup_Move_79(ewk, 1, -0x60000, 0x20000, 0);
                    break;
                default:
                    ewk->wu.dmcal_m = 1;
                    ewk->wu.dm_vital = 2;
                    Setup_Move_79(ewk, 1, -0x60000, 0x20000, 0);
                    break;
                }
                break;
            default:
                Select_End_Sub_79(ewk);
                break;
            }
            break;
        case R1_TURN:
            Move_79(ewk);
            break;
        case R1_REARRANGE:
            Move_Move_79(ewk);
            break;
        }
        break;
    case R0_LEAVE:
        switch (ewk->wu.routine_no[1]) {
        case R1_DELAY:
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[5] = R5_MOVE;
                ewk->wu.routine_no[6] = R6_MOVE;
                ewk->wu.vital_new = Plate_X[ewk->master_id][0];
                ewk->wu.direction = Plate_Y[ewk->master_id][0];
                ewk->wu.mvxy.a[1].sp = 0x20000;
                ewk->wu.mvxy.d[1].sp = 0x2000;
                if (ewk->wu.xyz[0].disp.pos < ewk->wu.vital_new) {
                    ewk->wu.mvxy.a[0].sp = 0x18000;
                    ewk->wu.mvxy.d[0].sp = 0x6000;
                } else {
                    ewk->wu.mvxy.a[0].sp = -0x18000;
                    ewk->wu.mvxy.d[0].sp = -0x6000;
                }
                Check_Speed_79(ewk);
            }
            break;
        case R1_BEHIND:
            arrived[0] = EFF79_Move_X(ewk);
            arrived[1] = EFF79_Move_Y(ewk);
            if (arrived[0] == 0 || arrived[1] == 0) {
                break;
            } else {
                ewk->wu.routine_no[0] = R0_END;
                ewk->wu.disp_flag = 0;
                Extra_Counter[ewk->master_id]--;
                return;
            }
        default:
            break;
        }
        break;
    case R0_CHOSEN:
        switch (ewk->wu.routine_no[1]) {
        case R1_DELAY:
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[1]++;
            }
            break;
        case R1_FLASH:
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 2) {
                ewk->wu.routine_no[1]++;
                Sel_Arts_Complete[ewk->master_id] |= 0x8000;
                if (ewk->wu.xyz[0].disp.pos ==
                    bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[1][ewk->master_id][0][SEL_POS_X]) {
                    ewk->wu.routine_no[0] = R0_DONE;
                }
            }
            break;
        case R1_HOLD:
            if (Extra_Counter[ewk->master_id] == 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.routine_no[5] = R5_MOVE;
                ewk->wu.routine_no[6] = R6_MOVE;
                ewk->wu.vital_new = Plate_Finish_Data_79[ewk->master_id][SEL_POS_X];
                ewk->wu.direction = Plate_Finish_Data_79[ewk->master_id][SEL_POS_Y];
                ewk->wu.mvxy.a[1].sp = -0x8000;
                ewk->wu.mvxy.d[1].sp = -0xE000;
                if (ewk->wu.xyz[0].disp.pos < ewk->wu.vital_new) {
                    ewk->wu.mvxy.a[0].sp = 0x10000;
                    ewk->wu.mvxy.d[0].sp = 0x30000;
                } else {
                    ewk->wu.mvxy.a[0].sp = -0x10000;
                    ewk->wu.mvxy.d[0].sp = -0x30000;
                }
            }
            break;
        case R1_FINISH:
            arrived[0] = EFF79_Move_X(ewk);
            arrived[1] = EFF79_Move_Y(ewk);
            if (arrived[0] != 0 && arrived[1] != 0) {
                ewk->wu.routine_no[0]++;
            }
            break;
        }
    case R0_DONE:
        break;
    case R0_STAY:
        if (Suicide[0]) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            return;
        }
        break;
    case R0_END:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        return;
    default:
        ewk->wu.disp_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    PP_Priority[ewk->master_id][ewk->master_player] = ewk->wu.dmcal_m;
    sort_push_request4(&ewk->wu);
}



s32 Check_Play_Status_79(WORK_Other* ewk) {
    if (ewk->wu.dir_old == 0 && Play_Type == PLAY_VS_PLAYER) {
        ewk->wu.routine_no[1] = R1_REARRANGE;
        ewk->wu.routine_no[2] = R2_DELAY;
        ewk->wu.routine_no[5] = R5_MOVE;
        ewk->wu.routine_no[6] = R6_MOVE;
        ewk->wu.routine_no[7] = R7_WAIT;
        Plate_Disposal_No[ewk->master_id][ewk->master_player] = 1;
        ewk->wu.dir_timer = 1;
        ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                            Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->wu.dmcal_m][SEL_POS_X];
        ewk->wu.direction = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                            Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->wu.dmcal_m][SEL_POS_Y];
        OK_Moving_SA_Plate[ewk->master_id] = 3;
        ewk->wu.mvxy.a[1].sp = -0x8000;
        ewk->wu.mvxy.d[1].sp = -0xE000;
        if (ewk->wu.xyz[0].disp.pos < ewk->wu.vital_new) {
            ewk->wu.mvxy.a[0].sp = 0x10000;
            ewk->wu.mvxy.d[0].sp = 0x30000;
            Moving_Plate[ewk->master_id] = 8;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x10000;
            ewk->wu.mvxy.d[0].sp = -0x30000;
            Moving_Plate[ewk->master_id] = 4;
        }
        return ewk->wu.dir_old = 99;
    }
    return 0;
}


void Move_Move_79(WORK_Other* ewk) {
    s16 arrived[2];
    switch (ewk->wu.routine_no[2]) {
    case R2_DELAY:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case R2_MOVE:
        arrived[0] = EFF79_Move_X(ewk);
        arrived[1] = EFF79_Move_Y(ewk);
        if (arrived[0] != 0 && arrived[1] != 0) {
            ewk->wu.routine_no[2]++;
            OK_Moving_SA_Plate[ewk->master_id]--;
        }
        break;
    case R2_WAIT:
        if (OK_Moving_SA_Plate[ewk->master_id] == 0) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case R2_END:
        ewk->wu.routine_no[1] = R1_IDLE;
        ewk->wu.routine_no[2] = R2_DELAY;
        Moving_Plate[ewk->master_id] = 0;
        break;
    }
    if (ewk->wu.hit_quake == 0) {
        Plate_X[ewk->master_id][0] = ewk->wu.xyz[0].disp.pos;
        Plate_Y[ewk->master_id][0] = ewk->wu.xyz[1].disp.pos;
    }
}



void Setup_Move_79(ewk, _p1, X_Value, Y_Value, Option)
WORK_Other* ewk;
s32 _p1;
s32 X_Value;
s32 Y_Value;
s16 Option;
{
    ewk->wu.routine_no[1] = R1_TURN;
    ewk->wu.routine_no[2] = R2_DELAY;
    ewk->wu.routine_no[5] = R5_MOVE;
    ewk->wu.routine_no[6] = R6_MOVE;
    ewk->wu.routine_no[7] = R7_WAIT;
    ewk->wu.dir_timer = 1;
    ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                        Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->wu.dmcal_m][SEL_POS_X];
    ewk->wu.direction = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                        Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->wu.dmcal_m][SEL_POS_Y];
    ewk->wu.mvxy.a[1].sp = Y_Value;
    ewk->wu.mvxy.d[1].sp = 0;
    Plate_Disposal_No[ewk->master_id][ewk->master_player] = 1;
    OK_Priority[ewk->master_id] = 0;
    ewk->wu.mvxy.a[0].sp = X_Value;
    if (!Option) {
        return;
    }
    ewk->wu.routine_no[6] = R6_ARC;
    if (0 < ewk->wu.mvxy.a[1].sp) {
        ewk->wu.vital_old = ewk->wu.xyz[1].disp.pos + 48;
    } else if (ewk->wu.dmcal_m == 0) {
        ewk->wu.vital_old = ewk->wu.xyz[1].disp.pos - 40;
    } else {
        ewk->wu.vital_old = ewk->wu.xyz[1].disp.pos - 48;
    }
}



void Move_79(WORK_Other* ewk) {
    s16 arrived[2];
    Check_Priority(ewk);
    switch (ewk->wu.routine_no[2]) {
    case R2_DELAY:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case R2_MOVE:
        arrived[0] = EFF79_Move_X(ewk);
        arrived[1] = EFF79_Move_Y(ewk);
        if (arrived[0] != 0 && arrived[1] != 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.hit_quake = ewk->wu.dmcal_m;
            Moving_Plate_Counter[ewk->master_id]--;
            ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.hit_quake] + 35;
        }
        break;
    case R2_WAIT:
        if (Moving_Plate_Counter[ewk->master_id] == 0) {
            ewk->wu.routine_no[2]++;
        }
        break;
    case R2_END:
        ewk->wu.routine_no[1] = R1_IDLE;
        ewk->wu.routine_no[2] = R2_DELAY;
        Moving_Plate[ewk->master_id] = 0;
        break;
    }
}



void Check_Priority(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[7]) {
    case R7_WAIT:
        if (OK_Priority[ewk->master_id] == 0) {
            return;
        }
        ewk->wu.routine_no[7]++;
    case R7_COUNT:
        if (--ewk->wu.dm_vital == 0) {
            ewk->wu.routine_no[7]++;
            ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 35;
        }
        break;
    }
}



s32 EFF79_Move_X(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[5]) {
    case R5_MOVE:
        if (Move_X_Sub(ewk, ewk->wu.vital_new, 1)) {
            ewk->wu.routine_no[5]++;
            return 1;
        }
        break;
    case R5_ARRIVED:
        return 1;
    case R5_TURN:
        if (Move_X_Sub(ewk, ewk->wu.vital_new, 1)) {
            ewk->wu.routine_no[5]++;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}



s32 EFF79_Move_Y(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[6]) {
    case R6_ARC:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
        if (0 > ewk->wu.mvxy.a[1].sp) {
            if (ewk->wu.vital_old >= ewk->wu.xyz[1].disp.pos) {
                OK_Priority[ewk->master_id] = 1;
                ewk->wu.routine_no[5] = R5_TURN;
                ewk->wu.routine_no[6]++;
                ewk->wu.routine_no[7] = R7_DONE;
                ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
                ewk->wu.mvxy.d[1].sp = -ewk->wu.mvxy.d[1].sp;
                if (ewk->wu.dmcal_m == 0) {
                    ewk->wu.mvxy.a[0].sp = -0x60000;
                    ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
                }
                ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 35;
                Setup_Command_Name(ewk);
            }
        } else if (ewk->wu.vital_old <= ewk->wu.xyz[1].disp.pos) {
            OK_Priority[ewk->master_id] = 1;
            ewk->wu.routine_no[5] = R5_TURN;
            ewk->wu.routine_no[6]++;
            ewk->wu.routine_no[7] = R7_DONE;
            ewk->wu.mvxy.a[1].sp = -ewk->wu.mvxy.a[1].sp;
            ewk->wu.mvxy.d[1].sp = -ewk->wu.mvxy.d[1].sp;
            if (ewk->wu.dmcal_m == 0) {
                ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
            }
            ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->wu.dmcal_m] + 35;
            Setup_Command_Name(ewk);
        }
        break;
    case R6_MOVE:
        if (!Move_Y_Sub(ewk, ewk->wu.direction, 1)) {
            break;
        }
        ewk->wu.routine_no[6] = R6_ARRIVED;
        return 1;
    default:
        return 1;
    }
    return 0;
}



void Setup_Command_Name(WORK_Other* ewk) {
    if (Moving_Plate[ewk->master_id] == 2) {
        (&Disp_Command_Name[ewk->master_id][0])[ewk->master_player] = 0;
        switch (ewk->master_player) {
        case 0:
            Disp_Command_Name[ewk->master_id][1] = 1;
            Disp_Command_Name[ewk->master_id][2] = 0;
            break;
        case 1:
            Disp_Command_Name[ewk->master_id][2] = 1;
            Disp_Command_Name[ewk->master_id][0] = 0;
            break;
        default:
            Disp_Command_Name[ewk->master_id][0] = 1;
            Disp_Command_Name[ewk->master_id][1] = 0;
            break;
        }
    } else {
        Disp_Command_Name[ewk->master_id][0] = 0;
        Disp_Command_Name[ewk->master_id][1] = 0;
        Disp_Command_Name[ewk->master_id][2] = 0;
        (&Disp_Command_Name[ewk->master_id][0])[ewk->master_player] = 1;
    }
}


/* provisional name */
void Setup_Command_Name_dummy(void) {}



s32 Select_End_Sub_79(WORK_Other* ewk) {
    if (Sel_Arts_Complete[ewk->master_id] == 0) {
        return 0;
    }
    if (ewk->wu.hit_quake == 0) {
        ewk->wu.routine_no[0] = R0_CHOSEN;
        ewk->wu.routine_no[1] = R1_DELAY;
        ewk->wu.dir_timer = 5;
        Extra_Counter[ewk->master_id] = 2;
        Plate_X[ewk->master_id][0] = ewk->wu.xyz[0].disp.pos;
        Plate_Y[ewk->master_id][0] = ewk->wu.xyz[1].disp.pos;
    } else if (Extra_Counter[ewk->master_id]) {
        ewk->wu.routine_no[0] = R0_LEAVE;
        ewk->wu.routine_no[1] = R1_DELAY;
        ewk->wu.dir_timer = 1;
    } else {
        return 0;
    }
    return 1;
}



s32 effect_79_init(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->master_player = plate_id;
    ewk->master_priority = pos_id;
    ewk->wu.hit_quake = pos_id;
    ewk->wu.dmcal_m = pos_id;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 79;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.dir_timer = time;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->master_id = pl_id;
    ewk->wu.char_index = 14;
    ewk->wu.dir_old = Play_Type;
    if (pos_id == 0) {
        ewk->wu.dir_step = 0;
    } else {
        ewk->wu.dir_step = 30;
    }
    Setup_Pos_79(ewk);
    if (pos_id == 0) {
        (&Disp_Command_Name[ewk->master_id][0])[plate_id] = 1;
    } else {
        (&Disp_Command_Name[ewk->master_id][0])[plate_id] = 0;
    }
    Plate_X[ewk->master_id][0] =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[Play_Type][ewk->master_id][0][SEL_POS_X];
    Plate_Y[ewk->master_id][0] =
        bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[Play_Type][ewk->master_id][0][SEL_POS_Y];
    return 0;
}



void Setup_Pos_79(WORK_Other* ewk) {
    if (ewk->master_priority) {
        ewk->wu.routine_no[0] = R0_FAN_OUT;
        ewk->wu.xyz[0].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Plate_Pos_Data_79[Play_Type][ewk->master_id][0][SEL_POS_X];
        ewk->wu.xyz[1].disp.pos =
            bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Plate_Pos_Data_79[Play_Type][ewk->master_id][0][SEL_POS_Y];
        ewk->wu.vital_new = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                            Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->master_priority][SEL_POS_X];
        ewk->wu.direction = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                            Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->master_priority][SEL_POS_Y];
        ewk->wu.mvxy.a[1].sp = -0x20000;
        ewk->wu.mvxy.d[1].sp = -0x2000;
        if (ewk->wu.xyz[0].disp.pos < ewk->wu.vital_new) {
            ewk->wu.mvxy.a[0].sp = 0x18000;
            ewk->wu.mvxy.d[0].sp = 0x6000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x18000;
            ewk->wu.mvxy.d[0].sp = -0x6000;
        }
        Check_Speed_79(ewk);
    } else {
        ewk->wu.routine_no[0] = R0_WAIT;
        OK_Appear79[ewk->master_id] = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos +
                                  Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->master_priority][SEL_POS_X];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos +
                                  Plate_Pos_Data_79[Play_Type][ewk->master_id][ewk->master_priority][SEL_POS_Y];
    }
    ewk->wu.xyz[2].disp.pos = Pos_Z_Data_79[ewk->master_priority] + 35;
}



void Check_Speed_79(WORK_Other* ewk) {
    if (Play_Type == PLAY_VS_PLAYER) {
        ewk->wu.mvxy.a[0].sp /= 3;
        ewk->wu.mvxy.d[0].sp /= 3;
        ewk->wu.mvxy.a[1].sp /= 3;
        ewk->wu.mvxy.d[1].sp /= 3;
    }
}



s32 Move_X_Sub(WORK_Other* ewk, s16 Target_X, s16 cut) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
    if (Check_Depth_to_Before()) {
        return 0;
    }
    if (0 > ewk->wu.mvxy.a[0].sp) {
        if (Target_X >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = Target_X;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            return 1;
        }
    } else if (Target_X <= ewk->wu.xyz[0].disp.pos) {
        ewk->wu.xyz[0].disp.pos = Target_X;
        ewk->wu.mvxy.a[0].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        return 1;
    }
    return 0;
}



s32 Check_Depth_to_Before(WORK_Other* ewk) {
    if (0 <= ewk->wu.mvxy.a[1].sp) {
        return 0;
    }
    if (ewk->wu.hit_quake == 2 && ewk->wu.dmcal_m == 0) {
        return 1;
    }
    return 0;
}



s32 Move_Y_Sub(WORK_Other* ewk, s16 Target_Y, u16 cut) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp * cut;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
    if (0 > ewk->wu.mvxy.a[1].sp) {
        if (Target_Y >= ewk->wu.xyz[1].disp.pos) {
            ewk->wu.xyz[1].disp.pos = Target_Y;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = 0;
            return 1;
        }
    } else if (Target_Y <= ewk->wu.xyz[1].disp.pos) {
        ewk->wu.xyz[1].disp.pos = Target_Y;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = 0;
        return 1;
    }
    return 0;
}
