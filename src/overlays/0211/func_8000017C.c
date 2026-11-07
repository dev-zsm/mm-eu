// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_sibuki.h"

void EffectSsSibuki_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    f32 scale = this->rScale / 100.0f;

    OPEN_DISPS(gfxCtx);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, gfxCtx);
    Gfx_SetupDL25_Opa(gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB, this->rPrimColorA);
    gDPSetEnvColor(POLY_OPA_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, this->rEnvColorA);
    gSPSegment(POLY_OPA_DISP++, 0x08, this->gfx);
    gSPDisplayList(POLY_OPA_DISP++, gEffBubbleDL);

    CLOSE_DISPS(gfxCtx);
}
