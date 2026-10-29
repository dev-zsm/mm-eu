// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_801D8624;
extern f32 D_801D8628;
extern f32 D_801D862C;

s8 AudioSfx_ComputeCombFilter(f32 arg0, s32 a1) {
    s8 v;

    if (arg0 < 0.0f) {
        if (arg0 < D_801D8624) {
            v = -0x20;
        } else {
            v = (s8)(s32)(((D_801D8628 + arg0) / D_801D8628) * 31.0f);
            v += 0xE0;
        }
    } else if (D_801D862C < arg0) {
        v = 0x7F;
    } else {
        v = (s32)((arg0 / D_801D862C) * 126.0f);
    }
    return v | 1;
}
