// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawLightning(PlayState* play, s32 unused) {
    s16 i;
    f32 dx;
    f32 dz;
    f32 x;
    f32 z;
    s32 pad[2];

    OPEN_DISPS(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(sLightningBolts); i++) {
        switch (sLightningBolts[i].state) {
            case LIGHTNING_BOLT_START:
                dx = play->view.at.x - play->view.eye.x;
                dz = play->view.at.z - play->view.eye.z;

                x = dx / sqrtf(SQ(dx) + SQ(dz));
                z = dz / sqrtf(SQ(dx) + SQ(dz));

                sLightningBolts[i].pos.x = play->view.eye.x + x * 9500.0f;
                sLightningBolts[i].pos.y = Rand_ZeroOne() * 1000.0f + 4000.0f;
                sLightningBolts[i].pos.z = play->view.eye.z + z * 9500.0f;

                sLightningBolts[i].offset.x = (Rand_ZeroOne() - 0.5f) * 5000.0f;
                sLightningBolts[i].offset.y = 0.0f;
                sLightningBolts[i].offset.z = (Rand_ZeroOne() - 0.5f) * 5000.0f;

                sLightningBolts[i].textureIndex = 0;
                sLightningBolts[i].pitch = (Rand_ZeroOne() - 0.5f) * 40.0f;
                sLightningBolts[i].roll = (Rand_ZeroOne() - 0.5f) * 40.0f;
                sLightningBolts[i].delayTimer = 3 * (i + 1);
                sLightningBolts[i].state++;
                break;

            case LIGHTNING_BOLT_WAIT:
                sLightningBolts[i].delayTimer--;

                if (sLightningBolts[i].delayTimer <= 0) {
                    sLightningBolts[i].state++;
                }
                break;

            case LIGHTNING_BOLT_DRAW:
                if (sLightningBolts[i].textureIndex < 7) {
                    sLightningBolts[i].textureIndex++;
                } else {
                    sLightningBolts[i].state = LIGHTNING_BOLT_INACTIVE;
                }
                break;

            default:
                break;
        }

        if (sLightningBolts[i].state == LIGHTNING_BOLT_DRAW) {
            Matrix_Translate(sLightningBolts[i].pos.x + sLightningBolts[i].offset.x,
                             sLightningBolts[i].pos.y + sLightningBolts[i].offset.y,
                             sLightningBolts[i].pos.z + sLightningBolts[i].offset.z, MTXMODE_NEW);
            Matrix_RotateXFApply(DEG_TO_RAD(sLightningBolts[i].pitch));
            Matrix_RotateZF(DEG_TO_RAD(sLightningBolts[i].roll), MTXMODE_APPLY);
            Matrix_Scale(22.0f, 100.0f, 22.0f, MTXMODE_APPLY);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 128);
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 255, 255, 128);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Lib_SegmentedToVirtual(sLightningTextures[sLightningBolts[i].textureIndex]));
            Gfx_SetupDL61_Xlu(play->state.gfxCtx);
            gSPMatrix(POLY_XLU_DISP++, &ref_D_01000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_XLU_DISP++, gEffLightningDL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
