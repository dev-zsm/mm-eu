// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

u8 Environment_LerpColor(f32 to, f32 from, f32 lerp) {
    to = CLAMP(to, 0.0f, 255.0f);
    from = CLAMP(from, 0.0f, 255.0f);

    return ((to - from) * lerp) + from;
}
