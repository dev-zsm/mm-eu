// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vr_box.h"

void Skybox_Reload(PlayState* play, SkyboxContext* skyboxCtx, s16 skyboxId) {
    size_t size;

    switch (skyboxId) {
        case SKYBOX_NORMAL_SKY:
            osCreateMesgQueue(&skyboxCtx->loadQueue, skyboxCtx->loadMsg, ARRAY_COUNT(skyboxCtx->loadMsg));

            if (play->envCtx.skybox1Index == 0) {
                
                size = SEGMENT_ROM_SIZE(d2_fine_static);

                DmaMgr_RequestAsync(&skyboxCtx->skybox1DmaRequest, skyboxCtx->staticSegments[0],
                                    SEGMENT_ROM_START(d2_fine_static), size, 0, &skyboxCtx->loadQueue, NULL);
            } else {
                
                size = SEGMENT_ROM_SIZE(d2_cloud_static);

                DmaMgr_RequestAsync(&skyboxCtx->skybox1DmaRequest, skyboxCtx->staticSegments[0],
                                    SEGMENT_ROM_START(d2_cloud_static), size, 0, &skyboxCtx->loadQueue, NULL);
            }

            osRecvMesg(&skyboxCtx->loadQueue, NULL, OS_MESG_BLOCK);
            osCreateMesgQueue(&skyboxCtx->loadQueue, skyboxCtx->loadMsg, ARRAY_COUNT(skyboxCtx->loadMsg));

            if (play->envCtx.skybox2Index == 0) {
                
                size = SEGMENT_ROM_SIZE(d2_fine_static);

                DmaMgr_RequestAsync(&skyboxCtx->skybox2DmaRequest, skyboxCtx->staticSegments[1],
                                    SEGMENT_ROM_START(d2_fine_static), size, 0, &skyboxCtx->loadQueue, NULL);
            } else {
                
                size = SEGMENT_ROM_SIZE(d2_cloud_static);

                DmaMgr_RequestAsync(&skyboxCtx->skybox2DmaRequest, skyboxCtx->staticSegments[1],
                                    SEGMENT_ROM_START(d2_cloud_static), size, 0, &skyboxCtx->loadQueue, NULL);
            }

            osRecvMesg(&skyboxCtx->loadQueue, NULL, OS_MESG_BLOCK);
            osCreateMesgQueue(&skyboxCtx->loadQueue, skyboxCtx->loadMsg, ARRAY_COUNT(skyboxCtx->loadMsg));

            size = SEGMENT_ROM_SIZE(d2_fine_pal_static);

            
            DmaMgr_RequestAsync(&skyboxCtx->paletteDmaRequest, skyboxCtx->palette,
                                SEGMENT_ROM_START(d2_fine_pal_static), size, 0, &skyboxCtx->loadQueue, NULL);

            osRecvMesg(&skyboxCtx->loadQueue, NULL, OS_MESG_BLOCK);
            break;

        default:
            break;
    }
}
