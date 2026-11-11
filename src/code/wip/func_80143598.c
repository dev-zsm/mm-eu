// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, bytes match; links once `gLoBuffer` and the other symbols of the reference have names of ours
#include "generated/mm/z_vr_box.h"

void Skybox_Setup(GameState* gameState, SkyboxContext* skyboxCtx, s16 skyboxId) {
    PlayState* play = (PlayState*)gameState;
    size_t size;
    void* segment;

    skyboxCtx->rot.z = 0.0f;

    switch (skyboxId) {
        case SKYBOX_NORMAL_SKY:
            
            skyboxCtx->staticSegments[0] = gLoBuffer.skyboxBuffer;
            size = SEGMENT_ROM_SIZE(d2_cloud_static);
            segment = (void*)ALIGN8((uintptr_t)skyboxCtx->staticSegments[0] + size);
            DmaMgr_RequestSync(skyboxCtx->staticSegments[0], SEGMENT_ROM_START(d2_cloud_static), size);

            
            skyboxCtx->staticSegments[1] = segment;
            size = SEGMENT_ROM_SIZE(d2_fine_static);
            segment = (void*)ALIGN8((uintptr_t)segment + size);
            DmaMgr_RequestSync(skyboxCtx->staticSegments[1], SEGMENT_ROM_START(d2_fine_static), size);

            
            skyboxCtx->palette = segment;
            size = SEGMENT_ROM_SIZE(d2_fine_pal_static);
            segment = (void*)ALIGN8((uintptr_t)segment + size);
            DmaMgr_RequestSync(skyboxCtx->palette, SEGMENT_ROM_START(d2_fine_pal_static), size);

            skyboxCtx->prim.r = 145;
            skyboxCtx->prim.g = 120;
            skyboxCtx->prim.b = 155;

            skyboxCtx->env.r = 40;
            skyboxCtx->env.g = 0;
            skyboxCtx->env.b = 40;

            
            if ((play->sceneId == SCENE_F41) || (play->sceneId == SCENE_INISIE_R)) {
                skyboxCtx->rot.z = 3.15f;
            }
            break;

        case SKYBOX_2:
            break;

        default:
            break;
    }
}
