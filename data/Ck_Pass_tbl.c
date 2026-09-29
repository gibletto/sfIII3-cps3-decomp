/*
 * CK_PASS_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void GILL_vs();
extern void HUGO_vs();
extern void KEN_vs();
extern void VS_ALEX_A();
extern void VS_ALEX_AS();
extern void VS_ALEX_B();
extern void VS_ALEX_BS();
extern void VS_ALEX_C();
extern void VS_ALEX_CS();
extern void VS_ALEX_D();
extern void VS_ALEX_DS();
extern void VS_CHUN_LI_A();
extern void VS_CHUN_LI_AS();
extern void VS_CHUN_LI_B();
extern void VS_CHUN_LI_BS();
extern void VS_CHUN_LI_C();
extern void VS_CHUN_LI_CS();
extern void VS_CHUN_LI_D();
extern void VS_CHUN_LI_DS();
extern void VS_DUDLEY_A();
extern void VS_DUDLEY_AS();
extern void VS_DUDLEY_B();
extern void VS_DUDLEY_BS();
extern void VS_DUDLEY_C();
extern void VS_DUDLEY_CS();
extern void VS_DUDLEY_D();
extern void VS_DUDLEY_DS();
extern void VS_ELENA_A();
extern void VS_ELENA_AS();
extern void VS_ELENA_B();
extern void VS_ELENA_BS();
extern void VS_ELENA_C();
extern void VS_ELENA_CS();
extern void VS_ELENA_D();
extern void VS_ELENA_DS();
extern void VS_GILL_A();
extern void VS_GILL_AS();
extern void VS_GILL_B();
extern void VS_GILL_BS();
extern void VS_GILL_C();
extern void VS_GILL_CS();
extern void VS_GILL_D();
extern void VS_GILL_DS();
extern void VS_GOUKI_A();
extern void VS_GOUKI_AS();
extern void VS_GOUKI_B();
extern void VS_GOUKI_BS();
extern void VS_GOUKI_C();
extern void VS_GOUKI_CS();
extern void VS_GOUKI_D();
extern void VS_GOUKI_DS();
extern void VS_HUGO_A();
extern void VS_HUGO_AS();
extern void VS_HUGO_B();
extern void VS_HUGO_BS();
extern void VS_HUGO_C();
extern void VS_HUGO_CS();
extern void VS_HUGO_D();
extern void VS_HUGO_DS();
extern void VS_IBUKI_A();
extern void VS_IBUKI_AS();
extern void VS_IBUKI_B();
extern void VS_IBUKI_BS();
extern void VS_IBUKI_C();
extern void VS_IBUKI_CS();
extern void VS_IBUKI_D();
extern void VS_IBUKI_DS();
extern void VS_KEN_A();
extern void VS_KEN_AS();
extern void VS_KEN_B();
extern void VS_KEN_BS();
extern void VS_KEN_C();
extern void VS_KEN_CS();
extern void VS_KEN_D();
extern void VS_KEN_DS();
extern void VS_MAKOTO_A();
extern void VS_MAKOTO_AS();
extern void VS_MAKOTO_B();
extern void VS_MAKOTO_BS();
extern void VS_MAKOTO_C();
extern void VS_MAKOTO_CS();
extern void VS_MAKOTO_D();
extern void VS_MAKOTO_DS();
extern void VS_NECRO_A();
extern void VS_NECRO_AS();
extern void VS_NECRO_B();
extern void VS_NECRO_BS();
extern void VS_NECRO_C();
extern void VS_NECRO_CS();
extern void VS_NECRO_D();
extern void VS_NECRO_DS();
extern void VS_NO12_A();
extern void VS_NO12_AS();
extern void VS_NO12_B();
extern void VS_NO12_BS();
extern void VS_NO12_C();
extern void VS_NO12_CS();
extern void VS_NO12_D();
extern void VS_NO12_DS();
extern void VS_ORO_A();
extern void VS_ORO_AS();
extern void VS_ORO_B();
extern void VS_ORO_BS();
extern void VS_ORO_C();
extern void VS_ORO_CS();
extern void VS_ORO_D();
extern void VS_ORO_DS();
extern void VS_Q_A();
extern void VS_Q_AS();
extern void VS_Q_B();
extern void VS_Q_BS();
extern void VS_Q_C();
extern void VS_Q_CS();
extern void VS_Q_D();
extern void VS_Q_DS();
extern void VS_REMY_A();
extern void VS_REMY_AS();
extern void VS_REMY_B();
extern void VS_REMY_BS();
extern void VS_REMY_C();
extern void VS_REMY_CS();
extern void VS_REMY_D();
extern void VS_REMY_DS();
extern void VS_RYU_A();
extern void VS_RYU_AS();
extern void VS_RYU_B();
extern void VS_RYU_BS();
extern void VS_RYU_C();
extern void VS_RYU_CS();
extern void VS_RYU_D();
extern void VS_RYU_DS();
extern void VS_SEAN_A();
extern void VS_SEAN_AS();
extern void VS_SEAN_B();
extern void VS_SEAN_BS();
extern void VS_SEAN_C();
extern void VS_SEAN_CS();
extern void VS_SEAN_D();
extern void VS_SEAN_DS();
extern void VS_URIEN_A();
extern void VS_URIEN_AS();
extern void VS_URIEN_B();
extern void VS_URIEN_BS();
extern void VS_URIEN_C();
extern void VS_URIEN_CS();
extern void VS_URIEN_D();
extern void VS_URIEN_DS();
extern void VS_YUN_A();
extern void VS_YUN_AS();
extern void VS_YUN_B();
extern void VS_YUN_BS();
extern void VS_YUN_C();
extern void VS_YUN_CS();
extern void VS_YUN_D();
extern void VS_YUN_DS();

void (*const Passive_jmp_tbl[21])() = {
    GILL_vs,  KEN_vs,   KEN_vs,   KEN_vs,  /* 0 */
    KEN_vs,   KEN_vs,   HUGO_vs,  KEN_vs,  /* 4 */
    KEN_vs,   KEN_vs,   KEN_vs,   KEN_vs,  /* 8 */
    KEN_vs,   KEN_vs,   KEN_vs,   KEN_vs,  /* 12 */
    KEN_vs,   KEN_vs,   KEN_vs,   KEN_vs,  /* 16 */
    KEN_vs,  /* 20 */
};

