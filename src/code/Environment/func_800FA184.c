// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawRainImpl(PlayState* play, View* view, GraphicsContext* gfxCtx) {
    Player* player = GET_PLAYER(play);
    s32 i;
    u8 precip;
    Vec3f temp;
    f32 length;
    f32 precipScale;
    f32 windScale;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Vec3f spD4;
    u8 materialApplied;
    f32 temp_fs1;
    f32 temp_fs2;
    s16 pitch;
    s16 yaw;
    f32 scale;

    if (play->envCtx.precipitation[PRECIP_SOS_MAX] != 0) {
        precip = play->envCtx.precipitation[PRECIP_RAIN_CUR];
    } else {
        precipScale = ref_func_80173B48(&play->state) / 3e7f;
        precipScale = CLAMP(precipScale, 0.0f, 1.0f);
        precip = play->envCtx.precipitation[PRECIP_RAIN_CUR] * precipScale;
        if (precip < 5) {
            precip = 5;
        }
    }

    OPEN_DISPS(gfxCtx);

    temp.x = view->at.x - view->eye.x;
    temp.y = view->at.y - view->eye.y;
    temp.z = view->at.z - view->eye.z;
    length = sqrtf(SQ(temp.x) + SQ(temp.y) + SQ(temp.z));

    temp_fs1 = temp.x / length;
    temp_fs2 = temp.z / length;

    spF0 = view->eye.x + (temp_fs1 * 50.0f);
    spEC = view->eye.y + ((temp.y / length) * 120.0f);
    spE8 = view->eye.z + (temp_fs2 * 50.0f);

    spE4 = view->eye.x + (temp_fs1 * 220.0f);
    spE0 = view->eye.z + (temp_fs2 * 220.0f);

    if ((u32)precip != 0) {
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 150, 255, 255, 25);
        POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);
    }

    windScale = play->envCtx.windSpeed / 60.0f;
    windScale = CLAMP(windScale, 0.0f, 1.0f);

    spD4.x = play->envCtx.windDirection.x * windScale;
    spD4.y = play->envCtx.windDirection.y + 100.0f;
    spD4.z = play->envCtx.windDirection.z * windScale;

    pitch = 0x4000 - Math_Vec3f_Pitch(&gZeroVec3f, &spD4);
    yaw = Math_Vec3f_Yaw(&gZeroVec3f, &spD4) + 0x8000;

    for (i = 0; i < precip; i++) {
        Matrix_Translate(((Rand_ZeroOne() - 0.7f) * 100.0f) + spF0, ((Rand_ZeroOne() - 0.7f) * 100.0f) + spEC,
                         ((Rand_ZeroOne() - 0.7f) * 100.0f) + spE8, MTXMODE_NEW);
        gSPMatrix(POLY_XLU_DISP++, &ref_D_01000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        Matrix_RotateYS(yaw + (s16)(i << 5), MTXMODE_APPLY);
        Matrix_RotateXS(pitch + (s16)(i << 5), MTXMODE_APPLY);
        Matrix_Scale(0.3f, 1.0f, 0.3f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gFallingRainDropDL);
    }

    if (player->actor.floorHeight < view->eye.y) {
        materialApplied = false;
        for (i = 0; i < precip; i++) {
            if (!materialApplied) {
                Gfx_SetupDL25_Xlu(gfxCtx);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 255);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 100);
                materialApplied++;
            }
            Matrix_Translate((Environment_RandCentered() * 220.0f) + spE4, player->actor.floorHeight + 2.0f,
                             (Environment_RandCentered() * 220.0f) + spE0, MTXMODE_NEW);
            scale = (Rand_ZeroOne() * 0.05f) + 0.05f;
            Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gEffShockwaveDL);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
