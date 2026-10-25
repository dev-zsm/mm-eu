// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"
extern f32 D_800976C4;
extern f32 D_80099384;
extern f32 D_80099388;
f32 Math_FAtanContFracF(f32 x) {
    s32 sector;
    f32 z;
    f32 conv;
    f32 sq;
    s32 i;
    if (x >= -1.0f && x <= 1.0f) {
        sector = 0;
    } else if (1.0f < x) {
        sector = 1;
        x = 1.0f / x;
    } else if (x < -1.0f) {
        sector = -1;
        x = 1.0f / x;
    } else {
        return D_800976C4;
    }
    sq = x * x; z = 0.0f; conv = 8.0f;
    for (i = 8; i > 0; i--) { z = ((conv * conv) * sq) / (((conv + conv) + 1.0f) + z); conv -= 1.0f; }
    z = x / (1.0f + z);
    if (sector == 0) {
        return z;
    }
    if (sector > 0) {
        return D_80099384 - z;
    }
    return D_80099388 - z;
}
