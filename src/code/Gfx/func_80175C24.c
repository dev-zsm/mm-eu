// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/gfxalloc_ctx.h"

void* Gfx_Alloc(Gfx** gfxP, size_t size) {
    u8* start;
    Gfx* gfx;

    size = ALIGN8(size);
    start = (u8*)&(*gfxP)[1];
    gfx = (Gfx*)(start + size);
    gSPBranchList(*gfxP, gfx);

    *gfxP = gfx;
    return start;
}
