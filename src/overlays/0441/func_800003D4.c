// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightblock.h"

void ObjLightblock_Draw(Actor* thisx, PlayState* play) {
    ObjLightblock* this = (ObjLightblock*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->alpha < 255) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08, gActorSetupXluDL);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, this->alpha);
        gSPDisplayList(POLY_XLU_DISP++, gSunBlockDL);
    } else {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x08, gActorSetupOpaDL);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, 255, 255, 255, 255);
        gSPDisplayList(POLY_OPA_DISP++, gSunBlockDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
