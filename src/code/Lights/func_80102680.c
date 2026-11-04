// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lights.h"

void Lights_GlowCheck(PlayState* play) {
    LightNode* light = play->lightCtx.listHead;

    while (light != NULL) {
        LightPoint* params = &light->info->params.point;

        if (light->info->type == LIGHT_POINT_GLOW) {
            Vec3f worldPos;
            Vec3f projectedPos;
            f32 invW;

            worldPos.x = params->x;
            worldPos.y = params->y;
            worldPos.z = params->z;
            Actor_GetProjectedPos(play, &worldPos, &projectedPos, &invW);

            params->drawGlow = false;

            if ((projectedPos.z > 1) && (fabsf(projectedPos.x * invW) < 1) && (fabsf(projectedPos.y * invW) < 1)) {
                s32 screenPosX = PROJECTED_TO_SCREEN_X(projectedPos, invW);
                s32 screenPosY = PROJECTED_TO_SCREEN_Y(projectedPos, invW);
                s32 wZ = (s32)(projectedPos.z * invW * ((G_MAXZ / 2) * 32)) + ((G_MAXZ / 2) * 32);
                s32 zBuf = SysCfb_GetZBufferInt(screenPosX, screenPosY);

                if (wZ < zBuf) {
                    params->drawGlow = true;
                }
            }
        }

        light = light->next;
    }
}
