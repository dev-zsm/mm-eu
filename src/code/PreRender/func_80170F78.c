// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/PreRender.h"

void PreRender_CopyImage(PreRender* this, Gfx** gfxP, void* img, void* imgDst, u32 useThresholdAlphaCompare) {
    Gfx* gfx = *gfxP;
    u32 flags;

    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, this->width, imgDst);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, this->width, this->height);

    flags = BG2D_FLAGS_LOAD_S2DEX2 | BG2D_FLAGS_COPY;
    if (useThresholdAlphaCompare == true) {
        flags |= BG2D_FLAGS_AC_THRESHOLD;
    }

    Prerender_DrawBackground2D(&gfx, img, NULL, this->width, this->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TT_NONE, 0,
                               0.0f, 0.0f, 1.0f, 1.0f, flags);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, this->width, this->fbuf);

    *gfxP = gfx;
}
