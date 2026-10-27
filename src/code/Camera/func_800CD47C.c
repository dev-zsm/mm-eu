// FLAGS: -O2 -g3 -mips2
#include "types.h"
float sqrtf(float);
#pragma intrinsic (sqrtf)
extern u8 D_801AF820[];
f32 Camera_GetAttentionActorRange(u8 *a0) {
    f32 *v = (f32 *)(D_801AF820 + ((s8)a0[0x1F] << 3));
    f32 r = sqrtf(v[0] / v[1]);
    return r;
}
