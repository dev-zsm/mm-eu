// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_funen.h"

void ObjFunen_Draw(Actor* thisx, PlayState* play) {
    s32 temp;
    s32 pad[2];

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_RotateYS((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) - 0x8000), MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    temp = -(play->gameplayFrames & 0x7FFFFFFF) & 0x7F;

    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, temp, 0x20, 0x20, 1, 0, temp, 0x20, 0x20));
    gSPDisplayList(POLY_XLU_DISP++, gStoneTowerSmokeDL);
    CLOSE_DISPS(play->state.gfxCtx);
}
