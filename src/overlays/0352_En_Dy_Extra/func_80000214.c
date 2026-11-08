// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dy_extra.h"

void EnDyExtra_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnDyExtra* this = (EnDyExtra*)thisx;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    Vtx* vertices = Lib_SegmentedToVirtual(gGreatFairySpiralBeamVtx);
    s32 i;
    u8 alphas[3];

    alphas[0] = 0.0f;
    alphas[1] = (s32)(this->alphaScale * 240.0f);
    alphas[2] = (s32)(this->alphaScale * 255.0f);

    for (i = 0; i < ARRAY_COUNT(sAlphaTypeIndices); i++) {
        if (sAlphaTypeIndices[i]) {
            vertices[i].v.cn[3] = alphas[sAlphaTypeIndices[i]];
        }
    }

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, play->state.frames * 2, 0, 0x20, 0x40, 1, play->state.frames,
                                play->state.frames * -8, 0x10, 0x10));
    gDPPipeSync(POLY_XLU_DISP++);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, sPrimColors[this->type].r, sPrimColors[this->type].g,
                    sPrimColors[this->type].b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, sEnvColors[this->type].r, sEnvColors[this->type].g, sEnvColors[this->type].b, 128);
    gSPDisplayList(POLY_XLU_DISP++, gGreatFairySpiralBeamDL);

    CLOSE_DISPS(gfxCtx);
}
