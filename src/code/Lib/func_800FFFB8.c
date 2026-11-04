// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lib.h"

void Color_RGB8_Lerp(Color_RGB8* from, Color_RGB8* to, f32 lerp, Color_RGB8* dst) {
    f32 aF;

    aF = from->r;
    dst->r = aF + (to->r - aF) * lerp;
    aF = from->g;
    dst->g = aF + (to->g - aF) * lerp;
    aF = from->b;
    dst->b = aF + (to->b - aF) * lerp;
}
