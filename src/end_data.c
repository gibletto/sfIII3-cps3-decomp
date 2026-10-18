/*
 * END_DATA.C  ending work
 *
 * The work RAM the ending sequences share: the ending state (end_w), fades, name and staff roll
 * control.
 */

#include "types.h"
#include "structs.h"


END_W end_w;  /* 02028240 */
s16 ls_rate1;  /* 0202824C */
s8 end_etc_flag;  /* 0202824E */
s8 ending_all_end;  /* 0202824F */
s8 end_fade_flag;  /* 02028250 */
s8 end_no_cut;  /* 02028251 */
s16 end_fade_timer;  /* 02028252 */
u8 end_fade_timer_tail[2];  /* after end_fade_timer; nothing refers to it by name or address */
s8 end_name_cut[2];  /* 02028256 */
s8 end_staff_flag;  /* 02028258 */
u8 end_cont_coin;  /* 02028259 */
u8 end_obj_sync;  /* 0202825A */
s16 staff_roll_timer;  /* 0202825C */
s32 staff_r_no;  /* 02028260 */

