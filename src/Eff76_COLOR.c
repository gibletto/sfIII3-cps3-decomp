/*
 * EFF76_COLOR.C  Winner palette helpers and the Akuma name check
 *
 * Setup_Color_76 (used by Eff76) and Setup_Color_L1 (used by the EFFL1 result plates) set
 * a work's colour code from the per-character palette table for the winner's character.
 * chkNameAkuma returns 1 for character 14 outside mode type 1, selecting the alternative name
 * graphic on the select and result screens.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Eff76_COLOR.h"
void Setup_Color_76(ewk)
s32 ewk;
{
    ((WORK *)ewk)->my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2040;
}

void Setup_Color_L1(ewk)
s32 ewk;
{
    ((WORK *)ewk)->my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x40;
}

s32 chkNameAkuma(char_id)
s16 char_id;
{
    if (Country != 1 && char_id == 14) {
        return 1;
    }
    return 0;
}
