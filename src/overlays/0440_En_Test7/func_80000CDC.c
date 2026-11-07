// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_DrawFeathers(PlayState* play2, OwlWarpFeather* feathers) {
    PlayState* play = play2;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL26_Opa(play->state.gfxCtx);

    Matrix_Push();

    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);

    for (i = 0; i < OWL_WARP_NUM_FEATHERS; i++) {
        Mtx* mtx;
        MtxF sp6C;
        OwlWarpFeather* feather = &feathers[i];

        if (feather->type == OWL_WARP_FEATHER_TYPE_DISABLED) {
            continue;
        }

        if ((feather->pos.x > 30000.0f) || (feather->pos.x < -30000.0f) || (feather->pos.y > 30000.0f) ||
            (feather->pos.y < -30000.0f) || (feather->pos.z > 30000.0f) || (feather->pos.z < -30000.0f)) {
            feather->type = OWL_WARP_FEATHER_TYPE_DISABLED;
            continue;
        }

        Matrix_Translate(feather->pos.x, feather->pos.y, feather->pos.z, MTXMODE_NEW);

        if (feather->type == OWL_WARP_FEATHER_TYPE_1) {
            Matrix_RotateZYX(feather->rot.x, feather->rot.y, feather->rot.z, MTXMODE_APPLY);
        } else {
            SkinMatrix_SetRotateYRP(&sp6C, feather->rot.x, feather->rot.y, feather->rot.z);
            Matrix_Mult(&sp6C, MTXMODE_APPLY);
        }

        Matrix_Scale(feather->scale, feather->scale, feather->scale, MTXMODE_APPLY);
        if (feather->type == OWL_WARP_FEATHER_TYPE_2) {
            Matrix_Translate(0.0f, 30.0f, 0.0f, MTXMODE_APPLY);
        }

        mtx = Matrix_Finalize(play->state.gfxCtx);
        if (mtx == NULL) {
            continue;
        }
        gSPMatrix(POLY_OPA_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gSoaringWarpCsFeatherDL);
    }

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);
}
