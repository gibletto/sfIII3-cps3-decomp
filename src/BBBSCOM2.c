/*
 * BBBSCOM2.C  Bonus stage: control for the other bonus game
 *
 * bbbs_com_execute2 drives the non-player side when Bonus_Game_Flag is not 22 (called from
 * PLMAIN2). It parks the work at x=468, creates effect C2 and the score display (effect 16),
 * makes the work invincible once battle is allowed, and when the C2 object reaches its final
 * state ends the stage and sets pcon_dp_flag.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFC2.h"
#include "EFF16.h"
#include "BBBSCOM2.h"



void bbbs_com_execute2(PLW* wk) {
    switch (Bonus_Stage_RNO[0]) {
    case 0:
        if (Bonus_Stage_RNO[1]) {
            if (!Allow_a_battle_f) {
                break;
            }
            Bonus_Stage_RNO[0] = 1;
            Bonus_Stage_RNO[1] = 0;
            wk->zettai_muteki_flag = 1;
            break;
        }
        wk->wu.xyz[0].disp.pos = 468;
        wk->wu.xyz[1].disp.pos = 0;
        effect_C2_init((WORK*)wk, 0);
        effect_16_init(wk);
        Bonus_Stage_RNO[1] = 1;
        break;
    case 1:
        if (((WORK*)wk->wu.my_effadrs)->routine_no[0] == 2 && ((WORK*)wk->wu.my_effadrs)->routine_no[1] == 9) {
            Bonus_Stage_RNO[0] = 2;
            Bonus_Stage_RNO[1] = 0;
            pcon_dp_flag = 1;
        }
        break;
    case 2:
        break;
    }
}
