// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_zoraband.h"

void EffZoraband_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EffZoraband* this = (EffZoraband*)thisx;

    if (this->alpha != 0) {
        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_RotateYS((Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000), MTXMODE_APPLY);
        AnimatedMat_DrawXlu(play, Lib_SegmentedToVirtual(object_zoraband_Matanimheader_000F38));
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        if (this->actor.home.rot.z != 0) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 100, this->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 200, 0, 255);
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 0, 100, 255, this->alpha);
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 100, 255);
        }
        gSPDisplayList(POLY_XLU_DISP++, object_zoraband_DL_000180);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0xFF, 200, 255, 255, this->alpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, 255);
        gSPDisplayList(POLY_XLU_DISP++, object_zoraband_DL_0002A8);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
