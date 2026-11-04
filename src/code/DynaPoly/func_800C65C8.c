// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void DynaPoly_AddBgActorToLookup(PlayState* play, DynaCollisionContext* dyna, s32 bgId, s32* vtxStartIndex,
                                 s32* polyStartIndex, s32* waterBoxStartIndex) {
    Actor* actor;
    s32 i;
    s32 j;
    s32 wi;
    f32 numVtxInverse;
    Vec3f pos;
    Sphere16* sphere;
    Vec3s* dVtxList;
    Vec3s* point;
    Vec3f newCenterPoint;
    f32 newRadiusSq;
    CollisionHeader* pbgdata;
    Vec3f newVtx;
    Vec3f vtxA;
    Vec3f vtxB;
    Vec3f vtxC;
    Vec3f newNormal;

    pbgdata = dyna->bgActors[bgId].colHeader;
    sphere = &dyna->bgActors[bgId].boundingSphere;
    actor = dyna->bgActors[bgId].actor;
    dyna->bgActors[bgId].dynaLookup.polyStartIndex = *polyStartIndex;
    dyna->bgActors[bgId].vtxStartIndex = *vtxStartIndex;
    dyna->bgActors[bgId].waterboxesStartIndex = *waterBoxStartIndex;
    pos = actor->world.pos;
    pos.y += actor->shape.yOffset * actor->scale.y;

    
    if (1) {}

    ScaleRotPos_SetValue(&dyna->bgActors[bgId].curTransform, &actor->scale, &actor->shape.rot, &pos);

    if (dyna->bgActorFlags[bgId] & BGACTOR_COLLISION_DISABLED) {
        return;
    }

    if (*waterBoxStartIndex + pbgdata->numWaterBoxes > DYNA_WATERBOX_MAX) {
        sprintf(ref_D_801EDAA8, "water_poly Error:[MoveBG OSUGI!!!]");
        sprintf(ref_D_801EDAF8, "num = %d > %d\n", *waterBoxStartIndex + pbgdata->numWaterBoxes, DYNA_WATERBOX_MAX);
        Fault_AddHungupAndCrashImpl(ref_D_801EDAA8, ref_D_801EDAF8);
    }

    if (*polyStartIndex + pbgdata->numPolygons > dyna->polyListMax) {
        sprintf(ref_D_801EDAA8, "bg_poly Error:[MoveBG OSUGI!!!]");
        sprintf(ref_D_801EDAF8, "num = %d > %d\n", *polyStartIndex + pbgdata->numPolygons, dyna->polyListMax);
        Fault_AddHungupAndCrashImpl(ref_D_801EDAA8, ref_D_801EDAF8);
    }

    if (*vtxStartIndex + pbgdata->numVertices > dyna->vtxListMax) {
        sprintf(ref_D_801EDAA8, "bg_vert Error:[MoveBG OSUGI!!!]");
        sprintf(ref_D_801EDAF8, "num = %d > %d\n", *vtxStartIndex + pbgdata->numVertices, dyna->vtxListMax);
        Fault_AddHungupAndCrashImpl(ref_D_801EDAA8, ref_D_801EDAF8);
    }

    if (!(dyna->bitFlag & DYNAPOLY_INVALIDATE_LOOKUP) && BgActor_IsTransformUnchanged(&dyna->bgActors[bgId])) {
        s32 pi;

        for (pi = *polyStartIndex; pi < *polyStartIndex + pbgdata->numPolygons; pi++) {
            CollisionPoly* poly = &dyna->polyList[pi];
            s16 normalY = poly->normal.y;

            if (normalY > COLPOLY_SNORMAL(0.5f)) {
                if (!(dyna->bgActorFlags[bgId] & BGACTOR_FLOOR_COLLISION_DISABLED)) {
                    s16 polyIndex = pi;

                    DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.floor, &polyIndex);
                }
            } else if (normalY < COLPOLY_SNORMAL(-0.8f)) {
                if (!(dyna->bgActorFlags[bgId] & BGACTOR_CEILING_COLLISION_DISABLED)) {
                    s16 polyIndex = pi;

                    DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.ceiling,
                                                 &polyIndex);
                }
            } else {
                s16 polyIndex = pi;

                DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.wall, &polyIndex);
            }
        }

        *polyStartIndex += pbgdata->numPolygons;
        *vtxStartIndex += pbgdata->numVertices;
        *waterBoxStartIndex += pbgdata->numWaterBoxes;
        return;
    }

    SkinMatrix_SetScaleRotateYRPTranslate(
        &sModelToWorldMtxF, dyna->bgActors[bgId].curTransform.scale.x, dyna->bgActors[bgId].curTransform.scale.y,
        dyna->bgActors[bgId].curTransform.scale.z, dyna->bgActors[bgId].curTransform.rot.x,
        dyna->bgActors[bgId].curTransform.rot.y, dyna->bgActors[bgId].curTransform.rot.z,
        dyna->bgActors[bgId].curTransform.pos.x, dyna->bgActors[bgId].curTransform.pos.y,
        dyna->bgActors[bgId].curTransform.pos.z);

    if ((pbgdata->numVertices != 0) && (pbgdata->numPolygons != 0)) {
        f32 radiusSq;

        numVtxInverse = 1.0f / pbgdata->numVertices;
        newCenterPoint.x = newCenterPoint.y = newCenterPoint.z = 0.0f;
        for (i = 0; i < pbgdata->numVertices; i++) {
            Vec3f vtx;
            Vec3f vtxT; 
            s32 pad;

            Math_Vec3s_ToVec3f(&vtx, &pbgdata->vtxList[i]);
            SkinMatrix_Vec3fMtxFMultXYZ(&sModelToWorldMtxF, &vtx, &vtxT);
            BgCheck_Vec3fToVec3s(&dyna->vtxList[*vtxStartIndex + (u32)i], &vtxT);

            if (i == 0) {
                dyna->bgActors[bgId].minY = dyna->bgActors[bgId].maxY = vtxT.y;
            } else if (vtxT.y < dyna->bgActors[bgId].minY) {
                dyna->bgActors[bgId].minY = vtxT.y;
            } else if (dyna->bgActors[bgId].maxY < vtxT.y) {
                dyna->bgActors[bgId].maxY = vtxT.y;
            }
            newCenterPoint.x += vtxT.x;
            newCenterPoint.y += vtxT.y;
            newCenterPoint.z += vtxT.z;
        }

        newCenterPoint.x *= numVtxInverse;
        newCenterPoint.y *= numVtxInverse;
        newCenterPoint.z *= numVtxInverse;
        sphere->center.x = newCenterPoint.x;
        sphere->center.y = newCenterPoint.y;
        sphere->center.z = newCenterPoint.z;
        newRadiusSq = -100.0f;

        for (i = 0, j = *vtxStartIndex; i < pbgdata->numVertices; i++, j++) {
            newVtx.x = dyna->vtxList[j].x;
            newVtx.y = dyna->vtxList[j].y;
            newVtx.z = dyna->vtxList[j].z;
            radiusSq = Math3D_Vec3fDistSq(&newVtx, &newCenterPoint);
            if (newRadiusSq < radiusSq) {
                newRadiusSq = radiusSq;
            }
        }

        sphere->radius = sqrtf(newRadiusSq) * 1.1f;

        for (i = 0; i < pbgdata->numPolygons; i++) {
            CollisionPoly* newPoly = &dyna->polyList[*polyStartIndex + i];
            f32 newNormMagnitude;
            u32 vIA;
            u32 vIB;
            u32 vIC;

            *newPoly = pbgdata->polyList[i];

            vIA = (COLPOLY_VTX_INDEX(newPoly->flags_vIA) + *vtxStartIndex);
            vIB = (COLPOLY_VTX_INDEX(newPoly->flags_vIB) + *vtxStartIndex);
            vIC = newPoly->vIC + *vtxStartIndex;

            newPoly->flags_vIA = vIA | COLPOLY_VTX_FLAGS_MASKED(newPoly->flags_vIA);
            newPoly->flags_vIB = vIB | COLPOLY_VTX_FLAGS_MASKED(newPoly->flags_vIB);
            newPoly->vIC = vIC;
            dVtxList = dyna->vtxList;
            vtxA.x = dVtxList[vIA].x;
            vtxA.y = dVtxList[vIA].y;
            vtxA.z = dVtxList[vIA].z;
            vtxB.x = dVtxList[vIB].x;
            vtxB.y = dVtxList[vIB].y;
            vtxB.z = dVtxList[vIB].z;
            vtxC.x = dVtxList[vIC].x;
            vtxC.y = dVtxList[vIC].y;
            vtxC.z = dVtxList[vIC].z;
            Math3D_SurfaceNorm(&vtxA, &vtxB, &vtxC, &newNormal);
            newNormMagnitude = Math3D_Vec3fMagnitude(&newNormal);

            if (!IS_ZERO(newNormMagnitude)) {
                newNormal.x *= 1.0f / newNormMagnitude;
                newNormal.y *= 1.0f / newNormMagnitude;
                newNormal.z *= 1.0f / newNormMagnitude;
                newPoly->normal.x = COLPOLY_SNORMAL(newNormal.x);
                newPoly->normal.y = COLPOLY_SNORMAL(newNormal.y);
                newPoly->normal.z = COLPOLY_SNORMAL(newNormal.z);
            }

            newPoly->dist = nearbyint(-DOTXYZ(newNormal, vtxA));
            if (newNormal.y > 0.5f) {
                s16 polyId = *polyStartIndex + i;

                DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.floor, &polyId);
            } else if (newNormal.y < -0.8f) {
                s16 polyId = *polyStartIndex + i;

                DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.ceiling, &polyId);
            } else {
                s16 polyId = *polyStartIndex + i;

                DynaSSNodeList_SetSSListHead(&dyna->polyNodes, &dyna->bgActors[bgId].dynaLookup.wall, &polyId);
            }
        }
    }

    if (pbgdata->numWaterBoxes > 0) {
        for (wi = 0; wi < pbgdata->numWaterBoxes; wi++) {
            WaterBox* waterBox;
            Vec3f modelMinPos;
            Vec3f worldMinPos;
            Vec3f modelMinPosXOffset;
            Vec3f worldMinPosXOffset;
            Vec3f modelMinPosZOffset;
            Vec3f worldMinPosZOffset;

            Math_Vec3s_ToVec3f(&modelMinPos, &pbgdata->waterBoxes[wi].minPos);
            Math_Vec3f_Copy(&modelMinPosXOffset, &modelMinPos);
            modelMinPosXOffset.x += pbgdata->waterBoxes[wi].xLength;
            Math_Vec3f_Copy(&modelMinPosZOffset, &modelMinPos);
            modelMinPosZOffset.z += pbgdata->waterBoxes[wi].zLength;
            SkinMatrix_Vec3fMtxFMultXYZ(&sModelToWorldMtxF, &modelMinPos, &worldMinPos);
            SkinMatrix_Vec3fMtxFMultXYZ(&sModelToWorldMtxF, &modelMinPosXOffset, &worldMinPosXOffset);
            SkinMatrix_Vec3fMtxFMultXYZ(&sModelToWorldMtxF, &modelMinPosZOffset, &worldMinPosZOffset);
            waterBox = &dyna->waterBoxList.boxes[*waterBoxStartIndex + wi];
            BgCheck_CalcWaterboxDimensions(&worldMinPos, &worldMinPosXOffset, &worldMinPosZOffset, &waterBox->minPos,
                                           &waterBox->xLength, &waterBox->zLength);
            waterBox->properties = pbgdata->waterBoxes[wi].properties;
        }
    }
    *polyStartIndex += pbgdata->numPolygons;
    *vtxStartIndex += pbgdata->numVertices;
    *waterBoxStartIndex += pbgdata->numWaterBoxes;
}
