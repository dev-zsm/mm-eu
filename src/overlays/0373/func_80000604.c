// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_DrawAmmoDropDefault(EnTest6* this, PlayState* play, SoTCsAmmoDrops* ammoDrop) {
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    if (ammoDrop->type != SOTCS_AMMO_DROP_NONE) {
        Matrix_Translate(ammoDrop->pos.x * ammoDrop->scale, ammoDrop->pos.y, ammoDrop->pos.z * ammoDrop->scale,
                         MTXMODE_NEW);
        Matrix_Scale(ammoDrop->scale * 0.02f, ammoDrop->scale * 0.02f, ammoDrop->scale * 0.02f, MTXMODE_APPLY);
        POLY_OPA_DISP = Play_SetFog(play, POLY_OPA_DISP);
        POLY_OPA_DISP = Gfx_SetupDL66(POLY_OPA_DISP);

        gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sSoTCsAmmoDropTextures[ammoDrop->type]));
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gItemDropDL);
    }

    Matrix_Translate(ammoDrop->pos.x * ammoDrop->scale, ammoDrop->pos.y, ammoDrop->pos.z * ammoDrop->scale,
                     MTXMODE_NEW);
    Matrix_Scale(2.0f * ammoDrop->scale, 2.0f * ammoDrop->scale, 2.0f * ammoDrop->scale, MTXMODE_APPLY);
    Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
    Matrix_RotateZS(play->state.frames * 512, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, 2.0f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 210, 210, 230, 128);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 0);
    gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
    gSPDisplayList(POLY_XLU_DISP++, gEffSparklesDL);
    gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);

    CLOSE_DISPS(play->state.gfxCtx);
}
