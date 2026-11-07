// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dora.h"

void ObjDora_Draw(Actor* thisx, PlayState* play) {
    static Vec3f sPos = { 0.0f, -61.5f, 0.0f };
    ObjDora* this = (ObjDora*)thisx;
    f32 gongForceX;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->actionFunc == ObjDora_MoveGong) {
        gongForceX = this->gongForce.x;
        if ((play->state.frames % 2) != 0) {
            gongForceX *= -1.0f;
        }

        Matrix_Push();
        Matrix_RotateXS(this->gongRotation.x, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, &gDoraChainDL);

        Matrix_Translate(sPos.x, sPos.y + gongForceX, sPos.z + gongForceX, MTXMODE_APPLY);
        Matrix_RotateXS(this->gongRotation.z - this->gongRotation.x, MTXMODE_APPLY);
        Matrix_Translate(-sPos.x, -sPos.y, -sPos.z, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, &gDoraGongDL);

        Matrix_Pop();
    } else {
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, &gDoraGongDL);
        gSPDisplayList(POLY_OPA_DISP++, &gDoraChainDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
