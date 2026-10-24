// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { s16 x, y, z; } V;
V *func_80100304(s32);
s16 func_80180F74(f32, f32);

f32 func_801229D4(u8 *arg0, u8 *arg1, s16 arg2, s16 *arg3) {
    f32 sp1C;
    f32 sp18;
    V *p, *base;

    if (arg1 == NULL) {
        return -1.0f;
    }
    base = func_80100304(*(s32 *)(arg1 + 4));
    p = base + arg2;
    sp1C = p->x - *(f32 *)(arg0 + 0x24);
    sp18 = p->z - *(f32 *)(arg0 + 0x2C);
    *arg3 = func_80180F74(sp1C, sp18);
    return sp1C * sp1C + sp18 * sp18;
}
