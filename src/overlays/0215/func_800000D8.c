// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_k_fire.h"

void EffectSsKFire_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    f32 xzScale;
    f32 yScale;

    xzScale = this->rXZScale / 10000.0f;
    yScale = this->rYScale / 10000.0f;

    OPEN_DISPS(gfxCtx);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(xzScale, yScale, xzScale, MTXMODE_APPLY);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, play->state.frames * this->rScroll, 0x20,
                                0x80));

    if (this->rType >= 100) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, this->rAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 10, 0, 0);
    } else {
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, this->rAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, 0);
    }

    gDPPipeSync(POLY_XLU_DISP++);
    Matrix_ReplaceRotation(&play->billboardMtxF);

    if ((index % 2) != 0) {
        Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
    }

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(gfxCtx);
}
