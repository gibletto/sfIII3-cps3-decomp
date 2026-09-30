/*
 * BG0001.C  Game task jump
 *
 * bg0001 copies the main game jump table Main_Jmp_Data and calls the routine selected by the
 * current top-level game number G_No[0].
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "sys_config.h"
#include "bg0001.h"

#pragma noregsave(game_frame_task)
#pragma inline(bg0001)



/* Frame task started by mode_init_task: every frame run the current game routine
   (bg0001), then the colour transfer and the frame render pipeline, and sleep
   until the next frame. */
/* provisional name */
void game_frame_task(void) {
loop:
    bg0001();
    color_trans_dummy();
    sprite_bank_flip();
    task_sleep(1);
    goto loop;
}



void bg0001(void) {
    GAME_TASK_JMP Main_Jmp_Tbl;
    Main_Jmp_Tbl = Main_Jmp_Data;
    Main_Jmp_Tbl.jmp[(*(s16(*)[4])&G_No[0])[0]]();
}
