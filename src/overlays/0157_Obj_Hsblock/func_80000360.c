// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hsblock.h"

void ObjHsblock_Draw(Actor* thisx, PlayState* play) {
    static Color_RGB8 sEnvColors[] = {
        { 60, 60, 120 },
        { 120, 100, 70 },
        { 100, 150, 120 },
        { 255, 255, 255 },
    };
    Color_RGB8* envColor = &sEnvColors[OBJHSBLOCK_GET_6(thisx)];

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gDPSetEnvColor(POLY_OPA_DISP++, envColor->r, envColor->g, envColor->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[OBJHSBLOCK_GET_3(thisx)]);

    CLOSE_DISPS(play->state.gfxCtx);
}
