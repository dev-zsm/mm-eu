// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2B0]; Gfx *p; } G;
typedef struct { u8 pad[0x25C]; s32 unk25C; } Act;
extern u32 D_80C08990[];

void func_80000170(G **a0, s32 a1, s32 a2, s32 a3, Act *a4) {
    G *g = *a0;
    Gfx *d;
    if (a1 == 0xF) {
        d = g->p++;
        d->w0 = 0xDE000000;
        d->w1 = D_80C08990[a4->unk25C];
    }
}
