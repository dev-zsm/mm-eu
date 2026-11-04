// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

u32 BgCheck_InitStaticLookup(CollisionContext* colCtx, PlayState* play, StaticLookup* lookupTbl) {
    Vec3s* vtxList;
    CollisionPoly* polyList;
    s32 polyMax;
    s32 polyIdx;
    s32 sx;
    s32 sy;
    s32 sz;
    
    s32 sxMin;
    s32 syMin;
    s32 szMin;
    
    s32 sxMax;
    s32 syMax;
    s32 szMax;
    
    Vec3f curSubdivMin;
    Vec3f curSubdivMax;
    CollisionHeader* colHeader = colCtx->colHeader;
    s32 pad[2];
    StaticLookup* iLookup;
    StaticLookup* jLookup;
    StaticLookup* lookup;
    s32 sp98;
    f32 subdivLengthX;
    f32 subdivLengthY;
    f32 subdivLengthZ;

    for (iLookup = lookupTbl;
         iLookup < (colCtx->subdivAmount.x * colCtx->subdivAmount.y * colCtx->subdivAmount.z + lookupTbl); iLookup++) {
        iLookup->floor.head = SS_NULL;
        iLookup->wall.head = SS_NULL;
        iLookup->ceiling.head = SS_NULL;
    }

    polyMax = colHeader->numPolygons;
    vtxList = colHeader->vtxList;
    polyList = colHeader->polyList;
    sp98 = colCtx->subdivAmount.x * colCtx->subdivAmount.y;
    subdivLengthX = colCtx->subdivLength.x + (2 * BGCHECK_SUBDIV_OVERLAP);
    subdivLengthY = colCtx->subdivLength.y + (2 * BGCHECK_SUBDIV_OVERLAP);
    subdivLengthZ = colCtx->subdivLength.z + (2 * BGCHECK_SUBDIV_OVERLAP);

    for (polyIdx = 0; polyIdx < polyMax; polyIdx++) {
        BgCheck_GetPolySubdivisionBounds(colCtx, vtxList, polyList, &sxMin, &syMin, &szMin, &sxMax, &syMax, &szMax,
                                         polyIdx);
        iLookup = szMin * sp98 + lookupTbl;
        curSubdivMin.z = (colCtx->subdivLength.z * szMin + colCtx->minBounds.z) - BGCHECK_SUBDIV_OVERLAP;
        curSubdivMax.z = curSubdivMin.z + subdivLengthZ;

        for (sz = szMin; sz < szMax + 1; sz++) {
            jLookup = (colCtx->subdivAmount.x * syMin) + iLookup;
            curSubdivMin.y = (colCtx->subdivLength.y * syMin + colCtx->minBounds.y) - BGCHECK_SUBDIV_OVERLAP;
            curSubdivMax.y = curSubdivMin.y + subdivLengthY;

            for (sy = syMin; sy < syMax + 1; sy++) {
                lookup = sxMin + jLookup;
                curSubdivMin.x = (colCtx->subdivLength.x * sxMin + colCtx->minBounds.x) - BGCHECK_SUBDIV_OVERLAP;
                curSubdivMax.x = curSubdivMin.x + subdivLengthX;

                for (sx = sxMin; sx < sxMax + 1; sx++) {
                    if (BgCheck_PolyIntersectsSubdivision(&curSubdivMin, &curSubdivMax, polyList, vtxList, polyIdx)) {
                        StaticLookup_AddPoly(lookup, colCtx, polyList, vtxList, polyIdx);
                    }
                    curSubdivMin.x += colCtx->subdivLength.x;
                    curSubdivMax.x += colCtx->subdivLength.x;
                    lookup++;
                }
                curSubdivMin.y += colCtx->subdivLength.y;
                curSubdivMax.y += colCtx->subdivLength.y;
                jLookup += colCtx->subdivAmount.x;
            }
            curSubdivMin.z += colCtx->subdivLength.z;
            curSubdivMax.z += colCtx->subdivLength.z;
            iLookup += sp98;
        }
    }
    return colCtx->polyNodes.count * sizeof(SSNode);
}
