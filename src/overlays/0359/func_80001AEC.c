// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_LodMoon_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnFall* this = (EnFall*)thisx;
    s32 primColor;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

    POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 20, 25, 30, 0, 0x3E7, 0x3200);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPLoadGeometryMode(POLY_OPA_DISP++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);

    primColor = (this->eyeGlowIntensity * 200.0f) + 40.0f;
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0x80, primColor, primColor, primColor, 255);

    gSPDisplayList(POLY_OPA_DISP++, gLodmoonEyesDL);
    gSPLoadGeometryMode(POLY_OPA_DISP++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gSPDisplayList(POLY_OPA_DISP++, gLodmoonMoonDL);
    POLY_OPA_DISP = Play_SetFog(play, POLY_OPA_DISP);

    CLOSE_DISPS(play->state.gfxCtx);
}
