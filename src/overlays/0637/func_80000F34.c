// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C173B4(Actor* thisx, PlayState* play) {
    s32 pad;
    DemoSyoten* this = (DemoSyoten*)thisx;
    Mtx* mtxStack;

    AnimatedMat_DrawXlu(play, Lib_SegmentedToVirtual(&object_syoten_Matanimheader_001298));

    mtxStack = GRAPH_ALLOC(play->state.gfxCtx, this->kfSkelAnime.skeleton->dListCount * sizeof(Mtx));

    if (mtxStack != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
        Keyframe_DrawFlex(play, &this->kfSkelAnime, mtxStack, DemoSyoten_OverrideLimbDraw, NULL, &this->actor);
    }
}
