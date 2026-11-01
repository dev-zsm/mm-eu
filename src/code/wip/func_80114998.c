// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x2B];
    /* 0x4C */ u8 unk4C[0x20];
    /* 0x6C */ u8 unk6C[0x10];
} Tbl;

extern Tbl D_801E6EF0;

#define GETA(r) r = (D_801E6EF0.unk20 == 4) ? 0 : D_801E6EF0.unk20;

void func_80114998(s16 a0) {
    s16 i;
    s32 a, b, c;
    s32 v;

    i = 1;
    do {
        if (i == 0) {
            GETA(a)
            v = D_801E6EF0.unk4C[a * 4 + i];
        } else {
            v = D_801E6EF0.unk4C[i];
        }
        if (a0 == (u8)v) {
            if (i == 0) {
                GETA(b)
                D_801E6EF0.unk4C[b * 4 + i] = 0xFF;
            } else {
                D_801E6EF0.unk4C[i] = 0xFF;
            }
            if (i == 0) {
                GETA(c)
                D_801E6EF0.unk4C[0x10 + c * 4 + i] = 0xFF;
            } else {
                D_801E6EF0.unk4C[0x10 + i] = 0xFF;
            }
        }
        i++;
    } while (i < 4);
}
