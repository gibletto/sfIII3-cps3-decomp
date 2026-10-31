/*
 * WORK.C  system settings work
 *
 * The free-running timer tick and the system and game settings that start the game with a value.
 * The boot code copies the image of every object's initialised work RAM from ROM to work RAM
 * 02000000-02007EEB (D_ROM, D_BGN, D_END in sections.src); this object links first, so its
 * variables start that area. The other modules keep their own initialised variables. A <name>_tail
 * table holds the initial values of the bytes between <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

/* provisional name */
u32 frt_tick_count = 0;  /* 02000000 */
s8 Coin_Mode = 0;  /* 02000004 */
s8 Monitor_Flip = 0;  /* 02000005 */
s8 Continue_Flag = 0;  /* 02000006 */
s8 Chute_Mode = 0;  /* 02000007 */
s8 Sound_Mode = 0;  /* 02000008 */
s8 Demo_Sound = 0;  /* 02000009 */
/* 0200000A */
/* Stored after Demo_Sound. Nothing in the program refers to it by name or address. */
u8 Demo_Sound_tail[1] = {
    0,
};

s8 Language = 0;  /* 0200000B */
s8 Free_Play = 0;  /* 0200000C */
u8 Card_Dispenser = 0;  /* 0200000D */
s8 Win_Point_Com = 0;  /* 0200000E */
s8 Win_Point_Human = 0;  /* 0200000F */
s8 Voice_Type = 0;  /* 02000010 */
s8 Win_Point_Com_Max = 8;  /* 02000011 */
s8 Win_Point_Human_Max = 30;  /* 02000012 */
s8 Win_Point_Com_Min = 2;  /* 02000013 */
s8 Win_Point_Human_Min = 2;  /* 02000014 */
s8 Win_Point_Split = 0;  /* 02000015 */
s8 Cabinet_Type = 0;  /* 02000016 */
s8 Area_Type = 0;  /* 02000017 */
s8 Area_Alt_Flag = 0;  /* 02000018 */
s8 Two_Coin_Start = 0;  /* 02000019 */
s8 Free_Play_Enable = 0;  /* 0200001A */
/* 0200001B */
/* Stored after Free_Play_Enable. Nothing in the program refers to it by name or address. */
u8 Free_Play_Enable_tail[2] = {
    0, 0,
};

s8 Cd_Error_Flag = 0;  /* 0200001D */
s16 Config_No_0 = 0;  /* 0200001E */
s16 Config_No_1 = 0;  /* 02000020 */
s16 Config_No_2 = 0;  /* 02000022 */
