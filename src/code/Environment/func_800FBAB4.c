// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawCustomLensFlare(PlayState* play) {
    Vec3f pos;

    if (gCustomLensFlare1On) {
        pos.x = gCustomLensFlare1Pos.x;
        pos.y = gCustomLensFlare1Pos.y;
        pos.z = gCustomLensFlare1Pos.z;
        Environment_DrawLensFlare(play, &play->envCtx, &play->view, play->state.gfxCtx, pos, ref_D_801F4E44, ref_D_801F4E48,
                                  ref_D_801F4E4C, false);
    }

    if (gCustomLensFlare2On) {
        pos.x = gCustomLensFlare2Pos.x;
        pos.y = gCustomLensFlare2Pos.y;
        pos.z = gCustomLensFlare2Pos.z;
        Environment_DrawLensFlare(play, &play->envCtx, &play->view, play->state.gfxCtx, pos, ref_D_801F4E5C, ref_D_801F4E60,
                                  ref_D_801F4E64, false);
    }
}
