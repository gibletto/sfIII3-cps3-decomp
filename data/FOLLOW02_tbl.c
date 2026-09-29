/*
 * FOLLOW02_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 Follow_Menu_1st_Unit_Data_0[];
extern const u32 Follow_Menu_1st_Unit_Data_2[];
extern const u32 Follow_Menu_2nd_Unit_Data_0[];
extern const u32 Follow_Menu_2nd_Unit_Data_2[];
extern const void* const Pattern20_Tbl_data_0[];

extern void Follow01_0000();
extern void Follow01_0001();
extern void Follow01_0002();
extern void Follow01_0003();
extern void Follow02_0000();
extern void Follow02_0001();
extern void Follow02_0002();
extern void Follow02_0003();
extern void Pattern20_0000();
extern void Pattern20_0001();
extern void Pattern20_0002();
extern void Pattern20_0003();
extern void Pattern20_0004();
extern void Pattern20_0005();
extern void Pattern20_0006();
extern void Pattern20_0007();
extern void Pattern20_0008();
extern void Pattern20_0009();
extern void Pattern20_0010();
extern void Pattern20_0011();
extern void Pattern20_0012();
extern void Pattern20_0013();
extern void Pattern20_0014();
extern void Pattern20_0015();
extern void Pattern20_0016();
extern void Pattern20_0017();
extern void Pattern20_0018();
extern void Pattern20_0019();
extern void Pattern20_0020();
extern void Pattern20_0021();
extern void Pattern20_0022();
extern void Pattern20_0023();
extern void Pattern20_0024();
extern void Pattern20_0025();
extern void Pattern20_0026();
extern void Pattern20_0027();
extern void Pattern20_0028();
extern void Pattern20_0029();
extern void Pattern20_0030();
extern void Pattern20_0031();
extern void Pattern20_0032();
extern void Pattern20_0033();
extern void Pattern20_0034();
extern void Pattern20_0035();
extern void Pattern20_0036();
extern void Pattern20_0037();
extern void Pattern20_0038();
extern void Pattern20_0039();
extern void Pattern20_0040();
extern void Pattern20_0041();
extern void Pattern20_0042();
extern void Pattern20_0043();
extern void Pattern20_0044();
extern void Pattern20_0045();
extern void Pattern20_0046();
extern void Pattern20_0047();
extern void Pattern20_0048();
extern void Pattern20_0049();
extern void Pattern20_0050();
extern void Pattern20_0051();
extern void Pattern20_0052();
extern void Pattern20_0053();
extern void Pattern20_0054();
extern void Pattern20_0055();
extern void Pattern20_0056();
extern void Pattern20_0057();
extern void Pattern20_0058();
extern void Pattern20_0059();
extern void Pattern20_0060();
extern void Pattern20_0061();
extern void Pattern20_0062();
extern void Pattern20_0063();
extern void Pattern20_0064();
extern void Pattern20_0065();
extern void Pattern20_0066();
extern void Pattern20_0067();
extern void Pattern20_0068();
extern void Pattern20_0069();
extern void Pattern20_0070();
extern void Pattern20_0071();
extern void Pattern20_0072();
extern void Pattern20_0073();
extern void Pattern20_0074();
extern void Pattern20_0075();
extern void Pattern20_0076();
extern void Pattern20_0077();
extern void Pattern20_0078();

void (*const Pattern20_Tbl[68])() = {
    Pattern20_0000,  Pattern20_0001,  Pattern20_0002,  Pattern20_0003,  /* 0 */
    Pattern20_0004,  Pattern20_0005,  Pattern20_0006,  Pattern20_0007,  /* 4 */
    Pattern20_0008,  Pattern20_0009,  Pattern20_0010,  Pattern20_0011,  /* 8 */
    Pattern20_0012,  Pattern20_0013,  Pattern20_0014,  Pattern20_0015,  /* 12 */
    Pattern20_0016,  Pattern20_0017,  Pattern20_0018,  Pattern20_0019,  /* 16 */
    Pattern20_0020,  Pattern20_0021,  Pattern20_0022,  Pattern20_0023,  /* 20 */
    Pattern20_0024,  Pattern20_0025,  Pattern20_0026,  Pattern20_0027,  /* 24 */
    Pattern20_0028,  Pattern20_0029,  Pattern20_0030,  Pattern20_0031,  /* 28 */
    Pattern20_0032,  Pattern20_0033,  Pattern20_0034,  Pattern20_0035,  /* 32 */
    Pattern20_0036,  Pattern20_0037,  Pattern20_0038,  Pattern20_0039,  /* 36 */
    Pattern20_0040,  Pattern20_0041,  Pattern20_0042,  Pattern20_0043,  /* 40 */
    Pattern20_0044,  Pattern20_0045,  Pattern20_0046,  Pattern20_0047,  /* 44 */
    Pattern20_0048,  Pattern20_0049,  Pattern20_0050,  Pattern20_0051,  /* 48 */
    Pattern20_0052,  Pattern20_0053,  Pattern20_0054,  Pattern20_0055,  /* 52 */
    Pattern20_0056,  Pattern20_0057,  Pattern20_0058,  Pattern20_0059,  /* 56 */
    Pattern20_0060,  Pattern20_0061,  Pattern20_0062,  Pattern20_0063,  /* 60 */
    Pattern20_0064,  Pattern20_0065,  Pattern20_0066,  Pattern20_0067,  /* 64 */
};

const void* const Pattern20_Tbl_data_0[11] = {
    Pattern20_0068, Pattern20_0069, Pattern20_0070, Pattern20_0071,
    Pattern20_0072, Pattern20_0073, Pattern20_0074, Pattern20_0075,
    Pattern20_0076, Pattern20_0077, Pattern20_0078,
};

const u32 Follow_Menu_1st_Unit_Data_0[128] = {
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
};

const u32 Follow_Menu_2nd_Unit_Data_0[4] = {
    0, 0, 0, 0,
};

const u32 Follow_Menu_1st_Unit_Data_2[128] = {
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
    0, 0, 0x1010101, 0x1010101, 0x2020202, 0x2020202, 0x3030303, 0x3030303,
};

const u32 Follow_Menu_2nd_Unit_Data_2[8] = {
    0x10203, 0x10203, 0x10203, 0x10203, (u32)Follow01_0000, (u32)Follow01_0001, (u32)Follow01_0002, (u32)Follow01_0003,
};

void (*const Follow02_Tbl[4])() = {
    Follow02_0000,
    Follow02_0001,
    Follow02_0002,
    Follow02_0003,
};
