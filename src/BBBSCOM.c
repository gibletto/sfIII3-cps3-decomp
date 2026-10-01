/*
 * BBBSCOM.C  Bonus stage: ball-thrower control and difficulty selection
 *
 * bbbs_com_execute is the control routine for the computer side in the ball bonus game
 * (Bonus_Game_Flag 22, called from PLMAIN2 instead of the normal CPU). It steps through the
 * bbbs_table entries for the current type and level: waits, sets the throw action and jump
 * level, launches the balls through bbbs_ball_set, and ends when the table runs out.
 * It also creates the score display (effect 16) and the bonus-stage level objects.
 * bbbs_com_initialize clears Bonus_Stage_RNO.
 * makeup_bonus_game_level picks Bonus_Stage_Level: from the secret button combination held
 * by the player (katteni_bonus_nando / set_bonus_game_nando, levels 0-9) or otherwise from
 * the player's VS-CPU grade (set_bonus_game_difficulty, levels 0-4).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFB1_INIT.h"
#include "EFFH0.h"
#include "BBBSBALL.h"
#include "EFF16.h"
#include "EFFH9.h"
#include "BBBSCOM.h"



void bbbs_com_execute(PLW* wk) {
    switch (Bonus_Stage_RNO[0]) {
    case 0:
        if (Allow_a_battle_f == 0) {
            break;
        }
        Bonus_Stage_Tix = 0;
        Bonus_Stage_RNO[0] = 1;
        if ((wk->wu.dir_timer = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
            Bonus_Stage_RNO[1] = 1;
        } else {
            Bonus_Stage_RNO[1] = 2;
        }
        wk->zettai_muteki_flag = 1;
        effect_B1_init(wk);
        effect_16_init(wk);
        effect_H9_init(wk);
        effect_H0_init(&wk->wu);
        break;
    case 1:
        switch (Bonus_Stage_RNO[1]) {
        case 0:
            if (wk->wu.routine_no[1] != 0) {
                break;
            }
            if (wk->wu.routine_no[2] != 1 && (wk->wu.routine_no[2] < 36 || wk->wu.routine_no[2] > 38)) {
                break;
            }
            Bonus_Stage_Tix++;
            if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer == -1) {
                Bonus_Stage_RNO[0] = 2;
                Bonus_Stage_RNO[1] = 0;
                break;
            }
            if ((wk->wu.dir_timer = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].timer)) {
                if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                    Bonus_Stage_RNO[1] = 1;
                    break;
                } else {
                    Bonus_Stage_RNO[1] = 5;
                    break;
                }
            } else {
                if (bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu) {
                    Bonus_Stage_RNO[1] = 2;
                    break;
                } else {
                    Bonus_Stage_RNO[1] = 6;
                    break;
                }
            }
            break;
        case 1:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 2;
            }
            break;
        case 2:
            Bonus_Stage_RNO[1] = 3;
            wk->wu.routine_no[1] = 4;
            wk->wu.routine_no[2] = 31;
            wk->wu.routine_no[3] = 0;
            wk->wu.char_index = 71;
            wk->wu.cmwk[5] = bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].kosuu;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = bbbs_jump_level[bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][0];
            wk->wu.mvxy.d[1].sp = bbbs_jump_level[bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix].jmplv][1];
            break;
        case 3:
            if (wk->wu.cg_type == 20) {
                wk->wu.cg_type = 0;
                bbbs_ball_set(wk, &bbbs_table[bbbs_type][Bonus_Stage_Level][Bonus_Stage_Tix]);
                Bonus_Stage_RNO[1] = 4;
            }
            break;
        case 4:
            if (wk->wu.routine_no[1] == 4 && wk->wu.routine_no[2] == 31 && wk->wu.routine_no[3] == 3) {
                Bonus_Stage_RNO[1] = 0;
            }
            break;
        case 5:
            if (--wk->wu.dir_timer <= 0) {
                Bonus_Stage_RNO[1] = 6;
            }
            break;
        case 6:
            Bonus_Stage_RNO[0] = 2;
            Bonus_Stage_RNO[1] = 0;
            break;
        }
    case 2:
        break;
    }
}



void bbbs_com_initialize(void) {
    Bonus_Stage_RNO[0] = Bonus_Stage_RNO[1] = 0;
    Bonus_Stage_RNO[2] = Bonus_Stage_RNO[3] = 0;
}



void makeup_bonus_game_level(s16 ix) {
    s16 emid = (ix + 1) & 1;
    u16 swdat;
    if (emid) {
        swdat = p2sw_0;
    } else {
        swdat = p1sw_0;
    }
    bbbs_type = 1;
    if (katteni_bonus_nando(swdat)) {
        Bonus_Stage_Level = set_bonus_game_nando(swdat);
        if (Bonus_Stage_Level > 4) {
            bbbs_type = 0;
            Bonus_Stage_Level -= 5;
        }
    } else {
        Bonus_Stage_Level = set_bonus_game_difficulty(emid);
    }
}



s32 set_bonus_game_difficulty(s16 emid) {
    s16 s;

    s = judge_final[emid][0].vs_cpu_grade[11];
    if (s < 9) {
        return 0;
    }
    if (s < 0xf) {
        return 1;
    }
    if (s < 0x12) {
        return 2;
    }
    if (s < 0x15) {
        return 3;
    }
    return 4;
}



s32 set_bonus_game_nando(u16 swdat) {
    if (swdat == 0x152) {
        return 9;
    }
    if (swdat == 0x382) {
        return 8;
    }
    if (swdat == 0x202) {
        return 7;
    }
    if (swdat == 0x102) {
        return 6;
    }
    if (swdat == 0x82) {
        return 5;
    }
    if (swdat == 0x2A1) {
        return 4;
    }
    if (swdat == 0x71) {
        return 3;
    }
    if (swdat == 0x41) {
        return 2;
    }
    if (swdat == 0x21) {
        return 1;
    }
    return 0;
}



s32 katteni_bonus_nando(u16 swdat) {
    if (swdat & 1) {
        if (swdat & 0x70) {
            return 1;
        }
    }
    if (swdat & 2) {
        if (swdat & 0x380) {
            return 1;
        }
    }
    return 0;
}
