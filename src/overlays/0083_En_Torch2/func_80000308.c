// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_torch2.h"

void EnTorch2_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTorch2* this = (EnTorch2*)thisx;
    Gfx* gfx = sShellDLists[this->actor.params];

    OPEN_DISPS(play->state.gfxCtx);

    if (this->alpha == 255) {
        Scene_SetRenderModeXlu(play, 0, 0x01);
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        Gfx_DrawDListOpa(play, gfx);
    } else {
        Scene_SetRenderModeXlu(play, 1, 0x02);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, this->alpha);
        Gfx_DrawDListXlu(play, gfx);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
