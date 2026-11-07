// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_ice.h"

void EffectSsEnIce_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    s32 pad;
    f32 scale = this->rScale * 0.01f;
    u32 gameplayFrames = play->gameplayFrames;
    f32 alpha;

    OPEN_DISPS(gfxCtx);

    if (this->rAlphaMode != 0) {
        alpha = this->life * 12.0f;
    } else if ((this->rLifespan > 0) && (this->life < (this->rLifespan >> 1))) {
        alpha = (this->life * 2.0f) / this->rLifespan;
        alpha *= 255.0f;
    } else {
        alpha = 255.0f;
    }

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Matrix_RotateYS(this->rYaw, MTXMODE_APPLY);
    Matrix_RotateXS(this->rPitch, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    ref_func_800BCC68(&this->pos, play);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, gameplayFrames & 0xFF, 0x20, 0x10, 1, 0,
                                (gameplayFrames * 2) & 0xFF, 0x40, 0x20));
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, this->rPrimColorR, this->rPrimColorG, this->rPrimColorB,
                    this->rPrimColorA);
    gDPSetEnvColor(POLY_XLU_DISP++, this->rEnvColorR, this->rEnvColorG, this->rEnvColorB, (u32)alpha);
    gSPDisplayList(POLY_XLU_DISP++, gEffIceFragment2MaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, gEffIceFragment2ModelDL);

    CLOSE_DISPS(gfxCtx);
}
