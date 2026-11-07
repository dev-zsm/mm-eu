// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_ExteriorGear_Draw(Actor* thisx, PlayState* play) {
    ObjTokeidai* this = (ObjTokeidai*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_Translate(0.0f, this->yTranslation, 0.0f, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, -1791.0f, MTXMODE_APPLY);
    Matrix_RotateYS(-this->actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateXS(-this->xRotation, MTXMODE_APPLY);
    Matrix_RotateYS(thisx->shape.rot.y, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, 1791.0f, MTXMODE_APPLY);
    Matrix_RotateZS(this->minuteRingOrExteriorGearRotation, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gClockTowerExteriorGearDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
