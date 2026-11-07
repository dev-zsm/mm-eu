// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Moon_Draw(Actor* thisx, PlayState* play) {
    
    
    static Vec3f sFocusOffset[] = { 1800.0f, 1000.0f, 4250.0f };
    EnFall* this = (EnFall*)thisx;
    s32 primColor;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    Matrix_MultVec3f(sFocusOffset, &this->actor.focus.pos);

    primColor = (this->eyeGlowIntensity * 200.0f) + 40.0f;
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, primColor, primColor, primColor, 255);

    gSPDisplayList(POLY_OPA_DISP++, gMoonDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
