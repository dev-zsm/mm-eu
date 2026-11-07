// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kinoko.h"

void ObjKinoko_Draw(Actor* thisx, PlayState* play) {
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gfx = POLY_XLU_DISP;
    gDPSetPrimColor(&gfx[0], 0, 0, 169, 63, 186, (u8)thisx->speed);
    gDPSetEnvColor(&gfx[1], 110, 44, 200, 100);
    gDPSetRenderMode(&gfx[2], G_RM_PASS, G_RM_ZB_CLD_SURF2);
    MATRIX_FINALIZE_AND_LOAD(&gfx[3], play->state.gfxCtx);
    gSPDisplayList(&gfx[4], &gameplay_keep_DL_029D10[2]);
    Matrix_RotateXS(-0x4000, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(&gfx[5], play->state.gfxCtx);
    gSPDisplayList(&gfx[6], &gameplay_keep_DL_029D10[2]);
    POLY_XLU_DISP = &gfx[7];

    CLOSE_DISPS(play->state.gfxCtx);
}
