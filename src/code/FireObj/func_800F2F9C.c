// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fireobj_ctx.h"

void FireObj_Draw(PlayState* play, FireObj* fire) {
    s32 pad;
    FireObjColors* fireColors = &sFireObjColors[fire->colorsIndex];

    if (fire->state != FIRE_STATE_NOT_LIT) {
        Vec3s vec;

        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, (fire->timer * -20) % 512U, 32, 128));

        gDPSetPrimColor(POLY_XLU_DISP++, 0, fireColors->lod, fireColors->primColor.r, fireColors->primColor.g,
                        fireColors->primColor.b, fireColors->primColor.a);

        gDPSetEnvColor(POLY_XLU_DISP++, fireColors->envColor.r, fireColors->envColor.g, fireColors->envColor.b, 0);

        vec.x = 0;
        vec.y = Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000;
        vec.z = 0;
        Matrix_SetTranslateRotateYXZ(fire->position.x, fire->position.y, fire->position.z, &vec);
        Matrix_Scale(fire->xScale, fire->yScale, 1.0f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
