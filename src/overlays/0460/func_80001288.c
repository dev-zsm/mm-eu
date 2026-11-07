// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B13C08(Actor* thisx, PlayState* play) {
    ObjDhouse* this = (ObjDhouse*)thisx;
    ObjDhouseStruct1* ptr;
    ObjDhouseStruct2* ptr2;
    ObjDhouseStruct3* ptr3;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, object_dhouse_DL_004928);

    for (i = 0, ptr = &this->unk_160[0], ptr3 = &ref_D_80B13E90[0]; i < ARRAY_COUNT(this->unk_160); i++, ptr3++, ptr++) {
        if (ptr->unk_1E >= 0) {
            Matrix_SetTranslateRotateYXZ(ptr->unk_00.x + ptr3->unk_08.x, ptr->unk_00.y + ptr3->unk_08.y,
                                         ptr->unk_00.z + ptr3->unk_08.z, &ptr->unk_18);
            Matrix_Translate(-ptr3->unk_08.x, -ptr3->unk_08.y, -ptr3->unk_08.z, MTXMODE_APPLY);
            Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, ptr3->unk_00);
            gSPDisplayList(POLY_OPA_DISP++, ptr3->unk_04);
        }
    }

    for (i = 0, ptr2 = &this->unk_240[0]; i < ARRAY_COUNT(this->unk_240); i++, ptr2++) {
        if (ptr2->unk_28 > 0) {
            Matrix_SetTranslateRotateYXZ(ptr2->unk_00.x, ptr2->unk_00.y, ptr2->unk_00.z, &ptr2->unk_1C);
            Matrix_Scale(ptr2->unk_18, ptr2->unk_18, ptr2->unk_18, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, object_dhouse_DL_0081D8);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
