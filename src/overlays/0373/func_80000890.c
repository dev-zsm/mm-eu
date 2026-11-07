// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_DrawAmmoDropRupee(EnTest6* this, PlayState* play, SoTCsAmmoDrops* ammoDrop) {
    s32 pad;
    Gfx* gfxHead = GRAPH_ALLOC(play->state.gfxCtx, 2 * sizeof(Gfx));
    Gfx* gfx = gfxHead;
    Hilite* hilite;
    Vec3f ammoDropPos;

    ammoDropPos.x = ammoDrop->pos.x * ammoDrop->scale;
    ammoDropPos.y = ammoDrop->pos.y;
    ammoDropPos.z = ammoDrop->pos.z * ammoDrop->scale;

    hilite = ref_func_800BCBF4(&ammoDropPos, play);

    OPEN_DISPS(play->state.gfxCtx);

    if (gfxHead != NULL) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        gDPSetHilite1Tile(gfx++, 1, hilite, 0x10, 0x10);
        gSPEndDisplayList(gfx++);

        gSPSegment(POLY_OPA_DISP++, 0x07, gfxHead);

        Matrix_Translate(ammoDropPos.x, ammoDropPos.y, ammoDropPos.z, MTXMODE_NEW);
        Matrix_Scale(ammoDrop->scale * 0.018f, ammoDrop->scale * 0.018f, ammoDrop->scale * 0.018f, MTXMODE_APPLY);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sSoTCsAmmoDropTextures[ammoDrop->type]));
        gSPDisplayList(POLY_OPA_DISP++, gRupeeDL);
    }

    Matrix_Translate(ammoDrop->pos.x * ammoDrop->scale, ammoDrop->pos.y, ammoDrop->pos.z * ammoDrop->scale,
                     MTXMODE_NEW);
    Matrix_Scale(ammoDrop->scale * 2.5f, ammoDrop->scale * 2.5f, ammoDrop->scale * 2.5f, MTXMODE_APPLY);
    Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
    Matrix_RotateZS(play->state.frames * 256, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, 4.0f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 220, 220, 230, 192);
    gDPSetEnvColor(POLY_XLU_DISP++, 128, 128, 128, 0);
    gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
    gSPDisplayList(POLY_XLU_DISP++, gEffSparklesDL);
    gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);

    CLOSE_DISPS(play->state.gfxCtx);
}
