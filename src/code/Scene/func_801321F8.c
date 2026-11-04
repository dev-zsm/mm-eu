// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene_proc.h"

void Scene_SetCullFlag(PlayState* play, s32 index, u32 flags) {
    static Gfx sSetBackCullDL[] = {
        gsSPSetGeometryMode(G_CULL_BACK),
        gsSPEndDisplayList(),
    };
    static Gfx sSetFrontCullDL[] = {
        gsSPSetGeometryMode(G_CULL_FRONT),
        gsSPEndDisplayList(),
    };
    static Gfx* sDLists[] = {
        sSetBackCullDL,
        sSetFrontCullDL,
    };
    Gfx* dList = sDLists[index];

    OPEN_DISPS(play->state.gfxCtx);

    if (flags & 1) {
        gSPSegment(POLY_OPA_DISP++, 0x0C, dList);
    }

    if (flags & 2) {
        gSPSegment(POLY_XLU_DISP++, 0x0C, dList);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
