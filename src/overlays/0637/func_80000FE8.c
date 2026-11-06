// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C17468(PlayState* play) {
    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    OPEN_DISPS(play->state.gfxCtx);

    Environment_LerpSandstormColors(ref_D_80C17824, &sp2C);
    Environment_LerpSandstormColors(ref_D_80C17834, &sp28);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, sp2C.r, sp2C.g, sp2C.b, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, sp28.r, sp28.g, sp28.b, 255);

    CLOSE_DISPS(play->state.gfxCtx);
}
