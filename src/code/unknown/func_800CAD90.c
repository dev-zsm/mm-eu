// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_item.h"

s32 DynaPolyActor_ValidateMove(PlayState* play, DynaPolyActor* dynaActor, s16 startRadius, s16 endRadius,
                               s16 startHeight) {
    Vec3f startPos;
    Vec3f endPos;
    Vec3f intersectionPos;
    f32 sin = Math_SinS(dynaActor->yRotation);
    f32 cos = Math_CosS(dynaActor->yRotation);
    s32 bgId;
    CollisionPoly* poly;
    f32 adjustedStartRadius;
    f32 adjustedEndRadius;
    f32 sign = (0.0f <= dynaActor->pushForce) ? 1.0f : -1.0f;

    adjustedStartRadius = (f32)startRadius - 0.1f;
    startPos.x = dynaActor->actor.world.pos.x + (adjustedStartRadius * cos);
    startPos.y = dynaActor->actor.world.pos.y + startHeight;
    startPos.z = dynaActor->actor.world.pos.z - (adjustedStartRadius * sin);

    adjustedEndRadius = (f32)endRadius - 0.1f;
    endPos.x = sign * adjustedEndRadius * sin + startPos.x;
    endPos.y = startPos.y;
    endPos.z = sign * adjustedEndRadius * cos + startPos.z;

    if (BgCheck_EntityLineTest3(&play->colCtx, &startPos, &endPos, &intersectionPos, &poly, true, false, false, true,
                                &bgId, &dynaActor->actor, 0.0f)) {
        return false;
    }

    startPos.x = (dynaActor->actor.world.pos.x * 2.0f) - startPos.x;
    startPos.z = (dynaActor->actor.world.pos.z * 2.0f) - startPos.z;
    endPos.x = sign * adjustedEndRadius * sin + startPos.x;
    endPos.z = sign * adjustedEndRadius * cos + startPos.z;

    if (BgCheck_EntityLineTest3(&play->colCtx, &startPos, &endPos, &intersectionPos, &poly, true, false, false, true,
                                &bgId, &dynaActor->actor, 0.0f)) {
        return false;
    }

    return true;
}
