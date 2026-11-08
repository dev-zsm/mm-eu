// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct G {
    /* 0x00 */ u8 pad0[0x3A];
    /* 0x3A */ s16 unk3A;
} G;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x364];
    /* 0x364 */ s16 unk364;
    /* 0x366 */ u8 unk366;
} Ea;

extern G D_801E6EF0;
extern u8 D_801C2D42;

s32 func_80000628(Ea *arg0) {
    u8 *p = (u8 *)&D_801E6EF0 + D_801C2D42;

    if (p[0x70] != 0xA) {
        return 0;
    }
    if (D_801E6EF0.unk3A < 0xA) {
        return 1;
    }
    if ((s8)p[0xA0] >= 0x14) {
        return 2;
    }
    arg0->unk364 = -0xA;
    arg0->unk366 = 0xA;
    return 3;
}
