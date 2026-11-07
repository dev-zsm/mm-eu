// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_change.h"

void EffChange_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    Mtx* mtxStack;
    EffChange* this = (EffChange*)thisx;

    AnimatedMat_DrawStepXlu(play, Lib_SegmentedToVirtual(&gameplay_keep_Matanimheader_028FEC), this->step);
    mtxStack = GRAPH_ALLOC(play->state.gfxCtx, this->kfSkelAnime.skeleton->dListCount * sizeof(Mtx));

    if (mtxStack != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_RotateYS((Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000), MTXMODE_APPLY);

        OPEN_DISPS(play->state.gfxCtx);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, this->primColors[0], this->primColors[1], this->primColors[2],
                        this->primColors[3]);
        gDPSetEnvColor(POLY_XLU_DISP++, this->envColors[0], this->envColors[1], this->envColors[2], 255);
        Keyframe_DrawFlex(play, &this->kfSkelAnime, mtxStack, NULL, NULL, &this->actor);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
