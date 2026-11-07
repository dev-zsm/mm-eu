// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_8093A608(Actor* thisx, PlayState* play) {
    s32 pad[8];
    ObjBombiwa* this = (ObjBombiwa*)thisx;
    f32 sp38;
    s32 i;
    ObjBombiwaStruct* ptr;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->actionFunc == ref_func_80939EF4) {
        if ((this->actor.projectedPos.z <= 2200.0f) ||
            ((this->unk_203 & 1) && (this->actor.projectedPos.z < 2300.0f))) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);

            gSPSegment(POLY_OPA_DISP++, 0x08, gActorSetupOpaDL);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x9B, 255, 255, 255, 255);
            gSPDisplayList(POLY_OPA_DISP++, object_bombiwa_DL_004560);

            Gfx_SetupDL25_Xlu(play->state.gfxCtx);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_bombiwa_DL_004688);
        } else if (this->actor.projectedPos.z < 2300.0f) {
            sp38 = (2300.0f - this->actor.projectedPos.z) * 2.55f;
            Gfx_SetupDL25_Xlu(play->state.gfxCtx);

            gSPSegment(POLY_XLU_DISP++, 0x08, gActorSetupXluDL);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x9B, 255, 255, 255, (s32)sp38);
            gSPDisplayList(POLY_XLU_DISP++, object_bombiwa_DL_004560);
        }
    } else {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        for (i = 0; i < ARRAY_COUNT(this->unk_190); i++) {
            ptr = &this->unk_190[i];

            if (ptr->unk_1A == 0) {
                Matrix_SetTranslateRotateYXZ(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, &ptr->unk_14);
                Matrix_Scale(ptr->unk_00, ptr->unk_00, ptr->unk_00, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, object_bombiwa_DL_005990);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
