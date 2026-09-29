/*
 * EFFB2_INIT.C  Effect B2 init: the round / fight call
 *
 * effect_B2_init is called by the game manager (Manage.c) at the start of each round. It loads
 * the round-call graphics, resets the BG3 scroll to the screen origin, sets the BG families
 * (ake_Family_Set) and decides from Battle_Round and Round_num whether this is the final round
 * (type 1) or a normal round (type 0). It then spawns effect B3, the display child that shows
 * the round number and FIGHT (EFFB4.C).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "EFFB4.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "EFFB2_INIT.h"



s32 effect_B2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x70;
    ewk->wu.work_id = 0x10;
    ewk->wu.my_family = 4;
    load_char_gfx(0xA7F8, 1);
    bg_w.bgw[3].xy[0].cal = bg_w.bgw[3].wxy[0].cal = 0x100000;
    bg_w.bgw[3].wxy[1].cal = 0;
    bg_w.bgw[3].xy[1].cal = 0;
    bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    ake_Family_Set();
    switch (Battle_Round[Play_Type]) {
    case 0:
        ewk->wu.type = 0;
        break;
    case 1:
        if (Round_num == 2) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    case 2:
        if (Round_num == 4) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    case 3:
        if (Round_num == 6) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }
        break;
    }
    effect_B3_init(ewk);
    return 0;
}
