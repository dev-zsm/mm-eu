// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_Init(PlayState* play2, EnvironmentContext* envCtx, s32 arg2) {
    PlayState* play = play2;
    f32 temp_ft4;
    u8 dayOffset;
    s16 i;

    CREG(1) = 0;

    gSaveContext.sunsSongState = SUNSSONG_INACTIVE;

    gSaveContext.skyboxTime = CURRENT_TIME;

    Environment_JumpForwardInTime();

    if ((CURRENT_TIME >= CLOCK_TIME(18, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 0))) {
        gSaveContext.save.isNight = true;
    } else {
        gSaveContext.save.isNight = false;
    }

    play->state.gfxCtx->callback = Environment_GraphCallback;
    play->state.gfxCtx->callbackArg = play;

    Lights_DirectionalSetInfo(&envCtx->dirLight1, 80, 80, 80, 80, 80, 80);
    LightContext_InsertLight(play, &play->lightCtx, &envCtx->dirLight1);

    Lights_DirectionalSetInfo(&envCtx->dirLight2, 80, 80, 80, 80, 80, 80);
    LightContext_InsertLight(play, &play->lightCtx, &envCtx->dirLight2);

    envCtx->changeSkyboxState = CHANGE_SKYBOX_INACTIVE;
    envCtx->changeSkyboxTimer = 0;
    envCtx->changeLightEnabled = false;
    envCtx->changeLightTimer = 0;
    envCtx->skyboxDmaState = 0;
    envCtx->skybox1Index = 99;
    envCtx->skybox2Index = 99;

    envCtx->glareAlpha = 0.0f;
    envCtx->lensFlareAlphaScale = 0.0f;

    if ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 8)) {
        gSaveContext.save.day = 1;
    }

    switch (gSaveContext.save.day) {
        default:
        case 0:
        case 1:
            envCtx->lightConfig = 0;
            envCtx->changeLightNextConfig = 0;
            break;

        case 2:
            envCtx->lightConfig = 3;
            envCtx->changeLightNextConfig = 3;
            break;

        case 3:
            envCtx->lightConfig = 4;
            envCtx->changeLightNextConfig = 4;
            break;
    }

    envCtx->lightSetting = 0;
    envCtx->prevLightSetting = 0;
    envCtx->lightBlendOverride = LIGHT_BLEND_OVERRIDE_NONE;
    envCtx->stormRequest = STORM_REQUEST_NONE;
    envCtx->stormState = STORM_STATE_OFF;
    envCtx->lightningState = LIGHTNING_OFF;
    envCtx->timeSeqState = TIMESEQ_DAY_BGM;
    envCtx->fillScreen = 0;
    envCtx->screenFillColor[0] = 0;
    envCtx->screenFillColor[1] = 0;
    envCtx->screenFillColor[2] = 0;
    envCtx->screenFillColor[3] = 0;
    envCtx->customSkyboxFilter = false;
    envCtx->skyboxFilterColor[0] = 0;
    envCtx->skyboxFilterColor[1] = 0;
    envCtx->skyboxFilterColor[2] = 0;
    envCtx->skyboxFilterColor[3] = 0;
    envCtx->sandstormState = SANDSTORM_OFF;
    envCtx->sandstormPrimA = 0;
    envCtx->sandstormEnvA = 0;
    envCtx->lightBlend = 1.0f;

    gLightningStrike.state = LIGHTNING_STRIKE_WAIT;
    gLightningStrike.flashRed = 0;
    gLightningStrike.flashGreen = 0;
    gLightningStrike.flashBlue = 0;

    sLightningFlashAlpha = 0;

    ref_D_801F4F30 = 0xFF;
    ref_D_801F4F31 = 0;
    ref_D_801F4E30 = 0;
    ref_D_801F4F33 = 0;

    gSaveContext.cutsceneTransitionControl = 0;

    envCtx->adjLightSettings.ambientColor[0] = 0;
    envCtx->adjLightSettings.ambientColor[1] = 0;
    envCtx->adjLightSettings.ambientColor[2] = 0;
    envCtx->adjLightSettings.light1Color[0] = 0;
    envCtx->adjLightSettings.light1Color[1] = 0;
    envCtx->adjLightSettings.light1Color[2] = 0;
    envCtx->adjLightSettings.light2Color[0] = 0;
    envCtx->adjLightSettings.light2Color[1] = 0;
    envCtx->adjLightSettings.light2Color[2] = 0;
    envCtx->adjLightSettings.fogColor[0] = 0;
    envCtx->adjLightSettings.fogColor[1] = 0;
    envCtx->adjLightSettings.fogColor[2] = 0;
    envCtx->adjLightSettings.fogNear = 0;
    envCtx->adjLightSettings.zFar = 0;

    envCtx->sunPos.x = -(Math_SinS(CURRENT_TIME - CLOCK_TIME(12, 0)) * 120.0f) * 25.0f;
    envCtx->sunPos.y = (Math_CosS(CURRENT_TIME - CLOCK_TIME(12, 0)) * 120.0f) * 25.0f;
    envCtx->sunPos.z = (Math_CosS(CURRENT_TIME - CLOCK_TIME(12, 0)) * 20.0f) * 25.0f;

    envCtx->windDirection.x = 80;
    envCtx->windDirection.y = 80;
    envCtx->windDirection.z = 80;
    envCtx->windSpeed = 20.0f;

    envCtx->lightBlendEnabled = false;
    envCtx->lightSettingOverride = LIGHT_SETTING_OVERRIDE_NONE;
    envCtx->lightBlendRateOverride = LIGHT_BLENDRATE_OVERRIDE_NONE;

    R_TIME_SPEED = envCtx->sceneTimeSpeed = 0;
    R_TIME_SPEED = R_TIME_SPEED; 
    R_ENV_DISABLE_DBG = false;

    CREG(64) = 0;

    play->envCtx.precipitation[PRECIP_RAIN_MAX] = 0;
    play->envCtx.precipitation[PRECIP_SNOW_CUR] = 0;
    play->envCtx.precipitation[PRECIP_SNOW_MAX] = 0;
    play->envCtx.precipitation[PRECIP_SOS_MAX] = 0;

    sInitSkyboxConfig = envCtx->skyboxConfig;

    dayOffset = 0;
    if (((void)0, gSaveContext.save.day) != 0) {
        dayOffset = ((void)0, gSaveContext.save.day) - 1;
    }
    envCtx->skyboxConfig = dayOffset + (sInitSkyboxConfig * 3);
    envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;

    if (sInitSkyboxConfig == SKYBOX_CONFIG_4) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_14;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_5) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_16;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_6) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_17;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_7) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_18 + dayOffset;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_8) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_21 + dayOffset;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_9) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_24;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    } else if (sInitSkyboxConfig == SKYBOX_CONFIG_10) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_25 + dayOffset;
        envCtx->changeSkyboxNextConfig = envCtx->skyboxConfig;
    }

    if (dayOffset >= 3) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_13;
        envCtx->changeSkyboxNextConfig = SKYBOX_CONFIG_13;
    }

    if (envCtx->skyboxConfig >= SKYBOX_CONFIG_MAX) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_0;
        envCtx->changeSkyboxNextConfig = SKYBOX_CONFIG_0;
    }

    ref_D_801F4E74 = 0.0f;

    if ((play->sceneId == SCENE_IKANA) &&
        ((((void)0, gSaveContext.sceneLayer) == 0) || (((void)0, gSaveContext.sceneLayer) == 1)) &&
        !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE)) {
        play->skyboxId = SKYBOX_3;
        envCtx->lightConfig = 5;
        envCtx->changeLightNextConfig = 5;
        ref_D_801F4E74 = 1.0f;
    }

    if (gSaveContext.retainWeatherMode || (gSaveContext.respawnFlag != 0)) {
        switch ((u32)gWeatherMode) {
            case WEATHER_MODE_2:
                if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE)) {
                    play->skyboxId = SKYBOX_3;
                    envCtx->lightConfig = 5;
                    envCtx->changeLightNextConfig = 5;
                    ref_D_801F4E74 = 1.0f;
                } else {
                    gWeatherMode = WEATHER_MODE_CLEAR;
                }
                break;

            default:
                break;
        }

        play->envCtx.precipitation[PRECIP_SNOW_CUR] = 0;
        play->envCtx.precipitation[PRECIP_SNOW_MAX] = 0;

        if (gWeatherMode == WEATHER_MODE_RAIN) {
            if (((u32)CURRENT_DAY == 2) && (CURRENT_TIME >= CLOCK_TIME(7, 0)) && (CURRENT_TIME < CLOCK_TIME(17, 30))) {
                if (Environment_GetStormState(play) != STORM_STATE_OFF) {
                    play->envCtx.precipitation[PRECIP_RAIN_MAX] = 60;
                }
                play->envCtx.precipitation[PRECIP_RAIN_CUR] = 60;
            } else {
                gWeatherMode = WEATHER_MODE_CLEAR;
                Environment_StopStormNatureAmbience(play);
            }
        } else if (gWeatherMode == WEATHER_MODE_SNOW) {
            play->envCtx.precipitation[PRECIP_SNOW_CUR] = 128;
            play->envCtx.precipitation[PRECIP_SNOW_MAX] = 128;
            Environment_StopStormNatureAmbience(play);
        } else {
            Environment_StopStormNatureAmbience(play);
        }
    } else {
        gWeatherMode = WEATHER_MODE_CLEAR;
        Environment_StopStormNatureAmbience(play);
    }

    gInterruptSongOfStorms = false;
    gLightConfigAfterUnderwater = 0;
    sSkyboxIsChanging = false;
    gSaveContext.retainWeatherMode = false;

    R_ENV_LIGHT1_DIR(0) = 80;
    R_ENV_LIGHT1_DIR(1) = 80;
    R_ENV_LIGHT1_DIR(2) = 80;

    R_ENV_LIGHT2_DIR(0) = -80;
    R_ENV_LIGHT2_DIR(1) = -80;
    R_ENV_LIGHT2_DIR(2) = -80;

    cREG(9) = 10;
    cREG(10) = 0;
    cREG(11) = 0;
    cREG(12) = 0;
    cREG(13) = 0;
    cREG(14) = 0;
    ref_D_801F4DDC = 1;

    for (i = 0; i < ARRAY_COUNT(sLightningBolts); i++) {
        sLightningBolts[i].state = LIGHTNING_BOLT_INACTIVE;
    }

    play->roomCtx.unk7A[0] = 0;
    play->roomCtx.unk7A[1] = 0;

    for (i = 0; i < ARRAY_COUNT(play->csCtx.actorCues); i++) {
        play->csCtx.actorCues[i] = NULL;
    }

    gCustomLensFlare1On = false;
    gCustomLensFlare2On = false;
    Rumble_StateReset();

    sEnvSkyboxNumStars = 0;
    gSkyboxNumStars = 0;
    ref_D_801BDBA8 = false;
    sEnvIsTimeStopped = false;
    sSunPrimAlpha = 255.0f;

    Environment_UpdatePostmanEvents(play);
}
