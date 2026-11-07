// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void EnTest_Draw(Actor* thisx, PlayState* play) {
    EnTest* this = (EnTest*)thisx;
    Mtx* mtxStack;
    s32 sp2C = this->unk_208 - 1;

    if (sp2C >= 29) {
        sp2C = 29;
    }

    
    if ((this->surfaceMaterial == SURFACE_MATERIAL_MAX) || (this->surfaceMaterial == SURFACE_MATERIAL_SNOW)) {
        AnimatedMat_DrawStep(play, Lib_SegmentedToVirtual(gameplay_keep_Matanimheader_06B730), sp2C);
    } else {
        AnimatedMat_DrawStep(play, Lib_SegmentedToVirtual(gameplay_keep_Matanimheader_06B6A0), sp2C);
    }

    mtxStack = GRAPH_ALLOC(play->state.gfxCtx, this->kfSkelAnime.skeleton->dListCount * sizeof(Mtx));

    if (mtxStack != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Keyframe_DrawFlex(play, &this->kfSkelAnime, mtxStack, EnTest_OverrideLimbDraw, NULL, thisx);
        ref_func_80863048(play, this->unk_20C);
    }
}
