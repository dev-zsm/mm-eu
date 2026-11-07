// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Clock_Draw(Actor* thisx, PlayState* play) {
    ObjTokeidai* this = (ObjTokeidai*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Matrix_Translate(0.0f, this->yTranslation, 0.0f, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, -1791.0f, MTXMODE_APPLY);
    Matrix_RotateXS(-this->xRotation, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, 1791.0f, MTXMODE_APPLY);

    Matrix_Push();
    Matrix_RotateZS(-this->minuteRingOrExteriorGearRotation, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gClockTowerMinuteRingDL);
    Matrix_Pop();

    Matrix_Translate(0.0f, 0.0f, this->clockFaceZTranslation, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gClockTowerClockCenterAndHandDL);

    Matrix_RotateZS(-this->clockFaceRotation * 2, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    if (OBJ_TOKEIDAI_TYPE(&this->actor) == OBJ_TOKEIDAI_TYPE_WALL_CLOCK ||
        OBJ_TOKEIDAI_TYPE(&this->actor) == OBJ_TOKEIDAI_TYPE_SMALL_WALL_CLOCK) {
        gSPDisplayList(POLY_OPA_DISP++, gWallClockClockFaceDL);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, gClockTowerClockFaceDL);
    }

    Matrix_Translate(0.0f, -1112.0f, -19.6f, MTXMODE_APPLY);
    Matrix_RotateYS(this->sunMoonPanelRotation, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gClockTowerSunAndMoonPanelDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
