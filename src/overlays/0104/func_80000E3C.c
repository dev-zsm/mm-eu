// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

void EnWood02_Draw(Actor* thisx, PlayState* play) {
    EnWood02* this = (EnWood02*)thisx;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    u8 red;
    u8 green;
    u8 blue;

    OPEN_DISPS(gfxCtx);

    if ((thisx->params == WOOD_TREE_OVAL_GREEN_SPAWNER) || (thisx->params == WOOD_TREE_OVAL_GREEN_SPAWNED) ||
        (thisx->params == WOOD_TREE_OVAL_GREEN) || (thisx->params == WOOD_LEAF_GREEN)) {
        red = 50;
        green = 170;
        blue = 70;
    } else if ((thisx->params == WOOD_TREE_OVAL_YELLOW_SPAWNER) || (thisx->params == WOOD_TREE_OVAL_YELLOW_SPAWNED) ||
               (thisx->params == WOOD_LEAF_YELLOW)) {
        red = 180;
        green = 155;
        blue = 0;
    } else {
        red = green = blue = 255;
    }

    Gfx_SetupDL25_Xlu(gfxCtx);

    if ((thisx->params == WOOD_LEAF_GREEN) || (thisx->params == WOOD_LEAF_YELLOW)) {
        Gfx_SetupDL25_Opa(gfxCtx);

        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, red, green, blue, 127);

        Gfx_DrawDListOpa(play, object_wood02_DL_000700);
    } else if (ref_D_808C4D70[this->drawType & 0xF] != NULL) {
        Gfx_DrawDListOpa(play, ref_D_808C4D54[this->drawType & 0xF]);

        gDPSetEnvColor(POLY_XLU_DISP++, red, green, blue, 0);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, ref_D_808C4D70[this->drawType & 0xF]);
    } else {
        Gfx_SetupDL25_Xlu(gfxCtx);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, ref_D_808C4D54[this->drawType & 0xF]);
    }

    CLOSE_DISPS(gfxCtx);
}
