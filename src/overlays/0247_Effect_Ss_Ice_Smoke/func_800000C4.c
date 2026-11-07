// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_ice_smoke.h"

void EffectSsIceSmoke_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    Mtx* mtx;
    f32 scale;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 235, 235, this->rAlpha);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, this->rScrollX * this->life, this->rScrollY * this->life, 0x20,
                                0x40, 1, 0, 0, 0x20, 0x20));
    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_ReplaceRotation(&play->billboardMtxF);
    scale = this->rScale * 0.0001f;
    Matrix_Scale(scale, scale, 1.0f, MTXMODE_APPLY);
    mtx = Matrix_Finalize(play->state.gfxCtx);
    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gEffIceSmokeDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
