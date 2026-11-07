// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_DrawFire(ObjChan* this, PlayState* play) {
    u32 sp4C;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    sp4C = play->gameplayFrames;

    Matrix_RotateYS(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) - this->actor.shape.rot.y - this->rotation + 0x8000,
                    MTXMODE_APPLY);
    Matrix_Scale(sObjChanFlameSize[OBJCHAN_SUBTYPE(&this->actor)].x * this->flameSize,
                 sObjChanFlameSize[OBJCHAN_SUBTYPE(&this->actor)].y * this->flameSize, 1.0f, MTXMODE_APPLY);
    Matrix_Translate(0.0f, sObjChanFlameYOffset[OBJCHAN_SUBTYPE(&this->actor)], 0.0f, MTXMODE_APPLY);

    gfx = Gfx_SetupDL71(POLY_XLU_DISP);
    MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);
    gSPSegment(&gfx[1], 0x08, Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, -sp4C * 20, 32, 128));
    gDPSetPrimColor(&gfx[2], 128, 128, 255, 255, 0, 255);
    gDPSetEnvColor(&gfx[3], 255, 0, 0, 0);
    gSPDisplayList(&gfx[4], gEffFire1DL);
    POLY_XLU_DISP = &gfx[5];

    CLOSE_DISPS(play->state.gfxCtx);
}
