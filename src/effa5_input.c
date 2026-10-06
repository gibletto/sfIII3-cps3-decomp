/*
 * EFFA5_INPUT.C  Select-screen button checks
 *
 * effA5_shot_pressed and effA5_start_pressed report whether an attack button or Start is held on the
 * current player's switch word.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sc_trans.h"
#include "effa5_input.h"



/* provisional name */
s32 effA5_shot_pressed(void) {
    u16 sw;
    if (Player_id) {
        sw = p2sw_0;
    } else {
        sw = p1sw_0;
    }
    if (sw & 0x3F0) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 effA5_start_pressed(void) {
    u16 sw;
    if (Player_id) {
        sw = p2sw_0;
    } else {
        sw = p1sw_0;
    }
    if (sw & 0x1000) {
        return 1;
    }
    return 0;
}
