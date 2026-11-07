// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_stone1.h"

void EffectSsStone1_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    EffStoneDrawInfo* drawParams = &sDrawInfo[this->life];
    Vec3f mfVec;
    f32 mfW;
    f32 scale;

    OPEN_DISPS(gfxCtx);

    SkinMatrix_Vec3fMtxFMultXYZW(&play->viewProjectionMtxF, &this->pos, &mfVec, &mfW);
    scale = (mfW < 1500.0f) ? 3.0f : (mfW / 1500.0f) * 3.0f;
    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
    Gfx_SetupDL61_Xlu(gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(drawParams->texture));
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, drawParams->primColor.r, drawParams->primColor.g, drawParams->primColor.b,
                    255);
    gDPSetEnvColor(POLY_XLU_DISP++, drawParams->envColor.r, drawParams->envColor.g, drawParams->envColor.b, 255);
    gSPDisplayList(POLY_XLU_DISP++, gEffStoneDL);

    CLOSE_DISPS(gfxCtx);
}
