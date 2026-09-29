/*
 * family.c  Scroll family position setters
 *
 * The scroll "family" helpers keep the fm_pos[] table of plane positions: Family_Init
 * zeroes all eight entries, Family_Set_R sets both the target and current position of a family
 * at once, and Family_Set_W sets only the target position (used by the BG, opening and ending code).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "fifo.h"
/* provisional name */
void Family_Init(void)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].set_x.cal = 0;
        fm_pos[i].set_y.cal = 0;
        fm_pos[i].cur_x.cal = 0;
        fm_pos[i].cur_y.cal = 0;
    }
}



void Family_Set_R(n, x, y)
s32 n;
s16 x;
s16 y;
{
    fm_pos[n].set_x.disp.pos = x;
    fm_pos[n].set_y.disp.pos = y;
    fm_pos[n].cur_x.disp.pos = x;
    fm_pos[n].cur_y.disp.pos = y;
}



void Family_Set_W(plane, x, y)
s32 plane;
s16 x;
s16 y;
{
    fm_pos[plane].set_x.disp.pos = x;
    fm_pos[plane].set_y.disp.pos = y;
}
