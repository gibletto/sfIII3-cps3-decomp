/*
 * ENTRY.C  Task control, debug dumps and the player entry / credit task
 *
 * Task control: init_task_stacks gives each of the eight task control blocks its stack; create_task,
 * destroy_current_task, kill_tasks_by_func and kill_tasks_by_priority start and stop tasks (used by
 * Com_Pl and end_sub). Debug screens: dbg_memory_dump_rows and dbg_disasm_rows print memory rows,
 * and disasm_sh_opcode turns an SH-2 instruction word into its mnemonic from the opcode tables.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFA2_MAIN.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "n_input.h"
#include "SYS_sub.h"
#include "cmb_win.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "eeprom.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Grade.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "sc_trans.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "entry_2.h"
#include "Entry.h"



/* provisional name */
void init_task_stacks(void) {
    current_task = 0;
    task_sys_w3 = 0;
    task_sys_w1 = 0;
    task_sys_w2 = 0;
    for (task_free_count = 0; task_free_count < task_stack_num; task_free_count++) {
        task_tbl[task_free_count].stack_top = (u32*)&task_stack[task_free_count][1024];
    }
}



/* provisional name */
TCB* create_task(void (*entry)(), s32 unused, TCB* task, s16 priority, u32 arg) {
    if (task->status != 0) {
        return 0;
    }
    task_free_count--;
    task->parent = current_task;
    task->priority = priority;
    task->status = 4;
    task->state = 0;
    task->entry = entry;
    task->func = entry;
    task->sp = task->stack_top;
    task->sr = 0x10;
    task->creator = current_task;
    task->arg = arg;
    task->wait = 0;
    task->timer = 0;
    return task;
}



/* provisional name */
void destroy_current_task(void) {
    _builtin_set_imask(15);
    current_task->status = 0;
    task_free_count++;
    task_exit_to_system();
}



/* provisional name: stop another task (1 = it is the running task, 2 = not active) */
s32 kill_task(TCB* task) {
    if (task == current_task) {
        return 1;
    }
    if (task->status == 0) {
        return 2;
    }
    task->status = 0;
    task_free_count++;
    return 0;
}



/* provisional name: put a task to sleep until woken (2 = not active) */
s32 suspend_task(TCB* task) {
    if (task->status == 0) {
        return 2;
    }
    task->status = 5;
    return 0;
}



/* provisional name: hand a task a value from the running task, mode 1 also sets it waiting */
s32 post_task(TCB* task, u32 arg, s32 mode) {
    if (task == current_task) {
        return 1;
    }
    if (task->status == 0) {
        return 2;
    }
    if (mode == 1) {
        task->status = 2;
    }
    task->creator = current_task;
    task->wait = arg;
    return 0;
}



/* provisional name */
void kill_tasks_by_func(void (*func)()) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (task_tbl[i].status && task_tbl[i].func == func && &task_tbl[i] != current_task) {
            task_tbl[i].status = 0;
            task_free_count++;
        }
    }
}



/* provisional name */
void kill_tasks_by_priority(prio, mode)
s32 prio;
s32 mode;
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (&task_tbl[i] == current_task) {
            continue;
        }
        switch (mode) {
        case 0:
            if (task_tbl[i].priority > prio) {
                break;
            }
            if (task_tbl[i].status != 0) {
                task_tbl[i].status = 0;
                task_free_count++;
            }
            break;
        case 2:
            if (task_tbl[i].priority < prio) {
                break;
            }
            if (task_tbl[i].status != 0) {
                task_tbl[i].status = 0;
                task_free_count++;
            }
            break;
        default:
            if (task_tbl[i].priority == prio) {
                if (task_tbl[i].status != 0) {
                    task_tbl[i].status = 0;
                    task_free_count++;
                }
            }
            break;
        }
    }
}



/* provisional name */
void dbg_memory_dump_rows(u16* tbl) {
    s32 row;
    s32 col;
    s32 x;
    tilemap_print_string(1, 0, 0xFFFF, dbg_dump_title);
    for (row = 0; row < 8; row++) {
        tilemap_print_hex_block(1, row + 11, 14, (s32)tbl, 8, 0);
        for (col = 0, x = 10; col < 8; col++, x += 5) {
            tilemap_print_hex_block(x, row + 11, 14, *tbl, 4, 0);
            tbl++;
        }
        continue;
    }
}



