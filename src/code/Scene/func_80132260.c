// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene_proc.h"

void Scene_DrawConfig5(PlayState* play) {
    u32 dListIndex;
    u32 alpha;

    if (play->roomCtx.unk7A[0] != 0) {
        dListIndex = 1;
        alpha = play->roomCtx.unk7A[1];
    } else {
        dListIndex = 0;
        alpha = 255;
    }

    if (alpha == 0) {
        play->roomCtx.unk78 = 0;
    } else {
        OPEN_DISPS(play->state.gfxCtx);

        play->roomCtx.unk78 = 1;
        AnimatedMat_Draw(play, play->sceneMaterialAnims);
        Scene_SetRenderModeXlu(play, dListIndex, 3);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, alpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, alpha);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
