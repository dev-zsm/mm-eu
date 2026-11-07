// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_part.h"

void EnPart_Draw(Actor* thisx, PlayState* play) {
    EnPart* this = (EnPart*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->actor.params > ENPART_TYPE_0) {
        Matrix_RotateZF(this->zRot, MTXMODE_APPLY);
    }
    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    ref_func_800B8050(&this->actor, play, 0);
    if (this->actor.params == ENPART_TYPE_15) {
        gSPSegment(POLY_OPA_DISP++, 0x0C, gEmptyDL);
    }
    if (this->dList != NULL) {
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, this->dList);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
