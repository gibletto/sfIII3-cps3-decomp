/*
 * SCRN_WORK.C  Screen and scroll control work RAM (scrn_ctrl)
 */

#include "types.h"
#include "structs.h"

SCREEN_WINDOW screen_window[2];  /* 0200DCA4 */
SCROLL_WINDOW zoom_frame[2];  /* 0200DCB4 */
volatile s16 screen_disp_ctrl;  /* 0200DCC4 */
s16 screen_base_x;  /* 0200DCC6 */
s16 screen_base_y;  /* 0200DCC8 */
s32 screen_mode;  /* 0200DCCC */
u8 zoom_req_flag;  /* 0200DCD0 */
u8 window_req_flag;  /* 0200DCD1 */
s16 zoom_adj_x;  /* 0200DCD2 */
s16 zoom_adj_y;  /* 0200DCD4 */
u16 flip_obj_ofs_x;  /* 0200DCD6 */
u16 flip_obj_ofs_y;  /* 0200DCD8 */
s16 flip_crt_ofs_x;  /* 0200DCDA */
s16 flip_crt_ofs_y;  /* 0200DCDC */
s16 flip_scr_ofs_x;  /* 0200DCDE */
s16 flip_scr_ofs_y;  /* 0200DCE0 */
s16 flip_zoom_ofs_x;  /* 0200DCE2 */
s16 flip_zoom_ofs_y;  /* 0200DCE4 */
static u8 scrn_spare[12];  /* nothing in the program refers to it */
