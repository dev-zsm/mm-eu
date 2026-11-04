// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Counterweight_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    u32 gameplayFrames = play->gameplayFrames;
    ObjTokeidai* this = (ObjTokeidai*)thisx;

    Matrix_RotateYS(-this->actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_Translate(0.0f, this->yTranslation, 0.0f, MTXMODE_APPLY);
    Matrix_Translate(0.0f, -5480.0f, 80.0f, MTXMODE_APPLY);
    Matrix_RotateXS(-this->xRotation, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 5480.0f, -80.0f, MTXMODE_APPLY);
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_APPLY);

    OPEN_DISPS(play->state.gfxCtx);

    
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, -gameplayFrames, 0, 0x20, 0x20));

    
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, this->opaDList);

    
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 255, 255, 235, 180, (s32)(this->spotlightIntensity * 2.55f));
    gSPDisplayList(POLY_XLU_DISP++, this->xluDList);

    CLOSE_DISPS(play->state.gfxCtx);
}
