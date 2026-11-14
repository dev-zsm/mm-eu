// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_80000390(f32 alphaScale) {
    static u8 sAlphaTypes[] = { 1, 1, 2, 0, 1, 1, 2, 0, 1, 2, 0, 2, 1, 0, 1, 0, 2, 0, 2, 2, 0 };
    Vtx* vtx = Lib_SegmentedToVirtual(gTimewarpVtx);
    s32 i;
    u8 alphas[3];

    alphas[0] = 0;
    alphas[1] = (s32)(202.0f * alphaScale);
    alphas[2] = (s32)(255.0f * alphaScale);

    for (i = 0; i < ARRAY_COUNT(sAlphaTypes); i++) {
        if (sAlphaTypes[i] != 0) {
            vtx[i].v.cn[3] = alphas[sAlphaTypes[i]];
        }
    }
}
