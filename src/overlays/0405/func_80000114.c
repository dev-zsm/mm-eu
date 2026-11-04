// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe4.h"

void TransitionWipe4_Draw(void* thisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    VisFbuf* copyFx = &((TransitionWipe4*)thisx)->copyFx;

    copyFx->primColor.rgba = ((TransitionWipe4*)thisx)->primColor.rgba;

    if (((TransitionWipe4*)thisx)->direction != 0) {
        copyFx->scale = ((TransitionWipe4*)thisx)->progress;
        copyFx->lodProportion = 1.0f - ((TransitionWipe4*)thisx)->progress;
    } else {
        copyFx->scale = 1.0f - ((TransitionWipe4*)thisx)->progress;
        copyFx->lodProportion = ((TransitionWipe4*)thisx)->progress;
    }

    
    
    VisFbuf_Draw(copyFx, &gfx, SysCfb_GetZBuffer());
    *gfxP = gfx;
}
