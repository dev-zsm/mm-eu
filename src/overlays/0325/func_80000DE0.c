// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ref_func_80A3D2C0(Actor* thisx, PlayState* play) {
    ObjVspinyroll* this = (ObjVspinyroll*)thisx;
    Vec3s sp3C;

    OPEN_DISPS(play->state.gfxCtx);

    sp3C.x = this->dyna.actor.shape.rot.x + this->unk_3C6;
    sp3C.y = this->dyna.actor.shape.rot.y;
    sp3C.z = this->dyna.actor.shape.rot.z + 0x4000;

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y + 60.0f, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(sp3C.y, MTXMODE_APPLY);
    Matrix_RotateZS(sp3C.z, MTXMODE_APPLY);
    Matrix_RotateXS(sp3C.x, MTXMODE_APPLY);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_spinyroll_DL_000460);

    ref_func_80A3CC84(120.0f);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_spinyroll_DL_000460);

    CLOSE_DISPS(play->state.gfxCtx);
}
