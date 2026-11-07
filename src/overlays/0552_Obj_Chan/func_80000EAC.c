// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjChan* this = (ObjChan*)thisx;
    Gfx* gfxOpa;
    Gfx* gfxXlu;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_RotateYS(this->rotation, MTXMODE_APPLY);

    gfxOpa = Gfx_SetupDL(POLY_OPA_DISP, SETUPDL_25);
    MATRIX_FINALIZE_AND_LOAD(&gfxOpa[0], play->state.gfxCtx);
    gSPDisplayList(&gfxOpa[1], gChandelierCenterDL);
    POLY_OPA_DISP = &gfxOpa[2];

    gfxXlu = Gfx_SetupDL71(POLY_XLU_DISP);
    MATRIX_FINALIZE_AND_LOAD(&gfxXlu[0], play->state.gfxCtx);
    gSPDisplayList(&gfxXlu[1], gChandelierPotHolderDL);
    POLY_XLU_DISP = &gfxXlu[2];

    CLOSE_DISPS(play->state.gfxCtx);

    Matrix_Push();
    if (this->stateFlags & OBJCHAN_STATE_ON_FIRE) {
        ObjChan_DrawFire(this, play);
    }
    Matrix_Pop();
}
