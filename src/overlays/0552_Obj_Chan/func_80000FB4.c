// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_DrawPot(Actor* thisx, PlayState* play) {
    ObjChan* this = (ObjChan*)thisx;
    s32 pad;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = Gfx_SetupDL(POLY_OPA_DISP, SETUPDL_25);
    MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);
    gSPDisplayList(&gfx[1], gChandelierPotDL);
    POLY_OPA_DISP = &gfx[2];

    CLOSE_DISPS(play->state.gfxCtx);

    if (this->stateFlags & OBJCHAN_STATE_ON_FIRE) {
        ObjChan_DrawFire(this, play);
    }
}
