/*
 * SCRN_CTRL.C  Screen mode, window and zoom registers
 *
 * set_screen_mode and screen_flip_offsets_set choose normal or wide screen; screen_window_regs_update
 * and zoom_regs_update write the window and zoom registers in vblank; Zoomf_Init_X/Y, Frame_Up/Down
 * and Frame_Adgjust handle screen zoom.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Ck_Pass.h"
#include "Com_Sub.h"
#include "ACTIVE00.h"
#include "active01.h"
#include "active02.h"
#include "active03.h"
#include "active04.h"
#include "active05.h"
#include "active06.h"
#include "active07.h"
#include "active08.h"
#include "active09.h"
#include "active10.h"
#include "active11.h"
#include "active12.h"
#include "active13.h"
#include "active14.h"
#include "active15.h"
#include "active16.h"
#include "active17.h"
#include "active18.h"
#include "active19.h"
#include "FOLLOW02.h"
#include "fifo.h"
#include "sys_test.h"
#include "textsound.h"
#include "pass00.h"
#include "PASS01.h"
#include "PASS02.h"
#include "PASS03.h"
#include "PASS04.h"
#include "PASS05.h"
#include "PASS06.h"
#include "PASS07.h"
#include "PASS08.h"
#include "PASS09.h"
#include "pass10.h"
#include "PASS11.h"
#include "PASS12.h"
#include "pass13.h"
#include "pass14.h"
#include "pass15.h"
#include "pass16.h"
#include "pass17.h"
#include "pass18.h"
#include "pass19.h"
#include "Passive20.h"
#include "SHELL00.h"
#include "SHELL01.h"
#include "SHELL03.h"
#include "SHELL04.h"
#include "SHELL05.h"
#include "SHELL07.h"
#include "SHELL11.h"
#include "SHELL12.h"
#include "SHELL13.h"
#include "SHELL14.h"
#include "Entry.h"
#include "CMD_MAIN.h"
#include "sys_config.h"
#include "PLS02.h"
#include "SE.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "Manage.h"
#include "bg0001.h"
#include "Com_Pl.h"
#include "cps3.h"
#include "fighter.h"
#include "RANKING.h"


/* provisional name */
void screen_flip_offsets_set(void) {
    const s16* p;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        p = screen_flip_ofs_tbl[screen_mode];
        flip_obj_ofs_x = p[0];
        flip_obj_ofs_y = p[1];
        flip_crt_ofs_x = p[2];
        flip_crt_ofs_y = p[3];
        flip_scr_ofs_x = p[4];
        flip_scr_ofs_y = p[5];
        flip_zoom_ofs_x = p[6];
        flip_zoom_ofs_y = p[7];
    } else {
        flip_obj_ofs_x = 0;
        flip_obj_ofs_y = 0;
        flip_crt_ofs_x = 0;
        flip_crt_ofs_y = 0;
        flip_scr_ofs_x = 0;
        flip_scr_ofs_y = 0;
        flip_zoom_ofs_x = 0;
        flip_zoom_ofs_y = 0;
    }
}



/* provisional name */
void set_screen_mode(mode)
s32 mode;
{
    const s16* row;
    window_req_flag = 1;
    screen_mode = mode;
    screen_base_x = screen_origin_tbl[mode][0];
    screen_base_y = screen_origin_tbl[mode][1];
    if (screen_mode == 7 && Monitor_Flip) {
        screen_window[0][0] = screen_window_flip_tbl[0];
        screen_window[0][1] = screen_window_flip_tbl[1];
        screen_window[0][2] = screen_window_flip_tbl[2];
        screen_window[0][3] = screen_window_flip_tbl[3];
        screen_window[1][0] = screen_window_flip_tbl[4];
        screen_window[1][1] = screen_window_flip_tbl[5];
        screen_window[1][2] = screen_window_flip_tbl[6];
        screen_window[1][3] = screen_window_flip_tbl[7];
        screen_disp_ctrl = screen_window_flip_tbl[8];
    } else {
        row = (const s16*)((const u8*)screen_window_tbl + (u8)(mode * sizeof(screen_window_tbl[0])));
        screen_window[0][0] = row[0];
        screen_window[0][1] = row[1];
        screen_window[0][2] = row[2];
        screen_window[0][3] = row[3];
        screen_window[1][0] = row[4];
        screen_window[1][1] = row[5];
        screen_window[1][2] = row[6];
        screen_window[1][3] = row[7];
        screen_disp_ctrl = row[8];
    }
}



