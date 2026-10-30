/*
 * PLPCU_TBL.C  thrown player routine tables
 *
 * plpcu_lv_00 is the list of caught routines Caught_00000 - Caught_03000, indexed by caught
 * routine number; setup_cu_dm_init_data lists the scdmd_ routines that set up the damage state
 * a thrown player is released into, indexed by routine number minus 12. plpcu_lv_00_tail
 * follows plpcu_lv_00 and is not referred to. Read by PLPCU.C, the player caught process.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Caught_00000();
extern void Caught_01000();
extern void Caught_02000();
extern void Caught_03000();
extern void scdmd_12000();
extern void scdmd_14000();
extern void scdmd_16000();
extern void scdmd_17000();
extern void scdmd_18000();
extern void scdmd_19000();
extern void scdmd_20000();
extern void scdmd_21000();
extern void scdmd_23000();
extern void scdmd_24000();
extern void scdmd_25000();
extern void scdmd_26000();
extern void scdmd_27000();
extern void scdmd_28000();
extern void scdmd_29000();
extern void scdmd_30000();
extern void scdmd_31000();

void (*const setup_cu_dm_init_data[20])() = {
    scdmd_12000,  scdmd_12000,  scdmd_14000,  scdmd_14000,  /* 0 */
    scdmd_16000,  scdmd_17000,  scdmd_18000,  scdmd_19000,  /* 4 */
    scdmd_20000,  scdmd_21000,  scdmd_21000,  scdmd_23000,  /* 8 */
    scdmd_24000,  scdmd_25000,  scdmd_26000,  scdmd_27000,  /* 12 */
    scdmd_28000,  scdmd_29000,  scdmd_30000,  scdmd_31000,  /* 16 */
};

void (*const plpcu_lv_00[4])() = {
    Caught_00000,
    Caught_01000,
    Caught_02000,
    Caught_03000,
};

/* Stored after plpcu_lv_00. Nothing in the program refers to it by name or address. */
const u8 plpcu_lv_00_tail[4] = {
    0, 0, 0, 0,
};

