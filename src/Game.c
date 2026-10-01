/*
 * GAME.C  Task sleep timer tick
 *
 * task_sleep_tick is called once per frame from the Game_Task scheduler loop. It counts down the sleep
 * timer of every waiting task control block (status 1) and marks the task ready to run (status 2)
 * when the timer reaches zero.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "sys_config.h"
#include "Game.h"

#pragma noregsave(Game_Task)



/* The task scheduler; never returns.  Each pass walks the eight task control
   blocks with interrupts masked and runs every task that is due, then lets
   interrupts in again before the next block.  A new vertical blank (vsync_flag)
   restarts the walk from the first block.  After a full pass: clear the sprite
   buffer if this is the first pass of the frame (unless the timers are ticked
   here), tick the sleep timers on the first two passes when the scheduler owns
   them (tick mode 3), note whether any task ran, count the pass and flip the
   frame. */
void Game_Task(void) {
    s32 i;
    TCB* task;
    s32 mode;

    _builtin_set_imask(1);
    do {
        i = 0;
        vsync_flag = 0;
        frame_pass_count = 0;
        task_ran_flag = 0;
        do {
            _builtin_set_imask(15);
            if (vsync_flag != 0) {
                break;
            }
            current_task = task = &task_tbl[i];
            mode = task_tick_mode;
            switch (task->status) {
            case 0:
            case 1:
            case 5:
                break;
            case 2:
                if (mode == 1) {
                    break;
                }
                if (mode == 2 && (task_tick_mask & system_timer)) {
                    break;
                }
            case 4:
                task->status = 3;
            default:
                task_ran_flag = 1;
                task_dispatch(task);
                break;
            }
            _builtin_set_imask(1);
            if (++i == 8) {
                i = 0;
                if (task_tick_mode != 3 && frame_pass_count == 0) {
                    tilemap_fill_column0(0, 32);
                }
                if (task_tick_mode == 3 && frame_pass_count < 2) {
                    task_sleep_tick();
                }
                if (task_ran_flag == 0) {
                    frame_ready = 0;
                } else {
                    frame_ready = 1;
                }
                frame_pass_count++;
                task_ran_flag = 0;
                poly_bank_flip();
            }
        } while (1);
    } while (1);
}



/* provisional name */
void task_sleep_tick(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (task_tbl[i].status == 1) {
            task_tbl[i].state--;
            if (task_tbl[i].state == 0) {
                task_tbl[i].status = 2;
            }
        }
    }
}
