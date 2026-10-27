// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 Curve_CubicHermiteSpline(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp4;
    f32 pad[5]; // unused, only to match the ROM frame size
    f32 t2;
    f32 t3;
    f32 t3x2;

    t2 = arg0 * arg0;
    t3 = t2 * arg0;
    t3x2 = 2.0f * t3;
    sp4 = t2 * 3.0f;
    return (((t3x2 - sp4) + 1.0f) * arg2) + ((sp4 - t3x2) * arg3) + (((t3 - (2.0f * t2)) + arg0) * arg4 * arg1) +
           ((t3 - t2) * arg5 * arg1);
}
