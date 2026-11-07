// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B22FA8(EnHanabiStruct* arg0, PlayState* play2) {
    PlayState* play = play2;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    s32 i;
    u8 sp53;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);

    gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gSun1Tex));
    gSPDisplayList(POLY_XLU_DISP++, gSunSparkleMaterialDL);

    sp53 = 0xFF;

    for (i = 0; i < 400; i++, arg0++) {
        if (arg0->unk_00 != 1) {
            continue;
        }

        Matrix_Translate(arg0->unk_08.x, arg0->unk_08.y, arg0->unk_08.z, MTXMODE_NEW);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        if (arg0->unk_01 < 40) {
            Matrix_Scale(arg0->unk_04 * 0.025f * arg0->unk_01, arg0->unk_04 * 0.025f * arg0->unk_01, 1.0f,
                         MTXMODE_APPLY);
        } else {
            Matrix_Scale(arg0->unk_04, arg0->unk_04, 1.0f, MTXMODE_APPLY);
        }
        Matrix_RotateZS(play->gameplayFrames * 4864, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

        if (sp53 != arg0->unk_02) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetEnvColor(POLY_XLU_DISP++, ref_D_80B23C40[arg0->unk_02], ref_D_80B23C40[arg0->unk_02 + 1],
                           ref_D_80B23C40[arg0->unk_02 + 2], 255);

            sp53 = arg0->unk_02;
        }

        if (arg0->unk_01 < 6) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, ref_D_80B23C2C[arg0->unk_02], ref_D_80B23C2C[arg0->unk_02 + 1],
                            ref_D_80B23C2C[arg0->unk_02 + 2], arg0->unk_01 * 50);
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, ref_D_80B23C2C[arg0->unk_02], ref_D_80B23C2C[arg0->unk_02 + 1],
                            ref_D_80B23C2C[arg0->unk_02 + 2], 255);
        }

        gSPDisplayList(POLY_XLU_DISP++, gSunSparkleModelDL);
    }

    CLOSE_DISPS(gfxCtx);
}
