// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
// -Wab,-r4300_mul: the ROM has a nop after the mul.s that precedes a dependent mul.s.
#include "types.h"

s32 BgCheck_ComputeWallDisplacement(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, s32 *arg10) {
    f32 scale;

    scale = (arg9 - arg8) * arg7;
    *arg2 += scale * arg4;
    *arg3 += scale * arg6;
    if (*arg10 == 0) {
        *arg10 = arg1;
        return 1;
    }
    return 0;
}
