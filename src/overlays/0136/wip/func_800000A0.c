// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 D_80901E8C;
extern s16 D_80901E90;
extern f32 D_80901EF4;

void func_800000A0(void) {
    f32 *pf = &D_80901E8C;
    s16 *ps = &D_80901E90;
    f32 x;

    x = *pf + D_80901EF4;
    *ps += 0xFA0;
    *pf = x;
}
