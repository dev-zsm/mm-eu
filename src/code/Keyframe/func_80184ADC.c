// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

void Keyframe_MorphInterpolateRotation(f32 t, s16* out, s16 rot1, s16 rot2) {
    u16 urot1 = rot1;
    s32 pad;
    u16 urot2 = rot2;
    f32 rot1f = rot1;
    f32 signedDiff = rot2 - rot1f;
    f32 urot1f = urot1;
    f32 unsignedDiff = urot2 - urot1f;

    if (fabsf(signedDiff) < fabsf(unsignedDiff)) {
        *out = rot1f + signedDiff * t;
    } else {
        *out = urot1f + unsignedDiff * t;
    }
}
