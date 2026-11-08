// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sbn.h"

void EffectSsSbn_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    MtxF mtx;
    f32 scale = this->rScale * 0.001f;

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

    if (this->rTexIndex < ARRAY_COUNT(sTextures)) {
        {
            TexturePtr tex = sTextures[this->rTexIndex];

            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(tex));
        }
        this->rTexIndex++;
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffPoppedDekuBubble5Tex));
    }
    gSPDisplayList(POLY_XLU_DISP++, gEffPoppedDekuBubbleDL);

    CLOSE_DISPS(gfxCtx);
}
