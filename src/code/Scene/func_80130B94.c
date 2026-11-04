// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene_proc.h"

void Scene_DrawConfigDefault(PlayState* play) {
    OPEN_DISPS(play->state.gfxCtx);

    gSPDisplayList(POLY_OPA_DISP++, sSceneDrawDefaultDL);
    gSPDisplayList(POLY_XLU_DISP++, sSceneDrawDefaultDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
