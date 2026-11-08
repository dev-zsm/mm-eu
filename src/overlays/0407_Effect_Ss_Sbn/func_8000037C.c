// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sbn.h"

void EffectSsSbn_DrawSliding(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    MtxF mtx;
    f32 scale = this->rScale * 0.001f;
    s32 pad;

    ref_func_800C0094(this->gfx, this->pos.x, this->pos.y, this->pos.z, &mtx);
    SkinMatrix_MulYRotation(&mtx, this->rRotAngle);
    Matrix_Mult(&mtx, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_Scale(0.05f, 0.05f, 0.05f, MTXMODE_APPLY);

    OPEN_DISPS(gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
    Gfx_SetupDL25_Xlu(gfxCtx);
    gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_ZB_XLU_DECAL2);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, this->rAlpha);

    if (this->rTexIndex < ARRAY_COUNT(sSlidingTextures)) {
        {
            TexturePtr tex = sSlidingTextures[this->rTexIndex];

            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(tex));
        }
        this->rTexIndex++;
        this->rScroll += this->rScrollStep;
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffPoppedDekuBubbleSliding12Tex));
        if ((this->rScrollStep >= 2) && ((play->state.frames % 2) == 0)) {
            this->rScrollStep--;
        }
        this->rScroll += this->rScrollStep;
    }
    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, this->rScroll, 0x20, 0x20));
    gSPDisplayList(POLY_XLU_DISP++, gEffPoppedDekuBubbleSlidingDL);

    CLOSE_DISPS(gfxCtx);
}
