// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_estone.h"

void EnEstone_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnEstone* this = (EnEstone*)thisx;

    if (this->inactive != true) {
        Matrix_Push();

        OPEN_DISPS(play->state.gfxCtx);

        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_RotateXFApply(DEG_TO_RAD(this->rot.x));
        Matrix_RotateYF(DEG_TO_RAD(this->rot.y), MTXMODE_APPLY);
        Matrix_RotateZF(DEG_TO_RAD(this->rot.z), MTXMODE_APPLY);
        Matrix_Scale(this->scale, this->scale, this->scale, MTXMODE_APPLY);
        Matrix_Translate(0.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, 255, 255, 255, 255);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gEyegoreStoneDL);

        CLOSE_DISPS(play->state.gfxCtx);

        Matrix_Pop();
    }
    EnEstone_DrawEffects(this, play);
}