/* provisional name */
void dbg_disasm_rows(u16* tbl) {
    u16 y;
    s16 i;
    s8 buf[128];
    tilemap_print_string(1, 0, 0xFFFF, dbg_disasm_title);
    for (i = 0; i < 10; i++) {
        tilemap_print_hex_block(1, i + 11, 14, (s32)tbl, 8, 0);
        y = i + 11;
        tilemap_print_hex_block(10, y, 14, *tbl, 4, 0);
        disasm_sh_opcode(*tbl, buf);
        tilemap_print_string_attr(15, y, 14, buf);
        tbl++;
    }
}



/* provisional name */
void disasm_sh_opcode(u16 code, char* str) {
    char buf[128];
    const MoveName* p;
    u32 hi;
    const char** side;
    u16 kind;
    char* mark;
    char* mark2;
    *str = 0;
    hi = code & 0xFF00;
    if (hi == 0) {
        for (p = sh_op_none_tbl; p->name != 0; p++) {
            if (code == p->code) {
                goto found;
            }
        }
    }
    kind = code & 0xF000;
    if (kind == 0x4000) {
        side = &reg_name_tbl[(s32)(code & 0xF00) >> 8];
        for (p = sh_op_ldm_tbl; p->name != 0; p++) {
            if ((code & 0xF0FF) == p->code) {
                strcpy(buf, p->name);
                mark = strstr(buf, sh_str_rm);
                *mark = 0;
                strcpy(str, buf);
                strcat(str, *side);
                strcat(str, mark + 2);
                return;
            }
        }
    }
    if (kind == 0 || kind == 0x4000) {
        side = &reg_name_tbl[(s32)(code & 0xF00) >> 8];
        for (p = sh_op_n_tbl; p->name != 0; p++) {
            if ((code & 0xF0FF) == p->code) {
                strcpy(buf, p->name);
                mark = strstr(buf, sh_str_rn);
                *mark = 0;
                strcpy(str, buf);
                strcat(str, *side);
                strcat(str, mark + 2);
                return;
            }
        }
    }
    if (kind == 0 || kind == 0x2000 || kind == 0x3000 || kind == 0x4000 || kind == 0x6000) {
        for (p = sh_op_nm_tbl; p->name != 0; p++) {
            if ((code & 0xF00F) == p->code) {
                strcpy(buf, p->name);
                mark = strstr(buf, sh_str_rm);
                *mark = 0;
                strcpy(str, buf);
                strcat(str, reg_name_tbl[(s32)(code & 0xF0) >> 4]);
                mark2 = strstr(mark + 2, sh_str_rn);
                *mark2 = 0;
                strcat(str, mark + 2);
                strcat(str, reg_name_tbl[(s32)(code & 0xF00) >> 8]);
                strcat(str, mark2 + 2);
                return;
            }
        }
    }
    if (kind == 0x8000) {
        for (p = sh_op_disp_m_tbl; p->name != 0; p++) {
            if (hi == p->code) {
                goto found;
            }
        }
    }
    if (kind == 0x8000) {
        for (p = sh_op_disp_n_tbl; p->name != 0; p++) {
            if (hi == p->code) {
                goto found;
            }
        }
    }
    if (kind == 0x8000 || kind == 0xC000) {
        for (p = sh_op_d8_tbl; p->name != 0; p++) {
            if (hi == p->code) {
                goto found;
            }
        }
    }
    if (kind == 0x8000 || kind == 0xC000) {
        for (p = sh_op_imm_tbl; p->name != 0; p++) {
            if (hi == p->code) {
                goto found;
            }
        }
    }
    for (p = sh_op_disp4_tbl; p->name != 0; p++) {
        if (kind == p->code) {
            goto found;
        }
    }
    for (p = sh_op_d12_tbl; p->name != 0; p++) {
        if (kind == p->code) {
            goto found;
        }
    }
    for (p = sh_op_pcrel_tbl; p->name != 0; p++) {
        if (kind == p->code) {
            goto found;
        }
    }
    for (p = sh_op_imm_n_tbl; p->name != 0; p++) {
        if (kind == p->code) {
            goto found;
        }
    }
    if (*str == 0) {
        strcpy(str, sh_str_undef);
    }
    return;
found:
    strcpy(str, p->name);
}

