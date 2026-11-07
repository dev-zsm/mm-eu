// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hamishi.h"

void ObjHamishi_Draw(Actor* thisx, PlayState* play) {
    ObjHamishi* this = (ObjHamishi*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if ((thisx->projectedPos.z <= 2150.0f) || ((this->unk_1A2 & 1) && (thisx->projectedPos.z < 2250.0f))) {
        thisx->shape.shadowAlpha = 160;
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        gSPSegment(POLY_OPA_DISP++, 0x08, gActorSetupOpaDL);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 170, 130, 255);
        gSPDisplayList(POLY_OPA_DISP++, gFieldSilverBoulderDL);
    } else if (thisx->projectedPos.z < 2250.0f) {
        f32 sp20 = (2250.0f - thisx->projectedPos.z) * 2.55f;

        thisx->shape.shadowAlpha = sp20 * 0.627451f;
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        gSPSegment(POLY_XLU_DISP++, 0x08, gActorSetupXluDL);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 170, 130, (s32)sp20);
        gSPDisplayList(POLY_XLU_DISP++, gFieldSilverBoulderDL);
    } else {
        thisx->shape.shadowAlpha = 0;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
