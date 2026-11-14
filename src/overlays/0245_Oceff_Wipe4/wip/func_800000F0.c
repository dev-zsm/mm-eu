// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (OceffWipe4_Draw), score 3.00 (3 differ, size +3)
#include "generated/mm/z_oceff_wipe4.h"

void func_800000F0(Actor* thisx, PlayState* play) {
    u32 scroll = play->state.frames & 0xFFF;
    OceffWipe4* this = (OceffWipe4*)thisx;
    f32 z;
    u8 alpha;
    s32 pad[2];
    Vec3f eye = GET_ACTIVE_CAM(play)->eye;
    Vtx* vtxPtr;
    Vec3f quakeOffset = Camera_GetQuakeOffset(GET_ACTIVE_CAM(play));

    if (this->counter < 16) {
        z = Math_SinS(this->counter * 0x400) * 1220.0f;
    } else {
        z = 1220.0f;
    }

    vtxPtr = sScarecrowSongFrustumVtx;
    if (this->counter >= 30) {
        alpha = 12 * (50 - this->counter);
    } else {
        alpha = 255;
    }

    vtxPtr[1].v.cn[3] = vtxPtr[3].v.cn[3] = vtxPtr[5].v.cn[3] = vtxPtr[7].v.cn[3] = vtxPtr[9].v.cn[3] =
        vtxPtr[11].v.cn[3] = vtxPtr[13].v.cn[3] = vtxPtr[15].v.cn[3] = vtxPtr[17].v.cn[3] = vtxPtr[19].v.cn[3] =
            vtxPtr[21].v.cn[3] = alpha;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    Matrix_Translate(eye.x + quakeOffset.x, eye.y + quakeOffset.y, eye.z + quakeOffset.z, MTXMODE_NEW);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Matrix_ReplaceRotation(&play->billboardMtxF);
    Matrix_RotateXS(0x708, MTXMODE_APPLY);
    Matrix_Translate(0.0f, 0.0f, -z, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    if (this->actor.params == OCEFF_WIPE4_UNUSED) {
        gSPDisplayList(POLY_XLU_DISP++, sScarecrowSongUnusedMaterialDL);
    } else {
        gSPDisplayList(POLY_XLU_DISP++, sScarecrowSongMaterialDL);
    }

    gSPDisplayList(POLY_XLU_DISP++, sScarecrowSongModelDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, scroll * 2, scroll * -2, 32,
                                                     64, 1, scroll * -1, scroll, 32, 32));
    gSPDisplayList(POLY_XLU_DISP++, &sScarecrowSongModelDL[11]);

    CLOSE_DISPS(play->state.gfxCtx);
}
