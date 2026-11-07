// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_jc_mato.h"

void EnJcMato_Draw(Actor* thisx, PlayState* play) {
    static Vec3f sOffset = { 0.0f, -2500.0f, 0.0f };
    EnJcMato* this = (EnJcMato*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gKoumeTargetDL);
    Matrix_MultVec3f(&sOffset, &this->pos);

    CLOSE_DISPS(play->state.gfxCtx);
}
