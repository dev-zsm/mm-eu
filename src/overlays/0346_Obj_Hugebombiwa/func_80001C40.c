// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ObjHugebombiwa_Draw(Actor* thisx, PlayState* play) {
    ObjHugebombiwa* this = (ObjHugebombiwa*)thisx;
    s32 pad[8];
    f32 sp38;

    OPEN_DISPS(play->state.gfxCtx);

    if ((this->actionFunc == ref_func_80A54C04) || (this->actionFunc == ref_func_80A54CEC)) {
        if (this->actor.projectedPos.z <= 4300.0f) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);

            gSPSegment(POLY_OPA_DISP++, 0x08, gActorSetupOpaDL);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0xFF, 255, 255, 255, 255);
            gSPDisplayList(POLY_OPA_DISP++, object_bombiwa_DL_002F60);

            Gfx_SetupDL25_Xlu(play->state.gfxCtx);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_bombiwa_DL_003110);

        } else if (this->actor.projectedPos.z < 4500.0f) {
            sp38 = (4500.0f - this->actor.projectedPos.z) * 1.275f;
            Gfx_SetupDL25_Xlu(play->state.gfxCtx);

            gSPSegment(POLY_XLU_DISP++, 0x08, gActorSetupXluDL);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0xFF, 255, 255, 255, (s32)sp38);
            gSPDisplayList(POLY_XLU_DISP++, object_bombiwa_DL_002F60);
        }
    } else {
        s32 i;
        EnHugebombiwaStruct* ptr;
        Gfx* gfx = POLY_OPA_DISP;

        gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);

        for (i = 0; i < ARRAY_COUNT(this->unk_190); i++) {
            ptr = &this->unk_190[i];

            if (ptr->unk_24 == 0) {
                Matrix_SetTranslateRotateYXZ(ptr->unk_0C.x, ptr->unk_0C.y, ptr->unk_0C.z, &ptr->unk_1C);
                Matrix_Scale(ptr->unk_00.x, ptr->unk_00.x, ptr->unk_00.x, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
                gSPDisplayList(gfx++, object_bombiwa_DL_001990);
            }
        }

        POLY_OPA_DISP = gfx;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
