// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_draw.h"

void GetItem_DrawPotion(PlayState* play, s16 drawId) {
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, -play->state.frames, play->state.frames, 32, 32, 1,
                                -play->state.frames, play->state.frames, 32, 32));
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].drawResources[1]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].drawResources[0]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].drawResources[2]);
    gSPDisplayList(POLY_OPA_DISP++, sDrawItemTable[drawId].drawResources[3]);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].drawResources[4]);
    gSPDisplayList(POLY_XLU_DISP++, sDrawItemTable[drawId].drawResources[5]);

    CLOSE_DISPS(play->state.gfxCtx);
}
