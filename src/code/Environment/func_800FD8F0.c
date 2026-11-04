// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawSkyboxStar(Gfx** gfxP, f32 x, f32 y, s32 width, s32 height) {
    Gfx* gfx = *gfxP;
    u32 xl = x * 4.0f;
    u32 yl = y * 4.0f;
    u32 xd = width;
    u32 yd = height;

    gSPTextureRectangle(gfx++, xl, yl, xl + xd, yl + yd, 0, 0, 0, 0, 0);

    *gfxP = gfx;
}
