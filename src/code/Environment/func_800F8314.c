// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateSun(PlayState* play) {
    f32 temp_f0;
    s16 temp_a0;
    u16 phi_v0;

    if (!play->envCtx.sunDisabled) {
        if (play->envCtx.precipitation[PRECIP_RAIN_CUR] != 0) {
            Math_SmoothStepToF(&sSunPrimAlpha, 0.0f, 0.5f, 4.0f, 0.01f);
        } else {
            Math_SmoothStepToF(&sSunPrimAlpha, 255.0f, 0.5f, 4.0f, 0.01f);
        }

        if (Environment_IsSceneUpsideDown(play)) {
            phi_v0 = CURRENT_TIME + CLOCK_TIME(12, 0);
        } else {
            phi_v0 = CURRENT_TIME;
        }

        temp_a0 = phi_v0 - CLOCK_TIME(12, 0);

        if (play->csCtx.state != CS_STATE_IDLE) {
            Math_SmoothStepToF(&play->envCtx.sunPos.x, -(Math_SinS(temp_a0) * 120.0f) * 25.0f, 1.0f, 0.8f, 0.8f);
            Math_SmoothStepToF(&play->envCtx.sunPos.y, Math_CosS(temp_a0) * 120.0f * 25.0f, 1.0f, 0.8f, 0.8f);
            
            Math_SmoothStepToF(&play->envCtx.sunPos.y, Math_CosS(temp_a0) * 20.0f * 25.0f, 1.0f, 0.8f, 0.8f);
        } else {
            play->envCtx.sunPos.x = -(Math_SinS(temp_a0) * 120.0f) * 25.0f;
            play->envCtx.sunPos.y = Math_CosS(temp_a0) * 120.0f * 25.0f;
            play->envCtx.sunPos.z = Math_CosS(temp_a0) * 20.0f * 25.0f;
        }

        temp_f0 = play->envCtx.sunPos.y / 25.0f;
        if (Environment_IsSceneUpsideDown(play)) {
            temp_f0 = -temp_f0;
        }

        sSunEnvAlpha = temp_f0 / 80.0f * 255.0f;
        if (sSunEnvAlpha < 0.0f) {
            sSunEnvAlpha = 0.0f;
        }
        if (sSunEnvAlpha > 255.0f) {
            sSunEnvAlpha = 255.0f;
        }
        sSunEnvAlpha = 255.0f - sSunEnvAlpha;

        sSunColor = temp_f0 / 80.0f;
        if (sSunColor < 0.0f) {
            sSunColor = 0.0f;
        }
        if (sSunColor > 1.0f) {
            sSunColor = 1.0f;
        }

        sSunScale = (2.0f * sSunColor) + 12.0f;
    }
}
