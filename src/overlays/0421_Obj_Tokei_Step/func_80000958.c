// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

void ObjTokeiStep_DrawOpen(Actor* thisx, PlayState* play) {
    ObjTokeiStep* this = (ObjTokeiStep*)thisx;
    s32 i;
    ObjTokeiStepPanel* panel;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_OPA_DISP;
    gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);

    for (i = 0; i < ARRAY_COUNT(this->panels); i++) {
        panel = &this->panels[i];
        ObjTokeiStep_SetMatrixTranslation(panel);
        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gSPDisplayList(gfx++, gClocktowerPanelDL);
    }
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(play->state.gfxCtx);
}
