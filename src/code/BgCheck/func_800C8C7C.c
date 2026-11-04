// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckLineAgainstDyna(CollisionContext* colCtx, u16 xpFlags, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                                 CollisionPoly** outPoly, f32* distSq, s32* outBgId, Actor* actor, f32 checkDist,
                                 s32 bccFlags) {
    s32 pad;
    s32 i;
    s32 result = false;
    Linef line;
    f32 ay;
    f32 by;

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if ((colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) && !(colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            if (actor != colCtx->dyna.bgActors[i].actor) {
                ay = posA->y;
                by = posB->y;
                if ((ay < colCtx->dyna.bgActors[i].minY) && (by < colCtx->dyna.bgActors[i].minY)) {
                    continue;
                }
                if ((ay > colCtx->dyna.bgActors[i].maxY) && (by > colCtx->dyna.bgActors[i].maxY)) {
                    continue;
                }
                line.a = *posA;
                line.b = *posB;
                if (Math3D_LineVsSph(&colCtx->dyna.bgActors[i].boundingSphere, &line) != 0) {
                    if (BgCheck_CheckLineAgainstBgActor(colCtx, xpFlags, posA, posB, posResult, outPoly, distSq, i,
                                                        checkDist, bccFlags, actor)) {
                        *outBgId = i;
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}
