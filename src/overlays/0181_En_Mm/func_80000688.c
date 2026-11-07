// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void EnMm_Draw(Actor* thisx, PlayState* play) {
    EnMm* this = (EnMm*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    if (this->unk_190 != 0) {
        s16 rotY = this->actor.world.rot.y - this->actor.shape.rot.y;

        Matrix_RotateYS(rotY, MTXMODE_APPLY);
        Matrix_RotateXS(this->unk_190, MTXMODE_APPLY);
        Matrix_RotateYS(-rotY, MTXMODE_APPLY);
    }
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gameplay_keep_DL_055628);

    CLOSE_DISPS(play->state.gfxCtx);
}
