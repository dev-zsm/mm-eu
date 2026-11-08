// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16974(f32 arg0) {
    Vtx* vtx = Lib_SegmentedToVirtual(&object_syotenVtx_0018C0);
    u8 sp20[3];
    s32 i;

    arg0 = CLAMP_MAX(arg0, 1.0f);

    sp20[0] = (s8)0.0f;
    sp20[1] = (s8)(152.0f * arg0);
    sp20[2] = (s8)(255.0f * arg0);

    for (i = 0; i < ARRAY_COUNT(ref_D_80C177D0); i++, vtx++) {
        vtx->v.cn[3] = sp20[ref_D_80C177D0[i]];
    }
}
