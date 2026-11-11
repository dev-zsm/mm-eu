// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_visfbuf.h"

void VisFbuf_DrawBgToColorImage(Gfx** gfxP, uObjBg* bg, void* img, s32 width, s32 height, VisFbufBgMode cycleMode) {
    Gfx* gfx = *gfxP;

    gDPPipeSync(gfx++);
    
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, img);
    gDPSetScissor(gfx++, 0, 0, 0, width, height);

    
    gSPObjRenderMode(gfx++, G_OBJRM_ANTIALIAS | G_OBJRM_BILERP);
    if (!!(cycleMode & VIS_FBUF_BG_CYC_COPY) != 0) { 
        gSPBgRectCopy(gfx++, bg);
    } else {
        gSPBgRect1Cyc(gfx++, bg);
    }

    gDPPipeSync(gfx++);
    
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, gCfbWidth, ref_D_0F000000);
    gSPDisplayList(gfx++, ref_D_0E000000.setScissor);

    *gfxP = gfx;
}
