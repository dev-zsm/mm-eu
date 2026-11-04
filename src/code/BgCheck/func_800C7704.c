// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

f32 BgCheck_RaycastFloorDyna(DynaRaycast* dynaRaycast) {
    s32 i;
    f32 result;
    f32 intersect2;
    s32 i2;
    s32 pauseState;
    DynaPolyActor* dynaActor;
    u32 bgId;
    Vec3f polyVtx[3];
    Vec3f polyNorm;
    u32 polyIndex;
    CollisionPoly* polyMin;
    MtxF srpMtx;
    f32 magnitude;
    Vec3s* vtxList;
    f32 polyDist;
    CollisionPoly* poly;
    Vec3f vtx;
    f32 intersect;
    ScaleRotPos* curTransform;

    result = BGCHECK_Y_MIN;
    *dynaRaycast->bgId = BGCHECK_SCENE;

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (!(dynaRaycast->colCtx->dyna.bgActorFlags[i] & BGACTOR_IN_USE) ||
            (dynaRaycast->colCtx->dyna.bgActorFlags[i] & BGACTOR_1)) {
            continue;
        }

        if ((dynaRaycast->actor == dynaRaycast->colCtx->dyna.bgActors[i].actor) ||
            (dynaRaycast->pos->y < dynaRaycast->colCtx->dyna.bgActors[i].minY) ||
            !Math3D_XZInSphere(&dynaRaycast->colCtx->dyna.bgActors[i].boundingSphere, dynaRaycast->pos->x,
                               dynaRaycast->pos->z)) {
            continue;
        }

        dynaRaycast->unk1C = i;
        dynaRaycast->dyna = &dynaRaycast->colCtx->dyna;
        if (dynaRaycast->unk_24 & BGCHECK_IGNORE_FLOOR) {
            dynaRaycast->ssList = &dynaRaycast->colCtx->dyna.bgActors[i].dynaLookup.floor;
            intersect2 = BgCheck_RaycastFloorDynaList(dynaRaycast, DYNA_RAYCAST_FLOORS);

            if (dynaRaycast->yIntersect < intersect2) {
                dynaRaycast->yIntersect = intersect2;
                *dynaRaycast->bgId = i;
                result = intersect2;
            }
        }
        if ((dynaRaycast->unk_24 & BGCHECK_IGNORE_WALL) ||
            ((*dynaRaycast->resultPoly == NULL) && (dynaRaycast->unk_24 & 8))) {
            dynaRaycast->ssList = &dynaRaycast->colCtx->dyna.bgActors[i].dynaLookup.wall;
            intersect2 = BgCheck_RaycastFloorDynaList(dynaRaycast, DYNA_RAYCAST_WALLS);
            if (dynaRaycast->yIntersect < intersect2) {

                dynaRaycast->yIntersect = intersect2;
                *dynaRaycast->bgId = i;
                result = intersect2;
            }
        }

        if (dynaRaycast->unk_24 & BGCHECK_IGNORE_CEILING) {
            dynaRaycast->ssList = &dynaRaycast->colCtx->dyna.bgActors[i].dynaLookup.ceiling;
            intersect2 = BgCheck_RaycastFloorDynaList(dynaRaycast, DYNA_RAYCAST_CEILINGS);
            if (dynaRaycast->yIntersect < intersect2) {

                dynaRaycast->yIntersect = intersect2;
                *dynaRaycast->bgId = i;
                result = intersect2;
            }
        }
    }

    dynaActor = DynaPoly_GetActor(dynaRaycast->colCtx, *dynaRaycast->bgId);
    if ((result != BGCHECK_Y_MIN) && (dynaActor != NULL) && (dynaRaycast->play != NULL)) {
        pauseState = (dynaRaycast->play->pauseCtx.state != PAUSE_STATE_OFF);
        if (!pauseState) {
            pauseState = dynaRaycast->play->pauseCtx.debugEditor != DEBUG_EDITOR_NONE;
        }
        if (!pauseState && (dynaRaycast->colCtx->dyna.bgActorFlags[*dynaRaycast->bgId] & BGACTOR_1)) {
            bgId = *dynaRaycast->bgId;
            polyMin = &dynaRaycast->dyna->polyList[(u16)dynaRaycast->dyna->bgActors[bgId].dynaLookup.polyStartIndex];
            polyIndex = *dynaRaycast->resultPoly - polyMin;
            poly = &dynaRaycast->dyna->bgActors[*dynaRaycast->bgId].colHeader->polyList[polyIndex];

            curTransform = &dynaRaycast->dyna->bgActors[*dynaRaycast->bgId].curTransform;
            SkinMatrix_SetScaleRotateYRPTranslate(&srpMtx, curTransform->scale.x, curTransform->scale.y,
                                                  curTransform->scale.z, curTransform->rot.x, curTransform->rot.y,
                                                  curTransform->rot.z, curTransform->pos.x, curTransform->pos.y,
                                                  curTransform->pos.z);

            vtxList = dynaRaycast->dyna->bgActors[*dynaRaycast->bgId].colHeader->vtxList;

            for (i2 = 0; i2 < 3; i2++) {
                Vec3s* src = &vtxList[COLPOLY_VTX_INDEX(poly->vtxData[i2])];

                Math_Vec3s_ToVec3f(&vtx, src);
                SkinMatrix_Vec3fMtxFMultXYZ(&srpMtx, &vtx, &polyVtx[i2]);
            }
            Math3D_SurfaceNorm(&polyVtx[0], &polyVtx[1], &polyVtx[2], &polyNorm);
            magnitude = Math3D_Vec3fMagnitude(&polyNorm);

            if (!IS_ZERO(magnitude)) {
                polyNorm.x *= 1.0f / magnitude;
                polyNorm.y *= 1.0f / magnitude;
                polyNorm.z *= 1.0f / magnitude;
                polyDist = -DOTXYZ(polyNorm, polyVtx[0]);
                if (Math3D_TriChkPointParaYIntersectInsideTri(
                        &polyVtx[0], &polyVtx[1], &polyVtx[2], polyNorm.x, polyNorm.y, polyNorm.z, polyDist,
                        dynaRaycast->pos->z, dynaRaycast->pos->x, &intersect, dynaRaycast->checkDist)) {
                    if (fabsf(intersect - result) < 1.0f) {
                        result = intersect;
                    }
                }
            }
        }
    }
    return result;
}
