/*
 * EXCHANGE.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const KOATT exchange_koa_data_0[];
extern const KOATT exchange_koa_data_1[];
extern const KOATT exchange_koa_data_10[];
extern const KOATT exchange_koa_data_2[];
extern const KOATT exchange_koa_data_3[];
extern const KOATT exchange_koa_data_4[];
extern const KOATT exchange_koa_data_5[];
extern const KOATT exchange_koa_data_6[];
extern const KOATT exchange_koa_data_7[];
extern const KOATT exchange_koa_data_8[];
extern const KOATT exchange_koa_data_9[];

extern const POWER exchange_pow_data_0[];
extern const POWER exchange_pow_data_1[];
extern const POWER exchange_pow_data_2[];

extern const void* const exchange_koa[];
extern const void* const exchange_pow[];

const void* const exchange_pow_pl03_sa3[33] = {
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
    (void*)exchange_pow_data_2,
};

const void* const exchange_pow[33] = {
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_0,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
    (void*)exchange_pow_data_1,
};

/* damage scaling by combo hit: the rows exchange_pow and exchange_pow_pl03_sa3 point at */
const POWER exchange_pow_data_0[2] = {
    { { 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8 } },
    { { 32, 31, 30, 28, 26, 23, 20, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 12, 12, 12, 11, 11, 11, 10, 10, 10, 9, 9, 9, 8 } },
};
const POWER exchange_pow_data_1[1] = {
    { { 32, 30, 28, 26, 24, 22, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 10, 9, 9, 8, 8, 7, 7, 7, 6, 6, 6, 5, 5, 5, 5 } },
};
const POWER exchange_pow_data_2[1] = {
    { { 32, 31, 30, 28, 26, 24, 21, 18, 15, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
};

const void* const exchange_koa[33] = {
    (void*)exchange_koa_data_0,
    (void*)exchange_koa_data_1,
    (void*)exchange_koa_data_2,
    (void*)exchange_koa_data_2,
    (void*)exchange_koa_data_3,
    (void*)exchange_koa_data_3,
    (void*)exchange_koa_data_3,
    (void*)exchange_koa_data_3,
    (void*)exchange_koa_data_4,
    (void*)exchange_koa_data_4,
    (void*)exchange_koa_data_4,
    (void*)exchange_koa_data_4,
    (void*)exchange_koa_data_5,
    (void*)exchange_koa_data_5,
    (void*)exchange_koa_data_5,
    (void*)exchange_koa_data_5,
    (void*)exchange_koa_data_6,
    (void*)exchange_koa_data_6,
    (void*)exchange_koa_data_6,
    (void*)exchange_koa_data_6,
    (void*)exchange_koa_data_7,
    (void*)exchange_koa_data_7,
    (void*)exchange_koa_data_7,
    (void*)exchange_koa_data_7,
    (void*)exchange_koa_data_8,
    (void*)exchange_koa_data_8,
    (void*)exchange_koa_data_8,
    (void*)exchange_koa_data_8,
    (void*)exchange_koa_data_9,
    (void*)exchange_koa_data_9,
    (void*)exchange_koa_data_9,
    (void*)exchange_koa_data_9,
    (void*)exchange_koa_data_10,
};

/* combo counting weights: the rows exchange_koa points at */
const KOATT exchange_koa_data_0[1] = {
    { { { 1536, 256, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_1[1] = {
    { { { 256, 1280, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_2[1] = {
    { { { 256, 256, 1024, 1536 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_3[1] = {
    { { { 256, 512, 768, 768 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_4[1] = {
    { { { 256, 512, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_5[1] = {
    { { { 256, 512, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 512, 512, 512, 512 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_6[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_7[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 256, 256, 256, 256 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_8[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 256, 256, 256, 256 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_9[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 512, 512, 512, 512 }, { 768, 768, 768, 768 }, { 1024, 1024, 1024, 1024 }, { 256, 256, 256, 256 }, { 256, 0, 0, 0 } } },
};
const KOATT exchange_koa_data_10[1] = {
    { { { 0, 256, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 768, 768, 768, 768 }, { 1280, 1280, 1280, 1280 }, { 256, 256, 256, 256 }, { 512, 512, 512, 512 }, { 1024, 1024, 1024, 1024 }, { 1280, 1280, 1280, 1280 }, { 256, 0, 0, 0 } } },
};
