// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_DrawCrystalSwitch(ObjSwitch* this, PlayState* play) {
    s32 pad[2];

    OPEN_DISPS(play->state.gfxCtx);

    ref_func_800B8118(&this->dyna.actor, play, 0);
    AnimatedMat_DrawStep(play, sCrystalSwitchAnimatedMat, this->crystalAnimTimer);
    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gCrystalSwitchBaseDL);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, this->color.r, this->color.g, this->color.b, 255);
    gSPDisplayList(POLY_OPA_DISP++, gCrystalSwitchCoreDL);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gCrystalSwitchDiamondDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
