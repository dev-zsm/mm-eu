// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_DrawVisibleEyeSwitch(ObjSwitch* this, PlayState* play) {
    s32 pad;
    s32 subType = OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor);

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, sEyeSwitchTextures[subType][this->eyeTexIndex]);
    gSPDisplayList(POLY_OPA_DISP++, sEyeSwitchDL[subType]);

    CLOSE_DISPS(play->state.gfxCtx);
}
