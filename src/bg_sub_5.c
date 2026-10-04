/*
 * BG_SUB_5.C  Stage background subroutines: scrolling, zoom, family set, cell writers (part 5)
 *
 * Bg_Family_Set and its variants load scroll and family registers; bg_pos_hosei_* add the screen
 * offset and quake.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg_sub_2.h"
#include "bg_sub_5.h"

#pragma inline(remake_x_mvstep)



void suzi_offset_set(WORK* wk) {
    if (wk->sync_suzi == 1) {
        suzi_offset_set_sub(wk);
    }
}

u32 suzi_offset_set_sub(WORK* wk)
{
    BGW *bgw;
    s16 work;

    work = 0x300 - (wk->xyz[1].disp.pos & 0x300);
    work += 0x100 - (wk->xyz[1].disp.pos & 0xFF);
    bgw = (BGW *)((u8 *)bg_w.bgw + (s16)((wk->my_family - 1) * sizeof(BGW)));
    wk->suzi_offset = bgw->suzi_adrs + (s16)(work * 2);
    return 0;
}



void suzi_sync_pos_set(WORK_Other* ewk) {
    s16 sub;
    if (ewk->wu.sync_suzi) {
        if (ewk->wu.sync_suzi == 2) {
            suzi_offset_set_sub((WORK*)ewk);
        }
        sub = *ewk->wu.suzi_offset;
        sub -= 0x200;
    } else {
        sub = 0;
    }
    ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos - sub) & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
}



void Bg_Family_Set(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < bg_w.scno; i++) {
        x = bg_w.bgw[i].position_x;
        y = bg_w.bgw[i].position_y;
        Scrn_Move_Set(i, x, y);
        x = -x & 0x3FF;
        y = (768 - (y & 0x3FF)) & 0x3FF;
        Family_Set_W(i + 1, x, y);
        continue;
    }
}
