/*
 * BG_DATA.C  stage background index table
 *
 * bg_index_tbl gives the background number (bg_index) for each stage and area; every other
 * stage background table is indexed by it. Read by BG000.C (bg_initialize). bg_index_tbl_tail
 * follows bg_index_tbl and is not referred to.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 bg_index_tbl[23][3] = {
    { 0, 0, 0 }, { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }, { 5, 5, 5 }, { 6, 6, 6 }, { 7, 7, 7 },
    { 8, 8, 8 }, { 9, 9, 9 }, { 10, 10, 10 }, { 11, 11, 11 }, { 12, 12, 12 }, { 13, 13, 13 }, { 14, 14, 14 }, { 15, 15, 15 },
    { 16, 16, 16 }, { 17, 17, 17 }, { 4, 4, 4 }, { 19, 19, 19 }, { 20, 20, 20 }, { 21, 21, 21 }, { 22, 22, 22 },
};

/* Stored after bg_index_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of bg_index_tbl. */
const s16 bg_index_tbl_tail[73] = {
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    256, 256, 312, 0, 0, 0,
    0,
};

#pragma section

BGW * bgw_ptr;  /* 02026FF4 */
SUZI_CALC suzi_calc_w[2];  /* 02026FF8 */
Ideal_W ideal_w;  /* 02027008 */
u16 suzi_line_buf[2048];  /* 02027010 */
MVXY bg_mvxy;  /* 02028010 */
s16 bg_stop;  /* 02028028 */
s8 bg_app_stop;  /* 0202802A */
s16 base_y_pos;  /* 0202802C */
u8 base_y_pos_tail[12];  /* after base_y_pos; nothing refers to it by name or address */
s16 bg_ofs_work[3];  /* 0202803A */
s16 bg_zoom_x_pos;  /* 02028040 */
s16 bg_sp_work;  /* 02028042 */
u8 bg_sp_work_tail[2];  /* after bg_sp_work; nothing refers to it by name or address */
s16 bg_land_flag;  /* 02028046 */
s8 demo_car_flag[2];  /* 02028048 */
s16 bg_etc_flag;  /* 0202804A */
s16 bg_stop2;  /* 0202804C */
s16 chase_x;  /* 0202804E */
s16 chase_y;  /* 02028050 */
s16 chase_time_x;  /* 02028052 */
s16 chase_time_y;  /* 02028054 */
s8 akebono_flag;  /* 02028056 */
s8 seraph_flag;  /* 02028057 */
s8 aku_flag;  /* 02028058 */
s8 bg_select_no;  /* 02028059 */
s8 sa_pa_flag;  /* 0202805A */
s8 bg_app;  /* 0202805B */
s8 bg_vbl_trans_flag;  /* 0202805C */
u8 bg_vbl_trans_flag_tail[3];  /* after bg_vbl_trans_flag; nothing refers to it by name or address */
s16 ls_cnt1;  /* 02028060 */
BG_ADRS eff_bg_adrs[3];  /* 02028064 */
u8 eff_bg_adrs_tail[56];  /* after eff_bg_adrs; nothing refers to it by name or address */
