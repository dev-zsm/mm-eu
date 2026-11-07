// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gWarpTagRainbowTexAnim));
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

    gSPDisplayList(POLY_OPA_DISP++, gWarpTagGoronTrialBaseDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
