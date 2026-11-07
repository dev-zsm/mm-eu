// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ObjAqua_Draw(Actor* thisx, PlayState* play) {
    ObjAqua* this = (ObjAqua*)thisx;
    s32 framesTemp;
    s32 pad;
    s16 yaw = Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000;
    s32 actionFuncTemp = this->actionFunc == ref_func_80ACBDFC;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    framesTemp = ((play->gameplayFrames & 0x7FFFFFFF) * -0xA) & 0x1FF;
    if (actionFuncTemp) {
        framesTemp >>= 1;
    }
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, framesTemp, 0x20, 0x80));
    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 170, 255, 255, this->alpha);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 150, 255, 0);
    if (actionFuncTemp) {
        s16 rotation = Math_SinS(this->unk_198) * 8000.0f;

        Matrix_RotateZS(rotation, MTXMODE_APPLY);
        Matrix_Scale(1.3f, 1.0f, 1.0f, MTXMODE_APPLY);
        Matrix_RotateZS(rotation * -1, MTXMODE_APPLY);
        Matrix_Scale(10.0f / 13.0f, 1.0f, 1.0f, MTXMODE_APPLY);
    }

    Matrix_RotateYS(yaw, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);

    CLOSE_DISPS(play->state.gfxCtx);
}