void (*const Passive_AS_tbl[21])() = {
    VS_GILL_AS,     VS_ALEX_AS,     VS_RYU_AS,      VS_YUN_AS,      /* 0 */
    VS_DUDLEY_AS,   VS_NECRO_AS,    VS_HUGO_AS,     VS_IBUKI_AS,    /* 4 */
    VS_ELENA_AS,    VS_ORO_AS,      VS_YUN_AS,      VS_KEN_AS,      /* 8 */
    VS_SEAN_AS,     VS_URIEN_AS,    VS_GOUKI_AS,    VS_GOUKI_AS,    /* 12 */
    VS_CHUN_LI_AS,  VS_MAKOTO_AS,   VS_Q_AS,        VS_NO12_AS,     /* 16 */
    VS_REMY_AS,     /* 20 */
};

void (*const Passive_A_tbl[21])() = {
    VS_GILL_A,     VS_ALEX_A,     VS_RYU_A,      VS_YUN_A,      /* 0 */
    VS_DUDLEY_A,   VS_NECRO_A,    VS_HUGO_A,     VS_IBUKI_A,    /* 4 */
    VS_ELENA_A,    VS_ORO_A,      VS_YUN_A,      VS_KEN_A,      /* 8 */
    VS_SEAN_A,     VS_URIEN_A,    VS_GOUKI_A,    VS_GOUKI_A,    /* 12 */
    VS_CHUN_LI_A,  VS_MAKOTO_A,   VS_Q_A,        VS_NO12_A,     /* 16 */
    VS_REMY_A,     /* 20 */
};

void (*const Passive_BS_tbl[21])() = {
    VS_GILL_BS,     VS_ALEX_BS,     VS_RYU_BS,      VS_YUN_BS,      /* 0 */
    VS_DUDLEY_BS,   VS_NECRO_BS,    VS_HUGO_BS,     VS_IBUKI_BS,    /* 4 */
    VS_ELENA_BS,    VS_ORO_BS,      VS_YUN_BS,      VS_KEN_BS,      /* 8 */
    VS_SEAN_BS,     VS_URIEN_BS,    VS_GOUKI_BS,    VS_GOUKI_BS,    /* 12 */
    VS_CHUN_LI_BS,  VS_MAKOTO_BS,   VS_Q_BS,        VS_NO12_BS,     /* 16 */
    VS_REMY_BS,     /* 20 */
};

