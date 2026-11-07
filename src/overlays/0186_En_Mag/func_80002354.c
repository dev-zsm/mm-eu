// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mag.h"

void EnMag_DrawCharTexture(Gfx** gfxP, TexturePtr texture, s32 rectLeft, s32 rectTop) {
    Gfx* gfx = *gfxP;

    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    
    
    gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + 10) << 2, (rectTop + 10) << 2, G_TX_RENDERTILE,
                        0, 0, 1625, 1625);

    *gfxP = gfx;
}
