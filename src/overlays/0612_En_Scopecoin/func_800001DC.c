// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_scopecoin.h"

void EnScopecoin_Draw(Actor* thisx, PlayState* play) {
    EnScopecoin* this = (EnScopecoin*)thisx;
    GraphicsContext* gfxCtx = play->state.gfxCtx;

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    ref_func_800B8050(&this->actor, play, 0);

    OPEN_DISPS(gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sRupeeTextures[this->rupeeIndex]));
    gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);

    CLOSE_DISPS(gfxCtx);
}
