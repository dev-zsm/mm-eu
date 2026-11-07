// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A55B34(Actor* thisx, PlayState* play) {
    ObjHugebombiwa* this = (ObjHugebombiwa*)thisx;
    s32 i;
    Gfx* gfx;
    EnHugebombiwaStruct* ptr;

    if ((this->actionFunc == ref_func_80A54C04) || (this->actionFunc == ref_func_80A54CEC)) {
        Gfx_DrawDListOpa(play, object_bombiwa_DL_001820);
        return;
    }

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_OPA_DISP;

    gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);

    for (i = 0; i < ARRAY_COUNT(this->unk_190); i++) {
        ptr = &this->unk_190[i];

        if (ptr->unk_24 != 0) {
            continue;
        }

        Matrix_SetTranslateRotateYXZ(ptr->unk_0C.x, ptr->unk_0C.y + (325.0f * ptr->unk_00.y), ptr->unk_0C.z,
                                     &ptr->unk_1C);
        Matrix_Scale(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, MTXMODE_APPLY);
        Matrix_Translate(0.0f, -325.0f, 0.0f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gSPDisplayList(gfx++, object_bombiwa_DL_0009E0);
    }

    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(play->state.gfxCtx);
}
