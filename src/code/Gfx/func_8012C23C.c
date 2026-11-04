// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx* Gfx_SetFogWithSync(Gfx* gfx, s32 r, s32 g, s32 b, s32 a, s32 n, s32 f) {
    gDPPipeSync(gfx++);
    gDPSetFogColor(gfx++, r, g, b, a);

    if (n >= 1000) {
        gSPFogFactor(gfx++, 0, 0); 
    } else if (n >= 997) {
        gSPFogFactor(gfx++, 0x7FFF, 0x8100); 
    } else if (n < 0) {
        gSPFogFactor(gfx++, 0, 255); 
    } else {
        gSPFogPosition(gfx++, n, f);
    }

    return gfx;
}
