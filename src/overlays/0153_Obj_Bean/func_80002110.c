// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80938E00(Actor* thisx, PlayState* play) {
    ObjBean* this = (ObjBean*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

    if (this->unk_1FE & 4) {
        gSPDisplayList(POLY_OPA_DISP++, object_mamenoki_DL_000090);
    }

    if (this->unk_1FE & 2) {
        gSPDisplayList(POLY_OPA_DISP++, object_mamenoki_DL_0002D0);
    }

    if (this->unk_1FE & 1) {
        Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                     this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
        Matrix_Scale(this->unk_1B8, this->unk_1B8, this->unk_1B8, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_mamenoki_DL_000530);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
