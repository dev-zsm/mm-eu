// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_solder_srch_ball.h"

void EffectSsSolderSrchBall_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    f32 scale = this->rgScale / 100.0f;

    Gfx_SetupDL25_Opa(gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    OPEN_DISPS(gfxCtx);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);
    gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gSun1Tex));
    gSPDisplayList(POLY_XLU_DISP++, gSunSparkleMaterialDL);
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 250, 180, 255, 255);
    Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
    Matrix_RotateZF(DEG_TO_RAD(20.0f * play->state.frames), MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gSunSparkleModelDL);

    CLOSE_DISPS(gfxCtx);
}
