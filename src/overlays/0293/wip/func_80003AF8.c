// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2B0]; Gfx *p; } G;
extern u8 D_6000970[];

void func_80003AF8(G **a0, s32 a1, s32 a2, s32 a3) {
    G *g = *a0;
    Gfx *d;
    if (a1 == 0xB) {
        d = g->p++;
        d->w0 = 0xDE000000;
        d->w1 = (u32)D_6000970;
    }
}
