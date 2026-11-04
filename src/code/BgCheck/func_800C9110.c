// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstDynaPoly(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, s32* outBgId,
                               Vec3f* center, f32 radius, Actor* actor, u16 bciFlags) {
    s32 i = 0;
    Sphere16 testSphere;

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (!(colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) || (colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            continue;
        }
        if (colCtx->dyna.bgActors[i].actor == actor) {
            continue;
        }
        testSphere.center.x = center->x;
        testSphere.center.y = center->y;
        testSphere.center.z = center->z;
        testSphere.radius = radius;
        if (!Math3D_SphVsSph(&testSphere, &colCtx->dyna.bgActors[i].boundingSphere)) {
            continue;
        }
        if (BgCheck_SphVsFirstDynaPolyInBgActor(colCtx, xpFlags, outPoly, center, radius, i, bciFlags, actor)) {
            return true;
        }
    }
    return false;
}
