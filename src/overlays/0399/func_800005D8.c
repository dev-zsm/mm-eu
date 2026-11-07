// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void EnDoorEtc_Draw(Actor* thisx, PlayState* play) {
    EnDoorEtc* this = (EnDoorEtc*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Matrix_Translate(-2900.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    Matrix_RotateZS(this->angle, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gDoorLeftDL);
    gSPDisplayList(POLY_OPA_DISP++, gDoorRightDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
