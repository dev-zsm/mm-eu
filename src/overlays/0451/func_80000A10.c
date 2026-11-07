// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void ref_func_80AFE650(Actor* thisx, PlayState* play) {
    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    OPEN_DISPS(play->state.gfxCtx);

    POLY_OPA_DISP = Play_SetFog(play, POLY_OPA_DISP);
    POLY_OPA_DISP = Gfx_SetupDL66(POLY_OPA_DISP);
    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(gDropBombTex));
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gItemDropDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
