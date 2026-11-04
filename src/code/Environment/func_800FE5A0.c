// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_LerpSandstormColors(Color_RGBA8* colorSrc, Color_RGBA8* colorDst) {
    f32 sandstormLerpScale = Environment_GetSandstormLerpScale();
    s32 pad;
    u32 sandstormColorIndex = Environment_GetSandstormColorIndex();
    u32 nextSandstormColorIndex = Environment_GetNextSandstormColorIndex();

    if (sandstormLerpScale <= 0.0f) {
        colorDst->r = colorSrc[sandstormColorIndex].r;
        colorDst->g = colorSrc[sandstormColorIndex].g;
        colorDst->b = colorSrc[sandstormColorIndex].b;
        colorDst->a = colorSrc[sandstormColorIndex].a;
    } else {
        colorDst->r =
            (s32)F32_LERP(colorSrc[sandstormColorIndex].r, colorSrc[nextSandstormColorIndex].r, sandstormLerpScale);
        colorDst->g =
            (s32)F32_LERP(colorSrc[sandstormColorIndex].g, colorSrc[nextSandstormColorIndex].g, sandstormLerpScale);
        colorDst->b =
            (s32)F32_LERP(colorSrc[sandstormColorIndex].b, colorSrc[nextSandstormColorIndex].b, sandstormLerpScale);
        colorDst->a =
            (s32)F32_LERP(colorSrc[sandstormColorIndex].a, colorSrc[nextSandstormColorIndex].a, sandstormLerpScale);
    }
}
