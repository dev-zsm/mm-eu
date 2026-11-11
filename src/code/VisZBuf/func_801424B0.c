// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_viszbuf.h"

void VisZBuf_Draw(VisZBuf* this, Gfx** gfxP, void* zbuffer) {
    Gfx* gfx = *gfxP;
    s32 height = VISZBUF_ZBUFFRAG_HEIGHT;
    s32 y;
    s32 fmt = (this->vis.type == VIS_ZBUF_TYPE_IA) ? G_IM_FMT_IA : G_IM_FMT_RGBA;

    if (zbuffer == NULL) {
        return;
    }

    gDPPipeSync(gfx++);
    if (this->vis.scissorType == VIS_SETSCISSOR) {
        gSPDisplayList(gfx++, ref_D_0E000000.setScissor);
    }

    
    
    
    gDPSetOtherMode(gfx++,
                    G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                        G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
                    G_AC_NONE | G_ZS_PRIM | G_RM_OPA_SURF | G_RM_OPA_SURF2);

    
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT);
    gDPSetColor(gfx++, G_SETPRIMCOLOR, this->vis.primColor.rgba);
    gDPSetColor(gfx++, G_SETENVCOLOR, this->vis.envColor.rgba);

    for (y = 0; y < (gCfbHeight - height) + 1; y += height) {
        
        gDPLoadTextureTile(gfx++, zbuffer, fmt, G_IM_SIZ_16b, gCfbWidth, 0, 0, y, gCfbWidth - 1, (y + height) - 1, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        
        gSPTextureRectangle(gfx++, 0, y << 2, gCfbWidth << 2, (y + height) << 2, G_TX_RENDERTILE, 0, y << 5, 1 << 10,
                            1 << 10);
    }

    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
