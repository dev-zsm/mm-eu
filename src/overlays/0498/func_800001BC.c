// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hariko.h"

void ObjHariko_Draw(Actor* thisx, PlayState* play) {
    ObjHariko* this = (ObjHariko*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    Matrix_Push();
    Matrix_RotateXS(this->headRot.x, MTXMODE_APPLY);
    Matrix_RotateYS(this->headRot.y, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gHarikoBodyDL);
    gSPDisplayList(POLY_OPA_DISP++, gHarikoFaceDL);

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);
}
