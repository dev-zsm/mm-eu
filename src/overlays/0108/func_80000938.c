// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_80000938(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    DemoEffect* this = (DemoEffect*)thisx;
    s16 zRot = (this->timer * 0x400) & 0xFFFF;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, this->envXluColor[0], this->envXluColor[1], this->envXluColor[2], 255);

    Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
    Matrix_Push();
    Matrix_RotateZS(zRot, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gEffFlash2DL);

    Matrix_Pop();
    Matrix_RotateZS(-zRot, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gEffFlash2DL);

    CLOSE_DISPS(play->state.gfxCtx);

    gCustomLensFlare1On = true;
    gCustomLensFlare1Pos.x = thisx->world.pos.x;
    gCustomLensFlare1Pos.y = thisx->world.pos.y;
    gCustomLensFlare1Pos.z = thisx->world.pos.z;

    ref_D_801F4E44 = thisx->scale.x * 60.0f;
    ref_D_801F4E48 = thisx->scale.x * 50.0f;
    ref_D_801F4E4C = thisx->scale.x * 250.0f;
}
