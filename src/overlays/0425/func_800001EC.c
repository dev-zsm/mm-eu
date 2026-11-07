// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_fu_mizu.h"

void BgFuMizu_Draw(Actor* thisx, PlayState* play) {
    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_fu_kaiten_Matanimheader_0037D8));

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, object_fu_kaiten_DL_002FC0);

    CLOSE_DISPS(play->state.gfxCtx);
}
