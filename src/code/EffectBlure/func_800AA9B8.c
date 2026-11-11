// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_SetupSimpleAlt(GraphicsContext* gfxCtx, EffectBlure* this, Vtx* vtx) {
    OPEN_DISPS(gfxCtx);

    gDPPipeSync(POLY_XLU_DISP++);
    POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_38);

    gDPSetCycleType(POLY_XLU_DISP++, G_CYC_2CYCLE);
    gDPSetTextureLUT(POLY_XLU_DISP++, G_TT_NONE);
    gSPTexture(POLY_XLU_DISP++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(POLY_XLU_DISP++, gameplay_keep_Tex_014570, G_IM_FMT_I, G_IM_SIZ_8b, 64, 32, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetCombineLERP(POLY_XLU_DISP++, TEXEL0, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
    gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
    gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(POLY_XLU_DISP++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(POLY_XLU_DISP++);

    gDPSetEnvColor(POLY_XLU_DISP++, this->altEnvColor.r, this->altEnvColor.g, this->altEnvColor.b, this->altEnvColor.a);

    CLOSE_DISPS(gfxCtx);
}
