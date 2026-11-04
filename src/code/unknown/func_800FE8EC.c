// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_NewDay(EnvironmentContext* envCtx) {
    u8 dayOffset = 0;

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

    switch (((void)0, gSaveContext.save.day)) {
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
}
