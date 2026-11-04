// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckLineImpl(CollisionContext* colCtx, u16 xpFlags1, u16 xpFlags2, Vec3f* posA, Vec3f* posB,
                          Vec3f* posResult, CollisionPoly** outPoly, s32* outBgId, Actor* actor, f32 checkDist,
                          u32 bccFlags) {
    StaticLookup* lookupTbl;
    StaticLookup* iLookup;
    s32 subdivMin[3];
    s32 subdivMax[3];
    s32 i;
    s32 result;
    Vec3f posBTemp;
    StaticLineTest checkLine;
    Vec3f sectorMin;
    Vec3f sectorMax;
    s32 temp_lo;
    StaticLookup* lookup;
    s32 j;

    lookupTbl = colCtx->lookupTbl;
    posBTemp = *posB;

    *outBgId = BGCHECK_SCENE;

    BgCheck_ResetPolyCheckTbl(&colCtx->polyNodes, colCtx->colHeader->numPolygons);
    BgCheck_GetStaticLookupIndicesFromPos(colCtx, posA, (Vec3i*)&subdivMin);
    BgCheck_GetStaticLookupIndicesFromPos(colCtx, &posBTemp, (Vec3i*)&subdivMax);
    *posResult = *posB;
    checkLine.outDistSq = 1.0e38f;
    *outPoly = NULL;

    checkLine.colCtx = colCtx;
    checkLine.xpFlags2 = xpFlags2;
    checkLine.posA = posA;
    checkLine.posB = &posBTemp;
    checkLine.outPoly = outPoly;
    checkLine.xpFlags1 = xpFlags1;
    checkLine.outPos = posResult;
    checkLine.checkDist = checkDist;
    checkLine.bccFlags = bccFlags;
    checkLine.actor = actor;
    result = false;

    if ((subdivMin[0] != subdivMax[0]) || (subdivMin[1] != subdivMax[1]) || (subdivMin[2] != subdivMax[2])) {
        for (i = 0; i < 3; i++) {
            if (subdivMax[i] < subdivMin[i]) {
                j = subdivMax[i];
                subdivMax[i] = subdivMin[i];
                subdivMin[i] = j;
            }
        }
        temp_lo = colCtx->subdivAmount.x * colCtx->subdivAmount.y;
        iLookup = lookupTbl + subdivMin[2] * temp_lo;
        sectorMin.z = subdivMin[2] * colCtx->subdivLength.z + colCtx->minBounds.z;
        sectorMax.z = colCtx->subdivLength.z + sectorMin.z;

        for (i = subdivMin[2]; i < subdivMax[2] + 1; i++) {
            StaticLookup* jLookup = iLookup + subdivMin[1] * colCtx->subdivAmount.x;
            s32 pad;

            sectorMin.y = subdivMin[1] * colCtx->subdivLength.y + colCtx->minBounds.y;
            sectorMax.y = colCtx->subdivLength.y + sectorMin.y;

            for (j = subdivMin[1]; j < subdivMax[1] + 1; j++) {
                s32 k;

                lookup = jLookup + subdivMin[0];
                sectorMin.x = subdivMin[0] * colCtx->subdivLength.x + colCtx->minBounds.x;
                sectorMax.x = colCtx->subdivLength.x + sectorMin.x;

                for (k = subdivMin[0]; k < subdivMax[0] + 1; k++) {
                    if (Math3D_LineVsCube(&sectorMin, &sectorMax, posA, &posBTemp)) {
                        checkLine.lookup = lookup;

                        if (BgCheck_CheckLineInSubdivision(&checkLine)) {
                            result = true;
                        }
                    }
                    lookup++;
                    sectorMin.x += colCtx->subdivLength.x;
                    sectorMax.x += colCtx->subdivLength.x;
                }
                jLookup += colCtx->subdivAmount.x;
                sectorMin.y += colCtx->subdivLength.y;
                sectorMax.y += colCtx->subdivLength.y;
            }
            iLookup += temp_lo;
            sectorMin.z += colCtx->subdivLength.z;
            sectorMax.z += colCtx->subdivLength.z;
        }
    } else if (BgCheck_PosInStaticBoundingBox(colCtx, posA) == false) {
        return false;
    } else {
        checkLine.lookup = BgCheck_GetNearestStaticLookup(colCtx, lookupTbl, posA);
        result = BgCheck_CheckLineInSubdivision(&checkLine);
        if (result) {
            checkLine.outDistSq = Math3D_Vec3fDistSq(posResult, posA);
        }
    }
    if ((bccFlags & BGCHECK_CHECK_DYNA) &&
        BgCheck_CheckLineAgainstDyna(colCtx, xpFlags1, posA, &posBTemp, posResult, outPoly, &checkLine.outDistSq,
                                     outBgId, actor, checkDist, bccFlags)) {
        result = true;
    }
    return result;
}
