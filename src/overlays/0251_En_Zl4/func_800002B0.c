// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_zl4.h"

void func_800002B0(Actor* thisx, PlayState* play) {
    EnZl4* this = (EnZl4*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->alpha < 255) {
        gSPSegment(POLY_OPA_DISP++, 0x0C, ref_func_809A1DD0(play->state.gfxCtx, this->alpha));
    } else {
        gSPSegment(POLY_OPA_DISP++, 0x0C, ref_func_809A1E28(play->state.gfxCtx, this->alpha));
    }

    SkelAnime_DrawTransformFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
    this->skelAnime.dListCount, EnZl4_OverrideLimbDraw, EnZl4_PostLimbDraw,
    EnZl4_TransformLimbDraw, &this->actor);

    CLOSE_DISPS(play->state.gfxCtx);
}
