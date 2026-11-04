// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckDynaCeiling(CollisionContext* colCtx, u16 xpFlags, f32* outY, Vec3f* pos, f32 checkDist,
                             CollisionPoly** outPoly, s32* outBgId, Actor* actor) {
    s32 i;
    s32 result = false;
    f32 resultY;
    f32 tempY = checkDist + pos->y;
    BgActor* bgActor;
    CollisionPoly* poly;

    resultY = tempY;

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (!(colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) || (colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            continue;
        }
        if (actor == colCtx->dyna.bgActors[i].actor) {
            continue;
        }
        if (!Math3D_XZInSphere(&colCtx->dyna.bgActors[i].boundingSphere, pos->x, pos->z)) {
            continue;
        }
        if (BgCheck_CheckDynaCeilingList(colCtx, xpFlags, &colCtx->dyna, &colCtx->dyna.bgActors[i].dynaLookup.ceiling,
                                         &tempY, pos, checkDist, &poly, actor, i) &&
            tempY < resultY) {

            resultY = tempY;
            *outPoly = poly;
            *outBgId = i;
            result = true;
        }
    }
    *outY = resultY;
    return result;
}
