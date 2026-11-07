// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_shutter.h"

void ObjShutter_Draw(Actor* thisx, PlayState* play) {
    ObjShutter* this = (ObjShutter*)thisx;

    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y + this->verticalOffset, this->actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Matrix_RotateYS(this->actor.world.rot.y, MTXMODE_APPLY);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gBankShutterDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
