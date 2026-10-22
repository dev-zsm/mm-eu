// FLAGS: -O2 -g0 -mips2
#include "types.h"

void guMtxL2F(f32 *arg0, u32 *arg1) {
    u32 *var_a1;
    f32 *var_a0;
    u32 hi;
    u32 lo;

    var_a0 = arg0;
    var_a1 = arg1;
    do {
        hi = var_a1[0];
        lo = var_a1[8];
        var_a1++;
        var_a0 += 2;
        var_a0[-2] = (f32)(s32)((hi & 0xFFFF0000) | (lo >> 16)) * 0.000015258789f;
        var_a0[-1] = (f32)(s32)((hi << 16) | (lo & 0xFFFF)) * 0.000015258789f;
    } while (var_a1 != arg1 + 8);
}
