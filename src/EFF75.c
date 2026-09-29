/*
 * EFF75.C  Effect 75: move routine
 *
 * effect_75_move runs the current order state of effect 75 from its jump table and draws
 * the object. The states and the init are in EFF75_ORDER.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFF75.h"



void effect_75_move(WORK_Other* ewk) {
    EFF75_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}
