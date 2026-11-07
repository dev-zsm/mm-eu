// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

f32 EnSlime_SnapIceBlockPosition(f32 currentPosition, f32 homePosition) {
    s32 dist = currentPosition - homePosition;

    if (dist > 0) {
        dist += 30;
    } else {
        dist -= 30;
    }

    return ((dist / 60) * 60.0f) + homePosition;
}
