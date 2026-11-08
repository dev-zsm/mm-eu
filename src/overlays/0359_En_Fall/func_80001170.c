// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Fireball_SetPerVertexAlpha(f32 fireballAlpha) {
    s32 pad;
    u8 perVertexAlphaTable[5];
    Vtx* vertices = Lib_SegmentedToVirtual(gMoonFireballVtx);
    s32 i;

    if (fireballAlpha > 1.0f) {
        fireballAlpha = 1.0f;
    }
    perVertexAlphaTable[0] = 0;
    perVertexAlphaTable[1] = (s8)(255.0f * fireballAlpha);
    perVertexAlphaTable[2] = (s8)(155.0f * fireballAlpha);
    perVertexAlphaTable[3] = (s8)(104.0f * fireballAlpha);
    perVertexAlphaTable[4] = (s8)(54.0f * fireballAlpha);

    for (i = 0; i < ARRAY_COUNT(sAlphaTableIndices); i++, vertices++) {
        vertices->v.cn[3] = perVertexAlphaTable[sAlphaTableIndices[i]];
    }
}
