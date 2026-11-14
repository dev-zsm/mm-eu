// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_800008B8(Actor* thisx, PlayState* play) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    DemoEffect* this = (DemoEffect*)thisx;

    OPEN_DISPS(gfxCtx);

    POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_25);

    Matrix_Scale(2.0f, 2.0f, 2.0f, MTXMODE_APPLY);
    SkelCurve_Draw(&this->actor, play, &this->skelCurve, DemoEffect_OverrideLimbDrawTimewarp, NULL, 1, &this->actor);

    CLOSE_DISPS(gfxCtx);
}
