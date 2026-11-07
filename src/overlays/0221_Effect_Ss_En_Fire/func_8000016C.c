// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_en_fire.h"

void EffectSsEnFire_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    f32 scale;
    s16 camYaw;
    s32 pad[3];
    s16 redGreen;

    OPEN_DISPS(gfxCtx);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    camYaw = (Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000);
    Matrix_RotateYS(camYaw, MTXMODE_APPLY);

    scale = Math_SinS(this->life * 0x333) * (this->rScale * 0.00005f);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    redGreen = this->life - 5;

    if (redGreen < 0) {
        redGreen = 0;
    }

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gDPSetEnvColor(POLY_XLU_DISP++, redGreen * 12.7f, 0, 0, 0);
    gDPSetPrimColor(POLY_XLU_DISP++, 0x0, 0x80, redGreen * 12.7f, redGreen * 12.7f, 0, 255);
    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, (this->rScroll * -20) & 0x1FF, 0x20, 0x80));

    if ((this->rFlags & 0x7FFF) || (this->life < 18)) {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire2DL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }

    CLOSE_DISPS(gfxCtx);
}
