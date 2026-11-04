// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateLights(PlayState* play, EnvironmentContext* envCtx, LightContext* lightCtx) {
    EnvLightSettings* lightSettingsList;
    f32 var_fs3;
    s32 i;
    s32 j;
    f32 temp_fv0;
    s32 adjustment;
    u16 temp_s0_2;
    u16 var_v0;
    AdjLightSettings spA4[4];

    var_fs3 = 0.0f;
    memset(spA4, 0, sizeof(AdjLightSettings) * ARRAY_COUNT(spA4));
    lightSettingsList = play->envCtx.lightSettingsList;

    if ((envCtx->lightSettingOverride != LIGHT_SETTING_OVERRIDE_NONE) &&
        (envCtx->lightBlendOverride != LIGHT_BLEND_OVERRIDE_FULL_CONTROL) &&
        (envCtx->lightSetting != envCtx->lightSettingOverride) && (envCtx->lightBlend >= 1.0f) &&
        (envCtx->lightSettingOverride <= LIGHT_SETTING_MAX)) {

        envCtx->lightBlend = 0.0f;
        envCtx->prevLightSetting = envCtx->lightSetting;
        envCtx->lightSetting = envCtx->lightSettingOverride;
    }

    if (envCtx->lightSettingOverride != LIGHT_SETTING_OVERRIDE_FULL_CONTROL) {
        if ((envCtx->lightMode == LIGHT_MODE_TIME) && (envCtx->lightSettingOverride == LIGHT_SETTING_OVERRIDE_NONE)) {
            for (i = 0; i < ARRAY_COUNT(sTimeBasedLightConfigs[envCtx->lightConfig]); i++) {
                f32 arg0;
                f32 arg1;
                u16 startTime;
                u16 endTime;
                u8 sp97;
                u8 sp96;
                u8 sp95;
                u8 sp94;

                startTime = sTimeBasedLightConfigs[envCtx->lightConfig][i].startTime;
                endTime = sTimeBasedLightConfigs[envCtx->lightConfig][i].endTime;

                sp97 = sTimeBasedLightConfigs[envCtx->lightConfig][i].lightSetting;
                sp95 = sTimeBasedLightConfigs[envCtx->lightConfig][i].nextLightSetting;
                sp96 = sTimeBasedLightConfigs[envCtx->changeLightNextConfig][i].lightSetting;
                sp94 = sTimeBasedLightConfigs[envCtx->changeLightNextConfig][i].nextLightSetting;

                if ((gSaveContext.skyboxTime >= startTime) &&
                    ((gSaveContext.skyboxTime < endTime) || (endTime == 0xFFFF))) {
                    u8 blend8[2];   
                    s16 blend16[2]; 

                    ref_func_800F6CEC(play, sp97, &spA4[0], lightSettingsList);
                    ref_func_800F6CEC(play, sp95, &spA4[1], lightSettingsList);
                    ref_func_800F6CEC(play, sp96, &spA4[2], lightSettingsList);
                    ref_func_800F6CEC(play, sp94, &spA4[3], lightSettingsList);

                    if ((sp94 >= envCtx->numLightSettings) && !ref_D_801BDBA8) {
                        ref_D_801BDBA8 = true;
                    }

                    if ((sp97 >= envCtx->numLightSettings) || (sp95 >= envCtx->numLightSettings) ||
                        (sp96 >= envCtx->numLightSettings) || (sp94 >= envCtx->numLightSettings)) {
                        sp97 = 0;
                        sp95 = 0;
                        sp96 = 0;
                        sp94 = 0;
                    }

                    temp_fv0 = Environment_LerpWeight(endTime, startTime, ((void)0, gSaveContext.skyboxTime));

                    sSandstormColorIndex = sp97 & 3;
                    sNextSandstormColorIndex = sp95 & 3;
                    sSandstormLerpScale = temp_fv0;

                    if (envCtx->changeLightEnabled) {
                        var_fs3 = ((f32)envCtx->changeDuration - envCtx->changeLightTimer) / envCtx->changeDuration;
                        envCtx->changeLightTimer--;

                        if (envCtx->changeLightTimer <= 0) {
                            envCtx->changeLightEnabled = false;
                            envCtx->lightConfig = envCtx->changeLightNextConfig;
                        }
                    }

                    for (j = 0; j < 3; j++) {
                        arg0 = lightSettingsList[(s32)sp95].ambientColor[j] + spA4[1].ambientColor[j];
                        arg1 = lightSettingsList[(s32)sp97].ambientColor[j] + spA4[0].ambientColor[j];
                        blend8[0] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        arg0 = lightSettingsList[(s32)sp94].ambientColor[j] + spA4[3].ambientColor[j];
                        arg1 = lightSettingsList[(s32)sp96].ambientColor[j] + spA4[2].ambientColor[j];
                        blend8[1] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        envCtx->lightSettings.ambientColor[j] = LERPIMP_ALT(blend8[0], blend8[1], var_fs3);
                    }

                    if (Environment_IsSceneUpsideDown(play)) {
                        var_v0 = CURRENT_TIME + CLOCK_TIME(12, 0);
                    } else {
                        var_v0 = CURRENT_TIME;
                    }
                    temp_s0_2 = var_v0 - CLOCK_TIME(12, 0);

                    envCtx->lightSettings.light1Dir[0] = -(Math_SinS(temp_s0_2) * 120.0f);
                    envCtx->lightSettings.light1Dir[1] = Math_CosS(temp_s0_2) * 120.0f;
                    envCtx->lightSettings.light1Dir[2] = Math_CosS(temp_s0_2) * 20.0f;

                    envCtx->lightSettings.light2Dir[0] = -envCtx->lightSettings.light1Dir[0];
                    envCtx->lightSettings.light2Dir[1] = -envCtx->lightSettings.light1Dir[1];
                    envCtx->lightSettings.light2Dir[2] = -envCtx->lightSettings.light1Dir[2];

                    for (j = 0; j < 3; j++) {
                        arg0 = lightSettingsList[(s32)sp95].light1Color[j] + spA4[1].light1Color[j];
                        arg1 = lightSettingsList[(s32)sp97].light1Color[j] + spA4[0].light1Color[j];
                        blend8[0] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        arg0 = lightSettingsList[(s32)sp94].light1Color[j] + spA4[3].light1Color[j];
                        arg1 = lightSettingsList[(s32)sp96].light1Color[j] + spA4[2].light1Color[j];
                        blend8[1] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        envCtx->lightSettings.light1Color[j] = LERPIMP_ALT(blend8[0], blend8[1], var_fs3);

                        arg0 = lightSettingsList[(s32)sp95].light2Color[j] + spA4[1].light2Color[j];
                        arg1 = lightSettingsList[(s32)sp97].light2Color[j] + spA4[0].light2Color[j];
                        blend8[0] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        arg0 = lightSettingsList[(s32)sp94].light2Color[j] + spA4[3].light2Color[j];
                        arg1 = lightSettingsList[(s32)sp96].light2Color[j] + spA4[2].light2Color[j];
                        blend8[1] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        envCtx->lightSettings.light2Color[j] = LERPIMP_ALT(blend8[0], blend8[1], var_fs3);
                    }

                    for (j = 0; j < 3; j++) {
                        arg0 = lightSettingsList[(s32)sp95].fogColor[j] + spA4[1].fogColor[j];
                        arg1 = lightSettingsList[(s32)sp97].fogColor[j] + spA4[0].fogColor[j];
                        blend8[0] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        arg0 = lightSettingsList[(s32)sp94].fogColor[j] + spA4[3].fogColor[j];
                        arg1 = lightSettingsList[(s32)sp96].fogColor[j] + spA4[2].fogColor[j];
                        blend8[1] = Environment_LerpColor(arg0, arg1, temp_fv0);

                        envCtx->lightSettings.fogColor[j] = LERPIMP_ALT(blend8[0], blend8[1], var_fs3);
                    }

                    blend16[0] = S16_LERP(ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)sp97].blendRateAndFogNear),
                                          ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)sp95].blendRateAndFogNear),
                                          temp_fv0);
                    blend16[1] = S16_LERP(ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)sp96].blendRateAndFogNear),
                                          ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)sp94].blendRateAndFogNear),
                                          temp_fv0);
                    envCtx->lightSettings.fogNear = LERPIMP_ALT(blend16[0], blend16[1], var_fs3);

                    blend16[0] =
                        S16_LERP(lightSettingsList[(s32)sp97].zFar, lightSettingsList[(s32)sp95].zFar, temp_fv0);
                    blend16[1] =
                        S16_LERP(lightSettingsList[(s32)sp96].zFar, lightSettingsList[(s32)sp94].zFar, temp_fv0);
                    envCtx->lightSettings.zFar = LERPIMP_ALT(blend16[0], blend16[1], var_fs3);

                    break;
                }
            }
        } else {
            u8 lightSetting;
            u8 var_v0_3;

            if ((envCtx->lightSetting >= envCtx->numLightSettings) && !ref_D_801BDBA8) {
                ref_D_801BDBA8 = true;
            }

            if (!envCtx->lightBlendEnabled) {
                for (i = 0; i < 3; i++) {
                    envCtx->lightSettings.ambientColor[i] = lightSettingsList[envCtx->lightSetting].ambientColor[i];
                    envCtx->lightSettings.light1Dir[i] = lightSettingsList[envCtx->lightSetting].light1Dir[i];
                    envCtx->lightSettings.light1Color[i] = lightSettingsList[envCtx->lightSetting].light1Color[i];
                    envCtx->lightSettings.light2Dir[i] = lightSettingsList[envCtx->lightSetting].light2Dir[i];
                    envCtx->lightSettings.light2Color[i] = lightSettingsList[envCtx->lightSetting].light2Color[i];
                    envCtx->lightSettings.fogColor[i] = lightSettingsList[envCtx->lightSetting].fogColor[i];
                }

                lightSetting = envCtx->lightSetting;
                envCtx->lightSettings.fogNear =
                    ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)lightSetting].blendRateAndFogNear);
                envCtx->lightSettings.zFar = lightSettingsList[(s32)lightSetting].zFar;
                envCtx->lightBlend = 1.0f;
            } else {
                var_v0_3 =
                    ENV_LIGHT_SETTINGS_BLEND_RATE_U8(lightSettingsList[(s32)envCtx->lightSetting].blendRateAndFogNear);

                if (var_v0_3 == 0) {
                    var_v0_3++;
                }

                if (envCtx->lightBlendRateOverride != LIGHT_BLENDRATE_OVERRIDE_NONE) {
                    var_v0_3 = envCtx->lightBlendRateOverride;
                }

                if (envCtx->lightBlendOverride == LIGHT_BLEND_OVERRIDE_NONE) {
                    envCtx->lightBlend += var_v0_3 / 255.0f;
                }

                if (envCtx->lightBlend > 1.0f) {
                    envCtx->lightBlend = 1.0f;
                }

                for (i = 0; i < 3; i++) {
                    envCtx->lightSettings.ambientColor[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].ambientColor[i],
                                    lightSettingsList[envCtx->lightSetting].ambientColor[i], envCtx->lightBlend);
                    envCtx->lightSettings.light1Dir[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].light1Dir[i],
                                    lightSettingsList[envCtx->lightSetting].light1Dir[i], envCtx->lightBlend);
                    envCtx->lightSettings.light1Color[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].light1Color[i],
                                    lightSettingsList[envCtx->lightSetting].light1Color[i], envCtx->lightBlend);
                    envCtx->lightSettings.light2Dir[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].light2Dir[i],
                                    lightSettingsList[envCtx->lightSetting].light2Dir[i], envCtx->lightBlend);
                    envCtx->lightSettings.light2Color[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].light2Color[i],
                                    lightSettingsList[envCtx->lightSetting].light2Color[i], envCtx->lightBlend);
                    envCtx->lightSettings.fogColor[i] =
                        LERPIMP_ALT(lightSettingsList[envCtx->prevLightSetting].fogColor[i],
                                    lightSettingsList[envCtx->lightSetting].fogColor[i], envCtx->lightBlend);
                }

                lightSetting = envCtx->lightSetting;
                envCtx->lightSettings.fogNear = LERPIMP_ALT(
                    ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)envCtx->prevLightSetting].blendRateAndFogNear),
                    ENV_LIGHT_SETTINGS_FOG_NEAR(lightSettingsList[(s32)lightSetting].blendRateAndFogNear),
                    envCtx->lightBlend);

                envCtx->lightSettings.zFar = LERPIMP_ALT(lightSettingsList[(s32)envCtx->prevLightSetting].zFar,
                                                         lightSettingsList[(s32)lightSetting].zFar, envCtx->lightBlend);
            }
        }
    }

    envCtx->lightBlendEnabled = true;

    for (i = 0; i < 3; i++) {
        if ((s16)(envCtx->lightSettings.ambientColor[i] + envCtx->adjLightSettings.ambientColor[i]) > 255) {
            lightCtx->ambientColor[i] = 255;
        } else if ((s16)(envCtx->lightSettings.ambientColor[i] + envCtx->adjLightSettings.ambientColor[i]) < 0) {
            lightCtx->ambientColor[i] = 0;
        } else {
            lightCtx->ambientColor[i] =
                (s16)(envCtx->lightSettings.ambientColor[i] + envCtx->adjLightSettings.ambientColor[i]);
        }

        if ((s16)(envCtx->lightSettings.light1Color[i] + envCtx->adjLightSettings.light1Color[i]) > 255) {
            envCtx->dirLight1.params.dir.color[i] = 255;
        } else if ((s16)(envCtx->lightSettings.light1Color[i] + envCtx->adjLightSettings.light1Color[i]) < 0) {
            envCtx->dirLight1.params.dir.color[i] = 0;
        } else {
            envCtx->dirLight1.params.dir.color[i] =
                (s16)(envCtx->lightSettings.light1Color[i] + envCtx->adjLightSettings.light1Color[i]);
        }

        if ((s16)(envCtx->lightSettings.light2Color[i] + envCtx->adjLightSettings.light2Color[i]) > 255) {
            envCtx->dirLight2.params.dir.color[i] = 255;
        } else if ((s16)(envCtx->lightSettings.light2Color[i] + envCtx->adjLightSettings.light2Color[i]) < 0) {
            envCtx->dirLight2.params.dir.color[i] = 0;
        } else {
            envCtx->dirLight2.params.dir.color[i] =
                (s16)(envCtx->lightSettings.light2Color[i] + envCtx->adjLightSettings.light2Color[i]);
        }

        if ((s16)(envCtx->lightSettings.fogColor[i] + envCtx->adjLightSettings.fogColor[i]) > 255) {
            lightCtx->fogColor[i] = 255;
        } else if ((s16)(envCtx->lightSettings.fogColor[i] + envCtx->adjLightSettings.fogColor[i]) < 0) {
            lightCtx->fogColor[i] = 0;
        } else {
            lightCtx->fogColor[i] = (s16)(envCtx->lightSettings.fogColor[i] + envCtx->adjLightSettings.fogColor[i]);
        }
    }

    
    envCtx->dirLight1.params.dir.x = envCtx->lightSettings.light1Dir[0];
    envCtx->dirLight1.params.dir.y = envCtx->lightSettings.light1Dir[1];
    envCtx->dirLight1.params.dir.z = envCtx->lightSettings.light1Dir[2];

    envCtx->dirLight2.params.dir.x = envCtx->lightSettings.light2Dir[0];
    envCtx->dirLight2.params.dir.y = envCtx->lightSettings.light2Dir[1];
    envCtx->dirLight2.params.dir.z = envCtx->lightSettings.light2Dir[2];

    
    adjustment = envCtx->lightSettings.fogNear + envCtx->adjLightSettings.fogNear;

    if (adjustment <= ENV_FOGNEAR_MAX) {
        lightCtx->fogNear = adjustment;
    } else {
        lightCtx->fogNear = ENV_FOGNEAR_MAX;
    }

    adjustment = envCtx->lightSettings.zFar + envCtx->adjLightSettings.zFar;

    if (adjustment <= ENV_ZFAR_MAX) {
        lightCtx->zFar = adjustment;
    } else {
        lightCtx->zFar = ENV_ZFAR_MAX;
    }

    if ((envCtx->dirLight1.params.dir.x == 0) && (envCtx->dirLight1.params.dir.y == 0) &&
        (envCtx->dirLight1.params.dir.z == 0)) {
        envCtx->dirLight1.params.dir.x = 1;
    }
    if ((envCtx->dirLight2.params.dir.x == 0) && (envCtx->dirLight2.params.dir.y == 0) &&
        (envCtx->dirLight2.params.dir.z == 0)) {
        envCtx->dirLight2.params.dir.x = 1;
    }
}