void (*const Passive_B_tbl[21])() = {
    VS_GILL_B,     VS_ALEX_B,     VS_RYU_B,      VS_YUN_B,      /* 0 */
    VS_DUDLEY_B,   VS_NECRO_B,    VS_HUGO_B,     VS_IBUKI_B,    /* 4 */
    VS_ELENA_B,    VS_ORO_B,      VS_YUN_B,      VS_KEN_B,      /* 8 */
    VS_SEAN_B,     VS_URIEN_B,    VS_GOUKI_B,    VS_GOUKI_B,    /* 12 */
    VS_CHUN_LI_B,  VS_MAKOTO_B,   VS_Q_B,        VS_NO12_B,     /* 16 */
    VS_REMY_B,     /* 20 */
};

void (*const Passive_CS_tbl[21])() = {
    VS_GILL_CS,     VS_ALEX_CS,     VS_RYU_CS,      VS_YUN_CS,      /* 0 */
    VS_DUDLEY_CS,   VS_NECRO_CS,    VS_HUGO_CS,     VS_IBUKI_CS,    /* 4 */
    VS_ELENA_CS,    VS_ORO_CS,      VS_YUN_CS,      VS_KEN_CS,      /* 8 */
    VS_SEAN_CS,     VS_URIEN_CS,    VS_GOUKI_CS,    VS_GOUKI_CS,    /* 12 */
    VS_CHUN_LI_CS,  VS_MAKOTO_CS,   VS_Q_CS,        VS_NO12_CS,     /* 16 */
    VS_REMY_CS,     /* 20 */
};

void (*const Passive_C_tbl[21])() = {
    VS_GILL_C,     VS_ALEX_C,     VS_RYU_C,      VS_YUN_C,      /* 0 */
    VS_DUDLEY_C,   VS_NECRO_C,    VS_HUGO_C,     VS_IBUKI_C,    /* 4 */
    VS_ELENA_C,    VS_ORO_C,      VS_YUN_C,      VS_KEN_C,      /* 8 */
    VS_SEAN_C,     VS_URIEN_C,    VS_GOUKI_C,    VS_GOUKI_C,    /* 12 */
    VS_CHUN_LI_C,  VS_MAKOTO_C,   VS_Q_C,        VS_NO12_C,     /* 16 */
    VS_REMY_C,     /* 20 */
};

void (*const Passive_DS_tbl[21])() = {
    VS_GILL_DS,     VS_ALEX_DS,     VS_RYU_DS,      VS_YUN_DS,      /* 0 */
    VS_DUDLEY_DS,   VS_NECRO_DS,    VS_HUGO_DS,     VS_IBUKI_DS,    /* 4 */
    VS_ELENA_DS,    VS_ORO_DS,      VS_YUN_DS,      VS_KEN_DS,      /* 8 */
    VS_SEAN_DS,     VS_URIEN_DS,    VS_GOUKI_DS,    VS_GOUKI_DS,    /* 12 */
    VS_CHUN_LI_DS,  VS_MAKOTO_DS,   VS_Q_DS,        VS_NO12_DS,     /* 16 */
    VS_REMY_DS,     /* 20 */
};

void (*const Passive_D_tbl[21])() = {
    VS_GILL_D,     VS_ALEX_D,     VS_RYU_D,      VS_YUN_D,      /* 0 */
    VS_DUDLEY_D,   VS_NECRO_D,    VS_HUGO_D,     VS_IBUKI_D,    /* 4 */
    VS_ELENA_D,    VS_ORO_D,      VS_YUN_D,      VS_KEN_D,      /* 8 */
    VS_SEAN_D,     VS_URIEN_D,    VS_GOUKI_D,    VS_GOUKI_D,    /* 12 */
    VS_CHUN_LI_D,  VS_MAKOTO_D,   VS_Q_D,        VS_NO12_D,     /* 16 */
    VS_REMY_D,     /* 20 */
};

