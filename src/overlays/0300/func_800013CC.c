// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ObjSpinyroll_Draw(Actor* thisx, PlayState* play) {
    ObjSpinyroll* this = (ObjSpinyroll*)thisx;
    f32 temp_f26;
    f32 temp_f28;
    s32 temp_s1 = OBJSPINYROLL_GET_C000(&this->dyna.actor);
    s32 phi_s4;
    f32 phi_f22;
    f32 phi_f24;
    s32 i;
    f32 temp_f30;
    Vec3s sp84;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    temp_f26 = Math_CosS(this->dyna.actor.shape.rot.y) * 120.0f;
    temp_f28 = Math_SinS(this->dyna.actor.shape.rot.y) * -120.0f;
    temp_f30 = this->dyna.actor.world.pos.y + this->unk_4D0;

    if (temp_s1 == OBJSPINYROLL_GET_C000_0) {
        phi_s4 = 1;
        phi_f22 = this->dyna.actor.world.pos.x;
        phi_f24 = this->dyna.actor.world.pos.z;
    } else if (temp_s1 == OBJSPINYROLL_GET_C000_1) {
        phi_s4 = 2;
        phi_f22 = this->dyna.actor.world.pos.x - (temp_f26 * 0.5f);
        phi_f24 = this->dyna.actor.world.pos.z - (temp_f28 * 0.5f);
    } else {
        phi_s4 = 4;
        phi_f22 = this->dyna.actor.world.pos.x - (temp_f26 * 1.5f);
        phi_f24 = this->dyna.actor.world.pos.z - (temp_f28 * 1.5f);
    }

    sp84.x = this->dyna.actor.shape.rot.x + this->unk_4E0;
    sp84.y = this->dyna.actor.shape.rot.y;
    sp84.z = this->dyna.actor.shape.rot.z;

    for (i = 0; i < phi_s4; i++) {
        Matrix_SetTranslateRotateYXZ(phi_f22, temp_f30, phi_f24, &sp84);
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_spinyroll_DL_000460);

        phi_f22 += temp_f26;
        phi_f24 += temp_f28;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
