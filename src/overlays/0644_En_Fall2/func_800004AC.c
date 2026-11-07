// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall2.h"

void EnFall2_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnFall2* this = (EnFall2*)thisx;
    Mtx* mtxStack;

    if (!(this->alphaLevel <= 0.0f)) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        AnimatedMat_DrawXlu(play, Lib_SegmentedToVirtual(object_fall2_Matanimheader_008840));

        mtxStack = GRAPH_ALLOC(play->state.gfxCtx, this->kfSkelAnime.skeleton->dListCount * sizeof(Mtx));

        if (mtxStack != NULL) {
            Gfx_SetupDL25_Xlu(play->state.gfxCtx);
            Matrix_RotateYS((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000), MTXMODE_APPLY);
            Keyframe_DrawFlex(play, &this->kfSkelAnime, mtxStack, NULL, NULL, &this->actor);
        }
    }
}
