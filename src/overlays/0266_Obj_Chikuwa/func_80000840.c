// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ObjChikuwa_Draw(Actor* thisx, PlayState* play) {
    ObjChikuwa* this = (ObjChikuwa*)thisx;
    ObjChikuwaStruct* temp;
    ObjChikuwaStruct2* temp2;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->unk_2A0 < this->unk_29C) {
        for (i = 0; i < this->unk_29C; i++) {
            temp = &this->unk_15C[i];
            if (!(temp->unk_0E & 1)) {
                Matrix_SetTranslateRotateYXZ(temp->unk_00.x, temp->unk_00.y, temp->unk_00.z,
                                             &this->dyna.actor.shape.rot);
                Matrix_Scale(0.15f, 0.2f, 0.05f, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, gDampeGraveBrownElevatorDL);
            }
        }
    }

    if (this->unk_9A6 != 0) {
        for (i = 0; i < ARRAY_COUNT(this->unk_2A4); i++) {
            temp2 = &this->unk_2A4[i];
            if (temp2->unk_34 > 0) {
                Matrix_SetTranslateRotateYXZ(temp2->unk_0C.x, temp2->unk_0C.y, temp2->unk_0C.z, &temp2->unk_28);
                Matrix_Scale(temp2->unk_00.x, temp2->unk_00.y, temp2->unk_00.z, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, gDampeGraveBrownElevatorDL);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
