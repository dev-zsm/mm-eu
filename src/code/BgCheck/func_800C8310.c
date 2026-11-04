// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsDynaWall(CollisionContext* colCtx, u16 xpFlags, f32* outX, f32* outZ, Vec3f* pos, f32 radius,
                          CollisionPoly** outPoly, s32* outBgId, Actor* actor) {
    Vec3f resultPos;
    s32 result;
    f32 r;
    f32 dz;
    f32 dx;
    BgActor* bgActor;
    s32 i;

    result = false;
    resultPos = *pos;

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (!(colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) || (colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            continue;
        }
        if ((colCtx->dyna.bgActors + i)->actor == actor) {
            continue;
        }
        bgActor = &colCtx->dyna.bgActors[i];

        if ((bgActor->minY > resultPos.y) || (bgActor->maxY < resultPos.y)) {
            continue;
        }

        bgActor->boundingSphere.radius += TRUNCF_BINANG(radius);

        r = bgActor->boundingSphere.radius;
        dx = bgActor->boundingSphere.center.x - resultPos.x;
        dz = bgActor->boundingSphere.center.z - resultPos.z;
        if ((SQ(r) < SQ(dx) + SQ(dz)) || (!Math3D_XYInSphere(&bgActor->boundingSphere, resultPos.x, resultPos.y) &&
                                          !Math3D_YZInSphere(&bgActor->boundingSphere, resultPos.y, resultPos.z))) {
            bgActor->boundingSphere.radius -= TRUNCF_BINANG(radius);
            continue;
        }
        bgActor->boundingSphere.radius -= TRUNCF_BINANG(radius);
        if (BgCheck_SphVsDynaWallInBgActor(colCtx, xpFlags, &colCtx->dyna,
                                           &(colCtx->dyna.bgActors + i)->dynaLookup.wall, outX, outZ, outPoly, outBgId,
                                           &resultPos, radius, i, actor)) {
            resultPos.x = *outX;
            resultPos.z = *outZ;
            result = true;
        }
    }
    return result;
}
