// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateSkybox(u8 skyboxId, EnvironmentContext* envCtx, SkyboxContext* skyboxCtx) {
    size_t size;
    s32 i;
    u8 skybox1Index = 255;
    u8 skybox2Index = 255;
    u8 color1Index = 255;
    u8 color2Index = 255;
    u8 skyboxBlend = 0;
    f32 colorWeight = 0.0f;

    if (envCtx->skyboxConfig >= SKYBOX_CONFIG_MAX) {
        envCtx->skyboxConfig = SKYBOX_CONFIG_0;
    }

    if ((skyboxId == SKYBOX_NORMAL_SKY) || ((skyboxId == SKYBOX_3) && (ref_D_801F4E74 < 1.0f))) {
        if (envCtx->skyboxDisabled) {
            return;
        }

        for (i = 0; i < ARRAY_COUNT(sTimeBasedSkyboxConfigs[envCtx->skyboxConfig]); i++) {
            if ((gSaveContext.skyboxTime >= sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].startTime) &&
                ((gSaveContext.skyboxTime < sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].endTime) ||
                 (sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].endTime == (CLOCK_TIME(24, 0) - 1)))) {

                skybox1Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].skybox1Index;
                skybox2Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].skybox2Index;
                if (skybox1Index == skybox2Index) {
                    sSkyboxIsChanging = false;
                } else {
                    sSkyboxIsChanging = true;
                }

                if (sSkyboxIsChanging) {
                    skyboxBlend = Environment_LerpWeight(sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].endTime,
                                                         sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].startTime,
                                                         ((void)0, gSaveContext.skyboxTime)) *
                                  255.0f;
                } else {
                    skyboxBlend = Environment_LerpWeight(sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].endTime,
                                                         sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].startTime,
                                                         ((void)0, gSaveContext.skyboxTime)) *
                                  255.0f;

                    if (skyboxBlend < 128) {
                        skyboxBlend = 255;
                    } else {
                        skyboxBlend = 0;
                    }

                    if ((envCtx->changeSkyboxState != CHANGE_SKYBOX_INACTIVE) &&
                        (envCtx->changeSkyboxState < CHANGE_SKYBOX_ACTIVE)) {
                        envCtx->changeSkyboxState++;
                        skyboxBlend = 0;
                    }
                }
                color1Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].color1Index;
                color2Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].color2Index;
                colorWeight = Environment_LerpWeight(sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].endTime,
                                                     sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].startTime,
                                                     gSaveContext.skyboxTime);
                break;
            }
        }

        if (CREG(64) != 0) {
            skybox1Index = skybox2Index = CREG(71);
        } else {
            CREG(71) = skybox1Index;
        }

        if (envCtx->changeSkyboxState >= CHANGE_SKYBOX_ACTIVE) {
            skybox1Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].skybox1Index;
            skybox2Index = sTimeBasedSkyboxConfigs[envCtx->changeSkyboxNextConfig][i].skybox2Index;
            color1Index = sTimeBasedSkyboxConfigs[envCtx->skyboxConfig][i].color1Index;
            color2Index = sTimeBasedSkyboxConfigs[envCtx->changeSkyboxNextConfig][i].color2Index;
            skyboxBlend = ((envCtx->changeDuration - (f32)envCtx->changeSkyboxTimer) / envCtx->changeDuration) * 255.0f;
            colorWeight = (envCtx->changeDuration - (f32)envCtx->changeSkyboxTimer) / envCtx->changeDuration;
            envCtx->changeSkyboxTimer--;
            if (envCtx->changeSkyboxTimer <= 0) {
                envCtx->changeSkyboxState = CHANGE_SKYBOX_INACTIVE;
                envCtx->skyboxConfig = envCtx->changeSkyboxNextConfig;
            }
        }

        if ((envCtx->skybox1Index != skybox1Index) && (envCtx->skyboxDmaState == SKYBOX_DMA_INACTIVE)) {
            envCtx->skyboxDmaState = SKYBOX_DMA_TEXTURE1_START;
            size = sNormalSkyFiles[skybox1Index].file.vromEnd - sNormalSkyFiles[skybox1Index].file.vromStart;
            osCreateMesgQueue(&envCtx->loadQueue, envCtx->loadMsg, ARRAY_COUNT(envCtx->loadMsg));
            DmaMgr_RequestAsync(&envCtx->dmaRequest, skyboxCtx->staticSegments[0],
                                sNormalSkyFiles[skybox1Index].file.vromStart, size, 0, &envCtx->loadQueue, NULL);
            envCtx->skybox1Index = skybox1Index;
        }

        if ((envCtx->skybox2Index != skybox2Index) && (envCtx->skyboxDmaState == SKYBOX_DMA_INACTIVE)) {
            envCtx->skyboxDmaState = SKYBOX_DMA_TEXTURE2_START;
            size = sNormalSkyFiles[skybox2Index].file.vromEnd - sNormalSkyFiles[skybox2Index].file.vromStart;
            osCreateMesgQueue(&envCtx->loadQueue, envCtx->loadMsg, ARRAY_COUNT(envCtx->loadMsg));
            DmaMgr_RequestAsync(&envCtx->dmaRequest, skyboxCtx->staticSegments[1],
                                sNormalSkyFiles[skybox2Index].file.vromStart, size, 0, &envCtx->loadQueue, NULL);
            envCtx->skybox2Index = skybox2Index;
        }

        if ((envCtx->skyboxDmaState == SKYBOX_DMA_TEXTURE1_START) ||
            (envCtx->skyboxDmaState == SKYBOX_DMA_TEXTURE2_START)) {
            if (osRecvMesg(&envCtx->loadQueue, NULL, 0) == 0) {
                envCtx->skyboxDmaState = SKYBOX_DMA_INACTIVE;
            }
        }

        envCtx->skyboxBlend = skyboxBlend;
        Skybox_SetColors(skyboxCtx,
                         LERPIMP_ALT(sSkyboxPrimColors[color1Index].r, sSkyboxPrimColors[color2Index].r, colorWeight),
                         LERPIMP_ALT(sSkyboxPrimColors[color1Index].g, sSkyboxPrimColors[color2Index].g, colorWeight),
                         LERPIMP_ALT(sSkyboxPrimColors[color1Index].b, sSkyboxPrimColors[color2Index].b, colorWeight),
                         LERPIMP_ALT(sSkyboxEnvColors[color1Index].r, sSkyboxEnvColors[color2Index].r, colorWeight),
                         LERPIMP_ALT(sSkyboxEnvColors[color1Index].g, sSkyboxEnvColors[color2Index].g, colorWeight),
                         LERPIMP_ALT(sSkyboxEnvColors[color1Index].b, sSkyboxEnvColors[color2Index].b, colorWeight));
    }
}
