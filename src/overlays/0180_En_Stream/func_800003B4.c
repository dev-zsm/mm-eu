// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_stream.h"

void EnStream_Draw(Actor* thisx, PlayState* play) {
    u32 multipliedFrames;
    u32 frames = play->gameplayFrames;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    gfx = POLY_XLU_DISP;
    MATRIX_FINALIZE_AND_LOAD(&gfx[0], play->state.gfxCtx);
    multipliedFrames = frames * 20;
    gSPSegment(&gfx[1], 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, frames * 30, -multipliedFrames, 64, 64, 1, multipliedFrames,
                                -multipliedFrames, 64, 64));
    gSPDisplayList(&gfx[2], gWaterVortexDL);
    POLY_XLU_DISP = &gfx[3];

    CLOSE_DISPS(play->state.gfxCtx);
}
