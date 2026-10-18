/*
 * OPENING.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 op_change_sound_tbl[18] = {
    101, 102, 103, 104, 105, 106, 107, 108,
    109, 110, 111, 112, 113, 114, 115, 116,
    117, 16,
};

#pragma section

OP_W op_w;  /* 020281C4 */
s16 op_end_flag;  /* 020281E0 */
s16 op_obj_disp;  /* 020281E2 */
u8 op_obj_disp_tail[2];  /* after op_obj_disp; nothing refers to it by name or address */
s8 op_scrn_end;  /* 020281E6 */
s16 op_sound_status;  /* 020281E8 */
OPBW * opw_ptr;  /* 020281EC */
u8 opw_ptr_tail[2];  /* after opw_ptr; nothing refers to it by name or address */
s16 op_plmove_timer;  /* 020281F2 */
s16 op_demo_index;  /* 020281F4 */
MVXY op_bg_mvxy[3];  /* 020281F8 */