/* provisional name */
void screen_window_regs_update(void) {
    s16* win;
    s16* win1;
    u16 ctrl;
    u16 t;
    if (Monitor_Flip != Monitor_Flip_Old) {
        Monitor_Flip_Old = Monitor_Flip;
        screen_flip_offsets_set();
    } else {
        if (window_req_flag == 0) {
            return;
        }
        window_req_flag = 0;
    }
    win = screen_window[0];
    *(u16*)(VIDEO_REG + 0x60) = win[0];
    *(u16*)(VIDEO_REG + 0x62) = win[1];
    *(u16*)(VIDEO_REG + 0x64) = win[2];
    *(u16*)(VIDEO_REG + 0x66) = win[3];
    win1 = win + 4;
    *(u16*)(VIDEO_REG + 0x70) = win1[0];
    *(u16*)(VIDEO_REG + 0x72) = win1[1];
    *(u16*)(VIDEO_REG + 0x74) = win1[2];
    *(u16*)(VIDEO_REG + 0x76) = win1[3];
    ctrl = screen_disp_ctrl;
    if (Monitor_Flip) {
        ctrl |= 24;
    }
    *(u16*)(VIDEO_REG + 0x80) = ctrl;
    win = screen_window[0];
    *(u16*)SS_REG = win[0];
    *(u16*)(SS_REG + 0x2) = screen_disp_reg_tbl[screen_mode][0];
    *(u16*)(SS_REG + 0x4) = screen_disp_reg_tbl[screen_mode][1];
    *(u16*)(SS_REG + 0x6) = screen_disp_reg_tbl[screen_mode][2];
    *(u16*)(SS_REG + 0x8) = screen_disp_reg_tbl[screen_mode][3];
    win1 = win + 4;
    t = win[3];
    *(u16*)(SS_REG + 0xA) = t;
    *(u16*)(SS_REG + 0xC) = t >> 8;
    *(u16*)(SS_REG + 0x12) = win1[0];
    t = win1[1];
    *(u16*)(SS_REG + 0x14) = t;
    *(u16*)(SS_REG + 0x16) = t >> 8;
    t = win1[2] + 2;
    *(u16*)(SS_REG + 0x18) = t;
    *(u16*)(SS_REG + 0x1A) = t >> 8;
    t = win1[3];
    *(u16*)(SS_REG + 0x1C) = t;
    *(u16*)(SS_REG + 0x1E) = t >> 8;
    *(u16*)(SS_REG + 0x26) = screen_disp_ctrl & 7;
    *(u16*)(SS_REG + 0x28) = Monitor_Flip ? 3 : 0;
}



/* provisional name */
void Zoomf_Init(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 1023;
    zoom_frame[0].zoom = 64;
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 1023;
    zoom_frame[1].zoom = 64;
    zoom_adj_x = 0;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_X(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 0x3FF;
    zoom_frame[0].zoom = 64;
    zoom_adj_x = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_Y(void) {
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 0x3FF;
    zoom_frame[1].zoom = 64;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* Zooms the frame in; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Up(u16 x, u16 y, s16 add_x, s16 add_y) {
    s32 adj;
    zoom_frame[0].zoom -= add_x;
    zoom_frame[1].zoom -= add_y;
    adj = Frame_Adgjust(x, y);
    zoom_req_flag = 1;
    return adj;
}



/* Zooms the frame out; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Down(u16 x, u16 y, s16 add_x, s16 add_y) {
    s32 adj;
    zoom_frame[0].zoom += add_x;
    zoom_frame[1].zoom += add_y;
    adj = Frame_Adgjust(x, y);
    zoom_req_flag = 1;
    return adj;
}



/* Recomputes the zoom frame offsets; returns the vertical offset as first computed (before -32 is nudged to -31). */
s32 Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;
    s16 adj;
    if (Monitor_Flip) {
        pos_y = 0xD0 - pos_y;
        if (screen_mode != 7) {
            flip_zoom_ofs_x = 0x80;
        }
    }
    if (zoom_frame[0].zoom >= 0x40) {
        buff = zoom_frame[0].zoom;
        buff = buff - 0x40;
        buff *= pos_x;
        buff = buff >> 6;
        buff = buff & 0x1FF;
        zoom_adj_x = -buff;
        if (Monitor_Flip && screen_mode != 7) {
            flip_zoom_ofs_x = 0x80 - buff * 2;
        }
    } else {
        buff = 0x40;
        buff = buff - zoom_frame[0].zoom;
        buff *= pos_x;
        buff = buff >> 6;
        buff = buff & 0x1FF;
        if (Monitor_Flip) {
            zoom_adj_x = -buff;
        } else {
            zoom_adj_x = buff;
        }
    }
    if (zoom_frame[1].zoom >= 0x40) {
        buff = zoom_frame[1].zoom;
        buff = buff - 0x40;
        buff *= pos_y + 0x21;
        buff = buff >> 6;
        buff = buff & 0x1FF;
        if (!Monitor_Flip) {
            buff = -buff;
        }
        zoom_adj_y = buff;
        if ((adj = zoom_adj_y) == -0x20) {
            zoom_adj_y = zoom_adj_y + 1;
        }
    } else {
        buff = 0x40;
        buff = buff - zoom_frame[1].zoom;
        buff *= pos_y + 0x21;
        buff = buff >> 6;
        buff = buff & 0x1FF;
        if (Monitor_Flip) {
            buff = -buff;
        }
        zoom_adj_y = buff;
        if ((adj = zoom_adj_y) == -0x20) {
            zoom_adj_y = zoom_adj_y + 1;
        }
    }
    return adj;
}



/* provisional name */
void zoom_regs_update(void) {
    SCROLL_WINDOW* win;
    if (zoom_req_flag != 0) {
        zoom_req_flag = 0;
        win = zoom_frame;
        *(s16*)(VIDEO_REG + 0x68) = (win->pos + flip_zoom_ofs_x) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x6A) = win->size;
        *(s16*)(VIDEO_REG + 0x6C) = win->mask;
        *(s16*)(VIDEO_REG + 0x6E) = win->zoom;
        win++;
        *(s16*)(VIDEO_REG + 0x78) = (win->pos + flip_zoom_ofs_y) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x7A) = win->size;
        *(s16*)(VIDEO_REG + 0x7C) = win->mask;
        *(s16*)(VIDEO_REG + 0x7E) = win->zoom;
    }
}
