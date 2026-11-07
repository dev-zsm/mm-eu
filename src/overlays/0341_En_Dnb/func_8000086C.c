// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void ref_func_80A5063C(EnDnb* this, PlayState* play) {
    s32 i;
    Gfx** dLists = Lib_SegmentedToVirtual(object_hanareyama_obj_DLArray_004638);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(this->effects); i++) {
        Matrix_Push();
        Matrix_Translate(this->effects[i].unk_0C.x, this->effects[i].unk_0C.y, this->effects[i].unk_0C.z, MTXMODE_NEW);
        Matrix_RotateXS(this->effects[i].unk_18.x, MTXMODE_APPLY);
        Matrix_RotateYS(this->effects[i].unk_18.y, MTXMODE_APPLY);
        Matrix_RotateZS(this->effects[i].unk_18.z, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, dLists[i]);

        Matrix_Pop();
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
