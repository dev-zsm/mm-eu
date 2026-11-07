// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_DrawPurified(Actor* thisx, PlayState* play) {
    BgIknvDoukutu* this = (BgIknvDoukutu*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Scene_SetRenderModeXlu(play, 0, 1);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPDisplayList(POLY_OPA_DISP++, gIkanaCavePurifiedDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
