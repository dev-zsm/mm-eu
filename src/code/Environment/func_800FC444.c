// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawSandstorm(PlayState* play, u8 sandstormState) {
    s32 primA1 = 0;
    s32 envA1 = 0;
    s32 primA = play->envCtx.sandstormPrimA;
    s32 envA = play->envCtx.sandstormEnvA;
    s32 step = 9;
    u16 sp96;
    u16 sp94;
    u16 sp92;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    s32 index;
    f32 sp98;
    s32 pad;

    switch (sandstormState) {
        case SANDSTORM_ACTIVE:
            primA1 = play->state.frames % 128;
            if (primA1 > 128) {
                primA1 = 255 - primA1;
            }
            primA1 += 73;
            envA1 = 255;
            break;

        case SANDSTORM_FILL:
            primA1 = 255;
            envA1 = (play->envCtx.sandstormPrimA >= 255) ? 255 : 128;
            break;

        case SANDSTORM_UNFILL:
        case SANDSTORM_5:
            envA1 = 128;
            if (play->envCtx.sandstormEnvA > 128) {
                primA1 = 255;
            } else {
                primA1 = play->state.frames % 128;
                if (primA1 > 64) {
                    primA1 = 128 - primA1;
                }
                primA1 += 73;
            }
            if ((primA1 >= primA) && (primA1 != 255)) {
                play->envCtx.sandstormState++;
            }
            break;

        case SANDSTORM_DISSIPATE:
            primA1 = (play->envCtx.sandstormEnvA > 128) ? 255 : play->envCtx.sandstormEnvA >> 1;

            if (primA == 0) {
                play->envCtx.sandstormState = SANDSTORM_OFF;
            }
            break;

        case SANDSTORM_6:
        case SANDSTORM_8:
            primA1 = ref_D_801F4E30;
            envA1 = ref_D_801F4E30;
            step = 1;
            if (sandstormState == SANDSTORM_8) {
                step = 10;
            }
            break;

        case SANDSTORM_7:
        case SANDSTORM_9:
            step = 1;
            if (primA == 0) {
                play->envCtx.sandstormState = SANDSTORM_OFF;
            }
            if (sandstormState == SANDSTORM_9) {
                step = 10;
            }
            break;

        case SANDSTORM_A:
            step = 255;
            primA1 = ref_D_801F4E30;
            envA1 = ref_D_801F4E30;
            if (primA == 0) {
                play->envCtx.sandstormState = SANDSTORM_OFF;
            }
            break;

        case SANDSTORM_B:
            primA1 = play->state.frames & 0x7F;
            if (primA1 > 64) {
                primA1 = 128 - primA1;
            }
            primA1 += 73;
            envA1 = 128;
            break;

        case SANDSTORM_C:
            if (primA == 0) {
                play->envCtx.sandstormState = SANDSTORM_OFF;
            }
            break;

        case SANDSTORM_D:
            primA1 = ref_D_801F4E30;
            envA1 = ref_D_801F4E30;
            step = 10;
            break;

        default:
            break;
    }

    if (ABS_ALT(primA - primA1) < step) {
        primA = primA1;
    } else if (primA1 < primA) {
        primA -= step;
    } else {
        primA += step;
    }

    if (ABS_ALT(envA - envA1) < step) {
        envA = envA1;
    } else if (envA1 < envA) {
        envA -= step;
    } else {
        envA += step;
    }

    play->envCtx.sandstormPrimA = primA;
    play->envCtx.sandstormEnvA = envA;

    sp98 = (512.0f - (primA + envA)) * (3.0f / 128.0f);

    if (sp98 > 6.0f) {
        sp98 = 6.0f;
    }

    if (play->envCtx.sandstormPrimA != 0) {
        index = 0;
        if (sandstormState >= SANDSTORM_B) {
            index = 4 * 3;
        }

        if ((play->envCtx.lightMode != LIGHT_MODE_TIME) ||
            (play->envCtx.lightSettingOverride != LIGHT_SETTING_OVERRIDE_NONE)) {
            primColor.r = sSandstormPrimColors[index + 1 * 3 + 0];
            primColor.g = sSandstormPrimColors[index + 1 * 3 + 1];
            primColor.b = sSandstormPrimColors[index + 1 * 3 + 2];
            envColor.r = sSandstormEnvColors[index + 1 * 3 + 0];
            envColor.g = sSandstormEnvColors[index + 1 * 3 + 1];
            envColor.b = sSandstormEnvColors[index + 1 * 3 + 2];
        } else if (sSandstormColorIndex == sNextSandstormColorIndex) {
            primColor.r = sSandstormPrimColors[sSandstormColorIndex * 3 + index + 0];
            primColor.g = sSandstormPrimColors[sSandstormColorIndex * 3 + index + 1];
            primColor.b = sSandstormPrimColors[sSandstormColorIndex * 3 + index + 2];
            envColor.r = sSandstormEnvColors[sSandstormColorIndex * 3 + index + 0];
            envColor.g = sSandstormEnvColors[sSandstormColorIndex * 3 + index + 1];
            envColor.b = sSandstormEnvColors[sSandstormColorIndex * 3 + index + 2];
        } else {
            primColor.r =
                (s32)F32_LERP_ALT(sSandstormPrimColors[sSandstormColorIndex * 3 + index + 0],
                                  sSandstormPrimColors[sNextSandstormColorIndex * 3 + index + 0], sSandstormLerpScale);
            primColor.g =
                (s32)F32_LERP_ALT(sSandstormPrimColors[sSandstormColorIndex * 3 + index + 1],
                                  sSandstormPrimColors[sNextSandstormColorIndex * 3 + index + 1], sSandstormLerpScale);
            primColor.b =
                (s32)F32_LERP_ALT(sSandstormPrimColors[sSandstormColorIndex * 3 + index + 2],
                                  sSandstormPrimColors[sNextSandstormColorIndex * 3 + index + 2], sSandstormLerpScale);
            envColor.r =
                (s32)F32_LERP_ALT(sSandstormEnvColors[sSandstormColorIndex * 3 + index + 0],
                                  sSandstormEnvColors[sNextSandstormColorIndex * 3 + index + 0], sSandstormLerpScale);
            envColor.g =
                (s32)F32_LERP_ALT(sSandstormEnvColors[sSandstormColorIndex * 3 + index + 1],
                                  sSandstormEnvColors[sNextSandstormColorIndex * 3 + index + 1], sSandstormLerpScale);
            envColor.b =
                (s32)F32_LERP_ALT(sSandstormEnvColors[sSandstormColorIndex * 3 + index + 2],
                                  sSandstormEnvColors[sNextSandstormColorIndex * 3 + index + 2], sSandstormLerpScale);
        }

        envColor.r = ((envColor.r * sp98) + ((6.0f - sp98) * primColor.r)) * (1.0f / 6.0f);
        envColor.g = ((envColor.g * sp98) + ((6.0f - sp98) * primColor.g)) * (1.0f / 6.0f);
        envColor.b = ((envColor.b * sp98) + ((6.0f - sp98) * primColor.b)) * (1.0f / 6.0f);

        sp96 = (sSandstormScroll * (11.0f / 6.0f));
        sp94 = (sSandstormScroll * (9.0f / 6.0f));
        sp92 = (sSandstormScroll * (6.0f / 6.0f));

        OPEN_DISPS(play->state.gfxCtx);

        POLY_XLU_DISP = Gfx_SetupDL64(POLY_XLU_DISP);

        gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
        gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, primColor.r, primColor.g, primColor.b, play->envCtx.sandstormPrimA);
        gDPSetEnvColor(POLY_XLU_DISP++, envColor.r, envColor.g, envColor.b, play->envCtx.sandstormEnvA);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, (u32)sp96 % 4096, 0, 512, 32, 1,
                                    (u32)sp94 % 4096, 4095 - ((u32)sp92 % 4096), 256, 64));
        gDPSetTextureLUT(POLY_XLU_DISP++, G_TT_NONE);
        gSPDisplayList(POLY_XLU_DISP++, gFieldSandstormDL);

        CLOSE_DISPS(play->state.gfxCtx);
    }

    sSandstormScroll += (s32)sp98;
}
