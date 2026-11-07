// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x1AC]; void *p1AC; u8 pad1[4]; s32 w1B4; u8 pad2[4]; s16 s1BC; u8 b1BE; } S0462;
extern u8 D_80AFAED0[];

void func_800009F0(S0462 *a0, s32 a1, s32 a2, s32 a3) {
    a0->w1B4 = a1;
    a0->b1BE = a2;
    a0->s1BC = a3;
    a0->p1AC = D_80AFAED0;
}
