// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void ref_func_80863048(PlayState* play, EnTestStruct* arg1) {
    EnTestStruct* ptr;
    s32 i;
    Mtx* mtx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);

    for (i = 0; i < 20; i++) {
        ptr = &arg1[i];

        if (!ptr->unk_00) {
            continue;
        }

        Matrix_Translate(ptr->unk_08.x, ptr->unk_08.y, ptr->unk_08.z, MTXMODE_NEW);
        Matrix_RotateZYX(ptr->unk_30.x, ptr->unk_30.y, ptr->unk_30.z, MTXMODE_APPLY);
        Matrix_Scale(ptr->unk_2C, ptr->unk_2C, ptr->unk_2C, MTXMODE_APPLY);

        mtx = Matrix_Finalize(play->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gameplay_keep_DL_06AB30);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
