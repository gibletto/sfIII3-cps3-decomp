/*
 * EFFA2.C  New challenger banner character transfer
 *
 * break_into_banner_trans is called from the effect A2 main routine (EFFA2_MAIN) while the new
 * challenger banner is shown. Kind 0 clears the banner characters and redraws the text layer;
 * any other kind copies the kind-th three-cell column of the banner graphics from sc_chr_data
 * into character RAM.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "EffA2.h"
#include "cps3.h"



/* provisional name */
void break_into_banner_trans(ewk, kind)
WORK_Other* ewk;
s16 kind;
{
    switch (kind) {
    case 0:
        sc_chr_clear(320, 192);
        sc_ram_to_vram_opc(16, 0, Text_Page_Y, 40);
        break;
    default:
        sc_trans_src = (u8*)&sc_chr_data[(kind - 1) * 3 * 16] + 0xA000;
        sc_trans_dst = (u16*)((SS_RAM + 0xD000) + (kind - 1) * 3 * 64);
        sc_chr_trans(3);
        break;
    }
}
