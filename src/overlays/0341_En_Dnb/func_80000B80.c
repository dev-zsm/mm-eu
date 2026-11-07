// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

s32 ref_func_80A50950(EnDnbUnkStruct* arg0, PlayState* play2) {
    static TexturePtr sDustTextures[] = {
        gEffDust8Tex, gEffDust7Tex, gEffDust6Tex, gEffDust5Tex, gEffDust4Tex, gEffDust3Tex, gEffDust2Tex, gEffDust1Tex,
    };
    PlayState* play = play2;
    s32 isGfxSetup = false;
    s32 sp5C = 0;
    s32 idx;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    for (i = 0; i < 256; i++, arg0++) {
        if (arg0->isEnabled != 1) {
            continue;
        }

        if (!isGfxSetup) {
            POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_0);
            gSPDisplayList(POLY_XLU_DISP++, object_hanareyama_obj_DL_000000);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 0);
            isGfxSetup = true;
        }
        Matrix_Push();

        arg0->unk_24 = (arg0->unk_01 / (f32)arg0->unk_02) * 255.0f;

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)arg0->unk_24);

        Matrix_Translate(arg0->unk_0C.x, arg0->unk_0C.y, arg0->unk_0C.z, MTXMODE_NEW);
        Matrix_Scale(arg0->unk_04, arg0->unk_04, 1.0f, MTXMODE_APPLY);
        Matrix_ReplaceRotation(&play->billboardMtxF);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        idx = (arg0->unk_01 / (f32)arg0->unk_02) * 8.0f;
        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(sDustTextures[idx]));
        gSPDisplayList(POLY_XLU_DISP++, object_hanareyama_obj_DL_000020);

        Matrix_Pop();
        sp5C += 1;
    }

    CLOSE_DISPS(play->state.gfxCtx);

    return sp5C;
}
