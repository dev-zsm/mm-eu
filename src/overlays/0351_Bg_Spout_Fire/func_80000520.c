// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

void BgSpoutFire_Draw(Actor* thisx, PlayState* play) {
    BgSpoutFire* this = (BgSpoutFire*)thisx;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);
    POLY_XLU_DISP = gfx;
    gSPSegment(&gfx[0], 0x08, sFlameTextures[this->flameTexIndex]);
    gDPSetPrimColor(&gfx[1], 0, 1, 255, 255, 0, 150);
    gDPSetEnvColor(&gfx[2], 255, 0, 0, 255);
    Matrix_Translate(-55.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(&gfx[3], play->state.gfxCtx);
    gSPDisplayList(&gfx[4], object_fwall_DL_000040);
    POLY_XLU_DISP = &gfx[5];

    CLOSE_DISPS(play->state.gfxCtx);
}
