// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_moonend.h"

void DemoMoonend_Draw(Actor* thisx, PlayState* play) {
    DemoMoonend* this = (DemoMoonend*)thisx;
    Mtx* mtxStack;

    AnimatedMat_Draw(play, (AnimatedMaterial*)Lib_SegmentedToVirtual(object_moonend_Matanimheader_00B540));

    mtxStack = GRAPH_ALLOC(play->state.gfxCtx, this->kfSkelAnime.skeleton->dListCount * sizeof(Mtx));

    if (mtxStack != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        Keyframe_DrawFlex(play, &this->kfSkelAnime, mtxStack, DemoMoonend_OverrideLimbDraw, DemoMoonend_PostLimbDraw,
                          &this->actor);
    }
}
