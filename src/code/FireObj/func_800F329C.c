// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fireobj_ctx.h"

void FireObj_UpdateLight(PlayState* play, FireObjLight* light, FireObj* fire) {
    FireObjLightParams* lightParams = &sFireObjLightParams[light->lightParamsIndex];
    s16 radius;

    if (fire->state == FIRE_STATE_NOT_LIT) {
        Lights_PointSetColorAndRadius(&light->lightInfo, 0, 0, 0, -1);
    } else {
        radius = (fire->yScale * 140.0f * fire->sizeInv) + 60.0f;

        Lights_PointGlowSetInfo(&light->lightInfo, fire->position.x, (fire->position.y + (fire->yScale * 6500.0f)),
                                fire->position.z,
                                ((s32)(Rand_ZeroOne() * lightParams->maxColorAdj.r) + lightParams->color.r),
                                ((s32)(Rand_ZeroOne() * lightParams->maxColorAdj.g) + lightParams->color.g),
                                ((s32)(Rand_ZeroOne() * lightParams->maxColorAdj.b) + lightParams->color.b), radius);
    }
}
