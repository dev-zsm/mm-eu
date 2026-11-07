// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_DrawFloorSwitch(ObjSwitch* this, PlayState* play) {
    s32 pad[2];

    if (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor) == OBJSWITCH_SUBTYPE_ONCE) {
        Gfx* gfx;

        OPEN_DISPS(play->state.gfxCtx);

        gfx = POLY_OPA_DISP;
        gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gDPSetPrimColor(gfx++, 0, 0x80, this->color.r, this->color.g, this->color.b, 255);
        gSPDisplayList(gfx++, gFloorSwitch1DL);
        POLY_OPA_DISP = gfx;

        CLOSE_DISPS(play->state.gfxCtx);
    } else {
        Gfx_DrawDListOpa(play, sFloorSwitchDL[OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor)]);
    }
}
