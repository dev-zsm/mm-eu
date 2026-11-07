// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wiz_brock.h"

void EnWizBrock_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnWizBrock* this = (EnWizBrock*)thisx;

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_Scale(this->dyna.actor.scale.x, this->dyna.actor.scale.y, this->dyna.actor.scale.z, MTXMODE_APPLY);
    if (this->dyna.actor.colChkInfo.health != 0) {
        Scene_SetRenderModeXlu(play, 0, 1);
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        Gfx_DrawDListOpa(play, gWizrobePlatformDL);

    } else {
        Scene_SetRenderModeXlu(play, 1, 2);
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, TRUNCF_BINANG(this->alpha));
        Gfx_DrawDListXlu(play, gWizrobePlatformDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);

    if (this->platformType != EN_WIZ_BROCK_PLATFORM_TYPE_INACTIVE) {
        OPEN_DISPS(play->state.gfxCtx);

        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gWizrobePlatformCenterTexAnim));
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, 255);
        if (this->platformType == EN_WIZ_BROCK_PLATFORM_TYPE_FIRE) {
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 00, 100, TRUNCF_BINANG(this->alpha));
        } else {
            gDPSetEnvColor(POLY_XLU_DISP++, 50, 00, 255, TRUNCF_BINANG(this->alpha));
        }

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, &gWizrobePlatformCenterDL);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
