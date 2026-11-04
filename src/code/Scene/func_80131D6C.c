// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene_proc.h"

void Scene_DrawConfig3(PlayState* play) {
    u32 frames;

    OPEN_DISPS(play->state.gfxCtx);

    frames = play->gameplayFrames;

    gSPSegment(POLY_XLU_DISP++, 0x08, Gfx_TexScroll(play->state.gfxCtx, 0, (frames * 1) % 64, 256, 16));

    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 127 - (frames % 128), (frames * 1) % 128, 32, 32, 1,
                                frames % 128, (frames * 1) % 128, 32, 32));

    gSPSegment(POLY_OPA_DISP++, 0x0A,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 32, 1, 0, 127 - (frames * 1) % 128, 32, 32));

    gSPSegment(POLY_OPA_DISP++, 0x0B, Gfx_TexScroll(play->state.gfxCtx, 0, (frames * 1) % 128, 32, 32));

    gSPSegment(
        POLY_XLU_DISP++, 0x0C,
        Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, (frames * 50) % 2048, 8, 512, 1, 0, (frames * 60) % 2048, 8, 512));

    gSPSegment(POLY_OPA_DISP++, 0x0D,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0, (frames * 1) % 128, 32, 32));

    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetEnvColor(POLY_XLU_DISP++, 128, 128, 128, 128);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, 128, 128, 128, 128);

    CLOSE_DISPS(play->state.gfxCtx);
}
