// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnEgblock* this = (EnEgblock*)thisx;

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->inactive != true) {
        OPEN_DISPS(play->state.gfxCtx);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x80, 255, 255, 255, 255);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        gSPDisplayList(POLY_OPA_DISP++, gEyegoreBlockDL);

        CLOSE_DISPS(play->state.gfxCtx);
    }

    EnEgblock_DrawEffects(this, play);
}
