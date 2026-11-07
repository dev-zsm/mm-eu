// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void ref_func_808B7B54(Actor* thisx, PlayState* play) {
    s32 pad;
    Color_RGBA8 sp50;
    Color_RGBA8 sp4C;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    Environment_LerpSandstormColors(ref_D_808B8310, &sp50);
    Environment_LerpSandstormColors(ref_D_808B8330, &sp4C);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, sp50.r, sp50.g, sp50.b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, sp4C.r, sp4C.g, sp4C.b, 255);
    gSPDisplayList(POLY_XLU_DISP++, object_kumo30_DL_000A50);

    Environment_LerpSandstormColors(ref_D_808B8320, &sp50);
    Environment_LerpSandstormColors(ref_D_808B8340, &sp4C);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, sp50.r, sp50.g, sp50.b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, sp4C.r, sp4C.g, sp4C.b, 255);
    gSPDisplayList(POLY_XLU_DISP++, object_kumo30_DL_000C98);

    CLOSE_DISPS(play->state.gfxCtx);
}
