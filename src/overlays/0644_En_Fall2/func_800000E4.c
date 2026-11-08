// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall2.h"

void ref_func_80C1B724(f32 arg0) {
    Vtx* vertex = Lib_SegmentedToVirtual(object_fall2_Vtx_005F10);
    u8 perVertexAlphaTable[6];
    s32 i;

    if (arg0 > 1.0f) {
        arg0 = 1.0f;
    }
    if (arg0 < 0.0f) {
        arg0 = 0.0f;
    }
    perVertexAlphaTable[0] = 0;
    perVertexAlphaTable[1] = (s8)(54.0f * arg0);
    perVertexAlphaTable[2] = (s8)(104.0f * arg0);
    perVertexAlphaTable[3] = (s8)(155.0f * arg0);
    perVertexAlphaTable[4] = (s8)(255.0f * arg0);
    perVertexAlphaTable[5] = (s8)(205.0f * arg0);

    for (i = 0; i < ARRAY_COUNT(sAlphaTableIndices); i++, vertex++) {
        vertex->v.cn[3] = perVertexAlphaTable[sAlphaTableIndices[i]];
    }
}
