// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

Gfx* ref_func_808AF86C(GraphicsContext* gfxCtx, PlayState* play) {
    Gfx* gfxHead = GRAPH_ALLOC(gfxCtx, 5 * sizeof(Gfx));
    Gfx* gfx = gfxHead;

    Matrix_ReplaceRotation(&play->billboardMtxF);

    MATRIX_FINALIZE_AND_LOAD(gfx++, gfxCtx);
    gSPEndDisplayList(gfx++);

    return gfxHead;
}
